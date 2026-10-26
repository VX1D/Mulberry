#include "common.h"





extern void SetCamCtrlMode(unsigned int);
extern void SetCameraPos(float *);
extern void SetCameraAng(float *);
extern signed int KnMsgMng_SendMsg(signed int);
extern signed int CheckEventFlag(signed int);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern void FreeMdlMng(void *);
extern void SetMyControlOff();
extern unsigned int CheckAnimEndFrame(void *);
extern void SetEventFlag(signed int);
extern void ResetEventFlag(signed int);
extern void SetMyControlOn();
extern u32 KnMsgMng_CheckMsgNone();
extern u32 MdlMng[];
extern u8 GameSt[];
extern u32 EventMngSt[];
static void ActiS0032Event000(void *a0 /* r4 */, unsigned int a1 /* r5 */);
static void PlayS0032Event000(void *a0 /* r4 */);
static void InitS0032Event000(void *a0 /* r4 */);
void SetEventFuncS0032(void);

/* SetEventFuncS0032 @ 0x215550 .. 0x215584 (0x34 bytes) */
/*
 * dcomp notes:
 *   repo declaration vs inferred signature: return void vs inferred u8 *
 */




void SetEventFuncS0032(void) {
    u8 *v1;

    v1 = (u8 *)InitS0032Event000;
    *(u32 *)EventMngSt = (u32)InitS0032Event000;
    v1 = (u8 *)PlayS0032Event000;
    *(u32 *)((u8 *)&EventMngSt + 4) = (u32)PlayS0032Event000;
    v1 = (u8 *)ActiS0032Event000;
    *(u32 *)((u8 *)&EventMngSt + 8) = (u32)ActiS0032Event000;
    return;
}
















/* InitS0032Event000 @ 0x215460 .. 0x215550 (0xf0 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x215484 if (..) goto .L00215500
 *   cfg: kept goto: 0x215490 -> .L00215540
 *   v1#15 is the pointer held in a0+0x34
 *   declaration vs inferred signature: return void vs inferred u32
 */


static void InitS0032Event000(void *a0 /* r4 */) {
    u32 v0;
    u32 v1;
    u32 *s0;
    s32 a1;

    v0 = 1;
    v1 = *(u8 *)((u8 *)&GameSt + 0x14);
    s0 = (u32 *)a0;
    if (v1 == v0) {
        a0 = (void *)(s32)0x6ce;
        v0 = CheckEventFlag((signed int)a0);
        if (v0 == 0) {
            goto _L00215500;
        }
    }
    a0 = (void *)(s32)1;
    a1 = 0x11;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
    a0 = (void *)(s32)(v0 + 0x30);
    v1 = (u32)a0 << 3;
    v1 = (s32)((u8 *)v1 - (u32)(a0));
    v0 = (u32)MdlMng;
    v1 = v1 << 6;
    a0 = (void *)(s32)((u8 *)MdlMng + v1);
    FreeMdlMng(a0);
    a0 = (void *)(s32)1;
    a1 = 0x12;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
    a0 = (void *)(s32)(v0 + 0x30);
    v1 = (u32)a0 << 3;
    v1 = (s32)((u8 *)v1 - (u32)(a0));
    v0 = (u32)MdlMng;
    v1 = v1 << 6;
    a0 = (void *)(s32)((u8 *)MdlMng + v1);
    FreeMdlMng(a0);
    v0 = 3;
    a0 = (void *)(s32)0x6ce;
    *(u32 *)(((u8 *)s0 + 0xc)) = v0;
    SetEventFlag((signed int)a0);
    goto _L00215540;
    _L00215500:;
    a0 = (void *)(s32)1;
    a1 = 0x12;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
    v1 = (u32)MdlMng;
    a0 = (void *)(s32)1;
    a1 = (u32)((u32)(v0 + 0x30)) * (u32)(0x1c0);
    v1 = (s32)((u8 *)MdlMng + a1);
    *(u32 *)(((u8 *)s0 + 0x34)) = v1;
    v1 = *(s32 *)(((u8 *)s0 + 0x34));
    *(u8 *)((v1 + 2)) = (s32)a0;
    *(u32 *)(((u8 *)s0 + 0xc)) = 0;
    _L00215540:;
    return;
}











/* PlayS0032Event000 @ 0x215300 .. 0x215460 (0x160 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @696 -> 0x250540
 *   literal: @698 -> 0x250550
 *   delay: addiu at 0x21531c writes a register its branch at 0x215318 reads
 *   fpu: float literal 0x00000000 at 0x21534c
 *   stack: address of the slot at 0x30 escapes at 0x2153a4
 *   stack: address of the slot at 0x20 escapes at 0x2153bc
 *   literal: @698 initializes the 16-byte local at 0x20
 *   literal: @696 initializes the 16-byte local at 0x30
 */


static void PlayS0032Event000(void *a0 /* r4 */) {
    u8 *s0;
    s32 a1;
    s32 v1;
    u32 v0;

    v1 = 2;
    s0 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    switch ((u32)(s32)a0) {
    case 0:
        a0 = (void *)(s32)0x6cf;
        v0 = CheckEventFlag((signed int)a0);
        a1 = 1;
        if (v0 == 0) {
            break;
        }
        *(u32 *)(s0 + 0xc) = a1;
        *(u8 *)((*(s32 *)(s0 + 0x34) + 2)) = 0;
        a0 = (void *)*(s32 *)(s0 + 0x34);
        ChangeAnimParam(a0, a1, 0.0f);
        a0 = (void *)(s32)1;
        a1 = 0x11;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        a0 = (void *)(s32)(v0 + 0x30);
        v1 = (s32)((u8 *)(s32)((u32)a0 << 3) - (u32)(a0));
        v0 = (u32)MdlMng;
        v1 = (u32)v1 << 6;
        a0 = (void *)((u8 *)MdlMng + v1);
        FreeMdlMng(a0);
        a0 = (void *)(s32)1;
        SetCamCtrlMode((unsigned int)a0);
        v0 = 0x250540;
        {
            struct stackFrame_30 { u8 b[16]; } stackFrame_30 __attribute__((aligned(16))) = {{0x33,
                0x33, 0xa7, 0x41, 0x66, 0x66, 0xe6, 0xbf, 0xcd, 0xcc, 0x14, 0xc1, 0x00, 0x00, 0x80,
                0x3f}};
            SetCameraPos((float *)((u8 *)&stackFrame_30));
            v0 = 0x250550;
            {
                struct stackFrame_20 { u8 b[16]; } stackFrame_20 __attribute__((aligned(16))) =
                    {{0xc7, 0x29, 0x7a, 0xbe, 0x8c, 0xb9, 0x4f, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00}};
                SetCameraAng((float *)((u8 *)&stackFrame_20));
                SetMyControlOff();
                break;
            }
        }
    case 1:
        a0 = (void *)*(s32 *)((*(s32 *)(s0 + 0x34) + 0x100));
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        a0 = (void *)*(s32 *)(s0 + 0x34);
        FreeMdlMng(a0);
        v0 = 3;
        *(u32 *)(s0 + 0xc) = v0;
        SetCamCtrlMode(0);
        a0 = (void *)(s32)0x6ce;
        SetEventFlag((signed int)a0);
        a0 = (void *)(s32)0x530;
        SetEventFlag((signed int)a0);
        a0 = (void *)(s32)0x65d;
        ResetEventFlag((signed int)a0);
        SetMyControlOn();
        break;
    case 2:
        v0 = KnMsgMng_CheckMsgNone();
        a0 = (void *)0;
        if (v0 == 0) {
            break;
        }
        SetCamCtrlMode(0);
        *(u32 *)(s0 + 0xc) = 0;
    }
    return;
}







/* ActiS0032Event000 @ 0x215280 .. 0x215300 (0x80 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @719 -> 0x250560
 *   literal: @721 -> 0x250570
 *   stack: address of the slot at 0x30 escapes at 0x2152bc
 *   stack: address of the slot at 0x20 escapes at 0x2152d4
 *   literal: @721 initializes the 16-byte local at 0x20
 *   literal: @719 initializes the 16-byte local at 0x30
 *   declaration vs inferred signature: return void vs inferred u32
 */


static void ActiS0032Event000(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u8 *s0;
    u32 v1;
    u32 v0;

    v1 = *(s32 *)(((u8 *)a0 + 0xc));
    s0 = (u8 *)a0;
    if (v1 == 0) {
        a0 = (void *)(s32)1;
        if ((u32)(s32)a1 == (u32)(s32)a0) {
            SetCamCtrlMode((unsigned int)a0);
            v0 = 0x250560;
            {
                struct stackFrame_30 { u8 b[16]; } stackFrame_30 __attribute__((aligned(16))) =
                    {{0x33, 0x33, 0xa7, 0x41, 0x66, 0x66, 0xe6, 0xbf, 0xcd, 0xcc, 0x14, 0xc1, 0x00,
                    0x00, 0x80, 0x3f}};
                a0 = (void *)((u8 *)&stackFrame_30);
                SetCameraPos((float *)a0);
                v0 = 0x250570;
                {
                    struct stackFrame_20 { u8 b[16]; } stackFrame_20 __attribute__((aligned(16))) =
                        {{0xc7, 0x29, 0x7a, 0xbe, 0x8c, 0xb9, 0x4f, 0x40, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00}};
                    a0 = (void *)((u8 *)&stackFrame_20);
                    SetCameraAng((float *)a0);
                    v0 = 0x60000;
                    KnMsgMng_SendMsg(0x60000 | 0x41d8);
                    *(u32 *)(s0 + 0xc) = 2;
                }
            }
        }
    }
    return;
}

