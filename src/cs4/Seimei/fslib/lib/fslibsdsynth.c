#include "common.h"




/* .bss tentatives: emitted in reverse order of first declaration -> memory order g_voice, s_iPortSpuMap,
 * s_svpBuf, s_sddSeTrans, s_esmData, s_sdiData, s_sddPacket, s_ucSeBuf (IOP DMA buffers 64-byte aligned) */
static u32 s_ucSeBuf[0x100] __attribute__((aligned(64)));
static u32 s_sddPacket[0x4];
static u32 s_sdiData[0x8];
static u8 s_esmData[0x410];
static u32 s_sddSeTrans[0x4];
static u16 s_svpBuf[0x100] __attribute__((aligned(64)));
extern u32 s_iPortSpuMap[];
extern void FsSpuMmng_AddMemBlock();
extern signed int fssdCallRpcStruct(signed int, signed int, signed int, signed int, signed int,
    void *);
extern u8 s_esmData[];
extern u8 g_ucSeVoiceState[8];
extern u32 fssdGetCalledRpcResult(void);
extern signed int fssdCallRpc(signed int, signed int, signed int, ...);
extern signed int fssdCallRpcInt(signed int, signed int, signed int, signed int);
extern u8 g_voice[];
extern void * memset(void *, int, unsigned int);
static void SetSurroundVolume2(signed int *, signed int *, signed int, signed int, signed int);
extern u16 s_svpBuf[];
extern u32 fssdsynthSeStreamOn();
extern void FlushCache(int);
extern int sceSifFreeIopHeap();
extern signed int fssdCallRpcVoid(signed int, signed int, signed int);
extern int sceSifDmaStat(unsigned int);
extern unsigned int sceSifSetDma(void *, int);
extern u32 s_sdiData[];
extern u32 s_sddPacket[];
struct TransBankSt { u8 busy; u8 state; u8 pad_[2]; u32 entry; u32 first; u32 second; u32 f4; u32 pktSize; u32 iopAddr; u32 spuRemain; s32 dmaId; };
extern struct TransBankSt s_TransBank;
void fssdsynthAssociateSpu2MemBlockIdWithPort(signed int a0 /* r4 */, unsigned int a1 /* r5 */);
void fssdsynthAddSpu2MemoryBlock(void);
signed int fssdsynthCheckSqEosAll(void);
signed int fssdsynthGetSqAddrOnIopMemory(signed int a0 /* r4 */);
signed int fssdsynthGetSeState(signed int a0 /* r4 */);
u32 fssdsynthUpdateSeState(void);
void fssdsynthSetCoreAttr(s32 a0 /* r4 */, s32 a1 /* r5 */);
void fssdsynthSetParam(s32 a0 /* r4 */, s32 a1 /* r5 */);
void fssdsynthGetTransStatus(u8 *a0 /* r4 */);
void fssdsynthSetMVolume(s32 a0 /* r4 */);
void fssdsynthPortSoundOff(s32 a0 /* r4 */);
signed int fssdsynthUpdateVoiceInfo(void);
void fssdsynthPackSeStreamSurroundOn(signed int a0 /* r4 */, void *a1 /* r5 */, u32 *a2);
void fssdsynthSeStreamOn_forSurround(s32 a0 /* r4 */, s32 a1 /* r5 */, u8 *a2 /* r6 */, s32 a3 /*
        r7 */, s32 t0 /* r8 */, s32 t1 /* r9 */);
void fssdsynthDefineSeStream(u8 *a0 /* r4 */, u8 *a1 /* r5 */);
signed int fssdsynthRemoveReverb(signed int a0 /* r4 */);
signed int fssdsynthAddReverb(signed int a0 /* r4 */, signed short a1 /* r5 */, signed short a2 /*
        r6 */, signed short a3 /* r7 */, signed short t0 /* r8 */, signed short t1 /* r9 */, signed
        short t2 /* r10 */, signed int t3 /* r11 */);
signed int fssdsynthSqVolume(signed int a0 /* r4 */, signed short a1 /* r5 */);
signed int fssdsynthStopSq(signed int a0 /* r4 */);
signed int fssdsynthPlaySq(signed int a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */);
u32 fssdsynthRemoveSqNoRelease(s32 a0 /* r4 */);
signed int fssdsynthRemoveSq(signed int a0 /* r4 */);
void fssdsynthSystemStart(void);
signed int fssdsynthSifTransSync(void);


static u32 s_SinTable[0x40];
signed short _Sinf511(signed int angle) {
    s32 index;
    s32 quadrant;
    s32 weight;
    s16 result;
    s32 partial=angle&0x1ff;
    index=partial>>2;
    weight=4-partial%4;
    quadrant=angle/512;
    switch(quadrant) {
    case 0:
        if(index<=126) {
            angle=*(s16 *)((u32)((s16 *)s_SinTable+1)+(index<<1));
            result=(s16)(angle+weight*(((s16 *)s_SinTable)[index]-angle)/4);
        } else result=((s16 *)s_SinTable)[127];
        break;
    case 1:
        if(index>0) {
            angle=((s16 *)s_SinTable)[127-index];
            result=(s16)(angle+weight*(((s16 *)s_SinTable)[128-index]-angle)/4);
        } else result=((s16 *)s_SinTable)[127];
        break;
    case 2:
        if(index<=126) {
            angle=*(s16 *)((u32)((s16 *)s_SinTable+1)+(index<<1));
            result=(s16)-(angle+weight*(((s16 *)s_SinTable)[index]-angle)/4);
        } else result=(s16)-((s16 *)s_SinTable)[127];
        break;
    case 3:
        if(index>0) {
            angle=((s16 *)s_SinTable)[127-index];
            result=(s16)-(angle+weight*(((s16 *)s_SinTable)[128-index]-angle)/4);
        } else result=(s16)-((s16 *)s_SinTable)[127];
        break;
    default: result=0;
    }
    return result;
}







static u32 s_SinTable[0x40];
signed short _Cosf511(int angle) {
    int index;
    int weight;
    int part;
    s16 result;
    angle+=512;
    if(angle>2047) angle-=2048;
    part=angle&511;
    index=part>>2;
    weight=4-part%4;
    switch(angle/512) {
    case 0:
        if(index<=126) {
            int next=*(s16 *)((u32)((u8 *)s_SinTable+2)+index*2);
            int current=*(s16 *)((u8 *)s_SinTable+index*2);
            result=(s16)(next+weight*(current-next)/4);
        } else result=*(s16 *)((u8 *)s_SinTable+254);
        break;
    case 1:
        if(index>0) {
            int current=*(s16 *)((u8 *)s_SinTable+(127-index)*2);
            int next=*(s16 *)((u8 *)s_SinTable+(128-index)*2);
            result=(s16)(current+weight*(next-current)/4);
        } else result=*(s16 *)((u8 *)s_SinTable+254);
        break;
    case 2:
        if(index<=126) {
            int next=*(s16 *)((u32)((u8 *)s_SinTable+2)+index*2);
            int current=*(s16 *)((u8 *)s_SinTable+index*2);
            result=(s16)-(next+weight*(current-next)/4);
        } else result=(s16)-*(s16 *)((u8 *)s_SinTable+254);
        break;
    case 3:
        if(index>0) {
            int current=*(s16 *)((u8 *)s_SinTable+(127-index)*2);
            int next=*(s16 *)((u8 *)s_SinTable+(128-index)*2);
            result=(s16)-(current+weight*(next-current)/4);
        } else result=(s16)-*(s16 *)((u8 *)s_SinTable+254);
        break;
    default: result=0;
    }
    return result;
}








extern void FsSpuMmng_Init();
extern u32 s_ucSeBuf[];
signed int fssdsynthInit(void) {
    s32 count, total;
    u8 *entry;
    fssdCallRpcVoid(4,1,0x100);
    *(u32 *)(s_esmData+0x3fc)=fssdCallRpcVoid(4,1,0x11d00);
    *(u32 *)(s_esmData+0x408)=0x3fff;
    fssdCallRpc(4,1,0x300,*(s32 *)(s_esmData+0x408),*(s32 *)(s_esmData+0x408));
    *(u32 *)(s_esmData+0x3f8)=0;
    *(u32 *)(s_esmData+0x400)=fssdCallRpc(4,1,0xa00);
    total=16;
    count=total;
    *(void **)(s_esmData+0x404)=s_ucSeBuf;
    entry=s_esmData;
    **(u32 **)(s_esmData+0x404)=0;
    *(u16 *)(s_esmData+0x40c)=1;
    *(u16 *)(s_esmData+0x40e)=0;
    while(count--) {
        *(u32 *)(entry)=0;
        *(u32 *)(entry+4)=0;
        *(u32 *)(entry+8)=0;
        *(u32 *)(entry+12)=0;
        *(u32 *)(entry+20)=0;
        *(u8 *)(entry+26)=0;
        *(u16 *)(entry+24)=0;
        *(u8 *)(entry+27)=0;
        *(u32 *)(entry+28)=1;
        *(u32 *)(entry+32)=total-(count+1);
        entry+=36;
    }
    {
    u8 *entry;
    s32 count;
    count=4; entry=s_esmData+0x240;
    while(count--) {
        *(u32 *)entry=0; *(u32 *)(entry+12)=0; *(u32 *)(entry+4)=0; entry+=16;
    }
    }
    {
    u8 *entry;
    s32 count;
    count=64; entry=s_esmData+0x280;
    while(count--) {
        *(s8 *)(entry+3)=-1; *(s8 *)(entry+2)=-1; *(s8 *)(entry+1)=-1; *(s8 *)entry=-1; entry+=4;
    }
    }
    {
    u8 *entry;
    s32 count;
    count=4; entry=s_esmData+0x380;
    while(count--) {
        *(s32 *)entry=-1; *(u32 *)(entry+4)=0; *(u16 *)(entry+8)=0; *(u16 *)(entry+10)=0;
        *(u32 *)(entry+12)=0; *(u32 *)(entry+16)=0; *(u16 *)(entry+20)=0; *(u16 *)(entry+22)=0;
        entry+=24;
    }
    }
    count=16;
    while(count--) s_iPortSpuMap[count]=-1;
    FsSpuMmng_Init();
    s_sdiData[6]=0;
    FlushCache(0);
    return 0;
}


/* fssdsynthSifTransBuffer @ 0x14A1F0 .. 0x14A2F4 (0x104 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int fssdsynthSifTransBuffer(char *a0 /* r4 */, char *a1 /* r5 */, unsigned int a2 /* r6 */) {
    u32 a1_scalar; // a1
    u32 v1;
    u32 v0;

    s_sdiData[1] = (u32)a1;
    *(u32 *)s_sdiData = (u32)a0;
    s_sdiData[6] = 1;
    s_sdiData[2] = a2;
    v0 = 0x4000;
    if ((u32)(s32)a2 > (u32)0x4000) {
        s_sdiData[3] = v0;
        s_sdiData[4] = v0;
    } else {
        s_sdiData[3] = a2;
        v0 = -0x10;
        s_sdiData[4] = a2;
        v1 = *(s32 *)(s_sdiData + 3);
        s_sdiData[3] = (u32)(v1 + 0xf) & v0;
    }
    a1_scalar = *(s32 *)(s_sdiData + 1);
    s_sddPacket[3] = 0;
    v1 = *(s32 *)(s_esmData + 0x400);
    v0 = *(s32 *)(s_sdiData + 3);
    *(u32 *)s_sddPacket = a1_scalar;
    s_sddPacket[1] = v1;
    s_sddPacket[2] = v0;
    FlushCache(0);
    a0 = (char *)s_sddPacket;
    v0 = sceSifSetDma((void *)s_sddPacket, 1);
    s_sdiData[5] = v0;
    v0 = *(s32 *)(s_sdiData + 5);
    if (v0 == 0) {
        return -1;
    } else {
        return 0;
    }
    return v0;
}






/* fssdsynthSifTransSync @ 0x14A070 .. 0x14A1EC (0x17c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x14a084 writes a register its branch at 0x14a080 reads
 */


signed int fssdsynthSifTransSync(void) {
    u32 t0;
    u32 a3;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;

    v0 = *(s32 *)(s_sdiData + 6);
    if (v0 == 0) {
        return 1;
    }
    v0 = sceSifDmaStat(*(s32 *)(s_sdiData + 5));
    if ((s32)v0 >= 0) {
        v0 = 0;
    } else {
        a3 = *(s32 *)s_sdiData;
        t0 = *(s32 *)(s_sdiData + 4);
        fssdCallRpc(4, 1, 0xb00, a3, t0);
        v1 = *(s32 *)(s_sdiData + 2);
        v0 = *(s32 *)(s_sdiData + 4);
        s_sdiData[2] = v1 - v0;
        a0 = *(s32 *)(s_sdiData + 2);
        if ((s32)a0 <= 0) {
            v0 = 1;
            s_sdiData[6] = 0;
        } else {
            v1 = *(s32 *)(s_sdiData + 1);
            s_sdiData[1] = v1 + 0x4000;
            v0 = *(s32 *)s_sdiData;
            *(u32 *)s_sdiData = v0 + 0x4000;
            v0 = 0x4000;
            if ((s32)a0 > (s32)0x4000) {
                s_sdiData[3] = v0;
                s_sdiData[4] = v0;
            } else {
                s_sdiData[3] = a0;
                v0 = -0x10;
                s_sdiData[4] = a0;
                v1 = *(s32 *)(s_sdiData + 3);
                s_sdiData[3] = (u32)(v1 + 0xf) & v0;
            }
            a1 = *(s32 *)(s_sdiData + 1);
            s_sddPacket[3] = 0;
            v1 = *(s32 *)(s_esmData + 0x400);
            v0 = *(s32 *)(s_sdiData + 3);
            *(u32 *)s_sddPacket = a1;
            s_sddPacket[1] = v1;
            s_sddPacket[2] = v0;
            FlushCache(0);
            a0 = (u32)s_sddPacket;
            v0 = sceSifSetDma((void *)s_sddPacket, 1);
            s_sdiData[5] = v0;
            v0 = 0;
        }
    }
    return v0;
}






/* fssdsynthSystemStart @ 0x14A030 .. 0x14A06C (0x3c bytes, frame 0x10) */


void fssdsynthSystemStart(void) {
    s32 a1;
    u32 v1;

    a1 = 1;
    v1 = *(u16 *)(s_esmData + 0x40e);
    if (v1 != (u32)a1) {
        fssdCallRpcVoid(4, a1, 0x400);
        *(u16 *)(s_esmData + 0x40e) = 1;
    }
    return;
}








/* fssdsynthSetStereo @ 0x149EA0 .. 0x14A02C (0x18c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: sll at 0x149fa8 writes a register its branch at 0x149fa4 reads
 *   cfg: loop body is not one contiguous region: .L00149F28
 *   cfg: loop body is not one contiguous region: .L00149F90
 */

void fssdsynthSetStereo(void) {
    s32 t2;
    u32 t1;
    u32 t0;
    u8 *s1;
    u8 *bmp;
    u8 *sqp;
    u32 a3;
    s32 s0;
    s32 a1;
    u32 a0;
    u32 v1;
    u32 v0;

    v0 = *(u16 *)(s_esmData + 0x40e);
    if (v0 != 0) {
        fssdCallRpcVoid(4, 1, 0x500);
    }
    s0 = 0;
    do {
        v0 = 0x10000;
        fssdCallRpc(4, 1, 0x10000 | 0x1100, (u32)s0);
        s0 = s0 + 1;
        v0 = s0 < (s32)0x10;
        a1 = 1;
    } while (v0 != 0);
    *(u16 *)(s_esmData + 0x40c) = a1;
    fssdCallRpcInt(4, a1, 0xc00, a1);
    s0 = 0;
    s1 = s_esmData;
    do {
        a1 = 1;
        *(u32 *)(s1 + 0x1c) = a1;
        t1 = *(s32 *)s1;
        if (t1 != 0) {
            t0 = *(s32 *)(s1 + 0xc);
            if (t0 != 0 && (u32)*(s32 *)(s1 + 4) != 0) {
                v0 = 0x10000;
                t2 = *(s8 *)(s1 + 0x1b);
                fssdCallRpc(4, a1, 0x10000 | 0x100, (u32)*(s16 *)(s1 + 0x18), t0, t1, t2);
                s1 = (u8 *)(s1 + 0x24);
            }
        }
        s0 = s0 + 1;
        v1 = s0 < (s32)0x10;
    } while (v1 != 0);
    bmp = (u8 *)(s_esmData + 0x240);
    for (s0 = 0; s0 < 4; s0++) {
        if (*(s32 *)bmp != 0) {
            if (*(s32 *)(bmp + 8) != -1) {
                sqp = (u8 *)s_esmData + *(s32 *)(bmp + 8) * 0x24;
                fssdCallRpc(4, 1, 0x20700, *(s32 *)(bmp + 0xc), *(s32 *)(sqp + 0xc), *(s32 *)sqp, *(s8 *)(sqp + 0x1b), 1);
                bmp = bmp + 0x10;
            }
        }
    }
    v1 = *(u16 *)(s_esmData + 0x40e);
    if (v1 != 0) {
        fssdCallRpcVoid(4, 1, 0x400);
    }
    return;
}








/* fssdsynthTransBankStatus @ 0x149A40 .. 0x149EA0 (0x460 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @2548 -> 0x2533d0
 *   indirect: jr v0 at 0x149a8c -> <v0>
 *   delay: lui at 0x149ba8 writes a register its branch at 0x149ba4 reads
 *   cfg: kept goto: 0x149a60 -> .L00149E90
 *   cfg: loop body is not one contiguous region: .L00149B10
 */

signed int fssdsynthRemoveBank(signed int bank);
extern void *sceSifAllocIopHeap(unsigned int);
extern u32 L2548[];

u32 fssdsynthTransBankStatus(void) {
    u32 t3;
    u32 s0;
    u32 t2;
    u32 t1;
    u32 t0;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;

    v0 = s_TransBank.busy;
    s0 = 0x100000;
    if (v0 != 0) {
        v0 = 1;
        goto _L00149E90;
    }
    v0 = s_TransBank.state;
    switch (v0) {
    case 0:
        fssdsynthSifTransBuffer((char *)*(s32 *)s_TransBank.entry, (char *)s_TransBank.first, *(s32 *)(s_TransBank.entry + 0x10));
        s_TransBank.state = 1;
        break;
    case 1:
        v0 = fssdsynthSifTransSync();
        if (v0 == 0) {
            break;
        }
        v0 = 2;
        s_TransBank.state = v0;
        break;
    case 2:
        v1 = s_TransBank.entry;
        v0 = 0x10000;
        a0 = 4;
        a3 = *(s32 *)((v1 + 4));
        t0 = *(s32 *)v1;
        t1 = *(s32 *)((v1 + 0x10));
        fssdCallRpc(a0, 1, 0x10000 | 0x700, a3, t0, t1);
        do {
            s0 = s0 >> 1;
            if (s0 == 0) {
                v0 = s_TransBank.entry;
                a0 = *(s32 *)((v0 + 0x20));
                fssdsynthRemoveBank(a0);
                v0 = 2;
                s_TransBank.busy = v0;
                v0 = (s8)s_TransBank.busy;
                return v0;
            }
            v0 = (u32)sceSifAllocIopHeap(s0);
            s_TransBank.iopAddr = v0;
            v0 = s_TransBank.iopAddr;
        } while (v0 == 0);
        v0 = 3;
        s_TransBank.pktSize = s0;
        s_TransBank.state = v0;
        break;
    case 3:
        if (s_TransBank.spuRemain == 0) {
            s_TransBank.state = 8;
            break;
        } else {
            if (s_TransBank.pktSize < s_TransBank.spuRemain) {
                s_sddPacket[2] = s_TransBank.pktSize;
            } else {
                s_sddPacket[2] = s_TransBank.spuRemain;
            }
            *(u32 *)s_sddPacket = s_TransBank.second;
            s_sddPacket[1] = s_TransBank.iopAddr;
            s_sddPacket[3] = 0;
            s_TransBank.state = 4;
            break;
        }
    case 4:
        v0 = s_TransBank.entry;
        a3 = *(s8 *)((v0 + 0x1a));
        v0 = fssdCallRpc(4, 1, 0x800, a3, 0);
        if (v0 == 0) {
            break;
        }
        v0 = 5;
        s_TransBank.state = v0;
        break;
    case 5:
        a0 = (u32)s_sddPacket;
        v0 = sceSifSetDma((void *)s_sddPacket, 1);
        s_TransBank.dmaId = v0;
        v0 = s_TransBank.dmaId;
        if (v0 == 0) {
            a0 = s_TransBank.iopAddr;
            sceSifFreeIopHeap(a0);
            v0 = s_TransBank.entry;
            a0 = *(s32 *)((v0 + 0x20));
            fssdsynthRemoveBank(a0);
            v0 = 2;
            s_TransBank.busy = v0;
            break;
        } else {
            s_TransBank.state = 6;
            break;
        }
    case 6:
        a0 = s_TransBank.dmaId;
        v0 = sceSifDmaStat(a0);
        if ((s32)v0 >= 0) {
            break;
        }
        v0 = 7;
        s_TransBank.state = v0;
        break;
    case 7:
        t3 = s_sddPacket[2];
        v1 = (s32)t3 >> 6;
        s0 = t3;
        v0 = (s32)t3 % 0x40;
        if (v0 != 0) {
            v0 = v1 + 1;
            s0 = v0 << 6;
        }
        v0 = s_TransBank.entry;
        a0 = 4;
        a1 = 1;
        a3 = *(s8 *)((v0 + 0x1a));
        t1 = s_TransBank.iopAddr;
        t2 = s_TransBank.f4;
        v0 = fssdCallRpc(a0, a1, 0x900, a3, 0, t1, t2, t3);
        if (v0 != s0) {
            a0 = s_TransBank.iopAddr;
            sceSifFreeIopHeap(a0);
            v0 = s_TransBank.entry;
            a0 = *(s32 *)((v0 + 0x20));
            fssdsynthRemoveBank(a0);
            v0 = 2;
            s_TransBank.busy = v0;
            break;
        } else {
            s_TransBank.second += s_sddPacket[2];
            s_TransBank.f4 += s_sddPacket[2];
            s_TransBank.spuRemain -= s_sddPacket[2];
            s_TransBank.state = 3;
            break;
        }
    case 8:
        v0 = s_TransBank.entry;
        a3 = *(s8 *)((v0 + 0x1a));
        v0 = fssdCallRpc(4, 1, 0x800, a3, 0);
        if (v0 == 0) {
            break;
        }
        v0 = 9;
        s_TransBank.state = v0;
        break;
    case 9:
        a0 = s_TransBank.iopAddr;
        sceSifFreeIopHeap(a0);
        s_TransBank.state = 0xa;
        break;
    case 10:
        v1 = s_TransBank.entry;
        v0 = *(s32 *)((v1 + 0x1c));
        a3 = *(s16 *)((v1 + 0x18));
        if (v0 != 0) {
            t1 = *(s32 *)v1;
        } else {
            t1 = *(s32 *)((v1 + 4));
        }
        t2 = *(s8 *)((v1 + 0x1b));
        v0 = 0x10000;
        t0 = *(s32 *)((v1 + 0xc));
        a0 = 4;
        if (t0 == -1) { t0 = t0; }
        v0 = fssdCallRpc(a0, 1, 0x10000 | 0x100, a3, t0, t1, t2);
        if (v0 != 0) {
            v0 = s_TransBank.entry;
            a0 = *(s32 *)((v0 + 0x20));
            fssdsynthRemoveBank(a0);
            v0 = 2;
            s_TransBank.busy = v0;
            break;
        } else {
            FlushCache(0);
            s_TransBank.busy = 1;
            break;
        }
    default:
        s_TransBank.busy = 2;
    }
    v0 = (s8)s_TransBank.busy;
    _L00149E90:;
    return v0;
}








extern void *sceSifAllocIopHeap(unsigned int);
extern signed int FsSpuMmng_Alloc(signed int, signed int);
extern signed int fssdsynthRemoveBank(signed int);
signed int fssdsynthAddBankFromEE2(signed int port, char *first, unsigned int size, char *second, unsigned int spuSize, signed int mode)
{
    u8 *entry;
    s32 i;
    if (!s_TransBank.busy) {
        do {} while ((u8)fssdsynthTransBankStatus() == 0);
    }
    entry = s_esmData;
    for (i = 0; i < 16; i++, entry += 36) {
        if (!*(u32 *)entry) break;
    }
    if (i >= 16) entry = 0;
    if (!entry) return -2;
    if (port == -1) port = *(s32 *)(entry + 32);
    else if (port < 0 || port > 16) return -1;
    *(u16 *)(entry + 24) = port;
    size = (size + 15) & ~15;
    *(u8 *)(entry + 27) = mode;
    *(u32 *)(entry + 16) = size;
    *(u32 *)entry = (u32)sceSifAllocIopHeap(*(u32 *)(entry + 16));
    *(u32 *)(entry + 4) = (u32)sceSifAllocIopHeap(*(u32 *)(entry + 16));
    if (!*(u32 *)entry || !*(u32 *)(entry + 4)) goto fail;
    if (*(u32 *)entry + *(u32 *)(entry + 16) > 0x1fffff) goto fail;
    if (*(u32 *)(entry + 4) + *(u32 *)(entry + 16) > 0x1fffff) goto fail;
    spuSize = (spuSize + 15) & ~15;
    *(u32 *)(entry + 20) = spuSize;
    if (!*(u32 *)(entry + 12))
        *(u32 *)(entry + 12) = FsSpuMmng_Alloc(s_iPortSpuMap[port], spuSize);
    if (!*(u32 *)(entry + 12)) goto fail;
    s_TransBank.busy = 0;
    s_TransBank.state = 0;
    s_TransBank.entry = (u32)entry;
    s_TransBank.f4 = *(u32 *)(entry + 12);
    s_TransBank.spuRemain = spuSize;
    s_TransBank.first = (u32)first;
    s_TransBank.second = (u32)second;
    return *(s32 *)(entry + 32);
fail:
    fssdsynthRemoveBank(*(s32 *)(entry + 32));
    return -1;
}







extern void FsSpuMmng_Free(signed int, signed int);
signed int fssdsynthRemoveBank(signed int bank) {
    s32 count;
    s8 *entry;
    u8 *data;
    s32 result;
    if (bank < 0 || bank >= 16) {
        result = -1;
    } else {
        count = 64;
        entry = (s8 *)(s_esmData + 0x280);
        while (count--) {
            if (*entry == bank) {
                entry[3] = -1;
                entry[2] = -1;
                entry[1] = -1;
                entry[0] = -1;
            }
            entry += 4;
        }
        data = (u8 *)s_esmData + bank * 36;
        FsSpuMmng_Free(((s32 *)s_iPortSpuMap)[*(s16 *)(data + 0x18)], *(s32 *)(data + 0xc));
        *(u32 *)(data + 0xc) = 0;
        if (*(s32 *)(data + 8)) {
            if (sceSifFreeIopHeap(*(s32 *)(data + 8))) { result = -1; goto end; }
            *(u32 *)(data + 8) = 0;
        }
        if (*(s32 *)data) {
            if (sceSifFreeIopHeap(*(s32 *)data)) { result = -1; goto end; }
            *(u32 *)data = 0;
        }
        if (*(s32 *)(data + 4)) {
            if (sceSifFreeIopHeap(*(s32 *)(data + 4))) { result = -1; goto end; }
            *(u32 *)(data + 4) = 0;
        }
        FlushCache(0);
        result = 0;
    }
end:
    return result;
}









#ifndef PROTO_SDSYNTH_ESM
#define PROTO_SDSYNTH_ESM
struct SdSqT { void *iopp; s32 size; s32 bt_idx; s32 midi_port; };
struct SdBankT { void *hd_iopp; void *hd_m_iopp; void *bd_iopp; void *bd_spup; s32 hd_size; s32 bd_size; s16 hsyn_port; char ch; char bank; u32 stereo; s32 iNum; };
struct SdEsmT { struct SdBankT bank_tbl[16]; struct SdSqT sq_tbl[4]; };
#endif

signed int fssdsynthAddSqFromEE(signed int port, signed int bt_idx, char *sq_buff, unsigned int sq_size) {
    s32 i;
    s32 idx;
    s32 res;
    struct SdSqT *sqp;
    struct SdBankT *bmp;

    sqp = ((struct SdEsmT *)s_esmData)->sq_tbl;
    for (i = 0; i < 4; i++, sqp++) {
        if (sqp->iopp == 0) {
            idx = i;
            break;
        }
    }
    if (i >= 4) {
        return -2;
    }
    if (port == -1) {
        port = idx;
    } else if (port < 0 || port >= 4) {
        return -1;
    }
    sqp->midi_port = port;
    sqp->bt_idx = bt_idx;
    bmp = &((struct SdEsmT *)s_esmData)->bank_tbl[sqp->bt_idx];
    sq_size = (sq_size + 15) & ~15;
    sqp->size = sq_size;
    res = (s32)sceSifAllocIopHeap(sqp->size);
    sqp->iopp = (void *)res;
    if (sqp->iopp == 0 || (u32)sqp->iopp + sqp->size > 0x1fffff) {
        sqp = &((struct SdEsmT *)s_esmData)->sq_tbl[idx];
        if (sqp->iopp && !sceSifFreeIopHeap(sqp->iopp)) {
            sqp->iopp = 0;
            sqp->size = 0;
            FlushCache(0);
        }
        return -1;
    }
    fssdsynthSifTransBuffer((char *)sqp->iopp, sq_buff, sqp->size);
    do {} while (!fssdsynthSifTransSync());
    if (fssdCallRpc(4, 1, 0x10100, sqp->midi_port, bmp->bd_spup, bmp->stereo ? bmp->hd_iopp : bmp->hd_m_iopp, bmp->bank)) {
        sqp = &((struct SdEsmT *)s_esmData)->sq_tbl[idx];
        if (sqp->iopp && !sceSifFreeIopHeap(sqp->iopp)) {
            sqp->iopp = 0;
            sqp->size = 0;
            FlushCache(0);
        }
        return -1;
    }
    if (fssdCallRpc(4, 1, 0x20000, sqp->midi_port, sqp->iopp)) {
        sqp = &((struct SdEsmT *)s_esmData)->sq_tbl[idx];
        if (sqp->iopp && !sceSifFreeIopHeap(sqp->iopp)) {
            sqp->iopp = 0;
            sqp->size = 0;
            FlushCache(0);
        }
        return -1;
    }
    FlushCache(0);
    return idx;
}






signed int fssdsynthAddSqFromIOP(signed int a0, signed int a1, char *a2,
                                  unsigned int a3) {
    u32 t1;
    s32 t2;
    u32 s1;
    u32 t0;
    u8 *s0;
    u32 v1;
    u32 v0;

    v1 = 0;
    s0 = (u8 *)(s_esmData + 0x240);
    do {
        v0 = *(s32 *)s0;
        if (v0 != 0) {
            goto _L001492F8;
        }
        s1 = v1;
        break;
        _L001492F8:;
        v1 = v1 + 1;
        v0 = (s32)v1 < (s32)4;
        s0 = (u8 *)(s0 + 0x10);
    } while (v0 != 0);
    v0 = (s32)v1 < (s32)4;
    if (v0 == 0) {
        v0 = -2;
        return v0;
    }
    v0 = -1;
    if ((u32)(s32)a0 == v0) {
        a0 = s1;
        goto _L00149350;
    } else if ((s32)a0 < 0 || (s32)a0 >= (s32)4) {
        return -1;
    } else {
        _L00149350:;
        *(u32 *)(s0 + 0xc) = a0;
        *(u32 *)(s0 + 8) = a1;
        a0 = *(s32 *)(s0 + 8);
        v1 = (u32)s_esmData;
        *(u32 *)(s0 + 4) = a3;
        *(u32 *)s0 = (u32)a2;
        a0 = (u32)a0 * 0x24;
        v0 = *(s32 *)s0;
        v1 = (s32)((u8 *)s_esmData + a0);
        if (v0 == 0) {
            return -1;
        } else {
            v0 = *(s32 *)((v1 + 0x1c));
            if (v0 != 0) {
                t1 = *(s32 *)v1;
            } else {
                t1 = *(s32 *)((v1 + 4));
            }
            v0 = 0x10000;
            t2 = *(volatile s8 *)((v1 + 0x1b));
            t0 = *(volatile s32 *)((v1 + 0xc));
            a0 = 4;
            a3 = *(volatile s32 *)(s0 + 0xc);
            a1 = 1;
            a2 = (char *)(0x10000 | 0x100);
            v0 = fssdCallRpc(a0, a1, (signed int)a2, a3, t0, t1, t2);
            if (v0 != 0) {
                return -1;
            } else {
                a3 = *(s32 *)(s0 + 0xc);
                t0 = *(s32 *)s0;
                a0 = 4;
                a1 = 1;
                v0 = fssdCallRpc(a0, a1, 0x20000, a3, t0);
                if (v0 != 0) {
                    return -1;
                } else {
                    FlushCache(0);
                    v0 = s1;
                }
            }
        }
    }
    return v0;
}





/* fssdsynthRemoveSq @ 0x149240 .. 0x1492B8 (0x78 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: kept goto: 0x149280 -> .L00149298
 *   cfg: kept goto: 0x149290 -> .L001492A8
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int fssdsynthRemoveSq(signed int a0 /* r4 */) {
    u32 v0;
    u32 *s0;

    v0 = (u32)s_esmData;
    v0 = (s32)((u8 *)s_esmData + (s32)((u32)a0 << 4));
    a0 = *(s32 *)((v0 + 0x240));
    s0 = (u32 *)(s32)(v0 + 0x240);
    if ((u32)(s32)a0 != 0) {
        v0 = sceSifFreeIopHeap(a0);
        if (v0 != 0) {
            v0 = -1;
        } else {
            *(u32 *)s0 = 0;
            *(u32 *)(((u8 *)s0 + 4)) = 0;
            goto _L00149298;
        }
    } else {
        v0 = -1;
        goto _L001492A8;
        _L00149298:;
        FlushCache(0);
        v0 = 0;
    }
    _L001492A8:;
    return v0;
}








u8 g_ucSeVoiceState[0x8] __attribute__((aligned(8)));

static u32 Vol_r_1454;
static u32 Vol_l_1453;
/* fssdsynthRemoveSqNoRelease @ 0x1491E0 .. 0x14923C (0x5c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   cfg: kept goto: 0x149208 -> .L00149220
 *   cfg: kept goto: 0x149218 -> .L00149230
 */


u32 fssdsynthRemoveSqNoRelease(s32 a0 /* r4 */) {
    u32 v1;
    u32 v0;

    v1 = (u32)a0 << 4;
    v0 = (u32)s_esmData;
    v0 = (u32)((u8 *)s_esmData + v1);
    v1 = v0 + 0x240;
    v0 = *(u32 *)((v0 + 0x240));
    if (v0 != 0) {
        *(u32 *)v1 = 0;
        *(u32 *)((v1 + 4)) = 0;
        goto _L00149220;
    } else {
        v0 = -1;
        goto _L00149230;
        _L00149220:;
        FlushCache(0);
        v0 = 0;
    }
    _L00149230:;
    return v0;
}


/* fssdsynthPlaySq @ 0x149140 .. 0x1491D4 (0x94 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x14919c writes a register its branch at 0x149198 reads
 *   cfg: kept branch: 0x14914c if (..) goto .L00149168
 *   cfg: kept goto: 0x149160 -> .L001491C8
 *   cfg: kept branch: 0x149168 if (..) goto .L00149180
 *   cfg: kept goto: 0x149178 -> .L001491C8
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




signed int fssdsynthPlaySq(signed int a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */) {
    s32 t0;
    u32 v0;
    s32 t1;
    u32 v1;

    t0 = a1;
    v0 = *(u16 *)((u8 *)&s_esmData + 0x40e);
    t1 = a2;
    if (v0 != 0) {
        goto _L00149168;
    }
    v0 = -1;
    goto _L001491C8;
    _L00149168:;
    if ((s32)a0 >= 0 && !((s32)a0 > (s32)4)) {
        goto _L00149180;
    }
    v0 = -1;
    goto _L001491C8;
    _L00149180:;
    v1 = (u32)a0 << 4;
    v0 = (u32)s_esmData;
    v0 = (s32)((u8 *)s_esmData + v1);
    v1 = v0 + 0x240;
    v0 = *(s32 *)((v0 + 0x240));
    if (v0 == 0) {
        v0 = -1;
        return v0;
    }
    v0 = 0x20000;
    a0 = 4;
    a1 = 1;
    a2 = 0x20000 | 0x300;
    v0 = fssdCallRpc(a0, a1, a2, *(s32 *)((v1 + 0xc)), t0, t1);
    v0 = v0 != 0;
    v0 = -v0;
    _L001491C8:;
    return v0;
}







/* fssdsynthStopSq @ 0x1490C0 .. 0x149134 (0x74 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1490fc writes a register its branch at 0x1490f8 reads
 *   cfg: kept branch: 0x1490c4 if (..) goto .L001490E0
 *   cfg: kept goto: 0x1490d8 -> .L00149128
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




signed int fssdsynthStopSq(signed int a0 /* r4 */) {
    u32 v0;
    u32 v1;

    if ((s32)a0 >= 0 && !((s32)a0 > (s32)4)) {
        goto _L001490E0;
    }
    v0 = -1;
    goto _L00149128;
    _L001490E0:;
    v1 = (u32)a0 << 4;
    v0 = (u32)s_esmData;
    v0 = (s32)((u8 *)s_esmData + v1);
    v1 = v0 + 0x240;
    v0 = *(s32 *)((v0 + 0x240));
    if (v0 == 0) {
        v0 = -1;
        return v0;
    }
    v0 = 0x20000;
    a0 = 4;
    v0 = fssdCallRpc(a0, (s32)1, (u32)(0x20000 | 0x400), *(s32 *)((v1 + 0xc)));
    v0 = v0 != 0;
    v0 = -v0;
    _L00149128:;
    return v0;
}


/* fssdsynthSqVolume @ 0x149090 .. 0x1490C0 (0x30 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x1490b8 leaves the function
 *   declaration vs inferred signature: return signed int vs inferred void
 */





signed int fssdsynthSqVolume(signed int a0 /* r4 */, signed short a1 /* r5 */) {
    u32 a3;
    u32 v0;

    a3 = *(s32 *)(u32)((u32)(u8 *)(s_esmData + 0x24c) + (s32)((u32)a0 << 4));
    v0 = 0x10000;
    return fssdCallRpc(4, 1, 0x10000 | 0x600, a3, (s32)(s16)a1);
}


extern u32 s_sddSeTrans[];

signed int fssdsynthSeFlush(void) {
    u32 did;
    u32 size;
    u32 *stream;

    if (*(u16 *)(s_esmData + 0x40e) == 0) {
        return -1;
    }
    stream = (u32 *)(*(u32 *)(s_esmData + 0x404) | 0x20000000);
    size = stream[0] + 4;
    s_sddSeTrans[0] = *(u32 *)(s_esmData + 0x404);
    s_sddSeTrans[2] = (size + 15) & ~15;
    s_sddSeTrans[1] = *(u32 *)(s_esmData + 0x3fc);
    s_sddSeTrans[3] = 0;
    FlushCache(0);
    did = sceSifSetDma(s_sddSeTrans, 1);
    if (did == 0) {
        return -1;
    }
    while (sceSifDmaStat(did) >= 0) {
    }
    stream[0] = 0;
    fssdCallRpcVoid(4, 1, 0x10800);
    return 0;
}







/* fssdsynthAddReverb @ 0x148F10 .. 0x148FA0 (0x90 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00148F20
 *   cfg: kept branch: 0x148f20 if (..) goto .L00148F38
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




signed int fssdsynthAddReverb(signed int a0 /* r4 */, signed short a1 /* r5 */, signed short a2 /*
        r6 */, signed short a3 /* r7 */, signed short t0 /* r8 */, signed short t1 /* r9 */, signed
        short t2 /* r10 */, signed int t3 /* r11 */) {
    u8 *t6;
    s32 t5;
    s32 t4;
    u32 v1;
    s32 v0;

    t5 = 0;
    t6 = (u8 *)s_esmData + 0x380;
    t4 = -1;
    do {
        v1 = *(s32 *)t6;
        if (v1 != (u32)t4) {
            goto _L00148F38;
        }
        v0 = t5;
        break;
        _L00148F38:;
        t5 = t5 + 1;
        v1 = t5 < (s32)4;
        t6 = (u8 *)(t6 + 0x18);
    } while (v1 != 0);
    v1 = t5 < (s32)4;
    if (v1 == 0) {
        v0 = -2;
    } else {
        v1 = (u32)(a0) | 0x100;
        *(u32 *)t6 = t3;
        *(u32 *)(t6 + 4) = v1;
        a0 = (s16)a3;
        *(u16 *)(t6 + 8) = a1;
        *(u16 *)(t6 + 0xa) = a2;
        v1 = (s16)t0;
        *(u32 *)(t6 + 0xc) = a0;
        *(u32 *)(t6 + 0x10) = v1;
        *(u16 *)(t6 + 0x14) = t1;
        *(u16 *)(t6 + 0x16) = t2;
    }
    return v0;
}


/* fssdsynthRemoveReverb @ 0x148EB0 .. 0x148F10 (0x60 bytes) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x148eb0 if (..) goto .L00148EC8
 *   cfg: kept goto: 0x148ec0 -> .L00148F08
 *   declaration vs inferred signature: return signed int vs inferred u32
 */





signed int fssdsynthRemoveReverb(signed int a0 /* r4 */) {
    u32 v0;
    u32 v1;

    if ((s32)a0 >= 0 && !((s32)a0 > (s32)4)) {
        goto _L00148EC8;
    }
    v0 = -1;
    goto _L00148F08;
    _L00148EC8:;
    a0 = (u32)((u32)a0) * (u32)(0x18);
    v1 = (u32)s_esmData;
    v1 = (s32)((u8 *)s_esmData + a0);
    v0 = -1;
    a0 = v1 + 0x380;
    v1 = *(s32 *)((v1 + 0x380));
    if (v1 == v0) {
        return v0;
    }
    *(u32 *)a0 = v0;
    v0 = 0;
    _L00148F08:;
    return v0;
}


struct rev_t { float f[6]; };

void fssdsynthSetReverb(signed int rt_idx) {
    if (rt_idx < 0 || rt_idx > 4) {
        return;
    }
    *(struct rev_t *)(s_esmData + 0x3e0) = ((struct rev_t *)(s_esmData + 0x380))[rt_idx];
    FlushCache(0);
    fssdCallRpcStruct(4, 1, 0x18, 4, 0x400700, s_esmData + 0x3e0);
}


/* fssdsynthDefineSeStream @ 0x148DE0 .. 0x148DFC (0x1c bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x148df4 leaves the function
 *   return value dropped, call kept: the function is void
 */


void fssdsynthDefineSeStream(u8 *a0 /* r4 */, u8 *a1 /* r5 */) {
    u32 a3;
    u32 t0;

    a3 = (u32)a0;
    t0 = (u32)a1;
    a0 = (u8 *)4;
    a1 = (u8 *)1;
    fssdCallRpc(4, 1, (u64)(0x10000 | 0x1600), a3, t0);
    return;
}



static void sub_SeStreamNoteOn(unsigned char *a0, unsigned int a1, unsigned char a2, unsigned char a3,
        unsigned char t0, unsigned char t1, unsigned char t2, unsigned short t3) {
    u32 t4;

    *(u8 *)a0 = 0xfe;
    *(u8 *)(a0 + 1) = 1;
    t4 = a1 + 0x10000000;
    *(u8 *)(a0 + 2) = t4;
    *(u8 *)(a0 + 3) = t4 >> 8;
    *(u8 *)(a0 + 4) = t4 >> 0x10;
    *(u8 *)(a0 + 5) = t4 >> 0x18;
    *(u8 *)(a0 + 6) = (a2 & 0xf) | 0xa0;
    *(u8 *)(a0 + 7) = a3;
    *(u8 *)(a0 + 8) = t0;
    *(u8 *)(a0 + 9) = t1;
    *(u8 *)(a0 + 0xa) = t2;
    *(u8 *)(a0 + 0xb) = t3 & 0x7f;
    *(u8 *)(a0 + 0xc) = (t3 >> 7) & 0x7f;
}


/* fssdsynthSeStreamOn @ 0x148C30 .. 0x148D6C (0x13c bytes, frame 0x30) */
#ifndef PROTO_SDSYNTH_ESM
#define PROTO_SDSYNTH_ESM



#endif
struct SdSeT { char bt_idx; char ch; char key; char use; };
struct SdRevT { s32 core; s32 mode; s16 ldepth; s16 rdepth; s32 delay; s32 feedback; s16 lvol; s16 rvol; };
struct SdStrmT { s32 size; };
struct SdEsmFull { struct SdBankT bank_tbl[16]; struct SdSqT sq_tbl[4]; struct SdSeT se_tbl[64]; struct SdRevT rev_tbl[4]; struct SdRevT cur_reverb; void *top_iopp; void *iop_se_strp; void *iop_pktp; struct SdStrmT *se_strp; u32 mvol; u16 stereo; u16 running; };
u32 fssdsynthSeStreamOn(se_idx, bt_idx, bank, prog, key, vol, pan, usPitch)
    signed int se_idx;
    signed int bt_idx;
    char bank;
    char prog;
    char key;
    char vol;
    char pan;
    unsigned short usPitch; {
    unsigned int idx;
    struct SdBankT *bmp;
    struct SdSeT *sep;
    struct SdStrmT *stream;
    unsigned char *dp;

    idx = se_idx;
    if (((struct SdEsmFull *)s_esmData)->running == 0) {
        return -1;
    }
    stream = (struct SdStrmT *)((u32)((struct SdEsmFull *)s_esmData)->se_strp | 0x20000000);
    if (!((u32)(stream->size + 0x10) < 0x3fc)) {
        return -2;
    }
    dp = (unsigned char *)(((u32)stream + stream->size + 4) | 0x20000000);
    if (0 <= (s32)idx && (s32)idx < 0x40) {
        sep = &((struct SdEsmFull *)s_esmData)->se_tbl[idx & 0x7f];
        sep->bt_idx = bt_idx;
        sep->ch = prog;
        sep->key = key;
        sep->use = bank;
    } else {
        return -1;
    }
    bmp = &((struct SdEsmFull *)s_esmData)->bank_tbl[bt_idx];
    dp[0] = 0xff;
    dp[1] = bmp->hsyn_port;
    dp[2] = 0xd;
    if (((struct SdEsmFull *)s_esmData)->stereo == 0 || bmp->stereo == 0) {
        pan = 0x3f;
    }
    sub_SeStreamNoteOn(dp + 3, idx, bank, prog, key, vol, pan, usPitch);
    stream->size += 0x10;
    return idx;
}


/* fssdsynthSeStreamOn_forSurround @ 0x148C20 .. 0x148C30 (0x10 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdsynthSeStreamOn at 0x148c28 leaves the function
 *   a0 forwarded to fssdsynthSeStreamOn
 *   a1 forwarded to fssdsynthSeStreamOn
 *   a2 forwarded to fssdsynthSeStreamOn
 *   a3 forwarded to fssdsynthSeStreamOn
 *   t0 forwarded to fssdsynthSeStreamOn
 *   return value dropped, call kept: the function is void
 */


void fssdsynthSeStreamOn_forSurround(s32 a0 /* r4 */, s32 a1 /* r5 */, u8 *a2 /* r6 */, s32 a3 /*
        r7 */, s32 t0 /* r8 */, s32 t1 /* r9 */) {
    u32 t3;

    t3 = t1;
    t1 = 1;
    fssdsynthSeStreamOn(a0, a1, a2, a3, t0, 1, 0x3f, t3);
    return;
}



static void sub_SeStreamNoteOn(unsigned char *a0, unsigned int a1, unsigned char a2, unsigned char a3,
        unsigned char t0, unsigned char t1, unsigned char t2, unsigned short t3);

signed int fssdsynthSeStreamOff(signed int se_idx) {
    u8 *sep;
    u32 *stream;
    u8 *dp;

    if (*(u16 *)(s_esmData + 0x40e) == 0) {
        return -1;
    }
    if (se_idx < 0 || se_idx >= 0x40) {
        return -1;
    }
    stream = (u32 *)(*(s32 *)(s_esmData + 0x404) | 0x20000000);
    if (!(*stream + 0x10 < 0x3fc)) {
        return -2;
    }
    dp = (u8 *)(((u32)stream + *stream + 4) | 0x20000000);
    sep = s_esmData + se_idx * 4 + 0x280;
    if ((s8)sep[3] != -1) {
        dp[0] = 0xff;
        dp[1] = ((struct { s16 x; u8 pad[0x22]; } *)(s_esmData + 0x18))[(s8)sep[0]].x;
        dp[2] = 0xd;
        sub_SeStreamNoteOn(dp + 3, se_idx, sep[3], sep[1], sep[2], 0, 0x40, 0);
        *stream += 0x10;
        *(s8 *)&sep[3] = -1;
    }
    return 0;
}







/* fssdsynthPackSeStreamSurroundOn @ 0x148960 .. 0x148AF0 (0x190 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00148990
 *   cfg: kept goto: 0x148990 -> .L00148A78
 *   cfg: loop body is not one contiguous region: .L00148A78
 *   cfg: kept branch: 0x148a84 if (..) goto .L001489B8
 *   declaration vs inferred signature: 2 parameters vs 3 inferred
 */


void fssdsynthPackSeStreamSurroundOn(signed int a0 /* r4 */, void *a1 /* r5 */, u32 *a2) {
    u8 *s5;
    s32 s4;
    u32 t0;
    s32 s3;
    u32 s6;
    u8 *s2;
    u8 *s1;
    u8 *s0;
    u32 v1;
    u32 v0;
    u8 *a0_2;
    s32 a1_2;

    s5 = (u8 *)a2;
    s4 = (s32)a1;
    if ((s32)a1 > 0) {
        do {
            a0_2 = (u8 *)s_svpBuf;
            a2 = (u32 *)(s32)0x10;
            s3 = 0;
            memset((void *)s_svpBuf, 0, (unsigned int)a2);
            s1 = (u8 *)s_svpBuf;
            goto _L00148A78;
            _L001489B8:;
            s6 = *(s32 *)(s5 + 8);
            a2 = (u32 *)s_esmData;
            v1 = s6 & 0x7f;
            v1 = v1 << 2;
            v1 = (s32)((u8 *)s_esmData + (u32)v1);
            a1_2 = *(s8 *)((v1 + 0x280));
            s2 = (u8 *)(s32)(v1 + 0x280);
            if (0 <= a1_2) {
                if (a1_2 < (s32)0x10) {
                    a0_2 = (u8 *)*(s8 *)(s2 + 3);
                    v1 = -1;
                    if ((u32)a0_2 != v1) {
                        v1 = *(s32 *)(s5 + 0xc);
                        a0_2 = (u8 *)(s32)((u32)a1_2 << 3);
                        a0_2 = (u8 *)(a0_2 + a1_2);
                        a0_2 = (u8 *)(s32)((u32)a0_2 << 2);
                        s0 = (u8 *)((u8 *)a2 + (u32)(a0_2));
                        if (v1 != 0) {
                            v0 = *(s32 *)(s5 + 4);
                            a0_2 = (u8 *)&Vol_l_1453;
                            a2 = (u32 *)*(s32 *)s5;
                            a1_2 = (s32)&Vol_r_1454;
                            t0 = 0x7ff;
                            SetSurroundVolume2((signed int *)&Vol_l_1453, (signed int
                                *)&Vol_r_1454, (signed int)a2, -v0, t0);
                            v1 = Vol_l_1453;
                            *(u16 *)s1 = v1;
                            v1 = Vol_r_1454;
                            *(u16 *)(s1 + 2) = v1;
                        }
                        v1 = *(s32 *)s0;
                        s3 = s3 + 1;
                        *(u32 *)(s1 + 4) = v1;
                        v1 = *(s8 *)(s2 + 1);
                        *(u16 *)(s1 + 8) = v1;
                        *(u16 *)(s1 + 0xa) = s6;
                        v1 = *(s16 *)(s0 + 0x18);
                        *(u16 *)(s1 + 0xc) = v1;
                        v1 = *(s32 *)(s5 + 0xc);
                        *(u16 *)(s1 + 0xe) = v1;
                        s1 = (u8 *)(s1 + 0x10);
                    }
                }
            }
            s5 = (u8 *)(s5 + 0x10);
            s4 = s4 + -1;
            while (1) {
                _L00148A78:;
                if (s3 > (s32)0x1f) {
                    break;
                }
                if (s4 > 0) {
                    goto _L001489B8;
                }
                break;
            }
            if (s3 > 0) {
                v0 = 0x410000;
                a2 = (u32 *)(s32)((u32)s3 << 4);
                a0_2 = (u8 *)(s32)4;
                a1_2 = 1;
                t0 = 0x410000 | 0x1c00;
                fssdCallRpcStruct((signed int)a0_2, a1_2, (signed int)a2, 0, t0, (void *)s_svpBuf);
            }
        } while (s4 > 0);
    }
    return;
}






/* fssdsynthUpdateVoiceInfo @ 0x148870 .. 0x14895C (0xec bytes, frame 0x20) */


signed int fssdsynthUpdateVoiceInfo(void) {
    s32 a3;
    u32 a2;
    u32 a1;
    u32 a0;
    u32 s0;
    u32 v1;
    u32 v0;

    v0 = 0x810000;
    a3 = 0xa0;
    v0 = fssdCallRpcStruct(4, 1, 0, a3, 0x810000 | 0x200, (void *)0);
    s0 = v0;
    v0 = fssdGetCalledRpcResult();
    a3 = 0;
    a2 = v0;
    a1 = (u32)g_voice;
    do {
        a0 = *(u8 *)a2;
        a3 = a3 + 8;
        v1 = (u32)a3 < (u32)0x98;
        *(u8 *)a1 = a0;
        a0 = *(u8 *)((a2 + 1));
        *(u8 *)((a1 + 1)) = a0;
        a0 = *(u8 *)((a2 + 2));
        *(u8 *)((a1 + 2)) = a0;
        a0 = *(u8 *)((a2 + 3));
        *(u8 *)((a1 + 3)) = a0;
        a0 = *(u8 *)((a2 + 4));
        *(u8 *)((a1 + 4)) = a0;
        a0 = *(u8 *)((a2 + 5));
        *(u8 *)((a1 + 5)) = a0;
        a0 = *(u8 *)((a2 + 6));
        *(u8 *)((a1 + 6)) = a0;
        a0 = *(u8 *)((a2 + 7));
        *(u8 *)((a1 + 7)) = a0;
        a2 = a2 + 8;
        a1 = a1 + 8;
    } while (v1 != 0);
    a1 = v0 + a3;
    if ((u32)a3 < (u32)0xa0) {
        v0 = (u32)g_voice;
        a0 = (s32)((u8 *)g_voice + a3);
        do {
            v1 = *(u8 *)a1;
            a3 = a3 + 1;
            v0 = (u32)a3 < (u32)0xa0;
            *(u8 *)a0 = v1;
            a1 = a1 + 1;
            a0 = a0 + 1;
        } while (v0 != 0);
    }
    return s0;
}


/* fssdsynthPortSoundOff @ 0x148850 .. 0x148868 (0x18 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpcInt at 0x148860 leaves the function
 *   return value dropped, call kept: the function is void
 */


void fssdsynthPortSoundOff(s32 a0 /* r4 */) {
    u32 a3;

    a3 = a0;
    a0 = 4;
    fssdCallRpcInt(4, 1, (u64)(0x10000 | 0x300), a3);
    return;
}


/* fssdsynthSetMVolume @ 0x148830 .. 0x148844 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpcInt at 0x14883c leaves the function
 *   return value dropped, call kept: the function is void
 */


void fssdsynthSetMVolume(s32 a0 /* r4 */) {
    u16 a3;

    a3 = (u16)a0;
    a0 = 4;
    fssdCallRpcInt(4, 1, 0x300, a3);
    return;
}


/* fssdsynthGetTransStatus @ 0x148810 .. 0x148828 (0x18 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x148820 leaves the function
 *   return value dropped, call kept: the function is void
 */


void fssdsynthGetTransStatus(u8 *a0 /* r4 */) {
    u32 a3;

    a3 = (u32)a0;
    a0 = (u8 *)4;
    fssdCallRpc(4, 1, 0x800, a3, 0);
    return;
}


/* fssdsynthSetParam @ 0x1487F0 .. 0x148808 (0x18 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x148800 leaves the function
 *   return value dropped, call kept: the function is void
 */


void fssdsynthSetParam(s32 a0 /* r4 */, s32 a1 /* r5 */) {
    u16 a3;
    u16 t0;

    a3 = (u16)a0;
    t0 = (u16)a1;
    a0 = 4;
    a1 = 1;
    fssdCallRpc(4, 1, 0xd00, a3, t0);
    return;
}


/* fssdsynthSetCoreAttr @ 0x1487D0 .. 0x1487E8 (0x18 bytes) */
/*
 * dcomp notes:
 *   tail: j fssdCallRpc at 0x1487e0 leaves the function
 *   return value dropped, call kept: the function is void
 */


void fssdsynthSetCoreAttr(s32 a0 /* r4 */, s32 a1 /* r5 */) {
    u16 a3;
    u16 t0;

    a3 = (u16)a0;
    t0 = (u16)a1;
    a0 = 4;
    a1 = 1;
    fssdCallRpc(4, 1, 0x1000, a3, t0);
    return;
}


/* fssdsynthUpdateSeState @ 0x148740 .. 0x1487C8 (0x88 bytes, frame 0x20) */


u32 fssdsynthUpdateSeState(void) {
    u32 v0;
    u32 s0;
    u32 v1;

    v0 = 0x10000;
    v0 = fssdCallRpcStruct((s32)4, (s32)1, 0, (s32)8, (u32)(0x10000 | 0x1f00), (void *)0);
    s0 = v0;
    v0 = fssdGetCalledRpcResult();
    v1 = *(u8 *)v0;
    g_ucSeVoiceState[0] = v1;
    v1 = *(u8 *)((v0 + 1));
    *(u8 *)((u8 *)&g_ucSeVoiceState[0] + 1) = v1;
    v1 = *(u8 *)((v0 + 2));
    *(u8 *)((u8 *)&g_ucSeVoiceState[0] + 2) = v1;
    v1 = *(u8 *)((v0 + 3));
    *(u8 *)((u8 *)&g_ucSeVoiceState[0] + 3) = v1;
    v1 = *(u8 *)((v0 + 4));
    *(u8 *)((u8 *)&g_ucSeVoiceState[0] + 4) = v1;
    v1 = *(u8 *)((v0 + 5));
    *(u8 *)((u8 *)&g_ucSeVoiceState[0] + 5) = v1;
    v1 = *(u8 *)((v0 + 6));
    *(u8 *)((u8 *)&g_ucSeVoiceState[0] + 6) = v1;
    v0 = *(u8 *)((v0 + 7));
    *(u8 *)((u8 *)&g_ucSeVoiceState[0] + 7) = v0;
    v0 = s0;
    return v0;
}






/* fssdsynthGetSeState @ 0x1486F0 .. 0x148740 (0x50 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int fssdsynthGetSeState(signed int a0 /* r4 */) {
    u32 a1;
    u32 v0;

    if ((s32)a0 < 0 || (s32)a0 >= (s32)0x40) {
        v0 = 0;
    } else {
        v0 = (u32)g_ucSeVoiceState;
        a1 = *(u8 *)(u32)(s32)((u8 *)g_ucSeVoiceState + (u32)((u32)a0 >> 3));
        v0 = 1;
        v0 = (u32)v0 << (u32)((s32)a0 % (s32)(8));
        v0 = a1 & (u32)v0;
    }
    return v0;
}









/* fssdsynthGetSqAddrOnIopMemory @ 0x1486D0 .. 0x1486E8 (0x18 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1486e4 computes the return value
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int fssdsynthGetSqAddrOnIopMemory(signed int a0 /* r4 */) {
    u32 *v0;

    v0 = (u32 *)((u8 *)s_esmData + 0x240);
    return *(s32 *)(u32 *)(s32)((u8 *)v0 + (s32)((u32)a0 << 4));
}


extern short _Sinf511(int);
extern short _Cosf511(int);

static void SetSurroundVolume2(signed int *Vol_l, signed int *Vol_r, signed int n_velo, signed int n_pan, signed int max_pan) {
    short (*SinFunc)(int);
    short (*CosFunc)(int);

    if (n_velo > 0x7f) n_velo = 0x7f;
    if (n_velo < 0) n_velo = 0;

    if (n_pan > max_pan) n_pan = max_pan;
    if (n_pan < -max_pan) n_pan = -max_pan;

    SinFunc = _Sinf511;
    CosFunc = _Cosf511;

    if (n_pan >= 0) {
        *Vol_l = n_velo * CosFunc(n_pan) / 0x7f;
        *Vol_r = n_velo * SinFunc(n_pan) / 0x7f;
    } else {
        n_pan = -n_pan;
        *Vol_l = n_velo * CosFunc(n_pan) / 0x7f;
        *Vol_r = -n_velo * SinFunc(n_pan) / 0x7f;
    }
}


static u32 s_SinTable[0x40] = {
    0xca0000, 0x25f0195, 0x3f4032a, 0x58804be, 0x71c0652, 0x8ae07e5, 0xa3f0976, 0xbce0b06,
    0xd5b0c95, 0xee60e21, 0x106f0fab, 0x11f61133, 0x137912b8, 0x14fa143a, 0x167715b9,
    0x17f11734, 0x196718ac, 0x1ad91a20, 0x1c461b90, 0x1db01cfc, 0x1f141e63, 0x20741fc5,
    0x21cf2122, 0x2324227a, 0x247423cd, 0x25bf251a, 0x27032661, 0x284127a3, 0x297928de,
    0x2aaa2a12, 0x2bd52b41, 0x2cf92c68, 0x2e162d88, 0x2f2b2ea1, 0x30392fb3, 0x314030be,
    0x323f31c1, 0x333632bc, 0x342533af, 0x350c349a, 0x35ea357c, 0x36c13657, 0x378e3728,
    0x385337f2, 0x390f38b2, 0x39c2396a, 0x3a6c3a18, 0x3b0d3abe, 0x3ba43b5a, 0x3c333bed,
    0x3cb83c76, 0x3d333cf6, 0x3da53d6d, 0x3e0d3dda, 0x3e6b3e3d, 0x3ec03e97, 0x3f0a3ee6,
    0x3f4b3f2c, 0x3f823f68, 0x3faf3f9a, 0x3fd23fc2, 0x3feb3fe0, 0x3ffa3ff4, 0x3fff3ffe
};
static struct TransBankSt s_TransBank = {
    1
};

/* fssdsynthCheckSqEosAll @ 0x148490 .. 0x148520 (0x90 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1626 -> 0x2288c0
 *   stack: address of the slot at 0x10 escapes at 0x1484c0
 *   literal: @1626 initializes the 16-byte local at 0x10
 *   cfg: loop body is not one contiguous region: .L001484C0
 */


signed int fssdsynthCheckSqEosAll(void) {
    u32 a2;
    s32 a1;
    u32 a0;
    s32 v1;
    u32 v0;

    v0 = 0x2288c0;
    {
        struct stackFrame_10 { u8 b[16]; } stackFrame_10 __attribute__((aligned(16))) = {{0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff}};
        a0 = (u32)((u8 *)&stackFrame_10);
        a2 = (u32)(u8 *)(s_esmData + 0x240);
        a1 = 0;
        v1 = -1;
        do {
            v0 = *(s32 *)a2;
            if (v0 != 0 && (u32)*(s32 *)((a2 + 8)) != (u32)v1) {
                v0 = *(s32 *)((a2 + 0xc));
                *(u32 *)a0 = v0;
            }
            a0 = a0 + 4;
            a2 = a2 + 0x10;
            a1 = a1 + 1;
            v0 = a1 < (s32)4;
        } while (v0 != 0);
        a0 = 4;
        v0 = 0x20000;
        a1 = 1;
        a2 = 0x10;
        v0 = fssdCallRpcStruct(a0, a1, a2, a0, 0x20000 | 0x200, (void *)(u8 *)((u8
            *)&stackFrame_10));
        return v0;
    }
}


/* fssdsynthAddSpu2MemoryBlock @ 0x148480 .. 0x148488 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j FsSpuMmng_AddMemBlock at 0x148480 leaves the function
 *   return value dropped, call kept: the function is void
 */


void fssdsynthAddSpu2MemoryBlock(void) {
    FsSpuMmng_AddMemBlock();
    return;
}


/* fssdsynthAssociateSpu2MemBlockIdWithPort @ 0x148440 .. 0x148480 (0x40 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00148450
 *   declaration vs inferred signature: return void vs inferred u32
 */


void fssdsynthAssociateSpu2MemBlockIdWithPort(signed int a0 /* r4 */, unsigned int a1 /* r5 */) {
    s32 t0;
    u32 *a3;
    s32 a2;
    s32 v1;

    t0 = 0;
    a3 = s_iPortSpuMap;
    a2 = 1;
    do {
        v1 = (u32)a2 << (u32)t0;
        if ((u32)((u32)(a1) & v1) != 0) {
            *(u32 *)a3 = a0;
        }
        t0 = t0 + 1;
        v1 = t0 < (s32)0x10;
        a3 = (u32 *)((u8 *)a3 + 4);
    } while ((u32)v1 != 0);
    return;
}


static u32 s_iPortSpuMap[0x10];
u8 g_voice[0xa0];
