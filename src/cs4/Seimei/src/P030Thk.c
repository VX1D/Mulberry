#include "common.h"

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void P030ThkInit(void *a0 , u32 *a1);
static void P030ThkStay(void);


/* P030ThkInit @ 0x1A6DB0 .. 0x1A6DC0 (0x10 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u8 *; 1 parameters vs 2 inferred
 */

void P030ThkInit(void *a0 /* r4 */, u32 *a1) {
    *(u32 *)a1 = (u32)P030ThkStay;
    return;
}

/* P030ThkStay @ 0x1A6DA0 .. 0x1A6DA8 (0x8 bytes) */

static void P030ThkStay(void) {
    return;
}
