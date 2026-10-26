#include "common.h"

u8 s_StrmInfo[0x940];
static struct { u32 w0; u32 w1; s16 freeHead; s16 nFree; s16 usedHead; s16 nUsed; } s_StrmMng;
u32 g_ucItoE_RpcBuff[0x40];
u32 g_ucEtoI_RpcBuff[0x40];
u64 g_ucRet_RpcBuff[0x20];
static u32 s_scdRpc[0xa];
static u32 s_stack[0x800];
static u32 s_qdIopToEeRpc[6];
static u32 s_sdIopToEeRpc[17];
static u32 s_ReadErrCB;
static u32 s_ReadEndCB;
static u32 s_iInited;

/* fsmfstrm_SetReadErrorCallBack @ 0x19E160 .. 0x19E168 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j mfstrm_SetReadErrorCallBack at 0x19e160 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 mfstrm_SetReadErrorCallBack();

/* fsmfstrm_SetReadEndCallBack @ 0x19E170 .. 0x19E178 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j mfstrm_SetReadEndCallBack at 0x19e170 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 mfstrm_SetReadEndCallBack();

/* fsmfstrm_GetIopIndex @ 0x19E180 .. 0x19E188 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j mstrm_GetIopIndex at 0x19e180 leaves the function
 *   return value dropped, call kept: the function is void
 */

u32 mstrm_GetIopIndex(s32 a0);

/* fsmfstrm_DmaReadSyncBlock @ 0x19E190 .. 0x19E198 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j mstrm_ReadSync at 0x19e190 leaves the function
 *   repo declaration vs inferred signature: return s32 vs inferred void; 2 parameters vs 0 inferred
 */

extern u32 mstrm_ReadSync();

extern int sceSifCheckStatRpc(void *);
s32 _CallRpc(s32 command, s32 mode, s32 sendSize, s32 receiveSize);
struct CdModeTail { u8 bytes[2]; };
struct CdMode { u8 first, second; struct CdModeTail tail; };


/* fsmfstrm_SetReadPacketSize @ 0x19E2F0 .. 0x19E304 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j fsmfstrm_CallRpc at 0x19e2fc leaves the function
 *   return value dropped, call kept: the function is void
 */

u32 fsmfstrm_CallRpc(s32 command, s32 mode, ...);

/* fsmfstrm_SetReadStart @ 0x19E310 .. 0x19E318 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j mstrm_SetReadStart at 0x19e310 leaves the function
 *   return value dropped, call kept: the function is void
 */

u32 mstrm_SetReadStart(s32 a0, s32 a1);

/* fsmfstrm_SetReloadSize @ 0x19E320 .. 0x19E328 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j mstrm_SetReloadSize at 0x19e320 leaves the function
 *   return value dropped, call kept: the function is void
 */

u32 mstrm_SetReloadSize(s32 a0, s32 a1);

/* fsmfstrm_DetachFileSector @ 0x19E330 .. 0x19E338 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j mstrm_DetachFileSector at 0x19e330 leaves the function
 *   return value dropped, call kept: the function is void
 */

u32 mstrm_DetachFileSector(s32 a0);

/* fsmfstrm_AttachSector @ 0x19E340 .. 0x19E348 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j mstrm_AttachSector at 0x19e340 leaves the function
 *   repo declaration vs inferred signature: return s32 vs inferred void; 4 parameters vs 0 inferred
 */

extern u32 mstrm_AttachSector();

/* fsmfstrm_FreeStreamBuffer @ 0x19E350 .. 0x19E358 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j mstrm_FreeStreamBuffer at 0x19e350 leaves the function
 *   return value dropped, call kept: the function is void
 */

u32 mstrm_FreeStreamBuffer(s32 a0);

/* fsmfstrm_AllocStreamBuffer @ 0x19E360 .. 0x19E368 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j mstrm_AllocStreamBuffer at 0x19e360 leaves the function
 *   return value dropped, call kept: the function is void
 */

u32 mstrm_AllocStreamBuffer(s32 a0, s32 a1, s32 a2, s32 a3);

/* fsmfstrm_AllocStream @ 0x19E370 .. 0x19E3E4 (0x74 bytes, frame 0x30) */

extern u32 mstrm_CreateStream(void);
extern u32 mstrm_AllocIopStream(u32, u32);
u32 mstrm_DeleteStream(s32 a0 /* r4 */);

/* fsmfstrm_AllocDmaBuffer @ 0x19E3F0 .. 0x19E4C8 (0xd8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2c escapes at 0x19e480
 *   call: _CallRpc is declared void but its v0 is read: called as returning u32
 *   cfg: loop body is not one contiguous region: .L0019E420
 *   cfg: kept branch: 0x19e420 if (..) goto .L0019E430
 *   cfg: kept goto: 0x19e424 -> .L0019E458
 */

extern int sceSifCheckStatRpc(void *);
s32 _CallRpc(s32 command, s32 mode, s32 sendSize, s32 receiveSize);


/* fsmfstrm_DmaInit @ 0x19E4D0 .. 0x19E560 (0x90 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: loop leaves to a block that is not its join: 0x19e504 -> 0x19e538
 *   cfg: kept branch: 0x19e500 if (..) goto .L0019E510
 *   cfg: kept goto: 0x19e504 -> .L0019E538
 *   cfg: kept branch: 0x19e510 if (..) goto .L0019E500
 */

extern int sceSifCheckStatRpc(void *);
s32 _CallRpc(s32 command, s32 mode, s32 sendSize, s32 receiveSize);

/* fsmfstrm_ThreadInit @ 0x19E560 .. 0x19E568 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j mstrm_ThreadInit at 0x19e560 leaves the function
 *   return value dropped, call kept: the function is void
 */

u32 mstrm_ThreadInit(s32 a0, s32 a1, s32 a2);

extern int sceSifBindRpc(void *, unsigned int, unsigned int);
extern int CreateThread(void *);
extern int StartThread(int, void *);
u32 mstrm_Init(void);
static void _ItoE_RpcThread(void);
extern u8 *_gp;
static u8 s_iRpcThrdID[4];


struct fsmf_ThreadParam {
    int status;
    void *entry;
    void *stack;
    int stackSize;
    void *gpReg;
    int initPriority;
    int currentPriority;
    u32 attr;
    u32 option;
    int waitType;
    int waitId;
    int wakeupCount;
};


extern void FlushCache(int);
extern int sceSifCallRpc(void *, unsigned int, unsigned int, void *, int, void *, int, void *, void *);


/* _ItoE_RpcDispatch @ 0x19EA30 .. 0x19EA8C (0x5c bytes, frame 0x10) */

extern void mstrm_EndReading(s32, u32);
extern void mstrm_CheckReadError(s32, s32);
extern u64 g_ucRet_RpcBuff[];

/* _ItoE_RpcThread @ 0x19EA90 .. 0x19EB00 (0x70 bytes, frame 0x10) */

extern void sceSifInitRpc(unsigned int);
extern int GetThreadId(void);
extern void sceSifSetRpcQueue(u32 *, int);
extern void sceSifRegisterRpc(u32 *, s32, void *, u32 *, u32, u32, u32 *);
extern void sceSifRpcLoop(u32 *);
extern u32 g_ucItoE_RpcBuff[];

/* mfstrm_SetReadErrorCallBack @ 0x19EB00 .. 0x19EB0C (0xc bytes) */

extern u32 s_ReadErrCB;

/* mfstrm_SetReadEndCallBack @ 0x19EB10 .. 0x19EB1C (0xc bytes) */

extern u32 s_ReadEndCB;

/* mstrm_GetIopIndex @ 0x19EB20 .. 0x19EB70 (0x50 bytes) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x19eb2c if (..) goto .L0019EB40
 *   cfg: kept goto: 0x19eb38 -> .L0019EB68
 *   declaration vs inferred signature: 0 parameters vs 1 inferred
 */

extern u8 s_StrmInfo[];

static u32 s_iSyncSema;
extern u32 strm_ReadSync();
extern int WaitSema(int);
extern void sbuf_FreeStreamBuffer(s32);
extern void strm_DetachStreamBuffer(u8 *);
extern int SignalSema(int);

static u32 s_SemaID;

/* mstrm_EndReading @ 0x19ED30 .. 0x19EEB4 (0x184 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0019ED60
 */

extern int WaitSema(int);
extern void strm_EndReading(u8 *);
extern int SignalSema(int);
extern void sbuf_FreeStreamBuffer(s32);
extern void strm_DetachStreamBuffer(u8 *);

extern u32 s_iThreadID;
extern u32 s_iSyncSema;
extern u32 s_iEndReadFlag;
static u8 s_iRpcThrdID[0x4] = {0xff, 0xff, 0xff, 0xff};
static u32 s_SemaID = 0xffffffff;

/* mstrm_SetReadStart @ 0x19EEC0 .. 0x19EF64 (0xa4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x19eee0 if (..) goto .L0019EEF8
 *   cfg: kept goto: 0x19eef0 -> .L0019EF50
 *   declaration vs inferred signature: 0 parameters vs 2 inferred
 */

extern u32 strm_SetReadStart(s32, u32);

/* mstrm_SetReloadSize @ 0x19EF70 .. 0x19EFFC (0x8c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x19ef90 if (..) goto .L0019EFA8
 *   cfg: kept goto: 0x19efa0 -> .L0019EFE8
 *   declaration vs inferred signature: 0 parameters vs 2 inferred
 */

extern u32 strm_SetReloadSize(s32, u32);

/* mstrm_DetachFileSector @ 0x19F000 .. 0x19F080 (0x80 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x19f01c if (..) goto .L0019F030
 *   cfg: kept goto: 0x19f028 -> .L0019F070
 *   declaration vs inferred signature: 0 parameters vs 1 inferred
 */

extern u32 strm_Close(s32);

extern u32 strm_OpenSector(s32, u32, u32, u32);

/* mstrm_DeleteStream @ 0x19F1D0 .. 0x19F2C4 (0xf4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x19f1f0 if (..) goto .L0019F200
 *   cfg: kept goto: 0x19f1f8 -> .L0019F2B0
 */

extern u32 fsmfstrm_CallRpcStruct(s32, s32, s32, s32, u32 *);
extern void _mstrm_ReleaseInfo(s16);

/* mstrm_AllocStreamBuffer @ 0x19F2D0 .. 0x19F3DC (0x10c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: 0 parameters vs 4 inferred
 */

extern u32 sbuf_AllocStreamBuffer(u32, u32);
extern void strm_AttachStreamBuffer(s32, u32);


/* mstrm_CreateStream @ 0x19F4C0 .. 0x19F504 (0x44 bytes, frame 0x20) */

extern u32 _mstrm_GetInfo(void);

/* mstrm_ThreadInit @ 0x19F510 .. 0x19F5E8 (0xd8 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: 0 parameters vs 3 inferred
 */

extern int CreateSema(void *);
extern int CreateThread(void *);
extern int StartThread(int, void *);
static void _mstrm_Thread(void);
extern u8 *_gp;

extern void strm_InitInfo(u8 *);
extern void sbuf_Init();


/* _mstrm_Thread @ 0x19F720 .. 0x19F830 (0x110 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x19f7d8 writes a register its branch at 0x19f7d4 reads
 *   cfg: loop header already being structured: .L0019F730
 *   cfg: loop body is not one contiguous region: .L0019F788
 *   cfg: kept branch: 0x19f7cc if (..) goto .L0019F7E8
 *   cfg: kept branch: 0x19f7d8 if (..) goto .L0019F810
 */

extern u32 strm_RequiredReading(s32);
extern u32 sbuf_GetBufferSize(s32);
extern void strm_Read(s32, u32);


/* _mstrm_GetInfo @ 0x19F980 .. 0x19FA70 (0xf0 bytes) */

typedef struct StrmInfoLink { u8 pad[0x120]; s16 next; s16 prev; u8 pad2[4]; } StrmInfoLink;

static u32 s_iThreadID = 0xffffffff;
static u32 s_iSyncSema = 0xffffffff;
u32 s_iEndReadFlag = 0xffffffff;




/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 _mstrm_GetInfo(void);
void _mstrm_ReleaseInfo(s16 a0);
static void _mstrm_Thread(void);
u32 mstrm_Init(void);
u32 mstrm_ThreadInit(s32 a0, s32 a1, s32 a2);
u32 mstrm_CreateStream(void);
u32 mstrm_AllocIopStream(u32 ch, u32 size);
u32 mstrm_AllocStreamBuffer(s32 a0, s32 a1, s32 a2, s32 a3);
u32 mstrm_DeleteStream(s32 a0 );
u32 mstrm_FreeStreamBuffer(s32 a0);
u32 mstrm_AttachSector(s32 a0, s32 a1, s32 a2, s32 a3);
u32 mstrm_DetachFileSector(s32 a0);
u32 mstrm_SetReloadSize(s32 a0, s32 a1);
u32 mstrm_SetReadStart(s32 a0, s32 a1);
void mstrm_EndReading(s32 a0 , u32 arg1);
void mstrm_CheckReadError(s32 arg0, s32 arg1);
u32 mstrm_ReadSync(s32 index, s32 mode);
u32 mstrm_GetIopIndex(s32 a0);
u32 mfstrm_SetReadEndCallBack(s32 a0 );
u32 mfstrm_SetReadErrorCallBack(s32 a0 );
static void _ItoE_RpcThread(void);
static u8 * _ItoE_RpcDispatch(s32 a0 , u32 *a1 );
s32 _CallRpc(s32 command, s32 mode, s32 sendSize, s32 receiveSize);
u32 fsmfstrm_CallRpcStruct(s32 a0 , s32 a1 , s32 a2 , s32 a3 , u32 *t0 );
u32 fsmfstrm_CallRpc(s32 command, s32 mode, ...);
u32 fsmfstrm_Init(void);
void fsmfstrm_ThreadInit(s32 a0 , s32 a1 , s32 a2 );
void fsmfstrm_DmaInit(void);
u32 fsmfstrm_AllocDmaBuffer(s32 a0 );
u32 fsmfstrm_AllocStream(s32 a0 );
void fsmfstrm_AllocStreamBuffer(s32 a0 , s32 a1 , s32 a2 , s32 a3 );
void fsmfstrm_FreeStreamBuffer(s32 a0 );
s32 fsmfstrm_AttachSector(s32 a0 , s32 a1 , s32 a2 , s32 a3 );
void fsmfstrm_DetachFileSector(s32 a0 );
void fsmfstrm_SetReloadSize(s32 a0 , s32 a1 );
void fsmfstrm_SetReadStart(s32 a0 , s32 a1 );
void fsmfstrm_SetReadPacketSize(s32 a0 );
u32 fsmfstrm_SetCdRMode(s32 mode, struct CdMode *settings);
s32 fsmfstrm_DmaReadSyncBlock(s32 a0 , s32 a1 );
void fsmfstrm_GetIopIndex(s32 a0 );
void fsmfstrm_SetReadEndCallBack(s32 a0 );
void fsmfstrm_SetReadErrorCallBack(s32 a0 );


u32 _mstrm_GetInfo(void) {
    s32 idx;
    s32 t;
    StrmInfoLink *info;
    u32 v1;

    if (s_StrmMng.nFree == 0) {
        return -1;
    }
    idx = s_StrmMng.freeHead;
    info = (StrmInfoLink *)s_StrmInfo + idx;
    s_StrmMng.freeHead = info->next;
    s_StrmMng.nFree--;
    t = info->next;
    if (t != -1) {
        v1 = (u32)(s_StrmInfo + 0x122);
        *(s16 *)(v1 + (u32)(t * 296)) = -1;
    }
    t = s_StrmMng.usedHead;
    if (t != -1) {
        v1 = (u32)(s_StrmInfo + 0x122);
        *(s16 *)(v1 + (u32)(t * 296)) = idx;
    }
    info->next = t;
    s_StrmMng.usedHead = idx;
    s_StrmMng.nUsed++;
    return (s16)idx;
}

void _mstrm_ReleaseInfo(s16 a0) {
    s32 t1;
    s32 t0;
    s32 a3;
    u32 a2;
    u32 a1;
    u32 v1;
    v1 = a0;
    if ((s32)v1 < 0 || (s32)v1 >= 8) return;
    a1 = (u32)s_StrmInfo;
    a2 = -1;
    a1 = (s32)(s_StrmInfo + (s32)(v1 * 296));
    t1 = *(s16 *)(a1 + 0x122);
    if ((u32)t1 != a2) {
        t0 = *(s16 *)(a1 + 0x120);
        a2 = (u32)(s_StrmInfo + 0x120);
        *(u16 *)(a2 + (s32)((u32)t1 * 296)) = t0;
    }
    t1 = *(s16 *)(a1 + 0x120);
    a2 = -1;
    if ((u32)t1 != a2) {
        t0 = *(s16 *)(a1 + 0x122);
        a2 = (u32)(s_StrmInfo + 0x122);
        *(u16 *)(a2 + (s32)((u32)t1 * 296)) = t0;
    }
    a2 = s_StrmMng.usedHead;
    if (a2 == v1) {
        v1 = *(s16 *)(a1 + 0x120);
        s_StrmMng.usedHead = v1;
    }
    s_StrmMng.nUsed--;
    v1 = -1;
    a3 = s_StrmMng.freeHead;
    if ((u32)a3 != v1) {
        v1 = (u32)(s_StrmInfo + 0x122);
        *(u16 *)(v1 + (u32)((u32)a3 * 296)) = a0;
    }
    *(u16 *)(a1 + 0x120) = a3;
    *(s16 *)(a1 + 0x122) = -1;
    s_StrmMng.freeHead = a0;
    s_StrmMng.nFree++;
}

static void _mstrm_Thread(void) {
    u32 a0;
    u32 v1;
    u32 v0;
    u8 *s0;

    while (1) {
        a0 = s_iSyncSema;
        WaitSema(a0);
        v1 = s_ReadEndCB;
        v0 = v1 != 0;
        v0 = v0 ^ 1;
        if (v0 == 0 && (s32)*(volatile s32 *)&s_iEndReadFlag >= 0) {
            a0 = s_iEndReadFlag;
            ((void (*)(s32))(s32)v1)(a0);
            v0 = -1;
            s_iEndReadFlag = v0;
        }
        a0 = s_SemaID;
        WaitSema(a0);
        v0 = -1;
        a0 = s_StrmMng.usedHead;
        if (a0 != v0) {
            do {
                v0 = (u32)s_StrmInfo;
                v1 = a0 * (u32)(0x128);
                s0 = (u8 *)((u8 *)s_StrmInfo + v1);
                v0 = *(u8 *)(s0 + 0x124);
                v0 = v0 & 1;
                if (v0 != 0) {
                    v0 = *(u8 *)(s0 + 0x18);
                    if ((u64)((u64)((u64)v0 << 0x3e) >> 0x3f) != 0) {
                        v1 = *(s32 *)(s0 + 0x14);
                        v0 = 1;
                        if (v1 == v0) {
                            goto _L0019F7E8;
                        }
                        v0 = 4;
                        if (v1 != v0) {
                            goto _L0019F810;
                        }
                        _L0019F7E8:;
                        a0 = (s32)s0;
                        v0 = strm_RequiredReading(a0);
                        if (v0 != 0) {
                            a0 = *(s32 *)(s0 + 0x1c);
                            v0 = sbuf_GetBufferSize(a0);
                            a0 = (s32)s0;
                            strm_Read(a0, v0);
                        }
                    }
                }
                _L0019F810:;
                a0 = *(s16 *)(s0 + 0x120);
                v0 = -1;
            } while (a0 != v0);
        }
        a0 = s_SemaID;
        SignalSema(a0);
    }
}

u32 mstrm_Init(void) {
    s32 i;
    u8 *info;
    u32 sema[8] __attribute__((aligned(16)));

    if (*(u8 *)&s_StrmMng.w1 & 1) {
        return;
    }
    for (i = 0, info = s_StrmInfo; i < 8; i++, info += 0x128) {
        strm_InitInfo(info);
        *(s16 *)(info + 0x120) = i + 1;
        *(s16 *)(info + 0x122) = i - 1;
        ((struct { unsigned char f:1; } *)(info + 0x124))->f = 1;
        ((struct { unsigned char _pad:1; unsigned char f:1; } *)(info + 0x124))->f = 0;
    }
    s_StrmMng.w1 = 0;
    *(s16 *)(s_StrmInfo + 0x938) = -1;
    s_StrmMng.usedHead = -1;
    s_StrmMng.nFree = 8;
    s_StrmMng.w0 = 0;
    s_StrmMng.nUsed = 0;
    s_StrmMng.freeHead = 0;
    sbuf_Init();
    sema[2] = 1;
    sema[1] = 1;
    s_SemaID = CreateSema(sema);
    if ((s32)s_SemaID >= 0) {
        ((struct { unsigned char f:1; } *)&s_StrmMng.w1)->f = 1;
    }
}

u32 mstrm_ThreadInit(s32 a0, s32 a1, s32 a2) {
    u32 s2;
    u32 s1;
    u32 s0;
    u32 v0;
    u8 stackFrame_70[32] __attribute__((aligned(16)));
    u8 stackFrame_40[48] __attribute__((aligned(16)));

    s2 = a0;
    s1 = a1;
    v0 = *(u8 *)&s_StrmMng.w1;
    v0 = v0 & 1;
    s0 = a2;
    if (v0 == 0) {
        v0 = 0;
    } else {
        v0 = 1;
        ((u32 *)stackFrame_70)[2] = v0;
        a0 = (s32)((u8 *)&stackFrame_70[0]);
        ((u32 *)stackFrame_70)[1] = v0;
        v0 = CreateSema((void *)a0);
        s_iSyncSema = (u32)v0;
        v0 = s_iSyncSema;
        if ((s32)v0 < 0) {
            v0 = 0;
        } else {
            v0 = (u32)_mstrm_Thread;
            a0 = (s32)((u8 *)&stackFrame_40[0]);
            ((u32 *)stackFrame_40)[1] = (u32)_mstrm_Thread;
            v0 = (u32)&_gp;
            ((u32 *)stackFrame_40)[2] = s2;
            ((u32 *)stackFrame_40)[4] = (u32)&_gp;
            ((u32 *)stackFrame_40)[3] = s1;
            ((u32 *)stackFrame_40)[5] = s0;
            ((u32 *)stackFrame_40)[8] = 0;
            v0 = CreateThread((void *)a0);
            s_iThreadID = (u32)v0;
            a0 = s_iThreadID;
            if (a0 < 0) {
                v0 = 0;
            } else {
                StartThread(a0, (void *)0);
                v0 = 1;
            }
        }
    }
    return v0;
}

u32 mstrm_CreateStream(void) {
    s16 s0;

    WaitSema(s_SemaID);
    s0 = _mstrm_GetInfo();
    SignalSema(s_SemaID);
    return s0;
}

u32 mstrm_AllocIopStream(u32 ch, u32 size) {
    u8 *info;
    u32 ret = 1;

    if (0 > (s32)ch || (s32)ch >= 8) {
        return 0;
    }
    if ((s32)size <= 0) {
        return 0;
    }
    WaitSema(s_SemaID);
    size = (size + 0x7ff) & ~0x7ff;
    info = s_StrmInfo + ch * 0x128;
    *(s32 *)info = fsmfstrm_CallRpcStruct(0x1000, ret, 4, 4, &size);
    if (*(s32 *)info < 0) {
        ret = 0;
    }
    SignalSema(s_SemaID);
    return ret;
}

u32 mstrm_AllocStreamBuffer(s32 a0, s32 a1, s32 a2, s32 a3) {
    u32 s3;
    u32 s2;
    u32 s1;
    u32 s0;
    s32 a0_2; // a0
    s32 v1;
    u32 v0;

    s3 = a1;
    s2 = a2;
    s1 = a3;
    s0 = a0;
    if ((s32)s2 <= 0) {
        v0 = 0;
    } else {
        a0_2 = s_SemaID;
        WaitSema(a0_2);
        v1 = s0 << 3;
        v1 = v1 + s0;
        v0 = (u32)s_StrmInfo;
        v1 = (u32)v1 << 2;
        v1 = v1 + s0;
        s0 = (s32)((u8 *)s_StrmInfo + (s32)((u32)v1 << 3));
        sbuf_FreeStreamBuffer(*(s32 *)((s0 + 0x1c)));
        strm_DetachStreamBuffer((u8 *)s0);
        v0 = sbuf_AllocStreamBuffer(s3, s2 & (u32)-0x10);
        if (v0 == 0) {
            a0_2 = s_SemaID;
            SignalSema(a0_2);
            v0 = 0;
        } else {
            strm_AttachStreamBuffer(s0, v0);
            v0 = 0;
            ((struct { unsigned char f:1; } *)&*(u8 *)((s0 + 0x124)))->f = s1;
            ((struct { unsigned char _pad:1; unsigned char f:1; } *)&*(u8 *)((s0 + 0x124)))->f = 0;
            a0_2 = s_SemaID;
            SignalSema(a0_2);
            a0_2 = s_iSyncSema;
            SignalSema(a0_2);
            v0 = 1;
        }
    }
    return v0;
}

u32 mstrm_DeleteStream(s32 a0 /* r4 */) {
    u8 *s1;
    s32 a2;
    u32 v1;
    u32 s0;
    u32 v0;

    s0 = a0;
    v0 = (s32)s0 < (s32)8;
    if (0 <= (s32)s0) {
        if (v0 != 0) {
            goto _L0019F200;
        }
    }
    v0 = 0;
    goto _L0019F2B0;
    _L0019F200:;
    v0 = s0 << 3;
    v0 = v0 + s0;
    a0 = v0 << 2;
    v1 = (u32)s_StrmInfo;
    a0 = a0 + s0;
    v0 = -1;
    a0 = (u32)a0 << 3;
    s1 = (u8 *)((u8 *)s_StrmInfo + a0);
    v1 = *(s32 *)s1;
    if (v1 != v0 && 0 <= (s32)s0 && (s32)s0 < (s32)8) {
        a0 = s_SemaID;
        WaitSema(a0);
        a2 = 4;
        a0 = 0x1000;
        v0 = fsmfstrm_CallRpcStruct(a0, 1, a2, a2, (u32 *)s1);
        if (v0 != 0) {
            v0 = -1;
            *(u32 *)s1 = v0;
        }
        a0 = s_SemaID;
        SignalSema(a0);
    }
    a0 = s_SemaID;
    WaitSema(a0);
    a0 = *(s32 *)(s1 + 0x1c);
    sbuf_FreeStreamBuffer(a0);
    a0 = (s32)s1;
    strm_DetachStreamBuffer((u8 *)a0);
    a0 = (s16)s0;
    _mstrm_ReleaseInfo(a0);
    a0 = s_SemaID;
    SignalSema(a0);
    v0 = 1;
    _L0019F2B0:;
    return v0;
}


/* mstrm_FreeStreamBuffer @ 0x19F140 .. 0x19F1C8 (0x88 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x19f15c if (..) goto .L0019F170
 *   cfg: kept goto: 0x19f168 -> .L0019F1B8
 *   declaration vs inferred signature: 0 parameters vs 1 inferred
 */

u32 mstrm_FreeStreamBuffer(s32 a0) {
    u32 s0;
    s32 v1;
    u32 v0;

    s0 = a0;
    v0 = (s32)s0 < (s32)8;
    if (0 <= (s32)s0) {
        if (v0 != 0) {
            goto _L0019F170;
        }
    }
    v0 = 0;
    goto _L0019F1B8;
    _L0019F170:;
    a0 = s_SemaID;
    WaitSema(a0);
    v1 = s0 << 3;
    v1 = v1 + s0;
    v0 = (u32)s_StrmInfo;
    v1 = (u32)v1 << 2;
    v1 = v1 + s0;
    v1 = (u32)v1 << 3;
    s0 = (s32)((u8 *)s_StrmInfo + v1);
    a0 = *(s32 *)((s0 + 0x1c));
    sbuf_FreeStreamBuffer(a0);
    a0 = s0;
    strm_DetachStreamBuffer((u8 *)a0);
    a0 = s_SemaID;
    SignalSema(a0);
    v0 = 1;
    _L0019F1B8:;
    return v0;
}

u32 mstrm_AttachSector(s32 a0, s32 a1, s32 a2, s32 a3) {
    u32 s0;
    u32 v0;

    s0 = a0;
    if (0 <= (s32)s0) {
        v0 = (s32)s0 < (s32)8;
        if (v0 != 0) {
            goto _L0019F0C8;
        }
    }
    return 0;
    _L0019F0C8:;
    a0 = s_SemaID;
    WaitSema(a0);
    a0 = (s32)((u8 *)s_StrmInfo + s0 * 296);
    v0 = strm_OpenSector(a0, a1, a2, a3);
    a0 = s_SemaID;
    s0 = v0;
    SignalSema(a0);
    a0 = s_iSyncSema;
    SignalSema(a0);
    v0 = s0;
    return v0;
}

u32 mstrm_DetachFileSector(s32 a0) {
    u32 s0;
    s32 v1;
    u32 v0;

    s0 = a0;
    v0 = (s32)s0 < (s32)8;
    if (0 <= (s32)s0) {
        if (v0 != 0) {
            goto _L0019F030;
        }
    }
    return 0;
    _L0019F030:;
    a0 = s_SemaID;
    WaitSema(a0);
    v1 = s0 << 3;
    v1 = v1 + s0;
    v0 = (u32)s_StrmInfo;
    v1 = (u32)v1 << 2;
    v1 = v1 + s0;
    v1 = (u32)v1 << 3;
    a0 = (s32)((u8 *)s_StrmInfo + v1);
    v0 = strm_Close(a0);
    a0 = s_SemaID;
    s0 = v0;
    SignalSema(a0);
    v0 = s0;
    return v0;
}

u32 mstrm_SetReloadSize(s32 a0, s32 a1) {
    u32 s1;
    u32 s0;
    s32 v1;
    u32 v0;
    s32 a1_2;

    s0 = a0;
    s1 = a1;
    if (0 <= (s32)s0) {
        v0 = (s32)s0 < (s32)8;
        if (v0 != 0) {
            goto _L0019EFA8;
        }
    }
    return -1;
    _L0019EFA8:;
    a0 = s_SemaID;
    WaitSema(a0);
    v0 = s0 << 3;
    a1_2 = s1;
    v1 = v0 + s0;
    v1 = (u32)v1 << 2;
    v1 = v1 + s0;
    v0 = (u32)s_StrmInfo;
    v1 = (u32)v1 << 3;
    a0 = (s32)((u8 *)s_StrmInfo + v1);
    v0 = strm_SetReloadSize(a0, a1_2);
    a0 = s_SemaID;
    s0 = v0;
    SignalSema(a0);
    v0 = s0;
    return v0;
}

u32 mstrm_SetReadStart(s32 a0, s32 a1) {
    u32 s1;
    u32 s0;
    s32 v1;
    u32 v0;
    s32 a1_2;

    s1 = a0;
    s0 = a1;
    if (0 <= (s32)s1) {
        v0 = (s32)s1 < (s32)8;
        if (v0 != 0) {
            goto _L0019EEF8;
        }
    }
    return -1;
    _L0019EEF8:;
    a0 = s_SemaID;
    WaitSema(a0);
    v1 = s1 << 3;
    v1 = v1 + s1;
    v0 = (u32)s_StrmInfo;
    v1 = (u32)v1 << 2;
    a1_2 = s0;
    v1 = v1 + s1;
    v1 = (u32)v1 << 3;
    a0 = (s32)((u8 *)s_StrmInfo + v1);
    v0 = strm_SetReadStart(a0, a1_2);
    a0 = s_SemaID;
    s1 = v0;
    SignalSema(a0);
    if (s0 != 0) {
        a0 = s_iSyncSema;
        SignalSema(a0);
    }
    v0 = s1;
    return v0;
}

void mstrm_EndReading(s32 a0 /* r4 */, u32 arg1) {
    s32 s3;
    s32 s2;
    u32 v1;
    u32 v0;
    s32 s1;
    u8 *s0;
    s32 a0_2;

    s3 = a0;
    a0_2 = s_SemaID;
    WaitSema(a0_2);
    s2 = 0;
    v1 = (u32)s_StrmInfo;
    do {
        v0 = *(s32 *)v1;
        if ((u32)s3 == v0) {
            v1 = (u32)s2 << 3;
            v1 = v1 + s2;
            v0 = (u32)s_StrmInfo;
            s1 = (u32)((u32)(v1 << 2) + s2) << 3;
            s0 = (u8 *)((u8 *)s_StrmInfo + s1);
            strm_EndReading((u8 *)(u32)(s32)s0);
            v0 = s_iThreadID;
            if ((s32)v0 >= 0) {
                a0_2 = s_SemaID;
                SignalSema(a0_2);
                a0_2 = s_iSyncSema;
                s_iEndReadFlag = s2;
                SignalSema(a0_2);
            } else {
                v1 = (u32)(u8 *)(s_StrmInfo + 0x14) + s1;
                v1 = *(s32 *)v1;
                v0 = 5;
                if (v1 == v0 && (u32)s_ReadEndCB != 0) {
                    a0_2 = s_SemaID;
                    SignalSema(a0_2);
                    v1 = (u32)s3 << 3;
                    v1 = v1 + s3;
                    v0 = (u32)s_StrmInfo;
                    v1 = v1 << 2;
                    v0 = (s32)((u8 *)s_StrmInfo + (u32)((u32)(v1 + s3) << 3));
                    v0 = *(u8 *)((v0 + 0x124));
                    if ((u64)((u64)((u64)v0 << 0x3e) >> 0x3f) != 0 && 0 <= s2 && s2 < (s32)8) {
                        a0_2 = s_SemaID;
                        WaitSema(a0_2);
                        sbuf_FreeStreamBuffer(*(s32 *)(s0 + 0x1c));
                        strm_DetachStreamBuffer((u8 *)(u32)(s32)s0);
                        a0_2 = s_SemaID;
                        SignalSema(a0_2);
                    }
                    v0 = s_ReadEndCB;
                    ((void (*)(u32))(s32)v0)(s2);
                } else {
                    a0_2 = s_SemaID;
                    SignalSema(a0_2);
                }
            }
            return;
        }
        s2 = s2 + 1;
        v0 = s2 < (s32)8;
        v1 = v1 + 0x128;
    } while (v0 != 0);
    a0_2 = s_SemaID;
    SignalSema(a0_2);
    return;
}


/* mstrm_CheckReadError @ 0x19ED00 .. 0x19ED2C (0x2c bytes, frame 0x10) */

void mstrm_CheckReadError(s32 arg0, s32 arg1) {
    u32 v1;

    v1 = s_ReadErrCB;
    if (v1 != 0) {
        ((void (*)(void))(s32)v1)();
    }
    return;
}
u32 mstrm_ReadSync(s32 index, s32 mode) {
    u8 *info;
    s32 savedIndex = index;
    s32 result = mode;
    if (0 > savedIndex || savedIndex >= 8) return 0;
    if (result != 0) {
        info = (u8 *)s_StrmInfo + savedIndex * 296;
        result = strm_ReadSync(info, result);
        if (result == 0 && ((u64)info[0x124] << 62 >> 63) != 0 && 0 <= savedIndex && savedIndex <= 7) {
            WaitSema(s_SemaID);
            sbuf_FreeStreamBuffer(*(s32 *)(info + 0x1c));
            strm_DetachStreamBuffer(info);
            SignalSema(s_SemaID);
        }
    } else {
        WaitSema(s_SemaID);
        info = (u8 *)s_StrmInfo + savedIndex * 296;
        result = strm_ReadSync(info, result);
        if (result == 0) {
            if (((u64)info[0x124] << 62 >> 63) == 0) goto signal;
            SignalSema(s_SemaID);
            if (0 <= savedIndex && savedIndex <= 7) {
                WaitSema(s_SemaID);
                sbuf_FreeStreamBuffer(*(s32 *)(info + 0x1c));
                strm_DetachStreamBuffer(info);
                SignalSema(s_SemaID);
            }
        } else {
        signal:
            SignalSema(s_SemaID);
        }
    }
    SignalSema(s_iSyncSema);
    return result;
}

u32 mstrm_GetIopIndex(s32 a0) {
    u32 v0;

    v0 = a0 < (s32)8;
    if (0 <= a0) {
        if (v0 != 0) {
            goto _L0019EB40;
        }
    }
    v0 = -1;
    goto _L0019EB68;
    _L0019EB40:;
    v0 = (u32)s_StrmInfo;
    v0 = (s32)((u8 *)s_StrmInfo + (s32)((u32)a0 * (u32)(0x128)));
    v0 = *(s32 *)v0;
    _L0019EB68:;
    return v0;
}

u32 mfstrm_SetReadEndCallBack(s32 a0 /* r4 */) {
    u32 v0;

    v0 = s_ReadEndCB;
    s_ReadEndCB = a0;
    return v0;
}

u32 mfstrm_SetReadErrorCallBack(s32 a0 /* r4 */) {
    u32 v0;

    v0 = s_ReadErrCB;
    s_ReadErrCB = a0;
    return v0;
}











static void _ItoE_RpcThread(void) {
    u32 a0;
    u32 v0;

    sceSifInitRpc(0);
    v0 = GetThreadId();
    a0 = (u32)s_qdIopToEeRpc;
    sceSifSetRpcQueue(s_qdIopToEeRpc, v0);
    a0 = (u32)s_sdIopToEeRpc;
    sceSifRegisterRpc(s_sdIopToEeRpc, 0x4020, _ItoE_RpcDispatch, g_ucItoE_RpcBuff, 0, 0,
        s_qdIopToEeRpc);
    a0 = (u32)s_qdIopToEeRpc;
    sceSifRpcLoop(s_qdIopToEeRpc);
    return;
}

static u8 * _ItoE_RpcDispatch(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u32 v0;
    u32 v1;

    v0 = 0x10000000;
    v1 = 0x10000000 | 0x200;
    switch ((u32)a0) {
    case 268435712:
        a0 = *(s32 *)a1;
        mstrm_EndReading(a0, (u32)a1);
        break;
    case 268435968:
        a0 = *(s32 *)a1;
        a1 = (u32 *)*(s32 *)(((u8 *)a1 + 4));
        mstrm_CheckReadError(a0, (s32)a1);
    }
    return (u8 *)(u32)g_ucRet_RpcBuff;
}
 s32 _CallRpc(s32 command, s32 mode, s32 sendSize, s32 receiveSize) {
    u32 rpcMode;
    u32 *buffer;
    rpcMode = !mode;
    sendSize = (sendSize + 15) & -16;
    buffer = g_ucEtoI_RpcBuff;
    if (sendSize > 256) sendSize = 256;
    receiveSize = (receiveSize + 15) & -16;
    if (receiveSize > 256) receiveSize = 256;
    FlushCache(0);
    sceSifCallRpc((void *)s_scdRpc, command, rpcMode, buffer, sendSize, buffer, receiveSize, 0, 0);
    FlushCache(0);
    return *(s32 *)buffer;
}


/* fsmfstrm_CallRpcStruct: convert the formal size to an unsigned local web. */
u32 fsmfstrm_CallRpcStruct(s32 a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */, s32 a3 /* r7 */, u32
        *t0 /* r8 */) {
    extern u32 _CallRpc(s32, s32, u32, u32);
    u32 s5;
    u32 s4;
    u32 size;
    u32 s2;
    u8 *s1;
    s32 s0;
    s32 a3_2;
    s32 a2_2; // a2
    s32 a1_2; // a1
    s32 a0_2;
    u8 *tail_src;
    u8 *tail_dst;
    u32 v1;
    u32 v0;

    v0 = 0x980000;
    s5 = a0;
    s4 = a1;
    size = (u32)a2;
    s2 = a3;
    s1 = (u8 *)t0;
    a0_2 = (s32)s_scdRpc;
    s0 = 0x980000 | 0x9680;
    v0 = sceSifCheckStatRpc((void *)s_scdRpc);
    v1 = 1;
    if (v0 == v1) {
        do {
            if (s0 >= 0) {
                goto _L0019E818;
            }
            v0 = 0;
            goto _L0019E840;
            _L0019E818:;
            a0_2 = (s32)s_scdRpc;
            s0 = s0 + -1;
            v0 = sceSifCheckStatRpc((void *)s_scdRpc);
            v1 = 1;
        } while (v0 == v1);
    }
    v0 = 1;
    _L0019E840:;
    if (v0 == 0) {
        v0 = -1;
    } else {
        v0 = (s32)size < (s32)0x100;
        if ((u32)s1 != 0) {
            if (v0 == 0) {
                size = 0x100;
            }
            a3_2 = 0;
            if (0 < (s32)size) {
                a2_2 = (s32)size + -8;
                if ((s32)size > (s32)8) {
                    a1_2 = (s32)s1;
                    a0_2 = (s32)g_ucEtoI_RpcBuff;
                    do {
                        v1 = *(u8 *)a1_2;
                        a3_2 = a3_2 + 8;
                        v0 = a3_2 < a2_2;
                        *(u8 *)a0_2 = v1;
                        v1 = *(u8 *)((a1_2 + 1));
                        *(u8 *)((a0_2 + 1)) = v1;
                        v1 = *(u8 *)((a1_2 + 2));
                        *(u8 *)((a0_2 + 2)) = v1;
                        v1 = *(u8 *)((a1_2 + 3));
                        *(u8 *)((a0_2 + 3)) = v1;
                        v1 = *(u8 *)((a1_2 + 4));
                        *(u8 *)((a0_2 + 4)) = v1;
                        v1 = *(u8 *)((a1_2 + 5));
                        *(u8 *)((a0_2 + 5)) = v1;
                        v1 = *(u8 *)((a1_2 + 6));
                        *(u8 *)((a0_2 + 6)) = v1;
                        v1 = *(u8 *)((a1_2 + 7));
                        *(u8 *)((a0_2 + 7)) = v1;
                        a1_2 = a1_2 + 8;
                        a0_2 = a0_2 + 8;
                    } while (v0 != 0);
                }
                if (a3_2 < (s32)size) {
                    tail_src = s1 + a3_2;
                    v0 = (u32)g_ucEtoI_RpcBuff;
                    tail_dst = (u8 *)g_ucEtoI_RpcBuff + a3_2;
                    do {
                        v1 = *tail_src;
                        a3_2 = a3_2 + 1;
                        *tail_dst = v1;
                        tail_src = tail_src + 1;
                        tail_dst = tail_dst + 1;
                    } while (a3_2 < (s32)size);
                }
            }
        }
        a0_2 = s5;
        a1_2 = s4;
        a2_2 = (s32)size;
        a3_2 = s2;
        v0 = _CallRpc(a0_2, a1_2, a2_2, a3_2);
    }
    return v0;
}


u32 fsmfstrm_CallRpc(s32 command, s32 mode, ...) {
    extern u32 _CallRpc(s32, s32, u32, u32);
    s32 count;
    u32 savedMode;
    u8 *buffer;
    s32 result;
    char *args;
    count = 10000000;
    savedMode = mode;
    buffer = (u8 *)g_ucEtoI_RpcBuff;
    while (sceSifCheckStatRpc((void *)s_scdRpc) == 1) {
        if (count < 0) { result = 0; goto ready; }
        count--;
    }
    result = 1;
ready:
    if (!result) return -1;
    args = (char *)__builtin_next_arg(command) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    *(u32 *)(buffer + 0) = *(u32 *)((args += 8) - 8);
    *(u32 *)(buffer + 4) = *(u32 *)((args += 8) - 8);
    *(u32 *)(buffer + 8) = *(u32 *)((args += 8) - 8);
    *(u32 *)(buffer + 12) = *(u32 *)((args += 8) - 8);
    *(u32 *)(buffer + 16) = *(u32 *)((args += 8) - 8);
    *(u32 *)(buffer + 20) = *(u32 *)((args += 8) - 8);
    *(u32 *)(buffer + 24) = *(u32 *)((args += 8) - 8);
    *(u32 *)(buffer + 28) = *(u32 *)args;
    return _CallRpc(*(s32 *)((u8 *)&command), savedMode, 32, 4);
}

u32 fsmfstrm_Init(void) {
    struct fsmf_ThreadParam param;

    if (s_iInited == 0) {
        do {
            sceSifBindRpc(s_scdRpc, 0x4010, 0);
        } while (s_scdRpc[9] == 0);
        _CallRpc(0x100, 1, 0, 0);
        param.entry = _ItoE_RpcThread;
        param.initPriority = 0x28;
        param.stackSize = 0x2000;
        param.stack = s_stack;
        param.gpReg = &_gp;
        *(s32 *)s_iRpcThrdID = CreateThread(&param);
        if (*(s32 *)s_iRpcThrdID > 0) {
            StartThread(*(s32 *)s_iRpcThrdID, 0);
        }
        _CallRpc(0x300, 1, 0, 0);
        mstrm_Init();
        s_iInited = 1;
    }
}

void fsmfstrm_ThreadInit(s32 a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */) {
    mstrm_ThreadInit(a0, a1, a2);
    return;
}


void fsmfstrm_DmaInit(void) {
    u32 a0;
    s32 v1;
    s32 s0;
    u32 v0;

    v0 = 0x980000;
    a0 = (u32)s_scdRpc;
    s0 = 0x980000 | 0x9680;
    v0 = sceSifCheckStatRpc((void *)s_scdRpc);
    v1 = 1;
    if (v0 == (u32)v1) {
        do {
            if (s0 >= 0) {
                goto _L0019E510;
            }
            v1 = 0;
            goto _L0019E538;
            _L0019E510:;
            a0 = (u32)s_scdRpc;
            s0 = s0 + -1;
            v0 = sceSifCheckStatRpc((void *)s_scdRpc);
            v1 = 1;
        } while (v0 == (u32)v1);
    }
    v1 = 1;
    _L0019E538:;
    a0 = 0x400;
    if (v1 != 0) {
        _CallRpc(a0, 1, 0, 0);
    }
    return;
}

u32 fsmfstrm_AllocDmaBuffer(s32 a0 /* r4 */) {
    s32 a2;
    s32 s0;
    u32 a1;
    u32 v1;
    s32 v0;
    s32 a0_2;
    u8 stackFrame_2C[4] __attribute__((aligned(4)));

    v0 = 0x980000;
    *(u32 *)((u8 *)&stackFrame_2C[0]) = a0;
    s0 = 0x980000 | 0x9680;
    a0_2 = (s32)s_scdRpc;
    v0 = sceSifCheckStatRpc((void *)s_scdRpc);
    v1 = 1;
    if ((u32)v0 == v1) {
        do {
            if (s0 >= 0) {
                goto _L0019E430;
            }
            v0 = 0;
            goto _L0019E458;
            _L0019E430:;
            a0_2 = (s32)s_scdRpc;
            s0 = s0 + -1;
            v0 = sceSifCheckStatRpc((void *)s_scdRpc);
            v1 = 1;
        } while ((u32)v0 == v1);
    }
    v0 = 1;
    _L0019E458:;
    if ((u32)v0 == 0) {
        v0 = -1;
    } else {
        a1 = (u32)((u8 *)&stackFrame_2C[0]);
        if ((u32)((u8 *)&stackFrame_2C[0]) != 0) {
            a2 = 0;
            a0_2 = (s32)g_ucEtoI_RpcBuff;
            do {
                v1 = *(u8 *)a1;
                a2 = a2 + 1;
                *(u8 *)a0_2 = v1;
                a1 = a1 + 1;
                a0_2 = a0_2 + 1;
            } while (a2 < (s32)4);
        }
        a2 = 4;
        a0_2 = 0x600;
        a1 = 1;
        v0 = _CallRpc(a0_2, a1, a2, a2);
    }
    return v0;
}

u32 fsmfstrm_AllocStream(s32 a0 /* r4 */) {
    u32 s1;
    u32 s0;
    s32 a0_2; // a0
    u32 v0;

    s1 = a0;
    v0 = mstrm_CreateStream();
    s0 = v0;
    if ((s32)s0 < 0) {
        return v0;
    }
    a0_2 = s0;
    if ((u32)mstrm_AllocIopStream(s0, s1) == 0) {
        mstrm_DeleteStream(a0_2);
        return -1;
    } else {
        return s0;
    }
    return v0;
}

void fsmfstrm_AllocStreamBuffer(s32 a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */, s32 a3 /* r7 */) {
    mstrm_AllocStreamBuffer(a0, a1, a2, a3);
    return;
}

void fsmfstrm_FreeStreamBuffer(s32 a0 /* r4 */) {
    mstrm_FreeStreamBuffer(a0);
    return;
}

s32 fsmfstrm_AttachSector(s32 a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */, s32 a3 /* r7 */) {
    return mstrm_AttachSector(a0, a1, a2, a3);
}

void fsmfstrm_DetachFileSector(s32 a0 /* r4 */) {
    mstrm_DetachFileSector(a0);
    return;
}

void fsmfstrm_SetReloadSize(s32 a0 /* r4 */, s32 a1 /* r5 */) {
    mstrm_SetReloadSize(a0, a1);
    return;
}

void fsmfstrm_SetReadStart(s32 a0 /* r4 */, s32 a1 /* r5 */) {
    mstrm_SetReadStart(a0, a1);
    return;
}

void fsmfstrm_SetReadPacketSize(s32 a0 /* r4 */) {
    u32 a2;

    a2 = a0;
    a0 = 0x10000 | 0x1000;
    fsmfstrm_CallRpc(a0, 0, a2);
    return;
}
u32 fsmfstrm_SetCdRMode(s32 mode, struct CdMode *settings) {
    s32 timeout;
    u32 result;
    struct CdModePacket { s32 mode; struct CdMode settings; } packet __attribute__((aligned(8))) = {0};
    packet.mode = mode;
    packet.settings = *settings;
    if (0 <= mode) {
        if (mode < 8) goto valid;
    }
    result = 0;
    goto end;
valid:
    if (!settings) return 0;
    timeout = 10000000;
    result = sceSifCheckStatRpc((void *)s_scdRpc);
    if (result == 1) {
        do {
            if (timeout >= 0) goto retry;
            result = 0;
            goto waited;
retry:
            timeout--;
            result = sceSifCheckStatRpc((void *)s_scdRpc);
        } while (result == 1);
    }
    result = 1;
waited:
    if (!result) result = -1;
    else {
        s32 i;
        u8 *source = (u8 *)&packet;
        u8 *dest;
        if (source) {
            i = 0;
            dest = (u8 *)g_ucEtoI_RpcBuff;
            do {
                u32 value = *source;
                i++;
                *dest = value;
                source++;
                dest++;
            } while (i < 8);
        }
        result = _CallRpc(0xf000, 1, 8, 4);
    }
end:
    return result;
}

s32 fsmfstrm_DmaReadSyncBlock(s32 a0 /* r4 */, s32 a1 /* r5 */) {
    return mstrm_ReadSync(a0, a1);
}

void fsmfstrm_GetIopIndex(s32 a0 /* r4 */) {
    mstrm_GetIopIndex(a0);
    return;
}

void fsmfstrm_SetReadEndCallBack(s32 a0 /* r4 */) {
    mfstrm_SetReadEndCallBack(a0);
    return;
}

void fsmfstrm_SetReadErrorCallBack(s32 a0 /* r4 */) {
    mfstrm_SetReadErrorCallBack(a0);
    return;
}
