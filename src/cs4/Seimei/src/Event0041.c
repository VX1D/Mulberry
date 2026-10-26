#include "common.h"

/* PlayS0041Event000 @ 0x212410 .. 0x2124EC (0xdc bytes, frame 0x50) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @671 -> 0x2503a0
 *   literal: @676 -> 0x2503b0
 *   fpu: float literal 0x00000000 at 0x212484
 *   fpu: float literal 0x00000000 at 0x2124ac
 *   stack: address of the slot at 0x30 escapes at 0x2124b8
 *   literal: @676 initializes the 16-byte local at 0x30
 *   literal: @671 initializes the 16-byte local at 0x40
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int CheckSquareRange(float *, float *);
extern signed int CheckMyControlOff(void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void FreeMdlMng(void *);
extern void SetMyFall(void *, float, float *);
extern void SetEventFlag(signed int);
extern void ResetEventFlag(signed int);
extern u32 MdlMng[];

/* InitS0041Event000 @ 0x2124F0 .. 0x2125EC (0xfc bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x212594
 *   cfg: kept branch: 0x21257c if (..) goto .L002125B8
 *   cfg: kept goto: 0x212590 -> .L002125D8
 *   v0#11 is the pointer held in a0+0x3c
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern signed int CheckEventFlag(signed int);

extern void SetAnimLastFrame(void *);


extern u8 GameSt[];

/* SetEventFuncS0041 @ 0x2125F0 .. 0x212614 (0x24 bytes) */
/*
 * dcomp notes:
 *   repo declaration vs inferred signature: return void vs inferred u8 *
 */


extern u32 EventMngSt[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetEventFuncS0041(void);
static void InitS0041Event000(void *a0 );
static void PlayS0041Event000(void *a0 );



void SetEventFuncS0041(void) {
    u8 *v1;

    v1 = (u8 *)InitS0041Event000;
    *(u32 *)EventMngSt = (u32)InitS0041Event000;
    v1 = (u8 *)PlayS0041Event000;
    *(u32 *)((u8 *)&EventMngSt + 4) = (u32)PlayS0041Event000;
    return;
}

static void InitS0041Event000(void *a0 /* r4 */) {
    u8 *s1;
    s32 a1;
    u8 *s0;
    u32 v0;
    u32 v1;

    a1 = 8;
    s1 = (u8 *)a0;
    a0 = (void *)(s32)1;
    s0 = (u8 *)MdlMng + 0x5400;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
    a0 = (void *)(s32)1;
    v0 = (u32)(v0) * (u32)(7);
    a1 = 7;
    v0 = v0 << 6;
    v0 = (s32)(s0 + v0);
    *(u32 *)(s1 + 0x34) = v0;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
    a0 = (void *)(s32)1;
    v0 = (u32)(v0) * (u32)(7);
    a1 = 9;
    v0 = v0 << 6;
    v0 = (s32)(s0 + v0);
    *(u32 *)(s1 + 0x38) = v0;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
    v1 = v0 << 3;
    v0 = (u32)(v0) * (u32)(7);
    v0 = v0 << 6;
    v0 = (s32)(s0 + v0);
    *(u32 *)(s1 + 0x3c) = v0;
    v0 = GameSt[0x14];
    a0 = (void *)(s32)0x548;
    if (v0 == 0) {
        v0 = CheckEventFlag((signed int)a0);
        if (v0 == 0) {
            goto _L002125B8;
        }
    }
    a0 = (void *)*(s32 *)(s1 + 0x34);
    a1 = 1;
    ChangeAnimParam(a0, a1, 0.0f);
    a0 = (void *)*(s32 *)(s1 + 0x34);
    SetAnimLastFrame(a0);
    a0 = (void *)*(s32 *)(s1 + 0x38);
    FreeMdlMng(a0);
    *(u32 *)(s1 + 0xc) = 0;
    goto _L002125D8;
    _L002125B8:;
    v1 = *(s32 *)(s1 + 0x34);
    a1 = 1;
    a0 = (void *)0x41200000;
    *(u8 *)((v1 + 2)) = a1;
    v1 = *(s32 *)(s1 + 0x3c);
    *(u32 *)((v1 + 0x24)) = 0x41200000;
    *(u32 *)(s1 + 0xc) = a1;
    _L002125D8:;
    return;
}

static void PlayS0041Event000(void *a0 /* r4 */) {
    u8 *s1;
    u32 v1;
    u8 *s0;
    u32 v0;
    u32 a1;
    float f12;

    v1 = 1;
    s1 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    s0 = (u8 *)MdlMng + 0x11800;
    switch ((u32)(s32)a0) {
    case 1:
        v0 = 0x2503a0;
        a0 = (void *)(s0 + 0x20);
        {
            struct stackFrame_40 { u8 b[16]; } stackFrame_40 __attribute__((aligned(16))) = {{0x9a,
                0x99, 0xcd, 0xc1, 0x33, 0x33, 0x2b, 0xc2, 0xcd, 0xcc, 0xbc, 0xc1, 0x66, 0x66, 0x26,
                0xc2}};
            a1 = (u32)((u8 *)&stackFrame_40);
            v0 = CheckSquareRange((float *)a0, (float *)a1);
            a0 = (void *)s0;
            if (v0 == 0) {
                break;
            }
            v0 = CheckMyControlOff(a0);
            if (v0 == 0) {
                break;
            }
            v0 = 0x2503b0;
            f12 = 0.0f;
            {
                struct stackFrame_30 { u8 b[16]; } stackFrame_30 __attribute__((aligned(16))) =
                    {{0xd7, 0xa3, 0xc4, 0xc1, 0xfe, 0xd4, 0xf8, 0xbe, 0xbc, 0xf4, 0x29, 0xc2, 0x00,
                    0x00, 0x80, 0x3f}};
                v1 = (u32)((u8 *)&stackFrame_30);
                v0 = *(s32 *)(s1 + 0x34);
                *(u8 *)((v0 + 2)) = 0;
                a0 = (void *)*(s32 *)(s1 + 0x34);
                a1 = 1;
                ChangeAnimParam(a0, a1, 0.0f);
                a0 = (void *)*(s32 *)(s1 + 0x38);
                FreeMdlMng(a0);
                v0 = *(s32 *)(s1 + 0x3c);
                f12 = 0.0f;
                a0 = (void *)s0;
                a1 = (u32)((u8 *)&stackFrame_30);
                *(u32 *)((v0 + 0x24)) = 0;
                SetMyFall(a0, 0.0f, (float *)a1);
                a0 = (void *)(s32)0x548;
                SetEventFlag((signed int)a0);
                a0 = (void *)(s32)0x532;
                ResetEventFlag((signed int)a0);
                *(u32 *)(s1 + 0xc) = 2;
            }
        }
    }
    return;
}
