#include "common.h"

/* PlayS0035Event005 @ 0x20FBF0 .. 0x20FCF0 (0x100 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x20fc18 writes a register its branch at 0x20fc14 reads
 *   fpu: float literal 0x41100000 at 0x20fc68
 *   fpu: float literal 0x00000000 at 0x20fc80
 *   fpu: float literal 0x4123d70b at 0x20fcb4
 *   fpu: float literal 0x00000000 at 0x20fccc
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int CheckEventFlag(signed int);
extern float Math_GetDist2(float *, float *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern u8 GameSt[];
extern u32 MdlMng[];

/* InitS0035Event005 @ 0x20FCF0 .. 0x20FD60 (0x70 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern signed int CheckEventFlag(signed int);
extern u8 GameSt[];
extern u32 MdlMng[];

/* ActiS0035Event001 @ 0x20FD60 .. 0x20FDE8 (0x88 bytes, frame 0x20) */

extern void SetMyControlOff();
extern void SetEventFlag(signed int);
extern signed int KnMsgMng_SendMsg(signed int);

/* PlayS0035Event001 @ 0x20FDF0 .. 0x20FE60 (0x70 bytes, frame 0x20) */

extern signed int KnMsgMng_SendMsg(signed int);

/* InitS0035Event001 @ 0x20FE60 .. 0x20FEF4 (0x94 bytes, frame 0x30) */

extern void FreeMdlMng(void *);

/* ActiS0035Event000 @ 0x20FF00 .. 0x20FFFC (0xfc bytes, frame 0x10) */

extern void SetEventFlag(signed int);

/* PlayS0035Event000 @ 0x210000 .. 0x2100C8 (0xc8 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x21001c writes a register its branch at 0x210018 reads
 *   delay: addiu at 0x210050 writes a register its branch at 0x21004c reads
 *   delay: addiu at 0x210074 writes a register its branch at 0x210070 reads
 *   cfg: kept branch: 0x210074 if (..) goto .L00210090
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 GetCamInfo();
extern void FreeMdlMng(void *);

/* InitS0035Event000 @ 0x2100D0 .. 0x210274 (0x1a4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   v0#7 is the pointer held in a0+0x38
 *   v0#15 is the pointer held in a0+0x40
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int SFX_Create_OnAng(unsigned short, float *, float *);
extern u32 V0[];

/* SetEventFuncS0035 @ 0x210280 .. 0x210304 (0x84 bytes) */
/*
 * dcomp notes:
 *   repo declaration vs inferred signature: return void vs inferred u8 *
 */


extern u32 EventMngSt[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetEventFuncS0035(void);
static void InitS0035Event000(void *a0 );
static void PlayS0035Event000(void *a0 );
static void ActiS0035Event000(void *a0 , unsigned int a1 );
static void InitS0035Event001(void *a0 );
static void PlayS0035Event001(void *a0 );
static void ActiS0035Event001(void *a0 , unsigned int a1 );
static void InitS0035Event005(void *a0 );
static void PlayS0035Event005(void *a0 );









void SetEventFuncS0035(void) {
    u8 *v1;

    v1 = (u8 *)InitS0035Event000;
    *(u32 *)EventMngSt = (u32)InitS0035Event000;
    v1 = (u8 *)PlayS0035Event000;
    *(u32 *)((u8 *)&EventMngSt + 4) = (u32)PlayS0035Event000;
    v1 = (u8 *)ActiS0035Event000;
    *(u32 *)((u8 *)&EventMngSt + 8) = (u32)ActiS0035Event000;
    v1 = (u8 *)InitS0035Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x60) = (u32)InitS0035Event001;
    v1 = (u8 *)PlayS0035Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x64) = (u32)PlayS0035Event001;
    v1 = (u8 *)ActiS0035Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x68) = (u32)ActiS0035Event001;
    v1 = (u8 *)InitS0035Event005;
    *(u32 *)((u8 *)&EventMngSt + 0x1e0) = (u32)InitS0035Event005;
    v1 = (u8 *)PlayS0035Event005;
    *(u32 *)((u8 *)&EventMngSt + 0x1e4) = (u32)PlayS0035Event005;
    return;
}

static void InitS0035Event000(void *a0 /* r4 */) {
    u8 *s1;
    u8 *s0;
    u32 v0;
    u32 v1;
    u8 *a2;

    s1 = (u8 *)a0;
    s0 = (u8 *)MdlMng + 0x5400;
    v0 = GetMdlMngIndexByCtrlId(1, 0x11);
    a0 = (void *)(s32)1;
    v0 = (u32)(v0) * (u32)(7);
    v0 = v0 << 6;
    *(u32 *)(s1 + 0x34) = (s32)(s0 + v0);
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, 0x13);
    a0 = (void *)(s32)7;
    v0 = (u32)(v0) * (u32)(7);
    v0 = v0 << 6;
    *(u32 *)(s1 + 0x38) = (s32)(s0 + v0);
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, 1);
    a0 = (void *)(s32)(v0 << 3);
    v0 = (s32)((u8 *)a0 - v0);
    a0 = (void *)(s32)1;
    *(u32 *)(s1 + 0x3c) = (u32)((u8 *)MdlMng + 0xfc00) + (u32)(v0 << 6);
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, 0x14);
    v1 = v0 << 3;
    v0 = (u32)(v0) * (u32)(7);
    v0 = v0 << 6;
    *(u32 *)(s1 + 0x40) = (s32)(s0 + v0);
    v0 = GameSt[0x14];
    if (v0 != 0) {
        a0 = (void *)*(s32 *)(s1 + 0x34);
        FreeMdlMng(a0);
        a0 = (void *)*(s32 *)(s1 + 0x38);
        FreeMdlMng(a0);
        a0 = (void *)*(s32 *)(s1 + 0x3c);
        FreeMdlMng(a0);
        *(u32 *)(s1 + 0xc) = 0;
    } else {
        v0 = CheckEventFlag(0x543);
        if (v0 == 0) {
            a0 = (void *)*(s32 *)(s1 + 0x34);
            FreeMdlMng(a0);
            a0 = (void *)*(s32 *)(s1 + 0x38);
            FreeMdlMng(a0);
            a0 = (void *)*(s32 *)(s1 + 0x3c);
            FreeMdlMng(a0);
            a0 = (void *)*(s32 *)(s1 + 0x40);
            FreeMdlMng(a0);
            *(u32 *)(s1 + 0xc) = 0;
        } else {
            v0 = CheckEventFlag(0x544);
            if (v0 != 0) {
                v0 = *(s32 *)(s1 + 0x34);
                a2 = (u8 *)V0;
                SFX_Create_OnAng(0x2c8, (float *)(u32)(v0 + 0x20), (float *)V0);
                a0 = (void *)*(s32 *)(s1 + 0x34);
                FreeMdlMng(a0);
                v0 = CheckEventFlag(0x545);
                if (v0 != 0) {
                    a0 = (void *)*(s32 *)(s1 + 0x38);
                    FreeMdlMng(a0);
                }
            } else {
                v0 = *(s32 *)(s1 + 0x34);
                a2 = (u8 *)V0;
                SFX_Create_OnAng(0x2c8, (float *)(u32)(v0 + 0x20), (float *)V0);
                v1 = *(s32 *)(s1 + 0x38);
                a0 = (void *)(s32)1;
                *(u8 *)((v1 + 2)) = (s32)a0;
                v1 = *(s32 *)(s1 + 0x40);
                *(u8 *)((v1 + 2)) = (s32)a0;
                *(u32 *)(s1 + 0xc) = (s32)a0;
            }
        }
    }
    return;
}


static void PlayS0035Event000(void *a0 /* r4 */) {
    u32 *s0;
    u32 v1;
    u8 *v0;

    v1 = 3;
    s0 = (u32 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    switch ((u32)(s32)a0) {
    case 1:
        v0 = (u8 *)GetCamInfo();
        v1 = *(s32 *)(((u8 *)v0 + 4));
        if (v1 != 0) {
            break;
        }
        v1 = 2;
        *(u32 *)(((u8 *)s0 + 0xc)) = v1;
        break;
    case 2:
        v0 = (u8 *)GetCamInfo();
        a0 = (void *)*(s32 *)(((u8 *)v0 + 4));
        v1 = 1;
        if ((u32)(s32)a0 != v1) {
            v1 = 3;
            if ((u32)(s32)a0 == v1) {
                goto _L00210090;
            }
            v1 = 7;
            if ((u32)(s32)a0 != v1) {
                break;
            }
        }
        _L00210090:;
        a0 = (void *)*(s32 *)(((u8 *)s0 + 0x34));
        FreeMdlMng(a0);
        v0 = (u8 *)*(s32 *)(((u8 *)s0 + 0x38));
        a0 = (void *)(s32)0x544;
        *(u8 *)(((u8 *)v0 + 2)) = 0;
        v0 = (u8 *)*(s32 *)(((u8 *)s0 + 0x40));
        *(u8 *)(((u8 *)v0 + 2)) = 0;
        SetEventFlag((signed int)a0);
        v1 = 3;
        *(u32 *)(((u8 *)s0 + 0xc)) = v1;
    case 3:
        break;
    }
    return;
}


static void ActiS0035Event000(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u32 v1;
    s32 v0;

    v1 = 2;
    switch ((u32)(s32)a1) {
    case 1:
        a0 = (void *)*(s32 *)(((u8 *)a0 + 0x34));
        v1 = *(u8 *)a0;
        if (v1 == 0) {
            break;
        }
        v1 = *(u8 *)(((u8 *)a0 + 2));
        if (v1 != 0) {
            break;
        }
        a0 = (void *)(s32)0x54c;
        v0 = CheckEventFlag((signed int)a0);
        a0 = (void *)(s32)0x54c;
        if ((u32)v0 == 0) {
            SetEventFlag((signed int)a0);
            v0 = 0x60000;
            a0 = (void *)(0x60000 | 0x8ffb);
            KnMsgMng_SendMsg((signed int)a0);
            break;
        } else {
            v0 = 0x60000;
            a0 = (void *)(0x60000 | 0x9003);
            KnMsgMng_SendMsg((signed int)a0);
            v0 = 0x60000;
            a0 = (void *)(0x60000 | 0x9004);
            KnMsgMng_SendMsg((signed int)a0);
            break;
        }
    case 2:
        a0 = (void *)*(s32 *)(((u8 *)a0 + 0x38));
        v1 = *(u8 *)a0;
        if (v1 == 0) {
            break;
        }
        v1 = *(u8 *)(((u8 *)a0 + 2));
        if (v1 != 0) {
            break;
        }
        a0 = (void *)(s32)0x54d;
        v0 = CheckEventFlag((signed int)a0);
        a0 = (void *)(s32)0x54d;
        if ((u32)v0 == 0) {
            SetEventFlag((signed int)a0);
            v0 = 0x60000;
            a0 = (void *)(0x60000 | 0x9005);
            KnMsgMng_SendMsg((signed int)a0);
            break;
        } else {
            v0 = 0x60000;
            a0 = (void *)(0x60000 | 0x9006);
            KnMsgMng_SendMsg((signed int)a0);
            v0 = 0x60000;
            a0 = (void *)(0x60000 | 0x9007);
            KnMsgMng_SendMsg((signed int)a0);
        }
    }
    return;
}

static void InitS0035Event001(void *a0 /* r4 */) {
    u8 *s1;
    u8 *s0;
    u32 v0;
    u8 v1;

    s1 = (u8 *)a0;
    s0 = (u8 *)MdlMng + 0x5400;
    v0 = GetMdlMngIndexByCtrlId(1, 0x15);
    a0 = (void *)(s32)1;
    *(u32 *)(s1 + 0x34) = (s32)(s0 + (u32)((u32)((u32)(v0) * (u32)(7)) << 6));
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, 0x18);
    *(u32 *)(s1 + 0x38) = (s32)(s0 + (u32)((u32)(v0) * (u32)(0x1c0)));
    v1 = GameSt[0x14];
    if ((u32)v1 == 0) {
        FreeMdlMng((void *)*(s32 *)(s1 + 0x34));
        FreeMdlMng((void *)*(s32 *)(s1 + 0x38));
    }
    return;
}

static void PlayS0035Event001(void *a0 /* r4 */) {
    u32 *s0;
    s32 a1;
    s32 v1;

    a1 = 2;
    s0 = (u32 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    v1 = 1;
    switch ((u32)(s32)a0) {
    case 1:
        a0 = (void *)*(s32 *)(((u8 *)s0 + 0x10));
        v1 = 0x3c;
        a0 = (void *)(s32)((u8 *)a0 + 1);
        *(u32 *)(((u8 *)s0 + 0x10)) = (s32)a0;
        if ((u32)(s32)a0 != (u32)v1) {
            break;
        }
        *(u32 *)(((u8 *)s0 + 0xc)) = a1;
        break;
    case 2:
        a0 = (void *)(0x60000 | 0x9009);
        KnMsgMng_SendMsg((signed int)a0);
        *(u32 *)(((u8 *)s0 + 0xc)) = 0;
    }
    return;
}

static void ActiS0035Event001(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u8 *s0;
    u32 v1;
    s32 v0;

    v1 = 1;
    s0 = (u8 *)a0;
    switch ((u32)(s32)a1) {
    case 1:
        a0 = (void *)*(s32 *)(s0 + 0x34);
        v1 = *(u8 *)a0;
        if (v1 == 0 || (u32)*(u8 *)(((u8 *)a0 + 2)) != 0) {
            break;
        }
        a0 = (void *)(s32)0x55a;
        v0 = CheckEventFlag((signed int)a0);
        if ((u32)v0 == 0) {
            v0 = 2;
            *(u32 *)(s0 + 0xc) = v0;
            SetMyControlOff();
            a0 = (void *)(s32)0x55a;
            SetEventFlag((signed int)a0);
            break;
        } else {
            v0 = 0x60000;
            a0 = (void *)(0x60000 | 0x900a);
            KnMsgMng_SendMsg((signed int)a0);
        }
    }
    return;
}

static void InitS0035Event005(void *a0 /* r4 */) {
    u32 v1;
    u32 *s0;
    s32 a1;
    u32 v0;

    v1 = *(u8 *)((u8 *)&GameSt + 0x14);
    s0 = (u32 *)a0;
    if (v1 == 0) {
        a0 = (void *)(s32)1;
        a1 = 2;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        a1 = v0 + 0x30;
        a0 = (void *)(s32)0x40f;
        v0 = (u32)MdlMng;
        v1 = (u32)((u32)a1) * (u32)(0x1c0);
        v0 = (s32)((u8 *)MdlMng + v1);
        *(u32 *)(((u8 *)s0 + 0x34)) = v0;
        v0 = CheckEventFlag((signed int)a0);
        v1 = 1;
        if (v0 == 0) {
            *(u32 *)(((u8 *)s0 + 0x10)) = v1;
        }
    }
    return;
}

static void PlayS0035Event005(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u32 v0;
    u32 a1;
    float f0;
    float f1;
    s32 fpcc;
    float f12;

    v1 = GameSt[0x14];
    s0 = (u8 *)a0;
    if (v1 == 0) {
        a0 = (void *)*(s32 *)(s0 + 0x10);
        v1 = 2;
        switch ((u32)(s32)a0) {
        case 1:
            a0 = (void *)(s32)0x40f;
            v0 = CheckEventFlag((signed int)a0);
            v1 = 1;
            if (v0 == v1) {
                *(u32 *)(s0 + 0x10) = 0;
                break;
            } else {
                v0 = *(s32 *)(s0 + 0x34);
                a1 = (u32)((u8 *)MdlMng + 0x11820);
                a0 = (void *)(s32)(v0 + 0x20);
                f0 = Math_GetDist2((float *)a0, (float *)a1);
                v1 = 0x41100000;
                f1 = 9.0f;
                fpcc = f0 < 9.0f;
                if (!fpcc) {
                    break;
                }
                a0 = (void *)*(s32 *)(s0 + 0x34);
                f12 = 0.0f;
                a1 = 0x1e;
                ChangeAnimParam(a0, a1, 0.0f);
                v1 = 2;
                *(u32 *)(s0 + 0x10) = v1;
                break;
            }
        case 2:
            v0 = *(s32 *)(s0 + 0x34);
            a1 = (u32)((u8 *)MdlMng + 0x11820);
            a0 = (void *)(s32)(v0 + 0x20);
            f0 = Math_GetDist2((float *)a0, (float *)a1);
            v1 = 0x4123d70b;
            f1 = 10.2400007f;
            fpcc = f0 <= 10.2400007f;
            if (fpcc) {
                break;
            }
            a0 = (void *)*(s32 *)(s0 + 0x34);
            f12 = 0.0f;
            ChangeAnimParam(a0, 0, 0.0f);
            v1 = 1;
            *(u32 *)(s0 + 0x10) = v1;
        }
    }
    return;
}
