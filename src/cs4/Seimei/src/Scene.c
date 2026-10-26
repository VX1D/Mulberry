#include "common.h"
extern u32 lpSceneLoad;
extern u16 LoadCamReserve;
extern u32 GetMapFileBuf(void);
extern u32 GetGameCamInfo(void);
extern void RemapBinderFile(void *);
extern unsigned char ** GetMapTexListBuf(signed int);
extern unsigned int GetBindOffsetByIndex(void *, unsigned short);
extern void AfterFileReadFunc(unsigned char *, signed int, signed int, signed int);
extern void RemapMapFile(void *);
static void SetMapMdlFile(void *);
extern u32 lpSceneFile;
extern void FreeMapData(signed int);
extern void FreeGameCamData(signed int);
extern void MemFree();
extern u32 FreeScript(void);
extern u32 FreeAllMyEquip(void);
extern void SFX_DeleteAll(signed int);
extern u32 FECard_CancelVannishAll(void);
extern u32 FreeAllMyEquipSound(void);
extern u32 SND_SecRemoveMap(void);
extern u8 GameSt[];
extern void *memset();
void ClearLoadMovieId();
unsigned char GetLoadMovieId();
u32 SetLoadMovieId(u8 a0 /* r4 */);
void SetLoadCamReserve(u8 **a0 /* r4 */);
void SetSceneBndFile(void);
void FreeSceneData(void);
u16 GetCamIdAfterLoad(void);
u_int CheckSceneLoad(void);
u32 SetSceneLoad(s32 a0 /* r4 */, u8 *a1 /* r5 */);
u32 InitSceneLoadFlag(void);
u32 InitSceneLoad(void);

/* InitSceneLoad @ 0x168B40 .. 0x168B70 (0x30 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u32 InitSceneLoad(void) {
    u32 a0;
    u16 *v1;

    a0 = lpSceneLoad;
    memset(a0, 0, 8);
    v1 = (u16 *)lpSceneLoad;
    a0 = 0xffff;
    *(u16 *)(((u8 *)v1 + 4)) = 0xffff;
    return;
}

/* InitSceneLoadFlag @ 0x168B30 .. 0x168B3C (0xc bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u32 InitSceneLoadFlag(void) {
    u8 *v1;

    v1 = (u8 *)lpSceneLoad;
    *(u8 *)v1 = 0;
    return;
}





/* SetSceneLoad @ 0x168AE0 .. 0x168B30 (0x50 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u32 SetSceneLoad(s32 a0 /* r4 */, u8 *a1 /* r5 */) {
    u32 v1;

    v1 = lpSceneLoad;
    *(u8 *)v1 = 1;
    v1 = lpSceneLoad;
    *(u16 *)((v1 + 4)) = a0;
    v1 = lpSceneLoad;
    *(u16 *)((v1 + 6)) = (u16)a1;
    v1 = *(u8 *)((u8 *)&GameSt + 0x1d);
    if (v1 == 0) {
        a1 = (u8 *)LoadCamReserve;
        a0 = 0xffff;
        if ((u32)(a1) != a0) {
            v1 = lpSceneLoad;
            *(u16 *)((v1 + 6)) = (u16)a1;
            LoadCamReserve = a0;
        }
    }
    return;
}




/* CheckSceneLoad @ 0x168AD0 .. 0x168AE0 (0x10 bytes) */
/*
 * dcomp notes:
 *   return: sltu at 0x168adc computes the return value
 *   repo declaration vs inferred signature: return u_int vs inferred u32
 */


u_int CheckSceneLoad(void) {
    u32 v0;

    v0 = lpSceneLoad;
    v0 = *(u8 *)v0;
    return (u32)v0 != 0;
}

/* GetCamIdAfterLoad @ 0x168AC0 .. 0x168ACC (0xc bytes) */
/*
 * dcomp notes:
 *   return: lhu at 0x168ac8 computes the return value
 */


u16 GetCamIdAfterLoad(void) {
    u16 *v0;

    v0 = (u16 *)lpSceneLoad;
    return *(u16 *)(((u8 *)v0 + 6));
}














/* LoadSceneData @ 0x168810 .. 0x168AB4 (0x2a4 bytes, frame 0xb0) */
/*
 * dcomp notes:
 *   literal: @1294 is the string 'map\\s%04d.bnd'
 *   literal: @1295 is the string 'script\\s%04d_%d.scb'
 *   stack: address of the slot at 0x30 escapes at 0x16883c
 *   stack: address of the slot at 0x30 escapes at 0x168850
 *   stack: address of the slot at 0x30 escapes at 0x168870
 *   stack: address of the slot at 0x30 escapes at 0x168880
 *   stack: address of the slot at 0x30 escapes at 0x168898
 *   stack: address of the slot at 0x30 escapes at 0x1688a0
 *   delay: addiu at 0x168934 writes a register its branch at 0x168930 reads
 *   delay: addiu at 0x168a58 writes a register its branch at 0x168a54 reads
 *   cfg: kept branch: 0x1688d4 if (..) goto .L001688F8
 *   cfg: kept branch: 0x168904 if (..) goto .L00168928
 *   cfg: kept branch: 0x168934 if (..) goto .L00168968
 *   cfg: kept branch: 0x168940 if (..) goto .L00168968
 *   cfg: kept branch: 0x168974 if (..) goto .L00168998
 *   cfg: kept branch: 0x1689c4 if (..) goto .L001689E8
 *   cfg: kept branch: 0x1689f4 if (..) goto .L00168A18
 *   cfg: kept branch: 0x168a24 if (..) goto .L00168A48
 *   cfg: kept branch: 0x168a60 if (..) goto .L00168A88
 */

extern void InitSaveEvent(void);
extern int sprintf(void *, void *, ...);
extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);
extern signed int InitScript(unsigned char *);
extern void SetAllMyEquip(void);
extern signed int SND_SecLoadMap(signed int);
extern void ReadAllMyEquipSound(void);
extern signed int CheckEventFlag(signed int);
extern void ReadDramaData(signed int, signed int, signed int);

void LoadSceneData(signed int a0 /* r4 */, signed int a1 /* r5 */) {
    s32 s0;
    s32 s1;
    u32 a2;
    u32 v1;
    u32 v0;
    signed int a0_2;
    signed int a1_2;
    u8 stackFrame_30[128] __attribute__((aligned(16)));

    s1 = a1;
    s0 = a0;
    GameSt[5] = 0;
    InitSaveEvent();
    a2 = 0x80;
    memset(((u8 *)&stackFrame_30[0]), 0, a2);
    a1_2 = (signed int)"map\\s%04d.bnd";
    a2 = s0;
    sprintf((void *)((u8 *)&stackFrame_30[0]), (void *)"map\\s%04d.bnd", a2);
    a1_2 = -1;
    a2 = (u32)&lpSceneFile;
    FileRead((char *)((u8 *)&stackFrame_30[0]), a1_2, (unsigned char **)&lpSceneFile, 0, a1_2,
        0x19, 0);
    a2 = 0x80;
    memset(((u8 *)&stackFrame_30[0]), 0, a2);
    a1_2 = (signed int)"script\\s%04d_%d.scb";
    a2 = s0;
    sprintf((void *)((u8 *)&stackFrame_30[0]), (void *)"script\\s%04d_%d.scb", a2, s1);
    InitScript((unsigned char *)((u8 *)&stackFrame_30[0]));
    SetAllMyEquip();
    FreeAllMyEquipSound();
    a0_2 = s0;
    SND_SecLoadMap(a0_2);
    ReadAllMyEquipSound();
    v1 = 9;
    a0_2 = 0x45f;
    if ((u32)s0 == v1) {
        v0 = CheckEventFlag(a0_2);
        a0_2 = 9;
        if (v0 != 0) {
            goto _L001688F8;
        }
        ReadDramaData(a0_2, 0, 0);
    } else {
        _L001688F8:;
        v1 = 0x17;
        a0_2 = 0xd8;
        if ((u32)s0 == v1) {
            v0 = CheckEventFlag(a0_2);
            a0_2 = 0x17;
            if (v0 != 0) {
                goto _L00168928;
            }
            a1_2 = 3;
            ReadDramaData(a0_2, a1_2, 0);
        } else {
            _L00168928:;
            v1 = GameSt[0x14];
            if (v1 == 0) {
                v1 = 0x21;
                a0_2 = 0x440;
                if ((u32)s0 != v1) {
                    goto _L00168968;
                }
                v0 = CheckEventFlag(a0_2);
                a0_2 = 0x21;
                if (v0 != 0) {
                    goto _L00168968;
                }
                ReadDramaData(a0_2, 0, 0);
            } else {
                _L00168968:;
                v1 = 0x24;
                a0_2 = 0x3ef;
                if ((u32)s0 == v1) {
                    v0 = CheckEventFlag(a0_2);
                    a0_2 = 0x24;
                    if (v0 != 0) {
                        goto _L00168998;
                    }
                    ReadDramaData(a0_2, 0, 0);
                } else {
                    _L00168998:;
                    a0_2 = 0x25;
                    a1_2 = 7;
                    if ((u32)s0 == (u32)(s32)a0_2) {
                        ReadDramaData(a0_2, a1_2, 0);
                    } else {
                        v1 = 0x47;
                        a0_2 = 0x110;
                        if ((u32)s0 == v1) {
                            v0 = CheckEventFlag(a0_2);
                            a0_2 = 0x47;
                            if (v0 == 0) {
                                goto _L001689E8;
                            }
                            a1_2 = 1;
                            ReadDramaData(a0_2, a1_2, 0);
                        } else {
                            _L001689E8:;
                            v1 = 0x4e;
                            a0_2 = 0x144;
                            if ((u32)s0 == v1) {
                                v0 = CheckEventFlag(a0_2);
                                a0_2 = 0x4e;
                                if (v0 != 0) {
                                    goto _L00168A18;
                                }
                                ReadDramaData(a0_2, 0, 0);
                            } else {
                                _L00168A18:;
                                v1 = 0x52;
                                a0_2 = 0x143;
                                if ((u32)s0 == v1) {
                                    v0 = CheckEventFlag(a0_2);
                                    a0_2 = 0x52;
                                    if (v0 != 0) {
                                        goto _L00168A48;
                                    }
                                    ReadDramaData(a0_2, 0, 0);
                                } else {
                                    _L00168A48:;
                                    a0_2 = GameSt[0x14];
                                    v1 = 2;
                                    v1 = 0x57;
                                    if ((u32)a0_2 == 2 && (u32)s0 == v1) {
                                        a0_2 = 0x1e4;
                                        v0 = CheckEventFlag(a0_2);
                                        a0_2 = 0x57;
                                        if (v0 != 0) {
                                        goto _L00168A88;
                                        }
                                        a1_2 = 2;
                                        ReadDramaData(a0_2, a1_2, 0);
                                    } else {
                                        _L00168A88:;
                                        a0_2 = 0x5a;
                                        a1_2 = 0;
                                        if ((u32)s0 == (u32)(s32)a0_2) {
                                        ReadDramaData(a0_2, 0, 0);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}















/* FreeSceneData @ 0x1687A0 .. 0x16880C (0x6c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   repo declaration vs inferred signature: return void vs inferred u8 *
 */


void FreeSceneData(void) {
    u16 *v1;
    u32 a0;

    FreeMapData(0);
    FreeGameCamData(0);
    a0 = lpSceneFile;
    MemFree(a0);
    FreeScript();
    FreeAllMyEquip();
    SFX_DeleteAll(1);
    FECard_CancelVannishAll();
    FreeAllMyEquipSound();
    SND_SecRemoveMap();
    v1 = (u16 *)lpSceneLoad;
    v1 = (u16 *)*(u16 *)(((u8 *)v1 + 4));
    *(u8 *)((u8 *)&GameSt + 9) = (u8)v1;
    return;
}

/* SetSceneBndFile @ 0x1686A0 .. 0x1687A0 (0x100 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001686D8
 */


void SetSceneBndFile(void) {
    u32 a0;
    u32 *s3;
    u32 v0;
    u32 *s2;
    u32 *s1;
    u32 s0;

    v0 = GetMapFileBuf();
    s2 = (u32 *)v0;
    v0 = GetGameCamInfo();
    a0 = lpSceneFile;
    s1 = (u32 *)v0;
    RemapBinderFile((void *)a0);
    s0 = 0;
    do {
        v0 = (u32)GetMapTexListBuf(s0);
        a0 = lpSceneFile;
        s3 = (u32 *)v0;
        v0 = GetBindOffsetByIndex((void *)a0, s0 + 2);
        *(u32 *)s3 = v0;
        a0 = *(s32 *)s3;
        if (a0 != 0) {
            if ((s32)s0 < (s32)3) {
                AfterFileReadFunc((unsigned char *)a0, s0, 8, 0);
            } else {
                AfterFileReadFunc((unsigned char *)a0, s0, 6, 0);
            }
        }
        s0 = s0 + 1;
        v0 = (s32)s0 < (s32)4;
    } while (v0 != 0);
    a0 = lpSceneFile;
    v0 = GetBindOffsetByIndex((void *)a0, 1);
    *(u32 *)s2 = v0;
    a0 = *(s32 *)s2;
    RemapMapFile((void *)a0);
    a0 = *(s32 *)s2;
    SetMapMdlFile((void *)a0);
    a0 = lpSceneFile;
    v0 = GetBindOffsetByIndex((void *)a0, 0);
    *(u32 *)s1 = v0;
    a0 = *(s32 *)s1;
    AfterFileReadFunc((unsigned char *)a0, 0, 1, 0);
    return;
}







/* SetMapMdlFile @ 0x1683B0 .. 0x1686A0 (0x2f0 bytes, frame 0xe0) */
/*
 * dcomp notes:
 *   literal: @1162 is the string '.bnd'
 *   stack: address of the slot at 0x60 escapes at 0x1683f8
 *   stack: address of the slot at 0x60 escapes at 0x168420
 *   stack: address of the slot at 0x60 escapes at 0x1684a0
 *   stack: address of the slot at 0x60 escapes at 0x1684c8
 *   stack: address of the slot at 0x60 escapes at 0x168550
 *   stack: address of the slot at 0x60 escapes at 0x168578
 *   stack: address of the slot at 0x60 escapes at 0x1685f8
 *   stack: address of the slot at 0x60 escapes at 0x168620
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void * GetMdlInfoStart(signed int);
extern void StringCorrectPath4Disc(char *, signed int);
extern char * SearchFileName(char *);
extern void ChangeExtension(void *, char *, char *);
extern unsigned int GetBindOffsetByName(void *, char *);
extern u32 MdlData[];

#ifndef PROTO_DW_736925
#define PROTO_DW_736925
struct dw_736925 {
    unsigned short MapMdlNum;
    unsigned short ObjMdlNum;
    unsigned short EneMdlNum;
    unsigned short PathMdlNum;
    unsigned short SfxMdlNum;
    unsigned short EventMdlNum;
    unsigned short SeMdlNum;
    unsigned short ItemMdlNum;
    unsigned short MapNum;
    unsigned short ObjNum;
    unsigned short EneNum;
    unsigned short PathNum;
    unsigned short SfxNum;
    unsigned short EventNum;
    unsigned short SeNum;
    unsigned short ItemNum;
    unsigned int MapMdlInfo;
    unsigned int ObjMdlInfo;
    unsigned int EneMdlInfo;
    unsigned int PathMdlInfo;
    unsigned int SfxMdlInfo;
    unsigned int EventMdlInfo;
    unsigned int SeMdlInfo;
    unsigned int ItemMdlInfo;
    unsigned int MapData;
    unsigned int ObjData;
    unsigned int EneData;
    unsigned int PathData;
    unsigned int SfxData;
    unsigned int EventData;
    unsigned int SeData;
    unsigned int ItemData;
    unsigned int MapObjectData;
    unsigned int ObjObjectData;
    unsigned int EneObjectData;
    unsigned int PathObjectData;
    unsigned int SfxObjectData;
    unsigned int EvtObjectData;
    unsigned int SeObjectData;
    unsigned int ItemObjectData;
};
#endif
#ifndef PROTO_DW_739960
#define PROTO_DW_739960
struct dw_739960 {
    float Pos[4];
    float Nrm[4];
    short ObjectId;
    unsigned char Type;
    unsigned char Id;
    unsigned int unused[3];
};
#endif
#ifndef PROTO_DW_738525
#define PROTO_DW_738525
struct dw_738525 {
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
    struct dw_739960 DmyPoly[32];
};
#endif

static void SetMapMdlFile(void *a0 /* r4 */) {
    struct dw_736925 *s0;
    u32 a2;
    struct dw_734335 *s3;
    struct dw_738525 *s4;
    u32 s2;
    u32 v1;
    u32 v0;
    s32 s1;
    void *a0_2;
    u8 stackFrame_60[128] __attribute__((aligned(16)));

    s0 = (struct dw_736925 *)a0;
    v0 = (u32)GetMdlInfoStart(0);
    s3 = (struct dw_734335 *)v0;
    v0 = s0->MapMdlNum;
    s2 = 0;
    if (0 < (s32)v0) {
        s1 = 0;
        do {
            memset(((u8 *)&stackFrame_60[0]), 0, (u32)0x80);
            StringCorrectPath4Disc((char *)s3, 0);
            v0 = (u32)SearchFileName((char *)s3);
            a2 = (u32)".bnd";
            ChangeExtension((void *)((u8 *)&stackFrame_60[0]), (char *)v0, ".bnd");
            a0_2 = (void *)lpSceneFile;
            v0 = (u32)MdlData;
            s4 = (struct dw_738525 *)((u8 *)MdlData + (u32)((u32)(s1 + 0x7fff) + 0x3601));
            v0 = GetBindOffsetByName(a0_2, (char *)((u8 *)&stackFrame_60[0]));
            s4->lpBndFile = (void *)(v0);
            AfterFileReadFunc((unsigned char *)(s32)s4->lpBndFile, s2 + 0x1c, 0, 0);
            v0 = s0->MapMdlNum;
            s2 = s2 + 1;
            s1 = s1 + 0x680;
            v0 = (s32)s2 < (s32)v0;
            s3 = (struct dw_734335 *)(s32)((u32)s3 + 0x20);
        } while (v0 != 0);
    }
    v0 = (u32)GetMdlInfoStart(1);
    s2 = v0;
    v0 = s0->ObjMdlNum;
    s1 = 0;
    if (0 < (s32)v0) {
        s3 = (struct dw_734335 *)0;
        do {
            memset(((u8 *)&stackFrame_60[0]), 0, (u32)0x80);
            StringCorrectPath4Disc((char *)s2, 0);
            v0 = (u32)SearchFileName((char *)s2);
            a2 = (u32)".bnd";
            ChangeExtension((void *)((u8 *)&stackFrame_60[0]), (char *)v0, ".bnd");
            a0_2 = (void *)lpSceneFile;
            v1 = 0x1ee00;
            v0 = (u32)MdlData;
            s4 = (struct dw_738525 *)((u8 *)MdlData + (u32)((u32)s3 + 0x1ee00));
            v0 = GetBindOffsetByName(a0_2, (char *)((u8 *)&stackFrame_60[0]));
            s4->lpBndFile = (void *)(v0);
            AfterFileReadFunc((unsigned char *)(s32)s4->lpBndFile, s1 + 0x4c, 0, 0);
            v0 = s0->ObjMdlNum;
            s1 = s1 + 1;
            s3 = (struct dw_734335 *)(s32)((u32)s3 + 0x680);
            v0 = s1 < (s32)v0;
            s2 = s2 + 0x20;
        } while (v0 != 0);
    }
    v0 = (u32)GetMdlInfoStart(2);
    s2 = v0;
    v0 = s0->EneMdlNum;
    s1 = 0;
    if (0 < (s32)v0) {
        s3 = (struct dw_734335 *)0;
        do {
            memset(((u8 *)&stackFrame_60[0]), 0, (u32)0x80);
            StringCorrectPath4Disc((char *)s2, 0);
            v0 = (u32)SearchFileName((char *)s2);
            a2 = (u32)".bnd";
            ChangeExtension((void *)((u8 *)&stackFrame_60[0]), (char *)v0, ".bnd");
            a0_2 = (void *)lpSceneFile;
            v0 = (u32)MdlData;
            s4 = (struct dw_738525 *)((u8 *)MdlData + (u32)((u32)s3 + 0x1a00));
            v0 = GetBindOffsetByName(a0_2, (char *)((u8 *)&stackFrame_60[0]));
            s4->lpBndFile = (void *)(v0);
            AfterFileReadFunc((unsigned char *)(s32)s4->lpBndFile, s1 + 4, 0, 0);
            v0 = s0->EneMdlNum;
            s1 = s1 + 1;
            s3 = (struct dw_734335 *)(s32)((u32)s3 + 0x680);
            v0 = s1 < (s32)v0;
            s2 = s2 + 0x20;
        } while (v0 != 0);
    }
    v0 = (u32)GetMdlInfoStart(7);
    v1 = s0->ItemMdlNum;
    s2 = v0;
    s1 = 0;
    if (0 < (s32)v1) {
        s3 = (struct dw_734335 *)0;
        do {
            memset(((u8 *)&stackFrame_60[0]), 0, (u32)0x80);
            StringCorrectPath4Disc((char *)s2, 0);
            v0 = (u32)SearchFileName((char *)s2);
            a2 = (u32)".bnd";
            ChangeExtension((void *)((u8 *)&stackFrame_60[0]), (char *)v0, ".bnd");
            a0_2 = (void *)lpSceneFile;
            v1 = 0x75000;
            v0 = (u32)MdlData;
            s4 = (struct dw_738525 *)((u8 *)MdlData + (u32)((u32)s3 + 0x75000));
            v0 = GetBindOffsetByName(a0_2, (char *)((u8 *)&stackFrame_60[0]));
            s4->lpBndFile = (void *)(v0);
            AfterFileReadFunc((unsigned char *)(s32)s4->lpBndFile, s1 + 0x120, 0, 0);
            v1 = s0->ItemMdlNum;
            s1 = s1 + 1;
            s3 = (struct dw_734335 *)(s32)((u32)s3 + 0x680);
            v1 = s1 < (s32)v1;
            s2 = s2 + 0x20;
        } while (v1 != 0);
    }
    return;
}




/* SetLoadCamReserve @ 0x1683A0 .. 0x1683A8 (0x8 bytes) */


void SetLoadCamReserve(u8 **a0 /* r4 */) {
    LoadCamReserve = (u16)a0;
    return;
}







/* SetLoadMovieId @ 0x168380 .. 0x168394 (0x14 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u32 SetLoadMovieId(u8 a0 /* r4 */) {
    u32 v1;

    v1 = (u8)a0;
    a0 = v1 + 1;
    v1 = lpSceneLoad;
    *(u8 *)((v1 + 1)) = a0;
    return;
}





/* GetLoadMovieId @ 0x168370 .. 0x16837C (0xc bytes) */
/*
 * dcomp notes:
 *   return: lbu at 0x168378 computes the return value
 *   declaration vs inferred signature: return unsigned char vs inferred u8
 */

unsigned char GetLoadMovieId(void) {
    u8 *v0;

    v0 = (u8 *)lpSceneLoad;
    return *(u8 *)(v0 + 1);
}






/* ClearLoadMovieId @ 0x168360 .. 0x16836C (0xc bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

void ClearLoadMovieId(void) {
    u8 *v1;

    v1 = (u8 *)lpSceneLoad;
    *(u8 *)(v1 + 1) = 0;
    return;
}extern u32 SceneLoad[];
u32 lpSceneLoad = (u32)&SceneLoad;
static u16 LoadCamReserve = 0xffff;
static u32 SceneLoad[0x2];
u32 lpSceneFile;
