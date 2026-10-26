#include "common.h"

/* sbuf_GetBufferSize @ 0x19FA70 .. 0x19FAC0 (0x50 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x19fa80 writes a register its branch at 0x19fa7c reads
 *   delay: addiu at 0x19faa8 writes a register its branch at 0x19faa4 reads
 */

extern u8 s_StrmBuffMng[];

/* sbuf_ClearData @ 0x19FB20 .. 0x19FB88 (0x68 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x19fb30 writes a register its branch at 0x19fb2c reads
 */

extern u8 s_StrmBuffMng[];

static u8 s_StrmBuffMng[16] = {0, 0, 8, 0, 0xff, 0xff};
static u16 s_SinTable[128] = {
    0x0,0xca,0x195,0x25f,0x32a,0x3f4,0x4be,0x588,0x652,0x71c,0x7e5,0x8ae,0x976,0xa3f,0xb06,0xbce,
    0xc95,0xd5b,0xe21,0xee6,0xfab,0x106f,0x1133,0x11f6,0x12b8,0x1379,0x143a,0x14fa,0x15b9,0x1677,0x1734,0x17f1,
    0x18ac,0x1967,0x1a20,0x1ad9,0x1b90,0x1c46,0x1cfc,0x1db0,0x1e63,0x1f14,0x1fc5,0x2074,0x2122,0x21cf,0x227a,0x2324,
    0x23cd,0x2474,0x251a,0x25bf,0x2661,0x2703,0x27a3,0x2841,0x28de,0x2979,0x2a12,0x2aaa,0x2b41,0x2bd5,0x2c68,0x2cf9,
    0x2d88,0x2e16,0x2ea1,0x2f2b,0x2fb3,0x3039,0x30be,0x3140,0x31c1,0x323f,0x32bc,0x3336,0x33af,0x3425,0x349a,0x350c,
    0x357c,0x35ea,0x3657,0x36c1,0x3728,0x378e,0x37f2,0x3853,0x38b2,0x390f,0x396a,0x39c2,0x3a18,0x3a6c,0x3abe,0x3b0d,
    0x3b5a,0x3ba4,0x3bed,0x3c33,0x3c76,0x3cb8,0x3cf6,0x3d33,0x3d6d,0x3da5,0x3dda,0x3e0d,0x3e3d,0x3e6b,0x3e97,0x3ec0,
    0x3ee6,0x3f0a,0x3f2c,0x3f4b,0x3f68,0x3f82,0x3f9a,0x3faf,0x3fc2,0x3fd2,0x3fe0,0x3feb,0x3ff4,0x3ffa,0x3ffe,0x3fff
};
extern int WaitSema(int);
extern int SignalSema(int);
extern u32 PollSema(u8 *);
static u16 s_SurroundVol[0x42];
static u8 s_StatPack[0x48];
static u16 s_StrmBuffInfo[0x80];

static u32 s_SemaID[8];


/* sbuf_CancelReadBlock @ 0x19FCA0 .. 0x19FD3C (0x9c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: daddu at 0x19fcb8 writes a register its branch at 0x19fcb4 reads
 *   delay: daddu at 0x19fce0 writes a register its branch at 0x19fcdc reads
 *   delay: daddu at 0x19fcf8 writes a register its branch at 0x19fcf4 reads
 */

extern int SignalSema(int);
static u32 s_SemaID[8];

extern int WaitSema(int);

typedef struct { u8 *base; u8 *rd; u8 *wr; s32 size; s32 margin; u8 *wr_end; s32 pad; s16 id; } SBufRB;
typedef struct { u8 *addr; s32 size; } SBufRBlk;


/* sbuf_FreeStreamBuffer @ 0x19FFF0 .. 0x1A0088 (0x98 bytes, frame 0x20) */

extern int WaitSema(int);
extern int DeleteSema(int);
void _sbuf_ReleaseStrmBufInfo(u32 a0 );
extern void _sbuf_ReleaseStrmBufInfo(u32);
static u32 s_SemaID[8];
u32 _sbuf_GetStrmBufInfo(void);

/* sbuf_AllocStreamBuffer @ 0x1A0090 .. 0x1A0188 (0xf8 bytes, frame 0x60) */

extern u32 _sbuf_GetStrmBufInfo(void);
extern int CreateSema(void *);
extern u16 s_StrmBuffInfo[];

/* strm_SetReadStart @ 0x1A0450 .. 0x1A0484 (0x34 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   call: fsmfstrm_CallRpc is declared void but its v0 is read: called as returning u32
 */

extern void fsmfstrm_CallRpc(u8 *, u32, ...);
u32 sbuf_SyncReadBlock(u8 *block, s32 wait);

/* strm_ReadSync @ 0x1A0500 .. 0x1A0528 (0x28 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   call: sbuf_SyncReadBlock is declared void but its v0 is read: called as returning u32
 */

extern u32 sbuf_SyncReadBlock(u8 *, s32);

/* strm_Close @ 0x1A07E0 .. 0x1A0898 (0xb8 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1a080c writes a register its branch at 0x1a0808 reads
 *   cfg: kept branch: 0x1a0828 if (..) goto .L001A0848
 */

extern u32 sbuf_SyncReadBlock(u8 *, s32);
extern void fsmfstrm_CallRpc(u8 *, u32, ...);

extern int printf(const char *, ...);
extern int sprintf(char *, const char *, ...);
extern u32 fsmfstrm_CallRpcStruct(u8 *, s32, u8 *, s32, u8 *);

/* fssdivagSetPlayEndCallBack @ 0x1A0A60 .. 0x1A0A68 (0x8 bytes) */

static u32 Vol_r_198;
static u32 Vol_l_197;
static u32 s_pfPlayEndCB;

/* fssdivagSetPlayStartCallBack @ 0x1A0A70 .. 0x1A0A78 (0x8 bytes) */

static u32 s_pfPlayStartCB;

/* fssdivagSetDmaChannel @ 0x1A0A80 .. 0x1A0A94 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x1a0a8c leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 fssdCallRpc();

/* fssdivagSetTrackReverb @ 0x1A0AA0 .. 0x1A0AB8 (0x18 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x1a0ab0 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 fssdCallRpc();

/* fssdivagSetCoreVoice @ 0x1A0AC0 .. 0x1A0AD4 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x1a0acc leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 fssdCallRpc();

/* fssdivagGetTrackStat @ 0x1A0AE0 .. 0x1A0B10 (0x30 bytes) */

extern u8 s_StatPack[];

/* fssdivagUpdateTrackStat @ 0x1A0B10 .. 0x1A0B5C (0x4c bytes, frame 0x10) */

extern signed int fssdCallRpcStruct(s32, s32, u32, s32, s32, void *);
extern unsigned int *fssdGetCalledRpcResult(void);
extern void *memcpy();
extern u8 s_StatPack[];
s16 _Cosf(s32 angle);

extern s16 _Cosf(s32);
s16 _Sinf(s32 angle);
extern s16 _Sinf(s32);
extern u16 s_SurroundVol[];


/* fssdivagSetMasterVolume @ 0x1A0CE0 .. 0x1A0CF8 (0x18 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x1a0cf0 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 fssdCallRpc();

/* fssdivagSetChVolume @ 0x1A0D00 .. 0x1A0D24 (0x24 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x1a0d1c leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 fssdCallRpc();

/* fssdivagGetChNum @ 0x1A0D30 .. 0x1A0D44 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x1a0d3c leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 fssdCallRpc();

/* fssdivagPause @ 0x1A0D50 .. 0x1A0D64 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x1a0d5c leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 fssdCallRpc();

/* fssdivagStop @ 0x1A0D70 .. 0x1A0D84 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x1a0d7c leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 fssdCallRpc();

/* fssdivagPlay @ 0x1A0D90 .. 0x1A0DA4 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x1a0d9c leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 fssdCallRpc();

/* fssdivagSetSpuMemory @ 0x1A0DB0 .. 0x1A0DC8 (0x18 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x1a0dc0 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 fssdCallRpc();

/* fssdivagSetPacket @ 0x1A0DD0 .. 0x1A0DE4 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x1a0ddc leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 fssdCallRpc();

/* fssdivagReserveSetup @ 0x1A0E50 .. 0x1A0E90 (0x40 bytes, frame 0x20) */

extern u32 fsmfstrm_GetIopIndex(u32, u32);

/* fssdivagInit @ 0x1A0E90 .. 0x1A0EE4 (0x54 bytes, frame 0x10) */

extern signed int fssdCallRpcVoid(s32, s32, s32);
extern void fssdRegister(s32, void *);
extern signed int fssdRequireIopToEeRpc(void);
u8 * _IopToEeRpcDispatch(s32 a0 , u32 *a1 , s32 a2 , u32 *a3 );
u8 * _IopToEeRpcDispatch(s32 a0 /* r4 */, u32 *a1 /* r5 */, s32 a2 /* r6 */, u32 *a3 /* r7 */);


/* _IopToEeRpcDispatch @ 0x1A13F0 .. 0x1A1488 (0x98 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   a2 takes slot 2 only because of the ABI order
 */

static u32 s_iRpcEeToIopRet;

INCLUDE_RODATA("config/asm/nonmatchings/unklib_0019FA70", @349);

INCLUDE_RODATA("config/asm/nonmatchings/unklib_0019FA70", @350);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * _IopToEeRpcDispatch(s32 a0 , u32 *a1 , s32 a2 , u32 *a3 );
s16 _Sinf(s32 angle);
s16 _Cosf(s32 angle);
u32 fssdivagInit(void);
void fssdivagReserveSetup(u8 *a0 , s32 a1 );
u32 fssdivagGetReserveSetupResult(s32 a0 );
void fssdivagSetPacket(s32 a0 );
void fssdivagSetSpuMemory(s32 a0 , s32 a1 );
void fssdivagPlay(u8 *a0 );
void fssdivagStop(u8 *a0 );
void fssdivagPause(u8 *a0 );
void fssdivagGetChNum(u8 *a0 );
void fssdivagSetChVolume(u8 *a0 , u8 *a1 , s32 a2 , s32 a3 );
void fssdivagSetMasterVolume(s32 a0 , s32 a1 );
void fssdivagSetVolumePack(u16 *a0 , u32 a1 );
void fssdivagUpdateTrackStat(void);
u32 fssdivagGetTrackStat(u8 *a0 );
void fssdivagSetCoreVoice(s32 a0 );
void fssdivagSetTrackReverb(u8 *a0 , u8 *a1 );
void fssdivagSetDmaChannel(s32 a0 );
void fssdivagSetPlayStartCallBack(u8 *a0 );
void fssdivagSetPlayEndCallBack(u8 *a0 );
u32 strm_InitInfo(u8 *a0 );
u32 strm_OpenSector(u8 *stream, s32 sector, s32 size, s32 mode);
u32 strm_Close(u8 *a0 );
u32 strm_AttachStreamBuffer(u8 *a0 , s32 a1 );
u32 strm_DetachStreamBuffer(u32 *a0 );
u32 strm_Read(u8 *streamArg, s32 requested);
void strm_EndReading(u8 *a0 );
u32 strm_ReadSync(u32 *a0 , s32 a1 );
u32 strm_RequiredReading(u32 *a0 );
u32 strm_SetReloadSize(u32 *a0 , s32 a1 );
u32 strm_SetReadStart(u32 *a0 , s32 a1 );
u32 _sbuf_GetStrmBufInfo(void);
void _sbuf_ReleaseStrmBufInfo(u32 a0 );
void sbuf_Init(void);
u32 sbuf_AllocStreamBuffer(s32 a0 , s32 a1 );
void sbuf_FreeStreamBuffer(u8 *a0 );
u32 sbuf_AllocReadBlock(u8 *a0, u32 *a1);
u32 sbuf_FreeReadBlock(u8 *a0 );
u32 sbuf_CancelReadBlock(u8 *a0 );
u32 sbuf_SyncReadBlock(u8 *block, s32 wait);
u32 sbuf_ClearData(u32 *a0 );
u32 sbuf_RequiredRead(u32 *a0 );
u32 sbuf_GetBufferSize(u32 *a0 );


u8 * _IopToEeRpcDispatch(s32 a0 /* r4 */, u32 *a1 /* r5 */, s32 a2 /* r6 */, u32 *a3 /* r7 */) {
    u32 v0;
    u32 *s1;
    u32 *s0;

    v0 = 0xfff0000;
    v0 = 0x1000000;
    s1 = a1;
    s0 = a3;
    switch ((u32)(a0 & 0xfff0000)) {
    case 16777216:
        v0 = s_pfPlayStartCB;
        if (v0 != 0) {
            a0 = *(s32 *)s1;
            if ((u32)a0 != 0) {
                ((void (*)(s32, u32, u32, u32))(s32)v0)(a0, (u32)a1, a2, (u32)a3);
            }
        }
        v0 = s_pfPlayEndCB;
        if (v0 != 0) {
            a0 = *(s32 *)(((u8 *)s1 + 4));
            if ((u32)a0 != 0) {
                ((void (*)(s32))(s32)v0)(a0);
            }
        }
        s_iRpcEeToIopRet = 0;
    }
    *(u32 *)s0 = 4;
    return (u8 *)(u32)&s_iRpcEeToIopRet;
}


/* _Sinf @ 0x1A0EF0 .. 0x1A1170 (0x280 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1a0f84 writes a register its branch at 0x1a0f80 reads
 *   cfg: kept branch: 0x1a0f5c if (..) goto .L001A0F68
 */

s16 _Sinf(s32 angle) {
    s32 index,weight,offset,first,next; s16 result;
    while(angle>2048) angle-=2048;
    while(angle<0) angle+=2048;
    offset=angle&511;
    index=offset>>2;
    weight=4-offset%4;
    switch((u32)(angle>>9)) {
    case 0:
        if(index<=126) {
            next=(s16)s_SinTable[index+1];
            first=(s16)s_SinTable[index];
            result=(s16)(next+weight*(first-next)/4);
        } else result=(s16)s_SinTable[127];
        break;
    case 1:
        if(index>0) {
            first=(s16)s_SinTable[127-index];
            next=(s16)s_SinTable[128-index];
            result=(s16)(first+weight*(next-first)/4);
        } else result=(s16)s_SinTable[127];
        break;
    case 2:
        if(index<=126) {
            next=(s16)s_SinTable[index+1];
            first=(s16)s_SinTable[index];
            result=(s16)-(next+weight*(first-next)/4);
        } else result=(s16)-(s16)s_SinTable[127];
        break;
    case 3:
        if(index>0) {
            first=(s16)s_SinTable[127-index];
            next=(s16)s_SinTable[128-index];
            result=(s16)-(first+weight*(next-first)/4);
        } else result=(s16)-(s16)s_SinTable[127];
        break;
    default:result=0;break;
    }
    return result;
}

/* _Cosf @ 0x1A0EF0 .. 0x1A1170 (0x280 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1a0f84 writes a register its branch at 0x1a0f80 reads
 *   cfg: kept branch: 0x1a0f5c if (..) goto .L001A0F68
 */

s16 _Cosf(s32 angle) {
    s32 index,weight,offset,first,next; s16 result;
    angle+=512;
    while(angle>2048) angle-=2048;
    while(angle<0) angle+=2048;
    offset=angle&511;
    index=offset>>2;
    weight=4-offset%4;
    switch((u32)(angle>>9)) {
    case 0:
        if(index<=126) {
            next=(s16)s_SinTable[index+1];
            first=(s16)s_SinTable[index];
            result=(s16)(next+weight*(first-next)/4);
        } else result=(s16)s_SinTable[127];
        break;
    case 1:
        if(index>0) {
            first=(s16)s_SinTable[127-index];
            next=(s16)s_SinTable[128-index];
            result=(s16)(first+weight*(next-first)/4);
        } else result=(s16)s_SinTable[127];
        break;
    case 2:
        if(index<=126) {
            next=(s16)s_SinTable[index+1];
            first=(s16)s_SinTable[index];
            result=(s16)-(next+weight*(first-next)/4);
        } else result=(s16)-(s16)s_SinTable[127];
        break;
    case 3:
        if(index>0) {
            first=(s16)s_SinTable[127-index];
            next=(s16)s_SinTable[128-index];
            result=(s16)-(first+weight*(next-first)/4);
        } else result=(s16)-(s16)s_SinTable[127];
        break;
    default:result=0;break;
    }
    return result;
}

u32 fssdivagInit(void) {
    u32 a1;
    s32 v0;

    v0 = fssdCallRpcVoid(0xa, 1, 0x10000);
    if ((u32)v0 == 0) {
        v0 = 0;
    } else {
        a1 = (u32)_IopToEeRpcDispatch;
        fssdRegister(0xa, _IopToEeRpcDispatch);
        fssdRequireIopToEeRpc();
        v0 = 1;
    }
    return v0;
}

void fssdivagReserveSetup(u8 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 s0;
    u32 v0;

    s0 = (u32)a0;
    a0 = (u8 *)a1;
    v0 = fsmfstrm_GetIopIndex((u32)a0, a1);
    a0 = (u8 *)(s32)0xa;
    a1 = 1;
    fssdCallRpc(a0, a1, 0x40000, s0, v0);
    return;
}

/* fssdivagGetReserveSetupResult @ 0x1A0DF0 .. 0x1A0E48 (0x58 bytes) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x1a0df4 if (..) goto .L001A0E00
 *   cfg: kept branch: 0x1a0df8 if (..) goto .L001A0E08
 *   cfg: kept goto: 0x1a0e00 -> .L001A0E40
 */

u32 fssdivagGetReserveSetupResult(s32 a0 /* r4 */) {
    u32 v0;
    u32 v1;

    v0 = a0 < (s32)8;
    if (a0 < 0) {
        goto _L001A0E00;
    }
    if (v0 != 0) {
        goto _L001A0E08;
    }
    _L001A0E00:;
    v0 = 0;
    goto _L001A0E40;
    _L001A0E08:;
    a0 = (u32)a0 << 3;
    v1 = (u32)s_StatPack;
    v1 = (s32)((u8 *)s_StatPack + a0);
    v0 = -1;
    v1 = *(s32 *)v1;
    if (v1 != v0) {
        return v0;
    }
    v0 = (u32)((u8 *)s_StatPack + 4);
    v0 = v0 + a0;
    v0 = *(s32 *)v0;
    _L001A0E40:;
    return v0;
}

void fssdivagSetPacket(s32 a0 /* r4 */) {
    u32 a3;

    a3 = a0;
    a0 = 0xa;
    fssdCallRpc(0xa, 1, 0x50000, a3);
    return;
}

void fssdivagSetSpuMemory(s32 a0 /* r4 */, s32 a1 /* r5 */) {
    u32 a3;
    u32 t0;

    a3 = a0;
    t0 = a1;
    a0 = 0xa;
    a1 = 1;
    fssdCallRpc(0xa, 1, 0x60000, a3, t0);
    return;
}

void fssdivagPlay(u8 *a0 /* r4 */) {
    u32 a3;

    a3 = (u32)a0;
    a0 = (u8 *)0xa;
    fssdCallRpc(0xa, 1, 0x70000, a3);
    return;
}

void fssdivagStop(u8 *a0 /* r4 */) {
    u32 a3;

    a3 = (u32)a0;
    a0 = (u8 *)0xa;
    fssdCallRpc(0xa, 1, 0x80000, a3);
    return;
}

void fssdivagPause(u8 *a0 /* r4 */) {
    u32 a3;

    a3 = (u32)a0;
    a0 = (u8 *)0xa;
    fssdCallRpc(0xa, 1, 0x90000, a3);
    return;
}

void fssdivagGetChNum(u8 *a0 /* r4 */) {
    u32 a3;

    a3 = (u32)a0;
    a0 = (u8 *)0xa;
    fssdCallRpc(0xa, 1, 0xc0000, a3);
    return;
}

void fssdivagSetChVolume(u8 *a0 /* r4 */, u8 *a1 /* r5 */, s32 a2 /* r6 */, s32 a3 /* r7 */) {
    u32 v0;
    u32 t0;
    u16 t1;
    u16 t2;

    v0 = (u32)a0;
    t0 = (u32)a1;
    t1 = (u16)a2;
    t2 = (u16)a3;
    a0 = (u8 *)0xa;
    a3 = v0;
    a1 = (u8 *)1;
    a2 = 0xa0000;
    fssdCallRpc(0xa, 1, 0xa0000, a3, t0, t1, t2);
    return;
}

void fssdivagSetMasterVolume(s32 a0 /* r4 */, s32 a1 /* r5 */) {
    u16 a3;
    u16 t0;

    a3 = (u16)a0;
    t0 = (u16)a1;
    a0 = 0xa;
    a1 = 1;
    fssdCallRpc(0xa, 1, 0xb0000, a3, t0);
    return;
}

void fssdivagSetVolumePack(u16 *a0 /* r4 */, u32 a1 /* r5 */) {
    s32 a2;
    u16 *s6;
    register s32 s5 = (s32)a1;
    s32 s4;
    u8 *s3;
    s32 s2;
    s32 s1;
    u8 *s0;
    u16 *a0_2; // a0
    u32 v1;
    u32 v0_2; // v0
    u32 v0_3; // v0
    u32 v0;

    if (s5 > (s32)0x10) {
        s5 = 0x10;
    }
    *(u32 *)s_SurroundVol = s5;
    s4 = 0;
    if (0 < s5) {
        s0 = (u8 *)a0;
        s6 = s_SurroundVol;
        do {
            s1 = *(s16 *)(s0 + 6);
            s2 = *(s16 *)(s0 + 4);
            s3 = (u8 *)(u8 *)(s6 + 2);
            if (s1 > (s32)0x7ff) {
                s1 = 0x7ff;
            }
            if (s1 < 0) {
                s1 = 0;
            }
            Vol_l_197 = (s2 * _Cosf(s1)) / 0x3fff;
            Vol_r_198 = (s2 * _Sinf(s1)) / 0x3fff;
            s4 = s4 + 1;
            s6 += 4;
            *(u16 *)(s3 + 4) = Vol_l_197;
            *(u16 *)(s3 + 6) = Vol_r_198;
            *(u16 *)s3 = *(s16 *)s0;
            *(u16 *)(s3 + 2) = *(s16 *)(s0 + 2);
            s0 = (u8 *)(s0 + 8);
        } while (s4 < s5);
    }
    fssdCallRpcStruct(0xa, 0, (u32)((u32)s5 << 3) + 4, 4, 0xd0000, (void *)s_SurroundVol);
    return;
}

void fssdivagUpdateTrackStat(void) {
    u32 a0;
    u8 *v0;

    fssdCallRpcStruct(0xa, 1, 0, 0x48, 0xe0000, 0);
    v0 = (u8 *)fssdGetCalledRpcResult();
    a0 = (u32)s_StatPack;
    memcpy(s_StatPack, (u32)v0, (s32)0x48);
    return;
}

u32 fssdivagGetTrackStat(u8 *a0 /* r4 */) {
    u32 v0;

    if ((s32)a0 < 0 || (s32)a0 >= (s32)8) {
        v0 = -1;
    } else {
        v0 = (u32)(u8 *)(s_StatPack + 0x40);
        v0 = (s32)((u8 *)v0 + (u32)(a0));
        v0 = *(u8 *)v0;
    }
    return v0;
}

void fssdivagSetCoreVoice(s32 a0 /* r4 */) {
    u32 a3;

    a3 = a0;
    a0 = 0xa;
    fssdCallRpc(0xa, 1, 0xf0000, a3);
    return;
}

void fssdivagSetTrackReverb(u8 *a0 /* r4 */, u8 *a1 /* r5 */) {
    u32 a3;
    u32 t0;

    a3 = (u32)a0;
    t0 = (u32)a1;
    a0 = (u8 *)0xa;
    a1 = (u8 *)0;
    fssdCallRpc(0xa, 0, 0x140000, a3, t0);
    return;
}

void fssdivagSetDmaChannel(s32 a0 /* r4 */) {
    u32 a3;

    a3 = a0;
    a0 = 0xa;
    fssdCallRpc(0xa, 1, 0x100000, a3);
    return;
}

void fssdivagSetPlayStartCallBack(u8 *a0 /* r4 */) {
    s_pfPlayStartCB = (u32)a0;
    return;
}

void fssdivagSetPlayEndCallBack(u8 *a0 /* r4 */) {
    s_pfPlayEndCB = (u32)a0;
    return;
}


/* strm_InitInfo @ 0x1A0A20 .. 0x1A0A58 (0x38 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 strm_InitInfo(u8 *a0 /* r4 */) {
    if ((u32)(a0) != 0) {
        *(u32 *)(((u8 *)a0 + 4)) = 0;
        *(u32 *)(((u8 *)a0 + 8)) = 0;
        *(u16 *)(((u8 *)a0 + 0x10)) = 0x4000;
        *(u32 *)(((u8 *)a0 + 0x14)) = 0;
        *(u32 *)(((u8 *)a0 + 0x18)) = 0;
        *(u32 *)(((u8 *)a0 + 0x1c)) = 0;
        *(u32 *)a0 = -1;
        *(u8 *)(((u8 *)a0 + 0x20)) = 0;
    }
    return;
}
u32 strm_OpenSector(u8 *stream, s32 sector, s32 size, s32 mode)
{
    u32 result;
    if (!stream) return 0;
    if ((u32)(*(s32 *)(stream + 0x14) - 2) <= 1 || *(s32 *)(stream + 0x14) == 7) {
        printf("%s : ERROR!!! ", __FUNCTION__);
        printf("\217\210\227\235\222\206\202\315\203A\203^\203b\203`\202\305\202\253\202\334\202\271\202\361\202\346\012");
        return 0;
    }
    {
        u32 packet[4] __attribute__((aligned(16))) = {0};
        packet[0] = *(u32 *)stream;
        packet[3] = (u16)mode;
        packet[1] = sector;
        packet[2] = size;
        result = fsmfstrm_CallRpcStruct((u8 *)0x4000, 1, (u8 *)16, 4, (u8 *)packet);
        if (result) {
            *(u32 *)(stream + 4) = size;
            *(u32 *)(stream + 8) = 0;
            *(u16 *)(stream + 0x10) = mode;
            ((struct { unsigned char first:1, second:1; } *)(stream + 0x18))->second = 1;
            ((struct { unsigned char first:1, second:1; } *)(stream + 0x18))->first = 0;
            *(u32 *)(stream + 0x14) = 0;
            sprintf((char *)stream + 0x20, "[SECTOR] : %d, [SIZE] : %d\0\0\0\0\0", sector, size);
            if (*(u32 *)(stream + 0x1c)) {
                sbuf_ClearData((u32 *)*(u32 *)(stream + 0x1c));
                *(u32 *)(stream + 0x14) = 1;
            }
        }
    }
    return result;
}

u32 strm_Close(u8 *a0 /* r4 */) {
    u8 *s0;
    u32 a1;
    s32 at;
    u32 v1;
    u32 v0;

    s0 = a0;
    if ((u32)s0 == 0) {
        v0 = 0;
        return v0;
    }
    v1 = *(s32 *)(s0 + 0x14);
    v0 = 6;
    if (v1 == v0) {
        v0 = 1;
        return v0;
    }
    if (v1 == 2 || v1 == 3 || v1 == 7) {
    if ((u32)s0 != 0) {
        a0 = (u8 *)*(s32 *)(((u8 *)0x1c + (u32)(s0)));
        sbuf_SyncReadBlock(a0, 1);
    }
    }
    a0 = (u8 *)(s32)0x5000;
    fsmfstrm_CallRpc(a0, 0, *(s32 *)s0);
    *(u32 *)(s0 + 4) = 0;
    *(u32 *)(s0 + 8) = 0;
    a1 = 0;
    v1 = 6;
    v0 = 1;
    ((struct { unsigned char f:1; } *)&*(u8 *)(s0 + 0x18))->f = 0;
    *(u32 *)(s0 + 0x14) = v1;
    *(u8 *)(s0 + 0x20) = 0;
    return v0;
}

/* strm_AttachStreamBuffer @ 0x1A0770 .. 0x1A07D8 (0x68 bytes) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x1a0794 if (..) goto .L001A07A8
 *   cfg: kept goto: 0x1a07a0 -> .L001A07D0
 */

u32 strm_AttachStreamBuffer(u8 *a0 /* r4 */, s32 a1 /* r5 */) {
    u32 v1;
    u32 v0;
    s32 at;
    u64 v0_64;

    if ((u32)a0 == 0) {
        v0 = 0;
        return v0;
    }
    v1 = *(s32 *)(a0 + 0x14);
    if (v1 == 1 || v1 == 2 || v1 == 7) {
    v0 = 0;
    goto _L001A07D0;
    }
    *(u32 *)(a0 + 0x1c) = a1;
    v0 = *(u8 *)(a0 + 0x18);
    v0_64 = (u64)((u64)v0 << 0x3e) >> 0x3f;
    v0 = 1;
    if (v0_64 != 0) {
        *(u32 *)(a0 + 0x14) = v0;
    }
    v0 = 1;
    _L001A07D0:;
    return v0;
}


/* strm_DetachStreamBuffer @ 0x1A0720 .. 0x1A0768 (0x48 bytes) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x1a0734 if (..) goto .L001A0750
 *   return without a value in a non-void function
 */

u32 strm_DetachStreamBuffer(u32 *a0 /* r4 */) {
    u32 a1;
    u32 v1;
    s32 at;

    if ((u32)a0 != 0 && (u32)(s32)a0[7] != 0) {
        a1 = (s32)a0[5];
        if (a1 == 1 || a1 == 2 || a1 == 7) {
            return;
        }
        a0[7] = 0;
        a0[5] = 0;
    }
    return;
}

u32 strm_Read(u8 *streamArg, s32 requested) {
    extern u32 fsmfstrm_CallRpc(u8 *, u32, ...);
    u32 block[2] __attribute__((aligned(8)));
    u32 *size;
    u8 *stream;
    u32 count;
    s32 result;
    u64 flags;
    s32 state;
    stream=streamArg;
    count=requested;
    if (!stream) { result=0; goto end; }
    if ((s32)count<=0) return 0;
    state=*(s32*)(stream+0x14);
    if (state==3 || state==2) { result=0; goto end; }
    flags=stream[0x18];
    if (flags&1) return 0;
    if ((flags<<62>>63)==0) return 0;
    {
        s32 position=*(s32*)(stream+8);
        s32 limit=*(s32*)(stream+4);
        if (limit<(s32)(count+position)) count=limit-position;
    }
    size=&block[1];
    *size=count;
    if (sbuf_AllocReadBlock(*(u8**)(stream+0x1c),block)) {
        s32 amount=*size;
        if ((s32)count<amount) amount=count;
        *(s32*)(stream+0x14)=2;
        *(s32*)(stream+0xc)=amount;
        {
            u32 address=*(volatile u32*)&block[0];
            u32 handle=*(u32*)stream;
            count=fsmfstrm_CallRpc((u8*)0x100000,1,handle,address,amount);
        }
        if ((s32)count<0) {
            sbuf_CancelReadBlock(*(u8**)(stream+0x1c));
            *(s32*)(stream+0x14)=4;
            *(s32*)(stream+0xc)=0;
        } else *(s32*)(stream+0x14)=3;
        return count;
    } else result=0;
end:
    return result;
}


/* strm_EndReading @ 0x1A0530 .. 0x1A05C4 (0x94 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1a0548 writes a register its branch at 0x1a0544 reads
 *   cfg: kept branch: 0x1a0548 if (..) goto .L001A05B8
 */

void strm_EndReading(u8 *a0 /* r4 */) {
    u32 a1;
    u32 v1;
    u32 v0;

    if ((u32)a0 != 0) {
        a1 = *(s32 *)(a0 + 0x14);
        if (a1 != (u32)2) {
            if (a1 != (u32)3) {
                goto _L001A05B8;
            }
        }
        *(u32 *)(a0 + 8) = *(s32 *)(a0 + 8) + *(s32 *)(a0 + 0xc);
        *(u32 *)(a0 + 0xc) = 0;
        v1 = *(s32 *)(a0 + 8);
        v0 = (s32)v1 < (s32)*(s32 *)(a0 + 4);
        if (v0 == 0) {
            a1 = 1;
            v0 = 5;
            ((struct { unsigned char f:1; } *)&*(u8 *)(a0 + 0x18))->f = 1;
            *(u32 *)(a0 + 0x14) = v0;
        } else {
            v0 = 4;
            *(u32 *)(a0 + 0x14) = v0;
        }
        a0 = (u8 *)*(s32 *)(a0 + 0x1c);
        sbuf_FreeReadBlock(a0);
    }
    _L001A05B8:;
    return;
}

u32 strm_ReadSync(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    extern u32 sbuf_SyncReadBlock(u8 *, s32);
    u32 v0;

    if ((u32)a0 == 0) {
        v0 = 0;
    } else {
        v0 = sbuf_SyncReadBlock((u8 *)*(s32 *)(((u8 *)a0 + 0x1c)), a1);
    }
    return v0;
}


/* strm_RequiredReading @ 0x1A04D0 .. 0x1A04F8 (0x28 bytes, frame 0x10) */

u32 strm_RequiredReading(u32 *a0 /* r4 */) {
    u32 v0;

    if ((u32)a0 == 0) {
        v0 = 0;
    } else {
        v0 = sbuf_RequiredRead((u32 *)*(s32 *)(((u8 *)a0 + 0x1c)));
    }
    return v0;
}


/* strm_SetReloadSize @ 0x1A0490 .. 0x1A04C4 (0x34 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   call: fsmfstrm_CallRpc is declared void but its v0 is read: called as returning u32
 */



u32 strm_SetReloadSize(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    extern u32 fsmfstrm_CallRpc(u8 *, u32, ...);
    u32 a3;
    u32 v0;

    a3 = a1;
    if ((u32)a0 == 0) {
        v0 = 0;
    } else {
        v0 = fsmfstrm_CallRpc((u8 *)0xa000, 1, *(s32 *)a0, a3);
    }
    return v0;
}

u32 strm_SetReadStart(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    extern u32 fsmfstrm_CallRpc(u8 *, u32, ...);
    u32 a3;
    u32 v0;

    a3 = a1;
    if ((u32)a0 == 0) {
        v0 = 0;
    } else {
        v0 = fsmfstrm_CallRpc((u8 *)0xb000, 1, *(s32 *)a0, a3);
    }
    return v0;
}

/* _sbuf_GetStrmBufInfo @ 0x1A0360 .. 0x1A0448 (0xe8 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1a0370 writes a register its branch at 0x1a036c reads
 *   delay: daddu at 0x1a038c writes a register its branch at 0x1a0388 reads
 */

u32 _sbuf_GetStrmBufInfo(void) {
    s32 a2;
    s32 a1;
    s32 a0;
    u32 v1;
    u32 v0;

    v0 = s_StrmBuffMng[8];
    if ((u32)(v0 & 1) == 0) {
        return 0;
    }
    v0 = *(s16 *)(s_StrmBuffMng + 2);
    if (v0 == 0) {
        return 0;
    }
    a2 = *(s16 *)s_StrmBuffMng;
    v0 = (u32)s_StrmBuffInfo;
    v1 = -1;
    v0 = (s32)((u8 *)s_StrmBuffInfo + (s32)((u32)a2 << 5));
    a0 = *(s16 *)((v0 + 0x18));
    *(u16 *)s_StrmBuffMng = a0;
    a0 = *(s16 *)s_StrmBuffMng;
    if ((u32)a0 != v1) {
        a1 = *(s16 *)((v0 + 0x1a));
        v1 = (u32)(u8 *)(s_StrmBuffInfo + 0xd);
        *(u16 *)(u32)(v1 + (s32)((u32)a0 << 5)) = a1;
    }
    a0 = *(s16 *)(s_StrmBuffMng + 2);
    v1 = -1;
    *(u16 *)(s_StrmBuffMng + 2) = a0 + -1;
    a1 = *(s16 *)(s_StrmBuffMng + 4);
    if ((u32)a1 != v1) {
        v1 = (u32)(u8 *)(s_StrmBuffInfo + 0xd);
        *(u16 *)(u32)(v1 + (s32)((u32)a1 << 5)) = a2;
    }
    *(u16 *)((v0 + 0x18)) = a1;
    *(u16 *)(s_StrmBuffMng + 4) = a2;
    v1 = *(s16 *)(s_StrmBuffMng + 6);
    *(u16 *)(s_StrmBuffMng + 6) = v1 + 1;
    return v0;
}


/* _sbuf_ReleaseStrmBufInfo @ 0x1A0250 .. 0x1A0358 (0x108 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */

void _sbuf_ReleaseStrmBufInfo(u32 a0 /* r4 */) {
    s32 a3;
    s32 a2;
    s32 a1;
    u32 v1;

    v1 = s_StrmBuffMng[8];
    v1 = v1 & 1;
    if (v1 != 0 && a0) {
        a1 = *(s16 *)((a0 + 0x1a));
        v1 = -1;
        if ((u32)a1 != v1) {
            a2 = *(s16 *)((a0 + 0x18));
            v1 = (u32)(u8 *)(s_StrmBuffInfo + 0xc);
            *(u16 *)(u32)(v1 + (s32)((u32)a1 << 5)) = a2;
        }
        a1 = *(s16 *)((a0 + 0x18));
        v1 = -1;
        if ((u32)a1 != v1) {
            a2 = *(s16 *)((a0 + 0x1a));
            v1 = (u32)(u8 *)(s_StrmBuffInfo + 0xd);
            *(u16 *)(u32)(v1 + (s32)((u32)a1 << 5)) = a2;
        }
        a1 = *(s16 *)((a0 + 0x1c));
        v1 = *(s16 *)(s_StrmBuffMng + 4);
        if ((u32)a1 == v1) {
            v1 = *(s16 *)((a0 + 0x18));
            *(u16 *)(s_StrmBuffMng + 4) = v1;
        }
        a1 = *(s16 *)(s_StrmBuffMng + 6);
        v1 = -1;
        *(u16 *)(s_StrmBuffMng + 6) = a1 + -1;
        a3 = *(s16 *)s_StrmBuffMng;
        if ((u32)a3 != v1) {
            a2 = *(s16 *)((a0 + 0x1c));
            v1 = (u32)(u8 *)(s_StrmBuffInfo + 0xd);
            *(u16 *)(u32)(v1 + (s32)((u32)a3 << 5)) = a2;
        }
        *(u16 *)((a0 + 0x18)) = a3;
        *(s16 *)((a0 + 0x1a)) = -1;
        a0 = *(s16 *)((a0 + 0x1c));
        v1 = *(s16 *)(s_StrmBuffMng + 2);
        v1 = v1 + 1;
        *(u16 *)s_StrmBuffMng = a0;
        *(u16 *)(s_StrmBuffMng + 2) = v1;
    }
    return;
}

/* sbuf_Init @ 0x1A0190 .. 0x1A0250 (0xc0 bytes) */

void sbuf_Init(void) {
    s32 t0;
    u8 *a3;
    u32 *a2;
    u32 a1;
    u32 a0;
    u32 v1;

    v1 = s_StrmBuffMng[8];
    v1 = v1 & 1;
    if (v1 == 0) {
        t0 = 0;
        a3 = (u8 *)s_StrmBuffInfo;
        a2 = s_SemaID;
        a1 = -1;
        do {
            *(u32 *)a3 = 0;
            *(u32 *)(a3 + 4) = 0;
            a0 = t0 + 1;
            *(u32 *)(a3 + 8) = 0;
            v1 = t0 + -1;
            *(u32 *)(a3 + 0xc) = 0;
            *(u32 *)(a3 + 0x10) = 0;
            *(u32 *)(a3 + 0x14) = 0;
            *(u16 *)(a3 + 0x18) = a0;
            *(u16 *)(a3 + 0x1a) = v1;
            *(u16 *)(a3 + 0x1c) = t0;
            t0 = t0 + 1;
            *(u32 *)a2 = a1;
            a3 = (u8 *)(a3 + 0x20);
            a2 += 1;
        } while (t0 < (s32)8);
        v1 = 8;
        *(s16 *)(s_StrmBuffInfo + 0x7c) = a1;
        a0 = 1;
        *(u16 *)(s_StrmBuffMng + 2) = v1;
        *(s16 *)(s_StrmBuffMng + 4) = a1;
        *(u16 *)s_StrmBuffMng = 0;
        *(u16 *)(s_StrmBuffMng + 6) = 0;
        ((struct { unsigned char f:1; } *)&s_StrmBuffMng[8])->f = 1;
    }
    return;
}

u32 sbuf_AllocStreamBuffer(s32 a0 /* r4 */, s32 a1 /* r5 */) {
    u32 s2;
    u32 s1;
    u8 *s0;
    u32 v1;
    u32 v0;
    s32 a0_2;
    u8 stackFrame_40[32] __attribute__((aligned(16)));

    s2 = a0;
    v0 = s_StrmBuffMng[8];
    v0 = v0 & 1;
    s1 = a1;
    if (v0 == 0) {
        v0 = 0;
    } else {
        v0 = _sbuf_GetStrmBufInfo();
        s0 = (u8 *)v0;
        if ((u32)s0 != 0) {
            *(u32 *)(s0 + 8) = s2;
            v0 = 1;
            *(u32 *)(s0 + 4) = s2;
            a0_2 = (s32)((u8 *)&stackFrame_40[0]);
            *(u32 *)s0 = s2;
            *(u32 *)(s0 + 0xc) = s1;
            *(u32 *)(s0 + 0x10) = 0;
            v1 = *(s32 *)s0;
            *(u32 *)(s0 + 0x14) = v1;
            ((u32 *)stackFrame_40)[2] = v0;
            ((u32 *)stackFrame_40)[1] = v0;
            v0 = CreateSema((void *)a0_2);
            v1 = *(s16 *)(s0 + 0x1c);
            a0_2 = (s32)s_SemaID;
            v1 = v1 << 2;
            *(u32 *)(u32)(s32)((u8 *)s_SemaID + v1) = v0;
            v1 = *(s16 *)(s0 + 0x1c);
            {
                u32 dcomp_tmp_0;
                dcomp_tmp_0 = v1 << 2;
                v0 = dcomp_tmp_0;
            }
            v0 = (s32)((u8 *)s_SemaID + (u32)v0);
            v0 = *(s32 *)v0;
            a0_2 = (s32)s0;
            if ((s32)v0 < 0) {
                _sbuf_ReleaseStrmBufInfo(a0_2);
                v0 = 0;
            } else {
                v0 = (u32)s_StrmBuffInfo;
                v0 = (s32)((u8 *)s_StrmBuffInfo + (u32)(v1 << 5));
            }
        } else {
            v0 = 0;
        }
    }
    return v0;
}

void sbuf_FreeStreamBuffer(u8 *a0 /* r4 */) {
    s32 v1;
    u32 *v0;
    u8 *s0;

    v1 = *(u8 *)((u8 *)&s_StrmBuffMng + 8);
    v1 = v1 & 1;
    if ((u32)v1 != 0) {
        if ((u32)a0 != 0) {
            v1 = *(s16 *)(((u8 *)a0 + 0x1c));
            v0 = s_SemaID;
            s0 = a0;
            a0 = (u8 *)*(s32 *)(u32 *)(s32)((u8 *)s_SemaID + (s32)((u32)v1 << 2));
            WaitSema((int)a0);
            v1 = *(s16 *)(((u8 *)s0 + 0x1c));
            v0 = s_SemaID;
            a0 = (u8 *)*(s32 *)(u32 *)(s32)((u8 *)s_SemaID + (s32)((u32)v1 << 2));
            DeleteSema((int)a0);
            *(u32 *)(((u8 *)s0 + 8)) = 0;
            a0 = s0;
            *(u32 *)(((u8 *)s0 + 4)) = 0;
            *(u32 *)s0 = 0;
            *(u32 *)(((u8 *)s0 + 0xc)) = 0;
            *(u32 *)(((u8 *)s0 + 0x10)) = 0;
            *(u32 *)(((u8 *)s0 + 0x14)) = 0;
            _sbuf_ReleaseStrmBufInfo((u32)a0);
        }
    }
    return;
}

u32 sbuf_AllocReadBlock(u8 *a0, u32 *a1) {
    SBufRBlk *blk;
    SBufRB *sb;
    s32 free;

    blk = (SBufRBlk *)a1;
    if (!(s_StrmBuffMng[8] & 1)) {
        return 0;
    }
    if (blk == 0) {
        return 0;
    }
    if (a0 == 0) {
        return 0;
    }
    sb = (SBufRB *)a0;
    if (sb->base == 0) {
        return 0;
    }
    if (sb->wr != sb->wr_end) {
        return 0;
    }
    WaitSema(s_SemaID[sb->id]);
    if (sb->wr > sb->rd) {
        free = sb->size - (sb->wr - sb->base);
    } else if (sb->wr < sb->rd) {
        free = sb->rd - sb->wr;
    } else {
        free = sb->size - (sb->rd - sb->base);
    }
    if (free > sb->size - sb->margin) {
        free = sb->size - sb->margin;
    }
    if (free == 0) {
        SignalSema(s_SemaID[sb->id]);
        return 0;
    }
    blk->size = (blk->size + 15) & ~15;
    if (blk->size > free) {
        blk->size = free;
    }
    blk->addr = sb->wr;
    sb->wr_end = sb->wr + blk->size;
    if (sb->size <= sb->wr_end - sb->base) {
        sb->wr_end = sb->base;
    }
    return (u32)blk->addr;
}

/* sbuf_FreeReadBlock @ 0x19FD40 .. 0x19FE24 (0xe4 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: daddu at 0x19fd58 writes a register its branch at 0x19fd54 reads
 *   delay: daddu at 0x19fd80 writes a register its branch at 0x19fd7c reads
 */

u32 sbuf_FreeReadBlock(u8 *a0 /* r4 */) {
    u32 v0;
    u32 v1;

    v0 = s_StrmBuffMng[8];
    if ((u32)(v0 & 1) == 0) {
        return 0;
    }
    if ((u32)a0 == 0) {
        return 0;
    }
    v0 = *(s32 *)a0;
    if (v0 == 0) {
        return 0;
    }
    v0 = *(s32 *)(a0 + 0x14);
    if (v0 == 0) {
        v0 = 0;
    } else {
        *(u32 *)(a0 + 8) = v0;
        v1 = *(s32 *)(a0 + 4);
        v0 = *(s32 *)(a0 + 8);
        if (v1 < v0) {
            *(u32 *)(a0 + 0x10) = v0 - v1;
        } else if (v0 < (u32)v1) {
            {
                u32 dcomp_tmp_0;
                dcomp_tmp_0 = (u32)v1 - v0;
                v0 = dcomp_tmp_0;
            }
            v1 = *(s32 *)(a0 + 0xc);
            *(u32 *)(a0 + 0x10) = v1 - v0;
        } else {
            v0 = *(s32 *)(a0 + 0xc);
            *(u32 *)(a0 + 0x10) = v0;
        }
        v1 = *(s16 *)(a0 + 0x1c);
        v0 = (u32)s_SemaID;
        a0 = (u8 *)*(s32 *)(u32)(s32)((u8 *)s_SemaID + (u32)(v1 << 2));
        SignalSema((int)a0);
        v0 = 1;
    }
    return v0;
}

u32 sbuf_CancelReadBlock(u8 *a0 /* r4 */) {
    u32 v0;
    u32 v1;

    v0 = s_StrmBuffMng[8];
    if ((u32)(v0 & 1) == 0) {
        return 0;
    }
    v0 = 0;
    if ((u32)a0 == 0) {
        return v0;
    }
    v0 = *(s32 *)a0;
    if (v0 == 0) {
        return 0;
    }
    v0 = *(s32 *)(a0 + 0x14);
    if (v0 == 0) {
        return 0;
    }
    v1 = *(s32 *)(a0 + 8);
    v0 = (u32)s_SemaID;
    *(u32 *)(a0 + 0x14) = v1;
    v1 = *(s16 *)(a0 + 0x1c);
    a0 = (u8 *)*(s32 *)(u32)(s32)((u8 *)s_SemaID + (u32)(v1 << 2));
    SignalSema((int)a0);
    return 1;
}
u32 sbuf_SyncReadBlock(u8 *block, s32 wait)
{
    u32 result = 0;
    u32 saved;
    result = s_StrmBuffMng[8] & 1;
    if (result == 0) return 0;
    if (!block) return 0;
    result = *(s32 *)block;
    saved = (u32)block;
    if (result == 0) {
        result = 0;
        goto finished;
    }
    result = *(s32 *)(saved + 0x14);
    if (result == 0) return 0;
    if (wait) {
        WaitSema(s_SemaID[*(s16 *)(saved + 0x1c)]);
        SignalSema(s_SemaID[*(s16 *)(saved + 0x1c)]);
        result = 0;
    } else {
        result = PollSema((u8 *)s_SemaID[*(s16 *)(saved + 0x1c)]);
        if ((s32)result < 0) result = 1;
        else {
            SignalSema(s_SemaID[*(s16 *)(saved + 0x1c)]);
            result = 0;
        }
    }
finished:
    return result;
}

u32 sbuf_ClearData(u32 *a0 /* r4 */) {
    u32 v0;
    s32 branchcond_19fb2c;
    u32 v1;

    v0 = *(u8 *)((u8 *)&s_StrmBuffMng + 8);
    v0 = v0 & 1;
    branchcond_19fb2c = v0 != 0;
    v0 = 0;
    if (!branchcond_19fb2c) {
        return v0;
    }
    v0 = 0;
    if ((u32)a0 == 0) {
        return v0;
    }
    v1 = *(s32 *)a0;
    v0 = 0;
    if (v1 == 0) {
        return v0;
    }
    v0 = *(s32 *)(((u8 *)a0 + 0x10));
    *(u32 *)(((u8 *)a0 + 8)) = v1;
    *(u32 *)(((u8 *)a0 + 4)) = v1;
    *(u32 *)(((u8 *)a0 + 0x10)) = 0;
    v1 = *(s32 *)a0;
    *(u32 *)(((u8 *)a0 + 0x14)) = v1;
    return v0;
}

/* sbuf_RequiredRead @ 0x19FAC0 .. 0x19FB18 (0x58 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x19fad0 writes a register its branch at 0x19facc reads
 *   delay: daddu at 0x19faf8 writes a register its branch at 0x19faf4 reads
 */



u32 sbuf_RequiredRead(u32 *a0 /* r4 */) {
    u32 v0;
    u32 v1;

    v0 = *(u8 *)((u8 *)&s_StrmBuffMng + 8);
    if ((u32)(v0 & 1) == 0) {
        return 0;
    }
    v0 = 0;
    if ((u32)a0 == 0) {
        return v0;
    }
    v0 = *(s32 *)a0;
    if (v0 == 0) {
        return 0;
    }
    v1 = *(s32 *)(((u8 *)a0 + 0x10));
    v0 = *(s32 *)(((u8 *)a0 + 0xc));
    return (s32)v1 < (s32)v0;
}

u32 sbuf_GetBufferSize(u32 *a0 /* r4 */) {
    u32 v0;

    v0 = *(u8 *)((u8 *)&s_StrmBuffMng + 8);
    if ((u32)(v0 & 1) == 0) {
        return -1;
    }
    v0 = -1;
    if ((u32)a0 == 0) {
        return v0;
    }
    v0 = *(s32 *)a0;
    if (v0 == 0) {
        return -1;
    }
    v0 = *(s32 *)(((u8 *)a0 + 0xc));
    return v0;
}
