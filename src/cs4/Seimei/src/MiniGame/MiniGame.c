#include "common.h"

/* TMKFunc @ 0x1FF000 .. 0x1FF360 (0x360 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1ff190 writes a register its branch at 0x1ff18c reads
 *   delay: addiu at 0x1ff1a4 writes a register its branch at 0x1ff1a0 reads
 *   delay: addiu at 0x1ff1b8 writes a register its branch at 0x1ff1b4 reads
 *   delay: addiu at 0x1ff1cc writes a register its branch at 0x1ff1c8 reads
 *   delay: addiu at 0x1ff1e0 writes a register its branch at 0x1ff1dc reads
 *   delay: addiu at 0x1ff1f4 writes a register its branch at 0x1ff1f0 reads
 *   cfg: kept branch: 0x1ff030 if (..) goto .L001FF048
 *   cfg: loop header already being structured: .L001FF050
 *   cfg: kept branch: 0x1ff0cc if (..) goto .L001FF0F8
 *   cfg: kept branch: 0x1ff0e4 if (..) goto .L001FF0F8
 *   cfg: loop body is not one contiguous region: .L001FF130
 */

extern signed int CheckVagStmState(unsigned char);
extern void ClearTime(void);
extern void PlayGeneralVagStm(signed int);
extern void KickMdlPacket(void);
extern void MGPadCtrl(void);
extern u32 GetLoopOutFlag();
extern void DrawCalcView();
extern void DrawBackSprite(void *);
extern void MasterMove(void *);
extern void PlayMi3(void *);
extern void MGDieAnimMain(void *);
extern void MGPieceAnimeMain(void *);
extern unsigned int CheckDrawModel(void *);
extern void DrawModel(void *);
extern void GetPieceAnimeInfo();
extern void MGDrawShadow(void *);
extern void DrawSprite(void *);
extern signed int SND_Update(void);
extern void MGFontDrawBegin(signed int);
extern void MGComplsionText(void);
extern void MGTextControl(void);
extern void MGFontDrawEnd(void);
extern void DrawFrameFilter(void);
extern void DrawSynch(void);
extern unsigned int GetTime(void);
extern void FlushCache(int);
extern u8 GameSt[];
extern u8 g_PrcStatus[];
extern u32 g_stSpriteDraw[];
extern u32 MdlMng[];
extern u8 *lpDrawMng;

struct dw_2534096_fields;
struct dw_2549112_fields;
#ifndef PROTO_DW_2547742_FIELDS
#define PROTO_DW_2547742_FIELDS
struct dw_2547742_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_2543491_FIELDS
#define PROTO_DW_2543491_FIELDS
struct dw_2543491_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_2543168_FIELDS
#define PROTO_DW_2543168_FIELDS
struct dw_2543168_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_2534096_fields *lpMdl; };
#endif
#ifndef PROTO_DW_2534096_FIELDS
#define PROTO_DW_2534096_FIELDS
struct dw_2534096_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_2549112_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_2534096_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_2547742_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_2543491_fields flags; unsigned char _pad1[3]; struct dw_2543168_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_2540315_FIELDS
#define PROTO_DW_2540315_FIELDS
struct dw_2540315_fields { unsigned char ctrlID; unsigned char sgmodeID; };
#endif
#ifndef PROTO_DW_2539511_FIELDS
#define PROTO_DW_2539511_FIELDS
struct dw_2539511_fields { unsigned int EN1 : 1; unsigned int EN2 : 1; unsigned int CRTMD : 3; unsigned int MMOD : 1; unsigned int AMOD : 1; unsigned int SLBG : 1; unsigned int ALP : 8; unsigned int p0 : 16; unsigned int p1; };
#endif
#ifndef PROTO_DW_2542936_FIELDS
#define PROTO_DW_2542936_FIELDS
struct dw_2542936_fields { unsigned int INT : 1; unsigned int FFMD : 1; unsigned int DPMS : 2; unsigned int p0 : 28; unsigned int p1; };
#endif
#ifndef PROTO_DW_2539913_FIELDS
#define PROTO_DW_2539913_FIELDS
struct dw_2539913_fields { unsigned int FBP : 9; unsigned int FBW : 6; unsigned int PSM : 5; unsigned int p0 : 12; unsigned int DBX : 11; unsigned int DBY : 11; unsigned int p1 : 10; };
#endif
#ifndef PROTO_DW_2544303_FIELDS
#define PROTO_DW_2544303_FIELDS
struct dw_2544303_fields { unsigned int DX : 12; unsigned int DY : 11; unsigned int MAGH : 4; unsigned int MAGV : 2; unsigned int p0 : 3; unsigned int DW : 12; unsigned int DH : 11; unsigned int p1 : 9; };
#endif
#ifndef PROTO_DW_2543622_FIELDS
#define PROTO_DW_2543622_FIELDS
struct dw_2543622_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int p0 : 8; unsigned int p1; };
#endif
#ifndef PROTO_DW_2536847_FIELDS
#define PROTO_DW_2536847_FIELDS
struct dw_2536847_fields { struct dw_2539511_fields pmode; struct dw_2542936_fields smode2; struct dw_2539913_fields dispfb; struct dw_2544303_fields display; struct dw_2543622_fields bgcolor; };
#endif
#ifndef PROTO_DW_2538090_FIELDS
#define PROTO_DW_2538090_FIELDS
struct dw_2538090_fields { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; };
#endif
#ifndef PROTO_DW_2542602_FIELDS
#define PROTO_DW_2542602_FIELDS
struct dw_2542602_fields { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
#endif
#ifndef PROTO_DW_2548785_FIELDS
#define PROTO_DW_2548785_FIELDS
struct dw_2548785_fields { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
#endif
#ifndef PROTO_DW_2546871_FIELDS
#define PROTO_DW_2546871_FIELDS
struct dw_2546871_fields { unsigned long OFX : 16; unsigned long pad16 : 16; unsigned long OFY : 16; unsigned long pad48 : 16; };
#endif
#ifndef PROTO_DW_2540455_FIELDS
#define PROTO_DW_2540455_FIELDS
struct dw_2540455_fields { unsigned long SCAX0 : 11; unsigned long pad11 : 5; unsigned long SCAX1 : 11; unsigned long pad27 : 5; unsigned long SCAY0 : 11; unsigned long pad43 : 5; unsigned long SCAY1 : 11; unsigned long pad59 : 5; };
#endif
#ifndef PROTO_DW_2537321_FIELDS
#define PROTO_DW_2537321_FIELDS
struct dw_2537321_fields { unsigned long AC : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_2548222_FIELDS
#define PROTO_DW_2548222_FIELDS
struct dw_2548222_fields { unsigned long CLAMP : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_2539393_FIELDS
#define PROTO_DW_2539393_FIELDS
struct dw_2539393_fields { unsigned long DTHE : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_2543884_FIELDS
#define PROTO_DW_2543884_FIELDS
struct dw_2543884_fields { unsigned long ATE : 1; unsigned long ATST : 3; unsigned long AREF : 8; unsigned long AFAIL : 2; unsigned long DATE : 1; unsigned long DATM : 1; unsigned long ZTE : 1; unsigned long ZTST : 2; unsigned long pad19 : 45; };
#endif
#ifndef PROTO_DW_2537437_FIELDS
#define PROTO_DW_2537437_FIELDS
struct dw_2537437_fields { struct dw_2542602_fields frame1; unsigned long frame1addr; struct dw_2548785_fields zbuf1; long zbuf1addr; struct dw_2546871_fields xyoffset1; long xyoffset1addr; struct dw_2540455_fields scissor1; long scissor1addr; struct dw_2537321_fields prmodecont; long prmodecontaddr; struct dw_2548222_fields colclamp; long colclampaddr; struct dw_2539393_fields dthe; long dtheaddr; struct dw_2543884_fields test1; long test1addr; };
#endif
#ifndef PROTO_DW_2551127_FIELDS
#define PROTO_DW_2551127_FIELDS
struct dw_2551127_fields { unsigned long PRIM : 3; unsigned long IIP : 1; unsigned long TME : 1; unsigned long FGE : 1; unsigned long ABE : 1; unsigned long AA1 : 1; unsigned long FST : 1; unsigned long CTXT : 1; unsigned long FIX : 1; unsigned long pad11 : 53; };
#endif
#ifndef PROTO_DW_2539172_FIELDS
#define PROTO_DW_2539172_FIELDS
struct dw_2539172_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int A : 8; float Q; };
#endif
#ifndef PROTO_DW_2548030_FIELDS
#define PROTO_DW_2548030_FIELDS
struct dw_2548030_fields { unsigned long X : 16; unsigned long Y : 16; unsigned long Z : 32; };
#endif
#ifndef PROTO_DW_2544831_FIELDS
#define PROTO_DW_2544831_FIELDS
struct dw_2544831_fields { struct dw_2543884_fields testa; long testaaddr; struct dw_2551127_fields prim; long primaddr; struct dw_2539172_fields rgbaq; long rgbaqaddr; struct dw_2548030_fields xyz2a; long xyz2aaddr; struct dw_2548030_fields xyz2b; long xyz2baddr; struct dw_2543884_fields testb; long testbaddr; };
#endif
#ifndef PROTO_DW_2548380_FIELDS
#define PROTO_DW_2548380_FIELDS
struct dw_2548380_fields { struct dw_2536847_fields disp[2]; struct dw_2538090_fields giftag0; struct dw_2537437_fields draw0; struct dw_2544831_fields clear0; struct dw_2538090_fields giftag1; struct dw_2537437_fields draw1; struct dw_2544831_fields clear1; };
#endif
#ifndef PROTO_DW_2541225_FIELDS
#define PROTO_DW_2541225_FIELDS
struct dw_2541225_fields { struct dw_2548380_fields dbBuf; float camPos[4]; float camAng[4]; float camPosB[4]; float camAngB[4]; float vsMat[4][4]; float wsMat[4][4]; float wvMat[4][4]; float lcMat[4][4]; float wcMat[4][4]; float csMat[4][4]; float scrDepth; unsigned int *sprBuf[2]; int sprBufID; unsigned int DMATag; int ctxt; int dbBufID; int oddeven; unsigned int calcTime; unsigned int drawTime; unsigned int frameTime; float fov; int TotalPolyNum; int TotalPrimNum; float WaterLevel; unsigned char DrawFlag; unsigned char DrawHitModel; unsigned char BlurMode; unsigned char BlurRate; unsigned char ProjectionType; unsigned char unused[15]; float PlaneParam[4]; float FogParam[4]; float FogParam16[4]; };
#endif
#ifndef PROTO_DW_2545305_FIELDS
#define PROTO_DW_2545305_FIELDS
struct dw_2545305_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2534096_FIELDS_BUSE_8A516693_DEFINED
#define DCOMP_OFF_STRUCT_DW_2534096_FIELDS_BUSE_8A516693_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2534096_FIELDS_BUSE_8A516693 = (int)&(((struct dw_2534096_fields *)0)->bUse) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2540315_FIELDS_CTRLID_2D7D2AAE_DEFINED
#define DCOMP_OFF_STRUCT_DW_2540315_FIELDS_CTRLID_2D7D2AAE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2540315_FIELDS_CTRLID_2D7D2AAE = (int)&(((struct dw_2540315_fields *)0)->ctrlID) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2541225_FIELDS_FRAMETIME_B02CAED2_DEFINED
#define DCOMP_OFF_STRUCT_DW_2541225_FIELDS_FRAMETIME_B02CAED2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2541225_FIELDS_FRAMETIME_B02CAED2 = (int)&(((struct dw_2541225_fields *)0)->frameTime) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2545305_FIELDS_CONTROLMODE_CA7C78D2_DEFINED
#define DCOMP_OFF_STRUCT_DW_2545305_FIELDS_CONTROLMODE_CA7C78D2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2545305_FIELDS_CONTROLMODE_CA7C78D2 = (int)&(((struct dw_2545305_fields *)0)->ControlMode) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2545305_FIELDS_SYSTEMCOUNTER_1AB8953F_DEFINED
#define DCOMP_OFF_STRUCT_DW_2545305_FIELDS_SYSTEMCOUNTER_1AB8953F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2545305_FIELDS_SYSTEMCOUNTER_1AB8953F = (int)&(((struct dw_2545305_fields *)0)->SystemCounter) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2545305_FIELDS_SCENENO_957BE9D6_DEFINED
#define DCOMP_OFF_STRUCT_DW_2545305_FIELDS_SCENENO_957BE9D6_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2545305_FIELDS_SCENENO_957BE9D6 = (int)&(((struct dw_2545305_fields *)0)->sceneNo) - 0 };
#endif


/* MenuFunc @ 0x1FF360 .. 0x1FF508 (0x1a8 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1ff404 writes a register its branch at 0x1ff400 reads
 *   delay: addiu at 0x1ff438 writes a register its branch at 0x1ff434 reads
 *   cfg: kept branch: 0x1ff384 if (..) goto .L001FF398
 *   cfg: loop header already being structured: .L001FF398
 *   cfg: kept branch: 0x1ff410 if (..) goto .L001FF430
 *   cfg: kept branch: 0x1ff444 if (..) goto .L001FF468
 */

extern signed int CheckVagStmState(unsigned char);
extern void ClearTime(void);
extern void PlayGeneralVagStm(signed int);
extern void KickMdlPacket(void);
extern void MGPadCtrl(void);
extern u32 GetLoopOutFlag();
extern void DrawBackSprite(void *);
extern void DrawSprite(void *);
extern signed int SND_Update(void);
extern void MGFontDrawBegin(signed int);
extern void MGComplsionText(void);
extern void MGTextControl(void);
extern void MGFontDrawEnd(void);
extern void DrawFrameFilter(void);
extern void DrawSynch(void);
extern unsigned int GetTime(void);
extern void FlushCache(int);
extern u8 GameSt[];
extern u8 g_PrcStatus[2];
extern u32 g_stSpriteDraw[];
extern u8 *lpDrawMng;


extern void SetLoopOutFlag(unsigned char);
extern signed int CheckVagStmFade(unsigned char);
extern signed int SetVagStmFade(unsigned char, unsigned char, signed int);
extern void PlayBgmVagStm(signed int, signed int);
void TMKFunc(void);
extern void TMKFunc();
extern void sghMainLoop();
extern void MGInitControl(void);
extern void MGFreeMdlInfo();


/* ResetMiniGameData @ 0x1FF690 .. 0x1FF6BC (0x2c bytes, frame 0x10) */

extern u32 MGInitCamData(void);
extern void MGInitControl(void);
extern u8 g_PrcStatus[2];

/* InitMiniGameData @ 0x1FF6C0 .. 0x1FF804 (0x144 bytes, frame 0x2f70) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @724 -> 0x24f250
 *   stack: address of the slot at 0x30 escapes at 0x1ff6d4
 *   stack: address of the slot at 0x20 escapes at 0x1ff6fc
 *   stack: address of the slot at 0x30 escapes at 0x1ff7a0
 *   stack: address of the slot at 0x30 escapes at 0x1ff7b0
 *   fpu: float literal 0x41200000 at 0x1ff7d8
 *   stack: address of the slot at 0x20 escapes at 0x1ff7e4
 *   stack: address of the slot at 0x10 escapes at 0x1ff7f0
 *   literal: @724 initializes the 16-byte local at 0x10
 */

extern void InitMirror(void);
extern void InitSandEffect(void);
extern void InitTextureScroll(void);
extern void InitDizzyFilter(void);
extern void InitTVEffect(void);
extern void KnMsgMng_MsgAllClear();
extern int TmpMenuMng_SetUDBlackDraw(void *, int);
extern void InitPointLight(void);
extern void MGInitPieceTbl(void *);
extern void MGInitMdlInfo(void);
extern void MGLoadSetTexId(void *);
extern void MGInitTexInfo(void *, void *);
extern void SND_SetMode(s32);
extern void MGInitTopMenu(void);
extern void SetPointLightOn(signed int, float *, float);
extern signed int UpdatePointLightPos(signed int, float *);
extern u8 GameSt[];
extern u32 g_TmpMenuMng[];
extern u32 g_PieceTable[];
extern u32 g_stSpriteDraw[];

/* GetDiceNum @ 0x1FF810 .. 0x1FF818 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x1ff814 computes the return value
 */

extern u16 g_DiceNum;

/* GetPieceTable @ 0x1FF820 .. 0x1FF82C (0xc bytes) */

extern u32 g_PieceTable[];

/* GetSpriteDraw @ 0x1FF830 .. 0x1FF83C (0xc bytes) */

extern u32 g_stSpriteDraw[];
static u32 g_stSpriteDraw[0xbd0];
static u32 g_PieceTable[0x9c0];
static u16 g_DiceNum;

static u8 g_PrcStatus[0x2];
void *gsHdOrderSerMsg;
void *gsOrderRetryMsg;
void *gsHelpTurnRestMsg;
void *gsHelpKakunin;
void *gsHelpDiceCast;
void *gsHelpChoiKoma;
void *gsHelpChoiDice;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * GetMGPrcStatus(void);
u8 * GetSpriteDraw(void);
u8 * GetPieceTable(void);
u8 * GetDiceNum(void);
void InitMiniGameData(void);
void ResetMiniGameData(void);
signed int MiniGameLoop(void);
void MenuFunc(void);
void TMKFunc(void);


/* GetMGPrcStatus @ 0x1FF840 .. 0x1FF848 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x1ff844 computes the return value
 */

u8 * GetMGPrcStatus(void) {
    return &g_PrcStatus[0];
}

u8 * GetSpriteDraw(void) {
    return (u8 *)g_stSpriteDraw;
}

u8 * GetPieceTable(void) {
    return (u8 *)g_PieceTable;
}

u8 * GetDiceNum(void) {
    return (u8 *)&g_DiceNum;
}

void InitMiniGameData(void) {
    u32 a0;
    u8 *v1;
    u32 v0;
    u8 stackFrame_30[12096] __attribute__((aligned(16))) = {0};
    u8 stackFrame_20[16] __attribute__((aligned(16))) = {0};

    v0 = 0x24f250;
    {
        struct stackFrame_10 { u8 b[16]; } stackFrame_10 __attribute__((aligned(16))) = {{0xcd,
            0xcc, 0x4c, 0x3f, 0x00, 0x00, 0x20, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
            0x3f}};
        v1 = ((u8 *)&stackFrame_10);
        GameSt[4] = 0;
        GameSt[0xf] = 0;
        InitMirror();
        InitSandEffect();
        InitTextureScroll();
        InitDizzyFilter();
        InitTVEffect();
        KnMsgMng_MsgAllClear();
        a0 = (u32)g_TmpMenuMng;
        TmpMenuMng_SetUDBlackDraw((void *)g_TmpMenuMng, 2);
        GameSt[0x13] = 0;
        InitPointLight();
        a0 = (u32)g_PieceTable;
        MGInitPieceTbl((void *)g_PieceTable);
        MGInitMdlInfo();
        MGInitCamData();
        MGLoadSetTexId((void *)((u8 *)&stackFrame_30[0]));
        a0 = (u32)g_stSpriteDraw;
        MGInitTexInfo((void *)g_stSpriteDraw, (void *)((u8 *)&stackFrame_30[0]));
        GameSt[9] = 0;
        SND_SetMode(2);
        MGInitTopMenu();
        GameSt[4] = 0;
        SetPointLightOn(3, (float *)((u8 *)&stackFrame_20[0]), 10.0f);
        UpdatePointLightPos(3, (float *)((u8 *)&stackFrame_10));
        return;
    }
}

void ResetMiniGameData(void) {
    MGInitCamData();
    MGInitControl();
    *(u8 *)g_PrcStatus = 0;
    g_PrcStatus[1] = 0;
    return;
}

signed int MiniGameLoop(void)
{
    SetLoopOutFlag(0);
    while (1) {
        if (GetLoopOutFlag() != 0) break;
        switch (*(u8 *)g_PrcStatus) {
        case 0:
            if (CheckVagStmFade(5)) SetVagStmFade(5, 0, 15);
            else PlayGeneralVagStm(2);
            MenuFunc();
            SetVagStmFade(5, 1, 15);
            break;
        case 1:
            if (CheckVagStmFade(0)) SetVagStmFade(0, 0, 15);
            else PlayBgmVagStm(0, 1);
            TMKFunc();
            SetVagStmFade(0, 1, 15);
            break;
        case 2:
            if (CheckVagStmFade(0)) SetVagStmFade(0, 0, 15);
            else PlayBgmVagStm(0, 1);
            sghMainLoop();
            GameSt[9] = 0x4c;
            *(u8 *)g_PrcStatus = 0;
            MGInitControl();
            SetVagStmFade(0, 1, 15);
            break;
        }
    }
    MGFreeMdlInfo();
    return 0;
}

void MenuFunc(void) {
    u32 a0;
    u32 v1;
    u32 v0;
    s32 s0;

    a0 = 5;
    v0 = CheckVagStmState(a0);
    v1 = v0 + -1;
    s0 = 0;
    if (v1 > (u32)2) {
        v1 = 4;
        if (v0 != v1) {
            goto _L001FF398;
        }
    }
    s0 = 1;
    while (1) {
        _L001FF398:;
        ClearTime();
        v0 = *(s32 *)GameSt;
        v0 = v0 + 1;
        *(u32 *)GameSt = v0;
        if ((u32)s0 == 0) {
            a0 = 5;
            v0 = CheckVagStmState(a0);
            a0 = 2;
            if (v0 == 0) {
                PlayGeneralVagStm(a0);
                s0 = 1;
            }
        }
        KickMdlPacket();
        MGPadCtrl();
        v0 = GetLoopOutFlag();
        if (v0 != 0) {
            break;
        }
        v1 = 8;
        a0 = GameSt[9];
        if (a0 == v1) {
            goto _L001FF420;
        }
        v1 = 0x20;
        if (a0 == v1) {
            goto _L001FF420;
        }
        v1 = 0x2e;
        if (a0 == v1) {
            _L001FF420:;
            *(u8 *)g_PrcStatus = 1;
            return;
        }
        v1 = 0x49;
        if (a0 == v1) {
            goto _L001FF450;
        }
        v1 = 0x4b;
        if (a0 == v1) {
            goto _L001FF450;
        }
        v1 = 0x4a;
        if (a0 == v1) {
            _L001FF450:;
            v1 = a0 + -0x49;
            g_PrcStatus[1] = v1;
            v1 = 2;
            *(u8 *)g_PrcStatus = v1;
            return;
        }
        a0 = (u32)g_stSpriteDraw;
        DrawBackSprite((void *)g_stSpriteDraw);
        a0 = (u32)g_stSpriteDraw;
        DrawSprite((void *)g_stSpriteDraw);
        SND_Update();
        MGFontDrawBegin(0);
        v0 = 1;
        v1 = GameSt[4];
        if (v1 == v0) {
            MGComplsionText();
        } else {
            MGTextControl();
        }
        MGFontDrawEnd();
        DrawFrameFilter();
        DrawSynch();
        v0 = GetTime();
        v1 = ((u32)lpDrawMng);
        *(u32 *)((v1 + 0x418)) = v0;
        FlushCache(0);
    }
    return;
}
void TMKFunc(void) {
    u8 *p;
    u8 i;
    u8 padInit;
    u32 st;
    u32 started;
    u32 scene;

    padInit = 0;
    st = CheckVagStmState(5);
    started = 0;
    if (st - 1 <= 2 || st == 4) {
        started = 1;
    }
    GameSt[(DCOMP_OFF_STRUCT_DW_2545305_FIELDS_CONTROLMODE_CA7C78D2 / 1)] = 0;
    while (1) {
        ClearTime();
        *(u32 *)(GameSt + (DCOMP_OFF_STRUCT_DW_2545305_FIELDS_SYSTEMCOUNTER_1AB8953F / 1)) += 1;
        if (started == 0) {
            if (CheckVagStmState(5) == 0) {
                PlayGeneralVagStm(1);
                started = 1;
            }
        }
        KickMdlPacket();
        if (padInit == 1) {
            MGPadCtrl();
        } else {
            padInit = 1;
        }
        if (GetLoopOutFlag() != 0) {
            break;
        }
        scene = GameSt[(DCOMP_OFF_STRUCT_DW_2545305_FIELDS_SCENENO_957BE9D6 / 1)];
        if (scene - 0x2b <= 1 || scene == 0x1e || scene == 0x44) {
            g_PrcStatus[(DCOMP_OFF_STRUCT_DW_2540315_FIELDS_CTRLID_2D7D2AAE / 1)] = 0;
            return;
        }
        DrawCalcView();
        DrawBackSprite((void *)g_stSpriteDraw);
        for (p = (u8 *)(MdlMng + 0x1500); p != (u8 *)(MdlMng + 0x150e0); p += 0x1c0) {
            if (*(u8 *)(p + DCOMP_OFF_STRUCT_DW_2534096_FIELDS_BUSE_8A516693) != 0) {
                if (GameSt[(DCOMP_OFF_STRUCT_DW_2545305_FIELDS_CONTROLMODE_CA7C78D2 / 1)] != 1) {
                    MasterMove(p);
                    PlayMi3(p);
                    MGDieAnimMain(p);
                    MGPieceAnimeMain(p);
                }
                scene = GameSt[(DCOMP_OFF_STRUCT_DW_2545305_FIELDS_SCENENO_957BE9D6 / 1)];
                if (scene != 0 && scene != 7 && scene != 0x1f && scene != 0x1e && scene != 0x2b && scene != 0x2c && scene != 0x2d && scene != 0x44 && scene != 0x45 && scene != 1 && scene != 2 && scene != 3 && scene != 4 && scene != 5 && scene != 6) {
                    if (CheckDrawModel(p) != 0) {
                        DrawModel(p);
                    }
                }
            }
        }
        for (i = 0; i < 0x1e; i++) {
            GetPieceAnimeInfo();
            MGDrawShadow((u8 *)MdlMng + (i + 0xa1) * 0x1c0);
        }
        for (i = 0; i < 2; i++) {
            MGDrawShadow((u8 *)MdlMng + (i + 0xd3) * 0x1c0);
        }
        DrawSprite((void *)g_stSpriteDraw);
        SND_Update();
        MGFontDrawBegin(0);
        if (GameSt[(DCOMP_OFF_STRUCT_DW_2545305_FIELDS_CONTROLMODE_CA7C78D2 / 1)] == 1) {
            MGComplsionText();
        } else {
            MGTextControl();
        }
        MGFontDrawEnd();
        DrawFrameFilter();
        DrawSynch();
        *(u32 *)(lpDrawMng + DCOMP_OFF_STRUCT_DW_2541225_FIELDS_FRAMETIME_B02CAED2) = GetTime();
        FlushCache(0);
    }
}
