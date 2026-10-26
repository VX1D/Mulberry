#include "common.h"

/* CheckRiddleMode @ 0x1A2330 .. 0x1A2340 (0x10 bytes) */
/*
 * dcomp notes:
 *   return: sltu at 0x1a233c computes the return value
 */

extern u8 RiddleMng[];

/* Riddle003UpdateAmbient @ 0x1A2340 .. 0x1A2470 (0x130 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: lui at 0x1a23dc writes a register its branch at 0x1a23d8 reads
 *   fpu: float literal 0x3e99999a at 0x1a2404
 *   cfg: loop body is not one contiguous region: .L001A2380
 *   cfg: loop body is not one contiguous region: .L001A23D0
 */

extern signed int SND_Play2D(signed int, signed short, signed short);
extern u8 MdlMng[];

extern unsigned int CheckAnimEndFrame(void *);
extern void sceVu0CopyVector(void *, void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern u32 R003_CurReferBoxId[];
extern u32 R003_BlockPos[];


typedef struct R003GodShelf { u8 NowCur; u8 Complete; u8 unused[2]; u8 Box[12]; } R003GodShelf;
typedef struct R003Mdl { u8 pad0[0x20]; float Pos[4]; u8 pad1[0xd0]; void *lpAnimCtrl; s16 IndexAnim; u8 pad2[0xba]; } R003Mdl;

static inline u32 R003_CheckComplete(void) {
    R003GodShelf *g = (R003GodShelf *)(RiddleMng + 0x38);
    s32 i;
    if (*(s32 *)RiddleMng != 5) {
        return 0;
    }
    for (i = 0; i < 12; i++) {
        if (i != g->Box[i]) {
            return 0;
        }
    }
    return 1;
}


/* PlayRiddle003 @ 0x1A26D0 .. 0x1A29BC (0x2ec bytes, frame 0x70) */
/*
 * dcomp notes:
 *   delay: dsll32 at 0x1a2728 writes a register its branch at 0x1a2724 reads
 *   delay: dsll32 at 0x1a277c writes a register its branch at 0x1a2778 reads
 *   fpu: float literal 0x00000000 at 0x1a27ec
 *   fpu: float literal 0x00000000 at 0x1a2840
 *   stack: address of the slot at 0x60 escapes at 0x1a28c8
 *   stack: address of the slot at 0x60 escapes at 0x1a2900
 *   delay: addiu at 0x1a2928 writes a register its branch at 0x1a2924 reads
 *   stack: address of the slot at 0x50 escapes at 0x1a2934
 *   stack: address of the slot at 0x50 escapes at 0x1a296c
 *   cfg: kept branch: 0x1a2728 if (..) goto .L001A2770
 *   cfg: kept goto: 0x1a2758 -> .L001A2880
 *   cfg: kept branch: 0x1a277c if (..) goto .L001A27C8
 *   cfg: kept goto: 0x1a27b0 -> .L001A2880
 *   cfg: loop body is not one contiguous region: .L001A2820
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void Riddle003BlockUpdate(void);
extern void SetFadeMng(unsigned char, signed int *, signed int, void *, void *, signed int,
    signed int);
static u32 EndRiddleModeFunc(void);
extern u32 lpPadData;
extern u8 GameSt[];
extern u32 R003_CurReferBoxId[];


extern signed int KnMsgMng_SendMsg(signed int);
extern u32 KnMsgMng_CheckMsgNone();
extern void SetFadeMng(unsigned char, signed int *, signed int, void *, void *, signed int,
                       signed int);
static u32 EndRiddleModeFunc(void);


/* PlayRiddle002 @ 0x1A30A0 .. 0x1A34F0 (0x450 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x70 escapes at 0x1a3338
 *   stack: address of the slot at 0x70 escapes at 0x1a3370
 *   stack: address of the slot at 0x80 escapes at 0x1a33d8
 *   stack: address of the slot at 0x80 escapes at 0x1a342c
 *   stack: address of the slot at 0x60 escapes at 0x1a3478
 *   stack: address of the slot at 0x60 escapes at 0x1a34b0
 *   cfg: kept branch: 0x1a32f8 if (..) goto .L001A33C0
 *   cfg: kept branch: 0x1a3308 if (..) goto .L001A33C0
 *   declaration vs inferred signature: return void vs inferred u32
 */


extern signed int ItemMng_Add_Direct(unsigned short, signed short);


struct dw_1536886_fields;
struct dw_1558366_fields;
#ifndef PROTO_DW_1534476_FIELDS
#define PROTO_DW_1534476_FIELDS
struct dw_1534476_fields { unsigned char Disc1Now; unsigned char Disc2Now; unsigned char Disc3Now; char Disc1Dir; char Disc2Dir; char Disc3Dir; unsigned char Disc1Lock; unsigned char Disc2Lock; unsigned char Disc3Lock; unsigned char unused[3]; };
#endif
#ifndef PROTO_DW_1541538_FIELDS
#define PROTO_DW_1541538_FIELDS
struct dw_1541538_fields { unsigned char WoodBoard[3]; unsigned char NowCur; unsigned char CurState[3]; unsigned char MsgState; unsigned char NailNum; unsigned char SilkWormNum; unsigned char CrowNum; unsigned char BrokenNum; };
#endif
#ifndef PROTO_DW_1546127_FIELDS
#define PROTO_DW_1546127_FIELDS
struct dw_1546127_fields { unsigned char NowCur; unsigned char Complete; unsigned char unused[2]; unsigned char Box[12]; };
#endif
#ifndef PROTO_DW_1534919_FIELDS
#define PROTO_DW_1534919_FIELDS
struct dw_1534919_fields { int State; int No; int Timer; int Result; unsigned char *lpRiddleBuf; int TutorialMsgId; int TutorialFlag; int unused[1]; struct dw_1534476_fields Pelorus; struct dw_1541538_fields Buddhist; struct dw_1546127_fields GodShelf; };
#endif
#ifndef PROTO_DW_1557756_FIELDS
#define PROTO_DW_1557756_FIELDS
struct dw_1557756_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_1552191_FIELDS
#define PROTO_DW_1552191_FIELDS
struct dw_1552191_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_1551868_FIELDS
#define PROTO_DW_1551868_FIELDS
struct dw_1551868_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_1536886_fields *lpMdl; };
#endif
#ifndef PROTO_DW_1536886_FIELDS
#define PROTO_DW_1536886_FIELDS
struct dw_1536886_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_1558366_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_1536886_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_1557756_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_1552191_fields flags; unsigned char _pad1[3]; struct dw_1551868_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_1555757_FIELDS
#define PROTO_DW_1555757_FIELDS
struct dw_1555757_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_CURSTATE__0___545B22F4_DEFINED
#define DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_CURSTATE__0___545B22F4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_CURSTATE__0___545B22F4 = (int)&(((struct dw_1534919_fields *)0)->Buddhist.CurState[0]) - 44 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_MSGSTATE_81B9FA9F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_MSGSTATE_81B9FA9F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_MSGSTATE_81B9FA9F = (int)&(((struct dw_1534919_fields *)0)->Buddhist.MsgState) - 44 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_NOWCUR_B7A73430_DEFINED
#define DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_NOWCUR_B7A73430_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_NOWCUR_B7A73430 = (int)&(((struct dw_1534919_fields *)0)->Buddhist.NowCur) - 44 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_0__23643E9D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_0__23643E9D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_0__23643E9D = (int)&(((struct dw_1534919_fields *)0)->Buddhist.WoodBoard[0]) - 44 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_1__54FB7A91_DEFINED
#define DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_1__54FB7A91_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_1__54FB7A91 = (int)&(((struct dw_1534919_fields *)0)->Buddhist.WoodBoard[1]) - 44 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_2__24E81980_DEFINED
#define DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_2__24E81980_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_2__24E81980 = (int)&(((struct dw_1534919_fields *)0)->Buddhist.WoodBoard[2]) - 44 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1534919_FIELDS_RESULT_7297F4CD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1534919_FIELDS_RESULT_7297F4CD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1534919_FIELDS_RESULT_7297F4CD = (int)&(((struct dw_1534919_fields *)0)->Result) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1534919_FIELDS_STATE_4B5175A4_DEFINED
#define DCOMP_OFF_STRUCT_DW_1534919_FIELDS_STATE_4B5175A4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1534919_FIELDS_STATE_4B5175A4 = (int)&(((struct dw_1534919_fields *)0)->State) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1536886_FIELDS_LPANIMCTRL_7C6525FF_DEFINED
#define DCOMP_OFF_STRUCT_DW_1536886_FIELDS_LPANIMCTRL_7C6525FF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1536886_FIELDS_LPANIMCTRL_7C6525FF = (int)&(((struct dw_1536886_fields *)0)->lpAnimCtrl) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1555757_FIELDS_PADPORT_A508C3F7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1555757_FIELDS_PADPORT_A508C3F7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1555757_FIELDS_PADPORT_A508C3F7 = (int)&(((struct dw_1555757_fields *)0)->padport) - 0 };
#endif


extern void RemapBinderFile(void *);
extern unsigned int GetBindOffsetByIndex(void *, unsigned short);
extern void SetMdlBndFile(signed int);
extern unsigned int SetMdlMng(void *, void *);
extern void * memset(void *, int, unsigned int);
extern unsigned short ItemMng_GetItemNum_Direct(unsigned short);
extern u32 MdlData[];


/* PlayRiddle001 @ 0x1A3620 .. 0x1A447C (0xe5c bytes, frame 0x70) */
/*
 * dcomp notes:
 *   delay: dsll32 at 0x1a36d0 writes a register its branch at 0x1a36cc reads
 *   delay: dsll32 at 0x1a3744 writes a register its branch at 0x1a3740 reads
 *   delay: addiu at 0x1a37fc writes a register its branch at 0x1a37f8 reads
 *   stack: address of the slot at 0x60 escapes at 0x1a3834
 *   stack: address of the slot at 0x60 escapes at 0x1a386c
 *   fpu: float literal 0x3c8ef34d at 0x1a38c8
 *   fpu: mtc1 reinterprets a0 at 0x1a38d4
 *   fpu: mtc1 reinterprets v1 at 0x1a3904
 *   fpu: mtc1 reinterprets a0 at 0x1a3918
 *   fpu: float literal 0x41f00000 at 0x1a3930
 *   fpu: float literal 0x3c8ef34d at 0x1a3938
 *   fpu: float literal 0x40490fdb at 0x1a395c
 *   fpu: float literal 0x00000000 at 0x1a3960
 *   fpu: float literal 0x40c90fdb at 0x1a3980
 *   fpu: mtc1 reinterprets v1 at 0x1a39a4
 *   delay: dsll32 at 0x1a3a24 writes a register its branch at 0x1a3a20 reads
 *   delay: dsll32 at 0x1a3ac4 writes a register its branch at 0x1a3ac0 reads
 *   fpu: float literal 0x3c8ef34d at 0x1a3c48
 *   fpu: mtc1 reinterprets a2 at 0x1a3c54
 *   fpu: mtc1 reinterprets a2 at 0x1a3c74
 *   fpu: mtc1 reinterprets v1 at 0x1a3ca4
 *   fpu: mtc1 reinterprets a2 at 0x1a3cb8
 *   fpu: float literal 0x41f00000 at 0x1a3cd0
 *   fpu: float literal 0x3c8ef34d at 0x1a3cd8
 *   fpu: mtc1 reinterprets v1 at 0x1a3cf8
 *   fpu: mtc1 reinterprets a2 at 0x1a3d0c
 *   fpu: float literal 0x41f00000 at 0x1a3d24
 *   fpu: float literal 0x3c8ef34d at 0x1a3d2c
 *   fpu: float literal 0x40490fdb at 0x1a3d4c
 *   fpu: float literal 0x00000000 at 0x1a3d50
 *   fpu: float literal 0x40c90fdb at 0x1a3d70
 *   fpu: mtc1 reinterprets v1 at 0x1a3d94
 *   fpu: float literal 0x40490fdb at 0x1a3dc4
 *   fpu: float literal 0x00000000 at 0x1a3dc8
 *   fpu: float literal 0x40c90fdb at 0x1a3de8
 *   fpu: mtc1 reinterprets v1 at 0x1a3e0c
 *   delay: dsll32 at 0x1a3e8c writes a register its branch at 0x1a3e88 reads
 *   delay: dsll32 at 0x1a3f54 writes a register its branch at 0x1a3f50 reads
 *   stack: address of the slot at 0x50 escapes at 0x1a406c
 *   stack: address of the slot at 0x50 escapes at 0x1a40a4
 *   fpu: float literal 0x3c8ef34d at 0x1a4158
 *   fpu: mtc1 reinterprets a3 at 0x1a4164
 *   fpu: mtc1 reinterprets a3 at 0x1a4184
 *   fpu: mtc1 reinterprets a3 at 0x1a41a4
 *   fpu: mtc1 reinterprets a2 at 0x1a41d4
 *   fpu: mtc1 reinterprets a3 at 0x1a41e8
 *   fpu: float literal 0x41f00000 at 0x1a4200
 *   fpu: float literal 0x3c8ef34d at 0x1a4208
 *   fpu: mtc1 reinterprets a2 at 0x1a4228
 *   fpu: mtc1 reinterprets a3 at 0x1a423c
 *   fpu: float literal 0x41f00000 at 0x1a4254
 *   fpu: float literal 0x3c8ef34d at 0x1a425c
 *   fpu: mtc1 reinterprets a2 at 0x1a427c
 *   fpu: mtc1 reinterprets a3 at 0x1a4290
 *   fpu: float literal 0x41f00000 at 0x1a42a8
 *   fpu: float literal 0x3c8ef34d at 0x1a42b0
 *   fpu: float literal 0x40490fdb at 0x1a42d4
 *   fpu: float literal 0x00000000 at 0x1a42d8
 *   fpu: float literal 0x40c90fdb at 0x1a42f8
 *   fpu: mtc1 reinterprets a2 at 0x1a431c
 *   fpu: float literal 0x40490fdb at 0x1a434c
 *   fpu: float literal 0x00000000 at 0x1a4350
 *   fpu: float literal 0x40c90fdb at 0x1a4370
 *   fpu: float literal 0x40c90fdb at 0x1a4398
 *   fpu: float literal 0x40490fdb at 0x1a43c8
 *   fpu: float literal 0x00000000 at 0x1a43cc
 *   fpu: float literal 0x40c90fdb at 0x1a43ec
 *   fpu: float literal 0x40c90fdb at 0x1a4414
 *   cfg: kept branch: 0x1a36d0 if (..) goto .L001A3738
 *   cfg: kept goto: 0x1a3720 -> .L001A4460
 *   cfg: kept branch: 0x1a3744 if (..) goto .L001A37B0
 *   cfg: kept goto: 0x1a3798 -> .L001A4460
 *   cfg: kept branch: 0x1a3a24 if (..) goto .L001A3AB8
 *   cfg: kept goto: 0x1a3aa0 -> .L001A4460
 *   cfg: kept branch: 0x1a3ac4 if (..) goto .L001A3B58
 *   cfg: kept goto: 0x1a3b40 -> .L001A4460
 *   cfg: kept branch: 0x1a3e8c if (..) goto .L001A3F48
 *   cfg: kept goto: 0x1a3f30 -> .L001A4460
 *   cfg: kept branch: 0x1a3f54 if (..) goto .L001A4010
 *   cfg: kept goto: 0x1a3ff8 -> .L001A4460
 *   declaration vs inferred signature: return void vs inferred u32
 *   return value dropped: the function is void
 */



#ifndef PROTO_DW_1534476_FIELDS
#define PROTO_DW_1534476_FIELDS

#endif
#ifndef PROTO_DW_1541538_FIELDS
#define PROTO_DW_1541538_FIELDS

#endif
#ifndef PROTO_DW_1546127_FIELDS
#define PROTO_DW_1546127_FIELDS

#endif
#ifndef PROTO_DW_1534919_FIELDS
#define PROTO_DW_1534919_FIELDS

#endif
#ifndef PROTO_DW_1557756_FIELDS
#define PROTO_DW_1557756_FIELDS

#endif
#ifndef PROTO_DW_1552191_FIELDS
#define PROTO_DW_1552191_FIELDS

#endif
#ifndef PROTO_DW_1551868_FIELDS
#define PROTO_DW_1551868_FIELDS

#endif
#ifndef PROTO_DW_1536886_FIELDS
#define PROTO_DW_1536886_FIELDS

#endif
#ifndef PROTO_DW_1555757_FIELDS
#define PROTO_DW_1555757_FIELDS

#endif
#ifndef PROTO_DW_1561754_FIELDS
#define PROTO_DW_1561754_FIELDS
struct dw_1561754_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_1558366_FIELDS
#define PROTO_DW_1558366_FIELDS
struct dw_1558366_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_1561754_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_EXPR_F4392B91E5A8C94E
#define DCOMP_EXPR_F4392B91E5A8C94E(dcomp_arg) ((3.1415927f + (dcomp_arg)) >= 0.0f ? ((dcomp_arg) - (6.2831855f * (float)(s32)((3.1415927f + (dcomp_arg)) / 6.2831855f))) : (6.2831855f + ((dcomp_arg) - (6.2831855f * (float)(s32)((3.1415927f + (dcomp_arg)) / 6.2831855f)))))
#endif

struct PrObj { float Position[4]; float Angle[4]; float Scale[4]; short ObjectId; short GeomObjectId; short ParentObjectId; short ChildObjectId; short SiblingObjectId; short MatrixNum; unsigned short *lpMatrixId; int PrimListNum; void *lpPrimHead; unsigned short PolyNum; unsigned short TreeNum; void *lpBoundBox; char *lpObjectName; void *lpObjParam; void *lpTree; void *lpObjReserve; };
struct PrObjB { float Position[4]; float Angle[4]; float Scale[4]; short ObjectId; short GeomObjectId; short ParentObjectId; short ChildObjectId; short SiblingObjectId; short MatrixNum; unsigned short *lpMatrixId; int PrimListNum; void *lpPrimHead; unsigned short PolyNum; unsigned short TreeNum; void *lpBoundBox; char *lpObjectName; void *lpObjParam; void *lpTree; void *lpObjReserve; };
#define RM ((struct dw_1534919_fields *)RiddleMng)
#define RM_STATE (*(s32 *)(RiddleMng + 0))
#define RM_TIMER (*(s32 *)(RiddleMng + 8))
#define RM_RESULT (*(s32 *)(RiddleMng + 0xc))
#define PB(off, n) (((struct { unsigned char _p : n; unsigned char f : 1; } *)((u8 *)lpPad + (off)))->f)
#define PB0(off) (((struct { unsigned char f : 1; } *)((u8 *)lpPad + (off)))->f)
#define ANG(o, v) (o)->Angle[1] = (o)->Angle[1] + 0.01745f * (float)(v)
#define SNAP(o, now) ((struct PrObjB *)(o))->Angle[1] = 0.01745f * (30.0f * (float)(unsigned int)(now))
#define WRP(o) (o)->Angle[1] = CAE_WRAPF((o)->Angle[1])
#define CAE_WRAPF(a) ((3.14159274f + (a) >= 0.0f) ? ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f)) : (6.28318548f + ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f))))
#define DEC(x) if ((x) == 0) { (x) = 0xb; } else { (x) = (x) - 1; }
#define INC(x) if ((x) == 0xb) { (x) = 0; } else { (x) = (x) + 1; }
#define COL(m, v) (m)->AmbientCol[0] = (v); (m)->AmbientCol[1] = (v); (m)->AmbientCol[2] = (v)










#define R001_WrapAng(x) ((3.1415927f + (x)) >= 0.0f ? ((x) - (6.2831855f * (float)(s32)((3.1415927f + (x)) / 6.2831855f))) : (6.2831855f + ((x) - (6.2831855f * (float)(s32)((3.1415927f + (x)) / 6.2831855f)))))


/* PlayRiddle @ 0x1A4850 .. 0x1A496C (0x11c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1a4868 writes a register its branch at 0x1a4864 reads
 *   delay: addiu at 0x1a48f8 writes a register its branch at 0x1a48f4 reads
 *   delay: addiu at 0x1a4950 writes a register its branch at 0x1a494c reads
 *   cfg: kept branch: 0x1a4880 if (..) goto .L001A48C8
 *   cfg: kept branch: 0x1a488c if (..) goto .L001A48B8
 *   cfg: kept goto: 0x1a48ac -> .L001A48C8
 *   cfg: kept goto: 0x1a48c8 -> .L001A4960
 *   cfg: kept branch: 0x1a48d0 if (..) goto .L001A4960
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int CheckNowFade(signed int);
extern signed int Menu_TD_CallOrder(signed int, signed int, signed int);
extern signed int Menu_TD_IsPlay(void);
extern void PlayRiddle001(void);
extern void PlayRiddle002(void);
extern void PlayRiddle003(void);

/* GetRiddleResult @ 0x1A4970 .. 0x1A497C (0xc bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1a4978 computes the return value
 *   spans: lui at at 0x1a4970 read at 0x1a4978 before its %lo
 */

extern u8 RiddleMng[];

/* CheckFreeRiddleData @ 0x1A49B0 .. 0x1A49EC (0x3c bytes, frame 0x10) */

static u32 FreeRiddleMdlMng();
static u32 FreeRiddleMdlData();
extern u8 RiddleMng[];
extern u8 GameSt[];

/* CheckRiddleFree @ 0x1A49F0 .. 0x1A4A44 (0x54 bytes, frame 0x10) */

static u32 FreeRiddleMdlData();
extern void SetCamCtrlMode(unsigned int);
extern void FECard_Enable_Draw(signed int);
extern u8 RiddleMng[];
extern u8 GameSt[];

/* FreeRiddleMdlData @ 0x1A4A50 .. 0x1A4B48 (0xf8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1a4a80 writes a register its branch at 0x1a4a7c reads
 *   declaration vs inferred signature: return u32 vs inferred void
 *   return without a value in a non-void function
 */

extern void FreeMdlData(void *, signed int);
extern void MemFree(void *);
extern u32 MdlData[];

/* FreeRiddleMdlMng @ 0x1A4B50 .. 0x1A4C34 (0xe4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1a4b80 writes a register its branch at 0x1a4b7c reads
 *   return without a value in a non-void function
 */

extern void FreeMdlMng(void *);
extern u8 MdlMng[];

extern void PadVibAllClear(void);
extern void PadUpdate();
extern void SetCameraPos(float *);
extern void SetCameraAng(float *);
extern void DrawSetViewRange();
extern void DrawCalcView();
extern void InitRiddle001();
extern void InitRiddle003();
extern u32 lpDrawMng;
static u32 R003_BaseButtonPos[0x1c] = {
    0xbe99999a, 0x3dcccccd, 0, 0x3f800000, 0xbe99999a, 0, 0, 0x3f800000, 0xbe99999a, 0xbdcccccd,
    0, 0x3f800000, 0xbe19999a, 0xbe800000, 0, 0x3f800000, 0xbd4ccccd, 0xbe800000, 0, 0x3f800000,
    0x3d4ccccd, 0xbe800000, 0, 0x3f800000, 0x3e19999a, 0xbe800000, 0, 0x3f800000
};
static u32 R003_BaseBlockPos[0x30] = {
    0xbe19999a, 0xbdcccccd, 0, 0x3f800000, 0xbd4ccccd, 0xbdcccccd, 0, 0x3f800000, 0x3d4ccccd,
    0xbdcccccd, 0, 0x3f800000, 0x3e19999a, 0xbdcccccd, 0, 0x3f800000, 0xbe19999a, 0, 0,
    0x3f800000, 0xbd4ccccd, 0, 0, 0x3f800000, 0x3d4ccccd, 0, 0, 0x3f800000, 0x3e19999a, 0, 0,
    0x3f800000, 0xbe19999a, 0x3dcccccd, 0, 0x3f800000, 0xbd4ccccd, 0x3dcccccd, 0, 0x3f800000,
    0x3d4ccccd, 0x3dcccccd, 0, 0x3f800000, 0x3e19999a, 0x3dcccccd, 0, 0x3f800000
};
static u32 R003_CurReferBoxId[0x1c] = {
    8, 9, 0xa, 0xb, 4, 5, 6, 7, 0, 1, 2, 3, 0, 4, 8, 0xffffffff, 1, 5, 9, 0xffffffff, 2, 6, 0xa,
    0xffffffff, 3, 7, 0xb, 0xffffffff
};


/* EndRiddleModeFunc @ 0x1A4DC0 .. 0x1A4DE8 (0x28 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

static u32 FreeRiddleMdlMng();
extern u8 RiddleMng[];

/* StartRiddleModeFunc @ 0x1A4DF0 .. 0x1A4E54 (0x64 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   literal: @2406 is the string 'riddle/r%03d.bnd'
 *   stack: address of the slot at 0x10 escapes at 0x1a4e10
 *   stack: address of the slot at 0x10 escapes at 0x1a4e34
 *   return without a value in a non-void function
 */

extern void PadVibAllClear(void);
extern int sprintf(void *, void *, ...);
extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);

/* SetRiddleMode @ 0x1A4E60 .. 0x1A4EFC (0x9c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x20 escapes at 0x1a4e7c
 *   stack: address of the slot at 0x20 escapes at 0x1a4eb4
 */

extern void SetFadeMng(unsigned char, signed int *, signed int, void *, void *, signed int, signed
    int);

/* InitRiddle003 @ 0x1A29C0 .. 0x1A2D10 (0x350 bytes, frame 0xb0) */








extern u32 R003_ButtonPos[];





#define BTN ((float (*)[4])R003_ButtonPos)
#define BBTN ((float (*)[4])R003_BaseButtonPos)
#define BLK ((float (*)[4])R003_BlockPos)
#define BBLK ((float (*)[4])R003_BaseBlockPos)

static inline void R3SetMdlMng(lpMdlMng, lpMdlData)
    u8 *lpMdlMng;
    u32 lpMdlData;
{
    SetMdlMng(lpMdlMng, (void *)(lpMdlData + 0x680));
}


static u8 RiddleMng[0x48];
static u32 R003_ButtonPos[0x1c];
static u32 R003_BlockPos[0x30];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetRiddleMode(signed int a0 );
static u32 StartRiddleModeFunc(void);
void SetRiddleData(void);
void CheckRiddleFree(void);
void CheckFreeRiddleData(void);
u32 GetRiddleFreeState(void);
u32 GetRiddleResult(void);
void PlayRiddle(void);
void InitRiddle002(void);
signed int Riddle002CheckMsg(void);
static void Riddle003UpdateAmbient(void);
u32 CheckRiddleMode(void);


void SetRiddleMode(signed int a0 /* r4 */) {
    s32 s0;

    s0 = a0;
    {
        u8 stackFrame_20[16] __attribute__((aligned(16))) = {0};
        SetFadeMng(5, (signed int *)(u8 *)((u8 *)&stackFrame_20[0]), 0x1e, (void *)0,
            StartRiddleModeFunc, 0, 0);
        ((u32 *)RiddleMng)[1] = s0;
        *(u32 *)RiddleMng = 1;
        ((u32 *)RiddleMng)[3] = -1;
        ((u32 *)RiddleMng)[4] = 0;
        FECard_Enable_Draw(0);
        return;
    }
}

static u32 StartRiddleModeFunc(void) {
    u32 a1;
    u8 stackFrame_10[128] __attribute__((aligned(16)));

    PadVibAllClear();
    a1 = (u32)"riddle/r%03d.bnd";
    sprintf((void *)(u8 *)((u8 *)&stackFrame_10[0]), (void *)"riddle/r%03d.bnd", *(s32 *)(RiddleMng + 0x4));
    a1 = -1;
    FileRead((char *)(u8 *)((u8 *)&stackFrame_10[0]), a1, (unsigned char **)((u8 *)RiddleMng +
        0x10), 0, a1, 0x1d, 0);
    *(u32 *)RiddleMng = 2;
    return;
}

static u32 EndRiddleModeFunc(void) {
    FreeRiddleMdlMng();
    *(u32 *)RiddleMng = 8;
    return;
}

void SetRiddleData(void) {
    PadVibAllClear();
    PadUpdate();
    GameSt[5] = 3;
    SetCamCtrlMode(1);
    {
        float pos[4] __attribute__((aligned(16))) = {0.0f, 0.0f, 0.0f, 1.0f};
        SetCameraPos(pos);
        {
            float ang[4] __attribute__((aligned(16))) = {0.0f, 0.0f, 0.0f, 1.0f};
            SetCameraAng(ang);
        }
    }
    *(float *)(lpDrawMng + 0x41c) = 0.7853982f;
    DrawSetViewRange();
    DrawCalcView();
    {
        u8 color[16] __attribute__((aligned(16))) = {0};
        SetFadeMng(0, (s32 *)color, 0x32, (void *)0, (void *)0, 0, 0);
    }
    switch (*(s32 *)(RiddleMng + 4)) {
    case 1:
        InitRiddle001();
        *(u32 *)(RiddleMng + 0x14) = 0x1d528;
        *(u32 *)(RiddleMng + 0x18) = 0x39d;
        break;
    case 2:
        InitRiddle002();
        *(u32 *)(RiddleMng + 0x14) = 0x1d51d;
        *(u32 *)(RiddleMng + 0x18) = 0x39e;
        break;
    case 3:
        InitRiddle003();
        *(u32 *)(RiddleMng + 0x14) = 0x1d522;
        *(u32 *)(RiddleMng + 0x18) = 0x39f;
    }
    *(u32 *)RiddleMng = 3;
}

static u32 FreeRiddleMdlMng(void) {
    s32 v1;
    u32 a0;
    u8 *s0;
    s32 s1;

    v1 = 3;
    a0 = *(s32 *)((u8 *)&RiddleMng + 4);
    s0 = (u8 *)MdlMng + 0x17f40;
    switch (a0) {
    case 1:
        s1 = 0;
        do {
            a0 = (u32)s0;
            FreeMdlMng((void *)a0);
            s1 = s1 + 1;
            s0 = (u8 *)((u8 *)s0 + 0x1c0);
            v1 = s1 < (s32)4;
        } while ((u32)v1 != 0);
        break;
    case 2:
        s1 = 0;
        do {
            a0 = (s32)s0;
            FreeMdlMng((void *)a0);
            s1 = s1 + 1;
            s0 = (u8 *)((u8 *)s0 + 0x1c0);
            v1 = s1 < (s32)4;
        } while ((u32)v1 != 0);
        break;
    case 3:
        s1 = 0;
        do {
            a0 = (s32)s0;
            FreeMdlMng((void *)a0);
            s1 = s1 + 1;
            s0 = (u8 *)((u8 *)s0 + 0x1c0);
            v1 = s1 < (s32)0x14;
        } while ((u32)v1 != 0);
    }
    return;
}

static u32 FreeRiddleMdlData() {
    s32 v0;
    u32 v1;
    u8 *s0;
    s32 s1;
    u32 a0;

    v0 = 3;
    v1 = *(s32 *)(RiddleMng + 0x4);
    s0 = (u8 *)MdlData + 0x32600;
    switch (v1) {
    case 1:
        s1 = 0;
        do {
            a0 = (u32)s0;
            FreeMdlData((void *)a0, 0);
            s1 = s1 + 1;
            v0 = s1 < (s32)4;
            s0 = (u8 *)(s0 + 0x680);
        } while ((u32)v0 != 0);
        break;
    case 2:
        s1 = 0;
        do {
            a0 = (s32)s0;
            FreeMdlData((void *)a0, 0);
            s1 = s1 + 1;
            v0 = s1 < (s32)4;
            s0 = (u8 *)(s0 + 0x680);
        } while ((u32)v0 != 0);
        break;
    case 3:
        s1 = 0;
        do {
            a0 = (s32)s0;
            FreeMdlData((void *)a0, 0);
            s1 = s1 + 1;
            v0 = s1 < (s32)0xe;
            s0 = (u8 *)(s0 + 0x680);
        } while ((u32)v0 != 0);
    }
    MemFree((void *)*(s32 *)(RiddleMng + 0x10));
    ((u32 *)RiddleMng)[4] = 0;
    return;
}

void CheckRiddleFree(void) {
    u32 a0;

    a0 = *(u32 *)RiddleMng;
    if (a0 == (u32)9) {
        FreeRiddleMdlData(a0);
        *(u32 *)RiddleMng = 0;
        *(u8 *)((u8 *)&GameSt + 5) = 0;
        SetCamCtrlMode(0);
        FECard_Enable_Draw(1);
    }
    return;
}

void CheckFreeRiddleData(void) {
    u32 v1;

    v1 = *(u32 *)((u8 *)&RiddleMng + 0x10);
    if (v1 != 0) {
        FreeRiddleMdlMng();
        FreeRiddleMdlData();
        *(u8 *)((u8 *)&GameSt + 5) = 0;
    }
    return;
}

/* GetRiddleFreeState @ 0x1A4980 .. 0x1A49A8 (0x28 bytes) */

u32 GetRiddleFreeState(void) {
    u32 v1;
    u32 v0;

    v1 = *(s32 *)RiddleMng;
    v0 = 1;
    if ((u32)(v1 + -8) > (u32)1) {
        v0 = 0;
    }
    return v0;
}

u32 GetRiddleResult(void) {
    return *(u32 *)((u8 *)&RiddleMng + 0xc);
}

void PlayRiddle(void) {
    u32 a0;
    s32 v1;
    u32 v0;

    v1 = 4;
    a0 = *(s32 *)RiddleMng;
    switch (a0) {
    case 3:
        v0 = CheckNowFade(0);
        if (v0 == 0) {
            a0 = *(s32 *)(RiddleMng + 0x14);
            v0 = Menu_TD_CallOrder(a0, *(s32 *)(RiddleMng + 0x18), 1);
            v1 = 4;
            if (v0 != 0) {
                *(u32 *)RiddleMng = v1;
                goto _L001A48C8;
            }
            v1 = 5;
            *(u32 *)RiddleMng = v1;
            break;
        }
        _L001A48C8:;
        return;
    case 4:
        v0 = Menu_TD_IsPlay();
        v1 = 5;
        if (v0 != 0) {
            goto _L001A4960;
        }
        *(u32 *)RiddleMng = v1;
    }
    a0 = *(s32 *)(RiddleMng + 0x4);
    v1 = 3;
    switch (a0) {
    case 1:
        PlayRiddle001();
        break;
    case 2:
        PlayRiddle002();
        break;
    case 3:
        PlayRiddle003();
    }
    a0 = *(s32 *)RiddleMng;
    v1 = 8;
    if (a0 == (u32)v1) {
        v1 = 9;
        *(u32 *)RiddleMng = v1;
    }
    _L001A4960:;
    return;
}

void InitRiddle001(void) {
    s32 i;
    u8 *lpPelorus;
    u8 *lpMdlMng;
    u8 *lpMdlData;
    u8 *lpMdlMng1;
    u8 *lpVmdObj1;
    u8 *lpVmdObj2;
    u8 *lpVmdObj3;

    lpPelorus = RiddleMng + 0x20;
    lpMdlMng = MdlMng + 0x17f40;
    lpMdlData = (u8 *)(MdlData + 0xc980);
    RemapBinderFile((void *)*(s32 *)(RiddleMng + 0x10));
    for (i = 0; i < 4; i++) {
        *(u32 *)(lpMdlData + 0x30) = GetBindOffsetByIndex((void *)*(s32 *)(RiddleMng + 0x10), i);
        RemapBinderFile((void *)*(s32 *)(lpMdlData + 0x30));
        SetMdlBndFile(i + 0x7c);
        SetMdlMng(lpMdlMng, lpMdlData);
        *(float *)(lpMdlMng + 0x20) = 0.0f;
        *(float *)(lpMdlMng + 0x24) = 0.0f;
        *(float *)(lpMdlMng + 0x28) = 1.3f;
        *(float *)(lpMdlMng + 0x30) = 1.5707964f;
        *(u8 *)(lpMdlMng + 8) = 1;
        *(float *)(lpMdlMng + 0xb0) = 0.4f;
        *(float *)(lpMdlMng + 0xb4) = 0.4f;
        *(float *)(lpMdlMng + 0xb8) = 0.4f;
        *(u16 *)(lpMdlMng + 0x106) = 2;
        lpMdlData += 0x680;
        lpMdlMng += 0x1c0;
    }
    memset(lpPelorus, 0, 0xc);
    lpMdlMng1 = MdlMng + 0x18100;
    lpVmdObj1 = *(u8 **)(*(u8 **)(*(u8 **)(lpMdlMng1 + 0xc) + 0x10) + 0x1c) + 0xc0;
    lpVmdObj2 = *(u8 **)(*(u8 **)(*(u8 **)(MdlMng + 0x182cc) + 0x10) + 0x1c) + 0xc0;
    lpVmdObj3 = *(u8 **)(*(u8 **)(*(u8 **)(MdlMng + 0x1848c) + 0x10) + 0x1c) + 0xc0;
    lpPelorus[0] = 4;
    lpPelorus[1] = 10;
    lpPelorus[2] = 7;
    *(float *)(lpVmdObj1 + 0x14) = 0.01745f * (30.0f * (float)lpPelorus[0]);
    *(float *)(lpVmdObj2 + 0x14) = 0.01745f * (30.0f * (float)lpPelorus[1]);
    *(float *)(lpVmdObj3 + 0x14) = 0.01745f * (30.0f * (float)lpPelorus[2]);
    *(float *)(lpVmdObj1 + 0x14) = R001_WrapAng(*(float *)(lpVmdObj1 + 0x14));
    *(float *)(lpVmdObj2 + 0x14) = R001_WrapAng(*(float *)(lpVmdObj2 + 0x14));
    *(float *)(lpVmdObj3 + 0x14) = R001_WrapAng(*(float *)(lpVmdObj3 + 0x14));
    *(float *)(lpMdlMng1 + 0xb0) = 0.9f;
    *(float *)(lpMdlMng1 + 0xb4) = 0.9f;
    *(float *)(lpMdlMng1 + 0xb8) = 0.9f;
}

void PlayRiddle001(void) {
    struct dw_1534476_fields *lpPelorus;
    unsigned char *lpPad;
    struct dw_1536886_fields *lpMdlMng0;
    struct dw_1536886_fields *lpMdlMng2;
    struct dw_1536886_fields *lpMdlMng3;
    struct PrObj *lpVmdObj1;
    struct PrObj *lpVmdObj2;
    struct PrObj *lpVmdObj3;

    lpPelorus = (struct dw_1534476_fields *)(RiddleMng + 0x20);
    lpPad = (unsigned char *)((u32 *)&lpPadData)[GameSt[10]];
    lpMdlMng0 = (struct dw_1536886_fields *)(MdlMng + 0x17f40);
    lpMdlMng2 = (struct dw_1536886_fields *)(MdlMng + 0x182c0);
    lpMdlMng3 = (struct dw_1536886_fields *)(MdlMng + 0x18480);
    lpVmdObj1 = (struct PrObj *)(*(u8 **)((u8 *)((struct dw_1558366_fields *)((struct dw_1536886_fields *)(MdlMng + 0x18100))->lpMdlData)->lpVmdHead + 0x1c) + 0xc0);
    lpVmdObj2 = (struct PrObj *)(*(u8 **)((u8 *)((struct dw_1558366_fields *)lpMdlMng2->lpMdlData)->lpVmdHead + 0x1c) + 0xc0);
    lpVmdObj3 = (struct PrObj *)(*(u8 **)((u8 *)((struct dw_1558366_fields *)lpMdlMng3->lpMdlData)->lpVmdHead + 0x1c) + 0xc0);
    if (lpPelorus->Disc1Lock == 0) {
        if (RM_STATE == 5) {
            if (PB(0x22, 7) || PB(0x22, 6)) {
                RM_STATE = 6;
                RM_TIMER = 0;
                lpPelorus->Disc1Dir = -1;
                DEC(lpPelorus->Disc1Now)
                SND_Play2D(0x427, 0x64, 0);
            } else if (PB(0x22, 5) || PB(0x22, 4)) {
                RM_STATE = 6;
                RM_TIMER = 0;
                lpPelorus->Disc1Dir = 1;
                INC(lpPelorus->Disc1Now)
                SND_Play2D(0x427, 0x64, 0);
            } else if (PB(0x23, 6)) {
                lpPelorus->Disc1Lock = 1;
                SND_Play2D(0x426, 0x64, 0);
                COL(lpMdlMng2, 0.9f);
                if (lpPelorus->Disc1Now == lpPelorus->Disc2Now) {
                    SND_Play2D(0x424, 0x64, 0);
                }
            } else if (PB(0x21, 5)) {
                u8 stackFrame_60[16] __attribute__((aligned(16))) = {0};
                SetFadeMng(2, (signed int *)stackFrame_60, 0x50, EndRiddleModeFunc, (void *)0, 0x1e, 0x32);
                RM_RESULT = 0;
                RM_STATE = 7;
            }
        } else if (RM_STATE == 6) {
            if (++RM_TIMER < 0x1f) {
                ANG(lpVmdObj1, lpPelorus->Disc1Dir);
                if (RM_TIMER == 0x1e) {
                    SNAP(lpVmdObj1, lpPelorus->Disc1Now);
                }
                WRP(lpVmdObj1);
            } else if (RM_TIMER == 0x23) {
                RM_STATE = 5;
                RM_TIMER = 0;
            }
        }
    } else if (lpPelorus->Disc2Lock == 0) {
        if (RM_STATE == 5) {
            if (PB(0x22, 7) || PB(0x22, 6)) {
                RM_STATE = 6;
                RM_TIMER = 0;
                lpPelorus->Disc1Dir = -1;
                DEC(lpPelorus->Disc1Now)
                lpPelorus->Disc2Dir = -1;
                DEC(lpPelorus->Disc2Now)
                SND_Play2D(0x427, 0x64, 0);
            } else if (PB(0x22, 5) || PB(0x22, 4)) {
                RM_STATE = 6;
                RM_TIMER = 0;
                lpPelorus->Disc1Dir = 1;
                INC(lpPelorus->Disc1Now)
                lpPelorus->Disc2Dir = 1;
                INC(lpPelorus->Disc2Now)
                SND_Play2D(0x427, 0x64, 0);
            } else if (PB(0x23, 6)) {
                lpPelorus->Disc2Lock = 1;
                SND_Play2D(0x426, 0x64, 0);
                COL(lpMdlMng3, 0.9f);
                if (lpPelorus->Disc1Now == lpPelorus->Disc2Now && lpPelorus->Disc2Now == lpPelorus->Disc3Now) {
                    SND_Play2D(0x424, 0x64, 0);
                }
            } else if (PB(0x21, 5)) {
                lpPelorus->Disc1Lock = 0;
                SND_Play2D(0x425, 0x64, 0);
                COL(lpMdlMng2, 0.4f);
            }
        } else if (RM_STATE == 6) {
            if (++RM_TIMER < 0x1f) {
                ANG(lpVmdObj1, lpPelorus->Disc1Dir);
                ANG(lpVmdObj2, lpPelorus->Disc2Dir);
                if (RM_TIMER == 0x1e) {
                    SNAP(lpVmdObj1, lpPelorus->Disc1Now);
                    SNAP(lpVmdObj2, lpPelorus->Disc2Now);
                }
                WRP(lpVmdObj1);
                WRP(lpVmdObj2);
            } else if (RM_TIMER == 0x23) {
                RM_STATE = 5;
                RM_TIMER = 0;
            }
        }
    } else if (lpPelorus->Disc3Lock == 0) {
        if (RM_STATE == 5) {
            if (PB(0x22, 7) || PB(0x22, 6)) {
                RM_STATE = 6;
                RM_TIMER = 0;
                lpPelorus->Disc1Dir = -1;
                DEC(lpPelorus->Disc1Now)
                lpPelorus->Disc2Dir = -1;
                DEC(lpPelorus->Disc2Now)
                lpPelorus->Disc3Dir = -1;
                DEC(lpPelorus->Disc3Now)
                SND_Play2D(0x427, 0x64, 0);
            } else if (PB(0x22, 5) || PB(0x22, 4)) {
                RM_STATE = 6;
                RM_TIMER = 0;
                lpPelorus->Disc1Dir = 1;
                INC(lpPelorus->Disc1Now)
                lpPelorus->Disc2Dir = 1;
                INC(lpPelorus->Disc2Now)
                lpPelorus->Disc3Dir = 1;
                INC(lpPelorus->Disc3Now)
                SND_Play2D(0x427, 0x64, 0);
            } else if (PB(0x23, 6)) {
                SND_Play2D(0x426, 0x64, 0);
                if (lpPelorus->Disc1Now == 0 && lpPelorus->Disc2Now == 0 && lpPelorus->Disc3Now == 0) {
                    RM_RESULT = 1;
                    {
                        u8 stackFrame_50[16] __attribute__((aligned(16))) = {0};
                        SetFadeMng(2, (signed int *)stackFrame_50, 0x50, EndRiddleModeFunc, (void *)0, 0x1e, 0x32);
                    }
                    RM_STATE = 7;
                    SND_Play2D(0x424, 0x64, 0);
                    COL(lpMdlMng0, 0.9f);
                }
            } else if (PB(0x21, 5)) {
                lpPelorus->Disc2Lock = 0;
                SND_Play2D(0x425, 0x64, 0);
                COL(lpMdlMng3, 0.4f);
            }
        } else if (RM_STATE == 6) {
            if (++RM_TIMER < 0x1f) {
                ANG(lpVmdObj1, lpPelorus->Disc1Dir);
                ANG(lpVmdObj2, lpPelorus->Disc2Dir);
                ANG(lpVmdObj3, lpPelorus->Disc3Dir);
                if (RM_TIMER == 0x1e) {
                    SNAP(lpVmdObj1, lpPelorus->Disc1Now);
                    SNAP(lpVmdObj2, lpPelorus->Disc2Now);
                    SNAP(lpVmdObj3, lpPelorus->Disc3Now);
                }
                WRP(lpVmdObj1);
                WRP(lpVmdObj2);
                WRP(lpVmdObj3);
            } else if (RM_TIMER == 0x23) {
                RM_STATE = 5;
                RM_TIMER = 0;
            }
        }
    }
}

void InitRiddle002(void) {
    int i;
    u8 *lpBuddhist;
    u8 *lpMdlMng;
    u8 *lpMdlData;

    lpBuddhist = (u8 *)(RiddleMng + 0x2c);
    lpMdlMng = (u8 *)(MdlMng + 0x17f40);
    lpMdlData = (u8 *)(MdlData + 0xc980);
    RemapBinderFile((void *)*(s32 *)(RiddleMng + 0x10));
    for (i = 0; i < 4; i++) {
        *(u32 *)(lpMdlData + 0x30) = GetBindOffsetByIndex((void *)*(s32 *)(RiddleMng + 0x10), i);
        RemapBinderFile((void *)*(s32 *)(lpMdlData + 0x30));
        SetMdlBndFile(i + 0x7c);
        SetMdlMng(lpMdlMng, lpMdlData);
        *(float *)(lpMdlMng + 0x20) = 0.0f;
        *(float *)(lpMdlMng + 0x24) = 1.2f;
        *(float *)(lpMdlMng + 0x28) = 2.0f;
        *(u8 *)(lpMdlMng + 8) = 1;
        *(float *)(lpMdlMng + 0xb0) = 0.7f;
        *(float *)(lpMdlMng + 0xb4) = 0.7f;
        *(float *)(lpMdlMng + 0xb8) = 0.7f;
        *(u16 *)(lpMdlMng + 0x106) = 2;
        lpMdlData += 0x680;
        lpMdlMng += 0x1c0;
    }
    memset(lpBuddhist, 0, 0xc);
    *(u8 *)lpBuddhist = 0xff;
    *(u8 *)(lpBuddhist + 1) = 0xff;
    *(u8 *)(lpBuddhist + 2) = 0xff;
    *(u8 *)(lpBuddhist + 8) = ItemMng_GetItemNum_Direct(0x36cc);
    *(u8 *)(lpBuddhist + 9) = ItemMng_GetItemNum_Direct(0x2ef2);
    *(u8 *)(lpBuddhist + 0xa) = ItemMng_GetItemNum_Direct(0x2ef3);
    *(u8 *)(lpBuddhist + 0xb) = ItemMng_GetItemNum_Direct(0x2ef4);
}
void PlayRiddle002(void) {
    static float OffSet[3][2] = {{0.0f, -1.538f}, {-0.2f, -0.865f}, {0.2f, -0.865f}};
    u8 *a3;
    u8 *s4;
    u32 a2;
    u8 *s3;
    u8 *s2;
    u32 a1;
    u32 a0;
    u8 *s1;
    u8 *s0;
    u64 v1_64;
    u32 v1;
    u32 v0;
    float f0;
    float CurPos[4] __attribute__((aligned(16)));

    v0 = (u32)&lpPadData;
    s4 = (u8 *)(RiddleMng + 0x2c);
    v1 = GameSt[(DCOMP_OFF_STRUCT_DW_1555757_FIELDS_PADPORT_A508C3F7 / 1)];
    v1 = v1 << 2;
    v0 = (s32)((u8 *)&lpPadData + v1);
    s3 = (u8 *)*(s32 *)v0;
    s2 = (u8 *)(MdlMng + 0x17f40);
    v0 = Riddle002CheckMsg();
    if (v0 != 0) {
        a1 = *(u8 *)(s4 + DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_0__23643E9D);
        a0 = 0xff;
        if (a1 == a0) {
            s1 = (u8 *)(MdlMng + 0x18100);
            s0 = (u8 *)*(s32 *)(s1 + DCOMP_OFF_STRUCT_DW_1536886_FIELDS_LPANIMCTRL_7C6525FF);
        } else {
            v1 = *(u8 *)(s4 + DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_1__54FB7A91);
            if (v1 == a0) {
                s1 = (u8 *)(MdlMng + 0x182c0);
                s0 = (u8 *)*(s32 *)(s1 + DCOMP_OFF_STRUCT_DW_1536886_FIELDS_LPANIMCTRL_7C6525FF);
            } else {
                v1 = *(u8 *)(s4 +
                    DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_2__24E81980);
                if (v1 == a0) {
                    s1 = (u8 *)(MdlMng + 0x18480);
                    s0 = (u8 *)*(s32 *)(s1 +
                        DCOMP_OFF_STRUCT_DW_1536886_FIELDS_LPANIMCTRL_7C6525FF);
                } else {
                    s1 = (u8 *)0;
                }
            }
        }
        a0 = *(s32 *)(RiddleMng + (DCOMP_OFF_STRUCT_DW_1534919_FIELDS_STATE_4B5175A4 / 1));
        v1 = 5;
        if (a0 == v1) {
            a0 = *(u8 *)(s3 + 0x20);
            v1_64 = (u64)a0 << 0x38 >> 0x3f;
            if (v1_64 != 0) {
                v1 = *(u8 *)(s4 + DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_NOWCUR_B7A73430);
                v0 = 2;
                if (v1 == v0) {
                    *(u8 *)(s4 + DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_NOWCUR_B7A73430) = 0;
                } else {
                    v0 = v1 + 1;
                    *(u8 *)(s4 + DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_NOWCUR_B7A73430) = v0;
                }
                SND_Play2D(0x423, 0x64, 0);
            } else {
                v1_64 = (u64)a0 << 0x3a >> 0x3f;
                if (v1_64 != 0) {
                    v0 = *(u8 *)(s4 + DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_NOWCUR_B7A73430);
                    if (v0 == 0) {
                        *(u8 *)(s4 + DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_NOWCUR_B7A73430) =
                            2;
                    } else {
                        v0 = v0 + -1;
                        *(u8 *)(s4 + DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_NOWCUR_B7A73430) =
                            v0;
                    }
                    SND_Play2D(0x423, 0x64, 0);
                } else {
                    v1 = *(u8 *)(s3 + 0x21);
                    v1_64 = (u64)v1 << 0x39 >> 0x3f;
                    if (v1_64 != 0 && *((u8 *)((u32)*(u8 *)(s4 + 3) + (u32)s4) +
                        DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_CURSTATE__0___545B22F4) == 0) {
                        *(u16 *)(s1 + 0x106) = 0;
                        a0 = *(u8 *)(s4 +
                            DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_NOWCUR_B7A73430);
                        *((u8 *)((u32)a0 + (u32)s4) +
                            DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_CURSTATE__0___545B22F4) = 1;
                        *(u32 *)(RiddleMng + (DCOMP_OFF_STRUCT_DW_1534919_FIELDS_STATE_4B5175A4 /
                            1)) = 6;
                    }
                }
            }
        } else {
            v1 = 6;
            if (a0 == v1) {
                a0 = 0xff;
                if (a1 == a0) {
                    v0 = CheckAnimEndFrame((void *)s0);
                    if (v0 != 0) {
                        a1 = *(u8 *)(s4 +
                            DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_NOWCUR_B7A73430);
                        *(u8 *)(s4 +
                            DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_0__23643E9D) = a1;
                        *(u32 *)(RiddleMng + (DCOMP_OFF_STRUCT_DW_1534919_FIELDS_STATE_4B5175A4 /
                            1)) = 5;
                        *(u8 *)(s4 + DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_MSGSTATE_81B9FA9F)
                            = 0xa;
                    }
                } else {
                    v1 = *(u8 *)(s4 +
                        DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_1__54FB7A91);
                    if (v1 == a0) {
                        v0 = CheckAnimEndFrame((void *)s0);
                        if (v0 != 0) {
                            a1 = *(u8 *)(s4 +
                                DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_NOWCUR_B7A73430);
                            *(u8 *)(s4 +
                                DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_1__54FB7A91)
                                = a1;
                            *(u32 *)(RiddleMng + (DCOMP_OFF_STRUCT_DW_1534919_FIELDS_STATE_4B5175A4
                                / 1)) = 5;
                            *(u8 *)(s4 +
                                DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_MSGSTATE_81B9FA9F) =
                                0x14;
                        }
                    } else {
                        v1 = *(u8 *)(s4 +
                            DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_2__24E81980);
                        if (v1 == a0) {
                            v0 = CheckAnimEndFrame((void *)s0);
                            if (v0 != 0) {
                                v1 = *(u8 *)(s4 +
                                    DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_NOWCUR_B7A73430);
                                *(u8 *)(s4 +
                                    DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_2__24E81980)
                                    = v1;
                                v1 = *(u8 *)(s4 +
                                    DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_0__23643E9D);
                                if (v1 == 0) {
                                    a0 = *(u8 *)(s4 +
                                        DCOMP_OFF_STRUCT_DW_1534919_FIELDS_BUDDHIST_WOODBOARD_1__54FB7A91);
                                    v1 = 2;
                                    if (a0 != v1) {
                                        goto _L001A33C0;
                                    }
                                    a0 = *(u8 *)(s4 + 2);
                                    v1 = 1;
                                    if (a0 != v1) {
                                        goto _L001A33C0;
                                    }
                                    a0 = 0x424;
                                    *(u32 *)(RiddleMng +
                                        (DCOMP_OFF_STRUCT_DW_1534919_FIELDS_RESULT_7297F4CD / 1)) =
                                        v1;
                                    a1 = 0x64;
                                    SND_Play2D(a0, a1, 0);
                                    {
                                        u8 stackFrame_70[16] __attribute__((aligned(16))) = {0};
                                        a0 = 2;
                                        a3 = (u8 *)EndRiddleModeFunc;
                                        SetFadeMng(a0, (signed int *)((u8 *)&stackFrame_70[0]),
                                            0x50, EndRiddleModeFunc, (void *)0, 0x1e, 0x32);
                                        a0 = 0x36cc;
                                        *(u32 *)(RiddleMng +
                                            (DCOMP_OFF_STRUCT_DW_1534919_FIELDS_STATE_4B5175A4 /
                                            1)) = 7;
                                        ItemMng_Add_Direct(a0, -3);
                                        a0 = 0x2ef2;
                                        ItemMng_Add_Direct(a0, -1);
                                        a0 = 0x2ef3;
                                        ItemMng_Add_Direct(a0, -1);
                                        a0 = 0x2ef4;
                                        ItemMng_Add_Direct(a0, -1);
                                    }
                                } else {
                                    _L001A33C0:;
                                    *(u8 *)(s4 + 7) = 0x1e;
                                    *(u32 *)(RiddleMng +
                                        (DCOMP_OFF_STRUCT_DW_1534919_FIELDS_RESULT_7297F4CD / 1)) =
                                        0;
                                }
                            }
                        }
                    }
                }
            }
        }
        a1 = (s32)(s2 + 0x20);
        if ((u32)s1 != 0) {
            sceVu0CopyVector((void *)((u8 *)&CurPos[0]), (void *)a1);
            CurPos[0] = CurPos[0] + OffSet[*(u8 *)(s4 + 3)][0];
            CurPos[1] = CurPos[1] + OffSet[*(u8 *)(s4 + 3)][1];
            a0 = (s32)(s1 + 0x20);
            sceVu0CopyVector((void *)a0, (void *)((u8 *)&CurPos[0]));
        }
        a0 = *(s32 *)(RiddleMng + (DCOMP_OFF_STRUCT_DW_1534919_FIELDS_STATE_4B5175A4 / 1));
        v1 = 7;
        if (a0 != v1) {
            v1 = 1;
            a0 = *(s32 *)(RiddleMng + (DCOMP_OFF_STRUCT_DW_1534919_FIELDS_RESULT_7297F4CD / 1));
            if (a0 != v1) {
                v1 = *(u8 *)(s3 + 0x21);
                v1_64 = (u64)v1 << 0x3a >> 0x3f;
                if (v1_64 != 0) {
                    {
                        u8 stackFrame_60[16] __attribute__((aligned(16))) = {0};
                        a3 = (u8 *)EndRiddleModeFunc;
                        SetFadeMng(2, (signed int *)((u8 *)&stackFrame_60[0]), 0x50,
                            EndRiddleModeFunc, (void *)0, 0x1e, 0x32);
                        *(u32 *)(RiddleMng + (DCOMP_OFF_STRUCT_DW_1534919_FIELDS_STATE_4B5175A4 /
                            1)) = 7;
                        *(u32 *)(RiddleMng + (DCOMP_OFF_STRUCT_DW_1534919_FIELDS_RESULT_7297F4CD /
                            1)) = 0;
                    }
                }
            }
        }
    }
    return;
}

signed int Riddle002CheckMsg(void) {
    u32 v1;
    u8 *s0;
    u32 v0;

    v0 = 0x29;
    s0 = (u8 *)(RiddleMng + 0x2c);
    v1 = *(u8 *)(s0 + 7);
    switch (v1) {
    case 0:
        v0 = 0x60000;
        KnMsgMng_SendMsg(0x60000 | 0xde20);
        v0 = *(u8 *)(s0 + 9);
        if (v0 == 0) {
            v0 = 0x60000;
            KnMsgMng_SendMsg(0x60000 | 0xde21);
            *(u8 *)(s0 + 7) = 0x28;
        } else {
            v0 = *(u8 *)(s0 + 8);
            if (v0 == 0) {
                v0 = 0x60000;
                KnMsgMng_SendMsg(0x60000 | 0xde22);
                *(u8 *)(s0 + 7) = 0x28;
            } else {
                v0 = 0x60000;
                KnMsgMng_SendMsg(0x60000 | 0xde23);
                *(u8 *)(s0 + 7) = 1;
            }
        }
        return 0;
    case 1:
        v0 = KnMsgMng_CheckMsgNone();
        if (v0 == 0) {
            break;
        }
        *(u8 *)(s0 + 7) = 2;
        v0 = *(u8 *)(s0 + 8);
        *(u8 *)(s0 + 8) = v0 + -1;
        break;
    case 2:
        return 1;
    case 10:
        v0 = *(u8 *)(s0 + 0xa);
        if (v0 == 0) {
            v0 = 0x60000;
            KnMsgMng_SendMsg(0x60000 | 0xde24);
            v0 = 0x60000;
            KnMsgMng_SendMsg(0x60000 | 0xde27);
            *(u8 *)(s0 + 7) = 0x28;
        } else {
            v0 = *(u8 *)(s0 + 8);
            if (v0 == 0) {
                v0 = 0x60000;
                KnMsgMng_SendMsg(0x60000 | 0xde25);
                v0 = 0x60000;
                KnMsgMng_SendMsg(0x60000 | 0xde27);
                *(u8 *)(s0 + 7) = 0x28;
            } else {
                v0 = 0x60000;
                KnMsgMng_SendMsg(0x60000 | 0xde26);
                *(u8 *)(s0 + 7) = 0xb;
            }
        }
        return 0;
    case 11:
        v0 = KnMsgMng_CheckMsgNone();
        if (v0 == 0) {
            break;
        }
        *(u8 *)(s0 + 7) = 0xc;
        v0 = *(u8 *)(s0 + 8);
        *(u8 *)(s0 + 8) = v0 + -1;
        break;
    case 12:
        return 1;
    case 20:
        v0 = *(u8 *)(s0 + 0xb);
        if (v0 == 0) {
            v0 = 0x60000;
            KnMsgMng_SendMsg(0x60000 | 0xde28);
            v0 = 0x60000;
            KnMsgMng_SendMsg(0x60000 | 0xde27);
            *(u8 *)(s0 + 7) = 0x28;
        } else {
            v0 = *(u8 *)(s0 + 8);
            if (v0 == 0) {
                v0 = 0x60000;
                KnMsgMng_SendMsg(0x60000 | 0xde29);
                v0 = 0x60000;
                KnMsgMng_SendMsg(0x60000 | 0xde27);
                *(u8 *)(s0 + 7) = 0x28;
            } else {
                v0 = 0x60000;
                KnMsgMng_SendMsg(0x60000 | 0xde2a);
                *(u8 *)(s0 + 7) = 0x15;
            }
        }
        return 0;
    case 21:
        v0 = KnMsgMng_CheckMsgNone();
        if (v0 == 0) {
            break;
        }
        *(u8 *)(s0 + 7) = 0x16;
        v0 = *(u8 *)(s0 + 8);
        *(u8 *)(s0 + 8) = v0 + -1;
        break;
    case 22:
        return 1;
    case 30:
        v0 = 0x60000;
        KnMsgMng_SendMsg(0x60000 | 0xde2c);
        v0 = 0x60000;
        KnMsgMng_SendMsg(0x60000 | 0xde2d);
        *(u8 *)(s0 + 7) = 0x1f;
        return 0;
    case 31:
        v0 = KnMsgMng_CheckMsgNone();
        if (v0 == 0) {
            break;
        }
        *(u8 *)(s0 + 7) = 0x28;
        break;
    case 32:
        return 0;
    case 40:
        v0 = KnMsgMng_CheckMsgNone();
        if (v0 == 0) {
            break;
        }
        {
        u8 stackFrame_20[16] __attribute__((aligned(16))) = {0};
        SetFadeMng(2, (signed int *)(u8 *)((u8 *)&stackFrame_20[0]), 0x50,
                   EndRiddleModeFunc, (void *)0, 0x1e, (signed int)0x32);
        *(u32 *)RiddleMng = 7;
        *(u32 *)(RiddleMng + 0xc) = 0;
        *(u8 *)(s0 + 7) = 0x29;
        }
    case 41:
        break;
    }
    return 0;
}

void InitRiddle003(void) {
    R003GodShelf *lpGodShelf;
    u8 *lpMdlMng;
    u8 *lpMdlData;
    float BasePos[4] = {0.0f, 0.0f, 1.15f, 1.0f};
    s32 i;
    u8 *ip;
    u8 *pos;
    u8 *basepos;

    lpGodShelf = (R003GodShelf *)(RiddleMng + 0x38);
    RemapBinderFile((void *)*(s32 *)(RiddleMng + 0x10));
    lpMdlData = (u8 *)(MdlData + 0xc980);
    for (i = 0; i < 14; i++) {
        *(u32 *)(lpMdlData + 0x30) = GetBindOffsetByIndex((void *)*(s32 *)(RiddleMng + 0x10), i);
        RemapBinderFile((void *)*(s32 *)(lpMdlData + 0x30));
        SetMdlBndFile(i + 0x7c);
        lpMdlData += 0x680;
    }
    lpMdlMng = (u8 *)(MdlMng + 0x17f40);
    lpMdlData = (u8 *)(MdlData + 0xc980);
    SetMdlMng(lpMdlMng, lpMdlData);
    sceVu0CopyVector(lpMdlMng + 0x20, BasePos);
    *(float *)(lpMdlMng + 0x30) = 1.5707964f;
    lpMdlMng += 0x1c0;
    for (i = 0; i < 7; i++, lpMdlMng += 0x1c0) {
        R3SetMdlMng(lpMdlMng, lpMdlData);
        sceVu0CopyVector(BTN[i], BBTN[i]);
        BTN[i][0] += BasePos[0];
        BTN[i][1] += BasePos[1];
        BTN[i][2] += BasePos[2];
        sceVu0CopyVector(lpMdlMng + 0x20, BTN[i]);
        *(float *)(lpMdlMng + 0x30) = 1.5707964f;
        ChangeAnimParam(lpMdlMng, 0, *(float *)(*(u8 **)(lpMdlMng + 0x100) + 0x10));
    }
    lpMdlData += 0xd00;
    for (i = 0; i < 12; i++, lpMdlMng += 0x1c0, lpMdlData += 0x680) {
        SetMdlMng(lpMdlMng, lpMdlData);
        sceVu0CopyVector(BLK[i], BBLK[i]);
        BLK[i][0] += BasePos[0];
        BLK[i][1] += BasePos[1];
        BLK[i][2] += BasePos[2];
        sceVu0CopyVector(lpMdlMng + 0x20, BLK[i]);
        *(float *)(lpMdlMng + 0x30) = 1.5707964f;
        ChangeAnimParam(lpMdlMng, 0, *(float *)(*(u8 **)(lpMdlMng + 0x100) + 0x10));
    }
    lpMdlMng = (u8 *)(MdlMng + 0x17f40);
    for (i = 0; i < 20; i++) {
        *(u8 *)(lpMdlMng + 8) = 1;
        *(float *)(lpMdlMng + 0xb0) = 0.7f;
        *(float *)(lpMdlMng + 0xb4) = 0.7f;
        *(float *)(lpMdlMng + 0xb8) = 0.7f;
        lpMdlMng += 0x1c0;
    }
    memset(lpGodShelf, 0, 0x10);
    {
        u8 InitPos[12] = {0, 5, 2, 7, 9, 6, 11, 4, 8, 1, 10, 3};
        i = 0;
        pos = (u8 *)R003_BlockPos;
        ip = InitPos;
        for (; i < 12; i++) {
            lpGodShelf->Box[i] = *ip;
            sceVu0CopyVector(MdlMng + (lpGodShelf->Box[i] + 0xe3) * 0x1c0 + 0x20, pos);
            ip++;
            pos += 0x10;
        }
    }
    Riddle003UpdateAmbient();
}

void PlayRiddle003(void) {
    u8 *a3;
    u32 a1;
    u32 a0;
    u32 v1;
    u8 *s3;
    u8 *s2;
    u64 v0_64;
    s32 s1;
    u32 s0;
    u64 v1_64;
    u32 v0;
    s32 branchcond_1a2924;

    a0 = (u32)&lpPadData;
    v0 = 5;
    a1 = GameSt[0xa];
    a1 = a1 << 2;
    a0 = (s32)((u8 *)&lpPadData + a1);
    v1 = *(s32 *)RiddleMng;
    s2 = (u8 *)*(s32 *)a0;
    s3 = (u8 *)(RiddleMng + 0x38);
    if (v1 == v0) {
        v1 = *(u8 *)(s2 + 0x22);
        v0_64 = (u64)v1 << 0x38 >> 0x3f;
        if (v0_64 == 0) {
            v0_64 = (u64)v1 << 0x39;
            v0_64 = v0_64 >> 0x3f;
            if (v0_64 == 0) {
                goto _L001A2770;
            }
        }
        v0 = *(u8 *)s3;
        if (v0 == 0) {
            *(u8 *)s3 = 6;
        } else {
            v0 = v0 + -1;
            *(u8 *)s3 = v0;
        }
        a0 = 0x423;
        a1 = 0x64;
        SND_Play2D(a0, a1, 0);
        goto _L001A2880;
        _L001A2770:;
        v0_64 = (u64)v1 << 0x3a >> 0x3f;
        if (v0_64 == 0) {
            v0_64 = (u64)v1 << 0x3b;
            v0_64 = v0_64 >> 0x3f;
            if (v0_64 == 0) {
                goto _L001A27C8;
            }
        }
        v1 = *(u8 *)s3;
        v0 = 6;
        if (v1 == v0) {
            *(u8 *)s3 = 0;
        } else {
            v0 = v1 + 1;
            *(u8 *)s3 = v0;
        }
        a0 = 0x423;
        a1 = 0x64;
        SND_Play2D(a0, a1, 0);
        goto _L001A2880;
        _L001A27C8:;
        v0 = *(u8 *)(s2 + 0x21);
        v0_64 = (u64)v0 << 0x39 >> 0x3f;
        if (v0_64 != 0) {
            s0 = *(u8 *)s3;
            v0 = (u32)MdlMng;
            a0 = s0 + 0xdc;
            v1 = a0 * 0x1c0;
            a0 = (s32)((u8 *)MdlMng + v1);
            ChangeAnimParam((void *)a0, 0, 0.0f);
            v0 = (u8)s0;
            s1 = 0;
            v1 = v0 << 4;
            v0 = (u32)R003_CurReferBoxId;
            s0 = (s32)((u8 *)R003_CurReferBoxId + v1);
            do {
                v1 = *(s32 *)s0;
                if (v1 != (u32)-1) {
                    v1 = (s32)(s3 + (u32)v1);
                    v1 = *(u8 *)((v1 + 4));
                    v0 = (u32)MdlMng;
                    a0 = v1 + 0xe3;
                    v1 = a0 * 0x1c0;
                    a0 = (s32)((u8 *)MdlMng + v1);
                    ChangeAnimParam((void *)a0, 1, 0.0f);
                }
                s1 = s1 + 1;
                v0 = s1 < (s32)4;
                s0 = s0 + 4;
            } while (v0 != 0);
            v0 = 6;
            *(u32 *)RiddleMng = v0;
        }
    }
    _L001A2880:;
    Riddle003BlockUpdate();
    v1 = 7;
    a0 = *(s32 *)RiddleMng;
    if (a0 != v1) {
        v1 = 1;
        a0 = *(s32 *)(RiddleMng + 0xc);
        if (a0 != v1) {
            v1 = *(u8 *)(s2 + 0x21);
            v1_64 = (u64)v1 << 0x3a >> 0x3f;
            if (v1_64 != 0) {
                u8 stackFrame_60[16] __attribute__((aligned(16))) = {0};
                a3 = (u8 *)EndRiddleModeFunc;
                SetFadeMng(2, (signed int *)((u8 *)&stackFrame_60[0]), 0x50, EndRiddleModeFunc,
                    (void *)0, 0x1e, 0x32);
                v1 = 7;
                *(u32 *)RiddleMng = v1;
                *(u32 *)(RiddleMng + 0xc) = 0;
            } else {
                v1 = *(u8 *)(s3 + 1);
                branchcond_1a2924 = v1 == 0;
                if (!branchcond_1a2924) {
                    u8 stackFrame_50[16] __attribute__((aligned(16))) = {0};
                    a0 = 2;
                    a3 = (u8 *)EndRiddleModeFunc;
                    SetFadeMng(a0, (signed int *)((u8 *)&stackFrame_50[0]), 0x50,
                        EndRiddleModeFunc, (void *)0, 0x1e, 0x32);
                    v1 = 7;
                    *(u32 *)RiddleMng = v1;
                    v0 = 1;
                    *(u8 *)(s3 + 1) = 0;
                    a0 = 0x424;
                    a1 = 0x64;
                    *(u32 *)(RiddleMng + 0xc) = v0;
                    SND_Play2D(a0, a1, 0);
                }
            }
        }
    }
    return;
}

void Riddle003BlockUpdate(void) {
    R003GodShelf *lpGodShelf;
    R003Mdl *lpMdlMng;
    s32 i;
    s32 CurId;
    u8 TmpBox[4];
    u32 *id;
    u8 *tb;

    lpGodShelf = (R003GodShelf *)(RiddleMng + 0x38);

    CurId = lpGodShelf->NowCur;
    if (*(s32 *)RiddleMng == 6) {
        lpMdlMng = (R003Mdl *)MdlMng + (lpGodShelf->Box[R003_CurReferBoxId[CurId * 4]] + 0xe3);
        if (CheckAnimEndFrame(lpMdlMng->lpAnimCtrl) != 0) {
            if (lpMdlMng->IndexAnim == 0) {
                *(s32 *)RiddleMng = 5;
                lpGodShelf->Complete = R003_CheckComplete();
            } else {
                if (CurId <= 2) {
                    TmpBox[0] = lpGodShelf->Box[R003_CurReferBoxId[CurId * 4 + 3]];
                    TmpBox[1] = lpGodShelf->Box[R003_CurReferBoxId[CurId * 4]];
                    TmpBox[2] = lpGodShelf->Box[R003_CurReferBoxId[CurId * 4 + 1]];
                    TmpBox[3] = lpGodShelf->Box[R003_CurReferBoxId[CurId * 4 + 2]];
                } else {
                    TmpBox[0] = lpGodShelf->Box[R003_CurReferBoxId[CurId * 4 + 2]];
                    TmpBox[1] = lpGodShelf->Box[R003_CurReferBoxId[CurId * 4]];
                    TmpBox[2] = lpGodShelf->Box[R003_CurReferBoxId[CurId * 4 + 1]];
                }
                for (i = 0, id = &R003_CurReferBoxId[CurId * 4], tb = TmpBox; i < 4; i++, id++, tb++) {
                    if (*id != -1) {
                        lpGodShelf->Box[*id] = *tb;
                        lpMdlMng = (R003Mdl *)MdlMng + (lpGodShelf->Box[*id] + 0xe3);
                        sceVu0CopyVector(lpMdlMng->Pos, &R003_BlockPos[*id * 4]);
                        ChangeAnimParam(lpMdlMng, 0, 0.0f);
                    }
                }
            }
        }
    }
    Riddle003UpdateAmbient();
}

static void Riddle003UpdateAmbient(void) {
    s32 t0;
    u8 *a3;
    u8 *s2;
    s32 a2;
    s32 a1;
    s32 a0;
    u32 v1;
    u8 *s1;
    s32 s0;
    float f1;

    a2 = 0;
    a3 = (u8 *)MdlMng + 0x18100;
    s2 = (u8 *)RiddleMng + 0x38;
    t0 = 0;
    v1 = 0x3f330000;
    a0 = 0x3f330000 | 0x3333;
    a1 = 0x3e4ccccd;
    do {
        v1 = *(u8 *)s2;
        if (v1 != (u32)t0) {
            *(u32 *)(a3 + 0xb0) = a1;
            *(u32 *)(a3 + 0xb4) = a1;
            *(u32 *)(a3 + 0xb8) = a1;
        } else {
            *(u32 *)(a3 + 0xb0) = a0;
            *(u32 *)(a3 + 0xb4) = a0;
            *(u32 *)(a3 + 0xb8) = a0;
        }
        t0 = t0 + 1;
        v1 = t0 < (s32)7;
        a3 = (u8 *)(a3 + 0x1c0);
    } while (v1 != 0);
    s0 = 0;
    s1 = (u8 *)MdlMng + 0x18d40;
    do {
        v1 = (s32)(s2 + s0);
        v1 = *(u8 *)((v1 + 4));
        if (v1 != (u32)s0) {
            v1 = 0x3e4ccccd;
            *(u32 *)(s1 + 0xb0) = 0x3e4ccccd;
            *(u32 *)(s1 + 0xb4) = 0x3e4ccccd;
            *(u32 *)(s1 + 0xb8) = 0x3e4ccccd;
        } else {
            f1 = *(float *)(s1 + 0xb0);
            v1 = 0x3e99999a;
            if (f1 < 0.300000012f && (u32)a2 == 0) {
                SND_Play2D(0x42d, 0x64, 0);
                a2 = 1;
            }
            v1 = 0x3f333333;
            *(u32 *)(s1 + 0xb0) = 0x3f333333;
            *(u32 *)(s1 + 0xb4) = 0x3f333333;
            *(u32 *)(s1 + 0xb8) = 0x3f333333;
        }
        s0 = s0 + 1;
        v1 = s0 < (s32)0xc;
        s1 = (u8 *)(s1 + 0x1c0);
    } while (v1 != 0);
    return;
}

u32 CheckRiddleMode(void) {
    u32 v0;

    v0 = *(u32 *)RiddleMng;
    return (u32)v0 != 0;
}
