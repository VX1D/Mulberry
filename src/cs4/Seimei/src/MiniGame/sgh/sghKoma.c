#include "common.h"

/* sghKoma_SetAnime @ 0x20A810 .. 0x20A8F4 (0xe4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x20a890
 *   fpu: float literal 0x00000000 at 0x20a89c
 *   fpu: float literal 0x3cdd2f1b at 0x20a8bc
 *   fpu: float literal 0xbc75c28f at 0x20a8c0
 */

extern u32 sghMap_GetMainTblMap();
signed int sghKoma_MapIDtoKomaID(unsigned char a0 , unsigned char a1 );
extern signed int sghKoma_MapIDtoKomaID(unsigned char, unsigned char);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern u8 MdlMng[];


extern u32 sghGetGameInfo();
extern signed int SND_Play2D(signed int, signed short, signed short);
extern u8 gKomaInfo[];


struct KmMdl { u8 pad[0x20]; float Pos[4]; };

/* __sghKoma_SetMoveAnimeTgtPos @ 0x20AAD0 .. 0x20ABE8 (0x118 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets t1 at 0x20ab44
 *   fpu: float literal 0x3cdd2f1b at 0x20ab60
 *   fpu: mtc1 reinterprets t0 at 0x20aba8
 *   fpu: float literal 0x3dcccccd at 0x20abac
 *   declaration vs inferred signature: return void vs inferred float
 */

extern u32 sghMap_GetMainTblMap();
extern u8 gKomaInfo[];


extern u8 MdlMng[];


typedef struct { u8 knum[25]; u8 dummy[7]; } SGHMAP;
typedef struct { SGHMAP map[2]; float posList[25][4]; } SGHLMAP;


extern signed int sghKoma_MapIDtoKomaID(unsigned char, unsigned char);
static void __sghKoma_SetMoveAnimeStartPos(unsigned char a0 , unsigned char a1 , unsigned char a2 );
static void __sghKoma_SetMoveAnimeStartPos(unsigned char, unsigned char, unsigned char);
static void __sghKoma_SetMoveAnimeTgtPos(unsigned char a0 , unsigned char a1 , unsigned char a2 );
static void __sghKoma_SetMoveAnimeTgtPos(unsigned char, unsigned char, unsigned char);
extern u8 gKomaInfo[];


/* sghKoma_AnimeExecute @ 0x20BD70 .. 0x20BDFC (0x8c bytes, frame 0x10) */

extern u32 gSGH_KomaAnimeFnc[];
extern u8 gKomaInfo[];
extern u8 MdlMng[];

/* sghKoma_Init @ 0x20BE00 .. 0x20BE14 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j memset at 0x20be0c leaves the function
 *   return value dropped, call kept: the function is void
 */

extern void *memset(void *, int, unsigned int);
extern u8 gKomaInfo[];
static void __sghKoma_AnimeMove(void *lpMdlMng_);
extern void __sghKoma_AnimeMove(void *);
static void __sghKoma_AnimeSelect(float *a0 );
static u32 gSGH_KomaAnimeFnc[0x3] = {
    0, (u32)&__sghKoma_AnimeSelect, (u32)&__sghKoma_AnimeMove
};
static u8 gKomaInfo[0x600];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void sghKoma_Init(void);
void sghKoma_AnimeExecute(void *a0 );
void sghKoma_SetMoveAnimeInit(unsigned char startID_, unsigned char endID_, unsigned char playerID_);
void sghKoma_UpdatePos(void);
signed int sghKoma_MapIDtoKomaID(unsigned char a0 , unsigned char a1 );
static void __sghKoma_SetMoveAnimeStartPos(unsigned char a0 , unsigned char a1 , unsigned char a2 );
static void __sghKoma_SetMoveAnimeTgtPos(unsigned char a0 , unsigned char a1 , unsigned char a2 );
static void __sghKoma_AnimeSelect(float *a0 );
static void __sghKoma_AnimeMove(void *lpMdlMng_);
void sghKoma_SetAnime(unsigned char a0 , unsigned char a1 , unsigned char a2 );


void sghKoma_Init(void) {
    memset((u8 *)gKomaInfo, 0, 0x600);
    return;
}

void sghKoma_AnimeExecute(void *a0 /* r4 */) {
    u32 v1;

    v1 = (u32)gSGH_KomaAnimeFnc;
    v1 = *(s32 *)(s32)((u8 *)gSGH_KomaAnimeFnc + (u32)((u32)*(u8 *)(s32)((u8 *)(u8 *)(gKomaInfo +
        0x24) + (s32)((u32)((s32)((u8 *)a0 - (u32)(u8 *)(MdlMng + 0x119c0)) / (s32)(0x1c0)) *
        (u32)(0x30))) << 2));
    if (v1 != 0) {
        ((void (*)(void *))(s32)v1)(a0);
    }
    return;
}

void sghKoma_SetMoveAnimeInit(unsigned char startID_, unsigned char endID_, unsigned char playerID_) {
    int komaID;

    komaID = sghKoma_MapIDtoKomaID(startID_, playerID_);
    *(u8 *)((u32)(gKomaInfo + 0x24) + (s32)(komaID * 0x30)) = 2;
    __sghKoma_SetMoveAnimeStartPos(komaID, startID_, playerID_);
    __sghKoma_SetMoveAnimeTgtPos(komaID, endID_, playerID_);
}

void sghKoma_UpdatePos(void) {
    SGHLMAP *pMap;
    SGHMAP *paMap_w;
    SGHMAP *paMap_b;
    float (*paPosList)[4];
    float *pPos;
    unsigned int knum;
    unsigned int knum_c;
    unsigned int i;
    u8 *lpMdlMng;

    pMap = (SGHLMAP *)sghMap_GetMainTblMap();
    paMap_w = &pMap->map[0];
    paMap_b = &pMap->map[1];
    paPosList = pMap->posList;
    pPos = 0;
    knum = 0;
    knum_c = 0;
    i = 0;
    lpMdlMng = (u8 *)(MdlMng + 0x13400);
    i = 1;
    pPos = paPosList[1];
    for (; i < 0x19; i++, pPos += 4) {
        knum = paMap_w->knum[i];
        for (knum_c = 1; knum_c < knum + 1; knum_c++) {
            *(float *)(lpMdlMng + 0x20) = pPos[0];
            *(float *)(lpMdlMng + 0x24) = pPos[1] - 0.027f * (float)(s32)((knum_c - 1) >> 2);
            *(float *)(lpMdlMng + 0x28) = pPos[2] - 0.1f * (float)(s32)((knum_c - 1) & 3);
            *(float *)(lpMdlMng + 0x2c) = pPos[3];
            lpMdlMng += 0x1c0;
        }
    }
    knum = paMap_w->knum[0];
    for (i = 0; i < knum; i++) {
        *(float *)(lpMdlMng + 0x20) = paPosList[0][0];
        *(float *)(lpMdlMng + 0x24) = paPosList[0][1] - 0.027f * (float)i;
        *(float *)(lpMdlMng + 0x28) = paPosList[0][2];
        *(float *)(lpMdlMng + 0x2c) = paPosList[0][3];
        lpMdlMng += 0x1c0;
    }
    lpMdlMng = (u8 *)(MdlMng + 0x119c0);
    for (i = 1; i < 0x19; i++) {
        knum = paMap_b->knum[i];
        pPos = paPosList[0x19 - i];
        for (knum_c = 1; knum_c < knum + 1; knum_c++) {
            *(float *)(lpMdlMng + 0x20) = pPos[0];
            *(float *)(lpMdlMng + 0x24) = pPos[1] - 0.027f * (float)(s32)((knum_c - 1) >> 2);
            *(float *)(lpMdlMng + 0x28) = pPos[2] - 0.1f * (float)(s32)((knum_c - 1) & 3);
            *(float *)(lpMdlMng + 0x2c) = pPos[3];
            lpMdlMng += 0x1c0;
        }
    }
    knum = paMap_b->knum[0];
    for (i = 0; i < knum; i++) {
        *(float *)(lpMdlMng + 0x20) = paPosList[0][0];
        *(float *)(lpMdlMng + 0x24) = paPosList[0][1] - 0.027f * (float)i;
        *(float *)(lpMdlMng + 0x28) = paPosList[0][2] - 0.1f;
        *(float *)(lpMdlMng + 0x2c) = paPosList[0][3];
        lpMdlMng += 0x1c0;
    }
}


/* sghKoma_MapIDtoKomaID @ 0x20AD30 .. 0x20AE74 (0x144 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */



signed int sghKoma_MapIDtoKomaID(unsigned char a0 /* r4 */, unsigned char a1 /* r5 */) {
    u8 *row;
    u8 *base;
    u32 y;
    u8 sum;
    s32 i;
    s32 adj;

    base = (u8 *)sghMap_GetMainTblMap();
    y = (u8)a1;
    row = base + (y << 5);
    sum = 0;
    if (a0 == 0) {
        if (y == 0) {
            return 0x1d;
        }
        return 0xe;
    }
    for (i = 1; i < a0 + 1; i++) {
        sum += row[i];
    }
    adj = sum - 1;
    adj = adj + (a1 == 0 ? 0xf : 0);
    return adj;
}





static void __sghKoma_SetMoveAnimeStartPos(unsigned char a0 /* r4 */, unsigned char a1 /* r5 */, unsigned char a2 /* r6 */) {
    u8 *tbl;
    u8 *posTbl;
    float *pos;
    u32 knum;
    s32 h;
    s32 d;
    s32 idx;
    u32 off;

    tbl = (u8 *)sghMap_GetMainTblMap();
    posTbl = 0x40 + tbl;
    d = 0;
    knum = tbl[(a2 << 5) + a1];
    if (a1 != 0) {
        d = knum - 1;
        h = (u32)d >> 2;
        d = d & 3;
        if (a2 == 0) {
            idx = a1;
        } else {
            idx = 0x19 - a1;
        }
        pos = (float *)(posTbl + idx * 16);
    } else {
        h = knum - 1;
        pos = (float *)posTbl;
    }
    off = a0 * 0x30;
    *(f32 *)((u8 *)(gKomaInfo + 0x0) + off) = pos[0];
    *(f32 *)((u8 *)(gKomaInfo + 0x4) + off) = pos[1] - 0.027f * (float)h;
    *(f32 *)((u8 *)(gKomaInfo + 0x8) + off) = pos[2] - 0.1f * (float)d;
    *(f32 *)((u8 *)(gKomaInfo + 0xc) + off) = pos[3];
    *(u32 *)((u8 *)(gKomaInfo + 0x20) + off) = 0;
}

static void __sghKoma_SetMoveAnimeTgtPos(unsigned char a0 /* r4 */, unsigned char a1 /* r5 */, unsigned char a2 /* r6 */) {
    u8 *tbl;
    u8 *posTbl;
    float *pos;
    u32 off;
    s32 row;
    s32 col;
    s32 idx;

    tbl = (u8 *)sghMap_GetMainTblMap();
    off = *(tbl + (a2 << 5) + a1);
    row = off >> 2;
    col = 3 & off;
    posTbl = 0x40 + tbl;
    if (a2 == 0) {
        idx = a1;
    } else {
        idx = 0x19 - a1;
    }
    pos = (float *)(posTbl + idx * 16);
    off = a0 * 0x30;
    *(f32 *)((u8 *)(gKomaInfo + 0x10) + off) = pos[0];
    *(f32 *)((u8 *)(gKomaInfo + 0x14) + off) = pos[1] - 0.027f * (float)row;
    *(f32 *)((u8 *)(gKomaInfo + 0x18) + off) = pos[2] - 0.1f * (float)col;
    *(f32 *)((u8 *)(gKomaInfo + 0x1c) + off) = pos[3];
}


/* __sghKoma_AnimeSelect @ 0x20AAC0 .. 0x20AAC8 (0x8 bytes) */
/*
 * dcomp notes:
 *   a0 typed from the __sghKoma_AnimeSelect call table
 */

static void __sghKoma_AnimeSelect(float *a0 /* r4 */) {
    return;
}

static void __sghKoma_AnimeMove(void *lpMdlMng_) {
    struct KmMdl *lpMdlMng = (struct KmMdl *)lpMdlMng_;
    u8 *pGmInfo;
    int mdlID;
    int frame;
    int off;
    float *p_bpos;
    float *p_epos;

    pGmInfo = (u8 *)sghGetGameInfo();
    mdlID = ((u8 *)lpMdlMng - (u8 *)(MdlMng + 0x119c0)) / 0x1c0;
    off = mdlID * 0x30;
    frame = *(int *)((u8 *)(gKomaInfo + 0x20) + off);
    if (frame == 0x19) {
        SND_Play2D(0x138a, 0x7f, 0);
        *(u8 *)((u8 *)(gKomaInfo + 0x24) + off) = 0;
        *pGmInfo = 0x15;
    } else {
        p_bpos = (float *)((u8 *)gKomaInfo + off);
        p_epos = p_bpos + 4;
        lpMdlMng->Pos[0] = p_bpos[0] + (float)frame * (0.04f * (p_epos[0] - p_bpos[0]));
        lpMdlMng->Pos[1] = p_bpos[1] + (float)frame * (0.04f * (p_epos[1] - p_bpos[1]));
        lpMdlMng->Pos[2] = p_bpos[2] + (float)frame * (0.04f * (p_epos[2] - p_bpos[2]));
        lpMdlMng->Pos[3] = p_bpos[7] + 0.0f;
        lpMdlMng->Pos[1] = lpMdlMng->Pos[1] + (float)(0.002 * (double)frame * (double)(frame - 0x19));
        { u8 *k = gKomaInfo + 0x20; (*(int *)(k + off))++; }
    }
}

void sghKoma_SetAnime(unsigned char a0 /* r4 */, unsigned char a1 /* r5 */, unsigned char a2 /* r6 */) {
    u8 *obj;
    u8 *tbl;
    s32 xt1;
    u32 v;

    tbl = (u8 *)sghMap_GetMainTblMap();
    xt1 = sghKoma_MapIDtoKomaID(a1, a2) + 0xa1;
    obj = MdlMng + xt1 * 0x1c0;
    v = *(tbl + ((u16)a2 << 5) + (s32)a1);
    if (a1 != 0) {
        xt1 = (((v - 1))) >> 2;
    } else {
        xt1 = v - 1;
    }
    *(f32 *)(obj + 0x30) = 0.0f;
    *(f32 *)(0x34 + obj) = 0.0f;
    *(f32 *)(obj + 0x38) = 0.0f;
    *(f32 *)(obj + 0x24) = -0.015f - (float)xt1 * 0.027f;
    ChangeAnimParam(obj, a0, 0.0f);
}
