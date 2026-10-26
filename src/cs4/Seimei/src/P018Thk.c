#include "common.h"

/* P018ThkStay @ 0x1A5E20 .. 0x1A5EBC (0x9c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int CheckEneAttackEnable(void *, void *);
extern unsigned int EneSearchAttackRange();

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * P018ThkInit(s32 a0 , u32 *a1 );
static void P018ThkStay(void *a0 , void *a1 );


/* P018ThkInit @ 0x1A5EC0 .. 0x1A5ED0 (0x10 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */



u8 * P018ThkInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    *(u32 *)a1 = (u32)P018ThkStay;
    return;
}

static void P018ThkStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 s1;
    u8 *s0;
    u32 v1;
    s32 v0;

    s1 = (u32)a0;
    s0 = (u8 *)a1;
    v0 = CheckEneAttackEnable(a0, a1);
    if ((u32)v0 == 0) {
        v1 = 0;
    } else {
        v0 = EneSearchAttackRange(s1, (u8 *)s0, 0);
        if ((u32)v0 != 0) {
            ((void (*)(u32, u32, s32))(s32)*(s32 *)(s0 + 0x110))(s1, (u32)(u8 *)s0, 0x28);
            v1 = 1;
        } else {
            v1 = 0;
        }
    }
    if (v1 == 0) {
        v1 = *(u16 *)(s0 + 0x1dc);
        *(u16 *)(s0 + 0x1dc) = v1 + 1;
    }
    return;
}
