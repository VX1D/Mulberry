#include "common.h"



extern void FlushCache(int);
u32 FsFont[0xdc/4];
u32 FontTexPacket[0x400/4];
static u32 DMABuf_811[8];
static u8 DMABuf_713[0x350];
extern signed int FsFontReplaceText(void *, void *, ...);
extern signed int FsFontDrawTextInRect(void *, unsigned short *, ...);
extern signed int FsFontDrawText(float, float, unsigned short *, ...);
extern u32 FontColor;
extern signed int FsFontSetColor(unsigned int);
extern signed int FsFontSetBaseColor(unsigned int);
extern u32 FontColorLast;
extern void * FsFontSetCurrent(void *);
extern void FsFont_SetDmaBuffer(void *, unsigned int);
extern void FsFontBegin();
extern signed int FsFontSetScale(float, float);
extern signed int FsFontSetBrightness(char);
u32 lpFontTm2[2] __attribute__((aligned(8)));
u32 lpFontCcm;
u32 lpFontDmaBuf[2];
u32 FontDmaBufSize;
u32 FontDmaID;
u32 FontDrawFlag;
u32 AutoPosX;
u32 AutoPosY;
u32 CurrentFont;
extern u8 GameSt[];
extern char * strcpy(char *, const char *);
extern void * memset(void *, int, unsigned int);
extern int sprintf(char *, const char *, ...);
extern void * GetTexMngByName(void *, char *);
extern unsigned int * MakeTexPacket(unsigned int *, void *);
void TransFontTex(void);
void FontPrintInRect(float f12 /* f12 */, float f13 /* f13 */, float f14 /* f14 */, float f15 /*
        f15 */, char *a0 /* r4 */, ...);
void FontPrintXY(float x, float y, char *lpFormat, ...);
u32 GetFontColor(u8 *a0 /* r4 */);
void SetLastFontColor(void);
void SetFontColorRGBA(unsigned int a0 /* r4 */);
void FontDrawBegin(int font);
static unsigned int * MakeFontTexPacket(unsigned int *a0 /* r4 */);



extern int FileRead(char *,int,unsigned char **,unsigned char,int,int,unsigned int);
extern void SetTm2Data(void *,void *,char *);
extern void ResetVramAddr();
extern int FsFontInit(void *);
extern void FsFont_SetMode(int,int);
extern unsigned int FsFont_GetDmaBufferSize(unsigned int,int);
extern void *MemAllocReal(unsigned int,char *,char *);
extern int FsFontSetCCMBuf(void *);
extern int FsFontSetTexBuf(int,void *);
extern void FsFontInitBugPath();
extern u32 lpFontCcm,lpFontTm2[2];
typedef struct FontTex0 { unsigned long long base:14,width:6,format:6,tw:4,th:4,color:1,func:2,palette:14,paletteFormat:4,paletteMode:1,paletteStart:5,paletteLoad:3; } FontTex0;
void FontInit(void) {
    u8 *data;
    u32 *packet;
    s32 i;
    u32 offset;
    u8 name[128] __attribute__((aligned(16)));
    u8 ccm[128] __attribute__((aligned(16)));
    u8 format[128] __attribute__((aligned(16)));
    packet=FontTexPacket;
    CurrentFont=0;
    strcpy((char *)ccm,"font/English/Font.ccm");
    strcpy((char *)format,"font/English/Font%.2d.tm2");
    FileRead((char *)ccm,-1,(u8 **)&(&lpFontCcm)[CurrentFont],1,-1,3,0);
    i=0; offset=0;
    do {
        memset(name,0,128);
        sprintf((char *)name,(char *)format,i);
        FileRead((char *)name,-1,(u8 **)((u8 *)lpFontTm2+CurrentFont*8+offset),1,-1,4,0);
        data=(u8 *)*(u32 *)((u8 *)lpFontTm2+CurrentFont*8+offset);
        if(i==0) ((FontTex0 *)(data+16))->format=44;
        else ((FontTex0 *)(data+16))->format=36;
        ((FontTex0 *)(data+16))->paletteLoad=1;
        SetTm2Data(0,data,(char *)name);
        ((FontTex0 *)(data+16))->base=0;
        if(i==0) ((FontTex0 *)(data+16))->palette=0x3ffc;
        else ((FontTex0 *)(data+16))->palette=0x3ffd;
        ++i; offset+=4;
    } while(i<2);
    ResetVramAddr(); MakeFontTexPacket(packet); TransFontTex();
    FsFontInit((u8 *)FsFont+CurrentFont*220);
    FsFont_SetMode(0,0); FsFont_SetMode(2,1); FsFont_SetMode(1,0); FsFont_SetMode(3,0);
    i=CurrentFont<<2;
    offset=(u32)&FontDmaBufSize+i;
    *(u32 *)offset=FsFont_GetDmaBufferSize(2048,0);
    *(u32 *)((u32)&FontDmaID+i)=0;
    {
        u32 amount=*(u32 *)offset;
        offset=CurrentFont;
        ((u32 (*)[2])lpFontDmaBuf)[offset][0]=(u32)MemAllocReal(amount,(char *)__FUNCTION__,"");
        amount=(&FontDmaBufSize)[offset];
        offset=CurrentFont;
        ((u32 (*)[2])((u32 *)lpFontDmaBuf+1))[offset][0]=(u32)MemAllocReal(amount,(char *)__FUNCTION__,"");
        FsFontSetCCMBuf((void *)(&lpFontCcm)[offset]);
    }
    offset=0; i=0;
    do {
        FsFontSetTexBuf(offset,(void *)*(u32 *)((u8 *)lpFontTm2+CurrentFont*8+i));
        ++offset; i+=4;
    } while((s32)offset<2);
    (&FontDrawFlag)[CurrentFont]=1;
    FsFontInitBugPath();
}










/* MakeFontTexPacket @ 0x177550 .. 0x177614 (0xc4 bytes, frame 0x130) */
/*
 * dcomp notes:
 *   literal: @984 is the string 'font/English/Font%.2d.tm2'
 *   literal: @985 is the string 'font/DbFont%.2d.tm2'
 *   stack: address of the slot at 0x30 escapes at 0x177574
 *   stack: address of the slot at 0x30 escapes at 0x177590
 *   stack: address of the slot at 0xb0 escapes at 0x1775a8
 *   stack: address of the slot at 0xb0 escapes at 0x1775b8
 *   stack: address of the slot at 0x30 escapes at 0x1775b8
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */


static unsigned int * MakeFontTexPacket(unsigned int *a0 /* r4 */) {
    u32 s1;
    u32 a1;
    s32 v1;
    s32 s0;
    u32 v0;
    u8 stackFrame_B0[128] __attribute__((aligned(16)));
    u8 stackFrame_30[128] __attribute__((aligned(16)));

    v0 = CurrentFont;
    s1 = (u32)a0;
    if (v0 == 0) {
        a1 = (u32)"font/English/Font%.2d.tm2";
        strcpy((char *)((u8 *)&stackFrame_30[0]), (const char *)"font/English/Font%.2d.tm2");
    } else {
        a1 = (u32)"font/DbFont%.2d.tm2";
        strcpy((char *)((u8 *)&stackFrame_30[0]), (const char *)"font/DbFont%.2d.tm2");
    }
    s0 = 0;
    do {
        memset((void *)((u8 *)&stackFrame_B0[0]), 0, 0x80);
        sprintf((char *)((u8 *)&stackFrame_B0[0]), (const char *)((u8 *)&stackFrame_30[0]),
            (u32)s0);
        v0 = (u32)GetTexMngByName((void *)0, (char *)((u8 *)&stackFrame_B0[0]));
        s1 = (u32)MakeTexPacket((unsigned int *)s1, (void *)v0);
        v1 = 0x60000000;
        s0 = s0 + 1;
    } while (s0 < (s32)2);
    v0 = s1 + 0x10;
    *(u32 *)s1 = v1;
    *(u32 *)(((u8 *)s1 + 4)) = 0;
    *(u32 *)(((u8 *)s1 + 8)) = 0;
    *(u32 *)(((u8 *)s1 + 0xc)) = 0;
    return (unsigned int *)v0;
}








void FontDrawBegin(int font) {
    CurrentFont = 0;
    if ((&FontDrawFlag)[CurrentFont] == 1) {
        FsFontSetCurrent(FsFont);
        (&FontDmaID)[CurrentFont] ^= 1;
        FsFont_SetDmaBuffer((void *)((u32 (*)[2])lpFontDmaBuf)[CurrentFont][(&FontDmaID)[CurrentFont]],
            (&FontDmaBufSize)[CurrentFont]);
        FsFontBegin();
        FsFontSetScale(0.666666687f, 0.666666687f);
        AutoPosX = 0x428c0000;
        AutoPosY = 0x41800000;
        FsFontSetBrightness(*(s8 *)(GameSt + 0x1e));
        (&FontDrawFlag)[CurrentFont] = 0;
    }
}







void FontDrawEnd(void) {
    u8 *s0;
    u32 v0;
    u32 v1;

    if ((&FontDrawFlag)[CurrentFont] == 0) {
        FsFontEnd();
        FlushCache(0);
        s0 = DMABuf_713;
        (&FontDrawFlag)[CurrentFont] = 1;
        if (FsFontGetSendTexFlag() != 0) {
            s0 = (u8 *)MakeTexPacket((u32 *)DMABuf_713,
                GetTexMngByName((void *)(u32)GetGameTexList(), "iconfont.tm2"));
            FsFontReSetSendTexFlag();
        }
        v0 = 0x50000000;
        *(u32 *)s0 = 0x50000000;
        *(u32 *)(s0 + 4) = *(u32 *)(((&FontDmaID)[CurrentFont] << 2) + (u32)&((u32 (*)[2])lpFontDmaBuf)[CurrentFont]);
        *(u32 *)(s0 + 8) = 0;
        *(u32 *)(s0 + 0xc) = 0;
        v0 = 0x70000000;
        *(u32 *)(s0 + 0x10) = 0x70000000;
        *(u32 *)(s0 + 0x14) = 0;
        *(u32 *)(s0 + 0x18) = 0;
        *(u32 *)(s0 + 0x1c) = 0;
        FlushCache(0);
        do {
            v1 = *(volatile s32 *)0x10009000;
            v1 = v1 & 0x100;
        } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
        *(volatile u32 *)0x10009020 = 0;
        *(volatile u32 *)0x10009010 = 0;
        *(volatile void **)0x10009030 = (void *)DMABuf_713;
        *(volatile u32 *)0x10009000 = 0x145;
        do {
            v1 = *(volatile s32 *)0x10009000;
            v1 = v1 & 0x100;
        } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    }
    return;
}







struct FontColorValue { u8 r, g, b, a; };

void SetFontColor(struct FontColorValue color) {
    u32 old = FontColor;
    FontColor = (u32)color.a << 24;
    FontColor += (u32)color.b << 16;
    FontColor += (u32)color.g << 8;
    FontColor += color.r;
    FontColorLast = old;
    FsFontSetColor(FontColor);
    FsFontSetBaseColor(FontColor);
}








/* SetFontColorRGBA @ 0x1771B0 .. 0x177274 (0xc4 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x1c escapes at 0x1771c4
 *   stack: 4-byte aggregate copy in 4-byte chunks at 0x177208
 */


void SetFontColorRGBA(unsigned int a0 /* r4 */) {
    u32 a2;
    u32 v0;
    u8 stackFrame_1C[4] __attribute__((aligned(4))) = {0};
    u8 stackFrame_18[4] __attribute__((aligned(8)));
    struct __copy_u32_1 { u32 b[1]; };

    ((u8 *)stackFrame_1C)[3] = a0;
    *(u8 *)((u8 *)&stackFrame_1C[0]) = (u32)a0 >> 0x18;
    ((u8 *)stackFrame_1C)[1] = (u32)a0 >> 0x10;
    ((u8 *)stackFrame_1C)[2] = (u32)a0 >> 8;
    v0 = (u32)((u8 *)&stackFrame_1C[0]);
    v0 = (u32)((u8 *)&stackFrame_18[0]);
    *(struct __copy_u32_1 *)((u8 *)&stackFrame_18[0]) = *(struct __copy_u32_1 *)((u8
        *)&stackFrame_1C[0]);
    a2 = FontColor;
    FontColor = (u32)((u8 *)stackFrame_18)[3] << 0x18;
    v0 = FontColor;
    FontColor = v0 + (u32)((u32)(unsigned int)((u8 *)stackFrame_18)[2] << 0x10);
    v0 = FontColor;
    FontColor = v0 + (u32)((unsigned int)(s32)((u32)((u8 *)stackFrame_18)[1] << 8));
    v0 = FontColor;
    FontColor = v0 + (u32)*(u8 *)((u8 *)&stackFrame_18[0]);
    a0 = FontColor;
    FontColorLast = a2;
    FsFontSetColor(a0);
    a0 = FontColor;
    FsFontSetBaseColor(a0);
    return;
}


/* SetLastFontColor @ 0x177180 .. 0x1771AC (0x2c bytes, frame 0x10) */


void SetLastFontColor(void) {
    u32 a0;
    u32 v0;

    v0 = FontColorLast;
    FontColor = (u32)v0;
    a0 = FontColor;
    FsFontSetColor(a0);
    a0 = FontColor;
    FsFontSetBaseColor(a0);
    return;
}


/* GetFontColor @ 0x177150 .. 0x177180 (0x30 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u32 GetFontColor(u8 *a0 /* r4 */) {
    u32 v1;

    v1 = FontColor;
    v1 = (u32)v1 >> 0x18;
    *(u8 *)(((u8 *)a0 + 3)) = v1;
    v1 = FontColor;
    v1 = (u32)v1 >> 0x10;
    *(u8 *)a0 = v1;
    v1 = FontColor;
    v1 = (u32)v1 >> 8;
    *(u8 *)(((u8 *)a0 + 1)) = v1;
    v1 = FontColor;
    *(u8 *)(((u8 *)a0 + 2)) = v1;
    return;
}















/* FontPrintXY @ 0x177080 .. 0x17714C (0xcc bytes, frame 0x390) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x177098 is a float copy
 *   fpu: mov.s at 0x1770cc is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x177100
 *   fpu: float literal 0x428c0000 at 0x177124
 *   fpu: mov.s at 0x17712c is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x177130
 */




void FontPrintXY(float x, float y, char *lpFormat, ...) {
    s32 a2;
    float f21;
    u32 a1;
    float f20;
    char *a0_value; // a0
    u32 v1;
    u32 v0;
    u8 stackFrame_20[768] __attribute__((aligned(16)));

    a0_value = lpFormat;
    v1 = (u32)&FontDrawFlag;
    f21 = (float)x;
    a0_value = (char *)CurrentFont;
    v1 = (s32)((u8 *)&FontDrawFlag + (u32)((char *)(s32)((u32)a0_value << 2)));
    v1 = *(s32 *)v1;
    f20 = (float)y;
    if (v1 == 0) {
        v1 = (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
        a1 = *(s32 *)((u8 *)&lpFormat);
        v0 = (u32)((u8 *)__builtin_next_arg(lpFormat));
        a2 = (s32)((u8 *)((u8 *)__builtin_next_arg(lpFormat)) - v1);
        if (a1 != 0) {
            FsFontReplaceText((void *)(char *)((u8 *)&stackFrame_20[0]), (void *)a1, a2);
            ((u8 *)stackFrame_20)[767] = 0;
            ((u8 *)stackFrame_20)[766] = 0;
        } else {
            *(u8 *)((u8 *)&stackFrame_20[0]) = 0;
        }
        FsFontDrawText((70.0f + f21), (float)f20, (unsigned short *)(char *)((u8
            *)&stackFrame_20[0]));
    }
    return;
}











/* FontPrintInRect @ 0x176F90 .. 0x177074 (0xe4 bytes, frame 0x3b0) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x10 escapes at 0x176fc4
 *   delay: addiu at 0x177008 writes a register its branch at 0x177004 reads
 *   stack: address of the slot at 0x20 escapes at 0x177038
 *   stack: address of the slot at 0x10 escapes at 0x17705c
 *   stack: address of the slot at 0x20 escapes at 0x17705c
 */


void FontPrintInRect(float f12 /* f12 */, float f13 /* f13 */, float f14 /* f14 */, float f15 /*
        f15 */, char *a0 /* r4 */, ...) {
    s32 a2;
    u32 a1;
    char *a0_value; // a0
    u32 v1;
    u32 v0;
    u8 stackFrame_20[768] __attribute__((aligned(16)));
    u8 stackFrame_10[16] __attribute__((aligned(16))) = {0};

    a0_value = a0;
    a0_value = (char *)CurrentFont;
    v1 = (u32)&FontDrawFlag;
    *(f32 *)((u8 *)&stackFrame_10[0]) = f12;
    ((f32 *)stackFrame_10)[1] = f13;
    ((f32 *)stackFrame_10)[2] = f14;
    ((f32 *)stackFrame_10)[3] = f15;
    v1 = (s32)((u8 *)&FontDrawFlag + (u32)((char *)(s32)((u32)a0_value << 2)));
    v1 = *(s32 *)v1;
    if (v1 == 0) {
        v1 = 1;
        v1 = (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
        a1 = *(s32 *)((u8 *)&a0);
        v0 = (u32)((u8 *)__builtin_next_arg(a0));
        a2 = (s32)((u8 *)((u8 *)__builtin_next_arg(a0)) - v1);
        if (a1 != 0) {
            FsFontReplaceText((void *)(char *)((u8 *)&stackFrame_20[0]), (void *)a1, a2);
            ((u8 *)stackFrame_20)[767] = 0;
            ((u8 *)stackFrame_20)[766] = 0;
        } else {
            *(u8 *)((u8 *)&stackFrame_20[0]) = 0;
        }
        FsFontDrawTextInRect((void *)(char *)((u8 *)&stackFrame_10[0]), (unsigned short *)((u8
            *)&stackFrame_20[0]));
    }
    return;
}





/* TransFontTex @ 0x176EA0 .. 0x176F90 (0xf0 bytes, frame 0x10) */


void TransFontTex(void) {
    u32 v1;
    u32 v0;

    DMABuf_811[2] = 0;
    v0 = 0x50000000;
    v1 = (u32)FontTexPacket;
    DMABuf_811[3] = 0;
    *(u32 *)DMABuf_811 = 0x50000000;
    v0 = 0x70000000;
    v0 = CurrentFont;
    v0 = (u32)v0 << 0xa;
    DMABuf_811[1] = (s32)((u8 *)FontTexPacket + v0);
    DMABuf_811[4] = 0x70000000;
    DMABuf_811[5] = 0;
    DMABuf_811[6] = 0;
    DMABuf_811[7] = 0;
    FlushCache(0);
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    *(volatile u32 *)0x10009020 = 0;
    *(volatile u32 *)0x10009010 = 0;
    *(volatile u32 *)0x10009030 = (u32)DMABuf_811;
    *(volatile u32 *)0x10009000 = 0x145;
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    return;
}


static u32 FontColor = 0x7f7f7f7f;
static u32 FontColorLast = 0x7f7f7f7f;
