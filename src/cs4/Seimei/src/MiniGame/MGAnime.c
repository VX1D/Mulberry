#include "common.h"
extern void *GetPieceTable(void);
extern u8 g_catch_up_mode;
extern signed int SND_Play2D(signed int, signed short, signed short);
extern unsigned char *GetChoisePiecePos(void);
extern void SetPieceAnimeMovePos(unsigned int);
struct MGAnimeInfo { unsigned char IndexAnim; unsigned char _pad0[3]; float height; float move_speed; float frame_num; float tilt; float freq_ang; float amp_rate; unsigned char _pad1[4]; float start_pos[4]; float end_pos[4]; float tilt_z; unsigned char key_count; unsigned char num; char direction; unsigned char _pad2[9]; };
struct MGPieceTbl { unsigned char PieceNum; unsigned char PieceID[16]; unsigned char _pad0[15]; float PiecePos[16][4]; unsigned char ShadowPos[128]; };
extern struct MGAnimeInfo g_piece_anime[];
extern u8 MdlMng[];
extern u8 g_dice_anime[];
extern int rand();
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern u32 g_MGDieAnimFuncTbl[];
extern u32 g_MGPieceAnimFuncTbl[];
extern u32 GetDiceNum();
extern void sceVu0CopyMatrix(void *, void *);
extern void sceVu0RotMatrixX(void *, void *, float);
extern void sceVu0RotMatrixZ(void *, void *, float);
extern void sceVu0RotMatrixY(void *, void *, float);
extern u32 L856[];
extern void MGDiceAnimeInit(unsigned int, unsigned char);
static void CheckWarSituation(void);
void MGPieceMoveAnimeInit(unsigned int a0 /* r4 */);
void MGPieceMoveAnimeFirstInit(unsigned char a0 /* r4 */, unsigned int a1 /* r5 */);
static void MGPieceSelectAnime(void *a0 /* r4 */, unsigned int a1 /* r5 */);
void MGPieceSelectAnimeExit(unsigned int a0 /* r4 */);
void MGPieceSelectAnimeInit(unsigned int a0 /* r4 */);
void MGPieceAnimeMain(void *lpMdlMng);
static void MGSetDieOneNum(unsigned char a0 /* r4 */);
static unsigned char MGGetDieNum(void *a0 /* r4 */);
static void MGReviseAngle(float *a0 /* r4 */);
static void MGDieSelectAnim(void *a0 /* r4 */, unsigned int a1 /* r5 */);
static void MGDieAnimReady(void *a0 /* r4 */, unsigned int a1 /* r5 */);
void MGDiceAnimeStart(unsigned char a0 /* r4 */, unsigned char a1 /* r5 */);
void MGDieAnimMain(void *a0 /* r4 */);
void InitCatchUpMode(void);
u8 * GetPieceAnimeInfo(void);
void SetDieAnimeInfoNum(unsigned char a0 /* r4 */, unsigned char a1 /* r5 */);
u8 * GetDieAnimeInfo(void);

/* GetDieAnimeInfo @ 0x1F7BE0 .. 0x1F7BEC (0xc bytes) */


u8 * GetDieAnimeInfo(void) {
    return (u8 *)g_dice_anime;
}








/* SetDieAnimeInfoNum @ 0x1F7BB0 .. 0x1F7BD4 (0x24 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */


void SetDieAnimeInfoNum(unsigned char a0 /* r4 */, unsigned char a1 /* r5 */) {
    u32 a0_word = a0;
    u32 a2;
    u8 *v1;

    a2 = (u8)a0_word;
    a0_word = a2 << 2;
    v1 = (u8 *)g_dice_anime + 0x35;
    a0_word = a0_word + a2;
    *(u8 *)(u8 *)(s32)((u8 *)v1 + (u32)(a0_word << 4)) = (u8)a1;
    return;
}


/* GetPieceAnimeInfo @ 0x1F7BA0 .. 0x1F7BAC (0xc bytes) */


u8 * GetPieceAnimeInfo(void) {
    return (u8 *)g_piece_anime;
}












/* InitCatchUpMode @ 0x1F7B90 .. 0x1F7B98 (0x8 bytes) */


void InitCatchUpMode(void) {
    g_catch_up_mode = 0;
    return;
}





void MGDiceAnimeInit(unsigned int index, unsigned char mode) {
    u8 *dice = (u8 *)g_dice_anime + index * 80;
    u8 *model = (u8 *)MdlMng + (index + 211) * 448;
    *dice = mode;
    switch (mode) {
    case 1:
        *(float *)(dice + 0x14) = 1.25f;
        *(float *)(dice + 8) = 0.015f;
        *(float *)(dice + 0xc) = 0.7f + 0.05f * index;
        *(float *)(dice + 4) = -0.4f;
        *(float *)(dice + 0x10) = -1.0f;
        *(float *)(dice + 0x30) = 0.6f + 0.005f * (rand() % 30 - 15);
        dice[0x34] = 0;
        dice[0x35] = 0;
        *(float *)(dice + 0x20) = 0.01745f * (1.0f + (rand() % 95) / 5.0f);
        *(float *)(dice + 0x24) = 0;
        *(float *)(dice + 0x28) = 0.01745f * (20.0f + (rand() % 100) / 4.0f);
        model[2] = 0;
        *(float *)(model + 0x20) = 0.7f + 0.03f * index;
        *(float *)(model + 0x24) = -0.4f;
        *(float *)(model + 0x28) = 0.04f - 0.1f * index;
        *(float *)(model + 0x30) = 0;
        *(float *)(model + 0x34) = 0;
        *(float *)(model + 0x38) = 0;
        *(float *)(model + 0x40) = 1.2f;
        *(float *)(model + 0x44) = 1.2f;
        *(float *)(model + 0x48) = 1.2f;
        *(float *)(model + 0x10c) = 1.0f;
        break;
    case 2:
        if (*dice != 1) {
            *(float *)(dice + 0x14) = 2.5f;
            *(float *)(dice + 8) = 0.015f;
            *(float *)(dice + 0xc) = 0.7f + 0.05f * index;
            *(float *)(dice + 4) = -0.4f;
            *(float *)(dice + 0x10) = -1.0f;
            *(float *)(dice + 0x30) = 0.6f + 0.005f * (rand() % 30 - 15);
            dice[0x34] = 0;
            dice[0x35] = 0;
            *(float *)(dice + 0x20) = 0.01745f * (1.0f + (rand() % 95) / 5.0f);
            *(float *)(dice + 0x24) = 0;
            *(float *)(dice + 0x28) = 0.01745f * (20.0f + (rand() % 100) / 4.0f);
            model[2] = 0;
            *(float *)(model + 0x20) = 0.7f + 0.03f * index;
            *(float *)(model + 0x24) = -0.4f;
            *(float *)(model + 0x28) = 0.04f - 0.1f * index;
            *(float *)(model + 0x30) = 0;
            *(float *)(model + 0x34) = 0;
            *(float *)(model + 0x38) = 0;
            *(float *)(model + 0x40) = 1.2f;
            *(float *)(model + 0x44) = 1.2f;
            *(float *)(model + 0x48) = 1.2f;
            *(float *)(model + 0x10c) = 1.0f;
        }
        CheckWarSituation();
        SND_Play2D(0x138b, 0x7f, 0);
    }
    *dice = mode;
}







/* MGDieAnimMain @ 0x1F7590 .. 0x1F7644 (0xb4 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x1f7590 if (..) goto .L001F75F0
 *   cfg: kept goto: 0x1f75cc -> .L001F7638
 *   cfg: kept branch: 0x1f75f0 if (..) goto .L001F7630
 *   cfg: kept goto: 0x1f7620 -> .L001F7638
 */


void MGDieAnimMain(void *a0 /* r4 */) {
    u8 *a2;
    u32 a1;
    u32 v1;
    u32 v0;

    v1 = (u32)(u8 *)(MdlMng + 0x17140);
    if ((u32)a0 != v1) {
        goto _L001F75F0;
    }
    v1 = *(u8 *)g_dice_anime;
    a2 = (u8 *)g_MGDieAnimFuncTbl;
    v1 = v1 << 2;
    v1 = (s32)((u8 *)g_MGDieAnimFuncTbl + (u32)v1);
    v1 = *(s32 *)v1;
    a1 = (u32)g_dice_anime;
    if (v1 != 0) {
        v0 = *(u8 *)a1;
        v0 = v0 << 2;
        v0 = (s32)(a2 + (u32)v0);
        v0 = *(s32 *)v0;
        ((void (*)(void *, u32, u32))(s32)v0)(a0, 0, (u32)a2);
        goto _L001F7638;
        _L001F75F0:;
        v1 = (u32)(u8 *)(MdlMng + 0x17300);
        if ((u32)a0 != v1) {
            goto _L001F7630;
        }
        a1 = *(u8 *)(g_dice_anime + 0x50);
        v1 = (u32)g_MGDieAnimFuncTbl;
        a1 = a1 << 2;
        v1 = (s32)((u8 *)g_MGDieAnimFuncTbl + a1);
        v1 = *(s32 *)v1;
        a1 = 1;
        if (v1 != 0) {
            ((void (*)(void *, s32))(s32)v1)(a0, a1);
            goto _L001F7638;
            _L001F7630:;
            return;
        }
    }
    _L001F7638:;
    return;
}







/* MGDiceAnimeStart @ 0x1F7530 .. 0x1F7590 (0x60 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */


void MGDiceAnimeStart(unsigned char a0 /* r4 */, unsigned char a1 /* r5 */) {
    u8 s1;
    u32 v1;

    s1 = 0;
    if (0 < (s32)a0) {
        do {
            MGDiceAnimeInit(s1, a1);
            s1 += 1;
            v1 = (s32)s1 < (s32)a0;
        } while (v1 != 0);
    }
    return;
}








/* MGDieAnimReady @ 0x1F7440 .. 0x1F7530 (0xf0 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1f7464
 *   fpu: float literal 0x40c90fdb at 0x1f74b8
 *   fpu: float literal 0x00000000 at 0x1f74cc
 *   fpu: float literal 0x40c90fdb at 0x1f74e4
 *   fpu: float literal 0x00000000 at 0x1f74fc
 *   fpu: float literal 0x40c90fdb at 0x1f7514
 *   declaration vs inferred signature: return void vs inferred float
 */


static void MGDieAnimReady(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u8 *a0_bytes; // a0
    float f1;
    float f0;
    u32 v1;

    a0_bytes = (u8 *)a0;
    v1 = (u32)g_dice_anime;
    v1 = (s32)((u8 *)g_dice_anime + (s32)((u32)((u32)a1 * (u32)(5)) << 4));
    f0 = 0.0f;
    *(f32 *)(a0_bytes + 0x30) = (*(float *)(a0_bytes + 0x30) - (*(float *)((v1 + 0x20)) * *(float
        *)((v1 + 0x14))));
    *(f32 *)(a0_bytes + 0x34) = (*(float *)(a0_bytes + 0x34) - (*(float *)((v1 + 0x24)) * *(float
        *)((v1 + 0x14))));
    *(f32 *)(a0_bytes + 0x38) = (*(float *)(a0_bytes + 0x38) - (*(float *)((v1 + 0x28)) * *(float
        *)((v1 + 0x14))));
    f1 = *(float *)(a0_bytes + 0x30);
    if (f1 < 0.0f) {
        v1 = 0x40c90fdb;
        f0 = 6.28318548f;
        *(f32 *)(a0_bytes + 0x30) = (f1 + f0);
    }
    f1 = *(float *)(a0_bytes + 0x34);
    f0 = 0.0f;
    if (f1 < 0.0f) {
        v1 = 0x40c90fdb;
        f0 = 6.28318548f;
        *(f32 *)(a0_bytes + 0x34) = (f1 + f0);
    }
    f1 = *(float *)(a0_bytes + 0x38);
    f0 = 0.0f;
    if (f1 < 0.0f) {
        v1 = 0x40c90fdb;
        f0 = 6.28318548f;
        *(f32 *)(a0_bytes + 0x38) = (f1 + f0);
    }
    return;
}




/* MGDieAnimeMain @ 0x1F6B80 .. 0x1F7434 (0x8b4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3d4ccccd at 0x1f6bc0
 *   fpu: mtc1 reinterprets s1 at 0x1f6bcc
 *   fpu: mtc1 reinterprets a0 at 0x1f6be4
 *   fpu: float literal 0x3c23d70a at 0x1f6c00
 *   fpu: float literal 0xbd1374bd at 0x1f7194
 *   fpu: mtc1 reinterprets v1 at 0x1f723c
 *   fpu: mtc1 reinterprets a0 at 0x1f7250
 *   fpu: float literal 0x3e800000 at 0x1f7268
 *   fpu: float literal 0x3f800000 at 0x1f7274
 *   fpu: mtc1 reinterprets v1 at 0x1f7294
 *   fpu: mtc1 reinterprets a0 at 0x1f72ac
 *   fpu: float literal 0x3e800000 at 0x1f72c4
 *   fpu: float literal 0x3f800000 at 0x1f72d0
 *   fpu: float literal 0x3ecccccd at 0x1f72f8
 *   fpu: float literal 0x40e00000 at 0x1f7314
 *   fpu: float literal 0x00000000 at 0x1f7318
 *   fpu: float literal 0x40c90fdb at 0x1f73a4
 *   fpu: float literal 0x00000000 at 0x1f73bc
 *   fpu: float literal 0x40c90fdb at 0x1f73d4
 *   fpu: float literal 0x00000000 at 0x1f73ec
 *   fpu: float literal 0x40c90fdb at 0x1f7404
 *   declaration vs inferred signature: return void vs inferred u32
 */

static void CatchUpModeFunc(unsigned char player);
extern void MGInitControl();
extern void SetChoisePiecePosSearch(unsigned char);
extern u8 GameSt[];

struct dw_2436777_fields;
struct dw_2442349_fields;
#ifndef PROTO_DW_2435537_FIELDS
#define PROTO_DW_2435537_FIELDS
struct dw_2435537_fields { unsigned char IndexAnim; unsigned char _pad0[3]; float height; float move_speed; float frame_num; float tilt; float angle_speed; unsigned char _pad1[8]; float local_ang[4]; float offset; unsigned char count; unsigned char num; unsigned char _pad2[10]; float quaternion[4]; };
#endif
#ifndef PROTO_DW_2441806_FIELDS
#define PROTO_DW_2441806_FIELDS
struct dw_2441806_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_2440075_FIELDS
#define PROTO_DW_2440075_FIELDS
struct dw_2440075_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_2439753_FIELDS
#define PROTO_DW_2439753_FIELDS
struct dw_2439753_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_2436777_fields *lpMdl; };
#endif
#ifndef PROTO_DW_2436777_FIELDS
#define PROTO_DW_2436777_FIELDS
struct dw_2436777_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_2442349_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_2436777_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_2441806_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_2440075_fields flags; unsigned char _pad1[3]; struct dw_2439753_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_2440241_FIELDS
#define PROTO_DW_2440241_FIELDS
struct dw_2440241_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#define MGDM_PIECES(SCN, SRCH) \
    { \
        unsigned char *pPiecePos; \
        struct MGPieceTbl *pTable; \
        unsigned int PieceNum; \
        unsigned int PID; \
        pPiecePos = GetChoisePiecePos(); \
        pTable = (struct MGPieceTbl *)GetPieceTable(); \
        SetChoisePiecePosSearch(SRCH); \
        PieceNum = pTable[*pPiecePos].PieceNum - 1; \
        PID = pTable[*pPiecePos].PieceID[PieceNum]; \
        g_piece_anime[PID].IndexAnim = 1; \
        g_piece_anime[PID].height = pTable[*pPiecePos].PiecePos[PieceNum][1]; \
        GameSt[9] = SCN; \
        MGInitControl(); \
    }
#define MGDM_ALPHA \
    { \
        struct dw_2436777_fields *pMdl = (struct dw_2436777_fields *)(MdlMng + 0x17140); \
        pMdl[0].Alpha = 0.3f; \
        pMdl[1].Alpha = 0.3f; \
    }
#define DIE ((struct dw_2435537_fields *)g_dice_anime)

void MGDieAnimeMain(struct dw_2436777_fields *lpMdlMng, unsigned int AniID) {
    struct dw_2435537_fields *pAnimeInfo;
    float Die_Ang_X;

    pAnimeInfo = DIE + AniID;
    if (pAnimeInfo->height > -(0.01f + 0.05f * (float)AniID)) {
        unsigned char *pDieNum;

        lpMdlMng->Pos[1] = -0.036000002f;
        pAnimeInfo->IndexAnim = 3;
        pAnimeInfo->count = 0;
        Die_Ang_X = lpMdlMng->Ang[0];
        MGReviseAngle(&lpMdlMng->Ang[2]);
        MGReviseAngle(&lpMdlMng->Ang[0]);
        pAnimeInfo->num = MGGetDieNum(lpMdlMng);
        lpMdlMng->Ang[1] = Die_Ang_X;
        CatchUpModeFunc(AniID);
        if (DIE[0].IndexAnim != 2 && DIE[1].IndexAnim != 2) {
            pDieNum = (unsigned char *)GetDiceNum();
            if (GameSt[9] == 0xa) {
                pDieNum[0] = DIE[0].num;
                GameSt[9] = 0xb;
                MGInitControl();
            } else if (GameSt[9] == 0xd) {
                pDieNum[1] = DIE[0].num;
                GameSt[9] = 0xe;
                MGInitControl();
            } else if (GameSt[9] == 0x11) {
                lpMdlMng = (struct dw_2436777_fields *)(MdlMng + 0x17140);
                lpMdlMng[0].Alpha = 0.3f;
                lpMdlMng[1].Alpha = 0.3f;
                pDieNum[0] = DIE[0].num;
                pDieNum[1] = DIE[1].num;
                MGDM_PIECES(0x12, 1)
            } else if (GameSt[9] == 0x16) {
                MGDM_ALPHA
                pDieNum[0] = DIE[0].num;
                pDieNum[1] = DIE[1].num;
                GameSt[9] = 0x17;
                MGInitControl();
            } else if (GameSt[9] == 0x24) {
                MGDM_ALPHA
                pDieNum[0] = DIE[0].num;
                pDieNum[1] = DIE[1].num;
                GameSt[9] = 0x25;
                MGInitControl();
                MGDM_PIECES(0x25, 1)
            } else if (GameSt[9] == 0x30) {
                pDieNum[0] = DIE[0].num;
                GameSt[9] = 0x31;
                MGInitControl();
            } else if (GameSt[9] == 0x33) {
                pDieNum[1] = DIE[0].num;
                GameSt[9] = 0x34;
                MGInitControl();
            } else if (GameSt[9] == 0x37) {
                MGDM_ALPHA
                pDieNum[0] = DIE[0].num;
                pDieNum[1] = DIE[1].num;
                GameSt[9] = 0x38;
                MGInitControl();
                MGDM_PIECES(0x38, 1)
            } else if (GameSt[9] == 0x3c) {
                MGDM_ALPHA
                pDieNum[0] = DIE[0].num;
                pDieNum[1] = DIE[1].num;
                GameSt[9] = 0x3d;
                MGInitControl();
                MGDM_PIECES(0x3d, 0)
            }
        }
        return;
    }
    if (lpMdlMng->Pos[1] >= -0.036000002f) {
        if (pAnimeInfo->count == 0) {
            SND_Play2D(0x138c, 0x7f, 0);
        } else if (pAnimeInfo->count == 1) {
            SND_Play2D(0x1393, 0x7f, 0);
        } else if (pAnimeInfo->count == 2) {
            SND_Play2D(0x1394, 0x7f, 0);
        }
        pAnimeInfo->count = pAnimeInfo->count + 1;
        lpMdlMng->Pos[1] = -0.036000002f;
        pAnimeInfo->height = pAnimeInfo->height * (1.0f - 0.25f * (float)(unsigned int)pAnimeInfo->count);
        pAnimeInfo->offset = lpMdlMng->Pos[0] - (1.0f - 0.25f * (float)(unsigned int)pAnimeInfo->count) * (pAnimeInfo->offset - lpMdlMng->Pos[0]);
        pAnimeInfo->angle_speed = pAnimeInfo->angle_speed * 0.4f;
    }
    pAnimeInfo->frame_num = pAnimeInfo->frame_num - pAnimeInfo->move_speed;
    lpMdlMng->Pos[0] = pAnimeInfo->frame_num;
    lpMdlMng->Pos[1] = pAnimeInfo->height + 7.0f * (pAnimeInfo->frame_num - pAnimeInfo->offset) * (pAnimeInfo->frame_num - pAnimeInfo->offset);
    lpMdlMng->Ang[0] = lpMdlMng->Ang[0] - pAnimeInfo->local_ang[0] * pAnimeInfo->angle_speed;
    lpMdlMng->Ang[1] = lpMdlMng->Ang[1] - pAnimeInfo->local_ang[1] * pAnimeInfo->angle_speed;
    lpMdlMng->Ang[2] = lpMdlMng->Ang[2] - pAnimeInfo->local_ang[2] * pAnimeInfo->angle_speed;
    if (lpMdlMng->Ang[0] < 0.0f) {
        lpMdlMng->Ang[0] = lpMdlMng->Ang[0] + 6.2831855f;
    }
    if (lpMdlMng->Ang[1] < 0.0f) {
        lpMdlMng->Ang[1] = lpMdlMng->Ang[1] + 6.2831855f;
    }
    if (lpMdlMng->Ang[2] < 0.0f) {
        lpMdlMng->Ang[2] = lpMdlMng->Ang[2] + 6.2831855f;
    }
}







/* MGDieSelectAnim @ 0x1F69B0 .. 0x1F6B78 (0x1c8 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3cf5c28f at 0x1f69e0
 *   fpu: mtc1 reinterprets a3 at 0x1f69ec
 *   fpu: mtc1 reinterprets a2 at 0x1f6a00
 *   fpu: float literal 0x3f800000 at 0x1f6a18
 *   fpu: mtc1 reinterprets a1 at 0x1f6a34
 *   fpu: mtc1 reinterprets a2 at 0x1f6a48
 *   fpu: float literal 0x3cf5c28f at 0x1f6a64
 *   fpu: float literal 0x3f800000 at 0x1f6a68
 *   fpu: mtc1 reinterprets a1 at 0x1f6a88
 *   fpu: mtc1 reinterprets a2 at 0x1f6a9c
 *   fpu: float literal 0x3cf5c28f at 0x1f6ab8
 *   fpu: float literal 0x3f800000 at 0x1f6abc
 *   fpu: mtc1 reinterprets a1 at 0x1f6adc
 *   fpu: float literal 0x3bc49ba6 at 0x1f6af8
 *   fpu: float literal 0x3fa66666 at 0x1f6afc
 *   fpu: mtc1 reinterprets a1 at 0x1f6b18
 *   fpu: mtc1 reinterprets a1 at 0x1f6b38
 *   declaration vs inferred signature: return void vs inferred float
 */


static void MGDieSelectAnim(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u32 a3;
    u32 a2;
    float f2;
    float f1;
    float f0;
    u8 *a0_bytes; // a0
    u32 v1;
    u8 *v1_address; // v1

    a0_bytes = (u8 *)a0;
    v1 = (u32)g_dice_anime;
    v1_address = (u8 *)((u8 *)g_dice_anime + (u32)((u32)((u32)a1 * (u32)(5)) << 4));
    a3 = *(u8 *)(v1_address + 0x34);
    if ((s32)a3 < (s32)0xb) {
        a1 = 0x3cf5c28f;
        f0 = 1.0f;
        *(f32 *)(a0_bytes + 0x40) = (1.0f + (0.0299999993f * (float)(float)a3));
        a1 = *(u8 *)(v1_address + 0x34);
        f1 = 0.0299999993f;
        f0 = 1.0f;
        *(f32 *)(a0_bytes + 0x44) = (1.0f + (0.0299999993f * (float)(float)(u32)a1));
        a1 = *(u8 *)(v1_address + 0x34);
        f2 = (float)(u32)a1;
        a1 = 0x3f800000;
        a2 = 0x3cf5c28f;
        f1 = 0.0299999993f;
        f0 = 1.0f;
        *(f32 *)(a0_bytes + 0x48) = (1.0f + (0.0299999993f * f2));
    } else {
        a1 = 0x3bc40000;
        a2 = 0x3bc40000 | 0x9ba6;
        f2 = 0.00600000005f;
        f1 = 1.29999995f;
        *(f32 *)(a0_bytes + 0x40) = (1.29999995f - (0.00600000005f * (float)((float)(s32)(u32)(a3 +
            -0xa))));
        a1 = *(u8 *)(v1_address + 0x34);
        *(f32 *)(a0_bytes + 0x44) = (1.29999995f - (0.00600000005f *
            (float)((float)(s32)(u32)((u32)(a1) + -0xa))));
        a1 = *(u8 *)(v1_address + 0x34);
        *(f32 *)(a0_bytes + 0x48) = (1.29999995f - (0.00600000005f *
            (float)((float)(s32)(u32)((u32)(a1) + -0xa))));
    }
    a1 = *(u8 *)(v1_address + 0x34);
    a0_bytes = (u8 *)(s32)0x3c;
    *(u8 *)(v1_address + 0x34) = (u32)(a1) + 1;
    a1 = *(u8 *)(v1_address + 0x34);
    if ((u32)a1 == (u32)(s32)a0_bytes) {
        *(u8 *)(v1_address + 0x34) = 0;
    }
    return;
}











/* MGReviseAngle @ 0x1F6860 .. 0x1F69B0 (0x150 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40c90fdb at 0x1f686c
 *   fpu: float literal 0x3f490fdb at 0x1f68a8
 *   fpu: float literal 0x40afeddf at 0x1f68c0
 *   fpu: float literal 0x4016cbe4 at 0x1f68f8
 *   fpu: float literal 0x4016cbe4 at 0x1f6928
 *   fpu: float literal 0x407b53d2 at 0x1f6940
 *   fpu: float literal 0x407b53d2 at 0x1f6970
 *   fpu: float literal 0x40afeddf at 0x1f6988
 *   cfg: kept branch: 0x1f68b8 if (..) goto .L001F68E8
 *   cfg: kept goto: 0x1f68d8 -> .L001F69A8
 *   cfg: kept branch: 0x1f68f0 if (..) goto .L001F6920
 *   cfg: kept branch: 0x1f6938 if (..) goto .L001F6968
 *   declaration vs inferred signature: return void vs inferred u32
 */





static void MGReviseAngle(float *a0 /* r4 */) {
    float f2;
    s32 v1;
    float f1;
    s32 fpcc;
    float f0;

    f2 = *(float *)a0;
    v1 = 0x40c90fdb;
    f1 = 6.28318548f;
    fpcc = f2 < 6.28318548f;
    if (!fpcc) {
        do {
            f2 = (*(float *)a0 - f1);
            *(f32 *)a0 = f2;
        } while (f2 >= f1);
    }
    v1 = 0x3f490fdb;
    f1 = 0.785398185f;
    fpcc = f2 < 0.785398185f;
    if (!fpcc) {
        v1 = 0x40afeddf;
        f0 = 5.497787f;
        fpcc = f2 < 5.497787f;
        if (fpcc) {
            goto _L001F68E8;
        }
    }
    v1 = 0x40c90fdb;
    *(u32 *)a0 = 0x40c90fdb;
    goto _L001F69A8;
    _L001F68E8:;
    fpcc = f2 < f1;
    if (!fpcc) {
        v1 = 0x4016cbe4;
        f0 = 2.3561945f;
        fpcc = f2 < 2.3561945f;
        if (!fpcc) {
            goto _L001F6920;
        }
        v1 = 0x3fc90fdb;
        *(u32 *)a0 = 0x3fc90fdb;
    } else {
        _L001F6920:;
        v1 = 0x4016cbe4;
        f0 = 2.3561945f;
        fpcc = f2 < 2.3561945f;
        if (!fpcc) {
            v1 = 0x407b53d2;
            f0 = 3.92699099f;
            fpcc = f2 < 3.92699099f;
            if (!fpcc) {
                goto _L001F6968;
            }
            v1 = 0x40490fdb;
            *(u32 *)a0 = 0x40490fdb;
        } else {
            _L001F6968:;
            v1 = 0x407b53d2;
            f0 = 3.92699099f;
            fpcc = f2 < 3.92699099f;
            if (!fpcc) {
                v1 = 0x40afeddf;
                f0 = 5.497787f;
                fpcc = f2 < 5.497787f;
                if (fpcc) {
                    v1 = 0x4096cbe4;
                    *(u32 *)a0 = 0x4096cbe4;
                }
            }
        }
    }
    _L001F69A8:;
    return;
}


struct dw_2436777_fields;
extern void MGDieAnimeMain(struct dw_2436777_fields *, unsigned int);
static u32 g_MGDieAnimFuncTbl[0x6] = {
    0, (u32)&MGDieAnimReady, (u32)&MGDieAnimeMain, 0, (u32)&MGDieSelectAnim
};
extern void MGPieceMoveAnime(struct dw_2436777_fields *, unsigned int);
static u32 g_MGPieceAnimFuncTbl[0x3] = {
    0, (u32)&MGPieceSelectAnime, (u32)&MGPieceMoveAnime
};

/* MGGetDieNum @ 0x1F65E0 .. 0x1F6860 (0x280 bytes, frame 0xb0) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @856 -> 0x249f50
 *   stack: address of the slot at 0x30 escapes at 0x1f6620
 *   stack: address of the slot at 0x70 escapes at 0x1f6620
 *   fpu: float literal 0x40490fdb at 0x1f6634
 *   fpu: float literal 0x00000000 at 0x1f6638
 *   fpu: float literal 0x40c90fdb at 0x1f6658
 *   fpu: mtc1 reinterprets v0 at 0x1f667c
 *   stack: address of the slot at 0x30 escapes at 0x1f66a0
 *   stack: address of the slot at 0x30 escapes at 0x1f66a0
 *   fpu: float literal 0x40490fdb at 0x1f66b4
 *   fpu: float literal 0x00000000 at 0x1f66b8
 *   fpu: float literal 0x40c90fdb at 0x1f66d8
 *   fpu: mtc1 reinterprets v0 at 0x1f66fc
 *   stack: address of the slot at 0x30 escapes at 0x1f6720
 *   stack: address of the slot at 0x30 escapes at 0x1f6720
 *   fpu: float literal 0x40490fdb at 0x1f6734
 *   fpu: float literal 0x00000000 at 0x1f6738
 *   fpu: float literal 0x40c90fdb at 0x1f6758
 *   fpu: mtc1 reinterprets v0 at 0x1f677c
 *   stack: address of the slot at 0x30 escapes at 0x1f67a0
 *   stack: address of the slot at 0x30 escapes at 0x1f67a0
 *   fpu: float literal 0x3f800000 at 0x1f67b0
 *   fpu: float literal 0xbf800000 at 0x1f67d4
 *   literal: @856 initializes the 64-byte local at 0x70
 *   declaration vs inferred signature: return unsigned char vs inferred u_long128
 */


static unsigned char MGGetDieNum(void *a0 /* r4 */) {
    u32 v0;
    float f12;
    float f3;
    float f3_v1; // f3
    float f3_v2; // f3
    float f2;
    float f1;
    float f0;
    u8 s0;

    v0 = (u32)L856;
    {
        struct stackFrame_70 { u8 b[64]; } stackFrame_70 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
            0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f}};
        u8 stackFrame_30[64] __attribute__((aligned(16)));
        sceVu0CopyMatrix((void *)((u8 *)&stackFrame_30[0]), (void *)(u8 *)((u8 *)&stackFrame_70));
        f2 = *(float *)(((u8 *)a0 + 0x30));
        f1 = 3.14159274f;
        f0 = 0.0f;
        f3 = (3.14159274f + f2);
        if (f3 >= 0.0f) {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f2 - (6.28318548f * (float)((float)(s32)(f3 / 6.28318548f))));
        } else {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f1 + (f2 - (f1 * (float)((float)(s32)(f3 / f1)))));
        }
        sceVu0RotMatrixX((void *)(float *)((u8 *)&stackFrame_30[0]), (void *)(u8 *)((u8
            *)&stackFrame_30[0]), f12);
        f2 = *(float *)(((u8 *)a0 + 0x38));
        f1 = 3.14159274f;
        f0 = 0.0f;
        f3_v1 = (3.14159274f + f2);
        if (f3_v1 >= 0.0f) {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f2 - (6.28318548f * (float)((float)(s32)(f3_v1 / 6.28318548f))));
        } else {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f1 + (f2 - (f1 * (float)((float)(s32)(f3_v1 / f1)))));
        }
        sceVu0RotMatrixZ((void *)(float *)((u8 *)&stackFrame_30[0]), (void *)(u8 *)((u8
            *)&stackFrame_30[0]), f12);
        f2 = *(float *)(((u8 *)a0 + 0x34));
        f1 = 3.14159274f;
        f0 = 0.0f;
        f3_v2 = (3.14159274f + f2);
        if (f3_v2 >= 0.0f) {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f2 - (6.28318548f * (float)((float)(s32)(f3_v2 / 6.28318548f))));
        } else {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f12 = (f1 + (f2 - (f1 * (float)((float)(s32)(f3_v2 / f1)))));
        }
        sceVu0RotMatrixY((void *)(float *)((u8 *)&stackFrame_30[0]), (void *)(u8 *)((u8
            *)&stackFrame_30[0]), f12);
        f2 = ((float *)stackFrame_30)[9];
        v0 = 0x3f800000;
        f1 = 1.0f;
        if (1.0f == f2) {
            s0 = 4;
        } else {
            v0 = -0x40800000;
            f0 = -1.0f;
            if (-1.0f == f2) {
                s0 = 3;
            } else {
                f2 = ((float *)stackFrame_30)[1];
                if (f1 == f2) {
                    s0 = 2;
                } else if (f0 == f2) {
                    s0 = 5;
                } else {
                    f2 = ((float *)stackFrame_30)[5];
                    if (f1 == f2) {
                        s0 = 1;
                    } else if (f0 == f2) {
                        s0 = 6;
                    }
                }
            }
        }
        return s0;
    }
}







/* MGSetDieOneNum @ 0x1F64C0 .. 0x1F65DC (0x11c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @1386 -> 0x257270
 *   indirect: jr v1 at 0x1f6540 -> <v1>
 *   declaration vs inferred signature: return void vs inferred u32
 */




static void MGSetDieOneNum(unsigned char a0 /* r4 */) {
    u32 a0_word = a0;
    u8 s1;
    u8 *a2;
    u8 *s0;
    u32 v1;
    u32 v0;

    s1 = a0;
    s0 = MdlMng + ((u8)a0_word + 0xd3) * 0x1c0;
    v0 = GetDiceNum();
    a2 = (u8 *)(v0 + (u8)s1);
    (&g_dice_anime[0x35])[(u8)s1 * 0x50] = *a2;
    v1 = *(u8 *)a2;
    switch (v1) {
    case 6:
        v1 = 0x40490fdb;
        *(u32 *)(s0 + 0x30) = 0x40490fdb;
        *(u32 *)(s0 + 0x38) = 0;
        break;
    case 5:
        *(u32 *)(s0 + 0x30) = 0;
        v1 = -0x4036f025;
        *(u32 *)(s0 + 0x38) = -0x4036f025;
        break;
    case 4:
        v1 = -0x4036f025;
        *(u32 *)(s0 + 0x30) = -0x4036f025;
        *(u32 *)(s0 + 0x38) = 0;
        break;
    case 3:
        v1 = 0x3fc90fdb;
        *(u32 *)(s0 + 0x30) = 0x3fc90fdb;
        *(u32 *)(s0 + 0x38) = 0;
        break;
    case 2:
        *(u32 *)(s0 + 0x30) = 0;
        v1 = 0x3fc90fdb;
        *(u32 *)(s0 + 0x38) = 0x3fc90fdb;
        break;
    case 1:
        *(u32 *)(s0 + 0x30) = 0;
        *(u32 *)(s0 + 0x38) = 0;
    case 0:
    default:
        break;
    }
    return;
}





void MGPieceAnimeMain(void *lpMdlMng) {
    unsigned int AniID;

    for (AniID = 0; AniID < 30; AniID++) {
        if (lpMdlMng == MdlMng + (AniID + 161) * 0x1c0) {
            if (g_MGDieAnimFuncTbl[((u8 *)g_piece_anime)[AniID * 0x50]] == 0) {
                return;
            }
            ((void (*)(void *, unsigned int))g_MGPieceAnimFuncTbl[((u8 *)g_piece_anime)[AniID * 0x50]])(lpMdlMng, AniID);
        }
    }
}







/* MGPieceSelectAnimeInit @ 0x1F63A0 .. 0x1F63E8 (0x48 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred float
 */


void MGPieceSelectAnimeInit(unsigned int a0 /* r4 */) {
    u32 v1;
    u32 a1;
    float f0;

    a1 = (u32)((u32)a0) * (u32)(0x50);
    a0 = (u32)(a0) + 0xa1;
    v1 = (u32)g_piece_anime;
    a1 = (s32)((u8 *)g_piece_anime + a1);
    *(u8 *)a1 = 1;
    v1 = (u32)MdlMng;
    f0 = *(float *)(((u32)(s32)((u8 *)MdlMng + (s32)((u32)((u32)((u32)a0) * (u32)(7)) << 6)) +
        0x24));
    *(f32 *)((a1 + 4)) = f0;
    return;
}






/* MGPieceSelectAnimeExit @ 0x1F6340 .. 0x1F63A0 (0x60 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1f6380
 *   tail: j ChangeAnimParam at 0x1f6398 leaves the function
 */


void MGPieceSelectAnimeExit(unsigned int a0 /* r4 */) {
    u8 *a2;
    s32 v1;
    u32 v0;

    v0 = (u32)g_piece_anime;
    v1 = (u32)(a0) + 0xa1;
    a2 = (u8 *)((u8 *)g_piece_anime + (u32)((u32)a0 * 0x50));
    *(u8 *)a2 = 0;
    v0 = (u32)MdlMng;
    a0 = (s32)((u8 *)MdlMng + (s32)((u32)v1 * 0x1c0));
    v0 = 0x43340000;
    *(f32 *)(((s32)(a0) + 0x24)) = *(float *)(a2 + 4);
    *(f32 *)(((s32)(a0) + 0x30)) = 0.0f;
    *(f32 *)(((s32)(a0) + 0x34)) = 0.0f;
    *(f32 *)(((s32)(a0) + 0x38)) = 0.0f;
    *(u32 *)(a2 + 0x14) = 0x43340000;
    ChangeAnimParam((void *)a0, 0, 0.0f);
    return;
}






/* MGPieceSelectAnime @ 0x1F6240 .. 0x1F6340 (0x100 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40c00000 at 0x1f627c
 *   fpu: float literal 0x43340000 at 0x1f6280
 *   fpu: mtc1 reinterprets v1 at 0x1f62c0
 *   fpu: float literal 0x3ca3d70a at 0x1f62c8
 *   fpu: float literal 0x3c8ef34d at 0x1f62ec
 *   fpu: float literal 0x3ca3d70a at 0x1f6318
 *   declaration vs inferred signature: return void vs inferred float
 * hand: the angle-scale multiply needs its loaded operand cast to float
 *   ((float)x * 0.01745f) to keep MWCC from swapping the operands (const went
 *   to f0, the lwc1 reload to f1).
 */


static void MGPieceSelectAnime(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    s32 v1;
    s32 v0;
    u8 *s0;
    float f12;
    float f1;
    float f20;
    float f0;
    void *a0_2;

    v1 = 0x40c00000;
    a0_2 = (void *)g_piece_anime;
    v0 = 0x43340000;
    s0 = (u8 *)((u8 *)g_piece_anime + (s32)((u32)a1 * 0x50));
    f1 = 6.0f;
    f0 = 180.0f;
    f1 = (*(float *)(s0 + 0x14) + (float)f1);
    *(f32 *)(s0 + 0x14) = f1;
    if (!(f1 < 180.0f)) {
        v0 = -0x3ccc0000;
        *(f32 *)(s0 + 0x14) = -180.0f;
        v0 = rand();
        v1 = v0 % 2;
        v0 = 0x3ca3d70a;
        f0 = 0.02f;
        *(f32 *)(s0 + 0x18) = (0.02f * (float)((float)(s32)(u32)(v1 + 1)));
    }
    f20 = *(float *)(s0 + 0x18);
    f12 = ((float)*(float *)(s0 + 0x14) * 0.01745f);
    *(f32 *)(((u8 *)a0 + 0x24)) = ((*(float *)(s0 + 4) + (f20 * (-cosf(f12)))) - f20) - 0.02f;
    return;
}


/* MGPieceMoveAnimeFirstInit @ 0x1F61F0 .. 0x1F623C (0x4c bytes) */


void MGPieceMoveAnimeFirstInit(unsigned char a0 /* r4 */, unsigned int a1 /* r5 */) {
    u32 a0_word;
    u8 *a1_address; // a1
    u32 v1;

    v1 = (s32)(a0 * (u32)(5));
    a1_address = (u8 *)((u8 *)g_piece_anime + (u32)((u32)((u32)a1 * 5) << 4));
    a0_word = v1 << 4;
    *(u8 *)a1_address = 0;
    v1 = (u32)g_dice_anime;
    a0_word = (s32)((u8 *)g_dice_anime + (u32)a0_word);
    a0_word = *(u8 *)((a0_word + 0x35));
    *(u8 *)(a1_address + 0x45) = a0_word;
    *(u8 *)(a1_address + 0x46) = 1;
    return;
}






/* MGPieceMoveAnimeInit @ 0x1F5F70 .. 0x1F61E4 (0x274 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v1 at 0x1f6144
 *   fpu: mtc1 reinterprets a0 at 0x1f615c
 *   cfg: kept branch: 0x1f603c if (..) goto .L001F6050
 *   declaration vs inferred signature: return void vs inferred float
 */


void MGPieceMoveAnimeInit(unsigned int a0 /* r4 */) {
    s32 s4;
    u8 a2;
    u32 a1;
    u32 v1;
    u8 *s3;
    u8 *s2;
    u32 v0;
    float f0;
    u8 *s1;
    u8 *s0;

    s4 = a0;
    v1 = s4 + 0xa1;
    a0 = (u32)a0 * 0x50;
    a1 = (u32)g_piece_anime;
    s3 = (u8 *)((u8 *)g_piece_anime + a0);
    v1 = v1 * 0x1c0;
    v0 = (u32)MdlMng;
    a0 = 0x138a;
    s2 = (u8 *)((u8 *)MdlMng + v1);
    a1 = 0x7f;
    a2 = 0x64;
    SND_Play2D(a0, a1, a2);
    v0 = 2;
    *(u8 *)s3 = v0;
    *(f32 *)(s3 + 0x20) = *(float *)(s2 + 0x20);
    *(f32 *)(s3 + 0x24) = *(float *)(s2 + 0x24);
    f0 = *(float *)(s2 + 0x28);
    *(f32 *)(s3 + 0x28) = f0;
    v0 = (u32)GetChoisePiecePos();
    s1 = (u8 *)v0;
    v0 = (u32)GetPieceTable();
    a1 = *(u8 *)s1;
    s0 = (u8 *)v0;
    v1 = 0xb;
    a0 = a1 * 0x1a0;
    a0 = v0 + (u32)(a0);
    v0 = *(u8 *)a0;
    v0 = v0 + -1;
    *(u8 *)a0 = v0;
    a0 = *(u8 *)s1;
    if ((u32)a0 != v1) {
        v0 = 0x17;
        if ((u32)a0 != v0) {
            goto _L001F6050;
        }
    }
    v0 = -1;
    *(s8 *)(s3 + 0x46) = v0;
    _L001F6050:;
    a0 = (s32)s4;
    SetPieceAnimeMovePos(a0);
    a1 = *(u8 *)s1;
    a0 = 0x14;
    v1 = a1 * 0x1a0;
    a1 = (s32)(s0 + v1);
    v1 = *(u8 *)a1;
    v1 = v1 + 1;
    *(u8 *)a1 = v1;
    a1 = *(u8 *)s1;
    v1 = a1 * 0x1a0;
    a1 = (s32)(s0 + v1);
    v1 = *(u8 *)a1;
    v1 = v1 + -1;
    *(u8 *)(((u32)(v1 + a1) + 1)) = s4;
    v1 = v1 << 4;
    a2 = *(u8 *)s1;
    a1 = (u32)a2 * 0x1a0;
    a1 = (s32)((u8 *)a1 + (u32)(s0));
    a1 = v1 + (u32)a1;
    *(f32 *)(s3 + 0x30) = *(float *)((a1 + 0x20));
    a2 = *(u8 *)s1;
    a1 = (u32)a2 * 0x1a0;
    a1 = (s32)((u8 *)a1 + (u32)(s0));
    a1 = v1 + (u32)a1;
    *(f32 *)(s3 + 0x34) = *(float *)((a1 + 0x24));
    a2 = *(u8 *)s1;
    a1 = (u32)a2 * 0x1a0;
    a1 = (s32)((u8 *)a1 + (u32)(s0));
    v1 = v1 + a1;
    *(f32 *)(s3 + 0x38) = *(float *)((v1 + 0x28));
    *(u8 *)(s3 + 0x44) = a0;
    v1 = *(u8 *)(s3 + 0x44);
    *(f32 *)(s3 + 8) = ((*(float *)(s3 + 0x30) - *(float *)(s3 + 0x20)) / (float)(float)v1);
    *(f32 *)(s3 + 0xc) = *(float *)(s2 + 0x20);
    *(f32 *)(s3 + 0x10) = ((*(float *)(s3 + 0x34) - *(float *)(s3 + 0x24)) / (*(float *)(s3 + 0x30)
        - *(float *)(s3 + 0x20)));
    *(f32 *)(s3 + 0x40) = ((*(float *)(s3 + 0x38) - *(float *)(s3 + 0x28)) / (*(float *)(s3 + 0x30)
        - *(float *)(s3 + 0x20)));
    return;
}





/* MGPieceMoveAnime @ 0x1F57F0 .. 0x1F5F64 (0x774 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42480000 at 0x1f5814
 *   delay: addiu at 0x1f5a58 writes a register its branch at 0x1f5a54 reads
 *   delay: addiu at 0x1f5ad8 writes a register its branch at 0x1f5ad4 reads
 *   delay: addiu at 0x1f5ba8 writes a register its branch at 0x1f5ba4 reads
 *   delay: addiu at 0x1f5cbc writes a register its branch at 0x1f5cb8 reads
 *   delay: addiu at 0x1f5d3c writes a register its branch at 0x1f5d38 reads
 *   delay: addiu at 0x1f5e54 writes a register its branch at 0x1f5e50 reads
 *   cfg: kept branch: 0x1f59f0 if (..) goto .L001F5A18
 *   cfg: kept goto: 0x1f5a00 -> .L001F5A28
 *   cfg: kept branch: 0x1f5a58 if (..) goto .L001F5AD0
 *   cfg: kept goto: 0x1f5ab8 -> .L001F5B40
 *   cfg: kept branch: 0x1f5ad8 if (..) goto .L001F5B40
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 GetChoiseDiePos();
extern void SetWinNumAdd(unsigned char);
extern void SetWinFlag(unsigned char);
extern void MGInitControl(void);
extern void SetChoisePiecePosSearch(unsigned char);
extern u8 GameSt[];


struct dw_2442349_fields;
#ifndef PROTO_DW_2435537_FIELDS
#define PROTO_DW_2435537_FIELDS
struct dw_2435537_fields { unsigned char IndexAnim; unsigned char _pad0[3]; float height; float move_speed; float frame_num; float tilt; float angle_speed; unsigned char _pad1[8]; float local_ang[4]; float offset; unsigned char count; unsigned char num; unsigned char _pad2[10]; float quaternion[4]; };
#endif
#ifndef PROTO_DW_2441806_FIELDS
#define PROTO_DW_2441806_FIELDS
struct dw_2441806_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_2440075_FIELDS
#define PROTO_DW_2440075_FIELDS
struct dw_2440075_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_2439753_FIELDS
#define PROTO_DW_2439753_FIELDS
struct dw_2439753_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_2436777_fields *lpMdl; };
#endif
#ifndef PROTO_DW_2436777_FIELDS
#define PROTO_DW_2436777_FIELDS
struct dw_2436777_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_2442349_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_2436777_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_2441806_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_2440075_fields flags; unsigned char _pad1[3]; struct dw_2439753_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_2440241_FIELDS
#define PROTO_DW_2440241_FIELDS
struct dw_2440241_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif


#define MGPMA_DICE(SCN0, SCN1, SRCH) \
    if (g_dice_anime[0x35] == 0 && g_dice_anime[0x85] == 0) { \
        GameSt[9] = SCN0; \
        MGInitControl(); \
    } else { \
        unsigned char *pDieNum; \
        unsigned char *pPiecePos; \
        struct MGPieceTbl *pTbl; \
        unsigned int PN; \
        unsigned int PID; \
        pDieNum = (unsigned char *)GetDiceNum(); \
        pDieNum[0] = g_dice_anime[0x35]; \
        pDieNum[1] = g_dice_anime[0x85]; \
        pPiecePos = GetChoisePiecePos(); \
        pTbl = (struct MGPieceTbl *)GetPieceTable(); \
        SetChoisePiecePosSearch(SRCH); \
        PN = pTbl[*pPiecePos].PieceNum - 1; \
        PID = pTbl[*pPiecePos].PieceID[PN]; \
        g_piece_anime[PID].IndexAnim = 1; \
        g_piece_anime[PID].height = pTbl[*pPiecePos].PiecePos[PN][1]; \
        GameSt[9] = SCN1; \
        MGInitControl(); \
    }

void MGPieceMoveAnime(struct dw_2436777_fields *lpMdlMng, unsigned int AniID) {
    struct MGAnimeInfo *pAnimeInfo;
    unsigned char *pChoisePiecePos;
    struct MGPieceTbl *pTable;
    unsigned int PieceNum;

    pAnimeInfo = g_piece_anime + AniID;
    lpMdlMng->Pos[0] = pAnimeInfo->frame_num;
    lpMdlMng->Pos[1] = pAnimeInfo->start_pos[1] + (50.0f * (pAnimeInfo->frame_num - pAnimeInfo->start_pos[0]) * (pAnimeInfo->frame_num - pAnimeInfo->end_pos[0]) + pAnimeInfo->tilt * (pAnimeInfo->frame_num - pAnimeInfo->start_pos[0]));
    lpMdlMng->Pos[2] = pAnimeInfo->start_pos[2] + pAnimeInfo->tilt_z * (pAnimeInfo->frame_num - pAnimeInfo->start_pos[0]);
    pAnimeInfo->frame_num = pAnimeInfo->frame_num + pAnimeInfo->move_speed;
    if (pAnimeInfo->key_count > 0) {
        pAnimeInfo->key_count = pAnimeInfo->key_count - 1;
    } else {
        pChoisePiecePos = GetChoisePiecePos();
        pTable = (struct MGPieceTbl *)GetPieceTable();
        PieceNum = pTable[*pChoisePiecePos].PieceNum - 1;
        pTable[*pChoisePiecePos].PieceID[PieceNum] = AniID;
        lpMdlMng->Pos[0] = pTable[*pChoisePiecePos].PiecePos[PieceNum][0];
        lpMdlMng->Pos[1] = pTable[*pChoisePiecePos].PiecePos[PieceNum][1];
        lpMdlMng->Pos[2] = pTable[*pChoisePiecePos].PiecePos[PieceNum][2];
        if (pAnimeInfo->num > 1) {
            pAnimeInfo->num = pAnimeInfo->num - 1;
            MGPieceMoveAnimeInit(AniID);
        } else {
            unsigned char *pChoiseDie;
            unsigned char *pChoisePiece;
            struct dw_2436777_fields *pMdlMngDie;
            struct MGPieceTbl *pTable2;
            struct dw_2436777_fields *pMdlMngPieceMove0;
            struct dw_2436777_fields *pMdlMngPieceMove1;

            pChoiseDie = (unsigned char *)GetChoiseDiePos();
            pChoisePiece = GetChoisePiecePos();
            pMdlMngDie = (struct dw_2436777_fields *)(MdlMng + (*pChoiseDie + 0xd3) * 0x1c0);
            pTable2 = (struct MGPieceTbl *)GetPieceTable();
            pMdlMngPieceMove0 = (struct dw_2436777_fields *)(MdlMng + 0x14e40);
            pMdlMngPieceMove1 = (struct dw_2436777_fields *)(MdlMng + 0x15000);
            if (*pChoisePiece == 0xb || *pChoisePiece == 0x17) {
                SND_Play2D(0x1392, 0x7f, 0);
            } else {
                SND_Play2D(0x1388, 0x7f, 0);
            }
            if (pTable2[11].PieceNum == 0xf || pTable2[23].PieceNum == 0xf) {
                if (GameSt[9] == 0x14 || GameSt[9] == 0x19) {
                    if (pTable2[11].PieceNum == 0xf) {
                        SND_Play2D(0x138f, 0x7f, 0);
                        SetWinNumAdd(1);
                        SetWinFlag(1);
                    } else {
                        SND_Play2D(0x138e, 0x7f, 0);
                        SetWinNumAdd(0);
                        SetWinFlag(0);
                    }
                    GameSt[9] = 0x1a;
                    MGInitControl();
                } else if (GameSt[9] == 0x3a || GameSt[9] == 0x3f) {
                    SND_Play2D(0x138e, 0x7f, 0);
                    if (pTable2[11].PieceNum == 0xf) {
                        SetWinNumAdd(1);
                        SetWinFlag(1);
                    } else {
                        SetWinNumAdd(0);
                        SetWinFlag(0);
                    }
                    GameSt[9] = 0x40;
                    MGInitControl();
                }
            }
            ((struct MGAnimeInfo *)g_dice_anime)[*pChoiseDie].IndexAnim = 0;
            pMdlMngDie->Alpha = 1.0f;
            pMdlMngDie->bErase = 1;
            pMdlMngPieceMove0->bErase = 1;
            pMdlMngPieceMove1->bErase = 1;
            pAnimeInfo->IndexAnim = 0;
            if (GameSt[9] == 0x14) {
                MGPMA_DICE(0x15, 0x12, 1)
            }
            if (GameSt[9] == 0x19) {
                if (g_dice_anime[0x35] == 0 && g_dice_anime[0x85] == 0) {
                    GameSt[9] = 0x10;
                    MGInitControl();
                } else {
                    GameSt[9] = 0x17;
                    MGInitControl();
                }
            }
            if (GameSt[9] == 0x27) {
                GameSt[9] = 0x28;
                MGInitControl();
            }
            if (GameSt[9] == 0x3a) {
                MGPMA_DICE(0x3b, 0x38, 1)
            }
            if (GameSt[9] == 0x3f) {
                MGPMA_DICE(0x36, 0x3d, 0)
            }
        }
    }
}






/* CheckWarSituation @ 0x1F5730 .. 0x1F57EC (0xbc bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1f5760 writes a register its branch at 0x1f575c reads
 *   delay: addiu at 0x1f5788 writes a register its branch at 0x1f5784 reads
 *   cfg: kept branch: 0x1f57a4 if (..) goto .L001F57C0
 */


static void CheckWarSituation(void) {
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetPieceTable();
    a1 = *(u8 *)(v0 + 0x2560);
    a2 = *(u8 *)(v0 + 0x11e0);
    v1 = a1 + 5;
    v1 = (s32)a2 < (s32)v1;
    if (v1 == 0 && g_catch_up_mode == 0) {
        g_catch_up_mode = 1;
    } else {
        v1 = a2 + 5;
        v1 = (s32)a1 < (s32)v1;
        if (v1 == 0 && g_catch_up_mode == 0) {
            g_catch_up_mode = 2;
        } else {
            v1 = (s32)a1 < (s32)a2;
            if (v1 == 0) {
                a0 = g_catch_up_mode;
                v1 = 1;
                if (a0 != v1) {
                    goto _L001F57C0;
                }
                g_catch_up_mode = 0;
            } else {
                _L001F57C0:;
                if ((u32)((s32)a2 < (s32)a1) == 0) {
                    a0 = g_catch_up_mode;
                    if (a0 == (u32)2) {
                        g_catch_up_mode = 0;
                    }
                }
            }
        }
    }
    return;
}






extern u8 GameSt[];
static void CatchUpModeFunc(unsigned char player) {
    u8 *pieces;
    u32 dice;
    u8 mode;
    pieces = (u8 *)GetPieceTable();
    dice = (u32)GetDiceNum();
    mode = g_catch_up_mode;
    if (mode != 0) {
        if (mode == 1) {
            mode = GameSt[9];
            if (mode != 0x16) {
                if (mode != 0x3c) goto randomize;
            }
            return;
        }
        if (mode == 2) {
            mode = GameSt[9];
            if (mode != 0x11) {
                if (mode != 0x37) goto randomize;
            }
            return;
        }
randomize:
        if (rand() % 10 <= 3) {
            switch ((u32)g_catch_up_mode) {
            case 1: {
                u8 index = 17;
                u8 *cursor;
                if (pieces[0x1ba0] < player) {
                    cursor = pieces + 0x1ba0;
                    do {
                        index++;
                        cursor += 0x1a0;
                        if (index > 22) return;
                    } while (*cursor < player);
                }
                {
                    u32 offset;
                    u32 address;
                    u32 count;
                    offset = (u8)player * 80;
                    address = (u32)(g_dice_anime + 0x35) + offset;
                    count = 23 - (u8)index;
                    *(u8 *)address = count;
                    *(u8 *)(dice + (u8)player) = *(u8 *)address;
                    MGSetDieOneNum(player);
                }
                break;
            }
            case 2: {
                u8 *cursor;
                u8 index = 5;
                if (pieces[0x820] == 0) {
                    cursor = pieces + 0x820;
                    do {
                        index++;
                        cursor += 0x1a0;
                        if (index > 10) return;
                    } while (*cursor == 0);
                }
                {
                    u32 offset;
                    u32 address;
                    u32 count;
                    offset = (u8)player * 80;
                    address = (u32)(g_dice_anime + 0x35) + offset;
                    count = 11 - (u8)index;
                    *(u8 *)address = count;
                    *(u8 *)(dice + (u8)player) = *(u8 *)address;
                    MGSetDieOneNum(player);
                }
            }
            }
        }
    }
}

static u8 g_dice_anime[0xa0];
static struct MGAnimeInfo g_piece_anime[32];
static u8 g_catch_up_mode;
