#include "common.h"

/* DrawBlurTexture @ 0x168D80 .. 0x168F7C (0x1fc bytes, frame 0x40) */
/*
 * dcomp notes:
 *   quad: v1: 128-bit web split from its scalar uses
 *   quad: a3: 128-bit web split from its scalar uses
 *   quad: a1: 128-bit web split from its scalar uses
 *   literal: @716 -> 0x228f80
 *   literal: @718 -> 0x228fa0
 *   stack: address of the slot at 0x20 escapes at 0x168dd4
 *   stack: address of the slot at 0x0 escapes at 0x168dd4
 *   stack: address of the slot at 0x20 escapes at 0x168ec8
 *   stack: address of the slot at 0x0 escapes at 0x168ec8
 *   literal: @718 initializes the 32-byte local at 0x0
 *   literal: @716 initializes the 32-byte local at 0x20
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */

extern u8 *lpDrawMng;


extern void * MemAllocReal(unsigned int, char *, char *);
extern int sceGsSetDefStoreImage(void *, short, short, short, short, short, short, short);
extern void FlushCache(int);
extern int sceGsExecStoreImage(void *, void *);
extern int sceGsSyncPath(int, unsigned short);
extern void * memset(void *, int, unsigned int);
extern void * memcpy(void *, const void *, unsigned int);
extern void MemFree(void *);
extern u8 AlphaData[];
extern s32 FOCUS_Z;
void MakeDepthAlphaTexture(void);


/* DrawDepthOfField @ 0x169290 .. 0x1693D4 (0x144 bytes, frame 0x30) */

extern void MakeDepthAlphaTexture(void);
extern signed int GetTexSize(signed int, signed int, signed int);
extern unsigned int * LoadImage(signed int, signed int, signed int, signed int, signed int, signed
    int, signed int, void *, signed int, unsigned int *);
static unsigned int * CopyFrameBuffer(unsigned int *a0 , signed int a1 );
static unsigned int * CopyFrameBuffer(unsigned int *, signed int);
extern void FlushCache(int);
extern u32 DMABuf[];
extern u8 AlphaData[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void DrawDepthOfField(void);
void MakeDepthAlphaTexture(void);
static unsigned int * CopyFrameBuffer(unsigned int *a0 , signed int a1 );
static unsigned int * DrawBlurTexture(unsigned int *a0 );


void DrawDepthOfField(void) {
    u8 *s0;
    u32 a0;
    u32 v1;
    u32 v0;
    u8 stackFrame[16] __attribute__((aligned(16)));

    s0 = (u8 *)DMABuf;
    do {
        v0 = *(volatile s32 *)0x10009000;
        v0 = v0 & 0x100;
    } while (v0 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    MakeDepthAlphaTexture();
    v0 = GetTexSize(0x200, 0x1c0, 0x1b);
    v0 = (u32)LoadImage(0x2a00, 8, 0x1b, 0, 0, 0x200, 0x1c0, (void *)AlphaData, (signed int)v0,
        (unsigned int *)s0);
    a0 = v0;
    v0 = (u32)CopyFrameBuffer((unsigned int *)a0, 0);
    a0 = v0;
    v0 = (u32)DrawBlurTexture((unsigned int *)a0);
    a0 = v0;
    v0 = (u32)CopyFrameBuffer((unsigned int *)a0, 1);
    v1 = 0x70000000;
    *(u32 *)v0 = 0x70000000;
    *(u32 *)(((u8 *)v0 + 4)) = 0;
    *(u32 *)(((u8 *)v0 + 8)) = 0;
    *(u32 *)(((u8 *)v0 + 0xc)) = 0;
    FlushCache(0);
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    *(volatile u32 *)0x10009020 = 0;
    a0 = (u32)DMABuf;
    *(volatile u32 *)0x10009010 = 0;
    *(volatile u32 *)0x10009030 = (u32)DMABuf;
    *(volatile u32 *)0x10009000 = 0x145;
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    return;
}

void MakeDepthAlphaTexture(void) {
    unsigned int *dst;
    u8 gs_simage[112] __attribute__((aligned(16)));
    unsigned char *lpZPixel;
    unsigned char *lpAPixel;
    int cntW;
    int cntH;
    int numW;
    int numH;
    int Pixel;

    dst = MemAllocReal(0xa8000, (char *)__FUNCTION__, "");
    sceGsSetDefStoreImage(gs_simage, 0x1c00, 8, 0x31, 0, 0, 0x200, 0x1c0);
    FlushCache(0);
    sceGsExecStoreImage(gs_simage, dst);
    sceGsSyncPath(0, 0);

    memset(AlphaData, 0x20, 0x38000);

    lpAPixel = AlphaData;
    lpZPixel = (unsigned char *)(dst + 3);
    cntH = 0x38;
    while (cntH--) {
        lpZPixel += 0x1800;
        cntW = 0x40;
        while (cntW--) {
            Pixel = lpZPixel[2] - FOCUS_Z;
            if (Pixel < 0) Pixel = -Pixel;
            if (Pixel > 0x3f) Pixel = 0x3f;
            numW = 8;
            while (numW--) {
                *lpAPixel++ = Pixel >> 1;
            }
            lpZPixel += 0x18;
        }
        lpZPixel += 0x1200;
        numH = 7;
        while (numH--) {
            memcpy(lpAPixel, lpAPixel - 0x200, 0x200);
            lpAPixel += 0x200;
        }
    }
    MemFree(dst);
}

/* CopyFrameBuffer @ 0x168F80 .. 0x1690D8 (0x158 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x168f90 writes a register its branch at 0x168f8c reads
 *   return: daddu at 0x1690d4 computes the return value
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */

static unsigned int * CopyFrameBuffer(unsigned int *a0 /* r4 */, signed int a1 /* r5 */) {
    u32 t0;
    u32 a3;
    u32 a2;
    u32 v1;
    u64 a2_64;
    u32 v0;
    u64 v1_64;

    a2 = (u32)lpDrawMng;
    v1 = *(s32 *)((a2 + 0x408));
    if (v1 == (u32)1) {
        v0 = a2 + 0x60;
    } else {
        v0 = a2 + 0x150;
    }
    v1 = 0x51000000;
    *(u32 *)a0 = 0x10000000 | 7;
    a0[1] = 0;
    a0[2] = 0;
    a0[3] = 0x51000000 | 7;
    a0[4] = 6;
    a0[5] = 0x10000000;
    a0[6] = 0xe;
    a0[7] = 0;
    *(u64 *)(((u8 *)a0 + 0x20)) = 0;
    *(s64 *)(((u8 *)a0 + 0x28)) = (s32)0x3f;
    if ((u32)(s32)a1 == 0) {
        t0 = *(u16 *)v0;
        a3 = 0x1080000;
        a2_64 = (u64)(s32)(0x1080000 | 0x2a00) << 0x20;
        *(u64 *)(((u8 *)a0 + 0x30)) = (u64)((s32)((s32)((u32)(t0 & 0x1ff) << 5))) |
            (u64)((u64)((s32)((s32)0x1080000)) | a2_64);
        *(s64 *)(((u8 *)a0 + 0x38)) = (s32)0x50;
        a0 = (unsigned int *)(u8 *)(a0 + 0x10);
    } else {
        t0 = *(u16 *)v0;
        a2 = 0x1080000;
        a2_64 = (u64)((u32)(0x1080000 | 0x2a00)) | (u64)((u64)(u32)0x1080000 << 0x20);
        *(u64 *)(((u8 *)a0 + 0x30)) = (u64)((u64)(s32)((u32)(t0 & 0x1ff) << 5) << 0x20) | a2_64;
        *(s64 *)(((u8 *)a0 + 0x38)) = (s32)0x50;
        a0 = (unsigned int *)(u8 *)(a0 + 0x10);
    }
    *(u64 *)a0 = 0;
    *(s64 *)(((u8 *)a0 + 8)) = (s32)0x51;
    *(u64 *)(((u8 *)a0 + 0x10)) = (u64)((s32)((s32)0x200)) | (u64)((u64)(u32)0x1c0 << 0x20);
    *(s64 *)(((u8 *)a0 + 0x18)) = (s32)0x52;
    *(s64 *)(((u8 *)a0 + 0x20)) = (s32)2;
    *(s64 *)(((u8 *)a0 + 0x28)) = (s32)0x53;
    if (a1 == 0) {
        *(u64 *)(((u8 *)a0 + 0x30)) = ((u64)0xff000000 << 0x20) | 0x80150;
        *(u64 *)(((u8 *)a0 + 0x38)) = 0x4c;
        a0 += 0x10;
    } else {
        *(u64 *)(((u8 *)a0 + 0x30)) = *(u64 *)v0;
        *(u64 *)(((u8 *)a0 + 0x38)) = 0x4c;
        a0 += 0x10;
    }
    return (unsigned int *)a0;
}

static unsigned int * DrawBlurTexture(unsigned int *a0 /* r4 */) {
    u32 t6;
    s32 t5;
    s32 t4;
    s32 t3;
    u32 t2;
    s32 t1;
    u32 t0;
    u32 *a3;
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;

    v0 = 0x228f80;
    v1 = 0x228fa0;
    {
        struct stackFrame_20 { u8 b[32]; } stackFrame_20 __attribute__((aligned(16))) = {{0x02,
            0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff,
            0xff, 0x03, 0x00, 0x00, 0x00, 0xfd, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00}};
        t0 = (u32)((u8 *)&stackFrame_20);
        {
            struct stackFrame_0 { u8 b[32]; } stackFrame_0 __attribute__((aligned(16))) = {{0x02,
                0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff,
                0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xfd,
                0xff, 0xff, 0xff}};
            a2 = (u32)((u8 *)&stackFrame_0);
            a1 = ((u32)lpDrawMng);
            t2 = a1 + 0x150;
            t2 = (u32)*(s32 *)((a1 + 0x408)) == (u32)1 ? (s32)(a1 + 0x60) : t2;
            a1 = 0x10000000;
            v1 = 0x51000000;
            *(u32 *)a0 = 0x10000000 | 7;
            a0[1] = 0;
            v0 = 0x8006;
            a0[2] = 0;
            a0[3] = (u32)(u32 *)(0x51000000 | 7);
            a0[4] = 0x8006;
            a0[5] = 0x10000000;
            a0[6] = 0xe;
            a0[7] = 0;
            v0 = 6;
            a2 = 0x64120000;
            *(u64 *)(((u8 *)a0 + 0x20)) = 0;
            *(s64 *)(((u8 *)a0 + 0x28)) = (s32)0x3f;
            *(u64 *)(((u8 *)a0 + 0x30)) = 0;
            *(s64 *)(((u8 *)a0 + 0x38)) = (s32)0x14;
            a2 = 0x3f800000;
            a2 = 0x8080;
            *(u64 *)(((u8 *)a0 + 0x40)) = (u64)((s32)((s32)((u32)((u32)(*(u16 *)t2) & 0x1ff) <<
                5))) | (u64)(((u64)((s32)((s32)0x64120000)) | (u64)((u64)(s32)v0 << 0x20)));
            *(s64 *)(((u8 *)a0 + 0x48)) = (s32)v0;
            *(u64 *)(((u8 *)a0 + 0x50)) = 0;
            *(s64 *)(((u8 *)a0 + 0x58)) = (s32)0x47;
            *(u64 *)((u8 *)(a0 + 0x18)) = (u64)((s32)((s32)0x54)) | (u64)((u64)(u32)0x20 << 0x20);
            *(s64 *)(((u8 *)a0 + 0x68)) = (s32)0x42;
            *(u64 *)(((u8 *)a0 + 0x70)) = (u64)((u64)((u64)0x8080 << 0x10) | (u64)(0x8080)) |
                (u64)((u64)(u32)0x3f800000 << 0x20);
            *(s64 *)(((u8 *)a0 + 0x78)) = (s32)1;
            a0 = (unsigned int *)(u8 *)(a0 + 0x20);
            t0 = 0;
            a3 = (u32 *)((u8 *)&stackFrame_20);
            a2 = (u32)((u8 *)&stackFrame_0);
            t1 = 0x20eb0000;
            a1 = 0x10000000 | 5;
            v1 = 0x51000000 | 5;
            v0 = 0x8002;
            t6 = 0x20eb0000 | 0x4000;
            t5 = 0x43;
            t4 = 0x2000;
            t3 = 0x1c00;
            do {
                *(u32 *)a0 = a1;
                a0[1] = 0;
                a0[2] = 0;
                a0[3] = v1;
                a0[4] = v0;
                a0[5] = t6;
                a0[6] = t5;
                a0[7] = 0;
                a0[8] = 0;
                a0[9] = 0;
                a0[0xa] = 0;
                a0[0xb] = 0;
                a0[0xc] = (u32)(*(s32 *)a3 + 0x700) << 4;
                a0[0xd] = (u32)(*(s32 *)a2 + 0x720) << 4;
                a0[0xe] = 0;
                a0[0xf] = 0;
                a0[0x10] = t4;
                a0[0x11] = t3;
                a0[0x12] = 0;
                a0[0x13] = 0;
                a0[0x14] = (u32)(*(s32 *)a3 + 0x900) << 4;
                a0[0x15] = (u32)(*(s32 *)a2 + 0x8e0) << 4;
                a0[0x16] = 0;
                a3 = (u32 *)(u8 *)(a3 + 1);
                a2 = a2 + 4;
                a0[0x17] = 0;
                a0 = (unsigned int *)(u8 *)(a0 + 0x18);
                t0 = t0 + 1;
                t1 = (s32)t0 < (s32)8;
            } while ((u32)t1 != 0);
            return (unsigned int *)a0;
        }
    }
}
static u8 AlphaData[0x38000];
static u32 DMABuf[0x1000];
static s32 FOCUS_Z;
