#include "common.h"




extern signed int KnMsgMng_SendMsg(signed int);
extern signed int CheckEventFlag(signed int);
extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern void FreeMdlMng(void *);
extern u8 GameSt[];
extern u32 MdlMng[];
extern signed int CheckSquareRange(float *, float *);
extern void SetCamCtrlMode(unsigned int);
extern void SetCameraPos(float *);
extern void SetCameraAng(float *);
extern void SetEventFlag(signed int);
static void InitS0008Event000(void *a0 /* r4 */);
extern u32 EventMngSt[];
static void PlayS0008Event001(void *a0 /* r4 */);
static void ActiS0008Event001(void *a0 /* r4 */, unsigned int a1 /* r5 */);
static void InitS0008Event001(void *a0 /* r4 */);
static void PlayS0008Event000(void *a0 /* r4 */);
void SetEventFuncS0008(void);

/* SetEventFuncS0008 @ 0x212970 .. 0x2129F4 (0x84 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x2129d8 writes a register its branch at 0x2129d4 reads
 */


void SetEventFuncS0008(void) {
    u32 v1;
    u32 a0;
    s32 branchcond_2129d4;

    v1 = (u32)InitS0008Event000;
    *(u32 *)EventMngSt = (u32)InitS0008Event000;
    v1 = (u32)PlayS0008Event000;
    *(u32 *)((u8 *)&EventMngSt + 4) = (u32)PlayS0008Event000;
    v1 = (u32)InitS0008Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x60) = (u32)InitS0008Event001;
    v1 = (u32)PlayS0008Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x64) = (u32)PlayS0008Event001;
    v1 = (u32)ActiS0008Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x68) = (u32)ActiS0008Event001;
    v1 = 1;
    a0 = *(u8 *)((u8 *)&GameSt + 0x14);
    branchcond_2129d4 = a0 != 1;
    a0 = 0x54a;
    if (!branchcond_2129d4) {
        SetEventFlag(0x54a);
    }
    return;
}

/* InitS0008Event000 @ 0x2128D0 .. 0x212968 (0x98 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x21291c if (..) goto .L00212948
 *   cfg: kept goto: 0x212930 -> .L00212958
 *   declaration vs inferred signature: return void vs inferred u32
 */

static void InitS0008Event000(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u32 v0;

    s0 = (u8 *)a0;
    a0 = (void *)(s32)1;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, 0xe);
    a0 = (void *)(s32)(v0 << 3);
    a0 = (void *)((u8 *)a0 - v0);
    a0 = (void *)(s32)((u32)a0 << 6);
    v1 = (s32)((u8 *)(u8 *)(MdlMng + 0x1500) + (u32)(a0));
    v0 = 1;
    *(u32 *)(s0 + 0x34) = v1;
    a0 = (void *)(s32)0x54b;
    if ((u32)GameSt[0x14] == v0) {
        v0 = CheckEventFlag((signed int)a0);
        if (v0 == 0) {
            goto _L00212948;
        }
    }
    a0 = (void *)*(s32 *)(s0 + 0x34);
    FreeMdlMng(a0);
    v1 = 2;
    *(u32 *)(s0 + 0xc) = v1;
    goto _L00212958;
    _L00212948:;
    v1 = *(s32 *)(s0 + 0x34);
    a0 = (void *)(s32)1;
    *(u8 *)((v1 + 2)) = (s32)a0;
    _L00212958:;
    return;
}









/* PlayS0008Event000 @ 0x2127D0 .. 0x2128D0 (0x100 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @709 -> 0x2503c0
 *   literal: @713 -> 0x2503d0
 *   literal: @715 -> 0x2503e0
 *   stack: address of the slot at 0x30 escapes at 0x212850
 *   stack: address of the slot at 0x20 escapes at 0x212868
 *   literal: @715 initializes the 16-byte local at 0x20
 *   literal: @713 initializes the 16-byte local at 0x30
 *   literal: @709 initializes the 16-byte local at 0x40
 *   declaration vs inferred signature: return void vs inferred u32
 */


static void PlayS0008Event000(void *a0 /* r4 */) {
    u8 *a1;
    u8 *s0;
    u8 *a0_bytes; // a0
    u32 v1;
    u32 v0;
    u8 stackFrame_50[16] __attribute__((aligned(16)));
    struct __copy_u_long128_1 { u_long128 b[1]; };

    a0_bytes = (u8 *)a0;
    v1 = 1;
    s0 = a0_bytes;
    a0_bytes = (u8 *)*(s32 *)(a0_bytes + 0xc);
    a1 = (u8 *)MdlMng + 0x11800;
    switch ((u32)(s32)a0_bytes) {
    case 0:
        v0 = 0x2503c0;
        a0_bytes = (u8 *)(a1 + 0x20);
        a1 = ((u8 *)&stackFrame_50[0]);
        {
            struct stackFrame_40 { u8 b[16]; } stackFrame_40 __attribute__((aligned(16))) = {{0xcd,
                0xcc, 0x44, 0x42, 0x00, 0x00, 0x1a, 0xc2, 0x33, 0x33, 0x4f, 0x42, 0xcd, 0xcc, 0x16,
                0xc2}};
            v1 = (u32)((u8 *)&stackFrame_40);
            *(struct __copy_u_long128_1 *)((u8 *)&stackFrame_50[0]) = *(struct __copy_u_long128_1
                *)((u8 *)&stackFrame_40);
            v0 = CheckSquareRange((float *)a0_bytes, (float *)a1);
            a0_bytes = (u8 *)(s32)1;
            if (v0 == 0) {
                break;
            }
            SetCamCtrlMode((unsigned int)a0_bytes);
            v0 = 0x2503d0;
            {
                struct stackFrame_30 { u8 b[16]; } stackFrame_30 __attribute__((aligned(16))) =
                    {{0x00, 0x00, 0x3c, 0x42, 0xcd, 0xcc, 0x4c, 0xbe, 0x66, 0x66, 0x18, 0xc2, 0x00,
                    0x00, 0x80, 0x3f}};
                a0_bytes = ((u8 *)&stackFrame_30);
                SetCameraPos((float *)a0_bytes);
                v0 = 0x2503e0;
                {
                    struct stackFrame_20 { u8 b[16]; } stackFrame_20 __attribute__((aligned(16))) =
                        {{0x7e, 0x4d, 0xbe, 0x3e, 0xd8, 0x5f, 0xcc, 0x3f, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00}};
                    a0_bytes = ((u8 *)&stackFrame_20);
                    SetCameraAng((float *)a0_bytes);
                    a0_bytes = (u8 *)(s32)0x54b;
                    SetEventFlag((signed int)a0_bytes);
                    a0_bytes = (u8 *)*(s32 *)(s0 + 0x34);
                    v1 = 1;
                    *(u8 *)(a0_bytes + 2) = 0;
                    *(u32 *)(s0 + 0xc) = v1;
                    *(u32 *)(s0 + 0x10) = 0;
                    break;
                }
            }
        }
    case 1:
        a0_bytes = (u8 *)*(s32 *)(s0 + 0x10);
        v1 = 0x1e;
        a0_bytes = (u8 *)(a0_bytes + 1);
        *(u32 *)(s0 + 0x10) = (s32)a0_bytes;
        if ((u32)(s32)a0_bytes != v1) {
            break;
        }
        SetCamCtrlMode(0);
        a0_bytes = (u8 *)*(s32 *)(s0 + 0x34);
        a1 = (u8 *)(s32)1;
        v1 = 2;
        *(u8 *)(a0_bytes + 2) = (s32)a1;
        *(u32 *)(s0 + 0xc) = v1;
    }
    return;
}









/* InitS0008Event001 @ 0x212740 .. 0x2127C8 (0x88 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x212768 if (..) goto .L00212780
 */


static void InitS0008Event001(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    s32 v0;

    v1 = 1;
    s0 = (u8 *)a0;
    a0 = (void *)GameSt[0x14];
    if ((u32)a0 == v1) {
        a0 = (void *)(s32)0x6c0;
        v0 = CheckEventFlag((signed int)a0);
        if ((u32)v0 == 0) {
            goto _L00212780;
        }
    }
    v1 = 2;
    *(u32 *)(s0 + 0x14) = v1;
    _L00212780:;
    v1 = GameSt[0x14];
    a0 = (void *)(s32)1;
    if (v1 == 0) {
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, 0xa);
        a0 = (void *)(s32)((u32)v0 << 3);
        v0 = (s32)((u8 *)a0 - v0);
        v1 = (u32)((u8 *)MdlMng + 0x5400);
        v0 = (u32)v0 << 6;
        a0 = (void *)(s32)(v1 + v0);
        FreeMdlMng(a0);
    }
    return;
}


/* PlayS0008Event001 @ 0x212680 .. 0x212738 (0xb8 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: a1: 128-bit web split from its scalar uses
 *   literal: @742 -> 0x2503f0
 *   literal: @747 -> 0x250400
 *   stack: address of the slot at 0x40 escapes at 0x2126c0
 *   fpu: float literal 0x42c80000 at 0x212700
 *   stack: address of the slot at 0x40 escapes at 0x21270c
 *   literal: @747 initializes the 16-byte local at 0x20
 *   literal: @742 initializes the 16-byte local at 0x40
 *   declaration vs inferred signature: return void vs inferred u32
 */


extern void EasyEneAppear(signed int);
extern signed int SND_Play3D(signed int, signed short, signed short, void *, float);



static void PlayS0008Event001(void *a0 /* r4 */) {
    u8 *s0;
    u8 *a3;
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    struct stackFrame_40 { u8 b[16]; } stackFrame_40 __attribute__((aligned(16)));
    u8 stackFrame_30[16] __attribute__((aligned(16)));
    struct stackFrame_20 { u8 b[16]; } stackFrame_20 __attribute__((aligned(16)));
    struct __copy_u_long128_1 { u_long128 b[1]; };

    v1 = 0x2503f0;
    a2 = (u32)((u8 *)&stackFrame_40);
    s0 = (u8 *)a0;
    stackFrame_40 = (struct stackFrame_40){{0x00, 0x00, 0x34, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xe0, 0xc1, 0x00, 0x00, 0x00, 0x00}};
    v1 = 1;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x14));
    a3 = (u8 *)(MdlMng + 0x4600);
    switch ((u32)(s32)a0) {
    case 1:
        v0 = 0x250400;
        v1 = (u32)((u8 *)&stackFrame_20);
        a1 = (u32)((u8 *)&stackFrame_30[0]);
        a0 = (void *)(a3 + 0x20);
        stackFrame_20 = (struct stackFrame_20){{0x00, 0x00, 0x42, 0x42, 0x00, 0x00, 0xe0, 0xc1,
            0x00, 0x00, 0x46, 0x42, 0x00, 0x00, 0xc8, 0xc1}};
        *(struct __copy_u_long128_1 *)((u8 *)&stackFrame_30[0]) = *(struct __copy_u_long128_1
            *)((u8 *)&stackFrame_20);
        v0 = CheckSquareRange((float *)a0, (float *)a1);
        a0 = (void *)(s32)2;
        if (v0 == 0) {
            break;
        }
        EasyEneAppear((signed int)a0);
        a0 = (void *)(s32)0x450;
        a1 = 0x40;
        a3 = ((u8 *)&stackFrame_40);
        SND_Play3D((signed int)a0, a1, 0, (void *)a3, 100.0f);
        a0 = (void *)(s32)0x6c0;
        SetEventFlag((signed int)a0);
        *(u32 *)(s0 + 0x14) = 2;
    }
    return;
}












/* ActiS0008Event001 @ 0x212620 .. 0x212678 (0x58 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */


static void ActiS0008Event001(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u8 *s0;
    u32 v1;

    v1 = 1;
    s0 = (u8 *)a0;
    switch ((u32)(s32)a1) {
    case 1:
        v1 = *(s32 *)(s0 + 0x14);
        if ((s32)v1 > (s32)1) {
            break;
        }
        a0 = (void *)(0x60000 | 0x1a8c);
        KnMsgMng_SendMsg((signed int)a0);
        v1 = 1;
        *(u32 *)(s0 + 0x14) = v1;
    }
    return;
}
