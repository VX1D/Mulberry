#include "common.h"

/* SfxMdl_EnableDraw @ 0x1CE1C0 .. 0x1CE244 (0x84 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void * SList_GetElemPtr(void *, unsigned short);
extern u8 MdlMng[];
static u32 s_pObjList;

/* SfxMdl_SetDrawStage @ 0x1CE250 .. 0x1CE2CC (0x7c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void * SList_GetElemPtr(void *, unsigned short);
extern u8 MdlMng[];
static u32 s_pObjList;

/* SfxMdl_EnableZWrite @ 0x1CE2D0 .. 0x1CE364 (0x94 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

struct dw_12032;
struct dw_24837;
#ifndef PROTO_DW_24196
#define PROTO_DW_24196
struct dw_24196 { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_21391
#define PROTO_DW_21391
struct dw_21391 { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_20666
#define PROTO_DW_20666
struct dw_20666 { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_12032 *lpMdl; };
#endif
#ifndef PROTO_DW_12032
#define PROTO_DW_12032
struct dw_12032 { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_24837 *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_12032 *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_24196 DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_21391 flags; unsigned char _pad1[3]; struct dw_20666 Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif

/* SfxMdl_GetTest @ 0x1CE370 .. 0x1CE3F4 (0x84 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */



static u32 s_pObjList;

/* SfxMdl_SetTest @ 0x1CE400 .. 0x1CE494 (0x94 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */



static u32 s_pObjList;

/* SfxMdl_SetScale_LEGACY @ 0x1CE4A0 .. 0x1CE524 (0x84 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void * SList_GetElemPtr(void *, unsigned short);
extern void sceVu0CopyVector(void *, void *);
extern u8 MdlMng[];
static u32 s_pObjList;

/* SfxMdl_SetMatrix_LEGACY @ 0x1CE530 .. 0x1CE5E4 (0xb4 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x3c escapes at 0x1ce598
 *   stack: address of the slot at 0x38 escapes at 0x1ce598
 *   stack: address of the slot at 0x34 escapes at 0x1ce598
 *   declaration vs inferred signature: return signed int vs inferred float
 */


extern void SfxCalc_PYRfromRotMatrix_LEGACY(void *, float *, float *, float *);


static u32 s_pObjList;

/* SfxMdl_SetTexScroll @ 0x1CE730 .. 0x1CE78C (0x5c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1ce74c is a float copy
 *   fpu: mov.s at 0x1ce754 is a float copy
 */


static u32 s_pObjList;

/* SfxMdl_SetColor @ 0x1CE810 .. 0x1CE8CC (0xbc bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1ce834 is a float copy
 *   fpu: mov.s at 0x1ce838 is a float copy
 *   fpu: mov.s at 0x1ce840 is a float copy
 *   stack: address of the slot at 0x30 escapes at 0x1ce87c
 */


extern void GetAmbientColor(void *);

static u32 s_pObjList;

/* SfxMdl_SetMatrix @ 0x1CE8D0 .. 0x1CE95C (0x8c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


extern void SetModelWorldMatrix(void *, void *);


static u32 s_pObjList;

/* SfxMdl_Free @ 0x1CE960 .. 0x1CE9EC (0x8c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred void
 */


extern void FreeMdlMng(void *);
extern void * memset(void *, int, unsigned int);
extern signed int SList_Delete(void *, unsigned short);

static u32 s_pObjList;

extern unsigned short SList_PushFront(void *, void *);
extern unsigned int SetMdlMng(void *, void *);
extern u32 MdlData[];


/* SfxMdl_InitMgr @ 0x1CEB20 .. 0x1CEB58 (0x38 bytes, frame 0x10) */

extern void * SList_Init(void *, unsigned int, unsigned short);
extern signed int SList_SetLimitter(void *, unsigned short);
static u32 s_pObjList;
static u32 s_data_buff[256];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SfxMdl_InitMgr(void);
unsigned short SfxMdl_Alloc(unsigned short model, signed int mode);
signed int SfxMdl_Free(unsigned short a0 );
signed int SfxMdl_SetMatrix(unsigned short a0 , void *a1 );
signed int SfxMdl_SetColor(unsigned short a0 , float f12 , float f13 , float f14 );
signed int SfxMdl_SetAlpha(unsigned short a0 , float f12 );
signed int SfxMdl_SetTexScroll(unsigned short a0 , float f12 , float f13 );
signed int SfxMdl_SetZOffset(unsigned short a0 , float f12 );
signed int SfxMdl_GetTexScroll_ByPtr(void *a0 , float *a1 , float *a2 );
signed int SfxMdl_SetMatrix_LEGACY(unsigned short a0 , void *a1 );
signed int SfxMdl_SetScale_LEGACY(unsigned short a0 , float *a1 );
signed int SfxMdl_SetTest(unsigned short a0 , unsigned int a1 );
signed int SfxMdl_GetTest(unsigned short a0 , unsigned int *a1 );
signed int SfxMdl_EnableZWrite(unsigned short a0 , signed int a1 );
signed int SfxMdl_SetDrawStage(unsigned short a0 , unsigned char a1 );
signed int SfxMdl_EnableDraw(unsigned short a0 , signed int a1 );


void SfxMdl_InitMgr(void) {
    u32 a0;
    s32 a1;
    u8 *v0;

    a0 = (u32)s_data_buff;
    a1 = 0x400;
    v0 = (u8 *)SList_Init((void *)s_data_buff, a1, (s32)8);
    s_pObjList = (u32)v0;
    a0 = s_pObjList;
    a1 = 0x80;
    SList_SetLimitter((void *)a0, a1);
    return;
}
unsigned short SfxMdl_Alloc(unsigned short model, signed int mode) {
    u16 handle;
    u8 *object;
    handle = SList_PushFront((void *)s_pObjList, 0);
    if (handle == 0xffff) return 0xffff;
    SList_GetElemPtr((void *)s_pObjList, handle);
    object = (u8 *)MdlMng + ((u16)handle + 239) * 448;
    if (!SetMdlMng(object, (u8 *)MdlData + (model + 140) * 1664)) {
        SList_Delete((void *)s_pObjList, handle);
        return 0xffff;
    } else {
        ((struct { unsigned int f:19; } *)(object + 0x150))->f = 0x7100d;
        ((struct { unsigned char f:1; } *)(object + 0x153))->f = 1;
        ((struct { unsigned char f:1; } *)(object + 0x194))->f = !mode;
        return handle;
    }
}

signed int SfxMdl_Free(unsigned short a0 /* r4 */) {
    u16 s1;
    u32 v0;
    u8 *s0;
    u32 a0_guard_word;

    v0 = 0xffff;
    s1 = a0;
    if ((u32)(u16)a0 == v0) {
        v0 = 0;
    } else {
        a0_guard_word = s_pObjList;
        v0 = (u32)SList_GetElemPtr((void *)a0_guard_word, s1);
        s0 = (u8 *)v0;
        a0_guard_word = (u32)s1 + 0xef;
        v0 = (u32)MdlMng;
        FreeMdlMng((void *)(u32)(s32)((u8 *)MdlMng + (s32)((u32)((s32)(a0_guard_word << 3) -
            a0_guard_word) << 6)));
        memset((void *)s0, 0, 8);
        a0_guard_word = s_pObjList;
        v0 = SList_Delete((void *)a0_guard_word, s1);
    }
    return v0;
}

signed int SfxMdl_SetMatrix(unsigned short a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u16 s1_handle; // s1
    u32 v0;
    u32 a0_guard_word;
    u32 s0;

    v0 = 0xffff;
    s1_handle = a0;
    s0 = (u32)a1;
    if ((u32)(u16)a0 == v0) {
        v0 = 0;
    } else {
        SList_GetElemPtr((void *)s_pObjList, s1_handle);
        a0_guard_word = (s32)s1_handle + 0xef;
        v0 = (u32)MdlMng;
        s1 = (u8 *)((u8 *)MdlMng + (s32)((u32)((s32)(a0_guard_word << 3) - a0_guard_word) << 6));
        SetModelWorldMatrix((void *)(u32)(s32)s1, (void *)s0);
        sceVu0CopyVector((void *)(u32)(s32)(s1 + 0x20), (void *)(u32)(s0 + 0x30));
        v0 = 1;
    }
    return v0;
}

signed int SfxMdl_SetColor(unsigned short a0 /* r4 */, float f12 /* f12 */, float f13 /* f13 */,
        float f14 /* f14 */) {
    u16 s0;
    float f22;
    float f21;
    float f20;
    u32 v0;
    u8 *s0_address; // s0
    u32 a0_guard_word;
    u8 stackFrame_30[16] __attribute__((aligned(16)));

    v0 = 0xffff;
    s0 = a0;
    f22 = f12;
    f21 = f13;
    f20 = f14;
    if ((u32)(u16)a0 == v0) {
        v0 = 0;
    } else {
        a0_guard_word = s_pObjList;
        SList_GetElemPtr((void *)a0_guard_word, s0);
        v0 = (u32)MdlMng;
        s0_address = (u8 *)((u8 *)MdlMng + (s32)((u32)((s32)s0 + 0xef) * (u32)(0x1c0)));
        GetAmbientColor((void *)((u8 *)&stackFrame_30[0]));
        v0 = 1;
        *(u8 *)(s0_address + 8) = v0;
        *(f32 *)(s0_address + 0xb0) = (f22 * *(float *)((u8 *)&stackFrame_30[0]));
        *(f32 *)(s0_address + 0xb4) = (f21 * ((float *)stackFrame_30)[1]);
        *(f32 *)(s0_address + 0xb8) = (f20 * ((float *)stackFrame_30)[2]);
    }
    return v0;
}

/* SfxMdl_SetAlpha @ 0x1CE790 .. 0x1CE80C (0x7c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1ce7b0 is a float copy
 */

signed int SfxMdl_SetAlpha(unsigned short a0 /* r4 */, float f12 /* f12 */) {
    u16 s0;
    u32 a1;
    float f20;
    u32 a0_guard_word; // a0
    u32 v1;
    s32 v0;

    v0 = 0xffff;
    s0 = a0;
    f20 = f12;
    if ((u32)(u16)a0 == (u32)v0) {
        v0 = 0;
    } else {
        SList_GetElemPtr((void *)s_pObjList, s0);
        a1 = (s32)s0 + 0xef;
        v1 = (u32)MdlMng;
        a0_guard_word = a1 << 3;
        *(f32 *)(((u32)(s32)((u8 *)MdlMng + (u32)((u32)(a0_guard_word - a1) << 6)) + 0x10c)) = f20;
        v0 = 1;
    }
    return v0;
}

signed int SfxMdl_SetTexScroll(unsigned short a0 /* r4 */, float f12 /* f12 */, float f13 /* f13 */) {
    float f21;
    float f20;
    u32 v0;

    v0 = 0xffff;
    f21 = f12;
    f20 = f13;
    if ((u32)(u16)a0 == v0) {
        v0 = 0;
    } else {
        v0 = (u32)SList_GetElemPtr((void *)s_pObjList, a0);
        *(f32 *)v0 = f21;
        *(f32 *)(((u8 *)v0 + 4)) = f20;
        v0 = 1;
    }
    return v0;
}

/* SfxMdl_SetZOffset @ 0x1CE6B0 .. 0x1CE72C (0x7c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1ce6d0 is a float copy
 */

signed int SfxMdl_SetZOffset(unsigned short a0 /* r4 */, float f12 /* f12 */) {
    u16 s0;
    u32 a1;
    float f20;
    u32 a0_guard_word; // a0
    u32 v1;
    s32 v0;

    v0 = 0xffff;
    s0 = a0;
    f20 = f12;
    if ((u32)(u16)a0 == (u32)v0) {
        v0 = 0;
    } else {
        SList_GetElemPtr((void *)s_pObjList, s0);
        a1 = (s32)s0 + 0xef;
        v1 = (u32)MdlMng;
        a0_guard_word = a1 << 3;
        *(f32 *)(((u32)(s32)((u8 *)MdlMng + (u32)((u32)(a0_guard_word - a1) << 6)) + 0x184)) = f20;
        v0 = 1;
    }
    return v0;
}

/* SfxMdl_GetTexScroll_ByPtr @ 0x1CE5F0 .. 0x1CE6AC (0xbc bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int SfxMdl_GetTexScroll_ByPtr(void *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */) {
    float *s1;
    float *s0;
    u32 v0;

    s1 = (float *)a1;
    v0 = (u32)(s32)((u8 *)a0 - (u32)(u8 *)(((u8 *)MdlMng) + 0x1a240)) / (u32)(0x1c0);
    s0 = (float *)a2;
    if (v0 > (u32)0x80) {
        v0 = 0;
    } else {
        a1 = (float *)(u16)v0;
        v0 = 0xffff;
        if ((u32)(u16)a1 == v0) {
            v0 = 0;
        } else {
            a0 = (void *)s_pObjList;
            v0 = (u32)SList_GetElemPtr(a0, (u16)a1);
            if ((u32)s1 != 0) {
                *(f32 *)s1 = *(float *)v0;
            }
            if ((u32)s0 != 0) {
                *(f32 *)s0 = *(float *)(((u8 *)v0 + 4));
            }
            v0 = 1;
        }
    }
    return v0;
}

signed int SfxMdl_SetMatrix_LEGACY(unsigned short a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u16 s1_handle; // s1
    u32 v0;
    u32 a0_guard_word;
    u32 s0;
    u8 stackFrame_3C[4] __attribute__((aligned(4)));
    u8 stackFrame_38[4] __attribute__((aligned(4)));
    u8 stackFrame_34[4] __attribute__((aligned(4)));

    v0 = 0xffff;
    s1_handle = a0;
    s0 = (u32)a1;
    if ((u32)(u16)a0 == v0) {
        v0 = 0;
    } else {
        a0_guard_word = s_pObjList;
        SList_GetElemPtr((void *)a0_guard_word, s1_handle);
        v0 = (u32)MdlMng;
        s1 = (u8 *)((u8 *)MdlMng + (s32)((u32)((s32)s1_handle + 0xef) * (u32)(0x1c0)));
        SfxCalc_PYRfromRotMatrix_LEGACY((void *)s0, (float *)((u8 *)&stackFrame_3C[0]), (float
            *)((u8 *)&stackFrame_38[0]), (float *)(u8 *)((u8 *)&stackFrame_34[0]));
        sceVu0CopyVector((void *)(u32)(s32)(s1 + 0x20), (void *)(u32)(s0 + 0x30));
        v0 = 1;
        *(f32 *)(s1 + 0x30) = *(float *)((u8 *)&stackFrame_3C[0]);
        *(f32 *)(s1 + 0x34) = *(float *)((u8 *)&stackFrame_38[0]);
        *(f32 *)(s1 + 0x38) = *(float *)((u8 *)&stackFrame_34[0]);
        *(u32 *)(s1 + 0x3c) = 0;
    }
    return v0;
}

signed int SfxMdl_SetScale_LEGACY(unsigned short a0 /* r4 */, float *a1 /* r5 */) {
    u16 s1;
    s32 v1;
    u32 v0;
    u32 a0_guard_word;

    v1 = (u16)a0;
    v0 = 0xffff;
    s1 = a0;
    if ((u32)v1 == v0) {
        v0 = 0;
    } else {
        SList_GetElemPtr((void *)s_pObjList, s1);
        a0_guard_word = (u32)s1 + 0xef;
        v1 = a0_guard_word << 3;
        v0 = (u32)MdlMng;
        sceVu0CopyVector((void *)(u32)((u32)(s32)((u8 *)MdlMng + (s32)((u32)(v1 - a0_guard_word) <<
            6)) + 0x40), (void *)a1);
        v0 = 1;
    }
    return v0;
}

signed int SfxMdl_SetTest(unsigned short a0 /* r4 */, unsigned int a1 /* r5 */) {
    u16 s1;
    s32 s0;
    u32 a2;
    u32 v1;
    s32 v0;

    s1 = a0;
    s0 = a1;
    if ((u32)(u16)a0 == (u32)0xffff) {
        return 0;
    }
    SList_GetElemPtr((void *)s_pObjList, s1);
    a2 = (s32)s1 + 0xef;
    v0 = a2 << 3;
    a1 = (unsigned int)MdlMng;
    a2 = a2 * (u32)(7);
    v1 = -0x80000;
    a2 = a2 << 6;
    ((struct { unsigned int f:19; } *)&*(u32 *)(((u32)(s32)((u8 *)MdlMng + a2) + 0x150)))->f = s0;
    return 1;
}

signed int SfxMdl_GetTest(unsigned short a0 /* r4 */, unsigned int *a1 /* r5 */) {
    u16 s1;
    unsigned int *a1_value; // a1
    u32 a0_guard_word;
    u32 v1;

    s1 = a0;
    if ((u32)(u16)a0 == (u32)0xffff) {
        return 0;
    }
    SList_GetElemPtr((void *)s_pObjList, s1);
    a1_value = (unsigned int *)(s32)((s32)s1 + 0xef);
    v1 = (u32)MdlMng;
    a0_guard_word = (u32)a1_value << 3;
    v1 = (s32)((u8 *)MdlMng + (u32)((u32)(s32)((u8 *)a0_guard_word - (u32)(a1_value)) << 6));
    v1 = *(s32 *)((v1 + 0x150));
    *(u32 *)a1 = v1 & 0x7ffff;
    return 1;
}

signed int SfxMdl_EnableZWrite(unsigned short a0 /* r4 */, signed int a1 /* r5 */) {
    u16 s1;
    s32 s0;
    struct dw_12032 *a2;
    u32 v0;

    s1 = a0;
    s0 = a1;
    if ((u32)(u16)a0 == (u32)0xffff) {
        return 0;
    }
    SList_GetElemPtr((void *)s_pObjList, s1);
    v0 = (u32)MdlMng;
    a2 = (struct dw_12032 *)((u8 *)MdlMng + (u32)((u32)((u32)((u32)s1 + 0xef) * (u32)(7)) << 6));
    a2->DrawRegs.ZMSK = (u32)((u32)s0 != 0) ^ 1;
    return 1;
}

signed int SfxMdl_SetDrawStage(unsigned short a0 /* r4 */, unsigned char a1 /* r5 */) {
    u16 s1;
    u32 v1;
    u32 a0_guard_word;
    u32 a1_guard_word;

    s1 = a0;
    if ((u32)(u16)a0 == (u32)0xffff) {
        return 0;
    }
    SList_GetElemPtr((void *)s_pObjList, s1);
    a1_guard_word = (s32)s1 + 0xef;
    v1 = (u32)MdlMng;
    a0_guard_word = a1_guard_word << 3;
    *(u8 *)(((u32)(s32)((u8 *)MdlMng + (u32)((u32)(a0_guard_word - a1_guard_word) << 6)) + 6)) = a1;
    return 1;
}

signed int SfxMdl_EnableDraw(unsigned short a0 /* r4 */, signed int a1 /* r5 */) {
    u16 s1;
    s32 s0;
    u32 v1;

    s1 = a0;
    s0 = a1;
    if ((u32)(u16)a0 == (u32)0xffff) {
        return 0;
    }
    SList_GetElemPtr((void *)s_pObjList, s1);
    v1 = (u32)MdlMng;
    *(u8 *)(((u32)(s32)((u8 *)MdlMng + (u32)((u32)((s32)((s32)s1 + 0xef)) * (u32)(0x1c0))) + 2)) =
        (u32)((u32)s0 != 0) ^ 1;
    return 1;
}
