#include "common.h"

/* sghGetGameInfo @ 0x207E10 .. 0x207E1C (0xc bytes) */

extern u8 gSGHInfo[9];

u8 * sghGetGameInfo(void) {
    return (u8 *)gSGHInfo;
}
static u8 gSGHInfo[0x9];
