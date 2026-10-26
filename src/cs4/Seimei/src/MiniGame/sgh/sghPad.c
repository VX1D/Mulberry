#include "common.h"

/* __sghPad_Tutorial @ 0x20E9C0 .. 0x20EA98 (0xd8 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x20e9f8 writes a register its branch at 0x20e9f4 reads
 */

extern u32 sghGetGameInfo(void);
extern signed int SND_Play2D(signed int, signed short, signed short);
extern u32 lpPadData;
extern u8 gsPadInfo[];

/* __sghPad_GameEnd @ 0x20EC10 .. 0x20ED44 (0x134 bytes, frame 0x10) */

extern u8 MdlMng[];

/* __sghPad_TurnRest @ 0x20ED50 .. 0x20EDD0 (0x80 bytes, frame 0x20) */

extern void sghTime_SetWait(signed int);

enum __sghPad_TurnRest__sel { __sghPad_TurnRest__sel_0, __sghPad_TurnRest__sel_1 };


/* __sghPad_UserChoiceDice @ 0x20EDD0 */
extern void sghDice_GetDiceSpotsList(u8 *);
extern void sghMarker_MarkerClear(void);
extern void sghMarker_SetActPossible(u8,u8,u8,u8);
extern void sghKoma_SetAnime(u8,u8,u8);
extern u8 gsPadCur[];

struct DiceBit { unsigned short select : 1; unsigned short L3 : 1; unsigned short R3 : 1; unsigned short start : 1; unsigned short Lup : 1; unsigned short Lright : 1; unsigned short Ldown : 1; unsigned short Lleft : 1; unsigned short L2 : 1; unsigned short R2 : 1; unsigned short L1 : 1; unsigned short R1 : 1; unsigned short Rup : 1; unsigned short Rdown : 1; unsigned short Rright : 1; unsigned short Rleft : 1; };
union DiceBtn { struct DiceBit bit; unsigned short set; };
struct DicePressInfo { u8 Lright, Lleft, Lup, Ldown, Rup, Rright, Rdown, Rleft, L1, R1, L2, R2; };
struct DicePad { u8 success; u8 data_len; union DiceBtn button; u8 r3h, r3v, l3h, l3v; u8 apress[12]; struct DicePressInfo press; union DiceBtn edge; union DiceBtn repeat; };
struct DiceGmInfo { u8 modeID, ctrlID, gameID, dbgID, nowPlayerID, aPlayerType[2], anWin_num[2]; };
struct DiceSpots { u8 spots[2]; };
struct DiceCopy { u8 b[2]; };




extern u8 gsPadInfo[], gsPadCur[];
extern void sghDice_GetDiceSpotsList(u8 *);

extern void sghKoma_SetAnime(u8,u8,u8);
extern void sghMarker_MarkerClear(void);
extern void sghMarker_SetActPossible(u8,u8,u8,u8);
extern s32 sghMarker_GetTgtPosNum(void);


/* __sghPad_DiceCast @ 0x20F390 .. 0x20F418 (0x88 bytes, frame 0x20) */

extern void sghTime_SetWait(signed int);
extern void sghDice_CastStart();

/* __sghPad_OrderPlayerEnd @ 0x20F420 .. 0x20F520 (0x100 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x28 escapes at 0x20f460
 *   stack: address of the slot at 0x2c escapes at 0x20f4a0
 *   stack: 2-byte aggregate copy in 1-byte chunks at 0x20f480
 *   cfg: kept branch: 0x20f44c if (..) goto .L0020F508
 *   cfg: kept branch: 0x20f490 if (..) goto .L0020F4C8
 *   cfg: kept goto: 0x20f4a0 -> .L0020F510
 *   cfg: kept goto: 0x20f4f0 -> .L0020F510
 */

extern void sghDice_GetDiceSpotsList(u8 *);
extern void sghDice_Init(void);

enum __sghPad_OrderPlayerEnd_Bool { __sghPad_OrderPlayerEnd_F, __sghPad_OrderPlayerEnd_T };


/* __sghPad_Top @ 0x20F5A0 .. 0x20F60C (0x6c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u32 sghGetGameInfo(void);
extern u32 lpPadData;

/* sghPad_GetCurInfo @ 0x20F610 .. 0x20F61C (0xc bytes) */

extern u8 gsPadCur[];

/* sghPad_Init @ 0x20F630 .. 0x20F654 (0x24 bytes) */

extern u8 gsPadInfo[];

/* sghPad_Execute @ 0x20F660 .. 0x20F74C (0xec bytes, frame 0x30) */

extern signed int sghTime_GetWait(void);
extern void PadUpdate(void);
extern void *GetMGPrcStatus(void);
static void __sghPad_GamePause(void);
static void __sghPad_GamePause(void);
extern u32 gSGH_PadFnc[];
static u32 __sghPad_Top(void);
void __sghPad_OrderPlayerCast(void);
void __sghPad_OrderPlayerEnd(void);
void __sghPad_DiceCast(void);
void __sghPad_UserChoiceKoma(void);
void __sghPad_UserChoiceDice(void);
void __sghPad_TurnRest(void);
static void __sghPad_GameEnd(void);
static void __sghPad_Tutorial(void);

static u32 gSGH_PadFnc[0x1c] = {
    0, (u32)&__sghPad_Top, 0, 0, (u32)&__sghPad_OrderPlayerCast, 0,
    (u32)&__sghPad_OrderPlayerEnd, 0, 0, (u32)&__sghPad_DiceCast, 0, 0, 0,
    (u32)&__sghPad_UserChoiceKoma, 0, (u32)&__sghPad_UserChoiceDice, 0, 0,
    (u32)&__sghPad_TurnRest, 0, 0, 0, 0, 0, 0, (u32)&__sghPad_GameEnd, 0,
    (u32)&__sghPad_Tutorial
};
static u8 gsPadCur[0x34];
static u8 gsPadInfo[0x10];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void sghPad_Execute(void);
void sghPad_Init(void);
void * sghPad_GetPadInfo(void);
u8 * sghPad_GetCurInfo(void);
static u32 __sghPad_Top(void);
void __sghPad_OrderPlayerCast(void);
void __sghPad_OrderPlayerEnd(void);
void __sghPad_DiceCast(void);
void __sghPad_UserChoiceKoma(void);
void __sghPad_UserChoiceDice(void);
void __sghPad_TurnRest(void);
static void __sghPad_GameEnd(void);
static void __sghPad_GamePause(void);
static void __sghPad_Tutorial(void);


void sghPad_Execute(void) {
    u8 *a1;
    u8 *s0;
    u8 *s1;
    u32 a0;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)sghGetGameInfo();
    s0 = v0;
    sghTime_GetWait();
    PadUpdate();
    v0 = (u8 *)GetMGPrcStatus();
    s1 = v0;
    v0 = (u8 *)sghGetGameInfo();
    a0 = *(u8 *)(s1 + 1);
    v1 = 2;
    a1 = (u8 *)lpPadData;
    if (a0 != v1 && (s32)*(u8 *)v0 <= (s32)0x16) {
        v1 = *(u8 *)(a1 + 0x20);
        if ((u64)((u64)v1 << 0x3c >> 0x3f) != 0) {
            a0 = *(u8 *)(v0 + 1);
            v1 = 1;
            if (a0 != v1) {
                *(u8 *)(v0 + 1) = v1;
                *(u32 *)gsPadInfo = v1;
            } else {
                *(u8 *)(v0 + 1) = 0;
            }
        }
    }
    a0 = *(u8 *)(s0 + 1);
    v1 = 1;
    if (a0 == v1) {
        __sghPad_GamePause();
    } else {
        a0 = *(u8 *)s0;
        v1 = (u32)gSGH_PadFnc;
        v1 = (s32)(u32)&((struct { u8 b[4]; } *)gSGH_PadFnc)[a0];
        v1 = *(s32 *)v1;
        if (v1 != 0) {
            ((void (*)(void))(s32)v1)();
        }
    }
    return;
}

void sghPad_Init(void) {
    *(u8 *)((u8 *)&gsPadInfo + 0xc) = 0;
    *(u8 *)((u8 *)&gsPadInfo + 0xd) = 0;
    *(u32 *)gsPadInfo = 0;
    *(u32 *)((u8 *)&gsPadInfo + 4) = 0;
    return;
}

/* sghPad_GetPadInfo @ 0x20F620 .. 0x20F62C (0xc bytes) */



void * sghPad_GetPadInfo(void) {
    return (void *)(u8 *)gsPadInfo;
}

u8 * sghPad_GetCurInfo(void) {
    return (u8 *)gsPadCur;
}

static u32 __sghPad_Top(void) {
    u8 *v0;
    u32 v1;
    u32 a0;

    v0 = (u8 *)sghGetGameInfo();
    v1 = lpPadData;
    v1 = ((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)((v1 + 0x21)))->f;
    if (v1 != 0) {
        a0 = *(u8 *)(((u8 *)v0 + 6));
        v1 = 1;
        switch (a0) {
        case 0:
            v1 = 3;
            *(u8 *)v0 = v1;
            break;
        case 1:
            v1 = 2;
            *(u8 *)v0 = v1;
        }
    }
    return;
}


/* __sghPad_OrderPlayerCast @ 0x20F520 .. 0x20F5A0 (0x80 bytes, frame 0x20) */

void __sghPad_OrderPlayerCast(void) {
    s32 a3;
    u8 *a2;
    u8 a1;
    u32 a0;
    u32 v1;
    u8 *v0;
    u8 *s0;

    v0 = (u8 *)sghGetGameInfo();
    a1 = *(u8 *)(v0 + 4);
    a2 = (u8 *)&lpPadData;
    v1 = 1;
    a3 = (u32)a1 << 2;
    a2 = (u8 *)((u8 *)&lpPadData + a3);
    a0 = *(u8 *)((u32)&((u8 *)(v0 + 5))[a1]);
    a2 = (u8 *)*(s32 *)a2;
    s0 = v0;
    if (a0 == v1) {
        *(u8 *)s0 = 5;
    } else {
        v1 = *(u8 *)(a2 + 0x21);
        a0 = 0;
        if ((u64)((u64)v1 << 0x39 >> 0x3f) != 0) {
            sghDice_CastStart(0, a1, a2, a3);
            *(u8 *)s0 = 5;
        }
    }
    return;
}

void __sghPad_OrderPlayerEnd(void) {
    u8 *a1;
    u8 *s0;
    u64 v0_64;
    u32 a0;
    u32 v1;
    u32 v0;
    u8 stackFrame_2C[4] __attribute__((aligned(4)));
    u8 stackFrame_28[4] __attribute__((aligned(8)));
    struct __copy_u8_2 { u8 b[2]; };

    v0 = sghGetGameInfo();
    s0 = (u8 *)v0;
    v0 = *(u8 *)((lpPadData + 0x21));
    v0_64 = (u64)v0 << 0x39 >> 0x3f;
    v1 = *(s32 *)((u8 *)&lpPadData + 4);
    if (v0_64 == 0) {
        v0 = *(u8 *)((v1 + 0x21));
        v0_64 = (u64)v0 << 0x39 >> 0x3f;
        if (v0_64 == 0) {
            goto _L0020F508;
        }
    }
    sghDice_GetDiceSpotsList(((u8 *)&stackFrame_28[0]));
    v0 = (u32)((u8 *)&stackFrame_28[0]);
    a1 = ((u8 *)&stackFrame_2C[0]);
    v1 = 0xff;
    *(struct __copy_u8_2 *)((u8 *)&stackFrame_2C[0]) = *(struct __copy_u8_2 *)((u8
        *)&stackFrame_28[0]);
    a0 = *(u8 *)((u8 *)&stackFrame_2C[0]);
    if (a0 != v1) {
        v0 = ((u8 *)stackFrame_2C)[1];
        if (v0 != v1) {
            goto _L0020F4C8;
        }
    }
    v0 = 3;
    *(u8 *)s0 = v0;
    *(u8 *)(s0 + 4) = *(u8 *)(s0 + 4) == 0 ? __sghPad_OrderPlayerEnd_T : __sghPad_OrderPlayerEnd_F;
    sghTime_SetWait(0);
    goto _L0020F510;
    _L0020F4C8:;
    if (a0 == v0) {
        sghTime_SetWait(0);
        v0 = 3;
        *(u8 *)s0 = v0;
        *(u8 *)(s0 + 4) = 0;
        sghDice_Init();
    } else {
        sghTime_SetWait(0);
        v1 = 8;
        *(u8 *)s0 = v1;
        goto _L0020F510;
        _L0020F508:;
        a0 = 0xff;
        sghTime_SetWait(a0);
    }
    _L0020F510:;
    return;
}

void __sghPad_DiceCast(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    u8 *v0;
    u8 *s0;

    v0 = (u8 *)sghGetGameInfo();
    a0 = *(u8 *)(v0 + 4);
    a1 = (u32)&lpPadData;
    v1 = 1;
    a1 = (s32)(u32)&((struct { u8 b[4]; } *)&lpPadData)[a0];
    a0 = *(u8 *)((u32)&((u8 *)(v0 + 5))[a0]);
    a1 = *(s32 *)a1;
    s0 = v0;
    if (a0 == v1) {
        *(u8 *)s0 = 0xa;
    } else {
        v1 = *(u8 *)((a1 + 0x21));
        a0 = 0;
        if ((u64)((u64)v1 << 0x39 >> 0x3f) != 0) {
            sghTime_SetWait(0);
            a1 = *(u8 *)(s0 + 4);
            sghDice_CastStart((u32)1, a1);
            *(u8 *)s0 = 0xa;
        }
    }
    return;
}
void __sghPad_UserChoiceKoma(void) {
    u32 next;
    u32 previous;
    u32 index;
    u32 pad;
    u32 game;
    u8 *cursor;
    u8 spots[4] __attribute__((aligned(8)));
    struct Choice { u8 b[2]; } choices;
    struct First { unsigned char unused:4, next1:1, next2:1, prev1:1, prev2:1; };
    struct Second { unsigned char unused:2, prev:1, next:1, other:2, confirm:1; };
    struct First *first;
    struct Second *second;
    {
        u32 raw, player;
        raw = sghGetGameInfo();
        player = *(u8 *)(raw+4);
        game = raw;
        pad = *(s32 *)((u8 *)&lpPadData + player*4);
    }
    sghDice_GetDiceSpotsList(spots);
    *(struct Choice *)(u32)&choices = *(struct Choice *)(u32)spots;
    first = (struct First *)(pad+0x20);
    second = (struct Second *)(pad+0x21);
    next = second->next | (first->next1 | first->next2);
    previous = second->prev | (first->prev1 | first->prev2);
    if (next == 0) { if (previous == 0) goto confirm; }
    index = *(s32 *)(gsPadInfo+4);
    SND_Play2D(0x1388,127,0);
    sghKoma_SetAnime(0,gsPadCur[index],*(u8 *)(game+4));
    if (next != 0) {
        u32 selectedIndex;
        u32 delta;
        if (*(u8 *)(game+4)==0) delta=1; else delta=-1;
        index = index + delta;
        selectedIndex = gsPadCur[25]-1;
        if ((s32)selectedIndex < (s32)index) selectedIndex=0;
        else selectedIndex = (s32)index < 0 ? selectedIndex : index;
        index=selectedIndex;
    } else if (previous != 0) {
        u32 selectedIndex;
        u32 delta;
        if (*(u8 *)(game+4)==0) delta=-1; else delta=1;
        index = index + delta;
        selectedIndex = gsPadCur[25]-1;
        if ((s32)selectedIndex < (s32)index) selectedIndex=0;
        else selectedIndex = (s32)index < 0 ? selectedIndex : index;
        index=selectedIndex;
    }
    next = (u32)(gsPadCur + index);
    sghKoma_SetAnime(2,*(u8 *)next,*(u8 *)(game+4));
    sghMarker_MarkerClear();
    previous=0;
    cursor=choices.b;
    do {
        u8 die=*cursor;
        if (die != 255) sghMarker_SetActPossible(previous,*(u8 *)next,die,*(u8 *)(game+4));
        previous++;
        cursor++;
    } while ((s32)previous<2);
    *(s32 *)(gsPadInfo+4)=index;
    return;
confirm:
    if (second->confirm!=0) {
        if (sghMarker_GetTgtPosNum()>0) {
            gsPadInfo[12] = gsPadCur[*(s32 *)(gsPadInfo+4)];
            sghKoma_SetAnime(3,gsPadInfo[12],*(u8 *)(game+4));
            *(u8 *)game=14;
        }
    }
}

void __sghPad_UserChoiceDice(void) {
    struct DiceGmInfo *pGmInfo;
    struct DicePad *lpPad;
    struct DiceSpots aSpots;
    struct DiceSpots tmp;

    pGmInfo = (struct DiceGmInfo *)sghGetGameInfo();
    lpPad = (struct DicePad *)*(s32 *)((u8 *)&lpPadData + pGmInfo->nowPlayerID * 4);
    sghDice_GetDiceSpotsList((u8 *)&tmp);
    *(struct DiceCopy *)(u32)&aSpots = *(struct DiceCopy *)(u32)&tmp;
    if (lpPad->edge.bit.Ldown || lpPad->edge.bit.Lup || lpPad->edge.bit.Lright || lpPad->edge.bit.Lleft || lpPad->edge.bit.R1 || lpPad->edge.bit.L1) {
        SND_Play2D(0x1388, 0x7f, 0);
        *(float *)((u8 *)(MdlMng + 0x1724c) + gsPadCur[0x1a + *(s32 *)(gsPadInfo + 4)] * 0x1c0) = 0.3f;
        *(s32 *)(gsPadInfo + 4) = *(s32 *)(gsPadInfo + 4) + 1;
        *(s32 *)(gsPadInfo + 4) = ((gsPadCur[0x33] - 1) < *(s32 *)(gsPadInfo + 4)) ? 0 : (*(s32 *)(gsPadInfo + 4) < 0 ? (gsPadCur[0x33] - 1) : *(s32 *)(gsPadInfo + 4));
        *(float *)((u8 *)(MdlMng + 0x1724c) + gsPadCur[0x1a + *(s32 *)(gsPadInfo + 4)] * 0x1c0) = 1.0f;
        sghMarker_MarkerClear();
        sghMarker_SetActPossible(*(s32 *)(gsPadInfo + 4), gsPadInfo[0xc], aSpots.spots[gsPadCur[0x1a + *(s32 *)(gsPadInfo + 4)]], pGmInfo->nowPlayerID);
        return;
    }
    if (lpPad->edge.bit.Rright) {
        sghKoma_SetAnime(0, gsPadInfo[0xc], pGmInfo->nowPlayerID);
        gsPadInfo[0xd] = aSpots.spots[gsPadCur[0x1a + *(s32 *)(gsPadInfo + 4)]];
        pGmInfo->modeID = 0x13;
    }
    if (lpPad->edge.bit.Rdown) {
        SND_Play2D(0x1389, 0x7f, 0);
        sghKoma_SetAnime(2, gsPadInfo[0xc], pGmInfo->nowPlayerID);
        {
            int i;
            for (i = 0; gsPadCur[i] != gsPadInfo[0xc]; i++) ;
            *(s32 *)(gsPadInfo + 4) = i;
        }
        {
            int i;
        for (i = 0; i < 2; i++) {
                if (aSpots.spots[i] != 0xff) sghMarker_SetActPossible(i, gsPadCur[*(s32 *)(gsPadInfo + 4)], aSpots.spots[i], pGmInfo->nowPlayerID);
            }
        }
        *(float *)(MdlMng + 0x1724c) = 0.3f;
        *(float *)(MdlMng + 0x1740c) = 0.3f;
        pGmInfo->modeID = 0xd;
    }
}

void __sghPad_TurnRest(void) {
    u8 a1;
    u32 a0;
    u32 v1;
    u8 *s0;
    u8 *v0;

    v0 = (u8 *)sghGetGameInfo();
    a0 = *(u8 *)(v0 + 4);
    v1 = *(u8 *)((u32)&((u8 *)(v0 + 5))[a0]);
    s0 = v0;
    if (v1 == 0) {
        v1 = (u32)&lpPadData;
        v1 = (s32)(u32)&((struct { u8 b[4]; } *)&lpPadData)[a0];
        v1 = *(s32 *)v1;
    } else {
        v1 = lpPadData;
    }
    v1 = *(u8 *)((v1 + 0x21));
    if ((u64)((u64)v1 << 0x39 >> 0x3f) != 0) {
        sghTime_SetWait(0);
        a1 = *(u8 *)(s0 + 4);
        a0 = 1;
        *(u8 *)(s0 + 4) = a1 == 0 ? (enum __sghPad_TurnRest__sel)(s32)a0 : (enum
            __sghPad_TurnRest__sel)(s32)0;
        *(u8 *)s0 = 8;
    } else {
        a0 = 0;
    }
    return;
}

static void __sghPad_GameEnd(void) {
    u8 *a1;
    u32 a0;
    u32 v1;
    u64 v1_64;
    u8 *v0;

    v0 = (u8 *)sghGetGameInfo();
    a1 = (u8 *)lpPadData;
    a0 = *(u8 *)(a1 + 0x20);
    v1_64 = (u64)((u64)a0 << 0x39) >> 0x3f;
    if (v1_64 != 0) {
        v1 = *(s32 *)gsPadInfo;
        v1 = v1 + -1;
        *(u32 *)gsPadInfo = (u32)v1;
        v1 = *(s32 *)gsPadInfo;
        if ((s32)v1 > (s32)1) {
            v1 = 0;
        } else {
            v1 = (s32)v1 < 0 ? (s32)1 : v1;
        }
        v1 = (u8)v1;
        *(u32 *)gsPadInfo = v1;
    } else {
        v1_64 = (u64)((u64)a0 << 0x3b) >> 0x3f;
        if (v1_64 != 0) {
            v1 = *(s32 *)gsPadInfo;
            v1 = v1 + 1;
            *(u32 *)gsPadInfo = (u32)v1;
            v1 = *(s32 *)gsPadInfo;
            if ((s32)v1 > (s32)1) {
                v1 = 0;
            } else {
                v1 = (s32)v1 < 0 ? (s32)1 : v1;
            }
            v1 = (u8)v1;
            *(u32 *)gsPadInfo = v1;
        } else {
            v1 = *(u8 *)(a1 + 0x21);
            v1_64 = (u64)((u64)v1 << 0x39) >> 0x3f;
            if (v1_64 != 0) {
                a0 = 1;
                MdlMng[0x174c2] = a0;
                MdlMng[0x17682] = a0;
                v1 = *(s32 *)gsPadInfo;
                switch (v1) {
                case 0:
                    *(u8 *)v0 = 0;
                    break;
                case 1:
                    v1 = 2;
                    *(u8 *)(v0 + 1) = v1;
                }
            }
        }
    }
    return;
}

/* __sghPad_GamePause @ 0x20EAA0 .. 0x20EC10 (0x170 bytes, frame 0x20) */

static void __sghPad_GamePause(void) {
    u32 a2;
    s32 a1;
    u32 a0;
    u32 v1;
    u8 *s0;
    u8 *v0;
    u64 v1_64;

    v0 = (u8 *)sghGetGameInfo();
    v1 = *(u8 *)(v0 + 1);
    a1 = 1;
    a2 = lpPadData;
    s0 = v0;
    if (v1 == (u32)a1) {
        a0 = *(u8 *)((a2 + 0x20));
        v1_64 = (u64)((u64)a0 << 0x39) >> 0x3f;
        if (v1_64 != 0) {
            a0 = 0x138d;
            a1 = 0x7f;
            SND_Play2D(a0, a1, 0);
            v1 = *(s32 *)gsPadInfo;
            v1 = v1 + -1;
            *(u32 *)gsPadInfo = (u32)v1;
            v1 = *(s32 *)gsPadInfo;
            if ((s32)v1 > (s32)1) {
                v1 = 0;
            } else {
                v1 = (s32)v1 < 0 ? (s32)1 : v1;
            }
            v1 = (u8)v1;
            *(u32 *)gsPadInfo = v1;
        } else {
            v1_64 = (u64)((u64)a0 << 0x3b) >> 0x3f;
            if (v1_64 != 0) {
                a0 = 0x138d;
                a1 = 0x7f;
                SND_Play2D(a0, a1, 0);
                v1 = *(s32 *)gsPadInfo;
                v1 = v1 + 1;
                *(u32 *)gsPadInfo = (u32)v1;
                v1 = *(s32 *)gsPadInfo;
                if ((s32)v1 > (s32)1) {
                    v1 = 0;
                } else {
                    v1 = (s32)v1 < 0 ? (s32)1 : v1;
                }
                v1 = (u8)v1;
                *(u32 *)gsPadInfo = v1;
            } else {
                v1 = *(u8 *)((a2 + 0x21));
                v1_64 = (u64)((u64)v1 << 0x39) >> 0x3f;
                if (v1_64 != 0) {
                    v1 = *(s32 *)gsPadInfo;
                    if (v1 != (u32)a1) {
                        switch (v1) {
                        case 0:
                            a0 = 0x1391;
                            a1 = 0x7f;
                            SND_Play2D(a0, a1, 0);
                            v1 = 2;
                            *(u8 *)(s0 + 1) = v1;
                            break;
                        }
                    } else {
                        *(u8 *)(s0 + 1) = 0;
                    }
                }
            }
        }
    }
    return;
}

static void __sghPad_Tutorial(void) {
    u32 a0;
    u32 v1;
    u8 *v0;
    u8 *s0;

    v0 = (u8 *)sghGetGameInfo();
    v1 = lpPadData;
    a0 = *(u8 *)((v1 + 0x21));
    s0 = v0;
    if ((u64)((u64)((u64)a0 << 0x39) >> 0x3f) != 0) {
        a0 = *(s32 *)(gsPadInfo + 8);
        if (a0 != (u32)6) {
            *(u32 *)(gsPadInfo + 8) = a0 + 1;
        } else {
            SND_Play2D(0x1391, 0x7f, 0);
            *(u8 *)(s0 + 1) = 2;
        }
        return;
    }
    if ((u64)((u64)((u64)a0 << 0x3b) >> 0x3f) != 0) {
        v1 = *(s32 *)(gsPadInfo + 8);
        if (v1 != 0) {
            *(u32 *)(gsPadInfo + 8) = v1 + -1;
        }
        return;
    }
    if ((u64)((u64)((u64)a0 << 0x3a) >> 0x3f) != 0) {
        SND_Play2D(0x1391, 0x7f, 0);
        *(u8 *)(s0 + 1) = 2;
        return;
    }
    return;
}
