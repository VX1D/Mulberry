#include "common.h"

/* SfxFog_EndDrama @ 0x2054E0 .. 0x20554C (0x6c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00205500
 *   return without a value in a non-void function
 */

extern signed int SfxMdl_Free(unsigned short);
static u32 s_mng[296];


extern unsigned short SfxMdl_Alloc(unsigned short, signed int);
extern char * strcpy(char *, const char *);
extern void SfxDbg_SetDebugMsg(unsigned char, char *, char *, unsigned int);
extern signed int SfxMdl_SetAlpha(unsigned short, float);
extern signed int SfxMdl_SetColor(unsigned short, float, float, float);
extern signed int SfxMdl_GetTest(unsigned short, unsigned int *);
extern signed int SfxMdl_SetTest(unsigned short, unsigned int);
extern signed int SfxMdl_EnableZWrite(unsigned short, signed int);
extern signed int SfxMdl_SetDrawStage(unsigned short, unsigned char);
extern void SfxCalc_QtnMakeFromPYR(float *, float, float, float);
extern void sceVu0CopyVector(void *, void *);


/* SfxFog_AddDramaSetting @ 0x2057C0 .. 0x205814 (0x54 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

static u32 s_mng[296];

/* SfxFog_Action @ 0x205820 .. 0x205920 (0x100 bytes, frame 0xc0) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x205850 is a float copy
 *   stack: address of the slot at 0xa0 escapes at 0x205858
 *   stack: address of the slot at 0xb0 escapes at 0x205890
 *   stack: address of the slot at 0xb0 escapes at 0x2058a0
 *   stack: address of the slot at 0x70 escapes at 0x2058b4
 *   stack: address of the slot at 0x70 escapes at 0x2058cc
 *   cfg: loop body is not one contiguous region: .L00205858
 */

extern void SfxCalc_QtnMakeFromPYR(float *, float, float, float);
extern void SfxCalc_QtnMult(float *, float *, float *);
extern void SfxCalc_MakeMatrixFromQtn(void *, float *);
extern void sceVu0CopyVector(void *, void *);
extern signed int SfxMdl_SetMatrix(unsigned short, void *);
extern signed int SfxMdl_EnableDraw(unsigned short, signed int);
extern u8 GameSt[];
extern u8 *lpDrawMng;


/* SfxFog_Initialize @ 0x205920 .. 0x205964 (0x44 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern void *memset();
static u32 s_mng[296];

/* SfxFog_CheckActive @ 0x205970 .. 0x20597C (0xc bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x205978 computes the return value
 */

static u32 s_mng[296];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 SfxFog_CheckActive(void);
u32 SfxFog_Initialize(void);
void SfxFog_Action(float f12 );
u32 SfxFog_AddDramaSetting(unsigned short a0 , unsigned short a1 , float f12 );
void SfxFog_StartDrama(unsigned int a0 , unsigned int a1 );
u32 SfxFog_EndDrama(void);


u32 SfxFog_CheckActive(void) {
    return *(s32 *)((u8 *)&s_mng + 0x494);
}

u32 SfxFog_Initialize(void) {
    memset((u32)s_mng, 0, 0x4a0);
    *(u16 *)((u8 *)&s_mng + 0x50) = 0xffff;
    *(u16 *)((u8 *)&s_mng + 0x30) = 0xffff;
    *(u16 *)((u8 *)&s_mng + 0x10) = 0xffff;
    return;
}

void SfxFog_Action(float f12 /* f12 */) {
    s32 s3;
    u32 s4;
    u8 *s2;
    float f20;
    u8 *s1;
    u16 a0;
    u32 v1;
    u32 v0;
    float f2;
    u8 *s0;
    u8 stackFrame_B0[16] __attribute__((aligned(16)));
    u8 stackFrame_70[64] __attribute__((aligned(16)));

    s3 = 0;
    s2 = (u8 *)s_mng;
    s1 = (u8 *)s_mng;
    f20 = f12;
    s0 = ((u8 *)&stackFrame_70[48]);
    do {
        a0 = *(u16 *)(s2 + 0x10);
        v1 = 0xffff;
        if (a0 != v1) {
            v0 = 1;
            v1 = GameSt[5];
            if (v1 == v0) {
                f2 = *(float *)s2;
                SfxCalc_QtnMakeFromPYR((float *)((u8 *)&stackFrame_B0[0]), (f20 * f2), (f20 *
                    *(float *)(s2 + 4)), (f20 * *(float *)(s2 + 8)));
                SfxCalc_QtnMult((float *)(s1 + 0x60), (float *)((u8 *)&stackFrame_B0[0]), (float
                    *)(u8 *)(s1 + 0x60));
                v0 = ((u32)lpDrawMng);
                s4 = v0 + 0x230;
                SfxCalc_MakeMatrixFromQtn((void *)((u8 *)&stackFrame_70[0]), (float *)(s1 + 0x60));
                sceVu0CopyVector((void *)s0, (void *)s4);
                a0 = *(u16 *)(s2 + 0x10);
                SfxMdl_SetMatrix(a0, (void *)((u8 *)&stackFrame_70[0]));
            } else {
                SfxMdl_EnableDraw(a0, 0);
            }
        }
        s3 = s3 + 1;
        v1 = s3 < (s32)3;
        s2 = (u8 *)(s2 + 0x20);
        s1 = (u8 *)(s1 + 0x10);
    } while (v1 != 0);
    return;
}

u32 SfxFog_AddDramaSetting(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */, float f12 /* f12
        */) {
    u32 t0;
    u32 v1;

    t0 = *(u8 *)(s_mng + 0x124);
    v1 = (u32)((u8 *)s_mng + 0x94);
    t0 = t0 << 3;
    *(u16 *)(u16 *)((u8 *)(u16 *)((u8 *)s_mng + 0x90) + t0) = a0;
    *(u16 *)(u16 *)((u8 *)(u16 *)((u8 *)s_mng + 0x92) + t0) = a1;
    *(f32 *)(u32)(v1 + t0) = (float)f12;
    v1 = *(u8 *)(s_mng + 0x124);
    *(u8 *)(s_mng + 0x124) = v1 + 1;
    return;
}

void SfxFog_StartDrama(unsigned int a0 /* r4 */, unsigned int a1 /* r5 */) {
    s32 t1;
    u8 *t0;
    u32 a3;
    s32 a2;
    u32 v1;
    s32 s3;
    u8 *s2;
    float *s1;
    u16 s0;
    u32 v0;
    float f12;
    u16 a0_2;
    u8 stackFrame_18C[4] __attribute__((aligned(4)));
    u8 stackFrame_80[268] __attribute__((aligned(16)));

    a2 = *(u8 *)(s_mng + 0x124);
    t1 = 0;
    if (0 < (s32)a2) {
        a1 = (u16)a1;
        t0 = (u8 *)s_mng;
        a3 = (u16)a0;
        do {
            v1 = *(u16 *)(t0 + 0x90);
            if (v1 == (u32)a3 && (u32)*(u16 *)(t0 + 0x92) == a1) {
                break;
            }
            t1 = t1 + 1;
            v1 = t1 < (s32)a2;
            t0 = (u8 *)(t0 + 8);
        } while (v1 != 0);
    }
    if ((u32)t1 != a2) {
        s2 = (u8 *)s_mng;
        s0 = a0;
        s3 = 0;
        s1 = (float *)(s32)((u32)(s32)(u32)&((struct { u8 b[8]; } *)s_mng)[t1] + 0x94);
        do {
            *(u16 *)(s2 + 0x10) = SfxMdl_Alloc(0x37, 0);
            a0_2 = *(u16 *)(s2 + 0x10);
            if (a0_2 == (u32)0xffff) {
                strcpy((char *)((u8 *)&stackFrame_80[0]), (const char *)"SfxFog.c");
                SfxDbg_SetDebugMsg(0, "SfxFog Create Failed", (char *)((u8 *)&stackFrame_80[0]),
                    0xca);
            } else {
                f12 = *(float *)s1;
                SfxMdl_SetAlpha(a0_2, f12);
                if ((s32)s0 >= (s32)0x50 && (s32)s0 <= (s32)0x59) {
                    a0_2 = *(u16 *)(s2 + 0x10);
                    SfxMdl_SetColor(a0_2, (f32)1.0f, (f32)0.5f, (float)0.5f);
                } else {
                    a0_2 = *(u16 *)(s2 + 0x10);
                    SfxMdl_SetColor(a0_2, 1.0f, (float)1.0f, (float)1.0f);
                }
                a0_2 = *(u16 *)(s2 + 0x10);
                SfxMdl_GetTest(a0_2, (unsigned int *)((u8 *)&stackFrame_18C[0]));
                v1 = *(s32 *)((u8 *)&stackFrame_18C[0]);
                v0 = 0x20000;
                a0_2 = *(u16 *)(s2 + 0x10);
                SfxMdl_SetTest(a0_2, (u32)(v1 & 0x1f) + 0x20000);
                a0_2 = *(u16 *)(s2 + 0x10);
                SfxMdl_EnableZWrite(a0_2, 0);
                a0_2 = *(u16 *)(s2 + 0x10);
                SfxMdl_SetDrawStage(a0_2, 3);
            }
            s3 = s3 + 1;
            v0 = s3 < (s32)3;
            s2 = (u8 *)(s2 + 0x20);
        } while (v0 != 0);
        SfxCalc_QtnMakeFromPYR((float *)(u8 *)(s_mng + 0x18), 0.0f, (float)0.0f, (float)0.0f);
        SfxCalc_QtnMakeFromPYR((float *)(u8 *)(s_mng + 0x1c), 0.0f, 1.5707964f, (float)0.0f);
        SfxCalc_QtnMakeFromPYR((float *)(u8 *)(s_mng + 0x20), (f32)1.5707964f, (f32)0.0f,
            (float)0.0f);
        sceVu0CopyVector((void *)s_mng, (void *)(u8[16]){0xfd, 0xad, 0, 0x3c, 0xfd, 0xad, 0x80,
            0x3c, 0, 0, 0, 0, 0, 0, 0, 0});
        sceVu0CopyVector((void *)(u8 *)(s_mng + 8), (void *)(u8[16]){0xfb, 4, 0xc1, 0x3c, 0x7c,
            0xd9, 0x20, 0x3d, 0, 0, 0, 0, 0, 0, 0, 0});
        sceVu0CopyVector((void *)(u8 *)(s_mng + 0x10), (void *)(u8[16]){0xfb, 4, 0x41, 0x3d, 0x7a,
            0x30, 0x61, 0x3d, 0, 0, 0, 0, 0, 0, 0, 0});
        s_mng[0x125] = 1;
    }
    return;
}

u32 SfxFog_EndDrama(void) {
    s32 s1;
    u8 *s0;
    u16 a0;
    s32 v1;

    s1 = 0;
    s0 = (u8 *)s_mng;
    do {
        a0 = *(u16 *)(s0 + 0x10);
        if ((u32)a0 != (u32)0xffff) {
            SfxMdl_Free(a0);
            v1 = 0xffff;
            *(u16 *)(s0 + 0x10) = 0xffff;
        }
        s1 = s1 + 1;
        v1 = s1 < (s32)3;
        s0 = (u8 *)(s0 + 0x20);
    } while ((u32)v1 != 0);
    s_mng[0x125] = 0;
    return;
}
