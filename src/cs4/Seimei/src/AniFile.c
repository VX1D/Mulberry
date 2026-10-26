#include "common.h"

typedef struct AniRemapEntry {
    u32 tag;
    s32 (*remap)(void *pMdl, void *pEntry);
    s32 (*make)(void *pMdl, void *pEntry);
} AniRemapEntry;

typedef struct AniEntry {
    u32 tag;    /* 0x0 */
    s32 off_4;  /* 0x4 */
    s32 off_8;  /* 0x8 */
    s32 off_C;  /* 0xC */
} AniEntry;

typedef struct AniWork {
    u8 *p;
} AniWork;

typedef struct AniHdr {
    u32 f0;      /* 0x0 */
    s32 base;    /* 0x4 */
    u32 count;   /* 0x8 */
} AniHdr;

typedef struct Jcon {
    u32 f0;      /* 0x0 */
    u32 made;    /* 0x4 */
    u32 count;   /* 0x8 */
    u32 off_C;   /* 0xC */
} Jcon;

extern u8 MdlData[];
extern void InitMic(u8 *pMdl, s32 id);

static s32 MakeAniName(void *pMdl, void *pData);
static s32 MakeJcon(void *pMdl, void *pData);
static s32 MakePlayParam(void *pMdl, void *pData);
static s32 MakeMic(void *pMdl, void *pData);
static s32 MakeObjGroup(void *pMdl, void *pData);
static s32 RemapAniName(void *pMdl, void *pData);
static s32 RemapAniNop(void *pMdl, void *pData);

s32 SetAniData(s32 idx, u8 *pData);

static AniRemapEntry RemapInfo[5] = {
    { 0x5052474F, RemapAniNop, MakeObjGroup },
    { 0x0043494D, RemapAniNop, MakeMic },
    { 0x4D504C50, RemapAniNop, MakePlayParam },
    { 0x4E4F434A, RemapAniNop, MakeJcon },
    { 0x4D414E41, RemapAniName, MakeAniName },
};


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
s32 SetAniData(s32 idx, u8 *pData);
static s32 RemapAniNop(void *pMdl, void *pData);
static s32 RemapAniName(void *pMdl, void *pData);
static s32 MakeObjGroup(void *pMdl, void *pData);
static s32 MakeMic(void *pMdl, void *pData);
static s32 MakePlayParam(void *pMdl, void *pData);
static s32 MakeJcon(void *pMdl, void *pData);
static s32 MakeAniName(void *pMdl, void *pData);


/* SetAniData @ 0x12E810 .. 0x12E994 (0x184 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0012E888
 *   cfg: loop body is not one contiguous region: .L0012E8C8
 *   cfg: loop body is not one contiguous region: .L0012E8D8
 *   cfg: kept branch: 0x12e8d8 if (..) goto .L0012E900
 *   cfg: loop body is not one contiguous region: .L0012E920
 *   cfg: kept branch: 0x12e920 if (..) goto .L0012E948
 *   v1#4 is the pointer held in @564+0x10
 *   v1#2 is the pointer held in @552+0x14
 *   declaration vs inferred signature: return s32 vs inferred void
 */

s32 SetAniData(s32 idx, u8 *pData) {
    s32 a2;
    u8 *s3;
    u8 *s2;
    u32 v1;
    AniRemapEntry *remap;
    u32 tag;
    u32 *s1;
    s32 s0;
    u32 v0;
    AniRemapEntry *remap2;
    u32 tag2;

    a2 = (u32)idx * 0xc;
    idx = (u32)idx * 0xd;
    v1 = (u32)MdlData;
    idx = (u32)idx << 7;
    s2 = (u8 *)((u8 *)MdlData + idx);
    if ((u32)pData != 0) {
        v1 = *(s32 *)(pData + 0x10);
        *(u32 *)(s2 + 0x14) = v1;
        s3 = (u8 *)*(s32 *)(s2 + 0x14);
        v1 = *(s32 *)(s3 + 0x10);
        if (v1 != 0) {
            v1 = (s32)(s3 + (u32)v1);
            *(u32 *)(s3 + 0x10) = v1;
        }
        idx = *(s32 *)(s3 + 0xc);
        pData = (u8 *)*(s32 *)(s3 + 0x10);
        a2 = 0;
        if ((u8 *)0 < (u8 *)(u32)idx) {
            do {
                v1 = *(s32 *)(pData + 4);
                if (v1 != 0) {
                    v1 = (s32)(s3 + (u32)v1);
                    *(u32 *)(pData + 4) = v1;
                }
                idx = *(s32 *)(s3 + 0xc);
                a2 = a2 + 1;
                v1 = (u32)a2 < (u32)idx;
                pData = (u8 *)(pData + 0x10);
            } while (v1 != 0);
        }
        s1 = (u32 *)*(s32 *)(s3 + 0x10);
        s0 = 0;
        if ((u8 *)0 < (u8 *)(u32)idx) {
            do {
                tag = *(u32 *)s1;
                a2 = 0;
                remap = RemapInfo;
                do {
                    v1 = remap->tag;
                    if (tag != v1) {
                        goto _L0012E900;
                    }
                    v0 = (s32)remap->remap;
                    idx = (s32)s2;
                    pData = (u8 *)s1;
                    v0 = ((u32 (*)(s32, s32, u32))(s32)v0)(idx, (s32)pData, a2);
                    break;
                    _L0012E900:;
                    a2 = a2 + 1;
                    v1 = (u32)a2 < (u32)5;
                    remap = remap + 1;
                } while (v1 != 0);
                tag2 = *(u32 *)s1;
                a2 = 0;
                remap2 = RemapInfo;
                do {
                    v1 = remap2->tag;
                    if (tag2 != v1) {
                        goto _L0012E948;
                    }
                    v0 = (s32)remap2->make;
                    idx = (s32)s2;
                    pData = (u8 *)s1;
                    v0 = ((u32 (*)(s32, s32, u32))(s32)v0)(idx, (s32)pData, a2);
                    break;
                    _L0012E948:;
                    a2 = a2 + 1;
                    v1 = (u32)a2 < (u32)5;
                    remap2 = remap2 + 1;
                } while (v1 != 0);
                v1 = *(s32 *)(s3 + 0xc);
                s0 = s0 + 1;
                v1 = (u32)s0 < v1;
                s1 = (u32 *)(u8 *)(s1 + 4);
            } while (v1 != 0);
        }
        v1 = 1;
        *(u32 *)(s3 + 4) = v1;
    }
    return v0;
}


static s32 RemapAniNop(void *pMdl, void *pData) {
    return 1;
}

/* RemapAniName @ 0x12E790 .. 0x12E7F4 (0x64 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0012E7B0
 *   a0 takes slot 0 only because of the ABI order
 *   a0 typed from the RemapAniName call table
 *   declaration vs inferred signature: return s32 vs inferred u32
 */

static s32 RemapAniName(void *pMdl, void *pData) {
    volatile AniHdr *pHdr = (AniHdr *)pData;
    volatile u32 p;
    u32 i;
    u32 v1;

    p = pHdr->base;
    for (i = 0; i < pHdr->count; i++) {
        v1 = p;
        if (v1 != 0) {
            p = pHdr->base + v1;
        }
        p = p + 1;
    }
    return 1;
}

static s32 MakeObjGroup(void *pMdl, void *pData) {
    *(u32 *)((u8 *)pMdl + 0x50) = *(u32 *)((u8 *)pData + 4);
    return 1;
}

static s32 MakeMic(void *pMdl, void *pData) {
    InitMic(pMdl, *(s32 *)((u8 *)pData + 4));
    return 1;
}

static s32 MakePlayParam(void *pMdl, void *pData) {
    u8 *p = pData;

    *(u32 *)((u8 *)pMdl + 0x2C) = *(u32 *)(p + 4);
    *(u32 *)((u8 *)pMdl + 0x00) = *(u32 *)(p + 8);
    return 1;
}

/* MakeJcon @ 0x12E630 .. 0x12E738 (0x108 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x12e734 computes the return value
 *   cfg: loop body is not one contiguous region: .L0012E670
 *   cfg: loop body is not one contiguous region: .L0012E6D8
 *   declaration vs inferred signature: return s32 vs inferred u32
 */

static s32 MakeJcon(void *pMdl, void *pData) {
    u32 v0;
    u8 *a0_bytes; // a0
    u8 *a1_bytes; // a1
    u32 a2;
    s32 v1;
    u8 *a3;

    a1_bytes = (u8 *)*(s32 *)(((u8 *)(u8 *)pData + 4));
    *(u32 *)(((u8 *)(u8 *)pMdl + 0x28)) = (s32)a1_bytes;
    v0 = *(s32 *)(a1_bytes + 4);
    if (v0 == 0) {
        v0 = *(s32 *)(a1_bytes + 0xc);
        if (v0 != 0) {
            *(u32 *)(a1_bytes + 0xc) = (s32)(a1_bytes + v0);
        }
        v0 = *(s32 *)(a1_bytes + 8);
        v1 = 0;
        if ((u8 *)0 < (u8 *)v0) {
            v0 = 0;
            do {
                a2 = (s32)((u8 *)*(s32 *)(a1_bytes + 0xc) + v0);
                a0_bytes = (u8 *)*(s32 *)a2;
                if ((u32)(s32)a0_bytes != 0) {
                    *(u32 *)a2 = (s32)(a1_bytes + (u32)(a0_bytes));
                }
                a0_bytes = (u8 *)*(s32 *)(s32)((u8 *)*(s32 *)(a1_bytes + 0xc) + v0);
                a2 = (s32)(a0_bytes + 4);
                a0_bytes = (u8 *)*(s32 *)(a0_bytes + 4);
                if ((u32)(s32)a0_bytes != 0) {
                    *(u32 *)a2 = (s32)(a1_bytes + (u32)(a0_bytes));
                }
                a0_bytes = (u8 *)*(s32 *)(s32)((u8 *)*(s32 *)(a1_bytes + 0xc) + v0);
                a3 = (u8 *)*(s32 *)(a0_bytes + 4);
                a0_bytes = (u8 *)*(s32 *)a0_bytes;
                a2 = 0;
                if ((u8 *)0 < (u8 *)a0_bytes) {
                    do {
                        a0_bytes = (u8 *)*(s32 *)(a3 + 0xc);
                        if ((u32)(s32)a0_bytes != 0) {
                            *(u32 *)(a3 + 0xc) = (s32)(a1_bytes + (u32)(a0_bytes));
                        }
                        a2 = a2 + 1;
                        a0_bytes = (u8 *)(s32)(a2 < (u32)*(s32 *)*(s32 *)(s32)((u8 *)v0 + *(s32
                            *)(a1_bytes + 0xc)));
                        a3 = (u8 *)(a3 + 0x10);
                    } while ((u32)(s32)a0_bytes != 0);
                }
                v1 = v1 + 1;
                a0_bytes = (u8 *)(s32)((u32)v1 < (u32)*(s32 *)(a1_bytes + 8));
                v0 = v0 + 4;
            } while ((u32)(s32)a0_bytes != 0);
        }
        *(u32 *)(a1_bytes + 4) = 1;
    }
    return 1;
}

static s32 MakeAniName(void *pMdl, void *pData) {
    return 1;
}
