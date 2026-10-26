#include "common.h"


struct DmyPrm_s {
    u8 _p0[0x16];
    u16 f16;
    u16 f18;
    u32 _p1;
    u16 f20;
    u16 f22;
    u16 f24;
    u16 f26;
    u16 f28;
    u8 _p2[0x13e];
};




static void PlayDramaEtcCtrl(void *);
extern u32 lpDramaMng;

struct __copy_u_long128_1 { u_long128 b[1]; };
extern u32 lpDramaMng;
static u32 FreeDramaMdlMng(void);
extern void FreeDramaData(void);
extern u8 GameSt[];
extern void SetFadeMng(unsigned char, signed int *, signed int, void *, void *, signed int, signed
    int);
extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern signed int GetMapSfxHdl(signed int);
extern signed int SFX_EnableDraw(signed int, signed int, unsigned short);
extern signed int SFX_EnableAction(signed int, signed int, unsigned short);
extern void SetPointLightOff(signed int);
extern void SetPointLightOn(signed int, float *, float);
extern void SetBlurFilter(signed int);
extern signed int ItemMng_GetItemProc(signed int, signed int, signed int, signed int, signed int);
extern signed int KnMsgMng_SendMsgEx(signed int, signed int, int);
extern signed int PlayVoiceVagStm(signed int);
extern void SetVagStm3D(unsigned char, float *, float, void *);
extern void KnMsgMng_MsgClear();
extern void PlayGeneralVagStm(signed int);
extern void SetBlast(float, float, float *, float *, signed int);
extern void ReCalcMi3Matrix(void *);
extern void UpdateWorldMatrixInAnim(void *);
extern signed int CsMngStabilize(unsigned int, unsigned int);
extern void ClearFadedFilter();
extern void SfxPostEffect_SetEnable(unsigned short, signed int);
extern void SfxPostEffect_SetFlickerParam(void *);
extern void SetFog(float, float, signed int *);
extern void * GetDummyPolyData(void *, unsigned char, unsigned char);
extern signed int SFX_Create_OnDir_Attach(unsigned short, float *, float *, void *, unsigned short,
    unsigned char, unsigned char);
extern void SND_SetLoopSeVolumeScale(float);
extern void SetEventFlag(signed int);
extern void ResetEventFlag(signed int);
extern void SetScriptDirect(unsigned int);
extern u8 MdlMng[];
extern u32 V0[];
extern u32 VW[];
extern u32 VZ[];
extern void FreeMdlMng(void *);
extern void SetLightOff(void);
extern void SetMyLumpOn(void);
extern void SetMyDizzy(signed int);
extern void PadVibAllClear(void);
extern void StopVagStm(unsigned char);
extern void SetVagStmReverb(unsigned char, signed int);
extern void SND_SqFadeStart(int, int);
extern int sprintf(void *, void *, ...);
extern void *memset();
extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);
extern void EneDramaStartFunc(void);
static void PlayLastDramaFrameData(void);
int CheckDramaGameOver(void);
void CheckFreeDramaData(void);
static u32 SetDramaSkipFlag(void);
u8 GetDramaReadFlag(void);
int GetDramaFreeFlag(void);
void CheckDramaFreeFlag(void);
static void PlayDramaEtcCtrl(void *a0 /* r4 */);
void RemapDramaData(void *a0 /* r4 */);
void ReadDramaData(signed int a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */);
void InitDramaMng(void);

/* InitDramaMng @ 0x17B610 .. 0x17B620 (0x10 bytes) */
/*
 * dcomp notes:
 *   tail: j memset at 0x17b618 leaves the function
 *   return value dropped, call kept: the function is void
 */


void InitDramaMng(void) {
    u32 a0;

    a0 = lpDramaMng;
    memset(a0, 0, 0x18);
    return;
}






/* ReadDramaData @ 0x17B570 .. 0x17B60C (0x9c bytes, frame 0xc0) */
/*
 * dcomp notes:
 *   literal: @1972 is the string 'drama/s%04d_%02d.drm'
 *   stack: address of the slot at 0x40 escapes at 0x17b5a4
 *   stack: address of the slot at 0x40 escapes at 0x17b5d4
 */
#pragma pool_strings on
#pragma dont_reuse_strings off


void ReadDramaData(signed int a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */) {
    s32 s1;
    s32 s0;
    signed int a0_s2; // a0
    u8 *v0;
    signed int a2_2;
    u8 stackFrame_40[128] __attribute__((aligned(16)));

    s1 = a1;
    s0 = a2;
    PadVibAllClear();
    a1 = (signed int)"drama/s%04d_%02d.drm";
    sprintf((void *)((u8 *)&stackFrame_40[0]), (void *)"drama/s%04d_%02d.drm", (u32)(s32)a0,
        (u32)s1);
    a0_s2 = lpDramaMng;
    memset(a0_s2, 0, (u32)0x18);
    a2_2 = lpDramaMng;
    FileRead((char *)((u8 *)&stackFrame_40[0]), -1, (unsigned char **)a2_2, 0, s0, 0x15, 0);
    v0 = (u8 *)lpDramaMng;
    *(u8 *)(v0 + 0x10) = 1;
    v0 = (u8 *)lpDramaMng;
    *(u8 *)(v0 + 0x11) = s1;
    EneDramaStartFunc();
    return;
}







/* RemapDramaData @ 0x17B440 .. 0x17B568 (0x128 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0017B468
 *   cfg: loop body is not one contiguous region: .L0017B4A8
 *   cfg: loop body is not one contiguous region: .L0017B4E8
 *   cfg: loop body is not one contiguous region: .L0017B530
 *   v1#1 is the pointer held in a0+0xc
 *   declaration vs inferred signature: return void vs inferred u32
 */





void RemapDramaData(void *a0 /* r4 */) {
    u8 *a2;
    s32 a1;
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    v1 = *(s32 *)(a0_bytes + 0xc);
    a2 = (u8 *)(a0_bytes + 0x40);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0xc) = (s32)(a0_bytes + v1);
    }
    v1 = *(u16 *)(a0_bytes + 4);
    a1 = 0;
    if (0 < (s32)v1) {
        do {
            v1 = *(s32 *)(a2 + 0x84);
            if (v1 != 0) {
                *(u32 *)(a2 + 0x84) = (s32)(a0_bytes + v1);
            }
            v1 = *(u16 *)(a0_bytes + 4);
            a1 = a1 + 1;
            v1 = a1 < (s32)v1;
            a2 = (u8 *)(a2 + 0xa0);
        } while (v1 != 0);
    }
    v1 = *(u16 *)(a0_bytes + 6);
    a1 = 0;
    if (0 < (s32)v1) {
        do {
            v1 = *(s32 *)(a2 + 0x84);
            if (v1 != 0) {
                *(u32 *)(a2 + 0x84) = (s32)(a0_bytes + v1);
            }
            v1 = *(u16 *)(a0_bytes + 6);
            a1 = a1 + 1;
            v1 = a1 < (s32)v1;
            a2 = (u8 *)(a2 + 0xa0);
        } while (v1 != 0);
    }
    v1 = *(u16 *)(a0_bytes + 0xa);
    a1 = 0;
    if (0 < (s32)v1) {
        do {
            v1 = *(s32 *)(a2 + 0x84);
            if (v1 != 0) {
                *(u32 *)(a2 + 0x84) = (s32)(a0_bytes + v1);
            }
            v1 = *(u16 *)(a0_bytes + 0xa);
            a1 = a1 + 1;
            v1 = a1 < (s32)v1;
            a2 = (u8 *)(a2 + 0xa0);
        } while (v1 != 0);
    }
    v1 = *(u16 *)(a0_bytes + 8);
    a2 = (u8 *)*(s32 *)(a0_bytes + 0xc);
    a1 = 0;
    if (0 < (s32)v1) {
        do {
            v1 = *(s32 *)(a2 + 8);
            if (v1 != 0) {
                *(u32 *)(a2 + 8) = (s32)(a0_bytes + v1);
            }
            v1 = *(u16 *)(a0_bytes + 8);
            a1 = a1 + 1;
            v1 = a1 < (s32)v1;
            a2 = (u8 *)(a2 + 0x20);
        } while (v1 != 0);
    }
    return;
}








/* SetDramaData @ 0x17AE30 .. 0x17B434 (0x604 bytes, frame 0x90). */

extern void PadUpdate();
extern void * GetDramaCamInfo(signed int);
extern void RemapCamData(void *);
extern void SetEraseMapData(void *);
extern void RemapBinderFile(void *);
extern void SetMdlBndFile(signed int);
extern unsigned int SetMdlMng(void *, void *);
extern void sceVu0ScaleVectorXYZ(void *, void *, float);
extern void PlayMi3(void *);
extern void DssPlay4Init(void *);
extern signed int GetClothDataId(void *);
extern void SetMasterInitial(void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetHokanFrame(void *, float);
extern void MasterMove(void *);
extern signed int CsMngRtaSetMat(unsigned int, void *, int);
extern void * GetLightData(signed int);
extern void RemapLightData(void *);
extern void PlayBgmVagStm(signed int, signed int);
extern void SetMyLumpOff();
extern void StopHeartBeatSnd(void *);
extern void FECard_SetFade(unsigned char, signed int);
extern signed int TmpMenuMng_SetUDBlackDraw(void *, int);
extern void FECard_Enable_Draw(signed int);
extern void SfxFog_StartDrama(unsigned short, unsigned short);
extern u32 MdlData[];
static struct DmyPrm_s DmyDramaPrm;
extern u32 g_UnitMat[];
extern u32 L1138[];
extern u32 g_TmpMenuMng[];
extern u32 L1150[];

void SetDramaData(void) {
    u32 a1;
    register u32 s2;
    u8 *s1;
    u8 *s0;
    u32 a0;
    register u8 *s3;
    u32 v1;
    u32 v0;
    u8 *s4;
    u8 *modelParams;
    u32 heartBeatData;
    u8 *playerModel;
    float f12;
    float f1;
    float f0;
    struct __copy_u_long128_1 { u_long128 b[1]; };

    v0 = lpDramaMng;
    s1 = (u8 *)*(s32 *)v0;
    s0 = (u8 *)(s1 + 0x40);
    PadVibAllClear();
    PadUpdate();
    v0 = *(u16 *)(s1 + 4);
    s2 = 0;
    if (0 < (s32)v0) {
        do {
            a0 = *(s32 *)(s0 + 0x8c);
            v0 = (u32)GetDramaCamInfo(a0);
            s3 = (u8 *)v0;
            memset((u32)s3, 0, (s32)0x3010);
            v0 = *(s32 *)(s0 + 0x84);
            *(u32 *)s3 = v0;
            a0 = *(s32 *)s3;
            RemapCamData((void *)a0);
            SetEraseMapData((void *)s3);
            s2 = s2 + 1;
            s0 = (u8 *)(s0 + 0xa0);
        } while ((s32)s2 < (s32)*(u16 *)(s1 + 4));
    }
    v0 = *(u16 *)(s1 + 6);
    s2 = 0;
    if (0 < (s32)v0) {
        do {
            a0 = *(s32 *)(s0 + 0x8c);
            v1 = (u32)MdlData;
            s3 = (u8 *)((u8 *)MdlData + (u32)((u32)(a0 + 0x7c) * 0x680));
            *(u32 *)(s3 + 0x30) = *(u32 *)(s0 + 0x84);
            RemapBinderFile((void *)*(s32 *)(s3 + 0x30));
            v0 = *(s32 *)(s0 + 0x8c);
            SetMdlBndFile(v0 + 0x7c);
            v1 = *(s32 *)(s0 + 0x8c);
            v0 = (u32)MdlMng;
            s4 = (u8 *)((u8 *)MdlMng + (u32)((u32)(v1 + 0xdb) * 0x1c0));
            SetMdlMng((void *)s4, (void *)s3);
            v0 = *(s32 *)(s4 + 0xc);
            modelParams = (u8 *)*(s32 *)((v0 + 0x4c));
            if ((u32)(s32)modelParams == 0) {
                modelParams = (u8 *)&DmyDramaPrm;
                DmyDramaPrm.f16 = 0x5a;
                DmyDramaPrm.f18 = 0xa0;
                DmyDramaPrm.f20 = 0x64;
                DmyDramaPrm.f24 = 0x64;
                DmyDramaPrm.f28 = 0;
            }
            v0 = *(s32 *)(s4 + 0xc);
            *(u32 *)((v0 + 0x4c)) = (u32)modelParams;
            v0 = *(u16 *)(modelParams + 0x20);
            f0 = 100.0f;
            sceVu0ScaleVectorXYZ((void *)(s4 + 0x40), (void *)(s4 + 0x40), ((float)(float)v0 /
                100.0f));
            v0 = *(u16 *)(modelParams + 0x16);
            f1 = 100.0f;
            *(f32 *)(s4 + 0x110) = (((float)(float)v0 / 100.0f) * *(float *)(s4 + 0x40));
            v0 = *(u16 *)(modelParams + 0x18);
            f1 = 100.0f;
            *(f32 *)(s4 + 0x114) = (((float)(float)v0 / 100.0f) * *(float *)(s4 + 0x44));
            v0 = *(u16 *)(modelParams + 0x24);
            f1 = 100.0f;
            *(f32 *)(s4 + 0x118) = (((float)(float)v0 / 100.0f) * *(float *)(s4 + 0x40));
            v0 = *(u16 *)(modelParams + 0x28);
            f1 = 100.0f;
            *(f32 *)(s4 + 0x11c) = (((float)(float)v0 / 100.0f) * *(float *)(s4 + 0x40));
            PlayMi3((void *)s4);
            v0 = *(s32 *)((*(s32 *)(s4 + 0xc) + 0x48));
            if (v0 != 0) {
                DssPlay4Init((void *)s4);
            }
            v0 = GetClothDataId((void *)s4);
            if ((s32)v0 > 0) {
                SetMasterInitial((void *)s4);
                f12 = 0.0f;
                ChangeAnimParam((void *)s4, *(u16 *)(s4 + 0x104), 0.0f);
                SetMasterInitial((void *)s4);
                f12 = 0.0f;
                SetHokanFrame((void *)s4, 0.0f);
                MasterMove((void *)s4);
                a1 = (u32)g_UnitMat;
                CsMngRtaSetMat((s32)s4, (void *)g_UnitMat, 1);
                PlayMi3((void *)s4);
                CsMngStabilize((s32)s4, 0x1e);
            }
            *(u16 *)(s4 + 0x106) = 2;
            s2 = s2 + 1;
            v0 = *(u16 *)(s1 + 6);
            v0 = (s32)s2 < (s32)v0;
            s0 = (u8 *)(s0 + 0xa0);
        } while (v0 != 0);
    }
    v0 = *(u16 *)(s1 + 0xa);
    s2 = 0;
    if (0 < (s32)v0) {
        do {
            a0 = *(s32 *)(s0 + 0x8c);
            v0 = (u32)GetLightData(a0);
            s3 = (u8 *)v0;
            memset((u32)s3, 0, (s32)8);
            v0 = *(s32 *)(s0 + 0x84);
            *(u32 *)s3 = v0;
            a0 = *(s32 *)s3;
            RemapLightData((void *)a0);
            s2 = s2 + 1;
            s0 = (u8 *)(s0 + 0xa0);
        } while ((s32)s2 < (s32)*(u16 *)(s1 + 0xa));
    }
    v0 = (u32)L1138;
    f12 = 1.0f;
    {
        SetPointLightOn(1, (float[4]){1.0f, 0.9f, 0.5f, 0.0f}, 1.0f);
        GameSt[5] = 1;
        StopVagStm(0);
        StopVagStm(1);
        StopVagStm(2);
        StopVagStm(3);
        StopVagStm(4);
        SetVagStmReverb(0, 0);
        v0 = lpDramaMng;
        a1 = *(u8 *)((v0 + 0x11));
        a0 = GameSt[9];
        PlayBgmVagStm(a0, a1);
        SND_SqFadeStart(0, 0);
        SND_SqFadeStart(1, 0);
        f12 = 0.400000006f;
        SND_SetLoopSeVolumeScale(0.400000006f);
        playerModel = (u8 *)(MdlMng + 0x11800);
        *(u8 *)(playerModel + 2) = 1;
        SetMyLumpOff();
        StopHeartBeatSnd((void *)playerModel);
        heartBeatData = *(s32 *)(playerModel + 0x148);
        v0 = *(u8 *)((heartBeatData + 0x190));
        if (v0 != 0) {
            v0 = *(u16 *)((*(s32 *)((*(s32 *)(playerModel + 0xc) + 0x4c)) + 0x18));
            f1 = 100.0f;
            *(f32 *)(playerModel + 0x114) = (((float)(float)v0 / 100.0f) * *(float *)(playerModel + 0x44));
            FECard_SetFade(2, 1);
            *(u8 *)((heartBeatData + 0x190)) = 0;
        }
        v0 = *(u8 *)(s1 + 0x30);
        if (v0 == 0) {
            a0 = (u32)g_TmpMenuMng;
            TmpMenuMng_SetUDBlackDraw((void *)g_TmpMenuMng, 0);
        }
        FECard_Enable_Draw(0);
        {
            s32 Color[4] __attribute__((aligned(16))) = {0};
            v0 = *(u8 *)(s1 + 0x36);
            if (v0 != 0) {
                v0 = (u32)L1150;
                v1 = (u32)((u8 *)&Color[0]);
                *(struct __copy_u_long128_1 *)Color =
                    *(struct __copy_u_long128_1 *)(s32[4]){255, 255, 255, 0};
            }
            SetFadeMng(0, (signed int *)((u8 *)&Color[0]), 0x3c, (void *)0, (void *)0, 0, (signed
    int)0);
        }
        SetMyDizzy(0);
        v0 = *(u8 *)(s1 + 0x34);
        if (v0 != 0) {
            v0 = lpDramaMng;
            *(u8 *)((v0 + 0x14)) = 1;
            v1 = *(u8 *)(s1 + 0x35);
            v0 = lpDramaMng;
            *(u8 *)((v0 + 0x15)) = v1;
        }
        v0 = lpDramaMng;
        a1 = *(u8 *)((v0 + 0x11));
        a0 = GameSt[9];
        SfxFog_StartDrama(a0, a1);
        return;
    }
}






/* FreeDramaData @ 0x17AB80 .. 0x17AE28 (0x2a8 bytes, frame 0xe0) */
/*
 * dcomp notes:
 *   literal: @1972 is the string 'drama/s%04d_%02d.drm'
 *   stack: address of the slot at 0xd0 escapes at 0x17ac50
 *   fpu: float literal 0x41200000 at 0x17ac74
 *   fpu: float literal 0x41f00000 at 0x17ac78
 *   stack: address of the slot at 0xd0 escapes at 0x17ac7c
 *   stack: address of the slot at 0x40 escapes at 0x17ad14
 *   stack: address of the slot at 0x40 escapes at 0x17ad44
 *   delay: addiu at 0x17adb8 writes a register its branch at 0x17adb4 reads
 *   stack: address of the slot at 0xc0 escapes at 0x17adc4
 *   stack: address of the slot at 0xc0 escapes at 0x17adf8
 *   cfg: kept branch: 0x17ad70 if (..) goto .L0017AE00
 *   cfg: kept branch: 0x17ad84 if (..) goto .L0017AE00
 *   cfg: kept goto: 0x17ad94 -> .L0017AE00
 */

extern void FreeDramaCamData(void);
extern void FreeMdlData(void *, signed int);
extern void FreeLightData(void);
extern void MemFree(void *);
extern void SetMyControlOn(void);
extern signed int TmpMenuMng_SetUDBlackDraw(void *, int);
extern void FECard_Enable_Draw(signed int);
extern void SfxFog_EndDrama(void);
extern void EneDramaEndFunc(void);
extern void SetSceneLoad(unsigned short, unsigned short);
extern void SetGoToEndingFlag(void);
extern u32 CheckFadeType();
extern u32 g_TmpMenuMng[];

void FreeDramaData(void) {
    u32 a2;
    s32 s2;
    u32 s1;
    u32 a1;
    u32 s0;
    u32 a0;
    u32 v1;
    u32 v0;
    v0 = lpDramaMng;
    s1 = *(s32 *)v0;
    s0 = s1 + 0x40;
    FreeDramaCamData();
    a0 = *(u16 *)((s1 + 4));
    s2 = 0;
    v0 = *(u16 *)((s1 + 6));
    v1 = a0 * 0xa0;
    s0 = s0 + v1;
    if (0 < (s32)v0) {
        do {
            v1 = *(s32 *)((s0 + 0x8c));
            v0 = (u32)MdlMng;
            a0 = v1 + 0xdb;
            v1 = a0 * 0x1c0;
            v0 = (s32)((u8 *)MdlMng + v1);
            a0 = *(s32 *)((v0 + 0xc));
            FreeMdlData((void *)a0, 0);
            s2 = s2 + 1;
            s0 = s0 + 0xa0;
        } while (s2 < (s32)*(u16 *)((s1 + 6)));
    }
    FreeLightData();
    v0 = lpDramaMng;
    a0 = *(s32 *)v0;
    MemFree((void *)a0);
    KnMsgMng_MsgClear();
    SetMyControlOn();
    a1 = 1;
    a0 = (u32)g_TmpMenuMng;
    TmpMenuMng_SetUDBlackDraw((void *)g_TmpMenuMng, a1);
    a0 = 1;
    FECard_Enable_Draw(a0);
    {
        s32 stackFrame_D0[4] __attribute__((aligned(16))) = {0};
        SetFog(10.0f, 30.0f, (signed int *)stackFrame_D0);
    }
    {
    struct {
        u8 filename[128];
        s32 fade[4];
    } stackFrames __attribute__((aligned(16)));
    SfxFog_EndDrama();
    SfxPostEffect_SetEnable(0, 0);
    EneDramaEndFunc();
    v0 = *(u8 *)((lpDramaMng + 0x17));
    if (v0 == 0) {
        v1 = *(u8 *)((s1 + 0x32));
        if (v1 != 0 || *(u8 *)((s1 + 0x33)) != 0) {
            a1 = *(u8 *)((s1 + 0x33));
            SetSceneLoad((u8)v1, a1);
        }
        a0 = lpDramaMng;
        v0 = *(u8 *)((a0 + 0x14));
        if (v0 != 0) {
            s1 = *(u8 *)((a0 + 0x15));
            memset(a0, 0, (s32)0x18);
            s0 = GameSt[9];
            PadVibAllClear();
            sprintf((void *)((u8 *)&stackFrames.filename[0]), (void *)"drama/s%04d_%02d.drm",
                s0, s1);
            a0 = lpDramaMng;
            memset(a0, 0, (s32)0x18);
            a2 = lpDramaMng;
            FileRead((char *)((u8 *)&stackFrames.filename[0]), -1, (unsigned char **)a2, 0, 1, (signed
                int)0x15, 0);
            v0 = lpDramaMng;
            *(u8 *)((v0 + 0x10)) = 1;
            v0 = lpDramaMng;
            *(u8 *)((v0 + 0x11)) = s1;
            EneDramaStartFunc();
        } else {
            v1 = GameSt[9];
            v0 = 0x25;
            if (v1 != v0) {
                goto _L0017AE00;
            }
            v1 = *(u8 *)(((u8 *)a0 + 0x11));
            v0 = 7;
            if (v1 != v0) {
                goto _L0017AE00;
            }
            SetGoToEndingFlag();
            goto _L0017AE00;
        }
    } else {
        v0 = CheckFadeType();
        v1 = 5;
        if (v0 == v1) {
            v1 = (u32)((u8 *)&stackFrames.fade[0]);
            __asm__ volatile(
                ".set noreorder\n"
                ".word 0x10600008\n"
                "addiu %1, $zero, 0x10\n"
                "0:\n"
                "sb $zero, 0(%0)\n"
                "addiu %1, %1, -1\n"
                "addiu %0, %0, 1\n"
                "nop\n"
                "nop\n"
                ".word 0x1440fffa\n"
                "nop\n"
                "1:\n"
                ".set reorder\n"
                : "+r"(v1), "=&r"(v0)
                :
                : "memory");
            SetFadeMng(0, (signed int *)((u8 *)&stackFrames.fade[0]), 0x3c, (void *)0, (void *)0, 0,
                (signed
    int)0);
        }
        _L0017AE00:;
        a0 = lpDramaMng;
        memset(a0, 0, (u32)0x18);
    }
    }
    return;
}


#pragma dont_reuse_strings reset
#pragma pool_strings reset





/* FreeDramaMdlMng @ 0x17AA50 .. 0x17AB7C (0x12c bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x17ab58
 *   declaration vs inferred signature: return u32 vs inferred void
 *   return without a value in a non-void function
 */


static u32 FreeDramaMdlMng(void) {
    s32 s2;
    u32 a0;
    u8 *s1;
    u32 v1;
    u8 *s0;
    u32 v0;

    s2 = 0;
    v0 = lpDramaMng;
    s1 = (u8 *)*(s32 *)v0;
    a0 = *(u16 *)(s1 + 4);
    s0 = (u8 *)(s1 + 0x40);
    v0 = *(u16 *)(s1 + 6);
    s0 = (s0 + (u32)(a0 * (u32)(0xa0)));
    if (0 < (s32)v0) {
        do {
            v1 = *(s32 *)(s0 + 0x8c);
            v0 = (u32)MdlMng;
            FreeMdlMng((void *)((u8 *)MdlMng + (u32)((u32)(v1 + 0xdb) * (u32)(0x1c0))));
            v0 = *(u16 *)(s1 + 6);
            s2 = s2 + 1;
            v0 = s2 < (s32)v0;
            s0 = (u8 *)(s0 + 0xa0);
        } while (v0 != 0);
    }
    SetLightOff();
    MdlMng[0x11802] = 0;
    SetMyLumpOn();
    SetMyDizzy(1);
    SetBlurFilter(0);
    GameSt[0x13] = 0;
    GameSt[0x12] = 0;
    PadVibAllClear();
    StopVagStm(0);
    StopVagStm(1);
    StopVagStm(2);
    StopVagStm(3);
    StopVagStm(4);
    SetVagStmReverb(0, 1);
    SND_SqFadeStart(0, 2);
    SND_SqFadeStart(1, 2);
    SND_SetLoopSeVolumeScale(1.0f);
    return;
}








/* PlayDrama @ 0x17A620 .. 0x17AA50 (0x430 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x17a670
 *   delay: addiu at 0x17a6d4 writes a register its branch at 0x17a6d0 reads
 *   stack: address of the slot at 0x50 escapes at 0x17a6f4
 *   stack: address of the slot at 0x50 escapes at 0x17a72c
 *   stack: address of the slot at 0x40 escapes at 0x17a74c
 *   stack: address of the slot at 0x40 escapes at 0x17a784
 *   fpu: float literal 0x3f800000 at 0x17a858
 *   fpu: mtc1 reinterprets v1 at 0x17a878
 *   fpu: mtc1 reinterprets a0 at 0x17a890
 *   delay: addiu at 0x17a8e0 writes a register its branch at 0x17a8dc reads
 *   fpu: float literal 0x3f800000 at 0x17aa28
 *   cfg: loop body is not one contiguous region: .L0017A988
 */

static void PlayDramaFrameData(void *);
extern void SetGameOver(void);
extern signed int TmpMenuMng_SetUDBlackDraw(void *, int);
extern void UpdateLightAnim(signed int);
extern void MasterMove(void *);
extern void * GetDramaCamInfo(signed int);
extern void UpdateCamAnim(void *, void *);
extern u32 lpPadData;
extern u32 g_TmpMenuMng[];

void PlayDrama(void) {
    s32 a2;
    u32 a1;
    u8 *s2;
    u32 s1;
    u32 s0;
    u32 a0;
    float f1;
    float f0;
    u32 v1;
    u32 v0;

    a1 = lpDramaMng;
    v1 = GameSt[0xf];
    s2 = (u8 *)*(s32 *)a1;
    s1 = *(s32 *)(s2 + 0xc);
    s0 = 0;
    if (v1 == 0 && *(u8 *)((a1 + 0x16)) == 0) {
        a0 = *(u16 *)((a1 + 0xc));
        v1 = a0 << 5;
        s1 = s1 + v1;
        if (a0 == 0) {
            f1 = *(float *)((a1 + 4));
            f0 = 0.0f;
            a0 = s1;
            if (0.0f == f1) {
                PlayDramaFrameData((void *)a0);
                s0 = 1;
            }
        }
        a0 = GameSt[0xa];
        v1 = (u32)&lpPadData;
        a1 = lpDramaMng;
        a0 = a0 << 2;
        a0 = (s32)((u8 *)&lpPadData + (u32)a0);
        v1 = *(u8 *)((a1 + 0x12));
        a0 = *(s32 *)a0;
        if (v1 == 0) {
            v1 = *(u8 *)((a0 + 0x20)) | *(u8 *)((a0 + 0x10));
            if ((v1 & 0x08u) != 0) {
                v1 = *(u8 *)((*(s32 *)a1 + 0x31));
                if (v1 != 0) {
                    v1 = 1;
                    *(u8 *)((a1 + 0x13)) = v1;
                } else {
                    v0 = *(u8 *)((a1 + 0x14));
                    if (v0 != 0) {
                        {
                            u8 stackFrame_50[16] __attribute__((aligned(16))) = {0};
                            a0 = 5;
                            a2 = 0x1e;
                            SetFadeMng(a0, (signed int *)((u8 *)&stackFrame_50[0]), a2, (void *)0,
                                SetDramaSkipFlag, 0, (signed
    int)0);
                        }
                    } else {
                        {
                            u8 stackFrame_40[16] __attribute__((aligned(16))) = {0};
                            a0 = 4;
                            a2 = 0x50;
                            SetFadeMng(a0, (signed int *)((u8 *)&stackFrame_40[0]), a2,
                                SetDramaSkipFlag, (void *)0, 0x1e, (signed
    int)0x32);
                        }
                    }
                }
                v1 = lpDramaMng;
                a0 = 1;
                *(u8 *)((v1 + 0x12)) = a0;
            }
        }
        a0 = lpDramaMng;
        v1 = *(u8 *)((a0 + 0x13));
        if (v1 != 0) {
            PlayLastDramaFrameData();
            v0 = *(u8 *)(s2 + 0x31);
            if (v0 != 0) {
                v0 = lpDramaMng;
                v1 = 1;
                *(u8 *)((v0 + 0x16)) = v1;
                SetGameOver();
                a1 = 1;
                a0 = (u32)g_TmpMenuMng;
                TmpMenuMng_SetUDBlackDraw((void *)g_TmpMenuMng, a1);
            } else {
                v0 = lpDramaMng;
                v1 = 1;
                *(u8 *)((v0 + 0xf)) = v1;
                FreeDramaMdlMng();
            }
            return;
        }
        a1 = 1;
        *(f32 *)((a0 + 8)) = *(float *)((a0 + 4));
        v1 = GameSt[5];
        {
            u32 selected;
            if (v1 == a1 && *(u8 *)(lpDramaMng + 0xe) != 0) selected=a1;
            else selected=0;
            a1=selected;
        }
        if (a1 == 0) {
            a0 = lpDramaMng;
            v1 = 0x3f800000;
            f0 = 1.0f;
            *(f32 *)((a0 + 4)) = (*(float *)((a0 + 4)) + f0);
        }
        a1 = lpDramaMng;
        f1 = *(float *)((a1 + 4));
        f0 = (float)(u32)*(u16 *)((s1 + 4));
        if (!(f1 <= f0)) {
            v1 = *(u16 *)((a1 + 0xc));
            v1 = v1 + 1;
            *(u16 *)((a1 + 0xc)) = v1;
            a1 = lpDramaMng;
            v1 = *(u16 *)(s2 + 8);
            a0 = *(u16 *)((a1 + 0xc));
            if (a0 == v1 && *(u8 *)((a1 + 0xf)) == 0) {
                a0 = a1 + 0xf;
                v0 = *(u8 *)(s2 + 0x31);
                if (v0 != 0) {
                    v0 = 1;
                    *(u8 *)((a1 + 0x16)) = v0;
                    SetGameOver();
                    a1 = 1;
                    a0 = (u32)g_TmpMenuMng;
                    TmpMenuMng_SetUDBlackDraw((void *)g_TmpMenuMng, a1);
                } else {
                    v0 = 1;
                    *(u8 *)a0 = v0;
                    FreeDramaMdlMng();
                }
                return;
            }
            *(u32 *)((a1 + 4)) = 0;
            s1 = s1 + 0x20;
            v1 = lpDramaMng;
            *(f32 *)((v1 + 8)) = *(float *)((v1 + 4));
        }
        a0 = lpDramaMng;
        v1 = *(u16 *)(s2 + 8);
        a0 = *(u16 *)((a0 + 0xc));
        if ((s32)a0 < (s32)v1) {
            a0 = s1;
            if (s0 == 0) {
                PlayDramaFrameData((void *)a0);
            }
            v0 = lpDramaMng;
            a0 = *(u16 *)((v0 + 0xc));
            UpdateLightAnim(a0);
            s0 = (u32)(u8 *)(MdlMng + 0x17f40);
            v0 = (u32)(u8 *)(MdlMng + 0x1a240);
            if (s0 != v0) {
                do {
                    v0 = *(u8 *)s0;
                    if (v0 != 0 && (u32)*(s32 *)*(s32 *)((s0 + 0xc)) != 0) {
                        MasterMove((void *)s0);
                    }
                    s0 = s0 + 0x1c0;
                } while ((u8 *)s0 != (u8 *)(MdlMng + 0x1a240));
            }
            v0 = lpDramaMng;
            a0 = *(u16 *)((v0 + 0xc));
            v0 = (u32)GetDramaCamInfo(a0);
            s0 = v0;
            UpdateCamAnim((void *)s0, (void *)0);
            a0 = 1;
            v1 = GameSt[5];
            {
                u32 selected;
                if (v1 == a0 && *(u8 *)(lpDramaMng + 0xe) != 0) selected=a0;
                else selected=0;
                a0=selected;
            }
            if (a0 == 0) {
                v1 = 0x3f800000;
                f0 = 1.0f;
                *(f32 *)(((u8 *)s0 + 8)) = (*(float *)(((u8 *)s0 + 8)) + f0);
            }
        }
    }
    return;
}








































extern void SetCamEnv(void *, signed int);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetMasterInitial(void *);

typedef struct { u8 _p[2]; u16 count; u32 _p2; u8 *recs; } FD;

static void PlayDramaFrameData(void *a0 /* r4 */) {
    FD *lpDramaCut = (FD *)a0;
    s32 i;
    s32 skip;
    u8 *lpFrameHead;
    u8 *lpFrameCam;
    u8 *lpFrameMdl;
    u8 *lpFrameEtc;
    u8 *mng;
    u32 start;

    lpFrameHead = lpDramaCut->recs;
    for (i = 0; i < lpDramaCut->count; i++) {
        mng = (u8 *)lpDramaMng;
        start = *(u16 *)(lpFrameHead + 4);
        skip = 1;
        if (*(float *)(mng + 8) < (float)start && !(*(float *)(mng + 4) < (float)start)) {
            skip = 0;
        } else if (!(*(float *)(mng + 4) < (float)start) &&
                   *(float *)(mng + 4) < (float)((s32)(u16)start + *(u16 *)(lpFrameHead + 6) + (*(u16 *)(lpFrameHead + 6) == 0))) {
            skip = 0;
        }
        switch (*lpFrameHead) {
        case 0:
            lpFrameCam = lpFrameHead + 0x10;
            if (skip == 0) {
                u8 *info = (u8 *)GetDramaCamInfo(*(u16 *)(mng + 0xc));
                u32 v;
                *(u32 *)(info + 4) = *(u16 *)lpFrameCam;
                v = *(u16 *)(lpFrameCam + 2);
                *(float *)(info + 8) = (float)v;
                SetCamEnv(info, *(s32 *)(info + 4));
            }
            lpFrameHead = lpFrameCam + 0x10;
            break;
        case 1: {
            u8 *mdl;
            lpFrameMdl = lpFrameHead + 0x10;
            if (skip == 0) {
                mdl = MdlMng + (*(u16 *)(lpFrameMdl + 4) + 0xdb) * 0x1c0;
                switch (*lpFrameMdl) {
                case 0:
                    *(u16 *)(mdl + 0x106) = 0;
                    ChangeAnimParam(mdl, *(u16 *)(lpFrameMdl + 6), 0.0f);
                    SetMasterInitial(mdl);
                    UpdateWorldMatrixInAnim(mdl);
                    break;
                case 1:
                    mdl[2] = (*(u16 *)(lpFrameMdl + 6) != 0) ^ 1;
                    break;
                }
            }
            lpFrameHead = lpFrameMdl + 0x10;
            break;
        }
        case 2:
            lpFrameEtc = lpFrameHead + 0x10;
            if (skip == 0) {
                PlayDramaEtcCtrl(lpFrameEtc);
            }
            lpFrameHead = lpFrameEtc + 0x10;
            break;
        }
    }
}


/* PlayDramaEtcCtrl @ 0x179810 .. 0x17A384 (0xb74 bytes, frame 0xe0) */
/*
 * dcomp notes:
 *   literal: @1697 -> 0x253c40
 *   literal: @1307 -> 0x22b150
 *   literal: @1330 -> 0x22b160
 *   literal: @1339 -> 0x22b170
 *   literal: @1373 -> 0x22b180
 *   indirect: jr v1 at 0x179844 -> <v1>
 *   delay: addiu at 0x17985c writes a register its branch at 0x179858 reads
 *   stack: address of the slot at 0xc0 escapes at 0x179868
 *   delay: lui at 0x179890 writes a register its branch at 0x17988c reads
 *   stack: address of the slot at 0x60 escapes at 0x1798b0
 *   stack: address of the slot at 0xc0 escapes at 0x1798b0
 *   stack: address of the slot at 0xc0 escapes at 0x1798cc
 *   stack: address of the slot at 0xb0 escapes at 0x179974
 *   fpu: mtc1 reinterprets v0 at 0x17999c
 *   fpu: mtc1 reinterprets v1 at 0x1799b0
 *   fpu: float literal 0x42c80000 at 0x1799c4
 *   fpu: mtc1 reinterprets v0 at 0x1799e4
 *   fpu: mtc1 reinterprets v1 at 0x1799f8
 *   fpu: float literal 0x42c80000 at 0x179a0c
 *   fpu: mtc1 reinterprets v0 at 0x179a2c
 *   fpu: mtc1 reinterprets v1 at 0x179a40
 *   fpu: float literal 0x42c80000 at 0x179a58
 *   fpu: mtc1 reinterprets v0 at 0x179a80
 *   fpu: mtc1 reinterprets v1 at 0x179a94
 *   fpu: float literal 0x42c80000 at 0x179aac
 *   stack: address of the slot at 0xb0 escapes at 0x179ac0
 *   delay: addiu at 0x179b14 writes a register its branch at 0x179b10 reads
 *   stack: address of the slot at 0xa0 escapes at 0x179b20
 *   delay: lui at 0x179b48 writes a register its branch at 0x179b44 reads
 *   stack: address of the slot at 0x50 escapes at 0x179b68
 *   stack: address of the slot at 0xa0 escapes at 0x179b68
 *   stack: address of the slot at 0xa0 escapes at 0x179b80
 *   delay: addiu at 0x179b9c writes a register its branch at 0x179b98 reads
 *   stack: address of the slot at 0x90 escapes at 0x179ba8
 *   delay: lui at 0x179bd0 writes a register its branch at 0x179bcc reads
 *   stack: address of the slot at 0x40 escapes at 0x179bf0
 *   stack: address of the slot at 0x90 escapes at 0x179bf0
 *   stack: address of the slot at 0x90 escapes at 0x179c08
 *   delay: daddu at 0x179c9c writes a register its branch at 0x179c98 reads
 *   fpu: mtc1 reinterprets a3 at 0x179cdc
 *   fpu: mtc1 reinterprets a0 at 0x179cf4
 *   fpu: float literal 0x42c80000 at 0x179d0c
 *   fpu: float literal 0x447a0000 at 0x179d2c
 *   fpu: mtc1 reinterprets v0 at 0x179d7c
 *   fpu: mtc1 reinterprets v1 at 0x179d90
 *   fpu: float literal 0x42c80000 at 0x179da8
 *   fpu: float literal 0x3cf5c28f at 0x179df4
 *   fpu: float literal 0x42f00000 at 0x179dfc
 *   delay: addiu at 0x179e9c writes a register its branch at 0x179e98 reads
 *   stack: address of the slot at 0x80 escapes at 0x179ea8
 *   delay: lui at 0x179ed0 writes a register its branch at 0x179ecc reads
 *   stack: address of the slot at 0x30 escapes at 0x179ef0
 *   stack: address of the slot at 0x80 escapes at 0x179ef0
 *   stack: address of the slot at 0x80 escapes at 0x179f08
 *   fpu: mtc1 reinterprets v0 at 0x179f6c
 *   fpu: mtc1 reinterprets v1 at 0x179f80
 *   fpu: float literal 0x42c80000 at 0x179f94
 *   fpu: mtc1 reinterprets v0 at 0x179fb4
 *   fpu: mtc1 reinterprets v1 at 0x179fc8
 *   fpu: float literal 0x42c80000 at 0x179fdc
 *   fpu: mtc1 reinterprets v0 at 0x179ffc
 *   fpu: mtc1 reinterprets v1 at 0x17a010
 *   fpu: float literal 0x42c80000 at 0x17a028
 *   stack: address of the slot at 0xd0 escapes at 0x17a03c
 *   stack: address of the slot at 0x70 escapes at 0x17a05c
 *   fpu: mtc1 reinterprets v0 at 0x17a084
 *   fpu: mtc1 reinterprets v1 at 0x17a098
 *   fpu: float literal 0x42c80000 at 0x17a0b0
 *   fpu: mtc1 reinterprets v0 at 0x17a0cc
 *   fpu: mtc1 reinterprets v1 at 0x17a0e4
 *   fpu: float literal 0x42c80000 at 0x17a0fc
 *   fpu: mtc1 reinterprets v0 at 0x17a118
 *   fpu: mtc1 reinterprets v1 at 0x17a130
 *   fpu: float literal 0x43000000 at 0x17a148
 *   fpu: float literal 0x42c80000 at 0x17a14c
 *   fpu: mtc1 reinterprets v0 at 0x17a178
 *   fpu: mtc1 reinterprets v1 at 0x17a18c
 *   fpu: float literal 0x43000000 at 0x17a1a4
 *   fpu: float literal 0x42c80000 at 0x17a1a8
 *   fpu: mtc1 reinterprets v0 at 0x17a1d4
 *   fpu: mtc1 reinterprets v1 at 0x17a1e8
 *   fpu: float literal 0x43000000 at 0x17a200
 *   fpu: float literal 0x42c80000 at 0x17a208
 *   stack: address of the slot at 0x70 escapes at 0x17a220
 *   fpu: mtc1 reinterprets v0 at 0x17a2d4
 *   fpu: mtc1 reinterprets v1 at 0x17a2e8
 *   fpu: float literal 0x42c80000 at 0x17a2fc
 *   literal: @1373 initializes the 16-byte local at 0x30
 *   literal: @1339 initializes the 16-byte local at 0x40
 *   literal: @1330 initializes the 16-byte local at 0x50
 *   literal: @1307 initializes the 16-byte local at 0x60
 *   cfg: kept goto: 0x17a264 -> .L0017A2A8
 *   declaration vs inferred signature: return void vs inferred u_long128
 */



static void PlayDramaEtcCtrl(void *a0 /* r4 */) {
    u8 SfxFlicker[16] __attribute__((aligned(16)));
    u8 *lpFrameEtc;
    int MapSfxHdl;
    int MsgId;
    int track;
    u8 *lpMdlMng;
    float Range;
    int ObjMdlIndex;
    u8 *lpObj;
    float *lpPos;
    float *lpDir;
    u8 *lpDmyPoly;
    u16 ObjectId;
    float near;
    float far;
    u32 flag;

    lpFrameEtc = (u8 *)a0;
    switch (*(u8 *)lpFrameEtc) {
    case 0:
        if (*(u8 *)(lpDramaMng + 0x12) == 0) {
            int Color[4] = {0};
            if (*(u8 *)(lpFrameEtc + 2) == 1) {
                *(struct __copy_u_long128_1 *)Color = *(struct __copy_u_long128_1 *)(int[4]){255, 255, 255, 0};
            }
            SetFadeMng(2, Color, *(u16 *)(lpFrameEtc + 4), 0, 0, *(u16 *)(lpFrameEtc + 6), *(u16 *)(lpFrameEtc + 4) - *(u16 *)(lpFrameEtc + 8));
        }
        break;
    case 1:
        GameSt[0x13] = *(u8 *)(lpFrameEtc + 1);
        break;
    case 2:
        ObjMdlIndex = GetMdlMngIndexByCtrlId(1, *(u16 *)(lpFrameEtc + 4));
        *(u8 *)(MdlMng + (ObjMdlIndex + 0x30) * 0x1c0 + 2) = !*(u8 *)(lpFrameEtc + 1);
        break;
    case 3:
        MapSfxHdl = GetMapSfxHdl(*(u16 *)(lpFrameEtc + 4));
        SFX_EnableDraw(MapSfxHdl, *(u8 *)(lpFrameEtc + 1), 0);
        SFX_EnableAction(MapSfxHdl, *(u8 *)(lpFrameEtc + 1), 0);
        break;
    case 4:
        {
            float Col[4] = {(float)(u32)*(u16 *)(lpFrameEtc + 4) / 100.0f, (float)(u32)*(u16 *)(lpFrameEtc + 6) / 100.0f, (float)(u32)*(u16 *)(lpFrameEtc + 8) / 100.0f};
            SetPointLightOff(1);
            SetPointLightOn(1, Col, (float)(u32)*(u16 *)(lpFrameEtc + 0xa) / 100.0f);
        }
        break;
    case 5:
        if (*(u8 *)(lpFrameEtc + 1) != 0 && *(u8 *)(lpFrameEtc + 2) != 0) {
            SetBlurFilter(2);
        } else {
            SetBlurFilter(*(u8 *)(lpFrameEtc + 1));
        }
        break;
    case 6:
        if (*(u8 *)(lpDramaMng + 0x12) == 0) {
            int Color[4] = {0};
            if (*(u8 *)(lpFrameEtc + 1) == 1) {
                *(struct __copy_u_long128_1 *)Color = *(struct __copy_u_long128_1 *)(int[4]){255, 255, 255, 0};
            }
            SetFadeMng(1, Color, *(u16 *)(lpFrameEtc + 4), 0, 0, 0, 0);
        }
        break;
    case 7:
        if (*(u8 *)(lpDramaMng + 0x12) == 0) {
            int Color[4] = {0};
            if (*(u8 *)(lpFrameEtc + 1) == 1) {
                *(struct __copy_u_long128_1 *)Color = *(struct __copy_u_long128_1 *)(int[4]){255, 255, 255, 0};
            }
            SetFadeMng(0, Color, *(u16 *)(lpFrameEtc + 4), 0, 0, 0, 0);
        }
        break;
    case 8:
        ItemMng_GetItemProc(*(u16 *)(lpFrameEtc + 4), *(u16 *)(lpFrameEtc + 8), -1, -1, *(u16 *)(lpFrameEtc + 6));
        break;
    case 9:
        MsgId = *(u16 *)(lpFrameEtc + 4) + (GameSt[9] / 10 * 10000 + 400000);
        KnMsgMng_SendMsgEx(MsgId, 0, 1);
        if (*(u8 *)(lpFrameEtc + 1) == 1) {
            track = PlayVoiceVagStm(MsgId);
            if (*(u16 *)(lpFrameEtc + 6) != 0x63) {
                lpMdlMng = MdlMng + (*(u16 *)(lpFrameEtc + 6) + 0xdb) * 0x1c0;
                Range = (float)(u32)*(u16 *)(lpFrameEtc + 8) / 100.0f;
                if (*(u16 *)(lpFrameEtc + 8) == 0) {
                    Range = 1000.0f;
                }
                SetVagStm3D(track, (float *)V0, Range, lpMdlMng);
            }
        }
        break;
    case 10:
        KnMsgMng_MsgClear();
        break;
    case 11:
        PlayGeneralVagStm(*(u16 *)(lpFrameEtc + 6));
        if (*(u16 *)(lpFrameEtc + 4) != 0x63) {
            SetVagStm3D(5, (float *)V0, (float)(u32)*(u16 *)(lpFrameEtc + 8) / 100.0f, MdlMng + (*(u16 *)(lpFrameEtc + 4) + 0xdb) * 0x1c0);
        }
        break;
    case 12:
        SetBlast(0.0299999993f, 120.0f, (float *)(MdlMng + (*(u16 *)(lpFrameEtc + 4) + 0xdb) * 0x1c0 + 0x20), (float *)(MdlMng + (*(u16 *)(lpFrameEtc + 6) + 0xdb) * 0x1c0 + 0x20), 0);
        break;
    case 13:
        lpMdlMng = MdlMng + (*(u16 *)(lpFrameEtc + 4) + 0xdb) * 0x1c0;
        ReCalcMi3Matrix(lpMdlMng);
        UpdateWorldMatrixInAnim(lpMdlMng);
        CsMngStabilize((unsigned int)lpMdlMng, *(u16 *)(lpFrameEtc + 6));
        break;
    case 14:
        if (*(u8 *)(lpDramaMng + 0x12) == 0) {
            int Color[4] = {0};
            if (*(u8 *)(lpFrameEtc + 1) == 1) {
                *(struct __copy_u_long128_1 *)Color = *(struct __copy_u_long128_1 *)(int[4]){255, 255, 255, 0};
            }
            SetFadeMng(5, Color, *(u16 *)(lpFrameEtc + 4), 0, 0, 0, 0);
        }
        break;
    case 15:
        GameSt[0x12] = *(u8 *)(lpFrameEtc + 1);
        if (GameSt[0x12] != 0) {
            ClearFadedFilter();
        }
        break;
    case 16:
        SfxPostEffect_SetEnable(0, *(u8 *)(lpFrameEtc + 1));
        if (*(u8 *)(lpFrameEtc + 1) != 0) {
            ((f32 *)SfxFlicker)[0] = (float)(u32)*(u16 *)(lpFrameEtc + 4) / 100.0f;
            ((f32 *)SfxFlicker)[1] = (float)(u32)*(u16 *)(lpFrameEtc + 6) / 100.0f;
            ((f32 *)SfxFlicker)[2] = (float)(u32)*(u16 *)(lpFrameEtc + 8) / 100.0f;
            SfxPostEffect_SetFlickerParam(SfxFlicker);
        }
        break;
    case 17:
        {
            int FogCol[4] = {0};
            near = (float)(u32)*(u16 *)(lpFrameEtc + 0xa) / 100.0f;
            far = (float)(u32)*(u16 *)(lpFrameEtc + 0xc) / 100.0f;
            FogCol[0] = (s32)(128.0f * (float)(u32)*(u16 *)(lpFrameEtc + 4) / 100.0f);
            FogCol[1] = (s32)(128.0f * (float)(u32)*(u16 *)(lpFrameEtc + 6) / 100.0f);
            FogCol[2] = (s32)(128.0f * (float)(u32)*(u16 *)(lpFrameEtc + 8) / 100.0f);
            SetFog(near, far, FogCol);
        }
        break;
    case 18:
        ObjMdlIndex = GetMdlMngIndexByCtrlId(1, *(u16 *)(lpFrameEtc + 4));
        lpObj = MdlMng + (ObjMdlIndex + 0x30) * 0x1c0;
        if (*(u16 *)(lpFrameEtc + 6) == 0xff) {
            lpPos = (float *)VW;
            lpDir = (float *)VZ;
            ObjectId = 0;
        } else {
            lpDmyPoly = GetDummyPolyData((void *)*(s32 *)(lpObj + 0xc), 0, *(u16 *)(lpFrameEtc + 6));
            if (lpDmyPoly == 0) {
                break;
            }
            lpPos = (float *)lpDmyPoly;
            lpDir = (float *)(lpDmyPoly + 0x10);
            ObjectId = *(u16 *)(lpDmyPoly + 0x20);
        }
        SFX_Create_OnDir_Attach(*(u16 *)(lpFrameEtc + 8), lpPos, lpDir, lpObj, ObjectId, 0, 0);
        break;
    case 19:
        SND_SetLoopSeVolumeScale((float)(u32)*(u16 *)(lpFrameEtc + 4) / 100.0f);
        break;
    case 20:
        flag = *(u16 *)(lpFrameEtc + 4);
        if (flag != 0) {
            SetEventFlag((u16)flag);
        }
        flag = *(u16 *)(lpFrameEtc + 6);
        if (flag != 0) {
            ResetEventFlag((u16)flag);
        }
        break;
    case 21:
        flag = *(u16 *)(lpFrameEtc + 4);
        if (flag != 0) {
            SetScriptDirect((u16)flag);
        }
        break;
    }
}



/* CheckDramaFreeFlag @ 0x1797D0 .. 0x179804 (0x34 bytes, frame 0x10) */


void CheckDramaFreeFlag(void) {
    u32 v1;

    v1 = *(u8 *)((lpDramaMng + 0xf));
    if (v1 != 0) {
        FreeDramaData();
        GameSt[5] = 0;
    }
    return;
}

















/* GetDramaFreeFlag @ 0x1797C0 .. 0x1797CC (0xc bytes) */
/*
 * dcomp notes:
 *   return: lbu at 0x1797c8 computes the return value
 *   repo declaration vs inferred signature: return int vs inferred u8
 */


int GetDramaFreeFlag(void) {
    u8 *v0;

    v0 = (u8 *)lpDramaMng;
    return *(u8 *)(((u8 *)v0 + 0xf));
}


/* GetDramaReadFlag @ 0x1797B0 .. 0x1797BC (0xc bytes) */
/*
 * dcomp notes:
 *   return: lbu at 0x1797b8 computes the return value
 */


u8 GetDramaReadFlag(void) {
    u8 *v0;

    v0 = (u8 *)lpDramaMng;
    return *(u8 *)(((u8 *)v0 + 0x10));
}



/* SetDramaSkipFlag @ 0x1797A0 .. 0x1797B0 (0x10 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


static u32 SetDramaSkipFlag(void) {
    u8 *v1;

    v1 = (u8 *)lpDramaMng;
    *(u8 *)(((u8 *)v1 + 0x13)) = 1;
    return;
}


/* CheckFreeDramaData @ 0x179760 .. 0x17979C (0x3c bytes, frame 0x10) */


void CheckFreeDramaData(void) {
    u32 v1;

    v1 = *(s32 *)(u8 *)lpDramaMng;
    if (v1 != 0) {
        *(u8 *)(((u8 *)(u8 *)lpDramaMng + 0x17)) = 1;
        FreeDramaMdlMng();
        FreeDramaData();
    }
    return;
}











/* CheckDramaGameOver @ 0x179750 .. 0x179760 (0x10 bytes) */
/*
 * dcomp notes:
 *   return: sltu at 0x17975c computes the return value
 *   repo declaration vs inferred signature: return int vs inferred u32
 */


int CheckDramaGameOver(void) {
    u32 v0;

    v0 = lpDramaMng;
    v0 = *(u8 *)((v0 + 0x16));
    return (u32)v0 != 0;
}







/* PlayLastDramaFrameData @ 0x179660 .. 0x179744 (0xe4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1796cc writes a register its branch at 0x1796c8 reads
 *   cfg: loop body is not one contiguous region: .L001796B0
 */

static void PlayLastDramaFrameData(void) {
    u32 a2;
    s32 s2;
    u8 *a1;
    u32 a0;
    u32 s1;
    u8 *s3;
    u32 v1;
    u16 s0;

    v1 = lpDramaMng;
    v1 = *(s32 *)v1;
    s1 = *(s32 *)((v1 + 0xc));
    v1 = *(u16 *)((v1 + 8));
    v1 = v1 + -1;
    v1 = v1 << 5;
    s1 = s1 + v1;
    v1 = *(u16 *)((s1 + 2));
    a0 = *(u16 *)((s1 + 4));
    a1 = (u8 *)*(s32 *)((s1 + 8));
    s2 = 0;
    if (0 < (s32)v1) {
        s0 = a0;
        do {
            v1 = *(u16 *)(a1 + 4);
            a2 = 1;
            if ((u32)s0 == v1) {
                a2 = 0;
            }
            a0 = *(u8 *)a1;
            v1 = 2;
            switch (a0) {
            case 0:
                a1 = (u8 *)(a1 + 0x20);
                break;
            case 1:
                a1 = (u8 *)(a1 + 0x20);
                break;
            case 2:
                s3 = (u8 *)(a1 + 0x10);
                if (a2 == 0) {
                    a0 = (s32)s3;
                    PlayDramaEtcCtrl((void *)a0);
                }
                a1 = (u8 *)(s3 + 0x10);
            }
            v1 = *(u16 *)((s1 + 2));
            s2 = s2 + 1;
            v1 = s2 < (s32)v1;
        } while (v1 != 0);
    }
    return;
}

static struct DmyPrm_s DmyDramaPrm;
static u32 DramaMng[0x6];
u32 lpDramaMng = (u32)&DramaMng;
