#include "common.h"
typedef struct { unsigned int v[16]; } ShMat;
struct ShBox { u8 pad[8]; short MM[2][3]; };
struct ShCyl { float P[4]; float N[4]; float H; float R; u8 pad[8]; };
struct ShInner { struct ShCyl Cylinder; float WorldPos[4]; float GeomScale; u8 pad[12]; };
float gShadowDir[4] = {1.0f, 1.0f, 1.0f, 0.0f};
static unsigned int * MakeAndDrawShadowModel(unsigned int *, void *);
extern u32 lpMdlPacketMem;
extern void CsMngSetBufType(unsigned int);
extern unsigned int CheckDrawModel(void *);
extern u8 GameSt[];
extern u8 MdlMng[];
extern void DrawSetViewScreenClipMatrix(void *, void *, void *, float, float, float, float, float,
    float, float, float, float, float, float);
static u32 gShadowVSMat[0x10];
static u32 gShadowLCMat[0x10];
static u32 ClearShadowTexture(u8 *a0 /* r4 */);
void MGDrawShadow(void *a0 /* r4 */);
void DrawShadow(void);
static unsigned int * MakePresetShadowPrimListPacket(unsigned int *a0 /* r4 */, void *a1 /* r5 */);
void InitShadowMatrix(void);

/* InitShadowMatrix @ 0x1682D0 .. 0x168354 (0x84 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f860418 at 0x168308
 *   fpu: float literal 0x45000000 at 0x168310
 *   fpu: float literal 0x3f800000 at 0x16831c
 *   fpu: float literal 0x00000000 at 0x168320
 *   fpu: float literal 0x4b7fff00 at 0x16832c
 *   fpu: mov.s at 0x168330 is a float copy
 *   fpu: float literal 0x3d4ccccd at 0x16833c
 *   fpu: mov.s at 0x168344 is a float copy
 *   stack: address of the slot at 0x30 escapes at 0x168340
 */


void InitShadowMatrix(void) {
    s32 v1;
    u8 stackFrame_30[64] __attribute__((aligned(16)));

    v1 = 0x44ff0000 | 0xe000;
    DrawSetViewScreenClipMatrix((void *)gShadowVSMat, (void *)gShadowLCMat, (void *)(u8 *)((u8
        *)&stackFrame_30[0]), 1.04699993f, 1.0f, (float)(float)1.0f, 2048.0f,
        (float)(float)2048.0f, 0.0f, 16776960.0f, 0.0500000007f, 100.0f, 2047.0f, 2047.0f);
    return;
}


/* MakePresetShadowObjPacket @ 0x168220 .. 0x1682C8 (0xa8 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: lui at 0x168290 writes a register its branch at 0x16828c reads
 *   cfg: loop body is not one contiguous region: .L00168240
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */

unsigned int * MakePresetShadowObjPacket(unsigned int *a0 /* r4 */, void *a1 /* r5 */) {
    u32 t9;
    s32 t8;
    u32 *v1;
    u32 v0;

    t9 = (u32)a1;
    t8 = *(s32 *)(((u8 *)a1 + 0x44));
    v0 = *(s32 *)(((u8 *)a1 + 0x5c));
    *(u32 *)((v0 + 8)) = (u32)a0;
    if ((u32)t8 != 0) {
        do {
            v0 = *(s32 *)((t8 + 0x2c));
            if (v0 != 0) {
                v0 = *(s32 *)((v0 + 0x2c));
                if (v0 != 0 && (u32)*(u8 *)v0 != 0) {
                    v0 = (u32)MakePresetShadowPrimListPacket(a0, (void *)(u32)t8);
                    a0 = (unsigned int *)v0;
                }
            }
            t8 = *(s32 *)((t8 + 8));
        } while ((u32)t8 != 0);
    }
    v0 = *(s32 *)((t9 + 0x5c));
    v1 = (u32 *)(s32)(v0 + 8);
    v0 = *(s32 *)((v0 + 8));
    if ((u32)a0 != v0) {
        v0 = 0x60000000;
        *(u32 *)a0 = 0x60000000;
        a0[1] = 0;
        a0[2] = 0;
        a0[3] = 0;
        a0 = (unsigned int *)((u8 *)a0 + 0x10);
    } else {
        *(u32 *)v1 = 0;
    }
    return (unsigned int *)a0;
}

/* MakePresetShadowPrimListPacket @ 0x168130 .. 0x168220 (0xf0 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */




static unsigned int * MakePresetShadowPrimListPacket(unsigned int *a0 /* r4 */, void *a1 /* r5 */) {
    u32 v0;
    u32 t7;
    s32 a2;
    u8 t5;
    u_long128 t6;
    u32 t2;
    u32 t1;

    v0 = 0x6c010000;
    t7 = 0x10000000 | 1;
    *(u32 *)a0 = t7;
    *(u32 *)(((u8 *)a0 + 4)) = 0;
    v0 = 0x302e0000;
    *(u32 *)(((u8 *)a0 + 8)) = 0;
    *(u32 *)(((u8 *)a0 + 0xc)) = 0x6c010000 | 0x800e;
    v0 = 0x1000000;
    t6 = *(u_long128 *)a1;
    v0 = 0x6d000000;
    t1 = 0x30000000;
    a2 = 0x17000000;
    *(u_long128 *)(((u8 *)a0 + 0x10)) = t6;
    *(u32 *)(((u8 *)a0 + 0x20)) = t7;
    *(u32 *)(((u8 *)a0 + 0x24)) = 0;
    *(u32 *)(((u8 *)a0 + 0x28)) = 0;
    *(u32 *)(((u8 *)a0 + 0x2c)) = 0x6c010000 | 0x800f;
    t5 = *(u8 *)(((u8 *)a1 + 3));
    *(u32 *)(((u8 *)a0 + 0x30)) = (u32)(t5) | 0x8000;
    *(u32 *)(((u8 *)a0 + 0x34)) = 0x302e0000 | 0x4000;
    *(u32 *)(((u8 *)a0 + 0x38)) = 0x412;
    *(u32 *)(((u8 *)a0 + 0x3c)) = 0;
    *(u32 *)(((u8 *)a0 + 0x40)) = 0x10000000;
    *(u32 *)(((u8 *)a0 + 0x44)) = 0;
    *(u32 *)(((u8 *)a0 + 0x48)) = 0;
    *(u32 *)(((u8 *)a0 + 0x4c)) = 0x1000000 | 0x104;
    t2 = *(u8 *)(((u8 *)a1 + 3));
    t2 = t2 << 3;
    *(u32 *)(((u8 *)a0 + 0x50)) = (u32)((u32)((u32)(t2) >> 4) + (s32)((u32)(t2 & 0xf) != 0)) |
        0x30000000;
    t1 = *(s32 *)(((u8 *)a1 + 0xc));
    *(u32 *)(((u8 *)a0 + 0x54)) = t1;
    *(u32 *)(((u8 *)a0 + 0x58)) = 0;
    a1 = (void *)*(u8 *)(((u8 *)a1 + 3));
    a1 = (void *)(s32)((u32)a1 << 0x10);
    *(u32 *)(((u8 *)a0 + 0x5c)) = (u32)((u32)(a1)) | (u32)(0x6d000000 | 0x8010);
    *(u32 *)(((u8 *)a0 + 0x60)) = 0x10000000;
    *(u32 *)(((u8 *)a0 + 0x64)) = 0;
    *(u32 *)(((u8 *)a0 + 0x68)) = 0;
    *(u32 *)(((u8 *)a0 + 0x6c)) = 0x1000000 | 0x404;
    *(u32 *)(((u8 *)a0 + 0x70)) = 0x10000000;
    *(u32 *)(((u8 *)a0 + 0x74)) = 0;
    *(u32 *)(((u8 *)a0 + 0x78)) = 0;
    *(u32 *)(((u8 *)a0 + 0x7c)) = 0x17000000;
    return (unsigned int *)(u32)(s32)((u8 *)a0 + 0x80);
}


/* DrawShadow @ 0x168060 .. 0x16812C (0xcc bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x168090 writes a register its branch at 0x16808c reads
 *   cfg: loop body is not one contiguous region: .L001680B8
 */


void DrawShadow(void) {
    u8 a0;
    u8 *s1;
    u8 v1;
    u32 s0;
    u32 v0;

    v1 = GameSt[0xb];
    s0 = lpMdlPacketMem;
    if ((u32)v1 != 0) {
        a0 = GameSt[6];
        if ((u32)a0 != (u32)2) {
            CsMngSetBufType(1);
            s1 = (u8 *)(MdlMng + 0x5400);
            if (s1 < (u8 *)(MdlMng + 0x1a240)) {
                do {
                    v0 = *(u8 *)s1;
                    if (v0 != 0 && (u32)*(s32 *)((*(s32 *)(s1 + 0xc) + 0x1c)) != 0) {
                        v0 = CheckDrawModel((void *)s1);
                        if (v0 != 0) {
                            v0 = (u32)MakeAndDrawShadowModel((unsigned int *)s0, (void *)(u8 *)s1);
                            s0 = v0;
                        }
                    }
                    s1 = (u8 *)(s1 + 0x1c0);
                } while (s1 < (u8 *)(MdlMng + 0x1a240));
            }
            CsMngSetBufType(0);
            lpMdlPacketMem = s0;
        }
    }
    return;
}


/* MGDrawShadow @ 0x168000 .. 0x16805C (0x5c bytes, frame 0x10) */


void MGDrawShadow(void *a0 /* r4 */) {
    u8 *a1;
    u8 v1;
    u8 *v0;

    a1 = (u8 *)a0;
    v1 = *(u8 *)a1;
    a0 = (void *)lpMdlPacketMem;
    if ((u32)v1 == 0 || (u32)*(u8 *)(a1 + 2) != 0 || (u32)*(s32 *)((*(s32 *)(a1 + 0xc) + 0x1c)) ==
        0) {
        return;
    }
    v0 = (u8 *)MakeAndDrawShadowModel((unsigned int *)a0, (void *)a1);
    lpMdlPacketMem = (u32)v0;
    return;
}



static unsigned int *MakeShadowTexture(unsigned int *, void *);
static unsigned int *DrawDropShadowModel(unsigned int *, void *, void *);
extern u32 lpDrawMng;
static unsigned int *MakeAndDrawShadowModel(unsigned int *packet, void *model)
{
    u32 cursor;
    u8 *shadow;
    u8 *environment;
    u32 original;
    u32 manager;
    shadow = model;
    manager = lpDrawMng;
    if (*(s32 *)(manager + 0x408) == 0) environment = (u8 *)(manager + 0x60);
    else environment = (u8 *)(manager + 0x150);
    original = (u32)packet;
    packet = MakeShadowTexture(packet, shadow);
    if ((u32)packet == original) return packet;
    if (GameSt[5] != 4) {
        if (shadow[7] != 2) {
            cursor = (u32)MdlMng;
            if ((u8 *)cursor < (u8 *)(MdlMng + 0xfc00)) {
                do {
                    if (*(u8 *)cursor != 0 && *(u8 *)(*(u32 *)(cursor + 12) + 14) == 1) {
                        if (CheckDrawModel((void *)cursor) != 0 && cursor != (u32)shadow)
                            packet = DrawDropShadowModel(packet, (void *)cursor, shadow);
                    }
                    cursor += 448;
                } while ((u8 *)cursor < (u8 *)(MdlMng + 0xfc00));
            }
        } else {
            cursor = (u32)(MdlMng + 0x5400);
            if ((u8 *)cursor < (u8 *)(MdlMng + 0xfc00)) {
                do {
                    if (*(u8 *)cursor != 0 && *(u8 *)(*(u32 *)(cursor + 12) + 14) == 2) {
                        if (CheckDrawModel((void *)cursor) != 0 && cursor != (u32)shadow)
                            packet = DrawDropShadowModel(packet, (void *)cursor, shadow);
                    }
                    cursor += 448;
                } while ((u8 *)cursor < (u8 *)(MdlMng + 0xfc00));
            }
        }
    } else packet = DrawDropShadowModel(packet, (void *)(MdlMng + 0x5400), shadow);
    packet[0] = 0x10000003;
    packet[1] = 0;
    packet[2] = 0;
    packet[3] = 0x50000003;
    packet[4] = 0x8002;
    packet[5] = 0x10000000;
    packet[6] = 14;
    packet[7] = 0;
    *(u64 *)(packet + 8) = *(u64 *)(environment + 16);
    *(u64 *)(packet + 10) = 78;
    *(u64 *)(packet + 12) = 0;
    *(u64 *)(packet + 14) = 8;
    return packet + 16;
}



#define MS_WRAP(a) ((3.1415927f + (a)) >= 0.0f ? ((a) - (6.2831855f * (float)(s32)((3.1415927f + (a)) / 6.2831855f))) : (6.2831855f + ((a) - (6.2831855f * (float)(s32)((3.1415927f + (a)) / 6.2831855f)))))
/* MakeShadowTexture @ 0x167370 .. 0x167DDC (0xa6c bytes, frame 0x130) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3aa7c5ac at 0x1673d8
 *   fpu: float literal 0x3e800000 at 0x167438
 *   fpu: float literal 0x3c23d70a at 0x16744c
 *   fpu: float literal 0x3fc00000 at 0x1674c8
 *   fpu: float literal 0x3f800000 at 0x1674e0
 *   fpu: mov.s at 0x167518 is a float copy
 *   fpu: float literal 0x42000000 at 0x167524
 *   fpu: float literal 0x3f800000 at 0x16752c
 *   fpu: float literal 0x4f000000 at 0x167540
 *   fpu: mov.s at 0x1676e4 is a float copy
 *   fpu: mov.s at 0x167700 is a float copy
 *   stack: address of the slot at 0xf0 escapes at 0x167704
 *   fpu: float literal 0x40490fdb at 0x167718
 *   fpu: float literal 0x00000000 at 0x16771c
 *   fpu: float literal 0x40c90fdb at 0x16773c
 *   fpu: mtc1 reinterprets v0 at 0x167760
 *   stack: address of the slot at 0xf0 escapes at 0x167784
 *   stack: address of the slot at 0xf0 escapes at 0x167784
 *   fpu: float literal 0x40490fdb at 0x167798
 *   fpu: float literal 0x00000000 at 0x16779c
 *   fpu: float literal 0x40c90fdb at 0x1677bc
 *   fpu: mtc1 reinterprets v0 at 0x1677e0
 *   stack: address of the slot at 0xf0 escapes at 0x167804
 *   stack: address of the slot at 0xf0 escapes at 0x167804
 *   fpu: float literal 0x40490fdb at 0x167818
 *   fpu: float literal 0x00000000 at 0x16781c
 *   fpu: float literal 0x40c90fdb at 0x16783c
 *   fpu: mtc1 reinterprets v0 at 0x167860
 *   stack: address of the slot at 0xf0 escapes at 0x167884
 *   stack: address of the slot at 0xf0 escapes at 0x167884
 *   fpu: float literal 0x40490fdb at 0x167894
 *   fpu: float literal 0x00000000 at 0x1678a0
 *   fpu: float literal 0x40c90fdb at 0x1678c0
 *   fpu: float literal 0x40c90fdb at 0x1678e8
 *   stack: address of the slot at 0xf0 escapes at 0x16790c
 *   stack: address of the slot at 0xf0 escapes at 0x16790c
 *   fpu: float literal 0x40490fdb at 0x16791c
 *   fpu: float literal 0x00000000 at 0x167920
 *   fpu: float literal 0x40c90fdb at 0x167940
 *   fpu: mtc1 reinterprets v0 at 0x167964
 *   stack: address of the slot at 0xf0 escapes at 0x167988
 *   stack: address of the slot at 0xf0 escapes at 0x167988
 *   stack: address of the slot at 0xf0 escapes at 0x16799c
 *   stack: address of the slot at 0xf0 escapes at 0x16799c
 *   stack: address of the slot at 0x100 escapes at 0x1679b0
 *   stack: address of the slot at 0x100 escapes at 0x1679b0
 *   stack: address of the slot at 0x110 escapes at 0x1679c4
 *   stack: address of the slot at 0x110 escapes at 0x1679c4
 *   stack: address of the slot at 0xf0 escapes at 0x167a50
 *   stack: address of the slot at 0xf0 escapes at 0x167a80
 *   stack: address of the slot at 0xb0 escapes at 0x167a98
 *   fpu: float literal 0x40490fdb at 0x167aac
 *   fpu: float literal 0x00000000 at 0x167ab0
 *   fpu: float literal 0x40c90fdb at 0x167ad0
 *   fpu: mtc1 reinterprets v0 at 0x167af4
 *   stack: address of the slot at 0xb0 escapes at 0x167b18
 *   stack: address of the slot at 0xb0 escapes at 0x167b18
 *   fpu: float literal 0x40490fdb at 0x167b2c
 *   fpu: float literal 0x00000000 at 0x167b30
 *   fpu: float literal 0x40c90fdb at 0x167b50
 *   fpu: mtc1 reinterprets v0 at 0x167b74
 *   stack: address of the slot at 0xb0 escapes at 0x167b98
 *   stack: address of the slot at 0xb0 escapes at 0x167b98
 *   fpu: float literal 0x40490fdb at 0x167bac
 *   fpu: float literal 0x00000000 at 0x167bb0
 *   fpu: float literal 0x40c90fdb at 0x167bd0
 *   fpu: mtc1 reinterprets v0 at 0x167bf4
 *   stack: address of the slot at 0xb0 escapes at 0x167c18
 *   stack: address of the slot at 0xb0 escapes at 0x167c18
 *   stack: address of the slot at 0xb0 escapes at 0x167c28
 *   stack: address of the slot at 0xb0 escapes at 0x167c28
 *   stack: address of the slot at 0xb0 escapes at 0x167c38
 *   stack: address of the slot at 0xb0 escapes at 0x167c38
 *   stack: address of the slot at 0xc0 escapes at 0x167c48
 *   stack: address of the slot at 0xc0 escapes at 0x167c48
 *   stack: address of the slot at 0xd0 escapes at 0x167c58
 *   stack: address of the slot at 0xd0 escapes at 0x167c58
 *   stack: address of the slot at 0xb0 escapes at 0x167c64
 *   stack: address of the slot at 0xb0 escapes at 0x167c64
 *   stack: address of the slot at 0xb0 escapes at 0x167c74
 *   stack: address of the slot at 0xf0 escapes at 0x167c74
 *   stack: address of the slot at 0xb0 escapes at 0x167c74
 *   stack: address of the slot at 0xb0 escapes at 0x167c84
 *   cfg: kept goto: 0x167420 -> .L00167DA0
 *   cfg: kept branch: 0x167520 if (..) goto .L001675F8
 *   cfg: kept goto: 0x167590 -> .L001675F8
 *   cfg: loop body is not one contiguous region: .L00167A10
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */

extern unsigned int CheckPointLightValid(void *, void *, signed int);
extern u32 GetPointLightMng();
extern void sceVu0UnitMatrix(void *);
extern void sceVu0RotMatrixX(void *, void *, float);
extern void sceVu0RotMatrixZ(void *, void *, float);
extern void sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0ScaleVector(void *, void *, float);
extern void PlayNoAnim(void *);
extern void sceVu0MulMatrix(void *, void *, void *);
static void UpdateShadowMatrix(void *, void *, void *);
extern void sceVu0TransMatrix(void *, void *, void *);
extern void fsvu0_ScaleVector(float *, float *, float);
extern void sceVu0InversMatrix(void *, void *);
extern void fsvu0_MulMatrix(void *, void *, void *);
extern signed int CsMngRtaSetMat(unsigned int, void *, int);
static unsigned int * DrawShadowModel(unsigned int *, void *);
extern float sqrtf(float);
static unsigned int * MakeBilinerTexture(unsigned int *a0 /* r4 */);


struct dw_696263_fields;
struct dw_719633_fields;
#ifndef PROTO_DW_707393_FIELDS
#define PROTO_DW_707393_FIELDS
struct dw_707393_fields { unsigned int EN1 : 1; unsigned int EN2 : 1; unsigned int CRTMD : 3; unsigned int MMOD : 1; unsigned int AMOD : 1; unsigned int SLBG : 1; unsigned int ALP : 8; unsigned int p0 : 16; unsigned int p1; };
#endif
#ifndef PROTO_DW_713003_FIELDS
#define PROTO_DW_713003_FIELDS
struct dw_713003_fields { unsigned int INT : 1; unsigned int FFMD : 1; unsigned int DPMS : 2; unsigned int p0 : 28; unsigned int p1; };
#endif
#ifndef PROTO_DW_707903_FIELDS
#define PROTO_DW_707903_FIELDS
struct dw_707903_fields { unsigned int FBP : 9; unsigned int FBW : 6; unsigned int PSM : 5; unsigned int p0 : 12; unsigned int DBX : 11; unsigned int DBY : 11; unsigned int p1 : 10; };
#endif
#ifndef PROTO_DW_714404_FIELDS
#define PROTO_DW_714404_FIELDS
struct dw_714404_fields { unsigned int DX : 12; unsigned int DY : 11; unsigned int MAGH : 4; unsigned int MAGV : 2; unsigned int p0 : 3; unsigned int DW : 12; unsigned int DH : 11; unsigned int p1 : 9; };
#endif
#ifndef PROTO_DW_713689_FIELDS
#define PROTO_DW_713689_FIELDS
struct dw_713689_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int p0 : 8; unsigned int p1; };
#endif
#ifndef PROTO_DW_699195_FIELDS
#define PROTO_DW_699195_FIELDS
struct dw_699195_fields { struct dw_707393_fields pmode; struct dw_713003_fields smode2; struct dw_707903_fields dispfb; struct dw_714404_fields display; struct dw_713689_fields bgcolor; };
#endif
#ifndef PROTO_DW_704389_FIELDS
#define PROTO_DW_704389_FIELDS
struct dw_704389_fields { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; };
#endif
#ifndef PROTO_DW_712669_FIELDS
#define PROTO_DW_712669_FIELDS
struct dw_712669_fields { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
#endif
#ifndef PROTO_DW_719144_FIELDS
#define PROTO_DW_719144_FIELDS
struct dw_719144_fields { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
#endif
#ifndef PROTO_DW_717358_FIELDS
#define PROTO_DW_717358_FIELDS
struct dw_717358_fields { unsigned long OFX : 16; unsigned long pad16 : 16; unsigned long OFY : 16; unsigned long pad48 : 16; };
#endif
#ifndef PROTO_DW_709972_FIELDS
#define PROTO_DW_709972_FIELDS
struct dw_709972_fields { unsigned long SCAX0 : 11; unsigned long pad11 : 5; unsigned long SCAX1 : 11; unsigned long pad27 : 5; unsigned long SCAY0 : 11; unsigned long pad43 : 5; unsigned long SCAY1 : 11; unsigned long pad59 : 5; };
#endif
#ifndef PROTO_DW_702116_FIELDS
#define PROTO_DW_702116_FIELDS
struct dw_702116_fields { unsigned long AC : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_718309_FIELDS
#define PROTO_DW_718309_FIELDS
struct dw_718309_fields { unsigned long CLAMP : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_707274_FIELDS
#define PROTO_DW_707274_FIELDS
struct dw_707274_fields { unsigned long DTHE : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_713985_FIELDS
#define PROTO_DW_713985_FIELDS
struct dw_713985_fields { unsigned long ATE : 1; unsigned long ATST : 3; unsigned long AREF : 8; unsigned long AFAIL : 2; unsigned long DATE : 1; unsigned long DATM : 1; unsigned long ZTE : 1; unsigned long ZTST : 2; unsigned long pad19 : 45; };
#endif
#ifndef PROTO_DW_703735_FIELDS
#define PROTO_DW_703735_FIELDS
struct dw_703735_fields { struct dw_712669_fields frame1; unsigned long frame1addr; struct dw_719144_fields zbuf1; long zbuf1addr; struct dw_717358_fields xyoffset1; long xyoffset1addr; struct dw_709972_fields scissor1; long scissor1addr; struct dw_702116_fields prmodecont; long prmodecontaddr; struct dw_718309_fields colclamp; long colclampaddr; struct dw_707274_fields dthe; long dtheaddr; struct dw_713985_fields test1; long test1addr; };
#endif
#ifndef PROTO_DW_721307_FIELDS
#define PROTO_DW_721307_FIELDS
struct dw_721307_fields { unsigned long PRIM : 3; unsigned long IIP : 1; unsigned long TME : 1; unsigned long FGE : 1; unsigned long ABE : 1; unsigned long AA1 : 1; unsigned long FST : 1; unsigned long CTXT : 1; unsigned long FIX : 1; unsigned long pad11 : 53; };
#endif
#ifndef PROTO_DW_706942_FIELDS
#define PROTO_DW_706942_FIELDS
struct dw_706942_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int A : 8; float Q; };
#endif
#ifndef PROTO_DW_717883_FIELDS
#define PROTO_DW_717883_FIELDS
struct dw_717883_fields { unsigned long X : 16; unsigned long Y : 16; unsigned long Z : 32; };
#endif
#ifndef PROTO_DW_715246_FIELDS
#define PROTO_DW_715246_FIELDS
struct dw_715246_fields { struct dw_713985_fields testa; long testaaddr; struct dw_721307_fields prim; long primaddr; struct dw_706942_fields rgbaq; long rgbaqaddr; struct dw_717883_fields xyz2a; long xyz2aaddr; struct dw_717883_fields xyz2b; long xyz2baddr; struct dw_713985_fields testb; long testbaddr; };
#endif
#ifndef PROTO_DW_718597_FIELDS
#define PROTO_DW_718597_FIELDS
struct dw_718597_fields { struct dw_699195_fields disp[2]; struct dw_704389_fields giftag0; struct dw_703735_fields draw0; struct dw_715246_fields clear0; struct dw_704389_fields giftag1; struct dw_703735_fields draw1; struct dw_715246_fields clear1; };
#endif
#ifndef PROTO_DW_694961_FIELDS
#define PROTO_DW_694961_FIELDS
struct dw_694961_fields { struct dw_718597_fields dbBuf; float camPos[4]; float camAng[4]; float camPosB[4]; float camAngB[4]; float vsMat[4][4]; float wsMat[4][4]; float wvMat[4][4]; float lcMat[4][4]; float wcMat[4][4]; float csMat[4][4]; float scrDepth; unsigned int *sprBuf[2]; int sprBufID; unsigned int DMATag; int ctxt; int dbBufID; int oddeven; unsigned int calcTime; unsigned int drawTime; unsigned int frameTime; float fov; int TotalPolyNum; int TotalPrimNum; float WaterLevel; unsigned char DrawFlag; unsigned char DrawHitModel; unsigned char BlurMode; unsigned char BlurRate; unsigned char ProjectionType; unsigned char unused[15]; float PlaneParam[4]; float FogParam[4]; float FogParam16[4]; };
#endif
#ifndef PROTO_DW_717598_FIELDS
#define PROTO_DW_717598_FIELDS
struct dw_717598_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_713558_FIELDS
#define PROTO_DW_713558_FIELDS
struct dw_713558_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_713235_FIELDS
#define PROTO_DW_713235_FIELDS
struct dw_713235_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_696263_fields *lpMdl; };
#endif
#ifndef PROTO_DW_696263_FIELDS
#define PROTO_DW_696263_FIELDS
struct dw_696263_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_719633_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_696263_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_717598_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_713558_fields flags; unsigned char _pad1[3]; struct dw_713235_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_715792_FIELDS
#define PROTO_DW_715792_FIELDS
struct dw_715792_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif
#ifndef PROTO_DW_721069_FIELDS
#define PROTO_DW_721069_FIELDS
struct dw_721069_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_719633_FIELDS
#define PROTO_DW_719633_FIELDS
struct dw_719633_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_721069_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_694961_FIELDS_DBBUFID_7F42E97A_DEFINED
#define DCOMP_OFF_STRUCT_DW_694961_FIELDS_DBBUFID_7F42E97A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_694961_FIELDS_DBBUFID_7F42E97A = (int)&(((struct dw_694961_fields *)0)->dbBufID) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_696263_FIELDS_SHADOWSIZE_E4D2E7C0_DEFINED
#define DCOMP_OFF_STRUCT_DW_696263_FIELDS_SHADOWSIZE_E4D2E7C0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_696263_FIELDS_SHADOWSIZE_E4D2E7C0 = (int)&(((struct dw_696263_fields *)0)->ShadowSize) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_696263_FIELDS_BUSEMDLLIGHT_3C2497AB_DEFINED
#define DCOMP_OFF_STRUCT_DW_696263_FIELDS_BUSEMDLLIGHT_3C2497AB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_696263_FIELDS_BUSEMDLLIGHT_3C2497AB = (int)&(((struct dw_696263_fields *)0)->bUseMdlLight) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_696263_FIELDS_LPMDLDATA_6751190D_DEFINED
#define DCOMP_OFF_STRUCT_DW_696263_FIELDS_LPMDLDATA_6751190D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_696263_FIELDS_LPMDLDATA_6751190D = (int)&(((struct dw_696263_fields *)0)->lpMdlData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_715792_FIELDS_GAMEMODE_D7DEC1A0_DEFINED
#define DCOMP_OFF_STRUCT_DW_715792_FIELDS_GAMEMODE_D7DEC1A0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_715792_FIELDS_GAMEMODE_D7DEC1A0 = (int)&(((struct dw_715792_fields *)0)->GameMode) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_719633_FIELDS_LPVMDHEAD_E3CCA084_DEFINED
#define DCOMP_OFF_STRUCT_DW_719633_FIELDS_LPVMDHEAD_E3CCA084_DEFINED
enum { DCOMP_OFF_STRUCT_DW_719633_FIELDS_LPVMDHEAD_E3CCA084 = (int)&(((struct dw_719633_fields *)0)->lpVmdHead) - 0 };
#endif
#ifndef DCOMP_EXPR_F4392B91E5A8C94E
#define DCOMP_EXPR_F4392B91E5A8C94E(dcomp_arg) ((3.1415927f + (dcomp_arg)) >= 0.0f ? ((dcomp_arg) - (6.2831855f * (float)(s32)((3.1415927f + (dcomp_arg)) / 6.2831855f))) : (6.2831855f + ((dcomp_arg) - (6.2831855f * (float)(s32)((3.1415927f + (dcomp_arg)) / 6.2831855f)))))
#endif
struct MsMdl { u8 pad0[0x20]; float Pos[4]; float Ang[4]; float Scl[4]; u8 pad1[0x40]; float LightDir[4]; u8 pad2[0x60]; void *lpAnimCtrl; };

static unsigned int * MakeShadowTexture(unsigned int *lpCurDMA, void *lpMdlMng) {
    float lw_mat[4][4] __attribute__((aligned(16)));
    float AngX;
    float AngY;
    float ShadowScale;
    unsigned int ShadowRate;
    u8 *lpVmdHead;
    u8 **lpPointLightMng;
    float Rate;
    float cs_mat[4][4] __attribute__((aligned(16)));
    u8 *env;
    u8 *s0 = (u8 *)lpMdlMng;
    u8 *s7;
    u32 v0;

    s7 = (*(s32 *)(lpDrawMng + DCOMP_OFF_STRUCT_DW_694961_FIELDS_DBBUFID_7F42E97A) == 0) ? (u8 *)(lpDrawMng + 0x60) : (u8 *)(lpDrawMng + 0x150);
    ShadowScale = 0.00128f / *(float *)(s0 + DCOMP_OFF_STRUCT_DW_696263_FIELDS_SHADOWSIZE_E4D2E7C0);
    lpVmdHead = (u8 *)*(s32 *)(*(s32 *)(s0 + DCOMP_OFF_STRUCT_DW_696263_FIELDS_LPMDLDATA_6751190D) + DCOMP_OFF_STRUCT_DW_719633_FIELDS_LPVMDHEAD_E3CCA084);
    if (GameSt[DCOMP_OFF_STRUCT_DW_715792_FIELDS_GAMEMODE_D7DEC1A0] != 4) {
        if (*(u8 *)(s0 + DCOMP_OFF_STRUCT_DW_696263_FIELDS_BUSEMDLLIGHT_3C2497AB) == 0) {
            if (CheckPointLightValid(s0, (void *)0, 1) == 0) {
                return lpCurDMA;
            }
            lpPointLightMng = (u8 **)GetPointLightMng();
            gShadowDir[0] = *(float *)(s0 + 0x20) - *(float *)(*lpPointLightMng + 0x10);
            gShadowDir[1] = (*(float *)(s0 + 0x24) - 0.25f * *(float *)(s0 + 0x114)) - *(float *)(*lpPointLightMng + 0x14);
            gShadowDir[2] = *(float *)(s0 + 0x28) - *(float *)(*lpPointLightMng + 0x18);
            if (gShadowDir[1] < 0.01f) {
                gShadowDir[1] = 0.01f;
            }
            Rate = sqrtf((gShadowDir[0] * gShadowDir[0] + gShadowDir[1] * gShadowDir[1] + gShadowDir[2] * gShadowDir[2]) / (*(float *)(*lpPointLightMng + 4) * *(float *)(*lpPointLightMng + 4))) / 1.5f;
            if (Rate > 1.0f) {
                Rate = 1.0f;
            }
            ShadowRate = (u32)(32.0f * (1.0f - Rate));
            if (ShadowRate == 0) {
                return lpCurDMA;
            }
        } else {
            ShadowRate = 0x10;
            gShadowDir[0] = -*(float *)(s0 + 0x90);
            gShadowDir[1] = -*(float *)(s0 + 0x94);
            gShadowDir[2] = -*(float *)(s0 + 0x98);
        }
    } else {
        *(u32 *)gShadowDir = -0x3f166666;
        *(u32 *)(gShadowDir + 1) = 0x41200000;
        *(u32 *)(gShadowDir + 2) = 0x4139999a;
        ShadowRate = 0x10;
    }
    lpCurDMA[0] = 0x10000007;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x50000007;
    lpCurDMA[4] = 0x8006;
    lpCurDMA[5] = 0x10000000;
    lpCurDMA[6] = 0xe;
    lpCurDMA[7] = 0;
    *(u64 *)(lpCurDMA + 8) = 0xa040150;
    *(u64 *)(lpCurDMA + 10) = 0x4c;
    *(u64 *)(lpCurDMA + 12) = (u64)1 << 32;
    *(u64 *)(lpCurDMA + 14) = 0x4e;
    *(u64 *)(lpCurDMA + 16) = ((u64)0x7800 << 32) | 0x7800;
    *(u64 *)(lpCurDMA + 18) = 0x18;
    *(u64 *)(lpCurDMA + 20) = ((u64)0xff0000 << 32) | 0xff0000;
    *(u64 *)(lpCurDMA + 22) = 0x40;
    *(u64 *)(lpCurDMA + 24) = 0;
    *(u64 *)(lpCurDMA + 26) = 0x47;
    *(u64 *)(lpCurDMA + 28) = 0x44;
    *(u64 *)(lpCurDMA + 30) = 0x42;
    lpCurDMA = (unsigned int *)ClearShadowTexture((u8 *)(lpCurDMA + 32));
    AngX = atan2f(gShadowDir[1], sqrtf(gShadowDir[0] * gShadowDir[0] + gShadowDir[2] * gShadowDir[2]));
    AngY = atan2f(-gShadowDir[0], gShadowDir[2]);
    sceVu0UnitMatrix(lw_mat);
    sceVu0RotMatrixX(lw_mat, lw_mat, MS_WRAP(*(float *)(s0 + 0x30)));
    sceVu0RotMatrixZ(lw_mat, lw_mat, MS_WRAP(*(float *)(s0 + 0x38)));
    sceVu0RotMatrixY(lw_mat, lw_mat, MS_WRAP(*(float *)(s0 + 0x34)));
    lw_mat[3][1] = *(float *)(s0 + 0x11c) * ShadowScale;
    sceVu0RotMatrixY(lw_mat, lw_mat, MS_WRAP(AngY));
    sceVu0RotMatrixX(lw_mat, lw_mat, MS_WRAP(AngX));
    sceVu0ScaleVector(lw_mat[0], lw_mat[0], *(float *)(s0 + 0x40) * ShadowScale);
    sceVu0ScaleVector(lw_mat[1], lw_mat[1], *(float *)(s0 + 0x44) * ShadowScale);
    sceVu0ScaleVector(lw_mat[2], lw_mat[2], *(float *)(s0 + 0x48) * ShadowScale);
    ((u32 *)lw_mat)[14] = 0x3c23d70a;
    if (*(s32 *)(s0 + 0x1c) == 0) {
        s32 s5;
        u8 *s4;
        u32 s3;
        s32 s2;
        PlayNoAnim(s0);
        s4 = (u8 *)*(s32 *)(*(s32 *)(s0 + 0xc) + 0x10);
        s3 = *(s32 *)(s4 + 0x1c);
        s5 = 0;
        if ((u8 *)0 < (u8 *)*(s16 *)(s4 + 0x10)) {
            s2 = 0;
            do {
                if (*(s16 *)(s3 + 0x34) >= 0) {
                    sceVu0MulMatrix((void *)(*(s32 *)(s0 + 0x14) + s2), (void *)(*(s32 *)(s0 + 0x14) + (*(s16 *)(s3 + 0x34) << 6)), (void *)(*(s32 *)(s0 + 0x18) + s2));
                } else {
                    sceVu0MulMatrix((void *)(*(s32 *)(s0 + 0x14) + s2), lw_mat, (void *)(*(s32 *)(s0 + 0x18) + s2));
                }
                s5++;
                s2 += 0x40;
                s3 += 0x60;
            } while ((u32)s5 < (u32)*(s16 *)(s4 + 0x10));
        }
    } else {
        UpdateShadowMatrix(s0, (void *)*(s32 *)(s0 + 0x100), lw_mat);
    }
    if (*(u8 *)(*(s32 *)(lpVmdHead + 0x38) + 0xc) != 0) {
        sceVu0UnitMatrix(cs_mat);
        sceVu0RotMatrixX(cs_mat, cs_mat, MS_WRAP(*(float *)(s0 + 0x30)));
        sceVu0RotMatrixZ(cs_mat, cs_mat, MS_WRAP(*(float *)(s0 + 0x38)));
        sceVu0RotMatrixY(cs_mat, cs_mat, MS_WRAP(*(float *)(s0 + 0x34)));
        sceVu0TransMatrix(cs_mat, cs_mat, (void *)(s0 + 0x20));
        fsvu0_ScaleVector(cs_mat[0], cs_mat[0], *(float *)(s0 + 0x40));
        fsvu0_ScaleVector(cs_mat[1], cs_mat[1], *(float *)(s0 + 0x44));
        fsvu0_ScaleVector(cs_mat[2], cs_mat[2], *(float *)(s0 + 0x48));
        sceVu0InversMatrix(cs_mat, cs_mat);
        fsvu0_MulMatrix(cs_mat, lw_mat, cs_mat);
        CsMngRtaSetMat((unsigned int)s0, cs_mat, 0);
    }
    lpCurDMA = DrawShadowModel(lpCurDMA, s0);
    lpCurDMA = MakeBilinerTexture(lpCurDMA);
    lpCurDMA[0] = 0x1000000b;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x5000000b;
    lpCurDMA[4] = 0x800a;
    lpCurDMA[5] = 0x10000000;
    lpCurDMA[6] = 0xe;
    lpCurDMA[7] = 0;
    *(u64 *)(lpCurDMA + 8) = 0;
    *(u64 *)(lpCurDMA + 10) = 0x3f;
    *(u64 *)(lpCurDMA + 12) = *(u64 *)s7;
    *(u64 *)(lpCurDMA + 14) = 0x4c;
    lpCurDMA[16] = *(s32 *)(s7 + 0x10);
    lpCurDMA[17] = 1;
    *(u64 *)(lpCurDMA + 18) = 0x4e;
    *(u64 *)(lpCurDMA + 20) = *(u64 *)(s7 + 0x20);
    *(u64 *)(lpCurDMA + 22) = 0x18;
    *(u64 *)(lpCurDMA + 24) = *(u64 *)(s7 + 0x30);
    *(u64 *)(lpCurDMA + 26) = 0x40;
    *(u64 *)(lpCurDMA + 28) = 0x50000;
    *(u64 *)(lpCurDMA + 30) = 0x47;
    *(u64 *)(lpCurDMA + 32) = ((u64)ShadowRate << 32) | 0x62;
    *(u64 *)(lpCurDMA + 34) = 0x42;
    *(u64 *)(lpCurDMA + 36) = 5;
    *(u64 *)(lpCurDMA + 38) = 8;
    *(u64 *)(lpCurDMA + 40) = 0x60;
    *(u64 *)(lpCurDMA + 42) = 0x14;
    *(u64 *)(lpCurDMA + 44) = ((u64)0x98a0 << 16) | 0x6c00 | ((u64)5 << 32);
    *(u64 *)(lpCurDMA + 46) = 6;
    return lpCurDMA + 48;
}



/* UpdateShadowMatrix @ 0x167080 .. 0x167368 (0x2e8 bytes, frame 0x80) */





#ifndef PROTO_DW_717598_FIELDS
#define PROTO_DW_717598_FIELDS

#endif
#ifndef PROTO_DW_713558_FIELDS
#define PROTO_DW_713558_FIELDS

#endif
#ifndef PROTO_DW_713235_FIELDS
#define PROTO_DW_713235_FIELDS

#endif
#ifndef PROTO_DW_696263_FIELDS
#define PROTO_DW_696263_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_696263_FIELDS_LPSHADOWMAT_C429EC4B_DEFINED
#define DCOMP_OFF_STRUCT_DW_696263_FIELDS_LPSHADOWMAT_C429EC4B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_696263_FIELDS_LPSHADOWMAT_C429EC4B = (int)&(((struct dw_696263_fields *)0)->lpShadowMat) - 0 };
#endif
#pragma inline_depth(8)
typedef struct USMNode {
    u8 pad0[0x18];
    s32 idx;
    u8 pad1[8];
    u32 flags;
    u8 pad2[0x80 - 0x28];
    float mat[4][4];
    u8 pad3[4];
    struct USMNode *child;
    struct USMNode *sibling;
} USMNode;
typedef struct dw_696263_fields USMMng;

static inline void USM_Leaf(USMMng *mng, void *a1, void *a2) {
    USMNode *n;
    u8 *mat;

    n = (USMNode *)a1;
    if ((n->flags & 8) == 0) {
        sceVu0MulMatrix((void *)mng->lpShadowMat[n->idx], a2, n->mat);
    }
    if (n->child != 0) {
        mat = (u8 *)mng->lpShadowMat[n->idx];
        UpdateShadowMatrix(mng, n->child, mat);
    }
    if (n->sibling != 0) {
        UpdateShadowMatrix(mng, n->sibling, a2);
    }
}

static inline void USM_Mid(USMMng *mng, void *a1, void *a2) {
    USMNode *n;
    u8 *mat;

    n = (USMNode *)a1;
    if ((n->flags & 8) == 0) {
        sceVu0MulMatrix((void *)mng->lpShadowMat[n->idx], a2, n->mat);
    }
    if (n->child != 0) {
        mat = (u8 *)mng->lpShadowMat[n->idx];
        USM_Leaf(mng, n->child, mat);
    }
    if (n->sibling != 0) {
        USM_Leaf(mng, n->sibling, a2);
    }
}
static void UpdateShadowMatrix(void *a0, void *a1, void *a2) {
    USMMng *mng = (USMMng *)a0;
    float (*pm)[4] = (float (*)[4])a2;
    USMNode *n = (USMNode *)a1;
    u8 *mat;
    if ((n->flags & 8) == 0) {
        sceVu0MulMatrix((void *)mng->lpShadowMat[n->idx], pm, n->mat);
    }
    if (n->child != 0) {
        mat = (u8 *)mng->lpShadowMat[n->idx];
        USM_Mid(mng, n->child, mat);
    }
    if (n->sibling != 0) {
        USM_Mid(mng, n->sibling, pm);
    }
}



static unsigned int * DrawShadowObject(unsigned int *, void *, void *);
extern void sceVu0CopyMatrix(void *, void *);
extern unsigned int * SetAmbientLightPacket(unsigned int *, float, void *);

struct ShSmdObj { u8 pad[0x32]; short Id; u8 pad2[0x2c]; };
struct ShSmdHead { u8 pad0[0xe]; short NumMat; short NumObj; u8 pad1[0xa]; struct ShSmdObj *lpObj; float Scale; };

static unsigned int * DrawShadowModel(unsigned int *lpCurDMA, void *lpMdlMng_) {
    struct dw_696263_fields *lpMdlMng = (struct dw_696263_fields *)lpMdlMng_;
    unsigned int j;
    struct ShSmdHead *lpSmdHead;
    struct ShSmdObj *lpSmdObj;
    unsigned int *lpMatDMA;
    unsigned int *p;
    unsigned int i;

    lpSmdHead = (struct ShSmdHead *)((struct dw_719633_fields *)lpMdlMng->lpMdlData)->lpSmdHead;
    {
        float GeomScale[4] = {0};
        lpCurDMA[0] = 0x10000004;
        lpCurDMA[1] = 0;
        lpCurDMA[2] = 0;
        lpCurDMA[3] = 0x6c040008;
        lpCurDMA += 4;
        sceVu0CopyMatrix(((ShMat *)lpCurDMA)++, gShadowLCMat);
        lpCurDMA[0] = 0x10000004;
        lpCurDMA[1] = 0;
        lpCurDMA[2] = 0;
        lpCurDMA[3] = 0x6c040004;
        lpCurDMA += 4;
        sceVu0CopyMatrix(((ShMat *)lpCurDMA)++, gShadowVSMat);
        lpCurDMA = SetAmbientLightPacket(lpCurDMA, lpMdlMng->Alpha, 0);
        lpCurDMA[0] = 0x10000001;
        lpCurDMA[1] = 0;
        lpCurDMA[2] = 0;
        lpCurDMA[3] = 0x6c01001d;
        GeomScale[0] = 1.0f / lpSmdHead->Scale;
        p = lpCurDMA + 8;
        ((u32 *)GeomScale)[1] = 0x3c010204;
        ((u32 *)GeomScale)[3] = 0x437f0000;
        *(u_long128 *)(lpCurDMA + 4) = *(u_long128 *)GeomScale;
        lpMatDMA = lpCurDMA + 12;
        {
            unsigned int t = (u32)p + (lpSmdHead->NumMat << 6) + 0x10;
            lpCurDMA[8] = 0x20000000;
            lpCurDMA[9] = t;
        }
        lpCurDMA[10] = 0;
        lpCurDMA[11] = 0;
        lpMatDMA = lpCurDMA + 12;
        p += 4;
        for (i = 0; i < lpSmdHead->NumObj; i++) {
            sceVu0CopyMatrix(((ShMat *)p)++, lpMdlMng->lpShadowMat[i]);
        }
        {
            u32 h2 = (u32)lpSmdHead;
            lpSmdObj = *(struct ShSmdObj **)(h2 + 0x1c);
            for (j = 0; j < *(short *)(h2 + 0x10); j++) {
                if (lpSmdObj->Id != -1) {
                    p = DrawShadowObject(p, lpSmdObj, lpMatDMA);
                }
                lpSmdObj++;
            }
        }
        return p;
    }
}


/* DrawShadowObject @ 0x166D20 .. 0x166E70 (0x150 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */

extern u16 GetMicroCodeMPG(u32 *);
extern u32 Vu1ProgMCShadowMake[];

static unsigned int * DrawShadowObject(unsigned int *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6
        */) {
    u32 s1;
    s32 t1;
    s32 t0;
    s32 a3;
    u8 *s0;
    u8 *a1_bytes; // a1
    s32 v1;
    unsigned int *a0_2;
    void *a1_2;
    u32 v0;

    a1_bytes = (u8 *)a1;
    v0 = 0x10000000;
    a3 = 0x10000000 | 1;
    v0 = 0x6c010000;
    *(u32 *)a0 = a3;
    s1 = (u32)a0;
    a0[1] = 0;
    v0 = 0x6c010000 | 0x1c;
    a0[2] = 0;
    s0 = a1_bytes;
    a0[3] = 0x6c010000 | 0x1e;
    s1 += 0x40;
    a0[4] = 0;
    a0[5] = 0;
    a0[6] = 0;
    a0[7] = 0;
    a0[8] = a3;
    a0[9] = 0;
    a0[0xa] = 0;
    a0[0xb] = v0;
    v0 = *(s16 *)(a1_bytes + 0x3a);
    a0[0xc] = v0;
    a0[0xd] = 0;
    a0[0xe] = 0;
    a0[0xf] = 0;
    v0 = *(s16 *)(a1_bytes + 0x3a);
    t1 = 0;
    if ((u8 *)0 < (u8 *)v0) {
        s32 joint;
        t0 = 0;
        a3 = 0x20;
        do {
            joint = *(u16 *)(*(u32 *)(s0 + 0x3c) + t0);
            t0 = t0 + 2;
            joint <<= 6;
            *(u32 *)s1 = 0x30000004;
            *(u32 *)(s1 + 4) = (u32)a2 + joint;
            *(u32 *)(s1 + 8) = 0;
            *(u32 *)(s1 + 0xc) = a3 | 0x6c040000;
            a3 = a3 + 4;
            t1 = t1 + 1;
            s1 += 0x10;
        } while ((u32)t1 < (u32)*(s16 *)(s0 + 0x3a));
    }
    v0 = 0x10000000;
    *(u32 *)s1 = 0x10000000;
    *(u32 *)(s1 + 4) = 0;
    a0_2 = (unsigned int *)Vu1ProgMCShadowMake;
    *(u32 *)(s1 + 8) = 0;
    v0 = GetMicroCodeMPG((unsigned int *)Vu1ProgMCShadowMake);
    a1_2 = (void *)0x15000000;
    *(u32 *)(s1 + 0xc) = (u32)(u16)v0 | 0x15000000;
    v0 = 0x50000000;
    *(u32 *)(s1 + 0x10) = 0x50000000;
    v1 = 0x10000000;
    a0_2 = (unsigned int *)*(s32 *)(s0 + 0x54);
    v0 = (s32)(s1 + 0x30);
    *(u32 *)(s1 + 0x14) = (s32)a0_2;
    *(u32 *)(s1 + 0x18) = 0;
    *(u32 *)(s1 + 0x1c) = 0;
    *(u32 *)(s1 + 0x20) = 0x10000000;
    *(u32 *)(s1 + 0x24) = 0;
    *(u32 *)(s1 + 0x28) = 0;
    *(u32 *)(s1 + 0x2c) = 0x15000000;
    return (unsigned int *)v0;
}


/* ClearShadowTexture @ 0x166C50 .. 0x166D20 (0xd0 bytes) */




static u32 ClearShadowTexture(u8 *a0 /* r4 */) {
    u64 v1;
    u32 v0;
    u32 a1;
    u64 t1;

    v1 = 0x10000000 | 8;
    v0 = 0x51000008;
    *(u32 *)a0 = v1;
    a1 = 2;
    *(u32 *)(((u8 *)a0 + 4)) = 0;
    *(u32 *)(((u8 *)a0 + 8)) = 0;
    v1 = 0x47;
    *(u32 *)(((u8 *)a0 + 0xc)) = 0x51000008;
    *(u32 *)(((u8 *)a0 + 0x10)) = 2;
    v0 = 0x3f800000;
    *(u32 *)(((u8 *)a0 + 0x14)) = 0x10000000;
    t1 = (u64)0x3f800000 << 0 + 0x20;
    *(u32 *)(((u8 *)a0 + 0x18)) = 0xe;
    *(u32 *)(((u8 *)a0 + 0x1c)) = 0;
    v0 = 0x10034000;
    *(u64 *)(((u8 *)a0 + 0x20)) = 0;
    *(u64 *)(((u8 *)a0 + 0x28)) = 0x47;
    *(u64 *)(((u8 *)a0 + 0x30)) = t1;
    v1 = 5;
    *(u64 *)(((u8 *)a0 + 0x38)) = 1;
    *(u32 *)(((u8 *)a0 + 0x40)) = 2;
    *(u32 *)(((u8 *)a0 + 0x44)) = 0x10034000;
    a1 = 0x8001;
    *(u32 *)(((u8 *)a0 + 0x48)) = 5;
    v0 = 0xffff;
    *(u32 *)(((u8 *)a0 + 0x4c)) = 0;
    v0 = (u64)0xffff << 0x10;
    *(u32 *)(((u8 *)a0 + 0x50)) = 0x7800;
    v0 = v0 | 0xffff;
    *(u32 *)(((u8 *)a0 + 0x54)) = 0x7800;
    v1 = v0 | t1;
    *(u32 *)(((u8 *)a0 + 0x58)) = 0;
    v0 = (u32)((u8 *)a0 + 0x90);
    *(u32 *)(((u8 *)a0 + 0x5c)) = 0;
    *(u32 *)(((u8 *)a0 + 0x60)) = 0x8800;
    *(u32 *)(((u8 *)a0 + 0x64)) = 0x8800;
    *(u32 *)(((u8 *)a0 + 0x68)) = 0;
    *(u32 *)(((u8 *)a0 + 0x6c)) = 0;
    *(u32 *)(((u8 *)a0 + 0x70)) = 0x8001;
    *(u32 *)(((u8 *)a0 + 0x74)) = 0x10000000;
    *(u32 *)(((u8 *)a0 + 0x78)) = 0xe;
    *(u32 *)(((u8 *)a0 + 0x7c)) = 0;
    *(u64 *)(((u8 *)a0 + 0x80)) = v1;
    *(u64 *)(((u8 *)a0 + 0x88)) = 1;
    return v0;
}



/* MakeBilinerTexture @ 0x166A90 .. 0x166C48 (0x1b8 bytes) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   delay: addiu at 0x166b44 writes a register its branch at 0x166b40 reads
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */

static u32 Flag_1034;

static unsigned int * MakeBilinerTexture(unsigned int *a0 /* r4 */) {
    u32 a2;
    s32 a1;
    u32 v1;
    u64 v1_64;
    u64 v0_64;
    u32 v0;

    v0 = 0x51000000;
    *(u32 *)a0 = 0x10000000 | 0xa;
    a0[1] = 0;
    a0[2] = 0;
    a0[3] = 0x51000000 | 0xa;
    a0[4] = 9;
    v0 = -0x1000000;
    a0[5] = 0x10000000;
    a0[6] = 0xe;
    a0[7] = 0;
    v0 = 0xa010160;
    *(u64 *)(((u8 *)a0 + 0x20)) = 0;
    *(s64 *)(((u8 *)a0 + 0x28)) = (s32)0x3f;
    *(u64 *)(((u8 *)a0 + 0x30)) = (u64)((s32)((s32)0xa010160)) | (u64)((u64)(s32)-0x1000000 <<
        0x20);
    *(s64 *)(((u8 *)a0 + 0x38)) = (s32)0x4c;
    *(u64 *)(((u8 *)a0 + 0x40)) = (u64)(u32)1 << 0x20;
    v1 = 0x7e00;
    *(s64 *)(((u8 *)a0 + 0x48)) = (s32)0x4e;
    *(u64 *)(((u8 *)a0 + 0x50)) = (u64)((s32)((s32)v1)) | (u64)((u64)(s32)v1 << 0x20);
    v1 = 0x3f0000;
    *(s64 *)(((u8 *)a0 + 0x58)) = (s32)0x18;
    *(u64 *)(((u8 *)a0 + 0x60)) = (u64)((s32)((s32)0x3f0000)) | (u64)((u64)(u32)0x3f0000 << 0x20);
    *(s64 *)(((u8 *)a0 + 0x68)) = (s32)0x40;
    v0 = Flag_1034;
    if (v0 == 0) {
        *(s64 *)(((u8 *)a0 + 0x70)) = (s32)0x60;
        a0 = (unsigned int *)(u8 *)(a0 + 0x1e);
    } else {
        *(u64 *)(((u8 *)a0 + 0x70)) = 0;
        a0 = (unsigned int *)(u8 *)(a0 + 0x1e);
    }
    *(s64 *)a0 = (s32)0x14;
    a2 = 6;
    v1_64 = (u64)(s32)a2 << 0x20;
    v0 = 0x20a12a00;
    *(u64 *)(((u8 *)a0 + 8)) = (u64)((s32)((s32)0x20a12a00)) | (u64)(v1_64);
    v0 = 0x3f800000;
    *(s64 *)(((u8 *)a0 + 0x10)) = (s32)a2;
    v0 = 0x8080;
    *(u64 *)(((u8 *)a0 + 0x18)) = 0;
    v0_64 = (u64)0x8080 << 0x10;
    *(s64 *)(((u8 *)a0 + 0x20)) = (s32)0x47;
    a2 = 0x7e00;
    a1 = 0x1000;
    *(u64 *)(((u8 *)a0 + 0x28)) = (u64)((u64)(v0_64) | (u64)(0x8080)) | (u64)((u64)(u32)0x3f800000
        << 0x20);
    *(s64 *)(((u8 *)a0 + 0x30)) = (s32)1;
    v0 = 0x10000005;
    v1 = 0x8002;
    a0[0xe] = 0x10000005;
    a0[0xf] = 0;
    v0 = 0x51000005;
    a0[0x10] = 0;
    a0[0x11] = 0x51000005;
    a0[0x12] = 0x8002;
    v0 = 0x208b4000;
    v1 = 0x8200;
    a0[0x13] = 0x208b4000;
    a0[0x14] = 0x53;
    a0[0x15] = 0;
    a0[0x16] = 0;
    a0[0x17] = 0;
    a0[0x18] = 0;
    a0[0x19] = 0;
    a0[0x1a] = a2;
    a0[0x1b] = a2;
    a0[0x1c] = 0;
    a0[0x1d] = 0;
    a0[0x1e] = a1;
    a0[0x1f] = a1;
    a0[0x20] = 0;
    a0[0x21] = 0;
    a0[0x22] = 0x8200;
    a0[0x23] = 0x8200;
    a0[0x24] = 0;
    a0[0x25] = 0;
    return (unsigned int *)(u8 *)(a0 + 0x26);
}


/* DrawDropShadowModel @ 0x1667F0 .. 0x166A88 (0x298 bytes, frame 0xc0) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1059 -> 0x228f30
 *   stack: address of the slot at 0xb0 escapes at 0x16682c
 *   fpu: float literal 0x40000000 at 0x166880
 *   stack: address of the slot at 0x60 escapes at 0x1668d4
 *   stack: address of the slot at 0x60 escapes at 0x1668ec
 *   stack: address of the slot at 0x60 escapes at 0x16691c
 *   fpu: float literal 0x3f800000 at 0x16699c
 *   literal: @1059 initializes the 16-byte local at 0xa0
 *   cfg: loop body is not one contiguous region: .L00166A00
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */

extern void sceVu0CopyVector(void *, void *);
extern void sceVu0InversMatrix(void *, void *);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern void sceVu0ScaleVectorXYZ(void *, void *, float);
extern void sceVu0Normalize(void *, void *);
static int CheckInnerShadow(struct ShBox *lpBoundBox);
extern unsigned int * SetCameraPacket(unsigned int *);
static unsigned int * SetShadowTexMatrixPacket(unsigned int *lpCurDMA, struct ShMdl *lpMyMdlMng);
extern unsigned int * SetMatrixPacket(unsigned int *, void *, void *);
static u32 *DrawDropShadowObject(u32 *packet, void *model, void *matrices);
extern u32 L1059[];
static struct ShInner InnerShadow;

struct dw_696263_fields;
struct dw_719633_fields;
#ifndef PROTO_DW_717598_FIELDS
#define PROTO_DW_717598_FIELDS
struct dw_717598_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_713558_FIELDS
#define PROTO_DW_713558_FIELDS
struct dw_713558_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_713235_FIELDS
#define PROTO_DW_713235_FIELDS
struct dw_713235_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_696263_fields *lpMdl; };
#endif
#ifndef PROTO_DW_696263_FIELDS
#define PROTO_DW_696263_FIELDS
struct dw_696263_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_719633_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_696263_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_717598_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_713558_fields flags; unsigned char _pad1[3]; struct dw_713235_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_718429_FIELDS
#define PROTO_DW_718429_FIELDS
struct dw_718429_fields { float P[4]; float N[4]; float H; float R; unsigned char _pad0[8]; };
#endif
#ifndef PROTO_DW_718960_FIELDS
#define PROTO_DW_718960_FIELDS
struct dw_718960_fields { struct dw_718429_fields Cylinder; float WorldPos[4]; float GeomScale; unsigned char _pad0[12]; };
#endif
#ifndef PROTO_DW_721069_FIELDS
#define PROTO_DW_721069_FIELDS
struct dw_721069_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_719633_FIELDS
#define PROTO_DW_719633_FIELDS
struct dw_719633_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_721069_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_696263_FIELDS_HITFLAG_74511E9D_DEFINED
#define DCOMP_OFF_STRUCT_DW_696263_FIELDS_HITFLAG_74511E9D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_696263_FIELDS_HITFLAG_74511E9D = (int)&(((struct dw_696263_fields *)0)->HitFlag) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_696263_FIELDS_SHADOWHIGH_BEDC5768_DEFINED
#define DCOMP_OFF_STRUCT_DW_696263_FIELDS_SHADOWHIGH_BEDC5768_DEFINED
enum { DCOMP_OFF_STRUCT_DW_696263_FIELDS_SHADOWHIGH_BEDC5768 = (int)&(((struct dw_696263_fields *)0)->ShadowHigh) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_696263_FIELDS_SHADOWSIZE_E4D2E7C0_DEFINED
#define DCOMP_OFF_STRUCT_DW_696263_FIELDS_SHADOWSIZE_E4D2E7C0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_696263_FIELDS_SHADOWSIZE_E4D2E7C0 = (int)&(((struct dw_696263_fields *)0)->ShadowSize) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_696263_FIELDS_LPMDLDATA_6751190D_DEFINED
#define DCOMP_OFF_STRUCT_DW_696263_FIELDS_LPMDLDATA_6751190D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_696263_FIELDS_LPMDLDATA_6751190D = (int)&(((struct dw_696263_fields *)0)->lpMdlData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_696263_FIELDS_LPOBJMAT_F929BED9_DEFINED
#define DCOMP_OFF_STRUCT_DW_696263_FIELDS_LPOBJMAT_F929BED9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_696263_FIELDS_LPOBJMAT_F929BED9 = (int)&(((struct dw_696263_fields *)0)->lpObjMat) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_718960_FIELDS_CYLINDER_H_41BB2BFD_DEFINED
#define DCOMP_OFF_STRUCT_DW_718960_FIELDS_CYLINDER_H_41BB2BFD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_718960_FIELDS_CYLINDER_H_41BB2BFD = (int)&(((struct dw_718960_fields *)0)->Cylinder.H) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_718960_FIELDS_CYLINDER_R_FD4F89AA_DEFINED
#define DCOMP_OFF_STRUCT_DW_718960_FIELDS_CYLINDER_R_FD4F89AA_DEFINED
enum { DCOMP_OFF_STRUCT_DW_718960_FIELDS_CYLINDER_R_FD4F89AA = (int)&(((struct dw_718960_fields *)0)->Cylinder.R) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_718960_FIELDS_GEOMSCALE_041CAFF9_DEFINED
#define DCOMP_OFF_STRUCT_DW_718960_FIELDS_GEOMSCALE_041CAFF9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_718960_FIELDS_GEOMSCALE_041CAFF9 = (int)&(((struct dw_718960_fields *)0)->GeomScale) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_718960_FIELDS_WORLDPOS_1__D8C9A4B5_DEFINED
#define DCOMP_OFF_STRUCT_DW_718960_FIELDS_WORLDPOS_1__D8C9A4B5_DEFINED
enum { DCOMP_OFF_STRUCT_DW_718960_FIELDS_WORLDPOS_1__D8C9A4B5 = (int)&(((struct dw_718960_fields *)0)->WorldPos[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_718960_FIELDS_WORLDPOS_3__D4AEA275_DEFINED
#define DCOMP_OFF_STRUCT_DW_718960_FIELDS_WORLDPOS_3__D4AEA275_DEFINED
enum { DCOMP_OFF_STRUCT_DW_718960_FIELDS_WORLDPOS_3__D4AEA275 = (int)&(((struct dw_718960_fields *)0)->WorldPos[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_719633_FIELDS_LPVMDHEAD_E3CCA084_DEFINED
#define DCOMP_OFF_STRUCT_DW_719633_FIELDS_LPVMDHEAD_E3CCA084_DEFINED
enum { DCOMP_OFF_STRUCT_DW_719633_FIELDS_LPVMDHEAD_E3CCA084 = (int)&(((struct dw_719633_fields *)0)->lpVmdHead) - 0 };
#endif
struct DsMdlMng { u8 pad0[0xc]; struct DsMdlData *lpMdlData; float (*lpObjMat)[4][4]; };
struct DsMdlData { u8 pad[0x10]; struct DsVmdHead *lpVmdHead; };
struct DsVmdHead { u8 pad0[0x10]; short NumObj; u8 pad1[0xa]; u8 *lpObj; float GeomScale; u8 pad2[0xc]; void *lpBound; };
struct DsMyMdl { u8 pad0[0x20]; float Pos[4]; u8 pad1[0xe8]; float ShadowSize; float ShadowHigh; u8 ds_pad2[0x14]; s32 ds_hit; };

static unsigned int * DrawDropShadowModel(unsigned int *lpCurDMA, void *lpMdlMng, void *lpMyMdlMng) {
    struct DsMyMdl *my = (struct DsMyMdl *)lpMyMdlMng;
    unsigned int i;
    struct DsVmdHead *lpVmdHead;
    u8 *lpObj;
    unsigned int *lpMatDMA;

    lpVmdHead = ((struct DsMdlMng *)lpMdlMng)->lpMdlData->lpVmdHead;
    {
    float GeomScale[4] = {0};
    int col[4] = {0x80, 0x80, 0x80, 0x80};
    float InverseMat[4][4] __attribute__((aligned(16)));
    sceVu0CopyVector(InnerShadow.WorldPos, my->Pos);
    InnerShadow.WorldPos[1] -= my->ShadowHigh;
    InnerShadow.WorldPos[3] = 1.0f;
    InnerShadow.GeomScale = lpVmdHead->GeomScale;
    InnerShadow.Cylinder.R = my->ShadowSize * InnerShadow.GeomScale;
    InnerShadow.Cylinder.H = 2.0f * my->ShadowSize * InnerShadow.GeomScale;
    sceVu0InversMatrix(InverseMat, ((struct DsMdlMng *)lpMdlMng)->lpObjMat);
    sceVu0ApplyMatrix(InnerShadow.Cylinder.P, InverseMat, InnerShadow.WorldPos);
    sceVu0ScaleVectorXYZ(InnerShadow.Cylinder.P, InnerShadow.Cylinder.P, InnerShadow.GeomScale);
    sceVu0ApplyMatrix(InnerShadow.Cylinder.N, InverseMat, gShadowDir);
    sceVu0Normalize(InnerShadow.Cylinder.N, InnerShadow.Cylinder.N);
    if (CheckInnerShadow((struct ShBox *)lpVmdHead->lpBound) == 0) {
        return lpCurDMA;
    }
    lpCurDMA = SetCameraPacket(lpCurDMA);
    lpCurDMA = SetShadowTexMatrixPacket(lpCurDMA, (struct ShMdl *)my);
    lpCurDMA[0] = 0x10000001;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x6c010001;
    *(u_long128 *)(lpCurDMA + 4) = *(u_long128 *)col;
    lpCurDMA[8] = 0x10000001;
    lpCurDMA[9] = 0;
    lpCurDMA[10] = 0;
    lpCurDMA[11] = 0x6c01001d;
    GeomScale[0] = 1.0f / lpVmdHead->GeomScale;
    ((u32 *)GeomScale)[1] = 0x3c010204;
    ((u32 *)GeomScale)[3] = 0x437f0000;
    *(u_long128 *)(lpCurDMA + 12) = *(u_long128 *)GeomScale;
    lpMatDMA = lpCurDMA + 20;
    lpCurDMA = SetMatrixPacket(lpCurDMA + 16, lpVmdHead, lpMdlMng);
    for (i = 0, lpObj = lpVmdHead->lpObj; i < lpVmdHead->NumObj; i++, lpObj += 0x60) {
        if (*(s16 *)(lpObj + 0x32) != -1 && *(u32 *)(*(s32 *)(lpObj + 0x5c) + 8) != 0) {
            if (*(u8 *)(*(s32 *)(lpObj + 0x54) + 8) == 0 || (my->ds_hit & 0x2000) == 0) {
                lpCurDMA = DrawDropShadowObject(lpCurDMA, lpObj, lpMatDMA);
            }
        }
    }
    return lpCurDMA;
    }
}








extern void sceVu0InversMatrix(void *, void *);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern void sceVu0ScaleVectorXYZ(void *, void *, float);
extern void sceVu0Normalize(void *, void *);
static int CheckInnerShadow(struct ShBox *);
extern u16 GetMicroCodeMPG(u32 *);
extern struct ShInner InnerShadow;
extern u32 Vu1ProgMCShadowDraw[];
static u32 *DrawDropShadowObject(u32 *packet, void *model, void *matrices) {
    u8 *object = model;
    u32 matrixBase = (u32)matrices;
    float inverse[4][4] __attribute__((aligned(16)));
    sceVu0InversMatrix(inverse,(u8 *)matrices + (*(u16 **)(object+0x3c))[0]*64);
    sceVu0ApplyMatrix(InnerShadow.Cylinder.P,inverse,InnerShadow.WorldPos);
    sceVu0ScaleVectorXYZ(InnerShadow.Cylinder.P,InnerShadow.Cylinder.P,InnerShadow.GeomScale);
    sceVu0ApplyMatrix(InnerShadow.Cylinder.N,inverse,gShadowDir);
    sceVu0Normalize(InnerShadow.Cylinder.N,InnerShadow.Cylinder.N);
    if (CheckInnerShadow(*(void **)(object+0x4c)) == 0) return packet;
    packet[0] = 0x10000001;
    packet[1] = 0;
    packet[2] = 0;
    packet[3] = 0x6c01001c;
    packet[4] = *(s16 *)(object+0x3a);
    packet[5] = 0;
    packet[6] = 0;
    packet[7] = 0;
    packet += 8;
    {
        u32 i = 0;
        if ((u8 *)0 < (u8 *)(s32)*(s16 *)(object+0x3a)) {
            u32 offset = 0;
            u32 destination = 0x20;
            do {
                u32 source = (u32)*(u16 *)((u8 *)*(void **)(object+0x3c)+offset)*64;
                packet[0] = 0x30000004;
                packet[1] = matrixBase + source;
                packet[2] = 0;
                packet[3] = destination | 0x6c040000;
                destination += 4;
                offset += 2;
                i++;
                packet += 4;
            } while (i < (u32)*(s16 *)(object+0x3a));
        }
    }
    packet[0] = 0x10000000;
    packet[1] = 0;
    packet[2] = 0;
    packet[3] = (u16)GetMicroCodeMPG(Vu1ProgMCShadowDraw) | 0x15000000;
    packet[4] = 0x50000000;
    packet[5] = *(u32 *)(*(u32 *)(object+0x5c)+8);
    packet[6] = 0;
    packet[7] = 0;
    packet[8] = 0x10000000;
    packet[9] = 0;
    packet[10] = 0;
    packet[11] = 0x15000000;
    return packet+12;
}










extern void sceVu0UnitMatrix(void *);
extern void sceVu0ScaleVector(void *, void *, float);
extern void sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0RotMatrixX(void *, void *, float);
extern void sceVu0MulMatrix(void *, void *, void *);
extern void sceVu0CopyMatrix(void *, void *);
extern void sceVu0TransposeMatrix(void *, void *);
extern float atan2f(float, float);
extern float sqrtf(float);


struct ShMdl { u8 pad0[0x20]; float Pos[4]; u8 pad1[0xe8]; float ShadowSize; float ShadowHigh; };

#define SH_WRAP(a) ((3.1415927f + (a)) >= 0.0f ? ((a) - (6.2831855f * (float)(s32)((3.1415927f + (a)) / 6.2831855f))) : (6.2831855f + ((a) - (6.2831855f * (float)(s32)((3.1415927f + (a)) / 6.2831855f)))))

static unsigned int * SetShadowTexMatrixPacket(unsigned int *lpCurDMA, struct ShMdl *lpMyMdlMng) {
    float sh_mat[4][4] __attribute__((aligned(16)));
    static float TexCoordMatrix[4][4] = {{1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, -100.0f, 0.0f}, {0.5f, 0.5f, 0.0f, 1.0f}};
    float AngX;
    float AngY;
    float ShadowScale;

    AngX = atan2f(gShadowDir[1], sqrtf(gShadowDir[0] * gShadowDir[0] + gShadowDir[2] * gShadowDir[2]));
    AngY = atan2f(-gShadowDir[0], gShadowDir[2]);
    ShadowScale = 255.0f * (0.00128f / lpMyMdlMng->ShadowSize);
    sceVu0UnitMatrix(sh_mat);
    sh_mat[3][0] = -lpMyMdlMng->Pos[0] * ShadowScale;
    sh_mat[3][1] = ShadowScale * -(lpMyMdlMng->Pos[1] - lpMyMdlMng->ShadowHigh);
    sh_mat[3][2] = -lpMyMdlMng->Pos[2] * ShadowScale;
    sceVu0ScaleVector(sh_mat[0], sh_mat[0], ShadowScale);
    sceVu0ScaleVector(sh_mat[1], sh_mat[1], ShadowScale);
    sceVu0ScaleVector(sh_mat[2], sh_mat[2], ShadowScale);
    sceVu0RotMatrixY(sh_mat, sh_mat, SH_WRAP(AngY));
    sceVu0RotMatrixX(sh_mat, sh_mat, SH_WRAP(AngX));
    sceVu0MulMatrix(sh_mat, TexCoordMatrix, sh_mat);
    lpCurDMA[0] = 0x10000004;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x6c04000c;
    lpCurDMA += 4;
    sceVu0CopyMatrix(((ShMat *)lpCurDMA)++, sh_mat);
    sceVu0UnitMatrix(sh_mat);
    sceVu0Normalize(sh_mat, gShadowDir);
    sceVu0TransposeMatrix(sh_mat, sh_mat);
    lpCurDMA[0] = 0x10000004;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x6c040010;
    lpCurDMA += 4;
    sceVu0CopyMatrix(((ShMat *)lpCurDMA)++, sh_mat);
    return lpCurDMA;
}



extern void sceVu0ScaleVector(void *, void *, float);
extern void sceVu0AddVector(void *, void *, void *);
extern void sceVu0CopyVector(void *, void *);
static signed int CheckCylinderInnerSquare(short (*)[3], float *, float *);
static signed int CheckLineInnerCylinder(short (*)[3], float *, float *, float);



#define SH_ABS(x) (((x) < 0.0f) ? -(x) : (x))

#define SH_IN_BOX(b, p) \
    ((float)(b)->MM[0][0] < (p)[0] && (float)(b)->MM[1][0] > (p)[0] \
     && (float)(b)->MM[0][1] < (p)[1] && (float)(b)->MM[1][1] > (p)[1] \
     && (float)(b)->MM[0][2] < (p)[2] && (float)(b)->MM[1][2] > (p)[2])

static int CheckInnerShadow(struct ShBox *lpBoundBox) {
    int i;
    float Vec[4] __attribute__((aligned(16)));

    if (GameSt[5] == 4) {
        return 1;
    }
    sceVu0ScaleVector(Vec, InnerShadow.Cylinder.N, InnerShadow.Cylinder.H);
    if (SH_IN_BOX(lpBoundBox, InnerShadow.Cylinder.P)) {
        sceVu0AddVector(Vec, Vec, InnerShadow.Cylinder.P);
        if (SH_IN_BOX(lpBoundBox, Vec)) {
            return 1;
        }
        sceVu0ScaleVector(Vec, InnerShadow.Cylinder.N, InnerShadow.Cylinder.H);
    }
    if (CheckCylinderInnerSquare(lpBoundBox->MM, InnerShadow.Cylinder.P, Vec) == 1) {
        return 1;
    }
    if (CheckLineInnerCylinder(lpBoundBox->MM, InnerShadow.Cylinder.P, Vec, InnerShadow.Cylinder.R) == 1) {
        return 1;
    }
    sceVu0AddVector(Vec, Vec, InnerShadow.Cylinder.P);
    for (i = 0; i < 2; i++) {
        if ((float)lpBoundBox->MM[0][0] < Vec[0] && (float)lpBoundBox->MM[1][0] > Vec[0]
            && (float)lpBoundBox->MM[0][2] < Vec[2] && (float)lpBoundBox->MM[1][2] > Vec[2]) {
            if (SH_ABS((float)lpBoundBox->MM[0][1] - Vec[1]) < InnerShadow.Cylinder.R
                || SH_ABS((float)lpBoundBox->MM[1][1] - Vec[1]) < InnerShadow.Cylinder.R) {
                return 1;
            }
        }
        if ((float)lpBoundBox->MM[0][0] < Vec[0] && (float)lpBoundBox->MM[1][0] > Vec[0]
            && (float)lpBoundBox->MM[0][1] < Vec[1] && (float)lpBoundBox->MM[1][1] > Vec[1]) {
            if (SH_ABS((float)lpBoundBox->MM[0][2] - Vec[2]) < InnerShadow.Cylinder.R
                || SH_ABS((float)lpBoundBox->MM[1][2] - Vec[2]) < InnerShadow.Cylinder.R) {
                return 1;
            }
        }
        if ((float)lpBoundBox->MM[0][1] < Vec[1] && (float)lpBoundBox->MM[1][1] > Vec[1]
            && (float)lpBoundBox->MM[0][2] < Vec[2] && (float)lpBoundBox->MM[1][2] > Vec[2]) {
            if (SH_ABS((float)lpBoundBox->MM[0][0] - Vec[0]) < InnerShadow.Cylinder.R
                || SH_ABS((float)lpBoundBox->MM[1][0] - Vec[0]) < InnerShadow.Cylinder.R) {
                return 1;
            }
        }
        sceVu0CopyVector(Vec, InnerShadow.Cylinder.P);
    }
    return 0;
}



static signed int CheckCylinderInnerSquare(short (*MinMaxVertex)[3], float *Pos, float *Vec) {
    int Base;
    int d1;
    int d2;
    int i;
    int j;
    float t;
    float p1;
    float p2;
    float last_t;
    int flag;

    flag = 1;
    for (i = 0; i < 3; i++) {
        switch (i) {
        case 0:
            Base = 1;
            d1 = 0;
            d2 = 2;
            break;
        case 1:
            Base = 0;
            d1 = 1;
            d2 = 2;
            break;
        case 2:
            Base = 2;
            d1 = 0;
            d2 = 1;
            break;
        }
        for (j = 0; j < 2; j++) {
            if (Vec[Base] == 0.0f) {
                flag = 0;
            } else {
                t = ((float)MinMaxVertex[j][Base] - Pos[Base]) / Vec[Base];
                if (t < 0.0f || t > 1.0f) {
                    switch (flag) {
                    case 1:
                        flag = 2;
                        last_t = t;
                        break;
                    case 2:
                        if (last_t * t < 0.0f) {
                            flag = 1;
                        } else {
                            flag = 0;
                        }
                        break;
                    }
                } else {
                    p1 = Pos[d1] + t * Vec[d1];
                    p2 = Pos[d2] + t * Vec[d2];
                    if (p1 < (float)MinMaxVertex[0][d1] || p1 > (float)MinMaxVertex[1][d1]
                        || p2 < (float)MinMaxVertex[0][d2] || p2 > (float)MinMaxVertex[1][d2]) {
                        flag = 0;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
    return flag != 0;
}










static signed int CheckLineInnerCylinder(short (*MinMaxVector)[3], float *Pos, float *Vec, float Radius) {
    int Base;
    int d1;
    int d2;
    int i;
    int j;
    int k;
    float t;
    float s;
    float p1;
    float p2;
    float p3;

    for (i = 0; i < 3; i++) {
        switch (i) {
        case 0:
            Base = 0;
            d1 = 1;
            d2 = 2;
            break;
        case 1:
            Base = 2;
            d1 = 0;
            d2 = 1;
            break;
        case 2:
            Base = 1;
            d1 = 0;
            d2 = 2;
            break;
        }
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                if (Vec[d1] != 0.0f || Vec[d2] != 0.0f) {
                    s = (Vec[d1] * ((float)MinMaxVector[j][d1] - Pos[d1])
                         + Vec[d2] * ((float)MinMaxVector[k][d2] - Pos[d2]))
                        / (Vec[d1] * Vec[d1] + Vec[d2] * Vec[d2]);
                    t = (Pos[Base] + s * Vec[Base] - (float)MinMaxVector[0][Base])
                        / (float)(MinMaxVector[1][Base] - MinMaxVector[0][Base]);
                    if (s < 0.0f) {
                        s = 0.0f;
                    } else if (s > 1.0f) {
                        s = 1.0f;
                    }
                    if (t < 0.0f) {
                        t = 0.0f;
                    } else if (t > 1.0f) {
                        t = 1.0f;
                    }
                    p1 = Pos[d1] + s * Vec[d1] - (float)MinMaxVector[j][d1];
                    p2 = Pos[d2] + s * Vec[d2] - (float)MinMaxVector[k][d2];
                    p3 = Pos[Base] + s * Vec[Base]
                         - ((float)MinMaxVector[0][Base]
                            + t * (float)(MinMaxVector[1][Base] - MinMaxVector[0][Base]));
                    if (p1 * p1 + p2 * p2 + p3 * p3 < Radius * Radius) {
                        return 1;
                    }
                } else {
                    p1 = Pos[d1] - (float)MinMaxVector[j][d1];
                    p2 = Pos[d2] - (float)MinMaxVector[k][d2];
                    if (p1 * p1 + p2 * p2 < Radius * Radius) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

static struct ShInner InnerShadow;
