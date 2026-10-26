#include "common.h"




/* GetMapTexListBuf @ 0x13EBA0 .. 0x13EBB4 (0x14 bytes) */
/*
 * dcomp notes:
 *   return: addu at 0x13ebb0 computes the return value
 */

extern u32 lpMapTexFile[];

extern int strcmp(void *, void *);
extern void *memset(void *, int, unsigned int);
extern void MemFree(void *);
extern u8 TexMngSt[];


extern u32 CheckBloodStain();
extern unsigned int * MakeBloodStain(unsigned int *);
extern u32 MapTexPacket[];


/* SetMapTexListFile @ 0x13EDB0 .. 0x13EDD8 (0x28 bytes) */
/*
 * dcomp notes:
 *   tail: j MakeTexListPacket at 0x13edd0 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern unsigned int *MakeTexListPacket(unsigned int *, void *);
extern u32 MapTexPacket[];
extern u32 lpMapTexFile[];


extern int GetTexSize(int,int,int);
extern int GetClutSize(int,int);
extern unsigned int *LoadImage(int,int,int,int,int,int,int,void *,int,unsigned int *);
typedef struct { unsigned long TBP0:14,TBW:6,PSM:6,TW:4,TH:4,TCC:1,TFX:2,CBP:14,CPSM:4,CSM:1,CSA:5,CLD:3; } M24PacketBits;
typedef struct { u32 total,imageSize; u8 pad[8]; M24PacketBits tex0; u8 other[8]; } M24PacketHead;


static inline unsigned int *MakeTexPacketInl(unsigned int *output,void *texture) {
    u8 *saved;
    M24PacketHead *head;
    void *clut;
    int size;
    u32 image;
    saved=(u8 *)texture;
    head=*(M24PacketHead **)(saved+4);
    size=GetTexSize(1<<head->tex0.TW,1<<head->tex0.TH,head->tex0.PSM);
    image=(u32)((u8 *)head+32);
    clut=(void *)(image+head->imageSize);
    output=LoadImage(head->tex0.TBP0,*(int *)(saved+88),*(int *)(saved+92),0,0,*(int *)(saved+80),*(int *)(saved+84),(void *)image,size,output);
    switch(head->tex0.PSM) {
    case 19: case 27:
        size=GetClutSize(head->tex0.PSM,head->tex0.CPSM);
        output=LoadImage(head->tex0.CBP,1,head->tex0.CPSM,0,0,16,16,clut,size,output);
        break;
    case 20: case 36: case 44:
        size=GetClutSize(head->tex0.PSM,head->tex0.CPSM);
        output=LoadImage(head->tex0.CBP,1,head->tex0.CPSM,0,0,8,2,clut,size,output);
        break;
    }
    return output;
}


/* SetTexList @ 0x13F580 .. 0x13F608 (0x88 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0013F5A8
 */

extern void SetTm2Data(void *, M24PacketHead *, char *);
extern void ResetVramAddr(void);

/* ReadTexList @ 0x13F610 .. 0x13F618 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j ReadMdlLink at 0x13f610 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern void *ReadMdlLink(char *, void **, signed int, signed int);

/* SetTm2Data @ 0x13F7A0 .. 0x13F9D4 (0x234 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   literal: @1273 is the string 'tm2'
 *   literal: @1299 is the string 's0080_016.tm2'
 *   cfg: loop body is not one contiguous region: .L0013F8A8
 *   cfg: kept branch: 0x13f8a8 if (..) goto .L0013F8C0
 *   cfg: kept goto: 0x13f8b4 -> .L0013F8D0
 */

extern signed int GetVramAddr(signed int);
extern void SetNextVramAddr(signed int);
extern char * strcpy(char *, const char *);
extern char * strchr(const char *, int);
extern void SetCrackWall(void *);

struct dw_243711_fields_01eb2e19;
#ifndef PROTO_DW_243136_FIELDS_01EB2E19
#define PROTO_DW_243136_FIELDS_01EB2E19
struct dw_243136_fields_01eb2e19 { unsigned char bUse; unsigned char unused0; unsigned short id; struct dw_243711_fields_01eb2e19 *lpTm2; void *lpTexList; int unused1[1]; unsigned char texName[32]; unsigned char texNameBase[32]; int texW; int texH; int texTBW; int texPSM; };
#endif
#ifndef PROTO_DW_248036_FIELDS_01EB2E19
#define PROTO_DW_248036_FIELDS_01EB2E19
struct dw_248036_fields_01eb2e19 { unsigned long TBP0 : 14; unsigned long TBW : 6; unsigned long PSM : 6; unsigned long TW : 4; unsigned long TH : 4; unsigned long TCC : 1; unsigned long TFX : 2; unsigned long CBP : 14; unsigned long CPSM : 4; unsigned long CSM : 1; unsigned long CSA : 5; unsigned long CLD : 3; };
#endif
#ifndef PROTO_DW_250042_FIELDS_01EB2E19
#define PROTO_DW_250042_FIELDS_01EB2E19
struct dw_250042_fields_01eb2e19 { unsigned long LCM : 1; unsigned long pad01 : 1; unsigned long MXL : 3; unsigned long MMAG : 1; unsigned long MMIN : 3; unsigned long MTBA : 1; unsigned long pad10 : 9; unsigned long L : 2; unsigned long pad21 : 11; unsigned long K : 12; unsigned long pad44 : 20; };
#endif
#ifndef PROTO_DW_243711_FIELDS_01EB2E19
#define PROTO_DW_243711_FIELDS_01EB2E19
struct dw_243711_fields_01eb2e19 { unsigned int size; unsigned int wnum; unsigned char dummy[5]; unsigned char compare; unsigned short tex_id; struct dw_248036_fields_01eb2e19 tex0; struct dw_250042_fields_01eb2e19 tex1; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_243136_FIELDS_01EB2E19_BUSE_76D2AFCD_DEFINED
#define DCOMP_OFF_STRUCT_DW_243136_FIELDS_01EB2E19_BUSE_76D2AFCD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_243136_FIELDS_01EB2E19_BUSE_76D2AFCD = (int)&(((struct dw_243136_fields_01eb2e19 *)0)->bUse) - 0 };
#endif
static inline u8 *TexMngFindFree(void) {
    u8 *m;
    u8 *e;

    m = TexMngSt;
    do {
        if (*m == 0) {
            return m;
        }
        m += 96;
    } while (m != TexMngSt + 0xc000);
    return 0;
}
/* SetMdlShiftTexPacket @ 0x13E920 .. 0x13EB9C (0x27c bytes, frame 0x60) */
extern int strcmp(void *, void *);
extern void * MemAllocReal(unsigned int, char *, char *);
extern int GetTexSize(int,int,int);
extern unsigned int *LoadImage(int,int,int,int,int,int,int,void *,int,unsigned int *);
extern int GetClutSize(int,int);
extern u8 TexMngSt[];

typedef struct { unsigned long TBP0:14,TBW:6,PSM:6,TW:4,TH:4,TCC:1,TFX:2,CBP:14,CPSM:4,CSM:1,CSA:5,CLD:3; } ShiftTm2Bits;
typedef struct { u32 total,imageSize; u8 pad[8]; ShiftTm2Bits tex0; u8 other[8]; } ShiftTm2Head;

typedef struct { u8 pad0[0x5c]; u32 lpTexPacket; u8 pad1[8]; u32 allocSize; } ShiftMdlData;
typedef struct { u8 pad0[12]; ShiftMdlData *lpMdlData; u8 pad1[0x17c]; unsigned int *lpTexPacket; } ShiftMdl;


/* GetTexMngByBaseName @ 0x13F9E0 .. 0x13FA78 (0x98 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: daddu at 0x13fa58 writes a register its branch at 0x13fa54 reads
 *   cfg: loop body is not one contiguous region: .L0013FA08
 *   declaration vs inferred signature: return void * vs inferred u32
 */

extern int strcmp(void *, void *);
extern u8 TexMngSt[];

/* InitTexMng @ 0x13FB70 .. 0x13FBB8 (0x48 bytes, frame 0x10) */

extern void *memset(void *, int, unsigned int);
extern u8 TexMngSt[];
extern u32 lpMapTexFile[];
u8 TexMngSt[0xc000];
u32 MapTexPacket[0x20000];
static u32 lpMapTexFile[0x4];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void InitTexMng(void);
void * GetTexMngByID(unsigned short a0 );
void * GetTexMngByName(void *a0 , char *a1 );
void * GetTexMngByBaseName(void *a0 , char *a1 );
void SetTm2Data(void *lpTexList, M24PacketHead *lpTm2, char *filename);
static void SetTm2TransMode(void *a0 , void *a1 , unsigned int a2 );
void ReadTexList(char *a0 , void **a1 , signed int a2 , signed int a3 );
void SetTexList(void *a0 , unsigned int a1 );
void FreeTexList(void *list);
void SetMdlTexListPacket(void *a0 );
unsigned int *MakeTexListPacket(unsigned int *lpCurDMA, void *lpTexList);
unsigned int *MakeTexPacket(unsigned int *output,void *texture);
unsigned int *LoadImage(int DstBP, int DstBW, int DstPSM, int x, int y, int w, int h, void *lpImage, int ImageSize, unsigned int *lpCurDMA);
void SetMapTexListFile(s32 a0 );
unsigned int * TransMapTexPacket(unsigned int *a0 , signed int a1 , s32 a2);
void FreeMapTex(signed int release);
u32 GetMapTexListBuf(s32 a0 );
void SetMdlShiftTexPacket(ShiftMdl *mdl, void *owner, char *name);


void InitTexMng(void) {
    memset(TexMngSt, 0, 0xc000);
    *(u32 *)((u8 *)&lpMapTexFile + 0xc) = 0;
    *(u32 *)((u8 *)&lpMapTexFile + 8) = 0;
    *(u32 *)((u8 *)&lpMapTexFile + 4) = 0;
    *(u32 *)lpMapTexFile = 0;
    return;
}

/* GetTexMngByID @ 0x13FB20 .. 0x13FB70 (0x50 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0013FB38
 *   declaration vs inferred signature: return void * vs inferred u32
 */

void * GetTexMngByID(unsigned short a0 /* r4 */) {
    u32 a0_2; // a0
    u32 v0;

    v0 = (u32)TexMngSt;
    do {
        a0_2 = *(u8 *)v0;
        if (a0_2 != 0 && (u32)*(u16 *)((v0 + 2)) == (u32)a0) {
            return (void *)v0;
        }
        v0 = v0 + 0x60;
    } while ((u8 *)v0 != (u8 *)(TexMngSt + 0xc000));
    return (void *)(u32)0;
}

/* GetTexMngByName @ 0x13FA80 .. 0x13FB18 (0x98 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: daddu at 0x13faf8 writes a register its branch at 0x13faf4 reads
 *   cfg: loop body is not one contiguous region: .L0013FAA8
 *   declaration vs inferred signature: return void * vs inferred u32
 */




void * GetTexMngByName(void *a0 /* r4 */, char *a1 /* r5 */) {
    u32 s2;
    u32 s1;
    u8 *s0;
    u32 v0;

    s2 = (u32)a0;
    s1 = (u32)a1;
    s0 = TexMngSt;
    do {
        v0 = *(u8 *)s0;
        if (v0 != 0 && (s2 == 0 || (u32)*(s32 *)(s0 + 8) == s2)) {
            a1 = (char *)(s0 + 0x10);
            v0 = strcmp((void *)s1, (void *)a1);
            if (v0 == 0) {
                return (void *)s0;
            }
        }
        s0 = (u8 *)(s0 + 0x60);
    } while (s0 != (u8 *)(TexMngSt + 0xc000));
    return (void *)(u32)0;
}

void * GetTexMngByBaseName(void *a0 /* r4 */, char *a1 /* r5 */) {
    u32 s2;
    u32 s1;
    u8 *s0;
    u32 v0;

    s2 = (u32)a0;
    s1 = (u32)a1;
    s0 = TexMngSt;
    do {
        v0 = *(u8 *)s0;
        if (v0 != 0 && (s2 == 0 || (u32)*(s32 *)(s0 + 8) == s2)) {
            a1 = (char *)(s0 + 0x30);
            v0 = strcmp((void *)s1, (void *)a1);
            if (v0 == 0) {
                return (void *)s0;
            }
        }
        s0 = (u8 *)(s0 + 0x60);
    } while (s0 != (u8 *)(TexMngSt + 0xc000));
    return (void *)(u32)0;
}
void SetTm2Data(void *lpTexList, M24PacketHead *lpTm2, char *filename) {
    int texSize;
    int clutSize;
    u8 *mng;
    char *ext;
    unsigned int mode;

    texSize = GetTexSize(1 << lpTm2->tex0.TW, 1 << lpTm2->tex0.TH, lpTm2->tex0.PSM);
    clutSize = GetClutSize(lpTm2->tex0.PSM, lpTm2->tex0.CPSM);
    lpTm2->tex0.TBP0 = GetVramAddr(0x100);
    SetNextVramAddr(texSize);
    lpTm2->tex0.CBP = GetVramAddr(0x100);
    SetNextVramAddr(clutSize);
    mng = TexMngFindFree();
    *mng = 1;
    *(u16 *)(mng + 2) = (mng - TexMngSt) / 96 + 1;
    *(u32 *)(mng + 4) = (u32)lpTm2;
    *(u32 *)(mng + 8) = (u32)lpTexList;
    strcpy((char *)(mng + 0x10), filename);
    strcpy((char *)(mng + 0x30), filename);
    ext = strchr((char *)(mng + 0x10), 0x2e);
    if (strcmp(ext + 1, "tm2") == 0) {
        mode = 0;
    } else {
        strcpy(ext + 1, "tm2");
        mode = 1;
    }
    SetTm2TransMode(mng, lpTm2, mode);
    if (strcmp(filename, "s0080_016.tm2") == 0) {
        SetCrackWall(lpTexList);
    }
    strcpy(filename, (char *)(mng + 0x10));
}

/* SetTm2TransMode @ 0x13F620 .. 0x13F798 (0x178 bytes) */
/*
 * dcomp notes:
 *   delay: sra at 0x13f6b0 writes a register its branch at 0x13f6ac reads
 *   cfg: kept branch: 0x13f648 if (..) goto .L0013F698
 *   cfg: kept goto: 0x13f660 -> .L0013F790
 *   declaration vs inferred signature: return void vs inferred u32
 */

static void SetTm2TransMode(void *a0 /* r4 */, void *a1 /* r5 */, unsigned int a2 /* r6 */) {
    u32 t0;
    u64 v1_64;
    s32 a3;
    u8 *a1_bytes; // a1
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    a1_bytes = (u8 *)a1;
    a3 = 1;
    v1_64 = *(u64 *)(a1_bytes + 0x10);
    t0 = ((struct { unsigned char _pad:2; unsigned char f:4; } *)&*(u8 *)(a1_bytes + 0x13))->f;
    v1_64 = v1_64 << 0x1e;
    t0 = (u32)a3 << t0;
    v1_64 = v1_64 >> 0x3c;
    a3 = (u32)a3 << v1_64;
    if ((u32)(s32)a2 != 0) {
        if ((u64)((u64)((u64)(u32)*(u16 *)(a1_bytes + 0x12) << 0x36) >> 0x3a) != 0) {
            goto _L0013F698;
        }
    }
    *(u32 *)(a0_bytes + 0x50) = t0;
    *(u32 *)(a0_bytes + 0x54) = a3;
    v1_64 = (u64)((u64)*(u64 *)(a1_bytes + 0x10) << 0x2c) >> 0x3a;
    *(u32 *)(a0_bytes + 0x58) = v1_64;
    v1 = ((struct { unsigned short _pad:4; unsigned short f:6; } *)&*(u16 *)(a1_bytes + 0x12))->f;
    *(u32 *)(a0_bytes + 0x5c) = v1;
    goto _L0013F790;
    _L0013F698:;
    *(u32 *)(a0_bytes + 0x5c) = 0;
    v1 = ((struct { unsigned short _pad:4; unsigned short f:6; } *)&*(u16 *)(a1_bytes + 0x12))->f &
        3;
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x50) = (s32)t0 / (s32)(2);
        *(u32 *)(a0_bytes + 0x54) = a3 / (s32)(2);
        a1_bytes = (u8 *)(s32)(*(s32 *)(a0_bytes + 0x50) + 0x3f);
        v1 = (s32)a1_bytes / (s32)(0x40);
        *(u32 *)(a0_bytes + 0x58) = v1;
    } else {
        v1 = (s32)t0 < (s32)0x80;
        if (v1 != 0 || a3 < (s32)0x80) {
            *(u32 *)(a0_bytes + 0x50) = a3 / (s32)(2);
            v1 = (s32)t0 / (s32)(4);
            *(u32 *)(a0_bytes + 0x54) = v1;
        } else {
            *(u32 *)(a0_bytes + 0x50) = (s32)t0 / (s32)(2);
            *(u32 *)(a0_bytes + 0x54) = a3 / (s32)(4);
        }
        a1_bytes = (u8 *)(s32)(*(s32 *)(a0_bytes + 0x50) + 0x3f);
        v1 = (s32)a1_bytes / (s32)(0x40);
        *(u32 *)(a0_bytes + 0x58) = v1;
    }
    _L0013F790:;
    return;
}

void ReadTexList(char *a0 /* r4 */, void **a1 /* r5 */, signed int a2 /* r6 */, signed int a3 /* r7
        */) {
    ReadMdlLink(a0, a1, a2, a3);
    return;
}

void SetTexList(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u32 *s2;
    s32 s1;
    u32 s0;
    u32 a2;

    s2 = (u32 *)a0;
    s0 = (u32)s2;
    s1 = (s32)a1;
    if (s0 != 0) {
        do {
            a1 = *(s32 *)((s0 + 0x10));
            a2 = *(s32 *)((s0 + 0xc));
            SetTm2Data((void *)(u32 *)s2, (void *)a1, (char *)a2);
            s0 = *(s32 *)((s0 + 0x18));
            if ((u32)s1 == (u32)2) {
                ResetVramAddr();
            }
        } while (s0 != 0);
    }
    if ((u32)s1 == (u32)1) {
        ResetVramAddr();
    }
    return;
}





void FreeTexList(void *list) {
    u32 owner;
    u8 *link;
    u8 *record;
    u32 name;
    u8 *end;
    u8 *selected;

    owner = (u32)list;
    link = (u8 *)owner;
    if (owner != 0) {
        goto test;
    }
    return;
body:
    name = *(u32 *)(link + 12);
    record = TexMngSt;
    end = TexMngSt + 0xc000;
    do {
        if (*record != 0 && (owner == 0 || *(u32 *)(record + 8) == owner) &&
            strcmp((void *)name, (void *)(record + 16)) == 0) {
            selected = record;
            goto found;
        }
        record += 96;
    } while (record != end);
    selected = 0;
found:
    if (selected != 0) {
        *selected = 0;
        memset(selected, 0, 96);
    }
    link = (u8 *)*(u32 *)(link + 24);
test:
    if (link != 0) goto body;
}


/* SetMdlTexListPacket @ 0x13F460 .. 0x13F4A0 (0x40 bytes, frame 0x20) */

void SetMdlTexListPacket(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u8 *v0;

    v1 = *(s32 *)(((u8 *)a0 + 0x44));
    s0 = (u8 *)a0;
    if (v1 != 0) {
        *(u32 *)(s0 + 4) = (s32)(u8 *)(s32)1;
        v0 = (u8 *)MakeTexListPacket((unsigned int *)*(s32 *)(s0 + 0x60), (void *)*(s32 *)(s0 +
            0x44));
        *(u32 *)(s0 + 0x60) = (u32)v0;
    }
    return;
}
unsigned int *MakeTexListPacket(unsigned int *lpCurDMA, void *lpTexList) {
    u32 owner;
    u8 *link;
    u8 *record;
    u32 name;
    u8 *end;
    u8 *selected;

    owner = (u32)lpTexList;
    link = (u8 *)owner;
    if (link == 0) {
        goto tail;
    }
body:
    name = *(u32 *)(link + 12);
    record = TexMngSt;
    end = TexMngSt + 0xc000;
    do {
        if (*record != 0 && (owner == 0 || *(u32 *)(record + 8) == owner) &&
            strcmp((void *)name, (void *)(record + 16)) == 0) {
            selected = record;
            goto found;
        }
        record += 96;
    } while (record != end);
    selected = 0;
found:
    if (selected != 0) {
        lpCurDMA = MakeTexPacketInl(lpCurDMA, selected);
    }
    link = (u8 *)*(u32 *)(link + 24);
test:
    if (link != 0) goto body;
tail:
    lpCurDMA[0] = 0x60000000;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0;
    return lpCurDMA + 4;
}
unsigned int *MakeTexPacket(unsigned int *output,void *texture) {
    u8 *saved;
    M24PacketHead *head;
    void *clut;
    int size;
    u32 image;
    saved=(u8 *)texture;
    head=*(M24PacketHead **)(saved+4);
    size=GetTexSize(1<<head->tex0.TW,1<<head->tex0.TH,head->tex0.PSM);
    image=(u32)((u8 *)head+32);
    clut=(void *)(image+head->imageSize);
    output=LoadImage(head->tex0.TBP0,*(int *)(saved+88),*(int *)(saved+92),0,0,*(int *)(saved+80),*(int *)(saved+84),(void *)image,size,output);
    switch(head->tex0.PSM) {
    case 19: case 27:
        size=GetClutSize(head->tex0.PSM,head->tex0.CPSM);
        output=LoadImage(head->tex0.CBP,1,head->tex0.CPSM,0,0,16,16,clut,size,output);
        break;
    case 20: case 36: case 44:
        size=GetClutSize(head->tex0.PSM,head->tex0.CPSM);
        output=LoadImage(head->tex0.CBP,1,head->tex0.CPSM,0,0,8,2,clut,size,output);
        break;
    }
    return output;
}

/* LoadImage @ 0x13EDE0 */
unsigned int *LoadImage(int DstBP, int DstBW, int DstPSM, int x, int y, int w, int h, void *lpImage, int ImageSize, unsigned int *lpCurDMA) {
    int TransQWC;
    int bpl;
    int offsetY;
    int loops;
    int line;
    int trans;

    TransQWC = (ImageSize + 0xf) / 0x10;
    offsetY = 0;
    bpl = ImageSize / h;
    loops = 2;
    if (TransQWC == 0 || lpImage == 0) {
        return lpCurDMA;
    }
    do {
        if (TransQWC > 0x7fff) {
            line = 0x7fff0 / bpl;
            trans = (line * bpl) / 16;
        } else {
            trans = TransQWC;
            line = (TransQWC << 4) / bpl;
        }
        lpCurDMA[0] = 0x10000007;
        lpCurDMA[1] = 0;
        lpCurDMA[2] = 0;
        lpCurDMA[3] = 0x51000007;
        lpCurDMA[4] = 5;
        lpCurDMA[5] = 0x10000000;
        lpCurDMA[6] = 0xe;
        lpCurDMA[7] = 0;
        *(u64 *)(lpCurDMA + 8) = 0;
        *(s64 *)(lpCurDMA + 0xa) = 0x3f;
        *(u64 *)(lpCurDMA + 0xc) = ((u64)(s32)DstBP << 0x20) | ((u64)(s32)DstBW << 0x30) | ((u64)(s32)DstPSM << 0x38);
        *(s64 *)(lpCurDMA + 0xe) = 0x50;
        *(u64 *)(lpCurDMA + 0x10) = ((u64)(s32)x << 0x20) | ((u64)(s32)(y + offsetY) << 0x30);
        *(s64 *)(lpCurDMA + 0x12) = 0x51;
        *(u64 *)(lpCurDMA + 0x14) = (u64)(s32)w | ((u64)(s32)h << 0x20);
        *(s64 *)(lpCurDMA + 0x16) = 0x52;
        *(u64 *)(lpCurDMA + 0x18) = 0;
        *(s64 *)(lpCurDMA + 0x1a) = 0x53;
        lpCurDMA[0x1c] = trans | 0x8000;
        lpCurDMA[0x1d] = 0x8000000;
        lpCurDMA[0x1e] = 0;
        lpCurDMA[0x1f] = 0;
        lpCurDMA[0x20] = trans | 0x30000000;
        lpCurDMA[0x21] = (u32)lpImage;
        lpCurDMA[0x22] = 0;
        lpCurDMA[0x23] = trans | 0x51000000;
        lpCurDMA += 0x24;
        lpImage = (u8 *)lpImage + (trans << 4);
        offsetY += line;
        TransQWC -= trans;
        loops--;
    } while (TransQWC > 0 && loops > 0);
    return lpCurDMA;
}

void SetMapTexListFile(s32 a0 /* r4 */) {
    u32 *v0;

    v0 = MapTexPacket;
    v0 = lpMapTexFile;
    MakeTexListPacket((unsigned int *)((u8 *)MapTexPacket + (u32)((u32)a0 << 0x11)), (void *)*(s32
        *)(u32 *)(u32)&((struct { u8 b[4]; } *)lpMapTexFile)[a0]);
    return;
}

unsigned int * TransMapTexPacket(unsigned int *a0 /* r4 */, signed int a1 /* r5 */, s32 a2) {
    u32 *lpCurDMA = (u32 *)a1;

    if (((u32 *)lpMapTexFile)[a2] == 0) {
        return lpCurDMA;
    }
    lpCurDMA[0] = 0x50000000;
    lpCurDMA[1] = (u32)((u8 *)MapTexPacket + (a2 << 0x11));
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0;
    lpCurDMA += 4;
    if (CheckBloodStain() != 0) {
        lpCurDMA = MakeBloodStain(lpCurDMA);
    }
    return lpCurDMA;
}
void FreeMapTex(signed int release)
{
    s32 index;
    u32 owner;
    u32 file;
    u8 *cursor;
    u32 name;
    u32 *slot;
    u8 *end;
    u8 *selected;
    index = 0;
    slot = lpMapTexFile;
    while (1) {
        owner = *slot;
        file = owner;
        if (owner != 0) {
            if (owner == 0) goto releaseSlot;
            goto setup;
nextFile:
            cursor = TexMngSt;
            name = *(u32 *)(file + 0xc);
            while (cursor != end) {
                if (*cursor != 0 && (owner == 0 || *(u32 *)(cursor + 8) == owner) &&
                    strcmp((void *)name, cursor + 0x10) == 0) {
                    selected = cursor;
                    goto found;
                }
                cursor += 0x60;
            }
            selected = 0;
found:
            if (selected != 0) {
                *selected = 0;
                memset(selected, 0, 0x60);
            }
            file = *(u32 *)(file + 0x18);
checkFile:
            if (file != 0) goto nextFile;
releaseSlot:
            if (release) MemFree((void *)*slot);
            *slot = 0;
        }
        ++index;
        ++slot;
        if (index < 4) continue;
        return;
setup:
        end = TexMngSt + 0xc000;
        goto checkFile;
    }
}

u32 GetMapTexListBuf(s32 a0 /* r4 */) {
    return (u32)((u8 *)(u8 *)lpMapTexFile + (u32)((u32)a0 << 2));
}

void SetMdlShiftTexPacket(ShiftMdl *mdl, void *owner, char *name) {
    unsigned int *pkt;
    u8 *record;
    u8 *selected;
    unsigned int *out;
    ShiftTm2Head *head;
    void *clut;
    int size;
    u32 image;

    if (mdl->lpMdlData->lpTexPacket != 0) {
        record = TexMngSt;
        do {
            if (*record != 0 && (owner == 0 || *(void **)(record + 8) == owner) &&
                strcmp(name, (void *)(record + 16)) == 0) {
                selected = record;
                goto found;
            }
            record += 96;
        } while (record != TexMngSt + 0xc000);
        selected = 0;
found:
        if (selected != 0 && mdl->lpTexPacket == 0) {
            mdl->lpTexPacket = MemAllocReal(mdl->lpMdlData->allocSize, (char *)__FUNCTION__, "");
            head = *(ShiftTm2Head **)(selected + 4);
            pkt = mdl->lpTexPacket;
            size = GetTexSize(1 << head->tex0.TW, 1 << head->tex0.TH, head->tex0.PSM);
            image = (u32)((u8 *)head + 32);
            clut = (void *)(image + head->imageSize);
            out = LoadImage(head->tex0.TBP0, *(int *)(selected + 88), *(int *)(selected + 92), 0, 0, *(int *)(selected + 80), *(int *)(selected + 84), (void *)image, size, pkt);
            switch (head->tex0.PSM) {
            case 19: case 27:
                size = GetClutSize(head->tex0.PSM, head->tex0.CPSM);
                out = LoadImage(head->tex0.CBP, 1, head->tex0.CPSM, 0, 0, 16, 16, clut, size, out);
                break;
            case 20: case 36: case 44:
                size = GetClutSize(head->tex0.PSM, head->tex0.CPSM);
                out = LoadImage(head->tex0.CBP, 1, head->tex0.CPSM, 0, 0, 8, 2, clut, size, out);
                break;
            }
            out[0] = 0x60000000;
            out[1] = 0;
            out[2] = 0;
            out[3] = 0;
        }
    }
}
