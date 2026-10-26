#include "common.h"




extern u32 __MCMNG[];
extern u32 __MCMNG[];
extern u32 sceMcInit();
static signed int fsmc_GetFileInfoFunc(void);
extern signed int fsmc_GetDirFunc(void);
extern signed int fsmc_DataWriteFunc(void);
extern signed int fsmc_DataReadFunc(void);
extern signed int fsmc_IconWriteFunc(void);
extern signed int fsmc_IconWriteFileFunc(void);
static u32 fsmc_FormatFunc(void);
static signed int fsmc_ChDirFunc(void);
static signed int fsmc_MkDirFunc(void);
extern signed int fsmc_IconReadFunc(void);
static signed int fsmc_FileChkFunc(void);
static u32 fsmc_UnFormatFunc(void);
extern int sceMcGetDir(int, int, void *, unsigned int, int, void *);
extern int sceMcSync(int, void *, void *);
extern u32 flchk[];
extern int sceMcMkdir(int, int, void *);
extern u32 sceMcChdir(s32, s32, s32, s32);
extern u32 sceMcUnformat(s32, s32);
extern int sceMcFormat(int, int);
static signed int _fsmc_GetInfo(signed int, signed int, signed int *, signed int *, signed int *,
    signed int);
static signed int _fsmc_InfoErrMess(signed int);
extern int sceMcOpen(int, int, void *, int);
static void _fsmc_OpenErrMess(signed int a0 );
extern int sceMcRead(int, void *, int);
extern int sceMcClose(int);
extern u32 fd;
static u32 fd;

static u32 rdofs_787;
static u8 wtsize_671[0x4];
static u8 allsize_670[0x4];
static u8 size_669[0x4];
static u8 src_668[0x4];
static u8 wtsize_560[0x4];
static u8 wtofs_559[0x4];
static u8 allsize_419[0x4];
static u8 wtchk_418[0x4];
static u8 datasize_417[0x4];
static u8 rdofs_416[0x4];
static u8 wsize_255[0x4];
static u8 wtofs_254[0x4];
static u8 allsize_253[0x4];
static u8 s_WkKByte[0x4];
static u8 s_pWkBuff[0x4];
static u32 s_ReadNum;
static u8 s_WriteNum[0x4];
extern int sceMcGetInfo(int, int, void *, void *, void *);
u32 fsmc_MessageCheck(void);
u32 fsmc_GetDirPoints(void);
signed int fsmc_GetFreeMemory(signed int a0 /* r4 */, signed int a1 /* r5 */);
u32 fsmc_Init(void);
signed int fsmc_FuncCheck(void);
signed int fsmc_MkDir(signed int a0 /* r4 */, signed int a1 /* r5 */, char *a2 /* r6 */);
signed int fsmc_Format(signed int a0 /* r4 */, signed int a1 /* r5 */);
signed int fsmc_IconWrite(signed int a0 /* r4 */, signed int a1 /* r5 */, char *a2 /* r6 */, void
        *a3 /* r7 */, unsigned int t0 /* r8 */);
signed int fsmc_DataRead(signed int a0 /* r4 */, signed int a1 /* r5 */, char *a2 /* r6 */, void
        *a3 /* r7 */, unsigned int t0 /* r8 */);
signed int fsmc_DataWrite(signed int a0 /* r4 */, signed int a1 /* r5 */, char *a2 /* r6 */, void
        *a3 /* r7 */, unsigned int t0 /* r8 */);
signed int fsmc_GetDir(signed int a0 /* r4 */, signed int a1 /* r5 */, char *a2 /* r6 */, unsigned
        int a3 /* r7 */, unsigned int t0 /* r8 */, void *t1 /* r9 */);
signed int fsmc_GetFileInfo(signed int a0 /* r4 */, signed int a1 /* r5 */);
signed int fsmc_IconReadFunc(void);
signed int fsmc_GetDirFunc(void);
static void _fsmc_OpenErrMess(signed int a0 /* r4 */);
static signed int _fsmc_GetInfo(signed int port, signed int slot, signed int *type, signed int *free, signed int *format, signed int prno);






static signed int _fsmc_GetInfo(signed int port, signed int slot, signed int *type, signed int *free, signed int *format, signed int prno) {
    int result;

    switch (prno) {
    case 0:
    case 2:
    case 4:
        if (sceMcGetInfo(port, slot, type, free, format) != 0) {
            if (prno == 4) {
                return -100;
            }
            prno += 2;
        } else {
            prno += 1;
        }
        break;
    case 1:
    case 3:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result == 0) {
                prno += 1;
            } else {
                return result;
            }
        }
        break;
    case 5:
        if (sceMcSync(1, 0, &result) != 0) {
            (&__MCMNG[0x18] + port * 4)[slot] = result;
            if (result == 0) {
                return 0;
            }
            return result;
        }
        break;
    }
    return prno;
}






static signed int _fsmc_InfoErrMess(signed int a0) {
    int port = __MCMNG[0x20];
    int slot = __MCMNG[0x21];

    if (a0 >= 0) {
        if ((&__MCMNG[0x10] + port * 4)[slot] == 0) {
            if ((&__MCMNG[0] + port * 4)[slot] == 3) {
                return 1;
            }
            return 3;
        }
        return (&__MCMNG[0] + port * 4)[slot] == 3;
    }
    if (a0 == -1) {
        if ((&__MCMNG[0] + port * 4)[slot] == 3) {
            return 1;
        }
        return 2;
    }
    if (a0 == -2) {
        if ((&__MCMNG[0] + port * 4)[slot] == 3) {
            return 1;
        }
        return 4;
    }
    if (a0 < -10 || a0 == -5) {
        return 1;
    }
    return 0x64;
}


/* _fsmc_OpenErrMess @ 0x146660 .. 0x146718 (0xb8 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x146678 writes a register its branch at 0x146674 reads
 *   delay: addiu at 0x146690 writes a register its branch at 0x14668c reads
 *   delay: addiu at 0x1466a8 writes a register its branch at 0x1466a4 reads
 *   delay: addiu at 0x1466c0 writes a register its branch at 0x1466bc reads
 *   delay: addiu at 0x1466d8 writes a register its branch at 0x1466d4 reads
 *   declaration vs inferred signature: return void vs inferred u32
 */





static void _fsmc_OpenErrMess(signed int a0 /* r4 */) {
    s32 v1;

    if ((s32)a0 >= 0) {
        *(u32 *)((u8 *)&__MCMNG + 0x98) = 0;
    } else {
        v1 = -2;
        if ((u32)(s32)a0 == (u32)v1) {
            *(u32 *)((u8 *)&__MCMNG + 0x98) = 3;
        } else {
            v1 = -3;
            if ((u32)(s32)a0 == (u32)v1) {
                *(u32 *)((u8 *)&__MCMNG + 0x98) = 0x1e;
            } else {
                v1 = -4;
                if ((u32)(s32)a0 == (u32)v1) {
                    *(u32 *)((u8 *)&__MCMNG + 0x98) = 0x64;
                } else {
                    v1 = -5;
                    if ((u32)(s32)a0 == (u32)v1) {
                        *(u32 *)((u8 *)&__MCMNG + 0x98) = 0x64;
                    } else {
                        v1 = -7;
                        if ((u32)(s32)a0 == (u32)v1) {
                            *(u32 *)((u8 *)&__MCMNG + 0x98) = 0x64;
                        } else {
                            v1 = 1;
                            if ((s32)a0 < (s32)-0xa) {
                                *(u32 *)((u8 *)&__MCMNG + 0x98) = v1;
                            } else {
                                *(u32 *)((u8 *)&__MCMNG + 0x98) = 0x64;
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}







extern void * memset(void *, int, unsigned int);
extern void * memcpy(void *, const void *, unsigned int);
extern u8 rddata[];

static unsigned int _fsmc_SetWriteData(unsigned int *pwtofs) {
    int remain;
    int wsiz;
    int wtsiz;
    unsigned char chk;
    unsigned char *pbuff;
    unsigned int buffsize;
    unsigned int wtofs;
    int i;
    int j;
    int num;
    int total;

    total = 0;
    pbuff = (u8 *)*(s32 *)s_pWkBuff;
    if (pbuff != 0) {
        buffsize = *(s32 *)s_WkKByte << 10;
        num = *(s32 *)s_WkKByte - 1;
    } else {
        pbuff = rddata;
        buffsize = 0x420;
        num = 1;
    }
    memset(pbuff, 0, buffsize);
    wtofs = *pwtofs;
    for (i = 0; i < num; i++) {
        remain = __MCMNG[0x2a] - wtofs;
        if (wtofs == 0) {
            if (remain >= 0x3fb) {
                remain = 0x3fb;
            }
            *(u32 *)pbuff = __MCMNG[0x2a];
            wtsiz = 4;
        } else {
            if (remain >= 0x3ff) {
                remain = 0x3ff;
            }
            wtsiz = 0;
        }
        wsiz = remain + wtsiz;
        chk = 0;
        if (remain != 0) {
            memcpy(pbuff + wtsiz, (void *)(__MCMNG[0x2e] + wtofs), remain);
            for (j = 0; j < remain; j++) {
                chk += ~pbuff[wtsiz + j];
            }
            pbuff[wsiz] = chk;
            wsiz++;
        }
        if (wtofs == 0) {
            if (remain <= 0x3fa) {
                pbuff[wsiz] = 1;
                wsiz++;
                wtofs++;
                i = num;
            }
        } else {
            if (remain <= 0x3fe) {
                pbuff[wsiz] = 1;
                wsiz++;
                wtofs++;
                i = num;
            }
        }
        wtofs += remain;
        if ((wsiz & 0x1f) != 0) {
            wsiz = (wsiz & ~0x1f) + 0x20;
        }
        total += wsiz;
        pbuff += wsiz;
    }
    *pwtofs = wtofs;
    return total;
}

















extern void * memcpy(void *, const void *, unsigned int);
extern u8 rddata[];

static signed int _fsmc_GetReadData(signed int *prdofs, signed int datasize) {
    unsigned char chk;
    int remain;
    int readmax;
    unsigned char *pbuff;
    int i;
    int j;
    int num;
    int rdofs;

    pbuff = (u8 *)*(s32 *)s_pWkBuff;
    if (pbuff != 0) {
        num = *(s32 *)s_WkKByte;
    } else {
        pbuff = rddata;
        num = 1;
    }
    rdofs = *prdofs;
    for (i = 0; i < num; i++) {
        readmax = 0x3ff;
        if (rdofs == 0) {
            readmax -= 4;
        }
        remain = datasize - rdofs;
        if (remain > readmax) {
            remain = readmax;
        }
        if (remain != 0) {
            chk = 0;
            for (j = 0; j < remain; j++) {
                chk += ~pbuff[j];
            }
            if (chk != pbuff[remain]) {
                return -1;
            }
            if (__MCMNG[0x2a] < datasize) {
                remain = __MCMNG[0x2a] - rdofs;
            } else {
                remain = datasize - rdofs;
            }
            if (remain > readmax) {
                remain = readmax;
            }
            memcpy((void *)(__MCMNG[0x2d] + rdofs), pbuff, remain);
            if (readmax > remain) {
                return 1;
            }
        }
        rdofs += remain;
        pbuff += remain + 1;
    }
    *prdofs = rdofs;
    return 0;
}


/* fsmc_GetFileInfoFunc @ 0x145F30 .. 0x14612C (0x1fc bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: lui at 0x14605c writes a register its branch at 0x146058 reads
 *   cfg: kept branch: 0x145f98 if (..) goto .L00146000
 *   cfg: kept branch: 0x145fcc if (..) goto .L00145FF0
 *   cfg: kept goto: 0x145fdc -> .L00146118
 *   cfg: kept branch: 0x146030 if (..) goto .L00146088
 *   cfg: kept branch: 0x146054 if (..) goto .L00146070
 *   cfg: kept branch: 0x146060 if (..) goto .L001460B8
 *   cfg: kept goto: 0x146070 -> .L00146118
 *   cfg: kept goto: 0x146088 -> .L00146118
 *   cfg: kept goto: 0x1460f4 -> .L00146118
 */


static signed int fsmc_GetFileInfoFunc(void) {
    int s1;
    int s0;
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u8 stackFrame_3C[4] __attribute__((aligned(4)));

    v0 = 2;
    s1 = *(s32 *)(__MCMNG + 0x20);
    s0 = *(s32 *)(__MCMNG + 0x21);
    v1 = *(s32 *)(__MCMNG + 0x23);
    a0 = 1;
    switch (v1) {
    case 0:
        v0 = v1 + 1;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
    case 1:
        v0 = (u32)__MCMNG;
        v1 = (s32)((u8 *)__MCMNG + (s32)(s1 << 4));
        a0 = s1;
        a1 = s0;
        a2 = (s32)(s0 << 2) + v1;
        v0 = sceMcGetInfo(a0, a1, (void *)a2, (void *)(s32)(a2 + 0x20), (void *)(s32)(a2 + 0x40));
        if (v0 == 0) {
            goto _L00146000;
        }
        v0 = 2;
        v1 = *(s32 *)(__MCMNG + 0x27);
        if (v1 != v0) {
            goto _L00145FF0;
        }
        v1 = 0x64;
        v0 = -0xa;
        __MCMNG[0x26] = v1;
        goto _L00146118;
        _L00145FF0:;
        v0 = v1 + 1;
        __MCMNG[0x27] = v0;
        break;
        _L00146000:;
        v0 = *(s32 *)(__MCMNG + 0x23) + 1;
        __MCMNG[0x23] = v0;
        break;
    case 2:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_3C[0]));
        if (v0 == 0) {
            break;
        }
        a0 = *(s32 *)((u8 *)&stackFrame_3C[0]);
        a1 = s1 << 4;
        v1 = (s32)((u8 *)(u8 *)(__MCMNG + 0x18) + a1);
        v0 = (s32)(s0 << 2) + v1;
        *(u32 *)v0 = a0;
        if ((s32)a0 >= 0) {
            goto _L00146088;
        }
        if ((s32)a0 > (s32)-0xb) {
            goto _L00146070;
        }
        v0 = 2;
        v1 = *(s32 *)(__MCMNG + 0x27);
        if (v1 != v0) {
            goto _L001460B8;
        }
        _L00146070:;
        v0 = _fsmc_InfoErrMess(a0);
        __MCMNG[0x26] = v0;
        v0 = -0xa;
        goto _L00146118;
        _L00146088:;
        __MCMNG[0x22] = 0;
        v0 = _fsmc_InfoErrMess(a0);
        v1 = -0xa;
        __MCMNG[0x26] = v0;
        a0 = *(s32 *)(__MCMNG + 0x26);
        v0 = a0 == 0 ? (s32)1 : (s32)v1;
        goto _L00146118;
        _L001460B8:;
        __MCMNG[0x27] = v1 + 1;
        v0 = *(s32 *)(__MCMNG + 0x23) + -1;
        __MCMNG[0x23] = v0;
        break;
    default:
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_3C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = 0x64;
        __MCMNG[0x22] = 0;
        __MCMNG[0x26] = v0;
        v0 = -0xa;
        return v0;
    }
    v0 = 0;
    _L00146118:;
    return v0;
}


/* fsmc_GetDirFunc @ 0x145D50 .. 0x145F24 (0x1d4 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x145d78 writes a register its branch at 0x145d74 reads
 *   delay: addiu at 0x145e80 writes a register its branch at 0x145e7c reads
 *   cfg: kept goto: 0x145df0 -> .L00145F18
 *   cfg: kept goto: 0x145e50 -> .L00145F18
 *   cfg: kept goto: 0x145ef8 -> .L00145F18
 *   declaration vs inferred signature: return signed int vs inferred u32
 */





signed int fsmc_GetDirFunc(void) {
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u8 stackFrame_1C[4] __attribute__((aligned(4)));

    v0 = 2;
    a0 = __MCMNG[0x20];
    a1 = __MCMNG[0x21];
    v1 = __MCMNG[0x23];
    v0 = 1;
    switch (v1) {
    case 0:
        v0 = v1 + 1;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        break;
    case 1:
        a2 = __MCMNG[0x28];
        v0 = sceMcGetDir(a0, a1, (void *)a2, __MCMNG[0x2a], __MCMNG[0x2b],
            (void *)__MCMNG[0x2c]);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v0 = 0x64;
                __MCMNG[0x22] = 0;
                __MCMNG[0x26] = v0;
                v0 = -1;
                goto _L00145F18;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            break;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 2:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if ((s32)v0 >= 0) {
            __MCMNG[0x22] = 0;
            __MCMNG[0x26] = 0;
            __MCMNG[0x25] = v0;
            v0 = 1;
            goto _L00145F18;
        }
        a0 = __MCMNG[0x27];
        v1 = 2;
        v1 = -2;
        if (a0 == 2) {
            if (v0 == v1) {
                v1 = 3;
                __MCMNG[0x26] = v1;
            } else {
                v1 = 0x64;
                __MCMNG[0x26] = v1;
            }
            return v0;
        }
        v0 = a0 + 1;
        __MCMNG[0x27] = v0;
        v0 = __MCMNG[0x23];
        v0 = v0 + -1;
        __MCMNG[0x23] = v0;
        break;
    default:
        v0 = sceMcSync(v0, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = 0x64;
        __MCMNG[0x22] = 0;
        __MCMNG[0x26] = v0;
        v0 = -1;
        return v0;
    }
    v0 = 0;
    _L00145F18:;
    return v0;
}



/* fsmc_DataWriteFunc @ 0x145090 .. 0x145D4C (0xcbc bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1450b8 writes a register its branch at 0x1450b4 reads
 *   delay: addiu at 0x1450cc writes a register its branch at 0x1450c8 reads
 *   delay: addiu at 0x1450e0 writes a register its branch at 0x1450dc reads
 *   delay: addiu at 0x1450f4 writes a register its branch at 0x1450f0 reads
 *   delay: addiu at 0x145108 writes a register its branch at 0x145104 reads
 *   delay: addiu at 0x14511c writes a register its branch at 0x145118 reads
 *   delay: addiu at 0x145130 writes a register its branch at 0x14512c reads
 *   delay: addiu at 0x145144 writes a register its branch at 0x145140 reads
 *   delay: addiu at 0x145158 writes a register its branch at 0x145154 reads
 *   delay: addiu at 0x14516c writes a register its branch at 0x145168 reads
 *   delay: addiu at 0x145358 writes a register its branch at 0x145354 reads
 *   delay: lui at 0x145444 writes a register its branch at 0x145440 reads
 *   delay: lui at 0x1454d4 writes a register its branch at 0x1454d0 reads
 *   delay: addiu at 0x1455e4 writes a register its branch at 0x1455e0 reads
 *   delay: addiu at 0x145820 writes a register its branch at 0x14581c reads
 *   delay: addiu at 0x1459c0 writes a register its branch at 0x1459bc reads
 *   cfg: kept goto: 0x145234 -> .L00145D40
 *   cfg: kept goto: 0x14527c -> .L00145D40
 *   cfg: kept goto: 0x1452e8 -> .L00145D40
 *   cfg: kept goto: 0x145364 -> .L001453B0
 *   cfg: kept goto: 0x145448 -> .L00145D40
 *   cfg: kept goto: 0x1454d8 -> .L00145D40
 *   cfg: kept goto: 0x145558 -> .L00145D40
 *   cfg: kept goto: 0x1455f0 -> .L00145D40
 *   cfg: kept branch: 0x145820 if (..) goto .L00145850
 *   cfg: kept branch: 0x1459c0 if (..) goto .L001459F0
 *   cfg: kept goto: 0x145a50 -> .L00145A90
 *   cfg: kept goto: 0x145bb4 -> .L00145D40
 *   cfg: kept goto: 0x145bf0 -> .L00145D40
 *   cfg: kept goto: 0x145ca4 -> .L00145D40
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u32 sceMcSeek(s32, s32, u32);
extern int sceMcWrite(int, void *, int);

signed int fsmc_DataWriteFunc(void) {
    u32 t1;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u32 *p;
    u8 stackFrame_1C[4] __attribute__((aligned(4)));

    v1 = 0x66;
    a0 = __MCMNG[0x20];
    a1 = __MCMNG[0x21];
    v0 = __MCMNG[0x23];
    a3 = 2;
    switch (v0) {
    case 0:
        v0 = v0 + 1;
        *(u32 *)s_WriteNum = 0;
        fd = 0;
        *(u32 *)wtofs_254 = 0;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        *(u32 *)wsize_255 = 0;
        break;
    case 1:
        t1 = *(s32 *)(__MCMNG + 0x24);
        p = &((u32 (*)[4])__MCMNG)[a0][a1];
        v0 = _fsmc_GetInfo(a0, a1, (signed int *)p, (signed int *)(u8 *)(p + 8), (signed int
            *)(u32 *)(u8 *)(p + 0x10), t1);
        __MCMNG[0x24] = v0;
        a0 = __MCMNG[0x24];
        if ((s32)a0 > 0) {
            break;
        }
        v0 = _fsmc_InfoErrMess(a0);
        __MCMNG[0x26] = v0;
        v0 = __MCMNG[0x26];
        if (v0 != 0) {
            v0 = -1;
            __MCMNG[0x22] = 0;
            goto _L00145D40;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 2:
        v1 = ((u32 (*)[4])__MCMNG)[a0][a1];
        if (v1 != a3) {
            v0 = 1;
            __MCMNG[0x26] = v0;
            v0 = -4;
            __MCMNG[0x22] = 0;
            goto _L00145D40;
        }
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        break;
    case 3:
        a2 = __MCMNG[0x28];
        t1 = (u32)flchk;
        v0 = sceMcGetDir(a0, a1, (void *)a2, 0, 1, (void *)flchk);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v0 = 0x64;
                __MCMNG[0x22] = 0;
                __MCMNG[0x26] = v0;
                v0 = -1;
                goto _L00145D40;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            break;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 4:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if ((s32)v0 < 0) {
            v1 = 2;
            a0 = __MCMNG[0x27];
            v1 = -2;
            if (a0 == 2) {
                if (v0 == v1) {
                    v1 = 3;
                    __MCMNG[0x26] = v1;
                    goto _L001453B0;
                }
                v1 = -4;
                if (v0 == v1) {
                    flchk[4] = 0;
                    v0 = __MCMNG[0x23];
                    v0 = v0 + 1;
                    __MCMNG[0x23] = v0;
                    break;
                }
                v1 = 0x64;
                __MCMNG[0x26] = v1;
                _L001453B0:;
                return v0;
            }
            v0 = a0 + 1;
            __MCMNG[0x27] = v0;
            v0 = __MCMNG[0x23];
            v0 = v0 + -1;
            __MCMNG[0x23] = v0;
            break;
        } else {
            if (v0 == 0) {
                flchk[4] = 0;
            }
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 5:
        v1 = ((u32 (*)[4])(__MCMNG + 8))[a0][a1];
        a1 = flchk[4];
        a3 = ((a1 + 0x3ff) >> 0xa) + v1;
        if (a1 == 0) {
            if ((s32)a3 <= (s32)2) {
                v0 = 0x1f;
                __MCMNG[0x26] = v0;
                v0 = -6;
                __MCMNG[0x22] = 0;
                goto _L00145D40;
            }
        }
        v1 = __MCMNG[0x2a];
        a2 = v1 + 6;
        if ((s32)(v1 - 0x3fb) > 0) {
            a2 = a2 + (s32)(v1 + 3) / 0x3ff;
        }
        v1 = (a2 + 0x1f) & -0x20;
        *(u32 *)allsize_253 = v1;
        if ((s32)((v1 + 0x3ff) >> 0xa) > (s32)(a3 - (a1 == 0 ? 2 : 0))) {
            v0 = 0x1f;
            __MCMNG[0x26] = v0;
            v0 = -6;
            __MCMNG[0x22] = 0;
            goto _L00145D40;
        }
        v0 = 9;
        __MCMNG[0x23] = v0;
        break;
    case 9:
        v0 = v0 + 1;
        __MCMNG[0x27] = 0;
        __MCMNG[0x23] = v0;
    case 10:
        v0 = flchk[4];
        a3 = 3;
        if (v0 == 0) {
            a3 = a3 | 0x200;
        }
        a2 = __MCMNG[0x28];
        v0 = sceMcOpen(a0, a1, (void *)a2, a3);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v0 = 0x3d;
                __MCMNG[0x26] = v0;
                v0 = -0xa;
                __MCMNG[0x22] = 0;
                goto _L00145D40;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            break;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 11:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        a0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if ((s32)a0 < 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                _fsmc_OpenErrMess(a0);
                v1 = __MCMNG[0x26];
                if (v1 == (u32)0x64) {
                    __MCMNG[0x26] = 0x3d;
                }
                __MCMNG[0x22] = 0;
                v0 = -5;
                goto _L00145D40;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            v0 = __MCMNG[0x23];
            v0 = v0 + -1;
            __MCMNG[0x23] = v0;
            break;
        }
        fd = a0;
        __MCMNG[0x27] = 0;
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 12:
        v0 = *(s32 *)allsize_253;
        a0 = fd;
        v0 = sceMcSeek(a0, v0 + -0x20, 0);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x3d;
                __MCMNG[0x26] = v1;
                __MCMNG[0x23] = 0x64;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 13:
        v0 = sceMcSync(1, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if ((s32)v0 < 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x3d;
                __MCMNG[0x26] = v1;
                __MCMNG[0x23] = 0x64;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                v0 = __MCMNG[0x23];
                v0 = v0 + -1;
                __MCMNG[0x23] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 14:
        a0 = (u32)rddata;
        __MCMNG[0x27] = 0;
        memset((void *)rddata, 0, 0x20);
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
    case 15:
        a0 = fd;
        a1 = (u32)rddata;
        v0 = sceMcWrite(a0, (void *)rddata, 0x20);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x3d;
                __MCMNG[0x26] = v1;
                __MCMNG[0x23] = 0x64;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 16:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        a0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if ((s32)a0 < 0) {
            if (__MCMNG[0x27] == 2 || a0 == -8) {
                __MCMNG[0x26] = 0x3d;
                __MCMNG[0x23] = 0x64;
                break;
            }
            __MCMNG[0x27] = __MCMNG[0x27] + 1;
            __MCMNG[0x23] = __MCMNG[0x23] - 1;
            break;
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            __MCMNG[0x27] = 0;
            break;
        }
    case 17:
        a0 = fd;
        v0 = sceMcSeek(a0, 0, 0);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x3d;
                __MCMNG[0x26] = v1;
                __MCMNG[0x23] = 0x64;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 18:
        v0 = sceMcSync(1, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if ((s32)v0 < 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x3d;
                __MCMNG[0x26] = v1;
                __MCMNG[0x23] = 0x64;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                v0 = __MCMNG[0x23];
                v0 = v0 + -1;
                __MCMNG[0x23] = v0;
                break;
            }
        } else {
            __MCMNG[0x23] = 0x14;
            break;
        }
    case 19:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        a0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if ((s32)a0 < 0) {
            if (__MCMNG[0x27] == 2 || a0 == -8) {
                __MCMNG[0x26] = 0x3d;
                __MCMNG[0x23] = 0x64;
                break;
            }
            __MCMNG[0x27] = __MCMNG[0x27] + 1;
            __MCMNG[0x23] = 0x15;
            break;
        } else {
            *(u32 *)s_WriteNum = *(s32 *)s_WriteNum + a0;
            __MCMNG[0x27] = 0;
            __MCMNG[0x23] = __MCMNG[0x23] + 1;
        }
    case 20:
        if (__MCMNG[0x2a] >= *(u32 *)wtofs_254) {
            v0 = _fsmc_SetWriteData((unsigned int *)wtofs_254);
            __MCMNG[0x27] = 0;
            *(u32 *)wsize_255 = v0;
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            goto _L00145A90;
        } else {
            __MCMNG[0x23] = 0x16;
            break;
        }
    case 21:
        _L00145A90:;
        a1 = *(s32 *)s_pWkBuff != 0 ? *(s32 *)s_pWkBuff : (u32)rddata;
        a2 = *(s32 *)wsize_255;
        v0 = sceMcWrite(*(s32 *)&fd, (void *)a1, a2);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x3d;
                __MCMNG[0x26] = v1;
                __MCMNG[0x23] = 0x64;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            __MCMNG[0x23] = 0x13;
            break;
        }
    case 22:
        a0 = fd;
        v0 = sceMcClose(a0);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x3d;
                __MCMNG[0x26] = v1;
                __MCMNG[0x23] = 0x64;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 23:
        v0 = sceMcSync(1, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        __MCMNG[0x22] = 0;
        if ((s32)v0 < 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x3d;
                v0 = -8;
                __MCMNG[0x26] = v1;
                goto _L00145D40;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            v0 = __MCMNG[0x23];
            v0 = v0 + -1;
            __MCMNG[0x23] = v0;
            break;
        }
        v0 = 0x3e;
        __MCMNG[0x26] = v0;
        v0 = 1;
        return v0;
    case 100:
        v0 = sceMcSync(1, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = fd;
        if ((s32)v0 < 0) {
            v0 = 0x3d;
            __MCMNG[0x26] = v0;
            __MCMNG[0x22] = 0;
            v0 = __MCMNG[0x24];
            return (s32)v0 < 0 ? v0 : -0x3e7;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        break;
    case 101:
        a0 = fd;
        v0 = sceMcClose(a0);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v0 = 0x3d;
                __MCMNG[0x26] = v0;
                v0 = -0x3e7;
                __MCMNG[0x22] = 0;
                goto _L00145D40;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            break;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 102:
        v0 = sceMcSync(1, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = 0x3d;
        __MCMNG[0x22] = 0;
        __MCMNG[0x26] = v0;
        v0 = __MCMNG[0x24];
        return (s32)v0 < 0 ? v0 : -0x3e7;
    }
    v0 = 0;
    _L00145D40:;
    return v0;
}



/* fsmc_DataReadFunc @ 0x1444B0 .. 0x145084 (0xbd4 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1444e0 writes a register its branch at 0x1444dc reads
 *   delay: addiu at 0x1444f4 writes a register its branch at 0x1444f0 reads
 *   delay: addiu at 0x144508 writes a register its branch at 0x144504 reads
 *   delay: addiu at 0x14451c writes a register its branch at 0x144518 reads
 *   delay: addiu at 0x144530 writes a register its branch at 0x14452c reads
 *   delay: addiu at 0x144544 writes a register its branch at 0x144540 reads
 *   delay: addiu at 0x144558 writes a register its branch at 0x144554 reads
 *   delay: addiu at 0x14456c writes a register its branch at 0x144568 reads
 *   delay: addiu at 0x144590 writes a register its branch at 0x14458c reads
 *   delay: addiu at 0x144754 writes a register its branch at 0x144750 reads
 *   delay: addiu at 0x144b5c writes a register its branch at 0x144b58 reads
 *   delay: addiu at 0x144ce0 writes a register its branch at 0x144cdc reads
 *   cfg: kept goto: 0x144640 -> .L00145070
 *   cfg: kept goto: 0x144660 -> .L00145070
 *   cfg: kept goto: 0x1446c4 -> .L00145070
 *   cfg: kept goto: 0x144760 -> .L00145070
 *   cfg: kept goto: 0x144ed4 -> .L00145070
 *   cfg: kept goto: 0x144f50 -> .L00145070
 *   cfg: kept goto: 0x144f90 -> .L00145070
 *   cfg: kept goto: 0x144fbc -> .L00145070
 *   cfg: kept goto: 0x145000 -> .L00145070
 *   cfg: kept goto: 0x145058 -> .L00145070
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u32 sceMcSeek(s32, s32, u32);
extern void * memset(void *, int, unsigned int);
static signed int _fsmc_GetReadData(signed int *, signed int);
extern u8 rddata[];

signed int fsmc_DataReadFunc(void) {
    u32 t1;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 s1;
    u32 v0;
    s32 branchcond_144b58;
    u32 *p;
    u32 s0;
    u8 stackFrame_3C[4] __attribute__((aligned(4)));

    v1 = 0x66;
    a0 = __MCMNG[0x20];
    a1 = __MCMNG[0x21];
    v0 = __MCMNG[0x23];
    a2 = 4;
    switch (v0) {
    case 0:
        v0 = v0 + 1;
        s_ReadNum = 0;
        __MCMNG[0x23] = v0;
        v0 = -1;
        fd = v0;
        __MCMNG[0x27] = 0;
        *(u32 *)rdofs_416 = 0;
    case 1:
        t1 = *(s32 *)(__MCMNG + 0x24);
        p = &((u32 (*)[4])__MCMNG)[a0][a1];
        v0 = _fsmc_GetInfo(a0, a1, (signed int *)p, (signed int *)(u8 *)(p + 8), (signed int
            *)(u32 *)(u8 *)(p + 0x10), t1);
        __MCMNG[0x24] = v0;
        a0 = __MCMNG[0x24];
        if ((s32)a0 > 0) {
            break;
        }
        v0 = _fsmc_InfoErrMess(a0);
        __MCMNG[0x26] = v0;
        v0 = __MCMNG[0x26];
        if (v0 != 0) {
            v0 = -0xa;
            __MCMNG[0x22] = 0;
            goto _L00145070;
        }
        v1 = *(s32 *)p;
        v0 = 2;
        if (v1 != v0) {
            v0 = 1;
            __MCMNG[0x26] = v0;
            v0 = -0xa;
            __MCMNG[0x22] = 0;
            goto _L00145070;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        break;
    case 2:
        a2 = __MCMNG[0x28];
        a3 = 1;
        v0 = sceMcOpen(a0, a1, (void *)a2, a3);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v0 = 0x47;
                __MCMNG[0x26] = v0;
                v0 = -0xa;
                __MCMNG[0x22] = 0;
                goto _L00145070;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            break;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 3:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_3C[0]));
        if (v0 == 0) {
            break;
        }
        a0 = *(s32 *)((u8 *)&stackFrame_3C[0]);
        if ((s32)a0 < 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                _fsmc_OpenErrMess(a0);
                v0 = 0x64;
                v1 = __MCMNG[0x26];
                if (v1 == v0) {
                    v0 = 0x47;
                    __MCMNG[0x26] = v0;
                }
                v0 = *(s32 *)((u8 *)&stackFrame_3C[0]);
                __MCMNG[0x22] = 0;
                goto _L00145070;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            v0 = __MCMNG[0x23];
            v0 = v0 + -1;
            __MCMNG[0x23] = v0;
            break;
        }
        fd = a0;
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        break;
    case 4:
        a0 = fd;
        a1 = (u32)datasize_417;
        v0 = sceMcRead(a0, (void *)datasize_417, a2);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x47;
                __MCMNG[0x26] = v1;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 5:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_3C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_3C[0]);
        if ((s32)v0 < 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x47;
                __MCMNG[0x26] = v1;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                v0 = __MCMNG[0x23];
                v0 = v0 + -1;
                __MCMNG[0x23] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 6:
        v1 = *(s32 *)datasize_417;
        v0 = v1 + -0x3fb;
        a1 = v1 + 6;
        if ((s32)v0 > 0) {
            a0 = v1 + 3;
            v0 = (s32)a0 / 0x3ff;
            a1 = a1 + v0;
        }
        *(u32 *)allsize_419 = (u32)a1;
        a0 = *(s32 *)allsize_419;
        *(u32 *)wtchk_418 = a0 - 1;
        *(u32 *)allsize_419 = (a0 + 0x1f) & ~0x1f;
        __MCMNG[0x27] = 0;
        __MCMNG[0x23] = __MCMNG[0x23] + 1;
        *(u32 *)wtchk_418 = *(s32 *)wtchk_418 - (*(s32 *)allsize_419 - 0x20);
        break;
    case 7:
        v0 = *(s32 *)allsize_419;
        a0 = fd;
        v0 = sceMcSeek(a0, v0 + -0x20, 0);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x47;
                __MCMNG[0x26] = v1;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 8:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_3C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_3C[0]);
        if ((s32)v0 < 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x47;
                __MCMNG[0x26] = v1;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                v0 = __MCMNG[0x23];
                v0 = v0 + -1;
                __MCMNG[0x23] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            __MCMNG[0x27] = 0;
            break;
        }
    case 9:
        a0 = fd;
        a2 = 0x20;
        a1 = (u32)rddata;
        v0 = sceMcRead(a0, (void *)rddata, a2);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x47;
                __MCMNG[0x26] = v1;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 10:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_3C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_3C[0]);
        if ((s32)v0 < 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x47;
                __MCMNG[0x26] = v1;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                v0 = __MCMNG[0x23];
                v0 = v0 + -1;
                __MCMNG[0x23] = v0;
                break;
            }
        } else {
            a0 = *(s32 *)wtchk_418;
            v0 = 1;
            v1 = (u32)rddata;
            v1 = (s32)((u8 *)rddata + a0);
            v1 = *(u8 *)v1;
            branchcond_144b58 = v1 == v0;
            v1 = 0x47;
            if (!branchcond_144b58) {
                __MCMNG[0x26] = v1;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = __MCMNG[0x23];
                v0 = v0 + 1;
                __MCMNG[0x23] = v0;
                __MCMNG[0x27] = 0;
                break;
            }
        }
    case 11:
        a0 = fd;
        a1 = 4;
        v0 = sceMcSeek(a0, a1, 0);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x47;
                __MCMNG[0x26] = v1;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 12:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_3C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_3C[0]);
        if ((s32)v0 < 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x47;
                __MCMNG[0x26] = v1;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                v0 = __MCMNG[0x23];
                v0 = v0 + -1;
                __MCMNG[0x23] = v0;
                break;
            }
        } else {
            v0 = 0xe;
            __MCMNG[0x23] = v0;
            a0 = (u32)rddata;
            a2 = 0x400;
            memset((void *)rddata, 0, a2);
            __MCMNG[0x27] = 0;
            break;
        }
    case 13:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_3C[0]));
        if (v0 == 0) {
            break;
        }
        a2 = *(s32 *)((u8 *)&stackFrame_3C[0]);
        if ((s32)a2 < 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v0 = -2;
                if (a2 == v0) {
                    v0 = 3;
                    __MCMNG[0x26] = v0;
                } else if ((s32)a2 <= (s32)-0xb) {
                    v0 = 1;
                    __MCMNG[0x26] = v0;
                } else {
                    v0 = 0x47;
                    __MCMNG[0x26] = v0;
                }
                __MCMNG[0x24] = a2;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                v0 = __MCMNG[0x23];
                v0 = v0 + 1;
                __MCMNG[0x23] = v0;
                break;
            }
        } else {
            v0 = s_ReadNum;
            a0 = (u32)rdofs_416;
            v0 = v0 + a2;
            s_ReadNum = v0;
            a1 = *(s32 *)datasize_417;
            v0 = _fsmc_GetReadData((signed int *)rdofs_416, a1);
            if ((s32)v0 < 0) {
                v0 = -0x18f;
                __MCMNG[0x24] = v0;
                v1 = 0x47;
                v0 = 0x64;
                __MCMNG[0x26] = v1;
                __MCMNG[0x23] = v0;
                break;
            } else if ((s32)v0 > 0) {
                v0 = 0xf;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = __MCMNG[0x23];
                v0 = v0 + 1;
                __MCMNG[0x23] = v0;
                __MCMNG[0x27] = 0;
            }
        }
    case 14:
        s1 = *(s32 *)s_pWkBuff;
        if (s1 != 0) {
            v0 = *(s32 *)s_WkKByte;
            s0 = v0 << 0xa;
        } else {
            s1 = (u32)rddata;
            s0 = 0x400;
        }
        memset((void *)s1, 0, s0);
        v0 = *(s32 *)rdofs_416;
        if (v0 == 0) {
            s0 = s0 + -4;
        }
        a0 = fd;
        v0 = sceMcRead(a0, (void *)s1, s0);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x47;
                __MCMNG[0x26] = v1;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = 0xd;
            __MCMNG[0x23] = v0;
            break;
        }
    case 15:
        v0 = v0 + 1;
        __MCMNG[0x27] = 0;
        __MCMNG[0x23] = v0;
        break;
    case 16:
        a0 = fd;
        v0 = sceMcClose(a0);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v0 = 0x47;
                __MCMNG[0x22] = 0;
                __MCMNG[0x26] = v0;
                v0 = -0x64;
                goto _L00145070;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            break;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 17:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_3C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_3C[0]);
        if ((s32)v0 < 0) {
            v1 = 2;
            a0 = __MCMNG[0x27];
            if (a0 == v1) {
                v1 = 0x47;
                __MCMNG[0x22] = 0;
                __MCMNG[0x26] = v1;
                goto _L00145070;
            }
            v0 = a0 + 1;
            __MCMNG[0x27] = v0;
            v0 = __MCMNG[0x23];
            v0 = v0 + -1;
            __MCMNG[0x23] = v0;
            break;
        }
        __MCMNG[0x22] = 0;
        v1 = 0x48;
        v0 = 1;
        __MCMNG[0x26] = v1;
        return v0;
    case 100:
        v1 = fd;
        if ((s32)v1 < 0) {
            v0 = -0x64;
            __MCMNG[0x22] = 0;
            goto _L00145070;
        }
        v0 = v0 + 1;
        __MCMNG[0x27] = 0;
        __MCMNG[0x23] = v0;
        break;
    case 101:
        a0 = fd;
        v0 = sceMcClose(a0);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = 0x47;
                v0 = -1;
                __MCMNG[0x26] = v1;
                goto _L00145070;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            break;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 102:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_3C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = -0xc8;
        __MCMNG[0x22] = 0;
        return v0;
    }
    v0 = 0;
    _L00145070:;
    return v0;
}



/* fsmc_IconWriteFunc @ 0x143C10 .. 0x1444A4 (0x894 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x143c38 writes a register its branch at 0x143c34 reads
 *   delay: addiu at 0x143c4c writes a register its branch at 0x143c48 reads
 *   delay: addiu at 0x143c60 writes a register its branch at 0x143c5c reads
 *   delay: addiu at 0x143c74 writes a register its branch at 0x143c70 reads
 *   delay: addiu at 0x143c88 writes a register its branch at 0x143c84 reads
 *   delay: addiu at 0x143c9c writes a register its branch at 0x143c98 reads
 *   delay: addiu at 0x143d64 writes a register its branch at 0x143d60 reads
 *   delay: addiu at 0x143e98 writes a register its branch at 0x143e94 reads
 *   delay: lui at 0x143f84 writes a register its branch at 0x143f80 reads
 *   delay: lui at 0x143fc4 writes a register its branch at 0x143fc0 reads
 *   delay: addiu at 0x1440c4 writes a register its branch at 0x1440c0 reads
 *   delay: addiu at 0x144210 writes a register its branch at 0x14420c reads
 *   delay: addiu at 0x144368 writes a register its branch at 0x144364 reads
 *   cfg: kept goto: 0x143d70 -> .L00144498
 *   cfg: kept goto: 0x143dbc -> .L00144498
 *   cfg: kept goto: 0x143e28 -> .L00144498
 *   cfg: kept goto: 0x143ea4 -> .L00143EF0
 *   cfg: kept goto: 0x143f88 -> .L00144498
 *   cfg: kept goto: 0x143fc8 -> .L00144498
 *   cfg: kept goto: 0x144038 -> .L00144498
 *   cfg: kept branch: 0x144210 if (..) goto .L00144240
 *   cfg: kept goto: 0x14436c -> .L00144498
 *   cfg: kept goto: 0x1443a0 -> .L00144498
 *   cfg: kept goto: 0x1443c4 -> .L00144498
 *   cfg: kept goto: 0x14441c -> .L00144498
 *   cfg: kept goto: 0x144478 -> .L00144498
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern int sceMcWrite(int, void *, int);

signed int fsmc_IconWriteFunc(void) {
    u32 t1;
    s32 t0;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u32 *p;
    u8 stackFrame_1C[4] __attribute__((aligned(4)));

    v1 = 0x66;
    a0 = __MCMNG[0x20];
    a1 = __MCMNG[0x21];
    v0 = __MCMNG[0x23];
    a3 = 2;
    switch (v0) {
    case 0:
        v0 = v0 + 1;
        *(u32 *)s_WriteNum = 0;
        fd = 0;
        *(u32 *)wtofs_559 = 0;
        __MCMNG[0x23] = v0;
        break;
    case 1:
        t1 = *(s32 *)(__MCMNG + 0x24);
        p = &((u32 (*)[4])__MCMNG)[a0][a1];
        v0 = _fsmc_GetInfo(a0, a1, (signed int *)p, (signed int *)(u8 *)(p + 8), (signed int
            *)(u32 *)(u8 *)(p + 0x10), t1);
        __MCMNG[0x24] = v0;
        a0 = __MCMNG[0x24];
        if ((s32)a0 > 0) {
            break;
        }
        v0 = _fsmc_InfoErrMess(a0);
        __MCMNG[0x26] = v0;
        v1 = __MCMNG[0x26];
        if (v1 != 0) {
            v0 = 0x64;
            if (v1 == v0) {
                v0 = 0x3d;
                __MCMNG[0x26] = v0;
            }
            __MCMNG[0x22] = 0;
            v0 = -0xa;
            goto _L00144498;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 2:
        v1 = ((u32 (*)[4])__MCMNG)[a0][a1];
        if (v1 != a3) {
            v0 = 0x3d;
            __MCMNG[0x22] = 0;
            __MCMNG[0x26] = v0;
            v0 = -4;
            goto _L00144498;
        }
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        break;
    case 3:
        a2 = __MCMNG[0x28];
        t0 = 1;
        t1 = (u32)flchk;
        v0 = sceMcGetDir(a0, a1, (void *)a2, 0, t0, (void *)flchk);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v0 = 0x64;
                __MCMNG[0x22] = 0;
                __MCMNG[0x26] = v0;
                v0 = -1;
                goto _L00144498;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            break;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 4:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if ((s32)v0 < 0) {
            v1 = 2;
            a0 = __MCMNG[0x27];
            v1 = -2;
            if (a0 == 2) {
                if (v0 == v1) {
                    v1 = 3;
                    __MCMNG[0x26] = v1;
                    goto _L00143EF0;
                }
                v1 = -4;
                if (v0 == v1) {
                    flchk[4] = 0;
                    v0 = __MCMNG[0x23];
                    v0 = v0 + 1;
                    __MCMNG[0x23] = v0;
                    break;
                }
                v1 = 0x64;
                __MCMNG[0x26] = v1;
                _L00143EF0:;
                return v0;
            }
            v0 = a0 + 1;
            __MCMNG[0x27] = v0;
            v0 = __MCMNG[0x23];
            v0 = v0 + -1;
            __MCMNG[0x23] = v0;
            break;
        } else {
            if (v0 == 0) {
                flchk[4] = 0;
            }
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 5:
        v1 = ((u32 (*)[4])(__MCMNG + 8))[a0][a1];
        a0 = flchk[4];
        a1 = ((a0 + 0x3ff) >> 0xa) + v1;
        if (a0 == 0 && (s32)a1 <= 2) {
            v0 = 0x1f;
            __MCMNG[0x26] = v0;
            v0 = -6;
            __MCMNG[0x22] = 0;
            goto _L00144498;
        }
        if (a1 - (a0 == 0 ? 2 : 0) < ((__MCMNG[0x2a] + 0x3ff) >> 0xa)) {
            v0 = 0x3d;
            __MCMNG[0x26] = v0;
            v0 = -0x65;
            __MCMNG[0x22] = 0;
            goto _L00144498;
        }
        __MCMNG[0x27] = 0;
        v0 = 8;
        __MCMNG[0x23] = v0;
        break;
    case 8:
        v0 = flchk[4];
        a3 = 3;
        if (v0 == 0) {
            a3 = a3 | 0x200;
        }
        a2 = __MCMNG[0x28];
        v0 = sceMcOpen(a0, a1, (void *)a2, a3);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v0 = 0x3d;
                __MCMNG[0x22] = 0;
                __MCMNG[0x26] = v0;
                v0 = -0xb;
                goto _L00144498;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            break;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 9:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        a0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if ((s32)a0 < 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                _fsmc_OpenErrMess(a0);
                v0 = 0x64;
                v1 = __MCMNG[0x26];
                if (v1 == v0) {
                    v0 = 0x3d;
                    __MCMNG[0x26] = v0;
                }
                v0 = -1;
                __MCMNG[0x24] = v0;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                v0 = __MCMNG[0x23];
                v0 = v0 + -1;
                __MCMNG[0x23] = v0;
                break;
            }
        } else {
            fd = a0;
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 10:
        __MCMNG[0x23] = v0 + 1;
        *(u32 *)wtsize_560 = __MCMNG[0x2a] - *(s32 *)wtofs_559;
        __MCMNG[0x27] = 0;
        break;
    case 11:
        v0 = sceMcWrite(fd, (void *)(__MCMNG[0x2e] + *(u32 *)wtofs_559), *(s32 *)wtsize_560);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = -1;
                __MCMNG[0x24] = v1;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 12:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        a1 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if ((s32)a1 < 0) {
            if (__MCMNG[0x27] == 2 || a1 == -8) {
                __MCMNG[0x24] = -1;
                __MCMNG[0x23] = 0x64;
                break;
            }
            __MCMNG[0x27] = __MCMNG[0x27] + 1;
            __MCMNG[0x23] = __MCMNG[0x23] - 1;
            break;
        } else {
            *(u32 *)s_WriteNum = *(s32 *)s_WriteNum + a1;
            *(u32 *)wtofs_559 = *(s32 *)wtofs_559 + a1;
            __MCMNG[0x27] = 0;
            if (*(u32 *)wtofs_559 >= __MCMNG[0x2a]) {
                __MCMNG[0x23] = __MCMNG[0x23] + 1;
            } else {
                __MCMNG[0x23] = 0xa;
            }
            break;
        }
    case 13:
        a0 = fd;
        v0 = sceMcClose(a0);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v1 = -1;
                __MCMNG[0x24] = v1;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 14:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        __MCMNG[0x22] = 0;
        if ((s32)v0 < 0) {
            v1 = 2;
            a0 = __MCMNG[0x27];
            v1 = 0x3d;
            if (a0 == 2) {
                __MCMNG[0x26] = v1;
                goto _L00144498;
            }
            v0 = a0 + 1;
            __MCMNG[0x27] = v0;
            v0 = __MCMNG[0x23];
            v0 = v0 + -1;
            __MCMNG[0x23] = v0;
            break;
        }
        v0 = 0x3e;
        __MCMNG[0x26] = v0;
        v0 = 1;
        return v0;
    case 100:
        v1 = fd;
        if ((s32)v1 < 0) {
            v0 = 0x3d;
            __MCMNG[0x22] = 0;
            __MCMNG[0x26] = v0;
            v0 = -0x3e7;
            goto _L00144498;
        }
        v0 = v0 + 1;
        __MCMNG[0x27] = 0;
        __MCMNG[0x23] = v0;
        break;
    case 101:
        a0 = fd;
        v0 = sceMcClose(a0);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v0 = 0x3d;
                __MCMNG[0x22] = 0;
                __MCMNG[0x26] = v0;
                v0 = -0x3e7;
                goto _L00144498;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            break;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 102:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = 0x3d;
        __MCMNG[0x22] = 0;
        __MCMNG[0x26] = v0;
        v0 = -0x3e7;
        return v0;
    }
    v0 = 0;
    _L00144498:;
    return v0;
}



/* fsmc_IconWriteFileFunc @ 0x1432A0 .. 0x143C10 (0x970 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1432cc writes a register its branch at 0x1432c8 reads
 *   delay: addiu at 0x1432e0 writes a register its branch at 0x1432dc reads
 *   delay: addiu at 0x1432f4 writes a register its branch at 0x1432f0 reads
 *   delay: addiu at 0x143308 writes a register its branch at 0x143304 reads
 *   delay: addiu at 0x14331c writes a register its branch at 0x143318 reads
 *   delay: addiu at 0x143330 writes a register its branch at 0x14332c reads
 *   delay: addiu at 0x143344 writes a register its branch at 0x143340 reads
 *   delay: addiu at 0x143518 writes a register its branch at 0x143514 reads
 *   delay: lui at 0x143604 writes a register its branch at 0x143600 reads
 *   stack: address of the slot at 0x20 escapes at 0x143628
 *   delay: lui at 0x1436d4 writes a register its branch at 0x1436d0 reads
 *   delay: addiu at 0x1437d4 writes a register its branch at 0x1437d0 reads
 *   delay: addiu at 0x143940 writes a register its branch at 0x14393c reads
 *   delay: lui at 0x1439c0 writes a register its branch at 0x1439bc reads
 *   cfg: kept goto: 0x1433fc -> .L00143C00
 *   cfg: kept goto: 0x143444 -> .L00143C00
 *   cfg: kept goto: 0x1434a8 -> .L00143C00
 *   cfg: kept goto: 0x143524 -> .L00143570
 *   cfg: kept goto: 0x143608 -> .L00143C00
 *   cfg: kept goto: 0x14364c -> .L00143C00
 *   cfg: kept goto: 0x1436d8 -> .L00143C00
 *   cfg: kept goto: 0x143748 -> .L00143C00
 *   cfg: kept branch: 0x143940 if (..) goto .L00143970
 *   cfg: kept goto: 0x143ab0 -> .L00143C00
 *   cfg: kept goto: 0x143af0 -> .L00143C00
 *   cfg: kept goto: 0x143b34 -> .L00143C00
 *   cfg: kept goto: 0x143b84 -> .L00143C00
 *   cfg: kept goto: 0x143be0 -> .L00143C00
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern char * strcpy(char *, const char *);
extern int sceOpen(void *, int, ...);
extern int sceLseek(int, int, int);
extern int sceRead(int, void *, int);
extern int sceClose(int);

signed int fsmc_IconWriteFileFunc(void) {
    u32 xt1;
    u32 xt0;
    u32 t1;
    u32 a3;
    u32 a0;
    u32 a2;
    u32 a1;
    s32 v1;
    s32 v0;
    s32 s0;
    s32 t0;
    u32 *p;
    u8 stackFrame_6C[4] __attribute__((aligned(4)));
    u8 stackFrame_20[76] __attribute__((aligned(16)));

    v1 = 0x66;
    a0 = __MCMNG[0x20];
    a1 = __MCMNG[0x21];
    v0 = __MCMNG[0x23];
    a3 = 2;
    switch (v0) {
    case 0:
        v0 = v0 + 1;
        fd = 0;
        *(u32 *)allsize_670 = 0;
        *(u32 *)wtsize_671 = 0;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        break;
    case 1:
        t1 = *(s32 *)(__MCMNG + 0x24);
        p = &((u32 (*)[4])__MCMNG)[a0][a1];
        v0 = _fsmc_GetInfo(a0, a1, (signed int *)p, (signed int *)(u8 *)(p + 8), (signed int
            *)(u32 *)(u8 *)(p + 0x10), t1);
        __MCMNG[0x24] = v0;
        a0 = __MCMNG[0x24];
        if ((s32)a0 > 0) {
            break;
        }
        v0 = _fsmc_InfoErrMess(a0);
        __MCMNG[0x26] = v0;
        v0 = __MCMNG[0x26];
        if (v0 != 0) {
            __MCMNG[0x22] = 0;
            return -0xa;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 2:
        v1 = ((u32 (*)[4])__MCMNG)[a0][a1];
        if (v1 != a3) {
            v0 = 0x3d;
            __MCMNG[0x22] = 0;
            __MCMNG[0x26] = v0;
            return -4;
        }
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 3:
        a2 = __MCMNG[0x28];
        t0 = 1;
        t1 = (u32)flchk;
        v0 = sceMcGetDir(a0, a1, (void *)a2, 0, t0, (void *)flchk);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v0 = 0x64;
                __MCMNG[0x22] = 0;
                __MCMNG[0x26] = v0;
                return -1;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            break;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 4:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_6C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_6C[0]);
        if ((s32)v0 < 0) {
            v1 = 2;
            a0 = __MCMNG[0x27];
            v1 = -2;
            if (a0 == 2) {
                if (v0 == v1) {
                    v1 = 3;
                    __MCMNG[0x26] = v1;
                    goto _L00143570;
                }
                v1 = -4;
                if (v0 == v1) {
                    flchk[4] = 0;
                    v0 = __MCMNG[0x23];
                    v0 = v0 + 1;
                    __MCMNG[0x23] = v0;
                    break;
                }
                v1 = 0x64;
                __MCMNG[0x26] = v1;
                _L00143570:;
                return v0;
            }
            v0 = a0 + 1;
            __MCMNG[0x27] = v0;
            v0 = __MCMNG[0x23];
            v0 = v0 + -1;
            __MCMNG[0x23] = v0;
            break;
        } else {
            if (v0 == 0) {
                flchk[4] = 0;
            }
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 5:
        v1 = ((u32 (*)[4])(__MCMNG + 8))[a0][a1];
        s0 = (((flchk[4]) + 0x3ff) >> 0xa) + v1;
        if ((flchk[4]) == 0) {
            if (s0 <= (s32)2) {
                __MCMNG[0x22] = 0;
                __MCMNG[0x26] = 0x1f;
                return -6;
            }
        }
        a1 = __MCMNG[0x29];
        strcpy((char *)((u8 *)&stackFrame_20[0]), (const char *)a1);
        a1 = 1;
        v0 = sceOpen((void *)((u8 *)&stackFrame_20[0]), a1);
        *(u32 *)src_668 = (u32)v0;
        v0 = *(s32 *)src_668;
        if ((s32)v0 < 0) {
            __MCMNG[0x22] = 0;
            __MCMNG[0x26] = 0x3d;
            return v0;
        }
        v1 = __MCMNG[0x2b];
        if (v1 != 0) {
            *(u32 *)allsize_670 = v1;
        } else {
            v0 = sceLseek(v0, 0, 2);
            *(u32 *)allsize_670 = v0;
            a0 = *(s32 *)src_668;
            sceLseek(a0, 0, 0);
        }
        if (s0 - (flchk[4] == 0 ? 2 : 0) < (*(s32 *)allsize_670 + 0x3ff) / 0x400) {
            __MCMNG[0x22] = 0;
            __MCMNG[0x26] = 0x3d;
            return -0x65;
        }
        __MCMNG[0x27] = 0;
        v0 = 8;
        __MCMNG[0x23] = v0;
        break;
    case 8:
        v0 = flchk[4];
        a3 = 3;
        if (v0 == 0) {
            a3 = a3 | 0x200;
        }
        a2 = __MCMNG[0x28];
        v0 = sceMcOpen(a0, a1, (void *)a2, a3);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v0 = 0x3d;
                __MCMNG[0x22] = 0;
                __MCMNG[0x26] = v0;
                return -0xb;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            break;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 9:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_6C[0]));
        if (v0 == 0) {
            break;
        }
        a0 = *(s32 *)((u8 *)&stackFrame_6C[0]);
        if ((s32)a0 < 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                _fsmc_OpenErrMess(a0);
                v0 = 0x64;
                v1 = __MCMNG[0x26];
                if (v1 == v0) {
                    __MCMNG[0x26] = 0x3d;
                }
                v0 = -1;
                __MCMNG[0x24] = v0;
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                v0 = __MCMNG[0x23];
                v0 = v0 + -1;
                __MCMNG[0x23] = v0;
                break;
            }
        } else {
            fd = a0;
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 10:
        a0 = *(s32 *)src_668;
        xt1 = (u32)rddata;
        a1 = xt1;
        v0 = sceRead(a0, (void *)rddata, 0x400);
        *(u32 *)size_669 = (u32)v0;
        v0 = *(s32 *)size_669;
        if ((s32)v0 <= 0) {
            __MCMNG[0x23] = 0xd;
            break;
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            __MCMNG[0x27] = 0;
            break;
        }
    case 11:
        a0 = fd;
        a2 = *(s32 *)size_669;
        xt0 = (u32)rddata;
        a1 = xt0;
        v0 = sceMcWrite(a0, (void *)rddata, a2);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                __MCMNG[0x24] = -1;
                __MCMNG[0x23] = 0x64;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 12:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_6C[0]));
        if (v0 == 0) {
            break;
        }
        a0 = *(s32 *)((u8 *)&stackFrame_6C[0]);
        if ((s32)a0 < 0) {
            if (__MCMNG[0x27] == 2 || a0 == -8) {
                __MCMNG[0x24] = -1;
                __MCMNG[0x23] = 0x64;
                break;
            }
            __MCMNG[0x27] = __MCMNG[0x27] + 1;
            __MCMNG[0x23] = __MCMNG[0x23] - 1;
            break;
        } else {
            *(u32 *)wtsize_671 = *(s32 *)wtsize_671 + *(s32 *)size_669;
            __MCMNG[0x27] = 0;
            if (*(s32 *)allsize_670 > *(s32 *)wtsize_671) {
                __MCMNG[0x23] = __MCMNG[0x23] - 2;
            } else {
                __MCMNG[0x23] = __MCMNG[0x23] + 1;
            }
            break;
        }
    case 13:
        a0 = *(s32 *)src_668;
        sceClose(a0);
        v0 = __MCMNG[0x23];
        v0 = 1 + v0;
        __MCMNG[0x23] = v0;
        break;
    case 14:
        a0 = fd;
        v0 = sceMcClose(a0);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                __MCMNG[0x24] = -1;
                __MCMNG[0x23] = 0x64;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = __MCMNG[0x23];
            v0 = 1 + v0;
            __MCMNG[0x23] = v0;
            break;
        }
    case 15:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_6C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_6C[0]);
        if ((s32)v0 < 0) {
            v1 = 2;
            a0 = __MCMNG[0x27];
            if (a0 == v1) {
                __MCMNG[0x22] = 0;
                __MCMNG[0x26] = 0x3d;
                goto _L00143C00;
            }
            v0 = a0 + 1;
            __MCMNG[0x27] = v0;
            v0 = __MCMNG[0x23];
            v0 = v0 + -1;
            __MCMNG[0x23] = v0;
            break;
        }
        __MCMNG[0x22] = 0;
        v1 = 0x3e;
        v0 = 1;
        __MCMNG[0x26] = v1;
        return v0;
    case 100:
        a0 = *(s32 *)src_668;
        if (a0 != 0) {
            sceClose(a0);
        }
        v0 = fd;
        if ((s32)v0 < 0) {
            v0 = 0x3d;
            __MCMNG[0x26] = v0;
            v0 = -0x3e7;
            __MCMNG[0x22] = 0;
            goto _L00143C00;
        }
        __MCMNG[0x27] = 0;
        break;
    case 101:
        a0 = fd;
        v0 = sceMcClose(a0);
        if (v0 != 0) {
            v0 = 2;
            v1 = __MCMNG[0x27];
            if (v1 == v0) {
                v0 = 0x3d;
                __MCMNG[0x26] = v0;
                v0 = -0x3e7;
                __MCMNG[0x22] = 0;
                goto _L00143C00;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            break;
        }
        v0 = __MCMNG[0x23];
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 102:
        v0 = sceMcSync(1, (void *)0, (void *)((u8 *)&stackFrame_6C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = 0x3d;
        __MCMNG[0x22] = 0;
        __MCMNG[0x26] = v0;
        v0 = -0x3e7;
        return v0;
    }
    v0 = 0;
    _L00143C00:;
    return v0;
}


/* fsmc_IconReadFunc @ 0x142CA0 .. 0x1432A0 (0x600 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x142ccc writes a register its branch at 0x142cc8 reads
 *   delay: addiu at 0x142ce0 writes a register its branch at 0x142cdc reads
 *   delay: addiu at 0x142cf4 writes a register its branch at 0x142cf0 reads
 *   delay: addiu at 0x142d08 writes a register its branch at 0x142d04 reads
 *   delay: addiu at 0x142d1c writes a register its branch at 0x142d18 reads
 *   delay: addiu at 0x142d30 writes a register its branch at 0x142d2c reads
 *   delay: addiu at 0x142df4 writes a register its branch at 0x142df0 reads
 *   delay: addiu at 0x142e44 writes a register its branch at 0x142e40 reads
 *   delay: addiu at 0x142ecc writes a register its branch at 0x142ec8 reads
 *   delay: addiu at 0x142f98 writes a register its branch at 0x142f94 reads
 *   delay: addiu at 0x143160 writes a register its branch at 0x14315c reads
 *   cfg: kept goto: 0x142dd8 -> .L00143290
 *   cfg: kept goto: 0x142ed8 -> .L00143290
 *   cfg: kept goto: 0x1430e4 -> .L00143290
 *   cfg: kept goto: 0x143164 -> .L00143290
 *   cfg: kept goto: 0x143198 -> .L00143290
 *   cfg: kept goto: 0x1431bc -> .L00143290
 *   cfg: kept goto: 0x143270 -> .L00143290
 *   declaration vs inferred signature: return signed int vs inferred u32
 */
/* r4 */


signed int fsmc_IconReadFunc(void) {
    u32 t1;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 *s0;
    u32 v0;
    u8 stackFrame_2C[4] __attribute__((aligned(4)));

    v0 = 0x66;
    a0 = *(s32 *)(__MCMNG + 0x20);
    a1 = *(s32 *)(__MCMNG + 0x21);
    v1 = *(s32 *)(__MCMNG + 0x23);
    switch (v1) {
    case 0:
        v0 = v1 + 1;
        s_ReadNum = 0;
        fd = 0;
        rdofs_787 = 0;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
    case 1:
        t1 = *(s32 *)(__MCMNG + 0x24);
        s0 = &((u32 (*)[4])__MCMNG)[a0][a1];
        v0 = _fsmc_GetInfo(a0, a1, (signed int *)s0, (signed int *)(u8 *)(s0 + 8), (signed int
            *)(u32 *)(u8 *)(s0 + 0x10), t1);
        __MCMNG[0x24] = v0;
        a0 = *(s32 *)(__MCMNG + 0x24);
        if ((s32)a0 > 0) {
            break;
        }
        v0 = _fsmc_InfoErrMess(a0);
        __MCMNG[0x26] = v0;
        v0 = *(s32 *)(__MCMNG + 0x26);
        if (v0 != 0) {
            v0 = -0xa;
            __MCMNG[0x22] = 0;
            goto _L00143290;
        }
        v1 = *(s32 *)s0;
        v0 = 2;
        if (v1 != v0) {
            v0 = 0x64;
            __MCMNG[0x23] = v0;
            break;
        } else {
            v0 = *(s32 *)(__MCMNG + 0x23);
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 2:
        a2 = *(s32 *)(__MCMNG + 0x28);
        a3 = 1;
        v0 = sceMcOpen(a0, a1, (void *)a2, a3);
        if (v0 != 0) {
            v0 = 2;
            v1 = *(s32 *)(__MCMNG + 0x27);
            if (v1 == v0) {
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = *(s32 *)(__MCMNG + 0x23);
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 3:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_2C[0]));
        if (v0 == 0) {
            break;
        }
        a0 = *(s32 *)((u8 *)&stackFrame_2C[0]);
        if ((s32)a0 < 0) {
            v0 = 2;
            v1 = *(s32 *)(__MCMNG + 0x27);
            if (v1 == v0) {
                _fsmc_OpenErrMess(a0);
                v0 = 0x64;
                v1 = *(s32 *)(__MCMNG + 0x26);
                if (v1 == v0) {
                    v0 = 0x47;
                    __MCMNG[0x26] = v0;
                }
                v1 = -1;
                v0 = 0x64;
                __MCMNG[0x24] = v1;
                __MCMNG[0x23] = v0;
                __MCMNG[0x22] = 0;
                v0 = *(s32 *)((u8 *)&stackFrame_2C[0]);
                goto _L00143290;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            v0 = *(s32 *)(__MCMNG + 0x23);
            v0 = v0 + -1;
            __MCMNG[0x23] = v0;
            break;
        }
        v0 = *(s32 *)(__MCMNG + 0x23);
        fd = a0;
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 4:
        v0 = v1 + 1;
        __MCMNG[0x27] = 0;
        __MCMNG[0x23] = v0;
        break;
    case 5:
        v0 = sceMcRead(fd, (void *)(__MCMNG[0x2d] + rdofs_787), __MCMNG[0x2a] - rdofs_787);
        if (v0 != 0) {
            v0 = 2;
            v1 = *(s32 *)(__MCMNG + 0x27);
            if (v1 == v0) {
                v0 = 0x64;
                __MCMNG[0x23] = v0;
                break;
            } else {
                v0 = v1 + 1;
                __MCMNG[0x27] = v0;
                break;
            }
        } else {
            v0 = *(s32 *)(__MCMNG + 0x23);
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 6:
        if (sceMcSync(1, (void *)0, (void *)stackFrame_2C) == 0) {
            break;
        }
        if (*(s32 *)stackFrame_2C < 0) {
            if (__MCMNG[0x27] == 2) {
                __MCMNG[0x24] = *(s32 *)stackFrame_2C;
                __MCMNG[0x23] = 0x64;
            } else {
                __MCMNG[0x23]--;
                __MCMNG[0x27]++;
            }
            break;
        }
        s_ReadNum += *(s32 *)stackFrame_2C;
        rdofs_787 += *(s32 *)stackFrame_2C;
        __MCMNG[0x27] = 0;
        if (rdofs_787 >= __MCMNG[0x2a]) {
            __MCMNG[0x23]++;
        } else {
            __MCMNG[0x23] = 4;
        }
        break;
    case 7:
        v0 = v1 + 1;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        break;
    case 8:
        a0 = fd;
        v0 = sceMcClose(a0);
        if (v0 != 0) {
            v0 = 2;
            v1 = *(s32 *)(__MCMNG + 0x27);
            if (v1 == v0) {
                v0 = 0x47;
                __MCMNG[0x22] = 0;
                __MCMNG[0x26] = v0;
                v0 = -1;
                goto _L00143290;
            }
            v0 = v1 + 1;
            __MCMNG[0x27] = v0;
            break;
        }
        v0 = *(s32 *)(__MCMNG + 0x23);
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 9:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_2C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_2C[0]);
        __MCMNG[0x22] = 0;
        if ((s32)v0 < 0) {
            v1 = 2;
            a0 = *(s32 *)(__MCMNG + 0x27);
            v1 = 0x47;
            if (a0 == 2) {
                __MCMNG[0x26] = v1;
                goto _L00143290;
            }
            v0 = a0 + 1;
            __MCMNG[0x27] = v0;
            v0 = *(s32 *)(__MCMNG + 0x23);
            v0 = v0 + -1;
            __MCMNG[0x23] = v0;
            break;
        }
        v0 = 0x48;
        __MCMNG[0x26] = v0;
        v0 = 1;
        return v0;
    case 100:
        v0 = fd;
        if ((s32)v0 < 0) {
            v0 = 0x47;
            __MCMNG[0x22] = 0;
            __MCMNG[0x26] = v0;
            v0 = *(s32 *)(__MCMNG + 0x24);
            goto _L00143290;
        }
        v0 = v1 + 1;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        break;
    case 101:
        a0 = fd;
        v0 = sceMcClose(a0);
        if (v0 != 0) {
            v0 = 2;
            v1 = *(s32 *)(__MCMNG + 0x27);
            if (v1 == v0) {
                v0 = 0x47;
                __MCMNG[0x22] = 0;
                __MCMNG[0x26] = v0;
            }
            v0 = *(s32 *)(__MCMNG + 0x27);
            v0 = v0 + 1;
            __MCMNG[0x27] = v0;
            break;
        } else {
            v0 = *(s32 *)(__MCMNG + 0x23);
            v0 = v0 + 1;
            __MCMNG[0x23] = v0;
            break;
        }
    case 102:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_2C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = 0x47;
        __MCMNG[0x22] = 0;
        __MCMNG[0x26] = v0;
        v0 = -0x64;
        return v0;
    }
    v0 = 0;
    _L00143290:;
    return v0;
}








/* fsmc_FormatFunc @ 0x142B40 .. 0x142C9C (0x15c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x142b68 writes a register its branch at 0x142b64 reads
 *   cfg: kept branch: 0x142ba0 if (..) goto .L00142BE8
 *   cfg: kept branch: 0x142bb0 if (..) goto .L00142BD8
 *   cfg: kept goto: 0x142bc0 -> .L00142C90
 *   cfg: kept branch: 0x142c18 if (..) goto .L00142C40
 *   cfg: kept goto: 0x142c24 -> .L00142C90
 *   cfg: kept branch: 0x142c40 if (..) goto .L00142C68
 *   cfg: kept goto: 0x142c54 -> .L00142C90
 */



static u32 fsmc_FormatFunc(void) {
    u32 v0;
    u32 a0;
    u32 a1;
    u32 v1;
    u8 stackFrame_1C[4] __attribute__((aligned(4)));

    v0 = 2;
    a0 = *(s32 *)(__MCMNG + 0x20);
    a1 = *(s32 *)(__MCMNG + 0x21);
    v1 = *(s32 *)(__MCMNG + 0x23);
    switch (v1) {
    case 0:
        v0 = v1 + 1;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        break;
    case 1:
        v0 = sceMcFormat(a0, a1);
        if (v0 == 0) {
            goto _L00142BE8;
        }
        v0 = 2;
        v1 = *(s32 *)(__MCMNG + 0x27);
        if (v1 != v0) {
            goto _L00142BD8;
        }
        v1 = 0x32;
        v0 = -0xa;
        __MCMNG[0x26] = v1;
        goto _L00142C90;
        _L00142BD8:;
        v0 = v1 + 1;
        __MCMNG[0x27] = v0;
        break;
        _L00142BE8:;
        v0 = *(s32 *)(__MCMNG + 0x23);
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 2:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)(u8 *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if (v0 != 0) {
            goto _L00142C40;
        }
        v0 = 0x34;
        __MCMNG[0x22] = 0;
        __MCMNG[0x26] = v0;
        v0 = 1;
        goto _L00142C90;
        _L00142C40:;
        a0 = *(s32 *)(__MCMNG + 0x27);
        v1 = 2;
        if (a0 != v1) {
            goto _L00142C68;
        }
        v1 = 0x32;
        __MCMNG[0x22] = 0;
        __MCMNG[0x26] = v1;
        goto _L00142C90;
        _L00142C68:;
        v0 = a0 + 1;
        __MCMNG[0x27] = v0;
        v0 = *(s32 *)(__MCMNG + 0x23);
        v0 = v0 + -1;
        __MCMNG[0x23] = v0;
    }
    v0 = 0;
    _L00142C90:;
    return v0;
}






/* fsmc_UnFormatFunc @ 0x1429E0 .. 0x142B3C (0x15c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x142a08 writes a register its branch at 0x142a04 reads
 *   cfg: kept branch: 0x142a40 if (..) goto .L00142A88
 *   cfg: kept branch: 0x142a50 if (..) goto .L00142A78
 *   cfg: kept goto: 0x142a60 -> .L00142B30
 *   cfg: kept branch: 0x142ab8 if (..) goto .L00142AE0
 *   cfg: kept goto: 0x142ac4 -> .L00142B30
 *   cfg: kept branch: 0x142ae0 if (..) goto .L00142B08
 *   cfg: kept goto: 0x142af4 -> .L00142B30
 */


static u32 fsmc_UnFormatFunc(void) {
    u32 v0;
    u32 a0;
    u32 a1;
    u32 v1;
    u8 stackFrame_1C[4] __attribute__((aligned(4)));

    v0 = 2;
    a0 = *(s32 *)(__MCMNG + 0x20);
    a1 = *(s32 *)(__MCMNG + 0x21);
    v1 = *(s32 *)(__MCMNG + 0x23);
    switch (v1) {
    case 0:
        v0 = v1 + 1;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        break;
    case 1:
        v0 = sceMcUnformat(a0, a1);
        if (v0 == 0) {
            goto _L00142A88;
        }
        v0 = 2;
        v1 = *(s32 *)(__MCMNG + 0x27);
        if (v1 != v0) {
            goto _L00142A78;
        }
        v1 = 0x37;
        v0 = -0xa;
        __MCMNG[0x26] = v1;
        goto _L00142B30;
        _L00142A78:;
        v0 = v1 + 1;
        __MCMNG[0x27] = v0;
        break;
        _L00142A88:;
        v0 = *(s32 *)(__MCMNG + 0x23);
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 2:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)(u8 *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if (v0 != 0) {
            goto _L00142AE0;
        }
        v0 = 0x39;
        __MCMNG[0x22] = 0;
        __MCMNG[0x26] = v0;
        v0 = 1;
        goto _L00142B30;
        _L00142AE0:;
        a0 = *(s32 *)(__MCMNG + 0x27);
        v1 = 2;
        if (a0 != v1) {
            goto _L00142B08;
        }
        v1 = 0x37;
        __MCMNG[0x22] = 0;
        __MCMNG[0x26] = v1;
        goto _L00142B30;
        _L00142B08:;
        v0 = a0 + 1;
        __MCMNG[0x27] = v0;
        v0 = *(s32 *)(__MCMNG + 0x23);
        v0 = v0 + -1;
        __MCMNG[0x23] = v0;
    }
    v0 = 0;
    _L00142B30:;
    return v0;
}






/* fsmc_ChDirFunc @ 0x142850 .. 0x1429D4 (0x184 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x142878 writes a register its branch at 0x142874 reads
 *   cfg: kept branch: 0x1428b0 if (..) goto .L00142900
 *   cfg: kept branch: 0x1428cc if (..) goto .L001428F0
 *   cfg: kept goto: 0x1428dc -> .L001429C8
 *   cfg: kept branch: 0x142930 if (..) goto .L00142950
 *   cfg: kept goto: 0x14293c -> .L001429C8
 */



static signed int fsmc_ChDirFunc(void) {
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u8 stackFrame_1C[4] __attribute__((aligned(4)));

    v0 = 2;
    a0 = *(s32 *)(__MCMNG + 0x20);
    a1 = *(s32 *)(__MCMNG + 0x21);
    v1 = *(s32 *)(__MCMNG + 0x23);
    switch (v1) {
    case 0:
        v0 = v1 + 1;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        break;
    case 1:
        a2 = *(s32 *)(__MCMNG + 0x28);
        v0 = sceMcChdir(a0, a1, a2, *(s32 *)(__MCMNG + 0x29));
        if (v0 == 0) {
            goto _L00142900;
        }
        v0 = 2;
        v1 = *(s32 *)(__MCMNG + 0x27);
        if (v1 != v0) {
            goto _L001428F0;
        }
        v1 = 0x64;
        v0 = -0xa;
        __MCMNG[0x26] = v1;
        goto _L001429C8;
        _L001428F0:;
        v0 = v1 + 1;
        __MCMNG[0x27] = v0;
        break;
        _L00142900:;
        v0 = *(s32 *)(__MCMNG + 0x23);
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 2:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if (v0 != 0) {
            goto _L00142950;
        }
        v0 = 1;
        __MCMNG[0x22] = 0;
        __MCMNG[0x26] = 0;
        goto _L001429C8;
        _L00142950:;
        a0 = *(s32 *)(__MCMNG + 0x27);
        v1 = 2;
        if (a0 == v1) {
            v1 = -2;
            __MCMNG[0x22] = 0;
            switch (v0) {
            case -2:
                v1 = 3;
                __MCMNG[0x26] = v1;
                break;
            default:
                v1 = 0x64;
                __MCMNG[0x26] = v1;
            }
            return v0;
        }
        v0 = a0 + 1;
        __MCMNG[0x27] = v0;
        v0 = *(s32 *)(__MCMNG + 0x23);
        v0 = v0 + -1;
        __MCMNG[0x23] = v0;
    }
    v0 = 0;
    _L001429C8:;
    return v0;
}







/* fsmc_MkDirFunc @ 0x1426F0 .. 0x142844 (0x154 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x142718 writes a register its branch at 0x142714 reads
 *   cfg: kept branch: 0x142750 if (..) goto .L00142798
 *   cfg: kept branch: 0x142764 if (..) goto .L00142788
 *   cfg: kept goto: 0x142774 -> .L00142838
 *   cfg: kept branch: 0x1427c8 if (..) goto .L001427E8
 *   cfg: kept goto: 0x1427d4 -> .L00142838
 *   cfg: kept branch: 0x1427e8 if (..) goto .L00142810
 *   cfg: kept goto: 0x1427fc -> .L00142838
 */



static signed int fsmc_MkDirFunc(void) {
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u8 stackFrame_1C[4] __attribute__((aligned(4)));

    v0 = 2;
    a0 = *(s32 *)(__MCMNG + 0x20);
    a1 = *(s32 *)(__MCMNG + 0x21);
    v1 = *(s32 *)(__MCMNG + 0x23);
    switch (v1) {
    case 0:
        v0 = v1 + 1;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        break;
    case 1:
        a2 = *(s32 *)(__MCMNG + 0x28);
        v0 = sceMcMkdir(a0, a1, (void *)a2);
        if (v0 == 0) {
            goto _L00142798;
        }
        v0 = 2;
        v1 = *(s32 *)(__MCMNG + 0x27);
        if (v1 != v0) {
            goto _L00142788;
        }
        v1 = 0x64;
        v0 = -0xa;
        __MCMNG[0x26] = v1;
        goto _L00142838;
        _L00142788:;
        v0 = v1 + 1;
        __MCMNG[0x27] = v0;
        break;
        _L00142798:;
        v0 = *(s32 *)(__MCMNG + 0x23);
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 2:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if (v0 != 0) {
            goto _L001427E8;
        }
        v0 = 1;
        __MCMNG[0x26] = 0;
        __MCMNG[0x22] = 0;
        goto _L00142838;
        _L001427E8:;
        a0 = *(s32 *)(__MCMNG + 0x27);
        v1 = 2;
        if (a0 != v1) {
            goto _L00142810;
        }
        v1 = 0x64;
        __MCMNG[0x22] = 0;
        __MCMNG[0x26] = v1;
        goto _L00142838;
        _L00142810:;
        v0 = a0 + 1;
        __MCMNG[0x27] = v0;
        v0 = *(s32 *)(__MCMNG + 0x23);
        v0 = v0 + -1;
        __MCMNG[0x23] = v0;
    }
    v0 = 0;
    _L00142838:;
    return v0;
}






/* fsmc_FileChkFunc @ 0x142530 .. 0x1426E4 (0x1b4 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x142638 writes a register its branch at 0x142634 reads
 *   cfg: kept branch: 0x142590 if (..) goto .L001425F0
 *   cfg: kept branch: 0x1425b0 if (..) goto .L001425E0
 *   cfg: kept goto: 0x1425c4 -> .L001426D8
 *   cfg: kept branch: 0x142620 if (..) goto .L00142698
 *   cfg: kept goto: 0x1426c0 -> .L001426D8
 */


static signed int fsmc_FileChkFunc(void) {
    s32 t0;
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u8 stackFrame_1C[4] __attribute__((aligned(4)));

    v0 = 2;
    a0 = *(s32 *)(__MCMNG + 0x20);
    a1 = *(s32 *)(__MCMNG + 0x21);
    v1 = *(s32 *)(__MCMNG + 0x23);
    t0 = 1;
    switch (v1) {
    case 0:
        v0 = v1 + 1;
        __MCMNG[0x23] = v0;
        __MCMNG[0x27] = 0;
        break;
    case 1:
        a2 = *(s32 *)(__MCMNG + 0x28);
        v0 = sceMcGetDir(a0, a1, (void *)a2, 0, t0, (void *)flchk);
        if (v0 == 0) {
            goto _L001425F0;
        }
        v0 = 2;
        v1 = *(s32 *)(__MCMNG + 0x27);
        if (v1 != v0) {
            goto _L001425E0;
        }
        v0 = 0x64;
        __MCMNG[0x22] = 0;
        __MCMNG[0x26] = v0;
        v0 = -1;
        goto _L001426D8;
        _L001425E0:;
        v0 = v1 + 1;
        __MCMNG[0x27] = v0;
        break;
        _L001425F0:;
        v0 = *(s32 *)(__MCMNG + 0x23);
        v0 = v0 + 1;
        __MCMNG[0x23] = v0;
        break;
    case 2:
        a0 = 1;
        v0 = sceMcSync(a0, (void *)0, (void *)((u8 *)&stackFrame_1C[0]));
        if (v0 == 0) {
            break;
        }
        v0 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        if ((s32)v0 >= 0) {
            goto _L00142698;
        }
        v1 = 2;
        a0 = *(s32 *)(__MCMNG + 0x27);
        v1 = -2;
        if (a0 == 2) {
            if (v0 == v1) {
                v1 = 3;
                __MCMNG[0x26] = v1;
            } else {
                v1 = 0x64;
                __MCMNG[0x26] = v1;
            }
            return v0;
        }
        v0 = a0 + 1;
        __MCMNG[0x27] = v0;
        v0 = *(s32 *)(__MCMNG + 0x23);
        v0 = v0 + -1;
        __MCMNG[0x23] = v0;
        break;
        _L00142698:;
        v1 = 0x2e;
        if ((s32)v0 > 0) {
            __MCMNG[0x26] = v1;
        }
        if (v0 == 0) {
            v0 = 0x2d;
            __MCMNG[0x26] = v0;
        }
        __MCMNG[0x22] = 0;
        v0 = 1;
        return v0;
    }
    v0 = 0;
    _L001426D8:;
    return v0;
}






























/* fsmc_GetFileInfo @ 0x1424A0 .. 0x142528 (0x88 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1424ac writes a register its branch at 0x1424a8 reads
 *   cfg: kept branch: 0x1424c4 if (..) goto .L001424D8
 *   cfg: kept goto: 0x1424d0 -> .L00142520
 *   cfg: kept branch: 0x1424e4 if (..) goto .L001424F8
 *   cfg: kept goto: 0x1424f0 -> .L00142520
 *   declaration vs inferred signature: return signed int vs inferred u8 *
 */




signed int fsmc_GetFileInfo(signed int a0 /* r4 */, signed int a1 /* r5 */) {
    u32 v0;

    v0 = *(s32 *)(__MCMNG + 0x22);
    if (v0 != 0) {
        v0 = 1;
        return v0;
    }
    if ((s32)a0 < (s32)3) {
        if ((s32)a0 >= 0) {
            goto _L001424D8;
        }
    }
    v0 = -1;
    goto _L00142520;
    _L001424D8:;
    if ((s32)a1 < (s32)5) {
        if ((s32)a1 >= 0) {
            goto _L001424F8;
        }
    }
    v0 = -1;
    goto _L00142520;
    _L001424F8:;
    __MCMNG[0x20] = a0;
    v0 = 3;
    __MCMNG[0x21] = a1;
    __MCMNG[0x22] = v0;
    v0 = 0;
    __MCMNG[0x23] = 0;
    _L00142520:;
    return v0;
}


/* fsmc_GetDir @ 0x1423F0 .. 0x142498 (0xa8 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1423fc writes a register its branch at 0x1423f8 reads
 *   cfg: kept branch: 0x142414 if (..) goto .L00142428
 *   cfg: kept goto: 0x142420 -> .L00142490
 *   cfg: kept branch: 0x142434 if (..) goto .L00142448
 *   cfg: kept goto: 0x142440 -> .L00142490
 *   declaration vs inferred signature: return signed int vs inferred u8 *
 */




signed int fsmc_GetDir(signed int a0 /* r4 */, signed int a1 /* r5 */, char *a2 /* r6 */, unsigned
        int a3 /* r7 */, unsigned int t0 /* r8 */, void *t1 /* r9 */) {
    u32 v0;

    v0 = *(s32 *)(__MCMNG + 0x22);
    if (v0 != 0) {
        v0 = 1;
        return v0;
    }
    if ((s32)a0 < (s32)3) {
        if ((s32)a0 >= 0) {
            goto _L00142428;
        }
    }
    v0 = -1;
    goto _L00142490;
    _L00142428:;
    if ((s32)a1 < (s32)5) {
        if ((s32)a1 >= 0) {
            goto _L00142448;
        }
    }
    v0 = -1;
    goto _L00142490;
    _L00142448:;
    __MCMNG[0x20] = a0;
    v0 = 4;
    __MCMNG[0x21] = a1;
    __MCMNG[0x22] = v0;
    v0 = 0;
    __MCMNG[0x28] = (u32)a2;
    __MCMNG[0x2a] = a3;
    __MCMNG[0x2b] = t0;
    __MCMNG[0x2c] = (u32)t1;
    __MCMNG[0x23] = 0;
    _L00142490:;
    return v0;
}


/* fsmc_DataWrite @ 0x142330 .. 0x1423E8 (0xb8 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x14233c writes a register its branch at 0x142338 reads
 *   cfg: kept branch: 0x142354 if (..) goto .L00142368
 *   cfg: kept goto: 0x142360 -> .L001423E0
 *   cfg: kept branch: 0x142374 if (..) goto .L00142388
 *   cfg: kept goto: 0x142380 -> .L001423E0
 *   declaration vs inferred signature: return signed int vs inferred u8 *
 */




signed int fsmc_DataWrite(signed int a0 /* r4 */, signed int a1 /* r5 */, char *a2 /* r6 */, void
        *a3 /* r7 */, unsigned int t0 /* r8 */) {
    u32 v0;

    v0 = *(s32 *)(__MCMNG + 0x22);
    if (v0 != 0) {
        v0 = 1;
        return v0;
    }
    if ((s32)a0 < (s32)3) {
        if ((s32)a0 >= 0) {
            goto _L00142368;
        }
    }
    v0 = -1;
    goto _L001423E0;
    _L00142368:;
    if ((s32)a1 < (s32)5) {
        if ((s32)a1 >= 0) {
            goto _L00142388;
        }
    }
    v0 = -1;
    goto _L001423E0;
    _L00142388:;
    __MCMNG[0x20] = a0;
    v0 = 5;
    __MCMNG[0x21] = a1;
    __MCMNG[0x22] = v0;
    v0 = 0;
    __MCMNG[0x28] = (u32)a2;
    __MCMNG[0x2e] = (u32)a3;
    __MCMNG[0x2a] = t0;
    __MCMNG[0x26] = 0x3c;
    __MCMNG[0x23] = 0;
    __MCMNG[0x24] = 0;
    _L001423E0:;
    return v0;
}


/* fsmc_DataRead @ 0x142270 .. 0x142328 (0xb8 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x14227c writes a register its branch at 0x142278 reads
 *   cfg: kept branch: 0x142294 if (..) goto .L001422A8
 *   cfg: kept goto: 0x1422a0 -> .L00142320
 *   cfg: kept branch: 0x1422b4 if (..) goto .L001422C8
 *   cfg: kept goto: 0x1422c0 -> .L00142320
 *   declaration vs inferred signature: return signed int vs inferred u8 *
 */




signed int fsmc_DataRead(signed int a0 /* r4 */, signed int a1 /* r5 */, char *a2 /* r6 */, void
        *a3 /* r7 */, unsigned int t0 /* r8 */) {
    u32 v0;

    v0 = *(s32 *)(__MCMNG + 0x22);
    if (v0 != 0) {
        v0 = 1;
        return v0;
    }
    if ((s32)a0 < (s32)3) {
        if ((s32)a0 >= 0) {
            goto _L001422A8;
        }
    }
    v0 = -1;
    goto _L00142320;
    _L001422A8:;
    if ((s32)a1 < (s32)5) {
        if ((s32)a1 >= 0) {
            goto _L001422C8;
        }
    }
    v0 = -1;
    goto _L00142320;
    _L001422C8:;
    __MCMNG[0x20] = a0;
    v0 = 6;
    __MCMNG[0x21] = a1;
    __MCMNG[0x22] = v0;
    v0 = 0;
    __MCMNG[0x28] = (u32)a2;
    __MCMNG[0x2d] = (u32)a3;
    __MCMNG[0x2a] = t0;
    __MCMNG[0x26] = 0x46;
    __MCMNG[0x24] = 0;
    __MCMNG[0x23] = 0;
    _L00142320:;
    return v0;
}


/* fsmc_IconWrite @ 0x1421B0 .. 0x142268 (0xb8 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1421bc writes a register its branch at 0x1421b8 reads
 *   cfg: kept branch: 0x1421d4 if (..) goto .L001421E8
 *   cfg: kept goto: 0x1421e0 -> .L00142260
 *   cfg: kept branch: 0x1421f4 if (..) goto .L00142208
 *   cfg: kept goto: 0x142200 -> .L00142260
 *   declaration vs inferred signature: return signed int vs inferred u8 *
 */




signed int fsmc_IconWrite(signed int a0 /* r4 */, signed int a1 /* r5 */, char *a2 /* r6 */, void
        *a3 /* r7 */, unsigned int t0 /* r8 */) {
    u32 v0;

    v0 = *(s32 *)(__MCMNG + 0x22);
    if (v0 != 0) {
        v0 = 1;
        return v0;
    }
    if ((s32)a0 < (s32)3) {
        if ((s32)a0 >= 0) {
            goto _L001421E8;
        }
    }
    v0 = -1;
    goto _L00142260;
    _L001421E8:;
    if ((s32)a1 < (s32)5) {
        if ((s32)a1 >= 0) {
            goto _L00142208;
        }
    }
    v0 = -1;
    goto _L00142260;
    _L00142208:;
    __MCMNG[0x20] = a0;
    v0 = 7;
    __MCMNG[0x21] = a1;
    __MCMNG[0x22] = v0;
    v0 = 0;
    __MCMNG[0x28] = (u32)a2;
    __MCMNG[0x2e] = (u32)a3;
    __MCMNG[0x2a] = t0;
    __MCMNG[0x26] = 0x3c;
    __MCMNG[0x24] = 0;
    __MCMNG[0x23] = 0;
    _L00142260:;
    return v0;
}


/* fsmc_Format @ 0x142110 .. 0x1421A8 (0x98 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x14211c writes a register its branch at 0x142118 reads
 *   cfg: kept branch: 0x142134 if (..) goto .L00142148
 *   cfg: kept goto: 0x142140 -> .L001421A0
 *   cfg: kept branch: 0x142154 if (..) goto .L00142168
 *   cfg: kept goto: 0x142160 -> .L001421A0
 *   declaration vs inferred signature: return signed int vs inferred u8 *
 */




signed int fsmc_Format(signed int a0 /* r4 */, signed int a1 /* r5 */) {
    u32 v0;

    v0 = *(s32 *)(__MCMNG + 0x22);
    if (v0 != 0) {
        v0 = 1;
        return v0;
    }
    if ((s32)a0 < (s32)3) {
        if ((s32)a0 >= 0) {
            goto _L00142148;
        }
    }
    v0 = -1;
    goto _L001421A0;
    _L00142148:;
    if ((s32)a1 < (s32)5) {
        if ((s32)a1 >= 0) {
            goto _L00142168;
        }
    }
    v0 = -1;
    goto _L001421A0;
    _L00142168:;
    __MCMNG[0x20] = a0;
    v0 = 9;
    __MCMNG[0x21] = a1;
    __MCMNG[0x22] = v0;
    v0 = 0x33;
    __MCMNG[0x26] = v0;
    v0 = 0;
    __MCMNG[0x23] = 0;
    _L001421A0:;
    return v0;
}








/* fsmc_MkDir @ 0x142080 .. 0x142110 (0x90 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x14208c writes a register its branch at 0x142088 reads
 *   cfg: kept branch: 0x1420a4 if (..) goto .L001420B8
 *   cfg: kept goto: 0x1420b0 -> .L00142108
 *   cfg: kept branch: 0x1420c4 if (..) goto .L001420D8
 *   cfg: kept goto: 0x1420d0 -> .L00142108
 *   declaration vs inferred signature: return signed int vs inferred u8 *
 */




signed int fsmc_MkDir(signed int a0 /* r4 */, signed int a1 /* r5 */, char *a2 /* r6 */) {
    u32 v0;

    v0 = *(s32 *)(__MCMNG + 0x22);
    if (v0 != 0) {
        v0 = 1;
        return v0;
    }
    if ((s32)a0 < (s32)3) {
        if ((s32)a0 >= 0) {
            goto _L001420B8;
        }
    }
    v0 = -1;
    goto _L00142108;
    _L001420B8:;
    if ((s32)a1 < (s32)5) {
        if ((s32)a1 >= 0) {
            goto _L001420D8;
        }
    }
    v0 = -1;
    goto _L00142108;
    _L001420D8:;
    __MCMNG[0x21] = a1;
    v0 = 0xb;
    __MCMNG[0x20] = a0;
    __MCMNG[0x22] = v0;
    v0 = 0;
    __MCMNG[0x28] = (u32)a2;
    __MCMNG[0x23] = 0;
    _L00142108:;
    return v0;
}


/* fsmc_FuncCheck @ 0x141F10 .. 0x14207C (0x16c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   literal: @1416 -> 0x253340
 *   indirect: jr v0 at 0x141f3c -> <v0>
 *   cfg: kept goto: 0x142008 -> .L00142070
 */


signed int fsmc_FuncCheck(void) {
    u32 v0;

    v0 = *(s32 *)(__MCMNG + 0x22);
    switch (v0) {
    case 3:
        v0 = fsmc_GetFileInfoFunc();
        break;
    case 4:
        v0 = fsmc_GetDirFunc();
        break;
    case 5:
        v0 = fsmc_DataWriteFunc();
        break;
    case 6:
        v0 = fsmc_DataReadFunc();
        break;
    case 7:
        v0 = fsmc_IconWriteFunc();
        break;
    case 8:
        v0 = fsmc_IconWriteFileFunc();
        break;
    case 9:
        v0 = fsmc_FormatFunc();
        break;
    case 10:
        v0 = fsmc_ChDirFunc();
        break;
    case 11:
        v0 = fsmc_MkDirFunc();
        break;
    case 12:
        v0 = fsmc_IconReadFunc();
        break;
    case 13:
        v0 = fsmc_FileChkFunc();
        break;
    case 14:
        v0 = fsmc_UnFormatFunc();
        break;
    case 0:
        return 0;
    case 1:
    case 2:
    default:
        v0 = -1;
    }
    if ((s32)v0 < 0) {
        v0 = *(s32 *)(__MCMNG + 0x22);
        v0 = -v0;
        __MCMNG[0x22] = 0;
        __MCMNG[0x23] = 0;
        if (v0 == 0) {
            v0 = -0x64;
        }
        return v0;
    }
    if ((s32)v0 > 0) {
        v0 = 0;
        __MCMNG[0x22] = 0;
        __MCMNG[0x23] = 0;
    } else {
        v0 = *(s32 *)(__MCMNG + 0x22);
    }
    return v0;
}


/* fsmc_Init @ 0x141E90 .. 0x141F04 (0x74 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u32 fsmc_Init(void) {
    u32 v0;

    v0 = sceMcInit();
    if (v0 == 0) {
        *(u32 *)((u8 *)&__MCMNG + 0x88) = 0;
        *(u32 *)((u8 *)&__MCMNG + 0x8c) = 0;
        *(u32 *)((u8 *)&__MCMNG + 0x60) = 0;
        *(u32 *)((u8 *)&__MCMNG + 0x70) = 0;
        *(u32 *)((u8 *)&__MCMNG + 0x64) = 0;
        *(u32 *)((u8 *)&__MCMNG + 0x74) = 0;
        *(u32 *)((u8 *)&__MCMNG + 0x68) = 0;
        *(u32 *)((u8 *)&__MCMNG + 0x78) = 0;
        *(u32 *)((u8 *)&__MCMNG + 0x6c) = 0;
        *(u32 *)((u8 *)&__MCMNG + 0x7c) = 0;
    }
    return;
}


/* fsmc_GetFreeMemory @ 0x141E10 .. 0x141E90 (0x80 bytes) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x141e30 if (..) goto .L00141E60
 *   declaration vs inferred signature: return signed int vs inferred u8 *
 */




signed int fsmc_GetFreeMemory(signed int a0 /* r4 */, signed int a1 /* r5 */) {
    u32 v1;
    u32 v0;

    a0 = (u32)a0 << 4;
    v0 = (u32)((u8 *)__MCMNG + 0x20);
    a1 = (u32)a1 << 2;
    v0 = v0 + (u32)(a0);
    v0 = (u32)(a1) + (u32)v0;
    v1 = *(s32 *)v0;
    if (v1 == 0) {
        v0 = (u32)__MCMNG;
        v0 = (s32)((u8 *)__MCMNG + a0);
        v0 = (u32)(a1) + (u32)v0;
        v0 = *(s32 *)v0;
        if (v0 != 0) {
            goto _L00141E60;
        }
        v1 = 1;
        v0 = -1;
        __MCMNG[0x26] = v1;
    } else {
        _L00141E60:;
        v0 = v1 + -2;
        if ((s32)v0 <= 0) {
            v1 = 0x1e;
            v0 = 0;
            __MCMNG[0x26] = v1;
        }
        __MCMNG[0x26] = 0;
    }
    return v0;
}


/* fsmc_GetDirPoints @ 0x141E00 .. 0x141E0C (0xc bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x141e08 computes the return value
 *   spans: lui at at 0x141e00 read at 0x141e08 before its %lo
 */


u32 fsmc_GetDirPoints(void) {
    return *(u32 *)((u8 *)&__MCMNG + 0x94);
}


/* fsmc_MessageCheck @ 0x141DF0 .. 0x141DFC (0xc bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x141df8 computes the return value
 *   spans: lui at at 0x141df0 read at 0x141df8 before its %lo
 */


u32 fsmc_MessageCheck(void) {
    return *(u32 *)((u8 *)&__MCMNG + 0x98);
}


static u32 __MCMNG[0x38]; /* +0x24 B unreferenced tail in the original */
static u8 rddata[0x420];
static u32 flchk[0x10];
