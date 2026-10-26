#include "common.h"

/* GetEneParam @ 0x193BE0 .. 0x193C3C (0x5c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x193c0c writes a register its branch at 0x193c08 reads
 *   declaration vs inferred signature: return void * vs inferred u32
 */

extern unsigned int GetBindOffsetByIndex(void *, unsigned short);
extern u32 lpEneParamBuf;

/* ReadEneParam @ 0x193C40 .. 0x193C58 (0x18 bytes) */
/*
 * dcomp notes:
 *   literal: @665 is the string 'eneparam.bnd'
 *   tail: j ReadBinderFile at 0x193c50 leaves the function
 */

extern void ReadBinderFile(char *, void **, signed int, signed int);
extern u32 lpEneParamBuf;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void ReadEneParam(void);
void * GetEneParam(signed int a0 , unsigned char a1 );


void ReadEneParam(void) {
    ReadBinderFile("eneparam.bnd", (void **)&lpEneParamBuf, 0, (s32)0x17);
    return;
}

void * GetEneParam(signed int a0 /* r4 */, unsigned char a1 /* r5 */) {
    u32 a2;
    u32 v0;
    u16 a1_guard_word;

    a2 = lpEneParamBuf;
    if (a2 == 0) {
        return (void *)(u32)0;
    }
    if ((u32)(u8)a1 == (u32)1) {
        v0 = GetBindOffsetByIndex((void *)a2, a0);
    } else {
        v0 = (u32)(a0) + 0x32;
        a1_guard_word = v0;
        v0 = GetBindOffsetByIndex((void *)a2, a1_guard_word);
    }
    return (void *)v0;
}
static u32 lpEneParamBuf;
