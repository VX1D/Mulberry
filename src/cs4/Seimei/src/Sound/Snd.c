#include "common.h"

/* SND_ReleaseBunk @ 0x1A9210 .. 0x1A923C (0x2c bytes, frame 0x10) */

extern void MemFree();
/* .sbss: tentative definitions are emitted in reverse order of first declaration -> memory order
 * s_pSec, g_pSndMng (16-aligned), g_SndProcCounter, ..Max, g_SndProcDcacheMiss, ..Max */
u32 g_SndProcDcacheMissMax;
u32 g_SndProcDcacheMiss;
u32 g_SndProcCounterMax;
u32 g_SndProcCounter;
u32 g_pSndMng __attribute__((aligned(16)));
static u32 s_pSec;
extern u32 s_pSec;

/* SND_GetListenerMatPtr @ 0x1A9240 .. 0x1A924C (0xc bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1a9248 computes the return value
 */

extern u32 g_pSndMng;

/* _TransBankData_EE2SPU @ 0x1A9250 .. 0x1A9270 (0x20 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdsynthAddBankFromEE2 at 0x1a9268 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern signed int fssdsynthAddBankFromEE2();

/* MakeBankInfo @ 0x1A9270 .. 0x1A9334 (0xc4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001A92D8
 */

extern void * memset(void *, int, unsigned int);

/* SND_LoadSecFromFileInMemory @ 0x1A9340 .. 0x1A95E8 (0x2a8 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x60 escapes at 0x1a936c
 *   delay: addiu at 0x1a93b0 writes a register its branch at 0x1a93ac reads
 *   delay: addiu at 0x1a943c writes a register its branch at 0x1a9438 reads
 *   stack: address of the slot at 0x74 escapes at 0x1a9448
 *   delay: addiu at 0x1a945c writes a register its branch at 0x1a9458 reads
 *   stack: address of the slot at 0x7c escapes at 0x1a9468
 *   call: _TransBankData_EE2SPU is declared void but its v0 is read: called as returning u32
 *   stack: address of the slot at 0x70 escapes at 0x1a94b8
 *   cfg: kept goto: 0x1a93a4 -> .L001A95C8
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int fssdsynthRemoveBank(signed int);
extern void * memcpy(void *, const void *, unsigned int);

#ifndef PROTO_SNDMNG_SM
#define PROTO_SNDMNG_SM
struct SndMngSM { u8 pad0[0x32]; u16 fade; u8 pad1[0x40 - 0x34]; s32 Handle[12]; u8 pad2[0x1974 - 0x70]; u16 tbl[16][128]; };
#endif

struct SecHd { u8 p0[8]; s32 o8; s32 oc; s32 o10; u8 p14[0x14]; s32 o28; s32 o2c; u8 p30[0x18]; s32 o48; };


extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);
u32 SoundManageData[0x95e];

static u32 pDmy_849[12];


extern void SND_VoiceOffSeKind(int);
extern void fssdsynthSeFlush(void);
extern signed int fssdsynthPortSoundOff(unsigned int);
extern signed int fssdsynthRemoveBank(signed int);


extern signed int fssdSetMasterVolume(signed int, unsigned short, unsigned short);
extern int sceGsSyncV(int);
extern void SND_SqStop(unsigned char);
extern void SND_VoiceOffAll();


extern void SND_SetReverbOff();

extern void SND_VoiceInitMng();

#ifndef PROTO_SNDMNG_SM
#define PROTO_SNDMNG_SM
struct SndMngSM { u8 pad0[0x32]; u16 fade; u8 pad1[0x40 - 0x34]; s32 Handle[12]; u8 pad2[0x1974 - 0x70]; u16 tbl[16][128]; };
#endif

static inline void ClearSec(int kind) {
    u32 j;
    for (j = (kind < 12 ? 0 : 0); j < 0x80; j++) {
        ((struct SndMngSM *)g_pSndMng)->tbl[kind][j] = 0xffff;
    }
    if ((u8)kind < 12) {
        s32 h = ((struct SndMngSM *)g_pSndMng)->Handle[(u8)kind];
        if (h >= 0 && h < 0x10) {
            fssdsynthRemoveBank(h);
            ((struct SndMngSM *)g_pSndMng)->Handle[kind] = -1;
        }
    }
}

extern void scePcStart(u32, u32, u32);
extern int fssdsynthSetMVolume(unsigned short);
extern void SND_SqManageProc();
extern void SND_VoiceProc();
extern void fssdsynthSeFlush();
extern void fssdsynthUpdateSeState();
extern void SND_ReverbProc();
extern void UpdateVagStm();
extern void scePcStop();
extern void fssdsynthUpdateVoiceInfo();
extern u32 g_SndProcCounter, g_SndProcCounterMax, g_SndProcDcacheMiss, g_SndProcDcacheMissMax;

/* SND_InitLoad @ 0x1A9CF0 .. 0x1A9D14 (0x24 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   literal: @1562 is the string 'sound\\kuon.segprj'
 */

extern signed int SND_LoadRandSeFromFile(char *);

extern void sceSdRemoteInit();
extern u32 fssdIsInited();
extern void fssdCleanup();
extern void fssdInit();
extern void fssdsynthInit();
extern void fssdsynthAddSpu2MemoryBlock(signed int, signed int, signed int);
extern void fssdsynthAssociateSpu2MemBlockIdWithPort(signed int, unsigned int);
extern signed int fssdsynthSetCoreAttr(unsigned short, unsigned short);

extern void SND_SqInit();

extern void SND_InitReverb();
extern void fssdsynthSystemStart();

extern void fssdsynthSetStereo();
extern void fssdsynthDefineSeStream(signed int, signed int);
extern u32 SoundManageData[];
extern u32 lpDrawMng;

#ifndef PROTO_SNDMNG_SM
#define PROTO_SNDMNG_SM
struct SndMngSM { u8 pad0[0x32]; u16 fade; u8 pad1[0x40 - 0x34]; s32 Handle[12]; u8 pad2[0x1974 - 0x70]; u16 tbl[16][128]; };
#endif
static inline void ClearTbl(u8 kind) {
    u32 j;
    for (j = (kind < 12 ? 0 : 0); j < 0x80; j++) {
        ((struct SndMngSM *)g_pSndMng)->tbl[kind][j] = 0xffff;
    }
}

static inline void SetListener(void *p0, void *p1, void *p2) {
    *(void **)g_pSndMng = p0;
    *(void **)(g_pSndMng + 4) = p1;
    *(void **)(g_pSndMng + 8) = p2;
}

static u32 s_pSec;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int SND_Init(void);
u32 SND_InitLoad(void);
void SND_RebootSpu2(void);
int SND_Update(void);
void SND_SetMode(u8 a0 );
void SND_RemoveSound(void);
void SND_RemoveSec(int kind);
void SND_SetVol(int type, unsigned char volume);
unsigned char SND_GetVol(int a0 );
signed int SND_LoadSecFromFile(int a0 , char *a1 );
signed int SND_LoadSecFromFileInMemory(int a0 , void *a1 );
static void MakeBankInfo(int a0 , u32 *a1 );
static void _TransBankData_EE2SPU(u8 *a0 );
u32 SND_GetListenerMatPtr(void);
void SND_ReleaseBunk(void);


signed int SND_Init(void) {
    s32 ii;
    u32 t0;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 v1;
    u32 a0;
    u32 v0;
    u32 s0;

    v0 = g_pSndMng;
    if (v0 != 0) {
        return -1;
    }
    v0 = (u32)SoundManageData;
    g_pSndMng = (u32)SoundManageData;
    a0 = g_pSndMng;
    memset((void *)a0, 0, 0x2578);
    sceSdRemoteInit();
    v0 = fssdIsInited();
    if (v0 != 0) {
        fssdCleanup();
    }
    fssdInit();
    fssdsynthInit();
    v0 = 0x1d0000;
    fssdsynthAddSpu2MemoryBlock(0, 0x5010, 0x1d0000 | 0xaf70);
    fssdsynthAddSpu2MemoryBlock(1, 0x1f0000, 0x9020);
    fssdsynthAssociateSpu2MemBlockIdWithPort(0, 0xffff);
    fssdsynthAssociateSpu2MemBlockIdWithPort(1, 0x20);
    fssdsynthSetCoreAttr(0xa, 0x800);
    ii = 0;
    do {
        ClearTbl((u8)ii);
        ii++;
    } while (ii < 12);
    SND_VoiceInitMng();
    SND_SqInit();
    v0 = g_pSndMng;
    a3 = 0x41a00000;
    a2 = 1;
    v1 = 0x3f800000;
    *(u32 *)((v0 + 0xc)) = 0x41a00000;
    v0 = g_pSndMng;
    *(u32 *)((v0 + 0x10)) = 0;
    v0 = g_pSndMng;
    *(u8 *)((v0 + 0x14)) = a2;
    v0 = g_pSndMng;
    *(u32 *)((v0 + 0x18)) = 0x3f800000;
    v0 = g_pSndMng;
    *(u8 *)((v0 + 0xb0)) = 0;
    v0 = g_pSndMng;
    *(u16 *)((v0 + 0x3c)) = 0;
    SND_SetVol(0, 0x7f);
    SND_SetVol(1, 0x7f);
    SND_SetVol(2, 0x7f);
    SND_SetVol(3, 0x7f);
    v1 = g_pSndMng;
    v0 = 0;
    a2 = 0;
    *(u16 *)((v1 + 0x32)) = 0x1e;
    a1 = -1;
    do {
        a0 = g_pSndMng;
        v0 = v0 + 8;
        v1 = v0 < (u32)4;
        *(u32 *)(((u32)(a0 + a2) + 0x40)) = a1;
        a0 = g_pSndMng;
        *(u32 *)(((u32)(a0 + a2) + 0x44)) = a1;
        a0 = g_pSndMng;
        *(u32 *)(((u32)(a0 + a2) + 0x48)) = a1;
        a0 = g_pSndMng;
        *(u32 *)(((u32)(a0 + a2) + 0x4c)) = a1;
        a0 = g_pSndMng;
        *(u32 *)(((u32)(a0 + a2) + 0x50)) = a1;
        a0 = g_pSndMng;
        *(u32 *)(((u32)(a0 + a2) + 0x54)) = a1;
        a0 = g_pSndMng;
        *(u32 *)(((u32)(a0 + a2) + 0x58)) = a1;
        a0 = g_pSndMng;
        *(u32 *)(((u32)(a0 + a2) + 0x5c)) = a1;
        a2 = a2 + 0x20;
    } while (v1 != 0);
    a2 = v0 << 2;
    if (v0 <= (u32)0xb) {
        a1 = -1;
        do {
            a0 = g_pSndMng;
            *(u32 *)(((u32)(a0 + a2) + 0x40)) = a1;
            v0 = v0 + 1;
            a2 = a2 + 4;
        } while (v0 < (u32)0xc);
    }
    v0 = g_pSndMng;
    a2 = 0x18c0;
    memset((void *)(u32)(v0 + 0xb4), 0, a2);
    SND_InitReverb();
    fssdsynthSystemStart();
    fssdsynthSetMVolume(0x3fff);
    fssdsynthSetStereo();
    s0 = 0;
    do {
        fssdsynthDefineSeStream(s0 + 4, 0);
        s0 = s0 + 1;
    } while (s0 < (u32)0xc);
    SND_SetMode(2);
    SetListener((void *)(lpDrawMng + 0x230), (void *)(lpDrawMng + 0x240), (void *)(lpDrawMng + 0x2f0));
    return 0;
}

u32 SND_InitLoad(void) {
    SND_LoadRandSeFromFile("sound\\kuon.segprj");
    return 0;
}


/* SND_RebootSpu2 @ 0x1A9CE0 .. 0x1A9CE8 (0x8 bytes) */

void SND_RebootSpu2(void) {
    return;
}
int SND_Update(void) {
    u32 value;
    {
        u32 flags = 0x30;
        flags |= 0x34000;
        scePcStart(flags | 0x80000000, 0, 0);
    }
    if (*(u8 *)(g_pSndMng + 0x2d) & 1) {
        fssdsynthSetMVolume(*(u8 *)(g_pSndMng + 0x2e) * 0x81);
        ((struct { unsigned char f:1; } *)(g_pSndMng + 0x2d))->f = 0;
    }
    SND_SqManageProc();
    *(u16 *)(g_pSndMng + 0x3c) = 0;
    SND_VoiceProc();
    fssdsynthSeFlush();
    fssdsynthUpdateSeState();
    SND_ReverbProc();
    UpdateVagStm();
    scePcStop();
    fssdsynthUpdateVoiceInfo();
    __asm__ volatile("mfpc %0, 0" : "=r"(value) : : "memory");
    g_SndProcCounter = value;
    if ((int)g_SndProcCounterMax < (int)g_SndProcCounter) g_SndProcCounterMax = g_SndProcCounter;
    __asm__ volatile("mfpc %0, 1" : "=r"(value) : : "memory");
    g_SndProcDcacheMiss = value;
    if ((int)g_SndProcDcacheMissMax < (int)g_SndProcDcacheMiss) g_SndProcDcacheMissMax = g_SndProcDcacheMiss;
    return 0;
}


/* SND_SetMode @ 0x1A9B90 .. 0x1A9BC8 (0x38 bytes) */
/*
 * dcomp notes:
 *   delay: slti at 0x1a9ba4 writes a register its branch at 0x1a9ba0 reads
 *   cfg: kept branch: 0x1a9b9c if (..) goto .L001A9BB0
 */

void SND_SetMode(u8 a0 /* r4 */) {
    s32 a1;
    u8 *v1;

    v1 = (u8 *)g_pSndMng;
    a1 = a0;
    if ((u32)(s32)v1 != 0) {
        if (0 > (s32)a1) {
            goto _L001A9BB0;
        }
        if ((s32)a1 > (s32)2) {
            _L001A9BB0:;
            return;
        }
        *(u8 *)(v1 + 0x2c) = a0;
    }
    return;
}

void SND_RemoveSound(void) {
    s32 i;
    u16 sVol;

    i = 0;
    if (0 < ((struct SndMngSM *)g_pSndMng)->fade) {
        do {
            sVol = (0x3fff / ((struct SndMngSM *)g_pSndMng)->fade) * (((struct SndMngSM *)g_pSndMng)->fade - i);
            fssdSetMasterVolume(0, sVol, sVol);
            fssdSetMasterVolume(1, sVol, sVol);
            sceGsSyncV(0);
            i++;
        } while (i < ((struct SndMngSM *)g_pSndMng)->fade);
    }
    i = 0;
    do {
        SND_SqStop(i);
        i++;
    } while (i <= 3);
    SND_VoiceOffAll();
    fssdsynthSeFlush();
    sceGsSyncV(0);
    i = 0;
    do {
        fssdsynthPortSoundOff(i + 4);
        i++;
    } while (i < 12);
    fssdsynthSeFlush();
    SND_SetReverbOff();
    i = 2;
    do {
        ClearSec((u8)i);
        i++;
    } while (i < 12);
    SND_VoiceInitMng();
    fssdSetMasterVolume(0, 0x3fff, 0x3fff);
    fssdSetMasterVolume(1, 0x3fff, 0x3fff);
}
void SND_RemoveSec(int kind) {
    __asm__ volatile(
        ".set noreorder\n"
        "jal SND_VoiceOffSeKind\n"
        "daddu $16,$4,$0\n"
        "jal fssdsynthSeFlush\n"
        "nop\n"
        "andi $2,$16,0xff\n"
        "jal fssdsynthPortSoundOff\n"
        "addiu $4,$2,4\n"
        "jal fssdsynthSeFlush\n"
        "nop\n"
        "andi $4,$16,0xff\n"
        "daddu $7,$0,$0\n"
        "daddu $5,$0,$0\n"
        "sll $6,$4,8\n"
        "ori $3,$0,0xffff\n"
        "nop\n"
        "lw $9,g_pSndMng\n"
        "addiu $7,$7,8\n"
        "sltiu $8,$7,0x78\n"
        "addu $9,$6,$9\n"
        "addu $9,$9,$5\n"
        "sh $3,0x1974($9)\n"
        "lw $9,g_pSndMng\n"
        "addu $9,$6,$9\n"
        "addu $9,$9,$5\n"
        "sh $3,0x1976($9)\n"
        "lw $9,g_pSndMng\n"
        "addu $9,$6,$9\n"
        "addu $9,$9,$5\n"
        "sh $3,0x1978($9)\n"
        "lw $9,g_pSndMng\n"
        "addu $9,$6,$9\n"
        "addu $9,$9,$5\n"
        "sh $3,0x197a($9)\n"
        "lw $9,g_pSndMng\n"
        "addu $9,$6,$9\n"
        "addu $9,$9,$5\n"
        "sh $3,0x197c($9)\n"
        "lw $9,g_pSndMng\n"
        "addu $9,$6,$9\n"
        "addu $9,$9,$5\n"
        "sh $3,0x197e($9)\n"
        "lw $9,g_pSndMng\n"
        "addu $9,$6,$9\n"
        "addu $9,$9,$5\n"
        "sh $3,0x1980($9)\n"
        "lw $9,g_pSndMng\n"
        "addu $9,$6,$9\n"
        "addu $9,$9,$5\n"
        "sh $3,0x1982($9)\n"
        ".word 0x1500ffdd\n"
        "addiu $5,$5,0x10\n"
        ".word 0x2ce10080\n"
        ".word 0x1020000a\n"
        "sll $9,$7,1\n"
        "ori $8,$0,0xffff\n"
        "lw $5,g_pSndMng\n"
        "addiu $7,$7,1\n"
        "sltiu $3,$7,0x80\n"
        "addu $5,$6,$5\n"
        "addu $5,$5,$9\n"
        "sh $8,0x1974($5)\n"
        ".word 0x1460fff9\n"
        "addiu $9,$9,2\n"
        "andi $3,$16,0xff\n"
        "slti $1,$3,0xc\n"
        ".word 0x1020000f\n"
        "nop\n"
        "lw $3,g_pSndMng\n"
        "sll $16,$4,2\n"
        "addu $3,$16,$3\n"
        "lw $4,0x40($3)\n"
        ".word 0x04800009\n"
        "slti $1,$4,0x10\n"
        ".word 0x10200007\n"
        "nop\n"
        "jal fssdsynthRemoveBank\n"
        "nop\n"
        "lw $3,g_pSndMng\n"
        "addiu $4,$0,-1\n"
        "addu $3,$16,$3\n"
        "sw $4,0x40($3)\n"
        ".set reorder\n"
        :
        :
        : "memory");
}


void SND_SetVol(int type, unsigned char volume) {
    u8 *mng = (u8 *)g_pSndMng;
    if (mng) {
        if ((s32)(u8)volume < 0) volume = 0;
        if ((s32)(u8)volume > 127) volume = 127;
        switch ((u8)type) {
        case 0:
            mng[0x2e] = volume;
            ((struct { unsigned char f:1; } *)((u8 *)g_pSndMng + 0x2d))->f = 1;
            break;
        case 1: mng[0x2f] = volume; break;
        case 2: mng[0x30] = volume; break;
        case 3: mng[0x31] = volume; break;
        }
    }
}


unsigned char SND_GetVol(int a0 /* r4 */) {
    unsigned char ucVolume = 0x7f;

    if (g_pSndMng == 0) {
        return 0x7f;
    }
    switch ((u8)a0) {
    case 0:
        ucVolume = *(u8 *)((u8 *)g_pSndMng + 0x2e);
        break;
    case 1:
        ucVolume = *(u8 *)((u8 *)g_pSndMng + 0x2f);
        break;
    case 2:
        ucVolume = *(u8 *)((u8 *)g_pSndMng + 0x30);
        break;
    case 3:
        ucVolume = *(u8 *)((u8 *)g_pSndMng + 0x31);
        break;
    }
    return ucVolume;
}

signed int SND_LoadSecFromFile(int a0 /* r4 */, char *a1 /* r5 */) {
    u8 t0;
    u32 *a2;
    u32 v1;
    u32 v0;

    if ((u32)a1 == 0) {
        v0 = -1;
        goto _L001A9678;
    }
    t0 = a0;
    v0 = (s32)t0 < (s32)0xc;
    if (v0 == 0) {
        v0 = -1;
        goto _L001A9678;
    }
    v1 = g_pSndMng;
    a0 = (u32)t0 << 2;
    v0 = -1;
    v1 = (u32)(a0) + (u32)v1;
    v1 = *(s32 *)((v1 + 0x40));
    if (v1 != v0) {
        return v0;
    }
    v1 = (u32)&pDmy_849;
    a2 = (u32 *)((u8 *)&pDmy_849 + a0);
    a0 = (int)a1;
    *(u32 *)a2 = v0;
    a1 = (char *)(s32)v0;
    FileRead((char *)a0, (signed int)a1, (unsigned char **)a2, 0, t0, 0x16, 0x40);
    v0 = 0;
_L001A9678:
    return v0;
}

signed int SND_LoadSecFromFileInMemory(int a0 /* r4 */, void *a1 /* r5 */) {
    extern u32 _TransBankData_EE2SPU(u8 *);
    u8 kind;
    u32 xt1;
    struct SecHd *sec;
    s32 h;
    u8 hdr[32] __attribute__((aligned(16))) = {0};

    kind = a0;
    s_pSec = (u32)a1;
    hdr[0] = (u32)kind + 4;
    sec = (struct SecHd *)a1;
    if (((u8 *)a1) == 0) {
        return -1;
    }
    if (kind >= 12) {
        return -1;
    }
    if (((u8 *)(s32)sec) == 0) {
        return -1;
    }
    xt1 = g_pSndMng;
    h = (*(struct SndMngSM **)&g_pSndMng)->Handle[kind];
    if (h >= 0 && h <= 0xf && 0xb >= kind && h >= 0 && 0xf >= h) {
        fssdsynthRemoveBank((s32)h);
        ((*(struct SndMngSM **)&g_pSndMng))->Handle[(u32)kind] = -1;
    }
    ((u32 *)hdr)[5] = sec->o28;
    if (((s32 *)hdr)[5] == 0) {
        return -1;
    }
    ((u32 *)hdr)[7] = sec->o2c;
    if (((s32 *)hdr)[7] == 0) {
        return -1;
    }
    ((u32 *)hdr)[4] = (u32)(((u8 *)(s32)sec) + sec->o8);
    ((u32 *)hdr)[6] = (u32)(((u8 *)(s32)sec) + sec->oc);
    ((*(struct SndMngSM **)&g_pSndMng))->Handle[kind] = _TransBankData_EE2SPU(hdr);
    if (((*(struct SndMngSM **)&g_pSndMng))->Handle[kind] < 0) {
        return -1;
    }
    MakeBankInfo(a0, (u32 *)((u32 *)hdr)[4]);
    for (xt1 = (kind < 12 ? 0 : 0); xt1 < 0x80; xt1++) {
        ((*(struct SndMngSM **)&g_pSndMng))->tbl[kind][xt1] = 0xffff;
    }
    if (((u8 *)(s32)sec) + sec->o10 != 0) {
        xt1 = (u32)((u8 *)(s32)sec);
        memcpy(&((*(struct SndMngSM **)&g_pSndMng))->tbl[kind][0], ((u8 *)(s32)sec) + sec->o10, sec->o48 << 1);
    }
    return 0;
}

static void MakeBankInfo(int a0 /* r4 */, u32 *a1 /* r5 */) {
    u32 a0_word = (u8)a0;
    u8 *s0;
    u8 *t1;
    u8 *t0;
    s32 a3;
    u8 *s1;
    u32 a2;
    u32 v1;

    v1 = g_pSndMng;
    s0 = (u8 *)a1;
    a1 = (u32 *)(u8)a0_word;
    a0_word = (u32)a1 << 5;
    s1 = (u8 *)(s32)((u32)(v1 + (u32)((u32)(s32)((u8 *)a0_word + (u32)(a1)) << 4)) + 0xb4);
    if ((u32)s0 != 0) {
        a2 = 0x210;
        memset((void *)(u32)(s32)s1, 0, a2);
        v1 = *(s32 *)(s0 + 0x30);
        a3 = 0;
        t0 = (u8 *)(s1 + 0x10);
        t1 = (u8 *)(s0 + v1);
        v1 = *(s32 *)(t1 + 0xc);
        a1 = (u32 *)t1;
        *(u32 *)s1 = v1;
        a0_word = 1;
        do {
            v1 = *(s32 *)(((u8 *)a1 + 0x10));
            a2 = (s32)(t1 + v1);
            v1 = *(u16 *)((a2 + 4));
            *(u16 *)t0 = v1;
            v1 = *(u8 *)((a2 + 6));
            if (v1 == 0) {
                *(u8 *)(t0 + 2) = 0;
            } else {
                *(u8 *)(t0 + 2) = a0_word;
            }
            v1 = *(s32 *)(t1 + 0xc);
            a3 = a3 + 1;
            a1 = (u32 *)((u8 *)a1 + 4);
            t0 = (u8 *)(t0 + 4);
        } while ((u32)a3 <= v1);
    }
    return;
}

static void _TransBankData_EE2SPU(u8 *a0 /* r4 */) {
    u32 v0;
    s8 t1;
    u32 a1;
    u32 a2;
    u32 a3;
    u32 t0;

    v0 = (u32)a0;
    t1 = *(s8 *)((v0 + 1));
    a1 = *(u32 *)((v0 + 0x10));
    a2 = *(u32 *)((v0 + 0x14));
    a3 = *(u32 *)((v0 + 0x18));
    t0 = *(u32 *)((v0 + 0x1c));
    a0 = (u8 *)*(s8 *)a0;
    fssdsynthAddBankFromEE2(a0, a1, a2, a3, t0, t1);
    return;
}

u32 SND_GetListenerMatPtr(void) {
    u32 *v0;

    v0 = (u32 *)g_pSndMng;
    return *(u32 *)(((u8 *)v0 + 8));
}

void SND_ReleaseBunk(void) {
    u32 a0;

    a0 = s_pSec;
    if (a0 != 0) {
        MemFree(a0);
        s_pSec = 0;
    }
    return;
}
