#include "common.h"



/* __sghDice_AnimeRot @ 0x208100 .. 0x208154 (0x54 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0xbecd7dbf at 0x208134
 */

extern float Math_GetAngle360(float);

/* sghDice_SetMdlSpots @ 0x208160 .. 0x208230 (0xd0 bytes) */
/*
 * dcomp notes:
 *   literal: @839 -> 0x2573c0
 *   indirect: jr v1 at 0x2081a0 -> <v1>
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u8 MdlMng[];

extern signed int SND_Play2D(signed int, signed short, signed short);
extern void sceVu0CopyVector(void *, void *);
extern int rand(void);
extern u8 gDice[];
extern const u32 DICE_ANIME_INIT_POS[];


/* sghDice_AnimeExecute @ 0x2083A0 .. 0x20842C (0x8c bytes, frame 0x10) */

static u32 gSGH_DiceAnimeFnc[0x3];
static u8 gDice[0xc0];

/* sghDice_SetAnimeInit @ 0x208430 .. 0x2085FC (0x1cc bytes, frame 0x90) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3c8ef34d at 0x2084b4
 *   fpu: mtc1 reinterprets v0 at 0x2084c0
 *   fpu: float literal 0x3c8ef34d at 0x2084e8
 *   fpu: mtc1 reinterprets v0 at 0x2084f4
 *   fpu: float literal 0x3c8ef34d at 0x208524
 *   fpu: mtc1 reinterprets v0 at 0x208530
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern int rand(void);
extern void sceVu0CopyVector(void *, void *);
const u32 DICE_ANIME_INIT_POS[0x8];
static u8 gDice[0xc0];
const u32 DICE_ANIME_INIT_SCALE[0x4];

/* sghDice_UseSpots @ 0x208600 .. 0x208660 (0x60 bytes) */
/*
 * dcomp notes:
 *   delay: sll at 0x208618 writes a register its branch at 0x208614 reads
 *   cfg: loop body is not one contiguous region: .L00208610
 *   declaration vs inferred signature: return unsigned char vs inferred u32
 */

extern u8 gDice[];

/* sghDice_IsUsed @ 0x2086E0 .. 0x208728 (0x48 bytes) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x2086f0 if (..) goto .L00208718
 *   cfg: kept branch: 0x208708 if (..) goto .L00208718
 *   cfg: kept goto: 0x208710 -> .L00208720
 */

extern u8 gDice[];

/* sghDice_Init @ 0x2087C0 .. 0x2087D8 (0x18 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u8 gDice[];
void __sghDice_AnimeCast(void *a0);
extern void __sghDice_AnimeCast(void *);
static void __sghDice_AnimeRot(void *a0 );
static u32 gSGH_DiceAnimeFnc[0x3] = {
    0, (u32)&__sghDice_AnimeRot, (u32)&__sghDice_AnimeCast
};/* __sghDice_AnimeCast @ 0x207E20 */
extern u32 sghGetGameInfo();
extern void sceVu0CopyVector(void *, void *);
extern signed int SND_Play2D(signed int, signed short, signed short);
extern float Math_GetAngle360(float);
extern u8 gDice[];
extern u8 MdlMng[];

struct CastMdl { u8 pad0[0x20]; float Pos[4]; float Ang[4]; u8 pad1[0x1c0 - 0x40]; };
struct CastGmInfo { u8 modeID, ctrlID, gameID, dbgID, nowPlayerID, aPlayerType[2], anWin_num[2]; };
struct CastDice { float s_pos[4]; float e_pos[3][4]; float w[4]; int frm_cnt; u8 bound_cnt; u8 animeID; u8 spots; u8 _pad0[9]; };

static u8 gDice[0xc0];
const u32 DICE_ANIME_INIT_POS[0x8] = {
    0x3f333333, 0xbecccccd, 0x3d23d70a, 0x3f800000, 0x3f400000, 0xbecccccd, 0xbd75c28f,
    0x3f800000
};
const u32 DICE_ANIME_INIT_SCALE[0x4] = {
    0x3f99999a, 0x3f99999a, 0x3f99999a, 0x3f800000
};

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 sghDice_Init(void);
void sghDice_SetDiceSpots(unsigned char a0 , unsigned char a1 );
u8 sghDice_GetDiceSpotsList(u8 *a0 );
u32 sghDice_IsUsed(void);
unsigned char sghDice_EraseSpots(unsigned char a0 );
unsigned char sghDice_UseSpots(unsigned char a0 );
void sghDice_SetAnimeInit(unsigned char a0 );
void sghDice_AnimeExecute(struct dw_2780647 *a0 );
void sghDice_CastStart(unsigned char modeID_);
void sghDice_SetMdlSpots(unsigned char a0 , unsigned char a1 );
static void __sghDice_AnimeRot(void *a0 );
void __sghDice_AnimeCast(void *a0);


u32 sghDice_Init(void) {
    *(u8 *)((u8 *)&gDice + 0x56) = 0xff;
    *(u8 *)((u8 *)&gDice + 0xb6) = 0xff;
    return;
}

/* sghDice_SetDiceSpots @ 0x208790 .. 0x2087B4 (0x24 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

void sghDice_SetDiceSpots(unsigned char a0 /* r4 */, unsigned char a1 /* r5 */) {
    u32 a0_word = a0;
    u32 a2;
    u8 *v1;

    a2 = (u8)a0_word;
    a0_word = a2 << 1;
    v1 = (u8 *)gDice + 0x56;
    a0_word = a0_word + a2;
    *(u8 *)(u8 *)(s32)((u8 *)v1 + (u32)(a0_word << 5)) = (u8)a1;
    return;
}

/* sghDice_GetDiceSpotsList @ 0x208730 .. 0x208790 (0x60 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0xc escapes at 0x208740
 *   stack: 2-byte aggregate copy in 1-byte chunks at 0x208784
 *   return without a value in a non-void function
 */

u8 sghDice_GetDiceSpotsList(u8 *a0 /* r4 */) {
    u32 a2;
    u32 a1;
    u32 v1;
    struct __copy_u8_2 { u8 b[2]; };

    {
        u8 stackFrame_C[2] __attribute__((aligned(4))) = {0};
        v1 = (u32)((u8 *)&stackFrame_C[0]);
        a2 = gDice[0x56];
        *(u8 *)((u8 *)&stackFrame_C[0]) = a2;
        a1 = gDice[0xb6];
        ((u8 *)stackFrame_C)[1] = a1;
        *(struct __copy_u8_2 *)a0 = *(struct __copy_u8_2 *)((u8 *)&stackFrame_C[0]);
        return;
    }
}

u32 sghDice_IsUsed(void) {
    u32 v1;
    u32 v0;

    v1 = *(u8 *)((u8 *)&gDice + 0x56);
    v0 = 0xff;
    if (v1 != 0) {
        if (v1 != v0) {
            goto _L00208718;
        }
    }
    v1 = *(u8 *)((u8 *)&gDice + 0xb6);
    v0 = 0xff;
    if (v1 != 0) {
        if (v1 != v0) {
            goto _L00208718;
        }
    }
    v0 = 1;
    goto _L00208720;
    _L00208718:;
    v0 = 0;
    _L00208720:;
    return v0;
}

/* sghDice_EraseSpots @ 0x208660 .. 0x2086E0 (0x80 bytes) */
/*
 * dcomp notes:
 *   delay: sll at 0x208678 writes a register its branch at 0x208674 reads
 *   cfg: loop body is not one contiguous region: .L00208670
 *   declaration vs inferred signature: return unsigned char vs inferred u32
 */

unsigned char sghDice_EraseSpots(unsigned char a0 /* r4 */) {
    u32 a0_2;
    s32 a2;
    u32 v1;
    u8 v0;

    v1 = (u8)a0;
    a2 = 0;
    a0_2 = (u32)gDice;
    do {
        v0 = *(u8 *)((a0_2 + 0x56));
        if (v1 == (u32)v0) {
            v0 = 1;
            *(u8 *)(u32)((u32)(u8 *)(gDice + 0x56) + (u32)((u32)((u32)a2 * (u32)(3)) << 5)) = 0xff;
            v1 = (u32)(u8 *)(MdlMng + 0x17142);
            *(u8 *)(u32)(v1 + (u32)((u32)((u32)a2 * (u32)(7)) << 6)) = v0;
            return v0;
        }
        a2 = a2 + 1;
        v0 = (u32)a2 < (u32)2;
        a0_2 = a0_2 + 0x60;
    } while ((u32)v0 != 0);
    return 0;
}

unsigned char sghDice_UseSpots(unsigned char a0 /* r4 */) {
    s32 a2;
    u32 v0;
    u32 a0_2;

    a2 = 0;
    a0_2 = (u32)gDice;
    do {
        v0 = *(u8 *)((a0_2 + 0x56));
        if ((u32)a0 == v0) {
            *(u32 *)(u32)((u32)(u8 *)(MdlMng + 0x1724c) + (u32)((u32)((u32)a2 * (u32)(7)) << 6)) =
                0x3f800000;
            return 1;
        }
        a2 = a2 + 1;
        v0 = (u32)a2 < (u32)2;
        a0_2 = a0_2 + 0x60;
    } while (v0 != 0);
    return 0;
}

void sghDice_SetAnimeInit(unsigned char a0 /* r4 */) {
    u8 *s5;
    u8 *s7;
    s32 s4;
    u8 *s3;
    s32 s2;
    u8 *s1;
    u8 *a1;
    u8 *s0;
    s32 v1;
    s32 hi;
    float f1;
    float f0;
    u32 v0;
    u32 a0_2;

    s5 = (u8 *)(MdlMng + 0x17140);
    s7 = (u8 *)(MdlMng + 0x17300);
    s4 = 0;
    s2 = 0;
    s1 = (u8 *)DICE_ANIME_INIT_POS;
    s0 = gDice;
    do {
        v0 = 0x10000;
        v0 = (u32)MdlMng;
        s3 = (u8 *)((u8 *)MdlMng + (s32)(s2 + (0x10000 | 0x7140)));
        v0 = rand();
        a0_2 = 0x2d;
        v1 = 0x3c8e0000;
        hi = (s32)v0 % (s32)(0x2d);
        v0 = 0x3c8e0000 | 0xf34d;
        f0 = 0.0174499992f;
        *(f32 *)(s3 + 0x30) = (0.0174499992f * (float)((float)(s32)(u32)(hi + -0x16)));
        v0 = rand();
        a0_2 = 0x2d;
        v1 = 0x3c8e0000;
        hi = (s32)v0 % (s32)(0x2d);
        v0 = 0x3c8e0000 | 0xf34d;
        f0 = 0.0174499992f;
        *(f32 *)(s3 + 0x34) = (0.0174499992f * (float)((float)(s32)(u32)(hi + -0x16)));
        v0 = rand();
        a0_2 = 0x78;
        v1 = 0x3c8e0000;
        hi = (s32)v0 % (s32)(0x78);
        v0 = 0x3c8e0000 | 0xf34d;
        f0 = 0.0174499992f;
        v0 = hi + -0x3c;
        f1 = ((float)(s32)v0);
        f0 = (0.0174499992f * f1);
        *(f32 *)(s3 + 0x38) = f0;
        sceVu0CopyVector((void *)(s3 + 0x20), (void *)s1);
        sceVu0CopyVector((void *)s0, (void *)(s3 + 0x20));
        a1 = (u8 *)DICE_ANIME_INIT_SCALE;
        sceVu0CopyVector((void *)(s3 + 0x40), (void *)DICE_ANIME_INIT_SCALE);
        v1 = 0x3f800000;
        s4 = s4 + 1;
        *(u32 *)(s3 + 0x10c) = 0x3f800000;
        s2 = s2 + 0x1c0;
        v1 = s4 < (s32)2;
        s1 = (u8 *)(s1 + 0x10);
        s0 = (u8 *)(s0 + 0x60);
    } while ((u32)v1 != 0);
    a0_2 = (u8)a0;
    v1 = 1;
    switch (a0_2) {
    case 0:
        *(u8 *)(s5 + 2) = 0;
        gDice[0x55] = v1;
        break;
    case 1:
        *(u8 *)(s5 + 2) = 0;
        *(u8 *)(s7 + 2) = 0;
        gDice[0x55] = v1;
        gDice[0xb5] = v1;
    }
    return;
}

void sghDice_AnimeExecute(struct dw_2780647 *a0 /* r4 */) {
    u32 v1;

    v1 = (u32)gSGH_DiceAnimeFnc;
    v1 = *(s32 *)(s32)((u8 *)gSGH_DiceAnimeFnc + (u32)((u32)*(u8 *)(s32)((u8 *)(u8 *)(gDice + 0x55)
        + (s32)((u32)((s32)((u8 *)(void *)a0 - (u32)(u8 *)(MdlMng + 0x17140)) / (s32)(0x1c0)) *
        (u32)(0x60))) << 2));
    if (v1 != 0) {
        ((void (*)(void *))(s32)v1)((void *)a0);
    }
    return;
}

void sghDice_CastStart(unsigned char modeID_) {
    float e_pos[4];
    float dx;
    int i;
    int dice_num;
    u8 *dice;
    const u32 *init;

    dice_num = (modeID_ == 0) ? 1 : 2;
    SND_Play2D(0x138b, 0x7f, 0);
    i = 0;
    if (0 < dice_num) {
        dice = gDice;
        init = DICE_ANIME_INIT_POS;
        do {
            sceVu0CopyVector(e_pos, (void *)init);
            e_pos[0] = 0.1f + 0.001f * (float)-(rand() % 500);
            e_pos[1] = -0.0360000022f;
            sceVu0CopyVector(dice + 0x10, e_pos);
            sceVu0CopyVector(dice + 0x20, e_pos);
            sceVu0CopyVector(dice + 0x30, e_pos);
            dx = e_pos[0] - *(float *)dice;
            *(float *)(dice + 0x10) = 0.667f * dx + *(float *)dice;
            *(float *)(dice + 0x20) = 0.917f * dx + *(float *)dice;
            *(u32 *)(dice + 0x50) = 0;
            *(u8 *)(dice + 0x54) = 0;
            *(u8 *)(dice + 0x55) = 2;
            i++;
            init += 4;
            dice += 0x60;
        } while (i < dice_num);
    }
}

void sghDice_SetMdlSpots(unsigned char a0 /* r4 */, unsigned char a1 /* r5 */) {
    s32 a2;
    u32 v1;
    u32 a0_2;
    u32 a1_2;

    v1 = (u8)a0;
    a2 = v1 + 0xd3;
    v1 = (u8)a1;
    a0_2 = (u32)MdlMng;
    a1_2 = (u32)a2 << 3;
    a1_2 = a1_2 - a2;
    a1_2 = a1_2 << 6;
    a1_2 = (s32)((u8 *)MdlMng + (u32)a1_2);
    a0_2 = 0x2573c0;
    switch (v1) {
    case 6:
        v1 = 0x40490fdb;
        *(u32 *)((a1_2 + 0x30)) = 0x40490fdb;
        *(u32 *)((a1_2 + 0x38)) = 0;
        break;
    case 5:
        *(u32 *)((a1_2 + 0x30)) = 0;
        v1 = -0x4036f025;
        *(u32 *)((a1_2 + 0x38)) = -0x4036f025;
        break;
    case 4:
        v1 = -0x4036f025;
        *(u32 *)((a1_2 + 0x30)) = -0x4036f025;
        *(u32 *)((a1_2 + 0x38)) = 0;
        break;
    case 3:
        v1 = 0x3fc90fdb;
        *(u32 *)((a1_2 + 0x30)) = 0x3fc90fdb;
        *(u32 *)((a1_2 + 0x38)) = 0;
        break;
    case 2:
        *(u32 *)((a1_2 + 0x30)) = 0;
        v1 = 0x3fc90fdb;
        *(u32 *)((a1_2 + 0x38)) = 0x3fc90fdb;
        break;
    case 1:
        *(u32 *)((a1_2 + 0x30)) = 0;
        *(u32 *)((a1_2 + 0x38)) = 0;
    case 0:
    default:
        break;
    }
    return;
}

static void __sghDice_AnimeRot(void *a0 /* r4 */) {
    u8 *s0;
    float f12;
    float f0;
    float f1;

    s0 = (u8 *)a0;
    f0 = Math_GetAngle360((float)*(float *)(((u8 *)a0 + 0x30)));
    *(f32 *)(s0 + 0x30) = f0;
    f0 = Math_GetAngle360((float)*(float *)(s0 + 0x34));
    *(f32 *)(s0 + 0x34) = f0;
    f1 = *(float *)(s0 + 0x38);
    f0 = -0.401349992f;
    f12 = (-0.401349992f + f1);
    f0 = Math_GetAngle360(f12);
    *(f32 *)(s0 + 0x38) = f0;
    return;
}

void __sghDice_AnimeCast(void *a0) {
    struct CastMdl *lpMdlMng = (struct CastMdl *)a0;
    struct CastGmInfo *pGmInfo = (struct CastGmInfo *)sghGetGameInfo();
    int aSteptbl[3] = {0x14, 0x18, 0x1c};
    float aSlanttbl[3] = {0.002f, 0.001f, 0.0002f};
    int aBoundSndtbl[3] = {0x138c, 0x1393, 0x1394};
    float inv_step;
    float dify;
    struct CastDice *pDice;
    u8 cnt;

    pDice = &((struct CastDice *)gDice)[lpMdlMng - ((struct CastMdl *)MdlMng + 211)];
    cnt = pDice->bound_cnt;
    if (pDice->frm_cnt == aSteptbl[cnt]) {
        sceVu0CopyVector(pDice, pDice->e_pos[cnt]);
        SND_Play2D(aBoundSndtbl[pDice->bound_cnt], 0x7f, 0);
        pDice->bound_cnt++;
        pDice->frm_cnt = 0;
        cnt = pDice->bound_cnt;
        if (cnt >= 3) {
            pDice->animeID = 0;
            pDice[1].animeID = 0;
            switch (pGmInfo->modeID) {
            case 5: pGmInfo->modeID = 6; break;
            case 10: pGmInfo->modeID = 11; break;
            }
            return;
        }
    }
    lpMdlMng->Ang[0] = Math_GetAngle360(0.01f + lpMdlMng->Ang[0]);
    lpMdlMng->Ang[1] = Math_GetAngle360(0.01f + lpMdlMng->Ang[1]);
    lpMdlMng->Ang[2] = Math_GetAngle360(lpMdlMng->Ang[2] + -0.40135f * (0.55f * (float)(3 - cnt)));
    inv_step = 1.0f / (float)aSteptbl[pDice->bound_cnt];
    dify = inv_step * (pDice->e_pos[pDice->bound_cnt][1] - pDice->s_pos[1]);
    { float t = inv_step * (pDice->e_pos[pDice->bound_cnt][0] - pDice->s_pos[0]); lpMdlMng->Pos[0] = pDice->s_pos[0] + t * (float)pDice->frm_cnt; }
    lpMdlMng->Pos[1] = pDice->s_pos[1] + dify * (float)pDice->frm_cnt;
    lpMdlMng->Pos[1] += (float)pDice->frm_cnt * aSlanttbl[pDice->bound_cnt] * (float)(pDice->frm_cnt - aSteptbl[pDice->bound_cnt]);
    pDice->frm_cnt++;
}
