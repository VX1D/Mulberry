#include "common.h"

extern float Math_VectorToAngle(float, float);
extern unsigned int CheckAnimParam(void *, signed int);


/* CalcP025Damage @ 0x200350 .. 0x200500 (0x1b0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x20038c
 *   fpu: mtc1 reinterprets v1 at 0x2003a4
 *   fpu: float literal 0x42c80000 at 0x2003f4
 *   fpu: mtc1 reinterprets v0 at 0x200400
 *   fpu: float literal 0x42c80000 at 0x200434
 *   fpu: mtc1 reinterprets v0 at 0x200440
 *   fpu: float literal 0x3f800000 at 0x20045c
 *   fpu: mtc1 reinterprets v1 at 0x200488
 *   fpu: float literal 0x41200000 at 0x200490
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern int rand();
extern signed int SFX_Create_OnAng_Attach(unsigned short, float *, float *, void *, unsigned short,
    unsigned char, unsigned char);
extern u32 VW[];
extern u32 V0[];


/* SetP025Dead @ 0x200500 .. 0x200528 (0x28 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x200518
 *   tail: j ChangeAnimParam at 0x200520 leaves the function
 *   a0 forwarded to ChangeAnimParam
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);

/* SetP025Walk @ 0x200530 .. 0x2005B4 (0x84 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x20058c
 */

extern unsigned int CheckAnimParam(void *, signed int);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * P025ActInit(s32 a0 , u32 *a1 );
static void SetP025Stay(void *a0 , void *a1 , unsigned short a2 );
static void SetP025Walk(void *a0 , void *a1 , unsigned short a2 );
static void SetP025Dead(void *a0 , void *a1 , unsigned short a2 );
static signed int CalcP025Damage(void *a0 );
static signed int GetP025DamageAnim(u8 *obj);


/* P025ActInit @ 0x200650 .. 0x200690 (0x40 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */







u8 * P025ActInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)GetP025DamageAnim;
    *(u32 *)(((u8 *)a1 + 0x184)) = (u32)GetP025DamageAnim;
    v1 = (u8 *)CalcP025Damage;
    *(u32 *)(((u8 *)a1 + 0x188)) = (u32)CalcP025Damage;
    v1 = (u8 *)SetP025Stay;
    *(u32 *)(((u8 *)a1 + 0x100)) = (u32)SetP025Stay;
    v1 = (u8 *)SetP025Walk;
    *(u32 *)(((u8 *)a1 + 0x104)) = (u32)SetP025Walk;
    v1 = (u8 *)SetP025Dead;
    *(u32 *)(((u8 *)a1 + 0x110)) = (u32)SetP025Dead;
    return;
}

/* SetP025Stay @ 0x2005C0 .. 0x200644 (0x84 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x20061c
 */




static void SetP025Stay(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    u32 s2;
    u8 *s1;
    u32 v0;
    u16 s0;

    s2 = (u32)a0;
    s1 = (u8 *)a1;
    *(u8 *)(((u8 *)a1 + 0x180)) = 0;
    v0 = *(u8 *)(((u8 *)a1 + 0x1f0));
    s0 = a2;
    if (v0 != 0) {
        s0 = 0x5b;
    } else {
        v0 = 0xe;
        a1 = (void *)s0;
        if ((u32)s0 == v0) {
            v0 = CheckAnimParam(a0, (signed int)a1);
            if (v0 == 0) {
                s0 = 0;
            }
        }
    }
    ChangeAnimParam((void *)s2, s0, 0.0f);
    *(u16 *)(((u8 *)s1 + 0x1dc)) = 0;
    return;
}


static void SetP025Walk(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    u32 s2;
    u8 *s1;
    u32 v0;
    u16 s0;

    s2 = (u32)a0;
    s1 = (u8 *)a1;
    *(u8 *)(((u8 *)a1 + 0x180)) = 1;
    v0 = *(u8 *)(((u8 *)a1 + 0x1f0));
    s0 = a2;
    if (v0 != 0) {
        s0 = 0x5b;
    } else {
        v0 = 5;
        a1 = (void *)s0;
        if ((u32)s0 == v0) {
            v0 = CheckAnimParam(a0, (signed int)a1);
            if (v0 == 0) {
                s0 = 0xa;
            }
        }
    }
    ChangeAnimParam((void *)s2, s0, 0.0f);
    *(u16 *)(((u8 *)s1 + 0x1de)) = 0;
    return;
}

static void SetP025Dead(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    u8 v0;
    u16 v1;

    v0 = *(u8 *)(((u8 *)a1 + 0x1f0));
    v1 = a2;
    if ((u32)v0 != 0) {
        v1 = 0x5c;
    }
    *(u8 *)(((u8 *)a1 + 0x180)) = 4;
    ChangeAnimParam(a0, v1, 0.0f);
    return;
}

static signed int CalcP025Damage(void *a0 /* r4 */) {
    float f20;
    u8 *s1;
    s32 xt1;
    u32 power;
    float f1;
    u8 *s0;

    s1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x10));
    s0 = (u8 *)*(s32 *)(s1 + 0x148);
    power = *(s32 *)((u8 *)(*(s32 *)(((u8 *)0x14 + (u32)a0)) + *(u8 *)(((u8 *)0x19 + (s32)a0)) * 0x28) + 0xa0);
    f20 = (float)power * *(float *)(((u8 *)a0 + 0x20));
    if ((rand() % 10) <= 4) {
        f1 = (float)(rand() % 30) / 100.0f;
    } else {
        f1 = -((float)(rand() % 30) / 100.0f);
    }
    xt1 = *(s32 *)(0x120 + (s1));
    f20 = f20 * (1.0f + f1);
    if (xt1 - (s32)f20 <= 10) {
        f20 = (float)xt1 - 10.0f;
        *(u8 *)(s0 + 0x1f0) = (1);
        *(s16 *)(s1 + 0x12e) = -1;
        *(u16 *)(0x1fa + s0) = 0xffff;
        *(u8 *)((s1 + 0x130)) = (1);
        SFX_Create_OnAng_Attach(0x30, (float *)VW, (float *)V0, (void *)((s32)s1), 0, 0, 0);
    }
    return f20;
}

static signed int GetP025DamageAnim(u8 *obj) {
    u8 *info;
    u32 anim;
    float d, ang, ad, t, w, c;
    u8 *tgt;
    info = (u8 *)*(u32 *)(obj + 0x14) + obj[0x19] * 0x28 + 0xa0;
    tgt = *(u8 **)(obj + 0x10);
    ang = Math_VectorToAngle(*(float *)(tgt + 0x20) - *(float *)obj, *(float *)(tgt + 0x28) - *(float *)(obj + 8));
    tgt = *(u8 **)(obj + 0x10);
    d = ang - *(float *)(tgt + 0x34);
    t = 3.14159274f + d;
    if (t >= 0.0f) {
        w = d - 6.28318548f * (float)(s32)(t / 6.28318548f);
    } else {
        c = 6.28318548f;
        w = c + (d - c * (float)(s32)(t / c));
    }
    if (*(u8 *)(*(u32 *)(tgt + 0x148) + 0x1f0) == 0) {
        if (info[7] != 0) {
            if (w < 0.0f) w = -w;
            if (w < 1.5704999f) anim = 0x1e; else anim = 0x20;
        } else if (*(s32 *)(tgt + 0x120) > 0) {
            ad = (w < 0.0f) ? -w : w;
            if (ad < 0.785249949f) {
                anim = 0x16;
            } else {
                ad = (w < 0.0f) ? -w : w;
                if (!(ad <= 2.35574985f)) anim = 0x17;
                else if (w < 0.0f) anim = 0x15;
                else if (!(w <= 0.0f)) anim = 0x14;
            }
        } else {
            if (w < 0.0f) w = -w;
            if (w < 1.5704999f) anim = 0x28; else anim = 0x29;
        }
    } else {
        if (*(s32 *)(tgt + 0x120) > 0) anim = 0x5a; else anim = 0x5c;
    }
    if (CheckAnimParam(tgt, (u16)anim) != 0) return anim;
    if (*(s32 *)(*(u8 **)(obj + 0x10) + 0x120) > 0) return 0x16;
    return 0x28;
}
