#include "common.h"

/* SetE003ClingAndPush @ 0x2008A0 .. 0x200AC4 (0x224 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: daddu at 0x2008f0 writes a register its branch at 0x2008ec reads
 *   delay: daddu at 0x200930 writes a register its branch at 0x20092c reads
 *   fpu: float literal 0x00000000 at 0x200948
 *   fpu: float literal 0x3e4ccccd at 0x20096c
 *   fpu: float literal 0x00000000 at 0x2009b0
 *   fpu: float literal 0x4027851e at 0x2009f4
 *   fpu: float literal 0x40490fdb at 0x200a0c
 *   fpu: float literal 0x00000000 at 0x200a20
 *   cfg: kept branch: 0x2008b0 if (..) goto .L002008E8
 *   cfg: kept goto: 0x2008e0 -> .L00200AA8
 *   cfg: kept branch: 0x200900 if (..) goto .L00200920
 *   cfg: kept goto: 0x200918 -> .L00200AA8
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u32 GetCamCtrlMode();
extern signed int CheckMyDamage(void *, void *);
extern float Math_GetAngleDist(float, float);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetMyDamage(void *, void *, unsigned short);
extern void ClearMyStruggleStick();
extern void SetEneFrontClingPos(void *, void *);

/* E003ActAttack @ 0x200AD0 .. 0x200E00 (0x330 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x200b1c
 *   fpu: mtc1 reinterprets v1 at 0x200b34
 *   fpu: float literal 0x41200000 at 0x200b4c
 *   delay: addiu at 0x200b74 writes a register its branch at 0x200b70 reads
 *   fpu: float literal 0x00000000 at 0x200bd8
 *   fpu: float literal 0x00000000 at 0x200c78
 *   fpu: float literal 0x00000000 at 0x200cf0
 *   fpu: float literal 0x00000000 at 0x200d0c
 *   fpu: float literal 0x3c8ef34d at 0x200dc8
 *   cfg: kept branch: 0x200b98 if (..) goto .L00200BC8
 *   cfg: kept goto: 0x200bb0 -> .L00200DA8
 *   cfg: kept branch: 0x200bc8 if (..) goto .L00200DA8
 *   cfg: kept goto: 0x200bdc -> .L00200DA8
 *   cfg: kept branch: 0x200bf0 if (..) goto .L00200C20
 *   cfg: kept goto: 0x200c08 -> .L00200DA8
 *   cfg: kept branch: 0x200c20 if (..) goto .L00200DA8
 *   cfg: kept branch: 0x200c60 if (..) goto .L00200DA8
 *   cfg: kept branch: 0x200c6c if (..) goto .L00200DA8
 *   cfg: kept goto: 0x200c7c -> .L00200DA8
 *   cfg: kept branch: 0x200ca0 if (..) goto .L00200CD0
 *   cfg: kept goto: 0x200cb8 -> .L00200DA8
 *   cfg: kept branch: 0x200cd0 if (..) goto .L00200DA8
 *   cfg: kept branch: 0x200ce0 if (..) goto .L00200D08
 *   cfg: kept goto: 0x200cf4 -> .L00200DA8
 *   cfg: kept goto: 0x200d08 -> .L00200DA8
 *   cfg: kept branch: 0x200d28 if (..) goto .L00200DA8
 */

extern signed int CheckEneClingOut();
extern void SetEneClingOut(void *, void *, unsigned short);
extern unsigned int CheckAnimEndFrame(void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern int rand(void);
extern void SetMyDamage(void *, void *, unsigned short);
extern void SetEneAttackOff(void *, void *);
extern void SetEneFrontClingPos(void *, void *);
extern float Math_GotoAngle(float, float, float);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * E003ActInit(s32 a0 , u32 *a1 );
static void E003ActStay(void *a0 );
static void E003ActWalk(void *a0 );
static void E003ActAttack(void *a0 , void *a1 );
signed int SetE003ClingAndPush(void *a0 , void *a1 );


/* E003ActInit @ 0x200F20 .. 0x200F48 (0x28 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */





u8 * E003ActInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)E003ActStay;
    *(u32 *)(((u8 *)a1 + 0x80)) = (u32)E003ActStay;
    v1 = (u8 *)E003ActWalk;
    *(u32 *)(((u8 *)a1 + 0x84)) = (u32)E003ActWalk;
    v1 = (u8 *)E003ActAttack;
    *(u32 *)(((u8 *)a1 + 0x88)) = (u32)E003ActAttack;
    return;
}

/* E003ActStay @ 0x200E90 .. 0x200F1C (0x8c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x200eb0
 *   fpu: mtc1 reinterprets v1 at 0x200ec8
 *   fpu: float literal 0x41200000 at 0x200ee0
 *   fpu: float literal 0x3c8ef34d at 0x200ee8
 */



static void E003ActStay(void *a0 /* r4 */) {
    u8 *s0;
    u32 v0;
    float f1;
    float f0;

    v0 = *(s32 *)(((u8 *)a0 + 0xc));
    v0 = *(s32 *)((v0 + 0x4c));
    v0 = *(u16 *)((v0 + 0x1c));
    s0 = (u8 *)a0;
    f1 = 10.0f;
    f0 = 0.0174499992f;
    f0 = Math_GotoAngle(*(float *)(s0 + 0x34), *(float *)(s0 + 0x198), (0.0174499992f *
        ((float)(float)v0 / 10.0f)));
    *(f32 *)(s0 + 0x34) = f0;
    return;
}

/* E003ActWalk @ 0x200E00 .. 0x200E8C (0x8c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x200e20
 *   fpu: mtc1 reinterprets v1 at 0x200e38
 *   fpu: float literal 0x41200000 at 0x200e50
 *   fpu: float literal 0x3c8ef34d at 0x200e58
 */



static void E003ActWalk(void *a0 /* r4 */) {
    u8 *s0;
    u32 v0;
    float f1;
    float f0;

    v0 = *(s32 *)(((u8 *)a0 + 0xc));
    v0 = *(s32 *)((v0 + 0x4c));
    v0 = *(u16 *)((v0 + 0x1a));
    s0 = (u8 *)a0;
    f1 = 10.0f;
    f0 = 0.0174499992f;
    f0 = Math_GotoAngle(*(float *)(s0 + 0x34), *(float *)(s0 + 0x198), (0.0174499992f *
        ((float)(float)v0 / 10.0f)));
    *(f32 *)(s0 + 0x34) = f0;
    return;
}

static void E003ActAttack(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s3;
    u8 *s2;
    s32 a2;
    u32 s1;
    u8 *s0;
    float f12;
    float f20;
    s32 v1;
    u32 v0;
    float f0;
    s32 hi;

    s3 = (u8 *)a0;
    v0 = *(s32 *)(((u8 *)a0 + 0xc));
    v1 = *(u8 *)(((u8 *)a0 + 0x12a));
    s1 = *(s32 *)(((u8 *)a0 + 0x100));
    s0 = (u8 *)*(s32 *)((v0 + 0x4c));
    v0 = (u32)v1 * (u32)(0x28);
    v0 = (s32)((u8 *)v0 + (u32)(s0));
    v0 = *(u16 *)((v0 + 0xaa));
    s2 = (u8 *)a1;
    v1 = *(s16 *)(s3 + 0x104);
    f0 = 10.0f;
    f20 = ((float)(float)v0 / 10.0f);
    v0 = 0x3f;
    switch ((u32)v1) {
    case 60:
        a0 = (void *)s3;
        a1 = (void *)s2;
        a2 = 0x7b;
        v0 = CheckEneClingOut(a0, a1, a2);
        a0 = (void *)s3;
        if (v0 == 0) {
            goto _L00200BC8;
        }
        a1 = (void *)s2;
        a2 = 0x3f;
        SetEneClingOut(a0, a1, a2);
        goto _L00200DA8;
        _L00200BC8:;
        a0 = (void *)(s32)s1;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            goto _L00200DA8;
        }
        f12 = 0.0f;
        a0 = (void *)s3;
        a1 = (void *)(s32)0x3d;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        goto _L00200DA8;
    case 61:
        a0 = (void *)s3;
        a1 = (void *)s2;
        a2 = 0x7b;
        v0 = CheckEneClingOut(a0, a1, a2);
        a0 = (void *)s3;
        if (v0 == 0) {
            goto _L00200C20;
        }
        a1 = (void *)s2;
        a2 = 0x3f;
        SetEneClingOut(a0, a1, a2);
        goto _L00200DA8;
        _L00200C20:;
        a0 = (void *)(s32)s1;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            goto _L00200DA8;
        }
        v0 = rand();
        v1 = 0x64;
        a0 = (void *)*(u8 *)(s0 + 0x31);
        hi = (s32)v0 % (s32)(0x64);
        v0 = *(s32 *)(s2 + 0x1e4);
        s0 = (u8 *)*(s32 *)((v0 + 0x148));
        v0 = hi;
        if ((u32)a0 == 0) {
            a0 = (void *)(s32)0x32;
        }
        if ((s32)a0 <= (s32)v0) {
            goto _L00200DA8;
        }
        v0 = *(s32 *)(s2 + 0x1e8);
        if (v0 != 0) {
            goto _L00200DA8;
        }
        f12 = 0.0f;
        a0 = (void *)s3;
        a1 = (void *)(s32)0x3e;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        a0 = (void *)*(s32 *)(s2 + 0x1e4);
        a1 = (void *)s0;
        a2 = 0x7a;
        SetMyDamage(a0, a1, a2);
        goto _L00200DA8;
    case 62:
        a0 = (void *)s3;
        a1 = (void *)s2;
        a2 = 0x7b;
        v0 = CheckEneClingOut(a0, a1, a2);
        a0 = (void *)s3;
        if (v0 == 0) {
            goto _L00200CD0;
        }
        a1 = (void *)s2;
        a2 = 0x3f;
        SetEneClingOut(a0, a1, a2);
        goto _L00200DA8;
        _L00200CD0:;
        a0 = (void *)(s32)s1;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            goto _L00200DA8;
        }
        v0 = *(s32 *)(s2 + 0x1e4);
        v0 = *(s32 *)((v0 + 0x120));
        if ((s32)v0 > 0) {
            goto _L00200D08;
        }
        f12 = 0.0f;
        a0 = (void *)s3;
        a1 = (void *)(s32)0x3e;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        goto _L00200DA8;
        _L00200D08:;
        a0 = (void *)s3;
        f12 = 0.0f;
        a1 = (void *)(s32)0x3d;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        v0 = *(u16 *)(s0 + 0x34);
        *(u32 *)(s2 + 0x1e8) = v0;
        goto _L00200DA8;
    case 63:
    default:
        a0 = (void *)(s32)s1;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            goto _L00200DA8;
        }
        *(u8 *)(s3 + 0x130) = 0;
        *(u8 *)(s3 + 0x131) = 0;
        *(u32 *)(s2 + 0x1e4) = 0;
        v1 = *(u8 *)(s3 + 0x12a);
        v0 = (u32)v1 * (u32)(0x28);
        v0 = (s32)((u8 *)v0 + (u32)(s0));
        v0 = *(u16 *)((v0 + 0xb2));
        *(u32 *)(s2 + 0x1e8) = v0;
        v0 = *(s32 *)(s3 + 0x1b4);
        if (v0 != 0 && (u32)*(s32 *)(s2 + 0x1e8) != 0) {
            a0 = (void *)s3;
            a1 = (void *)s2;
            SetEneAttackOff(a0, a1);
            break;
        } else {
            v0 = *(s32 *)(s2 + 0x100);
            a0 = (void *)s3;
            a1 = (void *)s2;
            a2 = 2;
            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0, (u32)a1, a2);
        }
    }
    *(f32 *)(s3 + 0x198) = *(float *)(s3 + 0x34);
    _L00200DA8:;
    v0 = *(s32 *)(s2 + 0x1e4);
    a1 = (void *)s2;
    if (v0 != 0) {
        a0 = (void *)s3;
        SetEneFrontClingPos(a0, a1);
    }
    f0 = 0.0174499992f;
    f12 = *(float *)(s3 + 0x34);
    f0 = Math_GotoAngle(f12, *(float *)(s3 + 0x198), (0.0174499992f * f20));
    *(f32 *)(s3 + 0x34) = f0;
    return;
}

signed int SetE003ClingAndPush(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s3;
    u8 *s2;
    u8 *s1;
    u32 v1;
    u8 *s0;
    float f13;
    float f12;
    u32 v0;
    float f1;
    float f0;
    u8 *a0_2;
    void *a1_2;

    s3 = (u8 *)a0;
    s1 = (u8 *)*(s32 *)((*(s32 *)(((u8 *)a0 + 0xc)) + 0x4c));
    v0 = *(s32 *)((*(s32 *)(((u8 *)a0 + 0x1b4)) + 0xc));
    v1 = *(s32 *)((v0 + 0x4c));
    s2 = (u8 *)a1;
    if (*(u16 *)((v0 + 0xa)) == 0) {
        goto _L002008E8;
    }
    v0 = 0;
    goto _L00200AA8;
    _L002008E8:;
    v0 = *(u8 *)((v1 + 9));
    if (v0 == 0) {
        v0 = 0;
        return v0;
    }
    v1 = 2;
    if ((u32)GetCamCtrlMode() != v1) {
        goto _L00200920;
    }
    v0 = 0;
    goto _L00200AA8;
    _L00200920:;
    a0_2 = (u8 *)*(s32 *)(s3 + 0x1b4);
    s0 = (u8 *)*(s32 *)(a0_2 + 0x148);
    if (*(u16 *)(s0 + 0x1cc) != 0) {
        return 0;
    }
    f0 = 0.0f;
    f1 = (*(float *)(s3 + 0x24) - *(float *)(a0_2 + 0x24));
    f1 = f1 < 0.0f ? (-f1) : f1;
    f0 = 0.200000003f;
    if (!(f1 <= 0.200000003f)) {
        return 0;
    }
    a1_2 = (void *)s3;
    v0 = CheckMyDamage((void *)a0_2, a1_2);
    if (v0 == 0) {
        v0 = 0;
    } else {
        f13 = *(float *)((*(s32 *)(s3 + 0x1b4) + 0x34));
        f12 = *(float *)(s3 + 0x34);
        f1 = 0.0f;
        if (Math_GetAngleDist(f12, f13) < 0.0f) {
            f13 = *(float *)((*(s32 *)(s3 + 0x1b4) + 0x34));
            f12 = *(float *)(s3 + 0x34);
            f0 = (-Math_GetAngleDist(f12, f13));
        } else {
            f13 = *(float *)((*(s32 *)(s3 + 0x1b4) + 0x34));
            f12 = *(float *)(s3 + 0x34);
            f0 = Math_GetAngleDist(f12, f13);
        }
        v0 = 0x4027851e;
        f1 = 2.61749983f;
        if (2.61749983f < f0) {
            v0 = 0x40490fdb;
            f1 = 3.14159274f;
            if (f0 < 3.14159274f) {
                f12 = 0.0f;
                ChangeAnimParam((void *)s3, 0x3c, 0.0f);
                v1 = 0x7c;
                v0 = 1;
                *(u32 *)(s2 + 0x1e4) = *(s32 *)(s3 + 0x1b4);
                *(u16 *)(s2 + 0x1e2) = v1;
                *(u8 *)(s3 + 0x130) = v0;
                *(u8 *)(s3 + 0x131) = v0;
                *(u8 *)(s3 + 0x132) = v0;
                SetMyDamage((void *)*(s32 *)(s2 + 0x1e4), (void *)s0, 0x78);
                ClearMyStruggleStick(*(s32 *)(s2 + 0x1e4), (s32)s0);
                a0_2 = s3;
                a1_2 = (void *)s2;
                SetEneFrontClingPos((void *)a0_2, a1_2);
                *(u8 *)(s2 + 0x246) = 0;
                *(u8 *)(s2 + 0x247) = 0;
            }
        }
        v0 = *(u8 *)(s1 + 0x2f);
        if (v0 == 0) {
            *(u8 *)(s0 + 0x1af) = 0x32;
        } else {
            *(u8 *)(s0 + 0x1af) = v0;
        }
        v0 = 1;
    }
    _L00200AA8:;
    return v0;
}
