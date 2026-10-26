#include "common.h"

typedef struct MorphVertex { s16 x,y,z; u8 pad; unsigned char unused:4; unsigned char relative:1; unsigned char high:3; } MorphVertex;


static unsigned int *MakePresetMaterialPacket(unsigned int *, void *, void *, void *);
static unsigned int *MakePresetMorphPrimListPacket(unsigned int *, void *, void *, void *, void *);


/* MakePresetMaterialPacket @ 0x140160 .. 0x14046C (0x30c bytes, frame 0x60) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x58 escapes at 0x1403c0
 *   stack: address of the slot at 0x50 escapes at 0x1403d0
 *   cfg: kept branch: 0x1401fc if (..) goto .L001403A0
 *   cfg: kept branch: 0x140208 if (..) goto .L001403A0
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */

extern void * GetTexMngByName(void *, char *);
extern void * memset(void *, int, unsigned int);

struct dw_260842_fields_5295f04a;
struct dw_268256_fields_5295f04a;
struct dw_268796_fields_5295f04a;
struct dw_269490_fields_5295f04a;
struct dw_270726;
#ifndef PROTO_DW_271547_FIELDS_5295F04A
#define PROTO_DW_271547_FIELDS_5295F04A
struct dw_271547_fields_5295f04a { unsigned int A : 2; unsigned int B : 2; unsigned int C : 2; unsigned int D : 2; unsigned int pad8 : 24; unsigned int FIX : 8; unsigned int pad40 : 24; };
#endif
#ifndef PROTO_DW_268556_FIELDS_5295F04A
#define PROTO_DW_268556_FIELDS_5295F04A
struct dw_268556_fields_5295f04a { struct dw_271547_fields_5295f04a Alpha; unsigned char Abe; unsigned char Pabe; unsigned char Pad0[2]; };
#endif
#ifndef PROTO_DW_262465_FIELDS_5295F04A
#define PROTO_DW_262465_FIELDS_5295F04A
struct dw_262465_fields_5295f04a { float DiffuseColor[3]; float SpecularLevel; float SpecularColor[3]; float SpecularExp; struct dw_268256_fields_5295f04a *lpDiffuseTexture; struct dw_268256_fields_5295f04a *lpReflectionTexture; unsigned char SemiTrans; unsigned char DummyPolyId; unsigned char Selfillum; unsigned char Pad0; struct dw_269490_fields_5295f04a *lpMaterialParam; struct dw_268556_fields_5295f04a AlphaBlend; struct dw_270726 *lpMaterialReserve; };
#endif
#ifndef PROTO_DW_268256_FIELDS_5295F04A
#define PROTO_DW_268256_FIELDS_5295F04A
struct dw_268256_fields_5295f04a { char *lpTexFileName; struct dw_268796_fields_5295f04a *lpTex0; struct dw_260842_fields_5295f04a *lpTex1; int Pad0; };
#endif


struct mpm_Tex0 { u64 TBP0 : 14; u64 TBW : 6; u64 PSM : 6; u64 TW : 4; u64 TH : 4; u64 TCC : 1; u64 TFX : 2; u64 CBP : 14; u64 CPSM : 4; u64 CSM : 1; u64 CSA : 5; u64 CLD : 3; };
struct mpm_Tex1 { long LCM : 1; long pad01 : 1; long MXL : 3; long MMAG : 1; long MMIN : 3; long MTBA : 1; long pad10 : 9; long L : 2; long pad21 : 11; long K : 12; long pad44 : 20; };
struct mpm_Tm2 { unsigned int size; unsigned int wnum; unsigned char dummy[5]; unsigned char compare; unsigned short tex_id; struct mpm_Tex0 tex0; struct mpm_Tex1 tex1; };
struct mpm_TexMng { unsigned char bUse; unsigned char unused0; unsigned short id; struct mpm_Tm2 *lpTm2; };
struct mpm_Alpha { unsigned char A : 2; unsigned char B : 2; unsigned char C : 2; unsigned char D : 2; unsigned char pad8[3]; unsigned char FIX; unsigned char pad40[3]; };
struct mpm_Blend { struct mpm_Alpha Alpha; unsigned char Abe; unsigned char Pabe; unsigned char Pad0[2]; };
struct mpm_Param { unsigned char a; unsigned char b; unsigned char c; };
struct mpm_Tx { char *lpTexFileName; };
struct mpm_Mat { float DiffuseColor[3]; float SpecularLevel; float SpecularColor[3]; float SpecularExp; struct mpm_Tx *lpDiffuseTexture; struct mpm_Tx *lpReflectionTexture; unsigned char SemiTrans; unsigned char DummyPolyId; unsigned char Selfillum; unsigned char Pad0; struct mpm_Param *lpMaterialParam; struct mpm_Blend AlphaBlend; void *lpMaterialReserve; };
struct mpm_Prim { unsigned char KickMaterial : 1; unsigned char Index : 7; };

#define MAT ((struct mpm_Mat *)lpMaterialArg)
#define PRM ((struct mpm_Prim *)lpPrimHeadArg)


/* MakePresetPrimListPacket @ 0x140470 .. 0x14073C (0x2cc bytes) */
/*
 * dcomp notes:
 *   quad: t3: 128-bit web split from its scalar uses
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */

struct dw_257837_fields;
struct dw_258493_fields;
struct dw_258955_fields;
struct dw_259838_fields;
struct dw_260202_fields;
struct dw_260546_fields;
struct dw_261383_fields;
struct dw_261525_fields;
struct dw_261629_fields;
struct dw_262286_fields;
struct dw_262396_fields;
struct dw_262465_fields;
struct dw_264169;
struct dw_264269_fields;
struct dw_265014_fields;
struct dw_265536_fields;
struct dw_268228;
struct dw_268256_fields;
struct dw_269490_fields;
struct dw_270726;
#ifndef PROTO_DW_258955_FIELDS
#define PROTO_DW_258955_FIELDS
struct dw_258955_fields { unsigned short KickMaterial : 1; unsigned short Index : 15; unsigned char PolyNum; unsigned char PrimNum; struct dw_258493_fields *lpBoundBox; struct dw_258955_fields *lpNext; struct dw_259838_fields *lpVertex; struct dw_260546_fields *lpNormal; struct dw_261383_fields *lpTexCoord; struct dw_261525_fields *lpColor; struct dw_261629_fields *lpLightVec; struct dw_262286_fields *lpSpecVec; struct dw_262396_fields *lpLodVertex; struct dw_258955_fields *lpNextTree; struct dw_262465_fields *lpMaterial; struct dw_264169 *lpPrimHeadReserve; unsigned int Pad0[3]; };
#endif
#ifndef PROTO_DW_271547_FIELDS
#define PROTO_DW_271547_FIELDS
struct dw_271547_fields { unsigned int A : 2; unsigned int B : 2; unsigned int C : 2; unsigned int D : 2; unsigned int pad8 : 24; unsigned int FIX : 8; unsigned int pad40 : 24; };
#endif
#ifndef PROTO_DW_268556_FIELDS
#define PROTO_DW_268556_FIELDS
struct dw_268556_fields { struct dw_271547_fields Alpha; unsigned char Abe; unsigned char Pabe; unsigned char Pad0[2]; };
#endif
#ifndef PROTO_DW_262465_FIELDS
#define PROTO_DW_262465_FIELDS
struct dw_262465_fields { float DiffuseColor[3]; float SpecularLevel; float SpecularColor[3]; float SpecularExp; struct dw_268256_fields *lpDiffuseTexture; struct dw_268256_fields *lpReflectionTexture; unsigned char SemiTrans; unsigned char DummyPolyId; unsigned char Selfillum; unsigned char Pad0; struct dw_269490_fields *lpMaterialParam; struct dw_268556_fields AlphaBlend; struct dw_270726 *lpMaterialReserve; };
#endif
#ifndef PROTO_DW_263095_FIELDS
#define PROTO_DW_263095_FIELDS
struct dw_263095_fields { unsigned int VmdFileVersion; char *lpAp2FileName; int VmdFileSize; short MaterialNum; short MatrixNum; short ObjectNum; short GeomObjectNum; struct dw_262465_fields *lpMaterial; struct dw_264269_fields *lpMatrix; struct dw_265536_fields *lpObject; float GeomScale; unsigned int PrimNodeFormat; struct dw_257837_fields *lpLightObject; short LightObjectNum; short TextureNum; struct dw_258493_fields *lpBoundBox; int PolyNum : 24; int PrimNodeMax : 8; struct dw_265014_fields *lpHeadParam; struct dw_268256_fields *lpTexture; struct dw_268228 *lpHeadReserve; struct dw_260202_fields *lpPMObject; int Pad0[2]; };
#endif
#ifndef PROTO_DW_264543_FIELDS
#define PROTO_DW_264543_FIELDS
struct dw_264543_fields { unsigned char Specular; unsigned char Scissor; unsigned char Fog; unsigned char ParallelLight; unsigned char PointLight; unsigned char Joint; unsigned char TexScroll; unsigned char SortPrio; unsigned char ShadowLevel; unsigned char MorphID; unsigned char Mirror; unsigned char Pad0; };
#endif
#ifndef PROTO_DW_265014_FIELDS
#define PROTO_DW_265014_FIELDS
struct dw_265014_fields { int ProgramID; unsigned char ParallelDraw; unsigned char Fog; unsigned char ParallelLight; unsigned char PointLight; unsigned char AlphaSort; unsigned char Mirror; unsigned char AmbientID; unsigned char Specular; unsigned char ClothDataID; unsigned char DrawRegsID; unsigned char Pad0[2]; };
#endif


struct VmdObjParam { unsigned char Specular; unsigned char Scissor; unsigned char Fog; unsigned char ParallelLight; unsigned char PointLight; unsigned char Joint; unsigned char TexScroll; unsigned char SortPrio; unsigned char ShadowLevel; unsigned char MorphID; unsigned char Mirror; unsigned char Pad0; };



static unsigned int *MakePresetPrimListPacket(unsigned int *, void *, void *, void *, unsigned int, void *);


/* SetVmdData @ 0x140960 .. 0x140E10 (0x4b0 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   literal: @1561 is the string 'lip'
 *   literal: @1562 is the string 'lip-t0'
 *   literal: @1563 is the string 'lip-t1'
 *   literal: @1564 is the string 'lip-t2'
 *   stack: address of the slot at 0x70 escapes at 0x140994
 *   fpu: float literal 0x3f800000 at 0x1409d0
 *   delay: addiu at 0x140cdc writes a register its branch at 0x140cd8 reads
 *   stack: address of the slot at 0x80 escapes at 0x140d4c
 *   cfg: loop body is not one contiguous region: .L00140A30
 *   cfg: loop body is not one contiguous region: .L00140B08
 *   cfg: loop body is not one contiguous region: .L00140B20
 *   cfg: loop body is not one contiguous region: .L00140BB8
 *   cfg: loop body is not one contiguous region: .L00140D68
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern int strcmp(const char *, const char *);
extern unsigned short GetMicroCodeMPG(unsigned int *);
extern unsigned int * MakePresetShadowObjPacket(unsigned int *, void *);
extern u32 Vu1ProgMCScissor[];
extern u32 Vu1ProgMCClipAmbi[];
extern u32 Vu1ProgMCClipJointAmbi[];
extern u32 Vu1ProgMCClipJointLight[];

#ifndef PROTO_DW_271868_FIELDS
#define PROTO_DW_271868_FIELDS
struct dw_271868_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_266463_FIELDS
#define PROTO_DW_266463_FIELDS
struct dw_266463_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_271868_fields DmyPoly[32]; };
#endif


struct vd_Tree { unsigned int mc; unsigned int *packet; void *x8; struct vd_Obj *next; };
struct vd_Obj { unsigned char pad0[0x50]; char *lpObjectName; unsigned char *lpObjParam; void *x58; struct vd_Tree *lpTree; };
struct vd_Head { unsigned char pad0[0x10]; short ObjectNum; unsigned char pad1[0xa]; struct vd_Obj *lpObject; float GeomScale; unsigned char pad3[0x14]; unsigned char *lpHeadParam; };
struct vd_Mdl { unsigned char pad0[8]; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; unsigned char pad1; struct vd_Head *lpVmdHead; unsigned char pad2[0x44]; unsigned int *lpCurrent; };
#define MDL ((struct vd_Mdl *)lpMdlData)

typedef struct VmdRemap60 { u8 head[56]; u32 p56; } VmdRemap60;
typedef struct VmdRemap16 { u32 p0,p4,p8,pad; } VmdRemap16;
typedef struct VmdRemap96 { u8 head[58]; s16 count58; u32 p60,count64,p68,pad72,p76,p80,p84,p88,p92; } VmdRemap96;
typedef struct VmdRemap52 { u8 head[3]; u8 count3; u32 p4,p8,p12,p16,p20,p24,p28,p32,p36,p40,p44,p48; } VmdRemap52;
typedef struct VmdRemap64 { u8 head[32]; u32 p32,p36,pad40,p44,pad48,pad52,pad56,p60; } VmdRemap64;
typedef struct VmdRemap8 { u8 head[6]; unsigned short low:2,index:10,pad:1,flag:1,tail:2; } VmdRemap8;
#define VMD_REMAP(field) do { offset=(field); if (offset) (field)=(u32)base+offset; } while (0)
#undef VMD_REMAP


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void RemapVmdData(void *data);
void RemapVmdTree(void *a0 , unsigned int a1 );
void SetVmdData(void *lpMdlDataArg);
static unsigned int *MakePresetObjPacket(unsigned int *packet, void *object, void *state, unsigned int mode);
static unsigned int *MakePresetMorphObjPacket(unsigned int *a0, void *a1, void *a2, void *a3);
#define VMD_REMAP(field) do { offset=(field); if (offset) (field)=(u32)base+offset; } while (0)

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */

void RemapVmdData(void *data) {
    s32 modelIndex;
    u8 *base=data;
    u32 offset;
    VmdRemap96 *model;
    VMD_REMAP(*(u32 *)(base+4));
    VMD_REMAP(*(u32 *)(base+20));
    VMD_REMAP(*(u32 *)(base+24));
    VMD_REMAP(*(u32 *)(base+28));
    VMD_REMAP(*(u32 *)(base+40));
    VMD_REMAP(*(u32 *)(base+48));
    VMD_REMAP(*(u32 *)(base+56));
    VMD_REMAP(*(u32 *)(base+60));
    VMD_REMAP(*(u32 *)(base+64));
    VMD_REMAP(*(u32 *)(base+68));
    {
        VmdRemap60 *pointer=(VmdRemap60 *)*(u32 *)(base+40);
        u32 i;
        if (pointer && (u8 *)0<(u8 *)(s32)*(s16 *)(base+44)) {
            i=0;
            do {
            VMD_REMAP(pointer->p56);
            i++; pointer++;
        } while(i<(u32)*(s16 *)(base+44));
        }
    }
    {
        VmdRemap16 *pointer=(VmdRemap16 *)*(u32 *)(base+60);
        u32 i;
        if (pointer && (u8 *)0<(u8 *)(s32)*(s16 *)(base+46)) {
            i=0;
            do {
            VMD_REMAP(pointer->p0);
            VMD_REMAP(pointer->p4);
            VMD_REMAP(pointer->p8);
            i++; pointer++;
        } while(i<(u32)*(s16 *)(base+46));
        }
    }
    model=(VmdRemap96 *)*(u32 *)(base+28); modelIndex=0;
    if ((u8 *)0<(u8 *)(s32)*(s16 *)(base+16)) do {
        VmdRemap52 *pointer;
        VMD_REMAP(model->p60);
        VMD_REMAP(model->p68);
        VMD_REMAP(model->p76);
        VMD_REMAP(model->p80);
        VMD_REMAP(model->p84);
        VMD_REMAP(model->p88);
        VMD_REMAP(model->p92);
        pointer=(VmdRemap52 *)model->p68;
        data=0;
        if ((u8 *)0<(u8 *)model->count64) do {
            VmdRemap8 *parts;
            u32 j;
            VMD_REMAP(pointer->p4);
            VMD_REMAP(pointer->p8);
            VMD_REMAP(pointer->p12);
            VMD_REMAP(pointer->p16);
            VMD_REMAP(pointer->p20);
            VMD_REMAP(pointer->p24);
            VMD_REMAP(pointer->p28);
            VMD_REMAP(pointer->p32);
            VMD_REMAP(pointer->p36);
            VMD_REMAP(pointer->p40);
            VMD_REMAP(pointer->p44);
            VMD_REMAP(pointer->p48);
            parts=(VmdRemap8 *)pointer->p12;
            j=0;
            if ((u8 *)0<(u8 *)(u32)pointer->count3) do {
                parts->index=(parts->index<<2)+parts->low;
                parts->low=!parts->flag;
                j++; parts++;
            } while(j<pointer->count3);
            if (model->count58>17) model->count58=17;
            data=(u8 *)data+1; pointer=(VmdRemap52 *)pointer->p8;
        } while((u32)data<model->count64);
        RemapVmdTree((void *)model->p88,(u32)base);
        modelIndex++; model++;
    } while((u32)modelIndex<(u32)*(s16 *)(base+16));
    {
        VmdRemap64 *pointer=(VmdRemap64 *)*(u32 *)(base+20);
        u32 i=0;
        if ((u8 *)0<(u8 *)(s32)*(s16 *)(base+12)) do {
            VMD_REMAP(pointer->p32);
            VMD_REMAP(pointer->p36);
            VMD_REMAP(pointer->p44);
            VMD_REMAP(pointer->p60);
            i++; pointer++;
        } while(i<(u32)*(s16 *)(base+12));
    }
}


/* RemapVmdTree @ 0x140E10 .. 0x140EE4 (0xd4 bytes, frame 0x30) */

void RemapVmdTree(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u8 *s1;
    s32 s0;
    u32 v1;

    s1 = (u8 *)a0;
    s0 = a1;
    if ((u32)s1 != 0) {
        v1 = *(s32 *)s1;
        if (v1 != 0) {
            *(u32 *)s1 = s0 + v1;
        }
        v1 = *(s32 *)(s1 + 4);
        if (v1 != 0) {
            *(u32 *)(s1 + 4) = s0 + v1;
        }
        v1 = *(s32 *)(s1 + 0xc);
        if (v1 != 0) {
            *(u32 *)(s1 + 0xc) = s0 + v1;
        }
        v1 = *(s32 *)(s1 + 8);
        if (v1 != 0) {
            *(u32 *)(s1 + 8) = s0 + v1;
        }
        v1 = *(s32 *)(s1 + 0x10);
        if (v1 != 0) {
            *(u32 *)(s1 + 0x10) = s0 + v1;
        }
        a0 = (void *)*(s32 *)(s1 + 0xc);
        a1 = (s32)s0;
        if ((u32)(s32)a0 != 0) {
            RemapVmdTree(a0, a1);
        }
        a0 = (void *)*(s32 *)(s1 + 8);
        a1 = s0;
        if ((u32)(s32)a0 != 0) {
            RemapVmdTree(a0, a1);
        }
    }
    return;
}

void SetVmdData(void *lpMdlDataArg) {
    u8 *lpMdlData = lpMdlDataArg;
    unsigned int i;
    unsigned int *lpCurDMA;
    struct vd_Head *lpVmdHead;
    struct vd_Obj *lpVmdObj;
    struct vd_Obj *lpLastVmdObj;
    int ObjectNum;
    unsigned char SortPrio;
    unsigned int prio;
    unsigned char *prm;
    struct vd_Obj *lpMorphObj;
    struct vd_Obj *apMorphTargetObj[3];
    int m;
    int ID;
    int n;

    lpVmdHead = *(struct vd_Head **)(lpMdlData + 0x10);
    {
    float GeomScale[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    lpCurDMA = *(unsigned int **)(lpMdlData + 0x58);
    lpCurDMA[0] = 0x10000001;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x6c01001d;
    GeomScale[0] = 1.0f / lpVmdHead->GeomScale;
    GeomScale[1] = 1.0f / 127.0f;
    GeomScale[3] = 255.0f;
    *(u_long128 *)(lpCurDMA + 4) = *(u_long128 *)GeomScale;
    lpCurDMA[8] = 0x60000000;
    lpCurDMA[9] = 0;
    lpCurDMA[10] = 0;
    lpCurDMA[11] = 0;
    lpCurDMA += 12;
    lpVmdObj = lpVmdHead->lpObject;
    for (i = 0; n = lpVmdHead->ObjectNum, i < n; i++) {
        lpVmdObj->lpTree->next = 0;
        if (strcmp(lpVmdObj->lpObjectName, "lip") == 0) {
            lpVmdObj->lpObjParam[9] = 10;
        } else if (strcmp(lpVmdObj->lpObjectName, "lip-t0") == 0) {
            lpVmdObj->lpObjParam[9] = 11;
        } else if (strcmp(lpVmdObj->lpObjectName, "lip-t1") == 0) {
            lpVmdObj->lpObjParam[9] = 12;
        } else if (strcmp(lpVmdObj->lpObjectName, "lip-t2") == 0) {
            lpVmdObj->lpObjParam[9] = 13;
        }
        lpVmdObj++;
    }
    lpLastVmdObj = lpVmdHead->lpObject;
    ObjectNum = n - 1;
    for (SortPrio = 0; ObjectNum != 0; SortPrio++) {
        struct vd_Obj *obj = lpVmdHead->lpObject + 1;
        i = 1;
        if (n = lpVmdHead->ObjectNum, i < n) {
            prio = SortPrio;
            do {
                prm = obj->lpObjParam;
                if (prm[9] % 10 != 0) {
                    ObjectNum--;
                } else if (prm[7] == prio) {
                    lpLastVmdObj->lpTree->next = obj;
                    ObjectNum--;
                    lpLastVmdObj = obj;
                }
                i++;
                obj++;
            } while (n = lpVmdHead->ObjectNum, i < n);
        }
    }
    lpVmdObj = lpVmdHead->lpObject;
    lpVmdHead->lpHeadParam[11] = 0;
    lpVmdHead->lpHeadParam[9] = 0;
    for (i = 0; i < lpVmdHead->ObjectNum; i++, lpVmdObj++) {
        lpVmdObj->lpTree->packet = lpCurDMA;
        lpVmdHead->lpHeadParam[11] |= lpVmdObj->lpObjParam[0];
        lpVmdHead->lpHeadParam[9] |= lpVmdObj->lpObjParam[10];
        lpVmdObj->lpObjParam[1] = 0;
        lpCurDMA = MakePresetObjPacket(lpCurDMA, lpMdlData, lpVmdObj, *(unsigned short *)(lpMdlData + 0xa));
        if (lpVmdObj->lpObjParam[1] != 0) {
            lpVmdObj->lpTree->mc = GetMicroCodeMPG(Vu1ProgMCScissor);
        } else {
            unsigned char *hp = lpVmdHead->lpHeadParam;
            unsigned int x = hp[7];
            if (x != 0) {
                if ((unsigned char)x == 1) {
                    lpVmdObj->lpTree->mc = GetMicroCodeMPG(Vu1ProgMCClipAmbi);
                } else {
                    lpVmdObj->lpTree->mc = GetMicroCodeMPG(Vu1ProgMCClipJointAmbi);
                }
            } else if (hp[6] == 0) {
                lpVmdObj->lpTree->mc = GetMicroCodeMPG(Vu1ProgMCClipAmbi);
            } else {
                lpVmdObj->lpTree->mc = GetMicroCodeMPG(Vu1ProgMCClipJointLight);
            }
        }
        switch (*(unsigned short *)(lpMdlData + 0xa)) {
        case 3:
        case 4:
            lpCurDMA = MakePresetShadowObjPacket(lpCurDMA, lpVmdObj);
            if (lpVmdObj->lpTree->x8 == 0) break;
            *(u8 *)(lpMdlData + 0xe) = 1;
        }
        if (lpVmdObj->lpObjParam[9] != 0 && lpVmdObj->lpObjParam[9] % 10 == 0) {
            lpMorphObj = lpVmdHead->lpObject;
            memset(apMorphTargetObj, 0, 12);
            for (m = 0; m < lpVmdHead->ObjectNum; m++) {
                ID = lpMorphObj->lpObjParam[9];
                if (ID != 0) {
                    ID = ID - lpVmdObj->lpObjParam[9];
                    if (ID > 0 && ID <= 3) {
                        apMorphTargetObj[ID - 1] = lpMorphObj;
                    }
                }
                lpMorphObj++;
            }
            lpCurDMA = MakePresetMorphObjPacket(lpCurDMA, lpMdlData, lpVmdObj, apMorphTargetObj);
        }
    }
    *(unsigned int **)(lpMdlData + 0x58) = lpCurDMA;
    }
}
static unsigned int *MakePresetObjPacket(unsigned int *packet, void *object, void *state, unsigned int mode) {
    u8 *obj;
    u8 *st;
    u32 savedMode;
    u32 t1;
    u8 *entry;
    float *envY;
    float *envZ;
    float *colorY;
    float *colorZ;
    u32 v1, v0;
    void *material;
    float env[4] __attribute__((aligned(16)));
    float color[4] __attribute__((aligned(16)));
    obj = object;
    st = state;
    savedMode = mode;
    entry = *(u8 **)((u8 *)state + 0x44);
    if (entry != 0) {
        envY = &env[1];
        envZ = &env[2];
        colorY = &color[1];
        colorZ = &color[2];
        do {
            ((struct { unsigned char active:1; } *)entry)->active = 0;
            material = *(void **)(entry + 0x2c);
            if (material != 0) {
                v1 = *((u8 *)material + 0x29);
                if (v1 == 0xff) {
                    if (material != 0) {
                        v0 = *(u32 *)((u8 *)material + 0x24);
                        if (v0 != 0 && (*(u8 **)(st + 0x54))[1] == 0)
                            ((struct { unsigned char active:1; } *)entry)->active = 1;
                        material = *(void **)(entry + 0x2c);
                        packet = MakePresetMaterialPacket(packet, material, entry, *(void **)(obj + 0x44));
                        v0 = *entry & 1;
                        if (v0 != 0) {
                            v0 = *(u32 *)(st + 0x54);
                            v1 = v0 + 6;
                            if (v0 != 0) {
                                v0 = ((struct { u8 pad[6]; u8 value; } *)v0)->value;
                                if (v0 != 0 && (s32)v0 <= 199) *(u8 *)v1 = v0 + 200;
                            }
                        }
                        if (**(u8 **)(st + 0x54) != 0) {
                            material = *(void **)(entry + 0x2c);
                            env[0] = *(float *)((u8 *)material + 0xc);
                            *envY = 1.0f - *(float *)((u8 *)material + 0x1c) / 2.0f;
                            *envZ = *(float *)((u8 *)material + 0x1c) / 2.0f;
                            color[0] = *(float *)((u8 *)material + 0x10);
                            *colorY = *(float *)((u8 *)material + 0x14);
                            *colorZ = *(float *)((u8 *)material + 0x18);
                            packet[0] = 0x10000002; packet[1] = 0; packet[2] = 0; packet[3] = 0x6c02800c;
                            *(u_long128 *)(packet + 4) = *(u_long128 *)env;
                            *(u_long128 *)(packet + 8) = *(u_long128 *)color;
                            packet += 12;
                        }
                    }
                    t1 = *(u32 *)(st + 0x54);
                    packet = MakePresetPrimListPacket(packet, *(void **)(obj + 0x10), entry, *(void **)(entry + 0x2c), savedMode, (void *)t1);
                }
            }
            entry = *(u8 **)(entry + 8);
        } while (entry != 0);
    }
    packet[0] = 0x60000000; packet[1] = 0; packet[2] = 0; packet[3] = 0;
    return packet + 4;
}

static unsigned int *MakePresetPrimListPacket(unsigned int *lpCurDMA, void *lpVmdHead, void *lpPrimHead, void *lpMaterial, unsigned int MdlType, void *lpObjParam) {
    s32 xt3;
    u32 xt2;
    s32 xt1;
    s32 xt0;
    u32 Scissor;
    u32 PrimReg;
    u8 *prim = lpPrimHead;
    u8 *mat = lpMaterial;

    Scissor = *((u8 *)lpObjParam + 1) != 0;
    *(u32 *)lpCurDMA = (0x10000000) | 1;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x6c01800e;
    *(u_long128 *)(lpCurDMA + 4) = *(u_long128 *)prim;
    lpCurDMA[8] = (Scissor + 1) | (0x10000000);
    lpCurDMA[9] = 0;
    lpCurDMA[10] = 0;
    lpCurDMA[11] = ((Scissor + 1) << 16) | 0x6c00800f;
    PrimReg = 0xc;
    if (*(u8 *)(*(u32 *)((u8 *)lpVmdHead + 0x38) + 5) != 0) PrimReg |= 0x20;
    switch ((unsigned short)MdlType) {
    case 3:
        if (mat == 0 || mat[0x38] == 0) break;
        PrimReg |= 0x40;
        break;
    default:
        PrimReg |= 0x40;
    }
    if (mat != 0 && *(u32 *)(mat + 0x20) != 0) PrimReg |= 0x10;
    lpCurDMA[12] = prim[3] | 0x8000;
    lpCurDMA[13] = (PrimReg << 15) | (0x4000 | 0x30000000);
    lpCurDMA[14] = 0x412;
    lpCurDMA[15] = 0;
    lpCurDMA += 16;
    if (((struct VmdObjParam *)lpObjParam)->Scissor != 0) {
        lpCurDMA[0] = prim[3] | 0x8000;
        lpCurDMA[1] = ((PrimReg | 5) << 15) | (0x4000 | 0x30000000);
        lpCurDMA[2] = 0x412;
        lpCurDMA[3] = 0;
        lpCurDMA += 4;
    }
    lpCurDMA[0] = 0x10000000;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x01000104;
    {
        u32 nb = prim[3] << 3;
        lpCurDMA[4] = ((nb >> 4) + ((15 & nb) != 0)) | 0x30000000;
    }
    lpCurDMA[5] = *(u32 *)(12 + prim);
    lpCurDMA[6] = 0;
    lpCurDMA[7] = (prim[3] << 16) | 0x6d000000 | ((((Scissor + 0x10))) | 0x8000);
    lpCurDMA += 8;
    if (*(u32 *)((u8 *)lpVmdHead + 36) == 0x97a5) {
        u32 nb = prim[3] * 3;
        lpCurDMA[0] = ((nb >> 4) + ((nb & 15) != 0)) | 0x30000000;
        lpCurDMA[1] = *(u32 *)(prim + 16);
        lpCurDMA[2] = 0;
        lpCurDMA[3] = (prim[3] << 16) | 0x6a000000 | ((Scissor + 0x11) | 0x8000);
        lpCurDMA += 4;
    }
    {
        u32 nb = prim[3] << 2;
        lpCurDMA[0] = ((nb >> 4) + ((nb & 15) != 0)) | 0x30000000;
        lpCurDMA[1] = *(u32 *)(prim + 20);
        lpCurDMA[2] = 0;
        xt0 = (Scissor + 0x12);
        lpCurDMA[3] = (prim[3] << 16) | 0x65000000 | (xt0 | 0x8000);
        nb = prim[3] << 2;
        lpCurDMA[4] = ((nb >> 4) + ((nb & 15) != 0)) | 0x30000000;
        lpCurDMA[5] = *(u32 *)((24 + (u32)prim));
        lpCurDMA[6] = 0;
        lpCurDMA[7] = (prim[3] << 16) | 0x6e000000 | ((0x13 + Scissor) | 0xc000);
        lpCurDMA[8] = 0x10000000;
        lpCurDMA[9] = 0;
        lpCurDMA[10] = 0;
        lpCurDMA[11] = 0x01000404;
        lpCurDMA[12] = 0x10000000;
        lpCurDMA[13] = 0;
        lpCurDMA[14] = 0;
        lpCurDMA[15] = 0x17000000;
    }
    return lpCurDMA + 16;
}
static unsigned int *MakePresetMaterialPacket(unsigned int *lpCurDMA, void *lpMaterialArg, void *lpPrimHeadArg, void *lpTexList) {
    struct mpm_TexMng *lpTexMng;
    struct mpm_Tm2 *lpTm2;
    struct mpm_Tex0 dummytex0;
    struct mpm_Tex1 dummytex1;

    if (MAT->AlphaBlend.Abe == 0) {
        MAT->AlphaBlend.Alpha.A = 0;
        MAT->AlphaBlend.Alpha.B = 1;
        MAT->AlphaBlend.Alpha.C = 0;
        MAT->AlphaBlend.Alpha.D = 1;
    }
    if (MAT->lpDiffuseTexture != 0) {
        char *name = MAT->lpDiffuseTexture->lpTexFileName;
        if (name == 0) goto nodata;
        lpTexMng = (struct mpm_TexMng *)GetTexMngByName(lpTexList, name);
        if (lpTexMng == 0) goto nodata;
        lpTm2 = lpTexMng->lpTm2;
        lpCurDMA[0] = 0x10000005;
        lpCurDMA[1] = 0;
        lpCurDMA[2] = 0;
        lpCurDMA[3] = 0x6c05c000;
        lpCurDMA[4] = 0x8004;
        lpCurDMA[5] = 0x10000000;
        lpCurDMA[6] = 14;
        lpCurDMA[7] = 0;
        lpTm2->tex0.CLD = 1;
        *(u64 *)(lpCurDMA + 8) = 0;
        *(u64 *)(lpCurDMA + 10) = 0x3f;
        *(u64 *)(lpCurDMA + 12) = *(u64 *)&lpTm2->tex1;
        *(u64 *)(lpCurDMA + 14) = 0x14;
        *(u64 *)(lpCurDMA + 16) = *(u64 *)&lpTm2->tex0;
        *(u64 *)(lpCurDMA + 18) = 6;
        *(u64 *)(lpCurDMA + 20) = *(u64 *)&MAT->AlphaBlend;
        *(u64 *)(lpCurDMA + 22) = 0x42;
        lpCurDMA += 24;
        if (PRM->KickMaterial) {
            lpTexMng = (struct mpm_TexMng *)GetTexMngByName(lpTexList, MAT->lpReflectionTexture->lpTexFileName);
            if (lpTexMng != 0) {
                lpTm2 = lpTexMng->lpTm2;
                lpCurDMA[0] = 0x10000003;
                lpCurDMA[1] = 0;
                lpCurDMA[2] = 0;
                lpCurDMA[3] = 0x6c03c006;
                lpCurDMA[4] = 0x8002;
                lpCurDMA[5] = 0x10000000;
                lpCurDMA[6] = 14;
                lpCurDMA[7] = 0;
                *(u64 *)(lpCurDMA + 8) = *(u64 *)&lpTm2->tex0;
                *(u64 *)(lpCurDMA + 10) = 6;
                if (MAT->lpMaterialParam != 0 && MAT->lpMaterialParam->c != 0) {
                    *(u64 *)(lpCurDMA + 12) = 0x8000000089ULL;
                    *(u64 *)(lpCurDMA + 14) = 0x42;
                    lpCurDMA += 16;
                } else {
                    *(u64 *)(lpCurDMA + 12) = 0x8000000068ULL;
                    *(u64 *)(lpCurDMA + 14) = 0x42;
                    lpCurDMA += 16;
                }
            } else {
                PRM->KickMaterial = 0;
            }
        }
        return lpCurDMA;
    } else {
nodata:
    PRM->KickMaterial = 0;
    memset(&dummytex0, 0, 8);
    memset(&dummytex1, 0, 8);
    lpCurDMA[0] = 0x10000005;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x6c05c000;
    lpCurDMA[4] = 0x8004;
    lpCurDMA[5] = 0x10000000;
    lpCurDMA[6] = 14;
    lpCurDMA[7] = 0;
    *(u64 *)(lpCurDMA + 8) = 0;
    *(u64 *)(lpCurDMA + 10) = 0x3f;
    *(u64 *)(lpCurDMA + 12) = *(u64 *)&dummytex1;
    *(u64 *)(lpCurDMA + 14) = 0x14;
    *(u64 *)(lpCurDMA + 16) = *(u64 *)&dummytex0;
    *(u64 *)(lpCurDMA + 18) = 6;
    *(u64 *)(lpCurDMA + 20) = *(u64 *)&MAT->AlphaBlend;
    *(u64 *)(lpCurDMA + 22) = 0x42;
    return lpCurDMA + 24;
    }
}
static unsigned int *MakePresetMorphObjPacket(unsigned int *a0, void *a1, void *a2, void *a3) {
    u8 *s5;
    u8 *s4;
    u32 t0;
    u8 *s3;
    float *s2;
    u32 v1;
    float *s1;
    float *s6;
    float *s7;
    u32 *s0;
    u32 v0;
    void *arg1;
    u8 *arg2;
    u32 morph[4] __attribute__((aligned(16)));
    float env[4] __attribute__((aligned(16)));
    float color[4] __attribute__((aligned(16)));
    s5 = a1;
    s4 = a2;
    a1 = 0;
    s3 = *(u8 **)((u8 *)a2 + 0x44);
    s0 = morph;
    v0 = *(u32 *)((u8 *)a2 + 0x5c);
    v1 = (u32)morph;
    *(u32 *)(v0 + 0x10) = (u32)a0;
    do {
        v0 = *(u32 *)a3;
        if (v0) *(u32 *)v1 = *(u32 *)(v0 + 0x44);
        else *(u32 *)v1 = 0;
        a1 = (void *)((u8 *)a1 + 1);
        v0 = (s32)a1 < 3;
        a3 = (u8 *)a3 + 4;
        v1 += 4;
    } while (v0);
    s2 = &env[1];
    if (s3) {
        s1 = &env[2];
        s6 = &color[1];
        s7 = &color[2];
        do {
            ((struct { unsigned char active:1; } *)s3)->active = 0;
            arg2 = *(u8 **)(s3 + 0x2c);
            if (arg2) {
                v1 = arg2[0x29];
                if (v1 == 0xff) {
                    if (arg2) {
                        v0 = *(u32 *)(arg2 + 0x24);
                        if (v0 && (*(u8 **)(s4 + 0x54))[1] == 0) {
                            ((struct { unsigned char active:1; } *)s3)->active = 1;
                        }
                        arg1 = *(void **)(s3 + 0x2c);
                        a3 = *(void **)(s5 + 0x44);
                        a0 = MakePresetMaterialPacket(a0, arg1, s3, a3);
                        v0 = *s3 & 1;
                        if (v0) {
                            v0 = *(u32 *)(s4 + 0x54);
                            v1 = v0 + 6;
                            if (v0) {
                                v0 = ((struct { u8 pad[6]; u8 value; } *)v0)->value;
                                if (v0 && (s32)v0 <= 199) *(u8 *)v1 = v0 + 200;
                            }
                        }
                        if (**(u8 **)(s4 + 0x54)) {
                            arg1 = *(void **)(s3 + 0x2c);
                            env[0] = *(float *)((u8 *)arg1 + 0xc);
                            *s2 = 1.0f - *(float *)((u8 *)arg1 + 0x1c) / 2.0f;
                            *s1 = *(float *)((u8 *)arg1 + 0x1c) / 2.0f;
                            color[0] = *(float *)((u8 *)arg1 + 0x10);
                            *s6 = *(float *)((u8 *)arg1 + 0x14);
                            *s7 = *(float *)((u8 *)arg1 + 0x18);
                            a0[0] = 0x10000002;
                            a0[1] = 0;
                            a0[2] = 0;
                            a0[3] = 0x6c02800c;
                            *(u_long128 *)(a0 + 4) = *(u_long128 *)env;
                            *(u_long128 *)(a0 + 8) = *(u_long128 *)color;
                            a0 += 12;
                        }
                    }
                    t0 = *(u32 *)(s3 + 0x2c);
                    a0 = MakePresetMorphPrimListPacket(a0, *(void **)(s5 + 0x10), s3, morph, (void *)t0);
                }
            }
            s3 = *(u8 **)(s3 + 8);
            v1 = 0;
            a1 = s0;
            do {
                v0 = *(u32 *)a1;
                if (v0) *(u32 *)a1 = *(u32 *)(v0 + 8);
                v1++;
                v0 = (s32)v1 < 3;
                a1 = (u8 *)a1 + 4;
            } while (v0);
        } while (s3);
    }
    a0[0] = 0x60000000;
    a0[1] = 0;
    a0[2] = 0;
    a0[3] = 0;
    return a0 + 4;
}
static unsigned int *MakePresetMorphPrimListPacket(unsigned int *packet, void *model, void *primitive, void *morphs, void *object) {
    u_long128 color;
    u8 *prim = primitive;
    u32 flags;
    s32 i;
    s32 tag;
    s32 bytes;
    u32 command;
    command = 0x10000000;
    tag = command | 1;
    *(u32 *)packet = tag;
    command = 0x6c010000;
    packet[1] = 0;
    packet[2] = 0;
    bytes = command | 0x800e;
    command |= 0x800f;
    packet[3] = bytes;
    color = *(u_long128 *)prim;
    *(u_long128 *)(packet+4) = color;
    packet[8] = tag;
    packet[9] = 0;
    packet[10] = 0;
    packet[11] = command;
    command = *(u8 *)((u8 *)*(void **)((u8 *)model+56)+5);
    flags = 12;
    if (command) flags |= 32;
    flags |= 64;
    if (object && *(u32 *)((u8 *)object+32)) flags |= 16;
    packet[12] = prim[3] | 0x8000;
    packet[13] = (flags<<15) | 0x30004000;
    packet[14] = 0x412;
    packet[15] = 0;
    tag = 0x10000000;
    packet[16] = tag;
    packet[17] = 0;
    packet[18] = 0;
    packet[19] = 0x01000107;
    {
        u32 nb = prim[3]<<3;
        tag = ((nb>>4)+((nb&15)!=0)) | 0x30000000;
    }
    packet[20] = tag;
    bytes = *(u32 *)(prim+12);
    packet[21] = bytes;
    packet[22] = 0;
    bytes = prim[3];
    packet[23] = (bytes<<16) | 0x6d008010;
    packet += 24;
    i = 0;
    do {
        void *morph = *(void **)morphs;
        if (morph) {
            MorphVertex *dst = *(MorphVertex **)((u8 *)morph+12);
            MorphVertex *src = *(MorphVertex **)(prim+12);
            u8 count = prim[3]-1;
            if (prim[3]) {
                do {
                    if (!dst->relative) {
                        dst->x -= src->x;
                        dst->y -= src->y;
                        dst->z -= src->z;
                        dst->relative = 1;
                    }
                    dst++;
                    src++;
                } while (count--);
            }
            packet[0] = tag;
            packet[1] = *(u32 *)((u8 *)*(void **)morphs+12);
            packet[2] = 0;
            packet[3] = (prim[3]<<16) | 0x6d000000 | ((i+17) | 0x8000);
            packet += 4;
        }
        i++;
        morphs = (u8 *)morphs+4;
    } while (i<3);
    if (*(u32 *)((u8 *)model+36)==0x97a5) {
        u32 bytes = prim[3]*3;
        packet[0] = ((bytes>>4)+((bytes&15)!=0)) | 0x30000000;
        packet[1] = *(u32 *)(prim+16);
        packet[2] = 0;
        packet[3] = (prim[3]<<16) | 0x6a008014;
        packet += 4;
    }
    {
        u32 bytes = prim[3]<<2;
        packet[0] = ((bytes>>4)+((bytes&15)!=0)) | 0x30000000;
        packet[1] = *(u32 *)(prim+20);
        packet[2] = 0;
        packet[3] = (prim[3]<<16) | 0x65008015;
        bytes = prim[3]<<2;
        packet[4] = ((bytes>>4)+((bytes&15)!=0)) | 0x30000000;
        packet[5] = *(u32 *)(prim+24);
        packet[6] = 0;
        packet[7] = (prim[3]<<16) | 0x6e00c016;
        packet[8] = 0x10000000;
        packet[9] = 0;
        packet[10] = 0;
        packet[11] = 0x01000404;
        packet[12] = 0x10000000;
        packet[13] = 0;
        packet[14] = 0;
        packet[15] = 0x17000000;
    }
    return packet+16;
}
