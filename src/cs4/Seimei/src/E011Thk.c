#include "common.h"

extern float Math_GetAngleDist(float, float);

#define ABSF(x) (((x) < 0.0f) ? -(x) : (x))
#define WRAPF(a) ((3.14159274f + (a) >= 0.0f) ? ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f)) : (6.28318548f + ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f))))


/* CheckE011AttackState @ 0x18F100 .. 0x18F1EC (0xec bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x18f18c
 *   cfg: kept branch: 0x18f118 if (..) goto .L0018F140
 *   cfg: kept goto: 0x18f138 -> .L0018F1D0
 *   cfg: loop body is not one contiguous region: .L0018F148
 *   cfg: kept branch: 0x18f160 if (..) goto .L0018F188
 *   cfg: kept branch: 0x18f170 if (..) goto .L0018F1A0
 *   cfg: kept goto: 0x18f17c -> .L0018F1B8
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

extern unsigned int CheckEneAttackEnable(void *, void *);
extern unsigned int EneSearchAttackRange();
extern signed int SetE011ClingAndPush(void *, void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);

/* CheckE011WalkState @ 0x18F1F0 .. 0x18F514 (0x324 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490624 at 0x18f2c4
 *   fpu: float literal 0x40490fdb at 0x18f2cc
 *   fpu: float literal 0x00000000 at 0x18f2d0
 *   fpu: float literal 0x40c90fdb at 0x18f2f0
 *   fpu: mtc1 reinterprets v0 at 0x18f314
 *   fpu: float literal 0x40490624 at 0x18f358
 *   fpu: float literal 0x40490fdb at 0x18f360
 *   fpu: float literal 0x00000000 at 0x18f364
 *   fpu: float literal 0x40c90fdb at 0x18f384
 *   fpu: mtc1 reinterprets v0 at 0x18f3a8
 *   fpu: float literal 0x3eb2b020 at 0x18f3e8
 *   fpu: float literal 0x40490fdb at 0x18f3f4
 *   fpu: float literal 0x00000000 at 0x18f3f8
 *   fpu: float literal 0x40c90fdb at 0x18f418
 *   fpu: mtc1 reinterprets v0 at 0x18f43c
 *   fpu: float literal 0x3eb2b020 at 0x18f480
 *   fpu: float literal 0x40490fdb at 0x18f48c
 *   fpu: float literal 0x00000000 at 0x18f490
 *   fpu: float literal 0x40c90fdb at 0x18f4b0
 *   fpu: mtc1 reinterprets v0 at 0x18f4d4
 *   cfg: kept branch: 0x18f214 if (..) goto .L0018F4F8
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

extern unsigned int CheckAnimEndFrame(void *);
extern int rand(void);

#define PI 3.14159274f
#define PI2 6.28318548f
#define ADJ(a) (((a) + PI >= 0.0f) ? ((a) - PI2 * (float)(s32)(((a) + PI) / PI2)) : (PI2 + ((a) - PI2 * (float)(s32)(((a) + PI) / PI2))))


/* CheckE011StayState @ 0x18F520 .. 0x18F630 (0x110 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x18f570 if (..) goto .L0018F610
 *   cfg: kept branch: 0x18f5c8 if (..) goto .L0018F610
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

static unsigned int CheckE011RollState(void *, void *);
extern unsigned int CheckAnimEndFrame(void *);
extern int rand(void);

/* E011ThkWalk @ 0x18F630 .. 0x18F67C (0x4c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

static unsigned int CheckE011AttackState(void *, void *);
static unsigned int CheckE011WalkState(void *, void *);

/* E011ThkStay @ 0x18F680 .. 0x18F6CC (0x4c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

static unsigned int CheckE011AttackState(void *, void *);
static unsigned int CheckE011StayState(void *, void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * E011ThkInit(s32 a0 , u32 *a1 );
static void E011ThkStay(void *a0 , void *a1 );
static void E011ThkWalk(void *a0 , void *a1 );
static unsigned int CheckE011StayState(void *a0 , void *a1 );
static unsigned int CheckE011WalkState(void *a0 , void *a1 );
static unsigned int CheckE011AttackState(void *a0 , void *a1 );
static unsigned int CheckE011RollState(void *a0, void *a1);


/* E011ThkInit @ 0x18F6D0 .. 0x18F6EC (0x1c bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */




u8 * E011ThkInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)E011ThkStay;
    *(u32 *)a1 = (u32)E011ThkStay;
    v1 = (u8 *)E011ThkWalk;
    *(u32 *)(((u8 *)a1 + 4)) = (u32)E011ThkWalk;
    return;
}

static void E011ThkStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 s1;
    u16 *s0;
    u32 v0;
    u32 v1;

    s1 = (u32)a0;
    s0 = (u16 *)a1;
    v0 = CheckE011AttackState(a0, a1);
    a0 = (void *)s1;
    if (v0 == 0) {
        a1 = (void *)s0;
        CheckE011StayState(a0, a1);
        v1 = *(u16 *)(((u8 *)s0 + 0x1dc));
        v1 = v1 + 1;
        *(u16 *)(((u8 *)s0 + 0x1dc)) = v1;
    }
    return;
}

static void E011ThkWalk(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 s1;
    u16 *s0;
    u32 v0;
    u32 v1;

    s1 = (u32)a0;
    s0 = (u16 *)a1;
    v0 = CheckE011AttackState(a0, a1);
    a0 = (void *)s1;
    if (v0 == 0) {
        a1 = (void *)s0;
        CheckE011WalkState(a0, a1);
        v1 = *(u16 *)(((u8 *)s0 + 0x1de));
        v1 = v1 + 1;
        *(u16 *)(((u8 *)s0 + 0x1de)) = v1;
    }
    return;
}

static unsigned int CheckE011StayState(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 *s1;
    u8 *s0;
    u32 v0;
    u32 s2;
    s32 a2;
    s32 v1;

    s1 = (u32 *)a0;
    v0 = *(s32 *)(((u8 *)a0 + 0x1b4));
    s2 = *(s32 *)(((u8 *)a0 + 0x100));
    s0 = (u8 *)a1;
    if (v0 != 0) {
        v0 = *(s32 *)(s0 + 0x1e8);
        if (v0 != 0) {
            v0 = CheckE011RollState(a0, a1);
            if (v0 != 0) {
                v0 = 1;
            } else {
                a0 = (void *)(s32)s2;
                v0 = CheckAnimEndFrame(a0);
                if (v0 == 0) {
                    goto _L0018F610;
                }
                v0 = *(s32 *)(s0 + 0x100);
                a0 = (void *)s1;
                a1 = (void *)s0;
                a2 = 2;
                ((void (*)(u32, u32, s32))(s32)v0)((u32)a0, (u32)a1, a2);
                v0 = 1;
            }
        } else {
            v0 = *(s32 *)(s0 + 0x104);
            a2 = 0xa;
            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0, (u32)a1, a2);
            v0 = 1;
        }
    } else {
        v0 = *(u16 *)(s0 + 0x1dc);
        if ((s32)v0 > (s32)0x78) {
            v0 = rand();
            v1 = 0x64;
            v0 = (s32)v0 % (s32)(0x64);
            if ((s32)v0 > (s32)4) {
                goto _L0018F610;
            }
            v0 = *(s32 *)(s0 + 0x104);
            a0 = (void *)s1;
            a1 = (void *)s0;
            a2 = 0xa;
            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0, (u32)a1, a2);
            v0 = 1;
        } else {
            _L0018F610:;
            v0 = 0;
        }
    }
    return v0;
}
static unsigned int CheckE011WalkState(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *a0_bytes; // s0
    void *a0_s0; // a0
    u32 v1;
    float f3;
    float f2;
    float f1;
    float f0;
    u32 v0;
    void *a1_2;
    u8 *s1;

    a0_bytes = (u8 *)a0;
    v0 = *(s32 *)(a0_bytes + 0x1b4);
    a0_s0 = (void *)*(s32 *)(a0_bytes + 0x100);
    s1 = (u8 *)a1;
    if (v0 != 0) {
        v0 = CheckAnimEndFrame(a0_s0);
        if (v0 == 0) {
            goto _L0018F4F8;
        }
        v0 = *(s32 *)(s1 + 0x1e8);
        if (v0 != 0) {
            v0 = *(s32 *)(s1 + 0x100);
            a0_s0 = (void *)a0_bytes;
            a1_2 = (void *)s1;
            ((void (*)(u32, u32, u32))(s32)v0)((u32)a0_s0, (u32)a1_2, 0);
        } else {
            v0 = *(s32 *)(s1 + 0x104);
            a0_s0 = (void *)a0_bytes;
            a1_2 = (void *)s1;
            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_s0, (u32)a1_2, 0xa);
        }
        v0 = 1;
    } else {
        v1 = *(u16 *)(s1 + 0x1de);
        v0 = 0x3c;
        v0 = (s32)v1 % 0x3c;
        if (v0 == 0) {
            v0 = rand();
            v1 = 0x64;
            v0 = (s32)v0 % 0x64;
            if ((s32)v0 <= (s32)9) {
                *(f32 *)(a0_bytes + 0x198) = ADJ(3.14099979f + *(float *)(a0_bytes + 0x198));
            } else if ((s32)v0 <= (s32)0x13) {
                *(f32 *)(a0_bytes + 0x198) = ADJ(*(float *)(a0_bytes + 0x198) - 3.14099979f);
            } else if ((s32)v0 <= (s32)0x31) {
                *(f32 *)(a0_bytes + 0x198) = ADJ(0.348999977f + *(float *)(a0_bytes + 0x198));
            } else if ((s32)v0 <= (s32)0x4f) {
                *(f32 *)(a0_bytes + 0x198) = ADJ(*(float *)(a0_bytes + 0x198) - 0.348999977f);
            }
        }
        _L0018F4F8:;
        v0 = 0;
    }
    return v0;
}

static unsigned int CheckE011AttackState(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u8 *s0;
    s32 s3;
    u8 *s2;
    u32 v0;

    s1 = (u8 *)a0;
    v0 = *(s32 *)(((u8 *)a0 + 0xc));
    s2 = (u8 *)*(s32 *)((v0 + 0x4c));
    s0 = (u8 *)a1;
    v0 = CheckEneAttackEnable(a0, a1);
    if (v0 != 0) {
        goto _L0018F140;
    }
    v0 = 0;
    goto _L0018F1D0;
    _L0018F140:;
    s3 = 0;
    do {
        a0 = (void *)s1;
        a1 = (void *)s0;
        v0 = EneSearchAttackRange(a0, a1, (u32)s3);
        if (v0 != 0) {
            v0 = *(u8 *)(s2 + 0xa5);
            if (v0 == 0) {
                goto _L0018F188;
            }
            a0 = (void *)s1;
            a1 = (void *)s0;
            v0 = SetE011ClingAndPush(a0, a1);
            if (v0 == 0) {
                goto _L0018F1B8;
            }
            goto _L0018F1A0;
            _L0018F188:;
            v0 = s3 + 0x32;
            a1 = (void *)(u16)v0;
            a0 = (void *)s1;
            ChangeAnimParam(a0, (signed int)a1, 0.0f);
            _L0018F1A0:;
            *(u8 *)(s1 + 0x12a) = s3;
            v0 = 1;
            *(u8 *)(s0 + 0x180) = 2;
            return v0;
        }
        _L0018F1B8:;
        s3 = s3 + 1;
        v0 = s3 < (s32)5;
        s2 = (u8 *)(s2 + 0x28);
    } while (v0 != 0);
    v0 = 0;
    _L0018F1D0:;
    return v0;
}

static unsigned int CheckE011RollState(void *a0, void *a1) {
    u8 *lpEne = a0;
    u8 *lpCtrl = a1;

    if (*(s32 *)(lpEne + 0x1b4) == 0) {
        return 0;
    }
    if (*(s16 *)(lpEne + 0x104) == 0x12 || *(s16 *)(lpEne + 0x104) == 0x13) {
        return 0;
    }
    if (ABSF(Math_GetAngleDist(*(float *)(lpEne + 0x34), *(float *)(lpEne + 0x198))) < 1.57079637f) {
        return 0;
    }
    if (ABSF(Math_GetAngleDist(WRAPF(*(float *)(lpEne + 0x34) + 1.57079637f), *(float *)(lpEne + 0x198))) < 1.57079637f) {
        ((void (*)(void *, void *, s32))*(u32 *)(lpCtrl + 0x104))(lpEne, lpCtrl, 0x13);
    } else {
        ((void (*)(void *, void *, s32))*(u32 *)(lpCtrl + 0x104))(lpEne, lpCtrl, 0x12);
    }
    return 1;
}
