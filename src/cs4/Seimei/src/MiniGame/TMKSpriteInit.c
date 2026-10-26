#include "common.h"





extern u32 GetSpriteDraw(void);
static void MGSetSpriteZPos(unsigned int);
extern u32 GetSpriteDraw(void);
void MGInitReturnSGHMenuFade(void);
void MGDrawSetMenuHelpWnd(unsigned char a0 /* r4 */);



/* MGSetSpriteZPos @ 0x2041C0 .. 0x2043E8 */

static void MGSetSpriteZPos(unsigned int id) {
    u8 *spr;
    s32 i;

    spr = (u8 *)GetSpriteDraw();
    switch (id) {
    case 0:
        {
            struct { u8 b[108]; } tbl __attribute__((aligned(16))) = {{0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
            for (i = 0; i < 0x6c; i = i + 1) {
                spr[i * 0x70 + 3] = tbl.b[i];
            }
            break;
        }
    case 1:
        {
            struct { u8 b[108]; } tbl __attribute__((aligned(16))) = {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
            for (i = 0; i < 0x6c; i = i + 1) {
                spr[i * 0x70 + 3] = tbl.b[i];
            }
        }
    }
    return;
}


/* MGInitTopMenu @ 0x2040A0 .. 0x2041B4 (0x114 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @695 -> 0x24f370
 *   stack: address of the slot at 0x10 escapes at 0x2040c0
 *   stack: address of the slot at 0x10 escapes at 0x204100
 *   literal: @695 initializes the 108-byte local at 0x10
 */

void MGInitTopMenu(void) {
    u8 *t0;
    u8 *a3;
    u32 a2;
    u32 a1;
    u32 a0;
    s32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x01,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        v1 = 0;
        for (; v1 < 0x6c; v1 = v1 + 1) {
            v0[v1 * 0x70 + 2] = stackFrame_10.b[v1];
        }
        MGSetSpriteZPos(0);
        return;
    }
}
/* MGDrawSetMenuHelpWnd @ 0x204060 .. 0x2040A0 (0x40 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */


void MGDrawSetMenuHelpWnd(unsigned char a0 /* r4 */) {
    u32 s0;
    u8 *v0;
    s32 v1;

    s0 = a0;
    v0 = (u8 *)GetSpriteDraw();
    v1 = (u8)s0;
    if ((u32)v1 == 0) {
        *(u8 *)(((u8 *)v0 + 0x152)) = 0;
    } else {
        v1 = 1;
        *(u8 *)(((u8 *)v0 + 0x152)) = v1;
    }
    return;
}



/* MGInitSGHGameMemu @ 0x203F40 .. 0x204054 (0x114 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @715 -> 0x24f3e0
 *   stack: address of the slot at 0x10 escapes at 0x203f60
 *   stack: address of the slot at 0x10 escapes at 0x203fa0
 *   literal: @715 initializes the 108-byte local at 0x10
 */

void MGInitSGHGameMemu(void) {
    u8 *t0;
    u8 *a3;
    u32 a2;
    u32 a1;
    u32 a0;
    s32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x00,
            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        v1 = 0;
        for (; v1 < 0x6c; v1 = v1 + 1) {
            v0[v1 * 0x70 + 2] = stackFrame_10.b[v1];
        }
        MGSetSpriteZPos(0);
        return;
    }
}



/* MGInitTMKGameMenu @ 0x203E20 .. 0x203F34 (0x114 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @727 -> 0x24f450
 *   stack: address of the slot at 0x10 escapes at 0x203e40
 *   stack: address of the slot at 0x10 escapes at 0x203e80
 *   literal: @727 initializes the 108-byte local at 0x10
 */

void MGInitTMKGameMenu(void) {
    u8 *t0;
    u8 *a3;
    u32 a2;
    u32 a1;
    u32 a0;
    s32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x00,
            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        v1 = 0;
        for (; v1 < 0x6c; v1 = v1 + 1) {
            v0[v1 * 0x70 + 2] = stackFrame_10.b[v1];
        }
        MGSetSpriteZPos(0);
        return;
    }
}


/* MGInitOrderPlay @ 0x203D00 .. 0x203E14 (0x114 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @739 -> 0x24f4c0
 *   stack: address of the slot at 0x10 escapes at 0x203d20
 *   stack: address of the slot at 0x10 escapes at 0x203d60
 *   literal: @739 initializes the 108-byte local at 0x10
 */

void MGInitOrderPlay(void) {
    u8 *t0;
    u8 *a3;
    u32 a2;
    u32 a1;
    u32 a0;
    s32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        v1 = 0;
        for (; v1 < 0x6c; v1 = v1 + 1) {
            v0[v1 * 0x70 + 2] = stackFrame_10.b[v1];
        }
        MGSetSpriteZPos(0);
        return;
    }
}


/* MGInitMainPlay @ 0x203BE0 .. 0x203CF4 (0x114 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @751 -> 0x24f530
 *   stack: address of the slot at 0x10 escapes at 0x203c00
 *   stack: address of the slot at 0x10 escapes at 0x203c40
 *   literal: @751 initializes the 108-byte local at 0x10
 */

void MGInitMainPlay(void) {
    u8 *t0;
    u8 *a3;
    u32 a2;
    u32 a1;
    u32 a0;
    s32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        v1 = 0;
        for (; v1 < 0x6c; v1 = v1 + 1) {
            v0[v1 * 0x70 + 2] = stackFrame_10.b[v1];
        }
        MGSetSpriteZPos(0);
        return;
    }
}


/* MGInitComplsion @ 0x203AC0 .. 0x203BD4 (0x114 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @763 -> 0x24f5a0
 *   stack: address of the slot at 0x10 escapes at 0x203ae0
 *   stack: address of the slot at 0x10 escapes at 0x203b20
 *   literal: @763 initializes the 108-byte local at 0x10
 */

void MGInitComplsion(void) {
    u8 *t0;
    u8 *a3;
    u32 a2;
    u32 a1;
    u32 a0;
    s32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        v1 = 0;
        for (; v1 < 0x6c; v1 = v1 + 1) {
            v0[v1 * 0x70 + 2] = stackFrame_10.b[v1];
        }
        MGSetSpriteZPos(0);
        return;
    }
}


/* MGInitTutorialTextView @ 0x2039A0 .. 0x203AB4 (0x114 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @775 -> 0x24f610
 *   stack: address of the slot at 0x10 escapes at 0x2039c0
 *   stack: address of the slot at 0x10 escapes at 0x203a00
 *   literal: @775 initializes the 108-byte local at 0x10
 */

void MGInitTutorialTextView(void) {
    u8 *t0;
    u8 *a3;
    u32 a2;
    u32 a1;
    u32 a0;
    s32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        v1 = 0;
        for (; v1 < 0x6c; v1 = v1 + 1) {
            v0[v1 * 0x70 + 2] = stackFrame_10.b[v1];
        }
        MGSetSpriteZPos(0);
        return;
    }
}


/* MGInitTutorialView @ 0x203880 .. 0x203994 (0x114 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @787 -> 0x24f680
 *   stack: address of the slot at 0x10 escapes at 0x2038a0
 *   stack: address of the slot at 0x10 escapes at 0x2038e0
 *   literal: @787 initializes the 108-byte local at 0x10
 */

void MGInitTutorialView(void) {
    u8 *t0;
    u8 *a3;
    u32 a2;
    u32 a1;
    u32 a0;
    s32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        v1 = 0;
        for (; v1 < 0x6c; v1 = v1 + 1) {
            v0[v1 * 0x70 + 2] = stackFrame_10.b[v1];
        }
        MGSetSpriteZPos(0);
        return;
    }
}


/* MGInitSGHMenuFromTopMenuFade @ 0x203760 .. 0x203880 (0x120 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @799 -> 0x24f6f0
 *   stack: address of the slot at 0x10 escapes at 0x203780
 *   stack: address of the slot at 0x10 escapes at 0x2037d8
 *   literal: @799 initializes the 108-byte local at 0x10
 *   cfg: loop body is not one contiguous region: .L002037D8
 */

void MGInitSGHMenuFromTopMenuFade(void) {
    s32 t4;
    u8 *t3;
    s32 t2;
    s32 t1;
    s32 t0;
    u32 a3;
    u32 a2;
    s32 a1;
    u32 a0;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x03,
            0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00,
            0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x02,
            0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x02, 0x02,
            0x02, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x02,
            0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        t4 = 0;
        t3 = ((u8 *)&stackFrame_10);
        t1 = 1;
        t0 = 4;
        a3 = 3;
        a0 = 2;
        a1 = 0x7f;
        a2 = 5;
        t2 = 7;
        do {
            v1 = *(u8 *)t3;
            if (v1 == (u32)t2) {
                v1 = *(u8 *)(v0 + 2);
                if (v1 == (u32)t1 || v1 == (u32)t0) {
                    *(u8 *)t3 = a3;
                } else {
                    *(u8 *)t3 = 0;
                }
            }
            v1 = *(u8 *)t3;
            if (v1 != a2) {
                *(u8 *)(v0 + 2) = v1;
                v1 = *(u8 *)(v0 + 2);
                if (v1 == a3) {
                    v1 = *(s32 *)(v0 + 0x3c);
                    *(u32 *)(v0 + 0x4c) = v1;
                    v1 = *(s32 *)(v0 + 0x4c);
                    if ((s32)v1 > (s32)0x7f) {
                        *(u32 *)(v0 + 0x4c) = a1;
                    }
                } else if (v1 == a0) {
                    *(u32 *)(v0 + 0x4c) = 0;
                }
            }
            t4 = t4 + 1;
            v1 = t4 < (s32)0x6c;
            t3 = (u8 *)(t3 + 1);
            v0 = (u8 *)(v0 + 0x70);
        } while (v1 != 0);
        MGSetSpriteZPos(0);
        return;
    }
}


/* MGInitTMKMenuFromTopMenuFade @ 0x203640 .. 0x203760 (0x120 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @826 -> 0x24f760
 *   stack: address of the slot at 0x10 escapes at 0x203660
 *   stack: address of the slot at 0x10 escapes at 0x2036b8
 *   literal: @826 initializes the 108-byte local at 0x10
 *   cfg: loop body is not one contiguous region: .L002036B8
 */

void MGInitTMKMenuFromTopMenuFade(void) {
    s32 t4;
    u8 *t3;
    s32 t2;
    s32 t1;
    s32 t0;
    u32 a3;
    u32 a2;
    s32 a1;
    u32 a0;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x03,
            0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00,
            0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00,
            0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x02,
            0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        t4 = 0;
        t3 = ((u8 *)&stackFrame_10);
        t1 = 1;
        t0 = 4;
        a3 = 3;
        a0 = 2;
        a1 = 0x7f;
        a2 = 5;
        t2 = 7;
        do {
            v1 = *(u8 *)t3;
            if (v1 == (u32)t2) {
                v1 = *(u8 *)(v0 + 2);
                if (v1 == (u32)t1 || v1 == (u32)t0) {
                    *(u8 *)t3 = a3;
                } else {
                    *(u8 *)t3 = 0;
                }
            }
            v1 = *(u8 *)t3;
            if (v1 != a2) {
                *(u8 *)(v0 + 2) = v1;
                v1 = *(u8 *)(v0 + 2);
                if (v1 == a3) {
                    v1 = *(s32 *)(v0 + 0x3c);
                    *(u32 *)(v0 + 0x4c) = v1;
                    v1 = *(s32 *)(v0 + 0x4c);
                    if ((s32)v1 > (s32)0x7f) {
                        *(u32 *)(v0 + 0x4c) = a1;
                    }
                } else if (v1 == a0) {
                    *(u32 *)(v0 + 0x4c) = 0;
                }
            }
            t4 = t4 + 1;
            v1 = t4 < (s32)0x6c;
            t3 = (u8 *)(t3 + 1);
            v0 = (u8 *)(v0 + 0x70);
        } while (v1 != 0);
        MGSetSpriteZPos(0);
        return;
    }
}


/* MGInitTopMenuFromGameMenuFade @ 0x203520 .. 0x203640 (0x120 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @853 -> 0x24f7d0
 *   stack: address of the slot at 0x10 escapes at 0x203540
 *   stack: address of the slot at 0x10 escapes at 0x203598
 *   literal: @853 initializes the 108-byte local at 0x10
 *   cfg: loop body is not one contiguous region: .L00203598
 */

void MGInitTopMenuFromGameMenuFade(void) {
    s32 t4;
    u8 *t3;
    s32 t2;
    s32 t1;
    s32 t0;
    u32 a3;
    u32 a2;
    s32 a1;
    u32 a0;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x02,
            0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x02, 0x00, 0x02, 0x02, 0x00,
            0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x07, 0x07, 0x07, 0x07, 0x02, 0x02, 0x00, 0x02, 0x00, 0x02, 0x02, 0x00, 0x07, 0x07,
            0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        t4 = 0;
        t3 = ((u8 *)&stackFrame_10);
        t1 = 1;
        t0 = 4;
        a3 = 3;
        a0 = 2;
        a1 = 0x7f;
        a2 = 5;
        t2 = 7;
        do {
            v1 = *(u8 *)t3;
            if (v1 == (u32)t2) {
                v1 = *(u8 *)(v0 + 2);
                if (v1 == (u32)t1 || v1 == (u32)t0) {
                    *(u8 *)t3 = a3;
                } else {
                    *(u8 *)t3 = 0;
                }
            }
            v1 = *(u8 *)t3;
            if (v1 != a2) {
                *(u8 *)(v0 + 2) = v1;
                v1 = *(u8 *)(v0 + 2);
                if (v1 == a3) {
                    v1 = *(s32 *)(v0 + 0x3c);
                    *(u32 *)(v0 + 0x4c) = v1;
                    v1 = *(s32 *)(v0 + 0x4c);
                    if ((s32)v1 > (s32)0x7f) {
                        *(u32 *)(v0 + 0x4c) = a1;
                    }
                } else if (v1 == a0) {
                    *(u32 *)(v0 + 0x4c) = 0;
                }
            }
            t4 = t4 + 1;
            v1 = t4 < (s32)0x6c;
            t3 = (u8 *)(t3 + 1);
            v0 = (u8 *)(v0 + 0x70);
        } while (v1 != 0);
        MGSetSpriteZPos(0);
        return;
    }
}


/* MGInitTopMenuMainFade @ 0x203400 .. 0x203520 (0x120 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @880 -> 0x24f840
 *   stack: address of the slot at 0x10 escapes at 0x203420
 *   stack: address of the slot at 0x10 escapes at 0x203478
 *   literal: @880 initializes the 108-byte local at 0x10
 *   cfg: loop body is not one contiguous region: .L00203478
 */

void MGInitTopMenuMainFade(void) {
    s32 t4;
    u8 *t3;
    s32 t2;
    s32 t1;
    s32 t0;
    u32 a3;
    u32 a2;
    s32 a1;
    u32 a0;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x00,
            0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07,
            0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        t4 = 0;
        t3 = ((u8 *)&stackFrame_10);
        t1 = 1;
        t0 = 4;
        a3 = 3;
        a0 = 2;
        a1 = 0x7f;
        a2 = 5;
        t2 = 7;
        do {
            v1 = *(u8 *)t3;
            if (v1 == (u32)t2) {
                v1 = *(u8 *)(v0 + 2);
                if (v1 == (u32)t1 || v1 == (u32)t0) {
                    *(u8 *)t3 = a3;
                } else {
                    *(u8 *)t3 = 0;
                }
            }
            v1 = *(u8 *)t3;
            if (v1 != a2) {
                *(u8 *)(v0 + 2) = v1;
                v1 = *(u8 *)(v0 + 2);
                if (v1 == a3) {
                    v1 = *(s32 *)(v0 + 0x3c);
                    *(u32 *)(v0 + 0x4c) = v1;
                    v1 = *(s32 *)(v0 + 0x4c);
                    if ((s32)v1 > (s32)0x7f) {
                        *(u32 *)(v0 + 0x4c) = a1;
                    }
                } else if (v1 == a0) {
                    *(u32 *)(v0 + 0x4c) = 0;
                }
            }
            t4 = t4 + 1;
            v1 = t4 < (s32)0x6c;
            t3 = (u8 *)(t3 + 1);
            v0 = (u8 *)(v0 + 0x70);
        } while (v1 != 0);
        MGSetSpriteZPos(0);
        return;
    }
}


/* MGInitMovePieceFade @ 0x203340 .. 0x2033F8 (0xb8 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @907 -> 0x24f8b0
 *   stack: address of the slot at 0x10 escapes at 0x203360
 *   stack: address of the slot at 0x10 escapes at 0x2033a0
 *   literal: @907 initializes the 108-byte local at 0x10
 *   cfg: loop body is not one contiguous region: .L002033A0
 */

void MGInitMovePieceFade(void) {
    s32 t0;
    u8 *a3;
    s32 a1;
    u32 a0;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x01, 0x03, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        t0 = 0;
        a3 = ((u8 *)&stackFrame_10);
        a0 = 2;
        a1 = 3;
        do {
            v1 = *(u8 *)a3;
            *(u8 *)(v0 + 2) = v1;
            v1 = *(u8 *)(v0 + 2);
            if (v1 == (u32)a1) {
                v1 = *(s32 *)(v0 + 0x3c);
                *(u32 *)(v0 + 0x4c) = v1;
            } else if (v1 == a0) {
                *(u32 *)(v0 + 0x4c) = 0;
            }
            t0 = t0 + 1;
            v1 = t0 < (s32)0x6c;
            a3 = (u8 *)(a3 + 1);
            v0 = (u8 *)(v0 + 0x70);
        } while (v1 != 0);
        MGSetSpriteZPos(0);
        return;
    }
}


/* MGInitTopMenuTutorialFade @ 0x203220 .. 0x203340 (0x120 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @924 -> 0x24f920
 *   stack: address of the slot at 0x10 escapes at 0x203240
 *   stack: address of the slot at 0x10 escapes at 0x203298
 *   literal: @924 initializes the 108-byte local at 0x10
 *   cfg: loop body is not one contiguous region: .L00203298
 */

void MGInitTopMenuTutorialFade(void) {
    s32 t4;
    u8 *t3;
    s32 t2;
    s32 t1;
    s32 t0;
    u32 a3;
    u32 a2;
    s32 a1;
    u32 a0;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x00,
            0x03, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07,
            0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        t4 = 0;
        t3 = ((u8 *)&stackFrame_10);
        t1 = 1;
        t0 = 4;
        a3 = 3;
        a0 = 2;
        a1 = 0x7f;
        a2 = 5;
        t2 = 7;
        do {
            v1 = *(u8 *)t3;
            if (v1 == (u32)t2) {
                v1 = *(u8 *)(v0 + 2);
                if (v1 == (u32)t1 || v1 == (u32)t0) {
                    *(u8 *)t3 = a3;
                } else {
                    *(u8 *)t3 = 0;
                }
            }
            v1 = *(u8 *)t3;
            if (v1 != a2) {
                *(u8 *)(v0 + 2) = v1;
                v1 = *(u8 *)(v0 + 2);
                if (v1 == a3) {
                    v1 = *(s32 *)(v0 + 0x3c);
                    *(u32 *)(v0 + 0x4c) = v1;
                    v1 = *(s32 *)(v0 + 0x4c);
                    if ((s32)v1 > (s32)0x7f) {
                        *(u32 *)(v0 + 0x4c) = a1;
                    }
                } else if (v1 == a0) {
                    *(u32 *)(v0 + 0x4c) = 0;
                }
            }
            t4 = t4 + 1;
            v1 = t4 < (s32)0x6c;
            t3 = (u8 *)(t3 + 1);
            v0 = (u8 *)(v0 + 0x70);
        } while (v1 != 0);
        MGSetSpriteZPos(0);
        return;
    }
}


/* MGInitReturnTopMenuMainFade @ 0x203100 .. 0x203220 (0x120 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @951 -> 0x24f990
 *   stack: address of the slot at 0x10 escapes at 0x203120
 *   stack: address of the slot at 0x10 escapes at 0x203178
 *   literal: @951 initializes the 108-byte local at 0x10
 *   cfg: loop body is not one contiguous region: .L00203178
 */

void MGInitReturnTopMenuMainFade(void) {
    s32 t4;
    u8 *t3;
    s32 t2;
    s32 t1;
    s32 t0;
    u32 a3;
    u32 a2;
    s32 a1;
    u32 a0;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x00,
            0x02, 0x03, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00,
            0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x02,
            0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        t4 = 0;
        t3 = ((u8 *)&stackFrame_10);
        t1 = 1;
        t0 = 4;
        a3 = 3;
        a0 = 2;
        a1 = 0x7f;
        a2 = 5;
        t2 = 7;
        do {
            v1 = *(u8 *)t3;
            if (v1 == (u32)t2) {
                v1 = *(u8 *)(v0 + 2);
                if (v1 == (u32)t1 || v1 == (u32)t0) {
                    *(u8 *)t3 = a3;
                } else {
                    *(u8 *)t3 = 0;
                }
            }
            v1 = *(u8 *)t3;
            if (v1 != a2) {
                *(u8 *)(v0 + 2) = v1;
                v1 = *(u8 *)(v0 + 2);
                if (v1 == a3) {
                    v1 = *(s32 *)(v0 + 0x3c);
                    *(u32 *)(v0 + 0x4c) = v1;
                    v1 = *(s32 *)(v0 + 0x4c);
                    if ((s32)v1 > (s32)0x7f) {
                        *(u32 *)(v0 + 0x4c) = a1;
                    }
                } else if (v1 == a0) {
                    *(u32 *)(v0 + 0x4c) = 0;
                }
            }
            t4 = t4 + 1;
            v1 = t4 < (s32)0x6c;
            t3 = (u8 *)(t3 + 1);
            v0 = (u8 *)(v0 + 0x70);
        } while (v1 != 0);
        MGSetSpriteZPos(0);
        return;
    }
}


/* MGInitResultWinTexAniFade @ 0x203030 .. 0x2030F4 (0xc4 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @979 -> 0x24fa00
 *   stack: address of the slot at 0x20 escapes at 0x203058
 *   stack: address of the slot at 0x20 escapes at 0x203098
 *   literal: @979 initializes the 108-byte local at 0x20
 *   cfg: loop body is not one contiguous region: .L00203098
 */

extern unsigned char GetWinFlag(void);

void MGInitResultWinTexAniFade(void) {
    s32 a3;
    u8 *s0;
    u8 *a2;
    u32 v0;

    v0 = GetSpriteDraw();
    s0 = (u8 *)v0;
    GetWinFlag();
    {
        struct stackFrame_20 { u8 b[108]; } stackFrame_20 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        a3 = 0;
        a2 = ((u8 *)&stackFrame_20);
        do {
            v0 = *(u8 *)a2;
            *(u8 *)(s0 + 2) = v0;
            v0 = *(u8 *)(s0 + 2);
            if (v0 == (u32)3) {
                v0 = *(s32 *)(s0 + 0x3c);
                *(u32 *)(s0 + 0x4c) = v0;
            } else if (v0 == (u32)2) {
                *(u32 *)(s0 + 0x4c) = 0;
            }
            a3 = a3 + 1;
            v0 = a3 < (s32)0x6c;
            a2 = (u8 *)(a2 + 1);
            s0 = (u8 *)(s0 + 0x70);
        } while (v0 != 0);
        MGSetSpriteZPos(1);
        return;
    }
}


/* MGInitResultLoseTexAniFade @ 0x202F60 .. 0x203024 (0xc4 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @997 -> 0x24fa70
 *   stack: address of the slot at 0x20 escapes at 0x202f88
 *   stack: address of the slot at 0x20 escapes at 0x202fc8
 *   literal: @997 initializes the 108-byte local at 0x20
 *   cfg: loop body is not one contiguous region: .L00202FC8
 */



void MGInitResultLoseTexAniFade(void) {
    s32 a3;
    u8 *s0;
    u8 *a2;
    u32 v0;

    v0 = GetSpriteDraw();
    s0 = (u8 *)v0;
    GetWinFlag();
    {
        struct stackFrame_20 { u8 b[108]; } stackFrame_20 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        a3 = 0;
        a2 = ((u8 *)&stackFrame_20);
        do {
            v0 = *(u8 *)a2;
            *(u8 *)(s0 + 2) = v0;
            v0 = *(u8 *)(s0 + 2);
            if (v0 == (u32)3) {
                v0 = *(s32 *)(s0 + 0x3c);
                *(u32 *)(s0 + 0x4c) = v0;
            } else if (v0 == (u32)2) {
                *(u32 *)(s0 + 0x4c) = 0;
            }
            a3 = a3 + 1;
            v0 = a3 < (s32)0x6c;
            a2 = (u8 *)(a2 + 1);
            s0 = (u8 *)(s0 + 0x70);
        } while (v0 != 0);
        MGSetSpriteZPos(1);
        return;
    }
}


/* MGInitResultWinTexAniFade2 @ 0x202E90 .. 0x202F54 (0xc4 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1015 -> 0x24fae0
 *   stack: address of the slot at 0x20 escapes at 0x202eb8
 *   stack: address of the slot at 0x20 escapes at 0x202ef8
 *   literal: @1015 initializes the 108-byte local at 0x20
 *   cfg: loop body is not one contiguous region: .L00202EF8
 */



void MGInitResultWinTexAniFade2(void) {
    s32 a3;
    u8 *s0;
    u8 *a2;
    u32 v0;

    v0 = GetSpriteDraw();
    s0 = (u8 *)v0;
    GetWinFlag();
    {
        struct stackFrame_20 { u8 b[108]; } stackFrame_20 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x01, 0x00, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        a3 = 0;
        a2 = ((u8 *)&stackFrame_20);
        do {
            v0 = *(u8 *)a2;
            *(u8 *)(s0 + 2) = v0;
            v0 = *(u8 *)(s0 + 2);
            if (v0 == (u32)3) {
                v0 = *(s32 *)(s0 + 0x3c);
                *(u32 *)(s0 + 0x4c) = v0;
            } else if (v0 == (u32)2) {
                *(u32 *)(s0 + 0x4c) = 0;
            }
            a3 = a3 + 1;
            v0 = a3 < (s32)0x6c;
            a2 = (u8 *)(a2 + 1);
            s0 = (u8 *)(s0 + 0x70);
        } while (v0 != 0);
        MGSetSpriteZPos(1);
        return;
    }
}


/* MGInitResultLoseTexAniFade2 @ 0x202DC0 .. 0x202E84 (0xc4 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1033 -> 0x24fb50
 *   stack: address of the slot at 0x20 escapes at 0x202de8
 *   stack: address of the slot at 0x20 escapes at 0x202e28
 *   literal: @1033 initializes the 108-byte local at 0x20
 *   cfg: loop body is not one contiguous region: .L00202E28
 */



void MGInitResultLoseTexAniFade2(void) {
    s32 a3;
    u8 *s0;
    u8 *a2;
    u32 v0;

    v0 = GetSpriteDraw();
    s0 = (u8 *)v0;
    GetWinFlag();
    {
        struct stackFrame_20 { u8 b[108]; } stackFrame_20 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x01, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        a3 = 0;
        a2 = ((u8 *)&stackFrame_20);
        do {
            v0 = *(u8 *)a2;
            *(u8 *)(s0 + 2) = v0;
            v0 = *(u8 *)(s0 + 2);
            if (v0 == (u32)3) {
                v0 = *(s32 *)(s0 + 0x3c);
                *(u32 *)(s0 + 0x4c) = v0;
            } else if (v0 == (u32)2) {
                *(u32 *)(s0 + 0x4c) = 0;
            }
            a3 = a3 + 1;
            v0 = a3 < (s32)0x6c;
            a2 = (u8 *)(a2 + 1);
            s0 = (u8 *)(s0 + 0x70);
        } while (v0 != 0);
        MGSetSpriteZPos(1);
        return;
    }
}


/* MGInit2PModeResultWinTexAniFade @ 0x202CF0 .. 0x202DB4 (0xc4 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1051 -> 0x24fbc0
 *   stack: address of the slot at 0x20 escapes at 0x202d18
 *   stack: address of the slot at 0x20 escapes at 0x202d58
 *   literal: @1051 initializes the 108-byte local at 0x20
 *   cfg: loop body is not one contiguous region: .L00202D58
 */



void MGInit2PModeResultWinTexAniFade(void) {
    s32 a3;
    u8 *s0;
    u8 *a2;
    u32 v0;

    v0 = GetSpriteDraw();
    s0 = (u8 *)v0;
    GetWinFlag();
    {
        struct stackFrame_20 { u8 b[108]; } stackFrame_20 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        a3 = 0;
        a2 = ((u8 *)&stackFrame_20);
        do {
            v0 = *(u8 *)a2;
            *(u8 *)(s0 + 2) = v0;
            v0 = *(u8 *)(s0 + 2);
            if (v0 == (u32)3) {
                v0 = *(s32 *)(s0 + 0x3c);
                *(u32 *)(s0 + 0x4c) = v0;
            } else if (v0 == (u32)2) {
                *(u32 *)(s0 + 0x4c) = 0;
            }
            a3 = a3 + 1;
            v0 = a3 < (s32)0x6c;
            a2 = (u8 *)(a2 + 1);
            s0 = (u8 *)(s0 + 0x70);
        } while (v0 != 0);
        MGSetSpriteZPos(1);
        return;
    }
}


/* MGInit2PModeResultLoseTexAniFade @ 0x202C20 .. 0x202CE4 (0xc4 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1069 -> 0x24fc30
 *   stack: address of the slot at 0x20 escapes at 0x202c48
 *   stack: address of the slot at 0x20 escapes at 0x202c88
 *   literal: @1069 initializes the 108-byte local at 0x20
 *   cfg: loop body is not one contiguous region: .L00202C88
 */



void MGInit2PModeResultLoseTexAniFade(void) {
    s32 a3;
    u8 *s0;
    u8 *a2;
    u32 v0;

    v0 = GetSpriteDraw();
    s0 = (u8 *)v0;
    GetWinFlag();
    {
        struct stackFrame_20 { u8 b[108]; } stackFrame_20 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x02,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        a3 = 0;
        a2 = ((u8 *)&stackFrame_20);
        do {
            v0 = *(u8 *)a2;
            *(u8 *)(s0 + 2) = v0;
            v0 = *(u8 *)(s0 + 2);
            if (v0 == (u32)3) {
                v0 = *(s32 *)(s0 + 0x3c);
                *(u32 *)(s0 + 0x4c) = v0;
            } else if (v0 == (u32)2) {
                *(u32 *)(s0 + 0x4c) = 0;
            }
            a3 = a3 + 1;
            v0 = a3 < (s32)0x6c;
            a2 = (u8 *)(a2 + 1);
            s0 = (u8 *)(s0 + 0x70);
        } while (v0 != 0);
        MGSetSpriteZPos(1);
        return;
    }
}


/* MGInit2PModeResultWinTexAniFade2 @ 0x202B50 .. 0x202C14 (0xc4 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1087 -> 0x24fca0
 *   stack: address of the slot at 0x20 escapes at 0x202b78
 *   stack: address of the slot at 0x20 escapes at 0x202bb8
 *   literal: @1087 initializes the 108-byte local at 0x20
 *   cfg: loop body is not one contiguous region: .L00202BB8
 */



void MGInit2PModeResultWinTexAniFade2(void) {
    s32 a3;
    u8 *s0;
    u8 *a2;
    u32 v0;

    v0 = GetSpriteDraw();
    s0 = (u8 *)v0;
    GetWinFlag();
    {
        struct stackFrame_20 { u8 b[108]; } stackFrame_20 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        a3 = 0;
        a2 = ((u8 *)&stackFrame_20);
        do {
            v0 = *(u8 *)a2;
            *(u8 *)(s0 + 2) = v0;
            v0 = *(u8 *)(s0 + 2);
            if (v0 == (u32)3) {
                v0 = *(s32 *)(s0 + 0x3c);
                *(u32 *)(s0 + 0x4c) = v0;
            } else if (v0 == (u32)2) {
                *(u32 *)(s0 + 0x4c) = 0;
            }
            a3 = a3 + 1;
            v0 = a3 < (s32)0x6c;
            a2 = (u8 *)(a2 + 1);
            s0 = (u8 *)(s0 + 0x70);
        } while (v0 != 0);
        MGSetSpriteZPos(1);
        return;
    }
}


/* MGInit2PModeResultLoseTexAniFade2 @ 0x202A80 .. 0x202B44 (0xc4 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1105 -> 0x24fd10
 *   stack: address of the slot at 0x20 escapes at 0x202aa8
 *   stack: address of the slot at 0x20 escapes at 0x202ae8
 *   literal: @1105 initializes the 108-byte local at 0x20
 *   cfg: loop body is not one contiguous region: .L00202AE8
 */



void MGInit2PModeResultLoseTexAniFade2(void) {
    s32 a3;
    u8 *s0;
    u8 *a2;
    u32 v0;

    v0 = GetSpriteDraw();
    s0 = (u8 *)v0;
    GetWinFlag();
    {
        struct stackFrame_20 { u8 b[108]; } stackFrame_20 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        a3 = 0;
        a2 = ((u8 *)&stackFrame_20);
        do {
            v0 = *(u8 *)a2;
            *(u8 *)(s0 + 2) = v0;
            v0 = *(u8 *)(s0 + 2);
            if (v0 == (u32)3) {
                v0 = *(s32 *)(s0 + 0x3c);
                *(u32 *)(s0 + 0x4c) = v0;
            } else if (v0 == (u32)2) {
                *(u32 *)(s0 + 0x4c) = 0;
            }
            a3 = a3 + 1;
            v0 = a3 < (s32)0x6c;
            a2 = (u8 *)(a2 + 1);
            s0 = (u8 *)(s0 + 0x70);
        } while (v0 != 0);
        MGSetSpriteZPos(1);
        return;
    }
}


/* MGInitGoTitleFade @ 0x202960 .. 0x202A80 (0x120 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1122 -> 0x24fd80
 *   stack: address of the slot at 0x10 escapes at 0x202980
 *   stack: address of the slot at 0x10 escapes at 0x2029d8
 *   literal: @1122 initializes the 108-byte local at 0x10
 *   cfg: loop body is not one contiguous region: .L002029D8
 */

void MGInitGoTitleFade(void) {
    s32 t4;
    u8 *t3;
    s32 t2;
    s32 t1;
    s32 t0;
    u32 a3;
    u32 a2;
    s32 a1;
    s32 a0;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x03,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        t4 = 0;
        t3 = ((u8 *)&stackFrame_10);
        t1 = 1;
        t0 = 4;
        a3 = 3;
        a0 = 2;
        a1 = 0x7f;
        a2 = 5;
        t2 = 7;
        do {
            v1 = *(u8 *)t3;
            if (v1 == (u32)t2) {
                v1 = *(u8 *)(v0 + 2);
                if (v1 == (u32)t1 || v1 == (u32)t0) {
                    *(u8 *)t3 = a3;
                } else {
                    *(u8 *)t3 = 0;
                }
            }
            v1 = *(u8 *)t3;
            if (v1 != a2) {
                *(u8 *)(v0 + 2) = v1;
                v1 = *(u8 *)(v0 + 2);
                if (v1 == a3) {
                    v1 = *(s32 *)(v0 + 0x3c);
                    *(u32 *)(v0 + 0x4c) = v1;
                    v1 = *(s32 *)(v0 + 0x4c);
                    if ((s32)v1 > (s32)0x7f) {
                        *(u32 *)(v0 + 0x4c) = a1;
                    }
                } else if (v1 == (u32)a0) {
                    *(u32 *)(v0 + 0x4c) = 0;
                }
            }
            t4 = t4 + 1;
            v1 = t4 < (s32)0x6c;
            t3 = (u8 *)(t3 + 1);
            v0 = (u8 *)(v0 + 0x70);
        } while (v1 != 0);
        MGSetSpriteZPos(1);
        return;
    }
}


void MGInitSpriteForTopMenu(void);
void MGTopMenuChoise(unsigned int choice) {
    u32 sprites = GetSpriteDraw();
    MGInitSpriteForTopMenu();
    switch (choice) {
    case 0: {
        s32 fade[2] = {22,76};
        s32 selected[4] __attribute__((aligned(16))) = {24,26,78,80};
        s32 hide[2] = {28,82};
        u32 i;
        for (i=0;i<2;i++) {
            *(s32 *)(sprites + selected[i]*112 +4) = *(s32 *)(sprites + selected[i]*112 +20)-4;
            *(s32 *)(sprites + selected[i]*112 +8) = *(s32 *)(sprites + selected[i]*112 +24)-4;
            *(s32 *)(sprites + selected[i]*112 +12) = *(s32 *)(sprites + selected[i]*112 +28)+8;
            *(s32 *)(sprites + selected[i]*112 +16) = *(s32 *)(sprites + selected[i]*112 +32)+8;
            *(s32 *)(sprites + fade[i]*112 +60) = 128;
        }
        for (i=0;i<4;i++) {
            *(s32 *)(sprites + selected[i]*112 +4) = *(s32 *)(sprites + selected[i]*112 +20)-4;
            *(s32 *)(sprites + selected[i]*112 +8) = *(s32 *)(sprites + selected[i]*112 +24)-4;
            *(s32 *)(sprites + selected[i]*112 +12) = *(s32 *)(sprites + selected[i]*112 +28)+8;
            *(s32 *)(sprites + selected[i]*112 +16) = *(s32 *)(sprites + selected[i]*112 +32)+8;
            *(s32 *)(sprites + selected[i]*112 +60) = 128;
            *(u8 *)(sprites + selected[i]*112 +2) = 4;
        }
        {
            u32 offset = (u32)hide[0] * 112;
            offset += sprites;
            *(u8 *)(offset + 2) = 0;
            offset = (u32)hide[1] * 112;
            offset += sprites;
            *(u8 *)(offset + 2) = 0;
        }
        break;
    }
    case 1: {
        s32 fade[2] = {21,75};
        s32 selected[4] __attribute__((aligned(16))) = {23,25,77,79};
        s32 hide[2] = {27,81};
        s32 *selectedPtr = selected;
        s32 *selectedCopy;
        s32 *fadePtr = fade;
        u32 i;
        i = 0;
        selectedCopy = selected;
        for (;i<2;i++) {
            *(s32 *)(sprites + *selectedCopy*112 +4) = *(s32 *)(sprites + *selectedCopy*112 +20)-4;
            *(s32 *)(sprites + *selectedCopy*112 +8) = *(s32 *)(sprites + *selectedCopy*112 +24)-4;
            *(s32 *)(sprites + *selectedCopy*112 +12) = *(s32 *)(sprites + *selectedCopy*112 +28)+8;
            *(s32 *)(sprites + *selectedCopy*112 +16) = *(s32 *)(sprites + *selectedCopy*112 +32)+8;
            selectedCopy++;
            *(s32 *)(sprites + *fadePtr++*112 +60) = 128;
        }
        for (i=0;i<4;i++) {
            *(s32 *)(sprites + *selectedPtr*112 +4) = *(s32 *)(sprites + *selectedPtr*112 +20)-4;
            *(s32 *)(sprites + *selectedPtr*112 +8) = *(s32 *)(sprites + *selectedPtr*112 +24)-4;
            *(s32 *)(sprites + *selectedPtr*112 +12) = *(s32 *)(sprites + *selectedPtr*112 +28)+8;
            *(s32 *)(sprites + *selectedPtr*112 +16) = *(s32 *)(sprites + *selectedPtr*112 +32)+8;
            *(s32 *)(sprites + *selectedPtr*112 +60) = 128;
            *(u8 *)(sprites + *selectedPtr++*112 +2) = 4;
        }
        {
            u32 offset = (u32)hide[0] * 112;
            offset += sprites;
            *(u8 *)(offset + 2) = 0;
            offset = (u32)hide[1] * 112;
            offset += sprites;
            *(u8 *)(offset + 2) = 0;
        }
        break;
    }
    }
}



void MGInitSpriteForTMKMenu(void);
void MGTMKMenuChoise(unsigned int mode) {
    u32 sprites = GetSpriteDraw();
    MGInitSpriteForTMKMenu();
    switch (mode) {
    case 0: {
        s32 fade[3] __attribute__((aligned(8))) = {34,35,90};
        s32 selected[6] __attribute__((aligned(16))) = {40,41,46,47,93,96};
        s32 hide[3] __attribute__((aligned(8))) = {52,53,99};
        u32 i;
        for (i=0;i<3;i++) {
            *(s32 *)(sprites + selected[i]*112 +4) = *(s32 *)(sprites + selected[i]*112 +20)-4;
            *(s32 *)(sprites + selected[i]*112 +8) = *(s32 *)(sprites + selected[i]*112 +24)-4;
            *(s32 *)(sprites + selected[i]*112 +12) = *(s32 *)(sprites + selected[i]*112 +28)+8;
            *(s32 *)(sprites + selected[i]*112 +16) = *(s32 *)(sprites + selected[i]*112 +32)+8;
            *(s32 *)(sprites + fade[i]*112 +60) = 128;
        }
        for (i=0;i<6;i++) {
            *(s32 *)(sprites + selected[i]*112 +4) = *(s32 *)(sprites + selected[i]*112 +20)-4;
            *(s32 *)(sprites + selected[i]*112 +8) = *(s32 *)(sprites + selected[i]*112 +24)-4;
            *(s32 *)(sprites + selected[i]*112 +12) = *(s32 *)(sprites + selected[i]*112 +28)+8;
            *(s32 *)(sprites + selected[i]*112 +16) = *(s32 *)(sprites + selected[i]*112 +32)+8;
            *(s32 *)(sprites + selected[i]*112 +60) = 128;
            *(u8 *)(sprites + selected[i]*112 +2) = 4;
        }
        {
            u32 offset;
            offset = (u32)hide[0] * 112;
            offset += sprites;
            *(u8 *)(offset + 2) = 0;
            offset = (u32)hide[1] * 112;
            offset += sprites;
            *(u8 *)(offset + 2) = 0;
            offset = (u32)hide[2] * 112;
            offset += sprites;
            *(u8 *)(offset + 2) = 0;
        }
        break;
    }
    case 2: {
        s32 fade[3] __attribute__((aligned(8))) = {32,33,89};
        s32 selected[6] __attribute__((aligned(16))) = {38,39,44,45,92,95};
        s32 hide[3] __attribute__((aligned(8))) = {50,51,98};
        s32 *selectedPtr = selected;
        s32 *selectedCopy;
        s32 *fadePtr = fade;
        u32 i;
        i = 0;
        selectedCopy = selected;
        for (;i<3;i++) {
            *(s32 *)(sprites + *selectedCopy*112 +4) = *(s32 *)(sprites + *selectedCopy*112 +20)-4;
            *(s32 *)(sprites + *selectedCopy*112 +8) = *(s32 *)(sprites + *selectedCopy*112 +24)-4;
            *(s32 *)(sprites + *selectedCopy*112 +12) = *(s32 *)(sprites + *selectedCopy*112 +28)+8;
            *(s32 *)(sprites + *selectedCopy*112 +16) = *(s32 *)(sprites + *selectedCopy*112 +32)+8;
            selectedCopy++;
            *(s32 *)(sprites + *fadePtr++*112 +60) = 128;
        }
        for (i=0;i<6;i++) {
            *(s32 *)(sprites + *selectedPtr*112 +4) = *(s32 *)(sprites + *selectedPtr*112 +20)-4;
            *(s32 *)(sprites + *selectedPtr*112 +8) = *(s32 *)(sprites + *selectedPtr*112 +24)-4;
            *(s32 *)(sprites + *selectedPtr*112 +12) = *(s32 *)(sprites + *selectedPtr*112 +28)+8;
            *(s32 *)(sprites + *selectedPtr*112 +16) = *(s32 *)(sprites + *selectedPtr*112 +32)+8;
            *(s32 *)(sprites + *selectedPtr*112 +60) = 128;
            *(u8 *)(sprites + *selectedPtr++*112 +2) = 4;
        }
        {
            u32 offset;
            offset = (u32)hide[0] * 112;
            offset += sprites;
            *(u8 *)(offset + 2) = 0;
            offset = (u32)hide[1] * 112;
            offset += sprites;
            *(u8 *)(offset + 2) = 0;
            offset = (u32)hide[2] * 112;
            offset += sprites;
            *(u8 *)(offset + 2) = 0;
        }
        break;
    }
    case 1: {
        s32 fade[3] __attribute__((aligned(8))) = {36,37,91};
        s32 selected[6] __attribute__((aligned(16))) = {42,43,48,49,94,97};
        s32 hide[3] __attribute__((aligned(8))) = {54,55,100};
        s32 *selectedPtr = selected;
        s32 *selectedCopy;
        s32 *fadePtr = fade;
        u32 i;
        i = 0;
        selectedCopy = selected;
        for (;i<3;i++) {
            *(s32 *)(sprites + *selectedCopy*112 +4) = *(s32 *)(sprites + *selectedCopy*112 +20)-4;
            *(s32 *)(sprites + *selectedCopy*112 +8) = *(s32 *)(sprites + *selectedCopy*112 +24)-4;
            *(s32 *)(sprites + *selectedCopy*112 +12) = *(s32 *)(sprites + *selectedCopy*112 +28)+8;
            *(s32 *)(sprites + *selectedCopy*112 +16) = *(s32 *)(sprites + *selectedCopy*112 +32)+8;
            selectedCopy++;
            *(s32 *)(sprites + *fadePtr++*112 +60) = 128;
        }
        for (i=0;i<6;i++) {
            *(s32 *)(sprites + *selectedPtr*112 +4) = *(s32 *)(sprites + *selectedPtr*112 +20)-4;
            *(s32 *)(sprites + *selectedPtr*112 +8) = *(s32 *)(sprites + *selectedPtr*112 +24)-4;
            *(s32 *)(sprites + *selectedPtr*112 +12) = *(s32 *)(sprites + *selectedPtr*112 +28)+8;
            *(s32 *)(sprites + *selectedPtr*112 +16) = *(s32 *)(sprites + *selectedPtr*112 +32)+8;
            *(s32 *)(sprites + *selectedPtr*112 +60) = 128;
            *(u8 *)(sprites + *selectedPtr++*112 +2) = 4;
        }
        {
            u32 offset;
            offset = (u32)hide[0] * 112;
            offset += sprites;
            *(u8 *)(offset + 2) = 0;
            offset = (u32)hide[1] * 112;
            offset += sprites;
            *(u8 *)(offset + 2) = 0;
            offset = (u32)hide[2] * 112;
            offset += sprites;
            *(u8 *)(offset + 2) = 0;
        }
        break;
    }
    }
}








/* MGInitSpriteForTopMenu @ 0x201C60 .. 0x201E68 (0x208 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   quad: a3: 128-bit web split from its scalar uses
 *   quad: t1: 128-bit web split from its scalar uses
 *   quad: a2: 128-bit web split from its scalar uses
 *   literal: @1324 -> 0x24fed0
 *   literal: @1326 -> 0x24fef0
 *   stack: address of the slot at 0x30 escapes at 0x201cb8
 *   stack: address of the slot at 0x10 escapes at 0x201cb8
 *   stack: address of the slot at 0x30 escapes at 0x201cb8
 *   stack: address of the slot at 0x10 escapes at 0x201d70
 *   literal: @1326 initializes the 32-byte local at 0x10
 *   literal: @1324 initializes the 32-byte local at 0x30
 */

void MGInitSpriteForTopMenu(void) {
    s32 t2;
    u32 t1;
    u32 t0;
    u32 a2;
    u8 *a1;
    u32 a0;
    u32 v1;
    u32 v0;

    v0 = GetSpriteDraw();
    {
        struct stackFrame_30 { u8 b[32]; } stackFrame_30 __attribute__((aligned(16))) = {{0x15,
            0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00,
            0x00, 0x4b, 0x00, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x51, 0x00, 0x00, 0x00, 0x52,
            0x00, 0x00, 0x00}};
        a1 = ((u8 *)&stackFrame_30);
        {
            struct stackFrame_10 { u8 b[32]; } stackFrame_10 __attribute__((aligned(16))) = {{0x17,
                0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x00,
                0x00, 0x4d, 0x00, 0x00, 0x00, 0x4e, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x00, 0x50,
                0x00, 0x00, 0x00}};
            a0 = 0;
            v1 = (u32)((u8 *)&stackFrame_30);
            t2 = 1;
            t1 = 0x40;
            do {
                a0 = a0 + 1;
                a2 = a0 < (u32)8;
                t0 = v0 + (s32)((u32)*(s32 *)v1 * (u32)(0x70));
                *(u32 *)((t0 + 4)) = *(s32 *)((t0 + 0x14));
                t0 = v0 + (s32)((u32)*(s32 *)v1 * (u32)(0x70));
                *(u32 *)((t0 + 8)) = *(s32 *)((t0 + 0x18));
                t0 = v0 + (s32)((u32)*(s32 *)v1 * (u32)(0x70));
                *(u32 *)((t0 + 0xc)) = *(s32 *)((t0 + 0x1c));
                t0 = v0 + (s32)((u32)*(s32 *)v1 * (u32)(0x70));
                *(u32 *)((t0 + 0x10)) = *(s32 *)((t0 + 0x20));
                *(u8 *)(((u32)(v0 + (s32)((u32)*(s32 *)v1 * (u32)(0x70))) + 2)) = t2;
                t0 = *(s32 *)v1;
                *(u32 *)(((u32)(v0 + (s32)(t0 * (u32)(0x70))) + 0x3c)) = t1;
                v1 = v1 + 4;
            } while (a2 != 0);
            v1 = 0;
            a0 = (u32)((u8 *)&stackFrame_10);
            do {
                *(u32 *)(((u32)(v0 + (s32)((u32)((u32)*(s32 *)a0 * (u32)(7)) << 4)) + 4)) = *(s32
                    *)(((s32)(v0 + (s32)((u32)((u32)*(s32 *)a1 * (u32)(7)) << 4)) + 0x14));
                *(u32 *)(((u32)(v0 + (s32)((u32)((u32)*(s32 *)a0 * (u32)(7)) << 4)) + 8)) = *(s32
                    *)(((s32)(v0 + (s32)((u32)((u32)*(s32 *)a1 * (u32)(7)) << 4)) + 0x18));
                *(u32 *)(((u32)(v0 + (s32)((u32)((u32)*(s32 *)a0 * (u32)(7)) << 4)) + 0xc)) = *(s32
                    *)(((s32)(v0 + (s32)((u32)((u32)*(s32 *)a1 * (u32)(7)) << 4)) + 0x1c));
                *(u32 *)(((u32)(v0 + (s32)((u32)((u32)*(s32 *)a0 * (u32)(7)) << 4)) + 0x10)) =
                    *(s32 *)(((s32)(v0 + (s32)((u32)((u32)*(s32 *)a1 * (u32)(7)) << 4)) + 0x20));
                a1 = (u8 *)(a1 + 4);
                t0 = *(s32 *)a0;
                a0 = a0 + 4;
                *(u8 *)(((u32)(v0 + (s32)(t0 * (u32)(0x70))) + 2)) = 0;
                v1 = v1 + 1;
                a2 = v1 < (u32)8;
            } while (a2 != 0);
            return;
        }
    }
}

/* MGInitSpriteForTMKMenu @ 0x201A20 .. 0x201C58 (0x238 bytes, frame 0xb0) */
/*
 * dcomp notes:
 *   quad: a3: 128-bit web split from its scalar uses
 *   quad: t1: 128-bit web split from its scalar uses
 *   quad: t0: 128-bit web split from its scalar uses
 *   quad: a2: 128-bit web split from its scalar uses
 *   literal: @1362 -> 0x24ff10
 *   literal: @1364 -> 0x24ff60
 *   stack: address of the slot at 0x60 escapes at 0x201aa8
 *   stack: address of the slot at 0x60 escapes at 0x201aa8
 *   stack: address of the slot at 0x10 escapes at 0x201b60
 *   literal: @1364 initializes the 72-byte local at 0x10
 *   literal: @1362 initializes the 72-byte local at 0x60
 */

void MGInitSpriteForTMKMenu(void) {
    u32 v0;
    u8 *a1;
    u8 *t2;
    u32 a0;
    u32 v1;
    u32 t1;
    s32 a2;
    u32 t0;

    v0 = GetSpriteDraw();
    {
        struct stackFrame_60 { u8 b[72]; } stackFrame_60 __attribute__((aligned(16))) = {{0x20,
            0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00,
            0x00, 0x24, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x33,
            0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00,
            0x00, 0x37, 0x00, 0x00, 0x00, 0x59, 0x00, 0x00, 0x00, 0x5a, 0x00, 0x00, 0x00, 0x5b,
            0x00, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x63, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00,
            0x00}};
        a1 = ((u8 *)&stackFrame_60);
        {
            struct stackFrame_10 { u8 b[72]; } stackFrame_10 __attribute__((aligned(16))) = {{0x26,
                0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x29, 0x00, 0x00,
                0x00, 0x2a, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x2d,
                0x00, 0x00, 0x00, 0x2e, 0x00, 0x00, 0x00, 0x2f, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00,
                0x00, 0x31, 0x00, 0x00, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x5d, 0x00, 0x00, 0x00, 0x5e,
                0x00, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x61, 0x00, 0x00,
                0x00}};
            t2 = ((u8 *)&stackFrame_10);
            a0 = 0;
            v1 = (u32)((u8 *)&stackFrame_60);
            t2 = (u8 *)(s32)1;
            t1 = 0x40;
            do {
                a0 = a0 + 1;
                a2 = a0 < (u32)0x12;
                t0 = v0 + (s32)((u32)*(s32 *)v1 * (u32)(0x70));
                *(u32 *)((t0 + 4)) = *(s32 *)((t0 + 0x14));
                t0 = v0 + (s32)((u32)*(s32 *)v1 * (u32)(0x70));
                *(u32 *)((t0 + 8)) = *(s32 *)((t0 + 0x18));
                t0 = v0 + (s32)((u32)*(s32 *)v1 * (u32)(0x70));
                *(u32 *)((t0 + 0xc)) = *(s32 *)((t0 + 0x1c));
                t0 = v0 + (s32)((u32)*(s32 *)v1 * (u32)(0x70));
                *(u32 *)((t0 + 0x10)) = *(s32 *)((t0 + 0x20));
                *(u8 *)(((u32)(v0 + (s32)((u32)*(s32 *)v1 * (u32)(0x70))) + 2)) = (s32)t2;
                t0 = *(s32 *)v1;
                *(u32 *)(((u32)(v0 + (s32)(t0 * (u32)(0x70))) + 0x3c)) = t1;
                v1 = v1 + 4;
            } while ((u32)a2 != 0);
            v1 = 0;
            a0 = (u32)((u8 *)&stackFrame_10);
            do {
                *(u32 *)(((u32)(v0 + (s32)((u32)((u32)*(s32 *)a0 * (u32)(7)) << 4)) + 4)) = *(s32
                    *)(((s32)(v0 + (s32)((u32)((u32)*(s32 *)a1 * (u32)(7)) << 4)) + 0x14));
                *(u32 *)(((u32)(v0 + (s32)((u32)((u32)*(s32 *)a0 * (u32)(7)) << 4)) + 8)) = *(s32
                    *)(((s32)(v0 + (s32)((u32)((u32)*(s32 *)a1 * (u32)(7)) << 4)) + 0x18));
                *(u32 *)(((u32)(v0 + (s32)((u32)((u32)*(s32 *)a0 * (u32)(7)) << 4)) + 0xc)) = *(s32
                    *)(((s32)(v0 + (s32)((u32)((u32)*(s32 *)a1 * (u32)(7)) << 4)) + 0x1c));
                *(u32 *)(((u32)(v0 + (s32)((u32)((u32)*(s32 *)a0 * (u32)(7)) << 4)) + 0x10)) =
                    *(s32 *)(((s32)(v0 + (s32)((u32)((u32)*(s32 *)a1 * (u32)(7)) << 4)) + 0x20));
                a1 = (u8 *)(a1 + 4);
                t0 = *(s32 *)a0;
                a0 = a0 + 4;
                *(u8 *)(((u32)(v0 + (s32)(t0 * (u32)(0x70))) + 2)) = 0;
                v1 = v1 + 1;
                a2 = v1 < (u32)0x12;
            } while ((u32)a2 != 0);
            return;
        }
    }
}
/* MGInitReturnSGHMenuFade @ 0x201900 .. 0x201A20 (0x120 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1381 -> 0x24ffb0
 *   stack: address of the slot at 0x10 escapes at 0x201920
 *   stack: address of the slot at 0x10 escapes at 0x201978
 *   literal: @1381 initializes the 108-byte local at 0x10
 *   cfg: loop body is not one contiguous region: .L00201978
 */


void MGInitReturnSGHMenuFade(void) {
    s32 t4;
    u8 *t3;
    s32 t2;
    s32 t1;
    s32 t0;
    u32 a3;
    u32 a2;
    s32 a1;
    u32 a0;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)GetSpriteDraw();
    {
        struct stackFrame_10 { u8 b[108]; } stackFrame_10 __attribute__((aligned(16))) = {{0x00,
            0x02, 0x03, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00,
            0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x02,
            0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02,
            0x02, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x02,
            0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        t4 = 0;
        t3 = ((u8 *)&stackFrame_10);
        t1 = 1;
        t0 = 4;
        a3 = 3;
        a0 = 2;
        a1 = 0x7f;
        a2 = 5;
        t2 = 7;
        do {
            v1 = *(u8 *)t3;
            if (v1 == (u32)t2) {
                v1 = *(u8 *)(v0 + 2);
                if (v1 == (u32)t1 || v1 == (u32)t0) {
                    *(u8 *)t3 = a3;
                } else {
                    *(u8 *)t3 = 0;
                }
            }
            v1 = *(u8 *)t3;
            if (v1 != a2) {
                *(u8 *)(v0 + 2) = v1;
                v1 = *(u8 *)(v0 + 2);
                if (v1 == a3) {
                    v1 = *(s32 *)(v0 + 0x3c);
                    *(u32 *)(v0 + 0x4c) = v1;
                    v1 = *(s32 *)(v0 + 0x4c);
                    if ((s32)v1 > (s32)0x7f) {
                        *(u32 *)(v0 + 0x4c) = a1;
                    }
                } else if (v1 == a0) {
                    *(u32 *)(v0 + 0x4c) = 0;
                }
            }
            t4 = t4 + 1;
            v1 = t4 < (s32)0x6c;
            t3 = (u8 *)(t3 + 1);
            v0 = (u8 *)(v0 + 0x70);
        } while (v1 != 0);
        MGSetSpriteZPos(0);
        return;
    }
}

