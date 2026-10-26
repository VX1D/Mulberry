#include "common.h"
extern signed int fsScr_ScriptStart();
extern u8 GameEventFlag[];
extern u32 Menu_TD_IsPlay(void);
extern void fsScr_SetPointerData(void *, signed int);
extern void PadSetVib(signed int, float, float, unsigned char, unsigned char, signed int);
extern u8 GameSt[];
extern u32 KnMenuMng_GetPlayMenu(s32);
extern signed int Menu_TD_CallOrder();
extern u32 SetScriptHeartBeat();
extern void SetFadeMng(unsigned char, signed int *, signed int, void *, void *, signed int, signed
    int);
extern void SetFadeMovieLoad(signed int, signed int, signed int);
extern void FECard_Enable_Draw();
extern u32 SetSceneLoad();
extern u32 GetRiddleResult(void);
extern void SetRiddleMode();
extern signed int EtcEventMng_EneExtGeneEvent_End(void *);
extern u32 g_EtcEventMng[];
extern signed int EtcEventMng_EneExtGeneEvent_Start_Corpse(void *);
extern signed int EtcEventMng_EneExtGeneEvent_Start_Room(void *);
extern void SND_Stop();
extern signed int SND_Play2D(signed int, signed short, signed short);
extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern signed int SfxPLight_Delete(unsigned short, float);
extern u8 MdlMng[];
extern unsigned short SfxPLight_Create(float);
extern signed int SfxPLight_SetRadius(unsigned short, float);
extern signed int SfxPLight_SetColor(unsigned short, float *);
extern signed int SfxPLight_SetBlink(unsigned short, float, float);
extern void FreeObjFollowTarget(void *);
extern void SetObjFollowTarget(void *, unsigned short, unsigned short, void *);
extern void SetObjCaveFaceStart(void *);
extern void SetObjTalkEnd(void *);
extern void SetObjTalkStart(void *, signed int, signed int, signed int);
extern void FreeObjMovePath(void *);
extern void SetObjMovePath(void *, signed int, unsigned short, unsigned short);
extern void SetPointLightOff(signed int);
extern void SetFadeSceneLoad(signed int, signed int);
extern signed int CheckVagStmState(unsigned char);
extern u32 SetVagStmFade();
extern u32 StopVagStm();
extern void * GetScriptMdlMng(s32, s32, s32);
extern void PlayBgmVagStm(signed int, signed int);
extern signed int PlayVoiceVagStm(signed int);
extern void PlayGeneralVagStm(signed int);
extern void SetVagStm3D(unsigned char, float *, float, void *);
extern u32 V0[];
extern u32 SFX_Idle();
extern void SfxScriptIF_SetBugColor();
extern void SfxScriptIF_GenerateBugs(float, float, float, float, signed int, float, float, float,
    float, signed int, signed int);
extern signed int SFX_Create_OnAng(unsigned short, float *, float *);
extern signed int GetMapSfxHdl(signed int);
extern signed int SFX_EnableDraw(signed int, signed int, unsigned short);
extern signed int SFX_EnableAction(signed int, signed int, unsigned short);
extern u32 ItemMng_Add_Direct();
extern unsigned short ItemMng_GetItemNum_Direct(unsigned short);
extern signed int ItemMng_GetItemProc();
extern u32 CheckPeepManual(void);
extern u32 StopPeepCamera(void);
extern void SetPeepCamera();
extern void SetLightDizzy();
extern void SfxPostEffect_SetFlickerParam(void *);
extern void SfxPostEffect_SetEnable(unsigned short, signed int);
extern u32 SetLoadCamReserve();
extern void SetCamPathDirect();
extern void SetTargetFreeCamera();
extern u32 GetGameCamInfo(void);
extern void SetCamCtrlMode(unsigned int);
extern u32 GetDramaReadFlag(void);
extern u32 GetFadeDrama(void);
extern void SetFadeDrama(signed int);
extern u32 GetCamCtrlMode(void);
extern void KnMsgMng_SendMsgEx_SetMdlId_AnimId(s32, s32, u16, s32, s32);
extern void KnMsgMng_SendMsgEx(s32, s32, u16);
extern u32 KnMsgMng_GetSelectNum(void);
extern u32 KnMsgMng_CheckMsgNone(void);
extern u32 SetMyNormalMode(void);
extern void SetMyMukadeMode();
extern void SetMyTotterMode(signed int);
extern void SetMyCrouch(void *);
extern u32 SetMyEquip();
extern u32 ChangeMyEquipSound(void);
extern void SetMyControlOn(void);
extern u32 Msg_GetDizzyOffFlag(void);
extern void SetMyDizzy(signed int);
extern signed int CheckMyControlOff(void *);
extern void SetMyControlOff(void);
extern signed int CheckEneRebirth(void *);
extern void * GetMapPartsInfoByCtrlId(signed int, signed int);
extern signed int GetMdlDataIndexFromMapMdlInfo(signed int, signed int);
extern void EneAppear(signed int, signed int, void *, float *, float, float *, unsigned char,
    unsigned short, unsigned char, void *, void *);
extern signed int CheckEneDead(void *);
extern u32 V1[];
extern signed int GetClothDataId(void *);
extern void ReCalcMi3Matrix(void *);
extern void UpdateWorldMatrixInAnim(void *);
extern signed int CsMngStabilize(unsigned int, unsigned int);
extern void fsScr_SetPointerDataF(void *, float);
extern void SetMdlFade(void *, unsigned char, float);
extern void FreeMdlMng(void *);
extern void SetAnimLastFrame(void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern u32 SetGoToEndingFade(void);
extern u32 SetGoToTitleFade(void);
extern void fsScr_SetScrFunc(signed int, void *);
extern void fsScr_SetGameVal(signed int, void *);
static void SCR_GetEventFlag(void *a0 );
extern u32 SCR_SetEventFlag();
static void SCR_GetEventFlag8(void *a0 );
extern u32 SCR_CheckEnterCircle();
extern u32 SCR_CheckEnterRectangle();
extern u32 SCR_CheckEnterRectangleByCtrlId();
static void SCR_ChangeAnimation(void *a0 );
static void SCR_SetAnimLastFrame(void *a0 );
static void SCR_DeleteModel(void *a0 );
static void SCR_SetModelHitOff(void *a0 );
static void SCR_SetModelErase(void *a0 );
static void SCR_SetModelFade(void *a0 );
extern u32 SCR_SetModelPlace();
static void SCR_GetModelPos(void *a0 );
static void SCR_CheckModelUse(void *a0 );
static void SCR_StabilizeModelCloth(void *a0 );
static void SCR_EneAppear(void *a0 );
static void SCR_CheckEneDead(void *a0 );
static void SCR_EneAppearOutLogic(void *a0 );
static u32 SCR_SetEneInLogic(u32 *);
static u32 SCR_SetEneDisableSearch(u32 *);
static void SCR_SetEneOutLogic(void *a0 );
static void SCR_SetEneHpRate(void *a0 );
static u32 SCR_SetEneRebirthTimes(u32 *);
static void SCR_CheckEneRebirth(void *a0 );
extern u32 SCR_SetMyPlace();
static void SCR_CheckMessage(void *a0 );
static void SCR_SendMessageWithMdlAnim(void *a0 );
static void SCR_SendMessageVoiceWithMdlAnim(void *a0 );
static void SCR_StartDrama(void *a0 );
static void SCR_CheckDrama(void *a0 );
extern u32 SCR_SetCamModeFree();
extern u32 SCR_SetPhantomBlast();
static void SCR_SetMapSfxErase(void *a0 );
static void SCR_GenerateSfx(void *a0 );
static void SCR_PlayVagStm(void *a0 );
static void SCR_CheckPlayVagStm(void *a0 );
static void SCR_FadeInScreen(void *a0 );
static void SCR_FadeOutScreen(void *a0 );
static void SCR_FadeOutInScreen(void *a0 );
static void SCR_FadeOutSceneLoad(void *a0 );
extern u32 SCR_SetObjPointLightOn();
static void SCR_SetObjPointLightOff(void *a0 );
static void SCR_SetObjMovePathDirect(void *a0 );
static void SCR_CheckObjMovePath(void *a0 );
static void SCR_SetObjTalkStart(void *a0 );
static void SCR_SetObjTalkEnd(void *a0 );
static void SCR_SetCaveFaceStart(void *a0 );
static void SCR_FreeObjMovePath(void *a0 );
static void SCR_SetObjFollowMe(void *a0 );
static void SCR_FreeObjFollowMode(void *a0 );
static void SCR_SetObjPointLightOn_Ex(void *a0 );
static void SCR_SetObjPointLightOff_Ex(void *a0 );
static void SCR_SetObjTalkStart2(void *a0 );
extern u32 SCR_SetSe3DUsePoint();
extern u32 SCR_SetSe3DUseModel();
static void SCR_SetSugorokuFlag(void *a0 );
static void SCR_SetMovieLoad(void *a0 );
static void SCR_CheckItemMenuOpen(void *a0 );
static void SCR_SetPadVib(void *a0 );
extern u32 fsScr_ScriptProc(void);
extern void MemFree();
extern u32 gpScrBuf;
extern signed int fsScr_ScriptInit(unsigned char *, signed int);
extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);
void SetScriptDirect(void);
void ClearEventFlag();
u8 * SetEventFlag8(s32 a0 /* r4 */, s32 a1 /* r5 */);
u8 CheckEventFlag8(s32 a0 /* r4 */);
void ResetEventFlag(signed int a0 /* r4 */);
void SetEventFlag(signed int a0 /* r4 */);
signed int CheckEventFlag(signed int a0 /* r4 */);
static void SCR_DebugPrint(u32 *a0 /* r4 */);
static void SCR_CheckMenuTD(void *a0 /* r4 */);
static void SCR_SetPadVib(void *a0 /* r4 */);
static void SCR_CheckItemMenuOpen(void *a0 /* r4 */);
static void SCR_GetGameLevel(u32 *a0 /* r4 */);
static void SCR_SetMenuTD(u32 *a0 /* r4 */);
static void SCR_SetScriptHeartBeat(u8 *a0 /* r4 */);
static void SCR_SetMovieLoad(void *a0 /* r4 */);
static void SCR_SetFrontEndDraw(u32 *a0 /* r4 */);
static void SCR_SetSceneLoad(u8 *a0 /* r4 */);
static void SCR_SetSugorokuFlag(void *a0 /* r4 */);
static void SCR_GetRiddleResult(void *a0 /* r4 */);
static void SCR_SetRiddle(u32 *a0 /* r4 */);
static void SCR_SetEventMassSpiderEnd(u32 *a0 /* r4 */);
static void SCR_SetEventMassSpiderStartCorpse(u32 *a0 /* r4 */);
static void SCR_SetEventMassSpiderStartRoom(u32 *a0 /* r4 */);
static void SCR_StopSe(u32 *a0 /* r4 */);
static void SCR_SetSe2D(void *a0 /* r4 */);
static void SCR_SetObjPointLightOff_Ex(void *a0 /* r4 */);
static void SCR_SetObjPointLightOn_Ex(void *a0 /* r4 */);
static void SCR_FreeObjFollowMode(void *a0 /* r4 */);
static void SCR_SetObjFollowMe(void *a0 /* r4 */);
static void SCR_SetCaveFaceStart(void *a0 /* r4 */);
static void SCR_SetObjTalkEnd(void *a0 /* r4 */);
static void SCR_SetObjTalkStart2(void *a0 /* r4 */);
static void SCR_SetObjTalkStart(void *a0 /* r4 */);
static void SCR_CheckObjMovePath(void *a0 /* r4 */);
static void SCR_FreeObjMovePath(void *a0 /* r4 */);
static void SCR_SetObjMovePathDirect(void *a0 /* r4 */);
static void SCR_SetObjPointLightOff(void *a0 /* r4 */);
static void SCR_FadeOutSceneLoad(void *a0 /* r4 */);
static void SCR_FadeOutInScreen(void *a0 /* r4 */);
static void SCR_FadeOutScreen(void *a0 /* r4 */);
static void SCR_FadeInScreen(void *a0 /* r4 */);
static void SCR_CheckPlayVagStm(void *a0 /* r4 */);
static void SCR_FadeOutVagStm(u8 *a0 /* r4 */);
static void SCR_StopVagStm(u8 *a0 /* r4 */);
static void SCR_PlayVagStm(void *a0 /* r4 */);
static void SCR_SfxIdol(u8 *a0 /* r4 */);
static void SCR_SetBugColor(u8 *a0 /* r4 */);
static void SCR_GenerateBugs(void *a0 /* r4 */);
static void SCR_GenerateSfx(void *a0 /* r4 */);
static void SCR_SetMapSfxErase(void *a0 /* r4 */);
static void SCR_AddItemNum(u8 *a0 /* r4 */);
static void SCR_GetItemNum(void *a0 /* r4 */);
static void SCR_GetItem2(u32 *a0 /* r4 */);
static void SCR_GetItem(u32 *a0 /* r4 */);
static void SCR_CheckPeepManual(void *a0 /* r4 */);
static void SCR_StopPeepCamera(u32 *a0 /* r4 */);
static void SCR_SetPeepCamera(u32 *a0 /* r4 */);
static void SCR_SetScreenDizzy(u32 *a0 /* r4 */);
static void SCR_SetScreenSway(void *a0 /* r4 */);
static void SCR_SetLoadCamReserve(u8 *a0 /* r4 */);
static void SCR_SetCamPathDirect(u32 *a0 /* r4 */);
static void SCR_SetCamModeFreeTarget(u32 *a0 /* r4 */);
static void SCR_GetNowCamIndex(void *a0 /* r4 */);
static void SCR_SetCamModePath(u32 *a0 /* r4 */);
static void SCR_CheckDrama(void *a0 /* r4 */);
static void SCR_StartDrama(void *a0 /* r4 */);
static void SCR_SendMessageVoiceWithMdlAnim(void *a0 /* r4 */);
static void SCR_SendMessageVoice(void *a0 /* r4 */);
static void SCR_SendMessageWithMdlAnim(void *a0 /* r4 */);
static void SCR_GetMessageSelectId(void *a0 /* r4 */);
static void SCR_CheckMessage(void *a0 /* r4 */);
static void SCR_SendMessage(void *a0 /* r4 */);
static void SCR_SetMyNormalMode(u32 *a0 /* r4 */);
static void SCR_SetMyMukade(u32 *a0 /* r4 */);
static void SCR_SetMyTotter(u32 *a0 /* r4 */);
static void SCR_SetMyCrouch(u32 *a0 /* r4 */);
static void SCR_SetMyEquip(u32 *a0 /* r4 */);
static void SCR_AddMySpiritNum(u32 *a0 /* r4 */);
static void SCR_MyControlOn(void *a0 /* r4 */);
static void SCR_MyControlOff(void *a0 /* r4 */);
static void SCR_CheckEneRebirth(void *a0 /* r4 */);
static void SCR_SetEneHpRate(void *a0 /* r4 */);
static u32 SCR_SetEneStop(u32 *a0 /* r4 */);
static void SCR_SetEneOutLogic(void *a0 /* r4 */);
static void SCR_EneAppearOutLogic(void *a0 /* r4 */);
static void SCR_CheckEneDead(void *a0 /* r4 */);
static void SCR_EneAppear(void *a0 /* r4 */);
static void SCR_StabilizeModelCloth(void *a0 /* r4 */);
static void SCR_CheckModelUse(void *a0 /* r4 */);
static void SCR_GetModelPos(void *a0 /* r4 */);
static void SCR_SetModelFade(void *a0 /* r4 */);
static void SCR_SetModelErase(void *a0 /* r4 */);
static void SCR_SetModelHitOff(void *a0 /* r4 */);
static void SCR_DeleteModel(void *a0 /* r4 */);
static void SCR_SetAnimLastFrame(void *a0 /* r4 */);
static void SCR_ChangeAnimation(void *a0 /* r4 */);
static void SCR_SetGoToEnding(u32 *a0 /* r4 */);
static void SCR_SetGoToTitle(u32 *a0 /* r4 */);
static u8 * SCR_SetEventFlag8(u8 *a0 /* r4 */);
static void SCR_GetEventFlag8(void *a0 /* r4 */);
static void SCR_GetEventFlag(void *a0 /* r4 */);
static void SetScriptFunction(void);
void ScriptProc(void);
void FreeScript(void);
signed int SetScript(signed int a0 /* r4 */, void *a1 /* r5 */);
signed int InitScript(unsigned char *a0 /* r4 */);

/* InitScript @ 0x16F2B0 .. 0x16F2EC (0x3c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   a0 forwarded to FileRead
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int InitScript(unsigned char *a0 /* r4 */) {
    s32 a1;
    s32 t0;
    s32 t1;

    a1 = -1;
    t0 = a1;
    t1 = 0x12;
    *(u8 *)((u8 *)&GameSt + 0xd) = 0;
    FileRead((char *)a0, a1, (unsigned char **)&gpScrBuf, 0, t0, t1, 0);
    return (s32)1;
}







/* SetScript @ 0x16F240 .. 0x16F2A4 (0x64 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int SetScript(signed int a0 /* r4 */, void *a1 /* r5 */) {
    u32 v0;

    v0 = (s32)a0;
    a0 = (signed int)a1;
    a1 = (void *)(s32)v0;
    v0 = fsScr_ScriptInit((unsigned char *)a0, (signed int)a1);
    if (v0 == 0) {
        v0 = 0;
    } else {
        SetScriptFunction();
        a0 = (s32)0x7fff;
        v0 = fsScr_ScriptStart(a0);
        if ((s32)v0 <= 0) {
            v0 = 0;
        } else {
            v0 = 1;
            *(u8 *)((u8 *)&GameSt + 0xd) = v0;
        }
    }
    return v0;
}


/* FreeScript @ 0x16F200 .. 0x16F234 (0x34 bytes, frame 0x10) */


void FreeScript(void) {
    u32 a0;

    a0 = gpScrBuf;
    *(u8 *)((u8 *)&GameSt + 0xd) = 0;
    if (a0 != 0) {
        MemFree(a0);
        gpScrBuf = 0;
    }
    return;
}






/* ScriptProc @ 0x16F1C0 .. 0x16F1FC (0x3c bytes, frame 0x10) */


void ScriptProc(void) {
    u8 v1;

    v1 = *(u8 *)((u8 *)&GameSt + 0xf);
    if (v1 == 0) {
        v1 = *(u8 *)((u8 *)&GameSt + 0xd);
        if (v1 != 0) {
            fsScr_ScriptProc();
        }
    }
    return;
}






/* SetScriptFunction @ 0x16EAC0 .. 0x16F1B4 (0x6f4 bytes, frame 0x10) */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */
/* r4 */


static void SetScriptFunction(void) {
    s32 a0;
    u8 *a1;

    a0 = 0xa;
    a1 = (u8 *)SCR_GetEventFlag;
    fsScr_SetScrFunc(a0, SCR_GetEventFlag);
    a0 = 0xb;
    a1 = (u8 *)SCR_SetEventFlag;
    fsScr_SetScrFunc(a0, SCR_SetEventFlag);
    a0 = 0xc;
    a1 = (u8 *)SCR_GetEventFlag8;
    fsScr_SetScrFunc(a0, SCR_GetEventFlag8);
    a0 = 0xd;
    a1 = (u8 *)SCR_SetEventFlag8;
    fsScr_SetScrFunc(a0, SCR_SetEventFlag8);
    a0 = 0xf;
    a1 = (u8 *)SCR_SetGoToTitle;
    fsScr_SetScrFunc(a0, SCR_SetGoToTitle);
    a0 = 0x10;
    a1 = (u8 *)SCR_SetGoToEnding;
    fsScr_SetScrFunc(a0, SCR_SetGoToEnding);
    a0 = 0x14;
    a1 = (u8 *)SCR_CheckEnterCircle;
    fsScr_SetScrFunc(a0, SCR_CheckEnterCircle);
    a0 = 0x15;
    a1 = (u8 *)SCR_CheckEnterRectangle;
    fsScr_SetScrFunc(a0, SCR_CheckEnterRectangle);
    a0 = 0x16;
    a1 = (u8 *)SCR_CheckEnterRectangleByCtrlId;
    fsScr_SetScrFunc(a0, SCR_CheckEnterRectangleByCtrlId);
    a0 = 0x1e;
    a1 = (u8 *)SCR_ChangeAnimation;
    fsScr_SetScrFunc(a0, SCR_ChangeAnimation);
    a0 = 0x1f;
    a1 = (u8 *)SCR_SetAnimLastFrame;
    fsScr_SetScrFunc(a0, SCR_SetAnimLastFrame);
    a0 = 0x28;
    a1 = (u8 *)SCR_DeleteModel;
    fsScr_SetScrFunc(a0, SCR_DeleteModel);
    a0 = 0x29;
    a1 = (u8 *)SCR_SetModelHitOff;
    fsScr_SetScrFunc(a0, SCR_SetModelHitOff);
    a0 = 0x2a;
    a1 = (u8 *)SCR_SetModelErase;
    fsScr_SetScrFunc(a0, SCR_SetModelErase);
    a0 = 0x2b;
    a1 = (u8 *)SCR_SetModelFade;
    fsScr_SetScrFunc(a0, SCR_SetModelFade);
    a0 = 0x2c;
    a1 = (u8 *)SCR_SetModelPlace;
    fsScr_SetScrFunc(a0, SCR_SetModelPlace);
    a0 = 0x2d;
    a1 = (u8 *)SCR_GetModelPos;
    fsScr_SetScrFunc(a0, SCR_GetModelPos);
    a0 = 0x2e;
    a1 = (u8 *)SCR_CheckModelUse;
    fsScr_SetScrFunc(a0, SCR_CheckModelUse);
    a0 = 0x2f;
    a1 = (u8 *)SCR_StabilizeModelCloth;
    fsScr_SetScrFunc(a0, SCR_StabilizeModelCloth);
    a0 = 0x32;
    a1 = (u8 *)SCR_EneAppear;
    fsScr_SetScrFunc(a0, SCR_EneAppear);
    a0 = 0x33;
    a1 = (u8 *)SCR_CheckEneDead;
    fsScr_SetScrFunc(a0, SCR_CheckEneDead);
    a0 = 0x34;
    a1 = (u8 *)SCR_EneAppearOutLogic;
    fsScr_SetScrFunc(a0, SCR_EneAppearOutLogic);
    a0 = 0x35;
    a1 = (u8 *)SCR_SetEneInLogic;
    fsScr_SetScrFunc(a0, SCR_SetEneInLogic);
    a0 = 0x36;
    a1 = (u8 *)SCR_SetEneStop;
    fsScr_SetScrFunc(a0, SCR_SetEneStop);
    a0 = 0x37;
    a1 = (u8 *)SCR_SetEneDisableSearch;
    fsScr_SetScrFunc(a0, SCR_SetEneDisableSearch);
    a0 = 0x38;
    a1 = (u8 *)SCR_SetEneOutLogic;
    fsScr_SetScrFunc(a0, SCR_SetEneOutLogic);
    a0 = 0x39;
    a1 = (u8 *)SCR_SetEneHpRate;
    fsScr_SetScrFunc(a0, SCR_SetEneHpRate);
    a0 = 0x3a;
    a1 = (u8 *)SCR_SetEneRebirthTimes;
    fsScr_SetScrFunc(a0, SCR_SetEneRebirthTimes);
    a0 = 0x3b;
    a1 = (u8 *)SCR_CheckEneRebirth;
    fsScr_SetScrFunc(a0, SCR_CheckEneRebirth);
    a0 = 0x46;
    a1 = (u8 *)SCR_MyControlOff;
    fsScr_SetScrFunc(a0, SCR_MyControlOff);
    a0 = 0x47;
    a1 = (u8 *)SCR_MyControlOn;
    fsScr_SetScrFunc(a0, SCR_MyControlOn);
    a0 = 0x48;
    a1 = (u8 *)SCR_SetMyPlace;
    fsScr_SetScrFunc(a0, SCR_SetMyPlace);
    a0 = 0x49;
    a1 = (u8 *)SCR_AddMySpiritNum;
    fsScr_SetScrFunc(a0, SCR_AddMySpiritNum);
    a0 = 0x4a;
    a1 = (u8 *)SCR_SetMyEquip;
    fsScr_SetScrFunc(a0, SCR_SetMyEquip);
    a0 = 0x4b;
    a1 = (u8 *)SCR_SetMyCrouch;
    fsScr_SetScrFunc(a0, SCR_SetMyCrouch);
    a0 = 0x4c;
    a1 = (u8 *)SCR_SetMyTotter;
    fsScr_SetScrFunc(a0, SCR_SetMyTotter);
    a0 = 0x4d;
    a1 = (u8 *)SCR_SetMyMukade;
    fsScr_SetScrFunc(a0, SCR_SetMyMukade);
    a0 = 0x4e;
    a1 = (u8 *)SCR_SetMyNormalMode;
    fsScr_SetScrFunc(a0, SCR_SetMyNormalMode);
    a0 = 0x64;
    a1 = (u8 *)SCR_SendMessage;
    fsScr_SetScrFunc(a0, SCR_SendMessage);
    a0 = 0x65;
    a1 = (u8 *)SCR_CheckMessage;
    fsScr_SetScrFunc(a0, SCR_CheckMessage);
    a0 = 0x66;
    a1 = (u8 *)SCR_GetMessageSelectId;
    fsScr_SetScrFunc(a0, SCR_GetMessageSelectId);
    a0 = 0x67;
    a1 = (u8 *)SCR_SendMessageWithMdlAnim;
    fsScr_SetScrFunc(a0, SCR_SendMessageWithMdlAnim);
    a0 = 0x68;
    a1 = (u8 *)SCR_SendMessageVoice;
    fsScr_SetScrFunc(a0, SCR_SendMessageVoice);
    a0 = 0x69;
    a1 = (u8 *)SCR_SendMessageVoiceWithMdlAnim;
    fsScr_SetScrFunc(a0, SCR_SendMessageVoiceWithMdlAnim);
    a0 = 0x6e;
    a1 = (u8 *)SCR_StartDrama;
    fsScr_SetScrFunc(a0, SCR_StartDrama);
    a0 = 0x6f;
    a1 = (u8 *)SCR_CheckDrama;
    fsScr_SetScrFunc(a0, SCR_CheckDrama);
    a0 = 0x96;
    a1 = (u8 *)SCR_SetCamModePath;
    fsScr_SetScrFunc(a0, SCR_SetCamModePath);
    a0 = 0x97;
    a1 = (u8 *)SCR_SetCamModeFree;
    fsScr_SetScrFunc(a0, SCR_SetCamModeFree);
    a0 = 0x98;
    a1 = (u8 *)SCR_GetNowCamIndex;
    fsScr_SetScrFunc(a0, SCR_GetNowCamIndex);
    a0 = 0x99;
    a1 = (u8 *)SCR_SetCamModeFreeTarget;
    fsScr_SetScrFunc(a0, SCR_SetCamModeFreeTarget);
    a0 = 0x9a;
    a1 = (u8 *)SCR_SetCamPathDirect;
    fsScr_SetScrFunc(a0, SCR_SetCamPathDirect);
    a0 = 0x9b;
    a1 = (u8 *)SCR_SetLoadCamReserve;
    fsScr_SetScrFunc(a0, SCR_SetLoadCamReserve);
    a0 = 0xa0;
    a1 = (u8 *)SCR_SetPhantomBlast;
    fsScr_SetScrFunc(a0, SCR_SetPhantomBlast);
    a0 = 0xa1;
    a1 = (u8 *)SCR_SetScreenSway;
    fsScr_SetScrFunc(a0, SCR_SetScreenSway);
    a0 = 0xa2;
    a1 = (u8 *)SCR_SetScreenDizzy;
    fsScr_SetScrFunc(a0, SCR_SetScreenDizzy);
    a0 = 0xaa;
    a1 = (u8 *)SCR_SetPeepCamera;
    fsScr_SetScrFunc(a0, SCR_SetPeepCamera);
    a0 = 0xab;
    a1 = (u8 *)SCR_StopPeepCamera;
    fsScr_SetScrFunc(a0, SCR_StopPeepCamera);
    a0 = 0xac;
    a1 = (u8 *)SCR_CheckPeepManual;
    fsScr_SetScrFunc(a0, SCR_CheckPeepManual);
    a0 = 0xb4;
    a1 = (u8 *)SCR_GetItem;
    fsScr_SetScrFunc(a0, SCR_GetItem);
    a0 = 0xb5;
    a1 = (u8 *)SCR_GetItemNum;
    fsScr_SetScrFunc(a0, SCR_GetItemNum);
    a0 = 0xb6;
    a1 = (u8 *)SCR_AddItemNum;
    fsScr_SetScrFunc(a0, SCR_AddItemNum);
    a0 = 0xb7;
    a1 = (u8 *)SCR_GetItem2;
    fsScr_SetScrFunc(a0, SCR_GetItem2);
    a0 = 0xbe;
    a1 = (u8 *)SCR_SetMapSfxErase;
    fsScr_SetScrFunc(a0, SCR_SetMapSfxErase);
    a0 = 0xbf;
    a1 = (u8 *)SCR_GenerateSfx;
    fsScr_SetScrFunc(a0, SCR_GenerateSfx);
    a0 = 0xc0;
    a1 = (u8 *)SCR_GenerateBugs;
    fsScr_SetScrFunc(a0, SCR_GenerateBugs);
    a0 = 0xc1;
    a1 = (u8 *)SCR_SetBugColor;
    fsScr_SetScrFunc(a0, SCR_SetBugColor);
    a0 = 0xc2;
    a1 = (u8 *)SCR_SfxIdol;
    fsScr_SetScrFunc(a0, SCR_SfxIdol);
    a0 = 0xc8;
    a1 = (u8 *)SCR_PlayVagStm;
    fsScr_SetScrFunc(a0, SCR_PlayVagStm);
    a0 = 0xc9;
    a1 = (u8 *)SCR_StopVagStm;
    fsScr_SetScrFunc(a0, SCR_StopVagStm);
    a0 = 0xca;
    a1 = (u8 *)SCR_FadeOutVagStm;
    fsScr_SetScrFunc(a0, SCR_FadeOutVagStm);
    a0 = 0xcb;
    a1 = (u8 *)SCR_CheckPlayVagStm;
    fsScr_SetScrFunc(a0, SCR_CheckPlayVagStm);
    a0 = 0xd2;
    a1 = (u8 *)SCR_FadeInScreen;
    fsScr_SetScrFunc(a0, SCR_FadeInScreen);
    a0 = 0xd3;
    a1 = (u8 *)SCR_FadeOutScreen;
    fsScr_SetScrFunc(a0, SCR_FadeOutScreen);
    a0 = 0xd4;
    a1 = (u8 *)SCR_FadeOutInScreen;
    fsScr_SetScrFunc(a0, SCR_FadeOutInScreen);
    a0 = 0xd5;
    a1 = (u8 *)SCR_FadeOutSceneLoad;
    fsScr_SetScrFunc(a0, SCR_FadeOutSceneLoad);
    a0 = 0xfa;
    a1 = (u8 *)SCR_SetObjPointLightOn;
    fsScr_SetScrFunc(a0, SCR_SetObjPointLightOn);
    a0 = 0xfb;
    a1 = (u8 *)SCR_SetObjPointLightOff;
    fsScr_SetScrFunc(a0, SCR_SetObjPointLightOff);
    a0 = 0xfc;
    a1 = (u8 *)SCR_SetObjMovePathDirect;
    fsScr_SetScrFunc(a0, SCR_SetObjMovePathDirect);
    a0 = 0xfd;
    a1 = (u8 *)SCR_CheckObjMovePath;
    fsScr_SetScrFunc(a0, SCR_CheckObjMovePath);
    a0 = 0xfe;
    a1 = (u8 *)SCR_SetObjTalkStart;
    fsScr_SetScrFunc(a0, SCR_SetObjTalkStart);
    a0 = 0xff;
    a1 = (u8 *)SCR_SetObjTalkEnd;
    fsScr_SetScrFunc(a0, SCR_SetObjTalkEnd);
    a0 = 0x100;
    a1 = (u8 *)SCR_SetCaveFaceStart;
    fsScr_SetScrFunc(a0, SCR_SetCaveFaceStart);
    a0 = 0x101;
    a1 = (u8 *)SCR_FreeObjMovePath;
    fsScr_SetScrFunc(a0, SCR_FreeObjMovePath);
    a0 = 0x102;
    a1 = (u8 *)SCR_SetObjFollowMe;
    fsScr_SetScrFunc(a0, SCR_SetObjFollowMe);
    a0 = 0x103;
    a1 = (u8 *)SCR_FreeObjFollowMode;
    fsScr_SetScrFunc(a0, SCR_FreeObjFollowMode);
    a0 = 0x104;
    a1 = (u8 *)SCR_SetObjPointLightOn_Ex;
    fsScr_SetScrFunc(a0, SCR_SetObjPointLightOn_Ex);
    a0 = 0x105;
    a1 = (u8 *)SCR_SetObjPointLightOff_Ex;
    fsScr_SetScrFunc(a0, SCR_SetObjPointLightOff_Ex);
    a0 = 0x106;
    a1 = (u8 *)SCR_SetObjTalkStart2;
    fsScr_SetScrFunc(a0, SCR_SetObjTalkStart2);
    a0 = 0x122;
    a1 = (u8 *)SCR_SetSe2D;
    fsScr_SetScrFunc(a0, SCR_SetSe2D);
    a0 = 0x123;
    a1 = (u8 *)SCR_SetSe3DUsePoint;
    fsScr_SetScrFunc(a0, SCR_SetSe3DUsePoint);
    a0 = 0x124;
    a1 = (u8 *)SCR_SetSe3DUseModel;
    fsScr_SetScrFunc(a0, SCR_SetSe3DUseModel);
    a0 = 0x125;
    a1 = (u8 *)SCR_StopSe;
    fsScr_SetScrFunc(a0, SCR_StopSe);
    a0 = 0x12c;
    a1 = (u8 *)SCR_SetEventMassSpiderStartRoom;
    fsScr_SetScrFunc(a0, SCR_SetEventMassSpiderStartRoom);
    a0 = 0x12d;
    a1 = (u8 *)SCR_SetEventMassSpiderStartCorpse;
    fsScr_SetScrFunc(a0, SCR_SetEventMassSpiderStartCorpse);
    a0 = 0x12e;
    a1 = (u8 *)SCR_SetEventMassSpiderEnd;
    fsScr_SetScrFunc(a0, SCR_SetEventMassSpiderEnd);
    a0 = 0x15e;
    a1 = (u8 *)SCR_SetRiddle;
    fsScr_SetScrFunc(a0, SCR_SetRiddle);
    a0 = 0x15f;
    a1 = (u8 *)SCR_GetRiddleResult;
    fsScr_SetScrFunc(a0, SCR_GetRiddleResult);
    a0 = 0x17c;
    a1 = (u8 *)SCR_SetSugorokuFlag;
    fsScr_SetScrFunc(a0, SCR_SetSugorokuFlag);
    a0 = 0x186;
    a1 = (u8 *)SCR_SetSceneLoad;
    fsScr_SetScrFunc(a0, SCR_SetSceneLoad);
    a0 = 0x187;
    a1 = (u8 *)SCR_SetFrontEndDraw;
    fsScr_SetScrFunc(a0, SCR_SetFrontEndDraw);
    a0 = 0x188;
    a1 = (u8 *)SCR_SetMovieLoad;
    fsScr_SetScrFunc(a0, SCR_SetMovieLoad);
    a0 = 0x189;
    a1 = (u8 *)SCR_SetScriptHeartBeat;
    fsScr_SetScrFunc(a0, SCR_SetScriptHeartBeat);
    a0 = 0x18a;
    a1 = (u8 *)SCR_SetMenuTD;
    fsScr_SetScrFunc(a0, SCR_SetMenuTD);
    a0 = 0x18b;
    a1 = (u8 *)SCR_GetGameLevel;
    fsScr_SetScrFunc(a0, SCR_GetGameLevel);
    a0 = 0x18c;
    a1 = (u8 *)SCR_CheckItemMenuOpen;
    fsScr_SetScrFunc(a0, SCR_CheckItemMenuOpen);
    a0 = 0x18d;
    a1 = (u8 *)SCR_SetPadVib;
    fsScr_SetScrFunc(a0, SCR_SetPadVib);
    a0 = 0x18e;
    a1 = (u8 *)SCR_CheckMenuTD;
    fsScr_SetScrFunc(a0, SCR_CheckMenuTD);
    a0 = 0x18f;
    a1 = (u8 *)SCR_DebugPrint;
    fsScr_SetScrFunc(a0, SCR_DebugPrint);
    a1 = GameSt;
    fsScr_SetGameVal(0, (void *)GameSt);
    a0 = 1;
    a1 = (u8 *)GameEventFlag;
    fsScr_SetGameVal(a0, (void *)GameEventFlag);
    return;
}


/* SCR_GetEventFlag @ 0x16EA40 .. 0x16EAB4 (0x74 bytes, frame 0x20) */




static void SCR_GetEventFlag(void *a0 /* r4 */) {
    u32 *s0;
    s32 a1;
    u32 v1;
    u32 v0;

    v1 = *(s32 *)(((u8 *)a0 + 8));
    s0 = (u32 *)a0;
    a1 = (s32)(u32)v1 / (s32)(8);
    a0 = (void *)((s32)v1 % (s32)(8));
    v1 = 1;
    v0 = (u32)GameEventFlag;
    v1 = v1 << (u32)a0;
    v0 = (s32)((u8 *)GameEventFlag + a1);
    a0 = (void *)((u8 *)s0 + 0xc);
    v0 = *(u8 *)v0;
    a1 = (u32)(v0 & v1) != 0;
    fsScr_SetPointerData(a0, a1);
    *(u32 *)s0 = 0;
    return;
}




u32 SCR_SetEventFlag(u32 *ss) {
    int Flag;
    int Index;

    Flag = ss[2];
    Index = Flag / 8;
    Flag = 1 << (Flag % 8);
    if (ss[4] != 0) {
        GameEventFlag[Index] |= Flag;
    } else {
        GameEventFlag[Index] &= ~Flag;
    }
    ss[0] = 0;
}


/* SCR_GetEventFlag8 @ 0x16E970 .. 0x16E9C0 (0x50 bytes, frame 0x20) */



static void SCR_GetEventFlag8(void *a0 /* r4 */) {
    u32 *s0;
    u32 v0;
    s32 v1;

    v0 = *(s32 *)(((u8 *)a0 + 8));
    s0 = (u32 *)a0;
    v1 = (s32)v0 / (s32)(8);
    v0 = (u32)GameEventFlag;
    fsScr_SetPointerData((u32 *)((u8 *)s0 + 0xc), (u32)*(u8 *)(u32)(s32)((u8 *)GameEventFlag + v1));
    *(u32 *)s0 = 0;
    return;
}


/* SCR_SetEventFlag8 @ 0x16E940 .. 0x16E970 (0x30 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


static u8 * SCR_SetEventFlag8(u8 *a0 /* r4 */) {
    u32 v1;
    u8 a2;
    s32 a1;

    v1 = *(u32 *)(((u8 *)a0 + 8));
    a2 = *(u8 *)(((u8 *)a0 + 0x10));
    a1 = (s32)v1 >> 3;
    if ((s32)v1 < 0) {
        v1 = v1 + 7;
        a1 = (s32)v1 >> 3;
    }
    v1 = (u32)GameEventFlag;
    v1 = (u32)((u8 *)GameEventFlag + a1);
    *(u8 *)v1 = a2;
    *(u32 *)a0 = 0;
    return;
}






/* SCR_SetGoToTitle @ 0x16E910 .. 0x16E938 (0x28 bytes, frame 0x20) */


static void SCR_SetGoToTitle(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    SetGoToTitleFade();
    *(u32 *)s0 = 0;
    return;
}







/* SCR_SetGoToEnding @ 0x16E8E0 .. 0x16E908 (0x28 bytes, frame 0x20) */


static void SCR_SetGoToEnding(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    SetGoToEndingFade();
    *(u32 *)s0 = 0;
    return;
}






u32 SCR_CheckEnterCircle(u8 *script) {
    u8 *saved;
    u32 model;
    u8 *begin;
    u8 *end;
    float x, z, radius;
    x = *(float *)(script + 0x10);
    z = *(float *)(script + 0x18);
    radius = *(float *)(script + 0x20);
    saved = script;
    switch (*(u32 *)(script + 8)) {
    case 0: begin = MdlMng + 0x11800; end = MdlMng + 0x119c0; break;
    case 1: begin = MdlMng + 0x119c0; end = MdlMng + 0x17140; break;
    case 2: begin = MdlMng + 0x17140; end = MdlMng + 0x17f40; break;
    case 4: begin = MdlMng + 0x5400; end = MdlMng + 0xfc00; break;
    case 10: begin = MdlMng + 0xfc00; end = MdlMng + 0x11800; break;
    default:
        fsScr_SetPointerData(saved + 0x24, -1);
        *(u32 *)saved = 0;
        return;
    }
    for (model = (u32)begin; (u8 *)model < end; model += 0x1c0) {
        if (*(u8 *)model != 0) {
            float dx = *(float *)(model + 0x20) - x;
            float dz = *(float *)(model + 0x28) - z;
            float range = *(float *)(model + 0x110) + radius;
            if (dx * dx + dz * dz < range * range) {
                fsScr_SetPointerData(saved + 0x24, (s32)((u32)model - (u32)begin) / 0x1c0);
                *(u32 *)saved = 0;
                return;
            }
        }
    }
    fsScr_SetPointerData(saved + 0x24, -1);
    *(u32 *)saved = 0;
    return;
}







u32 SCR_CheckEnterRectangle(u8 *ss) {
    u8 *lpMdlMng;
    u8 *lpStart;
    u8 *lpEnd;
    float MinX;
    float MinZ;
    float MaxX;
    float MaxZ;

    MinX = *(float *)(ss + 0x10);
    MaxX = *(float *)(ss + 0x20);
    MinZ = *(float *)(ss + 0x18);
    MaxZ = *(float *)(ss + 0x28);
    if (MinX > MaxX) {
        MinX = MaxX;
        MaxX = *(float *)(ss + 0x10);
    }
    if (MinZ > MaxZ) {
        MinZ = MaxZ;
        MaxZ = *(float *)(ss + 0x18);
    }
    switch (*(s32 *)(ss + 8)) {
    case 0:
        lpStart = (u8 *)(MdlMng + 0x11800);
        lpEnd = (u8 *)(MdlMng + 0x119c0);
        break;
    case 1:
        lpStart = (u8 *)(MdlMng + 0x119c0);
        lpEnd = (u8 *)(MdlMng + 0x17140);
        break;
    case 2:
        lpStart = (u8 *)(MdlMng + 0x17140);
        lpEnd = (u8 *)(MdlMng + 0x17f40);
        break;
    case 4:
        lpStart = (u8 *)(MdlMng + 0x5400);
        lpEnd = (u8 *)(MdlMng + 0xfc00);
        break;
    case 10:
        lpStart = (u8 *)(MdlMng + 0xfc00);
        lpEnd = (u8 *)(MdlMng + 0x11800);
        break;
    default:
        fsScr_SetPointerData((void *)(ss + 0x2c), -1);
        *(u32 *)ss = 0;
        return;
    }
    for (lpMdlMng = lpStart; lpMdlMng < lpEnd; lpMdlMng += 0x1c0) {
        if (*lpMdlMng != 0 && *(float *)(lpMdlMng + 0x20) >= MinX && *(float *)(lpMdlMng + 0x20) <= MaxX &&
            *(float *)(lpMdlMng + 0x28) >= MinZ && *(float *)(lpMdlMng + 0x28) <= MaxZ) {
            fsScr_SetPointerData((void *)(ss + 0x2c), (s32)(lpMdlMng - lpStart) / 0x1c0);
            *(u32 *)ss = 0;
            return;
        }
    }
    fsScr_SetPointerData((void *)(ss + 0x2c), -1);
    *(u32 *)ss = 0;
}





u32 SCR_CheckEnterRectangleByCtrlId(u8 *ss) {
    u8 *lpMdlMng;
    float MinX;
    float MinZ;
    float MaxX;
    float MaxZ;

    MinX = *(float *)(ss + 0x10);
    MaxX = *(float *)(ss + 0x20);
    MinZ = *(float *)(ss + 0x18);
    MaxZ = *(float *)(ss + 0x28);
    if (MinX > MaxX) {
        MinX = MaxX;
        MaxX = *(float *)(ss + 0x10);
    }
    if (MinZ > MaxZ) {
        MinZ = MaxZ;
        MaxZ = *(float *)(ss + 0x18);
    }
    lpMdlMng = (u8 *)GetScriptMdlMng(*(s32 *)(ss + 8), *(s32 *)(ss + 0x30), 1);
    if (lpMdlMng == 0) {
        fsScr_SetPointerData((void *)(ss + 0x34), -1);
        *(u32 *)ss = 0;
        return;
    }
    if (*(float *)(lpMdlMng + 0x20) >= MinX && *(float *)(lpMdlMng + 0x20) <= MaxX &&
        *(float *)(lpMdlMng + 0x28) >= MinZ && *(float *)(lpMdlMng + 0x28) <= MaxZ) {
        fsScr_SetPointerData((void *)(ss + 0x34), 0);
        *(u32 *)ss = 0;
        return;
    }
    fsScr_SetPointerData((void *)(ss + 0x34), -1);
    *(u32 *)ss = 0;
}





/* SCR_ChangeAnimation @ 0x16E400 .. 0x16E458 (0x58 bytes, frame 0x20) */


static void SCR_ChangeAnimation(void *a0 /* r4 */) {
    u8 *s0;
    u8 *v0;

    s0 = (u8 *)a0;
    v0 = (u8 *)GetScriptMdlMng(*(s32 *)(((u8 *)a0 + 8)), *(s32 *)(s0 + 0x10), (s32)1);
    a0 = (void *)v0;
    if ((u32)a0 == 0) {
        *(u32 *)s0 = 0;
    } else {
        ChangeAnimParam(a0, *(s32 *)(s0 + 0x18), *(float *)(s0 + 0x20));
        *(u32 *)s0 = 0;
    }
    return;
}







/* SCR_SetAnimLastFrame @ 0x16E3A0 .. 0x16E3F8 (0x58 bytes, frame 0x20) */


static void SCR_SetAnimLastFrame(void *a0 /* r4 */) {
    u8 *s0;
    u8 *v0;

    s0 = (u8 *)a0;
    v0 = (u8 *)GetScriptMdlMng(*(s32 *)(((u8 *)a0 + 8)), *(s32 *)(s0 + 0x10), (s32)1);
    a0 = (void *)v0;
    if ((u32)a0 == 0) {
        *(u32 *)s0 = 0;
    } else {
        SetAnimLastFrame(a0);
        *(u32 *)s0 = 0;
    }
    return;
}





/* SCR_DeleteModel @ 0x16E340 .. 0x16E398 (0x58 bytes, frame 0x20) */


static void SCR_DeleteModel(void *a0 /* r4 */) {
    u8 *s0;
    u8 *v0;

    s0 = (u8 *)a0;
    v0 = (u8 *)GetScriptMdlMng(*(s32 *)(((u8 *)a0 + 8)), *(s32 *)(s0 + 0x10), (s32)1);
    a0 = (void *)v0;
    if ((u32)a0 == 0) {
        *(u32 *)s0 = 0;
    } else {
        FreeMdlMng(a0);
        *(u32 *)s0 = 0;
    }
    return;
}





/* SCR_SetModelHitOff @ 0x16E2F0 .. 0x16E340 (0x50 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */






static void SCR_SetModelHitOff(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u8 *v0;

    s0 = (u8 *)a0;
    v0 = (u8 *)GetScriptMdlMng(*(s32 *)(((u8 *)a0 + 8)), *(s32 *)(s0 + 0x10), (s32)1);
    if ((u32)v0 == 0) {
        *(u32 *)s0 = 0;
    } else {
        v1 = *(s32 *)(s0 + 0x18);
        *(u8 *)(v0 + 0x130) = v1;
        *(u32 *)s0 = 0;
    }
    return;
}


/* SCR_SetModelErase @ 0x16E2A0 .. 0x16E2F0 (0x50 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */






static void SCR_SetModelErase(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u8 *v0;

    s0 = (u8 *)a0;
    v0 = (u8 *)GetScriptMdlMng(*(s32 *)(((u8 *)a0 + 8)), *(s32 *)(s0 + 0x10), (s32)1);
    if ((u32)v0 == 0) {
        *(u32 *)s0 = 0;
    } else {
        v1 = *(s32 *)(s0 + 0x18);
        *(u8 *)(v0 + 2) = v1;
        *(u32 *)s0 = 0;
    }
    return;
}





/* SCR_SetModelFade @ 0x16E210 .. 0x16E294 (0x84 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3c23d70a at 0x16e254
 *   declaration vs inferred signature: return void vs inferred u32
 */


static void SCR_SetModelFade(void *a0 /* r4 */) {
    u8 *s1;
    u8 a0_narrow; // a0
    u8 *s0;
    u32 v0;

    s1 = (u8 *)a0;
    v0 = (u32)GetScriptMdlMng(*(s32 *)(((u8 *)a0 + 8)), *(s32 *)(s1 + 0x10), (s32)1);
    s0 = (u8 *)v0;
    if ((u32)s0 == 0) {
        *(u32 *)s1 = 0;
    } else {
        SetMdlFade((void *)s0, *(u8 *)(s1 + 0x18), 0.00999999978f);
        a0_narrow = *(u8 *)(s0 + 5);
        if ((u32)a0_narrow == (u32)1) {
            *(u32 *)(s0 + 0x10c) = 0;
        }
        *(u32 *)s1 = 0;
    }
    return;
}





#define SCR_REV(a) (6.28318548f * (int)((3.14159274f + (a)) / 6.28318548f))
#define SCR_ADJ(a) ((3.14159274f + (a) >= 0.0f) ? (a) - SCR_REV(a) : 6.28318548f + ((a) - SCR_REV(a)))

u32 SCR_SetModelPlace(void *a0) {
    u8 *s0;
    u32 v0_2;

    s0 = (u8 *)a0;
    v0_2 = (u32)GetScriptMdlMng(*(s32 *)((u8 *)a0 + 8), *(s32 *)(s0 + 0x10), 1);
    a0 = (void *)v0_2;
    if ((u32)a0 == 0) {
        *(u32 *)s0 = 0;
    } else {
        *(f32 *)((u8 *)a0 + 0x20) = *(float *)(s0 + 0x18);
        *(f32 *)((u8 *)a0 + 0x24) = *(float *)(s0 + 0x20);
        *(f32 *)((u8 *)a0 + 0x28) = *(float *)(s0 + 0x28);
        *(f32 *)((u8 *)a0 + 0x34) = SCR_ADJ((0.0174499992f * *(float *)(s0 + 0x30)));
        UpdateWorldMatrixInAnim(a0);
        *(u32 *)s0 = 0;
    }
    return;
}






/* SCR_GetModelPos @ 0x16E080 .. 0x16E11C (0x9c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x16e0b0
 *   fpu: float literal 0x00000000 at 0x16e0bc
 *   fpu: float literal 0x00000000 at 0x16e0c8
 */


static void SCR_GetModelPos(void *a0 /* r4 */) {
    u8 *s1;
    float *v0;
    float *s0;
    float f12;

    s1 = (u8 *)a0;
    v0 = (float *)GetScriptMdlMng(*(s32 *)(((u8 *)a0 + 8)), *(s32 *)(s1 + 0x10), (s32)1);
    s0 = v0;
    if ((u32)s0 == 0) {
        f12 = 0.0f;
        fsScr_SetPointerDataF((void *)(u32)(s32)(s1 + 0x14), 0.0f);
        f12 = 0.0f;
        fsScr_SetPointerDataF((void *)(u32)(s32)(s1 + 0x1c), 0.0f);
        f12 = 0.0f;
        fsScr_SetPointerDataF((void *)(u32)(s32)(s1 + 0x24), 0.0f);
        *(u32 *)s1 = 0;
    } else {
        fsScr_SetPointerDataF((void *)(u32)(s32)(s1 + 0x14), s0[8]);
        fsScr_SetPointerDataF((void *)(u32)(s32)(s1 + 0x1c), s0[9]);
        fsScr_SetPointerDataF((void *)(u32)(s32)(s1 + 0x24), s0[0xa]);
        *(u32 *)s1 = 0;
    }
    return;
}






/* SCR_CheckModelUse @ 0x16E020 .. 0x16E07C (0x5c bytes, frame 0x20) */



static void SCR_CheckModelUse(void *a0 /* r4 */) {
    u8 *s0;
    u8 *v0;

    s0 = (u8 *)a0;
    v0 = (u8 *)GetScriptMdlMng(*(s32 *)(((u8 *)a0 + 8)), *(s32 *)(s0 + 0x10), 0);
    if ((u32)v0 != 0) {
        fsScr_SetPointerData((void *)(s0 + 4), 1);
    } else {
        fsScr_SetPointerData((void *)(s0 + 4), 0);
    }
    *(u32 *)s0 = 0;
    return;
}






/* SCR_StabilizeModelCloth @ 0x16DF90 .. 0x16E014 (0x84 bytes, frame 0x30) */


static void SCR_StabilizeModelCloth(void *a0 /* r4 */) {
    u8 *s1;
    u32 v0;
    u8 *s0;

    s1 = (u8 *)a0;
    v0 = (u32)GetScriptMdlMng(*(s32 *)(((u8 *)a0 + 8)), *(s32 *)(s1 + 0x10), (s32)1);
    s0 = (u8 *)v0;
    if ((u32)s0 == 0) {
        *(u32 *)s1 = 0;
    } else {
        v0 = GetClothDataId((void *)s0);
        a0 = (void *)s0;
        if ((s32)v0 > 0) {
            ReCalcMi3Matrix(a0);
            UpdateWorldMatrixInAnim((void *)s0);
            CsMngStabilize((u32)s0, *(s32 *)(s1 + 0x18));
        }
        *(u32 *)s1 = 0;
    }
    return;
}





/* SCR_EneAppear @ 0x16DEC0 .. 0x16DF88 (0xc8 bytes, frame 0x60) */


static void SCR_EneAppear(void *a0 /* r4 */) {
    u32 a1;
    void *a0_s2; // a0
    u8 *a0_bytes; // s2
    u8 *s1;
    s32 s3;
    u32 v0;
    u32 s0;
    u8 stackFrame[16] __attribute__((aligned(16)));

    a0_bytes = (u8 *)a0;
    v0 = (u32)GetMapPartsInfoByCtrlId((signed int)(void *)(s32)2, *(s32 *)(a0_bytes + 0x10));
    a1 = *(s32 *)(a0_bytes + 0x10);
    s1 = (u8 *)v0;
    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)2, a1);
    s0 = *(s32 *)(a0_bytes + 8);
    a0_s2 = (void *)(s32)(v0 + 0xa1);
    v0 = (u32)MdlMng;
    s3 = (s32)((u8 *)MdlMng + (s32)((u32)(s32)((u8 *)(s32)((u32)a0_s2 << 3) - (u32)(a0_s2)) << 6));
    v0 = GetMdlDataIndexFromMapMdlInfo((signed int)(void *)(s32)2, s0);
    a1 = v0;
    if ((u32)s1 != 0) {
        if (a1 != (u32)-1) {
            EneAppear((signed int)(void *)(s32)s0, a1, (void *)s3, (float *)s1, *(float *)(s1 +
                0x14), (float *)V1, 1, *(u16 *)(a0_bytes + 0x18), 0, (void *)0, (void *)0);
        }
    }
    *(u32 *)a0_bytes = 0;
    return;
}


/* SCR_CheckEneDead @ 0x16DE40 .. 0x16DEBC (0x7c bytes, frame 0x20) */


static void SCR_CheckEneDead(void *a0 /* r4 */) {
    u32 v0;
    void *a0_s0; // a0

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)2, *(s32 *)(((u8 *)a0 + 8)));
    a0_s0 = (void *)(s32)(v0 + 0xa1);
    v0 = (u32)MdlMng;
    v0 = CheckEneDead((void *)((u8 *)MdlMng + (s32)((u32)(s32)((u8 *)(s32)((u32)a0_s0 << 3) -
        (u32)(a0_s0)) << 6)));
    if (v0 != 0) {
        fsScr_SetPointerData((void *)((u8 *)a0 + 0xc), (u32)1);
    } else {
        fsScr_SetPointerData((void *)((u8 *)a0 + 0xc), 0);
    }
    *(u32 *)a0 = 0;
    return;
}


/* SCR_EneAppearOutLogic @ 0x16DD70 .. 0x16DE38 (0xc8 bytes, frame 0x60) */


static void SCR_EneAppearOutLogic(void *a0 /* r4 */) {
    s32 t1;
    u32 a1;
    u8 *a0_bytes; // s2
    u8 *s1;
    s32 s3;
    void *a0_s2; // a0
    u32 v0;
    u32 s0;
    u8 stackFrame[16] __attribute__((aligned(16)));

    a0_bytes = (u8 *)a0;
    v0 = (u32)GetMapPartsInfoByCtrlId((signed int)(void *)(s32)2, *(s32 *)(a0_bytes + 0x10));
    a1 = *(s32 *)(a0_bytes + 0x10);
    s1 = (u8 *)v0;
    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)2, a1);
    s0 = *(s32 *)(a0_bytes + 8);
    a0_s2 = (void *)(s32)(v0 + 0xa1);
    v0 = (u32)MdlMng;
    s3 = (s32)((u8 *)MdlMng + (s32)((u32)(s32)((u8 *)(s32)((u32)a0_s2 << 3) - (u32)(a0_s2)) << 6));
    v0 = GetMdlDataIndexFromMapMdlInfo((signed int)(void *)(s32)2, s0);
    a1 = v0;
    if ((u32)s1 != 0) {
        if (a1 != (u32)-1) {
            t1 = 1;
            EneAppear((signed int)(void *)(s32)s0, a1, (void *)s3, (float *)s1, *(float *)(s1 +
                0x14), (float *)(s1 + 0x20), t1, *(u16 *)(a0_bytes + 0x18), t1, (void *)0, (void
                *)0);
        }
    }
    *(u32 *)a0_bytes = 0;
    return;
}






/* SCR_SetEneInLogic @ 0x16DD10 .. 0x16DD68 (0x58 bytes, frame 0x20) */

static u32 SCR_SetEneInLogic(u32 *a0) {
    u32 a1;
    u32 a0_s0_index; // a0
    u32 a0_s0_index_; // a0
    u8 *v1;
    u32 v0;

    v0 = GetMdlMngIndexByCtrlId((signed int)(u32 *)(s32)2, *(s32 *)(((u8 *)a0 + 8)));
    a1 = v0 + 0xa1;
    a0_s0_index = a1 << 3;
    v1 = MdlMng;
    a0_s0_index_ = a1 * (u32)(7);
    *(u8 *)(((u8 *)*(s32 *)(((u8 *)(s32)((u8 *)MdlMng + (u32)(a1 * (u32)(0x1c0))) + 0x148)) +
        0x182)) = 1;
    *(u32 *)a0 = 0;
    return v0;
}







/* SCR_SetEneOutLogic @ 0x16DCB0 .. 0x16DD0C (0x5c bytes, frame 0x20) */



static void SCR_SetEneOutLogic(void *a0 /* r4 */) {
    u32 a1;
    u8 *a0_s0; // a0
    s32 v1;
    u32 v0;

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)2, *(s32 *)(((u8 *)a0 + 8)));
    a0_s0 = (u8 *)(s32)(v0 + 0xa1);
    v1 = (u32)a0_s0 << 3;
    v1 = (s32)((u8 *)v1 - (u32)(a0_s0));
    v0 = (u32)MdlMng;
    a0_s0 = (u8 *)((u8 *)MdlMng + (s32)((u32)v1 << 6));
    a1 = *(s32 *)(a0_s0 + 0x148);
    ((void (*)(s32, s32, u16))(s32)*(s32 *)((a1 + 0x118)))((s32)a0_s0, a1, *(u16 *)(((u8 *)a0 +
        0x10)));
    *(u32 *)a0 = 0;
    return;
}









/* SCR_SetEneStop @ 0x16DC90 .. 0x16DCA4 (0x14 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


static u32 SCR_SetEneStop(u32 *a0 /* r4 */) {
    u32 v1;

    v1 = *(u32 *)(((u8 *)a0 + 8));
    *(u8 *)((u8 *)&GameSt + 0x10) = v1;
    *(u32 *)a0 = 0;
    return;
}







/* SCR_SetEneDisableSearch @ 0x16DC30 .. 0x16DC88 (0x58 bytes, frame 0x20) */

static u32 SCR_SetEneDisableSearch(u32 *a0) {
    u32 a1;
    u32 a0_s0_index; // a0
    u32 a0_s0_index_; // a0
    u8 *v1;
    u32 v0;

    v0 = GetMdlMngIndexByCtrlId((signed int)(u32 *)(s32)2, *(s32 *)(((u8 *)a0 + 8)));
    a1 = v0 + 0xa1;
    a0_s0_index = a1 << 3;
    v1 = MdlMng;
    a0_s0_index_ = a1 * (u32)(7);
    *(u16 *)(((u8 *)*(s32 *)(((u8 *)(s32)((u8 *)MdlMng + (u32)(a1 * (u32)(0x1c0))) + 0x148)) +
        0x1fc)) = (s32)a0[4];
    *(u32 *)a0 = 0;
    return v0;
}





/* SCR_SetEneHpRate @ 0x16DBC0 .. 0x16DC2C (0x6c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */





static void SCR_SetEneHpRate(void *a0 /* r4 */) {
    u32 a1;
    u8 *a0_s0; // a0
    u8 *v1;
    u32 v0;

    a0_s0 = (u8 *)(s32)2;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0_s0, *(s32 *)(((u8 *)a0 + 8)));
    a1 = v0 + 0xa1;
    a0_s0 = (u8 *)(s32)(a1 << 3);
    v1 = (u8 *)MdlMng;
    a0_s0 = (u8 *)(a0_s0 - a1);
    a0_s0 = (u8 *)(s32)((u32)a0_s0 << 6);
    a0_s0 = (u8 *)((u8 *)MdlMng + (u32)(a0_s0));
    v1 = (u8 *)(s32)((s32)((float)(float)((float)*(s32 *)(a0_s0 + 0x120)) * *(float *)(((u8 *)a0 +
        0x10))));
    *(u32 *)(a0_s0 + 0x120) = (s32)v1;
    *(u32 *)a0 = 0;
    return;
}






/* SCR_SetEneRebirthTimes @ 0x16DB60 .. 0x16DBB8 (0x58 bytes, frame 0x20) */

static u32 SCR_SetEneRebirthTimes(u32 *a0) {
    u32 a1;
    u32 a0_s0_index; // a0
    u32 a0_s0_index_; // a0
    u8 *v1;
    u32 v0;

    v0 = GetMdlMngIndexByCtrlId((signed int)(u32 *)(s32)2, *(s32 *)(((u8 *)a0 + 8)));
    a1 = v0 + 0xa1;
    a0_s0_index = a1 << 3;
    v1 = MdlMng;
    a0_s0_index_ = a1 * (u32)(7);
    *(u8 *)(((u8 *)*(s32 *)(((u8 *)(s32)((u8 *)MdlMng + (u32)(a1 * (u32)(0x1c0))) + 0x148)) +
        0x1d9)) = (s32)a0[4];
    *(u32 *)a0 = 0;
    return v0;
}





/* SCR_CheckEneRebirth @ 0x16DAE0 .. 0x16DB5C (0x7c bytes, frame 0x20) */


static void SCR_CheckEneRebirth(void *a0 /* r4 */) {
    u32 v0;
    void *a0_s0; // a0

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)2, *(s32 *)(((u8 *)a0 + 8)));
    a0_s0 = (void *)(s32)(v0 + 0xa1);
    v0 = (u32)MdlMng;
    v0 = CheckEneRebirth((void *)((u8 *)MdlMng + (s32)((u32)(s32)((u8 *)(s32)((u32)a0_s0 << 3) -
        (u32)(a0_s0)) << 6)));
    if (v0 != 0) {
        fsScr_SetPointerData((void *)((u8 *)a0 + 0xc), (u32)1);
    } else {
        fsScr_SetPointerData((void *)((u8 *)a0 + 0xc), 0);
    }
    *(u32 *)a0 = 0;
    return;
}






/* SCR_MyControlOff @ 0x16DA70 .. 0x16DAD4 (0x64 bytes, frame 0x20) */


static void SCR_MyControlOff(void *a0 /* r4 */) {
    u32 *s0;
    u32 v0;

    s0 = (u32 *)a0;
    a0 = (void *)((u8 *)MdlMng + 0x11800);
    v0 = CheckMyControlOff(a0);
    if (v0 != 0) {
        SetMyControlOff();
        a0 = (void *)(s32)((u8 *)s0 + 4);
        fsScr_SetPointerData(a0, (u32)1);
    } else {
        a0 = (void *)(s32)((u8 *)s0 + 4);
        fsScr_SetPointerData(a0, 0);
    }
    *(u32 *)s0 = 0;
    return;
}


/* SCR_MyControlOn @ 0x16DA20 .. 0x16DA64 (0x44 bytes, frame 0x20) */


static void SCR_MyControlOn(void *a0 /* r4 */) {
    u32 *s0;
    u32 v0;

    s0 = (u32 *)a0;
    SetMyControlOn();
    v0 = Msg_GetDizzyOffFlag();
    a0 = (void *)(s32)1;
    if (v0 != 0) {
        SetMyDizzy((signed int)a0);
    }
    *(u32 *)s0 = 0;
    return;
}


extern u32 StabilizeMyCloth();
#define REV(a) (6.28318548f * (int)((3.14159274f + (a)) / 6.28318548f))
#define ADJ(a) ((3.14159274f + (a) >= 0.0f) ? (a) - REV(a) : 6.28318548f + ((a) - REV(a)))

u32 SCR_SetMyPlace(u8 *ss) {
    u8 *lpMdlMng;

    lpMdlMng = (u8 *)(MdlMng + 0x11800);
    *(float *)(lpMdlMng + 0x20) = *(float *)(ss + 8);
    *(float *)(lpMdlMng + 0x24) = *(float *)(ss + 0x10);
    *(float *)(lpMdlMng + 0x28) = *(float *)(ss + 0x18);
    *(float *)(lpMdlMng + 0x34) = ADJ((0.0174499992f * *(float *)(ss + 0x20)));
    StabilizeMyCloth();
    *(u32 *)ss = 0;
}






/* SCR_AddMySpiritNum @ 0x16D940 .. 0x16D948 (0x8 bytes) */



static void SCR_AddMySpiritNum(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}





/* SCR_SetMyEquip @ 0x16D8F0 .. 0x16D938 (0x48 bytes, frame 0x20) */


static void SCR_SetMyEquip(u32 *a0 /* r4 */) {
    u32 s0;
    u32 a1;
    u32 a2;
    u32 a3;

    s0 = (u32)a0;
    a1 = *(u32 *)((s0 + 8));
    a2 = *(u32 *)((s0 + 0x10));
    a3 = *(u32 *)((s0 + 0x18));
    a0 = (u32 *)((u8 *)MdlMng + 0x11800);
    SetMyEquip(a0, a1, a2, a3, 1);
    ChangeMyEquipSound();
    *(u32 *)s0 = 0;
    return;
}






/* SCR_SetMyCrouch @ 0x16D8C0 .. 0x16D8F0 (0x30 bytes, frame 0x20) */


static void SCR_SetMyCrouch(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = (u32 *)((u8 *)MdlMng + 0x11800);
    SetMyCrouch(a0);
    *(u32 *)s0 = 0;
    return;
}


/* SCR_SetMyTotter @ 0x16D890 .. 0x16D8BC (0x2c bytes, frame 0x20) */


static void SCR_SetMyTotter(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    SetMyTotterMode(0);
    *(u32 *)s0 = 0;
    return;
}







/* SCR_SetMyMukade @ 0x16D860 .. 0x16D88C (0x2c bytes, frame 0x20) */


static void SCR_SetMyMukade(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = (u32 *)*(u32 *)(((u8 *)a0 + 8));
    SetMyMukadeMode(a0);
    *(u32 *)s0 = 0;
    return;
}


/* SCR_SetMyNormalMode @ 0x16D830 .. 0x16D858 (0x28 bytes, frame 0x20) */


static void SCR_SetMyNormalMode(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    SetMyNormalMode();
    *(u32 *)s0 = 0;
    return;
}


/* SCR_SendMessage @ 0x16D7D0 .. 0x16D824 (0x54 bytes, frame 0x20) */






static void SCR_SendMessage(void *a0 /* r4 */) {
    u32 *s0;
    u32 v0;

    s0 = (u32 *)a0;
    v0 = GetCamCtrlMode();
    if (v0 != (u32)2) {
        v0 = *(s32 *)(((u8 *)s0 + 0x10));
        a0 = (void *)*(s32 *)(((u8 *)s0 + 8));
        v0 = v0 != 0;
        v0 = v0 ^ 1;
        KnMsgMng_SendMsgEx((s32)a0, 1, v0);
    }
    *(u32 *)s0 = 0;
    return;
}


/* SCR_CheckMessage @ 0x16D790 .. 0x16D7C8 (0x38 bytes, frame 0x20) */


static void SCR_CheckMessage(void *a0 /* r4 */) {
    u32 *s0;
    u32 v0;

    s0 = (u32 *)a0;
    v0 = KnMsgMng_CheckMsgNone();
    fsScr_SetPointerData((u32 *)((u8 *)s0 + 4), (u32)((u32)(v0 != 0) ^ 1));
    *(u32 *)s0 = 0;
    return;
}





/* SCR_GetMessageSelectId @ 0x16D750 .. 0x16D784 (0x34 bytes, frame 0x20) */


static void SCR_GetMessageSelectId(void *a0 /* r4 */) {
    u32 *s0;
    u32 v0;

    s0 = (u32 *)a0;
    v0 = KnMsgMng_GetSelectNum();
    a0 = (void *)(s32)((u8 *)s0 + 4);
    fsScr_SetPointerData(a0, v0);
    *(u32 *)s0 = 0;
    return;
}





/* SCR_SendMessageWithMdlAnim @ 0x16D690 .. 0x16D744 (0xb4 bytes, frame 0x30) */






static void SCR_SendMessageWithMdlAnim(void *a0 /* r4 */) {
    u8 *s0;
    s32 a3;
    u32 a2;
    u8 *s1;
    u32 v0;

    s0 = (u8 *)a0;
    v0 = (u32)GetScriptMdlMng(*(s32 *)(((u8 *)a0 + 0x18)), *(s32 *)(s0 + 0x20), (u32)1);
    s1 = (u8 *)v0;
    if ((u32)s1 == 0) {
        *(u32 *)s0 = 0;
    } else {
        v0 = GetCamCtrlMode();
        if (v0 != (u32)2) {
            a2 = *(s32 *)(s0 + 0x10);
            v0 = (u32)MdlMng;
            a3 = (s32)(s1 - (u32)(MdlMng));
            KnMsgMng_SendMsgEx_SetMdlId_AnimId(*(s32 *)(s0 + 8), 1, (u32)(a2 != 0) ^ 1, a3 /
                (s32)(0x1c0), *(s32 *)(s0 + 0x28));
        }
        *(u32 *)s0 = 0;
    }
    return;
}





/* SCR_SendMessageVoice @ 0x16D630 .. 0x16D68C (0x5c bytes, frame 0x20) */


static void SCR_SendMessageVoice(void *a0 /* r4 */) {
    u32 *s0;
    u32 v0;

    s0 = (u32 *)a0;
    v0 = GetCamCtrlMode();
    if (v0 != (u32)2) {
        v0 = *(s32 *)(((u8 *)s0 + 0x10));
        a0 = (void *)*(s32 *)(((u8 *)s0 + 8));
        v0 = v0 != 0;
        v0 = v0 ^ 1;
        v0 = (u16)v0;
        v0 = v0 | 0x10;
        KnMsgMng_SendMsgEx((s32)a0, 1, v0);
    }
    *(u32 *)s0 = 0;
    return;
}











/* SCR_SendMessageVoiceWithMdlAnim @ 0x16D570 .. 0x16D62C (0xbc bytes, frame 0x30) */


static void SCR_SendMessageVoiceWithMdlAnim(void *a0 /* r4 */) {
    u8 *s0;
    u32 a2;
    u32 v0;
    u8 *s1;

    s0 = (u8 *)a0;
    v0 = (u32)GetScriptMdlMng(*(s32 *)(((u8 *)a0 + 0x18)), *(s32 *)(s0 + 0x20), (u32)1);
    s1 = (u8 *)v0;
    if ((u32)s1 == 0) {
        *(u32 *)s0 = 0;
    } else {
        v0 = GetCamCtrlMode();
        if (v0 != (u32)2) {
            a2 = *(s32 *)(s0 + 0x10);
            v0 = (u32)MdlMng;
            KnMsgMng_SendMsgEx_SetMdlId_AnimId(*(s32 *)(s0 + 8), 1, (u32)(u16)((u32)(a2 != 0) ^ 1)
                | 0x10, (s32)(s1 - (u32)(MdlMng)) / (s32)(0x1c0), *(s32 *)(s0 + 0x28));
        }
        *(u32 *)s0 = 0;
    }
    return;
}





/* SCR_StartDrama @ 0x16D4F0 .. 0x16D564 (0x74 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x20 escapes at 0x16d50c
 *   stack: address of the slot at 0x20 escapes at 0x16d540
 */


static void SCR_StartDrama(void *a0 /* r4 */) {
    u8 *s0;

    s0 = (u8 *)a0;
    {
        u8 stackFrame_20[16] __attribute__((aligned(16))) = {0};
        SetFadeMng(3, (signed int *)(u8 *)((u8 *)&stackFrame_20[0]), 0x28, (void *)0, (void *)0, 0,
            0);
        SetFadeDrama(*(s32 *)(s0 + 0x10));
        *(u32 *)s0 = 0;
        return;
    }
}





/* SCR_CheckDrama @ 0x16D480 .. 0x16D4EC (0x6c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x16d49c if (..) goto .L0016D4C8
 *   cfg: kept goto: 0x16d4b0 -> .L0016D4D8
 */


static void SCR_CheckDrama(void *a0 /* r4 */) {
    u32 *s0;
    u32 v0;

    s0 = (u32 *)a0;
    v0 = GetDramaReadFlag();
    if (v0 == 0) {
        v0 = GetFadeDrama();
        if (v0 == (u32)-1) {
            goto _L0016D4C8;
        }
    }
    a0 = (void *)((u8 *)s0 + 4);
    fsScr_SetPointerData(a0, (u32)1);
    goto _L0016D4D8;
    _L0016D4C8:;
    a0 = (void *)((u8 *)s0 + 4);
    fsScr_SetPointerData(a0, 0);
    _L0016D4D8:;
    *(u32 *)s0 = 0;
    return;
}





/* SCR_SetCamModePath @ 0x16D450 .. 0x16D47C (0x2c bytes, frame 0x20) */


static void SCR_SetCamModePath(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    SetCamCtrlMode(0);
    *(u32 *)s0 = 0;
    return;
}






/* SCR_SetCamModeFree @ 0x16D270 .. 0x16D450 (0x1e0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3c8ef34d at 0x16d29c
 *   fpu: float literal 0x40490fdb at 0x16d2a0
 *   fpu: float literal 0x00000000 at 0x16d2ac
 *   fpu: float literal 0x40c90fdb at 0x16d2dc
 *   fpu: mtc1 reinterprets v0 at 0x16d300
 *   fpu: float literal 0x3c8ef34d at 0x16d330
 *   fpu: float literal 0x00000000 at 0x16d334
 *   fpu: float literal 0x40490fdb at 0x16d340
 *   fpu: float literal 0x40c90fdb at 0x16d360
 *   fpu: mtc1 reinterprets v0 at 0x16d384
 *   fpu: float literal 0x3c8ef34d at 0x16d3b4
 *   fpu: float literal 0x00000000 at 0x16d3b8
 *   fpu: float literal 0x40490fdb at 0x16d3c4
 *   fpu: float literal 0x40c90fdb at 0x16d3e4
 *   fpu: mtc1 reinterprets v0 at 0x16d408
 *   stack: address of the slot at 0x30 escapes at 0x16d42c
 *   stack: address of the slot at 0x20 escapes at 0x16d434
 *   declaration vs inferred signature: return u32 vs inferred void; 0 parameters vs 1 inferred
 *   return without a value in a non-void function
 */

extern void SetCameraPos(float *);
extern void SetCameraAng(float *);

u32 SCR_SetCamModeFree(u8 *a0) {
    u32 v1;
    u32 v0;
    float f2;
    float f2_v2; // f2
    float f2_v4; // f2
    float f1;
    float f0;
    u8 stackFrame_30[16] __attribute__((aligned(16)));
    u8 stackFrame_20[16] __attribute__((aligned(16)));

    SetCamCtrlMode(1);
    v0 = 0x3c8e0000;
    v1 = 0x3c8e0000 | 0xf34d;
    f2 = 0.0174499992f;
    f1 = 3.14159274f;
    *(f32 *)((u8 *)&stackFrame_30[0]) = *(float *)(a0 + 8);
    f0 = 0.0f;
    ((f32 *)stackFrame_30)[1] = *(float *)(a0 + 0x10);
    ((f32 *)stackFrame_30)[2] = *(float *)(a0 + 0x18);
    if ((3.14159274f + (0.0174499992f * *(float *)(a0 + 0x20))) >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f0 = ((0.0174499992f * *(float *)(a0 + 0x20)) - (6.28318548f *
            (float)((float)(s32)((3.14159274f + (0.0174499992f * *(float *)(a0 + 0x20))) /
            6.28318548f))));
    } else {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f0 = (f1 + ((0.0174499992f * *(float *)(a0 + 0x20)) - (f1 *
            (float)((float)(s32)((3.14159274f + (0.0174499992f * *(float *)(a0 + 0x20))) / f1)))));
    }
    *(f32 *)((u8 *)&stackFrame_20[0]) = f0;
    f2_v2 = 0.0174499992f;
    f0 = 0.0f;
    f1 = 3.14159274f;
    if ((3.14159274f + (0.0174499992f * *(float *)(a0 + 0x28))) >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f0 = ((0.0174499992f * *(float *)(a0 + 0x28)) - (6.28318548f *
            (float)((float)(s32)((3.14159274f + (0.0174499992f * *(float *)(a0 + 0x28))) /
            6.28318548f))));
    } else {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f0 = (f1 + ((0.0174499992f * *(float *)(a0 + 0x28)) - (f1 *
            (float)((float)(s32)((3.14159274f + (0.0174499992f * *(float *)(a0 + 0x28))) / f1)))));
    }
    ((f32 *)stackFrame_20)[1] = f0;
    f2_v4 = 0.0174499992f;
    f0 = 0.0f;
    f1 = 3.14159274f;
    if ((3.14159274f + (0.0174499992f * *(float *)(a0 + 0x30))) >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f0 = ((0.0174499992f * *(float *)(a0 + 0x30)) - (6.28318548f *
            (float)((float)(s32)((3.14159274f + (0.0174499992f * *(float *)(a0 + 0x30))) /
            6.28318548f))));
    } else {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f0 = (f1 + ((0.0174499992f * *(float *)(a0 + 0x30)) - (f1 *
            (float)((float)(s32)((3.14159274f + (0.0174499992f * *(float *)(a0 + 0x30))) / f1)))));
    }
    ((f32 *)stackFrame_20)[2] = f0;
    SetCameraPos((float *)((u8 *)&stackFrame_30[0]));
    SetCameraAng((float *)((u8 *)&stackFrame_20[0]));
    *(u32 *)a0 = 0;
    return;
}







/* SCR_GetNowCamIndex @ 0x16D230 .. 0x16D264 (0x34 bytes, frame 0x20) */


static void SCR_GetNowCamIndex(void *a0 /* r4 */) {
    u32 *s0;
    u32 *v0;
    u32 a1;

    s0 = (u32 *)a0;
    v0 = (u32 *)GetGameCamInfo();
    a1 = *(s32 *)(((u8 *)v0 + 4));
    a0 = (void *)(s32)((u8 *)s0 + 4);
    fsScr_SetPointerData(a0, a1);
    *(u32 *)s0 = 0;
    return;
}





/* SCR_SetCamModeFreeTarget @ 0x16D200 .. 0x16D22C (0x2c bytes, frame 0x20) */


static void SCR_SetCamModeFreeTarget(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = (u32 *)*(u32 *)(((u8 *)a0 + 8));
    SetTargetFreeCamera(a0);
    *(u32 *)s0 = 0;
    return;
}





/* SCR_SetCamPathDirect @ 0x16D1D0 .. 0x16D1FC (0x2c bytes, frame 0x20) */


static void SCR_SetCamPathDirect(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = (u32 *)*(u32 *)(((u8 *)a0 + 8));
    SetCamPathDirect(a0);
    *(u32 *)s0 = 0;
    return;
}





/* SCR_SetLoadCamReserve @ 0x16D1A0 .. 0x16D1CC (0x2c bytes, frame 0x20) */


static void SCR_SetLoadCamReserve(u8 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = (u8 *)*(u16 *)(((u8 *)a0 + 8));
    SetLoadCamReserve(a0);
    *(u32 *)s0 = 0;
    return;
}





extern void SetBlast(float, float, float *, float *, signed int);

u32 SCR_SetPhantomBlast(u8 *ss) {
    u8 *lpMdlMng;
    float BlastPos[4];

    lpMdlMng = (u8 *)(MdlMng + 0x11800);
    lpMdlMng = (u8 *)((u32)lpMdlMng + 0x20);
    BlastPos[0] = *(float *)(ss + 0x10);
    BlastPos[1] = *(float *)(ss + 0x18);
    BlastPos[2] = *(float *)(ss + 0x20);
    SetBlast(0.0299999993f, 120.0f, BlastPos, (float *)lpMdlMng, *(s32 *)(ss + 0x28));
    *(u32 *)ss = 0;
}





/* SCR_SetScreenSway @ 0x16D0B0 .. 0x16D124 (0x74 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x20 escapes at 0x16d0e4
 */


static void SCR_SetScreenSway(void *a0 /* r4 */) {
    u32 v1;
    u8 *s0;
    float f0;
    u8 stackFrame[16] __attribute__((aligned(16)));

    v1 = *(s32 *)(((u8 *)a0 + 8));
    s0 = (u8 *)a0;
    if (v1 == (u32)1) {
        f0 = *(float *)(((u8 *)s0 + 0x10));
        a0 = (void *)((u8 *)&stackFrame[0]);
        *(f32 *)((u8 *)&stackFrame[0]) = f0;
        f0 = *(float *)(((u8 *)s0 + 0x18));
        *(f32 *)((u8 *)&stackFrame[4]) = f0;
        f0 = *(float *)(((u8 *)s0 + 0x20));
        *(f32 *)((u8 *)&stackFrame[8]) = f0;
        SfxPostEffect_SetFlickerParam(a0);
        SfxPostEffect_SetEnable(0, (u32)1);
    } else {
        SfxPostEffect_SetEnable(0, 0);
    }
    *(u32 *)s0 = 0;
    return;
}





/* SCR_SetScreenDizzy @ 0x16D080 .. 0x16D0AC (0x2c bytes, frame 0x20) */


static void SCR_SetScreenDizzy(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = (u32 *)*(u32 *)(((u8 *)a0 + 8));
    SetLightDizzy(a0);
    *(u32 *)s0 = 0;
    return;
}





/* SCR_SetPeepCamera @ 0x16D050 .. 0x16D07C (0x2c bytes, frame 0x20) */


static void SCR_SetPeepCamera(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = (u32 *)*(u32 *)(((u8 *)a0 + 8));
    SetPeepCamera(a0);
    *(u32 *)s0 = 0;
    return;
}





/* SCR_StopPeepCamera @ 0x16D020 .. 0x16D048 (0x28 bytes, frame 0x20) */


static void SCR_StopPeepCamera(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    StopPeepCamera();
    *(u32 *)s0 = 0;
    return;
}







/* SCR_CheckPeepManual @ 0x16CFE0 .. 0x16D014 (0x34 bytes, frame 0x20) */


static void SCR_CheckPeepManual(void *a0 /* r4 */) {
    u32 *s0;
    u32 v0;

    s0 = (u32 *)a0;
    v0 = CheckPeepManual();
    a0 = (void *)(s32)((u8 *)s0 + 4);
    fsScr_SetPointerData(a0, v0);
    *(u32 *)s0 = 0;
    return;
}


/* SCR_GetItem @ 0x16CFA0 .. 0x16CFDC (0x3c bytes, frame 0x20) */


static void SCR_GetItem(u32 *a0 /* r4 */) {
    u32 s0;
    u32 a1;
    u32 a3;
    u32 t0;

    s0 = (u32)a0;
    a0 = (u32 *)*(u32 *)(((u8 *)a0 + 8));
    a1 = *(u32 *)((s0 + 0x10));
    a3 = *(u32 *)((s0 + 0x18));
    t0 = *(u32 *)((s0 + 0x20));
    ItemMng_GetItemProc(a0, a1, 1, a3, t0);
    *(u32 *)s0 = 0;
    return;
}






/* SCR_GetItem2 @ 0x16CF60 .. 0x16CF9C (0x3c bytes, frame 0x20) */


static void SCR_GetItem2(u32 *a0 /* r4 */) {
    u32 s0;
    u32 a1;
    u32 a3;
    u32 t0;

    s0 = (u32)a0;
    a0 = (u32 *)*(u32 *)(((u8 *)a0 + 8));
    a1 = *(u32 *)((s0 + 0x10));
    a3 = *(u32 *)((s0 + 0x18));
    t0 = *(u32 *)((s0 + 0x20));
    ItemMng_GetItemProc(a0, a1, 7, a3, t0);
    *(u32 *)s0 = 0;
    return;
}





/* SCR_GetItemNum @ 0x16CF20 .. 0x16CF58 (0x38 bytes, frame 0x20) */


static void SCR_GetItemNum(void *a0 /* r4 */) {
    u8 *s0;
    u32 v0;

    s0 = (u8 *)a0;
    a0 = (void *)*(u16 *)(((u8 *)a0 + 8));
    v0 = ItemMng_GetItemNum_Direct((unsigned short)a0);
    a0 = (void *)(s32)((u8 *)s0 + 0xc);
    fsScr_SetPointerData(a0, (u32)(u16)v0);
    *(u32 *)s0 = 0;
    return;
}





/* SCR_AddItemNum @ 0x16CEF0 .. 0x16CF20 (0x30 bytes, frame 0x20) */


static void SCR_AddItemNum(u8 *a0 /* r4 */) {
    u32 s0;
    s16 a1;

    s0 = (u32)a0;
    a1 = *(s16 *)((s0 + 0x10));
    a0 = (u8 *)*(u16 *)(((u8 *)a0 + 8));
    ItemMng_Add_Direct(a0, a1);
    *(u32 *)s0 = 0;
    return;
}





/* SCR_SetMapSfxErase @ 0x16CE80 .. 0x16CEE8 (0x68 bytes, frame 0x30) */


static void SCR_SetMapSfxErase(void *a0 /* r4 */) {
    u8 *s1;
    u32 v0;
    u32 s0;

    s1 = (u8 *)a0;
    v0 = GetMapSfxHdl(*(s32 *)(((u8 *)a0 + 8)));
    s0 = v0;
    v0 = *(s32 *)(s1 + 0x10);
    SFX_EnableDraw(s0, (u32)(v0 != 0) ^ 1, 0);
    v0 = *(s32 *)(s1 + 0x10);
    SFX_EnableAction(s0, (u32)(v0 != 0) ^ 1, 0);
    *(u32 *)s1 = 0;
    return;
}


/* SCR_GenerateSfx @ 0x16CDE0 .. 0x16CE7C (0x9c bytes, frame 0x40) */
/*
 * dcomp notes:
 *   quad: a1: 128-bit web split from its scalar uses
 *   literal: @1574 -> 0x22af50
 *   stack: address of the slot at 0x30 escapes at 0x16ce2c
 *   stack: address of the slot at 0x20 escapes at 0x16ce2c
 *   stack: address of the slot at 0x30 escapes at 0x16ce60
 *   stack: address of the slot at 0x20 escapes at 0x16ce60
 *   literal: @1574 initializes the 16-byte local at 0x30
 */


static void SCR_GenerateSfx(void *a0 /* r4 */) {
    u8 *s0;
    u32 a3;
    u8 *a2;
    u32 v0;
    struct stackFrame_30 { u8 b[16]; } stackFrame_30 __attribute__((aligned(16)));

    v0 = 0x22af50;
    a2 = ((u8 *)&stackFrame_30);
    a3 = *(s32 *)(((u8 *)a0 + 8));
    s0 = (u8 *)a0;
    stackFrame_30 = (struct stackFrame_30){{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f}};
    *(f32 *)((u8 *)&stackFrame_30) = *(float *)(((u8 *)a0 + 0x10));
    *(f32 *)((u8 *)&stackFrame_30 + 0x4) = *(float *)(((u8 *)a0 + 0x18));
    *(f32 *)((u8 *)&stackFrame_30 + 0x8) = *(float *)(((u8 *)a0 + 0x20));
    {
        u8 stackFrame_20[16] __attribute__((aligned(16))) = {0};
        a0 = (void *)(u16)a3;
        *(f32 *)((u8 *)&stackFrame_20[0]) = *(float *)(s0 + 0x28);
        ((f32 *)stackFrame_20)[1] = *(float *)(s0 + 0x30);
        SFX_Create_OnAng((unsigned short)a0, (float *)(u8 *)((u8 *)&stackFrame_30), (float *)(u8
            *)((u8 *)&stackFrame_20[0]));
        *(u32 *)s0 = 0;
        return;
    }
}






/* SCR_GenerateBugs @ 0x16CD80 .. 0x16CDD4 (0x54 bytes, frame 0x20) */


static void SCR_GenerateBugs(void *a0 /* r4 */) {
    float f12;
    u8 *s0;
    float f13;
    float f14;
    u32 a2;
    float f15;
    float f16;
    float f17;
    float f18;
    float f19;
    u32 a1;

    f12 = *(float *)(((u8 *)a0 + 8));
    s0 = (u8 *)a0;
    f13 = *(float *)(((u8 *)a0 + 0x10));
    f14 = *(float *)(((u8 *)a0 + 0x18));
    a2 = *(s32 *)(((u8 *)s0 + 0x58));
    f15 = *(float *)(((u8 *)a0 + 0x20));
    f16 = *(float *)(((u8 *)s0 + 0x30));
    f17 = *(float *)(((u8 *)s0 + 0x38));
    f18 = *(float *)(((u8 *)s0 + 0x40));
    f19 = *(float *)(((u8 *)s0 + 0x48));
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x28));
    a1 = *(s32 *)(((u8 *)s0 + 0x50));
    SfxScriptIF_GenerateBugs(f12, f13, f14, f15, (signed int)a0, f16, f17, f18, f19, a1, a2);
    *(u32 *)s0 = 0;
    return;
}







/* SCR_SetBugColor @ 0x16CD40 .. 0x16CD78 (0x38 bytes, frame 0x20) */


static void SCR_SetBugColor(u8 *a0 /* r4 */) {
    u32 s0;
    u8 a1;
    u8 a2;
    u8 a3;

    s0 = (u32)a0;
    a1 = *(u8 *)((s0 + 0x10));
    a2 = *(u8 *)((s0 + 0x18));
    a3 = *(u8 *)((s0 + 0x20));
    a0 = (u8 *)*(u8 *)(((u8 *)a0 + 8));
    SfxScriptIF_SetBugColor(a0, a1, a2, a3);
    *(u32 *)s0 = 0;
    return;
}







/* SCR_SfxIdol @ 0x16CD10 .. 0x16CD3C (0x2c bytes, frame 0x20) */


static void SCR_SfxIdol(u8 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = (u8 *)*(u8 *)(((u8 *)a0 + 8));
    SFX_Idle(a0);
    *(u32 *)s0 = 0;
    return;
}







/* SCR_PlayVagStm @ 0x16CC00 .. 0x16CD10 (0x110 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @2118 -> 0x2539e0
 *   indirect: jr v1 at 0x16cc80 -> <v1>
 *   cfg: kept branch: 0x16cc28 if (..) goto .L0016CC60
 */


static void SCR_PlayVagStm(void *a0 /* r4 */) {
    u8 *s2;
    u32 a2;
    u32 a1;
    u32 s1;
    u32 a0_scalar; // a0
    u32 v1;
    u32 s0;
    u32 v0;

    v1 = 2;
    s2 = (u8 *)a0;
    a0_scalar = *(s32 *)(((u8 *)a0 + 0x20));
    s1 = 0;
    if (a0_scalar != v1) {
        v1 = 4;
        if (a0_scalar != v1) {
            goto _L0016CC60;
        }
    }
    a0_scalar = *(s32 *)(s2 + 0x30);
    a1 = *(s32 *)(s2 + 0x38);
    a2 = 1;
    v0 = (u32)GetScriptMdlMng(a0_scalar, a1, a2);
    s1 = v0;
    if (s1 == 0) {
        *(u32 *)s2 = 0;
    } else {
        _L0016CC60:;
        a1 = *(s32 *)(s2 + 8);
        a0_scalar = 0x2539e0;
        switch (a1) {
        case 0:
            a0_scalar = (u8)a1;
            StopVagStm(a0_scalar, a1);
            a1 = *(s32 *)(s2 + 0x18);
            a0_scalar = *(s32 *)(s2 + 0x10);
            PlayBgmVagStm(a0_scalar, a1);
            s0 = *(s32 *)(s2 + 8);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            a0_scalar = *(s32 *)(s2 + 0x10);
            v0 = PlayVoiceVagStm(a0_scalar);
            s0 = v0;
            break;
        case 5:
            a0_scalar = (u8)a1;
            StopVagStm(a0_scalar);
            a0_scalar = *(s32 *)(s2 + 0x10);
            PlayGeneralVagStm(a0_scalar);
            s0 = *(s32 *)(s2 + 8);
        default:
            break;
        }
        if (s1 != 0) {
            a0_scalar = (u8)s0;
            a2 = s1;
            a1 = (u32)V0;
            SetVagStm3D(a0_scalar, (float *)V0, *(float *)(s2 + 0x40), (void *)a2);
        }
        *(u32 *)s2 = 0;
    }
    return;
}






/* SCR_StopVagStm @ 0x16CBD0 .. 0x16CBFC (0x2c bytes, frame 0x20) */


static void SCR_StopVagStm(u8 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = (u8 *)*(u8 *)(((u8 *)a0 + 8));
    StopVagStm(a0);
    *(u32 *)s0 = 0;
    return;
}


/* SCR_FadeOutVagStm @ 0x16CB90 .. 0x16CBC4 (0x34 bytes, frame 0x20) */


static void SCR_FadeOutVagStm(u8 *a0 /* r4 */) {
    u32 s0;
    u32 a2;

    s0 = (u32)a0;
    a0 = (u8 *)*(u8 *)(((u8 *)a0 + 8));
    a2 = *(u32 *)((s0 + 0x10));
    SetVagStmFade(a0, 1, a2);
    *(u32 *)s0 = 0;
    return;
}





/* SCR_CheckPlayVagStm @ 0x16CB50 .. 0x16CB88 (0x38 bytes, frame 0x20) */


static void SCR_CheckPlayVagStm(void *a0 /* r4 */) {
    u8 *s0;
    u32 v0;

    s0 = (u8 *)a0;
    v0 = CheckVagStmState(*(u8 *)(((u8 *)a0 + 8)));
    a0 = (void *)(s0 + 0xc);
    fsScr_SetPointerData(a0, v0 != 0);
    *(u32 *)s0 = 0;
    return;
}





/* SCR_FadeInScreen @ 0x16CAB0 .. 0x16CB4C (0x9c bytes, frame 0x40) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1634 -> 0x22af60
 *   stack: address of the slot at 0x30 escapes at 0x16cacc
 *   delay: lui at 0x16caf4 writes a register its branch at 0x16caf0 reads
 *   stack: address of the slot at 0x20 escapes at 0x16cb18
 *   stack: address of the slot at 0x30 escapes at 0x16cb18
 *   stack: address of the slot at 0x30 escapes at 0x16cb30
 *   literal: @1634 initializes the 16-byte local at 0x20
 */




static void SCR_FadeInScreen(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u32 v0;
    struct __copy_u_long128_1 { u_long128 b[1]; };

    s0 = (u8 *)a0;
    {
        u8 stackFrame_30[16] __attribute__((aligned(16))) = {0};
        v1 = *(s32 *)(s0 + 0x10);
        if (v1 == (u32)1) {
            v0 = 0x22af60;
            v1 = (u32)((u8 *)&stackFrame_30[0]);
            {
                struct stackFrame_20 { u8 b[16]; } stackFrame_20 __attribute__((aligned(16))) =
                    {{0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00}};
                a0 = (void *)((u8 *)&stackFrame_20);
                *(struct __copy_u_long128_1 *)((u8 *)&stackFrame_30[0]) = *(struct
                    __copy_u_long128_1 *)((u8 *)&stackFrame_20);
            }
        }
        SetFadeMng(0, (signed int *)(u8 *)((u8 *)&stackFrame_30[0]), *(s32 *)(s0 + 8), (void *)0,
            (void *)0, 0, (signed
    int)0);
        *(u32 *)s0 = 0;
        return;
    }
}


/* SCR_FadeOutScreen @ 0x16CA10 .. 0x16CAAC (0x9c bytes, frame 0x40) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1646 -> 0x22af70
 *   stack: address of the slot at 0x30 escapes at 0x16ca2c
 *   delay: lui at 0x16ca54 writes a register its branch at 0x16ca50 reads
 *   stack: address of the slot at 0x20 escapes at 0x16ca78
 *   stack: address of the slot at 0x30 escapes at 0x16ca78
 *   stack: address of the slot at 0x30 escapes at 0x16ca90
 *   literal: @1646 initializes the 16-byte local at 0x20
 */




static void SCR_FadeOutScreen(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u32 v0;
    struct __copy_u_long128_1 { u_long128 b[1]; };

    s0 = (u8 *)a0;
    {
        u8 stackFrame_30[16] __attribute__((aligned(16))) = {0};
        v1 = *(s32 *)(s0 + 0x10);
        if (v1 == (u32)1) {
            v0 = 0x22af70;
            v1 = (u32)((u8 *)&stackFrame_30[0]);
            {
                struct stackFrame_20 { u8 b[16]; } stackFrame_20 __attribute__((aligned(16))) =
                    {{0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00}};
                a0 = (void *)((u8 *)&stackFrame_20);
                *(struct __copy_u_long128_1 *)((u8 *)&stackFrame_30[0]) = *(struct
                    __copy_u_long128_1 *)((u8 *)&stackFrame_20);
            }
        }
        SetFadeMng(1, (signed int *)(u8 *)((u8 *)&stackFrame_30[0]), *(s32 *)(s0 + 8), (void *)0,
            (void *)0, 0, (signed
    int)0);
        *(u32 *)s0 = 0;
        return;
    }
}





/* SCR_FadeOutInScreen @ 0x16C970 .. 0x16CA10 (0xa0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1658 -> 0x22af80
 *   stack: address of the slot at 0x30 escapes at 0x16c98c
 *   delay: lui at 0x16c9b4 writes a register its branch at 0x16c9b0 reads
 *   stack: address of the slot at 0x20 escapes at 0x16c9d8
 *   stack: address of the slot at 0x30 escapes at 0x16c9d8
 *   stack: address of the slot at 0x30 escapes at 0x16c9f4
 *   literal: @1658 initializes the 16-byte local at 0x20
 */




static void SCR_FadeOutInScreen(void *a0 /* r4 */) {
    u8 *s0;
    u32 t1;
    u32 a2;
    u32 v1;
    u32 v0;
    struct __copy_u_long128_1 { u_long128 b[1]; };

    s0 = (u8 *)a0;
    {
        u8 stackFrame_30[16] __attribute__((aligned(16))) = {0};
        v1 = *(s32 *)(s0 + 0x10);
        if (v1 == (u32)3) {
            v0 = 0x22af80;
            v1 = (u32)((u8 *)&stackFrame_30[0]);
            {
                struct stackFrame_20 { u8 b[16]; } stackFrame_20 __attribute__((aligned(16))) =
                    {{0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00}};
                a0 = (void *)((u8 *)&stackFrame_20);
                *(struct __copy_u_long128_1 *)((u8 *)&stackFrame_30[0]) = *(struct
                    __copy_u_long128_1 *)((u8 *)&stackFrame_20);
            }
        }
        a2 = *(s32 *)(s0 + 8);
        v0 = *(s32 *)(s0 + 0x18);
        t1 = *(s32 *)(s0 + 0x10);
        SetFadeMng(2, (signed int *)(u8 *)((u8 *)&stackFrame_30[0]), a2, (void *)0, (void *)0, t1,
            (signed
    int)(a2 - v0));
        *(u32 *)s0 = 0;
        return;
    }
}





/* SCR_FadeOutSceneLoad @ 0x16C8C0 .. 0x16C968 (0xa8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1670 -> 0x22af90
 *   stack: address of the slot at 0x30 escapes at 0x16c8dc
 *   delay: lui at 0x16c904 writes a register its branch at 0x16c900 reads
 *   stack: address of the slot at 0x20 escapes at 0x16c928
 *   stack: address of the slot at 0x30 escapes at 0x16c928
 *   stack: address of the slot at 0x30 escapes at 0x16c940
 *   literal: @1670 initializes the 16-byte local at 0x20
 */


static void SCR_FadeOutSceneLoad(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u32 v0;
    struct __copy_u_long128_1 { u_long128 b[1]; };

    s0 = (u8 *)a0;
    {
        u8 stackFrame_30[16] __attribute__((aligned(16))) = {0};
        v1 = *(s32 *)(s0 + 0x18);
        if (v1 == (u32)1) {
            v0 = 0x22af90;
            v1 = (u32)((u8 *)&stackFrame_30[0]);
            {
                struct stackFrame_20 { u8 b[16]; } stackFrame_20 __attribute__((aligned(16))) =
                    {{0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00}};
                a0 = (void *)((u8 *)&stackFrame_20);
                *(struct __copy_u_long128_1 *)((u8 *)&stackFrame_30[0]) = *(struct
                    __copy_u_long128_1 *)((u8 *)&stackFrame_20);
            }
        }
        SetFadeMng(6, (signed int *)((u8 *)&stackFrame_30[0]), *(s32 *)(s0 + 8), (void *)0, (void
            *)0, *(s32 *)(s0 + 0x10), (signed
    int)0);
        SetFadeSceneLoad(*(s32 *)(s0 + 0x20), *(s32 *)(s0 + 0x28));
        *(u32 *)s0 = 0;
        return;
    }
}





extern u32 GetFreePointLightIndex();
extern void SetPointLightOn(signed int, float *, float);
u32 SCR_SetObjPointLightOn(u8 *script) {
    u32 index;
    u8 *model;
    index = GetMdlMngIndexByCtrlId(1, *(s32 *)(script + 8));
    index += 0x30;
    model = (u8 *)MdlMng + index * 0x1c0;
    *(u32 *)(model + 0x180) = GetFreePointLightIndex();
    {
        u8 position[16] __attribute__((aligned(16))) = {0};
        *(float *)&position[0] = *(float *)(script + 0x10);
        *(float *)&position[4] = *(float *)(script + 0x18);
        *(float *)&position[8] = *(float *)(script + 0x20);
        SetPointLightOn(*(s32 *)(model + 0x180), (float *)position, *(float *)(script + 0x28));
    }
    *(u32 *)script = 0;
    return;
}






/* SCR_SetObjPointLightOff @ 0x16C790 .. 0x16C804 (0x74 bytes, frame 0x30) */



static void SCR_SetObjPointLightOff(void *a0 /* r4 */) {
    u32 a1;
    u32 v0;
    u8 *s0;
    void *a0_s1; // a0

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)1, *(s32 *)(((u8 *)a0 + 8)));
    a1 = v0 + 0x30;
    a0_s1 = (void *)(s32)(a1 << 3);
    s0 = (u8 *)((u8 *)MdlMng + (u32)((void *)(s32)((u32)(void *)((u8 *)a0_s1 - a1) << 6)));
    a0_s1 = (void *)*(s32 *)(s0 + 0x180);
    if ((s32)a0_s1 > (s32)1) {
        SetPointLightOff((signed int)a0_s1);
    }
    *(u32 *)(s0 + 0x180) = 0;
    *(u32 *)a0 = 0;
    return;
}







/* SCR_SetObjMovePathDirect @ 0x16C730 .. 0x16C78C (0x5c bytes, frame 0x20) */


static void SCR_SetObjMovePathDirect(void *a0 /* r4 */) {
    u32 a3_field; // a3
    u32 a2_field; // a2
    void *a0_s0; // a0
    s32 v1;
    u32 v0;

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)1, *(s32 *)(((u8 *)a0 + 8)));
    a0_s0 = (void *)(s32)(v0 + 0x30);
    v1 = (u32)a0_s0 << 3;
    v0 = (u32)MdlMng;
    a2_field = *(u16 *)(((u8 *)a0 + 0x18));
    a3_field = *(u16 *)(((u8 *)a0 + 0x20));
    SetObjMovePath((void *)((u8 *)MdlMng + (s32)((u32)(s32)((u8 *)v1 - (u32)(a0_s0)) << 6)), *(s32
        *)(((u8 *)a0 + 0x10)), a2_field, a3_field);
    *(u32 *)a0 = 0;
    return;
}


/* SCR_FreeObjMovePath @ 0x16C6E0 .. 0x16C730 (0x50 bytes, frame 0x20) */



static void SCR_FreeObjMovePath(void *a0 /* r4 */) {
    u32 v0;
    s32 v1;
    void *a0_s0; // a0

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)1, *(s32 *)(((u8 *)a0 + 8)));
    a0_s0 = (void *)(s32)(v0 + 0x30);
    v1 = (u32)a0_s0 << 3;
    v0 = (u32)MdlMng;
    FreeObjMovePath((void *)((u8 *)MdlMng + (s32)((u32)(s32)((u8 *)v1 - (u32)(a0_s0)) << 6)));
    *(u32 *)a0 = 0;
    return;
}


/* SCR_CheckObjMovePath @ 0x16C670 .. 0x16C6D4 (0x64 bytes, frame 0x20) */



static void SCR_CheckObjMovePath(void *a0 /* r4 */) {
    u32 a1;
    u32 a0_s0_index; // a0
    u32 v0;

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)1, *(s32 *)(((u8 *)a0 + 8)));
    a0_s0_index = v0 + 0x30;
    v0 = (u32)MdlMng;
    v0 = (s32)((u8 *)MdlMng + (s32)(a0_s0_index * (u32)(0x1c0)));
    v0 = *(s32 *)((v0 + 0x17c));
    a1 = 0;
    if (v0 != 0) {
        a1 = 1;
    }
    fsScr_SetPointerData((void *)((u8 *)a0 + 0xc), a1);
    *(u32 *)a0 = 0;
    return;
}








/* SCR_SetObjTalkStart @ 0x16C610 .. 0x16C66C (0x5c bytes, frame 0x20) */







static void SCR_SetObjTalkStart(void *a0 /* r4 */) {
    u32 v0;
    s32 v1;
    void *a0_s0; // a0

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)1, *(s32 *)(((u8 *)a0 + 8)));
    a0_s0 = (void *)(s32)(v0 + 0x30);
    v1 = (u32)a0_s0 << 3;
    v0 = (u32)MdlMng;
    SetObjTalkStart((void *)((u8 *)MdlMng + (s32)((u32)(s32)((u8 *)v1 - (u32)(a0_s0)) << 6)), *(s32
        *)(((u8 *)a0 + 0x10)), *(s32 *)(((u8 *)a0 + 0x18)), 0);
    *(u32 *)a0 = 0;
    return;
}






/* SCR_SetObjTalkStart2 @ 0x16C5B0 .. 0x16C60C (0x5c bytes, frame 0x20) */



static void SCR_SetObjTalkStart2(void *a0 /* r4 */) {
    u32 v0;
    s32 v1;
    void *a0_s0; // a0

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)1, *(s32 *)(((u8 *)a0 + 8)));
    a0_s0 = (void *)(s32)(v0 + 0x30);
    v1 = (u32)a0_s0 << 3;
    v0 = (u32)MdlMng;
    SetObjTalkStart((void *)((u8 *)MdlMng + (s32)((u32)(s32)((u8 *)v1 - (u32)(a0_s0)) << 6)), *(s32
        *)(((u8 *)a0 + 0x10)), *(s32 *)(((u8 *)a0 + 0x18)), *(s32 *)(((u8 *)a0 + 0x20)));
    *(u32 *)a0 = 0;
    return;
}






/* SCR_SetObjTalkEnd @ 0x16C560 .. 0x16C5B0 (0x50 bytes, frame 0x20) */



static void SCR_SetObjTalkEnd(void *a0 /* r4 */) {
    u32 v0;
    s32 v1;
    void *a0_s0; // a0

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)1, *(s32 *)(((u8 *)a0 + 8)));
    a0_s0 = (void *)(s32)(v0 + 0x30);
    v1 = (u32)a0_s0 << 3;
    v0 = (u32)MdlMng;
    SetObjTalkEnd((void *)((u8 *)MdlMng + (s32)((u32)(s32)((u8 *)v1 - (u32)(a0_s0)) << 6)));
    *(u32 *)a0 = 0;
    return;
}


/* SCR_SetCaveFaceStart @ 0x16C510 .. 0x16C560 (0x50 bytes, frame 0x20) */



static void SCR_SetCaveFaceStart(void *a0 /* r4 */) {
    u32 v0;
    s32 v1;
    void *a0_s0; // a0

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)1, *(s32 *)(((u8 *)a0 + 8)));
    a0_s0 = (void *)(s32)(v0 + 0x30);
    v1 = (u32)a0_s0 << 3;
    v0 = (u32)MdlMng;
    SetObjCaveFaceStart((void *)((u8 *)MdlMng + (s32)((u32)(s32)((u8 *)v1 - (u32)(a0_s0)) << 6)));
    *(u32 *)a0 = 0;
    return;
}


/* SCR_SetObjFollowMe @ 0x16C4B0 .. 0x16C510 (0x60 bytes, frame 0x20) */



static void SCR_SetObjFollowMe(void *a0 /* r4 */) {
    u32 v0;
    s32 v1;
    void *a0_s0; // a0

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)1, *(s32 *)(((u8 *)a0 + 8)));
    a0_s0 = (void *)(s32)(v0 + 0x30);
    v1 = (u32)a0_s0 << 3;
    v0 = (u32)MdlMng;
    SetObjFollowTarget((void *)((u8 *)MdlMng + (s32)((u32)(s32)((u8 *)v1 - (u32)(a0_s0)) << 6)),
        *(u16 *)(((u8 *)a0 + 0x10)), *(u16 *)(((u8 *)a0 + 0x18)), (void *)(u8 *)((u8 *)MdlMng +
        0x11800));
    *(u32 *)a0 = 0;
    return;
}


/* SCR_FreeObjFollowMode @ 0x16C460 .. 0x16C4B0 (0x50 bytes, frame 0x20) */


static void SCR_FreeObjFollowMode(void *a0 /* r4 */) {
    u32 v0;
    s32 v1;
    void *a0_s0; // a0

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)1, *(s32 *)(((u8 *)a0 + 8)));
    a0_s0 = (void *)(s32)(v0 + 0x30);
    v1 = (u32)a0_s0 << 3;
    v0 = (u32)MdlMng;
    FreeObjFollowTarget((void *)((u8 *)MdlMng + (s32)((u32)(s32)((u8 *)v1 - (u32)(a0_s0)) << 6)));
    *(u32 *)a0 = 0;
    return;
}







/* SCR_SetObjPointLightOn_Ex @ 0x16C380 .. 0x16C458 (0xd8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1757 -> 0x22afa0
 *   fpu: float literal 0x3c888865 at 0x16c3c8
 *   stack: address of the slot at 0x30 escapes at 0x16c424
 *   literal: @1757 initializes the 16-byte local at 0x30
 */


static void SCR_SetObjPointLightOn_Ex(void *a0 /* r4 */) {
    u16 a0_narrow; // a0
    u16 a0_narrow_; // a0
    u8 *s1;
    float f0;
    u16 a0_narrow__; // a0
    u32 a0_s0_index; // a0
    u32 a0_s0_index_; // a0
    u32 v1;
    u32 v0;

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)1, *(s32 *)(((u8 *)a0 + 8)));
    a0_s0_index = v0 + 0x30;
    a0_s0_index_ = a0_s0_index * (u32)(7);
    v1 = (u32)MdlMng;
    s1 = (u8 *)((u8 *)MdlMng + (u32)(a0_s0_index * (u32)(0x1c0)));
    f0 = 0.0166666005f;
    *(u16 *)(s1 + 0x192) = SfxPLight_Create((0.0166666005f * (float)(float)((float)*(s32 *)(((u8
        *)a0 + 0x40)))));
    a0_narrow__ = *(u16 *)(s1 + 0x192);
    if ((u32)a0_narrow__ != (u32)0xffff) {
        SfxPLight_SetRadius(a0_narrow__, *(float *)(((u8 *)a0 + 0x28)));
        v0 = 0x22afa0;
        {
            struct stackFrame_30 { u8 b[16]; } stackFrame_30 __attribute__((aligned(16))) = {{0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
                0x3f}};
            *(f32 *)((u8 *)&stackFrame_30) = *(float *)(((u8 *)a0 + 0x10));
            *(f32 *)((u8 *)&stackFrame_30 + 0x4) = *(float *)(((u8 *)a0 + 0x18));
            *(f32 *)((u8 *)&stackFrame_30 + 0x8) = *(float *)(((u8 *)a0 + 0x20));
            a0_narrow = *(u16 *)(s1 + 0x192);
            SfxPLight_SetColor(a0_narrow, (float *)((u8 *)&stackFrame_30));
            a0_narrow_ = *(u16 *)(s1 + 0x192);
            SfxPLight_SetBlink(a0_narrow_, *(float *)(((u8 *)a0 + 0x30)), *(float *)(((u8 *)a0 +
                0x38)));
        }
    }
    *(u32 *)a0 = 0;
    return;
}


/* SCR_SetObjPointLightOff_Ex @ 0x16C2F0 .. 0x16C380 (0x90 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3c888865 at 0x16c348
 *   declaration vs inferred signature: return void vs inferred u32
 */


static void SCR_SetObjPointLightOff_Ex(void *a0 /* r4 */) {
    u16 a0_narrow; // a0
    void *a0_s0; // a0
    u8 *s1;
    u32 v1;
    s32 v0;

    v0 = GetMdlMngIndexByCtrlId((signed int)(void *)(s32)1, *(s32 *)(((u8 *)a0 + 8)));
    a0_s0 = (void *)MdlMng;
    s1 = (u8 *)((u8 *)MdlMng + (u32)((u32)(v0 + 0x30) * (u32)(0x1c0)));
    a0_narrow = *(u16 *)(s1 + 0x192);
    if ((u32)a0_narrow != (u32)0xffff) {
        SfxPLight_Delete(a0_narrow, (0.0166666005f * (float)(float)((float)*(s32 *)(((u8 *)a0 +
            0x10)))));
    }
    v1 = 0xffff;
    *(u16 *)(s1 + 0x192) = 0xffff;
    *(u32 *)a0 = 0;
    return;
}


/* SCR_SetSe2D @ 0x16C2B0 .. 0x16C2F0 (0x40 bytes, frame 0x20) */


static void SCR_SetSe2D(void *a0 /* r4 */) {
    s32 a1;
    u8 *s0;
    s32 a2;
    u32 v0;

    a1 = *(s16 *)(((u8 *)a0 + 0x10));
    s0 = (u8 *)a0;
    a2 = *(s16 *)(((u8 *)a0 + 0x18));
    a0 = (void *)*(s32 *)(((u8 *)a0 + 8));
    v0 = SND_Play2D((signed int)a0, a1, a2);
    a0 = (void *)(s32)((u8 *)s0 + 0x24);
    a1 = v0;
    fsScr_SetPointerData(a0, a1);
    *(u32 *)s0 = 0;
    return;
}









/* SCR_SetSe3DUsePoint @ 0x16C220 .. 0x16C2B0 (0x90 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return u32 vs inferred void; 0 parameters vs 1 inferred
 *   return without a value in a non-void function
 */

extern signed int SND_Play3D(signed int, signed short, signed short, void *, float);
extern signed int SND_Play3DPoint(signed int, signed short, signed short, float *, float);

u32 SCR_SetSe3DUsePoint(u8 *a0) {
    u8 *s0;
    s32 a2;
    s32 a1;
    float f12;
    u32 v0;
    u8 stackFrame_20[16] __attribute__((aligned(16)));

    v0 = 0x3f800000;
    *(f32 *)((u8 *)&stackFrame_20[0]) = *(float *)(a0 + 0x28);
    ((f32 *)stackFrame_20)[1] = *(float *)(a0 + 0x30);
    ((f32 *)stackFrame_20)[2] = *(float *)(a0 + 0x38);
    ((u32 *)stackFrame_20)[3] = 0x3f800000;
    v0 = *(s32 *)(a0 + 0x40);
    s0 = a0;
    if (v0 != 0) {
        a1 = *(s16 *)(s0 + 0x10);
        f12 = *(float *)(s0 + 0x20);
        a2 = *(s16 *)(s0 + 0x18);
        v0 = SND_Play3D(*(s32 *)(s0 + 8), a1, a2, (void *)(u8 *)((u8 *)&stackFrame_20[0]), f12);
    } else {
        a1 = *(s16 *)(s0 + 0x10);
        f12 = *(float *)(s0 + 0x20);
        a2 = *(s16 *)(s0 + 0x18);
        v0 = SND_Play3DPoint(*(s32 *)(s0 + 8), a1, a2, (float *)(u8 *)((u8 *)&stackFrame_20[0]),
            f12);
    }
    fsScr_SetPointerData((void *)(s0 + 0x44), v0);
    *(u32 *)s0 = 0;
    return;
}






/* SCR_SetSe3DUseModel @ 0x16C180 .. 0x16C218 (0x98 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: 0 parameters vs 1 inferred
 *   return without a value in a non-void function
 */




u32 SCR_SetSe3DUseModel(u8 *a0) {
    u8 *s0;
    s32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f12;

    s0 = a0;
    v0 = (u32)GetScriptMdlMng(*(s32 *)(a0 + 0x28), *(s32 *)(s0 + 0x30), 1);
    if (v0 == 0) {
        *(u32 *)s0 = 0;
    } else {
        v1 = *(s32 *)(s0 + 0x38);
        if (v1 != 0) {
            a1 = *(s16 *)(s0 + 0x10);
            f12 = *(float *)(s0 + 0x20);
            a2 = *(s16 *)(s0 + 0x18);
            v0 = SND_Play3D(*(s32 *)(s0 + 8), a1, a2, (void *)(s32)(v0 + 0x20), f12);
        } else {
            a1 = *(s16 *)(s0 + 0x10);
            f12 = *(float *)(s0 + 0x20);
            a2 = *(s16 *)(s0 + 0x18);
            v0 = SND_Play3DPoint(*(s32 *)(s0 + 8), a1, a2, (float *)(s32)(v0 + 0x20), f12);
        }
        fsScr_SetPointerData((void *)(s0 + 0x3c), v0);
        *(u32 *)s0 = 0;
    }
    return;
}








/* SCR_StopSe @ 0x16C150 .. 0x16C17C (0x2c bytes, frame 0x20) */


static void SCR_StopSe(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = (u32 *)*(u32 *)(((u8 *)a0 + 8));
    SND_Stop(a0);
    *(u32 *)s0 = 0;
    return;
}









/* SCR_SetEventMassSpiderStartRoom @ 0x16C120 .. 0x16C150 (0x30 bytes, frame 0x20) */


static void SCR_SetEventMassSpiderStartRoom(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = g_EtcEventMng;
    EtcEventMng_EneExtGeneEvent_Start_Room(g_EtcEventMng);
    *(u32 *)s0 = 0;
    return;
}


/* SCR_SetEventMassSpiderStartCorpse @ 0x16C0F0 .. 0x16C120 (0x30 bytes, frame 0x20) */


static void SCR_SetEventMassSpiderStartCorpse(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = g_EtcEventMng;
    EtcEventMng_EneExtGeneEvent_Start_Corpse(g_EtcEventMng);
    *(u32 *)s0 = 0;
    return;
}







/* SCR_SetEventMassSpiderEnd @ 0x16C0C0 .. 0x16C0F0 (0x30 bytes, frame 0x20) */


static void SCR_SetEventMassSpiderEnd(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = g_EtcEventMng;
    EtcEventMng_EneExtGeneEvent_End(g_EtcEventMng);
    *(u32 *)s0 = 0;
    return;
}


/* SCR_SetRiddle @ 0x16C090 .. 0x16C0BC (0x2c bytes, frame 0x20) */


static void SCR_SetRiddle(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = (u32 *)*(u32 *)(((u8 *)a0 + 8));
    SetRiddleMode(a0);
    *(u32 *)s0 = 0;
    return;
}








/* SCR_GetRiddleResult @ 0x16C050 .. 0x16C084 (0x34 bytes, frame 0x20) */


static void SCR_GetRiddleResult(void *a0 /* r4 */) {
    u32 *s0;
    u32 v0;

    s0 = (u32 *)a0;
    v0 = GetRiddleResult();
    a0 = (void *)(s32)((u8 *)s0 + 4);
    fsScr_SetPointerData(a0, v0);
    *(u32 *)s0 = 0;
    return;
}


/* SCR_SetSugorokuFlag @ 0x16C020 .. 0x16C044 (0x24 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */




static void SCR_SetSugorokuFlag(void *a0 /* r4 */) {
    u32 a1;
    u8 v1;

    a1 = *(s32 *)(((u8 *)a0 + 8));
    v1 = GameSt[0x22];
    GameSt[0x22] = (u32)(v1) | (u32)(a1 & 3);
    *(u32 *)a0 = 0;
    return;
}


/* SCR_SetSceneLoad @ 0x16BFF0 .. 0x16C020 (0x30 bytes, frame 0x20) */


static void SCR_SetSceneLoad(u8 *a0 /* r4 */) {
    u32 s0;
    u16 a1;

    s0 = (u32)a0;
    a1 = *(u16 *)((s0 + 0x10));
    a0 = (u8 *)*(u16 *)(((u8 *)a0 + 8));
    SetSceneLoad(a0, a1);
    *(u32 *)s0 = 0;
    return;
}






/* SCR_SetFrontEndDraw @ 0x16BFC0 .. 0x16BFEC (0x2c bytes, frame 0x20) */


static void SCR_SetFrontEndDraw(u32 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = (u32 *)*(u32 *)(((u8 *)a0 + 8));
    FECard_Enable_Draw(a0);
    *(u32 *)s0 = 0;
    return;
}






/* SCR_SetMovieLoad @ 0x16BF40 .. 0x16BFBC (0x7c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x20 escapes at 0x16bf5c
 *   stack: address of the slot at 0x20 escapes at 0x16bf90
 */


static void SCR_SetMovieLoad(void *a0 /* r4 */) {
    u8 *s0;

    s0 = (u8 *)a0;
    {
        u8 stackFrame_20[16] __attribute__((aligned(16))) = {0};
        SetFadeMng(7, (signed int *)((u8 *)&stackFrame_20[0]), 0x1e, (void *)0, (void *)0, 0, 0);
        SetFadeMovieLoad(*(s32 *)(s0 + 8), *(s32 *)(s0 + 0x10), *(s32 *)(s0 + 0x18));
        *(u32 *)s0 = 0;
        return;
    }
}






/* SCR_SetScriptHeartBeat @ 0x16BF10 .. 0x16BF3C (0x2c bytes, frame 0x20) */


static void SCR_SetScriptHeartBeat(u8 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = (u8 *)*(u8 *)(((u8 *)a0 + 8));
    SetScriptHeartBeat(a0);
    *(u32 *)s0 = 0;
    return;
}


/* SCR_SetMenuTD @ 0x16BED0 .. 0x16BF04 (0x34 bytes, frame 0x20) */


static void SCR_SetMenuTD(u32 *a0 /* r4 */) {
    u32 s0;
    u32 a1;

    s0 = (u32)a0;
    a0 = (u32 *)*(u32 *)(((u8 *)a0 + 8));
    a1 = *(u32 *)((s0 + 0x10));
    Menu_TD_CallOrder(a0, a1, 0);
    *(u32 *)s0 = 0;
    return;
}


/* SCR_GetGameLevel @ 0x16BE90 .. 0x16BEC4 (0x34 bytes, frame 0x20) */


static void SCR_GetGameLevel(u32 *a0 /* r4 */) {
    u8 a1;
    u32 s0;

    a1 = *(u8 *)((u8 *)&GameSt + 0x18);
    s0 = (u32)a0;
    a0 = (u32 *)(s0 + 4);
    fsScr_SetPointerData(a0, a1);
    *(u32 *)s0 = 0;
    return;
}


/* SCR_CheckItemMenuOpen @ 0x16BE30 .. 0x16BE84 (0x54 bytes, frame 0x20) */


static void SCR_CheckItemMenuOpen(void *a0 /* r4 */) {
    u32 *s0;
    u32 v0;

    s0 = (u32 *)a0;
    v0 = KnMenuMng_GetPlayMenu(7);
    if (v0 == 0) {
        fsScr_SetPointerData((void *)((u8 *)s0 + 4), 0);
    } else {
        fsScr_SetPointerData((void *)((u8 *)s0 + 4), 1);
    }
    *(u32 *)s0 = 0;
    return;
}






/* SCR_SetPadVib @ 0x16BD50 .. 0x16BE24 (0xd4 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x16bdf8
 */


static void SCR_SetPadVib(void *a0 /* r4 */) {
    u8 *s0;
    u32 a1;
    u32 a0_scalar; // a0
    float f13;
    float f12;
    float f1;
    float f0;
    s32 v1;

    v1 = 2;
    s0 = (u8 *)a0;
    a0_scalar = *(s32 *)(((u8 *)a0 + 8));
    a1 = 1;
    switch (a0_scalar) {
    case 0:
        f1 = ((float)*(s32 *)(s0 + 0x10));
        a0_scalar = GameSt[0xa];
        f0 = ((float)*(s32 *)(s0 + 0x18));
        f12 = f1;
        f13 = f0;
        PadSetVib(a0_scalar, f12, f13, 0, 0, 0);
        break;
    case 1:
        f1 = ((float)*(s32 *)(s0 + 0x10));
        a0_scalar = GameSt[0xa];
        f0 = ((float)*(s32 *)(s0 + 0x18));
        f12 = f1;
        f13 = f0;
        PadSetVib(a0_scalar, f12, f13, a1, 0, 0);
        break;
    case 2:
        f0 = ((float)*(s32 *)(s0 + 0x10));
        a0_scalar = GameSt[0xa];
        f13 = 1.0f;
        f12 = f0;
        PadSetVib(a0_scalar, f12, 1.0f, 0, 1, 0);
    }
    *(u32 *)s0 = 0;
    return;
}





/* SCR_CheckMenuTD @ 0x16BD10 .. 0x16BD44 (0x34 bytes, frame 0x20) */


static void SCR_CheckMenuTD(void *a0 /* r4 */) {
    u32 *s0;
    u32 v0;

    s0 = (u32 *)a0;
    v0 = Menu_TD_IsPlay();
    a0 = (void *)(s32)((u8 *)s0 + 4);
    fsScr_SetPointerData(a0, v0);
    *(u32 *)s0 = 0;
    return;
}






/* SCR_DebugPrint @ 0x16BD00 .. 0x16BD08 (0x8 bytes) */



static void SCR_DebugPrint(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}


/* CheckEventFlag @ 0x16BCB0 .. 0x16BCF8 (0x48 bytes) */
/*
 * dcomp notes:
 *   return: sltu at 0x16bcf4 computes the return value
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




signed int CheckEventFlag(signed int a0 /* r4 */) {
    u32 a1;
    u32 v0;

    v0 = (u32)GameEventFlag;
    a1 = *(u8 *)(u32)(s32)((u8 *)GameEventFlag + (u32)((s32)a0 / (s32)(8)));
    v0 = 1;
    v0 = (u32)v0 << (u32)((s32)a0 % (s32)(8));
    return (u32)(a1 & v0) != 0;
}


/* SetEventFlag @ 0x16BC60 .. 0x16BCAC (0x4c bytes) */



void SetEventFlag(signed int a0 /* r4 */) {
    u32 a2;
    s32 a1;
    u32 v1;

    a2 = (s32)a0 % (s32)(8);
    v1 = 1;
    v1 = v1 << a2;
    a2 = (u8)v1;
    a1 = (s32)a0 / (s32)(8);
    v1 = (u32)GameEventFlag;
    a0 = (s32)((u8 *)GameEventFlag + a1);
    v1 = *(u8 *)a0;
    v1 = v1 | a2;
    *(u8 *)a0 = v1;
    return;
}


/* ResetEventFlag @ 0x16BC10 .. 0x16BC60 (0x50 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */




void ResetEventFlag(signed int a0 /* r4 */) {
    u32 a2;
    s32 a1;
    u32 v1;

    a2 = (s32)a0 % (s32)(8);
    v1 = 1;
    v1 = v1 << a2;
    a2 = (u8)~v1;
    a1 = (s32)a0 / (s32)(8);
    v1 = (u32)GameEventFlag;
    a0 = (s32)((u8 *)GameEventFlag + a1);
    v1 = *(u8 *)a0;
    v1 = v1 & a2;
    *(u8 *)a0 = v1;
    return;
}


































































/* CheckEventFlag8 @ 0x16BBE0 .. 0x16BC04 (0x24 bytes) */
/*
 * dcomp notes:
 *   return: lbu at 0x16bc00 computes the return value
 */


u8 CheckEventFlag8(s32 a0 /* r4 */) {
    s32 v1;
    u8 *v0;

    v1 = (s32)a0 >> 3;
    if ((s32)a0 < 0) {
        v0 = (u8 *)(a0 + 7);
        v1 = (s32)v0 >> 3;
    }
    v0 = (u8 *)GameEventFlag;
    v0 = (u8 *)GameEventFlag + v1;
    return *(u8 *)v0;
}






/* SetEventFlag8 @ 0x16BBB0 .. 0x16BBD4 (0x24 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u8 * SetEventFlag8(s32 a0 /* r4 */, s32 a1 /* r5 */) {
    s32 a2;
    u8 *v1;

    a2 = (s32)a0 >> 3;
    if ((s32)a0 < 0) {
        v1 = (u8 *)(a0 + 7);
        a2 = (s32)v1 >> 3;
    }
    v1 = (u8 *)GameEventFlag;
    v1 = (u8 *)GameEventFlag + a2;
    *(u8 *)v1 = a1;
    return;
}







/* ClearEventFlag @ 0x16BB90 .. 0x16BBA4 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j memset at 0x16bb9c leaves the function
 */

extern void * memset(void *, int, unsigned int);

void ClearEventFlag(void) {
    memset((void *)GameEventFlag, 0, 0x100);
    return;
}





/* SetScriptDirect @ 0x16BB80 .. 0x16BB88 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j fsScr_ScriptStart at 0x16bb80 leaves the function
 *   return value dropped, call kept: the function is void
 */


void SetScriptDirect(void) {
    fsScr_ScriptStart();
    return;
}







/* GetScriptMdlMng @ 0x16BA80 .. 0x16BB80 (0x100 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void * vs inferred u32
 */

void * GetScriptMdlMng(s32 a0 /* r4 */, s32 a1 /* r5 */, s32 arg2) {
    u32 s0;
    s32 v1;
    u32 v0;

    v0 = 0xa;
    switch ((u32)a0) {
    case 0:
        s0 = (u32)(u8 *)(MdlMng + 0x11800);
        v0 = 0;
        break;
    case 1:
        a0 = 2;
        s0 = (u32)(u8 *)(MdlMng + 0x119c0);
        v0 = GetMdlMngIndexByCtrlId(a0, a1);
        break;
    case 3:
        s0 = (u32)MdlMng;
        v0 = GetMdlMngIndexByCtrlId(0, a1);
        break;
    case 4:
        a0 = 1;
        s0 = (u32)(u8 *)(MdlMng + 0x5400);
        v0 = GetMdlMngIndexByCtrlId(a0, a1);
        break;
    case 10:
        a0 = 7;
        s0 = (u32)(u8 *)(MdlMng + 0xfc00);
        v0 = GetMdlMngIndexByCtrlId(a0, a1);
        break;
    default:
        v0 = 0;
        return (void *)v0;
    }
    if ((s32)v0 < 0) {
        return (void *)(u32)0;
    } else {
        v1 = v0 << 3;
        v0 = v0 * 7;
        s0 = s0 + (u32)(v0 << 6);
        v0 = *(u8 *)s0;
        s0 = v0 != 0 ? (s32)s0 : (s32)0;
        v0 = s0;
    }
    return (void *)v0;
}

u8 GameEventFlag[0x100];
static u32 gpScrBuf;
