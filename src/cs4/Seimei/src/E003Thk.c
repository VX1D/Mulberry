#include "common.h"

extern float Math_GetAngleDist(float, float);

#define E3_PI 3.14159274f
#define E3_PI2 6.28318548f
#define E3_HPI 1.57079637f
#define E3_ADJ(a) (((a) + E3_PI >= 0.0f) ? ((a) - E3_PI2 * (float)(s32)(((a) + E3_PI) / E3_PI2)) : (E3_PI2 + ((a) - E3_PI2 * (float)(s32)(((a) + E3_PI) / E3_PI2))))
#define E3_ABS(x) (((x) < 0.0f) ? -(x) : (x))

typedef struct {
    u8 pad0[0x34];
    float rotY;
    u8 pad1[0x104 - 0x38];
    s16 act;
    u8 pad2[0x198 - 0x106];
    float tgtRot;
    u8 pad3[0x1b4 - 0x19c];
    s32 alive;
} E003Ene;

typedef struct {
    u8 pad0[0x104];
    void (*SetAct)(void *, void *, s32);
} E003Ctrl;


/* CheckE003AttackState @ 0x201220 .. 0x20130C (0xec bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x2012ac
 *   cfg: kept branch: 0x201238 if (..) goto .L00201260
 *   cfg: kept goto: 0x201258 -> .L002012F0
 *   cfg: loop body is not one contiguous region: .L00201268
 *   cfg: kept branch: 0x201280 if (..) goto .L002012A8
 *   cfg: kept branch: 0x201290 if (..) goto .L002012C0
 *   cfg: kept goto: 0x20129c -> .L002012D8
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

extern unsigned int CheckEneAttackEnable(void *, void *);
extern unsigned int EneSearchAttackRange();
extern signed int SetE003ClingAndPush(void *, void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);

/* CheckE003WalkState @ 0x201310 .. 0x201634 (0x324 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490624 at 0x2013e4
 *   fpu: float literal 0x40490fdb at 0x2013ec
 *   fpu: float literal 0x00000000 at 0x2013f0
 *   fpu: float literal 0x40c90fdb at 0x201410
 *   fpu: mtc1 reinterprets v0 at 0x201434
 *   fpu: float literal 0x40490624 at 0x201478
 *   fpu: float literal 0x40490fdb at 0x201480
 *   fpu: float literal 0x00000000 at 0x201484
 *   fpu: float literal 0x40c90fdb at 0x2014a4
 *   fpu: mtc1 reinterprets v0 at 0x2014c8
 *   fpu: float literal 0x3eb2b020 at 0x201508
 *   fpu: float literal 0x40490fdb at 0x201514
 *   fpu: float literal 0x00000000 at 0x201518
 *   fpu: float literal 0x40c90fdb at 0x201538
 *   fpu: mtc1 reinterprets v0 at 0x20155c
 *   fpu: float literal 0x3eb2b020 at 0x2015a0
 *   fpu: float literal 0x40490fdb at 0x2015ac
 *   fpu: float literal 0x00000000 at 0x2015b0
 *   fpu: float literal 0x40c90fdb at 0x2015d0
 *   fpu: mtc1 reinterprets v0 at 0x2015f4
 *   cfg: kept branch: 0x201334 if (..) goto .L00201618
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

extern unsigned int CheckAnimEndFrame(void *);
extern int rand(void);

#define E3_PI 3.14159274f
#define E3_PI2 6.28318548f
#define E3_ADJ(a) (((a) + E3_PI >= 0.0f) ? ((a) - E3_PI2 * (float)(s32)(((a) + E3_PI) / E3_PI2)) : (E3_PI2 + ((a) - E3_PI2 * (float)(s32)(((a) + E3_PI) / E3_PI2))))


/* CheckE003StayState @ 0x201640 .. 0x201750 (0x110 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x201690 if (..) goto .L00201730
 *   cfg: kept branch: 0x2016e8 if (..) goto .L00201730
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

static unsigned int CheckE003RollState(void *, void *);
extern unsigned int CheckAnimEndFrame(void *);
extern int rand(void);

/* E003ThkWalk @ 0x201750 .. 0x20179C (0x4c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

static unsigned int CheckE003AttackState(void *, void *);
static unsigned int CheckE003WalkState(void *, void *);

/* E003ThkStay @ 0x2017A0 .. 0x2017EC (0x4c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

static unsigned int CheckE003AttackState(void *, void *);
static unsigned int CheckE003StayState(void *, void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * E003ThkInit(s32 a0 , u32 *a1 );
static void E003ThkStay(void *a0 , void *a1 );
static void E003ThkWalk(void *a0 , void *a1 );
static unsigned int CheckE003StayState(void *a0 , void *a1 );
static unsigned int CheckE003WalkState(void *a0 , void *a1 );
static unsigned int CheckE003AttackState(void *a0 , void *a1 );
static unsigned int CheckE003RollState(void *a0, void *a1);


/* E003ThkInit @ 0x2017F0 .. 0x20180C (0x1c bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */




u8 * E003ThkInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)E003ThkStay;
    *(u32 *)a1 = (u32)E003ThkStay;
    v1 = (u8 *)E003ThkWalk;
    *(u32 *)(((u8 *)a1 + 4)) = (u32)E003ThkWalk;
    return;
}

static void E003ThkStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 s1;
    u16 *s0;
    u32 v0;
    u32 v1;

    s1 = (u32)a0;
    s0 = (u16 *)a1;
    v0 = CheckE003AttackState(a0, a1);
    a0 = (void *)s1;
    if (v0 == 0) {
        a1 = (void *)s0;
        CheckE003StayState(a0, a1);
        v1 = *(u16 *)(((u8 *)s0 + 0x1dc));
        v1 = v1 + 1;
        *(u16 *)(((u8 *)s0 + 0x1dc)) = v1;
    }
    return;
}

static void E003ThkWalk(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 s1;
    u16 *s0;
    u32 v0;
    u32 v1;

    s1 = (u32)a0;
    s0 = (u16 *)a1;
    v0 = CheckE003AttackState(a0, a1);
    a0 = (void *)s1;
    if (v0 == 0) {
        a1 = (void *)s0;
        CheckE003WalkState(a0, a1);
        v1 = *(u16 *)(((u8 *)s0 + 0x1de));
        v1 = v1 + 1;
        *(u16 *)(((u8 *)s0 + 0x1de)) = v1;
    }
    return;
}

static unsigned int CheckE003StayState(void *a0 /* r4 */, void *a1 /* r5 */) {
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
            v0 = CheckE003RollState(a0, a1);
            if (v0 != 0) {
                v0 = 1;
            } else {
                a0 = (void *)(s32)s2;
                v0 = CheckAnimEndFrame(a0);
                if (v0 == 0) {
                    goto _L00201730;
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
                goto _L00201730;
            }
            v0 = *(s32 *)(s0 + 0x104);
            a0 = (void *)s1;
            a1 = (void *)s0;
            a2 = 0xa;
            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0, (u32)a1, a2);
            v0 = 1;
        } else {
            _L00201730:;
            v0 = 0;
        }
    }
    return v0;
}

static unsigned int CheckE003WalkState(void *a0 /* r4 */, void *a1 /* r5 */) {
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
            goto _L00201618;
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
                *(f32 *)(a0_bytes + 0x198) = E3_ADJ(3.14099979f + *(float *)(a0_bytes + 0x198));
            } else if ((s32)v0 <= (s32)0x13) {
                *(f32 *)(a0_bytes + 0x198) = E3_ADJ(*(float *)(a0_bytes + 0x198) - 3.14099979f);
            } else if ((s32)v0 <= (s32)0x31) {
                *(f32 *)(a0_bytes + 0x198) = E3_ADJ(0.348999977f + *(float *)(a0_bytes + 0x198));
            } else if ((s32)v0 <= (s32)0x4f) {
                *(f32 *)(a0_bytes + 0x198) = E3_ADJ(*(float *)(a0_bytes + 0x198) - 0.348999977f);
            }
        }
        _L00201618:;
        v0 = 0;
    }
    return v0;
}

static unsigned int CheckE003AttackState(void *a0 /* r4 */, void *a1 /* r5 */) {
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
        goto _L00201260;
    }
    v0 = 0;
    goto _L002012F0;
    _L00201260:;
    s3 = 0;
    do {
        a0 = (void *)s1;
        a1 = (void *)s0;
        v0 = EneSearchAttackRange(a0, a1, (u32)s3);
        if (v0 != 0) {
            v0 = *(u8 *)(s2 + 0xa5);
            if (v0 == 0) {
                goto _L002012A8;
            }
            a0 = (void *)s1;
            a1 = (void *)s0;
            v0 = SetE003ClingAndPush(a0, a1);
            if (v0 == 0) {
                goto _L002012D8;
            }
            goto _L002012C0;
            _L002012A8:;
            v0 = s3 + 0x32;
            a1 = (void *)(u16)v0;
            a0 = (void *)s1;
            ChangeAnimParam(a0, (signed int)a1, 0.0f);
            _L002012C0:;
            *(u8 *)(s1 + 0x12a) = s3;
            v0 = 1;
            *(u8 *)(s0 + 0x180) = 2;
            return v0;
        }
        _L002012D8:;
        s3 = s3 + 1;
        v0 = s3 < (s32)5;
        s2 = (u8 *)(s2 + 0x28);
    } while (v0 != 0);
    v0 = 0;
    _L002012F0:;
    return v0;
}

static unsigned int CheckE003RollState(void *a0, void *a1) {
    E003Ene *lpEne = a0;
    E003Ctrl *lpCtrl = a1;
    if (lpEne->alive == 0) {
        return 0;
    }
    if (lpEne->act == 0x12 || lpEne->act == 0x13) {
        return 0;
    }
    if (E3_ABS(Math_GetAngleDist(lpEne->rotY, lpEne->tgtRot)) < E3_HPI) {
        return 0;
    }
    if (E3_ABS(Math_GetAngleDist(E3_ADJ(lpEne->rotY + E3_HPI), lpEne->tgtRot)) < E3_HPI) {
        lpCtrl->SetAct(lpEne, lpCtrl, 0x13);
    } else {
        lpCtrl->SetAct(lpEne, lpCtrl, 0x12);
    }
    return 1;
}
