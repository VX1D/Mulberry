#include "common.h"

/* _MovieMessage @ 0x1956D0 .. 0x19571C (0x4c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x1956e4 if (..) goto .L00195710
 *   return without a value in a non-void function
 */

extern u32 fsmmo_Exec();
extern u32 s_pMovieMessageWork;
extern u8 s_MovieMessageEndFlag;

extern u8 GameSt[];
extern void fsmpg_RegisterCallBack(u32);
extern void MemFree(void *);
extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed int, unsigned int);
extern u32 fsmmo_GetMemorySize(s32);
extern void *MemAllocAlignReal(unsigned int, unsigned int, char *, char *);
extern void fsmmo_Initialize(s32, s32);
extern void fsmmo_SetBlurNum(s32);
extern void *memset(void *, int, unsigned int);
extern u32 fsmpg_GetRequiredBufferSize(u32, s32);
extern u32 GetRootPath();
extern int sprintf(char *, const char *, ...);
extern void StringCorrectPath4Disc(char *, signed int);
extern void SND_RebootSpu2();
extern unsigned short GetVagMasterVolume(unsigned char);
extern u32 fsmpg_Startup(s32, s32, u16, s32, u32, u32, u32);
extern void fsmpg_SetPriority(s32);
extern u32 fsmpg_MovieStart(u8 *, s32, s32, u32 (*)(void), u16, s32, u32, u32, u32);
extern void fsmpg_Quit();
extern void SND_SetVol(int, unsigned char);
extern void TransFontTex();
extern void ResetDraw();
extern void Vu1SendProg();

extern void *s_pMovieMessage;
extern u32 MoviePlay[];
static u32 CheckMoviePad(void);

/* These named objects preserve the original literal identities and alignment. */
static const char sMovieOpeningPss[] __attribute__((section(".rodata"), aligned(8))) = "opening.pss";
static const char sMovieEnding00Pss[] __attribute__((section(".rodata"), aligned(8))) = "ending00.pss";
static const char sMovieEnding01Pss[] __attribute__((section(".rodata"), aligned(8))) = "ending01.pss";
static const char sMovieEnding02Pss[] __attribute__((section(".rodata"), aligned(8))) = "ending02.pss";
static const char sMovieMidPss[] __attribute__((section(".rodata"), aligned(8))) = "mid.pss";
static const char sMovieEnding0ePss[] __attribute__((section(".rodata"), aligned(8))) = "ending0e.pss";
static const char sMovieEnding1ePss[] __attribute__((section(".rodata"), aligned(8))) = "ending1e.pss";
static const char sMovieEnding2ePss[] __attribute__((section(".rodata"), aligned(8))) = "ending2e.pss";
static const char sMovieMidePss[] __attribute__((section(".rodata"), aligned(8))) = "mide.pss";
static const char sMovieEmpty[16] __attribute__((section(".rodata"), aligned(8))) = {0};
static const char sMovieEnding00Mso[] __attribute__((section(".rodata"), aligned(16))) = "mso/us/ending00.mso";
static const char sMovieEnding01Mso[] __attribute__((section(".rodata"), aligned(16))) = "mso/us/ending01.mso";
static const char sMovieEnding02Mso[] __attribute__((section(".rodata"), aligned(16))) = "mso/us/ending02.mso";
static const char sMovieMidMso[] __attribute__((section(".rodata"), aligned(8))) = "mso/us/mid.mso";
static const char sMovieInitName[] __attribute__((section(".rodata"), aligned(8))) = "InitMovie";
static const char sMovieMessageName[] __attribute__((section(".rodata"), aligned(16))) = "SetMovieMessageMovie";
static const char sMoviePathFormat[] __attribute__((section(".rodata"), aligned(8))) = "%s%s";

static const char *MovieFilePath[5] __attribute__((section(".data"), aligned(16))) = {
    sMovieOpeningPss, sMovieEnding00Pss, sMovieEnding01Pss, sMovieEnding02Pss, sMovieMidPss
};
static const char *MovieFilePathEnglish[5] __attribute__((section(".data"), aligned(16))) = {
    sMovieOpeningPss, sMovieEnding0ePss, sMovieEnding1ePss, sMovieEnding2ePss, sMovieMidePss
};
static const char *MovieMessagePath[5] __attribute__((section(".data"), aligned(16))) = {
    sMovieEmpty, sMovieEnding00Mso, sMovieEnding01Mso, sMovieEnding02Mso, sMovieMidMso
};

static inline signed int SetKuonMovie__inl0(u32 s0) {
    u32 a2;
    u32 v0;
    signed int a0_2;

    v0 = (u32)s_pMovieMessage;
    if (v0 != 0) {
        fsmpg_RegisterCallBack(0);
        a0_2 = (signed int)s_pMovieMessage;
        if (a0_2 != 0) {
            MemFree((void *)a0_2);
        }
        a0_2 = s_pMovieMessageWork;
        if (a0_2 != 0) {
            MemFree((void *)a0_2);
        }
        s_pMovieMessage = 0;
        s_pMovieMessageWork = 0;
    } else {
        a0_2 = 0;
    }
    v0 = (u32)MovieMessagePath;
    a2 = (u32)&s_pMovieMessage;
    FileRead((char *)*(s32 *)(u32)(s32)(u32)&((struct { u8 b[4]; } *)MovieMessagePath)[s0], -1,
        (unsigned char **)&s_pMovieMessage, 1, 0, 0x20, 0x10);
    a0_2 = (signed int)s_pMovieMessage;
    return a0_2;
}

static inline void SetKuonMovie__inl1(void) {
    signed int a0_2;

    fsmpg_RegisterCallBack(0);
    a0_2 = (signed int)s_pMovieMessage;
    if (a0_2 != 0) {
        MemFree((void *)a0_2);
    }
    a0_2 = s_pMovieMessageWork;
    if (a0_2 != 0) {
        MemFree((void *)a0_2);
    }
    s_pMovieMessage = 0;
    s_pMovieMessageWork = 0;
}

static inline signed int SetKuonMovie__playMovie(u32 s0, const char **pathTable) {
    u32 a3;
    u32 a2;
    u32 a1;
    u32 v0;
    u32 s2;
    signed int a0_2;
    u8 stackFrame_0[16] __attribute__((aligned(16)));

    s2 = *(s32 *)(u32)(s32)(u32)&((struct { u8 b[4]; } *)pathTable)[s0];
    s0 = (u32)MoviePlay;
    a0_2 = (signed int)MoviePlay;
    memset((void *)MoviePlay, 0, 0x4c);
    v0 = fsmpg_GetRequiredBufferSize(2, 0);
    MoviePlay[1] = v0;
    a0_2 = *(s32 *)(s0 + 4);
    a2 = (u32)sMovieInitName;
    a3 = (u32)sMovieEmpty;
    v0 = (u32)MemAllocAlignReal(a0_2, 0x10, (char *)sMovieInitName, (char *)sMovieEmpty);
    *(u32 *)s0 = (u32)v0;
    v0 = *(s32 *)s0;
    if (v0 == 0) {
        v0 = 0;
    } else {
        v0 = 1;
        *(u8 *)(s0 + 0x48) = v0;
    }
    if (v0 == 0) {
        s0 = 0;
        return s0;
    } else {
        v0 = GetRootPath();
        a1 = (u32)sMoviePathFormat;
        sprintf((char *)(u8 *)&MoviePlay[2], (const char *)sMoviePathFormat, v0, s2);
        StringCorrectPath4Disc((char *)(u8 *)&MoviePlay[2], 1);
        SND_RebootSpu2();
        a2 = (u16)GetVagMasterVolume(0);
        a0_2 = (s32)MoviePlay[0];
        a1 = (s32)MoviePlay[1];
        v0 = fsmpg_Startup(a0_2, a1, a2, 2, 0, 0, 0);
        if (v0 == 0) {
            v0 = 0;
        } else {
            fsmpg_SetPriority(0x40);
            v0 = 1;
        }
        if (v0 == 0) {
            s0 = 0;
            return s0;
        } else {
            v0 = GetVagMasterVolume(0);
            a1 = (s32)MoviePlay[0];
            a3 = (u32)CheckMoviePad;
            a2 = (s32)MoviePlay[1];
            v0 = fsmpg_MovieStart((u8 *)&MoviePlay[2], a1, a2, CheckMoviePad, v0, 2, 0,
                0, 0);
            if ((u32)(v0 != 0) == 0) {
                s0 = 0;
                return s0;
            } else {
                fsmpg_Quit();
                SND_SetVol(0, 0x7f);
                a0_2 = (s32)MoviePlay[0];
                MemFree((void *)a0_2);
                a0_2 = (signed int)MoviePlay;
                memset((void *)MoviePlay, 0, 0x4c);
                s0 = 1;
            }
        }
    }
    return s0;
}

/* CheckMoviePad @ 0x195C50 .. 0x195C98 (0x48 bytes, frame 0x20) */

extern void PadUpdate();
extern u32 lpPadData;
static u32 MoviePlay[0x13];
static u32 s_pMovieMessageWork;
static void *s_pMovieMessage;
static u8 s_MovieMessageEndFlag;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
static u32 CheckMoviePad(void);
signed int SetKuonMovie(signed int a0 );
static u32 _MovieMessage(void);


static u32 CheckMoviePad(void) {
    u32 v0;
    u32 v1;
    u8 *s0;

    v0 = (u32)&lpPadData;
    v1 = *(u8 *)((u8 *)&GameSt + 0xa);
    s0 = (u8 *)*(s32 *)(u32)(s32)((u8 *)&lpPadData + (u32)(v1 << 2));
    PadUpdate();
    v0 = ((struct { unsigned char _pad:3; unsigned char f:1; } *)&*(u8 *)(((u8 *)s0 + 0x20)))->f;
    return v0 != 0;
}

signed int SetKuonMovie(signed int a0 /* r4 */) {
    u32 s0;
    signed int MovieMessage;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    signed int a0_2;

    s0 = a0;
    MovieMessage = s0 != 0;
    if (MovieMessage != 0) {
        a0_2 = SetKuonMovie__inl0(s0);
        if (a0_2 != 0) {
            v0 = fsmmo_GetMemorySize(a0_2);
            if (v0 != 0) {
                a0_2 = v0;
                a2 = (u32)sMovieMessageName;
                a3 = (u32)sMovieEmpty;
                v0 = (u32)MemAllocAlignReal(a0_2, 0x10, (char *)sMovieMessageName, (char *)sMovieEmpty);
                s_pMovieMessageWork = (u32)v0;
                a1 = s_pMovieMessageWork;
                if (a1 != 0) {
                    a0_2 = (signed int)s_pMovieMessage;
                    fsmmo_Initialize(a0_2, a1);
                    fsmmo_SetBlurNum(2);
                    s_MovieMessageEndFlag = 0;
                    a0_2 = (signed int)_MovieMessage;
                    fsmpg_RegisterCallBack((u32)_MovieMessage);
                }
            }
        }
    }
    v1 = GameSt[0x2c];
    v0 = 1;
    if (v1 == v0) {
        s0 = SetKuonMovie__playMovie(s0, MovieFilePathEnglish);
    } else {
        s0 = SetKuonMovie__playMovie(s0, MovieFilePath);
    }
    if (MovieMessage != 0) {
        SetKuonMovie__inl1();
    } else {
        a0_2 = 0;
    }
    if (s0 != 0) {
        TransFontTex();
        ResetDraw();
        Vu1SendProg();
    }
    return s0;
}

static u32 _MovieMessage(void) {
    u32 v1;
    u32 a0;
    u32 v0;

    v1 = s_pMovieMessageWork;
    if (v1 == 0) {
        a0 = s_MovieMessageEndFlag;
        v1 = 1;
        if (a0 == v1) {
            goto _L00195710;
        }
    }
    v0 = fsmmo_Exec();
    v1 = 1;
    if (v0 != 0) {
        s_MovieMessageEndFlag = v1;
    }
    _L00195710:;
    return;
}
