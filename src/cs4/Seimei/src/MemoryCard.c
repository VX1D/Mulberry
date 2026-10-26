#include "common.h"
extern u8 SaveSys[];
extern u32 MCLoadListNum;
extern u32 lpMCMng;
extern u8 SaveData[];
extern signed int fsmc_GetFileInfo(signed int, signed int);
extern u32 fsmc_FuncCheck(void);
extern u32 fsmc_MessageCheck(void);
extern signed int fsmc_Format(signed int, signed int);
extern signed int fsmc_MkDir(signed int, signed int, char *);
extern signed int fsmc_DataWrite(signed int, signed int, char *, void *, unsigned int);
extern signed int fsmc_IconWrite(signed int, signed int, char *, void *, unsigned int);
extern u8 GameSt[];
extern u32 fsmc_Init(void);
extern void *memset();
extern u32 GetIconDataPtr(void);
extern u32 GetIconDataSize(void);
extern u32 IconSys[];
signed int ExistSaveData(signed int a0 /* r4 */);
u32 ExistKuonData(void);
signed int GetNeedCluster(signed int a0 /* r4 */);
u8 * GetSaveData(void);
u8 * GetSaveSystem(void);
u32 GetSaveDataHeader(s32 a0 /* r4 */);
signed int GetMemoryCardMessage(unsigned char a0 /* r4 */);
static u32 MCProcFormat(void);
static signed int MCProcSaveHeader(void);
static u32 MCProcEasyCheck(void);
u32 InitMemoryCard(void);

/* In the original .bss MCLoadList sits 0x30 bytes after FileName
   (at 0xA333C0); it was declared 64-byte aligned there. */
typedef u32 dcomp_MCLoadList_type[0x80] __attribute__((aligned(64)));
static u8 MemoryCardMng[0x50]; /* +0x28 B unreferenced tail in the original */
static u8 SaveData[0x320];
static u8 SaveSys[0x50];

static dcomp_MCLoadList_type MCLoadList;
static u32 FileName[0x10];
static u32 SavePointID[0x5];
static u32 MCLoadListNum;

/* InitMemoryCard @ 0x19DE60 .. 0x19DEEC (0x8c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u32 InitMemoryCard(void) {
    u32 v0;
    u32 a0;
    u32 *v1;

    do {
        v0 = fsmc_Init();
    } while ((s32)v0 < 0);
    a0 = lpMCMng;
    memset(a0, 0, 0x28);
    v0 = lpMCMng;
    v1 = IconSys;
    *(u32 *)((v0 + 0xc)) = (u32)IconSys;
    v0 = GetIconDataPtr();
    v1 = (u32 *)lpMCMng;
    *(u32 *)(((u8 *)v1 + 0x10)) = v0;
    v0 = lpMCMng;
    *(u32 *)((v0 + 0x14)) = 0;
    v0 = lpMCMng;
    *(u32 *)((v0 + 0x18)) = 0;
    v0 = GetIconDataSize();
    v1 = (u32 *)lpMCMng;
    *(u32 *)(((u8 *)v1 + 0x1c)) = v0;
    v1 = (u32 *)lpMCMng;
    *(u32 *)(((u8 *)v1 + 0x20)) = 0;
    v1 = (u32 *)lpMCMng;
    *(u32 *)(((u8 *)v1 + 0x24)) = 0;
    return;
}


/* MemoryCardStart @ 0x19DC90 .. 0x19DE58 (0x1c8 bytes) */
/*
 * dcomp notes:
 *   literal: @1885 -> 0x255050
 *   delay: addiu at 0x19dc9c writes a register its branch at 0x19dc98 reads
 *   indirect: jr v0 at 0x19dcec -> <v0>
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

static signed int MCProcCheck(void);
static u32 MCProcLoadList(void);
static signed int MCProcLoadData(void);
static signed int MCProcSaveData(void);
extern u32 L1885[];

struct McM { u8 mode; u8 state; u8 port; u8 b3; u8 slot; u8 b5; u8 flag[2]; void *proc; };
#define MCM ((struct McM *)lpMCMng)
signed int MemoryCardStart(unsigned char a0, unsigned char a1, unsigned char a2) {
    if (MCM->state != 0) {
        return -1;
    }
    MCM->mode = a0;
    MCM->port = a1;
    MCM->b3 = 0;
    MCM->slot = (s32)a2;
    MCM->b5 = 0;
    switch (a0) {
    case 0:
        MCM->state = 1;
        MCM->proc = MCProcCheck;
        { u8 *base = (u8 *)lpMCMng; base[a1 + 6] = 0; }
        break;
    case 6:
        MCM->state = 1;
        MCM->proc = MCProcEasyCheck;
        { u8 *base = (u8 *)lpMCMng; base[a1 + 6] = 0; }
        break;
    case 1:
        MCM->state = 1;
        MCM->proc = MCProcLoadList;
        { u8 *base = (u8 *)lpMCMng; base[a1 + 6] = 0; }
        break;
    case 2:
        MCM->state = 1;
        MCM->proc = MCProcLoadData;
        { u8 *base = (u8 *)lpMCMng; base[a1 + 6] = 0; }
        break;
    case 3:
        MCM->state = 1;
        MCM->proc = MCProcSaveData;
        { u8 *base = (u8 *)lpMCMng; base[a1 + 6] = 0; }
        break;
    case 4:
        MCM->state = 1;
        MCM->proc = MCProcLoadList;
        { u8 *base = (u8 *)lpMCMng; base[a1 + 6] = 0; }
        break;
    case 5:
        MCM->state = 1;
        MCM->proc = MCProcFormat;
        { u8 *base = (u8 *)lpMCMng; base[a1 + 6] = 0; }
    default:
        break;
    }
    return 0;
}


/* MemoryCardProc @ 0x19DBF0 .. 0x19DC8C (0x9c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: daddu at 0x19dc04 writes a register its branch at 0x19dc00 reads
 *   cfg: kept branch: 0x19dc2c if (..) goto .L0019DC78
 */

static u32 MCProcLoadList();

signed int MemoryCardProc(void) {
    u8 *a1;
    u32 a0;
    u32 v1;
    u32 v0;

    v1 = lpMCMng;
    v0 = *(u8 *)((v1 + 1));
    if (v0 == 0) {
        v0 = 0;
        return v0;
    }
    v0 = *(s32 *)((v1 + 8));
    v0 = ((u32 (*)(void))(s32)v0)();
    if (v0 != 0) {
        if ((s32)v0 > 0) {
            a1 = (u8 *)lpMCMng;
            v1 = 4;
            a0 = *(u8 *)a1;
            if (a0 != v1 || (u32)*(s32 *)(a1 + 8) != (u32)MCProcLoadList) {
                goto _L0019DC78;
            }
            v0 = 1;
            *(u8 *)(a1 + 1) = v0;
            a0 = (u32)MCProcSaveHeader;
            v1 = lpMCMng;
            *(u32 *)((v1 + 8)) = (u32)MCProcSaveHeader;
            v0 = 0;
        } else {
            _L0019DC78:;
            v1 = lpMCMng;
            *(u8 *)((v1 + 1)) = 0;
        }
    }
    return v0;
}





/* MCProcCheck @ 0x19D9C0 .. 0x19DBF0 (0x230 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @1394 is the string '/BASLUS-21007-KUON'
 *   delay: addiu at 0x19d9dc writes a register its branch at 0x19d9d8 reads
 *   delay: addiu at 0x19d9f0 writes a register its branch at 0x19d9ec reads
 *   delay: addiu at 0x19da4c writes a register its branch at 0x19da48 reads
 *   delay: addiu at 0x19dab4 writes a register its branch at 0x19dab0 reads
 *   delay: addiu at 0x19db24 writes a register its branch at 0x19db20 reads
 *   cfg: kept branch: 0x19da1c if (..) goto .L0019DA30
 *   cfg: kept branch: 0x19da30 if (..) goto .L0019DBD8
 *   cfg: kept branch: 0x19da70 if (..) goto .L0019DBD8
 *   cfg: kept branch: 0x19daf8 if (..) goto .L0019DB08
 *   cfg: kept branch: 0x19db08 if (..) goto .L0019DBD8
 *   cfg: kept branch: 0x19db48 if (..) goto .L0019DBD8
 *   cfg: kept branch: 0x19db58 if (..) goto .L0019DBD0
 *   cfg: kept branch: 0x19db70 if (..) goto .L0019DBD0
 *   cfg: kept branch: 0x19db8c if (..) goto .L0019DBD0
 */

extern signed int fsmc_GetDir(signed int, signed int, char *, unsigned int, unsigned int, void *);
extern u32 fsmc_GetDirPoints(void);
extern signed int fsmc_GetFreeMemory(signed int, signed int);
extern u32 MCLoadList[];

static signed int MCProcCheck(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u32 s0;

    v0 = 5;
    a1 = lpMCMng;
    v1 = *(u8 *)((a1 + 1));
    switch (v1) {
    case 1:
        a0 = *(u8 *)((a1 + 2));
        a1 = *(u8 *)((a1 + 3));
        v0 = fsmc_GetFileInfo(a0, a1);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019DA30;
            }
            v0 = -1;
            break;
            _L0019DA30:;
            v1 = lpMCMng;
            v0 = *(u8 *)((v1 + 5));
            v0 = v0 + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019DBD8;
            }
            v0 = -1;
            return v0;
        }
        v0 = lpMCMng;
        v1 = 2;
        *(u8 *)((v0 + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 2:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019DBD8;
        }
        s0 = lpMCMng;
        v0 = fsmc_MessageCheck();
        v1 = *(u8 *)((s0 + 2));
        v1 = v1 + s0;
        *(u8 *)((v1 + 6)) = v0;
        a0 = lpMCMng;
        v0 = *(u8 *)((a0 + 2));
        v0 = v0 + a0;
        v1 = *(u8 *)((v0 + 6));
        if (v1 != 0) {
            v0 = 2;
            if (v1 != v0) {
                v0 = -1;
                return v0;
            }
        }
        v0 = 4;
        *(u8 *)((a0 + 1)) = v0;
    case 4:
        v0 = lpMCMng;
        a0 = *(u8 *)((v0 + 2));
        a1 = *(u8 *)((v0 + 3));
        v0 = fsmc_GetDir(a0, a1, "/BASLUS-21007-KUON", 0, 8, (void *)MCLoadList);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019DB08;
            }
            v0 = -1;
            break;
            _L0019DB08:;
            v1 = lpMCMng;
            v0 = *(u8 *)((v1 + 5));
            v0 = v0 + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019DBD8;
            }
            v0 = -1;
            return v0;
        }
        v0 = lpMCMng;
        v1 = 5;
        *(u8 *)((v0 + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 5:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019DBD8;
        }
        v0 = fsmc_GetDirPoints();
        MCLoadListNum = (u32)v0;
        v0 = MCLoadListNum;
        if (v0 != 0) {
            goto _L0019DBD0;
        }
        a1 = lpMCMng;
        v0 = 2;
        a0 = *(u8 *)((a1 + 2));
        v1 = a0 + a1;
        v1 = *(u8 *)((v1 + 6));
        if (v1 == v0) {
            goto _L0019DBD0;
        }
        v0 = *(s32 *)((a1 + 0x1c));
        a1 = *(u8 *)((a1 + 3));
        v0 = v0 + 0x3ff;
        v0 = v0 >> 0xa;
        s0 = v0 + 7;
        v0 = fsmc_GetFreeMemory(a0, a1);
        if ((s32)s0 <= (s32)v0) {
            goto _L0019DBD0;
        }
        a1 = lpMCMng;
        a0 = 0x1f;
        v0 = -1;
        v1 = *(u8 *)((a1 + 2));
        *(u8 *)((((u32)(v1 + a1)) + 6)) = a0;
        break;
        _L0019DBD0:;
        v0 = 1;
        return v0;
    default:
        _L0019DBD8:;
        v0 = 0;
    }
    return v0;
}




/* MCProcEasyCheck @ 0x19D8B0 .. 0x19D9B8 (0x108 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x19d8cc writes a register its branch at 0x19d8c8 reads
 *   delay: addiu at 0x19d924 writes a register its branch at 0x19d920 reads
 *   delay: addiu at 0x19d98c writes a register its branch at 0x19d988 reads
 *   cfg: kept branch: 0x19d8f4 if (..) goto .L0019D908
 *   cfg: kept goto: 0x19d900 -> .L0019D9A8
 *   cfg: kept goto: 0x19d998 -> .L0019D9A8
 */










static u32 MCProcEasyCheck(void) {
    u32 v0;
    u32 a1;
    u32 v1;
    u32 a0;
    u8 *s0;

    v0 = 2;
    a1 = lpMCMng;
    v1 = *(u8 *)((a1 + 1));
    switch (v1) {
    case 1:
        a0 = *(u8 *)((a1 + 2));
        a1 = *(u8 *)((a1 + 3));
        v0 = fsmc_GetFileInfo(a0, a1);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019D908;
            }
            v0 = -1;
            goto _L0019D9A8;
            _L0019D908:;
            v1 = lpMCMng;
            v0 = *(u8 *)((v1 + 5));
            v0 = v0 + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                break;
            }
            v0 = -1;
            return v0;
        }
        v0 = lpMCMng;
        v1 = 2;
        *(u8 *)((v0 + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 2:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            break;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        v1 = *(u8 *)(((u8 *)s0 + 2));
        v1 = (s32)((u8 *)v1 + (u32)(s0));
        *(u8 *)((v1 + 6)) = v0;
        v1 = lpMCMng;
        v0 = *(u8 *)((v1 + 2));
        v0 = v0 + v1;
        v1 = *(u8 *)((v0 + 6));
        if (v1 != 0) {
            v0 = 2;
            if (v1 != v0) {
                v0 = -1;
                return v0;
            }
        }
        v0 = 1;
        return v0;
    }
    v0 = 0;
    _L0019D9A8:;
    return v0;
}






/* MCProcLoadList @ 0x19D580 .. 0x19D8A8 (0x328 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @1719 -> 0x255030
 *   literal: @1394 is the string '/BASLUS-21007-KUON'
 *   literal: @1395 is the string '/BASLUS-21007-KUON/BASLUS-21007-KUON'
 *   indirect: jr v0 at 0x19d5b0 -> <v0>
 *   delay: addiu at 0x19d5fc writes a register its branch at 0x19d5f8 reads
 *   delay: addiu at 0x19d714 writes a register its branch at 0x19d710 reads
 *   delay: addiu at 0x19d814 writes a register its branch at 0x19d810 reads
 *   cfg: kept branch: 0x19d5e0 if (..) goto .L0019D890
 *   cfg: kept branch: 0x19d620 if (..) goto .L0019D890
 *   cfg: kept branch: 0x19d660 if (..) goto .L0019D698
 *   cfg: kept branch: 0x19d6f8 if (..) goto .L0019D890
 *   cfg: kept branch: 0x19d738 if (..) goto .L0019D890
 *   cfg: kept branch: 0x19d7f8 if (..) goto .L0019D890
 *   cfg: kept branch: 0x19d838 if (..) goto .L0019D890
 */

extern signed int fsmc_DataRead(signed int, signed int, char *, void *, unsigned int);

static u32 MCProcLoadList(void) {
    s32 t0;
    u32 a2;
    u32 a1;
    u32 a0;
    u8 *s0;
    u32 v1;
    u32 v0;

    a1 = lpMCMng;
    v0 = *(u8 *)((a1 + 1));
    switch (v0) {
    case 1:
        a0 = *(u8 *)((a1 + 2));
        a1 = *(u8 *)((a1 + 3));
        v0 = fsmc_GetFileInfo(a0, a1);
        if (v0 != 0) {
            if ((s32)v0 < 0) {
                v0 = -1;
                break;
            } else {
                v1 = lpMCMng;
                v0 = *(u8 *)((v1 + 5));
                v0 = v0 + 1;
                *(u8 *)((v1 + 5)) = v0;
                v0 = (u8)v0;
                v0 = (s32)v0 < (s32)0xa;
                if (v0 != 0) {
                    goto _L0019D890;
                }
                v0 = -1;
                break;
            }
        } else {
            v0 = lpMCMng;
            v1 = 2;
            *(u8 *)((v0 + 1)) = v1;
            v0 = lpMCMng;
            *(u8 *)((v0 + 5)) = 0;
        }
    case 2:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019D890;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        a0 = *(u8 *)(s0 + 2);
        v1 = 3;
        *(u8 *)(((u32)(s32)((u8 *)a0 + (u32)(s0)) + 6)) = v0;
        a1 = lpMCMng;
        v0 = *(u8 *)((a1 + 2));
        v0 = v0 + a1;
        a0 = *(u8 *)((v0 + 6));
        a2 = v0 + 6;
        if (a0 != v1) {
            v0 = 4;
            if (a0 != v0) {
                goto _L0019D698;
            }
        }
        *(u8 *)a2 = 0;
        a0 = (u32)SaveSys;
        a2 = 0x50;
        MCLoadListNum = 0;
        memset(SaveSys, 0, a2);
        v0 = 1;
        break;
        _L0019D698:;
        v0 = 2;
        if (a0 != 0 && a0 != v0) {
            v0 = -1;
            break;
        } else {
            v0 = 4;
            *(u8 *)((a1 + 1)) = v0;
        }
    case 4:
        v0 = lpMCMng;
        a2 = (u32)"/BASLUS-21007-KUON";
        t0 = 8;
        a0 = *(u8 *)((v0 + 2));
        a1 = *(u8 *)((v0 + 3));
        v0 = fsmc_GetDir(a0, a1, "/BASLUS-21007-KUON", 0, t0, (void *)MCLoadList);
        if (v0 != 0) {
            if ((s32)v0 < 0) {
                v0 = -1;
                break;
            } else {
                v1 = lpMCMng;
                v0 = *(u8 *)((v1 + 5));
                v0 = v0 + 1;
                *(u8 *)((v1 + 5)) = v0;
                v0 = (u8)v0;
                v0 = (s32)v0 < (s32)0xa;
                if (v0 != 0) {
                    goto _L0019D890;
                }
                v0 = -1;
                break;
            }
        } else {
            v0 = lpMCMng;
            v1 = 5;
            *(u8 *)((v0 + 1)) = v1;
            v0 = lpMCMng;
            *(u8 *)((v0 + 5)) = 0;
        }
    case 5:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019D890;
        }
        v0 = fsmc_GetDirPoints();
        s0 = (u8 *)lpMCMng;
        MCLoadListNum = v0;
        v0 = fsmc_MessageCheck();
        v1 = *(u8 *)(s0 + 2);
        *(u8 *)(((u32)(s32)((u8 *)v1 + (u32)(s0)) + 6)) = v0;
        v1 = lpMCMng;
        v0 = *(u8 *)((v1 + 2));
        v0 = v0 + v1;
        v0 = *(u8 *)((v0 + 6));
        if (v0 != 0) {
            v0 = -1;
            break;
        } else {
            v0 = MCLoadListNum;
            if (v0 == 0) {
                a0 = (u32)SaveSys;
                a2 = 0x50;
                memset(SaveSys, 0, a2);
                v0 = 1;
                break;
            } else {
                v0 = 6;
                *(u8 *)((v1 + 1)) = v0;
            }
        }
    case 6:
        v0 = lpMCMng;
        a2 = (u32)"/BASLUS-21007-KUON/BASLUS-21007-KUON";
        a0 = *(u8 *)((v0 + 2));
        a1 = *(u8 *)((v0 + 3));
        t0 = 0x50;
        v0 = fsmc_DataRead(a0, a1, "/BASLUS-21007-KUON/BASLUS-21007-KUON", (void *)SaveSys, t0);
        if (v0 != 0) {
            if ((s32)v0 < 0) {
                v0 = -1;
                break;
            } else {
                v1 = lpMCMng;
                v0 = *(u8 *)((v1 + 5));
                v0 = v0 + 1;
                *(u8 *)((v1 + 5)) = v0;
                v0 = (u8)v0;
                v0 = (s32)v0 < (s32)0xa;
                if (v0 != 0) {
                    goto _L0019D890;
                }
                v0 = -1;
                break;
            }
        } else {
            v0 = lpMCMng;
            v1 = 7;
            *(u8 *)((v0 + 1)) = v1;
            v0 = lpMCMng;
            *(u8 *)((v0 + 5)) = 0;
        }
    case 7:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019D890;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        a0 = *(u8 *)(s0 + 2);
        v1 = 0x48;
        *(u8 *)(((u32)(s32)((u8 *)a0 + (u32)(s0)) + 6)) = v0;
        a0 = lpMCMng;
        v0 = *(u8 *)((a0 + 2));
        v0 = v0 + a0;
        v0 = *(u8 *)((v0 + 6));
        v0 = v0 != v1 ? (s32)-1 : (s32)1;
        break;
    case 0:
    case 3:
    default:
        _L0019D890:;
        v0 = 0;
    }
    return v0;
}




/* MCProcLoadData @ 0x19D370 .. 0x19D578 (0x208 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @1562 is the string '/BASLUS-21007-KUON/BASLUS-21007-KUON%02d'
 *   delay: addiu at 0x19d38c writes a register its branch at 0x19d388 reads
 *   delay: addiu at 0x19d3a0 writes a register its branch at 0x19d39c reads
 *   delay: addiu at 0x19d3fc writes a register its branch at 0x19d3f8 reads
 *   delay: addiu at 0x19d4e4 writes a register its branch at 0x19d4e0 reads
 *   cfg: kept branch: 0x19d3cc if (..) goto .L0019D3E0
 *   cfg: kept branch: 0x19d3e0 if (..) goto .L0019D560
 *   cfg: kept branch: 0x19d420 if (..) goto .L0019D560
 *   cfg: kept branch: 0x19d434 if (..) goto .L0019D468
 *   cfg: kept branch: 0x19d4b8 if (..) goto .L0019D4C8
 *   cfg: kept branch: 0x19d4c8 if (..) goto .L0019D560
 *   cfg: kept branch: 0x19d508 if (..) goto .L0019D560
 */

extern int sprintf(void *, void *, ...);
extern signed int fsmc_DataRead(signed int, signed int, char *, void *, unsigned int);
static void CopyLoadData(signed int);
extern u32 FileName[];

static signed int MCProcLoadData(void) {
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u8 *s0;
    u32 v0;

    v0 = 9;
    a1 = lpMCMng;
    v1 = *(u8 *)((a1 + 1));
    switch (v1) {
    case 1:
        a0 = *(u8 *)((a1 + 2));
        a1 = *(u8 *)((a1 + 3));
        v0 = fsmc_GetFileInfo(a0, a1);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019D3E0;
            }
            v0 = -1;
            break;
            _L0019D3E0:;
            v1 = lpMCMng;
            v0 = *(u8 *)((v1 + 5));
            v0 = v0 + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019D560;
            }
            v0 = -1;
            return v0;
        }
        v0 = lpMCMng;
        v1 = 2;
        *(u8 *)((v0 + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 2:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019D560;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        v1 = *(u8 *)(s0 + 2);
        v1 = (s32)((u8 *)v1 + (u32)(s0));
        *(u8 *)((v1 + 6)) = v0;
        v1 = lpMCMng;
        v0 = *(u8 *)((v1 + 2));
        v0 = v0 + v1;
        v0 = *(u8 *)((v0 + 6));
        if (v0 == 0) {
            goto _L0019D468;
        }
        v0 = -1;
        break;
        _L0019D468:;
        v0 = 8;
        *(u8 *)((v1 + 1)) = v0;
    case 8:
        v0 = lpMCMng;
        a0 = (u32)FileName;
        a2 = *(u8 *)((v0 + 4));
        a1 = (u32)"/BASLUS-21007-KUON/BASLUS-21007-KUON%02d";
        sprintf((void *)FileName, (void *)"/BASLUS-21007-KUON/BASLUS-21007-KUON%02d", a2);
        v0 = lpMCMng;
        a2 = (u32)FileName;
        a0 = *(u8 *)((v0 + 2));
        a1 = *(u8 *)((v0 + 3));
        v0 = fsmc_DataRead(a0, a1, (char *)FileName, (void *)SaveData, 0x320);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019D4C8;
            }
            v0 = -1;
            break;
            _L0019D4C8:;
            v1 = lpMCMng;
            v0 = *(u8 *)((v1 + 5));
            v0 = v0 + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019D560;
            }
            v0 = -1;
            return v0;
        }
        v0 = lpMCMng;
        v1 = 9;
        *(u8 *)((v0 + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 9:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019D560;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        a0 = *(u8 *)(s0 + 2);
        v1 = 0x48;
        a0 = (s32)((u8 *)a0 + (u32)(s0));
        *(u8 *)((a0 + 6)) = v0;
        a0 = lpMCMng;
        v0 = *(u8 *)((a0 + 2));
        v0 = v0 + a0;
        v0 = *(u8 *)((v0 + 6));
        if (v0 != v1) {
            v0 = -1;
            break;
        } else {
            a0 = *(u8 *)((a0 + 4));
            CopyLoadData(a0);
            v0 = 1;
            break;
        }
    default:
        _L0019D560:;
        v0 = 0;
    }
    return v0;
}



/* MCProcSaveData @ 0x19CDA0 .. 0x19D368 (0x5c8 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @1394 is the string '/BASLUS-21007-KUON'
 *   literal: @1562 is the string '/BASLUS-21007-KUON/BASLUS-21007-KUON%02d'
 *   literal: @1395 is the string '/BASLUS-21007-KUON/BASLUS-21007-KUON'
 *   literal: @1396 is the string '/BASLUS-21007-KUON/view.ico'
 *   literal: @1397 is the string '/BASLUS-21007-KUON/icon.sys'
 *   delay: addiu at 0x19cdbc writes a register its branch at 0x19cdb8 reads
 *   delay: addiu at 0x19cdd0 writes a register its branch at 0x19cdcc reads
 *   delay: addiu at 0x19cde4 writes a register its branch at 0x19cde0 reads
 *   delay: addiu at 0x19cdf8 writes a register its branch at 0x19cdf4 reads
 *   delay: addiu at 0x19ce0c writes a register its branch at 0x19ce08 reads
 *   delay: addiu at 0x19ce20 writes a register its branch at 0x19ce1c reads
 *   delay: addiu at 0x19ce7c writes a register its branch at 0x19ce78 reads
 *   delay: addiu at 0x19cf9c writes a register its branch at 0x19cf98 reads
 *   delay: addiu at 0x19d05c writes a register its branch at 0x19d058 reads
 *   delay: addiu at 0x19d12c writes a register its branch at 0x19d128 reads
 *   delay: addiu at 0x19d1a0 writes a register its branch at 0x19d19c reads
 *   delay: addiu at 0x19d20c writes a register its branch at 0x19d208 reads
 *   delay: addiu at 0x19d2d4 writes a register its branch at 0x19d2d0 reads
 *   cfg: kept branch: 0x19ce4c if (..) goto .L0019CE60
 *   cfg: kept branch: 0x19ce60 if (..) goto .L0019D350
 *   cfg: kept branch: 0x19cea0 if (..) goto .L0019D350
 *   cfg: kept branch: 0x19ceb4 if (..) goto .L0019CEE8
 *   cfg: kept branch: 0x19cee8 if (..) goto .L0019CF48
 *   cfg: kept branch: 0x19cef4 if (..) goto .L0019CFD0
 *   cfg: kept branch: 0x19cf18 if (..) goto .L0019CFD0
 *   cfg: kept branch: 0x19cf70 if (..) goto .L0019CF80
 *   cfg: kept branch: 0x19cf80 if (..) goto .L0019D350
 *   cfg: kept branch: 0x19cfc0 if (..) goto .L0019D350
 *   cfg: kept branch: 0x19d030 if (..) goto .L0019D040
 *   cfg: kept branch: 0x19d040 if (..) goto .L0019D350
 *   cfg: kept branch: 0x19d080 if (..) goto .L0019D350
 *   cfg: kept branch: 0x19d094 if (..) goto .L0019D0C8
 *   cfg: kept branch: 0x19d0fc if (..) goto .L0019D110
 *   cfg: kept branch: 0x19d110 if (..) goto .L0019D350
 *   cfg: kept branch: 0x19d150 if (..) goto .L0019D350
 *   cfg: kept branch: 0x19d164 if (..) goto .L0019D198
 *   cfg: kept branch: 0x19d1e0 if (..) goto .L0019D1F0
 *   cfg: kept branch: 0x19d1f0 if (..) goto .L0019D350
 *   cfg: kept branch: 0x19d230 if (..) goto .L0019D350
 *   cfg: kept branch: 0x19d244 if (..) goto .L0019D278
 *   cfg: kept branch: 0x19d2a8 if (..) goto .L0019D2B8
 *   cfg: kept branch: 0x19d2b8 if (..) goto .L0019D350
 *   cfg: kept branch: 0x19d2f8 if (..) goto .L0019D350
 */

static void MakeSaveData(signed int);

static signed int MCProcSaveData(void) {
    u32 t0;
    u32 a3;
    u32 a2;
    u32 a1;
    u8 *s0;
    u32 a0;
    u32 v1;
    u32 v0;

    v0 = 0x13;
    a1 = lpMCMng;
    v1 = *(u8 *)((a1 + 1));
    switch (v1) {
    case 1:
        a0 = *(u8 *)((a1 + 2));
        a1 = *(u8 *)((a1 + 3));
        v0 = fsmc_GetFileInfo(a0, a1);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019CE60;
            }
            v0 = -1;
            break;
            _L0019CE60:;
            v1 = lpMCMng;
            v0 = (u32)(*(u8 *)((v1 + 5))) + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019D350;
            }
            return -1;
        }
        v1 = 2;
        *(u8 *)((lpMCMng + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 2:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019D350;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        v1 = *(u8 *)(s0 + 2);
        *(u8 *)(((u32)(s32)((u8 *)v1 + (u32)(s0)) + 6)) = v0;
        a1 = lpMCMng;
        a0 = *(u8 *)((a1 + 2));
        if (*(u8 *)(((s32)(a0 + a1) + 6)) == 0) {
            goto _L0019CEE8;
        }
        v0 = -1;
        break;
        _L0019CEE8:;
        if ((u32)MCLoadListNum == 0) {
            goto _L0019CF48;
        }
        v1 = (u32)*(u8 *)((a1 + 4)) << 3;
        if (*(u8 *)(s32)((u8 *)(u8 *)(SaveSys + 0x10) + v1) != 0) {
            goto _L0019CFD0;
        }
        a1 = *(u8 *)((a1 + 3));
        v0 = fsmc_GetFreeMemory(a0, a1);
        if ((s32)v0 > (s32)1) {
            goto _L0019CFD0;
        }
        a1 = lpMCMng;
        a0 = 0x1f;
        v0 = -1;
        v1 = *(u8 *)((a1 + 2));
        *(u8 *)(((u32)(v1 + a1) + 6)) = a0;
        break;
        _L0019CF48:;
        v0 = 0xa;
        *(u8 *)((a1 + 1)) = v0;
    case 10:
        v0 = lpMCMng;
        a0 = *(u8 *)((v0 + 2));
        a1 = *(u8 *)((v0 + 3));
        a2 = (u32)"/BASLUS-21007-KUON";
        v0 = fsmc_MkDir(a0, a1, "/BASLUS-21007-KUON");
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019CF80;
            }
            v0 = -1;
            break;
            _L0019CF80:;
            v1 = lpMCMng;
            v0 = (u32)(*(u8 *)((v1 + 5))) + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019D350;
            }
            return -1;
        }
        v1 = 0xb;
        *(u8 *)((lpMCMng + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 11:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019D350;
        }
        _L0019CFD0:;
        a0 = *(u8 *)((lpMCMng + 4));
        MakeSaveData(a0);
        v0 = lpMCMng;
        v1 = 0xe;
        *(u8 *)((v0 + 1)) = v1;
    case 14:
        v0 = lpMCMng;
        a0 = (u32)FileName;
        a2 = *(u8 *)((v0 + 4));
        a1 = (u32)"/BASLUS-21007-KUON/BASLUS-21007-KUON%02d";
        sprintf((void *)FileName, (void *)"/BASLUS-21007-KUON/BASLUS-21007-KUON%02d", a2);
        v0 = lpMCMng;
        a2 = (u32)FileName;
        a3 = (u32)SaveData;
        a0 = *(u8 *)((v0 + 2));
        a1 = *(u8 *)((v0 + 3));
        t0 = 0x320;
        v0 = fsmc_DataWrite(a0, a1, (char *)FileName, (void *)SaveData, t0);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019D040;
            }
            v0 = -1;
            break;
            _L0019D040:;
            v1 = lpMCMng;
            v0 = (u32)(*(u8 *)((v1 + 5))) + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019D350;
            }
            return -1;
        }
        v1 = 0xf;
        *(u8 *)((lpMCMng + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 15:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019D350;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        a0 = *(u8 *)(s0 + 2);
        v1 = 0x3e;
        *(u8 *)(((u32)(s32)((u8 *)a0 + (u32)(s0)) + 6)) = v0;
        a0 = lpMCMng;
        if ((u32)*(u8 *)(((s32)((u32)(*(u8 *)((a0 + 2))) + a0) + 6)) == v1) {
            goto _L0019D0C8;
        }
        v0 = -1;
        break;
        _L0019D0C8:;
        v0 = 0xc;
        *(u8 *)((a0 + 1)) = v0;
    case 12:
        v0 = lpMCMng;
        a2 = (u32)"/BASLUS-21007-KUON/BASLUS-21007-KUON";
        a3 = (u32)SaveSys;
        a0 = *(u8 *)((v0 + 2));
        a1 = *(u8 *)((v0 + 3));
        t0 = 0x50;
        v0 = fsmc_DataWrite(a0, a1, "/BASLUS-21007-KUON/BASLUS-21007-KUON", (void *)SaveSys, t0);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019D110;
            }
            v0 = -1;
            break;
            _L0019D110:;
            v1 = lpMCMng;
            v0 = (u32)(*(u8 *)((v1 + 5))) + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019D350;
            }
            return -1;
        }
        v1 = 0xd;
        *(u8 *)((lpMCMng + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 13:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019D350;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        a0 = *(u8 *)(s0 + 2);
        v1 = 0x3e;
        *(u8 *)(((u32)(s32)((u8 *)a0 + (u32)(s0)) + 6)) = v0;
        a0 = lpMCMng;
        if ((u32)*(u8 *)(((s32)((u32)(*(u8 *)((a0 + 2))) + a0) + 6)) == v1) {
            goto _L0019D198;
        }
        v0 = -1;
        break;
        _L0019D198:;
        v0 = MCLoadListNum;
        if (v0 != 0) {
            v0 = 1;
            return v0;
        }
        v0 = 0x10;
        *(u8 *)((a0 + 1)) = v0;
    case 16:
        v0 = lpMCMng;
        a0 = *(u8 *)((v0 + 2));
        a1 = *(u8 *)((v0 + 3));
        a3 = *(s32 *)((v0 + 0x10));
        t0 = *(s32 *)((v0 + 0x1c));
        a2 = (u32)"/BASLUS-21007-KUON/view.ico";
        v0 = fsmc_IconWrite(a0, a1, "/BASLUS-21007-KUON/view.ico", (void *)a3, t0);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019D1F0;
            }
            v0 = -1;
            break;
            _L0019D1F0:;
            v1 = lpMCMng;
            v0 = (u32)(*(u8 *)((v1 + 5))) + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019D350;
            }
            return -1;
        }
        v1 = 0x11;
        *(u8 *)((lpMCMng + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 17:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019D350;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        a0 = *(u8 *)(s0 + 2);
        v1 = 0x3e;
        *(u8 *)(((u32)(s32)((u8 *)a0 + (u32)(s0)) + 6)) = v0;
        a0 = lpMCMng;
        if ((u32)*(u8 *)(((s32)((u32)(*(u8 *)((a0 + 2))) + a0) + 6)) == v1) {
            goto _L0019D278;
        }
        v0 = -1;
        break;
        _L0019D278:;
        v0 = 0x12;
        *(u8 *)((a0 + 1)) = v0;
    case 18:
        v0 = lpMCMng;
        t0 = 0x3c4;
        a0 = *(u8 *)((v0 + 2));
        a1 = *(u8 *)((v0 + 3));
        a3 = *(s32 *)((v0 + 0xc));
        a2 = (u32)"/BASLUS-21007-KUON/icon.sys";
        v0 = fsmc_IconWrite(a0, a1, "/BASLUS-21007-KUON/icon.sys", (void *)a3, t0);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019D2B8;
            }
            v0 = -1;
            break;
            _L0019D2B8:;
            v1 = lpMCMng;
            v0 = (u32)(*(u8 *)((v1 + 5))) + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019D350;
            }
            return -1;
        }
        v1 = 0x13;
        *(u8 *)((lpMCMng + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 19:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019D350;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        a0 = *(u8 *)(s0 + 2);
        v1 = 0x3e;
        *(u8 *)(((u32)(s32)((u8 *)a0 + (u32)(s0)) + 6)) = v0;
        a0 = lpMCMng;
        v0 = *(u8 *)(((s32)((u32)(*(u8 *)((a0 + 2))) + a0) + 6));
        if (v0 != v1) {
            v0 = -1;
            break;
        } else {
            v0 = 1;
            MCLoadListNum = v0;
            break;
        }
    default:
        _L0019D350:;
        v0 = 0;
    }
    return v0;
}




/* MCProcSaveHeader @ 0x19C8B0 .. 0x19CDA0 (0x4f0 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @1394 is the string '/BASLUS-21007-KUON'
 *   literal: @1395 is the string '/BASLUS-21007-KUON/BASLUS-21007-KUON'
 *   literal: @1396 is the string '/BASLUS-21007-KUON/view.ico'
 *   literal: @1397 is the string '/BASLUS-21007-KUON/icon.sys'
 *   delay: addiu at 0x19c8cc writes a register its branch at 0x19c8c8 reads
 *   delay: addiu at 0x19c8e0 writes a register its branch at 0x19c8dc reads
 *   delay: addiu at 0x19c8f4 writes a register its branch at 0x19c8f0 reads
 *   delay: addiu at 0x19c908 writes a register its branch at 0x19c904 reads
 *   delay: addiu at 0x19c91c writes a register its branch at 0x19c918 reads
 *   delay: addiu at 0x19c974 writes a register its branch at 0x19c970 reads
 *   delay: addiu at 0x19c9e8 writes a register its branch at 0x19c9e4 reads
 *   delay: addiu at 0x19ca3c writes a register its branch at 0x19ca38 reads
 *   delay: addiu at 0x19cb64 writes a register its branch at 0x19cb60 reads
 *   delay: addiu at 0x19cbd8 writes a register its branch at 0x19cbd4 reads
 *   delay: addiu at 0x19cc44 writes a register its branch at 0x19cc40 reads
 *   delay: addiu at 0x19cd0c writes a register its branch at 0x19cd08 reads
 *   cfg: kept branch: 0x19c944 if (..) goto .L0019C958
 *   cfg: kept branch: 0x19c958 if (..) goto .L0019CD88
 *   cfg: kept branch: 0x19c998 if (..) goto .L0019CD88
 *   cfg: kept branch: 0x19c9ac if (..) goto .L0019C9E0
 *   cfg: kept branch: 0x19c9e0 if (..) goto .L0019CA70
 *   cfg: kept branch: 0x19ca10 if (..) goto .L0019CA20
 *   cfg: kept branch: 0x19ca20 if (..) goto .L0019CD88
 *   cfg: kept branch: 0x19ca60 if (..) goto .L0019CD88
 *   cfg: kept branch: 0x19cb34 if (..) goto .L0019CB48
 *   cfg: kept branch: 0x19cb48 if (..) goto .L0019CD88
 *   cfg: kept branch: 0x19cb88 if (..) goto .L0019CD88
 *   cfg: kept branch: 0x19cb9c if (..) goto .L0019CBD0
 *   cfg: kept branch: 0x19cc18 if (..) goto .L0019CC28
 *   cfg: kept branch: 0x19cc28 if (..) goto .L0019CD88
 *   cfg: kept branch: 0x19cc68 if (..) goto .L0019CD88
 *   cfg: kept branch: 0x19cc7c if (..) goto .L0019CCB0
 *   cfg: kept branch: 0x19cce0 if (..) goto .L0019CCF0
 *   cfg: kept branch: 0x19ccf0 if (..) goto .L0019CD88
 *   cfg: kept branch: 0x19cd30 if (..) goto .L0019CD88
 */


static signed int MCProcSaveHeader(void) {
    u32 t1;
    u32 t0;
    u32 a3;
    u32 a2;
    u8 *s0;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;

    v0 = 0x13;
    a1 = lpMCMng;
    v1 = *(u8 *)((a1 + 1));
    switch (v1) {
    case 1:
        a0 = *(u8 *)((a1 + 2));
        a1 = *(u8 *)((a1 + 3));
        v0 = fsmc_GetFileInfo(a0, a1);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019C958;
            }
            v0 = -1;
            break;
            _L0019C958:;
            v1 = lpMCMng;
            v0 = *(u8 *)((v1 + 5));
            v0 = v0 + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019CD88;
            }
            v0 = -1;
            return v0;
        }
        v0 = lpMCMng;
        v1 = 2;
        *(u8 *)((v0 + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 2:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019CD88;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        v1 = *(u8 *)(s0 + 2);
        v1 = (s32)((u8 *)v1 + (u32)(s0));
        *(u8 *)((v1 + 6)) = v0;
        v1 = lpMCMng;
        v0 = *(u8 *)((v1 + 2));
        v0 = v0 + v1;
        v0 = *(u8 *)((v0 + 6));
        if (v0 == 0) {
            goto _L0019C9E0;
        }
        v0 = -1;
        break;
        _L0019C9E0:;
        v0 = MCLoadListNum;
        if (v0 != 0) {
            goto _L0019CA70;
        }
        v0 = 0xa;
        *(u8 *)((v1 + 1)) = v0;
    case 10:
        v0 = lpMCMng;
        a0 = *(u8 *)((v0 + 2));
        a1 = *(u8 *)((v0 + 3));
        a2 = (u32)"/BASLUS-21007-KUON";
        v0 = fsmc_MkDir(a0, a1, "/BASLUS-21007-KUON");
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019CA20;
            }
            v0 = -1;
            break;
            _L0019CA20:;
            v1 = lpMCMng;
            v0 = *(u8 *)((v1 + 5));
            v0 = v0 + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019CD88;
            }
            v0 = -1;
            return v0;
        }
        v0 = lpMCMng;
        v1 = 0xb;
        *(u8 *)((v0 + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 11:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019CD88;
        }
        _L0019CA70:;
        t1 = *(u8 *)SaveSys;
        v1 = 0xc;
        v0 = GameSt[0x28];
        t1 = t1 | v0;
        t0 = SaveSys[1];
        a1 = GameSt[0x29];
        t0 = t0 | a1;
        a3 = SaveSys[2];
        a0 = GameSt[0x2a];
        a3 = a3 | a0;
        a2 = SaveSys[3];
        v0 = GameSt[0x2b];
        a2 = a2 | v0;
        *(u8 *)SaveSys = t1;
        v0 = lpMCMng;
        a1 = SaveSys[4];
        SaveSys[1] = t0;
        a0 = GameSt[0x22];
        a0 = a1 | (u32)a0;
        SaveSys[2] = a3;
        SaveSys[3] = a2;
        SaveSys[4] = a0;
        *(u8 *)((v0 + 1)) = v1;
    case 12:
        v0 = lpMCMng;
        a2 = (u32)"/BASLUS-21007-KUON/BASLUS-21007-KUON";
        a3 = (u32)SaveSys;
        a0 = *(u8 *)((v0 + 2));
        a1 = *(u8 *)((v0 + 3));
        t0 = 0x50;
        v0 = fsmc_DataWrite(a0, a1, "/BASLUS-21007-KUON/BASLUS-21007-KUON", (void *)SaveSys, t0);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019CB48;
            }
            v0 = -1;
            break;
            _L0019CB48:;
            v1 = lpMCMng;
            v0 = *(u8 *)((v1 + 5));
            v0 = v0 + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019CD88;
            }
            v0 = -1;
            return v0;
        }
        v0 = lpMCMng;
        v1 = 0xd;
        *(u8 *)((v0 + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 13:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019CD88;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        a0 = *(u8 *)(s0 + 2);
        v1 = 0x3e;
        a0 = (s32)((u8 *)a0 + (u32)(s0));
        *(u8 *)((a0 + 6)) = v0;
        a0 = lpMCMng;
        v0 = *(u8 *)((a0 + 2));
        v0 = v0 + a0;
        v0 = *(u8 *)((v0 + 6));
        if (v0 == v1) {
            goto _L0019CBD0;
        }
        v0 = -1;
        break;
        _L0019CBD0:;
        v0 = MCLoadListNum;
        if (v0 != 0) {
            v0 = 1;
            return v0;
        }
        v0 = 0x10;
        *(u8 *)((a0 + 1)) = v0;
    case 16:
        v0 = lpMCMng;
        a0 = *(u8 *)((v0 + 2));
        a1 = *(u8 *)((v0 + 3));
        a3 = *(s32 *)((v0 + 0x10));
        t0 = *(s32 *)((v0 + 0x1c));
        a2 = (u32)"/BASLUS-21007-KUON/view.ico";
        v0 = fsmc_IconWrite(a0, a1, "/BASLUS-21007-KUON/view.ico", (void *)a3, t0);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019CC28;
            }
            v0 = -1;
            break;
            _L0019CC28:;
            v1 = lpMCMng;
            v0 = *(u8 *)((v1 + 5));
            v0 = v0 + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019CD88;
            }
            v0 = -1;
            return v0;
        }
        v0 = lpMCMng;
        v1 = 0x11;
        *(u8 *)((v0 + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 17:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019CD88;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        a0 = *(u8 *)(s0 + 2);
        v1 = 0x3e;
        a0 = (s32)((u8 *)a0 + (u32)(s0));
        *(u8 *)((a0 + 6)) = v0;
        a0 = lpMCMng;
        v0 = *(u8 *)((a0 + 2));
        v0 = v0 + a0;
        v0 = *(u8 *)((v0 + 6));
        if (v0 == v1) {
            goto _L0019CCB0;
        }
        v0 = -1;
        break;
        _L0019CCB0:;
        v0 = 0x12;
        *(u8 *)((a0 + 1)) = v0;
    case 18:
        v0 = lpMCMng;
        t0 = 0x3c4;
        a0 = *(u8 *)((v0 + 2));
        a1 = *(u8 *)((v0 + 3));
        a3 = *(s32 *)((v0 + 0xc));
        a2 = (u32)"/BASLUS-21007-KUON/icon.sys";
        v0 = fsmc_IconWrite(a0, a1, "/BASLUS-21007-KUON/icon.sys", (void *)a3, t0);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019CCF0;
            }
            v0 = -1;
            break;
            _L0019CCF0:;
            v1 = lpMCMng;
            v0 = *(u8 *)((v1 + 5));
            v0 = v0 + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                goto _L0019CD88;
            }
            v0 = -1;
            return v0;
        }
        v0 = lpMCMng;
        v1 = 0x13;
        *(u8 *)((v0 + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 19:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            goto _L0019CD88;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        a0 = *(u8 *)(s0 + 2);
        v1 = 0x3e;
        a0 = (s32)((u8 *)a0 + (u32)(s0));
        *(u8 *)((a0 + 6)) = v0;
        a0 = lpMCMng;
        v0 = *(u8 *)((a0 + 2));
        v0 = v0 + a0;
        v0 = *(u8 *)((v0 + 6));
        if (v0 != v1) {
            v0 = -1;
            break;
        } else {
            v0 = 1;
            MCLoadListNum = v0;
            break;
        }
    default:
        _L0019CD88:;
        v0 = 0;
    }
    return v0;
}

/* MCProcFormat @ 0x19C6C0 .. 0x19C8A8 (0x1e8 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x19c6dc writes a register its branch at 0x19c6d8 reads
 *   delay: addiu at 0x19c6f0 writes a register its branch at 0x19c6ec reads
 *   delay: addiu at 0x19c74c writes a register its branch at 0x19c748 reads
 *   delay: addiu at 0x19c7b4 writes a register its branch at 0x19c7b0 reads
 *   delay: addiu at 0x19c814 writes a register its branch at 0x19c810 reads
 *   cfg: kept branch: 0x19c71c if (..) goto .L0019C730
 *   cfg: kept goto: 0x19c728 -> .L0019C898
 *   cfg: kept branch: 0x19c784 if (..) goto .L0019C7C8
 *   cfg: kept branch: 0x19c7ac if (..) goto .L0019C7C8
 *   cfg: kept branch: 0x19c7b4 if (..) goto .L0019C7C8
 *   cfg: kept goto: 0x19c7c4 -> .L0019C898
 *   cfg: kept branch: 0x19c7e8 if (..) goto .L0019C7F8
 *   cfg: kept goto: 0x19c7f4 -> .L0019C898
 */



static u32 MCProcFormat(void) {
    u32 v0;
    u32 a1;
    u32 v1;
    u32 a0;
    u8 *s0;

    v0 = 0x15;
    a1 = lpMCMng;
    v1 = *(u8 *)((a1 + 1));
    switch (v1) {
    case 1:
        a0 = *(u8 *)((a1 + 2));
        a1 = *(u8 *)((a1 + 3));
        v0 = fsmc_GetFileInfo(a0, a1);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019C730;
            }
            v0 = -1;
            goto _L0019C898;
            _L0019C730:;
            v1 = lpMCMng;
            v0 = *(u8 *)((v1 + 5));
            v0 = v0 + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                break;
            }
            v0 = -1;
            return v0;
        }
        v0 = lpMCMng;
        v1 = 2;
        *(u8 *)((v0 + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 2:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            break;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        v1 = *(u8 *)(((u8 *)s0 + 2));
        v1 = (s32)((u8 *)v1 + (u32)(s0));
        *(u8 *)((v1 + 6)) = v0;
        a0 = lpMCMng;
        v0 = *(u8 *)((a0 + 2));
        v0 = v0 + a0;
        v1 = *(u8 *)((v0 + 6));
        if (v1 == 0) {
            goto _L0019C7C8;
        }
        v0 = 3;
        if (v1 == v0) {
            goto _L0019C7C8;
        }
        v0 = 4;
        if (v1 == v0) {
            goto _L0019C7C8;
        }
        v0 = -1;
        goto _L0019C898;
        _L0019C7C8:;
        v0 = 0x14;
        *(u8 *)((a0 + 1)) = v0;
    case 20:
        v0 = lpMCMng;
        a1 = *(u8 *)((v0 + 3));
        a0 = *(u8 *)((v0 + 2));
        v0 = fsmc_Format(a0, a1);
        if (v0 != 0) {
            if ((s32)v0 >= 0) {
                goto _L0019C7F8;
            }
            v0 = -1;
            goto _L0019C898;
            _L0019C7F8:;
            v1 = lpMCMng;
            v0 = *(u8 *)((v1 + 5));
            v0 = v0 + 1;
            *(u8 *)((v1 + 5)) = v0;
            v0 = (u8)v0;
            v0 = (s32)v0 < (s32)0xa;
            if (v0 != 0) {
                break;
            }
            v0 = -1;
            return v0;
        }
        v0 = lpMCMng;
        v1 = 0x15;
        *(u8 *)((v0 + 1)) = v1;
        v0 = lpMCMng;
        *(u8 *)((v0 + 5)) = 0;
    case 21:
        v0 = fsmc_FuncCheck();
        if ((s32)v0 > 0) {
            break;
        }
        s0 = (u8 *)lpMCMng;
        v0 = fsmc_MessageCheck();
        a0 = *(u8 *)(((u8 *)s0 + 2));
        v1 = 0x34;
        a0 = (s32)((u8 *)a0 + (u32)(s0));
        *(u8 *)((a0 + 6)) = v0;
        a0 = lpMCMng;
        v0 = *(u8 *)((a0 + 2));
        v0 = v0 + a0;
        v0 = *(u8 *)((v0 + 6));
        if (v0 != v1) {
            v0 = -1;
        } else {
            v0 = 1;
        }
        return v0;
    }
    v0 = 0;
    _L0019C898:;
    return v0;
}








/* GetMemoryCardMessage @ 0x19C6A0 .. 0x19C6B4 (0x14 bytes) */
/*
 * dcomp notes:
 *   return: lbu at 0x19c6b0 computes the return value
 *   declaration vs inferred signature: return signed int vs inferred u8
 */




signed int GetMemoryCardMessage(unsigned char a0 /* r4 */) {
    u8 *v1;

    v1 = (u8 *)lpMCMng;
    return (v1 + a0)[6];
}








/* GetSaveDataHeader @ 0x19C680 .. 0x19C698 (0x18 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x19c694 computes the return value
 */


u32 GetSaveDataHeader(s32 a0 /* r4 */) {
    u32 v0;

    v0 = (u32)SaveSys;
    return (u32)((u8 *)SaveSys + (u32)((u32)a0 << 3)) + 0x10;
}

/* GetSaveSystem @ 0x19C670 .. 0x19C67C (0xc bytes) */


u8 * GetSaveSystem(void) {
    return (u8 *)SaveSys;
}

/* GetSaveData @ 0x19C660 .. 0x19C66C (0xc bytes) */


u8 * GetSaveData(void) {
    return (u8 *)SaveData;
}

/* GetNeedCluster @ 0x19C610 .. 0x19C660 (0x50 bytes) */
/*
 * dcomp notes:
 *   cfg: kept goto: 0x19c630 -> .L0019C658
 *   cfg: kept goto: 0x19c648 -> .L0019C658
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int GetNeedCluster(signed int a0 /* r4 */) {
    u32 v0;

    v0 = 1;
    switch ((u32)(s32)a0) {
    case 0:
        v0 = lpMCMng;
        v0 = *(s32 *)((v0 + 0x1c));
        v0 = v0 + 0x3ff;
        v0 = (u32)(v0) >> 0xa;
        v0 = v0 + 7;
        return v0;
    case 1:
        v0 = 2;
        return v0;
    }
    return (u32)0;
}

/* ExistKuonData @ 0x19C600 .. 0x19C608 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x19c604 computes the return value
 */


u32 ExistKuonData(void) {
    return MCLoadListNum;
}

/* ExistSaveData @ 0x19C5E0 .. 0x19C5F8 (0x18 bytes) */
/*
 * dcomp notes:
 *   return: lbu at 0x19c5f4 computes the return value
 *   declaration vs inferred signature: return signed int vs inferred u8
 */


signed int ExistSaveData(signed int a0 /* r4 */) {
    u8 *v0;

    v0 = (u8 *)SaveSys + 0x10;
    return *(u8 *)(u8 *)(s32)((u8 *)v0 + (s32)((u32)a0 << 3));
}


extern void SetVagMasterVolume(unsigned char, unsigned short);
extern void SND_SqSetVolume(signed int);
extern void SND_SetVol(int, unsigned char);
extern void *memcpy(void *, const void *, unsigned int);
extern void ItemMng_SetCollectData(void *);
extern u32 g_pSndMng;
extern u32 GameEventFlag[];
static void CopyLoadData(signed int slot) {
    GameSt[0x28] = SaveSys[0];
    GameSt[0x29] = SaveSys[1];
    GameSt[0x2a] = SaveSys[2];
    GameSt[0x2b] = SaveSys[3];
    GameSt[0x22] |= SaveSys[4];
    GameSt[0x16] = SaveSys[5];
    GameSt[0x15] = SaveSys[6];
    GameSt[0x1e] = *(s8 *)(SaveSys + 7);
    SetVagMasterVolume(0, *(u16 *)(SaveSys + 8));
    SetVagMasterVolume(1, *(u16 *)(SaveSys + 10));
    SND_SqSetVolume((s32)(*(u16 *)(SaveSys + 8) * 255) / 0x3fff);
    SND_SetVol(3, SaveSys[12]);
    *(u8 *)(g_pSndMng + 0x2c) = SaveSys[13];
    GameSt[0x2c] = SaveSys[14];
    GameSt[0x14] = SaveSys[0x11 + slot * 8];
    *(u32 *)GameSt = *(u32 *)((u32)(SaveSys + 0x14) + slot * 8);
    GameSt[0x18] = SaveSys[0x13 + slot * 8];
    GameSt[0x1a] = SaveData[0x1d];
    memcpy(GameEventFlag, SaveData + 0x20, 0x100);
    ItemMng_SetCollectData(SaveData + 0x120);
}


/* MakeSaveData @ 0x19C110 .. 0x19C420 (0x310 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0019C278
 *   cfg: kept branch: 0x19c278 if (..) goto .L0019C290
 *   cfg: kept goto: 0x19c284 -> .L0019C2A8
 */

extern unsigned short GetVagMasterVolume(unsigned char);
extern unsigned char SND_GetVol(int);
extern u32 GetCurCamID();
extern void * GetMyEquip(void *, signed int);
extern unsigned char GetMyWeaponId(void *);
extern u32 ItemMng_GetCollectData();
extern struct dw_1480268_fields MdlMng[];
struct MsdEquip { u8 type; u8 pad[3]; s32 id; s32 pad2; };

struct dw_1480268_fields;
struct dw_1493384_fields;
#ifndef PROTO_DW_1490893_FIELDS
#define PROTO_DW_1490893_FIELDS
struct dw_1490893_fields { unsigned char Use; unsigned char Player; unsigned char Map; unsigned char Level; unsigned int Time; };
#endif
#ifndef PROTO_DW_1478337_FIELDS
#define PROTO_DW_1478337_FIELDS
struct dw_1478337_fields { unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char Sugoroku; unsigned char KeyConfType; unsigned char PadVib; char Brightness; unsigned short BGMVolume; unsigned short VoiceVolume; unsigned char SEVolume; unsigned char SndMode; unsigned char VoiceLanguage; unsigned char unused; struct dw_1490893_fields SaveDataHeader[8]; };
#endif
#ifndef PROTO_DW_1490647_FIELDS
#define PROTO_DW_1490647_FIELDS
struct dw_1490647_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_1486319_FIELDS
#define PROTO_DW_1486319_FIELDS
struct dw_1486319_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_1485961_FIELDS
#define PROTO_DW_1485961_FIELDS
struct dw_1485961_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_1480268_fields *lpMdl; };
#endif
#ifndef PROTO_DW_1480268_FIELDS
#define PROTO_DW_1480268_FIELDS
struct dw_1480268_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_1493384_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_1480268_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_1490647_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_1486319_fields flags; unsigned char _pad1[3]; struct dw_1485961_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_1493202_FIELDS
#define PROTO_DW_1493202_FIELDS
struct dw_1493202_fields { float (*fvListenerPosPtr)[4]; float (*fvListenerAngPtr)[4]; float (*fmListenerMatPtr)[4][4]; };
#endif
#ifndef PROTO_DW_1492206_FIELDS
#define PROTO_DW_1492206_FIELDS
struct dw_1492206_fields { float panlim; float zofs; char dopp; char pad[3]; float range; char reserved[16]; };
#endif
#ifndef PROTO_DW_1486449_FIELDS
#define PROTO_DW_1486449_FIELDS
struct dw_1486449_fields { short sCalcedVol; char bid; char sid; char PlayId; char reserv[3]; int sq_fade; int sq_vol; };
#endif
#ifndef PROTO_DW_1490510_FIELDS
#define PROTO_DW_1490510_FIELDS
struct dw_1490510_fields { unsigned short usFreq; unsigned char ucLoop; char cDmy[1]; };
#endif
#ifndef PROTO_DW_1491781_FIELDS
#define PROTO_DW_1491781_FIELDS
struct dw_1491781_fields { unsigned int uiProgNum; char cDmy[12]; struct dw_1490510_fields aParam[128]; };
#endif
#ifndef PROTO_DW_1482986_FIELDS
#define PROTO_DW_1482986_FIELDS
struct dw_1482986_fields { struct dw_1493202_fields Listener; struct dw_1492206_fields Param; signed char SndMode; unsigned char bfMasterVolume : 1; unsigned char bfReserv : 7; unsigned char ucMasterVolume; unsigned char ucBgmVolume; unsigned char ucSqVolume; unsigned char ucSeVolume; unsigned short usVolumeFadeOutFrame; char rid[8]; unsigned short ucVoiceCnt; unsigned char _pad0[2]; int Handle[12]; struct dw_1486449_fields aSqSong[4]; unsigned char calloff; unsigned char _pad1[3]; struct dw_1491781_fields aBankInfo[12]; unsigned short aaIdTable[12][128]; unsigned int uiUseVoiceNum; };
#endif
#ifndef PROTO_DW_1479578_FIELDS
#define PROTO_DW_1479578_FIELDS
struct dw_1479578_fields { float Position[3]; float Angle; unsigned char SceneNo; unsigned char CameraNo; unsigned char EquipType[3]; unsigned char EquipId[3]; unsigned char WepId; unsigned char Hp; unsigned char HeartBeat; unsigned char Clear; unsigned char NineHitNum; unsigned char Penance; unsigned char unused[2]; };
#endif
#ifndef PROTO_DW_1484908_FIELDS
#define PROTO_DW_1484908_FIELDS
struct dw_1484908_fields { struct dw_1479578_fields PlayerInfo; unsigned char GameEventFlag[256]; unsigned char ItemData[512]; };
#endif
#ifndef PROTO_DW_1488509_FIELDS
#define PROTO_DW_1488509_FIELDS
struct dw_1488509_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#define SS (*(struct dw_1478337_fields *)SaveSys)
#define GS (*(struct dw_1488509_fields *)GameSt)
#define SD (*(struct dw_1484908_fields *)SaveData)
static inline u8 MsdFindPoint(u8 id) {
    int i;

    for (i = 0; i < 0x14; i++) {
        u8 t = ((u8 *)SavePointID)[i];
        if (t == id) {
            return i;
        }
    }
    return 0xc8;
}

static void MakeSaveData(signed int Index) {
    struct dw_1480268_fields *lpMy;
    void *lpMyCtrl;
    struct MsdEquip *lpEquip;

    u8 scene;

    SS.ClearCount[0] |= GS.ClearCount[0];
    SS.ClearCount[1] |= GS.ClearCount[1];
    SS.ClearCount[2] |= GS.ClearCount[2];
    SS.ExtraClear |= GS.ExtraClear;
    SS.Sugoroku |= GS.Sugoroku;
    SS.KeyConfType = GS.KeyConfType;
    SS.PadVib = GS.PadVib;
    SS.Brightness = GS.Brightness;
    SS.BGMVolume = GetVagMasterVolume(0);
    SS.VoiceVolume = GetVagMasterVolume(1);
    SS.SEVolume = SND_GetVol(3);
    SS.SndMode = *(u8 *)(g_pSndMng + 0x2c);
    SS.VoiceLanguage = GS.VoiceLanguage;
    (SaveSys + 0x10)[Index * 8] = 1;
    (SaveSys + 0x11)[Index * 8] = GS.PlayerId;
    scene = GameSt[9];
    (SaveSys + 0x12)[Index * 8] = MsdFindPoint(scene);
    (SaveSys + 0x13)[Index * 8] = GS.GameLevel;
    ((u32 *)(SaveSys + 0x14))[Index * 2] = GS.SystemCounter;
    memset(SaveData, 0, 0x320);
    SD.PlayerInfo.Penance = GS.PenanceMode;
    SD.PlayerInfo.SceneNo = GS.sceneNo;
    SD.PlayerInfo.CameraNo = GetCurCamID();
    lpMy = &MdlMng[160];
    lpMyCtrl = lpMy->lpCtrlSt;
    lpEquip = (struct MsdEquip *)GetMyEquip(lpMy, 0);
    SD.PlayerInfo.Position[0] = lpMy->Pos[0];
    SD.PlayerInfo.Position[1] = lpMy->Pos[1];
    SD.PlayerInfo.Position[2] = lpMy->Pos[2];
    SD.PlayerInfo.Angle = lpMy->Ang[1];
    SD.PlayerInfo.EquipType[0] = lpEquip[0].type;
    SD.PlayerInfo.EquipId[0] = lpEquip[0].id;
    SD.PlayerInfo.EquipType[1] = lpEquip[1].type;
    SD.PlayerInfo.EquipId[1] = lpEquip[1].id;
    SD.PlayerInfo.WepId = GetMyWeaponId(lpMy);
    SD.PlayerInfo.Hp = lpMy->Hp;
    SD.PlayerInfo.HeartBeat = *(s32 *)((u8 *)lpMyCtrl + 0x1a0);
    SD.PlayerInfo.NineHitNum = GS.NineHitNum;
    memcpy(SD.GameEventFlag, GameEventFlag, 0x100);
    memcpy(SD.ItemData, (void *)ItemMng_GetCollectData(), 0x200);
}
#undef SS
#undef GS
#undef SD












/* InitSavePointID @ 0x19C070 .. 0x19C10C (0x9c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0019C090
 */

extern unsigned short * KnMsgMng_GetMsgStr(signed int);


void InitSavePointID(void) {
    unsigned short *lpMsg;
    s32 i;
    s32 SceneNo;

    for (i = 0; i < 0x14; i++) {
        if ((lpMsg = KnMsgMng_GetMsgStr(i + 0x1ae14)) != 0) {
            SceneNo = 0;
            while (*lpMsg != 0) {
                SceneNo = SceneNo * 10 + *lpMsg - '0';
                lpMsg++;
            }
            ((u8 *)SavePointID)[i] = SceneNo;
        } else {
            ((u8 *)SavePointID)[i] = 200;
        }
    }
}

static u32 IconSys[0xf1] = {
    0x44325350, 0x100000, 0, 0x6e, 0, 0, 0, 0, 0x68, 0, 0, 0, 0, 0, 0, 0, 0x96, 0, 0, 0,
    0x3f000000, 0x3f000000, 0x3f000000, 0, 0, 0xbecccccd, 0xbdcccccd, 0, 0xbf000000, 0xbf000000,
    0x3f000000, 0, 0x3e4ccccd, 0x3e4ccccd, 0x3e4ccccd, 0, 0x3f000000, 0x3ea8f5c3, 0x3e4ccccd, 0,
    0x3e0f5c29, 0x3e0f5c29, 0x3ec28f5c, 0, 0x3ecccccd, 0x3ecccccd, 0x3ecccccd, 0, 0x6a827c81,
    0x8f829582, 0x7c818e82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x77656976, 0x6f63692e, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x77656976, 0x6f63692e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0x77656976, 0x6f63692e
};


extern u8 MemoryCardMng[];
static u32 lpMCMng = (u32)&MemoryCardMng;

