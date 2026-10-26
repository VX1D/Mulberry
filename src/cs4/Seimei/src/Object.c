#include "common.h"

/* InitFadeItem @ 0x17DF30 .. 0x17DF90 (0x60 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern signed int CheckEventFlag(signed int);
extern u8 MdlMng[];

/* ItemAppear @ 0x17DF90 .. 0x17E27C (0x2ec bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x17e0d4
 *   fpu: mtc1 reinterprets v1 at 0x17e0e8
 *   fpu: float literal 0x42c80000 at 0x17e100
 *   fpu: mtc1 reinterprets v0 at 0x17e128
 *   fpu: mtc1 reinterprets v1 at 0x17e13c
 *   fpu: float literal 0x42c80000 at 0x17e150
 *   fpu: mtc1 reinterprets v0 at 0x17e170
 *   fpu: mtc1 reinterprets v1 at 0x17e184
 *   fpu: float literal 0x42c80000 at 0x17e198
 *   fpu: mtc1 reinterprets v0 at 0x17e1b8
 *   fpu: mtc1 reinterprets v1 at 0x17e1cc
 *   fpu: float literal 0x42c80000 at 0x17e1e0
 *   fpu: mtc1 reinterprets v0 at 0x17e200
 *   fpu: mtc1 reinterprets v1 at 0x17e214
 *   fpu: float literal 0x42c80000 at 0x17e22c
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 SetMdlMng(void *,void *);
extern void sceVu0CopyVector(void *, void *);
extern void *GetMapPartsInfo();
extern void sceVu0ScaleVectorXYZ(void *,void *,float);
extern void PlayMi3(void *);
extern void DssPlay4Init(void *);
extern u32 MdlData[];
extern u16 DmyObjPrm[];

struct dw_1058868_fields;
struct dw_1070909_fields;
#ifndef PROTO_DW_1070352_FIELDS
#define PROTO_DW_1070352_FIELDS
struct dw_1070352_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_1068393_FIELDS
#define PROTO_DW_1068393_FIELDS
struct dw_1068393_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_1068071_FIELDS
#define PROTO_DW_1068071_FIELDS
struct dw_1068071_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_1058868_fields *lpMdl; };
#endif
#ifndef PROTO_DW_1058868_FIELDS
#define PROTO_DW_1058868_FIELDS
struct dw_1058868_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_1070909_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_1058868_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_1070352_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_1068393_fields flags; unsigned char _pad1[3]; struct dw_1068071_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_1067216_FIELDS
#define PROTO_DW_1067216_FIELDS
struct dw_1067216_fields { unsigned int power; unsigned char per; unsigned char clingAt; unsigned char pushAt; unsigned char blowAt; unsigned short ang; unsigned short angCorrect; unsigned short area[2]; unsigned char finish; unsigned char damageID; unsigned short waitTime; unsigned char pullAt; unsigned char pauseAt; unsigned char recover; unsigned char fire; unsigned char perframe; unsigned char disnodamage; unsigned char blastAt; unsigned char unused1[13]; };
#endif
#ifndef PROTO_DW_1065528_FIELDS
#define PROTO_DW_1065528_FIELDS
struct dw_1065528_fields { unsigned short no; unsigned short game_no; unsigned int hp; unsigned char revival; unsigned char clingTarget; unsigned char pushTarget; unsigned char blowTarget; unsigned char wanderType; unsigned char thinkType; unsigned char unionThink; unsigned char searchType; unsigned short searchArea[2]; unsigned short searchAng; unsigned short hitR; unsigned short hitH; unsigned short angMoveCorrect; unsigned short angStayCorrect; unsigned char throughSearch; unsigned char throughMove; unsigned short scale; unsigned char summonAnimType; unsigned char useHeart; unsigned short shadowSize; unsigned char noDamageFlag; unsigned char headId; unsigned short shadowHigh; unsigned short sfxId; unsigned short lifecut; unsigned char decoy; unsigned char breakfollow; unsigned char revival_rate; unsigned char bite_rate; unsigned short revival_time; unsigned short bite_wait_time; unsigned short no_damage_time; unsigned short use_wait; unsigned char item_rate[2]; unsigned int item_id[2]; unsigned char unused1[92]; struct dw_1067216_fields Attack[5]; };
#endif
#ifndef PROTO_DW_1072350_FIELDS
#define PROTO_DW_1072350_FIELDS
struct dw_1072350_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_1070909_FIELDS
#define PROTO_DW_1070909_FIELDS
struct dw_1070909_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_1072350_fields DmyPoly[32]; };
#endif


/* ObjFollowTargetProc @ 0x17E280 .. 0x17E650 (0x3d0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3dcccccd at 0x17e2d4
 *   fpu: float literal 0x00000000 at 0x17e2f0
 *   fpu: float literal 0x3c8ef34d at 0x17e30c
 *   fpu: float literal 0x3f800000 at 0x17e330
 *   fpu: float literal 0x00000000 at 0x17e348
 *   fpu: float literal 0x00000000 at 0x17e36c
 *   fpu: mov.s at 0x17e3a4 is a float copy
 *   fpu: float literal 0x3f9c5a1c at 0x17e3ac
 *   fpu: float literal 0x3fc90fdb at 0x17e3dc
 *   fpu: float literal 0x40490fdb at 0x17e3e8
 *   fpu: float literal 0x00000000 at 0x17e3ec
 *   fpu: float literal 0x40c90fdb at 0x17e40c
 *   fpu: mtc1 reinterprets v0 at 0x17e430
 *   fpu: float literal 0x00000000 at 0x17e458
 *   fpu: float literal 0x3fc90fdb at 0x17e478
 *   fpu: float literal 0x40490fdb at 0x17e484
 *   fpu: float literal 0x40c90fdb at 0x17e4a8
 *   fpu: mtc1 reinterprets v0 at 0x17e4cc
 *   fpu: float literal 0x3fc90fdb at 0x17e50c
 *   fpu: float literal 0x40490fdb at 0x17e518
 *   fpu: float literal 0x40c90fdb at 0x17e53c
 *   fpu: mtc1 reinterprets v0 at 0x17e560
 *   fpu: float literal 0x3fc90fdb at 0x17e590
 *   fpu: float literal 0x00000000 at 0x17e5a4
 *   fpu: float literal 0x00000000 at 0x17e5c4
 *   delay: addiu at 0x17e5f0 writes a register its branch at 0x17e5ec reads
 *   fpu: float literal 0x00000000 at 0x17e614
 *   cfg: kept branch: 0x17e5f0 if (..) goto .L0017E638
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void SetModelTargetToModel(void *, void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern float Math_GotoAngle(float, float, float);
extern float Math_GetAngleDist(float, float);
extern unsigned int CheckAnimParam(void *, signed int);
extern unsigned int CheckAnimEndFrame(void *);


/* FreeObjFollowTarget @ 0x17E650 .. 0x17E6A0 (0x50 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x17e678
 *   declaration vs inferred signature: return void vs inferred u8
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);

/* ObjTalkProc @ 0x17E700 .. 0x17E878 (0x178 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x17e784
 *   fpu: float literal 0x00000000 at 0x17e850
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void SetModelTargetToPos(void *, float *);
extern signed int KnMsgMng_SendMsgEx(signed int, signed int, unsigned short);
extern int rand(void);

struct dw_1058868_fields;
struct dw_1070909_fields;
#ifndef PROTO_DW_1070352_FIELDS
#define PROTO_DW_1070352_FIELDS
struct dw_1070352_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_1068393_FIELDS
#define PROTO_DW_1068393_FIELDS
struct dw_1068393_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_1068071_FIELDS
#define PROTO_DW_1068071_FIELDS
struct dw_1068071_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_1058868_fields *lpMdl; };
#endif
#ifndef PROTO_DW_1058868_FIELDS
#define PROTO_DW_1058868_FIELDS
struct dw_1058868_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_1070909_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_1058868_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_1070352_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_1068393_fields flags; unsigned char _pad1[3]; struct dw_1068071_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1058868_FIELDS_ANG_1__91030D31_DEFINED
#define DCOMP_OFF_STRUCT_DW_1058868_FIELDS_ANG_1__91030D31_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1058868_FIELDS_ANG_1__91030D31 = (int)&(((struct dw_1058868_fields *)0)->Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1058868_FIELDS_ATTACKNO_81F19424_DEFINED
#define DCOMP_OFF_STRUCT_DW_1058868_FIELDS_ATTACKNO_81F19424_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1058868_FIELDS_ATTACKNO_81F19424 = (int)&(((struct dw_1058868_fields *)0)->AttackNo) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1058868_FIELDS_CTRLMODE_8E4E6207_DEFINED
#define DCOMP_OFF_STRUCT_DW_1058868_FIELDS_CTRLMODE_8E4E6207_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1058868_FIELDS_CTRLMODE_8E4E6207 = (int)&(((struct dw_1058868_fields *)0)->CtrlMode) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_6__FCAEFF58_DEFINED
#define DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_6__FCAEFF58_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_6__FCAEFF58 = (int)&(((struct dw_1058868_fields *)0)->State[6]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_8__480FF5BC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_8__480FF5BC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_8__480FF5BC = (int)&(((struct dw_1058868_fields *)0)->State[8]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_9__D1BF80A7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_9__D1BF80A7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_9__D1BF80A7 = (int)&(((struct dw_1058868_fields *)0)->State[9]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1058868_FIELDS_TARGET_ANGSTEP_0826F1FB_DEFINED
#define DCOMP_OFF_STRUCT_DW_1058868_FIELDS_TARGET_ANGSTEP_0826F1FB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1058868_FIELDS_TARGET_ANGSTEP_0826F1FB = (int)&(((struct dw_1058868_fields *)0)->Target.angStep) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1058868_FIELDS_TARGET_ANGY_1E37CC12_DEFINED
#define DCOMP_OFF_STRUCT_DW_1058868_FIELDS_TARGET_ANGY_1E37CC12_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1058868_FIELDS_TARGET_ANGY_1E37CC12 = (int)&(((struct dw_1058868_fields *)0)->Target.angY) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1058868_FIELDS_LPANIMCTRL_05395A38_DEFINED
#define DCOMP_OFF_STRUCT_DW_1058868_FIELDS_LPANIMCTRL_05395A38_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1058868_FIELDS_LPANIMCTRL_05395A38 = (int)&(((struct dw_1058868_fields *)0)->lpAnimCtrl) - 0 };
#endif

/* SetObjTalkStart @ 0x17E8D0 .. 0x17EC5C (0x38c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x17e940
 *   fpu: mov.s at 0x17e978 is a float copy
 *   fpu: float literal 0x3e32b020 at 0x17e980
 *   fpu: float literal 0x3fc90fdb at 0x17e9b0
 *   fpu: float literal 0x40490fdb at 0x17e9bc
 *   fpu: float literal 0x00000000 at 0x17e9c0
 *   fpu: float literal 0x40c90fdb at 0x17e9e0
 *   fpu: mtc1 reinterprets v0 at 0x17ea04
 *   fpu: float literal 0x00000000 at 0x17ea2c
 *   fpu: float literal 0x3fc90fdb at 0x17ea4c
 *   fpu: float literal 0x40490fdb at 0x17ea58
 *   fpu: float literal 0x40c90fdb at 0x17ea7c
 *   fpu: mtc1 reinterprets v0 at 0x17eaa0
 *   fpu: float literal 0x3fc90fdb at 0x17eadc
 *   fpu: float literal 0x40490fdb at 0x17eae8
 *   fpu: float literal 0x40c90fdb at 0x17eb0c
 *   fpu: mtc1 reinterprets v0 at 0x17eb30
 *   fpu: float literal 0x3fc90fdb at 0x17eb60
 *   fpu: float literal 0x00000000 at 0x17eb74
 *   fpu: float literal 0x00000000 at 0x17eb94
 *   fpu: float literal 0x00000000 at 0x17ebbc
 *   cfg: kept branch: 0x17e998 if (..) goto .L0017EBB8
 *   declaration vs inferred signature: return void vs inferred u32
 */



#ifndef PROTO_DW_1070352_FIELDS
#define PROTO_DW_1070352_FIELDS

#endif
#ifndef PROTO_DW_1068393_FIELDS
#define PROTO_DW_1068393_FIELDS

#endif
#ifndef PROTO_DW_1068071_FIELDS
#define PROTO_DW_1068071_FIELDS

#endif
#ifndef PROTO_DW_1058868_FIELDS
#define PROTO_DW_1058868_FIELDS

#endif

#define CAE_ABSF(x) (((x) < 0.0f) ? -(x) : (x))
#define CAE_WRAPF(a) ((3.14159274f + (a) >= 0.0f) ? ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f)) : (6.28318548f + ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f))))


extern float sqrtf(float);
extern float Math_VectorToAngle(float, float);
extern float Math_GetAngleDist(float, float);
extern signed int UpdateMovePath(void *);
extern float Math_GotoAngle(float, float, float);

/* SetObjMovePath @ 0x17EE50 .. 0x17EED0 (0x80 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x17ee8c
 *   a1 takes slot 1 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void * GetMovePath(unsigned char, signed int);

/* SetObjCaveFaceStart @ 0x17EED0 .. 0x17EF58 (0x88 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x461c4000 at 0x17ef18
 *   fpu: float literal 0x3ba3d70a at 0x17ef24
 *   fpu: mtc1 reinterprets v1 at 0x17ef2c
 *   declaration vs inferred signature: return void vs inferred float
 */

extern int rand(void);


/* ObjPrmInitFunc_CaveFace @ 0x17F180 .. 0x17F218 (0x98 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern int rand(void);

/* ObjPrmProcFunc_BigMonkey @ 0x17F220 .. 0x17F6A0 (0x480 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @1977 -> 0x253f70
 *   fpu: mtc1 reinterprets v0 at 0x17f24c
 *   fpu: mtc1 reinterprets v1 at 0x17f264
 *   fpu: float literal 0x41200000 at 0x17f27c
 *   indirect: jr v1 at 0x17f2c0 -> <v1>
 *   fpu: float literal 0x00000000 at 0x17f2e8
 *   fpu: float literal 0x00000000 at 0x17f350
 *   fpu: float literal 0x00000000 at 0x17f384
 *   fpu: float literal 0x3c8ef34d at 0x17f3cc
 *   fpu: float literal 0x3e4ccccd at 0x17f3f0
 *   fpu: float literal 0x00000000 at 0x17f420
 *   fpu: float literal 0x00000000 at 0x17f478
 *   fpu: float literal 0x00000000 at 0x17f4b0
 *   fpu: float literal 0x00000000 at 0x17f520
 *   fpu: float literal 0x00000000 at 0x17f554
 *   fpu: float literal 0x3c8ef34d at 0x17f59c
 *   fpu: float literal 0x3e4ccccd at 0x17f5c0
 *   fpu: float literal 0x00000000 at 0x17f5e8
 *   fpu: float literal 0x00000000 at 0x17f61c
 *   fpu: float literal 0x00000000 at 0x17f64c
 *   fpu: float literal 0x00000000 at 0x17f67c
 */

extern void SetModelTargetToPos(void *, float *);
extern float Math_GotoAngle(float, float, float);
extern unsigned int CheckAnimEndFrame(void *);
extern u32 BigMonkeyPath[];

/* ObjPrmInitFunc_BigMonkey @ 0x17F6A0 .. 0x17F6F0 (0x50 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x17f6d0
 */

extern void sceVu0CopyVector(void *, void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern u32 BigMonkeyPath[];

/* ObjPrmInitFunc_BigMonkey @ 0x17F6A0 .. 0x17F6F0 (0x50 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x17f6d0
 */



#ifndef PROTO_DW_1070352_FIELDS
#define PROTO_DW_1070352_FIELDS

#endif
#ifndef PROTO_DW_1068393_FIELDS
#define PROTO_DW_1068393_FIELDS

#endif
#ifndef PROTO_DW_1068071_FIELDS
#define PROTO_DW_1068071_FIELDS

#endif
#ifndef PROTO_DW_1058868_FIELDS
#define PROTO_DW_1058868_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_1__EF589220_DEFINED
#define DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_1__EF589220_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_1__EF589220 = (int)&(((struct dw_1058868_fields *)0)->State[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_2__168689BC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_2__168689BC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_2__168689BC = (int)&(((struct dw_1058868_fields *)0)->State[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_3__91217503_DEFINED
#define DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_3__91217503_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_3__91217503 = (int)&(((struct dw_1058868_fields *)0)->State[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_4__E7AD1D67_DEFINED
#define DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_4__E7AD1D67_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_4__E7AD1D67 = (int)&(((struct dw_1058868_fields *)0)->State[4]) - 0 };
#endif

/* ObjPrmProcFunc_SaveBoat @ 0x17F6F0 .. 0x17F750 (0x60 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3ca3d70a at 0x17f72c
 */

extern void SetMdlFade(void *, unsigned char, float);

/* CheckDoorSeal @ 0x17F760 .. 0x17F894 (0x134 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1085 -> 0x22b200
 *   fpu: float literal 0x3ca3d70a at 0x17f7f8
 *   stack: address of the slot at 0x40 escapes at 0x17f824
 *   stack: address of the slot at 0x30 escapes at 0x17f824
 *   stack: address of the slot at 0x40 escapes at 0x17f834
 *   literal: @1085 initializes the 16-byte local at 0x30
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern unsigned short ItemMng_GetItemNum_Direct(unsigned short);
extern signed int KnMsgMng_SendMsg(signed int);
extern void sceVu0AddVector(void *, void *, void *);
extern signed int SFX_Create_OnAng(unsigned short, float *, float *);
extern void SetEventFlag(signed int);
extern void ResetEventFlag(signed int);

extern void SetCamCtrlMode(unsigned int);
extern void SetCameraPos(float *);
extern void SetCameraAng(float *);
extern void SetCameraFov(float);
extern void DrawCalcView(void);
extern void SetMyDoor(void *, void *, float, unsigned short, unsigned char);
extern u8 GameSt[];


/* CheckDoorOpen @ 0x17FCD0 .. 0x17FDE0 (0x110 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x17fd50
 *   fpu: float literal 0x00000000 at 0x17fdac
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 KnMsgMng_CheckMsgNone();
static void SetDoorProc(void *object, u32 animation, void *player);
static void SetDoorProc(void *, unsigned int, void *);



extern void SetModelEraseByMapDraw(void *);

extern void UpdateObjectPointLight(void *);
extern signed int SfxPLight_SetPos(unsigned short, float *);
extern void MdlFadeProc(void *);
struct dw_1058868_fields;
static void ObjTalkProc(struct dw_1058868_fields *lpObj);
static void ObjTalkProc(struct dw_1058868_fields *);
static void ObjMovePathProc(void *object);
static void ObjMovePathProc(void *);
static void ObjFollowTargetProc(void *a0 );
static void ObjFollowTargetProc(void *);
extern void SetE044RandomAppear(float *, signed int, signed int, float);
extern void SetBlast(float, float, float *, float *, signed int);
extern void MasterMove(void *);
extern unsigned int CheckHitMapGetMdlMng(void *, void *);
extern u32 ObjPrmProcFunc[];


/* ObjPlayAll @ 0x180050 .. 0x180118 (0xc8 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00180090
 *   cfg: loop body is not one contiguous region: .L001800D8
 */

extern signed int Menu_TD_IsPlay(void);
static void ObjPlay(void *a0 );
static void ObjPlay(void *);
extern u8 GameSt[];

extern u32 SetMdlMng(void *,void *);
extern void *GetMapPartsInfo();
extern void sceVu0ScaleVectorXYZ(void *,void *,float);
extern void PlayMi3(void *);
extern void DssPlay4Init(void *);
extern void ReCalcMi3Matrix(void *);
extern void UpdateWorldMatrixInAnim(void *);
extern u32 MdlData[];
extern u16 DmyObjPrm[];


/* InitObjFunc @ 0x180580 .. 0x180618 (0x98 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001805A8
 */

extern u32 ObjPrmInitFunc[];
static void ObjPrmProcFunc_BigMonkey(void *a0 );

/* SetObjFunc @ 0x180620 .. 0x18071C (0xfc bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */

static void ObjPrmProcFunc_BigMonkey(void *a0 /* r4 */);
static void ObjPrmProcFunc_CaveFace(void *a0 );
static void ObjPrmProcFunc_CaveFace(void *a0 /* r4 */);
extern u32 ObjPrmInitFunc[];
extern u32 ObjPrmProcFunc[];
static u16 DmyObjPrm[0xb4];
static u32 ObjPrmInitFunc[0x32];
static u32 ObjPrmProcFunc[0x32];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetObjFunc(void);
void InitObjFunc(void);
void ObjAppear(s32 index,u8 *model,u32 position,u32 rotation,u32 scale);
void ObjPlayAll(void);
static void ObjPlay(void *a0 );
void CheckDoorOpen(void *a0 , signed int a1 );
static void SetDoorProc(void *object, u32 animation, void *player);
void InitFadeObj(signed int a0 , signed int a1 );
static signed int CheckDoorSeal(void *a0 );
static void ObjPrmInitFunc_SaveBoat(u32 *a0 );
static void ObjPrmProcFunc_SaveBoat(void *a0 );
static void ObjPrmInitFunc_BigMonkey(void *a0 );
static void ObjPrmProcFunc_BigMonkey(void *a0 );
static void ObjPrmInitFunc_CaveFace(void *a0 );
static void ObjPrmProcFunc_CaveFace(void *a0 );
void SetObjCaveFaceStart(void *a0 );
void SetObjMovePath(void *a0 , signed int a1 , unsigned short a2 , unsigned short a3 );
void FreeObjMovePath(void *a0 );
static void ObjMovePathProc(void *object);
void SetObjTalkStart(struct dw_1058868_fields *lpObj, signed int TalkId, signed int AttackNo, signed int Num);
void SetObjTalkEnd(void *a0 );
static void ObjTalkProc(struct dw_1058868_fields *lpObj);
void SetObjFollowTarget(void *a0 , unsigned short a1 , unsigned short a2 , void *a3 );
void FreeObjFollowTarget(void *a0 );
static void ObjFollowTargetProc(void *a0 );
void ItemAppear(s32 index,u8 *model,u32 position,u32 rotation,u32 scale);
void InitFadeItem(signed int a0 , signed int a1 );


void SetObjFunc(void) {
    u32 a1;
    u8 *a0;
    u8 *v1;

    a1 = 0x31;
    a0 = (u8 *)ObjPrmInitFunc + 0xc4;
    v1 = (u8 *)ObjPrmProcFunc + 0xc4;
    do {
        *(u32 *)a0 = 0;
        *(u32 *)v1 = 0;
        a1 = a1 + -8;
        *(u32 *)(a0 + -4) = 0;
        *(u32 *)(v1 + -4) = 0;
        *(u32 *)(a0 + -8) = 0;
        *(u32 *)(v1 + -8) = 0;
        *(u32 *)(a0 + -0xc) = 0;
        *(u32 *)(v1 + -0xc) = 0;
        *(u32 *)(a0 + -0x10) = 0;
        *(u32 *)(v1 + -0x10) = 0;
        *(u32 *)(a0 + -0x14) = 0;
        *(u32 *)(v1 + -0x14) = 0;
        *(u32 *)(a0 + -0x18) = 0;
        *(u32 *)(v1 + -0x18) = 0;
        *(u32 *)(a0 + -0x1c) = 0;
        *(u32 *)(v1 + -0x1c) = 0;
        a0 = (u8 *)(a0 + -0x20);
        v1 = (u8 *)(v1 + -0x20);
    } while ((s32)a1 > (s32)7);
    a1 = a1 << 2;
    v1 = (u8 *)ObjPrmInitFunc;
    a0 = (u8 *)((u8 *)ObjPrmInitFunc + a1);
    *(u32 *)a0 = 0;
    v1 = (u8 *)ObjPrmProcFunc;
    v1 = (u8 *)((u8 *)ObjPrmProcFunc + a1);
    *(u32 *)v1 = 0;
    *(u32 *)(a0 + -4) = 0;
    a1 = (u32)ObjPrmInitFunc_SaveBoat;
    *(u32 *)(v1 + -4) = 0;
    ObjPrmInitFunc[0xb] = (u32)ObjPrmInitFunc_SaveBoat;
    a0 = (u8 *)ObjPrmProcFunc_SaveBoat;
    ObjPrmProcFunc[0xb] = (u32)ObjPrmProcFunc_SaveBoat;
    v1 = (u8 *)ObjPrmInitFunc_BigMonkey;
    ObjPrmInitFunc[0x16] = (u32)ObjPrmInitFunc_BigMonkey;
    a1 = (u32)ObjPrmProcFunc_BigMonkey;
    ObjPrmProcFunc[0x16] = (u32)ObjPrmProcFunc_BigMonkey;
    a0 = (u8 *)ObjPrmInitFunc_CaveFace;
    ObjPrmInitFunc[0x18] = (u32)ObjPrmInitFunc_CaveFace;
    v1 = (u8 *)ObjPrmProcFunc_CaveFace;
    ObjPrmProcFunc[0x18] = (u32)ObjPrmProcFunc_CaveFace;
    return;
}

void InitObjFunc(void) {
    u16 a0;
    u8 *s0;
    u32 v1;

    v1 = (u32)(u8 *)(MdlMng + 0xfc00);
    s0 = (u8 *)(MdlMng + 0x5400);
    if ((u32)s0 != v1) {
        do {
            v1 = *(u8 *)s0;
            if (v1 != 0) {
                v1 = *(s32 *)(s0 + 0xc);
                v1 = *(s32 *)((v1 + 0x4c));
                if (v1 != 0) {
                    a0 = *(u16 *)v1;
                    v1 = (u32)ObjPrmInitFunc;
                    v1 = (s32)((u8 *)ObjPrmInitFunc + (u32)((u32)a0 << 2));
                    v1 = *(s32 *)v1;
                    if (v1 != 0) {
                        ((void (*)(u32))(s32)v1)((u32)s0);
                    }
                }
            }
            s0 = (u8 *)(s0 + 0x1c0);
        } while (s0 != (u8 *)(MdlMng + 0xfc00));
    }
    return;
}
void ObjAppear(s32 index,u8 *model,u32 position,u32 rotation,u32 scale)
{
    u16 *params;
    float factor;
    if(SetMdlMng(model,(u8 *)MdlData+(index+76)*1664)!=0) {
        sceVu0CopyVector(model+0x20,(void *)position);
        *(float *)(model+0x2c)=1.0f;
        sceVu0CopyVector(model+0x70,model+0x20);
        sceVu0CopyVector(model+0x30,(void *)rotation);
        sceVu0CopyVector(model+0x80,model+0x30);
        sceVu0CopyVector(model+0x40,(void *)scale);
        *(u16 *)(model+0x192)=0xffff;
        *(void **)(model+0x140)=GetMapPartsInfo(1,((s32)model-(s32)(MdlMng+0x5400))/448);
        params=*(u16 **)(*(u8 **)(model+12)+76);
        if(params==0) {
            params=DmyObjPrm;
            DmyObjPrm[11]=90;DmyObjPrm[12]=160;
            DmyObjPrm[16]=100;DmyObjPrm[18]=100;DmyObjPrm[20]=0;
        }
        *(u16 **)(*(u8 **)(model+12)+76)=params;
        sceVu0ScaleVectorXYZ(model+64,model+64,(float)(u32)params[16]/100.0f);
        factor=(float)(u32)params[11]/100.0f;
        *(float *)(model+0x110)=factor**(float *)(model+64);
        factor=(float)(u32)params[12]/100.0f;
        *(float *)(model+0x114)=factor**(float *)(model+68);
        factor=(float)(u32)params[18]/100.0f;
        *(float *)(model+0x118)=factor**(float *)(model+64);
        factor=(float)(u32)params[20]/100.0f;
        *(float *)(model+0x11c)=factor**(float *)(model+64);
        PlayMi3(model);
        if(*(u32 *)(*(u8 **)(model+12)+72)!=0) DssPlay4Init(model);
        if(*(u32 *)(*(u8 **)(model+12)+20)!=0) {
            ReCalcMi3Matrix(model);UpdateWorldMatrixInAnim(model);
        }
        if(*(volatile u8 *)(GameSt+9)==10) {
            switch(**(u32 **)(*(u8 **)(model+0x140)+56)) {
            case 32:
                model[7]=2;
                *(float *)(model+0x90)=-1.0f;*(float *)(model+0x94)=0.0f;*(float *)(model+0x98)=0.0f;
                break;
            case 26:
                if((*(u8 **)(model+12))[14]!=0) (*(u8 **)(model+12))[14]=2;
                break;
            }
        }
        if(*(volatile u8 *)(GameSt+9)==51) {
            switch(**(u32 **)(*(u8 **)(model+0x140)+56)) {
            case 4:case 9:case 43:
                model[7]=2;
                *(float *)(model+0x90)=0.0f;*(float *)(model+0x94)=0.0f;*(float *)(model+0x98)=-1.0f;
                break;
            case 55:
                if((*(u8 **)(model+12))[14]!=0) (*(u8 **)(model+12))[14]=2;
                break;
            }
        }
        if(*(volatile u8 *)(GameSt+9)==53) {
            switch(**(u32 **)(*(u8 **)(model+0x140)+56)) {
            case 36:model[0x12b]|=4;break;
            }
        }
    }
}

void ObjPlayAll(void) {
    u32 v1;
    u32 v0;
    u8 *s0;

    v1 = GameSt[0xf];
    if (v1 == 0) {
        v0 = Menu_TD_IsPlay();
        if (v0 == 0) {
            s0 = (u8 *)(MdlMng + 0x5400);
            v1 = (u32)(u8 *)(MdlMng + 0xfc00);
            if ((u32)s0 != v1) {
                do {
                    v1 = *(u8 *)s0;
                    if (v1 != 0) {
                        ObjPlay((void *)(u8 *)s0);
                    }
                    s0 = (u8 *)(s0 + 0x1c0);
                } while (s0 != (u8 *)(MdlMng + 0xfc00));
            }
            s0 = (u8 *)(MdlMng + 0xfc00);
            v1 = (u32)(u8 *)(MdlMng + 0x11800);
            if ((u32)s0 != v1) {
                do {
                    v1 = *(u8 *)s0;
                    if (v1 != 0) {
                        ObjPlay((void *)(u8 *)s0);
                    }
                    s0 = (u8 *)(s0 + 0x1c0);
                } while (s0 != (u8 *)(MdlMng + 0x11800));
            }
        }
    }
    return;
}

static void ObjPlay(void *a0 /* r4 */) {
    u32 a2;
    u32 a1;
    u8 *a0_bytes; // s1
    void *a0_s1; // a0
    u32 v1;
    float f0;
    u32 v0;
    u16 *s0;

    a0_bytes = (u8 *)a0;
    v0 = *(s32 *)(a0_bytes + 0xc);
    s0 = (u16 *)*(s32 *)((v0 + 0x4c));
    sceVu0CopyVector(a0_bytes + 0x70, a0_bytes + 0x20);
    a0_s1 = (void *)(a0_bytes + 0x80);
    sceVu0CopyVector(a0_s1, a0_bytes + 0x30);
    a0_s1 = (void *)a0_bytes;
    SetModelEraseByMapDraw(a0_s1);
    a1 = *(s32 *)(a0_bytes + 0x144);
    {
        u32 camera;
        if (a1 != 0 && *(s32 *)(a1 + 0xc) == 3) {
            camera = a1;
        } else {
            camera = 0;
        }
        a1 = camera;
    }
    a0_s1 = (void *)*(s32 *)(a0_bytes + 0x100);
    if (a1 != 0) {
        v1 = *(s16 *)(a0_bytes + 0x104);
        v0 = 0x15;
        switch (v1) {
        case 1:
        case 2:
        case 10:
        case 11:
        case 20:
        case 21:
            v0 = CheckAnimEndFrame(a0_s1);
            a0_s1 = (void *)0;
            if (v0 == 0) {
                break;
            }
            SetCamCtrlMode(0);
            a0_s1 = (void *)a0_bytes;
            ChangeAnimParam(a0_s1, 0, 0.0f);
            a0_s1 = (void *)*(s32 *)(a0_bytes + 0x1b4);
            if ((u32)(s32)a0_s1 == 0) {
                break;
            }
            ChangeAnimParam(a0_s1, 0, 0.0f);
            *(u32 *)(a0_bytes + 0x1b4) = 0;
        }
    }
    if ((u32)(s32)s0 != 0) {
        v1 = *(u16 *)s0;
        v0 = (u32)ObjPrmProcFunc;
        v1 = v1 << 2;
        v0 = (s32)((u8 *)ObjPrmProcFunc + v1);
        v0 = *(s32 *)v0;
        a0_s1 = (void *)a0_bytes;
        if (v0 != 0) {
            ((void (*)(u32))(s32)v0)((u32)a0_s1);
        }
    }
    UpdateObjectPointLight((void *)a0_bytes);
    {
        u16 light = *(u16 *)(a0_bytes + 0x192);
        if (light != 0xffff) {
            SfxPLight_SetPos(light, (float *)(a0_bytes + 0x20));
        }
    }
    MdlFadeProc((void *)a0_bytes);
    ObjTalkProc((void *)a0_bytes);
    ObjMovePathProc((void *)a0_bytes);
    ObjFollowTargetProc((void *)a0_bytes);
    v1 = *(u8 *)(a0_bytes + 0x18a);
    a0_s1 = (void *)*(s32 *)(a0_bytes + 0x100);
    v0 = 4;
    s0 = (u16 *)(u8 *)(MdlMng + 0x11800);
    if (v1 == v0) {
        v0 = CheckAnimEndFrame(a0_s1);
        if (v0 != 0) {
            v0 = *(s16 *)(a0_bytes + 0x104);
            a0_s1 = (void *)a0_bytes;
            ChangeAnimParam(a0_s1, (u16)(v0 + 1), 0.0f);
            *(u8 *)(a0_bytes + 0x18a) = 0;
            a1 = *(s32 *)(a0_bytes + 0x174);
            a0_s1 = (void *)(u8 *)(s0 + 0x10);
            SetE044RandomAppear((float *)a0_s1, a1, a1, 2.0f);
            v0 = 0x3cf50000;
            v1 = 0x3cf50000 | 0xc28f;
            a0_s1 = (void *)(a0_bytes + 0x20);
            a2 = 0x28;
            SetBlast(0.03f, 1.2e+02f, (float *)a0_s1, (float *)(u8 *)(s0 + 0x10), a2);
        }
    }
    MasterMove((void *)a0_bytes);
    a0_s1 = (void *)*(u8 *)(a0_bytes + 0x18a);
    v1 = 3;
    switch ((u32)a0_s1) {
    case 1:
    case 3:
        v1 = *(u8 *)(a0_bytes + 0x131);
        if (v1 == 0) {
            f0 = 0.1f;
            f0 = (*(float *)(a0_bytes + 0x24) + (float)f0);
            *(f32 *)(a0_bytes + 0x24) = f0;
        }
        v1 = *(u8 *)(a0_bytes + 0x132);
        a0_s1 = (void *)a0_bytes;
        if (v1 != 0) {
            break;
        }
        v0 = CheckHitMapGetMdlMng(a0_s1, (void *)(a0_bytes + 0x138));
        *(u32 *)(a0_bytes + 0x134) = v0;
    }
    return;
}

void CheckDoorOpen(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u8 *s3;
    u32 a0_index; // a0
    u8 *s2;
    u8 *s1;
    u32 s0;
    u32 v0;
    u32 a1_2;
    void *a0_2;
    u32 v1;

    s3 = (u8 *)a0;
    v0 = GetMdlMngIndexByCtrlId(1, *(s32 *)(s3 + 4));
    a0_index = v0 + (u32)0x30;
    v0 = (u32)MdlMng;
    s1 = (u8 *)(MdlMng + 0x11800);
    s2 = (u8 *)((u8 *)MdlMng + (u32)((u32)((s32)(a0_index * (u32)(7))) << 6));
    v0 = KnMsgMng_CheckMsgNone();
    if (v0 != 0 && (u32)*(s16 *)(s2 + 0x104) != (u32)(s32)a1) {
        v0 = CheckDoorSeal((void *)s3);
        s0 = (u16)a1;
        if (v0 == 0) {
            __asm__ volatile("daddu %0, %1, $zero" : "=r"(a0_2) : "r"(s2));
            ChangeAnimParam(a0_2, s0, 0.0f);
            SetDoorProc((void *)s2, a1, (void *)(u8 *)s1);
            *(u32 *)(s2 + 0x1b4) = 0;
            a1_2 = *(s32 *)(s3 + 0x3c);
            a0_2 = (void *)(s32)1;
            if ((s32)a1_2 > 0) {
                v0 = GetMdlMngIndexByCtrlId((signed int)a0_2, a1_2);
                a1_2 = v0 + 0x30;
                s1 = ((u8 (*)[0x1c0])MdlMng)[a1_2];
                v1 = *(u8 *)s1;
                if (v1 != 0) {
                    ChangeAnimParam((void *)s1, s0, 0.0f);
                    *(u32 *)(s2 + 0x1b4) = (s32)s1;
                }
            }
        }
    }
    return;
}
static void SetDoorProc(void *object, u32 animation, void *player) {
    float angle, distance, height, tilt;
    u8 *obj = object;
    u8 *my = player;
    u8 *params;
    u16 kind;
    u8 flag = 0;
    float position[4] __attribute__((aligned(16)));
    float rotation[4] __attribute__((aligned(16)));
    params = *(u8 **)(*(u32 *)(obj + 0xc) + 0x4c);
    distance = 0.35f;
    SetCamCtrlMode(1);
    if (params && *(u16 *)params == 20) {
        if (animation == 1) {
            angle = *(float *)(obj + 0x34);
            kind = 92;
        } else {
            kind = 91;
            angle = 3.1415927f + *(float *)(obj + 0x34);
        }
    } else if (params && *(u16 *)params == 19) {
        if (animation == 1 || animation == 10) {
            angle = *(float *)(obj + 0x34);
            kind = 90;
            if (GameSt[20] == 1) distance = 0.45f;
            flag = 1;
        } else {
            float base = *(float *)(obj + 0x34);
            kind = 94;
            angle = 3.1415927f + base;
            distance = 0.55f;
        }
    } else {
        switch (GameSt[20]) {
        case 0:
            if (animation == 1) angle = *(float *)(obj + 0x34);
            else angle = 3.1415927f + *(float *)(obj + 0x34);
            break;
        case 1:
            if (animation == 10) angle = *(float *)(obj + 0x34);
            else angle = 3.1415927f + *(float *)(obj + 0x34);
            distance = 0.45f;
            break;
        case 2:
            if (animation == 20) angle = *(float *)(obj + 0x34);
            else angle = 3.1415927f + *(float *)(obj + 0x34);
            distance = 0.45f;
            break;
        }
        kind = 90;
    }
    if (params && *(u16 *)params == 19) {
        height = 0.7f;
        tilt = 2.0f;
    } else {
        height = 2.2f;
        tilt = -14.0f;
    }
    position[0] = *(float *)(obj + 0x20) - 3.0f * sinf(angle);
    position[2] = *(float *)(obj + 0x28) - 3.0f * cosf(angle);
    position[1] = *(float *)(obj + 0x24) - height;
    position[3] = 1.0f;
    rotation[0] = 0.01745f * tilt;
    rotation[1] = angle;
    rotation[2] = 0.0f;
    rotation[3] = 0.0f;
    SetCameraPos(position);
    SetCameraAng(rotation);
    SetCameraFov(0.82014996f);
    DrawCalcView();
    position[0] = *(float *)(obj + 0x20) - distance * sinf(angle);
    position[2] = *(float *)(obj + 0x28) - distance * cosf(angle);
    position[1] = *(float *)(my + 0x24);
    SetMyDoor(my, position, rotation[1] += 3.1415927f, kind, flag);
}

/* InitFadeObj @ 0x17F8A0 .. 0x17F908 (0x68 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */





void InitFadeObj(signed int a0 /* r4 */, signed int a1 /* r5 */) {
    u32 s0;
    u32 v0;

    s0 = a1;
    v0 = GetMdlMngIndexByCtrlId(1, a0);
    a1 = v0 + 0x30;
    a0 = s0;
    v0 = (u32)MdlMng;
    s0 = (s32)((u8 *)MdlMng + (s32)((u32)((u32)a1) * (u32)(0x1c0)));
    v0 = CheckEventFlag(a0);
    if (v0 != 0) {
        *(u32 *)((s0 + 0x10c)) = 0;
        *(u32 *)((s0 + 0x154)) = 1;
    }
    return;
}

static signed int CheckDoorSeal(void *a0 /* r4 */) {
    u8 *s1;
    s32 v1;
    u32 v0;
    u8 *s0;
    void *a0_2;
    u8 stackFrame_40[16] __attribute__((aligned(16)));

    v0 = *(s32 *)(((u8 *)a0 + 0x10));
    s1 = (u8 *)a0;
    if (v0 == 0) {
        v0 = 0;
    } else {
        v0 = GetMdlMngIndexByCtrlId(1, *(s32 *)(s1 + 0x14));
        a0_2 = (void *)(s32)(v0 + 0x30);
        v1 = (s32)((u8 *)(s32)((u32)a0_2 << 3) - (u32)(a0_2));
        v0 = (u32)MdlMng;
        s0 = (u8 *)((u8 *)MdlMng + (s32)((u32)v1 << 6));
        v0 = *(s32 *)(s0 + 0x154);
        if (v0 != 0) {
            v0 = 0;
        } else {
            a0_2 = (void *)(u16)(*(s32 *)(s1 + 0x10) + 0x2ee0);
            if (ItemMng_GetItemNum_Direct((unsigned short)a0_2)) {
                KnMsgMng_SendMsg(*(s32 *)(s1 + 0x10) + 0x6e);
                SetMdlFade((void *)s0, 2, 0.0199999996f);
                v0 = 0x22b200;
                *(u32 *)(s0 + 0x154) = 1;
                {
                    struct stackFrame_30 { u8 b[16]; } stackFrame_30 __attribute__((aligned(16))) =
                        {{0x00, 0x00, 0x00, 0x00, 0x66, 0x66, 0xa6, 0xbf, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00}};
                    sceVu0AddVector((void *)((u8 *)&stackFrame_40[0]), (void *)(s0 + 0x20), (void
                        *)(u8 *)((u8 *)&stackFrame_30));
                    SFX_Create_OnAng(0x35, (float *)((u8 *)&stackFrame_40[0]), (float *)(u8 *)(s0 +
                        0x30));
                    a0_2 = (void *)*(s32 *)(s1 + 0x20);
                    if ((u32)(s32)a0_2 != 0) {
                        SetEventFlag((signed int)a0_2);
                    }
                    a0_2 = (void *)*(s32 *)(s1 + 0x34);
                    if ((u32)(s32)a0_2 != 0) {
                        ResetEventFlag((signed int)a0_2);
                    }
                    v0 = 1;
                }
            } else {
                KnMsgMng_SendMsg(*(s32 *)(s1 + 0x10) + 0x64);
                v0 = 1;
            }
        }
    }
    return v0;
}
u32 BigMonkeyPath[0x14] = {
    0xc2e8cccd, 0xc0d33333, 0xc189999a, 0x3f800000, 0xc2e90000, 0xc0d33333, 0xc1926666,
    0x3f800000, 0xc2e4cccd, 0xc0d33333, 0xc199999a, 0x3f800000, 0xc2e00000, 0xc0d33333,
    0xc1900000, 0x3f800000, 0xc2dc999a, 0xc0d33333, 0xc1840000, 0x3f800000
};

/* ObjPrmInitFunc_SaveBoat @ 0x17F750 .. 0x17F758 (0x8 bytes) */

static void ObjPrmInitFunc_SaveBoat(u32 *a0 /* r4 */) {
    *(u32 *)(((u8 *)a0 + 0x158)) = 0;
    return;
}

static void ObjPrmProcFunc_SaveBoat(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u32 a1;

    v1 = 1;
    a1 = *(s32 *)(((u8 *)a0 + 0x158));
    s0 = (u8 *)a0;
    switch (a1) {
    case 1:
        v1 = *(s32 *)(s0 + 0x17c);
        if (v1 != 0) {
            break;
        }
        a1 = 2;
        SetMdlFade(a0, a1, 0.0199999996f);
        *(u32 *)(s0 + 0x158) = 0;
    }
    return;
}
static void ObjPrmInitFunc_BigMonkey(void *a0 /* r4 */) {
    u32 *s0;

    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_1__EF589220) = 0;
    s0 = (u32 *)a0;
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_2__168689BC) = 0;
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_3__91217503) = 0;
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1058868_FIELDS_STATE_4__E7AD1D67) = 0;
    sceVu0CopyVector((void *)(u32 *)(u8 *)(s0 + 8), (void *)BigMonkeyPath);
    ChangeAnimParam((void *)(u32 *)s0, 0, 0.0f);
    return;
}

static void ObjPrmProcFunc_BigMonkey(void *a0 /* r4 */) {
    u8 *s1;
    s32 a1;
    u32 s0;
    float f14;
    float f13;
    u32 v1;
    float f20;
    u32 v0;
    float f12;
    float f1;
    float f0;

    v0 = *(s32 *)(((u8 *)a0 + 0xc));
    s0 = *(s32 *)(((u8 *)a0 + 0x100));
    v0 = *(s32 *)((v0 + 0x4c));
    v0 = *(u16 *)((v0 + 0x1a));
    s1 = (u8 *)a0;
    f1 = (float)v0;
    a0 = (void *)(s32)0xd5;
    f0 = 10.0f;
    f20 = (f1 / 10.0f);
    v0 = CheckEventFlag((signed int)a0);
    if (v0 != 0) {
        v1 = *(s32 *)(s1 + 0x158);
        a0 = (void *)0x253f70;
        switch (v1) {
        case 0:
            a0 = (void *)*(s32 *)(s1 + 0x15c);
            v1 = (s32)((u8 *)a0 + 1);
            *(u32 *)(s1 + 0x15c) = v1;
            if ((s32)a0 > (s32)0x258) {
                a1 = 1;
                a0 = (void *)s1;
                *(u32 *)(s1 + 0x158) = a1;
                f12 = 0.0f;
                *(u32 *)(s1 + 0x15c) = 0;
                *(u32 *)(s1 + 0x160) = a1;
                ChangeAnimParam(a0, a1, 0.0f);
                break;
            } else {
                a0 = (void *)*(s32 *)(s1 + 0x15c);
                v1 = 0x78;
                v1 = (s32)a0 % (s32)(0x78);
                if (v1 != 0) {
                    break;
                }
                v0 = rand();
                v1 = 0x64;
                v1 = (s32)v0 % (s32)(0x64);
                if ((s32)v1 < (s32)0xa) {
                    v0 = *(s32 *)(s1 + 0x158);
                    a1 = 4;
                    f12 = 0.0f;
                    a0 = (void *)s1;
                    *(u32 *)(s1 + 0x164) = v0;
                    *(u32 *)(s1 + 0x158) = a1;
                    ChangeAnimParam(a0, a1, 0.0f);
                    break;
                } else {
                    if ((s32)v1 > (s32)0x13) {
                        break;
                    }
                    v1 = *(s32 *)(s1 + 0x158);
                    v0 = 5;
                    f12 = 0.0f;
                    a0 = (void *)s1;
                    a1 = 2;
                    *(u32 *)(s1 + 0x164) = v1;
                    *(u32 *)(s1 + 0x158) = v0;
                    ChangeAnimParam(a0, a1, 0.0f);
                    break;
                }
            }
        case 1:
            v1 = *(s32 *)(s1 + 0x160);
            a0 = (void *)s1;
            v0 = (u32)BigMonkeyPath;
            v1 = v1 << 4;
            a1 = (s32)((u8 *)BigMonkeyPath + v1);
            SetModelTargetToPos(a0, (float *)a1);
            f0 = 0.0174499992f;
            f12 = *(float *)(s1 + 0x34);
            f13 = *(float *)(s1 + 0x198);
            f14 = (0.0174499992f * f20);
            f0 = Math_GotoAngle(f12, f13, f14);
            *(f32 *)(s1 + 0x34) = f0;
            f1 = *(float *)(s1 + 0x19c);
            v1 = 0x3e4ccccd;
            f0 = 0.200000003f;
            if (!(f1 < 0.200000003f)) {
                break;
            }
            a0 = (void *)*(s32 *)(s1 + 0x160);
            v1 = 5;
            a0 = (void *)((u8 *)a0 + 1);
            *(u32 *)(s1 + 0x160) = (s32)a0;
            if ((u32)(s32)a0 == v1) {
                v0 = 2;
                a0 = (void *)s1;
                f12 = 0.0f;
                *(u32 *)(s1 + 0x158) = v0;
                ChangeAnimParam(a0, 0, 0.0f);
                break;
            } else {
                a0 = (void *)*(s32 *)(s1 + 0x160);
                v1 = 3;
                if ((u32)(s32)a0 != v1) {
                    break;
                }
                v0 = rand();
                v1 = 0x64;
                v1 = (s32)v0 % (s32)(0x64);
                if ((s32)v1 > (s32)0x27) {
                    break;
                }
                v0 = 6;
                a0 = (void *)s1;
                f12 = 0.0f;
                *(u32 *)(s1 + 0x158) = v0;
                a1 = 3;
                ChangeAnimParam(a0, a1, 0.0f);
                break;
            }
        case 2:
            a0 = (void *)*(s32 *)(s1 + 0x15c);
            v1 = (s32)((u8 *)a0 + 1);
            *(u32 *)(s1 + 0x15c) = v1;
            if ((s32)a0 > (s32)0x258) {
                v0 = 3;
                a0 = (void *)s1;
                *(u32 *)(s1 + 0x158) = v0;
                f12 = 0.0f;
                *(u32 *)(s1 + 0x15c) = 0;
                a1 = 1;
                *(u32 *)(s1 + 0x160) = v0;
                ChangeAnimParam(a0, a1, 0.0f);
                break;
            } else {
                a0 = (void *)*(s32 *)(s1 + 0x15c);
                v1 = 0x78;
                v1 = (s32)a0 % (s32)(0x78);
                if (v1 != 0) {
                    break;
                }
                v0 = rand();
                v1 = 0x64;
                v1 = (s32)v0 % (s32)(0x64);
                if ((s32)v1 < (s32)0xa) {
                    v0 = *(s32 *)(s1 + 0x158);
                    a1 = 4;
                    f12 = 0.0f;
                    a0 = (void *)s1;
                    *(u32 *)(s1 + 0x164) = v0;
                    *(u32 *)(s1 + 0x158) = a1;
                    ChangeAnimParam(a0, a1, 0.0f);
                    break;
                } else {
                    if ((s32)v1 > (s32)0x13) {
                        break;
                    }
                    v1 = *(s32 *)(s1 + 0x158);
                    v0 = 5;
                    f12 = 0.0f;
                    a0 = (void *)s1;
                    a1 = 2;
                    *(u32 *)(s1 + 0x164) = v1;
                    *(u32 *)(s1 + 0x158) = v0;
                    ChangeAnimParam(a0, a1, 0.0f);
                    break;
                }
            }
        case 3:
            v1 = *(s32 *)(s1 + 0x160);
            a0 = (void *)s1;
            v0 = (u32)BigMonkeyPath;
            v1 = v1 << 4;
            a1 = (s32)((u8 *)BigMonkeyPath + v1);
            SetModelTargetToPos(a0, (float *)a1);
            f0 = 0.0174499992f;
            f12 = *(float *)(s1 + 0x34);
            f13 = *(float *)(s1 + 0x198);
            f14 = (0.0174499992f * f20);
            f0 = Math_GotoAngle(f12, f13, f14);
            *(f32 *)(s1 + 0x34) = f0;
            f1 = *(float *)(s1 + 0x19c);
            v1 = 0x3e4ccccd;
            f0 = 0.200000003f;
            if (!(f1 < 0.200000003f)) {
                break;
            }
            a0 = (void *)*(s32 *)(s1 + 0x160);
            v1 = -1;
            a0 = (void *)((u8 *)a0 + -1);
            *(u32 *)(s1 + 0x160) = (s32)a0;
            if ((u32)(s32)a0 != v1) {
                break;
            }
            f12 = 0.0f;
            a0 = (void *)s1;
            *(u32 *)(s1 + 0x158) = 0;
            ChangeAnimParam(a0, 0, 0.0f);
            break;
        case 4:
            a0 = (void *)(s32)s0;
            v0 = CheckAnimEndFrame(a0);
            if (v0 == 0) {
                break;
            }
            v0 = *(s32 *)(s1 + 0x164);
            f12 = 0.0f;
            a0 = (void *)s1;
            *(u32 *)(s1 + 0x158) = v0;
            ChangeAnimParam(a0, 0, 0.0f);
            break;
        case 5:
            a0 = (void *)(s32)s0;
            v0 = CheckAnimEndFrame(a0);
            if (v0 == 0) {
                break;
            }
            v0 = *(s32 *)(s1 + 0x164);
            f12 = 0.0f;
            a0 = (void *)s1;
            *(u32 *)(s1 + 0x158) = v0;
            ChangeAnimParam(a0, 0, 0.0f);
            break;
        case 6:
            a0 = (void *)(s32)s0;
            v0 = CheckAnimEndFrame(a0);
            a1 = 1;
            if (v0 == 0) {
                break;
            }
            a0 = (void *)s1;
            f12 = 0.0f;
            *(u32 *)(s1 + 0x158) = a1;
            ChangeAnimParam(a0, a1, 0.0f);
        default:
            break;
        }
    }
    return;
}

static void ObjPrmInitFunc_CaveFace(void *a0 /* r4 */) {
    u8 *s0;
    u32 v0;
    u32 v1;

    *(u32 *)(((u8 *)a0 + 0x158)) = 0;
    s0 = (u8 *)a0;
    *(u32 *)(((u8 *)a0 + 0x10c)) = 0;
    *(u32 *)(((u8 *)a0 + 0x48)) = 0;
    *(u8 *)(((u8 *)a0 + 4)) = 0;
    v0 = rand();
    *(u32 *)(s0 + 0x164) = (s32)((s32)v0) % (s32)(4);
    v0 = rand();
    *(u32 *)(s0 + 0x168) = (s32)((s32)v0) % (s32)(4);
    a0 = (void *)*(s32 *)(s0 + 0x168);
    v1 = *(s32 *)(s0 + 0x164);
    if (v1 == (u32)(s32)a0) {
        *(u32 *)(s0 + 0x168) = (s32)((s32)((u8 *)a0 + 1)) % (s32)(4);
    }
    return;
}

/* ObjPrmProcFunc_CaveFace @ 0x17EF60 .. 0x17F178 (0x218 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x17efc4
 *   fpu: float literal 0x00000000 at 0x17f010
 *   fpu: float literal 0x42700000 at 0x17f078
 *   fpu: float literal 0x3f800000 at 0x17f0c4
 *   declaration vs inferred signature: return void vs inferred u32
 */

static void ObjPrmProcFunc_CaveFace(void *a0 /* r4 */) {
    u8 *s0;
    u32 a2;
    s32 a1;
    u32 v1;
    float f2;
    float f1;
    float f0;
    u32 v0;
    void *a0_2;

    a1 = 4;
    a2 = *(s32 *)(((u8 *)a0 + 0x158));
    s0 = (u8 *)a0;
    a0_2 = (void *)(s32)3;
    switch (a2) {
    case 0:
        return;
    case 1:
        v1 = 0x3f800000;
        f2 = *(float *)(s0 + 0x5c);
        f1 = (*(f32 *)(s0 + 0x10c) += f2);
        if (f1 < 1.0f) {
            break;
        }
        *(f32 *)(s0 + 0x10c) = 1.0f;
        *(u32 *)(s0 + 0x158) = a1;
        v0 = rand();
        v1 = 0x5dc;
        *(u32 *)(s0 + 0x15c) = (s32)v0 % 0x5dc;
        break;
    case 2:
        f2 = *(float *)(s0 + 0x5c);
        f1 = (*(f32 *)(s0 + 0x10c) -= f2);
        if (!(f1 <= 0.0f)) {
            break;
        }
        *(f32 *)(s0 + 0x10c) = 0.0f;
        *(u32 *)(s0 + 0x158) = (s32)a0_2;
        v0 = rand();
        v1 = 0x12c;
        *(u32 *)(s0 + 0x15c) = (s32)v0 % 0x12c;
        break;
    case 3:
    case 4:
        a0_2 = (void *)*(s32 *)(s0 + 0x15c);
        *(u32 *)(s0 + 0x15c) = (s32)((u8 *)a0_2 + -1);
        if ((u32)(s32)a0_2 != 0) {
            break;
        }
        v1 = *(s32 *)(s0 + 0x158);
        *(u32 *)(s0 + 0x158) = v1 + -2;
    }
    f1 = *(float *)(s0 + 0x10c);
    f0 = 60.0f;
    *(f32 *)(s0 + 0x48) = f1;
    v1 = *(s32 *)(s0 + 0xc);
    *(u32 *)((v1 + 0x6c)) = 0;
    v1 = *(s32 *)(s0 + 0xc);
    *(u32 *)((v1 + 0x70)) = 0;
    v1 = *(s32 *)(s0 + 0xc);
    *(u32 *)((v1 + 0x74)) = 0;
    f1 = ((float)*(s32 *)(s0 + 0x160));
    v1 = *(s32 *)(s0 + 0x164);
    f1 = f1;
    f1 = (f1 / 60.0f);
    if (v1 != 0) {
        v1 = v1 << 2;
        f0 = 1.0f;
        a0_2 = (void *)*(s32 *)(s0 + 0xc);
        *(f32 *)(((u32)(s32)((u8 *)v1 + (u32)(a0_2)) + 0x6c)) = (1.0f - f1);
    }
    v1 = *(s32 *)(s0 + 0x168);
    if (v1 != 0) {
        a0_2 = (void *)*(s32 *)(s0 + 0xc);
        v1 = v1 << 2;
        *(f32 *)(((u32)(s32)((u8 *)v1 + (u32)(a0_2)) + 0x6c)) = f1;
    }
    v1 = *(s32 *)(s0 + 0x160);
    v1 = v1 + 1;
    *(u32 *)(s0 + 0x160) = v1;
    v1 = (s32)v1 < (s32)0x3c;
    if (v1 == 0) {
        *(u32 *)(s0 + 0x160) = 0;
        v0 = *(s32 *)(s0 + 0x168);
        *(u32 *)(s0 + 0x164) = v0;
        v0 = rand();
        *(u32 *)(s0 + 0x168) = (s32)v0 % 4;
        a0_2 = (void *)*(s32 *)(s0 + 0x168);
        v1 = *(s32 *)(s0 + 0x164);
        if (v1 == (u32)(s32)a0_2) {
            *(u32 *)(s0 + 0x168) = (s32)((u8 *)a0_2 + 1) % 4;
        }
    }
    return;
}

void SetObjCaveFaceStart(void *a0 /* r4 */) {
    u8 *s0;
    u32 v0;
    float f0;

    s0 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x4c));
    a0 = (void *)*(u16 *)a0;
    if ((u32)a0 == (u32)0x18) {
        *(u32 *)(s0 + 0x158) = 1;
        *(u32 *)(s0 + 0x10c) = 0;
        v0 = rand();
        a0 = (void *)(s32)0x2711;
        f0 = 10000.0f;
        *(f32 *)(s0 + 0x5c) = (0.00499999989f + (0.00499999989f *
            ((float)((float)(s32)(u32)((s32)v0 % (s32)(0x2711))) / 10000.0f)));
    }
    return;
}

void SetObjMovePath(void *a0 /* r4 */, signed int a1 /* r5 */, unsigned short a2 /* r6 */, unsigned
        short a3 /* r7 */) {
    u8 a0_narrow; // a0
    u32 v1;
    u8 *v0;

    v1 = *(u8 *)a0;
    if (v1 != 0) {
        v0 = (u8 *)GetMovePath(3, a1);
        *(u16 *)(v0 + 0x210) = a3;
        v1 = 0x3f800000;
        *(u16 *)(v0 + 0x212) = a2;
        *(u32 *)(v0 + 0x214) = 0x3f800000;
        a1 = (u16)a2;
        *(u32 *)(((u8 *)a0 + 0x17c)) = (u32)v0;
        ChangeAnimParam((void *)a0, a1, 0.0f);
        a0_narrow = *(u8 *)(((u8 *)a0 + 0x18a));
        *(u8 *)(((u8 *)a0 + 0x18b)) = a0_narrow;
        *(u8 *)(((u8 *)a0 + 0x18a)) = 1;
    }
    return;
}


/* FreeObjMovePath @ 0x17EDF0 .. 0x17EE50 (0x60 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x17ee24
 *   declaration vs inferred signature: return void vs inferred u8
 */



void FreeObjMovePath(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u8 *a2;
    u8 a1;

    v1 = *(u8 *)a0;
    a2 = (u8 *)*(s32 *)(((u8 *)a0 + 0x17c));
    s0 = (u8 *)a0;
    if (v1 != 0 && (u32)(s32)a2 != 0) {
        a1 = *(u8 *)(s0 + 0x18a);
        v1 = 1;
        if ((u32)a1 == v1) {
            ChangeAnimParam(a0, *(u16 *)(a2 + 0x210), 0.0f);
            *(u32 *)(s0 + 0x17c) = 0;
            v1 = *(u8 *)(s0 + 0x18b);
            *(u8 *)(s0 + 0x18a) = v1;
        }
    }
    return;
}
static void ObjMovePathProc(void *object) {
    float angle, distance, x, z, turn;
    u8 *model = object;
    u8 *parameter = *(u8 **)(model + 0x17c);
    u8 *player = (u8 *)(MdlMng + 0x11800);
    if (parameter && model[0x18a] == 1) {
        x = *(float *)(player + 0x20) - *(float *)(model + 0x20);
        z = *(float *)(player + 0x28) - *(float *)(model + 0x28);
        angle = Math_VectorToAngle(-x, -z);
        distance = sqrtf(x * x + z * z);
        if (Math_GetAngleDist(*(float *)(model + 0x34), angle) < 0.0f)
            turn = -Math_GetAngleDist(*(float *)(model + 0x34), angle);
        else turn = Math_GetAngleDist(*(float *)(model + 0x34), angle);
        if (distance <= *(float *)(model + 0x110) + *(float *)(player + 0x110)) {
            if (turn <= 1.5704999f) {
                if ((u32)*(s16 *)(model + 0x104) == *(u16 *)(parameter + 0x212))
                    ChangeAnimParam(model, 0, 0.0f);
                return;
            }
        }
        {
            u16 animation = *(u16 *)(parameter + 0x212);
            if ((u32)*(s16 *)(model + 0x104) != animation) ChangeAnimParam(model, animation, 0.0f);
        }
        UpdateMovePath(model);
        {
            float coefficient = 0.01745f;
            float speed = *(float *)(parameter + 0x214);
            angle = Math_GotoAngle(*(float *)(model + 0x34), *(float *)(model + 0x198), coefficient * (float)speed);
            *(float *)(model + 0x34) = angle;
        }
    }
}
void SetObjTalkStart(struct dw_1058868_fields *lpObj, signed int TalkId, signed int AttackNo, signed int Num) {
    struct dw_1058868_fields *lpMy = (struct dw_1058868_fields *)(MdlMng + 0x11800);
    u8 *lpAnimCtrl = (u8 *)lpObj->lpAnimCtrl;
    u16 MsgFlag;
    int j;
    float AngDist;
    float ang;

    if (lpObj->CtrlMode != 2) {
        lpObj->State[9] = 1;
        lpObj->State[8] = TalkId;
        lpObj->State[7] = lpObj->IndexAnim;
        lpObj->State[6] = Num;
        lpObj->AttackNo = AttackNo;
        lpObj->CtrlModeB = lpObj->CtrlMode;
        lpObj->CtrlMode = 2;
        SetModelTargetToPos(lpObj, lpMy->Pos);
        AngDist = CAE_ABSF(Math_GetAngleDist(lpObj->Ang[1], lpObj->Target.angY));
        if (!(AngDist <= 0.17449999f) && CheckAnimParam(lpObj, 0x1f) != 0) {
            ang = CAE_ABSF(Math_GetAngleDist(CAE_WRAPF(1.5707964f + lpObj->Ang[1]), lpObj->Target.angY));
            if (ang < 1.5707964f) {
                ChangeAnimParam(lpObj, 0x1f, 0.0f);
            } else {
                ChangeAnimParam(lpObj, 0x1e, 0.0f);
            }
            lpObj->Target.angStep = AngDist / *(float *)(lpAnimCtrl + 0x10);
        } else {
            lpObj->State[9] = 2;
            ChangeAnimParam(lpObj, 0xa, 0.0f);
            MsgFlag = 0x10;
            if (lpObj->AttackNo == 0) {
                MsgFlag |= 1;
            }
            KnMsgMng_SendMsgEx(lpObj->State[8], 1, MsgFlag);
            if (lpObj->State[6] > 0) {
                for (j = 0; j < lpObj->State[6]; j++) {
                    KnMsgMng_SendMsgEx(lpObj->State[8] + j + 1, 1, MsgFlag);
                }
            }
        }
    }
}


/* SetObjTalkEnd @ 0x17E880 .. 0x17E8D0 (0x50 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x17e89c
 *   declaration vs inferred signature: return void vs inferred u8
 */



void SetObjTalkEnd(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u8 a1;

    v1 = 2;
    a1 = *(u8 *)(((u8 *)a0 + 0x18a));
    s0 = (u8 *)a0;
    if ((u32)a1 == v1) {
        ChangeAnimParam(a0, *(u16 *)(s0 + 0x170), 0.0f);
        *(u32 *)(s0 + 0x178) = 0;
        *(u32 *)(s0 + 0x174) = 0;
        *(u32 *)(s0 + 0x170) = 0;
        v1 = *(u8 *)(s0 + 0x18b);
        *(u8 *)(s0 + 0x18a) = v1;
    }
    return;
}
static void ObjTalkProc(struct dw_1058868_fields *lpObj) {
    struct dw_1064503_fields *lpAnimCtrl = lpObj->lpAnimCtrl;
    struct dw_1058868_fields *lpMy = (struct dw_1058868_fields *)(MdlMng + 0x11800);
    u16 MsgFlag;
    int j;

    if (lpObj->CtrlMode == 2) {
        switch (lpObj->State[9]) {
        case 1:
            SetModelTargetToPos(lpObj, lpMy->Pos);
            lpObj->Ang[1] = Math_GotoAngle(lpObj->Ang[1], lpObj->Target.angY, lpObj->Target.angStep);
            if (CheckAnimEndFrame(lpAnimCtrl)) {
                lpObj->State[9] = 2;
                ChangeAnimParam(lpObj, 0xa, 0.0f);
                MsgFlag = 0x10;
                if (lpObj->AttackNo == 0) {
                    MsgFlag |= 1;
                }
                KnMsgMng_SendMsgEx(lpObj->State[8], 1, MsgFlag);
                if (lpObj->State[6] > 0) {
                    for (j = 0; j < lpObj->State[6]; j++) {
                        KnMsgMng_SendMsgEx(lpObj->State[8] + j + 1, 1, MsgFlag);
                    }
                }
            }
            break;
        case 2:
            if (rand() % 100 <= 0x1d) {
                if (CheckAnimEndFrame(lpAnimCtrl)) {
                    if (CheckAnimParam(lpObj, 0xb)) {
                        ChangeAnimParam(lpObj, 0xb, 0.0f);
                    }
                }
            }
            break;
        }
    }
}

/* SetObjFollowTarget @ 0x17E6A0 .. 0x17E6F4 (0x54 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x17e6bc
 */

void SetObjFollowTarget(void *a0 /* r4 */, unsigned short a1 /* r5 */, unsigned short a2 /* r6 */,
        void *a3 /* r7 */) {
    u8 *a0_bytes; // a0
    u8 v1;
    s32 v0;

    a0_bytes = (u8 *)a0;
    v1 = *(u8 *)a0_bytes;
    if ((u32)v1 != 0) {
        v1 = *(u8 *)(a0_bytes + 0x18a);
        *(u8 *)(a0_bytes + 0x18b) = v1;
        *(u8 *)(a0_bytes + 0x18a) = 3;
        *(u32 *)(a0_bytes + 0x1b4) = (u32)a3;
        *(u16 *)(a0_bytes + 0x1a6) = a1;
        *(u16 *)(a0_bytes + 0x1a4) = a2;
        v0 = *(s16 *)(a0_bytes + 0x104);
        *(u16 *)(a0_bytes + 0x1a8) = v0;
        ChangeAnimParam((void *)a0_bytes, (u16)a1, 0.0f);
    }
    return;
}

void FreeObjFollowTarget(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u8 a1;

    v1 = *(u8 *)a0;
    s0 = (u8 *)a0;
    if (v1 != 0) {
        a1 = *(u8 *)(s0 + 0x18a);
        v1 = 3;
        if ((u32)a1 == v1) {
            ChangeAnimParam(a0, *(u16 *)(s0 + 0x1a8), 0.0f);
            v1 = *(u8 *)(s0 + 0x18b);
            *(u8 *)(s0 + 0x18a) = v1;
        }
    }
    return;
}

static void ObjFollowTargetProc(void *a0 /* r4 */) {
    u8 *s1;
    u32 a1;
    u8 *s0;
    float f14;
    s32 a0_scalar; // a0
    float f13;
    float f12;
    u32 v1;
    float f3;
    float f2;
    float f1;
    float f20;
    float f0;
    u32 v0;
    void *a0_2;
    float adjusted;
    float wrapped;

    v1 = 3;
    a1 = *(u8 *)(((u8 *)a0 + 0x18a));
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    s1 = (u8 *)a0;
    if (a1 == v1) {
        a1 = *(s32 *)(s1 + 0x1b4);
        SetModelTargetToModel(a0, (void *)a1);
        v1 = *(s32 *)(s1 + 0x1b4);
        f0 = *(float *)(s1 + 0x110);
        a1 = *(u16 *)(s1 + 0x1a6);
        a0_scalar = *(s16 *)(s1 + 0x104);
        f1 = *(float *)((v1 + 0x110));
        f2 = (f0 + f1);
        if ((u32)a0_scalar == a1) {
            v0 = 0x3dcccccd;
            f0 = 0.100000001f;
            f1 = *(float *)(s1 + 0x19c);
            if (f1 < (0.100000001f + f2)) {
                a1 = *(u16 *)(s1 + 0x1a4);
                f12 = 0.0f;
                a0_2 = (void *)s1;
                ChangeAnimParam(a0_2, a1, 0.0f);
            }
            f13 = *(float *)(s1 + 0x198);
            f14 = 0.0174499992f;
            f12 = *(float *)(s1 + 0x34);
            f0 = Math_GotoAngle(f12, f13, 0.0174499992f);
            *(f32 *)(s1 + 0x34) = f0;
        } else {
            v1 = *(u16 *)(s1 + 0x1a4);
            if ((u32)a0_scalar == v1) {
                v0 = 0x3f800000;
                f0 = 1.0f;
                f1 = *(float *)(s1 + 0x19c);
                f0 = (1.0f + f2);
                if (!(f1 <= f0)) {
                    f12 = 0.0f;
                    a0_2 = (void *)s1;
                    ChangeAnimParam(a0_2, a1, 0.0f);
                } else {
                    f13 = *(float *)(s1 + 0x198);
                    f12 = *(float *)(s1 + 0x34);
                    f0 = Math_GetAngleDist(f12, f13);
                    f1 = 0.0f;
                    if (f0 < 0.0f) {
                        f13 = *(float *)(s1 + 0x198);
                        f12 = *(float *)(s1 + 0x34);
                        f20 = (-Math_GetAngleDist(f12, f13));
                    } else {
                        f13 = *(float *)(s1 + 0x198);
                        f12 = *(float *)(s1 + 0x34);
                        f20 = Math_GetAngleDist(f12, f13);
                    }
                    v1 = 0x3f9c5a1c;
                    f0 = 1.22149992f;
                    a0_2 = (void *)s1;
                    if (!(f20 <= 1.22149992f)) {
                        a1 = 0x1f;
                        v0 = CheckAnimParam(a0_2, a1);
                        if (v0 != 0) {
                            f3 = *(float *)(s1 + 0x34);
                            v0 = 0x3fc90000;
                            v1 = 0x3fc90000 | 0xfdb;
                            f2 = 1.57079637f;
                            f1 = 3.14159274f;
                            f0 = 0.0f;
                            adjusted = 1.57079637f + f3;
                            wrapped = 3.14159274f + (1.57079637f + f3);
                            if (wrapped >= 0.0f) {
                                v0 = 0x40c90fdb;
                                f1 = 6.28318548f;
                                f12 = adjusted - (6.28318548f * (float)(s32)(wrapped / 6.28318548f));
                            } else {
                                v0 = 0x40c90fdb;
                                f1 = 6.28318548f;
                                f12 = f1 + (adjusted - (f1 * (float)(s32)(wrapped / f1)));
                            }
                            f13 = *(float *)(s1 + 0x198);
                            f0 = Math_GetAngleDist(f12, f13);
                            if (f0 < 0.0f) {
                                v0 = 0x3fc90000;
                                v1 = 0x3fc90000 | 0xfdb;
                                f1 = 1.57079637f;
                                f0 = 3.14159274f;
                                f3 = *(float *)(s1 + 0x34);
                                f3 = 1.57079637f + (float)f3;
                                f0 = 3.14159274f + f3;
                                if (f0 >= 0.0f) {
                                    v0 = 0x40c90fdb;
                                    f1 = 6.28318548f;
                                    f12 = (f3 - (6.28318548f * (float)((float)(s32)(f0 /
                                        6.28318548f))));
                                } else {
                                    v0 = 0x40c90fdb;
                                    f1 = 6.28318548f;
                                    f12 = (f1 + (f3 - (f1 * (float)((float)(s32)(f0 / f1)))));
                                }
                                f13 = *(float *)(s1 + 0x198);
                                f0 = (-Math_GetAngleDist(f12, f13));
                            } else {
                                v1 = 0x3fc90fdb;
                                f1 = 1.57079637f;
                                f0 = 3.14159274f;
                                f3 = *(float *)(s1 + 0x34);
                                f3 = 1.57079637f + (float)f3;
                                f0 = 3.14159274f + f3;
                                if (f0 >= 0.0f) {
                                    v0 = 0x40c90fdb;
                                    f1 = 6.28318548f;
                                    f12 = (f3 - (6.28318548f * (float)((float)(s32)(f0 /
                                        6.28318548f))));
                                } else {
                                    v0 = 0x40c90fdb;
                                    f1 = 6.28318548f;
                                    f12 = (f1 + (f3 - (f1 * (float)((float)(s32)(f0 / f1)))));
                                }
                                f13 = *(float *)(s1 + 0x198);
                                f0 = Math_GetAngleDist(f12, f13);
                            }
                            v0 = 0x3fc90fdb;
                            f1 = 1.57079637f;
                            if (f0 < 1.57079637f) {
                                f12 = 0.0f;
                                a0_2 = (void *)s1;
                                a1 = 0x1f;
                                ChangeAnimParam(a0_2, a1, 0.0f);
                            } else {
                                a0_2 = (void *)s1;
                                f12 = 0.0f;
                                a1 = 0x1e;
                                ChangeAnimParam(a0_2, a1, 0.0f);
                            }
                            *(f32 *)(s1 + 0x1a0) = (f20 / *(float *)(s0 + 0x10));
                        }
                    }
                }
            } else {
                v1 = 0x1f;
                if ((u32)a0_scalar != v1) {
                    v1 = 0x1e;
                    if ((u32)a0_scalar != v1) {
                        goto _L0017E638;
                    }
                }
                a0_2 = (void *)s0;
                v0 = CheckAnimEndFrame(a0_2);
                if (v0 != 0) {
                    a1 = *(u16 *)(s1 + 0x1a4);
                    f12 = 0.0f;
                    a0_2 = (void *)s1;
                    ChangeAnimParam(a0_2, a1, 0.0f);
                }
                f13 = *(float *)(s1 + 0x198);
                f12 = *(float *)(s1 + 0x34);
                f0 = Math_GotoAngle(f12, f13, *(float *)(s1 + 0x1a0));
                *(f32 *)(s1 + 0x34) = f0;
            }
        }
    }
    _L0017E638:;
    return;
}

void ItemAppear(s32 index,u8 *model,u32 position,u32 rotation,u32 scale)
{
    u16 *params;
    float factor;
    if(SetMdlMng(model,(u8 *)MdlData+(index+288)*1664)!=0) {
        sceVu0CopyVector(model+0x20,(void *)position);
        *(float *)(model+0x2c)=1.0f;
        sceVu0CopyVector(model+0x70,model+0x20);
        sceVu0CopyVector(model+0x30,(void *)rotation);
        sceVu0CopyVector(model+0x80,model+0x30);
        sceVu0CopyVector(model+0x40,(void *)scale);
        *(u16 *)(model+0x192)=0xffff;
        *(void **)(model+0x140)=GetMapPartsInfo(7,((s32)model-(s32)(MdlMng+0xfc00))/448);
        params=*(u16 **)(*(u8 **)(model+12)+76);
        if(params==0) {
            params=DmyObjPrm;
            DmyObjPrm[11]=90;DmyObjPrm[12]=160;
            DmyObjPrm[16]=100;DmyObjPrm[18]=100;DmyObjPrm[20]=0;
        }
        *(u16 **)(*(u8 **)(model+12)+76)=params;
        sceVu0ScaleVectorXYZ(model+64,model+64,(float)(u32)params[16]/100.0f);
        factor=(float)(u32)params[11]/100.0f;
        *(float *)(model+0x110)=factor**(float *)(model+64);
        factor=(float)(u32)params[12]/100.0f;
        *(float *)(model+0x114)=factor**(float *)(model+68);
        factor=(float)(u32)params[18]/100.0f;
        *(float *)(model+0x118)=factor**(float *)(model+64);
        factor=(float)(u32)params[20]/100.0f;
        *(float *)(model+0x11c)=factor**(float *)(model+64);
        PlayMi3(model);
        if(*(u32 *)(*(u8 **)(model+12)+72)!=0) DssPlay4Init(model);
    }
}

void InitFadeItem(signed int a0 /* r4 */, signed int a1 /* r5 */) {
    u32 s0;
    u32 v0;

    s0 = a1;
    v0 = GetMdlMngIndexByCtrlId(7, a0);
    a1 = v0 + 0x90;
    a0 = s0;
    v0 = (u32)MdlMng;
    s0 = (s32)((u8 *)MdlMng + (s32)((u32)((u32)a1) * (u32)(0x1c0)));
    v0 = CheckEventFlag(a0);
    if (v0 != 0) {
        *(u32 *)((s0 + 0x10c)) = 0;
    }
    return;
}
