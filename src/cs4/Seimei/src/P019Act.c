#include "common.h"

/* P019DramaEnd @ 0x1A65B0 .. 0x1A663C (0x8c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x41f00000 at 0x1a65dc
 *   fpu: float literal 0x41f00000 at 0x1a6610
 */

extern signed int SND_Play3D(signed int, signed short, signed short, void *, float);

/* P019DramaStart @ 0x1A6640 .. 0x1A66BC (0x7c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern void SND_FadeStop();

/* SetP019Dead @ 0x1A66C0 .. 0x1A676C (0xac bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1a66cc
 *   a0 forwarded to ChangeAnimParam
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);
extern signed int SFX_Delete();

/* P019ActDead @ 0x1A6770 .. 0x1A67B4 (0x44 bytes, frame 0x30) */

extern unsigned int CheckAnimEndFrame(void *);
extern void EneDeadProc(void *, void *);

/* P019ActAppear @ 0x1A67D0 .. 0x1A6900 (0x130 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42700000 at 0x1a67dc
 *   fpu: float literal 0x42e60000 at 0x1a6808
 *   fpu: float literal 0x3c9374bc at 0x1a6828
 *   fpu: float literal 0x3f800000 at 0x1a6830
 *   fpu: float literal 0x42e80000 at 0x1a6854
 *   fpu: float literal 0x41f00000 at 0x1a68d4
 */

extern unsigned int CheckAnimNumFrame(void *, float);
extern signed int SFX_Create_OnAng_Attach(unsigned short, float *, float *, void *, unsigned short,
    unsigned char, unsigned char);
extern u32 VW[];
extern u32 V0[];

/* P019ActInit @ 0x1A6900 .. 0x1A6968 (0x68 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

static void SetP019Dead(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void P019ActInit(void *a0 , void *a1 );
static void P019ActAppear(void *a0 , void *a1 );
static void P019ActStay(void);
static void P019ActDead(void *a0 , void *a1 );
static void SetP019Dead(void *a0 , void *a1 , unsigned short a2 );
static u32 P019DramaStart(u32 *a0 , u32 *a1 );
static void P019DramaEnd(void *a0 , void *a1 );


void P019ActInit(void *a0 /* r4 */, void *a1 /* r5 */) {
    s32 a2;
    u8 *v1;

    a2 = 1;
    v1 = (u8 *)P019ActAppear;
    *(u32 *)(((u8 *)a1 + 0x94)) = (u32)P019ActAppear;
    v1 = (u8 *)P019ActStay;
    *(u32 *)(((u8 *)a1 + 0x80)) = (u32)P019ActStay;
    v1 = (u8 *)P019ActDead;
    *(u32 *)(((u8 *)a1 + 0x90)) = (u32)P019ActDead;
    v1 = (u8 *)SetP019Dead;
    *(u32 *)(((u8 *)a1 + 0x110)) = (u32)SetP019Dead;
    v1 = (u8 *)P019DramaStart;
    *(u32 *)(((u8 *)a1 + 0x190)) = (u32)P019DramaStart;
    v1 = (u8 *)P019DramaEnd;
    *(u32 *)(((u8 *)a1 + 0x194)) = (u32)P019DramaEnd;
    *(u8 *)(((u8 *)a1 + 0x1da)) = a2;
    v1 = (u8 *)(s32)-1;
    *(s16 *)(((u8 *)a0 + 0x12e)) = (s32)v1;
    v1 = (u8 *)0xffff;
    *(u16 *)(((u8 *)a1 + 0x1fa)) = 0xffff;
    *(u8 *)(((u8 *)a1 + 0x24d)) = a2;
    return;
}

static void P019ActAppear(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    float f12;
    float *s0;
    float f1;
    float f0;
    u32 v1;
    u32 v0;

    v0 = 0x42700000;
    f0 = 60.0f;
    s2 = (u8 *)a0;
    s0 = (float *)*(s32 *)(((u8 *)a0 + 0x100));
    f1 = *(float *)s0;
    s1 = (u8 *)a1;
    if ((s32)(60.0f <= f1)) {
        v0 = 0x42e60000;
        f0 = 115.0f;
        if ((s32)(f1 <= 115.0f)) {
            v0 = 0x3c930000;
            v1 = 0x3c930000 | 0x74bc;
            f1 = 0.0179999992f;
            v0 = 0x3f800000;
            f1 = (*(float *)(s2 + 0x10c) + (float)f1);
            *(f32 *)(s2 + 0x10c) = f1;
            if (!(s32)(f1 <= 1.0f)) {
                *(f32 *)(s2 + 0x10c) = 1.0f;
            }
        }
    }
    f12 = 116.0f;
    v0 = CheckAnimNumFrame((void *)(u32)(s32)s0, 116.0f);
    if (v0 != 0 && (u32)*(u8 *)(s1 + 0x1da) == 0) {
        *(u8 *)(s2 + 0x130) = 0;
    }
    v0 = CheckAnimEndFrame((void *)(u32)(s32)s0);
    if (v0 != 0) {
        v0 = *(s32 *)(s1 + 0x100);
        ((void (*)(u32, u32, u32))(s32)v0)((u32)s2, (u32)s1, 0);
        a1 = (void *)VW;
        v0 = SFX_Create_OnAng_Attach(0x1b1, (float *)VW, (float *)V0, (void *)(u8 *)s2, 0, 0, 0);
        *(u32 *)(s1 + 0x200) = v0;
        f12 = 30.0f;
        v0 = SND_Play3D(0x88e, 0x3c, 0, (void *)(u8 *)(s2 + 0x20), 30.0f);
        *(u32 *)(s1 + 0x220) = v0;
    }
    return;
}

/* P019ActStay @ 0x1A67C0 .. 0x1A67C8 (0x8 bytes) */

static void P019ActStay(void) {
    return;
}

static void P019ActDead(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 *s1;
    u32 s0;
    u32 v0;

    s1 = (u32 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x100));
    s0 = (u32)a1;
    v0 = CheckAnimEndFrame(a0);
    a0 = (void *)s1;
    if (v0 != 0) {
        a1 = (void *)s0;
        EneDeadProc(a0, a1);
    }
    return;
}

static void SetP019Dead(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    u8 *s0;
    void *a1_2; // a1
    u32 a0_scalar; // a0

    s0 = (u8 *)a1;
    *(u8 *)(((u8 *)a1 + 0x180)) = 4;
    ChangeAnimParam(a0, (u16)a2, 0.0f);
    a0_scalar = *(s32 *)(s0 + 0x200);
    a1_2 = (void *)(s32)1;
    if (a0_scalar != (u32)-1) {
        SFX_Delete(a0_scalar, a1_2);
    }
    a0_scalar = *(s32 *)(s0 + 0x204);
    a1_2 = (void *)(s32)1;
    if (a0_scalar != (u32)-1) {
        SFX_Delete(a0_scalar, a1_2);
    }
    a0_scalar = *(s32 *)(s0 + 0x220);
    if (a0_scalar != (u32)0x51) {
        SND_FadeStop(a0_scalar);
        *(u32 *)(s0 + 0x220) = 0x51;
    }
    a0_scalar = *(s32 *)(s0 + 0x224);
    if (a0_scalar != (u32)0x51) {
        SND_FadeStop(a0_scalar);
        *(u32 *)(s0 + 0x224) = 0x51;
    }
    *(u16 *)(s0 + 0x1dc) = 0;
    return;
}

static u32 P019DramaStart(u32 *a0 /* r4 */, u32 *a1 /* r5 */) {
    u32 v1;
    u32 s1;
    u32 s0;

    v1 = 0x51;
    s1 = (u32)a0;
    a0 = (u32 *)*(u32 *)(((u8 *)a1 + 0x220));
    s0 = (u32)a1;
    if ((u32)(a0) != v1) {
        SND_FadeStop(a0, a1);
        a0 = (u32 *)0x51;
        v1 = 1;
        *(u32 *)((s0 + 0x220)) = 0x51;
        *(u32 *)((s1 + 0x154)) = 1;
    }
    a0 = (u32 *)*(u32 *)((s0 + 0x224));
    v1 = 0x51;
    if ((u32)(a0) != v1) {
        SND_FadeStop(a0);
        a0 = (u32 *)0x51;
        v1 = 1;
        *(u32 *)((s0 + 0x224)) = 0x51;
        *(u32 *)((s1 + 0x158)) = 1;
    }
    return;
}

static void P019DramaEnd(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 *s1;
    u32 *s0;
    float f12;
    u32 v0;

    s1 = (u32 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x154));
    s0 = (u32 *)a1;
    if ((u32)(s32)a0 == (u32)1) {
        f12 = 30.0f;
        v0 = SND_Play3D(0x88e, 0x3c, 0, (void *)(u32 *)((u8 *)s1 + 0x20), 30.0f);
        *(u32 *)(((u8 *)s0 + 0x220)) = v0;
    }
    a0 = (void *)*(s32 *)(((u8 *)s1 + 0x158));
    if ((u32)(s32)a0 == (u32)1) {
        f12 = 30.0f;
        v0 = SND_Play3D(0x88e, 0x64, 0x12c, (void *)(u32 *)((u8 *)s1 + 0x20), 30.0f);
        *(u32 *)(((u8 *)s0 + 0x224)) = v0;
    }
    return;
}
