#include "common.h"

/* GetSpiritNum @ 0x18DD90 .. 0x18DDB8 (0x28 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed short vs inferred u32
 */

extern unsigned short ItemMng_GetItemNum(unsigned short, unsigned short);

/* AddSpiritNum @ 0x18DDC0 .. 0x18DDEC (0x2c bytes, frame 0x10) */

extern u32 ItemMng_Add();

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void InitSpiritMng(void);
void AddSpiritNum(s32 a0 , s32 a1 , s32 a2 );
signed short GetSpiritNum(signed int a0 );
signed int CheckSpiritType(signed int a0 );


/* InitSpiritMng @ 0x18DDF0 .. 0x18DDF8 (0x8 bytes) */

void InitSpiritMng(void) {
    return;
}

void AddSpiritNum(s32 a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */) {
    if (a2 != 0) {
        a2 = a1;
        a1 = (u16)a0;
        ItemMng_Add(3, a1, a2);
    }
    return;
}

signed short GetSpiritNum(signed int a0 /* r4 */) {
    return ItemMng_GetItemNum(3, a0);
}

/* CheckSpiritType @ 0x18DD30 .. 0x18DD90 (0x60 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x18dd38 writes a register its branch at 0x18dd34 reads
 *   delay: addiu at 0x18dd4c writes a register its branch at 0x18dd48 reads
 *   delay: addiu at 0x18dd60 writes a register its branch at 0x18dd5c reads
 *   cfg: kept goto: 0x18dd78 -> .L0018DD88
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int CheckSpiritType(signed int a0 /* r4 */) {
    u32 v0;

    v0 = 0x26;
    switch ((u32)(s32)a0) {
    case 8:
    case 9:
    case 10:
    case 12:
    case 20:
    case 38:
        v0 = 1;
        return v0;
    }
    return (u32)0;
}
