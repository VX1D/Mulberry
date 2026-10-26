#include "common.h"

/* NM_GetPcHeadPos @ 0x1BC6D0 .. 0x1BC724 (0x54 bytes, frame 0x20) */

extern void * GetDummyPolyData(void *, unsigned char, unsigned char);
extern void sceVu0ApplyMatrix();
extern u8 MdlMng[];

/* SfxCalc_VecHermite @ 0x1BC730 .. 0x1BC900 (0x1d0 bytes, frame 0xb0) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1bc76c is a float copy
 *   stack: address of the slot at 0xa0 escapes at 0x1bc778
 *   stack: address of the slot at 0xa0 escapes at 0x1bc790
 *   stack: address of the slot at 0xa0 escapes at 0x1bc7a0
 *   stack: address of the slot at 0xa0 escapes at 0x1bc7a0
 *   stack: address of the slot at 0xa0 escapes at 0x1bc7b0
 *   stack: address of the slot at 0xa0 escapes at 0x1bc7b0
 *   fpu: float literal 0x3f000000 at 0x1bc7c0
 *   stack: address of the slot at 0xa0 escapes at 0x1bc7c4
 *   stack: address of the slot at 0xa0 escapes at 0x1bc7c4
 *   stack: address of the slot at 0x90 escapes at 0x1bc7d4
 *   stack: address of the slot at 0x90 escapes at 0x1bc7e8
 *   stack: address of the slot at 0x90 escapes at 0x1bc7e8
 *   stack: address of the slot at 0x90 escapes at 0x1bc7f8
 *   stack: address of the slot at 0x90 escapes at 0x1bc7f8
 *   fpu: float literal 0x3f000000 at 0x1bc808
 *   stack: address of the slot at 0x90 escapes at 0x1bc80c
 *   stack: address of the slot at 0x90 escapes at 0x1bc80c
 *   fpu: float literal 0x40400000 at 0x1bc824
 *   fpu: float literal 0x40000000 at 0x1bc830
 *   fpu: float literal 0x3f800000 at 0x1bc844
 *   fpu: float literal 0x40000000 at 0x1bc858
 *   stack: address of the slot at 0x80 escapes at 0x1bc868
 *   stack: address of the slot at 0xa0 escapes at 0x1bc868
 *   stack: address of the slot at 0x80 escapes at 0x1bc878
 *   stack: address of the slot at 0x70 escapes at 0x1bc888
 *   stack: address of the slot at 0x90 escapes at 0x1bc888
 *   stack: address of the slot at 0x70 escapes at 0x1bc898
 *   fpu: float literal 0xc0000000 at 0x1bc8a8
 *   stack: address of the slot at 0x60 escapes at 0x1bc8b4
 *   stack: address of the slot at 0x60 escapes at 0x1bc8c4
 *   return without a value in a non-void function
 */

extern void sceVu0SubVector(void *, void *, void *);
extern void sceVu0CopyVector(void *, void *);
extern void sceVu0AddVector(void *, void *, void *);
extern void sceVu0ScaleVector(void *, void *, float);
extern u32 V0[];

/* SfxCalc_VecTransformByQtn @ 0x1BC900 .. 0x1BC944 (0x44 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x30 escapes at 0x1bc918
 *   stack: address of the slot at 0x30 escapes at 0x1bc928
 */

void SfxCalc_MakeMatrixFromQtn(float (*mrx_)[4], float *qtn_);


/* SfxCalc_MakeMatrix_SPYRT @ 0x1BC9F0 .. 0x1BCCB8 (0x2c8 bytes, frame 0xe0) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0xa0 escapes at 0x1bca20
 *   fpu: float literal 0x00000000 at 0x1bca2c
 *   fpu: float literal 0x40490fdb at 0x1bca64
 *   fpu: float literal 0x40c90fdb at 0x1bca84
 *   fpu: mtc1 reinterprets v0 at 0x1bcaa8
 *   stack: address of the slot at 0x60 escapes at 0x1bcad0
 *   stack: address of the slot at 0x60 escapes at 0x1bcae8
 *   fpu: float literal 0x00000000 at 0x1bcaf0
 *   fpu: float literal 0x40490fdb at 0x1bcb08
 *   fpu: float literal 0x40c90fdb at 0x1bcb28
 *   fpu: float literal 0x40c90fdb at 0x1bcb50
 *   stack: address of the slot at 0x60 escapes at 0x1bcb74
 *   stack: address of the slot at 0x60 escapes at 0x1bcb74
 *   fpu: float literal 0x00000000 at 0x1bcb80
 *   fpu: float literal 0x40490fdb at 0x1bcb98
 *   fpu: float literal 0x40c90fdb at 0x1bcbb8
 *   fpu: float literal 0x40c90fdb at 0x1bcbe0
 *   stack: address of the slot at 0x60 escapes at 0x1bcc04
 *   stack: address of the slot at 0x60 escapes at 0x1bcc04
 *   stack: address of the slot at 0x90 escapes at 0x1bcc14
 */

extern void sceVu0UnitMatrix(void *);
extern void sceVu0RotMatrixX(void *, void *, float);
extern void sceVu0CopyMatrix(void *, void *);
extern void sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0RotMatrixZ(void *, void *, float);
extern u32 MRX1[];
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif


static u32 B;
static u32 A;
/* SfxUtil_CalcRndPos @ 0x1BCCC0 .. 0x1BD148 (0x488 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f000000 at 0x1bcd0c
 *   fpu: mtc1 reinterprets v0 at 0x1bcd5c
 *   fpu: mtc1 reinterprets v1 at 0x1bcd74
 *   fpu: float literal 0x40c90fdb at 0x1bcd9c
 *   fpu: float literal 0x37800080 at 0x1bcda4
 *   fpu: mtc1 reinterprets v0 at 0x1bcde8
 *   fpu: mtc1 reinterprets v1 at 0x1bce00
 *   fpu: float literal 0x37800080 at 0x1bce20
 *   fpu: float literal 0x40c90fdb at 0x1bce24
 *   fpu: mov.s at 0x1bce38 is a float copy
 *   fpu: mov.s at 0x1bce44 is a float copy
 *   fpu: mov.s at 0x1bce4c is a float copy
 *   fpu: mov.s at 0x1bce5c is a float copy
 *   fpu: mov.s at 0x1bce70 is a float copy
 *   fpu: mtc1 reinterprets v0 at 0x1bcef4
 *   fpu: mtc1 reinterprets v1 at 0x1bcf08
 *   fpu: float literal 0x37800080 at 0x1bcf28
 *   fpu: mtc1 reinterprets v1 at 0x1bcf90
 *   fpu: mtc1 reinterprets a0 at 0x1bcfa4
 *   fpu: float literal 0x37800080 at 0x1bcfc0
 *   fpu: float literal 0x3f000000 at 0x1bcfcc
 *   fpu: mtc1 reinterprets v1 at 0x1bd030
 *   fpu: mtc1 reinterprets a0 at 0x1bd044
 *   fpu: float literal 0x37800080 at 0x1bd060
 *   fpu: float literal 0x3f000000 at 0x1bd06c
 *   fpu: mtc1 reinterprets v1 at 0x1bd0d0
 *   fpu: mtc1 reinterprets a0 at 0x1bd0e4
 *   fpu: float literal 0x37800080 at 0x1bd0fc
 *   fpu: float literal 0x3f000000 at 0x1bd10c
 *   declaration vs inferred signature: return void vs inferred u32
 */






static inline u32 RndInl(void) {
    u32 a = A;
    u32 b = B;
    A = b + a * 0x85;
    B = A * 5 + b * 7;
    return A ^ B;
}

extern float acosf(float);


extern float sqrtf(float);


extern void sceVu0Normalize(void *, void *);
extern float asinf(float);
extern float fabsf(float);


/* SfxUtil_HitCheck_Line_Map @ 0x1BDDA0 .. 0x1BDE68 (0xc8 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x1bdddc
 *   fpu: mov.s at 0x1bde00 is a float copy
 *   stack: address of the slot at 0x60 escapes at 0x1bddfc
 *   stack: address of the slot at 0x60 escapes at 0x1bde0c
 *   stack: address of the slot at 0x70 escapes at 0x1bde20
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern float CheckHitMapLineGetNormal(void *, void *, void *);

extern signed int CheckEneDamage();
extern float Math_GetDist();
extern float CheckHitMapLine();





typedef enum { SFX_FALSE, SFX_TRUE } SFX_BOOL;

struct SfxChar {
    u8 bUse;
    u8 _p0[0x1f];
    float pos[4];
    u8 _p1[0xe4];
    float high;
    u8 _p2[0x10];
    u8 team;
    u8 _p3[0x97];
};

static inline float SfxUtil_GetCharCenter(float *dst, struct SfxChar *pChar) {
    float ofs[4] = {0};
    float fallback[4];
    ofs[1] = 0.5f * pChar->high;
    if (dst) {
        sceVu0SubVector(dst, pChar->pos, ofs);
        return dst[1];
    } else {
        sceVu0SubVector(fallback, pChar->pos, ofs);
        return fallback[1];
    }
}

/* SfxUtil_FindChar_Fan @ 0x1BDEF0 */
extern signed int CheckEneLockOn(void *);
extern float sceVu0InnerProduct(void *, void *);


/* SfxUtil_FindChar_Corn @ 0x1BE3C0 */
extern float sceVu0InnerProduct(void *, void *);


/* SfxCalc_MakeMatrixFromPYR @ 0x1BE620 .. 0x1BE818 (0x1f8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1be628
 *   fpu: mov.s at 0x1be640 is a float copy
 *   fpu: mov.s at 0x1be648 is a float copy
 *   fpu: float literal 0x40490fdb at 0x1be654
 *   fpu: float literal 0x40c90fdb at 0x1be674
 *   fpu: mtc1 reinterprets v0 at 0x1be698
 *   fpu: float literal 0x00000000 at 0x1be6e0
 *   fpu: float literal 0x40490fdb at 0x1be6fc
 *   fpu: float literal 0x40c90fdb at 0x1be71c
 *   fpu: mtc1 reinterprets v0 at 0x1be740
 *   fpu: float literal 0x00000000 at 0x1be770
 *   fpu: float literal 0x40490fdb at 0x1be78c
 *   fpu: float literal 0x40c90fdb at 0x1be7ac
 *   fpu: mtc1 reinterprets v0 at 0x1be7d0
 */

extern void sceVu0RotMatrixX(void *, void *, float);
extern void sceVu0CopyMatrix(void *, void *);
extern void sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0RotMatrixZ(void *, void *, float);
extern u32 MRX1[];

/* SfxCalc_RotateVector @ 0x1BE860 .. 0x1BEA44 (0x1e4 bytes, frame 0xf0) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490fdb at 0x1be870
 *   fpu: float literal 0x00000000 at 0x1be884
 *   fpu: mov.s at 0x1be890 is a float copy
 *   fpu: mov.s at 0x1be898 is a float copy
 *   fpu: float literal 0x40c90fdb at 0x1be8a4
 *   fpu: float literal 0x40c90fdb at 0x1be8cc
 *   stack: address of the slot at 0xb0 escapes at 0x1be8f4
 *   fpu: float literal 0x40490fdb at 0x1be904
 *   fpu: float literal 0x00000000 at 0x1be908
 *   fpu: float literal 0x40c90fdb at 0x1be928
 *   fpu: mtc1 reinterprets v0 at 0x1be94c
 *   stack: address of the slot at 0x70 escapes at 0x1be974
 *   fpu: float literal 0x40490fdb at 0x1be984
 *   fpu: float literal 0x00000000 at 0x1be988
 *   fpu: float literal 0x40c90fdb at 0x1be9a8
 *   fpu: mtc1 reinterprets v0 at 0x1be9cc
 *   stack: address of the slot at 0x30 escapes at 0x1be9f4
 *   stack: address of the slot at 0xb0 escapes at 0x1bea04
 *   stack: address of the slot at 0x70 escapes at 0x1bea14
 *   stack: address of the slot at 0x30 escapes at 0x1bea24
 */

extern void sceVu0RotMatrixX(void *, void *, float);
extern void sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0RotMatrixZ(void *, void *, float);
extern u32 MRX1[];

/* SfxCalc_CheckInsightCamera @ 0x1BEA50 .. 0x1BEB14 (0xc4 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x20 escapes at 0x1bea64
 *   fpu: float literal 0xbf800000 at 0x1bea88
 *   stack: address of the slot at 0x30 escapes at 0x1bea9c
 *   stack: address of the slot at 0x20 escapes at 0x1beaa8
 *   stack: address of the slot at 0x20 escapes at 0x1beaa8
 *   stack: address of the slot at 0x10 escapes at 0x1beab4
 *   stack: address of the slot at 0x50 escapes at 0x1beab4
 *   fpu: float literal 0x3f800000 at 0x1bead0
 *   fpu: float literal 0x3fc90fdb at 0x1beae4
 *   fpu: float literal 0x3f000000 at 0x1beaec
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void sceVu0InversMatrix(void *, void *);
extern float sceVu0InnerProduct(void *, void *);
extern u8 *lpDrawMng;


/* SfxDbg_SetDebugMsg @ 0x1BEB20 .. 0x1BEBCC (0xac bytes, frame 0x50) */
/*
 * dcomp notes:
 *   literal: @2450 is the string '[SfxMsg No.%d] %s  [File] %s : %d\n'
 */

extern void * strcpy(void *, void *);
extern int printf(void *, ...);
extern u32 s_dbgmsg[];

/* SfxCalc_PYRfromRotMatrix @ 0x1BEBD0 .. 0x1BED54 (0x184 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x60 escapes at 0x1bec04
 *   stack: address of the slot at 0x70 escapes at 0x1bec10
 *   stack: address of the slot at 0x80 escapes at 0x1bec1c
 *   fpu: mov.s at 0x1bec34 is a float copy
 *   fpu: float literal 0x00000000 at 0x1bec38
 *   fpu: mov.s at 0x1bec58 is a float copy
 *   fpu: mov.s at 0x1bec60 is a float copy
 *   fpu: float literal 0x00000000 at 0x1bec84
 *   fpu: float literal 0x40490fdb at 0x1bec9c
 *   fpu: float literal 0x3fc90fdb at 0x1becb0
 *   fpu: mov.s at 0x1becb8 is a float copy
 *   fpu: mov.s at 0x1becdc is a float copy
 *   fpu: float literal 0x40490fdb at 0x1becf0
 *   declaration vs inferred signature: return void vs inferred float
 */

extern void sceVu0Normalize(void *, void *);
extern float asinf(float);

/* SfxCalc_MakeMatrixFromDir @ 0x1BED60 .. 0x1BEEB4 (0x154 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1bed68
 *   stack: address of the slot at 0x30 escapes at 0x1bedd8
 *   stack: address of the slot at 0x30 escapes at 0x1bedd8
 *   fpu: float literal 0x3f7ff972 at 0x1bedf0
 *   stack: address of the slot at 0x50 escapes at 0x1bee08
 *   stack: address of the slot at 0x34 escapes at 0x1bee18
 *   stack: address of the slot at 0x30 escapes at 0x1bee40
 *   stack: address of the slot at 0x50 escapes at 0x1bee40
 *   stack: address of the slot at 0x50 escapes at 0x1bee44
 *   stack: address of the slot at 0x50 escapes at 0x1bee44
 *   stack: address of the slot at 0x50 escapes at 0x1bee6c
 *   stack: address of the slot at 0x40 escapes at 0x1bee78
 *   stack: address of the slot at 0x30 escapes at 0x1bee84
 *   cfg: kept branch: 0x1bed84 if (..) goto .L001BEDB8
 *   cfg: kept branch: 0x1bed94 if (..) goto .L001BEDB8
 */

extern u32 VX[];
extern u32 VY[];
extern u32 VW[];
#ifndef DCOMP_COP2_5499821473
#define DCOMP_COP2_5499821473
static inline void dcomp_cop2_5499821473(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf16,0(%1)\nlqc2 vf17,0(%2)\nvopmula.xyz ACC,vf16,vf17\nvopmsub.xyz vf16,vf17,vf16\nsqc2 vf16,0(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif


/* SfxCalc_MakeRotTransMatrix_I @ 0x1BEEC0 .. 0x1BEED0 (0x10 bytes) */
/*
 * dcomp notes:
 *   tail: j SfxCalc_MakeMatrix_SPYRT at 0x1beec8 leaves the function
 *   a0 forwarded to SfxCalc_MakeMatrix_SPYRT
 *   a2 takes slot 2 only because of the ABI order
 *   return value dropped, call kept: the function is void
 */

extern void SfxCalc_MakeMatrix_SPYRT();

/* SfxCalc_Ang2Vec @ 0x1BEED0 .. 0x1BF004 (0x134 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490fdb at 0x1beee0
 *   fpu: float literal 0x00000000 at 0x1beef4
 *   fpu: mov.s at 0x1bef04 is a float copy
 *   fpu: float literal 0x40c90fdb at 0x1bef10
 *   fpu: float literal 0x40c90fdb at 0x1bef38
 *   stack: address of the slot at 0x30 escapes at 0x1bef60
 *   fpu: float literal 0x40490fdb at 0x1bef70
 *   fpu: float literal 0x00000000 at 0x1bef74
 *   fpu: float literal 0x40c90fdb at 0x1bef94
 *   fpu: mtc1 reinterprets v0 at 0x1befb8
 *   stack: address of the slot at 0x30 escapes at 0x1befdc
 *   stack: address of the slot at 0x30 escapes at 0x1befdc
 *   stack: address of the slot at 0x50 escapes at 0x1befe8
 */

extern void sceVu0RotMatrixX(void *, void *, float);
extern void sceVu0RotMatrixY(void *, void *, float);
extern u32 MRX1[];

/* SfxCalc_Sin @ 0x1BF170 .. 0x1BF1DC (0x6c bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40c90fd0 at 0x1bf178
 *   fpu: float literal 0x00000000 at 0x1bf17c
 *   fpu: float literal 0x42c80000 at 0x1bf1ac
 *   return: lwc1 at 0x1bf1d8 computes the return value
 */

extern u32 s_table_sin[];

/* SfxCalc_Cos @ 0x1BF1E0 .. 0x1BF24C (0x6c bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40c90fd0 at 0x1bf1e8
 *   fpu: float literal 0x00000000 at 0x1bf1ec
 *   fpu: float literal 0x42c80000 at 0x1bf21c
 *   return: lwc1 at 0x1bf248 computes the return value
 */

extern u32 s_table_cos[];

/* SfxCalc_RandU32 @ 0x1BF300 .. 0x1BF348 (0x48 bytes) */
/*
 * dcomp notes:
 *   return: xor at 0x1bf344 computes the return value
 */

extern u32 A;
extern u32 B;

/* SfxCalc_RandInit @ 0x1BF350 .. 0x1BF36C (0x1c bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u32 A;
extern u32 B;

/* SfxDbg_GetDebugFlag @ 0x1BF370 .. 0x1BF378 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: ld at 0x1bf374 computes the return value
 */

extern u64 s_dbg_flag;
static u32 s_dbgmsg[0x82];
static u32 s_table_cos[0x275];
static u32 s_table_sin[0x275];
static u32 A = 0x74915435;
static u32 B = 0xe8353554;
static u64 s_dbg_flag;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u64 SfxDbg_GetDebugFlag(void);
u32 SfxCalc_RandInit(void);
u32 SfxCalc_RandU32(void);
void SfxCalc_CosSinTableInit(void);
float SfxCalc_Cos(float f12 );
float SfxCalc_Sin(float f12 );
void SfxCalc_Angle2VectorZXY(float *a0 , float *a1 );
void SfxCalc_Vector2Angle(float *a0 , float *a1 );
void SfxCalc_Vec2Ang(float *a0 , float *a1 , float *a2 );
void SfxCalc_Ang2Vec(float *a0 , float f12 , float f13 );
void SfxCalc_MakeRotTransMatrix_I(u8 *a0 , s32 a1 , s32 a2 , float *a3 );
void SfxCalc_MakeMatrixFromDir(void *a0 , float *a1 );
void SfxCalc_PYRfromRotMatrix(void *a0 , float *a1 , float *a2 , float *a3 );
void SfxDbg_SetDebugMsg(unsigned char a0 , char *a1 , char *a2 , unsigned int a3 );
signed int SfxCalc_CheckInsightCamera(float *a0 );
void SfxCalc_RotateVector(float *a0 , float f12 , float f13 , float f14 );
float SfxCalc_IntoAngle_0_2PI(float f12 );
void SfxCalc_MakeMatrixFromPYR(void *a0 , float f12 , float f13 , float f14 );
void *SfxUtil_FindChar_Corn(signed int bEnemy, float *pos_, float *dir_, float range_, float theta_, signed int bEnableObstacle_);
void *SfxUtil_FindChar_Sphere(signed int bEnemy, float *pos_, float range_, signed int bEnableObstacle_);
void *SfxUtil_FindChar_Fan(signed int bEnemy, float *pos_, float *dir_, float range_, float theta_, signed int bEnableObstacle_);
void SfxCalc_PY_To_Dir(float f12 , float f13 , void *a0 );
signed int SfxUtil_HitCheck_Line_Map(float *a0 , float *a1 , void *a2 , void *a3 , unsigned int *t0 );
void SfxCalc_MakeRotTransMatrix_I_LEGACY(float (*mrx)[4], float *loc, float *ang, float *scl);
void SfxCalc_PYRfromRotMatrix_LEGACY(float (*mRot_)[4], float *pPitch_, float *pYaw_, float *pRoll_);
void SfxUtil_CalcCutAnimST(int divH_, int divV_, int curr_cut_, float (*pST_)[4]);
void SfxCalc_MakeMatrixFromQtn(float (*mrx_)[4], float *qtn_);
void SfxCalc_QtnMakeFromMatrix(float *output, void *input);
void SfxCalc_QtnMakeFromPYR(float *q, float pitch, float yaw, float roll);
void SfxCalc_QtnMakeFromDir(float *a0 , float *a1 );
void SfxCalc_QtnSLerp(float *out, float *left, float *right, float amount);
void SfxCalc_QtnMult(float *a0 , float *a1 , float *a2 );
void SfxUtil_CalcRndPos(float *a0 , signed int a1 , float *a2 );
void SfxCalc_MakeMatrix_SPYRT(void *a0 , float *a1 , float *a2 , float *a3 );
void SfxCalc_DirMakeFromQtn(float *out, float *q);
void SfxCalc_VecTransformByQtn(float *a0 , float *a1 , float *a2 );
u32 SfxCalc_VecHermite(float *a0 , float *a1 , float *a2 , float *a3 , float *t0 , float f12 );
void NM_GetPcHeadPos(float *a0 );


u64 SfxDbg_GetDebugFlag(void) {
    return s_dbg_flag;
}

u32 SfxCalc_RandInit(void) {
    u32 v1;

    v1 = 0x74910000;
    A = (u64)(0x74910000 | 0x5435);
    v1 = 0xe8353554;
    B = 0xe8353554;
    return;
}

u32 SfxCalc_RandU32(void) {
    u32 a0;
    u32 a1;
    u32 v0;

    a0 = A;
    a1 = B;
    A = a1 + (s32)((u32)(a0) * (u32)(0x85));
    a0 = A;
    B = (s32)((u32)(a0) * (u32)(5)) + (u32)((u32)(a1) * (u32)(7));
    v0 = B;
    return a0 ^ v0;
}

/* SfxCalc_CosSinTableInit @ 0x1BF250 .. 0x1BF2F8 (0xa8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets s1 at 0x1bf274
 *   fpu: float literal 0x3c23a990 at 0x1bf27c
 *   fpu: mtc1 reinterprets s0 at 0x1bf2b4
 *   fpu: float literal 0x3c23a990 at 0x1bf2bc
 */

void SfxCalc_CosSinTableInit(void) {
    s32 s1;
    float f1;
    float f0;

    s1 = 0;
    for (; s1 < 0x275; s1 = s1 + 1) {
        f1 = 0.00998915732f;
        f0 = cosf((0.00998915732f * (float)(float)s1));
        *(f32 *)((u32)&((struct { u8 b[4]; } *)(u8 *)s_table_cos)[s1]) = f0;
    }
    s1 = 0;
    for (; s1 < 0x275; s1 = s1 + 1) {
        f1 = 0.00998915732f;
        f0 = sinf((0.00998915732f * (float)(float)s1));
        *(f32 *)((u32)&((struct { u8 b[4]; } *)(u8 *)s_table_sin)[s1]) = f0;
    }
    return;
}

float SfxCalc_Cos(float f12 /* f12 */) {
    u32 v0;
    float f0;

    v0 = 0x40c90fd0;
    f0 = 0.0f;
    f12 = (f12 - (6.28318024f * (float)((float)(s32)(f12 / 6.28318024f))));
    if (f12 < 0.0f) {
        f12 = (f12 + 6.28318024f);
    }
    f0 = 100.0f;
    v0 = (u32)s_table_cos;
    return *(float *)(u32)(s32)((u8 *)s_table_cos + (s32)((u32)((s32)(100.0f * f12)) << 2));
}

float SfxCalc_Sin(float f12 /* f12 */) {
    u32 v0;
    float f0;

    v0 = 0x40c90fd0;
    f0 = 0.0f;
    f12 = (f12 - (6.28318024f * (float)((float)(s32)(f12 / 6.28318024f))));
    if (f12 < 0.0f) {
        f12 = (f12 + 6.28318024f);
    }
    f0 = 100.0f;
    v0 = (u32)s_table_sin;
    return *(float *)(u32)(s32)((u8 *)s_table_sin + (s32)((u32)((s32)(100.0f * f12)) << 2));
}


/* SfxCalc_Angle2VectorZXY @ 0x1BF0F0 .. 0x1BF164 (0x74 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1bf11c is a float copy
 *   declaration vs inferred signature: return void vs inferred float
 */

void SfxCalc_Angle2VectorZXY(float *a0 /* r4 */, float *a1 /* r5 */) {
    float *s0;
    float f12;
    float f0;
    float f20;

    f12 = *(float *)a1;
    s0 = a1;
    f0 = cosf(f12);
    f12 = s0[1];
    f20 = f0;
    f0 = sinf(f12);
    *(f32 *)a0 = (f20 * f0);
    f12 = *(float *)s0;
    f0 = (-sinf(f12));
    a0[1] = f0;
    f12 = s0[1];
    f0 = cosf(f12);
    a0[2] = (f20 * f0);
    *(u32 *)(((u8 *)a0 + 0xc)) = 0;
    return;
}

/* SfxCalc_Vector2Angle @ 0x1BF080 .. 0x1BF0F0 (0x70 bytes, frame 0x30) */

void SfxCalc_Vector2Angle(float *a0 /* r4 */, float *a1 /* r5 */) {
    float f13;
    float f12;
    float f2;
    float f1;
    float fp_acc_load_0; // f1
    float f0;

    fp_acc_load_0 = *(float *)a1;
    f2 = a1[2];
    f0 = a1[1];
    f1 = ((float)(fp_acc_load_0 * fp_acc_load_0) + (f2 * f2));
    f13 = ({ float native_result_0; __asm__("sqrt.s %0,%1" : "=f"(native_result_0) : "f"(f1));
        native_result_0; });
    f0 = atan2f((-f0), f13);
    *(f32 *)(u8 *)a0 = f0;
    f13 = a1[2];
    f12 = *(float *)a1;
    f0 = atan2f(f12, f13);
    *(f32 *)(((u8 *)a0 + 4)) = f0;
    *(u32 *)(((u8 *)a0 + 8)) = 0;
    *(u32 *)(((u8 *)a0 + 0xc)) = 0;
    return;
}

/* SfxCalc_Vec2Ang @ 0x1BF010 .. 0x1BF078 (0x68 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred float
 */



void SfxCalc_Vec2Ang(float *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */) {
    float *s2;
    float *s0;
    float *s1;
    float f13;
    float f12;
    float f0;

    s2 = a0;
    s0 = a2;
    s1 = a1;
    if ((u32)s0 != 0) {
        f13 = *(float *)(((u8 *)s2 + 8));
        f12 = *(float *)s2;
        f0 = atan2f(f12, f13);
        *(f32 *)s0 = f0;
    }
    if ((u32)s1 != 0) {
        f12 = *(float *)(((u8 *)s2 + 4));
        f0 = asinf(f12);
        f0 = (-f0);
        *(f32 *)s1 = f0;
    }
    return;
}

void SfxCalc_Ang2Vec(float *a0 /* r4 */, float f12 /* f12 */, float f13 /* f13 */) {
    u32 s0;
    u8 *a1;
    float f2;
    float f1;
    float f20;
    float f0;
    u32 v0;
    u8 stackFrame_50[32] __attribute__((aligned(16)));
    u8 stackFrame_30[32] __attribute__((aligned(16)));

    v0 = 0x40490fdb;
    f1 = 3.14159274f;
    s0 = (u32)a0;
    f2 = (3.14159274f + f12);
    f0 = 0.0f;
    f20 = f13;
    if (f2 >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f12 = (f12 - (6.28318548f * (float)((float)(s32)(f2 / 6.28318548f))));
    } else {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f12 = (6.28318548f + (f12 - (6.28318548f * (float)((float)(s32)(f2 / 6.28318548f)))));
    }
    a1 = (u8 *)MRX1;
    sceVu0RotMatrixX((void *)((u8 *)&stackFrame_30[0]), (void *)MRX1, f12);
    f1 = 3.14159274f;
    f0 = 0.0f;
    f2 = (3.14159274f + f20);
    if (f2 >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f12 = (f20 - (6.28318548f * (float)((float)(s32)(f2 / 6.28318548f))));
    } else {
        f1 = 6.28318548f;
        f12 = (f1 + (f20 - (f1 * (float)((float)(s32)(f2 / f1)))));
    }
    sceVu0RotMatrixY((void *)((u8 *)&stackFrame_30[0]), (void *)(u8 *)((u8 *)&stackFrame_30[0]),
        f12);
    sceVu0CopyVector((void *)s0, (void *)(u8 *)((u8 *)&stackFrame_50[0]));
    return;
}

void SfxCalc_MakeRotTransMatrix_I(u8 *a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */, float *a3 /*
        r7 */) {
    SfxCalc_MakeMatrix_SPYRT((void *)a0, (float *)a3, (float *)a2, (float *)a1);
    return;
}


void SfxCalc_MakeMatrixFromDir(void *a0 /* r4 */, float *a1 /* r5 */) {
    u32 s0;
    float f2;
    float f1;
    float f0;
    float *s1;
    void *a0_2; // a0
    u8 *v1;
    u32 v0;
    float *a1_2;
    u8 stackFrame_50[16] __attribute__((aligned(16)));
    u8 stackFrame_40[16] __attribute__((aligned(16)));
    u8 stackFrame_30[16] __attribute__((aligned(16)));

    f1 = 0.0f;
    f2 = *(float *)a1;
    s0 = (u32)a0;
    if (0.0f == f2) {
        f0 = a1[1];
        if (!(f1 == f0)) {
            goto _L001BEDB8;
        }
        f0 = a1[2];
        if (!(f1 == f0)) {
            goto _L001BEDB8;
        }
        a1_2 = (float *)MRX1;
        sceVu0CopyMatrix(a0, (void *)MRX1);
    } else {
        _L001BEDB8:;
        s1 = (float *)((u8 *)&stackFrame_30[0] + 0x4);
        *(f32 *)((u8 *)&stackFrame_30[0]) = f2;
        *(f32 *)s1 = a1[1];
        ((f32 *)stackFrame_30)[2] = a1[2];
        ((u32 *)stackFrame_30)[3] = 0;
        sceVu0Normalize((void *)((u8 *)&stackFrame_30[0]), (void *)((u8 *)&stackFrame_30[0]));
        f0 = fabsf(((float *)stackFrame_30)[1]);
        f1 = 0.999899983f;
        if (0.999899983f < f0) {
            a1_2 = (float *)VX;
            sceVu0CopyVector((void *)((u8 *)&stackFrame_50[0]), (void *)VX);
        } else {
            v1 = (u8 *)VY;
            v0 = (u32)((u8 *)&stackFrame_30[0]);
            a0_2 = (void *)((u8 *)&stackFrame_50[0]);
            dcomp_cop2_5499821473((void *)((u8 *)((u8 *)&stackFrame_50[0])), (void *)((u8 *)v1),
                (void *)(&stackFrame_30[0]));
        }
        sceVu0Normalize((void *)((u8 *)&stackFrame_50[0]), (void *)((u8 *)&stackFrame_50[0]));
        v0 = (u32)((u8 *)&stackFrame_30[0]);
        v1 = ((u8 *)&stackFrame_40[0]);
        dcomp_cop2_5499821473((void *)(&stackFrame_40[0]), (void *)(&stackFrame_30[0]), (void
            *)((u8 *)((u8 *)&stackFrame_50[0])));
        sceVu0CopyVector((void *)s0, (void *)((u8 *)&stackFrame_50[0]));
        a0_2 = (void *)(s32)(s0 + 0x10);
        sceVu0CopyVector(a0_2, (void *)((u8 *)&stackFrame_40[0]));
        a0_2 = (void *)(s32)(s0 + 0x20);
        sceVu0CopyVector(a0_2, (void *)((u8 *)&stackFrame_30[0]));
        a0_2 = (void *)(s32)(s0 + 0x30);
        a1_2 = (float *)VW;
        sceVu0CopyVector(a0_2, (void *)VW);
    }
    return;
}

void SfxCalc_PYRfromRotMatrix(void *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */, float *a3
        /* r7 */) {
    u32 s3;
    float *s2;
    float *s1;
    float *s0;
    float f12;
    float f0;
    float f21;
    float f20;
    float f13;
    float f1;
    float f2;
    u8 stackFrame[48] __attribute__((aligned(16)));

    s3 = (u32)a0;
    s2 = a1;
    s1 = a2;
    s0 = a3;
    sceVu0Normalize((void *)(u32)((u8 *)&stackFrame[0]), (void *)s3);
    sceVu0Normalize((void *)(u32)((u8 *)&stackFrame[16]), (void *)(u32)(s3 + 0x10));
    sceVu0Normalize((void *)(u32)((u8 *)&stackFrame[32]), (void *)(u32)(s3 + 0x20));
    f12 = *(float *)((u8 *)&stackFrame[8]);
    f0 = asinf(f12);
    f21 = (-f0);
    f0 = cosf((float)(float)f21);
    f20 = 0.0f;
    if (!(s32)(0.0f == f0)) {
        f13 = *(float *)((u8 *)&stackFrame[0]);
        f12 = *(float *)((u8 *)&stackFrame[4]);
        f0 = atan2f(f12, f13);
        f20 = (float)f0;
        f0 = cosf((float)(float)f21);
        f1 = *(float *)((u8 *)&stackFrame[24]);
        f12 = (f1 / f0);
        f0 = asinf(f12);
        f2 = *(float *)((u8 *)&stackFrame[40]);
        f1 = 0.0f;
        if ((s32)(f2 < 0.0f)) {
            f1 = 3.14159274f;
            f0 = (3.14159274f - f0);
        }
    } else {
        f21 = 1.57079637f;
        f0 = cosf((float)(float)1.57079637f);
        f1 = *(float *)((u8 *)&stackFrame[24]);
        f12 = (f1 / f0);
        f0 = asinf(f12);
        f2 = *(float *)((u8 *)&stackFrame[40]);
        if ((s32)(f2 < (float)(float)f20)) {
            f1 = 3.14159274f;
            f0 = (3.14159274f - f0);
        }
    }
    if ((u32)s1 != 0) {
        *(f32 *)s1 = f21;
    }
    if ((u32)s2 != 0) {
        *(f32 *)s2 = f0;
    }
    if ((u32)s0 != 0) {
        *(f32 *)s0 = f20;
    }
    return;
}

void SfxDbg_SetDebugMsg(unsigned char a0 /* r4 */, char *a1 /* r5 */, char *a2 /* r6 */, unsigned
        int a3 /* r7 */) {
    u32 s3;
    u32 s2;
    s32 s1;
    u32 v1;
    u32 a0_guard_word;
    char *a1_2;

    s3 = (u32)a1;
    s2 = (u32)a2;
    s1 = a3;
    if (0 <= (s32)a0) {
        strcpy((void *)(u8 *)(s_dbgmsg + 1), (void *)a1);
        strcpy((void *)(u8 *)(s_dbgmsg + 0x41), (void *)s2);
        s_dbgmsg[0x81] = s1;
        v1 = *(s32 *)s_dbgmsg;
        *(u32 *)s_dbgmsg = v1 + 1;
    }
    if ((u32)((s32)a0 < (s32)5) == 0) {
        a1_2 = (char *)*(s32 *)s_dbgmsg;
        a0_guard_word = (u32)"[SfxMsg No.%d] %s  [File] %s : %d\012";
        printf((void *)"[SfxMsg No.%d] %s  [File] %s : %d\012", a1_2, s3, s2, s1);
    }
    return;
}

signed int SfxCalc_CheckInsightCamera(float *a0 /* r4 */) {
    u32 v1;
    u32 v0;
    float f0;
    float f2, f3, f1;
    u8 *a0_2;
    u8 stackFrame_30[64] __attribute__((aligned(16)));
    u8 stackFrame_20[16] __attribute__((aligned(16)));
    u8 stackFrame_10[16] __attribute__((aligned(16)));

    v0 = ((u32)lpDrawMng);
    sceVu0SubVector((void *)((u8 *)&stackFrame_20[0]), (void *)a0, (void *)(u32)(v0 + 0x230));
    v1 = ((u32)lpDrawMng);
    v0 = *(u8 *)((v1 + 0x42c));
    if ((u32)(v0 & 1) != 0) {
        ((f32 *)stackFrame_20)[1] = (((float *)stackFrame_20)[1] * -1.0f);
    }
    sceVu0InversMatrix((void *)(u32)((u8 *)&stackFrame_30[0]), (void *)(u32)(v1 + 0x2f0));
    sceVu0Normalize((void *)((u8 *)&stackFrame_20[0]), (void *)((u8 *)&stackFrame_20[0]));
    sceVu0Normalize((void *)((u8 *)&stackFrame_10[0]), (void *)((u8 *)&stackFrame_30[0] + 0x20));
    f0 = sceVu0InnerProduct((void *)((u8 *)&stackFrame_20[0]), (void *)((u8 *)&stackFrame_10[0]));
    __asm__ volatile(
        ".set noreorder\n"
        "lui $2,0x3f80\n"
        "lui $3,0x3fc9\n"
        "mtc1 $2,$f2\n"
        "lw $4,lpDrawMng\n"
        "ori $3,$3,0xfdb\n"
        "sub.s $f2,$f2,%0\n"
        "lwc1 $f0,0x41c($4)\n"
        "mtc1 $3,$f3\n"
        "lui $3,0x3f00\n"
        "mtc1 $3,$f1\n"
        "mul.s $f2,$f3,$f2\n"
        "mul.s $f0,$f1,$f0\n"
        "c.le.s $f2,$f0\n"
        ".word 0x45010002\n"
        "addiu $2,$zero,1\n"
        "daddu $2,$zero,$zero\n"
        ".set reorder\n"
        :
        : "f"(f0)
        : "$2", "$3", "$4", "$f1", "$f2", "$f3", "memory");
    return;
}

void SfxCalc_RotateVector(float *a0 /* r4 */, float f12 /* f12 */, float f13 /* f13 */, float f14
        /* f14 */) {
    u32 s0;
    u8 *a1;
    float f2;
    float f1;
    float f21;
    float f20;
    float f0;
    u32 v0;
    u8 stackFrame_B0[64] __attribute__((aligned(16)));
    u8 stackFrame_70[64] __attribute__((aligned(16)));
    u8 stackFrame_30[64] __attribute__((aligned(16)));

    v0 = 0x40490fdb;
    f1 = 3.14159274f;
    s0 = (u32)a0;
    f2 = (3.14159274f + f12);
    f0 = 0.0f;
    f21 = f13;
    f20 = f14;
    if (f2 >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f12 = ((float)f12 - (6.28318548f * (float)((float)(s32)(f2 / 6.28318548f))));
    } else {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f12 = (6.28318548f + (f12 - (6.28318548f * (float)((float)(s32)(f2 / 6.28318548f)))));
    }
    a1 = (u8 *)MRX1;
    sceVu0RotMatrixX((void *)((u8 *)&stackFrame_B0[0]), (void *)MRX1, f12);
    f1 = 3.14159274f;
    f0 = 0.0f;
    f2 = (3.14159274f + f21);
    if (f2 >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f12 = (f21 - (6.28318548f * (float)((float)(s32)(f2 / 6.28318548f))));
    } else {
        f1 = 6.28318548f;
        f12 = (f1 + (f21 - (f1 * (float)((float)(s32)(f2 / f1)))));
    }
    a1 = (u8 *)MRX1;
    sceVu0RotMatrixY((void *)((u8 *)&stackFrame_70[0]), (void *)MRX1, f12);
    f1 = 3.14159274f;
    f0 = 0.0f;
    f2 = (3.14159274f + f20);
    if (f2 >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f12 = (f20 - (6.28318548f * (float)((float)(s32)(f2 / 6.28318548f))));
    } else {
        f1 = 6.28318548f;
        f12 = (f1 + (f20 - (f1 * (float)((float)(s32)(f2 / f1)))));
    }
    a1 = (u8 *)MRX1;
    sceVu0RotMatrixZ((void *)((u8 *)&stackFrame_30[0]), (void *)MRX1, f12);
    sceVu0ApplyMatrix(s0, (u8 *)((u8 *)&stackFrame_B0[0]), s0);
    sceVu0ApplyMatrix(s0, (u8 *)((u8 *)&stackFrame_70[0]), s0);
    sceVu0ApplyMatrix(s0, (u8 *)((u8 *)&stackFrame_30[0]), s0);
    return;
}


/* SfxCalc_IntoAngle_0_2PI @ 0x1BE820 .. 0x1BE860 (0x40 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40c90fd0 at 0x1be828
 *   fpu: float literal 0x00000000 at 0x1be82c
 *   fpu: mov.s at 0x1be85c is a float copy
 *   return: mov.s at 0x1be85c computes the return value
 */

float SfxCalc_IntoAngle_0_2PI(float f12 /* f12 */) {
    f12 = (f12 - (6.28318024f * (float)((float)(s32)(f12 / 6.28318024f))));
    if (f12 < 0.0f) {
        f12 = (f12 + 6.28318024f);
    }
    return f12;
}

void SfxCalc_MakeMatrixFromPYR(void *a0 /* r4 */, float f12 /* f12 */, float f13 /* f13 */, float
        f14 /* f14 */) {
    u32 s0;
    float f21;
    float f20;
    float f1;
    u32 a1;
    float f0;
    u32 v0;

    f1 = 0.0f;
    s0 = (u32)a0;
    f21 = f13;
    f20 = f14;
    if (!(0.0f == f12)) {
        f0 = 3.14159274f;
        f0 = (3.14159274f + f12);
        if (f0 >= f1) {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = ((float)f12 - (6.28318548f * (float)((float)(s32)(f0 / 6.28318548f))));
        } else {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f1 + (f12 - (f1 * (float)((float)(s32)(f0 / f1)))));
        }
        a1 = (u32)MRX1;
        sceVu0RotMatrixX((void *)s0, (void *)MRX1, f12);
    } else {
        a1 = (u32)MRX1;
        sceVu0CopyMatrix(a0, (void *)MRX1);
    }
    f1 = 0.0f;
    if (!(0.0f == f21)) {
        f0 = 3.14159274f;
        f0 = (3.14159274f + f21);
        if (f0 >= f1) {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f21 - (6.28318548f * (float)((float)(s32)(f0 / 6.28318548f))));
        } else {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f1 + (f21 - (f1 * (float)((float)(s32)(f0 / f1)))));
        }
        sceVu0RotMatrixY((void *)s0, (void *)s0, f12);
    }
    f1 = 0.0f;
    if (!(0.0f == f20)) {
        f0 = 3.14159274f;
        f0 = (3.14159274f + f20);
        if (f0 >= f1) {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f20 - (6.28318548f * (float)((float)(s32)(f0 / 6.28318548f))));
        } else {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f1 + (f20 - (f1 * (float)((float)(s32)(f0 / f1)))));
        }
        sceVu0RotMatrixZ((void *)s0, (void *)s0, f12);
    }
    return;
}



void *SfxUtil_FindChar_Corn(signed int bEnemy, float *pos_, float *dir_, float range_, float theta_, signed int bEnableObstacle_) {
    float half_theta;
    u8 *pChar;
    u8 *pNearChar;
    float near_dist;
    float work_dist;
    float work_ang;
    float work_vec[4];
    float tgt_pos[4];
    int team;

    team = bEnemy != 0;
    half_theta = 0.5f * theta_;
    pNearChar = 0;
    near_dist = -1.0f;
    for (pChar = MdlMng + 0x119c0; pChar != MdlMng + 0x17f40; pChar += 0x1c0) {
        if (pChar[0x128] != team || pChar[0] == 0) continue;
        if (bEnemy != 0) {
            if (CheckEneDamage(pChar) == 0) continue;
        }
        SfxUtil_GetCharCenter(tgt_pos, (struct SfxChar *)pChar);
        work_dist = Math_GetDist(tgt_pos, pos_);
        if (range_ < work_dist) continue;
        sceVu0SubVector(work_vec, tgt_pos, pos_);
        sceVu0Normalize(work_vec, work_vec);
        work_ang = fabsf(1.5707964f * (sceVu0InnerProduct(dir_, work_vec) - 1.0f));
        if (half_theta < work_ang) continue;
        if (bEnableObstacle_ != 0) {
            float work_vec[4];
            SFX_BOOL hit;
            sceVu0SubVector(work_vec, tgt_pos, pos_);
            sceVu0Normalize(work_vec, work_vec);
            sceVu0ScaleVector(work_vec, work_vec, work_dist);
            if (CheckHitMapLine((float (*)[4])pos_, (float (*)[4])work_vec) < 1.0f) hit = SFX_TRUE; else hit = SFX_FALSE;
            if (hit) continue;
        }
        if (near_dist >= 0.0f) {
            if (!(work_dist < near_dist)) continue;
        }
        pNearChar = pChar;
        near_dist = work_dist;
    }
    return pNearChar;
}


void *SfxUtil_FindChar_Sphere(signed int bEnemy, float *pos_, float range_, signed int bEnableObstacle_) {
    int i;
    int end;
    int team;
    struct SfxChar *pChar;
    struct SfxChar *pNearChar;
    float near_dist;
    float work_dist;
    float tgt_pos[4];
    float work_vec[4];

    team = bEnemy != 0;
    pNearChar = 0;
    near_dist = -1.0f;
    i = bEnemy ? 0xa1 : 0xd3;
    end = bEnemy ? 0xd3 : 0xdc;
    for (; i < end; i++) {
        if (i == 0xdb) {
            pChar = (struct SfxChar *)(MdlMng + 0x11800);
        } else {
            pChar = &((struct SfxChar *)MdlMng)[i];
        }
        if (pChar->team == team && pChar->bUse != 0) {
            if (bEnemy != 0) {
                if (CheckEneDamage(pChar) == 0) {
                    continue;
                }
            }
            SfxUtil_GetCharCenter(tgt_pos, pChar);
            work_dist = Math_GetDist(pChar->pos, pos_);
            if (range_ < work_dist) {
                continue;
            }
            if (bEnableObstacle_ != 0) {
                SFX_BOOL hit;
                sceVu0SubVector(work_vec, tgt_pos, pos_);
                sceVu0Normalize(work_vec, work_vec);
                sceVu0ScaleVector(work_vec, work_vec, work_dist);
                if (CheckHitMapLine(pos_, work_vec) < 1.0f) hit = SFX_TRUE; else hit = SFX_FALSE;
                if (hit) {
                    continue;
                }
            }
            if (near_dist < 0.0f || work_dist < near_dist) {
                pNearChar = pChar;
                near_dist = work_dist;
            }
        }
    }
    return pNearChar;
}



void *SfxUtil_FindChar_Fan(signed int bEnemy, float *pos_, float *dir_, float range_, float theta_, signed int bEnableObstacle_) {
    float half_theta;
    u8 *pChar;
    u8 *pNearChar;
    float near_dist;
    float work_dist;
    float work_ang;
    int team;
    SFX_BOOL hit;

    team = bEnemy != 0;
    half_theta = 0.5f * theta_;
    pNearChar = 0;
    near_dist = -1.0f;
    for (pChar = MdlMng + 0x119c0; pChar != MdlMng + 0x17f40; pChar += 0x1c0) {
        float work_vec[4];
        float org_pos[4];
        float tgt_pos[4];
        if (pChar[0x128] != team || pChar[0] == 0) continue;
        if (bEnemy != 0) {
            if (CheckEneLockOn(pChar) == 0) continue;
        }
        sceVu0CopyVector(tgt_pos, pChar + 0x20);
        sceVu0CopyVector(org_pos, pos_);
        tgt_pos[1] = 0.0f;
        org_pos[1] = 0.0f;
        work_dist = Math_GetDist(tgt_pos, org_pos);
        if (range_ < work_dist) continue;
        sceVu0SubVector(work_vec, tgt_pos, org_pos);
        sceVu0Normalize(work_vec, work_vec);
        work_ang = fabsf(1.5707964f * (sceVu0InnerProduct(dir_, work_vec) - 1.0f));
        if (half_theta < work_ang) continue;
        if (bEnableObstacle_ != 0) {
            float work_vec2[4];
            SfxUtil_GetCharCenter(tgt_pos, (struct SfxChar *)pChar);
            sceVu0SubVector(work_vec2, tgt_pos, pos_);
            sceVu0Normalize(work_vec2, work_vec2);
            sceVu0ScaleVector(work_vec2, work_vec2, work_dist);
            if (CheckHitMapLine((float (*)[4])pos_, (float (*)[4])work_vec2) < 1.0f) hit = SFX_TRUE; else hit = SFX_FALSE;
            if (hit) continue;
        }
        if (near_dist >= 0.0f) {
            if (!(work_dist < near_dist)) continue;
        }
        pNearChar = pChar;
        near_dist = work_dist;
    }
    return pNearChar;
}


/* SfxCalc_PY_To_Dir @ 0x1BDE70 .. 0x1BDEF0 (0x80 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1bde88 is a float copy
 *   fpu: mov.s at 0x1bde8c is a float copy
 *   fpu: mov.s at 0x1bde98 is a float copy
 *   fpu: mov.s at 0x1bdea0 is a float copy
 *   fpu: mov.s at 0x1bdea8 is a float copy
 *   fpu: mov.s at 0x1bdeb8 is a float copy
 */

void SfxCalc_PY_To_Dir(float f12 /* f12 */, float f13 /* f13 */, void *a0 /* r4 */) {
    float f22;
    float f21;
    float f20;
    float f0;

    f21 = f13;
    f22 = f12;
    f0 = cosf(f12);
    f20 = f0;
    f0 = sinf((float)f21);
    f12 = f22;
    *(f32 *)a0 = (f20 * f0);
    f0 = (-sinf(f12));
    f12 = f21;
    *(f32 *)(((u8 *)a0 + 4)) = f0;
    f0 = cosf(f12);
    *(f32 *)(((u8 *)a0 + 8)) = (f20 * f0);
    *(u32 *)(((u8 *)a0 + 0xc)) = 0x3f800000;
    return;
}

signed int SfxUtil_HitCheck_Line_Map(float *a0 /* r4 */, float *a1 /* r5 */, void *a2 /* r6 */,
        void *a3 /* r7 */, unsigned int *t0 /* r8 */) {
    u32 *s0;
    float f0;
    float *a1_value; // a1
    float *a0_value; // a0
    u32 v0;
    u8 stackFrame_70[32] __attribute__((aligned(16)));
    u8 stackFrame_60[16] __attribute__((aligned(16)));

    s0 = (u32 *)t0;
    f0 = CheckHitMapLineGetNormal((void *)a0, (void *)a1, (void *)((u8 *)&stackFrame_70[0]));
    v0 = 0x3f800000;
    if (f0 < 1.0f) {
        a1_value = (float *)a1;
        if ((u32)a2 != 0) {
            sceVu0ScaleVector((void *)((u8 *)&stackFrame_60[0]), (void *)a1_value, (float)f0);
            sceVu0AddVector((void *)a2, (void *)((u8 *)&stackFrame_60[0]), (void *)a0);
        }
        a0_value = (float *)a3;
        if ((u32)a3 != 0) {
            sceVu0CopyVector((void *)a0_value, (void *)((u8 *)&stackFrame_70[0]));
        }
        if ((u32)s0 != 0) {
            v0 = ((s32 *)stackFrame_70)[4];
            *(u32 *)s0 = v0;
        }
        v0 = 1;
    } else {
        v0 = 0;
    }
    return v0;
}


void SfxCalc_MakeRotTransMatrix_I_LEGACY(float (*mrx)[4], float *loc, float *ang, float *scl) {
    float s0, c0, s1, c1, s2, c2, s0s2, s0c2;

    s0 = sinf(ang[0]);
    c0 = cosf(ang[0]);
    s1 = sinf(ang[1]);
    c1 = cosf(ang[1]);
    s2 = sinf(ang[2]);
    c2 = cosf(ang[2]);
    s0s2 = s0 * s2;
    s0c2 = s0 * c2;

    mrx[0][0] = scl[0] * (s0s2 * s1 + c1 * c2);
    mrx[0][1] = scl[0] * (c0 * s2);
    mrx[0][2] = scl[0] * (s0s2 * c1 - s1 * c2);
    mrx[0][3] = 0.0f;
    mrx[1][0] = scl[1] * (s0c2 * s1 - c1 * s2);
    mrx[1][1] = scl[1] * (c0 * c2);
    mrx[1][2] = scl[1] * (s0c2 * c1 + s1 * s2);
    mrx[1][3] = 0.0f;
    mrx[2][0] = scl[2] * (c0 * s1);
    mrx[2][1] = scl[2] * -s0;
    mrx[2][2] = scl[2] * (c0 * c1);
    mrx[2][3] = 0.0f;
    mrx[3][0] = loc[0];
    mrx[3][1] = loc[1];
    mrx[3][2] = loc[2];
    mrx[3][3] = 1.0f;
}

void SfxCalc_PYRfromRotMatrix_LEGACY(float (*mRot_)[4], float *pPitch_, float *pYaw_, float *pRoll_) {
    float pitch;
    float yaw;
    float roll;
    float vDir[4];
    float vRight[4];
    float vBottom[4];
    float temp;

    sceVu0Normalize(vDir, mRot_[2]);
    sceVu0Normalize(vRight, mRot_[0]);
    sceVu0Normalize(vBottom, mRot_[1]);
    yaw = atan2f(vDir[0], vDir[2]);
    pitch = -asinf(vDir[1]);
    temp = vRight[1] / cosf(pitch);
    if (1.0f < fabsf(temp)) {
        temp = temp / fabsf(temp);
    }
    roll = asinf(temp);
    if (vBottom[1] < 0.0f) {
        roll = 3.14159274f - roll;
    }
    if (fabsf(cosf(pitch)) < 0.1f) {
        yaw = atan2f(-vRight[2], vRight[0]);
        pitch = -asinf(vDir[1]);
        roll = 0.0f;
    }
    if (pYaw_ != 0) {
        *pYaw_ = yaw;
    }
    if (pPitch_ != 0) {
        *pPitch_ = pitch;
    }
    if (pRoll_ != 0) {
        *pRoll_ = roll;
    }
}


void SfxUtil_CalcCutAnimST(int divH_, int divV_, int curr_cut_, float (*pST_)[4]) {
    float s;
    float t;

    s = curr_cut_ % divH_;
    (*pST_)[0] = s * (1.0f / divH_);
    t = curr_cut_ / divH_ % divV_;
    (*pST_)[1] = t * (1.0f / divV_);
    (*pST_)[2] = (*pST_)[0] + 1.0f / divH_;
    (*pST_)[3] = (*pST_)[1] + 1.0f / divV_;
}


void SfxCalc_MakeMatrixFromQtn(float (*mrx_)[4], float *qtn_) {
    float norm;
    float xx, yy, zz;
    float xy, xz, yz;
    float wx, wy, wz;
    float s;

    norm = qtn_[3] * qtn_[3] + (qtn_[2] * qtn_[2] + (qtn_[0] * qtn_[0] + qtn_[1] * qtn_[1]));
    s = norm > 0.0f ? 2.0f / norm : 0.0f;
    xx = s * (qtn_[0] * qtn_[0]);
    yy = s * (qtn_[1] * qtn_[1]);
    zz = s * (qtn_[2] * qtn_[2]);
    xy = s * (qtn_[0] * qtn_[1]);
    xz = s * (qtn_[0] * qtn_[2]);
    wx = s * (qtn_[3] * qtn_[0]);
    yz = s * (qtn_[1] * qtn_[2]);
    wy = s * (qtn_[3] * qtn_[1]);
    wz = s * (qtn_[3] * qtn_[2]);
    mrx_[0][0] = 1.0f - (yy + zz);
    mrx_[0][1] = xy + wz;
    mrx_[0][2] = xz - wy;
    mrx_[1][0] = xy - wz;
    mrx_[1][1] = 1.0f - (xx + zz);
    mrx_[1][2] = yz + wx;
    mrx_[2][0] = xz + wy;
    mrx_[2][1] = yz - wx;
    mrx_[2][2] = 1.0f - (xx + yy);
    mrx_[3][0] = mrx_[3][1] = mrx_[3][2] = mrx_[0][3] = mrx_[1][3] = mrx_[2][3] = 0.0f;
    mrx_[3][3] = 1.0f;
}
void SfxCalc_QtnMakeFromMatrix(float *output, void *input) {
    float *savedOutput = output;
    u8 *savedInput = input;
    float matrix[4][4] __attribute__((aligned(16)));
    float quaternion[4] __attribute__((aligned(16)));
    float trace, scale, x, y, z;
    sceVu0CopyMatrix(matrix, input);
    sceVu0CopyVector(quaternion, output);
    {
        float partial = (float)*(float *)savedInput + *(float *)(savedInput + 0x14);
        trace = *(float *)(savedInput + 0x3c) + (partial + *(float *)(savedInput + 0x28));
    }
    if (trace >= 1.0f) {
        scale = sqrtf(trace);
        y = matrix[2][0] - matrix[0][2];
        z = matrix[0][1] - matrix[1][0];
        scale = 2.0f * (float)scale;
        x = matrix[1][2] - matrix[2][1];
        quaternion[3] = scale / 4.0f;
        quaternion[0] = x / scale;
        quaternion[1] = y / scale;
        quaternion[2] = z / scale;
    } else {
        int i = (matrix[0][0] > matrix[1][1]) ^ 1;
        int j, k;
        if (!(matrix[2][2] <= matrix[i][i])) i = 2;
        j = (i + 1) % 3;
        k = (j + 1) % 3;
        scale = 2.0f * (float)sqrtf(1.0f + ((matrix[i][i] - matrix[j][j]) - matrix[k][k]));
        quaternion[i] = scale / 4.0f;
        quaternion[j] = (matrix[j][i] + matrix[i][j]) / scale;
        quaternion[k] = (matrix[k][i] + matrix[i][k]) / scale;
        quaternion[3] = (matrix[j][k] - matrix[k][j]) / scale;
    }
    sceVu0CopyMatrix(savedInput, matrix);
    sceVu0CopyVector(savedOutput, quaternion);
}


void SfxCalc_QtnMakeFromPYR(float *q, float pitch, float yaw, float roll) {
    float a;
    float b;
    float c;
    float d;

    a = sinf(yaw * 0.5f) * sinf(pitch * 0.5f);
    b = cosf(yaw * 0.5f) * cosf(pitch * 0.5f);
    c = sinf(yaw * 0.5f) * cosf(pitch * 0.5f);
    d = cosf(yaw * 0.5f) * sinf(pitch * 0.5f);
    q[0] = (d * cosf(roll * 0.5f)) - (c * sinf(roll * 0.5f));
    q[1] = (d * sinf(roll * 0.5f)) + (c * cosf(roll * 0.5f));
    q[2] = (b * sinf(roll * 0.5f)) - (a * cosf(roll * 0.5f));
    q[3] = (b * cosf(roll * 0.5f)) + (a * sinf(roll * 0.5f));
}


/* SfxCalc_QtnMakeFromDir @ 0x1BD3A0 .. 0x1BD528 (0x188 bytes, frame 0x50) */

void SfxCalc_QtnMakeFromDir(float *a0 /* r4 */, float *a1 /* r5 */) {
    float pitch;
    float yaw;
    float a;
    float b;
    float c;
    float d;

    pitch = atan2f(-a1[1], sqrtf(a1[0] * a1[0] + a1[2] * a1[2]));
    yaw = atan2f(a1[0], a1[2]);
    a = sinf(yaw * 0.5f) * sinf(pitch * 0.5f);
    b = cosf(yaw * 0.5f) * cosf(pitch * 0.5f);
    c = sinf(yaw * 0.5f) * cosf(pitch * 0.5f);
    d = cosf(yaw * 0.5f) * sinf(pitch * 0.5f);
    a0[0] = (d * cosf(0.0f)) - (c * sinf(0.0f));
    a0[1] = (d * sinf(0.0f)) + (c * cosf(0.0f));
    a0[2] = (b * sinf(0.0f)) - (a * cosf(0.0f));
    a0[3] = (b * cosf(0.0f)) + (a * sinf(0.0f));
    return;
}
void SfxCalc_QtnSLerp(float *out, float *left, float *right, float amount) {
    float blend;
    float dot;
    float angle;
    float sine;
    float target[4] __attribute__((aligned(16)));
    float scaled[4] __attribute__((aligned(16)));
    dot = left[1] * right[1] + left[0] * right[0] + left[2] * right[2] + left[3] * right[3];
    blend = amount;
    if (dot < 0.0f) {
        dot = -dot;
        sceVu0ScaleVector(target, right, -1.0f);
    } else sceVu0CopyVector(target, right);
    angle = acosf(dot);
    sine = sinf(angle);
    dot = sinf(angle * blend);
    sceVu0ScaleVector(out, left, sinf(angle * (1.0f - blend)));
    sceVu0ScaleVector(scaled, target, dot);
    sceVu0AddVector(out, scaled, out);
    sceVu0ScaleVector(out, out, 1.0f / sine);
}


/* SfxCalc_QtnMult @ 0x1BD150 .. 0x1BD234 (0xe4 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred float
 */

void SfxCalc_QtnMult(float *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */) {
    *(f32 *)a0 = (((a1[3] * *(float *)a2) + ((a1[1] * a2[2]) - (a1[2] * a2[1]))) + (*(float *)a1 *
        a2[3]));
    a0[1] = (((a1[3] * a2[1]) + ((a1[2] * *(float *)a2) - (*(float *)a1 * a2[2]))) + (a1[1] *
        a2[3]));
    a0[2] = (((a1[3] * a2[2]) + ((*(float *)a1 * a2[1]) - (a1[1] * *(float *)a2))) + (a1[2] *
        a2[3]));
    a0[3] = ((((a1[3] * a2[3]) - (*(float *)a1 * *(float *)a2)) - (a1[1] * a2[1])) - (a1[2] *
        a2[2]));
    return;
}
void SfxUtil_CalcRndPos(float *a0 /* r4 */, signed int a1 /* r5 */, float *a2 /* r6 */) {
    float r;
    float ya;
    float pa;
    float c;

    switch (a1) {
    case 1:
        r = 0.5f * a2[0];
        ya = 6.2831855f * (1.5259022e-05f * (float)(u16)RndInl());
        pa = 6.2831855f * (1.5259022e-05f * (float)(u16)RndInl());
        c = r * cosf(ya);
        a0[0] = c * cosf(pa);
        a0[1] = r * sinf(pa);
        r = r * sinf(ya);
        a0[2] = r * cosf(pa);
        a0[3] = 1.0f;
        break;
    case 2:
        a0[0] = a2[0];
        a0[1] = a2[1];
        a0[2] = a2[2];
        *(u32 *)(a0 + 3) = 0;
        sceVu0ScaleVector(a0, a0, 1.5259022e-05f * (float)(u16)RndInl());
        break;
    default:
        a0[0] = a2[0] * (1.5259022e-05f * (float)(u16)RndInl() - 0.5f);
        a0[1] = a2[1] * (1.5259022e-05f * (float)(u16)RndInl() - 0.5f);
        a0[2] = a2[2] * (1.5259022e-05f * (float)(u16)RndInl() - 0.5f);
    }
    a0[3] = 1.0f;
}


void SfxCalc_MakeMatrix_SPYRT(void *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */, float *a3
        /* r7 */) {
    float f12;
    float f2;
    float f1;
    float f21;
    float f20;
    float f0;
    u8 *v1;
    s32 v0;
    float *a1_2;
    void *a0_2;
    u8 stackFrame_A0[64] __attribute__((aligned(16)));
    u8 stackFrame_60[64] __attribute__((aligned(16)));

    sceVu0UnitMatrix((void *)(u8 *)((u8 *)&stackFrame_A0[0]));
    f1 = 0.0f;
    *(f32 *)((u8 *)&stackFrame_A0[0]) = *(float *)a1;
    ((f32 *)stackFrame_A0)[5] = a1[1];
    ((f32 *)stackFrame_A0)[10] = a1[2];
    f2 = *(float *)a2;
    f20 = a2[2];
    f21 = a2[1];
    if (!(0.0f == f2)) {
        f0 = 3.14159274f;
        f0 = (3.14159274f + f2);
        if (f0 >= f1) {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f2 - (6.28318548f * (float)((float)(s32)(f0 / 6.28318548f))));
        } else {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f1 + (f2 - (f1 * (float)((float)(s32)(f0 / f1)))));
        }
        a1_2 = (float *)MRX1;
        sceVu0RotMatrixX((void *)(u8 *)((u8 *)&stackFrame_60[0]), (void *)MRX1, f12);
    } else {
        a1_2 = (float *)MRX1;
        sceVu0CopyMatrix((void *)(u8 *)((u8 *)&stackFrame_60[0]), (void *)MRX1);
    }
    if (!(0.0f == f21)) {
        v0 = 0x40490fdb;
        f0 = 3.14159274f;
        f0 = (3.14159274f + f21);
        if (f0 >= 0.0f) {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f21 - (6.28318548f * (float)((float)(s32)(f0 / 6.28318548f))));
        } else {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (6.28318548f + (f21 - (6.28318548f * (float)((float)(s32)(f0 / 6.28318548f)))));
        }
        sceVu0RotMatrixY((void *)(u8 *)((u8 *)&stackFrame_60[0]), (void *)((u8
            *)&stackFrame_60[0]), f12);
    }
    if (!(0.0f == f20)) {
        v0 = 0x40490fdb;
        f0 = 3.14159274f;
        f0 = (3.14159274f + f20);
        if (f0 >= 0.0f) {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f20 - (6.28318548f * (float)((float)(s32)(f0 / 6.28318548f))));
        } else {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (6.28318548f + (f20 - (6.28318548f * (float)((float)(s32)(f0 / 6.28318548f)))));
        }
        sceVu0RotMatrixZ((void *)(u8 *)((u8 *)&stackFrame_60[0]), (void *)((u8
            *)&stackFrame_60[0]), f12);
    }
    sceVu0CopyVector((void *)(u8 *)((u8 *)&stackFrame_60[48]), (void *)a3);
    a0_2 = (void *)((u8 *)&stackFrame_60[0]);
    v1 = ((u8 *)&stackFrame_A0[0]);
    dcomp_cop2_9397A3F6B7((void *)((u8 *)a0), (void *)((u8 *)((u8 *)&stackFrame_60[0])), (void
        *)(&stackFrame_A0[0]));
    return;
}

void SfxCalc_DirMakeFromQtn(float *out, float *q) {
    __asm__ volatile(
        ".set noreorder\n"
        ".word 0xc4a40004\n"
        ".word 0xc4a50000\n"
        ".word 0xc4a20008\n"
        ".word 0xc4a3000c\n"
        ".word 0x44804000\n"
        ".word 0x46042182\n"
        ".word 0x460529c2\n"
        ".word 0x46021042\n"
        ".word 0x46063800\n"
        ".word 0x46000818\n"
        ".word 0x4603185c\n"
        ".word 0x46080836\n"
        ".word 0x45010007\n"
        ".word 0x3c034000\n"
        ".word 0x44830000\n"
        ".word 0x00000000\n"
        ".word 0x46010203\n"
        ".word 0x00000000\n"
        ".word 0x00000000\n"
        ".word 0x00000000\n"
        ".word 0x46022802\n"
        ".word 0x3c033f80\n"
        ".word 0x46022042\n"
        ".word 0x4600401a\n"
        ".word 0x46041882\n"
        ".word 0x4602409c\n"
        ".word 0x46051802\n"
        ".word 0x4601401a\n"
        ".word 0x4600401d\n"
        ".word 0xe4820000\n"
        ".word 0xe4800004\n"
        ".word 0x4607401a\n"
        ".word 0x44830000\n"
        ".word 0x4606405c\n"
        ".word 0x46010001\n"
        ".word 0xe4800008\n"
        :
        :
        : "memory");
    *(u32 *)(out + 3) = 0;
}

void SfxCalc_VecTransformByQtn(float *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */) {
    u32 s1;
    u32 s0;
    u8 stackFrame[64] __attribute__((aligned(16)));

    s1 = (u32)a0;
    s0 = (u32)a2;
    SfxCalc_MakeMatrixFromQtn((void *)(u32)((u8 *)&stackFrame[0]), a1);
    sceVu0ApplyMatrix(s1, (s32)(u8 *)((u8 *)&stackFrame[0]), (void *)s0);
    return;
}

u32 SfxCalc_VecHermite(float *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */, float *a3 /* r7
        */, float *t0 /* r8 */, float f12 /* f12 */) {
    u32 s3;
    u32 s2;
    u32 *s1;
    u32 s0;
    float f23;
    float f22;
    float f21;
    float f1;
    float f20;
    float f0;
    u8 stackFrame_A0[16] __attribute__((aligned(16)));
    u8 stackFrame_90[16] __attribute__((aligned(16)));
    u8 stackFrame_80[16] __attribute__((aligned(16)));
    u8 stackFrame_70[16] __attribute__((aligned(16)));
    u8 stackFrame_60[16] __attribute__((aligned(16)));

    s3 = (u32)a2;
    s2 = (u32)t0;
    s1 = (u32 *)a0;
    s0 = (u32)a3;
    f23 = (float)f12;
    if ((u32)a1 != 0) {
        sceVu0SubVector((void *)(u32 *)((u8 *)&stackFrame_A0[0]), (void *)s3, (void *)a1);
    } else {
        a1 = (float *)V0;
        sceVu0CopyVector((void *)(u32 *)((u8 *)&stackFrame_A0[0]), (void *)V0);
    }
    sceVu0AddVector((void *)(u32 *)((u8 *)&stackFrame_A0[0]), (void *)((u8 *)&stackFrame_A0[0]),
        (void *)s0);
    sceVu0SubVector((void *)(u32 *)((u8 *)&stackFrame_A0[0]), (void *)((u8 *)&stackFrame_A0[0]),
        (void *)s3);
    f12 = 0.5f;
    sceVu0ScaleVector((void *)(u32 *)((u8 *)&stackFrame_A0[0]), (void *)((u8 *)&stackFrame_A0[0]),
        0.5f);
    sceVu0SubVector((void *)(u32 *)((u8 *)&stackFrame_90[0]), (void *)s0, (void *)s3);
    a0 = (float *)((u8 *)&stackFrame_90[0]);
    if (s2 != 0) {
        sceVu0AddVector((void *)a0, (void *)((u8 *)&stackFrame_90[0]), (void *)s2);
        sceVu0SubVector((void *)(u32 *)((u8 *)&stackFrame_90[0]), (void *)((u8
            *)&stackFrame_90[0]), (void *)s0);
    }
    f12 = 0.5f;
    sceVu0ScaleVector((void *)(u32 *)((u8 *)&stackFrame_90[0]), (void *)((u8 *)&stackFrame_90[0]),
        0.5f);
    f22 = (f23 * f23);
    f21 = (f22 * f23);
    f1 = 2.0f;
    f20 = (3.0f * f22);
    f1 = (2.0f * f21);
    f1 = (f1 - f20);
    f0 = 1.0f;
    f12 = (1.0f + f1);
    sceVu0ScaleVector((void *)(u32 *)s1, (void *)s3, f12);
    f0 = 2.0f;
    f0 = (2.0f * f22);
    f0 = (f21 - f0);
    f12 = (f23 + f0);
    sceVu0ScaleVector((void *)(u32 *)((u8 *)&stackFrame_80[0]), (void *)((u8 *)&stackFrame_A0[0]),
        f12);
    sceVu0AddVector((void *)(u32 *)s1, (void *)((u8 *)&stackFrame_80[0]), (void *)s1);
    f12 = (f21 - f22);
    sceVu0ScaleVector((void *)(u32 *)((u8 *)&stackFrame_70[0]), (void *)((u8 *)&stackFrame_90[0]),
        f12);
    sceVu0AddVector((void *)(u32 *)s1, (void *)((u8 *)&stackFrame_70[0]), (void *)s1);
    f0 = -2.0f;
    f0 = (-2.0f * f21);
    f12 = (f0 + f20);
    sceVu0ScaleVector((void *)(u32 *)((u8 *)&stackFrame_60[0]), (void *)s0, f12);
    sceVu0AddVector((void *)(u32 *)s1, (void *)((u8 *)&stackFrame_60[0]), (void *)s1);
    *(u32 *)(((u8 *)s1 + 0xc)) = 0x3f800000;
    return;
}

void NM_GetPcHeadPos(float *a0 /* r4 */) {
    u32 s0;
    u32 v0;
    s32 a1;
    u32 v1;
    u32 a2;

    s0 = (u32)a0;
    a0 = (float *)*(s32 *)((u8 *)&MdlMng + 0x1180c);
    v0 = (u32)GetDummyPolyData((void *)a0, 0, 0);
    a1 = *(s16 *)(((u8 *)v0 + 0x20));
    v1 = *(s32 *)((u8 *)&MdlMng + 0x11810);
    a2 = v0;
    a0 = (float *)s0;
    v0 = (u32)a1 << 6;
    a1 = v1 + v0;
    sceVu0ApplyMatrix((u32)a0, a1, (void *)a2);
    return;
}
