#include "common.h"

/* MGFontPrintXYSclColShadow @ 0x1F7BF0 .. 0x1F7D14 (0x124 bytes, frame 0x2c0) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1f7c0c is a float copy
 *   fpu: mov.s at 0x1f7c14 is a float copy
 *   fpu: mov.s at 0x1f7c1c is a float copy
 *   fpu: mov.s at 0x1f7c3c is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x1f7c70
 *   fpu: mov.s at 0x1f7c98 is a float copy
 *   fpu: mov.s at 0x1f7ca0 is a float copy
 *   fpu: float literal 0x40000000 at 0x1f7cac
 *   stack: address of the slot at 0x20 escapes at 0x1f7cb8
 *   fpu: mov.s at 0x1f7cd0 is a float copy
 *   fpu: mov.s at 0x1f7cd8 is a float copy
 *   fpu: mov.s at 0x1f7cdc is a float copy
 *   fpu: mov.s at 0x1f7ce8 is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x1f7ce4
 */

extern signed int FsFontReplaceText(void *, void *, ...);
extern void SetFontColor(u8 *);
extern signed int FsFontSetScale(float, float);
extern void FontPrintXY(float, float, char *, ...);
extern void SetLastFontColor();

/* MGFontDrawEnd @ 0x1F7D20 .. 0x1F7D28 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j FontDrawEnd at 0x1f7d20 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 FontDrawEnd();

/* MGFontDrawBegin @ 0x1F7D30 .. 0x1F7D38 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j FontDrawBegin at 0x1f7d30 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern void FontDrawBegin();

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void MGFontDrawBegin(void);
void MGFontDrawEnd(void);
void MGFontPrintXYSclColShadow(float f12 , float f13 , float f14 , float f15 , u8 *a0 , s32 a1 , u8 *a2 , ...);


void MGFontDrawBegin(void) {
    FontDrawBegin();
    return;
}

void MGFontDrawEnd(void) {
    FontDrawEnd();
    return;
}

void MGFontPrintXYSclColShadow(float f12 /* f12 */, float f13 /* f13 */, float f14 /* f14 */, float
        f15 /* f15 */, u8 *a0 /* r4 */, s32 a1 /* r5 */, u8 *a2 /* r6 */, ...) {
    float f23;
    float f22;
    float f21;
    float f20;
    u8 *a2_value; // a2
    s32 a1_value; // a1
    u8 *a0_value; // a0
    u32 v1;
    u32 v0;
    u8 stackFrame_20[512] __attribute__((aligned(16)));

    a0_value = a0;
    a1_value = a1;
    a2_value = a2;
    f23 = f12;
    f22 = f13;
    f21 = f14;
    v1 = *(s32 *)((u8 *)&a2);
    f20 = f15;
    if (v1 != 0) {
        v1 = (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
        a1_value = *(s32 *)((u8 *)&a2);
        v0 = (u32)((u8 *)__builtin_next_arg(a2));
        a2_value = (u8 *)((u8 *)((u8 *)__builtin_next_arg(a2)) - v1);
        if ((u32)a1_value != 0) {
            FsFontReplaceText((void *)(u8 *)((u8 *)&stackFrame_20[0]), (void *)a1_value, a2_value);
            ((u8 *)stackFrame_20)[511] = 0;
            ((u8 *)stackFrame_20)[510] = 0;
        } else {
            *(u8 *)((u8 *)&stackFrame_20[0]) = 0;
        }
        SetFontColor((u8 *)*(s32 *)((u8 *)&a1));
        FsFontSetScale((float)f21, (float)f20);
        FontPrintXY((2.0f + f23), (2.0f + f22), (char *)(u8 *)((u8 *)&stackFrame_20[0]));
        SetLastFontColor();
        SetFontColor((u8 *)*(s32 *)((u8 *)&a0));
        FsFontSetScale((float)f21, (float)f20);
        FontPrintXY((float)f23, (float)f22, (char *)(u8 *)((u8 *)&stackFrame_20[0]));
        SetLastFontColor();
    }
    return;
}
