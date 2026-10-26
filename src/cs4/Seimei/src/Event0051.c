#include "common.h"




extern float Math_GetDist2(float *, float *);
extern unsigned int CheckMyDash(void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetEventFlag(signed int);
extern unsigned int CheckAnimEndFrame(void *);
extern signed int CheckEneDead(void *);
extern u16 MdlMng[];
extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern signed int CheckEventFlag(signed int);
extern void EasyEneAppear(signed int);
extern void EasyEneAppearEx(signed int, unsigned short, unsigned char);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern u16 MdlMng[];
extern u8 GameSt[];
extern signed int GetCurCamID(void);
extern void SetEventFlag(signed int);
extern void SetMyActFreeFlag(unsigned char);
extern void SetMyControlOff(void);
extern void *GetCamInfo(void);
extern signed int KnMsgMng_SendMsg(signed int);
extern void SetHokanFrame(void *, float);
extern signed int CheckMyControlOff(void *);
extern void SetMyControlOn(void);
extern unsigned int CheckAnimNumFrame(void *, float);
extern signed int CheckSquareRange(float *, float *);
extern unsigned int CheckAnimEndFrame(void *);
extern void FreeMdlMng(void *);
static void InitS0051Event000(void *a0 );
static void PlayS0051Event000(void *a0 );
static void ActiS0051Event000(void *a0 , unsigned int a1 );
static void InitS0051Event001(void *a0 );
static void PlayS0051Event001(void *a0 );
static void ActiS0051Event001(void *a0 , unsigned int a1 );
static void InitS0051Event002(void *a0 );
static void PlayS0051Event002(void *a0 );
extern u32 EventMngSt[];
static void PlayS0051Event002(void *a0 /* r4 */);
static void InitS0051Event002(void *a0 /* r4 */);
static void ActiS0051Event001(void *a0 /* r4 */, unsigned int a1 /* r5 */);
static void PlayS0051Event001(void *a0 /* r4 */);
static void InitS0051Event001(void *a0 /* r4 */);
static void ActiS0051Event000(void *a0 /* r4 */, unsigned int a1 /* r5 */);
static void PlayS0051Event000(void *a0 /* r4 */);
static void InitS0051Event000(void *a0 /* r4 */);
void SetEventFuncS0051(void);

/* SetEventFuncS0051 @ 0x207D60 .. 0x207E0C (0xac bytes, frame 0x10) */
/* r4 */
/* r4 */
/* r4 */
/* r5 */
/* r4 */
/* r4 */
/* r4 */
/* r5 */
/* r4 */
/* r4 */


void SetEventFuncS0051(void) {
    u32 v0;
    s32 a0;

    v0 = (u32)InitS0051Event000;
    a0 = 0x545;
    *(u32 **)EventMngSt = (u32 *)InitS0051Event000;
    v0 = (u32)PlayS0051Event000;
    *(u32 *)((u8 *)&EventMngSt + 4) = (u32)PlayS0051Event000;
    v0 = (u32)ActiS0051Event000;
    *(u32 *)((u8 *)&EventMngSt + 8) = (u32)ActiS0051Event000;
    v0 = (u32)InitS0051Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x60) = (u32)InitS0051Event001;
    v0 = (u32)PlayS0051Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x64) = (u32)PlayS0051Event001;
    v0 = (u32)ActiS0051Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x68) = (u32)ActiS0051Event001;
    v0 = (u32)InitS0051Event002;
    *(u32 *)((u8 *)&EventMngSt + 0xc0) = (u32)InitS0051Event002;
    v0 = (u32)PlayS0051Event002;
    *(u32 *)((u8 *)&EventMngSt + 0xc4) = (u32)PlayS0051Event002;
    v0 = CheckEventFlag(a0);
    a0 = 0x549;
    if (v0 != 0) {
        SetEventFlag(a0);
    }
    return;
}













/* InitS0051Event000 @ 0x207C00 .. 0x207D54 (0x154 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x207cc0
 *   fpu: float literal 0x00000000 at 0x207d0c
 *   v0#7 is the pointer held in a0+0x38
 */


static void InitS0051Event000(void *a0 /* r4 */) {
    u8 *s1;
    u8 *a2;
    u8 *s0;
    s32 v1;
    u32 v0;
    float f12;
    void *a0_2;

    s1 = (u8 *)a0;
    s0 = (u8 *)(MdlMng + 0x2a00);
    v0 = GetMdlMngIndexByCtrlId(1, 0x13);
    a0_2 = (void *)(s32)1;
    v0 = v0 * (u32)(7);
    v0 = v0 << 6;
    *(u32 *)(s1 + 0x34) = (s32)(s0 + v0);
    v0 = GetMdlMngIndexByCtrlId((signed int)a0_2, 0xa);
    a0_2 = (void *)(s32)(v0 << 3);
    v1 = 1;
    v0 = (s32)((u8 *)a0_2 - v0);
    v0 = v0 << 6;
    *(u32 *)(s1 + 0x38) = (s32)(s0 + v0);
    *(u8 *)((*(s32 *)(s1 + 0x34) + 2)) = v1;
    *(u8 *)((*(s32 *)(s1 + 0x38) + 2)) = v1;
    v0 = GameSt[0x14];
    if (v0 != 0) {
        FreeMdlMng((void *)*(s32 *)(s1 + 0x34));
        FreeMdlMng((void *)*(s32 *)(s1 + 0x38));
        *(u32 *)(s1 + 0xc) = 4;
    } else {
        v0 = CheckEventFlag(0x540);
        if (v0 != 0) {
            a2 = (u8 *)*(s32 *)(s1 + 0x34);
            v0 = -0x3ea20000;
            a0_2 = (void *)(-0x3ea20000 | 0x6666);
            v1 = -0x3cfd0000;
            f12 = 0.0f;
            *(u8 *)(a2 + 2) = 0;
            *(u32 *)((*(s32 *)(s1 + 0x34) + 0x20)) = (u32)a0_2;
            *(u32 *)((*(s32 *)(s1 + 0x34) + 0x24)) = 0;
            *(u32 *)((*(s32 *)(s1 + 0x34) + 0x28)) = -0x3cfd0000;
            ChangeAnimParam((void *)*(s32 *)(s1 + 0x34), 2, 0.0f);
            *(u32 *)(s1 + 0xc) = 2;
        }
        v0 = CheckEventFlag(0x541);
        if (v0 != 0) {
            v0 = *(s32 *)(s1 + 0x38);
            f12 = 0.0f;
            *(u8 *)((v0 + 2)) = 0;
            ChangeAnimParam((void *)*(s32 *)(s1 + 0x38), 2, 0.0f);
            *(u32 *)(s1 + 0xc) = 4;
        }
        v0 = CheckEventFlag(0x542);
        if (v0 != 0) {
            FreeMdlMng((void *)*(s32 *)(s1 + 0x34));
        }
    }
    return;
}













/* PlayS0051Event000 @ 0x207A30 .. 0x207BFC (0x1cc bytes, frame 0x60) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @704 -> 0x2500a0
 *   literal: @714 -> 0x2500b0
 *   delay: addiu at 0x207a60 writes a register its branch at 0x207a5c reads
 *   fpu: float literal 0x00000000 at 0x207acc
 *   fpu: float literal 0x00000000 at 0x207b10
 *   fpu: float literal 0x00000000 at 0x207b84
 *   fpu: float literal 0x00000000 at 0x207bc8
 *   literal: @714 initializes the 16-byte local at 0x30
 *   literal: @704 initializes the 16-byte local at 0x40
 */


static void PlayS0051Event000(void *a0 /* r4 */) {
    u8 *s1;
    u32 a1;
    u8 *s0;
    u32 v1;
    u32 v0;
    float f12;
    u8 stackFrame_50[16] __attribute__((aligned(16)));
    struct __copy_u_long128_1 { u_long128 b[1]; };

    v1 = 3;
    s1 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    s0 = (u8 *)MdlMng + 0x11800;
    switch ((u32)(s32)a0) {
    case 0:
        v0 = 0x2500a0;
        a1 = (u32)((u8 *)&stackFrame_50[0]);
        a0 = (void *)(s0 + 0x20);
        {
            struct stackFrame_40 { u8 b[16]; } stackFrame_40 __attribute__((aligned(16))) = {{0x33,
                0x33, 0x87, 0xc1, 0xcd, 0xcc, 0x01, 0xc3, 0x33, 0x33, 0x6b, 0xc1, 0x66, 0xe6, 0x00,
                0xc3}};
            v1 = (u32)((u8 *)&stackFrame_40);
            *(struct __copy_u_long128_1 *)((u8 *)&stackFrame_50[0]) = *(struct __copy_u_long128_1
                *)((u8 *)&stackFrame_40);
            v0 = CheckSquareRange((float *)a0, (float *)a1);
            a0 = (void *)s0;
            if (v0 == 0) {
                break;
            }
            v0 = CheckMyControlOff(a0);
            if (v0 == 0) {
                break;
            }
            SetMyControlOff();
            v0 = *(s32 *)(s1 + 0x34);
            f12 = 0.0f;
            *(u8 *)((v0 + 2)) = 0;
            a0 = (void *)*(s32 *)(s1 + 0x34);
            a1 = 1;
            ChangeAnimParam(a0, a1, 0.0f);
            v1 = 1;
            *(u32 *)(s1 + 0xc) = v1;
            break;
        }
    case 1:
        v0 = *(s32 *)(s1 + 0x34);
        a0 = (void *)*(s32 *)((v0 + 0x100));
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        SetMyControlOn();
        a0 = (void *)*(s32 *)(s1 + 0x34);
        f12 = 0.0f;
        a1 = 2;
        ChangeAnimParam(a0, a1, 0.0f);
        v0 = 2;
        a0 = (void *)(s32)0x540;
        *(u32 *)(s1 + 0xc) = v0;
        SetEventFlag((signed int)a0);
        break;
    case 2:
        v0 = 0x2500b0;
        a1 = (u32)((u8 *)&stackFrame_50[0]);
        a0 = (void *)(s0 + 0x20);
        {
            struct stackFrame_30 { u8 b[16]; } stackFrame_30 __attribute__((aligned(16))) = {{0xcd,
                0xcc, 0x74, 0xc1, 0xcd, 0xcc, 0x03, 0xc3, 0x00, 0x00, 0x68, 0xc1, 0x33, 0xb3, 0x01,
                0xc3}};
            v1 = (u32)((u8 *)&stackFrame_30);
            *(struct __copy_u_long128_1 *)((u8 *)&stackFrame_50[0]) = *(struct __copy_u_long128_1
                *)((u8 *)&stackFrame_30);
            v0 = CheckSquareRange((float *)a0, (float *)a1);
            a0 = (void *)s0;
            if (v0 == 0) {
                break;
            }
            v0 = CheckMyControlOff(a0);
            if (v0 == 0) {
                break;
            }
            SetMyControlOff();
            v0 = *(s32 *)(s1 + 0x38);
            f12 = 0.0f;
            *(u8 *)((v0 + 2)) = 0;
            a0 = (void *)*(s32 *)(s1 + 0x38);
            a1 = 1;
            ChangeAnimParam(a0, a1, 0.0f);
            v1 = 3;
            *(u32 *)(s1 + 0xc) = v1;
            break;
        }
    case 3:
        v0 = *(s32 *)(s1 + 0x38);
        a0 = (void *)*(s32 *)((v0 + 0x100));
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        SetMyControlOn();
        a0 = (void *)*(s32 *)(s1 + 0x38);
        f12 = 0.0f;
        a1 = 2;
        ChangeAnimParam(a0, a1, 0.0f);
        v0 = 4;
        a0 = (void *)(s32)0x541;
        *(u32 *)(s1 + 0xc) = v0;
        SetEventFlag((signed int)a0);
    }
    return;
}









/* ActiS0051Event000 @ 0x207990 .. 0x207A2C (0x9c bytes, frame 0x10) */







static void ActiS0051Event000(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u32 v1;
    s32 v0;

    v1 = 1;
    switch ((u32)(s32)a1) {
    case 1:
        a1 = *(s32 *)(((u8 *)a0 + 0x38));
        v1 = *(u8 *)a1;
        if (v1 == 0 || (u32)*(u8 *)(((s32)(a1) + 2)) != 0) {
            break;
        }
        a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
        v1 = 4;
        if ((u32)(s32)a0 != v1) {
            break;
        }
        a0 = (void *)(s32)0x558;
        v0 = CheckEventFlag((signed int)a0);
        a0 = (void *)(s32)0x558;
        if ((u32)v0 == 0) {
            SetEventFlag((signed int)a0);
            v0 = 0x60000;
            a0 = (void *)(0x60000 | 0xde2f);
            KnMsgMng_SendMsg((signed int)a0);
            v0 = 0x60000;
            a0 = (void *)(0x60000 | 0xde30);
            KnMsgMng_SendMsg((signed int)a0);
            break;
        } else {
            v0 = 0x60000;
            a0 = (void *)(0x60000 | 0xde31);
            KnMsgMng_SendMsg((signed int)a0);
        }
    }
    return;
}






/* InitS0051Event001 @ 0x2078B0 .. 0x207988 (0xd8 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x207914 writes a register its branch at 0x207910 reads
 *   fpu: float literal 0x00000000 at 0x207954
 *   fpu: float literal 0x00000000 at 0x207960
 *   cfg: kept branch: 0x2078f8 if (..) goto .L00207920
 *   cfg: kept branch: 0x207930 if (..) goto .L00207978
 *   declaration vs inferred signature: return void vs inferred u32
 */


static void InitS0051Event001(void *a0 /* r4 */) {
    u8 *s0;
    s32 a1;
    u32 v1;
    u32 v0;
    float f12;

    a1 = 0x14;
    s0 = (u8 *)a0;
    a0 = (void *)(s32)1;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
    a0 = (void *)(s32)(v0 << 3);
    v0 = (s32)((u8 *)a0 - v0);
    v1 = (u32)((u8 *)MdlMng + 0x5400);
    v0 = v0 << 6;
    a0 = (void *)(s32)0x62;
    v0 = v1 + (u32)v0;
    *(u32 *)(s0 + 0x34) = v0;
    v0 = CheckEventFlag((signed int)a0);
    a0 = (void *)(s32)0x6d3;
    if (v0 != 0) {
        v0 = CheckEventFlag((signed int)a0);
        if (v0 != 0 || (u32)GameSt[0x14] != (u32)1) {
            goto _L00207920;
        }
        v1 = 2;
        *(u32 *)(s0 + 0xc) = v1;
    } else {
        _L00207920:;
        a0 = (void *)(s32)0x6d3;
        v0 = CheckEventFlag((signed int)a0);
        a0 = (void *)(s32)0x546;
        if (v0 == 0) {
            v0 = CheckEventFlag((signed int)a0);
            if (v0 == 0 && (u32)GameSt[0x14] == 0) {
                goto _L00207978;
            }
        }
        a0 = (void *)*(s32 *)(s0 + 0x34);
        f12 = 0.0f;
        a1 = 2;
        ChangeAnimParam(a0, a1, 0.0f);
        f12 = 0.0f;
        a0 = (void *)*(s32 *)(s0 + 0x34);
        SetHokanFrame(a0, 0.0f);
        v1 = 5;
        *(u32 *)(s0 + 0xc) = v1;
    }
    _L00207978:;
    return;
}


/* PlayS0051Event001 @ 0x207670 .. 0x2078A8 (0x238 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x2076e0
 *   fpu: float literal 0x00000000 at 0x2076ec
 *   fpu: float literal 0x00000000 at 0x207720
 *   fpu: float literal 0x00000000 at 0x20774c
 *   fpu: float literal 0x00000000 at 0x207758
 *   delay: daddu at 0x207784 writes a register its branch at 0x207780 reads
 *   fpu: float literal 0x00000000 at 0x2077ac
 *   fpu: float literal 0x00000000 at 0x2077fc
 *   fpu: float literal 0x41a00000 at 0x207814
 *   fpu: float literal 0x00000000 at 0x207828
 *   fpu: float literal 0x00000000 at 0x207848
 *   declaration vs inferred signature: return void vs inferred u32
 */


static void PlayS0051Event001(void *a0 /* r4 */) {
    u8 *s1;
    u32 a1;
    u8 *s0;
    u32 v1;
    u32 v0;
    float f12;
    u32 s2;

    v1 = 4;
    s1 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    s0 = (u8 *)(MdlMng + 0x8c00);
    switch ((u32)(s32)a0) {
    case 2:
        v0 = GetCurCamID();
        a1 = 4;
        if (v0 == a1) {
            v0 = *(s32 *)(s1 + 0x20);
            if (v0 == 0) {
                f12 = 0.0f;
                a0 = (void *)*(s32 *)(s1 + 0x34);
                ChangeAnimParam(a0, a1, 0.0f);
                f12 = 0.0f;
                a0 = (void *)*(s32 *)(s1 + 0x34);
                SetHokanFrame(a0, 0.0f);
                v1 = *(s32 *)(s1 + 0x20);
                *(u32 *)(s1 + 0x20) = v1 + 1;
                break;
            } else {
                v0 = *(s32 *)(s1 + 0x34);
                a0 = (void *)*(s32 *)((v0 + 0x100));
                v0 = CheckAnimEndFrame(a0);
                if (v0 == 0) {
                    break;
                }
                a0 = (void *)*(s32 *)(s1 + 0x34);
                f12 = 0.0f;
                ChangeAnimParam(a0, 2, 0.0f);
                *(u32 *)(s1 + 0x20) = 0;
                *(u32 *)(s1 + 0xc) = 3;
                SetEventFlag(0x6d3);
                break;
            }
        } else {
            a0 = (void *)*(s32 *)(s1 + 0x34);
            f12 = 0.0f;
            ChangeAnimParam(a0, 2, 0.0f);
            f12 = 0.0f;
            a0 = (void *)*(s32 *)(s1 + 0x34);
            SetHokanFrame(a0, 0.0f);
            *(u32 *)(s1 + 0x20) = 0;
            break;
        }
    case 0:
        v0 = (u32)GetCamInfo();
        a0 = (void *)*(s32 *)(((u8 *)v0 + 4));
        if ((u32)(s32)a0 != (u32)4) {
            break;
        }
        v0 = CheckMyControlOff((void *)s0);
        a0 = (void *)(s32)1;
        if (v0 == 0) {
            break;
        }
        SetMyActFreeFlag((unsigned char)a0);
        SetMyControlOff();
        a0 = (void *)*(s32 *)(s1 + 0x34);
        f12 = 0.0f;
        ChangeAnimParam(a0, 1, 0.0f);
        SetEventFlag(0x546);
        *(u32 *)(s1 + 0xc) = 1;
        break;
    case 1:
        v0 = *(s32 *)(s1 + 0x34);
        s2 = *(s32 *)((v0 + 0x100));
        v0 = CheckAnimEndFrame((void *)s2);
        if (v0 != 0) {
            SetMyActFreeFlag(0);
            SetMyControlOn();
            a0 = (void *)*(s32 *)(s1 + 0x34);
            f12 = 0.0f;
            ChangeAnimParam(a0, 2, 0.0f);
            *(u32 *)(s1 + 0xc) = 5;
        } else {
            a0 = (void *)0;
        }
        f12 = 20.0f;
        v0 = CheckAnimNumFrame((void *)s2, 20.0f);
        if (v0 != 0) {
            f12 = 0.0f;
            ChangeAnimParam((void *)s0, 0x40, 0.0f);
        }
        a0 = (void *)*(s32 *)(s0 + 0x100);
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        ChangeAnimParam((void *)s0, 0, 0.0f);
        break;
    case 4:
        v1 = *(s32 *)(s1 + 0x10);
        v1 = v1 + 1;
        *(u32 *)(s1 + 0x10) = v1;
        if ((s32)v1 <= (s32)0x78) {
            break;
        }
        SetMyActFreeFlag(0);
        SetMyControlOn();
        *(u32 *)(s1 + 0xc) = 5;
        *(u32 *)(s1 + 0x10) = 0;
    }
    return;
}









/* ActiS0051Event001 @ 0x207560 .. 0x207668 (0x108 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x2075a0 writes a register its branch at 0x20759c reads
 *   delay: addiu at 0x207618 writes a register its branch at 0x207614 reads
 *   cfg: kept branch: 0x207594 if (..) goto .L002075D8
 */


static void ActiS0051Event001(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u8 *s0;
    unsigned int a1_2; // a1
    u8 *a0_2; // a0
    s32 branchcond_20759c;
    u32 v1;
    u32 v0;

    v1 = 1;
    s0 = (u8 *)a0;
    switch ((u32)(s32)a1) {
    case 1:
        v0 = GetCurCamID();
        a0_2 = (u8 *)(s32)4;
        if (v0 == (u32)(s32)a0_2) {
            a1_2 = *(s32 *)(s0 + 0xc);
            v1 = 3;
            branchcond_20759c = (u32)(s32)a1_2 != v1;
            a1_2 = 0x5f;
            if (branchcond_20759c) {
                goto _L002075D8;
            }
            EasyEneAppearEx((signed int)a0_2, a1_2, 0);
            SetEventFlag(0x6d3);
            a0_2 = (u8 *)(s32)1;
            SetMyActFreeFlag((unsigned char)a0_2);
            SetMyControlOff();
            v1 = 4;
            *(u32 *)(s0 + 0xc) = v1;
            *(u32 *)(s0 + 0x10) = 0;
            break;
        } else {
            _L002075D8:;
            a0_2 = (u8 *)*(s32 *)(s0 + 0x34);
            v1 = *(u8 *)a0_2;
            if (v1 == 0 || *(u8 *)(a0_2 + 2) != 0) {
                break;
            }
            a0_2 = (u8 *)*(s32 *)(s0 + 0xc);
            v1 = 5;
            if ((u32)(s32)a0_2 != v1) {
                break;
            }
            v0 = (u32)GetCamInfo();
            a0_2 = (u8 *)*(s32 *)(((u8 *)v0 + 4));
            v1 = 4;
            if ((u32)(s32)a0_2 != v1) {
                break;
            }
            a0_2 = (u8 *)(s32)0x559;
            v0 = CheckEventFlag((signed int)a0_2);
            a0_2 = (u8 *)(s32)0x559;
            if (v0 == 0) {
                SetEventFlag((signed int)a0_2);
                v0 = 0x60000;
                a0_2 = (u8 *)(0x60000 | 0xde32);
                KnMsgMng_SendMsg((signed int)a0_2);
                break;
            } else {
                v0 = 0x60000;
                a0_2 = (u8 *)(0x60000 | 0xde33);
                KnMsgMng_SendMsg((signed int)a0_2);
            }
        }
    }
    return;
}






/* InitS0051Event002 @ 0x207440 .. 0x207560 (0x120 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x20753c
 *   cfg: kept branch: 0x207490 if (..) goto .L002074B0
 *   cfg: kept goto: 0x2074a0 -> .L00207550
 */


static void InitS0051Event002(void *a0 /* r4 */) {
    u8 *s0;
    s32 a1;
    u32 v0;
    u32 v1;

    a1 = 0x25;
    s0 = (u8 *)a0;
    a0 = (void *)(s32)1;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
    a1 = v0 + 0x30;
    a0 = (void *)(s32)((u32)a1 << 3);
    v1 = (u32)MdlMng;
    a0 = (void *)((u8 *)a0 - a1);
    a0 = (void *)(s32)((u32)a0 << 6);
    v1 = (s32)((u8 *)MdlMng + (u32)(a0));
    *(u32 *)(s0 + 0x34) = v1;
    *(u32 *)(s0 + 0x38) = 0;
    v1 = GameSt[0x14];
    a0 = (void *)(s32)0x6cb;
    if (v1 == 0) {
        v0 = CheckEventFlag((signed int)a0);
        if (v0 == 0) {
            goto _L002074B0;
        }
    }
    v1 = 2;
    *(u32 *)(s0 + 0xc) = v1;
    goto _L00207550;
    _L002074B0:;
    a0 = (void *)(s32)0x6ca;
    v0 = CheckEventFlag((signed int)a0);
    a0 = (void *)(s32)3;
    if (v0 != 0) {
        EasyEneAppear((signed int)a0);
        a0 = (void *)(s32)2;
        a1 = 3;
        *(u32 *)(s0 + 0xc) = (s32)a0;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        a1 = v0 + 0xa1;
        a0 = (void *)(s32)((u32)a1 << 3);
        v1 = (u32)MdlMng;
        a0 = (void *)((u8 *)a0 - a1);
        a0 = (void *)(s32)((u32)a0 << 6);
        v1 = (s32)((u8 *)MdlMng + (u32)(a0));
        *(u32 *)(s0 + 0x38) = v1;
    } else {
        a0 = (void *)(s32)3;
        a1 = 0x52;
        EasyEneAppearEx((signed int)a0, a1, 1);
        a0 = (void *)(s32)2;
        a1 = 3;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        a0 = (void *)(s32)(v0 + 0xa1);
        v1 = (u32)a0 << 3;
        v1 = (s32)((u8 *)v1 - (u32)(a0));
        v0 = (u32)MdlMng;
        v1 = v1 << 6;
        v0 = (s32)((u8 *)MdlMng + v1);
        *(u32 *)(s0 + 0x38) = v0;
        a0 = (void *)*(s32 *)(s0 + 0x34);
        a1 = 0x1e;
        ChangeAnimParam(a0, a1, 0.0f);
        *(u32 *)(s0 + 0xc) = 0;
    }
    _L00207550:;
    return;
}















/* PlayS0051Event002 @ 0x207300 .. 0x207440 (0x140 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x41200000 at 0x207348
 *   fpu: float literal 0x40800000 at 0x207360
 *   fpu: float literal 0x00000000 at 0x2073a4
 *   fpu: float literal 0x00000000 at 0x2073b4
 *   cfg: kept branch: 0x207370 if (..) goto .L002073A0
 */
/* PlayS0051Event002 @ 0x207300 .. 0x207440 (0x140 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x41200000 at 0x207348
 *   fpu: float literal 0x40800000 at 0x207360
 *   fpu: float literal 0x00000000 at 0x2073a4
 *   fpu: float literal 0x00000000 at 0x2073b4
 *   declaration vs inferred signature: return void vs inferred u32
 */





static void PlayS0051Event002(void *a0 /* r4 */) {
    u8 *s0;
    s32 v1;
    u32 v0;
    float f12;
    float f1;
    float f0;

    v1 = 1;
    s0 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    switch ((u32)(s32)a0) {
    case 0:
        v0 = *(s32 *)(s0 + 0x38);
        f0 = Math_GetDist2((float *)(void *)(u32)(v0 + (u32)0x20), (float *)(u8 *)(MdlMng +
            0x8c10));
        v1 = 0x41200000;
        f1 = 10.0f;
        if (!(f0 <= 10.0f)) {
            break;
        }
        v0 = 0x40800000;
        f1 = 4.0f;
        if (!(f0 < 4.0f)) {
            v0 = CheckMyDash((void *)(u8 *)(MdlMng + 0x8c00));
            if (v0 == 0) {
                a0 = (void *)*(s16 *)(MdlMng + 0x8c82);
                if ((s32)a0 < (s32)0x29 || (s32)a0 > (s32)0x2b) {
                    break;
                }
            }
        }
        f12 = 0.0f;
        ChangeAnimParam((void *)*(s32 *)(s0 + 0x34), 0, 0.0f);
        a0 = (void *)*(s32 *)(s0 + 0x38);
        f12 = 0.0f;
        ChangeAnimParam(a0, 0x53, 0.0f);
        a0 = (void *)(s32)0x6ca;
        *(u32 *)(s0 + 0xc) = 1;
        SetEventFlag((signed int)a0);
        break;
    case 1:
        v0 = *(s32 *)(s0 + 0x38);
        a0 = (void *)*(s32 *)((v0 + 0x100));
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        a0 = (void *)*(s32 *)(((u8 *)*(s32 *)(s0 + 0x38) + 0x148));
        *(u8 *)(((u8 *)a0 + 0x182)) = 1;
        *(u32 *)(s0 + 0xc) = 2;
    }
    a0 = (void *)*(s32 *)(s0 + 0x38);
    if ((u32)(s32)a0 != 0) {
        v0 = CheckEneDead(a0);
        a0 = (void *)(s32)0x6cb;
        if (v0 != 0) {
            SetEventFlag((signed int)a0);
        }
    }
    return;
}

