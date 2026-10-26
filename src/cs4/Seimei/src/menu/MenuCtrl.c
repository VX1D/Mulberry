#include "common.h"
static void MenuCtrlMng_Free(void *);
extern signed int MngState_Init(void *);
extern int sprintf(void *, void *, ...);
extern signed int MenuCtrlMng_Alloc();
void MenuCtrlMng_SetForceChangeCursorId(u32 *a0 /* r4 */, s32 a1 /* r5 */);
signed int MenuCtrlMng_Delete(void *a0 /* r4 */);
signed int MenuCtrlMng_Init(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */,
        unsigned char *a3 /* r7 */);
u32 MenuCtrlMng_Initialize(u32 *a0 /* r4 */);

/* MenuCtrlMng_Initialize @ 0x1EDFE0 .. 0x1EDFF8 (0x18 bytes) */



u32 MenuCtrlMng_Initialize(u32 *a0 /* r4 */) {
    u32 v0;

    *(u32 *)(((u8 *)a0 + 0x20)) = 0;
    v0 = 1;
    *(u32 *)(((u8 *)a0 + 0x6c)) = 0;
    *(u32 *)(((u8 *)a0 + 0x74)) = 0;
    *(u32 *)(((u8 *)a0 + 0x8c)) = 0;
    return v0;
}






/* MenuCtrlMng_Init @ 0x1EDE80 .. 0x1EDFDC (0x15c bytes, frame 0x150) */
/*
 * dcomp notes:
 *   literal: @2163 is the string '%s'
 *   stack: address of the slot at 0x50 escapes at 0x1edf10
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int MenuCtrlMng_Init(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */,
        unsigned char *a3 /* r7 */) {
    u8 *s0;
    s32 s3;
    s32 s2;
    u32 s1;
    signed int a2_2; // a2
    void *a0_2; // a0
    u32 v1;
    signed int a1_2;
    u32 v0;
    u8 stackFrame_50[256] __attribute__((aligned(16)));

    s3 = a1;
    s2 = a2;
    s0 = (u8 *)a0;
    s1 = (u32)a3;
    if ((u32)s0 == 0) {
        return 0;
    } else {
        MngState_Init(a0);
        *(u32 *)(s0 + 0x24) = s3;
        *(u32 *)(s0 + 0x28) = s2;
        v1 = -1;
        *(u32 *)(s0 + 0x78) = 0;
        v0 = 0x3f800000;
        *(u32 *)(s0 + 0x7c) = v1;
        a2_2 = s1;
        *(u32 *)(s0 + 0x80) = 0;
        *(u8 *)(s0 + 0x70) = 0;
        a1_2 = (signed int)"%s";
        *(u8 *)(s0 + 0x84) = 0;
        *(u32 *)(s0 + 0x88) = 0;
        *(u32 *)(s0 + 0x2c) = 0;
        *(u32 *)(s0 + 0x30) = 0;
        *(u32 *)(s0 + 0x34) = 0x3f800000;
        *(u32 *)(s0 + 0x38) = 0x3f800000;
        *(u32 *)(s0 + 0x3c) = 0x3f800000;
        *(u32 *)(s0 + 0x40) = 0x3f800000;
        *(u32 *)(s0 + 0x44) = 0x3f800000;
        sprintf((void *)((u8 *)&stackFrame_50[0]), (void *)"%s", a2_2);
        v0 = MenuCtrlMng_Alloc((u32)s0, ((u8 *)&stackFrame_50[0]));
        a2_2 = 1;
        if (v0 != (u32)(s32)a2_2) {
            a0_2 = (void *)s0;
            if (s0 != 0) {
                MenuCtrlMng_Free(a0_2);
                *(u32 *)s0 = 0;
            }
            return 0;
        } else {
            v1 = *(s32 *)(s0 + 0x20);
            v0 = *(s32 *)((v1 + 0x24));
            *(u32 *)(s0 + 0x78) = v0;
            v0 = *(s32 *)((v1 + 0x24));
            *(u32 *)(s0 + 0x80) = v0;
            v0 = *(s32 *)((v1 + 0x14));
            v1 = *(s32 *)(s0 + 0x78);
            if (v0 < v1) {
                a0_2 = (void *)s0;
                if (s0 != 0) {
                    MenuCtrlMng_Free(a0_2);
                    *(u32 *)s0 = 0;
                }
                return 0;
            } else {
                a0_2 = (void *)*(s32 *)(s0 + 0x6c);
                a1_2 = v1 * (u32)(0xf0);
                v1 = 2;
                v0 = a2_2;
                *(u8 *)(((u8 *)(u32)(s32)((u8 *)a0_2 + a1_2) + 0xa4)) = a2_2;
                *(u32 *)s0 = v1;
            }
        }
    }
    return v0;
}



extern void MemFree(void *);
extern signed int MenuReadFile(unsigned char **, char *);
extern void * _MemAlloc(unsigned int);
extern void ResetVramAddr();
extern char * strcat(char *, const char *);
extern signed int MenuItemMng_Initialize(void *);
extern signed int MenuItemMng_Init(void *, void *, signed int *, signed int *, signed int *, void *, signed int *);
extern u32 sMenuTexListBuf[];

typedef struct { u8 b[0xf0]; } MCItemParam;
typedef struct { u8 flag; u8 pad[0xf]; char name[0x40]; } MCTexlistParam;
typedef struct {
    u8 _p0[0x14]; u32 nItems; u8 _p1[0x10];
    s32 f28; s32 f2c; s32 f30; s32 f34; u32 f38; u32 nTex; char name[1];
} MCFileHeader;
typedef struct {
    u8 _p0[0x20]; MCFileHeader *pFile; s32 f24; s32 f28; u8 _p1[0x40];
    MCItemParam *pItems; u8 _p2[4]; s32 *pF74; u8 _p3[0x14]; u32 *pTex;
} MCMng;

static inline signed int MenuCtrlMng_LoadFile(MCMng *p) {
    u8 stackFrame_80[256] __attribute__((aligned(16)));
    MemFree((void *)p->pFile);
    p->pFile = 0;
    sprintf((void *)&stackFrame_80[0], (void *)"ctrl%02d%02d.mnc", p->f28, p->f24);
    return MenuReadFile((unsigned char **)&p->pFile, (char *)&stackFrame_80[0]) == 1;
}

signed int MenuCtrlMng_Alloc(a0)
void *a0;
{
    MCMng *pMenuCtrlMng = (MCMng *)a0;
    s32 i;
    MCFileHeader *pMenuCtrlFileHeader;
    MCItemParam *pMenuItemParam;
    MCTexlistParam *pMenuCtrlTexlistParam;

    if (pMenuCtrlMng == 0) {
        return 0;
    }
    MenuCtrlMng_Free(pMenuCtrlMng);
    if (MenuCtrlMng_LoadFile(pMenuCtrlMng) != 1) {
        return 0;
    }
    pMenuCtrlFileHeader = pMenuCtrlMng->pFile;
    pMenuItemParam = (MCItemParam *)(((u32)pMenuCtrlFileHeader->nItems << 7) + (u32)pMenuCtrlFileHeader + 0xc0);
    pMenuCtrlTexlistParam = (MCTexlistParam *)((u8 *)pMenuItemParam + pMenuCtrlFileHeader->nItems * 0xf0 +
        pMenuCtrlFileHeader->f30 * 0x40 + pMenuCtrlFileHeader->f34 * 0x50);
    if ((pMenuCtrlMng->pItems = (MCItemParam *)_MemAlloc(pMenuCtrlFileHeader->nItems * 0xf0)) == 0) {
        return 0;
    }
    if ((pMenuCtrlMng->pF74 = (s32 *)_MemAlloc(pMenuCtrlFileHeader->f34 * 4)) == 0) {
        return 0;
    }
    if ((pMenuCtrlMng->pTex = (u32 *)_MemAlloc(pMenuCtrlFileHeader->nTex * 4)) == 0) {
        return 0;
    }
    ResetVramAddr();
    for (i = 0; i < pMenuCtrlFileHeader->nTex; i++) {
        char aFilename[256] __attribute__((aligned(16))) = {0};
        strcat(aFilename, pMenuCtrlFileHeader->name);
        strcat(aFilename, pMenuCtrlTexlistParam->name);
        pMenuCtrlMng->pTex[i] = 0;
        if ((pMenuCtrlTexlistParam->flag & 1) && sMenuTexListBuf[i] == 0) {
            MenuReadFile((unsigned char **)&sMenuTexListBuf[i], aFilename);
        }
        pMenuCtrlTexlistParam++;
    }
    for (i = 0; i < pMenuCtrlFileHeader->nItems; i++) {
        MenuItemMng_Initialize(&pMenuCtrlMng->pItems[i]);
        if (MenuItemMng_Init(&pMenuCtrlMng->pItems[i], &pMenuItemParam[i], &pMenuCtrlFileHeader->f28,
                             &pMenuCtrlFileHeader->f2c, &pMenuCtrlFileHeader->f30,
                             &pMenuItemParam[pMenuCtrlFileHeader->nItems], pMenuCtrlMng->pF74) == 0) {
            return 0;
        }
    }
    return 1;
}



/* MenuCtrlMng_Free @ 0x1EDAA0 .. 0x1EDBEC (0x14c bytes, frame 0x50) */

extern void FreeTexList(void *);
extern void MemFree(void *);
extern signed int MenuItemMng_Delete(void *);
u32 sMenuTexListBuf[0x8];

static void MenuCtrlMng_Free(void *a0 /* r4 */) {
    u8 *s3;
    s32 s2;
    u32 s1;
    s32 s0;
    void *a0_2; // a0
    u32 v0;

    s3 = (u8 *)a0;
    if ((u32)s3 != 0) {
        s1 = *(s32 *)(s3 + 0x20);
        if (s1 != 0) {
            v0 = *(s32 *)(s3 + 0x8c);
            if (v0 != 0 && (u8 *)0 < (u8 *)(u32)*(s32 *)((s1 + 0x3c))) {
                s2 = 0;
                s0 = 0;
                do {
                    v0 = *(s32 *)(s3 + 0x8c);
                    a0_2 = (void *)*(s32 *)(u32)(v0 + s0);
                    FreeTexList(a0_2);
                    v0 = *(s32 *)(s3 + 0x8c);
                    a0_2 = (void *)*(s32 *)(u32)(v0 + s0);
                    MemFree(a0_2);
                    v0 = *(s32 *)(s3 + 0x8c);
                    s2 = s2 + 1;
                    *(u32 *)(u32)(v0 + s0) = 0;
                    v0 = *(s32 *)((s1 + 0x3c));
                    v0 = (u32)s2 < v0;
                    s0 = s0 + 4;
                } while (v0 != 0);
            }
            s0 = 0;
            s1 = (u32)sMenuTexListBuf;
            do {
                a0_2 = (void *)*(s32 *)s1;
                FreeTexList(a0_2);
                a0_2 = (void *)*(s32 *)s1;
                MemFree(a0_2);
                s0 = s0 + 1;
                *(u32 *)s1 = 0;
                v0 = s0 < (s32)8;
                s1 = s1 + 4;
            } while (v0 != 0);
            v0 = *(s32 *)((*(s32 *)(s3 + 0x20) + 0x14));
            s0 = 0;
            if ((u8 *)0 < (u8 *)v0) {
                s1 = 0;
                do {
                    v0 = *(s32 *)(s3 + 0x6c);
                    MenuItemMng_Delete((void *)(u32)(v0 + s1));
                    v0 = *(s32 *)(s3 + 0x20);
                    s0 = s0 + 1;
                    v0 = *(s32 *)((v0 + 0x14));
                    v0 = (u32)s0 < v0;
                    s1 = s1 + 0xf0;
                } while (v0 != 0);
            }
        }
        a0_2 = (void *)*(s32 *)(s3 + 0x6c);
        MemFree(a0_2);
        *(u32 *)(s3 + 0x6c) = 0;
        *(u32 *)(s3 + 0x20) = 0;
        MemFree((void *)*(s32 *)(s3 + 0x74));
        *(u32 *)(s3 + 0x74) = 0;
        a0_2 = (void *)*(s32 *)(s3 + 0x8c);
        MemFree(a0_2);
        *(u32 *)(s3 + 0x8c) = 0;
    }
    return;
}



/* MenuCtrlMng_GetTexId @ 0x1ED970 .. 0x1EDA98 (0x128 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001EDA08
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int MngState_UpdateExeCheck(void *);
extern void * GetTexMngByBaseName(void *, char *);
u32 sMenuTexListBuf[0x8];

signed int MenuCtrlMng_GetTexId(void *a0 /* r4 */) {
    u8 *s4;
    u32 a2;
    s32 s3;
    u8 *s2;
    u32 v1;
    u32 v0;
    u8 *s1;
    s32 s0;

    s4 = (u8 *)a0;
    if ((u32)s4 == 0) {
        v0 = 0;
    } else {
        v0 = MngState_UpdateExeCheck(a0);
        v1 = 1;
        if (v0 != v1) {
            v0 = 0;
        } else {
            s2 = (u8 *)*(s32 *)(s4 + 0x20);
            s3 = 0;
            a2 = *(s32 *)(s2 + 0x14);
            v1 = *(s32 *)(s2 + 0x30);
            v0 = *(s32 *)(s2 + 0x34);
            s1 = (u8 *)(s32)((u32)(s32)((u8 *)(u32)(v1 << 6) + (u32)(s32)((u8 *)(u32)(a2 *
                (u32)(0xf0)) + (u32)(s32)((u8 *)(u32)(a2 << 7) + (u32)(s2)))) + 0xc0);
            if (0 < (s32)v0) {
                s0 = 0;
                do {
                    v1 = *(s32 *)(s1 + 4);
                    v0 = (u32)sMenuTexListBuf;
                    v0 = (u32)GetTexMngByBaseName((void *)*(s32 *)(u8 *)(u8 *)((u8
                        *)sMenuTexListBuf + (u32)(v1 << 2)), (char *)(s1 + 0x10));
                    if (v0 != 0) {
                        v1 = *(u16 *)(((u8 *)v0 + 2));
                        v0 = *(s32 *)(s4 + 0x74);
                        *(u32 *)(u32)(v0 + s0) = v1;
                    } else {
                        v0 = *(s32 *)(s4 + 0x74);
                        *(u32 *)(u32)(v0 + s0) = -1;
                    }
                    v0 = *(s32 *)(s2 + 0x34);
                    s3 = s3 + 1;
                    s1 = (u8 *)(s1 + 0x50);
                    v0 = s3 < (s32)v0;
                    s0 = s0 + 4;
                } while (v0 != 0);
            }
            v0 = 1;
        }
    }
    return v0;
}



/* MenuCtrlMng_Update @ 0x1ECC50 .. 0x1ED970 (0xd20 bytes, frame 0x160) */
/*
 * dcomp notes:
 *   literal: @2000 -> 0x256ee0
 *   delay: daddu at 0x1eccec writes a register its branch at 0x1ecce8 reads
 *   delay: daddu at 0x1ecd10 writes a register its branch at 0x1ecd0c reads
 *   delay: daddu at 0x1ecdf0 writes a register its branch at 0x1ecdec reads
 *   stack: address of the slot at 0xe1 escapes at 0x1ece40
 *   delay: addiu at 0x1ecf30 writes a register its branch at 0x1ecf2c reads
 *   stack: address of the slot at 0xd0 escapes at 0x1ecf68
 *   indirect: jr v0 at 0x1ecff4 -> <v0>
 *   stack: address of the slot at 0xc0 escapes at 0x1ed040
 *   stack: address of the slot at 0xc0 escapes at 0x1ed074
 *   delay: addiu at 0x1ed17c writes a register its branch at 0x1ed178 reads
 *   fpu: mtc1 reinterprets v1 at 0x1ed228
 *   fpu: mtc1 reinterprets v0 at 0x1ed230
 *   delay: addiu at 0x1ed27c writes a register its branch at 0x1ed278 reads
 *   delay: addiu at 0x1ed33c writes a register its branch at 0x1ed338 reads
 *   delay: addiu at 0x1ed45c writes a register its branch at 0x1ed458 reads
 *   delay: addiu at 0x1ed604 writes a register its branch at 0x1ed600 reads
 *   stack: address of the slot at 0xb0 escapes at 0x1ed748
 *   stack: address of the slot at 0xb0 escapes at 0x1ed77c
 *   stack: address of the slot at 0xa0 escapes at 0x1ed7f4
 *   stack: address of the slot at 0xa0 escapes at 0x1ed828
 *   delay: addiu at 0x1ed89c writes a register its branch at 0x1ed898 reads
 *   delay: andi at 0x1ed8dc writes a register its branch at 0x1ed8d8 reads
 *   cfg: kept goto: 0x1ecc90 -> .L001ED940
 *   cfg: kept goto: 0x1eccc0 -> .L001ED940
 *   cfg: kept goto: 0x1eccec -> .L001ED940
 *   cfg: kept goto: 0x1ecd44 -> .L001ED940
 *   cfg: kept goto: 0x1ecd74 -> .L001ED940
 *   cfg: kept goto: 0x1ece24 -> .L001ED940
 *   cfg: loop body is not one contiguous region: .L001ECE40
 *   cfg: loop body is not one contiguous region: .L001ECF18
 *   cfg: loop body is not one contiguous region: .L001ECFC8
 *   cfg: kept goto: 0x1ed92c -> .L001ECFC8
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void Menu_SetNoSndOff(signed int);
extern signed int MenuItemMng_Update(void *, void *);
extern signed int Memu_CtrlFunc(void *, signed int);
extern void SetFadeMng(unsigned char, signed int *, signed int, void *, void *, signed int, signed
    int);
extern u32 Menu_GetNoSndOff();
extern signed int MenuCtrlMng_Update_ExeWaitFunc(void *, void *);
extern signed int Menu_SND_Play2D(signed int, signed short, signed short);
extern u32 L2000[];
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 1; u8 b5 : 1; u8 b6 : 1; u8 b7 : 1; } MCU_Bits;
typedef struct { s8 get_state; u8 get_b1; s16 pad; s32 get_goto; s32 get_goto_order; s32 get_call_menu_id; s32 dmy2[12]; } MCU_GS;
typedef struct { u8 _p0[0xc]; s32 f0c; s32 f10; } MCU_Tmpl;
typedef struct {
    u8 _p0[0x20];
    MCU_Tmpl *lpTmpl;
    u8 b24;
    u8 _p1[0xb];
    u8 u30[0x30];
    s32 kind;
    u8 _p2[0x1c];
    u8 u80[0x24];
    s8 a4;
    u8 _p3[0x17];
    MCU_Bits bc;
    u8 _p4[0x23];
    s32 e0;
    u8 _p5[0xc];
} MCU_Item;
typedef struct {
    u8 _p0[0xc];
    s32 f0c; s32 f10; s32 f14; s32 f18; s32 f1c; s32 f20; s32 f24;
    u8 _p1[0x14];
    MCU_Bits fl;
    u8 _p2[0x43];
} MCU_Layer;

typedef struct { u8 *p; u8 pad[12]; } MCU_Arg;
typedef struct {
    u8 _p0[0x14];
    u32 nItems;
    s32 layersOff;
    u8 _p1[0x4];
    s32 f20;
    s32 f24;
    u8 _p2[0x10];
    s32 f38;
    u8 _p3[0x44];
    s32 f80; s32 f84; s32 f88; s32 f8c;
    u8 _p4[0x10];
    s32 fa0; s32 fa4; s32 fa8;
    u8 _p5[0x4];
    s32 fb0; s32 fb4;
} MCU_File;
typedef struct {
    u8 _p0[0x20];
    MCU_File *file;
    u8 _p1[0x8];
    s32 f2c;
    s32 f30;
    u8 _p2[0x10];
    float f44;
    s32 f48;
    u8 _p3[0x20];
    MCU_Item *items;
    u8 state;
    u8 _p4[7];
    s32 cur;
    u8 _p5[4];
    s32 f80;
    u8 next;
    u8 _p6[3];
    s32 f88;
} MCU_Ctrl;
#ifndef MCU_MAPFN_DEFINED
#define MCU_MAPFN_DEFINED
typedef struct {
    u8 name[0x20];
    void (*Get)(void *, s32);
    void (*Set)(void *, s32);
    void (*Decide)(void *, s32);
    void (*CntUp)(void *, s32);
    void (*CntDown)(void *, s32);
    void (*Gene1)(void *, s32);
    void (*Gene2)(void *, s32);
    void (*Evrfrm)(void *, s32, s32);
    void (*Init)(void *, s32, s32);
    void (*Check)(void *, s32, s32);
} MCU_MapFn;
extern MCU_MapFn g_MapFuncTable[];
#endif
#define FS32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define FU32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FU8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define FS8(p, o) (*(s8 *)((u8 *)(p) + (o)))
#define FF32(p, o) (*(float *)((u8 *)(p) + (o)))
#define NEXT_ST if (ctrl->state == ctrl->next) break; ctrl->state = s3;
#define CLR16(b) { u8 *pp = (b); u32 nn = 16; if (pp != 0) { do { *pp = 0; nn = nn - 1; pp = pp + 1; } while (nn != 0); } }

static inline s32 MCU_GSInit(MCU_GS *p) {
    if (p == 0) {
        return 0;
    }
    p->get_state = 0xc;
    p->get_goto = 0;
    p->get_goto_order = 0;
    return 1;
}

signed int MenuCtrlMng_Update(void *a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */) {
    MCU_Ctrl *ctrl;
    MCU_GS *gsOut;
    MCU_File *file;
    MCU_Layer *layers;
    u8 *pArg;
    s32 s3;
    MCU_File *fl;
    MCU_Layer *ly;
    s32 s0;
    s32 s1;
    s32 s6;
    s32 s7;
    s32 i;
    s32 p;
    MCU_Item *it;
    MCU_GS gs1;
    MCU_GS gs2;
    MCU_Arg arg;

    ctrl = (MCU_Ctrl *)a0;
    gsOut = (MCU_GS *)a1;
    if (ctrl == 0) {
        return 0;
    }
    if (gsOut == 0) {
        return 0;
    }
    if (MngState_UpdateExeCheck(ctrl) != 1) {
        return 0;
    }
    file = ctrl->file;
    s3 = (s8)ctrl->state;
    layers = (MCU_Layer *)((u8 *)file + file->layersOff);
    ctrl->f88 = a2;
    if (ctrl->state == 0 && ctrl->next == 0) {
        return 1;
    }
    if (ctrl->state == 0) {
        Menu_SetNoSndOff(1);
    }
    if (MCU_GSInit(&gs1) == 0) {
        return 0;
    }
    if (MenuItemMng_Update(&ctrl->items[ctrl->cur], &gs1) == 0) {
        return 0;
    }
    p = layers[ctrl->cur].f0c;
    if (p >= 0) {
        if ((u8)gs1.get_state != gs1.get_b1) {
            ctrl->items[p].e0 = ctrl->cur;
        }
        if (ctrl->cur == ctrl->items[p].e0) {
            ctrl->items[p].a4 = gs1.get_state;
        }
    }
    if (MCU_GSInit(&gs2) == 0) {
        return 0;
    }
    for (i = 0; i < file->nItems; i++, layers++) {
        if (i != ctrl->cur) {
            if (MenuItemMng_Update(&ctrl->items[i], &gs2) == 0) {
                return 0;
            }
            p = layers->f0c;
            if (p >= 0) {
                if ((u8)gs2.get_state != gs2.get_b1) {
                    ctrl->items[p].e0 = i;
                }
                if (i == ctrl->items[p].e0) {
                    ctrl->items[p].a4 = gs2.get_state;
                }
            }
        }
    }
    if (ctrl->state == 0) {
        Menu_SetNoSndOff(0);
    }
    for (i = 0; i < file->nItems; i++) {
        it = &ctrl->items[i];
        if (it->lpTmpl->f0c == 1) {
            arg.p = it->u30;
            g_MapFuncTable[ctrl->items[i].kind].Evrfrm(&arg, ctrl->items[i].lpTmpl->f10, *(s32 *)&ctrl->items[i].kind);
        } else {
            g_MapFuncTable[it->kind].Evrfrm(it->u80, it->lpTmpl->f10, *(s32 *)&it->kind);
        }
    }
    for (;;) {
        fl = ctrl->file;
        ly = (MCU_Layer *)((u8 *)fl + fl->layersOff);
        switch (ctrl->state) {
        case 0:
            s3 = s3 + 1;
            Memu_CtrlFunc((void *)0, ctrl->state);
            ctrl->f44 = 0;
            NEXT_ST
        case 1:
            s3 = s3 + 1;
            if (fl->fa0 > 0) {
                u8 buf1[16] __attribute__((aligned(16))) = {0};
                SetFadeMng(0xb, (signed int *)buf1, fl->fa0, (void *)0, (void *)0, 0, 0);
            }
            Memu_CtrlFunc((void *)0, ctrl->state);
            ctrl->f44 = 0;
            s6 = ctrl->f88;
            s7 = Menu_GetNoSndOff();
            Menu_SetNoSndOff(1);
            ctrl->f88 = 0;
            for (s0 = 0; s0 < 10; s0++) {
                MenuCtrlMng_Update_ExeWaitFunc(ctrl, gsOut);
            }
            ctrl->f88 = s6;
            Menu_SetNoSndOff(s7);
            if (fl->f38 != 0) {
                for (i = 0; i < fl->nItems; i++) {
                    ctrl->items[i].b24 = 0;
                    ctrl->items[i].a4 = 0;
                }
                ctrl->items[fl->f24].b24 = 1;
                ctrl->items[fl->f24].a4 = 1;
                ctrl->cur = fl->f24;
            }
            if (ctrl->state == ctrl->next) {
                ctrl->next = 3;
            }
            NEXT_ST
        case 2:
            ctrl->f44 = 1.0f;
            s3 = s3 + 1;
            Memu_CtrlFunc((void *)0, ctrl->state);
            ctrl->f48 = fl->f88;
            ctrl->f2c = fl->f80;
            if (ctrl->state == ctrl->next) {
                break;
            }
            ctrl->state = s3;
            Menu_SND_Play2D(fl->fb0, 0x64, 0);
        case 3:
            s3 = s3 + 1;
            Memu_CtrlFunc((void *)0, ctrl->state);
            if (ctrl->f2c > 0) {
                ctrl->f2c = ctrl->f2c - 1;
                if (fl->fa8 != 1) {
                    break;
                }
                ctrl->f44 = (float)(fl->f80 - ctrl->f2c) / (float)fl->f80;
                break;
            } else if (ctrl->f48 != 0) {
                ctrl->f48 = ctrl->f48 - 1;
                break;
            } else {
                if (ctrl->state == ctrl->next) {
                    ctrl->next = 6;
                }
                NEXT_ST
            }
        case 4:
            s3 = s3 + 1;
            Memu_CtrlFunc((void *)0, ctrl->state);
            NEXT_ST
        case 5:
            s3 = s3 + 1;
            Memu_CtrlFunc((void *)0, ctrl->state);
            NEXT_ST
        case 6:
            s3 = s3 + 1;
            Memu_CtrlFunc((void *)0, ctrl->state);
            if (ly[ctrl->cur].fl.b7 != 0) {
                ctrl->f80 = ctrl->cur;
            }
            MenuCtrlMng_Update_ExeWaitFunc(ctrl, gsOut);
            if (gs1.get_goto == 0) {
                if (gs1.get_goto_order != 0) {
                    switch ((u8)gs1.get_state) {
                    case 0:
                        if (ly[ctrl->cur].f18 == 1) {
                            ctrl->cur = ly[ctrl->cur].f1c;
                            ctrl->items[ctrl->cur].a4 = 1;
                        }
                        if (ly[ctrl->cur].f18 != 2) {
                            break;
                        }
                        if (ly[ctrl->cur].f1c == 1) {
                            it = &ctrl->items[ctrl->cur];
                            g_MapFuncTable[it->kind].Check(&it->bc, it->lpTmpl->f10, *(s32 *)&it->kind);
                            if (it->bc.b0 == 0) {
                                gsOut->get_goto_order = ly[ctrl->cur].f20;
                                if (ly[ctrl->cur].fl.b0 != 0) {
                                    ctrl->next = 9;
                                }
                            }
                        }
                        if (ly[ctrl->cur].f1c != 2) {
                            break;
                        }
                        it = &ctrl->items[ctrl->cur];
                            g_MapFuncTable[it->kind].Check(&it->bc, it->lpTmpl->f10, *(s32 *)&it->kind);
                        if (it->bc.b1 != 0) {
                            break;
                        }
                        gsOut->get_goto_order = ly[ctrl->cur].f24;
                        if (ly[ctrl->cur].fl.b1 != 0) {
                            ctrl->next = 9;
                        }
                        break;
                    case 9:
                        if (ly->f10 == 1) {
                            ctrl->cur = ly[ctrl->cur].f14;
                            ctrl->items[ctrl->cur].a4 = 1;
                        }
                        if (ly->f10 != 2) {
                            break;
                        }
                        if (ly[ctrl->cur].f1c == 1) {
                            it = &ctrl->items[ctrl->cur];
                            g_MapFuncTable[it->kind].Check(&it->bc, it->lpTmpl->f10, *(s32 *)&it->kind);
                            if (it->bc.b0 == 0) {
                                gsOut->get_goto_order = ly[ctrl->cur].f20;
                                if (ly[ctrl->cur].fl.b0 != 0) {
                                    ctrl->next = 9;
                                }
                            }
                        }
                        if (ly[ctrl->cur].f1c != 2) {
                            break;
                        }
                        it = &ctrl->items[ctrl->cur];
                            g_MapFuncTable[it->kind].Check(&it->bc, it->lpTmpl->f10, *(s32 *)&it->kind);
                        if (it->bc.b1 != 0) {
                            break;
                        }
                        gsOut->get_goto_order = ly[ctrl->cur].f24;
                        if (ly[ctrl->cur].fl.b1 != 0) {
                            ctrl->next = 9;
                        }
                        break;
                    }
                }
            }
            ctrl->f30 = gsOut->get_goto_order;
            NEXT_ST
        case 7:
            s3 = s3 + 1;
            Memu_CtrlFunc((void *)0, ctrl->state);
            NEXT_ST
        case 8:
            s3 = s3 + 1;
            Memu_CtrlFunc(&gsOut->get_goto_order, ctrl->state);
            ctrl->f48 = fl->f8c;
            ctrl->f2c = fl->f84;
            if (ctrl->f48 == 0 && fl->fa4 > 0) {
                u8 buf8[16] __attribute__((aligned(16))) = {0};
                SetFadeMng(9, (signed int *)buf8, fl->fa4, (void *)0, (void *)0, 0, 0);
            }
            if (ctrl->state == ctrl->next) {
                break;
            }
            ctrl->state = s3;
            Menu_SND_Play2D(fl->fb4, 0x64, 0);
        case 9:
            s3 = s3 + 1;
            Memu_CtrlFunc((void *)0, ctrl->state);
            if (ctrl->f48 > 0) {
                ctrl->f48 = ctrl->f48 - 1;
                break;
            } else {
                if (ctrl->f48 == 0) {
                    if (fl->fa4 > 0) {
                        u8 buf9[16] __attribute__((aligned(16))) = {0};
                        SetFadeMng(9, (signed int *)buf9, fl->fa4, (void *)0, (void *)0, 0, 0);
                    }
                    ctrl->f48 = ctrl->f48 - 1;
                }
                if (ctrl->f2c != 0) {
                    ctrl->f2c = ctrl->f2c - 1;
                    if (fl->fa8 == 1) {
                        ctrl->f44 = (float)ctrl->f2c / (float)fl->f80;
                    }
                    if (ctrl->f2c > 0) {
                        break;
                    }
                    ctrl->f44 = 0;
                    break;
                } else {
                    if (ctrl->state == ctrl->next) {
                        ctrl->next = 0xb;
                    }
                    NEXT_ST
                }
            }
        case 10:
            ctrl->f44 = 0;
            Memu_CtrlFunc((void *)0, ctrl->state);
            if (ctrl->state == ctrl->next) {
                break;
            }
            ctrl->state = (u8)s3 + 1;
        case 11:
            ctrl->f44 = 0;
            s3 = 0;
            Memu_CtrlFunc((void *)0, ctrl->state);
            gsOut->get_goto = ctrl->f30;
            if (ctrl->state == ctrl->next) {
                ctrl->next = 0;
            }
            if (ctrl->state == ctrl->next) {
                break;
            }
            ctrl->state = 0;
            continue;
        default:
            break;
        }
        break;
    }
    gsOut->get_state = *(s8 *)&ctrl->state;
    return 1;
}




/* MenuCtrlMng_Update_ExeWaitFunc @ 0x1EBDC0 .. 0x1ECC44 (0xe84 bytes, frame 0x80) */
extern signed int GetKeyState(int);
extern signed int Menu_SND_Play2D(signed int, signed short, signed short);
extern u32 Menu_GetMenuBreakKeyType();
typedef struct {
    u8 ctrl_decide : 1; u8 ctrl_cancel : 1; u8 ctrl_up : 1; u8 ctrl_down : 1;
    u8 ctrl_left : 1; u8 ctrl_right : 1; u8 ctrl_option : 1; u8 item_decide : 1;
    u8 item_cancel : 1; u8 item_up : 1; u8 item_down : 1; u8 item_left : 1;
    u8 item_right : 1; u8 item_option : 1; u8 exe_decide : 1; u8 exe_cancel : 1;
    u8 exe_up : 1; u8 exe_down : 1; u8 exe_left : 1; u8 exe_right : 1;
    u8 exe_option : 1; u8 force_end_none : 1; u8 force_end_end : 1; u8 through : 1;
    u8 pad[5];
} MCE_WaitFlag;
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 1; u8 b5 : 1; u8 b6 : 1; u8 b7 : 1; } MCE_Bits;
typedef struct {
    u8 _p0[0xc];
    s32 set_item_data_on;
    s32 p_data;
    u8 _p1[0x40];
    s32 decide_se_id;
    s32 cancel_se_id;
    u8 _p2[0x64];
} MCE_Param;
typedef struct {
    u8 _p0[0x20];
    MCE_Param *pParam;
    s8 state;
    u8 _p1[0xb];
    u8 menuItemData[0x30];
    s32 func_id;
    u8 _p2[0x1c];
    u8 variable[0x20];
    s32 goto_id;
    s8 state_order;
    u8 _p3[3];
    u8 _p4[0x14];
    MCE_WaitFlag wait_flag;
    u8 _p5[0x1c];
    s32 link_id;
    u8 _p6[0xc];
} MCE_Item;
typedef struct {
    u8 _p0[0x14];
    u32 nItems;
    s32 layersOff;
} MCE_File;
typedef struct {
    u8 _p0[0x20];
    s32 ctrl_goto[7];
    MCE_Bits restart;
    u8 _p1[3];
    s32 item_goto[8];
    s32 exe_goto[8];
} MCE_Layer;
typedef struct {
    u8 _p0[0x20];
    MCE_File *file;
    u8 _p1[0x48];
    MCE_Item *items;
    s8 state;
    u8 _p2[3];
    u8 *pTexIdList;
    s32 now_cursor_id;
    s32 force_change_cursor_id;
    s32 check_cursor_id;
    s8 state_order;
    u8 _p3[3];
    s32 key_enable;
} MCE_Ctrl;
typedef struct { s8 get_state; u8 get_b1; s16 pad; s32 get_goto; s32 get_goto_order; s32 get_call_menu_id; s32 dmy2[12]; } MCE_GS;
typedef struct { u8 *p; u8 pad[12]; } MCE_Arg;
#ifndef MCU_MAPFN_DEFINED
#define MCU_MAPFN_DEFINED
typedef struct {
    u8 name[0x20];
    void (*Get)(void *, s32);
    void (*Set)(void *, s32);
    void (*Decide)(void *, s32);
    void (*CntUp)(void *, s32);
    void (*CntDown)(void *, s32);
    void (*Gene1)(void *, s32);
    void (*Gene2)(void *, s32);
    void (*Evrfrm)(void *, s32, s32);
    void (*Init)(void *, s32, s32);
    void (*Check)(void *, s32, s32);
} MCU_MapFn;
extern MCU_MapFn g_MapFuncTable[];
#endif
static inline void MCE_SetCursor(MCE_Ctrl *c, s32 id) {
    ((MCE_Item *)(c->now_cursor_id * 0xf0 + (u8 *)c->items))->state_order = 0;
    c->now_cursor_id = id;
    ((MCE_Item *)(c->now_cursor_id * 0xf0 + (u8 *)c->items))->state_order = 1;
}

signed int MenuCtrlMng_Update_ExeWaitFunc(void *a0 /* r4 */, void *a1 /* r5 */) {
    MCE_Ctrl *ctrl;
    MCE_GS *gsOut;
    MCE_Item *it;
    s32 key;
    s32 fid;
    MCE_Layer *ly;
    MCE_Layer *ly2;
    MCE_Layer *ly3;
    s32 key2;
    s32 chk;
    MCE_Layer *layers;
    MCE_File *file;
    MCE_Param *tmpl;
    s32 cur;
    MCE_Item *items;
    s32 off;
    MCE_Arg arg;

    ctrl = (MCE_Ctrl *)a0;
    gsOut = (MCE_GS *)a1;
    key = -1;
    file = ctrl->file;
    cur = ctrl->now_cursor_id;
    items = ctrl->items;
    off = file->layersOff;
    it = &items[cur];
    layers = (MCE_Layer *)((u8 *)file + off);
    ly = (MCE_Layer *)((u8 *)layers + (cur << 7));
    g_MapFuncTable[it->func_id].Check(&it->wait_flag, it->pParam->p_data, *(s32 *)&it->func_id);
    fid = it->func_id;
    if (ctrl->key_enable != 0 && GetKeyState(0) == 1 && it->wait_flag.exe_decide == 0) {
        key = ly->exe_goto[0];
    } else if (ctrl->key_enable != 0 && GetKeyState(1) == 1 && it->wait_flag.exe_cancel == 0) {
        key = ly->exe_goto[1];
    } else if (ctrl->key_enable != 0 && GetKeyState(2) == 1 && it->wait_flag.exe_up == 0) {
        key = ly->exe_goto[2];
    } else if (ctrl->key_enable != 0 && GetKeyState(3) == 1 && it->wait_flag.exe_down == 0) {
        key = ly->exe_goto[3];
    } else if (ctrl->key_enable != 0 && GetKeyState(4) == 1 && it->wait_flag.exe_left == 0) {
        key = ly->exe_goto[4];
    } else if (ctrl->key_enable != 0 && GetKeyState(5) == 1 && it->wait_flag.exe_right == 0) {
        key = ly->exe_goto[5];
    } else if (ctrl->key_enable != 0 && GetKeyState(6) == 1 && it->wait_flag.exe_option == 0) {
        key = ly->exe_goto[7];
    }
    if (key != -1) {
        tmpl = it->pParam;
        if (tmpl->set_item_data_on == 1) {
            arg.p = it->menuItemData;
            switch (key) {
            case 1:
                g_MapFuncTable[fid].Get(&arg, it->pParam->p_data);
                break;
            case 2:
                g_MapFuncTable[fid].Set(&arg, it->pParam->p_data);
                break;
            case 3:
                g_MapFuncTable[fid].Decide(&arg, it->pParam->p_data);
                break;
            case 4:
                g_MapFuncTable[fid].CntUp(&arg, it->pParam->p_data);
                break;
            case 5:
                g_MapFuncTable[fid].CntDown(&arg, it->pParam->p_data);
                break;
            case 6:
                g_MapFuncTable[fid].Gene1(&arg, it->pParam->p_data);
                break;
            case 7:
                g_MapFuncTable[fid].Gene2(&arg, it->pParam->p_data);
                break;
            }
        } else {
            switch (key) {
            case 1:
                g_MapFuncTable[fid].Get(it->variable, tmpl->p_data);
                break;
            case 2:
                g_MapFuncTable[fid].Set(it->variable, tmpl->p_data);
                break;
            case 3:
                g_MapFuncTable[fid].Decide(it->variable, tmpl->p_data);
                break;
            case 4:
                g_MapFuncTable[fid].CntUp(it->variable, tmpl->p_data);
                break;
            case 5:
                g_MapFuncTable[fid].CntDown(it->variable, tmpl->p_data);
                break;
            case 6:
                g_MapFuncTable[fid].Gene1(it->variable, tmpl->p_data);
                break;
            case 7:
                g_MapFuncTable[fid].Gene2(it->variable, tmpl->p_data);
                break;
            }
        }
        if (ly->exe_goto[6] == 1) {
            return 1;
        }
    }
    key2 = -1;
    ly2 = (MCE_Layer *)((u8 *)ctrl->file + ctrl->file->layersOff);
    g_MapFuncTable[it->func_id].Check(&it->wait_flag, it->pParam->p_data, *(s32 *)&it->func_id);
    ly3 = (MCE_Layer *)((u8 *)ly2 + (ctrl->now_cursor_id << 7));
    if (ctrl->force_change_cursor_id >= 0) {
        key2 = ctrl->force_change_cursor_id;
        ctrl->force_change_cursor_id = -1;
    } else if (ctrl->key_enable != 0 && GetKeyState(0) == 1 && it->wait_flag.item_decide == 0) {
        key2 = ly3->item_goto[0];
        Menu_SND_Play2D(it->pParam->decide_se_id, 100, 0);
    } else if (ctrl->key_enable != 0 && GetKeyState(0) == 1 && it->wait_flag.item_decide != 0) {
    } else if (ctrl->key_enable != 0 && GetKeyState(1) == 1 && it->wait_flag.item_cancel == 0) {
        key2 = ly3->item_goto[1];
        Menu_SND_Play2D(it->pParam->cancel_se_id, 100, 0);
    } else if (ctrl->key_enable != 0 && GetKeyState(2) == 1 && it->wait_flag.item_up == 0) {
        key2 = ly3->item_goto[2];
    } else if (ctrl->key_enable != 0 && GetKeyState(3) == 1 && it->wait_flag.item_down == 0) {
        key2 = ly3->item_goto[3];
    } else if (ctrl->key_enable != 0 && GetKeyState(4) == 1 && it->wait_flag.item_left == 0) {
        key2 = ly3->item_goto[4];
    } else if (ctrl->key_enable != 0 && GetKeyState(5) == 1 && it->wait_flag.item_right == 0) {
        key2 = ly3->item_goto[5];
    } else if (ctrl->key_enable != 0 && GetKeyState(6) == 1 && it->wait_flag.item_option == 0) {
        key2 = ly3->item_goto[7];
    }
    if (key2 != -1) {
        if (key2 == -2) {
            chk = ctrl->check_cursor_id;
            if (chk >= 0) {
                MCE_SetCursor(ctrl, chk);
            }
        } else if (key2 >= 0) {
            MCE_SetCursor(ctrl, key2);
        }
        if (ly3->item_goto[6] == 1) {
            return 1;
        }
    }
    file = ctrl->file;
    layers = (MCE_Layer *)((u8 *)file + file->layersOff);
    it = (MCE_Item *)(ctrl->now_cursor_id * 0xf0 + (u8 *)ctrl->items);
    if (ctrl->key_enable != 0 && GetKeyState(0) == 1) {
        if (layers[ctrl->now_cursor_id].ctrl_goto[0] != 0) {
            it = (MCE_Item *)(ctrl->now_cursor_id * 0xf0 + (u8 *)ctrl->items);
            g_MapFuncTable[it->func_id].Check(&it->wait_flag, it->pParam->p_data, *(s32 *)&it->func_id);
            if (it->wait_flag.ctrl_decide == 0) {
                gsOut->get_goto_order = layers[ctrl->now_cursor_id].ctrl_goto[0];
                if (layers[ctrl->now_cursor_id].restart.b0 != 0) {
                    ctrl->state_order = 9;
                }
            }
            return 1;
        }
    } else if (ctrl->key_enable != 0 && GetKeyState(1) == 1) {
        if (layers[ctrl->now_cursor_id].ctrl_goto[1] != 0) {
            it = (MCE_Item *)(ctrl->now_cursor_id * 0xf0 + (u8 *)ctrl->items);
            g_MapFuncTable[it->func_id].Check(&it->wait_flag, it->pParam->p_data, *(s32 *)&it->func_id);
            if (it->wait_flag.ctrl_cancel == 0) {
                gsOut->get_goto_order = layers[ctrl->now_cursor_id].ctrl_goto[1];
                if (layers[ctrl->now_cursor_id].restart.b1 != 0) {
                    ctrl->state_order = 9;
                }
            }
            return 1;
        }
    } else if (ctrl->key_enable != 0 && GetKeyState(2) == 1) {
        if (layers[ctrl->now_cursor_id].ctrl_goto[2] != 0) {
            g_MapFuncTable[it->func_id].Check(&it->wait_flag, it->pParam->p_data, *(s32 *)&it->func_id);
            if (it->wait_flag.ctrl_up == 0) {
                gsOut->get_goto_order = layers[ctrl->now_cursor_id].ctrl_goto[2];
                if (layers[ctrl->now_cursor_id].restart.b2 != 0) {
                    ctrl->state_order = 9;
                }
            }
            return 1;
        }
    } else if (ctrl->key_enable != 0 && GetKeyState(3) == 1) {
        if (layers[ctrl->now_cursor_id].ctrl_goto[3] != 0) {
            g_MapFuncTable[it->func_id].Check(&it->wait_flag, it->pParam->p_data, *(s32 *)&it->func_id);
            if (it->wait_flag.ctrl_down == 0) {
                gsOut->get_goto_order = layers[ctrl->now_cursor_id].ctrl_goto[3];
                if (layers[ctrl->now_cursor_id].restart.b3 != 0) {
                    ctrl->state_order = 9;
                }
            }
            return 1;
        }
    } else if (ctrl->key_enable != 0 && GetKeyState(4) == 1) {
        if (layers[ctrl->now_cursor_id].ctrl_goto[4] != 0) {
            g_MapFuncTable[it->func_id].Check(&it->wait_flag, it->pParam->p_data, *(s32 *)&it->func_id);
            if (it->wait_flag.ctrl_left == 0) {
                gsOut->get_goto_order = layers[ctrl->now_cursor_id].ctrl_goto[4];
                if (layers[ctrl->now_cursor_id].restart.b4 != 0) {
                    ctrl->state_order = 9;
                }
            }
            return 1;
        }
    } else if (ctrl->key_enable != 0 && GetKeyState(5) == 1) {
        if (layers[ctrl->now_cursor_id].ctrl_goto[5] != 0) {
            g_MapFuncTable[it->func_id].Check(&it->wait_flag, it->pParam->p_data, *(s32 *)&it->func_id);
            if (it->wait_flag.ctrl_right == 0) {
                gsOut->get_goto_order = layers[ctrl->now_cursor_id].ctrl_goto[5];
                if (layers[ctrl->now_cursor_id].restart.b5 != 0) {
                    ctrl->state_order = 9;
                }
            }
            return 1;
        }
    } else if (ctrl->key_enable != 0) {
        if (GetKeyState(Menu_GetMenuBreakKeyType()) == 1 && layers[ctrl->now_cursor_id].ctrl_goto[1] != 0) {
            g_MapFuncTable[it->func_id].Check(&it->wait_flag, it->pParam->p_data, *(s32 *)&it->func_id);
            if (it->wait_flag.ctrl_cancel == 0) {
                gsOut->get_goto_order = -2;
                if (layers[ctrl->now_cursor_id].restart.b1 != 0) {
                    ctrl->state_order = 9;
                }
                Menu_SND_Play2D(0x13, 100, 0);
            }
            return 1;
        }
    }
    return 1;
}


extern s32 MngState_DrawExeCheck(void *);
extern void *GetTexMngByID(u16);
extern u32 *MakeTexPacket(u32 *,void *);
extern s32 MenuItemMng_Draw(void *,s32,float,float,float,float,float);
extern u32 lpMdlPacketMem;
s32 MenuCtrlMng_Draw(void *arg) {
    u8 *ctrl;
    s32 i;
    u32 layer;
    u8 *data;
    u8 *items;
    u32 packet;
    u8 *cursor;
    u8 *layers;
    s32 offset;
    u32 textures;
    ctrl=arg;
    if (!ctrl) return 0;
    if (MngState_DrawExeCheck(arg)!=1) return 1;
    if (ctrl[0x70]) {
        data=*(u8 **)(ctrl+0x20);
        items=data+0xc0;
        textures=(u32)((u8 *)items+*(u32 *)(data+0x14)*0x80+*(u32 *)(data+0x14)*0xf0+*(u32 *)(data+0x30)*0x40);
        layer=*(u32 *)(data+0x3c)-1;
        {
        u32 layerBase=textures+*(u32 *)(data+0x34)*0x50;
        if ((s32)layer>=0) {
        layers=(u8 *)(layerBase+layer*0x50);
        do {
            if (*(u32 *)(layers+8)==1) {
                i=0;
                if (0<*(s32 *)(data+0x34)) {
                    cursor=(u8 *)textures;
                    offset=0;
                    do {
                        if (layer==*(u32 *)(cursor+4)) {
                            void *tex;
                            packet=lpMdlPacketMem;
                            tex=GetTexMngByID(*(u16 *)(*(u32 *)(ctrl+0x74)+offset));
                            if (tex) lpMdlPacketMem=(u32)MakeTexPacket((u32 *)packet,tex);
                        }
                        ++i; cursor+=0x50; offset+=4;
                    } while(i<*(s32 *)(data+0x34));
                }
            }
            i=0;
            if ((u8 *)0<(u8 *)*(u32 *)(data+0x14)) {
                cursor=items; offset=0;
                do {
                    if (layer==*(u32 *)(cursor+0x38)) {
                        u32 hidden=*(u32 *)(layers+8);
                        float x=*(float *)(ctrl+0x34);
                        u32 base=*(u32 *)(ctrl+0x6c);
                        float y=*(float *)(ctrl+0x38);
                        float z=*(float *)(ctrl+0x3c);
                        if (!MenuItemMng_Draw((void *)(base+offset),hidden==0,x,y,z,*(float *)(ctrl+0x40),*(float *)(ctrl+0x44))) return 0;
                    }
                    ++i; cursor+=0x80; offset+=0xf0;
                } while((u32)i<*(u32 *)(data+0x14));
            }
            --layer; layers-=0x50;
        } while((s32)layer>=0);
        }
        }
    }
    return 1;
}









/* MenuCtrlMng_Delete @ 0x1EBB70 .. 0x1EBBB0 (0x40 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int MenuCtrlMng_Delete(void *a0 /* r4 */) {
    u32 *s0;
    s32 v0;

    s0 = (u32 *)a0;
    v0 = 0;
    if ((u32)s0 == 0) {
        return v0;
    }
    MenuCtrlMng_Free(a0);
    *(u32 *)s0 = 0;
    return (s32)1;
}


/* MenuCtrlMng_SetForceChangeCursorId @ 0x1EBB60 .. 0x1EBB68 (0x8 bytes) */




void MenuCtrlMng_SetForceChangeCursorId(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    *(u32 *)(((u8 *)a0 + 0x7c)) = a1;
    return;
}

u32 sMenuTexListBuf[0x8];
