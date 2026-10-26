#include "common.h"

/* MsgFileMng_GetMsgStr @ 0x19BB70 .. 0x19BC18 (0xa8 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0019BBA8
 *   cfg: kept branch: 0x19bba8 if (..) goto .L0019BBD0
 *   declaration vs inferred signature: return unsigned short * vs inferred u32
 */

extern signed int FsMsgGet(unsigned short **, void *, signed int);

/* MsgFileMng_ReadMsgFile @ 0x19BCE0 .. 0x19BDC8 (0xe8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: daddu at 0x19bd14 writes a register its branch at 0x19bd10 reads
 *   cfg: kept branch: 0x19bcf0 if (..) goto .L0019BD08
 *   cfg: kept goto: 0x19bd04 -> .L0019BDB0
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void MemFree(void *);
extern signed int ReadFile(unsigned char **, char *, signed int);

/* MsgFileMng_Delete @ 0x19BDD0 .. 0x19BDFC (0x2c bytes, frame 0x20) */

extern u32 MsgFileMng_Free();

/* MsgFileMng_Free @ 0x19BE00 .. 0x19BEC0 (0xc0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x19be28 if (..) goto .L0019BEA8
 *   declaration vs inferred signature: return u32 vs inferred void; 0 parameters vs 1 inferred
 *   return without a value in a non-void function
 */

extern void * GetTexMngByID(unsigned short);

/* MsgFileMng_Alloc @ 0x19BEC0 .. 0x19BFE0 (0x120 bytes, frame 0x120) */
/*
 * dcomp notes:
 *   quad: v1: 128-bit web split from its scalar uses
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: __FUNCTION__$681 is the string 'MsgFileMng_Alloc'
 *   literal: @892 is the string ''
 *   literal: @687 -> 0x22c680
 *   stack: address of the slot at 0x20 escapes at 0x19bf10
 *   stack: address of the slot at 0x20 escapes at 0x19bf48
 *   stack: address of the slot at 0x20 escapes at 0x19bf5c
 *   literal: @687 initializes the 256-byte local at 0x20
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void * MemAllocReal(unsigned int, char *, char *);
extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);
extern void SetTm2Data(void *, void *, char *);
extern void * GetTexMngByBaseName(void *, char *);

/* MsgFileMng_Init @ 0x19BFE0 .. 0x19C06C (0x8c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int MngState_Init(void *);
static signed int MsgFileMng_Alloc(void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int MsgFileMng_Init(void *a0 , unsigned int a1 );
static signed int MsgFileMng_Alloc(void *a0 );
u32 MsgFileMng_Free(u32 *a0);
u32 MsgFileMng_Delete(u32 *a0 );
signed int MsgFileMng_ReadMsgFile(void *a0 , unsigned int a1 , char *a2 );
signed int MsgFileMng_GetMsgData(void *a0 , unsigned short **a1 , signed int a2 );
unsigned short * MsgFileMng_GetMsgStr(void *a0 , signed int a1 );
u32 MsgFileMng_GetTexId(u32 *a0 );


signed int MsgFileMng_Init(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u32 *s1;
    s32 s0;
    void *a0_2; // a0
    s32 v1;
    s32 v0;

    s0 = a1;
    s1 = (u32 *)a0;
    if ((u32)s0 == 0) {
        v0 = 0;
    } else {
        MngState_Init(a0);
        s1[8] = s0;
        s1[0xb] = -1;
        v0 = MsgFileMng_Alloc((void *)(u32 *)s1);
        v1 = 1;
        a0_2 = (void *)s1;
        if ((u32)v0 != (u32)v1) {
            MsgFileMng_Free((u32 *)a0_2);
            *(u32 *)s1 = 0;
            v0 = 0;
        } else {
            v0 = v1;
            *(u32 *)s1 = 2;
        }
    }
    return v0;
}

static signed int MsgFileMng_Alloc(void *a0 /* r4 */) {
    u8 *a2;
    u32 a1;
    void *a0_s0; // a0
    u32 a0_s0_index; // a0
    s32 v1;
    u32 v0;
    u8 *a0_bytes; // s0

    a0_bytes = (u8 *)a0;
    MsgFileMng_Free((u32 *)a0_bytes);
    v0 = *(s32 *)(a0_bytes + 0x20);
    a1 = (u32)((char *)__FUNCTION__);
    a2 = (u8 *)"";
    a0_s0_index = v0 << 2;
    v0 = (u32)MemAllocReal(a0_s0_index, ((char *)__FUNCTION__), "");
    *(u32 *)(a0_bytes + 0x24) = v0;
    if (v0 == 0) {
        v0 = 0;
    } else {
        {
            struct stackFrame_20 { u8 b[256]; } stackFrame_20 __attribute__((aligned(16))) =
                {{0x6d, 0x73, 0x67, 0x5c, 0x66, 0x65, 0x5f, 0x69, 0x6e, 0x5f, 0x30, 0x30, 0x30,
                0x30, 0x2e, 0x74, 0x6d, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00}};
            a1 = -1;
            FileRead((char *)((u8 *)&stackFrame_20), a1, (unsigned char **)(u8 *)(a0_bytes + 0x28),
                1, a1, (signed
    int)0x14, 0);
            a1 = *(s32 *)(a0_bytes + 0x28);
            a0_s0 = (void *)0;
            if (a1 != 0) {
                SetTm2Data((void *)0, (void *)a1, (char *)(u8 *)((u8 *)&stackFrame_20));
                v0 = (u32)GetTexMngByBaseName((void *)0, (char *)((u8 *)&stackFrame_20));
                if (v0 != 0) {
                    v0 = *(u16 *)(((u8 *)v0 + 2));
                    *(u32 *)(a0_bytes + 0x2c) = v0;
                } else {
                    *(u32 *)(a0_bytes + 0x2c) = -1;
                }
            }
            v0 = *(s32 *)(a0_bytes + 0x20);
            a0_s0 = (void *)0;
            if ((u8 *)0 < (u8 *)v0) {
                v1 = 0;
                do {
                    v0 = *(s32 *)(a0_bytes + 0x24);
                    a0_s0 = (void *)((u8 *)a0_s0 + 1);
                    *(u32 *)(u32)(v0 + v1) = 0;
                    v0 = *(s32 *)(a0_bytes + 0x20);
                    v0 = (u32)(s32)a0_s0 < v0;
                    v1 = v1 + 4;
                } while (v0 != 0);
            }
            v0 = 1;
        }
    }
    return v0;
}

u32 MsgFileMng_Free(u32 *a0) {
    u8 *s2;
    u32 v1;
    u32 v0;
    s32 s1;

    v0 = -1;
    v1 = (s32)a0[0xb];
    s2 = (u8 *)a0;
    if (v1 != v0) {
        a0 = (u32 *)(u16)v1;
        v0 = (u32)GetTexMngByID((unsigned short)a0);
        if (v0 == 0) {
            goto _L0019BEA8;
        }
        *(u8 *)v0 = 0;
        a0 = (u32 *)*(s32 *)(s2 + 0x28);
        MemFree((void *)a0);
        *(u32 *)(s2 + 0x28) = 0;
    }
    v0 = *(s32 *)(s2 + 0x24);
    if (v0 != 0) {
        s1 = 0;
        for (; (u32)s1 < (u32)*(s32 *)(s2 + 0x20); s1 = s1 + 1) {
            a0 = (u32 *)*(s32 *)(s32)(*(s32 *)(s2 + 0x24) + s1 * 4);
            MemFree((void *)a0);
            v0 = *(s32 *)(s2 + 0x24) + s1 * 4;
            *(u32 *)v0 = 0;
        }
    }
    a0 = (u32 *)*(s32 *)(s2 + 0x24);
    MemFree((void *)a0);
    *(u32 *)(s2 + 0x24) = 0;
    _L0019BEA8:;
    return;
}

u32 MsgFileMng_Delete(u32 *a0 /* r4 */) {
    MsgFileMng_Free(a0);
    *(u32 *)a0 = 0;
    return 1;
}

signed int MsgFileMng_ReadMsgFile(void *a0 /* r4 */, unsigned int a1 /* r5 */, char *a2 /* r6 */) {
    u8 *s2;
    u32 s1;
    s32 s0;
    char *a2_2; // a2
    unsigned int a1_2; // a1
    u32 v1;
    u32 v0;

    s2 = (u8 *)a0;
    s1 = (u32)a2;
    if ((u32)s2 != 0) {
        goto _L0019BD08;
    }
    v0 = 0;
    goto _L0019BDB0;
    _L0019BD08:;
    v0 = (u32)(s32)a1 < (u32)*(s32 *)(s2 + 0x20);
    if (v0 == 0) {
        v0 = 0;
        return v0;
    }
    if (s1 == 0) {
        s0 = (u32)a1 << 2;
        a0 = (void *)*(s32 *)(s32)(*(s32 *)(s2 + 0x24) + s0);
        MemFree(a0);
        v1 = *(s32 *)(s2 + 0x24);
        v0 = 1;
        v1 = v1 + s0;
        *(u32 *)v1 = 0;
    } else {
        s0 = (u32)a1 << 2;
        a0 = (void *)*(s32 *)(s32)(*(s32 *)(s2 + 0x24) + s0);
        if ((u32)(s32)a0 != 0) {
            MemFree(a0);
            *(u32 *)(s32)(*(s32 *)(s2 + 0x24) + s0) = 0;
        }
        a1_2 = s1;
        a2_2 = (char *)(s32)0xe;
        a0 = (void *)(s32)(*(s32 *)(s2 + 0x24) + s0);
        v0 = ReadFile((unsigned char **)a0, (char *)a1_2, (signed int)a2_2);
        if (v0 == 0) {
            v0 = 0;
        } else {
            v0 = 1;
        }
    }
    _L0019BDB0:;
    return v0;
}

/* MsgFileMng_GetMsgData @ 0x19BC20 .. 0x19BCD8 (0xb8 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0019BC68
 *   cfg: kept branch: 0x19bc68 if (..) goto .L0019BC90
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int MsgFileMng_GetMsgData(void *a0 /* r4 */, unsigned short **a1 /* r5 */, signed int a2 /*
        r6 */) {
    u8 *s4;
    u32 s3;
    s32 s2;
    s32 s1;
    s32 s0;
    u32 v0;

    s4 = (u8 *)a0;
    s3 = (u32)a1;
    if ((u32)s4 == 0) {
        v0 = 0;
    } else {
        v0 = *(s32 *)(s4 + 0x20);
        s2 = 0;
        if ((u8 *)0 < (u8 *)v0) {
            s0 = a2;
            s1 = 0;
            do {
                v0 = *(s32 *)(s4 + 0x24);
                v0 = v0 + s1;
                a1 = (unsigned short **)*(s32 *)v0;
                if ((u32)(s32)a1 == 0) {
                    goto _L0019BC90;
                }
                a0 = (void *)s3;
                a2 = s0;
                v0 = FsMsgGet((unsigned short **)a0, (void *)a1, a2);
                if ((s32)v0 >= 0) {
                    break;
                }
                _L0019BC90:;
                v0 = *(s32 *)(s4 + 0x20);
                s2 = s2 + 1;
                v0 = (u32)s2 < v0;
                s1 = s1 + 4;
            } while (v0 != 0);
        }
        v0 = *(s32 *)(s4 + 0x20);
        v0 = (u32)(s2 ^ v0) != 0;
    }
    return v0;
}

unsigned short * MsgFileMng_GetMsgStr(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u32 *s3;
    s32 s2;
    s32 s1;
    s32 s0;
    u32 v0;
    u8 stackFrame_5C[4] __attribute__((aligned(4)));

    s3 = (u32 *)a0;
    v0 = *(s32 *)(((u8 *)a0 + 0x20));
    s2 = 0;
    if ((u8 *)0 < (u8 *)v0) {
        s0 = a1;
        s1 = 0;
        do {
            v0 = (s32)s3[9];
            v0 = v0 + s1;
            a1 = *(s32 *)v0;
            if ((u32)(s32)a1 == 0) {
                goto _L0019BBD0;
            }
            v0 = FsMsgGet((unsigned short **)((u8 *)&stackFrame_5C[0]), (void *)a1, s0);
            if ((s32)v0 >= 0) {
                break;
            }
            _L0019BBD0:;
            v0 = (s32)s3[8];
            s2 = s2 + 1;
            v0 = (u32)s2 < v0;
            s1 = s1 + 4;
        } while (v0 != 0);
    }
    v0 = (s32)s3[8];
    if ((u32)s2 == v0) {
        *(u32 *)((u8 *)&stackFrame_5C[0]) = 0;
    }
    v0 = *(s32 *)((u8 *)&stackFrame_5C[0]);
    return (unsigned short *)v0;
}

/* MsgFileMng_GetTexId @ 0x19BB60 .. 0x19BB68 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x19bb64 computes the return value
 */

u32 MsgFileMng_GetTexId(u32 *a0 /* r4 */) {
    return *(u32 *)(((u8 *)a0 + 0x2c));
}
