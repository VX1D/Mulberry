#include "common.h"

/* SetLightOff @ 0x1816E0 .. 0x1816E8 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j SetPointLightOff at 0x1816e0 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern void SetPointLightOff(signed int);

/* UpdateLightAnim @ 0x1816F0 .. 0x181838 (0x148 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x18172c
 *   fpu: mtc1 reinterprets v0 at 0x181758
 *   fpu: mtc1 reinterprets a1 at 0x181778
 *   fpu: mtc1 reinterprets v1 at 0x181790
 *   fpu: mtc1 reinterprets a0 at 0x1817a8
 *   fpu: mtc1 reinterprets v1 at 0x1817c0
 *   stack: address of the slot at 0x20 escapes at 0x1817ec
 *   stack: address of the slot at 0x20 escapes at 0x1817f8
 *   fpu: float literal 0x3f800000 at 0x181818
 *   declaration vs inferred signature: return void vs inferred float
 */

extern void AnimCurve(float *, float *, float *, float *, float *, float);
extern signed int UpdatePointLightPos(signed int, float *);
extern u32 LightAnim[];
extern u32 lpDramaMng;

/* FreeLightData @ 0x181840 .. 0x181854 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j memset at 0x18184c leaves the function
 *   return value dropped, call kept: the function is void
 */

extern void *memset(void *, int, unsigned int);
extern u32 LightAnim[];

/* GetLightData @ 0x181860 .. 0x181874 (0x14 bytes) */
/*
 * dcomp notes:
 *   return: addu at 0x181870 computes the return value
 */

extern u32 LightAnim[];

/* RemapLightData @ 0x181880 .. 0x181888 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j RemapMi2 at 0x181880 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern void RemapMi2();

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void RemapLightData(void);
u32 GetLightData(s32 a0 );
void FreeLightData(void);
void UpdateLightAnim(signed int a0 );
void SetLightOff(void);


void RemapLightData(void) {
    RemapMi2();
    return;
}

u32 GetLightData(s32 a0 /* r4 */) {
    return (u32)((u8 *)(u8 *)LightAnim + (u32)((u32)a0 << 3));
}

void FreeLightData(void) {
    memset((u8 *)LightAnim, 0, 0x100);
    return;
}

void UpdateLightAnim(signed int a0 /* r4 */) {
    u16 *t0;
    u16 *a3;
    u8 *s0;
    u8 *a2;
    float f12;
    u32 a1;
    float f1;
    float f0;
    u32 v1;
    u8 stackFrame_20[16] __attribute__((aligned(16)));

    v1 = (u32)LightAnim;
    s0 = (u8 *)((u8 *)LightAnim + (u32)((u32)a0 << 3));
    v1 = *(s32 *)s0;
    if (v1 != 0) {
        a2 = (u8 *)*(s32 *)((v1 + 0x40));
        f1 = *(float *)(s0 + 4);
        a0 = *(u16 *)(a2 + 2);
        a1 = *(u16 *)a2;
        f0 = ((float)(s32)(u32)(a1 + (u32)((signed int)a0)));
        if (f0 < f1) {
            do {
                a2 = (u8 *)(a2 + 0x80);
                a0 = *(u16 *)(a2 + 2);
                a1 = *(u16 *)a2;
                f0 = ((float)(s32)(u32)(a1 + (u32)(a0)));
            } while (f0 < f1);
        }
        t0 = (u16 *)(a2 + 0x80);
        f12 = ((f1 - (float)(float)a1) / (float)(float)(u32)a0);
        a1 = (s32)(a2 + 0x10);
        a3 = (u16 *)(a2 + 0x30);
        a2 = (u8 *)((u8 *)t0 + 0x10);
        t0 = (u16 *)((u8 *)t0 + 0x20);
        AnimCurve((float *)((u8 *)&stackFrame_20[0]), (float *)a1, (float *)a2, (float *)a3, (float
            *)t0, f12);
        UpdatePointLightPos(1, (float *)((u8 *)&stackFrame_20[0]));
        v1 = lpDramaMng;
        v1 = *(u8 *)((v1 + 0xe));
        if (v1 == 0) {
            v1 = 0x3f800000;
            f0 = 1.0f;
            *(f32 *)(s0 + 4) = (*(float *)(s0 + 4) + f0);
        }
    }
    return;
}

void SetLightOff(void) {
    SetPointLightOff(1);
    return;
}
static u32 LightAnim[0x44]; /* +0x10 B unreferenced tail in the original */
