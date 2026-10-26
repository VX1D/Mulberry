#include "common.h"



/* DssPlayFlg @ 0x159DC0 .. 0x15A104 (0x344 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   literal: @1365 -> 0x2537e0
 *   indirect: jr v1 at 0x159de8 -> <v1>
 *   fpu: float literal 0x42c80000 at 0x159dfc
 *   fpu: mtc1 reinterprets v1 at 0x159e04
 *   fpu: mtc1 reinterprets v1 at 0x159e1c
 *   fpu: mtc1 reinterprets v1 at 0x159e34
 *   fpu: mtc1 reinterprets v1 at 0x159e4c
 *   fpu: mtc1 reinterprets v1 at 0x159e64
 *   fpu: mtc1 reinterprets v1 at 0x159e7c
 *   fpu: float literal 0x42c80000 at 0x159eb4
 *   fpu: mtc1 reinterprets v1 at 0x159ebc
 *   fpu: mtc1 reinterprets v1 at 0x159ed4
 *   fpu: mtc1 reinterprets v1 at 0x159eec
 *   delay: addiu at 0x159f28 writes a register its branch at 0x159f24 reads
 *   fpu: float literal 0x3cf5c28f at 0x159f5c
 *   fpu: float literal 0x42f00000 at 0x159f64
 *   fpu: float literal 0x3f800000 at 0x159fa0
 *   fpu: float literal 0x42c80000 at 0x159fbc
 *   fpu: mtc1 reinterprets a1 at 0x159fc0
 *   fpu: mov.s at 0x159fe4 is a float copy
 *   fpu: float literal 0x00000000 at 0x159ff4
 *   fpu: float literal 0x42c80000 at 0x15a010
 *   fpu: mtc1 reinterprets a1 at 0x15a014
 *   fpu: mov.s at 0x15a038 is a float copy
 *   fpu: mtc1 reinterprets v1 at 0x15a060
 *   fpu: mtc1 reinterprets v0 at 0x15a064
 *   fpu: mtc1 reinterprets v1 at 0x15a098
 *   fpu: mtc1 reinterprets v0 at 0x15a09c
 *   fpu: float literal 0x3f800000 at 0x15a0d8
 *   fpu: mtc1 reinterprets v1 at 0x15a0e4
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void SetBlast(float, float, float *, float *, signed int);
extern void SetChainDamage(void *);
extern void PadSetVib(signed int, float, float, unsigned char, unsigned char, signed int);
extern void SetPadVibHeart(void);
extern u32 MdlMng[];
extern u8 GameSt[];
extern u32 L1365[];


extern int rand();
extern signed int SND_Play3DPoint(signed int, signed short, signed short, float *, float);
static void ChangeFootStepSnd(void *object, unsigned short *sound);

static void ChangeFootStepSnd(void *object, unsigned short *sound);

#ifndef PROTO_DSS_SND
#define PROTO_DSS_SND
struct DssSndT { s16 random; s16 random_pitch; s16 random_vol; s16 unused1; s16 range; s16 vol; u16 index; s16 pitch; };
struct DssMdlT { u8 pad[0x20]; float Pos[4]; };
#endif


/* DssPlaySfx @ 0x15A2B0 .. 0x15A44C (0x19c bytes, frame 0x180) */
/*
 * dcomp notes:
 *   literal: @1450 is the string
 *   '\x83}\x83b\x83v\x94z\x92uOBJ %d - "%s" \x82Ì\x90Ý\x92è\x82ð\x8am\x94F\x82µ\x82Ä\x82\xad\x82¾\x82³\x82¢'
 *   literal: @1451 is the string ''
 *   stack: address of the slot at 0x70 escapes at 0x15a340
 *   stack: address of the slot at 0x70 escapes at 0x15a358
 *   delay: andi at 0x15a3a0 writes a register its branch at 0x15a39c reads
 *   stack: address of the slot at 0x60 escapes at 0x15a3b4
 *   stack: address of the slot at 0x50 escapes at 0x15a3c8
 *   stack: address of the slot at 0x60 escapes at 0x15a3f0
 *   stack: address of the slot at 0x50 escapes at 0x15a3f0
 *   stack: address of the slot at 0x178 escapes at 0x15a3f0
 *   stack: address of the slot at 0x178 escapes at 0x15a424
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void *GetDummyPolyData(void *,u8,u8);
extern int sprintf(char *, const char *, ...);
static signed int ChangeSfxId(void *a0 , unsigned short *a1 );
static signed int ChangeSfxId(void *a0 /* r4 */, unsigned short *a1 /* r5 */);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern signed int SFX_Create_OnDir_Dmg2(unsigned short, float *, float *, unsigned char, unsigned
    char, void *);
extern signed int SFX_Create_OnDir_Attach2(unsigned short, float *, float *, void *, unsigned
    short, unsigned char, unsigned char, void *);
extern u32 VW[];
extern u32 VZ[];

struct dw_508570_fields;
struct dw_528605_fields;
#ifndef PROTO_DW_526765_FIELDS
#define PROTO_DW_526765_FIELDS
struct dw_526765_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_524093_FIELDS
#define PROTO_DW_524093_FIELDS
struct dw_524093_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_523491_FIELDS
#define PROTO_DW_523491_FIELDS
struct dw_523491_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_508570_fields *lpMdl; };
#endif
#ifndef PROTO_DW_508570_FIELDS
#define PROTO_DW_508570_FIELDS
struct dw_508570_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_528605_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_508570_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_526765_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_524093_fields flags; unsigned char _pad1[3]; struct dw_523491_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_513761_FIELDS
#define PROTO_DW_513761_FIELDS
struct dw_513761_fields { unsigned short dmyID; unsigned short unused0[6]; short sfxID; unsigned char nrmIgnore; unsigned char noAttach; short unused2[7]; };
#endif
#ifndef PROTO_DW_525163_FIELDS
#define PROTO_DW_525163_FIELDS
struct dw_525163_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif
#ifndef PROTO_DW_518269_FIELDS
#define PROTO_DW_518269_FIELDS
struct dw_518269_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_528605_FIELDS
#define PROTO_DW_528605_FIELDS
struct dw_528605_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_518269_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_508570_FIELDS_ATTACKNO_1EE33D05_DEFINED
#define DCOMP_OFF_STRUCT_DW_508570_FIELDS_ATTACKNO_1EE33D05_DEFINED
enum { DCOMP_OFF_STRUCT_DW_508570_FIELDS_ATTACKNO_1EE33D05 = (int)&(((struct dw_508570_fields *)0)->AttackNo) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_508570_FIELDS_LPMDLDATA_C02F7DCB_DEFINED
#define DCOMP_OFF_STRUCT_DW_508570_FIELDS_LPMDLDATA_C02F7DCB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_508570_FIELDS_LPMDLDATA_C02F7DCB = (int)&(((struct dw_508570_fields *)0)->lpMdlData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_508570_FIELDS_LPOBJMAT_47624E70_DEFINED
#define DCOMP_OFF_STRUCT_DW_508570_FIELDS_LPOBJMAT_47624E70_DEFINED
enum { DCOMP_OFF_STRUCT_DW_508570_FIELDS_LPOBJMAT_47624E70 = (int)&(((struct dw_508570_fields *)0)->lpObjMat) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_508570_FIELDS_LPPARTS_B1AB23CB_DEFINED
#define DCOMP_OFF_STRUCT_DW_508570_FIELDS_LPPARTS_B1AB23CB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_508570_FIELDS_LPPARTS_B1AB23CB = (int)&(((struct dw_508570_fields *)0)->lpParts) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_513761_FIELDS_DMYID_1D505FD9_DEFINED
#define DCOMP_OFF_STRUCT_DW_513761_FIELDS_DMYID_1D505FD9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_513761_FIELDS_DMYID_1D505FD9 = (int)&(((struct dw_513761_fields *)0)->dmyID) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_513761_FIELDS_NOATTACH_50970A64_DEFINED
#define DCOMP_OFF_STRUCT_DW_513761_FIELDS_NOATTACH_50970A64_DEFINED
enum { DCOMP_OFF_STRUCT_DW_513761_FIELDS_NOATTACH_50970A64 = (int)&(((struct dw_513761_fields *)0)->noAttach) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_513761_FIELDS_SFXID_5745DAC7_DEFINED
#define DCOMP_OFF_STRUCT_DW_513761_FIELDS_SFXID_5745DAC7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_513761_FIELDS_SFXID_5745DAC7 = (int)&(((struct dw_513761_fields *)0)->sfxID) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_525163_FIELDS_GAMEMODE_564CA50B_DEFINED
#define DCOMP_OFF_STRUCT_DW_525163_FIELDS_GAMEMODE_564CA50B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_525163_FIELDS_GAMEMODE_564CA50B = (int)&(((struct dw_525163_fields *)0)->GameMode) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_528605_FIELDS_LPPRM_1B39473E_DEFINED
#define DCOMP_OFF_STRUCT_DW_528605_FIELDS_LPPRM_1B39473E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_528605_FIELDS_LPPRM_1B39473E = (int)&(((struct dw_528605_fields *)0)->lpPrm) - 0 };
#endif

extern void *GetDummyPolyData(void *,u8,u8);
extern void SetDamageMng(void *,u8,void *,float,u8,void *,void *,s16,u8);
static void DssPlaySfx(void *a0 , void *a1 );
static void DssPlaySfx(void *,void *);
static void DssPlaySnd(void *a0, void *a1);
static void DssPlaySnd(void *,void *);
extern u32 DssPlaySt[];
extern u32 VW[];
typedef struct M24DssState { u32 object,pad[2],frame; } M24DssState;


/* DssPlay @ 0x15A680 .. 0x15AB30 (0x4b0 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets a3 at 0x15a7a8
 *   fpu: mtc1 reinterprets a2 at 0x15a7c0
 *   fpu: mtc1 reinterprets a3 at 0x15a7e4
 *   fpu: mtc1 reinterprets a2 at 0x15a7fc
 *   fpu: mtc1 reinterprets a3 at 0x15a828
 *   fpu: mtc1 reinterprets a2 at 0x15a840
 *   fpu: mtc1 reinterprets a1 at 0x15a874
 *   delay: addiu at 0x15a89c writes a register its branch at 0x15a898 reads
 *   delay: addiu at 0x15a8b0 writes a register its branch at 0x15a8ac reads
 *   fpu: mtc1 reinterprets v0 at 0x15a91c
 *   fpu: mtc1 reinterprets v1 at 0x15a930
 *   fpu: float literal 0x42c80000 at 0x15a948
 *   delay: addiu at 0x15a9ac writes a register its branch at 0x15a9a8 reads
 *   delay: addiu at 0x15a9c0 writes a register its branch at 0x15a9bc reads
 *   delay: addiu at 0x15aa1c writes a register its branch at 0x15aa18 reads
 *   cfg: loop body is not one contiguous region: .L0015A6B8
 *   cfg: kept branch: 0x15a6f0 if (..) goto .L0015A718
 *   cfg: loop body is not one contiguous region: .L0015A758
 *   cfg: loop body is not one contiguous region: .L0015A798
 *   cfg: kept branch: 0x15a7e0 if (..) goto .L0015A820
 *   cfg: kept goto: 0x15a8e0 -> .L0015A910
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int SFX_IsBloodPool(unsigned short);

#ifndef PROTO_DW_508352_FIELDS
#define PROTO_DW_508352_FIELDS
struct dw_508352_fields { struct dw_508570_fields *lpMdl; float nowFrame; float prvFrame; unsigned int nowAnimID; };
#endif
#ifndef PROTO_DW_526765_FIELDS
#define PROTO_DW_526765_FIELDS
#endif
#ifndef PROTO_DW_524093_FIELDS
#define PROTO_DW_524093_FIELDS
#endif
#ifndef PROTO_DW_523491_FIELDS
#define PROTO_DW_523491_FIELDS
#endif
#ifndef PROTO_DW_508570_FIELDS
#define PROTO_DW_508570_FIELDS
#endif


struct DssAnimT { u16 daID; u16 daNum; u16 daOff; u16 daPad; };
struct DssHeadT { u8 dhPad0[4]; u32 dhNum; u8 dhPad1[8]; struct DssAnimT dhAnim[1]; };
struct DssDataT { u8 ddKind; u8 ddPad[3]; u16 ddFrame; u16 ddLen; };
struct DssDmgT { u16 dmDmy; u8 dmPad0[0xc]; u16 dmDmg; u8 dmPad1[0x10]; };
struct DssFlgT { u8 dfPad[0x20]; };
struct DssSndU { u8 dsPad[0x20]; };
struct DssCtrlA { u8 caPad[0x1ce]; u16 caVal; };
struct DssCtrlB { u8 cbPad[0x1f2]; u8 cbVal; };
struct DssCtrlC { u8 ccPad[0x180]; u8 ccAct; };
struct DssAnimCtrl { float acNow; float acPrv; };


/* FreeDss @ 0x15AB90 .. 0x15ABE0 (0x50 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0015ABA0
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 DssPlaySt[];
static u32 DssPlaySt[0x258];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void DssInit(void);
void FreeDss(void *a0 );
void *SetDss(void *object);
void DssPlay(struct dw_508570_fields *lpMdlMng);
void DssPlay4Init(void *object);
static void DssPlaySfx(void *a0 , void *a1 );
static void DssPlaySnd(void *a0, void *a1);
static void DssPlayFlg(void *a0 , void *a1 );
static void ChangeFootStepSnd(void *object, unsigned short *sound);
static signed int ChangeSfxId(void *a0 , unsigned short *a1 );


/* DssInit @ 0x15ABE0 .. 0x15AC24 (0x44 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0015ABF8
 */



void DssInit(void) {
    u8 *a1;

    a1 = (u8 *)DssPlaySt;
    do {
        if ((u32)a1 != 0) {
            *(u32 *)a1 = 0;
            *(u32 *)(a1 + 4) = 0;
            *(u32 *)(a1 + 0xc) = -1;
        }
        a1 = (u8 *)(a1 + 0x10);
    } while (a1 != (u8 *)(DssPlaySt + 0x258));
    return;
}

void FreeDss(void *a0 /* r4 */) {
    u8 *a2;
    u32 a1;

    a2 = (u8 *)DssPlaySt;
    do {
        a1 = *(s32 *)a2;
        if (a1 == (u32)a0) {
            if ((u32)a2 == 0) {
                break;
            }
            *(u32 *)a2 = 0;
            *(u32 *)(a2 + 4) = 0;
            *(u32 *)(a2 + 0xc) = -1;
            return;
        }
        a2 = (u8 *)(a2 + 0x10);
    } while (a2 != (u8 *)(DssPlaySt + 0x258));
    return;
}



void *SetDss(void *object) {
    struct DssEntry { u32 data; u32 rest[3]; };
    struct DssEntry *cursor;
    struct DssEntry *selected;
    u32 value;
    cursor = (struct DssEntry *)DssPlaySt;
    do {
        value = cursor->data;
        if (value == 0) { selected = cursor; goto found; }
        ++cursor;
    } while (cursor != (struct DssEntry *)(DssPlaySt + 0x258));
    selected = 0;
found:
    if (selected == 0) selected = 0;
    else selected->data = (u32)object;
    return selected;
}
void DssPlay(struct dw_508570_fields *lpMdlMng) {
    struct dw_508352_fields *lpDssPlay;
    int i;
    int skip;
    float AnimStep;
    struct DssHeadT *dssHead;
    struct DssAnimT *dssAnim;
    struct DssDataT *dssData;
    struct DssDmgT *dssDmg;
    struct DssSndU *dssSnd;
    struct dw_513761_fields *dssSfx;
    struct DssFlgT *dssFlg;
    struct DssAnimCtrl *lpAnimCtrl;

    if (lpMdlMng->lpMi3Head == 0) {
        return;
    }
    lpDssPlay = (struct dw_508352_fields *)DssPlaySt;
    do {
        if (lpDssPlay->lpMdl == lpMdlMng) {
            break;
        }
        lpDssPlay++;
    } while (lpDssPlay != (struct dw_508352_fields *)(DssPlaySt + 0x258));
    if (lpDssPlay == (struct dw_508352_fields *)((u8 *)DssPlaySt + 0x960)) {
        return;
    }
    lpAnimCtrl = (struct DssAnimCtrl *)lpMdlMng->lpAnimCtrl;
    if (lpMdlMng->IndexAnim == lpDssPlay->nowAnimID) {
        if (lpAnimCtrl->acNow == lpAnimCtrl->acPrv) {
            return;
        }
    } else {
        lpDssPlay->nowAnimID = lpMdlMng->IndexAnim;
    }
    AnimStep = lpAnimCtrl->acNow - lpAnimCtrl->acPrv;
    lpDssPlay->nowFrame = lpAnimCtrl->acNow - AnimStep;
    lpDssPlay->prvFrame = lpAnimCtrl->acPrv - AnimStep;
    dssHead = (struct DssHeadT *)lpMdlMng->lpMdlData->lpDss;
    dssAnim = dssHead->dhAnim;
    for (i = 0; i < dssHead->dhNum; i++, dssAnim++) {
        if (dssAnim->daID == lpDssPlay->nowAnimID) {
            break;
        }
    }
    if (i == dssHead->dhNum) {
        return;
    }
    dssData = (struct DssDataT *)((u8 *)dssHead + dssAnim->daOff);
    for (i = 0; i < dssAnim->daNum; i++) {
        skip = 1;
        if (lpDssPlay->prvFrame < (float)dssData->ddFrame && !(lpDssPlay->nowFrame < (float)dssData->ddFrame)) {
            skip = 0;
        } else if (!(lpDssPlay->nowFrame < (float)dssData->ddFrame)) {
            if (lpDssPlay->nowFrame < (float)(int)(dssData->ddFrame + dssData->ddLen + (dssData->ddLen == 0))) {
                skip = 0;
            }
        }
        switch (dssData->ddKind) {
        case 1:
            dssDmg = (struct DssDmgT *)(dssData + 1);
            if (skip == 0) {
                void *pos;
                u32 bone;
                do {
                    if (dssDmg->dmDmy == 0xff) {
                        bone = 0;
                        pos = VW;
                    } else {
                        pos = GetDummyPolyData(lpMdlMng->lpMdlData, 1, dssDmg->dmDmy);
                        if (pos == 0) {
                            break;
                        }
                        bone = *(u16 *)((u8 *)pos + 0x20);
                    }
                    SetDamageMng(lpMdlMng, bone, pos, (float)dssDmg->dmDmg / 100.0f * lpMdlMng->Scl[0], lpMdlMng->TeamNo, 0, 0, -1, lpMdlMng->AttackNo);
                } while (0);
            }
            dssData = (struct DssDataT *)(dssDmg + 1);
            break;
        case 2:
            dssSfx = (struct dw_513761_fields *)(dssData + 1);
            if (lpMdlMng->lpMdlData->MdlType == 0) {
                struct DssCtrlA *lpCtrl = (struct DssCtrlA *)lpMdlMng->lpCtrlSt;
                switch (dssSfx->sfxID) {
                case 201:
                case 302:
                case 303:
                case 304:
                case 305:
                    if (lpCtrl != 0 && lpCtrl->caVal == 0) {
                        skip = 1;
                    }
                }
            } else if (lpMdlMng->lpMdlData->MdlType == 1) {
                struct DssCtrlB *lpCtrl = (struct DssCtrlB *)lpMdlMng->lpCtrlSt;
                switch (dssSfx->sfxID) {
                case 701:
                case 702:
                case 703:
                    if (lpCtrl != 0 && lpCtrl->cbVal != 0) {
                        skip = 1;
                    }
                }
            }
            if (skip == 0) {
                if (lpMdlMng->lpMdlData->MdlType == 1) {
                    if (SFX_IsBloodPool(dssSfx->sfxID) != 0) {
                        if (((struct DssCtrlC *)lpMdlMng->lpCtrlSt)->ccAct != 7) {
                            lpMdlMng->blood_pool_sfx_idx = dssSfx->sfxID;
                        }
                    }
                }
                DssPlaySfx(lpMdlMng, dssSfx);
            }
            dssData = (struct DssDataT *)(dssSfx + 1);
            break;
        case 3:
            dssSnd = (struct DssSndU *)(dssData + 1);
            if (lpMdlMng->AnimState == 1) {
                skip = 1;
            }
            if (skip == 0) {
                DssPlaySnd(lpMdlMng, dssSnd);
            }
            dssData = (struct DssDataT *)(dssSnd + 1);
            break;
        case 4:
            dssFlg = (struct DssFlgT *)(dssData + 1);
            if (skip == 0) {
                DssPlayFlg(lpMdlMng, dssFlg);
            }
            dssData = (struct DssDataT *)(dssFlg + 1);
        }
    }
}
void DssPlay4Init(void *object) {
    u8 *saved;
    u8 *entry;
    u8 *payload;
    s32 i;
    u32 owner;
    u32 index;
    u32 base;
    u32 cursor;
    saved=object;
    owner=(u32)DssPlaySt;
    do {
        object=*(void **)owner;
        if(object==(void *)saved)break;
        owner+=16;
    }while((u8 *)owner!=(u8 *)(DssPlaySt+0x258));
    if(owner!=(u32)(DssPlaySt+0x258)) {
        index=0;
        ((M24DssState *)owner)->frame=999;
        base=*(u32 *)(*(u32 *)(saved+12)+0x48);
        object=*(void **)(base+4);
        entry=(u8 *)(base+16);
        if((u8 *)0<(u8 *)object) {
            owner=*(u32 *)(owner+12);
            do {
                if(*(u16 *)entry==owner)break;
                ++index;entry+=8;
            }while(index<(u32)object);
        }
        if(index!=(u32)object) {
            i=0;
            cursor=base+*(u16 *)(entry+4);
            if(0<(s32)*(u16 *)(entry+2)) do {
                switch(*(u8 *)cursor) {
                case 1: {
                    void *poly;
                    u32 bone;
                    payload=(u8 *)(cursor+8);
                    if(*(u16 *)payload==255) {bone=0;poly=VW;}
                    else {
                        poly=GetDummyPolyData(*(void **)(saved+12),1,*(u16 *)payload);
                        if(poly==0)goto damageDone;
                        bone=*(u16 *)((u8 *)poly+32);
                    }
                    SetDamageMng(saved,(u8)bone,poly,((float)*(u16 *)(payload+14)/100.0f)**(float *)(saved+0x40),saved[0x128],0,0,-1,saved[0x12a]);
damageDone:
                    cursor=(u32)(payload+32);
                    break;
                }
                case 2:
                    payload=(u8 *)(cursor+8);
                    DssPlaySfx(saved,payload);
                    cursor=(u32)(payload+32);
                    break;
                case 3:
                    payload=(u8 *)(cursor+8);
                    DssPlaySnd(saved,payload);
                    cursor=(u32)(payload+32);
                    break;
                case 4:
                    payload=(u8 *)(cursor+8);
                    DssPlayFlg(saved,payload);
                    cursor=(u32)(payload+32);
                    break;
                }
                ++i;
            }while(i<(s32)*(u16 *)(entry+2));
        }
    }
}
static void DssPlaySfx(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *mdl = (u8 *)a0;
    u8 *sfx = (u8 *)a1;
    u8 *mdlData = *(u8 **)(mdl + DCOMP_OFF_STRUCT_DW_508570_FIELDS_LPMDLDATA_C02F7DCB);
    u8 *lpPos;
    u8 *lpDir;
    u16 *prm;
    u16 bone;
    u16 sfxId;
    u8 addData[6] __attribute__((aligned(8)));
    char comment[256] __attribute__((aligned(16)));
    float pos[4] __attribute__((aligned(16)));
    float dir[4] __attribute__((aligned(16)));

    prm = *(u16 **)(mdlData + DCOMP_OFF_STRUCT_DW_528605_FIELDS_LPPRM_1B39473E);
    if (GameSt[DCOMP_OFF_STRUCT_DW_525163_FIELDS_GAMEMODE_564CA50B] != 2) {
        if (*(u16 *)(sfx + DCOMP_OFF_STRUCT_DW_513761_FIELDS_DMYID_1D505FD9) == 0xff) {
            lpPos = (u8 *)VW;
            lpDir = (u8 *)VZ;
            bone = 0;
        } else {
            u8 *poly = (u8 *)GetDummyPolyData(mdlData, 0, *(u16 *)(sfx + DCOMP_OFF_STRUCT_DW_513761_FIELDS_DMYID_1D505FD9));
            if (poly == 0) {
                u8 *parts = *(u8 **)(mdl + DCOMP_OFF_STRUCT_DW_508570_FIELDS_LPPARTS_B1AB23CB);
                if (parts != 0) {
                    sprintf(comment, "\203}\203b\203v\224z\222uOBJ %d - \"%s\" \202\314\220\335\222\350\202\360\212m\224F\202\265\202\304\202\255\202\276\202\263\202\242", *(s32 *)(parts + 0x30), (char *)(parts + 0x40));
                } else {
                    sprintf(comment, "");
                }
                return;
            }
            bone = *(u16 *)(poly + 0x20);
            lpPos = poly;
            lpDir = poly + 0x10;
        }
        sfxId = *(s16 *)(sfx + DCOMP_OFF_STRUCT_DW_513761_FIELDS_SFXID_5745DAC7);
        if (ChangeSfxId(mdl, &sfxId) != 0) {
            *(u32 *)addData = (u32)mdl;
            if (*(u8 *)(sfx + DCOMP_OFF_STRUCT_DW_513761_FIELDS_NOATTACH_50970A64) != 0) {
                u32 offset = (u32)bone << 6;
                sceVu0ApplyMatrix(pos, (void *)(*(s32 *)(mdl + DCOMP_OFF_STRUCT_DW_508570_FIELDS_LPOBJMAT_47624E70) + offset), lpPos);
                sceVu0ApplyMatrix(dir, (void *)(*(s32 *)(mdl + DCOMP_OFF_STRUCT_DW_508570_FIELDS_LPOBJMAT_47624E70) + offset), lpDir);
                SFX_Create_OnDir_Dmg2(sfxId, pos, dir, prm != 0 ? *prm : 0, *(u8 *)(mdl + DCOMP_OFF_STRUCT_DW_508570_FIELDS_ATTACKNO_1EE33D05), &addData);
            } else {
                SFX_Create_OnDir_Attach2(sfxId, (float *)lpPos, (float *)lpDir, mdl, bone, prm != 0 ? *prm : 0, *(u8 *)(mdl + DCOMP_OFF_STRUCT_DW_508570_FIELDS_ATTACKNO_1EE33D05), &addData);
            }
        }
    }
}

static void DssPlaySnd(void *a0, void *a1) {
    struct DssMdlT *lpMdlMng = (struct DssMdlT *)a0;
    struct DssSndT *lpDssSnd = (struct DssSndT *)a1;
    u16 sndIndex;
    s16 pitch;
    s16 vol;
    float range;
    s32 rndvol;
    s32 rndpitch;

    sndIndex = lpDssSnd->index;
    if (lpDssSnd->random != 0) {
        if (rand() % 100 > lpDssSnd->random) {
            return;
        }
    }
    if (lpDssSnd->range == 0) {
        range = 25.0f;
    } else {
        range = (float)lpDssSnd->range;
    }
    rndvol = lpDssSnd->random_vol;
    if (rndvol == 0) {
        vol = lpDssSnd->vol;
    } else {
        { s32 t = (rand() % rndvol) * 2 - rndvol; vol = t + lpDssSnd->vol; }
        if (vol < 0) {
            vol = 0;
        } else if (vol > 0x7f) {
            vol = 0x7f;
        }
    }
    rndpitch = lpDssSnd->random_pitch;
    if (rndpitch == 0) {
        pitch = lpDssSnd->pitch;
    } else {
        { s32 t = (rand() % rndpitch) * 2 - rndpitch; pitch = t + lpDssSnd->pitch; }
        if (pitch < -0x960) {
            pitch = -0x960;
        } else if (pitch > 0x960) {
            pitch = 0x960;
        }
    }
    ChangeFootStepSnd(lpMdlMng, &sndIndex);
    SND_Play3DPoint(sndIndex, vol, pitch, lpMdlMng->Pos, range);
}

static void DssPlayFlg(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 a2;
    float Alpha;
    float f13;
    float f12;
    u8 *a1_bytes; // a1
    u8 *a0_bytes; // a0
    float f3;
    float f2;
    float f1;
    float f0;
    u32 v1;
    s32 v0;

    a0_bytes = (u8 *)a0;
    a1_bytes = (u8 *)a1;
    v1 = *(u16 *)(a1_bytes + 0xe);
    switch (v1) {
    case 0:
        *(u8 *)(a0_bytes + 7) = 1;
        f1 = 100.0f;
        v1 = *(s16 *)(a1_bytes + 0x10);
        *(f32 *)(a0_bytes + 0x90) = ((float)((float)(s32)v1) / 100.0f);
        v1 = *(s16 *)(a1_bytes + 0x12);
        *(f32 *)(a0_bytes + 0x94) = ((float)((float)(s32)v1) / 100.0f);
        v1 = *(s16 *)(a1_bytes + 0x14);
        *(f32 *)(a0_bytes + 0x98) = ((float)((float)(s32)v1) / 100.0f);
        v1 = *(s16 *)(a1_bytes + 0x18);
        *(f32 *)(a0_bytes + 0xa0) = ((float)((float)(s32)v1) / 100.0f);
        v1 = *(s16 *)(a1_bytes + 0x1a);
        *(f32 *)(a0_bytes + 0xa4) = ((float)((float)(s32)v1) / 100.0f);
        v1 = *(s16 *)(a1_bytes + 0x1c);
        *(f32 *)(a0_bytes + 0xa8) = ((float)((float)(s32)v1) / 100.0f);
        break;
    case 1:
        *(u8 *)(a0_bytes + 7) = 0;
        break;
    case 2:
        *(u8 *)(a0_bytes + 8) = 1;
        f1 = 100.0f;
        v1 = *(s16 *)(a1_bytes + 0x10);
        *(f32 *)(a0_bytes + 0xb0) = ((float)((float)(s32)v1) / 100.0f);
        v1 = *(s16 *)(a1_bytes + 0x12);
        *(f32 *)(a0_bytes + 0xb4) = ((float)((float)(s32)v1) / 100.0f);
        v1 = *(s16 *)(a1_bytes + 0x14);
        *(f32 *)(a0_bytes + 0xb8) = ((float)((float)(s32)v1) / 100.0f);
        break;
    case 3:
        *(u8 *)(a0_bytes + 8) = 0;
        break;
    case 4:
        a2 = *(u16 *)((*(s32 *)(a0_bytes + 0xc) + 0xa));
        if (a2 != (u32)1) {
            if (a2 != (u32)2) {
                break;
            }
        }
        a1_bytes = (u8 *)*(s16 *)(a1_bytes + 0x10);
        v1 = *(s32 *)(a0_bytes + 0x148);
        *(u16 *)((v1 + 0x1fa)) = (u16)a1_bytes;
        break;
    case 5:
        SetBlast(0.03f, 120.0f, (float *)(a0_bytes + 0x20), (float *)(u8 *)(MdlMng + 0x4608), 0x28);
        break;
    case 6:
        SetChainDamage((void *)a0_bytes);
        break;
    case 7:
        v1 = *(s16 *)(a1_bytes + 0x10);
        *(u16 *)(a0_bytes + 0x12e) = v1;
        break;
    case 8:
        v1 = 0x3f800000;
        f3 = *(float *)(a0_bytes + 0x10c);
        f2 = 1.0f;
        if (1.0f == f3) {
            break;
        }
        a1_bytes = (u8 *)*(s16 *)(a1_bytes + 0x10);
        v1 = 0x42c80000;
        f0 = 100.0f;
        f3 = (f3 + ((float)((float)(s32)(u32)a1_bytes) / 100.0f));
        if (!(f3 <= f2)) {
            f3 = f2;
        }
        *(f32 *)(a0_bytes + 0x10c) = f3;
        break;
    case 9:
        f3 = *(float *)(a0_bytes + 0x10c);
        f2 = 0.0f;
        if (0.0f == f3) {
            break;
        }
        a1_bytes = (u8 *)*(s16 *)(a1_bytes + 0x10);
        v1 = 0x42c80000;
        f0 = 100.0f;
        f3 = (f3 - ((float)((float)(s32)(u32)a1_bytes) / 100.0f));
        if (f3 < f2) {
            f3 = f2;
        }
        *(f32 *)(a0_bytes + 0x10c) = f3;
        break;
    case 10:
        v1 = *(s16 *)(a1_bytes + 0x10);
        v0 = *(s16 *)(a1_bytes + 0x12);
        a0_bytes = (u8 *)GameSt[0xa];
        PadSetVib((signed int)a0_bytes, (float)((float)(s32)v1), (float)((float)(s32)(u32)v0), 0,
            0, 0);
        break;
    case 11:
        v1 = *(s16 *)(a1_bytes + 0x10);
        v0 = *(s16 *)(a1_bytes + 0x12);
        a0_bytes = (u8 *)GameSt[0xa];
        PadSetVib((signed int)a0_bytes, (float)((float)(s32)v1), (float)((float)(s32)(u32)v0), 1,
            0, 0);
        break;
    case 12:
        SetPadVibHeart();
        break;
    case 13:
        v1 = *(s16 *)(a1_bytes + 0x10);
        a0_bytes = (u8 *)GameSt[0xa];
        f13 = 1.0f;
        PadSetVib((signed int)a0_bytes, (float)((float)(s32)v1), 1.0f, 0, 1, 0);
    default:
        break;
    }
    return;
}

static void ChangeFootStepSnd(void *object, unsigned short *sound)
{
    u16 base;
    u16 index;
    index = *sound;
    if (index < 0x3f2 || index > 0x3f6) return;
    object = (void *)*(u32 *)((u8 *)object + 0x134);
    index = (u16)(index - 0x3f2);
    if ((u32)object & 0x1000) base = 0x40b;
    else if ((u32)object & 2) base = 0x456;
    else if ((u32)object & 4) base = 0x45b;
    else if ((u32)object & 8) base = 0x3e8;
    else if ((u32)object & 0x10) base = 0x451;
    else if ((u32)object & 0x20) base = 0x460;
    else if ((u32)object & 0x40) base = 0x3f7;
    else if ((u32)object & 0x80) base = 0x3e8;
    else if ((u32)object & 0x100) base = 0x3ed;
    else base = 0x3f2;
    *sound = index + base;
}


/* ChangeSfxId @ 0x159BE0 .. 0x159CA0 (0xc0 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x159bec writes a register its branch at 0x159be8 reads
 *   delay: addiu at 0x159c64 writes a register its branch at 0x159c60 reads
 *   delay: daddu at 0x159c80 writes a register its branch at 0x159c7c reads
 *   cfg: kept branch: 0x159be0 if (..) goto .L00159BF8
 *   cfg: kept branch: 0x159bec if (..) goto .L00159C40
 *   cfg: kept goto: 0x159c30 -> .L00159C90
 *   cfg: kept branch: 0x159c40 if (..) goto .L00159C90
 *   cfg: kept branch: 0x159c54 if (..) goto .L00159C70
 *   cfg: kept branch: 0x159c64 if (..) goto .L00159C90
 *   cfg: kept branch: 0x159c70 if (..) goto .L00159C90
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

static signed int ChangeSfxId(void *a0 /* r4 */, unsigned short *a1 /* r5 */) {
    u32 a3;
    u8 *a2;
    u8 *a0_bytes; // a0
    u32 v1;
    u32 v0;

    a0_bytes = (u8 *)a0;
    a3 = *(u16 *)a1;
    v0 = 0x186;
    if (a3 == v0) {
        goto _L00159BF8;
    }
    v0 = 0x189;
    if (a3 != v0) {
        goto _L00159C40;
    }
    _L00159BF8:;
    a2 = (u8 *)*(s32 *)(a0_bytes + 0x148);
    v0 = 3;
    v1 = *(u8 *)(a2 + 0x100);
    if (v1 == v0 && (u32)*(u16 *)((*(s32 *)(a0_bytes + 0xc) + 0xa)) == 0) {
        v0 = *(u8 *)(a2 + 0x1ad);
        if (v0 == 0) {
            v0 = 0;
        } else {
            v0 = a3 + (u32)v0;
            *(u16 *)a1 = v0;
            goto _L00159C90;
            _L00159C40:;
            v0 = (s32)a3 < (s32)0x2c6;
            if (v0 != 0 || (s32)a3 >= (s32)0x2cb) {
                goto _L00159C90;
            }
            v1 = *(s32 *)(a0_bytes + 0xc);
            v0 = 1;
            v1 = *(u16 *)((v1 + 0xa));
            if (v1 == v0) {
                goto _L00159C70;
            }
            v0 = 2;
            if (v1 != v0) {
                goto _L00159C90;
            }
            _L00159C70:;
            v1 = *(s32 *)(a0_bytes + 0x148);
            v0 = 7;
            v1 = *(u8 *)((v1 + 0x180));
            if (v1 != v0) {
                goto _L00159C90;
            }
            v0 = 0;
            return v0;
        }
    } else {
        _L00159C90:;
        v0 = 1;
    }
    return v0;
}
