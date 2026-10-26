#include "common.h"

/* StringCorrectPath4Disc @ 0x14FB40 .. 0x14FBF4 (0xb4 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @763 is the string 'cdrom0:'
 *   delay: addiu at 0x14fbbc writes a register its branch at 0x14fbb8 reads
 *   cfg: kept goto: 0x14fb7c -> .L0014FBD0
 *   cfg: loop test does not fall through into its body: 0x14fbd0
 *   cfg: kept branch: 0x14fbd0 if (..) goto .L0014FB80
 */

extern int strncmp(void *, void *, unsigned int);
extern int toupper(int);

/* ChangeExtension @ 0x14FC00 .. 0x14FC60 (0x60 bytes, frame 0x40) */

extern void * strrchr(void *, int);
extern void * strncpy(void *, void *, unsigned int);
extern void * strcat(void *, void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
char * SearchFileName(char *a0 );
void ChangeExtension(void *a0 , char *a1 , char *a2 );
void StringCorrectPath4Disc(char *a0 , signed int a1 );


/* SearchFileName @ 0x14FC60 .. 0x14FCC4 (0x64 bytes) */
/*
 * dcomp notes:
 *   return: daddu at 0x14fcc0 computes the return value
 *   cfg: kept goto: 0x14fc64 -> .L0014FC70
 *   cfg: loop body is not one contiguous region: .L0014FC70
 *   cfg: kept goto: 0x14fc70 -> .L0014FC80
 *   cfg: loop test does not fall through into its body: 0x14fc80
 *   cfg: kept branch: 0x14fc80 if (..) goto .L0014FC78
 *   cfg: kept branch: 0x14fcac if (..) goto .L0014FC68
 *   declaration vs inferred signature: return char * vs inferred u32
 */

char * SearchFileName(char *a0 /* r4 */) {
    u8 *a1;
    s32 v1;
    u32 v0;

    v1 = 0x5c;
    goto _L0014FC70;
    _L0014FC68:;
    a0 = (char *)(a0 + v0);
    while (1) {
        _L0014FC70:;
        a1 = (u8 *)a0;
        goto _L0014FC80;
        _L0014FC78:;
        a1 = (u8 *)(a1 + 1);
        _L0014FC80:;
        v0 = *(s8 *)a1;
        if (v0 != (u32)v1 && v0 != 0) {
            goto _L0014FC78;
        }
        if (v0 == (u32)v1) {
            v0 = (s32)(a1 - (u32)(a0));
        } else {
            v0 = -1;
        }
        v0 = ~v0;
        v0 = v0 != 0;
        if (v0 != 0) {
            goto _L0014FC68;
        }
        break;
    }
    return (char *)a0;
}

void ChangeExtension(void *a0 /* r4 */, char *a1 /* r5 */, char *a2 /* r6 */) {
    u8 *v0;

    v0 = (u8 *)strrchr((void *)a1, 0x2e);
    strncpy((void *)a0, (void *)a1, (s32)(v0 - (u32)(a1)));
    strcat((void *)a0, (void *)a2);
    return;
}

void StringCorrectPath4Disc(char *a0 /* r4 */, signed int a1 /* r5 */) {
    s32 s2;
    u8 *s1;
    s32 s0;
    s32 v1;
    u32 v0;

    s2 = a1;
    s1 = (u8 *)a0;
    a1 = (signed int)"cdrom0:";
    s0 = 0;
    v0 = strncmp((void *)a0, (void *)"cdrom0:", 6);
    if (v0 != 0) {
        s0 = 1;
        goto _L0014FBD0;
        _L0014FB80:;
        v1 = 0x3a;
        if ((u32)a0 == (u32)v1) {
            s0 = 1;
        }
        if ( (u32)s0 != 0 && (u32)s2 ) {
            a0 = (char *)(s8)a0;
            v0 = toupper((int)a0);
            *(u8 *)s1 = v0;
        }
        a0 = (char *)*(s8 *)s1;
        v1 = 0x2f;
        v1 = 0x5c;
        if ((u32)a0 == 0x2f) {
            *(u8 *)s1 = v1;
        }
        s1 = (u8 *)(s1 + 1);
    }
    _L0014FBD0:;
    a0 = (char *)*(s8 *)s1;
    if ((u32)a0 != 0) {
        goto _L0014FB80;
    }
    return;
}
