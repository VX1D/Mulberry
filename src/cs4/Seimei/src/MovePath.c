#include "common.h"

extern float Math_GetDistXZ(float *, float *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern float Math_VectorToAngle(float, float);


/* FreeMovePath @ 0x1A5010 .. 0x1A5024 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j memset at 0x1a501c leaves the function
 *   return value dropped, call kept: the function is void
 */

extern void *memset(void *, int, unsigned int);
extern u8 PathMng[];

extern float Math_GetDistXZ(float *, float *);
extern void sceVu0CopyVector(void *, void *);
extern void sceVu0SubVector(void *, void *, void *);
extern float CheckHitMapLine(void *, void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern float Math_VectorToAngle(float, float);


/* InitMovePath @ 0x1A5350 .. 0x1A5364 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j memset at 0x1a535c leaves the function
 *   return value dropped, call kept: the function is void
 */

extern void *memset(void *, int, unsigned int);
extern u8 PathMng[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void InitMovePath(void);
void * GetFreeMovePath(void);
void * GetMovePath(unsigned char a0 , signed int a1 );
signed int UpdateMovePath(void *object);
void FreeMovePath(void);
s32 UpdateMovePathTotter(void *object);


void InitMovePath(void) {
    memset((u8 *)PathMng, 0, 0x2200);
    return;
}

/* GetFreeMovePath @ 0x1A52E0 .. 0x1A5348 (0x68 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001A5300
 */

void * GetFreeMovePath(void) {
    u8 *s0;
    u32 v1;
    u32 v0;

    s0 = PathMng;
    do {
        v1 = *(u8 *)s0;
        if (v1 == 0) {
            memset((void *)(u8 *)s0, 0, 0x220);
            v0 = (u32)s0;
            *(u8 *)s0 = 1;
            return (void *)v0;
        }
        s0 = (u8 *)(s0 + 0x220);
    } while (s0 != (u8 *)(PathMng + 0x2200));
    return (void *)(u32)0;
}


/* GetMovePath @ 0x1A5270 .. 0x1A52D8 (0x68 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001A5288
 *   declaration vs inferred signature: return void * vs inferred u32
 */

void * GetMovePath(unsigned char a0 /* r4 */, signed int a1 /* r5 */) {
    u32 a0_2; // a0
    u32 v0;

    v0 = (u32)PathMng;
    do {
        a0_2 = *(u8 *)v0;
        if (a0_2 != 0 && (u32)*(u8 *)((v0 + 3)) == (u32)a0 && (u32)*(s32 *)((v0 + 4)) ==
            (u32)(s32)a1) {
            *(u32 *)((v0 + 8)) = (s32)(u8 *)(s32)(v0 + 0x10);
            *(u32 *)((v0 + 0xc)) = 0;
            return (void *)v0;
        }
        v0 = v0 + 0x220;
    } while ((u8 *)v0 != (u8 *)(PathMng + 0x2200));
    return (void *)(u32)0;
}
signed int UpdateMovePath(void *object) {
    u8 *model;
    u8 *path;
    s32 i;
    u8 *nearest;
    float distance;
    u8 *entry;
    u8 *current;
    u32 next;
    u32 selected;
    float delta[4] __attribute__((aligned(16)));
    float start[4] __attribute__((aligned(16)));
    float end[4] __attribute__((aligned(16)));
    path = (u8 *)*(u32 *)((u8 *)object + 0x17c);
    model = object;
    if (!path) return 0;
    if (path[1]) {
        i = 0;
        entry = path;
        distance = 1000000.0f;
        do {
            float measured;
            if (!*(u32 *)(entry + 0x20) && !*(u32 *)(entry + 0x24)) break;
            measured = Math_GetDistXZ((float *)(entry + 0x10), (float *)(model + 0x20));
            if (measured < distance) {
                distance = measured;
                nearest = entry + 0x10;
            }
            i++;
            entry += 0x20;
        } while (i < 16);
        sceVu0CopyVector(start, model + 0x20);
        start[1] = start[1] - 0.8f * *(float *)(model + 0x114);
        sceVu0CopyVector(end, nearest);
        end[1] = end[1] - 0.8f * *(float *)(model + 0x114);
        sceVu0SubVector(delta, end, start);
        if (!(CheckHitMapLine(start, delta) <= 0.95f)) {
            path[1] = 0;
            *(u32 *)(path + 8) = (u32)nearest;
            *(u32 *)(path + 12) = 0;
        } else return 0;
    }
    if (Math_GetDistXZ((float *)*(u32 *)(path + 8), (float *)(model + 0x20)) < *(float *)(model + 0x110)) {
        current = (u8 *)*(u32 *)(path + 8);
        next = *(u32 *)(current + 20);
        if (next) {
            if (next == *(u32 *)(path + 12) && *(u32 *)(current + 16)) selected = *(u32 *)(current + 16);
            else selected = next;
            goto update;
        }
        {
            u32 animation = *(u16 *)(path + 0x210);
            if (animation != 65535) {
                ChangeAnimParam(model, animation, 0.0f);
                *(u32 *)(model + 0x17c) = 0;
                model[0x18a] = model[0x18b];
                return 1;
            }
            selected = *(u32 *)(current + 16);
        }
update:;
        *(u32 *)(path + 12) = (u32)current;
        *(u32 *)(path + 8) = selected;
    }
    next = *(u32 *)(path + 8);
    *(float *)(model + 0x198) = Math_VectorToAngle(-(*(float *)next - *(float *)(model + 0x20)), -(*(float *)(next + 8) - *(float *)(model + 0x28)));
    return 1;
}

void FreeMovePath(void) {
    memset((u8 *)PathMng, 0, 0x2200);
    return;
}
s32 UpdateMovePathTotter(void *object) {
    u8 *model;
    u8 *path;
    s32 result;
    model = (u8 *)object;
    path = *(u8 **)(model + 0x17c);
    if (path == 0) result = 0;
    else {
        u8 *current = *(u8 **)(path + 8);
        if (Math_GetDistXZ((float *)current, (float *)(model + 0x20)) < *(float *)(model + 0x110)) {
            u8 *next;
            u8 *selected;
            current = *(u8 **)(path + 8);
            next = *(u8 **)(current + 0x14);
            if (next != 0) {
                if (next == *(u8 **)(path + 12) && *(u8 **)(current + 16) != 0) selected = *(u8 **)(current + 16);
                else selected = next;
            } else {
                u32 anim = *(u16 *)(path + 0x210);
                if (anim != 0xffff) {
                    ChangeAnimParam(model, anim, 0.0f);
                    *(u32 *)(model + 0x17c) = 0;
                    result = 1;
                    goto end;
                }
                selected = *(u8 **)(current + 16);
            }
            *(u8 **)(path + 12) = current;
            *(u8 **)(path + 8) = selected;
        }
        {
            u8 *point = *(u8 **)(path + 8);
            float x, z;
            x = *(float *)(point + 0) - *(float *)(model + 0x20);
            z = *(float *)(point + 8) - *(float *)(model + 0x28);
            x = -x;
            z = -z;
            *(float *)(model + 0x198) = Math_VectorToAngle(x, z);
        }
        result = 1;
    }
end:
    return result;
}
static u8 PathMng[0x2200];
