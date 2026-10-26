#include "common.h"

/* SetE042ClingAndPush @ 0x1A8920 .. 0x1A8A4C (0x12c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1a8988 writes a register its branch at 0x1a8984 reads
 *   delay: daddu at 0x1a89a0 writes a register its branch at 0x1a899c reads
 *   delay: daddu at 0x1a89bc writes a register its branch at 0x1a89b8 reads
 *   fpu: float literal 0x00000000 at 0x1a89cc
 *   cfg: kept branch: 0x1a8930 if (..) goto .L001A8960
 *   cfg: kept goto: 0x1a895c -> .L001A8A30
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern float Math_GetAngleDist(float, float);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetMyDamage(void *, void *, unsigned short);
extern void ClearMyStruggleStick();
extern void SetEneBackClingPos(void *, void *);

/* E042ActAttack @ 0x1A8A50 .. 0x1A8C94 (0x244 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x1a8a98
 *   fpu: mtc1 reinterprets v1 at 0x1a8ab0
 *   fpu: float literal 0x41200000 at 0x1a8ac8
 *   fpu: float literal 0x00000000 at 0x1a8b2c
 *   fpu: float literal 0x00000000 at 0x1a8b50
 *   fpu: float literal 0x00000000 at 0x1a8b94
 *   fpu: float literal 0x3d23d70a at 0x1a8c10
 *   fpu: float literal 0x3ca3d70a at 0x1a8c28
 *   fpu: float literal 0x3c8ef34d at 0x1a8c60
 */

extern u32 EneSetTarget();
extern unsigned int CheckAnimEndFrame(void *);
extern void EneDeadProc(void *, void *);
extern float Math_GotoAngle(float, float, float);
extern u32 MdlMng[];

/* E042ActStay @ 0x1A8CA0 .. 0x1A8D10 (0x70 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u32 EneSetTarget();
extern void sceVu0CopyVector(void *, void *);
extern signed int SetE042ClingAndPush(void *, void *);
extern u32 MdlMng[];

/* E042ActInit @ 0x1A8D10 .. 0x1A8D48 (0x38 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

static void E042ActAttack(void *a0 /* r4 */, void *a1 /* r5 */);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void E042ActInit(void *a0 , void *a1 );
static u32 E042ActStay(u8 *a0 , u8 *a1 );
static void E042ActAttack(void *a0 , void *a1 );
signed int SetE042ClingAndPush(void *a0 , void *a1 );


void E042ActInit(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)E042ActStay;
    *(u32 *)(((u8 *)a1 + 0x80)) = (u32)E042ActStay;
    v1 = (u8 *)E042ActAttack;
    *(u32 *)(((u8 *)a1 + 0x88)) = (u32)E042ActAttack;
    v1 = (u8 *)0xffff;
    *(u16 *)(((u8 *)a1 + 0x1fa)) = 0xffff;
    v1 = (u8 *)(s32)1;
    *(u8 *)(((u8 *)a1 + 0x1da)) = (s32)v1;
    *(u8 *)(((u8 *)a0 + 0x130)) = (s32)v1;
    *(u8 *)(((u8 *)a0 + 0x132)) = (s32)v1;
    *(u8 *)(((u8 *)a0 + 0x131)) = (s32)v1;
    return;
}

static u32 E042ActStay(u8 *a0 /* r4 */, u8 *a1 /* r5 */) {
    u32 s2;
    u32 s1;
    float *s0;
    float f0;

    s2 = (u32)a0;
    s1 = (u32)a1;
    s0 = (float *)((u8 *)MdlMng + 0x11800);
    EneSetTarget(a0, a1, (u32)s0);
    a0 = (u8 *)(s2 + 0x20);
    a1 = (u8 *)s0 + 0x20;
    sceVu0CopyVector(a0, a1);
    f0 = *(float *)((s2 + 0x34));
    a0 = (u8 *)s2;
    a1 = (u8 *)s1;
    *(f32 *)(((u8 *)s0 + 0x34)) = f0;
    SetE042ClingAndPush(a0, a1);
    *(u8 *)((s2 + 0x12a)) = 0;
    *(u8 *)((s1 + 0x180)) = 2;
    return;
}

static void E042ActAttack(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    u32 s0;
    u32 v1;
    float f12;
    float f1;
    u32 v0;
    float f20;
    float f0;
    void *a1_2;

    s2 = (u8 *)a0;
    s0 = *(s32 *)(((u8 *)a0 + 0x100));
    v0 = *(s32 *)(((u8 *)a0 + 0xc));
    v1 = *(u8 *)(((u8 *)a0 + 0x12a));
    a0 = (void *)*(s32 *)((v0 + 0x4c));
    v0 = v1 * (u32)(0x28);
    v0 = (s32)((u8 *)v0 + (u32)(a0));
    v0 = *(u16 *)((v0 + 0xaa));
    s1 = (u8 *)a1;
    f1 = (float)v0;
    f0 = 10.0f;
    a0 = (void *)s2;
    a1_2 = (void *)s1;
    f20 = (f1 / 10.0f);
    EneSetTarget(a0, a1_2, (u8 *)(u8 *)(MdlMng + 0x4600));
    v1 = *(s16 *)(s2 + 0x104);
    a1_2 = (void *)(s32)0x67;
    v0 = 0x65;
    switch (v1) {
    case 100:
        v1 = *(s32 *)(s1 + 0x1e4);
        v0 = 0x99;
        v1 = *(s16 *)((v1 + 0x104));
        if (v1 == v0) {
            f12 = 0.0f;
            a0 = (void *)s2;
            ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        } else {
            a0 = (void *)(s32)s0;
            v0 = CheckAnimEndFrame(a0);
            if (v0 != 0) {
                f12 = 0.0f;
                a0 = (void *)s2;
                a1_2 = (void *)(s32)0x65;
                ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
                *(u16 *)(s1 + 0x1dc) = 0;
            }
        }
        a1_2 = (void *)s1;
        a0 = (void *)s2;
        SetEneBackClingPos(a0, a1_2);
        break;
    case 101:
        v1 = *(s32 *)(s1 + 0x1e4);
        v0 = 0x99;
        v1 = *(s16 *)((v1 + 0x104));
        if (v1 == v0) {
            f12 = 0.0f;
            a0 = (void *)s2;
            ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        } else {
            v1 = *(u16 *)(s1 + 0x1dc);
            v0 = 0x12c;
            v1 = v1 + 1;
            *(u16 *)(s1 + 0x1dc) = v1;
            v1 = (u16)v1;
            if (v1 == v0) {
                v0 = *(s32 *)(s2 + 0x1b4);
                v1 = 0xff;
                *(u8 *)(((*(s32 *)((v0 + 0x148))) + 0x1af)) = v1;
            }
        }
        a1_2 = (void *)s1;
        a0 = (void *)s2;
        SetEneBackClingPos(a0, a1_2);
        break;
    case 103:
        a0 = (void *)(s32)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        *(u32 *)(s1 + 0x1e4) = 0;
        f1 = *(float *)(s2 + 0x10c);
        v0 = 0x3d23d70a;
        f0 = 0.0399999991f;
        if (!(f1 < 0.0399999991f)) {
            v0 = 0x3ca3d70a;
            f0 = 0.0199999996f;
            f0 = (f1 - 0.0199999996f);
            *(f32 *)(s2 + 0x10c) = f0;
            break;
        } else {
            *(u32 *)(s2 + 0x10c) = 0;
            v0 = 1;
            a0 = (void *)s2;
            *(u8 *)(s1 + 0x1f3) = v0;
            a1_2 = (void *)s1;
            EneDeadProc(a0, a1_2);
        }
    }
    f0 = 0.0174499992f;
    f0 = Math_GotoAngle(*(float *)(s2 + 0x34), *(float *)(s2 + 0x198), (0.0174499992f * f20));
    *(f32 *)(s2 + 0x34) = f0;
    return;
}

signed int SetE042ClingAndPush(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s3;
    u8 *s2;
    u8 *s1;
    float f13;
    float f12;
    u8 *s0;
    u32 v1;
    u32 v0;

    s3 = (u8 *)a0;
    v0 = *(s32 *)(((u8 *)a0 + 0xc));
    v1 = *(s32 *)(((u8 *)a0 + 0x1b4));
    s1 = (u8 *)*(s32 *)((v0 + 0x4c));
    v0 = *(s32 *)((v1 + 0xc));
    v0 = *(u16 *)((v0 + 0xa));
    s2 = (u8 *)a1;
    if (v0 == 0) {
        goto _L001A8960;
    }
    v0 = 0;
    goto _L001A8A30;
    _L001A8960:;
    f13 = *(float *)((v1 + 0x34));
    f12 = *(float *)(s3 + 0x34);
    s0 = (u8 *)*(s32 *)((v1 + 0x148));
    Math_GetAngleDist(f12, f13);
    v0 = *(s32 *)(s3 + 0x1b4);
    f13 = *(float *)((v0 + 0x34));
    f12 = *(float *)(s3 + 0x34);
    Math_GetAngleDist(f12, f13);
    v0 = *(u8 *)(s0 + 0x18a);
    if (v0 != 0) {
        v0 = 0;
        return v0;
    }
    v0 = *(u8 *)(s0 + 0x189);
    if (v0 != 0) {
        v0 = 0;
        return v0;
    }
    v1 = *(u8 *)(s0 + 0x100);
    v0 = 6;
    if (v1 == v0) {
        v0 = 0;
        return v0;
    }
    a0 = (void *)s3;
    f12 = 0.0f;
    a1 = (void *)(s32)0x64;
    ChangeAnimParam(a0, (signed int)a1, 0.0f);
    v0 = *(s32 *)(s3 + 0x1b4);
    a1 = (void *)s0;
    *(u32 *)(s2 + 0x1e4) = v0;
    a0 = (void *)*(s32 *)(s2 + 0x1e4);
    SetMyDamage(a0, a1, 0x96);
    a0 = (void *)*(s32 *)(s2 + 0x1e4);
    a1 = (void *)s0;
    ClearMyStruggleStick(a0, a1);
    a0 = (void *)s3;
    a1 = (void *)s2;
    SetEneBackClingPos(a0, a1);
    v0 = *(u8 *)(s1 + 0x2f);
    if (v0 == 0) {
        v0 = 0x32;
        *(u8 *)(s0 + 0x1af) = v0;
    } else {
        *(u8 *)(s0 + 0x1af) = v0;
    }
    v0 = 1;
    _L001A8A30:;
    return v0;
}
