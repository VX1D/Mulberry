#include "common.h"

/* FontInitTable @ 0x1722E0 .. 0x172424 (0x144 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: slti at 0x1723d0 writes a register its branch at 0x1723cc reads
 *   cfg: loop body is not one contiguous region: .L001723C8
 *   cfg: kept branch: 0x1723d0 if (..) goto .L00172408
 */

extern void * memset(void *, int, unsigned int);
static u32 sState[88];

/* FontCharCheck_SJIS @ 0x172430 .. 0x172478 (0x48 bytes) */
/*
 * dcomp notes:
 *   delay: andi at 0x17244c writes a register its branch at 0x172448 reads
 *   declaration vs inferred signature: return unsigned short vs inferred u32
 */

static u32 sState[88];

/* FontDrawChar @ 0x172520 */
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
signed int FontOption(unsigned char **pStr, unsigned char isSizeCheck);


extern signed int FontOption(unsigned char **, unsigned char);
signed int FontDrawChar(unsigned short code, unsigned int isLast);
extern signed int FontDrawChar(unsigned short, unsigned int);
#define DT_SF(i) (*(float *)(sState + (i)))
#define DT_SU(i) (*(u32 *)(sState + (i)))
#define DT_FL ((struct dw_924860_fields_b726452d *)((u8 *)(sState + 0x4c)))
#define DT_CUR ((struct dw_920783_fields_b726452d *)sCurrentP)

static u32 sCurrentP;
void * FontFindGlyph(unsigned short a0);
extern void * FontFindGlyph(unsigned short);
extern void FontDrawRect(signed int, float *, unsigned int *, float *, float);
extern u32 OptFontGlyph[];
struct DcGlyph { float left; float top; float right; float bottom; short offset; short width; short advance; short texID; };
struct DcFlag { unsigned char isColor : 1; unsigned char isAlpha : 1; unsigned char isBold : 1; unsigned char isItalic : 1; unsigned char ruby : 2; unsigned char isInit : 1; unsigned char dummy : 1; };
#define DC_FLAG ((struct DcFlag *)((u8 *)(sState + 0x4c)))
union DcTmp { u32 w; u8 b[4]; };


extern signed int FontReplaceUnicode(unsigned short *, unsigned short *, char *);
extern int vsprintf(char *, const char *, void *);
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


extern signed int FontOption(unsigned char **, unsigned char);
extern signed int FontDrawChar(unsigned short, unsigned int);
#define DT_SF(i) (*(float *)(sState + (i)))
#define DT_SU(i) (*(u32 *)(sState + (i)))
#define DT_FL ((struct dw_924860_fields_b726452d *)((u8 *)(sState + 0x4c)))
#define DT_CUR ((struct dw_920783_fields_b726452d *)sCurrentP)
#undef pRect
u32 FontGetLineSize();


extern u32 FontGetLineSize();
signed int FontDrawTextInRect(void *a0, unsigned short *str, float *lineWidthAry);
extern signed int FontDrawTextInRect(void *, unsigned short *, float *);

struct DtAlign { unsigned char h:2; unsigned char v:2; unsigned char rest:4; };


extern u32 FontGetLineSize();
extern void FsFontSetRect(void *, float, float, float, float);
extern signed int FontDrawTextInRect(void *, unsigned short *, float *);


/* FontOption @ 0x1733A0 .. 0x173CD0 (0x930 bytes, frame 0x90) */

#define FO_MASK (*(unsigned long *)(sState + 0x4a))

static inline int FoIsDigit(u32 d) {
    return (d & 0x10) == 0;
}

static inline int FoHex2(unsigned char *p, u32 *out) {
    int n;
    u32 acc;
    u32 d;
    int ok;
    unsigned short c;

    acc = 0;
    n = 0;
    do {
        c = ((unsigned short (*)(unsigned char **))DT_SU(0x51))(&p);
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

static inline void FoSkip(unsigned char **pp) {
    unsigned char *q;
    unsigned int r;

    q = *pp;
    do {
        r = ((unsigned int (*)(unsigned char **))DT_SU(0x51))(&q);
        r = (unsigned short)r;
        if (r == 0) {
            break;
        }
    } while ((unsigned short)r != ']');
    *pp = q;
}



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
#define DT_FL ((struct dw_924860_fields_b726452d *)((u8 *)(sState + 0x4c)))
#define DT_CUR ((struct dw_920783_fields_b726452d *)sCurrentP)


struct FlGlyph { u8 pad[0x10]; short w1; short pad2; short w2; };
struct FlFlag { unsigned char isColor : 1; unsigned char isAlpha : 1; unsigned char isBold : 1; unsigned char isItalic : 1; unsigned char ruby : 2; unsigned char isInit : 1; unsigned char dummy : 1; };
#define FL_FLAG ((struct FlFlag *)((u8 *)(sState + 0x4c)))


/* FsFontGetSize @ 0x174130 .. 0x17414C (0x1c bytes) */
/*
 * dcomp notes:
 *   tail: j FontGetLineSize at 0x174144 leaves the function
 *   a0 forwarded to FontGetLineSize
 *   a1 forwarded to FontGetLineSize
 *   repo declaration vs inferred signature: return int vs inferred void
 */

extern u32 FontGetLineSize();

/* FsFontGetLineHeight @ 0x174150 .. 0x174194 (0x44 bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v1 at 0x174170
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

static u32 sCurrentP;

/* FsFontSetBrightness @ 0x1741A0 .. 0x1741B0 (0x10 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

static u32 sCurrentP;

/* FsFontSetPiecesParam @ 0x1741B0 .. 0x1741C8 (0x18 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

static u32 sCurrentP;

/* FsFontSetAlignment @ 0x1741D0 .. 0x17424C (0x7c bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

struct dw_923053;
#ifndef PROTO_DW_920783
#define PROTO_DW_920783
struct dw_920783 {
    unsigned char *pTex[16];
    struct dw_923053 *pCCM;
    unsigned int baseColor[4];
    unsigned int color[4];
    float italicParam;
    float spaceX[2];
    float spaceY[2];
    float scaleX[3];
    float scaleY[3];
    unsigned int reserved;
    unsigned char alignX : 2;
    unsigned char alignY : 2;
    unsigned char isRubyCenter : 1;
    unsigned char isDisableColor : 1;
    unsigned char dummy : 2;
    unsigned char dummy2[3];
    char brightness;
    unsigned char piecePixel;
    unsigned short moveRange;
    unsigned char aGeneralBuffer[64];
};
#endif

/* FsFontSetBaseColor @ 0x1742F0 .. 0x174318 (0x28 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

static u32 sCurrentP;

/* FsFontSetColor @ 0x174320 .. 0x174348 (0x28 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

static u32 sCurrentP;

/* FsFontSetMaxChar @ 0x174350 .. 0x1743BC (0x6c bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42fe0000 at 0x174368
 *   fpu: float literal 0x4f000000 at 0x17436c
 */

static u32 sState[88];


/* FsFontSetTexBuf @ 0x174480 .. 0x174498 (0x18 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return int vs inferred u32
 */

static u32 sCurrentP;

/* FsFontSetCCMBuf @ 0x1744A0 .. 0x174514 (0x74 bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v1 at 0x1744e4
 *   fpu: mtc1 reinterprets v1 at 0x174500
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

static u32 sState[88];

/* FsFontSetCurrent @ 0x174520 .. 0x17454C (0x2c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void * vs inferred u32
 */

extern void FontSetRefCurrentPtr(void *);
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

extern void FontSetRefStatePtr(u32);
#define FI_CUR ((struct dw_920783_fields_b726452d *)sCurrentP)
#define FI_ST ((struct dw_922084_fields_b726452d *)sState)

static inline void FontSetColor0(u32 c) {
    FI_CUR->baseColor[0] = c;
    FI_CUR->baseColor[1] = c;
    FI_CUR->baseColor[2] = c;
    FI_CUR->baseColor[3] = c;
}
static inline void FontSetColor1(u32 c) {
    FI_CUR->color[0] = c;
    FI_CUR->color[1] = c;
    FI_CUR->color[2] = c;
    FI_CUR->color[3] = c;
}
static inline void FontSetScale(float s) {
    FI_CUR->scaleX[0] = s;
    FI_CUR->scaleY[0] = s;
    FI_CUR->scaleX[1] = s * FI_CUR->scaleX[2];
    FI_CUR->scaleY[1] = s * FI_CUR->scaleY[2];
}
static inline void FontSetSkew(float t) {
    FI_CUR->scaleX[2] = 0;
    FI_CUR->scaleY[2] = 0;
    FI_CUR->scaleX[1] = FI_CUR->scaleX[0] * t;
    FI_CUR->scaleY[1] = FI_CUR->scaleY[0] * t;
}

typedef struct FontAlignBits { unsigned char h:2; unsigned char v:2; unsigned char flag:1; unsigned char pad:3; } FontAlignBits;
typedef struct StateBits { unsigned char a:6; unsigned char f:1; unsigned char b:1; } StateBits;
static inline void FontSetAlign(s32 alignment) {
    s32 h, v, flag;
    h = (alignment & 0x30) >> 4;
    v = (alignment & 0xc0) >> 6;
    flag = (alignment & 0x100) >> 8;
    ((FontAlignBits *)(sCurrentP + 0x94))->h = h;
    ((FontAlignBits *)(sCurrentP + 0x94))->v = v;
    ((FontAlignBits *)(sCurrentP + 0x94))->flag = flag;
}

u32 OptFontGlyph[0x5a] = {
    0, 0, 0x3e3851ec, 0x3e3851ec, 0x180000, 0x20018, 0x3e47ae14, 0, 0x3ec00000, 0x3e3851ec,
    0x180000, 0x20018, 0x3ecbc6a8, 0, 0x3f13f7cf, 0x3e3851ec, 0x180000, 0x20018, 0x3f160419, 0,
    0x3f441893, 0x3e3851ec, 0x180000, 0x20018, 0x3f47ef9e, 0, 0x3f760419, 0x3e3851ec, 0x180000,
    0x20018, 0, 0x3e47ae14, 0x3e8fdf3b, 0x3ebbe76d, 0x250000, 0x20025, 0x3e981062, 0x3e47ae14,
    0x3f13f7cf, 0x3ebbe76d, 0x250000, 0x20025, 0x3f181062, 0x3e47ae14, 0x3f45e354, 0x3ec00000,
    0x180000, 0x20018, 0, 0x3ec83127, 0x3e8fdf3b, 0x3f1020c5, 0x250000, 0x20025, 0x3e981062,
    0x3ec83127, 0x3f13f7cf, 0x3f1020c5, 0x250000, 0x20025, 0x3f181062, 0x3ec83127, 0x3f45e354,
    0x3f11eb85, 0x180000, 0x20018, 0, 0x3f160419, 0x3ed81062, 0x3f420c4a, 0x370000, 0x20037,
    0x3ee04189, 0x3f160419, 0x3f51eb85, 0x3f420c4a, 0x320000, 0x20032, 0, 0x3f47ef9e,
    0x3e3851ec, 0x3f760419, 0x180000, 0x20018, 0x3e400000, 0x3f47ef9e, 0x3f420000, 0x3f780000,
    0x490000, 0x20049
};

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int FsFontInit(void *a0 );
void * FsFontSetCurrent(void *a0 );
signed int FsFontSetCCMBuf(void *a0 );
int FsFontSetTexBuf(signed int id, void *pTexFileBuf);
void * FontFindGlyph(unsigned short a0);
signed int FsFontSetMaxChar(float f12 );
signed int FsFontSetColor(unsigned int a0 );
signed int FsFontSetBaseColor(unsigned int a0 );
signed int FsFontSetDisableColor(void);
signed int FsFontSetEnableColor(void);
signed int FsFontSetScale(float x, float y);
signed int FsFontSetAlignment(signed int a0 );
signed int FsFontSetPiecesParam(unsigned char a0 , unsigned short a1 );
signed int FsFontSetBrightness(char a0 );
signed int FsFontGetLineHeight(float *a0 );
int FsFontGetSize(u8 ***a0 , u8 ***a1 , u8 ***a2 , u8 **a3 );
u32 FontGetLineSize();
signed int FontOption(unsigned char **pStr, unsigned char isSizeCheck);
signed int FsFontDrawText(float x, float y, char *fmt, ...);
signed int FsFontDrawTextInRect(float *rect, char *fmt, ...);
signed int FontDrawTextInRect(void *a0, unsigned short *str, float *lineWidthAry);
signed int FsFontReplaceText(void *a0 , void *a1 , ...);
signed int FontDrawChar(unsigned short code, unsigned int isLast);
u32 FontCharNext_UTF16(u32 *a0 );
unsigned short FontCharNext_SJIS(unsigned char **pp);
u16 FontCharCheck_UTF16(u16 *a0 );
unsigned short FontCharCheck_SJIS(unsigned char *a0 );
void FontInitTable(void);


signed int FsFontInit(void *a0 /* r4 */) {
    memset(a0, 0, 0xdc);
    sCurrentP = (u32)a0;
    FontSetRefCurrentPtr(a0);
    FontSetColor0(0x7f7f7f7f);
    FontSetColor1(0x7f7f7f7f);
    FontSetScale(1.0f);
    FontSetSkew(0.0f);
    FI_CUR->italicParam = 3.0f;
    FontSetAlign(0x100);
    FI_CUR->brightness = 0;
    if (!((StateBits *)((u8 *)(sState + 0x4c)))->f) {
        u8 color[4];
        FontInitTable();
        ((StateBits *)((u8 *)(sState + 0x4c)))->f = 1;
        FI_ST->screenW = 640.0f;
        FI_ST->screenH = 448.0f;
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = 0;
        FI_ST->colorMask = *(u32 *)color;
        FI_ST->maxChar = 100000.0f;
        FI_ST->lastAlpha = 0x7f;
        FontSetRefStatePtr((u32)sState);
    }
    return 0;
}

void * FsFontSetCurrent(void *a0 /* r4 */) {
    u32 s0;

    s0 = sCurrentP;
    sCurrentP = (u32)a0;
    FontSetRefCurrentPtr(a0);
    return (void *)s0;
}

signed int FsFontSetCCMBuf(void *a0 /* r4 */) {
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    v1 = sCurrentP;
    *(u32 *)((v1 + 0x40)) = (u32)a0_bytes;
    v1 = sCurrentP;
    a0_bytes = (u8 *)*(s32 *)((v1 + 0x40));
    v1 = *(s32 *)(a0_bytes + 0x14);
    *(u32 *)(a0_bytes + 0x14) = (s32)(a0_bytes + v1);
    v1 = sCurrentP;
    a0_bytes = (u8 *)*(s32 *)((v1 + 0x40));
    v1 = *(s32 *)(a0_bytes + 0x18);
    *(u32 *)(a0_bytes + 0x18) = (s32)(a0_bytes + v1);
    a0_bytes = (u8 *)sCurrentP;
    v1 = *(s32 *)(a0_bytes + 0x40);
    v1 = *(s16 *)((v1 + 8));
    *(f32 *)(sState + 4) = (float)((float)(s32)v1);
    v1 = *(s32 *)(a0_bytes + 0x40);
    v1 = *(s16 *)((v1 + 8));
    *(f32 *)(sState + 2) = (float)((float)(s32)v1);
    return 0;
}

int FsFontSetTexBuf(signed int id, void *pTexFileBuf) {
    u32 v1;
    u32 v0;

    v1 = sCurrentP;
    id = (s32)((u32)id << 2);
    v0 = 0;
    v1 = v1 + (u32)(id);
    *(u32 *)v1 = (u32)pTexFileBuf;
    return v0;
}

void * FontFindGlyph(unsigned short a0) {
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
            return (void *)(t1 + (*(s32 *)(p + 8) + (s32)(a0 - *(u32 *)p)) * 0x18);
        }
    }
    return (void *)0;
}

signed int FsFontSetMaxChar(float f12 /* f12 */) {
    float f1;

    f1 = 127.0f;
    *(f32 *)(sState + 0x56) = f12;
    *(u8 *)(sState + 0x57) = (u32)(127.0f * (f12 - (float)((float)(s32)f12)));
    return 0;
}

signed int FsFontSetColor(unsigned int a0 /* r4 */) {
    u32 *v1;
    u32 v0;

    v1 = (u32 *)sCurrentP;
    v0 = 0;
    *(u32 *)(((u8 *)v1 + 0x54)) = (s32)a0;
    v1 = (u32 *)sCurrentP;
    *(u32 *)(((u8 *)v1 + 0x58)) = (s32)a0;
    v1 = (u32 *)sCurrentP;
    *(u32 *)(((u8 *)v1 + 0x5c)) = (s32)a0;
    v1 = (u32 *)sCurrentP;
    *(u32 *)(((u8 *)v1 + 0x60)) = (s32)a0;
    return v0;
}

signed int FsFontSetBaseColor(unsigned int a0 /* r4 */) {
    u32 *v1;
    u32 v0;

    v1 = (u32 *)sCurrentP;
    v0 = 0;
    *(u32 *)(((u8 *)v1 + 0x44)) = (s32)a0;
    v1 = (u32 *)sCurrentP;
    *(u32 *)(((u8 *)v1 + 0x48)) = (s32)a0;
    v1 = (u32 *)sCurrentP;
    *(u32 *)(((u8 *)v1 + 0x4c)) = (s32)a0;
    v1 = (u32 *)sCurrentP;
    *(u32 *)(((u8 *)v1 + 0x50)) = (s32)a0;
    return v0;
}

/* FsFontSetDisableColor @ 0x1742C0 .. 0x1742E4 (0x24 bytes) */

signed int FsFontSetDisableColor(void) {
    u8 *a2;

    a2 = (u8 *)sCurrentP;
    ((struct { unsigned char _pad:5; unsigned char f:1; } *)&*(u8 *)(a2 + 0x94))->f = 1;
    return 0;
}

/* FsFontSetEnableColor @ 0x174290 .. 0x1742B8 (0x28 bytes) */

signed int FsFontSetEnableColor(void) {
    u8 *a2;
    u32 v0;

    a2 = (u8 *)sCurrentP;
    v0 = 0;
    ((struct { unsigned char _pad:5; unsigned char f:1; } *)&*(u8 *)(a2 + 0x94))->f = 0;
    return 0;
}

/* FsFontSetScale @ 0x174250 .. 0x174288 (0x38 bytes) */

signed int FsFontSetScale(float x, float y) {
    u8 *v1;

    v1 = (u8 *)sCurrentP;
    *(f32 *)(v1 + 0x78) = (float)x;
    v1 = (u8 *)sCurrentP;
    *(f32 *)(v1 + 0x84) = (float)y;
    v1 = (u8 *)sCurrentP;
    *(f32 *)(v1 + 0x7c) = (x * *(float *)(v1 + 0x80));
    v1 = (u8 *)sCurrentP;
    *(f32 *)(v1 + 0x88) = (y * *(float *)(v1 + 0x8c));
    return 0;
}

signed int FsFontSetAlignment(signed int a0 /* r4 */) {
    u32 t1;
    u32 t0;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 v1;
    s32 v0;

    ((struct dw_920783 *)sCurrentP)->alignX = (s32)((u32)(a0) & 0x30) >> 4;
    ((struct dw_920783 *)sCurrentP)->alignY = (s32)((u32)(a0) & 0xc0) >> 6;
    ((struct dw_920783 *)sCurrentP)->isRubyCenter = (s32)((u32)(a0) & 0x100) >> 8;
    return 0;
}

signed int FsFontSetPiecesParam(unsigned char a0 /* r4 */, unsigned short a1 /* r5 */) {
    u8 *v1;
    u32 v0;

    v1 = (u8 *)sCurrentP;
    v0 = 0;
    *(u8 *)(((u8 *)v1 + 0x99)) = (u8)a0;
    v1 = (u8 *)sCurrentP;
    *(u16 *)(((u8 *)v1 + 0x9a)) = (u16)a1;
    return v0;
}

signed int FsFontSetBrightness(char a0 /* r4 */) {
    u8 *v1;
    u32 v0;

    v1 = (u8 *)sCurrentP;
    v0 = 0;
    *(u8 *)(((u8 *)v1 + 0x98)) = (u8)a0;
    return v0;
}

signed int FsFontGetLineHeight(float *a0 /* r4 */) {
    u8 *a1;
    u32 v1;
    float f4;

    a1 = (u8 *)sCurrentP;
    v1 = *(s32 *)(a1 + 0x40);
    v1 = *(s16 *)((v1 + 8));
    f4 = ((float)(s32)v1);
    *(f32 *)a0 = (*(float *)(a1 + 0x70) + ((*(float *)(a1 + 0x74) + ((float)f4 * *(float *)(a1 + 0x88))) +
        (f4 * *(float *)(a1 + 0x84))));
    return 0;
}

int FsFontGetSize(u8 ***a0 /* r4 */, u8 ***a1 /* r5 */, u8 ***a2 /* r6 */, u8 **a3 /* r7 */) {
    u32 v0;
    u32 t0;

    v0 = (u32)a2;
    t0 = (u32)a3;
    a2 = (u8 ***)0;
    a3 = (u8 **)v0;
    return FontGetLineSize(a0, a1, 0, a3, t0, 0, 0);
}

u32 FontGetLineSize(pWidth, pHeight, pLine, str, lastCode, nextCode, pRect)
    float *pWidth;
    float *pHeight;
    float *pLine;
    unsigned char *str;
    unsigned int lastCode;
    unsigned int nextCode;
    float *pRect; {
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
    cur = (u8 *)sCurrentP;
    italic = ((struct dw_920783_fields_b726452d *)cur)->scaleX[0] * (((struct dw_920783_fields_b726452d *)cur)->italicParam * (float)(unsigned int)FL_FLAG->isItalic);
    p = str;
    pf = (s32 *)(cur + 0x40);
    if (*(u8 *)(*pf + 0x1c) == 1) {
        DT_SU(0x51) = (u32)FontCharNext_UTF16;
        DT_SU(0x52) = (u32)FontCharCheck_UTF16;
    } else {
        DT_SU(0x51) = (u32)FontCharNext_SJIS;
        DT_SU(0x52) = (u32)FontCharCheck_SJIS;
    }
    lc = lastCode;
    nc = nextCode;
    DT_SF(2) = (float)*(s16 *)(*pf + 8) * DT_CUR->scaleY[0];
    DT_SF(4) = DT_SF(2) + DT_CUR->spaceY[0];
    DT_SF(3) = (float)*(s16 *)(*pf + 8) * DT_CUR->scaleY[1];
    DT_SF(5) = DT_SF(3) + DT_CUR->spaceY[1];
    DT_SU(0x54) = 0;
    DT_SF(0x53) = DT_SF(4) + DT_SF(5);
    *pWidth = 0.0f;
    *pHeight = DT_SF(0x53);
    while (1) {
        code = ((unsigned short (*)(unsigned char **))DT_SU(0x51))(&p);
        next = ((unsigned short (*)(unsigned char *))DT_SU(0x52))(p);
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
            *pHeight = *pHeight + DT_SF(0x53);
            continue;
        case '#':
            if (next != '#') {
                ret = FontOption(&p, 0);
                if (ret >= 0) {
                    continue;
                }
                return ret;
            }
            ((unsigned short (*)(unsigned char **))DT_SU(0x51))(&p);
        default:
            pGlyph = FontFindGlyph(code);
            if (pGlyph == 0) {
                continue;
            }
            isRuby = FL_FLAG->ruby == 2;
            pScale = (float *)((u8 *)sCurrentP + (isRuby * 4) + 0x78);
            charWidth = (float)(unsigned int)FL_FLAG->isBold
                + *pScale * (float)(pGlyph->w1 + pGlyph->w2);
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
                *pHeight = *pHeight + DT_SF(0x53);
                if (!(DT_SF(1) + DT_SF(0x53) <= DT_SF(0x50))) {
                    return -8;
                }
            }
        }
        spaceX = DT_CUR->spaceX[isRuby];
        x = x + (charWidth + spaceX);
    }
}

signed int FontOption(unsigned char **pStr, unsigned char isSizeCheck) {
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
    code = ((unsigned short (*)(unsigned char **, unsigned char))DT_SU(0x51))(pStr, isSizeCheck);
    switch (code) {
    case 'c':
        if (DT_FL->isColor) {
            if (!DT_CUR->isDisableColor) {
                DT_CUR->color[0] = (DT_CUR->baseColor[0] & FO_MASK) + (DT_CUR->color[0] & ~FO_MASK);
                DT_CUR->color[1] = (DT_CUR->baseColor[1] & FO_MASK) + (DT_CUR->color[1] & ~FO_MASK);
                DT_CUR->color[2] = (DT_CUR->baseColor[2] & FO_MASK) + (DT_CUR->color[2] & ~FO_MASK);
                DT_CUR->color[3] = (DT_CUR->baseColor[3] & FO_MASK) + (DT_CUR->color[3] & ~FO_MASK);
            }
        } else {
            if (!DT_CUR->isDisableColor) {
                *pStr += k;
                ret = FoHex2(*pStr, &value);
                if (ret < 0) {
                    return ret;
                }
                clr.c[0] = value;
                k = k << 1;
                *pStr += k;
                ret = FoHex2(*pStr, &value);
                if (ret < 0) {
                    return ret;
                }
                clr.c[1] = value;
                *pStr += k;
                ret = FoHex2(*pStr, &value);
                if (ret < 0) {
                    return ret;
                }
                clr.c[2] = value;
                *pStr += k;
                clr.c[3] = 0;
                m = DT_SU(0x4a);
                nm = ~m;
                DT_CUR->color[0] = (DT_CUR->color[0] & nm) + (clr.color & m);
                DT_CUR->color[1] = (DT_CUR->color[1] & nm) + (clr.color & m);
                DT_CUR->color[2] = (DT_CUR->color[2] & nm) + (clr.color & m);
                DT_CUR->color[3] = (DT_CUR->color[3] & nm) + (clr.color & m);
            }
            FoSkip(pStr);
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
            ret = FoHex2(*pStr, &value);
            if (ret < 0) {
                return ret;
            }
            clr.c[3] = value;
            nm = ~FO_MASK;
            DT_CUR->color[0] = (DT_CUR->color[0] & ~nm) + (clr.color & nm);
            DT_CUR->color[1] = (DT_CUR->color[1] & ~nm) + (clr.color & nm);
            DT_CUR->color[2] = (DT_CUR->color[2] & ~nm) + (clr.color & nm);
            DT_CUR->color[3] = (DT_CUR->color[3] & ~nm) + (clr.color & nm);
            FoSkip(pStr);
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
                ret = FontGetLineSize(&rubyW, &dummy, 0, *pStr, ']', 0, 0);
                if (ret < 0) {
                    return ret;
                }
                saveFlag = *DT_FL;
                c0 = DT_CUR->color[0];
                c1 = DT_CUR->color[1];
                c2 = DT_CUR->color[2];
                c3 = DT_CUR->color[3];
                DT_FL->ruby = 0;
                ret = FontGetLineSize(&textW, &dummy, 0, *pStr + ret, '#', 'r', 0);
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
            FoSkip(pStr);
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

signed int FsFontDrawText(float x, float y, char *fmt, ...) {
    char *ap;
    u32 r;
    s32 *pf;
    float w, h;
    u8 rect[24];
    char buf[1024];
    float work[32];

    memset(buf, 0, 0x200);
    ap = (char *)__builtin_next_arg(fmt) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    r = *(u8 *)(*(s32 *)(sCurrentP + 0x40) + 0x1c);
    if (r != 0) {
        r = FontReplaceUnicode((unsigned short *)buf, (unsigned short *)fmt, ap);
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
        *(void **)(sState + 0x51) = (void *)FontCharNext_UTF16;
        *(void **)(sState + 0x52) = (void *)FontCharCheck_UTF16;
    } else {
        *(void **)(sState + 0x51) = (void *)FontCharNext_SJIS;
        *(void **)(sState + 0x52) = (void *)FontCharCheck_SJIS;
    }
    *(float *)(sState + 2) = (float)*(s16 *)(*pf + 8) * *(float *)(sCurrentP + 0x84);
    *(float *)(sState + 4) = *(float *)(sState + 2) + *(float *)(sCurrentP + 0x70);
    *(float *)(sState + 3) = (float)*(s16 *)(*pf + 8) * *(float *)(sCurrentP + 0x88);
    *(float *)(sState + 5) = *(float *)(sState + 3) + *(float *)(sCurrentP + 0x74);
    *(u32 *)(sState + 0x54) = 0;
    *(float *)(sState + 0x53) = *(float *)(sState + 4) + *(float *)(sState + 5);
    r = *(u8 *)(sCurrentP + 0x94) & 3;
    if (r != 0) {
        r = FontGetLineSize(&w, &h, work, (u8 *)buf, 0, 0, 0);
        if ((s32)r < 0) {
            return r;
        }
    } else {
        w = *(float *)(sState + 0x48);
        h = *(float *)(sState + 0x49);
    }
    *(float *)(sState + 1) = y;
    FsFontSetRect(rect, x, y, x + w, y + h);
    return FontDrawTextInRect(rect, (unsigned short *)buf, work);
}

signed int FsFontDrawTextInRect(float *rect, char *fmt, ...) {
    char *ap;
    u32 r;
    s32 *pf;
    float w, h;
    char buf[1032];
    float work[32];
    u8 av;
    float yy;

    ap = (char *)__builtin_next_arg(fmt) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    r = *(u8 *)(*(s32 *)(sCurrentP + 0x40) + 0x1c);
    if (r != 0) {
        r = FontReplaceUnicode((unsigned short *)buf, (unsigned short *)fmt, ap);
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
        *(void **)(sState + 0x51) = (void *)FontCharNext_UTF16;
        *(void **)(sState + 0x52) = (void *)FontCharCheck_UTF16;
    } else {
        *(void **)(sState + 0x51) = (void *)FontCharNext_SJIS;
        *(void **)(sState + 0x52) = (void *)FontCharCheck_SJIS;
    }
    *(float *)(sState + 2) = (float)*(s16 *)(*pf + 8) * *(float *)(sCurrentP + 0x84);
    *(float *)(sState + 4) = *(float *)(sState + 2) + *(float *)(sCurrentP + 0x70);
    *(float *)(sState + 3) = (float)*(s16 *)(*pf + 8) * *(float *)(sCurrentP + 0x88);
    *(float *)(sState + 5) = *(float *)(sState + 3) + *(float *)(sCurrentP + 0x74);
    *(u32 *)(sState + 0x54) = 0;
    *(float *)(sState + 0x53) = *(float *)(sState + 4) + *(float *)(sState + 5);
    if (((struct DtAlign *)(sCurrentP + 0x94))->h == 0) {
        if (((struct DtAlign *)(sCurrentP + 0x94))->v == 0) {
            goto skip;
        }
    }
    r = FontGetLineSize(&w, &h, work, (u8 *)buf, 0, 0, rect);
    if ((s32)r < 0) {
        return r;
    }
skip:
    av = ((struct DtAlign *)(sCurrentP + 0x94))->v;
    if (av != 0) {
        yy = rect[1] + ((rect[3] - rect[1]) - h) / (float)av;
    } else {
        yy = rect[1];
    }
    *(float *)(sState + 1) = yy;
    return FontDrawTextInRect(rect, (unsigned short *)buf, work);
}

signed int FontDrawTextInRect(void *a0, unsigned short *str, float *lineWidthAry) {
#define pRect ((struct dw_923722_fields_b726452d *)a0)
    unsigned char *p;
    unsigned short code;
    unsigned int c;
    int ret;
    int saveRet;
    float width;
    float charCount;

    charCount = 0.0f;
    p = (unsigned char *)str;
    width = pRect->right - pRect->left;
    *(struct dw_923722_fields_b726452d *)(sState + 0x4d) = *pRect;
    DT_SF(0) = DT_CUR->alignX != 0 ? pRect->left + (width - lineWidthAry[DT_SU(0x54)]) / (float)DT_CUR->alignX : pRect->left;
    DT_FL->isColor = 0;
    DT_FL->isBold = 0;
    DT_FL->isItalic = 0;
    DT_CUR->color[0] = DT_CUR->baseColor[0];
    DT_CUR->color[1] = DT_CUR->baseColor[1];
    DT_CUR->color[2] = DT_CUR->baseColor[2];
    DT_CUR->color[3] = DT_CUR->baseColor[3];
    saveRet = 0;
    for (;;) {
        if (charCount >= DT_SF(0x56)) {
            return 0;
        }
        code = ((unsigned short (*)(unsigned char **))DT_SU(0x51))(&p);
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
                DT_SU(0x54)++;
                DT_SF(0) = DT_CUR->alignX != 0 ? pRect->left + (width - lineWidthAry[DT_SU(0x54)]) / (float)DT_CUR->alignX : pRect->left;
                DT_SF(1) = DT_SF(1) + DT_SF(0x53);
                if (DT_SF(1) + DT_SF(0x53) <= DT_SF(0x50)) {
                    continue;
                }
                return -8;
            case '#':
                if (((unsigned short (*)(unsigned char *))DT_SU(0x52))(p) != '#') {
                    ret = FontOption(&p, 1);
                    if (ret >= 0) {
                        continue;
                    }
                    return ret;
                }
                ((unsigned short (*)(unsigned char **))DT_SU(0x51))(&p);
                break;
            }
            ret = FontDrawChar(code, DT_SF(0x56) - charCount < 1.0f);
            charCount += 1.0f;
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

signed int FsFontReplaceText(void *a0 /* r4 */, void *a1 /* r5 */, ...) {
    s32 r;
    char *ap;
    ap = (char *)__builtin_next_arg(a1) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    if (*(u8 *)(*(s32 *)(sCurrentP + 0x40) + 0x1c) != 0) {
        r = FontReplaceUnicode((unsigned short *)a0, (unsigned short *)a1, ap);
    } else {
        r = vsprintf((char *)a0, (const char *)a1, ap);
        if (r < 0) {
            r = -9;
        }
    }
    return r;
}

signed int FontDrawChar(unsigned short code, unsigned int isLast) {
    int last = isLast;
    struct DcGlyph *pGlyph;
    struct dw_920783_fields_b726452d *pCur;
    float pos[4] __attribute__((aligned(16)));
    float uv[4] __attribute__((aligned(16)));
    float italic;
    int isRuby;
    unsigned int color[4];
    unsigned char *pColorElement;
    int i;
    union DcTmp tmp;
    unsigned int *pc;
    int wk;
    u64 mask;
    u64 alpha;
    float *pScale;

    if (code >= 0x2460 && code <= 0x246e) {
        pGlyph = (struct DcGlyph *)((u8 *)OptFontGlyph + (code - 0x2460) * 0x18);
    } else {
        pGlyph = FontFindGlyph(code);
    }
    if (pGlyph == 0) {
        return -4;
    }
    uv[0] = pGlyph->left;
    uv[1] = pGlyph->top;
    uv[2] = pGlyph->right;
    uv[3] = pGlyph->bottom;
    isRuby = DC_FLAG->ruby == 2;
    pScale = (float *)((u8 *)(isRuby * 4) + sCurrentP + 0x78);
    pCur = DT_CUR;
    italic = *pScale * (DT_CUR->italicParam * (float)(unsigned int)DC_FLAG->isItalic);
    if (!(DT_SF(0) + ((float)(unsigned int)DC_FLAG->isBold + *pScale * (float)(pGlyph->offset + pGlyph->advance)) <= DT_SF(0x4f))) {
        if (DT_CUR->alignX != 0) {
            return -8;
        }
        DT_SF(0) = DT_SF(0x4d);
        DT_SF(1) = DT_SF(1) + DT_SF(0x53);
        if (!(DT_SF(1) + DT_SF(0x53) <= DT_SF(0x50))) {
            return -8;
        }
    }
    DT_SF(0) = DT_SF(0) + (float)pGlyph->offset * *pScale;
    if (DC_FLAG->ruby == 2) {
        float px = DT_SF(0) - 0.5f;
        float py = DT_SF(1) - 0.5f;
        pos[0] = px;
        pos[1] = py;
        pos[2] = px + (float)pGlyph->width * *pScale;
        pos[3] = py + DT_SF(5);
    } else {
        float px = DT_SF(0) - 0.5f;
        float h = DT_SF(5);
        float py = DT_SF(1) - 0.5f;
        pos[0] = px;
        pos[1] = py + h;
        pos[2] = px + (float)pGlyph->width * *pScale;
        pos[3] = h + (py + DT_SF(2));
    }
    DT_SF(0) = DT_SF(0) + ((float)(unsigned int)DC_FLAG->isBold + (*(float *)((u8 *)(isRuby * 4) + sCurrentP + 0x68) + (float)pGlyph->advance * *pScale));
    tmp.w = 0;
    tmp.b[3] = *(u8 *)((u8 *)sState + 0x15c);
    mask = *(u64 *)(sState + 0x4a);
    alpha = tmp.w & ~mask;
    for (i = 0, pc = color; i < 4; i++, pc++) {
        *pc = pCur->color[i];
        if (last != 0) {
            { u64 t = mask & *pc; *pc = t | alpha; }
        }
    }
    color[0] = DT_CUR->color[0];
    color[1] = DT_CUR->color[1];
    color[2] = DT_CUR->color[2];
    color[3] = DT_CUR->color[3];
    pColorElement = (unsigned char *)color;
    for (i = 0; i < 3; i++) {
        wk = *pColorElement + *pColorElement * DT_CUR->brightness / 128;
        if (wk > 255) {
            *pColorElement = 255;
        } else if (wk < 0) {
            *pColorElement = 0;
        } else {
            *pColorElement = wk;
        }
        pColorElement++;
    }
    FontDrawRect(pGlyph->texID, pos, color, uv, italic);
    if (DC_FLAG->isBold != 0) {
        pos[0] = pos[0] + 1.0f;
        pos[2] = pos[2] + 1.0f;
        FontDrawRect(pGlyph->texID, pos, color, uv, italic);
    }
    return 0;
}


/* FontCharNext_UTF16 @ 0x172500 .. 0x172514 (0x14 bytes) */
/*
 * dcomp notes:
 *   v1 is the pointer held in a0+0x0
 */

u32 FontCharNext_UTF16(u32 *a0 /* r4 */) {
    u16 *v1;
    u16 v0;

    v1 = (u16 *)*(u32 *)a0;
    v0 = *(u16 *)v1;
    v1 = (u16 *)((u8 *)v1 + 2);
    *(u32 *)a0 = (u32)v1;
    return v0;
}

unsigned short FontCharNext_SJIS(unsigned char **pp) {
    unsigned short code;

    if (((u8 *)(sState + 8))[**pp] & 0x20) {
        code = *(*pp)++ << 8;
        code |= *(*pp)++;
        return code;
    } else {
        code = *(*pp)++;
    }
    return code;
}

/* FontCharCheck_UTF16 @ 0x172480 .. 0x172488 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lhu at 0x172484 computes the return value
 */

u16 FontCharCheck_UTF16(u16 *a0 /* r4 */) {
    return *(u16 *)a0;
}

unsigned short FontCharCheck_SJIS(unsigned char *a0 /* r4 */) {
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

void FontInitTable(void) {
    s32 a3;
    u32 a2;
    s32 a1;
    u8 *a0;
    u32 v1;

    memset((void *)(u8 *)(sState + 8), 0x10, 0x100);
    a1 = 0x39;
    a0 = (u8 *)sState + 0x39;
    do {
        *(u8 *)(a0 + 0x20) = a1 + -0x30;
        *(u8 *)(a0 + 0x1f) = a1 + -0x31;
        *(u8 *)(a0 + 0x1e) = a1 + -0x32;
        *(u8 *)(a0 + 0x1d) = a1 + -0x33;
        v1 = a1 + -0x34;
        a1 = a1 + -5;
        *(u8 *)(a0 + 0x1c) = v1;
        a0 = (u8 *)(a0 + -5);
    } while (a1 > (s32)0x2f);
    a0 = (u8 *)(s32)0xf;
    *(u8 *)((u8 *)&sState + 0x86) = (s32)a0;
    v1 = 0xe;
    a2 = 0xd;
    a1 = 0xc;
    *(u8 *)((u8 *)&sState + 0x66) = (s32)a0;
    a0 = (u8 *)(s32)0xb;
    *(u8 *)((u8 *)&sState + 0x85) = v1;
    *(u8 *)((u8 *)&sState + 0x65) = v1;
    v1 = 0xa;
    *(u8 *)(sState + 0x21) = a2;
    *(u8 *)(sState + 0x19) = a2;
    *(u8 *)((u8 *)&sState + 0x83) = a1;
    *(u8 *)((u8 *)&sState + 0x63) = a1;
    *(u8 *)((u8 *)&sState + 0x82) = (s32)a0;
    *(u8 *)((u8 *)&sState + 0x62) = (s32)a0;
    *(u8 *)((u8 *)&sState + 0x81) = v1;
    *(u8 *)((u8 *)&sState + 0x61) = v1;
    a3 = 0;
    a2 = (u32)sState;
    do {
        if (0 <= a3) {
            if (a3 <= (s32)0x7f) {
                goto _L00172408;
            }
        }
        v1 = a3 < (s32)0xa0;
        if (v1 != 0 || a3 > (s32)0xdf) {
            v1 = (u32)(*(u8 *)((a2 + 0x20))) | 0x20;
            *(u8 *)((a2 + 0x20)) = v1;
        }
        _L00172408:;
        a3 = a3 + 1;
        v1 = a3 < (s32)0x100;
        a2 = a2 + 1;
    } while (v1 != 0);
    return;
}
