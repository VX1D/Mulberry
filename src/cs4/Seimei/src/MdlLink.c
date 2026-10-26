#include "common.h"

/* ReadMdlLink @ 0x13BD00 .. 0x13BD40 (0x40 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   a0 forwarded to FileRead
 *   declaration vs inferred signature: return void * vs inferred u32
 */

extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void * ReadMdlLink(char *a0 , void **a1 , signed int a2 , signed int a3 );
void RemapMdlLink(void *a0 );


void * ReadMdlLink(char *a0 /* r4 */, void **a1 /* r5 */, signed int a2 /* r6 */, signed int a3 /*
        r7 */) {
    s32 t1;
    u32 *s0;
    s32 v0;

    t1 = (s32)a2;
    s0 = (u32 *)a1;
    a1 = (void **)(s32)-1;
    a2 = (signed int)s0;
    FileRead(a0, (signed int)a1, (unsigned char **)a2, 0, (s32)a3, t1, 0);
    v0 = *(s32 *)s0;
    return (void *)v0;
}

/* RemapMdlLink @ 0x13BC60 .. 0x13BCF8 (0x98 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0013BC68
 *   declaration vs inferred signature: return void vs inferred u32
 */

void RemapMdlLink(void *a0 /* r4 */) {
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    if ((u32)a0_bytes != 0) {
        do {
            v1 = *(s32 *)a0_bytes;
            if (v1 != 0) {
                *(u32 *)a0_bytes = (s32)(a0_bytes + v1);
            }
            v1 = *(s32 *)(a0_bytes + 4);
            if (v1 != 0) {
                *(u32 *)(a0_bytes + 4) = (s32)(a0_bytes + v1);
            }
            v1 = *(s32 *)(a0_bytes + 0xc);
            if (v1 != 0) {
                *(u32 *)(a0_bytes + 0xc) = (s32)(a0_bytes + v1);
            }
            v1 = *(s32 *)(a0_bytes + 0x10);
            if (v1 != 0) {
                *(u32 *)(a0_bytes + 0x10) = (s32)(a0_bytes + v1);
            }
            v1 = *(s32 *)(a0_bytes + 0x18);
            if (v1 != 0) {
                *(u32 *)(a0_bytes + 0x18) = (s32)(a0_bytes + v1);
            }
            a0_bytes = (u8 *)*(s32 *)(a0_bytes + 0x18);
        } while ((u32)(s32)a0_bytes != 0);
    }
    return;
}
