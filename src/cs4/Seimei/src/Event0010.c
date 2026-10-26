#include "common.h"

/* PlayS0010Event004 @ 0x2113F0 .. 0x211484 (0x94 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int CheckEventFlag(signed int);
extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern void SetEventModelDrawAndHit(void *, unsigned char);
extern u16 MdlMng[];

/* InitS0010Event004 @ 0x211490 .. 0x211594 (0x104 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x2114c4 if (..) goto .L00211518
 */

extern void FreeMdlMng(void *);
extern u8 GameSt[];



/* InitS0010Event003 @ 0x2119E0 .. 0x211A28 (0x48 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x211a00 if (..) goto .L00211A18
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u8 GameSt[];



/* InitS0010Event002 @ 0x211D90 .. 0x211E28 (0x98 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x211db0 if (..) goto .L00211DD0
 *   cfg: kept branch: 0x211dbc if (..) goto .L00211DE0
 *   cfg: kept goto: 0x211dd0 -> .L00211E18
 */

extern void EasyEneAppear(signed int);
extern void SetEventFlag(signed int);

/* ActiS0010Event001 @ 0x211E30 .. 0x211F70 (0x140 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42c80000 at 0x211ec8
 */

extern signed int KnMsgMng_SendMsg(signed int);
extern signed int SND_Play3D(signed int, signed short, signed short, void *, float);
extern void SetMyActFreeFlag(unsigned char);
extern void SetMyControlOff(void);

/* PlayS0010Event001 @ 0x211F70 .. 0x2120D4 (0x164 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x211ffc
 *   stack: address of the slot at 0x40 escapes at 0x21202c
 *   fpu: float literal 0x3e99999a at 0x2120a4
 *   fpu: float literal 0x42f00000 at 0x2120a8
 *   stack: address of the slot at 0x30 escapes at 0x2120ac
 */

extern signed int SFX_Create_OnAng(unsigned short, float *, float *);
extern void SetMyControlOn(void);
extern void SetBlast(float, float, float *, float *, signed int);
extern u32 V0[];

/* PlayS0010Event000 @ 0x212130 .. 0x21224C (0x11c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @915 -> 0x250340
 *   literal: @920 -> 0x250350
 *   fpu: float literal 0x00000000 at 0x2121cc
 *   fpu: float literal 0x00000000 at 0x2121f4
 *   stack: address of the slot at 0x30 escapes at 0x212200
 *   fpu: float literal 0x40000000 at 0x212220
 *   literal: @920 initializes the 16-byte local at 0x30
 *   literal: @915 initializes the 16-byte local at 0x40
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int CheckSquareRange(float *, float *);
extern signed int CheckMyControlOff(void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetMyFall(void *, float, float *);
extern void ResetEventFlag(signed int);
extern void SetE044RandomAppear(float *, signed int, signed int, float);
/* PlayS0010Event002 @ 0x211A30 .. 0x211D8C (0x35c bytes, frame 0x70) */
/*
 * dcomp notes:
 *   quad: a1: 128-bit web split from its scalar uses
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @988 -> 0x250360
 *   literal: @992 -> 0x250370
 *   literal: @997 -> 0x250380
 *   stack: address of the slot at 0x60 escapes at 0x211a98
 *   fpu: mov.s at 0x211b4c is a float copy
 *   fpu: mov.s at 0x211b54 is a float copy
 *   fpu: float literal 0x40490fdb at 0x211b60
 *   fpu: float literal 0x00000000 at 0x211b64
 *   fpu: mov.s at 0x211b78 is a float copy
 *   fpu: mov.s at 0x211b7c is a float copy
 *   fpu: mov.s at 0x211b84 is a float copy
 *   fpu: float literal 0x40490fdb at 0x211b98
 *   fpu: float literal 0x40c90fdb at 0x211b9c
 *   fpu: mov.s at 0x211bb4 is a float copy
 *   fpu: mov.s at 0x211bc0 is a float copy
 *   fpu: mov.s at 0x211bd0 is a float copy
 *   fpu: float literal 0x40490fdb at 0x211be4
 *   fpu: float literal 0x40c90fdb at 0x211be8
 *   fpu: mov.s at 0x211c00 is a float copy
 *   fpu: mov.s at 0x211c0c is a float copy
 *   fpu: float literal 0x40c90fdb at 0x211c1c
 *   fpu: float literal 0x40490fdb at 0x211c30
 *   fpu: float literal 0x00000000 at 0x211c34
 *   fpu: float literal 0x40c90fdb at 0x211c54
 *   fpu: mtc1 reinterprets v0 at 0x211c78
 *   fpu: float literal 0x3f800000 at 0x211cec
 *   fpu: float literal 0x3d4ccccd at 0x211d44
 *   fpu: float literal 0x00000000 at 0x211d48
 *   literal: @997 initializes the 16-byte local at 0x40
 *   literal: @992 initializes the 16-byte local at 0x50
 *   literal: @988 initializes the 16-byte local at 0x60
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int CheckSquareRange(float *, float *);
extern void EasyEneAppearEx(signed int, unsigned short, unsigned char);
extern float Math_VectorToAngle(float, float);
extern void SetEventFlag(signed int);
extern void EventEneHitCheck(void *);
extern float Math_GetDistXZ(float *, float *);
extern u32 L988[];
extern u32 L992[];
extern u32 L997[];

struct dw_2924721_fields;
struct dw_2934514_fields;
#ifndef PROTO_DW_2933149_FIELDS
#define PROTO_DW_2933149_FIELDS
struct dw_2933149_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_2930856_FIELDS
#define PROTO_DW_2930856_FIELDS
struct dw_2930856_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_2930534_FIELDS
#define PROTO_DW_2930534_FIELDS
struct dw_2930534_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_2924721_fields *lpMdl; };
#endif
#ifndef PROTO_DW_2924721_FIELDS
#define PROTO_DW_2924721_FIELDS
struct dw_2924721_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_2934514_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_2924721_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_2933149_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_2930856_fields flags; unsigned char _pad1[3]; struct dw_2930534_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_2927398_FIELDS
#define PROTO_DW_2927398_FIELDS
struct dw_2927398_fields { void *InitFunc; void *PlayFunc; void *ActiFunc; int State[10]; struct dw_2924721_fields *lpMdl[10]; unsigned char _pad0[4]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ALPHA_A5D24ECB_DEFINED
#define DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ALPHA_A5D24ECB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ALPHA_A5D24ECB = (int)&(((struct dw_2924721_fields *)0)->Alpha) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ANG_1__A615D873_DEFINED
#define DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ANG_1__A615D873_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ANG_1__A615D873 = (int)&(((struct dw_2924721_fields *)0)->Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_0__89458F54_DEFINED
#define DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_0__89458F54_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_0__89458F54 = (int)&(((struct dw_2924721_fields *)0)->Pos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_2__87718A46_DEFINED
#define DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_2__87718A46_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_2__87718A46 = (int)&(((struct dw_2924721_fields *)0)->Pos[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155_DEFINED
#define DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155 = (int)&(((struct dw_2927398_fields *)0)->State[2]) - 0 };
#endif
#define NORM_ANG(a) (((a) + 3.1415927f >= 0.0f) ? ((a) - 6.2831855f * (float)(s32)(((a) + 3.1415927f) / 6.2831855f)) : (6.2831855f + ((a) - 6.2831855f * (float)(s32)(((a) + 3.1415927f) / 6.2831855f))))

/* PlayS0010Event003 @ 0x2115A0 .. 0x2119D8 (0x438 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   quad: a1: 128-bit web split from its scalar uses
 *   literal: @1025 -> 0x250390
 *   stack: address of the slot at 0x50 escapes at 0x2115f8
 *   fpu: mov.s at 0x2116e0 is a float copy
 *   fpu: mov.s at 0x2116e8 is a float copy
 *   fpu: float literal 0x40490fdb at 0x2116f4
 *   fpu: float literal 0x00000000 at 0x2116f8
 *   fpu: mov.s at 0x21170c is a float copy
 *   fpu: mov.s at 0x211710 is a float copy
 *   fpu: mov.s at 0x211718 is a float copy
 *   fpu: float literal 0x40490fdb at 0x21172c
 *   fpu: float literal 0x40c90fdb at 0x211730
 *   fpu: mov.s at 0x211748 is a float copy
 *   fpu: mov.s at 0x211754 is a float copy
 *   fpu: mov.s at 0x211764 is a float copy
 *   fpu: float literal 0x40490fdb at 0x211778
 *   fpu: float literal 0x40c90fdb at 0x21177c
 *   fpu: mov.s at 0x211794 is a float copy
 *   fpu: mov.s at 0x2117a0 is a float copy
 *   fpu: float literal 0x40c90fdb at 0x2117b0
 *   fpu: float literal 0x3c64b87b at 0x2117c8
 *   fpu: mov.s at 0x2117cc is a float copy
 *   fpu: float literal 0x00000000 at 0x2117dc
 *   fpu: mov.s at 0x2117f8 is a float copy
 *   fpu: mov.s at 0x21180c is a float copy
 *   fpu: float literal 0x3c64b87b at 0x211818
 *   fpu: float literal 0x40490fdb at 0x211834
 *   fpu: float literal 0x00000000 at 0x211838
 *   fpu: float literal 0x40c90fdb at 0x211858
 *   fpu: float literal 0x40c90fdb at 0x211880
 *   fpu: float literal 0x00000000 at 0x2118a0
 *   fpu: float literal 0x3ca3d70a at 0x2118e0
 *   fpu: float literal 0x00000000 at 0x2118f4
 *   fpu: float literal 0x40c00000 at 0x21193c
 *   fpu: float literal 0x40400000 at 0x211950
 *   fpu: float literal 0x3f800000 at 0x211998
 *   literal: @1025 initializes the 16-byte local at 0x50
 *   cfg: kept goto: 0x211908 -> .L002119B8
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 GetCurCamID();
extern void EasyEneAppearEx(signed int, unsigned short, unsigned char);
extern void SetEventFlag(signed int);
extern float Math_VectorToAngle(float, float);
extern float Math_GetAngleDist(float, float);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void EventEneHitCheck(void *);
extern float Math_GetDist2(float *, float *);
extern unsigned int CheckMyDash(void *);
extern u32 L1025[];

struct dw_2924721_fields;
struct dw_2934514_fields;
#ifndef PROTO_DW_2933149_FIELDS
#define PROTO_DW_2933149_FIELDS
struct dw_2933149_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_2930856_FIELDS
#define PROTO_DW_2930856_FIELDS
struct dw_2930856_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_2930534_FIELDS
#define PROTO_DW_2930534_FIELDS
struct dw_2930534_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_2924721_fields *lpMdl; };
#endif
#ifndef PROTO_DW_2924721_FIELDS
#define PROTO_DW_2924721_FIELDS
struct dw_2924721_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_2934514_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_2924721_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_2933149_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_2930856_fields flags; unsigned char _pad1[3]; struct dw_2930534_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_2927398_FIELDS
#define PROTO_DW_2927398_FIELDS
struct dw_2927398_fields { void *InitFunc; void *PlayFunc; void *ActiFunc; int State[10]; struct dw_2924721_fields *lpMdl[10]; unsigned char _pad0[4]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ALPHA_A5D24ECB_DEFINED
#define DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ALPHA_A5D24ECB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ALPHA_A5D24ECB = (int)&(((struct dw_2924721_fields *)0)->Alpha) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ANG_1__A615D873_DEFINED
#define DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ANG_1__A615D873_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ANG_1__A615D873 = (int)&(((struct dw_2924721_fields *)0)->Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_0__89458F54_DEFINED
#define DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_0__89458F54_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_0__89458F54 = (int)&(((struct dw_2924721_fields *)0)->Pos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_2__87718A46_DEFINED
#define DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_2__87718A46_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_2__87718A46 = (int)&(((struct dw_2924721_fields *)0)->Pos[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2924721_FIELDS__160__INDEXANIM_6B336129_DEFINED
#define DCOMP_OFF_STRUCT_DW_2924721_FIELDS__160__INDEXANIM_6B336129_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2924721_FIELDS__160__INDEXANIM_6B336129 = (int)&(((struct dw_2924721_fields *)0)[160].IndexAnim) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2924721_FIELDS_LPCTRLST_DAEF4DAE_DEFINED
#define DCOMP_OFF_STRUCT_DW_2924721_FIELDS_LPCTRLST_DAEF4DAE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2924721_FIELDS_LPCTRLST_DAEF4DAE = (int)&(((struct dw_2924721_fields *)0)->lpCtrlSt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_0__D7B02039_DEFINED
#define DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_0__D7B02039_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_0__D7B02039 = (int)&(((struct dw_2927398_fields *)0)->State[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_1__A53B60BC_DEFINED
#define DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_1__A53B60BC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_1__A53B60BC = (int)&(((struct dw_2927398_fields *)0)->State[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155_DEFINED
#define DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155 = (int)&(((struct dw_2927398_fields *)0)->State[2]) - 0 };
#endif
#define NORM_ANG(a) (((a) + 3.1415927f >= 0.0f) ? ((a) - 6.2831855f * (float)(s32)(((a) + 3.1415927f) / 6.2831855f)) : (6.2831855f + ((a) - 6.2831855f * (float)(s32)(((a) + 3.1415927f) / 6.2831855f))))

/* InitS0010Event000 @ 0x212250 .. 0x21234C (0xfc bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x2122f4
 *   cfg: kept branch: 0x2122e0 if (..) goto .L00212318
 *   cfg: kept goto: 0x2122f0 -> .L00212338
 *   v0#11 is the pointer held in a0+0x3c
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetAnimLastFrame(void *);

/* SetEventFuncS0010 @ 0x212350 .. 0x212404 (0xb4 bytes) */
/*
 * dcomp notes:
 *   repo declaration vs inferred signature: return void vs inferred u8 *
 */


extern u32 EventMngSt[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetEventFuncS0010(void);
static void InitS0010Event000(void *a0 );
static void PlayS0010Event000(void *a0 );
static void InitS0010Event001(void *a0 );
static void PlayS0010Event001(void *a0 );
static void ActiS0010Event001(void *a0 , unsigned int a1 );
static void InitS0010Event002(void *a0 );
static void PlayS0010Event002(void *a0 );
static void InitS0010Event003(void *a0 );
static void PlayS0010Event003(void *a0 );
static void InitS0010Event004(void *a0 );
static void PlayS0010Event004(void *a0 );












void SetEventFuncS0010(void) {
    u8 *v1;

    v1 = (u8 *)InitS0010Event000;
    *(u32 *)EventMngSt = (u32)InitS0010Event000;
    v1 = (u8 *)PlayS0010Event000;
    *(u32 *)((u8 *)&EventMngSt + 4) = (u32)PlayS0010Event000;
    v1 = (u8 *)InitS0010Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x60) = (u32)InitS0010Event001;
    v1 = (u8 *)PlayS0010Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x64) = (u32)PlayS0010Event001;
    v1 = (u8 *)ActiS0010Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x68) = (u32)ActiS0010Event001;
    v1 = (u8 *)InitS0010Event002;
    *(u32 *)((u8 *)&EventMngSt + 0xc0) = (u32)InitS0010Event002;
    v1 = (u8 *)PlayS0010Event002;
    *(u32 *)((u8 *)&EventMngSt + 0xc4) = (u32)PlayS0010Event002;
    v1 = (u8 *)InitS0010Event003;
    *(u32 *)((u8 *)&EventMngSt + 0x120) = (u32)InitS0010Event003;
    v1 = (u8 *)PlayS0010Event003;
    *(u32 *)((u8 *)&EventMngSt + 0x124) = (u32)PlayS0010Event003;
    v1 = (u8 *)InitS0010Event004;
    *(u32 *)((u8 *)&EventMngSt + 0x180) = (u32)InitS0010Event004;
    v1 = (u8 *)PlayS0010Event004;
    *(u32 *)((u8 *)&EventMngSt + 0x184) = (u32)PlayS0010Event004;
    return;
}


static void InitS0010Event000(void *a0 /* r4 */) {
    u8 *s1;
    s32 a1;
    u8 *s0;
    u32 v0;
    u32 v1;

    a1 = 0x2b;
    s1 = (u8 *)a0;
    a0 = (void *)(s32)1;
    s0 = (u8 *)MdlMng + 0x5400;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
    a0 = (void *)(s32)1;
    v0 = (u32)(v0) * (u32)(7);
    a1 = 0x2c;
    v0 = v0 << 6;
    v0 = (s32)(s0 + v0);
    *(u32 *)(s1 + 0x34) = v0;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
    a0 = (void *)(s32)1;
    v0 = (u32)(v0) * (u32)(7);
    a1 = 0x2d;
    v0 = v0 << 6;
    v0 = (s32)(s0 + v0);
    *(u32 *)(s1 + 0x38) = v0;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
    a0 = (void *)(s32)(v0 << 3);
    v0 = (s32)((u8 *)a0 - v0);
    v1 = 1;
    v0 = v0 << 6;
    v0 = (s32)(s0 + v0);
    *(u32 *)(s1 + 0x3c) = v0;
    v0 = GameSt[0x14];
    a0 = (void *)(s32)0x546;
    if (v0 == v1) {
        v0 = CheckEventFlag((signed int)a0);
        if (v0 == 0) {
            goto _L00212318;
        }
    }
    a0 = (void *)*(s32 *)(s1 + 0x34);
    a1 = 1;
    ChangeAnimParam(a0, a1, 0.0f);
    a0 = (void *)*(s32 *)(s1 + 0x34);
    SetAnimLastFrame(a0);
    a0 = (void *)*(s32 *)(s1 + 0x38);
    FreeMdlMng(a0);
    *(u32 *)(s1 + 0xc) = 0;
    goto _L00212338;
    _L00212318:;
    v1 = *(s32 *)(s1 + 0x34);
    a1 = 1;
    a0 = (void *)0x41200000;
    *(u8 *)((v1 + 2)) = a1;
    v1 = *(s32 *)(s1 + 0x3c);
    *(u32 *)((v1 + 0x24)) = 0x41200000;
    *(u32 *)(s1 + 0xc) = a1;
    _L00212338:;
    return;
}

static void PlayS0010Event000(void *a0 /* r4 */) {
    u8 *s1;
    u32 v1;
    u8 *s0;
    u32 v0;
    u32 a1;
    float f12;

    v1 = 2;
    s1 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    s0 = (u8 *)MdlMng + 0x11800;
    switch ((u32)(s32)a0) {
    case 1:
        a0 = (void *)(s32)0x3ea;
        v0 = CheckEventFlag((signed int)a0);
        v1 = 2;
        if (v0 == 0) {
            break;
        }
        *(u32 *)(s1 + 0xc) = v1;
        break;
    case 2:
        v0 = 0x250340;
        a0 = (void *)(s0 + 0x20);
        {
            struct stackFrame_40 { u8 b[16]; } stackFrame_40 __attribute__((aligned(16))) = {{0xcd,
                0xcc, 0x44, 0x42, 0x00, 0x00, 0x20, 0x41, 0x33, 0x33, 0x4d, 0x42, 0xcd, 0xcc, 0x2c,
                0x41}};
            a1 = (u32)((u8 *)&stackFrame_40);
            v0 = CheckSquareRange((float *)a0, (float *)a1);
            a0 = (void *)s0;
            if (v0 == 0) {
                break;
            }
            v0 = CheckMyControlOff(a0);
            if (v0 == 0) {
                break;
            }
            v0 = 0x250350;
            f12 = 0.0f;
            {
                struct stackFrame_30 { u8 b[16]; } stackFrame_30 __attribute__((aligned(16))) =
                    {{0xcd, 0xcc, 0x48, 0x42, 0x29, 0x5c, 0x0f, 0xbd, 0x66, 0x66, 0x1e, 0x41, 0x00,
                    0x00, 0x80, 0x3f}};
                v1 = (u32)((u8 *)&stackFrame_30);
                v0 = *(s32 *)(s1 + 0x34);
                *(u8 *)((v0 + 2)) = 0;
                a0 = (void *)*(s32 *)(s1 + 0x34);
                a1 = 1;
                ChangeAnimParam(a0, a1, 0.0f);
                a0 = (void *)*(s32 *)(s1 + 0x38);
                FreeMdlMng(a0);
                v0 = *(s32 *)(s1 + 0x3c);
                f12 = 0.0f;
                a0 = (void *)s0;
                *(u32 *)((v0 + 0x24)) = 0;
                SetMyFall(a0, 0.0f, (float *)((u8 *)&stackFrame_30));
                a0 = (void *)(s32)0x546;
                SetEventFlag((signed int)a0);
                a0 = (void *)(s32)0x536;
                ResetEventFlag((signed int)a0);
                a0 = (void *)(s0 + 0x20);
                f12 = 2.0f;
                a1 = 3;
                SetE044RandomAppear((float *)a0, a1, 0x64, 2.0f);
                v1 = 3;
                *(u32 *)(s1 + 0xc) = v1;
            }
        }
    }
    return;
}

/* InitS0010Event001 @ 0x2120E0 .. 0x212128 (0x48 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x212104 if (..) goto .L00212118
 *   declaration vs inferred signature: return void vs inferred u32
 */



static void InitS0010Event001(void *a0 /* r4 */) {
    u32 v1;
    u32 *s0;
    u32 v0;

    *(u32 *)(((u8 *)a0 + 0x30)) = 0;
    v1 = *(u8 *)((u8 *)&GameSt + 0x14);
    s0 = (u32 *)a0;
    if (v1 == 0) {
        a0 = (void *)(s32)0x6c3;
        v0 = CheckEventFlag((signed int)a0);
        if (v0 == 0) {
            goto _L00212118;
        }
    }
    v1 = 3;
    *(u32 *)(((u8 *)s0 + 0x10)) = v1;
    _L00212118:;
    return;
}

static void PlayS0010Event001(void *a0 /* r4 */) {
    u8 *s1;
    u8 *t0;
    s32 a3;
    u8 *s0;
    u32 a2;
    u32 a1;
    u32 v1;
    s32 v0;
    float f1;
    float f0;
    void *a0_2;
    u8 stackFrame_40[16] __attribute__((aligned(16)));
    u8 stackFrame_30[16] __attribute__((aligned(16)));

    a1 = 0x2b;
    s1 = (u8 *)a0;
    a0_2 = (void *)(s32)1;
    s0 = (u8 *)(MdlMng + 0x8c00);
    v0 = GetMdlMngIndexByCtrlId((signed int)a0_2, a1);
    a0_2 = (void *)*(s32 *)(s1 + 0x10);
    a2 = v0 + 0x30;
    v1 = (u32)MdlMng;
    a1 = a2 * (u32)(0x1c0);
    a3 = 2;
    t0 = (u8 *)((u8 *)MdlMng + a1);
    switch ((u32)(s32)a0_2) {
    case 1:
        a0_2 = (void *)*(s32 *)(s1 + 0x30);
        v1 = 0x1e;
        a0_2 = (void *)((u8 *)a0_2 + 1);
        *(u32 *)(s1 + 0x30) = (s32)a0_2;
        if ((u32)(s32)a0_2 != v1) {
            break;
        }
        a0_2 = (void *)(s32)0x1db;
        f0 = 1.0f;
        a2 = (u32)V0;
        *(f32 *)((u8 *)&stackFrame_40[0]) = *(float *)(t0 + 0x20);
        f1 = *(float *)(t0 + 0x24);
        ((f32 *)stackFrame_40)[1] = (f1 - 1.0f);
        ((f32 *)stackFrame_40)[2] = *(float *)(t0 + 0x28);
        f0 = *(float *)(t0 + 0x2c);
        ((f32 *)stackFrame_40)[3] = f0;
        *(u32 *)(s1 + 0x30) = 0;
        *(u32 *)(s1 + 0x10) = a3;
        SFX_Create_OnAng((unsigned short)a0_2, (float *)((u8 *)&stackFrame_40[0]), (float *)V0);
        break;
    case 2:
        a0_2 = (void *)*(s32 *)(s1 + 0x30);
        v1 = 0x3c;
        a0_2 = (void *)((u8 *)a0_2 + 1);
        *(u32 *)(s1 + 0x30) = (s32)a0_2;
        if ((u32)(s32)a0_2 != v1) {
            break;
        }
        v0 = 3;
        *(f32 *)((u8 *)&stackFrame_30[0]) = *(float *)(t0 + 0x20);
        ((f32 *)stackFrame_30)[1] = *(float *)(s0 + 0x24);
        ((f32 *)stackFrame_30)[2] = *(float *)(t0 + 0x28);
        f0 = *(float *)(t0 + 0x2c);
        ((f32 *)stackFrame_30)[3] = f0;
        *(u32 *)(s1 + 0x30) = 0;
        *(u32 *)(s1 + 0x10) = v0;
        SetMyActFreeFlag(0);
        SetMyControlOn();
        v0 = 0x3e990000;
        a1 = (s32)(s0 + 0x20);
        v1 = 0x3e990000 | 0x999a;
        a2 = 0x28;
        SetBlast(0.300000012f, 120.0f, (float *)((u8 *)&stackFrame_30[0]), (float *)a1, a2);
        a0_2 = (void *)(s32)0x6c3;
        SetEventFlag((signed int)a0_2);
    }
    return;
}

static void ActiS0010Event001(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u8 *s0;
    u32 v1;
    u32 v0;

    v1 = 1;
    s0 = (u8 *)a0;
    switch ((u32)(s32)a1) {
    case 1:
        v0 = *(s32 *)(s0 + 0x10);
        a0 = (void *)(s32)0x6c2;
        if (v0 == 0) {
            v0 = CheckEventFlag((signed int)a0);
            if (v0 == 0) {
                v0 = 0x60000;
                a0 = (void *)(0x60000 | 0x41d1);
                KnMsgMng_SendMsg((signed int)a0);
                a0 = (void *)(s32)0x6c2;
                SetEventFlag((signed int)a0);
                break;
            } else {
                a0 = (void *)(s32)0x6c3;
                v0 = CheckEventFlag((signed int)a0);
                a0 = (void *)(s32)1;
                if (v0 == 0) {
                    a1 = 0x2b;
                    v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
                    a1 = v0 + 0x30;
                    a0 = (void *)(s32)((u32)a1 << 3);
                    a1 = (s32)((u8 *)a0 - a1);
                    v1 = (u32)MdlMng;
                    a0 = (void *)(s32)0x84c;
                    v1 = (s32)((u8 *)MdlMng + (u32)((u32)a1 << 6));
                    a1 = 0x40;
                    SND_Play3D((signed int)a0, a1, 0, (void *)(s32)(v1 + 0x20), 100.0f);
                    *(u32 *)(s0 + 0x30) = 0;
                    a0 = (void *)(s32)1;
                    *(u32 *)(s0 + 0x10) = (s32)a0;
                    SetMyActFreeFlag((unsigned char)a0);
                    SetMyControlOff();
                    break;
                } else {
                    v0 = 0x60000;
                    a0 = (void *)(0x60000 | 0x41d2);
                    KnMsgMng_SendMsg((signed int)a0);
                    break;
                }
            }
        } else {
            v1 = GameSt[0x14];
            v0 = 0x60000;
            if (v1 == 0) {
                a0 = (void *)(v0 | 0x41d2);
                KnMsgMng_SendMsg((signed int)a0);
                break;
            } else {
                v0 = 2;
                a0 = (void *)(s32)0x546;
                if (v1 != v0) {
                    v0 = CheckEventFlag((signed int)a0);
                    if (v0 == 0) {
                        break;
                    }
                }
                v0 = 0x60000;
                a0 = (void *)(0x60000 | 0x41d3);
                KnMsgMng_SendMsg((signed int)a0);
            }
        }
    }
    return;
}


static void InitS0010Event002(void *a0 /* r4 */) {
    u32 v1;
    u32 *s0;
    s32 v0;

    v1 = *(u8 *)((u8 *)&GameSt + 0x14);
    s0 = (u32 *)a0;
    if (v1 == 0) {
        a0 = (void *)(s32)0x6c6;
        v0 = CheckEventFlag((signed int)a0);
        a0 = (void *)(s32)0x6cc;
        if ((u32)v0 != 0) {
            goto _L00211DD0;
        }
        v0 = CheckEventFlag((signed int)a0);
        if ((u32)v0 != 0) {
            goto _L00211DE0;
        }
    }
    _L00211DD0:;
    v1 = 4;
    *(u32 *)(((u8 *)s0 + 0x14)) = v1;
    goto _L00211E18;
    _L00211DE0:;
    a0 = (void *)(s32)0x6c5;
    v0 = CheckEventFlag((signed int)a0);
    if ((u32)v0 != 0) {
        v0 = 4;
        a0 = (void *)(s32)5;
        *(u32 *)(((u8 *)s0 + 0x14)) = v0;
        EasyEneAppear((signed int)a0);
        a0 = (void *)(s32)6;
        EasyEneAppear((signed int)a0);
        a0 = (void *)(s32)7;
        EasyEneAppear((signed int)a0);
        a0 = (void *)(s32)0x6c6;
        SetEventFlag((signed int)a0);
    }
    _L00211E18:;
    return;
}
static void PlayS0010Event002(void *a0 /* r4 */) {
    u8 *s0;
    s32 xt3;
    u32 xt5;
    u32 xt2;
    u32 a0_index; // a0
    u32 a0_index_; // a0
    float f0;
    float f12;
    u32 a0_index__; // a0

    xt5 = (u32)L988;
    s0 = (u8 *)a0;
    {
        struct stackFrame_60 { u8 b[16]; } stackFrame_60 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x38, 0x42, 0x00, 0x00, 0x80, 0xbf, 0x66, 0x66, 0xe6, 0xc0, 0x00, 0x00, 0x00,
            0x00}};
        xt5 = 3;
        xt5 = (u32)((u8 *)&stackFrame_60);
        xt5 = *(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155);
        xt2 = (u32)(u8 *)(0x8c00 + MdlMng);
        a0 = (void *)(2);
        switch (xt5) {
        case 0:
            xt3 = (0x20 + xt2);
            a0 = (void *)xt3;
            xt2 = (u32)L992;
            {
                struct stackFrame_50 { u8 b[16]; } stackFrame_50 __attribute__((aligned(16))) =
                    {{0x00, 0x00, 0x08, 0x42, 0x00, 0x00, 0x80, 0xc0, 0x00, 0x00, 0x12, 0x42, 0x9a,
                    0x99, 0x59, 0xc0}};
                xt2 = CheckSquareRange((float *)a0, (float *)((u8 *)&stackFrame_50));
                if (xt2 == 0) {
                    break;
                }
                *(u32 *)(DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155 + s0) = 1;
                break;
            }
        case 1:
            xt2 = (xt2 + 0x20);
            a0 = (void *)xt2;
            xt2 = (u32)L997;
            {
                struct stackFrame_40 { u8 b[16]; } stackFrame_40 __attribute__((aligned(16))) =
                    {{0x00, 0x00, 0x08, 0x42, 0x9a, 0x99, 0x19, 0xc0, 0x00, 0x00, 0x12, 0x42, 0x9a,
                    0x99, 0xd9, 0xbf}};
                xt2 = CheckSquareRange((float *)a0, (float *)((u8 *)&stackFrame_40));
                if (xt2 == 0) {
                    break;
                }
                *(u32 *)(s0 + DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155) = 2;
                a0 = (void *)(4);
                xt3 = (u8)(s16)a0;
                xt2 = (u32)MdlMng;
                EasyEneAppearEx((signed int)xt3, 0xb, 1);
                xt2 = GetMdlMngIndexByCtrlId(2, 4);
                s0 = (u8 *)((u8 *)MdlMng + ((((0xa1)) + xt2) * (0x1c0)));
                f0 = *(float *)(s0 + DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_0__89458F54);
                f12 = *(float *)((u8 *)&stackFrame_60);
                f12 = (f12 - f0);
                f0 = *(float *)(s0 + DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_2__87718A46);
                f0 = (-((*(float *)((u8 *)&stackFrame_60 + 0x8)) - f0));
                f12 = (-f12);
                f12 = NORM_ANG(Math_VectorToAngle(f12, f0));
                f0 = NORM_ANG(f12);
                *(f32 *)(DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ANG_1__A615D873 + s0) = f0;
                SetEventFlag(0x6c5);
                break;
            }
        case 2:
            xt2 = GetMdlMngIndexByCtrlId((signed int)a0, 4);
            xt2 = (0xa1 + xt2);
            xt3 = (s32)((u8 *)MdlMng + (xt2 * (0x1c0)));
            xt2 = (u32)MdlMng;
            EventEneHitCheck((void *)xt3);
            f0 = Math_GetDistXZ((float *)((u8 *)&stackFrame_60), (float *)(xt3 + 0x20));
            if (!(f0 < 1.0f)) {
                break;
            }
            *(u32 *)(0x14 + s0) = 3;
            break;
        case 3:
            xt2 = GetMdlMngIndexByCtrlId(2, 4);
            xt3 = (s32)((u8 *)MdlMng + ((xt2 + (0xa1)) * (0x1c0)));
            EventEneHitCheck((void *)xt3);
            xt5 = (xt3 + DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ALPHA_A5D24ECB);
            f12 = ((*(float *)xt5) - 0.05f);
            xt2 = (u32)MdlMng;
            *(f32 *)(xt5) = f12;
            xt5 = (DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ALPHA_A5D24ECB + (u16)xt3);
            if (!(f12 <= 0.0f)) {
                break;
            }
            xt5 = xt3;
            FreeMdlMng((void *)xt5);
            *(u32 *)(s0 + 0x14) = 4;
        }
        return;
    }
}

static void InitS0010Event003(void *a0 /* r4 */) {
    u32 v1;
    u32 *s0;
    u32 v0;

    v1 = *(u8 *)((u8 *)&GameSt + 0x14);
    s0 = (u32 *)a0;
    if (v1 == 0) {
        a0 = (void *)(s32)0x6ce;
        v0 = CheckEventFlag((signed int)a0);
        if (v0 == 0) {
            goto _L00211A18;
        }
    }
    v1 = 2;
    *(u32 *)(((u8 *)s0 + 0xc)) = v1;
    _L00211A18:;
    return;
}
static void PlayS0010Event003(void *a0 /* r4 */) {
    u8 *s2;
    float f0;
    u32 xt2;
    u32 xt1;
    s32 a1;
    u8 *s1;
    u8 *s0;
    float f1;

    s2 = (u8 *)a0;
    xt1 = (u32)L1025;
    {
        struct stackFrame_50 { u8 b[16]; } stackFrame_50 __attribute__((aligned(16))) = {{0x33,
            0x33, 0x31, 0x42, 0xcd, 0xcc, 0xcc, 0xbf, 0xec, 0x51, 0xd8, 0xc0, 0x00, 0x00, 0x00,
            0x00}};
        xt2 = (u32)((u8 *)&stackFrame_50);
        xt1 = 1;
        a0 = (void *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_0__D7B02039);
        switch ((s32)a0) {
        case 0:
            a1 = CheckEventFlag(0x3e7);
            if (a1 == 0) {
                break;
            }
            a1 = GetCurCamID();
            xt2 = 1;
            if (a1 != xt2) {
                break;
            }
            *(u32 *)(DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_0__D7B02039 + (s32)(s32)s2) = xt2;
            a0 = (void *)8;
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_1__A53B60BC) = 0;
            *(u32 *)(DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155 + (s32)s2) = 0;
            EasyEneAppearEx((signed int)a0, 0, xt2);
            xt1 = ((u32)MdlMng);
            xt1 = 1;
            SetEventFlag(0x6ce);
            break;
        case 1:
            a1 = GetMdlMngIndexByCtrlId(2, 8);
            xt2 = (0xa1 + (s32)a1);
            xt2 = (7 * xt2);
            a0 = (void *)*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_1__A53B60BC);
            a1 = (xt2) << 6;
            s1 = (u8 *)((u8 *)MdlMng + a1);
            s0 = (u8 *)*(s32 *)(s1 + DCOMP_OFF_STRUCT_DW_2924721_FIELDS_LPCTRLST_DAEF4DAE);
            a1 = 2;
            switch ((s32)a0) {
            case 0:
                a1 = *(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155);
                a1 = a1 + 1;
                *(u32 *)((u32)s2 + DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155) = a1;
                if (0x1e0 >= a1) {
                    break;
                }
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_1__A53B60BC) = xt1;
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155) = 0;
                break;
            case 1:
                f0 = *(float *)(s1 + DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_0__89458F54);
                f1 = *(float *)((u8 *)&stackFrame_50);
                f1 = (f1 - f0);
                f0 = *(float *)(s1 + DCOMP_OFF_STRUCT_DW_2924721_FIELDS_POS_2__87718A46);
                f0 = (-((*(float *)((u8 *)&stackFrame_50 + 0x8)) - f0));
                f1 = (-f1);
                f1 = NORM_ANG(Math_VectorToAngle(f1, f0));
                f0 = (*(f32 *)(s1 + 0x34) -= 0.013959999f);
                f0 = Math_GetAngleDist(*(float *)(s1 +
                    DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ANG_1__A615D873), (float)f1);
                if (f0 < 0.0f) {
                    f0 = *(float *)(DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ANG_1__A615D873 + s1);
                    f0 = (-Math_GetAngleDist(f0, (float)f1));
                } else {
                    f0 = *(float *)(s1 + DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ANG_1__A615D873);
                    f0 = Math_GetAngleDist(f0, (float)f1);
                }
                if (!(f0 < 0.013959999f)) {
                    break;
                }
                *(u32 *)(DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_1__A53B60BC + s2) = 2;
                f0 = NORM_ANG(f1);
                *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ANG_1__A615D873) = f0;
                a0 = (void *)s1;
                ChangeAnimParam(a0, 0xa, 0.0f);
                *(u32 *)(DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155 + s2) = 0;
                break;
            case 2:
                a1 = *(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155);
                a1 = a1 + 1;
                *(u32 *)((s32)s2 + DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155) = a1;
                if (a1 > 0xf0) {
                    *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ALPHA_A5D24ECB) = (*(float
                        *)(s1 + DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ALPHA_A5D24ECB) - 0.02f);
                }
                a0 = (void *)s1;
                f1 = *(float *)(DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ALPHA_A5D24ECB + s1);
                if (!(f1 <= 0.0f)) {
                    break;
                }
                FreeMdlMng(a0);
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_0__D7B02039) = 2;
                *(u32 *)(DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_2__FBDAD155 + (u32)s2) = 0;
                return;
            }
            EventEneHitCheck((void *)s1);
            f0 = Math_GetDist2((float *)s1, (float *)(u8 *)(0x8c10 + MdlMng));
            if (!(f0 <= 6.0f)) {
                break;
            }
            if (!(f0 < 3.0f)) {
                a1 = CheckMyDash((void *)(u8 *)(0x8c00 + MdlMng));
                if (a1 == 0) {
                    a0 = (void *)*(s16 *)(MdlMng +
                        (DCOMP_OFF_STRUCT_DW_2924721_FIELDS__160__INDEXANIM_6B336129 / 2));
                    if ((s32)a0 < 0x29 || (s32)a0 > 0x2b) {
                        break;
                    }
                }
            }
            f1 = *(float *)(DCOMP_OFF_STRUCT_DW_2924721_FIELDS_ALPHA_A5D24ECB + s1);
            a0 = (void *)(xt1);
            xt1 = 1;
            if (f1 < 1.0f) {
                break;
            }
            *(u8 *)(s0 + 0x182) = ((u8)a0);
            *(u32 *)(DCOMP_OFF_STRUCT_DW_2927398_FIELDS_STATE_0__D7B02039 + (s32)s2) = 3;
        }
        return;
    }
}

static void InitS0010Event004(void *a0 /* r4 */) {
    u8 *s1;
    s32 a1;
    u32 v1;
    u8 *s0;
    s32 v0;

    a1 = 1;
    s1 = (u8 *)a0;
    *(u32 *)(((u8 *)a0 + 0xc)) = a1;
    v1 = GameSt[0x14];
    s0 = (u8 *)MdlMng + 0x5400;
    if (v1 == (u32)a1) {
        a0 = (void *)(s32)0x3d5;
        v0 = CheckEventFlag((signed int)a0);
        a0 = (void *)(s32)1;
        if ((u32)v0 != 0) {
            goto _L00211518;
        }
        a1 = 0x34;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        v0 = (u32)((u32)v0) * (u32)(7);
        v0 = (u32)v0 << 6;
        a0 = (void *)(s0 + v0);
        FreeMdlMng(a0);
        a0 = (void *)(s32)1;
        a1 = 0x35;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        v1 = (u32)v0 << 3;
        v0 = (u32)((u32)v0) * (u32)(7);
        v0 = (u32)v0 << 6;
        a0 = (void *)(s0 + v0);
        FreeMdlMng(a0);
    } else {
        _L00211518:;
        v1 = GameSt[0x14];
        a0 = (void *)(s32)0x45a;
        if (v1 == 0) {
            v0 = CheckEventFlag((signed int)a0);
            a0 = (void *)(s32)1;
            if ((u32)v0 == 0) {
                a1 = 0x34;
                v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
                a1 = 1;
                v0 = (u32)((u32)v0) * (u32)(7);
                v0 = (u32)v0 << 6;
                a0 = (void *)(s0 + v0);
                SetEventModelDrawAndHit(a0, a1);
                a0 = (void *)(s32)1;
                a1 = 0x35;
                v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
                v1 = (u32)v0 << 3;
                a1 = 1;
                v0 = (u32)((u32)v0) * (u32)(7);
                v0 = (u32)v0 << 6;
                a0 = (void *)(s0 + v0);
                SetEventModelDrawAndHit(a0, a1);
                *(u32 *)(s1 + 0xc) = 0;
            }
        }
    }
    return;
}

static void PlayS0010Event004(void *a0 /* r4 */) {
    u32 *s1;
    u32 v1;
    u8 *s0;
    s32 v0;
    u32 a1;

    s1 = (u32 *)a0;
    v1 = *(s32 *)(((u8 *)a0 + 0xc));
    s0 = (u8 *)MdlMng + 0x5400;
    if (v1 == 0) {
        a0 = (void *)(s32)0x45a;
        v0 = CheckEventFlag((signed int)a0);
        a0 = (void *)(s32)1;
        if ((u32)v0 != 0) {
            a1 = 0x34;
            v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
            v1 = (u32)v0 << 3;
            v0 = v1 - v0;
            v0 = (u32)v0 << 6;
            a0 = (void *)(s32)((u8 *)s0 + v0);
            SetEventModelDrawAndHit(a0, 0);
            a0 = (void *)(s32)1;
            a1 = 0x35;
            v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
            v1 = (u32)v0 << 3;
            v0 = v1 - v0;
            v0 = (u32)v0 << 6;
            a0 = (void *)(s32)((u8 *)s0 + v0);
            SetEventModelDrawAndHit(a0, 0);
            v1 = 1;
            *(u32 *)(((u8 *)s1 + 0xc)) = v1;
        }
    }
    return;
}
