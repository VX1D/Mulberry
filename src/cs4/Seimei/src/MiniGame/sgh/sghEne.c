#include "common.h"

/* sghEneThinking @ 0x208A50 .. 0x208B50 (0x100 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x3c escapes at 0x208a74
 *   delay: addiu at 0x208aa0 writes a register its branch at 0x208a9c reads
 *   stack: address of the slot at 0x3c escapes at 0x208ac4
 *   stack: address of the slot at 0x3c escapes at 0x208adc
 *   stack: address of the slot at 0x3c escapes at 0x208af4
 *   stack: address of the slot at 0x3c escapes at 0x208b0c
 *   stack: 4-byte aggregate copy in 1-byte chunks at 0x208b38
 *   return without a value in a non-void function
 */

extern u32 sghEneThk_GetOutSideKomaNum();
extern void sghEneThk_ThinkNomal(u8 *, u8 *);
extern void sghEneThk_ThinkOutSideOnce(u8 *, u8 *);
extern void sghEneThk_ThinkOutSide(u8 *, u8 *);

u8 sghEneThinking(u8 *a0 /* r4 */, u8 *a1 /* r5 */) {
    u32 s1;
    u8 *s0;
    u32 v1;
    u32 v0;
    u8 *a0_2;
    u8 *a1_2;
    struct __copy_u8_4 { u8 b[4]; };

    s1 = (u32)a1;
    s0 = a0;
    {
        u8 stackFrame_3C[4] __attribute__((aligned(4))) = {0};
        v0 = sghEneThk_GetOutSideKomaNum();
        v1 = 2;
        switch (v0) {
        case 0:
            a1_2 = (u8 *)s1;
            a0_2 = ((u8 *)&stackFrame_3C[0]);
            sghEneThk_ThinkNomal(a0_2, a1_2);
            break;
        case 1:
            a1_2 = (u8 *)s1;
            a0_2 = ((u8 *)&stackFrame_3C[0]);
            sghEneThk_ThinkOutSideOnce(a0_2, a1_2);
            break;
        case 2:
            a1_2 = (u8 *)s1;
            a0_2 = ((u8 *)&stackFrame_3C[0]);
            sghEneThk_ThinkOutSide(a0_2, a1_2);
            break;
        default:
            a1_2 = (u8 *)s1;
            a0_2 = ((u8 *)&stackFrame_3C[0]);
            sghEneThk_ThinkOutSide(a0_2, a1_2);
        }
        v1 = (u32)((u8 *)&stackFrame_3C[0]);
        *(struct __copy_u8_4 *)s0 = *(struct __copy_u8_4 *)((u8 *)&stackFrame_3C[0]);
        return;
    }
}
