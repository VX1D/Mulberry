#include "common.h"

static unsigned int * MakePresetPrimListPacket(unsigned int *, void *);
/* SetSmdData @ 0x168C60 */
struct dw_744408;
struct dw_744701;
struct dw_745862;
struct dw_745927;
struct dw_748108;
struct dw_748911;
struct dw_751233;
struct dw_753427;
struct dw_757461;
struct dw_757740;
struct dw_757809;
struct dw_758616;
struct dw_759146;
struct dw_760304;
struct dw_760628;
struct dw_761031;
struct dw_761589;
struct dw_761882;
struct dw_763617;
struct dw_764545;
struct dw_767645;
struct dw_769201 {
    float Pos[4];
    float Nrm[4];
    short ObjectId;
    unsigned char Type;
    unsigned char Id;
    unsigned int unused[3];
};
struct dw_752027 {
    int MaxAnimParam;
    unsigned int TexInVmd;
    unsigned short MdlNo;
    unsigned short MdlType;
    unsigned char bMultiDraw;
    unsigned char DmyPolyNum;
    unsigned char DropShadow;
    char unused0;
    void *lpVmdHead;
    void *lpAniHead;
    void *lpHmdHead;
    void *lpSmdHead;
    void *lpMicHead;
    void *lpMi3Index;
    void *lpJcnFileHead;
    void *lpAnimParam;
    void *lpBndFile;
    void *lpMdlFile;
    void *lpAniFile;
    void *lpHdlFile;
    void *lpSdlFile;
    void *lpTexList;
    void *lpDss;
    void *lpPrm;
    unsigned int *lpObjGroupID;
    unsigned int *lpPacket;
    unsigned int *lpCurrent;
    unsigned int *lpTexPacket;
    unsigned int *lpTexCurrent;
    unsigned int MdlPacketSize;
    unsigned int TexPacketSize;
    float aMorphRate[3];
    unsigned int unused[2];
    struct dw_769201 DmyPoly[32];
};
struct dw_744853 {
    unsigned int VmdFileVersion;
    char *lpAp2FileName;
    int VmdFileSize;
    short MaterialNum;
    short MatrixNum;
    short ObjectNum;
    short GeomObjectNum;
    struct dw_753427 *lpMaterial;
    struct dw_757461 *lpMatrix;
    struct dw_748108 *lpObject;
    float GeomScale;
    unsigned int PrimNodeFormat;
    struct dw_759146 *lpLightObject;
    short LightObjectNum;
    short TextureNum;
    struct dw_744701 *lpBoundBox;
    int PolyNum : 24;
    int PrimNodeMax : 8;
    struct dw_761031 *lpHeadParam;
    struct dw_757809 *lpTexture;
    struct dw_745862 *lpHeadReserve;
    struct dw_761882 *lpPMObject;
    int Pad0[2];
};
struct dw_748108 {
    float Position[4];
    float Angle[4];
    float Scale[4];
    short ObjectId;
    short GeomObjectId;
    short ParentObjectId;
    short ChildObjectId;
    short SiblingObjectId;
    short MatrixNum;
    unsigned short *lpMatrixId;
    int PrimListNum;
    struct dw_745927 *lpPrimHead;
    unsigned short PolyNum;
    unsigned short TreeNum;
    struct dw_744701 *lpBoundBox;
    char *lpObjectName;
    struct dw_751233 *lpObjParam;
    struct dw_744408 *lpTree;
    struct dw_760628 *lpObjReserve;
};
struct dw_745927 {
    short KickMaterial : 1;
    short Index : 15;
    unsigned char PolyNum;
    unsigned char PrimNum;
    struct dw_744701 *lpBoundBox;
    struct dw_745927 *lpNext;
    struct dw_748911 *lpVertex;
    struct dw_757740 *lpNormal;
    struct dw_758616 *lpTexCoord;
    struct dw_760304 *lpColor;
    struct dw_761589 *lpLightVec;
    struct dw_763617 *lpSpecVec;
    struct dw_764545 *lpLodVertex;
    struct dw_745927 *lpNextTree;
    struct dw_753427 *lpMaterial;
    struct dw_767645 *lpPrimHeadReserve;
    unsigned int Pad0[3];
};



/* SetSdlData @ 0x168D20 .. 0x168D78 (0x58 bytes, frame 0x20) */

extern u32 RemapVmdData();
extern void SetSmdData();
extern u32 MdlData[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetSdlData(s32 a0 , u32 *a1 );


void SetSdlData(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u32 v1;
    u32 a2;
    u32 *s0;
    u32 v0;

    a2 = (u32)((u32)a0 << 1) + a0;
    a2 = (u32)a2 << 2;
    a0 = a2 + a0;
    v1 = (u32)MdlData;
    a0 = (u32)a0 << 7;
    s0 = (u32 *)((u8 *)MdlData + a0);
    if ((u32)(a1) != 0) {
        v0 = *(u32 *)(((u8 *)a1 + 0x10));
        *(u32 *)(((u8 *)s0 + 0x1c)) = v0;
        a0 = *(u32 *)(((u8 *)s0 + 0x1c));
        RemapVmdData(a0, a1, a2);
        a0 = (s32)s0;
        SetSmdData(a0);
    }
    return;
}
void SetSmdData(struct dw_752027 *lpMdlData) {
    unsigned int i;
    unsigned int *lpCurDMA;
    struct dw_744853 *lpSmdHead;
    struct dw_748108 *lpSmdObj;
    struct dw_745927 *lpPrimHead;

    lpSmdHead = (struct dw_744853 *)lpMdlData->lpSmdHead;
    lpCurDMA = lpMdlData->lpCurrent;
    lpSmdObj = lpSmdHead->lpObject;
    for (i = 0; i < lpSmdHead->ObjectNum; i++) {
        lpSmdObj->lpObjParam = (struct dw_751233 *)lpCurDMA;
        lpPrimHead = lpSmdObj->lpPrimHead;
        while (lpPrimHead != 0) {
            lpCurDMA = MakePresetPrimListPacket(lpCurDMA, lpPrimHead);
            lpPrimHead = lpPrimHead->lpNext;
        }
        lpCurDMA[0] = 0x60000000;
        lpCurDMA[1] = 0;
        lpCurDMA[2] = 0;
        lpCurDMA[3] = 0;
        lpCurDMA += 4;
        lpSmdObj++;
    }
    lpMdlData->lpCurrent = lpCurDMA;
}

/* MakePresetPrimListPacket @ 0x168B70 .. 0x168C60 (0xf0 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */

static unsigned int * MakePresetPrimListPacket(unsigned int *a0 /* r4 */, void *a1 /* r5 */) {
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
    v0 = 0x10220000;
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
    *(u32 *)(((u8 *)a0 + 0x34)) = 0x10220000 | 0x4000;
    *(u32 *)(((u8 *)a0 + 0x38)) = 4;
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
