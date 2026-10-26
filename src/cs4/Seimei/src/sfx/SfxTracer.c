#include "common.h"

/* SfxTracer_AddLog @ 0x1CFD20 .. 0x1CFE20 (0x100 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void * SList_GetElemPtr(void *, unsigned short);
extern unsigned short SList_PushFront(void *, void *);
extern void sceVu0CopyVector(void *, void *);
extern u32 s_pLogList;
static u32 s_pLogList;

static u32 s_pObjList;

/* SfxTracer_Kill @ 0x1CFE20 .. 0x1CFE5C (0x3c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void * SList_GetElemPtr(void *, unsigned short);
static u32 s_pObjList;

/* SfxTracer_Create @ 0x1CFE60 .. 0x1CFF38 (0xd8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return unsigned short vs inferred float
 */

extern unsigned short SList_PushFront(void *, void *);

extern void *memset(void *, int, unsigned int);
static u32 s_pObjList;

/* SfxTracer_DrawAll @ 0x1CFF40 .. 0x1CFFA8 (0x68 bytes, frame 0x30) */

extern unsigned short SList_GetFrontElem(void *);
extern unsigned short SList_GetNextElem(void *, unsigned short);
signed int SfxTracer_Draw(unsigned short a0 /* r4 */);
static u32 s_pObjList;

/* SfxTracer_Draw @ 0x1CFFB0 .. 0x1D0090 (0xe0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar variable as a0_q
 *   quad: v0: 128-bit web split from its scalar variable as v0_q
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u_long128 SfxDraw_GetRenderStateBlock(void);
extern void SfxDraw_SetBlendType(unsigned short);
extern void SfxDraw_SetPrimitiveType(unsigned short);
extern void SfxDraw_SetTexture(void *);
extern void SfxDraw_UseTexture(signed int);
static signed int _DrawCross(unsigned short);
static signed int _DrawSpriteLine(unsigned short);
static signed int _DrawBelt(unsigned short);
extern void SfxDraw_SetRenderStateBlock(u_long128);

/* _DrawCross @ 0x1D0690 */
extern void sceVu0SubVector(void *, void *, void *);
extern void sceVu0Normalize(void *, void *);
extern void sceVu0ScaleVector(void *, void *, float);
extern void sceVu0AddVector(void *, void *, void *);
extern void * memcpy(void *, const void *, unsigned int);
extern void SfxDraw_DrawIndexedPrimitive2(void *, unsigned int *, void *, unsigned short *,
    unsigned short);
extern u32 lpDrawMng;
#ifndef DCOMP_COP2_5499821473
#define DCOMP_COP2_5499821473
static inline void dcomp_cop2_5499821473(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf16,0(%1)\nlqc2 vf17,0(%2)\nvopmula.xyz ACC,vf16,vf17\nvopmsub.xyz vf16,vf17,vf16\nsqc2 vf16,0(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif

typedef struct { u16 hHead; u16 nLog; u8 pad4[4]; float life; float width; } DC_OBJ;
typedef struct { float pos[4]; u8 pad10[0x10]; float life; u16 hNext; u16 hPrev; } DC_LOG;
typedef struct { u8 pad[0x230]; float cam[4]; } DC_MNG;



/* _DrawSpriteLine @ 0x1D09F0 .. 0x1D0C3C (0x24c bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @936 -> 0x248880
 *   fpu: float literal 0x00000000 at 0x1d0a68
 *   stack: address of the slot at 0x110 escapes at 0x1d0a90
 *   stack: address of the slot at 0x11c escapes at 0x1d0a90
 *   stack: address of the slot at 0x104 escapes at 0x1d0a90
 *   stack: address of the slot at 0x10c escapes at 0x1d0a90
 *   stack: address of the slot at 0x108 escapes at 0x1d0a90
 *   fpu: float literal 0x00000000 at 0x1d0ac8
 *   fpu: mov.s at 0x1d0ad8 is a float copy
 *   stack: address of the slot at 0x100 escapes at 0x1d0ae8
 *   stack: address of the slot at 0x110 escapes at 0x1d0ae8
 *   stack: address of the slot at 0xf0 escapes at 0x1d0b0c
 *   stack: address of the slot at 0xf0 escapes at 0x1d0b34
 *   stack: address of the slot at 0xf0 escapes at 0x1d0b34
 *   stack: address of the slot at 0xe0 escapes at 0x1d0b44
 *   stack: address of the slot at 0xf0 escapes at 0x1d0b44
 *   stack: address of the slot at 0xd0 escapes at 0x1d0b50
 *   fpu: mov.s at 0x1d0b64 is a float copy
 *   stack: address of the slot at 0xc0 escapes at 0x1d0b60
 *   stack: address of the slot at 0xf0 escapes at 0x1d0b60
 *   stack: address of the slot at 0xd0 escapes at 0x1d0b70
 *   stack: address of the slot at 0xc0 escapes at 0x1d0b70
 *   stack: address of the slot at 0xd0 escapes at 0x1d0b70
 *   fpu: float literal 0x00000000 at 0x1d0b8c
 *   fpu: mov.s at 0x1d0b9c is a float copy
 *   stack: address of the slot at 0xd0 escapes at 0x1d0bb0
 *   stack: address of the slot at 0xb0 escapes at 0x1d0bb0
 *   stack: address of the slot at 0x110 escapes at 0x1d0bb0
 *   stack: address of the slot at 0xd0 escapes at 0x1d0bc0
 *   stack: address of the slot at 0xd0 escapes at 0x1d0bc0
 *   stack: address of the slot at 0xe0 escapes at 0x1d0bc0
 *   fpu: float literal 0x00000000 at 0x1d0bcc
 *   literal: @936 initializes the 16-byte local at 0x110
 *   quad: a0: 128-bit web split from its scalar variable as a0_q
 *   quad: v0: 128-bit web split from its scalar variable as v0_q
 *   cfg: loop body is not one contiguous region: .L001D0A90
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void SfxDraw_SetColor(unsigned int);
extern void SfxDraw_DrawSprite_Wld(float *, void *, float, void *, void *, float);
extern void sceVu0SubVector(void *, void *, void *);
extern float sceVu0InnerProduct(void *, void *);
extern void sceVu0Normalize(void *, void *);
extern void sceVu0ScaleVector(void *, void *, float);
extern void sceVu0AddVector(void *, void *, void *);
extern u32 L936[];

/* _DrawBelt @ 0x1D0090 */
extern void SfxCalc_VecHermite(float *, float *, float *, float *, float *, float);
extern void SfxCalc_QtnSLerp(float *, float *, float *, float);
extern void SfxCalc_VecTransformByQtn(float *, float *, float *);


extern void sceVu0ApplyMatrix(void *, void *, void *);

extern void SfxUtil_CalcCutAnimST(signed int, signed int, signed int, void *);
extern void SfxDraw_DrawIndexedPrimitive3(unsigned short, void *, unsigned short *, unsigned short);
extern u32 VY[];


typedef struct { u16 b_hHead; u16 b_nStep; u8 b_pad4[4]; float b_life; float b_width; u8 b_pad10[8]; void *b_tex; u16 b_cutW; u16 b_cutH; u16 b_cutF; u16 b_pad22; float b_cutS; float b_alpha; } DB_OBJ;
typedef struct { sceVu0FVECTOR b_pos; sceVu0FVECTOR b_qtn; float b_life; u16 b_hNext; u16 b_hPrev; } DB_LOG;
typedef struct { float b_st[4]; float b_xyz[4]; } DB_VERT;
typedef struct { u8 b_pad[0x2b0]; float b_mat[16]; } DB_MNG;



/* SfxTracer_ActionAll @ 0x1D0C40 .. 0x1D0D2C (0xec bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1d0c64 is a float copy
 *   fpu: mov.s at 0x1d0c90 is a float copy
 *   cfg: loop body is not one contiguous region: .L001D0C78
 */



signed int SfxTracer_Action(unsigned short a0 /* r4 */, float f12 /* f12 */);
extern void * SList_GetElemPtr(void *, unsigned short);
extern signed int SList_Delete(void *, unsigned short);
extern u32 s_pLogList;
static u32 s_pObjList;

/* SfxTracer_Initialize @ 0x1D0EC0 .. 0x1D0F08 (0x48 bytes, frame 0x10) */

extern void * SList_Init(void *, unsigned int, unsigned short);
extern u32 s_tracer_obj_buff[];
extern u32 s_tracer_log_buff[];
extern u32 s_pLogList;
static u32 s_pObjList;
static u32 s_tracer_obj_buff[0x100];
static u32 s_tracer_log_buff[0xa00];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 SfxTracer_Initialize(void);
signed int SfxTracer_Action(unsigned short a0 , float f12 );
u32 SfxTracer_ActionAll(float f12 );
static signed int _DrawSpriteLine(unsigned short a0 );
static signed int _DrawCross(unsigned short hTracer_);
static signed int _DrawBelt(unsigned short hTracer_);
signed int SfxTracer_Draw(unsigned short a0 );
u32 SfxTracer_DrawAll(void);
unsigned short SfxTracer_Create(void *a0 );
signed int SfxTracer_Kill(unsigned short a0 );
signed int SfxTracer_AddLog(unsigned short a0 , float *a1 , float *a2 );


u32 SfxTracer_Initialize(void) {
    u8 *a0;
    s32 a1;
    s32 a2;
    u8 *v0;

    a0 = (u8 *)s_tracer_obj_buff;
    a1 = 0x400;
    a2 = 0x2c;
    v0 = (u8 *)SList_Init((void *)s_tracer_obj_buff, a1, a2);
    s_pObjList = (u32)v0;
    a0 = (u8 *)s_tracer_log_buff;
    a1 = 0x2800;
    a2 = 0x30;
    v0 = (u8 *)SList_Init((void *)s_tracer_log_buff, a1, a2);
    s_pLogList = (u32)v0;
    v0 = (u8 *)(s32)1;
    return (u32)v0;
}

/* SfxTracer_Action @ 0x1D0D30 .. 0x1D0EC0 (0x190 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1d0d60 is a float copy
 *   fpu: float literal 0x00000000 at 0x1d0d68
 *   cfg: kept branch: 0x1d0d7c if (..) goto .L001D0DB0
 *   cfg: loop body is not one contiguous region: .L001D0DC0
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int SfxTracer_Action(unsigned short a0 /* r4 */, float f12 /* f12 */) {
    u16 a1;
    float f20;
    u32 v0;
    float f1;
    float f0;
    u8 *s5;
    u16 s4;
    u8 *s3;
    u16 s2;
    u32 s1;
    u32 s0;
    u32 a0_2;

    a1 = a0;
    a0_2 = s_pObjList;
    f20 = (float)f12;
    v0 = (u32)SList_GetElemPtr((void *)a0_2, a1);
    f1 = *(float *)(((u8 *)v0 + 8));
    f0 = 0.0f;
    s5 = (u8 *)v0;
    if (f1 < 0.0f) {
        v0 = *(u16 *)(s5 + 2);
        if ((s32)v0 > (s32)1) {
            goto _L001D0DB0;
        }
        v0 = 0;
        return v0;
    }
    f0 = (f1 - f20);
    *(f32 *)(s5 + 8) = f0;
    v0 = *(u16 *)(s5 + 0x20);
    v0 = v0 + 1;
    *(u16 *)(s5 + 0x20) = v0;
    _L001D0DB0:;
    s4 = *(u16 *)s5;
    v0 = 0xffff;
    if ((u32)s4 != v0) {
        do {
            a0_2 = s_pLogList;
            a1 = s4;
            v0 = (u32)SList_GetElemPtr((void *)a0_2, a1);
            f0 = *(float *)(((u8 *)v0 + 0x20));
            s2 = *(u16 *)(((u8 *)v0 + 0x24));
            s3 = (u8 *)v0;
            if (f0 < f20) {
                a1 = *(u16 *)(s3 + 0x26);
                v0 = 0xffff;
                s1 = 0;
                s0 = 0;
                if ((u32)a1 != v0) {
                    a0_2 = s_pLogList;
                    v0 = (u32)SList_GetElemPtr((void *)a0_2, a1);
                    s1 = v0;
                }
                a1 = *(u16 *)(s3 + 0x24);
                v0 = 0xffff;
                if ((u32)a1 != v0) {
                    a0_2 = s_pLogList;
                    v0 = (u32)SList_GetElemPtr((void *)a0_2, a1);
                    s0 = v0;
                }
                if (s1 != 0) {
                    v0 = *(u16 *)(s3 + 0x24);
                    *(u16 *)(((u8 *)s1 + 0x24)) = v0;
                }
                if (s0 != 0) {
                    v0 = *(u16 *)(s3 + 0x26);
                    *(u16 *)(((u8 *)s0 + 0x26)) = v0;
                }
                v0 = *(u16 *)s5;
                if ((u32)s4 == v0) {
                    v0 = *(u16 *)(s3 + 0x24);
                    *(u16 *)s5 = v0;
                }
                a0_2 = s_pLogList;
                a1 = s4;
                SList_Delete((void *)a0_2, a1);
                v0 = *(u16 *)(s5 + 2);
                v0 = v0 + -1;
                *(u16 *)(s5 + 2) = v0;
            } else {
                f0 = (f0 - f20);
                *(f32 *)(s3 + 0x20) = f0;
            }
            s4 = s2;
            v0 = 0xffff;
        } while ((u32)s4 != v0);
    }
    v0 = 1;
    return v0;
}

u32 SfxTracer_ActionAll(float f12 /* f12 */) {
    u32 a0;
    float f20;
    u32 v0;
    u16 s0;
    u16 s3;
    u16 s2;
    u16 s1;

    a0 = s_pObjList;
    f20 = (float)f12;
    v0 = SList_GetFrontElem((void *)a0);
    s0 = v0;
    v0 = 0xffff;
    if ((u32)s0 != v0) {
        do {
            a0 = s_pObjList;
            v0 = SList_GetNextElem((void *)a0, s0);
            s3 = v0;
            v0 = SfxTracer_Action(s0, (float)(float)f20);
            if (v0 == 0) {
                a0 = s_pObjList;
                v0 = (u32)SList_GetElemPtr((void *)a0, s0);
                s2 = *(u16 *)v0;
                v0 = 0xffff;
                if ((u32)s2 != v0) {
                    do {
                        a0 = s_pLogList;
                        v0 = (u32)SList_GetElemPtr((void *)a0, s2);
                        s1 = *(u16 *)(((u8 *)v0 + 0x24));
                        a0 = s_pLogList;
                        SList_Delete((void *)a0, s2);
                        s2 = s1;
                        v0 = 0xffff;
                    } while ((u32)s2 != v0);
                }
                a0 = s_pObjList;
                SList_Delete((void *)a0, s0);
            }
            s0 = s3;
            v0 = 0xffff;
        } while ((u32)s0 != v0);
    }
    return 1;
}

static signed int _DrawSpriteLine(unsigned short a0 /* r4 */) {
    u16 a1;
    u32 v0;
    u8 *s4;
    u_long128 v0_q;
    u_long128 s3;
    float f21;
    u8 *s2;
    u16 s1;
    float *s0;
    float *s5;
    u32 *s6;
    u32 *s7;
    u8 *fp;
    float f12;
    float f1;
    float f0;
    float f20;
    s32 fpcc;
    u32 a0_2;
    struct stackFrame_110 { u8 b[16]; } stackFrame_110 __attribute__((aligned(16)));
    u8 stackFrame_100[16] __attribute__((aligned(16)));
    u8 stackFrame_F0[16] __attribute__((aligned(16)));
    u8 stackFrame_E0[16] __attribute__((aligned(16)));
    u8 stackFrame_D0[16] __attribute__((aligned(16)));
    u8 stackFrame_C0[16] __attribute__((aligned(16)));
    u8 stackFrame_B0[16] __attribute__((aligned(16)));

    a0_2 = s_pObjList;
    v0 = (u32)SList_GetElemPtr((void *)a0_2, a0);
    s4 = (u8 *)v0;
    v0_q = SfxDraw_GetRenderStateBlock();
    s3 = v0_q;
    SfxDraw_SetColor(0xffff);
    SfxDraw_SetBlendType(1);
    SfxDraw_SetTexture((void *)*(s32 *)(s4 + 0x18));
    a1 = *(u16 *)s4;
    v0 = (u32)L936;
    a0_2 = (u32)((u8 *)&stackFrame_110);
    f21 = 0.0f;
    v0 = 0xffff;
    stackFrame_110 = (struct stackFrame_110){{0x00, 0x00, 0x7f, 0x43, 0x00, 0x00, 0x7f, 0x43, 0x00,
        0x00, 0x7f, 0x43, 0x00, 0x00, 0x00, 0x43}};
    if ((u32)a1 != v0) {
        s0 = (float *)((u8 *)&stackFrame_110 + 0xc);
        s5 = (float *)((u8 *)&stackFrame_100[4]);
        s6 = (u32 *)((u8 *)&stackFrame_100[12]);
        s7 = (u32 *)((u8 *)&stackFrame_100[8]);
        fp = ((u8 *)&stackFrame_B0[4]);
        do {
            a0_2 = s_pLogList;
            v0 = (u32)SList_GetElemPtr((void *)a0_2, a1);
            f1 = *(float *)(((u8 *)v0 + 0x20));
            s1 = *(u16 *)(((u8 *)v0 + 0x24));
            s2 = (u8 *)v0;
            v0 = 0xffff;
            *(f32 *)s0 = (f1 / *(float *)(s4 + 0x10));
            if ((u32)s1 == v0) {
                f0 = *(float *)(s4 + 0xc);
                f12 = 0.0f;
                *(f32 *)s5 = f0;
                *(f32 *)((u8 *)&stackFrame_100[0]) = f0;
                *(u32 *)s6 = 0;
                *(u32 *)s7 = 0;
                SfxDraw_DrawSprite_Wld((float *)s2, (void *)((u8 *)&stackFrame_100[0]), 0.0f, (void
                    *)(u8 *)((u8 *)&stackFrame_110), (void *)0, (float)0.0f);
            } else {
                a0_2 = s_pLogList;
                v0 = (u32)SList_GetElemPtr((void *)a0_2, s1);
                sceVu0SubVector((void *)((u8 *)&stackFrame_F0[0]), (void *)v0, (void *)(u8 *)s2);
                f0 = sceVu0InnerProduct((void *)((u8 *)&stackFrame_F0[0]), (void *)((u8
                    *)&stackFrame_F0[0]));
                f20 = ({ float native_result_0; __asm__("sqrt.s %0,%1" : "=f"(native_result_0) :
                    "f"(f0)); native_result_0; });
                sceVu0Normalize((void *)((u8 *)&stackFrame_F0[0]), (void *)((u8
                    *)&stackFrame_F0[0]));
                f12 = *(float *)(s4 + 0x14);
                sceVu0ScaleVector((void *)((u8 *)&stackFrame_E0[0]), (void *)((u8
                    *)&stackFrame_F0[0]), f12);
                sceVu0CopyVector((void *)((u8 *)&stackFrame_D0[0]), (void *)s2);
                sceVu0ScaleVector((void *)((u8 *)&stackFrame_C0[0]), (void *)((u8
                    *)&stackFrame_F0[0]), (float)f21);
                sceVu0AddVector((void *)((u8 *)&stackFrame_D0[0]), (void *)((u8
                    *)&stackFrame_C0[0]), (void *)(u8 *)((u8 *)&stackFrame_D0[0]));
                f20 = (f20 - f21);
                do {
                    v0 = (u32)((u8 *)&stackFrame_B0[12]);
                    f0 = *(float *)(s4 + 0xc);
                    f12 = 0.0f;
                    ((f32 *)stackFrame_B0)[1] = f0;
                    *(f32 *)((u8 *)&stackFrame_B0[0]) = f0;
                    *(u32 *)v0 = 0;
                    v0 = (u32)((u8 *)&stackFrame_B0[8]);
                    ((u32 *)stackFrame_B0)[2] = 0;
                    SfxDraw_DrawSprite_Wld((float *)((u8 *)&stackFrame_D0[0]), (void *)((u8
                        *)&stackFrame_B0[0]), 0.0f, (void *)(u8 *)((u8 *)&stackFrame_110), (void
                        *)0, (float)0.0f);
                    sceVu0AddVector((void *)((u8 *)&stackFrame_D0[0]), (void *)((u8
                        *)&stackFrame_D0[0]), (void *)(u8 *)((u8 *)&stackFrame_E0[0]));
                    f1 = *(float *)(s4 + 0x14);
                    f0 = 0.0f;
                    f20 = (f20 - f1);
                    fpcc = 0.0f < f20;
                    f21 = (-f20);
                } while (fpcc);
            }
            v0 = 0xffff;
            a1 = s1;
        } while ((u32)s1 != v0);
    }
    SfxDraw_SetRenderStateBlock(s3);
    return 1;
}
static signed int _DrawCross(unsigned short hTracer_) {
    DC_OBJ *pObj;
    float aPos[160][4];
    float aST[160][4];
    unsigned int aCol[160];
    unsigned short aIdx[160];
    float WIDTH;
    int i;
    float vZ[4];
    float vT[4];
    unsigned short hElem;
    DC_LOG *pLogObj;
    DC_LOG *pNextLogObj;
    DC_LOG *pPrevLogObj;
    float vCross[4];
    int n0;
    int n1;

    pObj = (DC_OBJ *)SList_GetElemPtr((void *)s_pObjList, hTracer_);
    WIDTH = pObj->width;
    hElem = pObj->hHead;
    for (i = 0; hElem != 0xffff; i++) {
        n0 = i * 2;
        n1 = i * 2 + 1;
        pLogObj = (DC_LOG *)SList_GetElemPtr((void *)s_pLogList, hElem);
        pNextLogObj = (DC_LOG *)SList_GetElemPtr((void *)s_pLogList, pLogObj->hNext);
        pPrevLogObj = (DC_LOG *)SList_GetElemPtr((void *)s_pLogList, pLogObj->hPrev);
        sceVu0SubVector(vZ, ((DC_MNG *)lpDrawMng)->cam, pLogObj->pos);
        sceVu0Normalize(vZ, vZ);
        if (i == 0) {
            sceVu0SubVector(vT, pNextLogObj->pos, pLogObj->pos);
        } else if (pLogObj->hNext == 0xffff) {
            sceVu0SubVector(vT, pLogObj->pos, pPrevLogObj->pos);
        } else {
            sceVu0SubVector(vT, pNextLogObj->pos, pPrevLogObj->pos);
        }
        sceVu0Normalize(vT, vT);
        dcomp_cop2_5499821473(vCross, vT, vZ);
        sceVu0ScaleVector(vCross, vCross, WIDTH);
        sceVu0SubVector(aPos[n0], pLogObj->pos, vCross);
        sceVu0AddVector(aPos[n1], pLogObj->pos, vCross);
        {
            float vST[4] = {0.0f, 0.0f, 1.0f, 0.0f};
            vST[0] = (1.0f / (float)pObj->nLog) * (float)i;
            memcpy(aST[n0], vST, 16);
        }
        {
            float vST[4] = {0.0f, 1.0f, 1.0f, 0.0f};
            vST[0] = (1.0f / (float)pObj->nLog) * (float)i;
            memcpy(aST[n1], vST, 16);
        }
        aCol[n0] = aCol[n1] = (u8)(u32)(128.0f * (pLogObj->life / pObj->life)) + 0x80808000;
        aIdx[n0] = n0;
        aIdx[n1] = n1;
        hElem = pLogObj->hNext;
        if (i == 80) break;
    }
    SfxDraw_DrawIndexedPrimitive2(aPos, aCol, aST, aIdx, i * 2);
    return 1;
}

static signed int _DrawBelt(unsigned short hTracer_) {
    DB_OBJ *pObj;
    float CUT_WIDTH;
    float CUT_HEIGHT;
    DB_VERT *pVert;
    u8 vert_buff[7680];
    s8 vert_idx[480];
    unsigned short hElem;
    int i;
    DB_LOG *pLogObj;
    sceVu0FVECTOR *pPos0;
    DB_LOG *pPrevLogObj;
    DB_LOG *pNextLogObj;
    DB_LOG *pNextNextLogObj;
    unsigned short hNextElem;
    sceVu0FVECTOR *pPos1;
    sceVu0FVECTOR *pPos2;
    sceVu0FVECTOR *pPos3;
    int j;
    int k;
    int idx;
    float pos[4];
    float qtn[4];
    float offset[4];
    float st[4];
    u_long128 sb;
    unsigned short *pIdx;

    pObj = (DB_OBJ *)SList_GetElemPtr((void *)s_pObjList, hTracer_);
    CUT_WIDTH = 1.0f / (float)pObj->b_cutW;
    CUT_HEIGHT = 1.0f / (float)pObj->b_cutH;
    hElem = pObj->b_hHead;
    pVert = (DB_VERT *)vert_buff;
    pIdx = (unsigned short *)vert_idx;
    i = 0;
    while (hElem != 0xffff) {
        pLogObj = (DB_LOG *)SList_GetElemPtr((void *)s_pLogList, hElem);
        pPrevLogObj = (pLogObj->b_hPrev != 0xffff) ? (DB_LOG *)SList_GetElemPtr((void *)s_pLogList, pLogObj->b_hPrev) : 0;
        if (pLogObj->b_hNext != 0xffff) {
            pNextLogObj = (DB_LOG *)SList_GetElemPtr((void *)s_pLogList, pLogObj->b_hNext);
        } else {
            pNextLogObj = 0;
        }
        pNextNextLogObj = (pNextLogObj != 0 && pNextLogObj->b_hNext != 0xffff) ? (DB_LOG *)SList_GetElemPtr((void *)s_pLogList, pNextLogObj->b_hNext) : 0;
        hNextElem = pLogObj->b_hNext;
        pPos0 = pPrevLogObj ? &pPrevLogObj->b_pos : 0;
        pPos1 = pLogObj ? &pLogObj->b_pos : 0;
        pPos2 = pNextLogObj ? &pNextLogObj->b_pos : 0;
        pPos3 = pNextNextLogObj ? &pNextNextLogObj->b_pos : 0;
        idx = i * 6;
        for (k = 0; k < 3; k++) {
            if (pNextLogObj == 0 && 0 < k) break;
            if (k == 0) {
                sceVu0CopyVector(pos, pPos1);
            } else {
                SfxCalc_VecHermite(pos, (float *)pPos0, (float *)pPos1, (float *)pPos2, (float *)pPos3, 0.33333334f * (float)k);
            }
            if (k == 0) {
                sceVu0CopyVector(qtn, pLogObj->b_qtn);
            } else {
                SfxCalc_QtnSLerp(qtn, pLogObj->b_qtn, pNextLogObj->b_qtn, 0.33333334f * (float)k);
            }
            for (j = 0; j < 2; j++) {
                if (j == 0) {
                    sceVu0CopyVector(pVert[idx + j].b_xyz, pos);
                } else {
                    SfxCalc_VecTransformByQtn(offset, qtn, (float *)VY);
                    sceVu0ScaleVector(offset, offset, pObj->b_width);
                    sceVu0AddVector(pVert[idx + j].b_xyz, pos, offset);
                }
                sceVu0ApplyMatrix(pVert[idx + j].b_xyz, ((DB_MNG *)lpDrawMng)->b_mat, pVert[idx + j].b_xyz);
                sceVu0ScaleVector(pVert[j + idx].b_xyz, pVert[j + idx].b_xyz, 1.0f / pVert[idx + j].b_xyz[3]);
                {
                    float vST[4] = {0.0f, 0.0f, 1.0f, 0.0f};
                    vST[0] = (1.0f / (float)pObj->b_nStep) * (float)i;
                    vST[1] = (float)j;
                    memcpy(&pVert[idx + j], vST, 16);
                }
                SfxUtil_CalcCutAnimST(pObj->b_cutW, pObj->b_cutH, (int)(pObj->b_cutS * (float)pObj->b_cutF), st);
                pVert[idx + j].b_st[0] = st[0] + (CUT_WIDTH / (float)(pObj->b_nStep * 3)) * (float)(i * 3 + k);
                pVert[j + idx].b_st[1] = st[1] + CUT_HEIGHT * (float)j;
                pVert[idx + j].b_st[2] = 1.0f;
                *(u32 *)&pVert[j + idx].b_st[3] = (u8)(128.0f * pObj->b_alpha) + 0x80808000;
                pIdx[idx + j] = j + idx;
            }
            idx += 2;
        }
        i++;
        hElem = hNextElem;
        if ((u32)i == 80) break;
    }
    sb = SfxDraw_GetRenderStateBlock();
    SfxDraw_SetTexture(pObj->b_tex);
    SfxDraw_DrawIndexedPrimitive3(0xb, pVert, pIdx, (((((((((((i - 1))))))))))) * 6);
    SfxDraw_SetRenderStateBlock(sb);
    return 1;
}

signed int SfxTracer_Draw(unsigned short a0 /* r4 */) {
    u32 v1;
    u8 *s2;
    u_long128 v0_q;
    u_long128 s1;
    u32 v0;
    u32 a0_2;

    a0_2 = s_pObjList;
    v0 = (u32)SList_GetElemPtr((void *)a0_2, a0);
    s2 = (u8 *)v0;
    v0_q = SfxDraw_GetRenderStateBlock();
    s1 = v0_q;
    v0 = *(u16 *)(s2 + 2);
    if ((s32)v0 < (s32)2) {
        v0 = 1;
    } else {
        a0_2 = 1;
        SfxDraw_SetBlendType(a0_2);
        a0_2 = 4;
        SfxDraw_SetPrimitiveType(a0_2);
        a0_2 = *(s32 *)(s2 + 0x18);
        SfxDraw_SetTexture((void *)a0_2);
        a0_2 = 1;
        SfxDraw_UseTexture(a0_2);
        v1 = *(u16 *)(s2 + 4);
        v0 = 2;
        switch (v1) {
        case 1:
            a0_2 = a0;
            _DrawCross(a0);
            break;
        case 2:
            a0_2 = a0;
            _DrawSpriteLine(a0);
            break;
        case 0:
            a0_2 = a0;
            _DrawBelt(a0);
        }
        SfxDraw_SetRenderStateBlock(s1);
        v0 = 1;
    }
    return v0;
}

u32 SfxTracer_DrawAll(void) {
    u32 a0;
    u32 v0;
    u16 s1;
    u16 s0;

    a0 = s_pObjList;
    s1 = SList_GetFrontElem((void *)a0);
    v0 = 0xffff;
    if ((u32)s1 != v0) {
        do {
            a0 = s_pObjList;
            s0 = SList_GetNextElem((void *)a0, s1);
            SfxTracer_Draw(s1);
            s1 = s0;
            v0 = 0xffff;
        } while ((u32)s1 != v0);
    }
    return 1;
}

unsigned short SfxTracer_Create(void *a0 /* r4 */) {
    u8 *s0;
    u32 v0;
    u16 s2;
    u8 *s1;
    u32 v1;
    float f0;

    s0 = (u8 *)a0;
    a0 = (void *)s_pObjList;
    v0 = SList_PushFront(a0, (void *)0);
    s2 = v0;
    v0 = 0xffff;
    if ((u32)s2 == v0) {
        return v0;
    }
    a0 = (void *)s_pObjList;
    v0 = (u32)SList_GetElemPtr(a0, s2);
    s1 = (u8 *)v0;
    memset((void *)(u32)s1, 0, 0x2c);
    v1 = 0xffff;
    *(u16 *)s1 = 0xffff;
    f0 = *(float *)(s0 + 0x10);
    *(f32 *)(s1 + 8) = f0;
    *(u16 *)(s1 + 2) = 0;
    v1 = *(u16 *)s0;
    *(u16 *)(s1 + 4) = v1;
    v1 = *(s32 *)(s0 + 4);
    *(u32 *)(s1 + 0x18) = v1;
    f0 = *(float *)(s0 + 8);
    *(f32 *)(s1 + 0xc) = f0;
    f0 = *(float *)(s0 + 0xc);
    *(f32 *)(s1 + 0x10) = f0;
    f0 = *(float *)(s0 + 0x14);
    *(f32 *)(s1 + 0x14) = f0;
    v1 = *(u16 *)(s0 + 0x18);
    *(u16 *)(s1 + 0x1c) = v1;
    v1 = *(u16 *)(s0 + 0x1a);
    *(u16 *)(s1 + 0x1e) = v1;
    f0 = *(float *)(s0 + 0x1c);
    *(f32 *)(s1 + 0x24) = f0;
    f0 = *(float *)(s0 + 0x20);
    *(f32 *)(s1 + 0x28) = f0;
    return s2;
}

signed int SfxTracer_Kill(unsigned short a0 /* r4 */) {
    u8 *v0;

    v0 = (u8 *)SList_GetElemPtr((void *)s_pObjList, a0);
    if ((u32)v0 == 0) {
        v0 = (u8 *)0;
    } else {
        *(u32 *)(v0 + 8) = 0;
        v0 = (u8 *)(s32)1;
    }
    return (signed int)v0;
}

signed int SfxTracer_AddLog(unsigned short a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */) {
    u32 s4;
    u32 s3;
    u16 a1_narrow; // a1
    u8 *s2;
    u16 s1;
    u8 *s0;
    u32 v0;
    u32 a0_2;

    s4 = (u32)a1;
    a0_2 = s_pObjList;
    s3 = (u32)a2;
    v0 = (u32)SList_GetElemPtr((void *)a0_2, a0);
    s2 = (u8 *)v0;
    if ((u32)s2 == 0) {
        v0 = 0;
    } else {
        a0_2 = s_pLogList;
        v0 = SList_PushFront((void *)a0_2, (void *)0);
        s1 = v0;
        v0 = 0xffff;
        if ((u32)s1 == v0) {
            v0 = 0;
        } else {
            v0 = *(u16 *)(s2 + 2);
            *(u16 *)(s2 + 2) = v0 + 1;
            a0_2 = s_pLogList;
            v0 = (u32)SList_GetElemPtr((void *)a0_2, s1);
            s0 = (u8 *)v0;
            sceVu0CopyVector((void *)s0, (void *)s4);
            a1 = (float *)s3;
            if (s3 != 0) {
                sceVu0CopyVector((void *)(u32)(s32)(s0 + 0x10), (void *)a1);
            }
            *(f32 *)(s0 + 0x20) = *(float *)(s2 + 0x10);
            *(u16 *)(s0 + 0x26) = 0xffff;
            v0 = *(u16 *)s2;
            *(u16 *)(s0 + 0x24) = v0;
            a1_narrow = *(u16 *)s2;
            if ((u32)a1_narrow != (u32)0xffff) {
                a0_2 = s_pLogList;
                v0 = (u32)SList_GetElemPtr((void *)a0_2, a1_narrow);
                *(u16 *)(((u8 *)v0 + 0x26)) = s1;
            }
            *(u16 *)s2 = s1;
            v0 = 1;
        }
    }
    return v0;
}
