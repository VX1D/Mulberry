#include "common.h"
static void SetScreenPointLight(signed int, void *);
extern u8 TitleMng[];
extern u8 GameSt[];
extern u16 TexPosInfo[];
extern void KnMenuWindMng_Update(void);
extern void CsMngUpdate(void);
extern void CsMngDraw(void);
extern void PlayMi3(void *);
extern void DrawModel(void *);
extern u8 MdlMng[];
extern void CsMngRtaSetMat();
extern signed int CsMngStabilize(unsigned int, unsigned int);
extern u32 g_UnitMat[];
extern void ReadMdlBndFile(char *, signed int, void *);
extern void FileReadControl(signed int);
extern unsigned int SetMdlMng(void *, void *);
extern void SetCameraFov(float);
extern void DrawCalcView();
extern void InitPointLight();
extern void SetPointLightOn(signed int, float *, float);
extern void SetAmbientColor(float *);
extern u32 MdlData[];
extern u32 lpDrawMng;
extern void FreeTexList(void *);
extern void MemFree(void *);
extern void KnMenuMng_ReMakeMenu(s32);
extern u32 lpTitleTexList[];
static void SetPointLight(signed int a0 /* r4 */);
static u32 DrawTitleModel(void);
static void SetCharaPos(signed int a0 /* r4 */);
static void LoadTitleModel(void);
void FreeTitleTexture(void);

/* LoadTitleTexture @ 0x18DC20 .. 0x18DD28 (0x108 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @4708 is the string 'tex/title_us.tex'
 *   literal: @4709 is the string 'tex/title%d.tex'
 *   literal: @4710 is the string 'tex/select_us.tex'
 *   stack: address of the slot at 0x20 escapes at 0x18dcc4
 *   stack: address of the slot at 0x20 escapes at 0x18dcdc
 */

extern void * memset(void *, int, unsigned int);
extern int rand();
extern void ReadTexList(char *, void **, signed int, signed int);
extern int sprintf(char *, const char *, ...);
extern signed int KnMenuMng_ReLoadMenu(int);
static s32 MemoryCardCheck;
static u8 MiniGameReturn;
static s8 BrightnessBK;













/* TitleLoop @ 0x18D760 .. 0x18DB6C (0x40c bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @4689 -> 0x254cb0
 *   stack: address of the slot at 0x30 escapes at 0x18d82c
 *   stack: address of the slot at 0x30 escapes at 0x18d860
 *   fpu: float literal 0x3dcccccd at 0x18d8c0
 *   fpu: mtc1 reinterprets v0 at 0x18d8cc
 *   indirect: jr v0 at 0x18d920 -> <v0>
 *   delay: addiu at 0x18d9d8 writes a register its branch at 0x18d9d4 reads
 *   cfg: kept goto: 0x18d848 -> .L0018DA88
 *   cfg: loop body is not one contiguous region: .L0018D998
 *   cfg: loop test does not fall through into its body: 0x18da88
 *   cfg: kept branch: 0x18da88 if (..) goto .L0018D8E8
 *   cfg: loop body is not one contiguous region: .L0018DAE0
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void ReadMyMdl();
extern void InitFadeControl();
extern void SetPadDefaultRepeat();
extern void SetGlareFilter(signed int);
extern signed int KnMenuMng_CallMenu(int, unsigned char *, int);
extern void SetFadeMng(unsigned char, signed int *, signed int, void *, void *, signed int, signed
    int);
extern void KickMdlPacket();
extern void PadUpdate();
extern void FreeMdlMng(void *);
extern void FreeMdlData(void *, signed int);
extern void TitleControl();
extern void DrawBilinerFilter();
extern void DrawGlareFilter();
extern void TitleDraw();
extern void DrawBrightnessFilter();
extern void UpdateFadeMng();
extern void FileBackReadControl();
extern void SND_Update();
extern void DrawSynch();
extern signed int SetKuonMovie(signed int);
extern void MyFree();
extern void ResetMdlPacketMem();
extern u32 L4689[];












extern u32 CheckFadeEnd();
extern int FileCheckAsyncBusy(void);
extern signed int SND_Play2D(signed int, signed short, signed short);
extern void Menu_SetLoadSlotOffsetReset();
extern signed int SetVagStmFade(unsigned char, unsigned char, signed int);
extern signed int KnMenuMng_Update(signed int);
extern u32 Menu_IsLoaded();
extern void StopVagStm(unsigned char);
void UpdateChapterCursor(void);
extern void SetSceneLoad(unsigned short, unsigned short);
extern void fspad_PadSetRepeat(signed int, signed int, unsigned short, unsigned short, unsigned
    short);
extern void PlayBgmVagStm(signed int, signed int);
extern signed int CheckVagStmState(unsigned char);
extern signed int MemoryCardStart(unsigned char, unsigned char, unsigned char);
extern u32 MemoryCardProc();
extern u32 ExistKuonData();
void CheckMCResult(void);
extern struct SaveSysT *GetSaveSystem();
extern u32 lpPadData;
static s32 BrightnessSet;
extern u32 L4523[];

struct TitleMngT { unsigned char State; unsigned char NextState; short Counter; unsigned char TitleNo; unsigned char BGMStart; unsigned char Select; unsigned char Port; unsigned char MaxChapter; unsigned char MaxLevel[3]; unsigned char MaxEquip; unsigned char MaxPenance; unsigned char SelectMode; unsigned char MoviePlay; unsigned char Flicker; unsigned char LogoAlpha; unsigned char StartAlpha; unsigned char SelectFlag; float SelectRate; float SelectAlpha; float ChapterScale[3]; unsigned char ChapterAlpha[3]; unsigned char ChapterShadow[3]; unsigned char ChapterLight[3]; unsigned char MaruAlpha; unsigned char LoadModel; unsigned char YesNo; unsigned char MsgNo; unsigned char unused[3]; float WinkRate; };
struct GameStT { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };

struct SaveSysT { unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char Sugoroku; };
/*macros_inc*/
#define TM_State TitleMng[0x0]
#define TM_NextState TitleMng[0x1]
#define TM_Counter (*(s16 *)(TitleMng + 0x2))
#define TM_TitleNo TitleMng[0x4]
#define TM_BGMStart TitleMng[0x5]
#define TM_Select TitleMng[0x6]
#define TM_Port TitleMng[0x7]
#define TM_MaxChapter TitleMng[0x8]
#define TM_MaxEquip TitleMng[0xc]
#define TM_MaxPenance TitleMng[0xd]
#define TM_SelectMode TitleMng[0xe]
#define TM_MoviePlay TitleMng[0xf]
#define TM_Flicker TitleMng[0x10]
#define TM_LogoAlpha TitleMng[0x11]
#define TM_StartAlpha TitleMng[0x12]
#define TM_SelectFlag TitleMng[0x13]
#define TM_SelectRate (*(float *)(TitleMng + 0x14))
#define TM_SelectAlpha (*(float *)(TitleMng + 0x18))
#define TM_MaruAlpha TitleMng[0x31]
#define TM_LoadModel TitleMng[0x32]
#define TM_YesNo TitleMng[0x33]
#define TM_MsgNo TitleMng[0x34]
#define TM_WinkRate (*(float *)(TitleMng + 0x38))
#define TM_MaxLevel(i) TitleMng[0x9 + (i)]
#define TM_ChapterScale(i) (*(float *)(TitleMng + 0x1c + (i) * 4))
#define TM_ChapterAlpha(i) TitleMng[0x28 + (i)]
#define TM_ChapterShadow(i) TitleMng[0x2b + (i)]
#define TM_ChapterLight(i) TitleMng[0x2e + (i)]
#define GS_GameMode GameSt[0x5]
#define GS_PlayerId GameSt[0x14]
#define GS_GameLevel GameSt[0x18]
#define GS_StartEquip GameSt[0x19]
#define GS_PenanceMode GameSt[0x1a]
#define GS_Brightness (*(s8 *)(GameSt + 0x1e))
#define GS_Sugoroku GameSt[0x22]
#define GS_ExtraClear GameSt[0x2b]
#define GS_ClearCount(i) GameSt[0x28 + (i)]
#define TM ((struct TitleMngT *)TitleMng)
#define GS ((struct GameStT *)GameSt)
#define PADEDGE union { struct { unsigned short select:1, L3:1, R3:1, start:1, Lup:1, Lright:1, Ldown:1, Lleft:1, L2:1, R2:1, L1:1, R1:1, Rup:1, Rdown:1, Rright:1, Rleft:1; } bit; unsigned short set; }
typedef struct { unsigned char success; unsigned char data_len; PADEDGE button; unsigned char r3h, r3v, l3h, l3v; unsigned char apress[12]; unsigned char press[12]; PADEDGE edge; PADEDGE repeat; } PADD;
#define PADP (((PADD **)&lpPadData)[GameSt[0xa]])
static inline int PadOn(PADD *p, int m) {
    return (p->edge.set & m) ? 1 : 0;
}
#define PADON(m) PadOn(PADP, m)
#define PADONL(m) PadOn(lpPad, m)
#define FADE(d, f) { u8 fade[16] __attribute__((aligned(16))) = {0}; SetFadeMng(d, (signed int *)fade, f, (void *)0, (void *)0, 0, 0); }
















/* CheckMCResult @ 0x18ABE0 .. 0x18AE14 (0x234 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x40 escapes at 0x18ac60
 *   stack: address of the slot at 0x40 escapes at 0x18ac94
 *   delay: addiu at 0x18acc0 writes a register its branch at 0x18acbc reads
 *   delay: addiu at 0x18acd4 writes a register its branch at 0x18acd0 reads
 *   delay: andi at 0x18ad14 writes a register its branch at 0x18ad10 reads
 *   stack: address of the slot at 0x30 escapes at 0x18ad2c
 *   stack: address of the slot at 0x30 escapes at 0x18ad60
 *   delay: addiu at 0x18ad80 writes a register its branch at 0x18ad7c reads
 *   cfg: loop body is not one contiguous region: .L0018ACB0
 */

extern signed int GetMemoryCardMessage(unsigned char);
extern void SetFadeMng(unsigned char, signed int *, signed int, void *, void *, signed int, signed
    int);



#include "Tex.h"

/* DWARF dw_1206667: ver@0x10 col@0x50 uv@0x90 tex0@0xd0 tex1@0xd8 test@0xe0 size 0xf0 */
typedef struct {
    u_short bUse : 1;
    u_short Fst : 1;
    u_short Alpha : 2;
    u_short LoadOff : 1;
    u_short unused : 11;
    u_short texID;
    u_char pad0[12];
    int ver[4][4];
    int col[4][4];
    union {
        int uv[4][4];
        float st[4][4];
    };
    u_char tex0[8];
    u_char tex1[8];
    u_char test[8];
    u_char pad1[8];
} SPD;

extern void SetSprite(SPD *lpSp, int PosX, int PosY, int w, int h, int *col,
                      u_short texID, u_char Fst);
extern u_int *MakeSpritePacketUseSpr(SPD *lpSp, u_int *lpPacket);
extern u_int *MakeStripPacketUseSpr(SPD *lpSp, u_int *lpPacket);

typedef struct {
    short x;
    short y;
    short w;
    short h;
    short u;
    short v;
    u_char Mode;
    u_char unused[3];
} TEXPOS;

static u16 TexPosInfo[0x3b8] = {
    0x40, 0xffe0, 0x200, 0x200, 0, 0, 0, 0, 0, 0xc0, 0x280, 0x40, 0, 0, 0, 0, 0xc0, 0x60, 0x100,
    0x100, 0, 0, 0, 0, 0, 0, 0x280, 0x1c0, 0, 0, 0, 0, 0x1c9, 0x10c, 0x40, 0x40, 0x280, 0, 0, 0,
    0x131, 0x107, 0x80, 0x80, 0x280, 0, 0, 0, 0x109, 0xe0, 0x67, 0x60, 0x280, 0, 0, 0, 0x1b,
    0x25, 0xa9, 0x16b, 0, 0, 0, 0, 0x28, 0x26, 0xa9, 0x16b, 0, 0, 0, 0, 0x1b, 0x25, 0xa9, 0x16b,
    0, 0, 0, 0, 0x1c5, 0xb1, 0xa6, 0x32, 0, 0x16b, 0, 0, 0x1cb, 0x62, 0xa6, 0x32, 0, 0x16b, 0,
    0, 0x17b, 0xac, 0xa6, 0x32, 0, 0x16b, 0, 0, 0x21c, 0x8c, 0xba, 0x32, 0, 0x96, 0, 0, 0x199,
    0x87, 0xba, 0x32, 0, 0x32, 0, 0, 0x1e0, 0x77, 0xba, 0x32, 0, 0, 0, 0, 0x21c, 0x8c, 0xba,
    0x32, 0, 0x64, 0, 0, 0x7d, 0x18c, 0x191, 0x34, 0xc2, 0, 0x1e, 0, 0x8f, 0x18f, 0x162, 0x26,
    0, 0, 0, 0, 0x1c, 0xb, 0xb8, 0x4a, 0xb6, 0x48, 1, 0, 0x1c, 0x13, 0xc1, 0x4a, 0xb6, 0x3f, 1,
    0, 0xa, 0, 0xe8, 0x72, 0xb4, 0x6f, 0, 0, 0x6d, 0xaa, 0x94, 0x49, 0, 0x98, 0, 0, 0x6a, 0xa6,
    0x94, 0x51, 0, 0xa4, 0, 0, 0x6e, 0xaa, 0x94, 0x51, 0, 0xa4, 0, 0, 0x5c, 0x94, 0xb0, 0x6f,
    0xec, 0, 0, 0, 0x1a6, 0x93, 0x94, 0x50, 0, 0x48, 0, 0, 0x1a3, 0x90, 0x97, 0x56, 0, 0x4e, 0,
    0, 0x1a8, 0x96, 0x97, 0x56, 0, 0x4e, 0, 0, 0x197, 0x82, 0xb4, 0x72, 0, 0x6f, 0, 0, 0xdf,
    0x109, 0xc7, 0x48, 0, 0, 0, 0, 0xdd, 0x106, 0xb6, 0x4e, 0, 0, 0, 0, 0x192, 0x106, 0x17,
    0x3f, 0xb6, 0, 0, 0, 0xe2, 0x10b, 0xb6, 0x4e, 0, 0, 0, 0, 0x197, 0x10b, 0x17, 0x3f, 0xb6, 0,
    0, 0, 0xd1, 0xf6, 0xec, 0x6f, 0, 0, 0, 0, 0x8a, 0xf5, 0x58, 0x22, 0x94, 0x48, 1, 0, 0x87,
    0xf3, 0x5c, 0x22, 0x94, 0xa4, 1, 0, 0x8a, 0xfa, 0x5c, 0x22, 0x94, 0xa4, 1, 0, 0x71, 0xe5,
    0x82, 0x42, 0x19c, 0, 1, 0, 0x1c0, 0xe3, 0x58, 0x22, 0x94, 0x48, 1, 0, 0x1bd, 0xe1, 0x5c,
    0x22, 0x94, 0xa4, 1, 0, 0x1c0, 0xe8, 0x5c, 0x22, 0x94, 0xa4, 1, 0, 0x1a7, 0xd4, 0x82, 0x42,
    0x19c, 0, 1, 0, 0x117, 0x153, 0x58, 0x22, 0x94, 0x48, 1, 0, 0x115, 0x151, 0x5c, 0x22, 0x94,
    0xa4, 1, 0, 0x117, 0x158, 0x5c, 0x22, 0x94, 0xa4, 1, 0, 0xfe, 0x141, 0x82, 0x42, 0x19c, 0,
    1, 0, 0x2f, 0x4f, 0x97, 0x2b, 0, 0, 0, 0, 0x60, 0xeb, 0x6a, 0x2b, 0, 0x2a, 0, 0, 0x190,
    0xdc, 0x6a, 0x2b, 0, 0x55, 0, 0, 0xda, 0x14b, 0x67, 0x2b, 0x6a, 0x2a, 0, 0, 0x93, 0xeb,
    0x69, 0x2b, 0x97, 0, 0, 0, 0x1dc, 0xdc, 0x69, 0x2b, 0x97, 0, 0, 0, 0x12b, 0x14b, 0x69, 0x2b,
    0x97, 0, 0, 0, 0x77, 0x10a, 0x67, 0x2b, 0x6a, 0x55, 0, 0, 0x1b7, 0xfd, 0x67, 0x2b, 0x6a,
    0x55, 0, 0, 0x106, 0x16a, 0x67, 0x2b, 0x6a, 0x55, 0, 0, 0x28, 0x1c, 0x94, 0x49, 0, 0x98, 0,
    0, 0x29, 0x1c, 0x94, 0x51, 0, 0xa4, 0, 0, 0x17, 6, 0xb0, 0x6f, 0xec, 0, 0, 0, 0x28, 0x14,
    0x94, 0x50, 0, 0x48, 0, 0, 0x2b, 0x16, 0x97, 0x56, 0, 0x4e, 0, 0, 0x17, 3, 0xb4, 0x72, 0,
    0x6f, 0, 0, 0x21, 0x1a, 0xc7, 0x48, 0, 0, 0, 0, 0x21, 0x1c, 0xb6, 0x4e, 0, 0, 0, 0, 0xda,
    0x1c, 0x17, 0x3f, 0xb6, 0, 0, 0, 0x13, 7, 0xec, 0x6f, 0, 0, 0, 0, 0x45, 0x67, 0x58, 0x22,
    0x94, 0x48, 1, 0, 0x45, 0x6c, 0x5c, 0x22, 0x94, 0xa4, 1, 0, 0x2c, 0x57, 0x82, 0x42, 0x19c,
    0, 1, 0, 0x45, 0x66, 0x58, 0x22, 0x94, 0x48, 1, 0, 0x45, 0x69, 0x5c, 0x22, 0x94, 0xa4, 1, 0,
    0x30, 0x56, 0x82, 0x42, 0x19c, 0, 1, 0, 0x59, 0x64, 0x58, 0x22, 0x94, 0x48, 1, 0, 0x59,
    0x69, 0x5c, 0x22, 0x94, 0xa4, 1, 0, 0x40, 0x52, 0x82, 0x42, 0x19c, 0, 1, 0, 0x1b, 0x59,
    0x6a, 0x2b, 0, 0x2a, 0, 0, 0x16, 0x59, 0x6a, 0x2b, 0, 0x55, 0, 0, 0xf, 0x59, 0x67, 0x2b,
    0x6a, 0x2a, 0, 0, 0x4e, 0x59, 0x69, 0x2b, 0x97, 0, 0, 0, 0x62, 0x59, 0x69, 0x2b, 0x97, 0, 0,
    0, 0x60, 0x59, 0x69, 0x2b, 0x97, 0, 0, 0, 0x32, 0x75, 0x67, 0x2b, 0x6a, 0x55, 0, 0, 0x3d,
    0x77, 0x67, 0x2b, 0x6a, 0x55, 0, 0, 0x2a, 0x75, 0x67, 0x2b, 0x6a, 0x55, 0, 0, 0x13c, 0x8f,
    0x6e, 0x6d, 0, 0, 0xa, 0, 0x13c, 0xc1, 0x6e, 0x6d, 0, 0, 0xa, 0, 0x13c, 0xf3, 0x6e, 0x6d, 0,
    0, 0xa, 0, 0x13c, 0x11b, 0x6e, 0x6d, 0, 0, 0xa, 0, 0x136, 0xd6, 0x6e, 0x6d, 0, 0, 0xa, 0,
    0x136, 0x10c, 0x6e, 0x6d, 0, 0, 0xa, 0, 0, 0, 0x100, 0x20, 0, 0, 0, 0, 0x100, 0, 0x100,
    0x20, 0, 0, 0, 0, 0x200, 0, 0x80, 0x20, 0, 0, 0, 0, 0, 0x1a0, 0x100, 0x20, 0, 0, 3, 0,
    0x100, 0x1a0, 0x100, 0x20, 0, 0, 3, 0, 0x200, 0x1a0, 0x80, 0x20, 0, 0, 3, 0, 0x1e0, 0x186,
    0x1b, 0x1b, 0, 0, 0, 0, 0x226, 0x186, 0x1b, 0x1b, 0, 0, 0, 0, 0x1fe, 0x18a, 0x26, 0x13, 0,
    0x4d, 0, 0, 0x244, 0x18a, 0x26, 0x13, 0x98, 0x4d, 0, 0, 0x126, 0x7a, 0x80, 0x74, 0, 0, 0, 0,
    0x1a6, 0x7a, 0x80, 0x74, 0, 0, 2, 0, 0x126, 0xee, 0x80, 0x74, 0, 0, 3, 0, 0x1a6, 0xee, 0x80,
    0x74, 0, 0, 4, 0, 0x30, 0xfc, 0x6e, 0x6d, 0, 0, 0xa, 0, 0x30, 0x11a, 0x6e, 0x6d, 0, 0, 0xa,
    0, 0xd0, 0x110, 0x6e, 0x6d, 0, 0, 0xa, 0, 0xd0, 0x12e, 0x6e, 0x6d, 0, 0, 0xa, 0, 0, 0,
    0x200, 0x200, 0, 0, 0xb, 0, 0xc0, 0x14d, 0x101, 0x37, 0, 0, 0, 0, 0xdb, 0x168, 0xca, 1, 0xe,
    0x39, 0x14, 0, 0x13e, 0x164, 5, 0xb, 0, 0x39, 1, 0, 0x46, 0xae, 0x6e, 0x6d, 0, 0, 0xc, 0,
    0x1e0, 0x14, 0x1b, 0x1b, 0, 0, 0, 0, 0x226, 0x14, 0x1b, 0x1b, 0, 0, 0, 0, 0x1fe, 0x18, 0x26,
    0x13, 0, 0x4d, 0, 0, 0x244, 0x18, 0x26, 0x13, 0x98, 0x4d
};
static u32 TitleMessageInfo[0x82] = {
    0x95014b, 0x1d4c0, 0xa90162, 0x18772, 0xa9016a, 0x18773, 0xa90160, 0x18774, 0xa9016e,
    0x18775, 0xc70146, 0x1d4c1, 0xdb0184, 0x1d4c4, 0xdb018a, 0x1d4c5, 0xf90150, 0x1d4c2,
    0x10d0184, 0x1d4c4, 0x10d016a, 0x1d4c6, 0x10d016e, 0x1d4c7, 0x12b015d, 0x1d4c3, 0x940144,
    0x1d4c0, 0xa8015c, 0x18772, 0xa80164, 0x18773, 0xa8015a, 0x18774, 0xa80168, 0x18775,
    0xc6013c, 0x1d4c1, 0xda0182, 0x1d4c4, 0xda0188, 0x1d4c5, 0xf80146, 0x1d4c2, 0x10c0182,
    0x1d4c4, 0x10c0164, 0x1d4c6, 0x10c016a, 0x1d4c7, 0x12a0155, 0x1d4c3, 0xb9014b, 0x1d4c0,
    0xe60184, 0x18772, 0xe60184, 0x18773, 0xe60184, 0x18774, 0xe60184, 0x18775, 0x11c0156,
    0x1d4c3, 0xb8016e, 0x1d4c0, 0x11b0152, 0x1d4c3, 0x1860028, 0x1d4ca, 0x1860028, 0x1d4cb,
    0x1860028, 0x1d4cc, 0x1860028, 0x1d4cd, 0x1860028, 0x1d4ce, 0x1860028, 0x1d4cf, 0x1860028,
    0x1d4d0, 0x1860028, 0x1d4d1, 0x1860028, 0x1d4d2, 0x1860028, 0x1d4d3, 0x1860028, 0x1d4d4,
    0x1860028, 0x1d4d5, 0x1860028, 0x1d4d6, 0x18a00a5, 0x1d4c8, 0xc80078, 0x1d4c9, 0xc8005a,
    0x1d4e3, 0x780078, 0x1d4da, 0x780078, 0x1d4db, 0x780078, 0x1d4dc, 0x640078, 0x1d4dd,
    0x1220122, 0x1d4d8, 0x1400127, 0x1d4d9, 0x120011e, 0x1d4d8, 0x13e0125, 0x1d4d9, 0xaa0046,
    0x1d4d7, 0x10e007c, 0x1d4d8, 0x12c0081, 0x1d4d9, 0x10c0078, 0x1d4d8, 0x12a007f, 0x1d4d9,
    0x280190, 0x1d5f6, 0x280190, 0x1d5f7
};
static u32 CursorInfo[0x19] = {
    0x6001db, 0x2101b6, 0x5401e0, 0x3f4f5c29, 0, 0x7801ca, 0x3801b1, 0x7f01ba, 0x3f4f5c29, 0x40,
    0xa701b5, 0x6301b8, 0xaa01a0, 0x3f800000, 0x80, 0xdc01d0, 0x9501d8, 0xd50194, 0x3f4f5c29,
    0x40, 0xf701e4, 0xad01f1, 0x1000194, 0x3f4f5c29
};
static s32 MemoryCardCheck = 1;
typedef struct{u8 fc0,fc1,fc2,fc3;} FC;
extern void SetFontColor(FC);
/* TitleDraw @ 0x188420 .. 0x18A9D0 (0x25b0 bytes, frame 0x400) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @3556 -> 0x254b20
 *   literal: @3537 is the string 'agetec.tm2'
 *   literal: @3538 is the string 'opn_00.tm2'
 *   literal: @3539 is the string 'opn_04.tm2'
 *   literal: @3540 is the string 'fe_ti_000%d.tm2'
 *   literal: @3541 is the string 'fe_ti_0003.tm2'
 *   literal: @3542 is the string 'fe_ti_0008.tm2'
 *   literal: @3543 is the string 'fe_ti_0009.tm2'
 *   literal: @3544 is the string 'fe_me_0000.tm2'
 *   literal: @3545 is the string 'fe_ti_0005.tm2'
 *   literal: @3546 is the string 'fe_ti_0004.tm2'
 *   literal: @3547 is the string 'fe_ti_0006.tm2'
 *   literal: @3548 is the string 'rubi_ti_002.tm2'
 *   literal: @3549 is the string 'rubi_ti_001.tm2'
 *   literal: @3550 is the string 'rubi_ti_003.tm2'
 *   literal: @1978 -> 0x22c270
 *   literal: @3551 is the string 'fe_me_0019.tm2'
 *   literal: @3552 is the string 'fe_ti_0007.tm2'
 *   literal: @1783 -> 0x22c228
 *   literal: @1785 -> 0x22c238
 *   literal: @3553 is the string 'fe_ki_002.tm2'
 *   literal: @3554 is the string 'fe_ki_001.tm2'
 *   literal: @3555 is the string 'story00.tm2'
 *   literal: @1971 -> 0x22c260
 *   indirect: jr v0 at 0x1884fc -> <v0>
 *   fpu: float literal 0x3f800000 at 0x188534
 *   fpu: float literal 0x3f800000 at 0x188584
 *   fpu: float literal 0x3f800000 at 0x1885d4
 *   stack: address of the slot at 0x3a0 escapes at 0x188608
 *   fpu: float literal 0x3f800000 at 0x188640
 *   stack: address of the slot at 0x390 escapes at 0x1886a8
 *   delay: addiu at 0x1886c0 writes a register its branch at 0x1886bc reads
 *   fpu: float literal 0x00000000 at 0x1886e8
 *   fpu: float literal 0x3f800000 at 0x188708
 *   fpu: float literal 0x40a00000 at 0x18870c
 *   fpu: mtc1 reinterprets v0 at 0x188720
 *   fpu: float literal 0x00000000 at 0x188748
 *   fpu: float literal 0x3f800000 at 0x188768
 *   fpu: float literal 0x40c00000 at 0x18876c
 *   fpu: mtc1 reinterprets v0 at 0x188780
 *   fpu: float literal 0x00000000 at 0x1887a8
 *   fpu: float literal 0x40a00000 at 0x1887c8
 *   fpu: float literal 0x3f800000 at 0x1887d4
 *   fpu: mtc1 reinterprets v1 at 0x1887e4
 *   stack: address of the slot at 0x392 escapes at 0x188808
 *   fpu: float literal 0x3f800000 at 0x18880c
 *   fpu: float literal 0x3f800000 at 0x188834
 *   fpu: float literal 0x3f800000 at 0x18888c
 *   fpu: float literal 0x3f800000 at 0x1888c8
 *   fpu: float literal 0x40400000 at 0x1888fc
 *   fpu: float literal 0x3f800000 at 0x18894c
 *   fpu: float literal 0x3f99999a at 0x188a1c
 *   fpu: float literal 0x3f99999a at 0x188a44
 *   fpu: float literal 0x3f99999a at 0x188a6c
 *   fpu: float literal 0x3f99999a at 0x188a94
 *   fpu: float literal 0x3f99999a at 0x188abc
 *   fpu: float literal 0x3f99999a at 0x188ae4
 *   fpu: float literal 0x3f800000 at 0x188b2c
 *   delay: lui at 0x188b58 writes a register its branch at 0x188b54 reads
 *   delay: lui at 0x188bc4 writes a register its branch at 0x188bc0 reads
 *   delay: lui at 0x188c38 writes a register its branch at 0x188c34 reads
 *   fpu: float literal 0x3f800000 at 0x188d44
 *   delay: lui at 0x188dc4 writes a register its branch at 0x188dc0 reads
 *   fpu: float literal 0x3f800000 at 0x188e1c
 *   delay: lui at 0x188e9c writes a register its branch at 0x188e98 reads
 *   fpu: float literal 0x3f800000 at 0x188ef4
 *   fpu: float literal 0x3f800000 at 0x189054
 *   fpu: float literal 0x3f800000 at 0x189184
 *   fpu: float literal 0x3f4ccccd at 0x189298
 *   fpu: mov.s at 0x1892a0 is a float copy
 *   fpu: float literal 0x3f4ccccd at 0x1892bc
 *   fpu: mov.s at 0x1892c4 is a float copy
 *   delay: lui at 0x1892e8 writes a register its branch at 0x1892e4 reads
 *   stack: address of the slot at 0x2a0 escapes at 0x189314
 *   stack: address of the slot at 0x290 escapes at 0x189314
 *   fpu: float literal 0x3f99999a at 0x189364
 *   fpu: float literal 0x3f99999a at 0x18938c
 *   fpu: float literal 0x3f99999a at 0x1893b4
 *   fpu: float literal 0x3f99999a at 0x1893dc
 *   fpu: float literal 0x3f99999a at 0x189404
 *   fpu: float literal 0x3f99999a at 0x18942c
 *   fpu: float literal 0x3f800000 at 0x189494
 *   fpu: float literal 0x3f800000 at 0x1894fc
 *   fpu: float literal 0x3f800000 at 0x189544
 *   fpu: float literal 0x3f800000 at 0x189594
 *   fpu: float literal 0x3f800000 at 0x1895b8
 *   fpu: float literal 0x3f800000 at 0x1895dc
 *   fpu: float literal 0x3f800000 at 0x189600
 *   fpu: float literal 0x3f800000 at 0x18965c
 *   delay: lui at 0x189688 writes a register its branch at 0x189684 reads
 *   fpu: float literal 0x3f800000 at 0x189690
 *   fpu: float literal 0x3f800000 at 0x1896c8
 *   fpu: float literal 0x3f800000 at 0x1896e8
 *   fpu: float literal 0x3f800000 at 0x189744
 *   delay: lui at 0x189770 writes a register its branch at 0x18976c reads
 *   fpu: float literal 0x3f800000 at 0x189778
 *   delay: lui at 0x1897a8 writes a register its branch at 0x1897a4 reads
 *   fpu: float literal 0x3f800000 at 0x1897b0
 *   fpu: float literal 0x3f800000 at 0x18980c
 *   fpu: float literal 0x3f800000 at 0x189840
 *   delay: lui at 0x189868 writes a register its branch at 0x189864 reads
 *   fpu: float literal 0x3f800000 at 0x189870
 *   fpu: float literal 0x3f800000 at 0x1898cc
 *   fpu: float literal 0x3f800000 at 0x189904
 *   fpu: float literal 0x3f800000 at 0x189964
 *   fpu: float literal 0x3f800000 at 0x1899bc
 *   fpu: float literal 0x3f800000 at 0x1899f4
 *   fpu: float literal 0x3f800000 at 0x189a54
 *   fpu: float literal 0x3f800000 at 0x189aac
 *   fpu: float literal 0x3f800000 at 0x189ae4
 *   fpu: float literal 0x3f800000 at 0x189b44
 *   fpu: float literal 0x3f666666 at 0x189b70
 *   fpu: mov.s at 0x189b78 is a float copy
 *   delay: lui at 0x189ba4 writes a register its branch at 0x189ba0 reads
 *   fpu: float literal 0x3f800000 at 0x189ba8
 *   fpu: mov.s at 0x189bb0 is a float copy
 *   fpu: float literal 0x3f666666 at 0x189bd4
 *   fpu: mov.s at 0x189bdc is a float copy
 *   delay: lui at 0x189c10 writes a register its branch at 0x189c0c reads
 *   fpu: float literal 0x3f800000 at 0x189c14
 *   fpu: mov.s at 0x189c1c is a float copy
 *   fpu: float literal 0x3f666666 at 0x189c40
 *   fpu: mov.s at 0x189c48 is a float copy
 *   delay: lui at 0x189c80 writes a register its branch at 0x189c7c reads
 *   fpu: float literal 0x3f800000 at 0x189c84
 *   fpu: mov.s at 0x189c8c is a float copy
 *   fpu: float literal 0x3f666666 at 0x189cb0
 *   fpu: mov.s at 0x189cb8 is a float copy
 *   delay: lui at 0x189cf0 writes a register its branch at 0x189cec reads
 *   fpu: float literal 0x3f800000 at 0x189cf4
 *   fpu: mov.s at 0x189cfc is a float copy
 *   fpu: float literal 0x3f666666 at 0x189d10
 *   fpu: mov.s at 0x189d18 is a float copy
 *   literal: @1787 -> 0x257598
 *   literal: @1792 -> 0x2575a0
 *   stack: address of the slot at 0x3ff escapes at 0x189da8
 *   delay: sll at 0x189e1c writes a register its branch at 0x189e18 reads
 *   fpu: float literal 0x3f800000 at 0x189e7c
 *   fpu: mtc1 reinterprets a0 at 0x189e98
 *   fpu: mtc1 reinterprets v1 at 0x189ea4
 *   fpu: mtc1 reinterprets v1 at 0x189ed4
 *   fpu: mtc1 reinterprets v0 at 0x189ed8
 *   fpu: mtc1 reinterprets v0 at 0x189f0c
 *   fpu: mtc1 reinterprets v1 at 0x189f20
 *   fpu: mtc1 reinterprets v0 at 0x189f3c
 *   fpu: mtc1 reinterprets v1 at 0x189f54
 *   fpu: float literal 0x4f000000 at 0x189f70
 *   delay: addiu at 0x189fc4 writes a register its branch at 0x189fc0 reads
 *   fpu: float literal 0x3f800000 at 0x189fd4
 *   fpu: mov.s at 0x189fdc is a float copy
 *   fpu: float literal 0x3f666666 at 0x18a014
 *   fpu: mov.s at 0x18a01c is a float copy
 *   delay: lui at 0x18a078 writes a register its branch at 0x18a074 reads
 *   fpu: float literal 0x3f800000 at 0x18a07c
 *   fpu: mov.s at 0x18a084 is a float copy
 *   fpu: float literal 0x3f666666 at 0x18a098
 *   fpu: mov.s at 0x18a0a0 is a float copy
 *   delay: lui at 0x18a0c4 writes a register its branch at 0x18a0c0 reads
 *   fpu: float literal 0x3f4ccccd at 0x18a0cc
 *   fpu: mov.s at 0x18a0d4 is a float copy
 *   delay: addiu at 0x18a0e8 writes a register its branch at 0x18a0e4 reads
 *   fpu: float literal 0x3f5555c5 at 0x18a1a4
 *   fpu: mov.s at 0x18a1ac is a float copy
 *   delay: lui at 0x18a1c4 writes a register its branch at 0x18a1c0 reads
 *   fpu: float literal 0x3f800000 at 0x18a1c8
 *   fpu: mov.s at 0x18a1d0 is a float copy
 *   fpu: float literal 0x3f5555c5 at 0x18a1e4
 *   fpu: mov.s at 0x18a1ec is a float copy
 *   delay: lui at 0x18a210 writes a register its branch at 0x18a20c reads
 *   fpu: float literal 0x3f800000 at 0x18a214
 *   fpu: mov.s at 0x18a21c is a float copy
 *   fpu: float literal 0x3f5555c5 at 0x18a230
 *   fpu: mov.s at 0x18a238 is a float copy
 *   fpu: float literal 0x3f4ccccd at 0x18a260
 *   fpu: mov.s at 0x18a268 is a float copy
 *   stack: address of the slot at 0x3a0 escapes at 0x18a298
 *   fpu: float literal 0x3f800000 at 0x18a2c8
 *   stack: address of the slot at 0x3a0 escapes at 0x18a2f8
 *   fpu: float literal 0x3f800000 at 0x18a328
 *   fpu: float literal 0x43480000 at 0x18a35c
 *   fpu: mtc1 reinterprets v0 at 0x18a370
 *   delay: addiu at 0x18a3a0 writes a register its branch at 0x18a39c reads
 *   delay: addiu at 0x18a3b8 writes a register its branch at 0x18a3b4 reads
 *   fpu: float literal 0x3f800000 at 0x18a3ec
 *   fpu: float literal 0x3f400000 at 0x18a414
 *   fpu: mov.s at 0x18a41c is a float copy
 *   delay: lui at 0x18a438 writes a register its branch at 0x18a434 reads
 *   fpu: float literal 0x3f666666 at 0x18a440
 *   fpu: mov.s at 0x18a448 is a float copy
 *   literal: @1851 -> 0x2575a4
 *   fpu: float literal 0x3f4ccccd at 0x18a47c
 *   fpu: mov.s at 0x18a484 is a float copy
 *   stack: address of the slot at 0x1a0 escapes at 0x18a560
 *   stack: address of the slot at 0x190 escapes at 0x18a560
 *   literal: @1867 -> 0x2575a8
 *   fpu: float literal 0x3f4ccccd at 0x18a5a8
 *   fpu: mov.s at 0x18a5b0 is a float copy
 *   stack: address of the slot at 0x3f3 escapes at 0x18a5c0
 *   fpu: mtc1 reinterprets s1 at 0x18a5c4
 *   fpu: float literal 0x41c00000 at 0x18a5cc
 *   fpu: float literal 0x43960000 at 0x18a5d8
 *   fpu: mtc1 reinterprets v1 at 0x18a5f4
 *   fpu: mtc1 reinterprets v0 at 0x18a5f8
 *   fpu: float literal 0x42c80000 at 0x18a614
 *   fpu: float literal 0x438c0000 at 0x18a62c
 *   fpu: float literal 0x41a00000 at 0x18a650
 *   fpu: float literal 0x3f800000 at 0x18a654
 *   fpu: float literal 0x42fe0000 at 0x18a664
 *   fpu: float literal 0x4f000000 at 0x18a668
 *   fpu: float literal 0x42f00000 at 0x18a6bc
 *   fpu: float literal 0x42fe0000 at 0x18a6e0
 *   fpu: float literal 0x41a00000 at 0x18a6e4
 *   fpu: float literal 0x4f000000 at 0x18a6f8
 *   stack: address of the slot at 0x3f8 escapes at 0x18a774
 *   stack: address of the slot at 0x3f4 escapes at 0x18a774
 *   fpu: float literal 0x44000000 at 0x18a784
 *   fpu: float literal 0x3f000000 at 0x18a78c
 *   fpu: mov.s at 0x18a794 is a float copy
 *   fpu: float literal 0x3f5555c5 at 0x18a7e0
 *   fpu: mov.s at 0x18a7e8 is a float copy
 *   fpu: float literal 0x3f800000 at 0x18a84c
 *   fpu: float literal 0x3f5555c5 at 0x18a890
 *   fpu: mov.s at 0x18a898 is a float copy
 *   delay: lui at 0x18a8b4 writes a register its branch at 0x18a8b0 reads
 *   fpu: float literal 0x3f800000 at 0x18a8b8
 *   fpu: mov.s at 0x18a8c0 is a float copy
 *   fpu: float literal 0x3f5555c5 at 0x18a8d4
 *   fpu: mov.s at 0x18a8dc is a float copy
 *   delay: lui at 0x18a900 writes a register its branch at 0x18a8fc reads
 *   fpu: float literal 0x3f800000 at 0x18a904
 *   fpu: mov.s at 0x18a90c is a float copy
 *   fpu: float literal 0x3f5555c5 at 0x18a920
 *   fpu: mov.s at 0x18a928 is a float copy
 *   stack: address of the slot at 0xa0 escapes at 0x18a984
 *   stack: address of the slot at 0x90 escapes at 0x18a984
 *   literal: @1978 initializes the 16-byte local at 0x90
 *   literal: @1971 initializes the 16-byte local at 0x190
 *   literal: @1787 initializes the 5-byte local at 0x3c8
 *   literal: @1785 initializes the 10-byte local at 0x3d0
 *   literal: @1783 initializes the 10-byte local at 0x3e0
 *   literal: @1867 initializes the 4-byte local at 0x3f0
 *   literal: @1792 initializes the 4-byte local at 0x3fc
 *   quad: v0: 128-bit web split from its scalar variable as v0_q2
 *   cfg: kept branch: 0x18849c if (..) goto .L001884C0
 *   cfg: kept goto: 0x1884a8 -> .L001884D8
 *   cfg: loop body is not one contiguous region: .L00188F38
 *   cfg: loop body is not one contiguous region: .L00189098
 *   cfg: loop body is not one contiguous region: .L001891C8
 *   cfg: loop body is not one contiguous region: .L00189DA8
 *   cfg: kept branch: 0x189dc4 if (..) goto .L00189DD0
 *   cfg: kept branch: 0x189fc4 if (..) goto .L0018A040
 *   cfg: loop body is not one contiguous region: .L0018A5C0
 *   declaration vs inferred signature: return void vs inferred u_long128
 */

extern unsigned int * MakeTexPacket(unsigned int *, void *);
u_int *DrawTexture(u_int *lpPacket, TEXMNG *lpTexMng, TEXPOS *lpTexPos, float Scale,
    u_char Alpha, u_short Mode);
extern void * memcpy(void *, const void *, unsigned int);
u_int *DrawSelectCursor(u_int *lpPacket, TEXMNG *lpTexMng, int Cursor);
extern void KnMenuMng_Draw();
extern void FontDrawBegin(int);
extern signed int FsFontSetScale(float, float);
static void DrawMessage(signed int id);
extern void FontDrawEnd();
extern signed int FsFontSetAlignment(signed int);
extern unsigned short *KnMsgMng_GetMsgStr(signed int);
extern signed int FsFontGetSize(float *, float *, unsigned short *, unsigned short);
extern void FontPrintXY(float, float, char *, ...);
extern u32 lpMdlPacketMem;

#ifndef PROTO_DW_1212262_FIELDS
#define PROTO_DW_1212262_FIELDS
struct dw_1212262_fields { unsigned char State; unsigned char NextState; short Counter; unsigned char TitleNo; unsigned char BGMStart; unsigned char Select; unsigned char Port; unsigned char MaxChapter; unsigned char MaxLevel[3]; unsigned char MaxEquip; unsigned char MaxPenance; unsigned char SelectMode; unsigned char MoviePlay; unsigned char Flicker; unsigned char LogoAlpha; unsigned char StartAlpha; unsigned char SelectFlag; float SelectRate; float SelectAlpha; float ChapterScale[3]; unsigned char ChapterAlpha[3]; unsigned char ChapterShadow[3]; unsigned char ChapterLight[3]; unsigned char MaruAlpha; unsigned char LoadModel; unsigned char YesNo; unsigned char MsgNo; unsigned char unused[3]; float WinkRate; };
#endif
#ifndef PROTO_DW_1219698_FIELDS
#define PROTO_DW_1219698_FIELDS
struct dw_1219698_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#define WR (*(float *)(TitleMng + TMO(WinkRate)))
#define WABS (WR < 0.0f ? -WR : WR)
#define TMO(f) ((int)&(((struct dw_1212262_fields *)0)->f))
#define GMO(f) ((int)&(((struct dw_1219698_fields *)0)->f))
#define TPO(o) ((TEXPOS *)(TexPosInfo + (o)))
#define TPI(i) (&((TEXPOS *)TexPosInfo)[i])

static inline u_int *TitleDraw__bg(u_int *lpPacket, TEXMNG *lpTexMng);
static inline u_int *TitleDraw__dim(u_int *lpPacket);



typedef struct {
    s16 Pos[3][2];
    float Scale;
    u_char Alpha;
    u_char unused[3];
} CURSORINFO;
static u32 CursorInfo[0x19];
extern u_int *DrawTexture(u_int *, TEXMNG *, TEXPOS *, float, u_char, u_short);




extern unsigned short *KnMsgMng_GetMsgStr(signed int);
extern signed int GetNeedCluster(signed int);
extern signed int FsFontReplaceText(void *, void *, ...);
extern void FontPrintXY(float, float, char *, ...);
extern signed int FsFontGetSize(float *, float *, unsigned short *, unsigned short);
extern void GetFontColor(void *);
extern void FsFontSetDisableColor();
extern void FsFontSetEnableColor();
extern u32 TitleMessageInfo[];
extern unsigned int * MakeTexPacket(unsigned int *, void *);



extern double pow(double, double);
extern signed int UpdatePointLightPos(signed int, float *);
extern signed int UpdatePointLightRadius(signed int, float);



static f32 pl_a_2126;
static double dcomp_mul(double, double);


static u32 lpTitleTexList[0x3];
static u8 TitleMng[0x3c];
static s32 BrightnessSet = 0;
static s8 BrightnessBK = 0;
static u8 MiniGameReturn __attribute__((aligned(4))) = 0;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void LoadTitleTexture(void);
void TitleLoop(signed int AfterClear );


void LoadTitleTexture(void) {
    u32 a1;
    s32 s0;
    u32 a0;
    s64 v1;
    s32 hi;
    u32 v0;
    u8 stackFrame_20[32] __attribute__((aligned(16)));

    v0 = MemoryCardCheck;
    if (v0 == 0) {
        s0 = TitleMng[6];
    } else {
        s0 = 1;
    }
    a0 = (u32)TitleMng;
    memset((void *)TitleMng, 0, 0x3c);
    v0 = rand();
    v1 = (s32)3;
    TitleMng[6] = s0;
    hi = (s32)v0 % 3;
    v0 = MiniGameReturn;
    TitleMng[4] = hi;
    if (v0 != 0) {
        v0 = BrightnessBK;
        MiniGameReturn = 0;
        GameSt[0x1e] = v0;
    }
    a0 = (u32)"tex/title_us.tex";
    a1 = (u32)lpTitleTexList;
    ReadTexList("tex/title_us.tex", (void **)lpTitleTexList, 6, 0);
    a1 = (u32)"tex/title%d.tex";
    sprintf((char *)((u8 *)&stackFrame_20[0]), (const char *)"tex/title%d.tex", (u32)TitleMng[4]);
    ReadTexList((char *)((u8 *)&stackFrame_20[0]), (void **)(u8 *)(lpTitleTexList + 1), 6, 0);
    a0 = (u32)"tex/select_us.tex";
    ReadTexList("tex/select_us.tex", (void **)(u8 *)(lpTitleTexList + 2), 6, 0);
    KnMenuMng_ReLoadMenu(0x8000);
    FileReadControl(0);
    GameSt[0xf] = 0;
    return;
}










/* FreeTitleTexture @ 0x18DB70 .. 0x18DC1C (0xac bytes, frame 0x10) */


void FreeTitleTexture(void) {
    u32 a0;

    a0 = *(s32 *)lpTitleTexList;
    if (a0 != 0) {
        FreeTexList((void *)a0);
        a0 = *(s32 *)lpTitleTexList;
        MemFree((void *)a0);
        *(u32 *)lpTitleTexList = 0;
    }
    a0 = *(s32 *)(lpTitleTexList + 1);
    if (a0 != 0) {
        FreeTexList((void *)a0);
        a0 = *(s32 *)(lpTitleTexList + 1);
        MemFree((void *)a0);
        lpTitleTexList[1] = 0;
    }
    a0 = *(s32 *)(lpTitleTexList + 2);
    if (a0 != 0) {
        FreeTexList((void *)a0);
        a0 = *(s32 *)(lpTitleTexList + 2);
        MemFree((void *)a0);
        lpTitleTexList[2] = 0;
    }
    KnMenuMng_ReMakeMenu(0x64);
    return;
}

static inline void TitleLoop__freeModels(void) {
    u8 *mng;
    u8 *data;
    s32 i;

    mng = (u8 *)(MdlMng + 0x17f40);
    for (i = 0; i < 4; i++) {
        FreeMdlMng(mng);
        mng += 0x1c0;
    }
    data = (u8 *)(MdlData + 0xc980);
    for (i = 0; i < 4; i++) {
        if (*(s32 *)(data + 0x10) != 0) {
            FreeMdlData(data, 1);
        }
        data += 0x680;
    }
}

void TitleLoop(signed int AfterClear /* r4 */) {
    ReadMyMdl();
    InitFadeControl();
    SetPadDefaultRepeat();
    SetGlareFilter(1);
    if (MemoryCardCheck != 0) {
        TitleMng[0] = 0x29;
        TitleMng[7] = 0;
        TitleMng[6] = 1;
        MemoryCardCheck = 0;
    } else if (AfterClear != 0) {
        KnMenuMng_CallMenu(0xa, (unsigned char *)0, 0);
        GameSt[5] = 2;
        TitleMng[0] = 0x14;
        GameSt[0x28 + GameSt[0x14]] = 1;
        if (GameSt[0x1a] == 1) {
            GameSt[0x2b] = 1;
        }
    } else {
        u8 fade[16] __attribute__((aligned(16))) = {0};
        SetFadeMng(0, (signed int *)fade, 0x3c, (void *)0, (void *)0, 0, 0);
        TitleMng[0] = 0xc;
        TitleMng[5] = 0;
        TitleMng[0x11] = 0x80;
        TitleMng[0x12] = 0;
        TitleMng[0x13] = 0;
        *(u32 *)(TitleMng + 0x14) = 0;
        *(u32 *)(TitleMng + 0x18) = 0;
        *(f32 *)(TitleMng + 0x38) = 0.1f * (float)(rand() % 0x1e0 + 0x78);
    }
    while (TitleMng[0] != 0x32) {
        KickMdlPacket();
        PadUpdate();
        switch (({ s32 r_; __asm__("addi %0,%1,-24" : "=r"(r_) : "r"((s32)TitleMng[0])); r_; })) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6:
            if (TitleMng[0x32] == 0) {
                LoadTitleModel();
                TitleMng[0x32] = 1;
            }
            break;
        default:
            if (TitleMng[0x32] == 2) {
                TitleLoop__freeModels();
                TitleMng[0x32] = 0;
            }
            if (TitleMng[0x32] != 1) {
                break;
            }
            TitleMng[0x32] = 2;
        }
        TitleControl();
        if (TitleMng[0x32] == 1) {
            DrawTitleModel();
            DrawBilinerFilter();
            DrawGlareFilter();
        }
        TitleDraw();
        DrawBrightnessFilter();
        UpdateFadeMng();
        if (TitleMng[0] <= 0xd) {
            FileBackReadControl();
        }
        SND_Update();
        DrawSynch();
        if (TitleMng[0xf] != 0) {
            SetKuonMovie(0);
            TitleMng[0xf] = 0;
        }
    }
    InitFadeControl();
    MyFree();
    TitleLoop__freeModels();
    ResetMdlPacketMem();
    if (TitleMng[6] != 3) {
        GameSt[5] = 0;
    } else {
        GameSt[5] = 4;
        BrightnessBK = *(s8 *)(GameSt + 0x1e);
        MiniGameReturn = 1;
        GameSt[0x1e] = 0;
    }
}

static inline int PadA(PADD *p) {
    if (FileCheckAsyncBusy() != 0) {
        return 0;
    }
    if (p->edge.set & 0x4008) {
        return 1;
    }
    return 0;
}
void TitleControl(void) {
    u32 mx;
    PADD *lpPad;

    lpPad = PADP;
    switch (TM_State) {
    case 0:
        if (CheckFadeEnd()) {
            TM_State = 1;
            TM_Counter = 0;
            break;
        } else if (PadA(PADP)) {
            goto L_AFD8;
        }
        break;
    case 1:
        if (++TM_Counter >= 180) {
            FADE(1, 60);
            TM_State = 2;
            break;
        } else if (PadA(lpPad)) {
            goto L_AFD8;
        }
        break;
    case 2:
        if (CheckFadeEnd()) {
        L_AFD8:
            FADE(0, 60);
            TM_State = 3;
            break;
        } else if (PadA(PADP)) {
            goto L_AFD8;
        }
        break;
    case 3:
        if (CheckFadeEnd()) {
            TM_State = 4;
            TM_Counter = 0;
            break;
        } else if (PadA(PADP)) {
            goto L_B1F0;
        }
        break;
    case 4:
        if (++TM_Counter >= 180) {
            FADE(1, 60);
            TM_State = 5;
            break;
        } else if (PadA(lpPad)) {
            goto L_B1F0;
        }
        break;
    case 5:
        if (CheckFadeEnd()) {
        L_B1F0:
            FADE(0, 60);
            TM_State = 0xc;
            TM_BGMStart = 0;
            TM_LogoAlpha = 0x80;
            TM_StartAlpha = 0;
            TM_SelectFlag = 0;
            TM_SelectRate = 0.0f;
            TM_SelectAlpha = 0.0f;
            TM_WinkRate = 0.1f * (float)(rand() % 480 + 120);
            TM_MoviePlay = 1;
            break;
        } else if (PadA(PADP)) {
            goto L_B1F0;
        }
        break;
    case 6:
        if (CheckFadeEnd()) {
            TM_State = 7;
            TM_Counter = 0;
        }
        break;
    case 7:
        if (++TM_Counter < 180) {
            if (!PadA(lpPad)) {
                break;
            }
        }
        FADE(1, 60);
        TM_State = 8;
        break;
    case 8:
        if (CheckFadeEnd()) {
            FADE(0, 60);
            TM_State = 0xc;
            TM_BGMStart = 0;
            TM_LogoAlpha = 0x80;
            TM_StartAlpha = 0;
            TM_SelectFlag = 0;
            TM_SelectRate = 0.0f;
            TM_SelectAlpha = 0.0f;
            TM_WinkRate = 0.1f * (float)(rand() % 480 + 120);
            TM_MoviePlay = 1;
        }
        break;
    case 12:
    case 15:
        if (CheckFadeEnd()) {
            if (TM_State == 0xc) {
                TM_State = 0xd;
            } else {
                TM_State = 0x10;
            }
            TM_NextState = 0;
            TM_Counter = 0;
        }
        break;
    case 13:
    case 16:
        TM_WinkRate -= 0.1f;
        if (TM_WinkRate <= -1.0f) {
            TM_WinkRate = 0.1f * (float)(rand() % 480 + 120);
        }
        if (TM_LogoAlpha < 0x7d) {
            TM_LogoAlpha += 3;
        } else {
            TM_LogoAlpha = 0x80;
        }
        if (TM_State == 0xd) {
            if (TM_Flicker == 0) {
                if (TM_StartAlpha < 0x7f) {
                    TM_StartAlpha += 1;
                } else {
                    TM_StartAlpha = 0x80;
                    TM_Flicker = 1;
                }
            } else {
                if (TM_StartAlpha > 0x21) {
                    TM_StartAlpha -= 1;
                } else {
                    TM_StartAlpha = 0x20;
                    TM_Flicker = 0;
                }
            }
            if (PadA(PADP)) {
                SND_Play2D(0xb, 0x64, 0);
                TM_State = 0x10;
                TM_Counter = 0;
            }
        } else {
            if (TM_SelectFlag == 0) {
                if (lpPad->repeat.bit.Lup) {
                    TM_SelectFlag = 2;
                    TM_SelectRate = 1.0f;
                }
                if (lpPad->repeat.bit.Ldown) {
                    if (TM_Select < ((GS_Sugoroku == 3) ? 3 : 2)) {
                        TM_Select++;
                    } else {
                        TM_Select = 0;
                    }
                    TM_SelectFlag = 1;
                    TM_SelectRate = 0.0f;
                }
            } else if (TM_SelectFlag == 1) {
                TM_SelectRate += 0.1f;
                if (TM_SelectRate >= 1.0f) {
                    SND_Play2D(0x14, 0x64, 0);
                    TM_SelectFlag = 0;
                    TM_SelectRate = 0.0f;
                }
            } else if (TM_SelectFlag == 2) {
                TM_SelectRate -= 0.1f;
                if (TM_SelectRate <= 0.0f) {
                    SND_Play2D(0x14, 0x64, 0);
                    if (TM_Select > 0) {
                        TM_Select--;
                    } else {
                        TM_Select = (GS_Sugoroku == 3) ? 3 : 2;
                    }
                    TM_SelectFlag = 0;
                    TM_SelectRate = 0.0f;
                }
            }
            if (TM_StartAlpha > 3) {
                TM_StartAlpha -= 3;
            } else {
                TM_StartAlpha = 0;
            }
            if (TM_SelectAlpha < 0.95f) {
                TM_SelectAlpha += 0.05f;
            } else {
                TM_SelectAlpha = 1.0f;
            }
            if (TM_SelectFlag == 0 && PADON(0x4008)) {
                SND_Play2D(0xb, 0x64, 0);
                if (TM_Select == 2) {
                    TM_NextState = 0x12;
                }
                if (TM_Select == 0) {
                    TM_NextState = 0x13;
                }
                if (TM_Select == 1) {
                    TM_NextState = 0x2d;
                    Menu_SetLoadSlotOffsetReset();
                }
                if (TM_Select == 3) {
                    TM_NextState = 0x32;
                }
                goto L_BA30;
            } else {
                if (lpPad->repeat.set != 0) {
                    TM_Counter = 0;
                }
            }
        }
        if (++TM_Counter < 0xce4) {
            break;
        }
    L_BA30:
        if (TM_NextState == 0x32 || TM_NextState == 0) {
            if (TM_BGMStart == 1) {
                SetVagStmFade(0, 1, 0x3c);
            }
            TM_BGMStart = 2;
        }
        FADE(5, 60);
        TM_State = 0x11;
        break;
    case 18:
    case 19:
        KnMenuMng_Update(0);
        if (GS_GameMode == 2) {
            break;
        }
        if (Menu_IsLoaded()) {
            BrightnessSet = 2;
            TM_State = 0x32;
            if (TM_BGMStart == 1) {
                StopVagStm(0);
            }
            TM_BGMStart = 2;
        } else {
            FADE(0, 60);
            TM_State = 0xf;
            TM_SelectFlag = 0;
            TM_SelectRate = 0.0f;
        }
        ResetMdlPacketMem();
        break;
    case 20:
        KnMenuMng_Update(0);
        if (GS_GameMode == 0) {
            if (GS_PlayerId == 2) {
                FADE(0, 60);
                TM_State = 0;
            } else {
                FADE(0, 30);
                TM_State = 0x26;
            }
            ResetMdlPacketMem();
        }
        break;
    case 14:
    case 17:
        if (CheckFadeEnd()) {
            if (TM_NextState == 0x2d) {
                TM_Port = 0;
            }
            if (TM_NextState == 0x12) {
                KnMenuMng_CallMenu(5, (unsigned char *)0, 0);
                GS_GameMode = 2;
            } else if (TM_NextState == 0x13) {
                KnMenuMng_CallMenu(9, (unsigned char *)0, 0);
                GS_GameMode = 2;
            } else {
                FADE(0, 60);
            }
            TM_State = TM_NextState;
        }
        break;
    case 24:
        UpdateChapterCursor();
        if (CheckFadeEnd()) {
            TM_State = 0x19;
        }
        break;
    case 25:
        UpdateChapterCursor();
        if (PADON(0x4008)) {
            SND_Play2D(0xb, 0x64, 0);
            FADE(1, 60);
            TM_NextState = 0x1b;
            TM_State = 0x1a;
            TM_SelectMode = 0;
            TM_StartAlpha = 0x40;
            TM_MaruAlpha = 0x40;
            GS_GameLevel = 1;
            GS_StartEquip = 0;
            GS_PenanceMode = 0;
            break;
        } else if (PADON(0x2000)) {
            SND_Play2D(0x13, 0x64, 0);
            FADE(1, 60);
            TM_NextState = 0xf;
            TM_State = 0x1a;
            TM_StartAlpha = 0;
            break;
        } else if (lpPad->repeat.bit.Lleft) {
            SND_Play2D(0x14, 0x64, 0);
            switch (GS_PlayerId) {
            case 0:
                GS_PlayerId = 1;
                break;
            case 1:
                GS_PlayerId = (TM_MaxChapter == 2) ? 0 : 2;
                break;
            case 2:
                GS_PlayerId = 0;
                break;
            }
        } else if (lpPad->repeat.bit.Lright) {
            SND_Play2D(0x14, 0x64, 0);
            switch (GS_PlayerId) {
            case 0:
                GS_PlayerId = (TM_MaxChapter == 2) ? 1 : 2;
                break;
            case 1:
                GS_PlayerId = 0;
                break;
            case 2:
                GS_PlayerId = 1;
                break;
            }
        }
        break;
    case 26:
        UpdateChapterCursor();
        if (CheckFadeEnd()) {
            FADE(0, 60);
            TM_State = TM_NextState;
            TM_SelectFlag = 0;
            TM_SelectRate = 0.0f;
            if (TM_NextState == 0x1b) {
                SetCharaPos(1);
            } else {
                TM_Select = 1;
                TM_LogoAlpha = 0x80;
                TM_StartAlpha = 0;
                TM_SelectAlpha = 1.0f;
                TM_WinkRate = 0.1f * (float)(rand() % 480 + 120);
            }
        }
        break;
    case 27:
        if (CheckFadeEnd()) {
            TM_State = 0x1c;
        }
        break;
    case 28:
        if (TM_Flicker == 0) {
            if (TM_StartAlpha < 0x7e) {
                TM_StartAlpha += 2;
            } else {
                TM_StartAlpha = 0x80;
                TM_Flicker = 1;
            }
        } else {
            if (TM_StartAlpha > 0x42) {
                TM_StartAlpha -= 2;
            } else {
                TM_StartAlpha = 0x40;
                TM_Flicker = 0;
            }
        }
        mx = (TM_MaxEquip || TM_MaxPenance) ? 3 : 1;
        if (TM_SelectFlag == 0) {
            if (PADONL(8)) {
                TM_SelectMode = mx;
            L_C240:
                SND_Play2D(0x14, 0x64, 0);
                TM_State = 0x1d;
                TM_YesNo = 0;
                TM_SelectMode = 0xff;
                break;
            } else if (PADONL(0x4008)) {
                if (TM_SelectMode < (s32)mx) {
                    SND_Play2D(0x14, 0x64, 0);
                    TM_SelectMode++;
                    break;
                }
                goto L_C240;
            } else if (PADONL(0x2000)) {
                SND_Play2D(0x13, 0x64, 0);
                FADE(1, 60);
                TM_NextState = 0x18;
                TM_State = 0x1e;
                break;
            } else if (lpPad->repeat.bit.Lup) {
                SND_Play2D(0x14, 0x64, 0);
                if (TM_SelectMode > 0) {
                    TM_SelectMode--;
                } else {
                    TM_SelectMode = mx;
                }
                break;
            } else if (lpPad->repeat.bit.Ldown) {
                SND_Play2D(0x14, 0x64, 0);
                if (TM_SelectMode < (s32)mx) {
                    TM_SelectMode++;
                } else {
                    TM_SelectMode = 0;
                }
                break;
            }
            if (TM_MaxEquip || TM_MaxPenance) {
                switch (TM_SelectMode) {
                case 0:
                    if (lpPad->repeat.bit.Lleft) {
                        SND_Play2D(0x14, 0x64, 0);
                        if (GS_GameLevel > 0) {
                            GS_GameLevel--;
                        } else {
                            GS_GameLevel = TitleMng[9 + GS_PlayerId] - 1;
                        }
                    }
                    if (lpPad->repeat.bit.Lright) {
                        SND_Play2D(0x14, 0x64, 0);
                        if (GS_GameLevel < TitleMng[9 + GS_PlayerId] - 1) {
                            GS_GameLevel++;
                        } else {
                            GS_GameLevel = 0;
                        }
                    }
                    break;
                case 1:
                    if (lpPad->repeat.bit.Lleft) {
                        SND_Play2D(0x14, 0x64, 0);
                        if (GS_StartEquip > 0) {
                            GS_StartEquip--;
                        } else {
                            GS_StartEquip = TM_MaxEquip - 1;
                        }
                    }
                    if (lpPad->repeat.bit.Lright) {
                        SND_Play2D(0x14, 0x64, 0);
                        if (GS_StartEquip < TM_MaxEquip - 1) {
                            GS_StartEquip++;
                        } else {
                            GS_StartEquip = 0;
                        }
                    }
                    break;
                case 2:
                    if (lpPad->repeat.bit.Lleft) {
                        SND_Play2D(0x14, 0x64, 0);
                        if (GS_PenanceMode > 0) {
                            GS_PenanceMode--;
                        } else {
                            GS_PenanceMode = TM_MaxPenance - 1;
                        }
                    }
                    if (lpPad->repeat.bit.Lright) {
                        SND_Play2D(0x14, 0x64, 0);
                        if (GS_PenanceMode < TM_MaxPenance - 1) {
                            GS_PenanceMode++;
                        } else {
                            GS_PenanceMode = 0;
                        }
                    }
                    break;
                }
            } else {
                switch (TM_SelectMode) {
                case 0:
                    if (lpPad->repeat.bit.Lleft) {
                        TM_SelectFlag = 2;
                        TM_SelectRate = 1.0f;
                    }
                    if (lpPad->repeat.bit.Lright) {
                        if (GS_GameLevel < TitleMng[9 + GS_PlayerId] - 1) {
                            GS_GameLevel++;
                        } else {
                            GS_GameLevel = 0;
                        }
                        TM_SelectRate = 0.0f;
                        TM_SelectFlag = 1;
                    }
                }
            }
        } else if (TM_SelectFlag == 1) {
            TM_SelectRate += 0.1f;
            if (TM_SelectRate >= 1.0f) {
                SND_Play2D(0x14, 0x64, 0);
                TM_SelectFlag = 0;
                TM_SelectRate = 0.0f;
            }
        } else if (TM_SelectFlag == 2) {
            TM_SelectRate -= 0.1f;
            if (TM_SelectRate <= 0.0f) {
                SND_Play2D(0x14, 0x64, 0);
                if (GS_GameLevel > 0) {
                    GS_GameLevel--;
                } else {
                    GS_GameLevel = TitleMng[9 + GS_PlayerId] - 1;
                }
                TM_SelectFlag = 0;
                TM_SelectRate = 0.0f;
            }
        }
        break;
    case 29:
        if (lpPad->repeat.bit.Lup && TM_YesNo > 0) {
            SND_Play2D(0x14, 0x64, 0);
            TM_YesNo--;
        }
        if (lpPad->repeat.bit.Ldown && TM_YesNo <= 0) {
            SND_Play2D(0x14, 0x64, 0);
            TM_YesNo++;
        }
        if (PADON(0x4008)) {
            if (TM_YesNo != 0) {
                goto L_CA40;
            }
            SND_Play2D(0xb, 0x64, 0);
            if (TM_BGMStart == 1) {
                SetVagStmFade(0, 1, 0x3c);
            }
            TM_BGMStart = 2;
            switch (GS_PlayerId) {
            case 0:
                SetSceneLoad(0x24, 0);
                break;
            case 1:
                SetSceneLoad(0x5a, 0);
                break;
            case 2:
                SetSceneLoad(0x57, 0);
            }
            FADE(1, 60);
            if (BrightnessSet == 0) {
                BrightnessSet = 1;
            }
            if (GS_PlayerId == 0) {
                TM_NextState = 0x23;
            } else {
                TM_NextState = 0x32;
            }
            TM_State = 0x1e;
            break;
        } else if (PADON(0x2000)) {
        L_CA40:
            TM_SelectMode = (TM_MaxEquip || TM_MaxPenance) ? 3 : 1;
            TM_State = 0x1c;
            break;
        }
        break;
    case 30:
        if (CheckFadeEnd()) {
            FADE(0, 60);
            if (BrightnessSet == 1) {
                TM_State = 0x1f;
                BrightnessSet = 2;
            } else {
                TM_State = TM_NextState;
            }
            if (TM_NextState == 0x18) {
                SetCharaPos(0);
            }
        }
        break;
    case 31:
        if (CheckFadeEnd()) {
            TM_State = 0x20;
            fspad_PadSetRepeat(0, 0, 0xa0, 0x1e, 6);
        }
        break;
    case 32:
        if (lpPad->repeat.set & 0x80) {
            if (GS_Brightness != -100) {
                if (GS_Brightness > 0x60) {
                    GS_Brightness = 0x60;
                } else if (GS_Brightness < -0x5f) {
                    GS_Brightness = -100;
                } else {
                    GS_Brightness -= 6;
                }
                SND_Play2D(0x14, 0x64, 0x258);
            } else {
                SND_Play2D(0x16, 0x64, 0);
            }
        }
        if (lpPad->repeat.set & 0x20) {
            if (GS_Brightness != 100) {
                if (GS_Brightness < -0x60) {
                    GS_Brightness = -0x60;
                } else if (GS_Brightness >= 0x60) {
                    GS_Brightness = 100;
                } else {
                    GS_Brightness += 6;
                }
                SND_Play2D(0x14, 0x64, 0x258);
            } else {
                SND_Play2D(0x16, 0x64, 0);
            }
        }
        if (PADON(0x4008)) {
            SND_Play2D(0x14, 0x64, 0);
            TM_State = 0x21;
        }
        break;
    case 33:
        if (PADONL(0x4008)) {
            SND_Play2D(0xb, 0x64, 0);
            TM_State = 0x22;
            FADE(5, 60);
            SetPadDefaultRepeat();
            break;
        } else if (PADONL(0x2000)) {
            SND_Play2D(0x13, 0x64, 0);
            TM_State = 0x20;
            break;
        }
        break;
    case 34:
        if (CheckFadeEnd()) {
            TM_State = TM_NextState;
            if (TM_NextState == 0x23) {
                FADE(0, 60);
            }
        }
        break;
    case 35:
        if (CheckFadeEnd()) {
            StopVagStm(0);
            PlayBgmVagStm(0, 0xd);
            TM_State = 0x24;
            TM_Counter = 0;
        }
        break;
    case 36:
        TM_Counter++;
        if (TM_Counter > 0xa6a) {
        L_CE70:
            FADE(1, 60);
            TM_State = 0x25;
            SetVagStmFade(0, 1, 0x3c);
            break;
        } else if (PadA(lpPad)) {
            if (CheckVagStmState(0) == 4) {
                goto L_CE70;
            }
        }
        break;
    case 37:
        TM_Counter++;
        if (CheckFadeEnd()) {
            FADE(0, 60);
            TM_State = 0x32;
        }
        break;
    case 38:
        if (CheckFadeEnd()) {
            TM_State = 0x27;
        }
        break;
    case 39:
        if (PadA(lpPad)) {
            FADE(1, 30);
            TM_State = 0x28;
        }
        break;
    case 40:
        if (CheckFadeEnd()) {
            FADE(0, 60);
            TM_State = 0x2d;
            TM_Port = 0;
        }
        break;
    case 41:
        MemoryCardStart(0, TM_Port, 0);
        TM_State = 0x2a;
    case 42:
        if (MemoryCardProc()) {
            if (ExistKuonData()) {
                TM_Select = 2;
                MemoryCardStart(1, TM_Port, 0);
                TM_State = 0x2b;
                break;
            } else {
                CheckMCResult();
            }
        }
        break;
    case 43: {
        int Ret = MemoryCardProc();
        if (Ret == 0) {
            break;
        }
        if (Ret > 0) {
            struct SaveSysT *lpSaveSys = GetSaveSystem();
            GS_Sugoroku |= lpSaveSys->Sugoroku;
        }
        CheckMCResult();
        break;
    }
    case 44:
        if (TM_Flicker == 0) {
            if (TM_StartAlpha < 0x7e) {
                TM_StartAlpha += 2;
            } else {
                TM_StartAlpha = 0x80;
                TM_Flicker = 1;
            }
        } else {
            if (TM_StartAlpha > 0x42) {
                TM_StartAlpha -= 2;
            } else {
                TM_StartAlpha = 0x40;
                TM_Flicker = 0;
            }
        }
        if (lpPad->repeat.bit.Lup && TM_YesNo > 0) {
            TM_YesNo--;
        }
        if (lpPad->repeat.bit.Ldown && TM_YesNo <= 0) {
            TM_YesNo++;
        }
        if (PADONL(0x4008)) {
            if (TM_YesNo == 0) {
                FADE(0, 60);
                TM_State = 0;
            } else {
                TM_State = 0x29;
                TM_Port = 0;
                TM_Select = 1;
                TM_StartAlpha = 0;
                TM_Flicker = 0;
            }
        }
        break;
    case 45:
        MemoryCardStart(6, TM_Port, 0);
        TM_State = 0x2e;
        TM_MaxChapter = 2;
        TM_MaxLevel(0) = 3;
        TM_MaxLevel(1) = 3;
        TM_MaxLevel(2) = 3;
        TM_MaxEquip = 0;
        TM_MaxPenance = 0;
        if (TM_SelectMode >= TM_MaxChapter) {
            TM_SelectMode = 0;
        }
        GS_ClearCount(0) = GS_ClearCount(1) = GS_ClearCount(2) = GS_ExtraClear = 0;
    case 46:
        if (MemoryCardProc()) {
            MemoryCardStart(1, TM_Port, 0);
            TM_State = 0x2f;
        }
        break;
    case 47: {
        int Ret = MemoryCardProc();
        if (Ret == 0) {
            break;
        }
        if (Ret > 0) {
            struct SaveSysT *lpSaveSys = GetSaveSystem();
            GS_ClearCount(0) |= lpSaveSys->ClearCount[0];
            GS_ClearCount(1) |= lpSaveSys->ClearCount[1];
            GS_ClearCount(2) |= lpSaveSys->ClearCount[2];
            GS_ExtraClear |= lpSaveSys->ExtraClear;
        }
        if (TM_Port == 0) {
            TM_Port++;
            MemoryCardStart(1, TM_Port, 0);
            TM_State = 0x2f;
            break;
        }
        if (GS_ClearCount(0) != 0 && GS_ClearCount(1) != 0) {
            TM_MaxChapter = 3;
        }
        if (GS_ClearCount(2) != 0) {
            TM_MaxEquip = 2;
            if (GS_ExtraClear != 0) {
                TM_MaxPenance = 3;
            } else {
                TM_MaxPenance = 2;
            }
        }
        if (GS_ClearCount(0) != 0) {
            TM_MaxLevel(0) = 4;
        }
        if (GS_ClearCount(1) != 0) {
            TM_MaxLevel(1) = 4;
        }
        if (GS_ClearCount(2) != 0) {
            TM_MaxLevel(2) = 4;
        }
        FADE(0, 60);
        TM_State = 0x18;
        if (GS_ClearCount(0) == 0) {
            GS_PlayerId = 0;
        } else if (GS_ClearCount(1) == 0) {
            GS_PlayerId = 1;
        } else {
            GS_PlayerId = 2;
        }
        TM_ChapterAlpha(0) = 0;
        TM_ChapterScale(0) = 1.0f;
        TM_ChapterShadow(0) = 0;
        TM_ChapterLight(0) = 0;
        TM_ChapterAlpha(1) = 0;
        TM_ChapterScale(2) = TM_ChapterScale(1) = 1.0f;
        TM_ChapterShadow(1) = 0;
        TM_ChapterLight(1) = 0;
        TM_ChapterAlpha(2) = 0;
        TM_ChapterShadow(2) = 0;
        TM_ChapterLight(2) = 0;
        break;
    }
    case 49:
        if (FileCheckAsyncBusy() == 0) {
            TM_State = TM_NextState;
            FADE(0, 60);
        }
        break;
    default:
        break;
    }
    if (TM_BGMStart == 0 && TM_MoviePlay == 0 && TM_State >= 0xc && TM_State <= 0x11) {
        if (FileCheckAsyncBusy() == 0) {
            StopVagStm(0);
            PlayBgmVagStm(0, 0);
            TM_BGMStart = 1;
        }
    }
}

void CheckMCResult(void) {
    s32 a2;
    u32 a0;
    u32 v1;
    u32 v0;
    u32 s1;
    u32 s0;

    a0 = TitleMng[7];
    v0 = GetMemoryCardMessage(a0);
    a0 = 2;
    v1 = 0x29;
    if (v0 == a0) {
        *(u8 *)TitleMng = v1;
    } else {
        v1 = TitleMng[7];
        if (v1 == 0) {
            a0 = 0x29;
            *(u8 *)TitleMng = a0;
            v1 = 1;
            TitleMng[7] = v1;
        } else {
            v0 = TitleMng[6];
            if (v0 == a0) {
                {
                    u8 stackFrame_40[16] __attribute__((aligned(16))) = {0};
                    a2 = 0x3c;
                    SetFadeMng(0, (signed int *)(u8 *)((u8 *)&stackFrame_40[0]), a2, (void *)0,
                        (void *)0, 0, 0);
                    *(u8 *)TitleMng = 0;
                }
            } else {
                s1 = 0;
                s0 = 0;
                do {
                    v0 = GetMemoryCardMessage(s0);
                    v1 = 0x1f;
                    switch (v0) {
                    case 0:
                    case 3:
                    case 4:
                    case 2:
                        s1 = s1 | 0x10;
                        break;
                    case 31:
                        v1 = 1;
                        v1 = v1 << s0;
                        s1 = s1 | v1;
                    }
                    s0 = s0 + 1;
                    v1 = (s32)s0 < (s32)2;
                } while (v1 != 0);
                v1 = s1 & 0x10;
                if (v1 != 0) {
                    {
                        u8 stackFrame_30[16] __attribute__((aligned(16))) = {0};
                        a2 = 0x3c;
                        SetFadeMng(0, (signed int *)(u8 *)((u8 *)&stackFrame_30[0]), a2, (void *)0,
                            (void *)0, 0, 0);
                        *(u8 *)TitleMng = 0;
                    }
                } else {
                    v1 = 3;
                    switch (s1) {
                    case 1:
                        v1 = 0x33;
                        TitleMng[0x34] = v1;
                        break;
                    case 2:
                        v1 = 0x34;
                        TitleMng[0x34] = v1;
                        break;
                    case 3:
                        v1 = 0x35;
                        TitleMng[0x34] = v1;
                        break;
                    default:
                        v1 = 0x32;
                        TitleMng[0x34] = v1;
                    }
                    TitleMng[0x33] = 0;
                    a0 = 0x2c;
                    v1 = 0x40;
                    *(u8 *)TitleMng = a0;
                    TitleMng[0x12] = v1;
                }
            }
        }
    }
    return;
}



/* UpdateChapterCursor @ 0x18A9D0 .. 0x18ABDC (0x20c bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f8b851f at 0x18aa00
 *   fpu: float literal 0x3c23d70a at 0x18aa08
 *   fpu: float literal 0x3f8147ae at 0x18aa18
 *   cfg: loop body is not one contiguous region: .L0018AA28
 */

void UpdateChapterCursor(void) {
    u8 t6;
    s32 t3;
    u32 t2;
    s32 t1;
    u8 *t0;
    u8 *a3;
    u32 a2;
    u32 a0;
    float f3;
    float f2;
    float f1;
    float f0;
    s32 v1;

    a2 = GameSt[0x14];
    t0 = TitleMng;
    t1 = 0;
    a3 = TitleMng;
    v1 = 0x3f8b0000;
    t2 = 0x3c230000;
    a0 = 0x3f8b0000 | 0x851f;
    t3 = 0x3c230000 | 0xd70a;
    v1 = 0x3f8c0000;
    f3 = 1.09000003f;
    t2 = 0x3f8147ae;
    f2 = 0.00999999978f;
    f1 = 1.00999999f;
    do {
        if (a2 == (u32)t1) {
            t2 = *(u8 *)(t0 + 0x28);
            if ((s32)t2 <= (s32)0x77) {
                *(u8 *)(t0 + 0x28) = t2 + 8;
            } else {
                *(u8 *)(t0 + 0x28) = 0x80;
            }
            f0 = *(float *)(a3 + 0x1c);
            if (f0 < f3) {
                *(f32 *)(a3 + 0x1c) = (f0 + f2);
            } else {
                *(u32 *)(a3 + 0x1c) = 0x3f8c0000 | 0xcccd;
            }
            t2 = *(u8 *)(t0 + 0x2b);
            if ((s32)t2 <= (s32)0xee) {
                *(u8 *)(t0 + 0x2b) = t2 + 0x10;
            } else {
                *(u8 *)(t0 + 0x2b) = 0xff;
            }
            t6 = *(u8 *)(t0 + 0x2e);
            if ((s32)t6 <= (s32)0x37) {
                t2 = (u32)(t6) + 8;
                *(u8 *)(t0 + 0x2e) = t2;
                TitleMng[0x10] = 0;
            } else {
                t2 = TitleMng[0x10];
                if (t2 == 0) {
                    if ((s32)t6 <= (s32)0x7e) {
                        *(u8 *)(t0 + 0x2e) = (u32)(t6) + 1;
                    } else {
                        *(u8 *)(t0 + 0x2e) = 0x80;
                        TitleMng[0x10] = 1;
                    }
                } else if ((s32)t6 > (s32)0x41) {
                    *(u8 *)(t0 + 0x2e) = (u32)(t6) + -1;
                } else {
                    *(u8 *)(t0 + 0x2e) = 0x40;
                    TitleMng[0x10] = 0;
                }
            }
        } else {
            t2 = *(u8 *)(t0 + 0x28);
            if ((s32)t2 > (s32)8) {
                *(u8 *)(t0 + 0x28) = t2 + -8;
            } else {
                *(u8 *)(t0 + 0x28) = 0;
            }
            f0 = *(float *)(a3 + 0x1c);
            if (!(f0 <= f1)) {
                *(f32 *)(a3 + 0x1c) = (f0 - f2);
            } else {
                *(u32 *)(a3 + 0x1c) = 0x3f800000;
            }
            t2 = *(u8 *)(t0 + 0x2b);
            if ((s32)t2 > (s32)0x10) {
                *(u8 *)(t0 + 0x2b) = t2 + -0x10;
            } else {
                *(u8 *)(t0 + 0x2b) = 0;
            }
            t2 = *(u8 *)(t0 + 0x2e);
            if ((s32)t2 > (s32)8) {
                *(u8 *)(t0 + 0x2e) = t2 + -8;
            } else {
                *(u8 *)(t0 + 0x2e) = 0;
            }
        }
        t1 = t1 + 1;
        t2 = t1 < (s32)3;
        t0 = (u8 *)(t0 + 1);
        a3 = (u8 *)(a3 + 4);
    } while (t2 != 0);
    return;
}

void TitleDraw(void) {
    u_int *lpPacket;
    TEXMNG *lpTexMng;
    char FileName[32];
    TEXPOS WkTexPosInfo;

    lpPacket = (u_int *)lpMdlPacketMem;
    lpPacket[0] = 0x10000000 | 2;
    lpPacket[1] = 0;
    lpPacket[2] = 0;
    lpPacket[3] = 0x51000000 | 2;
    lpPacket[4] = 0x8001;
    lpPacket[5] = 0x10000000;
    lpPacket[6] = 0xe;
    lpPacket[7] = 0;
    if (TitleMng[TMO(State)] == 0x12 || TitleMng[TMO(State)] == 0x13 || TitleMng[TMO(State)] == 0x14) {
        *(u64 *)(lpPacket + 8) = 0;
        *(s64 *)(lpPacket + 10) = 8;
        lpPacket += 12;
    } else {
        *(s64 *)(lpPacket + 8) = 5;
        *(s64 *)(lpPacket + 10) = 8;
        lpPacket += 12;
    }
    switch (TitleMng[TMO(State)]) {
    case 0:
    case 1:
    case 2:
        if ((lpTexMng = GetTexMngByName(0, "agetec.tm2")) == 0) {
            break;
        }
        lpPacket = DrawTexture(MakeTexPacket(lpPacket, lpTexMng), lpTexMng, TPO(0), 1.0f, 0x80, 0);
        break;
    case 3:
    case 4:
    case 5:
        if ((lpTexMng = GetTexMngByName(0, "opn_00.tm2")) == 0) {
            break;
        }
        lpPacket = DrawTexture(MakeTexPacket(lpPacket, lpTexMng), lpTexMng, TPO(8), 1.0f, 0x80, 0);
        break;
    case 6:
    case 7:
    case 8:
        if ((lpTexMng = GetTexMngByName(0, "opn_04.tm2")) == 0) {
            break;
        }
        lpPacket = DrawTexture(MakeTexPacket(lpPacket, lpTexMng), lpTexMng, TPO(0x10), 1.0f, 0x80, 0);
        break;
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
        sprintf(FileName, "fe_ti_000%d.tm2", TitleMng[TMO(TitleNo)]);
        if ((lpTexMng = GetTexMngByName(0, FileName)) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            if ((*(float *)(TitleMng + TMO(WinkRate))) >= 1.0f) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(TitleMng[TMO(TitleNo)] + 4), 1.0f, 0x80, 0);
            } else {
                memcpy(&WkTexPosInfo, TPI(TitleMng[TMO(TitleNo)] + 4), 16);
                switch (TitleMng[TMO(TitleNo)]) {
                case 0:
                    WkTexPosInfo.x = (s16)((float)WkTexPosInfo.x - 5.0f * (1.0f - WABS));
                    break;
                case 1:
                    WkTexPosInfo.x = (s16)((float)WkTexPosInfo.x + 6.0f * (1.0f - WABS));
                    break;
                case 2:
                    WkTexPosInfo.y = (s16)((float)WkTexPosInfo.y - 5.0f * (1.0f - WABS));
                }
                lpPacket = DrawTexture(lpPacket, lpTexMng, &WkTexPosInfo, 1.0f, 0x80, 0);
            }
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x18), 1.0f, 0x80, 0);
        }
        if ((lpTexMng = GetTexMngByName(0, "fe_ti_0003.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(TitleMng[TMO(TitleNo)] + 7), 1.0f, TitleMng[TMO(LogoAlpha)], 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(TitleMng[TMO(TitleNo)] + 10), 1.0f, TitleMng[TMO(StartAlpha)], 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x88), 3.0f, TitleMng[TMO(LogoAlpha)], 0);
        }
        if ((lpTexMng = GetTexMngByName(0, "fe_ti_0008.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x90), 1.0f, TitleMng[TMO(LogoAlpha)], 0);
        }
        if ((lpTexMng = GetTexMngByName(0, "fe_ti_0009.tm2")) == 0) {
            break;
        }
        lpPacket = MakeTexPacket(lpPacket, lpTexMng);
        lpPacket = DrawSelectCursor(lpPacket, lpTexMng, 0);
        lpPacket = DrawSelectCursor(lpPacket, lpTexMng, 1);
        lpPacket = DrawSelectCursor(lpPacket, lpTexMng, 2);
        lpPacket = DrawSelectCursor(lpPacket, lpTexMng, 3);
        break;
    case 18:
    case 19:
    case 20:
        lpMdlPacketMem = (u32)lpPacket;
        KnMenuMng_Draw();
        lpPacket = (u_int *)lpMdlPacketMem;
        break;
    case 24:
    case 25:
    case 26:
        if ((lpTexMng = GetTexMngByName(0, "fe_me_0000.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x2e0), 1.2f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x2e8), 1.2f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x2f0), 1.2f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x2f8), 1.2f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x300), 1.2f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x308), 1.2f, 0x80, 0);
        }
        if ((lpTexMng = GetTexMngByName(0, "fe_ti_0005.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0xa0), 1.0f, 0x80, 2);
            if (TitleMng[TMO(ChapterShadow[0])] <= 0x7f) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0xb8), (*(float *)(TitleMng + TMO(ChapterScale[0]))), 0x80 - TitleMng[TMO(ChapterShadow[0])], 1);
            } else {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0xc0), (*(float *)(TitleMng + TMO(ChapterScale[0]))), TitleMng[TMO(ChapterShadow[0])] - 0x80, 2);
            }
            if (TitleMng[TMO(ChapterShadow[1])] <= 0x7f) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0xd8), (*(float *)(TitleMng + TMO(ChapterScale[1]))), 0x80 - TitleMng[TMO(ChapterShadow[1])], 1);
            } else {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0xe0), (*(float *)(TitleMng + TMO(ChapterScale[1]))), TitleMng[TMO(ChapterShadow[1])] - 0x80, 2);
            }
            if (TitleMng[TMO(MaxChapter)] > 2) {
                if (TitleMng[TMO(ChapterShadow[2])] <= 0x7f) {
                    lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0xf8), (*(float *)(TitleMng + TMO(ChapterScale[2]))), 0x80 - TitleMng[TMO(ChapterShadow[2])], 1);
                    lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x100), (*(float *)(TitleMng + TMO(ChapterScale[2]))), 0x80 - TitleMng[TMO(ChapterShadow[2])], 1);
                } else {
                    lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x108), (*(float *)(TitleMng + TMO(ChapterScale[2]))), TitleMng[TMO(ChapterShadow[2])] - 0x80, 2);
                    lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x110), (*(float *)(TitleMng + TMO(ChapterScale[2]))), TitleMng[TMO(ChapterShadow[2])] - 0x80, 2);
                }
            }
        }
        if ((lpTexMng = GetTexMngByName(0, "fe_ti_0004.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x98), 1.0f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0xb0), (*(float *)(TitleMng + TMO(ChapterScale[0]))), TitleMng[TMO(ChapterAlpha[0])], 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0xd0), (*(float *)(TitleMng + TMO(ChapterScale[1]))), TitleMng[TMO(ChapterAlpha[1])], 0);
            if (TitleMng[TMO(MaxChapter)] > 2) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0xf0), (*(float *)(TitleMng + TMO(ChapterScale[2]))), TitleMng[TMO(ChapterAlpha[2])], 0);
            }
        }
        if ((lpTexMng = GetTexMngByName(0, "fe_ti_0006.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0xa8), 1.0f, 0x80, 1);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0xc8), (*(float *)(TitleMng + TMO(ChapterScale[0]))), TitleMng[TMO(ChapterLight[0])], 1);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0xe8), (*(float *)(TitleMng + TMO(ChapterScale[1]))), TitleMng[TMO(ChapterLight[1])], 1);
            if (TitleMng[TMO(MaxChapter)] > 2) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x118), (*(float *)(TitleMng + TMO(ChapterScale[2]))), TitleMng[TMO(ChapterLight[2])], 1);
            }
        }
        if ((lpTexMng = GetTexMngByName(0, "rubi_ti_002.tm2")) != 0) {
            int i;
            u_char Alpha;
            u_short Mode;
            lpPacket = DrawTexture(MakeTexPacket(lpPacket, lpTexMng), lpTexMng, TPO(0x180), 1.0f, 0x80, 3);
            for (i = 0; i < TitleMng[TMO(MaxChapter)]; i++) {
                Alpha = TitleMng[TMO(ChapterShadow[0]) + i] <= 0x7f ? 0x80 - TitleMng[TMO(ChapterShadow[0]) + i] : TitleMng[TMO(ChapterShadow[0]) + i] - 0x80;
                if (TitleMng[TMO(ChapterShadow[0]) + i] <= 0x7f) {
                    Mode = 1;
                } else {
                    Mode = 3;
                }
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(i + 0x31), (*(float *)(TitleMng + TMO(ChapterScale[0]) + i * 4)), Alpha, Mode);
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(i + 0x34), (*(float *)(TitleMng + TMO(ChapterScale[0]) + i * 4)), Alpha, Mode);
                if (TitleMng[TMO(MaxLevel[0]) + i] >= 4) {
                    lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(i + 0x37), (*(float *)(TitleMng + TMO(ChapterScale[0]) + i * 4)), Alpha, Mode);
                }
            }
        }
        if ((lpTexMng = GetTexMngByName(0, "rubi_ti_001.tm2")) != 0) {
            int i;
            u_char Alpha;
            lpPacket = DrawTexture(MakeTexPacket(lpPacket, lpTexMng), lpTexMng, TPO(0x180), 1.0f, 0x80, 0);
            for (i = 0; i < TitleMng[TMO(MaxChapter)]; i++) {
                Alpha = TitleMng[TMO(ChapterAlpha[0]) + i];
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(i + 0x31), (*(float *)(TitleMng + TMO(ChapterScale[0]) + i * 4)), Alpha, 0);
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(i + 0x34), (*(float *)(TitleMng + TMO(ChapterScale[0]) + i * 4)), Alpha, 0);
                if (TitleMng[TMO(MaxLevel[0]) + i] >= 4) {
                    lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(i + 0x37), (*(float *)(TitleMng + TMO(ChapterScale[0]) + i * 4)), Alpha, 0);
                }
            }
        }
        if ((lpTexMng = GetTexMngByName(0, "rubi_ti_003.tm2")) != 0) {
            int i;
            u_char Alpha;
            lpPacket = DrawTexture(MakeTexPacket(lpPacket, lpTexMng), lpTexMng, TPO(0x180), 1.0f, 0x80, 1);
            for (i = 0; i < TitleMng[TMO(MaxChapter)]; i++) {
                Alpha = TitleMng[TMO(ChapterLight[0]) + i];
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(i + 0x31), (*(float *)(TitleMng + TMO(ChapterScale[0]) + i * 4)), Alpha, 1);
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(i + 0x34), (*(float *)(TitleMng + TMO(ChapterScale[0]) + i * 4)), Alpha, 1);
                if (TitleMng[TMO(MaxLevel[0]) + i] >= 4) {
                    lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(i + 0x37), (*(float *)(TitleMng + TMO(ChapterScale[0]) + i * 4)), Alpha, 1);
                }
            }
        }
        FontDrawBegin(0);
        FsFontSetScale(0.8f, 0.8f);
        DrawMessage(GameSt[GMO(PlayerId)] + 0x22);
        FsFontSetScale(0.8f, 0.8f);
        DrawMessage(0x3f);
        FontDrawEnd();
        break;
    case 27:
    case 28:
    case 29:
    case 30:
        if (TitleMng[TMO(State)] == 0x1d) {
            lpPacket = TitleDraw__dim(lpPacket);
        }
        if ((lpTexMng = GetTexMngByName(0, "fe_me_0000.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x2e0), 1.2f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x2e8), 1.2f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x2f0), 1.2f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x2f8), 1.2f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x300), 1.2f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x308), 1.2f, 0x80, 0);
        }
        if ((lpTexMng = GetTexMngByName(0, "fe_me_0019.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            if (TitleMng[TMO(State)] == 0x1d) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(TitleMng[TMO(YesNo)] + 0x6a), 1.0f, TitleMng[TMO(StartAlpha)], 1);
            } else if (TitleMng[TMO(MaxEquip)] != 0 || TitleMng[TMO(MaxPenance)] != 0) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(TitleMng[TMO(SelectMode)] + 0x56), 1.0f, TitleMng[TMO(StartAlpha)], 1);
            } else {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(TitleMng[TMO(SelectMode)] + 0x5a), 1.0f, TitleMng[TMO(StartAlpha)], 1);
            }
        }
        if ((lpTexMng = GetTexMngByName(0, "fe_ti_0007.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x330), 1.0f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x338), 1.0f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x340), 1.0f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x348), 1.0f, 0x80, 0);
        }
        if ((lpTexMng = GetTexMngByName(0, "fe_ti_0005.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            if (GameSt[GMO(PlayerId)] == 0) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x1d8), 1.0f, 0x80, 2);
            } else if (GameSt[GMO(PlayerId)] == 1) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x1f0), 1.0f, 0x80, 2);
            } else if (GameSt[GMO(PlayerId)] == 2) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x208), 1.0f, 0x80, 2);
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x210), 1.0f, 0x80, 2);
            }
        }
        if ((lpTexMng = GetTexMngByName(0, "fe_ti_0004.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            if (GameSt[GMO(PlayerId)] == 0) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x1d0), 1.0f, 0x80, 0);
            } else if (GameSt[GMO(PlayerId)] == 1) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x1e8), 1.0f, 0x80, 0);
            } else if (GameSt[GMO(PlayerId)] == 2) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x200), 1.0f, 0x80, 0);
            }
        }
        if ((lpTexMng = GetTexMngByName(0, "fe_ti_0006.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            if (GameSt[GMO(PlayerId)] == 0) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x1e0), 1.0f, 0x80, 1);
            } else if (GameSt[GMO(PlayerId)] == 1) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x1f8), 1.0f, 0x80, 1);
            } else if (GameSt[GMO(PlayerId)] == 2) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x218), 1.0f, 0x80, 1);
            }
        }
        if ((lpTexMng = GetTexMngByName(0, "rubi_ti_002.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(GameSt[GMO(PlayerId)] + 0x4d), 1.0f, 0x80, 3);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(GameSt[GMO(PlayerId)] + 0x50), 1.0f, 0x80, 3);
            if (TitleMng[TMO(MaxLevel[0]) + GameSt[GMO(PlayerId)]] >= 4) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(GameSt[GMO(PlayerId)] + 0x53), 1.0f, 0x80, 3);
            }
        }
        if ((lpTexMng = GetTexMngByName(0, "rubi_ti_001.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(GameSt[GMO(PlayerId)] + 0x4d), 1.0f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(GameSt[GMO(PlayerId)] + 0x50), 1.0f, 0x80, 0);
            if (TitleMng[TMO(MaxLevel[0]) + GameSt[GMO(PlayerId)]] >= 4) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(GameSt[GMO(PlayerId)] + 0x53), 1.0f, 0x80, 0);
            }
        }
        if ((lpTexMng = GetTexMngByName(0, "rubi_ti_003.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(GameSt[GMO(PlayerId)] + 0x4d), 1.0f, 0x80, 1);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(GameSt[GMO(PlayerId)] + 0x50), 1.0f, 0x80, 1);
            if (TitleMng[TMO(MaxLevel[0]) + GameSt[GMO(PlayerId)]] >= 4) {
                lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(GameSt[GMO(PlayerId)] + 0x53), 1.0f, 0x80, 1);
            }
        }
        FontDrawBegin(0);
        FsFontSetScale(0.9f, 0.9f);
        if (TitleMng[TMO(MaxEquip)] != 0 || TitleMng[TMO(MaxPenance)] != 0) {
            if (TitleMng[TMO(SelectMode)] == 0) {
                FsFontSetScale(1.0f, 1.0f);
                DrawMessage(0xd);
                DrawMessage(GameSt[GMO(GameLevel)] + 0xe);
                FsFontSetScale(0.9f, 0.9f);
            } else {
                DrawMessage(0);
                DrawMessage(GameSt[GMO(GameLevel)] + 1);
            }
            if (TitleMng[TMO(SelectMode)] == 1) {
                FsFontSetScale(1.0f, 1.0f);
                DrawMessage(0x12);
                DrawMessage(GameSt[GMO(StartEquip)] + 0x13);
                FsFontSetScale(0.9f, 0.9f);
            } else {
                DrawMessage(5);
                DrawMessage(GameSt[GMO(StartEquip)] + 6);
            }
            if (TitleMng[TMO(SelectMode)] == 2) {
                FsFontSetScale(1.0f, 1.0f);
                DrawMessage(0x15);
                DrawMessage(GameSt[GMO(PenanceMode)] + 0x16);
                FsFontSetScale(0.9f, 0.9f);
            } else {
                DrawMessage(8);
                DrawMessage(GameSt[GMO(PenanceMode)] + 9);
            }
            if (TitleMng[TMO(SelectMode)] == 3) {
                FsFontSetScale(1.0f, 1.0f);
                DrawMessage(0x19);
                FsFontSetScale(0.9f, 0.9f);
            } else {
                DrawMessage(0xc);
            }
        } else {
            short CursorX[5] = {0x112, 0x132, 0x166, 0x19a, 0x1ba};
            short CursorY[5] = {0x104, 0xf5, 0xe6, 0xd7, 0xc8};
            u_char Alpha[5] = {0, 0x30, 0x80, 0x30, 0};
            u_char Color[4] = {0x7f, 0x7f, 0x7f, 0x7f};
            int Cursor;
            int i;
            int j;
            DrawMessage(0x1a);
            for (i = 0, j = 0; i < 4; i++) {
                Cursor = (i + 6 - GameSt[GMO(GameLevel)]) % 4;
                if (i == 3) {
                    if (TitleMng[TMO(MaxLevel[0]) + GameSt[GMO(PlayerId)]] == 3) {
                        if (GameSt[GMO(GameLevel)] < 2) {
                            j = 2;
                        } else {
                            j = 0;
                        }
                    }
                }
                if (TitleMng[TMO(SelectFlag)] == 0) {
                    *(s16 *)((u8 *)TitleMessageInfo + j * 8 + 0xd8) = CursorX[Cursor];
                    *(s16 *)((u8 *)TitleMessageInfo + j * 8 + 0xda) = CursorY[Cursor];
                    Color[3] = Alpha[Cursor];
                    SetFontColor(*(FC *)Color);
                } else {
                    s16 *px = &CursorX[Cursor];
                    s16 *py = &CursorY[Cursor];
                    float t = (*(float *)(TitleMng + TMO(SelectRate)));
                    *(s16 *)((u8 *)TitleMessageInfo + j * 8 + 0xd8) = (s16)(t * (float)px[0] + (1.0f - t) * (float)px[1]);
                    *(s16 *)((u8 *)TitleMessageInfo + j * 8 + 0xda) = (s16)(t * (float)py[0] + (1.0f - t) * (float)py[1]);
                    Color[3] = (u_char)((float)Alpha[Cursor] * t + (float)Alpha[Cursor + 1] * (1.0f - t));
                    SetFontColor(*(FC *)Color);
                }
                if (TitleMng[TMO(SelectMode)] == 0 && Cursor == 2) {
                    FsFontSetScale(1.0f, 1.0f);
                    *(s16 *)((u8 *)TitleMessageInfo + j * 8 + 0xd8) -= 2;
                    *(s16 *)((u8 *)TitleMessageInfo + j * 8 + 0xda) -= 1;
                    DrawMessage(j + 0x1b);
                    *(s16 *)((u8 *)TitleMessageInfo + j * 8 + 0xd8) += 2;
                    *(s16 *)((u8 *)TitleMessageInfo + j * 8 + 0xda) += 1;
                    FsFontSetScale(0.9f, 0.9f);
                } else {
                    DrawMessage(j + 0x1b);
                }
                j++;
            }
            Color[3] = 0x80;
            SetFontColor(*(FC *)Color);
            if (TitleMng[TMO(SelectMode)] == 1) {
                FsFontSetScale(1.0f, 1.0f);
                DrawMessage(0x21);
                FsFontSetScale(0.9f, 0.9f);
            } else {
                DrawMessage(0x1f);
            }
        }
        if (TitleMng[TMO(SelectFlag)] == 0) {
            FsFontSetScale(0.8f, 0.8f);
            switch (TitleMng[TMO(SelectMode)]) {
            case 0:
                DrawMessage(GameSt[GMO(GameLevel)] + 0x25);
                break;
            case 1:
                if (TitleMng[TMO(MaxEquip)] != 0) {
                    DrawMessage(GameSt[GMO(StartEquip)] + 0x29);
                    break;
                } else {
                    DrawMessage(0x2e);
                    break;
                }
            case 2:
                DrawMessage(GameSt[GMO(PenanceMode)] + 0x2b);
                break;
            case 3:
                DrawMessage(0x2e);
            }
        }
        if (TitleMng[TMO(State)] == 0x1d) {
            FsFontSetAlignment(0x20);
            FsFontSetScale(0.83334f, 0.83334f);
            DrawMessage(0x3a);
            if (TitleMng[TMO(YesNo)] == 0) {
                FsFontSetScale(1.0f, 1.0f);
                DrawMessage(0x3d);
                FsFontSetScale(0.83334f, 0.83334f);
            } else {
                DrawMessage(0x3b);
            }
            if (TitleMng[TMO(YesNo)] == 1) {
                FsFontSetScale(1.0f, 1.0f);
                DrawMessage(0x3e);
                FsFontSetScale(0.83334f, 0.83334f);
            } else {
                DrawMessage(0x3c);
            }
            FsFontSetAlignment(0x100);
        }
        FsFontSetScale(0.8f, 0.8f);
        DrawMessage(0x3f);
        FontDrawEnd();
        break;
    case 31:
    case 32:
    case 33:
    case 34:
      {
        short Pos;
        sprintf(FileName, "fe_ki_002.tm2", TitleMng[TMO(TitleNo)]);
        if ((lpTexMng = GetTexMngByName(0, FileName)) != 0) {
            lpPacket = DrawTexture(MakeTexPacket(lpPacket, lpTexMng), lpTexMng, TPO(0x370), 1.0f, 0x80, 0);
        }
        sprintf(FileName, "fe_ki_001.tm2", TitleMng[TMO(TitleNo)]);
        if ((lpTexMng = GetTexMngByName(0, FileName)) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x378), 1.0f, 0x80, 0);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x380), (float)((*(s8 *)(GameSt + GMO(Brightness))) + 0x64) / 200.0f, 0x80, 0);
            if ((*(s8 *)(GameSt + GMO(Brightness))) == 0x64) {
                Pos = 0x1a0;
            } else if ((*(s8 *)(GameSt + GMO(Brightness))) == -0x64) {
                Pos = 0xda;
            } else {
                Pos = (s16)((*(s8 *)(GameSt + GMO(Brightness))) + 0x13d);
            }
            TexPosInfo[0x388] = Pos;
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPO(0x388), 1.0f, 0x80, 0x14);
        }
        FontDrawBegin(0);
        FsFontSetScale(0.75f, 0.75f);
        DrawMessage(0x2f);
        if (TitleMng[TMO(State)] >= 0x21) {
            FsFontSetScale(0.9f, 0.9f);
            FsFontSetAlignment(0x20);
            DrawMessage(0x30);
            FsFontSetAlignment(0x100);
        }
        {
            FC fcw = {0x7f, 0x7f, 0x7f, 0x7f};
            SetFontColor(fcw);
        }
        FsFontSetScale(0.8f, 0.8f);
        if (TitleMng[TMO(State)] >= 0x21) {
            DrawMessage(0x3f);
        } else {
            DrawMessage(0x40);
        }
        FontDrawEnd();
        break;
      }
    case 35:
    case 36:
    case 37:
        if ((lpTexMng = GetTexMngByName(0, "story00.tm2")) != 0) {
            lpPacket = TitleDraw__bg(lpPacket, lpTexMng);
        }
        if (TitleMng[TMO(State)] < 0x24) {
            break;
        }
        {
            int i;
            float w;
            float h;
            float y;
            u_char Color[4] = {0x7f, 0x7f, 0x7f, 0x7f};
            u_short *lpMsg;
            const float k = 0.3f;
            FontDrawBegin(0);
            FsFontSetScale(0.8f, 0.8f);
            i = 0;
            do {
                y = 300.0f + 24.0f * (float)i - k * (float)(*(s16 *)(TitleMng + TMO(Counter)));
                if (y <= 300.0f) {
                    if (!(y < 100.0f)) {
                        if (y > 280.0f) {
                            Color[3] = (u_char)(127.0f * (1.0f - ((y - 280.0f) / 20.0f)));
                        } else if (y < 120.0f) {
                            Color[3] = (u_char)((127.0f * (y - 100.0f)) / 20.0f);
                        } else {
                            Color[3] = 0x7f;
                        }
                        SetFontColor(*(FC *)Color);
                        lpMsg = KnMsgMng_GetMsgStr(i + 0x1d588);
                        if (lpMsg != 0) {
                            FsFontGetSize(&w, &h, lpMsg, 0);
                            FontPrintXY(0.5f * (512.0f - w), y, (char *)lpMsg);
                        }
                    }
                }
                i++;
            } while (i < 0x1a);
            FontDrawEnd();
        }
        break;
    case 38:
    case 39:
    case 40:
        FontDrawBegin(0);
        FsFontSetAlignment(0x20);
        FsFontSetScale(0.83334f, 0.83334f);
        DrawMessage(0x31);
        FsFontSetAlignment(0x100);
        FontDrawEnd();
        break;
    case 44:
        if ((lpTexMng = GetTexMngByName(0, "fe_me_0019.tm2")) != 0) {
            lpPacket = MakeTexPacket(lpPacket, lpTexMng);
            lpPacket = DrawTexture(lpPacket, lpTexMng, TPI(TitleMng[TMO(YesNo)] + 0x6c), 1.0f, TitleMng[TMO(StartAlpha)], 1);
        }
        FontDrawBegin(0);
        FsFontSetAlignment(0x20);
        FsFontSetScale(0.83334f, 0.83334f);
        DrawMessage(TitleMng[TMO(MsgNo)]);
        if (TitleMng[TMO(YesNo)] == 0) {
            FsFontSetScale(1.0f, 1.0f);
            DrawMessage(0x38);
            FsFontSetScale(0.83334f, 0.83334f);
        } else {
            DrawMessage(0x36);
        }
        if (TitleMng[TMO(YesNo)] == 1) {
            FsFontSetScale(1.0f, 1.0f);
            DrawMessage(0x39);
            FsFontSetScale(0.83334f, 0.83334f);
        } else {
            DrawMessage(0x37);
        }
        FsFontSetAlignment(0x100);
        FontDrawEnd();
        break;
    case 9:
    case 10:
    case 11:
    case 21:
    case 22:
    case 23:
    case 41:
    case 42:
    case 43:
    default:
        lpPacket = TitleDraw__dim(lpPacket);
        break;
    }
    lpMdlPacketMem = (u32)lpPacket;
}

u_int *DrawSelectCursor(u_int *lpPacket, TEXMNG *lpTexMng, int Cursor) {
    TEXPOS *lpTexPosInfo;
    CURSORINFO *lpCursorInfo;
    float Scale;
    u_char Alpha;
    CURSORINFO *lpCursorNextInfo;

    lpTexPosInfo = &((TEXPOS *)TexPosInfo)[Cursor + 0xd];
    if (GameSt[0x22] == 3) {
        Cursor = (Cursor + 6 - TitleMng[6]) % 4;
    } else if (Cursor != 3) {
        Cursor = (Cursor + 4 - TitleMng[6]) % 3 + 1;
    } else {
        Cursor = 0;
        lpTexPosInfo = &((TEXPOS *)TexPosInfo)[(TitleMng[6] + 1) % 3 + 0xd];
    }
    lpCursorInfo = &((CURSORINFO *)CursorInfo)[Cursor];
    if (TitleMng[0x13] == 0) {
        if (Cursor == 0) {
            return lpPacket;
        }
        lpTexPosInfo->x = lpCursorInfo->Pos[TitleMng[4]][0];
        lpTexPosInfo->y = lpCursorInfo->Pos[TitleMng[4]][1];
        Scale = lpCursorInfo->Scale;
        Alpha = lpCursorInfo->Alpha * *(float *)(TitleMng + 0x18);
    } else {
        lpCursorNextInfo = lpCursorInfo + 1;
        lpTexPosInfo->x = *(float *)(TitleMng + 0x14) * lpCursorInfo->Pos[TitleMng[4]][0]
                        + (1.0f - *(float *)(TitleMng + 0x14)) * lpCursorNextInfo->Pos[TitleMng[4]][0];
        lpTexPosInfo->y = *(float *)(TitleMng + 0x14) * lpCursorInfo->Pos[TitleMng[4]][1]
                        + (1.0f - *(float *)(TitleMng + 0x14)) * lpCursorNextInfo->Pos[TitleMng[4]][1];
        Scale = lpCursorInfo->Scale * *(float *)(TitleMng + 0x14)
              + lpCursorNextInfo->Scale * (1.0f - *(float *)(TitleMng + 0x14));
        Alpha = *(float *)(TitleMng + 0x18)
              * (lpCursorInfo->Alpha * *(float *)(TitleMng + 0x14)
                 + lpCursorNextInfo->Alpha * (1.0f - *(float *)(TitleMng + 0x14)));
    }
    return DrawTexture(lpPacket, lpTexMng, lpTexPosInfo, Scale, Alpha, 0);
}


u_int *DrawTexture(u_int *lpPacket, TEXMNG *lpTexMng, TEXPOS *lpTexPos, float Scale,
                   u_char Alpha, u_short Mode)
{
    SPD SpriteData;
    int col[4] = { 0x80, 0x80, 0x80, 0 };
    int ScaleX;
    int ScaleY;

    col[3] = Alpha;
    if (Mode == 3) {
        SetSprite(&SpriteData, (lpTexPos->x + 4) * 512 / 640 - 0x100, lpTexPos->y - 220,
                  lpTexPos->w * 512 / 640, lpTexPos->h, col, lpTexMng->id, 0);
        Mode = 2;
    } else {
        SetSprite(&SpriteData, lpTexPos->x * 512 / 640 - 0x100, lpTexPos->y - 224,
                  lpTexPos->w * 512 / 640, lpTexPos->h, col, lpTexMng->id, 0);
    }

    SpriteData.Alpha = Mode;

    if (Scale != 1.0f) {
        ScaleX = (int)((SpriteData.ver[1][0] - SpriteData.ver[0][0]) * (1.0f - Scale) * 0.5f);
        ScaleY = (int)((SpriteData.ver[2][1] - SpriteData.ver[0][1]) * (1.0f - Scale) * 0.5f);
        if (lpTexPos->Mode == 20) {
            SpriteData.ver[1][0] -= 2.0f * ScaleX;
            SpriteData.ver[3][0] -= 2.0f * ScaleX;
        } else if (lpTexPos->Mode == 30) {
            SpriteData.ver[0][1] += ScaleY;
            SpriteData.ver[1][1] += ScaleY;
            SpriteData.ver[2][1] -= ScaleY;
            SpriteData.ver[3][1] -= ScaleY;
        } else {
            SpriteData.ver[0][0] += ScaleX;
            SpriteData.ver[1][0] -= ScaleX;
            SpriteData.ver[2][0] += ScaleX;
            SpriteData.ver[3][0] -= ScaleX;
            SpriteData.ver[0][1] += ScaleY;
            SpriteData.ver[1][1] += ScaleY;
            SpriteData.ver[2][1] -= ScaleY;
            SpriteData.ver[3][1] -= ScaleY;
        }
    }

    switch (lpTexPos->Mode) {
    case 0:
        SpriteData.uv[0][0] = SpriteData.uv[2][0] = lpTexPos->u << 4;
        SpriteData.uv[1][0] = SpriteData.uv[3][0] = (lpTexPos->u + lpTexPos->w) << 4;
        SpriteData.uv[0][1] = SpriteData.uv[1][1] = lpTexPos->v << 4;
        SpriteData.uv[2][1] = SpriteData.uv[3][1] = (lpTexPos->v + lpTexPos->h) << 4;
        break;
    case 1:
    case 30:
        SpriteData.uv[0][0] = SpriteData.uv[1][0] = lpTexPos->u << 4;
        SpriteData.uv[2][0] = SpriteData.uv[3][0] = (lpTexPos->u + lpTexPos->h) << 4;
        SpriteData.uv[1][1] = SpriteData.uv[3][1] = lpTexPos->v << 4;
        SpriteData.uv[0][1] = SpriteData.uv[2][1] = (lpTexPos->v + lpTexPos->w) << 4;
        break;
    case 2:
        SpriteData.uv[0][0] = SpriteData.uv[2][0] = (lpTexPos->u + lpTexPos->w) << 4;
        SpriteData.uv[1][0] = SpriteData.uv[3][0] = lpTexPos->u << 4;
        SpriteData.uv[0][1] = SpriteData.uv[1][1] = lpTexPos->v << 4;
        SpriteData.uv[2][1] = SpriteData.uv[3][1] = (lpTexPos->v + lpTexPos->h) << 4;
        break;
    case 3:
        SpriteData.uv[0][0] = SpriteData.uv[2][0] = lpTexPos->u << 4;
        SpriteData.uv[1][0] = SpriteData.uv[3][0] = (lpTexPos->u + lpTexPos->w) << 4;
        SpriteData.uv[0][1] = SpriteData.uv[1][1] = (lpTexPos->v + lpTexPos->h) << 4;
        SpriteData.uv[2][1] = SpriteData.uv[3][1] = lpTexPos->v << 4;
        break;
    case 4:
        SpriteData.uv[0][0] = SpriteData.uv[2][0] = (lpTexPos->u + lpTexPos->w) << 4;
        SpriteData.uv[1][0] = SpriteData.uv[3][0] = lpTexPos->u << 4;
        SpriteData.uv[0][1] = SpriteData.uv[1][1] = (lpTexPos->v + lpTexPos->h) << 4;
        SpriteData.uv[2][1] = SpriteData.uv[3][1] = lpTexPos->v << 4;
        break;
    case 10:
        SpriteData.ver[1][0] = SpriteData.ver[0][0] + 0xc00;
        SpriteData.ver[3][0] = SpriteData.ver[2][0] + 0xc00;
        SpriteData.ver[2][1] = SpriteData.ver[0][1] + 0x400;
        SpriteData.ver[3][1] = SpriteData.ver[1][1] + 0x400;
        break;
    case 11:
        SpriteData.ver[1][0] = SpriteData.ver[0][0] + 0x2000;
        SpriteData.ver[3][0] = SpriteData.ver[2][0] + 0x2000;
        SpriteData.ver[2][1] = SpriteData.ver[0][1] + 0x1c00;
        SpriteData.ver[3][1] = SpriteData.ver[1][1] + 0x1c00;
        break;
    case 12:
        SpriteData.ver[1][0] = SpriteData.ver[0][0] + 0x1f40;
        SpriteData.ver[3][0] = SpriteData.ver[2][0] + 0x1f40;
        SpriteData.ver[2][1] = SpriteData.ver[0][1] + 0x640;
        SpriteData.ver[3][1] = SpriteData.ver[1][1] + 0x640;
        break;
    }

    if (lpTexPos->Mode == 1 || lpTexPos->Mode == 21 || lpTexPos->Mode == 30) {
        lpPacket = MakeStripPacketUseSpr(&SpriteData, lpPacket);
    } else {
        lpPacket = MakeSpritePacketUseSpr(&SpriteData, lpPacket);
    }
    return lpPacket;
}
static inline u_int *TitleDraw__bg(u_int *lpPacket, TEXMNG *lpTexMng) {
    SPD Sprite;
    int w;
    int h;
    u_int *lpPacket2 = MakeTexPacket(lpPacket, lpTexMng);
    {
        int Col[4] = {0x80, 0x80, 0x80, 0x80};
        w = 1 << lpTexMng->lpTm2->tex0.TW;
        h = 1 << lpTexMng->lpTm2->tex0.TH;
        SetSprite(&Sprite, -w / 2, -h / 2, w, h, Col, lpTexMng->id, 0);
    }
    return MakeSpritePacketUseSpr(&Sprite, lpPacket2);
}

static inline u_int *TitleDraw__dim(u_int *lpPacket) {
    SPD Sprite;
    int Col[4] = {0, 0, 0, 0x60};
    SetSprite(&Sprite, -0x100, -0xe0, 0x200, 0x1c0, Col, 0, 0);
    return MakeSpritePacketUseSpr(&Sprite, lpPacket);
}
static void DrawMessage(signed int id) {
    u8 *info;
    u16 *text;
    info = (u8 *)&TitleMessageInfo[id * 2];
    text = KnMsgMng_GetMsgStr(*(s32 *)(info + 4));
    {
    u8 oldColor[4] __attribute__((aligned(4)));
    u8 shadowColor[4] __attribute__((aligned(4))) = {0};
    float width, height;
    u8 buffer[256] __attribute__((aligned(16)));
    if (text != 0) {
        switch (id) {
        case 50: case 51: case 52: case 53:
            FsFontReplaceText(buffer, text, GetNeedCluster(0));
            FontPrintXY((float)((*(s16 *)info << 9) / 640), (float)*(s16 *)(info + 2), (char *)buffer);
            break;
        case 49:
            FsFontGetSize(&width, &height, text, 0);
            FontPrintXY(0.5f * (512.0f - width), 0.5f * (448.0f - height), (char *)text);
            break;
        default:
            GetFontColor(oldColor);
            shadowColor[3] = oldColor[3];
            SetFontColor(*(FC *)shadowColor);
            FsFontSetDisableColor();
            FontPrintXY((float)(((*(s16 *)info + 2) << 9) / 640), (float)(*(s16 *)(info + 2) + 2), (char *)text);
            FsFontSetEnableColor();
            SetFontColor(*(FC *)oldColor);
            FontPrintXY((float)((*(s16 *)info << 9) / 640), (float)*(s16 *)(info + 2), (char *)text);
        }
    }
    }
}


/* LoadTitleModel @ 0x1876E0 .. 0x187890 (0x1b0 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @2547 is the string 'menu/bnd/cloth00.bnd'
 *   literal: @2548 is the string 'title/tc001.bnd'
 *   literal: @2549 is the string 'title/tc002.bnd'
 *   literal: @2550 is the string 'title/tc003.bnd'
 *   literal: @2023 -> 0x22c280
 *   literal: @2025 -> 0x22c290
 *   fpu: float literal 0x3edf66f4 at 0x1877f8
 *   fpu: float literal 0x40400000 at 0x187854
 *   stack: address of the slot at 0x50 escapes at 0x187858
 *   stack: address of the slot at 0x40 escapes at 0x187870
 *   literal: @2025 initializes the 16-byte local at 0x40
 *   literal: @2023 initializes the 16-byte local at 0x50
 *   cfg: loop body is not one contiguous region: .L001877B8
 */


static void LoadTitleModel(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u8 *s0;
    s32 s2;
    u8 *s1;
    float f12;

    a0 = (u32)"menu/bnd/cloth00.bnd";
    ReadMdlBndFile("menu/bnd/cloth00.bnd", 0x7f, (void *)0);
    a0 = (u32)"title/tc001.bnd";
    ReadMdlBndFile("title/tc001.bnd", 0x7c, (void *)0);
    a0 = (u32)"title/tc002.bnd";
    ReadMdlBndFile("title/tc002.bnd", 0x7d, (void *)0);
    v1 = TitleMng[8];
    if (v1 == (u32)3) {
        a0 = (u32)"title/tc003.bnd";
        ReadMdlBndFile("title/tc003.bnd", 0x7e, (void *)0);
    }
    FileReadControl(0);
    a1 = (u32)(u8 *)(MdlData + 0xce60);
    v0 = *(s32 *)((a1 + 0x10));
    s0 = (u8 *)(MdlMng + 0x18480);
    if (v0 != 0) {
        SetMdlMng((void *)s0, (void *)a1);
        v0 = -0x3f940000;
        *(u32 *)(s0 + 0x20) = 0;
        *(u32 *)(s0 + 0x24) = -0x3f940000 | 0xcccd;
        v0 = 0x41b970a4;
        *(u32 *)(s0 + 0x28) = 0x41b970a4;
    }
    s1 = (u8 *)(MdlMng + 0x17f40);
    s0 = (u8 *)(MdlData + 0xc980);
    s2 = 0;
    do {
        v0 = *(s32 *)(s0 + 0x10);
        if (v0 != 0) {
            SetMdlMng((void *)s1, (void *)s0);
        }
        s2 = s2 + 1;
        v0 = s2 < (s32)3;
        s1 = (u8 *)(s1 + 0x1c0);
        s0 = (u8 *)(s0 + 0x680);
    } while (v0 != 0);
    SetCharaPos(0);
    v1 = lpDrawMng;
    f12 = 0.436332345f;
    *(u32 *)((v1 + 0x248)) = 0;
    v0 = lpDrawMng;
    *(u32 *)((v0 + 0x244)) = 0;
    v0 = lpDrawMng;
    *(u32 *)((v0 + 0x240)) = 0;
    v0 = lpDrawMng;
    *(u32 *)((v0 + 0x238)) = 0;
    v0 = lpDrawMng;
    *(u32 *)((v0 + 0x234)) = 0;
    v0 = lpDrawMng;
    *(u32 *)((v0 + 0x230)) = 0;
    SetCameraFov(0.436332345f);
    DrawCalcView();
    InitPointLight();
    v0 = 0x22c280;
    f12 = 3.0f;
    {
        struct stackFrame_50 { u8 b[16]; } stackFrame_50 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x80, 0x3f, 0x66, 0x66, 0x66, 0x3f, 0xcd, 0xcc, 0x4c, 0x3f, 0x00, 0x00, 0x80,
            0x3f}};
        SetPointLightOn(0, (float *)((u8 *)&stackFrame_50), 3.0f);
        v0 = 0x22c290;
        {
            struct stackFrame_40 { u8 b[16]; } stackFrame_40 __attribute__((aligned(16))) = {{0x0a,
                0xd7, 0xa3, 0x3d, 0x0a, 0xd7, 0xa3, 0x3d, 0x0a, 0xd7, 0xa3, 0x3d, 0x00, 0x00, 0x80,
                0x3f}};
            SetAmbientColor((float *)((u8 *)&stackFrame_40));
            return;
        }
    }
}


/* SetCharaPos @ 0x187540 .. 0x1876D8 (0x198 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x40 escapes at 0x1875b8
 *   delay: lui at 0x187654 writes a register its branch at 0x187650 reads
 *   cfg: loop body is not one contiguous region: .L001875B8
 *   cfg: loop body is not one contiguous region: .L00187640
 *   declaration vs inferred signature: return void vs inferred u32
 */


static void SetCharaPos(signed int a0 /* r4 */) {
    u32 v1;
    u32 a1;
    u8 *s2;
    s32 s1;
    u32 s0;
    float f0;
    s32 v0;
    s32 a2;
    u8 stackFrame[16] __attribute__((aligned(16)));

    a1 = TitleMng[8];
    s2 = (u8 *)MdlMng + 0x17f40;
    if (a1 == (u32)3) {
        v1 = -0x41000000;
        a1 = 0x3f000000;
        *(u32 *)((u8 *)&stackFrame[0]) = -0x41000000;
        *(u32 *)((u8 *)&stackFrame[4]) = 0x3f000000;
        v1 = 0x3d4ccccd;
        *(u32 *)((u8 *)&stackFrame[8]) = 0x3d4ccccd;
    } else {
        v1 = -0x41670000;
        *(u32 *)((u8 *)&stackFrame[0]) = -0x41670000 | 0x999a;
        v1 = 0x3e99999a;
        *(u32 *)((u8 *)&stackFrame[4]) = 0x3e99999a;
    }
    s1 = 0;
    if ((u32)(s32)a0 == 0) {
        s0 = (u32)((u8 *)&stackFrame[0]);
        do {
            v1 = *(u8 *)s2;
            if (v1 != 0) {
                *(u8 *)(s2 + 2) = 0;
                v1 = *(s32 *)(s2 + 0x154);
                if (v1 == 0) {
                    f0 = *(float *)s0;
                    v1 = 0x3f800000;
                    v0 = 0x40a00000;
                    a2 = 1;
                    a0 = (signed int)s2;
                    a1 = (u32)g_UnitMat;
                    *(f32 *)(s2 + 0x20) = f0;
                    *(u32 *)(s2 + 0x24) = 0x3f800000;
                    *(u32 *)(s2 + 0x28) = 0x40a00000;
                    *(u32 *)(s2 + 0x154) = a2;
                    CsMngRtaSetMat(a0, g_UnitMat, a2);
                    PlayMi3((void *)(u32)s2);
                    CsMngStabilize((u32)s2, 0x1e);
                }
            }
            s1 = s1 + 1;
            v1 = s1 < (s32)3;
            s0 = s0 + 4;
            s2 = (u8 *)(s2 + 0x1c0);
        } while (v1 != 0);
        return;
    }
    s0 = 0;
    do {
        v1 = *(u8 *)s2;
        if (v1 != 0) {
            v1 = GameSt[0x14];
            if (s0 == v1) {
                v1 = -0x41340000;
                v0 = 0x3f990000;
                *(u32 *)(s2 + 0x20) = -0x41340000 | 0xcccd;
                v0 = 0x40800000;
                *(u32 *)(s2 + 0x24) = 0x3f990000 | 0x999a;
                *(u32 *)(s2 + 0x28) = 0x40800000;
                a0 = (s32)s2;
                a1 = (u32)g_UnitMat;
                *(u32 *)(s2 + 0x154) = 0;
                CsMngRtaSetMat(a0, g_UnitMat, (s32)1);
                PlayMi3((void *)(u32)(s32)s2);
                CsMngStabilize((s32)s2, 0x1e);
            } else {
                *(u8 *)(s2 + 2) = 1;
            }
        }
        s0 = s0 + 1;
        v1 = (s32)s0 < (s32)3;
        s2 = (u8 *)(s2 + 0x1c0);
    } while (v1 != 0);
    return;
}


/* DrawTitleModel @ 0x187470 .. 0x18753C (0xcc bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001874E8
 *   return without a value in a non-void function
 */


static u32 DrawTitleModel(void) {
    u8 v0;
    u8 *s0;
    s32 s1;
    u32 v1;

    GameSt[5] = 2;
    KnMenuWindMng_Update();
    CsMngUpdate();
    CsMngDraw();
    SetPointLight(0);
    s0 = (u8 *)MdlMng + 0x18480;
    v0 = *(u8 *)s0;
    if ((u32)v0 != 0) {
        PlayMi3((void *)(u32)s0);
        DrawModel((void *)(u32)s0);
    }
    SetPointLight(1);
    s1 = 0;
    s0 = (u8 *)MdlMng + 0x17f40;
    do {
        v1 = *(u8 *)s0;
        if (v1 != 0 && (u32)*(u8 *)(s0 + 2) == 0) {
            PlayMi3((void *)(u32)s0);
            DrawModel((void *)(u32)s0);
        }
        s1 = s1 + 1;
        v1 = s1 < (s32)3;
        s0 = (u8 *)(s0 + 0x1c0);
    } while (v1 != 0);
    GameSt[5] = 0;
    return;
}









/* SetPointLight @ 0x187330 .. 0x187464 (0x134 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: lui at 0x187348 writes a register its branch at 0x187344 reads
 *   delay: addiu at 0x187358 writes a register its branch at 0x187354 reads
 *   cfg: kept branch: 0x1873fc if (..) goto .L00187438
 *   cfg: kept goto: 0x187410 -> .L00187458
 *   a0 forwarded to SetScreenPointLight
 */


static void SetPointLight(signed int a0 /* r4 */) {
    u32 v1;
    u32 a1;
    u32 v0;

    v1 = *(u8 *)TitleMng;
    if ((s32)v1 < (s32)0x1b) {
        v1 = 2;
        a1 = *(u8 *)((u8 *)&GameSt + 0x14);
        switch (a1) {
        case 0:
            a1 = (u32)((u8 *)TexPosInfo + 0x160);
            SetScreenPointLight(a0, (void *)a1);
            break;
        case 1:
            a1 = (u32)((u8 *)TexPosInfo + 0x1a0);
            SetScreenPointLight(a0, (void *)a1);
            break;
        case 2:
            a1 = (u32)((u8 *)TexPosInfo + 0x1e0);
            SetScreenPointLight(a0, (void *)a1);
            break;
        }
    } else {
        v0 = 0x1d;
        if (v1 == v0) {
            v1 = *(u8 *)((u8 *)&TitleMng + 0x33);
            v0 = (u32)TexPosInfo;
            v1 = v1 + 0x6a;
            v1 = v1 << 4;
            a1 = (s32)((u8 *)TexPosInfo + v1);
            SetScreenPointLight(a0, (void *)a1);
        } else {
            v0 = *(u8 *)((u8 *)&TitleMng + 0xc);
            if (v0 == 0) {
                v0 = *(u8 *)((u8 *)&TitleMng + 0xd);
                if (v0 == 0) {
                    goto _L00187438;
                }
            }
            v1 = *(u8 *)((u8 *)&TitleMng + 0xe);
            v0 = (u32)TexPosInfo;
            v1 = v1 + 0x56;
            v1 = v1 << 4;
            a1 = (s32)((u8 *)TexPosInfo + v1);
            SetScreenPointLight(a0, (void *)a1);
            goto _L00187458;
            _L00187438:;
            v1 = *(u8 *)((u8 *)&TitleMng + 0xe);
            v0 = (u32)TexPosInfo;
            v1 = v1 + 0x5a;
            v1 = v1 << 4;
            a1 = (s32)((u8 *)TexPosInfo + v1);
            SetScreenPointLight(a0, (void *)a1);
        }
    }
    _L00187458:;
    return;
}
static void SetScreenPointLight(signed int mode, void *info)
{
    s16 *p = (s16 *)info;
    float pos[4] __attribute__((aligned(16)));
    float f21, f20;
    float r;

    if (mode == 0) {
        if (*(u8 *)((u8 *)info + 0xc) == 10) {
            pos[0] = (float)(p[0] + 0x60) / 64.0f - 5.0f;
            pos[1] = (float)(p[1] + 0x20) / 64.0f - 3.5f;
        } else {
            pos[0] = (float)(p[0] + p[2] / 2) / 64.0f - 5.0f;
            pos[1] = (float)(p[1] + p[3] / 2) / 64.0f - 3.5f;
        }
        pos[2] = 20.0f;
        f20 = 1.0f;
        pos[3] = 1.0f;
        f21 = 3.0f;
    } else {
        if (*(u8 *)((u8 *)info + 0xc) == 10) {
            f20 = 1.0f;
            pos[0] = (float)(p[0] + 0x60) / 320.0f - 1.0f;
            pos[1] = (float)(p[1] + 0x20) / 320.0f - 0.7f;
        } else {
            f20 = 1.0f;
            pos[0] = (float)(p[0] + p[2] / 2) / 320.0f - 1.0f;
            pos[1] = (float)(p[1] + p[3] / 2) / 320.0f - 0.7f;
        }
        if (TitleMng[0] < 0x1b) pos[2] = 4.0f;
        else pos[2] = 3.0f;
        f21 = 0.8f;
        pos[3] = f20;
    }
    if (0) dcomp_mul(1.0, 2.0);
    UpdatePointLightPos(0, pos);
    pl_a_2126 = pl_a_2126 + 0.6f * (float)pow((double)(0.01f * (float)(rand() % 100)), 4.0);
    if (pl_a_2126 > 3.1415927f) pl_a_2126 = pl_a_2126 - 3.1415927f;
    r = (float)pow((double)sinf(pl_a_2126), 2.0);
    UpdatePointLightRadius(0, f21 * (f20 + 0.06f * r));
}

static double dcomp_mul(double x, double y) { return x * y; }
