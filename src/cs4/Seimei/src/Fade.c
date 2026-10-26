#include "common.h"



static u32 FadeDramaId = 0xffffffff;
static u32 FadeLoadScene = 0xffffffff;
static u32 FadeLoadCam = 0xffffffff;
static u32 FadeLoadMovie = 0xffffffff;
u8 FadeMng[0x30];

#define FM_S32(o) (*(s32 *)(FadeMng + (o)))
#define FM_F32(o) (*(float *)(FadeMng + (o)))
#define FM_PTR(o) (*(void **)(FadeMng + (o)))
extern void SetSprite(void *, signed int, signed int, signed int, signed int, signed int *,
    unsigned short, unsigned char);
extern void MakeAndKickSpritePacket(void *);
extern u32 GetDramaReadFlag();
extern void ReadDramaData(signed int, signed int, signed int);
extern void SetSceneLoad(unsigned short, unsigned short);
extern void SetLoadMovieId(unsigned char);
extern u8 GameSt[];
extern u32 L886[];
extern u32 L919[];
extern void *memset();
void SetFadeMovieLoad(s32 a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */);
void SetFadeSceneLoad(s32 a0 /* r4 */, s32 a1 /* r5 */);
u8 CheckFadeType(void);
signed int CheckNowFade(signed int a0 /* r4 */);
u32 GetFadeDrama(void);
void SetFadeDrama(s32 a0 /* r4 */);
void UpdateFadeMng(void);
void SetFadeMng(unsigned char Type, signed int *Col, signed int Time, void *a3, void *t0, signed int t1, signed int t2);
unsigned int CheckFadeEnd(void);
void InitFadeControl(void);

/* InitFadeControl @ 0x1810C0 .. 0x1810F8 (0x38 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */


void InitFadeControl(void) {
    s32 v1;

    memset((u32)FadeMng, 0, 0x30);
    v1 = -1;
    FadeDramaId = v1;
    FadeLoadScene = v1;
    FadeLoadCam = v1;
    return;
}






/* CheckFadeEnd @ 0x1810A0 .. 0x1810B4 (0x14 bytes) */
/*
 * dcomp notes:
 *   return: sltiu at 0x1810b0 computes the return value
 */





unsigned int CheckFadeEnd(void) {
    u32 v0;

    v0 = *(s32 *)(FadeMng + 0x14);
    return v0 == (u32)0;
}






/* SetFadeMng @ 0x180BE0 .. 0x181094 (0x4b4 bytes) */
/*
 * dcomp notes:
 *   literal: @919 -> 0x253fc0
 *   indirect: jr v1 at 0x180c48 -> <v1>
 *   fpu: mtc1 reinterprets a2 at 0x180c54
 *   fpu: float literal 0x43000000 at 0x180c60
 *   fpu: mtc1 reinterprets a2 at 0x180cbc
 *   fpu: float literal 0x43000000 at 0x180cc8
 *   fpu: mtc1 reinterprets v1 at 0x180d24
 *   fpu: float literal 0x43000000 at 0x180d3c
 *   fpu: mtc1 reinterprets a2 at 0x180d8c
 *   fpu: mtc1 reinterprets t1 at 0x180d94
 *   fpu: float literal 0x40400000 at 0x180db0
 *   fpu: float literal 0x43000000 at 0x180db4
 *   fpu: mtc1 reinterprets a2 at 0x180e18
 *   fpu: float literal 0x43000000 at 0x180e1c
 *   fpu: mtc1 reinterprets a2 at 0x180e44
 *   fpu: float literal 0x43000000 at 0x180e50
 *   fpu: mtc1 reinterprets v1 at 0x180ebc
 *   fpu: float literal 0x43000000 at 0x180ec0
 *   fpu: mtc1 reinterprets v1 at 0x180ee4
 *   fpu: float literal 0x43000000 at 0x180efc
 *   fpu: mtc1 reinterprets t1 at 0x180f4c
 *   fpu: float literal 0x43000000 at 0x180f78
 *   fpu: mtc1 reinterprets t1 at 0x180ff0
 *   fpu: float literal 0x43000000 at 0x180ff4
 *   fpu: mtc1 reinterprets t1 at 0x18101c
 *   fpu: float literal 0x43000000 at 0x181028
 */


void SetFadeMng(unsigned char Type, signed int *Col, signed int Time, void *a3, void *t0, signed int t1, signed int t2) {
    s32 bBusy = 0;
    float fAlpha;

    if (FM_S32(0x14) != 0) {
        bBusy = 1;
    } else if (FadeMng[0x10] == 5) {
        bBusy = 1;
    }
    FadeMng[0x10] = Type;
    FM_S32(0x14) = Time;
    switch (FadeMng[0x10]) {
    case 0:
    case 11:
        FM_F32(0x24) = 128.0f;
        FM_F32(0x20) = 128.0f / (float)Time;
        FM_S32(0x0) = Col[0];
        FM_S32(0x4) = Col[1];
        FM_S32(0x8) = Col[2];
        FM_S32(0xc) = (s32)FM_F32(0x24);
        break;
    case 1:
    case 3:
    case 7:
        FM_F32(0x24) = 0.0f;
        FM_F32(0x20) = 128.0f / (float)Time;
        FM_S32(0x0) = Col[0];
        FM_S32(0x4) = Col[1];
        FM_S32(0x8) = Col[2];
        FM_S32(0xc) = (s32)FM_F32(0x24);
        break;
    case 10:
        FM_F32(0x24) = 0.0f;
        FM_F32(0x20) = 128.0f / (float)(Time - 3);
        FM_S32(0x0) = Col[0];
        FM_S32(0x4) = Col[1];
        FM_S32(0x8) = Col[2];
        FM_S32(0xc) = (s32)FM_F32(0x24);
        break;
    case 6:
        FM_F32(0x24) = 0.0f;
        FM_F32(0x20) = 128.0f / (((float)Time - (float)t1) - 3.0f);
        FM_S32(0x0) = Col[0];
        FM_S32(0x4) = Col[1];
        FM_S32(0x8) = Col[2];
        FM_S32(0xc) = (s32)FM_F32(0x24);
        break;
    case 5:
        if (bBusy != 0) {
            FM_F32(0x20) = (128.0f - FM_F32(0x24)) / (float)Time;
            break;
        } else {
            FM_F32(0x24) = 0.0f;
            FM_F32(0x20) = 128.0f / (float)Time;
            FM_S32(0x0) = Col[0];
            FM_S32(0x4) = Col[1];
            FM_S32(0x8) = Col[2];
            FM_S32(0xc) = (s32)FM_F32(0x24);
            break;
        }
    case 9:
        if (bBusy != 0) {
            FM_F32(0x20) = (128.0f - FM_F32(0x24)) / (float)(Time - 3);
            break;
        } else {
            FM_F32(0x24) = 0.0f;
            FM_F32(0x20) = 128.0f / (float)(Time - 3);
            FM_S32(0x0) = Col[0];
            FM_S32(0x4) = Col[1];
            FM_S32(0x8) = Col[2];
            FM_S32(0xc) = (s32)FM_F32(0x24);
            break;
        }
    case 2:
    case 8:
        FM_S32(0x1c) = Time - t2;
        FM_F32(0x24) = 0.0f;
        FM_S32(0x18) = Time - t1;
        FM_F32(0x20) = 128.0f / (float)t1;
        FM_S32(0x0) = Col[0];
        FM_S32(0x4) = Col[1];
        FM_S32(0x8) = Col[2];
        FM_S32(0xc) = (s32)FM_F32(0x24);
        break;
    case 4:
        FM_S32(0x18) = Time - t1;
        FM_S32(0x1c) = Time - t2;
        if (bBusy != 0) {
            FM_F32(0x20) = (128.0f - FM_F32(0x24)) / (float)t1;
            break;
        } else {
            FM_F32(0x24) = 0.0f;
            FM_S32(0x0) = Col[0];
            fAlpha = FM_F32(0x24);
            FM_S32(0x4) = Col[1];
            FM_S32(0x8) = Col[2];
            FM_F32(0x20) = 128.0f / (float)t1;
            FM_S32(0xc) = (s32)fAlpha;
        }
    default:
        break;
    }
    FM_PTR(0x28) = a3;
    FM_PTR(0x2c) = t0;
}


/* UpdateFadeMng @ 0x1807B0 .. 0x180BDC (0x42c bytes, frame 0x100) */
/*
 * dcomp notes:
 *   literal: @886 -> 0x253f90
 *   delay: addiu at 0x1807d4 writes a register its branch at 0x1807d0 reads
 *   stack: address of the slot at 0x10 escapes at 0x180830
 *   stack: address of the slot at 0x10 escapes at 0x180838
 *   stack: address of the slot at 0x10 escapes at 0x180880
 *   stack: address of the slot at 0x10 escapes at 0x180888
 *   indirect: jr v1 at 0x1808d8 -> <v1>
 *   fpu: float literal 0x00000000 at 0x1808e8
 *   fpu: float literal 0x43000000 at 0x180924
 *   fpu: float literal 0x43000000 at 0x18095c
 *   fpu: float literal 0x43000000 at 0x1809e4
 *   fpu: float literal 0x43000000 at 0x180a5c
 *   delay: lui at 0x180ae8 writes a register its branch at 0x180ae4 reads
 *   fpu: float literal 0x00000000 at 0x180af0
 *   fpu: float literal 0x43000000 at 0x180b3c
 *   fpu: mtc1 reinterprets a0 at 0x180b5c
 */


void UpdateFadeMng(void) {
    u8 *t1;
    s32 t0;
    float f2;
    s32 a3;
    s32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    float f1;
    float f0;
    float fadeSum;
    float fadeLimit;
    float fadeDuration;
    float fadeRate;
    u8 stackFrame_10[240] __attribute__((aligned(16)));

    v1 = *(s32 *)(FadeMng + 0x14);
    if (v1 == 0) {
        v1 = 9;
        a0 = FadeMng[0x10];
        switch (a0) {
        case 5:
        case 3:
        case 9:
            a1 = -0x100;
            a2 = -0xe0;
            a3 = 0x200;
            t0 = 0x1c0;
            t1 = FadeMng;
            v0 = (s32)*(float *)(FadeMng + 0x24);
            *(u32 *)(FadeMng + 0xc) = v0;
            SetSprite((void *)((u8 *)&stackFrame_10[0]), a1, a2, a3, t0, (signed int *)FadeMng, 0,
                0);
            MakeAndKickSpritePacket((void *)((u8 *)&stackFrame_10[0]));
        }
        return;
    }
    a1 = -0x100;
    a2 = -0xe0;
    a3 = 0x200;
    t0 = 0x1c0;
    t1 = FadeMng;
    v0 = (s32)*(float *)(FadeMng + 0x24);
    *(u32 *)(FadeMng + 0xc) = v0;
    SetSprite((void *)((u8 *)&stackFrame_10[0]), a1, a2, a3, t0, (signed int *)FadeMng, 0, 0);
    MakeAndKickSpritePacket((void *)((u8 *)&stackFrame_10[0]));
    v1 = 1;
    a0 = GameSt[0xf];
    if (a0 != v1) {
        (*(s32 *)(FadeMng + 0x14))--;
        v1 = FadeMng[0x10];
        switch (v1) {
        case 0:
        case 11:
            f2 = *(float *)(FadeMng + 0x24);
            f0 = 0.0f;
            f1 = (f2 - *(float *)(FadeMng + 0x20));
            *(f32 *)(FadeMng + 0x24) = f1;
            if (f1 >= 0.0f) {
                break;
            }
            *(f32 *)(FadeMng + 0x24) = f0;
            break;
        case 1:
        case 5:
        case 9:
        case 10:
            f2 = *(float *)(FadeMng + 0x24);
            v1 = 0x43000000;
            f0 = 128.0f;
            f1 = (f2 + *(float *)(FadeMng + 0x20));
            *(f32 *)(FadeMng + 0x24) = f1;
            if (f1 <= 128.0f) {
                break;
            }
            *(f32 *)(FadeMng + 0x24) = f0;
            break;
        case 3:
            f2 = *(float *)(FadeMng + 0x24);
            v1 = 0x43000000;
            f0 = 128.0f;
            f1 = (f2 + *(float *)(FadeMng + 0x20));
            *(f32 *)(FadeMng + 0x24) = f1;
            if (!(f1 <= 128.0f)) {
                *(f32 *)(FadeMng + 0x24) = f0;
            }
            v1 = *(s32 *)(FadeMng + 0x14);
            if (v1 != 0) {
                break;
            }
            a0 = FadeDramaId;
            v1 = -1;
            if (a0 == v1) {
                break;
            }
            v0 = GetDramaReadFlag();
            if (v0 == 0) {
                a1 = FadeDramaId;
                a0 = GameSt[9];
                a2 = 1;
                ReadDramaData(a0, a1, a2);
            }
            v1 = -1;
            FadeDramaId = v1;
            break;
        case 6:
            f2 = *(float *)(FadeMng + 0x24);
            v1 = 0x43000000;
            f0 = 128.0f;
            f1 = (f2 + *(float *)(FadeMng + 0x20));
            *(f32 *)(FadeMng + 0x24) = f1;
            if (!(f1 <= 128.0f)) {
                *(f32 *)(FadeMng + 0x24) = f0;
            }
            v1 = *(s32 *)(FadeMng + 0x14);
            if (v1 != 0) {
                break;
            }
            a0 = FadeLoadScene;
            v1 = -1;
            if (a0 == v1) {
                break;
            }
            a1 = *(u16 *)((u8 *)&FadeLoadCam);
            SetSceneLoad(a0, a1);
            v1 = -1;
            FadeLoadScene = v1;
            FadeLoadCam = v1;
            break;
        case 7:
            f2 = *(float *)(FadeMng + 0x24);
            v1 = 0x43000000;
            f0 = 128.0f;
            f1 = (f2 + *(float *)(FadeMng + 0x20));
            *(f32 *)(FadeMng + 0x24) = f1;
            if (!(f1 <= 128.0f)) {
                *(f32 *)(FadeMng + 0x24) = f0;
            }
            v1 = *(s32 *)(FadeMng + 0x14);
            if (v1 != 0) {
                break;
            }
            a0 = FadeLoadMovie;
            v1 = -1;
            if (a0 == v1) {
                break;
            }
            a1 = *(u16 *)((u8 *)&FadeLoadCam);
            a0 = *(u16 *)((u8 *)&FadeLoadScene);
            SetSceneLoad(a0, a1);
            a0 = *(u8 *)((u8 *)&FadeLoadMovie);
            SetLoadMovieId(a0);
            v1 = -1;
            FadeLoadScene = v1;
            FadeLoadCam = v1;
            FadeLoadMovie = v1;
            break;
        case 2:
        case 4:
        case 8:
            if ((s32)*(s32 *)(FadeMng + 0x14) < (s32)*(s32 *)(FadeMng + 0x1c)) {
                f2 = *(float *)(FadeMng + 0x24);
                f0 = 0.0f;
                f1 = (f2 - *(float *)(FadeMng + 0x20));
                *(f32 *)(FadeMng + 0x24) = f1;
                if (f1 >= 0.0f) {
                    break;
                }
                *(f32 *)(FadeMng + 0x24) = f0;
                break;
            } else {
                if (!((s32)*(s32 *)(FadeMng + 0x14) < (s32)*(s32 *)(FadeMng + 0x18))) {
                    v1 = 0x43000000;
                    f2 = *(float *)(FadeMng + 0x24);
                    fadeLimit = 128.0f;
                    fadeSum = (f2 + *(float *)(FadeMng + 0x20));
                    *(f32 *)(FadeMng + 0x24) = fadeSum;
                    if (!(fadeSum <= fadeLimit)) {
                        fadeDuration = (float)*(s32 *)(FadeMng + 0x1c);
                        *(f32 *)(FadeMng + 0x24) = fadeLimit;
                        fadeRate = fadeLimit / fadeDuration;
                        *(f32 *)(FadeMng + 0x20) = fadeRate;
                    }
                    if (*(s32 *)(FadeMng + 0x14) == *(s32 *)(FadeMng + 0x18) + 1) {
                        v1 = *(s32 *)(FadeMng + 0x28);
                        if (v1 != 0) {
                            ((void (*)(s32))(s32)v1)(*(s32 *)(FadeMng + 0x14));
                        }
                    }
                }
                break;
            }
        default:
            break;
        }
    }
    v1 = *(s32 *)(FadeMng + 0x14);
    if (v1 == 0) {
        v1 = *(s32 *)(FadeMng + 0x2c);
        if (v1 != 0) {
            ((void (*)(void))(s32)v1)();
        }
    }
    return;
}






/* SetFadeDrama @ 0x1807A0 .. 0x1807A8 (0x8 bytes) */


void SetFadeDrama(s32 a0 /* r4 */) {
    FadeDramaId = a0;
    return;
}





/* GetFadeDrama @ 0x180790 .. 0x180798 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x180794 computes the return value
 */


u32 GetFadeDrama(void) {
    return FadeDramaId;
}













/* CheckNowFade @ 0x180750 .. 0x180788 (0x38 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x180768 writes a register its branch at 0x180764 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




signed int CheckNowFade(signed int a0 /* r4 */) {
    u32 v0;
    s32 branchcond_180764;

    v0 = *(u8 *)((u8 *)&FadeMng + 0x10);
    if (v0 == (u32)(s32)a0) {
        v0 = *(s32 *)((u8 *)&FadeMng + 0x14);
        branchcond_180764 = v0 == 0;
        v0 = 1;
        if (!branchcond_180764) {
            return v0;
        }
    }
    v0 = 0;
    return v0;
}







/* CheckFadeType @ 0x180740 .. 0x18074C (0xc bytes) */
/*
 * dcomp notes:
 *   return: lbu at 0x180748 computes the return value
 *   spans: lui at at 0x180740 read at 0x180748 before its %lo
 */


u8 CheckFadeType(void) {
    return *(u8 *)((u8 *)&FadeMng + 0x10);
}


/* SetFadeSceneLoad @ 0x180730 .. 0x18073C (0xc bytes) */


void SetFadeSceneLoad(s32 a0 /* r4 */, s32 a1 /* r5 */) {
    FadeLoadScene = a0;
    FadeLoadCam = a1;
    return;
}






/* SetFadeMovieLoad @ 0x180720 .. 0x180730 (0x10 bytes) */

void SetFadeMovieLoad(s32 a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */) {
    FadeLoadScene = a0;
    FadeLoadCam = a1;
    FadeLoadMovie = a2;
    return;
}

