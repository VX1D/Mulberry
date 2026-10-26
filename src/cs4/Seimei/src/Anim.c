#include "common.h"

/* ReCalcMi3Matrix @ 0x12E9A0 .. 0x12EB44 (0x1a4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x12ea10
 *   fpu: mtc1 reinterprets v0 at 0x12ea44
 *   fpu: mtc1 reinterprets v1 at 0x12ea58
 *   fpu: mov.s at 0x12ea9c is a float copy
 *   fpu: mov.s at 0x12eaa4 is a float copy
 *   fpu: mov.s at 0x12eab0 is a float copy
 *   fpu: mov.s at 0x12eab8 is a float copy
 *   fpu: mov.s at 0x12eac4 is a float copy
 *   fpu: mov.s at 0x12eacc is a float copy
 *   fpu: mov.s at 0x12ead0 is a float copy
 *   fpu: mov.s at 0x12eae0 is a float copy
 *   fpu: mov.s at 0x12eafc is a float copy
 *   fpu: mov.s at 0x12eb04 is a float copy
 *   cfg: loop body is not one contiguous region: .L0012E9E0
 *   cfg: loop body is not one contiguous region: .L0012EA38
 *   declaration vs inferred signature: return void vs inferred u32
 */

static void GetMasterAnimPosFrameData(void *, void *, float, float);
static void GetMasterAnimAngFrameData(void *, void *, float, float);
static void GetAnimSclFrameData(void *, void *, float, float);
static void UpdateAnimLocalMatrix(void *);
static void CalcMi3ObjectMatrix(void *a0 /* r4 */, float f12 /* f12 */, float f13 /* f13 */);

/* UpdateWorldMatrixInAnim @ 0x12EB50 .. 0x12EEE4 (0x394 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x40 escapes at 0x12eb88
 *   fpu: float literal 0x40490fdb at 0x12eba4
 *   fpu: float literal 0x00000000 at 0x12eba8
 *   fpu: float literal 0x40c90fdb at 0x12ebc8
 *   fpu: mtc1 reinterprets v0 at 0x12ebec
 *   fpu: float literal 0x40490fdb at 0x12ec18
 *   fpu: float literal 0x00000000 at 0x12ec1c
 *   fpu: float literal 0x40c90fdb at 0x12ec3c
 *   fpu: mtc1 reinterprets v0 at 0x12ec60
 *   fpu: float literal 0x40490fdb at 0x12ec8c
 *   fpu: float literal 0x00000000 at 0x12ec90
 *   fpu: float literal 0x40c90fdb at 0x12ecb0
 *   fpu: mtc1 reinterprets v0 at 0x12ecd4
 *   fpu: mov.s at 0x12ecf8 is a float copy
 *   fpu: mov.s at 0x12ecfc is a float copy
 *   fpu: mov.s at 0x12ed04 is a float copy
 *   fpu: mov.s at 0x12ed08 is a float copy
 *   fpu: mov.s at 0x12ed10 is a float copy
 *   fpu: mov.s at 0x12ed14 is a float copy
 *   fpu: mov.s at 0x12ed1c is a float copy
 *   fpu: mov.s at 0x12ed20 is a float copy
 *   fpu: mov.s at 0x12ed28 is a float copy
 *   fpu: mov.s at 0x12ed2c is a float copy
 *   fpu: mov.s at 0x12ed34 is a float copy
 *   delay: lui at 0x12ee2c writes a register its branch at 0x12ee28 reads
 *   stack: address of the slot at 0x40 escapes at 0x12ee5c
 *   delay: lui at 0x12ee80 writes a register its branch at 0x12ee7c reads
 *   stack: address of the slot at 0x40 escapes at 0x12eeb8
 */

extern void sceVu0CopyMatrix(void *, void *);
extern void UpdateWorldMatrixNoAnim(void *, void *);
extern void UpdateWorldMatrixWithAnim(void *, void *, void *);
extern u32 MdlMng[];

struct dw_12032_fields;
struct dw_24837_fields;
#ifndef PROTO_DW_24196_FIELDS
#define PROTO_DW_24196_FIELDS
struct dw_24196_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_21391_FIELDS
#define PROTO_DW_21391_FIELDS
struct dw_21391_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_20666_FIELDS
#define PROTO_DW_20666_FIELDS
struct dw_20666_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_12032_fields *lpMdl; };
#endif
#ifndef PROTO_DW_12032_FIELDS
#define PROTO_DW_12032_FIELDS
struct dw_12032_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_24837_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_12032_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_24196_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_21391_fields flags; unsigned char _pad1[3]; struct dw_20666_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_26289_FIELDS
#define PROTO_DW_26289_FIELDS
struct dw_26289_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_24837_FIELDS
#define PROTO_DW_24837_FIELDS
struct dw_24837_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_26289_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_ANG_0__87C1E16F_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_ANG_0__87C1E16F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_ANG_0__87C1E16F = (int)&(((struct dw_12032_fields *)0)->Ang[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_ANG_1__E34766EE_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_ANG_1__E34766EE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_ANG_1__E34766EE = (int)&(((struct dw_12032_fields *)0)->Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_ANG_2__5D4C459F_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_ANG_2__5D4C459F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_ANG_2__5D4C459F = (int)&(((struct dw_12032_fields *)0)->Ang[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_POS_0__88207ABB_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_POS_0__88207ABB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_POS_0__88207ABB = (int)&(((struct dw_12032_fields *)0)->Pos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_POS_1__974F562E_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_POS_1__974F562E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_POS_1__974F562E = (int)&(((struct dw_12032_fields *)0)->Pos[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_POS_2__A20A9870_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_POS_2__A20A9870_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_POS_2__A20A9870 = (int)&(((struct dw_12032_fields *)0)->Pos[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_0__D89815CC_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_0__D89815CC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_0__D89815CC = (int)&(((struct dw_12032_fields *)0)->Scl[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_1__69973D0D_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_1__69973D0D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_1__69973D0D = (int)&(((struct dw_12032_fields *)0)->Scl[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_2__D75B64C6_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_2__D75B64C6_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_2__D75B64C6 = (int)&(((struct dw_12032_fields *)0)->Scl[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_BPRESETMATRIX_8658849A_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_BPRESETMATRIX_8658849A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_BPRESETMATRIX_8658849A = (int)&(((struct dw_12032_fields *)0)->bPresetMatrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_BUSEWORLDMAT_995CBA5F_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_BUSEWORLDMAT_995CBA5F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_BUSEWORLDMAT_995CBA5F = (int)&(((struct dw_12032_fields *)0)->bUseWorldMat) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPANIMCTRL_9E538C48_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPANIMCTRL_9E538C48_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPANIMCTRL_9E538C48 = (int)&(((struct dw_12032_fields *)0)->lpAnimCtrl) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPCTRLST_B101F069_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPCTRLST_B101F069_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPCTRLST_B101F069 = (int)&(((struct dw_12032_fields *)0)->lpCtrlSt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPMDLDATA_3E85370A_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPMDLDATA_3E85370A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPMDLDATA_3E85370A = (int)&(((struct dw_12032_fields *)0)->lpMdlData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPMI3HEAD_4A417500_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPMI3HEAD_4A417500_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPMI3HEAD_4A417500 = (int)&(((struct dw_12032_fields *)0)->lpMi3Head) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPOBJMAT_0B4DF43D_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPOBJMAT_0B4DF43D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPOBJMAT_0B4DF43D = (int)&(((struct dw_12032_fields *)0)->lpObjMat) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_24837_FIELDS_MDLTYPE_C49D21D1_DEFINED
#define DCOMP_OFF_STRUCT_DW_24837_FIELDS_MDLTYPE_C49D21D1_DEFINED
enum { DCOMP_OFF_STRUCT_DW_24837_FIELDS_MDLTYPE_C49D21D1 = (int)&(((struct dw_24837_fields *)0)->MdlType) - 0 };
#endif

/* SetAnimInitData @ 0x12EFE0 .. 0x12F098 (0xb8 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void *memcpy();

/* SetAnimUserScale @ 0x12F0A0 .. 0x12F0C8 (0x28 bytes) */
/*
 * dcomp notes:
 *   tail: j sceVu0CopyVector at 0x12f0c0 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern void sceVu0CopyVector();

/* SetClothJointFlag @ 0x12F0D0 .. 0x12F164 (0x94 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int CsMngCheckClothJoint(unsigned int, unsigned int);

/* SetMasterInitial @ 0x12F1C0 .. 0x12F248 (0x88 bytes, frame 0x40) */

extern void *memcpy();


/* ChangeAnimParam @ 0x12F3F0 */
typedef struct {
    u16 KeyFrame;
    u16 cap_TFrameNum;
    u32 Index[7];
} CAP_TOD;

typedef struct {
    u16 cap_TodKeyNum;
    u16 cap_MimeKeyNum;
    u16 cap_Tp2Id;
    u16 cap_ObjectId;
    u32 cap_InitAngleIndex;
    u32 cap_InitPositionIndex;
    CAP_TOD *cap_lpTodData;
    void *lpMimeData;
    void *lpChild;
    void *lpSibling;
} CAP_MI3OBJ;

typedef struct {
    u32 DataSize;
    u32 FileId;
    s16 ObjectNum;
    u16 cap_HFlag;
    s32 cap_FrameNum;
} CAP_MI3HEAD;

typedef struct {
    float cap_NumFrame;
    float cap_PrevFrame;
    float cap_StartFrame;
    float cap_EndFrame;
    float cap_MaxFrame;
    float cap_HokanFrame;
    int cap_ObjId;
    float cap_AnimSpeed;
    u32 cap_ObjGroup;
    u32 cap_Flag;
    u8 cap_Loop;
    u8 cap_ClothJoint;
    s16 cap_State;
    CAP_MI3HEAD *cap_lpMi3Head;
    CAP_MI3OBJ *cap_lpMi3Obj;
    u32 lpVector;
    CAP_TOD *cap_lpTod;
    u8 pad[0x94];
} CAP_ANIMCTRL;

typedef struct {
    int ID;
    int cap_PLoop;
    u16 pad8;
    s16 Mi3Index;
    u32 cap_ObjGroup;
    float cap_HokanFrame;
    u8 bNoStart;
    float Start;
    u8 bNoEnd;
    float End;
    u8 pad24[0xc];
} CAP_PARAM;

typedef struct {
    int MaxAnimParam;
    u8 pad[0x10];
    void *lpAniHead;
    u8 pad2[0x8];
    u32 *lpMicHead;
    u32 *lpMi3Index;
    u8 pad3[4];
    CAP_PARAM *lpAnimParam;
} CAP_MDLDATA;

typedef struct {
    u8 pad[0xc];
    CAP_MDLDATA *lpMdlData;
    u8 pad1[0xc];
    CAP_MI3HEAD *cap_lpMi3Head;
    u8 pad2[0xe0];
    CAP_ANIMCTRL *lpAnimCtrl;
    s16 IndexAnim;
} CAP_MDLMNG;

static inline CAP_PARAM *CapFind(CAP_MDLDATA *lpMdlData, int AnimDataID) {
    int hi;
    int lo;
    int mid;
    CAP_PARAM *lpParam;

    hi = lpMdlData->MaxAnimParam - 1;
    lpParam = lpMdlData->lpAnimParam;
    hi = (hi < AnimDataID) ? hi : AnimDataID;
    if (hi < 0) {
        return 0;
    }
    if (lpParam[hi].ID == AnimDataID) {
        return &lpParam[hi];
    }
    lo = 0;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (lpParam[mid].ID < AnimDataID) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return (lpParam[lo].ID == AnimDataID) ? &lpParam[lo] : 0;
}

#define CAP_SETFRAME(FRM) \
    { \
    CAP_TOD *cap_lpTod; \
    u32 j; \
    cap_lpTod = lpAnimCtrl->cap_lpMi3Obj->cap_lpTodData; \
    if ((FRM) > lpAnimCtrl->cap_MaxFrame) { \
        lpAnimCtrl->cap_NumFrame = lpAnimCtrl->cap_MaxFrame; \
    } else { \
        lpAnimCtrl->cap_NumFrame = (FRM); \
    } \
    lpAnimCtrl->cap_PrevFrame = lpAnimCtrl->cap_NumFrame - 1.0f; \
    for (j = 0; j < (u32)(lpAnimCtrl->cap_lpMi3Obj->cap_TodKeyNum - 1); j++, cap_lpTod++) { \
        if ((FRM) <= (float)(u32)cap_lpTod[1].KeyFrame) { \
            break; \
        } \
    } \
    lpAnimCtrl->cap_lpTod = cap_lpTod; \
    }


/* MasterMoveCalc @ 0x12F7D0 .. 0x12FAE4 (0x314 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x12f800 is a float copy
 *   fpu: mov.s at 0x12f804 is a float copy
 *   fpu: mov.s at 0x12f810 is a float copy
 *   fpu: mov.s at 0x12f818 is a float copy
 *   fpu: mov.s at 0x12f81c is a float copy
 *   fpu: mov.s at 0x12f824 is a float copy
 *   fpu: float literal 0x40490fdb at 0x12f840
 *   fpu: float literal 0x00000000 at 0x12f844
 *   fpu: float literal 0x40c90fdb at 0x12f88c
 *   fpu: mtc1 reinterprets v1 at 0x12f8b0
 *   fpu: float literal 0x40490fdb at 0x12f8e0
 *   fpu: float literal 0x00000000 at 0x12f8e4
 *   fpu: float literal 0x40c90fdb at 0x12f904
 *   fpu: mtc1 reinterprets v1 at 0x12f928
 *   fpu: float literal 0x40490fdb at 0x12f958
 *   fpu: float literal 0x00000000 at 0x12f95c
 *   fpu: float literal 0x40c90fdb at 0x12f97c
 *   fpu: mtc1 reinterprets v1 at 0x12f9a0
 *   declaration vs inferred signature: return void vs inferred float
 */

#define PI 3.14159274f
#define PI2 6.28318548f
#define ADJ(a) (((a) + PI >= 0.0f) ? ((a) - PI2 * (float)(s32)(((a) + PI) / PI2)) : (PI2 + ((a) - PI2 * (float)(s32)(((a) + PI) / PI2))))


/* MasterMove @ 0x12FAF0 .. 0x12FB3C (0x4c bytes, frame 0x10) */

static void MasterMoveCalc(void *);

unsigned int AddAnimFrame(struct dw_5842 *, float);


/* CalcMi3ObjectMatrix @ 0x12FC70 .. 0x12FCE8 (0x78 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x12fc8c is a float copy
 *   fpu: mov.s at 0x12fc94 is a float copy
 *   fpu: mov.s at 0x12fca8 is a float copy
 *   fpu: mov.s at 0x12fcb0 is a float copy
 *   fpu: mov.s at 0x12fcb4 is a float copy
 *   fpu: mov.s at 0x12fcbc is a float copy
 */

static void GetAnimPosFrameData(void *, void *, float, float);
static void GetAnimAngFrameData(void *, void *, float, float);
static void GetAnimSclFrameData(void *, void *, float, float);
static void UpdateAnimLocalMatrix(void *);

/* PlayMi3 @ 0x12FCF0 .. 0x12FED4 (0x1e4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x12fd1c writes a register its branch at 0x12fd18 reads
 *   delay: addiu at 0x12fd30 writes a register its branch at 0x12fd2c reads
 *   delay: daddu at 0x12fd88 writes a register its branch at 0x12fd84 reads
 *   cfg: kept branch: 0x12fd50 if (..) goto .L0012FDB0
 *   cfg: kept branch: 0x12fd78 if (..) goto .L0012FDB0
 *   cfg: kept branch: 0x12fd8c if (..) goto .L0012FEC0
 *   cfg: kept branch: 0x12fd9c if (..) goto .L0012FEC0
 *   cfg: kept branch: 0x12fdb0 if (..) goto .L0012FDD8
 *   cfg: kept branch: 0x12fdd8 if (..) goto .L0012FEC0
 *   cfg: kept branch: 0x12fde8 if (..) goto .L0012FEC0
 *   cfg: kept branch: 0x12fdf8 if (..) goto .L0012FE28
 *   cfg: kept branch: 0x12fe00 if (..) goto .L0012FE28
 *   cfg: kept branch: 0x12fe14 if (..) goto .L0012FEC0
 *   cfg: kept branch: 0x12fe48 if (..) goto .L0012FE78
 *   cfg: kept goto: 0x12fe58 -> .L0012FEA8
 */

extern unsigned int CheckDrawModel(void *);
extern signed int CheckEneStop(void *);
extern signed int KnMsgMng_CheckMsgNone(void);
extern void PlayNoAnim(void *);
extern signed int Menu_TD_IsPlay(void);
extern void CalcMasterMoveMi3Matrix(void *);
extern void UpdateWorldMatrixInAnim(void *);
extern signed int CsMngRtaSetMat(unsigned int, void *, int);
extern signed int CsMngRtaUpdate(unsigned int);
extern void DssPlay(void *);
extern u8 GameSt[];
extern u32 MRX1[];


extern void AnimCurve(float *, float *, float *, float *, float *, float);


extern void AnimCurve(float *, float *, float *, float *, float *, float);


struct dw_6867 {
    unsigned short KeyFrame;
    unsigned short FrameNum;
    unsigned int PositionIndex;
    unsigned int PosInTanIndex;
    unsigned int PosOutTanIndex;
    unsigned int AngleIndex;
    unsigned int AngInTanIndex;
    unsigned int AngOutTanIndex;
    unsigned int ScaleIndex;
};

struct dw_8571 {
    unsigned short TodKeyNum;
    unsigned short MimeKeyNum;
    unsigned short Tp2Id;
    unsigned short ObjectId;
    unsigned int InitAngleIndex;
    unsigned int InitPositionIndex;
    struct dw_6867 *lpTodData;
};

struct dw_5842 {
    float NumFrame;
    float PrevFrame;
    float StartFrame;
    float EndFrame;
    float MaxFrame;
    float HokanFrame;
    int ObjId;
    float AnimSpeed;
    unsigned int ObjGroup;
    unsigned int Flag;
    unsigned char Loop;
    unsigned char ClothJoint;
    short State;
    void *lpMi3Head;
    struct dw_8571 *lpMi3Obj;
    float (*lpVector)[3];
    struct dw_6867 *lpTod;
};

extern void * MemAllocReal(unsigned int, char *, char *);
extern void * memset(void *, int, unsigned int);
extern void sceVu0RotMatrixX(void *, void *, float);
extern void sceVu0RotMatrixZ(void *, void *, float);
extern void sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0TransMatrix(void *, void *, void *);
static u32 MorphTargetMng[0x2] __attribute__((aligned(64)));
extern u32 MRX1[];
static float HokanLinear(float, float);
static void GetAnimFrameData(s32, void *, float *, void *);

struct IACMorph { s16 iaNum; s16 iaList[3]; };
#define IAC_MT ((struct IACMorph *)MorphTargetMng)
#define IAC_WrapAng(x) ((3.1415927f + (x)) >= 0.0f ? ((x) - (6.2831855f * (float)(s32)((3.1415927f + (x)) / 6.2831855f))) : (6.2831855f + ((x) - (6.2831855f * (float)(s32)((3.1415927f + (x)) / 6.2831855f)))))

struct IACObj { u16 ioTodKeyNum; u16 ioMimeKeyNum; u16 ioTp2Id; u16 ioObjectId; u8 ioPad[8]; void *ioTod; u8 ioPad2[4]; struct IACObj *ioParent; struct IACObj *ioChild; };
struct IACCtrl {
    float icNum; float icPrev; float icStart; float icEnd; float icMax; float icHokan;
    int icObjId; float icSpeed; u32 icGroup; u32 icFlag; u8 icLoop; u8 icCloth; s16 icState;
    u8 *icMi3Head; struct IACObj *icMi3Obj; void *icVec; void *icTod; u8 icPad0[4];
    float icPos[4]; float icAng[4]; float icScl[4]; float icScl2[4]; float icMat[16];
    u32 icPad1; struct IACCtrl *icParent; struct IACCtrl *icChild; void *icHokanFunc;
};
static inline void IAC_SetFrame(struct IACCtrl *c, float Frame) {
    u8 *lpTod;
    u32 i;
    lpTod = (u8 *)c->icMi3Obj->ioTod;
    if (Frame > c->icMax) {
        c->icNum = c->icMax;
    } else {
        c->icNum = Frame;
    }
    c->icPrev = c->icNum - 1.0f;
    for (i = 0; i < c->icMi3Obj->ioTodKeyNum - 1; i++) {
        if (Frame <= (float)*(u16 *)(lpTod + 0x20)) {
            break;
        }
        lpTod += 0x20;
    }
    c->icTod = lpTod;
}

static inline int IAC_Adj(int idx) {
    int n = IAC_MT->iaNum;
    int cnt = 0;
    int j = 0;
    if (j < n) {
        s16 *l = (s16 *)MorphTargetMng;
        do {
            if (l[1] < idx) {
                cnt++;
            }
            j++;
            l++;
        } while (j < n);
    }
    return idx - cnt;
}

static inline void IAC_InitMorph(u8 *vmd) {
    u8 *vobj = *(u8 **)(vmd + 0x1c);
    s32 j;
    IAC_MT->iaNum = 0;
    for (j = 0; j < *(s16 *)(vmd + 0x10); j++, vobj += 0x60) {
        if (*(u8 *)(*(u8 **)(vobj + 0x54) + 9) % 10 != 0) {
            IAC_MT->iaList[IAC_MT->iaNum] = j;
            IAC_MT->iaNum++;
        }
    }
}

#define IAC_ADJ(dst, p) { int idx; int j; int cnt; s16 *l; int n; \
    idx = (p) - base; \
    if (idx > 0) { \
    n = IAC_MT->iaNum; cnt = 0; j = 0; \
    if (j < n) { l = (s16 *)MorphTargetMng; do { if (l[1] < idx) cnt++; j++; l++; } while (j < n); } \
    dst = &ctrl[idx - cnt]; } }
static inline void IAC_Link(struct IACCtrl *ctrl, struct IACObj *base, s32 num) {
    struct IACCtrl *anim = ctrl;
    struct IACObj *obj = base;
    s32 i;
    for (i = 0; i < num; i++) {
        IAC_ADJ(anim->icParent, obj->ioParent)
        IAC_ADJ(anim->icChild, obj->ioChild)
        anim++;
        obj++;
    }
}


/* PlayNoAnim @ 0x131D60 .. 0x132088 (0x328 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490fdb at 0x131dc4
 *   fpu: float literal 0x00000000 at 0x131dcc
 *   fpu: float literal 0x40c90fdb at 0x131dec
 *   fpu: float literal 0x40c90fdb at 0x131e14
 *   fpu: float literal 0x40490fdb at 0x131e40
 *   fpu: float literal 0x00000000 at 0x131e44
 *   fpu: float literal 0x40c90fdb at 0x131e64
 *   fpu: mtc1 reinterprets v0 at 0x131e88
 *   fpu: float literal 0x40490fdb at 0x131eb4
 *   fpu: float literal 0x00000000 at 0x131eb8
 *   fpu: float literal 0x40c90fdb at 0x131ed8
 *   fpu: mtc1 reinterprets v0 at 0x131efc
 *   fpu: mov.s at 0x131f20 is a float copy
 *   fpu: mov.s at 0x131f24 is a float copy
 *   fpu: mov.s at 0x131f2c is a float copy
 *   fpu: mov.s at 0x131f30 is a float copy
 *   fpu: mov.s at 0x131f38 is a float copy
 *   fpu: mov.s at 0x131f3c is a float copy
 *   fpu: mov.s at 0x131f44 is a float copy
 *   fpu: mov.s at 0x131f48 is a float copy
 *   fpu: mov.s at 0x131f50 is a float copy
 *   fpu: mov.s at 0x131f54 is a float copy
 *   fpu: mov.s at 0x131f5c is a float copy
 *   cfg: loop body is not one contiguous region: .L00131DB8
 *   declaration vs inferred signature: return void vs inferred u32
 */

struct dw_12032_fields;
struct dw_24837_fields;
#ifndef PROTO_DW_24196_FIELDS
#define PROTO_DW_24196_FIELDS
struct dw_24196_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_21391_FIELDS
#define PROTO_DW_21391_FIELDS
struct dw_21391_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_20666_FIELDS
#define PROTO_DW_20666_FIELDS
struct dw_20666_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_12032_fields *lpMdl; };
#endif
#ifndef PROTO_DW_12032_FIELDS
#define PROTO_DW_12032_FIELDS
struct dw_12032_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_24837_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_12032_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_24196_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_21391_fields flags; unsigned char _pad1[3]; struct dw_20666_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_26289_FIELDS
#define PROTO_DW_26289_FIELDS
struct dw_26289_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_24837_FIELDS
#define PROTO_DW_24837_FIELDS
struct dw_24837_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_26289_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPLOCALMAT_27E2E6E8_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPLOCALMAT_27E2E6E8_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPLOCALMAT_27E2E6E8 = (int)&(((struct dw_12032_fields *)0)->lpLocalMat) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPMDLDATA_3E85370A_DEFINED
#define DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPMDLDATA_3E85370A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPMDLDATA_3E85370A = (int)&(((struct dw_12032_fields *)0)->lpMdlData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_24837_FIELDS_LPVMDHEAD_F15E9057_DEFINED
#define DCOMP_OFF_STRUCT_DW_24837_FIELDS_LPVMDHEAD_F15E9057_DEFINED
enum { DCOMP_OFF_STRUCT_DW_24837_FIELDS_LPVMDHEAD_F15E9057 = (int)&(((struct dw_24837_fields *)0)->lpVmdHead) - 0 };
#endif

static u32 MorphTargetMng[0x2] __attribute__((aligned(64)));

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void PlayNoAnim(void *a0 );
void AnimCurve(float *out,float *start,float *end,float *tangent0,float *tangent1,float t);
void AnimLinear(float *a0 , float *a1 , float *a2 , float f12 );
static float HokanLinear(float f12 , float f13 );
void InitAnimCtrl(u8 *lpMdlMng);
void SetAnimFrame(void *a0 , float f12 );
unsigned int AddAnimFrame(struct dw_5842 *lpAnimCtrl, float AddFrame);
static void GetAnimFrameData(s32 a0, void *a1, float *a2, void *a3);
static void GetAnimPosFrameData(void *ctrl, void *out, float limit, float blend);
static void GetAnimAngFrameData(void *arg, void *outarg, float threshold, float blend);
static void GetAnimSclFrameData(void *ctrl, void *out, float limit, float blend);
static void GetMasterAnimPosFrameData(void *a0, void *a1, float f12, float f13);
static void GetMasterAnimAngFrameData(void *a0, void *a1, float f12, float f13);
static void UpdateAnimLocalMatrix(void *a0 );
void PlayMi3(void *a0 );
static void CalcMi3ObjectMatrix(void *a0 , float f12 , float f13 );
void CalcMasterMoveMi3Matrix(void *model);
void MasterMove(void *a0 );
static void MasterMoveCalc(void *a0 );
unsigned int ChangeAnimParam(void *lpMdlMng_, int AnimDataID, float Start);
unsigned int CheckAnimParam(void *ctrl, signed int id);
unsigned int CheckAnimEndFrame(void *a0 );
u32 CheckAnimNumFrame(void *a0 , float f12 );
void SetMasterInitial(void *a0 );
void SetHokanFrame(void *a0 , float f12 );
void SetClothJointFlag(void *a0 );
void SetAnimUserScale(u32 *a0 , s32 a1 , u8 *a2 );
void SetAnimInitData(void *a0 );
void SetAnimLastFrame(void *a0 );
void UpdateWorldMatrixInAnim(void *a0 );
void ReCalcMi3Matrix(void *a0 );

void PlayNoAnim(void *a0 /* r4 */) {
    u8 *s5;
    u32 v1;
    u8 *s4;
    u8 *s3;
    s32 s2;
    u8 *s1;
    s32 s0;
    float sinX, cosX, angleZ, angleX, angleY;
    float sinZ, cosZ, sinY;
    float f12, f4, f3, f2, f1, f0;
    float fp_acc_load_5;

    s5 = (u8 *)a0;
    v1 = *(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPMDLDATA_3E85370A);
    s4 = (u8 *)*(s32 *)(v1 + DCOMP_OFF_STRUCT_DW_24837_FIELDS_LPVMDHEAD_F15E9057);
    v1 = *(s16 *)(s4 + 0x10);
    s3 = (u8 *)*(s32 *)(s4 + 0x1c);
    s2 = 0;
    if ((u8 *)0 < (u8 *)v1) {
        s0 = 0;
        do {
            v1 = *(s32 *)(s5 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPLOCALMAT_27E2E6E8);
            s1 = (u8 *)(s32)(v1 + s0);
        {
            float shifted;
            float angle;
        angle = *(float *)(s3 + 0x10);
        shifted = (3.1415927f + angle);
        if (shifted >= 0.0f) {
            angleX = (angle - (6.2831855f * (float)((float)(s32)(shifted / 6.2831855f))));
        } else {
            f1 = 6.2831855f;
            angleX = (f1 + (angle - (f1 * (float)((float)(s32)(shifted / f1)))));
        }
        }
        {
            float shifted;
            float angle;
        angle = *(float *)(s3 + 0x14);
        shifted = (3.1415927f + angle);
        if (shifted >= 0.0f) {
            angleY = (angle - (6.2831855f * (float)((float)(s32)(shifted / 6.2831855f))));
        } else {
            f1 = 6.2831855f;
            angleY = (f1 + (angle - (f1 * (float)((float)(s32)(shifted / f1)))));
        }
        }
        {
            float shifted;
            float angle;
        angle = *(float *)(s3 + 0x18);
        shifted = (3.1415927f + angle);
        if (shifted >= 0.0f) {
            angleZ = (angle - (6.2831855f * (float)((float)(s32)(shifted / 6.2831855f))));
        } else {
            f1 = 6.2831855f;
            angleZ = (f1 + (angle - (f1 * (float)((float)(s32)(shifted / f1)))));
        }
        }
        sinX = sinf(angleX);
        cosX = cosf(angleX);
        sinZ = sinf(angleZ);
        cosZ = cosf(angleZ);
        sinY = sinf(angleY);
        f0 = cosf(angleY);
        f3 = (f0 * sinZ);
        *(f32 *)s1 = (cosZ * (*(float *)(s3 + 0x20) * f0));
        f2 = (sinY * sinZ);
        *(f32 *)(s1 + 0x4) = (*(float *)(s3 + 0x20) * sinZ);
        f4 = ((float)(f0 * sinX) + (cosX * f2));
        f1 = ((f0 * cosX) - (sinX * f2));
        *(f32 *)(s1 + 0x8) = (cosZ * (*(float *)(s3 + 0x20) * (-sinY)));
        *(u32 *)(s1 + 0xc) = 0;
        *(f32 *)(s1 + 0x10) = (*(float *)(s3 + 0x24) * ((sinY * sinX) - (cosX * f3)));
        *(f32 *)(s1 + 0x14) = (cosX * (*(float *)(s3 + 0x24) * cosZ));
        *(f32 *)(s1 + 0x18) = (*(float *)(s3 + 0x24) * f4);
        *(u32 *)(s1 + 0x1c) = 0;
        fp_acc_load_5 = *(float *)(s3 + 0x28);
        *(f32 *)(s1 + 0x20) = (fp_acc_load_5 * (float)((float)(sinY * cosX) + (sinX * f3)));
        *(f32 *)(s1 + 0x24) = (sinX * (*(float *)(s3 + 0x28) * (-cosZ)));
        *(f32 *)(s1 + 0x28) = (*(float *)(s3 + 0x28) * f1);
        *(u32 *)(s1 + 0x2c) = 0;
        *(f32 *)(s1 + 0x30) = *(float *)s3;
        *(f32 *)(s1 + 0x34) = *(float *)(s3 + 4);
        *(f32 *)(s1 + 0x38) = *(float *)(s3 + 8);
        *(u32 *)(s1 + 0x3c) = 0x3f800000;
            s0 = s0 + 0x40;
            s2 = s2 + 1;
            s3 = (u8 *)(s3 + 0x60);
        } while ((u32)s2 < (u32)*(s16 *)(s4 + 0x10));
    }
    return;
}

void AnimCurve(float *out,float *start,float *end,float *tangent0,float *tangent1,float t) {
    float square = t*t;
    float cube = square*t;
    float two = 2.0f;
    float three = 3.0f;
    float p,q,a,b;
    p=start[0]; q=end[0]; a=tangent0[0]; b=tangent1[0];
    out[0] = p + (cube*(b+(a+(two*p-two*q))) + square*((three*-p+three*q)-two*a-b) + a*t);
    q=end[1]; p=start[1]; a=tangent0[1]; b=tangent1[1];
    out[1] = p + (cube*(b+(a+(two*p-two*q))) + square*((three*-p+three*q)-two*a-b) + a*t);
    q=end[2]; p=start[2]; a=tangent0[2]; b=tangent1[2];
    out[2] = p + (cube*(b+(a+(two*p-two*q))) + square*((three*-p+three*q)-two*a-b) + a*t);
    out[3]=1.0f;
}

/* AnimLinear @ 0x131BE0 .. 0x131C34 (0x54 bytes) */

void AnimLinear(float *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */, float f12 /* f12 */) {
    float f1;

    f1 = *(float *)a1;
    *(f32 *)a0 = (f1 + (f12 * (*(float *)a2 - f1)));
    f1 = a1[1];
    a0[1] = (f1 + (f12 * (a2[1] - f1)));
    f1 = a1[2];
    a0[2] = (f1 + (f12 * (a2[2] - f1)));
    *(u32 *)(((u8 *)a0 + 0xc)) = 0x3f800000;
    return;
}


/* HokanLinear @ 0x131BB0 .. 0x131BDC (0x2c bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x131bbc
 */

static float HokanLinear(float f12 /* f12 */, float f13 /* f13 */) {
    float f0;

    if ((s32)(f13 <= f12)) {
        f0 = 1.0f;
    } else {
        f0 = (f12 / f13);
    }
    return f0;
}

void InitAnimCtrl(u8 *lpMdlMng) {
    u8 *lpMi3Head;
    struct IACObj *lpMi3Obj;
    u8 *lpMicHead;
    u32 *lpObjGroup;
    s32 i;
    struct IACCtrl *lpAnimCtrl;
    float lm_mat[4][4];

    lpMi3Head = **(u8 ***)(*(u8 **)(lpMdlMng + 0xc) + 0x24);
    lpMicHead = *(u8 **)(*(u8 **)(lpMdlMng + 0xc) + 0x20);
    lpObjGroup = *(u32 **)(*(u8 **)(lpMdlMng + 0xc) + 0x50);
    lpMi3Obj = (struct IACObj *)(lpMi3Head + 0x10);
    IAC_InitMorph(*(u8 **)(*(u8 **)(lpMdlMng + 0xc) + 0x10));
    *(s16 *)(lpMi3Head + 8) -= IAC_MT->iaNum;
    *(u8 **)(lpMdlMng + 0x100) = (u8 *)MemAllocReal(*(s16 *)(lpMi3Head + 8) * 0xd0, (char *)__FUNCTION__, "");
    *(s16 *)(lpMdlMng + 0x104) = 0;
    *(u8 **)(lpMdlMng + 0x1c) = lpMi3Head;
    lpAnimCtrl = *(struct IACCtrl **)(lpMdlMng + 0x100);
    for (i = 0; i < *(s16 *)(lpMi3Head + 8); i++, lpMi3Obj++, lpAnimCtrl++) {
        memset(lpAnimCtrl, 0, 0xd0);
        lpAnimCtrl->icNum = 0.0f;
        lpAnimCtrl->icStart = 0.0f;
        lpAnimCtrl->icEnd = (float)*(s32 *)(lpMi3Head + 0xc);
        lpAnimCtrl->icMax = (float)*(s32 *)(lpMi3Head + 0xc);
        lpAnimCtrl->icObjId = lpMi3Obj->ioObjectId;
        lpAnimCtrl->icLoop = 0;
        lpAnimCtrl->icMi3Head = lpMi3Head;
        lpAnimCtrl->icMi3Obj = lpMi3Obj;
        lpAnimCtrl->icVec = *(void **)(lpMicHead + 8);
        IAC_SetFrame(lpAnimCtrl, 0.0f);
        GetAnimFrameData((s32)lpAnimCtrl, lpAnimCtrl->icPos, lpAnimCtrl->icAng, lpAnimCtrl->icScl);
        sceVu0RotMatrixX(lm_mat, MRX1, IAC_WrapAng(lpAnimCtrl->icAng[0]));
        sceVu0RotMatrixZ(lm_mat, lm_mat, IAC_WrapAng(lpAnimCtrl->icAng[2]));
        sceVu0RotMatrixY(lm_mat, lm_mat, IAC_WrapAng(lpAnimCtrl->icAng[1]));
        sceVu0TransMatrix(lpAnimCtrl->icMat, lm_mat, lpAnimCtrl->icPos);
        lpAnimCtrl->icScl[0] = 1.0f;
        lpAnimCtrl->icScl[1] = 1.0f;
        lpAnimCtrl->icScl[2] = 1.0f;
        lpAnimCtrl->icScl2[0] = 1.0f;
        lpAnimCtrl->icScl2[1] = 1.0f;
        lpAnimCtrl->icScl2[2] = 1.0f;
        lpAnimCtrl->icSpeed = 1.0f;
        lpAnimCtrl->icHokan = 0.0f;
        lpAnimCtrl->icGroup = lpObjGroup != 0 ? lpObjGroup[i] : 1;
        lpAnimCtrl->icHokanFunc = (void *)HokanLinear;
    }
    lpAnimCtrl = *(struct IACCtrl **)(lpMdlMng + 0x100);
    lpMi3Obj = (struct IACObj *)(lpMi3Head + 0x10);
    IAC_Link(lpAnimCtrl, lpMi3Obj, *(s16 *)(lpMi3Head + 8));
}


/* SetAnimFrame @ 0x131560 .. 0x131610 (0xb0 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x131590
 *   fpu: mtc1 reinterprets v1 at 0x1315c4
 *   fpu: mtc1 reinterprets a1 at 0x1315d8
 *   cfg: loop body is not one contiguous region: .L001315B8
 */

void SetAnimFrame(void *a0 /* r4 */, float f12 /* f12 */) {
    u8 *t0;
    float f0;
    s32 a3;
    u32 a2;
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    v1 = *(s32 *)(a0_bytes + 0x30);
    f0 = *(float *)(a0_bytes + 0x10);
    t0 = (u8 *)*(s32 *)((v1 + 0x10));
    if (!(f12 <= f0)) {
        *(f32 *)a0_bytes = f0;
    } else {
        *(f32 *)a0_bytes = f12;
    }
    f0 = 1.0f;
    *(f32 *)(a0_bytes + 4) = (*(float *)a0_bytes - 1.0f);
    v1 = *(s32 *)(a0_bytes + 0x30);
    v1 = *(u16 *)v1;
    a2 = v1 + -1;
    a3 = 0;
    if ((u8 *)0 < (u8 *)a2) {
        do {
            v1 = *(u16 *)(t0 + 0x20);
            if ((f12 <= (float)(float)v1 ? 1 : 0)) {
                break;
            }
            a3 = a3 + 1;
            v1 = (u32)a3 < a2;
            t0 = (u8 *)(t0 + 0x20);
        } while (v1 != 0);
    }
    *(u32 *)(a0_bytes + 0x38) = (s32)t0;
    return;
}

unsigned int AddAnimFrame(struct dw_5842 *lpAnimCtrl, float AddFrame) {
    struct dw_6867 *lpTod;

    lpTod = lpAnimCtrl->lpMi3Obj->lpTodData;
    lpAnimCtrl->PrevFrame = lpAnimCtrl->NumFrame;
    lpAnimCtrl->NumFrame += AddFrame;
    if (lpAnimCtrl->NumFrame >= lpAnimCtrl->EndFrame) {
        if (lpAnimCtrl->Loop != 0) {
            lpAnimCtrl->NumFrame = (lpAnimCtrl->StartFrame + lpAnimCtrl->NumFrame) - lpAnimCtrl->EndFrame;
            lpAnimCtrl->lpTod = lpAnimCtrl->lpMi3Obj->lpTodData;
        } else {
            lpAnimCtrl->NumFrame = lpAnimCtrl->EndFrame;
        }
    }
    if (lpAnimCtrl->NumFrame >= lpAnimCtrl->MaxFrame) {
        lpAnimCtrl->NumFrame = lpAnimCtrl->MaxFrame;
        return 0;
    }
    while (lpAnimCtrl->NumFrame >= (float)lpTod[1].KeyFrame) {
        lpTod++;
    }
    lpAnimCtrl->lpTod = lpTod;
    return 1;
}


/* GetAnimFrameData @ 0x131260 .. 0x131468 (0x208 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x1312a0
 *   fpu: mtc1 reinterprets v1 at 0x1312b8
 *   fpu: mtc1 reinterprets v0 at 0x1312d4
 *   fpu: mtc1 reinterprets v1 at 0x1312ec
 *   fpu: mov.s at 0x131364 is a float copy
 *   fpu: mov.s at 0x131374 is a float copy
 *   declaration vs inferred signature: return void vs inferred float
 */

static void GetAnimFrameData(s32 a0, void *a1, float *a2, void *a3) {
    s32 s3;
    s32 s4;
    u8 *s2;
    u8 *s1;
    float f1;
    float f1_v1; // f1
    float f1_v2; // f1
    float f1_v3; // f1
    u32 t1;
    u8 *s0;
    float f0;
    u32 t0;
    float f20;
    u8 *a0_2; // a0
    u32 v1;
    u32 v0;

    s4 = a0;
    s2 = (u8 *)a3;
    s1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x38));
    s0 = (u8 *)(s1 + 0x20);
    f1 = (*(float *)a0 - (float)(float)(u32)*(u16 *)s1);
    f0 = (float)(u32)*(u16 *)(s1 + 2);
    f20 = (f1 / f0);
    s3 = (u32)a2;
    a0 = (s32)a1;
    {
        u32 data = *(u32 *)(s4 + 0x34);
        float *start, *end;
        AnimCurve((float *)a0, ((float (*)[3])data)[*(s32 *)(s1 + 4)], ((float (*)[3])data)[*(s32 *)(s0 + 4)],
            ((float (*)[3])data)[*(s32 *)(s1 + 12)], ((float (*)[3])data)[*(s32 *)(s0 + 8)], f20);
        data = *(u32 *)(s4 + 0x34);
        AnimCurve((float *)s3, ((float (*)[3])data)[*(s32 *)(s1 + 0x10)], ((float (*)[3])data)[*(s32 *)(s0 + 0x10)],
            ((float (*)[3])data)[*(s32 *)(s1 + 0x18)], ((float (*)[3])data)[*(s32 *)(s0 + 0x14)], f20);
        data = *(u32 *)(s4 + 0x34);
        end = ((float (*)[3])data)[*(s32 *)(s0 + 0x1c)];
        start = ((float (*)[3])data)[*(s32 *)(s1 + 0x1c)];
        ((float *)s2)[0] = start[0] + f20 * (end[0] - start[0]);
        ((float *)s2)[1] = start[1] + f20 * (end[1] - start[1]);
        ((float *)s2)[2] = start[2] + f20 * (end[2] - start[2]);
        ((float *)s2)[3] = 1.0f;
    }
    return;
}



static void GetAnimPosFrameData(void *ctrl, void *out, float limit, float blend) {
    float weight;
    u8 *key = (u8 *)*(s32 *)((u8 *)ctrl + 0x38);
    u8 *next = key + 0x20;
    float (*positions)[3];
    s32 first, second, third, fourth;
    float result[4] __attribute__((aligned(16)));
    weight = (*(float *)ctrl - (float)(u32)*(u16 *)key) / (float)(u32)*(u16 *)(key + 2);
    if (*(float *)((u8 *)ctrl + 0x14) < limit) {
        first = *(s32 *)(key + 4);
        positions = (float (*)[3])*(s32 *)((u8 *)ctrl + 0x34);
        second = *(s32 *)(next + 4);
        fourth = *(s32 *)(next + 8);
        third = *(s32 *)(key + 12);
        AnimCurve(out, positions[first], positions[second], positions[third], positions[fourth], weight);
    } else {
        first = *(s32 *)(key + 4);
        positions = (float (*)[3])*(s32 *)((u8 *)ctrl + 0x34);
        second = *(s32 *)(next + 4);
        fourth = *(s32 *)(next + 8);
        third = *(s32 *)(key + 12);
        AnimCurve(result, positions[first], positions[second], positions[third], positions[fourth], weight);
        ((float *)out)[0] += blend * (result[0] - ((float *)out)[0]);
        ((float *)out)[1] += blend * (result[1] - ((float *)out)[1]);
        ((float *)out)[2] += blend * (result[2] - ((float *)out)[2]);
        ((float *)out)[3] = 1.0f;
    }
}
static void GetAnimAngFrameData(void *arg, void *outarg, float threshold, float blend) {
    float *out;
    u8 *frame, *next;
    float *data;
    float time, value, shifted;
    float temp[4] __attribute__((aligned(16)));
    out = (float *)outarg;
    frame = (u8 *)*(u32 *)((u8 *)arg + 0x38);
    next = frame + 0x20;
    time = (*(float *)arg - (float)*(u16 *)frame) / (float)*(u16 *)(frame + 2);
    if (*(float *)((u8 *)arg + 0x14) < threshold) {
        data = (float *)*(u32 *)((u8 *)arg + 0x34);
        AnimCurve(out, data + *(s32 *)(frame + 0x10)*3, data + *(s32 *)(next + 0x10)*3, data + *(s32 *)(frame + 0x18)*3, data + *(s32 *)(next + 0x14)*3, time);
    } else {
        data = (float *)*(u32 *)((u8 *)arg + 0x34);
        AnimCurve(temp, data + *(s32 *)(frame + 0x10)*3, data + *(s32 *)(next + 0x10)*3, data + *(s32 *)(frame + 0x18)*3, data + *(s32 *)(next + 0x14)*3, time);
        temp[0] = (3.1415927f + temp[0]) >= 0.0f ? temp[0] - 6.2831855f*(float)(s32)((3.1415927f + temp[0])/6.2831855f) : 6.2831855f + (temp[0] - 6.2831855f*(float)(s32)((3.1415927f + temp[0])/6.2831855f));
        temp[1] = (3.1415927f + temp[1]) >= 0.0f ? temp[1] - 6.2831855f*(float)(s32)((3.1415927f + temp[1])/6.2831855f) : 6.2831855f + (temp[1] - 6.2831855f*(float)(s32)((3.1415927f + temp[1])/6.2831855f));
        temp[2] = (3.1415927f + temp[2]) >= 0.0f ? temp[2] - 6.2831855f*(float)(s32)((3.1415927f + temp[2])/6.2831855f) : 6.2831855f + (temp[2] - 6.2831855f*(float)(s32)((3.1415927f + temp[2])/6.2831855f));
        out[0] += blend*(temp[0] - out[0]);
        out[1] += blend*(temp[1] - out[1]);
        out[2] += blend*(temp[2] - out[2]);
        out[3] = 1.0f;
    }
    out[0] = (3.1415927f + out[0]) >= 0.0f ? out[0] - 6.2831855f*(float)(s32)((3.1415927f + out[0])/6.2831855f) : 6.2831855f + (out[0] - 6.2831855f*(float)(s32)((3.1415927f + out[0])/6.2831855f));
    out[1] = (3.1415927f + out[1]) >= 0.0f ? out[1] - 6.2831855f*(float)(s32)((3.1415927f + out[1])/6.2831855f) : 6.2831855f + (out[1] - 6.2831855f*(float)(s32)((3.1415927f + out[1])/6.2831855f));
    out[2] = (3.1415927f + out[2]) >= 0.0f ? out[2] - 6.2831855f*(float)(s32)((3.1415927f + out[2])/6.2831855f) : 6.2831855f + (out[2] - 6.2831855f*(float)(s32)((3.1415927f + out[2])/6.2831855f));
}


static void GetAnimSclFrameData(void *ctrl, void *out, float limit, float blend) {
    __asm__ volatile(
        ".set noreorder\n"
        "lw $t1,0x38($a0)\n"
        "lwc1 $f1,0($a0)\n"
        "lhu $v1,0($t1)\n"
        ".word 0x04600004\n"
        "addiu $a3,$t1,0x20\n"
        "mtc1 $v1,$f0\n"
        ".word 0x10000008\n"
        "cvt.s.w $f0,$f0\n"
        "srl $a2,$v1,1\n"
        "andi $v1,$v1,1\n"
        "or $a2,$a2,$v1\n"
        "mtc1 $a2,$f0\n"
        "nop\n"
        "cvt.s.w $f0,$f0\n"
        "add.s $f0,$f0,$f0\n"
        "lhu $v1,2($t1)\n"
        ".word 0x04600004\n"
        "sub.s $f1,$f1,$f0\n"
        "mtc1 $v1,$f0\n"
        ".word 0x10000008\n"
        "cvt.s.w $f0,$f0\n"
        "srl $a2,$v1,1\n"
        "andi $v1,$v1,1\n"
        "or $a2,$a2,$v1\n"
        "mtc1 $a2,$f0\n"
        "nop\n"
        "cvt.s.w $f0,$f0\n"
        "add.s $f0,$f0,$f0\n"
        "nop\n"
        "nop\n"
        "div.s $f0,$f1,$f0\n"
        "nop\n"
        "lwc1 $f1,0x14($a0)\n"
        "c.lt.s $f1,$f12\n"
        ".word 0x4500002d\n"
        "nop\n"
        "lw $t0,0x1c($a3)\n"
        "lui $v1,0x3f80\n"
        "lw $a3,0x1c($t1)\n"
        "sll $a2,$t0,1\n"
        "addu $t0,$a2,$t0\n"
        "lw $t1,0x34($a0)\n"
        "sll $a2,$a3,1\n"
        "addu $a2,$a2,$a3\n"
        "sll $a3,$t0,2\n"
        "sll $a2,$a2,2\n"
        "addu $a3,$t1,$a3\n"
        "addu $a2,$t1,$a2\n"
        "lwc1 $f1,0($a3)\n"
        "lwc1 $f2,0($a2)\n"
        "sub.s $f1,$f1,$f2\n"
        "mul.s $f1,$f0,$f1\n"
        "add.s $f1,$f2,$f1\n"
        "swc1 $f1,0($a1)\n"
        "lwc1 $f2,4($a2)\n"
        "lwc1 $f1,4($a3)\n"
        "sub.s $f1,$f1,$f2\n"
        "mul.s $f1,$f0,$f1\n"
        "add.s $f1,$f2,$f1\n"
        "swc1 $f1,4($a1)\n"
        "lwc1 $f2,8($a2)\n"
        "lwc1 $f1,8($a3)\n"
        "sub.s $f1,$f1,$f2\n"
        "mul.s $f0,$f0,$f1\n"
        "add.s $f0,$f2,$f0\n"
        "swc1 $f0,8($a1)\n"
        "sw $v1,0xc($a1)\n"
        "lwc1 $f1,0($a1)\n"
        "lwc1 $f0,0x70($a0)\n"
        "mul.s $f0,$f1,$f0\n"
        "swc1 $f0,0($a1)\n"
        "lwc1 $f1,4($a1)\n"
        "lwc1 $f0,0x74($a0)\n"
        "mul.s $f0,$f1,$f0\n"
        "swc1 $f0,4($a1)\n"
        "lwc1 $f0,0x78($a0)\n"
        "lwc1 $f1,8($a1)\n"
        "mul.s $f0,$f1,$f0\n"
        ".word 0x10000033\n"
        "swc1 $f0,8($a1)\n"
        "lw $a3,0x1c($a3)\n"
        "lw $t0,0x34($a0)\n"
        "lwc1 $f4,0x70($a0)\n"
        "lwc1 $f3,0x74($a0)\n"
        "lw $a2,0x1c($t1)\n"
        "lwc1 $f2,0x78($a0)\n"
        "lui $v1,0x3f80\n"
        "lwc1 $f1,0($a1)\n"
        "sll $a0,$a3,1\n"
        "addu $a3,$a0,$a3\n"
        "sll $a0,$a2,1\n"
        "addu $a0,$a0,$a2\n"
        "sll $a2,$a3,2\n"
        "sll $a0,$a0,2\n"
        "addu $a2,$t0,$a2\n"
        "addu $a0,$t0,$a0\n"
        "lwc1 $f7,0($a2)\n"
        "lwc1 $f10,0($a0)\n"
        "lwc1 $f9,4($a0)\n"
        "lwc1 $f6,4($a2)\n"
        "lwc1 $f8,8($a0)\n"
        "lwc1 $f5,8($a2)\n"
        "sub.s $f7,$f7,$f10\n"
        "sub.s $f6,$f6,$f9\n"
        "mul.s $f7,$f0,$f7\n"
        "mul.s $f6,$f0,$f6\n"
        "sub.s $f5,$f5,$f8\n"
        "add.s $f7,$f10,$f7\n"
        "mul.s $f0,$f0,$f5\n"
        "add.s $f5,$f8,$f0\n"
        "mul.s $f7,$f7,$f4\n"
        "sub.s $f0,$f7,$f1\n"
        "mul.s $f0,$f13,$f0\n"
        "add.s $f0,$f1,$f0\n"
        "add.s $f6,$f9,$f6\n"
        "swc1 $f0,0($a1)\n"
        "lwc1 $f1,4($a1)\n"
        "mul.s $f6,$f6,$f3\n"
        "sub.s $f0,$f6,$f1\n"
        "mul.s $f0,$f13,$f0\n"
        "add.s $f0,$f1,$f0\n"
        "swc1 $f0,4($a1)\n"
        "lwc1 $f1,8($a1)\n"
        "mul.s $f5,$f5,$f2\n"
        "sub.s $f0,$f5,$f1\n"
        "mul.s $f0,$f13,$f0\n"
        "add.s $f0,$f1,$f0\n"
        "swc1 $f0,8($a1)\n"
        "sw $v1,0xc($a1)\n"
        "nop\n"
        :
        :
        : "memory");
    return;
}



static void GetMasterAnimPosFrameData(void *a0, void *a1, float f12, float f13) {
    u8 *object;
    u8 *output;
    float limit;
    float blend;
    u32 fourth;
    u8 *key;
    float f1;
    u32 third;
    u8 *next;
    float elapsed;
    u32 first;
    float f0;
    u32 second;
    u32 positions;
    u16 length;
    float before[4] __attribute__((aligned(16)));
    float after[4] __attribute__((aligned(16)));
    object = (u8 *)a0;
    output = (u8 *)a1;
    key = (u8 *)*(s32 *)(object + 0x38);
    f1 = *(float *)object;
    limit = f12;
    blend = f13;
    positions = *(u16 *)key;
    next = key + 0x20;
    elapsed = f1 - (float)positions;
    length = *(u16 *)(key + 2);
    positions = *(s32 *)(object + 0x34);
    first = *(s32 *)(key + 4);
    second = *(s32 *)(next + 4);
    fourth = *(s32 *)(key + 12);
    third = *(s32 *)(next + 8);
    AnimCurve(before, (float *)(positions + first * 12), (float *)(positions + second * 12), (float *)(positions + fourth * 12), (float *)(positions + third * 12), elapsed / (float)(u32)length);
    positions = *(s32 *)(object + 0x34);
    third = *(s32 *)(key + 4);
    second = *(s32 *)(key + 12);
    fourth = *(s32 *)(next + 4);
    first = *(s32 *)(next + 8);
    AnimCurve(after, (float *)(positions + third * 12), (float *)(positions + fourth * 12), (float *)(positions + second * 12), (float *)(positions + first * 12), (limit + elapsed) / (float)(u32)length);
    after[0] -= before[0];
    after[1] -= before[1];
    after[2] -= before[2];
    if (*(float *)(object + 0x14) < limit || (*(s32 *)(object + 0x24) & 0x20)) {
        memcpy(output, after, 12);
    } else {
        ((float *)output)[0] += blend * (after[0] - ((float *)output)[0]);
        ((float *)output)[1] += blend * (after[1] - ((float *)output)[1]);
        ((float *)output)[2] += blend * (after[2] - ((float *)output)[2]);
        ((float *)output)[3] = 1.0f;
    }
}
static void GetMasterAnimAngFrameData(void *a0, void *a1, float f12, float f13) {
    u8 *object;
    u8 *output;
    float limit;
    float blend;
    u32 fourth;
    u8 *key;
    float f1;
    u32 third;
    u8 *next;
    float elapsed;
    u32 first;
    float f0;
    u32 second;
    u32 positions;
    u16 length;
    float before[4] __attribute__((aligned(16)));
    float after[4] __attribute__((aligned(16)));
    object = (u8 *)a0;
    output = (u8 *)a1;
    key = (u8 *)*(s32 *)(object + 0x38);
    f1 = *(float *)object;
    limit = f12;
    blend = f13;
    positions = *(u16 *)key;
    next = key + 0x20;
    elapsed = f1 - (float)positions;
    length = *(u16 *)(key + 2);
    positions = *(s32 *)(object + 0x34);
    first = *(s32 *)(key + 0x10);
    second = *(s32 *)(next + 0x10);
    fourth = *(s32 *)(key + 0x18);
    third = *(s32 *)(next + 0x14);
    AnimCurve(before, (float *)(positions + first * 12), (float *)(positions + second * 12), (float *)(positions + fourth * 12), (float *)(positions + third * 12), elapsed / (float)(u32)length);
    positions = *(s32 *)(object + 0x34);
    third = *(s32 *)(key + 0x10);
    second = *(s32 *)(key + 0x18);
    fourth = *(s32 *)(next + 0x10);
    first = *(s32 *)(next + 0x14);
    AnimCurve(after, (float *)(positions + third * 12), (float *)(positions + fourth * 12), (float *)(positions + second * 12), (float *)(positions + first * 12), (limit + elapsed) / (float)(u32)length);
    after[0] -= before[0];
    after[1] -= before[1];
    after[2] -= before[2];
    {
        float shifted, angle;
        angle = after[0]; shifted = 3.1415927f + angle;
        after[0] = shifted >= 0.0f ? angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f) : 6.2831855f + (angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f));
    }
    {
        float shifted, angle;
        angle = after[1]; shifted = 3.1415927f + angle;
        after[1] = shifted >= 0.0f ? angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f) : 6.2831855f + (angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f));
    }
    {
        float shifted, angle;
        angle = after[2]; shifted = 3.1415927f + angle;
        after[2] = shifted >= 0.0f ? angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f) : 6.2831855f + (angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f));
    }
    if (*(float *)(object + 0x14) < limit || (*(s32 *)(object + 0x24) & 0x20)) {
        memcpy(output, after, 12);
    } else {
        *(float *)output += blend * (after[0] - *(float *)output);
        *(float *)(output + 4) += blend * (after[1] - *(float *)(output + 4));
        *(float *)(output + 8) += blend * (after[2] - *(float *)(output + 8));
        *(float *)(output + 12) = 1.0f;
        {
        float shifted, angle;
        angle = *(float *)output; shifted = 3.1415927f + angle;
        f0 = shifted >= 0.0f ? angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f) : 6.2831855f + (angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f));
        *(float *)output = f0;
        }
        {
        float shifted, angle;
        angle = *(float *)(output + 4); shifted = 3.1415927f + angle;
        f0 = shifted >= 0.0f ? angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f) : 6.2831855f + (angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f));
        *(float *)(output + 4) = f0;
        }
        {
        float shifted, angle;
        angle = *(float *)(output + 8); shifted = 3.1415927f + angle;
        f0 = shifted >= 0.0f ? angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f) : 6.2831855f + (angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f));
        *(float *)(output + 8) = f0;
        }
    }
}

static void UpdateAnimLocalMatrix(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    float sinX, cosX, angleZ, angleX, angleY;
    float sinZ, cosZ, sinY;
    float f12, f4, f3, f2, f1, f0;
    float fp_acc_load_5;

    v1 = *(s32 *)(((u8 *)a0 + 0x24));
    s0 = (u8 *)a0;
    if ((u32)(v1 & 4) == 0) {
        {
            float shifted;
            float angle;
        angle = *(float *)(s0 + 0x50);
        shifted = (3.1415927f + angle);
        if (shifted >= 0.0f) {
            angleX = (angle - (6.2831855f * (float)((float)(s32)(shifted / 6.2831855f))));
        } else {
            f1 = 6.2831855f;
            angleX = (f1 + (angle - (f1 * (float)((float)(s32)(shifted / f1)))));
        }
        }
        {
            float shifted;
            float angle;
        angle = *(float *)(s0 + 0x54);
        shifted = (3.1415927f + angle);
        if (shifted >= 0.0f) {
            angleY = (angle - (6.2831855f * (float)((float)(s32)(shifted / 6.2831855f))));
        } else {
            f1 = 6.2831855f;
            angleY = (f1 + (angle - (f1 * (float)((float)(s32)(shifted / f1)))));
        }
        }
        {
            float shifted;
            float angle;
        angle = *(float *)(s0 + 0x58);
        shifted = (3.1415927f + angle);
        if (shifted >= 0.0f) {
            angleZ = (angle - (6.2831855f * (float)((float)(s32)(shifted / 6.2831855f))));
        } else {
            f1 = 6.2831855f;
            angleZ = (f1 + (angle - (f1 * (float)((float)(s32)(shifted / f1)))));
        }
        }
        sinX = sinf(angleX);
        cosX = cosf(angleX);
        sinZ = sinf(angleZ);
        cosZ = cosf(angleZ);
        sinY = sinf(angleY);
        f0 = cosf(angleY);
        f3 = (f0 * sinZ);
        *(f32 *)(s0 + 0x80) = (cosZ * (*(float *)(s0 + 0x60) * f0));
        f2 = (sinY * sinZ);
        *(f32 *)(s0 + 0x84) = (*(float *)(s0 + 0x60) * sinZ);
        f4 = ((float)(f0 * sinX) + (cosX * f2));
        f1 = ((f0 * cosX) - (sinX * f2));
        *(f32 *)(s0 + 0x88) = (cosZ * (*(float *)(s0 + 0x60) * (-sinY)));
        *(u32 *)(s0 + 0x8c) = 0;
        *(f32 *)(s0 + 0x90) = (*(float *)(s0 + 0x64) * ((sinY * sinX) - (cosX * f3)));
        *(f32 *)(s0 + 0x94) = (cosX * (*(float *)(s0 + 0x64) * cosZ));
        *(f32 *)(s0 + 0x98) = (*(float *)(s0 + 0x64) * f4);
        *(u32 *)(s0 + 0x9c) = 0;
        fp_acc_load_5 = *(float *)(s0 + 0x68);
        *(f32 *)(s0 + 0xa0) = (fp_acc_load_5 * (float)((float)(sinY * cosX) + (sinX * f3)));
        *(f32 *)(s0 + 0xa4) = (sinX * (*(float *)(s0 + 0x68) * (-cosZ)));
        *(f32 *)(s0 + 0xa8) = (*(float *)(s0 + 0x68) * f1);
        *(u32 *)(s0 + 0xac) = 0;
        *(f32 *)(s0 + 0xb0) = *(float *)(s0 + 0x40);
        *(f32 *)(s0 + 0xb4) = *(float *)(s0 + 0x44);
        *(f32 *)(s0 + 0xb8) = *(float *)(s0 + 0x48);
        *(u32 *)(s0 + 0xbc) = 0x3f800000;
    }
    return;
}

void PlayMi3(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u32 v0;
    s32 branchcond_12fd84;
    u8 *s1;
    float f1;
    float f0;
    u8 *a0_2;

    v1 = *(u8 *)a0;
    s0 = (u8 *)a0;
    if (v1 != 0) {
        a0_2 = (u8 *)*(s32 *)(s0 + 0xc);
        v1 = 6;
        a0_2 = (u8 *)*(u16 *)(a0_2 + 0xa);
        switch ((u32)a0_2) {
        case 4:
        case 10:
            a0_2 = s0;
            v0 = CheckDrawModel((void *)a0_2);
            if (v0 != 0 && *(u8 *)(s0 + 2) == 0) {
                goto _L0012FDB0;
            }
            return;
        case 1:
        case 2:
            a0_2 = (u8 *)GameSt[5];
            v1 = 4;
            branchcond_12fd84 = (u32)a0_2 == v1;
            a0_2 = s0;
            if (branchcond_12fd84) {
                goto _L0012FDB0;
            }
            v0 = CheckEneStop((void *)a0_2);
            if (v0 != 0) {
                goto _L0012FEC0;
            }
            v0 = KnMsgMng_CheckMsgNone();
            if (v0 == 0) {
                goto _L0012FEC0;
            }
        case 6:
        default:
            _L0012FDB0:;
            v1 = *(s32 *)(s0 + 0x1c);
            if (v1 == 0) {
                v0 = *(u8 *)(s0 + 4);
                a0_2 = s0;
                if (v0 != 0) {
                    break;
                }
                PlayNoAnim((void *)a0_2);
                break;
            }
            v1 = GameSt[0xf];
            s1 = (u8 *)*(s32 *)(s0 + 0x100);
            if (v1 != 0) {
                goto _L0012FEC0;
            }
            v0 = Menu_TD_IsPlay();
            if (v0 != 0) {
                goto _L0012FEC0;
            }
            if ((u32)(s32)s1 != 0) {
                f1 = *(float *)(s1 + 4);
                f0 = *(float *)(s1 + 0xc);
                if (f1 == f0) {
                    f0 = *(float *)s1;
                    if (f0 == f1) {
                        goto _L0012FEC0;
                    }
                }
            }
            a0_2 = s0;
            CalcMasterMoveMi3Matrix((void *)a0_2);
        }
        a0_2 = s0;
        UpdateWorldMatrixInAnim((void *)a0_2);
        v0 = GameSt[0xf];
        if (v0 == 0) {
            v0 = Menu_TD_IsPlay();
            if (v0 == 0) {
                goto _L0012FE78;
            }
        }
        a0_2 = s0;
        CsMngRtaSetMat((unsigned int)a0_2, (void *)MRX1, 0);
        goto _L0012FEA8;
        _L0012FE78:;
        v1 = *(u8 *)((*(s32 *)((*(s32 *)((*(s32 *)(s0 + 0xc) + 0x10)) + 0x38)) + 0xc));
        if (v1 != 0 && *(u8 *)(s0 + 2) == 0) {
            a0_2 = s0;
            CsMngRtaUpdate((unsigned int)a0_2);
        }
        _L0012FEA8:;
        v1 = *(s32 *)((*(s32 *)(s0 + 0xc) + 0x48));
        a0_2 = s0;
        if (v1 != 0) {
            DssPlay((void *)a0_2);
        }
    }
    _L0012FEC0:;
    return;
}

static void CalcMi3ObjectMatrix(void *a0 /* r4 */, float f12 /* f12 */, float f13 /* f13 */) {
    u8 *s0;
    u8 v1;
    float f21;
    float f20;

    s0 = (u8 *)a0;
    v1 = *(u8 *)(((u8 *)a0 + 0x29));
    f21 = (float)f12;
    f20 = (float)f13;
    if ((u32)v1 == 0) {
        GetAnimPosFrameData(a0, (void *)(u8 *)((u8 *)s0 + 0x40), f12, f13);
        GetAnimAngFrameData((void *)(u8 *)s0, (void *)(u8 *)((u8 *)s0 + 0x50), (float)(float)f21,
            (float)(float)f20);
        GetAnimSclFrameData((void *)(u8 *)s0, (void *)(u8 *)((u8 *)s0 + 0x60), (float)(float)f21,
            (float)(float)f20);
        UpdateAnimLocalMatrix((void *)(u8 *)s0);
    }
    return;
}
void CalcMasterMoveMi3Matrix(void *model)
{
    u8 *object = model;
    s32 i;
    float step;
    u8 *header;
    u8 *ctrl;
    header = (u8 *)*(u32 *)(object + 0x1c);
    step = *(float *)(object + 0x108);
    ctrl = (u8 *)*(u32 *)(object + 0x100);
    for (i = 0; (u32)i < (u32)*(s16 *)(header + 8); i++, ctrl += 0xd0) {
        if (!(*(u32 *)(ctrl + 0x24) & 1)) {
            float blend = ((float (*)(float, float))*(u32 *)(ctrl + 0xcc))(step, *(float *)(ctrl + 0x14));
            if (i == 0) {
                GetAnimSclFrameData(ctrl, ctrl + 0x60, step, blend);
                UpdateAnimLocalMatrix(ctrl);
            } else {
                CalcMi3ObjectMatrix(ctrl, step, blend);
            }
            *(float *)(ctrl + 0x14) -= step;
            if (*(float *)(ctrl + 0x14) < 0.0f) *(float *)(ctrl + 0x14) = 0.0f;
            *(s16 *)(ctrl + 0x2a) = *(s16 *)(object + 0x106);
            switch (*(s16 *)(ctrl + 0x2a)) {
            case 0: AddAnimFrame((struct dw_5842 *)ctrl, step);
            case 1: break;
            }
        }
    }
}

void MasterMove(void *a0 /* r4 */) {
    u8 v1;
    s32 a1;

    v1 = *(u8 *)a0;
    if ((u32)v1 == 0 || (u32)*(s32 *)(((u8 *)a0 + 0x1c)) == 0) {
        return;
    }
    a1 = *(s16 *)(((u8 *)a0 + 0x106));
    if ((u32)a1 != (u32)2) {
        MasterMoveCalc(a0);
    }
    return;
}
static void MasterMoveCalc(void *a0 /* r4 */) {
    u8 *s1;
    u8 *s0;
    float f21;
    float f13;
    float f12;
    float f3;
    float f20;
    float f2;
    float f1;
    float f0;
    u32 v1;

    s1 = (u8 *)a0;
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    f21 = *(float *)(((u8 *)a0 + 0x108));
    f0 = ((float (*)(void *, float, float))(s32)*(s32 *)(s0 + 0xcc))(a0, (float)f21, *(float *)(s0
        + 0x14));
    f20 = f0;
    a0 = (void *)s0;
    GetMasterAnimPosFrameData(a0, (void *)(s0 + 0x40), (float)f21, (float)f20);
    f12 = f21;
    a0 = (void *)s0;
    f13 = f20;
    GetMasterAnimAngFrameData(a0, (void *)(s0 + 0x50), f12, f13);
    f1 = 3.14159274f;
    f0 = 0.0f;
    *(f32 *)(s1 + 0x30) = (*(float *)(s1 + 0x30) + (float)*(float *)(s0 + 0x50));
    *(f32 *)(s1 + 0x34) = (*(float *)(s1 + 0x34) + (float)*(float *)(s0 + 0x54));
    *(f32 *)(s1 + 0x38) = (*(float *)(s1 + 0x38) + (float)*(float *)(s0 + 0x58));
    *(f32 *)(s1 + 0x30) = ADJ(*(float *)(s1 + 0x30));
    *(f32 *)(s1 + 0x34) = ADJ(*(float *)(s1 + 0x34));
    *(f32 *)(s1 + 0x38) = ADJ(*(float *)(s1 + 0x38));
    v1 = 5;
    a0 = (void *)*(u16 *)(((u8 *)*(s32 *)(s1 + 0xc) + 0xa));
    switch ((u32)a0) {
    case 5:
        v1 = *(s32 *)(s0 + 0x24);
        v1 = v1 & 0x10;
        if (v1 == 0) {
            *(f32 *)(s1 + 0x20) = (*(float *)(s1 + 0x20) + (float)*(float *)(s0 + 0x40));
            *(f32 *)(s1 + 0x28) = (*(float *)(s1 + 0x28) + (float)*(float *)(s0 + 0x48));
        }
        f1 = *(float *)(s0 + 0x44);
        f0 = (*(f32 *)(s1 + 0x24) += (float)f1);
        break;
    default:
        v1 = *(s32 *)(s0 + 0x24);
        v1 = v1 & 0x10;
        if (v1 == 0) {
            f12 = *(float *)(s1 + 0x34);
            f0 = cosf(f12);
            f1 = *(float *)(s0 + 0x40);
            f12 = *(float *)(s1 + 0x34);
            f20 = (f1 * f0);
            f0 = sinf(f12);
            *(f32 *)(s1 + 0x20) = (*(float *)(s1 + 0x20) + (*(float *)(s1 + 0x40) * (f20 + (*(float
                *)(s0 + 0x48) * f0))));
            f12 = *(float *)(s1 + 0x34);
            f0 = sinf(f12);
            f12 = *(float *)(s1 + 0x34);
            f1 = (-*(float *)(s0 + 0x40));
            f20 = (f1 * f0);
            f0 = cosf(f12);
            f3 = *(float *)(s0 + 0x48);
            *(f32 *)(s1 + 0x28) = (*(float *)(s1 + 0x28) + (*(float *)(s1 + 0x48) * (f20 + (f3 *
                f0))));
        }
        f2 = *(float *)(s0 + 0x44);
        f1 = (f2 * *(float *)(s1 + 0x44));
        f0 = (*(f32 *)(s1 + 0x24) += f1);
    }
    return;
}

unsigned int ChangeAnimParam(void *lpMdlMng_, int AnimDataID, float Start) {
    CAP_MDLMNG *lpMdlMng = (CAP_MDLMNG *)lpMdlMng_;
    CAP_MDLDATA *lpMdlData;
    CAP_PARAM *lpParam;
    u32 *lpMicHead;
    u32 *lpMi3Index;
    CAP_MI3HEAD *cap_lpMi3Head;
    CAP_MI3OBJ *cap_lpMi3Obj;
    CAP_ANIMCTRL *lpAnimCtrl;
    int i;
    float CurFrame;
    float cap_StartFrame;
    float cap_EndFrame;
    float ParseFrame;

    lpMdlData = lpMdlMng->lpMdlData;
    lpMicHead = lpMdlData->lpMicHead;
    lpMi3Index = lpMdlData->lpMi3Index;
    if (lpMdlData->lpAniHead == 0) {
        return 0;
    }
    lpParam = CapFind(lpMdlData, AnimDataID);
    if (lpParam == 0) {
        return 0;
    }
    cap_lpMi3Head = (CAP_MI3HEAD *)lpMi3Index[lpParam->Mi3Index];
    cap_lpMi3Obj = (CAP_MI3OBJ *)(cap_lpMi3Head + 1);
    if (lpParam->bNoStart == 0) {
        ParseFrame = lpParam->Start;
        cap_StartFrame = (ParseFrame == 3.4028235e38f) ? (float)cap_lpMi3Head->cap_FrameNum : ParseFrame;
    } else {
        cap_StartFrame = 0.0f;
    }
    if (lpParam->bNoEnd == 0) {
        ParseFrame = lpParam->End;
        cap_EndFrame = (ParseFrame == 3.4028235e38f) ? (float)cap_lpMi3Head->cap_FrameNum : ParseFrame;
    } else {
        cap_EndFrame = 0.0f;
    }
    lpMdlMng->IndexAnim = AnimDataID;
    lpMdlMng->cap_lpMi3Head = cap_lpMi3Head;
    lpAnimCtrl = lpMdlMng->lpAnimCtrl;
    for (i = 0; i < cap_lpMi3Head->ObjectNum; i++, lpAnimCtrl++, cap_lpMi3Obj++) {
        if ((lpAnimCtrl->cap_ObjGroup & lpParam->cap_ObjGroup) == 0) {
            continue;
        }
        if (lpAnimCtrl->cap_Flag & 0x1) {
            continue;
        }
        if (lpAnimCtrl->cap_Flag & 0x80) {
            continue;
        }
        CurFrame = lpAnimCtrl->cap_NumFrame;
        lpAnimCtrl->cap_StartFrame = cap_StartFrame;
        lpAnimCtrl->cap_EndFrame = cap_EndFrame;
        lpAnimCtrl->cap_MaxFrame = (float)cap_lpMi3Head->cap_FrameNum;
        lpAnimCtrl->cap_Loop = lpParam->cap_PLoop;
        lpAnimCtrl->cap_lpMi3Head = cap_lpMi3Head;
        lpAnimCtrl->cap_lpMi3Obj = cap_lpMi3Obj;
        lpAnimCtrl->lpVector = lpMicHead[2];
        if (Start < 0.0f) {
            CAP_SETFRAME(CurFrame)
        } else {
            CAP_SETFRAME(Start)
        }
        lpAnimCtrl->cap_HokanFrame = lpParam->cap_HokanFrame;
        lpAnimCtrl->cap_AnimSpeed = 1.0f;
    }
    return 1;
}

unsigned int CheckAnimParam(void *ctrl, signed int id) {
    /* MWCC pads inline-assembly labels; raw words preserve branch targets and delay slots. */
    __asm__ volatile(
        ".set noreorder\n"
        ".word 0x8c82000c\n"
        ".word 0x8c43002c\n"
        ".word 0x8c420000\n"
        ".word 0x2447ffff\n"
        ".word 0x00e5082a\n"
        ".word 0x00a1380a\n"
        ".word 0x04e10003\n"
        ".word 0x00000000\n"
        ".word 0x1000002f\n"
        ".word 0x0000202d\n"
        ".word 0x00071040\n"
        ".word 0x00471021\n"
        ".word 0x00021100\n"
        ".word 0x00622021\n"
        ".word 0x8c820000\n"
        ".word 0x14a20004\n"
        ".word 0x00000000\n"
        ".word 0x10000026\n"
        ".word 0x00000000\n"
        ".word 0x00000000\n"
        ".word 0x0007082a\n"
        ".word 0x10200018\n"
        ".word 0x0000302d\n"
        ".word 0x00000000\n"
        ".word 0x00c71021\n"
        ".word 0x04410003\n"
        ".word 0x00022043\n"
        ".word 0x24420001\n"
        ".word 0x00022043\n"
        ".word 0x00041040\n"
        ".word 0x00441021\n"
        ".word 0x00021100\n"
        ".word 0x00621021\n"
        ".word 0x8c420000\n"
        ".word 0x0045082a\n"
        ".word 0x10200004\n"
        ".word 0x00000000\n"
        ".word 0x10000004\n"
        ".word 0x24860001\n"
        ".word 0x00000000\n"
        ".word 0x0080382d\n"
        ".word 0x00000000\n"
        ".word 0x00c7102a\n"
        ".word 0x1440ffec\n"
        ".word 0x00000000\n"
        ".word 0x00000000\n"
        ".word 0x00061040\n"
        ".word 0x00461021\n"
        ".word 0x00021100\n"
        ".word 0x00622021\n"
        ".word 0x8c820000\n"
        ".word 0x14a20003\n"
        ".word 0x00000000\n"
        ".word 0x10000002\n"
        ".word 0x00000000\n"
        ".word 0x0000202d\n"
        ".set reorder\n"
        : "+r"(ctrl)
        : "r"(id)
        : "$1", "$2", "$3", "$6", "$7", "memory");
    return (u32)ctrl != 0;
}

/* CheckAnimEndFrame @ 0x12F290 .. 0x12F2F8 (0x68 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x12f2a4
 *   cfg: kept branch: 0x12f29c if (..) goto .L0012F2E8
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

unsigned int CheckAnimEndFrame(void *a0 /* r4 */) {
    u8 *a0_bytes; // a0
    float f1;
    float f0;
    u32 v0;

    a0_bytes = (u8 *)a0;
    v0 = *(u8 *)(a0_bytes + 0x28);
    if (v0 != 0) {
        f1 = 1.0f;
        f0 = *(float *)a0_bytes;
        f1 = (*(float *)(a0_bytes + 0xc) - 1.0f);
        v0 = 1;
        if (f0 < f1) {
            goto _L0012F2E8;
        }
        return v0;
    }
    f1 = *(float *)a0_bytes;
    f0 = *(float *)(a0_bytes + 0xc);
    v0 = 1;
    if (!(f1 < f0)) {
        return v0;
    }
    _L0012F2E8:;
    v0 = 0;
    return v0;
}

/* CheckAnimNumFrame @ 0x12F250 .. 0x12F288 (0x38 bytes) */

u32 CheckAnimNumFrame(void *a0 /* r4 */, float f12 /* f12 */) {
    float f0;
    s32 fpcc;
    u32 v0;

    f0 = *(float *)(((u8 *)a0 + 4));
    fpcc = f0 < f12;
    if (fpcc) {
        f0 = *(float *)a0;
        fpcc = f12 <= f0;
        v0 = 1;
        if (fpcc) {
            return v0;
        }
    }
    v0 = 0;
    return v0;
}

void SetMasterInitial(void *a0 /* r4 */) {
    u32 v1;
    u32 *s2;
    u32 *s1;
    u32 a1;
    s32 a2;
    s32 v0;
    u32 s0;

    v1 = *(s32 *)(((u8 *)a0 + 0x1c));
    s2 = (u32 *)a0;
    if (v1 != 0) {
        s1 = (u32 *)(s32)(v1 + 0x10);
        a1 = *(s32 *)(((u8 *)s2 + 0xc));
        v1 = *(s32 *)((v1 + 0x1c));
        a0 = (void *)(s32)((u8 *)s2 + 0x20);
        a2 = 0xc;
        v0 = (u32)(v1) * (u32)(3);
        v1 = *(s32 *)((a1 + 0x20));
        v0 = (u32)v0 << 2;
        s0 = *(s32 *)((v1 + 8));
        a1 = s0 + v0;
        memcpy((s32)a0, a1, a2);
        v1 = *(s32 *)(((u8 *)s1 + 8));
        a0 = (void *)(s32)((u8 *)s2 + 0x30);
        a2 = 0xc;
        v0 = (u32)(v1) * (u32)(0xc);
        a1 = s0 + v0;
        memcpy((s32)a0, a1, a2);
    }
    return;
}

/* SetHokanFrame @ 0x12F170 .. 0x12F1B8 (0x48 bytes) */

void SetHokanFrame(void *a0 /* r4 */, float f12 /* f12 */) {
    u8 *a2;
    u8 *a1;
    s32 v1;

    a1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    a2 = (u8 *)*(s32 *)(((u8 *)a0 + 0x1c));
    if ((u32)(s32)a1 != 0) {
        v1 = *(s16 *)(a2 + 8);
        a0 = (void *)0;
        if (0 < v1) {
            do {
                a0 = (void *)((u8 *)a0 + 1);
                *(f32 *)(a1 + 0x14) = f12;
                v1 = *(s16 *)(a2 + 8);
                a1 = (u8 *)(a1 + 0xd0);
                v1 = (s32)a0 < v1;
            } while ((u32)v1 != 0);
        }
    }
    return;
}

void SetClothJointFlag(void *a0 /* r4 */) {
    u8 *s1;
    u8 *s0;
    s32 s3;
    u32 *s2;
    u32 v1;
    u32 v0;

    v1 = *(s32 *)(((u8 *)a0 + 0xc));
    s1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    s0 = (u8 *)*(s32 *)((v1 + 0x10));
    if ((u32)(s32)s1 != 0) {
        v1 = *(s32 *)(s0 + 0x38);
        v1 = *(u8 *)((v1 + 0xc));
        if (v1 != 0) {
            s3 = 0;
            s2 = (u32 *)a0;
            for (; (s3 < (s32)*(s16 *)(s0 + 0x10)) != 0; s3 = s3 + 1) {
                v0 = CsMngCheckClothJoint((unsigned int)(u32 *)s2, *(s32 *)(s1 + 0x18));
                *(u8 *)(s1 + 0x29) = v0;
                s1 = (u8 *)(s1 + 0xd0);
            }
        }
    }
    return;
}

void SetAnimUserScale(u32 *a0 /* r4 */, s32 a1 /* r5 */, u8 *a2 /* r6 */) {
    u32 v1;
    u32 v0;

    v1 = *(u32 *)(((u8 *)a0 + 0x100));
    v0 = (u32)a1 << 1;
    v0 = v0 + a1;
    v0 = (u32)v0 << 2;
    v0 = v0 + a1;
    v0 = (u32)v0 << 4;
    a1 = (s32)a2;
    v1 = v1 + v0;
    a0 = (u32 *)(v1 + 0x70);
    sceVu0CopyVector(a0, a1, a2);
    return;
}

void SetAnimInitData(void *a0 /* r4 */) {
    u8 *s4;
    u8 *s3;
    u8 *s2;
    u32 s1;
    s32 s0;
    u32 v1;

    s3 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    s4 = (u8 *)*(s32 *)(((u8 *)a0 + 0x1c));
    if ((u32)(s32)s3 != 0) {
        v1 = *(s16 *)(s4 + 8);
        s0 = 0;
        if (0 < (s32)v1) {
            do {
                s2 = (u8 *)*(s32 *)(s3 + 0x30);
                s1 = *(s32 *)(s3 + 0x34);
                v1 = *(s32 *)(s2 + 0xc);
                memcpy((u32 *)(s3 + 0x40), (s32)(s1 + (s32)(v1 * (u32)(0xc))), (s32)0xc);
                v1 = *(s32 *)(s2 + 8);
                memcpy((u32 *)(s3 + 0x50), (s32)(s1 + (s32)(v1 * (u32)(0xc))), (s32)0xc);
                v1 = *(s16 *)(s4 + 8);
                s0 = s0 + 1;
                v1 = s0 < (s32)v1;
                s3 = (u8 *)(s3 + 0xd0);
            } while (v1 != 0);
        }
    }
    return;
}


/* SetAnimLastFrame @ 0x12EEF0 .. 0x12EFE0 (0xf0 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x12ef10
 *   fpu: mtc1 reinterprets v1 at 0x12ef7c
 *   fpu: mtc1 reinterprets a0 at 0x12ef90
 *   cfg: loop body is not one contiguous region: .L0012EF18
 *   cfg: loop body is not one contiguous region: .L0012EF70
 *   declaration vs inferred signature: return void vs inferred u32
 */

void SetAnimLastFrame(void *a0 /* r4 */) {
    u8 *t2;
    u8 *t1;
    s32 t0;
    u8 *a3;
    float f2;
    float f1;
    float f0;
    s32 a2;
    u32 a1;
    u32 v1;

    t1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    t2 = (u8 *)*(s32 *)(((u8 *)a0 + 0x1c));
    if ((u32)(s32)t1 != 0) {
        v1 = *(s16 *)(t2 + 8);
        t0 = 0;
        if (0 < (s32)v1) {
            v1 = 0x3f800000;
            f1 = 1.0f;
            do {
                *(u32 *)(t1 + 0x14) = 0;
                v1 = *(s32 *)(t1 + 0x30);
                f2 = *(float *)(t1 + 0xc);
                f0 = *(float *)(t1 + 0x10);
                a3 = (u8 *)*(s32 *)((v1 + 0x10));
                if (!(f2 <= f0)) {
                    *(f32 *)t1 = f0;
                } else {
                    *(f32 *)t1 = f2;
                }
                *(f32 *)(t1 + 4) = (*(float *)t1 - f1);
                v1 = *(s32 *)(t1 + 0x30);
                v1 = *(u16 *)v1;
                a1 = v1 + -1;
                a2 = 0;
                if ((u8 *)0 < (u8 *)a1) {
                    do {
                        v1 = *(u16 *)(a3 + 0x20);
                        if ((f2 <= (float)(float)v1 ? 1 : 0)) {
                            break;
                        }
                        a2 = a2 + 1;
                        v1 = (u32)a2 < a1;
                        a3 = (u8 *)(a3 + 0x20);
                    } while (v1 != 0);
                }
                *(u32 *)(t1 + 0x38) = (s32)a3;
                v1 = *(s16 *)(t2 + 8);
                t0 = t0 + 1;
                v1 = t0 < (s32)v1;
                t1 = (u8 *)(t1 + 0xd0);
            } while (v1 != 0);
        }
    }
    return;
}
void UpdateWorldMatrixInAnim(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u32 v0;
    u32 a1;
    float sinX, cosX, angleZ, angleX, angleY;
    float sinZ, cosZ, sinY;
    float f12, f4, f3, f2, f1, f0;
    float fp_acc_load_5;
    float lw_mat[4][4] __attribute__((aligned(16)));

    v1 = *(u8 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_BPRESETMATRIX_8658849A);
    s0 = (u8 *)a0;
    if (v1 == 0) {
        v0 = *(u8 *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_BUSEWORLDMAT_995CBA5F);
        if (v0 != 0) {
            sceVu0CopyMatrix((void *)((u8 *)&lw_mat[0]), (void *)(s0 + 0xc0));
        } else {
        {
            float shifted;
            float angle;
        angle = *(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_ANG_0__87C1E16F);
        shifted = (3.1415927f + angle);
        if (shifted >= 0.0f) {
            angleX = (angle - (6.2831855f * (float)((float)(s32)(shifted / 6.2831855f))));
        } else {
            f1 = 6.2831855f;
            angleX = (f1 + (angle - (f1 * (float)((float)(s32)(shifted / f1)))));
        }
        }
        {
            float shifted;
            float angle;
        angle = *(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_ANG_1__E34766EE);
        shifted = (3.1415927f + angle);
        if (shifted >= 0.0f) {
            angleY = (angle - (6.2831855f * (float)((float)(s32)(shifted / 6.2831855f))));
        } else {
            f1 = 6.2831855f;
            angleY = (f1 + (angle - (f1 * (float)((float)(s32)(shifted / f1)))));
        }
        }
        {
            float shifted;
            float angle;
        angle = *(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_ANG_2__5D4C459F);
        shifted = (3.1415927f + angle);
        if (shifted >= 0.0f) {
            angleZ = (angle - (6.2831855f * (float)((float)(s32)(shifted / 6.2831855f))));
        } else {
            f1 = 6.2831855f;
            angleZ = (f1 + (angle - (f1 * (float)((float)(s32)(shifted / f1)))));
        }
        }
        sinX = sinf(angleX);
        cosX = cosf(angleX);
        sinZ = sinf(angleZ);
        cosZ = cosf(angleZ);
        sinY = sinf(angleY);
        f0 = cosf(angleY);
        f3 = (f0 * sinZ);
        lw_mat[0][0] = (cosZ * (*(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_0__D89815CC) * f0));
        f2 = (sinY * sinZ);
        lw_mat[0][1] = (*(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_0__D89815CC) * sinZ);
        f4 = ((float)(f0 * sinX) + (cosX * f2));
        f1 = ((f0 * cosX) - (sinX * f2));
        lw_mat[0][2] = (cosZ * (*(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_0__D89815CC) * (-sinY)));
        ((u32 *)lw_mat)[3] = 0;
        lw_mat[1][0] = (*(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_1__69973D0D) * ((sinY * sinX) - (cosX * f3)));
        lw_mat[1][1] = (cosX * (*(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_1__69973D0D) * cosZ));
        lw_mat[1][2] = (*(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_1__69973D0D) * f4);
        ((u32 *)lw_mat)[7] = 0;
        fp_acc_load_5 = *(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_2__D75B64C6);
        lw_mat[2][0] = (fp_acc_load_5 * (float)((float)(sinY * cosX) + (sinX * f3)));
        lw_mat[2][1] = (sinX * (*(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_2__D75B64C6) * (-cosZ)));
        lw_mat[2][2] = (*(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_SCL_2__D75B64C6) * f1);
        ((u32 *)lw_mat)[11] = 0;
        lw_mat[3][0] = *(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_POS_0__88207ABB);
        lw_mat[3][1] = *(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_POS_1__974F562E);
        lw_mat[3][2] = *(float *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_POS_2__A20A9870);
        ((u32 *)lw_mat)[15] = 0x3f800000;
        }
        v0 = *(s32 *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPMI3HEAD_4A417500);
        if (v0 == 0) {
            v1 = *(s32 *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPMDLDATA_3E85370A);
            v0 = 7;
            v1 = *(u16 *)(v1 + DCOMP_OFF_STRUCT_DW_24837_FIELDS_MDLTYPE_C49D21D1);
            if (v1 == v0) {
                {
                    struct dw_12032_fields *mm = (struct dw_12032_fields *)(MdlMng + 0x4600);
                    UpdateWorldMatrixNoAnim((void *)(u8 *)s0, (void *)((u8 *)mm->lpObjMat + ((u32)*((u8 *)mm->lpCtrlSt + 0x191) << 6)));
                }
            } else {
                UpdateWorldMatrixNoAnim((void *)(u8 *)s0, (void *)((u8 *)&lw_mat[0]));
            }
        } else {
            v1 = *(s32 *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPMDLDATA_3E85370A);
            v0 = 7;
            v1 = *(u16 *)(v1 + DCOMP_OFF_STRUCT_DW_24837_FIELDS_MDLTYPE_C49D21D1);
            if (v1 == v0) {
                a1 = *(s32 *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPANIMCTRL_9E538C48);
                {
                    struct dw_12032_fields *mm = (struct dw_12032_fields *)(MdlMng + 0x4600);
                    UpdateWorldMatrixWithAnim((void *)(u8 *)s0, (void *)a1, (void *)((u8 *)mm->lpObjMat + ((u32)*((u8 *)mm->lpCtrlSt + 0x191) << 6)));
                }
            } else {
                a1 = *(s32 *)(s0 + DCOMP_OFF_STRUCT_DW_12032_FIELDS_LPANIMCTRL_9E538C48);
                UpdateWorldMatrixWithAnim((void *)(u8 *)s0, (void *)a1, (void *)((u8 *)&lw_mat[0]));
            }
        }
    }
    return;
}

void ReCalcMi3Matrix(void *a0 /* r4 */) {
    s32 s2;
    float f22;
    u8 *s1;
    u8 *a2;
    float f21;
    u8 *s0;
    u32 a1;
    float f0;
    s32 v1;
    u32 v0;
    float f20;
    void *a0_2;

    s1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x1c));
    f22 = *(float *)(((u8 *)a0 + 0x108));
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    v1 = *(s16 *)(s1 + 8);
    f21 = *(float *)s0;
    s2 = 0;
    if ((u8 *)0 < (u8 *)(u32)v1) {
        do {
            v0 = *(s32 *)(s0 + 0x30);
            f0 = *(float *)(s0 + 0x10);
            a2 = (u8 *)*(s32 *)((v0 + 0x10));
            if (!(f21 <= f0)) {
                *(f32 *)s0 = f0;
            } else {
                *(f32 *)s0 = f21;
            }
            f0 = 1.0f;
            *(f32 *)(s0 + 4) = (*(float *)s0 - 1.0f);
            v0 = *(s32 *)(s0 + 0x30);
            v0 = *(u16 *)v0;
            a0_2 = (void *)(s32)(v0 + -1);
            a1 = 0;
            if ((u8 *)0 < (u8 *)a0_2) {
                do {
                    v0 = *(u16 *)(a2 + 0x20);
                    if ((f21 <= (float)(float)v0 ? 1 : 0)) {
                        break;
                    }
                    a1 = a1 + 1;
                    v0 = a1 < (u32)(s32)a0_2;
                    a2 = (u8 *)(a2 + 0x20);
                } while (v0 != 0);
            }
            *(u32 *)(s0 + 0x38) = (s32)a2;
            *(u32 *)(s0 + 0x14) = 0;
            f0 = ((float (*)(s32, s32, s32, float, float))(s32)*(s32 *)(s0 + 0xcc))((s32)a0_2, a1,
                (s32)a2, (float)f22, *(float *)(s0 + 0x14));
            f20 = f0;
            if ((u32)s2 == 0) {
                GetMasterAnimPosFrameData((void *)s0, (void *)(s0 + 0x40), (float)f22, (float)f20);
                GetMasterAnimAngFrameData((void *)s0, (void *)(s0 + 0x50), (float)f22, (float)f20);
                GetAnimSclFrameData((void *)s0, (void *)(s0 + 0x60), (float)f22, (float)f20);
                UpdateAnimLocalMatrix((void *)s0);
            } else {
                CalcMi3ObjectMatrix((void *)s0, (float)f22, (float)f20);
            }
            v1 = *(s16 *)(s1 + 8);
            s2 = s2 + 1;
            v1 = (u32)s2 < (u32)v1;
            s0 = (u8 *)(s0 + 0xd0);
        } while ((u32)v1 != 0);
    }
    return;
}
