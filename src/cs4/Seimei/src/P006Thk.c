#include "common.h"

/* P006ThkStay @ 0x1A5370 .. 0x1A5438 (0xc8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern int rand();

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * P006ThkInit(s32 a0 , u32 *a1 );
static void P006ThkStay(void *a0 , void *a1 );


/* P006ThkInit @ 0x1A5440 .. 0x1A5450 (0x10 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */



u8 * P006ThkInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    *(u32 *)a1 = (u32)P006ThkStay;
    return;
}

static void P006ThkStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u8 *s0;
    u32 v1;
    s32 v0;

    v1 = 0x3c;
    s1 = (u8 *)a0;
    a0 = (void *)*(u16 *)(((u8 *)a1 + 0x1dc));
    v1 = (s32)a0 % (s32)(0x3c);
    s0 = (u8 *)a1;
    if (v1 == 0) {
        v0 = rand();
        v1 = 0x64;
        v1 = v0 % (s32)(0x64);
        if ((s32)v1 < (s32)0x1e) {
            v0 = *(s16 *)(s1 + 0x104);
            switch ((u32)v0) {
            case 0:
                v0 = *(s32 *)(s0 + 0x100);
                a0 = (void *)s1;
                a1 = (void *)s0;
                ((void (*)(u32, u32, s32))v0)((u32)a0, (u32)a1, 0x5a);
                break;
            default:
                v0 = *(s32 *)(s0 + 0x100);
                a0 = (void *)s1;
                a1 = (void *)s0;
                ((void (*)(u32, u32, u32))v0)((u32)a0, (u32)a1, 0);
            }
        }
    }
    v1 = *(u16 *)(s0 + 0x1dc);
    v1 = v1 + 1;
    *(u16 *)(s0 + 0x1dc) = v1;
    return;
}
