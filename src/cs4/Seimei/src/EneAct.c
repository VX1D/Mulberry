#include "common.h"

/* SetEneClingOut @ 0x160DB0 .. 0x160DF4 (0x44 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x160db8
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);

/* SetEneBackClingPos @ 0x160E00 .. 0x160E9C (0x9c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3c23d70a at 0x160e38
 *   fpu: float literal 0x3e4ccccd at 0x160e3c
 *   fpu: float literal 0x3d4ccccd at 0x160e48
 *   fpu: float literal 0x3c0ef34d at 0x160e64
 *   fpu: mov.s at 0x160e7c is a float copy
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int Math_GotoVector2(float *, float *, float, float, float);
extern float Math_GotoAngle(float, float, float);

/* SetEneClingAndPush @ 0x160FC0 .. 0x161374 (0x3b4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: daddu at 0x161010 writes a register its branch at 0x16100c reads
 *   delay: daddu at 0x161050 writes a register its branch at 0x16104c reads
 *   fpu: float literal 0x00000000 at 0x161068
 *   fpu: float literal 0x3e4ccccd at 0x16108c
 *   fpu: float literal 0x00000000 at 0x1610d0
 *   fpu: float literal 0x3fc90fdb at 0x1610f0
 *   fpu: float literal 0x00000000 at 0x161104
 *   delay: lui at 0x161158 writes a register its branch at 0x161154 reads
 *   fpu: float literal 0x3c23d70a at 0x161170
 *   fpu: float literal 0x3e4ccccd at 0x161174
 *   fpu: float literal 0x3d4ccccd at 0x161180
 *   fpu: float literal 0x40490fdb at 0x16119c
 *   fpu: float literal 0x00000000 at 0x1611a0
 *   fpu: float literal 0x40c90fdb at 0x1611c4
 *   fpu: mtc1 reinterprets v0 at 0x1611e8
 *   fpu: float literal 0x40490fdb at 0x161218
 *   fpu: float literal 0x3c0ef34d at 0x161228
 *   fpu: float literal 0x00000000 at 0x161264
 *   delay: lui at 0x1612b8 writes a register its branch at 0x1612b4 reads
 *   fpu: float literal 0x3c23d70a at 0x1612d0
 *   fpu: float literal 0x3e4ccccd at 0x1612d4
 *   fpu: float literal 0x3d4ccccd at 0x1612e0
 *   fpu: float literal 0x3c0ef34d at 0x1612fc
 *   fpu: mov.s at 0x161314 is a float copy
 *   cfg: kept goto: 0x161000 -> .L00161358
 *   cfg: kept goto: 0x161038 -> .L00161358
 *   a0#6 is the pointer held in a1+0x1e4
 *   a0#15 is the pointer held in a1+0x1e4
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u32 GetCamCtrlMode();
extern signed int CheckMyDamage(void *, void *);
extern float Math_GetAngleDist(float, float);
extern void SetMyDamage(void *, void *, unsigned short);
extern void ClearMyStruggleStick();
extern unsigned int CheckAnimParam(void *, signed int);

struct dw_616170_fields;
struct dw_632134_fields;
#ifndef PROTO_DW_629974_FIELDS
#define PROTO_DW_629974_FIELDS
struct dw_629974_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_629128_FIELDS
#define PROTO_DW_629128_FIELDS
struct dw_629128_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_628744_FIELDS
#define PROTO_DW_628744_FIELDS
struct dw_628744_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_616170_fields *lpMdl; };
#endif
#ifndef PROTO_DW_616170_FIELDS
#define PROTO_DW_616170_FIELDS
struct dw_616170_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_632134_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_616170_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_629974_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_629128_fields flags; unsigned char _pad1[3]; struct dw_628744_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_633758_FIELDS
#define PROTO_DW_633758_FIELDS
struct dw_633758_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_632134_FIELDS
#define PROTO_DW_632134_FIELDS
struct dw_632134_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_633758_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_616170_FIELDS_TARGET_LPMDL_47F8147B_DEFINED
#define DCOMP_OFF_STRUCT_DW_616170_FIELDS_TARGET_LPMDL_47F8147B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_616170_FIELDS_TARGET_LPMDL_47F8147B = (int)&(((struct dw_616170_fields *)0)->Target.lpMdl) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPMDLDATA_4C9B1C04_DEFINED
#define DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPMDLDATA_4C9B1C04_DEFINED
enum { DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPMDLDATA_4C9B1C04 = (int)&(((struct dw_616170_fields *)0)->lpMdlData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_632134_FIELDS_MDLTYPE_494DCE2F_DEFINED
#define DCOMP_OFF_STRUCT_DW_632134_FIELDS_MDLTYPE_494DCE2F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_632134_FIELDS_MDLTYPE_494DCE2F = (int)&(((struct dw_632134_fields *)0)->MdlType) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_632134_FIELDS_LPPRM_291B2B52_DEFINED
#define DCOMP_OFF_STRUCT_DW_632134_FIELDS_LPPRM_291B2B52_DEFINED
enum { DCOMP_OFF_STRUCT_DW_632134_FIELDS_LPPRM_291B2B52 = (int)&(((struct dw_632134_fields *)0)->lpPrm) - 0 };
#endif
#ifndef DCOMP_EXPR_CFEF94067507FB7D
#define DCOMP_EXPR_CFEF94067507FB7D(dcomp_arg) ((dcomp_arg) < 0.0f ? (-(dcomp_arg)) : (dcomp_arg))
#endif
static inline void SetEneFrontClingPos_i(void *a0 /* r4 */, void *a1 /* r5 */) {
    float *s1;
    u8 *s0;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;
    float f3;
    float f2;
    float f1;
    float f0;

    s1 = (float *)a0;
    v0 = *(u8 *)(((u8 *)a1 + 0x247));
    s0 = (u8 *)a1;
    if (v0 == 0) {
        v0 = 0x3e4c0000;
        a1 = (void *)*(s32 *)(s0 + 0x1e4);
        v1 = 0x3e4c0000 | 0xcccd;
        f13 = 0.00999999978f;
        f12 = 0.200000003f;
        f14 = 0.0500000007f;
        Math_GotoVector2((float *)((u8 *)s1 + 0x20), (float *)(u32)(s32)((u8 *)a1 + 0x20),
            (f32)0.200000003f, (f32)0.00999999978f, 0.0500000007f);
    }
    v1 = *(s32 *)(s0 + 0x1e4);
    f1 = 3.14159274f;
    f0 = 0.0f;
    f2 = (3.14159274f + *(float *)((v1 + 0x34)));
    f3 = (3.14159274f + f2);
    if (f3 >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f0 = (f2 - (6.28318548f * (float)((float)(s32)(f3 / 6.28318548f))));
    } else {
        f1 = 6.28318548f;
        f0 = (f1 + (f2 - (f1 * (float)((float)(s32)(f3 / f1)))));
    }
    s1[0x66] = f0;
    v1 = *(s32 *)(s0 + 0x1e4);
    f0 = 3.14159274f;
    f14 = 0.00872499961f;
    f12 = *(float *)((v1 + 0x34));
    f0 = Math_GotoAngle(f12, (3.14159274f + s1[0x66]), 0.00872499961f);
    v1 = *(s32 *)(s0 + 0x1e4);
    *(f32 *)((v1 + 0x34)) = f0;
    return;
}

static inline void SetEneBackClingPos_i(void *a0 /* r4 */, void *a1 /* r5 */) {
    float *s1;
    u8 *s0;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;
    float f0;

    s1 = (float *)a0;
    v0 = *(u8 *)(((u8 *)a1 + 0x247));
    s0 = (u8 *)a1;
    if (v0 == 0) {
        v0 = 0x3e4c0000;
        a1 = (void *)*(s32 *)(s0 + 0x1e4);
        v1 = 0x3e4c0000 | 0xcccd;
        f13 = 0.00999999978f;
        f12 = 0.200000003f;
        f14 = 0.0500000007f;
        Math_GotoVector2((float *)((u8 *)s1 + 0x20), (float *)(u32)(s32)((u8 *)a1 + 0x20),
            (f32)0.200000003f, (f32)0.00999999978f, 0.0500000007f);
    }
    v1 = *(s32 *)(s0 + 0x1e4);
    f14 = 0.00872499961f;
    f0 = *(float *)((v1 + 0x34));
    s1[0x66] = f0;
    v0 = *(s32 *)(s0 + 0x1e4);
    f12 = *(float *)((v0 + 0x34));
    f0 = Math_GotoAngle(f12, (float)s1[0x66], 0.00872499961f);
    v1 = *(s32 *)(s0 + 0x1e4);
    *(f32 *)((v1 + 0x34)) = f0;
    return;
}

/* SetEneRebirth @ 0x1613D0 .. 0x161458 (0x88 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1613dc
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern int rand(void);

/* SetEneWalk @ 0x1614E0 .. 0x161554 (0x74 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x16152c
 */

extern unsigned int CheckAnimParam(void *, signed int);

/* EneActGuard @ 0x161620 .. 0x161704 (0xe4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x161650 writes a register its branch at 0x16164c reads
 *   fpu: float literal 0x00000000 at 0x161678
 *   fpu: float literal 0x00000000 at 0x1616ac
 */

extern unsigned int CheckAnimEndFrame(void *);

/* EneActRebirth @ 0x161710 .. 0x161870 (0x160 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x41b80000 at 0x16173c
 *   delay: addiu at 0x16177c writes a register its branch at 0x161778 reads
 *   delay: addiu at 0x161790 writes a register its branch at 0x16178c reads
 *   delay: addiu at 0x1617a4 writes a register its branch at 0x1617a0 reads
 *   delay: addiu at 0x1617b8 writes a register its branch at 0x1617b4 reads
 *   fpu: float literal 0x3e800000 at 0x1617e8
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int CheckAnimNumFrame(void *, float);


extern int SFX_Delete();
extern void EneDeadProc(void *, void *);
extern u32 EneAuraSfx[];


/* EneActDamage @ 0x161AE0 .. 0x161BE8 (0x108 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x41b80000 at 0x161b0c
 *   delay: addiu at 0x161b5c writes a register its branch at 0x161b58 reads
 *   cfg: kept goto: 0x161b70 -> .L00161BD0
 */

extern unsigned int CheckAnimNumFrame(void *, float);
extern unsigned int CheckAnimEndFrame(void *);

/* EneActAttack @ 0x161BF0 .. 0x1629C8 (0xdd8 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x161c3c
 *   fpu: mtc1 reinterprets v1 at 0x161c54
 *   fpu: float literal 0x41200000 at 0x161c6c
 *   delay: addiu at 0x161ca4 writes a register its branch at 0x161ca0 reads
 *   delay: addiu at 0x161cb8 writes a register its branch at 0x161cb4 reads
 *   delay: addiu at 0x161ccc writes a register its branch at 0x161cc8 reads
 *   delay: addiu at 0x161ce0 writes a register its branch at 0x161cdc reads
 *   delay: addiu at 0x161cf4 writes a register its branch at 0x161cf0 reads
 *   delay: addiu at 0x161d08 writes a register its branch at 0x161d04 reads
 *   delay: addiu at 0x161d38 writes a register its branch at 0x161d34 reads
 *   delay: addiu at 0x161d58 writes a register its branch at 0x161d54 reads
 *   fpu: float literal 0x00000000 at 0x161d78
 *   fpu: float literal 0x00000000 at 0x161da8
 *   delay: addiu at 0x161dd0 writes a register its branch at 0x161dcc reads
 *   delay: addiu at 0x161df0 writes a register its branch at 0x161dec reads
 *   fpu: float literal 0x00000000 at 0x161e10
 *   fpu: float literal 0x00000000 at 0x161ea0
 *   fpu: float literal 0x00000000 at 0x161f00
 *   delay: addiu at 0x161f48 writes a register its branch at 0x161f44 reads
 *   delay: addiu at 0x161f68 writes a register its branch at 0x161f64 reads
 *   fpu: float literal 0x00000000 at 0x161f88
 *   fpu: float literal 0x00000000 at 0x161fc8
 *   fpu: float literal 0x00000000 at 0x161fe4
 *   delay: addiu at 0x162010 writes a register its branch at 0x16200c reads
 *   delay: addiu at 0x162030 writes a register its branch at 0x16202c reads
 *   fpu: float literal 0x00000000 at 0x162050
 *   fpu: float literal 0x00000000 at 0x162090
 *   fpu: float literal 0x00000000 at 0x1620ac
 *   delay: addiu at 0x1620d0 writes a register its branch at 0x1620cc reads
 *   delay: addiu at 0x1620f0 writes a register its branch at 0x1620ec reads
 *   fpu: float literal 0x00000000 at 0x162110
 *   fpu: float literal 0x00000000 at 0x162188
 *   delay: addiu at 0x1621c0 writes a register its branch at 0x1621bc reads
 *   delay: addiu at 0x1621e0 writes a register its branch at 0x1621dc reads
 *   fpu: float literal 0x00000000 at 0x162200
 *   fpu: float literal 0x00000000 at 0x162240
 *   fpu: float literal 0x00000000 at 0x16225c
 *   delay: addiu at 0x162284 writes a register its branch at 0x162280 reads
 *   delay: addiu at 0x1622a0 writes a register its branch at 0x16229c reads
 *   fpu: float literal 0x00000000 at 0x1622c0
 *   fpu: float literal 0x00000000 at 0x1622f0
 *   delay: addiu at 0x162314 writes a register its branch at 0x162310 reads
 *   delay: addiu at 0x162330 writes a register its branch at 0x16232c reads
 *   fpu: float literal 0x00000000 at 0x162350
 *   fpu: float literal 0x00000000 at 0x1623e0
 *   fpu: float literal 0x00000000 at 0x162440
 *   delay: addiu at 0x162484 writes a register its branch at 0x162480 reads
 *   delay: addiu at 0x1624a0 writes a register its branch at 0x16249c reads
 *   fpu: float literal 0x00000000 at 0x1624c0
 *   fpu: float literal 0x00000000 at 0x162500
 *   fpu: float literal 0x00000000 at 0x16251c
 *   delay: addiu at 0x162544 writes a register its branch at 0x162540 reads
 *   delay: addiu at 0x162560 writes a register its branch at 0x16255c reads
 *   fpu: float literal 0x00000000 at 0x162580
 *   fpu: float literal 0x00000000 at 0x1625c0
 *   fpu: float literal 0x00000000 at 0x1625dc
 *   delay: addiu at 0x1625fc writes a register its branch at 0x1625f8 reads
 *   delay: addiu at 0x162618 writes a register its branch at 0x162614 reads
 *   fpu: float literal 0x00000000 at 0x162638
 *   fpu: float literal 0x00000000 at 0x1626b0
 *   delay: addiu at 0x1626e4 writes a register its branch at 0x1626e0 reads
 *   delay: addiu at 0x162700 writes a register its branch at 0x1626fc reads
 *   fpu: float literal 0x00000000 at 0x162720
 *   fpu: float literal 0x00000000 at 0x162760
 *   fpu: float literal 0x00000000 at 0x16277c
 *   fpu: float literal 0x3c23d70a at 0x16284c
 *   fpu: float literal 0x3e4ccccd at 0x162850
 *   fpu: float literal 0x3d4ccccd at 0x16285c
 *   fpu: float literal 0x40490fdb at 0x162874
 *   fpu: float literal 0x00000000 at 0x162878
 *   fpu: float literal 0x40c90fdb at 0x16289c
 *   fpu: mtc1 reinterprets v0 at 0x1628c0
 *   fpu: float literal 0x40490fdb at 0x1628f0
 *   fpu: float literal 0x3c0ef34d at 0x162900
 *   fpu: float literal 0x3c23d70a at 0x16293c
 *   fpu: float literal 0x3e4ccccd at 0x162940
 *   fpu: float literal 0x3d4ccccd at 0x16294c
 *   fpu: float literal 0x3c0ef34d at 0x162964
 *   fpu: float literal 0x3c8ef34d at 0x162990
 *   cfg: kept goto: 0x161d7c -> .L00162818
 *   cfg: kept branch: 0x161d98 if (..) goto .L00162818
 *   cfg: kept goto: 0x161dac -> .L00162818
 *   cfg: kept goto: 0x161e14 -> .L00162818
 *   cfg: kept branch: 0x161e30 if (..) goto .L00162818
 *   cfg: kept goto: 0x161ea4 -> .L00162818
 *   cfg: kept branch: 0x161ec8 if (..) goto .L00162818
 *   cfg: kept branch: 0x161ed4 if (..) goto .L00162818
 *   cfg: kept goto: 0x161f04 -> .L00162818
 *   cfg: kept goto: 0x161f8c -> .L00162818
 *   cfg: kept branch: 0x161fa8 if (..) goto .L00162818
 *   cfg: kept goto: 0x161fcc -> .L00162818
 *   cfg: kept goto: 0x161fe0 -> .L00162818
 *   cfg: kept goto: 0x162054 -> .L00162818
 *   cfg: kept branch: 0x162070 if (..) goto .L00162818
 *   cfg: kept goto: 0x162094 -> .L00162818
 *   cfg: kept goto: 0x1620a8 -> .L00162818
 *   cfg: kept goto: 0x162114 -> .L00162818
 *   cfg: kept branch: 0x162130 if (..) goto .L00162818
 *   cfg: kept branch: 0x162170 if (..) goto .L00162818
 *   cfg: kept branch: 0x16217c if (..) goto .L00162818
 *   cfg: kept goto: 0x16218c -> .L00162818
 *   cfg: kept goto: 0x162204 -> .L00162818
 *   cfg: kept branch: 0x162220 if (..) goto .L00162818
 *   cfg: kept goto: 0x162244 -> .L00162818
 *   cfg: kept goto: 0x162258 -> .L00162818
 *   cfg: kept goto: 0x1622c4 -> .L00162818
 *   cfg: kept branch: 0x1622e0 if (..) goto .L00162818
 *   cfg: kept goto: 0x1622f4 -> .L00162818
 *   cfg: kept goto: 0x162354 -> .L00162818
 *   cfg: kept branch: 0x162370 if (..) goto .L00162818
 *   cfg: kept goto: 0x1623e4 -> .L00162818
 *   cfg: kept branch: 0x162408 if (..) goto .L00162818
 *   cfg: kept branch: 0x162414 if (..) goto .L00162818
 *   cfg: kept goto: 0x162444 -> .L00162818
 *   cfg: kept goto: 0x1624c4 -> .L00162818
 *   cfg: kept branch: 0x1624e0 if (..) goto .L00162818
 *   cfg: kept goto: 0x162504 -> .L00162818
 *   cfg: kept goto: 0x162518 -> .L00162818
 *   cfg: kept goto: 0x162584 -> .L00162818
 *   cfg: kept branch: 0x1625a0 if (..) goto .L00162818
 *   cfg: kept goto: 0x1625c4 -> .L00162818
 *   cfg: kept goto: 0x1625d8 -> .L00162818
 *   cfg: kept goto: 0x16263c -> .L00162818
 *   cfg: kept branch: 0x162658 if (..) goto .L00162818
 *   cfg: kept branch: 0x162698 if (..) goto .L00162818
 *   cfg: kept branch: 0x1626a4 if (..) goto .L00162818
 *   cfg: kept goto: 0x1626b4 -> .L00162818
 *   cfg: kept goto: 0x162724 -> .L00162818
 *   cfg: kept branch: 0x162740 if (..) goto .L00162818
 *   cfg: kept goto: 0x162764 -> .L00162818
 *   cfg: kept goto: 0x162778 -> .L00162818
 *   cfg: kept branch: 0x162798 if (..) goto .L00162818
 */

extern void SetEneAttackOff(void *, void *);


struct dw_626529_fields;

#ifndef PROTO_DW_629974_FIELDS
#define PROTO_DW_629974_FIELDS

#endif
#ifndef PROTO_DW_629128_FIELDS
#define PROTO_DW_629128_FIELDS

#endif
#ifndef PROTO_DW_628744_FIELDS
#define PROTO_DW_628744_FIELDS

#endif
#ifndef PROTO_DW_616170_FIELDS
#define PROTO_DW_616170_FIELDS

#endif
#ifndef PROTO_DW_634074_FIELDS
#define PROTO_DW_634074_FIELDS
struct dw_634074_fields { void *ThkFunc[32]; void *ActFunc[32]; void *SetActFunc[32]; unsigned char actID; unsigned char actIDB; unsigned char freeEnd; unsigned char unused0[1]; void *GetDmgAnimFunc; void *CalcDmgFunc; void *FrameLastFunc; void *DramaStartFunc; void *DramaEndFunc; int unused[2]; };
#endif
#ifndef PROTO_DW_627041_FIELDS
#define PROTO_DW_627041_FIELDS
struct dw_627041_fields { struct dw_626529_fields *lpPad; char L3H; char L3V; char R3H; char R3V; unsigned int unused[2]; };
#endif
#ifndef PROTO_DW_620557_FIELDS
#define PROTO_DW_620557_FIELDS
struct dw_620557_fields { struct dw_634074_fields func; struct dw_627041_fields key; float InitPos[4]; float DstPos[4]; float moveRange; float moveAngle; unsigned char bDash; unsigned char Rebirth; unsigned char bHitOff; unsigned char bDead; unsigned short stayTimer; unsigned short walkTimer; unsigned short approachTimer; unsigned short ClingDmgMyAnim; struct dw_616170_fields *lpCling; int attackOff; short RebirthTimer; unsigned short PauseTime; unsigned char bWeak; unsigned char UseSfxHdlNum; unsigned char bFired; unsigned char bFree; float rollAng; unsigned short lifecut; unsigned short noDamage; short DisableSearch; short GuardFrame; int SfxHdl[8]; int SeHdl[8]; struct dw_616170_fields *lpP019; unsigned char lifecutscl; unsigned char captureLock; unsigned char ClingPos; unsigned char ClingFree; unsigned char NoSave; unsigned char FreeDamage; unsigned char bEraseDisable; unsigned char NoFloorDeadTimer; unsigned char bNoFloorDeadDisable; unsigned char AppearTypeAlpha; unsigned char unused0[2]; float PowerScl; int MaxHp; int ItemId; float SclLimit; };
#endif
#ifndef PROTO_DW_633758_FIELDS
#define PROTO_DW_633758_FIELDS

#endif
#ifndef PROTO_DW_632134_FIELDS
#define PROTO_DW_632134_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_616170_FIELDS_ATTACKNO_A9B89A80_DEFINED
#define DCOMP_OFF_STRUCT_DW_616170_FIELDS_ATTACKNO_A9B89A80_DEFINED
enum { DCOMP_OFF_STRUCT_DW_616170_FIELDS_ATTACKNO_A9B89A80 = (int)&(((struct dw_616170_fields *)0)->AttackNo) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_616170_FIELDS_INDEXANIM_25BEDBB1_DEFINED
#define DCOMP_OFF_STRUCT_DW_616170_FIELDS_INDEXANIM_25BEDBB1_DEFINED
enum { DCOMP_OFF_STRUCT_DW_616170_FIELDS_INDEXANIM_25BEDBB1 = (int)&(((struct dw_616170_fields *)0)->IndexAnim) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_616170_FIELDS_MAPHITOFF_21A8EBE0_DEFINED
#define DCOMP_OFF_STRUCT_DW_616170_FIELDS_MAPHITOFF_21A8EBE0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_616170_FIELDS_MAPHITOFF_21A8EBE0 = (int)&(((struct dw_616170_fields *)0)->MapHitOff) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPANIMCTRL_E8BE541D_DEFINED
#define DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPANIMCTRL_E8BE541D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPANIMCTRL_E8BE541D = (int)&(((struct dw_616170_fields *)0)->lpAnimCtrl) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPCTRLST_903BA429_DEFINED
#define DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPCTRLST_903BA429_DEFINED
enum { DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPCTRLST_903BA429 = (int)&(((struct dw_616170_fields *)0)->lpCtrlSt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPMDLDATA_4C9B1C04_DEFINED
#define DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPMDLDATA_4C9B1C04_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_620557_FIELDS_CLINGFREE_D779AB71_DEFINED
#define DCOMP_OFF_STRUCT_DW_620557_FIELDS_CLINGFREE_D779AB71_DEFINED
enum { DCOMP_OFF_STRUCT_DW_620557_FIELDS_CLINGFREE_D779AB71 = (int)&(((struct dw_620557_fields *)0)->ClingFree) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_620557_FIELDS_LPCLING_F810E45D_DEFINED
#define DCOMP_OFF_STRUCT_DW_620557_FIELDS_LPCLING_F810E45D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_620557_FIELDS_LPCLING_F810E45D = (int)&(((struct dw_620557_fields *)0)->lpCling) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_632134_FIELDS_LPPRM_291B2B52_DEFINED
#define DCOMP_OFF_STRUCT_DW_632134_FIELDS_LPPRM_291B2B52_DEFINED

#endif
static inline u32 EneActAttack__inl0(u8 *a1_2) {
    u32 v1;
    u32 v0;

    v0 = 0x49;
    v1 = *(s16 *)(a1_2 + 0x104);
    if (v1 == v0) {
        v0 = 1;
    } else {
        v1 = *(s32 *)(a1_2 + 0x148);
        v0 = 8;
        v1 = *(u8 *)((v1 + 0x100));
        if (v1 == v0) {
            v0 = 1;
        } else {
            v0 = 0;
        }
    }
    return v0;
}

static inline u32 EneActAttack__inl1(u8 *a1_2) {
    u32 v1;
    u32 v0;

    v0 = 0x4f;
    v1 = *(s16 *)(a1_2 + 0x104);
    if (v1 == v0) {
        v0 = 1;
    } else {
        v1 = *(s32 *)(a1_2 + 0x148);
        v0 = 8;
        v1 = *(u8 *)((v1 + 0x100));
        if (v1 == v0) {
            v0 = 1;
        } else {
            v0 = 0;
        }
    }
    return v0;
}

static inline u32 EneActAttack__inl2(u32 v1, u8 *a1_2) {
    u32 v0;

    v0 = *(s16 *)(a1_2 + 0x104);
    if (v0 == v1) {
        v0 = 1;
    } else {
        v1 = *(s32 *)(a1_2 + 0x148);
        v0 = 8;
        v1 = *(u8 *)((v1 + 0x100));
        if (v1 == v0) {
            v0 = 1;
        } else {
            v0 = 0;
        }
    }
    return v0;
}

static inline u32 EneActAttack__inl3(u32 v1, u8 *a1_2) {
    u32 v0;

    v0 = *(s16 *)((v1 + 0x104));
    if (v0 == (u32)(s32)a1_2) {
        v0 = 1;
    } else {
        v1 = *(s32 *)((v1 + 0x148));
        v0 = 8;
        v1 = *(u8 *)((v1 + 0x100));
        if (v1 == v0) {
            v0 = 1;
        } else {
            v0 = 0;
        }
    }
    return v0;
}


/* EneActWalk @ 0x1629D0 .. 0x162B68 (0x198 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x162a00
 *   fpu: mtc1 reinterprets v1 at 0x162a18
 *   fpu: float literal 0x41200000 at 0x162a30
 *   delay: addiu at 0x162a58 writes a register its branch at 0x162a54 reads
 *   delay: addiu at 0x162a6c writes a register its branch at 0x162a68 reads
 *   delay: addiu at 0x162a80 writes a register its branch at 0x162a7c reads
 *   fpu: float literal 0x3c8ef34d at 0x162b34
 *   cfg: kept goto: 0x162b08 -> .L00162B50
 */

extern void EneCorrectWalkAngle();

/* EneActAppear @ 0x162CA0 .. 0x162D40 (0xa0 bytes, frame 0x40) */

extern void EneAppearProc(void *, void *);

/* EneActInit @ 0x162D70 .. 0x162EB4 (0x144 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 */

extern void EneActAttack(void *, void *);
extern void EneActDead(void *, void *);
extern signed int GetEneDamageAnim(void *);
extern signed int CalcEneDamage(void *);


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void EneActInit(int a0 , void *a1 );
void EneActPlay(void *a0 , void *a1 );
static void EneActNone(void);
static void EneActAppear(void *a0 , void *a1 );
static void EneActFree(void *a0 , void *a1 );
static void EneActStay(void *a0 , void *a1 );
static void EneActWalk(void *a0 , void *a1 );
static void EneActAttack(void *a0 , void *a1 );
static void EneActDamage(void *a0 , void *a1 );
void EneActDead(void *actor, void *work);
static void EneActRebirth(void *a0 , void *a1 );
static void EneActGuard(void *a0 , void *a1 );
static void SetEneNone(void);
static void SetEneStay(void *a0 , void *a1 , unsigned short a2 );
static void SetEneWalk(void *a0 , void *a1 , unsigned short a2 );
static void SetEneFree(void *a0 , void *a1 , unsigned short a2 );
static void SetEneDamage(void *a0 , void *a1 , unsigned short a2 );
static void SetEneDead(void *a0 , void *a1 , unsigned short a2 );
static void SetEneRebirth(void *a0 , void *a1 , unsigned short a2 );
static void SetEneGuard(void *a0 , void *a1 , unsigned short a2 );
signed int SetEneClingAndPush(void *a0 , void *a1 );
void SetEneFrontClingPos(void *a0 , void *a1 );
void SetEneBackClingPos(void *a0 , void *a1 );
void SetEneClingOut(void *a0 , void *a1 , unsigned short a2 );
signed int CheckEneClingOut(int a0 , void *a1 , unsigned short a2 );


void EneActInit(int a0 /* r4 */, void *a1 /* r5 */) {
    u32 i;
    u32 *a3;
    u8 *a2;
    u32 v1;

    for (i = 0; i < 32; i++) {
        ((void (**)(void))a1)[0x20 + i] = EneActNone;
        ((void (**)(void))a1)[0x40 + i] = SetEneNone;
    }
    a0 = (int)EneActAppear;
    v1 = (u32)EneActFree;
    *(u32 *)(((u8 *)a1 + 0x94)) = (u32)EneActAppear;
    *(u32 *)(((u8 *)a1 + 0x98)) = (u32)EneActFree;
    a0 = (int)EneActStay;
    *(u32 *)(((u8 *)a1 + 0x80)) = (u32)EneActStay;
    v1 = (u32)EneActWalk;
    *(u32 *)(((u8 *)a1 + 0x84)) = (u32)EneActWalk;
    a0 = (int)EneActAttack;
    *(u32 *)(((u8 *)a1 + 0x88)) = (u32)EneActAttack;
    v1 = (u32)EneActDamage;
    *(u32 *)(((u8 *)a1 + 0x8c)) = (u32)EneActDamage;
    a0 = (int)EneActDead;
    *(u32 *)(((u8 *)a1 + 0x90)) = (u32)EneActDead;
    v1 = (u32)EneActRebirth;
    *(u32 *)(((u8 *)a1 + 0x9c)) = (u32)EneActRebirth;
    a0 = (int)EneActGuard;
    *(u32 *)(((u8 *)a1 + 0xa4)) = (u32)EneActGuard;
    v1 = (u32)GetEneDamageAnim;
    *(u32 *)(((u8 *)a1 + 0x184)) = (u32)GetEneDamageAnim;
    a0 = (int)CalcEneDamage;
    *(u32 *)(((u8 *)a1 + 0x188)) = (u32)CalcEneDamage;
    v1 = (u32)SetEneStay;
    *(u32 *)(((u8 *)a1 + 0x100)) = (u32)SetEneStay;
    a0 = (int)SetEneWalk;
    *(u32 *)(((u8 *)a1 + 0x104)) = (u32)SetEneWalk;
    v1 = (u32)SetEneFree;
    *(u32 *)(((u8 *)a1 + 0x118)) = (u32)SetEneFree;
    a0 = (int)SetEneDamage;
    *(u32 *)(((u8 *)a1 + 0x10c)) = (u32)SetEneDamage;
    v1 = (u32)SetEneDead;
    *(u32 *)(((u8 *)a1 + 0x110)) = (u32)SetEneDead;
    a0 = (int)SetEneRebirth;
    v1 = (u32)SetEneGuard;
    *(u32 *)(((u8 *)a1 + 0x11c)) = (u32)SetEneRebirth;
    *(u32 *)(((u8 *)a1 + 0x124)) = (u32)SetEneGuard;
    return;
}

/* EneActPlay @ 0x162D50 .. 0x162D68 (0x18 bytes) */
/*
 * dcomp notes:
 *   tail: jr v0 at 0x162d60 tail-calls through a pointer
 *   a0 takes slot 0 only because of the ABI order
 */

void EneActPlay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 v0;

    v0 = *(u8 *)(((u8 *)a1 + 0x180));
    v0 = v0 << 2;
    v0 = (s32)((u8 *)v0 + (u32)(a1));
    v0 = *(s32 *)((v0 + 0x80));
    ((void (*)(void *, void *))(s32)v0)(a0, a1);
    return;
}

/* EneActNone @ 0x162D40 .. 0x162D48 (0x8 bytes) */

static void EneActNone(void) {
    return;
}

static void EneActAppear(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u32 *s1;
    u32 s0;
    u32 v0;

    s2 = (u8 *)a0;
    s0 = *(s32 *)(((u8 *)a0 + 0x100));
    s1 = (u32 *)a1;
    EneAppearProc(a0, a1);
    v0 = CheckAnimEndFrame((void *)s0);
    if (v0 != 0) {
        v0 = *(s32 *)(s2 + 0x1b4);
        if (v0 != 0 && (u32)*(u8 *)(s2 + 0x128) != (u32)*(u8 *)((v0 + 0x128))) {
            v0 = *(s32 *)(((u8 *)s1 + 0x100));
            ((void (*)(u32, u32, s32))(s32)v0)((u32)s2, (u32)(u32 *)s1, 2);
        } else {
            v0 = *(s32 *)(((u8 *)s1 + 0x100));
            ((void (*)(u32, u32, u32))(s32)v0)((u32)s2, (u32)(u32 *)s1, 0);
        }
    }
    return;
}

/* EneActFree @ 0x162C30 .. 0x162C94 (0x64 bytes, frame 0x30) */



static void EneActFree(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 *s1;
    u8 *s0;
    u32 v1;
    s32 v0;

    s1 = (u32 *)a0;
    v1 = *(u8 *)(((u8 *)a1 + 0x182));
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x100));
    s0 = (u8 *)a1;
    if (v1 != 0) {
        v0 = CheckAnimEndFrame(a0);
        if ((u32)v0 != 0) {
            *(u8 *)(((u8 *)s0 + 0x182)) = 0;
            v0 = *(s32 *)(((u8 *)s0 + 0x104));
            ((void (*)(u32, u32, s32))v0)((u32)s1, (u32)(u8 *)s0, 0xb);
        }
    }
    return;
}

/* EneActStay @ 0x162B70 .. 0x162C24 (0xb4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x162ba0 writes a register its branch at 0x162b9c reads
 */



static void EneActStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 *s0;
    s32 v1;
    s32 v0;
    void *a0_s1; // a0

    v1 = 3;
    s0 = (u32 *)a1;
    a1 = (void *)*(s16 *)(((u8 *)a0 + 0x104));
    a0_s1 = (void *)*(s32 *)(((u8 *)a0 + 0x100));
    switch ((u32)a1) {
    case 14:
    case 1:
        v0 = CheckAnimEndFrame(a0_s1);
        if ((u32)v0 == 0) {
            break;
        }
        v0 = *(s32 *)(((u8 *)s0 + 0x100));
        a0_s1 = a0;
        a1 = (void *)s0;
        ((void (*)(u32, u32, s32))v0)((u32)a0_s1, (u32)a1, 2);
        break;
    case 3:
        v0 = CheckAnimEndFrame(a0_s1);
        if ((u32)v0 == 0) {
            break;
        }
        v0 = *(s32 *)(((u8 *)s0 + 0x100));
        a0_s1 = a0;
        a1 = (void *)s0;
        ((void (*)(u32, u32, u32))v0)((u32)a0_s1, (u32)a1, 0);
    }
    return;
}

static void EneActWalk(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *a0_bytes; // s1
    s32 a2;
    float f0;
    float f20;
    void *a0_s1; // a0
    s32 v1;
    u32 v0;
    void *a1_2;
    u8 *s0;

    a0_bytes = (u8 *)a0;
    a0_s1 = (void *)*(s32 *)(a0_bytes + 0x100);
    s0 = (u8 *)a1;
    v1 = *(s16 *)(a0_bytes + 0x104);
    f0 = 10.0f;
    f20 = ((float)(float)(u32)*(u16 *)((*(s32 *)((*(s32 *)(a0_bytes + 0xc) + 0x4c)) + 0x1a)) /
        10.0f);
    v0 = 0x1d;
    switch ((u32)v1) {
    case 16:
        v0 = CheckAnimEndFrame(a0_s1);
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)(s0 + 0x104);
        a0_s1 = (void *)a0_bytes;
        a1_2 = (void *)s0;
        a2 = 0x11;
        ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_s1, (u32)a1_2, a2);
        break;
    case 17:
        v0 = (u32)(*(u16 *)(s0 + 0x1e0)) + 1;
        *(u16 *)(s0 + 0x1e0) = v0;
        break;
    case 5:
        v0 = CheckAnimEndFrame(a0_s1);
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)(s0 + 0x104);
        a0_s1 = (void *)a0_bytes;
        a1_2 = (void *)s0;
        a2 = 0xa;
        ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_s1, (u32)a1_2, a2);
        break;
    case 18:
    case 19:
    case 28:
    case 29:
        f0 = Math_GotoAngle(*(float *)(a0_bytes + 0x34), *(float *)(a0_bytes + 0x198), *(float
            *)(s0 + 0x1f4));
        *(f32 *)(a0_bytes + 0x34) = f0;
        return;
    }
    EneCorrectWalkAngle((void *)a0_bytes, (u8 *)s0);
    f0 = 0.0174499992f;
    f0 = Math_GotoAngle(*(float *)(a0_bytes + 0x34), *(float *)(a0_bytes + 0x198), (0.0174499992f *
        f20));
    *(f32 *)(a0_bytes + 0x34) = f0;
    return;
}

static void EneActAttack(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *a0_bytes; // s3
    s32 a2;
    u8 *s2;
    float f13;
    float f12;
    u8 *a0_s3; // a0
    u32 v1;
    float f20;
    float f1;
    u8 *s1;
    s32 hi;
    float f0;
    u32 v0;
    u8 *a1_2;
    u8 *s0;
    int rnd;
    int biterate;
    int pushrate;
    u8 *lpMyCtrl;
    u8 *lpMyPrm;

    a0_bytes = (u8 *)a0;
    a0_s3 = (u8 *)*(s32 *)(a0_bytes + DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPANIMCTRL_E8BE541D);
    v0 = *(s32 *)(a0_bytes + DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPMDLDATA_4C9B1C04);
    v1 = *(u8 *)(a0_bytes + DCOMP_OFF_STRUCT_DW_616170_FIELDS_ATTACKNO_A9B89A80);
    s1 = (u8 *)*(s32 *)(v0 + DCOMP_OFF_STRUCT_DW_632134_FIELDS_LPPRM_291B2B52);
    v0 = v1 * 0x28;
    v0 = (s32)((u8 *)v0 + (u32)(s1));
    s2 = (u8 *)a1;
    f1 = (float)(u32)*(u16 *)((v0 + 0xaa));
    a2 = *(s16 *)(a0_bytes + DCOMP_OFF_STRUCT_DW_616170_FIELDS_INDEXANIM_25BEDBB1);
    a1_2 = (u8 *)(s32)0x6d;
    f20 = (f1 / 1e+01f);
    v1 = 0x67;
    switch ((u32)a2) {
    case 60:
        a1_2 = (u8 *)*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_620557_FIELDS_LPCLING_F810E45D);
        v0 = 0x49;
        v1 = *(s16 *)(a1_2 + DCOMP_OFF_STRUCT_DW_616170_FIELDS_INDEXANIM_25BEDBB1);
        if (v1 == v0) {
            v0 = 1;
        } else {
            v1 = *(s32 *)(a1_2 + DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPCTRLST_903BA429);
            v0 = 8;
            v1 = *(u8 *)((v1 + 0x100));
            if (v1 == v0) {
                v0 = 1;
            } else {
                v0 = 0;
            }
        }
        if (v0 != 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x3f, 0.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_620557_FIELDS_CLINGFREE_D779AB71) = 1;
            *(u8 *)(a0_bytes + DCOMP_OFF_STRUCT_DW_616170_FIELDS_MAPHITOFF_21A8EBE0) = 0;
            goto _L00162818;
        }
        v0 = CheckAnimEndFrame((void *)a0_s3);
        if (v0 == 0) {
            goto _L00162818;
        }
        a0_s3 = a0_bytes;
        a1_2 = (u8 *)(s32)0x3d;
        ChangeAnimParam((void *)a0_s3, (signed int)a1_2, 0.0f);
        goto _L00162818;
    case 61:
        a1_2 = (u8 *)*(s32 *)(s2 + 0x1e4);
        v0 = EneActAttack__inl0(a1_2);
        if (v0 != 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x3f, 0.0f);
            *(u8 *)(s2 + 0x247) = 1;
            *(u8 *)(a0_bytes + 0x132) = 0;
            goto _L00162818;
        }
        v0 = CheckAnimEndFrame((void *)a0_s3);
        if (v0 == 0) {
            goto _L00162818;
        }
        rnd = rand() % 100;
        lpMyCtrl = (u8 *)*(s32 *)(*(s32 *)(s2 + 0x1e4) + 0x148);
        biterate = *(u8 *)(s1 + 0x31);
        lpMyPrm = (u8 *)*(s32 *)(*(s32 *)(*(s32 *)(s2 + 0x1e4) + 0xc) + 0x4c);
        if (biterate == 0) {
            biterate = 0x32;
        }
        pushrate = biterate + 0x14;
        if (pushrate > 0x64) {
            pushrate = 0x64;
        }
        if (rnd < biterate) {
            v0 = *(s32 *)(s2 + 0x1e8);
            if (v0 == 0) {
                a0_s3 = a0_bytes;
                ChangeAnimParam((void *)a0_s3, 0x3e, 0.0f);
                a0_s3 = (u8 *)*(s32 *)(s2 + 0x1e4);
                a1_2 = lpMyCtrl;
                a2 = 0x48;
                SetMyDamage((void *)a0_s3, (void *)a1_2, a2);
                goto _L00162818;
            }
        }
        if (pushrate <= rnd) {
            goto _L00162818;
        }
        v1 = *(u8 *)(a0_bytes + 0x12a);
        v0 = v1 * 0x28;
        v0 = *(u8 *)((u32)&((u8 *)(s1 + 0xa6))[v0]);
        if (v0 == 0 || *(u8 *)(lpMyPrm + 0xa) == 0) {
            goto _L00162818;
        }
        a0_s3 = a0_bytes;
        ChangeAnimParam((void *)a0_s3, 0x42, 0.0f);
        a0_s3 = (u8 *)*(s32 *)(s2 + 0x1e4);
        a1_2 = lpMyCtrl;
        a2 = 0x4c;
        SetMyDamage((void *)a0_s3, (void *)a1_2, a2);
        a0_s3 = (u8 *)*(s32 *)(s2 + 0x1e4);
        a1_2 = lpMyCtrl;
        ClearMyStruggleStick(a0_s3, a1_2);
        v0 = 0x50;
        *(u16 *)(s2 + 0x1e2) = v0;
        goto _L00162818;
    case 62:
        a1_2 = (u8 *)*(s32 *)(s2 + 0x1e4);
        v0 = EneActAttack__inl0(a1_2);
        if (v0 != 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x3f, 0.0f);
            *(u8 *)(s2 + 0x247) = 1;
            *(u8 *)(a0_bytes + 0x132) = 0;
            goto _L00162818;
        }
        v0 = CheckAnimEndFrame((void *)a0_s3);
        if (v0 == 0) {
            goto _L00162818;
        }
        v0 = *(s32 *)((*(s32 *)(s2 + 0x1e4) + 0x120));
        if ((s32)v0 <= 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x42, 0.0f);
            goto _L00162818;
        }
        a0_s3 = a0_bytes;
        a1_2 = (u8 *)(s32)0x3d;
        ChangeAnimParam((void *)a0_s3, (signed int)a1_2, 0.0f);
        v0 = *(u16 *)(s1 + 0x34);
        *(u32 *)(s2 + 0x1e8) = v0;
        goto _L00162818;
    case 66:
        a1_2 = (u8 *)*(s32 *)(s2 + 0x1e4);
        v0 = EneActAttack__inl1(a1_2);
        if (v0 != 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x45, 0.0f);
            *(u8 *)(s2 + 0x247) = 1;
            *(u8 *)(a0_bytes + 0x132) = 0;
            goto _L00162818;
        }
        v0 = CheckAnimEndFrame((void *)a0_s3);
        if (v0 == 0) {
            goto _L00162818;
        }
        v0 = *(s32 *)((*(s32 *)(s2 + 0x1e4) + 0x120));
        if ((s32)v0 <= 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x44, 0.0f);
            goto _L00162818;
        }
        a0_s3 = a0_bytes;
        a1_2 = (u8 *)(s32)0x43;
        ChangeAnimParam((void *)a0_s3, (signed int)a1_2, 0.0f);
        goto _L00162818;
    case 67:
        a1_2 = (u8 *)*(s32 *)(s2 + 0x1e4);
        v0 = EneActAttack__inl1(a1_2);
        if (v0 != 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x45, 0.0f);
            *(u8 *)(s2 + 0x247) = 1;
            *(u8 *)(a0_bytes + 0x132) = 0;
            goto _L00162818;
        }
        v0 = CheckAnimEndFrame((void *)a0_s3);
        if (v0 == 0) {
            goto _L00162818;
        }
        v0 = rand();
        v1 = 0x64;
        a0_s3 = (u8 *)*(u8 *)(s1 + 0x31);
        hi = (s32)v0 % 0x64;
        v0 = *(s32 *)(s2 + 0x1e4);
        s0 = (u8 *)*(s32 *)((v0 + 0x148));
        v0 = hi;
        if ((u32)a0_s3 == 0) {
            a0_s3 = (u8 *)(s32)0x32;
        }
        if ((s32)a0_s3 <= (s32)v0) {
            goto _L00162818;
        }
        v0 = *(s32 *)(s2 + 0x1e8);
        if (v0 != 0) {
            goto _L00162818;
        }
        a0_s3 = a0_bytes;
        ChangeAnimParam((void *)a0_s3, 0x44, 0.0f);
        a0_s3 = (u8 *)*(s32 *)(s2 + 0x1e4);
        a1_2 = (u8 *)s0;
        a2 = 0x4e;
        SetMyDamage((void *)a0_s3, (void *)a1_2, a2);
        goto _L00162818;
    case 68:
        a1_2 = (u8 *)*(s32 *)(s2 + 0x1e4);
        v0 = EneActAttack__inl1(a1_2);
        if (v0 != 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x45, 0.0f);
            *(u8 *)(s2 + 0x247) = 1;
            *(u8 *)(a0_bytes + 0x132) = 0;
            goto _L00162818;
        }
        v0 = CheckAnimEndFrame((void *)a0_s3);
        if (v0 == 0) {
            goto _L00162818;
        }
        v0 = *(s32 *)((*(s32 *)(s2 + 0x1e4) + 0x120));
        if ((s32)v0 <= 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x44, 0.0f);
            goto _L00162818;
        }
        a0_s3 = a0_bytes;
        a1_2 = (u8 *)(s32)0x43;
        ChangeAnimParam((void *)a0_s3, (signed int)a1_2, 0.0f);
        v0 = *(u16 *)(s1 + 0x34);
        *(u32 *)(s2 + 0x1e8) = v0;
        goto _L00162818;
    case 100:
        a1_2 = (u8 *)*(s32 *)(s2 + 0x1e4);
        v0 = EneActAttack__inl2(v1, a1_2);
        if (v0 != 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x67, 0.0f);
            *(u8 *)(s2 + 0x247) = 1;
            *(u8 *)(a0_bytes + 0x132) = 0;
            goto _L00162818;
        }
        v0 = CheckAnimEndFrame((void *)a0_s3);
        if (v0 == 0) {
            goto _L00162818;
        }
        a0_s3 = a0_bytes;
        a1_2 = (u8 *)(s32)0x65;
        ChangeAnimParam((void *)a0_s3, (signed int)a1_2, 0.0f);
        goto _L00162818;
    case 101:
        a1_2 = (u8 *)*(s32 *)(s2 + 0x1e4);
        v0 = EneActAttack__inl2(v1, a1_2);
        if (v0 != 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x67, 0.0f);
            *(u8 *)(s2 + 0x247) = 1;
            *(u8 *)(a0_bytes + 0x132) = 0;
            goto _L00162818;
        }
        v0 = CheckAnimEndFrame((void *)a0_s3);
        if (v0 == 0) {
            goto _L00162818;
        }
        rnd = rand() % 100;
        lpMyCtrl = (u8 *)*(s32 *)(*(s32 *)(s2 + 0x1e4) + 0x148);
        biterate = *(u8 *)(s1 + 0x31);
        lpMyPrm = (u8 *)*(s32 *)(*(s32 *)(*(s32 *)(s2 + 0x1e4) + 0xc) + 0x4c);
        if (biterate == 0) {
            biterate = 0x32;
        }
        pushrate = biterate + 0x14;
        if (pushrate > 0x64) {
            pushrate = 0x64;
        }
        if (rnd < biterate) {
            v0 = *(s32 *)(s2 + 0x1e8);
            if (v0 == 0) {
                a0_s3 = a0_bytes;
                ChangeAnimParam((void *)a0_s3, 0x66, 0.0f);
                a0_s3 = (u8 *)*(s32 *)(s2 + 0x1e4);
                a1_2 = lpMyCtrl;
                a2 = 0x66;
                SetMyDamage((void *)a0_s3, (void *)a1_2, a2);
                goto _L00162818;
            }
        }
        if (pushrate <= rnd) {
            goto _L00162818;
        }
        v1 = *(u8 *)(a0_bytes + 0x12a);
        v0 = v1 * 0x28;
        v0 = *(u8 *)((u32)&((u8 *)(s1 + 0xa6))[v0]);
        if (v0 == 0 || *(u8 *)(lpMyPrm + 0xa) == 0) {
            goto _L00162818;
        }
        a0_s3 = a0_bytes;
        ChangeAnimParam((void *)a0_s3, 0x6a, 0.0f);
        a0_s3 = (u8 *)*(s32 *)(s2 + 0x1e4);
        a1_2 = lpMyCtrl;
        a2 = 0x6a;
        SetMyDamage((void *)a0_s3, (void *)a1_2, a2);
        a0_s3 = (u8 *)*(s32 *)(s2 + 0x1e4);
        a1_2 = lpMyCtrl;
        ClearMyStruggleStick(a0_s3, a1_2);
        v0 = 0x6e;
        *(u16 *)(s2 + 0x1e2) = v0;
        goto _L00162818;
    case 102:
        a1_2 = (u8 *)*(s32 *)(s2 + 0x1e4);
        v0 = EneActAttack__inl2(v1, a1_2);
        if (v0 != 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x67, 0.0f);
            *(u8 *)(s2 + 0x247) = 1;
            *(u8 *)(a0_bytes + 0x132) = 0;
            goto _L00162818;
        }
        v0 = CheckAnimEndFrame((void *)a0_s3);
        if (v0 == 0) {
            goto _L00162818;
        }
        v0 = *(s32 *)((*(s32 *)(s2 + 0x1e4) + 0x120));
        if ((s32)v0 <= 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x6a, 0.0f);
            goto _L00162818;
        }
        a0_s3 = a0_bytes;
        a1_2 = (u8 *)(s32)0x65;
        ChangeAnimParam((void *)a0_s3, (signed int)a1_2, 0.0f);
        v0 = *(u16 *)(s1 + 0x34);
        *(u32 *)(s2 + 0x1e8) = v0;
        goto _L00162818;
    case 106:
        v1 = *(s32 *)(s2 + 0x1e4);
        v0 = EneActAttack__inl3(v1, a1_2);
        if (v0 != 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x6d, 0.0f);
            *(u8 *)(s2 + 0x247) = 1;
            *(u8 *)(a0_bytes + 0x132) = 0;
            goto _L00162818;
        }
        v0 = CheckAnimEndFrame((void *)a0_s3);
        if (v0 == 0) {
            goto _L00162818;
        }
        v0 = *(s32 *)((*(s32 *)(s2 + 0x1e4) + 0x120));
        if ((s32)v0 <= 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x6c, 0.0f);
            goto _L00162818;
        }
        a0_s3 = a0_bytes;
        a1_2 = (u8 *)(s32)0x6b;
        ChangeAnimParam((void *)a0_s3, (signed int)a1_2, 0.0f);
        goto _L00162818;
    case 107:
        v1 = *(s32 *)(s2 + 0x1e4);
        v0 = EneActAttack__inl3(v1, a1_2);
        if (v0 != 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x6d, 0.0f);
            *(u8 *)(s2 + 0x247) = 1;
            *(u8 *)(a0_bytes + 0x132) = 0;
            goto _L00162818;
        }
        v0 = CheckAnimEndFrame((void *)a0_s3);
        if (v0 == 0) {
            goto _L00162818;
        }
        v0 = rand();
        v1 = 0x64;
        a0_s3 = (u8 *)*(u8 *)(s1 + 0x31);
        hi = (s32)v0 % 0x64;
        v0 = *(s32 *)(s2 + 0x1e4);
        s0 = (u8 *)*(s32 *)((v0 + 0x148));
        v0 = hi;
        if ((u32)a0_s3 == 0) {
            a0_s3 = (u8 *)(s32)0x32;
        }
        if ((s32)a0_s3 <= (s32)v0) {
            goto _L00162818;
        }
        v0 = *(s32 *)(s2 + 0x1e8);
        if (v0 != 0) {
            goto _L00162818;
        }
        a0_s3 = a0_bytes;
        ChangeAnimParam((void *)a0_s3, 0x6c, 0.0f);
        a0_s3 = (u8 *)*(s32 *)(s2 + 0x1e4);
        a1_2 = (u8 *)s0;
        a2 = 0x6c;
        SetMyDamage((void *)a0_s3, (void *)a1_2, a2);
        goto _L00162818;
    case 108:
        v1 = *(s32 *)(s2 + 0x1e4);
        v0 = EneActAttack__inl3(v1, a1_2);
        if (v0 != 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x6d, 0.0f);
            *(u8 *)(s2 + 0x247) = 1;
            *(u8 *)(a0_bytes + 0x132) = 0;
            goto _L00162818;
        }
        v0 = CheckAnimEndFrame((void *)a0_s3);
        if (v0 == 0) {
            goto _L00162818;
        }
        v0 = *(s32 *)((*(s32 *)(s2 + 0x1e4) + 0x120));
        if ((s32)v0 <= 0) {
            a0_s3 = a0_bytes;
            ChangeAnimParam((void *)a0_s3, 0x6c, 0.0f);
            goto _L00162818;
        }
        a0_s3 = a0_bytes;
        a1_2 = (u8 *)(s32)0x6b;
        ChangeAnimParam((void *)a0_s3, (signed int)a1_2, 0.0f);
        v0 = *(u16 *)(s1 + 0x34);
        *(u32 *)(s2 + 0x1e8) = v0;
        goto _L00162818;
    case 63:
    case 69:
    case 103:
    case 109:
    default:
        v0 = CheckAnimEndFrame((void *)a0_s3);
        if (v0 == 0) {
            goto _L00162818;
        }
        *(u8 *)(a0_bytes + 0x130) = 0;
        *(u8 *)(a0_bytes + 0x131) = 0;
        *(u32 *)(s2 + 0x1e4) = 0;
        v1 = *(u8 *)(a0_bytes + 0x12a);
        v0 = v1 * 0x28;
        v0 = (s32)((u8 *)v0 + (u32)(s1));
        v0 = *(u16 *)((v0 + 0xb2));
        *(u32 *)(s2 + 0x1e8) = v0;
        v0 = *(s32 *)(a0_bytes + 0x1b4);
        if (v0 != 0 && (u32)*(s32 *)(s2 + 0x1e8) != 0) {
            a0_s3 = a0_bytes;
            a1_2 = s2;
            SetEneAttackOff((void *)a0_s3, (void *)a1_2);
            break;
        } else {
            v0 = *(s32 *)(s2 + 0x100);
            a0_s3 = a0_bytes;
            a1_2 = s2;
            a2 = 2;
            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_s3, (u32)a1_2, a2);
        }
    }
    *(f32 *)(a0_bytes + 0x198) = *(float *)(a0_bytes + 0x34);
    _L00162818:;
    v1 = *(s32 *)(s2 + 0x1e4);
    if (v1 != 0) {
        v0 = *(u8 *)(s2 + 0x246);
        if (v0 == 0) {
            v0 = *(u8 *)(s2 + 0x247);
            if (v0 == 0) {
                v0 = 0x3e4c0000;
                a1_2 = (u8 *)(s32)(v1 + 0x20);
                v1 = 0x3e4c0000 | 0xcccd;
                Math_GotoVector2((float *)(a0_bytes + 0x20), (float *)a1_2, (f32)0.2f, (f32)0.01f,
                    0.05f);
            }
            v1 = *(s32 *)(s2 + 0x1e4);
            if ((3.1415927f + (3.1415927f + *(float *)((v1 + 0x34)))) >= 0.0f) {
                f0 = ((3.1415927f + *(float *)((v1 + 0x34))) - (6.2831855f *
                    (float)((float)(s32)((3.1415927f + (3.1415927f + *(float *)((v1 + 0x34)))) /
                    6.2831855f))));
            } else {
                f1 = 6.2831855f;
                f0 = (f1 + ((3.1415927f + *(float *)((v1 + 0x34))) - (f1 *
                    (float)((float)(s32)((3.1415927f + (3.1415927f + *(float *)((v1 + 0x34)))) /
                    f1)))));
            }
            *(f32 *)(a0_bytes + 0x198) = f0;
            v1 = *(s32 *)(s2 + 0x1e4);
            f12 = *(float *)((v1 + 0x34));
            f13 = (3.1415927f + *(float *)(a0_bytes + 0x198));
            f0 = Math_GotoAngle(f12, f13, 0.008725f);
            v0 = *(s32 *)(s2 + 0x1e4);
            *(f32 *)((v0 + 0x34)) = f0;
        } else {
            v0 = *(u8 *)(s2 + 0x247);
            if (v0 == 0) {
                v0 = 0x3e4c0000;
                a1_2 = (u8 *)(s32)(v1 + 0x20);
                v1 = 0x3e4c0000 | 0xcccd;
                Math_GotoVector2((float *)(a0_bytes + 0x20), (float *)a1_2, (f32)0.2f, (f32)0.01f,
                    0.05f);
            }
            v1 = *(s32 *)(s2 + 0x1e4);
            *(f32 *)(a0_bytes + 0x198) = *(float *)((v1 + 0x34));
            v0 = *(s32 *)(s2 + 0x1e4);
            f12 = *(float *)((v0 + 0x34));
            f13 = *(float *)(a0_bytes + 0x198);
            f0 = Math_GotoAngle(f12, f13, 0.008725f);
            v0 = *(s32 *)(s2 + 0x1e4);
            *(f32 *)((v0 + 0x34)) = f0;
        }
    }
    f12 = *(float *)(a0_bytes + 0x34);
    f13 = *(float *)(a0_bytes + 0x198);
    f0 = Math_GotoAngle(f12, f13, (0.01745f * f20));
    *(f32 *)(a0_bytes + 0x34) = f0;
    return;
}

static void EneActDamage(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    u32 v0;
    u32 s0;
    s32 v1;
    u32 a2;

    s2 = (u8 *)a0;
    v0 = *(u16 *)(((u8 *)a1 + 0x1ee));
    s0 = *(s32 *)(((u8 *)a0 + 0x100));
    s1 = (u8 *)a1;
    if (v0 != 0) {
        a0 = (void *)(s32)s0;
        v0 = CheckAnimNumFrame(a0, 23.0f);
        if (v0 != 0) {
            v0 = 2;
            *(u16 *)(((u8 *)s2 + 0x106)) = v0;
            v0 = *(u16 *)(((u8 *)s1 + 0x1ee));
            v0 = v0 + -1;
            *(u16 *)(((u8 *)s1 + 0x1ee)) = v0;
        }
    } else {
        *(u16 *)(((u8 *)s2 + 0x106)) = 0;
    }
    a0 = (void *)(s32)s0;
    v0 = CheckAnimEndFrame(a0);
    if (v0 != 0) {
        v1 = *(s16 *)(((u8 *)s2 + 0x104));
        v0 = 0x20;
        switch ((u32)v1) {
        case 30:
        case 32:
            v0 = v1 + 1;
            a2 = (u16)v0;
            a0 = (void *)s2;
            v0 = *(s32 *)(((u8 *)s1 + 0x10c));
            a1 = (void *)s1;
            ((void (*)(u32, u32, u16))(s32)v0)((u32)a0, (u32)a1, a2);
            return;
        }
        v0 = *(s32 *)(((u8 *)s2 + 0x1b4));
        if (v0 != 0) {
            v0 = *(s32 *)(((u8 *)s1 + 0x104));
            a0 = (void *)s2;
            a1 = (void *)s1;
            a2 = 0xb;
            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0, (u32)a1, a2);
        } else {
            v0 = *(s32 *)(((u8 *)s1 + 0x100));
            a0 = (void *)s2;
            a1 = (void *)s1;
            ((void (*)(u32, u32, u32))(s32)v0)((u32)a0, (u32)a1, 0);
        }
    }
    return;
}
void EneActDead(void *actor, void *work) {
    u8 *owner;
    u8 *data;
    u8 *anim;
    u16 *kind;
    owner = actor;
    data = work;
    anim = *(u8 **)((u8 *)actor + 0x100);
    kind = *(u16 **)(*(u8 **)((u8 *)actor + 0xc) + 0x4c);
    if (owner[0x128] == 1) {
        int slot = ((int (*)[2])EneAuraSfx)[*kind][0];
        if (slot != -1 && ((int *)(data + 0x200))[slot] != -1) {
            SFX_Delete(((int *)(data + 0x200))[slot], 0);
            ((int *)(data + 0x200))[((int (*)[2])EneAuraSfx)[*kind][0]] = -1;
        }
    }
    if (*(u16 *)(data + 0x1ee)) {
        if (CheckAnimNumFrame(anim, 23.0f)) {
            *(u16 *)(owner + 0x106) = 2;
            (*(u16 *)(data + 0x1ee))--;
        }
    } else *(u16 *)(owner + 0x106) = 0;
    switch (*(s16 *)(owner + 0x104)) {
    case 30:
        if (!CheckAnimEndFrame(anim)) goto finish;
        ((void (*)(void *, void *, int))*(u32 *)(data + 0x110))(owner, data, 42);
        return;
    case 32:
        if (!CheckAnimEndFrame(anim)) goto finish;
        ((void (*)(void *, void *, int))*(u32 *)(data + 0x110))(owner, data, 43);
        return;
    default:
        if (!anim) goto dead;
        if ((!owner[0x128] || data[0x1f3]) && *(float *)(anim + 0xc) - 50.0f <= *(float *)anim) {
            float alpha = *(float *)(owner + 0x10c);
            if (alpha >= 0.04f) *(float *)(owner + 0x10c) = alpha - 0.02f;
            else *(u32 *)(owner + 0x10c) = 0;
        }
    }
    if (!CheckAnimEndFrame(anim)) goto finish;
    if (!owner[0x128] || data[0x1f3]) {
        EneDeadProc(owner, data);
        return;
    }
    EneDeadProc(owner, data);
    return;
    dead:
    EneDeadProc(owner, data);
    finish:
    return;
}

static void EneActRebirth(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    u32 s0;
    u32 v1;
    float f0;
    u32 v0;
    void *a0_2;
    void *a1_2;

    s2 = (u8 *)a0;
    v1 = *(u16 *)(((u8 *)a1 + 0x1ee));
    s0 = *(s32 *)(((u8 *)a0 + 0x100));
    s1 = (u8 *)a1;
    if (v1 != 0) {
        v0 = CheckAnimNumFrame((void *)s0, 23.0f);
        v1 = 2;
        if (v0 != 0) {
            *(u16 *)(s2 + 0x106) = v1;
            v1 = *(u16 *)(s1 + 0x1ee);
            *(u16 *)(s1 + 0x1ee) = v1 + -1;
        }
    } else {
        *(u16 *)(s2 + 0x106) = 0;
    }
    a0_2 = (void *)*(s16 *)(s2 + 0x104);
    v1 = 0x2f;
    switch ((u32)a0_2) {
    case 31:
    case 33:
    case 36:
    case 35:
        v0 = CheckAnimEndFrame((void *)s0);
        if (v0 == 0) {
            break;
        }
        f0 = 0.25f;
        a0_2 = (void *)s2;
        a1_2 = (void *)s1;
        v0 = ((s32)(0.25f * (float)(float)((float)*(s32 *)(s1 + 0x254))));
        *(u32 *)(s2 + 0x120) = v0;
        v0 = *(s32 *)(s1 + 0x100);
        ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, 2);
        break;
    case 45:
    case 46:
    case 48:
    case 47:
        v1 = 1;
        *(u8 *)(s2 + 0x130) = v1;
        *(u8 *)(s2 + 0x131) = v1;
        *(u8 *)(s2 + 0x132) = v1;
        break;
    default:
        v0 = CheckAnimEndFrame((void *)s0);
        v1 = 1;
        if (v0 == 0) {
            break;
        }
        *(u8 *)(s2 + 0x130) = v1;
        *(u8 *)(s2 + 0x131) = v1;
        *(u8 *)(s2 + 0x132) = v1;
    }
    return;
}

static void EneActGuard(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u8 *s0;
    s32 a2;
    u32 v1;
    s32 v0;
    float f12;

    s1 = (u8 *)a1;
    s0 = (u8 *)a0;
    a1 = (void *)(s32)0x57;
    a2 = *(s16 *)(s0 + 0x104);
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x100));
    switch ((u32)a2) {
    case 85:
        v0 = CheckAnimEndFrame(a0);
        if ((u32)v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s0;
        a1 = (void *)(s32)0x56;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        break;
    case 86:
        v1 = *(s16 *)(s1 + 0x1fe);
        v1 = v1 + -1;
        *(u16 *)(s1 + 0x1fe) = v1;
        v1 = (s16)v1;
        if ((s32)v1 > 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s0;
        *(u16 *)(s1 + 0x1fe) = 0;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        break;
    case 87:
        v0 = CheckAnimEndFrame(a0);
        if ((u32)v0 == 0) {
            break;
        }
        v0 = *(s32 *)(s1 + 0x100);
        a0 = (void *)s0;
        a1 = (void *)s1;
        a2 = 2;
        ((void (*)(u32, u32, s32))v0)((u32)a0, (u32)a1, a2);
    }
    return;
}

/* SetEneNone @ 0x161610 .. 0x161618 (0x8 bytes) */

static void SetEneNone(void) {
    return;
}

/* SetEneStay @ 0x161560 .. 0x161604 (0xa4 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1615d4
 */

static void SetEneStay(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    u16 s2;
    u16 s1;
    u16 s0;
    void *a1_value; // a1
    u32 v0;

    v0 = 0xe;
    s2 = a2;
    s1 = a2;
    *(u8 *)(((u8 *)a1 + 0x180)) = 0;
    s0 = s1;
    if ((u32)s1 == v0) {
        v0 = CheckAnimParam(a0, s1);
        if (v0 == 0) {
            s1 = 0;
        }
    }
    v0 = 1;
    a1_value = (void *)s2;
    if ((u32)s0 == v0) {
        v0 = CheckAnimParam((void *)a0, (signed int)a1_value);
        if (v0 == 0) {
            s1 = 2;
        }
    }
    ChangeAnimParam((void *)a0, s1, 0.0f);
    *(u16 *)(((u8 *)a1 + 0x1dc)) = 0;
    return;
}

static void SetEneWalk(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    u32 s2;
    u8 *s1;
    u32 v0;
    u16 s0;

    v0 = 5;
    s2 = (u32)a0;
    s1 = (u8 *)a1;
    s0 = a2;
    *(u8 *)(((u8 *)a1 + 0x180)) = 1;
    if ((u32)s0 == v0) {
        v0 = CheckAnimParam(a0, s0);
        if (v0 == 0) {
            s0 = 0xa;
        }
    }
    ChangeAnimParam((void *)s2, s0, 0.0f);
    *(u16 *)(((u8 *)s1 + 0x1de)) = 0;
    return;
}

/* SetEneFree @ 0x1614A0 .. 0x1614D8 (0x38 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x1614ac
 *   a0 forwarded to ChangeAnimParam
 */



static void SetEneFree(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    float f12;
    u8 *s0;

    f12 = ({ float native_result_0; __asm__("mtc1 %1,%0" : "=f"(native_result_0) : "r"((u32)0));
        native_result_0; });
    s0 = (u8 *)a1;
    *(u8 *)(((u8 *)a1 + 0x180)) = 6;
    a1 = (void *)(u16)a2;
    ChangeAnimParam(a0, (signed int)a1, f12);
    *(u8 *)(((u8 *)s0 + 0x182)) = 0;
    return;
}

/* SetEneDamage @ 0x161480 .. 0x161498 (0x18 bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x161488
 *   tail: j ChangeAnimParam at 0x161490 leaves the function
 *   a0 forwarded to ChangeAnimParam
 */



static void SetEneDamage(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    *(u8 *)(((u8 *)a1 + 0x180)) = 3;
    a1 = (void *)(u16)a2;
    ChangeAnimParam(a0, (signed int)a1, (float)({ float native_result_0; __asm__("mtc1 %1,%0" :
        "=f"(native_result_0) : "r"((u32)0)); native_result_0; }));
    return;
}

/* SetEneDead @ 0x161460 .. 0x161478 (0x18 bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x161468
 *   tail: j ChangeAnimParam at 0x161470 leaves the function
 *   a0 forwarded to ChangeAnimParam
 */



static void SetEneDead(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    *(u8 *)(((u8 *)a1 + 0x180)) = 4;
    a1 = (void *)(u16)a2;
    ChangeAnimParam(a0, (signed int)a1, (float)({ float native_result_0; __asm__("mtc1 %1,%0" :
        "=f"(native_result_0) : "r"((u32)0)); native_result_0; }));
    return;
}

static void SetEneRebirth(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    u8 *s0;
    u32 v1;
    u16 s1;
    u32 s1_word; // s1
    u32 v0;

    v1 = *(s32 *)(((u8 *)a0 + 0xc));
    s0 = (u8 *)a1;
    v1 = *(s32 *)((v1 + 0x4c));
    s1 = *(u16 *)((v1 + 0x32));
    *(u8 *)(((u8 *)a1 + 0x180)) = 7;
    ChangeAnimParam(a0, (u16)a2, 0.0f);
    if ((u32)s1 == 0) {
        s1 = 0x708;
    }
    s1_word = s1;
    v0 = rand();
    v1 = (s32)v0 % (s32)s1_word;
    *(u16 *)(s0 + 0x1ec) = s1_word + v1;
    v1 = *(u8 *)(s0 + 0x1d9);
    *(u8 *)(s0 + 0x1d9) = v1 + -1;
    return;
}


/* SetEneGuard @ 0x161380 .. 0x1613C8 (0x48 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x16138c
 */



static void SetEneGuard(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    s32 v0;
    float f12;
    u8 *s1;
    u32 s0;

    v0 = 9;
    f12 = ({ float native_result_0; __asm__("mtc1 %1,%0" : "=f"(native_result_0) : "r"((u32)0));
        native_result_0; });
    s1 = (u8 *)a1;
    *(u16 *)(((u8 *)a0 + 0x106)) = 0;
    s0 = a2;
    *(u8 *)(((u8 *)a1 + 0x180)) = v0;
    a1 = (void *)(s32)0x55;
    ChangeAnimParam(a0, (signed int)a1, f12);
    *(u16 *)(((u8 *)s1 + 0x1fe)) = s0;
    return;
}

signed int SetEneClingAndPush(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s3;
    u8 *s2;
    u8 *s1;
    u8 *s0;
    u8 *tgt;
    float f1;
    float f0;
    u32 v0;
    u8 *md;
    u8 *tg;
    u8 *tm;
    u8 *prm;
    u32 ty;

    s3 = (u8 *)a0;
    md = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPMDLDATA_4C9B1C04);
    tg = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_616170_FIELDS_TARGET_LPMDL_47F8147B);
    s1 = (u8 *)*(s32 *)(md + DCOMP_OFF_STRUCT_DW_632134_FIELDS_LPPRM_291B2B52);
    tm = (u8 *)*(s32 *)(tg + DCOMP_OFF_STRUCT_DW_616170_FIELDS_LPMDLDATA_4C9B1C04);
    prm = (u8 *)*(s32 *)(tm + DCOMP_OFF_STRUCT_DW_632134_FIELDS_LPPRM_291B2B52);
    ty = *(u16 *)(tm + DCOMP_OFF_STRUCT_DW_632134_FIELDS_MDLTYPE_494DCE2F);
    s2 = (u8 *)a1;
    if (ty != 0) {
        return 0;
    }
    if (*(u8 *)(prm + 9) == 0) {
        return 0;
    }
    if (GetCamCtrlMode() == 2) {
        return 0;
    }
    tgt = (u8 *)*(s32 *)(s3 + 0x1b4);
    s0 = (u8 *)*(s32 *)(tgt + 0x148);
    if (*(u16 *)(s0 + 0x1cc) != 0) {
        return 0;
    }
    f1 = *(float *)(s3 + 0x24) - *(float *)(tgt + 0x24);
    if (!(((f1 < 0.0f) ? -f1 : f1) <= 0.2f)) {
        return 0;
    }
    if (CheckMyDamage(tgt, s3) == 0) {
        return 0;
    }
    f0 = Math_GetAngleDist(*(float *)(s3 + 0x34), *(float *)(*(s32 *)(s3 + 0x1b4) + 0x34));
    if (!(((f0 < 0.0f) ? -f0 : f0) <= 1.5707964f)) {
        ChangeAnimParam(s3, 0x3c, 0.0f);
        *(u32 *)(s2 + 0x1e4) = *(s32 *)(s3 + 0x1b4);
        *(u16 *)(s2 + 0x1e2) = 0x4a;
        *(u8 *)(s3 + 0x130) = 1;
        *(u8 *)(s3 + 0x131) = 1;
        *(u8 *)(s3 + 0x132) = 1;
        SetMyDamage((void *)*(s32 *)(s2 + 0x1e4), s0, 0x46);
        ClearMyStruggleStick((u8 *)*(s32 *)(s2 + 0x1e4), s0);
        SetEneFrontClingPos_i(s3, s2);
        *(u8 *)(s2 + 0x246) = 0;
        *(u8 *)(s2 + 0x247) = 0;
    } else {
        if (CheckAnimParam(s3, 0x64) != 0) {
            ChangeAnimParam(s3, 0x64, 0.0f);
            *(u32 *)(s2 + 0x1e4) = *(s32 *)(s3 + 0x1b4);
            *(u16 *)(s2 + 0x1e2) = 0x68;
            *(u8 *)(s3 + 0x130) = 1;
            *(u8 *)(s3 + 0x131) = 1;
            *(u8 *)(s3 + 0x132) = 1;
            SetMyDamage((void *)*(s32 *)(s2 + 0x1e4), s0, 0x64);
            ClearMyStruggleStick((u8 *)*(s32 *)(s2 + 0x1e4), s0);
            SetEneBackClingPos_i(s3, s2);
            *(u8 *)(s2 + 0x246) = 1;
            *(u8 *)(s2 + 0x247) = 0;
        }
    }
    v0 = *(u8 *)(s1 + 0x2f);
    if (v0 == 0) {
        *(u8 *)(s0 + 0x1af) = 0x32;
    } else {
        *(u8 *)(s0 + 0x1af) = v0;
    }
    return 1;
}

/* SetEneFrontClingPos @ 0x160EA0 .. 0x160FBC (0x11c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3c23d70a at 0x160ed8
 *   fpu: float literal 0x3e4ccccd at 0x160edc
 *   fpu: float literal 0x3d4ccccd at 0x160ee8
 *   fpu: float literal 0x40490fdb at 0x160f04
 *   fpu: float literal 0x00000000 at 0x160f08
 *   fpu: float literal 0x40c90fdb at 0x160f2c
 *   fpu: mtc1 reinterprets v0 at 0x160f50
 *   fpu: float literal 0x40490fdb at 0x160f80
 *   fpu: float literal 0x3c0ef34d at 0x160f90
 *   declaration vs inferred signature: return void vs inferred u32
 */




void SetEneFrontClingPos(void *a0 /* r4 */, void *a1 /* r5 */) {
    float *s1;
    u8 *s0;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;
    float f3;
    float f2;
    float f1;
    float f0;

    s1 = (float *)a0;
    v0 = *(u8 *)(((u8 *)a1 + 0x247));
    s0 = (u8 *)a1;
    if (v0 == 0) {
        v0 = 0x3e4c0000;
        a1 = (void *)*(s32 *)(s0 + 0x1e4);
        v1 = 0x3e4c0000 | 0xcccd;
        f13 = 0.00999999978f;
        f12 = 0.200000003f;
        f14 = 0.0500000007f;
        Math_GotoVector2((float *)((u8 *)s1 + 0x20), (float *)(u32)(s32)((u8 *)a1 + 0x20),
            (f32)0.200000003f, (f32)0.00999999978f, 0.0500000007f);
    }
    v1 = *(s32 *)(s0 + 0x1e4);
    f1 = 3.14159274f;
    f0 = 0.0f;
    f2 = (3.14159274f + *(float *)((v1 + 0x34)));
    f3 = (3.14159274f + f2);
    if (f3 >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f0 = (f2 - (6.28318548f * (float)((float)(s32)(f3 / 6.28318548f))));
    } else {
        f1 = 6.28318548f;
        f0 = (f1 + (f2 - (f1 * (float)((float)(s32)(f3 / f1)))));
    }
    s1[0x66] = f0;
    v1 = *(s32 *)(s0 + 0x1e4);
    f0 = 3.14159274f;
    f14 = 0.00872499961f;
    f12 = *(float *)((v1 + 0x34));
    f0 = Math_GotoAngle(f12, (3.14159274f + s1[0x66]), 0.00872499961f);
    v1 = *(s32 *)(s0 + 0x1e4);
    *(f32 *)((v1 + 0x34)) = f0;
    return;
}

void SetEneBackClingPos(void *a0 /* r4 */, void *a1 /* r5 */) {
    float *s1;
    u8 *s0;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;
    float f0;

    s1 = (float *)a0;
    v0 = *(u8 *)(((u8 *)a1 + 0x247));
    s0 = (u8 *)a1;
    if (v0 == 0) {
        v0 = 0x3e4c0000;
        a1 = (void *)*(s32 *)(s0 + 0x1e4);
        v1 = 0x3e4c0000 | 0xcccd;
        f13 = 0.00999999978f;
        f12 = 0.200000003f;
        f14 = 0.0500000007f;
        Math_GotoVector2((float *)((u8 *)s1 + 0x20), (float *)(u32)(s32)((u8 *)a1 + 0x20),
            (f32)0.200000003f, (f32)0.00999999978f, 0.0500000007f);
    }
    v1 = *(s32 *)(s0 + 0x1e4);
    f14 = 0.00872499961f;
    f0 = *(float *)((v1 + 0x34));
    s1[0x66] = f0;
    v0 = *(s32 *)(s0 + 0x1e4);
    f12 = *(float *)((v0 + 0x34));
    f0 = Math_GotoAngle(f12, (float)s1[0x66], 0.00872499961f);
    v1 = *(s32 *)(s0 + 0x1e4);
    *(f32 *)((v1 + 0x34)) = f0;
    return;
}

void SetEneClingOut(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    u8 *s1;
    u8 *s0;

    s1 = (u8 *)a0;
    s0 = (u8 *)a1;
    a1 = (void *)(u16)a2;
    ChangeAnimParam(a0, (signed int)a1, (float)({ float native_result_0; __asm__("mtc1 %1,%0" :
        "=f"(native_result_0) : "r"((u32)0)); native_result_0; }));
    *(u8 *)(((u8 *)s0 + 0x247)) = 1;
    *(u8 *)(((u8 *)s1 + 0x132)) = 0;
    return;
}

/* CheckEneClingOut @ 0x160D70 .. 0x160DA8 (0x38 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x160d80 writes a register its branch at 0x160d7c reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int CheckEneClingOut(int a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    s32 v1;
    u32 v0;

    a0 = *(s32 *)(((u8 *)a1 + 0x1e4));
    v1 = *(s16 *)(((u8 *)a0 + 0x104));
    if ((u32)v1 == (u32)(u16)a2) {
        return 1;
    }
    v0 = *(u8 *)((*(s32 *)(((u8 *)a0 + 0x148)) + 0x100));
    if ((u32)(v0 ^ 8) < (u32)1) {
        return 1;
    }
    return 0;
}
