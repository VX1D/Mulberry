#include "common.h"

/* GetE022DamageAnim @ 0x194380 .. 0x1947A0 (0x420 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490fdb at 0x1943f0
 *   fpu: float literal 0x00000000 at 0x1943f4
 *   fpu: float literal 0x40c90fdb at 0x194418
 *   fpu: mtc1 reinterprets v0 at 0x19443c
 *   delay: addiu at 0x194524 writes a register its branch at 0x194520 reads
 *   fpu: float literal 0x00000000 at 0x1945f4
 *   fpu: float literal 0x3fc90624 at 0x194614
 *   fpu: float literal 0x00000000 at 0x194640
 *   fpu: mov.s at 0x194650 is a float copy
 *   fpu: float literal 0x3f490624 at 0x194660
 *   fpu: float literal 0x00000000 at 0x194680
 *   fpu: mov.s at 0x194690 is a float copy
 *   fpu: float literal 0x4016c49b at 0x1946a0
 *   fpu: float literal 0x00000000 at 0x1946c0
 *   fpu: float literal 0x00000000 at 0x1946f8
 *   fpu: float literal 0x3fc90624 at 0x194718
 *   delay: addiu at 0x19476c writes a register its branch at 0x194768 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern float Math_VectorToAngle(float, float);
extern signed int SFX_Delete();
extern int rand();
extern signed int SFX_Create_OnAng_Attach(unsigned short, float *, float *, void *, unsigned short,
    unsigned char, unsigned char);
extern unsigned int CheckAnimParam(void *, signed int);
extern u32 V0[];
extern u32 VW[];

#ifndef DCOMP_EXPR_405892EAFA68827F
#define DCOMP_EXPR_405892EAFA68827F(dcomp_arg) ((dcomp_arg) < 0.0f ? (-(dcomp_arg)) : (float)(dcomp_arg))
#endif
#ifndef DCOMP_EXPR_CFEF94067507FB7D
#define DCOMP_EXPR_CFEF94067507FB7D(dcomp_arg) ((dcomp_arg) < 0.0f ? (-(dcomp_arg)) : (dcomp_arg))
#endif


/* CalcE022Damage @ 0x1947A0 .. 0x194920 (0x180 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42c80000 at 0x194808
 *   fpu: mtc1 reinterprets v0 at 0x194814
 *   fpu: float literal 0x42c80000 at 0x194848
 *   fpu: mtc1 reinterprets v0 at 0x194854
 *   fpu: mtc1 reinterprets v0 at 0x194880
 *   fpu: mtc1 reinterprets v1 at 0x194894
 *   fpu: float literal 0x40400000 at 0x1948a8
 *   fpu: mtc1 reinterprets v0 at 0x1948c8
 *   fpu: mtc1 reinterprets v1 at 0x1948dc
 *   fpu: float literal 0x3f800000 at 0x1948fc
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern int rand();

struct dw_1434568;
#ifndef PROTO_DW_1424954
#define PROTO_DW_1424954
struct dw_1424954 { unsigned int power; unsigned char per; unsigned char clingAt; unsigned char pushAt; unsigned char blowAt; unsigned short ang; unsigned short angCorrect; unsigned short area[2]; unsigned char finish; unsigned char damageID; unsigned short waitTime; unsigned char pullAt; unsigned char pauseAt; unsigned char recover; unsigned char fire; unsigned char perframe; unsigned char disnodamage; unsigned char blastAt; unsigned char unused1[13]; };
#endif
#ifndef PROTO_DW_1428974
#define PROTO_DW_1428974
struct dw_1428974 { float DmgPos[4]; struct dw_1434568 *lpTarget; void *lpMasterPrm; unsigned char TeamNo; unsigned char AttackNo; unsigned short PauseTime; unsigned char bFinish; unsigned char unused[3]; float PowerScl; unsigned char _pad0[12]; };
#endif

/* SetE022Jump @ 0x194920 .. 0x194938 (0x18 bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x194928
 *   tail: j ChangeAnimParam at 0x194930 leaves the function
 *   a0 forwarded to ChangeAnimParam
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);

/* E022ActJump @ 0x194940 .. 0x194CF4 (0x3b4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: addiu at 0x194978 writes a register its branch at 0x194974 reads
 *   fpu: float literal 0x41f00000 at 0x194998
 *   fpu: float literal 0x3cd66cf4 at 0x1949c0
 *   fpu: float literal 0x420c0000 at 0x1949dc
 *   fpu: float literal 0x428c0000 at 0x1949f0
 *   fpu: float literal 0x3fc90fdb at 0x194a28
 *   fpu: float literal 0x3cd66cf4 at 0x194a2c
 *   fpu: float literal 0x428c0000 at 0x194a44
 *   fpu: float literal 0x3c23d70a at 0x194a64
 *   fpu: float literal 0x00000000 at 0x194a94
 *   fpu: float literal 0x41f00000 at 0x194b04
 *   fpu: float literal 0x42200000 at 0x194b18
 *   fpu: float literal 0x3e19999a at 0x194b44
 *   fpu: float literal 0x3c0ef34d at 0x194b5c
 *   fpu: float literal 0x42200000 at 0x194b74
 *   fpu: float literal 0x42480000 at 0x194b88
 *   fpu: float literal 0x40200000 at 0x194bb8
 *   fpu: float literal 0x42480000 at 0x194bd4
 *   fpu: float literal 0x3e4ccccd at 0x194be4
 *   fpu: mov.s at 0x194c04 is a float copy
 *   fpu: float literal 0x3c0ef34d at 0x194c24
 *   fpu: float literal 0x3e99999a at 0x194c58
 *   fpu: float literal 0x3c0ef34d at 0x194c70
 *   fpu: mov.s at 0x194c88 is a float copy
 *   cfg: kept branch: 0x1949f0 if (..) goto .L00194A40
 *   cfg: kept branch: 0x194b18 if (..) goto .L00194B70
 *   cfg: kept branch: 0x194ba8 if (..) goto .L00194C38
 */

extern void SetModelTargetToPos(void *, float *);
extern float Math_GotoAngle(float, float, float);
extern unsigned int Math_GotoVectorXZ(float *, float *, float);
extern unsigned int Math_GotoVector(float *, float *, float);
extern unsigned int CheckAnimEndFrame(void *);
extern void sceVu0CopyVector(void *, void *);
extern float Math_GetDistXZ(float *, float *);
extern unsigned int CheckAnimNumFrame(void *, float);
extern u32 E022JumpDst[];

struct dw_1439064;
struct dw_1440383;
struct dw_1444702;
struct dw_1444991;
#ifndef PROTO_DW_1440383
#define PROTO_DW_1440383
struct dw_1440383 {
    float NumFrame;
    float PrevFrame;
    float StartFrame;
    float EndFrame;
    float MaxFrame;
    float HokanFrame;
    int ObjId;
    float AnimSpeed;
    unsigned int ObjGroup;
    unsigned int Flag;
    unsigned char Loop;
    unsigned char ClothJoint;
    short State;
    struct dw_1444702 *lpMi3Head;
    struct dw_1444991 *lpMi3Obj;
    float (*lpVector)[3];
    struct dw_1439064 *lpTod;
    unsigned char _pad0[4];
    float Pos[4];
    float Ang[4];
    float Scl[4];
    float UserScl[4];
    float LocalMat[4][4];
    struct dw_1440383 *lpParent;
    struct dw_1440383 *lpChild;
    struct dw_1440383 *lpSibling;
    void *lpHokanFunc;
};
#endif

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * E022ActInit(s32 a0 , u32 *a1 );
static void E022ActDamage(void *a0, void *a1);
static void E022ActJump(void *a0 , void *a1 );
static void SetE022Jump(void *a0 , void *a1 , unsigned short a2 );
static signed int CalcE022Damage(void *a0 );
static signed int GetE022DamageAnim(void *a0 );



/* E022ActInit @ 0x194E30 .. 0x194E70 (0x40 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */







u8 * E022ActInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)E022ActDamage;
    *(u32 *)(((u8 *)a1 + 0x8c)) = (u32)E022ActDamage;
    v1 = (u8 *)E022ActJump;
    *(u32 *)(((u8 *)a1 + 0xa0)) = (u32)E022ActJump;
    v1 = (u8 *)GetE022DamageAnim;
    *(u32 *)(((u8 *)a1 + 0x184)) = (u32)GetE022DamageAnim;
    v1 = (u8 *)CalcE022Damage;
    *(u32 *)(((u8 *)a1 + 0x188)) = (u32)CalcE022Damage;
    v1 = (u8 *)SetE022Jump;
    *(u32 *)(((u8 *)a1 + 0x120)) = (u32)SetE022Jump;
    return;
}

static void E022ActDamage(void *a0, void *a1) {
    u8 *s2;
    u8 *s1;
    u8 *s0;
    u32 v0;
    s2 = (u8 *)a0;
    s1 = (u8 *)a1;
    s0 = (u8 *)*(s32 *)(s2 + 0x100);
    if (*(u16 *)(s1 + 0x1ee) != 0) {
        v0 = CheckAnimNumFrame((void *)s0, 23.0f);
        if (v0 != 0) {
            *(u16 *)(s2 + 0x106) = 2;
            *(u16 *)(s1 + 0x1ee) = *(u16 *)(s1 + 0x1ee) - 1;
        }
    } else {
        *(u16 *)(s2 + 0x106) = 0;
    }
    v0 = CheckAnimEndFrame((void *)s0);
    if (v0 != 0) {
        __asm__ volatile(
            ".set noreorder\n"
            "lh $3, 0x104(%0)\n"
            "addiu $2, $0, 0x20\n"
            "beq $3, $2, E022ActDamageAsmCase\n"
            "addiu $2, $0, 0x1e\n"
            "beq $3, $2, E022ActDamageAsmCase\n"
            "nop\n"
            "b E022ActDamageAsmDefault\n"
            "nop\n"
            "E022ActDamageAsmCase:\n"
            "addiu $2, $3, 1\n"
            "andi $6, $2, 0xffff\n"
            "daddu $4, %0, $0\n"
            "lw $2, 0x10c(%1)\n"
            "jalr $31, $2\n"
            "daddu $5, %1, $0\n"
            "b E022ActDamageAsmEnd\n"
            "nop\n"
            "E022ActDamageAsmDefault:\n"
            "lw $2, 0x158(%0)\n"
            "addiu $6, $0, 2\n"
            "bne $2, $6, E022ActDamageAsmOther\n"
            "nop\n"
            "lw $2, 0x120(%1)\n"
            "daddu $4, %0, $0\n"
            "daddu $5, %1, $0\n"
            "jalr $31, $2\n"
            "addiu $6, $0, 0x59\n"
            "b E022ActDamageAsmEnd\n"
            "nop\n"
            "nop\n"
            "E022ActDamageAsmOther:\n"
            "lw $2, 0x1b4(%0)\n"
            "beqz $2, E022ActDamageAsmFallback\n"
            "nop\n"
            "lw $2, 0x104(%1)\n"
            "daddu $4, %0, $0\n"
            "daddu $5, %1, $0\n"
            "jalr $31, $2\n"
            "addiu $6, $0, 0xb\n"
            "b E022ActDamageAsmEnd\n"
            "nop\n"
            "E022ActDamageAsmFallback:\n"
            "lw $2, 0x100(%1)\n"
            "daddu $4, %0, $0\n"
            "jalr $31, $2\n"
            "daddu $5, %1, $0\n"
            "E022ActDamageAsmEnd:\n"
            ".set reorder\n"
            :
            : "r"(s2), "r"(s1)
            : "$2", "$3", "$4", "$5", "$6", "$31", "memory");
    }
}

static void E022ActJump(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    s32 a2;
    struct dw_1440383 *s0;
    float f14;
    float f13;
    float f12;
    float f2;
    float f1;
    u32 v1;
    u32 v0;
    float f20;
    float f0;
    void *a0_2;
    void *a1_2;

    v1 = 0x59;
    s1 = (u8 *)a1;
    a1_2 = (void *)*(s16 *)(((u8 *)a0 + 0x104));
    s0 = (struct dw_1440383 *)*(s32 *)(((u8 *)a0 + 0x100));
    s2 = (u8 *)a0;
    switch ((u32)a1_2) {
    case 87:
        v0 = 0x41f00000;
        f1 = s0->NumFrame;
        f0 = 30.0f;
        if (f1 < 30.0f) {
            a1_2 = (void *)E022JumpDst;
            SetModelTargetToPos(a0, (float *)E022JumpDst);
            f13 = *(float *)(s2 + 0x198);
            f14 = 0.0261749998f;
            f12 = *(float *)(s2 + 0x34);
            f0 = Math_GotoAngle(f12, f13, 0.0261749998f);
            *(f32 *)(s2 + 0x34) = f0;
        } else {
            f0 = 35.0f;
            v0 = 0x428c0000;
            if (35.0f <= f1) {
                f0 = 70.0f;
                if (!(f1 < 70.0f)) {
                    goto _L00194A40;
                }
                a1_2 = (void *)E022JumpDst;
                Math_GotoVectorXZ((float *)(s2 + 0x20), (float *)E022JumpDst, *(float *)(s2 +
                    0x50));
                f13 = 1.57079637f;
                f14 = 0.0261749998f;
                f12 = *(float *)(s2 + 0x34);
                f0 = Math_GotoAngle(f12, 1.57079637f, 0.0261749998f);
                *(f32 *)(s2 + 0x34) = f0;
            } else {
                _L00194A40:;
                v0 = 0x428c0000;
                f0 = 70.0f;
                if (!(f1 <= 70.0f)) {
                    f12 = 0.00999999978f;
                    a1_2 = (void *)E022JumpDst;
                    Math_GotoVector((float *)(s2 + 0x20), (float *)E022JumpDst, 0.00999999978f);
                }
            }
        }
        a0_2 = (void *)(u8 *)s0;
        v0 = CheckAnimEndFrame(a0_2);
        if (v0 == 0) {
            break;
        }
        a1_2 = (void *)E022JumpDst;
        sceVu0CopyVector((void *)(s2 + 0x20), (void *)E022JumpDst);
        v1 = s0->Flag;
        v0 = -0x11;
        f12 = 0.0f;
        a0_2 = (void *)s2;
        a1_2 = (void *)(s32)0x58;
        v0 = v1 & (u32)v0;
        s0->Flag = v0;
        ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
        break;
    case 88:
        a0_2 = (void *)(u8 *)s0;
        v0 = CheckAnimEndFrame(a0_2);
        if (v0 == 0) {
            break;
        }
        v1 = s0->Flag;
        v0 = -0x21;
        a0_2 = (void *)s2;
        a1_2 = (void *)s1;
        v0 = v1 & (u32)v0;
        s0->Flag = v0;
        v0 = *(s32 *)(s1 + 0x100);
        a2 = 0x5a;
        ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
        break;
    case 89:
        *(u8 *)(s2 + 0x130) = 0;
        f1 = s0->NumFrame;
        f0 = 30.0f;
        v0 = 0x42200000;
        if (30.0f <= f1) {
            f20 = 40.0f;
            if (!(f1 <= 40.0f)) {
                goto _L00194B70;
            }
            a1_2 = (void *)(u8 *)(E022JumpDst + 4);
            SetModelTargetToPos(a0, (float *)a1_2);
            f12 = 0.150000006f;
            a1_2 = (void *)(u8 *)(E022JumpDst + 4);
            Math_GotoVectorXZ((float *)(s2 + 0x20), (float *)a1_2, 0.150000006f);
            f13 = *(float *)(s2 + 0x198);
            f14 = 0.00872499961f;
            f0 = Math_GotoAngle(*(float *)(s2 + 0x34), f13, 0.00872499961f);
            *(f32 *)(s2 + 0x34) = f0;
        } else {
            _L00194B70:;
            f20 = 40.0f;
            v0 = 0x42480000;
            if (40.0f <= f1) {
                f0 = 50.0f;
                if (f1 <= 50.0f) {
                    v0 = *(s32 *)(s2 + 0x1b4);
                    if (v0 != 0) {
                        a1_2 = (void *)(s32)(v0 + 0x20);
                        a0_2 = (void *)(u8 *)(E022JumpDst + 4);
                        f0 = Math_GetDistXZ((float *)a0_2, (float *)a1_2);
                        v0 = 0x40200000;
                        f1 = 2.5f;
                        if (!(f0 < 2.5f)) {
                            goto _L00194C38;
                        }
                        f1 = *(float *)(s2 + 0x19c);
                        v0 = 0x3e4ccccd;
                        f0 = 0.200000003f;
                        f2 = (50.0f - s0->NumFrame);
                        f12 = (f1 / f2);
                        if (!(f12 <= 0.200000003f)) {
                            f12 = f0;
                        }
                        a1_2 = (void *)(s32)(*(s32 *)(s2 + 0x1b4) + 0x20);
                        Math_GotoVectorXZ((float *)(s2 + 0x20), (float *)a1_2, f12);
                        f13 = *(float *)(s2 + 0x198);
                        f14 = 0.00872499961f;
                        f0 = Math_GotoAngle(*(float *)(s2 + 0x34), f13, 0.00872499961f);
                        *(f32 *)(s2 + 0x34) = f0;
                    } else {
                        _L00194C38:;
                        SetModelTargetToPos((void *)s2, (float *)(u8 *)(E022JumpDst + 4));
                        f12 = 0.300000012f;
                        a1_2 = (void *)(u8 *)(E022JumpDst + 4);
                        Math_GotoVectorXZ((float *)(s2 + 0x20), (float *)a1_2, 0.300000012f);
                        f13 = *(float *)(s2 + 0x198);
                        f14 = 0.00872499961f;
                        f0 = Math_GotoAngle(*(float *)(s2 + 0x34), f13, 0.00872499961f);
                        *(f32 *)(s2 + 0x34) = f0;
                    }
                }
            }
        }
        f12 = f20;
        v0 = CheckAnimNumFrame((void *)(u8 *)s0, f12);
        if (v0 != 0) {
            *(u8 *)(s2 + 0x132) = 0;
        }
        a0_2 = (void *)(u8 *)s0;
        v0 = CheckAnimEndFrame(a0_2);
        if (v0 == 0) {
            break;
        }
        *(u8 *)(s2 + 0x131) = 0;
        v0 = -0x11;
        *(u8 *)(s2 + 0x132) = 0;
        a0_2 = (void *)s2;
        v1 = s0->Flag;
        a1_2 = (void *)s1;
        v0 = v1 & (u32)v0;
        s0->Flag = v0;
        v0 = *(s32 *)(s1 + 0x100);
        a2 = 2;
        ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
        *(u32 *)(s2 + 0x158) = 0;
    }
    return;
}

static void SetE022Jump(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    *(u8 *)(((u8 *)a1 + 0x180)) = 8;
    a1 = (void *)(u16)a2;
    ChangeAnimParam(a0, (signed int)a1, (float)({ float native_result_0; __asm__("mtc1 %1,%0" :
        "=f"(native_result_0) : "r"((u32)0)); native_result_0; }));
    return;
}

static signed int CalcE022Damage(void *a0 /* r4 */) {
    struct dw_1428974 *s1;
    u32 v1;
    struct dw_1424954 *s0;
    u32 v0;
    float f3;
    float f1;
    float f0;

    s1 = (struct dw_1428974 *)a0;
    s0 = (struct dw_1424954 *)(s32)((u32)(*(s32 *)(((u8 *)a0 + 0x14)) + (u32)((u32)*(u8 *)(((u8
        *)a0 + 0x19)) * (u32)(0x28))) + 0xa0);
    v1 = 0xa;
    if ((s32)((s32)rand() % (s32)(0xa)) <= (s32)4) {
        a0 = (void *)(s32)0x1e;
        v1 = 0x42c80000;
        f0 = 100.0f;
        f3 = ((float)((float)(s32)(u32)((s32)rand() % (s32)(0x1e))) / 100.0f);
    } else {
        a0 = (void *)(s32)0x1e;
        v1 = 0x42c80000;
        f0 = 100.0f;
        f3 = (-((float)((float)(s32)(u32)((s32)rand() % (s32)(0x1e))) / 100.0f));
    }
    v0 = s0->fire;
    if (v0 != 0) {
        v0 = 0x40400000;
        f1 = 3.0f;
        f1 = ((3.0f * (float)(u32)s0->power) * s1->PowerScl);
    } else {
        f1 = ((float)(float)(u32)s0->power * s1->PowerScl);
    }
    f0 = 1.0f;
    return ((s32)(f1 * (1.0f + f3)));
}
static signed int GetE022DamageAnim(void *a0 /* r4 */) {
    u8 *s5;
    u32 t0;
    u8 *a3;
    float f3;
    u32 a2;
    float f1;
    float f0;
    u32 a1;
    u8 *s4;
    float f20;
    u8 *s3;
    s32 s2;
    u32 s1;
    u32 v1;
    s32 hi;
    u8 *s0;
    u32 v0;
    void *a0_2;

    s5 = (u8 *)a0;
    s4 = (u8 *)(*(u32 *)((u8 *)a0 + 0x14) + *(u8 *)((u8 *)a0 + 0x19) * 40 + 0xa0);
    a2 = *(u32 *)((u8 *)a0 + 0x10);
    f0 = Math_VectorToAngle((*(float *)(a2 + 0x20) - *(float *)a0), (*(float *)(a2 + 0x28) -
        *(float *)((u8 *)a0 + 8)));
    v1 = *(s32 *)(s5 + 0x10);
    f3 = (f0 - *(float *)((v1 + 0x34)));
    if (3.1415927f + f3 >= 0.0f) {
        f20 = f3 - 6.2831855f * (float)(s32)((3.1415927f + f3) / 6.2831855f);
    } else {
        f20 = 6.2831855f + (f3 - 6.2831855f * (float)(s32)((3.1415927f + f3) / 6.2831855f));
    }
    s3 = (u8 *)*(s32 *)((v1 + 0x148));
    v0 = *(u8 *)(s3 + 0x1f0);
    if (v0 == 0 && *(u8 *)(s4 + 0x17) != 0) {
        a0_2 = (void *)*(s32 *)((v1 + 0x120));
        v1 = *(s32 *)(s3 + 0x254);
        v0 = 1;
        if ((s32)a0_2 < (s32)((s32)v1 / 3)) {
            *(u8 *)(s3 + 0x1f0) = v0;
            v0 = *(u8 *)(s3 + 0x1f1);
            s2 = 0;
            if (0 < (s32)v0) {
                s0 = (u8 *)s3;
                do {
                    SFX_Delete(*(s32 *)(s0 + 0x200), (s32)1);
                    *(u32 *)(s0 + 0x200) = -1;
                    s2 = s2 + 1;
                    s0 = (u8 *)(s0 + 4);
                } while (s2 < (s32)*(u8 *)(s3 + 0x1f1));
            }
            *(u8 *)(s3 + 0x1f1) = 0;
        }
    }
    a1 = *(s32 *)(s5 + 0x10);
    a0_2 = (void *)*(s32 *)((a1 + 0x120));
    if ((s32)a0_2 <= 0 && (u32)*(s32 *)((a1 + 0x158)) == (u32)2 && (u32)*(s16 *)((a1 + 0x104)) ==
        (u32)0x5a) {
        return 0x61;
    } else {
        v0 = *(u8 *)(s4 + 0x17);
        if (v0 != 0) {
            v0 = *(s32 *)((a1 + 0xc));
            s0 = (u8 *)*(s32 *)((v0 + 0x10));
            v0 = rand();
            v1 = *(s16 *)(s0 + 0x10);
            a3 = (u8 *)*(s32 *)(s5 + 0x10);
            a1 = (s32)v0 % (s32)v1;
            v0 = *(s32 *)(a3 + 0x120);
            if ((s32)v0 > 0) {
                u16 effect;
                u16 limit;
                v0 = *(u8 *)(s3 + 0x1f0);
                effect = 0x1e1;
                if (v0 != 0) {
                    s1 = 0x5f;
                    limit = 4;
                } else {
                    effect = 0x1e0;
                    s1 = 0x5e;
                    limit = 4;
                }
                v1 = *(u8 *)(s3 + 0x1f1);
                t0 = a1;
                if ((s32)v1 < (s32)limit) {
                    a2 = (u32)V0;
                    a1 = (u32)VW;
                    v0 = SFX_Create_OnAng_Attach(effect, (float *)a1, (float *)a2,
                        (void *)a3, (u16)t0, 0, 0);
                    v1 = *(u8 *)(s3 + 0x1f1);
                    *(u8 *)(s3 + 0x1f1) = v1 + 1;
                    *(u32 *)(((u32)(s32)((u8 *)(u32)(v1 << 2) + (u32)(s3)) + 0x200)) = v0;
                }
            } else {
                s1 = 0x60;
            }
        } else {
            v0 = *(u8 *)(s4 + 7);
            if (v0 != 0) {
                if ((float)DCOMP_EXPR_CFEF94067507FB7D(f20) < 1.5704999f) {
                    s1 = 0x1e;
                } else {
                    s1 = 0x20;
                }
            } else if ((s32)a0_2 > 0) {
                if ((float)DCOMP_EXPR_405892EAFA68827F(f20) < 0.78524995f) {
                    s1 = 0x16;
                } else if (!((float)DCOMP_EXPR_405892EAFA68827F(f20) <= 2.3557498f)) {
                    s1 = 0x17;
                } else if (f20 < 0.0f) {
                    s1 = 0x15;
                } else if (!(f20 <= 0.0f)) {
                    s1 = 0x14;
                }
            } else if ((float)DCOMP_EXPR_CFEF94067507FB7D(f20) < 1.5704999f) {
                s1 = 0x28;
            } else {
                s1 = 0x29;
            }
        }
        v0 = CheckAnimParam((void *)*(s32 *)(s5 + 0x10), (u16)s1);
        if (v0 != 0) {
            return s1;
        } else {
            v0 = *(s32 *)((*(s32 *)(s5 + 0x10) + 0x120));
            if ((s32)v0 > 0) {
                return 0x16;
            } else {
                return 0x28;
            }
        }
    }
    return v0;
}
u32 E022JumpDst[0x8] = {
    0xc2f73333, 0xc115a1cb, 0x40266666, 0x3f800000, 0xc2ef0000, 0xc1000000, 0x3fe66666,
    0x3f800000
};
