#include "common.h"

/* ClearZBuffer @ 0x141440 .. 0x1414DC (0x9c bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u32 lpMdlPacketMem;

/* ResetVramAddr @ 0x1414E0 .. 0x1414F0 (0x10 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u32 lpVramMng;


extern void sceGsSetDefDBuff(void *,short,short,short,short,short,short);
extern int sceGsSwapDBuff(void *,int);
extern u32 lpDrawMng;

typedef struct VramBaseBits { unsigned short base:9,pad:7; } VramBaseBits;
typedef struct VramFrameBits { unsigned long long low:32,mask:32; } VramFrameBits;


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void InitVramMng(s32 width,s32 height,s32 format,s32 depth);
signed int GetTexSize(signed int width, signed int height, signed int format);
signed int GetClutSize(signed int psm, signed int cpsm);
signed int GetVramAddr(signed int a0 );
void SetNextVramAddr(signed int a0 );
u32 ResetVramAddr(void);
u32 ClearZBuffer(void);

void InitVramMng(s32 width,s32 height,s32 format,s32 depth) {
    s32 page,pixels;
    u32 size,colorSize;
    u32 draw;
    switch(format) {
    case 0: pixels=(u32)width*(u32)height; size=(u32)pixels<<2; break;
    case 1: pixels=(u32)width*(u32)height; size=(u32)pixels<<2; break;
    case 2: case 10: pixels=(u32)width*(u32)height; size=(u32)pixels<<1; break;
    default: pixels=(u32)width*(u32)height; size=(u32)pixels<<2;
    }
    page=(s32)size/4/2048;
    sceGsSetDefDBuff((void *)lpDrawMng,(s16)format,(s16)width,(s16)height,3,(s16)depth,1);
    ((VramBaseBits *)(lpDrawMng+0x60))->base=page;
    ((VramBaseBits *)(lpDrawMng+0x150))->base=0;
    draw=lpDrawMng;
    ((VramFrameBits *)(draw+0x60))->mask=0xff000000;
    ((VramFrameBits *)(draw+0x150))->mask=0xff000000;
    ((VramBaseBits *)(draw+0x70))->base=page*2;
    ((VramBaseBits *)(lpDrawMng+0x160))->base=page*2;
    ((VramBaseBits *)(lpDrawMng+0x10))->base=0;
    ((VramBaseBits *)(lpDrawMng+0x38))->base=page;
    sceGsSwapDBuff((void *)lpDrawMng,*(s32 *)(lpDrawMng+0x408));
    *(s32 *)(lpDrawMng+0x408)=!*(s32 *)(lpDrawMng+0x408);
    switch(depth) {
    case 48: size=(u32)pixels<<2; break;
    case 49: size=(u32)pixels<<2; break;
    case 50: case 58: size=(u32)pixels<<1; break;
    default: size=(u32)pixels<<2;
    }
    switch(format) {
    case 0: colorSize=(u32)pixels<<2; break;
    case 1: colorSize=(u32)pixels<<2; break;
    case 2: case 10: colorSize=(u32)pixels<<1; break;
    default: colorSize=(u32)pixels<<2;
    }
    size+=colorSize<<1;
    *(u32 *)lpVramMng=size;
    *(u32 *)(lpVramMng+4)=*(u32 *)lpVramMng;
}


signed int GetTexSize(signed int width, signed int height, signed int format) {
    s32 size;
    switch ((u32)format) {
    case 0:
    case 1:
    case 48:
    case 49:
        if (width < height && width <= 64) size = ((u32)width * (u32)height) << 3;
        else size = ((u32)width * (u32)height) << 2;
        break;
    case 2:
    case 10:
    case 50:
    case 58:
        if (width < height && width <= 64) size = ((u32)width * (u32)height) << 2;
        else size = ((u32)width * (u32)height) << 1;
        break;
    case 19:
    case 27:
        if (width < height && width <= 64) size = ((u32)width * (u32)height) << 1;
        else if (width / height == 8) size = (u32)((s32)((u32)width * (u32)height) / 2) << 2;
        else size = (u32)width * (u32)height;
        break;
    case 20:
    case 36:
    case 44:
        if (width < height && width <= 64) size = (u32)((s32)((u32)width * (u32)height) / 2) << 1;
        else {
            s32 ratio = width / height;
            if (ratio == 4) {
                size = (u32)((s32)((u32)width * (u32)height) / 2) << 1;
                break;
            }
            if (ratio == 8) size = (u32)((s32)((u32)width * (u32)height) / 2) << 2;
            else size = (s32)((u32)width * (u32)height) / 2;
            return size;
        }
        break;
    default:
        size = (u32)width * (u32)height;
    }
    return size;
}

signed int GetClutSize(signed int psm, signed int cpsm) {
    signed int size;
    switch (psm) {
    case 19:
    case 27:
        switch (cpsm) {
        case 0: size = 4; break;
        case 2: size = 2; break;
        case 10: size = 2; break;
        default: size = 0; break;
        }
        size <<= 8;
        break;
    case 20:
    case 36:
    case 44:
        switch (cpsm) {
        case 0: size = 4; break;
        case 2: size = 2; break;
        case 10: size = 2; break;
        default: size = 0; break;
        }
        size <<= 4;
        break;
    default: size = 0;
    }
    return size;
}

/* GetVramAddr @ 0x141510 .. 0x141560 (0x50 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int GetVramAddr(signed int a0 /* r4 */) {
    u8 *v1;
    u32 v0;

    v1 = (u8 *)lpVramMng;
    v0 = *(s32 *)(v1 + 4);
    v0 = v0 + (u32)(a0);
    *(u32 *)(v1 + 4) = (u32)(s32)a0 * (u32)((s32)(v0 + -1) / (s32)a0);
    v0 = lpVramMng;
    v0 = *(s32 *)((v0 + 4));
    v0 = v0 + (u32)(a0);
    v0 = v0 + -1;
    return (s32)v0 / (s32)a0;
}

/* SetNextVramAddr @ 0x1414F0 .. 0x141504 (0x14 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

void SetNextVramAddr(signed int a0 /* r4 */) {
    u32 *a1;
    u32 v1;

    a1 = (u32 *)lpVramMng;
    v1 = *(s32 *)(((u8 *)a1 + 4));
    *(u32 *)(((u8 *)a1 + 4)) = v1 + (u32)(a0);
    return;
}

u32 ResetVramAddr(void) {
    u32 *a0;
    u32 v1;

    a0 = (u32 *)lpVramMng;
    v1 = *(u32 *)a0;
    *(u32 *)(((u8 *)a0 + 4)) = v1;
    return;
}

u32 ClearZBuffer(void) {
    u8 *t4;
    u64 a0;
    u32 v1;
    u32 a2;
    u64 a1;

    t4 = (u8 *)lpMdlPacketMem;
    a0 = 0x10000004;
    v1 = 0x51000000;
    a2 = 0x51000000 | 4;
    v1 = 0x10030000;
    a1 = 0x10030000 | 0x4000;
    v1 = 0x30000;
    *(u32 *)t4 = 0x10000004;
    *(u32 *)(((u8 *)t4 + 4)) = 0;
    a0 = 0x30000 | 0x2001;
    *(u32 *)(((u8 *)t4 + 8)) = 0;
    v1 = 0x72000000;
    *(u32 *)(((u8 *)t4 + 0xc)) = a2;
    *(u32 *)(((u8 *)t4 + 0x10)) = 1;
    a2 = 4;
    *(u32 *)(((u8 *)t4 + 0x14)) = a1;
    *(u32 *)(((u8 *)t4 + 0x18)) = 0xe;
    a1 = 0x72000000 | 0x7000;
    *(u32 *)(((u8 *)t4 + 0x1c)) = 0;
    v1 = 0x8e00;
    *(u64 *)(((u8 *)t4 + 0x20)) = a0;
    v1 = (u64)0x8e00 << 0x10;
    *(u64 *)(((u8 *)t4 + 0x28)) = 0x47;
    a0 = v1 | 0x9000;
    *(u32 *)(((u8 *)t4 + 0x30)) = 2;
    v1 = (u32)((u8 *)t4 + 0x50);
    *(u32 *)(((u8 *)t4 + 0x34)) = 0x14000000;
    *(u32 *)(((u8 *)t4 + 0x38)) = 4;
    *(u32 *)(((u8 *)t4 + 0x3c)) = 0;
    *(u64 *)(((u8 *)t4 + 0x40)) = a1;
    *(u64 *)(((u8 *)t4 + 0x48)) = a0;
    lpMdlPacketMem = v1;
    return;
}
static u32 VramMngSt[0x8]; /* 0x20 B in the original .bss (the last 0x10 never referenced) */
u32 lpVramMng = (u32)&VramMngSt;
