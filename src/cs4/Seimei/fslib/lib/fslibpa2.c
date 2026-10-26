#include "common.h"

/* fspad_PadSetAnalogEdgeMode @ 0x146980 .. 0x1469AC (0x2c bytes) */

extern u8 __PADMNG[];

/* fspad_PadSetVibraSepMode @ 0x146A00 .. 0x146A28 (0x28 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u8 __PADMNG[];

/* fspad_PadSetSmallVibra @ 0x146A30 .. 0x146A68 (0x38 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u8 __PADMNG[];



struct dw_304279 {
    u8 bytes[4];
};


/* fspad_PadRead @ 0x146B30 .. 0x146B58 (0x28 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x146b54 computes the return value
 */

extern u8 __PADMNG[];

/* _fspad_SetButtonData @ 0x147680 .. 0x14799C (0x31c bytes, frame 0x60) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1476dc writes a register its branch at 0x1476d8 reads
 *   stack: address of the slot at 0x30 escapes at 0x1476f8
 *   cfg: kept goto: 0x1476b4 -> .L00147988
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

struct B36 { s16 h[18]; };
extern int scePadRead(int, int, void *);


extern int scePadGetState(int, int);
extern int scePadGetReqState(int, int);
extern int scePadInfoMode(int, int, int, int);
extern int scePadInfoAct(int, int, int, int);
extern int scePadInfoPressMode(int, int);
extern int scePadSetMainMode(int, int, int, int);
extern int scePadEnterPressMode(int, int);
extern int scePadExitPressMode(int, int);
extern int scePadSetActAlign(int, int, void *);
extern int scePadSetActDirect(int, int, void *);
static signed int _fspad_SetButtonData(void *a0 , signed int a1 , signed int a2 );
static signed int _fspad_SetButtonData(void *a0, signed int a1, signed int a2);
static void _fspad_SetRepeatData(void *a0 );
static void _fspad_SetRepeatData(void *a0);

struct FSPAD_SDATA {
    unsigned int work[16];
    unsigned char _gap0[192];
    unsigned char success;
    unsigned char data_len;
    unsigned short button;
    unsigned char r3h;
    unsigned char r3v;
    unsigned char l3h;
    unsigned char l3v;
    unsigned char apress[12];
    unsigned char press[12];
    unsigned short edge;
    unsigned short repeat;
    unsigned char key[16][4];
    unsigned short repeat_key;
    unsigned short sdummy;
    int state;
    int req_state;
    int act_no;
    unsigned char act_data[6];
    unsigned char phase;
    unsigned char ret_phase;
    unsigned char term_id;
    unsigned char type;
    unsigned char mode;
    unsigned char modechg;
    unsigned char modelock;
    unsigned char sent_align;
    unsigned char vibrasep_mode;
    unsigned char analog_edge;
    unsigned char cdummy;
    unsigned char _gap1[59];
};

struct FSPAD_MNG {
    struct FSPAD_SDATA sdata[8];
    unsigned char open[2];
};


/* fspad_PadPortOpen @ 0x1473D0 .. 0x147418 (0x48 bytes) */
/*
 * dcomp notes:
 *   tail: j scePadPortOpen at 0x147410 leaves the function
 *   declaration vs inferred signature: return signed int vs inferred void
 */

extern int scePadPortOpen(int, int, void *);

/* fspad_PadInit @ 0x147420 .. 0x1475B4 (0x194 bytes) */
/*
 * dcomp notes:
 *   tail: j scePadInit at 0x1475ac leaves the function
 *   a0 forwarded to scePadInit
 *   declaration vs inferred signature: return signed int vs inferred void
 */

extern int scePadInit(int);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
static signed int _fspad_SetButtonData(void *a0 , signed int a1 , signed int a2 );
static void _fspad_SetRepeatData(void *a0 );
signed int fspad_PadInit(signed int a0 );
signed int fspad_PadPortOpen(signed int a0 , signed int a1 );
void fspad_PadUpdate(void);
u32 fspad_PadRead(s32 a0 , s32 a1 );
void fspad_PadSetRepeat(s32 port, s32 slot, u32 key, u16 delay, u16 interval);
void fspad_PadSetVibra(signed int a0 , signed int a1 , unsigned char a2 );
u32 fspad_PadSetSmallVibra(u8 *a0 , s32 a1 , s32 a2 );
u32 fspad_PadSetVibraSepMode(s32 a0 , s32 a1 , s32 a2 );
signed int fspad_PadModeAnalog(signed int a0 , signed int a1 , signed int a2 );
u32 fspad_PadSetAnalogEdgeMode(s32 a0 , s32 a1 , s32 a2 );


static signed int _fspad_SetButtonData(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /*
        r6 */) {
    u8 *s0;
    u32 s1;
    signed int a2_2; // a2
    s32 v1;
    u64 v0_64;
    u32 v0;
    u8 stackFrame_30[48] __attribute__((aligned(16)));

    s1 = *(u8 *)(((u8 *)a0 + 0x17c));
    s0 = (u8 *)a0;
    a0 = (void *)(s32)a1;
    a1 = a2;
    v0 = scePadRead((int)a0, a1, (void *)((u8 *)&stackFrame_30[0]));
    if (v0 == 0) {
        v0 = 0;
        goto _L00147988;
    }
    v0 = *(u8 *)((u8 *)&stackFrame_30[0]);
    if (v0 == 0) {
        v0 = ((u8 *)stackFrame_30)[1];
        v0 = (s32)v0 >> 4;
        *(u8 *)(s0 + 0x17c) = v0;
        if (s1 != 0) {
            v0 = *(u8 *)(s0 + 0x17c);
            if (v0 != s1) {
                v0 = -1;
                return v0;
            }
        }
        *(struct B36 *)(s0 + 0x100) = *(struct B36 *)stackFrame_30;
        v0 = *(u16 *)(s0 + 0x102);
        v0 = ~v0;
        *(u16 *)(s0 + 0x102) = v0;
        v0 = *(u8 *)(s0 + 0x183);
        if (v0 != 0) {
            v0 = (u8)v0;
            v0 = v0 & 1;
            if (v0 != 0) {
                v0 = *(u16 *)(s0 + 0x102);
                v0 = v0 & 0xf0;
                if (v0 != 0) {
                    v0 = *(u8 *)(s0 + 0x102);
                    v0_64 = (u64)v0 << 0x38 >> 0x3f;
                    if (v0_64 != 0) {
                        *(u8 *)(s0 + 0x106) = 0;
                    }
                    v0 = *(u8 *)(s0 + 0x102);
                    v0_64 = (u64)v0 << 0x3a >> 0x3f;
                    v0 = 0xff;
                    if (v0_64 != 0) {
                        *(u8 *)(s0 + 0x106) = v0;
                    }
                    v0 = *(u8 *)(s0 + 0x102);
                    v0_64 = (u64)v0 << 0x3b >> 0x3f;
                    if (v0_64 != 0) {
                        *(u8 *)(s0 + 0x107) = 0;
                    }
                    v0 = *(u8 *)(s0 + 0x102);
                    v0_64 = (u64)v0 << 0x39 >> 0x3f;
                    v0 = 0xff;
                    if (v0_64 != 0) {
                        *(u8 *)(s0 + 0x107) = v0;
                    }
                } else {
                    v0 = *(u8 *)(s0 + 0x106);
                    if ((s32)v0 <= (s32)0xe) {
                        v1 = 0x80;
                        ((struct { unsigned char _pad:7; unsigned char f:1; } *)&*(u8 *)(s0 +
                            0x102))->f = 1;
                    }
                    v0 = *(u8 *)(s0 + 0x106);
                    if ((s32)v0 > (s32)0xf0) {
                        v1 = 0x20;
                        ((struct { unsigned char _pad:5; unsigned char f:1; } *)&*(u8 *)(s0 +
                            0x102))->f = 1;
                    }
                    v0 = *(u8 *)(s0 + 0x107);
                    if ((s32)v0 <= (s32)0xe) {
                        v1 = 0x10;
                        ((struct { unsigned char _pad:4; unsigned char f:1; } *)&*(u8 *)(s0 +
                            0x102))->f = 1;
                    }
                    v0 = *(u8 *)(s0 + 0x107);
                    if ((s32)v0 > (s32)0xf0) {
                        v1 = 0x40;
                        ((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 +
                            0x102))->f = 1;
                    }
                }
            }
            v0 = *(u8 *)(s0 + 0x183);
            v0 = v0 & 2;
            if (v0 != 0) {
                v0 = *(u16 *)(s0 + 0x102);
                v0 = v0 & 0xf000;
                if (v0 != 0) {
                    v0 = *(u8 *)(s0 + 0x103);
                    v0_64 = (u64)v0 << 0x38 >> 0x3f;
                    if (v0_64 != 0) {
                        *(u8 *)(s0 + 0x104) = 0;
                    }
                    v0 = *(u8 *)(s0 + 0x103);
                    v0_64 = (u64)v0 << 0x39 >> 0x3f;
                    v0 = 0xff;
                    if (v0_64 != 0) {
                        *(u8 *)(s0 + 0x104) = v0;
                    }
                    v0 = *(u8 *)(s0 + 0x103);
                    v0_64 = (u64)v0 << 0x3b >> 0x3f;
                    if (v0_64 != 0) {
                        *(u8 *)(s0 + 0x105) = 0;
                    }
                    v0 = *(u8 *)(s0 + 0x103);
                    v0_64 = (u64)v0 << 0x3a >> 0x3f;
                    v0 = 0xff;
                    if (v0_64 != 0) {
                        *(u8 *)(s0 + 0x105) = v0;
                    }
                } else {
                    v0 = *(u8 *)(s0 + 0x104);
                    if ((s32)v0 <= (s32)0xe) {
                        v1 = 0x80;
                        ((struct { unsigned char _pad:7; unsigned char f:1; } *)&*(u8 *)(s0 +
                            0x103))->f = 1;
                    }
                    v0 = *(u8 *)(s0 + 0x104);
                    if ((s32)v0 > (s32)0xf0) {
                        v1 = 0x40;
                        ((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(s0 +
                            0x103))->f = 1;
                    }
                    v0 = *(u8 *)(s0 + 0x105);
                    if ((s32)v0 <= (s32)0xe) {
                        v1 = 0x10;
                        ((struct { unsigned char _pad:4; unsigned char f:1; } *)&*(u8 *)(s0 +
                            0x103))->f = 1;
                    }
                    v0 = *(u8 *)(s0 + 0x105);
                    if ((s32)v0 > (s32)0xf0) {
                        v1 = 0x20;
                        ((struct { unsigned char _pad:5; unsigned char f:1; } *)&*(u8 *)(s0 +
                            0x103))->f = 1;
                    }
                }
            }
        }
    }
    v0 = 1;
    _L00147988:;
    return v0;
}

/* _fspad_SetRepeatData @ 0x1475C0 .. 0x147680 (0xc0 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001475D8
 *   declaration vs inferred signature: return void vs inferred u32
 */

static void _fspad_SetRepeatData(void *a0 /* r4 */) {
    u8 *t2;
    s32 t1;
    u8 *t0;
    s32 a3;
    u16 a2;
    s32 a1;
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    *(u16 *)(a0_bytes + 0x122) = 0;
    t1 = 0;
    t0 = a0_bytes;
    a1 = 2;
    a3 = 1;
    do {
        v1 = (u32)a3 << (u32)t1;
        a2 = v1;
        v1 = *(u16 *)(a0_bytes + 0x164);
        v1 = v1 & (u32)(a2);
        if (v1 != 0) {
            v1 = *(u16 *)(a0_bytes + 0x102);
            v1 = v1 & (u32)(a2);
            t2 = (u8 *)(t0 + 0x124);
            if (v1 == 0) {
                *(u8 *)(t2 + 3) = 0;
            } else {
                v1 = *(u16 *)(a0_bytes + 0x120);
                v1 = v1 & (u32)(a2);
                if (v1 != 0) {
                    v1 = *(u16 *)(a0_bytes + 0x122);
                    *(u16 *)(a0_bytes + 0x122) = v1 | (u32)(a2);
                    *(u8 *)(t2 + 3) = a3;
                    v1 = *(u8 *)t2;
                    *(u8 *)(t2 + 2) = v1;
                } else {
                    v1 = *(u8 *)(t2 + 2);
                    v1 = v1 + -1;
                    *(u8 *)(t2 + 2) = v1;
                    v1 = (u8)v1;
                    if ((s32)v1 <= 0) {
                        v1 = *(u16 *)(a0_bytes + 0x122);
                        *(u16 *)(a0_bytes + 0x122) = v1 | (u32)(a2);
                        *(u8 *)(t2 + 3) = a1;
                        v1 = *(u8 *)(t2 + 1);
                        *(u8 *)(t2 + 2) = v1;
                    }
                }
            }
        }
        t1 = t1 + 1;
        v1 = t1 < (s32)0x10;
        t0 = (u8 *)(t0 + 4);
    } while (v1 != 0);
    return;
}

signed int fspad_PadInit(signed int a0 /* r4 */) {
    u8 *t2;
    u8 *t1;
    u8 *t0;
    u8 *a3;
    u8 *a2;
    u8 *a1;
    u8 *v1;
    s32 v0;

    __PADMNG[0xe00] = 0;
    __PADMNG[0xe01] = 0;
    *(u16 *)(__PADMNG + 0x120) = 0;
    *(u16 *)(__PADMNG + 0x122) = 0;
    v0 = 0xff;
    t2 = (u8 *)(__PADMNG + 0x1c0);
    *(u16 *)(__PADMNG + 0x164) = 0;
    v1 = (u8 *)(__PADMNG + 0x380);
    a1 = (u8 *)(__PADMNG + 0x540);
    __PADMNG[0x17a] = 0;
    a2 = (u8 *)(__PADMNG + 0x700);
    a3 = (u8 *)(__PADMNG + 0x8c0);
    __PADMNG[0x17c] = 0;
    __PADMNG[0x17e] = v0;
    t0 = (u8 *)(__PADMNG + 0xa80);
    t1 = (u8 *)(__PADMNG + 0xc40);
    __PADMNG[0x17f] = v0;
    __PADMNG[0x180] = 0;
    __PADMNG[0x182] = 0;
    *(u16 *)(t2 + 0x120) = 0;
    *(u16 *)(t2 + 0x122) = 0;
    *(u16 *)(t2 + 0x164) = 0;
    *(u8 *)(t2 + 0x17a) = 0;
    *(u8 *)(t2 + 0x17c) = 0;
    *(u8 *)(t2 + 0x17e) = v0;
    *(u8 *)(t2 + 0x17f) = v0;
    *(u8 *)(t2 + 0x180) = 0;
    *(u8 *)(t2 + 0x182) = 0;
    *(u16 *)(v1 + 0x120) = 0;
    *(u16 *)(v1 + 0x122) = 0;
    *(u16 *)(v1 + 0x164) = 0;
    *(u8 *)(v1 + 0x17a) = 0;
    *(u8 *)(v1 + 0x17c) = 0;
    *(u8 *)(v1 + 0x17e) = v0;
    *(u8 *)(v1 + 0x17f) = v0;
    *(u8 *)(v1 + 0x180) = 0;
    *(u8 *)(v1 + 0x182) = 0;
    *(u16 *)(a1 + 0x120) = 0;
    *(u16 *)(a1 + 0x122) = 0;
    *(u16 *)(a1 + 0x164) = 0;
    *(u8 *)(a1 + 0x17a) = 0;
    *(u8 *)(a1 + 0x17c) = 0;
    *(u8 *)(a1 + 0x17e) = v0;
    *(u8 *)(a1 + 0x17f) = v0;
    *(u8 *)(a1 + 0x180) = 0;
    *(u8 *)(a1 + 0x182) = 0;
    *(u16 *)(a2 + 0x120) = 0;
    *(u16 *)(a2 + 0x122) = 0;
    *(u16 *)(a2 + 0x164) = 0;
    *(u8 *)(a2 + 0x17a) = 0;
    *(u8 *)(a2 + 0x17c) = 0;
    *(u8 *)(a2 + 0x17e) = v0;
    *(u8 *)(a2 + 0x17f) = v0;
    *(u8 *)(a2 + 0x180) = 0;
    *(u8 *)(a2 + 0x182) = 0;
    *(u16 *)(a3 + 0x120) = 0;
    *(u16 *)(a3 + 0x122) = 0;
    *(u16 *)(a3 + 0x164) = 0;
    *(u8 *)(a3 + 0x17a) = 0;
    *(u8 *)(a3 + 0x17c) = 0;
    *(u8 *)(a3 + 0x17e) = v0;
    *(u8 *)(a3 + 0x17f) = v0;
    *(u8 *)(a3 + 0x180) = 0;
    *(u8 *)(a3 + 0x182) = 0;
    *(u16 *)(t0 + 0x120) = 0;
    *(u16 *)(t0 + 0x122) = 0;
    *(u16 *)(t0 + 0x164) = 0;
    *(u8 *)(t0 + 0x17a) = 0;
    *(u8 *)(t0 + 0x17c) = 0;
    *(u8 *)(t0 + 0x17e) = v0;
    *(u8 *)(t0 + 0x17f) = v0;
    *(u8 *)(t0 + 0x180) = 0;
    *(u8 *)(t0 + 0x182) = 0;
    *(u16 *)(t1 + 0x120) = 0;
    *(u16 *)(t1 + 0x122) = 0;
    *(u16 *)(t1 + 0x164) = 0;
    *(u8 *)(t1 + 0x17a) = 0;
    *(u8 *)(t1 + 0x17c) = 0;
    *(u8 *)(t1 + 0x17e) = v0;
    *(u8 *)(t1 + 0x17f) = v0;
    *(u8 *)(t1 + 0x180) = 0;
    *(u8 *)(t1 + 0x182) = 0;
    return scePadInit(a0);
}

signed int fspad_PadPortOpen(signed int a0 /* r4 */, signed int a1 /* r5 */) {
    u8 *t0;
    u32 v0;

    t0 = (u8 *)(s32)((u32)(u8 *)(__PADMNG + 0xe00) + (u32)(a0));
    v0 = (u32)__PADMNG;
    *(u8 *)t0 |= (u32)(u8)((u32)1 << (u32)a1);
    return scePadPortOpen(a0, a1, (void *)((u8 *)__PADMNG + (u32)((u32)((u32)(a1) + (u32)((u32)a0
        << 2)) * (u32)(0x1c0))));
}

void fspad_PadUpdate(void) {
    struct FSPAD_SDATA *sdp;
    int port;
    int slot;
    unsigned short opad;
    int id;
    int exid;
    int i;
    unsigned char data[6];
    int result;

    for (port = 0; port < 2; port++) {
        for (slot = 0; slot < 4; slot++) {
            if (!(((struct FSPAD_MNG *)__PADMNG)->open[port] & (1 << slot))) {
                continue;
            }
            sdp = &((struct FSPAD_MNG *)__PADMNG)->sdata[port * 4 + slot];
            sdp->state = scePadGetState(port, slot);
            if (sdp->state == 0) {
                sdp->phase = 0;
            }
            sdp->req_state = scePadGetReqState(port, slot);
            switch (sdp->phase) {
            case 0:
                sdp->mode = 0xff;
                if (sdp->state == 0) {
                    break;
                }
                id = scePadInfoMode(port, slot, 1, 0);
                if (id == 0) {
                    break;
                }
                exid = scePadInfoMode(port, slot, 2, 0);
                if (exid > 0) {
                    id = exid;
                }
                sdp->type = 0;
                sdp->sent_align = 0;
                switch (id) {
                case 2:
                case 3:
                case 5:
                case 6:
                case 0x100:
                case 0x300:
                    break;
                case 4:
                    sdp->phase = 40;
                    break;
                case 7:
                    sdp->phase = 70;
                    break;
                }
                break;
            case 40:
            case 70:
                if (sdp->phase == 40) {
                    if (scePadInfoMode(port, slot, 4, -1)) {
                        sdp->type |= 1;
                    }
                } else {
                    sdp->type |= 1;
                }
                if ((sdp->act_no = scePadInfoAct(port, slot, -1, 0)) != 0) {
                    sdp->type |= 2;
                }
                if (scePadInfoPressMode(port, slot) == 1) {
                    sdp->type |= 4;
                }
                if ((sdp->type & 1) && (sdp->modechg == 1 || sdp->modechg == 2)) {
                    sdp->phase = 110;
                    break;
                }
                if (sdp->modechg == 0) {
                    sdp->phase = 100;
                    break;
                }
                if (sdp->phase == 40) {
                    sdp->phase = 0xfd;
                } else {
                    sdp->phase = 0xfe;
                }
                break;
            case 100:
                if (scePadSetMainMode(port, slot, 0, sdp->modelock) == 1) {
                    sdp->phase = 101;
                }
                break;
            case 101:
                if (sdp->req_state == 1) {
                    sdp->phase = 100;
                }
                if (sdp->req_state == 0 && (sdp->state == 6 || sdp->state == 2)) {
                    sdp->sent_align = 0;
                    sdp->phase = 0xfd;
                }
                break;
            case 110:
                if (scePadSetMainMode(port, slot, 1, sdp->modelock) == 1) {
                    sdp->phase = 111;
                }
                break;
            case 111:
                if (sdp->req_state == 1) {
                    sdp->phase = 110;
                }
                if (sdp->req_state == 0 && (sdp->state == 6 || sdp->state == 2)) {
                    sdp->sent_align = 0;
                    if (scePadInfoPressMode(port, slot) == 1) {
                        sdp->type |= 4;
                    }
                    sdp->phase = 0xfe;
                }
                break;
            case 120:
                if (scePadEnterPressMode(port, slot) == 1) {
                    sdp->phase = 121;
                }
                break;
            case 121:
                if (sdp->req_state == 1) {
                    sdp->phase = 120;
                }
                if (sdp->req_state == 0 && (sdp->state == 6 || sdp->state == 2)) {
                    sdp->phase = 0xff;
                }
                break;
            case 130:
                if (scePadExitPressMode(port, slot) == 1) {
                    sdp->phase = 131;
                }
                break;
            case 131:
                if (sdp->req_state == 1) {
                    sdp->phase = 130;
                }
                if (sdp->req_state == 0 && (sdp->state == 6 || sdp->state == 2)) {
                    sdp->phase = 0xfe;
                }
                break;
            case 200:
                for (i = 0; i < 6; i++) {
                    data[i] = 0xff;
                    sdp->act_data[i] = 0;
                }
                for (i = 0; i < sdp->act_no; i++) {
                    data[i] = i;
                }
                if (scePadSetActAlign(port, slot, data) == 1) {
                    sdp->phase++;
                }
                break;
            case 201:
                if (sdp->req_state == 1) {
                    sdp->phase--;
                }
                if (sdp->req_state == 0) {
                    sdp->sent_align = 1;
                    sdp->phase = sdp->ret_phase;
                }
                break;
            case 0xff:
                if (sdp->modechg == 2) {
                    sdp->modechg = 0xff;
                }
                if (sdp->modechg == 0 || sdp->modechg == 1) {
                    sdp->mode = 0xff;
                    sdp->phase = 130;
                    break;
                }
                sdp->mode = 2;
                if (sdp->sent_align == 0 && (sdp->type & 2)) {
                    sdp->ret_phase = sdp->phase;
                    sdp->phase = 200;
                    break;
                }
                goto read;
            case 0xfe:
                if (scePadInfoMode(port, slot, 1, 0) == 4 && sdp->modelock == 3) {
                    sdp->modechg = 1;
                    sdp->mode = 0xff;
                    sdp->phase = 0;
                    break;
                }
                if (sdp->modechg == 1) {
                    sdp->modechg = 0xff;
                }
                if (sdp->modechg == 0) {
                    sdp->mode = 0xff;
                    sdp->phase = 0;
                    break;
                }
                if (sdp->modechg == 2 && (sdp->type & 4)) {
                    sdp->mode = 0xff;
                    sdp->phase = 120;
                    break;
                }
                sdp->mode = 1;
                if (sdp->sent_align == 0 && (sdp->type & 2)) {
                    sdp->ret_phase = sdp->phase;
                    sdp->phase = 200;
                    break;
                }
                goto read;
            case 0xfd:
                if (sdp->modechg == 0) {
                    sdp->modechg = 0xff;
                }
                if (sdp->modechg == 1 || sdp->modechg == 2) {
                    sdp->mode = 0xff;
                    sdp->phase = 0;
                    break;
                }
                sdp->mode = 0;
                if (sdp->sent_align == 0 && (sdp->type & 2)) {
                    sdp->ret_phase = sdp->phase;
                    sdp->phase = 200;
                    break;
                }
            read:
                opad = sdp->button;
                result = _fspad_SetButtonData(sdp, port, slot);
                if (result == 0) {
                    break;
                }
                if (result == -1) {
                    sdp->phase = 0;
                }
                sdp->edge = sdp->button & ~opad;
                _fspad_SetRepeatData(sdp);
                if ((sdp->type & 2) && sdp->state == 6) {
                    scePadSetActDirect(port, slot, sdp->act_data);
                }
                break;
            }
        }
    }
}

u32 fspad_PadRead(s32 a0 /* r4 */, s32 a1 /* r5 */) {
    u32 v0;
    u32 v1;

    v0 = (u32)a0 << 2;
    a0 = a1 + v0;
    v1 = (u32)a0 << 3;
    v1 = v1 - a0;
    v0 = (u32)__PADMNG;
    v1 = (u32)v1 << 6;
    v0 = (u32)((u8 *)__PADMNG + v1);
    return v0 + 0x100;
}

void fspad_PadSetRepeat(s32 port, s32 slot, u32 key, u16 delay, u16 interval) {
    s32 ct;
    struct dw_304279 *sdp;
    u32 key_mask;
    u32 flags;

    ct = 0;
    sdp = (struct dw_304279 *)((u8 *)__PADMNG + (u32)(slot + (port << 2)) * 0x1c0);
    flags = *(u16 *)((u8 *)sdp + 0x164);
    *(u16 *)((u8 *)sdp + 0x164) = flags | key;
    key_mask = key & 0xffff;
    do {
        if ((key_mask & (1u << ct)) != 0) {
            *(u8 *)((u8 *)sdp + 0x124) = delay;
            *(u8 *)((u8 *)sdp + 0x125) = interval;
            *(u8 *)((u8 *)sdp + 0x126) = 0;
            *(u8 *)((u8 *)sdp + 0x127) = 0;
        }
        ct++;
        sdp++;
    } while (ct < 16);
}

/* fspad_PadSetVibra @ 0x146A70 .. 0x146AC0 (0x50 bytes) */
/*
 * dcomp notes:
 *   delay: andi at 0x146a98 writes a register its branch at 0x146a94 reads
 *   declaration vs inferred signature: return void vs inferred u32
 */

void fspad_PadSetVibra(signed int a0 /* r4 */, signed int a1 /* r5 */, unsigned char a2 /* r6 */) {
    u32 v1;

    a1 = (s32)((u32)(a1) + (u32)((u32)a0 << 2));
    v1 = (u32)__PADMNG;
    a0 = (s32)((u32)((u32)a1) * (u32)(0x1c0));
    a0 = (s32)((u8 *)__PADMNG + a0);
    v1 = *(u8 *)(((s32)(a0) + 0x182));
    if (v1 == 0) {
        if ((s32)(u8)a2 > 0) {
            *(u8 *)(((s32)(a0) + 0x174)) = 1;
        } else {
            *(u8 *)(((s32)(a0) + 0x174)) = 0;
        }
    }
    *(u8 *)(((s32)(a0) + 0x175)) = (u8)a2;
    return;
}

u32 fspad_PadSetSmallVibra(u8 *a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */) {
    u32 v1;

    v1 = (u32)a0 << 2;
    a1 = a1 + v1;
    a0 = (u8 *)((u32)a1 << 3);
    a0 = (u8 *)a0 - a1;
    v1 = (u32)__PADMNG;
    a0 = (u8 *)((u32)a0 << 6);
    a0 = (u8 *)__PADMNG + (u32)(a0);
    v1 = *(u8 *)(((u8 *)a0 + 0x182));
    if (v1 != 0) {
        *(u8 *)(((u8 *)a0 + 0x174)) = a2;
    }
    return;
}

u32 fspad_PadSetVibraSepMode(s32 a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */) {
    u32 v1;

    v1 = (u32)a0 << 2;
    a1 = a1 + v1;
    a0 = (u32)a1 << 3;
    a0 = a0 - a1;
    v1 = (u32)__PADMNG;
    a0 = (u32)a0 << 6;
    v1 = (u32)((u8 *)__PADMNG + a0);
    *(u8 *)((v1 + 0x182)) = a2;
    return;
}

/* fspad_PadModeAnalog @ 0x1469B0 .. 0x146A00 (0x50 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1469dc writes a register its branch at 0x1469d8 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int fspad_PadModeAnalog(signed int a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6
        */) {
    u32 v0;
    u32 v1;
    s32 branchcond_1469d8;

    v0 = (u32)a0 << 2;
    a0 = (s32)((u32)(a1) + v0);
    v0 = (u32)__PADMNG;
    v1 = (u32)((u32)a0) * (u32)(0x1c0);
    v1 = (s32)((u8 *)__PADMNG + v1);
    v0 = *(u8 *)((v1 + 0x17d));
    v0 = v0 & 1;
    branchcond_1469d8 = v0 != 0;
    v0 = 0;
    if (!branchcond_1469d8) {
        return v0;
    }
    v0 = 1;
    *(u8 *)((v1 + 0x17f)) = v0;
    *(u8 *)((v1 + 0x180)) = (s32)a2;
    return v0;
}

u32 fspad_PadSetAnalogEdgeMode(s32 a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */) {
    u32 v0;
    u8 *v1;

    v0 = (u32)a0 << 2;
    a1 = a1 + v0;
    v1 = (u8 *)__PADMNG;
    a0 = (u32)a1 << 3;
    v0 = 1;
    a0 = a0 - a1;
    a0 = (u32)a0 << 6;
    *(u8 *)(((u8 *)(u8 *)((u8 *)__PADMNG + a0) + 0x183)) = a2;
    return v0;
}
static u8 __PADMNG[0xe40];
