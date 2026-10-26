#include "common.h"
extern u8 GameSt[];
extern u32 g_MGTextFuncTbl[];
static void MGTutorialThrowNowText(void);
void MGTextControl(void);

/* MGTextControl @ 0x1F54F0 .. 0x1F5534 (0x44 bytes, frame 0x10) */


void MGTextControl(void) {
    u32 a0;
    u32 v1;

    a0 = *(u8 *)((u8 *)&GameSt + 9);
    v1 = (u32)g_MGTextFuncTbl;
    a0 = a0 << 2;
    v1 = (s32)((u8 *)g_MGTextFuncTbl + a0);
    v1 = *(s32 *)v1;
    if (v1 != 0) {
        ((void (*)(s32))(s32)v1)(a0);
    }
    return;
}





/* MGTopMenuText @ 0x1F5480 .. 0x1F54F0 (0x70 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @705 -> 0x257690
 *   literal: @703 -> 0x25768c
 *   fpu: float literal 0x41f00000 at 0x1f54bc
 *   fpu: float literal 0x43a50000 at 0x1f54c4
 *   fpu: float literal 0x3f4ccccd at 0x1f54d8
 *   fpu: mov.s at 0x1f54e0 is a float copy
 *   literal: @705 initializes the 4-byte local at 0x18
 *   literal: @703 initializes the 4-byte local at 0x1c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif

extern u32 GetMenuPos(void);
extern unsigned short * KnMsgMng_GetMsgStr(signed int);
extern void MGFontPrintXYSclColShadow(float, float, float, float, struct
    dcomp_byte_aggregate_256d5d, struct dcomp_byte_aggregate_256d5d, char *, ...);

static void MGTopMenuText(void) {
    u32 a1;
    u32 v1;
    u32 v0;

    GetMenuPos();
    v0 = 0x10000;
    {
        static struct stackFrame_1C { u8 b[4]; } dcomp_init_stackFrame_1C = {{0x7f, 0x7f, 0x7f,
            0x7f}};
        static struct stackFrame_18 { u8 b[4]; } dcomp_init_stackFrame_18 = {{0x00, 0x00, 0x00,
            0x7f}};
        struct stackFrame_18 stackFrame_18 __attribute__((aligned(8))) = dcomp_init_stackFrame_18;
        a1 = (u32)((u8 *)&stackFrame_18);
        {
            struct stackFrame_1C stackFrame_1C __attribute__((aligned(4))) =
                dcomp_init_stackFrame_1C;
            v1 = (u32)((u8 *)&stackFrame_1C);
            v0 = (u32)KnMsgMng_GetMsgStr(0x10000 | 0x88c7);
            MGFontPrintXYSclColShadow(330.0f, 30.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            return;
        }
    }
}




/* MGMainMenuText @ 0x1F5350 .. 0x1F5478 (0x128 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @714 -> 0x257694
 *   literal: @716 -> 0x257698
 *   fpu: float literal 0x42400000 at 0x1f53b0
 *   fpu: float literal 0x3f4ccccd at 0x1f53c4
 *   fpu: float literal 0x43bd8000 at 0x1f53c8
 *   fpu: mov.s at 0x1f53d0 is a float copy
 *   fpu: float literal 0x42400000 at 0x1f53f0
 *   fpu: float literal 0x3f4ccccd at 0x1f5404
 *   fpu: float literal 0x43c88000 at 0x1f5408
 *   fpu: mov.s at 0x1f5410 is a float copy
 *   literal: @724 -> 0x2576a0
 *   literal: @722 -> 0x25769c
 *   fpu: float literal 0x41f00000 at 0x1f5444
 *   fpu: float literal 0x43a50000 at 0x1f544c
 *   fpu: float literal 0x3f4ccccd at 0x1f5460
 *   fpu: mov.s at 0x1f5468 is a float copy
 *   literal: @724 initializes the 4-byte local at 0x10
 *   literal: @722 initializes the 4-byte local at 0x14
 *   literal: @716 initializes the 4-byte local at 0x18
 *   literal: @714 initializes the 4-byte local at 0x1c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif


extern signed int CheckPadEnable(unsigned char);



static void MGMainMenuText(void) {
    u8 *a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;

    {
        struct stackFrame_1C { u8 b[4]; } stackFrame_1C __attribute__((aligned(4))) = {{0xff, 0xff,
            0xff, 0x80}};
        v1 = (u32)((u8 *)&stackFrame_1C);
        {
            struct stackFrame_18 { u8 b[4]; } stackFrame_18 __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            v0 = (u32)((u8 *)&stackFrame_18);
            v0 = GetMenuPos();
            v0 = *(u8 *)v0;
            a0 = 1;
            if (v0 == a0) {
                v0 = CheckPadEnable(a0);
                if (v0 == 0) {
                    v0 = 0x40000;
                    v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x950c);
                    a2 = (u8 *)v0;
                    f12 = 48.0f;
                    v0 = 0x43bd0000;
                    v1 = 0x43bd0000 | 0x8000;
                    f14 = 0.800000012f;
                    f13 = 379.0f;
                    MGFontPrintXYSclColShadow(48.0f, (f32)379.0f, (f32)0.800000012f,
                        (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                        *)&stackFrame_1C)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                        *)&stackFrame_18)), (char *)a2);
                    v0 = 0x40000;
                    v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x950d);
                    a2 = (u8 *)v0;
                    f12 = 48.0f;
                    v0 = 0x43c80000;
                    v1 = 0x43c80000 | 0x8000;
                    f14 = 0.800000012f;
                    f13 = 401.0f;
                    MGFontPrintXYSclColShadow(48.0f, (f32)401.0f, (f32)0.800000012f,
                        (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                        *)&stackFrame_1C)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                        *)&stackFrame_18)), (char *)a2);
                }
            }
            v0 = 0x10000;
            {
                static struct stackFrame_14 { u8 b[4]; } dcomp_init_stackFrame_14 = {{0x7f, 0x7f,
                    0x7f, 0x7f}};
                static struct stackFrame_10 { u8 b[4]; } dcomp_init_stackFrame_10 = {{0x00, 0x00,
                    0x00, 0x7f}};
                struct stackFrame_10 stackFrame_10 __attribute__((aligned(16))) =
                    dcomp_init_stackFrame_10;
                a1 = (u32)((u8 *)&stackFrame_10);
                {
                    struct stackFrame_14 stackFrame_14 __attribute__((aligned(4))) =
                        dcomp_init_stackFrame_14;
                    v1 = (u32)((u8 *)&stackFrame_14);
                    v0 = (u32)KnMsgMng_GetMsgStr(0x10000 | 0x88c7);
                    f13 = 30.0f;
                    f12 = 330.0f;
                    f14 = 0.800000012f;
                    MGFontPrintXYSclColShadow((f32)330.0f, (f32)30.0f, 0.800000012f,
                        (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                        *)&stackFrame_14)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                        *)&stackFrame_10)), (char *)(u8 *)v0);
                    return;
                }
            }
        }
    }
}


/* MGOrderPlayerText0 @ 0x1F5250 .. 0x1F5350 (0x100 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42600000 at 0x1f525c
 *   literal: @741 -> 0x2576a4
 *   fpu: float literal 0x3f4ccccd at 0x1f5278
 *   fpu: float literal 0x42d20000 at 0x1f5280
 *   literal: @743 -> 0x2576a8
 *   fpu: mov.s at 0x1f52a0 is a float copy
 *   fpu: float literal 0x42d20000 at 0x1f52b4
 *   fpu: float literal 0x43c58000 at 0x1f52bc
 *   fpu: float literal 0x3f19999a at 0x1f52d4
 *   fpu: float literal 0x3f4ccccd at 0x1f52d8
 *   fpu: float literal 0x42400000 at 0x1f52ec
 *   fpu: float literal 0x41a00000 at 0x1f52f8
 *   fpu: float literal 0x3f4ccccd at 0x1f5308
 *   fpu: mov.s at 0x1f5310 is a float copy
 *   fpu: float literal 0x42400000 at 0x1f531c
 *   fpu: float literal 0x43c30000 at 0x1f5328
 *   fpu: float literal 0x3f4ccccd at 0x1f5338
 *   fpu: mov.s at 0x1f5340 is a float copy
 *   literal: @741 initializes the 4-byte local at 0x18
 *   literal: @743 initializes the 4-byte local at 0x1c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif
extern void MGFontPrintXYSclColShadow(float, float, float, float, struct
    dcomp_byte_aggregate_256d5d, struct dcomp_byte_aggregate_256d5d, char *, ...);
extern u32 gsHdPlayerName[];
extern u32 gsHdOrderSerMsg;
extern u32 gsHelpKakunin;

static void MGOrderPlayerText0(void) {
    float f15;
    u32 a2;
    u32 a1;
    float f14;
    float f13;
    u32 a0;
    float f12;
    s32 v1;
    s32 v0;

    f12 = 56.0f;
    f14 = 0.800000012f;
    f13 = 105.0f;
    {
        struct stackFrame_18 { u8 b[4]; } stackFrame_18 __attribute__((aligned(8))) = {{0xff, 0xff,
            0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_18);
        {
            struct stackFrame_1C { u8 b[4]; } stackFrame_1C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_1C);
            MGFontPrintXYSclColShadow(56.0f, (f32)105.0f, (f32)0.800000012f, (float)0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), (char *)*(s32
                *)gsHdPlayerName);
            v0 = 0x43c50000;
            v1 = 0x43c50000 | 0x8000;
            f13 = 105.0f;
            v0 = 0x3f190000;
            f12 = 395.0f;
            v1 = 0x3f190000 | 0x999a;
            f14 = 0.600000024f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)395.0f, (f32)105.0f, 0.600000024f, 0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), (char *)*(s32
                *)(gsHdPlayerName + 1));
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), (char *)gsHdOrderSerMsg);
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), (char *)gsHelpKakunin);
            return;
        }
    }
}


/* MGOrderPlayerText1 @ 0x1F5130 .. 0x1F5248 (0x118 bytes, frame 0x120) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42600000 at 0x1f513c
 *   literal: @748 -> 0x2576ac
 *   fpu: float literal 0x3f4ccccd at 0x1f5158
 *   fpu: float literal 0x42d20000 at 0x1f5160
 *   literal: @750 -> 0x2576b0
 *   fpu: mov.s at 0x1f5180 is a float copy
 *   fpu: float literal 0x42d20000 at 0x1f5194
 *   fpu: float literal 0x43c58000 at 0x1f519c
 *   fpu: float literal 0x3f19999a at 0x1f51b4
 *   fpu: float literal 0x3f4ccccd at 0x1f51b8
 *   stack: address of the slot at 0x10 escapes at 0x1f51d4
 *   fpu: float literal 0x42400000 at 0x1f51e4
 *   fpu: float literal 0x41a00000 at 0x1f51f0
 *   fpu: float literal 0x3f4ccccd at 0x1f5200
 *   fpu: mov.s at 0x1f5208 is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f5204
 *   fpu: float literal 0x42400000 at 0x1f5214
 *   fpu: float literal 0x43c30000 at 0x1f5220
 *   fpu: float literal 0x3f4ccccd at 0x1f5230
 *   fpu: mov.s at 0x1f5238 is a float copy
 *   literal: @748 initializes the 4-byte local at 0x118
 *   literal: @750 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif

extern signed int FsFontReplaceText(void *, void *, ...);

extern u32 gsHdNowPlayerMsg[];
extern u32 gsHelpDiceCast;

static void MGOrderPlayerText1(void) {
    float f15;
    u32 a2;
    u32 a1;
    float f14;
    float f13;
    u32 a0;
    float f12;
    s32 v1;
    s32 v0;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    f12 = 56.0f;
    f14 = 0.800000012f;
    f13 = 105.0f;
    {
        struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0xff,
            0xff, 0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_118);
        {
            struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_11C);
            MGFontPrintXYSclColShadow(56.0f, (f32)105.0f, (f32)0.800000012f, (float)0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), (char *)*(s32
                *)gsHdPlayerName);
            v0 = 0x43c50000;
            v1 = 0x43c50000 | 0x8000;
            f13 = 105.0f;
            v0 = 0x3f190000;
            f12 = 395.0f;
            v1 = 0x3f190000 | 0x999a;
            f14 = 0.600000024f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)395.0f, (f32)105.0f, 0.600000024f, 0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), (char *)*(s32
                *)(gsHdPlayerName + 1));
            a1 = *(s32 *)gsHdNowPlayerMsg;
            a2 = *(s32 *)gsHdPlayerName;
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), (char *)((u8
                *)&stackFrame_10[0]));
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), (char *)gsHelpDiceCast);
            return;
        }
    }
}


/* MGOrderPlayerText2 @ 0x1F5040 .. 0x1F5128 (0xe8 bytes, frame 0x120) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42600000 at 0x1f504c
 *   literal: @756 -> 0x2576b4
 *   fpu: float literal 0x3f4ccccd at 0x1f5068
 *   fpu: float literal 0x42d20000 at 0x1f5070
 *   literal: @758 -> 0x2576b8
 *   fpu: mov.s at 0x1f5090 is a float copy
 *   fpu: float literal 0x42d20000 at 0x1f50a4
 *   fpu: float literal 0x43c58000 at 0x1f50ac
 *   fpu: float literal 0x3f19999a at 0x1f50c4
 *   fpu: float literal 0x3f4ccccd at 0x1f50c8
 *   stack: address of the slot at 0x10 escapes at 0x1f50e4
 *   fpu: float literal 0x42400000 at 0x1f50f4
 *   fpu: float literal 0x41a00000 at 0x1f5100
 *   fpu: float literal 0x3f4ccccd at 0x1f5110
 *   fpu: mov.s at 0x1f5118 is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f5114
 *   literal: @756 initializes the 4-byte local at 0x118
 *   literal: @758 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif





static void MGOrderPlayerText2(void) {
    float f15;
    u32 a2;
    u32 a1;
    float f14;
    float f13;
    u32 a0;
    float f12;
    s32 v1;
    s32 v0;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    f12 = 56.0f;
    f14 = 0.800000012f;
    f13 = 105.0f;
    {
        struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0xff,
            0xff, 0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_118);
        {
            struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_11C);
            MGFontPrintXYSclColShadow(56.0f, (f32)105.0f, (f32)0.800000012f, (float)0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), (char *)*(s32
                *)gsHdPlayerName);
            v0 = 0x43c50000;
            v1 = 0x43c50000 | 0x8000;
            f13 = 105.0f;
            v0 = 0x3f190000;
            f12 = 395.0f;
            v1 = 0x3f190000 | 0x999a;
            f14 = 0.600000024f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)395.0f, (f32)105.0f, 0.600000024f, 0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), (char *)*(s32
                *)(gsHdPlayerName + 1));
            a1 = *(s32 *)gsHdNowPlayerMsg;
            a2 = *(s32 *)gsHdPlayerName;
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), (char *)((u8
                *)&stackFrame_10[0]));
            return;
        }
    }
}



/* MGOrderPlayerText3 @ 0x1F4E20 .. 0x1F5034 (0x214 bytes, frame 0x130) */
/*
 * dcomp notes:
 *   literal: @2430 -> 0x257250
 *   literal: @1598 is the string ''
 *   call: GetDiceNum is declared void but its v0 is read: called as returning u32
 *   literal: @765 -> 0x2576bc
 *   fpu: float literal 0x42600000 at 0x1f4e48
 *   fpu: float literal 0x42d20000 at 0x1f4e50
 *   literal: @767 -> 0x2576c0
 *   fpu: float literal 0x3f4ccccd at 0x1f4e64
 *   fpu: mov.s at 0x1f4e7c is a float copy
 *   fpu: float literal 0x42d20000 at 0x1f4e90
 *   fpu: float literal 0x43c58000 at 0x1f4e98
 *   fpu: float literal 0x3f19999a at 0x1f4eb0
 *   fpu: float literal 0x3f4ccccd at 0x1f4eb4
 *   indirect: jr v0 at 0x1f4ee0 -> <v0>
 *   fpu: float literal 0x42780000 at 0x1f4f8c
 *   fpu: float literal 0x430c0000 at 0x1f4f98
 *   fpu: float literal 0x3f800000 at 0x1f4fa0
 *   fpu: mov.s at 0x1f4fa8 is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x1f4fbc
 *   fpu: float literal 0x42400000 at 0x1f4fcc
 *   fpu: float literal 0x41a00000 at 0x1f4fd8
 *   fpu: float literal 0x3f4ccccd at 0x1f4fe8
 *   fpu: mov.s at 0x1f4ff0 is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x1f4fec
 *   fpu: float literal 0x42400000 at 0x1f4ffc
 *   fpu: float literal 0x43c30000 at 0x1f5008
 *   fpu: float literal 0x3f4ccccd at 0x1f5018
 *   fpu: mov.s at 0x1f5020 is a float copy
 *   literal: @765 initializes the 4-byte local at 0x128
 *   literal: @767 initializes the 4-byte local at 0x12c
 */

extern void GetDiceNum(void);
extern unsigned short * KnMsgMng_GetMsgStr(signed int);

static void MGOrderPlayerText3(void) {
    extern u32 GetDiceNum(void);
    u32 a2;
    u32 a1;
    u8 *s0;
    u32 a0;
    float f15;
    float f14;
    float f13;
    u32 v1;
    float f12;
    u32 v0;
    u8 stackFrame_20[264] __attribute__((aligned(16)));

    v0 = GetDiceNum();
    s0 = (u8 *)v0;
    f12 = 56.0f;
    f13 = 105.0f;
    {
        struct stackFrame_128 { u8 b[4]; } stackFrame_128 __attribute__((aligned(8))) = {{0xff,
            0xff, 0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_128);
        f14 = 0.800000012f;
        {
            struct stackFrame_12C { u8 b[4]; } stackFrame_12C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_12C);
            MGFontPrintXYSclColShadow(56.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)*(s32
                *)gsHdPlayerName);
            v0 = 0x43c50000;
            v1 = 0x43c50000 | 0x8000;
            f13 = 105.0f;
            v0 = 0x3f190000;
            f12 = 395.0f;
            v1 = 0x3f190000 | 0x999a;
            f14 = 0.600000024f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)395.0f, (f32)105.0f, 0.600000024f, 0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)*(s32
                *)(gsHdPlayerName + 1));
            v0 = *(u8 *)s0;
            switch (v0) {
            case 1:
                v0 = 0x40000;
                a0 = 0x40000 | 0x9559;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 2:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955a;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 3:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955b;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 4:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955c;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 5:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955d;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 6:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955e;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 0:
            default:
                v0 = (u32)"";
            }
            a2 = v0;
            f12 = 62.0f;
            f13 = 140.0f;
            f14 = 1.0f;
            MGFontPrintXYSclColShadow(62.0f, 140.0f, 1.0f, (float)1.0f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)a2);
            a1 = *(s32 *)gsHdNowPlayerMsg;
            a2 = *(s32 *)gsHdPlayerName;
            FsFontReplaceText((void *)((u8 *)&stackFrame_20[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)((u8
                *)&stackFrame_20[0]));
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)gsHelpKakunin);
            return;
        }
    }
}



/* MGOrderCPUText1 @ 0x1F4C30 .. 0x1F4E14 (0x1e4 bytes, frame 0x130) */
/*
 * dcomp notes:
 *   literal: @2388 -> 0x257230
 *   literal: @1598 is the string ''
 *   call: GetDiceNum is declared void but its v0 is read: called as returning u32
 *   literal: @774 -> 0x2576c4
 *   fpu: float literal 0x42600000 at 0x1f4c58
 *   fpu: float literal 0x42d20000 at 0x1f4c60
 *   literal: @776 -> 0x2576c8
 *   fpu: float literal 0x3f4ccccd at 0x1f4c74
 *   fpu: mov.s at 0x1f4c8c is a float copy
 *   fpu: float literal 0x42d20000 at 0x1f4ca0
 *   fpu: float literal 0x43c58000 at 0x1f4ca8
 *   fpu: float literal 0x3f19999a at 0x1f4cc0
 *   fpu: float literal 0x3f4ccccd at 0x1f4cc4
 *   stack: address of the slot at 0x20 escapes at 0x1f4ce0
 *   fpu: float literal 0x42400000 at 0x1f4cf0
 *   fpu: float literal 0x41a00000 at 0x1f4cfc
 *   fpu: float literal 0x3f4ccccd at 0x1f4d0c
 *   fpu: mov.s at 0x1f4d14 is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x1f4d10
 *   indirect: jr v0 at 0x1f4d38 -> <v0>
 *   fpu: float literal 0x42780000 at 0x1f4ddc
 *   fpu: float literal 0x430c0000 at 0x1f4df0
 *   fpu: float literal 0x3f800000 at 0x1f4df8
 *   fpu: mov.s at 0x1f4e00 is a float copy
 *   literal: @774 initializes the 4-byte local at 0x128
 *   literal: @776 initializes the 4-byte local at 0x12c
 */




static void MGOrderCPUText1(void) {
    extern u32 GetDiceNum(void);
    u32 a2;
    u32 a1;
    u8 *s0;
    u32 a0;
    float f15;
    float f14;
    float f13;
    u32 v1;
    float f12;
    u32 v0;
    u8 stackFrame_20[264] __attribute__((aligned(16)));

    v0 = GetDiceNum();
    s0 = (u8 *)v0;
    f12 = 56.0f;
    f13 = 105.0f;
    {
        struct stackFrame_128 { u8 b[4]; } stackFrame_128 __attribute__((aligned(8))) = {{0xff,
            0xff, 0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_128);
        f14 = 0.800000012f;
        {
            struct stackFrame_12C { u8 b[4]; } stackFrame_12C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_12C);
            MGFontPrintXYSclColShadow(56.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)*(s32
                *)gsHdPlayerName);
            v0 = 0x43c50000;
            v1 = 0x43c50000 | 0x8000;
            f13 = 105.0f;
            v0 = 0x3f190000;
            f12 = 395.0f;
            v1 = 0x3f190000 | 0x999a;
            f14 = 0.600000024f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)395.0f, (f32)105.0f, 0.600000024f, 0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)*(s32
                *)(gsHdPlayerName + 1));
            a1 = *(s32 *)(gsHdNowPlayerMsg + 1);
            a2 = *(s32 *)(gsHdPlayerName + 1);
            FsFontReplaceText((void *)((u8 *)&stackFrame_20[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            a2 = (u32)((u8 *)&stackFrame_20[0]);
            f14 = 0.800000012f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, f15, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)a2);
            v0 = *(u8 *)s0;
            switch (v0) {
            case 1:
                v0 = 0x40000;
                a0 = 0x40000 | 0x9559;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 2:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955a;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 3:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955b;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 4:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955c;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 5:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955d;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 6:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955e;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 0:
            default:
                v0 = (u32)"";
            }
            f12 = 62.0f;
            a2 = v0;
            f13 = 140.0f;
            f14 = 1.0f;
            MGFontPrintXYSclColShadow(62.0f, 140.0f, 1.0f, (float)1.0f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)a2);
            return;
        }
    }
}



/* MGOrderCPUText2 @ 0x1F4A40 .. 0x1F4C24 (0x1e4 bytes, frame 0x130) */
/*
 * dcomp notes:
 *   literal: @2354 -> 0x257210
 *   literal: @1598 is the string ''
 *   call: GetDiceNum is declared void but its v0 is read: called as returning u32
 *   literal: @783 -> 0x2576cc
 *   fpu: float literal 0x42600000 at 0x1f4a68
 *   fpu: float literal 0x42d20000 at 0x1f4a70
 *   literal: @785 -> 0x2576d0
 *   fpu: float literal 0x3f4ccccd at 0x1f4a84
 *   fpu: mov.s at 0x1f4a9c is a float copy
 *   fpu: float literal 0x42d20000 at 0x1f4ab0
 *   fpu: float literal 0x43c58000 at 0x1f4ab8
 *   fpu: float literal 0x3f19999a at 0x1f4ad0
 *   fpu: float literal 0x3f4ccccd at 0x1f4ad4
 *   stack: address of the slot at 0x20 escapes at 0x1f4af0
 *   fpu: float literal 0x42400000 at 0x1f4b00
 *   fpu: float literal 0x41a00000 at 0x1f4b0c
 *   fpu: float literal 0x3f4ccccd at 0x1f4b1c
 *   fpu: mov.s at 0x1f4b24 is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x1f4b20
 *   indirect: jr v0 at 0x1f4b48 -> <v0>
 *   fpu: float literal 0x42780000 at 0x1f4bec
 *   fpu: float literal 0x430c0000 at 0x1f4c00
 *   fpu: float literal 0x3f800000 at 0x1f4c08
 *   fpu: mov.s at 0x1f4c10 is a float copy
 *   literal: @783 initializes the 4-byte local at 0x128
 *   literal: @785 initializes the 4-byte local at 0x12c
 */




static void MGOrderCPUText2(void) {
    extern u32 GetDiceNum(void);
    u32 a2;
    u32 a1;
    u8 *s0;
    u32 a0;
    float f15;
    float f14;
    float f13;
    u32 v1;
    float f12;
    u32 v0;
    u8 stackFrame_20[264] __attribute__((aligned(16)));

    v0 = GetDiceNum();
    s0 = (u8 *)v0;
    f12 = 56.0f;
    f13 = 105.0f;
    {
        struct stackFrame_128 { u8 b[4]; } stackFrame_128 __attribute__((aligned(8))) = {{0xff,
            0xff, 0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_128);
        f14 = 0.800000012f;
        {
            struct stackFrame_12C { u8 b[4]; } stackFrame_12C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_12C);
            MGFontPrintXYSclColShadow(56.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)*(s32
                *)gsHdPlayerName);
            v0 = 0x43c50000;
            v1 = 0x43c50000 | 0x8000;
            f13 = 105.0f;
            v0 = 0x3f190000;
            f12 = 395.0f;
            v1 = 0x3f190000 | 0x999a;
            f14 = 0.600000024f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)395.0f, (f32)105.0f, 0.600000024f, 0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)*(s32
                *)(gsHdPlayerName + 1));
            a1 = *(s32 *)(gsHdNowPlayerMsg + 1);
            a2 = *(s32 *)(gsHdPlayerName + 1);
            FsFontReplaceText((void *)((u8 *)&stackFrame_20[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            a2 = (u32)((u8 *)&stackFrame_20[0]);
            f14 = 0.800000012f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, f15, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)a2);
            v0 = *(u8 *)s0;
            switch (v0) {
            case 1:
                v0 = 0x40000;
                a0 = 0x40000 | 0x9559;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 2:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955a;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 3:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955b;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 4:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955c;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 5:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955d;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 6:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955e;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 0:
            default:
                v0 = (u32)"";
            }
            f12 = 62.0f;
            a2 = v0;
            f13 = 140.0f;
            f14 = 1.0f;
            MGFontPrintXYSclColShadow(62.0f, 140.0f, 1.0f, (float)1.0f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)a2);
            return;
        }
    }
}



/* MGOrderCPUText3 @ 0x1F47B0 .. 0x1F4A3C (0x28c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @2319 -> 0x2571f0
 *   literal: @1598 is the string ''
 *   literal: @2320 -> 0x2571d0
 *   call: GetDiceNum is declared void but its v0 is read: called as returning u32
 *   literal: @792 -> 0x2576d4
 *   fpu: float literal 0x42600000 at 0x1f47d8
 *   fpu: float literal 0x42d20000 at 0x1f47e0
 *   literal: @794 -> 0x2576d8
 *   fpu: float literal 0x3f4ccccd at 0x1f47f4
 *   fpu: mov.s at 0x1f480c is a float copy
 *   fpu: float literal 0x42d20000 at 0x1f4820
 *   fpu: float literal 0x43c58000 at 0x1f4828
 *   fpu: float literal 0x3f19999a at 0x1f4840
 *   fpu: float literal 0x3f4ccccd at 0x1f4844
 *   indirect: jr v0 at 0x1f4870 -> <v0>
 *   fpu: float literal 0x42780000 at 0x1f491c
 *   fpu: float literal 0x430c0000 at 0x1f4928
 *   fpu: float literal 0x3f800000 at 0x1f4930
 *   fpu: mov.s at 0x1f4938 is a float copy
 *   indirect: jr v0 at 0x1f495c -> <v0>
 *   fpu: float literal 0x43cf0000 at 0x1f4a04
 *   fpu: float literal 0x430c0000 at 0x1f4a18
 *   fpu: float literal 0x3f800000 at 0x1f4a20
 *   fpu: mov.s at 0x1f4a28 is a float copy
 *   literal: @792 initializes the 4-byte local at 0x28
 *   literal: @794 initializes the 4-byte local at 0x2c
 */




static void MGOrderCPUText3(void) {
    extern u32 GetDiceNum(void);
    u32 a2;
    u32 a1;
    u8 *s0;
    u32 a0;
    float f15;
    float f14;
    float f13;
    u32 v1;
    float f12;
    u32 v0;

    v0 = GetDiceNum();
    s0 = (u8 *)v0;
    f12 = 56.0f;
    f13 = 105.0f;
    {
        struct stackFrame_28 { u8 b[4]; } stackFrame_28 __attribute__((aligned(8))) = {{0xff, 0xff,
            0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_28);
        f14 = 0.800000012f;
        {
            struct stackFrame_2C { u8 b[4]; } stackFrame_2C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_2C);
            MGFontPrintXYSclColShadow(56.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)*(s32
                *)gsHdPlayerName);
            v0 = 0x43c50000;
            v1 = 0x43c50000 | 0x8000;
            f13 = 105.0f;
            v0 = 0x3f190000;
            f12 = 395.0f;
            v1 = 0x3f190000 | 0x999a;
            f14 = 0.600000024f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)395.0f, (f32)105.0f, 0.600000024f, 0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)*(s32
                *)(gsHdPlayerName + 1));
            v0 = *(u8 *)s0;
            v1 = 0x2571f0;
            switch (v0) {
            case 1:
                v0 = 0x40000;
                a0 = 0x40000 | 0x9559;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 2:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955a;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 3:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955b;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 4:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955c;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 5:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955d;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 6:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955e;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 0:
            default:
                v0 = (u32)"";
            }
            a2 = v0;
            f12 = 62.0f;
            f13 = 140.0f;
            f14 = 1.0f;
            f15 = 1.0f;
            MGFontPrintXYSclColShadow(62.0f, 140.0f, 1.0f, f15, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)a2);
            v0 = *(u8 *)(s0 + 1);
            v1 = 0x2571d0;
            switch (v0) {
            case 1:
                v0 = 0x40000;
                a0 = 0x40000 | 0x9559;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 2:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955a;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 3:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955b;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 4:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955c;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 5:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955d;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 6:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955e;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 0:
            default:
                v0 = (u32)"";
            }
            f12 = 414.0f;
            a2 = v0;
            f13 = 140.0f;
            f14 = 1.0f;
            MGFontPrintXYSclColShadow(414.0f, 140.0f, 1.0f, (float)1.0f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)a2);
            return;
        }
    }
}



/* MGOrderLastView @ 0x1F4420 .. 0x1F47A8 (0x388 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @2264 -> 0x2571b0
 *   literal: @1598 is the string ''
 *   literal: @2265 -> 0x257190
 *   call: GetDiceNum is declared void but its v0 is read: called as returning u32
 *   literal: @800 -> 0x2576dc
 *   fpu: float literal 0x42600000 at 0x1f4448
 *   fpu: float literal 0x42d20000 at 0x1f4450
 *   literal: @802 -> 0x2576e0
 *   fpu: float literal 0x3f4ccccd at 0x1f4464
 *   fpu: mov.s at 0x1f447c is a float copy
 *   fpu: float literal 0x42d20000 at 0x1f4490
 *   fpu: float literal 0x43c58000 at 0x1f4498
 *   fpu: float literal 0x3f19999a at 0x1f44b0
 *   fpu: float literal 0x3f4ccccd at 0x1f44b4
 *   indirect: jr v0 at 0x1f44e0 -> <v0>
 *   fpu: float literal 0x42780000 at 0x1f458c
 *   fpu: float literal 0x430c0000 at 0x1f4598
 *   fpu: float literal 0x3f800000 at 0x1f45a0
 *   fpu: mov.s at 0x1f45a8 is a float copy
 *   indirect: jr v0 at 0x1f45cc -> <v0>
 *   fpu: float literal 0x43cf0000 at 0x1f467c
 *   fpu: float literal 0x430c0000 at 0x1f4688
 *   fpu: float literal 0x3f800000 at 0x1f4690
 *   fpu: mov.s at 0x1f4698 is a float copy
 *   fpu: float literal 0x42400000 at 0x1f46a4
 *   fpu: float literal 0x43c30000 at 0x1f46b0
 *   fpu: float literal 0x3f4ccccd at 0x1f46c0
 *   fpu: mov.s at 0x1f46c8 is a float copy
 *   fpu: float literal 0x42400000 at 0x1f46e4
 *   fpu: float literal 0x41a00000 at 0x1f46f0
 *   fpu: float literal 0x3f4ccccd at 0x1f4700
 *   fpu: mov.s at 0x1f4708 is a float copy
 *   fpu: float literal 0x42400000 at 0x1f472c
 *   fpu: float literal 0x41a00000 at 0x1f4738
 *   fpu: float literal 0x3f4ccccd at 0x1f474c
 *   fpu: mov.s at 0x1f4754 is a float copy
 *   fpu: float literal 0x42400000 at 0x1f4764
 *   fpu: float literal 0x41a00000 at 0x1f4778
 *   fpu: float literal 0x3f4ccccd at 0x1f4788
 *   fpu: mov.s at 0x1f4790 is a float copy
 *   literal: @800 initializes the 4-byte local at 0x28
 *   literal: @802 initializes the 4-byte local at 0x2c
 */



extern u32 gsOrderRetryMsg;
extern u32 gsOrderEndMsg[];

static void MGOrderLastView(void) {
    extern u32 GetDiceNum(void);
    u32 a2;
    u32 a1;
    u8 *s0;
    u32 a0;
    float f15;
    float f14;
    float f13;
    u32 v1;
    float f12;
    u32 v0;

    v0 = GetDiceNum();
    s0 = (u8 *)v0;
    f12 = 56.0f;
    f13 = 105.0f;
    {
        struct stackFrame_28 { u8 b[4]; } stackFrame_28 __attribute__((aligned(8))) = {{0xff, 0xff,
            0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_28);
        f14 = 0.800000012f;
        {
            struct stackFrame_2C { u8 b[4]; } stackFrame_2C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_2C);
            MGFontPrintXYSclColShadow(56.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)*(s32
                *)gsHdPlayerName);
            v0 = 0x43c50000;
            v1 = 0x43c50000 | 0x8000;
            f13 = 105.0f;
            v0 = 0x3f190000;
            f12 = 395.0f;
            v1 = 0x3f190000 | 0x999a;
            f14 = 0.600000024f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)395.0f, (f32)105.0f, 0.600000024f, 0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)*(s32
                *)(gsHdPlayerName + 1));
            v0 = *(u8 *)s0;
            v1 = 0x2571b0;
            switch (v0) {
            case 1:
                v0 = 0x40000;
                a0 = 0x40000 | 0x9559;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 2:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955a;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 3:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955b;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 4:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955c;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 5:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955d;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 6:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955e;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 0:
            default:
                v0 = (u32)"";
            }
            a2 = v0;
            f12 = 62.0f;
            f13 = 140.0f;
            f14 = 1.0f;
            f15 = 1.0f;
            MGFontPrintXYSclColShadow(62.0f, 140.0f, 1.0f, f15, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)a2);
            v0 = *(u8 *)(s0 + 1);
            v1 = 0x257190;
            switch (v0) {
            case 1:
                v0 = 0x40000;
                a0 = 0x40000 | 0x9559;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 2:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955a;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 3:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955b;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 4:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955c;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 5:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955d;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 6:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955e;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 0:
            default:
                v0 = (u32)"";
            }
            a2 = v0;
            f12 = 414.0f;
            f13 = 140.0f;
            f14 = 1.0f;
            MGFontPrintXYSclColShadow(414.0f, 140.0f, 1.0f, (float)1.0f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)a2);
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)gsHelpKakunin);
            v1 = *(u8 *)(s0 + 1);
            v0 = *(u8 *)s0;
            if (v0 == v1) {
                f12 = 48.0f;
                f13 = 20.0f;
                f14 = 0.800000012f;
                MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                    dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                    dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char
                    *)gsOrderRetryMsg);
            } else if ((s32)v1 < (s32)v0) {
                f12 = 48.0f;
                f13 = 20.0f;
                f14 = 0.800000012f;
                MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                    dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                    dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)*(s32
                    *)gsOrderEndMsg);
            } else {
                f12 = 48.0f;
                f13 = 20.0f;
                f14 = 0.800000012f;
                MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                    dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                    dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)*(s32
                    *)(gsOrderEndMsg + 1));
            }
            return;
        }
    }
}


/* MGDiceThrowPlayer @ 0x1F4370 .. 0x1F441C (0xac bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @814 -> 0x2576e4
 *   literal: @816 -> 0x2576e8
 *   stack: address of the slot at 0x10 escapes at 0x1f43a8
 *   fpu: float literal 0x42400000 at 0x1f43b8
 *   fpu: float literal 0x41a00000 at 0x1f43c4
 *   fpu: float literal 0x3f4ccccd at 0x1f43d4
 *   fpu: mov.s at 0x1f43dc is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f43d8
 *   fpu: float literal 0x42400000 at 0x1f43e8
 *   fpu: float literal 0x43c30000 at 0x1f43f4
 *   fpu: float literal 0x3f4ccccd at 0x1f4404
 *   fpu: mov.s at 0x1f440c is a float copy
 *   literal: @816 initializes the 4-byte local at 0x118
 *   literal: @814 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif
extern void GetDiceNum(void);






static void MGDiceThrowPlayer(void) {
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    GetDiceNum();
    {
        struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        v1 = (u32)((u8 *)&stackFrame_11C);
        {
            struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v0 = (u32)((u8 *)&stackFrame_118);
            a1 = *(s32 *)gsHdNowPlayerMsg;
            a2 = *(s32 *)gsHdPlayerName;
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)((u8
                *)&stackFrame_10[0]));
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)gsHelpDiceCast);
            return;
        }
    }
}


/* MGDiceThrowPlayer1 @ 0x1F42F0 .. 0x1F436C (0x7c bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @823 -> 0x2576ec
 *   literal: @825 -> 0x2576f0
 *   stack: address of the slot at 0x10 escapes at 0x1f4328
 *   fpu: float literal 0x42400000 at 0x1f4338
 *   fpu: float literal 0x41a00000 at 0x1f4344
 *   fpu: float literal 0x3f4ccccd at 0x1f4354
 *   fpu: mov.s at 0x1f435c is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f4358
 *   literal: @825 initializes the 4-byte local at 0x118
 *   literal: @823 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif






static void MGDiceThrowPlayer1(void) {
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    GetDiceNum();
    {
        struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        v1 = (u32)((u8 *)&stackFrame_11C);
        {
            struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v0 = (u32)((u8 *)&stackFrame_118);
            a1 = *(s32 *)gsHdNowPlayerMsg;
            a2 = *(s32 *)gsHdPlayerName;
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)((u8
                *)&stackFrame_10[0]));
            return;
        }
    }
}


/* MGChoisePiecePlayer @ 0x1F4240 .. 0x1F42EC (0xac bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @834 -> 0x2576f4
 *   literal: @836 -> 0x2576f8
 *   stack: address of the slot at 0x10 escapes at 0x1f4278
 *   fpu: float literal 0x42400000 at 0x1f4288
 *   fpu: float literal 0x41a00000 at 0x1f4294
 *   fpu: float literal 0x3f4ccccd at 0x1f42a4
 *   fpu: mov.s at 0x1f42ac is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f42a8
 *   fpu: float literal 0x42400000 at 0x1f42b8
 *   fpu: float literal 0x43c30000 at 0x1f42c4
 *   fpu: float literal 0x3f4ccccd at 0x1f42d4
 *   fpu: mov.s at 0x1f42dc is a float copy
 *   literal: @836 initializes the 4-byte local at 0x118
 *   literal: @834 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif





extern u32 gsHelpChoiKoma;

static void MGChoisePiecePlayer(void) {
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    GetDiceNum();
    {
        struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        v1 = (u32)((u8 *)&stackFrame_11C);
        {
            struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v0 = (u32)((u8 *)&stackFrame_118);
            a1 = *(s32 *)gsHdNowPlayerMsg;
            a2 = *(s32 *)gsHdPlayerName;
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)((u8
                *)&stackFrame_10[0]));
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)gsHelpChoiKoma);
            return;
        }
    }
}


/* MGChoiseDiePlayer @ 0x1F4190 .. 0x1F423C (0xac bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @845 -> 0x2576fc
 *   literal: @847 -> 0x257700
 *   stack: address of the slot at 0x10 escapes at 0x1f41c8
 *   fpu: float literal 0x42400000 at 0x1f41d8
 *   fpu: float literal 0x41a00000 at 0x1f41e4
 *   fpu: float literal 0x3f4ccccd at 0x1f41f4
 *   fpu: mov.s at 0x1f41fc is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f41f8
 *   fpu: float literal 0x42400000 at 0x1f4208
 *   fpu: float literal 0x43c30000 at 0x1f4214
 *   fpu: float literal 0x3f4ccccd at 0x1f4224
 *   fpu: mov.s at 0x1f422c is a float copy
 *   literal: @847 initializes the 4-byte local at 0x118
 *   literal: @845 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif





extern u32 gsHelpChoiDice;

static void MGChoiseDiePlayer(void) {
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    GetDiceNum();
    {
        struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        v1 = (u32)((u8 *)&stackFrame_11C);
        {
            struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v0 = (u32)((u8 *)&stackFrame_118);
            a1 = *(s32 *)gsHdNowPlayerMsg;
            a2 = *(s32 *)gsHdPlayerName;
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)((u8
                *)&stackFrame_10[0]));
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)gsHelpChoiDice);
            return;
        }
    }
}


/* MGDiceThrowCPU @ 0x1F4110 .. 0x1F418C (0x7c bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @856 -> 0x257704
 *   literal: @858 -> 0x257708
 *   stack: address of the slot at 0x10 escapes at 0x1f4148
 *   fpu: float literal 0x42400000 at 0x1f4158
 *   fpu: float literal 0x41a00000 at 0x1f4164
 *   fpu: float literal 0x3f4ccccd at 0x1f4174
 *   fpu: mov.s at 0x1f417c is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f4178
 *   literal: @858 initializes the 4-byte local at 0x118
 *   literal: @856 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif






static void MGDiceThrowCPU(void) {
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    GetDiceNum();
    {
        struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        v1 = (u32)((u8 *)&stackFrame_11C);
        {
            struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v0 = (u32)((u8 *)&stackFrame_118);
            a1 = *(s32 *)(gsHdNowPlayerMsg + 1);
            a2 = *(s32 *)(gsHdPlayerName + 1);
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)((u8
                *)&stackFrame_10[0]));
            return;
        }
    }
}


/* MGViewResult @ 0x1F3EC0 .. 0x1F410C (0x24c bytes, frame 0x140) */
/*
 * dcomp notes:
 *   literal: @883 -> 0x25770c
 *   literal: @885 -> 0x257710
 *   literal: @887 -> 0x257714
 *   literal: @889 -> 0x257718
 *   fpu: float literal 0x42340000 at 0x1f3f2c
 *   fpu: float literal 0x43960000 at 0x1f3f3c
 *   fpu: float literal 0x3f800000 at 0x1f3f44
 *   fpu: mov.s at 0x1f3f4c is a float copy
 *   stack: address of the slot at 0x30 escapes at 0x1f3f5c
 *   fpu: float literal 0x42340000 at 0x1f3f6c
 *   fpu: float literal 0x43a40000 at 0x1f3f78
 *   fpu: float literal 0x3f800000 at 0x1f3f84
 *   fpu: mov.s at 0x1f3f8c is a float copy
 *   stack: address of the slot at 0x30 escapes at 0x1f3f88
 *   stack: address of the slot at 0x30 escapes at 0x1f3f9c
 *   fpu: float literal 0x42340000 at 0x1f3fac
 *   fpu: float literal 0x43b20000 at 0x1f3fb8
 *   fpu: float literal 0x3f800000 at 0x1f3fc4
 *   fpu: mov.s at 0x1f3fcc is a float copy
 *   stack: address of the slot at 0x30 escapes at 0x1f3fc8
 *   fpu: float literal 0x43a00000 at 0x1f3fd8
 *   fpu: float literal 0x43960000 at 0x1f3fe4
 *   fpu: float literal 0x3f4ccccd at 0x1f3ff8
 *   fpu: mov.s at 0x1f4000 is a float copy
 *   fpu: float literal 0x43a00000 at 0x1f4018
 *   fpu: float literal 0x43a40000 at 0x1f4024
 *   fpu: float literal 0x3f4ccccd at 0x1f4038
 *   fpu: mov.s at 0x1f4040 is a float copy
 *   fpu: float literal 0x43a00000 at 0x1f404c
 *   fpu: float literal 0x43b20000 at 0x1f4058
 *   fpu: float literal 0x3f4ccccd at 0x1f406c
 *   fpu: mov.s at 0x1f4074 is a float copy
 *   fpu: float literal 0x43a00000 at 0x1f4094
 *   fpu: float literal 0x43a40000 at 0x1f40a0
 *   fpu: float literal 0x3f4ccccd at 0x1f40b4
 *   fpu: mov.s at 0x1f40bc is a float copy
 *   fpu: float literal 0x43a00000 at 0x1f40c8
 *   fpu: float literal 0x43b20000 at 0x1f40d4
 *   fpu: float literal 0x3f4ccccd at 0x1f40e8
 *   fpu: mov.s at 0x1f40f0 is a float copy
 *   literal: @889 initializes the 4-byte local at 0x130
 *   literal: @887 initializes the 4-byte local at 0x134
 *   literal: @885 initializes the 4-byte local at 0x138
 *   literal: @883 initializes the 4-byte local at 0x13c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif

extern u32 GetWinNum(void);
extern void GetPieceTable(void);
extern u32 GetMenuPos(void);


extern u32 gsScoreMsg[];
extern u32 gsReplayMsg[];

static void MGViewResult(void) {
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u8 *s1;
    u8 *s0;
    float f14;
    u32 v0;
    float f13;
    float f12;
    u8 stackFrame_30[256] __attribute__((aligned(16)));

    {
        struct stackFrame_13C { u8 b[4]; } stackFrame_13C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_13C);
        {
            struct stackFrame_138 { u8 b[4]; } stackFrame_138 __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_138);
            {
                struct stackFrame_134 { u8 b[4]; } stackFrame_134 __attribute__((aligned(4))) =
                    {{0xff, 0x99, 0x00, 0x80}};
                v1 = (u32)((u8 *)&stackFrame_134);
                {
                    struct stackFrame_130 { u8 b[4]; } stackFrame_130 __attribute__((aligned(8))) =
                        {{0xff, 0xff, 0xff, 0x30}};
                    v0 = (u32)((u8 *)&stackFrame_130);
                    GetDiceNum();
                    v0 = GetWinNum();
                    s1 = (u8 *)v0;
                    GetPieceTable();
                    v0 = GetMenuPos();
                    s0 = (u8 *)v0;
                    f12 = 45.0f;
                    f13 = 300.0f;
                    f14 = 1.0f;
                    MGFontPrintXYSclColShadow(45.0f, 300.0f, 1.0f, (float)1.0f, *(struct
                        dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_13C)), *(struct
                        dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_138)), (char *)*(s32
                        *)gsScoreMsg);
                    a2 = *(u8 *)s1;
                    a1 = *(s32 *)(gsScoreMsg + 1);
                    FsFontReplaceText((void *)((u8 *)&stackFrame_30[0]), (void *)a1, a2);
                    f12 = 45.0f;
                    f13 = 328.0f;
                    f14 = 1.0f;
                    MGFontPrintXYSclColShadow(45.0f, 328.0f, 1.0f, (float)1.0f, *(struct
                        dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_13C)), *(struct
                        dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_138)), (char *)((u8
                        *)&stackFrame_30[0]));
                    a1 = *(s32 *)(gsScoreMsg + 2);
                    FsFontReplaceText((void *)((u8 *)&stackFrame_30[0]), (void *)a1, (u32)*(u8
                        *)(s1 + 1));
                    f12 = 45.0f;
                    f13 = 356.0f;
                    f14 = 1.0f;
                    MGFontPrintXYSclColShadow(45.0f, 356.0f, 1.0f, (float)1.0f, *(struct
                        dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_13C)), *(struct
                        dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_138)), (char *)((u8
                        *)&stackFrame_30[0]));
                    f12 = 320.0f;
                    f13 = 300.0f;
                    f14 = 0.800000012f;
                    MGFontPrintXYSclColShadow(320.0f, 300.0f, 0.800000012f, (float)0.800000012f,
                        *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_13C)), *(struct
                        dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_138)), (char *)*(s32
                        *)gsReplayMsg);
                    a0 = *(u8 *)s0;
                    if (a0 == 0) {
                        f12 = 320.0f;
                        f13 = 328.0f;
                        f14 = 0.800000012f;
                        MGFontPrintXYSclColShadow(320.0f, 328.0f, 0.800000012f,
                            (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_134)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_138)), (char *)*(s32 *)(gsReplayMsg + 1));
                        f12 = 320.0f;
                        f13 = 356.0f;
                        f14 = 0.800000012f;
                        MGFontPrintXYSclColShadow(320.0f, 356.0f, 0.800000012f,
                            (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_130)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_138)), (char *)*(s32 *)(gsReplayMsg + 2));
                    } else if (a0 == (u32)1) {
                        f12 = 320.0f;
                        f13 = 328.0f;
                        f14 = 0.800000012f;
                        MGFontPrintXYSclColShadow(320.0f, 328.0f, 0.800000012f,
                            (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_130)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_138)), (char *)*(s32 *)(gsReplayMsg + 1));
                        f12 = 320.0f;
                        f13 = 356.0f;
                        f14 = 0.800000012f;
                        MGFontPrintXYSclColShadow(320.0f, 356.0f, 0.800000012f,
                            (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_134)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_138)), (char *)*(s32 *)(gsReplayMsg + 2));
                    }
                    return;
                }
            }
        }
    }
}


/* MGComplsionText @ 0x1F3D30 .. 0x1F3EB8 (0x188 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @930 -> 0x25771c
 *   literal: @932 -> 0x257720
 *   literal: @934 -> 0x257724
 *   literal: @936 -> 0x257728
 *   literal: @938 -> 0x25772c
 *   fpu: float literal 0x431c0000 at 0x1f3d8c
 *   fpu: float literal 0x432f0000 at 0x1f3d9c
 *   fpu: float literal 0x3f4ccccd at 0x1f3da8
 *   fpu: mov.s at 0x1f3db0 is a float copy
 *   fpu: float literal 0x436c0000 at 0x1f3dc8
 *   fpu: float literal 0x435c0000 at 0x1f3dd4
 *   fpu: float literal 0x3f4ccccd at 0x1f3de8
 *   fpu: mov.s at 0x1f3df0 is a float copy
 *   fpu: float literal 0x43700000 at 0x1f3dfc
 *   fpu: float literal 0x43750000 at 0x1f3e08
 *   fpu: float literal 0x3f4ccccd at 0x1f3e1c
 *   fpu: mov.s at 0x1f3e24 is a float copy
 *   fpu: float literal 0x436c0000 at 0x1f3e44
 *   fpu: float literal 0x435c0000 at 0x1f3e50
 *   fpu: float literal 0x3f4ccccd at 0x1f3e64
 *   fpu: mov.s at 0x1f3e6c is a float copy
 *   fpu: float literal 0x43700000 at 0x1f3e78
 *   fpu: float literal 0x43750000 at 0x1f3e84
 *   fpu: float literal 0x3f4ccccd at 0x1f3e98
 *   fpu: mov.s at 0x1f3ea0 is a float copy
 *   literal: @938 initializes the 4-byte local at 0x2c
 *   literal: @936 initializes the 4-byte local at 0x30
 *   literal: @934 initializes the 4-byte local at 0x34
 *   literal: @932 initializes the 4-byte local at 0x38
 *   literal: @930 initializes the 4-byte local at 0x3c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif


extern u32 gsGameEndMsg[];

void MGComplsionText(void) {
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u8 *s0;
    float f14;
    float f13;
    float f12;

    {
        struct stackFrame_3C { u8 b[4]; } stackFrame_3C __attribute__((aligned(4))) = {{0xff, 0xff,
            0xff, 0x80}};
        a2 = (u32)((u8 *)&stackFrame_3C);
        {
            struct stackFrame_38 { u8 b[4]; } stackFrame_38 __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a1 = (u32)((u8 *)&stackFrame_38);
            {
                struct stackFrame_34 { u8 b[4]; } stackFrame_34 __attribute__((aligned(4))) =
                    {{0xff, 0x99, 0x00, 0x80}};
                a0 = (u32)((u8 *)&stackFrame_34);
                {
                    struct stackFrame_30 { u8 b[4]; } stackFrame_30 __attribute__((aligned(4))) =
                        {{0xff, 0x99, 0x00, 0x80}};
                    v1 = (u32)((u8 *)&stackFrame_30);
                    {
                        struct stackFrame_2C { u8 b[4]; } stackFrame_2C __attribute__((aligned(4)))
                            = {{0xff, 0xff, 0xff, 0x30}};
                        v0 = (u32)((u8 *)&stackFrame_2C);
                        v0 = GetMenuPos();
                        s0 = (u8 *)v0;
                        f12 = 156.0f;
                        f13 = 175.0f;
                        f14 = 0.800000012f;
                        MGFontPrintXYSclColShadow(156.0f, 175.0f, 0.800000012f,
                            (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_3C)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_38)), (char *)*(s32 *)gsGameEndMsg);
                        a0 = *(u8 *)s0;
                        if (a0 == 0) {
                            f12 = 236.0f;
                            f13 = 220.0f;
                            f14 = 0.800000012f;
                            MGFontPrintXYSclColShadow(236.0f, 220.0f, 0.800000012f,
                                (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                                *)&stackFrame_34)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                                *)&stackFrame_38)), (char *)*(s32 *)(gsGameEndMsg + 1));
                            f12 = 240.0f;
                            f13 = 245.0f;
                            f14 = 0.800000012f;
                            MGFontPrintXYSclColShadow(240.0f, 245.0f, 0.800000012f,
                                (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                                *)&stackFrame_2C)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                                *)&stackFrame_38)), (char *)*(s32 *)(gsGameEndMsg + 2));
                        } else if (a0 == (u32)1) {
                            f12 = 236.0f;
                            f13 = 220.0f;
                            f14 = 0.800000012f;
                            MGFontPrintXYSclColShadow(236.0f, 220.0f, 0.800000012f,
                                (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                                *)&stackFrame_2C)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                                *)&stackFrame_38)), (char *)*(s32 *)(gsGameEndMsg + 1));
                            f12 = 240.0f;
                            f13 = 245.0f;
                            f14 = 0.800000012f;
                            MGFontPrintXYSclColShadow(240.0f, 245.0f, 0.800000012f,
                                (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                                *)&stackFrame_30)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                                *)&stackFrame_38)), (char *)*(s32 *)(gsGameEndMsg + 2));
                        }
                        return;
                    }
                }
            }
        }
    }
}


/* MGTutorialText1View @ 0x1F3B60 .. 0x1F3D30 (0x1d0 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @958 -> 0x257730
 *   literal: @960 -> 0x257734
 *   fpu: float literal 0x42800000 at 0x1f3b9c
 *   fpu: float literal 0x42980000 at 0x1f3ba4
 *   fpu: float literal 0x3f4ccccd at 0x1f3bb0
 *   fpu: mov.s at 0x1f3bb8 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3bd8
 *   fpu: float literal 0x42d00000 at 0x1f3be0
 *   fpu: float literal 0x3f4ccccd at 0x1f3bec
 *   fpu: mov.s at 0x1f3bf4 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3c14
 *   fpu: float literal 0x43040000 at 0x1f3c1c
 *   fpu: float literal 0x3f4ccccd at 0x1f3c28
 *   fpu: mov.s at 0x1f3c30 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3c50
 *   fpu: float literal 0x43200000 at 0x1f3c58
 *   fpu: float literal 0x3f4ccccd at 0x1f3c64
 *   fpu: mov.s at 0x1f3c6c is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3c8c
 *   fpu: float literal 0x433c0000 at 0x1f3c94
 *   fpu: float literal 0x3f4ccccd at 0x1f3ca0
 *   fpu: mov.s at 0x1f3ca8 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3cc8
 *   fpu: float literal 0x43580000 at 0x1f3cd0
 *   fpu: float literal 0x3f4ccccd at 0x1f3cdc
 *   fpu: mov.s at 0x1f3ce4 is a float copy
 *   fpu: float literal 0x43880000 at 0x1f3cfc
 *   fpu: float literal 0x42800000 at 0x1f3d04
 *   fpu: float literal 0x3f4ccccd at 0x1f3d18
 *   fpu: mov.s at 0x1f3d20 is a float copy
 *   literal: @960 initializes the 4-byte local at 0x18
 *   literal: @958 initializes the 4-byte local at 0x1c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif
extern unsigned short * KnMsgMng_GetMsgStr(signed int);


static void MGTutorialText1View(void) {
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;

    v0 = 0x40000;
    {
        struct stackFrame_1C { u8 b[4]; } stackFrame_1C __attribute__((aligned(4))) = {{0xff, 0xff,
            0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_1C);
        {
            struct stackFrame_18 { u8 b[4]; } stackFrame_18 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v1 = (u32)((u8 *)&stackFrame_18);
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x951d);
            f12 = 64.0f;
            f13 = 76.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 76.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x951e);
            f12 = 64.0f;
            f13 = 104.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 104.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9520);
            f12 = 64.0f;
            f13 = 132.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 132.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9521);
            f12 = 64.0f;
            f13 = 160.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 160.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9522);
            f12 = 64.0f;
            f13 = 188.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 188.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9523);
            f12 = 64.0f;
            f13 = 216.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 216.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9524);
            f13 = 272.0f;
            f12 = 64.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)64.0f, (f32)272.0f, 0.800000012f, (float)0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            return;
        }
    }
}


/* MGTutorialText2View @ 0x1F3910 .. 0x1F3B58 (0x248 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @965 -> 0x257738
 *   literal: @967 -> 0x25773c
 *   fpu: float literal 0x42800000 at 0x1f394c
 *   fpu: float literal 0x42980000 at 0x1f3954
 *   fpu: float literal 0x3f4ccccd at 0x1f3960
 *   fpu: mov.s at 0x1f3968 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3988
 *   fpu: float literal 0x42d00000 at 0x1f3990
 *   fpu: float literal 0x3f4ccccd at 0x1f399c
 *   fpu: mov.s at 0x1f39a4 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f39c4
 *   fpu: float literal 0x43040000 at 0x1f39cc
 *   fpu: float literal 0x3f4ccccd at 0x1f39d8
 *   fpu: mov.s at 0x1f39e0 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3a00
 *   fpu: float literal 0x43200000 at 0x1f3a08
 *   fpu: float literal 0x3f4ccccd at 0x1f3a14
 *   fpu: mov.s at 0x1f3a1c is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3a3c
 *   fpu: float literal 0x43580000 at 0x1f3a44
 *   fpu: float literal 0x3f4ccccd at 0x1f3a50
 *   fpu: mov.s at 0x1f3a58 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3a78
 *   fpu: float literal 0x43740000 at 0x1f3a80
 *   fpu: float literal 0x3f4ccccd at 0x1f3a8c
 *   fpu: mov.s at 0x1f3a94 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3ab4
 *   fpu: float literal 0x43880000 at 0x1f3abc
 *   fpu: float literal 0x3f4ccccd at 0x1f3ac8
 *   fpu: mov.s at 0x1f3ad0 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3af0
 *   fpu: float literal 0x43960000 at 0x1f3af8
 *   fpu: float literal 0x3f4ccccd at 0x1f3b04
 *   fpu: mov.s at 0x1f3b0c is a float copy
 *   fpu: float literal 0x43a40000 at 0x1f3b24
 *   fpu: float literal 0x42800000 at 0x1f3b2c
 *   fpu: float literal 0x3f4ccccd at 0x1f3b40
 *   fpu: mov.s at 0x1f3b48 is a float copy
 *   literal: @967 initializes the 4-byte local at 0x18
 *   literal: @965 initializes the 4-byte local at 0x1c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif



static void MGTutorialText2View(void) {
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;

    v0 = 0x40000;
    {
        struct stackFrame_1C { u8 b[4]; } stackFrame_1C __attribute__((aligned(4))) = {{0xff, 0xff,
            0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_1C);
        {
            struct stackFrame_18 { u8 b[4]; } stackFrame_18 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v1 = (u32)((u8 *)&stackFrame_18);
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9526);
            f12 = 64.0f;
            f13 = 76.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 76.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9527);
            f12 = 64.0f;
            f13 = 104.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 104.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9528);
            f12 = 64.0f;
            f13 = 132.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 132.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9529);
            f12 = 64.0f;
            f13 = 160.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 160.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x952a);
            f12 = 64.0f;
            f13 = 216.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 216.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x952b);
            f12 = 64.0f;
            f13 = 244.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 244.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x952c);
            f12 = 64.0f;
            f13 = 272.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 272.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x952d);
            f12 = 64.0f;
            f13 = 300.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 300.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x952e);
            f13 = 328.0f;
            f12 = 64.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)64.0f, (f32)328.0f, 0.800000012f, (float)0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            return;
        }
    }
}


/* MGTutorialText3View @ 0x1F3770 .. 0x1F3904 (0x194 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @972 -> 0x257740
 *   literal: @974 -> 0x257744
 *   fpu: float literal 0x42800000 at 0x1f37ac
 *   fpu: float literal 0x42980000 at 0x1f37b4
 *   fpu: float literal 0x3f4ccccd at 0x1f37c0
 *   fpu: mov.s at 0x1f37c8 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f37e8
 *   fpu: float literal 0x42d00000 at 0x1f37f0
 *   fpu: float literal 0x3f4ccccd at 0x1f37fc
 *   fpu: mov.s at 0x1f3804 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3824
 *   fpu: float literal 0x43200000 at 0x1f382c
 *   fpu: float literal 0x3f4ccccd at 0x1f3838
 *   fpu: mov.s at 0x1f3840 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3860
 *   fpu: float literal 0x43580000 at 0x1f3868
 *   fpu: float literal 0x3f4ccccd at 0x1f3874
 *   fpu: mov.s at 0x1f387c is a float copy
 *   fpu: float literal 0x42800000 at 0x1f389c
 *   fpu: float literal 0x43740000 at 0x1f38a4
 *   fpu: float literal 0x3f4ccccd at 0x1f38b0
 *   fpu: mov.s at 0x1f38b8 is a float copy
 *   fpu: float literal 0x43960000 at 0x1f38d0
 *   fpu: float literal 0x42800000 at 0x1f38d8
 *   fpu: float literal 0x3f4ccccd at 0x1f38ec
 *   fpu: mov.s at 0x1f38f4 is a float copy
 *   literal: @974 initializes the 4-byte local at 0x18
 *   literal: @972 initializes the 4-byte local at 0x1c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif



static void MGTutorialText3View(void) {
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;

    v0 = 0x40000;
    {
        struct stackFrame_1C { u8 b[4]; } stackFrame_1C __attribute__((aligned(4))) = {{0xff, 0xff,
            0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_1C);
        {
            struct stackFrame_18 { u8 b[4]; } stackFrame_18 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v1 = (u32)((u8 *)&stackFrame_18);
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x952f);
            f12 = 64.0f;
            f13 = 76.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 76.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9530);
            f12 = 64.0f;
            f13 = 104.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 104.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9532);
            f12 = 64.0f;
            f13 = 160.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 160.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9534);
            f12 = 64.0f;
            f13 = 216.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 216.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9535);
            f12 = 64.0f;
            f13 = 244.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 244.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9536);
            f13 = 300.0f;
            f12 = 64.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)64.0f, (f32)300.0f, 0.800000012f, (float)0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            return;
        }
    }
}

/* MGTutorialThrowText @ 0x1F36C0 .. 0x1F3764 (0xa4 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @979 -> 0x257748
 *   literal: @981 -> 0x25774c
 *   fpu: float literal 0x42800000 at 0x1f36fc
 *   fpu: float literal 0x41a00000 at 0x1f3704
 *   fpu: float literal 0x3f4ccccd at 0x1f3710
 *   fpu: mov.s at 0x1f3718 is a float copy
 *   fpu: float literal 0x43c30000 at 0x1f3730
 *   fpu: float literal 0x42400000 at 0x1f3738
 *   fpu: float literal 0x3f4ccccd at 0x1f374c
 *   fpu: mov.s at 0x1f3754 is a float copy
 *   literal: @981 initializes the 4-byte local at 0x18
 *   literal: @979 initializes the 4-byte local at 0x1c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif



static void MGTutorialThrowText(void) {
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;

    v0 = 0x40000;
    {
        struct stackFrame_1C { u8 b[4]; } stackFrame_1C __attribute__((aligned(4))) = {{0xff, 0xff,
            0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_1C);
        {
            struct stackFrame_18 { u8 b[4]; } stackFrame_18 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v1 = (u32)((u8 *)&stackFrame_18);
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9538);
            f12 = 64.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9539);
            f13 = 390.0f;
            f12 = 48.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)48.0f, (f32)390.0f, 0.800000012f, (float)0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            return;
        }
    }
}
/* MGTutorialThrowNowText @ 0x1F36B0 .. 0x1F36B8 (0x8 bytes) */




static void MGTutorialThrowNowText(void) {
    return;
}



/* MGTutorialChoisePiece @ 0x1F3600 .. 0x1F36A4 (0xa4 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @991 -> 0x257750
 *   literal: @993 -> 0x257754
 *   fpu: float literal 0x42800000 at 0x1f363c
 *   fpu: float literal 0x41a00000 at 0x1f3644
 *   fpu: float literal 0x3f4ccccd at 0x1f3650
 *   fpu: mov.s at 0x1f3658 is a float copy
 *   fpu: float literal 0x43c30000 at 0x1f3670
 *   fpu: float literal 0x42400000 at 0x1f3678
 *   fpu: float literal 0x3f4ccccd at 0x1f368c
 *   fpu: mov.s at 0x1f3694 is a float copy
 *   literal: @993 initializes the 4-byte local at 0x18
 *   literal: @991 initializes the 4-byte local at 0x1c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif



static void MGTutorialChoisePiece(void) {
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;

    v0 = 0x40000;
    {
        struct stackFrame_1C { u8 b[4]; } stackFrame_1C __attribute__((aligned(4))) = {{0xff, 0xff,
            0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_1C);
        {
            struct stackFrame_18 { u8 b[4]; } stackFrame_18 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v1 = (u32)((u8 *)&stackFrame_18);
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x953e);
            f12 = 64.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x953f);
            f13 = 390.0f;
            f12 = 48.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)48.0f, (f32)390.0f, 0.800000012f, (float)0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            return;
        }
    }
}


/* MGTutorialChoiseDie @ 0x1F3550 .. 0x1F35F4 (0xa4 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @998 -> 0x257758
 *   literal: @1000 -> 0x25775c
 *   fpu: float literal 0x42800000 at 0x1f358c
 *   fpu: float literal 0x41a00000 at 0x1f3594
 *   fpu: float literal 0x3f4ccccd at 0x1f35a0
 *   fpu: mov.s at 0x1f35a8 is a float copy
 *   fpu: float literal 0x43c30000 at 0x1f35c0
 *   fpu: float literal 0x42400000 at 0x1f35c8
 *   fpu: float literal 0x3f4ccccd at 0x1f35dc
 *   fpu: mov.s at 0x1f35e4 is a float copy
 *   literal: @1000 initializes the 4-byte local at 0x18
 *   literal: @998 initializes the 4-byte local at 0x1c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif



static void MGTutorialChoiseDie(void) {
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;

    v0 = 0x40000;
    {
        struct stackFrame_1C { u8 b[4]; } stackFrame_1C __attribute__((aligned(4))) = {{0xff, 0xff,
            0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_1C);
        {
            struct stackFrame_18 { u8 b[4]; } stackFrame_18 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v1 = (u32)((u8 *)&stackFrame_18);
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x953b);
            f12 = 64.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x953c);
            f13 = 390.0f;
            f12 = 48.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)48.0f, (f32)390.0f, 0.800000012f, (float)0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            return;
        }
    }
}


/* MGTutorialText4View @ 0x1F3300 .. 0x1F3548 (0x248 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @1005 -> 0x257760
 *   literal: @1007 -> 0x257764
 *   fpu: float literal 0x42800000 at 0x1f333c
 *   fpu: float literal 0x42980000 at 0x1f3344
 *   fpu: float literal 0x3f4ccccd at 0x1f3350
 *   fpu: mov.s at 0x1f3358 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3378
 *   fpu: float literal 0x42d00000 at 0x1f3380
 *   fpu: float literal 0x3f4ccccd at 0x1f338c
 *   fpu: mov.s at 0x1f3394 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f33b4
 *   fpu: float literal 0x43200000 at 0x1f33bc
 *   fpu: float literal 0x3f4ccccd at 0x1f33c8
 *   fpu: mov.s at 0x1f33d0 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f33f0
 *   fpu: float literal 0x433c0000 at 0x1f33f8
 *   fpu: float literal 0x3f4ccccd at 0x1f3404
 *   fpu: mov.s at 0x1f340c is a float copy
 *   fpu: float literal 0x42800000 at 0x1f342c
 *   fpu: float literal 0x43580000 at 0x1f3434
 *   fpu: float literal 0x3f4ccccd at 0x1f3440
 *   fpu: mov.s at 0x1f3448 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f3468
 *   fpu: float literal 0x43880000 at 0x1f3470
 *   fpu: float literal 0x3f4ccccd at 0x1f347c
 *   fpu: mov.s at 0x1f3484 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f34a4
 *   fpu: float literal 0x43960000 at 0x1f34ac
 *   fpu: float literal 0x3f4ccccd at 0x1f34b8
 *   fpu: mov.s at 0x1f34c0 is a float copy
 *   fpu: float literal 0x42800000 at 0x1f34e0
 *   fpu: float literal 0x43a40000 at 0x1f34e8
 *   fpu: float literal 0x3f4ccccd at 0x1f34f4
 *   fpu: mov.s at 0x1f34fc is a float copy
 *   fpu: float literal 0x43b20000 at 0x1f3514
 *   fpu: float literal 0x42800000 at 0x1f351c
 *   fpu: float literal 0x3f4ccccd at 0x1f3530
 *   fpu: mov.s at 0x1f3538 is a float copy
 *   literal: @1007 initializes the 4-byte local at 0x18
 *   literal: @1005 initializes the 4-byte local at 0x1c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif



static void MGTutorialText4View(void) {
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;

    v0 = 0x40000;
    {
        struct stackFrame_1C { u8 b[4]; } stackFrame_1C __attribute__((aligned(4))) = {{0xff, 0xff,
            0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_1C);
        {
            struct stackFrame_18 { u8 b[4]; } stackFrame_18 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v1 = (u32)((u8 *)&stackFrame_18);
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9541);
            f12 = 64.0f;
            f13 = 76.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 76.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9542);
            f12 = 64.0f;
            f13 = 104.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 104.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9543);
            f12 = 64.0f;
            f13 = 160.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 160.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9544);
            f12 = 64.0f;
            f13 = 188.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 188.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9545);
            f12 = 64.0f;
            f13 = 216.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 216.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9546);
            f12 = 64.0f;
            f13 = 272.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 272.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9547);
            f12 = 64.0f;
            f13 = 300.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 300.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9548);
            f12 = 64.0f;
            f13 = 328.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(64.0f, 328.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x9549);
            f13 = 356.0f;
            f12 = 64.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow((f32)64.0f, (f32)356.0f, 0.800000012f, (float)0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), (char *)(u8 *)v0);
            return;
        }
    }
}


/* MGTutorialOnmoreText @ 0x1F3150 .. 0x1F32F8 (0x1a8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @1012 -> 0x257768
 *   literal: @1014 -> 0x25776c
 *   literal: @1016 -> 0x257770
 *   literal: @1018 -> 0x257774
 *   fpu: float literal 0x432f0000 at 0x1f31a8
 *   fpu: float literal 0x43280000 at 0x1f31b0
 *   fpu: float literal 0x3f4ccccd at 0x1f31c4
 *   fpu: mov.s at 0x1f31cc is a float copy
 *   fpu: float literal 0x43420000 at 0x1f31f8
 *   fpu: float literal 0x435c0000 at 0x1f3200
 *   fpu: float literal 0x3f4ccccd at 0x1f320c
 *   fpu: mov.s at 0x1f3214 is a float copy
 *   fpu: float literal 0x43750000 at 0x1f322c
 *   fpu: float literal 0x43340000 at 0x1f3234
 *   fpu: float literal 0x3f4ccccd at 0x1f3248
 *   fpu: mov.s at 0x1f3250 is a float copy
 *   fpu: float literal 0x43420000 at 0x1f3288
 *   fpu: float literal 0x435c0000 at 0x1f3290
 *   fpu: float literal 0x3f4ccccd at 0x1f329c
 *   fpu: mov.s at 0x1f32a4 is a float copy
 *   fpu: float literal 0x43750000 at 0x1f32bc
 *   fpu: float literal 0x43340000 at 0x1f32c4
 *   fpu: float literal 0x3f4ccccd at 0x1f32d8
 *   fpu: mov.s at 0x1f32e0 is a float copy
 *   literal: @1018 initializes the 4-byte local at 0x20
 *   literal: @1016 initializes the 4-byte local at 0x24
 *   literal: @1014 initializes the 4-byte local at 0x28
 *   literal: @1012 initializes the 4-byte local at 0x2c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif




static void MGTutorialOnmoreText(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u8 *s0;
    float f14;
    float f13;
    float f12;

    {
        struct stackFrame_2C { u8 b[4]; } stackFrame_2C __attribute__((aligned(4))) = {{0xff, 0xff,
            0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_2C);
        {
            struct stackFrame_28 { u8 b[4]; } stackFrame_28 __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_28);
            {
                struct stackFrame_24 { u8 b[4]; } stackFrame_24 __attribute__((aligned(4))) =
                    {{0xff, 0x99, 0x00, 0x80}};
                v1 = (u32)((u8 *)&stackFrame_24);
                {
                    struct stackFrame_20 { u8 b[4]; } stackFrame_20 __attribute__((aligned(16))) =
                        {{0xff, 0xff, 0xff, 0x30}};
                    v0 = (u32)((u8 *)&stackFrame_20);
                    v0 = GetMenuPos();
                    s0 = (u8 *)v0;
                    v0 = 0x40000;
                    v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x954b);
                    f13 = 175.0f;
                    f12 = 168.0f;
                    f14 = 0.800000012f;
                    MGFontPrintXYSclColShadow((f32)168.0f, (f32)175.0f, 0.800000012f,
                        (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                        *)&stackFrame_2C)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                        *)&stackFrame_28)), (char *)(u8 *)v0);
                    a0 = *(u8 *)s0;
                    if (a0 == 0) {
                        v0 = 0x40000;
                        v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x954c);
                        f12 = 194.0f;
                        f13 = 220.0f;
                        f14 = 0.800000012f;
                        MGFontPrintXYSclColShadow(194.0f, 220.0f, 0.800000012f,
                            (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_24)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_28)), (char *)(u8 *)v0);
                        v0 = 0x40000;
                        v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x954d);
                        f13 = 245.0f;
                        f12 = 180.0f;
                        f14 = 0.800000012f;
                        MGFontPrintXYSclColShadow((f32)180.0f, (f32)245.0f, 0.800000012f,
                            (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_20)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_28)), (char *)(u8 *)v0);
                    } else if (a0 == (u32)1) {
                        v0 = 0x40000;
                        v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x954e);
                        f12 = 194.0f;
                        f13 = 220.0f;
                        f14 = 0.800000012f;
                        MGFontPrintXYSclColShadow(194.0f, 220.0f, 0.800000012f,
                            (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_20)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_28)), (char *)(u8 *)v0);
                        v0 = 0x40000;
                        v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x954f);
                        f13 = 245.0f;
                        f12 = 180.0f;
                        f14 = 0.800000012f;
                        MGFontPrintXYSclColShadow((f32)180.0f, (f32)245.0f, 0.800000012f,
                            (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_24)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_28)), (char *)(u8 *)v0);
                    }
                    return;
                }
            }
        }
    }
}


/* MG2PModeOrderPlayerText0 @ 0x1F3050 .. 0x1F3144 (0xf4 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42500000 at 0x1f305c
 *   literal: @1097 -> 0x257778
 *   fpu: float literal 0x3f4ccccd at 0x1f3078
 *   fpu: float literal 0x42d20000 at 0x1f3080
 *   literal: @1099 -> 0x25777c
 *   fpu: mov.s at 0x1f30a0 is a float copy
 *   fpu: float literal 0x43c90000 at 0x1f30ac
 *   fpu: float literal 0x42d20000 at 0x1f30b8
 *   fpu: float literal 0x3f4ccccd at 0x1f30cc
 *   fpu: mov.s at 0x1f30d4 is a float copy
 *   fpu: float literal 0x42400000 at 0x1f30e0
 *   fpu: float literal 0x41a00000 at 0x1f30ec
 *   fpu: float literal 0x3f4ccccd at 0x1f30fc
 *   fpu: mov.s at 0x1f3104 is a float copy
 *   fpu: float literal 0x42400000 at 0x1f3110
 *   fpu: float literal 0x43c30000 at 0x1f311c
 *   fpu: float literal 0x3f4ccccd at 0x1f312c
 *   fpu: mov.s at 0x1f3134 is a float copy
 *   literal: @1097 initializes the 4-byte local at 0x18
 *   literal: @1099 initializes the 4-byte local at 0x1c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif





static void MG2PModeOrderPlayerText0(void) {
    float f14;
    u32 a2;
    u32 a1;
    float f13;
    float f12;
    u32 a0;

    f12 = 52.0f;
    f14 = 0.800000012f;
    f13 = 105.0f;
    {
        struct stackFrame_18 { u8 b[4]; } stackFrame_18 __attribute__((aligned(8))) = {{0xff, 0xff,
            0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_18);
        {
            struct stackFrame_1C { u8 b[4]; } stackFrame_1C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_1C);
            MGFontPrintXYSclColShadow(52.0f, (f32)105.0f, (f32)0.800000012f, (float)0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), (char *)*(s32
                *)(gsHdPlayerName + 2));
            f12 = 402.0f;
            f13 = 105.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(402.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), (char *)*(s32
                *)(gsHdPlayerName + 3));
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), (char *)gsHdOrderSerMsg);
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_18)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_1C)), (char *)gsHelpKakunin);
            return;
        }
    }
}


/* MG2PMode1POrderPlayerText1 @ 0x1F2F40 .. 0x1F304C (0x10c bytes, frame 0x120) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42500000 at 0x1f2f4c
 *   literal: @1104 -> 0x257780
 *   fpu: float literal 0x3f4ccccd at 0x1f2f68
 *   fpu: float literal 0x42d20000 at 0x1f2f70
 *   literal: @1106 -> 0x257784
 *   fpu: mov.s at 0x1f2f90 is a float copy
 *   fpu: float literal 0x43c90000 at 0x1f2f9c
 *   fpu: float literal 0x42d20000 at 0x1f2fa8
 *   fpu: float literal 0x3f4ccccd at 0x1f2fbc
 *   fpu: mov.s at 0x1f2fc4 is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f2fd8
 *   fpu: float literal 0x42400000 at 0x1f2fe8
 *   fpu: float literal 0x41a00000 at 0x1f2ff4
 *   fpu: float literal 0x3f4ccccd at 0x1f3004
 *   fpu: mov.s at 0x1f300c is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f3008
 *   fpu: float literal 0x42400000 at 0x1f3018
 *   fpu: float literal 0x43c30000 at 0x1f3024
 *   fpu: float literal 0x3f4ccccd at 0x1f3034
 *   fpu: mov.s at 0x1f303c is a float copy
 *   literal: @1104 initializes the 4-byte local at 0x118
 *   literal: @1106 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif






static void MG2PMode1POrderPlayerText1(void) {
    float f14;
    u32 a2;
    u32 a1;
    float f13;
    float f12;
    u32 a0;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    f12 = 52.0f;
    f14 = 0.800000012f;
    f13 = 105.0f;
    {
        struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0xff,
            0xff, 0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_118);
        {
            struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_11C);
            MGFontPrintXYSclColShadow(52.0f, (f32)105.0f, (f32)0.800000012f, (float)0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), (char *)*(s32
                *)(gsHdPlayerName + 2));
            f12 = 402.0f;
            f13 = 105.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(402.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), (char *)*(s32
                *)(gsHdPlayerName + 3));
            a1 = *(s32 *)(gsHdNowPlayerMsg + 2);
            a2 = *(s32 *)(gsHdPlayerName + 2);
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), (char *)((u8
                *)&stackFrame_10[0]));
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), (char *)gsHelpDiceCast);
            return;
        }
    }
}


/* MG2PMode1POrderPlayerText2 @ 0x1F2E60 .. 0x1F2F3C (0xdc bytes, frame 0x120) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42500000 at 0x1f2e6c
 *   literal: @1112 -> 0x257788
 *   fpu: float literal 0x3f4ccccd at 0x1f2e88
 *   fpu: float literal 0x42d20000 at 0x1f2e90
 *   literal: @1114 -> 0x25778c
 *   fpu: mov.s at 0x1f2eb0 is a float copy
 *   fpu: float literal 0x43c90000 at 0x1f2ebc
 *   fpu: float literal 0x42d20000 at 0x1f2ec8
 *   fpu: float literal 0x3f4ccccd at 0x1f2edc
 *   fpu: mov.s at 0x1f2ee4 is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f2ef8
 *   fpu: float literal 0x42400000 at 0x1f2f08
 *   fpu: float literal 0x41a00000 at 0x1f2f14
 *   fpu: float literal 0x3f4ccccd at 0x1f2f24
 *   fpu: mov.s at 0x1f2f2c is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f2f28
 *   literal: @1112 initializes the 4-byte local at 0x118
 *   literal: @1114 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif





static void MG2PMode1POrderPlayerText2(void) {
    float f14;
    u32 a2;
    u32 a1;
    float f13;
    float f12;
    u32 a0;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    f12 = 52.0f;
    f14 = 0.800000012f;
    f13 = 105.0f;
    {
        struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0xff,
            0xff, 0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_118);
        {
            struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_11C);
            MGFontPrintXYSclColShadow(52.0f, (f32)105.0f, (f32)0.800000012f, (float)0.800000012f,
                *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), (char *)*(s32
                *)(gsHdPlayerName + 2));
            f12 = 402.0f;
            f13 = 105.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(402.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), (char *)*(s32
                *)(gsHdPlayerName + 3));
            a1 = *(s32 *)(gsHdNowPlayerMsg + 2);
            a2 = *(s32 *)(gsHdPlayerName + 2);
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), (char *)((u8
                *)&stackFrame_10[0]));
            return;
        }
    }
}



/* MG2PMode1POrderPlayerText3 @ 0x1F2C50 .. 0x1F2E5C (0x20c bytes, frame 0x130) */
/*
 * dcomp notes:
 *   literal: @1773 -> 0x257170
 *   literal: @1598 is the string ''
 *   call: GetDiceNum is declared void but its v0 is read: called as returning u32
 *   literal: @1121 -> 0x257790
 *   fpu: float literal 0x42500000 at 0x1f2c78
 *   fpu: float literal 0x42d20000 at 0x1f2c80
 *   literal: @1123 -> 0x257794
 *   fpu: float literal 0x3f4ccccd at 0x1f2c94
 *   fpu: mov.s at 0x1f2cac is a float copy
 *   fpu: float literal 0x43c90000 at 0x1f2cb8
 *   fpu: float literal 0x42d20000 at 0x1f2cc4
 *   fpu: float literal 0x3f4ccccd at 0x1f2cd8
 *   fpu: mov.s at 0x1f2ce0 is a float copy
 *   indirect: jr v0 at 0x1f2d04 -> <v0>
 *   fpu: float literal 0x42780000 at 0x1f2db4
 *   fpu: float literal 0x430c0000 at 0x1f2dc0
 *   fpu: float literal 0x3f800000 at 0x1f2dc8
 *   fpu: mov.s at 0x1f2dd0 is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x1f2de4
 *   fpu: float literal 0x42400000 at 0x1f2df4
 *   fpu: float literal 0x41a00000 at 0x1f2e00
 *   fpu: float literal 0x3f4ccccd at 0x1f2e10
 *   fpu: mov.s at 0x1f2e18 is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x1f2e14
 *   fpu: float literal 0x42400000 at 0x1f2e24
 *   fpu: float literal 0x43c30000 at 0x1f2e30
 *   fpu: float literal 0x3f4ccccd at 0x1f2e40
 *   fpu: mov.s at 0x1f2e48 is a float copy
 *   literal: @1121 initializes the 4-byte local at 0x128
 *   literal: @1123 initializes the 4-byte local at 0x12c
 */

static void MG2PMode1POrderPlayerText3(void) {
    extern u32 GetDiceNum(void);
    u32 a2;
    u32 a1;
    u8 *s0;
    u32 a0;
    float f15;
    float f14;
    float f13;
    u32 v0;
    float f12;
    u8 stackFrame_20[264] __attribute__((aligned(16)));

    v0 = GetDiceNum();
    s0 = (u8 *)v0;
    f12 = 52.0f;
    f13 = 105.0f;
    {
        struct stackFrame_128 { u8 b[4]; } stackFrame_128 __attribute__((aligned(8))) = {{0xff,
            0xff, 0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_128);
        f14 = 0.800000012f;
        {
            struct stackFrame_12C { u8 b[4]; } stackFrame_12C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_12C);
            MGFontPrintXYSclColShadow(52.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)*(s32
                *)(gsHdPlayerName + 2));
            f12 = 402.0f;
            f13 = 105.0f;
            f14 = 0.800000012f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow(402.0f, 105.0f, 0.800000012f, f15, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)*(s32
                *)(gsHdPlayerName + 3));
            v0 = *(u8 *)s0;
            switch (v0) {
            case 1:
                v0 = 0x40000;
                a0 = 0x40000 | 0x9559;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 2:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955a;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 3:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955b;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 4:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955c;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 5:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955d;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 6:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955e;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 0:
            default:
                v0 = (u32)"";
            }
            a2 = v0;
            f12 = 62.0f;
            f13 = 140.0f;
            f14 = 1.0f;
            MGFontPrintXYSclColShadow(62.0f, 140.0f, 1.0f, (float)1.0f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)a2);
            a1 = *(s32 *)(gsHdNowPlayerMsg + 2);
            a2 = *(s32 *)(gsHdPlayerName + 2);
            FsFontReplaceText((void *)((u8 *)&stackFrame_20[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)((u8
                *)&stackFrame_20[0]));
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)gsHelpKakunin);
            return;
        }
    }
}



/* MG2PMode2POrderPlayerText1 @ 0x1F2A40 .. 0x1F2C4C (0x20c bytes, frame 0x130) */
/*
 * dcomp notes:
 *   literal: @1731 -> 0x257150
 *   literal: @1598 is the string ''
 *   call: GetDiceNum is declared void but its v0 is read: called as returning u32
 *   literal: @1130 -> 0x257798
 *   fpu: float literal 0x42500000 at 0x1f2a68
 *   fpu: float literal 0x42d20000 at 0x1f2a70
 *   literal: @1132 -> 0x25779c
 *   fpu: float literal 0x3f4ccccd at 0x1f2a84
 *   fpu: mov.s at 0x1f2a9c is a float copy
 *   fpu: float literal 0x43c90000 at 0x1f2aa8
 *   fpu: float literal 0x42d20000 at 0x1f2ab4
 *   fpu: float literal 0x3f4ccccd at 0x1f2ac8
 *   fpu: mov.s at 0x1f2ad0 is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x1f2ae4
 *   fpu: float literal 0x42400000 at 0x1f2af4
 *   fpu: float literal 0x41a00000 at 0x1f2b00
 *   fpu: float literal 0x3f4ccccd at 0x1f2b10
 *   fpu: mov.s at 0x1f2b18 is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x1f2b14
 *   indirect: jr v0 at 0x1f2b3c -> <v0>
 *   fpu: float literal 0x42780000 at 0x1f2bec
 *   fpu: float literal 0x430c0000 at 0x1f2bf8
 *   fpu: float literal 0x3f800000 at 0x1f2c00
 *   fpu: mov.s at 0x1f2c08 is a float copy
 *   fpu: float literal 0x42400000 at 0x1f2c14
 *   fpu: float literal 0x43c30000 at 0x1f2c20
 *   fpu: float literal 0x3f4ccccd at 0x1f2c30
 *   fpu: mov.s at 0x1f2c38 is a float copy
 *   literal: @1130 initializes the 4-byte local at 0x128
 *   literal: @1132 initializes the 4-byte local at 0x12c
 */

static void MG2PMode2POrderPlayerText1(void) {
    extern u32 GetDiceNum(void);
    u32 a2;
    u32 a1;
    u8 *s0;
    u32 a0;
    float f15;
    float f14;
    float f13;
    u32 v0;
    float f12;
    u8 stackFrame_20[264] __attribute__((aligned(16)));

    v0 = GetDiceNum();
    s0 = (u8 *)v0;
    f12 = 52.0f;
    f13 = 105.0f;
    {
        struct stackFrame_128 { u8 b[4]; } stackFrame_128 __attribute__((aligned(8))) = {{0xff,
            0xff, 0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_128);
        f14 = 0.800000012f;
        {
            struct stackFrame_12C { u8 b[4]; } stackFrame_12C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_12C);
            MGFontPrintXYSclColShadow(52.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)*(s32
                *)(gsHdPlayerName + 2));
            f12 = 402.0f;
            f13 = 105.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(402.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)*(s32
                *)(gsHdPlayerName + 3));
            a1 = *(s32 *)(gsHdNowPlayerMsg + 3);
            a2 = *(s32 *)(gsHdPlayerName + 3);
            FsFontReplaceText((void *)((u8 *)&stackFrame_20[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            a2 = (u32)((u8 *)&stackFrame_20[0]);
            f14 = 0.800000012f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, f15, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)a2);
            v0 = *(u8 *)s0;
            switch (v0) {
            case 1:
                v0 = 0x40000;
                a0 = 0x40000 | 0x9559;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 2:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955a;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 3:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955b;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 4:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955c;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 5:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955d;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 6:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955e;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 0:
            default:
                v0 = (u32)"";
            }
            a2 = v0;
            f12 = 62.0f;
            f13 = 140.0f;
            f14 = 1.0f;
            MGFontPrintXYSclColShadow(62.0f, 140.0f, 1.0f, (float)1.0f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)a2);
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)gsHelpDiceCast);
            return;
        }
    }
}



/* MG2PMode2POrderPlayerText2 @ 0x1F2860 .. 0x1F2A3C (0x1dc bytes, frame 0x130) */
/*
 * dcomp notes:
 *   literal: @1689 -> 0x257130
 *   literal: @1598 is the string ''
 *   call: GetDiceNum is declared void but its v0 is read: called as returning u32
 *   literal: @1139 -> 0x2577a0
 *   fpu: float literal 0x42500000 at 0x1f2888
 *   fpu: float literal 0x42d20000 at 0x1f2890
 *   literal: @1141 -> 0x2577a4
 *   fpu: float literal 0x3f4ccccd at 0x1f28a4
 *   fpu: mov.s at 0x1f28bc is a float copy
 *   fpu: float literal 0x43c90000 at 0x1f28c8
 *   fpu: float literal 0x42d20000 at 0x1f28d4
 *   fpu: float literal 0x3f4ccccd at 0x1f28e8
 *   fpu: mov.s at 0x1f28f0 is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x1f2904
 *   fpu: float literal 0x42400000 at 0x1f2914
 *   fpu: float literal 0x41a00000 at 0x1f2920
 *   fpu: float literal 0x3f4ccccd at 0x1f2930
 *   fpu: mov.s at 0x1f2938 is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x1f2934
 *   indirect: jr v0 at 0x1f295c -> <v0>
 *   fpu: float literal 0x42780000 at 0x1f2a04
 *   fpu: float literal 0x430c0000 at 0x1f2a18
 *   fpu: float literal 0x3f800000 at 0x1f2a20
 *   fpu: mov.s at 0x1f2a28 is a float copy
 *   literal: @1139 initializes the 4-byte local at 0x128
 *   literal: @1141 initializes the 4-byte local at 0x12c
 */

static void MG2PMode2POrderPlayerText2(void) {
    extern u32 GetDiceNum(void);
    u32 a2;
    u32 a1;
    u8 *s0;
    u32 a0;
    float f15;
    float f14;
    float f13;
    u32 v0;
    float f12;
    u8 stackFrame_20[264] __attribute__((aligned(16)));

    v0 = GetDiceNum();
    s0 = (u8 *)v0;
    f12 = 52.0f;
    f13 = 105.0f;
    {
        struct stackFrame_128 { u8 b[4]; } stackFrame_128 __attribute__((aligned(8))) = {{0xff,
            0xff, 0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_128);
        f14 = 0.800000012f;
        {
            struct stackFrame_12C { u8 b[4]; } stackFrame_12C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_12C);
            MGFontPrintXYSclColShadow(52.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)*(s32
                *)(gsHdPlayerName + 2));
            f12 = 402.0f;
            f13 = 105.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(402.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)*(s32
                *)(gsHdPlayerName + 3));
            a1 = *(s32 *)(gsHdNowPlayerMsg + 3);
            a2 = *(s32 *)(gsHdPlayerName + 3);
            FsFontReplaceText((void *)((u8 *)&stackFrame_20[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            a2 = (u32)((u8 *)&stackFrame_20[0]);
            f14 = 0.800000012f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, f15, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)a2);
            v0 = *(u8 *)s0;
            switch (v0) {
            case 1:
                v0 = 0x40000;
                a0 = 0x40000 | 0x9559;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 2:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955a;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 3:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955b;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 4:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955c;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 5:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955d;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 6:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955e;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 0:
            default:
                v0 = (u32)"";
            }
            f12 = 62.0f;
            a2 = v0;
            f13 = 140.0f;
            f14 = 1.0f;
            MGFontPrintXYSclColShadow(62.0f, 140.0f, 1.0f, (float)1.0f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_128)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_12C)), (char *)a2);
            return;
        }
    }
}



/* MG2PMode2POrderPlayerText3 @ 0x1F25D0 .. 0x1F2854 (0x284 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @1654 -> 0x257110
 *   literal: @1598 is the string ''
 *   literal: @1655 -> 0x2570f0
 *   call: GetDiceNum is declared void but its v0 is read: called as returning u32
 *   literal: @1148 -> 0x2577a8
 *   fpu: float literal 0x42500000 at 0x1f25f8
 *   fpu: float literal 0x42d20000 at 0x1f2600
 *   literal: @1150 -> 0x2577ac
 *   fpu: float literal 0x3f4ccccd at 0x1f2614
 *   fpu: mov.s at 0x1f262c is a float copy
 *   fpu: float literal 0x43c90000 at 0x1f2638
 *   fpu: float literal 0x42d20000 at 0x1f2644
 *   fpu: float literal 0x3f4ccccd at 0x1f2658
 *   fpu: mov.s at 0x1f2660 is a float copy
 *   indirect: jr v0 at 0x1f2684 -> <v0>
 *   fpu: float literal 0x42780000 at 0x1f2734
 *   fpu: float literal 0x430c0000 at 0x1f2740
 *   fpu: float literal 0x3f800000 at 0x1f2748
 *   fpu: mov.s at 0x1f2750 is a float copy
 *   indirect: jr v0 at 0x1f2774 -> <v0>
 *   fpu: float literal 0x43cf0000 at 0x1f281c
 *   fpu: float literal 0x430c0000 at 0x1f2830
 *   fpu: float literal 0x3f800000 at 0x1f2838
 *   fpu: mov.s at 0x1f2840 is a float copy
 *   literal: @1148 initializes the 4-byte local at 0x28
 *   literal: @1150 initializes the 4-byte local at 0x2c
 */

static void MG2PMode2POrderPlayerText3(void) {
    extern u32 GetDiceNum(void);
    u32 a2;
    u32 a1;
    u8 *s0;
    u32 a0;
    float f15;
    float f14;
    float f13;
    u32 v1;
    float f12;
    u32 v0;

    v0 = GetDiceNum();
    s0 = (u8 *)v0;
    f12 = 52.0f;
    f13 = 105.0f;
    {
        struct stackFrame_28 { u8 b[4]; } stackFrame_28 __attribute__((aligned(8))) = {{0xff, 0xff,
            0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_28);
        f14 = 0.800000012f;
        {
            struct stackFrame_2C { u8 b[4]; } stackFrame_2C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_2C);
            MGFontPrintXYSclColShadow(52.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)*(s32
                *)(gsHdPlayerName + 2));
            f12 = 402.0f;
            f13 = 105.0f;
            f14 = 0.800000012f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow(402.0f, 105.0f, 0.800000012f, f15, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)*(s32
                *)(gsHdPlayerName + 3));
            v0 = *(u8 *)s0;
            v1 = 0x257110;
            switch (v0) {
            case 1:
                v0 = 0x40000;
                a0 = 0x40000 | 0x9559;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 2:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955a;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 3:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955b;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 4:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955c;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 5:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955d;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 6:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955e;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 0:
            default:
                v0 = (u32)"";
            }
            a2 = v0;
            f12 = 62.0f;
            f13 = 140.0f;
            f14 = 1.0f;
            f15 = 1.0f;
            MGFontPrintXYSclColShadow(62.0f, 140.0f, 1.0f, f15, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)a2);
            v0 = *(u8 *)(s0 + 1);
            v1 = 0x2570f0;
            switch (v0) {
            case 1:
                v0 = 0x40000;
                a0 = 0x40000 | 0x9559;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 2:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955a;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 3:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955b;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 4:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955c;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 5:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955d;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 6:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955e;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 0:
            default:
                v0 = (u32)"";
            }
            f12 = 414.0f;
            a2 = v0;
            f13 = 140.0f;
            f14 = 1.0f;
            MGFontPrintXYSclColShadow(414.0f, 140.0f, 1.0f, (float)1.0f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)a2);
            return;
        }
    }
}



/* MG2PModeOrderLastView @ 0x1F2250 .. 0x1F25D0 (0x380 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @1599 -> 0x2570d0
 *   literal: @1598 is the string ''
 *   literal: @1600 -> 0x2570b0
 *   call: GetDiceNum is declared void but its v0 is read: called as returning u32
 *   literal: @1156 -> 0x2577b0
 *   fpu: float literal 0x42500000 at 0x1f2278
 *   fpu: float literal 0x42d20000 at 0x1f2280
 *   literal: @1158 -> 0x2577b4
 *   fpu: float literal 0x3f4ccccd at 0x1f2294
 *   fpu: mov.s at 0x1f22ac is a float copy
 *   fpu: float literal 0x43c90000 at 0x1f22b8
 *   fpu: float literal 0x42d20000 at 0x1f22c4
 *   fpu: float literal 0x3f4ccccd at 0x1f22d8
 *   fpu: mov.s at 0x1f22e0 is a float copy
 *   indirect: jr v0 at 0x1f2304 -> <v0>
 *   fpu: float literal 0x42780000 at 0x1f23b4
 *   fpu: float literal 0x430c0000 at 0x1f23c0
 *   fpu: float literal 0x3f800000 at 0x1f23c8
 *   fpu: mov.s at 0x1f23d0 is a float copy
 *   indirect: jr v0 at 0x1f23f4 -> <v0>
 *   fpu: float literal 0x43cf0000 at 0x1f24a4
 *   fpu: float literal 0x430c0000 at 0x1f24b0
 *   fpu: float literal 0x3f800000 at 0x1f24b8
 *   fpu: mov.s at 0x1f24c0 is a float copy
 *   fpu: float literal 0x42400000 at 0x1f24cc
 *   fpu: float literal 0x43c30000 at 0x1f24d8
 *   fpu: float literal 0x3f4ccccd at 0x1f24e8
 *   fpu: mov.s at 0x1f24f0 is a float copy
 *   fpu: float literal 0x42400000 at 0x1f250c
 *   fpu: float literal 0x41a00000 at 0x1f2518
 *   fpu: float literal 0x3f4ccccd at 0x1f2528
 *   fpu: mov.s at 0x1f2530 is a float copy
 *   fpu: float literal 0x42400000 at 0x1f2554
 *   fpu: float literal 0x41a00000 at 0x1f2560
 *   fpu: float literal 0x3f4ccccd at 0x1f2574
 *   fpu: mov.s at 0x1f257c is a float copy
 *   fpu: float literal 0x42400000 at 0x1f258c
 *   fpu: float literal 0x41a00000 at 0x1f25a0
 *   fpu: float literal 0x3f4ccccd at 0x1f25b0
 *   fpu: mov.s at 0x1f25b8 is a float copy
 *   literal: @1156 initializes the 4-byte local at 0x28
 *   literal: @1158 initializes the 4-byte local at 0x2c
 */




static void MG2PModeOrderLastView(void) {
    extern u32 GetDiceNum(void);
    u32 a2;
    u32 a1;
    u8 *s0;
    u32 a0;
    float f15;
    float f14;
    float f13;
    u32 v1;
    float f12;
    u32 v0;

    v0 = GetDiceNum();
    s0 = (u8 *)v0;
    f12 = 52.0f;
    f13 = 105.0f;
    {
        struct stackFrame_28 { u8 b[4]; } stackFrame_28 __attribute__((aligned(8))) = {{0xff, 0xff,
            0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_28);
        f14 = 0.800000012f;
        {
            struct stackFrame_2C { u8 b[4]; } stackFrame_2C __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_2C);
            MGFontPrintXYSclColShadow(52.0f, 105.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)*(s32
                *)(gsHdPlayerName + 2));
            f12 = 402.0f;
            f13 = 105.0f;
            f14 = 0.800000012f;
            f15 = 0.800000012f;
            MGFontPrintXYSclColShadow(402.0f, 105.0f, 0.800000012f, f15, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)*(s32
                *)(gsHdPlayerName + 3));
            v0 = *(u8 *)s0;
            v1 = 0x2570d0;
            switch (v0) {
            case 1:
                v0 = 0x40000;
                a0 = 0x40000 | 0x9559;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 2:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955a;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 3:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955b;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 4:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955c;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 5:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955d;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 6:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955e;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 0:
            default:
                v0 = (u32)"";
            }
            a2 = v0;
            f12 = 62.0f;
            f13 = 140.0f;
            f14 = 1.0f;
            f15 = 1.0f;
            MGFontPrintXYSclColShadow(62.0f, 140.0f, 1.0f, f15, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)a2);
            v0 = *(u8 *)(s0 + 1);
            v1 = 0x2570b0;
            switch (v0) {
            case 1:
                v0 = 0x40000;
                a0 = 0x40000 | 0x9559;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 2:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955a;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 3:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955b;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 4:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955c;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 5:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955d;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 6:
                v0 = 0x40000;
                a0 = 0x40000 | 0x955e;
                v0 = (u32)KnMsgMng_GetMsgStr(a0);
                break;
            case 0:
            default:
                v0 = (u32)"";
            }
            a2 = v0;
            f12 = 414.0f;
            f13 = 140.0f;
            f14 = 1.0f;
            MGFontPrintXYSclColShadow(414.0f, 140.0f, 1.0f, (float)1.0f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)a2);
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)gsHelpKakunin);
            v1 = *(u8 *)(s0 + 1);
            v0 = *(u8 *)s0;
            if (v0 == v1) {
                f12 = 48.0f;
                f13 = 20.0f;
                f14 = 0.800000012f;
                MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                    dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                    dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char
                    *)gsOrderRetryMsg);
            } else if ((s32)v1 < (s32)v0) {
                f12 = 48.0f;
                f13 = 20.0f;
                f14 = 0.800000012f;
                MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                    dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                    dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)*(s32
                    *)(gsOrderEndMsg + 2));
            } else {
                f12 = 48.0f;
                f13 = 20.0f;
                f14 = 0.800000012f;
                MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                    dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_28)), *(struct
                    dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_2C)), (char *)*(s32
                    *)(gsOrderEndMsg + 3));
            }
            return;
        }
    }
}


/* MG2PMode1PDiceThrowPlayer @ 0x1F21A0 .. 0x1F224C (0xac bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @1170 -> 0x2577b8
 *   literal: @1172 -> 0x2577bc
 *   stack: address of the slot at 0x10 escapes at 0x1f21d8
 *   fpu: float literal 0x42400000 at 0x1f21e8
 *   fpu: float literal 0x41a00000 at 0x1f21f4
 *   fpu: float literal 0x3f4ccccd at 0x1f2204
 *   fpu: mov.s at 0x1f220c is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f2208
 *   fpu: float literal 0x42400000 at 0x1f2218
 *   fpu: float literal 0x43c30000 at 0x1f2224
 *   fpu: float literal 0x3f4ccccd at 0x1f2234
 *   fpu: mov.s at 0x1f223c is a float copy
 *   literal: @1172 initializes the 4-byte local at 0x118
 *   literal: @1170 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif







static void MG2PMode1PDiceThrowPlayer(void) {
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    GetDiceNum();
    {
        struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        v1 = (u32)((u8 *)&stackFrame_11C);
        {
            struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v0 = (u32)((u8 *)&stackFrame_118);
            a1 = *(s32 *)(gsHdNowPlayerMsg + 2);
            a2 = *(s32 *)(gsHdPlayerName + 2);
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)((u8
                *)&stackFrame_10[0]));
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)gsHelpDiceCast);
            return;
        }
    }
}


/* MG2PMode1PDiceThrowPlayer1 @ 0x1F2120 .. 0x1F219C (0x7c bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @1179 -> 0x2577c0
 *   literal: @1181 -> 0x2577c4
 *   stack: address of the slot at 0x10 escapes at 0x1f2158
 *   fpu: float literal 0x42400000 at 0x1f2168
 *   fpu: float literal 0x41a00000 at 0x1f2174
 *   fpu: float literal 0x3f4ccccd at 0x1f2184
 *   fpu: mov.s at 0x1f218c is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f2188
 *   literal: @1181 initializes the 4-byte local at 0x118
 *   literal: @1179 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif






static void MG2PMode1PDiceThrowPlayer1(void) {
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    GetDiceNum();
    {
        struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        v1 = (u32)((u8 *)&stackFrame_11C);
        {
            struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v0 = (u32)((u8 *)&stackFrame_118);
            a1 = *(s32 *)(gsHdNowPlayerMsg + 2);
            a2 = *(s32 *)(gsHdPlayerName + 2);
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)((u8
                *)&stackFrame_10[0]));
            return;
        }
    }
}


/* MG2PMode1PChoisePiecePlayer @ 0x1F2070 .. 0x1F211C (0xac bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @1190 -> 0x2577c8
 *   literal: @1192 -> 0x2577cc
 *   stack: address of the slot at 0x10 escapes at 0x1f20a8
 *   fpu: float literal 0x42400000 at 0x1f20b8
 *   fpu: float literal 0x41a00000 at 0x1f20c4
 *   fpu: float literal 0x3f4ccccd at 0x1f20d4
 *   fpu: mov.s at 0x1f20dc is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f20d8
 *   fpu: float literal 0x42400000 at 0x1f20e8
 *   fpu: float literal 0x43c30000 at 0x1f20f4
 *   fpu: float literal 0x3f4ccccd at 0x1f2104
 *   fpu: mov.s at 0x1f210c is a float copy
 *   literal: @1192 initializes the 4-byte local at 0x118
 *   literal: @1190 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif







static void MG2PMode1PChoisePiecePlayer(void) {
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    GetDiceNum();
    {
        struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        v1 = (u32)((u8 *)&stackFrame_11C);
        {
            struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v0 = (u32)((u8 *)&stackFrame_118);
            a1 = *(s32 *)(gsHdNowPlayerMsg + 2);
            a2 = *(s32 *)(gsHdPlayerName + 2);
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)((u8
                *)&stackFrame_10[0]));
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)gsHelpChoiKoma);
            return;
        }
    }
}


/* MG2PMode1PChoiseDiePlayer @ 0x1F1FC0 .. 0x1F206C (0xac bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @1201 -> 0x2577d0
 *   literal: @1203 -> 0x2577d4
 *   stack: address of the slot at 0x10 escapes at 0x1f1ff8
 *   fpu: float literal 0x42400000 at 0x1f2008
 *   fpu: float literal 0x41a00000 at 0x1f2014
 *   fpu: float literal 0x3f4ccccd at 0x1f2024
 *   fpu: mov.s at 0x1f202c is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f2028
 *   fpu: float literal 0x42400000 at 0x1f2038
 *   fpu: float literal 0x43c30000 at 0x1f2044
 *   fpu: float literal 0x3f4ccccd at 0x1f2054
 *   fpu: mov.s at 0x1f205c is a float copy
 *   literal: @1203 initializes the 4-byte local at 0x118
 *   literal: @1201 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif







static void MG2PMode1PChoiseDiePlayer(void) {
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    GetDiceNum();
    {
        struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        v1 = (u32)((u8 *)&stackFrame_11C);
        {
            struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v0 = (u32)((u8 *)&stackFrame_118);
            a1 = *(s32 *)(gsHdNowPlayerMsg + 2);
            a2 = *(s32 *)(gsHdPlayerName + 2);
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)((u8
                *)&stackFrame_10[0]));
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)gsHelpChoiDice);
            return;
        }
    }
}


/* MG2PMode2PDiceThrowPlayer @ 0x1F1F10 .. 0x1F1FBC (0xac bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @1212 -> 0x2577d8
 *   literal: @1214 -> 0x2577dc
 *   stack: address of the slot at 0x10 escapes at 0x1f1f48
 *   fpu: float literal 0x42400000 at 0x1f1f58
 *   fpu: float literal 0x41a00000 at 0x1f1f64
 *   fpu: float literal 0x3f4ccccd at 0x1f1f74
 *   fpu: mov.s at 0x1f1f7c is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f1f78
 *   fpu: float literal 0x42400000 at 0x1f1f88
 *   fpu: float literal 0x43c30000 at 0x1f1f94
 *   fpu: float literal 0x3f4ccccd at 0x1f1fa4
 *   fpu: mov.s at 0x1f1fac is a float copy
 *   literal: @1214 initializes the 4-byte local at 0x118
 *   literal: @1212 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif







static void MG2PMode2PDiceThrowPlayer(void) {
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    GetDiceNum();
    {
        struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        v1 = (u32)((u8 *)&stackFrame_11C);
        {
            struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v0 = (u32)((u8 *)&stackFrame_118);
            a1 = *(s32 *)(gsHdNowPlayerMsg + 3);
            a2 = *(s32 *)(gsHdPlayerName + 3);
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)((u8
                *)&stackFrame_10[0]));
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)gsHelpDiceCast);
            return;
        }
    }
}


/* MG2PMode2PDiceThrowPlayer1 @ 0x1F1E90 .. 0x1F1F0C (0x7c bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @1223 -> 0x2577e0
 *   literal: @1225 -> 0x2577e4
 *   stack: address of the slot at 0x10 escapes at 0x1f1ec8
 *   fpu: float literal 0x42400000 at 0x1f1ed8
 *   fpu: float literal 0x41a00000 at 0x1f1ee4
 *   fpu: float literal 0x3f4ccccd at 0x1f1ef4
 *   fpu: mov.s at 0x1f1efc is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f1ef8
 *   literal: @1225 initializes the 4-byte local at 0x118
 *   literal: @1223 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif






static void MG2PMode2PDiceThrowPlayer1(void) {
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    GetDiceNum();
    {
        struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        v1 = (u32)((u8 *)&stackFrame_11C);
        {
            struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v0 = (u32)((u8 *)&stackFrame_118);
            a1 = *(s32 *)(gsHdNowPlayerMsg + 3);
            a2 = *(s32 *)(gsHdPlayerName + 3);
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)((u8
                *)&stackFrame_10[0]));
            return;
        }
    }
}


/* MG2PMode2PChoisePiecePlayer @ 0x1F1DE0 .. 0x1F1E8C (0xac bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @1234 -> 0x2577e8
 *   literal: @1236 -> 0x2577ec
 *   stack: address of the slot at 0x10 escapes at 0x1f1e18
 *   fpu: float literal 0x42400000 at 0x1f1e28
 *   fpu: float literal 0x41a00000 at 0x1f1e34
 *   fpu: float literal 0x3f4ccccd at 0x1f1e44
 *   fpu: mov.s at 0x1f1e4c is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f1e48
 *   fpu: float literal 0x42400000 at 0x1f1e58
 *   fpu: float literal 0x43c30000 at 0x1f1e64
 *   fpu: float literal 0x3f4ccccd at 0x1f1e74
 *   fpu: mov.s at 0x1f1e7c is a float copy
 *   literal: @1236 initializes the 4-byte local at 0x118
 *   literal: @1234 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif







static void MG2PMode2PChoisePiecePlayer(void) {
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    GetDiceNum();
    {
        struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        v1 = (u32)((u8 *)&stackFrame_11C);
        {
            struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v0 = (u32)((u8 *)&stackFrame_118);
            a1 = *(s32 *)(gsHdNowPlayerMsg + 3);
            a2 = *(s32 *)(gsHdPlayerName + 3);
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)((u8
                *)&stackFrame_10[0]));
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)gsHelpChoiKoma);
            return;
        }
    }
}


/* MG2PMode2PChoiseDiePlayer @ 0x1F1D30 .. 0x1F1DDC (0xac bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @1245 -> 0x2577f0
 *   literal: @1247 -> 0x2577f4
 *   stack: address of the slot at 0x10 escapes at 0x1f1d68
 *   fpu: float literal 0x42400000 at 0x1f1d78
 *   fpu: float literal 0x41a00000 at 0x1f1d84
 *   fpu: float literal 0x3f4ccccd at 0x1f1d94
 *   fpu: mov.s at 0x1f1d9c is a float copy
 *   stack: address of the slot at 0x10 escapes at 0x1f1d98
 *   fpu: float literal 0x42400000 at 0x1f1da8
 *   fpu: float literal 0x43c30000 at 0x1f1db4
 *   fpu: float literal 0x3f4ccccd at 0x1f1dc4
 *   fpu: mov.s at 0x1f1dcc is a float copy
 *   literal: @1247 initializes the 4-byte local at 0x118
 *   literal: @1245 initializes the 4-byte local at 0x11c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif







static void MG2PMode2PChoiseDiePlayer(void) {
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;
    u8 stackFrame_10[264] __attribute__((aligned(16)));

    GetDiceNum();
    {
        struct stackFrame_11C { u8 b[4]; } stackFrame_11C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        v1 = (u32)((u8 *)&stackFrame_11C);
        {
            struct stackFrame_118 { u8 b[4]; } stackFrame_118 __attribute__((aligned(8))) = {{0x00,
                0x00, 0x00, 0x80}};
            v0 = (u32)((u8 *)&stackFrame_118);
            a1 = *(s32 *)(gsHdNowPlayerMsg + 3);
            a2 = *(s32 *)(gsHdPlayerName + 3);
            FsFontReplaceText((void *)((u8 *)&stackFrame_10[0]), (void *)a1, a2);
            f12 = 48.0f;
            f13 = 20.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 20.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)((u8
                *)&stackFrame_10[0]));
            f12 = 48.0f;
            f13 = 390.0f;
            f14 = 0.800000012f;
            MGFontPrintXYSclColShadow(48.0f, 390.0f, 0.800000012f, (float)0.800000012f, *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_11C)), *(struct
                dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_118)), (char *)gsHelpChoiDice);
            return;
        }
    }
}







/* MG2PModeViewResult @ 0x1F1AE0 .. 0x1F1D2C (0x24c bytes, frame 0x140) */
/*
 * dcomp notes:
 *   literal: @1268 -> 0x2577f8
 *   literal: @1270 -> 0x2577fc
 *   literal: @1272 -> 0x257800
 *   literal: @1274 -> 0x257804
 *   fpu: float literal 0x42340000 at 0x1f1b4c
 *   fpu: float literal 0x43960000 at 0x1f1b5c
 *   fpu: float literal 0x3f800000 at 0x1f1b64
 *   fpu: mov.s at 0x1f1b6c is a float copy
 *   stack: address of the slot at 0x30 escapes at 0x1f1b7c
 *   fpu: float literal 0x42340000 at 0x1f1b8c
 *   fpu: float literal 0x43a40000 at 0x1f1b98
 *   fpu: float literal 0x3f800000 at 0x1f1ba4
 *   fpu: mov.s at 0x1f1bac is a float copy
 *   stack: address of the slot at 0x30 escapes at 0x1f1ba8
 *   stack: address of the slot at 0x30 escapes at 0x1f1bbc
 *   fpu: float literal 0x42340000 at 0x1f1bcc
 *   fpu: float literal 0x43b20000 at 0x1f1bd8
 *   fpu: float literal 0x3f800000 at 0x1f1be4
 *   fpu: mov.s at 0x1f1bec is a float copy
 *   stack: address of the slot at 0x30 escapes at 0x1f1be8
 *   fpu: float literal 0x43a00000 at 0x1f1bf8
 *   fpu: float literal 0x43960000 at 0x1f1c04
 *   fpu: float literal 0x3f4ccccd at 0x1f1c18
 *   fpu: mov.s at 0x1f1c20 is a float copy
 *   fpu: float literal 0x43a00000 at 0x1f1c38
 *   fpu: float literal 0x43a40000 at 0x1f1c44
 *   fpu: float literal 0x3f4ccccd at 0x1f1c58
 *   fpu: mov.s at 0x1f1c60 is a float copy
 *   fpu: float literal 0x43a00000 at 0x1f1c6c
 *   fpu: float literal 0x43b20000 at 0x1f1c78
 *   fpu: float literal 0x3f4ccccd at 0x1f1c8c
 *   fpu: mov.s at 0x1f1c94 is a float copy
 *   fpu: float literal 0x43a00000 at 0x1f1cb4
 *   fpu: float literal 0x43a40000 at 0x1f1cc0
 *   fpu: float literal 0x3f4ccccd at 0x1f1cd4
 *   fpu: mov.s at 0x1f1cdc is a float copy
 *   fpu: float literal 0x43a00000 at 0x1f1ce8
 *   fpu: float literal 0x43b20000 at 0x1f1cf4
 *   fpu: float literal 0x3f4ccccd at 0x1f1d08
 *   fpu: mov.s at 0x1f1d10 is a float copy
 *   literal: @1274 initializes the 4-byte local at 0x130
 *   literal: @1272 initializes the 4-byte local at 0x134
 *   literal: @1270 initializes the 4-byte local at 0x138
 *   literal: @1268 initializes the 4-byte local at 0x13c
 */

#ifndef DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
#define DCOMP_BYTE_AGGREGATE_256D5D_DEFINED
struct dcomp_byte_aggregate_256d5d { unsigned char r, g, b, a; };
#endif









static void MG2PModeViewResult(void) {
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u8 *s1;
    u8 *s0;
    float f14;
    u32 v0;
    float f13;
    float f12;
    u8 stackFrame_30[256] __attribute__((aligned(16)));

    {
        struct stackFrame_13C { u8 b[4]; } stackFrame_13C __attribute__((aligned(4))) = {{0xff,
            0xff, 0xff, 0x80}};
        a1 = (u32)((u8 *)&stackFrame_13C);
        {
            struct stackFrame_138 { u8 b[4]; } stackFrame_138 __attribute__((aligned(4))) = {{0x00,
                0x00, 0x00, 0x80}};
            a0 = (u32)((u8 *)&stackFrame_138);
            {
                struct stackFrame_134 { u8 b[4]; } stackFrame_134 __attribute__((aligned(4))) =
                    {{0xff, 0x99, 0x00, 0x80}};
                v1 = (u32)((u8 *)&stackFrame_134);
                {
                    struct stackFrame_130 { u8 b[4]; } stackFrame_130 __attribute__((aligned(8))) =
                        {{0xff, 0xff, 0xff, 0x30}};
                    v0 = (u32)((u8 *)&stackFrame_130);
                    GetDiceNum();
                    v0 = GetWinNum();
                    s1 = (u8 *)v0;
                    GetPieceTable();
                    v0 = GetMenuPos();
                    s0 = (u8 *)v0;
                    f12 = 45.0f;
                    f13 = 300.0f;
                    f14 = 1.0f;
                    MGFontPrintXYSclColShadow(45.0f, 300.0f, 1.0f, (float)1.0f, *(struct
                        dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_13C)), *(struct
                        dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_138)), (char *)*(s32
                        *)(gsScoreMsg + 3));
                    a2 = *(u8 *)s1;
                    FsFontReplaceText((void *)((u8 *)&stackFrame_30[0]), (void *)*(s32
                        *)(gsScoreMsg + 4), a2);
                    f12 = 45.0f;
                    f13 = 328.0f;
                    f14 = 1.0f;
                    MGFontPrintXYSclColShadow(45.0f, 328.0f, 1.0f, (float)1.0f, *(struct
                        dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_13C)), *(struct
                        dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_138)), (char *)((u8
                        *)&stackFrame_30[0]));
                    FsFontReplaceText((void *)((u8 *)&stackFrame_30[0]), (void *)*(s32
                        *)(gsScoreMsg + 5), (u32)*(u8 *)(s1 + 1));
                    f12 = 45.0f;
                    f13 = 356.0f;
                    f14 = 1.0f;
                    MGFontPrintXYSclColShadow(45.0f, 356.0f, 1.0f, (float)1.0f, *(struct
                        dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_13C)), *(struct
                        dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_138)), (char *)((u8
                        *)&stackFrame_30[0]));
                    f12 = 320.0f;
                    f13 = 300.0f;
                    f14 = 0.800000012f;
                    MGFontPrintXYSclColShadow(320.0f, 300.0f, 0.800000012f, (float)0.800000012f,
                        *(struct dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_13C)), *(struct
                        dcomp_byte_aggregate_256d5d *)(((u8 *)&stackFrame_138)), (char *)*(s32
                        *)gsReplayMsg);
                    a0 = *(u8 *)s0;
                    if (a0 == 0) {
                        f12 = 320.0f;
                        f13 = 328.0f;
                        f14 = 0.800000012f;
                        MGFontPrintXYSclColShadow(320.0f, 328.0f, 0.800000012f,
                            (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_134)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_138)), (char *)*(s32 *)(gsReplayMsg + 1));
                        f12 = 320.0f;
                        f13 = 356.0f;
                        f14 = 0.800000012f;
                        MGFontPrintXYSclColShadow(320.0f, 356.0f, 0.800000012f,
                            (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_130)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_138)), (char *)*(s32 *)(gsReplayMsg + 2));
                    } else if (a0 == (u32)1) {
                        f12 = 320.0f;
                        f13 = 328.0f;
                        f14 = 0.800000012f;
                        MGFontPrintXYSclColShadow(320.0f, 328.0f, 0.800000012f,
                            (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_130)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_138)), (char *)*(s32 *)(gsReplayMsg + 1));
                        f12 = 320.0f;
                        f13 = 356.0f;
                        f14 = 0.800000012f;
                        MGFontPrintXYSclColShadow(320.0f, 356.0f, 0.800000012f,
                            (float)0.800000012f, *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_134)), *(struct dcomp_byte_aggregate_256d5d *)(((u8
                            *)&stackFrame_138)), (char *)*(s32 *)(gsReplayMsg + 2));
                    }
                    return;
                }
            }
        }
    }
}









































static u32 g_MGTextFuncTbl[0x4d] = {
    (u32)&MGTopMenuText, 0, (u32)&MGMainMenuText, 0, 0, (u32)&MGMainMenuText, 0, 0,
    (u32)&MGOrderPlayerText0, (u32)&MGOrderPlayerText1, (u32)&MGOrderPlayerText2,
    (u32)&MGOrderPlayerText3, (u32)&MGOrderCPUText1, (u32)&MGOrderCPUText2,
    (u32)&MGOrderCPUText3, (u32)&MGOrderLastView, (u32)&MGDiceThrowPlayer,
    (u32)&MGDiceThrowPlayer1, (u32)&MGChoisePiecePlayer, (u32)&MGChoiseDiePlayer,
    (u32)&MGDiceThrowPlayer1, (u32)&MGDiceThrowCPU, (u32)&MGDiceThrowCPU, (u32)&MGDiceThrowCPU,
    (u32)&MGDiceThrowCPU, (u32)&MGDiceThrowCPU, 0, 0, 0, (u32)&MGViewResult, 0, 0,
    (u32)&MGTutorialText1View, (u32)&MGTutorialText2View, (u32)&MGTutorialText3View,
    (u32)&MGTutorialThrowText, (u32)&MGTutorialThrowNowText, (u32)&MGTutorialChoisePiece,
    (u32)&MGTutorialChoiseDie, (u32)&MGTutorialThrowNowText, 0, (u32)&MGTutorialText4View,
    (u32)&MGTutorialOnmoreText, 0, 0, 0, (u32)&MG2PModeOrderPlayerText0,
    (u32)&MG2PMode1POrderPlayerText1, (u32)&MG2PMode1POrderPlayerText2,
    (u32)&MG2PMode1POrderPlayerText3, (u32)&MG2PMode2POrderPlayerText1,
    (u32)&MG2PMode2POrderPlayerText2, (u32)&MG2PMode2POrderPlayerText3,
    (u32)&MG2PModeOrderLastView, (u32)&MG2PMode1PDiceThrowPlayer,
    (u32)&MG2PMode1PDiceThrowPlayer1, (u32)&MG2PMode1PChoisePiecePlayer,
    (u32)&MG2PMode1PChoiseDiePlayer, (u32)&MG2PMode1PDiceThrowPlayer1,
    (u32)&MG2PMode2PDiceThrowPlayer, (u32)&MG2PMode2PDiceThrowPlayer1,
    (u32)&MG2PMode2PChoisePiecePlayer, (u32)&MG2PMode2PChoiseDiePlayer,
    (u32)&MG2PMode2PDiceThrowPlayer1, 0, 0, 0, (u32)&MG2PModeViewResult
};
