#include "common.h"

/* P018DramaEnd @ 0x1A5A60 .. 0x1A5AEC (0x8c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x41f00000 at 0x1a5a8c
 *   fpu: float literal 0x41f00000 at 0x1a5ac0
 */

extern signed int SND_Play3D(signed int, signed short, signed short, void *, float);

/* P018DramaStart @ 0x1A5AF0 .. 0x1A5B6C (0x7c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern void SND_FadeStop(signed int);

extern int SFX_Delete(int,int);
extern int SFX_Create_OnAng_Attach(u16,float *,float *,void *,u16,u8,u8);
extern u32 VW[],V0[];


/* P018ActDead @ 0x1A5C60 .. 0x1A5C9C (0x3c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   a0 forwarded to EneDeadProc
 */

extern void EneDeadProc(void *, void *);

/* P018ActAppear @ 0x1A5CB0 .. 0x1A5DB4 (0x104 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x41f00000 at 0x1a5d0c
 *   fpu: float literal 0x41f00000 at 0x1a5d78
 *   cfg: kept goto: 0x1a5ce0 -> .L001A5D90
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int SFX_Create_OnAng_Attach(unsigned short, float *, float *, void *, unsigned short,
    unsigned char, unsigned char);
extern signed int SND_Play3D(signed int, signed short, signed short, void *, float);
extern u32 VW[];
extern u32 V0[];

/* P018ActInit @ 0x1A5DC0 .. 0x1A5E20 (0x60 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32; 1 parameters vs 2 inferred
 */

static void SetP018Dead(void *object,void *enemy,u32 animation);
static void P018DramaEnd(void *a0 /* r4 */, void *a1 /* r5 */);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void P018ActInit(void *a0 , u8 *a1);
static void P018ActAppear(void *a0 , void *a1 );
static void P018ActStay(void);
static void P018ActDead(void *a0 , void *a1 );
static void SetP018Dead(void *object,void *enemy,u32 animation);
static u32 CalcP018Damage(u32 *a0 );
static u32 P018DramaStart(u32 *a0 , u32 *a1 );
static void P018DramaEnd(void *a0 , void *a1 );


void P018ActInit(void *a0 /* r4 */, u8 *a1) {
    u8 *v1;

    v1 = (u8 *)P018ActAppear;
    *(u32 *)(((u8 *)a1 + 0x94)) = (u32)P018ActAppear;
    v1 = (u8 *)P018ActStay;
    *(u32 *)(((u8 *)a1 + 0x80)) = (u32)P018ActStay;
    v1 = (u8 *)P018ActDead;
    *(u32 *)(((u8 *)a1 + 0x90)) = (u32)P018ActDead;
    v1 = (u8 *)CalcP018Damage;
    *(u32 *)(((u8 *)a1 + 0x188)) = (u32)CalcP018Damage;
    v1 = (u8 *)SetP018Dead;
    *(u32 *)(((u8 *)a1 + 0x110)) = (u32)SetP018Dead;
    v1 = (u8 *)P018DramaStart;
    *(u32 *)(((u8 *)a1 + 0x190)) = (u32)P018DramaStart;
    v1 = (u8 *)P018DramaEnd;
    *(u32 *)(((u8 *)a1 + 0x194)) = (u32)P018DramaEnd;
    *(u8 *)(((u8 *)a1 + 0x24d)) = (s32)(u8 *)(s32)1;
    return;
}

static void P018ActAppear(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 v1;
    u8 *s1;
    u8 *s0;
    u32 v0;
    u32 a2;
    u8 *a3;
    float f12;

    v1 = 0x3c;
    s1 = (u8 *)a0;
    a0 = (void *)*(u16 *)(((u8 *)a1 + 0x1dc));
    s0 = (u8 *)a1;
    if ((u32)a0 == v1) {
        v0 = 0x3f800000;
        a0 = (void *)(s32)0x1b7;
        *(u32 *)(((u8 *)s1 + 0x10c)) = 0x3f800000;
        a1 = (void *)VW;
        a2 = (u32)V0;
        a3 = s1;
        SFX_Create_OnAng_Attach((unsigned short)a0, (float *)VW, (float *)V0, (void *)a3, 0, 0, 0);
        a3 = (u8 *)(s32)((u8 *)s1 + 0x20);
        f12 = 30.0f;
        a0 = (void *)(s32)0x87b;
        a1 = (void *)(s32)0x3c;
        v0 = SND_Play3D((signed int)a0, (signed short)a1, 0, (void *)a3, 30.0f);
        *(u32 *)(((u8 *)s0 + 0x220)) = v0;
        goto _L001A5D90;
    } else {
        v1 = 0x78;
        if ((u32)(s32)a0 == v1) {
            *(u8 *)(((u8 *)s1 + 0x130)) = 0;
            *(u8 *)(((u8 *)s0 + 0x180)) = 0;
            a0 = (void *)(s32)0x1ac;
            a1 = (void *)VW;
            a2 = (u32)V0;
            a3 = s1;
            *(u16 *)(((u8 *)s0 + 0x1dc)) = 0;
            v0 = SFX_Create_OnAng_Attach((unsigned short)a0, (float *)VW, (float *)V0, (void *)a3,
                0, 0, 0);
            *(u32 *)(((u8 *)s0 + 0x200)) = v0;
            a3 = (u8 *)(s32)((u8 *)s1 + 0x20);
            a0 = (void *)(s32)0x87a;
            f12 = 30.0f;
            a1 = (void *)(s32)0x64;
            v0 = SND_Play3D((signed int)a0, (signed short)a1, 0, (void *)a3, 30.0f);
            *(u32 *)(((u8 *)s0 + 0x224)) = v0;
        } else {
            _L001A5D90:;
            v1 = *(u16 *)(((u8 *)s0 + 0x1dc));
            v1 = v1 + 1;
            *(u16 *)(((u8 *)s0 + 0x1dc)) = v1;
        }
    }
    return;
}

/* P018ActStay @ 0x1A5CA0 .. 0x1A5CA8 (0x8 bytes) */

static void P018ActStay(void) {
    return;
}

static void P018ActDead(void *a0 /* r4 */, void *a1 /* r5 */) {
    s32 v1;
    u32 a2;

    v1 = 0x3c;
    a2 = *(u16 *)(((u8 *)a1 + 0x1dc));
    a2 = a2 + 1;
    *(u16 *)(((u8 *)a1 + 0x1dc)) = a2;
    a2 = (u16)a2;
    if (a2 == (u32)v1) {
        EneDeadProc(a0, a1);
    }
    return;
}

static void SetP018Dead(void *object,void *enemy,u32 animation) {
    u8 *info=*(u8 **)(*(u32 *)((u8 *)object+12)+76);
    int sound;
    *(u8 *)((u8 *)enemy+0x180)=4;
    SFX_Delete(*(int *)((u8 *)enemy+0x200),1);
    sound=*(int *)((u8 *)enemy+0x220);
    if (sound!=81) { SND_FadeStop(sound); *(int *)((s32)enemy+0x220)=81; }
    sound=*(int *)((u8 *)enemy+0x224);
    if (sound!=81) { SND_FadeStop(sound); *(int *)((s32)enemy+0x224)=81; }
    if ((u16)animation!=7) SFX_Create_OnAng_Attach(438,(float *)VW,(float *)V0,object,0,*info,((u8 *)object)[0x12a]);
    *(u16 *)((u8 *)enemy+0x1dc)=0;
    *(u32 *)((u8 *)object+0x120)=0;
}

/* CalcP018Damage @ 0x1A5B70 .. 0x1A5B7C (0xc bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1a5b78 computes the return value
 */

static u32 CalcP018Damage(u32 *a0 /* r4 */) {
    u32 *v0;

    v0 = (u32 *)*(u32 *)(((u8 *)a0 + 0x10));
    return *(u32 *)(((u8 *)v0 + 0x120));
}

static u32 P018DramaStart(u32 *a0 /* r4 */, u32 *a1 /* r5 */) {
    u32 a0_scalar; // a0

    a0_scalar = (s32)a1[0x88];
    if (a0_scalar != (u32)0x51) {
        SND_FadeStop(a0_scalar);
        a1[0x88] = 0x51;
        *(u32 *)(((u8 *)a0 + 0x154)) = 1;
    }
    a0_scalar = (s32)a1[0x89];
    if (a0_scalar != (u32)0x51) {
        SND_FadeStop(a0_scalar);
        a1[0x89] = 0x51;
        *(u32 *)(((u8 *)a0 + 0x158)) = 1;
    }
    return;
}

static void P018DramaEnd(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u8 *s0;
    float f12;
    u32 v0;

    s1 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x154));
    s0 = (u8 *)a1;
    if ((u32)(s32)a0 == (u32)1) {
        f12 = 30.0f;
        v0 = SND_Play3D(0x87b, 0x3c, 0, (void *)(u32 *)(s1 + 0x20), 30.0f);
        *(u32 *)(s0 + 0x220) = v0;
    }
    a0 = (void *)*(s32 *)(s1 + 0x158);
    if ((u32)(s32)a0 == (u32)1) {
        f12 = 30.0f;
        v0 = SND_Play3D(0x87a, 0x3c, 0, (void *)(u32 *)(s1 + 0x20), 30.0f);
        *(u32 *)(s0 + 0x224) = v0;
    }
    return;
}
