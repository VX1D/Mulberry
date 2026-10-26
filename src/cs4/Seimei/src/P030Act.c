#include "common.h"

/* P030ActDead @ 0x1A6AC0 .. 0x1A6B8C (0xcc bytes, frame 0x10) */
/*
 * dcomp notes:
 *   fpu: float literal 0x41f00000 at 0x1a6acc
 *   fpu: float literal 0x3d23d70a at 0x1a6af0
 *   fpu: float literal 0x3f800000 at 0x1a6af8
 *   fpu: float literal 0x42480000 at 0x1a6b28
 *   fpu: float literal 0x3d23d70a at 0x1a6b4c
 *   fpu: float literal 0x3ca3d70a at 0x1a6b64
 *   a1 forwarded to EneDeadProc
 */

extern void EneDeadProc(void *, void *);
extern u32 MdlMng[];

/* P030ActDamage @ 0x1A6B90 .. 0x1A6C54 (0xc4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x41f00000 at 0x1a6b9c
 *   fpu: float literal 0x3d23d70a at 0x1a6bcc
 *   fpu: float literal 0x3f800000 at 0x1a6bd4
 *   fpu: float literal 0x3d23d70a at 0x1a6c0c
 *   fpu: float literal 0x00000000 at 0x1a6c10
 */

extern unsigned int CheckAnimEndFrame(void *);

/* P030ActStay @ 0x1A6C60 .. 0x1A6CA8 (0x48 bytes, frame 0x30) */

extern void sceVu0CopyVector();
extern u32 MdlMng[];

/* P030ActAppear @ 0x1A6CB0 .. 0x1A6D48 (0x98 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3d23d70a at 0x1a6cf0
 *   fpu: float literal 0x00000000 at 0x1a6cf4
 */

extern void EneAppearProc(void *, void *);
extern unsigned int CheckAnimEndFrame(void *);

/* P030ActInit @ 0x1A6D50 .. 0x1A6DA0 (0x50 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32; 1 parameters vs 2 inferred
 */

static void P030ActAppear(void *a0 /* r4 */, void *a1 /* r5 */);
static void P030ActDamage(void *a0 /* r4 */, void *a1 /* r5 */);
static void P030ActDead(void *a0 /* r4 */, void *a1 /* r5 */);
static signed int GetP030DamageAnim(void *a0 /* r4 */);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void P030ActInit(void *a0 , u8 *a1);
static void P030ActAppear(void *a0 , void *a1 );
static void P030ActStay(u8 *a0 );
static void P030ActDamage(void *a0 , void *a1 );
static void P030ActDead(void *a0 , void *a1 );
static signed int GetP030DamageAnim(void *a0 );


void P030ActInit(void *a0 /* r4 */, u8 *a1) {
    u8 *v1;

    v1 = (u8 *)P030ActAppear;
    *(u32 *)(((u8 *)a1 + 0x94)) = (u32)P030ActAppear;
    v1 = (u8 *)P030ActStay;
    *(u32 *)(((u8 *)a1 + 0x80)) = (u32)P030ActStay;
    v1 = (u8 *)P030ActDamage;
    *(u32 *)(((u8 *)a1 + 0x8c)) = (u32)P030ActDamage;
    v1 = (u8 *)P030ActDead;
    *(u32 *)(((u8 *)a1 + 0x90)) = (u32)P030ActDead;
    v1 = (u8 *)GetP030DamageAnim;
    *(u32 *)(((u8 *)a1 + 0x184)) = (u32)GetP030DamageAnim;
    *(u8 *)(((u8 *)a1 + 0x1da)) = (s32)(u8 *)(s32)1;
    v1 = (u8 *)0xffff;
    *(u16 *)(((u8 *)a1 + 0x1fa)) = 0xffff;
    return;
}

static void P030ActAppear(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u32 *s1;
    u32 s0;
    s32 v0;
    float f2;
    float f1;

    s2 = (u8 *)a0;
    s0 = *(s32 *)(((u8 *)a0 + 0x100));
    s1 = (u32 *)a1;
    EneAppearProc(a0, a1);
    v0 = CheckAnimEndFrame((void *)s0);
    if ((u32)v0 != 0) {
        f2 = *(float *)(s2 + 0x10c);
        f1 = 0.0399999991f;
        f1 = (f2 - 0.0399999991f);
        *(f32 *)(s2 + 0x10c) = f1;
        if ((s32)(f1 <= 0.0f)) {
            a0 = (void *)s2;
            s0 = *(s32 *)(MdlMng + 0x4652);
            a1 = (void *)s1;
            *(f32 *)(s2 + 0x10c) = (float)0.0f;
            v0 = *(s32 *)(((u8 *)s1 + 0x100));
            ((void (*)(u32, u32, u32))v0)((u32)a0, (u32)a1, 0);
            *(u32 *)((s0 + 0x1b4)) = (u32)s2;
        }
    }
    return;
}

static void P030ActStay(u8 *a0 /* r4 */) {
    u32 s1;
    u8 *s0;
    u32 a1;

    s1 = (u32)a0;
    a0 = (u8 *)(s1 + 0x20);
    s0 = (u8 *)MdlMng + 0x11800;
    a1 = (u32)((u8 *)s0 + 0x20);
    sceVu0CopyVector(a0, a1);
    a0 = (u8 *)(s1 + 0x30);
    a1 = (u32)((u8 *)s0 + 0x30);
    sceVu0CopyVector(a0, a1);
    return;
}

static void P030ActDamage(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u32 *s0;
    float f1;
    float f0;
    s32 v1;
    s32 v0;

    v0 = 0x41f00000;
    f0 = 30.0f;
    s1 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x100));
    f1 = *(float *)a0;
    s0 = (u32 *)a1;
    if ((s32)(f1 <= 30.0f)) {
        v0 = 0x3d230000;
        v1 = 0x3d230000 | 0xd70a;
        f1 = 0.0399999991f;
        v0 = 0x3f800000;
        f1 = (*(float *)(s1 + 0x10c) + (float)f1);
        *(f32 *)(s1 + 0x10c) = f1;
        if (!(s32)(f1 <= 1.0f)) {
            *(f32 *)(s1 + 0x10c) = 1.0f;
        }
    }
    v0 = CheckAnimEndFrame(a0);
    if ((u32)v0 != 0) {
        f1 = 0.0399999991f;
        f1 = (*(float *)(s1 + 0x10c) - 0.0399999991f);
        *(f32 *)(s1 + 0x10c) = f1;
        if ((s32)(f1 <= 0.0f)) {
            *(f32 *)(s1 + 0x10c) = 0.0f;
            v0 = *(s32 *)(((u8 *)s0 + 0x100));
            ((void (*)(u32, u32, u32))v0)((u32)(u8 *)s1, (u32)(u32 *)s0, 0);
        }
    }
    return;
}

static void P030ActDead(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *a3;
    float f1;
    u32 a2;
    float f0;
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    v1 = 0x41f00000;
    f0 = 30.0f;
    a3 = (u8 *)*(s32 *)(a0_bytes + 0x100);
    f1 = *(float *)a3;
    if ((s32)(f1 <= 30.0f)) {
        v1 = 0x3d230000;
        a2 = 0x3d230000 | 0xd70a;
        f1 = 0.0399999991f;
        v1 = 0x3f800000;
        f1 = (*(float *)(a0_bytes + 0x10c) + (float)f1);
        *(f32 *)(a0_bytes + 0x10c) = f1;
        if (!(s32)(f1 <= 1.0f)) {
            v1 = *(s32 *)(MdlMng + 0x4652);
            *(f32 *)(a0_bytes + 0x10c) = 1.0f;
            *(u32 *)((v1 + 0x1b4)) = 0;
        }
    }
    v1 = 0x42480000;
    f1 = 50.0f;
    f0 = *(float *)a3;
    f1 = (*(float *)(a3 + 0xc) - 50.0f);
    if (f1 <= f0) {
        f1 = *(float *)(a0_bytes + 0x10c);
        v1 = 0x3d23d70a;
        f0 = 0.0399999991f;
        if (!(f1 < 0.0399999991f)) {
            v1 = 0x3ca3d70a;
            f0 = 0.0199999996f;
            *(f32 *)(a0_bytes + 0x10c) = (f1 - 0.0199999996f);
        } else {
            *(u32 *)(a0_bytes + 0x10c) = 0;
            EneDeadProc((void *)a0_bytes, a1);
        }
    }
    return;
}

/* GetP030DamageAnim @ 0x1A6AA0 .. 0x1A6ABC (0x1c bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1a6aac writes a register its branch at 0x1a6aa8 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

static signed int GetP030DamageAnim(void *a0 /* r4 */) {
    u32 v0;

    v0 = *(s32 *)(((u8 *)a0 + 0x10));
    v0 = *(s32 *)((v0 + 0x120));
    if ((s32)v0 > 0) {
        return 0x16;
    }
    return 0x28;
}
