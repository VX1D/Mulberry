#include "common.h"

/* SFX_DeleteBySfxIdx @ 0x1BB8E0 .. 0x1BB8E8 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j SfxMng_DeleteBySfxIdx at 0x1bb8e0 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 SfxMng_DeleteBySfxIdx();

/* SFX_Idle @ 0x1BB8F0 .. 0x1BB94C (0x5c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3c888865 at 0x1bb918
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void SFX_Action(float);

/* SFX_ConfirmReflect @ 0x1BB950 .. 0x1BB968 (0x18 bytes) */
/*
 * dcomp notes:
 *   return: lbu at 0x1bb964 computes the return value
 *   declaration vs inferred signature: return signed int vs inferred u8
 */

static u32 s_setting[260];
static u8 s_add_data_buff[0x400];

/* SFX_EnableAction @ 0x1BB970 .. 0x1BB97C (0xc bytes) */
/*
 * dcomp notes:
 *   tail: j SfxMng_EnableAction at 0x1bb974 leaves the function
 *   a0 forwarded to SfxMng_EnableAction
 *   a1 forwarded to SfxMng_EnableAction
 *   declaration vs inferred signature: return signed int vs inferred void
 */

extern signed int SfxMng_EnableAction(signed int, signed int, signed int, unsigned short);

/* SFX_EnableDraw @ 0x1BB980 .. 0x1BB98C (0xc bytes) */
/*
 * dcomp notes:
 *   tail: j SfxMng_EnableDraw at 0x1bb984 leaves the function
 *   a0 forwarded to SfxMng_EnableDraw
 *   a1 forwarded to SfxMng_EnableDraw
 *   declaration vs inferred signature: return signed int vs inferred void
 */

extern signed int SfxMng_EnableDraw(signed int, signed int, signed int, unsigned short);

typedef struct {
    u8 pad[0x10];
    u8 *model;
} MdlMngType;

extern unsigned short SList_PushFront(void *, void *);
extern void *SList_GetElemPtr(void *, unsigned short);
extern signed int SfxMng_AttachMatrix(signed int, void *);
extern u32 s_pAddDataList;


/* SFX_DeleteAll @ 0x1BBA20 .. 0x1BBA4C (0x2c bytes, frame 0x10) */

extern void SfxMng_DeleteAll(signed int);
extern void SList_DeleteAll();
extern void SfxPLight_DeleteAll(void);
extern u32 s_pAddDataList;

/* SFX_Delete @ 0x1BBA50 .. 0x1BBA58 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j SfxMng_Kill at 0x1bba50 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern signed int SfxMng_Kill(signed int);

extern int SfxMng_SfxCreate(s16,float *,float *,float *,void *,void *,u8,u8);


extern void SfxCalc_Vec2Ang(float *,float *,float *);


extern void SfxCalc_Vec2Ang(float *,float *,float *);


/* SFX_Create_OnAng @ 0x1BBD60 .. 0x1BBD80 (0x20 bytes) */
/*
 * dcomp notes:
 *   tail: j SfxMng_SfxCreate at 0x1bbd78 leaves the function
 *   declaration vs inferred signature: return signed int vs inferred void
 */

extern signed int SfxMng_SfxCreate(signed short, float *, float *, float *, void *, void *,
    unsigned char, unsigned char);

/* SFX_Create_OnDir_Dmg2 @ 0x1BBD80 .. 0x1BBE14 (0x94 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x60 escapes at 0x1bbdb8
 *   stack: address of the slot at 0x64 escapes at 0x1bbdb8
 *   declaration vs inferred signature: return signed int vs inferred void
 */

extern void SfxCalc_Vec2Ang(float *, float *, float *);

/* SFX_DrawSingleEmitter @ 0x1BBF20 .. 0x1BBF80 (0x60 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 GetTime(void);
extern signed int SfxDebug_TmrGraph_Start(unsigned short);
extern void PtclMng_DrawSingleEmitter(void *);
extern signed int SfxDebug_TmrGraph_End(unsigned short);
extern u32 s_draw_time;

/* SFX_DrawSinglePtcl @ 0x1BBF80 .. 0x1BBFE0 (0x60 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */



extern void PtclMng_DrawSinglePtcl(void *);

/* SFX_DrawAfterOT @ 0x1BBFE0 .. 0x1BC058 (0x78 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3c888865 at 0x1bc00c
 *   declaration vs inferred signature: return void vs inferred u32
 */



extern signed int SfxTracer_DrawAll(void);
extern void SfxDomanString_Act(float);
extern void SfxDomanString_Draw(void);
extern signed int SfxBugs_DrawAll(void);

/* SFX_Draw @ 0x1BC060 .. 0x1BC0E8 (0x88 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */



extern void *PtclMng_SfxSeekFirst(void);
extern void PtclMng_Draw(void *);
extern void *PtclMng_SfxSeekNext(void);

struct SfxStateStorage { u8 value; u8 padding[3]; };
struct SfxStateStorage s_states;
u32 s_draw_time;
u32 s_act_time;
u32 s_pAddDataList;

/* SFX_Action @ 0x1BC0F0 .. 0x1BC4A4 (0x3b4 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1bc114 is a float copy
 *   delay: dsll32 at 0x1bc138 writes a register its branch at 0x1bc134 reads
 *   fpu: float literal 0x00000000 at 0x1bc1c4
 *   fpu: mov.s at 0x1bc294 is a float copy
 *   fpu: mov.s at 0x1bc29c is a float copy
 *   fpu: mov.s at 0x1bc2a4 is a float copy
 *   fpu: mov.s at 0x1bc2ac is a float copy
 *   fpu: mov.s at 0x1bc2b4 is a float copy
 *   fpu: float literal 0x00000000 at 0x1bc374
 *   fpu: mov.s at 0x1bc464 is a float copy
 *   cfg: kept branch: 0x1bc138 if (..) goto .L001BC2D8
 *   cfg: loop body is not one contiguous region: .L001BC160
 *   cfg: loop body is not one contiguous region: .L001BC338
 *   cfg: loop body is not one contiguous region: .L001BC3E0
 */

extern void SfxDebug_TmrGraph_Clear();
extern unsigned short SList_GetFrontElem(void *);
extern unsigned short SList_GetNextElem(void *, unsigned short);
extern signed int SList_Delete(void *, unsigned short);
extern signed int CheckDramaDrawModel(void *);
extern unsigned char SfxMng_GetSfxState(signed int);
extern void SfxMng_Action(float);
extern void PtclMng_Action(float);
extern void SfxPLight_ActionAll(float);
extern signed int SfxTracer_ActionAll(float);
extern void SfxFog_Action(float);
extern u32 SfxDbg_GetDebugFlag();
extern signed int SfxBugs_ActionAll(float);
extern u8 GameSt[];
extern u32 MdlMng[];
extern u32 V0[];
static u32 count_1065 = 0x1;

struct dw_1955965_fields_5a618eba;
struct dw_1958857_fields_5a618eba;
#ifndef PROTO_DW_1970470_FIELDS_5A618EBA
#define PROTO_DW_1970470_FIELDS_5A618EBA
struct dw_1970470_fields_5a618eba { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_1966190_FIELDS_5A618EBA
#define PROTO_DW_1966190_FIELDS_5A618EBA
struct dw_1966190_fields_5a618eba { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_1965811_FIELDS_5A618EBA
#define PROTO_DW_1965811_FIELDS_5A618EBA
struct dw_1965811_fields_5a618eba { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_1955965_fields_5a618eba *lpMdl; };
#endif
#ifndef PROTO_DW_1955965_FIELDS_5A618EBA
#define PROTO_DW_1955965_FIELDS_5A618EBA
struct dw_1955965_fields_5a618eba { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_1958857_fields_5a618eba *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_1955965_fields_5a618eba *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_1970470_fields_5a618eba DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_1966190_fields_5a618eba flags; unsigned char _pad1[3]; struct dw_1965811_fields_5a618eba Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_1963853_FIELDS_5A618EBA
#define PROTO_DW_1963853_FIELDS_5A618EBA
struct dw_1963853_fields_5a618eba { unsigned int initialized : 1; unsigned int play : 1; unsigned int step : 1; unsigned int draw : 1; unsigned int dmy : 28; };
#endif
#ifndef PROTO_DW_1963365_FIELDS_5A618EBA
#define PROTO_DW_1963365_FIELDS_5A618EBA
union dw_1963365_fields_5a618eba { unsigned int ui32; struct dw_1963853_fields_5a618eba b; };
#endif
#ifndef PROTO_DW_1968942_FIELDS_5A618EBA
#define PROTO_DW_1968942_FIELDS_5A618EBA
struct dw_1968942_fields_5a618eba { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA__160__HP_FFA79371_DEFINED
#define DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA__160__HP_FFA79371_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA__160__HP_FFA79371 = (int)&(((struct dw_1955965_fields_5a618eba *)0)[160].Hp) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA__160__LPCTRLST_A3E984BD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA__160__LPCTRLST_A3E984BD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA__160__LPCTRLST_A3E984BD = (int)&(((struct dw_1955965_fields_5a618eba *)0)[160].lpCtrlSt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA_BERASEBYMAPDRAW_D9478265_DEFINED
#define DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA_BERASEBYMAPDRAW_D9478265_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA_BERASEBYMAPDRAW_D9478265 = (int)&(((struct dw_1955965_fields_5a618eba *)0)->bEraseByMapDraw) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA_BUSE_0FA692BB_DEFINED
#define DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA_BUSE_0FA692BB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA_BUSE_0FA692BB = (int)&(((struct dw_1955965_fields_5a618eba *)0)->bUse) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA_LPCTRLST_846830BF_DEFINED
#define DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA_LPCTRLST_846830BF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA_LPCTRLST_846830BF = (int)&(((struct dw_1955965_fields_5a618eba *)0)->lpCtrlSt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1968942_FIELDS_5A618EBA_GAMEMODE_D2D9BD07_DEFINED
#define DCOMP_OFF_STRUCT_DW_1968942_FIELDS_5A618EBA_GAMEMODE_D2D9BD07_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1968942_FIELDS_5A618EBA_GAMEMODE_D2D9BD07 = (int)&(((struct dw_1968942_fields_5a618eba *)0)->GameMode) - 0 };
#endif


/* SFX_Initialize_LoadFinish_CallBack @ 0x1BC4B0 .. 0x1BC57C (0xcc bytes, frame 0x20) */

extern char *SfxFIO_GetSfxDataFile_Data(void);
extern unsigned short SfxFIO_GetSfxDataNum(void);
extern void SfxMng_InitSystem(void *, signed int, signed int, signed int);
extern char *SfxFIO_GetPtclDataFile_Data(void);
extern unsigned short SfxFIO_GetPtclDataNum(void);
extern void PtclMng_InitDebug(void *, signed int, signed int, signed int, signed int);
extern void * SList_Init(void *, unsigned int, unsigned short);
extern void SfxCalc_RandInit(void);
extern void SfxCalc_CosSinTableInit(void);
extern void SfxMdl_InitMgr(void);
extern void SfxPLight_Initialize(void);
extern signed int SfxFlicker_Initialize(void);
extern signed int SfxTracer_Initialize(void);
extern void SfxDomanString_Init(void);

/* SFX_Initialize @ 0x1BC580 .. 0x1BC60C (0x8c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   literal: @1663 is the string 'sfx_data.bnd'
 */

extern void SfxDraw_Initialize(void);
extern void SfxFog_Initialize(void);
extern signed int SfxFIO_StartLoadSfxBindFile(char *);
extern signed int SfxBugs_Initialize(void);
extern void SfxScriptIF_Initialize(void);

/* SFX_EnableMillorMode @ 0x1BC650 .. 0x1BC658 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j PtclMng_EnableMillorMode at 0x1bc650 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern void PtclMng_EnableMillorMode(signed int);

/* SFX_BurnModel @ 0x1BC660 .. 0x1BC668 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j SfxMng_BurnModel at 0x1bc660 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern signed int SfxMng_BurnModel(void *);

/* SFX_SetPos @ 0x1BC670 .. 0x1BC678 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j SfxMng_SetPos at 0x1bc670 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern signed int SfxMng_SetPos(signed int, float *);

/* SFX_GetSettingData @ 0x1BC680 .. 0x1BC68C (0xc bytes) */

static u32 s_setting[260];
static u8 s_add_data_buff[0x400];

static u32 s_setting[260];
typedef struct { u32 w[0x104]; } SFX_SetSettingData_t;


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SFX_SetSettingData(void *pData_);
u8 * SFX_GetSettingData(void);
signed int SFX_SetPos(signed int a0 , float *a1 );
signed int SFX_BurnModel(void *a0 );
void SFX_EnableMillorMode(signed int a0 );
signed int SFX_IsBloodPool(unsigned short a0 );
signed int SFX_Initialize(void);
signed int SFX_Initialize_LoadFinish_CallBack(void);
void SFX_Action(float f12 );
void SFX_Draw(void);
void SFX_DrawAfterOT(void);
void SFX_DrawSinglePtcl(void *a0 );
void SFX_DrawSingleEmitter(void *a0 );
signed int SFX_Create_OnDir(unsigned short a0 , float *a1 , float *a2 );
signed int SFX_Create_OnDir_Dmg(unsigned short a0 , float *a1 , float *a2 , unsigned char a3 , unsigned char t0 );
signed int SFX_Create_OnDir_Dmg2(unsigned short a0 , float *a1 , float *a2 , unsigned char a3 , unsigned char t0 , void *t1 );
signed int SFX_Create_OnAng(unsigned short a0 , float *a1 , float *a2 );
int SFX_Create_OnDir_Attach(u16 effect,u32 position,float *direction,u32 model,u32 bone,u8 mode,u8 flag);
int SFX_Create_OnDir_Attach2(u16 effect,float *position,float *direction,u32 model,u16 bone,u8 mode,u8 flag,void *extra);
int SFX_Create_OnAng_Attach(u16 effect,float *position,float *angle,u32 model,u32 bone,u8 mode,u8 flag);
signed int SFX_Delete(signed int a0 );
void SFX_DeleteAll(signed int a0 );
signed int SFX_AttachMdlMng(signed int hSfx, MdlMngType *pMdlMng, unsigned short parts_id);
signed int SFX_EnableDraw(signed int a0 , signed int a1 , unsigned short a2 );
signed int SFX_EnableAction(signed int a0 , signed int a1 , unsigned short a2 );
signed int SFX_ConfirmReflect(unsigned short a0 );
void SFX_Idle(unsigned short a0 );
void SFX_DeleteBySfxIdx(void);
unsigned short ConvBloodPool_Nml_Reset(unsigned short a0 );


void SFX_SetSettingData(void *pData_) {
    *(SFX_SetSettingData_t *)s_setting = *(SFX_SetSettingData_t *)pData_;
}

u8 * SFX_GetSettingData(void) {
    return (u8 *)s_setting;
}

signed int SFX_SetPos(signed int a0 /* r4 */, float *a1 /* r5 */) {
    return SfxMng_SetPos(a0, a1);
}

signed int SFX_BurnModel(void *a0 /* r4 */) {
    return SfxMng_BurnModel(a0);
}

void SFX_EnableMillorMode(signed int a0 /* r4 */) {
    PtclMng_EnableMillorMode(a0);
    return;
}

/* SFX_IsBloodPool @ 0x1BC610 .. 0x1BC648 (0x38 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int SFX_IsBloodPool(unsigned short a0 /* r4 */) {
    u32 a0_word = a0;
    s32 v0;
    u32 v1;

    v1 = (s32)(u16)a0_word + -0x2c8;
    v0 = 0;
    if (v1 < (u32)5) {
        a0_word = 1;
        v1 = a0_word << v1;
        if ((u32)(v1 & 0x13) != 0) {
            v0 = a0_word;
        }
    }
    return v0;
}

signed int SFX_Initialize(void) {
    u32 a0;
    s32 v0;

    v0 = 0;
    ((struct { unsigned char _pad:1; unsigned char f:1; } *)&s_states)->f = 1;
    ((struct { unsigned char _pad:2; unsigned char f:1; } *)&s_states)->f = 0;
    ((struct { unsigned char _pad:3; unsigned char f:1; } *)&s_states)->f = 1;
    SfxDraw_Initialize();
    SfxFog_Initialize();
    a0 = (u32)"sfx_data.bnd";
    SfxFIO_StartLoadSfxBindFile("sfx_data.bnd");
    SfxBugs_Initialize();
    SfxScriptIF_Initialize();
    return 1;
}

signed int SFX_Initialize_LoadFinish_CallBack(void) {
    u32 a1;
    u8 *s0;
    u32 a0;
    u32 v0;

    v0 = (u32)SfxFIO_GetSfxDataFile_Data();
    s0 = (u8 *)v0;
    v0 = SfxFIO_GetSfxDataNum();
    SfxMng_InitSystem((void *)s0, 0x200, 1, (u16)v0);
    v0 = (u32)SfxFIO_GetPtclDataFile_Data();
    s0 = (u8 *)v0;
    v0 = SfxFIO_GetPtclDataNum();
    a1 = 0x200;
    PtclMng_InitDebug((void *)s0, a1, a1, 1, (u16)v0);
    a0 = (u32)s_add_data_buff;
    v0 = (u32)SList_Init((void *)s_add_data_buff, 0x400, 0xc);
    s_pAddDataList = v0;
    SfxCalc_RandInit();
    SfxCalc_CosSinTableInit();
    SfxMdl_InitMgr();
    SfxPLight_Initialize();
    SfxFlicker_Initialize();
    SfxTracer_Initialize();
    SfxDomanString_Init();
    a0 = 1;
    ((struct { unsigned char f:1; } *)&s_states)->f = 1;
    return 1;
}
void SFX_Action(float f12 /* f12 */) {
    float f20;
    u32 a2;
    u32 s0;
    u32 a1;
    u64 v0_64;
    u32 a0;
    u16 s4;
    u32 v1;
    u8 *s3;
    u32 s2;
    s32 s1;
    float f1;
    u32 v0;

    f20 = (float)f12;
    s0 = GetTime();
    SfxDebug_TmrGraph_Clear();
    SfxDebug_TmrGraph_Start(0);
    v1 = *(u8 *)((u8 *)&s_states);
    v0_64 = (u64)v1 << 0x3e >> 0x3f;
    if (v0_64 == 0) {
        v0_64 = (u64)v1 << 0x3d;
        v0_64 = v0_64 >> 0x3f;
        if (v0_64 == 0) {
            goto _L001BC2D8;
        }
    }
    a0 = s_pAddDataList;
    s4 = SList_GetFrontElem((void *)a0);
    v0 = 0xffff;
    if ((u32)s4 != v0) {
        do {
            a0 = s_pAddDataList;
            v0 = (u32)SList_GetElemPtr((void *)a0, s4);
            s3 = (u8 *)v0;
            a0 = s_pAddDataList;
            v0 = SList_GetNextElem((void *)a0, s4);
            a0 = *(s32 *)(s3 + 4);
            s2 = (u16)v0;
            v0 = *(u8 *)a0;
            if (v0 == 0) {
                a0 = *(s32 *)s3;
                SfxMng_Kill(a0);
                a0 = s_pAddDataList;
                SList_Delete((void *)a0, s4);
            } else {
                v0 = *(u8 *)((a0 + 2)) != 0 || 0.0f == *(float *)((a0 + 0x10c)) || *(u8 *)((a0 + 3)) != 0 ||
                    (GameSt[(DCOMP_OFF_STRUCT_DW_1968942_FIELDS_5A618EBA_GAMEMODE_D2D9BD07 / 1)] == 1 && !CheckDramaDrawModel((void *)a0));
                a0 = *(s32 *)s3;
                s1 = v0 ^ 1;
                SfxMng_EnableDraw(a0, s1, 0, 0);
                v1 = *(s32 *)(s3 + 4);
                v0 = 2;
                v1 = *(s32 *)((v1 + 0xc));
                v1 = *(u16 *)((v1 + 0xa));
                if (v1 != v0) {
                    a0 = *(s32 *)s3;
                    SfxMng_EnableAction(a0, s1, 0, 0);
                }
                a0 = *(s32 *)s3;
                v0 = (u8)SfxMng_GetSfxState(a0);
                if (v0 == 0) {
                    a0 = s_pAddDataList;
                    SList_Delete((void *)a0, s4);
                }
            }
            s4 = s2;
            v0 = 0xffff;
        } while ((u32)s4 != v0);
    }
    SfxMng_Action((float)f20);
    PtclMng_Action((float)f20);
    SfxPLight_ActionAll((float)f20);
    SfxTracer_ActionAll((float)f20);
    SfxFog_Action((float)f20);
    v0 = 0;
    ((union dw_1963365_fields_5a618eba *)&s_states)->b.step = 0;
    _L001BC2D8:;
    v0 = SfxDbg_GetDebugFlag();
    v0 = v0 & 1;
    if (v0 != 0) {
        v1 = MdlMng[(DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA__160__LPCTRLST_A3E984BD / 4)];
        MdlMng[(DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA__160__HP_FFA79371 / 4)] = 0x64;
        *(u32 *)((v1 + 0x1a0)) = 0;
    }
    v0 = GameSt[(DCOMP_OFF_STRUCT_DW_1968942_FIELDS_5A618EBA_GAMEMODE_D2D9BD07 / 1)];
    if (v0 == 0) {
        v1 = count_1065;
        v0 = 0xf0;
        v0 = v1 % 0xf0;
        s2 = 0;
        if (v0 == 0) {
            s1 = 0;
            do {
                v1 = s1 + 0x5400;
                v0 = (u32)MdlMng;
                v1 = (s32)((u8 *)MdlMng + (u32)v1);
                v0 = *(u8 *)((v1 + 0x12b));
                v0 = v0 & 2;
                if (v0 != 0 && *(u8 *)v1 != 0 && *(u8 *)((v1 + 2)) == 0) {
                    f1 = *(float *)((v1 + 0x10c));
                    if (!(0.0f == f1) && *(u8 *)((v1 + 5)) == 0 && *(u8 *)((v1 + 3)) == 0) {
                        a0 = 0x1f;
                        a2 = (u32)V0;
                        SfxMng_SfxCreate(a0, (float *)(s32)(v1 + 0x20), (float *)V0, (float *)0,
                            (void *)0, (void *)0, 0, 0);
                    }
                }
                s2 = s2 + 1;
                s1 = s1 + 0x1c0;
            } while ((s32)s2 < (s32)0x70);
            s1 = 0;
            s2 = 0;
            do {
                u8 *pMdlMng = (u8 *)MdlMng + (s2 + 0x119c0);
                u8 *pEneCtrl = *(u8 **)(pMdlMng + DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA_LPCTRLST_846830BF);
                if (*(u8 *)(pMdlMng + DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA_BUSE_0FA692BB) != 0 && *(u8 *)(pMdlMng + DCOMP_OFF_STRUCT_DW_1955965_FIELDS_5A618EBA_BERASEBYMAPDRAW_D9478265) == 0) {
                    if (*(s32 *)(pEneCtrl + 0x258) > 0) {
                        SfxMng_SfxCreate(0x1f, (float *)(pMdlMng + 0x20), (float *)V0, (float *)0, (void *)0, (void *)0, 0, 0);
                    }
                }
                s1 = s1 + 1;
                s2 = s2 + 0x1c0;
            } while (s1 < 0x32);
        }
        v0 = count_1065;
        v0 = v0 + 1;
        count_1065 = v0;
    }
    SfxBugs_ActionAll((float)f20);
    SfxDebug_TmrGraph_End(0);
    v0 = GetTime();
    v1 = v0 - s0;
    s_act_time = v1;
    return;
}


void SFX_Draw(void) {
    u32 v0;
    u32 s0;

    v0 = GetTime();
    s0 = v0;
    SfxDebug_TmrGraph_Start(1);
    v0 = s_states.value;
    if ((u64)((u64)v0 << 0x3c >> 0x3f) != 0) {
        v0 = (u32)PtclMng_SfxSeekFirst();
        if (v0 != 0) {
            do {
                PtclMng_Draw((void *)v0);
                v0 = (u32)PtclMng_SfxSeekNext();
            } while (v0 != 0);
        }
    }
    SfxDebug_TmrGraph_End(1);
    v0 = GetTime();
    s_draw_time = v0 - s0;
    return;
}



void SFX_DrawAfterOT(void) {
    u32 v0;
    u32 s0;

    v0 = GetTime();
    s0 = v0;
    SfxDebug_TmrGraph_Start(1);
    SfxTracer_DrawAll();
    SfxDomanString_Act(0.0166666005f);
    SfxDomanString_Draw();
    SfxBugs_DrawAll();
    SfxDebug_TmrGraph_End(1);
    v0 = GetTime();
    s_draw_time += (s32)(v0 - s0);
    return;
}



void SFX_DrawSinglePtcl(void *a0 /* r4 */) {
    u32 s1;
    u32 v0;
    u32 s0;
    u32 v1;

    s1 = (u32)a0;
    v0 = GetTime();
    s0 = v0;
    SfxDebug_TmrGraph_Start((s32)1);
    PtclMng_DrawSinglePtcl((void *)(s32)s1);
    SfxDebug_TmrGraph_End((s32)1);
    v0 = GetTime();
    v1 = s_draw_time;
    s_draw_time = (s32)((u8 *)v1 + (s32)(v0 - s0));
    return;
}

void SFX_DrawSingleEmitter(void *a0 /* r4 */) {
    u32 s1;
    u32 v0;
    u32 s0;
    u32 v1;

    s1 = (u32)a0;
    v0 = GetTime();
    s0 = v0;
    SfxDebug_TmrGraph_Start((s32)1);
    PtclMng_DrawSingleEmitter((void *)(s32)s1);
    SfxDebug_TmrGraph_End((s32)1);
    v0 = GetTime();
    v1 = s_draw_time;
    s_draw_time = (s32)((u8 *)v1 + (s32)(v0 - s0));
    return;
}

/* SFX_Create_OnDir @ 0x1BBEB0 .. 0x1BBF20 (0x70 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x30 escapes at 0x1bbed0
 *   stack: address of the slot at 0x34 escapes at 0x1bbed0
 *   declaration vs inferred signature: return signed int vs inferred u32
 */



signed int SFX_Create_OnDir(unsigned short a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */) {
    float *a1_value; // a1
    u32 v0;
    u8 stackFrame_34[12] __attribute__((aligned(4)));
    u8 stackFrame_30[4] __attribute__((aligned(16)));

    SfxCalc_Vec2Ang((float *)a2, (float *)((u8 *)&stackFrame_30[0]), (float *)((u8
        *)&stackFrame_34[0]));
    v0 = 0x3f800000;
    a1_value = a1;
    ((u32 *)stackFrame_34)[2] = 0x3f800000;
    a2 = (float *)((u8 *)&stackFrame_30[0]);
    ((u32 *)stackFrame_34)[1] = 0;
    v0 = SfxMng_SfxCreate(a0, a1_value, a2, (float *)0, (void *)0, (void *)0, 0, 0);
    return v0;
}

/* SFX_Create_OnDir_Dmg @ 0x1BBE20 .. 0x1BBEA8 (0x88 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x50 escapes at 0x1bbe50
 *   stack: address of the slot at 0x54 escapes at 0x1bbe50
 *   declaration vs inferred signature: return signed int vs inferred void
 */



signed int SFX_Create_OnDir_Dmg(unsigned short a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */,
        unsigned char a3 /* r7 */, unsigned char t0 /* r8 */) {
    float *a1_value; // a1
    u32 v0;
    u8 stackFrame_54[12] __attribute__((aligned(4)));
    u8 stackFrame_50[4] __attribute__((aligned(16)));

    SfxCalc_Vec2Ang((float *)a2, (float *)((u8 *)&stackFrame_50[0]), (float *)((u8
        *)&stackFrame_54[0]));
    v0 = 0x3f800000;
    a1_value = a1;
    ((u32 *)stackFrame_54)[2] = 0x3f800000;
    a2 = (float *)((u8 *)&stackFrame_50[0]);
    ((u32 *)stackFrame_54)[1] = 0;
    v0 = SfxMng_SfxCreate(a0, a1_value, a2, (float *)0, (void *)0, (void *)0, a3, t0);
    return v0;
}

signed int SFX_Create_OnDir_Dmg2(unsigned short a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6
        */, unsigned char a3 /* r7 */, unsigned char t0 /* r8 */, void *t1 /* r9 */) {
    void *t1_value; // t1
    float *a1_value; // a1
    u32 v0;
    u8 stackFrame_64[12] __attribute__((aligned(4)));
    u8 stackFrame_60[4] __attribute__((aligned(16)));

    SfxCalc_Vec2Ang((float *)a2, (float *)((u8 *)&stackFrame_60[0]), (float *)((u8
        *)&stackFrame_64[0]));
    v0 = 0x3f800000;
    a1_value = a1;
    t1_value = t1;
    a2 = (float *)((u8 *)&stackFrame_60[0]);
    ((u32 *)stackFrame_64)[2] = 0x3f800000;
    ((u32 *)stackFrame_64)[1] = 0;
    v0 = SfxMng_SfxCreate(a0, a1_value, a2, (float *)0, (void *)0, t1_value, a3, t0);
    return v0;
}

signed int SFX_Create_OnAng(unsigned short a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */) {
    return SfxMng_SfxCreate(a0, a1, a2, (float *)0, (void *)0, (void *)0, 0, 0);
}




int SFX_Create_OnDir_Attach(u16 effect,u32 position,float *direction,u32 model,u32 bone,u8 mode,u8 flag) {
    s32 offset;
    float angles[4] __attribute__((aligned(16)));
    SfxCalc_Vec2Ang(direction,angles,angles+1);
    angles[3]=1.0f;
    angles[2]=0.0f;
    offset=(u32)(u16)bone*64;
    position=SfxMng_SfxCreate(effect,(float *)position,angles,0,(void *)(*(s32 *)(model+16)+offset),0,mode,flag);
    if (position==-1) position=-1;
    else {
        u16 entry=SList_PushFront((void *)s_pAddDataList,0);
        if (entry!=65535) {
            u8 *data=(u8 *)SList_GetElemPtr((void *)s_pAddDataList,entry);
            *(u32 *)data=position;
            *(u32 *)(data+4)=model;
            *(u16 *)(data+8)=bone;
            SfxMng_AttachMatrix(position,(void *)(*(s32 *)(model+16)+offset));
        }
    }
    return position;
}
int SFX_Create_OnDir_Attach2(u16 effect,float *position,float *direction,u32 model,u16 bone,u8 mode,u8 flag,void *extra) {
    s32 offset;
    float angles[4] __attribute__((aligned(16)));
    SfxCalc_Vec2Ang(direction,angles,angles+1);
    angles[3]=1.0f;
    angles[2]=0.0f;
    offset=(u32)(u16)bone*64;
    position=(float *)SfxMng_SfxCreate(effect,position,angles,0,(void *)(*(s32 *)(model+16)+offset),extra,mode,flag);
    if ((s32)position==-1) position=(float *)-1;
    else {
        u16 entry=SList_PushFront((void *)s_pAddDataList,0);
        if (entry!=65535) {
            u8 *data=(u8 *)SList_GetElemPtr((void *)s_pAddDataList,entry);
            *(u32 *)data=(u32)position;
            *(u32 *)(data+4)=model;
            *(u16 *)(data+8)=bone;
            SfxMng_AttachMatrix((s32)position,(void *)(*(s32 *)(model+16)+offset));
        }
    }
    return (int)position;
}



int SFX_Create_OnAng_Attach(u16 effect,float *position,float *angle,u32 model,u32 bone,u8 mode,u8 flag) {
    u32 savedModel;
    u32 savedBone;
    s32 result;
    s32 offset;
    savedModel=model;
    savedBone=bone;
    offset=(u32)(u16)bone*64;
    result=SfxMng_SfxCreate(effect,position,angle,0,(void *)(*(s32 *)(savedModel+16)+offset),0,mode,flag);
    if (result==-1) result=-1;
    else {
        u16 entry=SList_PushFront((void *)s_pAddDataList,0);
        if (entry!=65535) {
            u8 *data=(u8 *)SList_GetElemPtr((void *)s_pAddDataList,entry);
            *(s32 *)data=result;
            *(u32 *)(data+4)=savedModel;
            *(u16 *)(data+8)=savedBone;
            SfxMng_AttachMatrix(result,(void *)(*(s32 *)(savedModel+16)+offset));
        }
    }
    return result;
}

signed int SFX_Delete(signed int a0 /* r4 */) {
    return SfxMng_Kill(a0);
}

void SFX_DeleteAll(signed int a0 /* r4 */) {
    SfxMng_DeleteAll(a0);
    SList_DeleteAll(s_pAddDataList);
    SfxPLight_DeleteAll();
    return;
}

signed int SFX_AttachMdlMng(signed int hSfx, MdlMngType *pMdlMng, unsigned short parts_id) {
    unsigned short hElem;
    void *pData;

    hElem = SList_PushFront((void *)s_pAddDataList, (void *)0);
    if (hElem == 0xffff) {
        return 0;
    }
    pData = SList_GetElemPtr((void *)s_pAddDataList, hElem);
    *(signed int *)pData = hSfx;
    *(void **)((u8 *)pData + 4) = pMdlMng;
    *(unsigned short *)((u8 *)pData + 8) = parts_id;
    SfxMng_AttachMatrix(hSfx, (void *)(pMdlMng->model + ((unsigned int)parts_id << 6)));
    return 1;
}

signed int SFX_EnableDraw(signed int a0 /* r4 */, signed int a1 /* r5 */, unsigned short a2 /* r6
        */) {
    u32 a2_2; // a2

    a2_2 = 0;
    return SfxMng_EnableDraw(a0, a1, 0, a2);
}

signed int SFX_EnableAction(signed int a0 /* r4 */, signed int a1 /* r5 */, unsigned short a2 /* r6
        */) {
    u32 a2_2; // a2

    a2_2 = 0;
    return SfxMng_EnableAction(a0, a1, 0, a2);
}

signed int SFX_ConfirmReflect(unsigned short a0 /* r4 */) {
    u8 *v0;

    v0 = (u8 *)s_setting + 0x10;
    return *(u8 *)(u8 *)(s32)((u8 *)v0 + (u32)(u16)a0);
}

void SFX_Idle(unsigned short a0 /* r4 */) {
    s32 s1;
    u16 s0;
    s32 v1;

    s0 = a0;
    s1 = 0;
    if (0 < (s32)s0) {
        do {
            SFX_Action(0.0166666005f);
            s1 = s1 + 1;
            v1 = s1 < (s32)s0;
        } while ((u32)v1 != 0);
    }
    return;
}

void SFX_DeleteBySfxIdx(void) {
    SfxMng_DeleteBySfxIdx();
    return;
}

/* ConvBloodPool_Nml_Reset @ 0x1BB880 .. 0x1BB8D8 (0x58 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1bb88c writes a register its branch at 0x1bb888 reads
 *   cfg: kept goto: 0x1bb8b0 -> .L001BB8D0
 *   cfg: kept goto: 0x1bb8b8 -> .L001BB8D0
 *   cfg: kept goto: 0x1bb8c0 -> .L001BB8D0
 *   declaration vs inferred signature: return unsigned short vs inferred u32
 */

unsigned short ConvBloodPool_Nml_Reset(unsigned short a0 /* r4 */) {
    u32 v0;

    v0 = 0x2cc;
    switch ((u32)(u16)a0) {
    case 712:
        v0 = 0x2ce;
        return v0;
    case 713:
        v0 = 0x2cf;
        return v0;
    case 716:
        v0 = 0x2d0;
        return v0;
    }
    return a0;
}
