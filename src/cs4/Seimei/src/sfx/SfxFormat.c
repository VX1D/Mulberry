#include "common.h"

/* SFX_GetSeqParam @ 0x1C5E10 .. 0x1C600C (0x1fc bytes, frame 0x90) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1c5e48
 *   delay: lui at 0x1c5ebc writes a register its branch at 0x1c5eb8 reads
 *   delay: lui at 0x1c5ef4 writes a register its branch at 0x1c5ef0 reads
 *   fpu: float literal 0x00000000 at 0x1c5f50
 *   fpu: mtc1 reinterprets s1 at 0x1c5f60
 *   fpu: mtc1 reinterprets v0 at 0x1c5f6c
 *   fpu: mtc1 reinterprets v1 at 0x1c5f84
 *   fpu: mov.s at 0x1c5fc4 is a float copy
 *   cfg: loop header already being structured: .L001C5E80
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u32 zero_value_tab[];
extern u32 get_value_tab[];
extern u32 erp_value_tab[];

/* __SFX_GetErpValue_char @ 0x1C61D0 .. 0x1C628C (0xbc bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets a1 at 0x1c6230
 *   fpu: mtc1 reinterprets a0 at 0x1c6238
 */

extern u32 erp_tab[];

/* __SFX_GetErpValue_u_char @ 0x1C6290 .. 0x1C63EC (0x15c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x4f000000 at 0x1c62e4
 *   fpu: mtc1 reinterprets v1 at 0x1c62f4
 *   fpu: mtc1 reinterprets a1 at 0x1c630c
 *   fpu: mtc1 reinterprets a2 at 0x1c6324
 *   fpu: mtc1 reinterprets a1 at 0x1c6338
 *   fpu: mtc1 reinterprets a2 at 0x1c6354
 *   fpu: mtc1 reinterprets a1 at 0x1c636c
 */

extern u32 erp_tab[];

extern char *strncpy(char *, const char *, unsigned int);


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
s32 SFX_DataRemap(char *a0, void *a1, u32 a2);
void __SFX_GetErpValue_float(void *a0 , void *a1 , void *a2 , signed int a3 , signed int t0 , float arg5 );
void __SFX_GetErpValue_u_int(void *a0 , void *a1 , void *a2 , signed int a3 , signed int t0 , float arg5 );
void __SFX_GetErpValue_int(void *a0 , void *a1 , void *a2 , signed int a3 , signed int t0 , float arg5 );
void __SFX_GetErpValue_u_short(void *a0 , void *a1 , void *a2 , signed int a3 , signed int t0 , float arg5 );
void __SFX_GetErpValue_short(void *a0 , void *a1 , void *a2 , signed int a3 , signed int t0 , float arg5 );
void __SFX_GetErpValue_u_char(void *a0 , void *a1 , void *a2 , signed int a3 , signed int t0 , float arg5 );
void __SFX_GetErpValue_char(void *a0 , void *a1 , void *a2 , signed int a3 , signed int t0 , float arg5 );
u32 __SFX_ZeroValue_float(u32 *a0 , s32 a1 );
u32 __SFX_ZeroValue_u_int(u32 *a0 , s32 a1 );
u32 __SFX_ZeroValue_int(u32 *a0 , s32 a1 );
u32 __SFX_ZeroValue_u_short(u16 *a0 , s32 a1 );
u32 __SFX_ZeroValue_short(u16 *a0 , s32 a1 );
u32 __SFX_ZeroValue_u_char(u8 *a0 , s32 a1 );
u32 __SFX_ZeroValue_char(u8 *a0 , s32 a1 );
signed int SFX_GetSeqParam(void *a0 , signed int a1 , signed int a2 , void *a3 , signed int t0 );
void __SFX_GetValue_float(void *a0 , void *a1 , signed int a2 );
void __SFX_GetValue_u_int(void *a0 , void *a1 , signed int a2 );
void __SFX_GetValue_int(void *a0 , void *a1 , signed int a2 );
void __SFX_GetValue_u_short(void *a0 , void *a1 , signed int a2 );
void __SFX_GetValue_short(void *a0 , void *a1 , signed int a2 );
void __SFX_GetValue_u_char(void *a0 , void *a1 , signed int a2 );
void __SFX_GetValue_char(void *a0 , void *a1 , signed int a2 );
float erp_linear(float f12 );
float erp_none(void);
float erp_ei(float f12 );
float erp_eo(float f12 );
float erp_sei(float f12 );
float erp_seo(float f12 );

s32 SFX_DataRemap(char *a0, void *a1, u32 a2) {
    u32 s6;
    s32 s7;
    u8 *s5;
    s32 s4;
    u32 s3;
    s32 s2;
    u8 *s1;
    s32 s0;
    u32 v1;
    u32 v0;
    struct RemapEntry { u32 first, second; } *entry;
    s7 = a2;
    s6 = (u32)a1;
    s5 = (u8 *)a0;
    s3 = -1;
    for (s4 = 0; s4 < s7; s4++) {
        v0 = *(s32 *)(s5 + 4);
        *(u32 *)(s5 + 4) = (s32)(s5 + v0);
        v0 = *(s32 *)(s5 + 8);
        *(u32 *)(s5 + 8) = (s32)(s5 + v0);
        v0 = *(u16 *)(s5 + 2);
        s2 = 0;
        if (0 < (s32)v0) {
            s0 = 0;
            do {
                v0 = *(s32 *)(s5 + 8);
                v1 = v0 + s0;
                v0 = *(s32 *)v1;
                *(u32 *)v1 = (s32)(s5 + v0);
                s1 = (u8 *)*(s32 *)((u8 *)*(s32 *)(s5 + 8) + s0);
                v0 = *(s32 *)(s1 + 4);
                if (v0 != 0) *(u32 *)(s1 + 4) = (s32)(s5 + v0);
                v0 = *(s32 *)(s1 + 8);
                if (v0 != 0) *(u32 *)(s1 + 8) = (s32)(s5 + v0);
                v0 = *(s32 *)(s1 + 0xc);
                if (v0 != 0) *(u32 *)(s1 + 0xc) = (s32)(s5 + v0);
                v0 = *(s32 *)(s1 + 0x14);
                if (v0 != 0) *(u32 *)(s1 + 0x14) = (s32)(s1 + v0);
                v0 = *(s32 *)(s1 + 0x1c);
                if (v0 != 0) *(u32 *)(s1 + 0x1c) = (s32)(s1 + v0);
                a1 = (void *)*(s32 *)(s5 + 4);
                a0 = (char *)(s1 + 0x24);
                strncpy(a0, (const char *)a1, 0x1a);
                v0 = *(u16 *)s5;
                *(u16 *)(s1 + 0x3e) = v0;
                v0 = *(s32 *)(s1 + 0x18);
                entry = (struct RemapEntry *)*(u32 *)(s1 + 0x1c);
                a0 = (char *)0;
                if (0 < (s32)v0) {
                    do {
                        v0 = entry->second;
                        if (v0 == 0) entry->second = 0;
                        else entry->second = (u32)(s1 + v0);
                        a0 = (char *)(a0 + 1);
                        entry++;
                    } while ((s32)a0 < *(s32 *)(s1 + 0x18));
                }
                v0 = *(u16 *)(s5 + 2);
                s2 = s2 + 1;
                v0 = s2 < (s32)v0;
                s0 = s0 + 4;
            } while (v0 != 0);
        }
        v1 = *(s32 *)(s5 + 8);
        v0 = *(u16 *)s5;
        v1 = *(s32 *)v1;
        *(u32 *)(s6 + (v0 << 2)) = v1;
        v0 = *(u16 *)s5;
        if ((s32)s3 < (s32)v0) s3 = v0;
        v1 = *(s32 *)(s5 + 0xc);
        s5 = (u8 *)(s5 + v1);
    }
    return s3;
}

/* __SFX_GetErpValue_float @ 0x1C6830 .. 0x1C68CC (0x9c bytes, frame 0x50) */



void __SFX_GetErpValue_float(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */, signed int a3
        /* r7 */, signed int t0 /* r8 */, float arg5 /* f12 */) {
    s32 v1;
    u32 *v0;
    float f2;
    float f1;
    float f0;

    v0 = erp_tab;
    v0 = (u32 *)((u8 *)erp_tab + (s32)((u32)t0 << 2));
    v0 = (u32 *)*(s32 *)v0;
    f0 = ((float (*)(void *, void *, void *, s32, s32))(s32)v0)(a0, a1, a2, a3, t0);
    v1 = a3;
    a3 = (u32)(a3) + -1;
    if ((u32)v1 != 0) {
        do {
            v1 = a3;
            f2 = *(float *)a1;
            a3 = (u32)(a3) + -1;
            a1 = (void *)((u8 *)a1 + 4);
            f1 = (*(float *)a2 - f2);
            a2 = (void *)((u8 *)a2 + 4);
            *(f32 *)a0 = (f2 + (f0 * f1));
            a0 = (void *)((u8 *)a0 + 4);
        } while ((u32)v1 != 0);
    }
    return;
}


/* __SFX_GetErpValue_u_int @ 0x1C66D0 .. 0x1C682C (0x15c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x4f000000 at 0x1c6724
 *   fpu: mtc1 reinterprets v1 at 0x1c6734
 *   fpu: mtc1 reinterprets a1 at 0x1c674c
 *   fpu: mtc1 reinterprets a2 at 0x1c6764
 *   fpu: mtc1 reinterprets a1 at 0x1c6778
 *   fpu: mtc1 reinterprets a2 at 0x1c6794
 *   fpu: mtc1 reinterprets a1 at 0x1c67ac
 */



void __SFX_GetErpValue_u_int(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */, signed int a3
        /* r7 */, signed int t0 /* r8 */, float arg5 /* f12 */) {
    u32 a2_after_call; // a2
    float f0;
    u32 v1;
    u32 *v0;

    v0 = erp_tab;
    v0 = (u32 *)((u8 *)erp_tab + (u32)((u32)t0 << 2));
    v0 = (u32 *)*(s32 *)v0;
    f0 = ((float (*)(void *, void *, void *, s32, s32))(s32)v0)(a0, a1, a2, a3, t0);
    if (a3-- != 0) {
        do {
            v1 = *(s32 *)a2;
            a2_after_call = *(s32 *)a1;
            *(u32 *)a0 = (u32)((float)(float)a2_after_call + (f0 * ((float)(float)v1 -
                (float)(float)a2_after_call)));
            a1 = (void *)((u8 *)a1 + 4);
            a0 = (void *)((u8 *)a0 + 4);
            a2 = (void *)((u8 *)a2 + 4);
        } while (a3-- != 0);
    }
    return;
}

/* __SFX_GetErpValue_int @ 0x1C6610 .. 0x1C66C4 (0xb4 bytes, frame 0x50) */

void __SFX_GetErpValue_int(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */, signed int a3
        /* r7 */, signed int t0 /* r8 */, float arg5 /* f12 */) {
    float f3;
    s32 f2;
    float f0;
    u32 *v0;
    s32 f1_word;

    v0 = erp_tab;
    v0 = (u32 *)(u32)&((struct { u8 b[4]; } *)erp_tab)[t0];
    v0 = (u32 *)*(s32 *)v0;
    f0 = ((float (*)(void *, void *, void *, s32, s32))(s32)v0)(a0, a1, a2, a3, t0);
    if (a3-- != 0) {
        do {
            f1_word = *(s32 *)a1;
            f3 = ((float)*(s32 *)a2);
            f2 = f1_word;
            a1 = (void *)((u8 *)a1 + 4);
            a2 = (void *)((u8 *)a2 + 4);
            *(u32 *)a0 = ((s32)((float)f2 + (f0 * (f3 - (float)f2))));
            a0 = (void *)((u8 *)a0 + 4);
        } while (a3-- != 0);
    }
    return;
}

/* __SFX_GetErpValue_u_short @ 0x1C64B0 .. 0x1C660C (0x15c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x4f000000 at 0x1c6504
 *   fpu: mtc1 reinterprets v1 at 0x1c6514
 *   fpu: mtc1 reinterprets a1 at 0x1c652c
 *   fpu: mtc1 reinterprets a2 at 0x1c6544
 *   fpu: mtc1 reinterprets a1 at 0x1c6558
 *   fpu: mtc1 reinterprets a2 at 0x1c6574
 *   fpu: mtc1 reinterprets a1 at 0x1c658c
 */



void __SFX_GetErpValue_u_short(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */, signed int
        a3 /* r7 */, signed int t0 /* r8 */, float arg5 /* f12 */) {
    u16 a2_after_call; // a2
    float f0;
    u32 v1;
    u32 *v0;

    v0 = erp_tab;
    v0 = (u32 *)((u8 *)erp_tab + (u32)((u32)t0 << 2));
    f0 = ((float (*)(void *, void *, void *, s32, s32))(s32)(u32 *)*(s32 *)v0)(a0, a1, a2, a3, t0);
    if (a3-- != 0) {
        do {
            v1 = *(u16 *)a2;
            a2_after_call = *(u16 *)a1;
            *(u16 *)a0 = (u32)((float)(float)(u32)a2_after_call + (f0 * ((float)(float)v1 -
                (float)(float)(u32)a2_after_call)));
            a1 = (void *)((u8 *)a1 + 2);
            a0 = (void *)((u8 *)a0 + 2);
            a2 = (void *)((u8 *)a2 + 2);
        } while (a3-- != 0);
    }
    return;
}

/* __SFX_GetErpValue_short @ 0x1C63F0 .. 0x1C64AC (0xbc bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets a1 at 0x1c6450
 *   fpu: mtc1 reinterprets a0 at 0x1c6458
 */

void __SFX_GetErpValue_short(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */, signed int a3
        /* r7 */, signed int t0 /* r8 */, float arg5 /* f12 */) {
    u32 a1_after_call; // a1
    s32 f2;
    u32 a0_after_call; // a0
    float f0;
    s32 v1;
    u32 *v0;

    v0 = erp_tab;
    v0 = (u32 *)((u8 *)erp_tab + (s32)((u32)t0 << 2));
    f0 = ((float (*)(void *, void *, void *, s32, s32))(s32)(u32 *)*(s32 *)v0)(a0, a1, a2, a3, t0);
    if (a3-- != 0) {
        do {
            a1_after_call = *(s16 *)a1;
            a0_after_call = *(s16 *)a2;
            a1 = (void *)((u8 *)a1 + 2);
            a2 = (void *)((u8 *)a2 + 2);
            f2 = ((s32)a1_after_call);
            *(u16 *)a0 = ((s32)(f2 + (f0 * ((float)((float)(s32)a0_after_call) - f2))));
            a0 = (void *)((u8 *)a0 + 2);
        } while (a3-- != 0);
    }
    return;
}

void __SFX_GetErpValue_u_char(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */, signed int
        a3 /* r7 */, signed int t0 /* r8 */, float arg5 /* f12 */) {
    u8 a2_after_call; // a2
    float f0;
    u32 v1;
    u32 *v0;

    v0 = erp_tab;
    v0 = (u32 *)((u8 *)erp_tab + (u32)((u32)t0 << 2));
    f0 = ((float (*)(void *, void *, void *, s32, s32))(s32)(u32 *)*(s32 *)v0)(a0, a1, a2, a3, t0);
    if (a3-- != 0) {
        do {
            v1 = *(u8 *)a2;
            a2_after_call = *(u8 *)a1;
            *(u8 *)a0 = (u32)((float)(float)(u32)a2_after_call + (f0 * ((float)(float)v1 -
                (float)(float)(u32)a2_after_call)));
            a1 = (void *)((u8 *)a1 + 1);
            a0 = (void *)((u8 *)a0 + 1);
            a2 = (void *)((u8 *)a2 + 1);
        } while (a3-- != 0);
    }
    return;
}

void __SFX_GetErpValue_char(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */, signed int a3
        /* r7 */, signed int t0 /* r8 */, float arg5 /* f12 */) {
    u32 a1_after_call; // a1
    s32 f2;
    u32 a0_after_call; // a0
    float f0;
    s32 v1;
    u32 *v0;

    v0 = erp_tab;
    v0 = (u32 *)((u8 *)erp_tab + (s32)((u32)t0 << 2));
    f0 = ((float (*)(void *, void *, void *, s32, s32))(s32)(u32 *)*(s32 *)v0)(a0, a1, a2, a3, t0);
    if (a3-- != 0) {
        do {
            a1_after_call = *(s8 *)a1;
            a0_after_call = *(s8 *)a2;
            a1 = (void *)((u8 *)a1 + 1);
            a2 = (void *)((u8 *)a2 + 1);
            f2 = ((s32)a1_after_call);
            *(u8 *)a0 = ((s32)(f2 + (f0 * ((float)((float)(s32)a0_after_call) - f2))));
            a0 = (void *)((u8 *)a0 + 1);
        } while (a3-- != 0);
    }
    return;
}

/* __SFX_ZeroValue_float @ 0x1C6190 .. 0x1C61C8 (0x38 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 __SFX_ZeroValue_float(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 v1;

    v1 = a1;
    a1 = v1 + -1;
    if (v1 != 0) {
        do {
            *(u32 *)a0 = 0;
            v1 = a1;
            a0 = (u32 *)((u8 *)a0 + 4);
            a1 = v1 + -1;
        } while (v1 != 0);
    }
    return;
}

/* __SFX_ZeroValue_u_int @ 0x1C6150 .. 0x1C6188 (0x38 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 __SFX_ZeroValue_u_int(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 v1;

    v1 = a1;
    a1 = v1 + -1;
    if (v1 != 0) {
        do {
            *(u32 *)a0 = 0;
            v1 = a1;
            a0 = (u32 *)((u8 *)a0 + 4);
            a1 = v1 + -1;
        } while (v1 != 0);
    }
    return;
}

/* __SFX_ZeroValue_int @ 0x1C6110 .. 0x1C6148 (0x38 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 __SFX_ZeroValue_int(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 v1;

    v1 = a1;
    a1 = v1 + -1;
    if (v1 != 0) {
        do {
            *(u32 *)a0 = 0;
            v1 = a1;
            a0 = (u32 *)((u8 *)a0 + 4);
            a1 = v1 + -1;
        } while (v1 != 0);
    }
    return;
}

/* __SFX_ZeroValue_u_short @ 0x1C60D0 .. 0x1C6108 (0x38 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 __SFX_ZeroValue_u_short(u16 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 v1;

    v1 = a1;
    a1 = v1 + -1;
    if (v1 != 0) {
        do {
            *(u16 *)a0 = 0;
            v1 = a1;
            a0 = (u16 *)((u8 *)a0 + 2);
            a1 = v1 + -1;
        } while (v1 != 0);
    }
    return;
}

/* __SFX_ZeroValue_short @ 0x1C6090 .. 0x1C60C8 (0x38 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 __SFX_ZeroValue_short(u16 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 v1;

    v1 = a1;
    a1 = v1 + -1;
    if (v1 != 0) {
        do {
            *(u16 *)a0 = 0;
            v1 = a1;
            a0 = (u16 *)((u8 *)a0 + 2);
            a1 = v1 + -1;
        } while (v1 != 0);
    }
    return;
}

/* __SFX_ZeroValue_u_char @ 0x1C6050 .. 0x1C6088 (0x38 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 __SFX_ZeroValue_u_char(u8 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 v1;

    v1 = a1;
    a1 = v1 + -1;
    if (v1 != 0) {
        do {
            *(u8 *)a0 = 0;
            v1 = a1;
            a0 = (u8 *)a0 + 1;
            a1 = v1 + -1;
        } while (v1 != 0);
    }
    return;
}


/* __SFX_ZeroValue_char @ 0x1C6010 .. 0x1C6048 (0x38 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 __SFX_ZeroValue_char(u8 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 v1;

    v1 = a1;
    a1 = v1 + -1;
    if (v1 != 0) {
        do {
            *(u8 *)a0 = 0;
            v1 = a1;
            a0 = (u8 *)a0 + 1;
            a1 = v1 + -1;
        } while (v1 != 0);
    }
    return;
}

signed int SFX_GetSeqParam(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */, void
        *a3 /* r7 */, signed int t0 /* r8 */) {
    void *output;
    s32 s5;
    s32 s4;
    u32 s3;
    float f20;
    u8 s2;
    s32 s1;
    u8 *s0;
    u32 v1;
    u32 v0;
    signed int a1_2;

    output = a0;
    s5 = a1;
    s4 = a2;
    s2 = 0;
    f20 = 0.0f;
    s1 = t0;
    if ((u32)a3 == 0) {
        v0 = (u32)zero_value_tab;
        v0 = (s32)(u32)&((struct { u8 b[4]; } *)zero_value_tab)[s5];
        v0 = *(s32 *)v0;
        ((void (*)(void *, s32))(s32)v0)(a0, s4);
        v0 = 0;
    } else {
        s3 = *(u16 *)(((u8 *)a3 + 2));
        s0 = (u8 *)a3;
        while (1) {
            s32 duration;
            if (s3 == 0) {
                break;
            }
            s0 = (u8 *)((u8 *)a3 + s3);
            duration = *(u16 *)(s0 + 4);
            if (duration > s1) {
                break;
            }
            s3 = *(u16 *)(s0 + 2);
            s1 = s1 - duration;
            a3 = (void *)s0;
        }
        v1 = *(u16 *)a3;
        v0 = 0x100;
        if (v1 == v0) {
            a1_2 = (s32)((u8 *)a3 + 0xc);
            v0 = (u32)get_value_tab;
            v0 = (s32)(u32)&((struct { u8 b[4]; } *)get_value_tab)[s5];
            a3 = (void *)*(u8 *)(((u8 *)a3 + 6));
            v0 = *(s32 *)v0;
            ((void (*)(s32, s32, s32, u8))(s32)v0)(0x70000000, a1_2, s4, (u8)(u32)a3);
        }
        v1 = *(u16 *)s0;
        v0 = 0x100;
        if (v1 == v0) {
            ((void (*)(u32, s32, s32, u8))get_value_tab[s5])(0x70000020, (s32)(s0 + 0xc), s4, *(u8 *)(s0 + 6));
            v0 = 1;
        } else {
            v0 = 0;
        }
        if (v0 != 0) {
            v0 = *(u16 *)(s0 + 4);
            s2 = *(u8 *)(s0 + 7);
            if (v0 == 0 || s3 == 0) {
                f20 = 0.0f;
            } else {
                f20 = ((float)((float)(s32)(u32)s1) / (float)(float)v0);
            }
        }
        v0 = (u32)erp_value_tab;
        v0 = (s32)(u32)&((struct { u8 b[4]; } *)erp_value_tab)[s5];
        a1_2 = 0x70000000;
        v0 = *(s32 *)v0;
        ((void (*)(u32, s32, u32, s32, u8, float))(s32)v0)((u32)output, 0x70000000, 0x70000000 | 0x20,
            s4, s2, (float)f20);
        v0 = 1;
        v0 = (u32)s1 == 0 ? (s32)v0 : (s32)-1;
    }
    return v0;
}

/* __SFX_GetValue_float @ 0x1C5DD0 .. 0x1C5E08 (0x38 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

void __SFX_GetValue_float(void *a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */) {
    s32 v1;
    float f0;

    v1 = (s32)a2;
    a2 = (s32)(v1 + -1);
    if ((u32)v1 != 0) {
        do {
            v1 = (s32)a2;
            f0 = *(float *)a1;
            a2 = (s32)(v1 + -1);
            *(f32 *)a0 = f0;
            a1 = (void *)(s32)((u8 *)a1 + 4);
            a0 = (void *)(s32)((u8 *)a0 + 4);
        } while ((u32)v1 != 0);
    }
    return;
}

/* __SFX_GetValue_u_int @ 0x1C5D90 .. 0x1C5DC8 (0x38 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

void __SFX_GetValue_u_int(void *a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */) {
    u32 a3;
    s32 v1;

    if (a2-- != 0) {
        do {
            a3 = *(s32 *)a1;
            *(u32 *)a0 = a3;
            a1 = (void *)((u8 *)a1 + 4);
            a0 = (void *)((u8 *)a0 + 4);
        } while (a2-- != 0);
    }
    return;
}

/* __SFX_GetValue_int @ 0x1C5D50 .. 0x1C5D88 (0x38 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

void __SFX_GetValue_int(void *a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */) {
    u32 a3;
    s32 v1;

    if (a2-- != 0) {
        do {
            a3 = *(s32 *)a1;
            *(u32 *)a0 = a3;
            a1 = (void *)((u8 *)a1 + 4);
            a0 = (void *)((u8 *)a0 + 4);
        } while (a2-- != 0);
    }
    return;
}

/* __SFX_GetValue_u_short @ 0x1C5D10 .. 0x1C5D48 (0x38 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

void __SFX_GetValue_u_short(void *a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */) {
    u32 a3;
    s32 v1;

    if (a2-- != 0) {
        do {
            a3 = *(u16 *)a1;
            *(u16 *)a0 = a3;
            a1 = (void *)((u8 *)a1 + 2);
            a0 = (void *)((u8 *)a0 + 2);
        } while (a2-- != 0);
    }
    return;
}

/* __SFX_GetValue_short @ 0x1C5CD0 .. 0x1C5D08 (0x38 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

void __SFX_GetValue_short(void *a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */) {
    s32 a3;
    s32 v1;

    if (a2-- != 0) {
        do {
            a3 = *(s16 *)a1;
            *(u16 *)a0 = a3;
            a1 = (void *)((u8 *)a1 + 2);
            a0 = (void *)((u8 *)a0 + 2);
        } while (a2-- != 0);
    }
    return;
}

/* __SFX_GetValue_u_char @ 0x1C5C90 .. 0x1C5CC8 (0x38 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

void __SFX_GetValue_u_char(void *a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */) {
    u32 a3;
    s32 v1;

    if (a2-- != 0) {
        do {
            a3 = *(u8 *)a1;
            *(u8 *)a0 = a3;
            a1 = (void *)((u8 *)a1 + 1);
            a0 = (void *)((u8 *)a0 + 1);
        } while (a2-- != 0);
    }
    return;
}

/* __SFX_GetValue_char @ 0x1C5C50 .. 0x1C5C88 (0x38 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

void __SFX_GetValue_char(void *a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */) {
    s32 a3;
    s32 v1;

    if (a2-- != 0) {
        do {
            a3 = *(s8 *)a1;
            *(u8 *)a0 = a3;
            a1 = (void *)((u8 *)a1 + 1);
            a0 = (void *)((u8 *)a0 + 1);
        } while (a2-- != 0);
    }
    return;
}

/* erp_linear @ 0x1C5C40 .. 0x1C5C48 (0x8 bytes) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1c5c44 is a float copy
 *   return: mov.s at 0x1c5c44 computes the return value
 */

float erp_linear(float f12 /* f12 */) {
    return (float)f12;
}

/* erp_none @ 0x1C5C30 .. 0x1C5C3C (0xc bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1c5c30
 */

float erp_none(void) {
    return 0.0f;
}

/* erp_ei @ 0x1C5C10 .. 0x1C5C28 (0x18 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40000000 at 0x1c5c14
 *   return: mul.s at 0x1c5c24 computes the return value
 */

float erp_ei(float f12 /* f12 */) {
    float f0;

    f0 = 2.0f;
    f0 = (2.0f - f12);
    return (f12 * f0);
}

/* erp_eo @ 0x1C5C00 .. 0x1C5C08 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: mul.s at 0x1c5c04 computes the return value
 */

float erp_eo(float f12 /* f12 */) {
    return (f12 * f12);
}

/* erp_sei @ 0x1C5BE0 .. 0x1C5C00 (0x20 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40400000 at 0x1c5be4
 *   return: mul.s at 0x1c5bfc computes the return value
 */

float erp_sei(float f12 /* f12 */) {
    return (f12 * (3.0f + (f12 * (f12 - 3.0f))));
}

/* erp_seo @ 0x1C5BD0 .. 0x1C5BDC (0xc bytes) */
/*
 * dcomp notes:
 *   return: mul.s at 0x1c5bd8 computes the return value
 */

float erp_seo(float f12 /* f12 */) {
    float f0;

    f0 = (f12 * f12);
    return (f12 * f0);
}
static u32 erp_tab[0x6] = {
    (u32)&erp_linear, (u32)&erp_none, (u32)&erp_ei, (u32)&erp_eo, (u32)&erp_sei, (u32)&erp_seo
};
static u32 erp_value_tab[0x7] = {
    (u32)&__SFX_GetErpValue_char, (u32)&__SFX_GetErpValue_u_char, (u32)&__SFX_GetErpValue_short,
    (u32)&__SFX_GetErpValue_u_short, (u32)&__SFX_GetErpValue_int, (u32)&__SFX_GetErpValue_u_int,
    (u32)&__SFX_GetErpValue_float
};
static u32 zero_value_tab[0x7] = {
    (u32)&__SFX_ZeroValue_char, (u32)&__SFX_ZeroValue_u_char, (u32)&__SFX_ZeroValue_short,
    (u32)&__SFX_ZeroValue_u_short, (u32)&__SFX_ZeroValue_int, (u32)&__SFX_ZeroValue_u_int,
    (u32)&__SFX_ZeroValue_float
};
static u32 get_value_tab[0x7] = {
    (u32)&__SFX_GetValue_char, (u32)&__SFX_GetValue_u_char, (u32)&__SFX_GetValue_short,
    (u32)&__SFX_GetValue_u_short, (u32)&__SFX_GetValue_int, (u32)&__SFX_GetValue_u_int,
    (u32)&__SFX_GetValue_float
};
