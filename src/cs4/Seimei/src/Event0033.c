#include "common.h"

/* PlayS0033Event000 @ 0x210740 .. 0x210DAC (0x66c bytes, frame 0x40) */
/*
 * dcomp notes:
 *   quad: a1: 128-bit web split from its scalar uses
 *   literal: @670 -> 0x250330
 *   stack: address of the slot at 0x30 escapes at 0x2107a0
 *   fpu: mov.s at 0x2107e4 is a float copy
 *   fpu: mov.s at 0x2107ec is a float copy
 *   fpu: float literal 0x40490fdb at 0x2107f8
 *   fpu: float literal 0x00000000 at 0x2107fc
 *   fpu: mov.s at 0x210810 is a float copy
 *   fpu: mov.s at 0x210814 is a float copy
 *   fpu: mov.s at 0x21081c is a float copy
 *   fpu: float literal 0x40490fdb at 0x210830
 *   fpu: float literal 0x40c90fdb at 0x210834
 *   fpu: mov.s at 0x21084c is a float copy
 *   fpu: mov.s at 0x210858 is a float copy
 *   fpu: mov.s at 0x210868 is a float copy
 *   fpu: float literal 0x40490fdb at 0x21087c
 *   fpu: float literal 0x40c90fdb at 0x210880
 *   fpu: mov.s at 0x210898 is a float copy
 *   fpu: mov.s at 0x2108a4 is a float copy
 *   fpu: float literal 0x40c90fdb at 0x2108b4
 *   fpu: float literal 0x40490fdb at 0x2108c8
 *   fpu: float literal 0x00000000 at 0x2108cc
 *   fpu: float literal 0x40c90fdb at 0x2108f0
 *   fpu: mtc1 reinterprets v1 at 0x210914
 *   fpu: float literal 0x4109999a at 0x21094c
 *   fpu: float literal 0xc1b80000 at 0x210968
 *   fpu: mov.s at 0x210994 is a float copy
 *   fpu: mov.s at 0x21099c is a float copy
 *   fpu: float literal 0x40490fdb at 0x2109a8
 *   fpu: float literal 0x00000000 at 0x2109ac
 *   fpu: mov.s at 0x2109c0 is a float copy
 *   fpu: mov.s at 0x2109c4 is a float copy
 *   fpu: mov.s at 0x2109cc is a float copy
 *   fpu: float literal 0x40490fdb at 0x2109e0
 *   fpu: float literal 0x40c90fdb at 0x2109e4
 *   fpu: mov.s at 0x2109fc is a float copy
 *   fpu: mov.s at 0x210a08 is a float copy
 *   fpu: mov.s at 0x210a18 is a float copy
 *   fpu: float literal 0x40490fdb at 0x210a2c
 *   fpu: float literal 0x40c90fdb at 0x210a30
 *   fpu: mov.s at 0x210a48 is a float copy
 *   fpu: mov.s at 0x210a54 is a float copy
 *   fpu: float literal 0x40c90fdb at 0x210a64
 *   fpu: mov.s at 0x210a74 is a float copy
 *   fpu: mov.s at 0x210a7c is a float copy
 *   fpu: mov.s at 0x210aa0 is a float copy
 *   fpu: mov.s at 0x210aa8 is a float copy
 *   fpu: float literal 0x40490fdb at 0x210ab4
 *   fpu: float literal 0x00000000 at 0x210ab8
 *   fpu: mov.s at 0x210acc is a float copy
 *   fpu: mov.s at 0x210ad0 is a float copy
 *   fpu: mov.s at 0x210ad8 is a float copy
 *   fpu: float literal 0x40490fdb at 0x210aec
 *   fpu: float literal 0x40c90fdb at 0x210af0
 *   fpu: mov.s at 0x210b08 is a float copy
 *   fpu: mov.s at 0x210b14 is a float copy
 *   fpu: mov.s at 0x210b24 is a float copy
 *   fpu: float literal 0x40490fdb at 0x210b38
 *   fpu: float literal 0x40c90fdb at 0x210b3c
 *   fpu: mov.s at 0x210b54 is a float copy
 *   fpu: mov.s at 0x210b60 is a float copy
 *   fpu: float literal 0x40c90fdb at 0x210b70
 *   fpu: float literal 0x40490fdb at 0x210b84
 *   fpu: float literal 0x00000000 at 0x210b88
 *   fpu: float literal 0x40c90fdb at 0x210bac
 *   fpu: mtc1 reinterprets v0 at 0x210bd0
 *   fpu: mov.s at 0x210bf4 is a float copy
 *   fpu: mov.s at 0x210bf8 is a float copy
 *   delay: lui at 0x210c14 writes a register its branch at 0x210c10 reads
 *   fpu: float literal 0x3eb2b020 at 0x210c1c
 *   fpu: float literal 0x00000000 at 0x210c30
 *   fpu: float literal 0xbeb2b020 at 0x210c50
 *   fpu: float literal 0x00000000 at 0x210c64
 *   fpu: float literal 0xbeb2b020 at 0x210c80
 *   fpu: float literal 0x3eb2b020 at 0x210c98
 *   fpu: float literal 0x00000000 at 0x210cac
 *   fpu: float literal 0x402aded2 at 0x210cc0
 *   fpu: float literal 0xc027851e at 0x210cd8
 *   fpu: float literal 0x00000000 at 0x210d34
 *   fpu: float literal 0xc1b80000 at 0x210d50
 *   literal: @670 initializes the 16-byte local at 0x30
 *   cfg: kept branch: 0x210960 if (..) goto .L00210D20
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern float Math_VectorToAngle(float, float);
extern float Math_GetAngleDist(float, float);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetObjMovePath(void *, signed int, unsigned short, unsigned short);
extern void FreeMdlMng(void *);
extern void SetEventFlag(signed int);


struct dw_2906456_fields;
struct dw_2912092_fields;
#ifndef PROTO_DW_2911493_FIELDS
#define PROTO_DW_2911493_FIELDS
struct dw_2911493_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_2909721_FIELDS
#define PROTO_DW_2909721_FIELDS
struct dw_2909721_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_2909399_FIELDS
#define PROTO_DW_2909399_FIELDS
struct dw_2909399_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_2906456_fields *lpMdl; };
#endif
#ifndef PROTO_DW_2906456_FIELDS
#define PROTO_DW_2906456_FIELDS
struct dw_2906456_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_2912092_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_2906456_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_2911493_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_2909721_fields flags; unsigned char _pad1[3]; struct dw_2909399_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_2911702_FIELDS
#define PROTO_DW_2911702_FIELDS
struct dw_2911702_fields { void *InitFunc; void *PlayFunc; void *ActiFunc; int State[10]; struct dw_2906456_fields *lpMdl[10]; unsigned char _pad0[4]; };
#endif

#define CAE_PI 3.14159274f
#define CAE_WRAPF(a) ((3.14159274f + (a) >= 0.0f) ? ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f)) : (6.28318548f + ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f))))
extern u32 MdlMng[];


/* InitS0033Event000 @ 0x210DB0 .. 0x210E70 (0xc0 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x210e24
 *   cfg: kept branch: 0x210df8 if (..) goto .L00210E20
 *   cfg: kept goto: 0x210e08 -> .L00210E60
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern signed int CheckEventFlag(signed int);
extern void FreeMdlMng(void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern u32 MdlMng[];
extern u8 GameSt[];

/* SetEventFuncS0033 @ 0x210E70 .. 0x210E94 (0x24 bytes) */
/*
 * dcomp notes:
 *   repo declaration vs inferred signature: return void vs inferred u8 *
 */


extern u32 EventMngSt[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetEventFuncS0033(void);
static void InitS0033Event000(void *a0 );
static void PlayS0033Event000(struct dw_2911702_fields *lpEvent);



void SetEventFuncS0033(void) {
    u8 *v1;

    v1 = (u8 *)InitS0033Event000;
    *(u32 *)EventMngSt = (u32)InitS0033Event000;
    v1 = (u8 *)PlayS0033Event000;
    *(u32 *)((u8 *)&EventMngSt + 4) = (u32)PlayS0033Event000;
    return;
}

static void InitS0033Event000(void *a0 /* r4 */) {
    u8 *s0;
    u8 *a2;
    u32 a1;
    u32 v1;
    u32 v0;

    a1 = 0x16;
    s0 = (u8 *)a0;
    a0 = (void *)(s32)1;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
    a0 = (void *)(s32)(v0 << 3);
    v0 = (s32)((u8 *)a0 - v0);
    v1 = (u32)((u8 *)MdlMng + 0x5400);
    v0 = v0 << 6;
    v0 = v1 + (u32)v0;
    *(u32 *)(s0 + 0x34) = v0;
    v0 = GameSt[0x14];
    a0 = (void *)(s32)0x543;
    if (v0 == 0) {
        v0 = CheckEventFlag((signed int)a0);
        if (v0 == 0) {
            goto _L00210E20;
        }
    }
    a0 = (void *)*(s32 *)(s0 + 0x34);
    FreeMdlMng(a0);
    v1 = 3;
    *(u32 *)(s0 + 0xc) = v1;
    goto _L00210E60;
    _L00210E20:;
    a0 = (void *)*(s32 *)(s0 + 0x34);
    a1 = 5;
    ChangeAnimParam(a0, a1, 0.0f);
    a2 = (u8 *)*(s32 *)(s0 + 0x34);
    a0 = (void *)0x404c0000;
    v1 = -0x3e0a0000;
    a1 = 0x404c0000 | 0xcccd;
    a0 = (void *)(-0x3e0a0000 | 0x6666);
    *(u32 *)(a2 + 0x110) = 0x3f000000;
    v1 = *(s32 *)(s0 + 0x34);
    *(u32 *)((v1 + 0x20)) = a1;
    v1 = *(s32 *)(s0 + 0x34);
    *(u32 *)((v1 + 0x28)) = (u32)a0;
    _L00210E60:;
    return;
}
static void PlayS0033Event000(struct dw_2911702_fields *lpEvent) {
    struct dw_2906456_fields *lpMy = (struct dw_2906456_fields *)((u8 *)MdlMng + 0x11800);
    float Center[4] = {4.1f, 0.0f, -28.0f, 1.0f};
    float angA, angB;

    switch (lpEvent->State[0]) {
    case 0:
        if (++lpEvent->State[1] == 0x28) {
            lpEvent->State[0] = 1;
            lpEvent->State[1] = 0;
            break;
        } else {
            float xx, zz;
            xx = lpEvent->lpMdl[0]->Pos[0] - Center[0];
            zz = lpEvent->lpMdl[0]->Pos[2] - Center[2];
            angA = CAE_WRAPF(Math_VectorToAngle(-xx, -zz));
            lpEvent->lpMdl[0]->Ang[1] = CAE_WRAPF(CAE_PI + angA);
            break;
        }
    case 1:
        if (lpMy->Pos[0] < 8.6f && lpMy->Pos[2] < -23.0f) {
            float xx, zz, AngDist;
            xx = Center[0] - lpMy->Pos[0];
            zz = Center[2] - lpMy->Pos[2];
            angA = CAE_WRAPF(Math_VectorToAngle(-xx, -zz));
            sinf(angA);
            cosf(angA);
            xx = lpEvent->lpMdl[0]->Pos[0] - Center[0];
            zz = lpEvent->lpMdl[0]->Pos[2] - Center[2];
            angB = CAE_WRAPF(Math_VectorToAngle(-xx, -zz));
            lpEvent->lpMdl[0]->Ang[1] = CAE_WRAPF(CAE_PI + angB);
            AngDist = Math_GetAngleDist(angB, angA);
            if (lpEvent->lpMdl[0]->IndexAnim == 5) {
                if (AngDist > 0.34899998f) {
                    ChangeAnimParam(lpEvent->lpMdl[0], 8, 0.0f);
                } else if (AngDist < -0.34899998f) {
                    ChangeAnimParam(lpEvent->lpMdl[0], 7, 0.0f);
                }
            } else if (-0.34899998f <= AngDist && AngDist <= 0.34899998f) {
                ChangeAnimParam(lpEvent->lpMdl[0], 5, 0.0f);
            }
            if (2.6698498725891113f < angB || !(-2.617499828338623f <= angB)) {
                SetObjMovePath(lpEvent->lpMdl[0], 1, 2, 5);
                *(float *)((u8 *)lpEvent->lpMdl[0]->lpPathMng + 0x214) = 3.0f;
                lpEvent->State[0] = 2;
            }
        } else {
            if (lpEvent->lpMdl[0]->IndexAnim != 5) {
                ChangeAnimParam(lpEvent->lpMdl[0], 5, 0.0f);
            }
        }
        break;
    case 2:
        if (lpMy->Pos[2] < -23.0f && lpEvent->lpMdl[0]->lpPathMng != 0) {
            break;
        }
        FreeMdlMng(lpEvent->lpMdl[0]);
        SetEventFlag(0x543);
        lpEvent->State[0] = 3;
    }
}
