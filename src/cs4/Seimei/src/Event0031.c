#include "common.h"

/* ActiS0031Event001 @ 0x206A10 .. 0x206A68 (0x58 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u32 KnMsgMng_SendMsgEx();

/* PlayS0031Event001 @ 0x206A70 .. 0x206E70 (0x400 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   literal: @876 -> 0x257370
 *   literal: @749 -> 0x250080
 *   literal: @761 -> 0x250090
 *   indirect: jr v1 at 0x206ad8 -> <v1>
 *   fpu: float literal 0x41100000 at 0x206af8
 *   fpu: float literal 0x00000000 at 0x206b10
 *   fpu: float literal 0x4123d70b at 0x206b44
 *   fpu: float literal 0x00000000 at 0x206b5c
 *   fpu: float literal 0xc1e80000 at 0x206c44
 *   fpu: float literal 0x41100000 at 0x206ca8
 *   fpu: float literal 0x00000000 at 0x206d30
 *   fpu: float literal 0x00000000 at 0x206d64
 *   literal: @761 initializes the 16-byte local at 0x40
 *   literal: @749 initializes the 16-byte local at 0x50
 *   cfg: kept branch: 0x206aa0 if (..) goto .L00206AB8
 *   cfg: loop body is not one contiguous region: .L00206CC8
 *   cfg: kept branch: 0x206cc8 if (..) goto .L00206DA8
 *   cfg: kept branch: 0x206cd4 if (..) goto .L00206DA8
 *   cfg: kept branch: 0x206ce8 if (..) goto .L00206DA8
 */

extern u32 KnMsgMng_CheckMsgNone();
extern float Math_GetDist2(float *, float *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern signed int CheckSquareRange(float *, float *);
extern signed int CheckEventFlag(signed int);
extern void EasyEneAppear(signed int);
extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern signed int CheckEneDead(void *);
extern signed int CheckEneFlick(void *);
extern void SetEventFlag(signed int);
extern unsigned int CheckAnimEndFrame(void *);
extern u32 MdlMng[];

/* InitS0031Event001 @ 0x206E70 .. 0x2070A0 (0x230 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x206f58
 *   fpu: float literal 0x00000000 at 0x20706c
 *   v1#6 is the pointer held in a0+0x40
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern signed int CheckEventFlag(signed int);
extern void SetEventFlag(signed int);
extern void ResetEventFlag(signed int);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void EasyEneAppear(signed int);
extern void FreeMdlMng(void *);
extern u32 MdlMng[];
extern u8 GameSt[];

/* ActiS0031Event000 @ 0x2070A0 .. 0x207158 (0xb8 bytes, frame 0x20) */

extern signed int CheckEventFlag(signed int);
extern u8 GameSt[];

/* PlayS0031Event000 @ 0x207160 .. 0x207278 (0x118 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x20717c writes a register its branch at 0x207178 reads
 *   fpu: float literal 0x00000000 at 0x207224
 */

extern u32 KnMsgMng_CheckMsgNone(void);
extern u32 KnMsgMng_GetSelectNum(void);
extern void SetMyControlOff(void);
extern void SetMyDizzy(signed int);
extern void SetRiddleMode(signed int);
extern u32 GetRiddleResult(void);
extern void SetEventFlag(signed int);
extern void ResetEventFlag(signed int);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetMyControlOn(void);
extern u32 EventMngSt[];

/* SetEventFuncS0031 @ 0x207290 .. 0x2072F4 (0x64 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */

static void PlayS0031Event000(void *a0 /* r4 */);
static void InitS0031Event001(void *a0 /* r4 */);
static void PlayS0031Event001(void *a0 /* r4 */);
extern u32 EventMngSt[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetEventFuncS0031(void);
static void InitS0031Event000(void);
static void PlayS0031Event000(void *a0 );
static void ActiS0031Event000(void *a0 );
static void InitS0031Event001(void *a0 );
static void PlayS0031Event001(void *a0 );
static u32 ActiS0031Event001(u32 *a0 );


void SetEventFuncS0031(void) {
    u8 *v1;

    v1 = (u8 *)InitS0031Event000;
    *(u32 **)EventMngSt = (u32 *)InitS0031Event000;
    v1 = (u8 *)PlayS0031Event000;
    *(u32 *)((u8 *)&EventMngSt + 4) = (u32)PlayS0031Event000;
    v1 = (u8 *)ActiS0031Event000;
    *(u32 *)((u8 *)&EventMngSt + 8) = (u32)ActiS0031Event000;
    v1 = (u8 *)InitS0031Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x60) = (u32)InitS0031Event001;
    v1 = (u8 *)PlayS0031Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x64) = (u32)PlayS0031Event001;
    v1 = (u8 *)ActiS0031Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x68) = (u32)ActiS0031Event001;
    return;
}

/* InitS0031Event000 @ 0x207280 .. 0x207288 (0x8 bytes) */

static void InitS0031Event000(void) {
    return;
}

static void PlayS0031Event000(void *a0 /* r4 */) {
    u8 *s0;
    s32 v1;
    u32 v0;

    v1 = 2;
    s0 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    switch ((u32)(s32)a0) {
    case 1:
        v0 = KnMsgMng_CheckMsgNone();
        if (v0 == 0) {
            break;
        }
        v0 = KnMsgMng_GetSelectNum();
        if (v0 == 0) {
            SetMyControlOff();
            SetMyDizzy(0);
            a0 = (void *)(s32)1;
            SetRiddleMode((signed int)a0);
            v1 = 2;
            *(u32 *)(s0 + 0xc) = v1;
            break;
        } else {
            *(u32 *)(s0 + 0xc) = 0;
            break;
        }
    case 2:
        v0 = GetRiddleResult();
        v1 = -1;
        if (v0 == (u32)v1) {
            break;
        }
        a0 = (void *)(s32)0x550;
        if (v0 != 0) {
            SetEventFlag((signed int)a0);
            a0 = (void *)(s32)0x402;
            SetEventFlag((signed int)a0);
            a0 = (void *)(s32)0x403;
            ResetEventFlag((signed int)a0);
            a0 = (void *)(s32)0x60d;
            ResetEventFlag((signed int)a0);
            a0 = (void *)*(s32 *)(EventMngSt + 0x25);
            ChangeAnimParam(a0, 0, 0.0f);
            v0 = 0x60000;
            v1 = 3;
            a0 = (void *)(0x60000 | 0x8ff6);
            EventMngSt[0x1c] = v1;
            KnMsgMng_SendMsgEx(a0, (s32)1, 0);
        }
        SetMyControlOn();
        a0 = (void *)(s32)1;
        SetMyDizzy((signed int)a0);
        *(u32 *)(s0 + 0xc) = 0;
    }
    return;
}

static void ActiS0031Event000(void *a0 /* r4 */) {
    u32 v1;
    u32 *s0;
    s32 v0;
    s32 a1;

    v1 = *(s32 *)(((u8 *)a0 + 0xc));
    s0 = (u32 *)a0;
    if (v1 == 0) {
        v0 = 2;
        v1 = *(u8 *)((u8 *)&GameSt + 0x14);
        a0 = (void *)(s32)0x550;
        if (v1 != (u32)v0) {
            v0 = CheckEventFlag((signed int)a0);
            if ((u32)v0 == 0) {
                v0 = 0x60000;
                a1 = 1;
                a0 = (void *)(0x60000 | 0x8fde);
                KnMsgMng_SendMsgEx(a0, a1, (u32)a1);
                v0 = 0x60000;
                a1 = 1;
                a0 = (void *)(0x60000 | 0x8fdf);
                KnMsgMng_SendMsgEx(a0, a1, 0);
                v1 = 1;
                *(u32 *)(((u8 *)s0 + 0xc)) = v1;
            } else {
                v0 = 0x60000;
                a0 = (void *)(0x60000 | 0x8ff7);
                a1 = 1;
                KnMsgMng_SendMsgEx(a0, a1, 0);
            }
        } else {
            v0 = 0x60000;
            a0 = (void *)(0x60000 | 0x8fe0);
            a1 = 1;
            KnMsgMng_SendMsgEx(a0, a1, 0);
        }
    }
    return;
}

static void InitS0031Event001(void *a0 /* r4 */) {
    u8 *s0;
    s32 a1;
    u32 v1;
    u32 v0;
    float f12;
    void *a0_2;

    s0 = (u8 *)a0;
    v0 = GetMdlMngIndexByCtrlId(1, 0xa);
    a1 = v0 + 0x30;
    v0 = (u32)MdlMng;
    *(u32 *)(s0 + 0x34) = (s32)((u8 *)MdlMng + (u32)((u32)a1 * (u32)(0x1c0)));
    v0 = GetMdlMngIndexByCtrlId(1, 2);
    a0_2 = (void *)(s32)(v0 + 0x30);
    v1 = (u32)MdlMng;
    a0_2 = (void *)((u8 *)(s32)((u32)a0_2 << 3) - (u32)(a0_2));
    a1 = 1;
    v0 = 2;
    *(u32 *)(s0 + 0x40) = (s32)((u8 *)MdlMng + (u32)((u32)a0_2 << 6));
    *(u8 *)((*(s32 *)(s0 + 0x40) + 0x130)) = a1;
    a0_2 = (void *)(s32)0x550;
    if ((u32)GameSt[0x14] != v0) {
        v0 = CheckEventFlag((signed int)a0_2);
        a0_2 = (void *)(s32)0x403;
        if (v0 == 0) {
            SetEventFlag((signed int)a0_2);
            *(u32 *)(s0 + 0x10) = 1;
        } else {
            v0 = CheckEventFlag(0x551);
            a0_2 = (void *)(s32)0x403;
            if (v0 == 0) {
                ResetEventFlag((signed int)a0_2);
                *(u32 *)(s0 + 0x10) = 3;
            } else {
                SetEventFlag(0x403);
                *(u32 *)(s0 + 0x10) = 7;
                f12 = 0.0f;
                ChangeAnimParam((void *)*(s32 *)(s0 + 0x34), 0x1f, 0.0f);
                *(u8 *)((*(s32 *)(s0 + 0x34) + 0x130)) = 1;
                *(u8 *)((*(s32 *)(s0 + 0x40) + 0x130)) = 0;
                v0 = CheckEventFlag(0x552);
                a0_2 = (void *)(s32)1;
                if (v0 == 0) {
                    EasyEneAppear((signed int)a0_2);
                    v0 = GetMdlMngIndexByCtrlId(2, 1);
                    a0_2 = (void *)(s32)(v0 + 0xa1);
                    v0 = (u32)MdlMng;
                    *(u32 *)(s0 + 0x38) = (s32)((u8 *)MdlMng + (u32)((u32)(s32)((u8
                        *)(s32)((u32)a0_2 << 3) - (u32)(a0_2)) << 6));
                }
                v0 = CheckEventFlag(0x553);
                a0_2 = (void *)(s32)2;
                if (v0 == 0) {
                    EasyEneAppear((signed int)a0_2);
                    a0_2 = (void *)(s32)2;
                    v0 = GetMdlMngIndexByCtrlId((signed int)a0_2, (s32)a0_2);
                    a1 = v0 + 0xa1;
                    v1 = (u32)MdlMng;
                    *(u32 *)(s0 + 0x3c) = (s32)((u8 *)MdlMng + (u32)((u32)(s32)((u8 *)(s32)((u32)a1
                        << 3) - a1) << 6));
                }
            }
        }
    } else {
        v0 = GetMdlMngIndexByCtrlId(7, a1);
        a0_2 = (void *)(s32)(v0 + 0x90);
        v0 = (u32)MdlMng;
        FreeMdlMng((void *)((u8 *)MdlMng + (u32)((u32)(s32)((u8 *)(u32)((u32)a0_2 << 3) -
            (u32)(a0_2)) << 6)));
        v0 = GetMdlMngIndexByCtrlId(7, 3);
        a0_2 = (void *)(s32)(v0 + 0x90);
        v0 = (u32)MdlMng;
        FreeMdlMng((void *)((u8 *)MdlMng + (u32)((u32)(s32)((u8 *)(u32)((u32)a0_2 << 3) -
            (u32)(a0_2)) << 6)));
        SetEventFlag(0x403);
        *(u32 *)(s0 + 0x10) = 7;
        f12 = 0.0f;
        ChangeAnimParam((void *)*(s32 *)(s0 + 0x34), 0x1e, 0.0f);
        *(u8 *)((*(s32 *)(s0 + 0x34) + 0x130)) = 1;
        *(u8 *)((*(s32 *)(s0 + 0x40) + 0x130)) = 0;
    }
    return;
}

static void PlayS0031Event001(void *a0 /* r4 */) {
    u8 *a3;
    u8 *s2;
    u32 a2;
    u32 a1;
    float f12;
    float f1;
    float f0;
    s32 s1;
    u8 *s0;
    u8 *a0_bytes; // a0
    u32 v1;
    u32 v0;

    a0_bytes = (u8 *)a0;
    v1 = 1;
    s2 = a0_bytes;
    a0_bytes = (u8 *)*(s32 *)(a0_bytes + 0xc);
    switch ((u32)(s32)a0_bytes) {
    case 1:
        v0 = KnMsgMng_CheckMsgNone();
        if (v0 == 0) {
            goto _L00206AB8;
        }
        *(u32 *)(s2 + 0xc) = 0;
    default:
        _L00206AB8:;
        v1 = *(s32 *)(s2 + 0x10);
        switch (v1) {
        case 1:
            v0 = *(s32 *)(s2 + 0x34);
            a1 = (u32)(u8 *)(MdlMng + 0x4608);
            a0_bytes = (u8 *)(s32)(v0 + 0x20);
            f0 = Math_GetDist2((float *)a0_bytes, (float *)a1);
            v1 = 0x41100000;
            f1 = 9.0f;
            if (!(f0 < 9.0f)) {
                break;
            }
            a0_bytes = (u8 *)*(s32 *)(s2 + 0x34);
            f12 = 0.0f;
            a1 = 0x28;
            ChangeAnimParam((void *)a0_bytes, a1, 0.0f);
            v1 = 2;
            *(u32 *)(s2 + 0x10) = v1;
            break;
        case 2:
            v0 = *(s32 *)(s2 + 0x34);
            a1 = (u32)(u8 *)(MdlMng + 0x4608);
            a0_bytes = (u8 *)(s32)(v0 + 0x20);
            f0 = Math_GetDist2((float *)a0_bytes, (float *)a1);
            v1 = 0x4123d70b;
            f1 = 10.2400007f;
            if (f0 <= 10.2400007f) {
                break;
            }
            a0_bytes = (u8 *)*(s32 *)(s2 + 0x34);
            f12 = 0.0f;
            ChangeAnimParam((void *)a0_bytes, 0, 0.0f);
            v1 = 1;
            *(u32 *)(s2 + 0x10) = v1;
            break;
        case 3:
            v0 = 0x250080;
            a0_bytes = (u8 *)(MdlMng + 0x4608);
            {
                struct stackFrame_50 { u8 b[16]; } stackFrame_50 __attribute__((aligned(16))) =
                    {{0x00, 0x00, 0xe8, 0xc1, 0x00, 0x00, 0x60, 0xc1, 0x00, 0x00, 0xd0, 0xc1, 0x00,
                    0x00, 0x10, 0xc1}};
                v0 = CheckSquareRange((float *)a0_bytes, (float *)((u8 *)&stackFrame_50));
                if (v0 == 0) {
                    break;
                }
                *(u32 *)(s2 + 0x10) = 4;
                v0 = CheckEventFlag(0x552);
                a0_bytes = (u8 *)(s32)1;
                if (v0 == 0) {
                    EasyEneAppear((signed int)a0_bytes);
                    a1 = 1;
                    v0 = GetMdlMngIndexByCtrlId(2, a1);
                    a0_bytes = (u8 *)(s32)(v0 + 0xa1);
                    v0 = (u32)MdlMng;
                    v1 = (u32)(s32)((u8 *)(s32)((u32)a0_bytes << 3) - (u32)(a0_bytes)) << 6;
                    v0 = (s32)((u8 *)MdlMng + v1);
                    *(u32 *)(s2 + 0x38) = v0;
                }
                if (CheckEventFlag(0x553) != 0) {
                    break;
                }
                EasyEneAppear(2);
                a0_bytes = (u8 *)(s32)2;
                v0 = GetMdlMngIndexByCtrlId((signed int)a0_bytes, (s32)a0_bytes);
                a1 = v0 + 0xa1;
                v1 = (u32)MdlMng;
                a0_bytes = (u8 *)(s32)((u32)(s32)((u8 *)(s32)(a1 << 3) - a1) << 6);
                v1 = (s32)((u8 *)MdlMng + (u32)(a0_bytes));
                *(u32 *)(s2 + 0x3c) = v1;
                break;
            }
        case 4:
            f1 = *(float *)(MdlMng + 0x4608);
            f0 = -29.0f;
            v1 = 5;
            if (!(f1 < -29.0f)) {
                break;
            }
            *(u32 *)(s2 + 0x10) = v1;
            break;
        case 5:
            v0 = 0x250090;
            a0_bytes = (u8 *)(MdlMng + 0x4608);
            {
                struct stackFrame_40 { u8 b[16]; } stackFrame_40 __attribute__((aligned(16))) =
                    {{0x00, 0x00, 0xe8, 0xc1, 0x00, 0x00, 0x60, 0xc1, 0x00, 0x00, 0xd0, 0xc1, 0x00,
                    0x00, 0x10, 0xc1}};
                v0 = CheckSquareRange((float *)a0_bytes, (float *)((u8 *)&stackFrame_40));
                v1 = 4;
                if (v0 != 0) {
                    *(u32 *)(s2 + 0x10) = v1;
                    break;
                } else {
                    v0 = *(s32 *)(s2 + 0x34);
                    a1 = (u32)(u8 *)(MdlMng + 0x4608);
                    a0_bytes = (u8 *)(s32)(v0 + 0x20);
                    f0 = Math_GetDist2((float *)a0_bytes, (float *)a1);
                    f1 = 9.0f;
                    v1 = 7;
                    if (f0 <= 9.0f) {
                        break;
                    }
                    s1 = 1;
                    *(u32 *)(s2 + 0x10) = v1;
                    s0 = (u8 *)(s2 + 4);
                    do {
                        a0_bytes = (u8 *)*(s32 *)(s0 + 0x34);
                        if ((u32)(s32)a0_bytes == 0) {
                            goto _L00206DA8;
                        }
                        v0 = CheckEneDead((void *)a0_bytes);
                        if (v0 != 0) {
                            goto _L00206DA8;
                        }
                        a0_bytes = (u8 *)*(s32 *)(s0 + 0x34);
                        v0 = CheckEneFlick((void *)a0_bytes);
                        if (v0 != 0) {
                            goto _L00206DA8;
                        }
                        v0 = (s32)((u8 *)(s32)((u32)s1 << 2) + (u32)(s2));
                        a0_bytes = (u8 *)*(s32 *)((v0 + 0x34));
                        s0 = (u8 *)(s32)(v0 + 0x34);
                        a1 = *(s32 *)(a0_bytes + 0x148);
                        ((void (*)(s32, s32, s32))(s32)*(s32 *)((a1 + 0x118)))((s32)a0_bytes, a1,
                            0x62);
                        a3 = (u8 *)*(s32 *)s0;
                        v0 = -0x40c00000;
                        a2 = -0x40c00000 | 0x8312;
                        v0 = 0x3fc90000;
                        a0_bytes = (u8 *)-0x3ed80000;
                        f12 = 0.0f;
                        *(u32 *)(a3 + 0x20) = -0x3e1c0000;
                        *(u32 *)((*(s32 *)s0 + 0x24)) = a2;
                        *(u32 *)((*(s32 *)s0 + 0x28)) = -0x3ed80000;
                        *(u32 *)((*(s32 *)s0 + 0x34)) = 0x3fc90000 | 0xfdb;
                        ChangeAnimParam((void *)*(s32 *)s0, 0x62, 0.0f);
                        v1 = 1;
                        f12 = 0.0f;
                        *(u8 *)((*(s32 *)(s2 + 0x34) + 0x130)) = v1;
                        *(u8 *)((*(s32 *)(s2 + 0x40) + 0x130)) = 0;
                        a1 = 0x1e;
                        ChangeAnimParam((void *)*(s32 *)(s2 + 0x34), a1, 0.0f);
                        v0 = 6;
                        *(u32 *)(s2 + 0x10) = v0;
                        *(u32 *)(s2 + 0x14) = s1;
                        SetEventFlag(0x403);
                        a0_bytes = (u8 *)(s32)0x551;
                        SetEventFlag((signed int)a0_bytes);
                        break;
                        _L00206DA8:;
                        s1 = s1 + 1;
                        s0 = (u8 *)(s0 + 4);
                    } while (s1 <= (s32)2);
                    break;
                }
            }
        case 6:
            a0_bytes = (u8 *)*(s32 *)((*(s32 *)(((s32)((u8 *)(s32)((u32)*(s32 *)(s2 + 0x14) << 2) +
                (u32)(s2)) + 0x34)) + 0x100));
            v0 = CheckAnimEndFrame((void *)a0_bytes);
            if (v0 == 0) {
                break;
            }
            a1 = 1;
            v1 = 7;
            a0_bytes = (u8 *)*(s32 *)(((u8 *)*(s32 *)(((u8 *)(s32)((u8 *)(s32)((u32)*(s32 *)(s2 +
                0x14) << 2) + (u32)(s2)) + 0x34)) + 0x148));
            *(u8 *)(a0_bytes + 0x182) = a1;
            *(u32 *)(s2 + 0x10) = v1;
        case 0:
        default:
            break;
        }
    }
    a0_bytes = (u8 *)*(s32 *)(s2 + 0x38);
    if ((u32)(s32)a0_bytes != 0) {
        v0 = CheckEneDead((void *)a0_bytes);
        a0_bytes = (u8 *)(s32)0x552;
        if (v0 != 0) {
            SetEventFlag((signed int)a0_bytes);
        }
    }
    a0_bytes = (u8 *)*(s32 *)(s2 + 0x3c);
    if ((u32)(s32)a0_bytes != 0) {
        v0 = CheckEneDead((void *)a0_bytes);
        a0_bytes = (u8 *)(s32)0x553;
        if (v0 != 0) {
            SetEventFlag((signed int)a0_bytes);
        }
    }
    return;
}

static u32 ActiS0031Event001(u32 *a0 /* r4 */) {
    u32 v1;
    u32 s0;
    u32 v0;

    v1 = *(u32 *)(((u8 *)a0 + 0xc));
    s0 = (u32)a0;
    if (v1 == 0) {
        v0 = 0x60000;
        a0 = (u32 *)(0x60000 | 0x8fe1);
        KnMsgMng_SendMsgEx(a0, 1, 1);
        v0 = 0x60000;
        a0 = (u32 *)(0x60000 | 0x8fe2);
        KnMsgMng_SendMsgEx(a0, 1, 0);
        v1 = 1;
        *(u32 *)((s0 + 0xc)) = 1;
    }
    return;
}
