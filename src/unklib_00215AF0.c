#include "common.h"


extern void * memset(void *, int, unsigned int);
static f32 sState[85];


/* MmoFontCharCheck_SJIS @ 0x215E60 .. 0x215EA8 (0x48 bytes) */
/*
 * dcomp notes:
 *   delay: andi at 0x215e7c writes a register its branch at 0x215e78 reads
 */

static f32 sState[85];

/* MmoFontDrawChar @ 0x215F50 .. 0x216308 (0x3b8 bytes, frame 0x60) */
static u32 sCurrentP;
struct dw_923053_fields_b726452d;
#ifndef PROTO_DW_920783_FIELDS_B726452D
#define PROTO_DW_920783_FIELDS_B726452D
struct dw_920783_fields_b726452d { unsigned char *pTex[16]; struct dw_923053_fields_b726452d *pCCM; unsigned int baseColor[4]; unsigned int color[4]; float italicParam; float spaceX[2]; float spaceY[2]; float scaleX[3]; float scaleY[3]; unsigned int reserved; unsigned char alignX : 2; unsigned char alignY : 2; unsigned char isRubyCenter : 1; unsigned char isDisableColor : 1; unsigned char dummy : 2; unsigned char dummy2[3]; char brightness; unsigned char piecePixel; unsigned short moveRange; unsigned char aGeneralBuffer[64]; };
#endif
#ifndef PROTO_DW_924860_FIELDS_B726452D
#define PROTO_DW_924860_FIELDS_B726452D
struct dw_924860_fields_b726452d { unsigned char isColor : 1; unsigned char isAlpha : 1; unsigned char isBold : 1; unsigned char isItalic : 1; unsigned char ruby : 2; unsigned char isInit : 1; unsigned char dummy : 1; };
#endif
#ifndef PROTO_DW_923722_FIELDS_B726452D
#define PROTO_DW_923722_FIELDS_B726452D
struct dw_923722_fields_b726452d { float left; float top; float right; float bottom; };
#endif
#ifndef PROTO_DW_922084_FIELDS_B726452D
#define PROTO_DW_922084_FIELDS_B726452D
struct dw_922084_fields_b726452d { float x; float y; float scaledHeight[2]; float nextHeight[2]; float saveX; float saveY; unsigned char tb[256]; float screenW; float screenH; unsigned long colorMask; struct dw_924860_fields_b726452d flag; unsigned char dummy[3]; struct dw_923722_fields_b726452d rect; void *charNextFP; void *charCheckFP; float lineHeight; int currentLine; int isBegin; float maxChar; unsigned char lastAlpha; char dummyCode; unsigned char dummy2[2]; };
#endif


u32 MmoFontFindGlyph(u16 a0);
extern void MmoFontDrawRect(s16, u8 *, s32, u8 *, float);
typedef struct {
    float uv[4];
    s16 w;
    s16 h;
    s16 pad;
    s16 tex;
} MMO_GLYPH;
#define MF_FL ((struct dw_924860_fields_b726452d *)((u8 *)(sState + 0x4b)))
#define MF_CUR ((struct dw_920783_fields_b726452d *)sCurrentP)

#define MS(i) (*(float *)((u32 *)sState + (i)))


static u32 sCurrentP;
struct dw_923053_fields_b726452d;
#ifndef PROTO_DW_920783_FIELDS_B726452D
#define PROTO_DW_920783_FIELDS_B726452D
struct dw_920783_fields_b726452d { unsigned char *pTex[16]; struct dw_923053_fields_b726452d *pCCM; unsigned int baseColor[4]; unsigned int color[4]; float italicParam; float spaceX[2]; float spaceY[2]; float scaleX[3]; float scaleY[3]; unsigned int reserved; unsigned char alignX : 2; unsigned char alignY : 2; unsigned char isRubyCenter : 1; unsigned char isDisableColor : 1; unsigned char dummy : 2; unsigned char dummy2[3]; char brightness; unsigned char piecePixel; unsigned short moveRange; unsigned char aGeneralBuffer[64]; };
#endif
#ifndef PROTO_DW_924860_FIELDS_B726452D
#define PROTO_DW_924860_FIELDS_B726452D
struct dw_924860_fields_b726452d { unsigned char isColor : 1; unsigned char isAlpha : 1; unsigned char isBold : 1; unsigned char isItalic : 1; unsigned char ruby : 2; unsigned char isInit : 1; unsigned char dummy : 1; };
#endif
#ifndef PROTO_DW_923722_FIELDS_B726452D
#define PROTO_DW_923722_FIELDS_B726452D
struct dw_923722_fields_b726452d { float left; float top; float right; float bottom; };
#endif
#ifndef PROTO_DW_922084_FIELDS_B726452D
#define PROTO_DW_922084_FIELDS_B726452D
struct dw_922084_fields_b726452d { float x; float y; float scaledHeight[2]; float nextHeight[2]; float saveX; float saveY; unsigned char tb[256]; float screenW; float screenH; unsigned long colorMask; struct dw_924860_fields_b726452d flag; unsigned char dummy[3]; struct dw_923722_fields_b726452d rect; void *charNextFP; void *charCheckFP; float lineHeight; int currentLine; int isBegin; float maxChar; unsigned char lastAlpha; char dummyCode; unsigned char dummy2[2]; };
#endif


extern signed int MmoFontOption(unsigned char **, unsigned char);
extern signed int MmoFontDrawChar(unsigned short, unsigned int);
#define DT_SF(i) (*(float *)(sState + (i)))
#define DT_SU(i) (*(u32 *)(sState + (i)))
#define DT_FL ((struct dw_924860_fields_b726452d *)((u8 *)(sState + 0x4b)))
#define DT_CUR ((struct dw_920783_fields_b726452d *)sCurrentP)
#undef pRect


/* MmoFsFontDrawText @ 0x216660 .. 0x2168B4 (0x254 bytes, frame 0x530) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x21667c is a float copy
 *   fpu: mov.s at 0x216684 is a float copy
 *   delay: lui at 0x216728 writes a register its branch at 0x216724 reads
 *   fpu: mtc1 reinterprets v0 at 0x216784
 *   fpu: mtc1 reinterprets v0 at 0x2167c8
 *   fpu: mov.s at 0x2167fc is a float copy
 *   call: MmoFontGetLineSize is declared void but its v0 is read: called as returning u32
 *   fpu: mov.s at 0x216878 is a float copy
 *   fpu: mov.s at 0x21687c is a float copy
 *   stack: address of the slot at 0x4a0 escapes at 0x216888
 *   stack: address of the slot at 0x4a0 escapes at 0x216898
 *   stack: address of the slot at 0xa0 escapes at 0x216898
 *   stack: address of the slot at 0x20 escapes at 0x216898
 *   cfg: kept branch: 0x21681c if (..) goto .L00216868
 *   return without a value in a non-void function
 */

extern signed int MmoFontReplaceUnicode(void *, void *, char *);
extern int vsprintf(char *, const char *, void *);
extern signed int MmoFontGetLineSize(float *, float *, u8 *, u8 *, u32, u32, u32);
extern void MmoFsFontSetRect(u8 *, float, float, float, float);
extern signed int MmoFontDrawTextInRect(u8 *, u8 *, u8 *);
static u32 sCurrentP;

static inline signed int MmoReplaceTextInl(void *a0, void *a1, char *ap) {
    u32 r;
    r = *(u8 *)(*(s32 *)(sCurrentP + 0x40) + 0x1c);
    if (r != 0) {
        r = MmoFontReplaceUnicode(a0, a1, ap);
    } else {
        r = vsprintf((char *)a0, (const char *)a1, ap);
        if ((s32)r < 0) {
            r = -9;
        }
    }
    return r;
}


/* MmoFontOption @ 0x2168C0 .. 0x217180 (0x8c0 bytes, frame 0x90) */

#define FO_MASK DT_SU(0x4a)

static inline int MmoFoIsDigit(u32 d) {
    return (d & 0x10) == 0;
}

static inline int MmoFoHex2(unsigned char *p, u32 *out) {
    int n;
    u32 acc;
    u32 d;
    int ok;
    unsigned short c;

    acc = 0;
    n = 0;
    do {
        c = ((unsigned short (*)(unsigned char **))DT_SU(0x50))(&p);
        d = ((u8 *)sState + c)[0x20];
        ok = (d & 0x10) ? 0 : 1;
        if (ok == 0) {
            return -6;
        }
        acc = acc << 4;
        n++;
        acc = acc + (d & 0xf);
    } while (n < 2);
    *out = acc;
    return 0;
}

static inline void MmoFoSkip(unsigned char **pp) {
    unsigned char *q;
    unsigned int r;

    q = *pp;
    do {
        r = ((unsigned int (*)(unsigned char **))DT_SU(0x50))(&q);
        r = (unsigned short)r;
        if (r == 0) {
            break;
        }
    } while ((unsigned short)r != ']');
    *pp = q;
}


/* MmoFontGetLineSize @ 0x217180 .. 0x2175E4 (0x464 bytes, frame 0xc0) */


#ifndef PROTO_DW_920783_FIELDS_B726452D
#define PROTO_DW_920783_FIELDS_B726452D

#endif
#ifndef PROTO_DW_924860_FIELDS_B726452D
#define PROTO_DW_924860_FIELDS_B726452D

#endif
#ifndef PROTO_DW_923722_FIELDS_B726452D
#define PROTO_DW_923722_FIELDS_B726452D

#endif
#ifndef PROTO_DW_922084_FIELDS_B726452D
#define PROTO_DW_922084_FIELDS_B726452D

#endif




#define DT_SF(i) (*(float *)(sState + (i)))
#define DT_SU(i) (*(u32 *)(sState + (i)))
#define DT_FL ((struct dw_924860_fields_b726452d *)((u8 *)(sState + 0x4b)))
#define DT_CUR ((struct dw_920783_fields_b726452d *)sCurrentP)


struct FlGlyph { u8 pad[0x10]; short w1; short pad2; short w2; };
struct FlFlag { unsigned char isColor : 1; unsigned char isAlpha : 1; unsigned char isBold : 1; unsigned char isItalic : 1; unsigned char ruby : 2; unsigned char isInit : 1; unsigned char dummy : 1; };
#define FL_FLAG ((struct FlFlag *)((u8 *)(sState + 0x4b)))


/* MmoFsFontGetSize @ 0x2175F0 .. 0x21760C (0x1c bytes) */
/*
 * dcomp notes:
 *   tail: j MmoFontGetLineSize at 0x217604 leaves the function
 *   a0 forwarded to MmoFontGetLineSize
 *   a1 forwarded to MmoFontGetLineSize
 */

extern signed int MmoFontGetLineSize(float *, float *, u8 *, u8 *, u32, u32, u32);

/* MmoFsFontGetPos @ 0x217610 .. 0x217630 (0x20 bytes) */

static f32 sState[85];

static u32 sCurrentP;
typedef struct FontAlignBits { unsigned char h:2; unsigned char v:2; unsigned char flag:1; unsigned char pad:3; } FontAlignBits;


/* MmoFsFontSetMargin @ 0x2176B0 .. 0x2176C8 (0x18 bytes) */

static u32 sCurrentP;

/* MmoFsFontSetBaseColor @ 0x2176D0 .. 0x2176F8 (0x28 bytes) */

static u32 sCurrentP;


/* MmoFsFontSetTexBuf @ 0x2177C0 .. 0x2177D8 (0x18 bytes) */

static u32 sCurrentP;

/* MmoFsFontSetCurrent @ 0x217860 .. 0x21788C (0x2c bytes, frame 0x20) */

extern void MmoFontSetRefCurrentPtr(u32);
static u32 sCurrentP;

extern void MmoFontSetRefStatePtr(u32);



 

static inline void FontSetAlign(s32 alignment) {
    s32 h, v, flag;
    h = (alignment & 0x30) >> 4;
    v = (alignment & 0xc0) >> 6;
    flag = (alignment & 0x100) >> 8;
    ((FontAlignBits *)(sCurrentP + 0x94))->h = h;
    ((FontAlignBits *)(sCurrentP + 0x94))->v = v;
    ((FontAlignBits *)(sCurrentP + 0x94))->flag = flag;
}
typedef struct StateBits { unsigned char a:6; unsigned char f:1; unsigned char b:1; } StateBits;
static inline void FontSetColor0(u32 c) {
    *(u32 *)(sCurrentP + 0x44) = c;
    *(u32 *)(sCurrentP + 0x48) = c;
    *(u32 *)(sCurrentP + 0x4c) = c;
    *(u32 *)(sCurrentP + 0x50) = c;
}
static inline void FontSetColor1(u32 c) {
    *(u32 *)(sCurrentP + 0x54) = c;
    *(u32 *)(sCurrentP + 0x58) = c;
    *(u32 *)(sCurrentP + 0x5c) = c;
    *(u32 *)(sCurrentP + 0x60) = c;
}
static inline void FontSetScale(float s) {
    *(f32 *)(sCurrentP + 0x78) = s;
    *(f32 *)(sCurrentP + 0x84) = s;
    *(f32 *)(sCurrentP + 0x7c) = s * *(f32 *)(sCurrentP + 0x80);
    *(f32 *)(sCurrentP + 0x88) = s * *(f32 *)(sCurrentP + 0x8c);
}
static inline void FontSetSkew(float t) {
    *(f32 *)(sCurrentP + 0x80) = 0;
    *(f32 *)(sCurrentP + 0x8c) = 0;
    *(f32 *)(sCurrentP + 0x7c) = *(f32 *)(sCurrentP + 0x78) * t;
    *(f32 *)(sCurrentP + 0x88) = *(f32 *)(sCurrentP + 0x84) * t;
}


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 MmoFsFontInit(u8 *a0 );
u32 MmoFsFontSetCurrent(u8 *a0 );
u32 MmoFsFontSetCCMBuf(s32 a0 );
u32 MmoFsFontSetTexBuf(u8 *a0 , u8 *a1 );
u32 MmoFontFindGlyph(u16 a0);
u32 MmoFsFontSetBaseColor(s32 a0 );
u32 MmoFsFontSetMargin(float f12 , float f13 );
u32 MmoFsFontSetAlignment(s32 alignment);
u32 MmoFsFontGetPos(float *a0 , float *a1 );
void MmoFsFontGetSize(u8 *a0 , float *a1 , u8 *a2 , u32 a3 );
signed int MmoFontGetLineSize(float *pWidth, float *pHeight, u8 *pLineU, u8 *str, u32 lastCode, u32 nextCode, u32 pRectU);
signed int MmoFontOption(unsigned char **pStr, unsigned char isSizeCheck);
int MmoFsFontDrawText(float x, float y, char *fmt, ...);
signed int MmoFontDrawTextInRect(u8 *a0, u8 *str, u8 *lineWidthAry0);
signed int MmoFontDrawChar(unsigned short code, unsigned int isLast);
u32 MmoFontCharNext_UTF16(u32 *a0 );
u16 MmoFontCharNext_SJIS(u32 *a0);
u16 MmoFontCharCheck_UTF16(u16 *a0 );
u16 MmoFontCharCheck_SJIS(u8 *a0 );
void MmoFontInitTable(void);
u32 MmoFsCConvUTF16To8(u8 *output,u16 *input);
int MmoFsCConvUTF8To16(u16 *dst, u8 *src);


u32 MmoFsFontInit(u8 *a0 /* r4 */) {
    memset(a0, 0, 0xd8);
    sCurrentP = (u32)a0;
    MmoFontSetRefCurrentPtr((u32)a0);
    FontSetColor0(0x7f7f7f7f);
    FontSetColor1(0x7f7f7f7f);
    FontSetScale(1.0f);
    FontSetSkew(0.0f);
    *(u32 *)(sCurrentP + 0x64) = 0x40400000;
    FontSetAlign(0x100);
    if (!((StateBits *)((u8 *)(sState + 0x4b)))->f) {
        u8 color[4];
        MmoFontInitTable();
        ((StateBits *)((u8 *)(sState + 0x4b)))->f = 1;
        sState[0x48] = 640.0f;
        sState[0x49] = 448.0f;
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = 0;
        *(u32 *)(sState + 0x4a) = *(u32 *)color;
        MmoFontSetRefStatePtr((u32)sState);
    }
    return 0;
}

u32 MmoFsFontSetCurrent(u8 *a0 /* r4 */) {
    u32 s0;

    s0 = sCurrentP;
    sCurrentP = (u32)a0;
    MmoFontSetRefCurrentPtr((u32)a0);
    return s0;
}

/* MmoFsFontSetCCMBuf @ 0x2177E0 .. 0x217854 (0x74 bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v1 at 0x217824
 *   fpu: mtc1 reinterprets v1 at 0x217840
 */

u32 MmoFsFontSetCCMBuf(s32 a0 /* r4 */) {
    u32 v1;
    u32 v0;

    v1 = sCurrentP;
    v0 = 0;
    *(u32 *)((v1 + 0x40)) = a0;
    v1 = sCurrentP;
    a0 = *(s32 *)((v1 + 0x40));
    v1 = *(s32 *)((a0 + 0x14));
    *(u32 *)((a0 + 0x14)) = a0 + v1;
    v1 = sCurrentP;
    a0 = *(s32 *)((v1 + 0x40));
    v1 = *(s32 *)((a0 + 0x18));
    *(u32 *)((a0 + 0x18)) = a0 + v1;
    a0 = sCurrentP;
    v1 = *(s32 *)((a0 + 0x40));
    v1 = *(s16 *)((v1 + 8));
    sState[4] = (float)((float)(s32)v1);
    v1 = *(s32 *)((a0 + 0x40));
    v1 = *(s16 *)((v1 + 8));
    sState[2] = (float)((float)(s32)v1);
    return v0;
}

u32 MmoFsFontSetTexBuf(u8 *a0 /* r4 */, u8 *a1 /* r5 */) {
    u32 v1;
    u32 v0;

    v1 = sCurrentP;
    a0 = (u8 *)(s32)((u32)a0 << 2);
    v0 = 0;
    v1 = (s32)((u8 *)v1 + (u32)(a0));
    *(u32 *)v1 = (u32)a1;
    return v0;
}

u32 MmoFontFindGlyph(u16 a0) {
    u32 t1;
    u32 t0;
    s32 lo;
    s32 hi;
    s32 mid;
    u32 c;
    u32 p;
    u32 v0;

    v0 = *(s32 *)((sCurrentP + 0x40));
    t1 = *(s32 *)((v0 + 0x18));
    t0 = *(s32 *)((v0 + 0x14));
    hi = *(s16 *)((v0 + 0x10)) - 1;
    lo = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        p = t0 + mid * 0xc;
        if (*(u32 *)(p + 4) < a0) {
            lo = mid + 1;
        } else if (a0 < *(u32 *)p) {
            hi = mid - 1;
        } else {
            return t1 + (*(s32 *)(p + 8) + (s32)(a0 - *(u32 *)p)) * 0x18;
        }
    }
    return 0;
}

u32 MmoFsFontSetBaseColor(s32 a0 /* r4 */) {
    u32 *v1;
    u32 v0;

    v1 = (u32 *)sCurrentP;
    v0 = 0;
    *(u32 *)(((u8 *)v1 + 0x44)) = a0;
    v1 = (u32 *)sCurrentP;
    *(u32 *)(((u8 *)v1 + 0x48)) = a0;
    v1 = (u32 *)sCurrentP;
    *(u32 *)(((u8 *)v1 + 0x4c)) = a0;
    v1 = (u32 *)sCurrentP;
    *(u32 *)(((u8 *)v1 + 0x50)) = a0;
    return v0;
}

u32 MmoFsFontSetMargin(float f12 /* f12 */, float f13 /* f13 */) {
    float *v1;
    u32 v0;

    v1 = (float *)sCurrentP;
    v0 = 0;
    *(f32 *)(((u8 *)v1 + 0x68)) = (float)f12;
    v1 = (float *)sCurrentP;
    *(f32 *)(((u8 *)v1 + 0x70)) = (float)f13;
    return v0;
}
u32 MmoFsFontSetAlignment(s32 alignment) {
    s32 h, v, flag;
    h = (alignment & 0x30) >> 4;
    v = (alignment & 0xc0) >> 6;
    flag = (alignment & 0x100) >> 8;
    ((FontAlignBits *)(sCurrentP + 0x94))->h = h;
    ((FontAlignBits *)(sCurrentP + 0x94))->v = v;
    ((FontAlignBits *)(sCurrentP + 0x94))->flag = flag;
    return 0;
}

u32 MmoFsFontGetPos(float *a0 /* r4 */, float *a1 /* r5 */) {
    u32 v0;
    float f0;

    v0 = 0;
    f0 = *(float *)sState;
    *(f32 *)a0 = f0;
    f0 = *(float *)(sState + 1);
    *(f32 *)a1 = f0;
    return v0;
}

/* MmoFsFontGetSize @ 0x2175F0 .. 0x21760C (0x1c bytes) */
/*
 * dcomp notes:
 *   tail: j MmoFontGetLineSize at 0x217604 leaves the function
 *   a0 forwarded to MmoFontGetLineSize
 *   a1 forwarded to MmoFontGetLineSize
 */
void MmoFsFontGetSize(u8 *a0 /* r4 */, float *a1 /* r5 */, u8 *a2 /* r6 */, u32 a3 /* r7 */) {
    MmoFontGetLineSize((float *)a0, a1, (u8 *)0, (u8 *)a2, a3, 0, 0);
    return;
}

signed int MmoFontGetLineSize(float *pWidth, float *pHeight, u8 *pLineU, u8 *str, u32 lastCode, u32 nextCode, u32 pRectU) {
    float *pLine = (float *)pLineU;
    float *pRect = (float *)pRectU;
    u8 *cur;
    s32 *pf;
    unsigned char *p;
    unsigned short code;
    unsigned short next;
    float x;
    float italic;
    float charWidth;
    float *pScale;
    float spaceX;
    struct FlGlyph *pGlyph;
    int isRuby;
    int ret;
    unsigned short lc;
    unsigned short nc;

    x = 0.0f;
    spaceX = x;
    cur = (u8 *)sCurrentP;
    italic = ((struct dw_920783_fields_b726452d *)cur)->scaleX[0] * (((struct dw_920783_fields_b726452d *)cur)->italicParam * (float)(unsigned int)FL_FLAG->isItalic);
    p = str;
    pf = (s32 *)(cur + 0x40);
    if (*(u8 *)(*pf + 0x1c) == 1) {
        DT_SU(0x50) = (u32)MmoFontCharNext_UTF16;
        DT_SU(0x51) = (u32)MmoFontCharCheck_UTF16;
    } else {
        DT_SU(0x50) = (u32)MmoFontCharNext_SJIS;
        DT_SU(0x51) = (u32)MmoFontCharCheck_SJIS;
    }
    lc = lastCode;
    nc = nextCode;
    DT_SF(2) = (float)*(s16 *)(*pf + 8) * DT_CUR->scaleY[0];
    DT_SF(4) = DT_SF(2) + DT_CUR->spaceY[0];
    DT_SF(3) = (float)*(s16 *)(*pf + 8) * DT_CUR->scaleY[1];
    DT_SF(5) = DT_SF(3) + DT_CUR->spaceY[1];
    DT_SU(0x53) = 0;
    DT_SF(0x52) = DT_SF(4) + DT_SF(5);
    *pWidth = 0.0f;
    *pHeight = DT_SF(0x52);
    while (1) {
        code = ((unsigned short (*)(unsigned char **))DT_SU(0x50))(&p);
        next = ((unsigned short (*)(unsigned char *))DT_SU(0x51))(p);
        if (code == lc) {
            if (nextCode == 0 || next == nc) {
                x = x - spaceX;
                if (!(x <= *pWidth)) {
                    *pWidth = x;
                }
                *pWidth = *pWidth + italic;
                if (pLine != 0) {
                    *pLine = x;
                }
                return p - str;
            }
        }
        switch (code) {
        case '\n':
            x = x - spaceX;
            if (!(x <= *pWidth)) {
                *pWidth = x;
            }
            if (pLine != 0) {
                *pLine = x;
                pLine++;
            }
            x = 0.0f;
            *pHeight = *pHeight + DT_SF(0x52);
            continue;
        case '#':
            if (next != '#') {
                ret = MmoFontOption(&p, 0);
                if (ret >= 0) {
                    continue;
                }
                return ret;
            }
            ((unsigned short (*)(unsigned char **))DT_SU(0x50))(&p);
        default:
            pGlyph = (struct FlGlyph *)MmoFontFindGlyph(code);
            if (pGlyph == 0) {
                return -4;
            }
            isRuby = FL_FLAG->ruby == 2;
            pScale = (float *)((u8 *)sCurrentP + (isRuby * 4) + 0x78);
            charWidth = (float)(unsigned int)FL_FLAG->isBold + *pScale * (float)(pGlyph->w1 + pGlyph->w2);
            break;
        }
        if (pRect != 0) {
            if (!(x + charWidth <= pRect[2])) {
                if (DT_CUR->alignX != 0) {
                    return -8;
                }
                x = x - spaceX;
                if (!(x <= *pWidth)) {
                    *pWidth = x;
                }
                if (pLine != 0) {
                    *pLine = x;
                    pLine++;
                }
                x = pRect[0];
                *pHeight = *pHeight + DT_SF(0x52);
                if (!(DT_SF(1) + DT_SF(0x52) <= DT_SF(0x4f))) {
                    return -8;
                }
            }
        }
        spaceX = DT_CUR->spaceX[isRuby];
        x = x + (charWidth + spaceX);
    }
}

signed int MmoFontOption(unsigned char **pStr, unsigned char isSizeCheck) {
    int k;
    int ret;
    unsigned int value;
    unsigned short code;
    union {
        unsigned char c[4];
        unsigned int color;
    } clr;
    float dummy;
    float rubyW;
    float textW;
    struct dw_924860_fields_b726452d saveFlag;
    u32 m;
    u32 nm;

    k = *(u8 *)(*(u32 *)(sCurrentP + 0x40) + 0x1c) + 1;
    code = ((unsigned short (*)(unsigned char **, unsigned char))DT_SU(0x50))(pStr, isSizeCheck);
    switch (code) {
    case 'c':
        if (DT_FL->isColor) {
            DT_CUR->color[0] = (DT_CUR->baseColor[0] & FO_MASK) + (DT_CUR->color[0] & ~FO_MASK);
            DT_CUR->color[1] = (DT_CUR->baseColor[1] & FO_MASK) + (DT_CUR->color[1] & ~FO_MASK);
            DT_CUR->color[2] = (DT_CUR->baseColor[2] & FO_MASK) + (DT_CUR->color[2] & ~FO_MASK);
            DT_CUR->color[3] = (DT_CUR->baseColor[3] & FO_MASK) + (DT_CUR->color[3] & ~FO_MASK);
        } else {
            *pStr += k;
            ret = MmoFoHex2(*pStr, &value);
            if (ret < 0) {
                return ret;
            }
            clr.c[0] = value;
            k = k << 1;
            *pStr += k;
            ret = MmoFoHex2(*pStr, &value);
            if (ret < 0) {
                return ret;
            }
            clr.c[1] = value;
            *pStr += k;
            ret = MmoFoHex2(*pStr, &value);
            if (ret < 0) {
                return ret;
            }
            clr.c[2] = value;
            *pStr += k;
            clr.c[3] = 0;
            m = DT_SU(0x4a);
            DT_CUR->color[0] = (DT_CUR->color[0] & ~m) + (clr.color & m);
            DT_CUR->color[1] = (DT_CUR->color[1] & ~m) + (clr.color & m);
            DT_CUR->color[2] = (DT_CUR->color[2] & ~m) + (clr.color & m);
            DT_CUR->color[3] = (DT_CUR->color[3] & ~m) + (clr.color & m);
            MmoFoSkip(pStr);
        }
        DT_FL->isColor = !DT_FL->isColor;
        break;
    case 'a':
        if (DT_FL->isAlpha) {
            DT_CUR->color[0] = (DT_CUR->baseColor[0] & ~FO_MASK) + (DT_CUR->color[0] & FO_MASK);
            DT_CUR->color[1] = (DT_CUR->baseColor[1] & ~FO_MASK) + (DT_CUR->color[1] & FO_MASK);
            DT_CUR->color[2] = (DT_CUR->baseColor[2] & ~FO_MASK) + (DT_CUR->color[2] & FO_MASK);
            DT_CUR->color[3] = (DT_CUR->baseColor[3] & ~FO_MASK) + (DT_CUR->color[3] & FO_MASK);
        } else {
            *pStr += k;
            clr.color = 0;
            ret = MmoFoHex2(*pStr, &value);
            if (ret < 0) {
                return ret;
            }
            clr.c[3] = value;
            nm = ~FO_MASK;
            DT_CUR->color[0] = (DT_CUR->color[0] & ~nm) + (clr.color & nm);
            DT_CUR->color[1] = (DT_CUR->color[1] & ~nm) + (clr.color & nm);
            DT_CUR->color[2] = (DT_CUR->color[2] & ~nm) + (clr.color & nm);
            DT_CUR->color[3] = (DT_CUR->color[3] & ~nm) + (clr.color & nm);
            MmoFoSkip(pStr);
        }
        DT_FL->isAlpha = !DT_FL->isAlpha;
        break;
    case 'b':
        DT_FL->isBold = !DT_FL->isBold;
        break;
    case 'i':
        DT_FL->isItalic = !DT_FL->isItalic;
        break;
    case 'r':
        if (DT_FL->ruby == 0) {
            DT_FL->ruby = 2;
            *pStr += k;
            if (isSizeCheck) {
                u32 c0, c1, c2, c3;
                DT_SF(6) = DT_SF(0);
                ret = MmoFontGetLineSize(&rubyW, &dummy, 0, *pStr, ']', 0, 0);
                if (ret < 0) {
                    return ret;
                }
                saveFlag = *DT_FL;
                c0 = DT_CUR->color[0];
                c1 = DT_CUR->color[1];
                c2 = DT_CUR->color[2];
                c3 = DT_CUR->color[3];
                DT_FL->ruby = 0;
                ret = MmoFontGetLineSize(&textW, &dummy, 0, *pStr + ret, '#', 'r', 0);
                if (ret < 0) {
                    return ret;
                }
                DT_CUR->color[0] = c0;
                DT_CUR->color[1] = c1;
                DT_CUR->color[2] = c2;
                DT_CUR->color[3] = c3;
                *DT_FL = saveFlag;
                if (DT_CUR->isRubyCenter) {
                    DT_SF(0) = DT_SF(0) + (textW - rubyW) / 2.0f;
                }
                break;
            }
            MmoFoSkip(pStr);
            DT_FL->ruby = 1;
        } else {
            DT_FL->ruby = 0;
        }
        break;
    default:
        return -3;
    }
    return 0;
}
int MmoFsFontDrawText(float x, float y, char *fmt, ...) {
    char *ap;
    u32 r;
    s32 *pf;
    float w, h;
    u8 rect[24];
    char buf[1024];
    u8 work[128];

    ap = (char *)__builtin_next_arg(fmt) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    r = *(u8 *)(*(s32 *)(sCurrentP + 0x40) + 0x1c);
    if (r != 0) {
        r = MmoFontReplaceUnicode(buf, fmt, ap);
    } else {
        r = vsprintf(buf, fmt, ap);
        if ((s32)r < 0) {
            r = -9;
        }
    }
    if ((s32)r < 0) {
        return r;
    }
    pf = (s32 *)(sCurrentP + 0x40);
    if (*(u8 *)(*pf + 0x1c) == 1) {
        *(void **)(sState + 0x50) = (void *)MmoFontCharNext_UTF16;
        *(void **)(sState + 0x51) = (void *)MmoFontCharCheck_UTF16;
    } else {
        *(void **)(sState + 0x50) = (void *)MmoFontCharNext_SJIS;
        *(void **)(sState + 0x51) = (void *)MmoFontCharCheck_SJIS;
    }
    sState[2] = (float)*(s16 *)(*pf + 8) * *(float *)(sCurrentP + 0x84);
    sState[4] = sState[2] + *(float *)(sCurrentP + 0x70);
    sState[3] = (float)*(s16 *)(*pf + 8) * *(float *)(sCurrentP + 0x88);
    sState[5] = sState[3] + *(float *)(sCurrentP + 0x74);
    *(u32 *)(sState + 0x53) = 0;
    sState[0x52] = sState[4] + sState[5];
    r = *(u8 *)(sCurrentP + 0x94) & 3;
    if (r != 0) {
        r = MmoFontGetLineSize(&w, &h, work, (u8 *)buf, 0, 0, 0);
        if ((s32)r < 0) {
            return r;
        }
    } else {
        w = sState[0x48];
        h = sState[0x49];
    }
    sState[1] = y;
    MmoFsFontSetRect(rect, x, y, x + w, y + h);
    MmoFontDrawTextInRect(rect, (u8 *)buf, work);
}

signed int MmoFontDrawTextInRect(u8 *a0, u8 *str, u8 *lineWidthAry0) {
#define pRect ((struct dw_923722_fields_b726452d *)a0)
    unsigned char *p;
    unsigned short code;
    unsigned int c;
    int ret;
    int saveRet;

    p = str;
    *(struct dw_923722_fields_b726452d *)(sState + 0x4c) = *pRect;
    DT_SF(0) = DT_CUR->alignX != 0 ? pRect->left - ((float *)lineWidthAry0)[DT_SU(0x53)] / (float)DT_CUR->alignX : pRect->left;
    DT_FL->isColor = 0;
    DT_FL->isBold = 0;
    DT_FL->isItalic = 0;
    DT_CUR->color[0] = DT_CUR->baseColor[0];
    DT_CUR->color[1] = DT_CUR->baseColor[1];
    DT_CUR->color[2] = DT_CUR->baseColor[2];
    DT_CUR->color[3] = DT_CUR->baseColor[3];
    saveRet = 0;
    for (;;) {
        code = ((unsigned short (*)(unsigned char **))DT_SU(0x50))(&p);
        if (code != 0) {
            c = code & 0xffff;
            if (c == ']' && DT_FL->ruby == 2) {
                DT_FL->ruby = 1;
                DT_SF(0) = DT_SF(6);
                continue;
            }
            switch (c) {
            case '\r':
                continue;
            case '\n':
                DT_SU(0x53)++;
                DT_SF(0) = DT_CUR->alignX != 0 ? pRect->left - ((float *)lineWidthAry0)[DT_SU(0x53)] / (float)DT_CUR->alignX : pRect->left;
                DT_SF(1) = DT_SF(1) + DT_SF(0x52);
                if (DT_SF(1) + DT_SF(0x52) <= DT_SF(0x4f)) {
                    continue;
                }
                return -8;
            case '#':
                if (((unsigned short (*)(unsigned char *))DT_SU(0x51))(p) != '#') {
                    ret = MmoFontOption(&p, 1);
                    if (ret >= 0) {
                        continue;
                    }
                    return ret;
                }
                ((unsigned short (*)(unsigned char **))DT_SU(0x50))(&p);
                break;
            }
            ret = MmoFontDrawChar(code, (unsigned int)lineWidthAry0);
            if (ret == -4) {
                saveRet = -4;
                continue;
            }
            if (ret >= 0) {
                continue;
            }
            return ret;
        } else {
            return saveRet;
        }
    }
}
signed int MmoFontDrawChar(unsigned short code, unsigned int isLast) {
    MMO_GLYPH *g;
    float pos[4];
    float uv[4];
    float *pScale;
    float italic;
    int isRuby;

    g = (MMO_GLYPH *)MmoFontFindGlyph(code);
    if (g == 0) {
        return -4;
    }
    uv[0] = g->uv[0];
    uv[1] = g->uv[1];
    uv[2] = g->uv[2];
    uv[3] = g->uv[3];
    isRuby = MF_FL->ruby == 2;
    pScale = (float *)((u8 *)(isRuby * 4) + sCurrentP + 0x78);
    italic = *pScale * (MF_CUR->italicParam * (float)MF_FL->isItalic);
    if (!(sState[0] + ((float)MF_FL->isBold + *pScale * (float)(g->w + g->pad)) <= sState[0x4e])) {
        if (MF_CUR->alignX != 0) {
            return -8;
        }
        sState[0] = sState[0x4c];
        sState[1] = sState[1] + sState[0x52];
        if (!(sState[1] + sState[0x52] <= sState[0x4f])) {
            return -8;
        }
    }
    MS(0) = sState[0] + (float)g->w * *pScale;
    if (MF_FL->ruby == 2) {
        float px = sState[0] - 0.0625f;
        float py = sState[1] - 0.0625f;
        pos[0] = px;
        pos[1] = py;
        pos[2] = px + (float)g->h * *pScale;
        pos[3] = py + sState[5];
    } else {
        float px = sState[0] - 0.0625f;
        float h = sState[5];
        float py = sState[1] - 0.0625f;
        pos[0] = px;
        pos[1] = py + h;
        pos[2] = px + (float)g->h * *pScale;
        pos[3] = h + (py + sState[2]);
    }
    sState[0] = sState[0] + ((float)MF_FL->isBold + (*(float *)((u8 *)(isRuby * 4) + sCurrentP + 0x68) + (float)g->pad * *pScale));
    MmoFontDrawRect(g->tex, (u8 *)pos, (s32)((u8 *)sCurrentP + 0x54), (u8 *)uv, italic);
    if (MF_FL->isBold) {
        pos[0] = pos[0] + 1.0f;
        pos[2] = pos[2] + 1.0f;
        MmoFontDrawRect(g->tex, (u8 *)pos, (s32)((u8 *)sCurrentP + 0x54), (u8 *)uv, italic);
    }
    return 0;
}


/* MmoFontCharNext_UTF16 @ 0x215F30 .. 0x215F44 (0x14 bytes) */
/*
 * dcomp notes:
 *   v1 is the pointer held in a0+0x0
 */

u32 MmoFontCharNext_UTF16(u32 *a0 /* r4 */) {
    u16 *v1;
    u16 v0;

    v1 = (u16 *)*(u32 *)a0;
    v0 = *(u16 *)v1;
    v1 = (u16 *)((u8 *)v1 + 2);
    *(u32 *)a0 = (u32)v1;
    return v0;
}

u16 MmoFontCharNext_SJIS(u32 *a0) {
    u8 **pp = (u8 **)a0;
    u16 c;

    if (((u8 *)(sState + 8))[**pp] & 0x20) {
        c = *(*pp)++ << 8;
        c |= *(*pp)++;
        return c;
    }
    return *(*pp)++;
}

/* MmoFontCharCheck_UTF16 @ 0x215EB0 .. 0x215EB8 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lhu at 0x215eb4 computes the return value
 */

u16 MmoFontCharCheck_UTF16(u16 *a0 /* r4 */) {
    return *(u16 *)a0;
}

u16 MmoFontCharCheck_SJIS(u8 *a0 /* r4 */) {
    u8 v1;
    u32 v0;
    u16 v0_return; // v0

    v1 = *(u8 *)a0;
    v0 = (u32)(u8 *)(sState + 8);
    v0 = v0 + (u32)(v1);
    v0 = *(u8 *)v0;
    v0 = v0 & 0x20;
    if (v0 != 0) {
        v0_return = v1;
        v1 = *(u8 *)(a0 + 1);
        v0_return = (u32)(u16)v0_return << 8;
        v0_return = v0_return;
        v0_return |= v1;
        v0_return = v0_return;
    } else {
        v0_return = v1;
    }
    return v0_return;
}

void MmoFontInitTable(void) {
    s32 a3;
    u32 a2;
    s32 a1;
    u8 *a0;
    u32 v1;

    a0 = (u8 *)(sState + 8);
    a1 = 0x10;
    memset((void *)a0, a1, 0x100);
    a1 = 0x30;
    a0 = (u8 *)(sState + 0xc);
    do {
        v1 = a1 + -0x30;
        *(u8 *)(a0 + 0x20) = v1;
        v1 = a1 + -0x2f;
        *(u8 *)(a0 + 0x21) = v1;
        v1 = a1 + -0x2e;
        *(u8 *)(a0 + 0x22) = v1;
        v1 = a1 + -0x2d;
        *(u8 *)(a0 + 0x23) = v1;
        v1 = a1 + -0x2c;
        a1 = a1 + 5;
        *(u8 *)(a0 + 0x24) = v1;
        a0 = (u8 *)(a0 + 5);
    } while (a1 <= (s32)0x39);
    ((u8 *)sState)[0x81] = 10;
    ((u8 *)sState)[0x61] = 10;
    ((u8 *)sState)[0x82] = 11;
    ((u8 *)sState)[0x62] = 11;
    ((u8 *)sState)[0x83] = 12;
    ((u8 *)sState)[0x63] = 12;
    ((u8 *)sState)[0x84] = 13;
    ((u8 *)sState)[0x64] = 13;
    ((u8 *)sState)[0x85] = 14;
    ((u8 *)sState)[0x65] = 14;
    ((u8 *)sState)[0x86] = 15;
    ((u8 *)sState)[0x66] = 15;
    a3 = 0;
    a2 = (u32)sState;
    do {
        if (0 <= a3) {
            if (a3 <= (s32)0x7f) {
                goto _L00215E38;
            }
        }
        v1 = a3 < (s32)0xa0;
        if (v1 != 0 || a3 > (s32)0xdf) {
            v1 = *(u8 *)((a2 + 0x20));
            v1 = v1 | 0x20;
            *(u8 *)((a2 + 0x20)) = v1;
        }
        _L00215E38:;
        a3 = a3 + 1;
        v1 = a3 < (s32)0x100;
        a2 = a2 + 1;
    } while (v1 != 0);
    return;
}


u32 MmoFsCConvUTF16To8(u8 *output,u16 *input) {
    u16 code;
    u8 *cursor=output;
    if(*(volatile u16 *)input!=0) {
        do {
            code=*input;
            if(code&0xf800) {
                *cursor++=((s32)code>>12&15)|0xe0;
                *cursor++=((s32)*input>>6&63)|0x80;
                *cursor++=(*input&63)|0x80;
            } else if(code&0x780) {
                *cursor++=((s32)code>>6&31)|0xc0;
                *cursor++=(*input&63)|0x80;
            } else *cursor++=code;
            ++input;
        } while(*input!=0);
    }
    *cursor=0;
    return cursor-output+1;
}

int MmoFsCConvUTF8To16(u16 *dst, u8 *src) {
    int tbl[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 4};
    u16 *d = dst;
    int c;
    int t;

    while (*src != 0) {
        c = *src;
        t = tbl[(c >> 4) & 0xf];
        switch (t) {
        case 0:
            *d = c;
            src += 1;
            break;
        case 2:
            *d = (c & 0x1f) << 6;
            *d += src[1] & 0x3f;
            src += 2;
            break;
        case 3:
            *d = (c & 0xf) << 12;
            c = src[1] & 0x3f;
            src = (u8 *)((u32)src + 2);
            *d += (u16)(c << 6);
            *d += src[0] & 0x3f;
            src = (u8 *)((u32)src + 1);
            break;
        default:
            if (t == 1 || t >= 7) {
                return -2;
            }
            return -3;
        }
        d++;
    }
    *d = 0;
    return ((d - dst) + 1) * 2;
}
