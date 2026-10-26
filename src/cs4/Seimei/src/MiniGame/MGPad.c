#include "common.h"
static u8 g_ChoisePiecePos;
static u8 g_ChoiseDiePos;
static u8 g_TimerFrameNum;
static u8 g_MenuPos;
static u8 g_LoopOutFlag;

/* PadGoSGHMenuFade @ 0x1F9C50 .. 0x1F9D28 (0xd8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x2e escapes at 0x1f9cec
 *   cfg: loop body is not one contiguous region: .L001F9C90
 */

extern void GetSpriteDraw(void);
extern void GetAnalogPad(void *, unsigned short *);
extern void MGInitTopMenu(void);
extern void MGInitControl(void);
extern u32 lpPadData;
extern u8 GameSt[];

/* Pad2PModeViewResult @ 0x1FA390 .. 0x1FA4A8 (0x118 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fa3b8
 *   delay: addiu at 0x1fa3f8 writes a register its branch at 0x1fa3f4 reads
 */

extern void GetAnalogPad(void *, unsigned short *);
extern signed int SND_Play2D(signed int, signed short, signed short);
extern void MGInitControl(void);
extern u32 lpPadData;
extern u8 GameSt[];

/* Pad2PModeViewResultAnime1 @ 0x1FA630 .. 0x1FA66C (0x3c bytes, frame 0x10) */

extern void MGInitControl(void);
extern u8 GameSt[];

/* Pad2PMode2PChoiseDiePlayer @ 0x1FA670 .. 0x1FA9F0 (0x380 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x6e escapes at 0x1fae30
 *   delay: dsll32 at 0x1fae88 writes a register its branch at 0x1fae84 reads
 *   delay: dsll32 at 0x1faea4 writes a register its branch at 0x1faea0 reads
 *   fpu: float literal 0x3f800000 at 0x1fafe4
 *   fpu: float literal 0x00000000 at 0x1fb008
 *   fpu: float literal 0x00000000 at 0x1fb0c0
 *   cfg: kept branch: 0x1faea4 if (..) goto .L001FAFC8
 *   cfg: kept goto: 0x1faef4 -> .L001FAF18
 *   cfg: loop test does not fall through into its body: 0x1faf18
 *   cfg: kept branch: 0x1faf18 if (..) goto .L001FAEF8
 *   cfg: kept branch: 0x1fafdc if (..) goto .L001FB088
 */

extern void MGPieceMoveAnimeFirstInit(unsigned char, unsigned int);
extern void MGPieceMoveAnimeInit(unsigned int);
extern void SetDieAnimeInfoNum(unsigned char, unsigned char);

struct dw_2491335_fields;
struct dw_2500499_fields;
#ifndef PROTO_DW_2499653_FIELDS
#define PROTO_DW_2499653_FIELDS
struct dw_2499653_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_2497847_FIELDS
#define PROTO_DW_2497847_FIELDS
struct dw_2497847_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_2497525_FIELDS
#define PROTO_DW_2497525_FIELDS
struct dw_2497525_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_2491335_fields *lpMdl; };
#endif
#ifndef PROTO_DW_2491335_FIELDS
#define PROTO_DW_2491335_FIELDS
struct dw_2491335_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_2500499_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_2491335_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_2499653_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_2497847_fields flags; unsigned char _pad1[3]; struct dw_2497525_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_2498049_FIELDS
#define PROTO_DW_2498049_FIELDS
struct dw_2498049_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2491335_FIELDS_ALPHA_38035833_DEFINED
#define DCOMP_OFF_STRUCT_DW_2491335_FIELDS_ALPHA_38035833_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2491335_FIELDS_ALPHA_38035833 = (int)&(((struct dw_2491335_fields *)0)->Alpha) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2498049_FIELDS_SCENENO_17D01227_DEFINED
#define DCOMP_OFF_STRUCT_DW_2498049_FIELDS_SCENENO_17D01227_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2498049_FIELDS_SCENENO_17D01227 = (int)&(((struct dw_2498049_fields *)0)->sceneNo) - 0 };
#endif
#ifndef PADFAM_DEFS
#define PADFAM_DEFS
extern void *GetPieceTable(void);
extern void *GetPieceAnimeInfo(void);
extern u32 GetDieAnimeInfo();
extern void MGPieceSelectAnimeExit(unsigned int);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern u32 MdlMng[];
struct PadBits { u8 pad0[0x20]; u8 a0:1, a1:1, a2:1, a3:1, a4:1, a5:1, a6:1, a7:1; u8 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1; };
struct PieceTbl { u8 PieceNum; u8 PieceID[16]; u8 pad[15]; float PiecePos[16][4]; u8 ShadowPos[16][8]; };
struct DieInfo { u8 IndexAnim; u8 pad1[3]; float f[5]; u8 pad2[8]; float local_ang[4]; float offset; u8 count, num; u8 pad3[10]; float quat[4]; };
#define MDL(i) (&((struct dw_2491335_fields *)MdlMng)[i])
#endif


extern void *GetPieceTable(void);
extern void *GetPieceAnimeInfo(void);
extern u32 GetDieAnimeInfo();
extern void MGPieceSelectAnimeExit(unsigned int);
extern void MGPieceSelectAnimeInit(unsigned int);
extern unsigned int ChangeAnimParam(void *, signed int, float);

extern u32 MdlMng[];

/* Pad2PMode1PChoiseDiePlayer @ 0x1FADF0 .. 0x1FB170 (0x380 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x6e escapes at 0x1fae30
 *   delay: dsll32 at 0x1fae88 writes a register its branch at 0x1fae84 reads
 *   delay: dsll32 at 0x1faea4 writes a register its branch at 0x1faea0 reads
 *   fpu: float literal 0x3f800000 at 0x1fafe4
 *   fpu: float literal 0x00000000 at 0x1fb008
 *   fpu: float literal 0x00000000 at 0x1fb0c0
 *   cfg: kept branch: 0x1faea4 if (..) goto .L001FAFC8
 *   cfg: kept goto: 0x1faef4 -> .L001FAF18
 *   cfg: loop test does not fall through into its body: 0x1faf18
 *   cfg: kept branch: 0x1faf18 if (..) goto .L001FAEF8
 *   cfg: kept branch: 0x1fafdc if (..) goto .L001FB088
 */

extern void MGPieceMoveAnimeFirstInit(unsigned char, unsigned int);
extern void MGPieceMoveAnimeInit(unsigned int);
extern void SetDieAnimeInfoNum(unsigned char, unsigned char);

struct dw_2491335_fields;
struct dw_2500499_fields;
#ifndef PROTO_DW_2499653_FIELDS
#define PROTO_DW_2499653_FIELDS
struct dw_2499653_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_2497847_FIELDS
#define PROTO_DW_2497847_FIELDS
struct dw_2497847_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_2497525_FIELDS
#define PROTO_DW_2497525_FIELDS
struct dw_2497525_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_2491335_fields *lpMdl; };
#endif
#ifndef PROTO_DW_2491335_FIELDS
#define PROTO_DW_2491335_FIELDS
struct dw_2491335_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_2500499_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_2491335_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_2499653_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_2497847_fields flags; unsigned char _pad1[3]; struct dw_2497525_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_2498049_FIELDS
#define PROTO_DW_2498049_FIELDS
struct dw_2498049_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2491335_FIELDS_ALPHA_38035833_DEFINED
#define DCOMP_OFF_STRUCT_DW_2491335_FIELDS_ALPHA_38035833_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2491335_FIELDS_ALPHA_38035833 = (int)&(((struct dw_2491335_fields *)0)->Alpha) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2498049_FIELDS_SCENENO_17D01227_DEFINED
#define DCOMP_OFF_STRUCT_DW_2498049_FIELDS_SCENENO_17D01227_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2498049_FIELDS_SCENENO_17D01227 = (int)&(((struct dw_2498049_fields *)0)->sceneNo) - 0 };
#endif
#ifndef PADFAM_DEFS
#define PADFAM_DEFS
struct PadBits { u8 pad0[0x20]; u8 a0:1, a1:1, a2:1, a3:1, a4:1, a5:1, a6:1, a7:1; u8 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1; };
struct PieceTbl { u8 PieceNum; u8 PieceID[16]; u8 pad[15]; float PiecePos[16][4]; u8 ShadowPos[16][8]; };
struct DieInfo { u8 IndexAnim; u8 pad1[3]; float f[5]; u8 pad2[8]; float local_ang[4]; float offset; u8 count, num; u8 pad3[10]; float quat[4]; };
#define MDL(i) (&((struct dw_2491335_fields *)MdlMng)[i])
#endif


extern void *GetPieceTable(void);
extern void *GetPieceAnimeInfo(void);
extern u32 GetDieAnimeInfo();
extern void MGPieceSelectAnimeExit(unsigned int);
extern void MGPieceSelectAnimeInit(unsigned int);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern u32 MdlMng[];

/* Pad2PModeViewOrder @ 0x1FB570 .. 0x1FB648 (0xd8 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x4e escapes at 0x1fb598
 *   stack: address of the slot at 0x4e escapes at 0x1fb5a4
 *   cfg: kept branch: 0x1fb5c0 if (..) goto .L001FB630
 */

extern u32 GetDiceNum(void);

/* PadTutorialChoiceDie @ 0x1FBD00 .. 0x1FC088 (0x388 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x6e escapes at 0x1fae30
 *   delay: dsll32 at 0x1fae88 writes a register its branch at 0x1fae84 reads
 *   delay: dsll32 at 0x1faea4 writes a register its branch at 0x1faea0 reads
 *   fpu: float literal 0x3f800000 at 0x1fafe4
 *   fpu: float literal 0x00000000 at 0x1fb008
 *   fpu: float literal 0x00000000 at 0x1fb0c0
 *   cfg: kept branch: 0x1faea4 if (..) goto .L001FAFC8
 *   cfg: kept goto: 0x1faef4 -> .L001FAF18
 *   cfg: loop test does not fall through into its body: 0x1faf18
 *   cfg: kept branch: 0x1faf18 if (..) goto .L001FAEF8
 *   cfg: kept branch: 0x1fafdc if (..) goto .L001FB088
 */







#ifndef PROTO_DW_2499653_FIELDS
#define PROTO_DW_2499653_FIELDS

#endif
#ifndef PROTO_DW_2497847_FIELDS
#define PROTO_DW_2497847_FIELDS

#endif
#ifndef PROTO_DW_2497525_FIELDS
#define PROTO_DW_2497525_FIELDS

#endif
#ifndef PROTO_DW_2491335_FIELDS
#define PROTO_DW_2491335_FIELDS

#endif
#ifndef PROTO_DW_2498049_FIELDS
#define PROTO_DW_2498049_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_2491335_FIELDS_ALPHA_38035833_DEFINED
#define DCOMP_OFF_STRUCT_DW_2491335_FIELDS_ALPHA_38035833_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_2498049_FIELDS_SCENENO_17D01227_DEFINED
#define DCOMP_OFF_STRUCT_DW_2498049_FIELDS_SCENENO_17D01227_DEFINED

#endif
#ifndef PADFAM_DEFS
#define PADFAM_DEFS









#define MDL(i) (&((struct dw_2491335_fields *)MdlMng)[i])
#endif

/* PadComplsionCtrl @ 0x1FC6E0 .. 0x1FC928 (0x248 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fc708
 *   delay: slti at 0x1fc744 writes a register its branch at 0x1fc740 reads
 *   delay: addiu at 0x1fc7f8 writes a register its branch at 0x1fc7f4 reads
 *   delay: slti at 0x1fc874 writes a register its branch at 0x1fc870 reads
 *   cfg: kept branch: 0x1fc73c if (..) goto .L001FC760
 *   cfg: kept branch: 0x1fc744 if (..) goto .L001FC760
 *   cfg: kept goto: 0x1fc750 -> .L001FC7C0
 *   cfg: kept branch: 0x1fc770 if (..) goto .L001FC790
 *   cfg: kept branch: 0x1fc774 if (..) goto .L001FC790
 *   cfg: kept goto: 0x1fc780 -> .L001FC7C0
 *   cfg: kept branch: 0x1fc7a0 if (..) goto .L001FC7B8
 *   cfg: kept goto: 0x1fc7a8 -> .L001FC7C0
 *   cfg: kept branch: 0x1fc86c if (..) goto .L001FC890
 *   cfg: kept branch: 0x1fc874 if (..) goto .L001FC890
 *   cfg: kept goto: 0x1fc880 -> .L001FC8F0
 *   cfg: kept branch: 0x1fc8a0 if (..) goto .L001FC8C0
 *   cfg: kept branch: 0x1fc8a4 if (..) goto .L001FC8C0
 *   cfg: kept goto: 0x1fc8b0 -> .L001FC8F0
 *   cfg: kept branch: 0x1fc8d0 if (..) goto .L001FC8E8
 *   cfg: kept goto: 0x1fc8d8 -> .L001FC8F0
 */

extern void MGInitOrderPlay(void);
extern void MGInitMainPlay(void);
extern void MGInitTutorialTextView(void);
extern void MGInitTutorialView(void);


/* PadCpmplsionCheck @ 0x1FC930 .. 0x1FCA08 (0xd8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1fc968 writes a register its branch at 0x1fc964 reads
 *   stack: address of the slot at 0x2e escapes at 0x1fc9c4
 *   cfg: kept branch: 0x1fc934 if (..) goto .L001FC9B8
 *   cfg: kept branch: 0x1fc960 if (..) goto .L001FC9B8
 *   cfg: kept branch: 0x1fc974 if (..) goto .L001FC9B8
 *   cfg: kept branch: 0x1fc984 if (..) goto .L001FC9B8
 *   cfg: kept branch: 0x1fc990 if (..) goto .L001FC9B8
 */

extern u32 GetMGPrcStatus(void);
extern void MGInitComplsion(void);

struct dw_2495435 {
    unsigned char PieceNum;
    unsigned char PieceID[16];
    unsigned char _pad1[15];
    float PiecePos[16][4];
    unsigned char ShadowPos[16][8];
};
struct dw_2495620 {
    unsigned char IndexAnim;
    unsigned char _pad1[3];
    float height, move_speed, frame_num, tilt, angle_speed;
    unsigned char _pad2[8];
    float local_ang[4];
    float offset;
    unsigned char count, num;
    unsigned char _pad3[10];
    float quaternion[4];
};


extern void MGPieceMoveAnimeFirstInit(unsigned char, unsigned int);
extern void MGPieceMoveAnimeInit(unsigned int);
extern void SetDieAnimeInfoNum(unsigned char, unsigned char);


extern u32 GetAIType();

#define CPU_PREFIX \
    { \
    u8 sum; \
    u8 diff; \
    s32 pos; \
    g_ChoiseDiePos = 0xff; \
    g_ChoisePiecePos = 0xff; \
    GameSt[9] = 0x18; \
    if (pDieAnimeInfo[0].num > 0 && pTable[0xb - pDieAnimeInfo[0].num].PieceNum > 0) { \
        g_ChoiseDiePos = 0; \
        g_ChoisePiecePos = 0xb - pDieAnimeInfo[0].num; \
        break; \
    } \
    if (pDieAnimeInfo[1].num > 0 && pTable[0xb - pDieAnimeInfo[1].num].PieceNum > 0) { \
        g_ChoiseDiePos = 1; \
        g_ChoisePiecePos = 0xb - pDieAnimeInfo[1].num; \
        break; \
    } \
    if (pDieAnimeInfo[0].num > 0 && pDieAnimeInfo[1].num > 0) { \
        sum = pDieAnimeInfo[0].num + pDieAnimeInfo[1].num; \
        if (pDieAnimeInfo[1].num < pDieAnimeInfo[0].num) { \
            diff = pDieAnimeInfo[0].num - pDieAnimeInfo[1].num; \
        } else { \
            diff = pDieAnimeInfo[1].num - pDieAnimeInfo[0].num; \
        } \
        if (sum <= 0xb) { \
            pos = 0xb - sum; \
            if (pTable[pos].PieceNum > 0) { \
                g_ChoisePiecePos = pos; \
                g_ChoiseDiePos = 0; \
                break; \
            } \
        } \
        if (diff > 0) { \
            pos = 0xb - diff; \
            if (pTable[pos].PieceNum > 0) { \
                g_ChoiseDiePos = pDieAnimeInfo[0].num <= pDieAnimeInfo[1].num; \
                g_ChoisePiecePos = pos; \
                break; \
            } \
        } \
    } \
    }

#define CPU_SEARCH(num) \
    { \
    u8 AddDieNum; \
    for (loop = 0; loop < 0xb; loop++) { \
        if (loop + (num) < 0xb) { \
            AddDieNum = (u8)loop + (num); \
        } else { \
            AddDieNum = 0xb - ((u8)loop + (num) - 0xb); \
        } \
        if (pTable[AddDieNum].PieceNum == 0 && pTable[loop].PieceNum > 0) { \
            g_ChoisePiecePos = loop; \
            return; \
        } \
    } \
    }

/* PadChoiseDiePlayer @ 0x1FD460 .. 0x1FD7F0 (0x390 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x6e escapes at 0x1fae30
 *   delay: dsll32 at 0x1fae88 writes a register its branch at 0x1fae84 reads
 *   delay: dsll32 at 0x1faea4 writes a register its branch at 0x1faea0 reads
 *   fpu: float literal 0x3f800000 at 0x1fafe4
 *   fpu: float literal 0x00000000 at 0x1fb008
 *   fpu: float literal 0x00000000 at 0x1fb0c0
 *   cfg: kept branch: 0x1faea4 if (..) goto .L001FAFC8
 *   cfg: kept goto: 0x1faef4 -> .L001FAF18
 *   cfg: loop test does not fall through into its body: 0x1faf18
 *   cfg: kept branch: 0x1faf18 if (..) goto .L001FAEF8
 *   cfg: kept branch: 0x1fafdc if (..) goto .L001FB088
 */







#ifndef PROTO_DW_2499653_FIELDS
#define PROTO_DW_2499653_FIELDS

#endif
#ifndef PROTO_DW_2497847_FIELDS
#define PROTO_DW_2497847_FIELDS

#endif
#ifndef PROTO_DW_2497525_FIELDS
#define PROTO_DW_2497525_FIELDS

#endif
#ifndef PROTO_DW_2491335_FIELDS
#define PROTO_DW_2491335_FIELDS

#endif
#ifndef PROTO_DW_2498049_FIELDS
#define PROTO_DW_2498049_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_2491335_FIELDS_ALPHA_38035833_DEFINED
#define DCOMP_OFF_STRUCT_DW_2491335_FIELDS_ALPHA_38035833_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_2498049_FIELDS_SCENENO_17D01227_DEFINED
#define DCOMP_OFF_STRUCT_DW_2498049_FIELDS_SCENENO_17D01227_DEFINED

#endif
#ifndef PADFAM_DEFS
#define PADFAM_DEFS









#define MDL(i) (&((struct dw_2491335_fields *)MdlMng)[i])
#endif

/* PadViewOrder @ 0x1FDC20 .. 0x1FDCE4 (0xc4 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x3e escapes at 0x1fdc54
 */

extern u32 GetDiceNum(void);
extern void MGDiceAnimeStart(unsigned char, unsigned char);

/* PadSGHGameMenu @ 0x1FDFC0 .. 0x1FE240 (0x280 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fe024
 *   delay: dsll32 at 0x1fe03c writes a register its branch at 0x1fe038 reads
 *   delay: dsll32 at 0x1fe0d8 writes a register its branch at 0x1fe0d4 reads
 *   cfg: kept branch: 0x1fdff8 if (..) goto .L001FE018
 *   cfg: kept branch: 0x1fe03c if (..) goto .L001FE060
 *   cfg: kept branch: 0x1fe04c if (..) goto .L001FE0C8
 *   cfg: kept branch: 0x1fe0d8 if (..) goto .L001FE100
 *   cfg: kept branch: 0x1fe0e8 if (..) goto .L001FE160
 *   cfg: kept branch: 0x1fe174 if (..) goto .L001FE198
 *   cfg: kept branch: 0x1fe184 if (..) goto .L001FE230
 */

extern void GetSpriteDraw(void);
extern signed int CheckPadEnable(unsigned char);
extern void MGDrawSetMenuHelpWnd(unsigned char);
extern void MGTMKMenuChoise(unsigned int);

/* PadTopMenu @ 0x1FE4C0 .. 0x1FE638 (0x178 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fe4ec
 *   delay: dsll32 at 0x1fe504 writes a register its branch at 0x1fe500 reads
 *   delay: dsll32 at 0x1fe524 writes a register its branch at 0x1fe520 reads
 *   delay: dsll32 at 0x1fe540 writes a register its branch at 0x1fe53c reads
 *   cfg: kept branch: 0x1fe504 if (..) goto .L001FE550
 *   cfg: kept branch: 0x1fe514 if (..) goto .L001FE550
 *   cfg: kept branch: 0x1fe524 if (..) goto .L001FE550
 *   cfg: kept branch: 0x1fe534 if (..) goto .L001FE550
 *   cfg: kept branch: 0x1fe540 if (..) goto .L001FE5A0
 */

extern void GetSpriteDraw(void);
extern void MGTopMenuChoise(unsigned int);

/* MGPadCtrl @ 0x1FE640 .. 0x1FE6E4 (0xa4 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern void PadUpdate(void);
void PadCpmplsionCheck(void);
extern void PadCpmplsionCheck(void);
extern u32 GetMGPrcStatus(void);
void PadComplsionCtrl(void);
extern void PadComplsionCtrl(void);
extern u32 g_MGPadFuncTbl[];

/* SetChoisePiecePosSearch @ 0x1FE6F0 .. 0x1FE770 (0x80 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void *GetPieceTable(void);

/* SetPieceAnimeMovePos @ 0x1FE770 .. 0x1FE7D8 (0x68 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void *GetPieceAnimeInfo(void);
static void PadTopMenu(void);
static void PadTMKGameMenu(void);
static void PadSGHGameMenu(void);
static void PadTopMenuMainFadeTimer(void);
static void PadOrderPlayer0(void);
static void PadOrderPlayer(void);
static void PadOrderPlayer1(void);
static void PadOrderCPU(void);
static void PadOrderCPU1(void);
static void PadViewOrder(void);
static void PadDiceThrowPlayer(void);
void PadChoisePiecePlayer(void);
void PadChoiseDiePlayer(void);
static void PadDiceThrowCPU(void);
void PadChoisePieceCPU(void);
void PadChoiseDieCPU(void);
static void PadViewResultAnime1(void);
static void PadViewResultAnime2(void);
static void PadViewResultAnime3(void);
static void PadViewResult(void);
static void PadReturnTopMenuMainFadeTimer(void);
static void PadTopMenuTutorialFadeTimer(void);
static void PadTutorialText1(void);
static void PadTutorialText2(void);
static void PadTutorialText3(void);
static void PadTutorialThrow1(void);
void PadTutorialChoicePiece(void);
void PadTutorialChoiceDie(void);
static void PadTutorialMovePieceFade(void);
static u32 PadTutorialText4(void);
static void PadTutorialOnmoreMenu(void);
static void PadReturnTopMenuTutorialFadeTimer(void);
static void PadComplsionFadeTimer(void);
static void Pad2PModeMenuMainFadeTimer(void);
static void Pad2PMode1POrderPlayer0(void);
static void Pad2PMode1POrderPlayer(void);
static void Pad2PMode1POrderPlayer1(void);
static void Pad2PMode2POrderPlayer(void);
static void Pad2PMode2POrderPlayer1(void);
static void Pad2PModeViewOrder(void);
static void Pad2PMode1PDiceThrowPlayer(void);
void Pad2PMode1PChoisePiecePlayer(void);
void Pad2PMode1PChoiseDiePlayer(void);
static void Pad2PMode2PDiceThrowPlayer(void);
void Pad2PMode2PChoisePiecePlayer(void);
void Pad2PMode2PChoiseDiePlayer(void);
static void Pad2PModeViewResultAnime1(void);
static void Pad2PModeViewResultAnime2(void);
static void Pad2PModeViewResultAnime3(void);
static void Pad2PModeViewResult(void);
static void PadGoTitleFade(void);
static void PadTMKMenuFromTopMenuFadeTimer(void);
static void PadSGHMenuFromTopMenuFadeTimer(void);
static void PadTopMenuFromTMKMenuFadeTimer(void);
static void PadTopMenuFromSGHMenuFadeTimer(void);
static void PadGoSGHJitsugiFade(void);
static void PadGoSGHShigiFade(void);
static void PadGoSGHTaisenFade(void);
static void PadGoSGHMenuFade(void);





static u32 g_MGPadFuncTbl[0x4d] = {
    (u32)&PadTopMenu, (u32)&PadTMKMenuFromTopMenuFadeTimer, (u32)&PadTMKGameMenu,
    (u32)&PadTopMenuFromTMKMenuFadeTimer, (u32)&PadSGHMenuFromTopMenuFadeTimer,
    (u32)&PadSGHGameMenu, (u32)&PadTopMenuFromSGHMenuFadeTimer, (u32)&PadTopMenuMainFadeTimer,
    (u32)&PadOrderPlayer0, (u32)&PadOrderPlayer, 0, (u32)&PadOrderPlayer1, (u32)&PadOrderCPU, 0,
    (u32)&PadOrderCPU1, (u32)&PadViewOrder, (u32)&PadDiceThrowPlayer, 0,
    (u32)&PadChoisePiecePlayer, (u32)&PadChoiseDiePlayer, 0, (u32)&PadDiceThrowCPU, 0,
    (u32)&PadChoisePieceCPU, (u32)&PadChoiseDieCPU, 0, (u32)&PadViewResultAnime1,
    (u32)&PadViewResultAnime2, (u32)&PadViewResultAnime3, (u32)&PadViewResult,
    (u32)&PadReturnTopMenuMainFadeTimer, (u32)&PadTopMenuTutorialFadeTimer,
    (u32)&PadTutorialText1, (u32)&PadTutorialText2, (u32)&PadTutorialText3,
    (u32)&PadTutorialThrow1, 0, (u32)&PadTutorialChoicePiece, (u32)&PadTutorialChoiceDie, 0,
    (u32)&PadTutorialMovePieceFade, (u32)&PadTutorialText4, (u32)&PadTutorialOnmoreMenu,
    (u32)&PadReturnTopMenuTutorialFadeTimer, (u32)&PadComplsionFadeTimer,
    (u32)&Pad2PModeMenuMainFadeTimer, (u32)&Pad2PMode1POrderPlayer0,
    (u32)&Pad2PMode1POrderPlayer, 0, (u32)&Pad2PMode1POrderPlayer1,
    (u32)&Pad2PMode2POrderPlayer, 0, (u32)&Pad2PMode2POrderPlayer1, (u32)&Pad2PModeViewOrder,
    (u32)&Pad2PMode1PDiceThrowPlayer, 0, (u32)&Pad2PMode1PChoisePiecePlayer,
    (u32)&Pad2PMode1PChoiseDiePlayer, 0, (u32)&Pad2PMode2PDiceThrowPlayer, 0,
    (u32)&Pad2PMode2PChoisePiecePlayer, (u32)&Pad2PMode2PChoiseDiePlayer, 0,
    (u32)&Pad2PModeViewResultAnime1, (u32)&Pad2PModeViewResultAnime2,
    (u32)&Pad2PModeViewResultAnime3, (u32)&Pad2PModeViewResult,
    (u32)&PadReturnTopMenuMainFadeTimer, (u32)&PadGoTitleFade, (u32)&PadGoSGHJitsugiFade,
    (u32)&PadGoSGHShigiFade, (u32)&PadGoSGHTaisenFade, 0, 0, 0, (u32)&PadGoSGHMenuFade
};

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetLoopOutFlag(s32 a0 );
u8 GetLoopOutFlag(void);
u8 * GetChoisePiecePos(void);
u8 * GetChoiseDiePos(void);
void SetTimerFrameNum(s32 a0 );
u8 * GetMenuPos(void);
void SetMenuPos(u8 *a0 );
void SetPieceAnimeMovePos(unsigned int a0 );
void SetChoisePiecePosSearch(unsigned char a0 );
u32 MGPadCtrl(void);
static void PadTopMenu(void);
static void PadTMKGameMenu(void);
static void PadSGHGameMenu(void);
static void PadTopMenuMainFadeTimer(void);
static void PadOrderPlayer0(void);
static void PadOrderPlayer(void);
static void PadOrderPlayer1(void);
static void PadOrderCPU(void);
static void PadOrderCPU1(void);
static void PadViewOrder(void);
static void PadDiceThrowPlayer(void);
void PadChoisePiecePlayer(void);
void PadChoiseDiePlayer(void);
static void PadDiceThrowCPU(void);
void PadChoisePieceCPU(void);
void PadChoiseDieCPU(void);
static void PadViewResultAnime1(void);
static void PadViewResultAnime2(void);
static void PadViewResultAnime3(void);
static void PadViewResult(void);
static void PadReturnTopMenuMainFadeTimer(void);
void PadCpmplsionCheck(void);
void PadComplsionCtrl(void);
static void PadTopMenuTutorialFadeTimer(void);
static void PadTutorialText1(void);
static void PadTutorialText2(void);
static void PadTutorialText3(void);
static void PadTutorialThrow1(void);
void PadTutorialChoicePiece(void);
void PadTutorialChoiceDie(void);
static void PadTutorialMovePieceFade(void);
static u32 PadTutorialText4(void);
static void PadTutorialOnmoreMenu(void);
static void PadReturnTopMenuTutorialFadeTimer(void);
static void PadComplsionFadeTimer(void);
static void Pad2PModeMenuMainFadeTimer(void);
static void Pad2PMode1POrderPlayer0(void);
static void Pad2PMode1POrderPlayer(void);
static void Pad2PMode1POrderPlayer1(void);
static void Pad2PMode2POrderPlayer(void);
static void Pad2PMode2POrderPlayer1(void);
static void Pad2PModeViewOrder(void);
static void Pad2PMode1PDiceThrowPlayer(void);
void Pad2PMode1PChoisePiecePlayer(void);
void Pad2PMode1PChoiseDiePlayer(void);
static void Pad2PMode2PDiceThrowPlayer(void);
void Pad2PMode2PChoisePiecePlayer(void);
void Pad2PMode2PChoiseDiePlayer(void);
static void Pad2PModeViewResultAnime1(void);
static void Pad2PModeViewResultAnime2(void);
static void Pad2PModeViewResultAnime3(void);
static void Pad2PModeViewResult(void);
static void PadGoTitleFade(void);
static void PadTMKMenuFromTopMenuFadeTimer(void);
static void PadSGHMenuFromTopMenuFadeTimer(void);
static void PadTopMenuFromTMKMenuFadeTimer(void);
static void PadTopMenuFromSGHMenuFadeTimer(void);
static void PadGoSGHJitsugiFade(void);
static void PadGoSGHShigiFade(void);
static void PadGoSGHTaisenFade(void);
static void PadGoSGHMenuFade(void);


/* SetLoopOutFlag @ 0x1FE840 .. 0x1FE848 (0x8 bytes) */


void SetLoopOutFlag(s32 a0 /* r4 */) {
    g_LoopOutFlag = a0;
    return;
}

/* GetLoopOutFlag @ 0x1FE830 .. 0x1FE838 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lbu at 0x1fe834 computes the return value
 */


u8 GetLoopOutFlag(void) {
    return g_LoopOutFlag;
}

/* GetChoisePiecePos @ 0x1FE820 .. 0x1FE828 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x1fe824 computes the return value
 */

u8 * GetChoisePiecePos(void) {
    return &g_ChoisePiecePos;
}

/* GetChoiseDiePos @ 0x1FE810 .. 0x1FE818 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x1fe814 computes the return value
 */


u8 * GetChoiseDiePos(void) {
    return (u8 *)&g_ChoiseDiePos;
}

/* SetTimerFrameNum @ 0x1FE800 .. 0x1FE808 (0x8 bytes) */


void SetTimerFrameNum(s32 a0 /* r4 */) {
    g_TimerFrameNum = a0;
    return;
}

/* GetMenuPos @ 0x1FE7F0 .. 0x1FE7F8 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x1fe7f4 computes the return value
 */

u8 * GetMenuPos(void) {
    return &g_MenuPos;
}

/* SetMenuPos @ 0x1FE7E0 .. 0x1FE7E8 (0x8 bytes) */


void SetMenuPos(u8 *a0 /* r4 */) {
    g_MenuPos = (u8)a0;
    return;
}

void SetPieceAnimeMovePos(unsigned int a0 /* r4 */) {
    unsigned int a0_2; // a0
    u8 v1;
    u8 *v0;

    v0 = (u8 *)GetPieceAnimeInfo();
    a0_2 = (u32)a0 << 2;
    v1 = 1;
    a0_2 = (u32)(a0_2) + (u32)(a0);
    a0_2 = (u32)a0_2 << 4;
    a0_2 = *(s8 *)((u32)&((u8 *)(v0 + 0x46))[a0_2]);
    if ((u32)a0_2 == (u32)v1) {
        v1 = g_ChoisePiecePos;
        g_ChoisePiecePos = (u32)(v1) + 1;
    } else {
        v1 = g_ChoisePiecePos;
        g_ChoisePiecePos = (u32)(v1) + -1;
    }
    return;
}

void SetChoisePiecePosSearch(unsigned char a0 /* r4 */) {
    u32 a0_2; // a0
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetPieceTable();
    a0_2 = (u8)a0;
    g_ChoisePiecePos = (u32)((s32)(a0_2 * (u32)(3))) << 2;
    a0_2 = g_ChoisePiecePos;
    v1 = (s32)(a0_2 * (u32)(0xd));
    a0_2 = (s32)(v0 + (u32)(v1 << 5));
    v1 = *(u8 *)a0_2;
    if (v1 == 0) {
        do {
            v1 = g_ChoisePiecePos;
            a0_2 = a0_2 + 0x1a0;
            g_ChoisePiecePos = v1 + 1;
            v1 = *(u8 *)a0_2;
        } while (v1 == 0);
    }
    return;
}

u32 MGPadCtrl(void) {
    u32 a0;
    u32 v1;
    u32 v0;

    PadUpdate();
    a0 = *(u8 *)((u8 *)&GameSt + 4);
    if (a0 == 0) {
        v1 = *(u8 *)((u8 *)&GameSt + 9);
        v0 = (u32)g_MGPadFuncTbl;
        v0 = (s32)((u8 *)g_MGPadFuncTbl + (u32)(v1 << 2));
        v0 = *(s32 *)v0;
        if (v0 == 0) {
            PadCpmplsionCheck();
        } else {
            ((void (*)(void))(s32)v0)();
            v0 = GetMGPrcStatus();
            v1 = *(u8 *)v0;
            if (v1 != 0) {
                PadCpmplsionCheck();
            }
        }
    } else if (a0 == (u32)1) {
        PadComplsionCtrl();
    }
    return;
}

static void PadTopMenu(void) {
    u32 a1;
    u32 a0;
    u8 *s0;
    u32 v1;
    u32 v0;
    u64 v1_64;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u32)&lpPadData;
    v1 = GameSt[0xa];
    v1 = v1 << 2;
    v0 = (s32)((u8 *)&lpPadData + v1);
    s0 = (u8 *)*(s32 *)v0;
    GetSpriteDraw();
    a0 = (s32)s0;
    GetAnalogPad((void *)a0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    a1 = *(u8 *)(s0 + 0x20);
    v1_64 = (u64)((u64)a1 << 0x3b) >> 0x3f;
    if (v1_64 == 0) {
        v1_64 = (u64)a1 << 0x3a;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 != 0) {
            goto _L001FE550;
        }
        a0 = *(u8 *)(s0 + 0x21);
        v1_64 = (u64)((u64)a0 << 0x3c) >> 0x3f;
        if (v1_64 != 0) {
            goto _L001FE550;
        }
        v1_64 = (u64)a1 << 0x39;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 != 0) {
            goto _L001FE550;
        }
        v1_64 = (u64)((u64)a1 << 0x38) >> 0x3f;
        if (v1_64 != 0) {
            goto _L001FE550;
        }
        v1_64 = (u64)a0 << 0x3d;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 == 0) {
            goto _L001FE5A0;
        }
    }
    _L001FE550:;
    a0 = 0x138d;
    a1 = 0x7f;
    SND_Play2D(a0, a1, 0);
    v1 = g_MenuPos;
    v0 = 1;
    switch (v1) {
    case 0:
        g_MenuPos = v0;
        break;
    case 1:
        g_MenuPos = 0;
        break;
    default:
        g_MenuPos = 0;
    }
    a0 = g_MenuPos;
    MGTopMenuChoise(a0);
    _L001FE5A0:;
    v1 = *(u8 *)(s0 + 0x21);
    v1_64 = (u64)((u64)v1 << 0x39) >> 0x3f;
    a0 = 0x1390;
    if (v1_64 != 0) {
        a1 = 0x7f;
        SND_Play2D(a0, a1, 0);
        v1 = g_MenuPos;
        if (v1 == 0) {
            v0 = 1;
            GameSt[9] = v0;
            MGInitControl();
        }
        a0 = g_MenuPos;
        v1 = 1;
        if (a0 == v1) {
            v0 = 4;
            GameSt[9] = v0;
            MGInitControl();
        }
    }
    v1 = *(u8 *)(s0 + 0x21);
    v1_64 = (u64)((u64)v1 << 0x3a) >> 0x3f;
    if (v1_64 != 0) {
        v0 = 0x45;
        GameSt[9] = v0;
        MGInitControl();
    }
    return;
}

/* PadTMKGameMenu @ 0x1FE240 .. 0x1FE4C0 (0x280 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fe2a4
 *   delay: dsll32 at 0x1fe2bc writes a register its branch at 0x1fe2b8 reads
 *   delay: dsll32 at 0x1fe358 writes a register its branch at 0x1fe354 reads
 *   cfg: kept branch: 0x1fe278 if (..) goto .L001FE298
 *   cfg: kept branch: 0x1fe2bc if (..) goto .L001FE2E0
 *   cfg: kept branch: 0x1fe2cc if (..) goto .L001FE348
 *   cfg: kept branch: 0x1fe358 if (..) goto .L001FE380
 *   cfg: kept branch: 0x1fe368 if (..) goto .L001FE3E0
 *   cfg: kept branch: 0x1fe3f4 if (..) goto .L001FE418
 *   cfg: kept branch: 0x1fe404 if (..) goto .L001FE4B0
 */






static void PadTMKGameMenu(void) {
    u32 a1;
    u32 a0;
    u8 *s0;
    u32 v1;
    u32 v0;
    u64 v1_64;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u32)&lpPadData;
    v1 = GameSt[0xa];
    v1 = v1 << 2;
    v0 = (s32)((u8 *)&lpPadData + v1);
    s0 = (u8 *)*(s32 *)v0;
    GetSpriteDraw();
    v0 = g_MenuPos;
    a0 = 1;
    if (v0 == a0) {
        v0 = CheckPadEnable(a0);
        a0 = 1;
        if (v0 != 0) {
            goto _L001FE298;
        }
        MGDrawSetMenuHelpWnd(a0);
    } else {
        _L001FE298:;
        MGDrawSetMenuHelpWnd(0);
    }
    a0 = (s32)s0;
    GetAnalogPad((void *)a0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    a0 = *(u8 *)(s0 + 0x20);
    v1_64 = (u64)((u64)a0 << 0x3b) >> 0x3f;
    if (v1_64 == 0) {
        v1_64 = (u64)a0 << 0x3a;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 != 0) {
            goto _L001FE2E0;
        }
        v1 = *(u8 *)(s0 + 0x21);
        v1_64 = (u64)((u64)v1 << 0x3c) >> 0x3f;
        if (v1_64 == 0) {
            goto _L001FE348;
        }
    }
    _L001FE2E0:;
    a0 = 0x138d;
    a1 = 0x7f;
    SND_Play2D(a0, a1, 0);
    a0 = g_MenuPos;
    v1 = 1;
    v0 = 2;
    switch (a0) {
    case 0:
        g_MenuPos = v1;
        break;
    case 2:
        g_MenuPos = 0;
        break;
    case 1:
        v0 = 2;
        g_MenuPos = v0;
        break;
    default:
        g_MenuPos = 0;
    }
    a0 = g_MenuPos;
    MGTMKMenuChoise(a0);
    _L001FE348:;
    a0 = *(u8 *)(s0 + 0x20);
    v1_64 = (u64)((u64)a0 << 0x39) >> 0x3f;
    if (v1_64 == 0) {
        v1_64 = (u64)a0 << 0x38;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 != 0) {
            goto _L001FE380;
        }
        v1 = *(u8 *)(s0 + 0x21);
        v1_64 = (u64)((u64)v1 << 0x3d) >> 0x3f;
        if (v1_64 == 0) {
            goto _L001FE3E0;
        }
    }
    _L001FE380:;
    a0 = 0x138d;
    a1 = 0x7f;
    SND_Play2D(a0, a1, 0);
    a0 = g_MenuPos;
    v1 = 1;
    v0 = 2;
    switch (a0) {
    case 0:
        g_MenuPos = v0;
        break;
    case 2:
        g_MenuPos = v1;
        break;
    case 1:
        g_MenuPos = 0;
        break;
    default:
        g_MenuPos = 0;
    }
    a0 = g_MenuPos;
    MGTMKMenuChoise(a0);
    _L001FE3E0:;
    a0 = *(u8 *)(s0 + 0x21);
    v1_64 = (u64)((u64)a0 << 0x39) >> 0x3f;
    if (v1_64 != 0) {
        v0 = g_MenuPos;
        a0 = 1;
        if (v0 != a0) {
            goto _L001FE418;
        }
        v0 = CheckPadEnable(a0);
        if (v0 == 0) {
            goto _L001FE4B0;
        }
        _L001FE418:;
        a0 = 0x1390;
        a1 = 0x7f;
        SND_Play2D(a0, a1, 0);
        v1 = g_MenuPos;
        if (v1 == 0) {
            v0 = 7;
            GameSt[9] = v0;
            MGInitControl();
        }
        a0 = g_MenuPos;
        v1 = 2;
        if (a0 == v1) {
            v0 = 0x1f;
            GameSt[9] = v0;
            MGInitControl();
        }
        a0 = g_MenuPos;
        v1 = 1;
        if (a0 == v1) {
            v0 = 0x2d;
            GameSt[9] = v0;
            MGInitControl();
        }
        return;
    }
    v1_64 = (u64)((u64)a0 << 0x3a) >> 0x3f;
    if (v1_64 != 0) {
        v0 = 3;
        GameSt[9] = v0;
        MGInitControl();
    }
    _L001FE4B0:;
    return;
}

static void PadSGHGameMenu(void) {
    u32 a1;
    u32 a0;
    u8 *s0;
    u32 v1;
    u32 v0;
    u64 v1_64;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u32)&lpPadData;
    v1 = GameSt[0xa];
    v1 = v1 << 2;
    v0 = (s32)((u8 *)&lpPadData + v1);
    s0 = (u8 *)*(s32 *)v0;
    GetSpriteDraw();
    v0 = g_MenuPos;
    a0 = 1;
    if (v0 == a0) {
        v0 = CheckPadEnable(a0);
        a0 = 1;
        if (v0 != 0) {
            goto _L001FE018;
        }
        MGDrawSetMenuHelpWnd(a0);
    } else {
        _L001FE018:;
        MGDrawSetMenuHelpWnd(0);
    }
    a0 = (s32)s0;
    GetAnalogPad((void *)a0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    a0 = *(u8 *)(s0 + 0x20);
    v1_64 = (u64)((u64)a0 << 0x3b) >> 0x3f;
    if (v1_64 == 0) {
        v1_64 = (u64)a0 << 0x3a;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 != 0) {
            goto _L001FE060;
        }
        v1 = *(u8 *)(s0 + 0x21);
        v1_64 = (u64)((u64)v1 << 0x3c) >> 0x3f;
        if (v1_64 == 0) {
            goto _L001FE0C8;
        }
    }
    _L001FE060:;
    a0 = 0x138d;
    a1 = 0x7f;
    SND_Play2D(a0, a1, 0);
    a0 = g_MenuPos;
    v1 = 1;
    v0 = 2;
    switch (a0) {
    case 0:
        g_MenuPos = v1;
        break;
    case 2:
        g_MenuPos = 0;
        break;
    case 1:
        v0 = 2;
        g_MenuPos = v0;
        break;
    default:
        g_MenuPos = 0;
    }
    a0 = g_MenuPos;
    MGTMKMenuChoise(a0);
    _L001FE0C8:;
    a0 = *(u8 *)(s0 + 0x20);
    v1_64 = (u64)((u64)a0 << 0x39) >> 0x3f;
    if (v1_64 == 0) {
        v1_64 = (u64)a0 << 0x38;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 != 0) {
            goto _L001FE100;
        }
        v1 = *(u8 *)(s0 + 0x21);
        v1_64 = (u64)((u64)v1 << 0x3d) >> 0x3f;
        if (v1_64 == 0) {
            goto _L001FE160;
        }
    }
    _L001FE100:;
    a0 = 0x138d;
    a1 = 0x7f;
    SND_Play2D(a0, a1, 0);
    a0 = g_MenuPos;
    v1 = 1;
    v0 = 2;
    switch (a0) {
    case 0:
        g_MenuPos = v0;
        break;
    case 2:
        g_MenuPos = v1;
        break;
    case 1:
        g_MenuPos = 0;
        break;
    default:
        g_MenuPos = 0;
    }
    a0 = g_MenuPos;
    MGTMKMenuChoise(a0);
    _L001FE160:;
    v1 = *(u8 *)(s0 + 0x21);
    v1_64 = (u64)((u64)v1 << 0x39) >> 0x3f;
    if (v1_64 != 0) {
        v0 = g_MenuPos;
        a0 = 1;
        if (v0 != a0) {
            goto _L001FE198;
        }
        v0 = CheckPadEnable(a0);
        if (v0 == 0) {
            goto _L001FE230;
        }
        _L001FE198:;
        a0 = 0x1390;
        a1 = 0x7f;
        SND_Play2D(a0, a1, 0);
        v1 = g_MenuPos;
        if (v1 == 0) {
            v0 = 0x46;
            GameSt[9] = v0;
            MGInitControl();
        }
        a0 = g_MenuPos;
        v1 = 1;
        if (a0 == v1) {
            v0 = 0x48;
            GameSt[9] = v0;
            MGInitControl();
        }
        a0 = g_MenuPos;
        v1 = 2;
        if (a0 == v1) {
            v0 = 0x47;
            GameSt[9] = v0;
            MGInitControl();
        }
    }
    v1 = *(u8 *)(s0 + 0x21);
    v1_64 = (u64)((u64)v1 << 0x3a) >> 0x3f;
    if (v1_64 != 0) {
        v0 = 6;
        GameSt[9] = v0;
        MGInitControl();
    }
    _L001FE230:;
    return;
}

/* PadTopMenuMainFadeTimer @ 0x1FDEF0 .. 0x1FDFC0 (0xd0 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x2e escapes at 0x1fdf8c
 *   cfg: loop body is not one contiguous region: .L001FDF30
 */



static void PadTopMenuMainFadeTimer(void) {
    extern u32 GetSpriteDraw(void);
    s32 a3;
    s32 a2;
    u32 s0;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u8 *)&lpPadData;
    v1 = GameSt[0xa];
    s0 = *(s32 *)(u8 *)((u8 *)&lpPadData + (u32)(v1 << 2));
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)8;
        MGInitControl();
    }
    return;
}

/* PadOrderPlayer0 @ 0x1FDE80 .. 0x1FDEE8 (0x68 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fdea8
 */




static void PadOrderPlayer0(void) {
    u32 *v0;
    u8 v1;
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = &lpPadData;
    v1 = GameSt[0xa];
    s0 = (u8 *)*(s32 *)(u32 *)((u8 *)&lpPadData + (u32)((u32)v1 << 2));
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        GameSt[9] = (s32)(u32 *)(s32)9;
        MGInitControl();
    }
    return;
}

/* PadOrderPlayer @ 0x1FDE10 .. 0x1FDE78 (0x68 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fde38
 */




static void PadOrderPlayer(void) {
    u32 *v0;
    u8 v1;
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = &lpPadData;
    v1 = GameSt[0xa];
    s0 = (u8 *)*(s32 *)(u32 *)((u8 *)&lpPadData + (u32)((u32)v1 << 2));
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        GameSt[9] = (s32)(u32 *)(s32)0xa;
        MGInitControl();
    }
    return;
}

/* PadOrderPlayer1 @ 0x1FDDA0 .. 0x1FDE08 (0x68 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fddc8
 */




static void PadOrderPlayer1(void) {
    u32 *v0;
    u8 v1;
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = &lpPadData;
    v1 = GameSt[0xa];
    s0 = (u8 *)*(s32 *)(u32 *)((u8 *)&lpPadData + (u32)((u32)v1 << 2));
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        GameSt[9] = (s32)(u32 *)(s32)0xc;
        MGInitControl();
    }
    return;
}

/* PadOrderCPU @ 0x1FDD40 .. 0x1FDD9C (0x5c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x1e escapes at 0x1fdd60
 */




static void PadOrderCPU(void) {
    u32 *v0;
    u8 v1;
    u8 stackFrame_1E[2] __attribute__((aligned(2)));

    v0 = &lpPadData;
    v1 = GameSt[0xa];
    GetAnalogPad((void *)*(s32 *)(u32 *)((u8 *)&lpPadData + (u32)((u32)v1 << 2)), (unsigned short
        *)(u8 *)((u8 *)&stackFrame_1E[0]));
    v1 = g_TimerFrameNum;
    g_TimerFrameNum = (u32)(v1) + -1;
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u32 *)(s32)0xd;
        MGInitControl();
    }
    return;
}

/* PadOrderCPU1 @ 0x1FDCF0 .. 0x1FDD34 (0x44 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x1e escapes at 0x1fdd10
 */




static void PadOrderCPU1(void) {
    u32 *v0;
    u8 v1;
    u8 stackFrame_1E[2] __attribute__((aligned(2)));

    v0 = &lpPadData;
    v1 = GameSt[0xa];
    GetAnalogPad((void *)*(s32 *)(u32 *)((u8 *)&lpPadData + (u32)((u32)v1 << 2)), (unsigned short
        *)(u8 *)((u8 *)&stackFrame_1E[0]));
    GameSt[9] = (s32)(u32 *)(s32)0xf;
    MGInitControl();
    return;
}

static void PadViewOrder(void) {
    u32 a0;
    u8 v1;
    u8 *s1;
    u8 *s0;
    u32 v0;
    u8 stackFrame_3E[2] __attribute__((aligned(2)));

    v0 = (u32)&lpPadData;
    v1 = GameSt[0xa];
    s1 = (u8 *)*(s32 *)(u32)(s32)((u8 *)&lpPadData + (u32)((u32)v1 << 2));
    v0 = GetDiceNum();
    s0 = (u8 *)v0;
    GetAnalogPad((void *)(u32)(s32)s1, (unsigned short *)((u8 *)&stackFrame_3E[0]));
    v1 = *(u8 *)(s1 + 0x21);
    if ((u64)((u64)((u64)(u32)v1 << 0x39) >> 0x3f) != 0) {
        v1 = *(u8 *)(s0 + 1);
        v0 = *(u8 *)s0;
        if (v0 == (u32)v1) {
            GameSt[9] = 8;
        } else if ((s32)v1 < (s32)v0) {
            GameSt[9] = 0x10;
        } else {
            a0 = 2;
            GameSt[9] = 0x15;
            MGDiceAnimeStart(a0, a0);
        }
        MGInitControl();
    }
    return;
}


/* PadDiceThrowPlayer @ 0x1FDBB0 .. 0x1FDC18 (0x68 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fdbd8
 */




static void PadDiceThrowPlayer(void) {
    u32 *v0;
    u8 v1;
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = &lpPadData;
    v1 = GameSt[0xa];
    s0 = (u8 *)*(s32 *)(u32 *)((u8 *)&lpPadData + (u32)((u32)v1 << 2));
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        GameSt[9] = (s32)(u32 *)(s32)0x11;
        MGInitControl();
    }
    return;
}












void PadChoisePiecePlayer(void) {
    u32 a2;
    u8 *s3;
    u32 a1;
    u8 *s0;
    u8 *s2;
    u32 a0;
    u32 v1;
    u64 v1_64;
    u32 s1;
    u32 v0;
    u8 stackFrame_5E[2] __attribute__((aligned(2)));

    v0 = (u32)GetPieceTable();
    s3 = (u8 *)v0;
    v1 = GameSt[0xa];
    v0 = (u32)&lpPadData;
    v1 = v1 << 2;
    v0 = (s32)((u8 *)&lpPadData + v1);
    s0 = (u8 *)*(s32 *)v0;
    GetPieceAnimeInfo();
    v0 = GetDieAnimeInfo();
    s2 = (u8 *)v0;
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_5E[0]));
    a1 = *(u8 *)(s0 + 0x20);
    v1_64 = (u64)a1 << 0x39 >> 0x3f;
    if (v1_64 == 0) {
        v1_64 = (u64)a1 << 0x38;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 == 0) {
            a0 = *(u8 *)(s0 + 0x21);
            v1_64 = (u64)a0 << 0x3d >> 0x3f;
            if (v1_64 == 0) {
                goto _L001FD940;
            }
        }
    }
    a0 = 0x1388;
    a1 = 0x7f;
    SND_Play2D(a0, a1, 0);
    v1 = g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)((u8 *)v0 + (u32)(s3));
    v0 = *(u8 *)v1;
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeExit(a0);
    v1 = g_ChoisePiecePos;
    v0 = 0x17;
    v1 = v1 + 1;
    g_ChoisePiecePos = v1;
    v1 = g_ChoisePiecePos;
    if (v1 == v0) {
        v0 = 0xc;
        g_ChoisePiecePos = v0;
        goto _L001FD900;
        _L001FD8E0:;
        v1 = *(volatile u8 *)&g_ChoisePiecePos;
        v0 = 0x17;
        v1 = v1 + 1;
        g_ChoisePiecePos = v1;
        v1 = g_ChoisePiecePos;
        if (v1 == v0) {
            v0 = 0xc;
            g_ChoisePiecePos = v0;
        }
    }
    _L001FD900:;
    v1 = g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)(s3 + v0);
    v0 = *(u8 *)v1;
    if (v0 == 0) {
        goto _L001FD8E0;
    }
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeInit(a0);
    goto _L001FDA30;
    _L001FD940:;
    v1_64 = (u64)a1 << 0x3b >> 0x3f;
    if (v1_64 == 0) {
        v1_64 = (u64)a1 << 0x3a;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 == 0) {
            v1_64 = (u64)a0 << 0x3c >> 0x3f;
            if (v1_64 == 0) {
                goto _L001FDA30;
            }
        }
    }
    a0 = 0x1388;
    a1 = 0x7f;
    SND_Play2D(a0, a1, 0);
    v1 = g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)((u8 *)v0 + (u32)(s3));
    v0 = *(u8 *)v1;
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeExit(a0);
    v1 = g_ChoisePiecePos;
    v0 = 0xb;
    v1 = v1 + -1;
    g_ChoisePiecePos = v1;
    v1 = g_ChoisePiecePos;
    if (v1 == v0) {
        v0 = 0x16;
        g_ChoisePiecePos = v0;
        goto _L001FD9F8;
        _L001FD9D8:;
        v1 = *(volatile u8 *)&g_ChoisePiecePos;
        v0 = 0xb;
        v1 = v1 + -1;
        g_ChoisePiecePos = v1;
        v1 = g_ChoisePiecePos;
        if (v1 == v0) {
            v0 = 0x16;
            g_ChoisePiecePos = v0;
        }
    }
    _L001FD9F8:;
    v1 = g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)(s3 + v0);
    v0 = *(u8 *)v1;
    if (v0 == 0) {
        goto _L001FD9D8;
    }
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeInit(a0);
    _L001FDA30:;
    v1 = *(u8 *)(s0 + 0x21);
    v1_64 = (u64)v1 << 0x39 >> 0x3f;
    if (v1_64 != 0) {
        v0 = GetDieAnimeInfo();
        s1 = v0;
        a0 = 0x138d;
        a1 = 0x7f;
        s0 = (u8 *)(MdlMng + 0x5400);
        SND_Play2D(a0, a1, 0);
        {
            u32 modelScale;
            u8 *modelAddress;
            u8 *dieInfo;
            u8 diePos;
            u32 dieOffset;
            modelScale = 0x3f800000;
            a0 = g_ChoisePiecePos;
            v0 = (u32)MdlMng;
            a1 = 1;
            v1 = a0 * 0x1a0;
            a0 = (s32)((u8 *)v1 + (u32)(s3));
            v1 = *(u8 *)a0;
            v1 = v1 + -1;
            v1 = v1 + a0;
            v1 = *(u8 *)((v1 + 1));
            a0 = v1 + 0xa1;
            v1 = a0 * 0x1c0;
            ChangeAnimParam((void *)((u8 *)MdlMng + v1), a1, 0.0f);
            v1 = 0x13;
            GameSt[9] = v1;
            v1 = *(u8 *)(s2 + 0x35);
            if ((s32)v1 > 0) {
                *(u8 *)&g_ChoiseDiePos = 0;
            } else {
                v1 = 1;
                *(u8 *)&g_ChoiseDiePos = v1;
            }
            diePos = *(u8 *)&g_ChoiseDiePos;
            dieOffset = diePos * 0x50;
            dieInfo = (u8 *)(dieOffset + s1);
            modelAddress = (u8 *)MdlMng + (diePos + 0xd3) * 0x1c0;
            *(u32 *)(modelAddress + 0x10c) = modelScale;
            a0 = *(volatile u8 *)(dieInfo + 0x35);
            v1 = g_ChoisePiecePos;
            v1 += a0;
            v1 = (u8)v1;
        }
        a0 = 0x17;
        if ((s32)v1 > (s32)0x17) {
            v1 = v1 + -0x17;
            v1 = a0 - v1;
            v1 = (u8)v1;
        }
        a0 = (u8)v1;
        v1 = a0 * 0x1a0;
        a0 = (s32)(s3 + v1);
        v1 = *(u8 *)a0;
        v1 = v1 << 4;
        v1 = v1 + a0;
        *(f32 *)(s0 + 0x20) = *(float *)((v1 + 0x20));
        *(f32 *)(s0 + 0x24) = *(float *)((v1 + 0x24));
        *(f32 *)(s0 + 0x28) = *(float *)((v1 + 0x28));
        *(u8 *)(s0 + 2) = 0;
    }
    return;
}
void PadChoiseDiePlayer(void) {
    struct PadBits *lpPad;
    unsigned short Stick;
    unsigned int PieceID;
    struct PieceTbl *pTable;
    struct dw_2491335_fields *pMdlMngPiece;
    struct dw_2491335_fields *pMdlMngDie;
    struct DieInfo *pDieAnimeInfo;
    struct dw_2491335_fields *pMdlMngPieceMove;
    u8 MovePlace;
    u32 v1;
    u32 off;
    struct PieceTbl *piece;

    lpPad = (struct PadBits *)(&lpPadData)[GameSt[10]];
    pTable = (struct PieceTbl *)GetPieceTable();
    pDieAnimeInfo = (struct DieInfo *)GetDieAnimeInfo();
    GetPieceAnimeInfo();
    pMdlMngPieceMove = (struct dw_2491335_fields *)(MdlMng + 0x5400);
    GetAnalogPad(lpPad, &Stick);
    pMdlMngDie = MDL(g_ChoiseDiePos + 0xd3);
    if (lpPad->a6 || lpPad->a7 || lpPad->b2 || lpPad->a4 || lpPad->a5 || lpPad->b3) {
        SND_Play2D(0x1388, 0x7f, 0);
        pMdlMngDie->Alpha = 0.3f;
        g_ChoiseDiePos++;
        if (g_ChoiseDiePos == 2) {
            g_ChoiseDiePos = 0;
        }
        while (pDieAnimeInfo[g_ChoiseDiePos].num == 0) {
            g_ChoiseDiePos++;
            if (g_ChoiseDiePos == 2) {
                g_ChoiseDiePos = 0;
            }
        }
        pMdlMngDie = MDL(g_ChoiseDiePos + 0xd3);
        pMdlMngDie->Alpha = 1.0f;
        v1 = g_ChoisePiecePos + pDieAnimeInfo[g_ChoiseDiePos].num;
        v1 = (u8)v1;
        if ((s32)v1 > 0x17) {
            v1 = 0x17 - (v1 - 0x17);
            v1 = (u8)v1;
        }
        MovePlace = v1;
        {
            struct PieceTbl *pc = &pTable[MovePlace];
            u32 n = pc->PieceNum;
            pMdlMngPieceMove->Pos[0] = pc->PiecePos[n][0];
            pMdlMngPieceMove->Pos[1] = pc->PiecePos[n][1];
            pMdlMngPieceMove->Pos[2] = pc->PiecePos[n][2];
        }
        pMdlMngPieceMove->bErase = 0;
    }
    if (lpPad->b6 && 1.0f == pMdlMngDie->Alpha) {
        off = g_ChoisePiecePos * 0x1a0;
        piece = (struct PieceTbl *)((u8 *)off + (u32)pTable);
        PieceID = piece->PieceNum;
        PieceID -= 1;
        PieceID = piece->PieceID[PieceID];
        ChangeAnimParam(MDL(PieceID + 0xa1), 0, 0.0f);
        MGPieceSelectAnimeExit(PieceID);
        MGPieceMoveAnimeFirstInit(g_ChoiseDiePos, PieceID);
        MGPieceMoveAnimeInit(PieceID);
        SetDieAnimeInfoNum(g_ChoiseDiePos, 0);
        GameSt[9] = 0x14;
    } else if (lpPad->b5) {
        SND_Play2D(0x1389, 0x7f, 0);
        off = g_ChoisePiecePos * 0x1a0;
        piece = (struct PieceTbl *)((u8 *)off + (u32)pTable);
        PieceID = piece->PieceNum;
        PieceID -= 1;
        PieceID = piece->PieceID[PieceID];
        pMdlMngPiece = MDL(PieceID + 0xa1);
        {
            struct dw_2491335_fields *pd = MDL(g_ChoiseDiePos + 0xd3);
            pd->Alpha = 0.3f;
        }
        ChangeAnimParam(pMdlMngPiece, 0, 0.0f);
        pMdlMngPiece->Ang[0] = 0.0f;
        pMdlMngPiece->Ang[1] = -1.5704999f;
        pMdlMngPiece->Ang[2] = 0.0f;
        GameSt[9] = 0x12;
        pMdlMngPieceMove->bErase = 1;
    }
}


/* PadDiceThrowCPU @ 0x1FD420 .. 0x1FD45C (0x3c bytes, frame 0x10) */





static void PadDiceThrowCPU(void) {
    u32 v1;

    v1 = g_TimerFrameNum;
    v1 = v1 + -1;
    g_TimerFrameNum = v1;
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        *(u8 *)((u8 *)&GameSt + 9) = 0x16;
        MGInitControl();
    }
    return;
}

void PadChoisePieceCPU(void) {
    struct dw_2495435 *pTable;
    struct dw_2495620 *pDieAnimeInfo;
    u8 loop;

    pTable = (struct dw_2495435 *)GetPieceTable();
    pDieAnimeInfo = (struct dw_2495620 *)GetDieAnimeInfo();
    GetPieceAnimeInfo();
    switch (GetAIType() & 0xff) {
    case 0:
        CPU_PREFIX;
        if (pDieAnimeInfo[0].num > 0) {
            g_ChoiseDiePos = 0;
        } else {
            g_ChoiseDiePos = 1;
        }
        g_ChoisePiecePos = 0;
        while (pTable->PieceNum == 0) {
            pTable++;
            g_ChoisePiecePos++;
        }
        break;
    case 1:
        CPU_PREFIX;
        if (pDieAnimeInfo[0].num > 0) {
            g_ChoiseDiePos = 0;
            CPU_SEARCH(pDieAnimeInfo[0].num);
        } else {
            g_ChoiseDiePos = 1;
            CPU_SEARCH(pDieAnimeInfo[1].num);
        }
        g_ChoisePiecePos = 0;
        while (pTable->PieceNum == 0) {
            pTable++;
            g_ChoisePiecePos++;
        }
        break;
    }
}




void PadChoiseDieCPU(void) {
    u32 PieceID;
    struct dw_2495435 *pTable;
    struct dw_2495620 *pDieAnimeInfo;
    u8 *pMdlMngPieceMove;
    u8 diePos;
    u32 v1;
    struct dw_2495435 *piece;
    u32 pieceOffset;
    pTable = (struct dw_2495435 *)GetPieceTable();
    pDieAnimeInfo = (struct dw_2495620 *)GetDieAnimeInfo();
    GetPieceAnimeInfo();
    pMdlMngPieceMove = (u8 *)(MdlMng + 0x5390);
    diePos = *(u8 *)&g_ChoiseDiePos;
    v1 = g_ChoisePiecePos + pDieAnimeInfo[diePos].num;
    v1 = (u8)v1;
    if ((s32)v1 > 0xb) {
        v1 = 0xb - (v1 - 0xb);
        v1 = (u8)v1;
    }
    {
        u32 modelScale;
        u32 modelIndex;
        u8 movePos;
        struct dw_2495435 *pieceMove;
        u32 firstPieceID;

        movePos = (u8)v1;
        modelScale = 0x3f800000;
        pieceMove = (struct dw_2495435 *)((s32)pTable + movePos * 0x1a0);
        firstPieceID = pieceMove->PieceNum;
        *(float *)(pMdlMngPieceMove + 0x20) = pieceMove->PiecePos[firstPieceID][0];
        *(float *)(pMdlMngPieceMove + 0x24) = pieceMove->PiecePos[firstPieceID][1];
        *(float *)(pMdlMngPieceMove + 0x28) = pieceMove->PiecePos[firstPieceID][2];
        *(u8 *)(pMdlMngPieceMove + 2) = 0;
        diePos = *(u8 *)&g_ChoiseDiePos;
        modelIndex = diePos + 0xd3;
        *(u32 *)(modelIndex * 0x1c0 + (u8 *)MdlMng + 0x10c) = modelScale;
    }
    pieceOffset = g_ChoisePiecePos * 0x1a0;
    piece = (struct dw_2495435 *)(pieceOffset + (u32)pTable);
    PieceID = piece->PieceNum;
    PieceID -= 1;
    PieceID = piece->PieceID[PieceID];
    MGPieceMoveAnimeFirstInit(diePos, PieceID);
    MGPieceMoveAnimeInit(PieceID);
    SetDieAnimeInfoNum(*(u8 *)&g_ChoiseDiePos, 0);
    GameSt[9] = 0x19;
}

/* PadViewResultAnime1 @ 0x1FCD90 .. 0x1FCDCC (0x3c bytes, frame 0x10) */





static void PadViewResultAnime1(void) {
    u32 v1;

    v1 = g_TimerFrameNum;
    v1 = v1 + -1;
    g_TimerFrameNum = v1;
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        *(u8 *)((u8 *)&GameSt + 9) = 0x1b;
        MGInitControl();
    }
    return;
}

/* PadViewResultAnime2 @ 0x1FCCD0 .. 0x1FCD84 (0xb4 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   cfg: loop body is not one contiguous region: .L001FCD00
 */



static void PadViewResultAnime2(void) {
    extern u32 GetSpriteDraw(void);
    u8 *t0;
    s32 a3;
    s32 a2;
    s32 a1;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    t0 = v0;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(t0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(t0 + 0x4c) > 0) {
                *(u32 *)(t0 + 0x4c) += -1;
            }
        } else if (v1 == (u32)a1) {
            v1 = *(s32 *)(t0 + 0x3c);
            if ((s32)*(s32 *)(t0 + 0x4c) < (s32)v1) {
                *(u32 *)(t0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        t0 = (u8 *)(t0 + 0x70);
    } while (v1 != 0);
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)0x1c;
        MGInitControl();
    }
    return;
}

/* PadViewResultAnime3 @ 0x1FCC10 .. 0x1FCCC4 (0xb4 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   cfg: loop body is not one contiguous region: .L001FCC40
 */



static void PadViewResultAnime3(void) {
    extern u32 GetSpriteDraw(void);
    u8 *t0;
    s32 a3;
    s32 a2;
    s32 a1;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    t0 = v0;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(t0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(t0 + 0x4c) > 0) {
                *(u32 *)(t0 + 0x4c) += -1;
            }
        } else if (v1 == (u32)a1) {
            v1 = *(s32 *)(t0 + 0x3c);
            if ((s32)*(s32 *)(t0 + 0x4c) < (s32)v1) {
                *(u32 *)(t0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        t0 = (u8 *)(t0 + 0x70);
    } while (v1 != 0);
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)0x1d;
        MGInitControl();
    }
    return;
}

/* PadViewResult @ 0x1FCAF0 .. 0x1FCC08 (0x118 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fcb18
 *   delay: addiu at 0x1fcb58 writes a register its branch at 0x1fcb54 reads
 */






static void PadViewResult(void) {
    u32 *v0;
    u8 v1;
    u8 *s0;
    u32 a0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = &lpPadData;
    v1 = GameSt[0xa];
    s0 = (u8 *)*(s32 *)(u32 *)((u8 *)&lpPadData + (u32)((u32)v1 << 2));
    GetAnalogPad((void *)(u32)(s32)s0, (unsigned short *)(u32)((u8 *)&stackFrame_2E[0]));
    a0 = 0x138d;
    if ((u32)((struct { unsigned char _pad:4; unsigned char f:1; } *)&*(u8 *)(s0 + 0x20))->f != 0) {
        SND_Play2D(a0, 0x7f, 0);
        a0 = g_MenuPos;
        g_MenuPos = a0 + -1;
        a0 = g_MenuPos;
        if (a0 == (u32)0xff) {
            g_MenuPos = 1;
        }
    }
    a0 = 0x138d;
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x20))->f != 0) {
        SND_Play2D(a0, 0x7f, 0);
        a0 = g_MenuPos;
        g_MenuPos = a0 + 1;
        a0 = g_MenuPos;
        if (a0 == (u32)2) {
            g_MenuPos = 0;
        }
    }
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        a0 = g_MenuPos;
        if (a0 == 0) {
            GameSt[9] = (s32)(u32 *)(s32)8;
            MGInitControl();
        } else if (a0 == (u32)1) {
            GameSt[9] = (s32)(u32 *)(s32)0x1e;
            MGInitControl();
        }
    }
    return;
}

/* PadReturnTopMenuMainFadeTimer @ 0x1FCA10 .. 0x1FCAE8 (0xd8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x2e escapes at 0x1fcaac
 *   cfg: loop body is not one contiguous region: .L001FCA50
 */




static void PadReturnTopMenuMainFadeTimer(void) {
    extern u32 GetSpriteDraw(void);
    s32 a3;
    s32 a2;
    u32 s0;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u8 *)&lpPadData;
    v1 = GameSt[0xa];
    s0 = *(s32 *)(u8 *)((u8 *)&lpPadData + (u32)(v1 << 2));
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)2;
        MGInitTopMenu();
        MGInitControl();
    }
    return;
}

void PadCpmplsionCheck(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    u8 *s0;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v1 = (u32)&lpPadData;
    a1 = (u32)GameSt[0xa] << 2;
    v1 = (s32)((u8 *)&lpPadData + a1);
    s0 = (u8 *)*(s32 *)v1;
    a0 = GameSt[9];
    if (a0 == 0 || a0 == 7) {
        goto _L001FC9B8;
    }
    v1 = 7;
    if (a0 == (u32)0x28) {
        goto _L001FC9B8;
    }
    v1 = a0 + -0x2a;
    if (v1 <= (u32)3) {
        goto _L001FC9B8;
    }
    if ((u32)(a0 + -0x1a) <= (u32)5) {
        goto _L001FC9B8;
    }
    if ((u32)(a0 + -0x43) <= (u32)3) {
        goto _L001FC9B8;
    }
    v0 = (u8 *)GetMGPrcStatus();
    if (*(u8 *)v0 == 0) {
        _L001FC9B8:;
        return;
    }
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    if ((u64)((u64)((u64)(u32)*(u8 *)(s0 + 0x20) << 0x3c) >> 0x3f) != 0) {
        GameSt[4] = 1;
        MGInitComplsion();
        g_MenuPos = 1;
    }
    return;
}

void PadComplsionCtrl(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    u8 *s0;
    u32 v0;
    u64 v1_64;
    s32 at;
    u8 n;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u32)&lpPadData;
    v1 = GameSt[0xa];
    v1 = v1 << 2;
    v0 = (s32)((u8 *)&lpPadData + v1);
    s0 = (u8 *)*(s32 *)v0;
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = *(u8 *)(s0 + 0x20);
    v1_64 = (u64)v1 << 0x3c >> 0x3f;
    if (v1_64 != 0) {
        GameSt[4] = 0;
        n = GameSt[9];
        if (n < 16 || (n <= 53 && n > 45)) {
            MGInitOrderPlay();
        } else if (n < 29 || (n < 77 && n >= 54)) {
            MGInitMainPlay();
        } else if ((u32)(n - 32) <= 2 || n == 41) {
            MGInitTutorialTextView();
        } else {
            MGInitTutorialView();
        }
    }
    v1 = *(u8 *)(s0 + 0x20);
    v1_64 = (u64)v1 << 0x3b >> 0x3f;
    a0 = 0x138d;
    if (v1_64 != 0) {
        a1 = 0x7f;
        SND_Play2D(a0, a1, 0);
        a0 = g_MenuPos;
        v1 = 0xff;
        a0 = a0 + -1;
        g_MenuPos = a0;
        a0 = g_MenuPos;
        if (a0 == v1) {
            v1 = 1;
            g_MenuPos = v1;
        }
    }
    v1 = *(u8 *)(s0 + 0x20);
    v1_64 = (u64)v1 << 0x39 >> 0x3f;
    a0 = 0x138d;
    if (v1_64 != 0) {
        a1 = 0x7f;
        SND_Play2D(a0, a1, 0);
        a0 = g_MenuPos;
        v1 = 2;
        a0 = a0 + 1;
        g_MenuPos = a0;
        a0 = g_MenuPos;
        if (a0 == v1) {
            g_MenuPos = 0;
        }
    }
    v1 = *(u8 *)(s0 + 0x21);
    v1_64 = (u64)v1 << 0x39 >> 0x3f;
    if (v1_64 != 0) {
        GameSt[4] = 0;
        n = GameSt[9];
        if (n < 16 || (n <= 53 && n > 45)) {
            MGInitOrderPlay();
        } else if (n < 29 || (n < 77 && n >= 54)) {
            MGInitMainPlay();
        } else if ((u32)(n - 32) <= 2 || n == 41) {
            MGInitTutorialTextView();
        } else {
            MGInitTutorialView();
        }
        v1 = g_MenuPos;
        a0 = 0x1391;
        if (v1 == 0) {
            a1 = 0x7f;
            SND_Play2D(a0, a1, 0);
            v0 = 0x2c;
            GameSt[9] = v0;
            MGInitControl();
        }
    }
    return;
}

/* PadTopMenuTutorialFadeTimer @ 0x1FC610 .. 0x1FC6E0 (0xd0 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x2e escapes at 0x1fc6ac
 *   cfg: loop body is not one contiguous region: .L001FC650
 */



static void PadTopMenuTutorialFadeTimer(void) {
    extern u32 GetSpriteDraw(void);
    s32 a3;
    s32 a2;
    u32 s0;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u8 *)&lpPadData;
    v1 = GameSt[0xa];
    s0 = *(s32 *)(u8 *)((u8 *)&lpPadData + (u32)(v1 << 2));
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)0x20;
        MGInitControl();
    }
    return;
}

/* PadTutorialText1 @ 0x1FC5A0 .. 0x1FC608 (0x68 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fc5c8
 */




static void PadTutorialText1(void) {
    u32 *v0;
    u8 v1;
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = &lpPadData;
    v1 = GameSt[0xa];
    s0 = (u8 *)*(s32 *)(u32 *)((u8 *)&lpPadData + (u32)((u32)v1 << 2));
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        GameSt[9] = (s32)(u32 *)(s32)0x21;
        MGInitControl();
    }
    return;
}

/* PadTutorialText2 @ 0x1FC530 .. 0x1FC598 (0x68 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fc558
 */




static void PadTutorialText2(void) {
    u32 *v0;
    u8 v1;
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = &lpPadData;
    v1 = GameSt[0xa];
    s0 = (u8 *)*(s32 *)(u32 *)((u8 *)&lpPadData + (u32)((u32)v1 << 2));
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        GameSt[9] = (s32)(u32 *)(s32)0x22;
        MGInitControl();
    }
    return;
}

/* PadTutorialText3 @ 0x1FC4C0 .. 0x1FC528 (0x68 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fc4e8
 */




static void PadTutorialText3(void) {
    u32 *v0;
    u8 v1;
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = &lpPadData;
    v1 = GameSt[0xa];
    s0 = (u8 *)*(s32 *)(u32 *)((u8 *)&lpPadData + (u32)((u32)v1 << 2));
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        GameSt[9] = (s32)(u32 *)(s32)0x23;
        MGInitControl();
    }
    return;
}


/* PadTutorialThrow1 @ 0x1FC450 .. 0x1FC4B8 (0x68 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fc478
 */




static void PadTutorialThrow1(void) {
    u32 *v0;
    u8 v1;
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = &lpPadData;
    v1 = GameSt[0xa];
    s0 = (u8 *)*(s32 *)(u32 *)((u8 *)&lpPadData + (u32)((u32)v1 << 2));
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        GameSt[9] = (s32)(u32 *)(s32)0x24;
        MGInitControl();
    }
    return;
}


/* PadTutorialChoicePiece @ 0x1FC090 .. 0x1FC44C (0x3bc bytes, frame 0x60) */
/* Partial: 13 code-diff bytes and 25 relocation-only bytes remain.
 * The code diff is in g_ChoiseDiePos GP/register use; g_ChoisePiecePos
 * still resolves differently from the target's .sbss+0x10 references.
 * why.py reports a declaration conflict for PadTutorialChoicePiece. */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x5e escapes at 0x1fc0dc
 *   delay: dsll32 at 0x1fc0f4 writes a register its branch at 0x1fc0f0 reads
 *   delay: addiu at 0x1fc170 writes a register its branch at 0x1fc16c reads
 *   delay: addiu at 0x1fc198 writes a register its branch at 0x1fc194 reads
 *   delay: dsll32 at 0x1fc1ec writes a register its branch at 0x1fc1e8 reads
 *   delay: addiu at 0x1fc268 writes a register its branch at 0x1fc264 reads
 *   delay: addiu at 0x1fc290 writes a register its branch at 0x1fc28c reads
 *   fpu: float literal 0x00000000 at 0x1fc318
 *   cfg: kept branch: 0x1fc104 if (..) goto .L001FC1E0
 *   cfg: kept goto: 0x1fc170 -> .L001FC1A0
 *   cfg: loop test does not fall through into its body: 0x1fc1a0
 *   cfg: kept branch: 0x1fc1a0 if (..) goto .L001FC180
 *   cfg: kept goto: 0x1fc1c8 -> .L001FC2D0
 *   cfg: kept branch: 0x1fc1fc if (..) goto .L001FC2D0
 *   cfg: kept goto: 0x1fc268 -> .L001FC298
 *   cfg: loop test does not fall through into its body: 0x1fc298
 *   cfg: kept branch: 0x1fc298 if (..) goto .L001FC278
 */











void PadTutorialChoicePiece(void) {
    u32 a2;
    u8 *s3;
    u32 a1;
    u8 *s0;
    u8 *s2;
    u32 a0;
    u32 v1;
    u64 v1_64;
    u32 s1;
    u32 v0;
    u8 stackFrame_5E[2] __attribute__((aligned(2)));

    v0 = (u32)GetPieceTable();
    s3 = (u8 *)v0;
    v1 = GameSt[0xa];
    v0 = (u32)&lpPadData;
    v1 = v1 << 2;
    v0 = (s32)((u8 *)&lpPadData + v1);
    s0 = (u8 *)*(s32 *)v0;
    GetPieceAnimeInfo();
    v0 = GetDieAnimeInfo();
    s2 = (u8 *)v0;
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_5E[0]));
    a1 = *(u8 *)(s0 + 0x20);
    v1_64 = (u64)a1 << 0x39 >> 0x3f;
    if (v1_64 == 0) {
        v1_64 = (u64)a1 << 0x38;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 == 0) {
            a0 = *(u8 *)(s0 + 0x21);
            v1_64 = (u64)a0 << 0x3d >> 0x3f;
            if (v1_64 == 0) {
                goto _L001FC1E0;
            }
        }
    }
    a0 = 0x1388;
    a1 = 0x7f;
    SND_Play2D(a0, a1, 0);
    v1 = *(volatile u8 *)&g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)((u8 *)v0 + (u32)(s3));
    v0 = *(u8 *)v1;
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeExit(a0);
    v1 = *(volatile u8 *)&g_ChoisePiecePos;
    v0 = 0x17;
    v1 = v1 + 1;
    *(volatile u8 *)&g_ChoisePiecePos = v1;
    v1 = *(volatile u8 *)&g_ChoisePiecePos;
    if (v1 == v0) {
        v0 = 0xc;
        *(volatile u8 *)&g_ChoisePiecePos = v0;
        goto _L001FC1A0;
        _L001FC180:;
        v1 = *(volatile u8 *)&g_ChoisePiecePos;
        v0 = 0x17;
        v1 = v1 + 1;
        *(volatile u8 *)&g_ChoisePiecePos = v1;
        v1 = *(volatile u8 *)&g_ChoisePiecePos;
        if (v1 == v0) {
            v0 = 0xc;
            *(volatile u8 *)&g_ChoisePiecePos = v0;
        }
    }
    _L001FC1A0:;
    v1 = *(volatile u8 *)&g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)(s3 + v0);
    v0 = *(u8 *)v1;
    if (v0 == 0) {
        goto _L001FC180;
    }
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeInit(a0);
    goto _L001FC2D0;
    _L001FC1E0:;
    v1_64 = (u64)a1 << 0x3b >> 0x3f;
    if (v1_64 == 0) {
        v1_64 = (u64)a1 << 0x3a;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 == 0) {
            v1_64 = (u64)a0 << 0x3c >> 0x3f;
            if (v1_64 == 0) {
                goto _L001FC2D0;
            }
        }
    }
    a0 = 0x1388;
    a1 = 0x7f;
    SND_Play2D(a0, a1, 0);
    v1 = *(volatile u8 *)&g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)((u8 *)v0 + (u32)(s3));
    v0 = *(u8 *)v1;
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeExit(a0);
    v1 = *(volatile u8 *)&g_ChoisePiecePos;
    v0 = 0xb;
    v1 = v1 + -1;
    *(volatile u8 *)&g_ChoisePiecePos = v1;
    v1 = *(volatile u8 *)&g_ChoisePiecePos;
    if (v1 == v0) {
        v0 = 0x16;
        *(volatile u8 *)&g_ChoisePiecePos = v0;
        goto _L001FC298;
        _L001FC278:;
        v1 = *(volatile u8 *)&g_ChoisePiecePos;
        v0 = 0xb;
        v1 = v1 + -1;
        *(volatile u8 *)&g_ChoisePiecePos = v1;
        v1 = *(volatile u8 *)&g_ChoisePiecePos;
        if (v1 == v0) {
            v0 = 0x16;
            *(volatile u8 *)&g_ChoisePiecePos = v0;
        }
    }
    _L001FC298:;
    v1 = *(volatile u8 *)&g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)(s3 + v0);
    v0 = *(u8 *)v1;
    if (v0 == 0) {
        goto _L001FC278;
    }
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeInit(a0);
    _L001FC2D0:;
    v1 = *(u8 *)(s0 + 0x21);
    v1_64 = (u64)v1 << 0x39 >> 0x3f;
    if (v1_64 != 0) {
        v0 = GetDieAnimeInfo();
        s1 = v0;
        a0 = 0x138d;
        a1 = 0x7f;
        s0 = (u8 *)(MdlMng + 0x5390);
        SND_Play2D(a0, a1, 0);
        a0 = *(volatile u8 *)&g_ChoisePiecePos;
        v0 = (u32)MdlMng;
        a1 = 1;
        v1 = a0 * 0x1a0;
        a0 = (s32)((u8 *)v1 + (u32)(s3));
        v1 = *(u8 *)a0;
        v1 = v1 + -1;
        v1 = v1 + a0;
        v1 = *(u8 *)((v1 + 1));
        a0 = v1 + 0xa1;
        v1 = a0 * 0x1c0;
        ChangeAnimParam((void *)((u8 *)MdlMng + v1), a1, 0.0f);
        v1 = 0x26;
        GameSt[9] = v1;
        v1 = *(u8 *)(s2 + 0x35);
        if ((s32)v1 > 0) {
            *(volatile u8 *)&g_ChoiseDiePos = 0;
        } else {
            v1 = 1;
            *(volatile u8 *)&g_ChoiseDiePos = v1;
        }
        {
            u32 chosen;
            s32 modelAddress;
            s32 die = *(u8 *)&g_ChoiseDiePos;
            s32 dieOffset = die * 80;
            s32 modelIndex = die + 211;
            modelAddress = (u32)MdlMng + modelIndex * 448;
            *(u32 *)(modelAddress + 268) = 0x3f800000;
            modelAddress = *(u8 *)(dieOffset + s1 + 53);
            chosen = g_ChoisePiecePos;
            v1 = chosen + modelAddress;
        }
        v1 = (u8)v1;
        a0 = 0x17;
        if ((s32)v1 > (s32)0x17) {
            v1 = v1 + -0x17;
            v1 = a0 - v1;
            v1 = (u8)v1;
        }
        a0 = (u8)v1;
        v1 = a0 * 0x1a0;
        a0 = (s32)(s3 + v1);
        v1 = *(u8 *)a0;
        v1 = v1 << 4;
        v1 = v1 + a0;
        *(f32 *)(s0 + 0x20) = *(float *)((v1 + 0x20));
        *(f32 *)(s0 + 0x24) = *(float *)((v1 + 0x24));
        *(f32 *)(s0 + 0x28) = *(float *)((v1 + 0x28));
        *(u8 *)(s0 + 2) = 0;
    }
    return;
}
void PadTutorialChoiceDie(void) {
    struct PadBits *lpPad;
    unsigned short Stick;
    unsigned int PieceID;
    unsigned int PieceNo;
    struct PieceTbl *pTable;
    struct dw_2491335_fields *pMdlMngPiece;
    struct dw_2491335_fields *pMdlMngDie;
    struct DieInfo *pDieAnimeInfo;
    struct dw_2491335_fields *pMdlMngPieceMove;
    u8 MovePlace;
    u32 v1;
    u32 off;
    struct PieceTbl *piece;

    lpPad = (struct PadBits *)(&lpPadData)[GameSt[10]];
    pTable = (struct PieceTbl *)GetPieceTable();
    pDieAnimeInfo = (struct DieInfo *)GetDieAnimeInfo();
    GetPieceAnimeInfo();
    pMdlMngPieceMove = (struct dw_2491335_fields *)(MdlMng + 0x5390);
    GetAnalogPad(lpPad, &Stick);
    pMdlMngDie = MDL(g_ChoiseDiePos + 0xd3);
    if (lpPad->a6 || lpPad->a7 || lpPad->b2 || lpPad->a4 || lpPad->a5 || lpPad->b3) {
        SND_Play2D(0x1388, 0x7f, 0);
        pMdlMngDie->Alpha = 0.3f;
        g_ChoiseDiePos++;
        if (g_ChoiseDiePos == 2) {
            g_ChoiseDiePos = 0;
        }
        while (pDieAnimeInfo[g_ChoiseDiePos].num == 0) {
            g_ChoiseDiePos++;
            if (g_ChoiseDiePos == 2) {
                g_ChoiseDiePos = 0;
            }
        }
        pMdlMngDie = MDL(g_ChoiseDiePos + 0xd3);
        pMdlMngDie->Alpha = 1.0f;
        v1 = g_ChoisePiecePos + pDieAnimeInfo[g_ChoiseDiePos].num;
        v1 = (u8)v1;
        if ((s32)v1 > 0x17) {
            v1 = 0x17 - (v1 - 0x17);
            v1 = (u8)v1;
        }
        MovePlace = v1;
        {
            struct PieceTbl *pc = &pTable[MovePlace];
            u32 n = pc->PieceNum;
            pMdlMngPieceMove->Pos[0] = pc->PiecePos[n][0];
            pMdlMngPieceMove->Pos[1] = pc->PiecePos[n][1];
            pMdlMngPieceMove->Pos[2] = pc->PiecePos[n][2];
        }
        pMdlMngPieceMove->bErase = 0;
    }
    if (lpPad->b6 && 1.0f == pMdlMngDie->Alpha) {
        off = g_ChoisePiecePos * 0x1a0;
        piece = (struct PieceTbl *)((u8 *)off + (u32)pTable);
        PieceID = piece->PieceNum;
        PieceID -= 1;
        PieceNo = piece->PieceID[PieceID];
        ChangeAnimParam(MDL(PieceNo + 0xa1), 0, 0.0f);
        MGPieceSelectAnimeExit(PieceNo);
        MGPieceMoveAnimeFirstInit(g_ChoiseDiePos, PieceNo);
        MGPieceMoveAnimeInit(PieceNo);
        SetDieAnimeInfoNum(g_ChoiseDiePos, 0);
        GameSt[9] = 0x27;
    }
    if (lpPad->b5) {
        SND_Play2D(0x1389, 0x7f, 0);
        off = g_ChoisePiecePos * 0x1a0;
        piece = (struct PieceTbl *)((u8 *)off + (u32)pTable);
        PieceID = piece->PieceNum;
        PieceID -= 1;
        PieceID = piece->PieceID[PieceID];
        pMdlMngPiece = MDL(PieceID + 0xa1);
        {
            struct dw_2491335_fields *pd = MDL(g_ChoiseDiePos + 0xd3);
            pd->Alpha = 0.3f;
        }
        ChangeAnimParam(pMdlMngPiece, 0, 0.0f);
        pMdlMngPiece->Ang[0] = 0.0f;
        pMdlMngPiece->Ang[1] = -1.5704999f;
        pMdlMngPiece->Ang[2] = 0.0f;
        GameSt[9] = 0x25;
        pMdlMngPieceMove->bErase = 1;
    }
}

/* PadTutorialMovePieceFade @ 0x1FBC30 .. 0x1FBD00 (0xd0 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x2e escapes at 0x1fbccc
 *   cfg: loop body is not one contiguous region: .L001FBC70
 */



static void PadTutorialMovePieceFade(void) {
    extern u32 GetSpriteDraw(void);
    s32 a3;
    s32 a2;
    u32 s0;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u8 *)&lpPadData;
    v1 = GameSt[0xa];
    s0 = *(s32 *)(u8 *)((u8 *)&lpPadData + (u32)(v1 << 2));
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)0x29;
        MGInitControl();
    }
    return;
}

/* PadTutorialText4 @ 0x1FBBD0 .. 0x1FBC30 (0x60 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fbbf8
 *   return without a value in a non-void function
 */





static u32 PadTutorialText4(void) {
    u32 *v0;
    u8 v1;
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = &lpPadData;
    v1 = GameSt[0xa];
    s0 = (u8 *)*(s32 *)(u32 *)((u8 *)&lpPadData + (u32)((u32)v1 << 2));
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    v1 = *(u8 *)(s0 + 0x21);
    if ((u64)((u64)((u64)(u32)v1 << 0x39) >> 0x3f) != 0) {
        g_MenuPos = 0;
        GameSt[9] = 0x2a;
    }
    return;
}

/* PadTutorialOnmoreMenu @ 0x1FBA90 .. 0x1FBBC8 (0x138 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fbab8
 *   delay: addiu at 0x1fbaf8 writes a register its branch at 0x1fbaf4 reads
 */






static void PadTutorialOnmoreMenu(void) {
    u32 *v0;
    u8 v1;
    u8 *s0;
    u32 a0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = &lpPadData;
    v1 = GameSt[0xa];
    s0 = (u8 *)*(s32 *)(u32 *)((u8 *)&lpPadData + (u32)((u32)v1 << 2));
    GetAnalogPad((void *)(u32)(s32)s0, (unsigned short *)(u32)((u8 *)&stackFrame_2E[0]));
    a0 = 0x138d;
    if ((u32)((struct { unsigned char _pad:4; unsigned char f:1; } *)&*(u8 *)(s0 + 0x20))->f != 0) {
        SND_Play2D(a0, 0x7f, 0);
        a0 = g_MenuPos;
        g_MenuPos = a0 + -1;
        a0 = g_MenuPos;
        if (a0 == (u32)0xff) {
            g_MenuPos = 1;
        }
    }
    a0 = 0x138d;
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x20))->f != 0) {
        SND_Play2D(a0, 0x7f, 0);
        a0 = g_MenuPos;
        g_MenuPos = a0 + 1;
        a0 = g_MenuPos;
        if (a0 == (u32)2) {
            g_MenuPos = 0;
        }
    }
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        a0 = g_MenuPos;
        if (a0 == 0) {
            SND_Play2D(0x1391, 0x7f, 0);
            GameSt[9] = (s32)(u32 *)(s32)0x2b;
            MGInitControl();
        } else if (a0 == (u32)1) {
            SND_Play2D(0x1391, 0x7f, 0);
            GameSt[9] = (s32)(u32 *)(s32)0x20;
            MGInitControl();
        }
    }
    return;
}

/* PadReturnTopMenuTutorialFadeTimer @ 0x1FB9B0 .. 0x1FBA88 (0xd8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x2e escapes at 0x1fba4c
 *   cfg: loop body is not one contiguous region: .L001FB9F0
 */




static void PadReturnTopMenuTutorialFadeTimer(void) {
    extern u32 GetSpriteDraw(void);
    s32 a3;
    s32 a2;
    u32 s0;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u8 *)&lpPadData;
    v1 = GameSt[0xa];
    s0 = *(s32 *)(u8 *)((u8 *)&lpPadData + (u32)(v1 << 2));
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)2;
        MGInitTopMenu();
        MGInitControl();
    }
    return;
}

/* PadComplsionFadeTimer @ 0x1FB8D0 .. 0x1FB9A8 (0xd8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x2e escapes at 0x1fb96c
 *   cfg: loop body is not one contiguous region: .L001FB910
 */




static void PadComplsionFadeTimer(void) {
    extern u32 GetSpriteDraw(void);
    s32 a3;
    s32 a2;
    u32 s0;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u8 *)&lpPadData;
    v1 = GameSt[0xa];
    s0 = *(s32 *)(u8 *)((u8 *)&lpPadData + (u32)(v1 << 2));
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)2;
        MGInitTopMenu();
        MGInitControl();
    }
    return;
}

/* Pad2PModeMenuMainFadeTimer @ 0x1FB7F0 .. 0x1FB8CC (0xdc bytes, frame 0x40) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x3e escapes at 0x1fb884
 *   stack: address of the slot at 0x3e escapes at 0x1fb890
 *   cfg: loop body is not one contiguous region: .L001FB828
 */

static void Pad2PModeMenuMainFadeTimer(void) {
    extern u32 GetSpriteDraw(void);
    u32 s1;
    u32 s0;
    s32 a3;
    s32 a2;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_3E[2] __attribute__((aligned(2)));

    s1 = lpPadData;
    s0 = *(s32 *)((u8 *)&lpPadData + 4);
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s1, (unsigned short *)((u8 *)&stackFrame_3E[0]));
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_3E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)0x2e;
        MGInitControl();
    }
    return;
}

/* Pad2PMode1POrderPlayer0 @ 0x1FB770 .. 0x1FB7EC (0x7c bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x3e escapes at 0x1fb78c
 *   stack: address of the slot at 0x3e escapes at 0x1fb798
 */

static void Pad2PMode1POrderPlayer0(void) {
    u8 *s1;
    u8 *s0;
    u8 stackFrame_3E[2] __attribute__((aligned(2)));

    s0 = (u8 *)lpPadData;
    s1 = (u8 *)*(s32 *)((u8 *)&lpPadData + 4);
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_3E[0]));
    GetAnalogPad((void *)(u8 *)s1, (unsigned short *)(u8 *)((u8 *)&stackFrame_3E[0]));
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0
        || (u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s1 + 0x21))->f !=
        0) {
        GameSt[9] = 0x2f;
        MGInitControl();
    }
    return;
}

/* Pad2PMode1POrderPlayer @ 0x1FB720 .. 0x1FB770 (0x50 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fb734
 */




static void Pad2PMode1POrderPlayer(void) {
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    s0 = (u8 *)lpPadData;
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        GameSt[9] = 0x30;
        MGInitControl();
    }
    return;
}

/* Pad2PMode1POrderPlayer1 @ 0x1FB6D0 .. 0x1FB720 (0x50 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fb6e4
 */




static void Pad2PMode1POrderPlayer1(void) {
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    s0 = (u8 *)lpPadData;
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        GameSt[9] = 0x32;
        MGInitControl();
    }
    return;
}

/* Pad2PMode2POrderPlayer @ 0x1FB680 .. 0x1FB6D0 (0x50 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fb694
 */




static void Pad2PMode2POrderPlayer(void) {
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    s0 = (u8 *)*(s32 *)((u8 *)&lpPadData + 4);
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        GameSt[9] = 0x33;
        MGInitControl();
    }
    return;
}

/* Pad2PMode2POrderPlayer1 @ 0x1FB650 .. 0x1FB680 (0x30 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x1e escapes at 0x1fb65c
 */




static void Pad2PMode2POrderPlayer1(void) {
    u8 stackFrame_1E[2] __attribute__((aligned(2)));

    GetAnalogPad((void *)*(s32 *)((u8 *)&lpPadData + 4), (unsigned short *)(u8 *)((u8
        *)&stackFrame_1E[0]));
    GameSt[9] = 0x35;
    MGInitControl();
    return;
}

static void Pad2PModeViewOrder(void) {
    u8 *s2;
    u8 *s1;
    u8 *a1;
    u8 *s0;
    u8 *a0;
    u32 v1;
    u32 v0;
    u64 v1_64;
    u8 stackFrame_4E[2] __attribute__((aligned(2)));

    s2 = (u8 *)lpPadData;
    s1 = (u8 *)*(s32 *)((u8 *)&lpPadData + 4);
    v0 = GetDiceNum();
    s0 = (u8 *)v0;
    a0 = (u8 *)s2;
    GetAnalogPad((void *)a0, (unsigned short *)(u8 *)((u8 *)&stackFrame_4E[0]));
    a0 = (u8 *)s1;
    GetAnalogPad((void *)a0, (unsigned short *)((u8 *)&stackFrame_4E[0]));
    v1 = *(u8 *)(s2 + 0x21);
    v1_64 = (u64)((u64)v1 << 0x39) >> 0x3f;
    if (v1_64 == 0) {
        v1 = *(u8 *)(s1 + 0x21);
        v1_64 = (u64)((u64)v1 << 0x39) >> 0x3f;
        if (v1_64 == 0) {
            goto _L001FB630;
        }
    }
    v1 = *(u8 *)(s0 + 1);
    v0 = *(u8 *)s0;
    if (v0 == v1) {
        v0 = 0x2e;
        GameSt[9] = v0;
    } else if ((s32)v1 < (s32)v0) {
        v0 = 0x36;
        GameSt[9] = v0;
    } else {
        v0 = 0x3b;
        GameSt[9] = v0;
    }
    MGInitControl();
    _L001FB630:;
    return;
}


/* Pad2PMode1PDiceThrowPlayer @ 0x1FB520 .. 0x1FB570 (0x50 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fb534
 */




static void Pad2PMode1PDiceThrowPlayer(void) {
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    s0 = (u8 *)lpPadData;
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        GameSt[9] = 0x37;
        MGInitControl();
    }
    return;
}

void Pad2PMode1PChoisePiecePlayer(void) {
    u32 a2;
    u32 a3;
    u8 *s3;
    u8 *s0;
    u8 *s2;
    u32 a1;
    u32 a0;
    u64 v1_64;
    u32 v1;
    u32 s1;
    u32 v0;
    u8 stackFrame_5E[2] __attribute__((aligned(2)));

    v0 = (u32)GetPieceTable();
    s0 = (u8 *)lpPadData;
    s3 = (u8 *)v0;
    GetPieceAnimeInfo();
    v0 = GetDieAnimeInfo();
    s2 = (u8 *)v0;
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_5E[0]));
    a1 = *(u8 *)(s0 + 0x20);
    v1_64 = (u64)a1 << 0x39 >> 0x3f;
    if (v1_64 == 0) {
        v1_64 = (u64)a1 << 0x38;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 == 0) {
            a0 = *(u8 *)(s0 + 0x21);
            v1_64 = (u64)a0 << 0x3d >> 0x3f;
            if (v1_64 == 0) {
                goto _L001FB2B0;
            }
        }
    }
    a0 = 0x1388;
    a1 = 0x7f;
    SND_Play2D(a0, a1, 0);
    v1 = g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)((u8 *)v0 + (u32)(s3));
    v0 = *(u8 *)v1;
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeExit(a0);
    v1 = g_ChoisePiecePos;
    v0 = 0x17;
    v1 = v1 + 1;
    g_ChoisePiecePos = v1;
    v1 = g_ChoisePiecePos;
    if (v1 == v0) {
        v0 = 0xc;
        g_ChoisePiecePos = v0;
        goto _L001FB270;
        _L001FB250:;
        v1 = *(volatile u8 *)&g_ChoisePiecePos;
        v0 = 0x17;
        v1 = v1 + 1;
        g_ChoisePiecePos = v1;
        v1 = g_ChoisePiecePos;
        if (v1 == v0) {
            v0 = 0xc;
            g_ChoisePiecePos = v0;
        }
    }
    _L001FB270:;
    v1 = g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)(s3 + v0);
    v0 = *(u8 *)v1;
    if (v0 == 0) {
        goto _L001FB250;
    }
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeInit(a0);
    goto _L001FB3A0;
    _L001FB2B0:;
    v1_64 = (u64)a1 << 0x3b >> 0x3f;
    if (v1_64 == 0) {
        v1_64 = (u64)a1 << 0x3a;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 == 0) {
            v1_64 = (u64)a0 << 0x3c >> 0x3f;
            if (v1_64 == 0) {
                goto _L001FB3A0;
            }
        }
    }
    a0 = 0x1388;
    a1 = 0x7f;
    SND_Play2D(a0, a1, 0);
    v1 = g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)((u8 *)v0 + (u32)(s3));
    v0 = *(u8 *)v1;
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeExit(a0);
    v1 = g_ChoisePiecePos;
    v0 = 0xb;
    v1 = v1 + -1;
    g_ChoisePiecePos = v1;
    v1 = g_ChoisePiecePos;
    if (v1 == v0) {
        v0 = 0x16;
        g_ChoisePiecePos = v0;
        goto _L001FB368;
        _L001FB348:;
        v1 = *(volatile u8 *)&g_ChoisePiecePos;
        v0 = 0xb;
        v1 = v1 + -1;
        g_ChoisePiecePos = v1;
        v1 = g_ChoisePiecePos;
        if (v1 == v0) {
            v0 = 0x16;
            g_ChoisePiecePos = v0;
        }
    }
    _L001FB368:;
    v1 = g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)(s3 + v0);
    v0 = *(u8 *)v1;
    if (v0 == 0) {
        goto _L001FB348;
    }
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeInit(a0);
    _L001FB3A0:;
    v1 = *(u8 *)(s0 + 0x21);
    v1_64 = (u64)v1 << 0x39 >> 0x3f;
    if (v1_64 != 0) {
        v0 = GetDieAnimeInfo();
        s1 = v0;
        a0 = 0x138d;
        a1 = 0x7f;
        s0 = (u8 *)(MdlMng + 0x5400);
        SND_Play2D(a0, a1, 0);
        a0 = g_ChoisePiecePos;
        v0 = (u32)MdlMng;
        a1 = 1;
        v1 = a0 * 0x1a0;
        a0 = (s32)((u8 *)v1 + (u32)(s3));
        v1 = *(u8 *)a0;
        v1 = v1 + -1;
        v1 = v1 + a0;
        v1 = *(u8 *)((v1 + 1));
        a0 = v1 + 0xa1;
        v1 = a0 * 0x1c0;
        ChangeAnimParam((void *)((u8 *)MdlMng + v1), a1, 0.0f);
        v1 = 0x39;
        GameSt[9] = v1;
        v1 = *(u8 *)(s2 + 0x35);
        if ((s32)v1 > 0) {
            *(u8 *)&g_ChoiseDiePos = 0;
        } else {
            v1 = 1;
            *(u8 *)&g_ChoiseDiePos = v1;
        }
        {
            u32 chosen;
            s32 modelAddress;
            s32 die = *(u8 *)&g_ChoiseDiePos;
            s32 dieOffset = die * 80;
            s32 modelIndex = die + 211;
            modelAddress = (u32)MdlMng + modelIndex * 448;
            *(u32 *)(modelAddress + 268) = 0x3f800000;
            modelAddress = *(u8 *)(dieOffset + s1 + 53);
            chosen = g_ChoisePiecePos;
            v1 = chosen + modelAddress;
        }
        v1 = (u8)v1;
        a0 = 0x17;
        if ((s32)v1 > (s32)0x17) {
            v1 = v1 + -0x17;
            v1 = a0 - v1;
            v1 = (u8)v1;
        }
        a0 = (u8)v1;
        v1 = a0 * 0x1a0;
        a0 = (s32)(s3 + v1);
        v1 = *(u8 *)a0;
        v1 = v1 << 4;
        v1 = v1 + a0;
        *(f32 *)(s0 + 0x20) = *(float *)((v1 + 0x20));
        *(f32 *)(s0 + 0x24) = *(float *)((v1 + 0x24));
        *(f32 *)(s0 + 0x28) = *(float *)((v1 + 0x28));
        *(u8 *)(s0 + 2) = 0;
    }
    return;
}
void Pad2PMode1PChoiseDiePlayer(void) {
    struct PadBits *lpPad;
    unsigned short Stick;
    unsigned int PieceID;
    struct PieceTbl *pTable;
    struct dw_2491335_fields *pMdlMngPiece;
    struct dw_2491335_fields *pMdlMngDie;
    struct DieInfo *pDieAnimeInfo;
    struct dw_2491335_fields *pMdlMngPieceMove;
    u8 MovePlace;
    u32 v1;
    u32 off;
    struct PieceTbl *piece;

    lpPad = (struct PadBits *)lpPadData;
    pTable = (struct PieceTbl *)GetPieceTable();
    pDieAnimeInfo = (struct DieInfo *)GetDieAnimeInfo();
    GetPieceAnimeInfo();
    pMdlMngPieceMove = (struct dw_2491335_fields *)(MdlMng + 0x5400);
    GetAnalogPad(lpPad, &Stick);
    pMdlMngDie = MDL(g_ChoiseDiePos + 0xd3);
    if (lpPad->a6 || lpPad->a7 || lpPad->b2 || lpPad->a4 || lpPad->a5 || lpPad->b3) {
        SND_Play2D(0x1388, 0x7f, 0);
        pMdlMngDie->Alpha = 0.3f;
        g_ChoiseDiePos++;
        if (g_ChoiseDiePos == 2) {
            g_ChoiseDiePos = 0;
        }
        while (pDieAnimeInfo[g_ChoiseDiePos].num == 0) {
            g_ChoiseDiePos++;
            if (g_ChoiseDiePos == 2) {
                g_ChoiseDiePos = 0;
            }
        }
        pMdlMngDie = MDL(g_ChoiseDiePos + 0xd3);
        pMdlMngDie->Alpha = 1.0f;
        v1 = g_ChoisePiecePos + pDieAnimeInfo[g_ChoiseDiePos].num;
        v1 = (u8)v1;
        if ((s32)v1 > 0x17) {
            v1 = 0x17 - (v1 - 0x17);
            v1 = (u8)v1;
        }
        MovePlace = v1;
        {
            struct PieceTbl *pc = &pTable[MovePlace];
            u32 n = pc->PieceNum;
            pMdlMngPieceMove->Pos[0] = pc->PiecePos[n][0];
            pMdlMngPieceMove->Pos[1] = pc->PiecePos[n][1];
            pMdlMngPieceMove->Pos[2] = pc->PiecePos[n][2];
        }
        pMdlMngPieceMove->bErase = 0;
    }
    if (lpPad->b6 && 1.0f == pMdlMngDie->Alpha) {
        off = g_ChoisePiecePos * 0x1a0;
        piece = (struct PieceTbl *)((u8 *)off + (u32)pTable);
        PieceID = piece->PieceNum;
        PieceID -= 1;
        PieceID = piece->PieceID[PieceID];
        ChangeAnimParam(MDL(PieceID + 0xa1), 0, 0.0f);
        MGPieceSelectAnimeExit(PieceID);
        MGPieceMoveAnimeFirstInit(g_ChoiseDiePos, PieceID);
        MGPieceMoveAnimeInit(PieceID);
        SetDieAnimeInfoNum(g_ChoiseDiePos, 0);
        GameSt[9] = 0x3a;
    } else if (lpPad->b5) {
        SND_Play2D(0x1389, 0x7f, 0);
        off = g_ChoisePiecePos * 0x1a0;
        piece = (struct PieceTbl *)((u8 *)off + (u32)pTable);
        PieceID = piece->PieceNum;
        PieceID -= 1;
        PieceID = piece->PieceID[PieceID];
        pMdlMngPiece = MDL(PieceID + 0xa1);
        {
            struct dw_2491335_fields *pd = MDL(g_ChoiseDiePos + 0xd3);
            pd->Alpha = 0.3f;
        }
        ChangeAnimParam(pMdlMngPiece, 0, 0.0f);
        pMdlMngPiece->Ang[0] = 0.0f;
        pMdlMngPiece->Ang[1] = -1.5704999f;
        pMdlMngPiece->Ang[2] = 0.0f;
        GameSt[9] = 0x38;
        pMdlMngPieceMove->bErase = 1;
    }
}


/* Pad2PMode2PDiceThrowPlayer @ 0x1FADA0 .. 0x1FADF0 (0x50 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x1fadb4
 */




static void Pad2PMode2PDiceThrowPlayer(void) {
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    s0 = (u8 *)*(s32 *)((u8 *)&lpPadData + 4);
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        GameSt[9] = 0x3c;
        MGInitControl();
    }
    return;
}


void Pad2PMode2PChoisePiecePlayer(void) {
    u32 a2;
    u8 *s3;
    u8 *s0;
    u8 *s2;
    u32 padBits;
    u32 sfxParam;
    u32 a1;
    u32 a0;
    u64 v1_64;
    u32 v1;
    u32 s1;
    u32 v0;
    u8 stackFrame_5E[2] __attribute__((aligned(2)));

    v0 = (u32)GetPieceTable();
    s0 = (u8 *)*(s32 *)((u8 *)&lpPadData + 4);
    s3 = (u8 *)v0;
    GetPieceAnimeInfo();
    v0 = (u32)GetDieAnimeInfo();
    s2 = (u8 *)v0;
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_5E[0]));
    padBits = *(u8 *)(s0 + 0x20);
    v1_64 = (u64)padBits << 0x39 >> 0x3f;
    if (v1_64 == 0) {
        v1_64 = (u64)padBits << 0x38;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 == 0) {
            a0 = *(u8 *)(s0 + 0x21);
            v1_64 = (u64)a0 << 0x3d >> 0x3f;
            if (v1_64 == 0) {
                goto _L001FAB30;
            }
        }
    }
    a0 = 0x1388;
    sfxParam = 0x7f;
    SND_Play2D(a0, sfxParam, 0);
    v1 = g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)((u8 *)v0 + (u32)(s3));
    v0 = *(u8 *)v1;
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeExit(a0);
    v1 = g_ChoisePiecePos;
    v0 = 0xb;
    v1 = v1 + 1;
    g_ChoisePiecePos = v1;
    v1 = g_ChoisePiecePos;
    if (v1 == v0) {
        g_ChoisePiecePos = 0;
        goto _L001FAAF0;
        _L001FAAD0:;
        v1 = *(volatile u8 *)&g_ChoisePiecePos;
        v0 = 0xb;
        v1 = v1 + 1;
        g_ChoisePiecePos = v1;
        v1 = g_ChoisePiecePos;
        if (v1 == v0) {
            g_ChoisePiecePos = 0;
        }
    }
    _L001FAAF0:;
    v1 = g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)(s3 + v0);
    v0 = *(u8 *)v1;
    if (v0 == 0) {
        goto _L001FAAD0;
    }
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeInit(a0);
    goto _L001FAC20;
    _L001FAB30:;
    v1_64 = (u64)padBits << 0x3b >> 0x3f;
    if (v1_64 == 0) {
        v1_64 = (u64)padBits << 0x3a;
        v1_64 = v1_64 >> 0x3f;
        if (v1_64 == 0) {
            v1_64 = (u64)a0 << 0x3c >> 0x3f;
            if (v1_64 == 0) {
                goto _L001FAC20;
            }
        }
    }
    a0 = 0x1388;
    sfxParam = 0x7f;
    SND_Play2D(a0, sfxParam, 0);
    v1 = g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)((u8 *)v0 + (u32)(s3));
    v0 = *(u8 *)v1;
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeExit(a0);
    v1 = g_ChoisePiecePos;
    v0 = 0xff;
    v1 = v1 + -1;
    g_ChoisePiecePos = v1;
    v1 = g_ChoisePiecePos;
    if (v1 == v0) {
        v0 = 0xa;
        g_ChoisePiecePos = v0;
        goto _L001FABE8;
        _L001FABC8:;
        v1 = *(volatile u8 *)&g_ChoisePiecePos;
        v0 = 0xff;
        v1 = v1 + -1;
        g_ChoisePiecePos = v1;
        v1 = g_ChoisePiecePos;
        if (v1 == v0) {
            v0 = 0xa;
            g_ChoisePiecePos = v0;
        }
    }
    _L001FABE8:;
    v1 = g_ChoisePiecePos;
    v0 = v1 * 0x1a0;
    v1 = (s32)(s3 + v0);
    v0 = *(u8 *)v1;
    if (v0 == 0) {
        goto _L001FABC8;
    }
    v0 = v0 + -1;
    v0 = v0 + v1;
    a0 = *(u8 *)((v0 + 1));
    MGPieceSelectAnimeInit(a0);
    _L001FAC20:;
    v1 = *(u8 *)(s0 + 0x21);
    v1_64 = (u64)v1 << 0x39 >> 0x3f;
    if (v1_64 != 0) {
        v0 = (u32)GetDieAnimeInfo();
        s1 = v0;
        a0 = 0x138d;
        sfxParam = 0x7f;
        s0 = (u8 *)(MdlMng + 0x5400);
        SND_Play2D(a0, sfxParam, 0);
        {
            u32 modelScale;
            u8 *modelAddress;
            u8 *dieInfo;
            u8 diePos;
            u32 dieOffset;
        modelScale = 0x3f800000;
        a0 = g_ChoisePiecePos;
        v0 = (u32)MdlMng;
        v1 = a0 * 0x1a0;
        a0 = (s32)((u8 *)v1 + (u32)(s3));
        v1 = *(u8 *)a0;
        v1 = v1 + -1;
        v1 = v1 + a0;
        v1 = *(u8 *)((v1 + 1));
        a0 = v1 + 0xa1;
        v1 = a0 * 0x1c0;
        ChangeAnimParam((void *)((u8 *)MdlMng + v1), 1, 0.0f);
        v1 = 0x3e;
        GameSt[9] = v1;
        v1 = *(u8 *)(s2 + 0x35);
        if ((s32)v1 > 0) {
            *(u8 *)&g_ChoiseDiePos = 0;
        } else {
            v1 = 1;
            *(u8 *)&g_ChoiseDiePos = v1;
        }
        diePos = *(u8 *)&g_ChoiseDiePos;
        dieOffset = diePos * 0x50;
        dieInfo = (u8 *)(dieOffset + s1);
        modelAddress = (u8 *)MdlMng + (diePos + 0xd3) * 0x1c0;
        *(u32 *)(modelAddress + 0x10c) = modelScale;
        a0 = *(volatile u8 *)(dieInfo + 0x35);
        v1 = g_ChoisePiecePos;
        v1 += a0;
        v1 = (u8)v1;
        }
        a0 = 0xb;
        if ((s32)v1 > (s32)0xb) {
            v1 = v1 + -0xb;
            v1 = a0 - v1;
            v1 = (u8)v1;
        }
        a0 = (u8)v1;
        v1 = a0 * 0x1a0;
        a0 = (s32)(s3 + v1);
        v1 = *(u8 *)a0;
        v1 = v1 << 4;
        v1 = v1 + a0;
        *(f32 *)(s0 + 0x20) = *(float *)((v1 + 0x20));
        *(f32 *)(s0 + 0x24) = *(float *)((v1 + 0x24));
        *(f32 *)(s0 + 0x28) = *(float *)((v1 + 0x28));
        *(u8 *)(s0 + 2) = 0;
    }
    return;
}
void Pad2PMode2PChoiseDiePlayer(void) {
    struct PadBits *lpPad;
    unsigned short Stick;
    unsigned int PieceID;
    struct PieceTbl *pTable;
    struct dw_2491335_fields *pMdlMngPiece;
    struct dw_2491335_fields *pMdlMngDie;
    struct DieInfo *pDieAnimeInfo;
    struct dw_2491335_fields *pMdlMngPieceMove;
    u8 MovePlace;
    u32 v1;
    u32 off;
    struct PieceTbl *piece;

    lpPad = (struct PadBits *)*(u32 *)((u8 *)&lpPadData + 4);
    pTable = (struct PieceTbl *)GetPieceTable();
    pDieAnimeInfo = (struct DieInfo *)GetDieAnimeInfo();
    GetPieceAnimeInfo();
    pMdlMngPieceMove = (struct dw_2491335_fields *)(MdlMng + 0x5400);
    GetAnalogPad(lpPad, &Stick);
    pMdlMngDie = MDL(g_ChoiseDiePos + 0xd3);
    if (lpPad->a6 || lpPad->a7 || lpPad->b2 || lpPad->a4 || lpPad->a5 || lpPad->b3) {
        SND_Play2D(0x1388, 0x7f, 0);
        pMdlMngDie->Alpha = 0.3f;
        g_ChoiseDiePos++;
        if (g_ChoiseDiePos == 2) {
            g_ChoiseDiePos = 0;
        }
        while (pDieAnimeInfo[g_ChoiseDiePos].num == 0) {
            g_ChoiseDiePos++;
            if (g_ChoiseDiePos == 2) {
                g_ChoiseDiePos = 0;
            }
        }
        pMdlMngDie = MDL(g_ChoiseDiePos + 0xd3);
        pMdlMngDie->Alpha = 1.0f;
        v1 = g_ChoisePiecePos + pDieAnimeInfo[g_ChoiseDiePos].num;
        v1 = (u8)v1;
        if ((s32)v1 > 0xb) {
            v1 = 0xb - (v1 - 0xb);
            v1 = (u8)v1;
        }
        MovePlace = v1;
        {
            struct PieceTbl *pc = &pTable[MovePlace];
            u32 n = pc->PieceNum;
            pMdlMngPieceMove->Pos[0] = pc->PiecePos[n][0];
            pMdlMngPieceMove->Pos[1] = pc->PiecePos[n][1];
            pMdlMngPieceMove->Pos[2] = pc->PiecePos[n][2];
        }
        pMdlMngPieceMove->bErase = 0;
    }
    if (lpPad->b6 && 1.0f == pMdlMngDie->Alpha) {
        off = g_ChoisePiecePos * 0x1a0;
        piece = (struct PieceTbl *)((u8 *)off + (u32)pTable);
        PieceID = piece->PieceNum;
        PieceID -= 1;
        PieceID = piece->PieceID[PieceID];
        ChangeAnimParam(MDL(PieceID + 0xa1), 0, 0.0f);
        MGPieceSelectAnimeExit(PieceID);
        MGPieceMoveAnimeFirstInit(g_ChoiseDiePos, PieceID);
        MGPieceMoveAnimeInit(PieceID);
        SetDieAnimeInfoNum(g_ChoiseDiePos, 0);
        GameSt[9] = 0x3f;
    } else if (lpPad->b5) {
        SND_Play2D(0x1389, 0x7f, 0);
        off = g_ChoisePiecePos * 0x1a0;
        piece = (struct PieceTbl *)((u8 *)off + (u32)pTable);
        PieceID = piece->PieceNum;
        PieceID -= 1;
        PieceID = piece->PieceID[PieceID];
        pMdlMngPiece = MDL(PieceID + 0xa1);
        {
            struct dw_2491335_fields *pd = MDL(g_ChoiseDiePos + 0xd3);
            pd->Alpha = 0.3f;
        }
        ChangeAnimParam(pMdlMngPiece, 0, 0.0f);
        pMdlMngPiece->Ang[0] = 0.0f;
        pMdlMngPiece->Ang[1] = -1.5704999f;
        pMdlMngPiece->Ang[2] = 0.0f;
        GameSt[9] = 0x3d;
        pMdlMngPieceMove->bErase = 1;
    }
}

static void Pad2PModeViewResultAnime1(void) {
    u32 v1;

    v1 = g_TimerFrameNum;
    v1 = v1 + -1;
    g_TimerFrameNum = v1;
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        *(u8 *)((u8 *)&GameSt + 9) = 0x41;
        MGInitControl();
    }
    return;
}

/* Pad2PModeViewResultAnime2 @ 0x1FA570 .. 0x1FA624 (0xb4 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   cfg: loop body is not one contiguous region: .L001FA5A0
 */




static void Pad2PModeViewResultAnime2(void) {
    extern u32 GetSpriteDraw(void);
    u8 *t0;
    s32 a3;
    s32 a2;
    s32 a1;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    t0 = v0;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(t0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(t0 + 0x4c) > 0) {
                *(u32 *)(t0 + 0x4c) += -1;
            }
        } else if (v1 == (u32)a1) {
            v1 = *(s32 *)(t0 + 0x3c);
            if ((s32)*(s32 *)(t0 + 0x4c) < (s32)v1) {
                *(u32 *)(t0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        t0 = (u8 *)(t0 + 0x70);
    } while (v1 != 0);
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)0x42;
        MGInitControl();
    }
    return;
}

/* Pad2PModeViewResultAnime3 @ 0x1FA4B0 .. 0x1FA564 (0xb4 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   cfg: loop body is not one contiguous region: .L001FA4E0
 */




static void Pad2PModeViewResultAnime3(void) {
    extern u32 GetSpriteDraw(void);
    u8 *t0;
    s32 a3;
    s32 a2;
    s32 a1;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    t0 = v0;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(t0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(t0 + 0x4c) > 0) {
                *(u32 *)(t0 + 0x4c) += -1;
            }
        } else if (v1 == (u32)a1) {
            v1 = *(s32 *)(t0 + 0x3c);
            if ((s32)*(s32 *)(t0 + 0x4c) < (s32)v1) {
                *(u32 *)(t0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        t0 = (u8 *)(t0 + 0x70);
    } while (v1 != 0);
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)0x43;
        MGInitControl();
    }
    return;
}

static void Pad2PModeViewResult(void) {
    u32 *v0;
    u8 v1;
    u8 *s0;
    u32 a0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = &lpPadData;
    v1 = GameSt[0xa];
    s0 = (u8 *)*(s32 *)(u32 *)((u8 *)&lpPadData + (u32)((u32)v1 << 2));
    GetAnalogPad((void *)(u32)(s32)s0, (unsigned short *)(u32)((u8 *)&stackFrame_2E[0]));
    a0 = 0x138d;
    if ((u32)((struct { unsigned char _pad:4; unsigned char f:1; } *)&*(u8 *)(s0 + 0x20))->f != 0) {
        SND_Play2D(a0, 0x7f, 0);
        a0 = g_MenuPos;
        g_MenuPos = a0 + -1;
        a0 = g_MenuPos;
        if (a0 == (u32)0xff) {
            g_MenuPos = 1;
        }
    }
    a0 = 0x138d;
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x20))->f != 0) {
        SND_Play2D(a0, 0x7f, 0);
        a0 = g_MenuPos;
        g_MenuPos = a0 + 1;
        a0 = g_MenuPos;
        if (a0 == (u32)2) {
            g_MenuPos = 0;
        }
    }
    if ((u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 + 0x21))->f != 0) {
        a0 = g_MenuPos;
        if (a0 == 0) {
            GameSt[9] = (s32)(u32 *)(s32)0x2e;
            MGInitControl();
        } else if (a0 == (u32)1) {
            GameSt[9] = (s32)(u32 *)(s32)0x44;
            MGInitControl();
        }
    }
    return;
}

/* PadGoTitleFade @ 0x1FA2E0 .. 0x1FA384 (0xa4 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   delay: addiu at 0x1fa370 writes a register its branch at 0x1fa36c reads
 *   cfg: loop body is not one contiguous region: .L001FA310
 */




static void PadGoTitleFade(void) {
    extern u32 GetSpriteDraw(void);
    u8 *t0;
    s32 a3;
    s32 a2;
    s32 a1;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    t0 = v0;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(t0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(t0 + 0x4c) > 0) {
                *(u32 *)(t0 + 0x4c) += -1;
            }
        } else if (v1 == (u32)a1) {
            v1 = *(s32 *)(t0 + 0x3c);
            if ((s32)*(s32 *)(t0 + 0x4c) < (s32)v1) {
                *(u32 *)(t0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        t0 = (u8 *)(t0 + 0x70);
    } while (v1 != 0);
    v1 = g_TimerFrameNum;
    if (!(s32)((s32)v1 > 0)) {
        g_LoopOutFlag = 1;
    }
    return;
}

/* PadTMKMenuFromTopMenuFadeTimer @ 0x1FA210 .. 0x1FA2E0 (0xd0 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x2e escapes at 0x1fa2ac
 *   cfg: loop body is not one contiguous region: .L001FA250
 */








static void PadTMKMenuFromTopMenuFadeTimer(void) {
    extern u32 GetSpriteDraw(void);
    s32 a3;
    s32 a2;
    u32 s0;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u8 *)&lpPadData;
    v1 = GameSt[0xa];
    s0 = *(s32 *)(u8 *)((u8 *)&lpPadData + (u32)(v1 << 2));
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)2;
        MGInitControl();
    }
    return;
}

/* PadSGHMenuFromTopMenuFadeTimer @ 0x1FA140 .. 0x1FA210 (0xd0 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x2e escapes at 0x1fa1dc
 *   cfg: loop body is not one contiguous region: .L001FA180
 */








static void PadSGHMenuFromTopMenuFadeTimer(void) {
    extern u32 GetSpriteDraw(void);
    s32 a3;
    s32 a2;
    u32 s0;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u8 *)&lpPadData;
    v1 = GameSt[0xa];
    s0 = *(s32 *)(u8 *)((u8 *)&lpPadData + (u32)(v1 << 2));
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)5;
        MGInitControl();
    }
    return;
}

/* PadTopMenuFromTMKMenuFadeTimer @ 0x1FA070 .. 0x1FA138 (0xc8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x2e escapes at 0x1fa10c
 *   cfg: loop body is not one contiguous region: .L001FA0B0
 */








static void PadTopMenuFromTMKMenuFadeTimer(void) {
    extern u32 GetSpriteDraw(void);
    s32 a3;
    s32 a2;
    u32 s0;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u8 *)&lpPadData;
    v1 = GameSt[0xa];
    s0 = *(s32 *)(u8 *)((u8 *)&lpPadData + (u32)(v1 << 2));
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = 0;
        MGInitControl();
    }
    return;
}

/* PadTopMenuFromSGHMenuFadeTimer @ 0x1F9FA0 .. 0x1FA068 (0xc8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x2e escapes at 0x1fa03c
 *   cfg: loop body is not one contiguous region: .L001F9FE0
 */








static void PadTopMenuFromSGHMenuFadeTimer(void) {
    extern u32 GetSpriteDraw(void);
    s32 a3;
    s32 a2;
    u32 s0;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u8 *)&lpPadData;
    v1 = GameSt[0xa];
    s0 = *(s32 *)(u8 *)((u8 *)&lpPadData + (u32)(v1 << 2));
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = 0;
        MGInitControl();
    }
    return;
}

/* PadGoSGHJitsugiFade @ 0x1F9ED0 .. 0x1F9FA0 (0xd0 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x2e escapes at 0x1f9f6c
 *   cfg: loop body is not one contiguous region: .L001F9F10
 */








static void PadGoSGHJitsugiFade(void) {
    extern u32 GetSpriteDraw(void);
    s32 a3;
    s32 a2;
    u32 s0;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u8 *)&lpPadData;
    v1 = GameSt[0xa];
    s0 = *(s32 *)(u8 *)((u8 *)&lpPadData + (u32)(v1 << 2));
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)0x49;
        MGInitControl();
    }
    return;
}

/* PadGoSGHShigiFade @ 0x1F9E00 .. 0x1F9ED0 (0xd0 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x2e escapes at 0x1f9e9c
 *   cfg: loop body is not one contiguous region: .L001F9E40
 */








static void PadGoSGHShigiFade(void) {
    extern u32 GetSpriteDraw(void);
    s32 a3;
    s32 a2;
    u32 s0;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u8 *)&lpPadData;
    v1 = GameSt[0xa];
    s0 = *(s32 *)(u8 *)((u8 *)&lpPadData + (u32)(v1 << 2));
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)0x4b;
        MGInitControl();
    }
    return;
}

/* PadGoSGHTaisenFade @ 0x1F9D30 .. 0x1F9E00 (0xd0 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   call: GetSpriteDraw is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x2e escapes at 0x1f9dcc
 *   cfg: loop body is not one contiguous region: .L001F9D70
 */








static void PadGoSGHTaisenFade(void) {
    extern u32 GetSpriteDraw(void);
    s32 a3;
    s32 a2;
    u32 s0;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u8 *)&lpPadData;
    v1 = GameSt[0xa];
    s0 = *(s32 *)(u8 *)((u8 *)&lpPadData + (u32)(v1 << 2));
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)0x4a;
        MGInitControl();
    }
    return;
}

static void PadGoSGHMenuFade(void) {
    extern u32 GetSpriteDraw(void);
    s32 a3;
    s32 a2;
    u32 s0;
    u32 a1;
    u32 v1;
    u8 *v0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    v0 = (u8 *)&lpPadData;
    v1 = GameSt[0xa];
    s0 = *(s32 *)(u8 *)((u8 *)&lpPadData + (u32)(v1 << 2));
    v0 = (u8 *)GetSpriteDraw();
    v1 = g_TimerFrameNum;
    a3 = 0;
    g_TimerFrameNum = v1 + -1;
    a1 = 2;
    a2 = 3;
    do {
        v1 = *(u8 *)(v0 + 2);
        if (v1 == (u32)a2) {
            if ((s32)*(s32 *)(v0 + 0x4c) > 0) {
                *(u32 *)(v0 + 0x4c) += -1;
            }
        } else if (v1 == a1) {
            v1 = *(s32 *)(v0 + 0x3c);
            if ((s32)*(s32 *)(v0 + 0x4c) < (s32)v1) {
                *(u32 *)(v0 + 0x4c) += 1;
            }
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)0x6c;
        v0 = (u8 *)(v0 + 0x70);
    } while (v1 != 0);
    GetAnalogPad((void *)s0, (unsigned short *)((u8 *)&stackFrame_2E[0]));
    v1 = g_TimerFrameNum;
    if ((s32)v1 <= 0) {
        GameSt[9] = (s32)(u8 *)(s32)5;
        MGInitTopMenu();
        MGInitControl();
    }
    return;
}
