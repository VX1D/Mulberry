#include "common.h"

/* SetE041Dead @ 0x213A90 .. 0x213AA8 (0x18 bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x213a98
 *   tail: j ChangeAnimParam at 0x213aa0 leaves the function
 *   a0 forwarded to ChangeAnimParam
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);

/* E041ActDead @ 0x213AB0 .. 0x213B24 (0x74 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x43020000 at 0x213ae4
 */

extern unsigned int CheckAnimNumFrame(void *, float);
extern void EneDeadProc(void *, void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * E041ActInit(s32 a0 , u32 *a1 );
static void E041ActDead(void *a0 , void *a1 );
static void SetE041Dead(void *a0 , void *a1 );


/* E041ActInit @ 0x213B30 .. 0x213B4C (0x1c bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */




u8 * E041ActInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)E041ActDead;
    *(u32 *)(((u8 *)a1 + 0x90)) = (u32)E041ActDead;
    v1 = (u8 *)SetE041Dead;
    *(u32 *)(((u8 *)a1 + 0x110)) = (u32)SetE041Dead;
    return;
}

static void E041ActDead(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s0;
    s32 v1;
    s32 v0;
    void *a0_s1; // a0

    v1 = 0x5b;
    s0 = (u8 *)a1;
    a1 = (void *)*(s16 *)(((u8 *)a0 + 0x104));
    a0_s1 = (void *)*(s32 *)(((u8 *)a0 + 0x100));
    switch ((u32)a1) {
    case 91:
        v0 = CheckAnimNumFrame(a0_s1, 130.0f);
        if ((u32)v0 == 0) {
            break;
        }
        v0 = 1;
        a0_s1 = a0;
        *(u8 *)(s0 + 0x1f3) = v0;
        a1 = (void *)s0;
        EneDeadProc(a0_s1, a1);
    }
    return;
}

static void SetE041Dead(void *a0 /* r4 */, void *a1 /* r5 */) {
    *(u8 *)(((u8 *)a1 + 0x180)) = 4;
    a1 = (void *)(s32)0x5b;
    ChangeAnimParam(a0, (signed int)a1, (float)({ float native_result_0; __asm__("mtc1 %1,%0" :
        "=f"(native_result_0) : "r"((u32)0)); native_result_0; }));
    return;
}
