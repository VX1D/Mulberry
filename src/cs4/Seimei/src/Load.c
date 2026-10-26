#include "common.h"

extern void FontDrawBegin(int);
extern s32 FsFontSetScale(float,float);
extern s32 FsFontSetPiecesParam(u8,u32);
extern u32 KnMsgMng_GetMapNameMsg();
extern s32 FsFontGetSize(float *,float *,u16 *,u16);
extern void SetFontColor(s32);
extern void FsFontSetDisableColor();
extern void FontPrintXY(float,float,char *,...);
extern void FsFontSetEnableColor();
extern void FontDrawEnd();
extern void * GetTexMngByName(void *, char *);
extern u32 LoadingFileName[];
extern void SetSceneLoad(unsigned short, unsigned short);
extern u8 GameSt[];
static u16 LoadSceneAndCamera[0xc] = {
    0x24, 0, 0, 0, 0x5a, 0, 0, 0, 0x57
};
extern void MGFreeTexture(void);
extern void MGFreeModel(void);
extern signed int SND_SecRemoveMap(void);
extern void MGLoadTexture(void);
extern void MGLoadModel(void);
extern signed int SND_SecLoadMap(signed int);
extern void SFX_DeleteAll(signed int);
extern void ReadEneParam(void);
extern void LoadDebugParam(void);
extern void LoadGameTexture(void);
static f32 Scroll_1216;
static u32 Load_1056;
extern signed int KnMenuMng_ReMakeMenu(int);
extern void FreeAllMyEquip(void);
extern void MyFree(void);
extern signed int SND_SecRemovePlayer(void);
extern signed int KnMsgMng_MsgAllClear(void);
extern int TmpMenuMng_SetUDBlackDraw(void *, int);
extern u32 g_TmpMenuMng[];
extern void InitMyEquip(void);
extern void ReadMyMdl(void);
extern signed int SND_SecLoadPlayer(signed int);
extern signed int KnMenuMng_ReLoadMenu(int);
static void DrawMapTitle(s32 time);
void FreeLoadingTexture(void);
void SetInitLoadScene(void);
void FreeMiniGameData(void);
void LoadMiniGameData(void);
void FreePrevTitleLoop(void);
u32 LoadPrevTitleLoop(void);
void FreePrevGameLoop(void);
void LoadPrevGameLoop(void);

/* LoadPrevGameLoop @ 0x13A2C0 .. 0x13A2FC (0x3c bytes, frame 0x10) */


void LoadPrevGameLoop(void) {
    u8 v0;

    InitMyEquip();
    ReadMyMdl();
    v0 = GameSt[0x14];
    SND_SecLoadPlayer((u32)(v0) + 1);
    KnMenuMng_ReLoadMenu(0x4000);
    return;
}


/* FreePrevGameLoop @ 0x13A270 .. 0x13A2BC (0x4c bytes, frame 0x10) */


void FreePrevGameLoop(void) {
    u32 a0;

    KnMenuMng_ReMakeMenu(0x64);
    FreeAllMyEquip();
    MyFree();
    SND_SecRemovePlayer();
    KnMsgMng_MsgAllClear();
    a0 = (u32)g_TmpMenuMng;
    TmpMenuMng_SetUDBlackDraw((void *)g_TmpMenuMng, 2);
    return;
}


/* LoadPrevTitleLoop @ 0x13A220 .. 0x13A264 (0x44 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u32 LoadPrevTitleLoop(void) {
    u32 v1;

    v1 = Load_1056;
    if (v1 == 0) {
        ReadEneParam();
        LoadDebugParam();
        LoadGameTexture();
        v1 = 1;
        Load_1056 = v1;
    }
    return;
}








/* FreePrevTitleLoop @ 0x13A210 .. 0x13A218 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j SFX_DeleteAll at 0x13a210 leaves the function
 *   return value dropped, call kept: the function is void
 */


void FreePrevTitleLoop(void) {
    SFX_DeleteAll(1);
    return;
}


/* LoadMiniGameData @ 0x13A1E0 .. 0x13A20C (0x2c bytes, frame 0x10) */


void LoadMiniGameData(void) {
    MGLoadTexture();
    MGLoadModel();
    SND_SecLoadMap(0x3e8);
    return;
}









/* FreeMiniGameData @ 0x13A1B0 .. 0x13A1DC (0x2c bytes, frame 0x10) */


void FreeMiniGameData(void) {
    MGFreeTexture();
    MGFreeModel();
    SND_SecRemoveMap();
    return;
}







/* SetInitLoadScene @ 0x13A180 .. 0x13A1B0 (0x30 bytes) */
/*
 * dcomp notes:
 *   tail: j SetSceneLoad at 0x13a1a8 leaves the function
 */


void SetInitLoadScene(void) {
    u16 a1;
    u32 a0;
    u16 *v1;
    u16 *v0;

    a0 = GameSt[0x14];
    v1 = LoadSceneAndCamera;
    v0 = (u16 *)(u8 *)(LoadSceneAndCamera + 2);
    a0 = a0 << 3;
    v1 = (u16 *)((u8 *)LoadSceneAndCamera + (u32)a0);
    a1 = *(u16 *)(u16 *)((u8 *)v0 + (u32)a0);
    a0 = *(u16 *)v1;
    SetSceneLoad(a0, a1);
    return;
}








extern int sprintf(char *, const char *, ...);
extern s32 FileRead(char *, s32, u8 **, u8, s32, s32, u32);
extern void SetTm2Data(void *, void *, char *);
extern void ResetVramAddr();
static void *lpLoading1Tm2;
static void *lpLoading2Tm2;
void LoadLoadingTexture(void) {
    s32 map = GameSt[9];
    s32 index;
    if (map != 0x5a) {
        if (map != 0x29) {
            if (map != 0x24) {
                index = 4;
                if (GameSt[5] != 4) goto choose;
            }
        }
    }
    index = 0;
    goto read;
choose:
    if (map >= 0x51) index = 7;
    else if (map >= 0x47) index = 6;
    else if (map >= 0x33) index = 5;
    else if (map >= 0x28) index = 4;
    else if (map >= 0x1f) index = 3;
    else if (map >= 0x15) index = 2;
    else index = 0;
read:
    sprintf((char *)LoadingFileName,"tex/load/load%03d.tm2",index);
    do {
        index = FileRead((char *)LoadingFileName,0x40420,(u8 **)&lpLoading1Tm2,1,-1,0x81,0);
        index = (index != 0) ^ 1;
    } while (index != 0);
    ((struct { unsigned char pad:5; unsigned char flag:3; } *)((u8 *)lpLoading1Tm2+0x17))->flag = 1;
    SetTm2Data(0,lpLoading1Tm2,(char *)LoadingFileName);
    ResetVramAddr();
    if (*(s32 *)lpLoading2Tm2 == 0) {
        do {
            index = FileRead("tex/load/load001.tm2",0x40420,(u8 **)&lpLoading2Tm2,1,-1,0x81,0);
            index = (index != 0) ^ 1;
        } while (index != 0);
        ((struct { unsigned char pad:5; unsigned char flag:3; } *)((u8 *)lpLoading2Tm2+0x17))->flag = 1;
    }
    SetTm2Data(0,lpLoading2Tm2,"tex/load/load001.tm2");
    ResetVramAddr();
}






/* FreeLoadingTexture @ 0x139F20 .. 0x139F74 (0x54 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   literal: @1283 is the string 'tex/load/load001.tm2'
 *   declaration vs inferred signature: return void vs inferred u8 *
 */


void FreeLoadingTexture(void) {
    u8 *a1;
    u8 *v0;

    a1 = (u8 *)LoadingFileName;
    v0 = (u8 *)GetTexMngByName((void *)0, (char *)LoadingFileName);
    if ((u32)v0 != 0) {
        *(u8 *)v0 = 0;
    }
    a1 = (u8 *)"tex/load/load001.tm2";
    v0 = (u8 *)GetTexMngByName((void *)0, "tex/load/load001.tm2");
    if ((u32)v0 != 0) {
        *(u8 *)v0 = 0;
    }
    return;
}










extern void SetFadeMng(unsigned char, signed int *, signed int, void *, void *, signed int, signed int);
extern void KickMdlPacket();
extern u32 CheckFadeEnd();
extern int FileCheckAsyncBusy(void);
extern void PadUpdate();
extern void DrawLoading();
extern void DrawBrightnessFilter();
extern void UpdateFadeMng();
extern void FileBackReadControl();
extern void SND_Update();
extern void DrawSynch();
extern void InitFadeControl();
void LoadingLoop(void) {
    u32 state = 1;
    u16 title = 200;
    {
        s32 color[4] __attribute__((aligned(16))) = {0};
        SetFadeMng(0,color,30,0,0,0,0);
    }
    do {
        KickMdlPacket();
        switch (state) {
        case 1:
            if (CheckFadeEnd() != 0) state = 2;
            break;
        case 2:
            if (FileCheckAsyncBusy() == 0) {
                s32 color[4] __attribute__((aligned(16))) = {0};
                SetFadeMng(1,color,30,0,0,0,0);
                state = 3;
            }
            break;
        case 3:
            if (CheckFadeEnd() != 0) {
                s32 color[4] __attribute__((aligned(16))) = {0};
                SetFadeMng(0,color,30,0,0,0,0);
                state = 0;
            }
            break;
        }
        PadUpdate();
        DrawLoading();
        DrawBrightnessFilter();
        if (GameSt[5] != 4) {
            void DrawMapTitle(u16);
            DrawMapTitle(title);
            if (title > 2) title -= 2;
            else title = 0;
        }
        UpdateFadeMng();
        FileBackReadControl();
        SND_Update();
        DrawSynch();
    } while (state != 0);
    InitFadeControl();
}












/* DrawLoading @ 0x139AF0 .. 0x139D1C (0x22c bytes, frame 0x130) */
/*
 * dcomp notes:
 *   quad: t2: 128-bit web split from its scalar uses
 *   literal: @1214 -> 0x2286e0
 *   literal: @1283 is the string 'tex/load/load001.tm2'
 *   stack: address of the slot at 0x40 escapes at 0x139bcc
 *   stack: address of the slot at 0x30 escapes at 0x139bcc
 *   fpu: float literal 0x3a83126f at 0x139c04
 *   fpu: float literal 0x3f800000 at 0x139c10
 *   stack: address of the slot at 0x40 escapes at 0x139c98
 *   stack: address of the slot at 0x30 escapes at 0x139c98
 *   literal: @1214 initializes the 16-byte local at 0x30
 */

extern void SetSprite(void *, signed int, signed int, signed int, signed int, signed int *,
    unsigned short, unsigned char);
extern unsigned int * MakeTexPacket(unsigned int *, void *);
extern unsigned int * MakeSpritePacketUseSpr(void *, unsigned int *);
extern u32 L1214[];
extern u32 lpMdlPacketMem;


typedef struct {
    u16 bUse : 1; u16 Fst : 1; u16 Alpha : 2; u16 LoadOff : 1; u16 unused : 11;
    u16 texID; u8 pad0[12];
    int ver[4][4]; int col[4][4];
    union { int uv[4][4]; float st[4][4]; };
    u8 tex0[8]; u8 tex1[8]; u8 test[8]; u8 pad1[8];
} dlSPD;
typedef struct { u8 bUse; u8 unused0; u16 id; void *lpTm2; } dlTEXMNG;
typedef struct { unsigned long TBP0:14,TBW:6,PSM:6,TW:4,TH:4,TCC:1,TFX:2,CBP:14,CPSM:4,CSM:1,CSA:5,CLD:3; } dlTex0Bits;
typedef struct { u8 pad0[16]; dlTex0Bits tex0; } dlTm2;
void DrawLoading(void) {
    dlSPD SpriteData;
    dlTEXMNG *lpTexMng;
    int w;
    int h;
    int col[4] = {0x80, 0x80, 0x80, 0x80};
    u32 *lpPacket;
    float Scroll;

    lpPacket = (u32 *)lpMdlPacketMem;
    lpPacket[0] = 0x10000000 | 2;
    lpPacket[1] = 0;
    lpPacket[2] = 0;
    lpPacket[3] = 0x51000000 | 2;
    lpPacket[4] = 0x8001;
    lpPacket[5] = 0x10000000;
    lpPacket[6] = 0xe;
    lpPacket[7] = 0;
    *(u64 *)(lpPacket + 8) = 0;
    *(s64 *)(lpPacket + 10) = 8;
    lpTexMng = (dlTEXMNG *)GetTexMngByName((void *)0, (char *)LoadingFileName);
    w = 1 << ((dlTm2 *)lpTexMng->lpTm2)->tex0.TW;
    h = 1 << ((dlTm2 *)lpTexMng->lpTm2)->tex0.TH;
    SetSprite(&SpriteData, -w / 2, -h / 2, w, h, col, lpTexMng->id, 0);
    lpPacket = MakeTexPacket(lpPacket + 12, lpTexMng);
    lpPacket = MakeSpritePacketUseSpr(&SpriteData, lpPacket);
    col[3] = 0x40;
    Scroll_1216 = Scroll_1216 + 0.001f;
    if (!(Scroll_1216 < 1.0f)) {
        Scroll_1216 = 0.0f;
    }
    lpTexMng = (dlTEXMNG *)GetTexMngByName((void *)0, "tex/load/load001.tm2");
    w = 1 << ((dlTm2 *)lpTexMng->lpTm2)->tex0.TW;
    h = 1 << ((dlTm2 *)lpTexMng->lpTm2)->tex0.TH;
    SetSprite(&SpriteData, -w / 2, -h / 2, w, h, col, lpTexMng->id, 1);
    lpPacket = MakeTexPacket(lpPacket, lpTexMng);
    Scroll = Scroll_1216;
    SpriteData.Alpha = 2;
    SpriteData.st[0][0] = SpriteData.st[0][0] + Scroll;
    SpriteData.st[0][1] = SpriteData.st[0][1] - Scroll;
    SpriteData.st[3][0] = SpriteData.st[3][0] + Scroll;
    SpriteData.st[3][1] = SpriteData.st[3][1] - Scroll;
    lpMdlPacketMem = (u32)MakeSpritePacketUseSpr(&SpriteData, lpPacket);
}









extern u32 LoadingTm2Buffer[];
static void *lpLoading1Tm2 = (void *)&LoadingTm2Buffer;
static void *lpLoading2Tm2 = (void *)((u8 *)&LoadingTm2Buffer + 0x40420);

static void DrawMapTitle(s32 time) {
    s32 fade;
    u32 param;
    u32 shifted;
    u32 alpha;
    u32 alphaPtr;
    u16 *name;
    param=time;
    {
    u8 color[4]={127,127,127,127};
    u8 shadow[4]={0,0,0,127};
    float width;
    float height;
    
    shifted=time&0xffffu;
    shifted=shifted>>1;
    fade=(u8)shifted;
    if ((s32)fade<=126) {
        FontDrawBegin(0);
        FsFontSetScale(1.5f,1.5f);
        alpha=127;
        alpha-=fade;
        alphaPtr=(u32)(color+3);
        shadow[3]=alpha;
        *(u8 *)alphaPtr=alpha;
        FsFontSetPiecesParam(2,param);
        shifted=KnMsgMng_GetMapNameMsg();
        if (shifted!=0) {
            name=(u16 *)shifted;
            FsFontGetSize(&width,&height,name,0);
            SetFontColor(*(s32 *)shadow);
            FsFontSetDisableColor();
            FontPrintXY(2.0f+0.5f*(512.0f-width),182.0f,(char *)name);
            FsFontSetEnableColor();
            SetFontColor(*(s32 *)color);
            FontPrintXY(0.5f*(512.0f-width),180.0f,(char *)name);
        }
        *(u8 *)alphaPtr=127;
        SetFontColor(*(s32 *)color);
        FsFontSetPiecesParam(0,0);
        FontDrawEnd();
    }
    }
}

static u32 LoadingTm2Buffer[0x20210];
static u32 LoadingFileName[0x8];
