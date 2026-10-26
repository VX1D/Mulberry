#include "common.h"
signed int fsScr_ScriptStart(unsigned int num);




extern signed int fsScr_ScriptStart(unsigned int);
extern u16 SCR[];
extern u32 ScrWk;
static void GetGameValue(void *a0 , signed int a1 , signed int a2 );
static void GetGameValue(void *, signed int, signed int);
static void GetAutoValue(void *a0 , void *a1 , signed int a2 , signed int a3 );
static void GetAutoValue(void *, void *, signed int, signed int);
static void GetStaticValue(void *a0 , signed int a1 , signed int a2 );
static void GetStaticValue(void *, signed int, signed int);
extern u32 ScriptFunc[];
extern u32 SCR_GValue[];
static void SetGameValue(void *a0 , signed int a1 , signed int a2 );
static void SetGameValue(void *, signed int, signed int);
static void SetAutoPTRValue(void *a0 , signed int a1 , signed int a2 );
static void SetAutoPTRValue(void *, signed int, signed int);
static void SetStaticValue(void *a0 , signed int a1 , signed int a2 );
static void SetStaticValue(void *, signed int, signed int);
static signed int SettingScript(void *context);
static signed int SettingScript(void *);
void SCR_CallScript(void *a0 );
void SCR_CallScript(void *a0 /* r4 */);
u32 SCR_Wait(u32 *a0 );
u32 SCR_Wait(u32 *a0 /* r4 */);
void SCR_NoUse(u32 *a0 );
void SCR_NoUse(u32 *a0 /* r4 */);
static void SetAutoValue(void *a0 , void *a1 , signed int a2 , signed int a3 );
static void SetAutoValue(void *a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */, signed int
        a3 /* r7 */);
static void SetAutoPTRValue(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */);
static void GetValueData(void *arg0, unsigned int *a1 , void *a2 );
static void GetValueData(void *arg0, unsigned int *a1 /* r5 */, void *a2 /* r6 */);
u8 * fsScr_SetScrFunc(s32 a0 , u8 *a1 );
u8 * fsScr_SetScrFunc(s32 a0 /* r4 */, u8 *a1 /* r5 */);
u8 * fsScr_SetGameVal(s32 a0 , u8 *a1 );
u8 * fsScr_SetGameVal(s32 a0 /* r4 */, u8 *a1 /* r5 */);
void fsScr_SetPointerData(void *a0 , signed int a1 );
void fsScr_SetPointerData(void *a0 /* r4 */, signed int a1 /* r5 */);
void fsScr_ScriptProc(void);
void fsScr_ScriptProc(void);

extern void * memset(void *, int, unsigned int);
extern u32 SCRP;
extern u32 ScrSize;
extern u8 ScrStaticMem[];

struct dw_876583 { int kind; int val; };
struct dw_876417 { int kind; struct dw_876583 arg[16]; int wkL[7]; float wkF[8]; };
struct dw_876178 { unsigned short on; char pad1[2]; unsigned int *ScrNow; char pad2[4]; struct dw_876417 fifo[12]; unsigned char Reg[128]; };
static unsigned int *SCR_IfCheck(void *Sp, unsigned int *now);
static unsigned int *SCR_IfCheck(void *, unsigned int *);
static unsigned int *CalculateProc(void *Sp, unsigned int *now);
static unsigned int *CalculateProc(void *, unsigned int *);
extern u32 L1417[];
extern u32 L1418[];
extern u8 ScrStaticMem[];
signed int fsScr_ScriptInit(unsigned char *pBuf, signed int size);
signed int fsScr_ScriptInit(unsigned char *pBuf, signed int size);
void fsScr_ScriptProc(void);
void fsScr_SetPointerData(void *a0 /* r4 */, signed int a1 /* r5 */);
void fsScr_SetPointerDataF(void *a0 , float f12 );
void fsScr_SetPointerDataF(void *a0 /* r4 */, float f12 /* f12 */);
u8 * fsScr_SetGameVal(s32 a0 /* r4 */, u8 *a1 /* r5 */);
u8 * fsScr_SetScrFunc(s32 a0 /* r4 */, u8 *a1 /* r5 */);
static signed int SettingScript(void *context);
static unsigned int *SCR_IfCheck(void *Sp, unsigned int *now);
static void GetValueData(void *arg0, unsigned int *a1 /* r5 */, void *a2 /* r6 */);
static void GetGameValue(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */);
static void GetStaticValue(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */);
static void GetAutoValue(void *a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */, signed int
        a3 /* r7 */);
static void SetGameValue(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */);
static void SetStaticValue(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */);
static void SetAutoPTRValue(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */);
static void SetAutoValue(void *a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */, signed int
        a3 /* r7 */);
void SCR_NoUse(u32 *a0 /* r4 */);
u32 SCR_Wait(u32 *a0 /* r4 */);
void SCR_CallScript(void *a0 /* r4 */);



#define SCRS ((struct dw_876178 *)SCR)
#define SCR_CMD(w) (((w) & 0xffff0000) >> 16)
#define SCR_NUM(w) ((w) & 0xffff)

static inline struct dw_876178 *_SearchScr(unsigned int num) {
    struct dw_876178 *Sp;

    for (Sp = SCRS; (u8 *)Sp < (u8 *)(SCR + 0x98c0); Sp++) {
        if (Sp->on == num) {
            return 0;
        }
    }
    for (Sp = SCRS; (u8 *)Sp < (u8 *)(SCR + 0x98c0); Sp++) {
        if (Sp->on == 0) {
            return Sp;
        }
    }
    return Sp;
}

static inline unsigned int *_ScrNext(unsigned int *p) {
    unsigned int cmd = SCR_CMD(*p);
    unsigned int nn = SCR_NUM(*p);

    p++;
    switch (cmd) {
    case 0x190:
    case 0x191:
    case 0x194:
    case 0x195:
    case 0x197: break;
    case 0x192: p += (nn >> 8) * 5 + 1; break;
    case 0x196: p += nn; break;
    case 0x19d: p += nn + 1; break;
    default: p += nn * 2; break;
    }
    return p;
}



static u8 ScrStaticMem[0x200];
static u16 SCR[0x98c0];
static u32 SCR_GValue[0x40];
static u32 ScriptFunc[0x190];
static u32 ScrSize;
static u32 SCRP;
static u32 ScrWk;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int fsScr_ScriptInit(unsigned char *pBuf, signed int size);
void fsScr_ScriptProc(void);
signed int fsScr_ScriptStart(unsigned int num);
void fsScr_SetPointerData(void *a0 , signed int a1 );
void fsScr_SetPointerDataF(void *a0 , float f12 );
u8 * fsScr_SetGameVal(s32 a0 , u8 *a1 );
u8 * fsScr_SetScrFunc(s32 a0 , u8 *a1 );
static signed int SettingScript(void *context);
static unsigned int *SCR_IfCheck(void *Sp, unsigned int *now);
static unsigned int *CalculateProc(void *Sp, unsigned int *now);
static void GetValueData(void *arg0, unsigned int *a1 , void *a2 );
static void GetGameValue(void *a0 , signed int a1 , signed int a2 );
static void GetStaticValue(void *a0 , signed int a1 , signed int a2 );
static void GetAutoValue(void *a0 , void *a1 , signed int a2 , signed int a3 );
static void SetGameValue(void *a0 , signed int a1 , signed int a2 );
static void SetStaticValue(void *a0 , signed int a1 , signed int a2 );
static void SetAutoPTRValue(void *a0 , signed int a1 , signed int a2 );
static void SetAutoValue(void *a0 , void *a1 , signed int a2 , signed int a3 );
void SCR_NoUse(u32 *a0 );
u32 SCR_Wait(u32 *a0 );
void SCR_CallScript(void *a0 );


signed int fsScr_ScriptInit(unsigned char *pBuf, signed int size) {
    u16 *Sp;
    s32 i;
    s32 j;

    if (pBuf == 0 || size <= 0) {
        return 0;
    }
    SCRP = (u32)pBuf;
    ScrSize = size;
    ScrWk = 0;
    memset(ScrStaticMem, 0, 0x200);
    memset(SCR, 0, 0x13180);
    for (Sp = SCR; Sp < SCR + 0x98c0; Sp += 0x4c6) {
        *(u32 *)(Sp + 2) = SCRP;
    }
    for (i = 63; i >= 0; i--) {
        SCR_GValue[i] = 0;
    }
    for (j = 399; j >= 0; j--) {
        ScriptFunc[j] = 0;
    }
    ScriptFunc[0] = (u32)SCR_NoUse;
    ScriptFunc[1] = (u32)SCR_Wait;
    ScriptFunc[2] = (u32)SCR_CallScript;
    return 1;
}


/* fsScr_ScriptProc @ 0x170670 .. 0x17076C (0xfc bytes, frame 0x50) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001706A0
 *   cfg: loop body is not one contiguous region: .L001706B0
 *   cfg: loop body is not one contiguous region: .L001706C0
 */






void fsScr_ScriptProc(void) {
    u32 a0;
    u8 *s3;
    s32 s2;
    s32 s1;
    u8 *s0;
    u32 v1;
    u32 v0;

    s3 = (u8 *)SCR;
    if ((u32)SCR < (u32)(u8 *)(SCR + 0x98c0)) {
        do {
            v1 = *(u16 *)s3;
            if (v1 != 0) {
                ScrWk = (u32)s3;
                do {
                    s1 = 0;
                    s2 = 0;
                    s0 = s3;
                    do {
                        a0 = *(s32 *)(s0 + 0xc);
                        v1 = a0 & 0x8000;
                        if (a0 != 0) {
                            if (v1 != 0) {
                                s1 = s1 + 1;
                            } else {
                                v1 = (u32)ScriptFunc;
                                v1 = (s32)((u8 *)ScriptFunc + (u32)(a0 << 2));
                                v1 = *(s32 *)v1;
                                if (v1 != 0) {
                                    ((void (*)(s32))(s32)v1)((s32)(s0 + 0xc));
                                }
                                s1 = s1 + 1;
                            }
                        }
                        s2 = s2 + 1;
                        v1 = s2 < (s32)0xc;
                        s0 = (u8 *)(s0 + 0xc0);
                    } while (v1 != 0);
                    if ((u32)s1 != 0) {
                        break;
                    }
                    v0 = SettingScript((void *)s3);
                } while (v0 != 0);
            }
            s3 = (u8 *)(s3 + 0x98c);
        } while (s3 < (u8 *)(SCR + 0x98c0));
    }
    return;
}

signed int fsScr_ScriptStart(unsigned int num) {
    struct dw_876178 *Sp;
    unsigned int nn;
    int i;

    Sp = _SearchScr(num);
    if (Sp == 0) {
        return -1;
    }
    Sp->on = num;
    Sp->ScrNow = (unsigned int *)SCRP;
    do {
        nn = SCR_NUM(*Sp->ScrNow);
        if (SCR_CMD(*Sp->ScrNow) == 0x190 && nn == num) {
            goto found;
        }
        Sp->ScrNow = _ScrNext(Sp->ScrNow);
    } while ((unsigned int)Sp->ScrNow - SCRP < ScrSize);
    Sp->on = 0;
    return 0;

found:
    for (i = 0; i < 12; i++) {
        Sp->fifo[i].kind = 0;
    }
    return Sp - SCRS + 1;
}


/* fsScr_SetPointerData @ 0x1703C0 .. 0x17043C (0x7c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1703e4 writes a register its branch at 0x1703e0 reads
 *   stack: address of the slot at 0x18 escapes at 0x170408
 *   stack: address of the slot at 0x18 escapes at 0x170418
 *   stack: address of the slot at 0x18 escapes at 0x170428
 *   declaration vs inferred signature: return void vs inferred u8 *
 */






void fsScr_SetPointerData(void *a0 /* r4 */, signed int a1 /* r5 */) {
    s32 v1;
    u32 a2;
    u8 stackFrame[16] __attribute__((aligned(16)));

    v1 = 0x13;
    *(u32 *)((u8 *)&stackFrame[12]) = (s32)a1;
    a2 = *(s32 *)(((u8 *)a0 + 4));
    a0 = (void *)*(s32 *)a0;
    a1 = (s32)((s32)a0) >> 8;
    a0 = (void *)(u8)(s32)a0;
    switch ((u32)a0) {
    case 17:
        a0 = (void *)((u8 *)&stackFrame[8]);
        SetGameValue(a0, a1, a2);
        break;
    case 18:
        a0 = (void *)((u8 *)&stackFrame[8]);
        SetAutoPTRValue(a0, a1, a2);
        break;
    case 19:
        a0 = (void *)((u8 *)&stackFrame[8]);
        SetStaticValue(a0, a1, a2);
    }
    return;
}


/* fsScr_SetPointerDataF @ 0x170330 .. 0x1703B4 (0x84 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x17035c writes a register its branch at 0x170358 reads
 *   stack: address of the slot at 0x18 escapes at 0x170380
 *   stack: address of the slot at 0x18 escapes at 0x170390
 *   stack: address of the slot at 0x18 escapes at 0x1703a0
 */









void fsScr_SetPointerDataF(void *a0 /* r4 */, float f12 /* f12 */) {
    u32 a2;
    u32 a1;
    s32 v1;
    u8 stackFrame_18[8] __attribute__((aligned(4)));
    u8 stackFrame_14[4] __attribute__((aligned(4)));

    v1 = 0x13;
    *(f32 *)((u8 *)&stackFrame_14[0]) = f12;
    a1 = *(s32 *)((u8 *)&stackFrame_14[0]);
    ((u32 *)stackFrame_18)[1] = a1;
    a2 = *(s32 *)(((u8 *)a0 + 4));
    a0 = (void *)*(s32 *)a0;
    a1 = (s32)a0 >> 8;
    a0 = (void *)(u8)(s32)a0;
    switch ((u32)a0) {
    case 17:
        SetGameValue((void *)((u8 *)&stackFrame_18[0]), a1, a2);
        break;
    case 18:
        SetAutoPTRValue((void *)((u8 *)&stackFrame_18[0]), a1, a2);
        break;
    case 19:
        SetStaticValue((void *)((u8 *)&stackFrame_18[0]), a1, a2);
    }
    return;
}


/* fsScr_SetGameVal @ 0x170310 .. 0x170328 (0x18 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */





u8 * fsScr_SetGameVal(s32 a0 /* r4 */, u8 *a1 /* r5 */) {
    u32 *v1;

    a0 = (u32)a0 << 2;
    v1 = SCR_GValue;
    *(u32 *)(u32 *)((u8 *)SCR_GValue + a0) = (u32)a1;
    return;
}


/* fsScr_SetScrFunc @ 0x1702F0 .. 0x170308 (0x18 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */






u8 * fsScr_SetScrFunc(s32 a0 /* r4 */, u8 *a1 /* r5 */) {
    u32 *v1;

    a0 = (u32)a0 << 2;
    v1 = ScriptFunc;
    *(u32 *)(u32 *)((u8 *)ScriptFunc + a0) = (u32)a1;
    return;
}


static signed int SettingScript(void *context) {
    u8 *script;
    u32 looping;
    u32 running;
    u32 result;
    u32 cursor;
    script = context;
    looping = 0;
    running = 1;
    cursor = *(u32 *)(script + 4);
    result = 0;
    do {
        u32 word = *(u32 *)cursor;
        u32 argc;
        context = (void *)((word & 0xffff0000) >> 16);
        argc = (u16)word;
        switch ((u32)context) {
        case 400: cursor += 4; break;
        case 401: *(u16 *)script = 0; running = 0; break;
        case 404: looping = 1; cursor += 4; break;
        case 405: looping = 0; running = 0; cursor += 4; break;
        case 402: cursor = (u32)SCR_IfCheck(script, (u32 *)cursor); break;
        case 407: cursor += 4; cursor += (s16)argc * 4; break;
        case 406: cursor = (u32)CalculateProc(script, (u32 *)cursor); break;
        default: {
            u32 index = 0;
            u32 selected;
            u32 scan = (u32)script;
            s32 i;
            u32 output;
            result = cursor;
            do {
                if (*(u32 *)(scan + 12) == 0) {
                    selected = index;
                    goto slot;
                }
                index++;
                scan += 0xc0;
            } while ((s32)index < 12);
            selected = 0;
slot:
            result += 4;
            running = (u32)script + selected * 0xc0;
            i = 0;
            *(u32 *)(running + 12) = (u32)context;
            if ((u8 *)0 < (u8 *)argc) {
                output = running;
                do {
                    context = script;
                    cursor = result;
                    GetValueData(context, (u32 *)(s32)cursor, (u8 *)output + 16);
                    i++;
                    result += 8;
                    output += 8;
                } while ((u32)i < argc);
            }
            memset((void *)(running + 0x90), 0, 0x1c);
            memset((void *)(running + 0xac), 0, 0x20);
            cursor = result;
            running = looping;
            result = 1;
            break;
        }
        case 413: break;
        }
    } while (running);
    *(u32 *)(script + 4) = cursor;
    return result;
}






/* SCR_IfCheck @ 0x16FD40 .. 0x1700E8 (0x3a8 bytes, frame 0xc0) */
/*
 * dcomp notes:
 *   literal: @1417 -> 0x253b00
 *   literal: @1418 -> 0x253ae0
 *   stack: address of the slot at 0x30 escapes at 0x16fd88
 *   stack: address of the slot at 0xbc escapes at 0x16fd88
 *   stack: address of the slot at 0xb4 escapes at 0x16fd88
 *   stack: address of the slot at 0xb8 escapes at 0x16fd90
 *   stack: address of the slot at 0xb0 escapes at 0x16fda4
 *   indirect: jr v1 at 0x16fdec -> <v1>
 *   indirect: jr v1 at 0x16fea4 -> <v1>
 *   stack: address of the slot at 0x34 escapes at 0x16ff90
 *   stack: address of the slot at 0x34 escapes at 0x170040
 *   cfg: loop body is not one contiguous region: .L0016FD88
 *   cfg: kept branch: 0x16fd88 if (..) goto .L0016FE88
 *   a0 typed from the SCR_IfCheck call table
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */




static unsigned int *SCR_IfCheck(void *Sp, unsigned int *now) {
    unsigned int i;
    unsigned int num;
    unsigned int tp;
    unsigned int ret;
    unsigned int com;
    unsigned int ok[32];
    unsigned int nomach;
    struct dw_876583 arg1;
    struct dw_876583 arg2;
    float fa1;
    float fa2;

    nomach = now[1];
    ret = now[0];
    now += 2;
    num = (ret & 0xff00) >> 8;
    tp = ret & 0xff;
    for (i = 0; i < num; i++) {
        GetValueData(Sp, now, &arg1);
        com = now[2];
        GetValueData(Sp, (unsigned int *)(s32)(now + 3), &arg2);
        now += 5;
        if (arg1.kind == 6 || arg2.kind == 6) {
            fa1 = *(float *)&arg1.val;
            fa2 = *(float *)&arg2.val;
            switch (com) {
            case 0: ok[i] = fa1 == fa2; break;
            case 1: ok[i] = fa1 != fa2; break;
            case 2: ok[i] = fa1 > fa2; break;
            case 3: ok[i] = fa1 < fa2; break;
            case 4: ok[i] = fa1 >= fa2; break;
            case 5: ok[i] = fa1 <= fa2; break;
            }
        } else {
            switch (com) {
            case 0: ok[i] = arg1.val == arg2.val; break;
            case 1: ok[i] = arg1.val != arg2.val; break;
            case 2: ok[i] = arg1.val > arg2.val; break;
            case 3: ok[i] = arg1.val < arg2.val; break;
            case 4: ok[i] = arg1.val >= arg2.val; break;
            case 5: ok[i] = arg1.val <= arg2.val; break;
            }
        }
    }
    if (num == 1) {
        ret = ok[0];
    } else {
        ret = ok[0];
        if (tp == 0) {
            for (i = 1; i < num; i++) ret |= ok[i];
        } else {
            for (i = 1; i < num; i++) ret &= ok[i];
        }
    }
    return ret == 0 ? now + nomach : now;
}










/* CalculateProc @ 0x16FA00 .. 0x16FD34 (0x334 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x40 escapes at 0x16fa28
 *   stack: address of the slot at 0x3c escapes at 0x16fa58
 *   stack: address of the slot at 0x38 escapes at 0x16fa64
 *   delay: addiu at 0x16fa7c writes a register its branch at 0x16fa78 reads
 *   delay: addiu at 0x16fa90 writes a register its branch at 0x16fa8c reads
 *   delay: addiu at 0x16faa4 writes a register its branch at 0x16faa0 reads
 *   delay: addiu at 0x16fab8 writes a register its branch at 0x16fab4 reads
 *   delay: addiu at 0x16fba8 writes a register its branch at 0x16fba4 reads
 *   delay: addiu at 0x16fc58 writes a register its branch at 0x16fc54 reads
 *   delay: addiu at 0x16fccc writes a register its branch at 0x16fcc8 reads
 *   stack: address of the slot at 0x40 escapes at 0x16fce8
 *   stack: address of the slot at 0x40 escapes at 0x16fd00
 *   stack: address of the slot at 0x40 escapes at 0x16fd18
 *   cfg: loop body is not one contiguous region: .L0016FA58
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 *   return without a value in a non-void function
 */




static unsigned int *CalculateProc(void *Sp, unsigned int *now) {
    int dd;
    int loop;
    unsigned int mode;
    int result;
    int tt;
    int zzz;
    int nn;
    struct dw_876583 rv;
    struct dw_876583 wkv;
    float resF;
    unsigned int idx;
    int out;

    nn = *(unsigned int *)(s32)(now + 1);
    dd = now[2];
    GetValueData(Sp, now + 1, &rv);
    now += 3;
    mode = 0xff;
    loop = 1;
    tt = 0;
    result = 0;
    zzz = (rv.kind == 6);
    while (loop) {
        if (tt == 0) {
            GetValueData(Sp, now, &wkv);
            now += 2;
            if (zzz == 0) {
                switch (mode) {
                case 0xff: result = wkv.val; break;
                case 0: result += wkv.val; break;
                case 1: result -= wkv.val; break;
                case 2: result *= wkv.val; break;
                case 3: result /= wkv.val; break;
                case 4: result %= wkv.val; break;
                case 5: result <<= wkv.val; break;
                case 6: result >>= wkv.val; break;
                case 7: result &= wkv.val; break;
                case 8: result |= wkv.val; break;
                default: result = 0; break;
                }
            } else {
                switch (mode) {
                case 0xff: resF = *(float *)&wkv.val; break;
                case 0: resF += *(float *)&wkv.val; break;
                case 1: resF -= *(float *)&wkv.val; break;
                case 2: resF *= *(float *)&wkv.val; break;
                case 3: resF /= *(float *)&wkv.val; break;
                }
            }
            mode = 0xff;
        } else {
            switch ((unsigned char)*now) {
            case 0xff:
                now++;
                loop = 0;
                break;
            case 4:
                mode = *now >> 8;
                now++;
                break;
            }
        }
        tt = !tt;
    }
    if (zzz == 0) {
        out = result;
    } else {
        out = *(int *)&resF;
    }
    idx = (unsigned int)(nn & 0xffffff00) >> 8;
    rv.val = out;
    switch ((unsigned char)nn) {
    case 1: SetGameValue(&rv, idx, dd); break;
    case 2: SetAutoValue(&rv, Sp, idx, dd); break;
    case 3: SetStaticValue(&rv, idx, dd); break;
    }
    return now;
}


/* GetValueData @ 0x16F910 .. 0x16F9F4 (0xe4 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x16f944 writes a register its branch at 0x16f940 reads
 *   delay: addiu at 0x16f974 writes a register its branch at 0x16f970 reads
 *   a0 takes slot 0 only because of the ABI order
 */













static void GetValueData(void *arg0, unsigned int *a1 /* r5 */, void *a2 /* r6 */) {
    s32 t2;
    u32 t1;
    u32 t0;
    u32 a3;
    u8 *a2_bytes; // a2
    s32 a0;
    s32 v1;

    a2_bytes = (u8 *)a2;
    t0 = -0x10000;
    v1 = 0x13;
    t1 = *(s32 *)a1;
    a3 = (s32)a1[1];
    t0 = t1 & -0x10000;
    a1 = (unsigned int *)(s32)-0x100;
    t2 = t0 >> 0x10;
    a1 = (unsigned int *)(t1 & (u32)((u32)(a1)));
    t0 = (u32)a1 >> 8;
    switch ((u32)((unsigned int *)(u8)t1)) {
    case 1:
        a0 = (s32)a2_bytes;
        a1 = (unsigned int *)(s32)t0;
        a2_bytes = (u8 *)(s32)a3;
        GetGameValue((void *)a0, (signed int)a1, (signed int)a2_bytes);
        break;
    case 2:
        a1 = (unsigned int *)a0;
        a0 = (s32)a2_bytes;
        a2_bytes = (u8 *)(s32)t0;
        GetAutoValue((void *)a0, (void *)a1, (signed int)a2_bytes, a3);
        break;
    case 3:
        a0 = (s32)a2_bytes;
        a1 = (unsigned int *)(s32)t0;
        a2_bytes = (u8 *)(s32)a3;
        GetStaticValue((void *)a0, (signed int)a1, (signed int)a2_bytes);
        break;
    case 0:
        *(u32 *)a2_bytes = t2;
        *(u32 *)(a2_bytes + 4) = a3;
        break;
    case 17:
    case 18:
    case 19:
        *(u32 *)a2_bytes = t1;
        *(u32 *)(a2_bytes + 4) = a3;
    }
    return;
}


/* GetGameValue @ 0x16F840 .. 0x16F908 (0xc8 bytes) */
/*
 * dcomp notes:
 *   literal: @1256 -> 0x253ac0
 *   indirect: jr v1 at 0x16f88c -> <v1>
 *   declaration vs inferred signature: return void vs inferred u32
 */






static void GetGameValue(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */) {
    u32 t0;
    u32 a3;
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    v1 = 0xff0000;
    a3 = 0xff0000 | 0xff00;
    a3 = (u32)(a1) & (u32)a3;
    v1 = (u8)(s32)a1;
    a1 = v1 << 2;
    a3 = (s32)a3 >> 8;
    t0 = (u16)a3;
    v1 = (u32)SCR_GValue;
    v1 = (s32)((u8 *)SCR_GValue + a1);
    a3 = *(s32 *)v1;
    a3 = a3 + (u32)(a2);
    switch (t0) {
    case 0:
        v1 = *(s8 *)a3;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 1:
        v1 = *(u8 *)a3;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 2:
        v1 = *(s16 *)a3;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 3:
        v1 = *(u16 *)a3;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 4:
        v1 = *(s32 *)a3;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 5:
        v1 = *(s32 *)a3;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 6:
        v1 = *(s32 *)a3;
        *(u32 *)(a0_bytes + 4) = v1;
    default:
        break;
    }
    *(u32 *)a0_bytes = t0;
    return;
}


/* GetStaticValue @ 0x16F780 .. 0x16F838 (0xb8 bytes) */
/*
 * dcomp notes:
 *   literal: @1246 -> 0x253aa0
 *   indirect: jr v1 at 0x16f7c0 -> <v1>
 *   a1 typed from the GetStaticValue call table
 *   declaration vs inferred signature: return void vs inferred u32
 */


static void GetStaticValue(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */) {
    u32 a3;
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    v1 = 0xff0000;
    a1 = (u32)(a1) & (0xff0000 | 0xff00);
    v1 = (u32)ScrStaticMem;
    a2 = (s32)((u8 *)ScrStaticMem + a2);
    v1 = (s32)a1 >> 8;
    a3 = (u16)v1;
    switch (a3) {
    case 0:
        v1 = *(s8 *)a2;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 1:
        v1 = *(u8 *)a2;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 2:
        v1 = *(s16 *)a2;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 3:
        v1 = *(u16 *)a2;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 4:
        v1 = *(s32 *)a2;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 5:
        v1 = *(s32 *)a2;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 6:
        v1 = *(s32 *)a2;
        *(u32 *)(a0_bytes + 4) = v1;
    default:
        break;
    }
    *(u32 *)a0_bytes = a3;
    return;
}







/* GetAutoValue @ 0x16F6C0 .. 0x16F778 (0xb8 bytes) */
/*
 * dcomp notes:
 *   literal: @1236 -> 0x253a80
 *   indirect: jr v1 at 0x16f6fc -> <v1>
 *   a1 typed from the GetAutoValue call table
 *   declaration vs inferred signature: return void vs inferred u32
 */





static void GetAutoValue(void *a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */, signed int
        a3 /* r7 */) {
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    v1 = (s32)((u8 *)a3 + (u32)(a1));
    a3 = v1 + 0x90c;
    v1 = 0xffff00;
    v1 = (u32)(a2) & 0xffff00;
    v1 = (s32)v1 >> 8;
    a2 = (u16)v1;
    switch (a2) {
    case 0:
        v1 = *(s8 *)a3;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 1:
        v1 = *(u8 *)a3;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 2:
        v1 = *(s16 *)a3;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 3:
        v1 = *(u16 *)a3;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 4:
        v1 = *(s32 *)a3;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 5:
        v1 = *(s32 *)a3;
        *(u32 *)(a0_bytes + 4) = v1;
        break;
    case 6:
        v1 = *(s32 *)a3;
        *(u32 *)(a0_bytes + 4) = v1;
    default:
        break;
    }
    *(u32 *)a0_bytes = a2;
    return;
}


/* SetGameValue @ 0x16F5F0 .. 0x16F6B8 (0xc8 bytes) */
/*
 * dcomp notes:
 *   literal: @1226 -> 0x253a60
 *   indirect: jr v1 at 0x16f63c -> <v1>
 *   declaration vs inferred signature: return void vs inferred u32
 */










static void SetGameValue(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */) {
    u32 a3;
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    v1 = (u8)(s32)a1;
    a3 = v1 << 2;
    v1 = (u32)SCR_GValue;
    a3 = (s32)((u8 *)SCR_GValue + (u32)a3);
    a3 = *(s32 *)a3;
    v1 = 0xffff00;
    v1 = (u32)(a1) & 0xffff00;
    v1 = (s32)v1 >> 8;
    v1 = (u16)v1;
    a3 = a3 + (u32)(a2);
    switch (v1) {
    case 0:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u8 *)a3 = v1;
        break;
    case 1:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u8 *)a3 = v1;
        break;
    case 2:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u16 *)a3 = v1;
        break;
    case 3:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u16 *)a3 = v1;
        break;
    case 4:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u32 *)a3 = v1;
        break;
    case 5:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u32 *)a3 = v1;
        break;
    case 6:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u32 *)a3 = v1;
    default:
        break;
    }
    return;
}


/* SetStaticValue @ 0x16F530 .. 0x16F5E8 (0xb8 bytes) */
/*
 * dcomp notes:
 *   literal: @1216 -> 0x253a40
 *   indirect: jr v1 at 0x16f570 -> <v1>
 *   a1 typed from the SetStaticValue call table
 *   declaration vs inferred signature: return void vs inferred u32
 */


static void SetStaticValue(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */) {
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    v1 = (u32)ScrStaticMem;
    a2 = (s32)((u8 *)ScrStaticMem + a2);
    v1 = 0xffff00;
    v1 = (u32)(a1) & 0xffff00;
    v1 = (s32)v1 >> 8;
    v1 = (u16)v1;
    switch (v1) {
    case 0:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u8 *)a2 = v1;
        break;
    case 1:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u8 *)a2 = v1;
        break;
    case 2:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u16 *)a2 = v1;
        break;
    case 3:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u16 *)a2 = v1;
        break;
    case 4:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u32 *)a2 = v1;
        break;
    case 5:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u32 *)a2 = v1;
        break;
    case 6:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u32 *)a2 = v1;
    default:
        break;
    }
    return;
}










/* SetAutoPTRValue @ 0x16F470 .. 0x16F528 (0xb8 bytes) */
/*
 * dcomp notes:
 *   literal: @1206 -> 0x253a20
 *   indirect: jr v1 at 0x16f4ac -> <v1>
 *   a1 typed from the SetAutoPTRValue call table
 *   declaration vs inferred signature: return void vs inferred u32
 */





static void SetAutoPTRValue(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */) {
    u32 a3;
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    a3 = ScrWk;
    v1 = 0xffff00;
    v1 = (u16)((s32)((u32)(a1) & 0xffff00) >> 8);
    a1 = (u32)(a2) + a3;
    a2 = (u32)(a1) + 0x90c;
    switch (v1) {
    case 0:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u8 *)a2 = v1;
        break;
    case 1:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u8 *)a2 = v1;
        break;
    case 2:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u16 *)a2 = v1;
        break;
    case 3:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u16 *)a2 = v1;
        break;
    case 4:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u32 *)a2 = v1;
        break;
    case 5:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u32 *)a2 = v1;
        break;
    case 6:
        v1 = *(s32 *)(a0_bytes + 4);
        *(u32 *)a2 = v1;
    default:
        break;
    }
    return;
}


/* SetAutoValue @ 0x16F3B0 .. 0x16F468 (0xb8 bytes) */
/*
 * dcomp notes:
 *   literal: @1196 -> 0x253a00
 *   indirect: jr v1 at 0x16f3ec -> <v1>
 *   a1 typed from the SetAutoValue call table
 *   declaration vs inferred signature: return void vs inferred u32
 */















static void SetAutoValue(void *a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */, signed int
        a3 /* r7 */) {
    u32 v1;

    v1 = (s32)((u8 *)a3 + (u32)(a1));
    a3 = (s32)(v1 + 0x90c);
    v1 = 0xffff00;
    v1 = (u32)(a2) & (u32)(0xffff00);
    v1 = (s32)((s32)v1) >> 8;
    v1 = (u16)v1;
    a1 = (void *)0x253a00;
    switch (v1) {
    case 0:
        v1 = *(s32 *)(((u8 *)a0 + 4));
        *(u8 *)a3 = v1;
        break;
    case 1:
        v1 = *(s32 *)(((u8 *)a0 + 4));
        *(u8 *)a3 = v1;
        break;
    case 2:
        v1 = *(s32 *)(((u8 *)a0 + 4));
        *(u16 *)a3 = v1;
        break;
    case 3:
        v1 = *(s32 *)(((u8 *)a0 + 4));
        *(u16 *)a3 = v1;
        break;
    case 4:
        v1 = *(s32 *)(((u8 *)a0 + 4));
        *(u32 *)a3 = v1;
        break;
    case 5:
        v1 = *(s32 *)(((u8 *)a0 + 4));
        *(u32 *)a3 = v1;
        break;
    case 6:
        v1 = *(s32 *)(((u8 *)a0 + 4));
        *(u32 *)a3 = v1;
    default:
        break;
    }
    return;
}


/* SCR_NoUse @ 0x16F3A0 .. 0x16F3A8 (0x8 bytes) */






void SCR_NoUse(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}


/* SCR_Wait @ 0x16F380 .. 0x16F3A0 (0x20 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */














u32 SCR_Wait(u32 *a0 /* r4 */) {
    u32 v1;

    v1 = *(u32 *)(((u8 *)a0 + 8));
    v1 = v1 + -1;
    *(u32 *)(((u8 *)a0 + 8)) = v1;
    if ((s32)v1 <= 0) {
        *(u32 *)a0 = 0;
    }
    return;
}


/* SCR_CallScript @ 0x16F2F0 .. 0x16F378 (0x88 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */






void SCR_CallScript(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u32 v0;
    u32 a1;

    v1 = *(s32 *)(((u8 *)a0 + 0x84));
    s0 = (u8 *)a0;
    if (v1 == 0) {
        *(u32 *)(s0 + 0x84) = 1;
        v0 = fsScr_ScriptStart(*(s32 *)(s0 + 8));
        *(u32 *)(s0 + 0x88) = v0;
        a0 = (void *)*(s32 *)(s0 + 0x10);
        if ((u32)(s32)a0 == (u32)1) {
            *(u32 *)s0 = 0;
        }
        return;
    }
    a1 = *(s32 *)(s0 + 0x88);
    a0 = (void *)(s32)0x98c;
    v1 = (u32)SCR;
    v1 = (s32)((u8 *)SCR + (u32)((u32)((u32)(a1 + -1)) * (u32)((u32)a0)));
    v1 = *(u16 *)v1;
    if (v1 == 0) {
        *(u32 *)s0 = 0;
    }
    return;
}
