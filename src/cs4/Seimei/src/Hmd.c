#include "common.h"


/* DrawHmdPrimListDirect @ 0x15B430 .. 0x15B84C (0x41c bytes) */

extern void sceVu0ScaleVectorXYZ(void *,void *,float);
extern void sceVu0AddVector(void *,void *,void *);
extern void sceVu0RotTransPers(void *, void *, void *, int);

#ifndef HMD_DRAW_STRUCTS_DEFINED
#define HMD_DRAW_STRUCTS_DEFINED
struct HmdVtx { float x; float y; float z; float w; };
struct HmdMdl { u8 pad0[0x4c]; struct HmdVtx *pVertex; u8 pad1[0x0c]; u8 *pColor; };
struct HmdPrim { s16 i0; s16 pad0; s16 i1; s16 pad1; s16 i2; u8 pad2[8]; u8 mat; u8 pad3; };
#endif


/* DrawHmdModel @ 0x15B850 .. 0x15BEB4 (0x664 bytes, frame 0x140) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490fdb at 0x15b8c0
 *   fpu: float literal 0x00000000 at 0x15b8c4
 *   fpu: float literal 0x40c90fdb at 0x15b8e4
 *   fpu: mtc1 reinterprets v0 at 0x15b908
 *   fpu: float literal 0x40490fdb at 0x15b934
 *   fpu: float literal 0x00000000 at 0x15b938
 *   fpu: float literal 0x40c90fdb at 0x15b958
 *   fpu: mtc1 reinterprets v0 at 0x15b97c
 *   fpu: float literal 0x40490fdb at 0x15b9a8
 *   fpu: float literal 0x00000000 at 0x15b9ac
 *   fpu: float literal 0x40c90fdb at 0x15b9cc
 *   fpu: mtc1 reinterprets v0 at 0x15b9f0
 *   fpu: mov.s at 0x15ba14 is a float copy
 *   fpu: mov.s at 0x15ba18 is a float copy
 *   fpu: mov.s at 0x15ba20 is a float copy
 *   fpu: mov.s at 0x15ba24 is a float copy
 *   fpu: mov.s at 0x15ba2c is a float copy
 *   fpu: mov.s at 0x15ba30 is a float copy
 *   fpu: mov.s at 0x15ba38 is a float copy
 *   fpu: mov.s at 0x15ba3c is a float copy
 *   fpu: mov.s at 0x15ba44 is a float copy
 *   fpu: mov.s at 0x15ba48 is a float copy
 *   fpu: mov.s at 0x15ba50 is a float copy
 *   stack: address of the slot at 0x100 escapes at 0x15bb38
 *   stack: address of the slot at 0x100 escapes at 0x15bb38
 *   stack: address of the slot at 0xc4 escapes at 0x15bb70
 *   stack: address of the slot at 0xc8 escapes at 0x15bb70
 *   stack: address of the slot at 0xcc escapes at 0x15bb70
 *   fpu: float literal 0x40490fdb at 0x15bb88
 *   fpu: float literal 0x00000000 at 0x15bb8c
 *   fpu: float literal 0x40c90fdb at 0x15bbac
 *   fpu: mtc1 reinterprets v0 at 0x15bbd0
 *   fpu: float literal 0x40490fdb at 0x15bbfc
 *   fpu: float literal 0x00000000 at 0x15bc00
 *   fpu: float literal 0x40c90fdb at 0x15bc20
 *   fpu: mtc1 reinterprets v0 at 0x15bc44
 *   fpu: float literal 0x40490fdb at 0x15bc70
 *   fpu: float literal 0x00000000 at 0x15bc74
 *   fpu: float literal 0x40c90fdb at 0x15bc94
 *   fpu: mtc1 reinterprets v0 at 0x15bcb8
 *   fpu: mov.s at 0x15bcdc is a float copy
 *   fpu: mov.s at 0x15bce0 is a float copy
 *   fpu: mov.s at 0x15bce8 is a float copy
 *   fpu: mov.s at 0x15bcec is a float copy
 *   fpu: mov.s at 0x15bcf4 is a float copy
 *   fpu: mov.s at 0x15bcf8 is a float copy
 *   fpu: mov.s at 0x15bd00 is a float copy
 *   fpu: mov.s at 0x15bd04 is a float copy
 *   fpu: mov.s at 0x15bd0c is a float copy
 *   fpu: mov.s at 0x15bd10 is a float copy
 *   fpu: mov.s at 0x15bd18 is a float copy
 *   stack: address of the slot at 0xc0 escapes at 0x15be28
 *   stack: address of the slot at 0x100 escapes at 0x15be28
 *   stack: address of the slot at 0xc0 escapes at 0x15be28
 *   stack: 12-byte aggregate copy in 4-byte chunks at 0x15be20
 *   cfg: loop body is not one contiguous region: .L0015BB70
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void sceVu0MulMatrix(void *, void *, void *);
#ifndef HMD_DRAW_STRUCTS_DEFINED
#define HMD_DRAW_STRUCTS_DEFINED
struct HmdVtx { float x; float y; float z; float w; };
struct HmdMdl { u8 pad0[0x4c]; struct HmdVtx *pVertex; u8 pad1[0x0c]; u8 *pColor; };
struct HmdPrim { s16 i0; s16 pad0; s16 i1; s16 pad1; s16 i2; u8 pad2[8]; u8 mat; u8 pad3; };
#endif

extern u32 lpMdlPacketMem;
extern u8 *lpDrawMng;

struct dw_561015_fields;
struct dw_570778_fields;
#ifndef PROTO_DW_569360_FIELDS
#define PROTO_DW_569360_FIELDS
struct dw_569360_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_566998_FIELDS
#define PROTO_DW_566998_FIELDS
struct dw_566998_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_566675_FIELDS
#define PROTO_DW_566675_FIELDS
struct dw_566675_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_561015_fields *lpMdl; };
#endif
#ifndef PROTO_DW_561015_FIELDS
#define PROTO_DW_561015_FIELDS
struct dw_561015_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_570778_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_561015_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_569360_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_566998_fields flags; unsigned char _pad1[3]; struct dw_566675_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_572214_FIELDS
#define PROTO_DW_572214_FIELDS
struct dw_572214_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_570778_FIELDS
#define PROTO_DW_570778_FIELDS
struct dw_570778_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_572214_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_570778_FIELDS_LPHMDHEAD_51419E4B_DEFINED
#define DCOMP_OFF_STRUCT_DW_570778_FIELDS_LPHMDHEAD_51419E4B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_570778_FIELDS_LPHMDHEAD_51419E4B = (int)&(((struct dw_570778_fields *)0)->lpHmdHead) - 0 };
#endif


extern void sceVu0CopyVector(void *,void *);
extern void sceVu0SubVector(void *,void *,void *);
extern int fsHit_GetHitPolygonLine(void *,void *,void *);
extern u8 gHitLine[];


static u32 gHitMdlMng;
/* CheckHitMapLine @ 0x15C150 .. 0x15CC4C (0xafc bytes, frame 0x200) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x1b0 escapes at 0x15d7f8
 *   stack: address of the slot at 0x1c8 escapes at 0x15d840
 *   stack: address of the slot at 0x134 escapes at 0x15d878
 *   stack: address of the slot at 0x138 escapes at 0x15d878
 *   stack: address of the slot at 0x13c escapes at 0x15d878
 *   fpu: float literal 0x40490fdb at 0x15d8b8
 *   fpu: float literal 0x00000000 at 0x15d8bc
 *   fpu: float literal 0x40c90fdb at 0x15d8dc
 *   fpu: mtc1 reinterprets v0 at 0x15d900
 *   fpu: float literal 0x40490fdb at 0x15d92c
 *   fpu: float literal 0x00000000 at 0x15d930
 *   fpu: float literal 0x40c90fdb at 0x15d950
 *   fpu: mtc1 reinterprets v0 at 0x15d974
 *   fpu: float literal 0x40490fdb at 0x15d9a0
 *   fpu: float literal 0x00000000 at 0x15d9a4
 *   fpu: float literal 0x40c90fdb at 0x15d9c4
 *   fpu: mtc1 reinterprets v0 at 0x15d9e8
 *   fpu: mov.s at 0x15da0c is a float copy
 *   fpu: mov.s at 0x15da10 is a float copy
 *   fpu: mov.s at 0x15da18 is a float copy
 *   fpu: mov.s at 0x15da1c is a float copy
 *   fpu: mov.s at 0x15da24 is a float copy
 *   fpu: mov.s at 0x15da28 is a float copy
 *   fpu: mov.s at 0x15da30 is a float copy
 *   fpu: mov.s at 0x15da34 is a float copy
 *   fpu: mov.s at 0x15da3c is a float copy
 *   fpu: mov.s at 0x15da40 is a float copy
 *   fpu: mov.s at 0x15da48 is a float copy
 *   stack: address of the slot at 0x1ac escapes at 0x15db80
 *   fpu: float literal 0x40490fdb at 0x15db98
 *   fpu: float literal 0x00000000 at 0x15db9c
 *   fpu: float literal 0x40c90fdb at 0x15dbbc
 *   fpu: mtc1 reinterprets v0 at 0x15dbe0
 *   fpu: float literal 0x40490fdb at 0x15dc0c
 *   fpu: float literal 0x00000000 at 0x15dc10
 *   fpu: float literal 0x40c90fdb at 0x15dc30
 *   fpu: mtc1 reinterprets v0 at 0x15dc54
 *   fpu: float literal 0x40490fdb at 0x15dc80
 *   fpu: float literal 0x00000000 at 0x15dc84
 *   fpu: float literal 0x40c90fdb at 0x15dca4
 *   fpu: mtc1 reinterprets v0 at 0x15dcc8
 *   fpu: mov.s at 0x15dcec is a float copy
 *   fpu: mov.s at 0x15dcf0 is a float copy
 *   fpu: mov.s at 0x15dcf8 is a float copy
 *   fpu: mov.s at 0x15dcfc is a float copy
 *   fpu: mov.s at 0x15dd04 is a float copy
 *   fpu: mov.s at 0x15dd08 is a float copy
 *   fpu: mov.s at 0x15dd10 is a float copy
 *   fpu: mov.s at 0x15dd14 is a float copy
 *   fpu: mov.s at 0x15dd1c is a float copy
 *   fpu: mov.s at 0x15dd20 is a float copy
 *   fpu: mov.s at 0x15dd28 is a float copy
 *   stack: address of the slot at 0x130 escapes at 0x15de38
 *   stack: address of the slot at 0x170 escapes at 0x15de38
 *   stack: address of the slot at 0x130 escapes at 0x15de38
 *   stack: address of the slot at 0xf0 escapes at 0x15de44
 *   stack: address of the slot at 0x130 escapes at 0x15de44
 *   stack: address of the slot at 0x1b0 escapes at 0x15de54
 *   stack: address of the slot at 0xf0 escapes at 0x15de54
 *   stack: address of the slot at 0x1b0 escapes at 0x15de54
 *   stack: address of the slot at 0x1b0 escapes at 0x15de80
 *   stack: address of the slot at 0x130 escapes at 0x15de80
 *   stack: address of the slot at 0x1b0 escapes at 0x15de80
 *   delay: addiu at 0x15deb8 writes a register its branch at 0x15deb4 reads
 *   stack: 12-byte aggregate copy in 4-byte chunks at 0x15db58
 *   stack: 12-byte aggregate copy in 4-byte chunks at 0x15de30
 *   cfg: loop body is not one contiguous region: .L0015D878
 *   cfg: loop body is not one contiguous region: .L0015DB80
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */


extern void sceVu0InversMatrix(void *, void *);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern u32 MdlMng[];


struct dw_561015_fields;
struct dw_570778_fields;
#ifndef PROTO_DW_569360_FIELDS
#define PROTO_DW_569360_FIELDS
struct dw_569360_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_566998_FIELDS
#define PROTO_DW_566998_FIELDS
struct dw_566998_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_566675_FIELDS
#define PROTO_DW_566675_FIELDS
struct dw_566675_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_561015_fields *lpMdl; };
#endif
#ifndef PROTO_DW_561015_FIELDS
#define PROTO_DW_561015_FIELDS
struct dw_561015_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_570778_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_561015_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_569360_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_566998_fields flags; unsigned char _pad1[3]; struct dw_566675_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_572214_FIELDS
#define PROTO_DW_572214_FIELDS
struct dw_572214_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_570778_FIELDS
#define PROTO_DW_570778_FIELDS
struct dw_570778_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_572214_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_0__AA597FC4_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_0__AA597FC4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_0__AA597FC4 = (int)&(((struct dw_561015_fields *)0)->Ang[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_1__64DAA9BD_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_1__64DAA9BD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_1__64DAA9BD = (int)&(((struct dw_561015_fields *)0)->Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_2__4FC02471_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_2__4FC02471_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_2__4FC02471 = (int)&(((struct dw_561015_fields *)0)->Ang[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_FLAGS_A911C298_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_FLAGS_A911C298_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_FLAGS_A911C298 = (int)&(((struct dw_561015_fields *)0)->Flags) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITHIGH_9413C2EF_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITHIGH_9413C2EF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITHIGH_9413C2EF = (int)&(((struct dw_561015_fields *)0)->HitHigh) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITOFF_18097F10_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITOFF_18097F10_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITOFF_18097F10 = (int)&(((struct dw_561015_fields *)0)->HitOff) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITSIZE_1ABCAEB8_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITSIZE_1ABCAEB8_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITSIZE_1ABCAEB8 = (int)&(((struct dw_561015_fields *)0)->HitSize) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_0__FD72036E_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_0__FD72036E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_0__FD72036E = (int)&(((struct dw_561015_fields *)0)->Pos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_1__01E8F4BC_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_1__01E8F4BC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_1__01E8F4BC = (int)&(((struct dw_561015_fields *)0)->Pos[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_2__BB0DD427_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_2__BB0DD427_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_2__BB0DD427 = (int)&(((struct dw_561015_fields *)0)->Pos[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_0__6F22A097_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_0__6F22A097_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_0__6F22A097 = (int)&(((struct dw_561015_fields *)0)->Scl[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_1__BBF9EFE8_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_1__BBF9EFE8_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_1__BBF9EFE8 = (int)&(((struct dw_561015_fields *)0)->Scl[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_2__5FE8A366_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_2__5FE8A366_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_2__5FE8A366 = (int)&(((struct dw_561015_fields *)0)->Scl[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_BERASE_C3198934_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_BERASE_C3198934_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_BERASE_C3198934 = (int)&(((struct dw_561015_fields *)0)->bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_BUSE_DDFC874D_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_BUSE_DDFC874D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_BUSE_DDFC874D = (int)&(((struct dw_561015_fields *)0)->bUse) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_LPMDLDATA_3B0FE35B_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_LPMDLDATA_3B0FE35B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_LPMDLDATA_3B0FE35B = (int)&(((struct dw_561015_fields *)0)->lpMdlData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_570778_FIELDS_LPHMDHEAD_51419E4B_DEFINED
#define DCOMP_OFF_STRUCT_DW_570778_FIELDS_LPHMDHEAD_51419E4B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_570778_FIELDS_LPHMDHEAD_51419E4B = (int)&(((struct dw_570778_fields *)0)->lpHmdHead) - 0 };
#endif
#ifndef HM_MAKE_MATRIX_DEFINED
#define HM_MAKE_MATRIX_DEFINED
static inline void HmMakeMatrix(float (*m)[4], float *scl, float *ang, float *pos) {
    float sinX, cosX, angleZ, angleX, angleY;
    float sinZ, cosZ, sinY;
    float f4, f3, f2, f1, f0;
    {
        float shifted;
        float angle;
        angle = ang[0];
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
        angle = ang[1];
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
        angle = ang[2];
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
    m[0][0] = (cosZ * (scl[0] * f0));
    f2 = (sinY * sinZ);
    m[0][1] = (scl[0] * sinZ);
    f4 = ((float)(f0 * sinX) + (cosX * f2));
    f1 = ((f0 * cosX) - (sinX * f2));
    m[0][2] = (cosZ * (scl[0] * (-sinY)));
    ((u32 *)m)[3] = 0;
    m[1][0] = (scl[1] * ((sinY * sinX) - (cosX * f3)));
    m[1][1] = (cosX * (scl[1] * cosZ));
    m[1][2] = (scl[1] * f4);
    ((u32 *)m)[7] = 0;
    m[2][0] = (scl[2] * ((float)(sinY * cosX) + (sinX * f3)));
    m[2][1] = (sinX * (scl[2] * (-cosZ)));
    m[2][2] = (scl[2] * f1);
    ((u32 *)m)[11] = 0;
    m[3][0] = pos[0];
    m[3][1] = pos[1];
    m[3][2] = pos[2];
    ((u32 *)m)[15] = 0x3f800000;
}
#endif




extern void sceVu0Normalize(void *, void *);


#ifndef HM_LINE_STRUCTS
#define HM_LINE_STRUCTS
struct HmVec4 { float x; float y; float z; unsigned char a; unsigned char b; unsigned char c; unsigned char d; };
struct HmLineBox { struct HmVec4 Min; struct HmVec4 Max; struct HmVec4 Center; float Rxyz; float Rxz; float ZeroRxyz; float ZeroRxz; };
struct HmLine { float Pos[4]; float Vec[4]; };
#endif


/* CheckHitMapLineGetNormal @ 0x15CC50 .. 0x15CCC0 (0x70 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return float vs inferred void
 */

extern void * memset(void *, int, unsigned int);
float CheckHitMapLine(float (*lpPos)[4], float (*lpVec)[4]);
extern u8 gHitLine[];

/* InitHitLine @ 0x15CCC0 .. 0x15CCCC (0xc bytes) */

extern u8 gHitLine[];

/* CheckHitFloor @ 0x15CCD0 .. 0x15CF48 (0x278 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x15cce8
 *   fpu: float literal 0x00000000 at 0x15cd18
 *   fpu: float literal 0x00000000 at 0x15cd38
 *   fpu: float literal 0x00000000 at 0x15cd70
 *   delay: addiu at 0x15ce58 writes a register its branch at 0x15ce54 reads
 *   delay: addiu at 0x15ce6c writes a register its branch at 0x15ce68 reads
 *   delay: addiu at 0x15ce80 writes a register its branch at 0x15ce7c reads
 *   delay: addiu at 0x15ce94 writes a register its branch at 0x15ce90 reads
 *   delay: addiu at 0x15cea8 writes a register its branch at 0x15cea4 reads
 *   cfg: kept branch: 0x15cd0c if (..) goto .L0015CD58
 *   cfg: kept branch: 0x15cd2c if (..) goto .L0015CD58
 *   cfg: kept branch: 0x15cd38 if (..) goto .L0015CD60
 *   cfg: kept branch: 0x15cd4c if (..) goto .L0015CD60
 *   cfg: kept goto: 0x15cd58 -> .L0015CF40
 *   cfg: kept goto: 0x15cf28 -> .L0015CF40
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

#ifndef PROTO_DW_557316_FIELDS
#define PROTO_DW_557316_FIELDS
struct dw_557316_fields { float P1[4]; float P2[4]; float P3[4]; float V12[4]; float V13[4]; float N[4]; };
#endif


extern float sqrtf(float);




extern void sceVu0ScaleVectorXYZ(void *,void *,float);
extern void sceVu0AddVector(void *,void *,void *);
static unsigned int CheckHitFloor(void *,void *,unsigned char);
static unsigned int CheckHitWall(void *,void *,unsigned char);


/* CheckHitMap @ 0x15D7A0 .. 0x15DF80 (0x7e0 bytes, frame 0x1d0) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x1b0 escapes at 0x15d7f8
 *   stack: address of the slot at 0x1c8 escapes at 0x15d840
 *   stack: address of the slot at 0x134 escapes at 0x15d878
 *   stack: address of the slot at 0x138 escapes at 0x15d878
 *   stack: address of the slot at 0x13c escapes at 0x15d878
 *   fpu: float literal 0x40490fdb at 0x15d8b8
 *   fpu: float literal 0x00000000 at 0x15d8bc
 *   fpu: float literal 0x40c90fdb at 0x15d8dc
 *   fpu: mtc1 reinterprets v0 at 0x15d900
 *   fpu: float literal 0x40490fdb at 0x15d92c
 *   fpu: float literal 0x00000000 at 0x15d930
 *   fpu: float literal 0x40c90fdb at 0x15d950
 *   fpu: mtc1 reinterprets v0 at 0x15d974
 *   fpu: float literal 0x40490fdb at 0x15d9a0
 *   fpu: float literal 0x00000000 at 0x15d9a4
 *   fpu: float literal 0x40c90fdb at 0x15d9c4
 *   fpu: mtc1 reinterprets v0 at 0x15d9e8
 *   fpu: mov.s at 0x15da0c is a float copy
 *   fpu: mov.s at 0x15da10 is a float copy
 *   fpu: mov.s at 0x15da18 is a float copy
 *   fpu: mov.s at 0x15da1c is a float copy
 *   fpu: mov.s at 0x15da24 is a float copy
 *   fpu: mov.s at 0x15da28 is a float copy
 *   fpu: mov.s at 0x15da30 is a float copy
 *   fpu: mov.s at 0x15da34 is a float copy
 *   fpu: mov.s at 0x15da3c is a float copy
 *   fpu: mov.s at 0x15da40 is a float copy
 *   fpu: mov.s at 0x15da48 is a float copy
 *   stack: address of the slot at 0x1ac escapes at 0x15db80
 *   fpu: float literal 0x40490fdb at 0x15db98
 *   fpu: float literal 0x00000000 at 0x15db9c
 *   fpu: float literal 0x40c90fdb at 0x15dbbc
 *   fpu: mtc1 reinterprets v0 at 0x15dbe0
 *   fpu: float literal 0x40490fdb at 0x15dc0c
 *   fpu: float literal 0x00000000 at 0x15dc10
 *   fpu: float literal 0x40c90fdb at 0x15dc30
 *   fpu: mtc1 reinterprets v0 at 0x15dc54
 *   fpu: float literal 0x40490fdb at 0x15dc80
 *   fpu: float literal 0x00000000 at 0x15dc84
 *   fpu: float literal 0x40c90fdb at 0x15dca4
 *   fpu: mtc1 reinterprets v0 at 0x15dcc8
 *   fpu: mov.s at 0x15dcec is a float copy
 *   fpu: mov.s at 0x15dcf0 is a float copy
 *   fpu: mov.s at 0x15dcf8 is a float copy
 *   fpu: mov.s at 0x15dcfc is a float copy
 *   fpu: mov.s at 0x15dd04 is a float copy
 *   fpu: mov.s at 0x15dd08 is a float copy
 *   fpu: mov.s at 0x15dd10 is a float copy
 *   fpu: mov.s at 0x15dd14 is a float copy
 *   fpu: mov.s at 0x15dd1c is a float copy
 *   fpu: mov.s at 0x15dd20 is a float copy
 *   fpu: mov.s at 0x15dd28 is a float copy
 *   stack: address of the slot at 0x130 escapes at 0x15de38
 *   stack: address of the slot at 0x170 escapes at 0x15de38
 *   stack: address of the slot at 0x130 escapes at 0x15de38
 *   stack: address of the slot at 0xf0 escapes at 0x15de44
 *   stack: address of the slot at 0x130 escapes at 0x15de44
 *   stack: address of the slot at 0x1b0 escapes at 0x15de54
 *   stack: address of the slot at 0xf0 escapes at 0x15de54
 *   stack: address of the slot at 0x1b0 escapes at 0x15de54
 *   stack: address of the slot at 0x1b0 escapes at 0x15de80
 *   stack: address of the slot at 0x130 escapes at 0x15de80
 *   stack: address of the slot at 0x1b0 escapes at 0x15de80
 *   delay: addiu at 0x15deb8 writes a register its branch at 0x15deb4 reads
 *   stack: 12-byte aggregate copy in 4-byte chunks at 0x15db58
 *   stack: 12-byte aggregate copy in 4-byte chunks at 0x15de30
 *   cfg: loop body is not one contiguous region: .L0015D878
 *   cfg: loop body is not one contiguous region: .L0015DB80
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */







struct dw_561015_fields;
struct dw_570778_fields;
#ifndef PROTO_DW_569360_FIELDS
#define PROTO_DW_569360_FIELDS
struct dw_569360_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_566998_FIELDS
#define PROTO_DW_566998_FIELDS
struct dw_566998_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_566675_FIELDS
#define PROTO_DW_566675_FIELDS
struct dw_566675_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_561015_fields *lpMdl; };
#endif
#ifndef PROTO_DW_561015_FIELDS
#define PROTO_DW_561015_FIELDS
struct dw_561015_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_570778_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_561015_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_569360_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_566998_fields flags; unsigned char _pad1[3]; struct dw_566675_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_572214_FIELDS
#define PROTO_DW_572214_FIELDS
struct dw_572214_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_570778_FIELDS
#define PROTO_DW_570778_FIELDS
struct dw_570778_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_572214_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_0__AA597FC4_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_0__AA597FC4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_0__AA597FC4 = (int)&(((struct dw_561015_fields *)0)->Ang[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_1__64DAA9BD_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_1__64DAA9BD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_1__64DAA9BD = (int)&(((struct dw_561015_fields *)0)->Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_2__4FC02471_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_2__4FC02471_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_ANG_2__4FC02471 = (int)&(((struct dw_561015_fields *)0)->Ang[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_FLAGS_A911C298_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_FLAGS_A911C298_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_FLAGS_A911C298 = (int)&(((struct dw_561015_fields *)0)->Flags) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITHIGH_9413C2EF_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITHIGH_9413C2EF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITHIGH_9413C2EF = (int)&(((struct dw_561015_fields *)0)->HitHigh) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITOFF_18097F10_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITOFF_18097F10_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITOFF_18097F10 = (int)&(((struct dw_561015_fields *)0)->HitOff) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITSIZE_1ABCAEB8_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITSIZE_1ABCAEB8_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_HITSIZE_1ABCAEB8 = (int)&(((struct dw_561015_fields *)0)->HitSize) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_0__FD72036E_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_0__FD72036E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_0__FD72036E = (int)&(((struct dw_561015_fields *)0)->Pos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_1__01E8F4BC_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_1__01E8F4BC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_1__01E8F4BC = (int)&(((struct dw_561015_fields *)0)->Pos[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_2__BB0DD427_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_2__BB0DD427_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_POS_2__BB0DD427 = (int)&(((struct dw_561015_fields *)0)->Pos[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_0__6F22A097_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_0__6F22A097_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_0__6F22A097 = (int)&(((struct dw_561015_fields *)0)->Scl[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_1__BBF9EFE8_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_1__BBF9EFE8_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_1__BBF9EFE8 = (int)&(((struct dw_561015_fields *)0)->Scl[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_2__5FE8A366_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_2__5FE8A366_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_SCL_2__5FE8A366 = (int)&(((struct dw_561015_fields *)0)->Scl[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_BERASE_C3198934_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_BERASE_C3198934_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_BERASE_C3198934 = (int)&(((struct dw_561015_fields *)0)->bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_BUSE_DDFC874D_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_BUSE_DDFC874D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_BUSE_DDFC874D = (int)&(((struct dw_561015_fields *)0)->bUse) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_561015_FIELDS_LPMDLDATA_3B0FE35B_DEFINED
#define DCOMP_OFF_STRUCT_DW_561015_FIELDS_LPMDLDATA_3B0FE35B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_561015_FIELDS_LPMDLDATA_3B0FE35B = (int)&(((struct dw_561015_fields *)0)->lpMdlData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_570778_FIELDS_LPHMDHEAD_51419E4B_DEFINED
#define DCOMP_OFF_STRUCT_DW_570778_FIELDS_LPHMDHEAD_51419E4B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_570778_FIELDS_LPHMDHEAD_51419E4B = (int)&(((struct dw_570778_fields *)0)->lpHmdHead) - 0 };
#endif
#ifndef HM_MAKE_MATRIX_DEFINED
#define HM_MAKE_MATRIX_DEFINED
static inline void HmMakeMatrix(float (*m)[4], float *scl, float *ang, float *pos) {
    float sinX, cosX, angleZ, angleX, angleY;
    float sinZ, cosZ, sinY;
    float f4, f3, f2, f1, f0;
    {
        float shifted;
        float angle;
        angle = ang[0];
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
        angle = ang[1];
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
        angle = ang[2];
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
    m[0][0] = (cosZ * (scl[0] * f0));
    f2 = (sinY * sinZ);
    m[0][1] = (scl[0] * sinZ);
    f4 = ((float)(f0 * sinX) + (cosX * f2));
    f1 = ((f0 * cosX) - (sinX * f2));
    m[0][2] = (cosZ * (scl[0] * (-sinY)));
    ((u32 *)m)[3] = 0;
    m[1][0] = (scl[1] * ((sinY * sinX) - (cosX * f3)));
    m[1][1] = (cosX * (scl[1] * cosZ));
    m[1][2] = (scl[1] * f4);
    ((u32 *)m)[7] = 0;
    m[2][0] = (scl[2] * ((float)(sinY * cosX) + (sinX * f3)));
    m[2][1] = (sinX * (scl[2] * (-cosZ)));
    m[2][2] = (scl[2] * f1);
    ((u32 *)m)[11] = 0;
    m[3][0] = pos[0];
    m[3][1] = pos[1];
    m[3][2] = pos[2];
    ((u32 *)m)[15] = 0x3f800000;
}
#endif


/* CheckHitMapGetMdlMng @ 0x15DF80 .. 0x15DFAC (0x2c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

unsigned int CheckHitMap(struct dw_561015_fields *lpMdlMng_);
extern u32 gHitMdlMng;

/* SetHdlData @ 0x15E290 .. 0x15E2DC (0x4c bytes, frame 0x10) */

void RemapHmdData(void *a0 /* r4 */);
extern u32 MdlData[];
static u8 gHitLine[0x10];
static u32 gHitMdlMng;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetHdlData(s32 a0 , u32 *a1 );
void RemapHmdData(void *a0 );
void RemapHmdPrim(void *a0 , unsigned int a1 );
unsigned int CheckHitMapGetMdlMng(void *a0 , void *a1 );
unsigned int CheckHitMap(struct dw_561015_fields *lpMdlMng_);
unsigned int CheckHitHmdPrimList(void *node,void *positions,void *normals,void *materials,void *bounds);
static unsigned int CheckHitWall(void *lpMapHit_, void *lpPlayerHit_, unsigned char Mode);
static unsigned int CheckHitFloor(void *a0, void *a1, unsigned char Mode);
void InitHitLine(void);
float CheckHitMapLineGetNormal(void *a0 , void *a1 , void *a2 );
float CheckHitMapLine(float (*lpPos)[4], float (*lpVec)[4]);
float CheckHitLineHmdPrimList(void *node,void *positions,void *normals,void *materials,void *line,void *bounds);
void DrawHmdModel(struct dw_561015_fields *lpMdlMng, unsigned int Mode);
unsigned int * DrawHmdPrimListDirect(void *node, struct HmdMdl *model, void *matrix, unsigned int *packet, unsigned int mode);
static unsigned int * MakePolygonPacket(void *a0 , void *a1 , void *a2 , void *a3 , unsigned int *t0 , unsigned int t1 );


void SetHdlData(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    s32 a2;
    u32 v1;
    u8 *v1_address; // v1
    u32 v0;

    a2 = (u32)a0 * (u32)(0xc);
    a0 = (u32)a0 * (u32)(0xd);
    v1 = (u32)MdlData;
    v1_address = (u8 *)((u8 *)MdlData + (u32)((u32)a0 << 7));
    if ((u32)a1 != 0) {
        v0 = (s32)a1[4];
        *(u32 *)(v1_address + 0x18) = v0;
        RemapHmdData((void *)*(s32 *)(v1_address + 0x18));
    }
    return;
}

/* RemapHmdData @ 0x15E140 .. 0x15E290 (0x150 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0015E198
 *   cfg: loop body is not one contiguous region: .L0015E230
 *   v1#3 is the pointer held in @11820+0x24
 *   declaration vs inferred signature: return void vs inferred u32
 */

void RemapHmdData(void *a0 /* r4 */) {
    u8 *s2;
    u8 *a1;
    u8 *s1;
    s32 s0;
    u32 v1;
    u32 v0;

    v1 = *(s32 *)(((u8 *)a0 + 0x20));
    s2 = (u8 *)a0;
    if (v1 != 0) {
        *(u32 *)(s2 + 0x20) = (s32)(s2 + v1);
    }
    v1 = *(s32 *)(s2 + 0x24);
    if (v1 != 0) {
        *(u32 *)(s2 + 0x24) = (s32)(s2 + v1);
    }
    v1 = *(s32 *)(s2 + 0x10);
    s1 = (u8 *)*(s32 *)(s2 + 0x24);
    s0 = 0;
    if ((u8 *)0 < (u8 *)v1) {
        do {
            v0 = *(s32 *)(s1 + 0x44);
            if (v0 != 0) {
                *(u32 *)(s1 + 0x44) = (s32)(s2 + v0);
            }
            v0 = *(s32 *)(s1 + 0x4c);
            if (v0 != 0) {
                *(u32 *)(s1 + 0x4c) = (s32)(s2 + v0);
            }
            v0 = *(s32 *)(s1 + 0x54);
            if (v0 != 0) {
                *(u32 *)(s1 + 0x54) = (s32)(s2 + v0);
            }
            v0 = *(s32 *)(s1 + 0x5c);
            if (v0 != 0) {
                *(u32 *)(s1 + 0x5c) = (s32)(s2 + v0);
            }
            a0 = (void *)*(s32 *)(s1 + 0x44);
            RemapHmdPrim(a0, (unsigned int)(u32 *)s2);
            v1 = *(s32 *)(s2 + 0x10);
            s0 = s0 + 1;
            v1 = (u32)s0 < v1;
            s1 = (u8 *)(s1 + 0x60);
        } while (v1 != 0);
    }
    v1 = *(s32 *)(s2 + 0xc);
    a1 = (u8 *)*(s32 *)(s2 + 0x20);
    a0 = (void *)0;
    if ((u8 *)0 < (u8 *)v1) {
        do {
            v1 = *(s32 *)a1;
            if (v1 != 0) {
                *(u32 *)a1 = (s32)(s2 + v1);
            }
            v1 = *(s32 *)(a1 + 4);
            if (v1 != 0) {
                *(u32 *)(a1 + 4) = (s32)(s2 + v1);
            }
            v1 = *(s32 *)(s2 + 0xc);
            a0 = (void *)((u8 *)a0 + 1);
            v1 = (u32)(s32)a0 < v1;
            a1 = (u8 *)(a1 + 8);
        } while (v1 != 0);
    }
    return;
}

/* RemapHmdPrim @ 0x15DFB0 .. 0x15E140 (0x190 bytes, frame 0x40) */

void RemapHmdPrim(void *a0 /* r4 */, unsigned int a1 /* r5 */) {
    u8 *s2;
    s32 s1;
    u32 v1;
    u8 *s0;

    s2 = (u8 *)a0;
    s1 = a1;
    if ((u32)s2 != 0) {
        v1 = *(s32 *)(s2 + 4);
        if (v1 != 0) {
            *(u32 *)(s2 + 4) = s1 + v1;
        }
        v1 = *(s32 *)(s2 + 8);
        if (v1 != 0) {
            *(u32 *)(s2 + 8) = s1 + v1;
        }
        v1 = *(s32 *)(s2 + 0xc);
        if (v1 != 0) {
            *(u32 *)(s2 + 0xc) = s1 + v1;
        }
        s0 = (u8 *)*(s32 *)(s2 + 4);
        if ((u32)(s32)s0 != 0 && (u32)(s32)s0 != 0) {
            v1 = *(s32 *)(s0 + 4);
            if (v1 != 0) {
                *(u32 *)(s0 + 4) = s1 + v1;
            }
            v1 = *(s32 *)(s0 + 8);
            if (v1 != 0) {
                *(u32 *)(s0 + 8) = s1 + v1;
            }
            v1 = *(s32 *)(s0 + 0xc);
            if (v1 != 0) {
                *(u32 *)(s0 + 0xc) = s1 + v1;
            }
            a0 = (void *)*(s32 *)(s0 + 4);
            a1 = s1;
            if ((u32)(s32)a0 != 0) {
                RemapHmdPrim(a0, a1);
            }
            a0 = (void *)*(s32 *)(s0 + 8);
            a1 = s1;
            if ((u32)(s32)a0 != 0) {
                RemapHmdPrim(a0, a1);
            }
        }
        s0 = (u8 *)*(s32 *)(s2 + 8);
        if ((u32)(s32)s0 != 0 && (u32)(s32)s0 != 0) {
            v1 = *(s32 *)(s0 + 4);
            if (v1 != 0) {
                *(u32 *)(s0 + 4) = s1 + v1;
            }
            v1 = *(s32 *)(s0 + 8);
            if (v1 != 0) {
                *(u32 *)(s0 + 8) = s1 + v1;
            }
            v1 = *(s32 *)(s0 + 0xc);
            if (v1 != 0) {
                *(u32 *)(s0 + 0xc) = s1 + v1;
            }
            a0 = (void *)*(s32 *)(s0 + 4);
            a1 = s1;
            if ((u32)(s32)a0 != 0) {
                RemapHmdPrim(a0, a1);
            }
            a0 = (void *)*(s32 *)(s0 + 8);
            a1 = s1;
            if ((u32)(s32)a0 != 0) {
                RemapHmdPrim(a0, a1);
            }
        }
    }
    return;
}

/* CheckHitMapGetMdlMng @ 0x15DF80 .. 0x15DFAC (0x2c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */
unsigned int CheckHitMapGetMdlMng(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 v1;
    unsigned int v0;

    v0 = CheckHitMap((struct dw_561015_fields *)a0);
    v1 = gHitMdlMng;
    *(u32 *)a1 = v1;
    return v0;
}

unsigned int CheckHitMap(struct dw_561015_fields *lpMdlMng_) {
    struct dw_561015_fields *lpMdlMng = lpMdlMng_;
    int i;
    int j;
    struct dw_561015_fields *lpMapMdlMng;
    u8 *lpHmdHead;
    u8 *lpHmdObj;
    float PlayerHit[8];
    float w_mat[4][4];
    float l_mat[4][4];
    float i_mat[4][4];
    unsigned int Ret;
    unsigned int Wk;

    lpMapMdlMng = (struct dw_561015_fields *)MdlMng;
    Ret = 0;
    sceVu0CopyVector(PlayerHit, lpMdlMng->Pos);
    PlayerHit[4] = lpMdlMng->HitHigh;
    PlayerHit[5] = lpMdlMng->HitSize;
    ((u8 *)PlayerHit)[24] = 0;
    if (lpMdlMng->Flags & 0x10) {
        ((u8 *)PlayerHit)[24] |= 1;
    }
    if (lpMdlMng->Flags & 0x20) {
        ((u8 *)PlayerHit)[24] |= 2;
    }
    gHitMdlMng = 0;
    for (i = 0; i < 0x90; i++, lpMapMdlMng++) {
        if (lpMapMdlMng->bUse != 0 && lpMapMdlMng->lpMdlData->lpHmdHead != 0) {
            if (lpMapMdlMng->HitOff == 0 && lpMapMdlMng != lpMdlMng) {
                HmMakeMatrix(w_mat, lpMapMdlMng->Scl, lpMapMdlMng->Ang, lpMapMdlMng->Pos);
                lpHmdHead = (u8 *)lpMapMdlMng->lpMdlData->lpHmdHead;
                lpHmdObj = *(u8 **)(lpHmdHead + 0x24);
                Wk = 0;
                for (j = 0; j < *(s32 *)(lpHmdHead + 0x10); j++, lpHmdObj += 0x60) {
                    if (*(s32 *)(lpHmdObj + 0x44) != 0) {
                        HmMakeMatrix(l_mat, (float *)(lpHmdObj + 0x20), (float *)(lpHmdObj + 0x10), (float *)lpHmdObj);
                        sceVu0MulMatrix(l_mat, w_mat, l_mat);
                        sceVu0InversMatrix(i_mat, l_mat);
                        sceVu0ApplyMatrix(PlayerHit, i_mat, PlayerHit);
                        Wk |= CheckHitHmdPrimList((void *)*(s32 *)(lpHmdObj + 0x44), (void *)*(s32 *)(lpHmdObj + 0x4c), (void *)*(s32 *)(lpHmdObj + 0x54), (void *)*(s32 *)(lpHmdObj + 0x5c), PlayerHit);
                        sceVu0ApplyMatrix(PlayerHit, l_mat, PlayerHit);
                    }
                }
                if (Wk & 1) {
                    gHitMdlMng = (u32)lpMapMdlMng;
                }
                if (lpMapMdlMng->bErase != 0) {
                    Wk &= -0x1001;
                }
                Ret |= Wk;
            }
        }
    }
    if (Ret & 1) {
        lpMdlMng->Pos[1] = PlayerHit[1];
    }
    if (Ret & 0x10000) {
        lpMdlMng->Pos[0] = PlayerHit[0];
        lpMdlMng->Pos[2] = PlayerHit[2];
    }
    return Ret;
}
unsigned int CheckHitHmdPrimList(void *node,void *positions,void *normals,void *materials,void *bounds) {
    float *other;
    float *third;
    u8 *savedNode;
    u32 savedPositions;
    u8 *savedBounds;
    float radius,coordinate,limit,value;
    u32 result;
    u8 *primitive;
    int index;
    u8 *material;
    float polygon[6][4] __attribute__((aligned(16)));
    float center[4] __attribute__((aligned(16)));
    float temporary[4] __attribute__((aligned(16)));
    savedNode=(u8 *)node; savedPositions=(u32)positions; savedBounds=(u8 *)bounds;
    radius=*(float *)((u8 *)bounds+20);
    coordinate=*(float *)bounds;
    limit=*(float *)((u8 *)node+32);
    value=coordinate-radius;
    result=0;
    if(!(limit<value)) {
     limit=*(float *)(savedNode+16); value=coordinate+radius;
     if(limit<=value) {
      coordinate=*(float *)(savedBounds+8); limit=*(float *)(savedNode+40); value=coordinate-radius;
      if(!(limit<value)) {
       limit=*(float *)(savedNode+24); value=coordinate+radius;
       if(limit<=value) {
        coordinate=*(float *)(savedBounds+4); limit=*(float *)(savedNode+36); value=coordinate-*(float *)(savedBounds+16);
        if(!(limit<value)) {
         value=*(float *)(savedNode+20);
         if(value<=coordinate) {
          primitive=savedNode+80; index=0;
          if(0<(int)*(u16 *)savedNode) {
           other=polygon[1]; third=polygon[2];
           do {
            u32 type;
            material=(u8 *)materials+*(u8 *)(primitive+18)*4;
            type=material[2];
            if(type!=100) {
             u32 flags=savedBounds[24];
             if(flags&1) { if(type==150) goto next; }
             else { if(type==50) goto next; }
             {
              if(!(flags&2)||material[1]!=0) {
               sceVu0CopyVector(polygon[0],(void *)(savedPositions+(*(s16 *)primitive<<4)));
               sceVu0CopyVector(other,(void *)(savedPositions+(*(s16 *)(primitive+4)<<4)));
               sceVu0CopyVector(third,(void *)(savedPositions+(*(s16 *)(primitive+8)<<4)));
               sceVu0CopyVector(polygon[5],(void *)((u32)normals+(*(s16 *)(primitive+16)<<4)));
               sceVu0SubVector(polygon[3],other,polygon[0]);
               sceVu0SubVector(polygon[4],third,polygon[0]);
               {
               u8 kind=material[0];
               if(kind==0) {
                center[0]=(third[0]+(polygon[0][0]+other[0]))/3.0f;
                center[1]=(polygon[2][1]+(polygon[0][1]+polygon[1][1]))/3.0f;
                center[2]=(polygon[2][2]+(polygon[0][2]+polygon[1][2]))/3.0f;
                sceVu0ScaleVectorXYZ(center,center,-0.049999952f);
                sceVu0ScaleVectorXYZ(temporary,polygon[0],1.05f);
                sceVu0AddVector(polygon[0],center,temporary);
                sceVu0ScaleVectorXYZ(temporary,other,1.05f);
                sceVu0AddVector(other,center,temporary);
                sceVu0ScaleVectorXYZ(temporary,third,1.05f);
                sceVu0AddVector(third,center,temporary);
                result|=CheckHitFloor(polygon[0],savedBounds,material[1]);
               } else if(material[1]==0) {
                result|=CheckHitWall(polygon[0],savedBounds,kind);
               }
               }
              }
             }
            }
            next:;
            index++; primitive+=20;
           } while(index<(int)*(u16 *)savedNode);
          }
          node=*(void **)(savedNode+4);
          if((u32)node!=0) result|=CheckHitHmdPrimList(node,(void *)savedPositions,normals,materials,savedBounds);
         }
        }
       }
      }
     }
    }
    node=*(void **)(savedNode+8);
    if((u32)node!=0) result|=CheckHitHmdPrimList(node,(void *)savedPositions,normals,materials,savedBounds);
    return result;
}

static unsigned int CheckHitWall(void *lpMapHit_, void *lpPlayerHit_, unsigned char Mode) {
    float *m = (float *)lpMapHit_;
    float *p = (float *)lpPlayerHit_;
    float tt;
    float pos[3][3];
    float dist2[3];
    int near;
    int i;
    float dx0, dz0, dx1, dz1, dx2, dz2;
    float px0, pz0, px1, pz1, px2, pz2;
    float ax, az, ay;
    float qx, qz;
    float minDist;
    float *pp;
    float *py;
    float *pz;

    if (m[1] < p[1] || m[5] < p[1] || m[9] < p[1]) {
        if (!(m[1] <= p[1] - p[4] && m[5] <= p[1] - p[4] && m[9] <= p[1] - p[4])) {
            goto main;
        }
    }
    return 0;
main:
    dx0 = m[4] - m[0];
    dz0 = m[6] - m[2];
    dx1 = m[8] - m[4];
    dz1 = m[10] - m[6];
    dx2 = m[0] - m[8];
    dz2 = m[2] - m[10];
    px0 = p[0] - m[0];
    pz0 = p[2] - m[2];
    px1 = p[0] - m[4];
    pz1 = p[2] - m[6];
    px2 = p[0] - m[8];
    pz2 = p[2] - m[10];
    tt = 0.0f;
    if (!(0.0f == dx0 && tt == dz0)) {
        tt = (px0 * dx0 + pz0 * dz0) / (dx0 * dx0 + dz0 * dz0);
        if (tt < 0.0f) {
            tt = 0.0f;
        } else if (!(tt <= 1.0f)) {
            tt = 1.0f;
        } else {
            tt = tt;
        }
    }
    pz = &pos[0][2];
    py = &pos[0][1];
    pos[0][0] = m[0] + dx0 * tt;
    *pz = m[2] + dz0 * tt;
    *py = m[1] + tt * (m[5] - m[1]);
    tt = 0.0f;
    if (!(0.0f == dx1 && tt == dz1)) {
        tt = (px1 * dx1 + pz1 * dz1) / (dx1 * dx1 + dz1 * dz1);
        if (tt < 0.0f) {
            tt = 0.0f;
        } else if (!(tt <= 1.0f)) {
            tt = 1.0f;
        } else {
            tt = tt;
        }
    }
    pos[1][0] = m[4] + dx1 * tt;
    pos[1][2] = m[6] + dz1 * tt;
    pos[1][1] = m[5] + tt * (m[9] - m[5]);
    tt = 0.0f;
    if (!(0.0f == dx2 && tt == dz2)) {
        tt = (px2 * dx2 + pz2 * dz2) / (dx2 * dx2 + dz2 * dz2);
        if (tt < 0.0f) {
            tt = 0.0f;
        } else if (!(tt <= 1.0f)) {
            tt = 1.0f;
        } else {
            tt = tt;
        }
    }
    pos[2][0] = m[8] + dx2 * tt;
    pos[2][2] = m[10] + dz2 * tt;
    pos[2][1] = m[9] + tt * (m[1] - m[9]);
    near = -1;
    qx = p[0];
    qz = p[2];
    minDist = 0.99f * (p[5] * p[5]);
    for (i = 0, pp = &pos[0][0]; i < 3; pp += 3, i++) {
        float ex = pp[0] - qx;
        float ez = pp[2] - qz;
        dist2[i] = ex * ex + ez * ez;
        if (!(minDist <= dist2[i])) {
            minDist = dist2[i];
            near = i;
        }
    }
    if (near == -1) {
        return 0;
    }
    if (0.0f != dist2[near]) {
        switch (Mode) {
        case 200:
            return 0x100000;
        case 249:
            return 0x200000;
        case 250:
            return 0x400000;
        default: {
            float ex = p[0] - pos[near][0];
            float ey = p[1] - py[near * 3];
            float d1;
            float d2;
            float ez = p[2] - pz[near * 3];
            if (!(ey <= 0.0f)) {
                d1 = sqrtf(dist2[near]);
                p[0] = p[0] + ex * (p[5] - d1) / d1;
                p[2] = p[2] + ez * (p[5] - d1) / d1;
                break;
            } else {
                d2 = sqrtf(dist2[near]);
                p[0] = p[0] + ex * (p[5] - d2) / d2;
                p[2] = p[2] + ez * (p[5] - d2) / d2;
            }
        }
        }
        return 0x10000;
    }
    return 0;
}

static unsigned int CheckHitFloor(void *a0, void *a1, unsigned char Mode) {
    struct dw_557316_fields *lpMapHit = (struct dw_557316_fields *)a0;
    float *lpPlayerHit = (float *)a1;
    unsigned int Ret;
    float dx12;
    float dz12;
    float dx23;
    float dz23;
    float dx31;
    float dz31;
    float px1;
    float pz1;
    float px2;
    float pz2;
    float px3;
    float pz3;
    float x2;
    float z2;
    float x3;
    float area;
    float c1;
    float c2;
    float c3;
    float y0;
    float h;
    float t0;
    float t1;
    float t2;

    dx12 = (x2 = lpMapHit->P2[0]) - lpMapHit->P1[0];
    dz12 = (z2 = lpMapHit->P2[2]) - lpMapHit->P1[2];
    dx23 = (x3 = lpMapHit->P3[0]) - x2;
    dz23 = lpMapHit->P3[2] - z2;
    dx31 = lpMapHit->P1[0] - x3;
    dz31 = lpMapHit->P1[2] - lpMapHit->P3[2];
    if ((0.0f == dx12 && 0.0f == dz12) || (0.0f == dx23 && 0.0f == dz23) || (0.0f == dx31 && 0.0f == dz31)) {
        return 0;
    }
    px1 = lpPlayerHit[0] - lpMapHit->P1[0];
    pz1 = lpPlayerHit[2] - lpMapHit->P1[2];
    px2 = lpPlayerHit[0] - x2;
    pz2 = lpPlayerHit[2] - z2;
    px3 = lpPlayerHit[0] - x3;
    pz3 = lpPlayerHit[2] - lpMapHit->P3[2];
    area = (dz12 * dx31) - (dx12 * dz31);
    c1 = (dx12 * pz1) - (dz12 * px1);
    if (!(c1 * area < 0.0f)) {
        c2 = (dx23 * pz2) - (dz23 * px2);
        if (!(c2 * ((dz23 * dx12) - (dx23 * dz12)) < 0.0f)) {
            c3 = (dx31 * pz3) - (dz31 * px3);
            if (!(c3 * ((dz31 * dx23) - (dx31 * dz23)) < 0.0f)) {
                if (!(0.0f == area)) {
                    y0 = lpMapHit->P1[1];
                    t0 = (pz1 * dx31) - (px1 * dz31);
                    t1 = lpMapHit->P2[1] - y0;
                    t2 = lpMapHit->P3[1] - y0;
                    h = y0 + (((t1 * t0) + (t2 * c1)) / area);
                    if (h <= lpPlayerHit[1]) {
                        if (!(h < lpPlayerHit[1] - lpPlayerHit[4])) {
                            Ret = 0;
                            switch (Mode) {
                            case 200:
                                return 0x1000;
                            case 201:
                                return 0x2000;
                            case 202:
                                return 0x4000;
                            case 203:
                                return 0x8000;
                            case 204:
                                Ret = 2;
                                break;
                            case 205:
                                Ret = 4;
                                break;
                            case 206:
                                Ret = 8;
                                break;
                            case 207:
                                Ret = 0x10;
                                break;
                            case 208:
                                Ret = 0x20;
                                break;
                            case 210:
                                Ret = 0x40;
                                break;
                            case 220:
                                Ret = 0x80;
                                break;
                            case 230:
                                Ret = 0x100;
                            }
                            lpPlayerHit[1] = h;
                            return Ret | 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void InitHitLine(void) {
    *(u8 *)gHitLine = 0;
    return;
}

float CheckHitMapLineGetNormal(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    u32 s2;
    u32 s1;
    u32 s0;
    float f0;
    void *a0_2;
    void *a1_2;

    s2 = (u32)a0;
    s1 = (u32)a1;
    s0 = (u32)a2;
    memset((void *)s0, 0, 0x20);
    *(u32 *)(gHitLine + 0xc) = s0;
    a0_2 = (void *)s2;
    a1_2 = (void *)s1;
    *(u8 *)gHitLine = 1;
    f0 = CheckHitMapLine(a0_2, a1_2);
    *(u8 *)gHitLine = 0;
    return f0;
}
float CheckHitMapLine(float (*lpPos)[4], float (*lpVec)[4]) {
    int i;
    int j;
    struct dw_561015_fields *lpMapMdlMng;
    u8 *lpHmdHead;
    u8 *lpHmdObj;
    float WkPos[4];
    struct HmLine LineHit;
    struct HmLineBox LineBox;
    float w_mat[4][4];
    float l_mat[4][4];
    float i_mat[4][4];
    float Rate;
    float Ret;
    u8 *lpColor;
    float Normal[4];

    Ret = 1.0f;
    lpMapMdlMng = (struct dw_561015_fields *)MdlMng;
    sceVu0AddVector(WkPos, lpPos, lpVec);
    for (i = 0; i < 0x90; i++, lpMapMdlMng++) {
        if (lpMapMdlMng->bUse != 0 && lpMapMdlMng->lpMdlData->lpHmdHead != 0 && (i < 0x30 || lpMapMdlMng->HitOff == 0)) {
            HmMakeMatrix(w_mat, lpMapMdlMng->Scl, lpMapMdlMng->Ang, lpMapMdlMng->Pos);
            lpHmdHead = (u8 *)lpMapMdlMng->lpMdlData->lpHmdHead;
            lpHmdObj = *(u8 **)(lpHmdHead + 0x24);
            for (j = 0; j < *(s32 *)(lpHmdHead + 0x10); j++, lpHmdObj += 0x60) {
                if (*(s32 *)(lpHmdObj + 0x44) != 0) {
                    HmMakeMatrix(l_mat, (float *)(lpHmdObj + 0x20), (float *)(lpHmdObj + 0x10), (float *)lpHmdObj);
                    sceVu0MulMatrix(l_mat, w_mat, l_mat);
                    sceVu0InversMatrix(i_mat, l_mat);
                    sceVu0ApplyMatrix(LineHit.Pos, i_mat, lpPos);
                    sceVu0ApplyMatrix(LineHit.Vec, i_mat, WkPos);
                    if (LineHit.Pos[0] < LineHit.Vec[0]) {
                        LineBox.Min.x = LineHit.Pos[0];
                        LineBox.Max.x = LineHit.Vec[0];
                    } else {
                        LineBox.Min.x = LineHit.Vec[0];
                        LineBox.Max.x = LineHit.Pos[0];
                    }
                    if (LineHit.Pos[1] < LineHit.Vec[1]) {
                        LineBox.Min.y = LineHit.Pos[1];
                        LineBox.Max.y = LineHit.Vec[1];
                    } else {
                        LineBox.Min.y = LineHit.Vec[1];
                        LineBox.Max.y = LineHit.Pos[1];
                    }
                    if (LineHit.Pos[2] < LineHit.Vec[2]) {
                        LineBox.Min.z = LineHit.Pos[2];
                        LineBox.Max.z = LineHit.Vec[2];
                    } else {
                        LineBox.Min.z = LineHit.Vec[2];
                        LineBox.Max.z = LineHit.Pos[2];
                    }
                    sceVu0SubVector(LineHit.Vec, LineHit.Vec, LineHit.Pos);
                    *(u32 *)(gHitLine + 4) = 0;
                    *(u32 *)(gHitLine + 8) = 0x3f800000;
                    Rate = CheckHitLineHmdPrimList(*(void **)(lpHmdObj + 0x44), *(void **)(lpHmdObj + 0x4c), *(void **)(lpHmdObj + 0x54), *(void **)(lpHmdObj + 0x5c), &LineHit, &LineBox);
                    if (Rate < Ret) {
                        u8 *lpPrim = *(u8 **)(gHitLine + 4);
                        lpColor = *(u8 **)(lpHmdObj + 0x5c) + lpPrim[0x12] * 4;
                        if (lpColor[2] != 0xff && lpColor[2] != 0x96 && lpColor[2] != 0x32) {
                            if (gHitLine[0] != 0) {
                                sceVu0CopyVector(Normal, (void *)(*(s32 *)(lpHmdObj + 0x54) + (*(s16 *)(lpPrim + 0x10) << 4)));
                                ((u32 *)Normal)[3] = 0x3f800000;
                                ((u32 *)l_mat)[12] = 0;
                                ((u32 *)l_mat)[13] = 0;
                                ((u32 *)l_mat)[14] = 0;
                                sceVu0ApplyMatrix(Normal, l_mat, Normal);
                                sceVu0Normalize(*(void **)(gHitLine + 0xc), Normal);
                                switch (lpColor[0]) {
                                case 200:
                                    *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 0x100000;
                                    break;
                                case 249:
                                    *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 0x200000;
                                    break;
                                case 250:
                                    *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 0x400000;
                                    break;
                                case 255:
                                    *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 0x10000;
                                    break;
                                default:
                                    if (lpColor[1] != 0xff) {
                                        if (lpColor[1] != 0xe6) {
                                            switch (lpColor[1]) {
                                            case 200:
                                                *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 0x1000;
                                                break;
                                            case 201:
                                                *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 0x2000;
                                                break;
                                            case 202:
                                                *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 0x4000;
                                                break;
                                            case 203:
                                                *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 0x8000;
                                                break;
                                            case 204:
                                                *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 3;
                                                break;
                                            case 205:
                                                *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 5;
                                                break;
                                            case 206:
                                                *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 9;
                                                break;
                                            case 207:
                                                *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 0x11;
                                                break;
                                            case 208:
                                                *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 0x21;
                                                break;
                                            case 210:
                                                *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 0x41;
                                                break;
                                            case 220:
                                                *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 0x81;
                                                break;
                                            }
                                        } else {
                                            *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 0x101;
                                        }
                                    } else {
                                        *(u32 *)(*(s32 *)(gHitLine + 0xc) + 0x10) = 1;
                                    }
                                    break;
                                }
                            }
                            Ret = Rate;
                        }
                    }
                }
            }
        }
    }
    return Ret;
}
float CheckHitLineHmdPrimList(void *node,void *positions,void *normals,void *materials,void *line,void *bounds) {
    u8 *savedNode;
    u32 savedPositions;
    u32 savedNormals;
    u32 savedLine;
    float *savedBounds;
    float nearest;
    float first;
    float second;
    u8 *primitive;
    int index;
    float *other;
    float *third;
    float polygon[6][4] __attribute__((aligned(16)));
    float hit[4] __attribute__((aligned(16)));
    savedBounds=(float *)bounds;
    savedNode=(u8 *)node;
    savedPositions=(u32)positions;
    savedNormals=(u32)normals;
    nearest=1.0f;
    first=*(volatile float *)((u8 *)node+32);
    second=*(volatile float *)bounds;
    savedLine=(u32)line;
    if(!(first<second)) {
      first=*(float *)(savedNode+16); second=savedBounds[4];
      if(first<=second) {
       first=*(float *)(savedNode+40); second=savedBounds[2];
       if(!(first<second)) {
        first=*(float *)(savedNode+24); second=savedBounds[6];
        if(first<=second) {
         first=*(float *)(savedNode+36); second=savedBounds[1];
         if(!(first<second)) {
          first=*(float *)(savedNode+20); second=savedBounds[5];
          if(first<=second) {
           primitive=savedNode+80;
           index=0;
           if(0<(int)*(u16 *)savedNode) {
            other=polygon[1]; third=polygon[2];
            do {
             u32 kind=*((u8 *)materials+*(u8 *)(primitive+18)*4+1);
             if(kind-200>3) {
              sceVu0CopyVector(polygon[0],(void *)(savedPositions+(*(s16 *)primitive<<4)));
              sceVu0CopyVector(other,(void *)(savedPositions+(*(s16 *)(primitive+4)<<4)));
              sceVu0CopyVector(third,(void *)(savedPositions+(*(s16 *)(primitive+8)<<4)));
              sceVu0CopyVector(polygon[5],(void *)(savedNormals+(*(s16 *)(primitive+16)<<4)));
              sceVu0SubVector(polygon[3],other,polygon[0]);
              sceVu0SubVector(polygon[4],third,polygon[0]);
              if(fsHit_GetHitPolygonLine(polygon[0],(void *)savedLine,hit)==1) {
               first=hit[0];
               if(first<nearest) nearest=first;
               second=*(float *)(gHitLine+8);
               if(first<second) { *(u32 *)(gHitLine+4)=(u32)primitive; *(float *)(gHitLine+8)=nearest; }
              }
             }
             index++; primitive+=20;
            } while(index<(int)*(u16 *)savedNode);
           }
           node=*(void **)(savedNode+4);
           if((u32)node!=0) {
            second=CheckHitLineHmdPrimList(node,(void *)savedPositions,(void *)savedNormals,materials,(void *)savedLine,savedBounds);
            if(second<nearest) nearest=second;
           }
          }
         }
        }
       }
      }
    }
    node=*(void **)(savedNode+8);
    if((u32)node!=0) {
     second=CheckHitLineHmdPrimList(node,(void *)savedPositions,(void *)savedNormals,materials,(void *)savedLine,savedBounds);
     if(second<nearest) nearest=second;
    }
    return nearest;
}
void DrawHmdModel(struct dw_561015_fields *lpMdlMng, unsigned int Mode) {
    int i;
    u8 *lpHmdHead;
    u8 *lpHmdObj;
    u32 *lpPacket;
    float w_mat[4][4] __attribute__((aligned(16)));
    float l_mat[4][4] __attribute__((aligned(16)));
    float sinX, cosX, angleZ, angleX, angleY;
    float sinZ, cosZ, sinY;
    float f4, f3, f2, f1, f0;
    struct Copy3 { u32 b[3]; };

    lpPacket = (u32 *)lpMdlPacketMem;
    if (lpMdlMng->bUse != 0) {
        if (lpMdlMng->lpMdlData->lpHmdHead != 0) {
        {
            float shifted;
            float angle;
            angle = lpMdlMng->Ang[0];
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
            angle = lpMdlMng->Ang[1];
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
            angle = lpMdlMng->Ang[2];
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
        w_mat[0][0] = (cosZ * (lpMdlMng->Scl[0] * f0));
        f2 = (sinY * sinZ);
        w_mat[0][1] = (lpMdlMng->Scl[0] * sinZ);
        f4 = ((float)(f0 * sinX) + (cosX * f2));
        f1 = ((f0 * cosX) - (sinX * f2));
        w_mat[0][2] = (cosZ * (lpMdlMng->Scl[0] * (-sinY)));
        ((u32 *)w_mat)[3] = 0;
        w_mat[1][0] = (lpMdlMng->Scl[1] * ((sinY * sinX) - (cosX * f3)));
        w_mat[1][1] = (cosX * (lpMdlMng->Scl[1] * cosZ));
        w_mat[1][2] = (lpMdlMng->Scl[1] * f4);
        ((u32 *)w_mat)[7] = 0;
        w_mat[2][0] = (lpMdlMng->Scl[2] * ((float)(sinY * cosX) + (sinX * f3)));
        w_mat[2][1] = (sinX * (lpMdlMng->Scl[2] * (-cosZ)));
        w_mat[2][2] = (lpMdlMng->Scl[2] * f1);
        ((u32 *)w_mat)[11] = 0;
        w_mat[3][0] = lpMdlMng->Pos[0];
        w_mat[3][1] = lpMdlMng->Pos[1];
        w_mat[3][2] = lpMdlMng->Pos[2];
        ((u32 *)w_mat)[15] = 0x3f800000;
        sceVu0MulMatrix(w_mat, (void *)(lpDrawMng + 0x2b0), w_mat);
        lpHmdHead = (u8 *)lpMdlMng->lpMdlData->lpHmdHead;
        lpHmdObj = *(u8 **)(lpHmdHead + 0x24);
        for (i = 0; i < *(s32 *)(lpHmdHead + 0x10); i++) {
            if (*(s32 *)(lpHmdObj + 0x44) != 0) {
        {
            float shifted;
            float angle;
            angle = *(float *)(lpHmdObj + 0x10);
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
            angle = *(float *)(lpHmdObj + 0x14);
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
            angle = *(float *)(lpHmdObj + 0x18);
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
        l_mat[0][0] = (cosZ * (*(float *)(lpHmdObj + 0x20) * f0));
        f2 = (sinY * sinZ);
        l_mat[0][1] = (*(float *)(lpHmdObj + 0x20) * sinZ);
        f4 = ((float)(f0 * sinX) + (cosX * f2));
        f1 = ((f0 * cosX) - (sinX * f2));
        l_mat[0][2] = (cosZ * (*(float *)(lpHmdObj + 0x20) * (-sinY)));
        ((u32 *)l_mat)[3] = 0;
        l_mat[1][0] = (*(float *)(lpHmdObj + 0x24) * ((sinY * sinX) - (cosX * f3)));
        l_mat[1][1] = (cosX * (*(float *)(lpHmdObj + 0x24) * cosZ));
        l_mat[1][2] = (*(float *)(lpHmdObj + 0x24) * f4);
        ((u32 *)l_mat)[7] = 0;
        l_mat[2][0] = (*(float *)(lpHmdObj + 0x28) * ((float)(sinY * cosX) + (sinX * f3)));
        l_mat[2][1] = (sinX * (*(float *)(lpHmdObj + 0x28) * (-cosZ)));
        l_mat[2][2] = (*(float *)(lpHmdObj + 0x28) * f1);
        ((u32 *)l_mat)[11] = 0;
        l_mat[3][0] = *(float *)lpHmdObj;
        l_mat[3][1] = *(float *)(lpHmdObj + 4);
        l_mat[3][2] = *(float *)(lpHmdObj + 8);
        ((u32 *)l_mat)[15] = 0x3f800000;
                sceVu0MulMatrix(l_mat, w_mat, l_mat);
                lpPacket = DrawHmdPrimListDirect(*(void **)(lpHmdObj + 0x44), (struct HmdMdl *)lpHmdObj, l_mat, lpPacket, Mode);
            }
            lpHmdObj += 0x60;
        }
        lpMdlPacketMem = (u32)lpPacket;
        }
    }
}

unsigned int * DrawHmdPrimListDirect(void *node, struct HmdMdl *model, void *matrix, unsigned int *packet, unsigned int mode) {
    u8 *savedNode;
    struct HmdPrim *primitive;
    int index;
    u8 *material;
    u8 *s2;
    u8 *s1;
    u8 *s0;
    int sv0[4] __attribute__((aligned(16)));
    int sv1[4] __attribute__((aligned(16)));
    int sv2[4] __attribute__((aligned(16)));
    u32 color[4] __attribute__((aligned(16)));
    float poly0[4] __attribute__((aligned(16)));
    float poly1[4] __attribute__((aligned(16)));
    float poly2[4] __attribute__((aligned(16)));
    float center[4] __attribute__((aligned(16)));
    float temporary[4] __attribute__((aligned(16)));
    savedNode = (u8 *)node;
    index = 0;
    primitive = (struct HmdPrim *)(savedNode + 80);
    if (0 < (int)*(u16 *)savedNode) {
        do {
            material = model->pColor + primitive->mat * 4;
            if (material[0] == 0) {
                s0 = (u8 *)(model->pVertex + primitive->i2);
                s1 = (u8 *)(model->pVertex + primitive->i1);
                s2 = (u8 *)(model->pVertex + primitive->i0);
                center[0] = (*(float *)s0 + (*(float *)s2 + *(float *)s1)) / 3.0f;
                center[1] = (*(float *)(s0 + 4) + (*(float *)(s2 + 4) + *(float *)(s1 + 4))) / 3.0f;
                center[2] = (*(float *)(s0 + 8) + (*(float *)(s2 + 8) + *(float *)(s1 + 8))) / 3.0f;
                sceVu0ScaleVectorXYZ(center, center, -0.049999952f);
                sceVu0ScaleVectorXYZ(temporary, s2, 1.05f);
                sceVu0AddVector(poly0, center, temporary);
                sceVu0ScaleVectorXYZ(temporary, s1, 1.05f);
                sceVu0AddVector(poly1, center, temporary);
                sceVu0ScaleVectorXYZ(temporary, s0, 1.05f);
                sceVu0AddVector(poly2, center, temporary);
                *(u32 *)&poly0[3] = 0x3f800000;
                *(u32 *)&poly1[3] = 0x3f800000;
                *(u32 *)&poly2[3] = 0x3f800000;
                sceVu0RotTransPers(sv0, matrix, poly0, 0);
                sceVu0RotTransPers(sv1, matrix, poly1, 0);
                sceVu0RotTransPers(sv2, matrix, poly2, 0);
            } else {
                sceVu0RotTransPers(sv0, matrix, (void *)(model->pVertex + primitive->i0), 0);
                sceVu0RotTransPers(sv1, matrix, (void *)(model->pVertex + primitive->i1), 0);
                sceVu0RotTransPers(sv2, matrix, (void *)(model->pVertex + primitive->i2), 0);
            }
            if (sv0[0] >= 0 && sv0[0] < 0x10000 && sv0[1] >= 0 && sv0[1] < 0x10000 && sv0[2] >= 0 && sv0[1] < 0x1000000
                && sv1[0] >= 0 && sv1[0] < 0x10000 && sv1[1] >= 0 && sv1[1] < 0x10000 && sv1[2] >= 0 && sv1[1] < 0x1000000
                && sv2[0] >= 0 && sv2[0] < 0x10000 && sv2[1] >= 0 && sv2[1] < 0x10000 && sv2[2] >= 0 && sv2[1] < 0x1000000) {
                color[0] = material[0];
                color[1] = material[1];
                color[2] = material[2];
                color[3] = material[3];
                packet = MakePolygonPacket(sv0, sv1, sv2, color, packet, mode);
            }
            index++;
            primitive++;
        } while (index < (int)*(u16 *)savedNode);
    }
    node = *(void **)(savedNode + 4);
    if ((u32)node != 0) packet = DrawHmdPrimListDirect(node, model, matrix, packet, mode);
    node = *(void **)(savedNode + 8);
    if ((u32)node != 0) packet = DrawHmdPrimListDirect(node, model, matrix, packet, mode);
    return packet;
}

/* MakePolygonPacket @ 0x15B330 .. 0x15B428 (0xf8 bytes) */
/*
 * dcomp notes:
 *   quad: v1: 128-bit web split from its scalar uses
 *   quad: v0: 128-bit web split from its scalar uses
 *   return: daddu at 0x15b424 computes the return value
 *   quad: v1: 128-bit web split from its scalar variable as v1_q2
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */

static unsigned int * MakePolygonPacket(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */,
        void *a3 /* r7 */, unsigned int *t0 /* r8 */, unsigned int t1 /* r9 */) {
    s32 t4;
    u32 v1;
    u_long128 v1_q;
    u32 v0;
    u_long128 v1_q2;
    u_long128 v0_q;

    v1 = 8;
    if ((u32)(s32)t1 == (u32)2) {
        v1 = 9;
    }
    v0 = 0x50000000;
    *(u32 *)t0 = v1 | 0x10000000;
    v1 = v1 | 0x50000000;
    t0[1] = 0;
    t4 = 1;
    t0[2] = 0;
    t0[3] = v1;
    t0[4] = t4;
    t0[5] = 0x10000000;
    v1 = 0x41;
    t0[6] = 0xe;
    t0[7] = 0;
    *(s64 *)(((u8 *)t0 + 0x20)) = (s32)0x70000;
    *(s64 *)(((u8 *)t0 + 0x28)) = (s32)0x47;
    t0[0xc] = t4;
    t0[0xd] = 0x10000000;
    t0[0xe] = v1;
    t0[0xf] = 0;
    v1_q = *(u_long128 *)a3;
    *(u_long128 *)(((u8 *)t0 + 0x40)) = v1_q;
    if ((u32)(s32)t1 == (u32)2) {
        v1 = 0x8004;
        t0[0x14] = 0x8004;
        v0 = 0x10054000;
        t0[0x15] = 0x10054000;
        t0 = (unsigned int *)(u8 *)(t0 + 0x16);
    } else {
        v0 = 0x8003;
        t0[0x14] = 0x8003;
        v0 = 0x1005c000;
        t0[0x15] = 0x1005c000;
        t0 = (unsigned int *)(u8 *)(t0 + 0x16);
    }
    *(u32 *)t0 = 4;
    t0[1] = 0;
    *(u_long128 *)((u8 *)t0 + 8) = *(u_long128 *)a0;
    *(u_long128 *)((u8 *)t0 + 0x18) = *(u_long128 *)a1;
    *(u_long128 *)((u8 *)t0 + 0x28) = *(u_long128 *)a2;
    t0 = t0 + 0xe;
    if (t1 == 2) {
        *(u_long128 *)t0 = *(u_long128 *)a0;
        t0 = t0 + 4;
    }
    return (unsigned int *)t0;
}
