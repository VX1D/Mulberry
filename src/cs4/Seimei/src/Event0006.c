#include "common.h"

/* PlayS0006Event002 @ 0x214090 .. 0x21414C (0xbc bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int CheckEventFlag(signed int);
extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern void SetEventModelDrawAndHit(void *, unsigned char);
extern u32 MdlMng[];

/* InitS0006Event002 @ 0x214150 .. 0x214294 (0x144 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x214184 if (..) goto .L00214200
 */

extern void FreeMdlMng(void *);
extern u8 GameSt[];


/* InitS0006Event001 @ 0x2148E0 .. 0x214928 (0x48 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x214900 if (..) goto .L00214918
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u8 GameSt[];

/* PlayS0006Event000 @ 0x214930 .. 0x214F3C (0x60c bytes, frame 0xc0) */
/*
 * dcomp notes:
 *   quad: a1: 128-bit web split from its scalar uses
 *   quad: a2: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @907 -> 0x250460
 *   stack: address of the slot at 0x60 escapes at 0x2149c8
 *   fpu: mov.s at 0x214a3c is a float copy
 *   fpu: mov.s at 0x214a44 is a float copy
 *   fpu: float literal 0x40490fdb at 0x214a50
 *   fpu: float literal 0x00000000 at 0x214a54
 *   fpu: mov.s at 0x214a68 is a float copy
 *   fpu: mov.s at 0x214a6c is a float copy
 *   fpu: mov.s at 0x214a74 is a float copy
 *   fpu: float literal 0x40490fdb at 0x214a88
 *   fpu: float literal 0x40c90fdb at 0x214a8c
 *   fpu: mov.s at 0x214aa4 is a float copy
 *   fpu: mov.s at 0x214ab0 is a float copy
 *   fpu: mov.s at 0x214ac0 is a float copy
 *   fpu: float literal 0x40490fdb at 0x214ad4
 *   fpu: float literal 0x40c90fdb at 0x214ad8
 *   fpu: mov.s at 0x214af0 is a float copy
 *   fpu: mov.s at 0x214afc is a float copy
 *   fpu: float literal 0x40c90fdb at 0x214b0c
 *   fpu: float literal 0x40490fdb at 0x214b20
 *   fpu: float literal 0x00000000 at 0x214b24
 *   fpu: float literal 0x40c90fdb at 0x214b44
 *   fpu: mtc1 reinterprets v1 at 0x214b68
 *   fpu: float literal 0x3d23d70a at 0x214c0c
 *   fpu: float literal 0x00000000 at 0x214c24
 *   delay: addiu at 0x214c4c writes a register its branch at 0x214c48 reads
 *   fpu: mov.s at 0x214cf0 is a float copy
 *   fpu: mov.s at 0x214cf8 is a float copy
 *   fpu: float literal 0x40490fdb at 0x214d04
 *   fpu: float literal 0x00000000 at 0x214d08
 *   fpu: mov.s at 0x214d1c is a float copy
 *   fpu: mov.s at 0x214d20 is a float copy
 *   fpu: mov.s at 0x214d28 is a float copy
 *   fpu: float literal 0x40490fdb at 0x214d3c
 *   fpu: float literal 0x40c90fdb at 0x214d40
 *   fpu: mov.s at 0x214d58 is a float copy
 *   fpu: mov.s at 0x214d64 is a float copy
 *   fpu: mov.s at 0x214d74 is a float copy
 *   fpu: float literal 0x40490fdb at 0x214d88
 *   fpu: float literal 0x40c90fdb at 0x214d8c
 *   fpu: mov.s at 0x214da4 is a float copy
 *   fpu: mov.s at 0x214db0 is a float copy
 *   fpu: float literal 0x40c90fdb at 0x214dc0
 *   fpu: float literal 0x3c64b87b at 0x214dd8
 *   fpu: mov.s at 0x214ddc is a float copy
 *   fpu: float literal 0x00000000 at 0x214dec
 *   fpu: mov.s at 0x214e08 is a float copy
 *   fpu: mov.s at 0x214e1c is a float copy
 *   fpu: float literal 0x3c64b87b at 0x214e28
 *   fpu: float literal 0x40490fdb at 0x214e40
 *   fpu: float literal 0x00000000 at 0x214e44
 *   fpu: float literal 0x40c90fdb at 0x214e64
 *   fpu: float literal 0x40c90fdb at 0x214e8c
 *   fpu: float literal 0x00000000 at 0x214eac
 *   delay: daddiu at 0x214ee8 writes a register its branch at 0x214ee4 reads
 *   literal: @907 initializes the 96-byte local at 0x60
 *   cfg: kept goto: 0x214cb0 -> .L00214F18
 *   cfg: kept branch: 0x214ed8 if (..) goto .L00214EF8
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void EasyEneAppearEx(signed int, unsigned short, unsigned char);
extern float Math_VectorToAngle(float, float);
extern float Math_GetDistXZ(float *, float *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern float Math_GetAngleDist(float, float);
extern void EventEneHitCheck(void *);
extern u32 GetCurCamID();
extern u32 L907[];

struct dw_3020706_fields;
struct dw_3030020_fields;
#ifndef PROTO_DW_3020477_FIELDS
#define PROTO_DW_3020477_FIELDS
struct dw_3020477_fields { void *InitFunc; void *PlayFunc; void *ActiFunc; int State[10]; struct dw_3020706_fields *lpMdl[10]; unsigned char _pad0[4]; };
#endif
#ifndef PROTO_DW_3026447_FIELDS
#define PROTO_DW_3026447_FIELDS
struct dw_3026447_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_3024680_FIELDS
#define PROTO_DW_3024680_FIELDS
struct dw_3024680_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_3024322_FIELDS
#define PROTO_DW_3024322_FIELDS
struct dw_3024322_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_3020706_fields *lpMdl; };
#endif
#ifndef PROTO_DW_3020706_FIELDS
#define PROTO_DW_3020706_FIELDS
struct dw_3020706_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_3030020_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_3020706_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_3026447_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_3024680_fields flags; unsigned char _pad1[3]; struct dw_3024322_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_3020477_FIELDS_STATE_0__4DBCF020_DEFINED
#define DCOMP_OFF_STRUCT_DW_3020477_FIELDS_STATE_0__4DBCF020_DEFINED
enum { DCOMP_OFF_STRUCT_DW_3020477_FIELDS_STATE_0__4DBCF020 = (int)&(((struct dw_3020477_fields *)0)->State[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_3020477_FIELDS_STATE_1__2608F4B8_DEFINED
#define DCOMP_OFF_STRUCT_DW_3020477_FIELDS_STATE_1__2608F4B8_DEFINED
enum { DCOMP_OFF_STRUCT_DW_3020477_FIELDS_STATE_1__2608F4B8 = (int)&(((struct dw_3020477_fields *)0)->State[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_3020477_FIELDS_STATE_2__16EB0AD4_DEFINED
#define DCOMP_OFF_STRUCT_DW_3020477_FIELDS_STATE_2__16EB0AD4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_3020477_FIELDS_STATE_2__16EB0AD4 = (int)&(((struct dw_3020477_fields *)0)->State[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_3020477_FIELDS_STATE_3__0A6A3491_DEFINED
#define DCOMP_OFF_STRUCT_DW_3020477_FIELDS_STATE_3__0A6A3491_DEFINED
enum { DCOMP_OFF_STRUCT_DW_3020477_FIELDS_STATE_3__0A6A3491 = (int)&(((struct dw_3020477_fields *)0)->State[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_3020477_FIELDS_LPMDL_0__976E6970_DEFINED
#define DCOMP_OFF_STRUCT_DW_3020477_FIELDS_LPMDL_0__976E6970_DEFINED
enum { DCOMP_OFF_STRUCT_DW_3020477_FIELDS_LPMDL_0__976E6970 = (int)&(((struct dw_3020477_fields *)0)->lpMdl[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_3020706_FIELDS_ANG_1__51A3F84B_DEFINED
#define DCOMP_OFF_STRUCT_DW_3020706_FIELDS_ANG_1__51A3F84B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_3020706_FIELDS_ANG_1__51A3F84B = (int)&(((struct dw_3020706_fields *)0)->Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_3020706_FIELDS_POS_0__D623E081_DEFINED
#define DCOMP_OFF_STRUCT_DW_3020706_FIELDS_POS_0__D623E081_DEFINED
enum { DCOMP_OFF_STRUCT_DW_3020706_FIELDS_POS_0__D623E081 = (int)&(((struct dw_3020706_fields *)0)->Pos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_3020706_FIELDS_POS_2__53C12059_DEFINED
#define DCOMP_OFF_STRUCT_DW_3020706_FIELDS_POS_2__53C12059_DEFINED
enum { DCOMP_OFF_STRUCT_DW_3020706_FIELDS_POS_2__53C12059 = (int)&(((struct dw_3020706_fields *)0)->Pos[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_3020706_FIELDS_LPCTRLST_47087477_DEFINED
#define DCOMP_OFF_STRUCT_DW_3020706_FIELDS_LPCTRLST_47087477_DEFINED
enum { DCOMP_OFF_STRUCT_DW_3020706_FIELDS_LPCTRLST_47087477 = (int)&(((struct dw_3020706_fields *)0)->lpCtrlSt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_3020706_FIELDS_LPCTRLST_38FEAE10_DEFINED
#define DCOMP_OFF_STRUCT_DW_3020706_FIELDS_LPCTRLST_38FEAE10_DEFINED
enum { DCOMP_OFF_STRUCT_DW_3020706_FIELDS_LPCTRLST_38FEAE10 = (int)&(((struct dw_3020706_fields *)0)->lpCtrlSt) - 328 };
#endif
#define PI_ 3.14159274f
#define WRAPF(a) ((3.14159274f + (a) >= 0.0f) ? ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f)) : (6.28318548f + ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f))))

/* SetEventFuncS0006 @ 0x214F90 .. 0x214FF4 (0x64 bytes) */
/*
 * dcomp notes:
 *   repo declaration vs inferred signature: return void vs inferred u8 *
 */


extern u32 EventMngSt[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetEventFuncS0006(void);
static void InitS0006Event000(void *a0 );
static void PlayS0006Event000(struct dw_3020477_fields *lpEvent);
static void InitS0006Event001(void *a0 );
void PlayS0006Event001(struct dw_3020477_fields *lpEvent);
static void InitS0006Event002(void *a0 );
static void PlayS0006Event002(void *a0 );






void SetEventFuncS0006(void) {
    u8 *v1;

    v1 = (u8 *)InitS0006Event000;
    *(u32 *)EventMngSt = (u32)InitS0006Event000;
    v1 = (u8 *)PlayS0006Event000;
    *(u32 *)((u8 *)&EventMngSt + 4) = (u32)PlayS0006Event000;
    v1 = (u8 *)InitS0006Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x60) = (u32)InitS0006Event001;
    v1 = (u8 *)PlayS0006Event001;
    *(u32 *)((u8 *)&EventMngSt + 0x64) = (u32)PlayS0006Event001;
    v1 = (u8 *)InitS0006Event002;
    *(u32 *)((u8 *)&EventMngSt + 0xc0) = (u32)InitS0006Event002;
    v1 = (u8 *)PlayS0006Event002;
    *(u32 *)((u8 *)&EventMngSt + 0xc4) = (u32)PlayS0006Event002;
    return;
}


/* InitS0006Event000 @ 0x214F40 .. 0x214F90 (0x50 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x214f68 if (..) goto .L00214F80
 *   declaration vs inferred signature: return void vs inferred u32
 */



static void InitS0006Event000(void *a0 /* r4 */) {
    s32 v1;
    u32 *s0;
    u32 v0;

    v1 = 1;
    s0 = (u32 *)a0;
    a0 = (void *)*(u8 *)((u8 *)&GameSt + 0x14);
    if ((u32)a0 == (u32)v1) {
        a0 = (void *)(s32)0x3c8;
        v0 = CheckEventFlag((signed int)a0);
        if (v0 == 0) {
            goto _L00214F80;
        }
    }
    v1 = 2;
    *(u32 *)(((u8 *)s0 + 0xc)) = v1;
    _L00214F80:;
    return;
}
static void PlayS0006Event000(struct dw_3020477_fields *lpEvent) {
    u8 *lpMyCtrl;
    struct dw_3020706_fields *lpEne;
    u8 *lpEneCtrl;
    int EventMdlMngIndex;
    int t;
    u8 fl;
    float xx, zz, ang, f0, f1, f3, d;
    u32 *s1;

    s1 = (u32 *)(MdlMng + 0x4652);
    lpMyCtrl = *(u8 **)s1;
    {
    float aWanderPos[6][4] = {
        {37.0f, 0.0f, 0.5f, 0.0f}, {36.5f, 0.0f, 1.0f, 0.0f}, {36.0f, 0.0f, 1.10000002f, 0.0f},
        {35.5999985f, 0.0f, 0.600000024f, 0.0f}, {35.4000015f, 0.0f, -2.79999995f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}};
    switch (lpEvent->State[0]) {
    case 0:
        if (CheckEventFlag(0x3c8) == 0 || lpMyCtrl[0x190] == 0) {
            break;
        }
        EasyEneAppearEx(3, 0xa, 1);
        EventMdlMngIndex = GetMdlMngIndexByCtrlId(2, 3);
        lpEne = &((struct dw_3020706_fields *)MdlMng)[EventMdlMngIndex + 0xa1];
        lpEvent->lpMdl[0] = lpEne;
        xx = aWanderPos[1][0] - lpEne->Pos[0];
        zz = aWanderPos[1][2] - lpEne->Pos[2];
        f3 = WRAPF(Math_VectorToAngle(-xx, -zz));
        lpEne->Ang[1] = WRAPF(f3);
        lpEvent->State[0] = 1;
        lpEvent->State[1] = 0;
        lpEvent->State[2] = 0;
        break;
    case 1:
        EventMdlMngIndex = GetMdlMngIndexByCtrlId(2, 3);
        lpEne = &((struct dw_3020706_fields *)MdlMng)[EventMdlMngIndex + 0xa1];
        lpEneCtrl = (u8 *)lpEne->lpCtrlSt;
        switch (lpEvent->State[1]) {
        case 0:
            f0 = Math_GetDistXZ(aWanderPos[lpEvent->State[2] + 1], lpEne->Pos);
            if (!(f0 < 0.04f)) {
                break;
            }
            lpEvent->State[1] = 1;
            ChangeAnimParam(lpEne, 0, 0.0f);
            lpEvent->State[2] = lpEvent->State[2] + 1;
            if (lpEvent->State[2] == 2 || lpEvent->State[2] == 1) {
                lpEvent->State[3] = 1;
            }
            break;
        case 1:
            if (lpEvent->State[2] == 2 || lpEvent->State[2] == 1) {
                if (lpEvent->State[3] > 0) {
                    t = lpEvent->State[3] + 1;
                    lpEvent->State[3] = t;
                    if (t <= 0xb4) {
                        break;
                    }
                    lpEvent->State[3] = 0;
                }
            }
            if (lpEvent->State[2] >= 4) {
                FreeMdlMng(lpEne);
                lpEvent->State[0] = 2;
                return;
            }
            xx = aWanderPos[lpEvent->State[2] + 1][0] - aWanderPos[lpEvent->State[2]][0];
            zz = aWanderPos[lpEvent->State[2] + 1][2] - aWanderPos[lpEvent->State[2]][2];
            ang = WRAPF(Math_VectorToAngle(-xx, -zz));
            lpEne->Ang[1] -= 0.013959999f;
            f0 = Math_GetAngleDist(lpEne->Ang[1], ang);
            if (f0 < 0.0f) {
                f0 = -Math_GetAngleDist(lpEne->Ang[1], ang);
            } else {
                f0 = Math_GetAngleDist(lpEne->Ang[1], ang);
            }
            if (!(f0 < 0.013959999f)) {
                break;
            }
            lpEvent->State[1] = 0;
            lpEne->Ang[1] = WRAPF(ang);
            ChangeAnimParam(lpEne, 0xa, 0.0f);
        }
        EventEneHitCheck(lpEne);
        if (*(u8 *)(*(s32 *)s1 + 0x190) == 0 && GetCurCamID() == 9) {
            fl = 1;
        } else {
            fl = 0;
        }
        if (fl) {
            lpEneCtrl[0x182] = 1;
            lpEvent->State[0] = 2;
        }
    case 2:
        break;
    }
    }
}

static void InitS0006Event001(void *a0 /* r4 */) {
    u32 v1;
    u32 *s0;
    u32 v0;

    v1 = *(u8 *)((u8 *)&GameSt + 0x14);
    s0 = (u32 *)a0;
    if (v1 == 0) {
        a0 = (void *)(s32)0x6cc;
        v0 = CheckEventFlag((signed int)a0);
        if (v0 == 0) {
            goto _L00214918;
        }
    }
    v1 = 3;
    *(u32 *)(((u8 *)s0 + 0xc)) = v1;
    _L00214918:;
    return;
}

void PlayS0006Event001(struct dw_3020477_fields *lpEvent) {
    struct dw_3020706_fields *lpMy;
    u8 *lpMyCtrl;
    int EventMdlMngIndex;
    struct dw_3020706_fields *lpEne;
    u8 *lpEneCtrl;
    float xx, zz, ang, f0, f1, f3;
    u8 fl;

    lpMy = (struct dw_3020706_fields *)(MdlMng + 0x4600);
    lpMyCtrl = (u8 *)lpMy->lpCtrlSt;
    {
        float aWanderPos[5][4] = {
            {38.0f, -1.33f, 4.0f, 0.0f}, {36.2f, -1.33f, 4.1f, 0.0f}, {34.3f, -1.37f, 3.4f, 0.0f},
            {33.5f, -1.28f, 4.2f, 0.0f}, {32.0f, -1.35f, 3.6f, 0.0f}};
        switch (lpEvent->State[0]) {
        case 0:
            if (lpMyCtrl[0x190] != 0) {
                break;
            }
            if (GetCurCamID() != 8) {
                break;
            }
            lpEvent->State[0] = 1;
            break;
        case 1:
            {
                float Range[4] = {34.0f, 6.0f, 36.0f, 6.3f};
                if (CheckSquareRange(lpMy->Pos, Range) == 0) {
                    break;
                }
            }
            EasyEneAppearEx(4, 0xa, 1);
            EventMdlMngIndex = GetMdlMngIndexByCtrlId(2, 4);
            lpEne = &((struct dw_3020706_fields *)MdlMng)[EventMdlMngIndex + 0xa1];
            xx = aWanderPos[1][0] - lpEne->Pos[0];
            zz = aWanderPos[1][2] - lpEne->Pos[2];
            f3 = WRAPF(Math_VectorToAngle(-xx, -zz));
            lpEne->Ang[1] = WRAPF(f3);
            lpEvent->State[0] = 2;
            lpEvent->State[1] = 0;
            lpEvent->State[2] = 0;
            SetEventFlag(0x6cc);
            break;
        case 2:
            EventMdlMngIndex = GetMdlMngIndexByCtrlId(2, 4);
            lpEne = &((struct dw_3020706_fields *)MdlMng)[EventMdlMngIndex + 0xa1];
            lpEneCtrl = (u8 *)lpEne->lpCtrlSt;
            switch (lpEvent->State[1]) {
            case 0:
                f1 = lpEne->Pos[0] - aWanderPos[lpEvent->State[2] + 1][0];
                if (!(f1 < 0.1f)) {
                    break;
                }
                lpEvent->State[1] = 1;
                ChangeAnimParam(lpEne, 0, 0.0f);
                lpEvent->State[2] = lpEvent->State[2] + 1;
                break;
            case 1:
                if (lpEvent->State[2] >= 4) {
                    FreeMdlMng(lpEne);
                    lpEvent->State[1] = 3;
                    break;
                } else {
                    xx = aWanderPos[lpEvent->State[2] + 1][0] - aWanderPos[lpEvent->State[2]][0];
                    zz = aWanderPos[lpEvent->State[2] + 1][2] - aWanderPos[lpEvent->State[2]][2];
                    ang = WRAPF(Math_VectorToAngle(-xx, -zz));
                    if (lpEvent->State[2] % 2 == 0) {
                        lpEne->Ang[1] += 0.01745f;
                    } else {
                        lpEne->Ang[1] -= 0.01745f;
                    }
                    f0 = Math_GetAngleDist(lpEne->Ang[1], ang);
                    if (f0 < 0.0f) {
                        f0 = -Math_GetAngleDist(lpEne->Ang[1], ang);
                    } else {
                        f0 = Math_GetAngleDist(lpEne->Ang[1], ang);
                    }
                    /* Preserve the target's post-call threshold reload. */
                    f1 = ({ float native_result_0; __asm__("mtc1 %1,%0" : "=f"(native_result_0) : "r"((u32)0x3c8ef34d)); native_result_0; });
                    if (!(f0 < f1)) {
                        break;
                    }
                    lpEvent->State[1] = 0;
                    lpEne->Ang[1] = WRAPF(ang);
                    ChangeAnimParam(lpEne, 0xa, 0.0f);
                }
            }
            EventEneHitCheck(lpEne);
            if (*(u8 *)(*(s32 *)(MdlMng + 0x4652) + 0x190) == 0 && GetCurCamID() == 9) {
                fl = 1;
            } else {
                fl = 0;
            }
            if (!fl || lpEvent->State[1] > 2) {
                break;
            }
            lpEneCtrl[0x182] = 1;
            lpEvent->State[0] = 3;
        case 3:
            break;
        }
    }
}

static void InitS0006Event002(void *a0 /* r4 */) {
    u8 *s1;
    s32 a1;
    u32 v1;
    u8 *s0;
    s32 v0;

    a1 = 1;
    s1 = (u8 *)a0;
    *(u32 *)(((u8 *)a0 + 0xc)) = a1;
    v1 = GameSt[0x14];
    s0 = (u8 *)MdlMng + 0x5400;
    if (v1 == (u32)a1) {
        a0 = (void *)(s32)0x3d5;
        v0 = CheckEventFlag((signed int)a0);
        a0 = (void *)(s32)1;
        if ((u32)v0 != 0) {
            goto _L00214200;
        }
        a1 = 0x17;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        a1 = 1;
        v0 = (u32)((u32)v0) * (u32)(7);
        v0 = (u32)v0 << 6;
        a0 = (void *)(s0 + v0);
        SetEventModelDrawAndHit(a0, a1);
        a0 = (void *)(s32)1;
        a1 = 0x18;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        a1 = 1;
        v0 = (u32)((u32)v0) * (u32)(7);
        v0 = (u32)v0 << 6;
        a0 = (void *)(s0 + v0);
        SetEventModelDrawAndHit(a0, a1);
        a0 = (void *)(s32)1;
        a1 = 0x19;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        v1 = (u32)v0 << 3;
        a1 = 1;
        v0 = (u32)((u32)v0) * (u32)(7);
        v0 = (u32)v0 << 6;
        a0 = (void *)(s0 + v0);
        SetEventModelDrawAndHit(a0, a1);
        *(u32 *)(s1 + 0xc) = 0;
    } else {
        _L00214200:;
        v1 = GameSt[0x14];
        a0 = (void *)(s32)0x45a;
        if (v1 == 0) {
            v0 = CheckEventFlag((signed int)a0);
            a0 = (void *)(s32)1;
            if ((u32)v0 == 0) {
                a1 = 0x17;
                v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
                v0 = (u32)((u32)v0) * (u32)(7);
                v0 = (u32)v0 << 6;
                a0 = (void *)(s0 + v0);
                FreeMdlMng(a0);
                a0 = (void *)(s32)1;
                a1 = 0x18;
                v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
                v0 = (u32)((u32)v0) * (u32)(7);
                v0 = (u32)v0 << 6;
                a0 = (void *)(s0 + v0);
                FreeMdlMng(a0);
                a0 = (void *)(s32)1;
                a1 = 0x19;
                v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
                v1 = (u32)v0 << 3;
                v0 = (u32)((u32)v0) * (u32)(7);
                v0 = (u32)v0 << 6;
                a0 = (void *)(s0 + v0);
                FreeMdlMng(a0);
            }
        }
    }
    return;
}

static void PlayS0006Event002(void *a0 /* r4 */) {
    u32 *s1;
    u32 v1;
    u8 *s0;
    s32 v0;
    u32 a1;

    s1 = (u32 *)a0;
    v1 = *(s32 *)(((u8 *)a0 + 0xc));
    s0 = (u8 *)MdlMng + 0x5400;
    if (v1 == 0) {
        a0 = (void *)(s32)0x3d5;
        v0 = CheckEventFlag((signed int)a0);
        a0 = (void *)(s32)1;
        if ((u32)v0 != 0) {
            a1 = 0x17;
            v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
            v1 = (u32)v0 << 3;
            v0 = v1 - v0;
            v0 = (u32)v0 << 6;
            a0 = (void *)(s32)((u8 *)s0 + v0);
            SetEventModelDrawAndHit(a0, 0);
            a0 = (void *)(s32)1;
            a1 = 0x18;
            v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
            v1 = (u32)v0 << 3;
            v0 = v1 - v0;
            v0 = (u32)v0 << 6;
            a0 = (void *)(s32)((u8 *)s0 + v0);
            SetEventModelDrawAndHit(a0, 0);
            a0 = (void *)(s32)1;
            a1 = 0x19;
            v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
            v1 = (u32)v0 << 3;
            v0 = v1 - v0;
            v0 = (u32)v0 << 6;
            a0 = (void *)(s32)((u8 *)s0 + v0);
            SetEventModelDrawAndHit(a0, 0);
            v1 = 1;
            *(u32 *)(((u8 *)s1 + 0xc)) = v1;
        }
    }
    return;
}
