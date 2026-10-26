#include "common.h"

extern float Math_GetDistXZ(float *, float *);
extern void SetModelTargetToPos(void *, float *);
extern int rand();
extern float Math_VectorToAngle(float, float);
extern float Math_GetAngleDist(float, float);
extern f32 E022JumpDst[];


/* CheckE022StayState @ 0x195320 .. 0x195560 (0x240 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3a64b87b at 0x195364
 *   cfg: kept branch: 0x195378 if (..) goto .L001953B8
 *   cfg: kept goto: 0x19538c -> .L00195548
 *   cfg: kept branch: 0x195400 if (..) goto .L00195540
 *   cfg: kept branch: 0x195408 if (..) goto .L00195540
 *   cfg: kept goto: 0x195414 -> .L00195488
 *   cfg: kept goto: 0x195480 -> .L00195548
 *   cfg: kept branch: 0x1954b4 if (..) goto .L00195540
 *   cfg: kept branch: 0x1954c4 if (..) goto .L00195540
 *   cfg: kept branch: 0x195510 if (..) goto .L00195540
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

extern float Math_GotoAngle(float, float, float);
extern unsigned int CheckEneRollState(void *, void *);
extern unsigned int CheckAnimEndFrame(void *);
extern void SetEneAttackOff(void *, void *);
extern int rand();

/* E022ThkWalk @ 0x195570 .. 0x195628 (0xb8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1955a8 writes a register its branch at 0x1955a4 reads
 *   cfg: kept branch: 0x1955a8 if (..) goto .L001955D8
 *   cfg: kept goto: 0x1955c8 -> .L00195600
 *   declaration vs inferred signature: return void vs inferred u32
 */

static unsigned int CheckE022JumpState(void *, void *);
extern unsigned int CheckEneAttackState(void *, void *);
extern unsigned int CheckEneWalkState(void *, void *);
extern unsigned int CheckAnimEndFrame(void *);

/* E022ThkStay @ 0x195630 .. 0x19569C (0x6c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x195664 if (..) goto .L00195688
 *   declaration vs inferred signature: return void vs inferred u32
 */

static unsigned int CheckE022JumpState(void *, void *);

static unsigned int CheckE022StayState(void *, void *);

/* E022ThkInit @ 0x1956A0 .. 0x1956C8 (0x28 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u8 *; 1 parameters vs 2 inferred
 */

static void E022ThkStay(void *a0 /* r4 */, void *a1 /* r5 */);
static void E022ThkWalk(void *a0 /* r4 */, void *a1 /* r5 */);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void E022ThkInit(void *a0 , u32 *a1);
static void E022ThkStay(void *a0 , void *a1 );
static void E022ThkWalk(void *a0 , void *a1 );
static void E022ThkJump(void);
static unsigned int CheckE022StayState(void *a0 , void *a1 );
static unsigned int CheckE022JumpState(void *object, void *controller);


void E022ThkInit(void *a0 /* r4 */, u32 *a1) {
    u8 *v1;

    v1 = (u8 *)E022ThkStay;
    *(u32 *)a1 = (u32)E022ThkStay;
    v1 = (u8 *)E022ThkWalk;
    *(u32 *)(((u8 *)a1 + 4)) = (u32)E022ThkWalk;
    v1 = (u8 *)E022ThkJump;
    *(u32 *)(((u8 *)a1 + 0x20)) = (u32)E022ThkJump;
    return;
}

static void E022ThkStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 *s1;
    u16 *s0;
    u32 v0;
    u32 v1;

    s1 = (u32 *)a0;
    s0 = (u16 *)a1;
    v0 = CheckE022JumpState(a0, a1);
    if (v0 == 0) {
        v0 = *(s32 *)(((u8 *)s1 + 0x158));
        a0 = (void *)s1;
        if (v0 == 0) {
            a1 = (void *)s0;
            v0 = CheckEneAttackState(a0, a1);
            if (v0 != 0) {
                goto _L00195688;
            }
        }
        a0 = (void *)s1;
        a1 = (void *)s0;
        CheckE022StayState(a0, a1);
        v1 = *(u16 *)(((u8 *)s0 + 0x1dc));
        v1 = v1 + 1;
        *(u16 *)(((u8 *)s0 + 0x1dc)) = v1;
    }
    _L00195688:;
    return;
}

static void E022ThkWalk(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s0;
    u32 s1;
    s32 v0;
    u32 v1;

    s2 = (u8 *)a0;
    s1 = *(s32 *)(((u8 *)a0 + 0x100));
    s0 = (u8 *)a1;
    v0 = CheckE022JumpState(a0, a1);
    if ((u32)v0 == 0) {
        v1 = *(s16 *)(s2 + 0x104);
        v0 = 0x12;
        if (v1 != (u32)v0) {
            v0 = 0x13;
            a0 = (void *)s2;
            if (v1 == (u32)v0) {
                goto _L001955D8;
            }
            a1 = (void *)s0;
            v0 = CheckEneAttackState(a0, a1);
            a0 = (void *)s2;
            if ((u32)v0 == 0) {
                a1 = (void *)s0;
                CheckEneWalkState(a0, a1);
                goto _L00195600;
            }
        } else {
            _L001955D8:;
            a0 = (void *)(s32)s1;
            v0 = CheckAnimEndFrame(a0);
            if ((u32)v0 != 0) {
                v0 = *(s32 *)(s0 + 0x100);
                a0 = (void *)s2;
                a1 = (void *)s0;
                ((void (*)(u32, u32, s32))v0)((u32)a0, (u32)a1, 2);
            }
            _L00195600:;
            v1 = *(u16 *)(s0 + 0x1de);
            v1 = v1 + 1;
            *(u16 *)(s0 + 0x1de) = v1;
        }
    }
    return;
}

/* E022ThkJump @ 0x195560 .. 0x195568 (0x8 bytes) */

static void E022ThkJump(void) {
    return;
}

static unsigned int CheckE022StayState(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    s32 a2;
    u8 *s0;
    float f0;
    void *a1_2; // a1
    void *a0_2; // a0
    u32 v1;
    u32 v0;

    v1 = 2;
    s2 = (u8 *)a0;
    v0 = *(s32 *)(((u8 *)a0 + 0x158));
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    s1 = (u8 *)a1;
    if (v0 == v1) {
        v0 = *(s32 *)(s2 + 0x1b4);
        if (v0 != 0) {
            f0 = Math_GotoAngle(*(float *)(s2 + 0x34), *(float *)(s2 + 0x198), 0.00087249995f);
            *(f32 *)(s2 + 0x34) = f0;
        }
        v1 = *(s32 *)(s2 + 0x154);
        v0 = v1 + 1;
        *(u32 *)(s2 + 0x154) = v0;
        if ((s32)v1 <= (s32)0xb4) {
            goto _L001953B8;
        }
        v0 = *(s32 *)(s1 + 0x120);
        a0_2 = (void *)s2;
        a1_2 = (void *)s1;
        a2 = 0x59;
        ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
        v1 = *(s32 *)(s0 + 0x24);
        v0 = 1;
        v1 = v1 | 0x10;
        *(u32 *)(s0 + 0x24) = v1;
        goto _L00195548;
        _L001953B8:;
        v0 = 0;
        return v0;
    }
    v0 = *(s32 *)(s2 + 0x1b4);
    if (v0 != 0) {
        v0 = CheckEneRollState(a0, a1);
        if (v0 != 0) {
            v0 = 1;
        } else {
            v1 = *(s16 *)(s2 + 0x104);
            v0 = 2;
            if (v1 != v0) {
                v0 = 1;
                if (v1 != 0) {
                    if (v1 == v0) {
                        goto _L00195540;
                    }
                    v0 = 0xe;
                    if (v1 != v0) {
                        goto _L00195488;
                    }
                    goto _L00195540;
                } else {
                    v0 = *(s32 *)(s1 + 0x100);
                    a0_2 = (void *)s2;
                    a1_2 = (void *)s1;
                    a2 = 1;
                    ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
                    v0 = 1;
                }
            } else {
                v0 = *(s32 *)(s1 + 0x1e8);
                if (v0 == 0) {
                    v0 = *(s32 *)(s1 + 0x104);
                    a0_2 = (void *)s2;
                    a1_2 = (void *)s1;
                    a2 = 0xb;
                    ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
                } else {
                    a0_2 = (void *)s0;
                    v0 = CheckAnimEndFrame(a0_2);
                    a0_2 = (void *)s2;
                    if (v0 != 0) {
                        a1_2 = (void *)s1;
                        SetEneAttackOff(a0_2, a1_2);
                    }
                }
                v0 = 1;
                goto _L00195548;
                _L00195488:;
                v0 = *(s32 *)(s1 + 0x104);
                a0_2 = (void *)s2;
                a1_2 = (void *)s1;
                a2 = 5;
                ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
                v0 = 1;
            }
        }
    } else {
        v0 = *(s16 *)(s2 + 0x104);
        if (v0 == 0) {
            v0 = *(u16 *)(s1 + 0x1dc);
            if ((s32)v0 <= (s32)0x78) {
                goto _L00195540;
            }
            v0 = rand();
            v1 = 0x64;
            v0 = (s32)v0 % (s32)(0x64);
            if ((s32)v0 > (s32)4) {
                goto _L00195540;
            }
            v0 = *(s32 *)(s1 + 0x104);
            a0_2 = (void *)s2;
            a1_2 = (void *)s1;
            a2 = 5;
            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
            v0 = 1;
        } else {
            a0_2 = (void *)s0;
            if (v0 == v1) {
                v0 = CheckAnimEndFrame(a0_2);
                if (v0 == 0) {
                    goto _L00195540;
                }
                v0 = *(s32 *)(s1 + 0x104);
                a0_2 = (void *)s2;
                a1_2 = (void *)s1;
                a2 = 5;
                ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
                v0 = 1;
            } else {
                _L00195540:;
                v0 = 0;
            }
        }
    }
    _L00195548:;
    return v0;
}

static unsigned int CheckE022JumpState(void *object, void *controller) {
    float distance, targetAngle, angleDistance;
    u8 *obj = (u8 *)object;
    u8 *ctrl;
    u8 *model;
    unsigned int result;
    model = (u8 *)*(s32 *)((u8 *)object + 0x100);
    ctrl = (u8 *)controller;
    if (*(s32 *)(obj + 0x158) == 2) { result = 0; goto done; }
    if (*(float *)(obj + 0x28) < 1.6f || *(float *)(obj + 0x28) > 6.0f) { result = 0; goto done; }
    distance = Math_GetDistXZ((float *)(obj + 0x20), E022JumpDst);
    if (distance < 3.0f || distance > 6.0f) { result = 0; goto done; }
    if ((*(s16 *)(obj + 0x104) == 0x12 || *(s16 *)(obj + 0x104) == 0x13) && *(s32 *)(obj + 0x158) == 1) {
        SetModelTargetToPos(obj, E022JumpDst); result = 0; goto done;
    }
    if (*(s32 *)(obj + 0x158) == 0) {
        if (*(u32 *)(obj + 0x124) % 120 == 0 && rand() % 100 > 20) {
            *(s32 *)(obj + 0x158) = 1;
        } else return 0;
    }
    targetAngle = (float)Math_VectorToAngle(-(E022JumpDst[0] - *(float *)(obj + 0x20)), -(E022JumpDst[2] - *(float *)(obj + 0x28)));
    if (Math_GetAngleDist(*(float *)(obj + 0x34), targetAngle) < 0.0f)
        angleDistance = -Math_GetAngleDist(*(float *)(obj + 0x34), targetAngle);
    else angleDistance = Math_GetAngleDist(*(float *)(obj + 0x34), targetAngle);
    if (!(angleDistance <= 1.5704999f)) {
        float a, s;
        float zero;
        float normalized;
        {
        float shifted;
        float angle = 1.5707964f + *(float *)(obj + 0x34);
        shifted = 3.1415927f + angle;
        if (shifted >= 0.0f) normalized = angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f);
        else normalized = 6.2831855f + (angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f));
        }
        normalized = Math_GetAngleDist(normalized, targetAngle);
        zero = 0.0f;
        if (normalized < zero) {
            a = *(float *)(obj + 0x34);
            a = 1.5707964f + (float)a;
            s = 3.1415927f + a;
            if (s >= zero) normalized = a - 6.2831855f * (float)(s32)(s / 6.2831855f);
            else normalized = 6.2831855f + (a - 6.2831855f * (float)(s32)(s / 6.2831855f));
            normalized = -Math_GetAngleDist(normalized, targetAngle);
        } else {
            a = *(float *)(obj + 0x34);
            a = 1.5707964f + (float)a;
            s = 3.1415927f + a;
            if (s >= zero) normalized = a - 6.2831855f * (float)(s32)(s / 6.2831855f);
            else normalized = 6.2831855f + (a - 6.2831855f * (float)(s32)(s / 6.2831855f));
            normalized = Math_GetAngleDist(normalized, targetAngle);
        }
        if (normalized < 1.5707964f) ((void (*)(void *, void *, s32))*(s32 *)(ctrl + 0x104))(obj, ctrl, 0x13);
        else ((void (*)(void *, void *, s32))*(s32 *)(ctrl + 0x104))(obj, ctrl, 0x12);
        result = 0;
        *(float *)(ctrl + 0x1f4) = angleDistance / *(float *)(model + 0x10);
    } else {
        ((void (*)(void *, void *, s32))*(s32 *)(ctrl + 0x120))(obj, ctrl, 0x57);
        result = 1;
        obj[0x131] = 1; obj[0x132] = 1; obj[0x130] = 1;
        *(s32 *)(obj + 0x154) = 0; *(s32 *)(obj + 0x158) = 2;
        *(float *)(obj + 0x50) = distance / 35.0f;
        *(u32 *)(model + 0x24) |= 0x10;
        *(u32 *)(model + 0x24) |= 0x20;
    }
done:
    return result;
}
