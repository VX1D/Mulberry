#include "common.h"

/* ActiS0040Event000 @ 0x210EA0 .. 0x211174 (0x2d4 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x210fc0 if (..) goto .L00211018
 */

extern signed int KnMsgMng_SendMsg(signed int);
extern signed int CheckEventFlag(signed int);
extern void SetEventFlag(signed int);
extern u8 GameSt[];

/* PlayS0040Event000 @ 0x211180 .. 0x211238 (0xb8 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x21119c writes a register its branch at 0x211198 reads
 *   delay: addiu at 0x2111d4 writes a register its branch at 0x2111d0 reads
 *   delay: addiu at 0x2111f4 writes a register its branch at 0x2111f0 reads
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 GetCamInfo();
extern void FreeMdlMng(void *);
extern void SetEventFlag(signed int);

/* InitS0040Event000 @ 0x211240 .. 0x2113AC (0x16c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   v0#7 is the pointer held in a0+0x38
 *   v0#11 is the pointer held in a0+0x3c
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);

extern signed int SFX_Create_OnAng(unsigned short, float *, float *);
extern u32 MdlMng[];

extern u32 V0[];

/* SetEventFuncS0040 @ 0x2113B0 .. 0x2113E4 (0x34 bytes) */
/*
 * dcomp notes:
 *   repo declaration vs inferred signature: return void vs inferred u8 *
 */


extern u32 EventMngSt[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetEventFuncS0040(void);
static void InitS0040Event000(void *a0 );
static void PlayS0040Event000(void *a0 );
static void ActiS0040Event000(void *a0 , unsigned int a1 );




void SetEventFuncS0040(void) {
    u8 *v1;

    v1 = (u8 *)InitS0040Event000;
    *(u32 *)EventMngSt = (u32)InitS0040Event000;
    v1 = (u8 *)PlayS0040Event000;
    *(u32 *)((u8 *)&EventMngSt + 4) = (u32)PlayS0040Event000;
    v1 = (u8 *)ActiS0040Event000;
    *(u32 *)((u8 *)&EventMngSt + 8) = (u32)ActiS0040Event000;
    return;
}

static void InitS0040Event000(void *a0 /* r4 */) {
    u8 *s1;
    u8 *s0;
    u32 v0;
    u32 v1;
    u8 *a2;

    s1 = (u8 *)a0;
    s0 = (u8 *)MdlMng + 0x5400;
    v0 = GetMdlMngIndexByCtrlId(1, 6);
    a0 = (void *)(s32)1;
    v0 = (u32)(v0) * (u32)(7);
    v0 = v0 << 6;
    *(u32 *)(s1 + 0x34) = (s32)(s0 + v0);
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, 8);
    a0 = (void *)(s32)1;
    v0 = (u32)(v0) * (u32)(7);
    v0 = v0 << 6;
    *(u32 *)(s1 + 0x38) = (s32)(s0 + v0);
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, 0xd);
    v1 = v0 << 3;
    v0 = (u32)(v0) * (u32)(7);
    v0 = v0 << 6;
    *(u32 *)(s1 + 0x3c) = (s32)(s0 + v0);
    v0 = GameSt[0x14];
    if (v0 != 0) {
        a0 = (void *)*(s32 *)(s1 + 0x34);
        FreeMdlMng(a0);
        a0 = (void *)*(s32 *)(s1 + 0x38);
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
            *(u32 *)(s1 + 0xc) = 0;
        } else {
            v0 = CheckEventFlag(0x545);
            if (v0 != 0) {
                v0 = *(s32 *)(s1 + 0x34);
                a2 = (u8 *)V0;
                SFX_Create_OnAng(0x2c8, (float *)(u32)(v0 + 0x20), (float *)V0);
                a0 = (void *)*(s32 *)(s1 + 0x34);
                FreeMdlMng(a0);
                v0 = CheckEventFlag(0x549);
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
                v1 = *(s32 *)(s1 + 0x3c);
                *(u8 *)((v1 + 2)) = (s32)a0;
                *(u32 *)(s1 + 0xc) = (s32)a0;
            }
        }
    }
    return;
}

static void PlayS0040Event000(void *a0 /* r4 */) {
    u32 *s0;
    s32 v1;
    u8 *v0;

    v1 = 3;
    s0 = (u32 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    switch ((u32)(s32)a0) {
    case 1:
        v0 = (u8 *)GetCamInfo();
        a0 = (void *)*(s32 *)(((u8 *)v0 + 4));
        v1 = 0xd;
        if ((u32)(s32)a0 != (u32)v1) {
            break;
        }
        v1 = 2;
        *(u32 *)(((u8 *)s0 + 0xc)) = v1;
        break;
    case 2:
        v0 = (u8 *)GetCamInfo();
        a0 = (void *)*(s32 *)(((u8 *)v0 + 4));
        v1 = 1;
        if ((u32)(s32)a0 != (u32)v1) {
            v1 = 3;
            if ((u32)(s32)a0 != (u32)v1) {
                break;
            }
        }
        a0 = (void *)*(s32 *)(((u8 *)s0 + 0x34));
        FreeMdlMng(a0);
        v0 = (u8 *)*(s32 *)(((u8 *)s0 + 0x38));
        a0 = (void *)(s32)0x545;
        *(u8 *)(((u8 *)v0 + 2)) = 0;
        v0 = (u8 *)*(s32 *)(((u8 *)s0 + 0x3c));
        *(u8 *)(((u8 *)v0 + 2)) = 0;
        SetEventFlag((signed int)a0);
        v1 = 3;
        *(u32 *)(((u8 *)s0 + 0xc)) = v1;
    case 3:
        break;
    }
    return;
}

static void ActiS0040Event000(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u32 v1;
    s32 v0;

    v1 = 3;
    if ((u32)(s32)a1 != v1) {
        v1 = 2;
        if ((u32)(s32)a1 != v1) {
            v1 = 1;
            switch ((u32)(s32)a1) {
            case 1:
                a0 = (void *)*(s32 *)(((u8 *)a0 + 0x34));
                v1 = *(u8 *)a0;
                if (v1 == 0 || (u32)*(u8 *)(((u8 *)a0 + 2)) != 0) {
                    break;
                }
                v0 = 0x60000;
                a0 = (void *)(0x60000 | 0xb6f2);
                KnMsgMng_SendMsg((signed int)a0);
                break;
            }
        } else {
            a0 = (void *)GameSt[0x14];
            if ((u32)a0 != v1) {
                v1 = 1;
                switch ((u32)a0) {
                case 0:
                    a0 = (void *)(s32)0x41a;
                    v0 = CheckEventFlag((signed int)a0);
                    if ((u32)v0 != 0) {
                        v0 = 0x60000;
                        a0 = (void *)(0x60000 | 0xb6f9);
                        KnMsgMng_SendMsg((signed int)a0);
                        break;
                    } else {
                        a0 = (void *)(s32)0x4b7;
                        v0 = CheckEventFlag((signed int)a0);
                        a0 = (void *)(s32)0x54f;
                        if ((u32)v0 != 0) {
                            v0 = CheckEventFlag((signed int)a0);
                            a0 = (void *)(s32)0x54f;
                            if ((u32)v0 == 0) {
                                SetEventFlag((signed int)a0);
                                v0 = 0x60000;
                                a0 = (void *)(0x60000 | 0xb6f7);
                                KnMsgMng_SendMsg((signed int)a0);
                                break;
                            } else {
                                v0 = 0x60000;
                                a0 = (void *)(0x60000 | 0xb6f8);
                                KnMsgMng_SendMsg((signed int)a0);
                                break;
                            }
                        } else {
                            a0 = (void *)(s32)0x543;
                            v0 = CheckEventFlag((signed int)a0);
                            a0 = (void *)(s32)0x545;
                            if ((u32)v0 != 0) {
                                v0 = CheckEventFlag((signed int)a0);
                                if ((u32)v0 != 0) {
                                    goto _L00211018;
                                }
                            }
                            a0 = (void *)(s32)0x54e;
                            v0 = CheckEventFlag((signed int)a0);
                            a0 = (void *)(s32)0x54e;
                            if ((u32)v0 == 0) {
                                SetEventFlag((signed int)a0);
                                v0 = 0x60000;
                                a0 = (void *)(0x60000 | 0xb701);
                                KnMsgMng_SendMsg((signed int)a0);
                                break;
                            } else {
                                v0 = 0x60000;
                                a0 = (void *)(0x60000 | 0xb702);
                                KnMsgMng_SendMsg((signed int)a0);
                                break;
                                _L00211018:;
                                v0 = 0x60000;
                                a0 = (void *)(0x60000 | 0xb6f6);
                                KnMsgMng_SendMsg((signed int)a0);
                                break;
                            }
                        }
                    }
                case 1:
                    a0 = (void *)(s32)0x41a;
                    v0 = CheckEventFlag((signed int)a0);
                    if ((u32)v0 != 0) {
                        v0 = 0x60000;
                        a0 = (void *)(0x60000 | 0xb6f9);
                        KnMsgMng_SendMsg((signed int)a0);
                        break;
                    } else {
                        a0 = (void *)(s32)0x4b7;
                        v0 = CheckEventFlag((signed int)a0);
                        a0 = (void *)(s32)0x54f;
                        if ((u32)v0 != 0) {
                            v0 = CheckEventFlag((signed int)a0);
                            a0 = (void *)(s32)0x54f;
                            if ((u32)v0 == 0) {
                                SetEventFlag((signed int)a0);
                                v0 = 0x60000;
                                a0 = (void *)(0x60000 | 0xb6f7);
                                KnMsgMng_SendMsg((signed int)a0);
                                break;
                            } else {
                                v0 = 0x60000;
                                a0 = (void *)(0x60000 | 0xb6f8);
                                KnMsgMng_SendMsg((signed int)a0);
                                break;
                            }
                        } else {
                            a0 = (void *)(s32)0x54e;
                            v0 = CheckEventFlag((signed int)a0);
                            a0 = (void *)(s32)0x54e;
                            if ((u32)v0 == 0) {
                                SetEventFlag((signed int)a0);
                                v0 = 0x60000;
                                a0 = (void *)(0x60000 | 0xb701);
                                KnMsgMng_SendMsg((signed int)a0);
                                break;
                            } else {
                                v0 = 0x60000;
                                a0 = (void *)(0x60000 | 0xb702);
                                KnMsgMng_SendMsg((signed int)a0);
                                break;
                            }
                        }
                    }
                }
            } else {
                v0 = CheckEventFlag(0x54e);
                a0 = (void *)(s32)0x54e;
                if ((u32)v0 == 0) {
                    SetEventFlag((signed int)a0);
                    v0 = 0x60000;
                    KnMsgMng_SendMsg(0x60000 | 0xb701);
                } else {
                    v0 = 0x60000;
                    KnMsgMng_SendMsg(0x60000 | 0xb702);
                }
            }
        }
    } else {
        a0 = (void *)*(s32 *)(((u8 *)a0 + 0x3c));
        v1 = *(u8 *)a0;
        if (v1 != 0 && (u32)*(u8 *)(((u8 *)a0 + 2)) == 0) {
            v0 = 0x60000;
            KnMsgMng_SendMsg(0x60000 | 0xb6f5);
        }
    }
    return;
}
