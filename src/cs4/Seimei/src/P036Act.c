#include "common.h"

/* P036ActDead @ 0x215770 .. 0x2157B8 (0x48 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void EneActDead(void *, void *);
extern signed int SFX_Delete();

/* P036ActAppear @ 0x2157C0 .. 0x215868 (0xa8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x2157cc
 */

extern unsigned int CheckAnimNumFrame(void *, float);
extern signed int SFX_Create_OnDir_Attach(unsigned short, float *, float *, void *, unsigned short,
    unsigned char, unsigned char);
extern void EneAppearProc(void *, void *);
extern unsigned int CheckAnimEndFrame(void *);
extern u32 VW[];
extern u32 V0[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * P036ActInit(s32 a0 , u32 *a1 );
static void P036ActAppear(void *a0 , void *a1 );
static void P036ActDead(void *a0 , void *a1 );


/* P036ActInit @ 0x215870 .. 0x21588C (0x1c bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */




u8 * P036ActInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)P036ActAppear;
    *(u32 *)(((u8 *)a1 + 0x94)) = (u32)P036ActAppear;
    v1 = (u8 *)P036ActDead;
    *(u32 *)(((u8 *)a1 + 0x90)) = (u32)P036ActDead;
    return;
}

static void P036ActAppear(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 *s2;
    u32 *s1;
    u32 s0;
    s32 v0;

    s2 = (u32 *)a0;
    s1 = (u32 *)a1;
    s0 = *(s32 *)(((u8 *)a0 + 0x100));
    v0 = CheckAnimNumFrame((void *)s0, 1.0f);
    if ((u32)v0 != 0) {
        a1 = (void *)VW;
        v0 = SFX_Create_OnDir_Attach((u32)0x1f2, (float *)VW, (float *)V0, (void *)(u32 *)s2, 0, 0,
            0);
        *(u32 *)(((u8 *)s1 + 0x200)) = v0;
    }
    EneAppearProc((void *)(u32)s2, (void *)(u32 *)s1);
    v0 = CheckAnimEndFrame((void *)s0);
    if ((u32)v0 != 0) {
        v0 = *(s32 *)(((u8 *)s1 + 0x100));
        ((void (*)(u32, u32, u32))v0)((u32)s2, (u32)(u32 *)s1, 0);
    }
    return;
}

static void P036ActDead(void *a0 /* r4 */, void *a1 /* r5 */) {
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
