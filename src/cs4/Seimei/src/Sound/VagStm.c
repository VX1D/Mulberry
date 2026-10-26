#include "common.h"




extern void fssdivagSetTrackReverb(u8);
extern u32 VagStmMng[];
extern void fssdivagSetVolumePack(u8 *, s32);
extern void sceVu0CopyVector(void *, void *);
extern int sprintf(char *, const char *, ...);
signed int SetUpVagStm(char *fname, unsigned char track, signed int stream);
extern signed int SetUpVagStm(char *, unsigned char, signed int);
extern u8 GameSt[];
extern u32 BgmVol;
extern u32 VoiceVol;
extern void fssdivagUpdateTrackStat(void);
extern u32 fssdivagGetReserveSetupResult(u32);
void StopVagStm(unsigned char track);
extern void StopVagStm(unsigned char);
void PlayVagStm(u32 arg);
extern void PlayVagStm(unsigned int);
static void UpdateVagStmFade(unsigned char a0 );
static void UpdateVagStmFade(unsigned char);
static void UpdateVagStm3D(unsigned char track);
static void UpdateVagStm3D(unsigned char);
extern u32 fssdivagGetTrackStat(u32);
extern void fssdivagPause(u8);
extern void fssdivagStop(s32);
extern void fsmfstrm_DetachFileSector(s32);
extern void *memset();
extern void fssdivagInit(void);
extern void fssdivagSetPacket(s32);
extern void fssdivagSetSpuMemory(s32, s32);
extern void fssdivagSetCoreVoice(s32);
extern void fssdivagSetDmaChannel(s32);
extern void fssdivagSetPlayStartCallBack(u32);
extern void fssdivagSetPlayEndCallBack(u32);
extern void fssdivagSetMasterVolume(s32, s32);
void SetVagStmReverb(unsigned char a0 , signed int arg1);
void SetVagStmReverb(unsigned char a0 /* r4 */, signed int arg1);
signed int CheckVagStmState(unsigned char a0 );
signed int CheckVagStmState(unsigned char a0 /* r4 */);
static void UpdateVolumePack(void);
static void UpdateVolumePack(void);
void SetVagStm3D(unsigned char a0 , float *arg1 , float f12 , void *a2 );
void SetVagStm3D(unsigned char a0 /* r4 */, float *arg1 /* r5 */, float f12 /* f12 */, void *a2 /*
        r6 */);
void PlayGeneralVagStm(int id);
void PlayGeneralVagStm(int id);
void PlayBgmVagStm(signed int area, signed int track);
void PlayBgmVagStm(signed int area, signed int track);
unsigned short GetVagMasterVolume(unsigned char a0 );
unsigned short GetVagMasterVolume(unsigned char a0 /* r4 */);
signed int CheckVagStmFade(unsigned char a0 );
signed int CheckVagStmFade(unsigned char a0 /* r4 */);
void UpdateVagStm(void);
void UpdateVagStm(void);
void PauseVagStm(unsigned char track);
void PauseVagStm(unsigned char track);
void StopVagStm(unsigned char track);
static void VagStmEndCallBack(void);
static void VagStmEndCallBack(void);
static void VagStmStartCallBack(void);
static void VagStmStartCallBack(void);
u32 InitVagStm(void);
u32 InitVagStm(void);

u32 VagStmMng[0x138];
static u32 BgmVol;
static u32 VoiceVol;
static s32 UseVoiceTrack;










extern u32 fssdivagGetChNum(u32);
extern void fssdivagPlay(u32);
extern void fssdivagSetChVolume(u32,u32,u32,u32);
s32 SetVagStmFade();
extern s32 SetVagStmFade();
extern u32 g_pSndMng;


struct dw_1862101_fields;
#ifndef PROTO_DW_1865031_FIELDS
#define PROTO_DW_1865031_FIELDS
struct dw_1865031_fields { float Pos[4]; unsigned char FileName[128]; int StmIndex; int State; int NextState; unsigned char FadeType; unsigned char FadeReserve; unsigned char b3DStm; unsigned char Channel; int Timer; int VolStep; int Vol; int MaxVol; float MaxDist; float NowDist; float DistRate; int Pan; int LastPan; float Ang; struct dw_1862101_fields *lpMdlMng; int Frame; };
#endif

/* SetUpVagStm @ 0x1AE0C0 .. 0x1AE48C (0x3cc bytes, frame 0x180) */

extern char * strcpy(char *, const char *);
extern void StringCorrectPath4Disc(char *, signed int);
extern char * SearchFileName(char *);
extern void GetAllBindInfo(char *, unsigned int *, unsigned int *);
extern u32 fsmfstrm_AttachSector(s32, s32, s32, s32);
extern void fssdivagReserveSetup(u32, s32);
/* UpdateVagStmFade @ 0x1AD3E0 .. 0x1AD740 (0x360 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @2699 -> 0x2553b0
 *   delay: addiu at 0x1ad434 writes a register its branch at 0x1ad430 reads
 *   indirect: jr v1 at 0x1ad45c -> <v1>
 *   delay: addiu at 0x1ad560 writes a register its branch at 0x1ad55c reads
 *   delay: andi at 0x1ad578 writes a register its branch at 0x1ad574 reads
 *   fpu: float literal 0x4f000000 at 0x1ad5b8
 *   fpu: mtc1 reinterprets v0 at 0x1ad5fc
 *   fpu: float literal 0x4f000000 at 0x1ad6d0
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 L2699[];

#ifndef PROTO_DW_1870941_FIELDS
#define PROTO_DW_1870941_FIELDS
struct dw_1870941_fields { float (*fvListenerPosPtr)[4]; float (*fvListenerAngPtr)[4]; float (*fmListenerMatPtr)[4][4]; };
#endif
#ifndef PROTO_DW_1870113_FIELDS
#define PROTO_DW_1870113_FIELDS
struct dw_1870113_fields { float panlim; float zofs; char dopp; char pad[3]; float range; char reserved[16]; };
#endif
#ifndef PROTO_DW_1865960_FIELDS
#define PROTO_DW_1865960_FIELDS
struct dw_1865960_fields { short sCalcedVol; char bid; char sid; char PlayId; char reserv[3]; int sq_fade; int sq_vol; };
#endif
#ifndef PROTO_DW_1869263_FIELDS
#define PROTO_DW_1869263_FIELDS
struct dw_1869263_fields { unsigned short usFreq; unsigned char ucLoop; char cDmy[1]; };
#endif
#ifndef PROTO_DW_1869861_FIELDS
#define PROTO_DW_1869861_FIELDS
struct dw_1869861_fields { unsigned int uiProgNum; char cDmy[12]; struct dw_1869263_fields aParam[128]; };
#endif
#ifndef PROTO_DW_1872395_FIELDS
#define PROTO_DW_1872395_FIELDS
struct dw_1872395_fields { struct dw_1870941_fields Listener; struct dw_1870113_fields Param; signed char SndMode; unsigned char bfMasterVolume : 1; unsigned char bfReserv : 7; unsigned char ucMasterVolume; unsigned char ucBgmVolume; unsigned char ucSqVolume; unsigned char ucSeVolume; unsigned short usVolumeFadeOutFrame; char rid[8]; unsigned short ucVoiceCnt; unsigned char _pad0[2]; int Handle[12]; struct dw_1865960_fields aSqSong[4]; unsigned char calloff; unsigned char _pad1[3]; struct dw_1869861_fields aBankInfo[12]; unsigned short aaIdTable[12][128]; unsigned int uiUseVoiceNum; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1865031_FIELDS_CHANNEL_02843EC4_DEFINED
#define DCOMP_OFF_STRUCT_DW_1865031_FIELDS_CHANNEL_02843EC4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1865031_FIELDS_CHANNEL_02843EC4 = (int)&(((struct dw_1865031_fields *)0)->Channel) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1865031_FIELDS_DISTRATE_A17AA8E6_DEFINED
#define DCOMP_OFF_STRUCT_DW_1865031_FIELDS_DISTRATE_A17AA8E6_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1865031_FIELDS_DISTRATE_A17AA8E6 = (int)&(((struct dw_1865031_fields *)0)->DistRate) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADERESERVE_B45AD192_DEFINED
#define DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADERESERVE_B45AD192_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADERESERVE_B45AD192 = (int)&(((struct dw_1865031_fields *)0)->FadeReserve) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADETYPE_F49EA64B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADETYPE_F49EA64B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADETYPE_F49EA64B = (int)&(((struct dw_1865031_fields *)0)->FadeType) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1865031_FIELDS_MAXVOL_9B79CAB0_DEFINED
#define DCOMP_OFF_STRUCT_DW_1865031_FIELDS_MAXVOL_9B79CAB0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1865031_FIELDS_MAXVOL_9B79CAB0 = (int)&(((struct dw_1865031_fields *)0)->MaxVol) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1865031_FIELDS_STATE_E2C2DD60_DEFINED
#define DCOMP_OFF_STRUCT_DW_1865031_FIELDS_STATE_E2C2DD60_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1865031_FIELDS_STATE_E2C2DD60 = (int)&(((struct dw_1865031_fields *)0)->State) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1865031_FIELDS_TIMER_CE6EAFB5_DEFINED
#define DCOMP_OFF_STRUCT_DW_1865031_FIELDS_TIMER_CE6EAFB5_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1865031_FIELDS_TIMER_CE6EAFB5 = (int)&(((struct dw_1865031_fields *)0)->Timer) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1865031_FIELDS_VOL_E7300CFF_DEFINED
#define DCOMP_OFF_STRUCT_DW_1865031_FIELDS_VOL_E7300CFF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1865031_FIELDS_VOL_E7300CFF = (int)&(((struct dw_1865031_fields *)0)->Vol) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1865031_FIELDS_VOLSTEP_80FB0EBB_DEFINED
#define DCOMP_OFF_STRUCT_DW_1865031_FIELDS_VOLSTEP_80FB0EBB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1865031_FIELDS_VOLSTEP_80FB0EBB = (int)&(((struct dw_1865031_fields *)0)->VolStep) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1865031_FIELDS_B3DSTM_F9BBCDF9_DEFINED
#define DCOMP_OFF_STRUCT_DW_1865031_FIELDS_B3DSTM_F9BBCDF9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1865031_FIELDS_B3DSTM_F9BBCDF9 = (int)&(((struct dw_1865031_fields *)0)->b3DStm) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1872395_FIELDS_SNDMODE_FEEB8698_DEFINED
#define DCOMP_OFF_STRUCT_DW_1872395_FIELDS_SNDMODE_FEEB8698_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1872395_FIELDS_SNDMODE_FEEB8698 = (int)&(((struct dw_1872395_fields *)0)->SndMode) - 0 };
#endif
















/* PlayVoiceVagStm @ 0x1ACEE0 .. 0x1AD03C (0x15c bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   literal: @2532 is the string 'vag/v%06d.adx'
 *   literal: @2533 is the string 'vag/v%06de.adx'
 *   stack: address of the slot at 0x20 escapes at 0x1acf2c
 *   stack: address of the slot at 0x20 escapes at 0x1acf48
 *   cfg: loop body is not one contiguous region: .L001ACF70
 *   cfg: kept branch: 0x1acf70 if (..) goto .L001ACF90
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




#ifndef PROTO_DW_1865031_FIELDS
#define PROTO_DW_1865031_FIELDS

#endif
#ifndef PROTO_DW_1876911_FIELDS
#define PROTO_DW_1876911_FIELDS
struct dw_1876911_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1865031_FIELDS_STATE_E2C2DD60_DEFINED
#define DCOMP_OFF_STRUCT_DW_1865031_FIELDS_STATE_E2C2DD60_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1876911_FIELDS_VOICELANGUAGE_55350583_DEFINED
#define DCOMP_OFF_STRUCT_DW_1876911_FIELDS_VOICELANGUAGE_55350583_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1876911_FIELDS_VOICELANGUAGE_55350583 = (int)&(((struct dw_1876911_fields *)0)->VoiceLanguage) - 0 };
#endif


extern float atanf(float);
extern float atan2f(float, float);
extern float sqrtf(float);
extern float g_fSndScaleFactor;
extern u32 lpDrawMng;
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern float sceVu0InnerProduct(void *, void *);






/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 InitVagStm(void);
static void VagStmStartCallBack(void);
static void VagStmEndCallBack(void);
signed int SetUpVagStm(char *fname, unsigned char track, signed int stream);
void PlayVagStm(u32 arg);
void StopVagStm(unsigned char track);
void PauseVagStm(unsigned char track);
void UpdateVagStm(void);
s32 SetVagStmFade();
static void UpdateVagStmFade(unsigned char a0 );
signed int CheckVagStmFade(unsigned char a0 );
void SetVagMasterVolume(unsigned char a0 , unsigned short a1 );
unsigned short GetVagMasterVolume(unsigned char a0 );
void PlayBgmVagStm(signed int area, signed int track);
signed int PlayVoiceVagStm(signed int id);
void PlayGeneralVagStm(int id);
void SetVagStm3D(unsigned char a0 , float *arg1 , float f12 , void *a2 );
static void UpdateVagStm3D(unsigned char track);
static void UpdateVolumePack(void);
signed int CheckVagStmState(unsigned char a0 );
void SetVagStmReverb(unsigned char a0 , signed int arg1);


/* InitVagStm @ 0x1AE4B0 .. 0x1AE57C (0xcc bytes, frame 0x10) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001AE540
 *   cfg: kept branch: 0x1ae548 if (..) goto .L001AE558
 *   cfg: kept goto: 0x1ae550 -> .L001AE560
 *   return without a value in a non-void function
 */


u32 InitVagStm(void) {
    u32 a0;
    s32 a1;
    s32 v0;
    s32 a2;
    s32 t0;
    u8 *a3;
    s32 v1;

    fssdivagInit();
    a0 = 0x1000;
    fssdivagSetPacket(a0);
    fssdivagSetSpuMemory(0x1e0000, 0x10000);
    a0 = 0x28;
    fssdivagSetCoreVoice(a0);
    a0 = 1;
    fssdivagSetDmaChannel(a0);
    a0 = (u32)VagStmStartCallBack;
    fssdivagSetPlayStartCallBack((u32)VagStmStartCallBack);
    a0 = (u32)VagStmEndCallBack;
    fssdivagSetPlayEndCallBack((u32)VagStmEndCallBack);
    a0 = 0x3fff;
    a1 = a0;
    fssdivagSetMasterVolume(a0, a1);
    v0 = 0x3fff;
    a0 = (u32)VagStmMng;
    BgmVol = v0;
    VoiceVol = v0;
    a2 = 0x4e0;
    memset((u32)VagStmMng, 0, a2);
    t0 = 0;
    a3 = (u8 *)VagStmMng;
    a2 = 5;
    a0 = 1;
    a1 = 2;
    do {
        if ((u32)t0 != 0) {
            if ((u32)t0 != (u32)a2) {
                goto _L001AE558;
            }
        }
        *(u8 *)(((u8 *)a3 + 0x9f)) = a1;
        goto _L001AE560;
        _L001AE558:;
        *(u8 *)(((u8 *)a3 + 0x9f)) = a0;
        _L001AE560:;
        t0 = t0 + 1;
        v1 = (u32)t0 < (u32)6;
        a3 = (u8 *)(s32)((u8 *)a3 + 0xd0);
    } while ((u32)v1 != 0);
    return;
}






/* VagStmStartCallBack @ 0x1AE4A0 .. 0x1AE4A8 (0x8 bytes) */



static void VagStmStartCallBack(void) {
    return;
}






/* VagStmEndCallBack @ 0x1AE490 .. 0x1AE498 (0x8 bytes) */




static void VagStmEndCallBack(void) {
    return;
}


signed int SetUpVagStm(char *fname, unsigned char track, signed int stream) {
    char FullPath[128];
    int TrackStat;
    int PlayReserveFlag;
    unsigned int lsn;
    unsigned int size;
    char TmpStr[128];
    struct dw_1865031_fields *stm;
    float f;
    u32 left;
    u32 right;

    PlayReserveFlag = 0;
    stm = &((struct dw_1865031_fields *)VagStmMng)[track];
    switch (stm->State) {
    case 0:
        break;
    case 1:
        PlayReserveFlag = 1;
        break;
    default:
        return 0;
    }
    TrackStat = fssdivagGetTrackStat(track);
    if (TrackStat != 0) {
        if (stm->NextState != 1) {
            strcpy((char *)stm->FileName, fname);
            stm->StmIndex = stream;
            stm->State = 1;
            stm->NextState = 1;
            stm->FadeReserve = 0;
            stm->Timer = 0;
        }
        return 0;
    }
    stm->FadeReserve = 0;
    stm->Timer = 0;
    strcpy(TmpStr, fname);
    StringCorrectPath4Disc(TmpStr, 0);
    strcpy(FullPath, SearchFileName(TmpStr));
    GetAllBindInfo(FullPath, &lsn, &size);
    if (size == 0) return 0;
    if (fsmfstrm_AttachSector(stream, lsn, size, 0x30) == 0) return 0;
    fssdivagReserveSetup(track, stream);
    strcpy((char *)stm->FileName, FullPath);
    stm->StmIndex = stream;
    stm->State = 2;
    switch (track) {
    case 0:
        stm->MaxVol = BgmVol;
        stm->Vol = BgmVol;
        break;
    case 5:
        stm->MaxVol = BgmVol;
        stm->Vol = BgmVol;
        stm->Channel = 2;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        stm->MaxVol = VoiceVol;
        stm->Vol = VoiceVol;
        break;
    default:
        stm->MaxVol = 0;
        stm->Vol = 0;
    }
    stm->DistRate = 1.0f;
    stm->Pan = 0;
    stm->LastPan = 0;
    stm->Frame = 0;
    if (stm->Channel == 2) {
        f = (float)stm->Vol * stm->DistRate;
        left = (u16)(u32)f;
        right = (u16)(u32)(float)f;
        if (*(u8 *)((u8 *)g_pSndMng + 0x2c) != 0) {
            fssdivagSetChVolume(track, 0, left, 0);
            fssdivagSetChVolume(track, 1, 0, right);
        } else {
            fssdivagSetChVolume(track, 0, left, right);
            fssdivagSetChVolume(track, 1, left, right);
        }
    } else if (stm->Channel == 1) {
        f = (float)stm->Vol * stm->DistRate;
        fssdivagSetChVolume(track, 0, (u16)(u32)f, (u16)(u32)f);
    }
    if (PlayReserveFlag != 0) {
        switch (stm->State) {
        case 0:
        case 4:
            break;
        default:
            stm->State = 3;
        }
    }
    return 1;
}
void PlayVagStm(u32 arg) {
    u32 saved;
    u32 left;
    u32 right;
    u8 *stream;
    u32 track;
    saved=arg;
    track=(u8)arg;
    stream=(u8 *)VagStmMng+track*208;
    switch(*(u32 *)(stream+0x94)) {
    case 0:return;
    case 1:return;
    case 4:return;
    default: {
        u32 status=fssdivagGetTrackStat(track);
        if(status!=3 && status!=5)return;
        if(status!=5)stream[0x9f]=fssdivagGetChNum(track);
        fssdivagPlay(track);
        *(u32 *)(stream+0x94)=4;
        if(stream[0x9f]==2) {
            float volume=(float)*(s32 *)(stream+0xa8)**(float *)(stream+0xb8);
            left=(u16)(u32)volume;
            right=(u16)(u32)(float)volume;
            if(*(u8 *)(g_pSndMng+0x2c)!=0) {
                fssdivagSetChVolume(track,0,left,0);
                fssdivagSetChVolume(track,1,0,right);
            } else {
                fssdivagSetChVolume(track,0,left,right);
                fssdivagSetChVolume(track,1,left,right);
            }
        } else if(stream[0x9f]==1) {
            u32 volume=(u16)(u32)((float)*(s32 *)(stream+0xa8)**(float *)(stream+0xb8));
            fssdivagSetChVolume(track,0,volume,volume);
        }
        if(stream[0x9d]!=0)SetVagStmFade(saved,stream[0x9c],*(s32 *)(stream+0xa0));
        else *(u32 *)(stream+0xa0)=0;
    }
    }
}





void StopVagStm(unsigned char track) {
    s32 index;
    u32 base;
    u32 state;
    u8 *lpVagMng;
    u32 value;

    base = (u32)VagStmMng;
    state = 6;
    index = (s32)((u32)track << 1);
    index += (u32)track;
    index = (s32)((u32)index << 2);
    index += (u32)track;
    index = (s32)((u32)index << 4);
    lpVagMng = (u8 *)(base + index);
    state = *(s32 *)(lpVagMng + 0x94);
    switch (state) {
    case 0:
        return;
    case 6:
        value = fssdivagGetTrackStat(track);
        if (value != 0) break;
    default:
        state = *(s32 *)(lpVagMng + 0x94);
        value = 6;
        if (state != value) {
            fssdivagStop(track);
            state = 6;
            *(u32 *)(lpVagMng + 0x94) = state;
            break;
        }
        value = *(s32 *)(lpVagMng + 0x90);
        fsmfstrm_DetachFileSector(value);
        value = *(s32 *)(lpVagMng + 0x98);
        state = 1;
        if (value == state) {
            *(u32 *)(lpVagMng + 0x94) = state;
            *(u32 *)(lpVagMng + 0x98) = 0;
            break;
        }
        *(u32 *)(lpVagMng + 0x94) = 0;
        *(u8 *)(lpVagMng + 0x9e) = 0;
        memset(lpVagMng + 0x10, 0, 0x80);
    }
}










/* PauseVagStm @ 0x1ADC70 .. 0x1ADD24 (0xb4 bytes) */



void PauseVagStm(unsigned char track) {
    u8 *stm = (u8 *)VagStmMng + (u32)track * 0xd0;
    u32 state = *(u32 *)(stm + 0x94);

    switch (state) {
    case 0:
        return;
    case 5:
        if (fssdivagGetTrackStat(track) != 5) {
            goto done;
        }
    }
    if (*(u32 *)(stm + 0x94) != 5) {
        u32 id = (u8)track;
        fssdivagPause(id);
        *(u32 *)(stm + 0x94) = 5;
        return;
    }
done:
    return;
}


/* UpdateVagStm @ 0x1ADB40 .. 0x1ADC64 (0x124 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1adb6c writes a register its branch at 0x1adb68 reads
 *   cfg: loop body is not one contiguous region: .L001ADB60
 */


void UpdateVagStm(void) {
    u8 *s1;
    s32 s0;
    u32 v1;
    u32 v0;

    s1 = (u8 *)VagStmMng;
    fssdivagUpdateTrackStat();
    s0 = 0;
    do {
        v1 = *(s32 *)(s1 + 0x94);
        v0 = 3;
        switch (v1) {
        case 1:
            fssdivagGetReserveSetupResult(s0);
            SetUpVagStm((char *)(s1 + 0x10), s0, *(s32 *)(s1 + 0x90));
            break;
        case 3:
            v0 = fssdivagGetReserveSetupResult(s0);
            if (v0 == 0) {
                StopVagStm(s0);
                break;
            } else {
                PlayVagStm((u8)s0);
            }
        }
        UpdateVagStmFade(s0);
        UpdateVagStm3D(s0);
        v0 = fssdivagGetTrackStat(s0);
        v1 = 6;
        switch (v0) {
        case 0:
            v0 = *(s32 *)(s1 + 0x94);
            if (v0 != v1) {
                break;
            }
            StopVagStm(s0);
            break;
        case 6:
            v0 = *(s32 *)(s1 + 0x94);
            if (v0 == 0) {
                break;
            }
            StopVagStm(s0);
        }
        s0 = s0 + 1;
        v0 = s0 < (s32)6;
        s1 = (u8 *)(s1 + 0xd0);
    } while (v0 != 0);
    UpdateVolumePack();
    return;
}


s32 SetVagStmFade(arg, type, timer)
    unsigned int arg;
    unsigned char type;
    s32 timer;
{
    extern void PauseVagStm();
    extern void StopVagStm();
    u8 *stream;
    u32 state;
    u32 left;
    u32 right;
    stream=(u8 *)VagStmMng+(arg & 0xff)*208;
    if(timer<=0)timer=1;
    if(*(u32 *)(stream+0x94)==4 && stream[0x9c]==1 && *(s32 *)(stream+0xa0)>0) {
        u32 t=type;
        if(t==3 || t==5 || t==1)return 1;
    }
    stream[0x9c]=type;
    *(s32 *)(stream+0xa0)=timer;
    state=*(u32 *)(stream+0x94);
    if(state!=4) {
        u32 t=type;
        if(t==0 || t==2 || t==4) {
            stream[0x9d]=1;
        } else {
            if(state==3) {
                if(t==3) {PauseVagStm(arg);return 1;}
                if(t==5) {*(u32 *)(stream+0xa8)=0;return 1;}
                if(t==1) {StopVagStm(arg);return 1;}
            }
            stream[0x9d]=0;
            *(u32 *)(stream+0xa0)=0;
            state=*(u32 *)(stream+0x94);
            if(state==5 && t==1) {StopVagStm(arg);return 1;}
            if(state==0 || (state==5 && t==3))return 1;
            return 0;
        }
        if(t==2 && *(u32 *)(stream+0x94)==5)PlayVagStm(arg);
        return 1;
    }
    switch(type) {
    case 0:case 2:case 4:
        *(u32 *)(stream+0xa8)=0;
        *(u32 *)(stream+0xa4)=*(s32 *)(stream+0xac)/timer+1;
        break;
    case 1:case 3:case 5:
        *(u32 *)(stream+0xa8)=*(u32 *)(stream+0xac);
        *(u32 *)(stream+0xa4)=*(s32 *)(stream+0xac)/timer+1;
    default:
        break;
    }
    if(stream[0x9f]==2) {
        float volume=(float)*(s32 *)(stream+0xa8)**(float *)(stream+0xb8);
        left=(u16)(u32)volume;
        right=(u16)(u32)(float)volume;
        if(*(u8 *)(g_pSndMng+0x2c)!=0) {
            fssdivagSetChVolume((u8)arg,0,left,0);
            fssdivagSetChVolume((u8)arg,1,0,right);
        } else {
            fssdivagSetChVolume((u8)arg,0,left,right);
            fssdivagSetChVolume((u8)arg,1,left,right);
        }
    } else if(stream[0x9f]==1) {
        u32 volume=(u16)(u32)((float)*(s32 *)(stream+0xa8)**(float *)(stream+0xb8));
        fssdivagSetChVolume((u8)arg,0,volume,volume);
    }
    return 1;
}
static void UpdateVagStmFade(unsigned char a0 /* r4 */) {
    u8 *stm;
    float f;
    u32 left;
    u32 right;

    stm = (u8 *)VagStmMng + a0 * 0xd0;
    if (*(s32 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_TIMER_CE6EAFB5) != 0 && *(s32 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_STATE_E2C2DD60) == 4) {
        *(s32 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_TIMER_CE6EAFB5) -= 1;
        switch (*(u8 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADETYPE_F49EA64B)) {
        case 0:
        case 2:
        case 4:
            *(s32 *)(stm + 0xa8) = *(s32 *)(stm + 0xa8) + *(s32 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_VOLSTEP_80FB0EBB);
            if (*(s32 *)(stm + 0xa8) > *(s32 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_MAXVOL_9B79CAB0)) {
                *(s32 *)(stm + 0xa8) = *(s32 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_MAXVOL_9B79CAB0);
                *(u8 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADETYPE_F49EA64B) = 6;
                *(s32 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_TIMER_CE6EAFB5) = 0;
                *(u8 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADERESERVE_B45AD192) = 0;
            }
            break;
        case 1:
            *(s32 *)(stm + 0xa8) -= *(s32 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_VOLSTEP_80FB0EBB);
            if (*(s32 *)(stm + 0xa8) < 0) {
                *(s32 *)(stm + 0xa8) = 0;
            }
            if (*(s32 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_TIMER_CE6EAFB5) == 0) {
                StopVagStm(a0);
                *(u8 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADETYPE_F49EA64B) = 6;
                *(u8 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADERESERVE_B45AD192) = 0;
            }
            break;
        case 3:
            *(s32 *)(stm + 0xa8) -= *(s32 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_VOLSTEP_80FB0EBB);
            if (*(s32 *)(stm + 0xa8) < 0) {
                *(s32 *)(stm + 0xa8) = 0;
            }
            if (*(s32 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_TIMER_CE6EAFB5) == 0) {
                PauseVagStm(a0);
                *(u8 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADETYPE_F49EA64B) = 6;
                *(u8 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADERESERVE_B45AD192) = 0;
            }
            break;
        case 5:
            *(s32 *)(stm + 0xa8) -= *(s32 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_VOLSTEP_80FB0EBB);
            if (*(s32 *)(stm + 0xa8) < 0) {
                *(s32 *)(stm + 0xa8) = 0;
            }
            if (*(s32 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_TIMER_CE6EAFB5) == 0) {
                *(u8 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADETYPE_F49EA64B) = 6;
                *(u8 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_FADERESERVE_B45AD192) = 0;
            }
            break;
        }
        if (*(u8 *)(stm + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_B3DSTM_F9BBCDF9) == 0) {
            u32 ch = a0;
            u8 *e = (u8 *)&((struct { u8 b[0xd0]; } *)VagStmMng)[ch];
            if (*(u8 *)(e + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_CHANNEL_02843EC4) == 2) {
                f = (float)*(s32 *)(e + 0xa8) * *(float *)(e + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_DISTRATE_A17AA8E6);
                left = (u16)(u32)f;
                right = (u16)(u32)(float)f;
                if (*(u8 *)(g_pSndMng + DCOMP_OFF_STRUCT_DW_1872395_FIELDS_SNDMODE_FEEB8698) != 0) {
                    fssdivagSetChVolume((u8)ch, 0, left, 0);
                    fssdivagSetChVolume((u8)ch, 1, 0, right);
                } else {
                    fssdivagSetChVolume((u8)ch, 0, left, right);
                    fssdivagSetChVolume((u8)ch, 1, left, right);
                }
            } else if (*(u8 *)(e + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_CHANNEL_02843EC4) == 1) {
                f = (float)*(s32 *)(e + 0xa8) * *(float *)(e + DCOMP_OFF_STRUCT_DW_1865031_FIELDS_DISTRATE_A17AA8E6);
                fssdivagSetChVolume((u8)ch, 0, (u16)(u32)f, (u16)(u32)f);
            }
        }
    }
}







/* CheckVagStmFade @ 0x1AD3B0 .. 0x1AD3E0 (0x30 bytes) */
/*
 * dcomp notes:
 *   return: sltu at 0x1ad3dc computes the return value
 *   declaration vs inferred signature: return signed int vs inferred u32
 */







signed int CheckVagStmFade(unsigned char a0 /* r4 */) {
    u32 a0_word = a0;
    s32 v1;
    u32 v0;

    a0_word = (u8)a0_word;
    v1 = a0_word << 1;
    v0 = (u32)VagStmMng;
    v1 = v1 + a0_word;
    v1 = (u32)v1 << 2;
    v1 = v1 + a0_word;
    v1 = (u32)v1 << 4;
    v0 = (s32)((u8 *)VagStmMng + v1);
    v0 = *(s32 *)((v0 + 0xa0));
    return (s32)(v0 != 0);
}



/* SetVagMasterVolume @ 0x1AD130 .. 0x1AD3A8 (0x278 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   delay: andi at 0x1ad168 writes a register its branch at 0x1ad164 reads
 *   fpu: float literal 0x4f000000 at 0x1ad208
 *   fpu: mtc1 reinterprets v0 at 0x1ad24c
 *   fpu: float literal 0x4f000000 at 0x1ad320
 *   cfg: loop body is not one contiguous region: .L001AD1B8
 */

void SetVagMasterVolume(unsigned char a0 /* r4 */, unsigned short a1 /* r5 */) {
    u32 i;
    u32 left;
    u32 right;
    u8 *p;
    u8 *e;
    float f;

    if (a0 == 0) {
        BgmVol = a1;
    } else if (a0 == 1) {
        VoiceVol = a1;
    }
    i = 0;
    p = (u8 *)VagStmMng;
    VagStmMng[0x2b] = BgmVol;
    VagStmMng[0x12f] = BgmVol;
    VagStmMng[0x5f] = VoiceVol;
    VagStmMng[0x93] = VoiceVol;
    VagStmMng[0xc7] = VoiceVol;
    VagStmMng[0xfb] = VoiceVol;
    do {
        *(s32 *)(p + 0xa8) = *(s32 *)(p + 0xac);
        if (*(u8 *)(p + 0x9e) == 0) {
            e = (u8 *)VagStmMng + (u8)i * 0xd0;
            if (*(u8 *)(e + 0x9f) == 2) {
                f = (float)*(s32 *)(e + 0xa8) * *(float *)(e + 0xb8);
                left = (u16)(u32)f;
                right = (u16)(u32)(float)f;
                if (*(u8 *)(g_pSndMng + 0x2c) != 0) {
                    fssdivagSetChVolume((u8)i, 0, left, 0);
                    fssdivagSetChVolume((u8)i, 1, 0, right);
                } else {
                    fssdivagSetChVolume((u8)i, 0, left, right);
                    fssdivagSetChVolume((u8)i, 1, left, right);
                }
            } else if (*(u8 *)(e + 0x9f) == 1) {
                f = (float)*(s32 *)(e + 0xa8) * *(float *)(e + 0xb8);
                fssdivagSetChVolume((u8)i, 0, (u16)(u32)f, (u16)(u32)f);
            }
        }
        i++;
        p += 0xd0;
    } while (i < 6);
}


/* GetVagMasterVolume @ 0x1AD0F0 .. 0x1AD128 (0x38 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1ad110 writes a register its branch at 0x1ad10c reads
 *   cfg: branch target label disagrees with the instruction: branch target 0x1ad120 is not a block
 *   cfg: kept goto: 0x1ad100 -> .L001AD120
 *   declaration vs inferred signature: return unsigned short vs inferred u16
 */







unsigned short GetVagMasterVolume(unsigned char a0 /* r4 */) {
    u16 v0;

    if (a0 == 0) {
        return *(u16 *)((u16 *)&BgmVol);
    }
    v0 = 1;
    if ((u32)a0 == (u32)v0) {
        return *(u16 *)((u16 *)&VoiceVol);
    } else {
        return 0;
    }
    _L001AD120:;
    return v0;
}

void PlayBgmVagStm(signed int area, signed int track) {
    char path[128] __attribute__((aligned(16)));
    if (GameSt[0x2c] == 1 && area == 0 && track == 10)
        sprintf(path, "vag/a%02d%02de.adx", area, track);
    else
        sprintf(path, "vag/a%02d%02d.adx", area, track);
    if (SetUpVagStm(path, 0, 1)) {
        u8 *stm = (u8 *)VagStmMng;
        switch ((s32)VagStmMng[0x25]) {
        case 0:
        case 4:
            break;
        default:
            *(s32 *)(stm + 0x94) = 3;
            break;
        }
    }
}
signed int PlayVoiceVagStm(signed int id) {
    char filename[128] __attribute__((aligned(16)));
    u8 *lpVagMng;
    s32 track;
    s32 Track;

    lpVagMng = (u8 *)VagStmMng + (UseVoiceTrack + 1) * 0xd0;
    if (GameSt[(DCOMP_OFF_STRUCT_DW_1876911_FIELDS_VOICELANGUAGE_55350583 / 1)] == 0) {
        sprintf(filename, "vag/v%06d.adx", id);
    } else {
        sprintf(filename, "vag/v%06de.adx", id);
    }
    if (*(s32 *)(lpVagMng + 0x94) != 0) {
        for (Track = 0; Track < 4; Track++) {
            if (*(s32 *)((u8 *)VagStmMng + (Track + 1) * 0xd0 + 0x94) == 0) {
                UseVoiceTrack = Track;
                break;
            }
        }
    }
    track = UseVoiceTrack + 1;
    if (SetUpVagStm(filename, track, UseVoiceTrack + 2)) {
        lpVagMng = (u8 *)VagStmMng + (u8)track * 0xd0;
        switch (*(s32 *)(lpVagMng + 0x94)) {
        case 0:
        case 4:
            break;
        default:
            *(s32 *)(lpVagMng + 0x94) = 3;
            break;
        }
    }
    UseVoiceTrack = (UseVoiceTrack + 1) % 4;
    return track;
}














void PlayGeneralVagStm(int id) {
    char filename[128];

    sprintf(filename, "vag/a%04d.adx", id);
    if (SetUpVagStm(filename, 5, 6)) {
        u8 *stm = (u8 *)&VagStmMng[0x104];
        switch (*(s32 *)(stm + 0x94)) {
        case 0:
        case 4:
            break;
        default:
            *(s32 *)(stm + 0x94) = 3;
            break;
        }
    }
}


/* SetVagStm3D @ 0x1ACDA0 .. 0x1ACE6C (0xcc bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1acddc is a float copy
 */


void SetVagStm3D(unsigned char a0 /* r4 */, float *arg1 /* r5 */, float f12 /* f12 */, void *a2 /*
        r6 */) {
    u32 a0_word = a0;
    u8 a3;
    u32 v1;
    u8 *s0;
    float f20;
    u32 v0;
    u32 a1;

    a3 = a0_word;
    a0_word = (u32)a3 << 1;
    a0_word = a0_word + (u32)(a3);
    a0_word = a0_word << 2;
    a0_word = a0_word + (u32)(a3);
    v1 = (u32)VagStmMng;
    s0 = (u8 *)((u8 *)VagStmMng + (u32)(a0_word << 4));
    v1 = *(s32 *)(s0 + 0x94);
    f20 = (float)f12;
    if (v1 != 0) {
        *(u8 *)(s0 + 0x9e) = 1;
        *(u32 *)(s0 + 0xc8) = (u32)a2;
        v0 = *(s32 *)(s0 + 0xc8);
        if (v0 != 0) {
            v0 = *(s32 *)(((u8 *)a2 + 0x1c));
            if (v0 != 0 && (s32)*(s16 *)((v0 + 8)) > (s32)1) {
                v0 = *(s32 *)(((u8 *)a2 + 0x10));
                sceVu0CopyVector((void *)(u32)(s32)s0, (void *)(u32)(v0 + 0x70));
            } else {
                sceVu0CopyVector((void *)(u32)(s32)s0, (void *)(u32)(s32)((u8 *)a2 + 0x20));
            }
        } else {
            sceVu0CopyVector((void *)(u32)(s32)s0, (void *)a1);
        }
        *(f32 *)(s0 + 0xb0) = f20;
    }
    return;
}


static void UpdateVagStm3D(unsigned char track) {
    float Pos[4] __attribute__((aligned(16)));
    u8 *lpVagMng;
    float Rate;
    float AngDist;
    float ang;
    float scrz;
    float shifted;
    float NowDist;
    u8 *lpMdlMng;

    lpVagMng = (u8 *)VagStmMng + (u32)track * 0xd0;
    if (lpVagMng[0x9e] != 0) {
        lpMdlMng = *(u8 **)(lpVagMng + 0xc8);
        if (lpMdlMng[0] != 0) {
            if (lpMdlMng != 0) {
                u8 *head = *(u8 **)(lpMdlMng + 0x1c);
                if (head != 0 && *(s16 *)(head + 8) > 1) {
                    sceVu0CopyVector(lpVagMng, *(u8 **)(lpMdlMng + 0x10) + 0x70);
                } else {
                    sceVu0CopyVector(lpVagMng, lpMdlMng + 0x20);
                }
            }
            sceVu0ApplyMatrix(Pos, (u8 *)lpDrawMng + 0x2f0, lpVagMng);
            Rate = atanf(0.5f * *(float *)((u8 *)lpDrawMng + 0x41c));
            if (Rate != 0.0f) {
                Pos[0] = Pos[0] / Rate;
            }
            NowDist = sqrtf(sceVu0InnerProduct(Pos, Pos));
            NowDist = NowDist * Rate;
            scrz = *(float *)(lpVagMng + 0xb0) != 0.0f ? NowDist * g_fSndScaleFactor / *(float *)(lpVagMng + 0xb0) : 0.0f;
            if (!(scrz <= 1.0f)) {
                scrz = 1.0f;
            }
            *(float *)(lpVagMng + 0xb8) = 1.0f - scrz;
            ang = atan2f(Pos[0], Pos[2]);
            if (*(s32 *)(lpVagMng + 0xcc) == 0) {
                *(float *)(lpVagMng + 0xc4) = ang;
            }
            ang = ang - *(float *)(lpVagMng + 0xc4);
            shifted = 3.1415927f + ang;
            AngDist = shifted >= 0.0f ? ang - 6.2831855f * (float)(s32)(shifted / 6.2831855f) : 6.2831855f + (ang - 6.2831855f * (float)(s32)(shifted / 6.2831855f));
            if (AngDist < -0.3926991f) {
                AngDist = -0.3926991f;
            }
            if (!(AngDist <= 0.3926991f)) {
                AngDist = 0.3926991f;
            }
            *(float *)(lpVagMng + 0xc4) = *(float *)(lpVagMng + 0xc4) + AngDist;
            *(s32 *)(lpVagMng + 0xc0) = *(s32 *)(lpVagMng + 0xbc);
            *(s32 *)(lpVagMng + 0xbc) = (s32)(162.97466f * (1.5707964f + *(float *)(lpVagMng + 0xc4)));
            if (*(u8 *)(g_pSndMng + 0x2c) == 0) {
                *(s32 *)(lpVagMng + 0xbc) = 0x100;
            } else if (*(u8 *)(g_pSndMng + 0x2c) == 1) {
                if (*(s32 *)(lpVagMng + 0xbc) < 0) {
                    *(s32 *)(lpVagMng + 0xbc) = -*(s32 *)(lpVagMng + 0xbc);
                }
                while (*(s32 *)(lpVagMng + 0xbc) > 0x1ff) {
                    *(s32 *)(lpVagMng + 0xbc) -= 0x400;
                }
                if (*(s32 *)(lpVagMng + 0xbc) < 0) {
                    *(s32 *)(lpVagMng + 0xbc) = -*(s32 *)(lpVagMng + 0xbc);
                }
            }
            *(s32 *)(lpVagMng + 0xcc) += 1;
        }
    }
}


/* UpdateVolumePack @ 0x1AC950 .. 0x1ACA6C (0x11c bytes, frame 0x70) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x10 escapes at 0x1ac970
 *   stack: address of the slot at 0x10 escapes at 0x1aca58
 *   cfg: loop body is not one contiguous region: .L001AC970
 */


static void UpdateVolumePack(void) {
    u8 *a3;
    u8 *a2;
    s32 a1;
    u32 v0;
    u8 stackFrame_10[96] __attribute__((aligned(16)));

    a3 = (u8 *)VagStmMng;
    a2 = ((u8 *)&stackFrame_10[0]);
    a1 = 0;
    do {
        v0 = *(u8 *)(a3 + 0x9e);
        if (v0 != 0) {
            v0 = *(u8 *)(a3 + 0x9f);
            if (v0 == (u32)2) {
                *(u16 *)a2 = a1;
                *(u16 *)(a2 + 2) = 0;
                v0 = ((s32)((float)(float)((float)*(s32 *)(a3 + 0xa8)) * *(float *)(a3 + 0xb8)));
                *(u16 *)(a2 + 4) = v0;
                v0 = *(s32 *)(a3 + 0xbc);
                *(u16 *)(a2 + 6) = v0;
                *(u16 *)(a2 + 8) = a1;
                *(u16 *)(a2 + 0xa) = 1;
                v0 = ((s32)((float)(float)((float)*(s32 *)(a3 + 0xa8)) * *(float *)(a3 + 0xb8)));
                *(u16 *)(a2 + 0xc) = v0;
                v0 = *(s32 *)(a3 + 0xbc);
                *(u16 *)(a2 + 0xe) = v0;
                a2 = (u8 *)(a2 + 0x10);
            } else if (v0 == (u32)1) {
                *(u16 *)a2 = a1;
                *(u16 *)(a2 + 2) = 0;
                v0 = ((s32)((float)(float)((float)*(s32 *)(a3 + 0xa8)) * *(float *)(a3 + 0xb8)));
                *(u16 *)(a2 + 4) = v0;
                v0 = *(s32 *)(a3 + 0xbc);
                *(u16 *)(a2 + 6) = v0;
                a2 = (u8 *)(a2 + 8);
            }
        }
        a1 = a1 + 1;
        v0 = (u32)a1 < (u32)6;
        a3 = (u8 *)(a3 + 0xd0);
    } while (v0 != 0);
    v0 = (u32)((u8 *)&stackFrame_10[0]);
    v0 = (s32)(a2 - (u32)(((u8 *)&stackFrame_10[0])));
    if ((s32)v0 < 0) {
        a1 = (s32)(v0 + 7) >> 3;
    } else {
        a1 = (s32)v0 >> 3;
    }
    fssdivagSetVolumePack((u8 *)((u8 *)&stackFrame_10[0]), a1);
    return;
}


/* CheckVagStmState @ 0x1AC920 .. 0x1AC94C (0x2c bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1ac948 computes the return value
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int CheckVagStmState(unsigned char a0 /* r4 */) {
    u32 a0_word = a0;
    s32 v1;
    u32 *v0;

    a0_word = (u8)a0_word;
    v1 = a0_word << 1;
    v0 = VagStmMng;
    v1 = v1 + a0_word;
    v1 = (u32)v1 << 2;
    v1 = v1 + a0_word;
    v1 = (u32)v1 << 4;
    return *(s32 *)(((u8 *)(u32 *)(s32)((u8 *)VagStmMng + v1) + 0x94));
}

















/* SetVagStmReverb @ 0x1AC910 .. 0x1AC918 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdivagSetTrackReverb at 0x1ac910 leaves the function
 */


void SetVagStmReverb(unsigned char a0 /* r4 */, signed int arg1) {
    a0 = (u8)a0;
    fssdivagSetTrackReverb(a0);
    return;
}
