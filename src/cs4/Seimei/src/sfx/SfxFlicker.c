#include "common.h"

/* SfxFlicker_SetCycle @ 0x1C4220 .. 0x1C4268 (0x48 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1c4238 is a float copy
 */

extern void * SList_GetElemPtr(void *, unsigned short);
static u32 s_pObjList;

/* SfxFlicker_SetAmplitude @ 0x1C4270 .. 0x1C42B8 (0x48 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1c4288 is a float copy
 */


static u32 s_pObjList;

/* SfxFlicker_SetScale @ 0x1C42C0 .. 0x1C4308 (0x48 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1c42d8 is a float copy
 */


static u32 s_pObjList;

/* SfxFlicker_SetPos @ 0x1C4310 .. 0x1C4370 (0x60 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static u32 s_pObjList;

/* Source-shaped 3D mesh candidate: same strip model, (7,7) FrameBuff selectors. */
extern u_long128 SfxDraw_GetRenderStateBlock(void);
extern void SfxDraw_SetPrimitiveType(unsigned short);
extern void SfxDraw_UseTexture(signed int);
extern void SfxDraw_SetColor(unsigned int);
extern void SfxDraw_EnableZTest(signed int);
extern void SfxDraw_UseST(signed int);
extern void SfxDraw_SetTexture_FrameBuff(unsigned short, unsigned short, void *);
extern void SfxDraw_DrawIndexedPrimitive(void *, void *, unsigned short *, unsigned short);
extern void SfxDraw_SetRenderStateBlock(u_long128);
extern struct dw_2067600_fields s_aCircleVertices[];
extern float sinf(float);

struct SfxFlickerP { float pos_x; float pos_y; float pos_z; float scale; float amplitude; float cycle; float time; };


/* _DrawFanCircle_3D_YAxis @ 0x1C4B70 .. 0x1C50EC (0x57c bytes, frame 0x2d0) */

extern void sceVu0SubVector(void *, void *, void *);
extern void sceVu0Normalize(void *, void *);
extern void SfxCalc_MakeMatrixFromDir(void *, float *);
extern void sceVu0CopyVector(void *, void *);
extern void sceVu0UnitMatrix(void *);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern void sceVu0ScaleVector(void *, void *, float);
extern u_long128 SfxDraw_GetRenderStateBlock(void);
extern void SfxDraw_SetPrimitiveType(unsigned short);
extern void SfxDraw_SetBlendType(unsigned short);
extern void SfxDraw_SetTexture_FrameBuff(unsigned short, unsigned short, void *);
extern void SfxDraw_UseST(signed int);
extern void SfxDraw_DrawIndexedPrimitive2(void *, unsigned int *, void *, unsigned short *,
    unsigned short);
extern void SfxDraw_SetRenderStateBlock(u_long128);
extern float sinf(float);
extern u32 lpDrawMng;
extern u16 s_aCircleIndices[];
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif


#ifndef PROTO_DW_2065842_FIELDS
#define PROTO_DW_2065842_FIELDS
struct dw_2065842_fields { unsigned short unused : 8; unsigned short : 8; };
#endif
#ifndef PROTO_DW_2064745_FIELDS
#define PROTO_DW_2064745_FIELDS
struct dw_2064745_fields { float pos_x; float pos_y; float pos_z; float scale; float amplitude; float cycle; float time; unsigned short type; struct dw_2065842_fields flag; unsigned char dmy[1]; };
#endif
#ifndef PROTO_DW_2067600_FIELDS
#define PROTO_DW_2067600_FIELDS
struct dw_2067600_fields { float pos[4]; float uv[4]; unsigned int color; unsigned char _pad0[12]; };
#endif

#define VTX s_aCircleVertices


/* _DrawFanCircle_3D @ 0x1C50F0 .. 0x1C5664 (0x574 bytes, frame 0x2f0) */


















#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif


#ifndef PROTO_DW_2065842_FIELDS
#define PROTO_DW_2065842_FIELDS
struct dw_2065842_fields { unsigned short unused : 8; unsigned short : 8; };
#endif
#ifndef PROTO_DW_2064745_FIELDS
#define PROTO_DW_2064745_FIELDS
struct dw_2064745_fields { float pos_x; float pos_y; float pos_z; float scale; float amplitude; float cycle; float time; unsigned short type; struct dw_2065842_fields flag; unsigned char dmy[1]; };
#endif
#ifndef PROTO_DW_2067600_FIELDS
#define PROTO_DW_2067600_FIELDS
struct dw_2067600_fields { float pos[4]; float uv[4]; unsigned int color; unsigned char _pad0[12]; };
#endif

#define VTX s_aCircleVertices


/* _DrawFanCircle_2D @ 0x1C5670 .. 0x1C5840 (0x1d0 bytes, frame 0x1b0) */
/*
 * dcomp notes:
 *   quad: s0: 128-bit web split from its scalar uses
 *   stack: address of the slot at 0x90 escapes at 0x1c56b8
 *   stack: address of the slot at 0x120 escapes at 0x1c56b8
 *   stack: address of the slot at 0x120 escapes at 0x1c56b8
 *   stack: address of the slot at 0x90 escapes at 0x1c56b8
 *   fpu: float literal 0x3f000000 at 0x1c56d8
 *   fpu: float literal 0x40c90fdb at 0x1c5744
 *   fpu: float literal 0x40000000 at 0x1c5750
 *   fpu: float literal 0x3c8ef34d at 0x1c5764
 *   stack: address of the slot at 0x80 escapes at 0x1c57ec
 *   stack: address of the slot at 0x120 escapes at 0x1c5804
 *   stack: address of the slot at 0x90 escapes at 0x1c5804
 *   quad: a0: 128-bit web split from its scalar variable as a0_q
 *   quad: v0: 128-bit web split from its scalar variable as v0_q
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void sceVu0CopyVector(void *, void *);
extern void sceVu0ScaleVector(void *, void *, float);
extern u_long128 SfxDraw_GetRenderStateBlock(void);
extern void SfxDraw_SetPrimitiveType(unsigned short);
extern void SfxDraw_SetTexture_FrameBuff(unsigned short, unsigned short, void *);
extern void SfxDraw_DrawIndexedPrimitive(void *, void *, unsigned short *, unsigned short);
extern void SfxDraw_SetRenderStateBlock(u_long128);
extern u16 s_aCircleIndices[];


/* SfxFlicker_Delete @ 0x1C5840 .. 0x1C584C (0xc bytes) */
/*
 * dcomp notes:
 *   tail: j SList_Delete at 0x1c5844 leaves the function
 *   declaration vs inferred signature: return signed int vs inferred void
 */

extern signed int SList_Delete(void *, unsigned short);
static u32 s_pObjList;

/* SfxFlicker_Create @ 0x1C5850 .. 0x1C58F8 (0xa8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return unsigned short vs inferred u32
 */

extern unsigned short SList_PushFront(void *, void *);

extern void *memset(void *, int, unsigned int);
static u32 s_pObjList;

/* SfxFlicker_Draw @ 0x1C5900 .. 0x1C59A8 (0xa8 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1c5920 writes a register its branch at 0x1c591c reads
 *   delay: addiu at 0x1c5934 writes a register its branch at 0x1c5930 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int _DrawFanCircle_2D(void *);
static signed int _DrawFanCircle_3D(void *);
static signed int _DrawFanCircle_3D_YAxis(void *);
static u32 s_pObjList;

/* SfxFlicker_Action @ 0x1C59B0 .. 0x1C5A00 (0x50 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1c59c8 is a float copy
 */


static u32 s_pObjList;

extern void *SList_Init(void *, unsigned int, unsigned short);
extern void sceVu0CopyVector(void *, void *);
extern u32 VW[];
static u32 s_data_buff[256];
static struct dw_2067600_fields s_aCircleVertices[9]; /* 9 x 48 B (was u32[108]) */
static u16 s_aCircleIndices[10];


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int SfxFlicker_Initialize(void);
u32 SfxFlicker_Action(unsigned short a0 , float f12 );
signed int SfxFlicker_Draw(unsigned short a0 );
unsigned short SfxFlicker_Create(unsigned short a0 );
signed int SfxFlicker_Delete(unsigned short a0 );
static signed int _DrawRectMesh_2D(void *a0);
static signed int _DrawRectMesh_3D(void *a0);
signed int SfxFlicker_SetPos(unsigned short a0 , float *a1 );
u32 SfxFlicker_SetScale(unsigned short a0 , float f12 );
u32 SfxFlicker_SetAmplitude(unsigned short a0 , float f12 );
u32 SfxFlicker_SetCycle(unsigned short a0 , float f12 );

signed int SfxFlicker_Initialize(void) {
    u32 i;
    u8 *vertex;
    float angle;
    s_pObjList = (u32)SList_Init(s_data_buff, 0x400, 0x20);
    sceVu0CopyVector(s_aCircleVertices, VW);
    ((u32 *)s_aCircleVertices)[4] = 0x3f000000;
    i = 0;
    vertex = (u8 *)s_aCircleVertices;
    ((u32 *)s_aCircleVertices)[5] = 0x3f000000;
    ((u32 *)s_aCircleVertices)[6] = 0x3f800000;
    ((u32 *)s_aCircleVertices)[7] = 0;
    ((u32 *)s_aCircleVertices)[8] = 0x80808080;
    do {
        angle = 0.7853982f * (float)i;
        *(float *)(vertex + 0x30) = cosf(angle);
        *(float *)(vertex + 0x34) = sinf(angle);
        *(u32 *)(vertex + 0x38) = 0;
        *(u32 *)(vertex + 0x3c) = 0x3f800000;
        *(float *)(vertex + 0x40) = 0.5f + 0.496f * cosf(angle);
        *(float *)(vertex + 0x44) = 0.5f + 0.496f * sinf(angle);
        *(u32 *)(vertex + 0x48) = 0x3f800000;
        *(u32 *)(vertex + 0x4c) = 0;
        *(u32 *)(vertex + 0x50) = 0x80808000;
        i = (u16)(i + 1);
        vertex += 0x30;
    } while ((s32)i < 8);
    {
        u16 *dest;
        u32 index;
        index = 0;
        dest = s_aCircleIndices;
        do {
            dest[0] = index;
            dest[1] = index + 1;
            dest[2] = index + 2;
            index = (u16)(index + 3);
            dest += 3;
        } while ((s32)index < 9);
        s_aCircleIndices[index] = 1;
    }
    return 1;
}

u32 SfxFlicker_Action(unsigned short a0 /* r4 */, float f12 /* f12 */) {
    float f20;
    u8 *v0;
    float f0;

    f20 = (float)f12;
    v0 = (u8 *)SList_GetElemPtr((void *)s_pObjList, a0);
    if ((u32)v0 == 0) {
        v0 = (u8 *)0;
    } else {
        f0 = *(float *)(v0 + 0x18);
        f0 = (f0 + f20);
        *(f32 *)(v0 + 0x18) = f0;
        v0 = (u8 *)(s32)1;
    }
    return (u32)v0;
}

signed int SfxFlicker_Draw(unsigned short a0 /* r4 */) {
    u32 v0;
    s32 v1;
    u32 a0_2; // a0

    a0_2 = s_pObjList;
    v0 = (u32)SList_GetElemPtr((void *)a0_2, a0);
    a0_2 = *(u16 *)(((u8 *)v0 + 0x1c));
    v1 = 4;
    switch (a0_2) {
    case 0:
        a0_2 = v0;
        _DrawRectMesh_2D((void *)a0_2);
        break;
    case 1:
        a0_2 = v0;
        _DrawFanCircle_2D((void *)a0_2);
        break;
    case 2:
        a0_2 = v0;
        _DrawRectMesh_3D((void *)a0_2);
        break;
    case 3:
        a0_2 = v0;
        _DrawFanCircle_3D((void *)a0_2);
        break;
    case 4:
        a0_2 = v0;
        _DrawFanCircle_3D_YAxis((void *)a0_2);
    }
    v0 = 1;
    return v0;
}

unsigned short SfxFlicker_Create(unsigned short a0 /* r4 */) {
    u16 s0;
    u32 v0;
    u16 s2;
    u8 *s1;
    s32 v1;
    u32 a0_2; // a0

    s0 = a0;
    a0_2 = s_pObjList;
    v0 = SList_PushFront((void *)a0_2, (void *)0);
    s2 = v0;
    v0 = 0xffff;
    if ((u32)s2 == v0) {
        return v0;
    }
    a0_2 = s_pObjList;
    v0 = (u32)SList_GetElemPtr((void *)a0_2, s2);
    s1 = (u8 *)v0;
    memset((void *)(u32)s1, 0, 0x20);
    v1 = 0x43800000;
    a0_2 = 0x3f800000;
    *(u32 *)s1 = 0x43800000;
    v1 = 0x43600000;
    *(u32 *)(s1 + 4) = 0x43600000;
    *(u32 *)(s1 + 8) = 0;
    v1 = 0x3f000000;
    *(u32 *)(s1 + 0xc) = 0x3f800000;
    *(u32 *)(s1 + 0x10) = 0x3f000000;
    *(u32 *)(s1 + 0x14) = 0x3f800000;
    *(u16 *)(s1 + 0x1c) = s0;
    return s2;
}

signed int SfxFlicker_Delete(unsigned short a0 /* r4 */) {
    u32 a0_2; // a0

    a0_2 = s_pObjList;
    return SList_Delete((void *)a0_2, a0);
}

static signed int _DrawFanCircle_2D(void *a0 /* r4 */) {
    u8 *s5;
    s32 s4;
    int count;
    u8 *s6;
    float *s3;
    u8 *s2;
    u8 *s1;
    u8 *s0;
    u8 *a2;
    float f12;
    float f3;
    float f1;
    float f0;
    u_long128 v0_q;
    u_long128 s0_q;
    void *a0_2; // a0
    s32 v0;
    u8 stackFrame_120[144] __attribute__((aligned(16)));
    u8 stackFrame_90[144] __attribute__((aligned(16)));
    u8 stackFrame_80[16] __attribute__((aligned(16)));

    s6 = ((u8 *)&stackFrame_90[0]);
    s5 = (u8 *)a0;
    s4 = 0;
    s3 = (float *)((u8 *)&stackFrame_120[0]);
    s2 = (u8 *)s_aCircleVertices;
    s1 = (u8 *)s3;
    s0 = s6;
    do {
        sceVu0CopyVector((void *)s1, (void *)s2);
        sceVu0CopyVector((void *)s0, (void *)(s2 + 0x10));
        f12 = (0.5f * *(float *)(s5 + 0xc));
        sceVu0ScaleVector((void *)s1, (void *)s1, f12);
        f1 = *(float *)s1;
        s2 = (u8 *)(s2 + 0x30);
        *(f32 *)s1 = (f1 + *(float *)s5);
        f1 = *(float *)(s5 + 4);
        *(f32 *)(s1 + 4) = (*(float *)(s1 + 4) + f1);
        f1 = *(float *)(s5 + 8);
        *(f32 *)(s1 + 8) = (*(float *)(s1 + 8) + f1);
        s0 = s0 + 0x10;
        s4 = s4 + 1;
        s1 = (u8 *)(s1 + 0x10);
    } while (s4 < (s32)9);
    count = 0;
    do {
        f0 = sinf(2.0f * (6.2831855f * *(float *)(s6 + 4)) + 0.01745f * (float)*(float *)(s5 + 0x18));
        f1 = *(float *)s3;
        s6 = (u8 *)(s6 + 0x10);
        *(f32 *)s3 = (f1 + (*(float *)(s5 + 0x10) * f0));
        count++;
        s3 = (float *)(u8 *)(s3 + 4);
    } while (count < 9);
    v0_q = SfxDraw_GetRenderStateBlock();
    f1 = *(float *)(s5 + 0xc);
    a0_2 = (void *)(s32)5;
    s0_q = v0_q;
    *(f32 *)((u8 *)&stackFrame_80[0]) = (*(float *)s5 - f1);
    ((f32 *)stackFrame_80)[1] = (*(float *)(s5 + 4) - f1);
    ((f32 *)stackFrame_80)[2] = (*(float *)s5 + f1);
    ((f32 *)stackFrame_80)[3] = (*(float *)(s5 + 4) + f1);
    SfxDraw_SetPrimitiveType((unsigned short)a0_2);
    a0_2 = (void *)(s32)8;
    SfxDraw_SetTexture_FrameBuff((unsigned short)a0_2, (s32)a0_2, (void *)(u8 *)((u8
        *)&stackFrame_80[0]));
    a2 = (u8 *)s_aCircleIndices;
    SfxDraw_DrawIndexedPrimitive((void *)((u8 *)&stackFrame_120[0]), (void *)((u8
        *)&stackFrame_90[0]), (unsigned short *)s_aCircleIndices, 0xa);
    SfxDraw_SetRenderStateBlock(s0_q);
    return 1;
}
static signed int _DrawFanCircle_3D(void *a0) {
    struct dw_2064745_fields *pFlicker_ = (struct dw_2064745_fields *)a0;
    float aPos[9][4];
    float aST[9][4];
    unsigned int aColor[9];
    float bound_rect[4] = {512.0f, 448.0f, 0.0f, 0.0f};
    float mTrn[4][4];
    int i;
    float mRot[4][4];
    float mScl[4][4];
    float vDir[4];
    float vPos[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    float x;
    u_long128 sb;
    float rect[4];

    vPos[0] = pFlicker_->pos_x;
    vPos[1] = pFlicker_->pos_y;
    vPos[2] = pFlicker_->pos_z;
    sceVu0SubVector(vDir, (void *)(lpDrawMng + 0x230), vPos);
    sceVu0Normalize(vDir, vDir);
    SfxCalc_MakeMatrixFromDir(mRot, vDir);
    sceVu0CopyVector(mRot[3], vPos);
    sceVu0UnitMatrix(mScl);
    mScl[0][0] = pFlicker_->scale;
    mScl[1][1] = pFlicker_->scale;
    mScl[2][2] = pFlicker_->scale;
    dcomp_cop2_9397A3F6B7(mTrn, mRot, mScl);
    dcomp_cop2_9397A3F6B7(mTrn, (void *)(lpDrawMng + 0x2b0), mTrn);
    for (i = 0; i < 9; i++) {
        sceVu0ApplyMatrix(aPos[i], mTrn, VTX[i].pos);
        sceVu0ScaleVector(aPos[i], aPos[i], 1.0f / aPos[i][3]);
        aPos[i][0] = (float)(s32)(256.0f + (aPos[i][0] - 2048.0f));
        aPos[i][1] = (float)(s32)(224.0f + (aPos[i][1] - 2048.0f));
        if (bound_rect[0] < aPos[i][0]) {
            bound_rect[0] = aPos[i][0];
        }
        if (bound_rect[1] < aPos[i][1]) {
            bound_rect[1] = aPos[i][1];
        }
        if (aPos[i][2] < bound_rect[2]) {
            bound_rect[2] = aPos[i][2];
        }
        if (aPos[i][3] < bound_rect[3]) {
            bound_rect[3] = aPos[i][3];
        }
    }
    for (i = 0; i < 9; i++) {
        aST[i][0] = (aPos[i][0] - bound_rect[0]) / (bound_rect[2] - bound_rect[0]);
        aST[i][1] = (aPos[i][1] - bound_rect[1]) / (bound_rect[3] - bound_rect[1]);
        aST[i][2] = 1.0f;
        aST[i][3] = 0.0f;
    }
    for (i = 8; i >= 0; i--) {
        aColor[i] = VTX[i].color;
    }
    for (i = 0; i < 9; i++) {
        x = pFlicker_->amplitude * sinf(6.2831855f * pFlicker_->cycle * (pFlicker_->time + 0.2f * VTX[i].uv[1]));
        {
            float vTmp[4] = {0.0f, 0.0f, 0.0f, 1.0f};
            vTmp[0] = x + VTX[i].pos[0];
            vTmp[1] = VTX[i].pos[1];
            vTmp[2] = VTX[i].pos[2];
            sceVu0ApplyMatrix(aPos[i], mTrn, vTmp);
        }
        sceVu0ScaleVector(aPos[i], aPos[i], 1.0f / aPos[i][3]);
        aPos[i][0] = (float)(s32)(256.0f + (aPos[i][0] - 2048.0f));
        aPos[i][1] = (float)(s32)(224.0f + (aPos[i][1] - 2048.0f));
    }
    sb = SfxDraw_GetRenderStateBlock();
    sceVu0CopyVector(rect, bound_rect);
    SfxDraw_SetPrimitiveType(5);
    SfxDraw_SetBlendType(0);
    SfxDraw_SetTexture_FrameBuff(8, 8, rect);
    SfxDraw_UseST(1);
    SfxDraw_DrawIndexedPrimitive2(aPos, aColor, aST, s_aCircleIndices, 10);
    SfxDraw_SetRenderStateBlock(sb);
    return 1;
}
static signed int _DrawFanCircle_3D_YAxis(void *a0) {
    extern u32 VX[];
    extern u32 VY[];
    extern u32 VZ[];
    struct dw_2064745_fields *pFlicker_ = (struct dw_2064745_fields *)a0;
    float aPos[9][4];
    float aST[9][4];
    unsigned int aColor[9];
    float bound_rect[4] = {512.0f, 448.0f, 0.0f, 0.0f};
    float mTrn[4][4];
    int i;
    float mMdl[4][4];
    float mScl[4][4];
    float x;
    u_long128 sb;
    float rect[4];

    sceVu0CopyVector(mMdl[0], VX);
    sceVu0CopyVector(mMdl[1], VZ);
    sceVu0CopyVector(mMdl[2], VY);
    sceVu0ScaleVector(mMdl[2], mMdl[2], -1.0f);
    mMdl[3][0] = pFlicker_->pos_x;
    mMdl[3][1] = pFlicker_->pos_y;
    mMdl[3][2] = pFlicker_->pos_z;
    mMdl[3][3] = 1.0f;
    sceVu0UnitMatrix(mScl);
    mScl[0][0] = pFlicker_->scale;
    mScl[1][1] = pFlicker_->scale;
    mScl[2][2] = pFlicker_->scale;
    dcomp_cop2_9397A3F6B7(mTrn, mMdl, mScl);
    dcomp_cop2_9397A3F6B7(mTrn, (void *)(lpDrawMng + 0x2b0), mTrn);
    for (i = 0; i < 9; i++) {
        sceVu0ApplyMatrix(aPos[i], mTrn, VTX[i].pos);
        sceVu0ScaleVector(aPos[i], aPos[i], 1.0f / aPos[i][3]);
        aPos[i][0] = (float)(s32)(256.0f + (aPos[i][0] - 2048.0f));
        aPos[i][1] = (float)(s32)(224.0f + (aPos[i][1] - 2048.0f));
        if (bound_rect[0] < aPos[i][0]) {
            bound_rect[0] = aPos[i][0];
        }
        if (bound_rect[1] < aPos[i][1]) {
            bound_rect[1] = aPos[i][1];
        }
        if (aPos[i][2] < bound_rect[2]) {
            bound_rect[2] = aPos[i][2];
        }
        if (aPos[i][3] < bound_rect[3]) {
            bound_rect[3] = aPos[i][3];
        }
    }
    for (i = 0; i < 9; i++) {
        aST[i][0] = (aPos[i][0] - bound_rect[0]) / (bound_rect[2] - bound_rect[0]);
        aST[i][1] = (aPos[i][1] - bound_rect[1]) / (bound_rect[3] - bound_rect[1]);
        aST[i][2] = 1.0f;
        aST[i][3] = 0.0f;
    }
    for (i = 8; i >= 0; i--) {
        aColor[i] = VTX[i].color;
    }
    for (i = 0; i < 9; i++) {
        x = pFlicker_->amplitude * sinf(6.2831855f * pFlicker_->cycle * (pFlicker_->time + 0.2f * VTX[i].uv[1]));
        {
            float vTmp[4] = {0.0f, 0.0f, 0.0f, 1.0f};
            vTmp[0] = x + VTX[i].pos[0];
            vTmp[1] = VTX[i].pos[1];
            vTmp[2] = VTX[i].pos[2];
            sceVu0ApplyMatrix(aPos[i], mTrn, vTmp);
        }
        sceVu0ScaleVector(aPos[i], aPos[i], 1.0f / aPos[i][3]);
        aPos[i][0] = (float)(s32)(256.0f + (aPos[i][0] - 2048.0f));
        aPos[i][1] = (float)(s32)(224.0f + (aPos[i][1] - 2048.0f));
    }
    sb = SfxDraw_GetRenderStateBlock();
    sceVu0CopyVector(rect, bound_rect);
    SfxDraw_SetPrimitiveType(5);
    SfxDraw_SetBlendType(0);
    SfxDraw_SetTexture_FrameBuff(8, 8, rect);
    SfxDraw_UseST(1);
    SfxDraw_DrawIndexedPrimitive2(aPos, aColor, aST, s_aCircleIndices, 10);
    SfxDraw_SetRenderStateBlock(sb);
    return 1;
}


/* Source-shaped 2D mesh candidate, reconstructed from the original DWARF and assembly. */












static signed int _DrawRectMesh_2D(void *a0) {
    struct SfxFlickerP *pFlicker_ = (struct SfxFlickerP *)a0;
    int i;
    int j;
    unsigned short count;
    int stripBase;
    float aVert[200][4] __attribute__((aligned(16)));
    unsigned short aIndex[380];
    float aST[200][4] __attribute__((aligned(16)));
    u_long128 sb;
    float rect[4] __attribute__((aligned(16)));

    count = 0;
    for (i = 0; i < 200; i++) {
        aVert[i][0] = (pFlicker_->pos_x + (float)((i % 10) * 10)) - 50.0f;
        aVert[i][1] = (pFlicker_->pos_y + (float)((i / 10) * 10)) - 100.0f;
        ((u32 *)aVert[i])[2] = 0;
        ((u32 *)aVert[i])[3] = 0;
        aST[i][0] = 0.1f * (float)(i % 10);
        aST[i][1] = 0.05f * (float)(i / 10);
        aST[i][2] = 1.0f;
        ((u32 *)aST[i])[3] = 0;
    }
    i = 0;
    stripBase = 0;
    {
        unsigned short *marker = aIndex;
        int row2Current;
        int row2Base;
        for (; i < 19; i++) {
            row2Current = stripBase + 10;
            j = 0;
            row2Base = row2Current;
            for (; j < 10; j += 5) {
                /* Keep the odd index dependent on the narrowed pair base. */
                unsigned short c;
                c = (u16)(count + 0);
                aIndex[c] = (j + 0) + stripBase;
                aIndex[(u16)(c + 1)] = row2Current;
                c = (u16)(count + 2);
                aIndex[c] = (j + 1) + stripBase;
                aIndex[(u16)(c + 1)] = (j + 1) + row2Base;
                c = (u16)(count + 4);
                aIndex[c] = (j + 2) + stripBase;
                aIndex[(u16)(c + 1)] = (j + 2) + row2Base;
                c = (u16)(count + 6);
                aIndex[c] = (j + 3) + stripBase;
                aIndex[(u16)(c + 1)] = (j + 3) + row2Base;
                c = (u16)(count + 8);
                aIndex[c] = (j + 4) + stripBase;
                aIndex[(u16)(c + 1)] = (j + 4) + row2Base;
                count += 10;
                row2Current += 5;
            }
            stripBase += 10;
            marker[0] = marker[0] + 0x8000;
            marker[1] = marker[1] + 0x8000;
            marker += 20;
        }
    }
    count = (u32)pFlicker_->time;
    for (i = 0; i < 200; i++) {
        aVert[i][0] = aVert[i][0] + pFlicker_->amplitude * sinf(0.01745f * (float)count);
        count += 10;
    }
    sb = SfxDraw_GetRenderStateBlock();
    rect[0] = pFlicker_->pos_x - 50.0f;
    rect[1] = pFlicker_->pos_y - 100.0f;
    rect[2] = 50.0f + pFlicker_->pos_x;
    rect[3] = 100.0f + pFlicker_->pos_y;
    SfxDraw_SetPrimitiveType(4);
    SfxDraw_UseTexture(1);
    SfxDraw_SetColor(0x80808040);
    SfxDraw_EnableZTest(0);
    SfxDraw_UseST(1);
    SfxDraw_SetTexture_FrameBuff(8, 8, rect);
    SfxDraw_DrawIndexedPrimitive(aVert, aST, aIndex, 0x17c);
    SfxDraw_SetRenderStateBlock(sb);
    return 1;
}
static signed int _DrawRectMesh_3D(void *a0) {
    struct SfxFlickerP *pFlicker_ = (struct SfxFlickerP *)a0;
    int i;
    int j;
    unsigned short count;
    int stripBase;
    float aVert[200][4] __attribute__((aligned(16)));
    unsigned short aIndex[380];
    float aST[200][4] __attribute__((aligned(16)));
    u_long128 sb;
    float rect[4] __attribute__((aligned(16)));

    count = 0;
    for (i = 0; i < 200; i++) {
        aVert[i][0] = (pFlicker_->pos_x + (float)((i % 10) * 10)) - 50.0f;
        aVert[i][1] = (pFlicker_->pos_y + (float)((i / 10) * 10)) - 100.0f;
        ((u32 *)aVert[i])[2] = 0;
        ((u32 *)aVert[i])[3] = 0;
        aST[i][0] = 0.1f * (float)(i % 10);
        aST[i][1] = 0.05f * (float)(i / 10);
        aST[i][2] = 1.0f;
        ((u32 *)aST[i])[3] = 0;
    }
    i = 0;
    stripBase = 0;
    {
        unsigned short *marker = aIndex;
        int row2Current;
        int row2Base;
        for (; i < 19; i++) {
            row2Current = stripBase + 10;
            j = 0;
            row2Base = row2Current;
            for (; j < 10; j += 5) {
                /* Keep the odd index dependent on the narrowed pair base. */
                unsigned short c;
                c = (u16)(count + 0);
                aIndex[c] = (j + 0) + stripBase;
                aIndex[(u16)(c + 1)] = row2Current;
                c = (u16)(count + 2);
                aIndex[c] = (j + 1) + stripBase;
                aIndex[(u16)(c + 1)] = (j + 1) + row2Base;
                c = (u16)(count + 4);
                aIndex[c] = (j + 2) + stripBase;
                aIndex[(u16)(c + 1)] = (j + 2) + row2Base;
                c = (u16)(count + 6);
                aIndex[c] = (j + 3) + stripBase;
                aIndex[(u16)(c + 1)] = (j + 3) + row2Base;
                c = (u16)(count + 8);
                aIndex[c] = (j + 4) + stripBase;
                aIndex[(u16)(c + 1)] = (j + 4) + row2Base;
                count += 10;
                row2Current += 5;
            }
            stripBase += 10;
            marker[0] = marker[0] + 0x8000;
            marker[1] = marker[1] + 0x8000;
            marker += 20;
        }
    }
    count = (u32)pFlicker_->time;
    for (i = 0; i < 200; i++) {
        aVert[i][0] = aVert[i][0] + pFlicker_->amplitude * sinf(0.01745f * (float)count);
        count += 10;
    }
    sb = SfxDraw_GetRenderStateBlock();
    rect[0] = pFlicker_->pos_x - 50.0f;
    rect[1] = pFlicker_->pos_y - 100.0f;
    rect[2] = 50.0f + pFlicker_->pos_x;
    rect[3] = 100.0f + pFlicker_->pos_y;
    SfxDraw_SetPrimitiveType(4);
    SfxDraw_UseTexture(1);
    SfxDraw_SetColor(0x80808040);
    SfxDraw_EnableZTest(0);
    SfxDraw_UseST(1);
    SfxDraw_SetTexture_FrameBuff(7, 7, rect);
    SfxDraw_DrawIndexedPrimitive(aVert, aST, aIndex, 0x17c);
    SfxDraw_SetRenderStateBlock(sb);
    return 1;
}

signed int SfxFlicker_SetPos(unsigned short a0 /* r4 */, float *a1 /* r5 */) {
    u8 *s0;
    u32 v0;
    float f0;
    u32 a0_2; // a0

    a0_2 = s_pObjList;
    s0 = (u8 *)a1;
    v0 = (u32)SList_GetElemPtr((void *)a0_2, a0);
    if (v0 == 0) {
        v0 = 0;
    } else {
        f0 = *(float *)s0;
        *(f32 *)v0 = f0;
        f0 = *(float *)(s0 + 4);
        *(f32 *)((v0 + 4)) = f0;
        f0 = *(float *)(s0 + 8);
        *(f32 *)((v0 + 8)) = f0;
        v0 = 1;
    }
    return v0;
}

u32 SfxFlicker_SetScale(unsigned short a0 /* r4 */, float f12 /* f12 */) {
    float f20;
    u8 *v0;

    f20 = (float)f12;
    v0 = (u8 *)SList_GetElemPtr((void *)s_pObjList, a0);
    if ((u32)v0 == 0) {
        v0 = (u8 *)0;
    } else {
        *(f32 *)(v0 + 0xc) = f20;
        v0 = (u8 *)(s32)1;
    }
    return (u32)v0;
}

u32 SfxFlicker_SetAmplitude(unsigned short a0 /* r4 */, float f12 /* f12 */) {
    float f20;
    u8 *v0;

    f20 = (float)f12;
    v0 = (u8 *)SList_GetElemPtr((void *)s_pObjList, a0);
    if ((u32)v0 == 0) {
        v0 = (u8 *)0;
    } else {
        *(f32 *)(v0 + 0x10) = f20;
        v0 = (u8 *)(s32)1;
    }
    return (u32)v0;
}

u32 SfxFlicker_SetCycle(unsigned short a0 /* r4 */, float f12 /* f12 */) {
    float f20;
    u8 *v0;

    f20 = (float)f12;
    v0 = (u8 *)SList_GetElemPtr((void *)s_pObjList, a0);
    if ((u32)v0 == 0) {
        v0 = (u8 *)0;
    } else {
        *(f32 *)(v0 + 0x14) = f20;
        v0 = (u8 *)(s32)1;
    }
    return (u32)v0;
}
