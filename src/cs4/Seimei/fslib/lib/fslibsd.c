#include "common.h"

static u32 s_scdRpc[0x14]; /* +0x28 B unreferenced tail in the original */
static u32 s_ucRpcStack[0x400];
static u32 s_psrcFunc[0x10];
static u32 s_qdIopToEeRpc[0x6];
static u32 s_sdIopToEeRpc[0x11];
u32 g_ucEeToIopRpcBuff[0x80];
u32 g_ucIopToEeRpcBuff[0x80];
u32 g_ucErrBuf[0x40];
static u32 s_iIsMakeIopToEeRpc;
static u32 s_iIsInit;

static s32 s_iIopToEeRpcThreadId;
extern int CreateThread(void *);
extern int StartThread(int, void *);
extern int sceSifCheckStatRpc(void *);
extern int printf(void *, ...);
extern int sceSifCallRpc(void *, unsigned int, unsigned int, void *, int, void *, int, void *,
    void
    *);
static void IopToEeRpcThread(void);
extern u32 _gp;


struct fssd_ThreadParam {
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


/* fssdRegister @ 0x147AE0 .. 0x147AF8 (0x18 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u32 s_psrcFunc[];

/* fssdGetCalledRpcResult @ 0x147B00 .. 0x147B0C (0xc bytes) */

extern u32 g_ucEeToIopRpcBuff[];


/* fssdSetMasterVolume @ 0x148100 .. 0x14811C (0x1c bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x148114 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern signed int fssdCallRpc(signed int, signed int, signed int, ...);

/* fssdIsInited @ 0x148120 .. 0x148128 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x148124 computes the return value
 */

extern u32 s_iIsInit;


static s32 s_iIopToEeRpcThreadId;
/* fssdCleanup @ 0x148130 .. 0x148198 (0x68 bytes, frame 0x10) */

extern void TerminateThread(s32);
extern void DeleteThread(s32);
extern void sceSifRemoveRpc(u32 *, u32 *);
extern void sceSifRemoveRpcQueue(u32 *);


/* fssdInit @ 0x1481A0 .. 0x1482A0 (0x100 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @404 is the string '<CallRpcSyncWait> sceSifCheckStatRpc() == 1\n'
 *   delay: daddu at 0x1481b8 writes a register its branch at 0x1481b4 reads
 *   delay: lui at 0x1481f0 writes a register its branch at 0x1481ec reads
 *   cfg: loop leaves to a block that is not its join: 0x148214 -> 0x148250
 *   cfg: kept branch: 0x148210 if (..) goto .L00148228
 *   cfg: kept goto: 0x148214 -> .L00148250
 *   cfg: kept branch: 0x148228 if (..) goto .L00148210
 */

extern int sceSifBindRpc(void *, unsigned int, unsigned int);
extern int sceSifCheckStatRpc(void *);
extern int printf(void *, ...);
extern int sceSifCallRpc(void *, unsigned int, unsigned int, void *, int, void *, int, void *, void
    *);
extern u32 s_iIsMakeIopToEeRpc;

#pragma opt_propagateequivalentscalartypes on
static inline void IopPut(off, base, c)
    s8 *off;
    unsigned int base;
    s8 c;
{
    *(off + base) = c;
}

static inline void IopCpy(void *dst, void *src, int n) {
    unsigned int i;
    for (i = 0; (int)i < n; i++) {
        IopPut(i, (unsigned int)dst, ((s8 *)src)[i]);
    }
}


/* IopToEeRpcThread @ 0x1483D0 .. 0x148440 (0x70 bytes, frame 0x10) */

extern void sceSifInitRpc(unsigned int);
extern int GetThreadId(void);
extern void sceSifSetRpcQueue(u32 *, int);
extern void sceSifRegisterRpc(u32 *, s32, void *, u32 *, u32, u32, u32 *);
extern void sceSifRpcLoop(u32 *);
extern void *IopToEeRpcDispatch(unsigned int, void *, signed int);








static s32 s_iIopToEeRpcThreadId = -0x1;



/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
static void IopToEeRpcThread(void);
static void * IopToEeRpcDispatch(unsigned int uiFno, void *pData, signed int iSize);
signed int fssdInit(void);
signed int fssdCleanup(void);
u32 fssdIsInited(void);
void fssdSetMasterVolume(u8 *a0 , s32 a1 , s32 a2 );
signed int fssdCallRpc(signed int type, signed int mode, signed int command, ...);
signed int fssdCallRpcVoid(signed int command, signed int mode, signed int value);
signed int fssdCallRpcInt(signed int a0 , signed int mode , signed int a2 , signed int a3 );
s32 fssdCallRpcStruct(s32 type,s32 mode,s32 sendSize,s32 recvSize,s32 command,void *source);
u8 * fssdGetCalledRpcResult(void);
u8 * fssdRegister(s32 a0 , u8 *a1 );
signed int fssdRequireIopToEeRpc(void);







static void IopToEeRpcThread(void) {
    u32 a0;
    u32 v0;

    sceSifInitRpc(0);
    v0 = GetThreadId();
    a0 = (u32)s_qdIopToEeRpc;
    sceSifSetRpcQueue(s_qdIopToEeRpc, v0);
    a0 = (u32)s_sdIopToEeRpc;
    sceSifRegisterRpc(s_sdIopToEeRpc, 0x102a, IopToEeRpcDispatch, g_ucIopToEeRpcBuff, 0, 0,
        s_qdIopToEeRpc);
    a0 = (u32)s_qdIopToEeRpc;
    sceSifRpcLoop(s_qdIopToEeRpc);
    return;
}

static void * IopToEeRpcDispatch(unsigned int uiFno, void *pData, signed int iSize) {
    int iModId;
    int iRetSize;
    void *pRet;
    u32 (*pFunc)(u32, void *, s32, s32 *);

    *(u32 *)g_ucErrBuf = 0;
    iModId = (uiFno & 0xf0000000) >> 0x1c;
    if (iModId != 0) {
        pFunc = (void *)s_psrcFunc[iModId];
        if (pFunc != 0) {
            iRetSize = 0;
            pRet = (void *)pFunc(uiFno & 0xfffffff, pData, iSize, &iRetSize);
            IopCpy(g_ucErrBuf, pRet, iRetSize);
        }
    }
    return g_ucErrBuf;
}


signed int fssdInit(void) {
    u8 *a0;
    u32 v1;
    u32 v0;
    s32 s0;
    u8 stackFrame[16] __attribute__((aligned(16)));

    v0 = 1;
    v1 = s_iIsInit;
    if (v1 == v0) {
        v0 = 0;
        return v0;
    }
    s_iIsMakeIopToEeRpc = 0;
    do {
        a0 = (u8 *)s_scdRpc;
        sceSifBindRpc((void *)s_scdRpc, 0x101a, 0);
        v0 = *(s32 *)(s_scdRpc + 9);
    } while (v0 == 0);
    v0 = 0x980000;
    a0 = (u8 *)s_scdRpc;
    s0 = 0x980000 | 0x9680;
    v0 = sceSifCheckStatRpc((void *)s_scdRpc);
    v1 = 1;
    if (v0 == v1) {
        _L00148210:;
        if (s0 >= 0) {
            goto _L00148228;
        }
        a0 = (u8 *)"<CallRpcSyncWait> sceSifCheckStatRpc() == 1\012";
        printf((void *)"<CallRpcSyncWait> sceSifCheckStatRpc() == 1\012");
        v0 = -1;
        goto _L00148250;
        _L00148228:;
        a0 = (u8 *)s_scdRpc;
        s0 = s0 + -1;
        v0 = sceSifCheckStatRpc((void *)s_scdRpc);
        v1 = 1;
        if (v0 == v1) {
            goto _L00148210;
        }
    }
    v0 = 1;
    _L00148250:;
    if ((s32)v0 >= 0) {
        a0 = (u8 *)s_scdRpc;
        sceSifCallRpc((void *)s_scdRpc, 0x10000, 0, (void *)g_ucEeToIopRpcBuff, 0, (void
            *)g_ucEeToIopRpcBuff, 0x10, (void *)0, (void *)0);
    }
    v0 = 1;
    s_iIsInit = v0;
    return v0;
}








signed int fssdCleanup(void) {
    u32 a0;
    u32 v0;

    v0 = s_iIsInit;
    if (v0 != 0 && (u32)s_iIsMakeIopToEeRpc != 0) {
        a0 = s_iIopToEeRpcThreadId;
        TerminateThread(a0);
        a0 = s_iIopToEeRpcThreadId;
        DeleteThread(a0);
        a0 = (u32)s_sdIopToEeRpc;
        sceSifRemoveRpc(s_sdIopToEeRpc, s_qdIopToEeRpc);
        a0 = (u32)s_qdIopToEeRpc;
        sceSifRemoveRpcQueue(s_qdIopToEeRpc);
    }
    s_iIsInit = 0;
    s_iIsMakeIopToEeRpc = 0;
    return 1;
}

u32 fssdIsInited(void) {
    return s_iIsInit;
}

void fssdSetMasterVolume(u8 *a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */) {
    u32 a3;
    u16 t0;
    u16 t1;

    a3 = (u32)a0;
    t0 = (u16)a1;
    t1 = (u16)a2;
    a0 = (u8 *)0;
    a1 = 1;
    a2 = 0x40000;
    fssdCallRpc(0, 1, 0x40000, a3, t0, t1);
    return;
}


signed int fssdCallRpc(signed int type, signed int mode, signed int command, ...) {
    int count;
    int savedType;
    u32 savedMode;
    u8 *buffer;
    int result;
    char *args;
    int rpcCommand;
    int rpcMode;
    count = 10000000;
    savedType = type;
    savedMode = mode;
    buffer = (u8 *)g_ucEeToIopRpcBuff;
    while (sceSifCheckStatRpc((void *)s_scdRpc) == 1) {
        if (count < 0) {
            printf("<CallRpcSyncWait> sceSifCheckStatRpc() == 1\n");
            result = -1;
            goto ready;
        }
        count--;
    }
    result = 1;
    ready:
    if (result < 0) result = -1;
    else {
        args = (char *)__builtin_next_arg(command) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
        rpcMode = !savedMode;
        rpcCommand = ((u32)savedType << 28) & 0xf0000000;
        savedMode = (int)g_ucEeToIopRpcBuff;
        *(u32 *)(buffer + 0) = *(u32 *)((args += 8) - 8);
        *(u32 *)(buffer + 4) = *(u32 *)((args += 8) - 8);
        *(u32 *)(buffer + 8) = *(u32 *)((args += 8) - 8);
        *(u32 *)(buffer + 12) = *(u32 *)((args += 8) - 8);
        *(u32 *)(buffer + 16) = *(u32 *)((args += 8) - 8);
        *(u32 *)(buffer + 20) = *(u32 *)((args += 8) - 8);
        *(u32 *)(buffer + 24) = *(u32 *)((args += 8) - 8);
        *(u32 *)(buffer + 28) = *(u32 *)args;
        sceSifCallRpc((void *)s_scdRpc, rpcCommand | (command & 0x0fffffff), rpcMode,
            (void *)savedMode, 32, (void *)savedMode, 16, 0, 0);
        result = *(int *)savedMode;
    }
    return result;
}


signed int fssdCallRpcVoid(signed int command, signed int mode, signed int value) {
    s32 savedCommand;
    s32 savedMode;
    u32 savedValue;
    s32 timeout;
    s32 rpcCommand;
    s32 rpcMode;
    u32 v1;
    s32 v0;

    timeout = 0x989680;
    savedCommand = command;
    savedMode = mode;
    savedValue = value;
    v0 = sceSifCheckStatRpc((void *)s_scdRpc);
    v1 = 1;
    if (v0 == (s32)v1) {
        do {
            if (timeout >= 0) goto wait;
            printf((void *)"<CallRpcSyncWait> sceSifCheckStatRpc() == 1\n");
            v0 = -1;
            goto done;
wait:
            timeout--;
            v0 = sceSifCheckStatRpc((void *)s_scdRpc);
            v1 = 1;
        } while ((u32)v0 == v1);
    }
    v0 = 1;
done:
    if (v0 < 0) v0 = -1;
    else {
        rpcMode = !savedMode;
        rpcCommand = (((u32)savedCommand << 28) & 0xf0000000) | (savedValue & 0x0fffffff);
        savedValue = (u32)g_ucEeToIopRpcBuff;
        sceSifCallRpc((void *)s_scdRpc, rpcCommand, rpcMode, (void *)savedValue, 0, (void *)savedValue, 0x10, (void *)0, (void *)0);
        v0 = *(s32 *)savedValue;
    }
    return v0;
}


signed int fssdCallRpcInt(signed int a0 /* r4 */, signed int mode /* r5 */, signed int a2 /* r6 */,
        signed int a3 /* r7 */) {
    s32 a1;
    s32 s4;
    s32 s3;
    s32 s2;
    u32 s1;
    s32 t0;
    u32 s0;
    signed int a2_2; // a2
    u32 v1;
    s32 v0;
    u8 stackFrame[16] __attribute__((aligned(16)));

    v0 = 0x980000;
    s4 = a0;
    s3 = mode;
    s2 = a2;
    s1 = a3;
    s0 = 0x980000 | 0x9680;
    a0 = (signed int)s_scdRpc;
    v0 = sceSifCheckStatRpc((void *)s_scdRpc);
    v1 = 1;
    if ((u32)v0 == v1) {
        do {
            if ((s32)s0 >= 0) {
                goto _L00147D88;
            }
            a0 = (signed int)"<CallRpcSyncWait> sceSifCheckStatRpc() == 1\012";
            printf((void *)"<CallRpcSyncWait> sceSifCheckStatRpc() == 1\012");
            v0 = -1;
            goto _L00147DB0;
            _L00147D88:;
            a0 = (signed int)s_scdRpc;
            s0 = s0 + -1;
            v0 = sceSifCheckStatRpc((void *)s_scdRpc);
            v1 = 1;
        } while ((u32)v0 == v1);
    }
    v0 = 1;
    _L00147DB0:;
    if (v0 < 0) {
        v0 = -1;
    } else {
        a2_2 = !s3;
        v1 = (u32)s2 & 0x0fffffff;
        s0 = (u32)g_ucEeToIopRpcBuff;
        a1 = (u32)s4 << 0x1c;
        v0 = -0x10000000;
        t0 = 0x10;
        *(u32 *)g_ucEeToIopRpcBuff = s1;
        v0 = (u32)a1 & -0x10000000;
        a0 = (signed int)s_scdRpc;
        a3 = (signed int)s0;
        a1 = v0 | v1;
        sceSifCallRpc((void *)s_scdRpc, a1, a2_2, (void *)s0, t0, (void *)s0, t0,
                (void *)0, (void *)0);
        v0 = *(s32 *)s0;
    }
    return v0;
}





s32 fssdCallRpcStruct(s32 type,s32 mode,s32 sendSize,s32 recvSize,s32 command,void *source) {
    s32 savedType;
    s32 savedMode;
    s32 send;
    s32 receive;
    s32 savedCommand;
    u8 *src;
    s32 roundedReceive;
    u32 buffer;
    s32 result;
    s32 count;
    savedCommand=command;
    savedType=type;
    savedMode=mode;
    send=sendSize;
    receive=recvSize;
    src=source;
    count=10000000;
    while(sceSifCheckStatRpc(s_scdRpc)==1) {
        if(count<0) { printf("<CallRpcSyncWait> sceSifCheckStatRpc() == 1\n"); result=-1; goto waited; }
        --count;
    }
    result=1;
waited:
    if(result<0) result=-1;
    else {
        s32 i;
        s32 rpcMode;
        if(src!=0) {
            s32 bound;
            s32 input;
            s32 destination;
            u32 byte;
            s32 positive=0<send;
            i=0;
            if(positive!=0) {
            bound=send-8;
            if(send>8) {
                input=(s32)src;
                destination=(s32)g_ucEeToIopRpcBuff;
                do {
                    byte=*(u8 *)input;
                    i+=8;
                    *(u8 *)destination=byte;
                    *(u8 *)(destination+1)=*(u8 *)(input+1);
                    *(u8 *)(destination+2)=*(u8 *)(input+2);
                    *(u8 *)(destination+3)=*(u8 *)(input+3);
                    *(u8 *)(destination+4)=*(u8 *)(input+4);
                    *(u8 *)(destination+5)=*(u8 *)(input+5);
                    *(u8 *)(destination+6)=*(u8 *)(input+6);
                    *(u8 *)(destination+7)=*(u8 *)(input+7);
                    input+=8;
                    destination+=8;
                } while(i<bound);
            }
            if(i<send) {
                input=(s32)(src+i);
                destination=(s32)((u8 *)g_ucEeToIopRpcBuff+i);
                do {
                    byte=*(u8 *)input;
                    *(u8 *)destination=byte;
                    input++;
                    i++;
                    destination++;
                } while(i<send);
            }
        }
            }
        rpcMode=!savedMode;
        send=(send+15)&-16;
        buffer=(u32)g_ucEeToIopRpcBuff;
        if(send>512)send=512;
        roundedReceive=(receive+15)&-16;
        if(roundedReceive>512)roundedReceive=512;
        sceSifCallRpc(s_scdRpc,(((u32)savedType<<28)&0xf0000000u)|(savedCommand&0x0fffffff),rpcMode,(void *)buffer,send,(void *)buffer,roundedReceive,0,0);
        result=*(s32 *)buffer;
    }
    return result;
}

u8 * fssdGetCalledRpcResult(void) {
    return (u8 *)g_ucEeToIopRpcBuff;
}

u8 * fssdRegister(s32 a0 /* r4 */, u8 *a1 /* r5 */) {
    u32 *v1;

    a0 = (u32)a0 << 2;
    v1 = s_psrcFunc;
    *(u32 *)(u32 *)((u8 *)s_psrcFunc + a0) = (u32)a1;
    return;
}

signed int fssdRequireIopToEeRpc(void) {
    u32 a0;
    s32 v1;
    u32 v0;
    s32 s0;
    struct fssd_ThreadParam param;

    v0 = s_iIsMakeIopToEeRpc;
    if (v0 == 0) {
        param.entry = IopToEeRpcThread;
        param.initPriority = 0x30;
        param.stack = s_ucRpcStack;
        param.stackSize = 0x1000;
        param.gpReg = &_gp;
        v0 = CreateThread(&param);
        if ((s32)v0 >= 0) {
            s_iIopToEeRpcThreadId = v0;
            StartThread(v0, (void *)0);
            v0 = 1;
        } else {
            v0 = 0;
        }
        if (v0 != 0) {
            v0 = 0x980000;
            a0 = (u32)s_scdRpc;
            s0 = 0x980000 | 0x9680;
            v0 = sceSifCheckStatRpc((void *)s_scdRpc);
            v1 = 1;
            if (v0 == (u32)v1) {
                do {
                    if (s0 >= 0) {
                        goto _L00147A58;
                    }
                    a0 = (u32)"<CallRpcSyncWait> sceSifCheckStatRpc() == 1\012";
                    printf((void *)"<CallRpcSyncWait> sceSifCheckStatRpc() == 1\012");
                    v0 = -1;
                    goto _L00147A80;
                    _L00147A58:;
                    a0 = (u32)s_scdRpc;
                    s0 = s0 + -1;
                    v0 = sceSifCheckStatRpc((void *)s_scdRpc);
                    v1 = 1;
                } while (v0 == (u32)v1);
            }
            v0 = 1;
            _L00147A80:;
            if ((s32)v0 >= 0) {
                a0 = (u32)s_scdRpc;
                sceSifCallRpc((void *)s_scdRpc, 0x20000, 0, (void *)g_ucEeToIopRpcBuff, 0, (void
                    *)g_ucEeToIopRpcBuff, 0x10, (void *)0, (void
    *)0);
            }
            v0 = 1;
            s_iIsMakeIopToEeRpc = v0;
        }
        v0 = 1;
    } else {
        v0 = 0;
    }
    return v0;
}
