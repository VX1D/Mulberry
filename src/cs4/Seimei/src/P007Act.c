#include "common.h"

/* P007ActDead @ 0x190EE0 .. 0x190F28 (0x48 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void EneActDead(void *, void *);
extern signed int SFX_Delete();

/* P007ActAppear @ 0x190F40 .. 0x190FE8 (0xa8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42700000 at 0x190f4c
 */

extern unsigned int CheckAnimNumFrame(void *, float);
extern signed int SFX_Create_OnDir_Attach(unsigned short, float *, float *, void *, unsigned short,
    unsigned char, unsigned char);
extern void EneAppearProc(void *, void *);
extern unsigned int CheckAnimEndFrame(void *);
extern u32 VW[];
extern u32 V0[];

/* P007ActInit @ 0x190FF0 .. 0x191020 (0x30 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32; 1 parameters vs 2 inferred
 */

static void P007ActAppear(void *a0 /* r4 */, void *a1 /* r5 */);
static void P007ActDead(void *a0 /* r4 */, void *a1 /* r5 */);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void P007ActInit(void *a0 , u8 *a1);
static void P007ActAppear(void *a0 , void *a1 );
static void P007ActStay(void);
static void P007ActDead(void *a0 , void *a1 );


void P007ActInit(void *a0 /* r4 */, u8 *a1) {
    u8 *v1;

    v1 = (u8 *)P007ActAppear;
    *(u32 *)(((u8 *)a1 + 0x94)) = (u32)P007ActAppear;
    v1 = (u8 *)P007ActStay;
    *(u32 *)(((u8 *)a1 + 0x80)) = (u32)P007ActStay;
    v1 = (u8 *)P007ActDead;
    *(u32 *)(((u8 *)a1 + 0x90)) = (u32)P007ActDead;
    *(u8 *)(((u8 *)a1 + 0x1da)) = (s32)(u8 *)(s32)1;
    return;
}

static void P007ActAppear(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 *s2;
    u32 *s1;
    u32 s0;
    s32 v0;

    s2 = (u32 *)a0;
    s1 = (u32 *)a1;
    s0 = *(s32 *)(((u8 *)a0 + 0x100));
    v0 = CheckAnimNumFrame((void *)s0, 60.0f);
    if ((u32)v0 != 0) {
        a1 = (void *)VW;
        v0 = SFX_Create_OnDir_Attach(0x1b9, (float *)VW, (float *)V0, (void *)(u32 *)s2, 0, 0, 0);
        *(u32 *)(((u8 *)s1 + 0x200)) = v0;
    }
    EneAppearProc((void *)s2, (void *)(u32 *)s1);
    v0 = CheckAnimEndFrame((void *)s0);
    if ((u32)v0 != 0) {
        v0 = *(s32 *)(((u8 *)s1 + 0x100));
        ((void (*)(u32, u32, u32))v0)((u32)s2, (u32)(u32 *)s1, 0);
    }
    return;
}

/* P007ActStay @ 0x190F30 .. 0x190F38 (0x8 bytes) */

static void P007ActStay(void) {
    return;
}

static void P007ActDead(void *a0 /* r4 */, void *a1 /* r5 */) {
    void *a1_s0; // a1
    u32 a0_scalar; // a0
    u8 *a1_bytes; // s0

    a1_bytes = (u8 *)a1;
    EneActDead(a0, (void *)a1_bytes);
    a0_scalar = *(s32 *)(a1_bytes + 0x200);
    a1_s0 = (void *)0;
    if (a0_scalar != (u32)-1) {
        SFX_Delete(a0_scalar, 0);
        *(u32 *)(a1_bytes + 0x200) = -1;
    }
    return;
}
