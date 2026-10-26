#include "common.h"

/* sghTime_GetWait @ 0x20FBD0 .. 0x20FBD8 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x20fbd4 computes the return value
 */

extern u32 gWaitTime;

/* sghTime_SetWait @ 0x20FBE0 .. 0x20FBE8 (0x8 bytes) */

extern u32 gWaitTime;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void sghTime_SetWait(s32 a0 );
u32 sghTime_GetWait(void);


void sghTime_SetWait(s32 a0 /* r4 */) {
    gWaitTime = a0;
    return;
}

u32 sghTime_GetWait(void) {
    return gWaitTime;
}
static u32 gWaitTime;
