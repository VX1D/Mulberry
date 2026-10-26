#include "common.h"

signed int FsMsgGet(unsigned short **a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */) {
    u8 *ents;
    u8 *tbl;
    s32 lo;
    s32 hi;
    s32 mid;
    u8 *ent;
    u32 off;

    tbl = (u8 *)a1 + *(s32 *)((u8 *)a1 + 0x14);
    ents = (u8 *)a1 + 0x1c;
    hi = *(s32 *)((u8 *)a1 + 0xc) - 1;
    lo = 0;
    *(u32 *)a0 = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        ent = ents + mid * 0xc;
        if (*(s32 *)(ent + 8) < a2) {
            lo = mid + 1;
        } else if (a2 < *(s32 *)(ent + 4)) {
            hi = mid - 1;
        } else {
            off = *(u32 *)(tbl + (*(s32 *)ent + (a2 - *(s32 *)(ent + 4))) * 4);
            if (off == 0) {
                return -3;
            }
            *(u32 *)a0 = (u32)((u8 *)a1 + off);
            return 0;
        }
    }
    return -2;
}

