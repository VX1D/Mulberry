#include "common.h"

/* P027ActStay @ 0x1A5450 .. 0x1A5574 (0x124 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1a5480 writes a register its branch at 0x1a547c reads
 *   delay: addiu at 0x1a5494 writes a register its branch at 0x1a5490 reads
 */

extern unsigned int CheckAnimEndFrame(void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * P027ActInit(s32 a0 , u32 *a1 );
static void P027ActStay(void *a0 , void *a1 );


/* P027ActInit @ 0x1A5580 .. 0x1A5590 (0x10 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */



u8 * P027ActInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    *(u32 *)(((u8 *)a1 + 0x80)) = (u32)P027ActStay;
    return;
}

static void P027ActStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 *s0;
    s32 v1;
    s32 v0;
    u32 a2;
    void *a0_s1; // a0

    v1 = 3;
    s0 = (u32 *)a1;
    a1 = (void *)*(s16 *)(((u8 *)a0 + 0x104));
    a0_s1 = (void *)*(s32 *)(((u8 *)a0 + 0x100));
    switch ((u32)a1) {
    case 14:
    case 1:
        v0 = CheckAnimEndFrame(a0_s1);
        if ((u32)v0 == 0) {
            break;
        }
        v0 = *(s32 *)(((u8 *)s0 + 0x100));
        a0_s1 = a0;
        a1 = (void *)s0;
        a2 = 2;
        ((void (*)(u32, u32, s32))v0)((u32)a0_s1, (u32)a1, a2);
        break;
    case 90:
        v0 = CheckAnimEndFrame(a0_s1);
        if ((u32)v0 == 0) {
            break;
        }
        v0 = *(s32 *)(((u8 *)s0 + 0x100));
        a0_s1 = a0;
        a1 = (void *)s0;
        a2 = 0x5b;
        ((void (*)(u32, u32, s32))v0)((u32)a0_s1, (u32)a1, a2);
        break;
    case 92:
        v0 = CheckAnimEndFrame(a0_s1);
        if ((u32)v0 == 0) {
            break;
        }
        v0 = *(s32 *)(((u8 *)s0 + 0x100));
        a0_s1 = a0;
        a1 = (void *)s0;
        a2 = 0x5d;
        ((void (*)(u32, u32, s32))v0)((u32)a0_s1, (u32)a1, a2);
        break;
    case 3:
        v0 = CheckAnimEndFrame(a0_s1);
        if ((u32)v0 == 0) {
            break;
        }
        v0 = *(s32 *)(((u8 *)s0 + 0x100));
        a0_s1 = a0;
        a1 = (void *)s0;
        ((void (*)(u32, u32, u32))v0)((u32)a0_s1, (u32)a1, 0);
    }
    return;
}
