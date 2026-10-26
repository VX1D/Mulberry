#include "common.h"
extern u32 MmoFsFont_GetDmaBufferSize(s32, u32);
extern void fsmmo_DrawSprite(u8 *, u8 *, float *);
extern u32 sMmoData[];
extern u32 fsmmo_Calc(u32, u8 *, u8 *);
extern void * memcpy(void *, void *, unsigned int);
extern void MmoFsFontGetPos(float *, float *);
extern u32 MmoFsFontGetSize();
extern void MmoFsFontSetMargin(float, float);
extern void MmoFsFontSetAlignment(u32);
extern void MmoFsFontDrawText(u32, u32, u32, float, float);
extern u32 s_System[];
extern u32 MmoFsFontEnd(void);
extern u32 MmoFsFontSetCurrent();
extern u32 MmoFsFontBegin(void);
extern void MmoFsFontSetCCMBuf(u32, u8 *);
extern void MmoFsFontSetTexBuf(u32, u32);
extern u32 MmoFsFontInit(u32);
extern void *memset();
extern void MmoFsFont_SetMode();
extern void MmoFsFontSetBaseColor(u32);
extern u32 s_aWorkBuffer[];
void MmoFontSetRefStatePtr(void);
void MmoFontSetRefCurrentPtr(s32 a0 /* r4 */);
u32 MmoFsFont_SetDmaBuffer(u8 *a0 /* r4 */, s32 a1 /* r5 */);
void MmoFsFontSetRect(float *a0 /* r4 */, float f12 /* f12 */, float f13 /* f13 */, float f14 /*
        f14 */, float f15 /* f15 */);
static float GetEaseOutPrm(u32 *a0 /* r4 */, s32 a1 /* r5 */);
static float GetEaseInPrm(u32 *a0 /* r4 */, s32 a1 /* r5 */);
static float GetLinearPrm(u32 *a0 /* r4 */, s32 a1 /* r5 */);
static void DrawResTexture(float *a0 /* r4 */);
static u32 CalcTexture(u8 *a0 /* r4 */);
void fsmmo_SetBlurNum(s32 a0 /* r4 */);
void Font_GetPos(float *x, float *y);
void Font_GetSize(u8 *a0 /* r4 */, u8 *a1 /* r5 */, s32 a2 /* r6 */);
void Font_SetMargin(float x, float y);
void Font_SetAlignment(u32 align);
void Font_Print2Xy(s32 a0 /* r4 */, s32 a1 /* r5 */, u8 *a2 /* r6 */);
void Font_End(void);
u32 Font_Begin(void);
void Font_SetTexture(s32 a0 /* r4 */, u8 *a1 /* r5 */);
u32 Font_Initialize(void);



static u32 sCurrentP;
static u8 s_pSysInfo[0x4];


typedef struct {
    unsigned long NLOOP : 15;
    unsigned long EOP : 1;
    unsigned long pad : 30;
    unsigned long PRE : 1;
    unsigned long PRIM : 11;
    unsigned long FLG : 2;
    unsigned long NREG : 4;
    unsigned long REGS;
} MmoGifTag __attribute__((aligned(16)));

extern void FlushCache(int);

static inline u32 *MmoPk4(u32 *p, u32 a, u32 b, u32 c, u32 d) {
    *p++ = a;
    *p++ = b;
    *p++ = c;
    *p++ = d;
    return p;
}


#include "common.h"
#include "sce/libgraph.h"

typedef struct {
    u32 totalSize;              /* 0x00 */
    u32 wnum;                   /* 0x04 */
    u8  dummy[5];               /* 0x08 */
    u8  compare;                /* 0x0d */
    u16 tex_id;                 /* 0x0e */
    sceGsTex0 tex0;             /* 0x10 */
    sceGsTex1 tex1;             /* 0x18 */
} TM2;

extern void FlushCache(int);

#define _WAITSYNC() \
    while ((*(volatile u32 *)0x1000a000 & 0x100) != 0 || \
           (*(volatile u32 *)0x10003020 & 0xc00) != 0) { }







/* fsmmo_Initialize @ 0x21B6D0 .. 0x21B864 (0x194 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0021B7D0
 */

extern u32 Analyze(void);

/* Analyze @ 0x21B260 .. 0x21B53C (0x2dc bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x21b380
 *   fpu: mtc1 reinterprets v1 at 0x21b394
 *   fpu: float literal 0x447a0000 at 0x21b3a8
 *   fpu: mtc1 reinterprets v0 at 0x21b3cc
 *   fpu: mtc1 reinterprets v0 at 0x21b3f4
 *   fpu: mtc1 reinterprets v1 at 0x21b408
 *   fpu: float literal 0x447a0000 at 0x21b41c
 *   fpu: mtc1 reinterprets v0 at 0x21b440
 *   cfg: loop body is not one contiguous region: .L0021B2A0
 */

static u32 CalcText(u8 *a0 /* r4 */);
extern u32 DrawResText();



typedef struct {
    float x;
    float y;
} MmoVec2;


extern u32 GetSplinePrm[];
extern int Calc_Screen(s32, u8 *, u8 *, u8);

typedef struct FM_Col { u8 r, g, b, a; } FM_Col;

/* Calc_Screen @ 0x21A1E0 .. 0x21A448 (0x268 bytes, frame 0x70) */


typedef struct CS_Rect { float x, y, w, h; } CS_Rect;
typedef struct CS_U4 { u32 a, b, c, d; } CS_U4;
typedef struct CS_Key { u8 pad[0x10]; float s[4]; u8 pad2[0x10]; float e[4]; } CS_Key;

static inline void CS_Lerp(CS_Rect *out, u8 *key, s32 t0) {
    CS_Rect v;
    float (*fn)(u8 *, s32);
    float rate;
    CS_Key *k = (CS_Key *)key;

    fn = (float (*)(u8 *, s32))((u32 *)GetSplinePrm)[key[9]];
    if (fn != 0) {
        rate = fn(key, t0);
        v.x = k->s[0] + rate * (k->e[0] - k->s[0]);
        v.y = k->s[1] + rate * (k->e[1] - k->s[1]);
        v.w = k->s[2] + rate * (k->e[2] - k->s[2]);
        v.h = k->s[3] + rate * (k->e[3] - k->s[3]);
    }
    *(CS_U4 *)out = *(CS_U4 *)&v;
}
/* MmoFontReplaceUnicode @ 0x219C20 .. 0x219EF8 (0x2d8 bytes, frame 0x680) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x380 escapes at 0x219c78
 *   stack: address of the slot at 0x380 escapes at 0x219c88
 *   delay: addiu at 0x219cc8 writes a register its branch at 0x219cc4 reads
 *   delay: addiu at 0x219cf8 writes a register its branch at 0x219cf4 reads
 *   delay: addiu at 0x219d0c writes a register its branch at 0x219d08 reads
 *   delay: addiu at 0x219d20 writes a register its branch at 0x219d1c reads
 *   delay: addiu at 0x219d34 writes a register its branch at 0x219d30 reads
 *   delay: addiu at 0x219d48 writes a register its branch at 0x219d44 reads
 *   delay: addiu at 0x219d5c writes a register its branch at 0x219d58 reads
 *   delay: addiu at 0x219d70 writes a register its branch at 0x219d6c reads
 *   delay: addiu at 0x219d98 writes a register its branch at 0x219d94 reads
 *   delay: addiu at 0x219df0 writes a register its branch at 0x219dec reads
 *   cfg: kept goto: 0x219c70 -> .L00219ED0
 *   cfg: loop body is not one contiguous region: .L00219C88
 *   cfg: kept branch: 0x219c88 if (..) goto .L00219CB0
 *   cfg: kept goto: 0x219c9c -> .L00219E78
 *   cfg: kept branch: 0x219cb0 if (..) goto .L00219E70
 *   cfg: kept branch: 0x219cb8 if (..) goto .L00219CE8
 *   cfg: kept goto: 0x219ce0 -> .L00219E78
 *   cfg: kept goto: 0x219ce8 -> .L00219E78
 *   cfg: kept goto: 0x219dd8 -> .L00219E60
 *   cfg: kept goto: 0x219e28 -> .L00219E60
 *   cfg: kept goto: 0x219e38 -> .L00219E60
 *   cfg: kept goto: 0x219e40 -> .L00219E60
 *   cfg: kept goto: 0x219e48 -> .L00219E60
 *   cfg: kept goto: 0x219e50 -> .L00219E80
 *   cfg: kept goto: 0x219e60 -> .L00219E78
 *   a1 takes slot 1 only because of the ABI order
 */

extern u32 MmoFsCConvUTF16To8();
extern int vsprintf(char *, const char *, void *);
extern u32 MmoFsCConvUTF8To16(u8 *, u8 *);


/* MmoFontDrawRect: matched caller; preserve its register-forwarding call contract. */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x21995c is a float copy
 *   fpu: float literal 0x00000000 at 0x219980
 *   fpu: mov.s at 0x2199c4 is a float copy
 *   return without a value in a non-void function
 */

extern void _TransTextureFromFileInMemory();
static void _MakeDmaPacketSprite(u32, u32, u32, u32);
static void _MakeDmaPacketTriangleStrip(s32, u32, u32, u32, float);


extern void _SetDrawCondition();







/* MmoFsFontEnd @ 0x219730 .. 0x219824 (0xf4 bytes, frame 0x10) */

extern void _SendPacketByDma(void);





typedef struct {
    unsigned long dma : 1;
    unsigned long context : 1;
} MmoDrawFlags;

static inline u_long *MmoPkAD(u_long *p, u_long data, u_long addr) {
    *p++ = data;
    *p++ = addr;
    return p;
}

#define MMO_SYS (*(u8 **)s_pSysInfo)

#undef MMO_SYS






extern void FlushCache(int);






/* _MakeDmaPacketSprite @ 0x218CA0 .. 0x2193C8 (0x728 bytes, frame 0xb0) */
/*
 * dcomp notes:
 *   fpu: float literal 0x44a00000 at 0x218cb4
 *   fpu: float literal 0xc4200000 at 0x218d10
 *   fpu: float literal 0xc2c80000 at 0x218d2c
 *   fpu: float literal 0x44090000 at 0x218d48
 *   fpu: float literal 0x41800000 at 0x219070
 *   fpu: float literal 0x44d80000 at 0x2190c4
 *   fpu: float literal 0x4f000000 at 0x2190d8
 *   fpu: float literal 0x43600000 at 0x2191b4
 *   fpu: float literal 0x40000000 at 0x2191d4
 *   fpu: float literal 0x41800000 at 0x2191e4
 *   fpu: float literal 0x45000000 at 0x2191ec
 *   fpu: float literal 0x4f000000 at 0x219200
 *   fpu: float literal 0x41800000 at 0x219260
 *   fpu: float literal 0x44d80000 at 0x219264
 *   fpu: float literal 0x4f000000 at 0x21926c
 *   fpu: float literal 0x43600000 at 0x2192d4
 *   fpu: float literal 0x40000000 at 0x2192f4
 *   fpu: float literal 0x41800000 at 0x219304
 *   fpu: float literal 0x45000000 at 0x21930c
 *   fpu: float literal 0x4f000000 at 0x219320
 *   stack: 8-byte aggregate copy in 4-byte chunks at 0x219154
 *   stack: 8-byte aggregate copy in 4-byte chunks at 0x219278
 *   cfg: kept branch: 0x218d40 if (..) goto .L00218D68
 *   cfg: kept goto: 0x218e28 -> .L00218E48
 *   declaration vs inferred signature: return void vs inferred u32
 */

typedef struct {
    u32 mmo_vif_low;
    u32 mmo_vif_high;
} MmoSpriteVifPair;

static inline void *MmoSprite_PkVIFDirect(void *p) {
    u32 *words = p;
    MmoSpriteVifPair *pair;
    *words++ = 0;
    *words++ = 0;
    pair = (MmoSpriteVifPair *)words;
    pair->mmo_vif_low = 0;
    (pair++)->mmo_vif_high = 0x51000006;
    return pair;
}

static inline void *MmoSprite_PkDMA(void *p, u32 tagWord, u32 next) {
    u32 *words = p;
    u_long *tail;
    *words++ = tagWord;
    *words++ = next;
    tail = (u_long *)words;
    *tail++ = 0;
    return tail;
}

static inline void *MmoSprite_PkADFixed(void *p, u_long data, int addr) {
    u_long *words = p;
    *words++ = data;
    *(s_long *)words++ = addr;
    return words;
}

static inline void *MmoSprite_PkRGBAQ(void *p, u32 *color, float q) {
    u32 *w = p;
    *w++ = *color;
    *w++ = *(u32 *)&q;
    return w;
}

static inline void *MmoSprite_PkST(void *p, float s, float t) {
    float *q = p;
    *q++ = s;
    *q++ = t;
    return q;
}

static inline void *MmoSprite_XYZ(void *p, float x, float y) {
    float yy;
    u16 *xy = p;
    u32 *z;
    *(u32 *)s_pSysInfo = sCurrentP + 0x98;
    *xy++ = (u32)(16.0f * (1728.0f + x));
    yy = 224.0f - y;
    if (((struct { unsigned char pad : 3; unsigned char half : 1; } *)
         (*(u8 **)s_pSysInfo + 0x22))->half == 1) {
        yy /= 2.0f;
    }
    *xy++ = (u32)(16.0f * (2048.0f - yy));
    z = (u32 *)xy;
    *z++ = 0x1000000;
    return z;
}






/* _MakeDmaPacketTriangleStrip @ 0x218380 .. 0x218C9C (0x91c bytes, frame 0xc0) */

typedef struct {
    u32 mmo_vif_low;
    u32 mmo_vif_high;
} MmoStripVifPair;

static inline void *MmoStrip_PkVIFDirect(void *p) {
    u32 *words = p;
    MmoStripVifPair *pair;
    *words++ = 0;
    *words++ = 0;
    pair = (MmoStripVifPair *)words;
    pair->mmo_vif_low = 0;
    (pair++)->mmo_vif_high = 0x51000008;
    return pair;
}

static inline void *MmoStrip_PkDMA(void *p, u32 tagWord, u32 next) {
    u32 *words = p;
    u_long *tail;
    *words++ = tagWord;
    *words++ = next;
    tail = (u_long *)words;
    *tail++ = 0;
    return tail;
}

static inline void *MmoStrip_PkADFixed(void *p, u_long data, int addr) {
    u_long *words = p;
    *words++ = data;
    *(s_long *)words++ = addr;
    return words;
}

static inline void *MmoStrip_PkRGBAQ(void *p, u32 *color, float q) {
    u32 *w = p;
    *w++ = *color;
    *w++ = *(u32 *)&q;
    return w;
}

static inline void *MmoStrip_PkST(void *p, float s, float t) {
    float *q = p;
    *q++ = s;
    *q++ = t;
    return q;
}

static inline void *MmoStrip_XYZ(void *p, float x, float y) {
    float yy;
    u16 *xy = p;
    u32 *z;
    *(u32 *)s_pSysInfo = sCurrentP + 0x98;
    *xy++ = (u32)(16.0f * (1728.0f + x));
    yy = 224.0f - y;
    if (((struct { unsigned char pad : 3; unsigned char half : 1; } *)
         (*(u8 **)s_pSysInfo + 0x22))->half == 1) {
        yy /= 2.0f;
    }
    *xy++ = (u32)(16.0f * (2048.0f - yy));
    z = (u32 *)xy;
    *z++ = 0x1000000;
    return z;
}






typedef struct FileTexReg {
    u64 base:14;
    u64 width:6;
    u64 format:6;
    u64 logWidth:4;
    u64 logHeight:4;
    u64 unused:3;
    u64 clutBase:14;
    u64 clutFormat:4;
    u64 rest:9;
} FileTexReg;
extern void _TransTexture(void *, s32, s32, s32, u32, u32);










typedef struct {
    u32 mmo_tex_vif_low;
    u32 mmo_tex_vif_high;
} MmoTexVifPair;

static inline void *MmoTex_PkVIFDirect(void *p, u32 qwc) {
    u32 *words = p;
    MmoTexVifPair *pair;
    *words++ = 0;
    *words++ = 0;
    pair = (MmoTexVifPair *)words;
    pair->mmo_tex_vif_low = 0;
    (pair++)->mmo_tex_vif_high = 0x51000000 | qwc;
    return pair;
}

static inline void *MmoTex_PkAD(void *p, u_long data, int addr) {
    u_long *words = p;
    *words++ = data;
    *(s_long *)words++ = addr;
    return words;
}

static inline int MmoTex_CheckSpace(u32 qwc) {
    u32 currentSys = sCurrentP + 0x98;
    u8 *info;
    u32 *tag;
    qwc <<= 4;
    *(u32 *)s_pSysInfo = currentSys;
    info = *(u8 **)s_pSysInfo;
    if (*(u32 *)(info + 4) - (*(u32 *)(info + 8) - *(u32 *)info) < qwc) {
        if ((info[0x22] & 1) == 1) {
            if (((struct { unsigned char pad : 2; unsigned char overDraw : 1; } *)
                 (info + 0x22))->overDraw) {
                *(u32 *)s_pSysInfo = currentSys;
                tag = *(u32 **)(info + 0xc);
                tag[0] &= 0x8fffffff;
                if (((*(u8 **)s_pSysInfo)[0x22] & 1) == 0) {
                    tag[0] |= 0x60000000;
                } else {
                    tag[0] |= 0x70000000;
                }
                tag[1] = 0;
                _SendPacketByDma();
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    }
    return 0;
}

static inline void *MmoTex_PkDMA(void *p, u32 tagWord, u32 next) {
    u32 *words = p;
    u_long *tail;
    *words++ = tagWord;
    *words++ = next;
    tail = (u_long *)words;
    *tail++ = 0;
    return tail;
}

typedef struct _sceDmaTag {
    u_short qwc;
    u_char mark;
    u_char id;
    struct _sceDmaTag *next;
    u_int p[2];
} sceDmaTag __attribute__ ((aligned(16)));
float GetSlowEaseInPrm(u32 *a0 , s32 a1 );
float GetSlowEaseOutPrm(u32 *a0 , s32 a1 );



static u32 GetSplinePrm[5] = {
    (u32)&GetLinearPrm, (u32)&GetEaseInPrm, (u32)&GetEaseOutPrm, (u32)&GetSlowEaseInPrm,
    (u32)&GetSlowEaseOutPrm
};
static u32 s_aWorkBuffer[0x2000];
static u32 s_System[0x3d];
static u32 sMmoData[0x11];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void fsmmo_LoadTm2(TM2 *pTm2, u64 *tex0, u64 *tex1);
u32 fsmmo_GetMemorySize(u16 *a0);
u32 fsmmo_Initialize(u8 *a0 , s32 a1 );
u32 fsmmo_Exec(void);
float GetSlowEaseInPrm(u32 *a0 , s32 a1 );
float GetSlowEaseOutPrm(u32 *a0 , s32 a1 );
u32 MmoFontReplaceUnicode(u8 *a0 , s32 a1 , u32 *a2 );
u64 MmoFontDrawRect(s32 font, u8 *a1, u8 *a2, u8 *a3, float rot);
#define MMO_SYS (*(u8 **)s_pSysInfo)

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */



/* Font_Initialize @ 0x21C520 .. 0x21C634 (0x114 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: lui at 0x21c5d4 writes a register its branch at 0x21c5d0 reads
 *   return without a value in a non-void function
 */


u32 Font_Initialize(void) {
    u32 a0;
    u32 v0;
    u32 v1;
    u32 a1;
    s32 at;

    v0 = MmoFsFontInit((u32)((u8 *)s_System + 0x14));
    if (v0 != 0) {
        v1 = *(s32 *)s_System;
        if (v1 != 0) {
            a0 = (u32)s_System;
            memset((u32)s_System, 0, 0xf4);
        }
        return;
    }
    MmoFsFont_SetMode(0, (u32)1);
    MmoFsFont_SetMode((u32)2, (u32)1);
    MmoFsFont_SetMode((u32)1, 0);
    MmoFsFont_SetMode((u32)3, 0);
    MmoFsFont_SetMode((u32)4, (u32)1);
    v0 = MmoFsFont_GetDmaBufferSize(0x40, 0);
    s_System[0x3b] = v0;
    v1 = (u32)s_aWorkBuffer;
    s_System[0x3c] = (u32)s_aWorkBuffer;
    a1 = *(s32 *)(s_System + 0x3b);
    at = 0x8001;
    if (a1 > (u32)0x8000) {
        v1 = *(s32 *)s_System;
        if (v1 != 0) {
            a0 = (u32)s_System;
            memset((u32)s_System, 0, 0xf4);
        }
        return;
    }
    MmoFsFont_SetDmaBuffer((u8 *)*(s32 *)(s_System + 0x3c), a1);
    v0 = 0x7f7f0000;
    MmoFsFontSetBaseColor(0x7f7f0000 | 0x7f7f);
    *(u32 *)s_System = 1;
    return;
}

/* Font_SetTexture @ 0x21C4B0 .. 0x21C520 (0x70 bytes, frame 0x20) */


void Font_SetTexture(s32 a0 /* r4 */, u8 *a1 /* r5 */) {
    u32 s0;
    u8 *v1;
    u32 v0;

    s0 = (u32)a1;
    if ((u32)a0 != 0) {
        v1 = (u8 *)*(s32 *)(s_System + 0x15);
        if ((u32)(s32)v1 != 0) {
            v0 = *(s32 *)(v1 + 0x14);
            *(u32 *)(v1 + 0x14) = (s32)((u8 *)v0 - (u32)(v1));
            v0 = *(s32 *)(v1 + 0x18);
            *(u32 *)(v1 + 0x18) = (s32)((u8 *)v0 - (u32)(v1));
            s_System[0x15] = 0;
        }
        MmoFsFontSetCCMBuf(a0, a1);
        MmoFsFontSetTexBuf(0, s0);
    }
    return;
}

/* Font_Begin @ 0x21C460 .. 0x21C4A4 (0x44 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u32 Font_Begin(void) {
    u32 v1;

    v1 = *(u32 *)s_System;
    if (v1 != 0) {
        MmoFsFontSetCurrent((u8 *)((u8 *)s_System + 0x14));
        MmoFsFontBegin();
        v1 = 1;
        *(u32 *)((u8 *)&s_System + 4) = 1;
    }
    return;
}
/* Font_End @ 0x21C420 .. 0x21C454 (0x34 bytes, frame 0x10) */


void Font_End(void) {
    u32 v1;

    v1 = *(u32 *)s_System;
    if (v1 != 0) {
        MmoFsFontEnd();
        *(u32 *)((u8 *)&s_System + 4) = 0;
    }
    return;
}

/* Font_Print2Xy @ 0x21C3D0 .. 0x21C41C (0x4c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets a0 at 0x21c3f0
 *   fpu: mtc1 reinterprets a1 at 0x21c3f4
 */


void Font_Print2Xy(s32 a0 /* r4 */, s32 a1 /* r5 */, u8 *a2 /* r6 */) {
    u32 v1;
    float f12;
    float f13;

    v1 = *(s32 *)s_System;
    if (v1 != 0) {
        if ((u32)a2 != 0) {
            f12 = ((float)(s32)(u32)a0);
            f13 = ((float)(s32)(u32)a1);
            MmoFsFontDrawText((u32)a2, a1, (u32)a2, f12, f13);
        }
    }
    return;
}

/* Font_SetAlignment @ 0x21C3C0 .. 0x21C3C8 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j MmoFsFontSetAlignment at 0x21c3c0 leaves the function
 *   return value dropped, call kept: the function is void
 */


void Font_SetAlignment(u32 align) {
    MmoFsFontSetAlignment(align);
    return;
}

/* Font_SetMargin @ 0x21C3B0 .. 0x21C3B8 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j MmoFsFontSetMargin at 0x21c3b0 leaves the function
 *   return value dropped, call kept: the function is void
 */


void Font_SetMargin(float x, float y) {
    MmoFsFontSetMargin(x, y);
    return;
}

/* Font_GetSize @ 0x21C3A0 .. 0x21C3A8 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j MmoFsFontGetSize at 0x21c3a0 leaves the function
 *   a0 forwarded to MmoFsFontGetSize
 *   a1 forwarded to MmoFsFontGetSize
 *   a2 forwarded to MmoFsFontGetSize
 *   return value dropped, call kept: the function is void
 */


void Font_GetSize(u8 *a0 /* r4 */, u8 *a1 /* r5 */, s32 a2 /* r6 */) {
    MmoFsFontGetSize(a0, a1, a2, 0);
    return;
}

/* Font_GetPos @ 0x21C390 .. 0x21C398 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j MmoFsFontGetPos at 0x21c390 leaves the function
 *   return value dropped, call kept: the function is void
 */


void Font_GetPos(float *x, float *y) {
    MmoFsFontGetPos(x, y);
    return;
}

void fsmmo_DrawSprite(u8 *pos_, u8 *uv_, float *tex_) {
    float *pos = (float *)pos_;
    u32 *uv = (u32 *)uv_;
    u8 *tex = (u8 *)tex_;
    u_long *p;
    u32 qi;
    u_long128 packet[12];
    u_long tex0;
    float fq;
    u_long *d;
    u32 *q;
    MmoGifTag *tag;
    extern void fsmmo_LoadTm2();

    fq = 1.0f;
    qi = *(u32 *)&fq;
    p = (u_long *)packet;
    if (640.0f < pos[0] || 448.0f < pos[1] || pos[2] < 0.0f || pos[3] < 0.0f) {
        return;
    }
    while ((*(volatile u32 *)0x1000a000 & 0x100) != 0 ||
           (*(volatile u32 *)0x10003020 & 0xc00) != 0) { }
    fsmmo_LoadTm2(*(void **)(tex + 0x18), &tex0, 0);
    *p++ = 0x7000000b;
    *p++ = 0;
    tag = (MmoGifTag *)p;
    tag->NLOOP = 1;
    tag->EOP = 1;
    tag->pad = 0;
    tag->PRE = 1;
    tag->PRIM = 0x5e;
    tag->FLG = 0;
    tag->NREG = 10;
    tag->REGS = 0x52521eeeeeUL;
    d = (u_long *)(tag + 1);
    *d++ = 0;
    *d++ = 0x3f;
    *d++ = 5;
    *d++ = 8;
    *d++ = 0x71001;
    *d++ = 0x47;
    *d++ = 0x44;
    *d++ = 0x42;
    *d++ = tex0;
    *d++ = 6;
    q = (u32 *)d;
    q = MmoPk4(q, tex[0x40], tex[0x41], tex[0x42], tex[0x43]);
    q = MmoPk4(q, uv[0], uv[1], qi, 0);
    q = MmoPk4(q, (u32)(16.0f * (1728.0f + pos[0])), (u32)(16.0f * (1824.0f + pos[1])), 0x1000000, 0);
    q = MmoPk4(q, uv[2], uv[3], qi, 0);
    q = MmoPk4(q, (u32)(16.0f * (1728.0f + pos[2])), (u32)(16.0f * (1824.0f + pos[3])), 0x1000000, 0);
    while ((*(volatile u32 *)0x1000a000 & 0x100) != 0 ||
           (*(volatile u32 *)0x10003020 & 0xc00) != 0) { }
    FlushCache(0);
    *(volatile u32 *)0x1000a020 = 0;
    *(volatile u32 *)0x1000a010 = 0;
    *(volatile u32 *)0x1000a030 = (u32)packet;
    FlushCache(0);
    *(volatile u32 *)0x1000a000 = 0x145;
    while ((*(volatile u32 *)0x1000a000 & 0x100) != 0 ||
           (*(volatile u32 *)0x10003020 & 0xc00) != 0) { }
}

void fsmmo_LoadTm2(TM2 *pTm2, u64 *tex0, u64 *tex1) {
    sceGsLoadImage li;
    u16 w;
    u16 h;
    int m;

    w = 1 << pTm2->tex0.TW;
    h = 1 << pTm2->tex0.TH;
    if (pTm2->tex0.PSM == 0x13) {
        m = 2;
    } else if (pTm2->tex0.PSM == 0x1b) {
        m = 2;
    } else if (pTm2->tex0.PSM == 0x14) {
        m = 1;
    } else if (pTm2->tex0.PSM == 0x2c) {
        m = 1;
    } else if (pTm2->tex0.PSM == 0x24) {
        m = 1;
    } else {
        m = 8;
    }
    if (w * h * m >= 0x80000) {
        sceGsSetDefLoadImage(&li, pTm2->tex0.TBP0, pTm2->tex0.TBW, pTm2->tex0.PSM, 0, 0, w, h / 2);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u_long128 *)((u8 *)pTm2 + 0x20));
        _WAITSYNC();
        sceGsSetDefLoadImage(&li, pTm2->tex0.TBP0, pTm2->tex0.TBW, pTm2->tex0.PSM, 0, h / 2, w, h / 2);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u_long128 *)((u8 *)pTm2 + 0x20 + w * h * m / 4));
        _WAITSYNC();
    } else {
        sceGsSetDefLoadImage(&li, pTm2->tex0.TBP0, pTm2->tex0.TBW, pTm2->tex0.PSM, 0, 0, w, h);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u_long128 *)((u8 *)pTm2 + 0x20));
        _WAITSYNC();
    }
    if (pTm2->tex0.PSM == 0x13) {
        sceGsSetDefLoadImage(&li, pTm2->tex0.CBP, 1, pTm2->tex0.CPSM, 0, 0, 16, 16);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u_long128 *)((u8 *)pTm2 + 0x20 + pTm2->wnum));
        _WAITSYNC();
    } else if (pTm2->tex0.PSM == 0x1b) {
        sceGsSetDefLoadImage(&li, pTm2->tex0.CBP, 1, pTm2->tex0.CPSM, 0, 0, 16, 16);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u_long128 *)((u8 *)pTm2 + 0x20 + pTm2->wnum));
        _WAITSYNC();
    } else if (pTm2->tex0.PSM == 0x14) {
        sceGsSetDefLoadImage(&li, pTm2->tex0.CBP, 1, pTm2->tex0.CPSM, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u_long128 *)((u8 *)pTm2 + 0x20 + pTm2->wnum));
        _WAITSYNC();
    } else if (pTm2->tex0.PSM == 0x2c) {
        sceGsSetDefLoadImage(&li, pTm2->tex0.CBP, 1, pTm2->tex0.CPSM, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u_long128 *)((u8 *)pTm2 + 0x20 + pTm2->wnum));
        _WAITSYNC();
    } else if (pTm2->tex0.PSM == 0x24) {
        sceGsSetDefLoadImage(&li, pTm2->tex0.CBP, 1, pTm2->tex0.CPSM, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(&li, (u_long128 *)((u8 *)pTm2 + 0x20 + pTm2->wnum));
        _WAITSYNC();
    }
    if (tex0 != 0) {
        *tex0 = *(u64 *)&pTm2->tex0;
    }
    if (tex1 != 0) {
        *tex1 = *(u64 *)&pTm2->tex1;
    }
    return;
}


u32 fsmmo_GetMemorySize(u16 *a0) {
    u32 size = 0;
    size += *(u16 *)((u8 *)a0 + 8) * 0x90;
    return size;
}

u32 fsmmo_Initialize(u8 *a0 /* r4 */, s32 a1 /* r5 */) {
    s32 a2;
    u32 s1;
    u32 s0;
    s32 a1_2; // a1
    u32 v1;
    u8 *a0_2;
    u32 v0;

    a2 = 0x44;
    s1 = (u32)a0;
    s0 = a1;
    a0_2 = (u8 *)sMmoData;
    memset(sMmoData, 0, a2);
    if (s1 != 0 && s0) {
        v0 = 3;
        sMmoData[2] = s1;
        sMmoData[5] = s0;
        v1 = *(u8 *)((*(s32 *)(sMmoData + 2) + 0xb));
        switch (v1) {
        default:
            v0 = 0x41855555;
            sMmoData[1] = 0x41855555;
            break;
        case 1:
            v0 = 0x419fffff;
            sMmoData[1] = 0x419fffff;
            break;
        case 2:
            v0 = 0x42055555;
            sMmoData[1] = 0x42055555;
            break;
        case 3:
            v0 = 0x421fffff;
            sMmoData[1] = 0x421fffff;
        }
        v0 = *(s32 *)(sMmoData + 2);
        v1 = *(s32 *)((v0 + 0xc));
        if (v1 != 0) {
            a1_2 = v0 + v1;
            a2 = 0;
            a0_2 = (u8 *)sMmoData;
            do {
                v1 = *(s32 *)((a1_2 + 0x10));
                if (v1 != 0 && (u32)*(s32 *)a1_2 != 0) {
                    v0 = *(s32 *)(sMmoData + 2);
                    v0 = v0 + v1;
                    *(u32 *)(a0_2 + 0x1c) = v0;
                    *(u32 *)(a0_2 + 0x28) = *(s32 *)(sMmoData + 2) + *(s32 *)a1_2;
                }
                a2 = a2 + 1;
                v0 = a2 < (s32)3;
                a1_2 = a1_2 + 4;
                a0_2 = (u8 *)(a0_2 + 4);
            } while (v0 != 0);
            Font_Initialize();
        }
        sMmoData[0x10] = 0;
        v0 = Analyze();
    } else {
        v0 = -1;
    }
    return v0;
}

/* fsmmo_Exec @ 0x21B560 .. 0x21B6C8 (0x168 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x4f000000 at 0x21b598
 *   fpu: float literal 0x4f000000 at 0x21b654
 *   fpu: mov.s at 0x21b674 is a float copy
 *   cfg: kept branch: 0x21b588 if (..) goto .L0021B5E8
 *   cfg: kept goto: 0x21b5e0 -> .L0021B6B8
 *   cfg: loop body is not one contiguous region: .L0021B610
 */

u32 fsmmo_Exec(void) {
    u32 t;
    u32 v1;
    u32 *h;
    u32 *n;
    float f1;

    t = sMmoData[6];
    if (t != 0) {
        t = sMmoData[2];
        if (t != 0) {
            t = *(u32 *)(t + 4);
            f1 = *(float *)(sMmoData + 1);
            v1 = (u32)f1;
            if (v1 <= t) {
                goto ok;
            }
        }
    }
    t = -1;
    goto end;
ok:
    memset(sMmoData + 0xe, 0, 8);
    n = (u32 *)sMmoData[6];
    if (n != 0) {
        do {
            ((void (*)(u32 *))n[2])(n);
            if (n[7] == 0) {
                ((void (*)(u32 *))n[3])(n);
            }
            n = (u32 *)*n;
        } while (n != 0);
    }
    *(float *)sMmoData = *(float *)sMmoData + *(float *)(sMmoData + 1);
    v1 = (u32)*(float *)sMmoData;
    h = (u32 *)sMmoData[2];
    t = h[1];
    t = t < v1;
end:
    return t;
}

/* fsmmo_SetBlurNum @ 0x21B540 .. 0x21B55C (0x1c bytes) */


void fsmmo_SetBlurNum(s32 a0 /* r4 */) {
    if ((u32)a0 > (u32)8) {
        a0 = 8;
    }
    *(u32 *)((u8 *)&sMmoData + 0x40) = a0;
    return;
}

u32 Analyze(void) {
    u32 a0;
    u32 v1;
    u32 s2;
    u8 *s1;
    u32 s0;
    u32 v0;

    v1 = *(s32 *)(sMmoData + 2);
    v0 = v1 + 0x20;
    sMmoData[3] = v0;
    v0 = *(u16 *)((v1 + 8));
    s1 = (u8 *)*(s32 *)(sMmoData + 3);
    s2 = v0 + -1;
    if (v0 != 0) {
        do {
            v0 = *(s32 *)(sMmoData + 5);
            s0 = ((s32)v0 + 0xf) / 0x10 << 4;
            v0 = s0 + 0x80;
            sMmoData[5] = v0;
            if (s0 == 0) {
                s0 = 0;
            } else {
                memset(s0, 0, (s32)0x80);
                *(u32 *)((s0 + 4)) = (s32)s1;
            }
            if (s0 == 0) {
                break;
            }
            a0 = *(u8 *)(s1 + 4);
            v1 = 1;
            switch (a0) {
            case 2:
                v0 = (u32)CalcTexture;
                *(void **)((s0 + 8)) = (void *)CalcTexture;
                v0 = (u32)DrawResTexture;
                *(void **)((s0 + 0xc)) = (void *)DrawResTexture;
                *(u32 *)((s0 + 0x1c)) = v1;
                v1 = *(s32 *)((s0 + 4));
                v0 = *(s32 *)((v1 + 8));
                v0 = v1 + (u32)v0;
                *(u32 *)((s0 + 0x10)) = v0;
                if (*(s32 *)((*(s32 *)((s0 + 4)) + 0x10)) != 0) {
                    *(u32 *)((s0 + 0x18)) = *(s32 *)((s0 + 4)) + *(s32 *)((*(s32 *)((s0 + 4)) + 0x10));
                } else {
                    *(u32 *)((s0 + 0x18)) = 0;
                }
                v0 = *(u16 *)((*(s32 *)((s0 + 4)) + 0x20));
                *(f32 *)((s0 + 0x60)) = (float)v0 / 1000.0f;
                *(f32 *)((s0 + 0x50)) = (float)v0 / 1000.0f;
                v0 = *(s32 *)((s0 + 4));
                v1 = *(u16 *)((v0 + 0x20));
                v0 = *(u16 *)((v0 + 0x24));
                v0 = v1 + (u32)v0;
                *(f32 *)((s0 + 0x68)) = (float)(s32)v0 / 1000.0f;
                *(f32 *)((s0 + 0x58)) = (float)(s32)v0 / 1000.0f;
                v0 = *(u16 *)((*(s32 *)((s0 + 4)) + 0x22));
                *(f32 *)((s0 + 0x5c)) = (float)v0 / 1000.0f;
                *(f32 *)((s0 + 0x54)) = (float)v0 / 1000.0f;
                v0 = *(s32 *)((s0 + 4));
                v1 = *(u16 *)((v0 + 0x22));
                v0 = *(u16 *)((v0 + 0x26));
                v0 = v1 + (u32)v0;
                *(f32 *)((s0 + 0x6c)) = (float)(s32)v0 / 1000.0f;
                *(f32 *)((s0 + 0x64)) = (float)(s32)v0 / 1000.0f;
                break;
            case 0:
            case 1:
                v0 = (u32)CalcText;
                *(void **)((s0 + 8)) = (void *)CalcText;
                v0 = (u32)DrawResText;
                *(void **)((s0 + 0xc)) = (void *)DrawResText;
                v0 = 1;
                *(u32 *)((s0 + 0x1c)) = v0;
                v1 = *(s32 *)((s0 + 4));
                v0 = *(s32 *)((v1 + 8));
                v0 = v1 + (u32)v0;
                *(u32 *)((s0 + 0x10)) = v0;
                v1 = *(s32 *)((s0 + 4));
                v0 = *(s32 *)((v1 + 0xc));
                v0 = v1 + (u32)v0;
                *(u32 *)((s0 + 0x14)) = v0;
                v1 = *(s32 *)((s0 + 4));
                v0 = *(s32 *)((v1 + 0x10));
                v0 = v1 + (u32)v0;
                *(u32 *)((s0 + 0x18)) = v0;
            }
            v1 = *(s32 *)(sMmoData + 6);
            if (v1 == 0) {
                sMmoData[6] = s0;
            } else {
                v0 = *(s32 *)v1;
                if (v0 != 0) {
                    do {
                        v1 = v0;
                        v0 = *(s32 *)v0;
                    } while (v0 != 0);
                }
                *(u32 *)v1 = s0;
            }
            v0 = s2;
            s1 = (u8 *)(s1 + 0x40);
            s2 = s2 + -1;
        } while (v0 != 0);
    }
    v0 = *(s32 *)(sMmoData + 6);
    v0 = v0;
    v0 = v0 == (u32)0;
    v0 = -v0;
    return v0;
}

/* CalcTexture @ 0x21B0D0 .. 0x21B258 (0x188 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   fpu: float literal 0x4f000000 at 0x21b0e4
 *   stack: address of the slot at 0x20 escapes at 0x21b150
 *   stack: address of the slot at 0x3c escapes at 0x21b160
 *   stack: address of the slot at 0x58 escapes at 0x21b170
 *   stack: address of the slot at 0x74 escapes at 0x21b180
 *   return without a value in a non-void function
 */



static u32 CalcTexture(u8 *a0 /* r4 */) {
    u32 *a3;
    float f1;
    u8 *s0;
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    u8 *a0_2;
    u8 stackFrame_84[12] __attribute__((aligned(4)));
    u8 stackFrame_74[16] __attribute__((aligned(4)));
    u8 stackFrame_68[12] __attribute__((aligned(4)));
    u8 stackFrame_58[16] __attribute__((aligned(4)));
    u8 stackFrame_4C[12] __attribute__((aligned(4)));
    u8 stackFrame_3C[16] __attribute__((aligned(4)));
    u8 stackFrame_30[12] __attribute__((aligned(16)));
    u8 stackFrame_20[16] __attribute__((aligned(16)));

    f1 = *(float *)sMmoData;
    s0 = a0;
    v0 = fsmmo_Calc((u32)f1, (u8 *)*(s32 *)(s0 + 4), (u8 *)((u8 *)&stackFrame_20[0]));
    if (v0 == 0) {
        *(u32 *)(s0 + 0x1c) = 1;
    } else {
        *(u32 *)(s0 + 0x1c) = 0;
    }
    a0_2 = (u8 *)(s0 + 0x20);
    memcpy((void *)a0_2, (void *)((u8 *)&stackFrame_20[0]), 8);
    a0_2 = (u8 *)(s0 + 0x28);
    memcpy((void *)a0_2, (void *)((u8 *)&stackFrame_3C[0]), 8);
    a0_2 = (u8 *)(s0 + 0x30);
    memcpy((void *)a0_2, (void *)((u8 *)&stackFrame_58[0]), 8);
    a0_2 = (u8 *)(s0 + 0x38);
    memcpy((void *)a0_2, (void *)((u8 *)&stackFrame_74[0]), 8);
    a3 = (u32 *)((u8 *)&stackFrame_30[0]);
    a2 = (u32)((u8 *)&stackFrame_4C[0]);
    a0_2 = (u8 *)*(s32 *)a3;
    a1 = (u32)((u8 *)&stackFrame_68[0]);
    v1 = (u32)((u8 *)&stackFrame_84[0]);
    *(u8 *)(s0 + 0x40) = (s32)a0_2;
    a0_2 = (u8 *)*(s32 *)a3;
    *(u8 *)(s0 + 0x41) = (u32)a0_2 >> 8;
    a0_2 = (u8 *)*(s32 *)a3;
    *(u8 *)(s0 + 0x42) = (u32)a0_2 >> 0x10;
    a0_2 = (u8 *)*(s32 *)a3;
    *(u8 *)(s0 + 0x43) = (u32)a0_2 >> 0x18;
    a0_2 = (u8 *)*(s32 *)a2;
    *(u8 *)(s0 + 0x44) = (s32)a0_2;
    a0_2 = (u8 *)*(s32 *)a2;
    *(u8 *)(s0 + 0x45) = (u32)a0_2 >> 8;
    a0_2 = (u8 *)*(s32 *)a2;
    *(u8 *)(s0 + 0x46) = (u32)a0_2 >> 0x10;
    a0_2 = (u8 *)*(s32 *)a2;
    *(u8 *)(s0 + 0x47) = (u32)a0_2 >> 0x18;
    a0_2 = (u8 *)*(s32 *)a1;
    *(u8 *)(s0 + 0x48) = (s32)a0_2;
    a0_2 = (u8 *)*(s32 *)a1;
    *(u8 *)(s0 + 0x49) = (u32)a0_2 >> 8;
    a0_2 = (u8 *)*(s32 *)a1;
    *(u8 *)(s0 + 0x4a) = (u32)a0_2 >> 0x10;
    a0_2 = (u8 *)*(s32 *)a1;
    *(u8 *)(s0 + 0x4b) = (u32)a0_2 >> 0x18;
    a0_2 = (u8 *)*(s32 *)v1;
    *(u8 *)(s0 + 0x4c) = (s32)a0_2;
    a0_2 = (u8 *)*(s32 *)v1;
    *(u8 *)(s0 + 0x4d) = (u32)a0_2 >> 8;
    a0_2 = (u8 *)*(s32 *)v1;
    *(u8 *)(s0 + 0x4e) = (u32)a0_2 >> 0x10;
    v1 = *(s32 *)v1;
    *(u8 *)(s0 + 0x4f) = v1 >> 0x18;
    return;
}

/* CalcText @ 0x21AF60 .. 0x21B0C8 (0x168 bytes, frame 0xb0) */
/*
 * dcomp notes:
 *   fpu: float literal 0x4f000000 at 0x21af74
 *   stack: address of the slot at 0x40 escapes at 0x21aff0
 *   stack: address of the slot at 0x50 escapes at 0x21b0b0
 *   return without a value in a non-void function
 */

static u32 CalcText(u8 *a0 /* r4 */) {
    u32 a1;
    float f1;
    float f0;
    s32 s2;
    u32 v1;
    u32 v0;
    u8 *s1;
    u8 *s0;
    u8 *a0_2;
    u8 stackFrame_50[96] __attribute__((aligned(16)));
    u8 stackFrame_40[16] __attribute__((aligned(16)));

    f1 = *(float *)sMmoData;
    s0 = a0;
    a1 = *(s32 *)(s0 + 4);
    v0 = fsmmo_Calc((u32)f1, (u8 *)a1, (u8 *)((u8 *)&stackFrame_40[0]));
    v1 = 1;
    if (v0 == 0) {
        *(u32 *)(s0 + 0x1c) = v1;
    } else {
        *(u32 *)(s0 + 0x1c) = 0;
        v1 = *(s32 *)(s0 + 4);
        v1 = *(s8 *)((v1 + 0x2c));
        a0_2 = (u8 *)(s0 + 0x20);
        if (v1 != 0) {
            memcpy((void *)a0_2, (void *)((u8 *)&stackFrame_40[0]), 8);
        } else {
            a0_2 = (u8 *)*(s32 *)(s0 + 0x18);
            a0_2 = (u8 *)*(u16 *)a0_2;
            if ((u32)a0_2 == (u32)0xa) {
                f0 = *(float *)((u8 *)&stackFrame_40[0]);
                *(f32 *)(s0 + 0x20) = f0;
            } else {
                f0 = *(float *)(sMmoData + 0xe);
                *(f32 *)(s0 + 0x20) = f0;
            }
            f0 = *(float *)(sMmoData + 0xf);
            *(f32 *)(s0 + 0x24) = f0;
        }
        a0_2 = (u8 *)*(u8 *)(s0 + 0x34);
        v1 = (u32)((u32)(a0_2)) & 1;
        if (v1 == 0) {
            s2 = 0;
            *(u8 *)(s0 + 0x34) = (u32)((u32)(a0_2)) | 1;
            s1 = s0;
            do {
                a0_2 = (u8 *)(s1 + 0x40);
                memcpy((void *)a0_2, (void *)(s0 + 0x20), 8);
                s2 = s2 + 1;
                v1 = s2 < (s32)8;
                s1 = (u8 *)(s1 + 8);
            } while (v1 != 0);
        }
        a0_2 = ((u8 *)&stackFrame_50[0]);
        v1 = *(s32 *)a0_2;
        *(u8 *)(s0 + 0x30) = v1;
        v1 = *(s32 *)a0_2;
        *(u8 *)(s0 + 0x31) = v1 >> 8;
        v1 = *(s32 *)a0_2;
        *(u8 *)(s0 + 0x32) = v1 >> 0x10;
        v1 = *(s32 *)a0_2;
        *(u8 *)(s0 + 0x33) = v1 >> 0x18;
    }
    return;
}
/* DrawResTexture @ 0x21AEA0 .. 0x21AF54 (0xb4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x20 escapes at 0x21aeb8
 *   stack: address of the slot at 0x10 escapes at 0x21af00
 *   stack: address of the slot at 0x20 escapes at 0x21af40
 *   stack: address of the slot at 0x10 escapes at 0x21af40
 */


static void DrawResTexture(float *a0 /* r4 */) {
    float *a2;
    float f0;
    u8 *a1;
    u8 stackFrame_20[16] __attribute__((aligned(16))) = {0};

    a2 = a0;
    f0 = a2[8];
    *(f32 *)((u8 *)&stackFrame_20[0]) = f0;
    f0 = a2[9];
    ((f32 *)stackFrame_20)[1] = f0;
    f0 = a2[0xe];
    ((f32 *)stackFrame_20)[2] = f0;
    f0 = a2[0xf];
    ((f32 *)stackFrame_20)[3] = f0;
    {
        u8 stackFrame_10[16] __attribute__((aligned(16))) = {0};
        f0 = a2[0x14];
        a0 = (float *)((u8 *)&stackFrame_20[0]);
        a1 = ((u8 *)&stackFrame_10[0]);
        *(f32 *)((u8 *)&stackFrame_10[0]) = f0;
        f0 = a2[0x15];
        ((f32 *)stackFrame_10)[1] = f0;
        f0 = a2[0x1a];
        ((f32 *)stackFrame_10)[2] = f0;
        f0 = a2[0x1b];
        ((f32 *)stackFrame_10)[3] = f0;
        fsmmo_DrawSprite((u8 *)a0, a1, a2);
        return;
    }
}

u32 DrawResText(u8 *res) {
    MmoVec2 pos = {0};
    u32 tex;
    u32 align;
    u8 info;
    s32 i;
    u8 *text;
    float w;
    float h;

    ((float *)&pos)[0] = *(float *)(res + 0x20);
    ((float *)&pos)[1] = *(float *)(res + 0x24);
    tex = *(u32 *)(*(u8 **)(res + 4) + 0x20);
    align = 0;
    if (tex > 2) {
        tex = 2;
    }
    Font_Begin();
    Font_SetTexture(sMmoData[7 + tex], (u8 *)sMmoData[0xa + tex]);
    info = *(u8 *)(*(u8 **)(res + 4) + 5);
    switch (info & 0xf) {
    case 0:
        align |= 0x20;
        break;
    case 1:
        break;
    case 2:
        align |= 0x10;
        break;
    }
    switch ((info >> 4) & 0xf) {
    case 0:
        align |= 0x80;
        break;
    }
    Font_SetAlignment(align);
    Font_SetMargin(0.0f, 5.0f);
    if (**(u16 **)(res + 0x18) != 10) {
        w = 0.0f;
        h = 0.0f;
        text = *(u8 **)(res + 0x18);
        Font_GetSize((u8 *)&w, (u8 *)&h, (s32)text);
        if (640.0f < pos.x || pos.x + (float)(s32)w < 0.0f ||
            448.0f < pos.y || pos.y + (float)(s32)h < 0.0f) {
            Font_Print2Xy((s32)pos.x, (s32)pos.y, (u8 *)" ");
        } else {
            u8 col[4] = {0};
            u8 a;

            ((u8 *)&col)[0] = res[0x30];
            ((u8 *)&col)[1] = res[0x31];
            ((u8 *)&col)[2] = res[0x32];
            ((u8 *)&col)[3] = res[0x33];
            if (sMmoData[0x10] != 0) {
                a = col[3];
                col[3] = a / (u8)(sMmoData[0x10] + 1);
                MmoFsFontSetBaseColor(*(u32 *)col);
                for (i = sMmoData[0x10] - 1; i >= 0; i--) {
                    float p2[2] = {0};

                    p2[0] = pos.x;
                    p2[1] = pos.y;
                    if (i % 2 == 0) {
                        p2[1] += 0.8f * (float)((i + 2) / 2);
                        Font_Print2Xy((s32)p2[0], (s32)p2[1], text);
                    } else {
                        p2[1] -= 0.8f * (float)((i + 2) / 2);
                        Font_Print2Xy((s32)p2[0], (s32)p2[1], text);
                    }
                }
                col[3] = a - col[3] * sMmoData[0x10];
            }
            MmoFsFontSetBaseColor(*(u32 *)col);
            Font_Print2Xy((s32)pos.x, (s32)pos.y, text);
        }
        for (i = sMmoData[0x10] - 1; i >= 0; i--) {
            if (i == 0) {
                memcpy(res + 0x40, &pos, 8);
            } else {
                memcpy(res + 0x40 + i * 8, res + 0x40 + (i - 1) * 8, 8);
            }
        }
        Font_GetPos((float *)&sMmoData[0xe], (float *)&sMmoData[0xf]);
    } else {
        Font_Print2Xy((s32)pos.x, (s32)pos.y, *(u8 **)(res + 0x18));
        Font_GetPos((float *)&sMmoData[0xe], (float *)&sMmoData[0xf]);
        *(float *)&sMmoData[0xe] = pos.x;
    }
    Font_End();
}

u32 fsmmo_Calc(u32 t, u8 *obj, u8 *quad) {
    s32 i;
    u8 *k;
    u8 *cnt;
    u8 *p;
    FM_Col col2;
    FM_Col col;
    u8 *keys;
    float rate;
    u32 packed;
    u32 c0;
    u32 c1;
    float (*fn)(u8 *, u32);

    if (t < *(u32 *)(obj + 0x14)) {
        return 0;
    }
    t -= *(u32 *)(obj + 0x14);
    for (i = 0, p = obj, cnt = obj; i < 2; i++) {
        if (*(u32 *)(p + 8) != 0) {
            u32 n;
            keys = obj + *(u32 *)(p + 8);
            n = *(u16 *)cnt - 1;
            keys += 0x20;
            if (n != 0) {
                do {
                    if (t < *(u32 *)keys) {
                        break;
                    }
                    n--;
                    keys += 0x20;
                } while (n != 0);
            }
            if (n != 0) {
            if (keys[-0x18] == 1) {
                return 0;
            }
            if (i == 0) {
                Calc_Screen(t, keys - 0x20, quad, obj[5]);
            } else {
                k = keys - 0x20;
                fn = (float (*)(u8 *, u32))GetSplinePrm[keys[-0x17]];
                if (fn != 0) {
                    rate = fn(k, t);
                    c1 = k[0x3c];
                    c0 = k[0x1c];
                    col.r = (u32)((float)c0 + rate * ((float)c1 - (float)c0));
                    c1 = k[0x3d];
                    c0 = k[0x1d];
                    col.g = (u32)((float)c0 + rate * ((float)c1 - (float)c0));
                    c1 = k[0x3e];
                    c0 = k[0x1e];
                    col.b = (u32)((float)c0 + rate * ((float)c1 - (float)c0));
                    c1 = k[0x3f];
                    c0 = k[0x1f];
                    col.a = (u32)((float)c0 + rate * ((float)c1 - (float)c0));
                }
                *(FM_Col *)&col2 = col;
                packed = (col2.a << 24) | (col2.r << 16) | (col2.g << 8) | col2.b;
                *(u32 *)(quad + 0x64) = packed;
                *(u32 *)(quad + 0x48) = packed;
                *(u32 *)(quad + 0x2c) = packed;
                *(u32 *)(quad + 0x10) = packed;
            }
            } else {
                return 0;
            }
        }
        p += 4;
        cnt += 2;
    }
    return 1;
}

int Calc_Screen(s32 t, u8 *key, u8 *quad, u8 align) {
    CS_Rect r;
    CS_Lerp(&r, key, t);
    {
        CS_Rect rect = {0.0f, 0.0f, 0.0f, 0.0f};
        ((float *)&rect)[0] = ((float *)&r)[0];
        ((float *)&rect)[1] = ((float *)&r)[1];
        ((float *)&rect)[2] = ((float *)&r)[2];
        ((float *)&rect)[3] = ((float *)&r)[3];
        switch (align & 0xf) {
        case 1:
            break;
        default:
            rect.x = rect.x - rect.w / 2.0f;
            break;
        case 2:
            rect.x = rect.x - rect.w;
            break;
        }
        switch ((align >> 4) & 0xf) {
        case 1:
            break;
        default:
            rect.y = rect.y - rect.h / 2.0f;
            break;
        case 2:
            rect.y = rect.y - rect.h;
            break;
        }
        *(u32 *)(quad + 8) = *(u32 *)(quad + 0x24) = *(u32 *)(quad + 0x40) = *(u32 *)(quad + 0x5c) = 0;
        *(float *)(quad + 0xc) = *(float *)(quad + 0x28) = *(float *)(quad + 0x44) = *(float *)(quad + 0x60) = 1.0f;
        *(float *)(quad + 0) = *(float *)(quad + 0x38) = -0.5f + rect.x;
        *(float *)(quad + 0x1c) = *(float *)(quad + 0x54) = -0.5f + (rect.x + rect.w);
        *(float *)(quad + 4) = *(float *)(quad + 0x20) = -0.5f + rect.y;
        *(float *)(quad + 0x3c) = *(float *)(quad + 0x58) = -0.5f + (rect.y + rect.h);
    }
}

/* GetLinearPrm @ 0x21A150 .. 0x21A1D4 (0x84 bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x21a164
 *   fpu: mtc1 reinterprets v1 at 0x21a178
 *   fpu: mtc1 reinterprets v0 at 0x21a194
 *   fpu: mtc1 reinterprets v1 at 0x21a1a8
 */




static float GetLinearPrm(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 a2;
    u32 v0;

    a2 = *(s32 *)a0;
    v0 = *(s32 *)(((u8 *)a0 + 0x20));
    return ((float)(float)(u32)(a1 - a2) / (float)(float)(u32)(v0 - a2));
}

/* GetEaseInPrm @ 0x21A0C0 .. 0x21A14C (0x8c bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x21a0d4
 *   fpu: mtc1 reinterprets v1 at 0x21a0e8
 *   fpu: mtc1 reinterprets v0 at 0x21a104
 *   fpu: mtc1 reinterprets v1 at 0x21a118
 *   fpu: float literal 0x40000000 at 0x21a138
 *   return: mul.s at 0x21a148 computes the return value
 */




static float GetEaseInPrm(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 a2;
    u32 v0;
    float f1;
    float f0;

    a2 = *(s32 *)a0;
    v0 = *(s32 *)(((u8 *)a0 + 0x20));
    f0 = ((float)(float)(u32)(a1 - a2) / (float)(float)(u32)(v0 - a2));
    v0 = 0x40000000;
    f1 = 2.0f;
    f1 = (f1 - f0);
    return (f0 * f1);
}






/* GetEaseOutPrm @ 0x21A030 .. 0x21A0B4 (0x84 bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x21a044
 *   fpu: mtc1 reinterprets v1 at 0x21a058
 *   fpu: mtc1 reinterprets v0 at 0x21a074
 *   fpu: mtc1 reinterprets v1 at 0x21a088
 *   return: mul.s at 0x21a0b0 computes the return value
 */





static float GetEaseOutPrm(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 a2;
    u32 v0;
    float f0;

    a2 = *(s32 *)a0;
    v0 = *(s32 *)(((u8 *)a0 + 0x20));
    f0 = ((float)(float)(u32)(a1 - a2) / (float)(float)(u32)(v0 - a2));
    return (f0 * f0);
}


/* GetSlowEaseInPrm @ 0x219F90 .. 0x21A024 (0x94 bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x219fa4
 *   fpu: mtc1 reinterprets v1 at 0x219fb8
 *   fpu: mtc1 reinterprets v0 at 0x219fd4
 *   fpu: mtc1 reinterprets v1 at 0x219fe8
 *   fpu: float literal 0x40400000 at 0x21a008
 *   return: mul.s at 0x21a020 computes the return value
 */

float GetSlowEaseInPrm(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 a2;
    u32 v0;
    float f0;

    a2 = *(s32 *)a0;
    v0 = (s32)a0[8];
    f0 = ((float)(float)(u32)(a1 - a2) / (float)(float)(u32)(v0 - a2));
    v0 = 0x40400000;
    f0 = (f0 * (3.0f + (f0 * (f0 - 3.0f))));
    return f0;
}









/* GetSlowEaseOutPrm @ 0x219F00 .. 0x219F84 (0x84 bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x219f14
 *   fpu: mtc1 reinterprets v1 at 0x219f28
 *   fpu: mtc1 reinterprets v0 at 0x219f44
 *   fpu: mtc1 reinterprets v1 at 0x219f58
 *   return: mul.s at 0x219f80 computes the return value
 */

float GetSlowEaseOutPrm(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 a2;
    u32 v0;
    float f0;

    a2 = *(s32 *)a0;
    v0 = (s32)a0[8];
    f0 = ((float)(float)(u32)(a1 - a2) / (float)(float)(u32)(v0 - a2));
    f0 = (f0 * (f0 * f0));
    return f0;
}

u32 MmoFontReplaceUnicode(u8 *a0 /* r4 */, s32 a1 /* r5 */, u32 *a2 /* r6 */) {
    u32 s6;
    u8 *s4;
    u32 s3;
    u32 *s2;
    u32 s1;
    u32 s0;
    u8 *a0_2; // a0
    s32 v1;
    u32 v0;
    u32 *a2_2;
    u8 stackFrame_380[768] __attribute__((aligned(16)));
    u8 stackFrame_80[768] __attribute__((aligned(16)));

    s6 = (u32)a0;
    s3 = (u32)((u8 *)&stackFrame_380[0]);
    a0_2 = ((u8 *)&stackFrame_380[0]);
    s2 = a2;
    s1 = 0;
    s0 = 0;
    v0 = MmoFsCConvUTF16To8(a0_2, a1, a2);
    if ((s32)v0 < 0) {
        return -0xb;
    }
    s3 = s3 + v0;
    v0 = *(s8 *)((u8 *)&stackFrame_380[0]);
    s4 = ((u8 *)&stackFrame_380[0]);
    if (v0 != 0) {
        do {
            v0 = (s8)v0;
            v1 = 0x25;
            if (v0 != (u32)v1) {
                goto _L00219CB0;
            }
            v0 = s1 != 0;
            s0 = 0;
            s1 = v0 ^ 1;
            goto _L00219E78;
            _L00219CB0:;
            v1 = 0x68;
            if (s1 == 0) {
                goto _L00219E70;
            }
            if (v0 == (u32)v1) {
                goto _L00219CE8;
            }
            v1 = 0x4c;
            switch (v0) {
            case 108:
            case 76:
                s0 = 2;
                goto _L00219E78;
                _L00219CE8:;
                s0 = 1;
                goto _L00219E78;
            default:
                v1 = 0x47;
                switch (v0) {
                case 99:
                case 67:
                    v0 = s0 & 2;
                    if (v0 != 0) {
                        return -0xa;
                    }
                    a2 += 2;
                    v0 = 0x73;
                    *(u8 *)s4 = v0;
                    s0 = (s32)((u8 *)a2 + -8);
                    a0_2 = (u8 *)(s32)s3;
                    a1 = s0;
                    v0 = MmoFsCConvUTF16To8(a0_2, a1);
                    if ((s32)v0 < 0) {
                        v0 = -0xb;
                        return v0;
                    }
                    *(u32 *)s0 = s3;
                    s3 = s3 + v0;
                    goto _L00219E60;
                case 115:
                case 83:
                    v0 = s0 & 2;
                    if (v0 != 0) {
                        return -0xa;
                    }
                    a2 += 2;
                    a1 = (s32)a2[-2];
                    a0_2 = (u8 *)(s32)s3;
                    s0 = (s32)((u8 *)a2 + -8);
                    v0 = MmoFsCConvUTF16To8(a0_2, a1);
                    if ((s32)v0 < 0) {
                        v0 = -0xb;
                        return v0;
                    }
                    *(u32 *)s0 = s3;
                    s3 = s3 + v0;
                    goto _L00219E60;
                case 117:
                    a2 += 2;
                    goto _L00219E60;
                case 100:
                case 105:
                case 111:
                case 120:
                case 88:
                    a2 += 2;
                    goto _L00219E60;
                case 101:
                case 69:
                case 102:
                case 103:
                case 71:
                    a2 += 2;
                    goto _L00219E60;
                }
            }
            s0 = 0;
            s4 = (u8 *)(s4 + 1);
            goto _L00219E80;
            _L00219E60:;
            s0 = 0;
            s1 = 0;
            goto _L00219E78;
            _L00219E70:;
            s0 = 0;
            _L00219E78:;
            s4 = (u8 *)(s4 + 1);
            _L00219E80:;
            v0 = *(s8 *)s4;
        } while (v0 != 0);
    }
    a2_2 = s2;
    v0 = vsprintf((char *)((u8 *)&stackFrame_80[0]), (const char *)((u8 *)&stackFrame_380[0]),
        (void *)a2_2);
    if ((s32)v0 < 0) {
        return -9;
    }
    v0 = MmoFsCConvUTF8To16((u8 *)s6, ((u8 *)&stackFrame_80[0]));
    if ((s32)v0 < 0) {
        return -0xb;
    }
    return 0;
}





/* MmoFsFontSetRect @ 0x219C00 .. 0x219C14 (0x14 bytes) */




void MmoFsFontSetRect(float *a0 /* r4 */, float f12 /* f12 */, float f13 /* f13 */, float f14 /*
        f14 */, float f15 /* f15 */) {
    *(f32 *)a0 = f12;
    *(f32 *)(((u8 *)a0 + 4)) = f13;
    *(f32 *)(((u8 *)a0 + 8)) = f14;
    *(f32 *)(((u8 *)a0 + 0xc)) = f15;
    return;
}

/* MmoFsFont_GetDmaBufferSize @ 0x219B80 .. 0x219BF8 (0x78 bytes) */
/*
 * dcomp notes:
 *   return: sll at 0x219bf4 computes the return value
 */

u32 MmoFsFont_GetDmaBufferSize(s32 a0 /* r4 */, u32 a1 /* r5 */) {
    s32 a3;
    s32 a2;
    u32 v1;
    u32 v0;

    v0 = sCurrentP;
    a3 = 0xb;
    a2 = 0;
    *(u32 *)s_pSysInfo = v0 + 0x98;
    if (a1 == 0) {
        a2 = a2 + 7;
    } else {
        a2 = a2 + 9;
    }
    v0 = *(s32 *)s_pSysInfo;
    v1 = v0 + 0x22;
    v0 = *(u8 *)((v0 + 0x22));
    if ((u32)(v0 & 1) == 0) {
        a2 = a2 + 1;
        a3 = a3 + 2;
    }
    v1 = *(u8 *)v1;
    if ((u64)((u64)((u64)v1 << 0x3b) >> 0x3f) == (u64)(u32)1) {
        a2 = a2 + a3;
    }
    a2 *= (u32)a0;
    return (u32)(a2 + 5) << 4;
}
/* MmoFsFont_SetDmaBuffer @ 0x219B10 .. 0x219B7C (0x6c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u32 MmoFsFont_SetDmaBuffer(u8 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 s1;
    u32 v0;
    u32 s0;
    u32 *v1;

    s1 = (u32)a0;
    v0 = sCurrentP;
    s0 = a1;
    a0 = (u8 *)(s32)1;
    *(u32 *)s_pSysInfo = v0 + 0x98;
    v0 = MmoFsFont_GetDmaBufferSize((s32)a0, 0);
    if (s0 < v0) {
        s1 = 0;
        s0 = 0;
    }
    v1 = (u32 *)*(s32 *)s_pSysInfo;
    *(u32 *)v1 = s1;
    v1 = (u32 *)*(s32 *)s_pSysInfo;
    *(u32 *)(((u8 *)v1 + 4)) = s0;
    return;
}


/* MmoFsFont_SetMode @ 0x2199F0 .. 0x219B08 (0x118 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x219a10 writes a register its branch at 0x219a0c reads
 *   declaration vs inferred signature: 0 parameters vs 2 inferred
 */

void MmoFsFont_SetMode(a0, a1)
    u8 a0;
    s32 a1; {
    u32 a2;
    u32 v1;

    a2 = sCurrentP;
    v1 = 4;
    a2 = a2 + 0x98;
    *(u32 *)s_pSysInfo = a2;
    switch ((u32)a0) {
    case 0:
        a2 = *(s32 *)s_pSysInfo;
        ((struct { unsigned char f:1; } *)&*(u8 *)((a2 + 0x22)))->f = a1 & 1;
        break;
    case 1:
        a2 = *(s32 *)s_pSysInfo;
        ((struct { unsigned char _pad:1; unsigned char f:1; } *)&*(u8 *)((a2 + 0x22)))->f = a1 & 1;
        break;
    case 2:
        a2 = *(s32 *)s_pSysInfo;
        ((struct { unsigned char _pad:2; unsigned char f:1; } *)&*(u8 *)((a2 + 0x22)))->f = a1 & 1;
        break;
    case 3:
        a2 = *(s32 *)s_pSysInfo;
        ((struct { unsigned char _pad:3; unsigned char f:1; } *)&*(u8 *)((a2 + 0x22)))->f = a1 & 1;
        break;
    case 4:
        a2 = *(s32 *)s_pSysInfo;
        ((struct { unsigned char _pad:4; unsigned char f:1; } *)&*(u8 *)((a2 + 0x22)))->f = a1 & 1;
    }
    return;
}

u64 MmoFontDrawRect(s32 font, u8 *a1, u8 *a2, u8 *a3, float rot) {
    s32 tex;

    *(u32 *)s_pSysInfo = sCurrentP + 0x98;
    tex = ((s32 *)sCurrentP)[font];
    *(u32 *)s_pSysInfo = sCurrentP + 0x98;
    if (((struct { unsigned char _pad:4; unsigned char f:1; } *)(*(s32 *)s_pSysInfo + 0x22))->f && *(u8 *)(*(s32 *)s_pSysInfo + 0x23) != font) {
        _TransTextureFromFileInMemory(tex, a1, a2, a3);
        *(u8 *)(*(s32 *)s_pSysInfo + 0x23) = font;
    }
    if (0.0f == rot) {
        _MakeDmaPacketSprite(font, (u32)a1, (u32)a2, (u32)a3);
    } else {
        _MakeDmaPacketTriangleStrip(font, (u32)a1, (u32)a2, (u32)a3, rot);
    }
}

u32 MmoFsFontBegin(void) {
    u32 a0;
    u32 v1;
    u32 v0;
    u32 *p;

    v0 = sCurrentP;
    *(u32 *)s_pSysInfo = (u32)v0 + 0x98;
    a0 = *(s32 *)s_pSysInfo;
    v1 = *(u16 *)((a0 + 0x3e));
    *(u16 *)((a0 + 0x3e)) = v1 + 1;
    if (v1 != 0) {
        v0 = 0;
    } else {
        a0 = sCurrentP;
        v0 = 0x20000000;
        *(u32 *)s_pSysInfo = a0 + 0x98;
        a0 = *(s32 *)(((u8 *)(u32 *)*(s32 *)s_pSysInfo + 0x10));
        *(u32 *)(((u8 *)(u32 *)*(s32 *)s_pSysInfo + 0x18)) = a0;
        a0 = *(s32 *)s_pSysInfo;
        *(u16 *)((a0 + 0x20)) = 0;
        a0 = sCurrentP;
        *(u32 *)s_pSysInfo = a0 + 0x98;
        a0 = *(s32 *)(u32 *)*(s32 *)s_pSysInfo;
        *(u32 *)(((u8 *)(u32 *)*(s32 *)s_pSysInfo + 8)) = a0;
        a0 = *(s32 *)(((u8 *)(u32 *)*(s32 *)s_pSysInfo + 8));
        *(u32 *)(((u8 *)(u32 *)*(s32 *)s_pSysInfo + 0xc)) = a0;
        p = (u32 *)*(s32 *)((*(s32 *)s_pSysInfo + 8));
        *p++ = 0x20000000;
        *p++ = 0;
        *(u64 *)p = 0;
        *(u16 *)(*(u32 *)s_pSysInfo + 0x1c) = 0;
        *(u8 *)(*(u32 *)s_pSysInfo + 0x23) = 0xff;
        *(u16 *)(*(u32 *)s_pSysInfo + 0x1e) = 0;
        _SetDrawCondition();
        v0 = 0;
    }
    return v0;
}

u32 MmoFsFontEnd(void) {
    u8 *a0;
    u32 v1;
    u32 v0;

    v0 = sCurrentP;
    *(u32 *)s_pSysInfo = (u32)v0 + 0x98;
    v0 = *(s32 *)s_pSysInfo;
    v1 = v0 + 0x3e;
    v0 = *(u16 *)((v0 + 0x3e));
    if (v0 == 0) {
        v0 = 0;
    } else {
        v0 = v0 + -1;
        *(u16 *)v1 = v0;
        v0 = (u16)v0;
        if ((s32)v0 > 0) {
            v0 = 0;
        } else {
            v1 = sCurrentP;
            v0 = -0x70000001;
            *(u32 *)s_pSysInfo = (u32)v1 + 0x98;
            v1 = *(s32 *)s_pSysInfo;
            a0 = (u8 *)*(s32 *)((v1 + 0xc));
            v1 = *(s32 *)a0;
            *(u32 *)a0 = v1 & -0x70000001;
            v0 = *(s32 *)s_pSysInfo;
            v0 = *(u8 *)((v0 + 0x22));
            if ((u32)(v0 & 1) == 0) {
                v1 = *(s32 *)a0;
                v0 = 0x60000000;
                *(u32 *)a0 = v1 | 0x60000000;
            } else {
                v1 = *(s32 *)a0;
                v0 = 0x70000000;
                *(u32 *)a0 = v1 | 0x70000000;
            }
            *(u32 *)(a0 + 4) = 0;
            v1 = *(u8 *)(((u8 *)(u8 *)*(s32 *)s_pSysInfo + 0x22));
            if ((u32)(v1 & 1) == (u32)1 && (s32)*(u16 *)(((u8 *)(u8 *)*(s32 *)s_pSysInfo + 0x1c)) >
                0) {
                _SendPacketByDma();
            }
            v0 = 0;
        }
    }
    return v0;
}

static void _SetDrawCondition(void) {
    u32 qwc;
    u8 *sys;
    u32 *q;
    u_long *p;
    u32 *base;
    MmoGifTag *tag;
    u_long *d;
    u_long128 pre;

    *(u32 *)s_pSysInfo = sCurrentP + 0x98;
    qwc = 4;
    if (*(u32 *)MMO_SYS != 0) {
        base = *(u32 **)(MMO_SYS + 8);
        if (!((MmoDrawFlags *)(MMO_SYS + 0x22))->dma) {
            qwc++;
        }
        *(u32 **)(MMO_SYS + 0xc) = base;
        q = base;
        *q++ = (u16)qwc | 0x20000000;
        *q++ = (u32)base + ((qwc + 1) << 4);
        *(u_long *)q = 0;
        p = (u_long *)q + 1;
        if (!((MmoDrawFlags *)(MMO_SYS + 0x22))->dma) {
            q = (u32 *)p;
            *q++ = 0;
            *q++ = 0;
            *q++ = 0;
            *q++ = 0x51000004;
            p = (u_long *)q;
        }
        tag = (MmoGifTag *)p;
        tag->NLOOP = 3;
        tag->EOP = 1;
        tag->pad = 0;
        pre = 0;
        tag->PRE = pre ? 1 : 0;
        tag->PRIM = 0;
        tag->FLG = 0;
        tag->NREG = 1;
        tag->REGS = 0xe;
        d = (u_long *)(tag + 1);
        sys = MMO_SYS;
        d = MmoPkAD(d, 5, ((MmoDrawFlags *)(sys + 0x22))->context ? 9 : 8);
        d = MmoPkAD(d, 0x31001, ((MmoDrawFlags *)(sys + 0x22))->context ? 0x48 : 0x47);
        d = MmoPkAD(d, 0x44, ((MmoDrawFlags *)(sys + 0x22))->context ? 0x43 : 0x42);
        *(u_long **)(sys + 8) = d;
    }
}

static void _SendPacketByDma(void) {
    u32 *p;
    u32 v1;
    u32 v0;

    v0 = sCurrentP;
    *(u32 *)s_pSysInfo = v0 + 0x98;
    do {
        v0 = *(volatile s32 *)0x1000a000;
        v0 = v0 & 0x100;
    } while (v0 != 0 || (u32)(*(volatile s32 *)0x10003020 & 0xc00) != 0);
    *(volatile u32 *)0x1000a020 = 0;
    *(volatile u32 *)0x1000a010 = 0;
    v0 = *(s32 *)*(s32 *)s_pSysInfo;
    *(volatile u32 *)0x1000a030 = v0;
    FlushCache(0);
    *(volatile u32 *)0x1000a000 = 0x145;
    do {
        v1 = *(volatile s32 *)0x1000a000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x10003020 & 0xc00) != 0);
    *(u32 *)s_pSysInfo = sCurrentP + 0x98;
    ((u32 *)*(u32 *)s_pSysInfo)[2] = ((u32 *)*(u32 *)s_pSysInfo)[0];
    ((u32 *)*(u32 *)s_pSysInfo)[3] = ((u32 *)*(u32 *)s_pSysInfo)[2];
    p = (u32 *)((u32 *)*(u32 *)s_pSysInfo)[2];
    *p++ = 0x20000000;
    *p++ = 0;
    *(u64 *)p = 0;
    *(u16 *)(*(u32 *)s_pSysInfo + 0x1c) = 0;
    *(u8 *)(*(u32 *)s_pSysInfo + 0x23) = 0xff;
}

static void _MakeDmaPacketSprite(u32 a0 /* r4 */, u32 a1 /* r5 */, u32 a2 /* r6 */, u32 a3 /* r7 */) {
    u32 t9;
    float f4;
    s32 fp;
    s32 s7;
    u32 *s5;
    s32 t8;
    u32 t7;
    float *s4;
    float f3;
    float *s3;
    u32 t6;
    u32 s2;
    u32 t4;
    u64 a0_64;
    s32 t3;
    u32 t2;
    u64 t2_64;
    u64 a1_64;
    u32 t0;
    u64 t1_64;
    u64 t7_64;
    u8 *s1;
    u64 a2_64;
    u32 s0;
    u64 t3_64;
    u64 a3_64;
    u64 v1_64;
    u64 t5_64;
    u64 t4_64;
    u32 v1;
    u64 t0_64;
    u64 t6_64;
    u32 v0;
    float f1;
    float f0;
    u32 a1_2;
    u32 a2_2;
    u32 a3_2;
    volatile u32 uiPrim;
    u_long regs;
    MmoGifTag *packetTag;
    MmoGifTag *spriteTag;
    u_long textureReg;
    u8 *packetSys;
    void *pDmaCur;
    struct __copy_float_2 { float b[2]; };

    a0 = a0 << 2;
    s5 = (u32 *)(s32)a2;
    s4 = (float *)(s32)a1;
    s3 = (float *)(s32)a3;
    a2_2 = sCurrentP;
    a0 = a2_2 + (u32)a0;
    v1 = a2_2 + 0x98;
    s1 = (u8 *)*(s32 *)a0;
    *(u32 *)s_pSysInfo = v1;
    s2 = 6;
    if (1280.0f < s4[0] || s4[2] < -640.0f || s4[1] < -100.0f || 548.0f < s4[3]) {
        return;
    }
    a0 = *(u8 *)((*(s32 *)s_pSysInfo + 0x22));
    a0 = a0 & 1;
    if (a0 == 0) {
        s2 = s2 + 1;
    }
    *(u32 *)s_pSysInfo = (u32)v1;
    a3_2 = *(s32 *)s_pSysInfo;
    a0 = s2 + 1;
    s0 = a0 << 4;
    a0 = *(u32 *)(a3_2 + 4) - (*(u32 *)(a3_2 + 8) - *(u32 *)a3_2);
    if (a0 < s0) {
        a2_2 = *(u8 *)((a3_2 + 0x22));
        a0 = 1;
        a1_2 = a2_2 & 1;
        if (a1_2 == a0) {
            if (((struct { unsigned char pad : 2; unsigned char overDraw : 1; } *)
                 (a3_2 + 0x22))->overDraw) {
                *(u32 *)s_pSysInfo = v1;
                a0 = *(s32 *)((a3_2 + 0xc));
                v0 = -0x70000001;
                v1 = *(s32 *)a0;
                v0 = v1 & -0x70000001;
                *(u32 *)a0 = v0;
                v0 = *(u8 *)((*(s32 *)s_pSysInfo + 0x22));
                v0 = v0 & 1;
                if (v0 == 0) {
                    v1 = *(s32 *)a0;
                    v0 = 0x60000000;
                    v0 = v1 | 0x60000000;
                    *(u32 *)a0 = v0;
                } else {
                    v1 = *(s32 *)a0;
                    v0 = 0x70000000;
                    v0 = v1 | 0x70000000;
                    *(u32 *)a0 = v0;
                }
                *(u32 *)((a0 + 4)) = 0;
                _SendPacketByDma();
                goto _L00218E48;
            } else {
                v1 = -1;
            }
        } else {
            v1 = -1;
        }
    } else {
        _L00218E48:;
        v1 = 0;
    }
    if (v1 == 0) {
        pDmaCur = *(void **)(*(u8 **)s_pSysInfo + 8);
        *(void **)(*(u8 **)s_pSysInfo + 0xc) = pDmaCur;
        pDmaCur = MmoSprite_PkDMA(pDmaCur, (u16)s2 | 0x20000000,
                                 (u32)pDmaCur + s0);
        if (!((MmoDrawFlags *)(*(u8 **)s_pSysInfo + 0x22))->dma) {
            pDmaCur = MmoSprite_PkVIFDirect(pDmaCur);
        }
        uiPrim = ((long)((MmoDrawFlags *)(*(u8 **)s_pSysInfo + 0x22))->context << 9) | 0x5e;
        packetTag = (MmoGifTag *)pDmaCur;
        packetTag->NLOOP = 1;
        packetTag->EOP = 0;
        packetTag->pad = 0;
        packetTag->PRE = 1;
        packetTag->PRIM = uiPrim & 0x7ff;
        packetTag->FLG = 0;
        packetTag->NREG = 1;
        packetTag->REGS = 0xe;
        spriteTag = (MmoGifTag *)((u8 *)packetTag + 16);
        packetSys = *(u8 **)s_pSysInfo;
        textureReg = *(u_long *)(s1 + 0x18);
        spriteTag = MmoSprite_PkADFixed(spriteTag, textureReg,
                                     ((MmoDrawFlags *)(packetSys + 0x22))->context ? 0x15 : 0x14);
        regs = 0x525210;
        if (!((MmoDrawFlags *)(packetSys + 0x22))->context) {
            regs |= 6;
        } else {
            regs |= 7;
        }
        {
            u_long128 pre = 0;
            spriteTag->NLOOP = 1;
            spriteTag->EOP = 1;
            spriteTag->pad = 0;
            spriteTag->PRE = pre ? 1 : 0;
            spriteTag->PRIM = 0;
            spriteTag->FLG = 1;
            spriteTag->NREG = 6;
            spriteTag->REGS = regs;
        }
        pDmaCur = (u8 *)(spriteTag + 1);
        *(u_long *)pDmaCur = *(u_long *)(s1 + 0x10);
        pDmaCur = (u8 *)pDmaCur + 8;
        pDmaCur = MmoSprite_PkRGBAQ(pDmaCur, s5, 1.0f);
        pDmaCur = MmoSprite_PkST(pDmaCur, s3[0], s3[1]);
        pDmaCur = MmoSprite_XYZ(pDmaCur, s4[0], s4[1]);
        pDmaCur = MmoSprite_PkST(pDmaCur, s3[2], s3[3]);
        pDmaCur = MmoSprite_XYZ(pDmaCur, s4[2], s4[3]);
        *(void **)(*(u8 **)s_pSysInfo + 8) = pDmaCur;
        v1 = *(u16 *)(((u32)*(s32 *)s_pSysInfo + 0x1e));
        v1 = v1 + 1;
        *(u16 *)(((u32)*(s32 *)s_pSysInfo + 0x1e)) = v1;
        v1 = *(u16 *)(((u32)*(s32 *)s_pSysInfo + 0x1c));
        v1 = v1 + 1;
        *(u16 *)(((u32)*(s32 *)s_pSysInfo + 0x1c)) = v1;
    }
    return;
}

static void _MakeDmaPacketTriangleStrip(s32 texID, u32 a1 /* r5 */, u32 a2 /* r6 */, u32 a3 /* r7 */, float f12) {
    u32 currentSys;
    u32 a0;
    u32 t9;
    float f4;
    s32 fp;
    s32 s7;
    u32 *s5;
    s32 t8;
    u32 t7;
    float *s4;
    float f3;
    float *s3;
    u32 t6;
    u32 s2;
    u32 t4;
    u64 a0_64;
    s32 t3;
    u32 t2;
    u64 t2_64;
    u64 a1_64;
    u32 t0;
    u64 t1_64;
    u64 t7_64;
    u8 *s1;
    u64 a2_64;
    u32 s0;
    u64 t3_64;
    u64 a3_64;
    u64 v1_64;
    u64 t5_64;
    u64 t4_64;
    u32 v1;
    u64 t0_64;
    u64 t6_64;
    u32 v0;
    float f1;
    float f0;
    u32 a1_2;
    u32 a2_2;
    u32 a3_2;
    volatile u32 uiPrim;
    u_long regs;
    MmoGifTag *packetTag;
    MmoGifTag *spriteTag;
    u_long textureReg;
    u8 *packetSys;
    float f20;
    void *pDmaCur;
    struct __copy_float_2 { float b[2]; };

    texID = (u32)texID << 2;
    s5 = (u32 *)(s32)a2;
    s4 = (float *)(s32)a1;
    s3 = (float *)(s32)a3;
    s2 = 8;
    v1 = sCurrentP;
    a0 = v1 + texID;
    s1 = (u8 *)*(s32 *)a0;
    currentSys = v1 + 0x98;
    *(u32 *)s_pSysInfo = currentSys;
    a0 = *(u8 *)((*(s32 *)s_pSysInfo + 0x22));
    a0 = a0 & 1;
    f20 = (float)f12;
    if (a0 == 0) {
        s2 = s2 + 1;
    }
    *(u32 *)s_pSysInfo = currentSys;
    a3_2 = *(s32 *)s_pSysInfo;
    a0 = s2 + 1;
    s0 = a0 << 4;
    a0 = *(u32 *)(a3_2 + 4) - (*(u32 *)(a3_2 + 8) - *(u32 *)a3_2);
    if (a0 < s0) {
        a2_2 = *(u8 *)((a3_2 + 0x22));
        a0 = 1;
        a1_2 = a2_2 & 1;
        if (a1_2 == a0) {
            if (((struct { unsigned char pad : 2; unsigned char overDraw : 1; } *)
                 (a3_2 + 0x22))->overDraw) {
                *(u32 *)s_pSysInfo = currentSys;
                a0 = *(s32 *)((a3_2 + 0xc));
                v0 = -0x70000001;
                v1 = *(s32 *)a0;
                v0 = v1 & -0x70000001;
                *(u32 *)a0 = v0;
                v0 = *(u8 *)((*(s32 *)s_pSysInfo + 0x22));
                v0 = v0 & 1;
                if (v0 == 0) {
                    v1 = *(s32 *)a0;
                    v0 = 0x60000000;
                    v0 = v1 | 0x60000000;
                    *(u32 *)a0 = v0;
                } else {
                    v1 = *(s32 *)a0;
                    v0 = 0x70000000;
                    v0 = v1 | 0x70000000;
                    *(u32 *)a0 = v0;
                }
                *(u32 *)((a0 + 4)) = 0;
                _SendPacketByDma();
                goto _L00218E48;
            } else {
                v1 = -1;
            }
        } else {
            v1 = -1;
        }
    } else {
        _L00218E48:;
        v1 = 0;
    }
    if (v1 == 0) {
        pDmaCur = *(void **)(*(u8 **)s_pSysInfo + 8);
        *(void **)(*(u8 **)s_pSysInfo + 0xc) = pDmaCur;
        pDmaCur = MmoStrip_PkDMA(pDmaCur, (u16)s2 | 0x20000000,
                                 (u32)pDmaCur + s0);
        if (!((MmoDrawFlags *)(*(u8 **)s_pSysInfo + 0x22))->dma) {
            pDmaCur = MmoStrip_PkVIFDirect(pDmaCur);
        }
        uiPrim = ((long)((MmoDrawFlags *)(*(u8 **)s_pSysInfo + 0x22))->context << 9) | 0x5c;
        packetTag = (MmoGifTag *)pDmaCur;
        packetTag->NLOOP = 1;
        packetTag->EOP = 0;
        packetTag->pad = 0;
        packetTag->PRE = 1;
        packetTag->PRIM = uiPrim & 0x7ff;
        packetTag->FLG = 0;
        packetTag->NREG = 1;
        packetTag->REGS = 0xe;
        spriteTag = (MmoGifTag *)((u8 *)packetTag + 16);
        packetSys = *(u8 **)s_pSysInfo;
        textureReg = *(u_long *)(s1 + 0x18);
        spriteTag = MmoStrip_PkADFixed(spriteTag, textureReg,
                                     ((MmoDrawFlags *)(packetSys + 0x22))->context ? 0x15 : 0x14);
        regs = 0x5252525210;
        if (!((MmoDrawFlags *)(packetSys + 0x22))->context) {
            regs |= 6;
        } else {
            regs |= 7;
        }
        {
            u_long128 pre = 0;
            spriteTag->NLOOP = 1;
            spriteTag->EOP = 1;
            spriteTag->pad = 0;
            spriteTag->PRE = pre ? 1 : 0;
            spriteTag->PRIM = 0;
            spriteTag->FLG = 1;
            spriteTag->NREG = 10;
            spriteTag->REGS = regs;
        }
        pDmaCur = (u8 *)(spriteTag + 1);
        *(u_long *)pDmaCur = *(u_long *)(s1 + 0x10);
        pDmaCur = (u8 *)pDmaCur + 8;
        pDmaCur = MmoStrip_PkRGBAQ(pDmaCur, s5, 1.0f);
        pDmaCur = MmoStrip_PkST(pDmaCur, s3[0], s3[1]);
        pDmaCur = MmoStrip_XYZ(pDmaCur, s4[0] + f20, s4[1]);
        pDmaCur = MmoStrip_PkST(pDmaCur, s3[2], s3[1]);
        pDmaCur = MmoStrip_XYZ(pDmaCur, s4[2] + f20, s4[1]);
        pDmaCur = MmoStrip_PkST(pDmaCur, s3[0], s3[3]);
        pDmaCur = MmoStrip_XYZ(pDmaCur, s4[0], s4[3]);
        pDmaCur = MmoStrip_PkST(pDmaCur, s3[2], s3[3]);
        pDmaCur = MmoStrip_XYZ(pDmaCur, s4[2], s4[3]);
        *(void **)(*(u8 **)s_pSysInfo + 8) = pDmaCur;
        v1 = *(u16 *)(((u32)*(s32 *)s_pSysInfo + 0x1e));
        v1 = v1 + 1;
        *(u16 *)(((u32)*(s32 *)s_pSysInfo + 0x1e)) = v1;
        v1 = *(u16 *)(((u32)*(s32 *)s_pSysInfo + 0x1c));
        v1 = v1 + 1;
        *(u16 *)(((u32)*(s32 *)s_pSysInfo + 0x1c)) = v1;
    }
    return;
}





/* MmoFontSetRefCurrentPtr @ 0x218370 .. 0x218378 (0x8 bytes) */


void MmoFontSetRefCurrentPtr(s32 a0 /* r4 */) {
    sCurrentP = a0;
    return;
}







/* MmoFontSetRefStatePtr @ 0x218360 .. 0x218368 (0x8 bytes) */




void MmoFontSetRefStatePtr(void) {
    return;
}
void _TransTextureFromFileInMemory(u8 *file)
{
    u32 saved = (u32)file;
    FileTexReg *reg;
    u8 *image = file + 32;
    if (saved) {
        reg = (FileTexReg *)(saved + 16);
        _TransTexture(image, reg->base, reg->width, reg->format, 1 << reg->logWidth, 1 << reg->logHeight);
        file = (u8 *)*(s32 *)(saved + 4);
        file = image + (u32)file;
        switch (reg->format) {
        case 19: case 27:
            _TransTexture(file, reg->clutBase, 1, reg->clutFormat, 16, 16);
            break;
        case 20: case 44: case 36:
            _TransTexture(file, reg->clutBase, 1, reg->clutFormat, 8, 2);
        }
    }
}

void _TransTexture(void *src, s32 base, s32 dbw, s32 psm, u32 width, u32 height) {
    float bytes_per_pixel;
    u32 flags;
    u32 first_qwc;
    u32 finish_qwc;
    u32 pixels;
    u32 bytes;
    u32 current_base;
    u32 remaining;
    u8 *info;
    void *write_ptr;
    sceDmaTag *first;
    sceDmaTag *dma_cursor;
    void *load;
    MmoGifTag *gif;

    current_base = (u32)base;
    pixels = width * (u32)height;
    first_qwc = 6;
    finish_qwc = 2;
    *(u32 *)s_pSysInfo = sCurrentP + 0x98;
    switch (psm) {
    case 0:
        bytes_per_pixel = 4.0f;
        break;
    case 1:
        bytes_per_pixel = 3.0f;
        break;
    case 2:
        bytes_per_pixel = 2.0f;
        break;
    case 0x13:
    case 0x1b:
        bytes_per_pixel = 1.0f;
        break;
    case 0x14:
    case 0x2c:
    case 0x24:
        bytes_per_pixel = 0.5f;
        break;
    default:
        return;
    }

    remaining = (u32)((float)pixels * bytes_per_pixel);
    info = (u8 *)*(u32 *)s_pSysInfo;
    flags = info[0x22];
    if ((flags & 1) == 0) {
        first_qwc += 1;
        finish_qwc += 1;
    }

    while (1) {
        if (remaining == 0) {
            break;
        }
        if (remaining < 0x7fff0) {
            bytes = remaining;
        } else {
            bytes = 0x7fff0;
        }
        remaining -= bytes;
        height = (u32)((float)(bytes / width) / bytes_per_pixel);

        if (MmoTex_CheckSpace(first_qwc + 3 + finish_qwc) != 0) {
            break;
        }

        first = *(sceDmaTag **)((*(u8 **)s_pSysInfo) + 8);
        load = MmoTex_PkDMA(first, (u16)first_qwc | 0x20000000,
                            (u32)((u8 *)first + (first_qwc + 1) * 16));
        if (((*(u8 **)s_pSysInfo)[0x22] & 1) == 0) {
            load = MmoTex_PkVIFDirect(load, 6);
        }

        gif = (MmoGifTag *)load;
        {
            u_long128 pre = 0;
            gif->NLOOP = 4;
            gif->EOP = 0;
            gif->pad = 0;
            gif->PRE = pre ? 1 : 0;
            gif->PRIM = 0;
            gif->FLG = 0;
            gif->NREG = 1;
            gif->REGS = 0xe;
        }

        load = (u8 *)load + 16;
        load = MmoTex_PkAD(load,
            SCE_GS_SET_BITBLTBUF(0, 0, 0, current_base, (u32)dbw, (u32)psm), 0x50);
        load = MmoTex_PkAD(load, SCE_GS_SET_TRXPOS(0, 0, 0, 0, 0), 0x51);
        load = MmoTex_PkAD(load, SCE_GS_SET_TRXREG(width, height), 0x52);
        load = MmoTex_PkAD(load, SCE_GS_SET_TRXDIR(0), 0x53);

        gif = (MmoGifTag *)load;
        {
            u_long128 pre = 0;
            gif->NLOOP = bytes >> 4;
            gif->EOP = 1;
            gif->pad = 0;
            gif->PRE = pre ? 1 : 0;
            gif->PRIM = 0;
            gif->FLG = 2;
            gif->NREG = 0;
            gif->REGS = 0;
        }

        dma_cursor = (sceDmaTag *)((u8 *)load + 16);
        dma_cursor = MmoTex_PkDMA(dma_cursor, (u16)(bytes >> 4) | 0x30000000,
                              (u32)src);
        *(sceDmaTag **)((*(u8 **)s_pSysInfo) + 0xc) = dma_cursor;
        write_ptr = MmoTex_PkDMA(dma_cursor, (u16)finish_qwc | 0x20000000,
                                 (u32)((u8 *)dma_cursor + (finish_qwc + 1) * 16));
        if (((*(u8 **)s_pSysInfo)[0x22] & 1) == 0) {
            write_ptr = MmoTex_PkVIFDirect(write_ptr, 2);
        }

        gif = (MmoGifTag *)(write_ptr);
        {
            u_long128 pre = 0;
            gif->NLOOP = 1;
            gif->EOP = 1;
            gif->pad = 0;
            gif->PRE = pre ? 1 : 0;
            gif->PRIM = 0;
            gif->FLG = 0;
            gif->NREG = 1;
            gif->REGS = 0xe;
        }
        write_ptr = (u8 *)gif + 16;
        write_ptr = MmoTex_PkAD(write_ptr, 0, 0x3f);
        *(void **)((*(u8 **)s_pSysInfo) + 8) = write_ptr;
        info = *(u8 **)s_pSysInfo;
        *(u16 *)(info + 0x1c) = *(u16 *)(info + 0x1c) + 1;
        current_base += (bytes / 2) / 64;
        src = (void *)((u8 *)src + bytes);
    }
}
