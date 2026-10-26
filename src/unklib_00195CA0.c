#include "common.h"

u32 g_MPG_MAX_WIDTH;
u32 g_MPG_MAX_HEIGHT;
u16 g_MPG_DISP_WIDTH[2];
u16 g_MPG_DISP_HEIGHT[2];
static u32 s_pfVSyncCallback;
static u32 s_pfCallback;
static u32 s_isInit;
static u32 s_pMpgMng;
volatile u32 g_mpg_vblankCount;
u32 g_mpg_oddeven;
static u32 handler_error;
static u32 isFrameEnd;
static volatile u32 isCountVblank;

typedef struct {
    u8 pad[0x50];
    u8 *buf;   /* 0x50 */
    int pos;   /* 0x54 */
} AudioDecAC3;

/* _sendToIOP2areaAC3 @ 0x195CA0 .. 0x1964F8 (0x858 bytes, frame 0x160)
 * AC3 variant of ezmpeg audiodec.c sendToIOP2area: each 512-byte source
 * chunk is staged into ad->buf followed by 512 zero bytes, then the staged
 * buffer is DMAed to the two IOP areas. */

extern void *memcpy();
extern void *memset(void *, int, unsigned int);
extern void FlushCache(int);
extern unsigned int sceSifSetDma(void *, int);
extern int sceSifDmaStat(unsigned int);

typedef struct {
    unsigned int a3data;
    unsigned int a3addr;
    unsigned int a3size;
    unsigned int a3mode;
} AC3SifDmaData;

static inline void sendToIOPAC3(int dst, u8 *src, int size)
{
    AC3SifDmaData transData;
    int did;

    if (size <= 0) {
        return;
    }
    transData.a3data = (unsigned int)src;
    transData.a3addr = (unsigned int)dst;
    transData.a3size = size;
    transData.a3mode = 0;
    FlushCache(0);
    did = sceSifSetDma(&transData, 1);
    while (sceSifDmaStat(did) >= 0)
        ;
}

static inline void copyAC3(AudioDecAC3 *ad, u8 *src, int size)
{
    int i;
    int n = size / 1024;

    for (i = 0; i < n; i++) {
        memcpy(ad->buf + ad->pos, src, 512);
        ad->pos += 512;
        memset(ad->buf + ad->pos, 0, 512);
        ad->pos += 512;
        src += 512;
    }
}

static inline void copyAC3i(AudioDecAC3 *ad, u8 *src, int size)
{
    int i;
    int n = size / 1024;

    for (i = 0; i < n; i++) {
        memcpy(ad->buf + ad->pos, src + i * 512, 512);
        ad->pos += 512;
        memset(ad->buf + ad->pos, 0, 512);
        ad->pos += 512;
    }
}


/* _sendToIOP2area @ 0x196500 .. 0x196870 (0x370 bytes, frame 0x110) */


/* dcomp generated forward */
extern void FlushCache(int);
static inline void SendToIop(u32 data, u32 addr, s32 size) {
    extern void FlushCache(int);
    extern unsigned int sceSifSetDma(void *, int);
    extern int sceSifDmaStat(unsigned int);
    u8 frame[16] __attribute__((aligned(16)));
    u32 id;

    if (size > 0) {
        ((u32 *)frame)[0] = data;
        ((u32 *)frame)[1] = addr;
        ((u32 *)frame)[2] = size;
        ((u32 *)frame)[3] = 0;
        FlushCache(0);
        id = sceSifSetDma(frame, 1);
        do {
        } while (sceSifDmaStat(id) >= 0);
    }
}


/* mpg_audioDecChangeVolume @ 0x196870 .. 0x1968D4 (0x64 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern int sceSdRemote(int, ...);

/* mpg_audioDecSendToIOP @ 0x1968E0 .. 0x196B28 (0x248 bytes, frame 0x50) */

extern u32 _sendToIOP2area(s32, s32, s32, s32, s32, s32, s32, s32);
extern u32 _sendToIOP2areaAC3(AudioDecAC3 *, u32, s32, s32, s32, s32, s32, u32, s32);

struct AudioEndState {
    u32 state, mode;
    u8 pad[48];
    u32 header;
    u32 pad2;
    s32 position;
    u32 count;
    s32 size;
    u32 total;
};

/* mpg_audioDecDelete @ 0x196EE0 .. 0x196F94 (0xb4 bytes, frame 0x30) */

extern int sceSifFreeIopHeap();

extern u32 sceSifAllocSysMemory();
extern void *memset(void *, int, unsigned int);
extern void FlushCache(int);
extern unsigned int sceSifSetDma(void *, int);
extern int sceSifDmaStat(unsigned int);
enum mpg_audioDecCreate__sel { mpg_audioDecCreate__sel_0, mpg_audioDecCreate__sel_1 };


/* mpg_DefMain @ 0x1971D0 .. 0x1971E8 (0x18 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   cfg: loop header already being structured: .L001971D8
 */

extern u32 mpg_SwitchThread();

/* endDisplay @ 0x1971F0 .. 0x1971F8 (0x8 bytes) */

extern volatile u32 isCountVblank;

/* startDisplay @ 0x197200 .. 0x197248 (0x48 bytes, frame 0x20) */


extern int sceGsSyncV(int);
extern volatile u32 g_mpg_vblankCount;


/* handler_endimage @ 0x197250 .. 0x197290 (0x40 bytes, frame 0x10) */

extern u32 mpg_GetVoBuff();
extern void voBufDecCount(u32);
extern u32 isFrameEnd;

extern void * sceDmaGetChan(int);
extern int sceGsSyncPath(int, unsigned short);
extern u32 voBufGetTag(u32);
u32 mpg_GetDBuff(void);
extern int sceGsSwapDBuff(void *, int);
extern void sceDmaSend(void *, void *);
extern void mpg_CallRegisteredVSyncIntrFunc();
extern u32 g_mpg_oddeven;
extern u32 handler_error;
extern u32 g_MPG_MAX_WIDTH;
extern u32 g_MPG_MAX_HEIGHT;




struct MP_Display { unsigned DX : 12; unsigned DY : 11; unsigned MAGH : 4; unsigned MAGV : 2; unsigned p0 : 3; unsigned DW : 12; unsigned DH : 11; unsigned p1 : 9; };
struct MP_Dispfb { unsigned FBP : 9; unsigned FBW : 6; unsigned PSM : 5; unsigned p0 : 12; unsigned DBX : 11; unsigned DBY : 11; unsigned p1 : 10; };
struct MP_DispEnv { u_long pmode; u_long smode2; struct MP_Dispfb dispfb; struct MP_Display display; u_long bgcolor; };
struct MP_Frame { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
struct MP_Zbuf { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
struct MP_DrawEnv { struct MP_Frame frame1; u_long frame1addr; struct MP_Zbuf zbuf1; long zbuf1addr; u_long rest[12]; };
struct MP_DBuff { struct MP_DispEnv disp[2]; u_long giftag0[2]; struct MP_DrawEnv draw0; u_long clear0[12]; u_long giftag1[2]; struct MP_DrawEnv draw1; u_long clear1[12]; };

/* clearGsMem @ 0x197780 .. 0x197A10 (0x290 bytes, frame 0xb0) */
/*
 * dcomp notes:
 *   literal: @193 -> 0x22c650
 *   stack: address of the slot at 0x90 escapes at 0x1978f8
 *   stack: address of the slot at 0x90 escapes at 0x197900
 *   stack: address of the slot at 0x90 escapes at 0x197914
 *   stack: address of the slot at 0x90 escapes at 0x197920
 *   stack: address of the slot at 0x90 escapes at 0x197930
 *   stack: address of the slot at 0x90 escapes at 0x197964
 *   stack: address of the slot at 0x90 escapes at 0x197974
 *   stack: address of the slot at 0x90 escapes at 0x1979a0
 *   stack: address of the slot at 0x90 escapes at 0x1979a8
 *   stack: address of the slot at 0x90 escapes at 0x1979b0
 *   literal: @193 initializes the 16-byte local at 0xa0
 *   quad: a1: 128-bit web split from its scalar variable as a1_q
 */

extern int sceGsSetDefDrawEnv(void *, short, short, short, short, short);
extern int sceGsPutDrawEnv();
extern void sceGifPkInit(void *, void *);
extern void sceGifPkReset(void *);
extern void sceGifPkEnd(void *, unsigned int, unsigned int, unsigned int);
extern void sceGifPkOpenGifTag(void *, u_long128);
extern void sceGifPkAddGsAD(void *, unsigned int, unsigned long);
extern void sceGifPkCloseGifTag(void *);
extern void * sceGifPkTerminate(void *);


/* setImageTag @ 0x197420 .. 0x197778 (0x358 bytes, frame 0xd0) */
/*
 * dcomp notes:
 *   quad: t0: 128-bit web split from its scalar uses
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @223 -> 0x22c660
 *   literal: @225 -> 0x22c670
 *   stack: address of the slot at 0xc0 escapes at 0x197498
 *   stack: address of the slot at 0xc0 escapes at 0x1974a0
 *   stack: address of the slot at 0xc0 escapes at 0x1974e0
 *   stack: address of the slot at 0xc0 escapes at 0x1974ec
 *   stack: address of the slot at 0xc0 escapes at 0x197518
 *   stack: address of the slot at 0xc0 escapes at 0x197530
 *   stack: address of the slot at 0xc0 escapes at 0x197538
 *   stack: address of the slot at 0xc0 escapes at 0x19757c
 *   stack: address of the slot at 0xc0 escapes at 0x197588
 *   stack: address of the slot at 0xc0 escapes at 0x1975a4
 *   stack: address of the slot at 0xc0 escapes at 0x1975b4
 *   stack: address of the slot at 0xc0 escapes at 0x1975bc
 *   stack: address of the slot at 0xc0 escapes at 0x1975fc
 *   stack: address of the slot at 0xc0 escapes at 0x19767c
 *   stack: address of the slot at 0xc0 escapes at 0x197688
 *   stack: address of the slot at 0xc0 escapes at 0x197698
 *   stack: address of the slot at 0xc0 escapes at 0x1976a8
 *   stack: address of the slot at 0xc0 escapes at 0x1976b8
 *   stack: address of the slot at 0xc0 escapes at 0x1976e0
 *   stack: address of the slot at 0xc0 escapes at 0x197704
 *   stack: address of the slot at 0xc0 escapes at 0x197730
 *   stack: address of the slot at 0xc0 escapes at 0x197738
 *   stack: address of the slot at 0xc0 escapes at 0x197740
 *   literal: @225 initializes the 16-byte local at 0xa0
 *   literal: @223 initializes the 16-byte local at 0xb0
 *   quad: a1: 128-bit web split from its scalar variable as a1_q
 *   cfg: loop body is not one contiguous region: .L00197550
 */

extern void sceGifPkInit(void *, void *);
extern void sceGifPkReset(void *);
extern void sceGifPkCnt(void *, unsigned int, unsigned int, unsigned int);
extern void sceGifPkOpenGifTag(void *, u_long128);
extern void sceGifPkAddGsAD(void *, unsigned int, unsigned long);
extern void sceGifPkCloseGifTag(void *);
extern void * sceGifPkReserve(void *, unsigned int);
extern void sceGifPkRef(void *, void *, unsigned int, unsigned int, unsigned int, unsigned int);
extern void sceGifPkEnd(void *, unsigned int, unsigned int, unsigned int);
extern void * sceGifPkTerminate(void *);
extern u32 L223[];
extern u32 L225[];
extern u16 g_MPG_DISP_WIDTH[2];
extern u16 g_MPG_DISP_HEIGHT[2];





/* _initAll @ 0x197A10 .. 0x197CDC (0x2cc bytes, frame 0xa0) */

u32 readBufCreate(u32 *a0 /* r4 */);
extern void sceMpegInit(void);
u32 videoDecCreate(u32 *a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */, s32 a3 /* r7 */, s32 t0 /*
    r8 */, s32 t1 /* r9 */, s32 t2 /* r10 */, s32 t3 /* r11 */);
u32 videoDecSetStream(u8 *a0 /* r4 */, u8 a1 /* r5 */, u32 a2, void *a3, u32 t0);
void voBufCreate(u32 *buffer, s32 data, s32 tags, s32 count);
extern int CreateThread(void *);
extern int StartThread(int, void *);
extern u32 AddIntcHandler(s32, void *, u32);
extern void EnableIntc(s32);
extern u32 AddDmacHandler(s32, void *, u32);
extern void EnableDmac(s32);
u32 videoDecMain(u32 *a0 /* r4 */);
u32 mpg_videoCallback(s32 unused,u32 *packet,u8 *ring);
u32 mpg_pcmCallback(u32 a0 /* r4 */, u32 *a1 /* r5 */, u8 *a2 /* r6 */);
u32 mpg_dataCallback(u32 unused, u32 *packet, u8 *ring);
extern u32 s_pMpgMng;
extern u8 *_gp;

struct ThreadParamI { int status; void *entry; void *stack; int stackSize; void *gpReg; int initPriority; int currentPriority; u32 attr; u32 option; };


/* mpg_SwitchThread @ 0x197CE0 .. 0x197CEC (0xc bytes) */
/*
 * dcomp notes:
 *   tail: j RotateThreadReadyQueue at 0x197ce4 leaves the function
 *   declaration vs inferred signature: return u32 vs inferred void
 */

extern int RotateThreadReadyQueue(int);
extern u32 s_pMpgMng;

/* mpg_ChangeDrawEnv @ 0x197CF0 .. 0x197DB0 (0xc0 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   cfg: loop header already being structured: .L00197D50
 *   cfg: loop header already being structured: .L00197D80
 *   return without a value in a non-void function
 */

extern void *memcpy();

extern int sceGsPutDrawEnv();

/* mpg_PlayPss @ 0x197DB0 (0x510 bytes, frame 0xb0): ezmpeg-style playback loop */
u32 videoDecAbort(u32 *a0);
void _updateFadeColor(void);
u32 readBufBeginPut(u32 *a0, u32 *a1);
u32 readBufEndPut(u32 *a0, s32 a1);
u32 readBufBeginGet(u32 *a0, u32 *a1);
extern u32 sceMpegDemuxPssRing(u8 *, u8 *, u32, s32, s32);
u32 readBufEndGet(u32 *a0, s32 a1);
u32 voBufIsFull(u32 *a0);
u32 videoDecGetState(u32 *a0);
u32 videoDecFlush(u32 *a0);
u32 videoDecIsFlushed(u32 *a0);
void readBufDelete(u32 *unused);
void voBufDelete(u32 *unused);
extern void TerminateThread(u8 *);
extern void DeleteThread(u8 *);
extern void DisableDmac(s32);
extern void RemoveDmacHandler(s32, u8 *);
extern void DisableIntc(s32);
extern void RemoveIntcHandler(s32, u8 *);
u32 videoDecDelete(u8 *a0);

struct PpsMng {
    int thread;            /* 0x000 */
    u8 pad04[0xe - 0x4];
    u16 stereo;            /* 0x00e */
    u8 pad10[0x2c - 0x10];
    u8 *rb;                /* 0x02c */
    u8 pad30[0x40 - 0x30];
    u8 vd[8];              /* 0x040 */
    int frame;             /* 0x048 */
    u8 pad4c[0xf0 - 0x4c];
    u8 *dmacHandler;       /* 0x0f0 */
    u8 *intcHandler;       /* 0x0f4 */
    u8 ad0[0x16c - 0xf8];  /* 0x0f8 */
    u8 ad1[0x1e0 - 0x16c]; /* 0x16c */
    u8 vo[0x1f4 - 0x1e0];  /* 0x1e0 */
    u8 *videoThread;       /* 0x1f4 */
    u8 *audioThread;       /* 0x1f8 */
    u8 pad1fc[0x200 - 0x1fc];
    int audioOn;           /* 0x200 */
    u8 pad204[0x208 - 0x204];
    int abortEnable;       /* 0x208 */
    u8 pad20c[0x210 - 0x20c];
    int abortReady;        /* 0x210 */
    u8 pad214[0x228 - 0x214];
    int abortFrame;        /* 0x228 */
    int abortDelay;        /* 0x22c */
    int aborted;           /* 0x230 */
};

#define PPS_MNG ((struct PpsMng *)s_pMpgMng)
u32 mpg_audioDecDelete(u32 *a0 );

static inline void _termAll(void)
{
    readBufDelete((u32 *)PPS_MNG->rb);
    voBufDelete((u32 *)PPS_MNG->vo);
    TerminateThread(PPS_MNG->videoThread);
    DeleteThread(PPS_MNG->videoThread);
    TerminateThread(PPS_MNG->audioThread);
    DeleteThread(PPS_MNG->audioThread);
    DisableDmac(2);
    RemoveDmacHandler(2, PPS_MNG->dmacHandler);
    DisableIntc(2);
    RemoveIntcHandler(2, PPS_MNG->intcHandler);
    videoDecDelete(PPS_MNG->vd);
    mpg_audioDecDelete((u32 *)PPS_MNG->ad0);
    if (PPS_MNG->stereo) {
        mpg_audioDecDelete((u32 *)PPS_MNG->ad1);
    }
}
#undef PPS_MNG


/* mpg_QuitPss @ 0x1982C0 .. 0x1982C8 (0x8 bytes) */

extern u32 s_isInit;

u32 mpg_GetRequiredBufferSize(u32, s32);
extern void sceGsResetPath(void);
extern void sceDmaReset(int);

extern void sceGsResetGraph(short, short, short, short);
extern void clearGsMem(int, int, int, int, int, int);
extern void sceGsSetDefDBuff(void *, short, short, short, short, short, short);


typedef struct MP_Mng {
    u32 defaultPriority;
    u32 field_04;
    s32 field_08;
    short displayMode;
    short hasAudio;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1c;
    u32 audioBuffer0;
    u32 audioBuffer1;
    u32 videoBufferSize;
    u32 readBuffer;
    u32 videoStack;
    u32 audioStack;
    u32 decoderParam;
    u8 unknown_3c[0x1f4 - 0x3c];
    s32 videoThreadId;
    s32 audioThreadId;
    u32 unknown_1fc;
    u32 mpegEnabled;
    struct MP_DBuff *gsPacket;
    u32 state_208;
    u32 state_20c;
    u32 state_210;
    u32 state_214;
    u_long field_218;
    u32 unknown_220;
    u32 unknown_224;
    u32 state_228;
    u32 state_22c;
    u32 state_230;
    u32 field_234;
    u_long *outputPacket;
    u32 unknown_23c;
} MP_Mng;

#define MP_MNG ((MP_Mng *)s_pMpgMng)

/* mpg_SetDefPrio @ 0x1988D0 .. 0x198908 (0x38 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u32 s_isInit;
extern u32 s_pMpgMng;

/* mpg_CallRegisteredVSyncIntrFunc @ 0x198B50 .. 0x198B7C (0x2c bytes, frame 0x10) */

extern u32 s_pfVSyncCallback;

/* mpg_RegisterCallBack @ 0x198B80 .. 0x198B88 (0x8 bytes) */

extern u32 s_pfCallback;

extern void mpg_audioDecEndPut(u32, u32);


extern void videoDecBeginPut(s32 *,u8 **,s32 *,u8 **,s32 *);
extern void videoDecPutTs(u32 *,u64,u64,s32,s32);
extern void videoDecEndPut(u8 *,u32);

/* strFileRead @ 0x199300 .. 0x1995F4 (0x2f4 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x85 escapes at 0x199340
 *   stack: address of the slot at 0x86 escapes at 0x199340
 *   delay: addiu at 0x199368 writes a register its branch at 0x199364 reads
 *   delay: addiu at 0x19937c writes a register its branch at 0x199378 reads
 *   stack: address of the slot at 0x88 escapes at 0x199450
 *   cfg: loop body is not one contiguous region: .L00199340
 *   cfg: loop body is not one contiguous region: .L001993A8
 *   cfg: loop body is not one contiguous region: .L00199468
 */

extern int sceCdStRead(unsigned int, void *, unsigned int, void *);
extern int sceCdDiskReady(int);
extern u32 sceCdStSeekF(u32 *);
extern void sceCdTrayReq(u32 *, u8 *);
extern u32 sceCdStStop();
extern int sceCdStStart(unsigned int, void *);
extern int sceRead(int, void *, int);


/* strFileClose @ 0x199600 .. 0x19965C (0x5c bytes, frame 0x20) */

extern u32 sceCdStStop();
extern int sceClose();
extern int sceSifFreeIopHeap();

/* strFileOpen @ 0x199660 .. 0x199974 (0x314 bytes, frame 0x1c0) */
/*
 * dcomp notes:
 *   literal: @345 is the string 'cdrom0'
 *   literal: @346 is the string ''
 *   literal: @347 is the string ';1'
 *   literal: @348 is the string '%s%s'
 *   literal: @349 is the string '%s:%s'
 *   literal: @350 is the string 'host0'
 *   stack: address of the slot at 0x70 escapes at 0x1996a8
 *   delay: addiu at 0x199704 writes a register its branch at 0x199700 reads
 *   stack: address of the slot at 0xb0 escapes at 0x199760
 *   stack: address of the slot at 0xb0 escapes at 0x199784
 *   stack: address of the slot at 0x70 escapes at 0x199784
 *   stack: address of the slot at 0x70 escapes at 0x1997a0
 *   stack: address of the slot at 0xb0 escapes at 0x1997bc
 *   stack: address of the slot at 0x70 escapes at 0x1997bc
 *   stack: address of the slot at 0x1bc escapes at 0x199878
 *   delay: lui at 0x199890 writes a register its branch at 0x19988c reads
 *   cfg: loop body is not one contiguous region: .L001996F0
 *   cfg: kept goto: 0x199810 -> .L00199950
 *   cfg: kept goto: 0x199858 -> .L00199948
 *   cfg: kept goto: 0x1998b8 -> .L00199950
 */

extern void * index(void *, int);
extern char * strncpy(char *, const char *, unsigned int);
extern int strcmp(const char *, const char *);
extern unsigned int strlen(const char *);
extern int toupper(int);
extern int sprintf(char *, const char *, ...);
extern char * strcpy(char *, const char *);
extern int sceCdStInit(unsigned int, unsigned int, unsigned int);
extern int sceCdSearchFile(void *, void *);
extern int sceOpen(void *, int, ...);
extern int sceLseek(int, int, int);
#undef dev

/* viBufGetTs @ 0x199990 .. 0x199B3C (0x1ac bytes, frame 0x60) */

extern int WaitSema(int);
extern int SignalSema(int);
typedef struct { s64 gt_pts; s64 gt_dts; s32 gt_pos; s32 gt_len; } GtTs;
typedef GtTs GtEnt;


extern int WaitSema(int);
extern u32 viBufModifyPts(u32, u8 *);
extern int SignalSema(int);
typedef struct { s64 pts; s64 dts; s32 position; s32 length; } M24Timestamp;
typedef struct { s64 pts; s64 dts; s32 position; s32 length; } M24TableEntry;


/* viBufFlush @ 0x199C80 .. 0x199CC4 (0x44 bytes, frame 0x20) */

extern int WaitSema(int);
extern int SignalSema(int);

/* viBufDelete @ 0x199D20 .. 0x199DAC (0x8c bytes, frame 0x20) */

extern u32 DIntr(void);
extern u32 EIntr(void);
extern int DeleteSema();

/* viBufRestartDMA @ 0x199DB0 (0x3a8 bytes, frame 0x80): ezmpeg vibuf.c */





typedef struct {
    u_long128 *data;   /* 0x00 */
    u_long128 *tag;    /* 0x04 */
    int n;             /* 0x08 */
    int dmaStart;      /* 0x0c */
    int dmaN;          /* 0x10 */
    int readBytes;     /* 0x14 */
    int buffSize;      /* 0x18 */
    struct {
        u_int d4madr;  /* 0x1c */
        u_int d4tadr;  /* 0x20 */
        u_int d4qwc;   /* 0x24 */
        u_int d4chcr;  /* 0x28 */
        u_int d3madr;  /* 0x2c */
        u_int d3qwc;   /* 0x30 */
        u_int d3chcr;  /* 0x34 */
        u_int ipubp;   /* 0x38 */
        u_int ipuctrl; /* 0x3c */
    } env;
    int sema;          /* 0x40 */
    int isActive;      /* 0x44 */
} VbRestartBuf;

#define VB_ELM_SIZE 2048
#define VB_DMA_REFE 0
#define VB_DMA_REF 3
#define VB_DMAADDR(a) ((u_int)(a) & 0x0fffffff)
#define VB_TAG_ADDR(i) VB_DMAADDR(f->tag + (i))
#define VB_DATA_ADDR(i) ((u_int)f->data + VB_ELM_SIZE * (i))
#define VB_WRAP_ADDR(addr) ((u_int)(f->data) + (((u_int)(addr) - (u_int)(f->data)) % (VB_ELM_SIZE * f->n)))
#define VB_IS_IN_REGION(i, start, len, n) ((0 <= (((i) + (n) - (start)) % (n))) && \
    ((((i) + (n) - (start)) % (n)) < (len)))


/* viBufStopDMA @ 0x19A160 .. 0x19A2B4 (0x154 bytes, frame 0x20) */

extern int WaitSema(int);
extern int SignalSema(int);

struct AdBuf {
    u32 ad_base;
    u32 ad_ring;
    s32 ad_n;
    s32 ad_head;
    s32 ad_cnt;
    s32 ad_pend;
    u8 ad_pad[0x28];
    s32 ad_sema;
    s32 ad_en;
};

/* viBufCreate @ 0x19A8C0 .. 0x19A934 (0x74 bytes, frame 0x40) */

extern int CreateSema(void *);


/* mpegTS @ 0x19AA90 .. 0x19AAD4 (0x44 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x20 escapes at 0x19aaa8
 *   a0 takes slot 0 only because of the ABI order
 */

extern u32 mpg_GetVideoDec();
u32 viBufGetTs(s32 buffer, u8 *timestamp);

/* mpegRestartDMA @ 0x19AAE0 .. 0x19AB08 (0x28 bytes, frame 0x10) */

int viBufRestartDMA(VbRestartBuf *f);

/* mpegNodata @ 0x19AB40 .. 0x19AB74 (0x34 bytes, frame 0x20) */

struct AdBuf;
extern u32 viBufAddDMA(struct AdBuf *);

/* decBs0 @ 0x19AB90 .. 0x19AE9C (0x30c bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0019ABD8
 *   cfg: kept branch: 0x19abd8 if (..) goto .L0019ABF8
 *   cfg: loop test does not fall through into its body: 0x19abf8
 *   cfg: kept branch: 0x19abf8 if (..) goto .L0019ABF0
 *   declaration vs inferred signature: return void vs inferred u32
 *   return value dropped: the function is void
 */

extern int sceMpegIsEnd(void *);
u32 voBufGetData(u32 *a0);
extern int sceMpegGetPicture(void *, void *, int);
extern void setImageTag();
void voBufIncCount(u32 *a0 /* r4 */);
extern int sceMpegReset(void *);


/* videoDecMain @ 0x19AEA0 .. 0x19AF08 (0x68 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 viBufReset(u32 *a0 /* r4 */);
void voBufReset(u32 *a0 /* r4 */);
s32 decBs0(u32 a0 /* r4 */);

/* videoDecIsFlushed @ 0x19AF10 .. 0x19AF68 (0x58 bytes, frame 0x30) */

u32 viBufCount(u32 *a0 /* r4 */);
extern int sceMpegIsRefBuffEmpty(void *);

static inline s32 videoFlushCopy(u32 first, s32 firstSize, u32 second, s32 secondSize,
                                 u8 *source, s32 size, u8 *tail, s32 tailSize) {
    if (firstSize + secondSize < size + tailSize) return 0;
    if (firstSize <= size) {
        memcpy(first, source, firstSize);
        memcpy(second, source + firstSize, size - firstSize);
        memcpy(second + size - firstSize, tail, tailSize);
    } else {
        if ((u32)(firstSize - size > tailSize) == 0) {
            memcpy(first, source, size);
            memcpy(first + size, tail, firstSize - size);
            memcpy(second, tail + firstSize - size, tailSize - (firstSize - size));
        } else {
            memcpy(first, source, size);
            memcpy(first + size, tail, tailSize);
        }
    }
    return size + tailSize;
}


/* videoDecPutTs @ 0x19B130 .. 0x19B16C (0x3c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x10 escapes at 0x19b158
 */

u32 viBufPutTs(s32 buffer, u8 *timestamp);

/* videoDecDelete @ 0x19B190 .. 0x19B1C4 (0x34 bytes, frame 0x20) */

extern u32 viBufDelete();
extern int sceMpegDelete(void *);

/* videoDecEndPut @ 0x19B1D0 .. 0x19B1D8 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j viBufEndPut at 0x19b1d0 leaves the function
 *   return value dropped, call kept: the function is void
 */

void viBufEndPut(u8 *a0 /* r4 */, u32 a1 /* r5 */);

/* videoDecBeginPut @ 0x19B1E0 .. 0x19B1E8 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j viBufBeginPut at 0x19b1e0 leaves the function
 *   return value dropped, call kept: the function is void
 */

void viBufBeginPut(s32 *buf, u8 **first, s32 *firstSize, u8 **second, s32 *secondSize);

/* videoDecSetStream @ 0x19B1F0 .. 0x19B210 (0x20 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   a0 forwarded to sceMpegAddStrCallback
 */

extern void *sceMpegAddStrCallback();

/* videoDecCreate @ 0x19B210 .. 0x19B30C (0xfc bytes, frame 0x70) */
/*
 * dcomp notes:
 *   a1 takes slot 1 only because of the ABI order
 *   a2 takes slot 2 only because of the ABI order
 */

extern int sceMpegCreate(void *, void *, int);
extern void * sceMpegAddCallback(void *, int, void *, void *);
u32 viBufCreate(u8 *a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */, s32 a3 /* r7 */, s32 t0 /* r8
        */, s32 t1 /* r9 */);





static inline u32 voBufIsEmpty_inl(u32 *a0) {
    return ((volatile u32 *)a0)[3] == 0;
}
#define FRAME_SZ ((((((((s32)(((s32)g_MPG_MAX_WIDTH / 0x10) * g_MPG_MAX_HEIGHT) / 0x10) * 6 + 0x6e) << 2) + 0x3f) & -0x40) << 3) + 0x40)


extern u32 g_MPG_MAX_HEIGHT;
extern u32 g_MPG_MAX_WIDTH;

static inline u32 voBufIsFull_inl(u32 *a0) {
    return a0[3] == a0[4];
}


/* voBufIncCount @ 0x19B430 .. 0x19B4F0 (0xc0 bytes, frame 0x20) */

extern u32 g_MPG_MAX_WIDTH;
extern u32 g_MPG_MAX_HEIGHT;

/* fsmpg_GetRequiredBufferSize @ 0x19B920 .. 0x19B928 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail-jumps mpg_GetRequiredBufferSize at 0x19b920; its $v0 reaches the caller.
 *   Movie.s stores that return in MoviePlay + 4 at 0x195878.
 */

u32 mpg_GetRequiredBufferSize(u32 a0 /* r4 */, s32 a1 /* r5 */);

/* fsmpg_SetPriority @ 0x19B940 .. 0x19B948 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j mpg_SetDefPrio at 0x19b940 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 mpg_SetDefPrio();

/* fsmpg_Startup @ 0x19B950 .. 0x19B98C (0x3c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   a0 forwarded to mpg_InitPss
 *   a1 forwarded to mpg_InitPss
 */

extern u32 mpg_InitPss(u32, u32, u32, u32, u32, u32, u32, u32);

/* fsmpg_MovieStart @ 0x19B990 .. 0x19BB08 (0x178 bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   cfg: kept goto: 0x19b9e8 -> .L0019BAD8
 *   cfg: loop body is not one contiguous region: .L0019BA20
 */

extern u32 strFileOpen(u8 *, char *);
extern u32 mpg_PlayPss(s32, u32 (*)(u8 *, s32), u32 (*)(void));
static u32 _cbFileRead(u8 *a0 /* r4 */, s32 a1 /* r5 */);
extern u32 s_infile[];


/* _cbFileRead @ 0x19BB10 .. 0x19BB5C (0x4c bytes, frame 0x30) */

extern void *memset(void *, int, unsigned int);
extern u32 strFileRead();
extern u32 s_infile[];

INCLUDE_RODATA("config/asm/nonmatchings/unklib_00195CA0", @346);

INCLUDE_RODATA("config/asm/nonmatchings/unklib_00195CA0", @347);

INCLUDE_RODATA("config/asm/nonmatchings/unklib_00195CA0", @348);

INCLUDE_RODATA("config/asm/nonmatchings/unklib_00195CA0", @349);

INCLUDE_RODATA("config/asm/nonmatchings/unklib_00195CA0", @350);
static u32 s_infile[0x10];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 fsmpg_MovieStart(u8 *a0 , s32 a1 , s32 a2 , u32 (*a3)(void) , s32 t0 , s32 t1 , s32 t2 , s32 t3 , u32 arg8);
u32 fsmpg_Startup(u8 *a0 , u8 *a1 , s32 a2 , s32 a3 , s32 t0 , s32 t1 , s32 t2 );
void fsmpg_SetPriority(s32 a0 );
void fsmpg_RegisterCallBack(s32 a0 );
u32 fsmpg_GetRequiredBufferSize(u32 a0 , s32 a1 );
void fsmpg_Quit(void);
static u32 mpegError(void);
static u32 mpegNodata(void);
static u32 mpegStopDMA(void);
static u32 mpegRestartDMA(void);
static u64 mpegTS(s32 a0 , u64 *a1 );
u32 viBufStopDMA(u32 *a0 );
void viBufFlush(u32 *a0 );
u32 strFileInit(u32 *a0 );
u32 strFileClose(u32 *a0 );
void mpg_CallRegisteredFunc(void);
void mpg_RegisterCallBack(s32 a0 );
u32 mpg_GetFadeColorPtr(s32 a0 , s32 a1 );
u32 mpg_GetAudioDec(void);
u32 mpg_GetDigitalAudioDec(void);
void mpg_QuitPss(void);
u32 mpg_ChangeDrawEnv(u8 *a0 );
void _initAll(void);
u32 vblankHandler(void);
u32 handler_endimage(void);
void startDisplay(s32 a0 );
void endDisplay(void);
void mpg_DefMain(void);
u32 mpg_audioDecCreate(u32 *dec, u8 *buffer, s32 size, s32 arg, s32 allocSize, s32 mode);
u32 mpg_audioDecDelete(u32 *a0 );
u32 mpg_audioDecStart(u32 *a0 );
void mpg_audioDecReset(u32 *a0 );
u32 mpg_audioDecBeginPut(u32 *a0 , u32 *a1 , u32 *a2 , u32 *a3 , u32 *t0 );
u32 mpg_audioDecIsPreset(u32 *a0 );
u32 mpg_audioDecSendToIOP(u32 *a0 );
u32 mpg_audioDecChangeVolume(s32 a0 );


static u32 _cbFileRead(u8 *a0 /* r4 */, s32 a1 /* r5 */) {
    s32 s0;
    u8 *a0_s1; // a0

    s0 = a1;
    memset((void *)a0, 0, s0);
    a0_s1 = (u8 *)s_infile;
    return strFileRead(s_infile, (u32)a0, s0);
}

u32 fsmpg_MovieStart(u8 *a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */, u32 (*a3)(void) /* r7 */, s32 t0 /*
        r8 */, s32 t1 /* r9 */, s32 t2 /* r10 */, s32 t3 /* r11 */, u32 arg8) {
    s32 n;
    u32 ret;

    n = 0;
    if (a0 == 0) {
        return 0;
    }
    strFileInit(s_infile);
    while (!strFileOpen((u8 *)s_infile, (char *)a0)) {
        if (n++ > 10) {
            strFileClose(s_infile);
            return 0;
        }
    }
    if (mpg_InitPss((u32)a1, (u32)a2, (u32)t1, 0, t0, t2, t3, *(u16 *)&arg8) == 0) {
        strFileClose(s_infile);
        return 0;
    }
    ret = mpg_PlayPss((s32)s_infile[1], _cbFileRead, a3);
    strFileClose(s_infile);
    return ret;
}

u32 fsmpg_Startup(u8 *a0 /* r4 */, u8 *a1 /* r5 */, s32 a2 /* r6 */, s32 a3 /* r7 */, s32 t0 /* r8
        */, s32 t1 /* r9 */, s32 t2 /* r10 */) {
    u32 v0;

    v0 = mpg_InitPss((u32)a0, (u32)a1, a3, 0, a2, t0, t1, t2);
    return v0 != 0;
}

void fsmpg_SetPriority(s32 a0 /* r4 */) {
    mpg_SetDefPrio(a0);
    return;
}

/* fsmpg_RegisterCallBack @ 0x19B930 .. 0x19B938 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j mpg_RegisterCallBack at 0x19b930 leaves the function
 */

void fsmpg_RegisterCallBack(s32 a0 /* r4 */) {
    mpg_RegisterCallBack(a0);
    return;
}

u32 fsmpg_GetRequiredBufferSize(u32 a0 /* r4 */, s32 a1 /* r5 */) {
    return mpg_GetRequiredBufferSize(a0, a1);
}


/* fsmpg_Quit @ 0x19B910 .. 0x19B918 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j mpg_QuitPss at 0x19b910 leaves the function
 */

void fsmpg_Quit(void) {
    mpg_QuitPss();
    return;
}

void voBufCreate(u32 *buffer, s32 data, s32 tags, s32 count) {
    s32 i;
    buffer[0] = data;
    buffer[1] = tags;
    buffer[4] = count;
    buffer[3] = 0;
    buffer[2] = 0;
    for (i = 0; i < count; i++) {
        s32 blocks = (((s32)g_MPG_MAX_WIDTH / 16) * (s32)g_MPG_MAX_HEIGHT) / 16;
        *(u32 *)(buffer[1] + i * (((((blocks * 6 + 110) * 4 + 63) & -64) * 8) + 64)) = 0;
    }
}

/* voBufDelete @ 0x19B520 .. 0x19B528 (0x8 bytes) */

void voBufDelete(u32 *unused /* r4 */) {
    return;
}

/* voBufReset @ 0x19B510 .. 0x19B51C (0xc bytes) */

void voBufReset(u32 *a0 /* r4 */) {
    *(u32 *)(((u8 *)a0 + 0xc)) = 0;
    *(u32 *)(((u8 *)a0 + 8)) = 0;
    return;
}

/* voBufIsFull @ 0x19B4F0 .. 0x19B504 (0x14 bytes) */
/*
 * dcomp notes:
 *   return: sltiu at 0x19b500 computes the return value
 */

u32 voBufIsFull(u32 *a0 /* r4 */) {
    u32 v1;
    u32 v0;

    v1 = *(s32 *)(((u8 *)a0 + 0xc));
    v0 = *(s32 *)(((u8 *)a0 + 0x10));
    return (u32)(v1 ^ v0) < (u32)1;
}

void voBufIncCount(u32 *a0 /* r4 */) {
    u8 *s0;

    s0 = (u8 *)a0;
    DIntr();
    *(u32 *)(u32)(*(s32 *)(s0 + 4) + (u32)((u32)*(s32 *)(s0 + 8) * (u32)(s32)((u8
        *)(u32)((u32)((s32)((s32)((u32)((s32)((u32)((s32)((u32)((s32)g_MPG_MAX_WIDTH / (s32)(0x10))
        * (u32)g_MPG_MAX_HEIGHT) / (s32)(0x10)) * (u32)(6)) + 0x6e) << 2) + 0x3f) & (u32)-0x40) <<
        3) + 0x40))) = 2;
    *(u32 *)(s0 + 0xc) += 1;
    *(u32 *)(s0 + 8) = (s32)(*(s32 *)(s0 + 8) + 1) % (s32)*(s32 *)(s0 + 0x10);
    EIntr();
    return;
}

u32 voBufGetData(u32 *a0) {
    if (voBufIsFull_inl(a0)) return 0; return a0[0] + (s32)a0[2] * (s32)(g_MPG_MAX_WIDTH * g_MPG_MAX_HEIGHT * 4);
}
u32 voBufGetTag(u32 buf) {
    u32 *a0 = (u32 *)buf;
    if (voBufIsEmpty_inl(a0)) return 0;
    return a0[1] + (u32)((s32)(a0[4] + (a0[2] - a0[3])) % (s32)a0[4]) * (u32)FRAME_SZ;
}

void voBufDecCount(u32 a0) {
    volatile s32 *p = (s32 *)a0;
    if (p[3] > 0) {
        p[3]--;
    }
}

u32 videoDecCreate(u32 *a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */, s32 a3 /* r7 */, s32 t0 /*
        r8 */, s32 t1 /* r9 */, s32 t2 /* r10 */, s32 t3 /* r11 */) {
    u32 *s5;
    s32 s4;
    s32 s3;
    s32 s2;
    s32 s1;
    s32 s0;
    u32 *a0_2;
    s32 a1_2;
    s32 a2_2;
    s32 a3_2;
    s32 t0_2;
    s32 t1_2;

    s5 = a0;
    s4 = a3;
    s3 = t0;
    s2 = t1;
    s1 = t2;
    s0 = t3;
    sceMpegCreate((void *)a0, (void *)a1, a2);
    a2_2 = (s32)mpegError;
    sceMpegAddCallback((void *)(u32 *)s5, 0, mpegError, (void *)0);
    a2_2 = (s32)mpegNodata;
    sceMpegAddCallback((void *)(u32 *)s5, 1, mpegNodata, (void *)0);
    a2_2 = (s32)mpegStopDMA;
    sceMpegAddCallback((void *)(u32 *)s5, 2, mpegStopDMA, (void *)0);
    a2_2 = (s32)mpegRestartDMA;
    sceMpegAddCallback((void *)(u32 *)s5, 3, mpegRestartDMA, (void *)0);
    a2_2 = (s32)mpegTS;
    sceMpegAddCallback((void *)(u32 *)s5, 5, mpegTS, (void *)0);
    a1_2 = s4;
    a2_2 = s3;
    a3_2 = s2;
    t0_2 = s1;
    t1_2 = s0;
    a0_2 = (u32 *)((u8 *)s5 + 0x48);
    s5[0x2a] = 0;
    viBufCreate((u8 *)a0_2, a1_2, a2_2, a3_2, t0_2, t1_2);
    return 1;
}

u32 videoDecSetStream(u8 *a0 /* r4 */, u8 a1 /* r5 */, u32 a2, void *a3, u32 t0) {
    u32 a1_word = a1;

    a1_word = (u8)a1_word;
    sceMpegAddStrCallback((u32)a0, a1_word);
    return 1;
}

void videoDecBeginPut(s32 *a0 /* r4 */, u8 **a1 /* r5 */, s32 *a2 /* r6 */, u8 **a3 /* r7 */, s32
        *t0 /* r8 */) {
    viBufBeginPut((s32 *)(u8 *)(a0 + 0x12), a1, a2, a3, t0);
    return;
}

void videoDecEndPut(u8 *a0 /* r4 */, u32 a1 /* r5 */) {
    viBufEndPut((u8 *)(a0 + 0x48), a1);
    return;
}

u32 videoDecDelete(u8 *a0 /* r4 */) {
    u32 s0;

    s0 = (u32)a0;
    a0 = (u8 *)(s0 + 0x48);
    viBufDelete(a0);
    a0 = (u8 *)s0;
    sceMpegDelete(a0);
    return (u32)1;
}

/* videoDecAbort @ 0x19B180 .. 0x19B18C (0xc bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 videoDecAbort(u32 *a0 /* r4 */) {
    *(u32 *)(((u8 *)a0 + 0xa8)) = 1;
    return;
}

/* videoDecGetState @ 0x19B170 .. 0x19B178 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x19b174 computes the return value
 */

u32 videoDecGetState(u32 *a0 /* r4 */) {
    return *(u32 *)(((u8 *)a0 + 0xa8));
}

void videoDecPutTs(u32 *a0 /* r4 */, u64 a1 /* r5 */, u64 a2 /* r6 */, s32 a3 /* r7 */, s32 t0 /*
        r8 */) {
    u32 v0;
    u8 stackFrame_10[32] __attribute__((aligned(16)));

    *(u64 *)((u8 *)&stackFrame_10[0]) = a1;
    ((u64 *)stackFrame_10)[1] = a2;
    v0 = (s32)a0[0x12];
    v0 = a3 - v0;
    ((u32 *)stackFrame_10)[5] = t0;
    ((u32 *)stackFrame_10)[4] = v0;
    v0 = mpg_GetVideoDec();
    viBufPutTs((s32)(u32 *)(u32)(v0 + (u32)0x48), (u8 *)((u8 *)&stackFrame_10[0]));
    return;
}
u32 videoDecFlush(u32 *a0) {
    u8 *decoder;
    u32 first, second;
    s32 count;
    u8 *p0, *p1;
    struct { u8 b[4]; } marker = {{0,0,1,0xb7}};
    s32 n0, n1;
    decoder = (u8 *)a0;
    viBufBeginPut((s32 *)(decoder+0x48), &p0, &n0, &p1, &n1);
    count = n0;
    if (count+n1 <= 3) return 0;
    first = ((u32)p0 & 0x0fffffff) | 0x20000000;
    second = ((u32)p1 & 0x0fffffff) | 0x20000000;
    count = videoFlushCopy(first, count, second, n1, (u8 *)&marker, 4, 0, 0);
    viBufEndPut((u8 *)(mpg_GetVideoDec()+0x48), count);
    viBufFlush((u32 *)(decoder+0x48));
    if (*(u32 *)(decoder+0xa8)==0) *(u32 *)(decoder+0xa8)=2;
    return 1;
}

u32 videoDecIsFlushed(u32 *a0 /* r4 */) {
    u32 s1;
    s32 s0;
    u32 v0;
    u32 *a0_2;

    s1 = (u32)a0;
    s0 = 0;
    v0 = viBufCount((u32 *)(u32)(s1 + 0x48));
    a0_2 = (u32 *)s1;
    if (v0 == 0) {
        v0 = sceMpegIsRefBuffEmpty((void *)a0_2);
        if (v0 != 0) {
            s0 = 1;
        }
    }
    return s0;
}

u32 videoDecMain(u32 *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u32 v0;

    s0 = (u8 *)a0;
    viBufReset((u32 *)(s0 + 0x48));
    v0 = mpg_GetVoBuff();
    voBufReset((u32 *)v0);
    decBs0((u32)s0);
    do {
        v0 = mpg_GetVoBuff();
        v1 = *(s32 *)((v0 + 0xc));
    } while (v1 != 0);
    *(u32 *)(s0 + 0xa8) = 3;
    return v0;
}

s32 decBs0(u32 a0 /* r4 */) {
    u32 t1;
    s32 a2;
    u32 a1;
    s32 fp;
    u8 *s7;
    u32 a0_index; // a0
    u32 *a0_2; // a0
    s32 v1;
    u32 v0_2; // v0
    u32 v0_3; // v0
    s32 s6;
    u8 *s5;
    u32 imageOffset;
    s32 s4;
    u32 s3;
    u32 s2;
    u32 v0_4; // v0
    u32 v0_5; // v0
    s32 v0;

    fp = 1;
    s7 = (u8 *)a0;
    v0 = sceMpegIsEnd((void *)a0);
    v0 = v0 != 0;
    v0 = v0 ^ 1;
    if (v0 != 0) {
        do {
            v1 = *(s32 *)(s7 + 0xa8);
            v0 = 1;
            if (v1 != v0) {
                goto _L0019ABF8;
            }
            fp = -1;
            break;
            _L0019ABF0:;
            mpg_SwitchThread();
            _L0019ABF8:;
            v0_4 = mpg_GetVoBuff();
            a0_2 = (u32 *)v0_4;
            v0 = voBufGetData(a0_2);
            v1 = v0 != 0;
            v1 = v1 ^ 1;
            if (v1 != 0) {
                goto _L0019ABF0;
            }
            a0 = (s32)g_MPG_MAX_WIDTH / 16;
            v1 = (s32)a0 * (s32)g_MPG_MAX_HEIGHT;
            a2 = (s32)v1 / 16;
            sceMpegGetPicture((void *)s7, (void *)v0, a2);
            v0 = *(s32 *)(s7 + 8);
            if (v0 == 0) {
                s2 = *(volatile s32 *)(s7 + 4);
                s3 = *(volatile s32 *)s7;
                v0 = mpg_GetVoBuff();
                s5 = (u8 *)v0;
                v0 = *(s32 *)((v0 + 0x10));
                s4 = 0;
                if (0 < (s32)v0) {
                    do {
                        {
                            u32 imageBase;
                            s32 s1;
                            s32 s0;
                        s0 = g_MPG_MAX_WIDTH;
                        s1 = g_MPG_MAX_HEIGHT;
                        v0 = (s32)s0 / 0x10;
                        v0 = (s32)v0 * (s32)s1;
                        a0_2 = (u32 *)((s32)v0 / 0x10);
                        v1 = (u32)a0_2 << 1;
                        v0 = -0x40;
                        v1 = (s32)((u8 *)v1 + (u32)(a0_2));
                        v1 = v1 << 1;
                        v1 = v1 + 0x6e;
                        v1 = v1 << 2;
                        v1 = v1 + 0x3f;
                        v0 = v1 & (u32)v0;
                        v0 = v0 << 3;
                        v0 = v0 + 0x40;
                        s6 = (u32)s4 * v0;
                        v0 = mpg_GetVoBuff();
                        v0 = *(s32 *)((v0 + 4));
                        a0_2 = (u32 *)s4;
                        s6 = v0 + (s32)s6;
                        v0_2 = mpg_GetFadeColorPtr((s32)a0_2, 0);
                        imageOffset = s0 * s1;
                        t1 = v0_2;
                        imageBase = *(u32 *)s5;
                        a0_2 = (u32 *)(s32)(s6 + 0x40);
                        a2 = 0;
                        imageOffset = imageOffset << 2;
                        a1 = imageBase + (u32)s4 * imageOffset;
                        setImageTag(a0_2, a1, a2, (s32)s3, (s32)s2, t1);
                        }
                        {
                            s32 s1;
                            s32 s0;
                        s0 = g_MPG_MAX_WIDTH;
                        s1 = g_MPG_MAX_HEIGHT;
                        v0 = (s32)s0 / 0x10;
                        v0 = (s32)v0 * (s32)s1;
                        a0_2 = (u32 *)((s32)v0 / 0x10);
                        v1 = (u32)a0_2 << 1;
                        v0 = -0x40;
                        v1 = (s32)((u8 *)v1 + (u32)(a0_2));
                        v1 = v1 << 1;
                        v1 = v1 + 0x6e;
                        v1 = v1 << 2;
                        v1 = v1 + 0x3f;
                        v0 = v1 & (u32)v0;
                        v0 = v0 << 3;
                        v0 = v0 + 0x40;
                        s6 = (u32)s4 * v0;
                        v0 = mpg_GetVoBuff();
                        v0 = *(s32 *)((v0 + 4));
                        v1 = g_MPG_MAX_WIDTH;
                        v0 = v0 + s6;
                        a0 = (s32)v1 / 16;
                        v1 = (s32)a0 * (s32)g_MPG_MAX_HEIGHT;
                        a1 = (s32)v1 / 16;
                        a0 = a1 << 1;
                        v1 = -0x40;
                        a1 = (s32)a0 + (s32)a1;
                        a2 = a1 << 1;
                        a0_2 = (u32 *)s4;
                        a2 = a2 + 0x6e;
                        a1 = 1;
                        a2 = (u32)a2 << 2;
                        a2 = a2 + 0x3f;
                        v1 = a2 & (u32)v1;
                        v1 = v1 << 2;
                        s6 = v0 + v1;
                        v0_3 = mpg_GetFadeColorPtr((s32)a0_2, a1);
                        v1 = s0 * s1;
                        t1 = v0_3;
                        v0 = *(s32 *)s5;
                        a0_2 = (u32 *)(s32)(s6 + 0x40);
                        a2 = 1;
                        v1 = v1 << 2;
                        v1 = (s32)s4 * (s32)v1;
                        a1 = v0 + v1;
                        setImageTag(a0_2, a1, a2, (s32)s3, (s32)s2, t1);
                        }
                        s4 = s4 + 1;
                    } while (s4 < (s32)*(s32 *)(s5 + 0x10));
                }
            }
            v0_5 = mpg_GetVoBuff();
            voBufIncCount((u32 *)v0_5);
            {
                extern void mpg_CallRegisteredFunc();
                v0 = g_mpg_vblankCount;
                mpg_CallRegisteredFunc((s32)v0 >> 1);
            }
            mpg_SwitchThread();
            a0_2 = (u32 *)s7;
            v0 = sceMpegIsEnd((void *)a0_2);
            v0 = v0 != 0;
            v0 = v0 ^ 1;
        } while (v0 != 0);
    }
    sceMpegReset((void *)s7);
    return fp;
}

/* mpegError @ 0x19AB80 .. 0x19AB88 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x19ab84 computes the return value
 */

static u32 mpegError(void) {
    return 1;
}

static u32 mpegNodata(void) {
    u32 v0;
    u32 s0;
    struct AdBuf *a0;
    u32 a1;

    v0 = mpg_GetVideoDec();
    s0 = v0;
    mpg_SwitchThread();
    a0 = (struct AdBuf *)(s0 + 0x48);
    viBufAddDMA(a0);
    v0 = 1;
    return v0;
}

/* mpegStopDMA @ 0x19AB10 .. 0x19AB38 (0x28 bytes, frame 0x10) */

static u32 mpegStopDMA(void) {
    u32 v0;
    u32 a0;
    u32 a1;

    v0 = mpg_GetVideoDec();
    a0 = v0 + 0x48;
    viBufStopDMA((u32 *)a0);
    v0 = 1;
    return v0;
}

/* mpegRestartDMA @ 0x19AAE0 .. 0x19AB08 (0x28 bytes, frame 0x10) */
static u32 mpegRestartDMA(void) {
    u32 v0;

    v0 = mpg_GetVideoDec();
    viBufRestartDMA((VbRestartBuf *)(u32)(v0 + 0x48));
    return 1;
}

/* mpegTS @ 0x19AA90 .. 0x19AAD4 (0x44 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x20 escapes at 0x19aaa8
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return u64 vs inferred u32
 */
static u64 mpegTS(s32 a0 /* r4 */, u64 *a1 /* r5 */) {
    u64 *s0;
    u64 v1;
    u32 v0;
    u8 stackFrame_20[32] __attribute__((aligned(16)));

    s0 = a1;
    v0 = mpg_GetVideoDec();
    viBufGetTs(v0 + 0x48, (u8 *)(u64 *)((u8 *)&stackFrame_20[0]));
    v1 = *(u64 *)((u8 *)&stackFrame_20[0]);
    v0 = 1;
    *(u64 *)(((u8 *)s0 + 8)) = v1;
    v1 = ((u64 *)stackFrame_20)[1];
    *(u64 *)(((u8 *)s0 + 0x10)) = v1;
    return v0;
}

 
 
u32 viBufModifyPts(u32 a0, u8 *a1) {
    u8 *buf = (u8 *)a0;
    M24Timestamp *ts = (M24Timestamp *)a1;
    M24TableEntry *entry;
    s32 idx;
    s32 mod;
    s32 size;
    s32 head;
    s32 num;
    s32 n;
    s32 cont;
    s32 left;

    cont = 1;
    num = *(s32 *)(buf + 0x58);
    head = *(s32 *)(buf + 0x5c);
    size = *(s32 *)(buf + 0x54);
    mod = *(s32 *)(buf + 8) << 11;
    idx = (size + (head - num)) % size;
    if (num > 0) {
        do {
            entry = (M24TableEntry *)(*(s32 *)(buf + 0x50) + idx * 0x18);
            if (entry->length == 0) {
                break;
            }
            if (ts->length == 0) {
                break;
            }
            if (((entry->position + mod - ts->position) % mod) < ts->length) {
                n = ts->position + ts->length - entry->position;
                if (n < entry->length) {
                    n = (s32)(u32)n;
                } else {
                    n = entry->length;
                }
                entry->position = (entry->position + n) % mod;
                entry->length -= n;
                if (entry->length == 0) {
                    if (entry->pts >= 0) {
                        entry->pts = -1;
                        entry->dts = -1;
                        entry->position = 0;
                        entry->length = 0;
                    }
                    left = *(s32 *)(buf + 0x58) - 1;
                    left = (left < 0) ? 0 : left;
                    *(s32 *)(buf + 0x58) = left;
                }
            } else {
                cont = 0;
            }
            idx = (idx + 1) % *(s32 *)(buf + 0x54);
        } while (cont != 0);
    }
    return 0;
}

u32 viBufCreate(u8 *a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */, s32 a3 /* r7 */, s32 t0 /* r8
        */, s32 t1 /* r9 */) {
    u8 *s0;
    s32 v1;
    s32 v0;
    u8 stackFrame_20[32] __attribute__((aligned(16)));

    v0 = 0x20000000;
    v1 = (u32)a3 << 0xb;
    *(u32 *)a0 = a1;
    s0 = a0;
    a1 = (u32)a2 & 0xfffffff;
    *(u32 *)(a0 + 4) = a1 | 0x20000000;
    v0 = 1;
    *(u32 *)(a0 + 8) = a3;
    *(u32 *)(a0 + 0x18) = v1;
    *(u32 *)(a0 + 0x50) = t0;
    *(u32 *)(a0 + 0x54) = t1;
    ((u32 *)stackFrame_20)[2] = v0;
    a0 = ((u8 *)&stackFrame_20[0]);
    ((u32 *)stackFrame_20)[1] = v0;
    v0 = CreateSema((void *)a0);
    *(u32 *)(s0 + 0x40) = v0;
    viBufReset((u32 *)(u8 *)s0);
    *(u64 *)(s0 + 0x48) = 0;
    return 1;
}


/* viBufReset @ 0x19A720 .. 0x19A8B4 (0x194 bytes, frame 0x10) */

u32 viBufReset(u32 *a0 /* r4 */) {
    s32 t0;
    s32 a3;
    s32 a2;
    u32 a1;
    u32 v1;
    u64 v1_64;
    u32 v0;

    v0 = 1;
    a0[3] = 0;
    a0[4] = 0;
    a0[5] = 0;
    a0[0x11] = v0;
    a0[0x16] = 0;
    a0[0x17] = 0;
    v0 = (s32)a0[0x15];
    a2 = 0;
    if (0 < (s32)v0) {
        a1 = 0;
        v1 = -1;
        do {
            v0 = (s32)a0[0x14];
            a2 = a2 + 1;
            *(s64 *)(u32)(v0 + a1) = (s32)v1;
            v0 = (s32)a0[0x14];
            *(s64 *)(((u32)(v0 + a1) + 8)) = (s32)v1;
            v0 = (s32)a0[0x14];
            *(u32 *)(((u32)(v0 + a1) + 0x10)) = 0;
            v0 = (s32)a0[0x14];
            *(u32 *)(((u32)(v0 + a1) + 0x14)) = 0;
            v0 = (s32)a0[0x15];
            v0 = a2 < (s32)v0;
            a1 = a1 + 0x18;
        } while (v0 != 0);
    }
    v0 = (s32)a0[2];
    a2 = 0;
    if (0 < (s32)v0) {
        t0 = 0;
        a3 = 0;
        v0 = 0x30000000;
        a1 = 0x30000000 | 0x80;
        do {
            v1 = *(s32 *)a0;
            v0 = (s32)a0[1];
            a2 = a2 + 1;
            v1 = v1 + t0;
            t0 = t0 + 0x800;
            v1_64 = (u64)(u32)(v1 & 0xfffffff) << 0x20;
            *(u64 *)(u32)(v0 + a3) = (u64)(v1_64) | (u64)(a1);
            v0 = (s32)a0[2];
            v0 = a2 < (s32)v0;
            a3 = a3 + 0x10;
        } while (v0 != 0);
    }
    a1 = (s32)a0[1];
    v1 = 0x20000000;
    *(u64 *)(u32)(a1 + (u32)((u32)a2 << 4)) = (u64)((u64)(u32)(a1 & 0xfffffff) << 0x20) |
        (u64)((s32)((s32)0x20000000));
    *(volatile u32 *)0x1000b420 = 0;
    v0 = *(s32 *)a0;
    *(volatile u32 *)0x1000b410 = v0 & 0xfffffff;
    v0 = (s32)a0[1];
    *(volatile u32 *)0x1000b430 = v0 & 0xfffffff;
    DIntr();
    a1 = *(volatile s32 *)0x1000f520;
    a0 = (u32 *)0x10000;
    v1 = 5;
    v0 = -0x10001;
    *(volatile u32 *)0x1000f590 = a1 | 0x10000;
    *(volatile u32 *)0x1000b400 = v1;
    v1 = *(volatile s32 *)0x1000f520;
    *(volatile u32 *)0x1000f590 = v1 & -0x10001;
    EIntr();
    return 1;
}

void viBufBeginPut(s32 *buf, u8 **first, s32 *firstSize, u8 **second, s32 *secondSize) {
    s32 start;
    s32 space;
    s32 extra, count, total, numerator, capacity;
    WaitSema(buf[16]);
    count = buf[4];
    numerator = buf[3];
    extra = buf[5];
    total = buf[6];
    capacity = buf[2];
    numerator += count;
    numerator <<= 11;
    numerator += extra;
    start = numerator % total;
    capacity -= 2;
    capacity -= count;
    capacity <<= 11;
    numerator = capacity - extra;
    space = numerator;
    if (!(total - start < space)) {
        *first = (u8 *)buf[0] + start;
        *firstSize = space;
        *second = 0;
        *secondSize = 0;
    } else {
        *first = (u8 *)buf[0] + start;
        *firstSize = buf[6] - start;
        *second = (u8 *)buf[0];
        *secondSize = space - (buf[6] - start);
    }
    SignalSema(buf[16]);
}


/* viBufEndPut @ 0x19A5C0 .. 0x19A61C (0x5c bytes, frame 0x30) */

void viBufEndPut(u8 *a0 /* r4 */, u32 a1 /* r5 */) {
    u8 *s1;
    u32 s0;
    u32 a0_scalar; // a0
    s32 v1;
    u64 v0_64;
    u32 v0;

    s1 = a0;
    a0_scalar = *(s32 *)(a0 + 0x40);
    s0 = a1;
    WaitSema(a0_scalar);
    v0 = *(s32 *)(s1 + 0x14);
    v1 = s0;
    *(u32 *)(s1 + 0x14) = v0 + s0;
    v0_64 = *(u64 *)(s1 + 0x48);
    *(u64 *)(s1 + 0x48) = v0_64 + (u64)((s32)(v1));
    a0_scalar = *(s32 *)(s1 + 0x40);
    SignalSema(a0_scalar);
    return;
}

u32 viBufAddDMA(struct AdBuf *buf) {
    struct AdBuf *s2;
    s32 s1;
    s32 s0;
    s32 madr;
    s32 retired;
    s32 a0;
    s32 a1;
    s32 v0;
    s32 v1;
    s32 t2;
    s32 t1;

    s2 = buf;
    s0 = 0;
    WaitSema(s2->ad_sema);
    if (s2->ad_en == 0) {
        SignalSema(s2->ad_sema);
        return 0;
    }
    DIntr();
    a1 = *(volatile s32 *)0x1000f520;
    *(volatile u32 *)0x1000f590 = a1 | 0x10000;
    *(volatile u32 *)0x1000b400 = 5;
    v1 = *(volatile s32 *)0x1000f520;
    *(volatile u32 *)0x1000f590 = v1 & -0x10001;
    EIntr();
    a0 = s2->ad_n;
    s1 = *(volatile s32 *)0x1000b400;
    v1 = a0 + 1;
    madr = *(volatile s32 *)0x1000b410;
    if ((u64)(s32)madr == ((u64)(u32)(s2->ad_ring + (v1 << 4)) & 0xfffffff)) {
        v0 = 0;
    } else {
        v0 = (u32)(madr - s2->ad_base) >> 0xb;
    }
    v1 = s2->ad_head;
    retired = (v0 + a0 - v1) % a0;
    s2->ad_head = (v1 + retired) % a0;
    s2->ad_cnt -= retired;
    v1 = (s2->ad_head + s2->ad_cnt) % s2->ad_n;
    v0 = s2->ad_pend / 0x800;
    s2->ad_pend = s2->ad_pend % 0x800;
    if (v0 > 0) {
        a1 = (s2->ad_n + (s2->ad_head + s2->ad_cnt - 1)) % s2->ad_n;
        s0 = 1;
        *(u64 *)(s2->ad_ring + (a1 << 4)) = ((u64)(u32)(s2->ad_base + (a1 << 0xb)) << 0x20) | 0x30000080;
    }
    t2 = 0;
    if (0 < v0) {
        t1 = v0 - 1;
        do {
            u32 w;
            u64 hi;
            w = s2->ad_base + (v1 << 0xb);
            hi = (u64)w << 0x20;
            if (t2 == t1) {
                w = 0;
            } else {
                w = 3;
            }
            t2 = t2 + 1;
            ((struct { u64 low, high; } *)s2->ad_ring)[v1].low = (hi | ((u64)w << 0x1c)) | 0x80;
            v1 = (v1 + 1) % s2->ad_n;
        } while (t2 < v0);
    }
    s2->ad_cnt += v0;
    if (s2->ad_cnt != 0) {
        if (s0 != 0) {
            s1 = (s1 & 0xfffffff) | 0x30000000;
        }
        DIntr();
        a1 = *(volatile s32 *)0x1000f520;
        *(volatile u32 *)0x1000f590 = a1 | 0x10000;
        *(volatile u32 *)0x1000b400 = s1 | 0x100;
        v1 = *(volatile s32 *)0x1000f520;
        *(volatile u32 *)0x1000f590 = v1 & -0x10001;
        EIntr();
    }
    SignalSema(s2->ad_sema);
    return 1;
}

u32 viBufStopDMA(u32 *a0 /* r4 */) {
    u32 *s0;
    u32 a1;
    u32 v1;
    u32 v0;

    s0 = a0;
    a0 = (u32 *)*(s32 *)(((u8 *)a0 + 0x40));
    WaitSema((s32)a0);
    *(u32 *)(((u8 *)s0 + 0x44)) = 0;
    DIntr();
    a1 = *(volatile s32 *)0x1000f520;
    a0 = (u32 *)0x10000;
    v1 = 5;
    v0 = -0x10001;
    a0 = (u32 *)(a1 | 0x10000);
    *(volatile u32 *)0x1000f590 = (u32)a0;
    *(volatile u32 *)0x1000b400 = v1;
    v1 = *(volatile s32 *)0x1000f520;
    v0 = v1 & (u32)(-0x10001);
    *(volatile u32 *)0x1000f590 = v0;
    EIntr();
    v0 = *(volatile s32 *)0x1000b410;
    *(u32 *)(((u8 *)s0 + 0x1c)) = v0;
    v0 = *(volatile s32 *)0x1000b430;
    *(u32 *)(((u8 *)s0 + 0x20)) = v0;
    v0 = *(volatile s32 *)0x1000b420;
    *(u32 *)(((u8 *)s0 + 0x24)) = v0;
    v0 = *(volatile s32 *)0x1000b400;
    *(u32 *)(((u8 *)s0 + 0x28)) = v0;
    do {
        v0 = *(volatile s32 *)0x10002010;
        v0 = v0 & 0xf0;
    } while (v0 != 0);
    DIntr();
    a0 = (u32 *)*(volatile s32 *)0x1000f520;
    v1 = 0x10000;
    v0 = -0x10001;
    v1 = (u32)((u32)(a0)) | 0x10000;
    *(volatile u32 *)0x1000f590 = v1;
    *(volatile u32 *)0x1000b000 = 0;
    v1 = *(volatile s32 *)0x1000f520;
    v0 = v1 & (u32)(-0x10001);
    *(volatile u32 *)0x1000f590 = v0;
    EIntr();
    v0 = *(volatile s32 *)0x1000b010;
    *(u32 *)(((u8 *)s0 + 0x2c)) = v0;
    v0 = *(volatile s32 *)0x1000b020;
    *(u32 *)(((u8 *)s0 + 0x30)) = v0;
    v0 = *(volatile s32 *)0x1000b000;
    *(u32 *)(((u8 *)s0 + 0x34)) = v0;
    v0 = *(volatile s32 *)0x10002020;
    *(u32 *)(((u8 *)s0 + 0x38)) = v0;
    v0 = *(volatile s32 *)0x10002010;
    *(u32 *)(((u8 *)s0 + 0x3c)) = v0;
    a0 = (u32 *)*(s32 *)(((u8 *)s0 + 0x40));
    SignalSema((s32)a0);
    v0 = 1;
    return v0;
}

int viBufRestartDMA(VbRestartBuf *f)
{
    int id;
    int bp;
    int fp;
    int ifc;
    u_int d4madr;
    u_int d4tadr;
    u_int d4qwc;
    int index_next;
    u_int d4chcr;
    u_int d4madr_next;
    u_int d4qwc_next;
    u_int d4tadr_next;
    u_int d4chcr_next;
    u_int d3chcr;

    WaitSema(f->sema);

    bp = f->env.ipubp & 0x7f;
    fp = (f->env.ipubp >> 16) & 0x3;
    ifc = (f->env.ipubp >> 8) & 0xf;
    d4madr = f->env.d4madr;
    d4tadr = f->env.d4tadr;
    d4qwc = f->env.d4qwc;
    d4chcr = f->env.d4chcr;

    d4madr_next = d4madr - ((fp + ifc) << 4);
    d4qwc_next = d4qwc + (fp + ifc);
    d4tadr_next = d4tadr;
    d4chcr_next = d4chcr | 0x100;

    if (d4madr_next < (u_int)f->data) {
        d4qwc_next = ((u_int)f->data - d4madr_next) >> 4;
        d4madr_next += VB_ELM_SIZE * f->n;
        d4tadr_next = VB_TAG_ADDR(0);
        id = (d4madr == (u_int)f->data || d4madr == (u_int)f->data + VB_ELM_SIZE * f->n)
            ? VB_DMA_REFE : VB_DMA_REF;
        d4chcr_next = (d4chcr & 0x0fffffff) | (id << 28) | 0x100;
        if (!VB_IS_IN_REGION(0, f->dmaStart, f->dmaN, f->n)) {
            f->dmaStart = f->n - 1;
            f->dmaN++;
        }
    } else {
        int index;

        index = (d4madr == VB_TAG_ADDR(f->n + 1)) ? 0 : (d4madr - (u_int)f->data) / VB_ELM_SIZE;
        index_next = (d4madr_next == VB_TAG_ADDR(f->n + 1)) ? 0 : (d4madr_next - (u_int)f->data) / VB_ELM_SIZE;

        if (index != index_next) {
            d4tadr_next = VB_TAG_ADDR(index);
            d4qwc_next = (VB_DATA_ADDR(index) - d4madr_next) >> 4;
            id = (VB_WRAP_ADDR(d4madr) == VB_DATA_ADDR((f->dmaStart + f->dmaN) % f->n))
                ? VB_DMA_REFE : VB_DMA_REF;
            d4chcr_next = (d4chcr & 0x0fffffff) | (id << 28) | 0x100;
            if (!VB_IS_IN_REGION(index_next, f->dmaStart, f->dmaN, f->n)) {
                f->dmaStart = index_next;
                f->dmaN++;
            }
        }
    }

    if (f->env.d3madr && f->env.d3qwc) {
        *(volatile u_int *)0x1000b010 = f->env.d3madr;
        *(volatile u_int *)0x1000b020 = f->env.d3qwc;
        d3chcr = f->env.d3chcr | 0x100;
        DIntr();
        *(volatile u_int *)0x1000f590 = *(volatile u_int *)0x1000f520 | 0x10000;
        *(volatile u_int *)0x1000b000 = d3chcr;
        *(volatile u_int *)0x1000f590 = *(volatile u_int *)0x1000f520 & ~0x10000;
        EIntr();
    }
    if (f->dmaN) {
        while (*(volatile int *)0x10002010 < 0)
            ;
        *(volatile u_int *)0x10002000 = bp;
        while (*(volatile int *)0x10002010 < 0)
            ;
    }
    *(volatile u_int *)0x1000b410 = d4madr_next;
    *(volatile u_int *)0x1000b430 = d4tadr_next;
    *(volatile u_int *)0x1000b420 = d4qwc_next;
    if (f->dmaN) {
        DIntr();
        *(volatile u_int *)0x1000f590 = *(volatile u_int *)0x1000f520 | 0x10000;
        *(volatile u_int *)0x1000b400 = d4chcr_next;
        *(volatile u_int *)0x1000f590 = *(volatile u_int *)0x1000f520 & ~0x10000;
        EIntr();
    }
    *(volatile u_int *)0x10002010 = f->env.ipuctrl;
    f->isActive = 1;
    SignalSema(f->sema);
    return 1;
}

u32 viBufDelete(u32 *a0 /* r4 */) {
    u32 s0;
    u32 v0;
    u32 v1;
    u32 a1;

    s0 = (u32)a0;
    DIntr();
    a1 = *(u32 *)0x1000f520;
    a0 = (u32 *)0x10000;
    v1 = 5;
    v0 = 0xfffeffff;
    a0 = (u32 *)(a1 | 0x10000);
    *(u32 *)0x1000f590 = (u32)a0;
    *(u32 *)0x1000b400 = 5;
    v1 = *(u32 *)0x1000f520;
    v0 = v1 & 0xfffeffff;
    *(u32 *)0x1000f590 = v0;
    EIntr();
    *(u32 *)0x1000b420 = 0;
    *(u32 *)0x1000b410 = 0;
    *(u32 *)0x1000b430 = 0;
    a0 = (u32 *)*(u32 *)((s0 + 0x40));
    DeleteSema(a0);
    v0 = 1;
    return v0;
}

/* viBufCount @ 0x199CD0 .. 0x199D14 (0x44 bytes, frame 0x20) */

u32 viBufCount(u32 *a0 /* r4 */) {
    u32 s0;
    u32 a0_scalar; // a0
    u32 v1;
    u32 v0;

    s0 = (u32)a0;
    a0_scalar = (s32)a0[0x10];
    WaitSema(a0_scalar);
    v1 = *(s32 *)(((u32)s0 + 0x10));
    v0 = *(s32 *)((s0 + 0x14));
    a0_scalar = *(s32 *)(((u32)s0 + 0x40));
    s0 = v0 + (u32)(v1 << 0xb);
    SignalSema(a0_scalar);
    return s0;
}

void viBufFlush(u32 *a0 /* r4 */) {
    u32 *s0;
    u32 v1;
    u32 v0;

    s0 = a0;
    a0 = (u32 *)*(s32 *)(((u8 *)a0 + 0x40));
    WaitSema((s32)a0);
    v1 = *(s32 *)(((u8 *)s0 + 0x14));
    v0 = -0x800;
    *(u32 *)(((u8 *)s0 + 0x14)) = (u32)(v1 + 0x7ff) & v0;
    a0 = (u32 *)*(s32 *)(((u8 *)s0 + 0x40));
    SignalSema((s32)a0);
    return;
}
u32 viBufPutTs(s32 buffer, u8 *timestamp)
{
    s32 result;
    u8 *saved;
    M24Timestamp *ts;
    u32 index;
    result = 0;
    saved = (u8 *)buffer;
    ts = (M24Timestamp *)timestamp;
    WaitSema(*(s32 *)(saved + 0x40));
    if (*(s32 *)(saved + 0x58) < *(s32 *)(saved + 0x54)) {
        viBufModifyPts((u32)saved, (u8 *)ts);
        if (ts->pts >= 0 || ts->dts >= 0) {
            *(s64 *)(*(u32 *)(saved + 0x50) + *(s32 *)(saved + 0x5c) * 24) = ts->pts;
            {
                u32 offset;
                s64 dts;
                M24TableEntry *table;
                offset = *(s32 *)(saved + 0x5c);
                table = (M24TableEntry *)*(u32 *)(saved + 0x50);
                dts = ts->dts;
                table[offset].dts = dts;
            }
            {
                M24TableEntry *table;
                index = *(s32 *)(saved + 0x5c);
                table = (M24TableEntry *)*(u32 *)(saved + 0x50);
                timestamp = (u8 *)ts->position;
                table[index].position = (s32)timestamp;
            }
            {
                s32 offset;
                M24TableEntry *table;
                offset = *(s32 *)(saved + 0x5c);
                table = (M24TableEntry *)*(u32 *)(saved + 0x50);
                timestamp = (u8 *)ts->length;
                table[offset].length = (s32)timestamp;
            }
            (*(s32 *)(saved + 0x58))++;
            index = *(s32 *)(saved + 0x5c) + 1;
            *(s32 *)(saved + 0x5c) = (s32)index % *(s32 *)(saved + 0x54);
        }
        result = 1;
    }
    SignalSema(*(s32 *)(saved + 0x40));
    return result;
}

u32 viBufGetTs(s32 buffer, u8 *timestamp) {
    u32 gsB;
    u32 gsA;
    u8 *saved;
    GtTs *ts;
    s32 found;
    s32 raw;
    u32 p;
    s32 q;
    s32 mod;
    s32 num;
    s32 i;
    s32 diff;
    u32 target;
    u32 base;
    s32 idx;
    GtEnt *entry;

    saved = (u8 *)buffer;
    ts = (GtTs *)timestamp;
    gsB = *(volatile s32 *)0x1000b410;
    gsA = *(volatile s32 *)0x10002020;
    found = 0;
    WaitSema(*(s32 *)(saved + 0x40));
    raw = *(volatile s32 *)(saved + 0x38);
    mod = *(s32 *)(saved + 8) << 11;
    ts->gt_pts = -1;
    ts->gt_dts = -1;
    p = gsA >> 16;
    q = gsA >> 8;
    p = p & 3;
    q = q & 0xf;
    q = p + q;
    q = q << 4;
    p = gsB - q;
    q = raw & 0x7f;
    q = q >> 3;
    q = p + q;
    base = mod + q;
    target = (base - *(u32 *)saved) % (u32)mod;
    target = target + mod;
    num = *(s32 *)(saved + 0x58);
    diff = *(s32 *)(saved + 0x5c);
    diff = diff - num;
    for (i = 0; i < num && found == 0; i++) {
        idx = (i + (*(s32 *)(saved + 0x54) + diff)) % *(s32 *)(saved + 0x54);
        entry = (GtEnt *)(*(s32 *)(saved + 0x50) + idx * 24);
        if ((s32)(target - entry->gt_pos) % mod < entry->gt_len) {
            ts->gt_pts = entry->gt_pts;
            ts->gt_dts = ((GtEnt *)(*(s32 *)(saved + 0x50) + idx * 24))->gt_dts;
            ((GtEnt *)(*(s32 *)(saved + 0x50) + idx * 24))->gt_pts = -1;
            ((GtEnt *)(*(s32 *)(saved + 0x50) + idx * 24))->gt_dts = -1;
            found = 1;
            *(s32 *)(saved + 0x58) -= (*(s32 *)(saved + 0x58) > 1) ? 1 : *(s32 *)(saved + 0x58);
        }
    }
    SignalSema(*(s32 *)(saved + 0x40));
    return 1;
}


/* strFileInit @ 0x199980 .. 0x199990 (0x10 bytes) */

u32 strFileInit(u32 *a0 /* r4 */) {
    u32 v0;

    *(u32 *)(((u8 *)a0 + 0x38)) = 0;
    v0 = 1;
    *(u32 *)(((u8 *)a0 + 0x30)) = 0;
    return v0;
}


u32 strFileOpen(u8 *fp, char *path) {
    char *colon;
    int len;
    int i;
    int n;
    char *c;
    char name[256];
    u8 dev_[64] __attribute__((aligned(16)));
#define dev ((char *)dev_)
    u8 cdres[4];

    colon = (char *)index(path, ':');
    len = colon - path;
    if (colon != 0) {
        strncpy(dev, path, len);
        dev[len] = 0;
        if (strcmp(dev, "cdrom0\0") == 0) {
            n = strlen(colon + 1);
            *(u32 *)fp = 1;
            for (i = 0; i < n; i++) {
                c = colon + i + 1;
                if (*c == '/') {
                    *c = '\\';
                }
                *c = toupper(*c);
            }
            sprintf(name, "%s%s\0\0\0", colon + 1, index(path, ';') != 0 ? "\0\0\0\0\0\0\0" : ";1\0\0\0\0\0");
        } else {
            *(u32 *)fp = 0;
            sprintf(name, "%s:%s\0\0", dev, colon + 1);
        }
    } else {
        strcpy(dev, "host0\0\0");
        *(u32 *)fp = 0;
        sprintf(name, "%s:%s\0\0", dev, path);
    }
    if (*(s32 *)fp != 0) {
        if (*(s32 *)(fp + 0x38) == 0) {
            sceCdDiskReady(0);
            *(s32 *)(fp + 0x30) = sceSifAllocSysMemory(0, 0x28010, 0);
            if (*(s32 *)(fp + 0x30) == 0) {
                return 0;
            }
            sceCdStInit(0x50, 5, (*(s32 *)(fp + 0x30) + 0xf) & -0x10);
            *(u32 *)(fp + 0x38) = 1;
        }
        if (sceCdSearchFile(fp + 8, name) == 0) {
            return 0;
        }
        *(u32 *)(fp + 4) = *(s32 *)(fp + 0xc);
        *(u32 *)(fp + 0x2c) = *(s32 *)(fp + 8);
        cdres[0] = 0;
        cdres[1] = 0;
        cdres[2] = 0;
        sceCdStStart(*(s32 *)(fp + 8), cdres);
    } else {
        if (*(s32 *)(fp + 0x38) == 0) {
            *(s32 *)(fp + 0x30) = sceSifAllocSysMemory(0, 0x28010, 0);
            if (*(s32 *)(fp + 0x30) == 0) {
                return 0;
            }
            *(u32 *)(fp + 0x38) = 1;
        }
        *(s32 *)(fp + 0x34) = sceOpen(name, 1);
        if (*(s32 *)(fp + 0x34) < 0) {
            return 0;
        }
        *(s32 *)(fp + 4) = sceLseek(*(s32 *)(fp + 0x34), 0, 2);
        if (*(s32 *)(fp + 4) < 0) {
            sceClose(*(s32 *)(fp + 0x34));
            return 0;
        }
        if (sceLseek(*(s32 *)(fp + 0x34), 0, 0) < 0) {
            sceClose(*(s32 *)(fp + 0x34));
            return 0;
        }
    }
    return 1;
}

u32 strFileClose(u32 *a0 /* r4 */) {
    u32 v0;
    u32 s0;

    v0 = *(u32 *)a0;
    s0 = (u32)a0;
    if (v0 != 0) {
        sceCdStStop(a0);
    } else {
        a0 = (u32 *)*(u32 *)((s0 + 0x34));
        sceClose(a0);
    }
    a0 = (u32 *)*(u32 *)((s0 + 0x30));
    if ((u32)(a0) != 0) {
        sceSifFreeIopHeap(a0);
        *(u32 *)((s0 + 0x30)) = 0;
    }
    v0 = 1;
    return v0;
}

u32 strFileRead(u32 *a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */) {
    s32 s3;
    s32 s2;
    s32 s1;
    u32 s0;
    s32 s4;
    s32 s5;
    s32 s6;
    u32 v1;
    u32 v0;
    u32 *a0_2;
    s32 a1_2;
    s32 a2_2;
    u8 stackFrame_8C[4] __attribute__((aligned(1)));
    u8 stackFrame_88[4] __attribute__((aligned(1)));
    u8 stackFrame_86[2] __attribute__((aligned(1)));
    u8 stackFrame_85[1] __attribute__((aligned(1)));
    u8 stackFrame_84[1] __attribute__((aligned(4)));

    s5 = a1;
    v0 = *(s32 *)a0;
    s1 = (s32)a0;
    if (v0 != 0) {
        s6 = a2 >> 0xb;
        s3 = (s32)&stackFrame_85[0];
        s2 = (s32)&stackFrame_86[0];
        do {
            a0_2 = (u32 *)s6;
            a1_2 = s5;
            a2_2 = 1;
            v0 = sceCdStRead((unsigned int)a0_2, (void *)a1_2, a2_2, (void *)(u8 *)((u8
                *)&stackFrame_8C[0]));
            v1 = *(s32 *)((u8 *)&stackFrame_8C[0]);
            s0 = v0;
            switch (v1) {
            case 32:
                *(u32 *)((u8 *)&stackFrame_8C[0]) = 0;
                s0 = 0;
                break;
            case 49:
                s4 = 0;
                do {
                    v1 = *(s32 *)(s1 + 0x3c);
                    if (v1 != 0 && (u32)s4 >= (u32)0xf) {
                        v0 = g_mpg_vblankCount;
                        a0_2 = (u32 *)((s32)v0 >> 1);
                        ((void (*)(s32))(s32)v1)((s32)a0_2);
                    }
                    s4 = s4 + 1;
                    do {
                        v0 = sceGsSyncV(0);
                    } while (v0 != 0);
                    v0 = g_mpg_oddeven;
                    if (v0 == 0) {
                        v0 = g_mpg_vblankCount;
                        mpg_ChangeDrawEnv((u8 *)((s32)v0 >> 1));
                    }
                    a0_2 = (u32 *)(s32)1;
                    v0 = sceCdDiskReady((int)a0_2);
                    v1 = 6;
                } while (v0 == v1);
                do {
                    a0_2 = (u32 *)*(s32 *)(s1 + 0x2c);
                    v0 = sceCdStSeekF(a0_2);
                    v0 = v0 != 0;
                    v0 = v0 ^ 1;
                } while (v0 != 0);
                break;
            case 253:
            case 254:
                a0_2 = (u32 *)(s32)2;
                *(u32 *)((u8 *)&stackFrame_88[0]) = 0;
                sceCdTrayReq(a0_2, ((u8 *)&stackFrame_88[0]));
                v0 = *(s32 *)((u8 *)&stackFrame_88[0]);
                s4 = 0;
                if (v0 == 0) {
                    break;
                }
                do {
                    v1 = *(s32 *)(s1 + 0x3c);
                    if (v1 != 0 && (u32)s4 >= (u32)0xf) {
                        v0 = g_mpg_vblankCount;
                        a0_2 = (u32 *)((s32)v0 >> 1);
                        ((void (*)(s32))(s32)v1)((s32)a0_2);
                    }
                    s4 = s4 + 1;
                    do {
                        v0 = sceGsSyncV(0);
                    } while (v0 != 0);
                    v0 = g_mpg_oddeven;
                    if (v0 == 0) {
                        v0 = g_mpg_vblankCount;
                        mpg_ChangeDrawEnv((u8 *)((s32)v0 >> 1));
                    }
                    a0_2 = (u32 *)(s32)1;
                    v0 = sceCdDiskReady((int)a0_2);
                    v1 = 6;
                } while (v0 == v1);
                do {
                    a0_2 = (u32 *)*(s32 *)(s1 + 0x2c);
                    v0 = sceCdStSeekF(a0_2);
                    v0 = v0 != 0;
                    v0 = v0 ^ 1;
                } while (v0 != 0);
                break;
            default:
                a0_2 = (u32 *)(s32)1;
                if (v1 == (u32)(s32)a0_2) {
                    do {
                        v0 = sceCdStStop();
                        v0 = v0 != 0;
                        v0 = v0 ^ 1;
                    } while (v0 != 0);
                    *(u8 *)((u8 *)&stackFrame_84[0]) = 0;
                    *(u8 *)s3 = 0;
                    *(u8 *)s2 = 0;
                    do {
                        a0_2 = (u32 *)*(s32 *)(s1 + 0x2c);
                        v0 = sceCdStStart((unsigned int)a0_2, (void *)((u8 *)&stackFrame_84[0]));
                        v0 = v0 != 0;
                        v0 = v0 ^ 1;
                    } while (v0 != 0);
                    break;
                } else {
                    sceCdDiskReady((int)a0_2);
                    do {
                        a0_2 = (u32 *)*(s32 *)(s1 + 0x2c);
                        v0 = sceCdStSeekF(a0_2);
                        v0 = v0 != 0;
                        v0 = v0 ^ 1;
                    } while (v0 != 0);
                }
            case 0:
                break;
            }
            v0 = *(s32 *)((u8 *)&stackFrame_8C[0]);
        } while (v0 != 0);
        v0 = (*(s32 *)(s1 + 0x2c) += s0);
        s0 = s0 << 0xb;
    } else {
        a0_2 = (u32 *)*(s32 *)(s1 + 0x34);
        v0 = sceRead((int)a0_2, (void *)s5, a2);
        s0 = v0;
    }
    v0 = s0;
    return v0;
}

/* readBufCreate @ 0x1992D0 .. 0x1992FC (0x2c bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 readBufCreate(u32 *a0 /* r4 */) {
    a0[0x1c001] = 0;
    a0[0x1c000] = 0;
    a0[0x1c002] = 0x70000;
    return;
}

/* readBufDelete @ 0x1992C0 .. 0x1992C8 (0x8 bytes) */

void readBufDelete(u32 *unused /* r4 */) {
    return;
}

/* readBufBeginPut @ 0x199280 .. 0x1992C0 (0x40 bytes) */

u32 readBufBeginPut(u32 *a0 /* r4 */, u32 *a1 /* r5 */) {
    u32 v1;
    u32 v0;

    v1 = *(s32 *)(a0 + 0x1c002);
    v0 = *(s32 *)(a0 + 0x1c001);
    {
        u32 dcomp_tmp_0;
        dcomp_tmp_0 = v1 - v0;
        v0 = dcomp_tmp_0;
    }
    if (v0 != 0) {
        v1 = *(s32 *)(a0 + 0x1c000);
        *(u32 *)a1 = (s32)((u8 *)a0 + v1);
    }
    return v0;
}

/* readBufEndPut @ 0x199200 .. 0x199280 (0x80 bytes) */

u32 readBufEndPut(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 a2;
    u32 v1;
    s32 at;
    u32 v0;

    a2 = *(s32 *)(a0 + 0x1c002);
    v0 = *(s32 *)(a0 + 0x1c001);
    {
        u32 _dcomp_scalar_value;
        _dcomp_scalar_value = a2 - v0;
        v0 = _dcomp_scalar_value;
    }
    v0 = (s32)v0 < a1 ? v0 : a1;
    v1 = *(s32 *)(a0 + 0x1c000);
    v1 = v1 + v0;
    v1 = (s32)v1 % (s32)a2;
    a0[0x1c000] = v1;
    v1 = *(s32 *)(a0 + 0x1c001);
    at = 0x70000;
    v1 = v1 + v0;
    a0[0x1c001] = v1;
    return v0;
}

/* readBufBeginGet @ 0x1991A0 .. 0x1991F8 (0x58 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1991f4 computes the return value
 */

u32 readBufBeginGet(u32 *a0 /* r4 */, u32 *a1 /* r5 */) {
    u32 a2;
    u32 v1;
    u32 v0;

    a2 = *(s32 *)(a0 + 0x1c001);
    if (a2 != 0) {
        v1 = *(s32 *)(a0 + 0x1c002);
        v0 = *(s32 *)(a0 + 0x1c000);
        v0 = v0 - a2;
        v0 = v1 + (u32)v0;
        v0 = (s32)v0 % (s32)v1;
        *(u32 *)a1 = (s32)((u8 *)a0 + v0);
    }
    return *(s32 *)(a0 + 0x1c001);
}


/* readBufEndGet @ 0x199150 .. 0x199198 (0x48 bytes) */

u32 readBufEndGet(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 v0;
    s32 at;

    v0 = *(s32 *)(a0 + 0x1c001);
    v0 = (s32)v0 < a1 ? v0 : a1;
    at = 0x70000;
    a0[0x1c001] -= v0;
    return v0;
}
u32 mpg_videoCallback(s32 unused,u32 *packet,u8 *ring) {
extern void *memcpy(void *,const void *,unsigned int);
    u32 second;
    s32 extra;
    u32 ringBase;
    s32 first;
    s32 remaining;
    u32 destination;
    s32 total;
    u32 source;
    s32 capacity;
    u8 *firstBuffer;
    u8 *secondBuffer;
    s32 firstSize;
    s32 secondSize;
    ringBase=(u32)ring;
    source=packet[2];
    first=(u32)(ring+*(s32 *)(ring+0x70008))-source;
    first=(u32)first<packet[3]?first:packet[3];
    remaining=packet[3]-first;
    videoDecBeginPut((s32 *)mpg_GetVideoDec(),&firstBuffer,&firstSize,&secondBuffer,&secondSize);
    total=first+remaining;
    capacity=firstSize;
    destination=((u32)firstBuffer&0xfffffff)|0x20000000;
    second=((u32)secondBuffer&0xfffffff)|0x20000000;
    if(capacity+secondSize<total) total=0;
    else if(first>=capacity) {
        memcpy((void *)destination,(void *)source,capacity);
        memcpy((void *)second,(void *)(source+capacity),first-capacity);
        memcpy((void *)(second+first-capacity),(void *)ringBase,remaining);
    } else {
        extra=capacity-first;
        if(remaining>=extra) {
            memcpy((void *)destination,(void *)source,first);
            memcpy((void *)(destination+first),(void *)ringBase,extra);
            memcpy((void *)second,(void *)(ringBase+capacity-first),remaining-extra);
        } else {
            memcpy((void *)destination,(void *)source,first);
            memcpy((void *)(destination+first),(void *)ringBase,remaining);
        }
    }
    if(total>0) videoDecPutTs((u32 *)mpg_GetVideoDec(),*(u64 *)((u8 *)packet+16),*(u64 *)((u8 *)packet+24),(s32)firstBuffer,total);
    videoDecEndPut((u8 *)mpg_GetVideoDec(),total);
    return total>0;
}


/* mpg_pcmCallback @ 0x198DA0 .. 0x198F58 (0x1b8 bytes, frame 0xb0) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0xac escapes at 0x198e24
 *   stack: address of the slot at 0xa4 escapes at 0x198e24
 *   stack: address of the slot at 0xa8 escapes at 0x198e24
 *   stack: address of the slot at 0xa0 escapes at 0x198e24
 */

u32 mpg_pcmCallback(u32 a0 /* r4 */, u32 *a1 /* r5 */, u8 *a2 /* r6 */) {
    s32 at;
    s32 len;
    s32 fp;
    s32 s7;
    u32 s6;
    u32 s5;
    s32 v1;
    u32 v0;
    u32 s4;
    s32 s3;
    u32 s2;
    s32 s1;
    u32 s0;
    u8 stackFrame_AC[4] __attribute__((aligned(4)));
    u8 stackFrame_A8[4] __attribute__((aligned(4)));
    u8 stackFrame_A4[4] __attribute__((aligned(4)));
    u8 stackFrame_A0[4] __attribute__((aligned(16)));

    at = 0x70000;
    at = (s32)(a2 + 0x70000);
    s4 = a1[2] + 4;
    a0 = *(s32 *)(a2 + 0x70008);
    v1 = (s32)(a2 + a0);
    s5 = (u32)a2;
    if ((u32)(s4 < (u32)v1) == 0) {
        s4 = s4 - a0;
    }
    len = (s32)a1[3] - 4;
    s1 = v1 - s4;
    s1 = s1 < len ? s1 : len;
    s3 = len - s1;
    v0 = mpg_GetAudioDec();
    mpg_audioDecBeginPut((u32 *)v0, (u32 *)((u8 *)&stackFrame_AC[0]), (u32 *)((u8
        *)&stackFrame_A4[0]), (u32 *)(u8 *)((u8 *)&stackFrame_A8[0]), (u32 *)(u8 *)((u8
        *)&stackFrame_A0[0]));
    s0 = *(s32 *)((u8 *)&stackFrame_A4[0]);
    s6 = s1 + s3;
    v0 = *(s32 *)((u8 *)&stackFrame_A0[0]);
    fp = *(s32 *)((u8 *)&stackFrame_A8[0]);
    s2 = *(s32 *)((u8 *)&stackFrame_AC[0]);
    if ((s32)(s0 + v0) < (s32)s6) {
        s6 = 0;
    } else if ((u32)(s1 < (s32)s0) == 0) {
        memcpy(s2, s4, s0);
        memcpy((u32)fp, (u32)(s4 + s0), (u32)(s1 - s0));
        memcpy((u32)((u32)(fp + s1) - s0), s5, (u32)s3);
    } else {
        s7 = s0 - s1;
        if ((u32)(s3 < s7) == 0) {
            memcpy(s2, s4, (u32)s1);
            memcpy((u32)(s2 + s1), s5, (u32)s7);
            memcpy((u32)fp, (u32)((u32)(s5 + s0) - s1), (u32)(s3 - s7));
        } else {
            memcpy(s2, s4, (u32)s1);
            memcpy((u32)(s2 + s1), s5, (u32)s3);
        }
    }
    v0 = mpg_GetAudioDec();
    mpg_audioDecEndPut(v0, s6);
    return (s32)s6 > 0;
}
u32 mpg_dataCallback(u32 unused, u32 *packet, u8 *ring) {
    s32 remaining;
    u32 written;
    s32 ringBase;
    u32 decoder;
    u32 source;
    u32 end;
    s32 count;
    s32 second;
    u32 destination;
    s32 first;
    s32 capacity;
    u32 dstFirst;
    u32 dstSecond;
    s32 sizeFirst;
    s32 sizeSecond;
    u32 savedSecond __attribute__((aligned(16)));
    source = packet[2] + 4;
    unused = *(s32 *)(ring + 0x70008);
    end = (u32)ring + unused;
    ringBase = (u32)ring;
    if (!(source < end)) source -= unused;
    count = packet[3] - 4;
    first = end - source;
    first = first < count ? first : count;
    second = count - first;
    decoder = mpg_GetDigitalAudioDec();
    if (decoder != 0) {
        mpg_audioDecBeginPut((u32 *)decoder, &dstFirst, (u32 *)&sizeFirst, &dstSecond, (u32 *)&sizeSecond);
        savedSecond = dstSecond;
        written = first + second;
        capacity = sizeFirst;
        destination = dstFirst;
        if (capacity + sizeSecond < (s32)written) {
            written = 0;
        } else if (!(first < capacity)) {
            memcpy(destination, source, capacity);
            memcpy(savedSecond, source + capacity, first - capacity);
            memcpy(savedSecond + first - capacity, ringBase, second);
        } else {
            remaining = capacity - first;
            if (!(second < remaining)) {
                memcpy(destination, source, first);
                memcpy(destination + first, ringBase, remaining);
                memcpy(savedSecond, ringBase + capacity - first, second - remaining);
            } else {
                memcpy(destination, source, first);
                memcpy(destination + first, ringBase, second);
            }
        }
        mpg_audioDecEndPut(decoder, written);
    }
    if (decoder != 0) return (s32)written > 0;
    return 1;
}

/* mpg_CallRegisteredFunc @ 0x198B90 .. 0x198BBC (0x2c bytes, frame 0x10) */

void mpg_CallRegisteredFunc(void) {
    u32 v1;

    v1 = s_pfCallback;
    if (v1 != 0) {
        ((void (*)(void))(s32)v1)();
    }
    return;
}

void mpg_RegisterCallBack(s32 a0 /* r4 */) {
    s_pfCallback = a0;
    return;
}

void mpg_CallRegisteredVSyncIntrFunc() {
    u32 v1;

    v1 = s_pfVSyncCallback;
    if (v1 != 0) {
        ((void (*)(void))(s32)v1)();
    }
    return;
}

/* mpg_GetFadeColorPtr @ 0x198B20 .. 0x198B4C (0x2c bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x198b28 writes a register its branch at 0x198b24 reads
 */

u32 mpg_GetFadeColorPtr(s32 a0 /* r4 */, s32 a1 /* r5 */) {
    u32 v0;

    v0 = s_isInit;
    return v0 != 0 ? (s32)((s32)((s32)(s_pMpgMng + (s32)((u32)a0 * (u32)(8))) + (s32)((u32)a1 *
        (u32)(4))) + 0x208) : 0;
}

/* mpg_GetVideoDec @ 0x198B00 .. 0x198B1C (0x1c bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x198b08 writes a register its branch at 0x198b04 reads
 */

u32 mpg_GetVideoDec(void) {
    u32 v0;

    v0 = s_isInit;
    if (v0 != 0) {
        v0 = s_pMpgMng;
        return v0 + 0x40;
    }
    return 0;
}

/* mpg_GetAudioDec @ 0x198AE0 .. 0x198AFC (0x1c bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x198ae8 writes a register its branch at 0x198ae4 reads
 */

u32 mpg_GetAudioDec(void) {
    u32 v0;

    v0 = s_isInit;
    if (v0 != 0) {
        v0 = s_pMpgMng;
        return v0 + 0xf8;
    }
    return 0;
}

/* mpg_GetDigitalAudioDec @ 0x198AA0 .. 0x198AD8 (0x38 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x198aa8 writes a register its branch at 0x198aa4 reads
 *   delay: daddu at 0x198ac4 writes a register its branch at 0x198ac0 reads
 */

u32 mpg_GetDigitalAudioDec(void) {
    u32 v0;
    u16 *v1;

    v0 = s_isInit;
    if (v0 == 0) {
        return 0;
    }
    v1 = (u16 *)s_pMpgMng;
    v0 = *(u16 *)(((u8 *)v1 + 0xe));
    if (v0 != 0) {
        v0 = (s32)((u8 *)v1 + 0x16c);
    } else {
        v0 = 0;
    }
    return v0;
}

/* mpg_GetDBuff @ 0x198A80 .. 0x198A9C (0x1c bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x198a88 writes a register its branch at 0x198a84 reads
 */

u32 mpg_GetDBuff(void) {
    u32 v0;

    v0 = s_isInit;
    if (v0 != 0) {
        v0 = s_pMpgMng;
        v0 = *(s32 *)((v0 + 0x204));
        return v0;
    }
    return 0;
}


/* mpg_GetVoBuff @ 0x198A60 .. 0x198A7C (0x1c bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x198a68 writes a register its branch at 0x198a64 reads
 */

u32 mpg_GetVoBuff(void) {
    u32 v0;

    v0 = s_isInit;
    if (v0 != 0) {
        v0 = s_pMpgMng;
        return v0 + 0x1e0;
    }
    return 0;
}



void _updateFadeColor(void) {
    u32 a3;
    u8 *q;
    u32 a2;
    u8 *a1;
    u32 a0;
    u32 v1;
    u64 v0_64;
    u64 v1_64;
    u32 v0;

    a1 = (u8 *)s_pMpgMng;
    v1 = *(s32 *)(a1 + 0x230);
    if (v1 != 0) {
        a0 = *(s32 *)(a1 + 0x22c);
        if (a0 == 0) {
            v0 = 0x80;
            a2 = 0;
            *(u8 *)(a1 + 0x21b) = v0;
            a1 = (u8 *)s_pMpgMng;
            a0 = (s32)(a1 + 0x218);
            do {
                v1 = *(s32 *)(a1 + 0x208);
                if (v1 != 0 && (u32)*(s32 *)(a1 + 0x20c) != 0) {
                    v0_64 = *(u64 *)a0;
                    *(u64 *)v1 = v0_64;
                    v1_64 = *(u64 *)a0;
                    v0 = *(s32 *)(a1 + 0x20c);
                    *(u64 *)v0 = v1_64;
                }
                a2 = a2 + 1;
                v0 = (s32)a2 < (s32)2;
                a1 = (u8 *)(a1 + 8);
            } while (v0 != 0);
            mpg_audioDecChangeVolume(0);
        } else {
            v1 = *(s32 *)(a1 + 0x48);
            v0 = *(s32 *)(a1 + 0x228);
            a3 = v1 - v0;
            if ((s32)a3 < 0) {
                a3 = 0;
            }
            v0 = a3 << 7;
            v0 = (s32)v0 / (s32)a0;
            a0 = 0;
            *(u8 *)(a1 + 0x21b) = v0;
            q = (u8 *)s_pMpgMng;
            a1 = (u8 *)(s32)(q + 0x218);
            do {
                v1 = *(s32 *)(q + 0x208);
                if (v1 != 0 && (u32)*(s32 *)(q + 0x20c) != 0) {
                    v0_64 = *(u64 *)a1;
                    *(u64 *)v1 = v0_64;
                    v1_64 = *(u64 *)a1;
                    v0 = *(s32 *)(q + 0x20c);
                    *(u64 *)v0 = v1_64;
                }
                a0 = a0 + 1;
                v0 = (s32)a0 < (s32)2;
                q = q + 8;
            } while (v0 != 0);
            v0 = s_pMpgMng;
            a0 = *(s32 *)((v0 + 0x22c));
            mpg_audioDecChangeVolume((*(s32 *)(v0 + 0x234) * (s32)(a0 - a3)) / (s32)a0);
        }
    }
    return;
}

u32 mpg_SetDefPrio(s32 a0 /* r4 */) {
    u32 v1;
    u32 *a2;
    u32 a1;

    v1 = s_isInit;
    if (v1 != 0) {
        a2 = (u32 *)s_pMpgMng;
        a1 = -1;
        v1 = *(u32 *)(((u8 *)a2 + 0x1f8));
        if (v1 == a1) {
            v1 = *(u32 *)(((u8 *)a2 + 0x1f4));
            if (v1 == a1) {
                *(u32 *)a2 = a0;
            }
        }
    }
    return;
}


/* mpg_GetRequiredBufferSize @ 0x198870 .. 0x1988D0 (0x60 bytes) */

u32 mpg_GetRequiredBufferSize(u32 a0 /* r4 */, s32 a1 /* r5 */) {
    u32 a0_word = a0;
    s32 v1;
    s32 v0;

    a0_word = (u16)a0_word;
    v0 = 0;
    if (a0_word == (u32)2) {
        v0 = 0x4dea40;
        if ((u32)a1 != 0) {
            v1 = 0x24000;
            v0 = v0 + 0x24000;
        }
    } else if (a0_word == (u32)3) {
        v0 = 0x5b0a40;
        if ((u32)a1 != 0) {
            v1 = 0x24000;
            v0 = v0 + 0x24000;
        }
    }
    return v0;
}

u32 mpg_InitPss(u32 buf, u32 size, u32 mode, u32 p4, u32 p5, u32 p6, u32 p7, u32 hasAudio) {
    u8 *p;

    if (s_isInit != 0) {
        return 1;
    }
    if ((u16)mode == 3) {
        g_MPG_MAX_WIDTH = 640;
        *(u32 *)g_MPG_DISP_WIDTH = 640;
        g_MPG_MAX_HEIGHT = 544;
        *(u32 *)g_MPG_DISP_HEIGHT = 544;
    } else if ((u16)mode == 2) {
        g_MPG_MAX_WIDTH = 640;
        *(u32 *)g_MPG_DISP_WIDTH = 640;
        g_MPG_MAX_HEIGHT = 448;
        *(u32 *)g_MPG_DISP_HEIGHT = 448;
    } else {
        return 0;
    }
    if (buf == 0) {
        return 0;
    }
    if ((s32)size < (s32)mpg_GetRequiredBufferSize(mode, hasAudio)) {
        return 0;
    }
    p = (u8 *)((buf + 63) & ~63);
    s_pMpgMng = (u32)p;
    p += 0x240;
    MP_MNG->field_10 = (u32)(p);
    p += (g_MPG_MAX_WIDTH * g_MPG_MAX_HEIGHT * 8 + 63) & ~63;
    MP_MNG->field_14 = (u32)(p);
    p += ((((((s32)g_MPG_MAX_WIDTH / 16) * (s32)g_MPG_MAX_HEIGHT / 16 * 6 + 110) * 4 + 63) & ~63) * 8 + 64) * 2 + 63 & ~63;
    MP_MNG->field_18 = (u32)(p);
    MP_MNG->field_1c = (u32)(p + 0x80000);
    MP_MNG->audioBuffer0 = (u32)(p + 0x81040);
    p += 0x8d040;
    if (hasAudio != 0) {
        MP_MNG->audioBuffer1 = (u32)(p);
        p += 0x24000;
    }
    MP_MNG->videoBufferSize = (u32)(p);
    p += ((s32)(g_MPG_MAX_WIDTH * g_MPG_MAX_HEIGHT * 9) / 2 + 0x283f) & ~63;
    MP_MNG->readBuffer = (u32)(p);
    MP_MNG->videoStack = (u32)(p + 0x70040);
    MP_MNG->audioStack = (u32)(p + 0x74040);
    MP_MNG->decoderParam = (u32)(p + 0x76040);
    MP_MNG->gsPacket = (struct MP_DBuff *)(p + 0x79040);
    MP_MNG->outputPacket = (u_long *)(p + 0x79270);
    MP_MNG->audioThreadId = -1;
    MP_MNG->videoThreadId = -1;
    MP_MNG->displayMode = mode;
    MP_MNG->state_228 = 0;
    MP_MNG->state_22c = 0;
    MP_MNG->state_230 = 0;
    MP_MNG->field_218 = p4;
    MP_MNG->field_234 = (p5 > 0x3fff) ? 0x3fff : p5;
    MP_MNG->field_04 = p6;
    MP_MNG->field_08 = p7;
    MP_MNG->defaultPriority = 1;
    MP_MNG->hasAudio = hasAudio;
    MP_MNG->mpegEnabled = 1;
    s_isInit = 1;
    sceGsResetPath();
    sceDmaReset(1);
    sceGsSyncV(0);
    sceGsResetGraph(0, 1, MP_MNG->displayMode, 0);
    clearGsMem(MP_MNG->field_14, 0, 0, 0, *(s32 *)g_MPG_DISP_WIDTH, *(s32 *)g_MPG_DISP_HEIGHT);
    sceGsSetDefDBuff(MP_MNG->gsPacket, 0, *(s16 *)g_MPG_DISP_WIDTH, *(s16 *)g_MPG_DISP_HEIGHT, 0, 0, 0);
    MP_MNG->gsPacket->disp[1].dispfb.FBP = ((g_MPG_MAX_WIDTH + 63) & ~63) * ((g_MPG_MAX_HEIGHT + 31) & ~31) >> 11;
    MP_MNG->gsPacket->disp[0].display.DX += MP_MNG->field_04 * MP_MNG->gsPacket->disp[0].display.MAGH;
    MP_MNG->gsPacket->disp[0].display.DY += MP_MNG->field_08;
    MP_MNG->gsPacket->disp[1].display.DX += MP_MNG->field_04 * MP_MNG->gsPacket->disp[1].display.MAGH;
    MP_MNG->gsPacket->disp[1].display.DY += MP_MNG->field_08;
    MP_MNG->gsPacket->draw0.frame1.FBP = ((g_MPG_MAX_WIDTH + 63) & ~63) * ((g_MPG_MAX_HEIGHT + 31) & ~31) >> 11;
    MP_MNG->gsPacket->draw0.zbuf1.ZMSK = 1;
    MP_MNG->gsPacket->draw1.zbuf1.ZMSK = 1;
    MP_MNG->outputPacket[0] = (u_long)0x8008 | ((u_long)0x10000000 << 32);
    MP_MNG->outputPacket[1] = 0xe;
    MP_MNG->state_208 = 0;
    MP_MNG->state_20c = 0;
    MP_MNG->state_210 = 0;
    MP_MNG->state_214 = 0;
    FlushCache(0);
    return 1;
}

void mpg_QuitPss(void) {
    s_isInit = 0;
    return;
}
#define PPS_MNG ((struct PpsMng *)s_pMpgMng)

u32 mpg_PlayPss(s32 size, u32 (*cbRead)(u8 *, s32), u32 (*cbAbort)(void))
{
    int readrest;
    int putrest;
    int isStarted;
    int isAborted;
    int ret;
    int proceed;
    u8 *vd;
    u8 *rb;
    int putsize;
    int getsize;
    u8 *put_ptr;
    u8 *get_ptr;

    isAborted = 0;
    isStarted = 0;
    readrest = size;
    putrest = size;
    if (s_isInit && cbRead) {
    _initAll();
    rb = PPS_MNG->rb;
    vd = PPS_MNG->vd;
    while (putrest > 4 && videoDecGetState((u32 *)vd) != 3) {
        if (cbAbort) {
            if (PPS_MNG->abortEnable && PPS_MNG->abortReady) {
                if (!PPS_MNG->aborted & cbAbort()) {
                    PPS_MNG->aborted = 1;
                    PPS_MNG->abortFrame = PPS_MNG->frame;
                }
            }
            if (PPS_MNG->aborted && PPS_MNG->abortFrame + PPS_MNG->abortDelay < PPS_MNG->frame && !isAborted) {
                videoDecAbort((u32 *)PPS_MNG->vd);
                isAborted = 1;
            }
        }
        _updateFadeColor();
        putsize = readBufBeginPut((u32 *)rb, (u32 *)&put_ptr);
        if (readrest > 0 && putsize >= 0x10000) {
            ret = cbRead(put_ptr, 0x10000);
            if (ret == 0) {
                videoDecAbort((u32 *)PPS_MNG->vd);
                break;
            }
            readBufEndPut((u32 *)rb, ret);
            readrest -= ret;
        }
        RotateThreadReadyQueue(PPS_MNG->thread);
        getsize = readBufBeginGet((u32 *)rb, (u32 *)&get_ptr);
        if (getsize > 0) {
            proceed = sceMpegDemuxPssRing(vd, get_ptr, getsize, (s32)rb, *(s32 *)(rb + 0x70008));
            readBufEndGet((u32 *)rb, proceed);
            putrest -= proceed;
        }
        mpg_audioDecSendToIOP((u32 *)PPS_MNG->ad0);
        if (PPS_MNG->stereo) {
            mpg_audioDecSendToIOP((u32 *)PPS_MNG->ad1);
        }
        if (!isStarted && voBufIsFull((u32 *)PPS_MNG->vo)) {
            int ready;

            if (PPS_MNG->audioOn) {
                if (PPS_MNG->stereo) {
                    ready = mpg_audioDecIsPreset((u32 *)PPS_MNG->ad0) && mpg_audioDecIsPreset((u32 *)PPS_MNG->ad1);
                } else {
                    ready = mpg_audioDecIsPreset((u32 *)PPS_MNG->ad0);
                }
            } else {
                ready = 1;
            }
            if (ready) {
                startDisplay(1);
                if (PPS_MNG->audioOn) {
                    mpg_audioDecStart((u32 *)PPS_MNG->ad0);
                    if (PPS_MNG->stereo) {
                        mpg_audioDecStart((u32 *)PPS_MNG->ad1);
                    }
                }
                isStarted = 1;
            }
        }
    }
    while (!videoDecFlush((u32 *)vd)) {
        RotateThreadReadyQueue(PPS_MNG->thread);
    }
    while (!videoDecIsFlushed((u32 *)vd) && videoDecGetState((u32 *)vd) != 3) {
        RotateThreadReadyQueue(PPS_MNG->thread);
    }
    endDisplay();
    if (PPS_MNG->audioOn) {
        mpg_audioDecReset((u32 *)PPS_MNG->ad0);
        if (PPS_MNG->stereo) {
            mpg_audioDecReset((u32 *)PPS_MNG->ad1);
        }
    }
    _termAll();
    return 1;
    }
    _termAll();
    return 0;
}


u32 mpg_ChangeDrawEnv(u8 *a0 /* r4 */) {
    u32 v0;
    s32 a2;
    u32 v1;
    u32 a1;

    v0 = (u32)((u32)(a0)) & 1;
    if (v0 == 0) {
        v0 = s_pMpgMng;
        a2 = 0x80;
        v1 = *(s32 *)((v0 + 0x238));
        v0 = *(s32 *)((v0 + 0x204));
        a0 = (u8 *)(s32)(v1 + 0x10);
        a1 = v0 + 0x60;
        memcpy((s32)a0, a1, a2);
    } else {
        v0 = s_pMpgMng;
        a2 = 0x80;
        v1 = *(s32 *)((v0 + 0x238));
        v0 = *(s32 *)((v0 + 0x204));
        a0 = (u8 *)(s32)(v1 + 0x10);
        a1 = v0 + 0x150;
        memcpy((s32)a0, a1, a2);
    }
    FlushCache(0);
    while (1) {
        v0 = *(volatile s32 *)0x1000a000;
        v0 = v0 & 0x100;
        if (v0 != 0) {
            continue;
        }
        v0 = *(volatile s32 *)0x10003020;
        v0 = v0 & 0xc00;
        if (v0 != 0) {
            continue;
        }
        break;
    }
    v0 = s_pMpgMng;
    a0 = (u8 *)*(s32 *)((v0 + 0x238));
    sceGsPutDrawEnv((s32)a0);
    while (1) {
        v1 = *(volatile s32 *)0x1000a000;
        v1 = v1 & 0x100;
        if (v1 != 0) {
            continue;
        }
        v1 = *(volatile s32 *)0x10003020;
        v1 = v1 & 0xc00;
        if (v1 != 0) {
            continue;
        }
        break;
    }
    return;
}

u32 mpg_SwitchThread(void) {
    u32 *v0;
    u32 a0;

    v0 = (u32 *)s_pMpgMng;
    a0 = *(s32 *)v0;
    return RotateThreadReadyQueue(a0);
}
void _initAll(void) {
    struct ThreadParamI th;
    u8 *m;

    *(volatile u32 *)0x1000e000 = *(volatile s32 *)0x1000e000 | 3;
    *(volatile u32 *)0x1000e010 = 4;
    readBufCreate(*(u32 **)(s_pMpgMng + 0x2c));
    sceMpegInit();
    m = (u8 *)s_pMpgMng;
    videoDecCreate((u32 *)(m + 0x40), *(s32 *)(m + 0x28), (u32)((s32)((u32)(g_MPG_MAX_WIDTH * g_MPG_MAX_HEIGHT) * 9) / 2) + 0x2800, *(s32 *)(m + 0x18), *(s32 *)(m + 0x1c), 0x100, *(s32 *)(m + 0x38), 0x200);
    *(u32 *)(s_pMpgMng + 0x168) = *(s32 *)(s_pMpgMng + 0x234);
    m = (u8 *)s_pMpgMng;
    mpg_audioDecCreate((u32 *)(m + 0xf8), *(u8 **)(m + 0x20), 0xc000, 0, 0x6000, 0);
    if (*(u16 *)(s_pMpgMng + 0xe) != 0) {
        *(u32 *)(s_pMpgMng + 0x1dc) = *(s32 *)(s_pMpgMng + 0x234);
        m = (u8 *)s_pMpgMng;
        mpg_audioDecCreate((u32 *)(m + 0x16c), *(u8 **)(m + 0x24), 0xc000, (s32)(*(u8 **)(m + 0x24) + 0xc000), 0xc000, 1);
    }
    videoDecSetStream((u8 *)(s_pMpgMng + 0x40), 0, 0, mpg_videoCallback, *(s32 *)(s_pMpgMng + 0x2c));
    if (*(s32 *)(s_pMpgMng + 0x200) != 0) {
        videoDecSetStream((u8 *)(s_pMpgMng + 0x40), 2, 0, mpg_pcmCallback, *(s32 *)(s_pMpgMng + 0x2c));
        videoDecSetStream((u8 *)(s_pMpgMng + 0x40), 4, 0, mpg_dataCallback, *(s32 *)(s_pMpgMng + 0x2c));
    }
    m = (u8 *)s_pMpgMng;
    voBufCreate((u32 *)(m + 0x1e0), (*(s32 *)(m + 0x10) & 0xfffffff) | 0x20000000, *(s32 *)(m + 0x14), 2);
    th.entry = (void *)mpg_DefMain;
    m = (u8 *)s_pMpgMng;
    th.stack = (void *)*(s32 *)(m + 0x34);
    th.stackSize = 0x2000;
    th.initPriority = *(s32 *)m;
    th.gpReg = &_gp;
    th.option = 0;
    *(s32 *)(s_pMpgMng + 0x1f8) = CreateThread(&th);
    StartThread(*(s32 *)(s_pMpgMng + 0x1f8), (void *)0);
    th.entry = (void *)videoDecMain;
    m = (u8 *)s_pMpgMng;
    th.stack = (void *)*(s32 *)(m + 0x30);
    th.stackSize = 0x4000;
    th.initPriority = *(s32 *)m;
    th.gpReg = &_gp;
    th.option = 0;
    *(s32 *)(s_pMpgMng + 0x1f4) = CreateThread(&th);
    StartThread(*(s32 *)(s_pMpgMng + 0x1f4), (void *)(s_pMpgMng + 0x40));
    *(u32 *)(s_pMpgMng + 0xf4) = AddIntcHandler(2, vblankHandler, 0);
    EnableIntc(2);
    *(u32 *)(s_pMpgMng + 0xf0) = AddDmacHandler(2, handler_endimage, 0);
    EnableDmac(2);
}

void clearGsMem(int pkBuf, int r, int g, int b, int w, int h)
{
    void *buf = (void *)pkBuf;
    u8 *dma;
    struct stackFrame_A0 { u8 b[16]; } tag __attribute__((aligned(16))) = {{0x00, 0x80,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
    u8 pk[16] __attribute__((aligned(16)));

    dma = (u8 *)sceDmaGetChan(2);
    *(u_long128 *)(mpg_GetDBuff() + 0x50) = (u_long128)0;
    __asm__ volatile("sync" : :  : "memory");
    ((struct { u16 nloop:15; u16 eop:1; } *)(mpg_GetDBuff() + 0x50))->nloop = 8;
    ((struct { unsigned char _pad:7; unsigned char f:1; } *)(mpg_GetDBuff() + 0x51))->f = 1;
    ((struct { unsigned char _pad:4; unsigned char f:4; } *)(mpg_GetDBuff() + 0x57))->f = 1;
    ((struct { unsigned char f:4; } *)(mpg_GetDBuff() + 0x58))->f = 0xe;
    sceGsSetDefDrawEnv(&((struct MP_DBuff *)mpg_GetDBuff())->draw0, 0, w, (u32)(((h / 2 + 0x1f) & -0x20) + ((h + 0x1f) & -0x20)) << 1, 0, 0);
    *(u64 *)(mpg_GetDBuff() + 0x80) = 0;
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsPutDrawEnv(mpg_GetDBuff() + 0x50);
    sceGifPkInit(pk, buf);
    sceGifPkReset(pk);
    sceGifPkEnd(pk, 0, 0, 0);
    sceGifPkOpenGifTag(pk, *(u_long128 *)&tag);
    sceGifPkAddGsAD(pk, 0, 6);
    sceGifPkAddGsAD(pk, 1, ((u64)b << 0x10) | ((u64)r | ((u64)g << 8)));
    sceGifPkAddGsAD(pk, 5, 0);
    { s32 hh = g_MPG_MAX_HEIGHT * 0x50; u64 hs = (u64)hh << 0x10; s32 ww = g_MPG_MAX_WIDTH << 4; sceGifPkAddGsAD(pk, 5, (u64)ww | hs); }
    sceGifPkCloseGifTag(pk);
    sceGifPkTerminate(pk);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceDmaSend(dma, (void *)((s32 *)pk)[1]);
    sceGsSyncPath(0, 0);
}

void setImageTag(s32 a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */, s32 a3 /* r7 */, s32 t0 /* r8
        */, u32 *t1 /* r9 */) {
    u32 fp;
    s32 s6;
    s32 s7;
    u64 s5;
    s32 s4;
    u32 v1;
    u32 v0;
    u32 s3;
    u_long128 a1_q;
    u32 s2;
    u32 s1;
    u32 s0;
    s32 wd;
    s32 ht;
    s32 x0;
    s32 y0;
    s32 w16;
    s32 h16;
    s32 a0_2;
    s32 a1_2;
    s32 a2_2;
    u32 *t1_2;
    u8 stackFrame_C0[16] __attribute__((aligned(16)));

    v0 = (u32)L223;
    fp = (u32)t1;
    s7 = t0 >> 4;
    s6 = a3 >> 4;
    s4 = a1;
    v1 = (u32)a0 & 0xfffffff;
    s1 = a2;
    a3 = (s32)L225;
    v0 = 0x20000000;
    {
        struct stackFrame_B0 { u8 b[16]; } stackFrame_B0 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00}};
        t1_2 = (u32 *)((u8 *)&stackFrame_B0);
        a1_2 = v1 | 0x20000000;
        {
            struct stackFrame_A0 { u8 b[16]; } stackFrame_A0 __attribute__((aligned(16))) = {{0x00,
                0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00}};
            a2_2 = (s32)((u8 *)&stackFrame_A0);
            sceGifPkInit((void *)((u8 *)&stackFrame_C0[0]), (void *)a1_2);
            sceGifPkReset((void *)((u8 *)&stackFrame_C0[0]));
            t1_2 = (u32 *)g_MPG_MAX_WIDTH;
            v1 = g_MPG_MAX_HEIGHT;
            s0 = (u32)(s32)((u8 *)t1_2 + 0x3f) & (u32)-0x40;
            s1 = s1 * (u32)((u32)(s0 * (u32)((u32)(v1 + 0x1f) & (u32)-0x20)) >> 6);
            sceGifPkCnt((void *)((u8 *)&stackFrame_C0[0]), 0, 0, 0);
            a1_q = *(u_long128 *)((u8 *)&stackFrame_B0);
            sceGifPkOpenGifTag((void *)((u8 *)&stackFrame_C0[0]), a1_q);
            sceGifPkAddGsAD((void *)((u8 *)&stackFrame_C0[0]), 0x50, (u64)((u64)(u32)s1 << 0x20) |
                (u64)((u64)(u32)(s0 >> 6) << 0x30));
            v1 = 0x10;
            sceGifPkAddGsAD((void *)((u8 *)&stackFrame_C0[0]), 0x52, (u64)((s32)((s32)v1)) |
                (u64)((u64)(u32)v1 << 0x20));
            sceGifPkCloseGifTag((void *)((u8 *)&stackFrame_C0[0]));
            s3 = 0;
            if (0 < s6) {
                s1 = 0;
                do {
                    s2 = 0;
                    if (0 < s7) {
                        s0 = 0;
                        s5 = (u64)(u32)s1 << 0x20;
                        do {
                            sceGifPkCnt((void *)((u8 *)&stackFrame_C0[0]), 0, 0, 0);
                            a1_q = *(u_long128 *)((u8 *)&stackFrame_B0);
                            sceGifPkOpenGifTag((void *)((u8 *)&stackFrame_C0[0]), a1_q);
                            sceGifPkAddGsAD((void *)((u8 *)&stackFrame_C0[0]), 0x51, s5 |
                                (u64)((u64)(u32)s0 << 0x30));
                            sceGifPkAddGsAD((void *)((u8 *)&stackFrame_C0[0]), 0x53, 0);
                            sceGifPkCloseGifTag((void *)((u8 *)&stackFrame_C0[0]));
                            v0 = (u32)sceGifPkReserve((void *)((u8 *)&stackFrame_C0[0]), 4);
                            v1 = 0x8000000;
                            a2_2 = 0x40;
                            a1_2 = (u32)s4 & 0xfffffff;
                            *(u64 *)v0 = (u64)((s32)(a2_2)) | (u64)((u64)(u32)0x8000000 << 0x20);
                            *(u64 *)(((u8 *)v0 + 8)) = 0;
                            sceGifPkRef((void *)((u8 *)&stackFrame_C0[0]), (void *)a1_2, a2_2, 0,
                                0, 0);
                            s2 = s2 + 1;
                            s4 = s4 + 0x400;
                            s0 = s0 + 0x10;
                        } while ((s32)s2 < s7);
                    }
                    s3 = s3 + 1;
                    v0 = (s32)s3 < s6;
                    s1 = s1 + 0x10;
                } while (v0 != 0);
            }
            wd = *(s32 *)g_MPG_DISP_WIDTH;
            x0 = (0x800 - wd / 2) << 4;
            ht = *(s32 *)g_MPG_DISP_HEIGHT;
            y0 = (0x800 - ht / 2) << 4;
            w16 = wd << 4;
            h16 = ht << 4;
            sceGifPkEnd((void *)((u8 *)&stackFrame_C0[0]), 0, 0, 0);
            a1_q = *(u_long128 *)((u8 *)&stackFrame_A0);
            sceGifPkOpenGifTag((void *)((u8 *)&stackFrame_C0[0]), a1_q);
            sceGifPkAddGsAD((void *)((u8 *)&stackFrame_C0[0]), 0x3f, 0);
            sceGifPkAddGsAD((void *)((u8 *)&stackFrame_C0[0]), 0x42, (s32)0x44);
            sceGifPkAddGsAD((void *)((u8 *)&stackFrame_C0[0]), 0, (s32)0x146);
            if (fp != 0) {
                v0 = *(s32 *)((u8 *)&stackFrame_C0[0]);
                *(u32 *)fp = v0 & 0xfffffff;
            }
            a1_2 = 1;
            sceGifPkAddGsAD((void *)((u8 *)&stackFrame_C0[0]), a1_2, (u64)a1_2 << 0x20);
            sceGifPkAddGsAD((void *)((u8 *)&stackFrame_C0[0]), 5, (u64)x0 | ((u64)y0 << 0x10));
            sceGifPkAddGsAD((void *)((u8 *)&stackFrame_C0[0]), 5, (u64)(x0 + w16) | ((u64)(y0 + h16) << 0x10));
            sceGifPkCloseGifTag((void *)((u8 *)&stackFrame_C0[0]));
            sceGifPkTerminate((void *)((u8 *)&stackFrame_C0[0]));
            return;
        }
    }
}

u32 vblankHandler(void) {
    s32 a1;
    s32 size;
    u32 a0;
    u32 v1;
    u32 v0_2; // v0
    u32 v0_3; // v0
    u32 v0_4; // v0
    u8 *s1;
    u64 v0_64;
    u32 *s0;
    u32 v0_5; // v0
    u32 v0;

    a0 = 2;
    v0_5 = (u32)sceDmaGetChan(a0);
    s1 = (u8 *)v0_5;
    v0_64 = *(volatile u64 *)0x12001000;
    v0_64 = v0_64 >> 0xd;
    v0 = v0_64 & (u64)(1);
    v0 = v0;
    g_mpg_oddeven = v0;
    v0 = isCountVblank;
    if (v0 != 0) {
        v0 = g_mpg_vblankCount;
        a0 = 1;
        v0 = v0 + 1;
        g_mpg_vblankCount = v0;
        v0_3 = sceGsSyncPath(a0, 0);
        handler_error = (u32)v0_3;
        v0 = handler_error;
        if (v0 != 0) {
            goto _L001973F8;
        }
        v0 = mpg_GetVoBuff();
        v0_4 = voBufGetTag(v0);
        s0 = (u32 *)v0_4;
        if ((u32)s0 == 0) {
            __asm__ volatile("sync" : :  : "memory");
            __asm__ volatile("ei" : :  : "memory");
            v0 = 0;
            goto _L00197408;
        }
        v0 = g_mpg_oddeven;
        if (v0 == 0) {
            v1 = *(s32 *)s0;
            v0 = 2;
            if (v1 == v0) {
                v0_2 = mpg_GetDBuff();
                a0 = v0_2;
                v0 = g_mpg_vblankCount;
                sceGsSwapDBuff((void *)a0, (s32)v0 >> 1);
                sceGsSyncPath(0, 0);
                v0 = g_MPG_MAX_WIDTH;
                v1 = (s32)v0 / 0x10;
                v0 = g_MPG_MAX_HEIGHT;
                size = v1 * v0;
                v1 = (s32)size / 0x10;
                v0 = v1 * 3;
                a1 = v0 * 2;
                v1 = -0x40;
                a1 = a1 + 0x6e;
                a1 = (u32)a1 << 2;
                a1 = a1 + 0x3f;
                v1 = a1 & (u32)v1;
                v0 = g_mpg_vblankCount;
                v0 = (s32)v0 >> 1;
                v0 = v0 & 1;
                v0 = v0 != 0;
                v0 = v0 ^ 1;
                v0 *= v1;
                v0 = v0 << 2;
                v0 = (s32)((u8 *)s0 + (u32)v0);
                sceDmaSend((void *)s1, (void *)(s32)(v0 + 0x40));
                *(u32 *)s0 = 0;
                v0 = 1;
                isFrameEnd = v0;
                mpg_CallRegisteredVSyncIntrFunc((s32)g_mpg_vblankCount >> 1);
            }
        }
    }
    _L001973F8:;
    __asm__ volatile("sync" : :  : "memory");
    __asm__ volatile("ei" : :  : "memory");
    v0 = 0;
    _L00197408:;
    return v0;
}

u32 handler_endimage(void) {
    u32 v0;

    v0 = isFrameEnd;
    if (v0 != 0) {
        v0 = mpg_GetVoBuff();
        voBufDecCount(v0);
        isFrameEnd = 0;
    }
    __asm__ volatile("sync" : :  : "memory");
    __asm__ volatile("ei" : :  : "memory");
    v0 = 0;
    return v0;
}

void startDisplay(s32 a0 /* r4 */) {
    u32 s0;
    u32 v0;

    s0 = a0;
    do {
        v0 = sceGsSyncV(0);
    } while (s0 == v0);
    isCountVblank = 1;
    g_mpg_vblankCount = 0;
    return;
}

void endDisplay(void) {
    isCountVblank = 0;
    return;
}

void mpg_DefMain(void) {
    while (1) {
        mpg_SwitchThread();
    }
}
u32 mpg_audioDecCreate(u32 *dec, u8 *buffer, s32 size, s32 arg, s32 allocSize, s32 mode) {
    u32 *saved = dec;
    s32 i;
    s32 savedMode = mode;
    u32 dma[4] __attribute__((aligned(16)));
    s32 volume;
    u32 enabled = 1;
    u32 result;
    dec[0] = 0;
    enabled = mode != 0 ? (enum mpg_audioDecCreate__sel)enabled : (enum mpg_audioDecCreate__sel)0;
    dec[1] = (u8)enabled;
    dec[2] = (u32)(mode != 0) ^ 1;
    dec[14] = 0;
    dec[15] = (u32)buffer;
    dec[16] = 0;
    dec[17] = 0;
    dec[18] = size;
    dec[19] = 0;
    dec[26] = 0;
    dec[20] = arg;
    dec[21] = 0;
    dec[23] = allocSize;
    dec[24] = 0;
    dec[25] = 0;
    saved[22] = sceSifAllocSysMemory(0, allocSize, 0);
    if (saved[22] == 0) result = 0;
    else {
        saved[27] = sceSifAllocSysMemory(0, 0x800, 0);
        if (saved[27] == 0) result = 0;
        else {
            memset(buffer, 0, 0x800);
            dma[1] = saved[27];
            dma[2] = 0x800;
            dma[0] = (u32)buffer;
            dma[3] = 0;
            FlushCache(0);
            i = sceSifSetDma(dma, 1);
            do {} while (sceSifDmaStat(i) >= 0);
            if (saved[1] == 0) sceSdRemote(1, 0x80d0, saved[2], 0, saved[27], 0x4800, 0x800);
            else sceSdRemote(1, 0x80d0, saved[2], 0, saved[27], 0x4000, 0x800);
            sceSdRemote(1, 0x80f0, saved[2], 0);
            volume = saved[28];
            i = 0;
            do {
                sceSdRemote(1, 0x8010, i | 0x980, volume);
                sceSdRemote(1, 0x8010, i | 0xa80, volume);
                i++;
            } while (i < 2);
            if (savedMode != 0) {
                sceSdRemote(1, 0x8010, 0xf80, 0);
                sceSdRemote(1, 0x8010, 0x1080, 0);
                sceSdRemote(1, 0x8070, 0xa, 0x881);
            }
            result = 1;
        }
    }
    return result;
}

u32 mpg_audioDecDelete(u32 *a0 /* r4 */) {
    u8 *s1;
    s32 s0;
    u32 v0;

    s1 = (u8 *)a0;
    sceSifFreeIopHeap(*(s32 *)(((u8 *)a0 + 0x58)));
    sceSifFreeIopHeap(*(s32 *)(s1 + 0x6c));
    s0 = 0;
    do {
        sceSdRemote(1, 0x8010, (u32)(s0 | 0x980), 0);
        sceSdRemote(1, 0x8010, (u32)(s0 | 0xa80), 0);
        s0 = s0 + 1;
        v0 = s0 < (s32)2;
    } while (v0 != 0);
    v0 = *(s32 *)(s1 + 4);
    a0 = (u32 *)(s32)1;
    if (v0 == (u32)(s32)a0) {
        sceSdRemote((int)a0, 0x8070, (u32)0xa, (u32)0x800);
    }
    do {
        v0 = sceSdRemote(1, 0x80f0, *(s32 *)(s1 + 8), 0);
    } while (v0 == 0);
    return 1;
}

/* mpg_audioDecStart @ 0x196E50 .. 0x196EE0 (0x90 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 mpg_audioDecStart(u32 *a0 /* r4 */) {
    u32 v0;
    u8 *s0;
    u32 v1;
    u32 t0;

    v0 = *(s32 *)(((u8 *)a0 + 4));
    s0 = (u8 *)a0;
    if (v0 == 0) {
        sceSdRemote(1, 0x8010, (u32)0xf81, (s32)0x7fff);
        sceSdRemote(1, 0x8010, (u32)0x1081, (s32)0x7fff);
    }
    v1 = *(s32 *)(s0 + 0x5c);
    t0 = *(s32 *)(s0 + 0x58);
    v0 = *(s32 *)(s0 + 0x64);
    sceSdRemote(1, 0x80e0, *(s32 *)(s0 + 8), (s32)0x13, t0, (s32)((u32)((s32)v1 / (s32)(0x400)) <<
        0xa), (s32)(t0 + v0));
    *(u32 *)s0 = 2;
    return;
}

/* mpg_audioDecReset @ 0x196D50 .. 0x196E4C (0xfc bytes, frame 0x20) */

void mpg_audioDecReset(u32 *a0 /* r4 */) {
    u32 v0;
    u32 a2;
    u8 *s0;
    u32 v1;
    u32 t0;

    a2 = 0xf81;
    s0 = (u8 *)a0;
    *(u32 *)a0 = 3;
    sceSdRemote(1, 0x8010, a2, 0);
    sceSdRemote(1, 0x8010, (u32)0x1081, 0);
    a2 = *(s32 *)(s0 + 8);
    v0 = sceSdRemote(1, 0x80e0, a2, (u32)2, 0, 0);
    v1 = v0 & 0xffffff;
    v0 = *(s32 *)(s0 + 0x58);
    *(u32 *)(s0 + 0x64) = v1 - v0;
    v0 = *(s32 *)(s0 + 4);
    if (v0 == 0) {
        a2 = *(s32 *)(s0 + 8);
        t0 = *(s32 *)(s0 + 0x6c);
        sceSdRemote(1, 0x80d0, a2, 0, t0, (s32)0x4800, (s32)0x800);
    } else {
        a2 = *(s32 *)(s0 + 8);
        t0 = *(s32 *)(s0 + 0x6c);
        sceSdRemote(1, 0x80d0, a2, 0, t0, (s32)0x4000, (s32)0x800);
    }
    *(u32 *)s0 = 0;
    *(u32 *)(s0 + 4) = 0;
    *(u32 *)(s0 + 0x38) = 0;
    *(u32 *)(s0 + 0x40) = 0;
    *(u32 *)(s0 + 0x44) = 0;
    *(u32 *)(s0 + 0x4c) = 0;
    *(u32 *)(s0 + 0x68) = 0;
    *(u32 *)(s0 + 0x60) = 0;
    *(u32 *)(s0 + 0x64) = 0;
    return;
}


/* mpg_audioDecBeginPut @ 0x196C40 .. 0x196D48 (0x108 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 mpg_audioDecBeginPut(u32 *a0 /* r4 */, u32 *a1 /* r5 */, u32 *a2 /* r6 */, u32 *a3 /* r7 */,
        u32 *t0 /* r8 */) {
    s32 t3;
    u32 t2;
    u32 t1;
    u32 v1;

    v1 = *(s32 *)a0;
    if (v1 == 0) {
        v1 = (s32)a0[1];
        if (v1 == 0) {
            t1 = (s32)a0[0xe];
            v1 = 0x28;
            *(u32 *)a1 = (u32)(s32)((u8 *)t1 + (u32)(a0)) + 0xc;
            a1 = (u32 *)(s32)a0[0xe];
            *(u32 *)a2 = (s32)((u8 *)v1 - (u32)(a1));
            v1 = (s32)a0[0xf];
            *(u32 *)a3 = v1;
            v1 = (s32)a0[0x12];
            *(u32 *)t0 = v1;
        } else {
            t1 = (s32)a0[0xe];
            v1 = 0x2c;
            *(u32 *)a1 = (u32)(s32)((u8 *)t1 + (u32)(a0)) + 0xc;
            a1 = (u32 *)(s32)a0[0xe];
            *(u32 *)a2 = (s32)((u8 *)v1 - (u32)(a1));
            v1 = (s32)a0[0xf];
            *(u32 *)a3 = v1;
            v1 = (s32)a0[0x12];
            *(u32 *)t0 = v1;
        }
        return;
    }
    t2 = (s32)a0[0x12];
    v1 = (s32)a0[0x11];
    t1 = (s32)a0[0x10];
    t3 = t2 - v1;
    v1 = t2 - t1;
    v1 = (s32)v1 < t3;
    if (v1 == 0) {
        v1 = (s32)a0[0xf];
        *(u32 *)a1 = v1 + t1;
        *(u32 *)a2 = t3;
        *(u32 *)a3 = 0;
        *(u32 *)t0 = 0;
    } else {
        v1 = (s32)a0[0xf];
        *(u32 *)a1 = v1 + t1;
        a1 = (u32 *)(s32)a0[0x12];
        v1 = (s32)a0[0x10];
        *(u32 *)a2 = (s32)((u8 *)a1 - v1);
        v1 = (s32)a0[0xf];
        *(u32 *)a3 = v1;
        a1 = (u32 *)(s32)a0[0x12];
        v1 = (s32)a0[0x10];
        *(u32 *)t0 = t3 - ((s32)((u8 *)a1 - v1));
    }
    return;
}
void mpg_audioDecEndPut(u32 address, u32 amount) {
    struct AudioEndState *decoder=(struct AudioEndState *)address;
    s32 copied;
    if (decoder->state==0) {
        if (decoder->mode==0) {
            u32 capacity=40-decoder->header;
            if(amount<capacity) copied=amount; else copied=capacity;
            decoder->header+=copied;
            if (decoder->header>=40) decoder->state=1;
            amount-=copied;
        } else {
            u32 capacity=44-decoder->header;
            if(amount<capacity) copied=amount; else copied=capacity;
            decoder->header+=copied;
            if (decoder->header>=44) decoder->state=1;
            amount-=copied;
        }
    }
    decoder->position=(s32)(decoder->position+amount)%decoder->size;
    decoder->count+=amount;
    decoder->total+=amount;
}


/* mpg_audioDecIsPreset @ 0x196B30 .. 0x196B44 (0x14 bytes) */
/*
 * dcomp notes:
 *   return: xori at 0x196b40 computes the return value
 */

u32 mpg_audioDecIsPreset(u32 *a0 /* r4 */) {
    u32 v1;
    u32 v0;

    v1 = *(s32 *)(((u8 *)a0 + 0x68));
    v0 = *(s32 *)(((u8 *)a0 + 0x5c));
    return (u32)((s32)v1 < (s32)v0) ^ 1;
}

u32 mpg_audioDecSendToIOP(u32 *a0 /* r4 */) {
    u32 t3;
    u8 *s2;
    u32 t2;
    u32 s1;
    u32 t1;
    s32 t0;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 s0;
    u32 *a0_2; // a0
    u32 v1;
    u32 v0;
    u8 stackFrame_0[16] __attribute__((aligned(16)));

    v0 = 3;
    s2 = (u8 *)a0;
    v1 = *(s32 *)a0;
    s1 = 0;
    switch (v1) {
    case 0:
        return 0;
    case 1:
        v1 = *(s32 *)(s2 + 0x5c);
        a0_2 = (u32 *)*(s32 *)(s2 + 0x68);
        a3 = 0;
        v0 = *(s32 *)(s2 + 0x58);
        t0 = 0;
        a2 = (s32)((u8 *)v1 - (u32)(a0_2));
        v1 = (s32)a0_2 % (s32)v1;
        a1 = v0 + v1;
        break;
    case 2:
        s0 = *(s32 *)(s2 + 0x58);
        v0 = sceSdRemote(1, 0x8100, *(s32 *)(s2 + 8), a3, t0);
        a0_2 = (u32 *)*(s32 *)(s2 + 0x5c);
        a1 = *(s32 *)(s2 + 0x60);
        a2 = (s32)((u8 *)a0_2 - a1);
        v1 = (u32)((s32)((u32)((u32)(s32)((u8 *)(u32)((u32)(v0 & 0xffffff) - s0) + (u32)(a0_2)) -
            a1) + -0x400) % (s32)a0_2) & (u32)-0x400;
        if ((u32)((s32)a2 < (s32)v1) == 0) {
            a1 = s0 + (u32)a1;
            a2 = v1;
            a3 = 0;
            t0 = 0;
            break;
        } else {
            a3 = *(s32 *)(s2 + 0x58);
            t0 = v1 - a2;
            a1 = a3 + (u32)a1;
            break;
        }
    case 3:
        return 0;
    }
    t1 = *(s32 *)(s2 + 0x44);
    t2 = *(s32 *)(s2 + 0x48);
    v0 = *(s32 *)(s2 + 0x3c);
    t3 = t1 & (u32)-0x400;
    a0_2 = (u32 *)(s32)((s32)((u8 *)t2 + (u32)(s32)((u8 *)*(s32 *)(s2 + 0x40) - t1)) % (s32)t2);
    v1 = v0 + t2;
    t1 = (s32)((u8 *)v0 + (u32)(a0_2));
    t2 = v1 - t1;
    t2 = (s32)t2 < (s32)t3 ? (s32)t2 : (s32)t3;
    v1 = *(s32 *)(s2 + 4);
    t3 = t3 - t2;
    if (v1 == 0) {
        if ((s32)(a2 + t0) >= (s32)0x400 && (s32)(t2 + t3) >= (s32)0x400) {
            s1 = _sendToIOP2area(a1, a2, a3, t0, t1, t2, v0, t3);
        }
    } else if ((s32)(a2 + t0) >= (s32)0x400 && (s32)((u32)(t2 + t3) << 1) >= (s32)0x400) {
        s1 = _sendToIOP2areaAC3((AudioDecAC3 *)s2, a1, a2, a3, t0, t1, t2, v0, t3);
    }
    v0 = 1;
    *(u32 *)(s2 + 0x44) -= s1;
    v1 = *(s32 *)(s2 + 4);
    if (v1 == v0) {
        s1 = s1 << 1;
    }
    v0 = s1;
    *(u32 *)(s2 + 0x68) += s1;
    a0_2 = (u32 *)*(s32 *)(s2 + 0x60);
    v1 = *(s32 *)(s2 + 0x5c);
    *(u32 *)(s2 + 0x60) = (s32)((u8 *)a0_2 + s1) % (s32)v1;
    return v0;
}

u32 mpg_audioDecChangeVolume(s32 a0 /* r4 */) {
    s32 s1;
    u32 s0;
    s32 v1;

    s1 = 0;
    s0 = a0;
    do {
        sceSdRemote((s32)1, 0x8010, (u32)(s1 | 0x980), s0);
        sceSdRemote((s32)1, 0x8010, (u32)(s1 | 0xa80), s0);
        s1 = s1 + 1;
        v1 = s1 < (s32)2;
    } while ((u32)v1 != 0);
    return;
}

u32 _sendToIOP2area(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3) {
    s32 v1 = a1 + a3;
    s32 v0 = t1 + t3;
    s32 s0;

    if (v1 < v0) {
        v1 = v0 - v1;
        if (!(v1 < t3)) {
            t1 = t1 - (v1 - t3);
            t3 = 0;
        } else {
            t3 = t3 - v1;
        }
    }
    if (!(t1 < a1)) {
        SendToIop(t0, a0, a1);
        SendToIop(t0 + a1, a2, t1 - a1);
        SendToIop(t2, a2 + t1 - a1, t3);
    } else {
        s0 = a1 - t1;
        if (!(t3 < s0)) {
            SendToIop(t0, a0, t1);
            SendToIop(t2, a0 + t1, s0);
            SendToIop(t2 + a1 - t1, a2, t3 - s0);
        } else {
            SendToIop(t0, a0, t1);
            SendToIop(t2, a0 + t1, t3);
        }
    }
    return t1 + t3;
}

u32 _sendToIOP2areaAC3(AudioDecAC3 *ad, u32 pd0, s32 d0, s32 pd1, s32 d1, s32 ps0, s32 s0, u32 ps1, s32 s1)
{
    u8 *p99;
    int n99;
    int i99;

    s0 = s0 * 2 / 1024;
    s0 *= 512;
    s1 = s1 * 2 / 1024;
    s1 *= 512;

    if (d0 + d1 < (s0 + s1) * 2) {
        int diff = (s0 + s1) * 2 - (d0 + d1);
        if (diff >= s1 * 2) {
            s0 -= (diff - s1 * 2) / 2;
            s1 = 0;
        } else {
            s1 -= diff / 2;
        }
    }

    ad->pos = 0;
    if (s0 * 2 >= d0) {
        copyAC3i(ad, (u8 *)ps0, d0);
        copyAC3i(ad, (u8 *)ps0 + d0 / 2, s0 * 2 - d0);
        copyAC3i(ad, (u8 *)ps1, s1 * 2);
        sendToIOPAC3(pd0, ad->buf, d0);
        sendToIOPAC3(pd1, ad->buf + d0, s0 * 2 - d0);
        sendToIOPAC3(pd1 + s0 * 2 - d0, ad->buf + s0 * 2, s1 * 2);
    } else {
        if (s1 * 2 >= d0 - s0 * 2) {
            copyAC3(ad, (u8 *)ps0, s0 * 2);
            n99 = (d0 - s0 * 2) / 1024;
            i99 = 0;
            if (i99 < n99) {
                p99 = (u8 *)ps1;
                do {
                    memcpy(ad->buf + ad->pos, p99, 512);
                    ad->pos += 512;
                    memset(ad->buf + ad->pos, 0, 512);
                    ad->pos += 512;
                    p99 += 512;
                    i99++;
                } while (i99 < n99);
            }
            copyAC3i(ad, (u8 *)ps1 + (d0 / 2 - s0), s1 * 2 - (d0 - s0 * 2));
            sendToIOPAC3(pd0, ad->buf, s0 * 2);
            sendToIOPAC3(pd0 + s0 * 2, ad->buf + s0 * 2, d0 - s0 * 2);
            sendToIOPAC3(pd1, ad->buf + d0, s1 * 2 - (d0 - s0 * 2));
        } else {
            copyAC3(ad, (u8 *)ps0, s0 * 2);
            copyAC3(ad, (u8 *)ps1, s1 * 2);
            sendToIOPAC3(pd0, ad->buf, s0 * 2);
            sendToIOPAC3(pd0 + s0 * 2, ad->buf + s0 * 2, s1 * 2);
        }
    }
    return s0 + s1;
}
