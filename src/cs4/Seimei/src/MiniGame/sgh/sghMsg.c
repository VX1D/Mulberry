#include "common.h"
static u32 __sghMsg_PrintHelpWindow(s32 a0, ...);
static u32 __sghMsg_PrintHelpWindow(s32 a0, ...);
extern u32 gsHelpTurnRestMsg;
extern u32 gsHelpChoiDice;
extern u32 gsHelpChoiKoma;
extern u32 gsHelpDiceCast;
extern u32 gsHelpKakunin;
extern signed int FsFontReplaceText(void *, void *, ...);
#ifndef M24_SGH_MSG_COLOR_BYTES_DEFINED
#define M24_SGH_MSG_COLOR_BYTES_DEFINED
static u32 dcomp_ph_819[1];
static u32 dcomp_ph_817[1];
static u32 dcomp_ph_804[1];
static u32 dcomp_ph_802[1];
static u32 dcomp_ph_754[1];
static u32 dcomp_ph_752[1];
typedef struct M24MsgColorBytes { u8 bytes[4]; } M24MsgColorBytes;
#endif
extern u32 MGFontPrintXYSclColShadow(float, float, float, float, M24MsgColorBytes, M24MsgColorBytes, char *, ...);
static void __sghMsg_TurnRest(void);
static void __sghMsg_TurnRest(void);
static void __sghMsg_KomaMoveInit(void);
static void __sghMsg_KomaMoveInit(void);
static void __sghMsg_UserChoiceDice(void);
static void __sghMsg_UserChoiceDice(void);
static void __sghMsg_UserChoiceKoma(void);
static void __sghMsg_UserChoiceKoma(void);
static void __sghMsg_DiceCast(void);
static void __sghMsg_DiceCast(void);
static void __sghMsg_Top(void);
static void __sghMsg_Top(void);
static void __sghMsg_PrintHeader(char *a0, ...);
static void __sghMsg_PrintHeader(char *a0 /* r4 */, ...);
void __sghMsg_GameEnd(void);
void __sghMsg_GameEnd(void);
void __sghMsg_OrderPlayer(void);
void __sghMsg_OrderPlayer(void);
void __sghMsg_OrderPlayerCast(void);
void __sghMsg_OrderPlayerCast(void);
void __sghMsg_OrderPlayerEnd(void);
void __sghMsg_OrderPlayerEnd(void);
static u32 gSGH_MsgFnc[0x1c] = {
    0, (u32)&__sghMsg_Top, 0, (u32)&__sghMsg_OrderPlayer, (u32)&__sghMsg_OrderPlayerCast,
    (u32)&__sghMsg_OrderPlayer, (u32)&__sghMsg_OrderPlayerEnd, 0, 0, (u32)&__sghMsg_DiceCast, 0,
    0, 0, (u32)&__sghMsg_UserChoiceKoma, 0, (u32)&__sghMsg_UserChoiceDice, 0, 0,
    (u32)&__sghMsg_TurnRest, (u32)&__sghMsg_KomaMoveInit, 0, 0, 0, 0, 0, (u32)&__sghMsg_GameEnd
};
static u32 s_OrderPlayerPos[0x4] = {
    0x42600000, 0x43c58000, 0x42500000, 0x43c90000
};
extern void sghDice_GetDiceSpotsList(u8 *);
extern unsigned short * KnMsgMng_GetMsgStr(signed int);
extern u32 GetMGPrcStatus();
extern u32 gsHdPlayerName[];
extern float L760[];
struct CastPos { float f[2][2]; };
struct CastQ { u8 b[16]; } __attribute__((aligned(16)));
struct CastPair { u8 b[2]; };
struct CastDice { u8 list[4]; u8 spots[4]; };
struct CastColor { float value; };


/* __sghMsg_OrderPlayerEnd @ 0x20DED0 .. 0x20E18C (0x2bc bytes, frame 0x90) */
/*
 * dcomp notes:
 *   quad: a1: 128-bit web split from its scalar uses
 *   literal: @760 -> 0x250280
 *   stack: address of the slot at 0x88 escapes at 0x20def8
 *   literal: @752 -> 0x257840
 *   literal: @754 -> 0x257844
 *   stack: address of the slot at 0x78 escapes at 0x20df30
 *   stack: address of the slot at 0x7c escapes at 0x20df5c
 *   stack: address of the slot at 0x60 escapes at 0x20df5c
 *   fpu: float literal 0x42d20000 at 0x20dff4
 *   fpu: float literal 0x3f4ccccd at 0x20e008
 *   fpu: mov.s at 0x20e034 is a float copy
 *   fpu: float literal 0x42780000 at 0x20e040
 *   fpu: float literal 0x430c0000 at 0x20e050
 *   fpu: float literal 0x3f800000 at 0x20e058
 *   fpu: mov.s at 0x20e070 is a float copy
 *   fpu: float literal 0x42d20000 at 0x20e07c
 *   fpu: float literal 0x3f4ccccd at 0x20e090
 *   fpu: float literal 0x3f19999a at 0x20e094
 *   fpu: float literal 0x430c0000 at 0x20e0c8
 *   fpu: float literal 0x43cf0000 at 0x20e0d0
 *   fpu: float literal 0x3f800000 at 0x20e0e0
 *   fpu: mov.s at 0x20e0f4 is a float copy
 *   stack: address of the slot at 0x5c escapes at 0x20e118
 *   literal: @760 initializes the 16-byte local at 0x50
 *   literal: @754 initializes the 4-byte local at 0x80
 *   literal: @752 initializes the 4-byte local at 0x84
 *   stack: 1-byte aggregate copy in 1-byte chunks at 0x20df58
 *   cfg: kept branch: 0x20e108 if (..) goto .L0020E128
 *   cfg: kept goto: 0x20e118 -> .L0020E170
 */

extern u32 sghGetGameInfo();
extern u32 gsOrderRetryMsg;
extern u32 gsOrderEndMsg[];
struct GameEndColor { float data; };
extern u32 GetMGPrcStatus();
extern u32 sghPad_GetPadInfo();
extern u32 sghGetGameInfo();
extern u32 gsScoreMsg[], gsReplayMsg[];
static const u8 CL_CHOICE[4] __attribute__((aligned(8))) = {0xff, 0x99, 0x00, 0x80};
static const u8 CL_UNCHOICE[4] __attribute__((aligned(8))) = {0xff, 0xff, 0xff, 0x30};



extern u32 sghGetGameInfo();
extern u32 GetMGPrcStatus();
extern void FontDrawBegin(int);
extern u32 sghPad_GetPadInfo();
extern void FontDrawEnd();
extern u32 gsGameEndMsg[];
extern u32 gsHdOrderSerMsg;
extern u32 gsHdNowPlayerMsg[],gsHdPlayerName[];

#ifndef M24_SGH_MSG_COLOR_BYTES_DEFINED
#define M24_SGH_MSG_COLOR_BYTES_DEFINED
 
#endif

typedef struct M24MsgColor {float value;} M24MsgColor;


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void sghMsg_Execute(void);
static void __sghMsg_PrintHeader(char *a0, ...);
static u32 __sghMsg_PrintHelpWindow(s32 a0, ...);
static void __sghMsg_Top(void);
void __sghMsg_OrderPlayer(void);
void __sghMsg_OrderPlayerCast(void);
void __sghMsg_OrderPlayerEnd(void);
static void __sghMsg_DiceCast(void);
static void __sghMsg_UserChoiceKoma(void);
static void __sghMsg_UserChoiceDice(void);
static void __sghMsg_KomaMoveInit(void);
static void __sghMsg_TurnRest(void);
void __sghMsg_GameEnd(void);

void sghMsg_Execute(void) {
    u8 *game;
    u8 *status;
    M24MsgColor first,second;
    u8 text[260] __attribute__((aligned(16)));
    game=(u8 *)sghGetGameInfo();
    status=(u8 *)GetMGPrcStatus();
    if(status[1]!=2) {
        FontDrawBegin(0);
        if(game[1]==1) {
            status=(u8 *)sghPad_GetPadInfo();
            sghGetGameInfo();
            {
                struct M24ShadowFloat { float value; } shadow = *(struct M24ShadowFloat *)dcomp_ph_819;
                MGFontPrintXYSclColShadow(156.0f,175.0f,0.8f,0.8f,*(M24MsgColorBytes *)dcomp_ph_817,*(M24MsgColorBytes *)&shadow,(char *)gsGameEndMsg[0]);
                if(*(u32 *)status==0) {
                    first=*(M24MsgColor *)CL_CHOICE;
                    second=*(M24MsgColor *)CL_UNCHOICE;
                } else {
                    first=*(M24MsgColor *)CL_UNCHOICE;
                    second=*(M24MsgColor *)CL_CHOICE;
                }
                MGFontPrintXYSclColShadow(236.0f,220.0f,0.8f,0.8f,*(M24MsgColorBytes *)&first,*(M24MsgColorBytes *)&shadow,(char *)gsGameEndMsg[1]);
                MGFontPrintXYSclColShadow(240.0f,245.0f,0.8f,0.8f,*(M24MsgColorBytes *)&second,*(M24MsgColorBytes *)&shadow,(char *)gsGameEndMsg[2]);
                FontDrawEnd();
            }
        } else {
            switch(game[0]) {
            case 6:break;
            case 0:case 1:case 2:case 3:
                __sghMsg_PrintHeader((char *)gsHdOrderSerMsg);break;
            default:
                FsFontReplaceText(text,(void *)((u32 (*)[2])gsHdNowPlayerMsg)[status[1]][game[4]],((u32 (*)[2])gsHdPlayerName)[status[1]][game[4]]);
                __sghMsg_PrintHeader((char *)text);
            }
            if(gSGH_MsgFnc[game[0]]==0)FontDrawEnd();
            else {((void (*)(void))gSGH_MsgFnc[game[0]])();FontDrawEnd();}
        }
    }
}








/* __sghMsg_PrintHeader @ 0x20E690 .. 0x20E75C (0xcc bytes, frame 0x270) */
/*
 * dcomp notes:
 *   literal: @724 -> 0x257830
 *   literal: @726 -> 0x257834
 *   stack: address of the slot at 0x10 escapes at 0x20e700
 *   fpu: float literal 0x42400000 at 0x20e724
 *   fpu: float literal 0x41a00000 at 0x20e738
 *   fpu: float literal 0x3f4ccccd at 0x20e744
 *   fpu: mov.s at 0x20e74c is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x20e748
 *   literal: @726 initializes the 4-byte local at 0x218
 *   literal: @724 initializes the 4-byte local at 0x21c
 */




static void __sghMsg_PrintHeader(char *a0, ...) {
    u32 a2;
    u32 a1;
    char * a0_value;
    u32 v1;
    u32 v0;
    u8 stackFrame_10[512] __attribute__((aligned(16)));

    a0_value = a0;
    {
        struct stackFrame_21C { u8 b[4]; } stackFrame_21C __attribute__((aligned(4))) = {{0xff, 0xff, 0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_21C);
        {
            struct stackFrame_218 { u8 b[4]; } stackFrame_218 __attribute__((aligned(8))) = {{0x00, 0x00, 0x00, 0x80}};
            a0_value = (char *)((u8 *)&stackFrame_218);
            v1 = (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
            a1 = *(s32 *)((u8 *)&a0);
            v0 = (u32)((u8 *)__builtin_next_arg(a0));
            a2 = (s32)((u8 *)((u8 *)__builtin_next_arg(a0)) - v1);
            if (a1 != 0) {
                FsFontReplaceText((void *)(char *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
                ((u8 *)stackFrame_10)[511] = 0;
                ((u8 *)stackFrame_10)[510] = 0;
            } else {
                *(u8 *)((u8 *)&stackFrame_10[0]) = 0;
            }
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.8f, 0.8f,
                *(M24MsgColorBytes *)((u8 *)&stackFrame_21C),
                *(M24MsgColorBytes *)((u8 *)&stackFrame_218), (char *)((u8 *)&stackFrame_10[0]));
            return;
        }
    }
}



/* __sghMsg_PrintHelpWindow @ 0x20E5C0 .. 0x20E68C (0xcc bytes, frame 0x270) */
/*
 * dcomp notes:
 *   literal: @737 -> 0x257838
 *   literal: @739 -> 0x25783c
 *   stack: address of the slot at 0x10 escapes at 0x20e630
 *   fpu: float literal 0x42400000 at 0x20e654
 *   fpu: float literal 0x43c30000 at 0x20e668
 *   fpu: float literal 0x3f4ccccd at 0x20e674
 *   fpu: mov.s at 0x20e67c is a float copy
 *   literal: @739 initializes the 4-byte local at 0x218
 *   literal: @737 initializes the 4-byte local at 0x21c
 *   declaration vs inferred signature: return u32 vs inferred void; 0 parameters vs 1 inferred
 */


static u32 __sghMsg_PrintHelpWindow(s32 a0, ...) {
    u32 a2;
    u32 a1;
    s32 a0_value;
    u32 v1;
    u32 v0;
    u8 stackFrame_10[512] __attribute__((aligned(16)));

    a0_value = a0;
    {
        struct stackFrame_21C { u8 b[4]; } stackFrame_21C __attribute__((aligned(4))) = {{0xff, 0xff, 0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_21C);
        {
            struct stackFrame_218 { u8 b[4]; } stackFrame_218 __attribute__((aligned(8))) = {{0x00, 0x00, 0x00, 0x80}};
            a0_value = (s32)((u8 *)&stackFrame_218);
            v1 = (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
            a1 = *(s32 *)((u8 *)&a0);
            v0 = (u32)((u8 *)__builtin_next_arg(a0));
            a2 = (s32)((u8 *)((u8 *)__builtin_next_arg(a0)) - v1);
            if (a1 != 0) {
                FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
                ((u8 *)stackFrame_10)[511] = 0;
                ((u8 *)stackFrame_10)[510] = 0;
            } else {
                *(u8 *)((u8 *)&stackFrame_10[0]) = 0;
            }
            v0 = MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.8f, 0.8f,
                *(M24MsgColorBytes *)((u8 *)&stackFrame_21C),
                *(M24MsgColorBytes *)((u8 *)&stackFrame_218), (char *)((u8 *)&stackFrame_10[0]));
            return v0;
        }
    }
}
static u32 dcomp_ph_752[1] = {0x80ffffff};
static u32 dcomp_ph_754[1] = {0x80000000};
static u32 dcomp_ph_802[1] = {0x80ffffff};
static u32 dcomp_ph_804[1] = {0x80000000};
static u32 dcomp_ph_817[1] = {0x80ffffff};
static u32 dcomp_ph_819[1] = {0x80000000};



















/* __sghMsg_Top @ 0x20E5B0 .. 0x20E5B8 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j __sghMsg_PrintHelpWindow at 0x20e5b0 leaves the function
 *   return value dropped, call kept: the function is void
 */


static void __sghMsg_Top(void) {
    u32 a0;

    a0 = gsHelpKakunin;
    __sghMsg_PrintHelpWindow(a0);
    return;
}


void __sghMsg_OrderPlayer(void) {
    struct CastColor col = *(struct CastColor *)dcomp_ph_752;
    struct CastColor shadow = *(struct CastColor *)dcomp_ph_754;
    u8 spots[4];
    u8 list[4];
    u8 *status;

    sghDice_GetDiceSpotsList(list);
    *(struct CastPair *)spots = *(struct CastPair *)list;
    {
    char *msgs[6] = {0, 0, 0, 0, 0, 0};
    msgs[0] = (char *)KnMsgMng_GetMsgStr(0x49559);
    msgs[1] = (char *)KnMsgMng_GetMsgStr(0x4955a);
    msgs[2] = (char *)KnMsgMng_GetMsgStr(0x4955b);
    msgs[3] = (char *)KnMsgMng_GetMsgStr(0x4955c);
    msgs[4] = (char *)KnMsgMng_GetMsgStr(0x4955d);
    msgs[5] = (char *)KnMsgMng_GetMsgStr(0x4955e);
    status = (u8 *)GetMGPrcStatus();
    {
    struct CastPos pos __attribute__((aligned(16)));
    *(struct CastQ *)&pos = *(struct CastQ *)s_OrderPlayerPos;
    MGFontPrintXYSclColShadow(pos.f[status[1]][0], 105.0f, 0.8f, 0.8f, *(M24MsgColorBytes *)&col, *(M24MsgColorBytes *)&shadow, (char *)((u32 (*)[2])gsHdPlayerName)[status[1]][0]);
    MGFontPrintXYSclColShadow(62.0f, 140.0f, 1.0f, 1.0f, *(M24MsgColorBytes *)&col, *(M24MsgColorBytes *)&shadow, msgs[spots[0] - 1]);
    MGFontPrintXYSclColShadow(pos.f[status[1]][1], 105.0f, 0.6f, 0.8f, *(M24MsgColorBytes *)&col, *(M24MsgColorBytes *)&shadow, (char *)(gsHdPlayerName + 1)[status[1] * 2]);
    MGFontPrintXYSclColShadow(414.0f, 140.0f, 1.0f, 1.0f, *(M24MsgColorBytes *)&col, *(M24MsgColorBytes *)&shadow, msgs[spots[1] - 1]);
    }
    }
}








/* __sghMsg_OrderPlayerCast @ 0x20E190 .. 0x20E39C (0x20c bytes, frame 0x70) */
/*
 * dcomp notes:
 *   quad: a1: 128-bit web split from its scalar uses
 *   literal: @760 -> 0x250280
 *   literal: @752 -> 0x257840
 *   literal: @754 -> 0x257844
 *   stack: address of the slot at 0x60 escapes at 0x20e1b8
 *   stack: address of the slot at 0x64 escapes at 0x20e1e4
 *   stack: address of the slot at 0x40 escapes at 0x20e1e4
 *   fpu: float literal 0x42d20000 at 0x20e27c
 *   fpu: float literal 0x3f4ccccd at 0x20e290
 *   fpu: mov.s at 0x20e2bc is a float copy
 *   fpu: float literal 0x42780000 at 0x20e2c8
 *   fpu: float literal 0x430c0000 at 0x20e2d8
 *   fpu: float literal 0x3f800000 at 0x20e2e0
 *   fpu: mov.s at 0x20e2f8 is a float copy
 *   fpu: float literal 0x42d20000 at 0x20e304
 *   fpu: float literal 0x3f4ccccd at 0x20e318
 *   fpu: float literal 0x3f19999a at 0x20e31c
 *   fpu: float literal 0x430c0000 at 0x20e350
 *   fpu: float literal 0x43cf0000 at 0x20e358
 *   fpu: float literal 0x3f800000 at 0x20e368
 *   fpu: mov.s at 0x20e37c is a float copy
 *   literal: @760 initializes the 16-byte local at 0x30
 *   literal: @754 initializes the 4-byte local at 0x68
 *   literal: @752 initializes the 4-byte local at 0x6c
 *   stack: 1-byte aggregate copy in 1-byte chunks at 0x20e1e0
 */

void __sghMsg_OrderPlayerCast(void) {
    struct CastColor col = *(struct CastColor *)dcomp_ph_752;
    struct CastColor shadow = *(struct CastColor *)dcomp_ph_754;
    u8 spots[4];
    u8 list[4];
    u8 *status;

    sghDice_GetDiceSpotsList(list);
    *(struct CastPair *)spots = *(struct CastPair *)list;
    {
    char *msgs[6] = {0, 0, 0, 0, 0, 0};
    msgs[0] = (char *)KnMsgMng_GetMsgStr(0x49559);
    msgs[1] = (char *)KnMsgMng_GetMsgStr(0x4955a);
    msgs[2] = (char *)KnMsgMng_GetMsgStr(0x4955b);
    msgs[3] = (char *)KnMsgMng_GetMsgStr(0x4955c);
    msgs[4] = (char *)KnMsgMng_GetMsgStr(0x4955d);
    msgs[5] = (char *)KnMsgMng_GetMsgStr(0x4955e);
    status = (u8 *)GetMGPrcStatus();
    {
    struct CastPos pos __attribute__((aligned(16)));
    *(struct CastQ *)&pos = *(struct CastQ *)s_OrderPlayerPos;
    MGFontPrintXYSclColShadow(pos.f[status[1]][0], 105.0f, 0.8f, 0.8f, *(M24MsgColorBytes *)&col, *(M24MsgColorBytes *)&shadow, (char *)((u32 (*)[2])gsHdPlayerName)[status[1]][0]);
    MGFontPrintXYSclColShadow(62.0f, 140.0f, 1.0f, 1.0f, *(M24MsgColorBytes *)&col, *(M24MsgColorBytes *)&shadow, msgs[spots[0] - 1]);
    MGFontPrintXYSclColShadow(pos.f[status[1]][1], 105.0f, 0.6f, 0.8f, *(M24MsgColorBytes *)&col, *(M24MsgColorBytes *)&shadow, (char *)(gsHdPlayerName + 1)[status[1] * 2]);
    MGFontPrintXYSclColShadow(414.0f, 140.0f, 1.0f, 1.0f, *(M24MsgColorBytes *)&col, *(M24MsgColorBytes *)&shadow, msgs[spots[1] - 1]);
    __sghMsg_PrintHelpWindow(gsHelpDiceCast);
    }
    }
}

void __sghMsg_OrderPlayerEnd(void) {
    u8 *status;
    u8 *game;
    u8 *cur;
    u8 spots1[4];
    u8 list1[4];

    status = (u8 *)GetMGPrcStatus();
    game = (u8 *)sghGetGameInfo();
    sghDice_GetDiceSpotsList(list1);
    *(struct CastPair *)spots1 = *(struct CastPair *)list1;
    {
    struct CastColor col = *(struct CastColor *)dcomp_ph_752;
    struct CastColor shadow = *(struct CastColor *)dcomp_ph_754;
    u8 spots2[4];
    u8 list2[4];
    sghDice_GetDiceSpotsList(list2);
    *(struct CastPair *)spots2 = *(struct CastPair *)list2;
    {
    char *msgs[6] = {0, 0, 0, 0, 0, 0};
    msgs[0] = (char *)KnMsgMng_GetMsgStr(0x49559);
    msgs[1] = (char *)KnMsgMng_GetMsgStr(0x4955a);
    msgs[2] = (char *)KnMsgMng_GetMsgStr(0x4955b);
    msgs[3] = (char *)KnMsgMng_GetMsgStr(0x4955c);
    msgs[4] = (char *)KnMsgMng_GetMsgStr(0x4955d);
    msgs[5] = (char *)KnMsgMng_GetMsgStr(0x4955e);
    cur = (u8 *)GetMGPrcStatus();
    {
    struct CastPos pos __attribute__((aligned(16)));
    *(struct CastQ *)&pos = *(struct CastQ *)s_OrderPlayerPos;
    MGFontPrintXYSclColShadow(pos.f[cur[1]][0], 105.0f, 0.8f, 0.8f, *(M24MsgColorBytes *)&col, *(M24MsgColorBytes *)&shadow, (char *)((u32 (*)[2])gsHdPlayerName)[cur[1]][0]);
    MGFontPrintXYSclColShadow(62.0f, 140.0f, 1.0f, 1.0f, *(M24MsgColorBytes *)&col, *(M24MsgColorBytes *)&shadow, msgs[spots2[0] - 1]);
    MGFontPrintXYSclColShadow(pos.f[cur[1]][1], 105.0f, 0.6f, 0.8f, *(M24MsgColorBytes *)&col, *(M24MsgColorBytes *)&shadow, (char *)(gsHdPlayerName + 1)[cur[1] * 2]);
    MGFontPrintXYSclColShadow(414.0f, 140.0f, 1.0f, 1.0f, *(M24MsgColorBytes *)&col, *(M24MsgColorBytes *)&shadow, msgs[spots2[1] - 1]);
    if (spots1[0] == 0xff || spots1[1] == 0xff) {
        __sghMsg_PrintHelpWindow(gsHelpKakunin);
    } else {
        if (spots1[0] == spots1[1]) {
            __sghMsg_PrintHeader((char *)gsOrderRetryMsg);
        } else {
            __sghMsg_PrintHeader((char *)((u32 (*)[2])gsOrderEndMsg)[status[1]][game[4]]);
        }
        __sghMsg_PrintHelpWindow(gsHelpKakunin);
    }
    }
    }
    }
}


/* __sghMsg_DiceCast @ 0x20DEC0 .. 0x20DEC8 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j __sghMsg_PrintHelpWindow at 0x20dec0 leaves the function
 *   return value dropped, call kept: the function is void
 */


static void __sghMsg_DiceCast(void) {
    u32 a0;

    a0 = gsHelpDiceCast;
    __sghMsg_PrintHelpWindow(a0);
    return;
}


/* __sghMsg_UserChoiceKoma @ 0x20DEB0 .. 0x20DEB8 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j __sghMsg_PrintHelpWindow at 0x20deb0 leaves the function
 *   return value dropped, call kept: the function is void
 */


static void __sghMsg_UserChoiceKoma(void) {
    u32 a0;

    a0 = gsHelpChoiKoma;
    __sghMsg_PrintHelpWindow(a0);
    return;
}








/* __sghMsg_UserChoiceDice @ 0x20DEA0 .. 0x20DEA8 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j __sghMsg_PrintHelpWindow at 0x20dea0 leaves the function
 *   return value dropped, call kept: the function is void
 */


static void __sghMsg_UserChoiceDice(void) {
    u32 a0;

    a0 = gsHelpChoiDice;
    __sghMsg_PrintHelpWindow(a0);
    return;
}








/* __sghMsg_KomaMoveInit @ 0x20DE90 .. 0x20DE98 (0x8 bytes) */



static void __sghMsg_KomaMoveInit(void) {
    return;
}


/* __sghMsg_TurnRest @ 0x20DE80 .. 0x20DE88 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j __sghMsg_PrintHelpWindow at 0x20de80 leaves the function
 *   return value dropped, call kept: the function is void
 */


static void __sghMsg_TurnRest(void) {
    u32 a0;

    a0 = gsHelpTurnRestMsg;
    __sghMsg_PrintHelpWindow(a0);
    return;
}
void __sghMsg_GameEnd(void) {
    u8 *status;
    u32 *pad;
    u8 *game;
    struct GameEndColor first, second;
    u8 text[256] __attribute__((aligned(16)));
    status = (u8 *)GetMGPrcStatus();
    pad = (u32 *)sghPad_GetPadInfo();
    game = (u8 *)sghGetGameInfo();
    {
        struct GameEndColor shadow, color;
        float x, y, scale;
        char *message;
        color = *(struct GameEndColor *)dcomp_ph_802;
        x = 45.0f;
        y = 300.0f;
        scale = 1.0f;
        shadow = *(struct GameEndColor *)dcomp_ph_804;
        message = (char *)((u32 (*)[3])gsScoreMsg)[status[1]][0];
        MGFontPrintXYSclColShadow(x, y, scale, scale, *(M24MsgColorBytes *)&color, *(M24MsgColorBytes *)&shadow, message);
        FsFontReplaceText(text, (void *)(gsScoreMsg + 1)[status[1] * 3], (u32)game[7]);
        MGFontPrintXYSclColShadow(45.0f, 328.0f, 1.0f, 1.0f, *(M24MsgColorBytes *)&color, *(M24MsgColorBytes *)&shadow, (char *)text);
        FsFontReplaceText(text, (void *)(gsScoreMsg + 2)[status[1] * 3], (u32)game[8]);
        MGFontPrintXYSclColShadow(45.0f, 356.0f, 1.0f, 1.0f, *(M24MsgColorBytes *)&color, *(M24MsgColorBytes *)&shadow, (char *)text);
        MGFontPrintXYSclColShadow(320.0f, 300.0f, 0.8f, 0.8f, *(M24MsgColorBytes *)&color, *(M24MsgColorBytes *)&shadow, (char *)gsReplayMsg[0]);
        if (!pad[0]) {
            first = *(struct GameEndColor *)CL_CHOICE;
            second = *(struct GameEndColor *)CL_UNCHOICE;
        } else {
            first = *(struct GameEndColor *)CL_UNCHOICE;
            second = *(struct GameEndColor *)CL_CHOICE;
        }
        MGFontPrintXYSclColShadow(320.0f, 328.0f, 0.8f, 0.8f, *(M24MsgColorBytes *)&first, *(M24MsgColorBytes *)&shadow, (char *)gsReplayMsg[1]);
        MGFontPrintXYSclColShadow(320.0f, 356.0f, 0.8f, 0.8f, *(M24MsgColorBytes *)&second, *(M24MsgColorBytes *)&shadow, (char *)gsReplayMsg[2]);
    }
}
