#include "common.h"
static u8 s_PrepareStatus __attribute__((aligned(4))) = 8;

/* SND_SqLoadSqFromFile @ 0x1AA5C0 .. 0x1AA5F4 (0x34 bytes, frame 0x10) */

extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);
extern u32 s_pSqReadAddr;

/* SND_SqVolSetValue @ 0x1AA600 .. 0x1AA668 (0x68 bytes) */
/*
 * dcomp notes:
 *   delay: slti at 0x1aa614 writes a register its branch at 0x1aa610 reads
 *   cfg: kept branch: 0x1aa60c if (..) goto .L001AA620
 */

extern u32 g_pSndMng;
static u8 s_Mng[9];

#ifndef PROTO_DW_1828594
#define PROTO_DW_1828594
struct dw_1828594 { unsigned char ucType; unsigned char ucVolume; unsigned char ucDelay; unsigned char ucFeedback; char cDmy[4]; };
#endif
#ifndef PROTO_DW_1828179
#define PROTO_DW_1828179
struct dw_1828179 { struct dw_1828594 Current; struct dw_1828594 Next; int Cmd; };
#endif

static u32 s_pSqReadAddr;
static u32 s_pFileInfo[3];
typedef struct VolRow { s16 volume; u8 pad2; s8 slot; u32 pad[2]; s32 fade; } VolRow;
extern int fssdsynthSqVolume(int, short);


/* SND_SqSetVolume @ 0x1AA8F0 .. 0x1AA91C (0x2c bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 g_pSndMng;

/* SND_SqPlay @ 0x1AA920 .. 0x1AAA1C */
extern signed int fssdsynthPlaySq(signed int, signed int, signed int);

/* SND_SqManageProc @ 0x1AAA20 .. 0x1AAB00 (0xe0 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   delay: and at 0x1aaab0 writes a register its branch at 0x1aaaac reads
 *   cfg: loop body is not one contiguous region: .L001AAA68
 */

extern u32 fssdsynthCheckSqEosAll(void);
extern void _VolSet(u8);
extern void SND_SqStop(u8);
extern int SND_SqPlay(u8, int);
static u8 s_Mng[9];

#ifndef PROTO_DW_1828594
#define PROTO_DW_1828594
struct dw_1828594 { unsigned char ucType; unsigned char ucVolume; unsigned char ucDelay; unsigned char ucFeedback; char cDmy[4]; };
#endif
#ifndef PROTO_DW_1828179
#define PROTO_DW_1828179
struct dw_1828179 { struct dw_1828594 Current; struct dw_1828594 Next; int Cmd; };
#endif
#ifndef PROTO_DW_1833784
#define PROTO_DW_1833784
struct dw_1833784 { short sCalcedVol; char bid; char sid; char PlayId; char reserv[3]; int sq_fade; int sq_vol; };
#endif

extern signed int fssdsynthStopSq(signed int);


/* SND_SqRemove @ 0x1AABB0 .. 0x1AAD4C (0x19c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: slti at 0x1aac0c writes a register its branch at 0x1aac08 reads
 *   cfg: loop body is not one contiguous region: .L001AABF8
 *   cfg: loop body is not one contiguous region: .L001AAC60
 */

extern signed int fssdsynthRemoveSq(signed int);
extern int sceGsSyncV(int);
extern signed int fssdsynthRemoveSqNoRelease(signed int);
extern signed int fssdsynthRemoveBank(signed int);

/* SND_SqPrepareStatus @ 0x1AAD50 .. 0x1AAF44 (0x1f4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @1313 -> 0x2552f0
 *   indirect: jr v0 at 0x1aadac -> <v0>
 *   delay: addiu at 0x1aadd4 writes a register its branch at 0x1aadd0 reads
 *   cfg: kept branch: 0x1aae2c if (..) goto .L001AAE48
 *   cfg: kept branch: 0x1aaecc if (..) goto .L001AAEE8
 */

extern void MemFree(void *);
extern int fssdsynthTransBankStatus(void);
extern signed int fssdsynthAddSqFromEE(signed int, signed int, char *, unsigned int);
extern signed int fssdsynthGetSqAddrOnIopMemory(signed int);
extern signed int fssdsynthAddSqFromIOP(signed int, signed int, char *, unsigned int);
extern signed int fssdsynthSifTransSync(void);
extern signed int fssdsynthGetTransStatus(signed int);
static u32 s_pFileInfo[3];
extern u32 L1313[];



/* SND_SqPrepare @ 0x1AAF50 .. 0x1AB06C (0x11c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1aaf6c writes a register its branch at 0x1aaf68 reads
 *   delay: addiu at 0x1aaf84 writes a register its branch at 0x1aaf80 reads
 *   cfg: loop body is not one contiguous region: .L001AAFA8
 *   a3 is the pointer held in s_pFileInfo+0x0
 *   v0 is the pointer held in s_pFileInfo+0x0
 */

extern signed int fssdsynthAddBankFromEE2(signed int, char *, unsigned int, char *, unsigned int,
    signed int);
static u32 s_pFileInfo[3];


/* SND_SqInit @ 0x1AB070 .. 0x1AB104 (0x94 bytes) */

static u8 s_Mng[9] = {0x0, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f};

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SND_SqInit(void);
void SND_SqPrepare(void);
signed int SND_SqPrepareStatus(void);
void SND_SqRemove(void);
void SND_SqStop(u8 index);
void SND_SqManageProc(void);
signed int SND_SqPlay(u8 a0, signed int a1);
void SND_SqSetVolume(signed int a0 );
void SND_SqFadeStart(int channel, int mode);
static void _VolSet(u8 channel);
void SND_SqVolSetValue(u8 a0 , s32 a1 );
void SND_SqLoadSqFromFile(char *a0 );


void SND_SqInit(void) {
    s32 t1;
    s32 t0;
    u32 a3;
    s32 a2;
    s32 a1;
    s32 a0;
    s32 v1;

    t1 = 0;
    *(u8 *)s_Mng = 0;
    t0 = 0;
    a2 = -1;
    a1 = 0x7f;
    a0 = 0x7fff;
    do {
        a3 = g_pSndMng;
        t1 = t1 + 1;
        v1 = (u32)t1 < (u32)4;
        a3 = a3 + t0;
        *(s8 *)((a3 + 0x73)) = a2;
        t0 = t0 + 0x10;
        *(s8 *)((a3 + 0x72)) = a2;
        *(u8 *)((a3 + 0x74)) = 0;
        *(u32 *)((a3 + 0x78)) = 0;
        *(u32 *)((a3 + 0x7c)) = a1;
        *(u16 *)((a3 + 0x70)) = a0;
    } while ((u32)v1 != 0);
    s_Mng[4] = a1;
    s_Mng[3] = a1;
    s_Mng[2] = a1;
    s_Mng[1] = a1;
    s_Mng[8] = a1;
    s_Mng[7] = a1;
    s_Mng[6] = a1;
    s_Mng[5] = a1;
    return;
}

void SND_SqPrepare(void) {
    u32 t0;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;

    a3 = s_pSqReadAddr;
    if (a3 != 0) {
        v1 = g_pSndMng;
        if (v1 == 0) {
            s_PrepareStatus = 8;
        } else {
            a0 = *(s32 *)((a3 + 8));
            v1 = 3;
            if (a0 != v1) {
                s_PrepareStatus = 8;
            } else {
                a2 = 0;
                if ((u8 *)0 < (u8 *)a0) {
                    a0 = a3 + 0x10;
                    a1 = (u32)s_pFileInfo;
                    do {
                        if (a2 == 0) {
                            *(u32 *)a1 = a0;
                        } else {
                            v0 = *(s32 *)((a1 + -4));
                            *(u32 *)a1 = v0 + 8;
                        }
                        v1 = *(s32 *)a1;
                        a2 = a2 + 1;
                        *(u32 *)v1 += a3;
                        v0 = *(s32 *)((a3 + 8));
                        v0 = a2 < v0;
                        a1 = a1 + 4;
                    } while (v0 != 0);
                }
                v1 = *(s32 *)(s_pFileInfo + 1);
                a3 = *(s32 *)v1;
                t0 = *(s32 *)((v1 + 4));
                a1 = *(s32 *)(u32)*(s32 *)s_pFileInfo;
                a2 = *(s32 *)(((u32)*(s32 *)s_pFileInfo + 4));
                v0 = fssdsynthAddBankFromEE2(0, (char *)a1, a2, (char *)a3, t0, 0);
                v1 = g_pSndMng;
                *(u8 *)((v1 + 0x72)) = v0;
                v1 = *(s8 *)((g_pSndMng + 0x72));
                if ((s32)v1 < 0 || (s32)v1 >= (s32)0x10) {
                    s_PrepareStatus = 8;
                } else {
                    *(u8 *)s_Mng = 0;
                    s_PrepareStatus = 0;
                }
            }
        }
    }
    return;
}

signed int SND_SqPrepareStatus(void) {
    u32 a3;
    u32 a2;
    s32 a1;
    u32 a0;
    u32 v1;
    u32 v0_2; // v0
    u32 v0_3; // v0
    u32 v0_4; // v0
    u32 v0_5; // v0
    u32 v0_6; // v0
    u32 v0;
    s32 s1;
    u8 *s0;

    v0 = 8;
    a0 = s_PrepareStatus;
    if (a0 == v0) {
        a0 = s_pSqReadAddr;
        if (a0 != 0) {
            MemFree((void *)a0);
            s_pSqReadAddr = 0;
        }
        v0 = 0;
    } else {
        switch (a0) {
        case 0:
            v0_6 = fssdsynthTransBankStatus();
            v1 = (u8)v0_6;
            if (v1 == 0) {
                break;
            }
            v0 = 2;
            if (v1 == v0) {
                v0 = 8;
                s_PrepareStatus = v0;
                break;
            } else {
                v0 = *(s8 *)&s_PrepareStatus;
                v0 = v0 + 1;
                s_PrepareStatus = v0;
                break;
            }
        case 1:
            v1 = *(s32 *)(s_pFileInfo + 2);
            v0 = g_pSndMng;
            a2 = *(s32 *)v1;
            a1 = *(s8 *)((v0 + 0x72));
            a3 = *(s32 *)((v1 + 4));
            v0_5 = fssdsynthAddSqFromEE(0, a1, (char *)a2, a3);
            v1 = g_pSndMng;
            *(u8 *)((v1 + 0x73)) = v0_5;
            v0 = *(s8 *)((g_pSndMng + 0x73));
            if (0 <= (s32)v0) {
                v0 = (s32)v0 < (s32)4;
                if (v0 != 0) {
                    goto _L001AAE48;
                }
            }
            v0 = 8;
            s_PrepareStatus = v0;
            break;
            _L001AAE48:;
            v0 = *(s8 *)&s_PrepareStatus;
            v0 = v0 + 1;
            s_PrepareStatus = v0;
            break;
        case 2:
        case 4:
        case 6:
            s1 = (s32)a0 / 2;
            v1 = g_pSndMng;
            v0 = (u32)s1 << 4;
            a0 = *(s8 *)((v1 + 0x73));
            v0 = v1 + (u32)v0;
            s0 = (u8 *)(s32)(v0 + 0x70);
            v0 = fssdsynthGetSqAddrOnIopMemory(a0);
            if (v0 == 0) {
                v0 = 8;
                s_PrepareStatus = v0;
                break;
            } else {
                v0_4 = fssdsynthAddSqFromIOP(s1, *(s8 *)(g_pSndMng + 0x72), (char *)v0, *(s32 *)(*(s32 *)(s_pFileInfo + 2) + 4));
                *(u8 *)(s0 + 3) = v0_4;
                v0 = *(s8 *)(s0 + 3);
                if (0 <= (s32)v0) {
                    v0 = (s32)v0 < (s32)4;
                    if (v0 != 0) {
                        goto _L001AAEE8;
                    }
                }
                v0 = 8;
                s_PrepareStatus = v0;
                break;
                _L001AAEE8:;
                v0 = *(s8 *)&s_PrepareStatus;
                v0 = v0 + 1;
                s_PrepareStatus = v0;
                break;
            }
        case 3:
        case 5:
        case 7:
            v0_2 = fssdsynthSifTransSync();
            a0 = 0;
            if (v0_2 == 0) {
                break;
            }
            v0_3 = fssdsynthGetTransStatus(0);
            if (v0_3 == 0) {
                break;
            }
            v0 = *(s8 *)&s_PrepareStatus;
            v0 = v0 + 1;
            s_PrepareStatus = v0;
        default:
            break;
        }
        v0 = 1;
    }
    return v0;
}

void SND_SqRemove(void) {
    u32 t1;
    u32 s0;
    u32 t0;
    u32 a3;
    s32 a2;
    s32 a1;
    u32 a0;
    u32 v1;

    v1 = g_pSndMng;
    if (v1 != 0) {
        s0 = 0;
        do {
            SND_SqStop(s0);
            s0 = s0 + 1;
        } while ((s32)s0 <= (s32)3);
        s0 = 0;
        do {
            v1 = g_pSndMng;
            a0 = *(s8 *)(((u32)(v1 + (u32)((u32)(((u8 *)(u8 *)0 + s0 * 0x10)))) + 0x73));
            if (0 <= (s32)a0) {
                if ((s32)a0 <= (s32)3) {
                    if (s0 == 0) {
                        fssdsynthRemoveSq(a0);
                        sceGsSyncV(0);
                        sceGsSyncV(0);
                    } else {
                        fssdsynthRemoveSqNoRelease(a0);
                    }
                }
            }
            s0 = s0 + 1;
            v1 = s0 < (u32)4;
        } while (v1 != 0);
        s0 = 0;
        do {
            v1 = g_pSndMng;
            a0 = *(s8 *)(((u32)(v1 + (u32)((u32)(((u8 *)(u8 *)0 + s0 * 0x10)))) + 0x72));
            if ((s32)a0 >= 0 && (s32)a0 <= (s32)0xf) {
                fssdsynthRemoveBank(a0);
                sceGsSyncV(0);
                sceGsSyncV(0);
            }
            s0 = s0 + 1;
            v1 = s0 < (u32)4;
        } while (v1 != 0);
        t1 = 0;
        *(u8 *)s_Mng = 0;
        t0 = 0;
        a2 = -1;
        a1 = 0x7f;
        a0 = 0x7fff;
        do {
            a3 = g_pSndMng;
            t1 = t1 + 1;
            v1 = t1 < (u32)4;
            a3 = a3 + t0;
            *(s8 *)((a3 + 0x73)) = a2;
            t0 = t0 + 0x10;
            *(s8 *)((a3 + 0x72)) = a2;
            *(u8 *)((a3 + 0x74)) = 0;
            *(u32 *)((a3 + 0x78)) = 0;
            *(u32 *)((a3 + 0x7c)) = a1;
            *(u16 *)((a3 + 0x70)) = a0;
        } while (v1 != 0);
        s_Mng[4] = a1;
        s_Mng[3] = a1;
        s_Mng[2] = a1;
        s_Mng[1] = a1;
        s_Mng[8] = a1;
        s_Mng[7] = a1;
        s_Mng[6] = a1;
        s_Mng[5] = a1;
    }
    return;
}
void SND_SqStop(u8 index) {
    s32 slot;
    u8 mask = 1;
    s32 i = index;
    if (0 <= i) {
        if (i <= 3) goto valid;
    }
    return;
valid:
    slot = g_pSndMng;
    i <<= 4;
    i += slot;
    slot = *(s8 *)(i + 0x73);
    if (0 <= slot) {
        if (slot < 4) goto active;
    }
    return;
active:
    mask <<= index;
    if (mask & *(u8 *)s_Mng) {
        fssdsynthStopSq(slot);
        *(u8 *)s_Mng &= (u8)~mask;
    }
}

void SND_SqManageProc(void) {
    u32 v1;
    u32 s4;
    u32 v0;
    u32 s3;
    struct dw_1833784 *s2;
    u32 s1;
    s32 s0;

    v1 = g_pSndMng;
    if (v1 != 0 && ((struct dw_1828179 *)&s_Mng)->Current.ucType != 0) {
        v0 = fssdsynthCheckSqEosAll();
        s3 = v0;
        s4 = 0;
        s1 = 0;
        do {
            v1 = g_pSndMng + s1;
            s2 = (struct dw_1833784 *)(s32)(v1 + 0x70);
            v1 = *(s8 *)((v1 + 0x73));
            if ((s32)v1 >= 0) {
                s0 = (u32)1 << s4;
                v1 = (u32)(((struct dw_1828179 *)&s_Mng)->Current.ucType) & s0;
                if (v1 != 0) {
                    _VolSet(s4);
                    v1 = ((struct dw_1828179 *)&s_Mng)->Current.ucType;
                    if ((u32)(v1 & s0) != 0 && (u32)(s3 & s0) == 0) {
                        SND_SqStop(s4);
                        SND_SqPlay((u8)s4, s2->PlayId);
                    }
                }
            }
            s4 = s4 + 1;
            v1 = s4 < (u32)4;
            s1 = s1 + 0x10;
        } while (v1 != 0);
    }
    return;
}

signed int SND_SqPlay(u8 a0, signed int a1) {
    u8 *entry;
    s32 ch;
    u32 mng;
    u8 vol;
    signed int result;

    mng = g_pSndMng;
    ch = (u8)(u32)a0;
    entry = (u8 *)(mng + ((u32)ch << 4) + 0x70);
    if (mng == 0) {
        result = 1;
        goto done;
    }
    if (0 <= (s32)ch && (s32)ch <= 3) goto body;
    result = 1;
    goto done;
body:
    if (fssdsynthPlaySq(*(s8 *)(entry + 3), a1, 1) == 0) {
        s_Mng[0] |= (u8)(1 << a0);
        *(u8 *)(entry + 4) = a1;
        vol = s_Mng[1 + ch];
        s_Mng[5 + ch] = vol;
        *(u32 *)(entry + 0xc) = vol;
        *(u32 *)(entry + 8) = 0;
        *(u16 *)entry = 0x7fff;
        _VolSet(a0);
        result = 0;
    } else {
        result = 1;
    }
done:
    return result;
}

void SND_SqSetVolume(signed int a0 /* r4 */) {
    u8 *v1;

    if ((s32)a0 < 0) {
        a0 = 0;
    }
    if ((s32)a0 > (s32)0x7f) {
        a0 = 0x7f;
    }
    v1 = (u8 *)g_pSndMng;
    *(u8 *)(((u8 *)v1 + 0x30)) = a0;
    return;
}


void SND_SqFadeStart(int channel, int mode) {
    int fade;
    unsigned int index;
    unsigned int manager;
    int one;
    unsigned int bits;
    manager = g_pSndMng;
    fade = 2;
    if (manager != 0) {
        index = (u8)channel;
        if (0 <= (int)index) {
            if ((int)index <= 3) goto valid;
        }
        return;
valid:
        channel = s_Mng[0];
        one = 1;
        bits = channel & ((unsigned int)one << index);
        if (bits != 0) {
            bits = (u8)mode;
            switch (bits) {
            case 0:
                bits = (u32)(s_Mng + 5);
                fade *= -1;
                *(u8 *)(bits + index) = one;
                break;
            case 2:
                bits = index << 4;
                channel = bits + manager;
                *(u32 *)(channel + 0x7c) = one;
                bits = (u32)(s_Mng + 1);
                bits += index;
                channel = *(u8 *)bits;
                bits = (u32)(s_Mng + 5);
                *(u8 *)(bits + index) = channel;
                break;
            default:
                return;
            }
            __asm__ volatile(
                ".set noreorder\n"
                "lw $4, g_pSndMng\n"
                "sll $3, %0, 4\n"
                "addu $3, $3, $4\n"
                "sw %1, 0x78($3)\n"
                ".set reorder\n"
                :
                : "r"(index), "r"(fade)
                : "$3", "$4", "memory");
        }
    }
}
static void _VolSet(u8 channel) {
    unsigned int index;
    unsigned int manager;
    VolRow *row;
    u8 *target;
    int current;
    unsigned int result;
    float volume;
    index = (u8)channel;
    manager = g_pSndMng;
    row = (VolRow *)(manager + (index << 4) + 0x70);
    if (manager != 0) {
        if (0 <= (int)index) {
            if ((int)index <= 3) goto valid;
        }
        return;
valid:
        if (s_Mng[0] & (1U << index)) {
            current = row->fade;
            target = (u8 *)((u32)(s_Mng + 5) + index);
            if (*target < current) {
                row->fade = current - 2;
                if (row->fade < *target) row->fade = *target;
            } else if (current < *target) {
                row->fade = current + 2;
                if (*target < row->fade) row->fade = *target;
            }
            volume = (float)row->fade * (float)(u32)*(u8 *)(g_pSndMng + 0x30);
            result = (u32)((127.0f * (volume / 127.0f)) / 127.0f);
            result = (s16)(u8)result;
            if (row->volume != result) {
                row->volume = result;
                fssdsynthSqVolume(row->slot, row->volume);
            }
        }
    }
}

void SND_SqVolSetValue(u8 a0 /* r4 */, s32 a1 /* r5 */) {
    u32 a0_word = a0;
    u32 a2;
    u32 v1;

    v1 = g_pSndMng;
    a2 = (u8)a0_word;
    if (v1 != 0) {
        if (0 > (s32)a2) {
            goto _L001AA620;
        }
        if ((s32)a2 > (s32)3) {
            _L001AA620:;
            return;
        }
        a0_word = ((struct dw_1828179 *)&s_Mng)->Current.ucType;
        v1 = a0_word & (s32)((u32)1 << a2);
        if (v1 != 0) {
            a0_word = (u32)(u8 *)(s_Mng + 1);
            a0_word = a0_word + a2;
            *(u8 *)a0_word = a1;
            *(u8 *)(s32)((u8 *)(u8 *)(s_Mng + 5) + a2) = a1;
        }
    }
    return;
}

void SND_SqLoadSqFromFile(char *a0 /* r4 */) {
    if ((u32)a0 != 0) {
        FileRead(a0, (s32)-1, (unsigned char **)&s_pSqReadAddr, 0, 0, (s32)0x18, (s32)0x40);
    }
    return;
}
