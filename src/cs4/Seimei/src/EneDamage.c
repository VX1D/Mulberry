#include "common.h"

/* SetChainDamage @ 0x171060 .. 0x171278 (0x218 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @1293 -> 0x253b20
 *   indirect: jr v1 at 0x1710d8 -> <v1>
 *   fpu: mov.s at 0x17112c is a float copy
 *   fpu: float literal 0x00000000 at 0x171130
 *   fpu: float literal 0x3fc90fdb at 0x171150
 *   cfg: loop body is not one contiguous region: .L00171090
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int CheckHitTargetMdl(void *, void *, signed int);
extern float Math_VectorToAngle(float, float);
extern float Math_GetAngleDist(float, float);
extern signed int CheckAnimParam(void *, signed int);
extern u8 MdlMng[];
extern u32 L1293[];

/* EneLifeCutProc @ 0x171280 .. 0x171418 (0x198 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   literal: @1327 -> 0x253b40
 *   delay: addiu at 0x1712c8 writes a register its branch at 0x1712c4 reads
 *   delay: addiu at 0x1712dc writes a register its branch at 0x1712d8 reads
 *   indirect: jr v1 at 0x17131c -> <v1>
 *   stack: address of the slot at 0x40 escapes at 0x171380
 *   stack: address of the slot at 0x40 escapes at 0x171390
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void * memset(void *, int, unsigned int);
extern void sceVu0CopyVector(void *, void *);

struct dw_902612_fields;
struct dw_915444_fields;
#ifndef PROTO_DW_914077_FIELDS
#define PROTO_DW_914077_FIELDS
struct dw_914077_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_912011_FIELDS
#define PROTO_DW_912011_FIELDS
struct dw_912011_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_911689_FIELDS
#define PROTO_DW_911689_FIELDS
struct dw_911689_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_902612_fields *lpMdl; };
#endif
#ifndef PROTO_DW_902612_FIELDS
#define PROTO_DW_902612_FIELDS
struct dw_902612_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_915444_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_902612_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_914077_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_912011_fields flags; unsigned char _pad1[3]; struct dw_911689_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_916844_FIELDS
#define PROTO_DW_916844_FIELDS
struct dw_916844_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_915444_FIELDS
#define PROTO_DW_915444_FIELDS
struct dw_915444_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_916844_fields DmyPoly[32]; };
#endif

struct EneCtrlLC { u8 pad0[0x110]; void (*CalcDmgFunc)(void *, void *, u16); u8 pad1[0x180 - 0x114]; u8 actID; u8 pad2[3]; int (*GetDmgAnimFunc)(void *); u8 pad3[0x1f8 - 0x188]; u16 lifecut; u8 pad4[0x244 - 0x1fa]; u8 lifecutscl; };
struct EneLCPrm { u8 pad[0x2c]; u16 lifecut; };
struct EneDmgPrm { float pos[4]; void *lpEne; void *lpPrm; u8 pad[24]; };
/* SetChainDamage @ 0x171060 .. 0x171278 (0x218 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @1293 -> 0x253b20
 *   indirect: jr v1 at 0x1710d8 -> <v1>
 *   fpu: mov.s at 0x17112c is a float copy
 *   fpu: float literal 0x00000000 at 0x171130
 *   fpu: float literal 0x3fc90fdb at 0x171150
 *   cfg: loop body is not one contiguous region: .L00171090
 *   declaration vs inferred signature: return void vs inferred u32
 */

struct dw_902612_fields;
struct dw_915444_fields;
#ifndef PROTO_DW_914077_FIELDS
#define PROTO_DW_914077_FIELDS
struct dw_914077_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_912011_FIELDS
#define PROTO_DW_912011_FIELDS
struct dw_912011_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_911689_FIELDS
#define PROTO_DW_911689_FIELDS
struct dw_911689_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_902612_fields *lpMdl; };
#endif
#ifndef PROTO_DW_902612_FIELDS
#define PROTO_DW_902612_FIELDS
struct dw_902612_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_915444_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_902612_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_914077_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_912011_fields flags; unsigned char _pad1[3]; struct dw_911689_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_902612_FIELDS_ANG_1__AB797FE0_DEFINED
#define DCOMP_OFF_STRUCT_DW_902612_FIELDS_ANG_1__AB797FE0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_902612_FIELDS_ANG_1__AB797FE0 = (int)&(((struct dw_902612_fields *)0)->Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_902612_FIELDS_HP_88CBD382_DEFINED
#define DCOMP_OFF_STRUCT_DW_902612_FIELDS_HP_88CBD382_DEFINED
enum { DCOMP_OFF_STRUCT_DW_902612_FIELDS_HP_88CBD382 = (int)&(((struct dw_902612_fields *)0)->Hp) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_902612_FIELDS_POS_0__DBC19E4B_DEFINED
#define DCOMP_OFF_STRUCT_DW_902612_FIELDS_POS_0__DBC19E4B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_902612_FIELDS_POS_0__DBC19E4B = (int)&(((struct dw_902612_fields *)0)->Pos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_902612_FIELDS_POS_2__9E8BE087_DEFINED
#define DCOMP_OFF_STRUCT_DW_902612_FIELDS_POS_2__9E8BE087_DEFINED
enum { DCOMP_OFF_STRUCT_DW_902612_FIELDS_POS_2__9E8BE087 = (int)&(((struct dw_902612_fields *)0)->Pos[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_902612_FIELDS_BUSE_7674BEDE_DEFINED
#define DCOMP_OFF_STRUCT_DW_902612_FIELDS_BUSE_7674BEDE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_902612_FIELDS_BUSE_7674BEDE = (int)&(((struct dw_902612_fields *)0)->bUse) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_902612_FIELDS_LPCTRLST_8F05BFE7_DEFINED
#define DCOMP_OFF_STRUCT_DW_902612_FIELDS_LPCTRLST_8F05BFE7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_902612_FIELDS_LPCTRLST_8F05BFE7 = (int)&(((struct dw_902612_fields *)0)->lpCtrlSt) - 0 };
#endif
#ifndef DCOMP_EXPR_CFEF94067507FB7D
#define DCOMP_EXPR_CFEF94067507FB7D(dcomp_arg) ((dcomp_arg) < 0.0f ? (-(dcomp_arg)) : (dcomp_arg))
#endif




/* GetEneDamageAnim @ 0x171420 .. 0x1718E8 (0x4c8 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490fdb at 0x17148c
 *   fpu: float literal 0x00000000 at 0x171490
 *   fpu: float literal 0x40c90fdb at 0x1714b4
 *   fpu: mtc1 reinterprets v0 at 0x1714d8
 *   delay: addiu at 0x171504 writes a register its branch at 0x171500 reads
 *   delay: addiu at 0x171518 writes a register its branch at 0x171514 reads
 *   delay: addiu at 0x17152c writes a register its branch at 0x171528 reads
 *   delay: addiu at 0x171540 writes a register its branch at 0x17153c reads
 *   delay: addiu at 0x171554 writes a register its branch at 0x171550 reads
 *   delay: addiu at 0x171568 writes a register its branch at 0x171564 reads
 *   fpu: float literal 0x00000000 at 0x171598
 *   fpu: float literal 0x00000000 at 0x1715c0
 *   fpu: float literal 0x00000000 at 0x1715f8
 *   fpu: float literal 0x00000000 at 0x171620
 *   fpu: float literal 0x00000000 at 0x171658
 *   fpu: float literal 0x00000000 at 0x171680
 *   fpu: float literal 0x00000000 at 0x1716b8
 *   fpu: float literal 0x00000000 at 0x1716e0
 *   fpu: float literal 0x00000000 at 0x17170c
 *   fpu: float literal 0x3fc90624 at 0x17172c
 *   fpu: float literal 0x00000000 at 0x17175c
 *   fpu: mov.s at 0x17176c is a float copy
 *   fpu: float literal 0x3f490624 at 0x17177c
 *   fpu: float literal 0x00000000 at 0x171798
 *   fpu: mov.s at 0x1717a8 is a float copy
 *   fpu: float literal 0x4016c49b at 0x1717b8
 *   fpu: float literal 0x00000000 at 0x1717d8
 *   fpu: float literal 0x00000000 at 0x171810
 *   fpu: float literal 0x3fc90624 at 0x171830
 *   delay: addiu at 0x1718b8 writes a register its branch at 0x1718b4 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void sceVu0CopyVector(void *, void *);

#ifndef DCOMP_EXPR_405892EAFA68827F
#define DCOMP_EXPR_405892EAFA68827F(dcomp_arg) ((dcomp_arg) < 0.0f ? (-(dcomp_arg)) : (float)(dcomp_arg))
#endif
#ifndef DCOMP_EXPR_CFEF94067507FB7D
#define DCOMP_EXPR_CFEF94067507FB7D(dcomp_arg) ((dcomp_arg) < 0.0f ? (-(dcomp_arg)) : (dcomp_arg))
#endif
/* GetEneDamageAnim @ 0x171420 .. 0x1718E8 (0x4c8 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490fdb at 0x17148c
 *   fpu: float literal 0x00000000 at 0x171490
 *   fpu: float literal 0x40c90fdb at 0x1714b4
 *   fpu: mtc1 reinterprets v0 at 0x1714d8
 *   delay: addiu at 0x171504 writes a register its branch at 0x171500 reads
 *   delay: addiu at 0x171518 writes a register its branch at 0x171514 reads
 *   delay: addiu at 0x17152c writes a register its branch at 0x171528 reads
 *   delay: addiu at 0x171540 writes a register its branch at 0x17153c reads
 *   delay: addiu at 0x171554 writes a register its branch at 0x171550 reads
 *   delay: addiu at 0x171568 writes a register its branch at 0x171564 reads
 *   fpu: float literal 0x00000000 at 0x171598
 *   fpu: float literal 0x00000000 at 0x1715c0
 *   fpu: float literal 0x00000000 at 0x1715f8
 *   fpu: float literal 0x00000000 at 0x171620
 *   fpu: float literal 0x00000000 at 0x171658
 *   fpu: float literal 0x00000000 at 0x171680
 *   fpu: float literal 0x00000000 at 0x1716b8
 *   fpu: float literal 0x00000000 at 0x1716e0
 *   fpu: float literal 0x00000000 at 0x17170c
 *   fpu: float literal 0x3fc90624 at 0x17172c
 *   fpu: float literal 0x00000000 at 0x17175c
 *   fpu: mov.s at 0x17176c is a float copy
 *   fpu: float literal 0x3f490624 at 0x17177c
 *   fpu: float literal 0x00000000 at 0x171798
 *   fpu: mov.s at 0x1717a8 is a float copy
 *   fpu: float literal 0x4016c49b at 0x1717b8
 *   fpu: float literal 0x00000000 at 0x1717d8
 *   fpu: float literal 0x00000000 at 0x171810
 *   fpu: float literal 0x3fc90624 at 0x171830
 *   delay: addiu at 0x1718b8 writes a register its branch at 0x1718b4 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

#ifndef DCOMP_EXPR_405892EAFA68827F
#define DCOMP_EXPR_405892EAFA68827F(dcomp_arg) ((dcomp_arg) < 0.0f ? (-(dcomp_arg)) : (float)(dcomp_arg))
#endif
#ifndef DCOMP_EXPR_CFEF94067507FB7D
#define DCOMP_EXPR_CFEF94067507FB7D(dcomp_arg) ((dcomp_arg) < 0.0f ? (-(dcomp_arg)) : (dcomp_arg))
#endif


/* CalcEneDamage @ 0x1718F0 .. 0x171A10 (0x120 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x171920
 *   fpu: mtc1 reinterprets v1 at 0x171934
 *   fpu: float literal 0x42c80000 at 0x171984
 *   fpu: mtc1 reinterprets v0 at 0x171990
 *   fpu: float literal 0x42c80000 at 0x1719c4
 *   fpu: mtc1 reinterprets v0 at 0x1719d0
 *   fpu: float literal 0x3f800000 at 0x1719ec
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern int rand();

/* SetEneDamageProc @ 0x171A10 .. 0x171E90 (0x480 bytes, frame 0xc0) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @985 -> 0x22afb0
 *   stack: address of the slot at 0xa0 escapes at 0x171a84
 *   stack: address of the slot at 0xa0 escapes at 0x171a90
 *   stack: address of the slot at 0xa0 escapes at 0x171a90
 *   stack: address of the slot at 0xa0 escapes at 0x171aa0
 *   stack: address of the slot at 0xbc escapes at 0x171aa0
 *   stack: address of the slot at 0x90 escapes at 0x171ab4
 *   stack: address of the slot at 0x90 escapes at 0x171ae0
 *   fpu: float literal 0x40490fdb at 0x171b40
 *   fpu: float literal 0x00000000 at 0x171b44
 *   fpu: float literal 0x40c90fdb at 0x171b68
 *   fpu: mtc1 reinterprets v0 at 0x171b8c
 *   fpu: float literal 0x00000000 at 0x171bac
 *   fpu: float literal 0x40060418 at 0x171bcc
 *   delay: addiu at 0x171dd4 writes a register its branch at 0x171dd0 reads
 *   stack: address of the slot at 0x80 escapes at 0x171df0
 *   literal: @985 initializes the 16-byte local at 0x80
 *   cfg: kept branch: 0x171d70 if (..) goto .L00171DB8
 */

extern void sceVu0SubVector(void *, void *, void *);
extern void sceVu0Normalize(void *, void *);
extern void SfxCalc_Vec2Ang(float *, float *, float *);
extern signed int SFX_Create_OnAng(unsigned short, float *, float *);
extern signed int SFX_BurnModel(void *);
extern u8 GameSt[];
extern u32 L985[];

#ifndef PROTO_DW_912241_FIELDS
#define PROTO_DW_912241_FIELDS
struct dw_912241_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_912241_FIELDS_PENANCEMODE_32C6CEAC_DEFINED
#define DCOMP_OFF_STRUCT_DW_912241_FIELDS_PENANCEMODE_32C6CEAC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_912241_FIELDS_PENANCEMODE_32C6CEAC = (int)&(((struct dw_912241_fields *)0)->PenanceMode) - 0 };
#endif
#ifndef DCOMP_EXPR_CFEF94067507FB7D
#define DCOMP_EXPR_CFEF94067507FB7D(dcomp_arg) ((dcomp_arg) < 0.0f ? (-(dcomp_arg)) : (dcomp_arg))
#endif
#ifndef DCOMP_EXPR_F4392B91E5A8C94E
#define DCOMP_EXPR_F4392B91E5A8C94E(dcomp_arg) ((3.1415927f + (dcomp_arg)) >= 0.0f ? ((dcomp_arg) - (6.2831855f * (float)(s32)((3.1415927f + (dcomp_arg)) / 6.2831855f))) : (6.2831855f + ((dcomp_arg) - (6.2831855f * (float)(s32)((3.1415927f + (dcomp_arg)) / 6.2831855f)))))
#endif

/* CheckEneDamage @ 0x171F40 .. 0x17209C (0x15c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: daddu at 0x171f78 writes a register its branch at 0x171f74 reads
 *   delay: daddu at 0x171f90 writes a register its branch at 0x171f8c reads
 *   delay: daddu at 0x171fa8 writes a register its branch at 0x171fa4 reads
 *   delay: daddu at 0x171fc0 writes a register its branch at 0x171fbc reads
 *   delay: addiu at 0x171fdc writes a register its branch at 0x171fd8 reads
 *   delay: addiu at 0x171ff0 writes a register its branch at 0x171fec reads
 *   delay: addiu at 0x17201c writes a register its branch at 0x172018 reads
 *   delay: addiu at 0x172030 writes a register its branch at 0x17202c reads
 *   delay: daddu at 0x172058 writes a register its branch at 0x172054 reads
 *   delay: daddu at 0x172070 writes a register its branch at 0x17206c reads
 *   cfg: kept branch: 0x171f48 if (..) goto .L00171F60
 *   cfg: kept goto: 0x171f58 -> .L00172090
 *   cfg: kept goto: 0x172008 -> .L00172090
 *   cfg: kept goto: 0x172048 -> .L00172090
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int KnMsgMng_CheckMsgNone(void);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int CheckEneDamage(void *a0 );
signed int CheckEneLockOn(void *a0 );
void SetEneDamageProc(void *a0 );
signed int CalcEneDamage(void *a0 );
signed int GetEneDamageAnim(void *a0 );
void EneLifeCutProc(struct dw_902612_fields *lpEne);
void SetChainDamage(void *a0 );


signed int CheckEneDamage(void *a0 /* r4 */) {
    u8 *a1;
    s32 v1;
    u32 v0;

    v0 = *(u8 *)a0;
    a1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    if (v0 == 0) {
        v0 = 0;
        goto _L00172090;
    }
    v0 = *(s32 *)(((u8 *)a0 + 0x120));
    if ((s32)v0 <= 0) {
        v1 = *(u8 *)(a1 + 0x180);
        v0 = 7;
        if ((u32)v1 != v0) {
            v0 = 0;
            return v0;
        }
    }
    v0 = *(s16 *)(((u8 *)a0 + 0x12c));
    if (v0 != 0) {
        v0 = 0;
        return v0;
    }
    v0 = *(u16 *)(a1 + 0x1fa);
    if (v0 != 0) {
        v0 = 0;
        return v0;
    }
    v0 = *(u8 *)(((u8 *)a0 + 3));
    if (v0 != 0) {
        v0 = 0;
        return v0;
    }
    v1 = *(s16 *)(((u8 *)a0 + 0x104));
    v0 = 0x6d;
    switch ((u32)v1) {
    case 63:
    case 69:
    case 103:
    case 109:
        v0 = 0;
        return v0;
    default:
        v1 = *(u8 *)(a1 + 0x180);
        v0 = 6;
        switch ((u32)v1) {
        case 5:
        case 4:
        case 8:
            v0 = 0;
            return v0;
        case 6:
            v0 = *(u8 *)(a1 + 0x249);
            if (v0 != 0) {
                break;
            }
            v0 = 0;
            return v0;
        }
    }
    v0 = *(u16 *)(a1 + 0x1ee);
    if (v0 != 0) {
        v0 = 0;
        return v0;
    }
    v0 = KnMsgMng_CheckMsgNone();
    v0 = v0 != 0;
    _L00172090:;
    return v0;
}


/* CheckEneLockOn @ 0x171E90 .. 0x171F38 (0xa8 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x171ec0 writes a register its branch at 0x171ebc reads
 *   delay: daddu at 0x171ed8 writes a register its branch at 0x171ed4 reads
 *   delay: addiu at 0x171ef4 writes a register its branch at 0x171ef0 reads
 *   delay: addiu at 0x171f08 writes a register its branch at 0x171f04 reads
 *   cfg: kept branch: 0x171e90 if (..) goto .L00171EA8
 *   cfg: kept goto: 0x171ea0 -> .L00171F30
 *   cfg: kept goto: 0x171f20 -> .L00171F30
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int CheckEneLockOn(void *a0 /* r4 */) {
    u32 v0;
    u8 *a1;
    u32 v1;

    v0 = *(u8 *)a0;
    a1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    if (v0 != 0) {
        goto _L00171EA8;
    }
    v0 = 0;
    goto _L00171F30;
    _L00171EA8:;
    v0 = *(s32 *)(((u8 *)a0 + 0x120));
    if ((s32)v0 <= 0) {
        v1 = *(u8 *)(((u8 *)a1 + 0x180));
        v0 = 7;
        if (v1 != v0) {
            v0 = 0;
            return v0;
        }
    }
    v0 = *(u8 *)(((u8 *)a0 + 3));
    if (v0 != 0) {
        v0 = 0;
        return v0;
    }
    v1 = *(u8 *)(((u8 *)a1 + 0x180));
    v0 = 8;
    switch (v1) {
    case 5:
    case 4:
    case 6:
    case 8:
        v0 = 0;
        return v0;
    }
    v0 = 1;
    _L00171F30:;
    return v0;
}
void SetEneDamageProc(void *a0 /* r4 */) {
    s32 xt2;
    u8 *s4;
    u32 xt0;
    u8 *s3;
    s32 v1;
    u8 *s2;
    u32 s1;
    u8 *s0;
    float f12;
    s32 v0;
    void *a0_2;
    u8 stackFrame_A0[28] __attribute__((aligned(16)));
    u8 stackFrame_BC[4] __attribute__((aligned(4)));

    xt2 = *(s32 *)(((u8 *)a0 + 0x14));
    xt0 = *(u8 *)(((u8 *)0x19 + (u32)a0));
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x10));
    v1 = 9;
    s3 = (u8 *)*(s32 *)(s0 + 0x148);
    a0_2 = (void *)((((u16)xt0 << 2) + xt0));
    a0_2 = (void *)((((u32)a0_2)) << 3);
    s2 = (u8 *)*(s32 *)(*(s32 *)(s0 + 0xc) + 0x4c);
    a0_2 = (void *)((u8 *)xt2 + ((u32)a0_2));
    s4 = (u8 *)((u8 *)a0_2 + 0xa0);
    a0_2 = (void *)*(u8 *)(0x180 + (s32)s3);
    if ((u32)a0_2 == v1) {
        a0_2 = (void *)*(u16 *)s2;
        xt0 = (u32)((u8 *)a0);
        if ((u32)a0_2 == 0x22) {
            sceVu0SubVector((void *)((u8 *)&stackFrame_A0[0]), (void *)(s0 + 0x20), (void *)xt0);
            sceVu0Normalize((void *)((u8 *)&stackFrame_A0[0]), (void *)((u8 *)&stackFrame_A0[0]));
            SfxCalc_Vec2Ang((float *)((u8 *)&stackFrame_A0[0]), (float *)0, (float *)((u8
                *)&stackFrame_BC[0]));
            {
                u8 stackFrame_90[16] __attribute__((aligned(16))) = {0};
                xt0 = (s32)(s0 + 0x20);
                a0_2 = (void *)((0x2d));
                ((f32 *)stackFrame_90)[1] = *(float *)((u8 *)&stackFrame_BC[0]);
                SFX_Create_OnAng((unsigned short)a0_2, (float *)xt0, (float *)((u8
                    *)&stackFrame_90[0]));
                *(u16 *)(0x1fa + s3) = 0x14;
            }
        }
        return;
    }
    a0_2 = (void *)s0;
    xt0 = 0x55;
    v0 = CheckAnimParam(a0_2, xt0);
    if (v0 == 0) {
        v0 = 0;
    } else {
        f12 = (*(float *)(s0 + 0x20) - *(float *)((u8 *)a0));
        f12 = Math_VectorToAngle(f12, (*(float *)(s0 + 0x28) - *(float *)(((u8 *)a0) + 8)));
        f12 = DCOMP_EXPR_F4392B91E5A8C94E((f12 - *(float *)(0x34 + (u32)s0)));
        if (!((float)DCOMP_EXPR_CFEF94067507FB7D(f12) <= 2.0939999f)) {
            v0 = 0;
        } else {
            v1 = 0x64;
            v0 = rand();
            v0 = (v0) % 0x64;
            if ((s32)0x31 >= v0) {
                v0 = 0;
            } else {
                v0 = 1;
            }
        }
    }
    if (v0 != 0) {
        v0 = *(s32 *)(s3 + 0x124);
        xt0 = (v0);
        ((void (*)(s32, s32, s32))xt0)((s32)a0_2, (s32)s3, 0x78);
        *(u16 *)(s3 + 0x1fa) = 0x14;
        a0_2 = (void *)s0;
    } else {
        v0 = *(u8 *)(0x26 + s2);
        if (v0 == 0) {
            v0 = *(s32 *)(0x188 + s3);
            a0_2 = (void *)((u8 *)((a0)));
            v0 = ((u32 (*)(u32))v0)((u32)a0_2);
            v1 = *(s32 *)(s0 + 0x120);
            v0 = v1 - v0;
            *(u32 *)(0x120 + s0) = v0;
            v0 = *(s32 *)(0x120 + s0);
            if (v0 < 0) {
                *(u32 *)(s0 + 0x120) = 0;
            }
            v1 = GameSt[(DCOMP_OFF_STRUCT_DW_912241_FIELDS_PENANCEMODE_32C6CEAC / 1)];
            v0 = 2;
            if (v1 == v0) {
                *(u32 *)(0x120 + s0) = 0;
            }
        }
        v0 = *(u8 *)(s4 + 0x17);
        *(u8 *)(0x1f2 + s3) = (u32)v0;
        a0_2 = (void *)s0;
        v0 = *(u8 *)(s3 + 0x1f2);
        if (v0 != 0) {
            SFX_BurnModel(a0_2);
        }
        a0_2 = (void *)((u8 *)a0);
        v0 = *(s32 *)(0x184 + s3);
        s1 = ((u32 (*)(u32))(v0))((u32)a0_2);
        v0 = *(u8 *)(((u8 *)a0) + 0x1c);
        if (v0 != 0) {
            if (s1 != (u32)0x22) {
                v1 = *(s16 *)(s0 + 0x104);
                v0 = 0x30;
                switch (v1) {
                case 48:
                    s1 = 0x31;
                    break;
                default:
                    s1 = v1 + -3;
                }
            }
        }
        v0 = *(s32 *)(s0 + 0x120);
        if (v0 > 0) {
            v0 = *(s32 *)(s3 + 0x10c);
            a0_2 = (void *)s0;
            ((void (*)(s32, s32, u16))(s32)v0)((((s32)a0_2)), ((s32)(s3)), (s1));
        } else {
            xt2 = *(u8 *)((xt2 + 0x30));
            if (xt2 == 0) {
                xt2 = 0x28;
            }
            v1 = GameSt[(DCOMP_OFF_STRUCT_DW_912241_FIELDS_PENANCEMODE_32C6CEAC / 1)];
            v0 = 2;
            if (v1 == v0) {
                xt2 = 0;
            }
            v0 = *(u8 *)(0x1d9 + s3);
            if (v0 != 0 && *(u8 *)(0x14 + s4) == 0) {
                v0 = rand();
                v1 = 0x64;
                v0 = v0 % 0x64;
                if (xt2 <= (s32)v0) {
                    goto _L00171DB8;
                }
                v0 = *(s32 *)(s3 + 0x11c);
                a0_2 = (void *)s0;
                ((void (*)(s32, s32, u16))v0)((((s32)a0_2)), ((s32)s3), s1);
            } else {
                _L00171DB8:;
                a0_2 = (void *)s0;
                v0 = *(s32 *)(s3 + 0x110);
                ((void (*)(s32, s32, u16))(v0))((((s32)a0_2)), (((s32)(u32)s3)), (u16)s1);
                v1 = *(u8 *)(s3 + 0x1f2);
                if (v1 != 0) {
                    *(u8 *)(8 + s0) = 1;
                    v0 = ((u32)L985);
                    a0_2 = (void *)(0xb0 + s0);
                    {
                        struct stackFrame_80 { u8 b[16]; } stackFrame_80
                            __attribute__((aligned(16))) = {{0xcd, 0xcc, 0x4c, 0x3d, 0xcd, 0xcc,
                            0x4c, 0x3d, 0xcd, 0xcc, 0x4c, 0x3d, 0x00, 0x00, 0x80, 0x3f}};
                        sceVu0CopyVector(a0_2, (void *)((u8 *)&stackFrame_80));
                    }
                }
            }
        }
        a0_2 = (void *)*(u16 *)(0x36 + s2);
        if (a0_2 == 0) {
            a0_2 = (void *)(0x2d);
        }
        v1 = *(u8 *)(0x19 + s4);
        v1 = (s32)((u8 *)a0_2 - v1);
        *(u16 *)(0x12c + s0) = v1;
        v1 = *(s16 *)(s0 + 0x12c);
        if (v1 < 0) {
            *(u16 *)(0x12c + (s32)s0) = 0;
        }
        v1 = *(u8 *)(s4 + 0x15);
        if (v1 != 0) {
            v1 = *(u16 *)(((u8 *)a0) + 0x1a);
            *(u16 *)(s3 + 0x1ee) = v1;
        }
        v1 = *(s32 *)(0x240 + s3);
        if (v1 != 0) {
            xt0 = *(s32 *)((0x148 + (s32)v1));
            *(u32 *)(((v1 + 0x120))) = 0;
            v0 = *(s32 *)((0x110 + xt0));
            a0_2 = (void *)*(s32 *)(0x240 + s3);
            ((void (*)(s32, s32, s32))(v0))(((s32)a0_2), xt0, 0x28);
        }
    }
    return;
}

signed int CalcEneDamage(void *a0 /* r4 */) {
    float f1;
    float f0;
    float f20;
    s32 v1;

    f20 = ((float)(float)(u32)*(s32 *)(((s32)(*(s32 *)(((u8 *)a0 + 0x14)) + (s32)((u32)*(u8 *)(((u8
        *)a0 + 0x19)) * (u32)(0x28))) + 0xa0)) * *(float *)(((u8 *)0x20 + (u32)(a0))));
    v1 = 0xa;
    if ((s32)((s32)rand() % (s32)(0xa)) <= (s32)4) {
        a0 = (void *)(s32)0x1e;
        v1 = 0x42c80000;
        f0 = 100.0f;
        f1 = ((float)((float)(s32)(u32)((s32)rand() % (s32)(0x1e))) / 100.0f);
    } else {
        a0 = (void *)(s32)0x1e;
        v1 = 0x42c80000;
        f0 = 100.0f;
        f1 = (-((float)((float)(s32)(u32)((s32)rand() % (s32)(0x1e))) / 100.0f));
    }
    f0 = 1.0f;
    return ((s32)(f20 * (1.0f + f1)));
}
signed int GetEneDamageAnim(void *a0 /* r4 */) {
    u8 *s4;
    u8 *s3;
    float f3;
    u32 a1;
    float f2;
    float f1;
    u8 *s2;
    float f0;
    s32 v1;
    u8 *s1;
    u32 v0;
    s32 s0;

    s4 = (u8 *)a0;
    s2 = (u8 *)*(s32 *)(((u8 *)a0 + 0x10));
    a1 = *(u8 *)(((u8 *)a0 + 0x19));
    v0 = *(s32 *)(((u8 *)a0 + 0x14));
    s1 = (u8 *)*(s32 *)(s2 + 0x148);
    s3 = (u8 *)(s32)((u32)(v0 + (s32)(a1 * 0x28)) + 0xa0);
    f0 = Math_VectorToAngle((*(float *)(s2 + 0x20) - *(float *)a0), (*(float *)(s2 + 0x28) -
        *(float *)(((u8 *)a0 + 8))));
    f3 = (f0 - *(float *)(s2 + 0x34));
    f0 = (3.1415927f + f3);
    if (f0 >= 0.0f) {
        f2 = (f3 - (6.2831855f * (float)((float)(s32)(f0 / 6.2831855f))));
    } else {
        f1 = 6.2831855f;
        f2 = (f1 + (f3 - (f1 * (float)((float)(s32)(f0 / f1)))));
    }
    v1 = *(s16 *)(s2 + 0x104);
    v0 = 0x6c;
    switch ((u32)v1) {
    case 60:
    case 61:
    case 62:
        *(u8 *)(s2 + 0x132) = 0;
        *(u8 *)(s2 + 0x130) = 0;
        *(u8 *)(s2 + 0x131) = 0;
        v0 = *(s32 *)(s2 + 0x120);
        if ((s32)v0 > 0) {
            a0 = (void *)*(s32 *)(s1 + 0x1e4);
            a1 = *(u16 *)(s1 + 0x1e2);
            ChangeAnimParam(a0, a1, 0.0f);
            *(u32 *)(s1 + 0x1e4) = 0;
            return 0x40;
        }
        v0 = *(u16 *)(s1 + 0x1e2);
        a0 = (void *)*(s32 *)(s1 + 0x1e4);
        ChangeAnimParam(a0, (u16)(v0 + 1), 0.0f);
        *(u32 *)(s1 + 0x1e4) = 0;
        return 0x41;
    case 66:
    case 67:
    case 68:
        *(u8 *)(s2 + 0x132) = 0;
        *(u8 *)(s2 + 0x130) = 0;
        *(u8 *)(s2 + 0x131) = 0;
        v0 = *(s32 *)(s2 + 0x120);
        if ((s32)v0 > 0) {
            a0 = (void *)*(s32 *)(s1 + 0x1e4);
            a1 = *(u16 *)(s1 + 0x1e2);
            ChangeAnimParam(a0, a1, 0.0f);
            *(u32 *)(s1 + 0x1e4) = 0;
            return 0x46;
        }
        v0 = *(u16 *)(s1 + 0x1e2);
        a0 = (void *)*(s32 *)(s1 + 0x1e4);
        ChangeAnimParam(a0, (u16)(v0 + 1), 0.0f);
        *(u32 *)(s1 + 0x1e4) = 0;
        return 0x47;
    case 100:
    case 101:
    case 102:
        *(u8 *)(s2 + 0x132) = 0;
        *(u8 *)(s2 + 0x130) = 0;
        *(u8 *)(s2 + 0x131) = 0;
        v0 = *(s32 *)(s2 + 0x120);
        if ((s32)v0 > 0) {
            a0 = (void *)*(s32 *)(s1 + 0x1e4);
            a1 = *(u16 *)(s1 + 0x1e2);
            ChangeAnimParam(a0, a1, 0.0f);
            *(u32 *)(s1 + 0x1e4) = 0;
            return 0x68;
        }
        v0 = *(u16 *)(s1 + 0x1e2);
        a0 = (void *)*(s32 *)(s1 + 0x1e4);
        ChangeAnimParam(a0, (u16)(v0 + 1), 0.0f);
        *(u32 *)(s1 + 0x1e4) = 0;
        return 0x69;
    case 106:
    case 107:
    case 108:
        *(u8 *)(s2 + 0x132) = 0;
        *(u8 *)(s2 + 0x130) = 0;
        *(u8 *)(s2 + 0x131) = 0;
        v0 = *(s32 *)(s2 + 0x120);
        if ((s32)v0 > 0) {
            a0 = (void *)*(s32 *)(s1 + 0x1e4);
            a1 = *(u16 *)(s1 + 0x1e2);
            ChangeAnimParam(a0, a1, 0.0f);
            *(u32 *)(s1 + 0x1e4) = 0;
            return 0x6e;
        }
        v0 = *(u16 *)(s1 + 0x1e2);
        a0 = (void *)*(s32 *)(s1 + 0x1e4);
        ChangeAnimParam(a0, (u16)(v0 + 1), 0.0f);
        *(u32 *)(s1 + 0x1e4) = 0;
        return 0x6f;
    default:
        v0 = *(u8 *)(s3 + 7);
        if (v0 != 0) {
            if ((float)DCOMP_EXPR_CFEF94067507FB7D(f2) < 1.5704999f) {
                s0 = 0x1e;
                break;
            } else {
                s0 = 0x20;
                break;
            }
        } else {
            v0 = *(s32 *)(s2 + 0x120);
            if ((s32)v0 > 0) {
                if ((float)DCOMP_EXPR_405892EAFA68827F(f2) < 0.78524995f) {
                    s0 = 0x16;
                    break;
                } else if (!((float)DCOMP_EXPR_405892EAFA68827F(f2) <= 2.3557498f)) {
                    s0 = 0x17;
                    break;
                } else if (f2 < 0.0f) {
                    s0 = 0x15;
                    break;
                } else {
                    if (f2 <= 0.0f) {
                        break;
                    }
                    s0 = 0x14;
                    break;
                }
            } else if ((float)DCOMP_EXPR_CFEF94067507FB7D(f2) < 1.5704999f) {
                s0 = 0x28;
                break;
            } else {
                s0 = 0x29;
            }
        }
    }
    v0 = *(u8 *)(s3 + 0x14);
    a0 = (void *)s2;
    if (v0 != 0) {
        v0 = CheckAnimParam(a0, 0x22);
        if (v0 != 0) {
            v0 = 1;
            *(u8 *)(s2 + 0x130) = v0;
            a0 = (void *)(s2 + 0x20);
            *(u8 *)(s1 + 0x1f3) = v0;
            s0 = 0x22;
            sceVu0CopyVector(a0, (void *)s4);
        }
    }
    v0 = CheckAnimParam((void *)s2, (u16)s0);
    if (v0 != 0) {
        return s0;
    }
    v0 = *(s32 *)(s2 + 0x120);
    return (s32)v0 > 0 ? (s32)0x16 : (s32)0x28;
}

void EneLifeCutProc(struct dw_902612_fields *lpEne) {
    struct EneLCPrm *lpEnePrm = (struct EneLCPrm *)lpEne->lpMdlData->lpPrm;
    struct EneCtrlLC *lpCtrl = (struct EneCtrlLC *)lpEne->lpCtrlSt;
    u16 LifeCutScl = 1;
    struct EneDmgPrm DmgPrm;
    int AnimID;
    static u8 dmyParam[0x168];

    if (lpEne->Hp > 0 && lpEnePrm->lifecut != 0) {
        switch (lpEne->IndexAnim) {
        case 63:
        case 69:
        case 103:
        case 109:
            return;
        default:
            switch (({ s32 r_; __asm__("addi %0,%1,-3" : "=r"(r_) : "r"((s32)lpCtrl->actID)); r_; })) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                return;
            default:
                if (lpCtrl->lifecutscl != 0) {
                    LifeCutScl = lpCtrl->lifecutscl;
                }
                lpCtrl->lifecut += LifeCutScl;
                if (!(lpCtrl->lifecut < lpEnePrm->lifecut)) {
                    lpCtrl->lifecut = 0;
                    lpEne->Hp--;
                }
                if (lpEne->Hp > 0) {
                    break;
                }
                memset(&DmgPrm, 0, 0x30);
                DmgPrm.lpEne = lpEne;
                sceVu0CopyVector(&DmgPrm, lpEne->Pos);
                memset(dmyParam, 0, 0x168);
                DmgPrm.lpPrm = dmyParam;
                AnimID = lpCtrl->GetDmgAnimFunc(&DmgPrm);
                if (lpEne->TeamNo == 0) {
                    if (CheckAnimParam(lpEne, 7)) {
                        AnimID = 7;
                    }
                }
                lpCtrl->CalcDmgFunc(lpEne, lpCtrl, AnimID);
            }
        }
    }
}
void SetChainDamage(void *a0 /* r4 */) {
    u8 *s2;
    u8 *s1;
    u8 *s0;
    u32 v1;
    s32 v0;
    float f13;
    float f12;
    float f0;
    void *a0_2;

    v1 = (u32)(u8 *)(MdlMng + 0x17f40);
    s2 = (u8 *)a0;
    s1 = (u8 *)(MdlMng + 0x119c0);
    if ((u32)s1 != v1) {
        do {
            v1 = *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_902612_FIELDS_BUSE_7674BEDE);
            if (v1 != 0 && (s32)*(s32 *)(s1 + DCOMP_OFF_STRUCT_DW_902612_FIELDS_HP_88CBD382) > 0 &&
                (u32)s1 != (u32)s2) {
                s0 = (u8 *)*(s32 *)(s1 + DCOMP_OFF_STRUCT_DW_902612_FIELDS_LPCTRLST_8F05BFE7);
                v1 = *(u8 *)(s0 + 0x180);
                v1 = ({ s32 native_result_0; __asm__("addi %0,%1,-3" : "=r"(native_result_0) :
                    "r"((s32)v1)); native_result_0; });
                switch (v1) {
                default:
                    v1 = *(u16 *)(s0 + 0x1ee);
                    a0_2 = (void *)s2;
                    if (v1 != 0) {
                        break;
                    }
                    v0 = CheckHitTargetMdl(a0_2, (void *)s1, 0);
                    if ((u32)v0 == 0) {
                        break;
                    }
                    f12 = (-(*(float *)(s1 + DCOMP_OFF_STRUCT_DW_902612_FIELDS_POS_0__DBC19E4B) -
                        *(float *)(s2 + DCOMP_OFF_STRUCT_DW_902612_FIELDS_POS_0__DBC19E4B)));
                    f13 = (-(*(float *)(s1 + DCOMP_OFF_STRUCT_DW_902612_FIELDS_POS_2__9E8BE087) -
                        *(float *)(s2 + DCOMP_OFF_STRUCT_DW_902612_FIELDS_POS_2__9E8BE087)));
                    f0 = Math_VectorToAngle(f12, f13);
                    f0 = Math_GetAngleDist(*(float *)(s2 +
                        DCOMP_OFF_STRUCT_DW_902612_FIELDS_ANG_1__AB797FE0), (float)f0);
                    a0_2 = (void *)s1;
                    if (!((float)DCOMP_EXPR_CFEF94067507FB7D(f0) <= 1.5707964f)) {
                        v0 = CheckAnimParam(a0_2, 0x1e);
                        if ((u32)v0 != 0) {
                            v0 = *(s32 *)(s0 + 0x10c);
                            ((void (*)(u32, s32, s32))v0)((u32)(u8 *)s1, (s32)s0, 0x1e);
                            break;
                        } else {
                            v0 = CheckAnimParam((void *)(u8 *)s1, 0x16);
                            if ((u32)v0 == 0) {
                                break;
                            }
                            v0 = *(s32 *)(s0 + 0x10c);
                            ((void (*)(u32, s32, s32))v0)((u32)(u8 *)s1, (s32)s0, 0x16);
                            break;
                        }
                    } else {
                        v0 = CheckAnimParam((void *)(u8 *)s1, 0x20);
                        if ((u32)v0 != 0) {
                            v0 = *(s32 *)(s0 + 0x10c);
                            ((void (*)(u32, s32, s32))v0)((u32)(u8 *)s1, (s32)s0, 0x20);
                            break;
                        } else {
                            v0 = CheckAnimParam((void *)(u8 *)s1, 0x17);
                            if ((u32)v0 != 0) {
                                v0 = *(s32 *)(s0 + 0x10c);
                                ((void (*)(u32, s32, s32))v0)((u32)(u8 *)s1, (s32)s0, 0x17);
                                break;
                            } else {
                                v0 = CheckAnimParam((void *)(u8 *)s1, 0x16);
                                if ((u32)v0 == 0) {
                                    break;
                                }
                                v0 = *(s32 *)(s0 + 0x10c);
                                ((void (*)(u32, s32, s32))v0)((u32)(u8 *)s1, (s32)s0, 0x16);
                            }
                        }
                    }
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    break;
                }
            }
            s1 = (u8 *)(s1 + 0x1c0);
        } while (s1 != (u8 *)(MdlMng + 0x17f40));
    }
    return;
}
