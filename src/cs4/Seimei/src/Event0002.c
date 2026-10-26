#include "common.h"

/* PlayS0002Event001 @ 0x213B50 .. 0x213C88 (0x138 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @740 -> 0x250450
 *   delay: addiu at 0x213ba0 writes a register its branch at 0x213b9c reads
 *   fpu: float literal 0x00000000 at 0x213bd8
 *   fpu: float literal 0x42700000 at 0x213c18
 *   fpu: float literal 0x3c888889 at 0x213c48
 *   literal: @740 initializes the 16-byte local at 0x20
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 GetCurCamID(void);
extern signed int CheckSquareRange(float *, float *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetEventFlag(signed int);
extern unsigned int CheckAnimEndFrame(void *);
extern void FreeMdlMng(void *);
extern u8 MdlMng[];

/* InitS0002Event001 @ 0x213C90 .. 0x213D8C (0xfc bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x213cbc if (..) goto .L00213D48
 *   cfg: kept goto: 0x213cf0 -> .L00213D78
 *   v1#6 is the pointer held in a0+0x38
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int CheckEventFlag(signed int);
extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern void FreeMdlMng(void *);
extern u8 MdlMng[];
extern u8 GameSt[];

/* ActiS0002Event000 @ 0x213D90 .. 0x213E64 (0xd4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x213de8
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void ResetEventFlag(signed int);
extern void SetEventFlag(signed int);
extern void SetMyActFreeFlag(unsigned char);
extern void SetMyControlOff(void);
extern signed int KnMsgMng_SendMsg(signed int);

/* PlayS0002Event000 @ 0x213E70 .. 0x213F6C (0xfc bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x213ec0
 *   fpu: float literal 0x3e99999a at 0x213ee0
 *   fpu: float literal 0x42f00000 at 0x213ee4
 *   fpu: float literal 0x40400000 at 0x213f14
 *   fpu: float literal 0x40200000 at 0x213f1c
 *   stack: address of the slot at 0x30 escapes at 0x213f38
 *   stack: 16-byte aggregate copy in 4-byte chunks at 0x213f2c
 */

extern void SetMyControlOn();
extern void SetBlast(float, float, float *, float *, signed int);
extern void SetE044RandomAppear(float *, signed int, signed int, float);

/* InitS0002Event000 @ 0x213F70 .. 0x214024 (0xb4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int CheckEventFlag(signed int);
extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern void FreeMdlMng(void *);
extern u8 MdlMng[];

/* SetEventFuncS0002 @ 0x214030 .. 0x214084 (0x54 bytes) */
/*
 * dcomp notes:
 *   repo declaration vs inferred signature: return void vs inferred u8 *
 */


extern u32 EventMngSt[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetEventFuncS0002(void);
static void InitS0002Event000(void *a0 );
static void PlayS0002Event000(void *a0 );
static void ActiS0002Event000(void *a0 , unsigned int a1 );
static void InitS0002Event001(void *a0 );
static void PlayS0002Event001(void *a0 );






void SetEventFuncS0002(void) {
    u8 *v1;

    v1 = (u8 *)InitS0002Event000;
    *(u32 *)EventMngSt = (u32)InitS0002Event000;
    v1 = (u8 *)PlayS0002Event000;
    *(u32 *)((u8 *)&EventMngSt + 4) = (u32)PlayS0002Event000;
    v1 = (u8 *)ActiS0002Event000;
    *(u32 *)((u8 *)&EventMngSt + 8) = (u32)ActiS0002Event000;
    v1 = (u8 *)InitS0002Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x60) = (u32)InitS0002Event001;
    v1 = (u8 *)PlayS0002Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x64) = (u32)PlayS0002Event001;
    return;
}

static void InitS0002Event000(void *a0 /* r4 */) {
    u32 *s1;
    u8 *s0;
    u32 v0;
    s32 a1;
    s32 v1;

    s1 = (u32 *)a0;
    a0 = (void *)(s32)0x6c9;
    s0 = (u8 *)MdlMng + 0x5400;
    v0 = CheckEventFlag((signed int)a0);
    a0 = (void *)(s32)1;
    if (v0 != 0) {
        a1 = 0x29;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        v1 = v0 << 3;
        v0 = v1 - v0;
        v0 = v0 << 6;
        a0 = (void *)(s32)((u8 *)s0 + v0);
        FreeMdlMng(a0);
        v1 = 2;
        *(u32 *)(((u8 *)s1 + 0xc)) = v1;
    } else {
        a0 = (void *)(s32)1;
        a1 = 0x2a;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        v1 = v0 << 3;
        v0 = v1 - v0;
        v0 = v0 << 6;
        a0 = (void *)(s32)((u8 *)s0 + v0);
        FreeMdlMng(a0);
        a0 = (void *)(s32)1;
        a1 = 0x29;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        v1 = v0 << 3;
        v1 = v1 - v0;
        v1 = (u32)v1 << 6;
        v1 = (s32)((u8 *)s0 + v1);
        *(u32 *)(((u8 *)s1 + 0x34)) = v1;
        *(u32 *)(((u8 *)s1 + 0xc)) = 0;
    }
    return;
}

static void PlayS0002Event000(void *a0 /* r4 */) {
    u8 *s1;
    float *s0;
    u32 v0;
    float f12;
    float f0;
    u8 stackFrame_30[16] __attribute__((aligned(16)));
    struct __copy_u32_4 { u32 b[4]; };

    s1 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    s0 = (float *)(u8 *)(MdlMng + 0x11800);
    if ((u32)(s32)a0 == (u32)1) {
        v0 = *(s32 *)(s1 + 0x34);
        a0 = (void *)*(s32 *)((v0 + 0x100));
        v0 = CheckAnimEndFrame(a0);
        a0 = (void *)0;
        if (v0 != 0) {
            SetMyActFreeFlag(0);
            SetMyControlOn();
            a0 = (void *)*(s32 *)(s1 + 0x34);
            f12 = 0.0f;
            ChangeAnimParam(a0, 2, 0.0f);
            v0 = 0x3e990000;
            a0 = (void *)(0x3e990000 | 0x999a);
            v0 = *(s32 *)(s1 + 0x34);
            f12 = 0.300000012f;
            SetBlast(0.300000012f, 120.0f, (float *)(u32)(v0 + 0x20), (float *)(u8 *)(s0 + 8),
                0x28);
            a0 = (void *)((u8 *)&stackFrame_30[0]);
            f0 = 3.0f;
            f12 = 2.5f;
            *(struct __copy_u32_4 *)((u8 *)&stackFrame_30[0]) = *(struct __copy_u32_4 *)(u8 *)(s0 +
                8);
            *(f32 *)((u8 *)&stackFrame_30[0]) = (*(float *)((u8 *)&stackFrame_30[0]) + f0);
            SetE044RandomAppear((float *)a0, 2, 0x64, 2.5f);
            a0 = (void *)(s32)1;
            *(u32 *)(s1 + 0xc) = 2;
            GetMdlMngIndexByCtrlId((signed int)a0, 0x2a);
        }
    }
    return;
}

static void ActiS0002Event000(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u8 *s0;
    u8 *s1;
    u32 v0;
    s32 v1;

    s0 = (u8 *)a0;
    a0 = (void *)(s32)1;
    s1 = (u8 *)MdlMng + 0x5400;
    switch ((u32)(s32)a1) {
    case 1:
        a1 = *(s32 *)(s0 + 0xc);
        if ((u32)(s32)a1 == 0) {
            a1 = 0x29;
            v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
            v1 = v0 << 3;
            v0 = (u32)(v0) * (u32)(7);
            v0 = v0 << 6;
            v0 = (s32)(s1 + v0);
            *(u32 *)(s0 + 0x34) = v0;
            a0 = (void *)*(s32 *)(s0 + 0x34);
            a1 = 1;
            ChangeAnimParam(a0, a1, 0.0f);
            v0 = 1;
            *(u32 *)(s0 + 0xc) = v0;
            v0 = GameSt[0x14];
            a0 = (void *)(s32)0x654;
            if (v0 == 0) {
                ResetEventFlag((signed int)a0);
            }
            a0 = (void *)(s32)0x6c9;
            SetEventFlag((signed int)a0);
            a0 = (void *)(s32)1;
            SetMyActFreeFlag((unsigned char)a0);
            SetMyControlOff();
            break;
        } else {
            if ((u32)(s32)a1 != (u32)2) {
                break;
            }
            v0 = 0x60000;
            a0 = (void *)(0x60000 | 0x1a8d);
            KnMsgMng_SendMsg((signed int)a0);
        }
    }
    return;
}

static void InitS0002Event001(void *a0 /* r4 */) {
    u32 *s1;
    u8 *s0;
    u32 v0;
    s32 a1;
    u32 v1;

    s1 = (u32 *)a0;
    a0 = (void *)(s32)0x5c;
    s0 = (u8 *)MdlMng + 0x5400;
    v0 = CheckEventFlag((signed int)a0);
    a0 = (void *)(s32)0x6d1;
    if (v0 != 0) {
        v0 = CheckEventFlag((signed int)a0);
        if (v0 != 0) {
            goto _L00213D48;
        }
        a0 = (void *)(s32)1;
        v0 = *(u8 *)((u8 *)&GameSt + 0x14);
        switch (v0) {
        case 0:
        case 1:
            a0 = (void *)(s32)1;
            a1 = 0x31;
            v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
            a0 = (void *)(s32)1;
            v1 = (u32)(v0) * (u32)(0x1c0);
            v1 = (s32)((u8 *)s0 + v1);
            *(u32 *)(((u8 *)s1 + 0x38)) = v1;
            v1 = *(s32 *)(((u8 *)s1 + 0x38));
            *(u8 *)((v1 + 2)) = (s32)a0;
            return;
        }
        a1 = 0x31;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        v0 = (u32)(v0) * (u32)(7);
        v0 = v0 << 6;
        a0 = (void *)(s32)((u8 *)s0 + v0);
        FreeMdlMng(a0);
        v1 = 3;
        *(u32 *)(((u8 *)s1 + 0x10)) = v1;
    } else {
        _L00213D48:;
        a0 = (void *)(s32)1;
        a1 = 0x31;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        a0 = (void *)(s32)(v0 << 3);
        v1 = 1;
        v0 = (s32)((u8 *)a0 - v0);
        v0 = v0 << 6;
        a0 = (void *)(s32)((u8 *)v0 + (u32)(s0));
        *(u8 *)(((u8 *)a0 + 2)) = v1;
        FreeMdlMng(a0);
        v1 = 3;
        *(u32 *)(((u8 *)s1 + 0x10)) = v1;
    }
    return;
}

static void PlayS0002Event001(void *a0 /* r4 */) {
    u8 *s0;
    u32 a1;
    u32 v1;
    u32 v0;
    float f1;
    float f0;

    v1 = 2;
    s0 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x10));
    a1 = (u32)((u8 *)MdlMng + 0x11800);
    switch ((u32)(s32)a0) {
    case 0:
        v0 = GetCurCamID();
        v1 = 3;
        if (v0 != v1) {
            break;
        }
        v1 = 1;
        *(u32 *)(s0 + 0x10) = v1;
        break;
    case 1:
        v0 = 0x250450;
        a0 = (void *)(s32)(a1 + 0x20);
        {
            struct stackFrame_20 { u8 b[16]; } stackFrame_20 __attribute__((aligned(16))) = {{0x00,
                0x00, 0x80, 0x40, 0x9a, 0x99, 0xd9, 0x3f, 0x00, 0x00, 0xa0, 0x40, 0x33, 0x33, 0x13,
                0x40}};
            a1 = (u32)((u8 *)&stackFrame_20);
            v0 = CheckSquareRange((float *)a0, (float *)a1);
            if (v0 == 0) {
                break;
            }
            a0 = (void *)*(s32 *)(s0 + 0x38);
            a1 = 1;
            ChangeAnimParam(a0, a1, 0.0f);
            v1 = *(s32 *)(s0 + 0x38);
            v0 = 2;
            a0 = (void *)(s32)0x6d1;
            *(u8 *)((v1 + 2)) = 0;
            *(u32 *)(s0 + 0x10) = v0;
            SetEventFlag((signed int)a0);
            break;
        }
    case 2:
        a1 = *(s32 *)(s0 + 0x38);
        v0 = 0x42700000;
        v1 = -0x41333333;
        f0 = 60.0f;
        a0 = (void *)*(s32 *)((a1 + 0x100));
        *(u32 *)((a1 + 0x24)) = -0x41333333;
        f1 = (*(float *)(((u8 *)a0 + 0xc)) - *(float *)a0);
        if (f1 < 60.0f) {
            v1 = *(s32 *)(s0 + 0x38);
            v0 = 0x3c888889;
            f0 = 0.0166666675f;
            f1 = *(float *)((v1 + 0x10c));
            *(f32 *)((v1 + 0x10c)) = (f1 - 0.0166666675f);
        }
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        a0 = (void *)*(s32 *)(s0 + 0x38);
        FreeMdlMng(a0);
        v1 = 3;
        *(u32 *)(s0 + 0x10) = v1;
    }
    return;
}
