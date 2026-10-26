#include "common.h"

/* StmReadErrCallBack @ 0x19DF10 .. 0x19E004 (0xf4 bytes, frame 0x10) */

extern signed int SetVagStmFade(unsigned char, unsigned char, signed int);

/* StmReadEndCallBack @ 0x19E010 .. 0x19E03C (0x2c bytes, frame 0x20) */

extern u32 fsmfstrm_FreeStreamBuffer();
extern u32 fsmfstrm_DetachFileSector();

/* InitMultiStm @ 0x19E040 .. 0x19E158 (0x118 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x3c escapes at 0x19e05c
 *   stack: address of the slot at 0x3c escapes at 0x19e104
 *   stack: address of the slot at 0x3c escapes at 0x19e12c
 */

extern void * memset(void *, int, unsigned int);
extern void fsmfstrm_Init();
extern void fsmfstrm_ThreadInit(u32 *, s32, s32);
extern void fsmfstrm_DmaInit();
extern void fsmfstrm_AllocDmaBuffer(u32);
extern void fsmfstrm_SetReadEndCallBack(void *);
extern void fsmfstrm_SetReadErrorCallBack(void *);
extern void fsmfstrm_SetReadPacketSize(s32);
extern u32 fsmfstrm_AllocStream(s32);
extern void fsmfstrm_SetReloadSize();
extern void fsmfstrm_SetCdRMode(s32, u8 *);
extern u32 StmMng[];
extern u32 StmThreadBuf[];


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void InitMultiStm(void);
static void StmReadEndCallBack(s32 a0 );
static void StmReadErrCallBack(signed int a0 , signed int a1 );


void InitMultiStm(void) {
    u32 a0;
    u32 v0;
    s32 s1;
    u32 *s0;
    u8 stackFrame_3C[4] __attribute__((aligned(4))) = {0};

    a0 = (u32)StmMng;
    memset((void *)StmMng, 0, 0x1c);
    fsmfstrm_Init();
    a0 = (u32)StmThreadBuf;
    fsmfstrm_ThreadInit(StmThreadBuf, 0x800, 0x30);
    fsmfstrm_DmaInit();
    fsmfstrm_AllocDmaBuffer(0x8000);
    a0 = (u32)StmReadEndCallBack;
    fsmfstrm_SetReadEndCallBack(StmReadEndCallBack);
    a0 = (u32)StmReadErrCallBack;
    fsmfstrm_SetReadErrorCallBack(StmReadErrCallBack);
    fsmfstrm_SetReadPacketSize(0x10000);
    s1 = 0;
    s0 = StmMng;
    do {
        v0 = fsmfstrm_AllocStream(0x10000);
        *(u32 *)s0 = v0;
        a0 = *(s32 *)s0;
        fsmfstrm_SetReloadSize(a0, 0x8000);
        a0 = *(s32 *)s0;
        fsmfstrm_SetCdRMode(a0, (u8 *)((u8 *)&stackFrame_3C[0]));
        s1 = s1 + 1;
        v0 = s1 < (s32)7;
        s0 = (u32 *)(u8 *)(s0 + 1);
    } while (v0 != 0);
    a0 = *(s32 *)StmMng;
    ((u8 *)stackFrame_3C)[1] = 1;
    fsmfstrm_SetCdRMode(a0, (u8 *)((u8 *)&stackFrame_3C[0]));
    a0 = *(s32 *)StmMng;
    fsmfstrm_SetReloadSize(a0, 0x10000);
    return;
}

static void StmReadEndCallBack(s32 a0 /* r4 */) {
    u32 s0;

    s0 = a0;
    fsmfstrm_FreeStreamBuffer(a0);
    a0 = s0;
    fsmfstrm_DetachFileSector(a0);
    return;
}

static void StmReadErrCallBack(signed int a0 /* r4 */, signed int a1 /* r5 */) {
    if ((s32)a0 > 0) {
        if ((s32)a0 < (s32)7) {
            a0 = 0;
            if ((u32)(s32)a1 == (u32)0x31) {
                SetVagStmFade(0, 5, 0xa);
                SetVagStmFade(1, 5, 0xa);
                SetVagStmFade(2, 5, 0xa);
                SetVagStmFade(3, 5, 0xa);
                SetVagStmFade(4, 5, 0xa);
                a0 = 5;
                SetVagStmFade(a0, a0, 0xa);
            } else {
                SetVagStmFade(0, 4, 0x3c);
                SetVagStmFade(1, 4, 0x3c);
                SetVagStmFade(2, 4, 0x3c);
                SetVagStmFade(3, 4, 0x3c);
                a0 = 4;
                SetVagStmFade(a0, a0, 0x3c);
                SetVagStmFade(5, 4, 0x3c);
            }
        }
    }
    return;
}
static u32 StmMng[0x7];
static u32 StmThreadBuf[0x200];
