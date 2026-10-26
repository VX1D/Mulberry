#include "common.h"

/* FsFontInitBugPath @ 0x174750 .. 0x17488C (0x13c bytes, frame 0x90) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x17479c
 *   fpu: float literal 0x38d1b717 at 0x1747cc
 *   fpu: mtc1 reinterprets v1 at 0x1747dc
 *   fpu: float literal 0x3c23d70a at 0x174810
 *   fpu: mtc1 reinterprets v1 at 0x17481c
 *   cfg: loop body is not one contiguous region: .L00174780
 *   cfg: loop body is not one contiguous region: .L00174798
 *   cfg: loop body is not one contiguous region: .L001747A8
 */

extern int rand(void);
extern u32 BugPath[];

/* FontSetRefCurrentPtr @ 0x1748A0 .. 0x1748A8 (0x8 bytes) */

static u32 s_send_tex_flag;

static u32 sCurrentP;
static void *s_pSysInfo;

typedef struct {
    void *pDmaBuffer;
    unsigned int uiDmaBufferSize;
    void *pDmaCurrent;
    void *pDmaLatest;
    void *pCodeBuffer;
    unsigned int uiCodeBufferSize;
    void *pCodeCurrent;
    unsigned short usEntryStrNum;
    unsigned short usStrNum;
    unsigned short usCodeEntryNum;
    unsigned char bfMode : 1;
    unsigned char bfConText : 1;
    unsigned char bfDmaOverDraw : 1;
    unsigned char bfFfmd : 1;
    unsigned char bfDummy : 4;
    unsigned char ucBfTransTexId;
    unsigned char cDmy[26];
    unsigned short usBegin;
} TSFDSys;

typedef struct {
    unsigned int size;
    unsigned int wnum;
    unsigned int dummy0;
    unsigned int dummy1;
    struct {
        unsigned long fd_tex0;
        unsigned long fd_tex1;
    } fd_texinfo;
} TSFDTm2Head;

struct TSFDGifTag {
    unsigned long nloop : 15;
    unsigned long eop : 1;
    unsigned long dummy : 30;
    unsigned long pre : 1;
    unsigned long prim : 11;
    unsigned long flg : 2;
    unsigned long nreg : 4;
    unsigned long regs;
} __attribute__((aligned(16)));

#define TS_SYS ((TSFDSys *)s_pSysInfo)

typedef struct {
    float s;
    float t;
} TSFDST;

static inline void TSFD_XYZ(void *p, float x, float y) {
    float yy;

    s_pSysInfo = (void *)(sCurrentP + 0x9c);
    *(unsigned short *)p = (int)(16.0f * (1728.0f + x));
    yy = 224.0f - y;
    if (TS_SYS->bfFfmd == 1) {
        yy /= 2.0f;
    }
    ((unsigned short *)p)[1] = (int)(16.0f * (2048.0f - yy));
    ((unsigned int *)p)[1] = 0x1000000;
}

extern void _SendPacketByDma(void);
static inline void *FontDraw_PkADFixed(void *, u_long, int);

static inline int TSFD_CheckDmaSpace(unsigned int currentSys) {
    TSFDSys *sys;
    sys = TS_SYS;
    if ((unsigned int)(sys->uiDmaBufferSize - ((unsigned int)sys->pDmaCurrent - (unsigned int)sys->pDmaBuffer)) <= 8) {
        if (sys->bfMode == 1) {
            if (sys->bfDmaOverDraw) {
                unsigned int *pLatest;
                s_pSysInfo = (void *)(currentSys);
                pLatest = (unsigned int *)sys->pDmaLatest;
                *pLatest &= 0x8fffffff;
                if (!TS_SYS->bfMode) {
                    *pLatest |= 0x60000000;
                } else {
                    *pLatest |= 0x70000000;
                }
                pLatest[1] = 0;
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


typedef struct {
    void *pDmaBuffer;
    unsigned int uiDmaBufferSize;
    void *pDmaCurrent;
    void *pDmaLatest;
    void *pCodeBuffer;
    unsigned int uiCodeBufferSize;
    void *pCodeCurrent;
    unsigned short usEntryStrNum;
    unsigned short usStrNum;
    unsigned short usCodeEntryNum;
    unsigned char bfMode : 1;
    unsigned char bfConText : 1;
    unsigned char bfDmaOverDraw : 1;
    unsigned char bfFfmd : 1;
    unsigned char bfDummy : 4;
    unsigned char ucBfTransTexId;
    unsigned char cDmy[26];
    unsigned short usBegin;
} FDSys;

typedef struct {
    unsigned int size;
    unsigned int wnum;
    unsigned int dummy0;
    unsigned int dummy1;
    struct {
        unsigned long fd_tex0;
        unsigned long fd_tex1;
    } fd_texinfo;
} FDTm2Head;

struct FDGifTag {
    unsigned long nloop : 15;
    unsigned long eop : 1;
    unsigned long dummy : 30;
    unsigned long pre : 1;
    unsigned long prim : 11;
    unsigned long flg : 2;
    unsigned long nreg : 4;
    unsigned long regs;
} __attribute__((aligned(16)));

#define SYS ((FDSys *)s_pSysInfo)

typedef struct {
    float s;
    float t;
} FDST;

static inline void FD_XYZ(void *p, float x, float y) {
    float yy;

    s_pSysInfo = (void *)(sCurrentP + 0x9c);
    *(unsigned short *)p = (int)(16.0f * (1728.0f + x));
    yy = 224.0f - y;
    if (SYS->bfFfmd == 1) {
        yy /= 2.0f;
    }
    ((unsigned short *)p)[1] = (int)(16.0f * (2048.0f - yy));
    ((unsigned int *)p)[1] = 0x1000000;
}

extern void _SendPacketByDma(void);
static inline void *FontDraw_PkADFixed(void *, u_long, int);

static inline int FD_CheckDmaSpace(unsigned int currentSys) {
    FDSys *sys;
    sys = SYS;
    if ((unsigned int)(sys->uiDmaBufferSize - ((unsigned int)sys->pDmaCurrent - (unsigned int)sys->pDmaBuffer)) <= 6) {
        if (sys->bfMode == 1) {
            if (sys->bfDmaOverDraw) {
                unsigned int *pLatest;
                s_pSysInfo = (void *)(currentSys);
                pLatest = (unsigned int *)sys->pDmaLatest;
                *pLatest &= 0x8fffffff;
                if (!SYS->bfMode) {
                    *pLatest |= 0x60000000;
                } else {
                    *pLatest |= 0x70000000;
                }
                pLatest[1] = 0;
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


/* _MakeDmaPacketSpritePieces @ 0x1755A0 .. 0x175D40 (0x7a0 bytes, frame 0x160) */

static void _SendPacketByDma(void);


typedef struct {
    unsigned long NLOOP : 15;
    unsigned long EOP : 1;
    unsigned long ID : 30;
    unsigned long PRE : 1;
    unsigned long PRIM : 11;
    unsigned long FLG : 2;
    unsigned long NREG : 4;
    unsigned long REGS;
} SpGifTag;

typedef struct {
    u8 *base;
    u32 size;
    u8 *cur;
    u32 *tag;
    u32 pad10[3];
    u16 n1c;
    u16 n1e;
    u16 pad20;
    struct {
        unsigned char f0 : 1;
        unsigned char ctxt : 1;
        unsigned char f2 : 1;
        unsigned char half : 1;
    } fl;
    u8 curTex;
} SpSys;

typedef struct {
    u32 size;
    u32 wnum;
    u32 d0;
    u32 d1;
    u64 tx0;
    u64 tx1;
} SpTm2;

typedef struct {
    float b[2];
} SpF2;

#define SP_SYS ((SpSys *)s_pSysInfo)

static inline void SpSetTag(SpGifTag *t, u32 nloop, u32 eop, u32 id, u32 pre, u32 prim, u32 flg, u32 nreg) {
    t->NLOOP = nloop;
    t->EOP = eop;
    t->ID = id;
    t->PRE = (pre != 0);
    t->PRIM = prim & 0x7ff;
    t->FLG = flg;
    t->NREG = nreg;
}

static inline int SpCheck(u32 n, u32 currentSys) {
    if (SP_SYS->size - (u32)(SP_SYS->cur - SP_SYS->base) < n) {
        if ((*(u8 *)&SP_SYS->fl & 1) == 1) {
            if (SP_SYS->fl.f2) {
                u32 *tag;
                s_pSysInfo = (void *)currentSys;
                tag = SP_SYS->tag;
                *tag &= -0x70000001;
                if ((*(u8 *)&SP_SYS->fl & 1) == 0) {
                    *tag |= 0x60000000;
                } else {
                    *tag |= 0x70000000;
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


/* _LoadTm2 @ 0x175D40 .. 0x176364 (0x624 bytes, frame 0xd0)
 *
 * TIM2 (PNG-style PS2 texture) uploader.  Reads the TEX0/TEX1 pair the file
 * carries, uploads the picture through the GS (splitting the image in two
 * halves when it does not fit), then uploads the CLUT for the indexed
 * formats.  The resulting TEX0/TEX1 are handed back to the caller.
 */

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


/* _SendPacketByDma @ 0x176370 .. 0x17643C (0xcc bytes, frame 0x10) */

extern void FlushCache(int);

struct FontDrawGifTag {
    unsigned long fd_nloop : 15;
    unsigned long fd_eop : 1;
    unsigned long fd_padding : 30;
    unsigned long fd_pre : 1;
    unsigned long fd_prim : 11;
    unsigned long fd_flg : 2;
    unsigned long fd_nreg : 4;
    unsigned long fd_regs;
} __attribute__((aligned(16)));

struct FontDrawPacketFlags {
    unsigned long fd_dma : 1;
    unsigned long fd_context : 1;
} __attribute__((packed));

static inline void FontDraw_SetGifTag(struct FontDrawGifTag *tag,
        unsigned long nloop, unsigned long eop, unsigned int prim,
        unsigned long flg, unsigned long nreg) {
    u_long128 pre = 0;
    tag->fd_nloop = nloop;
    tag->fd_eop = eop;
    tag->fd_padding = 0;
    tag->fd_pre = pre ? 1 : 0;
    tag->fd_prim = prim;
    tag->fd_flg = flg;
    tag->fd_nreg = nreg;
}

static inline void *FontDraw_PkADFixed(void *p, u_long data, int addr) {
    ((u_long *)p)[0] = data;
    ((s_long *)p)[1] = addr;
    return (u8 *)p + 0x10;
}

#define FONT_DRAW_SYS ((u8 *)((u32)s_pSysInfo))
#define FONT_DRAW_FLAGS(p) ((struct FontDrawPacketFlags *)((u8 *)(p) + 0x22))

#undef FONT_DRAW_FLAGS
#undef FONT_DRAW_SYS


/* FsFontGetSendTexFlag @ 0x176670 .. 0x176678 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x176674 computes the return value
 */

extern u32 s_send_tex_flag;

/* FsFontReSetSendTexFlag @ 0x176680 .. 0x176688 (0x8 bytes) */

extern u32 s_send_tex_flag;

/* FsFontBegin @ 0x176790 .. 0x176834 (0xa4 bytes, frame 0x10) */

extern void _SetDrawCondition(void);


static void _MakeDmaPacketSprite(signed int, float *, unsigned int *, float *);
static void _MakeDmaPacketSpritePieces(signed int, float *, unsigned int *, float *, signed int *, signed int);
static void _MakeDmaPacketTriangleStrip(signed int, float *, unsigned int *, float *, float);
static u32 BugPath[0x9600];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
unsigned int FsFont_GetDmaBufferSize(unsigned int a0 , signed int a1 );
void FsFont_SetDmaBuffer(void *a0 , unsigned int a1 );
void FsFont_SetMode(int a0 , signed int a1 );
void FontDrawRect(signed int a0, float *a1, unsigned int *a2, float *a3, float f12);
signed int FsFontBegin(void);
signed int FsFontEnd(void);
void FsFontReSetSendTexFlag(void);
u32 FsFontGetSendTexFlag(void);
static void _LoadTm2(TM2 *pTm2, u64 *tex0, u64 *tex1);
void FontSetRefCurrentPtr(void *a0 );
void FontSetRefStatePtr(void);
void FsFontInitBugPath(void);


/* FsFont_GetDmaBufferSize @ 0x176B60 .. 0x176B98 (0x38 bytes) */
/*
 * dcomp notes:
 *   return: sll at 0x176b94 computes the return value
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

unsigned int FsFont_GetDmaBufferSize(unsigned int a0 /* r4 */, signed int a1 /* r5 */) {
    s32 v1;
    u32 v0;

    v0 = sCurrentP;
    v1 = 0;
    s_pSysInfo = (void *)(v0 + 0x9c);
    if ((u32)(s32)a1 == 0) {
        v1 = v1 + 7;
    } else {
        v1 = v1 + 9;
    }
    v1 *= (u32)a0;
    return (u32)(v1 + 6) << 4;
}

/* FsFont_SetDmaBuffer @ 0x176B40 .. 0x176B60 (0x20 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

void FsFont_SetDmaBuffer(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u32 v1;

    v1 = sCurrentP;
    s_pSysInfo = (void *)(v1 + 0x9c);
    v1 = ((s32)s_pSysInfo);
    *(u32 *)v1 = (u32)a0;
    v1 = ((s32)s_pSysInfo);
    *(u32 *)((v1 + 4)) = a1;
    return;
}


/* FsFont_SetMode @ 0x176A50 .. 0x176B38 (0xe8 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x176a70 writes a register its branch at 0x176a6c reads
 *   declaration vs inferred signature: return void vs inferred u32
 */

void FsFont_SetMode(int a0 /* r4 */, signed int a1 /* r5 */) {
    u32 a2;
    u32 v1;

    a2 = sCurrentP;
    a0 = (u8)(s32)a0;
    v1 = 3;
    a2 = a2 + 0x9c;
    s_pSysInfo = (void *)(a2);
    switch ((u32)a0) {
    case 0:
        a2 = ((s32)s_pSysInfo);
        ((struct { unsigned char f:1; } *)&*(u8 *)((a2 + 0x22)))->f = (u32)(a1) & 1;
        break;
    case 1:
        a2 = ((s32)s_pSysInfo);
        ((struct { unsigned char _pad:1; unsigned char f:1; } *)&*(u8 *)((a2 + 0x22)))->f =
            (u32)(a1) & 1;
        break;
    case 2:
        a2 = ((s32)s_pSysInfo);
        ((struct { unsigned char _pad:2; unsigned char f:1; } *)&*(u8 *)((a2 + 0x22)))->f =
            (u32)(a1) & 1;
        break;
    case 3:
        a2 = ((s32)s_pSysInfo);
        ((struct { unsigned char _pad:3; unsigned char f:1; } *)&*(u8 *)((a2 + 0x22)))->f =
            (u32)(a1) & 1;
    }
    return;
}
void FontDrawRect(signed int a0, float *a1, unsigned int *a2, float *a3, float f12) {
    s32 mode;
    u8 *rectangle;
    u32 color;
    u32 uv;
    float angle;
    u32 index;
    u32 current;
    s32 size;
    u8 *base;
    s32 pieces[2] __attribute__((aligned(8)));
    index = (u32)a0 << 2;
    mode = a0;
    rectangle = (u8 *)a1;
    color = (u32)a2;
    uv = (u32)a3;
    a1 = (float *)sCurrentP;
    angle = f12;
    index = (u32)((u8 *)a1 + index);
    a1 = (float *)((u8 *)a1 + 0x9c);
    s_pSysInfo = (void *)((u32)a1);
    a0 = *(s32 *)index;
    s_pSysInfo = (void *)((u32)a1);
    if ((u32)mode == 2) s_send_tex_flag = 1;
    base = (u8 *)((u32)s_pSysInfo);
    if ((base[0x22] & 1) == 1) {
        if (base[0x23] != (u32)mode) _LoadTm2((TM2 *)a0, (u64 *)0, (u64 *)0);
        *(u8 *)(((u32)s_pSysInfo) + 0x23) = mode;
    }
    if (0.0f == angle) {
        current = sCurrentP;
        size = *(u8 *)(current + 0x99);
        if (size == 0) {
            _MakeDmaPacketSprite(mode, (float *)rectangle, (unsigned int *)color, (float *)uv);
        } else {
            pieces[0] = (size + (s32)(*(float *)(rectangle + 8) - *(float *)rectangle) - 1) / size;
            size = *(u8 *)(current + 0x99);
            pieces[1] = (size + (s32)(0.5f * (*(float *)(rectangle + 12) - *(float *)(rectangle + 4))) - 1) / size;
            if (pieces[0] <= 0) pieces[0] = 1;
            if (pieces[0] > 8) pieces[0] = 8;
            if (pieces[1] <= 0) pieces[1] = 1;
            if (pieces[1] > 8) pieces[1] = 8;
            _MakeDmaPacketSpritePieces(mode, (float *)rectangle, (unsigned int *)color, (float *)uv, pieces, *(u16 *)(current + 0x9a));
        }
    } else {
        _MakeDmaPacketTriangleStrip(mode, (float *)rectangle, (unsigned int *)color, (float *)uv, angle);
    }
}

signed int FsFontBegin(void) {
    u16 v1;
    u32 v0;

    v0 = sCurrentP;
    s_pSysInfo = (void *)(v0 + 0x9c);
    v1 = *(u16 *)(((u8 *)(u8 *)((s32)s_pSysInfo) + 0x3e));
    *(u16 *)(((u8 *)(u8 *)((s32)s_pSysInfo) + 0x3e)) = (u32)(v1) + 1;
    if (v1 != 0) {
        v0 = 0;
    } else {
        v0 = sCurrentP;
        s_pSysInfo = (void *)(v0 + 0x9c);
        *(u32 *)(((u8 *)(u8 *)((s32)s_pSysInfo) + 0x18)) = *(s32 *)(((u8 *)(u8 *)((s32)s_pSysInfo) + 0x10));
        v0 = ((s32)s_pSysInfo);
        *(u16 *)((v0 + 0x20)) = 0;
        v0 = sCurrentP;
        s_pSysInfo = (void *)(v0 + 0x9c);
        v0 = *(s32 *)(u8 *)((s32)s_pSysInfo);
        *(u32 *)(((u8 *)(u8 *)((s32)s_pSysInfo) + 8)) = v0;
        v0 = *(s32 *)(((u8 *)(u8 *)((s32)s_pSysInfo) + 8));
        *(u32 *)(((u8 *)(u8 *)((s32)s_pSysInfo) + 0xc)) = v0;
        v0 = ((s32)s_pSysInfo);
        *(u16 *)((v0 + 0x1c)) = 0;
        v0 = ((s32)s_pSysInfo);
        *(u16 *)((v0 + 0x1e)) = 0;
        v0 = ((s32)s_pSysInfo);
        *(u8 *)((v0 + 0x23)) = 0xff;
        _SetDrawCondition();
        v0 = 0;
    }
    return v0;
}

/* FsFontEnd @ 0x176690 .. 0x176784 (0xf4 bytes, frame 0x10) */

signed int FsFontEnd(void) {
    u8 *a0;
    u32 v1;
    u32 v0;

    s_pSysInfo = (void *)(sCurrentP + 0x9c);
    v0 = ((s32)s_pSysInfo);
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
            v0 = -0x70000001;
            s_pSysInfo = (void *)(sCurrentP + 0x9c);
            a0 = (u8 *)*(s32 *)((((s32)s_pSysInfo) + 0xc));
            *(u32 *)a0 &= -0x70000001;
            v0 = *(u8 *)((((s32)s_pSysInfo) + 0x22));
            if ((u32)(v0 & 1) == 0) {
                v0 = 0x60000000;
                *(u32 *)a0 |= 0x60000000;
            } else {
                v0 = 0x70000000;
                *(u32 *)a0 |= 0x70000000;
            }
            *(u32 *)(a0 + 4) = 0;
            v1 = *(u8 *)(((u8 *)(u8 *)((s32)s_pSysInfo) + 0x22));
            if ((u32)(v1 & 1) == (u32)1 && (s32)*(u16 *)(((u8 *)(u8 *)((s32)s_pSysInfo) + 0x1c)) >
                0) {
                _SendPacketByDma();
            }
            v0 = 0;
        }
    }
    return v0;
}

void FsFontReSetSendTexFlag(void) {
    s_send_tex_flag = 0;
    return;
}

u32 FsFontGetSendTexFlag(void) {
    return s_send_tex_flag;
}
#define FONT_DRAW_FLAGS(p) ((struct FontDrawPacketFlags *)((u8 *)(p) + 0x22))
#define FONT_DRAW_SYS ((u8 *)((u32)s_pSysInfo))

static void _SetDrawCondition(void) {
    void *pDmaCur;
    u8 *pSysInfo;
    void *pTag;

    s_pSysInfo = (void *)(sCurrentP + 0x9c);
    if (*(u32 *)FONT_DRAW_SYS != 0) {
        pDmaCur = *(void **)(FONT_DRAW_SYS + 8);
        *(void **)(FONT_DRAW_SYS + 12) = pDmaCur;
        ((u32 *)pDmaCur)[0] = 0x20000005;
        ((u32 *)pDmaCur)[1] = (u32)pDmaCur + 0x60;
        ((u64 *)pDmaCur)[1] = 0;
        pTag = (u8 *)pDmaCur + 0x10;
        if (!FONT_DRAW_FLAGS(FONT_DRAW_SYS)->fd_dma) {
            ((u32 *)pTag)[-1] = 0x51000005;
        }
        FontDraw_SetGifTag((struct FontDrawGifTag *)pTag, 4, 1, 0, 0, 1);
        ((u64 *)pTag)[1] = 0xe;
        pDmaCur = (u8 *)pTag + 0x10;
        pDmaCur = FontDraw_PkADFixed(pDmaCur, 0, 0x3f);
        pSysInfo = FONT_DRAW_SYS;
        pDmaCur = FontDraw_PkADFixed(pDmaCur, 0, FONT_DRAW_FLAGS(pSysInfo)->fd_context ? 9 : 8);
        pDmaCur = FontDraw_PkADFixed(pDmaCur, 0x31001, FONT_DRAW_FLAGS(pSysInfo)->fd_context ? 0x48 : 0x47);
        pDmaCur = FontDraw_PkADFixed(pDmaCur, 0x44, FONT_DRAW_FLAGS(pSysInfo)->fd_context ? 0x43 : 0x42);
        *(void **)(pSysInfo + 8) = pDmaCur;
    }
}

static void _SendPacketByDma(void) {
    u32 a0;
    u32 v1;
    u32 v0;

    v0 = sCurrentP;
    s_pSysInfo = (void *)(v0 + 0x9c);
    do {
        u32 dcomp_tmp_1;
        v0 = *(volatile s32 *)268476416;
        {
            dcomp_tmp_1 = ((u32)(u32)v0 & ((256)));
            {
                v0 = (u32)((u32)dcomp_tmp_1);
            }
        }
    } while (v0 != 0 || (u32)(*(volatile s32 *)0x10003020 & 0xc00) != 0);
    *(volatile u32 *)268476448 = 0;
    *(volatile u32 *)0x1000a010 = 0;
    v0 = ((s32)s_pSysInfo);
    v0 = *(s32 *)(u32)v0;
    *(volatile u32 *)0x1000a030 = (u32)v0;
    FlushCache(0);
    *(volatile u32 *)268476416 = 0x145;
    do {
        v1 = *(volatile s32 *)0x1000a000;
        {
            u32 dcomp_tmp_0;
            u32 dcomp_tmp_6;
            {
                {
                    {
                        u32 dcomp_tmp_13;
                        {
                            u32 dcomp_tmp_14;
                            {
                                u32 dcomp_tmp_15;
                                {
                                    dcomp_tmp_15 = (u32)((u32)(v1 & 256));
                                    dcomp_tmp_14 = dcomp_tmp_15;
                                }
                            }
                            dcomp_tmp_13 = dcomp_tmp_14;
                        }
                        dcomp_tmp_6 = dcomp_tmp_13;
                    }
                }
                {
                    dcomp_tmp_0 = (u32)(dcomp_tmp_6);
                }
            }
            {
                {
                    {
                        {
                            u32 dcomp_tmp_3;
                            u32 dcomp_tmp_2;
                            {
                                u32 dcomp_tmp_4;
                                dcomp_tmp_4 = (u32)((u32)((u32)((u32)dcomp_tmp_0)));
                                {
                                    {
                                        u32 dcomp_tmp_12;
                                        dcomp_tmp_2 = ((u32)((u32)(dcomp_tmp_4)));
                                    }
                                }
                            }
                            {
                                dcomp_tmp_3 = (u32)dcomp_tmp_2;
                                {
                                    u32 dcomp_tmp_7;
                                    {
                                        u32 dcomp_tmp_8;
                                        dcomp_tmp_8 = dcomp_tmp_3;
                                        dcomp_tmp_7 = dcomp_tmp_8;
                                    }
                                    {
                                        u32 dcomp_tmp_5;
                                        u32 dcomp_tmp_9;
                                        {
                                            {
                                                u32 dcomp_tmp_11;
                                                dcomp_tmp_11 = (u32)((u32)(dcomp_tmp_7));
                                                {
                                                    {
                                                        u32 dcomp_tmp_10;
                                                        dcomp_tmp_5 = ((u32)((u32)(dcomp_tmp_11)));
                                                    }
                                                }
                                            }
                                            {
                                                u32 dcomp_tmp_16;
                                                dcomp_tmp_16 = (u32)dcomp_tmp_5;
                                                {
                                                    u32 dcomp_tmp_17;
                                                    dcomp_tmp_17 = dcomp_tmp_16;
                                                    v1 = dcomp_tmp_17;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x10003020 & 0xc00) != 0);
    v1 = sCurrentP;
    s_pSysInfo = (void *)((u32)(u32)(u32)v1 + 0x9c);
    a0 = ((s32)s_pSysInfo);
    v1 = *(s32 *)a0;
    *(u32 *)((a0 + 0x8)) = v1;
    a0 = ((s32)s_pSysInfo);
    v1 = *(s32 *)(((u32)a0 + 8));
    *(u32 *)(((u32)a0 + 12)) = v1;
    v1 = ((s32)s_pSysInfo);
    *(u16 *)((v1 + 0x1c)) = 0;
    return;
}

static void _LoadTm2(TM2 *pTm2, u64 *tex0, u64 *tex1) {
    sceGsLoadImage li;
    u16 w;
    u16 h;
    int m;

    w = 1 << pTm2->tex0.TW;
    h = 1 << pTm2->tex0.TH;
    _WAITSYNC();
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



static void _MakeDmaPacketSpritePieces(signed int texID, float *pos, unsigned int *color, float *uv, signed int *pieces, signed int range) {
    int countX;
    int countY;
    float PosX[9];
    float PosY[9];
    float TexS[9];
    float TexT[9];
    int columns;
    int rows;
    unsigned int currentSys;
    unsigned int uiTransSize;
    unsigned int uiPacketSize;
    u8 *pDmaCur;
    SpTm2 *pTm2Head;
    volatile unsigned int uiPrim;
    float RandPosX;
    float RandPosY;
    float uvT0;
    float uvT1;
    SpGifTag *g;
    u_long textureReg;
    u64 *w, *w0, *w1, *w2, *w3;
    u_long128 *p1, *p2, *p3, *p4, *p5;
    float *bug;
    float *e;

    texID = (u32)texID << 2;
    columns = pieces[0];
    rows = pieces[1];
    pTm2Head = *(SpTm2 **)(sCurrentP + texID);
    currentSys = sCurrentP + 0x9c;
    s_pSysInfo = (void *)currentSys;
    uiTransSize = columns * rows * 2 + 5;
    uiPacketSize = uiTransSize + 1;
    if (SpCheck(uiPacketSize, currentSys) != 0) {
        return;
    }
    pDmaCur = SP_SYS->cur;
    SP_SYS->tag = (u32 *)pDmaCur;
    ((u32 *)pDmaCur)[0] = (u16)uiTransSize | 0x20000000;
    ((u32 *)pDmaCur)[1] = (u32)pDmaCur + (uiTransSize + 1) * 16;
    *(u64 *)(pDmaCur + 8) = 0;
    p1 = (u_long128 *)pDmaCur + 1;
    if ((*(u8 *)&SP_SYS->fl & 1) == 0) {
        ((u32 *)p1)[-1] = uiTransSize | 0x51000000;
    }
    uiPrim = (u_long)0x5e | ((u_long)SP_SYS->fl.ctxt << 9);
    g = (SpGifTag *)p1;
    SpSetTag(g, 3, 0, 0, 1, uiPrim, 0, 1);
    g->REGS = 0xe;
    p2 = p1 + 1;
    textureReg = pTm2Head->tx1;
    p3 = FontDraw_PkADFixed(p2, textureReg, SP_SYS->fl.ctxt ? 0x15 : 0x14);
    p4 = FontDraw_PkADFixed(p3, pTm2Head->tx0, SP_SYS->fl.ctxt ? 7 : 6);
    p5 = p4 + 1;
    ((u32 *)p4)[0] = color[0];
    ((float *)p4)[1] = 1.0f;
    ((u64 *)p4)[1] = 1;
    g = (SpGifTag *)p5;
    {
        u_long128 pre = 0;
        g->NLOOP = pieces[0] * pieces[1];
        g->EOP = 1;
        g->ID = 0;
        g->PRE = pre ? 1 : 0;
        g->PRIM = 0;
        g->FLG = 1;
        g->NREG = 4;
    }
    g->REGS = 0x5252;
    w = (u64 *)(p5 + 1);
    PosX[0] = pos[0];
    PosX[pieces[0]] = pos[2];
    PosY[0] = pos[1];
    PosY[pieces[1]] = pos[3];
    TexS[0] = uv[0];
    TexS[pieces[0]] = uv[2];
    TexT[0] = uv[1];
    TexT[pieces[1]] = uv[3];
    for (countX = 1; countX < pieces[0]; countX++) {
        PosX[countX] = PosX[0] + (float)countX * (PosX[pieces[0]] - PosX[0]) / (float)pieces[0];
        TexS[countX] = TexS[0] + (float)countX * (TexS[pieces[0]] - TexS[0]) / (float)pieces[0];
    }
    for (countY = 1; countY < pieces[1]; countY++) {
        PosY[countY] = PosY[0] + (float)countY * (PosY[pieces[1]] - PosY[0]) / (float)pieces[1];
        TexT[countY] = TexT[0] + (float)countY * (TexT[pieces[1]] - TexT[0]) / (float)pieces[1];
    }
    for (countY = 0; countY < pieces[1]; countY++) {
        for (countX = 0; countX < pieces[0]; countX++) {
            float y;
            bug = (float *)((u8 *)BugPath + (range << 9));
            e = bug + ((countY + countX * pieces[0]) << 2);
            RandPosX = e[0];
            RandPosY = e[1];
            w0 = w;
            uvT0 = TexT[countY];
            ((float *)w0)[0] = TexS[countX];
            ((float *)w0)[1] = uvT0;
            w1 = w0 + 1;
            y = RandPosY + PosY[countY];
            s_pSysInfo = (void *)(sCurrentP + 0x9c);
            *(s16 *)w1 = (s16)(16.0f * (1728.0f + (RandPosX + PosX[countX])));
            y = 224.0f - y;
            if (SP_SYS->fl.half == 1) {
                y = y / 2.0f;
            }
            ((s16 *)w1)[1] = (s16)(16.0f * (2048.0f - y));
            ((u32 *)w1)[1] = 0x1000000;
            w2 = w1 + 1;
            uvT1 = TexT[countY + 1];
            ((float *)w2)[0] = TexS[countX + 1];
            ((float *)w2)[1] = uvT1;
            w3 = w2 + 1;
            y = RandPosY + PosY[countY + 1];
            s_pSysInfo = (void *)(sCurrentP + 0x9c);
            *(s16 *)w3 = (s16)(16.0f * (1728.0f + (RandPosX + PosX[countX + 1])));
            y = 224.0f - y;
            if (SP_SYS->fl.half == 1) {
                y = y / 2.0f;
            }
            ((s16 *)w3)[1] = (s16)(16.0f * (2048.0f - y));
            ((u32 *)w3)[1] = 0x1000000;
            w = w3 + 1;
        }
    }
    SP_SYS->cur = (u8 *)w;
    SP_SYS->n1e++;
    SP_SYS->n1c++;
}

static void _MakeDmaPacketSprite(signed int texID, float *pos, unsigned int *color, float *uv) {
    void *pDmaCur;
    unsigned int currentSys;
    FDTm2Head *pTm2Head;
    volatile unsigned int uiPrim;
    unsigned long regs;
    struct FDGifTag *tag;
    struct FDGifTag *spriteTag;
    float fq;
    float uvT0;
    float uvT1;
    u_long textureReg;
    FDSys *packetSys;

    pTm2Head = *(FDTm2Head **)(sCurrentP + texID * 4);
    currentSys = sCurrentP + 0x9c;
    s_pSysInfo = (void *)(currentSys);
    if (FD_CheckDmaSpace(currentSys) != 0) {
        return;
    }
    pDmaCur = SYS->pDmaCurrent;
    SYS->pDmaLatest = pDmaCur;
    ((unsigned int *)pDmaCur)[0] = 0x20000006;
    ((unsigned int *)pDmaCur)[1] = (unsigned int)pDmaCur + 0x70;
    ((unsigned long *)pDmaCur)[1] = 0;
    pDmaCur = (unsigned char *)pDmaCur + 0x10;
    if (!SYS->bfMode) {
        ((unsigned int *)pDmaCur)[-1] = 0x51000006;
    }
    uiPrim = ((long)SYS->bfConText << 9) | 0x5e;
    tag = (struct FDGifTag *)pDmaCur;
    tag->nloop = 1;
    tag->eop = 0;
    tag->dummy = 0;
    tag->pre = 1;
    tag->prim = uiPrim & 0x7ff;
    tag->flg = 0;
    tag->nreg = 1;
    tag->regs = 0xe;
    pDmaCur = (unsigned char *)pDmaCur + 0x10;
    packetSys = SYS;
    textureReg = pTm2Head->fd_texinfo.fd_tex1;
    spriteTag = FontDraw_PkADFixed(pDmaCur, textureReg, packetSys->bfConText ? 0x15 : 0x14);
    regs = 0x525210;
    if (!packetSys->bfConText) {
        regs |= 6;
    } else {
        regs |= 7;
    }
    {
        u_long128 pre = 0;
        spriteTag->nloop = 1;
        spriteTag->eop = 1;
        spriteTag->dummy = 0;
        spriteTag->pre = pre ? 1 : 0;
        spriteTag->prim = 0;
        spriteTag->flg = 1;
        spriteTag->nreg = 6;
        spriteTag->regs = regs;
    }
    pDmaCur = (unsigned char *)spriteTag + 0x10;
    *(unsigned long *)pDmaCur = pTm2Head->fd_texinfo.fd_tex0;
    pDmaCur = (unsigned char *)pDmaCur + 8;
    fq = 1.0f;
    ((unsigned int *)pDmaCur)[0] = *color;
    ((unsigned int *)pDmaCur)[1] = *(unsigned int *)&fq;
    pDmaCur = (unsigned char *)pDmaCur + 8;
    uvT0 = uv[1];
    ((float *)pDmaCur)[0] = uv[0];
    ((float *)pDmaCur)[1] = uvT0;
    pDmaCur = (unsigned char *)pDmaCur + 8;
    FD_XYZ(pDmaCur, pos[0], pos[1]);
    pDmaCur = (unsigned char *)pDmaCur + 8;
    uvT1 = uv[3];
    ((float *)pDmaCur)[0] = uv[2];
    ((float *)pDmaCur)[1] = uvT1;
    pDmaCur = (unsigned char *)pDmaCur + 8;
    FD_XYZ(pDmaCur, pos[2], pos[3]);
    SYS->pDmaCurrent = (unsigned char *)pDmaCur + 8;
    SYS->usStrNum++;
    SYS->usEntryStrNum++;
}

static void _MakeDmaPacketTriangleStrip(signed int texID, float *pos, unsigned int *color, float *uv, float offsetTop) {
    void *pDmaCur;
    void *topRightXYZ;
    unsigned int currentSys;
    TSFDTm2Head *pTm2Head;
    volatile unsigned int uiPrim;
    unsigned long regs;
    struct TSFDGifTag *tag;
    struct TSFDGifTag *stripTag;
    float fq;
    float uvT0;
    float uvT1;
    float uvT2;
    float uvT3;
    u_long textureReg;
    TSFDSys *packetSys;

    pTm2Head = *(TSFDTm2Head **)(sCurrentP + texID * 4);
    currentSys = sCurrentP + 0x9c;
    s_pSysInfo = (void *)(currentSys);
    if (TSFD_CheckDmaSpace(currentSys) != 0) {
        return;
    }
    pDmaCur = TS_SYS->pDmaCurrent;
    TS_SYS->pDmaLatest = pDmaCur;
    ((unsigned int *)pDmaCur)[0] = 0x20000008;
    ((unsigned int *)pDmaCur)[1] = (unsigned int)pDmaCur + 0x90;
    ((unsigned long *)pDmaCur)[1] = 0;
    pDmaCur = (unsigned char *)pDmaCur + 0x10;
    if (!TS_SYS->bfMode) {
        ((unsigned int *)pDmaCur)[-1] = 0x51000008;
    }
    uiPrim = ((long)TS_SYS->bfConText << 9) | 0x5c;
    tag = (struct TSFDGifTag *)pDmaCur;
    tag->nloop = 1;
    tag->eop = 0;
    tag->dummy = 0;
    tag->pre = 1;
    tag->prim = uiPrim & 0x7ff;
    tag->flg = 0;
    tag->nreg = 1;
    tag->regs = 0xe;
    pDmaCur = (unsigned char *)pDmaCur + 0x10;
    packetSys = TS_SYS;
    textureReg = pTm2Head->fd_texinfo.fd_tex1;
    stripTag = FontDraw_PkADFixed(pDmaCur, textureReg, packetSys->bfConText ? 0x15 : 0x14);
    regs = 0x5252525210;
    if (!packetSys->bfConText) {
        regs |= 6;
    } else {
        regs |= 7;
    }
    {
        u_long128 pre = 0;
        stripTag->nloop = 1;
        stripTag->eop = 1;
        stripTag->dummy = 0;
        stripTag->pre = pre ? 1 : 0;
        stripTag->prim = 0;
        stripTag->flg = 1;
        stripTag->nreg = 10;
        stripTag->regs = regs;
    }
    pDmaCur = (unsigned char *)stripTag + 0x10;
    *(unsigned long *)pDmaCur = pTm2Head->fd_texinfo.fd_tex0;
    pDmaCur = (unsigned char *)pDmaCur + 8;
    fq = 1.0f;
    ((unsigned int *)pDmaCur)[0] = *color;
    ((unsigned int *)pDmaCur)[1] = *(unsigned int *)&fq;
    pDmaCur = (unsigned char *)pDmaCur + 8;
    uvT0 = uv[1];
    ((float *)pDmaCur)[0] = uv[0];
    ((float *)pDmaCur)[1] = uvT0;
    pDmaCur = (unsigned char *)pDmaCur + 8;
    TSFD_XYZ(pDmaCur, pos[0] + offsetTop, pos[1]);
    pDmaCur = (unsigned char *)pDmaCur + 8;
    uvT1 = uv[1];
    ((float *)pDmaCur)[0] = uv[2];
    ((float *)pDmaCur)[1] = uvT1;
    topRightXYZ = (unsigned char *)pDmaCur + 8;
    TSFD_XYZ(topRightXYZ, pos[2] + offsetTop, pos[1]);
    pDmaCur = (unsigned char *)topRightXYZ + 8;
    uvT2 = uv[3];
    ((float *)pDmaCur)[0] = uv[0];
    ((float *)pDmaCur)[1] = uvT2;
    pDmaCur = (unsigned char *)pDmaCur + 8;
    TSFD_XYZ(pDmaCur, pos[0], pos[3]);
    pDmaCur = (unsigned char *)pDmaCur + 8;
    uvT3 = uv[3];
    ((float *)pDmaCur)[0] = uv[2];
    ((float *)pDmaCur)[1] = uvT3;
    pDmaCur = (unsigned char *)pDmaCur + 8;
    TSFD_XYZ(pDmaCur, pos[2], pos[3]);
    TS_SYS->pDmaCurrent = (unsigned char *)pDmaCur + 8;
    TS_SYS->usStrNum++;
    TS_SYS->usEntryStrNum++;
}

void FontSetRefCurrentPtr(void *a0 /* r4 */) {
    sCurrentP = (u32)a0;
    return;
}

/* FontSetRefStatePtr @ 0x174890 .. 0x174898 (0x8 bytes) */

void FontSetRefStatePtr(void) {
    return;
}

void FsFontInitBugPath(void) {
    s32 s6;
    s32 s5;
    s32 a0;
    s32 s4;
    s32 s3;
    s32 s2;
    s32 s1;
    float f20;
    float *s0;
    s32 v1;
    float f0;
    u32 v0;

    s4 = 0;
    s3 = 0;
    do {
        v0 = (u32)BugPath;
        s5 = 0;
        s2 = 0;
        s1 = (s32)((u8 *)BugPath + s3);
        do {
            s6 = 0;
            f20 = 0.0f;
            s0 = (float *)(s32)(s1 + s2);
            do {
                *(f32 *)s0 = f20;
                if (s6 < (s32)0x64) {
                    v0 = rand();
                    a0 = 0xc8;
                    f0 = 9.99999975e-05f;
                    f20 = (f20 + (9.99999975e-05f * (float)((float)(s32)(u32)((u32)s6 *
                        (u32)((s32)((s32)v0 % (s32)(0xc8)) + -0x64)))));
                } else {
                    v0 = rand();
                    a0 = 0xc8;
                    f0 = 0.00999999978f;
                    f20 = (f20 + (0.00999999978f * (float)((float)(s32)(u32)((s32)((s32)v0 %
                        (s32)(0xc8)) + -0x64))));
                }
                s6 = s6 + 1;
                v1 = s6 < (s32)0x12c;
                s0 = (float *)((u8 *)s0 + 0x200);
            } while ((u32)v1 != 0);
            s5 = s5 + 1;
            v1 = s5 < (s32)0x40;
            s2 = s2 + 8;
        } while ((u32)v1 != 0);
        s4 = s4 + 1;
        v1 = s4 < (s32)2;
        s3 = (s32)s3 + 4;
    } while ((u32)v1 != 0);
    return;
}
