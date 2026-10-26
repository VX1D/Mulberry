#include "common.h"
extern void sceVu0CopyVector(void *, void *);
static unsigned int * _MakePacket_CopyFrameBuffer(unsigned int *);
extern u8 s_rndr_stt[];
extern u16 s_fb_width_pow;
extern u16 s_fb_height_pow;
extern u32 s_fb_LURD[];
extern u32 L1280[];
extern u32 lpMdlPacketMem;
extern u32 s_pTex;
static void _SetSprite(void *, float *, float *, float, float *);
static unsigned int * _MakePacket_SetBlend(unsigned int *, unsigned short);
static unsigned int * _MakePacket_DrawSprite(void *, unsigned int *, signed int *);
void SfxDraw_SetTexture_FrameBuff(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */, void *a2
        /* r6 */);
void SfxDraw_SetTexture_NoLoad(void *a0 /* r4 */);
void SfxDraw_DrawSprite_Scr(float *a0 /* r4 */, void *a1 /* r5 */, float f12 /* f12 */, void *a2 /*
        r6 */, void *a3 /* r7 */);
void SfxDraw_Initialize(void);
void SfxDraw_UseST(signed int a0 /* r4 */);
void SfxDraw_SetPrimitiveType(unsigned short a0 /* r4 */);
void SfxDraw_UseTexture(signed int a0 /* r4 */);
u_long128 SfxDraw_GetRenderStateBlock(void);
void SfxDraw_SetRenderStateBlock(u_long128 a0 /* r4 */);
void SfxDraw_EnableFog(signed int a0 /* r4 */);
void SfxDraw_EnableZTest(signed int a0 /* r4 */);
void SfxDraw_SetColor(s32 a0 /* r4 */);
void SfxDraw_SetTexWrapMode(unsigned short a0 /* r4 */);
void SfxDraw_SetBlendType(unsigned short a0 /* r4 */);

/* SfxDraw_SetBlendType @ 0x1C3B20 .. 0x1C3B48 (0x28 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */




void SfxDraw_SetBlendType(unsigned short a0 /* r4 */) {
    ((struct { unsigned char _pad:1; unsigned char f:2; } *)&*(u8 *)s_rndr_stt)->f = a0;
    return;
}


/* SfxDraw_SetTexWrapMode @ 0x1C3AF0 .. 0x1C3B18 (0x28 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */




void SfxDraw_SetTexWrapMode(unsigned short a0 /* r4 */) {
    ((struct { unsigned char _pad:4; unsigned char f:2; } *)&s_rndr_stt[1])->f = a0;
    return;
}


/* SfxDraw_SetColor @ 0x1C3AE0 .. 0x1C3AEC (0xc bytes) */


void SfxDraw_SetColor(s32 a0 /* r4 */) {
    *(u32 *)((u8 *)&s_rndr_stt + 4) = a0;
    return;
}














/* SfxDraw_EnableZTest @ 0x1C3AB0 .. 0x1C3AD4 (0x24 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */






void SfxDraw_EnableZTest(signed int a0 /* r4 */) {
    ((struct { unsigned char f:1; } *)&*(u8 *)s_rndr_stt)->f = a0;
    return;
}








/* SfxDraw_EnableFog @ 0x1C3A80 .. 0x1C3AA8 (0x28 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */






void SfxDraw_EnableFog(signed int a0 /* r4 */) {
    ((struct { unsigned char _pad:3; unsigned char f:1; } *)&s_rndr_stt[1])->f = a0;
    return;
}


/* SfxDraw_SetRenderStateBlock @ 0x1C3A70 .. 0x1C3A7C (0xc bytes) */





void SfxDraw_SetRenderStateBlock(u_long128 a0 /* r4 */) {
    *(u_long128 *)s_rndr_stt = a0;
    return;
}


/* SfxDraw_GetRenderStateBlock @ 0x1C3A60 .. 0x1C3A6C (0xc bytes) */
/*
 * dcomp notes:
 *   return: lq at 0x1c3a68 computes the return value
 */






u_long128 SfxDraw_GetRenderStateBlock(void) {
    return *(u_long128 *)s_rndr_stt;
}


/* SfxDraw_UseTexture @ 0x1C3A30 .. 0x1C3A58 (0x28 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */






void SfxDraw_UseTexture(signed int a0 /* r4 */) {
    ((struct { unsigned char _pad:5; unsigned char f:1; } *)&*(u8 *)s_rndr_stt)->f = a0;
    return;
}


/* SfxDraw_SetPrimitiveType @ 0x1C3A00 .. 0x1C3A28 (0x28 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */






void SfxDraw_SetPrimitiveType(unsigned short a0 /* r4 */) {
    ((struct { unsigned short _pad:6; unsigned short f:4; } *)&*(u16 *)s_rndr_stt)->f = a0;
    return;
}


/* SfxDraw_UseST @ 0x1C39D0 .. 0x1C39F8 (0x28 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */


void SfxDraw_UseST(signed int a0 /* r4 */) {
    ((struct { unsigned char _pad:2; unsigned char f:1; } *)&s_rndr_stt[1])->f = a0;
    return;
}


/* SfxDraw_Initialize @ 0x1C3890 .. 0x1C39D0 (0x140 bytes, frame 0x10) */






void SfxDraw_Initialize(void) {
    *(u_long128 *)s_rndr_stt = (u_long128)0;
    ((struct { unsigned char f:1; } *)&*(u8 *)s_rndr_stt)->f = 1;
    ((struct { unsigned char _pad:1; unsigned char f:2; } *)&*(u8 *)s_rndr_stt)->f = 1;
    ((struct { unsigned char _pad:3; unsigned char f:2; } *)&*(u8 *)s_rndr_stt)->f = 0;
    ((struct { unsigned char _pad:5; unsigned char f:1; } *)&*(u8 *)s_rndr_stt)->f = 1;
    *(u32 *)(s_rndr_stt + 4) = 0x80808080;
    ((struct { unsigned short _pad:6; unsigned short f:4; } *)&*(u16 *)s_rndr_stt)->f = 4;
    ((struct { unsigned char _pad:2; unsigned char f:1; } *)&s_rndr_stt[1])->f = 1;
    ((struct { unsigned char _pad:3; unsigned char f:1; } *)&s_rndr_stt[1])->f = 0;
    ((struct { unsigned char _pad:4; unsigned char f:2; } *)&s_rndr_stt[1])->f = 0;
    s_fb_width_pow = 7;
    s_fb_height_pow = 7;
    return;
}


/* SfxDraw_DrawSprite_Scr @ 0x1C37A0 .. 0x1C3884 (0xe4 bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42fe0000 at 0x1c37b8
 *   stack: address of the slot at 0x10 escapes at 0x1c3840
 */


void SfxDraw_DrawSprite_Scr(float *a0 /* r4 */, void *a1 /* r5 */, float f12 /* f12 */, void *a2 /*
        r6 */, void *a3 /* r7 */) {
    u32 v1;
    u32 v0;
    void *a1_2;
    u8 stackFrame_90[16] __attribute__((aligned(16)));
    u8 stackFrame_10[128] __attribute__((aligned(16)));

    v1 = (u32)a1;
    if ((u32)a2 != 0) {
        v0 = ((s32)(127.0f * *(float *)a2));
        *(u32 *)((u8 *)&stackFrame_90[0]) = v0;
        v0 = ((s32)(127.0f * *(float *)(((u8 *)a2 + 4))));
        ((u32 *)stackFrame_90)[1] = v0;
        v0 = ((s32)(127.0f * *(float *)(((u8 *)a2 + 8))));
        ((u32 *)stackFrame_90)[2] = v0;
        v0 = ((s32)(127.0f * *(float *)(((u8 *)a2 + 0xc))));
        ((u32 *)stackFrame_90)[3] = v0;
    } else {
        v0 = 0x7f;
        ((u32 *)stackFrame_90)[3] = v0;
        ((u32 *)stackFrame_90)[2] = v0;
        ((u32 *)stackFrame_90)[1] = v0;
        *(u32 *)((u8 *)&stackFrame_90[0]) = v0;
    }
    _SetSprite((void *)((u8 *)&stackFrame_10[0]), (float *)a0, (float *)v1, f12, (float *)a3);
    a0 = (float *)lpMdlPacketMem;
    v0 = (u32)_MakePacket_SetBlend((unsigned int *)a0, ((struct { unsigned char _pad:1; unsigned
        char f:2; } *)&*(u8 *)s_rndr_stt)->f);
    lpMdlPacketMem = (u32)v0;
    a1_2 = (void *)lpMdlPacketMem;
    v0 = (u32)_MakePacket_DrawSprite((void *)((u8 *)&stackFrame_10[0]), (unsigned int *)a1_2,
        (signed int *)((u8 *)&stackFrame_90[0]));
    lpMdlPacketMem = v0;
    return;
}




/* SfxDraw_DrawSprite_Wld @ 0x1C33C0 .. 0x1C3794 (0x3d4 bytes, frame 0x1b0) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @994 -> 0x2485d0
 *   fpu: mov.s at 0x1c33f0 is a float copy
 *   fpu: mov.s at 0x1c33f8 is a float copy
 *   fpu: float literal 0x00000000 at 0x1c3404
 *   stack: address of the slot at 0x60 escapes at 0x1c3420
 *   stack: address of the slot at 0xa0 escapes at 0x1c3434
 *   fpu: float literal 0x42c8199a at 0x1c344c
 *   fpu: float literal 0x41200000 at 0x1c3454
 *   fpu: float literal 0x3f800000 at 0x1c345c
 *   stack: address of the slot at 0x1a0 escapes at 0x1c3578
 *   stack: address of the slot at 0x140 escapes at 0x1c3578
 *   stack: address of the slot at 0x1a0 escapes at 0x1c3594
 *   fpu: float literal 0x3f800000 at 0x1c35ac
 *   stack: address of the slot at 0x1a0 escapes at 0x1c35c0
 *   stack: address of the slot at 0x1a0 escapes at 0x1c35c0
 *   fpu: float literal 0xc4e00000 at 0x1c35d8
 *   fpu: float literal 0xc4e40000 at 0x1c35dc
 *   stack: address of the slot at 0x180 escapes at 0x1c3634
 *   stack: address of the slot at 0x180 escapes at 0x1c3634
 *   fpu: float literal 0x3f800000 at 0x1c3644
 *   stack: address of the slot at 0x180 escapes at 0x1c365c
 *   stack: address of the slot at 0x180 escapes at 0x1c365c
 *   fpu: float literal 0x45000000 at 0x1c3674
 *   fpu: float literal 0x3f600000 at 0x1c367c
 *   fpu: mov.s at 0x1c3690 is a float copy
 *   fpu: float literal 0x42fe0000 at 0x1c36a8
 *   stack: address of the slot at 0x194 escapes at 0x1c3710
 *   fpu: mov.s at 0x1c372c is a float copy
 *   stack: address of the slot at 0xb0 escapes at 0x1c3738
 *   stack: address of the slot at 0x1a0 escapes at 0x1c3738
 *   stack: address of the slot at 0x190 escapes at 0x1c3738
 *   literal: @994 initializes the 16-byte local at 0x180
 */

extern signed int SfxCalc_CheckInsightCamera(float *);
extern void sceVu0CopyMatrix(void *, void *);
extern void sceVu0ApplyMatrix(float *, float (*)[4], float *);
extern void sceVu0ScaleVector(float *, float *, float);
extern u32 GetCameraPos();
extern float Math_GetDist(float *, float *);
extern u8 *lpDrawMng;
extern u32 L994[];
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif


struct sdwV4 { float v[4]; };
void SfxDraw_DrawSprite_Wld(float *pos_, float *scale_, float rot_, float *pRGBA_, float *aTexPos_, float z_offset_) {
    float pos_scr[4];
    float scl_scr[4];
    struct sdwV4 vScl;
    float mWS[4][4];
    int col[4];
    float aSprite[32];
    float v[4];
    float m[4][4];

    if (SfxCalc_CheckInsightCamera(pos_)) {
        if (0.0f != z_offset_) {
            sceVu0CopyMatrix(m, lpDrawMng + 0x330);
            sceVu0ApplyMatrix(v, (float (*)[4])(lpDrawMng + 0x2f0), pos_);
            m[2][2] *= 1.0f + (10.0f * z_offset_) / ((100.05f * v[2]) * (v[2] + z_offset_));
            dcomp_cop2_9397A3F6B7(mWS, m, lpDrawMng + 0x2f0);
            dcomp_cop2_9397A3F6B7(mWS, lpDrawMng + 0x3b0, mWS);
            sceVu0ApplyMatrix(pos_scr, mWS, pos_);
        } else {
            sceVu0ApplyMatrix(pos_scr, (float (*)[4])(lpDrawMng + 0x2b0), pos_);
        }
        sceVu0ScaleVector(pos_scr, pos_scr, 1.0f / pos_scr[3]);
        pos_scr[0] = pos_scr[0] + -1792.0f;
        pos_scr[1] = pos_scr[1] + -1824.0f;
        vScl = (struct sdwV4){{0.0f, 0.0f, 0.0f, 1.0f}};
        vScl.v[0] = scale_[0];
        *(float *)((u8 *)&vScl + 4) = scale_[1];
        vScl.v[2] = Math_GetDist(pos_, (float *)GetCameraPos());
        sceVu0ApplyMatrix(vScl.v, (float (*)[4])(lpDrawMng + 0x270), vScl.v);
        sceVu0ScaleVector(vScl.v, vScl.v, 1.0f / vScl.v[3]);
        scl_scr[0] = vScl.v[0] - 2048.0f;
        scl_scr[1] = vScl.v[1] - 2048.0f;
        scl_scr[1] = scl_scr[1] * 0.875f;
        if (pRGBA_ != 0) {
            col[0] = (int)(127.0f * pRGBA_[0]);
            col[1] = (int)(127.0f * pRGBA_[1]);
            col[2] = (int)(127.0f * pRGBA_[2]);
            col[3] = (int)(127.0f * pRGBA_[3]);
        } else {
            col[3] = 0x7f;
            col[2] = 0x7f;
            col[1] = 0x7f;
            col[0] = 0x7f;
        }
        _SetSprite(aSprite, pos_scr, scl_scr, rot_, aTexPos_);
        lpMdlPacketMem = (u32)_MakePacket_SetBlend((unsigned int *)lpMdlPacketMem,
            ((struct { unsigned char _pad:1; unsigned char f:2; } *)s_rndr_stt)->f);
        lpMdlPacketMem = (u32)_MakePacket_DrawSprite(aSprite, (unsigned int *)lpMdlPacketMem, col);
    }
}




extern signed int SfxCalc_CheckInsightCamera(float *);
extern void sceVu0RotMatrixZ(void *, void *, float);
extern void SfxCalc_Ang2Vec(float *, float, float);
extern void sceVu0ScaleVector(float *, float *, float);
extern void SfxCalc_MakeMatrixFromDir(void *, float *);
extern void sceVu0CopyMatrix(void *, void *);
extern void sceVu0ApplyMatrix(float *, float (*)[4], float *);
extern void sceVu0FTOI4Vector(int *, float *);
static unsigned int * _MakePacket_DrawSprite2(void *, unsigned int *, void *, signed int *);
extern float MRX1[4][4];
extern u8 *lpDrawMng;

struct sdw2_Tex0 {
    unsigned long TBP0 : 14;
    unsigned long TBW : 6;
    unsigned long PSM : 6;
    unsigned long TW : 4;
    unsigned long TH : 4;
    unsigned long sdw2_rest : 30;
};
struct sdw2_TexHead {
    unsigned char sdw2_r0[0x10];
    struct sdw2_Tex0 tex0;
};
struct sdw2_Tex {
    unsigned int sdw2_r1;
    struct sdw2_TexHead *pTm2Head;
};

static inline void SDW2_MULMAT(void *d, void *a, void *b) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}

#define SDW2_WRAP(a) (((a) + PI) >= 0.0f ? ((a) - TWO_PI * (int)(((a) + PI) / TWO_PI)) : (TWO_PI + ((a) - TWO_PI * (int)(((a) + PI) / TWO_PI))))

void SfxDraw_DrawSprite_Wld2(float *pos_, float *scale_, float rot_, float *tex_rect_, float z_offset_) {
    if (SfxCalc_CheckInsightCamera(pos_)) {
        int col_int[4];
        float aTexPos[4][4];
        float aPos[4][4] = {
            {0.5f * -scale_[0], 0.5f * -scale_[1], 0.0f, 1.0f},
            {0.5f * scale_[0], 0.5f * -scale_[1], 0.0f, 1.0f},
            {0.5f * -scale_[0], 0.5f * scale_[1], 0.0f, 1.0f},
            {0.5f * scale_[0], 0.5f * scale_[1], 0.0f, 1.0f},
        };
        int aPosInt[4][4];
        float mRot[4][4];
        float mTrn[4][4];
        float mWS[4][4];
        float mrx[4][4];
        float mRoll[4][4];
        float vDir[4];

        sceVu0RotMatrixZ(mRoll, MRX1, SDW2_WRAP(rot_));
        SfxCalc_Ang2Vec(vDir, *(float *)(lpDrawMng + 0x240), *(float *)(lpDrawMng + 0x244));
        sceVu0ScaleVector(vDir, vDir, -1.0f);
        SfxCalc_MakeMatrixFromDir(mRot, vDir);
        SDW2_MULMAT(mRot, mRot, mRoll);
        sceVu0CopyMatrix(mTrn, MRX1);
        sceVu0CopyVector(mTrn[3], pos_);
        SDW2_MULMAT(mrx, mTrn, mRot);
        if (0.0f == z_offset_) {
            SDW2_MULMAT(mrx, lpDrawMng + 0x2b0, mrx);
        } else {
            {
                float v[4];
                float m[4][4];
                sceVu0CopyMatrix(m, lpDrawMng + 0x330);
                sceVu0ApplyMatrix(v, (float (*)[4])(lpDrawMng + 0x2f0), pos_);
                m[2][2] *= 1.0f + (10.0f * z_offset_) / ((100.05f * v[2]) * (v[2] + z_offset_));
                SDW2_MULMAT(mWS, m, lpDrawMng + 0x2f0);
                SDW2_MULMAT(mWS, lpDrawMng + 0x3b0, mWS);
            }
            SDW2_MULMAT(mrx, mWS, mrx);
        }
        sceVu0ApplyMatrix(aPos[0], mrx, aPos[0]);
        sceVu0ApplyMatrix(aPos[1], mrx, aPos[1]);
        sceVu0ApplyMatrix(aPos[2], mrx, aPos[2]);
        sceVu0ApplyMatrix(aPos[3], mrx, aPos[3]);
        sceVu0ScaleVector(aPos[0], aPos[0], 1.0f / aPos[0][3]);
        sceVu0ScaleVector(aPos[1], aPos[1], 1.0f / aPos[1][3]);
        sceVu0ScaleVector(aPos[2], aPos[2], 1.0f / aPos[2][3]);
        sceVu0ScaleVector(aPos[3], aPos[3], 1.0f / aPos[3][3]);
        sceVu0FTOI4Vector(aPosInt[0], aPos[0]);
        sceVu0FTOI4Vector(aPosInt[1], aPos[1]);
        sceVu0FTOI4Vector(aPosInt[2], aPos[2]);
        sceVu0FTOI4Vector(aPosInt[3], aPos[3]);

        if (((struct { unsigned char _pad:3; unsigned char f:1; } *)&s_rndr_stt[1])->f) {
            float fog = 0.0243069008f * ((float)((int)aPos[0][2] << 4) - 587487.375f);
            int ifog;
            if (fog < 0.0f) {
                fog = 0.0f;
            } else if (4080.0f < fog) {
                fog = 4080.0f;
            } else {
                fog = fog;
            }
            ifog = (int)fog;
            aPosInt[0][3] = ifog;
            aPosInt[1][3] = ifog;
            aPosInt[2][3] = ifog;
            aPosInt[3][3] = ifog;
        } else {
            aPosInt[0][3] = 0;
            aPosInt[1][3] = 0;
            aPosInt[2][3] = 0;
            aPosInt[3][3] = 0;
        }
        {
        int col = *(int *)(s_rndr_stt + 4);
        col_int[0] = (col >> 24) & 0xff;
        col_int[1] = (col >> 16) & 0xff;
        col_int[2] = (col >> 8) & 0xff;
        col_int[3] = col & 0xff;
        }

        if (s_pTex) {
            if (((struct { unsigned char _pad:2; unsigned char f:1; } *)&s_rndr_stt[1])->f) {
                if (tex_rect_) {
                    aTexPos[0][0] = tex_rect_[0];
                    aTexPos[0][1] = tex_rect_[1];
                    aTexPos[1][0] = tex_rect_[2];
                    aTexPos[1][1] = tex_rect_[1];
                    aTexPos[2][0] = tex_rect_[0];
                    aTexPos[2][1] = tex_rect_[3];
                    aTexPos[3][0] = tex_rect_[2];
                    aTexPos[3][1] = tex_rect_[3];
                } else {
                    aTexPos[0][0] = 0.0f;
                    aTexPos[0][1] = 0.0f;
                    aTexPos[1][0] = 1.0f;
                    aTexPos[1][1] = 0.0f;
                    aTexPos[2][0] = 0.0f;
                    aTexPos[2][1] = 1.0f;
                    aTexPos[3][0] = 1.0f;
                    aTexPos[3][1] = 1.0f;
                }
                aTexPos[0][2] = aTexPos[1][2] = aTexPos[2][2] = aTexPos[3][2] = 1.0f;
            } else if (tex_rect_) {
                int left = (int)tex_rect_[0] << 4;
                int right = (int)tex_rect_[2] << 4;
                int top = (int)tex_rect_[1] << 4;
                int botttom = (int)tex_rect_[3] << 4;
                aTexPos[0][0] = left;
                aTexPos[0][1] = top;
                aTexPos[1][0] = right;
                aTexPos[1][1] = top;
                aTexPos[2][0] = left;
                aTexPos[2][1] = botttom;
                aTexPos[3][0] = right;
                aTexPos[3][1] = botttom;
            } else {
                int right = (unsigned short)(1 << ((struct sdw2_Tex *)s_pTex)->pTm2Head->tex0.TW) << 4;
                int botttom = (unsigned short)(1 << ((struct sdw2_Tex *)s_pTex)->pTm2Head->tex0.TH) << 4;
                aTexPos[0][0] = 0.0f;
                aTexPos[0][1] = 0.0f;
                aTexPos[1][0] = right;
                aTexPos[1][1] = 0.0f;
                aTexPos[2][0] = 0.0f;
                aTexPos[2][1] = botttom;
                aTexPos[3][0] = right;
                aTexPos[3][1] = botttom;
            }
        }
        lpMdlPacketMem = (u32)_MakePacket_SetBlend((unsigned int *)lpMdlPacketMem,
            ((struct { unsigned char _pad:1; unsigned char f:2; } *)s_rndr_stt)->f);
        lpMdlPacketMem = (u32)_MakePacket_DrawSprite2(aPosInt, (unsigned int *)lpMdlPacketMem, aTexPos, col_int);
    }
}













/* SfxDraw_DrawSprite_Wld2Pt @ 0x1C2290 */
extern void * memset(void *, int, unsigned int);
extern void sceVu0SubVector(void *, void *, void *);
extern void sceVu0Normalize(void *, void *);
extern void sceVu0AddVector(void *, void *, void *);




struct dw_2036591 { int ver[4][4]; int uv[4][4]; };

void SfxDraw_DrawSprite_Wld2Pt(float *pos0_, float *pos1_, float scale_, float *pRGBA_, float z_offset_) {
    float src_pos[2][4] __attribute__((aligned(16)));
    float pos_scr[2][4] __attribute__((aligned(16)));
    struct sdwV4 vScl;
    int col_int[4] __attribute__((aligned(16)));
    struct dw_2036591 sprite __attribute__((aligned(16)));
    float dir[4] __attribute__((aligned(16)));
    float pos[4][4] __attribute__((aligned(16)));
    float mRotZplus[4][4] __attribute__((aligned(16)));
    float mRotZminus[4][4] __attribute__((aligned(16)));
    unsigned short i;

    sceVu0CopyVector(src_pos[0], pos0_);
    sceVu0CopyVector(src_pos[1], pos1_);
    for (i = 0; i < 2; i++) {
        float mWS[4][4] __attribute__((aligned(16)));
        float v[4] __attribute__((aligned(16)));
        float m[4][4] __attribute__((aligned(16)));

        if (!SfxCalc_CheckInsightCamera(src_pos[i])) {
            return;
        }
        if (0.0f != z_offset_) {
            sceVu0CopyMatrix(m, lpDrawMng + 0x330);
            sceVu0ApplyMatrix(v, (float (*)[4])(lpDrawMng + 0x2f0), src_pos[i]);
            m[2][2] *= 1.0f + (10.0f * z_offset_) / ((100.05f * v[2]) * (v[2] + z_offset_));
            dcomp_cop2_9397A3F6B7(mWS, m, lpDrawMng + 0x2f0);
            dcomp_cop2_9397A3F6B7(mWS, lpDrawMng + 0x3b0, mWS);
            sceVu0ApplyMatrix(pos_scr[i], mWS, src_pos[i]);
        } else {
            sceVu0ApplyMatrix(pos_scr[i], (float (*)[4])(lpDrawMng + 0x2b0), src_pos[i]);
        }
        sceVu0ScaleVector(pos_scr[i], pos_scr[i], 1.0f / pos_scr[i][3]);
        pos_scr[i][0] = pos_scr[i][0] + -1792.0f;
        pos_scr[i][1] = pos_scr[i][1] + -1824.0f;
    }
    vScl = (struct sdwV4){{0.0f, 0.0f, 0.0f, 1.0f}};
    vScl.v[0] = scale_;
    *(float *)((u8 *)&vScl + 4) = scale_;
    vScl.v[2] = Math_GetDist(src_pos[0], (float *)GetCameraPos());
    sceVu0ApplyMatrix(vScl.v, (float (*)[4])(lpDrawMng + 0x270), vScl.v);
    sceVu0ScaleVector(vScl.v, vScl.v, 1.0f / vScl.v[3]);
    {
        float sx = vScl.v[0] - 2048.0f;
        float sy = vScl.v[1] - 2048.0f;
        sy = sy * 0.875f;
        if (pRGBA_ != 0) {
            col_int[0] = (int)(127.0f * pRGBA_[0]);
            col_int[1] = (int)(127.0f * pRGBA_[1]);
            col_int[2] = (int)(127.0f * pRGBA_[2]);
            col_int[3] = (int)(127.0f * pRGBA_[3]);
        } else {
            col_int[3] = 0x7f;
            col_int[2] = 0x7f;
            col_int[1] = 0x7f;
            col_int[0] = 0x7f;
        }
        memset(&sprite, 0, 0x80);
        sceVu0RotMatrixZ(mRotZplus, MRX1, 0.78539f);
        sceVu0RotMatrixZ(mRotZminus, MRX1, -0.78539f);
        sceVu0SubVector(dir, pos_scr[1], pos_scr[0]);
        dir[3] = 0;
        dir[2] = 0;
        sceVu0Normalize(dir, dir);
        sceVu0ApplyMatrix(pos[0], mRotZplus, dir);
        pos[0][0] = -pos[0][0] * sx;
        pos[0][1] = -pos[0][1] * sy;
        sceVu0ApplyMatrix(pos[1], mRotZminus, dir);
        pos[1][0] = -pos[1][0] * sx;
        pos[1][1] = -pos[1][1] * sy;
        sceVu0ApplyMatrix(pos[2], mRotZminus, dir);
        pos[2][0] = pos[2][0] * sx;
        pos[2][1] = pos[2][1] * sy;
        sceVu0ApplyMatrix(pos[3], mRotZplus, dir);
        pos[3][0] = pos[3][0] * sx;
        pos[3][1] = pos[3][1] * sy;
    }
    sceVu0AddVector(pos[0], pos[0], pos_scr[0]);
    pos[0][2] = pos_scr[0][2];
    pos[0][3] = 1.0f;
    sceVu0AddVector(pos[1], pos[1], pos_scr[0]);
    pos[1][2] = pos_scr[0][2];
    pos[1][3] = 1.0f;
    sceVu0AddVector(pos[2], pos[2], pos_scr[1]);
    pos[2][2] = pos_scr[1][2];
    pos[2][3] = 1.0f;
    sceVu0AddVector(pos[3], pos[3], pos_scr[1]);
    pos[3][2] = pos_scr[1][2];
    pos[3][3] = 1.0f;
    sprite.ver[0][0] = ((int)(pos[0][0] - 256.0f) + 0x800) << 4;
    sprite.ver[0][1] = ((int)(pos[0][1] - 224.0f) + 0x800) << 4;
    sprite.ver[0][2] = (int)pos[0][2] << 4;
    sprite.ver[0][3] = 0xff;
    sprite.ver[1][0] = ((int)(pos[1][0] - 256.0f) + 0x800) << 4;
    sprite.ver[1][1] = ((int)(pos[1][1] - 224.0f) + 0x800) << 4;
    sprite.ver[1][2] = (int)pos[1][2] << 4;
    sprite.ver[1][3] = 0xff;
    sprite.ver[2][0] = ((int)(pos[2][0] - 256.0f) + 0x800) << 4;
    sprite.ver[2][1] = ((int)(pos[2][1] - 224.0f) + 0x800) << 4;
    sprite.ver[2][2] = (int)pos[2][2] << 4;
    sprite.ver[2][3] = 0xff;
    sprite.ver[3][0] = ((int)(pos[3][0] - 256.0f) + 0x800) << 4;
    sprite.ver[3][1] = ((int)(pos[3][1] - 224.0f) + 0x800) << 4;
    sprite.ver[3][2] = (int)pos[3][2] << 4;
    sprite.ver[3][3] = 0xff;
    if (s_pTex) {
        sprite.uv[0][0] = 0;
        *(float *)&sprite.uv[0][2] = 1.0f;
        sprite.uv[0][1] = 0;
        *(float *)&sprite.uv[1][0] = 1.0f;
        sprite.uv[0][3] = 0;
        *(float *)&sprite.uv[1][2] = 1.0f;
        sprite.uv[1][1] = 0;
        *(float *)&sprite.uv[2][1] = 1.0f;
        sprite.uv[1][3] = 0;
        *(float *)&sprite.uv[2][2] = 1.0f;
        sprite.uv[2][0] = 0;
        *(float *)&sprite.uv[3][0] = 1.0f;
        sprite.uv[2][3] = 0;
        *(float *)&sprite.uv[3][1] = 1.0f;
        *(float *)&sprite.uv[3][2] = 1.0f;
        sprite.uv[3][3] = 0;
    }
    lpMdlPacketMem = (u32)_MakePacket_SetBlend((unsigned int *)lpMdlPacketMem,
        ((struct { unsigned char _pad:1; unsigned char f:2; } *)s_rndr_stt)->f);
    {
        u_long128 saved = *(u_long128 *)s_rndr_stt;
        ((struct { unsigned char _pad:2; unsigned char f:1; } *)&s_rndr_stt[1])->f = 1;
        lpMdlPacketMem = (u32)_MakePacket_DrawSprite(&sprite, (unsigned int *)lpMdlPacketMem, col_int);
        *(u_long128 *)s_rndr_stt = saved;
    }
}



/* _SetSprite @ 0x1C1C60 .. 0x1C2284 (0x624 bytes, frame 0x130) */



#define pSpr_ ((struct dw_2036591 *)pSpr_v)
static void _SetSprite(void *pSpr_v, float *pos_2d_, float *scale_, float rot_, float *tex_pos_) {
    float aPos[4][4] __attribute__((aligned(16)));
    float mrx[4][4] __attribute__((aligned(16)));
    float fog;

    memset(pSpr_v, 0, 0x80);
    aPos[0][0] = -0.5f * scale_[0];
    aPos[0][1] = -0.5f * scale_[1];
    aPos[0][2] = 0.0f;
    aPos[0][3] = 1.0f;
    aPos[1][0] = 0.5f * scale_[0];
    aPos[1][1] = -0.5f * scale_[1];
    aPos[1][2] = 0.0f;
    aPos[1][3] = 1.0f;
    aPos[2][0] = -0.5f * scale_[0];
    aPos[2][1] = 0.5f * scale_[1];
    aPos[2][2] = 0.0f;
    aPos[2][3] = 1.0f;
    aPos[3][0] = 0.5f * scale_[0];
    aPos[3][1] = 0.5f * scale_[1];
    aPos[3][2] = 0.0f;
    aPos[3][3] = 1.0f;
    sceVu0RotMatrixZ(mrx, MRX1, SDW2_WRAP(rot_));
    sceVu0ApplyMatrix(aPos[0], mrx, aPos[0]);
    sceVu0ApplyMatrix(aPos[1], mrx, aPos[1]);
    sceVu0ApplyMatrix(aPos[2], mrx, aPos[2]);
    sceVu0ApplyMatrix(aPos[3], mrx, aPos[3]);
    fog = pos_2d_[0] - 256.0f;
    aPos[0][0] += fog;
    aPos[0][1] += pos_2d_[1] - 224.0f;
    fog = pos_2d_[0] - 256.0f;
    aPos[1][0] += fog;
    aPos[1][1] += pos_2d_[1] - 224.0f;
    fog = pos_2d_[0] - 256.0f;
    aPos[2][0] += fog;
    aPos[2][1] += pos_2d_[1] - 224.0f;
    fog = pos_2d_[0] - 256.0f;
    aPos[3][0] += (float)fog;
    aPos[3][1] += pos_2d_[1] - 224.0f;
    pSpr_->ver[0][0] = ((int)aPos[0][0] + 0x800) << 4;
    pSpr_->ver[0][1] = ((int)aPos[0][1] + 0x800) << 4;
    pSpr_->ver[1][0] = ((int)aPos[1][0] + 0x800) << 4;
    pSpr_->ver[1][1] = ((int)aPos[1][1] + 0x800) << 4;
    pSpr_->ver[2][0] = ((int)aPos[2][0] + 0x800) << 4;
    pSpr_->ver[2][1] = ((int)aPos[2][1] + 0x800) << 4;
    pSpr_->ver[3][0] = ((int)aPos[3][0] + 0x800) << 4;
    pSpr_->ver[3][1] = ((int)aPos[3][1] + 0x800) << 4;
    pSpr_->ver[0][2] = (int)pos_2d_[2] << 4;
    pSpr_->ver[1][2] = (int)pos_2d_[2] << 4;
    pSpr_->ver[2][2] = (int)pos_2d_[2] << 4;
    pSpr_->ver[3][2] = (int)pos_2d_[2] << 4;
    if (((struct { unsigned char _pad:3; unsigned char f:1; } *)&s_rndr_stt[1])->f) {
        int ifog;
        fog = 0.0243069008f * ((float)((int)pos_2d_[2] << 4) - 587487.375f);
        if (fog < 0.0f) {
            fog = 0.0f;
        } else if (4080.0f < fog) {
            fog = 4080.0f;
        } else {
            fog = fog;
        }
        ifog = (int)fog;
        pSpr_->ver[0][3] = ifog;
        pSpr_->ver[1][3] = ifog;
        pSpr_->ver[2][3] = ifog;
        pSpr_->ver[3][3] = ifog;
    }
    if (s_pTex) {
        if (((struct { unsigned char _pad:2; unsigned char f:1; } *)&s_rndr_stt[1])->f) {
            if (tex_pos_) {
                *(float *)&pSpr_->uv[0][0] = tex_pos_[0];
                *(float *)&pSpr_->uv[0][1] = tex_pos_[1];
                *(float *)&pSpr_->uv[1][0] = tex_pos_[2];
                *(float *)&pSpr_->uv[1][1] = tex_pos_[1];
                *(float *)&pSpr_->uv[2][0] = tex_pos_[0];
                *(float *)&pSpr_->uv[2][1] = tex_pos_[3];
                *(float *)&pSpr_->uv[3][0] = tex_pos_[2];
                *(float *)&pSpr_->uv[3][1] = tex_pos_[3];
            } else {
                *(float *)&pSpr_->uv[0][0] = 0.0f;
                *(float *)&pSpr_->uv[0][1] = 0.0f;
                *(float *)&pSpr_->uv[1][0] = 1.0f;
                *(float *)&pSpr_->uv[1][1] = 0.0f;
                *(float *)&pSpr_->uv[2][0] = 0.0f;
                *(float *)&pSpr_->uv[2][1] = 1.0f;
                *(float *)&pSpr_->uv[3][0] = 1.0f;
                *(float *)&pSpr_->uv[3][1] = 1.0f;
            }
            *(float *)&pSpr_->uv[0][2] = *(float *)&pSpr_->uv[1][2] = *(float *)&pSpr_->uv[2][2] = *(float *)&pSpr_->uv[3][2] = 1.0f;
        } else if (tex_pos_) {
            int left = (int)tex_pos_[0] << 4;
            int right = (int)tex_pos_[2] << 4;
            int top = (int)tex_pos_[1] << 4;
            int botttom = (int)tex_pos_[3] << 4;
            pSpr_->uv[0][0] = left;
            pSpr_->uv[0][1] = top;
            pSpr_->uv[1][0] = right;
            pSpr_->uv[1][1] = top;
            pSpr_->uv[2][0] = left;
            pSpr_->uv[2][1] = botttom;
            pSpr_->uv[3][0] = right;
            pSpr_->uv[3][1] = botttom;
        } else {
            int right = (unsigned short)(1 << ((struct sdw2_Tex *)s_pTex)->pTm2Head->tex0.TW) << 4;
            int botttom = (unsigned short)(1 << ((struct sdw2_Tex *)s_pTex)->pTm2Head->tex0.TH) << 4;
            pSpr_->uv[0][0] = 0;
            pSpr_->uv[0][1] = 0;
            pSpr_->uv[1][0] = right;
            pSpr_->uv[1][1] = 0;
            pSpr_->uv[2][0] = 0;
            pSpr_->uv[2][1] = botttom;
            pSpr_->uv[3][0] = right;
            pSpr_->uv[3][1] = botttom;
        }
    }
}








extern char *strcpy(char *, const char *);
extern void SfxDbg_SetDebugMsg(unsigned char, char *, char *, unsigned int);
static unsigned int *_MakePacket_SetBlend(unsigned int *lpCurDMA_, unsigned short type_)
{
    u8 szFile[256] __attribute__((aligned(16)));
    lpCurDMA_[0] = 0x10000002;
    lpCurDMA_[1] = 0;
    lpCurDMA_[2] = 0;
    lpCurDMA_[3] = 0x51000002;
    lpCurDMA_[4] = 0x8001;
    lpCurDMA_[5] = 0x10000000;
    lpCurDMA_[6] = 14;
    lpCurDMA_[7] = 0;
    lpCurDMA_ += 8;
    switch (type_) {
    case 0: *(s64 *)lpCurDMA_ = 0x44; lpCurDMA_ += 2; break;
    case 1: *(s64 *)lpCurDMA_ = 0x48; lpCurDMA_ += 2; break;
    case 2: *(s64 *)lpCurDMA_ = 0x42; lpCurDMA_ += 2; break;
    case 3: *(s64 *)lpCurDMA_ = 0x2a; lpCurDMA_ += 2; break;
    default:
        strcpy((char *)szFile, "SfxDraw.c");
        SfxDbg_SetDebugMsg(0, "Undefined Blending", (char *)szFile, 0x41b);
    }
    *(s64 *)lpCurDMA_ = 0x42;
    return lpCurDMA_ + 2;
}



/* _MakePacket_CopyFrameBuffer @ 0x1C1700 .. 0x1C1B48 (0x448 bytes, frame 0x20) */
static unsigned int * _MakePacket_CopyFrameBuffer(unsigned int *lpCurDMA) {
    unsigned int tex_width;
    unsigned int tex_height;
    u8 *fb;
    u8 *p;

    if (*(int *)(lpDrawMng + 0x408) == 0) {
        fb = lpDrawMng + 0x60;
    } else {
        fb = lpDrawMng + 0x150;
    }
    tex_width = 1 << s_fb_width_pow;
    tex_height = 1 << s_fb_height_pow;
    p = (u8 *)lpCurDMA;
    lpCurDMA[0] = 0x10000015;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x51000015;
    lpCurDMA[4] = 0x800b;
    lpCurDMA[5] = 0x10ab4000;
    lpCurDMA[6] = 0xe;
    lpCurDMA[7] = 0;
    *(u64 *)(p + 0x20) = 0;
    *(s64 *)(p + 0x28) = 0x3f;
    *(u64 *)(p + 0x30) = ((u64)(u16)(tex_width >> 6) << 16) | (0x1000150 | ((u64)0xff000000 << 32));
    *(s64 *)(p + 0x38) = 0x4c;
    *(u64 *)(p + 0x40) = (u64)(u32)((0x800 - (tex_width >> 1)) << 4) | ((u64)(u32)((0x800 - (tex_height >> 1)) << 4) << 32);
    *(s64 *)(p + 0x48) = 0x18;
    *(u64 *)(p + 0x50) = ((u64)(u32)(tex_width - 1) << 16) | ((u64)(u32)(tex_height - 1) << 48);
    *(s64 *)(p + 0x58) = 0x40;
    *(u64 *)(p + 0x60) = (u64)1 << 32;
    *(s64 *)(p + 0x68) = 0x4e;
    *(s64 *)(p + 0x70) = 0x60;
    *(s64 *)(p + 0x78) = 0x14;
    *(u64 *)(p + 0x80) = (u64)((u64)(u32)((u32)(*(u8 *)(fb + 3)) & 0x3f) << 0x14 | (u64)((u64)((u64)(u32)((u32)(*(u8 *)(fb + 2)) & 0x3f) << 0xe) | (u64)((s32)((s32)((u32)(*(u16 *)fb & 0x1ff) << 5))))) | (u64)((u64)((s32)((s32)0x64000000)) | (u64)((u64)(s32)2 << 0x20));
    *(s64 *)(p + 0x88) = 6;
    *(u64 *)(p + 0x90) = 0;
    *(s64 *)(p + 0x98) = 0x47;
    *(s64 *)(p + 0xa0) = 0x44;
    *(s64 *)(p + 0xa8) = 0x42;
    *(u64 *)(p + 0xb0) = 0x80 | ((u64)0x80 << 32);
    *(s64 *)(p + 0xb8) = 0x3b;
    *(u64 *)(p + 0xc0) = ((u64)0x3f800000 << 32) | 0x80808080;
    *(s64 *)(p + 0xc8) = 1;
    lpCurDMA[0x34] = 0x8002;
    lpCurDMA[0x35] = 0x24000000;
    lpCurDMA[0x36] = 0x43;
    lpCurDMA[0x37] = 0;
    *(u64 *)(p + 0xe0) = (u64)(s32)((u16)(u32)*(float *)&s_fb_LURD[0] << 4) | ((u64)(s32)((u16)(u32)*(float *)&s_fb_LURD[1] << 4) << 16);
    *(u64 *)(p + 0xe8) = (u64)(u32)((0x7ff - (tex_width >> 1)) << 4) | ((u64)(u32)((0x7ff - (tex_height >> 1)) << 4) << 16) | ((u64)(s32)-1 << 32);
    *(u64 *)(p + 0xf0) = (u64)(s32)((u16)(u32)((float *)s_fb_LURD)[2] << 4) | ((u64)(s32)((u16)(u32)((float *)s_fb_LURD)[3] << 4) << 16);
    *(u64 *)(p + 0xf8) = (u64)(u32)((((tex_width >> 1) + 0x800)) << 4) | ((u64)(u32)(((tex_height >> 1) + 0x800) << 4) << 16) | ((u64)(s32)-1 << 32);
    lpCurDMA[0x40] = 0x8005;
    lpCurDMA[0x41] = 0x10000000;
    lpCurDMA[0x42] = 0xe;
    lpCurDMA[0x43] = 0;
    *(u64 *)(p + 0x110) = 0;
    *(s64 *)(p + 0x118) = 0x3f;
    *(u64 *)(p + 0x120) = *(u64 *)fb;
    *(s64 *)(p + 0x128) = 0x4c;
    *(u64 *)(p + 0x130) = *(u64 *)(fb + 0x20);
    *(s64 *)(p + 0x138) = 0x18;
    *(u64 *)(p + 0x140) = *(u64 *)(fb + 0x30);
    *(s64 *)(p + 0x148) = 0x40;
    *(u64 *)(p + 0x150) = *(u64 *)(fb + 0x10);
    *(s64 *)(p + 0x158) = 0x4e;
    return (unsigned int *)(p + 0x160);
}



typedef struct { u8 pad[0x10]; u64 tex0; u64 tex1; } MP2_TEXHEAD;
typedef struct { u16 w; u16 flag; MP2_TEXHEAD *pHead; } MP2_TEX;
typedef struct { u8 alphaTest:1, blend:2, fbmsk:2, f5:1, pad:2; } MP2_RS0;
typedef struct { u8 pad:2, zEnable:1, zWrite:1, rest:4; } MP2_RS1;

#define MP2_BLEND(p, off, line) \
    { \
        s64 reg; \
        u8 szFile[256] __attribute__((aligned(16))); \
        switch (((MP2_RS0 *)&s_rndr_stt[0])->blend) { \
        case 0: reg = 0x44; break; \
        case 1: reg = 0x48; break; \
        case 2: reg = 0x42; break; \
        case 3: reg = 0x2a; break; \
        default: \
            strcpy((char *)szFile, "SfxDraw.c"); \
            SfxDbg_SetDebugMsg(0, "Undefined Blending", (char *)szFile, line); \
            reg = 0x2a; \
            break; \
        } \
        *(s64 *)((u8 *)(p) + (off)) = reg; \
        *(s64 *)((u8 *)(p) + (off) + 8) = 0x42; \
    }

/* _MakePacket_DrawSprite @ 0x1C1300 */


static unsigned int * _MakePacket_DrawSprite(void *aPos_, unsigned int *pPacket_, signed int *col_) {
    u8 *aPos = (u8 *)aPos_;
    u8 *p = (u8 *)pPacket_;
    signed int *col = col_;
    u64 tmp;
    u32 prim;

    if (((MP2_TEX *)s_pTex)->flag == 0) {
        *(u32 *)(p + 0x00) = 0x10000009;
        *(u32 *)(p + 0x04) = 0;
        *(u32 *)(p + 0x08) = 0;
        *(u32 *)(p + 0x0c) = 0x51000009;
        *(u32 *)(p + 0x10) = 3;
        *(u32 *)(p + 0x14) = 0x10000000;
        *(u32 *)(p + 0x18) = 0xe;
        *(u32 *)(p + 0x1c) = 0;
        *(u64 *)(p + 0x20) = ((u64)(((MP2_RS0 *)&s_rndr_stt[0])->alphaTest ? 2 : 1) << 17) | 0x13001;
        *(u64 *)(p + 0x28) = 0x47;
        MP2_BLEND(p, 0x30, 0x4c8)
        *(u64 *)(p + 0x40) = (((u64)col[3] << 24) | (((u64)col[2] << 16) | ((u64)col[0] | ((u64)col[1] << 8)))) | ((u64)0x3f800000 << 32);
        *(u64 *)(p + 0x48) = 1;
        *(u32 *)(p + 0x50) = 0x8004;
        *(u32 *)(p + 0x54) = 0x10264000;
        *(u32 *)(p + 0x58) = 4;
        *(u32 *)(p + 0x5c) = 0;
        *(u_long128 *)(p + 0x60) = *(u_long128 *)(aPos + 0x00);
        *(u_long128 *)(p + 0x70) = *(u_long128 *)(aPos + 0x10);
        *(u_long128 *)(p + 0x80) = *(u_long128 *)(aPos + 0x20);
        *(u_long128 *)(p + 0x90) = *(u_long128 *)(aPos + 0x30);
        p += 0xa0;
    } else {
        *(u32 *)(p + 0x00) = 0x1000000f;
        *(u32 *)(p + 0x04) = 0;
        *(u32 *)(p + 0x08) = 0;
        *(u32 *)(p + 0x0c) = 0x5100000f;
        *(u32 *)(p + 0x10) = 5;
        *(u32 *)(p + 0x14) = 0x10000000;
        *(u32 *)(p + 0x18) = 0xe;
        *(u32 *)(p + 0x1c) = 0;
        *(u64 *)(p + 0x20) = 0;
        *(u64 *)(p + 0x28) = 0x3f;
        *(u64 *)(p + 0x30) = ((u64)(((MP2_RS0 *)&s_rndr_stt[0])->alphaTest ? 2 : 1) << 17) | 0x13001;
        *(u64 *)(p + 0x38) = 0x47;
        *(u64 *)(p + 0x40) = ((MP2_TEX *)s_pTex)->pHead->tex1;
        *(u64 *)(p + 0x48) = 0x14;
        if (((MP2_RS0 *)&s_rndr_stt[0])->fbmsk == 1) {
            tmp = (u64)s_fb_height_pow << 30 | (((u64)(u16)((1u << s_fb_width_pow) >> 6) << 14 | 0x102a00) | (u64)s_fb_width_pow << 26);
        } else {
            tmp = ((MP2_TEX *)s_pTex)->pHead->tex0;
        }
        *(u64 *)(p + 0x50) = tmp;
        *(u64 *)(p + 0x58) = 6;
        *(u64 *)(p + 0x60) = (((u64)col[3] << 24) | (((u64)col[2] << 16) | ((u64)col[0] | ((u64)col[1] << 8)))) | ((u64)0x3f800000 << 32);
        *(u64 *)(p + 0x68) = 1;
        prim = ((((MP2_RS1 *)&s_rndr_stt[1])->zWrite ? 0x20 : 0) | (((((MP2_RS1 *)&s_rndr_stt[1])->zEnable ? 0 : 0x100) | 0x4c) | (((MP2_RS0 *)&s_rndr_stt[0])->f5 ? 0x10 : 0)))  << 15;
        *(u32 *)(p + 0x70) = 0x8004;
        *(u32 *)(p + 0x74) = prim | 0x20004000;
        *(u32 *)(p + 0x78) = (((MP2_RS1 *)&s_rndr_stt[1])->zEnable ? 2 : 3) | 0x40;
        *(u32 *)(p + 0x7c) = 0;
        *(u_long128 *)(p + 0x80) = *(u_long128 *)(aPos + 0x40);
        *(u_long128 *)(p + 0x90) = *(u_long128 *)(aPos + 0x00);
        *(u_long128 *)(p + 0xa0) = *(u_long128 *)(aPos + 0x40 + 0x10);
        *(u_long128 *)(p + 0xb0) = *(u_long128 *)(aPos + 0x10);
        *(u_long128 *)(p + 0xc0) = *(u_long128 *)(aPos + 0x40 + 0x20);
        *(u_long128 *)(p + 0xd0) = *(u_long128 *)(aPos + 0x20);
        *(u_long128 *)(p + 0xe0) = *(u_long128 *)(aPos + 0x40 + 0x30);
        *(u_long128 *)(p + 0xf0) = *(u_long128 *)(aPos + 0x30);
        p += 0x100;
    }
    return (unsigned int *)p;
}



/* _MakePacket_DrawSprite2 @ 0x1C0F00 */


static unsigned int * _MakePacket_DrawSprite2(void *aPos_, unsigned int *pPacket_, void *aTex, signed int *col_) {
    u8 *aPos = (u8 *)aPos_;
    u8 *p = (u8 *)pPacket_;
    signed int *col = col_;
    u64 tmp;
    u32 prim;

    if (((MP2_TEX *)s_pTex)->flag == 0) {
        *(u32 *)(p + 0x00) = 0x10000009;
        *(u32 *)(p + 0x04) = 0;
        *(u32 *)(p + 0x08) = 0;
        *(u32 *)(p + 0x0c) = 0x51000009;
        *(u32 *)(p + 0x10) = 3;
        *(u32 *)(p + 0x14) = 0x10000000;
        *(u32 *)(p + 0x18) = 0xe;
        *(u32 *)(p + 0x1c) = 0;
        *(u64 *)(p + 0x20) = ((u64)(((MP2_RS0 *)&s_rndr_stt[0])->alphaTest ? 2 : 1) << 17) | 0x13001;
        *(u64 *)(p + 0x28) = 0x47;
        MP2_BLEND(p, 0x30, 0x4c8)
        *(u64 *)(p + 0x40) = (((u64)col[3] << 24) | (((u64)col[2] << 16) | ((u64)col[0] | ((u64)col[1] << 8)))) | ((u64)0x3f800000 << 32);
        *(u64 *)(p + 0x48) = 1;
        *(u32 *)(p + 0x50) = 0x8004;
        *(u32 *)(p + 0x54) = 0x10264000;
        *(u32 *)(p + 0x58) = 4;
        *(u32 *)(p + 0x5c) = 0;
        *(u_long128 *)(p + 0x60) = *(u_long128 *)(aPos + 0x00);
        *(u_long128 *)(p + 0x70) = *(u_long128 *)(aPos + 0x10);
        *(u_long128 *)(p + 0x80) = *(u_long128 *)(aPos + 0x20);
        *(u_long128 *)(p + 0x90) = *(u_long128 *)(aPos + 0x30);
        p += 0xa0;
    } else {
        *(u32 *)(p + 0x00) = 0x1000000f;
        *(u32 *)(p + 0x04) = 0;
        *(u32 *)(p + 0x08) = 0;
        *(u32 *)(p + 0x0c) = 0x5100000f;
        *(u32 *)(p + 0x10) = 5;
        *(u32 *)(p + 0x14) = 0x10000000;
        *(u32 *)(p + 0x18) = 0xe;
        *(u32 *)(p + 0x1c) = 0;
        *(u64 *)(p + 0x20) = 0;
        *(u64 *)(p + 0x28) = 0x3f;
        *(u64 *)(p + 0x30) = ((u64)(((MP2_RS0 *)&s_rndr_stt[0])->alphaTest ? 2 : 1) << 17) | 0x13001;
        *(u64 *)(p + 0x38) = 0x47;
        *(u64 *)(p + 0x40) = ((MP2_TEX *)s_pTex)->pHead->tex1;
        *(u64 *)(p + 0x48) = 0x14;
        if (((MP2_RS0 *)&s_rndr_stt[0])->fbmsk == 1) {
            tmp = (u64)s_fb_height_pow << 30 | (((u64)(u16)((1u << s_fb_width_pow) >> 6) << 14 | 0x102a00) | (u64)s_fb_width_pow << 26);
        } else {
            tmp = ((MP2_TEX *)s_pTex)->pHead->tex0;
        }
        *(u64 *)(p + 0x50) = tmp;
        *(u64 *)(p + 0x58) = 6;
        *(u64 *)(p + 0x60) = (((u64)col[3] << 24) | (((u64)col[2] << 16) | ((u64)col[0] | ((u64)col[1] << 8)))) | ((u64)0x3f800000 << 32);
        *(u64 *)(p + 0x68) = 1;
        prim = ((((MP2_RS1 *)&s_rndr_stt[1])->zWrite ? 0x20 : 0) | (((((MP2_RS1 *)&s_rndr_stt[1])->zEnable ? 0 : 0x100) | 0x4c) | (((MP2_RS0 *)&s_rndr_stt[0])->f5 ? 0x10 : 0)))  << 15;
        *(u32 *)(p + 0x70) = 0x8004;
        *(u32 *)(p + 0x74) = prim | 0x20004000;
        *(u32 *)(p + 0x78) = (((MP2_RS1 *)&s_rndr_stt[1])->zEnable ? 2 : 3) | 0x40;
        *(u32 *)(p + 0x7c) = 0;
        *(u_long128 *)(p + 0x80) = *(u_long128 *)((u8 *)aTex + 0x00);
        *(u_long128 *)(p + 0x90) = *(u_long128 *)(aPos + 0x00);
        *(u_long128 *)(p + 0xa0) = *(u_long128 *)((u8 *)aTex + 0x10);
        *(u_long128 *)(p + 0xb0) = *(u_long128 *)(aPos + 0x10);
        *(u_long128 *)(p + 0xc0) = *(u_long128 *)((u8 *)aTex + 0x20);
        *(u_long128 *)(p + 0xd0) = *(u_long128 *)(aPos + 0x20);
        *(u_long128 *)(p + 0xe0) = *(u_long128 *)((u8 *)aTex + 0x30);
        *(u_long128 *)(p + 0xf0) = *(u_long128 *)(aPos + 0x30);
        p += 0x100;
    }
    return (unsigned int *)p;
}


extern int GetTexSize(int,int,int);
extern int GetClutSize(int,int);
extern unsigned int *LoadImage(int,int,int,int,int,int,int,void *,int,unsigned int *);
typedef struct { unsigned long TBP0:14,TBW:6,PSM:6,TW:4,TH:4,TCC:1,TFX:2,CBP:14,CPSM:4,CSM:1,CSA:5,CLD:3; } M24TextureBits;
typedef struct { u32 total,imageSize; u8 pad[8]; M24TextureBits tex0; u8 other[8]; } M24TextureHead;
void SfxDraw_SetTexture(void *texture) {
    unsigned int *packet;
    M24TextureHead *head;
    void *clut;
    int size;
    u8 *saved;
    u32 image;
    ((struct { unsigned char pad:3,mode:2; } *)s_rndr_stt)->mode=0;
    s_pTex=(u32)texture;
    saved=(u8 *)texture;
    packet=(unsigned int *)lpMdlPacketMem;
    head=*(M24TextureHead **)((u8 *)texture+4);
    size=GetTexSize(1<<head->tex0.TW,1<<head->tex0.TH,head->tex0.PSM);
    image=(u32)((u8 *)head+32);
    clut=(void *)(image+head->imageSize);
    packet=LoadImage(head->tex0.TBP0,*(int *)(saved+88),*(int *)(saved+92),0,0,*(int *)(saved+80),*(int *)(saved+84),(void *)image,size,packet);
    switch(head->tex0.PSM) {
    case 19: case 27:
        size=GetClutSize(head->tex0.PSM,head->tex0.CPSM);
        packet=LoadImage(head->tex0.CBP,1,head->tex0.CPSM,0,0,16,16,clut,size,packet);
        break;
    case 20: case 36: case 44:
        size=GetClutSize(head->tex0.PSM,head->tex0.CPSM);
        packet=LoadImage(head->tex0.CBP,1,head->tex0.CPSM,0,0,8,2,clut,size,packet);
        break;
    }
    lpMdlPacketMem=(u32)packet;
}


/* SfxDraw_SetTexture_NoLoad @ 0x1C0CE0 .. 0x1C0D0C (0x2c bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */


void SfxDraw_SetTexture_NoLoad(void *a0 /* r4 */) {
    u32 v1;

    s_pTex = (u32)a0;
    v1 = 0;
    ((struct { unsigned char _pad:3; unsigned char f:2; } *)&*(u8 *)s_rndr_stt)->f = 0;
    return;
}


/* SfxDraw_SetTexture_FrameBuff @ 0x1C0C50 .. 0x1C0CD8 (0x88 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1280 -> 0x248630
 *   stack: address of the slot at 0x10 escapes at 0x1c0cb8
 *   literal: @1280 initializes the 16-byte local at 0x10
 */


void SfxDraw_SetTexture_FrameBuff(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */, void *a2
        /* r6 */) {
    u32 v0;
    u32 a0_2;

    ((struct { unsigned char _pad:3; unsigned char f:2; } *)&*(u8 *)s_rndr_stt)->f = 1;
    s_fb_width_pow = a0;
    s_fb_height_pow = a1;
    if ((u32)a2 != 0) {
        a0_2 = (u32)s_fb_LURD;
        sceVu0CopyVector((void *)s_fb_LURD, (void *)a2);
    } else {
        v0 = (u32)L1280;
        a0_2 = (u32)s_fb_LURD;
        {
            struct stackFrame_10 { u8 b[16]; } stackFrame_10 __attribute__((aligned(16))) = {{0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0xe0,
                0x43}};
            sceVu0CopyVector((void *)s_fb_LURD, (void *)((u8 *)&stackFrame_10));
        }
    }
    v0 = (u32)_MakePacket_CopyFrameBuffer((unsigned int *)lpMdlPacketMem);
    lpMdlPacketMem = v0;
    return;
}






/* SfxDraw_DrawIndexedPrimitive @ 0x1C0900 .. 0x1C0C4C (0x34c bytes, frame 0xc0) */
extern void sceVu0FTOI0Vector(int *, float *);

#define RS_ZTEST   (((struct { unsigned char f:1; } *)&s_rndr_stt[0])->f)
#define RS_MODE    (((struct { unsigned char _pad:3; unsigned char f:2; } *)&s_rndr_stt[0])->f)
#define RS_USETEX  (((struct { unsigned char _pad:5; unsigned char f:1; } *)&s_rndr_stt[0])->f)
#define RS_PRIM    (((struct { unsigned short _pad:6; unsigned short f:4; } *)&s_rndr_stt[0])->f)
#define RS_UST     (((struct { unsigned char _pad:2; unsigned char f:1; } *)&s_rndr_stt[1])->f)
#define RS_FOG     (((struct { unsigned char _pad:3; unsigned char f:1; } *)&s_rndr_stt[1])->f)

void SfxDraw_DrawIndexedPrimitive(float (*aVert_)[4], float (*aTexPos_)[4], unsigned short *aIdx_, unsigned short num_vert_) {
    unsigned int *lpPacket;
    unsigned int nQWD;
    unsigned int Prim;
    int i;

    lpPacket = (unsigned int *)lpMdlPacketMem;
    nQWD = num_vert_ * 2 + 6;
    lpPacket[0] = nQWD | 0x10000000;
    lpPacket[1] = 0;
    lpPacket[2] = 0;
    lpPacket[3] = nQWD | 0x50000000;
    lpPacket[4] = 2;
    lpPacket[5] = 0x10000000;
    lpPacket[6] = 0xe;
    lpPacket[7] = 0;
    *(u64 *)(lpPacket + 8) = ((u64)(RS_ZTEST ? 2 : 1) << 17) | 0x13001;
    *(s64 *)(lpPacket + 10) = 0x47;
    *(u64 *)(lpPacket + 12) = (RS_MODE == 1) ? (((u64)s_fb_height_pow << 30) | ((((u64)(u16)((1u << s_fb_width_pow) >> 6) << 14) | 0x102a00) | ((u64)s_fb_width_pow << 26))) : *(u64 *)(*(u32 *)(s_pTex + 4) + 0x10);
    *(s64 *)(lpPacket + 14) = 6;
    lpPacket[16] = 1;
    lpPacket[17] = 0x10000000;
    lpPacket[18] = 1;
    lpPacket[19] = 0;
    {
    int col[4] __attribute__((aligned(16))) = {0};
    int ivec[4] __attribute__((aligned(16)));
    col[0] = (u8)(*(u32 *)(s_rndr_stt + 4) >> 24);
    col[1] = (u8)(*(u32 *)(s_rndr_stt + 4) >> 16);
    col[2] = (u8)(*(u32 *)(s_rndr_stt + 4) >> 8);
    col[3] = (u8)(*(u32 *)(s_rndr_stt + 4));
    *(u_long128 *)(lpPacket + 20) = *(u_long128 *)col;
    Prim = ((RS_FOG ? 0x20 : 0) | (((RS_PRIM | 0x48) | (RS_UST ? 0 : 0x100)) | (RS_USETEX ? 0x10 : 0))) << 15;
    lpPacket[24] = (unsigned short)num_vert_ | 0x8000;
    lpPacket[25] = Prim | 0x20004000;
    lpPacket[26] = (RS_UST ? 2 : 3) | 0xe0;
    lpPacket[27] = 0;
    lpPacket += 28;
    for (i = 0; i < num_vert_; i++) {
        unsigned int idx = aIdx_[i];
        *(u_long128 *)lpPacket = *(u_long128 *)aTexPos_[idx & 0x7fff];
        sceVu0FTOI0Vector(ivec, aVert_[idx & 0x7fff]);
        ivec[0] += 0x700;
        ivec[1] += 0x720;
        ivec[0] <<= 4;
        ivec[1] <<= 4;
        *(u64 *)(lpPacket + 4) = ((u64)ivec[2] << 32) | (ivec[0] | ((u64)ivec[1] << 16));
        if (idx & 0x8000) {
            *(s64 *)(lpPacket + 6) = 0xc;
            lpPacket += 8;
        } else {
            *(s64 *)(lpPacket + 6) = 4;
            lpPacket += 8;
        }
    }
    lpMdlPacketMem = (u32)lpPacket;
    }
}



/* SfxDraw_DrawIndexedPrimitive2 @ 0x1C0530 .. 0x1C08FC (0x3cc bytes, frame 0xd0) */


#define RS_ZTEST   (((struct { unsigned char f:1; } *)&s_rndr_stt[0])->f)
#define RS_BLEND   (((struct { unsigned char _pad:1; unsigned char f:2; } *)&s_rndr_stt[0])->f)
#define RS_MODE    (((struct { unsigned char _pad:3; unsigned char f:2; } *)&s_rndr_stt[0])->f)
#define RS_USETEX  (((struct { unsigned char _pad:5; unsigned char f:1; } *)&s_rndr_stt[0])->f)
#define RS_PRIM    (((struct { unsigned short _pad:6; unsigned short f:4; } *)&s_rndr_stt[0])->f)
#define RS_UST     (((struct { unsigned char _pad:2; unsigned char f:1; } *)&s_rndr_stt[1])->f)
#define RS_FOG     (((struct { unsigned char _pad:3; unsigned char f:1; } *)&s_rndr_stt[1])->f)

void SfxDraw_DrawIndexedPrimitive2(sceVu0FVECTOR *aVert_, unsigned int *aColor_, sceVu0FVECTOR *aTexPos_, unsigned short *aIdx_, unsigned short num_vert_) {
    sceVu0IVECTOR ivec;
    unsigned int *lpPacket;
    unsigned int nQWD;
    unsigned int Prim;
    int i;
    int bInhibit_last0;
    int bInhibit_last1;
    int bInhibit;

    nQWD = num_vert_ * 3 + 4;
    lpPacket = _MakePacket_SetBlend((unsigned int *)lpMdlPacketMem, RS_BLEND);
    lpPacket[0] = nQWD | 0x10000000;
    lpPacket[1] = 0;
    lpPacket[2] = 0;
    lpPacket[3] = nQWD | 0x50000000;
    lpPacket[4] = 2;
    lpPacket[5] = 0x10000000;
    lpPacket[6] = 0xe;
    lpPacket[7] = 0;
    *(u64 *)(lpPacket + 8) = ((u64)(RS_ZTEST ? 2 : 1) << 17) | 0x13001;
    *(s64 *)(lpPacket + 10) = 0x47;
    *(u64 *)(lpPacket + 12) = (RS_MODE == 1) ? ((u64)s_fb_height_pow << 30) | ((((u64)(u16)((1u << s_fb_width_pow) >> 6) << 14) | 0x102a00) | ((u64)s_fb_width_pow << 26)) : *(u64 *)(*(u32 *)(s_pTex + 4) + 0x10);
    *(s64 *)(lpPacket + 14) = 6;
    bInhibit_last0 = 0;
    bInhibit_last1 = 0;
    Prim = ((RS_FOG ? 0x20 : 0) | (((RS_PRIM | 0x48) | (RS_UST ? 0 : 0x100)) | (RS_USETEX ? 0x10 : 0))) << 15;
    lpPacket[16] = (unsigned short)num_vert_ | 0x8000;
    lpPacket[17] = Prim | 0x30004000;
    lpPacket[18] = (RS_UST ? 2 : 3) | 0xe10;
    lpPacket[19] = 0;
    lpPacket += 20;
    for (i = 0; i < num_vert_; i++) {
        unsigned int idx = aIdx_[i];
        unsigned int c;
        int kick;
        bInhibit = idx & 0x8000;
        *(u_long128 *)lpPacket = *(u_long128 *)aTexPos_[idx & 0x7fff];
        c = aColor_[idx & 0x7fff];
        *(u64 *)(lpPacket + 4) = (u64)(u8)(c >> 24) | ((u64)(u8)(c >> 16) << 32);
        *(u64 *)(lpPacket + 6) = (u64)(u8)(c >> 8) | ((u64)(u8)c << 32);
        sceVu0FTOI0Vector(ivec, aVert_[idx & 0x7fff]);
        ivec[0] += 0x700;
        ivec[1] += 0x720;
        if (ivec[0] < 0 || ivec[0] >= 0x1000 || ivec[1] < 0 || ivec[1] >= 0x1000 || ivec[2] < 0 || 16776960.0f < (float)ivec[2]) {
            bInhibit = 1;
        }
        ivec[0] <<= 4;
        ivec[1] <<= 4;
        *(u64 *)(lpPacket + 8) = ((u64)ivec[2] << 32) | (ivec[0] | ((u64)ivec[1] << 16));
        kick = !(bInhibit || bInhibit_last0 || bInhibit_last1);
        if (kick) {
            *(s64 *)(lpPacket + 10) = 4;
            lpPacket += 12;
        } else {
            *(s64 *)(lpPacket + 10) = 0xc;
            lpPacket += 12;
        }
        bInhibit_last0 = bInhibit_last1;
        bInhibit_last1 = bInhibit;
    }
    lpMdlPacketMem = (u32)lpPacket;
}



/* SfxDraw_DrawIndexedPrimitive3 @ 0x1C0030 .. 0x1C052C (0x4fc bytes, frame 0xf0) */


#define RS_ZTEST   (((struct { unsigned char f:1; } *)&s_rndr_stt[0])->f)
#define RS_BLEND   (((struct { unsigned char _pad:1; unsigned char f:2; } *)&s_rndr_stt[0])->f)
#define RS_MODE    (((struct { unsigned char _pad:3; unsigned char f:2; } *)&s_rndr_stt[0])->f)
#define RS_USETEX  (((struct { unsigned char _pad:5; unsigned char f:1; } *)&s_rndr_stt[0])->f)
#define RS_PRIM    (((struct { unsigned short _pad:6; unsigned short f:4; } *)&s_rndr_stt[0])->f)
#define RS_UST     (((struct { unsigned char _pad:2; unsigned char f:1; } *)&s_rndr_stt[1])->f)
#define RS_FOG     (((struct { unsigned char _pad:3; unsigned char f:1; } *)&s_rndr_stt[1])->f)
#define RS_WRAP    (((struct { unsigned char _pad:4; unsigned char f:2; } *)&s_rndr_stt[1])->f)

void SfxDraw_DrawIndexedPrimitive3(unsigned short fvf_, void *aVert_, unsigned short *aIdx_, unsigned short num_indices_) {
    sceVu0IVECTOR ivec;
    int num_flag;
    unsigned int *lpPacket;
    unsigned int nQWD;
    unsigned int size_1vert;
    int m;
    unsigned int Prim;
    int i;
    int bInhibit_last0;
    int bInhibit_last1;
    int bInhibit;
    unsigned char *pVertHead;
    float t;
    float q;

    num_flag = 0;
    size_1vert = ((fvf_ & 2) ? 8 : 0) + (((fvf_ & 1) ? 4 : 0) + (((fvf_ & 8) ? 0x10 : 0) + ((fvf_ & 4) ? 0x10 : 0)));
    if (size_1vert & 0xf) {
        size_1vert += 0x10 - (size_1vert & 0xf);
    }
    for (m = 0; fvf_ >> m; m++) {
        if ((fvf_ >> m) & 1) {
            num_flag++;
        }
    }
    nQWD = num_indices_ * num_flag + 5;
    lpPacket = _MakePacket_SetBlend((unsigned int *)lpMdlPacketMem, RS_BLEND);
    lpPacket[0] = nQWD | 0x10000000;
    lpPacket[1] = 0;
    lpPacket[2] = 0;
    lpPacket[3] = nQWD | 0x50000000;
    lpPacket[4] = 3;
    lpPacket[5] = 0x10000000;
    lpPacket[6] = 0xe;
    lpPacket[7] = 0;
    *(u64 *)(lpPacket + 8) = ((u64)(RS_ZTEST ? 2 : 1) << 17) | 0x13001;
    *(s64 *)(lpPacket + 10) = 0x47;
    *(u64 *)(lpPacket + 12) = (RS_MODE == 1) ? ((u64)s_fb_height_pow << 30) | ((((u64)(u16)((1u << s_fb_width_pow) >> 6) << 14) | 0x102a00) | ((u64)s_fb_width_pow << 26)) : *(u64 *)(*(u32 *)(s_pTex + 4) + 0x10);
    *(s64 *)(lpPacket + 14) = 6;
    *(u64 *)(lpPacket + 16) = (u64)RS_WRAP | ((u64)RS_WRAP << 2);
    *(s64 *)(lpPacket + 18) = 8;
    Prim = ((RS_FOG ? 0x20 : 0) | (((RS_PRIM | 0x48) | (RS_UST ? 0 : 0x100)) | (RS_USETEX ? 0x10 : 0))) << 15;
    lpPacket[20] = (unsigned short)num_indices_ | 0x8000;
    lpPacket[21] = Prim | 0x30004000;
    lpPacket[22] = ((fvf_ & 8) ? 0xe00 : 0) | (((fvf_ & 1) ? 0x10 : 0) | ((fvf_ & 2) ? (RS_UST ? 2 : 3) : 0));
    lpPacket[23] = 0;
    lpPacket += 24;
    bInhibit_last0 = 0;
    bInhibit_last1 = 0;
    for (i = 0; i < num_indices_; i++) {
        bInhibit = *aIdx_ & 0x8000;
        pVertHead = (unsigned char *)aVert_ + size_1vert * (*aIdx_ & 0x7fff);
        if (fvf_ & 2) {
            t = ((float *)pVertHead)[1];
            q = ((float *)pVertHead)[2];
            ((float *)lpPacket)[0] = ((float *)pVertHead)[0];
            ((float *)lpPacket)[1] = t;
            ((float *)lpPacket)[2] = q;
            lpPacket[3] = 0;
            pVertHead += 12;
            lpPacket += 4;
        }
        if (fvf_ & 1) {
            unsigned int c = *(unsigned int *)pVertHead;
            *(u64 *)lpPacket = (u64)(u8)(c >> 24) | ((u64)(u8)(c >> 16) << 32);
            *(u64 *)(lpPacket + 2) = (u64)(u8)(c >> 8) | ((u64)(u8)c << 32);
            pVertHead += 4;
            lpPacket += 4;
        }
        pVertHead += ((unsigned int)pVertHead & 0xf) ? 0x10 - ((unsigned int)pVertHead & 0xf) : 0;
        if (fvf_ & 8) {
            int kick;
            sceVu0FTOI0Vector(ivec, (float *)pVertHead);
            if (ivec[0] < 0 || ivec[0] >= 0x1000 || ivec[1] < 0 || ivec[1] >= 0x1000 || ivec[2] < 0 || 16776960.0f < (float)ivec[2]) {
                bInhibit = 1;
            }
            ivec[0] <<= 4;
            ivec[1] <<= 4;
            *(u64 *)lpPacket = ((u64)ivec[2] << 32) | (ivec[0] | ((u64)ivec[1] << 16));
            kick = !(bInhibit || bInhibit_last0 || bInhibit_last1);
            if (kick) {
                *(s64 *)(lpPacket + 2) = 4;
                lpPacket += 4;
            } else {
                *(s64 *)(lpPacket + 2) = 0xc;
                lpPacket += 4;
            }
        }
        bInhibit_last0 = bInhibit_last1;
        bInhibit_last1 = bInhibit;
        aIdx_++;
    }
    lpMdlPacketMem = (u32)lpPacket;
}

static u32 s_fb_LURD[0x4];
static u8 s_rndr_stt[0x10];
static u16 s_fb_width_pow;
static u16 s_fb_height_pow;
static u32 s_pTex;
