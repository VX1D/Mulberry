#include "common.h"


/* __SFX_EndPtclModel2 @ 0x1AE580 .. 0x1AE5AC (0x2c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   a1 typed from the __SFX_EndPtclModel2 call table
 *   a2 typed from the __SFX_EndPtclModel2 call table
 */

extern signed int SfxMdl_Free(unsigned short);

/* _Model2_SetMdlParamToMdlMng @ 0x1AE5B0 .. 0x1AECC4 (0x714 bytes, frame 0x1d0) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x150 escapes at 0x1ae614
 *   stack: address of the slot at 0x1c0 escapes at 0x1ae698
 *   stack: address of the slot at 0x190 escapes at 0x1ae798
 *   stack: address of the slot at 0x60 escapes at 0x1ae7a4
 *   fpu: mov.s at 0x1ae7d8 is a float copy
 *   stack: address of the slot at 0x190 escapes at 0x1ae7d4
 *   stack: address of the slot at 0x1c0 escapes at 0x1ae7e4
 *   stack: address of the slot at 0x1c0 escapes at 0x1ae8e0
 *   stack: address of the slot at 0x190 escapes at 0x1ae8e0
 *   stack: address of the slot at 0x140 escapes at 0x1ae8e4
 *   stack: address of the slot at 0x1b0 escapes at 0x1ae8e4
 *   stack: address of the slot at 0x130 escapes at 0x1ae8f0
 *   stack: address of the slot at 0x140 escapes at 0x1ae900
 *   stack: address of the slot at 0x140 escapes at 0x1ae900
 *   stack: address of the slot at 0x190 escapes at 0x1ae90c
 *   stack: address of the slot at 0x140 escapes at 0x1ae90c
 *   stack: address of the slot at 0x130 escapes at 0x1ae918
 *   stack: address of the slot at 0x190 escapes at 0x1ae930
 *   stack: address of the slot at 0x1a0 escapes at 0x1ae944
 *   stack: address of the slot at 0x1b0 escapes at 0x1ae958
 *   stack: address of the slot at 0x1c0 escapes at 0x1ae964
 *   stack: address of the slot at 0x1a0 escapes at 0x1aea60
 *   stack: address of the slot at 0x1b0 escapes at 0x1aea60
 *   stack: address of the slot at 0x190 escapes at 0x1aea60
 *   stack: address of the slot at 0xf0 escapes at 0x1aea6c
 *   stack: address of the slot at 0xb0 escapes at 0x1aea84
 *   fpu: float literal 0xbf800000 at 0x1aea94
 *   stack: address of the slot at 0xb0 escapes at 0x1aea98
 *   stack: address of the slot at 0xb0 escapes at 0x1aea98
 *   fpu: float literal 0xbf800000 at 0x1aeaa8
 *   stack: address of the slot at 0xd0 escapes at 0x1aeaac
 *   stack: address of the slot at 0xd0 escapes at 0x1aeaac
 *   stack: address of the slot at 0x190 escapes at 0x1aeb4c
 *   stack: address of the slot at 0xf0 escapes at 0x1aeb4c
 *   stack: address of the slot at 0x100 escapes at 0x1aeb74
 *   stack: address of the slot at 0x110 escapes at 0x1aeb9c
 *   stack: address of the slot at 0x70 escapes at 0x1aebb4
 *   stack: address of the slot at 0x80 escapes at 0x1aebc8
 *   stack: address of the slot at 0x90 escapes at 0x1aebdc
 *   stack: address of the slot at 0xa0 escapes at 0x1aebec
 *   stack: address of the slot at 0x190 escapes at 0x1aec6c
 */

extern void SfxCalc_MakeMatrixFromPYR(void *, float, float, float);
extern void sceVu0CopyVector(void *, void *);
extern void sceVu0Normalize(void *, void *);
extern void SfxCalc_MakeMatrixFromDir(void *, float *);
extern void sceVu0ScaleVector(void *, void *, float);
extern float sceVu0InnerProduct(void *,void *);
extern signed int SfxMdl_SetMatrix(unsigned short, void *);
extern signed int SfxMdl_SetColor(unsigned short, float, float, float);
extern signed int SfxMdl_SetAlpha(unsigned short, float);
extern signed int SfxMdl_SetTexScroll(unsigned short, float, float);
extern u32 VX[];
extern u32 VY[];
extern u32 VZ[];
extern u8 *lpDrawMng;
extern u32 VW[];
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif


struct dw_1890884_fields;
struct dw_1891466_fields;
struct dw_1904865_fields;
struct dw_1905892_fields;
#ifndef PROTO_DW_1890884_FIELDS
#define PROTO_DW_1890884_FIELDS
struct dw_1890884_fields { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float rgba[4]; float n_speed[4]; float add_uv[2]; float dmy; char rand[4]; unsigned int lifecnt; unsigned int cnt; struct dw_1890884_fields *p_sibling; struct dw_1891466_fields *pEmitter; unsigned char extra_data[32]; float qtn[4]; };
#endif
#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS
struct dw_1916235_fields { unsigned short disable_draw : 1; unsigned short disable_draw_by_map : 1; unsigned short disable_act : 1; unsigned short disable_act_by_map : 1; unsigned short draw_stage : 4; unsigned short unused : 8; };
#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS
struct dw_1891466_fields { float matrix[4][4]; float (*p_matrix)[4][4]; unsigned short prog_no; unsigned char ptcl_num; unsigned char dmy; struct dw_1890884_fields *p_ptcl_top; struct dw_1904865_fields *p_fix_param; struct dw_1905892_fields *p_seq_param; struct dw_1891466_fields *p_prev; struct dw_1891466_fields *p_next; struct dw_1891466_fields *p_relation_prev; struct dw_1891466_fields *p_relation_next; unsigned int lifecnt; unsigned int cnt; struct dw_1916235_fields bit_flag; unsigned short sfx_sttdata_idx; unsigned short cframe; unsigned char dmy2[14]; unsigned char extra_data[32]; };
#endif
#ifndef PROTO_DW_1914572_FIELDS
#define PROTO_DW_1914572_FIELDS
struct dw_1914572_fields { unsigned int EN1 : 1; unsigned int EN2 : 1; unsigned int CRTMD : 3; unsigned int MMOD : 1; unsigned int AMOD : 1; unsigned int SLBG : 1; unsigned int ALP : 8; unsigned int p0 : 16; unsigned int p1; };
#endif
#ifndef PROTO_DW_1898071_FIELDS
#define PROTO_DW_1898071_FIELDS
struct dw_1898071_fields { unsigned int INT : 1; unsigned int FFMD : 1; unsigned int DPMS : 2; unsigned int p0 : 28; unsigned int p1; };
#endif
#ifndef PROTO_DW_1914975_FIELDS
#define PROTO_DW_1914975_FIELDS
struct dw_1914975_fields { unsigned int FBP : 9; unsigned int FBW : 6; unsigned int PSM : 5; unsigned int p0 : 12; unsigned int DBX : 11; unsigned int DBY : 11; unsigned int p1 : 10; };
#endif
#ifndef PROTO_DW_1900000_FIELDS
#define PROTO_DW_1900000_FIELDS
struct dw_1900000_fields { unsigned int DX : 12; unsigned int DY : 11; unsigned int MAGH : 4; unsigned int MAGV : 2; unsigned int p0 : 3; unsigned int DW : 12; unsigned int DH : 11; unsigned int p1 : 9; };
#endif
#ifndef PROTO_DW_1898574_FIELDS
#define PROTO_DW_1898574_FIELDS
struct dw_1898574_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int p0 : 8; unsigned int p1; };
#endif
#ifndef PROTO_DW_1909241_FIELDS
#define PROTO_DW_1909241_FIELDS
struct dw_1909241_fields { struct dw_1914572_fields pmode; struct dw_1898071_fields smode2; struct dw_1914975_fields dispfb; struct dw_1900000_fields display; struct dw_1898574_fields bgcolor; };
#endif
#ifndef PROTO_DW_1912894_FIELDS
#define PROTO_DW_1912894_FIELDS
struct dw_1912894_fields { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; };
#endif
#ifndef PROTO_DW_1897738_FIELDS
#define PROTO_DW_1897738_FIELDS
struct dw_1897738_fields { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
#endif
#ifndef PROTO_DW_1907886_FIELDS
#define PROTO_DW_1907886_FIELDS
struct dw_1907886_fields { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
#endif
#ifndef PROTO_DW_1903783_FIELDS
#define PROTO_DW_1903783_FIELDS
struct dw_1903783_fields { unsigned long OFX : 16; unsigned long pad16 : 16; unsigned long OFY : 16; unsigned long pad48 : 16; };
#endif
#ifndef PROTO_DW_1916577_FIELDS
#define PROTO_DW_1916577_FIELDS
struct dw_1916577_fields { unsigned long SCAX0 : 11; unsigned long pad11 : 5; unsigned long SCAX1 : 11; unsigned long pad27 : 5; unsigned long SCAY0 : 11; unsigned long pad43 : 5; unsigned long SCAY1 : 11; unsigned long pad59 : 5; };
#endif
#ifndef PROTO_DW_1912705_FIELDS
#define PROTO_DW_1912705_FIELDS
struct dw_1912705_fields { unsigned long AC : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_1905772_FIELDS
#define PROTO_DW_1905772_FIELDS
struct dw_1905772_fields { unsigned long CLAMP : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_1914381_FIELDS
#define PROTO_DW_1914381_FIELDS
struct dw_1914381_fields { unsigned long DTHE : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_1900399_FIELDS
#define PROTO_DW_1900399_FIELDS
struct dw_1900399_fields { unsigned long ATE : 1; unsigned long ATST : 3; unsigned long AREF : 8; unsigned long AFAIL : 2; unsigned long DATE : 1; unsigned long DATM : 1; unsigned long ZTE : 1; unsigned long ZTST : 2; unsigned long pad19 : 45; };
#endif
#ifndef PROTO_DW_1911313_FIELDS
#define PROTO_DW_1911313_FIELDS
struct dw_1911313_fields { struct dw_1897738_fields frame1; unsigned long frame1addr; struct dw_1907886_fields zbuf1; long zbuf1addr; struct dw_1903783_fields xyoffset1; long xyoffset1addr; struct dw_1916577_fields scissor1; long scissor1addr; struct dw_1912705_fields prmodecont; long prmodecontaddr; struct dw_1905772_fields colclamp; long colclampaddr; struct dw_1914381_fields dthe; long dtheaddr; struct dw_1900399_fields test1; long test1addr; };
#endif
#ifndef PROTO_DW_1910783_FIELDS
#define PROTO_DW_1910783_FIELDS
struct dw_1910783_fields { unsigned long PRIM : 3; unsigned long IIP : 1; unsigned long TME : 1; unsigned long FGE : 1; unsigned long ABE : 1; unsigned long AA1 : 1; unsigned long FST : 1; unsigned long CTXT : 1; unsigned long FIX : 1; unsigned long pad11 : 53; };
#endif
#ifndef PROTO_DW_1914015_FIELDS
#define PROTO_DW_1914015_FIELDS
struct dw_1914015_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int A : 8; float Q; };
#endif
#ifndef PROTO_DW_1904938_FIELDS
#define PROTO_DW_1904938_FIELDS
struct dw_1904938_fields { unsigned long X : 16; unsigned long Y : 16; unsigned long Z : 32; };
#endif
#ifndef PROTO_DW_1915335_FIELDS
#define PROTO_DW_1915335_FIELDS
struct dw_1915335_fields { struct dw_1900399_fields testa; long testaaddr; struct dw_1910783_fields prim; long primaddr; struct dw_1914015_fields rgbaq; long rgbaqaddr; struct dw_1904938_fields xyz2a; long xyz2aaddr; struct dw_1904938_fields xyz2b; long xyz2baddr; struct dw_1900399_fields testb; long testbaddr; };
#endif
#ifndef PROTO_DW_1897376_FIELDS
#define PROTO_DW_1897376_FIELDS
struct dw_1897376_fields { struct dw_1909241_fields disp[2]; struct dw_1912894_fields giftag0; struct dw_1911313_fields draw0; struct dw_1915335_fields clear0; struct dw_1912894_fields giftag1; struct dw_1911313_fields draw1; struct dw_1915335_fields clear1; };
#endif
#ifndef PROTO_DW_1892708_FIELDS
#define PROTO_DW_1892708_FIELDS
struct dw_1892708_fields { struct dw_1897376_fields dbBuf; float camPos[4]; float camAng[4]; float camPosB[4]; float camAngB[4]; float vsMat[4][4]; float wsMat[4][4]; float wvMat[4][4]; float lcMat[4][4]; float wcMat[4][4]; float csMat[4][4]; float scrDepth; unsigned int *sprBuf[2]; int sprBufID; unsigned int DMATag; int ctxt; int dbBufID; int oddeven; unsigned int calcTime; unsigned int drawTime; unsigned int frameTime; float fov; int TotalPolyNum; int TotalPrimNum; float WaterLevel; unsigned char DrawFlag; unsigned char DrawHitModel; unsigned char BlurMode; unsigned char BlurRate; unsigned char ProjectionType; unsigned char unused[15]; float PlaneParam[4]; float FogParam[4]; float FogParam16[4]; };
#endif
#ifndef PROTO_DW_1904865_FIELDS
#define PROTO_DW_1904865_FIELDS
struct dw_1904865_fields { char cdummy; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ADD_UV_0__91FC4FD4_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ADD_UV_0__91FC4FD4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ADD_UV_0__91FC4FD4 = (int)&(((struct dw_1890884_fields *)0)->add_uv[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ADD_UV_1__B796255F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ADD_UV_1__B796255F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ADD_UV_1__B796255F = (int)&(((struct dw_1890884_fields *)0)->add_uv[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C = (int)&(((struct dw_1890884_fields *)0)->ang[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_1__C6D2CBBE_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_1__C6D2CBBE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_1__C6D2CBBE = (int)&(((struct dw_1890884_fields *)0)->ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE = (int)&(((struct dw_1890884_fields *)0)->ang[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510 = (int)&(((struct dw_1890884_fields *)0)->pEmitter) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_0__89D82EC2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_0__89D82EC2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_0__89D82EC2 = (int)&(((struct dw_1890884_fields *)0)->rgba[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_1__872F13A5_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_1__872F13A5_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_1__872F13A5 = (int)&(((struct dw_1890884_fields *)0)->rgba[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_2__2B1C9A34_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_2__2B1C9A34_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_2__2B1C9A34 = (int)&(((struct dw_1890884_fields *)0)->rgba[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_3__47898D35_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_3__47898D35_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_3__47898D35 = (int)&(((struct dw_1890884_fields *)0)->rgba[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_0__A4EC329F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_0__A4EC329F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_0__A4EC329F = (int)&(((struct dw_1890884_fields *)0)->scale[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_1__0DD44650_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_1__0DD44650_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_1__0DD44650 = (int)&(((struct dw_1890884_fields *)0)->scale[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_2__ED13F378_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_2__ED13F378_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_2__ED13F378 = (int)&(((struct dw_1890884_fields *)0)->scale[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571 = (int)&(((struct dw_1891466_fields *)0)->p_fix_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B = (int)&(((struct dw_1891466_fields *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892708_FIELDS_CAMANG_0__F84E15FD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892708_FIELDS_CAMANG_0__F84E15FD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892708_FIELDS_CAMANG_0__F84E15FD = (int)&(((struct dw_1892708_fields *)0)->camAng[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892708_FIELDS_CAMANG_1__D6D04EFB_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892708_FIELDS_CAMANG_1__D6D04EFB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892708_FIELDS_CAMANG_1__D6D04EFB = (int)&(((struct dw_1892708_fields *)0)->camAng[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892708_FIELDS_CAMANG_2__81A9446B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892708_FIELDS_CAMANG_2__81A9446B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892708_FIELDS_CAMANG_2__81A9446B = (int)&(((struct dw_1892708_fields *)0)->camAng[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1904865_FIELDS__80__CDUMMY_FD3F90B0_DEFINED
#define DCOMP_OFF_STRUCT_DW_1904865_FIELDS__80__CDUMMY_FD3F90B0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1904865_FIELDS__80__CDUMMY_FD3F90B0 = (int)&(((struct dw_1904865_fields *)0)[80].cdummy) - 0 };
#endif
struct M2_ExtData { unsigned char pad0[4]; unsigned short mdl_id; };
typedef float M2_Mat[4][4];


static u32 s_mngp __attribute__((aligned(8)));
/* __SFX_ActModel2 @ 0x1AECD0 .. 0x1AFAB8 (0xde8 bytes, frame 0x290) */
/*
 * dcomp notes:
 *   literal: @3373 is the string 'PtclMng.c'
 *   literal: @3374 is the string 'Invalid angle control type'
 *   fpu: mov.s at 0x1aed14 is a float copy
 *   stack: address of the slot at 0x278 escapes at 0x1aee24
 *   fpu: float literal 0x3c8ef34d at 0x1aee38
 *   fpu: float literal 0xc0490fd0 at 0x1aee54
 *   fpu: float literal 0x40490fd0 at 0x1aeeac
 *   fpu: float literal 0x40c90fd0 at 0x1aeed8
 *   fpu: float literal 0xc0490fd0 at 0x1aeef4
 *   fpu: float literal 0x40490fd0 at 0x1aef0c
 *   fpu: float literal 0x40c90fd0 at 0x1aef38
 *   fpu: float literal 0xc0490fd0 at 0x1aef54
 *   fpu: float literal 0x40490fd0 at 0x1aef6c
 *   fpu: float literal 0x40c90fd0 at 0x1aef98
 *   stack: address of the slot at 0x278 escapes at 0x1aefc4
 *   fpu: float literal 0x3c8ef34d at 0x1aefe0
 *   fpu: float literal 0xc0490fd0 at 0x1af004
 *   fpu: float literal 0x40490fd0 at 0x1af01c
 *   fpu: float literal 0x40c90fd0 at 0x1af048
 *   fpu: float literal 0xc0490fd0 at 0x1af064
 *   fpu: float literal 0x40490fd0 at 0x1af07c
 *   fpu: float literal 0x40c90fd0 at 0x1af0a8
 *   fpu: float literal 0xc0490fd0 at 0x1af0c4
 *   fpu: float literal 0x40490fd0 at 0x1af0dc
 *   fpu: float literal 0x40c90fd0 at 0x1af108
 *   stack: address of the slot at 0x278 escapes at 0x1af134
 *   fpu: float literal 0x3c8ef34d at 0x1af148
 *   fpu: float literal 0xc0490fd0 at 0x1af164
 *   fpu: float literal 0x40490fd0 at 0x1af1bc
 *   fpu: float literal 0x40c90fd0 at 0x1af1e8
 *   fpu: float literal 0xc0490fd0 at 0x1af204
 *   fpu: float literal 0x40490fd0 at 0x1af21c
 *   fpu: float literal 0x40c90fd0 at 0x1af248
 *   fpu: float literal 0xc0490fd0 at 0x1af264
 *   fpu: float literal 0x40490fd0 at 0x1af27c
 *   fpu: float literal 0x40c90fd0 at 0x1af2a8
 *   stack: address of the slot at 0x160 escapes at 0x1af2c8
 *   stack: address of the slot at 0x160 escapes at 0x1af2e0
 *   stack: address of the slot at 0xe0 escapes at 0x1af308
 *   fpu: float literal 0x3c23d70a at 0x1af330
 *   fpu: mtc1 reinterprets a0 at 0x1af33c
 *   stack: address of the slot at 0xe4 escapes at 0x1af368
 *   stack: address of the slot at 0xe8 escapes at 0x1af37c
 *   stack: address of the slot at 0xf0 escapes at 0x1af398
 *   fpu: float literal 0x3c23d70a at 0x1af3b4
 *   fpu: mtc1 reinterprets a0 at 0x1af3bc
 *   fpu: mtc1 reinterprets v1 at 0x1af3e4
 *   fpu: mtc1 reinterprets v1 at 0x1af410
 *   stack: address of the slot at 0xf0 escapes at 0x1af430
 *   fpu: mov.s at 0x1af43c is a float copy
 *   stack: address of the slot at 0x150 escapes at 0x1af438
 *   stack: address of the slot at 0x150 escapes at 0x1af448
 *   stack: address of the slot at 0x28c escapes at 0x1af464
 *   fpu: float literal 0x00000000 at 0x1af470
 *   stack: address of the slot at 0x110 escapes at 0x1af510
 *   stack: address of the slot at 0x110 escapes at 0x1af514
 *   stack: address of the slot at 0x110 escapes at 0x1af524
 *   stack: address of the slot at 0x110 escapes at 0x1af524
 *   stack: address of the slot at 0x260 escapes at 0x1af538
 *   stack: address of the slot at 0x110 escapes at 0x1af538
 *   stack: address of the slot at 0x100 escapes at 0x1af554
 *   stack: address of the slot at 0x260 escapes at 0x1af554
 *   stack: address of the slot at 0x100 escapes at 0x1af564
 *   stack: address of the slot at 0x288 escapes at 0x1af588
 *   fpu: mtc1 reinterprets v0 at 0x1af59c
 *   fpu: mtc1 reinterprets v1 at 0x1af5b0
 *   fpu: float literal 0x43000000 at 0x1af5c4
 *   fpu: mtc1 reinterprets v0 at 0x1af5e4
 *   fpu: mtc1 reinterprets v1 at 0x1af5f8
 *   fpu: float literal 0x43000000 at 0x1af60c
 *   fpu: mtc1 reinterprets v0 at 0x1af62c
 *   fpu: mtc1 reinterprets v1 at 0x1af640
 *   fpu: float literal 0x43000000 at 0x1af658
 *   stack: address of the slot at 0x28b escapes at 0x1af674
 *   fpu: mtc1 reinterprets v0 at 0x1af68c
 *   fpu: mtc1 reinterprets v1 at 0x1af6a0
 *   fpu: float literal 0x43000000 at 0x1af6b8
 *   fpu: mtc1 reinterprets v1 at 0x1af6f8
 *   fpu: mtc1 reinterprets a0 at 0x1af710
 *   fpu: mtc1 reinterprets v1 at 0x1af754
 *   fpu: mtc1 reinterprets a0 at 0x1af768
 *   fpu: float literal 0x3f800000 at 0x1af77c
 *   fpu: mtc1 reinterprets a3 at 0x1af788
 *   fpu: mtc1 reinterprets a0 at 0x1af79c
 *   fpu: mtc1 reinterprets v1 at 0x1af7e4
 *   fpu: mtc1 reinterprets a0 at 0x1af7fc
 *   fpu: float literal 0x3f800000 at 0x1af810
 *   fpu: mtc1 reinterprets v0 at 0x1af81c
 *   fpu: mtc1 reinterprets v1 at 0x1af830
 *   fpu: mtc1 reinterprets v0 at 0x1af86c
 *   fpu: mtc1 reinterprets v1 at 0x1af880
 *   fpu: mtc1 reinterprets v0 at 0x1af8a8
 *   fpu: mtc1 reinterprets v1 at 0x1af8bc
 *   fpu: float literal 0x3f800000 at 0x1af8d4
 *   fpu: float literal 0x3f800000 at 0x1af908
 *   fpu: float literal 0x00000000 at 0x1af92c
 *   fpu: float literal 0x3f800000 at 0x1af94c
 *   fpu: float literal 0x00000000 at 0x1af964
 *   fpu: float literal 0x3f800000 at 0x1af984
 *   delay: addiu at 0x1af9b4 writes a register its branch at 0x1af9b0 reads
 *   cfg: kept goto: 0x1aece0 -> .L001AFA58
 *   cfg: kept branch: 0x1aeea4 if (..) goto .L001AEEC8
 *   cfg: kept branch: 0x1aef04 if (..) goto .L001AEF28
 *   cfg: kept branch: 0x1aef64 if (..) goto .L001AEF88
 *   cfg: kept branch: 0x1af014 if (..) goto .L001AF038
 *   cfg: kept branch: 0x1af074 if (..) goto .L001AF098
 *   cfg: kept branch: 0x1af0d4 if (..) goto .L001AF0F8
 *   cfg: kept branch: 0x1af1b4 if (..) goto .L001AF1D8
 *   cfg: kept branch: 0x1af214 if (..) goto .L001AF238
 *   cfg: kept branch: 0x1af274 if (..) goto .L001AF298
 *   cfg: loop body is not one contiguous region: .L001AFA58
 *   cfg: kept branch: 0x1afa6c if (..) goto .L001AED28
 *   v1#82 is the pointer held in a0+0x48
 *   v1#10 is the pointer held in s2#1+0xa8
 *   a2 typed from the __SFX_ActModel2 call table
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void * memset(void *, int, unsigned int);
extern signed int SFX_GetSeqParam(void *, signed int, signed int, void *, signed int);
extern float SfxCalc_IntoAngle_0_2PI(float);
extern char * strcpy(char *, const char *);
extern void SfxDbg_SetDebugMsg(unsigned char, char *, char *, unsigned int);
extern void sceVu0ScaleVector(void *, void *, float);
extern void sceVu0AddVector(void *, void *, void *);
extern void sceVu0CopyMatrix(void *, void *);
extern void sceVu0InversMatrix(void *, void *);
extern void sceVu0ApplyMatrix(void *,void *,void *);
static void _Model2_SetMdlParamToMdlMng(void *pPtcl__);
static void _Model2_SetMdlParamToMdlMng(void *);
extern signed int SfxMdl_EnableDraw(unsigned short, signed int);

extern u32 s_FuncTable[];
extern u32 VY[];
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif


struct dw_1890884_fields;
struct dw_1891466_fields;
struct dw_1904865_fields;
struct dw_1905892_fields;
#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS
struct dw_1916235_fields { unsigned short disable_draw : 1; unsigned short disable_draw_by_map : 1; unsigned short disable_act : 1; unsigned short disable_act_by_map : 1; unsigned short draw_stage : 4; unsigned short unused : 8; };
#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS
struct dw_1891466_fields { float matrix[4][4]; float (*p_matrix)[4][4]; unsigned short prog_no; unsigned char ptcl_num; unsigned char dmy; struct dw_1890884_fields *p_ptcl_top; struct dw_1904865_fields *p_fix_param; struct dw_1905892_fields *p_seq_param; struct dw_1891466_fields *p_prev; struct dw_1891466_fields *p_next; struct dw_1891466_fields *p_relation_prev; struct dw_1891466_fields *p_relation_next; unsigned int lifecnt; unsigned int cnt; struct dw_1916235_fields bit_flag; unsigned short sfx_sttdata_idx; unsigned short cframe; unsigned char dmy2[14]; unsigned char extra_data[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571 = (int)&(((struct dw_1891466_fields *)0)->p_fix_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087 = (int)&(((struct dw_1891466_fields *)0)->p_ptcl_top) - 0 };
#endif
static inline float __SFX_ActModel2__inl0(u8 *s2) {
    float f12;

    f12 = *(float *)(s2 + 0x50);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(f32 *)(s2 + 0x50) = f12;
    f12 = *(float *)(s2 + 0x54);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(f32 *)(s2 + 0x54) = f12;
    f12 = *(float *)(s2 + 0x58);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    return f12;
}


/* __SFX_InitModel2 @ 0x1AFAC0 .. 0x1B05FC (0xb3c bytes, frame 0x230) */
/*
 * dcomp notes:
 *   literal: @3373 is the string 'PtclMng.c'
 *   literal: @3668 is the string '3DÓÃÞÙ\x8a\x84\x82è\x93\x96\x82Ä\x8e¸\x94s'
 *   stack: address of the slot at 0xb4 escapes at 0x1afc10
 *   delay: lui at 0x1afc24 writes a register its branch at 0x1afc20 reads
 *   fpu: mtc1 reinterprets v0 at 0x1afc4c
 *   fpu: mtc1 reinterprets v1 at 0x1afc60
 *   fpu: float literal 0x37800080 at 0x1afc7c
 *   fpu: mtc1 reinterprets v0 at 0x1afc88
 *   fpu: mtc1 reinterprets v1 at 0x1afca0
 *   fpu: float literal 0x3f000000 at 0x1afcb8
 *   fpu: mtc1 reinterprets v1 at 0x1afccc
 *   fpu: float literal 0x4f000000 at 0x1afcd0
 *   fpu: mtc1 reinterprets v0 at 0x1afd2c
 *   fpu: mtc1 reinterprets v1 at 0x1afd40
 *   fpu: float literal 0x37800080 at 0x1afd5c
 *   fpu: float literal 0x42c80000 at 0x1afd64
 *   fpu: float literal 0x3f000000 at 0x1afd70
 *   fpu: mtc1 reinterprets v0 at 0x1afd9c
 *   fpu: mtc1 reinterprets v1 at 0x1afdb0
 *   fpu: float literal 0x37800080 at 0x1afdcc
 *   fpu: float literal 0x42c80000 at 0x1afdd4
 *   fpu: float literal 0x3f000000 at 0x1afde0
 *   fpu: mtc1 reinterprets v0 at 0x1afe0c
 *   fpu: mtc1 reinterprets v1 at 0x1afe20
 *   fpu: float literal 0x37800080 at 0x1afe3c
 *   fpu: float literal 0x42c80000 at 0x1afe44
 *   fpu: float literal 0x3f000000 at 0x1afe50
 *   fpu: mtc1 reinterprets v0 at 0x1afe7c
 *   fpu: mtc1 reinterprets v1 at 0x1afe90
 *   fpu: float literal 0x37800080 at 0x1afeb0
 *   fpu: float literal 0x42c80000 at 0x1afeb4
 *   fpu: float literal 0x3f000000 at 0x1afec8
 *   stack: address of the slot at 0x1d0 escapes at 0x1afee8
 *   fpu: float literal 0x00000000 at 0x1aff08
 *   fpu: mtc1 reinterprets v0 at 0x1aff30
 *   fpu: mtc1 reinterprets v1 at 0x1aff44
 *   fpu: float literal 0x37800080 at 0x1aff60
 *   fpu: float literal 0x3f000000 at 0x1aff6c
 *   fpu: float literal 0x00000000 at 0x1aff9c
 *   fpu: mtc1 reinterprets v0 at 0x1affc4
 *   fpu: mtc1 reinterprets v1 at 0x1affd8
 *   fpu: float literal 0x37800080 at 0x1afff4
 *   fpu: float literal 0x3f000000 at 0x1b0000
 *   fpu: float literal 0x00000000 at 0x1b0024
 *   fpu: mtc1 reinterprets v0 at 0x1b004c
 *   fpu: mtc1 reinterprets v1 at 0x1b0060
 *   fpu: float literal 0x37800080 at 0x1b007c
 *   fpu: float literal 0x3f000000 at 0x1b0088
 *   fpu: float literal 0x3c8ef34d at 0x1b00b4
 *   fpu: float literal 0x00000000 at 0x1b00b8
 *   stack: address of the slot at 0x1e0 escapes at 0x1b00c0
 *   stack: address of the slot at 0x1e0 escapes at 0x1b00d0
 *   stack: address of the slot at 0x1d0 escapes at 0x1b00d0
 *   fpu: float literal 0x00000000 at 0x1b00dc
 *   fpu: mtc1 reinterprets v0 at 0x1b0104
 *   fpu: mtc1 reinterprets v1 at 0x1b0118
 *   fpu: float literal 0x37800080 at 0x1b0134
 *   fpu: float literal 0x3f000000 at 0x1b0140
 *   fpu: float literal 0x00000000 at 0x1b0164
 *   fpu: mtc1 reinterprets v0 at 0x1b018c
 *   fpu: mtc1 reinterprets v1 at 0x1b01a0
 *   fpu: float literal 0x37800080 at 0x1b01bc
 *   fpu: float literal 0x3f000000 at 0x1b01c8
 *   fpu: float literal 0x00000000 at 0x1b01ec
 *   fpu: mtc1 reinterprets v0 at 0x1b0214
 *   fpu: mtc1 reinterprets v1 at 0x1b0228
 *   fpu: float literal 0x37800080 at 0x1b0244
 *   fpu: float literal 0x3f000000 at 0x1b0250
 *   fpu: float literal 0x3c8ef34d at 0x1b027c
 *   stack: address of the slot at 0xb0 escapes at 0x1b02c0
 *   fpu: float literal 0x3c23d70a at 0x1b02e0
 *   fpu: mtc1 reinterprets v1 at 0x1b02ec
 *   stack: address of the slot at 0xb8 escapes at 0x1b032c
 *   stack: address of the slot at 0xc0 escapes at 0x1b0348
 *   fpu: float literal 0x3c23d70a at 0x1b035c
 *   fpu: mtc1 reinterprets v1 at 0x1b036c
 *   fpu: mtc1 reinterprets v1 at 0x1b0394
 *   fpu: mtc1 reinterprets v1 at 0x1b03b8
 *   stack: address of the slot at 0xc0 escapes at 0x1b03d8
 *   stack: address of the slot at 0x22c escapes at 0x1b03f0
 *   fpu: mtc1 reinterprets v0 at 0x1b0404
 *   fpu: mtc1 reinterprets v1 at 0x1b0418
 *   fpu: float literal 0x43000000 at 0x1b042c
 *   fpu: mtc1 reinterprets v0 at 0x1b044c
 *   fpu: mtc1 reinterprets v1 at 0x1b0460
 *   fpu: float literal 0x43000000 at 0x1b0474
 *   fpu: mtc1 reinterprets v0 at 0x1b0494
 *   fpu: mtc1 reinterprets v1 at 0x1b04a8
 *   fpu: float literal 0x43000000 at 0x1b04c0
 *   stack: address of the slot at 0x22f escapes at 0x1b04dc
 *   fpu: mtc1 reinterprets v0 at 0x1b04f4
 *   fpu: mtc1 reinterprets v1 at 0x1b0508
 *   fpu: float literal 0x43000000 at 0x1b0520
 *   stack: address of the slot at 0xd0 escapes at 0x1b0560
 *   stack: address of the slot at 0xd0 escapes at 0x1b0578
 *   cfg: loop body is not one contiguous region: .L001AFC10
 *   v0#8 is the pointer held in a0+0x48
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void sceVu0UnitMatrix(void *);
extern void sceVu0CopyVector(void *, void *);
static void * _AllocPtcl(signed int num);
static void * _AllocPtcl(signed int num);
extern unsigned int SfxCalc_RandU32(void);
extern void SfxCalc_MakeMatrixFromPYR(void *, float, float, float);

extern void SfxUtil_CalcRndPos(float *, signed int, float *);

extern signed int SFX_ConfirmReflect();
extern unsigned short SfxMdl_Alloc(unsigned short, signed int);


extern signed int SfxMdl_SetZOffset(unsigned short, float);
static void _Model2_SetMdlParamToMdlMng(void *);
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif


struct dw_1890884_fields;
struct dw_1891466_fields;
struct dw_1892300_fields;
struct dw_1904865_fields;
struct dw_1905892_fields;
struct dw_1906538_fields;
#ifndef PROTO_DW_1898869_FIELDS
#define PROTO_DW_1898869_FIELDS
struct dw_1898869_fields { unsigned short disable_draw_scr : 1; unsigned short disable_draw_map : 1; unsigned short disable_act_scr : 1; unsigned short disable_act_map : 1; unsigned short unused : 12; };
#endif
#ifndef PROTO_DW_1890401_FIELDS
#define PROTO_DW_1890401_FIELDS
struct dw_1890401_fields { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float (*p_matrix)[4][4]; int prev_ptcl; short life_time; unsigned short ptcl_num; unsigned short prog_no; struct dw_1898869_fields flag; unsigned short sfx_sttdata_idx; unsigned char _pad0[14]; };
#endif
#ifndef PROTO_DW_1890884_FIELDS
#define PROTO_DW_1890884_FIELDS
struct dw_1890884_fields { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float rgba[4]; float n_speed[4]; float add_uv[2]; float dmy; char rand[4]; unsigned int lifecnt; unsigned int cnt; struct dw_1890884_fields *p_sibling; struct dw_1891466_fields *pEmitter; unsigned char extra_data[32]; float qtn[4]; };
#endif
#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS
struct dw_1916235_fields { unsigned short disable_draw : 1; unsigned short disable_draw_by_map : 1; unsigned short disable_act : 1; unsigned short disable_act_by_map : 1; unsigned short draw_stage : 4; unsigned short unused : 8; };
#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS
struct dw_1891466_fields { float matrix[4][4]; float (*p_matrix)[4][4]; unsigned short prog_no; unsigned char ptcl_num; unsigned char dmy; struct dw_1890884_fields *p_ptcl_top; struct dw_1904865_fields *p_fix_param; struct dw_1905892_fields *p_seq_param; struct dw_1891466_fields *p_prev; struct dw_1891466_fields *p_next; struct dw_1891466_fields *p_relation_prev; struct dw_1891466_fields *p_relation_next; unsigned int lifecnt; unsigned int cnt; struct dw_1916235_fields bit_flag; unsigned short sfx_sttdata_idx; unsigned short cframe; unsigned char dmy2[14]; unsigned char extra_data[32]; };
#endif
#ifndef PROTO_DW_1902102_FIELDS
#define PROTO_DW_1902102_FIELDS
struct dw_1902102_fields { unsigned int Frame; char szName[26]; unsigned short sfx_idx; };
#endif
#ifndef PROTO_DW_1892300_FIELDS
#define PROTO_DW_1892300_FIELDS
struct dw_1892300_fields { int ProgramId; struct dw_1892300_fields *pParent; struct dw_1892300_fields *pChild; struct dw_1892300_fields *pSibling; int FixParamNum; struct dw_1904865_fields *pFixParam; int SeqParamNum; struct dw_1905892_fields *pSeqParam; struct dw_1902102_fields CommonParam; };
#endif
#ifndef PROTO_DW_1904865_FIELDS
#define PROTO_DW_1904865_FIELDS
struct dw_1904865_fields { char cdummy; };
#endif
#ifndef PROTO_DW_1905892_FIELDS
#define PROTO_DW_1905892_FIELDS
struct dw_1905892_fields { unsigned int ParamSize; struct dw_1906538_fields *pKeyTop; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24 = (int)&(((struct dw_1890401_fields *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A = (int)&(((struct dw_1890401_fields *)0)->ptcl_num) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D = (int)&(((struct dw_1890401_fields *)0)->scale[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01 = (int)&(((struct dw_1890401_fields *)0)->scale[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2 = (int)&(((struct dw_1890401_fields *)0)->scale[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_CNT_43F0299F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_CNT_43F0299F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_CNT_43F0299F = (int)&(((struct dw_1890884_fields *)0)->cnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700 = (int)&(((struct dw_1890884_fields *)0)->lifecnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510 = (int)&(((struct dw_1890884_fields *)0)->pEmitter) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76 = (int)&(((struct dw_1890884_fields *)0)->p_sibling) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038 = (int)&(((struct dw_1890884_fields *)0)->rand[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C = (int)&(((struct dw_1890884_fields *)0)->rand[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC = (int)&(((struct dw_1890884_fields *)0)->rand[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F = (int)&(((struct dw_1890884_fields *)0)->rand[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_0__89D82EC2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_0__89D82EC2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_0__89D82EC2 = (int)&(((struct dw_1890884_fields *)0)->rgba[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_1__872F13A5_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_1__872F13A5_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_1__872F13A5 = (int)&(((struct dw_1890884_fields *)0)->rgba[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_2__2B1C9A34_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_2__2B1C9A34_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_2__2B1C9A34 = (int)&(((struct dw_1890884_fields *)0)->rgba[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_3__47898D35_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_3__47898D35_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_3__47898D35 = (int)&(((struct dw_1890884_fields *)0)->rgba[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_0__A4EC329F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_0__A4EC329F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_0__A4EC329F = (int)&(((struct dw_1890884_fields *)0)->scale[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_1__0DD44650_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_1__0DD44650_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_1__0DD44650 = (int)&(((struct dw_1890884_fields *)0)->scale[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_2__ED13F378_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_2__ED13F378_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_2__ED13F378 = (int)&(((struct dw_1890884_fields *)0)->scale[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD = (int)&(((struct dw_1891466_fields *)0)->lifecnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7 = (int)&(((struct dw_1891466_fields *)0)->matrix[0][0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9 = (int)&(((struct dw_1891466_fields *)0)->matrix[1][1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0 = (int)&(((struct dw_1891466_fields *)0)->matrix[2][2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571 = (int)&(((struct dw_1891466_fields *)0)->p_fix_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B = (int)&(((struct dw_1891466_fields *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087 = (int)&(((struct dw_1891466_fields *)0)->p_ptcl_top) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20 = (int)&(((struct dw_1891466_fields *)0)->p_seq_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B = (int)&(((struct dw_1891466_fields *)0)->ptcl_num) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_SFX_STTDATA_IDX_BFD85288_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_SFX_STTDATA_IDX_BFD85288_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_SFX_STTDATA_IDX_BFD85288 = (int)&(((struct dw_1891466_fields *)0)->sfx_sttdata_idx) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F = (int)&(((struct dw_1892300_fields *)0)->pFixParam) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D = (int)&(((struct dw_1892300_fields *)0)->pSeqParam) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1904865_FIELDS__81__CDUMMY_9F800173_DEFINED
#define DCOMP_OFF_STRUCT_DW_1904865_FIELDS__81__CDUMMY_9F800173_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1904865_FIELDS__81__CDUMMY_9F800173 = (int)&(((struct dw_1904865_fields *)0)[81].cdummy) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1905892_FIELDS__3__PKEYTOP_4BDB433E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1905892_FIELDS__3__PKEYTOP_4BDB433E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1905892_FIELDS__3__PKEYTOP_4BDB433E = (int)&(((struct dw_1905892_fields *)0)[3].pKeyTop) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1905892_FIELDS__4__PKEYTOP_A9D4A4E0_DEFINED
#define DCOMP_OFF_STRUCT_DW_1905892_FIELDS__4__PKEYTOP_A9D4A4E0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1905892_FIELDS__4__PKEYTOP_A9D4A4E0 = (int)&(((struct dw_1905892_fields *)0)[4].pKeyTop) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1905892_FIELDS__5__PKEYTOP_AC5C6D3D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1905892_FIELDS__5__PKEYTOP_AC5C6D3D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1905892_FIELDS__5__PKEYTOP_AC5C6D3D = (int)&(((struct dw_1905892_fields *)0)[5].pKeyTop) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1905892_FIELDS__6__PKEYTOP_609FF26B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1905892_FIELDS__6__PKEYTOP_609FF26B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1905892_FIELDS__6__PKEYTOP_609FF26B = (int)&(((struct dw_1905892_fields *)0)[6].pKeyTop) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1905892_FIELDS__7__PKEYTOP_A318AB84_DEFINED
#define DCOMP_OFF_STRUCT_DW_1905892_FIELDS__7__PKEYTOP_A318AB84_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1905892_FIELDS__7__PKEYTOP_A318AB84 = (int)&(((struct dw_1905892_fields *)0)[7].pKeyTop) - 0 };
#endif
#define PTCL_RNDRANGE(dst, b, r) \
    if (0.0f < (r)) { \
        float rr_ = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32(); \
        (dst) = (b) + (r) * (rr_ - 0.5f); \
    } else { \
        (dst) = (b); \
    }


/* __SFX_EndPtclPlume @ 0x1B0600 .. 0x1B062C (0x2c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   a1 typed from the __SFX_EndPtclPlume call table
 *   a2 typed from the __SFX_EndPtclPlume call table
 */

extern signed int SfxMdl_Free(unsigned short);

static u32 s_mngp;
/* __SFX_ActPlume @ 0x1B0650 .. 0x1B0940 (0x2f0 bytes, frame 0xe0) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1b069c is a float copy
 *   stack: address of the slot at 0xd0 escapes at 0x1b06a0
 *   fpu: mov.s at 0x1b075c is a float copy
 *   delay: addiu at 0x1b0788 writes a register its branch at 0x1b0784 reads
 *   stack: address of the slot at 0xa0 escapes at 0x1b07a0
 *   stack: address of the slot at 0xa0 escapes at 0x1b089c
 *   cfg: kept goto: 0x1b0660 -> .L001B08E8
 *   cfg: loop body is not one contiguous region: .L001B08E8
 *   cfg: kept branch: 0x1b08fc if (..) goto .L001B06A0
 *   s0#2 is the pointer held in a0+0x48
 *   v1#10 is the pointer held in s0#1+0xa8
 *   a2 typed from the __SFX_ActPlume call table
 */

extern void * memset(void *, int, unsigned int);
static void _SubFunc_Plume_Move(void *p_ptcl_v , float dt_ );
static void _SubFunc_Plume_Move(void *, float);
extern void SfxCalc_MakeMatrixFromQtn(void *, float *);
extern void sceVu0CopyVector(void *, void *);
extern signed int SfxMdl_SetMatrix(unsigned short, void *);
extern signed int SfxMdl_SetColor(unsigned short, float, float, float);
extern signed int SfxMdl_SetAlpha(unsigned short, float);
extern signed int SfxMdl_SetTexScroll(unsigned short, float, float);

extern u32 s_FuncTable[];
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif


/* __SFX_InitPlume @ 0x1B0940 .. 0x1B108C (0x74c bytes, frame 0x230) */
/*
 * dcomp notes:
 *   literal: @3373 is the string 'PtclMng.c'
 *   literal: @3668 is the string '3DÓÃÞÙ\x8a\x84\x82è\x93\x96\x82Ä\x8e¸\x94s'
 *   stack: address of the slot at 0xa8 escapes at 0x1b09d0
 *   stack: address of the slot at 0xe0 escapes at 0x1b09d0
 *   fpu: mtc1 reinterprets v0 at 0x1b0a14
 *   fpu: mtc1 reinterprets v1 at 0x1b0a28
 *   fpu: float literal 0x37800080 at 0x1b0a44
 *   fpu: float literal 0x42c80000 at 0x1b0a4c
 *   fpu: float literal 0x3f000000 at 0x1b0a58
 *   fpu: mtc1 reinterprets v0 at 0x1b0a84
 *   fpu: mtc1 reinterprets v1 at 0x1b0a98
 *   fpu: float literal 0x37800080 at 0x1b0ab4
 *   fpu: float literal 0x42c80000 at 0x1b0abc
 *   fpu: float literal 0x3f000000 at 0x1b0ac8
 *   fpu: mtc1 reinterprets v0 at 0x1b0af4
 *   fpu: mtc1 reinterprets v1 at 0x1b0b08
 *   fpu: float literal 0x37800080 at 0x1b0b24
 *   fpu: float literal 0x42c80000 at 0x1b0b2c
 *   fpu: float literal 0x3f000000 at 0x1b0b38
 *   fpu: mtc1 reinterprets v0 at 0x1b0b64
 *   fpu: mtc1 reinterprets v1 at 0x1b0b78
 *   fpu: float literal 0x37800080 at 0x1b0b94
 *   fpu: float literal 0x42c80000 at 0x1b0b9c
 *   fpu: float literal 0x3f000000 at 0x1b0ba8
 *   fpu: mtc1 reinterprets v0 at 0x1b0be8
 *   fpu: mtc1 reinterprets v1 at 0x1b0bfc
 *   fpu: float literal 0x37800080 at 0x1b0c14
 *   fpu: mtc1 reinterprets v0 at 0x1b0c2c
 *   fpu: mtc1 reinterprets v1 at 0x1b0c40
 *   fpu: float literal 0x37800080 at 0x1b0c5c
 *   fpu: float literal 0x3f000000 at 0x1b0c70
 *   fpu: float literal 0x40c90fdb at 0x1b0c74
 *   fpu: float literal 0x00000000 at 0x1b0c84
 *   stack: address of the slot at 0xa0 escapes at 0x1b0cb4
 *   fpu: mtc1 reinterprets v0 at 0x1b0ce4
 *   fpu: mtc1 reinterprets v1 at 0x1b0cf8
 *   fpu: float literal 0x37800080 at 0x1b0d18
 *   fpu: float literal 0x3f000000 at 0x1b0d28
 *   stack: address of the slot at 0xa0 escapes at 0x1b0d3c
 *   stack: address of the slot at 0x1f0 escapes at 0x1b0d48
 *   stack: address of the slot at 0x1f0 escapes at 0x1b0d58
 *   fpu: mtc1 reinterprets v0 at 0x1b0e04
 *   fpu: mtc1 reinterprets v1 at 0x1b0e18
 *   fpu: float literal 0x37800080 at 0x1b0e34
 *   fpu: float literal 0x3f000000 at 0x1b0e40
 *   fpu: mtc1 reinterprets v0 at 0x1b0e68
 *   fpu: mtc1 reinterprets v1 at 0x1b0e7c
 *   fpu: float literal 0x37800080 at 0x1b0e98
 *   fpu: float literal 0x3f000000 at 0x1b0ea4
 *   fpu: mtc1 reinterprets v0 at 0x1b0ecc
 *   fpu: mtc1 reinterprets v1 at 0x1b0ee0
 *   fpu: float literal 0x37800080 at 0x1b0efc
 *   fpu: float literal 0x3f000000 at 0x1b0f08
 *   stack: address of the slot at 0xf0 escapes at 0x1b0f50
 *   stack: address of the slot at 0xf0 escapes at 0x1b0f68
 *   stack: address of the slot at 0xb0 escapes at 0x1b0f80
 *   stack: address of the slot at 0xb0 escapes at 0x1b1008
 *   cfg: loop body is not one contiguous region: .L001B09D0
 *   v0#4 is the pointer held in a0+0x48
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void sceVu0CopyMatrix(void *, void *);
static void * _AllocPtcl(signed int num);
extern unsigned int SfxCalc_RandU32(void);
extern void SfxCalc_QtnMakeFromPYR(float *, float, float, float);
extern void SfxCalc_QtnMakeFromMatrix(float *, void *);
extern void sceVu0ApplyMatrix(void *,void *,void *);
extern void SfxUtil_CalcRndPos(float *, signed int, float *);
extern void sceVu0AddVector(void *, void *, void *);
extern signed int SFX_ConfirmReflect();
extern unsigned short SfxMdl_Alloc(unsigned short, signed int);
extern char * strcpy(char *, const char *);
extern void SfxDbg_SetDebugMsg(unsigned char, char *, char *, unsigned int);
extern u32 MRX1[];
extern u32 V1[];
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif


struct dw_1890884_fields;
struct dw_1891466_fields;
struct dw_1892300_fields;
struct dw_1904865_fields;
struct dw_1905892_fields;
#ifndef PROTO_DW_1898869_FIELDS
#define PROTO_DW_1898869_FIELDS
struct dw_1898869_fields { unsigned short disable_draw_scr : 1; unsigned short disable_draw_map : 1; unsigned short disable_act_scr : 1; unsigned short disable_act_map : 1; unsigned short unused : 12; };
#endif
#ifndef PROTO_DW_1890401_FIELDS
#define PROTO_DW_1890401_FIELDS
struct dw_1890401_fields { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float (*p_matrix)[4][4]; int prev_ptcl; short life_time; unsigned short ptcl_num; unsigned short prog_no; struct dw_1898869_fields flag; unsigned short sfx_sttdata_idx; unsigned char _pad0[14]; };
#endif
#ifndef PROTO_DW_1890884_FIELDS
#define PROTO_DW_1890884_FIELDS
struct dw_1890884_fields { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float rgba[4]; float n_speed[4]; float add_uv[2]; float dmy; char rand[4]; unsigned int lifecnt; unsigned int cnt; struct dw_1890884_fields *p_sibling; struct dw_1891466_fields *pEmitter; unsigned char extra_data[32]; float qtn[4]; };
#endif
#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS
struct dw_1916235_fields { unsigned short disable_draw : 1; unsigned short disable_draw_by_map : 1; unsigned short disable_act : 1; unsigned short disable_act_by_map : 1; unsigned short draw_stage : 4; unsigned short unused : 8; };
#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS
struct dw_1891466_fields { float matrix[4][4]; float (*p_matrix)[4][4]; unsigned short prog_no; unsigned char ptcl_num; unsigned char dmy; struct dw_1890884_fields *p_ptcl_top; struct dw_1904865_fields *p_fix_param; struct dw_1905892_fields *p_seq_param; struct dw_1891466_fields *p_prev; struct dw_1891466_fields *p_next; struct dw_1891466_fields *p_relation_prev; struct dw_1891466_fields *p_relation_next; unsigned int lifecnt; unsigned int cnt; struct dw_1916235_fields bit_flag; unsigned short sfx_sttdata_idx; unsigned short cframe; unsigned char dmy2[14]; unsigned char extra_data[32]; };
#endif
#ifndef PROTO_DW_1902102_FIELDS
#define PROTO_DW_1902102_FIELDS
struct dw_1902102_fields { unsigned int Frame; char szName[26]; unsigned short sfx_idx; };
#endif
#ifndef PROTO_DW_1892300_FIELDS
#define PROTO_DW_1892300_FIELDS
struct dw_1892300_fields { int ProgramId; struct dw_1892300_fields *pParent; struct dw_1892300_fields *pChild; struct dw_1892300_fields *pSibling; int FixParamNum; struct dw_1904865_fields *pFixParam; int SeqParamNum; struct dw_1905892_fields *pSeqParam; struct dw_1902102_fields CommonParam; };
#endif
#ifndef PROTO_DW_1904865_FIELDS
#define PROTO_DW_1904865_FIELDS
struct dw_1904865_fields { char cdummy; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24 = (int)&(((struct dw_1890401_fields *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A = (int)&(((struct dw_1890401_fields *)0)->ptcl_num) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ADD_UV_0__91FC4FD4_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ADD_UV_0__91FC4FD4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ADD_UV_0__91FC4FD4 = (int)&(((struct dw_1890884_fields *)0)->add_uv[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ADD_UV_1__B796255F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ADD_UV_1__B796255F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ADD_UV_1__B796255F = (int)&(((struct dw_1890884_fields *)0)->add_uv[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700 = (int)&(((struct dw_1890884_fields *)0)->lifecnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED = (int)&(((struct dw_1890884_fields *)0)->loc[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510 = (int)&(((struct dw_1890884_fields *)0)->pEmitter) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76 = (int)&(((struct dw_1890884_fields *)0)->p_sibling) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038 = (int)&(((struct dw_1890884_fields *)0)->rand[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C = (int)&(((struct dw_1890884_fields *)0)->rand[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC = (int)&(((struct dw_1890884_fields *)0)->rand[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F = (int)&(((struct dw_1890884_fields *)0)->rand[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_0__89D82EC2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_0__89D82EC2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_0__89D82EC2 = (int)&(((struct dw_1890884_fields *)0)->rgba[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_1__872F13A5_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_1__872F13A5_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_1__872F13A5 = (int)&(((struct dw_1890884_fields *)0)->rgba[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_2__2B1C9A34_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_2__2B1C9A34_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_2__2B1C9A34 = (int)&(((struct dw_1890884_fields *)0)->rgba[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_3__47898D35_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_3__47898D35_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_3__47898D35 = (int)&(((struct dw_1890884_fields *)0)->rgba[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD = (int)&(((struct dw_1891466_fields *)0)->lifecnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571 = (int)&(((struct dw_1891466_fields *)0)->p_fix_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B = (int)&(((struct dw_1891466_fields *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087 = (int)&(((struct dw_1891466_fields *)0)->p_ptcl_top) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20 = (int)&(((struct dw_1891466_fields *)0)->p_seq_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B = (int)&(((struct dw_1891466_fields *)0)->ptcl_num) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_SFX_STTDATA_IDX_BFD85288_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_SFX_STTDATA_IDX_BFD85288_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_SFX_STTDATA_IDX_BFD85288 = (int)&(((struct dw_1891466_fields *)0)->sfx_sttdata_idx) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F = (int)&(((struct dw_1892300_fields *)0)->pFixParam) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D = (int)&(((struct dw_1892300_fields *)0)->pSeqParam) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1904865_FIELDS__23__CDUMMY_8292A35A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1904865_FIELDS__23__CDUMMY_8292A35A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1904865_FIELDS__23__CDUMMY_8292A35A = (int)&(((struct dw_1904865_fields *)0)[23].cdummy) - 0 };
#endif
void __SFX_ActAnimSprite(void *a0 , float f12 );




extern void __SFX_ActAnimSprite(void *, float);
void __SFX_ActAnimSprite2(void *a0 , float f12 );
extern void __SFX_ActAnimSprite2(void *, float);
void __SFX_ActConnectedSprite(void *a0 , float f12 );
extern void __SFX_ActConnectedSprite(void *, float);
void __SFX_ActDefault(void *a0 , float f12 );
extern void __SFX_ActDefault(void *, float);
void __SFX_ActDistortion(void *a0 , float f12 );
extern void __SFX_ActDistortion(void *, float);
void __SFX_ActFireFly(void *a0 , float f12 );
extern void __SFX_ActFireFly(void *, float);
void __SFX_ActModel2(void *a0 , float f12 );
extern void __SFX_ActModel2(void *, float);
void __SFX_ActPlume(void *a0 , float f12 );
extern void __SFX_ActPlume(void *, float);
void __SFX_ActSprite(void *a0 , float f12 );
extern void __SFX_ActSprite(void *, float);
void __SFX_ActSprite2(void *a0 , float f12 );
extern void __SFX_ActSprite2(void *, float);
void __SFX_ActTracer(void *a0 , float f12 );
extern void __SFX_ActTracer(void *, float);
static void __SFX_DrawAnimSprite(void *a0 );
static void __SFX_DrawAnimSprite(void *);
static void __SFX_DrawAnimSprite2(void *a0 );
static void __SFX_DrawAnimSprite2(void *);
static void __SFX_DrawConnectedSprite(void *a0 );
static void __SFX_DrawConnectedSprite(void *);
static void __SFX_DrawDistortion(void *a0 );
static void __SFX_DrawDistortion(void *a0 /* r4 */);
static void __SFX_DrawFireFly(u8 *a0 , u8 *a1 , u32 *a2 );
static void __SFX_DrawFireFly(u8 *a0 /* r4 */, u8 *a1 /* r5 */, u32 *a2 /* r6 */);
void __SFX_DrawPtclAnimSprite(void *object);
extern void __SFX_DrawPtclAnimSprite(void *);
void __SFX_DrawPtclAnimSprite2(void *object);
extern void __SFX_DrawPtclAnimSprite2(void *);
void __SFX_DrawPtclConnectedSprite(void *a0 );
extern void __SFX_DrawPtclConnectedSprite(void *);
static void __SFX_DrawPtclDistortion(void *a0 );
static void __SFX_DrawPtclDistortion(void *a0 /* r4 */);
static void __SFX_DrawPtclFireFly(void *a0 );
static void __SFX_DrawPtclFireFly(void *);
void __SFX_DrawPtclSprite(void *a0 );
extern void __SFX_DrawPtclSprite(void *);
void __SFX_DrawPtclSprite2(void *particle);
extern void __SFX_DrawPtclSprite2(void *);
static void __SFX_DrawSprite(void *a0 );
static void __SFX_DrawSprite(void *);
void __SFX_DrawSprite2(void *a0 );
extern void __SFX_DrawSprite2(void *);
static void __SFX_EndPtclConnectedSprite(u8 *a0 , u8 *a1 , u32 *a2 );
static void __SFX_EndPtclConnectedSprite(u8 *a0 /* r4 */, u8 *a1 /* r5 */, u32 *a2 /* r6 */);
static void __SFX_EndPtclDefault(u16 *a0 , u8 *a1 , u32 *a2 );
static void __SFX_EndPtclDefault(u16 *a0 /* r4 */, u8 *a1 /* r5 */, u32 *a2 /* r6 */);
static void __SFX_EndPtclDistortion(u16 *a0 , u8 *a1 , u32 *a2 );
static void __SFX_EndPtclDistortion(u16 *a0 /* r4 */, u8 *a1 /* r5 */, u32 *a2 /* r6 */);
static void __SFX_EndPtclTracer(u16 *a0 , u8 *a1 , u32 *a2 );
static void __SFX_EndPtclTracer(u16 *a0 /* r4 */, u8 *a1 /* r5 */, u32 *a2 /* r6 */);
void __SFX_InitAnimSprite(void *a0 , void *a1 , void *a2 );
extern void __SFX_InitAnimSprite(void *, void *, void *);
void __SFX_InitAnimSprite2(void *a0 , void *a1 , void *a2 );
extern void __SFX_InitAnimSprite2(void *, void *, void *);
void __SFX_InitConnectedSprite(void *a0 , void *a1 , void *a2 );
extern void __SFX_InitConnectedSprite(void *, void *, void *);
void __SFX_InitDefault(void *a0 , void *a1 , void *a2 );
extern void __SFX_InitDefault(void *, void *, void *);
void __SFX_InitDistortion(void *a0 , void *a1 , void *a2 );
extern void __SFX_InitDistortion(void *, void *, void *);
void __SFX_InitFireFly(void *a0 , void *a1 , void *a2 );
extern void __SFX_InitFireFly(void *, void *, void *);
void __SFX_InitModel2(void *a0 , void *a1 , void *a2 );
extern void __SFX_InitModel2(void *, void *, void *);
void __SFX_InitPlume(void *a0 , void *a1 , void *a2 );
extern void __SFX_InitPlume(void *, void *, void *);
void __SFX_InitSprite(void *a0 , void *a1 , void *a2 );
extern void __SFX_InitSprite(void *, void *, void *);
void __SFX_InitSprite2(void *a0 , void *a1 , void *a2 );
extern void __SFX_InitSprite2(void *, void *, void *);
void __SFX_InitTracer(void *a0 , void *a1 , void *a2 );
extern void __SFX_InitTracer(void *, void *, void *);
static void __SFX_DrawPlume(u8 *a0 , u8 *a1 , u32 *a2 );
static void __SFX_DrawPtclPlume(u8 *a0 , u8 *a1 , u32 *a2 );
static void __SFX_EndPtclPlume(u16 *a0 , u8 *a1 , u32 *a2 );
static void __SFX_EndPtclModel2(u16 *a0 , u8 *a1 , u32 *a2 );
static u32 s_FuncTable[0x3c] = {
    0, 0, 0, 0, 0, (u32)&__SFX_InitDefault, (u32)&__SFX_ActDefault, 0, 0,
    (u32)&__SFX_EndPtclDefault, (u32)&__SFX_InitSprite, (u32)&__SFX_ActSprite,
    (u32)&__SFX_DrawSprite, (u32)&__SFX_DrawPtclSprite, 0, (u32)&__SFX_InitDistortion,
    (u32)&__SFX_ActDistortion, (u32)&__SFX_DrawDistortion, (u32)&__SFX_DrawPtclDistortion,
    (u32)&__SFX_EndPtclDistortion, (u32)&__SFX_InitTracer, (u32)&__SFX_ActTracer, 0, 0,
    (u32)&__SFX_EndPtclTracer, (u32)&__SFX_InitConnectedSprite, (u32)&__SFX_ActConnectedSprite,
    (u32)&__SFX_DrawConnectedSprite, (u32)&__SFX_DrawPtclConnectedSprite,
    (u32)&__SFX_EndPtclConnectedSprite, (u32)&__SFX_InitSprite2, (u32)&__SFX_ActSprite2,
    (u32)&__SFX_DrawSprite2, (u32)&__SFX_DrawPtclSprite2, 0, (u32)&__SFX_InitAnimSprite,
    (u32)&__SFX_ActAnimSprite, (u32)&__SFX_DrawAnimSprite, (u32)&__SFX_DrawPtclAnimSprite, 0,
    (u32)&__SFX_InitAnimSprite2, (u32)&__SFX_ActAnimSprite2, (u32)&__SFX_DrawAnimSprite2,
    (u32)&__SFX_DrawPtclAnimSprite2, 0, (u32)&__SFX_InitFireFly, (u32)&__SFX_ActFireFly,
    (u32)&__SFX_DrawFireFly, (u32)&__SFX_DrawPtclFireFly, 0, (u32)&__SFX_InitPlume,
    (u32)&__SFX_ActPlume, (u32)&__SFX_DrawPlume, (u32)&__SFX_DrawPtclPlume,
    (u32)&__SFX_EndPtclPlume, (u32)&__SFX_InitModel2, (u32)&__SFX_ActModel2, 0, 0,
    (u32)&__SFX_EndPtclModel2
};
/* dcomp: UV template of __SFX_DrawPtclSprite2 (.data+0xf0): one file-scope
 * object that the function copies into its stack local. */
struct dcomp_uv { float f[4]; };
static struct dcomp_uv dcomp_uv_data __attribute__((aligned(16))) = {{0, 0, 1.0f, 1.0f}};

/* __SFX_DrawPtclFireFly @ 0x1B13C0 .. 0x1B154C (0x18c bytes, frame 0x80) */
/*
 * dcomp notes:
 *   literal: @2583 -> 0x248530
 *   stack: address of the slot at 0x60 escapes at 0x1b144c
 *   fpu: mtc1 reinterprets v0 at 0x1b1460
 *   stack: address of the slot at 0x6c escapes at 0x1b146c
 *   fpu: mtc1 reinterprets v1 at 0x1b1478
 *   fpu: float literal 0x42700000 at 0x1b148c
 *   fpu: float literal 0x40c90fdb at 0x1b14a4
 *   fpu: float literal 0x00000000 at 0x1b14b0
 *   fpu: float literal 0x00000000 at 0x1b1510
 *   stack: address of the slot at 0x70 escapes at 0x1b1520
 *   stack: address of the slot at 0x60 escapes at 0x1b1520
 *   stack: address of the slot at 0x50 escapes at 0x1b1520
 *   literal: @2583 initializes the 16-byte local at 0x50
 *   quad: a0: 128-bit web split from its scalar variable as a0_q
 *   quad: v0: 128-bit web split from its scalar variable as v0_q2
 *   cfg: kept branch: 0x1b13fc if (..) goto .L001B1530
 *   a1 typed from the __SFX_DrawPtclFireFly call table
 *   a2 typed from the __SFX_DrawPtclFireFly call table
 */

extern signed int SFX_ConfirmReflect();
extern signed int SfxCalc_CheckInsightCamera(float *);
extern void sceVu0CopyVector(void *, void *);
extern float SfxCalc_Cos(float);
extern u_long128 SfxDraw_GetRenderStateBlock(void);
extern void SfxDraw_UseTexture(signed int);
extern void SfxDraw_SetBlendType(unsigned short);
extern void SfxDraw_SetTexture(void *);
extern void SfxDraw_EnableFog(signed int);
extern void SfxDraw_UseST(signed int);
extern void SfxDraw_DrawSprite_Wld(float *, void *, float, void *, void *, float);
extern void SfxDraw_SetRenderStateBlock(u_long128);
extern u32 s_mngp;
extern u32 V1[];

/* __SFX_ActFireFly @ 0x1B1560 .. 0x1B1868 (0x308 bytes, frame 0xd0) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40000000 at 0x1b156c
 *   fpu: mov.s at 0x1b15b0 is a float copy
 *   fpu: float literal 0x00000000 at 0x1b168c
 *   fpu: mtc1 reinterprets v0 at 0x1b16e8
 *   fpu: mtc1 reinterprets v1 at 0x1b16fc
 *   fpu: float literal 0x37800080 at 0x1b1718
 *   fpu: float literal 0x40a00000 at 0x1b171c
 *   stack: address of the slot at 0xc0 escapes at 0x1b1738
 *   stack: address of the slot at 0xc0 escapes at 0x1b1744
 *   stack: address of the slot at 0xc0 escapes at 0x1b1744
 *   fpu: mov.s at 0x1b1750 is a float copy
 *   stack: address of the slot at 0xc0 escapes at 0x1b1754
 *   stack: address of the slot at 0xc0 escapes at 0x1b1754
 *   stack: address of the slot at 0xc0 escapes at 0x1b1764
 *   fpu: mov.s at 0x1b17bc is a float copy
 *   stack: address of the slot at 0xb0 escapes at 0x1b17b8
 *   stack: address of the slot at 0xb0 escapes at 0x1b17c8
 *   delay: addiu at 0x1b17ec writes a register its branch at 0x1b17e8 reads
 *   cfg: kept goto: 0x1b1564 -> .L001B1808
 *   cfg: loop body is not one contiguous region: .L001B1808
 *   cfg: kept branch: 0x1b181c if (..) goto .L001B15C8
 *   s2#2 is the pointer held in a0+0x48
 *   v1#11 is the pointer held in s2#1+0xa8
 *   a2 typed from the __SFX_ActFireFly call table
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void SfxUtil_CalcRndPos(float *, signed int, float *);
extern void sceVu0AddVector(void *, void *, void *);
extern unsigned int SfxCalc_RandU32(void);
extern void sceVu0SubVector(void *, void *, void *);
extern void sceVu0Normalize(void *, void *);
extern void sceVu0ScaleVector(void *, void *, float);
extern float sceVu0InnerProduct(void *,void *);

struct dw_1890884_fields;
struct dw_1891466_fields;
struct dw_1904865_fields;
struct dw_1905892_fields;
#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS
struct dw_1916235_fields { unsigned short disable_draw : 1; unsigned short disable_draw_by_map : 1; unsigned short disable_act : 1; unsigned short disable_act_by_map : 1; unsigned short draw_stage : 4; unsigned short unused : 8; };
#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS
struct dw_1891466_fields { float matrix[4][4]; float (*p_matrix)[4][4]; unsigned short prog_no; unsigned char ptcl_num; unsigned char dmy; struct dw_1890884_fields *p_ptcl_top; struct dw_1904865_fields *p_fix_param; struct dw_1905892_fields *p_seq_param; struct dw_1891466_fields *p_prev; struct dw_1891466_fields *p_next; struct dw_1891466_fields *p_relation_prev; struct dw_1891466_fields *p_relation_next; unsigned int lifecnt; unsigned int cnt; struct dw_1916235_fields bit_flag; unsigned short sfx_sttdata_idx; unsigned short cframe; unsigned char dmy2[14]; unsigned char extra_data[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571 = (int)&(((struct dw_1891466_fields *)0)->p_fix_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087 = (int)&(((struct dw_1891466_fields *)0)->p_ptcl_top) - 0 };
#endif


/* __SFX_InitFireFly @ 0x1B1870 .. 0x1B1D34 (0x4c4 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x1b1954
 *   fpu: mtc1 reinterprets v1 at 0x1b1968
 *   fpu: float literal 0x37800080 at 0x1b1984
 *   fpu: float literal 0x42c80000 at 0x1b198c
 *   fpu: float literal 0x3f000000 at 0x1b1998
 *   fpu: mtc1 reinterprets v0 at 0x1b19c4
 *   fpu: mtc1 reinterprets v1 at 0x1b19d8
 *   fpu: float literal 0x37800080 at 0x1b19f4
 *   fpu: float literal 0x42c80000 at 0x1b19fc
 *   fpu: float literal 0x3f000000 at 0x1b1a08
 *   fpu: mtc1 reinterprets v0 at 0x1b1a34
 *   fpu: mtc1 reinterprets v1 at 0x1b1a48
 *   fpu: float literal 0x37800080 at 0x1b1a64
 *   fpu: float literal 0x42c80000 at 0x1b1a6c
 *   fpu: float literal 0x3f000000 at 0x1b1a78
 *   fpu: mtc1 reinterprets v0 at 0x1b1aa4
 *   fpu: mtc1 reinterprets v1 at 0x1b1ab8
 *   fpu: float literal 0x37800080 at 0x1b1ad4
 *   fpu: float literal 0x42c80000 at 0x1b1adc
 *   fpu: float literal 0x3f000000 at 0x1b1ae8
 *   fpu: mtc1 reinterprets v0 at 0x1b1ba0
 *   fpu: mtc1 reinterprets v1 at 0x1b1bb4
 *   fpu: float literal 0x37800080 at 0x1b1bd0
 *   fpu: float literal 0x3f000000 at 0x1b1bd8
 *   fpu: float literal 0x3fc00000 at 0x1b1be4
 *   fpu: mtc1 reinterprets v0 at 0x1b1c08
 *   fpu: mtc1 reinterprets v1 at 0x1b1c1c
 *   fpu: float literal 0x37800080 at 0x1b1c3c
 *   fpu: float literal 0x3fc00000 at 0x1b1c54
 *   fpu: float literal 0x3f000000 at 0x1b1c58
 *   fpu: mtc1 reinterprets v1 at 0x1b1ca8
 *   fpu: mtc1 reinterprets a0 at 0x1b1cbc
 *   fpu: float literal 0x37800080 at 0x1b1cdc
 *   fpu: float literal 0x40a00000 at 0x1b1ce0
 *   cfg: loop body is not one contiguous region: .L001B1910
 *   v0#6 is the pointer held in a0+0x48
 *   a0 is the pointer held in s2#1+0xac
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void SfxCalc_MakeRotTransMatrix_I(void *, float *, float *, float *);
static void * _AllocPtcl(signed int num);
extern void SfxCalc_RotateVector(float *, float, float, float);
extern void sceVu0ApplyMatrix(void *,void *,void *);
static u8 s_mng[64];
static u8 s_aTexMng[0x400];
extern u32 MRX1[];



struct dw_1892300_fields;


#ifndef PROTO_DW_1898869_FIELDS
#define PROTO_DW_1898869_FIELDS
struct dw_1898869_fields { unsigned short disable_draw_scr : 1; unsigned short disable_draw_map : 1; unsigned short disable_act_scr : 1; unsigned short disable_act_map : 1; unsigned short unused : 12; };
#endif
#ifndef PROTO_DW_1890401_FIELDS
#define PROTO_DW_1890401_FIELDS
struct dw_1890401_fields { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float (*p_matrix)[4][4]; int prev_ptcl; short life_time; unsigned short ptcl_num; unsigned short prog_no; struct dw_1898869_fields flag; unsigned short sfx_sttdata_idx; unsigned char _pad0[14]; };
#endif
#ifndef PROTO_DW_1890884_FIELDS
#define PROTO_DW_1890884_FIELDS
struct dw_1890884_fields { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float rgba[4]; float n_speed[4]; float add_uv[2]; float dmy; char rand[4]; unsigned int lifecnt; unsigned int cnt; struct dw_1890884_fields *p_sibling; struct dw_1891466_fields *pEmitter; unsigned char extra_data[32]; float qtn[4]; };
#endif
#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif
#ifndef PROTO_DW_1902102_FIELDS
#define PROTO_DW_1902102_FIELDS
struct dw_1902102_fields { unsigned int Frame; char szName[26]; unsigned short sfx_idx; };
#endif
#ifndef PROTO_DW_1892300_FIELDS
#define PROTO_DW_1892300_FIELDS
struct dw_1892300_fields { int ProgramId; struct dw_1892300_fields *pParent; struct dw_1892300_fields *pChild; struct dw_1892300_fields *pSibling; int FixParamNum; struct dw_1904865_fields *pFixParam; int SeqParamNum; struct dw_1905892_fields *pSeqParam; struct dw_1902102_fields CommonParam; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_0__5ED7228F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_0__5ED7228F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_0__5ED7228F = (int)&(((struct dw_1890401_fields *)0)->ang[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_1__A795EEE1_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_1__A795EEE1_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_1__A795EEE1 = (int)&(((struct dw_1890401_fields *)0)->ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_2__3B661BD7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_2__3B661BD7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_2__3B661BD7 = (int)&(((struct dw_1890401_fields *)0)->ang[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24 = (int)&(((struct dw_1890401_fields *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A = (int)&(((struct dw_1890401_fields *)0)->ptcl_num) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700 = (int)&(((struct dw_1890884_fields *)0)->lifecnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED = (int)&(((struct dw_1890884_fields *)0)->loc[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E = (int)&(((struct dw_1890884_fields *)0)->n_speed[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9 = (int)&(((struct dw_1890884_fields *)0)->n_speed[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E = (int)&(((struct dw_1890884_fields *)0)->n_speed[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC = (int)&(((struct dw_1890884_fields *)0)->n_speed[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510 = (int)&(((struct dw_1890884_fields *)0)->pEmitter) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76 = (int)&(((struct dw_1890884_fields *)0)->p_sibling) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038 = (int)&(((struct dw_1890884_fields *)0)->rand[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C = (int)&(((struct dw_1890884_fields *)0)->rand[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC = (int)&(((struct dw_1890884_fields *)0)->rand[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F = (int)&(((struct dw_1890884_fields *)0)->rand[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD = (int)&(((struct dw_1891466_fields *)0)->lifecnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B = (int)&(((struct dw_1891466_fields *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20 = (int)&(((struct dw_1891466_fields *)0)->p_seq_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B = (int)&(((struct dw_1891466_fields *)0)->ptcl_num) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F = (int)&(((struct dw_1892300_fields *)0)->pFixParam) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D = (int)&(((struct dw_1892300_fields *)0)->pSeqParam) - 0 };
#endif


extern void sceVu0ApplyMatrix(void *,void *,void *);
extern u32 SFX_GetSettingData();
extern float sceVu0InnerProduct(void *,void *);
extern void SfxDraw_EnableZTest(int);

/* __SFX_ActAnimSprite2 @ 0x1B20C0 .. 0x1B2924 (0x864 bytes, frame 0x190) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1b2114 is a float copy
 *   stack: address of the slot at 0x178 escapes at 0x1b2204
 *   fpu: float literal 0x3c23d70a at 0x1b2220
 *   fpu: mtc1 reinterprets a0 at 0x1b2228
 *   fpu: float literal 0x3c8ef34d at 0x1b2250
 *   fpu: float literal 0xc0490fd0 at 0x1b2254
 *   fpu: float literal 0x40490fd0 at 0x1b2278
 *   fpu: float literal 0x40c90fd0 at 0x1b22a4
 *   stack: address of the slot at 0x140 escapes at 0x1b22c8
 *   fpu: float literal 0x3c23d70a at 0x1b22ec
 *   fpu: mtc1 reinterprets a0 at 0x1b22f8
 *   stack: address of the slot at 0x144 escapes at 0x1b2320
 *   stack: address of the slot at 0x148 escapes at 0x1b2334
 *   fpu: float literal 0x3c23d70a at 0x1b2350
 *   fpu: mtc1 reinterprets a0 at 0x1b2358
 *   fpu: mtc1 reinterprets v1 at 0x1b2380
 *   stack: address of the slot at 0x148 escapes at 0x1b23a0
 *   fpu: mov.s at 0x1b23ac is a float copy
 *   stack: address of the slot at 0x130 escapes at 0x1b23a8
 *   stack: address of the slot at 0x130 escapes at 0x1b23b8
 *   stack: address of the slot at 0x18c escapes at 0x1b23d4
 *   fpu: float literal 0x00000000 at 0x1b23e0
 *   stack: address of the slot at 0xe0 escapes at 0x1b2480
 *   stack: address of the slot at 0xe0 escapes at 0x1b2484
 *   stack: address of the slot at 0x120 escapes at 0x1b2494
 *   stack: address of the slot at 0xe8 escapes at 0x1b2494
 *   stack: address of the slot at 0xe0 escapes at 0x1b24ac
 *   stack: address of the slot at 0xe0 escapes at 0x1b24c0
 *   stack: address of the slot at 0xe0 escapes at 0x1b24c0
 *   stack: address of the slot at 0xe0 escapes at 0x1b2508
 *   stack: address of the slot at 0x160 escapes at 0x1b2508
 *   stack: address of the slot at 0xd0 escapes at 0x1b2514
 *   stack: address of the slot at 0x160 escapes at 0x1b2514
 *   stack: address of the slot at 0xd0 escapes at 0x1b2524
 *   stack: address of the slot at 0x188 escapes at 0x1b2544
 *   fpu: mtc1 reinterprets v0 at 0x1b2558
 *   fpu: mtc1 reinterprets v1 at 0x1b256c
 *   fpu: float literal 0x43000000 at 0x1b2580
 *   fpu: mtc1 reinterprets v0 at 0x1b25a0
 *   fpu: mtc1 reinterprets v1 at 0x1b25b4
 *   fpu: float literal 0x43000000 at 0x1b25c8
 *   fpu: mtc1 reinterprets v0 at 0x1b25e8
 *   fpu: mtc1 reinterprets v1 at 0x1b25fc
 *   fpu: float literal 0x43000000 at 0x1b2614
 *   stack: address of the slot at 0x18b escapes at 0x1b2630
 *   fpu: mtc1 reinterprets v1 at 0x1b2648
 *   fpu: mtc1 reinterprets a0 at 0x1b265c
 *   fpu: float literal 0x43000000 at 0x1b2670
 *   stack: address of the slot at 0x184 escapes at 0x1b26a4
 *   fpu: mtc1 reinterprets a0 at 0x1b26e8
 *   fpu: mtc1 reinterprets a1 at 0x1b2700
 *   fpu: mtc1 reinterprets a0 at 0x1b2740
 *   fpu: mtc1 reinterprets a1 at 0x1b2754
 *   fpu: float literal 0x3f800000 at 0x1b2768
 *   fpu: mtc1 reinterprets t0 at 0x1b2774
 *   fpu: mtc1 reinterprets a1 at 0x1b2788
 *   fpu: mtc1 reinterprets a0 at 0x1b27d0
 *   fpu: mtc1 reinterprets a1 at 0x1b27e8
 *   fpu: float literal 0x3f800000 at 0x1b27fc
 *   fpu: mtc1 reinterprets v1 at 0x1b2808
 *   fpu: mtc1 reinterprets a0 at 0x1b281c
 *   stack: address of the slot at 0x180 escapes at 0x1b2858
 *   delay: addiu at 0x1b2880 writes a register its branch at 0x1b287c reads
 *   cfg: kept goto: 0x1b20d8 -> .L001B28C8
 *   cfg: kept branch: 0x1b2270 if (..) goto .L001B2294
 *   cfg: loop body is not one contiguous region: .L001B28C8
 *   cfg: kept branch: 0x1b28dc if (..) goto .L001B2128
 *   s1#2 is the pointer held in a0+0x48
 *   v1#11 is the pointer held in s1#1+0xa8
 *   a2 typed from the __SFX_ActAnimSprite2 call table
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int SFX_GetSeqParam(void *, signed int, signed int, void *, signed int);
extern float SfxCalc_IntoAngle_0_2PI(float);
extern void sceVu0CopyMatrix(void *, void *);
extern void SfxCalc_Vector2Angle(float *, float *);
extern void sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0RotMatrixX(void *, void *, float);

extern u32 VY[];
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif

#ifndef DCOMP_COP2_21F95D43C1
#define DCOMP_COP2_21F95D43C1
static inline void dcomp_cop2_21F95D43C1(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf16,0(%2)\nvmulax.xyzw ACC,vf1,vf16x\nvmadday.xyzw ACC,vf2,vf16y\nvmaddaz.xyzw ACC,vf3,vf16z\nvmaddw.xyzw vf16,vf4,vf16w\nsqc2 vf16,0(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif






#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED

#endif


/* __SFX_InitAnimSprite2 @ 0x1B2930 .. 0x1B31D8 (0x8a8 bytes, frame 0xe0) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1b2984 writes a register its branch at 0x1b2980 reads
 *   stack: address of the slot at 0xd8 escapes at 0x1b2b40
 *   delay: lui at 0x1b2b50 writes a register its branch at 0x1b2b4c reads
 *   fpu: mtc1 reinterprets v0 at 0x1b2b74
 *   fpu: mtc1 reinterprets v1 at 0x1b2b88
 *   fpu: float literal 0x37800080 at 0x1b2ba4
 *   fpu: mtc1 reinterprets v0 at 0x1b2bb0
 *   fpu: mtc1 reinterprets v1 at 0x1b2bc8
 *   fpu: float literal 0x3f000000 at 0x1b2be0
 *   fpu: mtc1 reinterprets v1 at 0x1b2bf4
 *   fpu: float literal 0x4f000000 at 0x1b2bf8
 *   fpu: mtc1 reinterprets v0 at 0x1b2c54
 *   fpu: mtc1 reinterprets v1 at 0x1b2c68
 *   fpu: float literal 0x37800080 at 0x1b2c84
 *   fpu: float literal 0x42c80000 at 0x1b2c8c
 *   fpu: float literal 0x3f000000 at 0x1b2c98
 *   fpu: mtc1 reinterprets v0 at 0x1b2cc4
 *   fpu: mtc1 reinterprets v1 at 0x1b2cd8
 *   fpu: float literal 0x37800080 at 0x1b2cf4
 *   fpu: float literal 0x42c80000 at 0x1b2cfc
 *   fpu: float literal 0x3f000000 at 0x1b2d08
 *   fpu: mtc1 reinterprets v0 at 0x1b2d34
 *   fpu: mtc1 reinterprets v1 at 0x1b2d48
 *   fpu: float literal 0x37800080 at 0x1b2d64
 *   fpu: float literal 0x42c80000 at 0x1b2d6c
 *   fpu: float literal 0x3f000000 at 0x1b2d78
 *   fpu: mtc1 reinterprets v0 at 0x1b2da4
 *   fpu: mtc1 reinterprets v1 at 0x1b2db8
 *   fpu: float literal 0x37800080 at 0x1b2dd4
 *   fpu: float literal 0x42c80000 at 0x1b2ddc
 *   fpu: float literal 0x3f000000 at 0x1b2de8
 *   fpu: mtc1 reinterprets v0 at 0x1b2e20
 *   fpu: mtc1 reinterprets v1 at 0x1b2e34
 *   fpu: float literal 0x37800080 at 0x1b2e54
 *   fpu: float literal 0x3f000000 at 0x1b2e58
 *   fpu: float literal 0x3c8ef34d at 0x1b2e88
 *   stack: address of the slot at 0xd0 escapes at 0x1b2ea0
 *   fpu: float literal 0x00000000 at 0x1b2ec0
 *   fpu: mtc1 reinterprets v0 at 0x1b2ee8
 *   fpu: mtc1 reinterprets v1 at 0x1b2efc
 *   fpu: float literal 0x37800080 at 0x1b2f18
 *   fpu: float literal 0x3f000000 at 0x1b2f24
 *   fpu: float literal 0x00000000 at 0x1b2f50
 *   fpu: mtc1 reinterprets v0 at 0x1b2f78
 *   fpu: mtc1 reinterprets v1 at 0x1b2f8c
 *   fpu: float literal 0x37800080 at 0x1b2fa8
 *   fpu: float literal 0x3f000000 at 0x1b2fb4
 *   fpu: float literal 0x00000000 at 0x1b2fdc
 *   fpu: mtc1 reinterprets v0 at 0x1b3004
 *   fpu: mtc1 reinterprets v1 at 0x1b3018
 *   fpu: float literal 0x37800080 at 0x1b3034
 *   fpu: float literal 0x3f000000 at 0x1b3040
 *   fpu: float literal 0x3c8ef34d at 0x1b306c
 *   fpu: float literal 0x00000000 at 0x1b3070
 *   stack: address of the slot at 0x90 escapes at 0x1b3078
 *   stack: address of the slot at 0x90 escapes at 0x1b3088
 *   stack: address of the slot at 0xd0 escapes at 0x1b3088
 *   fpu: mtc1 reinterprets v0 at 0x1b30e0
 *   fpu: mtc1 reinterprets v1 at 0x1b30f8
 *   fpu: mtc1 reinterprets a0 at 0x1b310c
 *   fpu: float literal 0x37800080 at 0x1b3128
 *   fpu: float literal 0x4f000000 at 0x1b312c
 *   cfg: loop body is not one contiguous region: .L001B2B40
 *   v0#26 is the pointer held in a0+0x48
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void sceVu0UnitMatrix(void *);

extern void SfxCalc_MakeMatrixFromPYR(void *, float, float, float);
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif


struct dw_1890884_fields_a92cd2e9;
struct dw_1891466_fields_a92cd2e9;
struct dw_1892300_fields_a92cd2e9;
struct dw_1904865_fields_a92cd2e9;
struct dw_1905892_fields_a92cd2e9;
#ifndef PROTO_DW_1898869_FIELDS_A92CD2E9
#define PROTO_DW_1898869_FIELDS_A92CD2E9
struct dw_1898869_fields_a92cd2e9 { unsigned short disable_draw_scr : 1; unsigned short disable_draw_map : 1; unsigned short disable_act_scr : 1; unsigned short disable_act_map : 1; unsigned short unused : 12; };
#endif
#ifndef PROTO_DW_1890401_FIELDS_A92CD2E9
#define PROTO_DW_1890401_FIELDS_A92CD2E9
struct dw_1890401_fields_a92cd2e9 { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float (*p_matrix)[4][4]; int prev_ptcl; short life_time; unsigned short ptcl_num; unsigned short prog_no; struct dw_1898869_fields_a92cd2e9 flag; unsigned short sfx_sttdata_idx; unsigned char _pad0[14]; };
#endif
#ifndef PROTO_DW_1890884_FIELDS_A92CD2E9
#define PROTO_DW_1890884_FIELDS_A92CD2E9
struct dw_1890884_fields_a92cd2e9 { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float rgba[4]; float n_speed[4]; float add_uv[2]; float dmy; char rand[4]; unsigned int lifecnt; unsigned int cnt; struct dw_1890884_fields_a92cd2e9 *p_sibling; struct dw_1891466_fields_a92cd2e9 *pEmitter; unsigned char extra_data[32]; float qtn[4]; };
#endif
#ifndef PROTO_DW_1916235_FIELDS_A92CD2E9
#define PROTO_DW_1916235_FIELDS_A92CD2E9
struct dw_1916235_fields_a92cd2e9 { unsigned short disable_draw : 1; unsigned short disable_draw_by_map : 1; unsigned short disable_act : 1; unsigned short disable_act_by_map : 1; unsigned short draw_stage : 4; unsigned short unused : 8; };
#endif
#ifndef PROTO_DW_1891466_FIELDS_A92CD2E9
#define PROTO_DW_1891466_FIELDS_A92CD2E9
struct dw_1891466_fields_a92cd2e9 { float matrix[4][4]; float (*p_matrix)[4][4]; unsigned short prog_no; unsigned char ptcl_num; unsigned char dmy; struct dw_1890884_fields_a92cd2e9 *p_ptcl_top; struct dw_1904865_fields_a92cd2e9 *p_fix_param; struct dw_1905892_fields_a92cd2e9 *p_seq_param; struct dw_1891466_fields_a92cd2e9 *p_prev; struct dw_1891466_fields_a92cd2e9 *p_next; struct dw_1891466_fields_a92cd2e9 *p_relation_prev; struct dw_1891466_fields_a92cd2e9 *p_relation_next; unsigned int lifecnt; unsigned int cnt; struct dw_1916235_fields_a92cd2e9 bit_flag; unsigned short sfx_sttdata_idx; unsigned short cframe; unsigned char dmy2[14]; unsigned char extra_data[32]; };
#endif
#ifndef PROTO_DW_1902102_FIELDS_A92CD2E9
#define PROTO_DW_1902102_FIELDS_A92CD2E9
struct dw_1902102_fields_a92cd2e9 { unsigned int Frame; char szName[26]; unsigned short sfx_idx; };
#endif
#ifndef PROTO_DW_1892300_FIELDS_A92CD2E9
#define PROTO_DW_1892300_FIELDS_A92CD2E9
struct dw_1892300_fields_a92cd2e9 { int ProgramId; struct dw_1892300_fields_a92cd2e9 *pParent; struct dw_1892300_fields_a92cd2e9 *pChild; struct dw_1892300_fields_a92cd2e9 *pSibling; int FixParamNum; struct dw_1904865_fields_a92cd2e9 *pFixParam; int SeqParamNum; struct dw_1905892_fields_a92cd2e9 *pSeqParam; struct dw_1902102_fields_a92cd2e9 CommonParam; };
#endif
#ifndef PROTO_DW_1904865_FIELDS_A92CD2E9
#define PROTO_DW_1904865_FIELDS_A92CD2E9
struct dw_1904865_fields_a92cd2e9 { char cdummy; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_P_MATRIX_856A4D9C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_P_MATRIX_856A4D9C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_P_MATRIX_856A4D9C = (int)&(((struct dw_1890401_fields_a92cd2e9 *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_PTCL_NUM_5C66241F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_PTCL_NUM_5C66241F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_PTCL_NUM_5C66241F = (int)&(((struct dw_1890401_fields_a92cd2e9 *)0)->ptcl_num) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_SCALE_0__C00CD91D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_SCALE_0__C00CD91D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_SCALE_0__C00CD91D = (int)&(((struct dw_1890401_fields_a92cd2e9 *)0)->scale[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_SCALE_1__9F7D8219_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_SCALE_1__9F7D8219_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_SCALE_1__9F7D8219 = (int)&(((struct dw_1890401_fields_a92cd2e9 *)0)->scale[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_SCALE_2__84ED8173_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_SCALE_2__84ED8173_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_SCALE_2__84ED8173 = (int)&(((struct dw_1890401_fields_a92cd2e9 *)0)->scale[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_0__5DFAC5FD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_0__5DFAC5FD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_0__5DFAC5FD = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->ang[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_1__7C315EB0_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_1__7C315EB0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_1__7C315EB0 = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_2__44E621F2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_2__44E621F2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_2__44E621F2 = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->ang[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_3__84C321C3_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_3__84C321C3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_3__84C321C3 = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->ang[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_EXTRA_DATA_0__B1AAA7B6_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_EXTRA_DATA_0__B1AAA7B6_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_EXTRA_DATA_0__B1AAA7B6 = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->extra_data[0]) - 176 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LIFECNT_92F2613A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LIFECNT_92F2613A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LIFECNT_92F2613A = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->lifecnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LOC_3__E52D55BB_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LOC_3__E52D55BB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LOC_3__E52D55BB = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->loc[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_PEMITTER_8D2B2DDD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_PEMITTER_8D2B2DDD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_PEMITTER_8D2B2DDD = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->pEmitter) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_P_SIBLING_8BDDA96F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_P_SIBLING_8BDDA96F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_P_SIBLING_8BDDA96F = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->p_sibling) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_0__A5F80208_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_0__A5F80208_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_0__A5F80208 = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->rand[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_1__649EEDFC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_1__649EEDFC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_1__649EEDFC = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->rand[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_2__16CFF809_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_2__16CFF809_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_2__16CFF809 = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->rand[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_3__2BF6EA67_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_3__2BF6EA67_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_3__2BF6EA67 = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->rand[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_LIFECNT_7CEC2A9C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_LIFECNT_7CEC2A9C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_LIFECNT_7CEC2A9C = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->lifecnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_MATRIX_0__0__90CCE4D2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_MATRIX_0__0__90CCE4D2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_MATRIX_0__0__90CCE4D2 = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->matrix[0][0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_MATRIX_1__1__6BB6CA6F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_MATRIX_1__1__6BB6CA6F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_MATRIX_1__1__6BB6CA6F = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->matrix[1][1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_MATRIX_2__2__8F829CA2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_MATRIX_2__2__8F829CA2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_MATRIX_2__2__8F829CA2 = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->matrix[2][2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_FIX_PARAM_89E876C2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_FIX_PARAM_89E876C2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_FIX_PARAM_89E876C2 = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->p_fix_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_MATRIX_84DDDCB3_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_MATRIX_84DDDCB3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_MATRIX_84DDDCB3 = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_PTCL_TOP_1E22B1BC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_PTCL_TOP_1E22B1BC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_PTCL_TOP_1E22B1BC = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->p_ptcl_top) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_SEQ_PARAM_BCE30E49_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_SEQ_PARAM_BCE30E49_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_SEQ_PARAM_BCE30E49 = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->p_seq_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_PTCL_NUM_86E21A87_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_PTCL_NUM_86E21A87_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_PTCL_NUM_86E21A87 = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->ptcl_num) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PFIXPARAM_FECB6825_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PFIXPARAM_FECB6825_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PFIXPARAM_FECB6825 = (int)&(((struct dw_1892300_fields_a92cd2e9 *)0)->pFixParam) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PSEQPARAM_30AF687F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PSEQPARAM_30AF687F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PSEQPARAM_30AF687F = (int)&(((struct dw_1892300_fields_a92cd2e9 *)0)->pSeqParam) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__58__CDUMMY_249D2759_DEFINED
#define DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__58__CDUMMY_249D2759_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__58__CDUMMY_249D2759 = (int)&(((struct dw_1904865_fields_a92cd2e9 *)0)[58].cdummy) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__59__CDUMMY_A7408244_DEFINED
#define DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__59__CDUMMY_A7408244_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__59__CDUMMY_A7408244 = (int)&(((struct dw_1904865_fields_a92cd2e9 *)0)[59].cdummy) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__64__CDUMMY_13EB4259_DEFINED
#define DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__64__CDUMMY_13EB4259_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__64__CDUMMY_13EB4259 = (int)&(((struct dw_1904865_fields_a92cd2e9 *)0)[64].cdummy) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__65__CDUMMY_8D4B2421_DEFINED
#define DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__65__CDUMMY_8D4B2421_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__65__CDUMMY_8D4B2421 = (int)&(((struct dw_1904865_fields_a92cd2e9 *)0)[65].cdummy) - 0 };
#endif
#define PTCL_RNDRANGE(dst, b, r) \
    if (0.0f < (r)) { \
        float rr_ = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32(); \
        (dst) = (b) + (r) * (rr_ - 0.5f); \
    } else { \
        (dst) = (b); \
    }

/* __SFX_ActAnimSprite @ 0x1B3510 .. 0x1B3D04 (0x7f4 bytes, frame 0x190) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1b3564 is a float copy
 *   stack: address of the slot at 0x178 escapes at 0x1b3654
 *   fpu: float literal 0x3c8ef34d at 0x1b3670
 *   fpu: float literal 0xc0490fd0 at 0x1b368c
 *   fpu: float literal 0x40490fd0 at 0x1b36a8
 *   fpu: float literal 0x40c90fd0 at 0x1b36d4
 *   stack: address of the slot at 0x140 escapes at 0x1b36f8
 *   fpu: float literal 0x3c23d70a at 0x1b371c
 *   fpu: mtc1 reinterprets a0 at 0x1b3728
 *   stack: address of the slot at 0x144 escapes at 0x1b3750
 *   stack: address of the slot at 0x148 escapes at 0x1b3764
 *   fpu: float literal 0x3c23d70a at 0x1b3780
 *   fpu: mtc1 reinterprets a0 at 0x1b3788
 *   fpu: mtc1 reinterprets v1 at 0x1b37b0
 *   stack: address of the slot at 0x148 escapes at 0x1b37d0
 *   fpu: mov.s at 0x1b37dc is a float copy
 *   stack: address of the slot at 0x130 escapes at 0x1b37d8
 *   stack: address of the slot at 0x130 escapes at 0x1b37e8
 *   stack: address of the slot at 0x18c escapes at 0x1b3804
 *   fpu: float literal 0x00000000 at 0x1b3810
 *   stack: address of the slot at 0xe0 escapes at 0x1b38b0
 *   stack: address of the slot at 0xe0 escapes at 0x1b38b4
 *   stack: address of the slot at 0x120 escapes at 0x1b38c4
 *   stack: address of the slot at 0xe8 escapes at 0x1b38c4
 *   stack: address of the slot at 0xe0 escapes at 0x1b38dc
 *   stack: address of the slot at 0xe0 escapes at 0x1b38f0
 *   stack: address of the slot at 0xe0 escapes at 0x1b38f0
 *   stack: address of the slot at 0xe0 escapes at 0x1b3938
 *   stack: address of the slot at 0x160 escapes at 0x1b3938
 *   stack: address of the slot at 0xd0 escapes at 0x1b3944
 *   stack: address of the slot at 0x160 escapes at 0x1b3944
 *   stack: address of the slot at 0xd0 escapes at 0x1b3954
 *   stack: address of the slot at 0x188 escapes at 0x1b3974
 *   fpu: mtc1 reinterprets v0 at 0x1b3988
 *   fpu: mtc1 reinterprets v1 at 0x1b399c
 *   fpu: float literal 0x43000000 at 0x1b39b0
 *   fpu: mtc1 reinterprets v0 at 0x1b39d0
 *   fpu: mtc1 reinterprets v1 at 0x1b39e4
 *   fpu: float literal 0x43000000 at 0x1b39f8
 *   fpu: mtc1 reinterprets v0 at 0x1b3a18
 *   fpu: mtc1 reinterprets v1 at 0x1b3a2c
 *   fpu: float literal 0x43000000 at 0x1b3a44
 *   stack: address of the slot at 0x18b escapes at 0x1b3a60
 *   fpu: mtc1 reinterprets v1 at 0x1b3a78
 *   fpu: mtc1 reinterprets a0 at 0x1b3a8c
 *   fpu: float literal 0x43000000 at 0x1b3aa0
 *   stack: address of the slot at 0x184 escapes at 0x1b3ad4
 *   fpu: mtc1 reinterprets a0 at 0x1b3af4
 *   fpu: mtc1 reinterprets a1 at 0x1b3b0c
 *   fpu: mtc1 reinterprets a0 at 0x1b3b4c
 *   fpu: mtc1 reinterprets a1 at 0x1b3b60
 *   fpu: float literal 0x3f800000 at 0x1b3b74
 *   fpu: mtc1 reinterprets t0 at 0x1b3b80
 *   fpu: mtc1 reinterprets a1 at 0x1b3b94
 *   fpu: mtc1 reinterprets a0 at 0x1b3bdc
 *   fpu: mtc1 reinterprets a1 at 0x1b3bf4
 *   fpu: float literal 0x3f800000 at 0x1b3c08
 *   fpu: mtc1 reinterprets v1 at 0x1b3c14
 *   fpu: mtc1 reinterprets a0 at 0x1b3c28
 *   delay: addiu at 0x1b3c60 writes a register its branch at 0x1b3c5c reads
 *   cfg: kept goto: 0x1b3528 -> .L001B3CA8
 *   cfg: kept branch: 0x1b36a0 if (..) goto .L001B36C4
 *   cfg: loop body is not one contiguous region: .L001B3CA8
 *   cfg: kept branch: 0x1b3cbc if (..) goto .L001B3578
 *   s1#2 is the pointer held in a0+0x48
 *   v1#11 is the pointer held in s1#1+0xa8
 *   a2 typed from the __SFX_ActAnimSprite call table
 *   declaration vs inferred signature: return void vs inferred u32
 */









#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif

#ifndef DCOMP_COP2_21F95D43C1
#define DCOMP_COP2_21F95D43C1

#endif






#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED

#endif


/* __SFX_InitAnimSprite @ 0x1B3D10 .. 0x1B441C (0x70c bytes, frame 0x80) */
/*
 * dcomp notes:
 *   delay: lui at 0x1b3e78 writes a register its branch at 0x1b3e74 reads
 *   fpu: mtc1 reinterprets v0 at 0x1b3e9c
 *   fpu: mtc1 reinterprets v1 at 0x1b3eb0
 *   fpu: float literal 0x37800080 at 0x1b3ecc
 *   fpu: mtc1 reinterprets v0 at 0x1b3ed8
 *   fpu: mtc1 reinterprets v1 at 0x1b3ef0
 *   fpu: float literal 0x3f000000 at 0x1b3f08
 *   fpu: mtc1 reinterprets v1 at 0x1b3f1c
 *   fpu: float literal 0x4f000000 at 0x1b3f20
 *   fpu: mtc1 reinterprets v0 at 0x1b3f7c
 *   fpu: mtc1 reinterprets v1 at 0x1b3f90
 *   fpu: float literal 0x37800080 at 0x1b3fac
 *   fpu: float literal 0x42c80000 at 0x1b3fb4
 *   fpu: float literal 0x3f000000 at 0x1b3fc0
 *   fpu: mtc1 reinterprets v0 at 0x1b3fec
 *   fpu: mtc1 reinterprets v1 at 0x1b4000
 *   fpu: float literal 0x37800080 at 0x1b401c
 *   fpu: float literal 0x42c80000 at 0x1b4024
 *   fpu: float literal 0x3f000000 at 0x1b4030
 *   fpu: mtc1 reinterprets v0 at 0x1b405c
 *   fpu: mtc1 reinterprets v1 at 0x1b4070
 *   fpu: float literal 0x37800080 at 0x1b408c
 *   fpu: float literal 0x42c80000 at 0x1b4094
 *   fpu: float literal 0x3f000000 at 0x1b40a0
 *   fpu: mtc1 reinterprets v0 at 0x1b40cc
 *   fpu: mtc1 reinterprets v1 at 0x1b40e0
 *   fpu: float literal 0x37800080 at 0x1b40fc
 *   fpu: float literal 0x42c80000 at 0x1b4104
 *   fpu: float literal 0x3f000000 at 0x1b4110
 *   fpu: mtc1 reinterprets v0 at 0x1b4148
 *   fpu: mtc1 reinterprets v1 at 0x1b415c
 *   fpu: float literal 0x37800080 at 0x1b4178
 *   fpu: float literal 0x3f000000 at 0x1b417c
 *   fpu: float literal 0x3c8ef34d at 0x1b41a8
 *   fpu: mtc1 reinterprets v0 at 0x1b41cc
 *   fpu: mtc1 reinterprets v1 at 0x1b41e0
 *   fpu: float literal 0x37800080 at 0x1b41fc
 *   fpu: float literal 0x3f000000 at 0x1b4208
 *   fpu: mtc1 reinterprets v0 at 0x1b4230
 *   fpu: mtc1 reinterprets v1 at 0x1b4244
 *   fpu: float literal 0x37800080 at 0x1b4260
 *   fpu: float literal 0x3f000000 at 0x1b426c
 *   fpu: mtc1 reinterprets v0 at 0x1b4294
 *   fpu: mtc1 reinterprets v1 at 0x1b42a8
 *   fpu: float literal 0x37800080 at 0x1b42c8
 *   fpu: float literal 0x3f000000 at 0x1b42d4
 *   fpu: mtc1 reinterprets v0 at 0x1b432c
 *   fpu: mtc1 reinterprets v1 at 0x1b4344
 *   fpu: mtc1 reinterprets a0 at 0x1b4358
 *   fpu: float literal 0x37800080 at 0x1b4374
 *   fpu: float literal 0x4f000000 at 0x1b4378
 *   cfg: loop body is not one contiguous region: .L001B3E68
 *   v0#10 is the pointer held in a0+0x48
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void sceVu0UnitMatrix(void *);

#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif







#ifndef PROTO_DW_1898869_FIELDS
#define PROTO_DW_1898869_FIELDS

#endif
#ifndef PROTO_DW_1890401_FIELDS
#define PROTO_DW_1890401_FIELDS

#endif
#ifndef PROTO_DW_1890884_FIELDS
#define PROTO_DW_1890884_FIELDS

#endif
#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif
#ifndef PROTO_DW_1902102_FIELDS
#define PROTO_DW_1902102_FIELDS

#endif
#ifndef PROTO_DW_1892300_FIELDS
#define PROTO_DW_1892300_FIELDS

#endif
#ifndef PROTO_DW_1904865_FIELDS
#define PROTO_DW_1904865_FIELDS
struct dw_1904865_fields { char cdummy; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D = (int)&(((struct dw_1890401_fields *)0)->scale[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01 = (int)&(((struct dw_1890401_fields *)0)->scale[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2 = (int)&(((struct dw_1890401_fields *)0)->scale[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C = (int)&(((struct dw_1890884_fields *)0)->ang[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_1__C6D2CBBE_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_1__C6D2CBBE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_1__C6D2CBBE = (int)&(((struct dw_1890884_fields *)0)->ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE = (int)&(((struct dw_1890884_fields *)0)->ang[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_3__500368EC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_3__500368EC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_3__500368EC = (int)&(((struct dw_1890884_fields *)0)->ang[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_EXTRA_DATA_0__72E3C7F7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_EXTRA_DATA_0__72E3C7F7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_EXTRA_DATA_0__72E3C7F7 = (int)&(((struct dw_1890884_fields *)0)->extra_data[0]) - 176 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7 = (int)&(((struct dw_1891466_fields *)0)->matrix[0][0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9 = (int)&(((struct dw_1891466_fields *)0)->matrix[1][1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0 = (int)&(((struct dw_1891466_fields *)0)->matrix[2][2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1904865_FIELDS__73__CDUMMY_8C162FC7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1904865_FIELDS__73__CDUMMY_8C162FC7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1904865_FIELDS__73__CDUMMY_8C162FC7 = (int)&(((struct dw_1904865_fields *)0)[73].cdummy) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1904865_FIELDS__74__CDUMMY_FCD2552D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1904865_FIELDS__74__CDUMMY_FCD2552D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1904865_FIELDS__74__CDUMMY_FCD2552D = (int)&(((struct dw_1904865_fields *)0)[74].cdummy) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1904865_FIELDS__79__CDUMMY_E7F7B9D7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1904865_FIELDS__79__CDUMMY_E7F7B9D7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1904865_FIELDS__79__CDUMMY_E7F7B9D7 = (int)&(((struct dw_1904865_fields *)0)[79].cdummy) - 0 };
#endif

/* __SFX_DrawPtclConnectedSprite @ 0x1B4430 .. 0x1B4600 (0x1d0 bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   quad: s2: 128-bit web split from its scalar uses
 *   stack: address of the slot at 0x90 escapes at 0x1b4494
 *   stack: address of the slot at 0x80 escapes at 0x1b44a4
 *   stack: address of the slot at 0x90 escapes at 0x1b44bc
 *   stack: address of the slot at 0x80 escapes at 0x1b44c8
 *   stack: address of the slot at 0x70 escapes at 0x1b4564
 *   fpu: float literal 0x3daaaa7e at 0x1b45a0
 *   stack: address of the slot at 0x60 escapes at 0x1b45a4
 *   stack: address of the slot at 0x60 escapes at 0x1b45b4
 *   stack: address of the slot at 0x90 escapes at 0x1b45b4
 *   stack: address of the slot at 0x60 escapes at 0x1b45b4
 *   stack: address of the slot at 0x90 escapes at 0x1b45cc
 *   stack: address of the slot at 0x60 escapes at 0x1b45cc
 *   quad: a0: 128-bit web split from its scalar variable as a0_q
 *   quad: v0: 128-bit web split from its scalar variable as v0_q
 *   cfg: kept branch: 0x1b4470 if (..) goto .L001B45E0
 *   cfg: kept branch: 0x1b44e0 if (..) goto .L001B44F8
 *   a1 typed from the __SFX_DrawPtclConnectedSprite call table
 *   a2 typed from the __SFX_DrawPtclConnectedSprite call table
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void sceVu0ApplyMatrix(void *, void *, void *);
extern float sceVu0InnerProduct(void *, void *);
extern void sceVu0ScaleVector(void *, void *, float);
extern void sceVu0SubVector(void *, void *, void *);
extern void SfxDraw_DrawSprite_Wld2Pt(float *, float *, float, void *, float);

/* __SFX_ActConnectedSprite @ 0x1B4690 .. 0x1B4B0C (0x47c bytes, frame 0x170) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1b46e8 is a float copy
 *   stack: address of the slot at 0x120 escapes at 0x1b47c4
 *   fpu: float literal 0x3c23d70a at 0x1b47e4
 *   fpu: mtc1 reinterprets a2 at 0x1b47f0
 *   stack: address of the slot at 0x140 escapes at 0x1b480c
 *   fpu: mov.s at 0x1b4820 is a float copy
 *   stack: address of the slot at 0x110 escapes at 0x1b481c
 *   stack: address of the slot at 0x110 escapes at 0x1b482c
 *   stack: address of the slot at 0x16c escapes at 0x1b4848
 *   fpu: float literal 0x00000000 at 0x1b4854
 *   stack: address of the slot at 0xc0 escapes at 0x1b4878
 *   stack: address of the slot at 0x100 escapes at 0x1b4884
 *   stack: address of the slot at 0xc8 escapes at 0x1b4884
 *   stack: address of the slot at 0xc0 escapes at 0x1b489c
 *   stack: address of the slot at 0xc0 escapes at 0x1b48b0
 *   stack: address of the slot at 0xc0 escapes at 0x1b48b0
 *   stack: address of the slot at 0xc0 escapes at 0x1b48f8
 *   stack: address of the slot at 0x150 escapes at 0x1b48f8
 *   stack: address of the slot at 0xb0 escapes at 0x1b4904
 *   stack: address of the slot at 0x150 escapes at 0x1b4904
 *   stack: address of the slot at 0xb0 escapes at 0x1b4914
 *   stack: address of the slot at 0x168 escapes at 0x1b4934
 *   fpu: mtc1 reinterprets v0 at 0x1b4948
 *   fpu: mtc1 reinterprets v1 at 0x1b495c
 *   fpu: float literal 0x43000000 at 0x1b4970
 *   fpu: mtc1 reinterprets v0 at 0x1b4990
 *   fpu: mtc1 reinterprets v1 at 0x1b49a4
 *   fpu: float literal 0x43000000 at 0x1b49b8
 *   fpu: mtc1 reinterprets v0 at 0x1b49d8
 *   fpu: mtc1 reinterprets v1 at 0x1b49ec
 *   fpu: float literal 0x43000000 at 0x1b4a04
 *   stack: address of the slot at 0x16b escapes at 0x1b4a20
 *   fpu: mtc1 reinterprets v0 at 0x1b4a38
 *   fpu: mtc1 reinterprets v1 at 0x1b4a4c
 *   fpu: float literal 0x43000000 at 0x1b4a64
 *   stack: address of the slot at 0x140 escapes at 0x1b4a78
 *   delay: addiu at 0x1b4a90 writes a register its branch at 0x1b4a8c reads
 *   cfg: kept goto: 0x1b46a8 -> .L001B4AB0
 *   cfg: loop body is not one contiguous region: .L001B4AB0
 *   cfg: kept branch: 0x1b4ac4 if (..) goto .L001B46F0
 *   s0#2 is the pointer held in a0+0x48
 *   v1#10 is the pointer held in s0#1+0xa8
 *   a2 typed from the __SFX_ActConnectedSprite call table
 */

extern signed int SFX_GetSeqParam(void *, signed int, signed int, void *, signed int);
extern void fsvu0_MulMatrix(void *, void *, void *);
extern void SfxCalc_Vector2Angle(float *, float *);
extern void sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0RotMatrixX(void *, void *, float);

extern u32 VY[];
#ifndef DCOMP_COP2_21F95D43C1
#define DCOMP_COP2_21F95D43C1
static inline void dcomp_cop2_21F95D43C1(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf16,0(%2)\nvmulax.xyzw ACC,vf1,vf16x\nvmadday.xyzw ACC,vf2,vf16y\nvmaddaz.xyzw ACC,vf3,vf16z\nvmaddw.xyzw vf16,vf4,vf16w\nsqc2 vf16,0(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif






#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED

#endif


/* __SFX_InitConnectedSprite @ 0x1B4B10 .. 0x1B50EC (0x5dc bytes, frame 0x80) */
/*
 * dcomp notes:
 *   literal: @5279 is the string 'sfxt%03d.tm2'
 *   stack: address of the slot at 0x60 escapes at 0x1b4b50
 *   delay: lui at 0x1b4c80 writes a register its branch at 0x1b4c7c reads
 *   fpu: mtc1 reinterprets v0 at 0x1b4ca4
 *   fpu: mtc1 reinterprets v1 at 0x1b4cb8
 *   fpu: float literal 0x37800080 at 0x1b4cd4
 *   fpu: mtc1 reinterprets v0 at 0x1b4ce0
 *   fpu: mtc1 reinterprets v1 at 0x1b4cf8
 *   fpu: float literal 0x3f000000 at 0x1b4d10
 *   fpu: mtc1 reinterprets v1 at 0x1b4d24
 *   fpu: float literal 0x4f000000 at 0x1b4d28
 *   fpu: mtc1 reinterprets v0 at 0x1b4d84
 *   fpu: mtc1 reinterprets v1 at 0x1b4d98
 *   fpu: float literal 0x37800080 at 0x1b4db4
 *   fpu: float literal 0x42c80000 at 0x1b4dbc
 *   fpu: float literal 0x3f000000 at 0x1b4dc8
 *   fpu: mtc1 reinterprets v0 at 0x1b4df4
 *   fpu: mtc1 reinterprets v1 at 0x1b4e08
 *   fpu: float literal 0x37800080 at 0x1b4e24
 *   fpu: float literal 0x42c80000 at 0x1b4e2c
 *   fpu: float literal 0x3f000000 at 0x1b4e38
 *   fpu: mtc1 reinterprets v0 at 0x1b4e64
 *   fpu: mtc1 reinterprets v1 at 0x1b4e78
 *   fpu: float literal 0x37800080 at 0x1b4e94
 *   fpu: float literal 0x42c80000 at 0x1b4e9c
 *   fpu: float literal 0x3f000000 at 0x1b4ea8
 *   fpu: mtc1 reinterprets v0 at 0x1b4ed4
 *   fpu: mtc1 reinterprets v1 at 0x1b4ee8
 *   fpu: float literal 0x37800080 at 0x1b4f08
 *   fpu: float literal 0x42c80000 at 0x1b4f10
 *   fpu: float literal 0x3f000000 at 0x1b4f20
 *   fpu: mtc1 reinterprets v0 at 0x1b4f54
 *   fpu: mtc1 reinterprets v1 at 0x1b4f68
 *   fpu: float literal 0x37800080 at 0x1b4f84
 *   fpu: float literal 0x3f000000 at 0x1b4f90
 *   fpu: mtc1 reinterprets v0 at 0x1b4fb8
 *   fpu: mtc1 reinterprets v1 at 0x1b4fcc
 *   fpu: float literal 0x37800080 at 0x1b4fe8
 *   fpu: float literal 0x3f000000 at 0x1b4ff4
 *   fpu: mtc1 reinterprets v0 at 0x1b501c
 *   fpu: mtc1 reinterprets v1 at 0x1b5030
 *   fpu: float literal 0x37800080 at 0x1b5050
 *   fpu: float literal 0x3f000000 at 0x1b505c
 *   cfg: loop body is not one contiguous region: .L001B4C70
 *   v0#11 is the pointer held in a0+0x48
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern int sprintf(char *, const char *, ...);
extern void *GetTexMngByName(void *, char *);



extern u32 V0[];
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif







#ifndef PROTO_DW_1898869_FIELDS
#define PROTO_DW_1898869_FIELDS

#endif
#ifndef PROTO_DW_1890401_FIELDS
#define PROTO_DW_1890401_FIELDS

#endif
#ifndef PROTO_DW_1890884_FIELDS
#define PROTO_DW_1890884_FIELDS

#endif
#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif
#ifndef PROTO_DW_1902102_FIELDS
#define PROTO_DW_1902102_FIELDS

#endif
#ifndef PROTO_DW_1892300_FIELDS
#define PROTO_DW_1892300_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED

#endif


/* __SFX_EndPtclTracer @ 0x1B50F0 .. 0x1B511C (0x2c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   a1 typed from the __SFX_EndPtclTracer call table
 *   a2 typed from the __SFX_EndPtclTracer call table
 */

extern signed int SfxTracer_Kill(unsigned short);

/* __SFX_ActTracer @ 0x1B5120 .. 0x1B541C (0x2fc bytes, frame 0x100) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1b5164 is a float copy
 *   fpu: mov.s at 0x1b522c is a float copy
 *   stack: address of the slot at 0xf0 escapes at 0x1b5230
 *   stack: address of the slot at 0xf0 escapes at 0x1b5240
 *   delay: addiu at 0x1b5254 writes a register its branch at 0x1b5250 reads
 *   stack: address of the slot at 0xe0 escapes at 0x1b525c
 *   stack: address of the slot at 0xe0 escapes at 0x1b526c
 *   stack: address of the slot at 0xe0 escapes at 0x1b526c
 *   fpu: float literal 0xc0490fdb at 0x1b5284
 *   stack: address of the slot at 0xa0 escapes at 0x1b5288
 *   stack: address of the slot at 0x90 escapes at 0x1b5378
 *   stack: address of the slot at 0xa0 escapes at 0x1b5378
 *   stack: address of the slot at 0xe0 escapes at 0x1b5388
 *   stack: address of the slot at 0x90 escapes at 0x1b5388
 *   delay: addiu at 0x1b53ac writes a register its branch at 0x1b53a8 reads
 *   cfg: kept goto: 0x1b5130 -> .L001B53C8
 *   cfg: loop body is not one contiguous region: .L001B53C8
 *   cfg: kept branch: 0x1b53dc if (..) goto .L001B5168
 *   s1#2 is the pointer held in a0+0x48
 *   v1#10 is the pointer held in s1#1+0xa8
 *   a2 typed from the __SFX_ActTracer call table
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void sceVu0RotMatrixZ(void *, void *, float);
extern void SfxCalc_QtnMakeFromMatrix(float *, void *);
extern signed int SfxTracer_AddLog(unsigned short, float *, float *);
extern u32 MRX1[];
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif






#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED

#endif


/* __SFX_InitTracer @ 0x1B5420 .. 0x1B58C4 (0x4a4 bytes, frame 0x1e0) */
/*
 * dcomp notes:
 *   literal: @5279 is the string 'sfxt%03d.tm2'
 *   literal: @3373 is the string 'PtclMng.c'
 *   literal: @5480 is the string
 *   '\x83g\x83\x8c\x81[\x83T\x83I\x83u\x83W\x83F\x83N\x83g\x82Ì\x8dì\x90¬\x82É\x8e¸\x94s\x82µ\x82Ü\x82µ\x82½'
 *   stack: address of the slot at 0x1a4 escapes at 0x1b5560
 *   stack: address of the slot at 0x1a8 escapes at 0x1b5560
 *   stack: address of the slot at 0x1ac escapes at 0x1b5560
 *   fpu: mtc1 reinterprets v0 at 0x1b55a4
 *   fpu: mtc1 reinterprets v1 at 0x1b55b8
 *   fpu: float literal 0x37800080 at 0x1b55d4
 *   fpu: float literal 0x42c80000 at 0x1b55dc
 *   fpu: float literal 0x3f000000 at 0x1b55e8
 *   fpu: mtc1 reinterprets v0 at 0x1b5614
 *   fpu: mtc1 reinterprets v1 at 0x1b5628
 *   fpu: float literal 0x37800080 at 0x1b5644
 *   fpu: float literal 0x42c80000 at 0x1b564c
 *   fpu: float literal 0x3f000000 at 0x1b5658
 *   fpu: mtc1 reinterprets v0 at 0x1b5684
 *   fpu: mtc1 reinterprets v1 at 0x1b5698
 *   fpu: float literal 0x37800080 at 0x1b56b4
 *   fpu: float literal 0x42c80000 at 0x1b56bc
 *   fpu: float literal 0x3f000000 at 0x1b56c8
 *   fpu: mtc1 reinterprets v0 at 0x1b56f4
 *   fpu: mtc1 reinterprets v1 at 0x1b5708
 *   fpu: float literal 0x37800080 at 0x1b5724
 *   fpu: float literal 0x42c80000 at 0x1b572c
 *   fpu: float literal 0x3f000000 at 0x1b5738
 *   stack: address of the slot at 0x1d0 escapes at 0x1b57a4
 *   fpu: float literal 0x3c888865 at 0x1b57c4
 *   fpu: mtc1 reinterprets v0 at 0x1b57f0
 *   stack: address of the slot at 0xa0 escapes at 0x1b5858
 *   stack: address of the slot at 0xa0 escapes at 0x1b5870
 *   stack: 4-byte aggregate copy in 2-byte chunks at 0x1b5820
 *   cfg: loop body is not one contiguous region: .L001B5560
 *   v0#7 is the pointer held in a0+0x48
 *   v0 is the pointer held in a0+0x4c
 *   declaration vs inferred signature: return void vs inferred u32
 */






extern unsigned short SfxTracer_Create(void *);


#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif







#ifndef PROTO_DW_1898869_FIELDS
#define PROTO_DW_1898869_FIELDS

#endif
#ifndef PROTO_DW_1890401_FIELDS
#define PROTO_DW_1890401_FIELDS

#endif
#ifndef PROTO_DW_1890884_FIELDS
#define PROTO_DW_1890884_FIELDS

#endif
#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif
#ifndef PROTO_DW_1902102_FIELDS
#define PROTO_DW_1902102_FIELDS

#endif
#ifndef PROTO_DW_1892300_FIELDS
#define PROTO_DW_1892300_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_0__5ED7228F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_0__5ED7228F_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_1__A795EEE1_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_1__A795EEE1_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_2__3B661BD7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_2__3B661BD7_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED

#endif
#ifndef PROTO_DW_1915845_FIELDS
#define PROTO_DW_1915845_FIELDS
struct dw_1896911_fields;
struct dw_1915845_fields { unsigned short type; struct dw_1896911_fields *pTex; float size; float length; float life; float split; unsigned short divH; unsigned short divV; float cut; float alpha; };
#endif
#ifndef PROTO_DW_1899432_FIELDS
#define PROTO_DW_1899432_FIELDS
struct dw_1899432_fields { short life; unsigned short type; unsigned short model_id; unsigned short dmy; float size; float length; float alpha; unsigned short divH; unsigned short divV; float cut; };
#endif
struct dw_1892300_dsc { u8 pad[0x14]; u8 *pFixParam; int SeqParamNum; u8 *pSeqParam; };
struct dw_1890401_dsc { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float (*p_matrix)[4][4]; int prev_ptcl; short life_time; unsigned short ptcl_num; };


/* __SFX_DrawPtclDistortion @ 0x1B58D0 .. 0x1B5978 (0xa8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x20 escapes at 0x1b5918
 *   stack: address of the slot at 0x20 escapes at 0x1b592c
 *   stack: address of the slot at 0x20 escapes at 0x1b5958
 *   a1 typed from the __SFX_DrawPtclDistortion call table
 *   a2 typed from the __SFX_DrawPtclDistortion call table
 */

extern void sceVu0ApplyMatrix(void *, void *, void *);
extern void sceVu0CopyVector(void *, void *);
extern unsigned int CheckPosOutOfSight(float *);
extern signed int SfxFlicker_SetPos(unsigned short, float *);
extern signed int SfxFlicker_Draw(unsigned short);
static u8 s_mng[64];
static u8 s_aTexMng[0x400];

/* __SFX_EndPtclDistortion @ 0x1B5980 .. 0x1B59AC (0x2c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   a1 typed from the __SFX_EndPtclDistortion call table
 *   a2 typed from the __SFX_EndPtclDistortion call table
 */

extern signed int SfxFlicker_Delete(unsigned short);

/* __SFX_DrawDistortion @ 0x1B59B0 .. 0x1B5A4C (0x9c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar variable as a0_q
 *   quad: v0: 128-bit web split from its scalar variable as v0_q
 *   cfg: kept goto: 0x1b59d4 -> .L001B5A08
 *   cfg: loop body is not one contiguous region: .L001B5A08
 *   cfg: kept branch: 0x1b5a1c if (..) goto .L001B59F0
 *   a1 typed from the __SFX_DrawDistortion call table
 *   a2 typed from the __SFX_DrawDistortion call table
 */

extern u_long128 SfxDraw_GetRenderStateBlock(void);
extern void SfxDraw_EnableZTest(signed int);
extern void SfxDraw_SetRenderStateBlock(u_long128);

/* __SFX_ActDistortion @ 0x1B5A50 .. 0x1B5CC0 (0x270 bytes, frame 0xc0) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1b5a98 is a float copy
 *   fpu: mov.s at 0x1b5b64 is a float copy
 *   stack: address of the slot at 0xa0 escapes at 0x1b5b68
 *   stack: address of the slot at 0xa0 escapes at 0x1b5b78
 *   stack: address of the slot at 0xbc escapes at 0x1b5b94
 *   fpu: float literal 0x00000000 at 0x1b5ba0
 *   stack: address of the slot at 0xb8 escapes at 0x1b5be4
 *   stack: address of the slot at 0xb4 escapes at 0x1b5c00
 *   fpu: mov.s at 0x1b5c28 is a float copy
 *   delay: addiu at 0x1b5c4c writes a register its branch at 0x1b5c48 reads
 *   cfg: kept goto: 0x1b5a60 -> .L001B5C68
 *   cfg: loop body is not one contiguous region: .L001B5C68
 *   cfg: kept branch: 0x1b5c7c if (..) goto .L001B5AA0
 *   s2#2 is the pointer held in a0+0x48
 *   v1#10 is the pointer held in s2#1+0xa8
 *   a2 typed from the __SFX_ActDistortion call table
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void * memset(void *, int, unsigned int);
extern void sceVu0ScaleVector(void *, void *, float);
extern void sceVu0AddVector(void *, void *, void *);
extern signed int SFX_GetSeqParam(void *, signed int, signed int, void *, signed int);
extern signed int SfxFlicker_SetScale(unsigned short, float);
extern signed int SfxFlicker_SetAmplitude(unsigned short, float);
extern signed int SfxFlicker_Action(unsigned short, float);


/* __SFX_InitDistortion @ 0x1B5CC0 .. 0x1B6308 (0x648 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   delay: lui at 0x1b5df0 writes a register its branch at 0x1b5dec reads
 *   fpu: mtc1 reinterprets v0 at 0x1b5e14
 *   fpu: mtc1 reinterprets v1 at 0x1b5e28
 *   fpu: float literal 0x37800080 at 0x1b5e44
 *   fpu: mtc1 reinterprets v0 at 0x1b5e50
 *   fpu: mtc1 reinterprets v1 at 0x1b5e68
 *   fpu: float literal 0x3f000000 at 0x1b5e80
 *   fpu: mtc1 reinterprets v1 at 0x1b5e94
 *   fpu: float literal 0x4f000000 at 0x1b5e98
 *   fpu: mtc1 reinterprets v0 at 0x1b5ef4
 *   fpu: mtc1 reinterprets v1 at 0x1b5f08
 *   fpu: float literal 0x37800080 at 0x1b5f24
 *   fpu: float literal 0x42c80000 at 0x1b5f2c
 *   fpu: float literal 0x3f000000 at 0x1b5f38
 *   fpu: mtc1 reinterprets v0 at 0x1b5f64
 *   fpu: mtc1 reinterprets v1 at 0x1b5f78
 *   fpu: float literal 0x37800080 at 0x1b5f94
 *   fpu: float literal 0x42c80000 at 0x1b5f9c
 *   fpu: float literal 0x3f000000 at 0x1b5fa8
 *   fpu: mtc1 reinterprets v0 at 0x1b5fd4
 *   fpu: mtc1 reinterprets v1 at 0x1b5fe8
 *   fpu: float literal 0x37800080 at 0x1b6004
 *   fpu: float literal 0x42c80000 at 0x1b600c
 *   fpu: float literal 0x3f000000 at 0x1b6018
 *   fpu: mtc1 reinterprets v0 at 0x1b6044
 *   fpu: mtc1 reinterprets v1 at 0x1b6058
 *   fpu: float literal 0x37800080 at 0x1b6074
 *   fpu: float literal 0x42c80000 at 0x1b607c
 *   fpu: float literal 0x3f000000 at 0x1b6088
 *   fpu: mtc1 reinterprets v0 at 0x1b60b4
 *   fpu: mtc1 reinterprets v1 at 0x1b60c8
 *   fpu: float literal 0x37800080 at 0x1b60e4
 *   fpu: float literal 0x3f000000 at 0x1b60f0
 *   fpu: mtc1 reinterprets v0 at 0x1b6118
 *   fpu: mtc1 reinterprets v1 at 0x1b612c
 *   fpu: float literal 0x37800080 at 0x1b6148
 *   fpu: float literal 0x3f000000 at 0x1b6154
 *   fpu: mtc1 reinterprets v0 at 0x1b617c
 *   fpu: mtc1 reinterprets v1 at 0x1b6190
 *   fpu: float literal 0x37800080 at 0x1b61ac
 *   fpu: float literal 0x3f000000 at 0x1b61b8
 *   fpu: mtc1 reinterprets v0 at 0x1b626c
 *   fpu: mtc1 reinterprets v1 at 0x1b6280
 *   fpu: float literal 0x37800080 at 0x1b629c
 *   fpu: float literal 0x3f000000 at 0x1b62ac
 *   cfg: loop body is not one contiguous region: .L001B5DE0
 *   v0#6 is the pointer held in a0+0x48
 *   v0 is the pointer held in a0+0x4c
 */

extern void sceVu0UnitMatrix(void *);
static void * _AllocPtcl(signed int num);

extern void SfxCalc_RotateVector(float *, float, float, float);

extern unsigned short SfxFlicker_Create(unsigned short);
extern signed int SfxFlicker_SetCycle(unsigned short, float);
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif




struct dw_1892300_fields;


#ifndef PROTO_DW_1898869_FIELDS
#define PROTO_DW_1898869_FIELDS
struct dw_1898869_fields { unsigned short disable_draw_scr : 1; unsigned short disable_draw_map : 1; unsigned short disable_act_scr : 1; unsigned short disable_act_map : 1; unsigned short unused : 12; };
#endif
#ifndef PROTO_DW_1890401_FIELDS
#define PROTO_DW_1890401_FIELDS
struct dw_1890401_fields { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float (*p_matrix)[4][4]; int prev_ptcl; short life_time; unsigned short ptcl_num; unsigned short prog_no; struct dw_1898869_fields flag; unsigned short sfx_sttdata_idx; unsigned char _pad0[14]; };
#endif
#ifndef PROTO_DW_1890884_FIELDS
#define PROTO_DW_1890884_FIELDS
struct dw_1890884_fields { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float rgba[4]; float n_speed[4]; float add_uv[2]; float dmy; char rand[4]; unsigned int lifecnt; unsigned int cnt; struct dw_1890884_fields *p_sibling; struct dw_1891466_fields *pEmitter; unsigned char extra_data[32]; float qtn[4]; };
#endif
#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif
#ifndef PROTO_DW_1902102_FIELDS
#define PROTO_DW_1902102_FIELDS
struct dw_1902102_fields { unsigned int Frame; char szName[26]; unsigned short sfx_idx; };
#endif
#ifndef PROTO_DW_1892300_FIELDS
#define PROTO_DW_1892300_FIELDS
struct dw_1892300_fields { int ProgramId; struct dw_1892300_fields *pParent; struct dw_1892300_fields *pChild; struct dw_1892300_fields *pSibling; int FixParamNum; struct dw_1904865_fields *pFixParam; int SeqParamNum; struct dw_1905892_fields *pSeqParam; struct dw_1902102_fields CommonParam; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_0__5ED7228F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_0__5ED7228F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_0__5ED7228F = (int)&(((struct dw_1890401_fields *)0)->ang[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_1__A795EEE1_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_1__A795EEE1_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_1__A795EEE1 = (int)&(((struct dw_1890401_fields *)0)->ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_2__3B661BD7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_2__3B661BD7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_2__3B661BD7 = (int)&(((struct dw_1890401_fields *)0)->ang[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24 = (int)&(((struct dw_1890401_fields *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A = (int)&(((struct dw_1890401_fields *)0)->ptcl_num) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D = (int)&(((struct dw_1890401_fields *)0)->scale[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01 = (int)&(((struct dw_1890401_fields *)0)->scale[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2 = (int)&(((struct dw_1890401_fields *)0)->scale[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700 = (int)&(((struct dw_1890884_fields *)0)->lifecnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED = (int)&(((struct dw_1890884_fields *)0)->loc[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E = (int)&(((struct dw_1890884_fields *)0)->n_speed[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9 = (int)&(((struct dw_1890884_fields *)0)->n_speed[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E = (int)&(((struct dw_1890884_fields *)0)->n_speed[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC = (int)&(((struct dw_1890884_fields *)0)->n_speed[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510 = (int)&(((struct dw_1890884_fields *)0)->pEmitter) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76 = (int)&(((struct dw_1890884_fields *)0)->p_sibling) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038 = (int)&(((struct dw_1890884_fields *)0)->rand[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C = (int)&(((struct dw_1890884_fields *)0)->rand[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC = (int)&(((struct dw_1890884_fields *)0)->rand[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F = (int)&(((struct dw_1890884_fields *)0)->rand[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD = (int)&(((struct dw_1891466_fields *)0)->lifecnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7 = (int)&(((struct dw_1891466_fields *)0)->matrix[0][0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9 = (int)&(((struct dw_1891466_fields *)0)->matrix[1][1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0 = (int)&(((struct dw_1891466_fields *)0)->matrix[2][2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B = (int)&(((struct dw_1891466_fields *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20 = (int)&(((struct dw_1891466_fields *)0)->p_seq_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B = (int)&(((struct dw_1891466_fields *)0)->ptcl_num) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F = (int)&(((struct dw_1892300_fields *)0)->pFixParam) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D = (int)&(((struct dw_1892300_fields *)0)->pSeqParam) - 0 };
#endif
/* _SubFunc_Plume_Move @ 0x1B1090 .. 0x1B13B4 (0x324 bytes, frame 0x170) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @2606 -> 0x248540
 *   fpu: mov.s at 0x1b10c8 is a float copy
 *   fpu: float literal 0x40c90fdb at 0x1b10fc
 *   fpu: float literal 0x4196cbe4 at 0x1b1104
 *   stack: address of the slot at 0x160 escapes at 0x1b1110
 *   stack: address of the slot at 0x120 escapes at 0x1b111c
 *   fpu: mov.s at 0x1b1138 is a float copy
 *   stack: address of the slot at 0x100 escapes at 0x1b113c
 *   stack: address of the slot at 0xf0 escapes at 0x1b113c
 *   fpu: float literal 0x00000000 at 0x1b1170
 *   fpu: float literal 0x3f800000 at 0x1b1188
 *   fpu: mov.s at 0x1b1190 is a float copy
 *   stack: address of the slot at 0x130 escapes at 0x1b1194
 *   fpu: mtc1 reinterprets v0 at 0x1b1194
 *   fpu: mov.s at 0x1b1198 is a float copy
 *   fpu: float literal 0xbf800000 at 0x1b11b8
 *   stack: address of the slot at 0x110 escapes at 0x1b11c4
 *   fpu: float literal 0x00000000 at 0x1b11f4
 *   fpu: float literal 0x3f800000 at 0x1b120c
 *   fpu: mtc1 reinterprets v0 at 0x1b1218
 *   fpu: float literal 0x00000000 at 0x1b1234
 *   fpu: float literal 0xbf800000 at 0x1b124c
 *   fpu: mov.s at 0x1b1254 is a float copy
 *   fpu: mtc1 reinterprets v0 at 0x1b1258
 *   fpu: mov.s at 0x1b125c is a float copy
 *   stack: address of the slot at 0x100 escapes at 0x1b1274
 *   stack: address of the slot at 0x110 escapes at 0x1b1284
 *   fpu: mov.s at 0x1b1298 is a float copy
 *   stack: address of the slot at 0xe0 escapes at 0x1b1294
 *   stack: address of the slot at 0xe0 escapes at 0x1b12a4
 *   stack: address of the slot at 0x50 escapes at 0x1b12b8
 *   fpu: mov.s at 0x1b12f4 is a float copy
 *   stack: address of the slot at 0x60 escapes at 0x1b12f0
 *   stack: address of the slot at 0xa0 escapes at 0x1b12fc
 *   stack: address of the slot at 0xa0 escapes at 0x1b137c
 *   literal: @2606 initializes the 16-byte local at 0xf0
 */

extern float sceVu0InnerProduct(void *,void *);
extern void sceVu0Normalize(void *, void *);
extern void sceVu0ScaleVector(void *, void *, float);
extern float fabsf(float);
extern void sceVu0AddVector(void *, void *, void *);
extern void SfxCalc_MakeMatrixFromPYR(void *, float, float, float);
extern void SfxCalc_QtnMakeFromMatrix(float *, void *);
extern u32 L2606[];
extern u32 VY[];
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif


#ifndef PROTO_DW_1890884_FIELDS
#define PROTO_DW_1890884_FIELDS
struct dw_1891466_fields;
struct dw_1890884_fields { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float rgba[4]; float n_speed[4]; float add_uv[2]; float dmy; char rand[4]; unsigned int lifecnt; unsigned int cnt; struct dw_1890884_fields *p_sibling; struct dw_1891466_fields *pEmitter; unsigned char extra_data[32]; float qtn[4]; };
#endif
struct dw_1899235_fields { float press_coeff; float valance; float pitch_coeff; unsigned short hModel; };


/* __SFX_DrawSprite2 @ 0x1B6530 .. 0x1B68A0 (0x370 bytes, frame 0xc0) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0xa4 escapes at 0x1b65c0
 *   stack: address of the slot at 0xa8 escapes at 0x1b65c0
 *   stack: address of the slot at 0xac escapes at 0x1b65c0
 *   stack: address of the slot at 0xb0 escapes at 0x1b65cc
 *   stack: address of the slot at 0xb0 escapes at 0x1b65e4
 *   stack: address of the slot at 0xa0 escapes at 0x1b66ac
 *   fpu: float literal 0x43000000 at 0x1b66c0
 *   fpu: float literal 0x4f000000 at 0x1b66c8
 *   fpu: float literal 0x43000000 at 0x1b6710
 *   fpu: float literal 0x4f000000 at 0x1b6718
 *   fpu: float literal 0x43000000 at 0x1b6760
 *   fpu: float literal 0x4f000000 at 0x1b676c
 *   fpu: float literal 0x43000000 at 0x1b67b4
 *   fpu: float literal 0x4f000000 at 0x1b67c0
 *   fpu: float literal 0xbf800000 at 0x1b682c
 *   stack: address of the slot at 0xb0 escapes at 0x1b6850
 *   stack: address of the slot at 0xa0 escapes at 0x1b6850
 *   quad: a0: 128-bit web split from its scalar variable as a0_q
 *   quad: v0: 128-bit web split from its scalar variable as v0_q
 *   cfg: loop body is not one contiguous region: .L001B65C0
 *   a1 typed from the __SFX_DrawSprite2 call table
 *   a2 typed from the __SFX_DrawSprite2 call table
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void SfxDraw_SetColor(unsigned int);
extern void SfxDraw_DrawSprite_Wld2(float *, float *, float, float *, float);





#ifndef PROTO_DW_1890884_FIELDS
#define PROTO_DW_1890884_FIELDS

#endif
#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif
#ifndef PROTO_DW_1904865_FIELDS
#define PROTO_DW_1904865_FIELDS
struct dw_1904865_fields { char cdummy; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE = (int)&(((struct dw_1890884_fields *)0)->ang[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_0__89D82EC2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_0__89D82EC2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_0__89D82EC2 = (int)&(((struct dw_1890884_fields *)0)->rgba[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_1__872F13A5_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_1__872F13A5_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_1__872F13A5 = (int)&(((struct dw_1890884_fields *)0)->rgba[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_2__2B1C9A34_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_2__2B1C9A34_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_2__2B1C9A34 = (int)&(((struct dw_1890884_fields *)0)->rgba[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_3__47898D35_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_3__47898D35_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_3__47898D35 = (int)&(((struct dw_1890884_fields *)0)->rgba[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_0__A4EC329F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_0__A4EC329F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_0__A4EC329F = (int)&(((struct dw_1890884_fields *)0)->scale[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_1__0DD44650_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_1__0DD44650_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_1__0DD44650 = (int)&(((struct dw_1890884_fields *)0)->scale[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1904865_FIELDS__56__CDUMMY_D98F238D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1904865_FIELDS__56__CDUMMY_D98F238D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1904865_FIELDS__56__CDUMMY_D98F238D = (int)&(((struct dw_1904865_fields *)0)[56].cdummy) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1904865_FIELDS__57__CDUMMY_6DE78BD2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1904865_FIELDS__57__CDUMMY_6DE78BD2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1904865_FIELDS__57__CDUMMY_6DE78BD2 = (int)&(((struct dw_1904865_fields *)0)[57].cdummy) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1904865_FIELDS__62__CDUMMY_78E3347D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1904865_FIELDS__62__CDUMMY_78E3347D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1904865_FIELDS__62__CDUMMY_78E3347D = (int)&(((struct dw_1904865_fields *)0)[62].cdummy) - 0 };
#endif


/* __SFX_ActSprite2 @ 0x1B68A0 .. 0x1B70B4 (0x814 bytes, frame 0x170) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1b68fc is a float copy
 *   stack: address of the slot at 0x160 escapes at 0x1b69d4
 *   fpu: float literal 0x3c23d70a at 0x1b69f0
 *   fpu: mtc1 reinterprets a0 at 0x1b69f8
 *   fpu: float literal 0x3c8ef34d at 0x1b6a20
 *   fpu: float literal 0xc0490fd0 at 0x1b6a24
 *   fpu: float literal 0x40490fd0 at 0x1b6a48
 *   fpu: float literal 0x40c90fd0 at 0x1b6a74
 *   stack: address of the slot at 0x130 escapes at 0x1b6a98
 *   fpu: float literal 0x3c23d70a at 0x1b6abc
 *   fpu: mtc1 reinterprets a0 at 0x1b6ac8
 *   stack: address of the slot at 0x134 escapes at 0x1b6af0
 *   stack: address of the slot at 0x138 escapes at 0x1b6b04
 *   fpu: float literal 0x3c23d70a at 0x1b6b20
 *   fpu: mtc1 reinterprets a0 at 0x1b6b28
 *   fpu: mtc1 reinterprets v1 at 0x1b6b50
 *   stack: address of the slot at 0x138 escapes at 0x1b6b70
 *   fpu: mov.s at 0x1b6b7c is a float copy
 *   stack: address of the slot at 0x120 escapes at 0x1b6b78
 *   stack: address of the slot at 0x120 escapes at 0x1b6b88
 *   stack: address of the slot at 0x16c escapes at 0x1b6ba4
 *   fpu: float literal 0x00000000 at 0x1b6bb0
 *   stack: address of the slot at 0xd0 escapes at 0x1b6c50
 *   stack: address of the slot at 0xd0 escapes at 0x1b6c54
 *   stack: address of the slot at 0x110 escapes at 0x1b6c64
 *   stack: address of the slot at 0xd8 escapes at 0x1b6c64
 *   fpu: float literal 0x00000000 at 0x1b6c74
 *   fpu: float literal 0x40490fdb at 0x1b6c80
 *   fpu: float literal 0x40c90fdb at 0x1b6ca4
 *   fpu: mtc1 reinterprets v0 at 0x1b6ccc
 *   stack: address of the slot at 0xd0 escapes at 0x1b6cf4
 *   fpu: float literal 0x40490fdb at 0x1b6d08
 *   fpu: float literal 0x00000000 at 0x1b6d0c
 *   fpu: float literal 0x40c90fdb at 0x1b6d30
 *   fpu: mtc1 reinterprets v0 at 0x1b6d58
 *   stack: address of the slot at 0xd0 escapes at 0x1b6d7c
 *   stack: address of the slot at 0xd0 escapes at 0x1b6d7c
 *   stack: address of the slot at 0x150 escapes at 0x1b6d90
 *   stack: address of the slot at 0xd0 escapes at 0x1b6d90
 *   stack: address of the slot at 0xc0 escapes at 0x1b6dac
 *   stack: address of the slot at 0x150 escapes at 0x1b6dac
 *   stack: address of the slot at 0xc0 escapes at 0x1b6dbc
 *   stack: address of the slot at 0x168 escapes at 0x1b6ddc
 *   fpu: mtc1 reinterprets v0 at 0x1b6df0
 *   fpu: mtc1 reinterprets v1 at 0x1b6e04
 *   fpu: float literal 0x43000000 at 0x1b6e18
 *   fpu: mtc1 reinterprets v0 at 0x1b6e38
 *   fpu: mtc1 reinterprets v1 at 0x1b6e4c
 *   fpu: float literal 0x43000000 at 0x1b6e60
 *   fpu: mtc1 reinterprets v0 at 0x1b6e80
 *   fpu: mtc1 reinterprets v1 at 0x1b6e94
 *   fpu: float literal 0x43000000 at 0x1b6eac
 *   stack: address of the slot at 0x16b escapes at 0x1b6ec8
 *   fpu: mtc1 reinterprets v1 at 0x1b6ee0
 *   fpu: mtc1 reinterprets a0 at 0x1b6ef4
 *   fpu: float literal 0x43000000 at 0x1b6f08
 *   stack: address of the slot at 0xb0 escapes at 0x1b6f34
 *   stack: address of the slot at 0xb0 escapes at 0x1b6f4c
 *   fpu: mov.s at 0x1b6f6c is a float copy
 *   fpu: float literal 0x00000000 at 0x1b6f7c
 *   fpu: float literal 0x3f800000 at 0x1b6fa4
 *   fpu: float literal 0x40490fdb at 0x1b6fc0
 *   fpu: mov.s at 0x1b6fd0 is a float copy
 *   fpu: mov.s at 0x1b6fdc is a float copy
 *   delay: addiu at 0x1b7008 writes a register its branch at 0x1b7004 reads
 *   cfg: kept goto: 0x1b68b0 -> .L001B7050
 *   cfg: kept branch: 0x1b6a40 if (..) goto .L001B6A64
 *   cfg: kept branch: 0x1b6fa4 if (..) goto .L001B6FF0
 *   cfg: loop body is not one contiguous region: .L001B7050
 *   cfg: kept branch: 0x1b7064 if (..) goto .L001B6900
 *   s1#2 is the pointer held in a0+0x48
 *   v1#10 is the pointer held in s1#1+0xa8
 *   a2 typed from the __SFX_ActSprite2 call table
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern float SfxCalc_IntoAngle_0_2PI(float);
extern void sceVu0CopyMatrix(void *, void *);
extern void SfxCalc_Vector2Angle(float *, float *);
extern void sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0RotMatrixX(void *, void *, float);
extern float Math_GetDist(float *, float *);
extern float SfxCalc_Sin(float);
extern float powf(float, float);
extern u32 MRX1[];
extern u32 VY[];
extern u8 *lpDrawMng;
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif


/* __SFX_InitSprite2 @ 0x1B70C0 .. 0x1B781C (0x75c bytes, frame 0xd0) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1b7110 writes a register its branch at 0x1b710c reads
 *   stack: address of the slot at 0xc8 escapes at 0x1b7248
 *   delay: lui at 0x1b7258 writes a register its branch at 0x1b7254 reads
 *   fpu: mtc1 reinterprets v0 at 0x1b727c
 *   fpu: mtc1 reinterprets v1 at 0x1b7290
 *   fpu: float literal 0x37800080 at 0x1b72ac
 *   fpu: mtc1 reinterprets v0 at 0x1b72b8
 *   fpu: mtc1 reinterprets v1 at 0x1b72d0
 *   fpu: float literal 0x3f000000 at 0x1b72e8
 *   fpu: mtc1 reinterprets v1 at 0x1b72fc
 *   fpu: float literal 0x4f000000 at 0x1b7300
 *   fpu: mtc1 reinterprets v0 at 0x1b735c
 *   fpu: mtc1 reinterprets v1 at 0x1b7370
 *   fpu: float literal 0x37800080 at 0x1b738c
 *   fpu: float literal 0x42c80000 at 0x1b7394
 *   fpu: float literal 0x3f000000 at 0x1b73a0
 *   fpu: mtc1 reinterprets v0 at 0x1b73cc
 *   fpu: mtc1 reinterprets v1 at 0x1b73e0
 *   fpu: float literal 0x37800080 at 0x1b73fc
 *   fpu: float literal 0x42c80000 at 0x1b7404
 *   fpu: float literal 0x3f000000 at 0x1b7410
 *   fpu: mtc1 reinterprets v0 at 0x1b743c
 *   fpu: mtc1 reinterprets v1 at 0x1b7450
 *   fpu: float literal 0x37800080 at 0x1b746c
 *   fpu: float literal 0x42c80000 at 0x1b7474
 *   fpu: float literal 0x3f000000 at 0x1b7480
 *   fpu: mtc1 reinterprets v0 at 0x1b74ac
 *   fpu: mtc1 reinterprets v1 at 0x1b74c0
 *   fpu: float literal 0x37800080 at 0x1b74dc
 *   fpu: float literal 0x42c80000 at 0x1b74e4
 *   fpu: float literal 0x3f000000 at 0x1b74f0
 *   fpu: mtc1 reinterprets v0 at 0x1b7528
 *   fpu: mtc1 reinterprets v1 at 0x1b753c
 *   fpu: float literal 0x37800080 at 0x1b755c
 *   fpu: float literal 0x3f000000 at 0x1b7560
 *   fpu: float literal 0x3c8ef34d at 0x1b7590
 *   stack: address of the slot at 0xc0 escapes at 0x1b75a8
 *   fpu: float literal 0x00000000 at 0x1b75c8
 *   fpu: mtc1 reinterprets v0 at 0x1b75f0
 *   fpu: mtc1 reinterprets v1 at 0x1b7604
 *   fpu: float literal 0x37800080 at 0x1b7620
 *   fpu: float literal 0x3f000000 at 0x1b762c
 *   fpu: float literal 0x00000000 at 0x1b7658
 *   fpu: mtc1 reinterprets v0 at 0x1b7680
 *   fpu: mtc1 reinterprets v1 at 0x1b7694
 *   fpu: float literal 0x37800080 at 0x1b76b0
 *   fpu: float literal 0x3f000000 at 0x1b76bc
 *   fpu: float literal 0x00000000 at 0x1b76e4
 *   fpu: mtc1 reinterprets v0 at 0x1b770c
 *   fpu: mtc1 reinterprets v1 at 0x1b7720
 *   fpu: float literal 0x37800080 at 0x1b773c
 *   fpu: float literal 0x3f000000 at 0x1b7748
 *   fpu: float literal 0x3c8ef34d at 0x1b7774
 *   fpu: float literal 0x00000000 at 0x1b7778
 *   stack: address of the slot at 0x80 escapes at 0x1b7780
 *   stack: address of the slot at 0x80 escapes at 0x1b7790
 *   stack: address of the slot at 0xc0 escapes at 0x1b7790
 *   cfg: loop body is not one contiguous region: .L001B7248
 *   v0#25 is the pointer held in a0+0x48
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void SfxCalc_MakeMatrix_SPYRT(void *, float *, float *, float *);

extern void SfxCalc_MakeMatrixFromPYR(void *, float, float, float);

struct dw_1890884_fields_a92cd2e9;
struct dw_1891466_fields_a92cd2e9;
struct dw_1892300_fields_a92cd2e9;
struct dw_1904865_fields_a92cd2e9;
struct dw_1905892_fields_a92cd2e9;
#ifndef PROTO_DW_1898869_FIELDS_A92CD2E9
#define PROTO_DW_1898869_FIELDS_A92CD2E9
struct dw_1898869_fields_a92cd2e9 { unsigned short disable_draw_scr : 1; unsigned short disable_draw_map : 1; unsigned short disable_act_scr : 1; unsigned short disable_act_map : 1; unsigned short unused : 12; };
#endif
#ifndef PROTO_DW_1890401_FIELDS_A92CD2E9
#define PROTO_DW_1890401_FIELDS_A92CD2E9
struct dw_1890401_fields_a92cd2e9 { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float (*p_matrix)[4][4]; int prev_ptcl; short life_time; unsigned short ptcl_num; unsigned short prog_no; struct dw_1898869_fields_a92cd2e9 flag; unsigned short sfx_sttdata_idx; unsigned char _pad0[14]; };
#endif
#ifndef PROTO_DW_1890884_FIELDS_A92CD2E9
#define PROTO_DW_1890884_FIELDS_A92CD2E9
struct dw_1890884_fields_a92cd2e9 { float mRot[4][4]; float loc[4]; float ang[4]; float scale[4]; float rgba[4]; float n_speed[4]; float add_uv[2]; float dmy; char rand[4]; unsigned int lifecnt; unsigned int cnt; struct dw_1890884_fields_a92cd2e9 *p_sibling; struct dw_1891466_fields_a92cd2e9 *pEmitter; unsigned char extra_data[32]; float qtn[4]; };
#endif
#ifndef PROTO_DW_1916235_FIELDS_A92CD2E9
#define PROTO_DW_1916235_FIELDS_A92CD2E9
struct dw_1916235_fields_a92cd2e9 { unsigned short disable_draw : 1; unsigned short disable_draw_by_map : 1; unsigned short disable_act : 1; unsigned short disable_act_by_map : 1; unsigned short draw_stage : 4; unsigned short unused : 8; };
#endif
#ifndef PROTO_DW_1891466_FIELDS_A92CD2E9
#define PROTO_DW_1891466_FIELDS_A92CD2E9
struct dw_1891466_fields_a92cd2e9 { float matrix[4][4]; float (*p_matrix)[4][4]; unsigned short prog_no; unsigned char ptcl_num; unsigned char dmy; struct dw_1890884_fields_a92cd2e9 *p_ptcl_top; struct dw_1904865_fields_a92cd2e9 *p_fix_param; struct dw_1905892_fields_a92cd2e9 *p_seq_param; struct dw_1891466_fields_a92cd2e9 *p_prev; struct dw_1891466_fields_a92cd2e9 *p_next; struct dw_1891466_fields_a92cd2e9 *p_relation_prev; struct dw_1891466_fields_a92cd2e9 *p_relation_next; unsigned int lifecnt; unsigned int cnt; struct dw_1916235_fields_a92cd2e9 bit_flag; unsigned short sfx_sttdata_idx; unsigned short cframe; unsigned char dmy2[14]; unsigned char extra_data[32]; };
#endif
#ifndef PROTO_DW_1902102_FIELDS_A92CD2E9
#define PROTO_DW_1902102_FIELDS_A92CD2E9
struct dw_1902102_fields_a92cd2e9 { unsigned int Frame; char szName[26]; unsigned short sfx_idx; };
#endif
#ifndef PROTO_DW_1892300_FIELDS_A92CD2E9
#define PROTO_DW_1892300_FIELDS_A92CD2E9
struct dw_1892300_fields_a92cd2e9 { int ProgramId; struct dw_1892300_fields_a92cd2e9 *pParent; struct dw_1892300_fields_a92cd2e9 *pChild; struct dw_1892300_fields_a92cd2e9 *pSibling; int FixParamNum; struct dw_1904865_fields_a92cd2e9 *pFixParam; int SeqParamNum; struct dw_1905892_fields_a92cd2e9 *pSeqParam; struct dw_1902102_fields_a92cd2e9 CommonParam; };
#endif
#ifndef PROTO_DW_1904865_FIELDS_A92CD2E9
#define PROTO_DW_1904865_FIELDS_A92CD2E9
struct dw_1904865_fields_a92cd2e9 { char cdummy; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_P_MATRIX_856A4D9C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_P_MATRIX_856A4D9C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_P_MATRIX_856A4D9C = (int)&(((struct dw_1890401_fields_a92cd2e9 *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_PTCL_NUM_5C66241F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_PTCL_NUM_5C66241F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_PTCL_NUM_5C66241F = (int)&(((struct dw_1890401_fields_a92cd2e9 *)0)->ptcl_num) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_0__5DFAC5FD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_0__5DFAC5FD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_0__5DFAC5FD = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->ang[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_1__7C315EB0_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_1__7C315EB0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_1__7C315EB0 = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_2__44E621F2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_2__44E621F2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_2__44E621F2 = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->ang[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_3__84C321C3_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_3__84C321C3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_3__84C321C3 = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->ang[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LIFECNT_92F2613A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LIFECNT_92F2613A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LIFECNT_92F2613A = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->lifecnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LOC_3__E52D55BB_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LOC_3__E52D55BB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LOC_3__E52D55BB = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->loc[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_PEMITTER_8D2B2DDD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_PEMITTER_8D2B2DDD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_PEMITTER_8D2B2DDD = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->pEmitter) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_P_SIBLING_8BDDA96F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_P_SIBLING_8BDDA96F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_P_SIBLING_8BDDA96F = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->p_sibling) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_0__A5F80208_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_0__A5F80208_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_0__A5F80208 = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->rand[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_1__649EEDFC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_1__649EEDFC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_1__649EEDFC = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->rand[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_2__16CFF809_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_2__16CFF809_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_2__16CFF809 = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->rand[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_3__2BF6EA67_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_3__2BF6EA67_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_3__2BF6EA67 = (int)&(((struct dw_1890884_fields_a92cd2e9 *)0)->rand[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_LIFECNT_7CEC2A9C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_LIFECNT_7CEC2A9C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_LIFECNT_7CEC2A9C = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->lifecnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_FIX_PARAM_89E876C2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_FIX_PARAM_89E876C2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_FIX_PARAM_89E876C2 = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->p_fix_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_MATRIX_84DDDCB3_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_MATRIX_84DDDCB3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_MATRIX_84DDDCB3 = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_PTCL_TOP_1E22B1BC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_PTCL_TOP_1E22B1BC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_PTCL_TOP_1E22B1BC = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->p_ptcl_top) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_SEQ_PARAM_BCE30E49_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_SEQ_PARAM_BCE30E49_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_SEQ_PARAM_BCE30E49 = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->p_seq_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_PTCL_NUM_86E21A87_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_PTCL_NUM_86E21A87_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_PTCL_NUM_86E21A87 = (int)&(((struct dw_1891466_fields_a92cd2e9 *)0)->ptcl_num) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PFIXPARAM_FECB6825_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PFIXPARAM_FECB6825_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PFIXPARAM_FECB6825 = (int)&(((struct dw_1892300_fields_a92cd2e9 *)0)->pFixParam) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PSEQPARAM_30AF687F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PSEQPARAM_30AF687F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PSEQPARAM_30AF687F = (int)&(((struct dw_1892300_fields_a92cd2e9 *)0)->pSeqParam) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__59__CDUMMY_A7408244_DEFINED
#define DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__59__CDUMMY_A7408244_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__59__CDUMMY_A7408244 = (int)&(((struct dw_1904865_fields_a92cd2e9 *)0)[59].cdummy) - 0 };
#endif
#define PTCL_RNDRANGE(dst, b, r) \
    if (0.0f < (r)) { \
        float rr_ = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32(); \
        (dst) = (b) + (r) * (rr_ - 0.5f); \
    } else { \
        (dst) = (b); \
    }

/* __SFX_ActSprite @ 0x1B7AB0 .. 0x1B80FC (0x64c bytes, frame 0x180) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1b7b04 is a float copy
 *   stack: address of the slot at 0x168 escapes at 0x1b7bec
 *   fpu: float literal 0x3c8ef34d at 0x1b7c08
 *   fpu: float literal 0xc0490fd0 at 0x1b7c24
 *   fpu: float literal 0x40490fd0 at 0x1b7c40
 *   fpu: float literal 0x40c90fd0 at 0x1b7c6c
 *   stack: address of the slot at 0x130 escapes at 0x1b7c90
 *   fpu: float literal 0x3c23d70a at 0x1b7cb4
 *   fpu: mtc1 reinterprets a0 at 0x1b7cc0
 *   stack: address of the slot at 0x134 escapes at 0x1b7ce8
 *   stack: address of the slot at 0x138 escapes at 0x1b7cfc
 *   fpu: float literal 0x3c23d70a at 0x1b7d18
 *   fpu: mtc1 reinterprets a0 at 0x1b7d20
 *   fpu: mtc1 reinterprets v1 at 0x1b7d48
 *   stack: address of the slot at 0x138 escapes at 0x1b7d68
 *   fpu: mov.s at 0x1b7d74 is a float copy
 *   stack: address of the slot at 0x120 escapes at 0x1b7d70
 *   stack: address of the slot at 0x120 escapes at 0x1b7d80
 *   stack: address of the slot at 0x17c escapes at 0x1b7d9c
 *   fpu: float literal 0x00000000 at 0x1b7da8
 *   stack: address of the slot at 0xd0 escapes at 0x1b7e48
 *   stack: address of the slot at 0xd0 escapes at 0x1b7e4c
 *   stack: address of the slot at 0x110 escapes at 0x1b7e5c
 *   stack: address of the slot at 0xd8 escapes at 0x1b7e5c
 *   stack: address of the slot at 0xd0 escapes at 0x1b7e74
 *   stack: address of the slot at 0xd0 escapes at 0x1b7e88
 *   stack: address of the slot at 0xd0 escapes at 0x1b7e88
 *   stack: address of the slot at 0xd0 escapes at 0x1b7ed0
 *   stack: address of the slot at 0x150 escapes at 0x1b7ed0
 *   stack: address of the slot at 0xc0 escapes at 0x1b7edc
 *   stack: address of the slot at 0x150 escapes at 0x1b7edc
 *   stack: address of the slot at 0xc0 escapes at 0x1b7eec
 *   stack: address of the slot at 0x178 escapes at 0x1b7f0c
 *   fpu: mtc1 reinterprets v0 at 0x1b7f20
 *   fpu: mtc1 reinterprets v1 at 0x1b7f34
 *   fpu: float literal 0x43000000 at 0x1b7f48
 *   fpu: mtc1 reinterprets v0 at 0x1b7f68
 *   fpu: mtc1 reinterprets v1 at 0x1b7f7c
 *   fpu: float literal 0x43000000 at 0x1b7f90
 *   fpu: mtc1 reinterprets v0 at 0x1b7fb0
 *   fpu: mtc1 reinterprets v1 at 0x1b7fc4
 *   fpu: float literal 0x43000000 at 0x1b7fdc
 *   stack: address of the slot at 0x17b escapes at 0x1b7ff8
 *   fpu: mtc1 reinterprets v1 at 0x1b8010
 *   fpu: mtc1 reinterprets a0 at 0x1b8024
 *   fpu: float literal 0x43000000 at 0x1b803c
 *   delay: addiu at 0x1b8058 writes a register its branch at 0x1b8054 reads
 *   cfg: kept goto: 0x1b7ac8 -> .L001B80A0
 *   cfg: kept branch: 0x1b7c38 if (..) goto .L001B7C5C
 *   cfg: loop body is not one contiguous region: .L001B80A0
 *   cfg: kept branch: 0x1b80b4 if (..) goto .L001B7B18
 *   s0#2 is the pointer held in a0+0x48
 *   v1#11 is the pointer held in s0#1+0xa8
 *   a2 typed from the __SFX_ActSprite call table
 *   declaration vs inferred signature: return void vs inferred u32
 */
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif

#ifndef DCOMP_COP2_21F95D43C1
#define DCOMP_COP2_21F95D43C1

#endif






#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED

#endif


/* __SFX_InitSprite @ 0x1B8100 .. 0x1B873C (0x63c bytes, frame 0x60) */
/*
 * dcomp notes:
 *   delay: lui at 0x1b8260 writes a register its branch at 0x1b825c reads
 *   fpu: mtc1 reinterprets v0 at 0x1b8284
 *   fpu: mtc1 reinterprets v1 at 0x1b8298
 *   fpu: float literal 0x37800080 at 0x1b82b4
 *   fpu: mtc1 reinterprets v0 at 0x1b82c0
 *   fpu: mtc1 reinterprets v1 at 0x1b82d8
 *   fpu: float literal 0x3f000000 at 0x1b82f0
 *   fpu: mtc1 reinterprets v1 at 0x1b8304
 *   fpu: float literal 0x4f000000 at 0x1b8308
 *   fpu: mtc1 reinterprets v0 at 0x1b8364
 *   fpu: mtc1 reinterprets v1 at 0x1b8378
 *   fpu: float literal 0x37800080 at 0x1b8394
 *   fpu: float literal 0x42c80000 at 0x1b839c
 *   fpu: float literal 0x3f000000 at 0x1b83a8
 *   fpu: mtc1 reinterprets v0 at 0x1b83d4
 *   fpu: mtc1 reinterprets v1 at 0x1b83e8
 *   fpu: float literal 0x37800080 at 0x1b8404
 *   fpu: float literal 0x42c80000 at 0x1b840c
 *   fpu: float literal 0x3f000000 at 0x1b8418
 *   fpu: mtc1 reinterprets v0 at 0x1b8444
 *   fpu: mtc1 reinterprets v1 at 0x1b8458
 *   fpu: float literal 0x37800080 at 0x1b8474
 *   fpu: float literal 0x42c80000 at 0x1b847c
 *   fpu: float literal 0x3f000000 at 0x1b8488
 *   fpu: mtc1 reinterprets v0 at 0x1b84b4
 *   fpu: mtc1 reinterprets v1 at 0x1b84c8
 *   fpu: float literal 0x37800080 at 0x1b84e4
 *   fpu: float literal 0x42c80000 at 0x1b84ec
 *   fpu: float literal 0x3f000000 at 0x1b84f8
 *   fpu: mtc1 reinterprets v0 at 0x1b8530
 *   fpu: mtc1 reinterprets v1 at 0x1b8544
 *   fpu: float literal 0x37800080 at 0x1b8560
 *   fpu: float literal 0x3f000000 at 0x1b8564
 *   fpu: float literal 0x3c8ef34d at 0x1b8590
 *   fpu: mtc1 reinterprets v0 at 0x1b85b4
 *   fpu: mtc1 reinterprets v1 at 0x1b85c8
 *   fpu: float literal 0x37800080 at 0x1b85e4
 *   fpu: float literal 0x3f000000 at 0x1b85f0
 *   fpu: mtc1 reinterprets v0 at 0x1b8618
 *   fpu: mtc1 reinterprets v1 at 0x1b862c
 *   fpu: float literal 0x37800080 at 0x1b8648
 *   fpu: float literal 0x3f000000 at 0x1b8654
 *   fpu: mtc1 reinterprets v0 at 0x1b867c
 *   fpu: mtc1 reinterprets v1 at 0x1b8690
 *   fpu: float literal 0x37800080 at 0x1b86b0
 *   fpu: float literal 0x3f000000 at 0x1b86bc
 *   cfg: loop body is not one contiguous region: .L001B8250
 *   v0#10 is the pointer held in a0+0x48
 *   declaration vs inferred signature: return void vs inferred u32
 */



#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif







#ifndef PROTO_DW_1898869_FIELDS
#define PROTO_DW_1898869_FIELDS

#endif
#ifndef PROTO_DW_1890401_FIELDS
#define PROTO_DW_1890401_FIELDS

#endif
#ifndef PROTO_DW_1890884_FIELDS
#define PROTO_DW_1890884_FIELDS

#endif
#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif
#ifndef PROTO_DW_1902102_FIELDS
#define PROTO_DW_1902102_FIELDS

#endif
#ifndef PROTO_DW_1892300_FIELDS
#define PROTO_DW_1892300_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C = (int)&(((struct dw_1890884_fields *)0)->ang[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_1__C6D2CBBE_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_1__C6D2CBBE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_1__C6D2CBBE = (int)&(((struct dw_1890884_fields *)0)->ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE = (int)&(((struct dw_1890884_fields *)0)->ang[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_3__500368EC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_3__500368EC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_3__500368EC = (int)&(((struct dw_1890884_fields *)0)->ang[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED

#endif


/* PtclMng_EnableDraw @ 0x1B8810 .. 0x1B89A0 (0x190 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1b88fc writes a register its branch at 0x1b88f8 reads
 *   cfg: kept goto: 0x1b8870 -> .L001B8980
 *   cfg: kept branch: 0x1b88fc if (..) goto .L001B8958
 *   cfg: loop test does not fall through into its body: 0x1b8960
 *   cfg: kept branch: 0x1b8960 if (..) goto .L001B8878
 *   cfg: kept goto: 0x1b8970 -> .L001B8960
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int SfxMdl_EnableDraw(unsigned short, signed int);


/* __SFX_EndPtclDefault @ 0x1B89A0 .. 0x1B89CC (0x2c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   a1 typed from the __SFX_EndPtclDefault call table
 *   a2 typed from the __SFX_EndPtclDefault call table
 */

extern signed int SfxMdl_Free(unsigned short);

/* _SetMdlParamToMdlMng @ 0x1B89D0 .. 0x1B8F48 (0x578 bytes, frame 0x110) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0xd0 escapes at 0x1b8a3c
 *   stack: address of the slot at 0xc0 escapes at 0x1b8b38
 *   stack: address of the slot at 0x100 escapes at 0x1b8b38
 *   fpu: mov.s at 0x1b8b4c is a float copy
 *   fpu: float literal 0x40490fdb at 0x1b8ba8
 *   fpu: float literal 0x00000000 at 0x1b8bac
 *   fpu: float literal 0x40c90fdb at 0x1b8bcc
 *   fpu: mtc1 reinterprets v0 at 0x1b8bf0
 *   stack: address of the slot at 0x80 escapes at 0x1b8c18
 *   fpu: mov.s at 0x1b8c20 is a float copy
 *   stack: address of the slot at 0xd0 escapes at 0x1b8c28
 *   stack: address of the slot at 0x80 escapes at 0x1b8c28
 *   fpu: mov.s at 0x1b8c30 is a float copy
 *   stack: address of the slot at 0xe0 escapes at 0x1b8c38
 *   stack: address of the slot at 0x90 escapes at 0x1b8c38
 *   fpu: mov.s at 0x1b8c40 is a float copy
 *   stack: address of the slot at 0xf0 escapes at 0x1b8c48
 *   stack: address of the slot at 0xa0 escapes at 0x1b8c48
 *   stack: address of the slot at 0x70 escapes at 0x1b8c64
 *   stack: address of the slot at 0xd0 escapes at 0x1b8c98
 *   stack: address of the slot at 0x70 escapes at 0x1b8c98
 *   stack: address of the slot at 0x60 escapes at 0x1b8d8c
 *   stack: address of the slot at 0xf0 escapes at 0x1b8d8c
 *   stack: address of the slot at 0x50 escapes at 0x1b8d9c
 *   stack: address of the slot at 0x100 escapes at 0x1b8d9c
 *   stack: address of the slot at 0x60 escapes at 0x1b8dac
 *   stack: address of the slot at 0x60 escapes at 0x1b8dac
 *   stack: address of the slot at 0xd0 escapes at 0x1b8db8
 *   stack: address of the slot at 0x60 escapes at 0x1b8db8
 *   stack: address of the slot at 0x100 escapes at 0x1b8dc4
 *   stack: address of the slot at 0x50 escapes at 0x1b8dc4
 *   stack: address of the slot at 0x100 escapes at 0x1b8dd8
 *   stack: address of the slot at 0xd0 escapes at 0x1b8de8
 *   stack: address of the slot at 0xd0 escapes at 0x1b8ed8
 *   stack: address of the slot at 0xd0 escapes at 0x1b8edc
 */

extern void SfxCalc_MakeRotTransMatrix_I_LEGACY(void *, float *, float *, float *);
extern u32 GetCameraPos();
extern float Math_VectorToAngle(float, float);
extern void sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0Normalize(void *, void *);
extern void SfxCalc_MakeMatrixFromDir(void *, float *);
extern signed int SfxMdl_SetMatrix_LEGACY(unsigned short, void *);
extern signed int SfxMdl_SetScale_LEGACY(unsigned short, float *);
extern u32 V0[];
extern u32 MRX1[];
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif


/* __SFX_ActDefault @ 0x1B8F50 .. 0x1B99EC (0xa9c bytes, frame 0x2b0) */
/*
 * dcomp notes:
 *   literal: @3373 is the string 'PtclMng.c'
 *   literal: @3374 is the string 'Invalid angle control type'
 *   fpu: mov.s at 0x1b8fa0 is a float copy
 *   stack: address of the slot at 0x298 escapes at 0x1b90bc
 *   fpu: float literal 0x3c8ef34d at 0x1b90d8
 *   fpu: float literal 0xc0490fd0 at 0x1b90f8
 *   fpu: float literal 0x40490fd0 at 0x1b9110
 *   fpu: float literal 0x40c90fd0 at 0x1b913c
 *   fpu: float literal 0xc0490fd0 at 0x1b9158
 *   fpu: float literal 0x40490fd0 at 0x1b9170
 *   fpu: float literal 0x40c90fd0 at 0x1b919c
 *   fpu: float literal 0xc0490fd0 at 0x1b91b8
 *   fpu: float literal 0x40490fd0 at 0x1b91d0
 *   fpu: float literal 0x40c90fd0 at 0x1b91fc
 *   stack: address of the slot at 0x180 escapes at 0x1b9230
 *   stack: address of the slot at 0x180 escapes at 0x1b9248
 *   stack: address of the slot at 0xf0 escapes at 0x1b9270
 *   fpu: float literal 0x3c23d70a at 0x1b9298
 *   fpu: mtc1 reinterprets a0 at 0x1b92a4
 *   stack: address of the slot at 0xf4 escapes at 0x1b92d0
 *   stack: address of the slot at 0xf8 escapes at 0x1b92e4
 *   stack: address of the slot at 0x100 escapes at 0x1b9300
 *   fpu: float literal 0x3c23d70a at 0x1b931c
 *   fpu: mtc1 reinterprets a0 at 0x1b9324
 *   fpu: mtc1 reinterprets v1 at 0x1b934c
 *   fpu: mtc1 reinterprets v1 at 0x1b9378
 *   stack: address of the slot at 0x100 escapes at 0x1b9398
 *   fpu: mov.s at 0x1b93a4 is a float copy
 *   stack: address of the slot at 0x170 escapes at 0x1b93a0
 *   stack: address of the slot at 0x170 escapes at 0x1b93b0
 *   stack: address of the slot at 0x2ac escapes at 0x1b93cc
 *   fpu: float literal 0x00000000 at 0x1b93d8
 *   stack: address of the slot at 0x120 escapes at 0x1b9400
 *   stack: address of the slot at 0x160 escapes at 0x1b940c
 *   stack: address of the slot at 0x128 escapes at 0x1b940c
 *   stack: address of the slot at 0x120 escapes at 0x1b9424
 *   stack: address of the slot at 0x120 escapes at 0x1b9438
 *   stack: address of the slot at 0x120 escapes at 0x1b9438
 *   stack: address of the slot at 0x120 escapes at 0x1b9480
 *   stack: address of the slot at 0x280 escapes at 0x1b9480
 *   stack: address of the slot at 0x110 escapes at 0x1b948c
 *   stack: address of the slot at 0x280 escapes at 0x1b948c
 *   stack: address of the slot at 0x110 escapes at 0x1b949c
 *   stack: address of the slot at 0x2a8 escapes at 0x1b94c0
 *   fpu: mtc1 reinterprets v0 at 0x1b94d4
 *   fpu: mtc1 reinterprets v1 at 0x1b94e8
 *   fpu: float literal 0x43000000 at 0x1b94fc
 *   fpu: mtc1 reinterprets v0 at 0x1b951c
 *   fpu: mtc1 reinterprets v1 at 0x1b9530
 *   fpu: float literal 0x43000000 at 0x1b9544
 *   fpu: mtc1 reinterprets v0 at 0x1b9564
 *   fpu: mtc1 reinterprets v1 at 0x1b9578
 *   fpu: float literal 0x43000000 at 0x1b9590
 *   stack: address of the slot at 0x2ab escapes at 0x1b95ac
 *   fpu: mtc1 reinterprets v0 at 0x1b95c4
 *   fpu: mtc1 reinterprets v1 at 0x1b95d8
 *   fpu: float literal 0x43000000 at 0x1b95f0
 *   fpu: mtc1 reinterprets v1 at 0x1b9630
 *   fpu: mtc1 reinterprets a0 at 0x1b9648
 *   fpu: mtc1 reinterprets v1 at 0x1b968c
 *   fpu: mtc1 reinterprets a0 at 0x1b96a0
 *   fpu: float literal 0x3f800000 at 0x1b96b4
 *   fpu: mtc1 reinterprets a3 at 0x1b96c0
 *   fpu: mtc1 reinterprets a0 at 0x1b96d4
 *   fpu: mtc1 reinterprets v1 at 0x1b971c
 *   fpu: mtc1 reinterprets a0 at 0x1b9734
 *   fpu: float literal 0x3f800000 at 0x1b9748
 *   fpu: mtc1 reinterprets v0 at 0x1b9754
 *   fpu: mtc1 reinterprets v1 at 0x1b9768
 *   fpu: mtc1 reinterprets v0 at 0x1b97a4
 *   fpu: mtc1 reinterprets v1 at 0x1b97b8
 *   fpu: mtc1 reinterprets v0 at 0x1b97e0
 *   fpu: mtc1 reinterprets v1 at 0x1b97f4
 *   fpu: float literal 0x3f800000 at 0x1b980c
 *   fpu: float literal 0x3f800000 at 0x1b9840
 *   fpu: float literal 0x00000000 at 0x1b9864
 *   fpu: float literal 0x3f800000 at 0x1b9884
 *   fpu: float literal 0x00000000 at 0x1b989c
 *   fpu: float literal 0x3f800000 at 0x1b98bc
 *   delay: addiu at 0x1b98ec writes a register its branch at 0x1b98e8 reads
 *   cfg: kept goto: 0x1b8f68 -> .L001B9990
 *   cfg: kept branch: 0x1b9108 if (..) goto .L001B912C
 *   cfg: kept branch: 0x1b9168 if (..) goto .L001B918C
 *   cfg: kept branch: 0x1b91c8 if (..) goto .L001B91EC
 *   cfg: loop body is not one contiguous region: .L001B9990
 *   cfg: kept branch: 0x1b99a4 if (..) goto .L001B8FB8
 *   v1#11 is the pointer held in s1#1+0xa8
 *   a2 typed from the __SFX_ActDefault call table
 *   declaration vs inferred signature: return void vs inferred u32
 */




#ifndef DCOMP_COP2_21F95D43C1
#define DCOMP_COP2_21F95D43C1

#endif






#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED

#endif


/* __SFX_InitDefault @ 0x1B99F0 .. 0x1BA590 (0xba0 bytes, frame 0x230) */
/*
 * dcomp notes:
 *   literal: @3373 is the string 'PtclMng.c'
 *   literal: @3668 is the string '3DÓÃÞÙ\x8a\x84\x82è\x93\x96\x82Ä\x8e¸\x94s'
 *   stack: address of the slot at 0xb4 escapes at 0x1b9b58
 *   delay: lui at 0x1b9b6c writes a register its branch at 0x1b9b68 reads
 *   fpu: mtc1 reinterprets v0 at 0x1b9b94
 *   fpu: mtc1 reinterprets v1 at 0x1b9ba8
 *   fpu: float literal 0x37800080 at 0x1b9bc4
 *   fpu: mtc1 reinterprets v0 at 0x1b9bd0
 *   fpu: mtc1 reinterprets v1 at 0x1b9be8
 *   fpu: float literal 0x3f000000 at 0x1b9c00
 *   fpu: mtc1 reinterprets v1 at 0x1b9c14
 *   fpu: float literal 0x4f000000 at 0x1b9c18
 *   fpu: mtc1 reinterprets v0 at 0x1b9c74
 *   fpu: mtc1 reinterprets v1 at 0x1b9c88
 *   fpu: float literal 0x37800080 at 0x1b9ca4
 *   fpu: float literal 0x42c80000 at 0x1b9cac
 *   fpu: float literal 0x3f000000 at 0x1b9cb8
 *   fpu: mtc1 reinterprets v0 at 0x1b9ce4
 *   fpu: mtc1 reinterprets v1 at 0x1b9cf8
 *   fpu: float literal 0x37800080 at 0x1b9d14
 *   fpu: float literal 0x42c80000 at 0x1b9d1c
 *   fpu: float literal 0x3f000000 at 0x1b9d28
 *   fpu: mtc1 reinterprets v0 at 0x1b9d54
 *   fpu: mtc1 reinterprets v1 at 0x1b9d68
 *   fpu: float literal 0x37800080 at 0x1b9d84
 *   fpu: float literal 0x42c80000 at 0x1b9d8c
 *   fpu: float literal 0x3f000000 at 0x1b9d98
 *   fpu: mtc1 reinterprets v0 at 0x1b9dc4
 *   fpu: mtc1 reinterprets v1 at 0x1b9dd8
 *   fpu: float literal 0x37800080 at 0x1b9df8
 *   fpu: float literal 0x42c80000 at 0x1b9dfc
 *   fpu: float literal 0x3f000000 at 0x1b9e10
 *   stack: address of the slot at 0x210 escapes at 0x1b9e30
 *   fpu: float literal 0x00000000 at 0x1b9e50
 *   fpu: mtc1 reinterprets v0 at 0x1b9e78
 *   fpu: mtc1 reinterprets v1 at 0x1b9e8c
 *   fpu: float literal 0x37800080 at 0x1b9ea8
 *   fpu: float literal 0x3f000000 at 0x1b9eb4
 *   fpu: float literal 0x00000000 at 0x1b9ee4
 *   fpu: mtc1 reinterprets v0 at 0x1b9f0c
 *   fpu: mtc1 reinterprets v1 at 0x1b9f20
 *   fpu: float literal 0x37800080 at 0x1b9f3c
 *   fpu: float literal 0x3f000000 at 0x1b9f48
 *   fpu: float literal 0x00000000 at 0x1b9f6c
 *   fpu: mtc1 reinterprets v0 at 0x1b9f94
 *   fpu: mtc1 reinterprets v1 at 0x1b9fa8
 *   fpu: float literal 0x37800080 at 0x1b9fc4
 *   fpu: float literal 0x3f000000 at 0x1b9fd0
 *   fpu: float literal 0x00000000 at 0x1b9ff4
 *   fpu: mtc1 reinterprets v0 at 0x1ba01c
 *   fpu: mtc1 reinterprets v1 at 0x1ba030
 *   fpu: float literal 0x37800080 at 0x1ba04c
 *   fpu: float literal 0x3f000000 at 0x1ba058
 *   fpu: float literal 0x3c8ef34d at 0x1ba084
 *   fpu: mov.s at 0x1ba098 is a float copy
 *   fpu: mov.s at 0x1ba09c is a float copy
 *   fpu: mov.s at 0x1ba0a4 is a float copy
 *   stack: address of the slot at 0x1d0 escapes at 0x1ba0a0
 *   stack: address of the slot at 0x1d0 escapes at 0x1ba0b0
 *   stack: address of the slot at 0x210 escapes at 0x1ba0b0
 *   fpu: float literal 0xc0490fd0 at 0x1ba0d4
 *   fpu: float literal 0x40490fd0 at 0x1ba0ec
 *   fpu: float literal 0x40c90fd0 at 0x1ba118
 *   fpu: float literal 0xc0490fd0 at 0x1ba134
 *   fpu: float literal 0x40490fd0 at 0x1ba14c
 *   fpu: float literal 0x40c90fd0 at 0x1ba178
 *   fpu: float literal 0xc0490fd0 at 0x1ba194
 *   fpu: float literal 0x40490fd0 at 0x1ba1ac
 *   fpu: float literal 0x40c90fd0 at 0x1ba1d8
 *   delay: addiu at 0x1ba1f4 writes a register its branch at 0x1ba1f0 reads
 *   stack: address of the slot at 0xb0 escapes at 0x1ba254
 *   fpu: float literal 0x3c23d70a at 0x1ba274
 *   fpu: mtc1 reinterprets v1 at 0x1ba280
 *   stack: address of the slot at 0xb8 escapes at 0x1ba2bc
 *   stack: address of the slot at 0xc0 escapes at 0x1ba2d8
 *   fpu: float literal 0x3c23d70a at 0x1ba2ec
 *   fpu: mtc1 reinterprets v1 at 0x1ba2fc
 *   fpu: mtc1 reinterprets v1 at 0x1ba324
 *   fpu: mtc1 reinterprets v1 at 0x1ba348
 *   stack: address of the slot at 0xc0 escapes at 0x1ba368
 *   stack: address of the slot at 0x22c escapes at 0x1ba380
 *   fpu: mtc1 reinterprets v0 at 0x1ba394
 *   fpu: mtc1 reinterprets v1 at 0x1ba3a8
 *   fpu: float literal 0x43000000 at 0x1ba3bc
 *   fpu: mtc1 reinterprets v0 at 0x1ba3dc
 *   fpu: mtc1 reinterprets v1 at 0x1ba3f0
 *   fpu: float literal 0x43000000 at 0x1ba404
 *   fpu: mtc1 reinterprets v0 at 0x1ba424
 *   fpu: mtc1 reinterprets v1 at 0x1ba438
 *   fpu: float literal 0x43000000 at 0x1ba450
 *   stack: address of the slot at 0x22f escapes at 0x1ba46c
 *   fpu: mtc1 reinterprets v0 at 0x1ba484
 *   fpu: mtc1 reinterprets v1 at 0x1ba498
 *   fpu: float literal 0x43000000 at 0x1ba4b0
 *   stack: address of the slot at 0xd0 escapes at 0x1ba4f0
 *   stack: address of the slot at 0xd0 escapes at 0x1ba508
 *   cfg: loop body is not one contiguous region: .L001B9B58
 *   cfg: kept branch: 0x1ba0e4 if (..) goto .L001BA108
 *   cfg: kept branch: 0x1ba144 if (..) goto .L001BA168
 *   cfg: kept branch: 0x1ba1a4 if (..) goto .L001BA1C8
 *   v0#10 is the pointer held in a0+0x48
 *   v0 is the pointer held in a0+0x4c
 *   declaration vs inferred signature: return void vs inferred u32
 */








#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif







#ifndef PROTO_DW_1898869_FIELDS
#define PROTO_DW_1898869_FIELDS

#endif
#ifndef PROTO_DW_1890401_FIELDS
#define PROTO_DW_1890401_FIELDS

#endif
#ifndef PROTO_DW_1890884_FIELDS
#define PROTO_DW_1890884_FIELDS

#endif
#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif
#ifndef PROTO_DW_1902102_FIELDS
#define PROTO_DW_1902102_FIELDS

#endif
#ifndef PROTO_DW_1892300_FIELDS
#define PROTO_DW_1892300_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_1__C6D2CBBE_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_1__C6D2CBBE_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_3__500368EC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_3__500368EC_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED
#define DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D_DEFINED

#endif
#define PTCL_RNDRANGE(dst, b, r) \
    if (0.0f < (r)) { \
        float rr_ = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32(); \
        (dst) = (b) + (r) * (rr_ - 0.5f); \
    } else { \
        (dst) = (b); \
    }



typedef struct AllocPtcl_Data { u8 pad[0xa8]; struct AllocPtcl_Data *next; } AllocPtcl_Data;
typedef struct AllocPtcl_Mng { u8 pad[0x30]; AllocPtcl_Data *free; u8 pad2[4]; s16 cnt; s16 max; } AllocPtcl_Mng;
#define ALLOCPTCL_MNGP ((AllocPtcl_Mng *)s_mngp)


/* PtclMng_Draw @ 0x1BA650 .. 0x1BA7CC (0x17c bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x30 escapes at 0x1ba764
 *   stack: address of the slot at 0x30 escapes at 0x1ba77c
 *   cfg: kept branch: 0x1ba690 if (..) goto .L001BA6C8
 *   cfg: kept branch: 0x1ba740 if (..) goto .L001BA7B8
 *   cfg: loop body is not one contiguous region: .L001BA758
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 SfxFog_CheckActive();
extern signed int SetDrawOTSprite(void *, float *, unsigned int);
static signed int _SfxFreeIndex(signed int index);

/* PtclMng_Action @ 0x1BA810 .. 0x1BA96C (0x15c bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1ba848 is a float copy
 *   delay: dsll32 at 0x1ba878 writes a register its branch at 0x1ba874 reads
 *   fpu: mov.s at 0x1ba8e8 is a float copy
 *   delay: addiu at 0x1ba908 writes a register its branch at 0x1ba904 reads
 *   cfg: loop body is not one contiguous region: .L001BA850
 */

static signed int _SfxFreeIndex(signed int);

/* _DeleteRelation @ 0x1BAAB0 .. 0x1BAB30 (0x80 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001BAAF0
 *   return without a value in a non-void function
 */

extern u32 s_mngp;

struct SfxFreeIdx_Ptcl {
    u8 ptclBody[0xa8];
    struct SfxFreeIdx_Ptcl *pNextPtcl;
    u8 *pPtclData;
    u8 ptclPadB0[0x30];
};

struct SfxFreeIdx_Sfx {
    u8 sfxBody[0x46];
    u8 nPtcl;
    u8 sfxPad47;
    struct SfxFreeIdx_Ptcl *pTopPtcl;
    u8 sfxPad4C[8];
    struct SfxFreeIdx_Sfx *pPrevSfx;
    struct SfxFreeIdx_Sfx *pNextSfx;
    u8 sfxPad5C[0x44];
};

struct SfxFreeIdx_Mng {
    s32 nMax;
    u32 *pIndexTbl;
    struct SfxFreeIdx_Sfx *pSfxTbl;
    u32 mngPadC;
    s32 **ppPtclType;
    u8 mngPad14[0x1c];
    struct SfxFreeIdx_Ptcl *pFreePtcl;
    u32 mngPad34;
    s16 nUsePtcl;
};

/* PtclMng_SfxCreate @ 0x1BAF50 .. 0x1BB59C (0x64c bytes, frame 0x170) */
/*
 * dcomp notes:
 *   literal: @3373 is the string 'PtclMng.c'
 *   literal: @8026 is the string 'thin out ptcl'
 *   stack: address of the slot at 0x70 escapes at 0x1baff4
 *   stack: address of the slot at 0x70 escapes at 0x1bb00c
 *   cfg: loop body is not one contiguous region: .L001BB038
 *   cfg: loop body is not one contiguous region: .L001BB0A0
 *   cfg: loop body is not one contiguous region: .L001BB188
 *   cfg: kept branch: 0x1bb188 if (..) goto .L001BB1A0
 *   cfg: kept goto: 0x1bb194 -> .L001BB1C0
 *   cfg: kept branch: 0x1bb33c if (..) goto .L001BB480
 *   cfg: kept branch: 0x1bb354 if (..) goto .L001BB480
 *   cfg: loop body is not one contiguous region: .L001BB4E0
 *   s1#1 is the pointer held in @52888+0x0
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




#ifndef PROTO_DW_1898869_FIELDS
#define PROTO_DW_1898869_FIELDS

#endif
#ifndef PROTO_DW_1890401_FIELDS
#define PROTO_DW_1890401_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PROG_NO_DE4355CC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PROG_NO_DE4355CC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PROG_NO_DE4355CC = (int)&(((struct dw_1890401_fields *)0)->prog_no) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A_DEFINED

#endif




#ifndef PROTO_DW_1916235_FIELDS
#define PROTO_DW_1916235_FIELDS

#endif
#ifndef PROTO_DW_1890884_FIELDS
#define PROTO_DW_1890884_FIELDS

#endif
#ifndef PROTO_DW_1891466_FIELDS
#define PROTO_DW_1891466_FIELDS

#endif
struct SfxCreate_Mng {
    s32 cMax;
    u32 *cIdxTbl;
    struct dw_1891466_fields *cSfxTbl;
    struct dw_1891466_fields **ppEmtrTbl;
    s32 **cPtclType;
    u8 pad14[4];
    u32 serial;
    u8 pad1c[8];
    s32 nProg;
    u8 pad28[8];
    struct dw_1890884_fields *cFreePtcl;
    u32 pad34;
    s16 cUsePtcl;
};
#define SFXC_MNG ((struct SfxCreate_Mng *)s_mngp)
#define SFXC_BF(p) ((struct { unsigned char f0:1; unsigned char f1:1; unsigned char f2:1; unsigned char f3:1; unsigned char st:4; } *)(p))
static inline s32 SfxCreate_CountPtcl(struct dw_1891466_fields *p) {
    s32 n = 0;
    if (p != 0 && p) {
        do {
            n += p->ptcl_num;
            p = p->p_relation_next;
        } while (p != 0);
    }
    return n;
}

static inline s32 SfxCreate_CountP(s32 n, struct dw_1891466_fields *p) {
    if (p != 0 && p) {
        do {
            n += p->ptcl_num;
            p = p->p_relation_next;
        } while (p != 0);
    }
    return n;
}

static inline s32 SfxCreate_FindFree(void) {
    s32 i = 0;
    u32 *tbl = SFXC_MNG->cIdxTbl;
    u32 *pt = tbl;
    while (i < SFXC_MNG->cMax) {
        if (*pt == 0) {
            return i;
        }
        i++;
        pt++;
    }
    return -1;
}

static inline s32 SfxCreate_Take(s32 i) {
    if (i < 0) {
        return -1;
    }
    ((struct { unsigned serial : 20; unsigned rest : 12; } *)&SFXC_MNG->cIdxTbl[i])->serial = SFXC_MNG->serial & 0xfffff;
    SFXC_MNG->cIdxTbl[i] = 1;
    return i;
}
void PtclMng_InitDebug(void *source, signed int models, signed int particles, signed int allocate, signed int mode);


extern void *MemAllocAlignReal(unsigned int, unsigned int, char *, char *);
extern signed int SFX_DataRemap(char *, void *, signed int);
extern int sprintf(char *, const char *, ...);
extern u32 SfxFIO_GetTextureFile_Data(void);
extern void *GetTexMngByName(void *, char *);


/* PtclMng_EnableMillorMode @ 0x1BB850 .. 0x1BB87C (0x2c bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */

static u8 s_mng[64];
static u8 s_aTexMng[0x400];
static u32 s_mngp;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void PtclMng_EnableMillorMode(signed int a0 );
void PtclMng_InitDebug(void *source, signed int models, signed int particles, signed int allocate, signed int mode);
signed int PtclMng_SfxCreate(void *a0 );
signed int PtclMng_SfxFreeAll(signed int a0 );
static signed int _SfxFreeIndex(signed int index);
signed int PtclMng_UpdateHandle(signed int a0 );
void PtclMng_DrawSinglePtcl(void *a0 );
static u32 _DeleteRelation(u8 *a0 );
void * PtclMng_SfxSeekFirst(void);
void * PtclMng_SfxSeekNext(void);
void PtclMng_Action(float f12 );
void PtclMng_DrawSingleEmitter(void *a0 );
void PtclMng_Draw(void *a0 );
static void * _AllocPtcl(signed int num);
void __SFX_InitDefault(void *a0 , void *a1 , void *a2 );
void __SFX_ActDefault(void *a0 , float f12 );
static void _SetMdlParamToMdlMng(void *a0 );
static void __SFX_EndPtclDefault(u16 *a0 , u8 *a1 , u32 *a2 );
signed int PtclMng_EnableDraw(signed int a0 , signed int a1 , unsigned short a2 );
signed int PtclMng_EnableAction(signed int a0 , signed int a1 , unsigned short a2 );
void __SFX_InitSprite(void *a0 , void *a1 , void *a2 );
void __SFX_ActSprite(void *a0 , float f12 );
static void __SFX_DrawSprite(void *a0 );
void __SFX_DrawPtclSprite(void *a0 );
void __SFX_InitSprite2(void *a0 , void *a1 , void *a2 );
void __SFX_ActSprite2(void *a0 , float f12 );
void __SFX_DrawSprite2(void *a0 );
void __SFX_DrawPtclSprite2(void *particle);
void __SFX_InitDistortion(void *a0 , void *a1 , void *a2 );
void __SFX_ActDistortion(void *a0 , float f12 );
static void __SFX_DrawDistortion(void *a0 );
static void __SFX_EndPtclDistortion(u16 *a0 , u8 *a1 , u32 *a2 );
static void __SFX_DrawPtclDistortion(void *a0 );
void __SFX_InitTracer(void *a0 , void *a1 , void *a2 );
void __SFX_ActTracer(void *a0 , float f12 );
static void __SFX_EndPtclTracer(u16 *a0 , u8 *a1 , u32 *a2 );
void __SFX_InitConnectedSprite(void *a0 , void *a1 , void *a2 );
void __SFX_ActConnectedSprite(void *a0 , float f12 );
static void __SFX_DrawConnectedSprite(void *a0 );
void __SFX_DrawPtclConnectedSprite(void *a0 );
static void __SFX_EndPtclConnectedSprite(u8 *a0 , u8 *a1 , u32 *a2 );
void __SFX_InitAnimSprite(void *a0 , void *a1 , void *a2 );
void __SFX_ActAnimSprite(void *a0 , float f12 );
static void __SFX_DrawAnimSprite(void *a0 );
void __SFX_DrawPtclAnimSprite(void *object);
void __SFX_InitAnimSprite2(void *a0 , void *a1 , void *a2 );
void __SFX_ActAnimSprite2(void *a0 , float f12 );
static void __SFX_DrawAnimSprite2(void *a0 );
void __SFX_DrawPtclAnimSprite2(void *object);
void __SFX_InitFireFly(void *a0 , void *a1 , void *a2 );
void __SFX_ActFireFly(void *a0 , float f12 );
static void __SFX_DrawFireFly(u8 *a0 , u8 *a1 , u32 *a2 );
static void __SFX_DrawPtclFireFly(void *a0 );
static void _SubFunc_Plume_Move(void *p_ptcl_v , float dt_ );
void __SFX_InitPlume(void *a0 , void *a1 , void *a2 );
void __SFX_ActPlume(void *a0 , float f12 );
static void __SFX_DrawPlume(u8 *a0 , u8 *a1 , u32 *a2 );
static void __SFX_DrawPtclPlume(u8 *a0 , u8 *a1 , u32 *a2 );
static void __SFX_EndPtclPlume(u16 *a0 , u8 *a1 , u32 *a2 );
void __SFX_InitModel2(void *a0 , void *a1 , void *a2 );
void __SFX_ActModel2(void *a0 , float f12 );
static void _Model2_SetMdlParamToMdlMng(void *pPtcl__);
static void __SFX_EndPtclModel2(u16 *a0 , u8 *a1 , u32 *a2 );


void PtclMng_EnableMillorMode(signed int a0 /* r4 */) {
    s32 a1;
    u32 v1;

    a1 = *(s8 *)(s_mng + 0x3c);
    v1 = (s8)a0;
    a0 = v1 & 1;
    v1 = -2;
    v1 = a1 & (u32)v1;
    s_mng[0x3c] = v1 | (u32)(a0);
    return;
}
void PtclMng_InitDebug(void *source, signed int models, signed int particles, signed int allocate, signed int mode)
{
    s32 current;
    s32 i;
    s32 next;
    u8 filename[32] __attribute__((aligned(16)));
    s_mngp = (u32)s_mng;
    if (allocate) memset((void *)s_mngp, 0, 64);
    *(u32 *)(s_mngp + 24) = 1;
    *(s32 *)s_mngp = models;
    if (allocate) *(u32 *)(s_mngp + 4) = (u32)MemAllocAlignReal(models * 4, 16, (char *)__FUNCTION__, (char *)"");
    memset((void *)*(u32 *)(s_mngp + 4), 0, models * 4);
    if (allocate) *(u32 *)(s_mngp + 8) = (u32)MemAllocAlignReal(models * 160, 16, (char *)__FUNCTION__, (char *)"");
    memset((void *)*(u32 *)(s_mngp + 8), 0, models * 160);
    if (allocate) *(u32 *)(s_mngp + 52) = (u32)MemAllocAlignReal(particles * 224, 16, (char *)__FUNCTION__, (char *)"");
    memset((void *)*(u32 *)(s_mngp + 52), 0, particles * 224);
    *(u16 *)(s_mngp + 56) = 0;
    *(u16 *)(s_mngp + 58) = particles;
    *(u32 *)(s_mngp + 48) = *(u32 *)(s_mngp + 52);
    current = *(s32 *)(s_mngp + 48);
    next = current + 224;
    for (i = 1; i < *(s16 *)(s_mngp + 58); i++) {
        *(s32 *)(current + 168) = next;
        current = next;
        next += 224;
    }
    *(u32 *)(current + 168) = 0;
    if (allocate) {
        *(u32 *)(s_mngp + 16) = (u32)MemAllocAlignReal(0x10000, 16, (char *)__FUNCTION__, (char *)"");
        memset((void *)*(u32 *)(s_mngp + 16), 0, 0x1000);
    }
    *(u32 *)(s_mngp + 20) = (u32)source;
    *(u32 *)(s_mngp + 36) = SFX_DataRemap((char *)*(u32 *)(s_mngp + 20), (void *)*(u32 *)(s_mngp + 16), mode);
    if (allocate) *(u32 *)(s_mngp + 12) = (u32)MemAllocAlignReal(0x1000, 16, (char *)__FUNCTION__, (char *)"");
    memset((void *)*(u32 *)(s_mngp + 12), 0, 0x1000);
    mode = (s32)s_aTexMng;
    for (allocate = 0; allocate < 255; allocate++) {
        sprintf((char *)filename, "sfxt%03d.tm2", allocate);
        *(u32 *)mode = (u32)GetTexMngByName((void *)SfxFIO_GetTextureFile_Data(), (char *)filename);
        mode += 4;
    }
}

signed int PtclMng_SfxCreate(void *a0 /* r4 */) {
    struct dw_1890401_fields *dsc = (struct dw_1890401_fields *)a0;
    s32 handle;
    struct dw_1891466_fields *p_sfx;
    struct dw_1891466_fields *p;
    s32 i;
    s32 prev_index;
    struct dw_1891466_fields *p_sfx_prev;

    if (SFXC_MNG->nProg < (s32)dsc->prog_no) {
        return -1;
    }
    if (SfxCreate_CountP(0, SFXC_MNG->ppEmtrTbl[dsc->prog_no]) + dsc->ptcl_num > 0x100) {
        s32 num;
        struct dw_1891466_fields *p_emtr;
        struct dw_1890884_fields *p_ptcl;
        struct dw_1890884_fields *p_ptcl_top;
        u8 szFile[256] __attribute__((aligned(16)));
        struct dw_1890884_fields *p_ptcl_del;

        p_ptcl_top = 0;
        strcpy((char *)szFile, (const char *)"PtclMng.c");
        SfxDbg_SetDebugMsg(0, (char *)"thin out ptcl", (char *)szFile, 0x1bf);
        p_emtr = SFXC_MNG->ppEmtrTbl[dsc->prog_no];
        if (p_emtr->ptcl_num == 0) {
            do {
                if (p_emtr == 0) {
                    break;
                }
                p_emtr = p_emtr->p_relation_next;
            } while (p_emtr->ptcl_num == 0);
        }
        p_ptcl = p_emtr->p_ptcl_top;
        {
            num = SfxCreate_CountP(0, SFXC_MNG->ppEmtrTbl[dsc->prog_no]) + dsc->ptcl_num - 0x100;
        }
        if (num != 0) {
            do {
                if (p_ptcl == 0) {
                    p_emtr->p_ptcl_top = 0;
                    p_emtr->ptcl_num = 0;
                    p_emtr = p_emtr->p_relation_next;
                    p_ptcl = p_emtr->p_ptcl_top;
                } else {
                    void (*func)(void *);
                    p_ptcl_del = p_ptcl;
                    p_ptcl = p_ptcl->p_sibling;
                    func = (void (*)(void *))((u32 *)((u8 *)s_FuncTable + *SFXC_MNG->cPtclType[p_ptcl_del->pEmitter->prog_no] * 0x14))[4];
                    if (func != 0) {
                        func(p_ptcl_del);
                    }
                    memset(p_ptcl_del, 0, 0xe0);
                    p_ptcl_top = p_ptcl;
                    num--;
                    p_ptcl_del->p_sibling = SFXC_MNG->cFreePtcl;
                    SFXC_MNG->cFreePtcl = p_ptcl_del;
                    SFXC_MNG->cUsePtcl--;
                    p_emtr->ptcl_num--;
                }
            } while (num != 0);
        }
        p_emtr->p_ptcl_top = p_ptcl_top;
    }
    i = SfxCreate_Take(SfxCreate_FindFree());
    if (i < 0) {
        return -1;
    }
    handle = ((SFXC_MNG->cIdxTbl[i] & 0xfffff) << 12) | (i & 0xfff);
    p_sfx = &SFXC_MNG->cSfxTbl[i];
    memset(p_sfx, 0, 0xa0);
    p_sfx->prog_no = dsc->prog_no;
    SFXC_BF((u8 *)p_sfx + 0x6c)->st = 1;
    SFXC_BF((u8 *)p_sfx + 0x6c)->f0 = SFXC_BF((u8 *)dsc + 0x7e)->f0;
    SFXC_BF((u8 *)p_sfx + 0x6c)->f1 = SFXC_BF((u8 *)dsc + 0x7e)->f1;
    SFXC_BF((u8 *)p_sfx + 0x6c)->f2 = SFXC_BF((u8 *)dsc + 0x7e)->f2;
    SFXC_BF((u8 *)p_sfx + 0x6c)->f3 = SFXC_BF((u8 *)dsc + 0x7e)->f3;
    p_sfx->sfx_sttdata_idx = dsc->sfx_sttdata_idx;
    if ((s32)p_sfx->prog_no <= SFXC_MNG->nProg) {
        s32 *ty = SFXC_MNG->cPtclType[p_sfx->prog_no];
        void (*init)(void *, void *, void *);
        if (ty == 0) {
            goto fail;
        }
        init = (void (*)(void *, void *, void *))*(s32 *)((u8 *)s_FuncTable + *ty * 0x14);
        if (init == 0) {
            goto fail;
        }
        init(p_sfx, dsc, ty);
        if (dsc->prev_ptcl != -1) {
            s32 rel = dsc->prev_ptcl;
            p_sfx_prev = &SFXC_MNG->cSfxTbl[rel & 0xfff];
            if (((((s32)rel) >> 12) & 0xfffff) == (SFXC_MNG->cIdxTbl[rel & 0xfff] & 0xfffff)) {
                while (p_sfx_prev->p_next != 0) {
                    p_sfx_prev = p_sfx_prev->p_next;
                }
                p_sfx_prev->p_next = p_sfx;
                p_sfx->p_prev = p_sfx_prev;
            }
        }
        p = (struct dw_1891466_fields *)&SFXC_MNG->ppEmtrTbl[p_sfx->prog_no];
        if (*(struct dw_1891466_fields **)p == 0) {
            *(struct dw_1891466_fields **)p = p_sfx;
            p_sfx->p_relation_prev = 0;
            p_sfx->p_relation_next = 0;
        } else {
            struct dw_1891466_fields *last = *(struct dw_1891466_fields **)p;
            while (last->p_relation_next != 0) {
                last = last->p_relation_next;
            }
            last->p_relation_next = p_sfx;
            p_sfx->p_relation_prev = last;
            p_sfx->p_relation_next = 0;
        }
        return handle;
    }
fail:
    if (handle != -1) {
      if (handle != -1) {
        p_sfx = &SFXC_MNG->cSfxTbl[handle & 0xfff];
        if (((((s32)handle) >> 12) & 0xfffff) == (SFXC_MNG->cIdxTbl[handle & 0xfff] & 0xfffff)) {
            p = p_sfx->p_next;
            if (p != 0) {
                do {
                    p_sfx_prev = p;
                    p = p->p_next;
                    if (p_sfx_prev != 0) {
                        prev_index = ((u32)p_sfx_prev - (u32)SFXC_MNG->cSfxTbl) / 0xa0;
                    } else {
                        prev_index = -1;
                    }
                } while (_SfxFreeIndex(prev_index) == 0 && p != 0);
            }
            if (p_sfx != 0) {
                prev_index = ((u32)p_sfx - (u32)SFXC_MNG->cSfxTbl) / 0xa0;
            } else {
                prev_index = -1;
            }
            _SfxFreeIndex(prev_index);
        }
    }
    }
    return -1;
}


/* PtclMng_SfxFreeAll @ 0x1BAE30 .. 0x1BAF4C (0x11c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001BAEA8
 *   declaration vs inferred signature: return signed int vs inferred void
 */

signed int PtclMng_SfxFreeAll(signed int a0 /* r4 */) {
    s32 a2;
    s32 a1;
    u64 v1_64;
    u32 v0;
    u8 *s1;
    u32 s0;

    v0 = -1;
    if ((u32)(s32)a0 == v0) {
        return v0;
    }
    a1 = (u32)(a0) & 0xfff;
    a2 = (u32)a1 << 2;
    a1 = (u32)a1 * (u32)(0xa0);
    v1_64 = (u32)((s32)a0 >> 0xc) & 0xfffff;
    a0 = *(s32 *)(((u8 *)(u32 *)s_mngp + 8));
    v0 = (u32)*(s32 *)(s32)(*(s32 *)(((u8 *)(u32 *)s_mngp + 4)) + a2) & 0xfffff;
    s1 = (u8 *)(s32)((a0) + a1);
    if (v1_64 != (u64)v0) {
        v0 = 0;
    } else {
        s0 = *(s32 *)(s1 + 0x58);
        if (s0 != 0) {
            do {
                a0 = s0;
                s0 = *(s32 *)((s0 + 0x58));
                if ((u32)(s32)a0 != 0) {
                    a0 = (u32)((u32)(a0) - *(s32 *)((s_mngp + 8))) / (u32)(0xa0);
                } else {
                    a0 = -1;
                }
                v0 = _SfxFreeIndex(a0);
            } while (v0 == 0 && s0);
        }
        a0 = -1;
        if ((u32)(s32)s1 != 0) {
            a0 = (u32)(s32)(s1 - *(s32 *)((s_mngp + 8))) / (u32)(0xa0);
        }
        v0 = _SfxFreeIndex(a0);
    }
    return v0;
}

static signed int _SfxFreeIndex(signed int index) {
    unsigned char i;
    struct SfxFreeIdx_Sfx *p_sfx;
    u32 *p_ss;
    struct SfxFreeIdx_Ptcl *p_ptcl;
    struct SfxFreeIdx_Ptcl *p_ptcl_del;

    if (index < 0 || index > (*(struct SfxFreeIdx_Mng **)&s_mngp)->nMax) {
        return -1;
    }
    p_sfx = &(*(struct SfxFreeIdx_Mng **)&s_mngp)->pSfxTbl[index];
    p_ss = &(*(struct SfxFreeIdx_Mng **)&s_mngp)->pIndexTbl[index];
    p_ptcl = p_sfx->pTopPtcl;
    for (i = 0; i < p_sfx->nPtcl && p_ptcl != 0; i++) {
        void (*func)(struct SfxFreeIdx_Ptcl *);
        p_ptcl_del = p_ptcl;
        p_ptcl = p_ptcl->pNextPtcl;
        func = (void (*)(struct SfxFreeIdx_Ptcl *))((u32 *)((u8 *)s_FuncTable + *(*(struct SfxFreeIdx_Mng **)&s_mngp)->ppPtclType[*(u16 *)(p_ptcl_del->pPtclData + 0x44)] * 0x14))[4];
        if (func != 0) {
            func(p_ptcl_del);
        }
        memset(p_ptcl_del, 0, 0xe0);
        p_ptcl_del->pNextPtcl = (*(struct SfxFreeIdx_Mng **)&s_mngp)->pFreePtcl;
        (*(struct SfxFreeIdx_Mng **)&s_mngp)->pFreePtcl = p_ptcl_del;
        (*(struct SfxFreeIdx_Mng **)&s_mngp)->nUsePtcl--;
    }
    if (p_sfx->pPrevSfx != 0) {
        p_sfx->pPrevSfx->pNextSfx = p_sfx->pNextSfx;
    }
    if (p_sfx->pNextSfx != 0) {
        p_sfx->pNextSfx->pPrevSfx = p_sfx->pPrevSfx;
    }
    memset(p_sfx, 0, 0xa0);
    *p_ss = 0;
    _DeleteRelation((u8 *)p_sfx);
    return 0;
}

/* PtclMng_UpdateHandle @ 0x1BABA0 .. 0x1BAC98 (0xf8 bytes) */
/*
 * dcomp notes:
 *   cfg: loop leaves to a block that is not its join: 0x1bac00 -> 0x1bac08
 *   cfg: kept branch: 0x1bac18 if (..) goto .L001BAC00
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int PtclMng_UpdateHandle(signed int a0 /* r4 */) {
    int a2;
    int t0;
    u8 *a3;
    int a1;
    int v1;
    int v0;

    v1 = (s32)a0 >> 0xc;
    v0 = -1;
    a2 = (u32)(a0) & 0xfff;
    t0 = v1 & 0xfffff;
    if ((u32)(s32)a0 == v0) {
        return v0;
    }
    a1 = s_mngp;
    a0 = a2 << 2;
    v1 = a2 * (u32)(0xa0);
    a2 = *(s32 *)((a1 + 8));
    a1 = *(s32 *)((a1 + 4));
    a3 = (u8 *)(s32)(a2 + v1);
    v1 = (u32)*(s32 *)(s32)(a1 + (u32)(a0)) & 0xfffff;
    if (t0 != v1) {
        return v0;
        _L001BAC00:;
        a3 = (u8 *)*(s32 *)(a3 + 0x58);
        if ((u32)(s32)a3 == 0) {
            v0 = -1;
            return v0;
        }
    }
    v0 = *(s32 *)(a3 + 0x64);
    if (v0 == 0) {
        goto _L001BAC00;
    }
    if ((u32)(s32)a3 == 0) {
        v0 = -1;
    } else {
        v0 = (u32)(s32)(a3 - a2) / (u32)(0xa0);
        v1 = a1 + (s32)(v0 << 2);
        v0 = v0 & 0xfff;
        v1 = *(s32 *)v1;
        v1 = v1 & 0xfffff;
        v1 = v1 << 0xc;
        v0 = v1 | (u32)v0;
    }
    v1 = -1;
    if (v0 == v1) {
        v0 = v1;
        return v0;
    }
    return v0;
}

/* PtclMng_DrawSinglePtcl @ 0x1BAB30 .. 0x1BAB94 (0x64 bytes, frame 0x10) */

void PtclMng_DrawSinglePtcl(void *a0 /* r4 */) {
    u32 v1;

    v1 = *(s32 *)(s32)((u8 *)(u8 *)(s_FuncTable + 3) + (u32)((u32)*(s32 *)*(s32 *)(s32)(*(s32
        *)((s_mngp + 0x10)) + (u32)((u32)*(u16 *)((*(s32 *)(((u8 *)a0 + 0xac)) + 0x44)) << 2)) *
        (u32)(0x14)));
    if (v1 != 0) {
        ((void (*)(void *))(s32)v1)(a0);
    }
    return;
}

static u32 _DeleteRelation(u8 *a0 /* r4 */) {
    u32 v1;
    u32 a1;
    u32 *a2;

    v1 = s_mngp;
    a1 = *(u16 *)(((u8 *)a0 + 0x44));
    v1 = *(u32 *)((v1 + 0xc));
    a1 = (u32)a1 << 2;
    v1 = v1 + a1;
    a2 = (u32 *)*(u32 *)v1;
    if ((u32)(a2) != 0) {
        if ((u32)(a2) == (u32)(a0)) {
            *(u32 *)v1 = 0;
        } else {
            v1 = *(u32 *)(((u8 *)a2 + 0x60));
            if (v1 != (u32)(a0)) {
                do {
                    a2 = (u32 *)v1;
                    if (v1 == 0) {
                        break;
                    }
                    v1 = *(u32 *)((v1 + 0x60));
                } while (v1 != (u32)(a0));
            }
            a1 = *(u32 *)(((u8 *)a0 + 0x60));
            if ((u32)(a2) != 0) {
                *(u32 *)(((u8 *)a2 + 0x60)) = a1;
            }
            if (a1 != 0) {
                v1 = *(u32 *)(((u8 *)a0 + 0x5c));
                *(u32 *)((a1 + 0x5c)) = v1;
            }
        }
    }
    return;
}


/* PtclMng_SfxSeekFirst @ 0x1BAA30 .. 0x1BAAB0 (0x80 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001BAA48
 */

void * PtclMng_SfxSeekFirst(void) {
    s32 a2;
    u32 a1;
    u32 *a0;
    u32 v1;
    u32 v0;

    v1 = s_mngp;
    a1 = *(s32 *)v1;
    a2 = 0;
    if (0 < (s32)a1) {
        a0 = (u32 *)*(s32 *)((v1 + 4));
        do {
            if ((u32)*(s32 *)a0 != 0) {
                break;
            }
            a2 = a2 + 1;
            v0 = a2 < (s32)a1;
            a0 = (u32 *)(u8 *)(a0 + 1);
        } while (v0 != 0);
    }
    a2 = (u32)a2 == a1 ? (s32)-1 : a2;
    *(u32 *)((v1 + 0x1c)) = a2;
    if (0 <= a2) {
        return (void *)(u32)(*(s32 *)(((u8 *)s_mngp + 8)) + (a2 * 0xa0));
    } else {
        return (void *)(u32)0;
    }
}

void * PtclMng_SfxSeekNext(void) {
    s32 i;
    s32 num;
    s32 *pIdx;

    pIdx = (s32 *)(s_mngp + 0x1c);
    if (*pIdx < 0) {
        return 0;
    }
    num = *(s32 *)s_mngp;
    if (num <= *pIdx) {
        return 0;
    }
    for (i = *pIdx + 1; i < num; i++) {
        if (((s32 *)*(s32 *)(s_mngp + 4))[i] != 0) {
            break;
        }
    }
    *pIdx = i = (i == num) ? -1 : i;
    if (0 <= i) {
        return (void *)(*(s32 *)(s_mngp + 8) + i * 0xa0);
    }
    return 0;
}

void PtclMng_Action(float f12 /* f12 */) {
    u8 *s3;
    s32 s2;
    u32 a1;
    u32 a0;
    s32 s1;
    float f20;
    s32 s0;
    u32 v1;

    s2 = 0;
    s1 = 0;
    a1 = s_mngp;
    v1 = *(s32 *)a1;
    s3 = (u8 *)*(s32 *)((a1 + 8));
    f20 = f12;
    if (0 < (s32)v1) {
        s0 = 0;
        do {
            v1 = 1;
            a0 = *(s32 *)(s32)(*(s32 *)((a1 + 4)) + s0);
            if (a0 == v1) {
                a0 = *(u8 *)(s3 + 0x6c);
                if ((u64)((u64)((u64)a0 << 0x3d) >> 0x3f) == 0) {
                    if ((u64)((u64)((u64)a0 << 0x3c) >> 0x3f) == 0) {
                        v1 = *(s32 *)(s3 + 0x64);
                        a0 = s2;
                        if (v1 == 0) {
                            _SfxFreeIndex(a0);
                        } else {
                            v1 = (u32)s_FuncTable;
                            a1 = *(s32 *)*(s32 *)(s32)(*(s32 *)((a1 + 0x10)) + (u32)((u32)*(u16
                                *)(s3 + 0x44) << 2));
                            v1 = *(s32 *)(((s32)((u8 *)s_FuncTable + (u32)(a1 * (u32)(0x14))) + 4));
                            if (v1 != 0) {
                                ((void (*)(s32, s32, float))(s32)v1)((s32)s3, a1, (float)f20);
                                *(u32 *)(s3 + 0x68) += 1;
                            }
                            if ((u32)*(s32 *)(s3 + 0x64) != (u32)0x7fffffff) {
                                *(u32 *)(s3 + 0x64) += -1;
                            }
                            s1 = s1 + 1;
                        }
                    }
                }
            }
            a1 = s_mngp;
            s2 = s2 + 1;
            s0 = s0 + 4;
            v1 = s2 < (s32)*(s32 *)a1;
            s3 = (u8 *)(s3 + 0xa0);
        } while (v1 != 0);
    }
    *(u32 *)((a1 + 0x20)) = s1;
    *(u32 *)(((u32)s_mngp + 0x18)) = *(s32 *)(((u32)s_mngp + 0x18)) + 1;
    return;
}


/* PtclMng_DrawSingleEmitter @ 0x1BA7D0 .. 0x1BA810 (0x40 bytes) */
/*
 * dcomp notes:
 *   tail: jr v0 at 0x1ba808 tail-calls through a pointer
 */

void PtclMng_DrawSingleEmitter(void *a0 /* r4 */) {
    u32 a1;

    a1 = *(s32 *)*(s32 *)(s32)(*(s32 *)((s_mngp + 0x10)) + (u32)((u32)*(u16 *)(((u8 *)a0 + 0x44))
        << 2));
    ((void (*)(void *, s32))(s32)*(s32 *)(s32)((u8 *)(u8 *)(s_FuncTable + 2) + (u32)(a1 *
        (u32)(0x14))))(a0, a1);
    return;
}

void PtclMng_Draw(void *a0 /* r4 */) {
    u32 a3;
    u8 *s1;
    u8 *s0;
    u32 a2;
    u32 a1;
    u32 fg;
    u32 v1;
    u32 v0;
    u32 fl;
    s32 id;
    float pos[4] __attribute__((aligned(16)));

    s0 = (u8 *)a0;
    v1 = s_mngp;
    a0 = (void *)*(u16 *)(((u8 *)a0 + 0x44));
    a0 = (void *)(s32)((u32)a0 << 2);
    v1 = *(s32 *)(u32)(s32)((u8 *)(u32)*(s32 *)((v1 + 0x10)) + (u32)(a0));
    a1 = *(s32 *)v1;
    if ((u32)s0 != 0) {
        fl = *(u8 *)(s0 + 0x6c);
        v1 = fl & 1;
        if (v1 == 0) {
            if (((struct { unsigned char f0:1; unsigned char f1:1; unsigned char _p:6; } *)(s0 + 0x6c))->f1 == 0 && (u32)*(s32 *)(s32)((u8 *)(u8
                *)(s_FuncTable + 2) + (s32)((u32)((s32)(a1 << 2) + a1) << 2)) != 0) {
                goto _L001BA6C8;
            }
        }
        return;
        _L001BA6C8:;
        v0 = SfxFog_CheckActive();
        if (v0 != 0) {
            id = *(u16 *)(s0 + 0x44);
            a3 = 1;
            fg = 0;
            v1 = id < 0x60;
            a2 = a3;
            if (v1 == 0 && id <= 0x64) {
                fg = a3;
            }
            v1 = id < 0x54;
            if (fg == 0) {
                v1 = v1 ^ 1;
                if (v1 != 0) {
                    v1 = id < 0x5a;
                }
                if (v1 == 0) {
                    a2 = 0;
                }
            }
            v1 = 0x85;
            if (a2 == 0 && id != v1) {
                a3 = 0;
            }
            if (a3 != 0) {
                goto _L001BA7B8;
            }
        }
        s1 = (u8 *)*(s32 *)(s0 + 0x48);
        if ((u32)(s32)s1 != 0) {
            do {
                a1 = *(s32 *)(s0 + 0x40);
                if (a1 != 0) {
                    sceVu0ApplyMatrix((void *)((u8 *)&pos[0]), (void *)a1, (void *)(s1 + 0x40));
                    a0 = (void *)s1;
                    a2 = ((struct { unsigned char _pad:4; unsigned char f:4; } *)&*(u8 *)(s0 +
                        0x6c))->f;
                    SetDrawOTSprite(a0, (float *)((u8 *)&pos[0]), a2);
                } else {
                    a0 = (void *)s1;
                    a2 = ((struct { unsigned char _pad:4; unsigned char f:4; } *)&*(u8 *)(s0 +
                        0x6c))->f;
                    SetDrawOTSprite(a0, (float *)(s1 + 0x40), a2);
                }
                s1 = (u8 *)*(s32 *)(s1 + 0xa8);
            } while ((u32)(s32)s1 != 0);
        }
    }
    _L001BA7B8:;
    return;
}

static void * _AllocPtcl(signed int num) {
    AllocPtcl_Data *p_data;
    AllocPtcl_Data *p_head;
    int i;
    AllocPtcl_Data *p_alloc;

    if (ALLOCPTCL_MNGP->max <= ALLOCPTCL_MNGP->cnt) {
        return 0;
    }
    if (num <= 0) {
        return 0;
    }
    p_head = p_data = ALLOCPTCL_MNGP->free;
    if (p_data != 0) {
        ALLOCPTCL_MNGP->cnt++;
        ALLOCPTCL_MNGP->free = ALLOCPTCL_MNGP->free->next;
        p_data->next = 0;
        for (i = 1; i < num; i++) {
            p_alloc = ALLOCPTCL_MNGP->free;
            if (p_alloc == 0) {
                break;
            }
            ALLOCPTCL_MNGP->cnt++;
            ALLOCPTCL_MNGP->free = ALLOCPTCL_MNGP->free->next;
            p_data->next = p_alloc;
            p_alloc->next = 0;
            p_data = p_alloc;
        }
    }
    return p_head;
}

void __SFX_InitDefault(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    u8 *s5;
    u8 *s4;
    u32 t0;
    float f12;
    u32 a3;
    u8 *s3;
    u8 *s2;
    u8 s1;
    u8 *s0;
    float f4;
    float f2;
    float f1;
    float f22;
    float f21;
    float f20;
    float f0;
    float *s7;
    u32 v1;
    u8 *s6;
    u32 v0;
    void *a0_2;
    void *a1_2;
    void *a2_2;
    u8 col[4];
    float spdz;
    float py;
    float yaw;
    float r;

    s5 = (u8 *)a0;
    s4 = (u8 *)a1;
    v0 = *(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571) = v0;
    v0 = *(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20) = v0;
    sceVu0UnitMatrix(a0);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7) = *(float *)(s4 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9) = *(float *)(s4 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0) = *(float *)(s4 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2);
    dcomp_cop2_9397A3F6B7((void *)((u8 *)s5), (void *)((u8 *)s5), (void *)((u8 *)s4));
    a0_2 = (void *)(s5 + 0x30);
    a1_2 = (void *)(s4 + 0x40);
    sceVu0CopyVector(a0_2, a1_2);
    v0 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24);
    if (v0 != 0) {
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) = v0;
    } else {
        v0 = (u32)MRX1;
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) = (u32)MRX1;
    }
    s3 = (u8 *)*(s32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571);
    v1 = *(s16 *)(s3 + 2);
    if ((s32)v1 < 0) {
        v0 = 0x7fffffff;
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD) = 0x7fffffff;
    } else {
        v0 = *(u16 *)(s3 + 4);
        v0 = v1 + (u32)v0;
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD) = v0;
    }
    a0_2 = (void *)*(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
    v0 = (u32)_AllocPtcl((signed int)a0_2);
    *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087) = v0;
    v1 = *(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
    s2 = (u8 *)*(s32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    s1 = 0;
    if (0 < (s32)v1) {
        do {
            if ((u32)(s32)s2 == 0) {
                break;
            }
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510) = (u32)s5;
            v0 = *(s16 *)(s3 + 2);
            if ((s32)v0 < 0) {
                v0 = 0x7fffffff;
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = 0x7fffffff;
            } else {
                r = (float)(u16)SfxCalc_RandU32() * 1.5259022e-05f;
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = (u32)((float)*(s16 *)(s3 + 2) + (float)*(u16 *)(s3 + 4) * (r - 0.5f));
            }
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F) = (s32)(100.0f * (r - 0.5f));
            {
                float spd[4] __attribute__((aligned(16))) = {0};
                float mRot[4][4] __attribute__((aligned(16)));
                PTCL_RNDRANGE(spdz, *(float *)(s3 + 0x14), *(float *)(s3 + 0x18));
                spd[2] = spdz;
                PTCL_RNDRANGE(f21, *(float *)(s3 + 0x1c), *(float *)(s3 + 0x20));
                PTCL_RNDRANGE(f20, *(float *)(s3 + 0x24), *(float *)(s3 + 0x28));
                PTCL_RNDRANGE(py, *(float *)(s3 + 0x2c), *(float *)(s3 + 0x30));
                f22 = (0.01745f * py);
                f20 = (0.01745f * (float)f20);
                f21 = (0.01745f * (float)f21);
                SfxCalc_MakeMatrixFromPYR((void *)mRot, f21, f20, f22);
                sceVu0ApplyMatrix((void *)(s2 + 0x80), (void *)mRot, (void *)spd);
            }
            *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C) = f21;
            *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_1__C6D2CBBE) = f20;
            *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE) = f22;
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_3__500368EC) = 0x3f800000;
            f12 = *(float *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C);
            f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
            *(f32 *)(s2 + 0x50) = f12;
            f12 = *(float *)(s2 + 0x54);
            f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
            *(f32 *)(s2 + 0x54) = f12;
            f12 = *(float *)(s2 + 0x58);
            f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
            *(f32 *)(s2 + 0x58) = f12;
            {
            u8 szFile[256] __attribute__((aligned(16)));
            float scl[8] __attribute__((aligned(16)));
            v0 = 2;
            v1 = *(u8 *)(s3 + 0x40);
            switch (v1) {
            case 0:
                break;
            case 1:
            case 2:
                *(u32 *)(s2 + 0x50) = 0;
                *(u32 *)(s2 + 0x54) = 0;
                v0 = 0x3f800000;
                *(u32 *)(s2 + 0x58) = 0;
                *(u32 *)(s2 + 0x5c) = 0x3f800000;
                break;
            default:
                break;
            }
            a1_2 = (void *)*(u16 *)(s3 + 6);
            a0_2 = (void *)(s2 + 0x40);
            SfxUtil_CalcRndPos((float *)a0_2, (signed int)a1_2, (float *)(s3 + 8));
            s0 = (u8 *)*(s32 *)(s2 + 0xac);
            t0 = *(s32 *)(s2 + 0xa4);
            a1_2 = (void *)(s32)6;
            v0 = *(s32 *)(s0 + 0x50);
            s6 = (u8 *)*(s32 *)(s0 + 0x4c);
            a3 = *(s32 *)((v0 + 0x1c));
            a2_2 = (void *)(s32)2;
            SFX_GetSeqParam((void *)&scl[0], (signed int)a1_2, (signed int)a2_2,
                (void *)a3, t0);
            v0 = *(u8 *)(s6 + 0x41);
            if (v0 != 0) {
                v1 = *(s8 *)(s2 + 0x9c);
                f0 = (scl[0] + (scl[1] * (0.01f *
                    (float)((float)(s32)v1))));
                *(f32 *)(s2 + 0x68) = f0;
                *(f32 *)(s2 + 0x64) = f0;
                *(f32 *)(s2 + 0x60) = f0;
            } else {
                v0 = *(s32 *)(s0 + 0x50);
                t0 = *(s32 *)(s2 + 0xa4);
                a1_2 = (void *)(s32)6;
                a3 = *(s32 *)((v0 + 0x24));
                SFX_GetSeqParam((void *)&scl[2], (signed int)a1_2, 2, (void *)a3, t0);
                v0 = *(s32 *)(s0 + 0x50);
                t0 = *(s32 *)(s2 + 0xa4);
                a1_2 = (void *)(s32)6;
                a3 = *(s32 *)((v0 + 0x2c));
                a2_2 = (void *)(s32)2;
                SFX_GetSeqParam((void *)&scl[4], (signed int)a1_2, (signed
                    int)a2_2, (void *)a3, t0);
                v1 = *(s8 *)(s2 + 0x9c);
                *(f32 *)(s2 + 0x60) = (scl[0] + (scl[1] *
                    (0.01f * (float)((float)(s32)v1))));
                v1 = *(s8 *)(s2 + 0x9d);
                
                *(f32 *)(s2 + 0x64) = (scl[2] + (scl[3] * (0.01f *
                    (float)((float)(s32)v1))));
                v1 = *(s8 *)(s2 + 0x9e);
                
                *(f32 *)(s2 + 0x68) = (scl[4] + (scl[5] * (0.01f * (float)((float)(s32)v1))));
            }
        
            s0 = (u8 *)*(s32 *)(s2 + 0xac);
            t0 = *(s32 *)(s2 + 0xa4);
            a1_2 = (void *)(s32)1;
            v0 = *(s32 *)(s0 + 0x50);
            a3 = *(s32 *)((v0 + 0x34));
            SFX_GetSeqParam((void *)&col[0], (signed int)a1_2, 3, (void *)a3, t0);
            f0 = ((float)(float)(u32)col[0] / 128.0f);
            *(f32 *)(s2 + 0x70) = f0;
            f0 = ((float)(float)(u32)col[1] / 128.0f);
            *(f32 *)(s2 + 0x74) = f0;
            a1_2 = (void *)(s32)1;
            f0 = ((float)(float)(u32)col[2] / 128.0f);
            *(f32 *)(s2 + 0x78) = f0;
            v0 = *(s32 *)(s0 + 0x50);
            t0 = *(s32 *)(s2 + 0xa4);
            a3 = *(s32 *)((v0 + 0x3c));
            a2_2 = (void *)a1_2;
            SFX_GetSeqParam((void *)&col[3], (signed int)a1_2, (signed int)a2_2,
                (void *)a3, t0);
            f0 = ((float)(float)(u32)col[3] / 128.0f);
            *(f32 *)(s2 + 0x7c) = f0;
            s0 = (u8 *)(s2 + 0xb0);
            a0_2 = (void *)*(u16 *)(s5 + 0x6e);
            v0 = SFX_ConfirmReflect(a0_2, 0);
            a0_2 = (void *)*(u16 *)s3;
            a1_2 = (void *)v0;
            *(u16 *)(s0 + 4) = SfxMdl_Alloc((unsigned short)a0_2, (signed int)a1_2);
            v1 = *(u16 *)(s0 + 4);
            v0 = 0xffff;
            if (v1 == v0) {
                a1_2 = (void *)(char *)"PtclMng.c";
                strcpy((char *)szFile, (const char *)(char *)"PtclMng.c");
                a1_2 = (void *)(char *)"\x33\x44\xd3\xc3\xde\xd9\x8a\x84\x82\xe8\x93\x96\x82\xc4\x8e\xb8\x94\x73";
                SfxDbg_SetDebugMsg(0,
                    (char *)"\x33\x44\xd3\xc3\xde\xd9\x8a\x84\x82\xe8\x93\x96\x82\xc4\x8e\xb8\x94\x73", (char *)szFile, 0x5ae);
            }
            a0_2 = (void *)*(u16 *)(s0 + 4);
            SfxMdl_SetZOffset((unsigned short)a0_2, *(float *)(s3 + 0x44));
            v1 = *(u8 *)(s5 + 0x6c);
            v1 = v1 & 1;
            a0_2 = (void *)s2;
            if (v1 == 0) {
                _SetMdlParamToMdlMng(a0_2);
            }
            }
            s2 = (u8 *)*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76);
            s1 += 1;
        } while ((s32)s1 < (s32)*(u16 *)(s4 + 0x7a));
    }
    *(u8 *)(s5 + 0x46) = s1;
    return;
}
void __SFX_ActDefault(void *a0 /* r4 */, float f12 /* f12 */) {
    u8 *s3;
    u32 t0;
    u8 *s2;
    u8 s5;
    u32 *s6;
    u8 *s1;
    u8 *s7;
    float f20;
    u8 *fp;
    u32 a3;
    u8 *s0;
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f2;
    float f1;
    float f0;
    float f3;
    u8 *s4;
    u8 *a0_2;
    float gravity;
    u8 col[4];
    float vec_gravity[4] __attribute__((aligned(16)));
    u8 szFile[256] __attribute__((aligned(16)));
    float vAdd[4] __attribute__((aligned(16)));
    float tmp_vector[4] __attribute__((aligned(16)));
    u8 mrx[64] __attribute__((aligned(16)));
    float vt[4] __attribute__((aligned(16)));
    float scl[6] __attribute__((aligned(16)));
    u32 calc_gravity;
    s32 life_cnt;
    u8 *p_fix2;
    void *pMrx1;
    void *pm;
    float ang[3] __attribute__((aligned(8)));

    fp = (u8 *)0;
    s7 = (u8 *)0;
    s6 = (u32 *)0;
    s5 = 0;
    s3 = (u8 *)a0;
    s2 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571);
    f20 = (float)f12;
    s1 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    calc_gravity = 0;
    pMrx1 = (void *)MRX1;
    goto _L001B9990;
    _L001B8FB8:;
    life_cnt = *(s32 *)(s1 + 0xa4);
    v0 = *(s32 *)(s1 + 0xa0);
    s0 = (u8 *)(s1 + 0xb0);
    if (v0 == 0) {
        s0 = (u8 *)s1;
        if ((u32)s7 != 0) {
            v0 = *(s32 *)(s1 + 0xa8);
            *(u32 *)(s7 + 0xa8) = v0;
        }
        a0_2 = (u8 *)*(s32 *)(s0 + 0xac);
        v1 = s_mngp;
        v0 = (u32)s_FuncTable;
        a0_2 = (u8 *)*(u16 *)(a0_2 + 0x44);
        a0_2 = (u8 *)(s32)((u32)a0_2 << 2);
        v1 = *(s32 *)(u32)(s32)((u8 *)(u32)*(s32 *)((v1 + 0x10)) + (u32)(a0_2));
        a0_2 = (u8 *)*(s32 *)v1;
        v0 = (s32)((u8 *)s_FuncTable + (s32)((u32)((u32)(a0_2)) * (u32)(0x14)));
        v0 = *(s32 *)((v0 + 0x10));
        s1 = (u8 *)*(s32 *)(s1 + 0xa8);
        if (v0 != 0) {
            a0_2 = (u8 *)s0;
            ((void (*)(s32))(s32)v0)((s32)a0_2);
        }
        a0_2 = (u8 *)s0;
        a2 = 0xe0;
        memset((void *)a0_2, 0, a2);
        v1 = *(s32 *)((s_mngp + 0x30));
        *(u32 *)(s0 + 0xa8) = v1;
        v1 = s_mngp;
        *(u32 *)((v1 + 0x30)) = (s32)s0;
        a0_2 = (u8 *)s_mngp;
        v1 = *(s16 *)(a0_2 + 0x38);
        v1 = v1 + -1;
        *(u16 *)(a0_2 + 0x38) = v1;
    } else {
        if ((u32)fp == 0) {
            fp = (u8 *)s1;
        }
        v1 = *(u8 *)(s2 + 0x40);
        v0 = 2;
        s7 = (u8 *)s1;
        s6 = (u32 *)((u8 *)s6 + 1);
        switch (v1) {
        case 0:
        case 1:
            v0 = *(s32 *)(s3 + 0x50);
            t0 = life_cnt;
            a3 = *(s32 *)((v0 + 0x14));
            a2 = 3;
            SFX_GetSeqParam((void *)ang, 6, a2, (void *)a3, t0);
            *(f32 *)(s1 + 0x54) = (*(float *)(s1 + 0x54) + (0.01745f * *(volatile float *)&ang[1]));
            f12 = *(float *)(s1 + 0x50);
            f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
            *(f32 *)(s1 + 0x50) = f12;
            f12 = *(float *)(s1 + 0x54);
            f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
            *(f32 *)(s1 + 0x54) = f12;
            f12 = *(float *)(s1 + 0x58);
            f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
            *(f32 *)(s1 + 0x58) = f12;
            break;
        case 2:
            a0_2 = (u8 *)(s1 + 0x50);
            a1 = (u32)V0;
            sceVu0CopyVector((void *)a0_2, (void *)V0);
            break;
        default:
            a1 = (u32)(char *)"PtclMng.c";
            strcpy((char *)szFile, (const char *)(char *)"PtclMng.c");
            a1 = (u32)(char *)"Invalid angle control type";
            SfxDbg_SetDebugMsg(0, (char *)"Invalid angle control type", (char *)szFile,
                0x610);
        }
        s4 = (u8 *)*(s32 *)(s1 + 0xac);
        t0 = *(s32 *)(s1 + 0xa4);
        a1 = 6;
        v0 = *(s32 *)(s4 + 0x4c);
        p_fix2 = (u8 *)v0;
        v0 = *(s32 *)(s4 + 0x50);
        a3 = *(s32 *)((v0 + 0x1c));
        SFX_GetSeqParam((void *)&scl[0], a1, 2, (void *)a3, t0);
        v0 = *(u8 *)(p_fix2 + 0x41);
        if (v0 != 0) {
            f0 = (scl[0] + (scl[1] * (0.01f * (float)*(s8 *)(s1 + 0x9c))));
            *(f32 *)(s1 + 0x68) = f0;
            *(f32 *)(s1 + 0x64) = f0;
            *(f32 *)(s1 + 0x60) = f0;
        } else {
            v0 = *(s32 *)(s4 + 0x50);
            t0 = *(s32 *)(s1 + 0xa4);
            a1 = 6;
            a3 = *(s32 *)((v0 + 0x24));
            SFX_GetSeqParam((void *)&scl[2], a1, 2, (void *)a3, t0);
            v0 = *(s32 *)(s4 + 0x50);
            t0 = *(s32 *)(s1 + 0xa4);
            a1 = 6;
            a3 = *(s32 *)((v0 + 0x2c));
            SFX_GetSeqParam((void *)&scl[4], a1, 2, (void *)a3, t0);
            *(f32 *)(s1 + 0x60) = (scl[0] + (scl[1] * (0.01f * (float)*(s8 *)(s1 + 0x9c))));
            *(f32 *)(s1 + 0x64) = (scl[2] + (scl[3] * (0.01f * (float)*(s8 *)(s1 + 0x9d))));
            *(f32 *)(s1 + 0x68) = (scl[4] + (scl[5] * (0.01f * (float)*(s8 *)(s1 + 0x9e))));
        }
        sceVu0ScaleVector((void *)vAdd, (void *)(s1 + 0x80), (float)f20);
        a0_2 = (u8 *)(s1 + 0x40);
        sceVu0AddVector((void *)a0_2, (void *)a0_2, (void *)vAdd);
        v0 = *(s32 *)(s3 + 0x50);
        t0 = life_cnt;
        a1 = 6;
        a3 = *(s32 *)((v0 + 0xc));
        SFX_GetSeqParam((void *)&gravity, a1, 1, (void *)a3, t0);
        f0 = gravity;
        if (!(0.0f == f0)) {
            if (calc_gravity == 0) {
                a1 = *(s32 *)(s3 + 0x40);
                fsvu0_MulMatrix((void *)mrx, (void *)a1, (void *)s3);
                SfxCalc_Vector2Angle((float *)tmp_vector, (float *)(mrx + 0x8));
                f0 = tmp_vector[1];
                sceVu0RotMatrixY((void *)mrx, pMrx1, (-f0));
                f0 = tmp_vector[0];
                sceVu0RotMatrixX((void *)mrx, (void *)mrx, (-f0));
                dcomp_cop2_21F95D43C1((void *)vec_gravity, (void *)mrx, (void *)VY);
                calc_gravity = 1;
            }
            f0 = gravity;
            sceVu0ScaleVector((void *)vt, (void *)vec_gravity,
                (f0 * f20));
            a0_2 = (u8 *)(s1 + 0x80);
            sceVu0AddVector((void *)a0_2, (void *)vt, (void *)a0_2);
        }
        s4 = (u8 *)*(s32 *)(s1 + 0xac);
        t0 = *(s32 *)(s1 + 0xa4);
        a1 = 1;
        v0 = *(s32 *)(s4 + 0x50);
        a3 = *(s32 *)((v0 + 0x34));
        a2 = 3;
        SFX_GetSeqParam((void *)&col[0], a1, a2, (void *)a3, t0);
        f0 = ((float)(float)(u32)col[0] / 128.0f);
        *(f32 *)(s1 + 0x70) = f0;
        f0 = ((float)(float)(u32)col[1] / 128.0f);
        *(f32 *)(s1 + 0x74) = f0;
        a1 = 1;
        f0 = ((float)(float)(u32)col[2] / 128.0f);
        *(f32 *)(s1 + 0x78) = f0;
        v0 = *(s32 *)(s4 + 0x50);
        t0 = *(s32 *)(s1 + 0xa4);
        a3 = *(s32 *)((v0 + 0x3c));
        SFX_GetSeqParam((void *)&col[3], a1, a1, (void *)a3, t0);
        f1 = (float)(u32)col[3];
        v0 = 1;
        *(f32 *)(s1 + 0x7c) = (f1 / 128.0f);
        v1 = *(u8 *)(s2 + 0x37);
        switch (v1) {
        case 0: {
            u32 fcnt;
            float fu;
            float one;
            u32 tw;
            u32 th;
            s32 idx;
            fcnt = *(u32 *)s0;
            tw = *(u8 *)(s2 + 0x35);
            th = *(u8 *)(s2 + 0x36);
            idx = (s32)((float)fcnt * *(float *)(s2 + 0x38));
            fu = (float)(u16)(idx % (u16)tw);
            one = 1.0f;
            *(f32 *)(s1 + 0x90) = fu * (one / (float)tw);
            one = 1.0f;
            *(f32 *)(s1 + 0x94) = (float)(u16)((idx / (u16)tw) % (u16)th) * (one / (float)th);
            break;
        }
        case 1:
            v0 = *(s32 *)s0;
            *(f32 *)(s1 + 0x90) = ((float)(float)v0 * *(float *)(s2 + 0x38));
            v0 = *(s32 *)s0;
            f2 = (float)v0;
            *(f32 *)(s1 + 0x94) = (f2 * *(float *)(s2 + 0x3c));
            f1 = *(float *)(s1 + 0x90);
            if (1.0f < f1) {
                *(f32 *)(s1 + 0x90) = (f1 - (float)((float)(s32)f1));
            }
            f1 = *(float *)(s1 + 0x94);
            if (1.0f < f1) {
                *(f32 *)(s1 + 0x94) = (f1 - (float)((float)(s32)f1));
            }
            f1 = *(float *)(s1 + 0x90);
            if (f1 < 0.0f) {
                *(f32 *)(s1 + 0x90) = 1.0f + (f1 - (float)(s32)f1);
            }
            f1 = *(float *)(s1 + 0x94);
            if (f1 < 0.0f) {
                *(f32 *)(s1 + 0x94) = 1.0f + (f1 - (float)(s32)f1);
            }
        }
        v1 = *(s32 *)s0;
        v0 = 0x7fffffff;
        v1 = v1 + 1;
        *(u32 *)s0 = v1;
        v1 = *(s32 *)(s1 + 0xa0);
        if (v1 != v0) {
            v0 = v1 + -1;
            *(u32 *)(s1 + 0xa0) = v0;
        }
        v0 = *(s32 *)(s1 + 0xa4);
        v0 = v0 + 1;
        *(u32 *)(s1 + 0xa4) = v0;
        v1 = *(u16 *)(s2 + 0x42);
        if (v1 != 0 && v1 <= (u32)*(s32 *)(s1 + 0xa4)) {
            *(u32 *)(s1 + 0xa4) = 0;
        }
        v0 = (((struct { u8 f0:1; u8 f1:1; u8 pad:6; } *)(s3 + 0x6c))->f0 != 0 || ((struct { u8 f0:1; u8 f1:1; u8 pad:6; } *)(s3 + 0x6c))->f1 != 0) ^ 1;
        if (v0 != 0) {
            a0_2 = (u8 *)s1;
            _SetMdlParamToMdlMng((void *)a0_2);
            a0_2 = (u8 *)*(u16 *)(s0 + 4);
            SfxMdl_EnableDraw((unsigned short)a0_2, 1);
        } else {
            a0_2 = (u8 *)*(u16 *)(s0 + 4);
            SfxMdl_EnableDraw((unsigned short)a0_2, 0);
        }
        s1 = (u8 *)*(s32 *)(s1 + 0xa8);
    }
    s5 += 1;
    while (1) {
        _L001B9990:;
        v1 = *(u8 *)(s3 + 0x46);
        a0_2 = (u8 *)s5;
        if ((s32)a0_2 >= (s32)v1) {
            break;
        }
        if ((u32)(s32)s1 != 0) {
            goto _L001B8FB8;
        }
        break;
    }
    *(u32 *)(s3 + 0x48) = (s32)fp;
    *(u8 *)(s3 + 0x46) = (s32)s6;
    return;
}


static void _SetMdlParamToMdlMng(void *a0 /* r4 */) {
    u8 *s2;
    u8 *a3;
    u8 *s1;
    u8 *a2;
    u8 *s0;
    u32 a1;
    u32 v1;
    u32 v0;
    float f13;
    float f12;
    float f2;
    float f23;
    float f22;
    float f21;
    float f20;
    float f1;
    float f0;
    void *a0_2;
    u8 stackFrame_D0[64] __attribute__((aligned(16)));
    u8 stackFrame_C0[16] __attribute__((aligned(16)));
    u8 stackFrame_80[64] __attribute__((aligned(16)));

    v0 = 1;
    s2 = (u8 *)a0;
    s1 = (u8 *)*(s32 *)(((u8 *)a0 + 0xac));
    v1 = *(u8 *)((*(s32 *)(s1 + 0x4c) + 0x40));
    s0 = (u8 *)(s2 + 0xb0);
    switch (v1) {
    case 2:
        a2 = (u8 *)V0;
        a3 = (u8 *)V1;
        SfxCalc_MakeRotTransMatrix_I_LEGACY((void *)((u8 *)&stackFrame_D0[0]), (float *)(s2 +
            0x40), (float *)V0, (float *)V1);
        v1 = (u32)((u8 *)&stackFrame_D0[0]);
        dcomp_cop2_9397A3F6B7((void *)v1, s1, (void *)v1);
        v0 = *(s32 *)(s1 + 0x40);
        dcomp_cop2_9397A3F6B7((void *)v1, (void *)v0, (void *)v1);
        v0 = GetCameraPos();
        sceVu0SubVector((void *)((u8 *)&stackFrame_C0[0]), (void *)v0, (void *)((u8
            *)&stackFrame_D0[0] + 0x30));
        f13 = ((float *)stackFrame_C0)[2];
        f0 = Math_VectorToAngle(*(float *)((u8 *)&stackFrame_C0[0]), f13);
        f23 = f0;
        a0_2 = (void *)s1;
        f0 = sceVu0InnerProduct(a0_2, (void *)s1);
        f22 = ({ float native_result_0; __asm__("sqrt.s %0,%1" : "=f"(native_result_0) : "f"(f0));
            native_result_0; });
        a0_2 = (void *)(s1 + 0x10);
        f0 = sceVu0InnerProduct(a0_2, (void *)a0_2);
        a0_2 = (void *)(s1 + 0x20);
        f21 = ({ float native_result_1; __asm__("sqrt.s %0,%1" : "=f"(native_result_1) : "f"(f0));
            native_result_1; });
        f0 = sceVu0InnerProduct(a0_2, (void *)a0_2);
        f20 = ({ float native_result_2; __asm__("sqrt.s %0,%1" : "=f"(native_result_2) : "f"(f0));
            native_result_2; });
        f2 = (3.1415927f + f23);
        if (f2 >= 0.0f) {
            f0 = (6.2831855f * (float)((float)(s32)(f2 / 6.2831855f)));
            f12 = (f23 - f0);
        } else {
            f1 = 6.2831855f;
            f0 = (f23 - (f1 * (float)((float)(s32)(f2 / f1))));
            f12 = (f1 + f0);
        }
        a1 = (u32)MRX1;
        sceVu0RotMatrixY((void *)((u8 *)&stackFrame_80[0]), (void *)MRX1, f12);
        sceVu0ScaleVector((void *)((u8 *)&stackFrame_D0[0]), (void *)((u8 *)&stackFrame_80[0]),
            (float)f22);
        sceVu0ScaleVector((void *)((u8 *)&stackFrame_D0[0] + 0x10), (void *)((u8
            *)&stackFrame_80[0] + 0x10), (float)f21);
        f12 = f20;
        sceVu0ScaleVector((void *)((u8 *)&stackFrame_D0[0] + 0x20), (void *)((u8
            *)&stackFrame_80[0] + 0x20), f12);
        break;
    case 1: {
        u8 stackFrame_70[16] __attribute__((aligned(16))) = {0};
    u8 stackFrame_60[16] __attribute__((aligned(16)));
    u8 stackFrame_50[16] __attribute__((aligned(16)));
        f0 = *(float *)(s2 + 0x54);
        a3 = (u8 *)V1;
        ((f32 *)stackFrame_70)[1] = f0;
        SfxCalc_MakeRotTransMatrix_I_LEGACY(stackFrame_D0, (float *)(s2+0x40), (float *)stackFrame_70, (float *)V1);
        v1 = (u32)((u8 *)&stackFrame_D0[0]);
        dcomp_cop2_9397A3F6B7((void *)(&stackFrame_D0[0]), (void *)((u8 *)s1), (void
            *)(&stackFrame_D0[0]));
        v0 = *(s32 *)(s1 + 0x40);
        dcomp_cop2_9397A3F6B7((void *)(&stackFrame_D0[0]), (void *)((u8 *)v0), (void
            *)(&stackFrame_D0[0]));
        sceVu0CopyVector((void *)((u8 *)&stackFrame_60[0]), (void *)((u8 *)&stackFrame_D0[0] +
            0x20));
        s1 = ((u8 *)&stackFrame_D0[0] + 0x30);
        sceVu0CopyVector((void *)((u8 *)&stackFrame_50[0]), (void *)((u8 *)&stackFrame_D0[0] +
            0x30));
        ((u32 *)stackFrame_60)[1] = 0;
        sceVu0Normalize((void *)((u8 *)&stackFrame_60[0]), (void *)((u8 *)&stackFrame_60[0]));
        SfxCalc_MakeMatrixFromDir((void *)((u8 *)&stackFrame_D0[0]), (float *)((u8
            *)&stackFrame_60[0]));
        a0_2 = (void *)((u8 *)&stackFrame_D0[0] + 0x30);
        sceVu0CopyVector(a0_2, (void *)((u8 *)&stackFrame_50[0]));
        break;
        }
    default:
        a3 = (u8 *)V1;
        SfxCalc_MakeRotTransMatrix_I_LEGACY((void *)((u8 *)&stackFrame_D0[0]), (float *)(s2 +
            0x40), (float *)(s2 + 0x50), (float *)V1);
        v1 = (u32)((u8 *)&stackFrame_D0[0]);
        dcomp_cop2_9397A3F6B7((void *)(&stackFrame_D0[0]), (void *)((u8 *)s1), (void
            *)(&stackFrame_D0[0]));
        v0 = *(s32 *)(s1 + 0x40);
        dcomp_cop2_9397A3F6B7((void *)(&stackFrame_D0[0]), (void *)((u8 *)v0), (void
            *)(&stackFrame_D0[0]));
    }
    a0_2 = (void *)*(u16 *)(s0 + 4);
    SfxMdl_SetMatrix_LEGACY((unsigned short)a0_2, (void *)((u8 *)&stackFrame_D0[0]));
    a0_2 = (void *)*(u16 *)(s0 + 4);
    SfxMdl_SetScale_LEGACY((unsigned short)a0_2, (float *)(s2 + 0x60));
    a0_2 = (void *)*(u16 *)(s0 + 4);
    SfxMdl_SetColor((unsigned short)a0_2, *(float *)(s2 + 0x70), *(float *)(s2 + 0x74), *(float
        *)(s2 + 0x78));
    a0_2 = (void *)*(u16 *)(s0 + 4);
    SfxMdl_SetAlpha((unsigned short)a0_2, *(float *)(s2 + 0x7c));
    a0_2 = (void *)*(u16 *)(s0 + 4);
    SfxMdl_SetTexScroll((unsigned short)a0_2, *(float *)(s2 + 0x90), *(float *)(s2 + 0x94));
    return;
}

static void __SFX_EndPtclDefault(u16 *a0 /* r4 */, u8 *a1 /* r5 */, u32 *a2 /* r6 */) {
    u16 a0_narrow; // a0

    a0_narrow = *(u16 *)(((u8 *)a0 + 0xb4));
    if ((u32)a0_narrow != (u32)0xffff) {
        SfxMdl_Free(a0_narrow);
    }
    return;
}

signed int PtclMng_EnableDraw(signed int a0 /* r4 */, signed int a1 /* r5 */, unsigned short a2 /* r6 */) {
    s32 off;
    u64 v1_64;
    u32 v0;
    u8 *p;
    u32 type;
    u32 s4;
    u8 *q;

    off = (u32)(a0) & 0xfff;
    v1_64 = (u32)((s32)a0 >> 0xc) & 0xfffff;
    v0 = (u32)*(s32 *)(*(s32 *)(((u8 *)(u32 *)s_mngp + 4)) + off * 4) & 0xfffff;
    p = (u8 *)(*(s32 *)(((u8 *)(u32 *)s_mngp + 8)) + off * 0xa0);
    if (v1_64 != (u64)v0) {
        return 0;
    }
    while (p != 0) {
        switch (a2) {
        case 0:
            ((struct { u8 f0:1; u8 pad1:7; } *)(p + 0x6c))->f0 = ((a1 != 0) ^ 1);
            break;
        case 1:
            ((struct { u8 pad0:1; u8 f1:1; u8 pad2:6; } *)(p + 0x6c))->f1 = ((a1 != 0) ^ 1);
            break;
        }
        type = **(s32 **)(*(s32 *)((u8 *)(u32 *)s_mngp + 0x10) + (*(u16 *)(p + 0x44) << 2));
        if (type == 0xb || type == 1) {
            s4 = (((struct { u8 f0:1; u8 f1:1; u8 pad2:6; } *)(p + 0x6c))->f0 != 0 || ((struct { u8 f0:1; u8 f1:1; u8 pad2:6; } *)(p + 0x6c))->f1 != 0) ^ 1;
            for (q = (u8 *)*(s32 *)(p + 0x48); q != 0; q = (u8 *)*(s32 *)(q + 0xa8)) {
                SfxMdl_EnableDraw(*(u16 *)(q + 0xb4), s4);
            }
        }
        p = (u8 *)*(s32 *)(p + 0x58);
    }
    return 1;
}


/* PtclMng_EnableAction @ 0x1B8740 .. 0x1B8810 (0xd0 bytes) */
/*
 * dcomp notes:
 *   cfg: kept goto: 0x1b8784 -> .L001B8808
 *   cfg: loop test does not fall through into its body: 0x1b87d0
 *   cfg: kept branch: 0x1b87d0 if (..) goto .L001B8788
 *   cfg: kept goto: 0x1b87e0 -> .L001B87D0
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int PtclMng_EnableAction(signed int a0 /* r4 */, signed int a1 /* r5 */, unsigned short a2 /* r6 */) {
    s32 off;
    u64 v1_64;
    u32 v0;
    u8 *p;

    off = (u32)(a0) & 0xfff;
    v1_64 = (u32)((s32)a0 >> 0xc) & 0xfffff;
    v0 = (u32)*(s32 *)(*(s32 *)(((u8 *)(u32 *)s_mngp + 4)) + off * 4) & 0xfffff;
    p = (u8 *)(*(s32 *)(((u8 *)(u32 *)s_mngp + 8)) + off * 0xa0);
    if (v1_64 != (u64)v0) {
        return 0;
    }
    while (p != 0) {
        switch (a2) {
        case 0:
            ((struct { u8 pad0:2; u8 f2:1; u8 pad3:5; } *)(p + 0x6c))->f2 = ((a1 != 0) ^ 1);
            break;
        case 1:
            ((struct { u8 pad0:3; u8 f3:1; u8 pad4:4; } *)(p + 0x6c))->f3 = ((a1 != 0) ^ 1);
            break;
        }
        p = (u8 *)*(s32 *)(p + 0x58);
    }
    return 1;
}
void __SFX_InitSprite(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    u8 *s4;
    u8 *s3;
    u8 *s2;
    u32 v1;
    u8 *s1;
    u8 s0;
    float f3;
    float f2;
    float f1;
    u32 v0;
    float r;
    void *a0_2;
    void *a1_2;

    v0 = (u32)s_aTexMng;
    s4 = (u8 *)a0;
    s3 = (u8 *)a1;
    s2 = (u8 *)*(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571) = (s32)s2;
    v1 = *(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20) = v1;
    v1 = *(u16 *)s2;
    v0 = *(s32 *)(u32)(s32)(u32)&((struct { u8 b[4]; } *)s_aTexMng)[v1];
    *(u32 *)(((u8 *)a0 + 0x80)) = v0;
    sceVu0UnitMatrix(a0);
    *(f32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7) = *(float *)(s3 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D);
    *(f32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9) = *(float *)(s3 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01);
    *(f32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0) = *(float *)(s3 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2);
    dcomp_cop2_9397A3F6B7((void *)((u8 *)s4), (void *)((u8 *)s4), (void *)((u8 *)s3));
    a0_2 = (void *)(s4 + 0x30);
    a1_2 = (void *)(s3 + 0x40);
    sceVu0CopyVector(a0_2, a1_2);
    v0 = *(s32 *)(s3 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24);
    if (v0 != 0) {
        *(u32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) = v0;
    } else {
        *(u32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) = 0;
    }
    v1 = *(s16 *)(s2 + 2);
    if ((s32)v1 < 0) {
        v0 = 0x7fffffff;
        *(u32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD) = 0x7fffffff;
    } else {
        v0 = *(u16 *)(s2 + 4);
        *(u32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD) = v1 + v0;
    }
    a0_2 = (void *)*(u16 *)(s3 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
    v0 = (u32)_AllocPtcl((signed int)a0_2);
    *(u32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087) = v0;
    v1 = *(u16 *)(s3 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
    s1 = (u8 *)*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    s0 = 0;
    if (0 < (s32)v1) {
        do {
            if ((u32)(s32)s1 == 0) {
                break;
            }
            v0 = *(s16 *)(s2 + 2);
            if ((s32)v0 < 0) {
                v0 = 0x7fffffff;
                *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = 0x7fffffff;
            } else {
                r = (float)(u16)SfxCalc_RandU32() * 1.5259022e-05f;
                *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = (u32)((float)*(s16 *)(s2 + 2) + (float)*(u16 *)(s2 + 4) * (r - 0.5f));
            }
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F) = (s32)(100.0f * (r - 0.5f));
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C) = 0;
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_1__C6D2CBBE) = 0;
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            f3 = r;
            v0 = 0x3c8e0000;
            v1 = 0x3c8e0000 | 0xf34d;
            v0 = 0x3f800000;
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE) = (0.01745f *
                (*(float *)(s2 + 0x24) + (*(float *)(s2 + 0x28) * (f3 - 0.5f))));
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_3__500368EC) = 0x3f800000;
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E) = (*(float *)(s2
                + 0x2c) + (*(float *)(s2 + 0x30) * (r -
                0.5f)));
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9) = (*(float *)(s2
                + 0x34) + (*(float *)(s2 + 0x38) * (r -
                0.5f)));
            v0 = SfxCalc_RandU32();
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E) = (*(float *)(s2
                + 0x3c) + (*(float *)(s2 + 0x40) * ((1.5259022e-05f * (float)(float)(u32)(u16)v0) -
                0.5f)));
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC) = 0;
            SfxUtil_CalcRndPos((float *)(s1 + 0x40), *(u16 *)(s2 + 6), (float *)(u8 *)(s2 + 8));
            a0_2 = (void *)(s1 + 0x40);
            sceVu0AddVector(a0_2, (void *)(u32)(s32)a0_2, (void *)(u8 *)(s3 + 0x40));
            a0_2 = (void *)0x3f800000;
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED) = 0x3f800000;
            s0 += 1;
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510) = (u32)s4;
            v1 = *(u16 *)(s3 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
            v1 = (s32)s0 < (s32)v1;
            s1 = (u8 *)*(s32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76);
        } while (v1 != 0);
    }
    *(u8 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B) = s0;
    return;
}
void __SFX_ActSprite(void *a0 /* r4 */, float f12 /* f12 */) {
    u8 *s3;
    u32 *t0;
    u8 s2;
    u32 *s1;
    u8 *s0;
    u8 *s5;
    u8 *s6;
    u8 *s7;
    float f20;
    s32 fp;
    u32 a3;
    u8 *s4;
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f2;
    float f1;
    float f0;
    void *a0_2;
    void *pMrx1;
    void *pm;
    u8 stackFrame_17C[4] __attribute__((aligned(4)));
    u8 stackFrame_178[4] __attribute__((aligned(8)));
    float ang[3] __attribute__((aligned(8)));
    u8 stackFrame_150[24] __attribute__((aligned(16)));
    float scl[3][2] __attribute__((aligned(16)));
    float vAdd[4] __attribute__((aligned(16)));
    float tmp_vector[4] __attribute__((aligned(16)));
    u8 mrx[64] __attribute__((aligned(16)));
    float vt[4] __attribute__((aligned(16)));

    fp = 0;
    s6 = (u8 *)0;
    s5 = (u8 *)0;
    s3 = (u8 *)a0;
    s2 = 0;
    s0 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    s1 = (u32 *)0;
    f20 = (float)f12;
    s7 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571);
    pMrx1 = (void *)MRX1;
    goto _L001B80A0;
    _L001B7B18:;
    v0 = *(s32 *)(s0 + 0xa0);
    s4 = (u8 *)*(s32 *)(s0 + 0xa4);
    if (v0 == 0) {
        s4 = (u8 *)s0;
        if ((u32)s5 != 0) {
            v0 = *(s32 *)(s0 + 0xa8);
            *(u32 *)(s5 + 0xa8) = v0;
        }
        a0_2 = (void *)*(s32 *)(s4 + 0xac);
        v1 = s_mngp;
        v0 = (u32)s_FuncTable;
        a0_2 = (void *)*(u16 *)(((u8 *)a0_2 + 0x44));
        a0_2 = (void *)(s32)((u32)a0_2 << 2);
        v1 = *(s32 *)(u32)(s32)((u8 *)(u32)*(s32 *)((v1 + 0x10)) + (u32)(a0_2));
        a0_2 = (void *)*(s32 *)v1;
        v0 = (s32)((u8 *)s_FuncTable + (s32)((u32)((u32)(a0_2)) * (u32)(0x14)));
        v0 = *(s32 *)((v0 + 0x10));
        s0 = (u8 *)*(s32 *)(s0 + 0xa8);
        if (v0 != 0) {
            a0_2 = (void *)s4;
            ((void (*)(s32))(s32)v0)((s32)a0_2);
        }
        a0_2 = (void *)s4;
        memset(a0_2, 0, 0xe0);
        v1 = *(s32 *)((s_mngp + 0x30));
        *(u32 *)(s4 + 0xa8) = v1;
        v1 = s_mngp;
        *(u32 *)((v1 + 0x30)) = (s32)s4;
        a0_2 = (void *)s_mngp;
        v1 = *(s16 *)(((u8 *)a0_2 + 0x38));
        v1 = v1 + -1;
        *(u16 *)(((u8 *)a0_2 + 0x38)) = v1;
    } else {
        if ((u32)s6 == 0) {
            s6 = (u8 *)s0;
        }
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 6;
        a2 = 3;
        s5 = (u8 *)s0;
        a3 = *(s32 *)((v0 + 0x14));
        s1 = (u32 *)((u8 *)s1 + 1);
        SFX_GetSeqParam((void *)((u8 *)&ang[0]), a1, a2, (void *)a3, (s32)s4);
        f1 = *(float *)(s0 + 0x58);
        f2 = ((*(volatile float *)&ang[2] * 0.01745f) * f20);
        {
            float angle = f1 + f2;
            *(float *)(s0 + 0x58) = angle;
            angle = (angle < -3.14159f || 3.14159f < angle) ? SfxCalc_IntoAngle_0_2PI(angle) - 6.28318f : angle;
            f12 = angle;
        }
        *(f32 *)(s0 + 0x58) = f12;
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 6;
        a2 = 2;
        a3 = *(s32 *)((v0 + 0x1c));
        SFX_GetSeqParam((void *)((u8 *)&scl[0]), a1, a2, (void *)a3, (s32)s4);
        v0 = *(u8 *)(s7 + 0x4c);
        if (v0 != 0) {
            {
                float sc = (scl[0][0] + (scl[0][1] * (0.01f * (float)*(s8 *)(s0 + 0x9c))));
                *(f32 *)(s0 + 0x64) = sc;
                *(f32 *)(s0 + 0x60) = sc;
            }
        } else {
            v0 = *(s32 *)(s3 + 0x50);
            a3 = *(s32 *)((v0 + 0x24));
            SFX_GetSeqParam((void *)((u8 *)&scl[0] + 0x8), 6, 2, (void *)a3, (s32)s4);
            *(f32 *)(s0 + 0x60) = (scl[0][0] + (scl[0][1] * (0.01f * (float)*(s8 *)(s0 + 0x9c))));
            *(f32 *)(s0 + 0x64) = (scl[1][0] + (scl[1][1] * (0.01f * (float)*(s8 *)(s0 + 0x9d))));
        }
        sceVu0ScaleVector((void *)((u8 *)&vAdd[0]), (void *)(s0 + 0x80), (float)f20);
        a0_2 = (void *)(s0 + 0x40);
        sceVu0AddVector(a0_2, (void *)a0_2, (void *)((u8 *)&vAdd[0]));
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 6;
        a2 = 1;
        a3 = *(s32 *)((v0 + 0xc));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_17C[0]), a1, a2, (void *)a3, (s32)s4);
        f0 = *(float *)((u8 *)&stackFrame_17C[0]);
        if (!(0.0f == f0)) {
            if ((u32)fp == 0) {
                pm = *(void **)(s3 + 0x40);
                if (pm != 0) {
                    dcomp_cop2_9397A3F6B7((void *)mrx, pm, (void *)s3);
                } else {
                    sceVu0CopyMatrix((void *)mrx, (void *)s3);
                }
                SfxCalc_Vector2Angle((float *)((u8 *)&tmp_vector[0]), (float *)(mrx + 0x8));
                f0 = tmp_vector[1];
                sceVu0RotMatrixY((void *)mrx, pMrx1, (-f0));
                f0 = tmp_vector[0];
                sceVu0RotMatrixX((void *)mrx, (void *)mrx, (-f0));
                dcomp_cop2_21F95D43C1((void *)((u8 *)&stackFrame_150[0]), (void *)mrx, (void *)VY);
                fp = 1;
            }
            f0 = *(float *)((u8 *)&stackFrame_17C[0]);
            sceVu0ScaleVector((void *)((u8 *)&vt[0]), (void *)((u8 *)&stackFrame_150[0]), (f0 *
                f20));
            a0_2 = (void *)(s0 + 0x80);
            sceVu0AddVector(a0_2, (void *)((u8 *)&vt[0]), (void *)a0_2);
        }
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 1;
        a2 = 3;
        a3 = *(s32 *)((v0 + 0x2c));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_178[0]), a1, a2, (void *)a3, (s32)s4);
        f0 = ((float)(float)(u32)*(u8 *)((u8 *)&stackFrame_178[0]) / 128.0f);
        *(f32 *)(s0 + 0x70) = f0;
        f0 = ((float)(float)(u32)((u8 *)stackFrame_178)[1] / 128.0f);
        *(f32 *)(s0 + 0x74) = f0;
        a1 = 1;
        t0 = (u32 *)s4;
        f0 = ((float)(float)(u32)((u8 *)stackFrame_178)[2] / 128.0f);
        *(f32 *)(s0 + 0x78) = f0;
        v0 = *(s32 *)(s3 + 0x50);
        a3 = *(s32 *)((v0 + 0x34));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_178[0] + 0x3), a1, a1, (void *)a3, (signed
            int)t0);
        v1 = (u32)((u8 *)&stackFrame_178[0] + 0x3);
        v1 = 0x7fffffff;
        f0 = ((float)(float)(u32)((u8 *)stackFrame_178)[3] / 128.0f);
        *(f32 *)(s0 + 0x7c) = f0;
        a0_2 = (void *)*(s32 *)(s0 + 0xa0);
        if ((u32)(s32)a0_2 != v1) {
            v1 = (s32)((u8 *)a0_2 + -1);
            *(u32 *)(s0 + 0xa0) = v1;
        }
        v1 = *(s32 *)(s0 + 0xa4);
        v1 = v1 + 1;
        *(u32 *)(s0 + 0xa4) = v1;
        a0_2 = (void *)*(u16 *)(s7 + 0x4a);
        if ((u32)a0_2 != 0 && (u32)a0_2 <= (u32)*(s32 *)(s0 + 0xa4)) {
            *(u32 *)(s0 + 0xa4) = 0;
        }
        s0 = (u8 *)*(s32 *)(s0 + 0xa8);
    }
    s2 += 1;
    while (1) {
        _L001B80A0:;
        v1 = *(u8 *)(s3 + 0x46);
        a0_2 = (void *)s2;
        if ((s32)a0_2 >= (s32)v1) {
            break;
        }
        if ((u32)(s32)s0 != 0) {
            goto _L001B7B18;
        }
        break;
    }
    *(u32 *)(s3 + 0x48) = (s32)s6;
    *(u8 *)(s3 + 0x46) = (s32)s1;
    return;
}


/* __SFX_DrawSprite @ 0x1B7A20 .. 0x1B7AA8 (0x88 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   cfg: kept goto: 0x1b7a4c -> .L001B7A70
 *   cfg: loop body is not one contiguous region: .L001B7A70
 *   cfg: kept branch: 0x1b7a84 if (..) goto .L001B7A58
 *   a1 typed from the __SFX_DrawSprite call table
 *   a2 typed from the __SFX_DrawSprite call table
 *   declaration vs inferred signature: return void vs inferred u8
 */

static void __SFX_DrawSprite(void *a0 /* r4 */) {
    u8 *s0;
    u8 s2;
    u32 s1;
    u32 v1;

    v1 = *(s32 *)(((u8 *)a0 + 0x4c));
    s1 = *(s32 *)(((u8 *)a0 + 0x48));
    v1 = *(u16 *)v1;
    s0 = (u8 *)a0;
    if ((s32)v1 > 0 && s1) {
        s2 = 0;
        goto _L001B7A70;
        _L001B7A58:;
        a0 = (void *)(s32)s1;
        __SFX_DrawPtclSprite(a0);
        s1 = *(s32 *)((s1 + 0xa8));
        s2 += 1;
        while (1) {
            _L001B7A70:;
            v1 = *(u8 *)(s0 + 0x46);
            a0 = (void *)s2;
            if ((s32)a0 >= (s32)v1) {
                break;
            }
            if (s1 != 0) {
                goto _L001B7A58;
            }
            break;
        }
    }
    return;
}


/* __SFX_DrawPtclSprite @ 0x1B7820 .. 0x1B7A14 (0x1f4 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   quad: s0: 128-bit web split from its scalar uses
 *   stack: address of the slot at 0x80 escapes at 0x1b7884
 *   stack: address of the slot at 0x80 escapes at 0x1b789c
 *   stack: address of the slot at 0x70 escapes at 0x1b798c
 *   fpu: float literal 0xbf800000 at 0x1b79b8
 *   stack: address of the slot at 0x80 escapes at 0x1b79dc
 *   stack: address of the slot at 0x70 escapes at 0x1b79dc
 *   quad: a0: 128-bit web split from its scalar variable as a0_q
 *   quad: v0: 128-bit web split from its scalar variable as v0_q
 *   cfg: kept branch: 0x1b7860 if (..) goto .L001B79F0
 *   a1 typed from the __SFX_DrawPtclSprite call table
 *   a2 typed from the __SFX_DrawPtclSprite call table
 *   declaration vs inferred signature: return void vs inferred u32
 */



void __SFX_DrawPtclSprite(void *a0 /* r4 */) {
    u8 *s3;
    u32 a1;
    u8 *s2;
    u8 *s1;
    s64 v0_64;
    u32 v1;
    u8 *s0;
    float f1;
    u32 v0;
    float f0;
    u8 *s4;
    u_long128 v0_q;
    u_long128 s0_q;
    float f20;
    void *a0_2;
    u32 outside;
    s32 below;
    u8 stackFrame_80[16] __attribute__((aligned(16)));
    u8 stackFrame_70[16] __attribute__((aligned(16)));

    v0 = s_mngp;
    s2 = (u8 *)*(s32 *)(((u8 *)a0 + 0xac));
    v0 = *(s8 *)((v0 + 0x3c));
    s1 = (u8 *)*(s32 *)(s2 + 0x4c);
    v0_64 = (s64)((u64)((s64)(s32)v0) << 0x3f) >> 0x3f;
    s3 = (u8 *)a0;
    if ((u64)v0_64 != 0) {
        a0_2 = (void *)*(u16 *)(s2 + 0x6e);
        v0 = SFX_ConfirmReflect(a0_2, 0);
        if (v0 == 0) {
            goto _L001B79F0;
        }
    }
    a1 = *(s32 *)(s2 + 0x40);
    if (a1 != 0) {
        sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_80[0]), (void *)a1, (void *)(s3 + 0x40));
    } else {
        sceVu0CopyVector((void *)((u8 *)&stackFrame_80[0]), (void *)(s3 + 0x40));
    }
    v0 = SFX_GetSettingData();
    s0 = (u8 *)v0;
    outside = !(0 < (u32)SfxCalc_CheckInsightCamera((float *)((u8 *)&stackFrame_80[0])));
    below = *(float *)(s3 + 0x7c) < *(float *)(s0 + 0xc);
    if (outside != 0 || below != 0) {
        return;
    }
    s4 = (u8 *)*(s32 *)(s2 + 0x80);
    v0_q = SfxDraw_GetRenderStateBlock();
    s0_q = v0_q;
    SfxDraw_UseTexture(1);
    a0_2 = (void *)*(u8 *)(s1 + 0x48);
    SfxDraw_SetBlendType((unsigned short)a0_2);
    SfxDraw_SetTexture((void *)s4);
    a0_2 = (void *)*(u8 *)(s1 + 0x49);
    SfxDraw_EnableFog((signed int)a0_2);
    a0_2 = (void *)*(s32 *)(s2 + 0x40);
    if (a0_2 != 0) {
        f0 = sceVu0InnerProduct(a0_2, a0_2);
        v0 = *(s32 *)(s2 + 0x40);
        f20 = ({ float native_result_0; __asm__("sqrt.s %0,%1" : "=f"(native_result_0) : "f"(f0));
            native_result_0; });
        a0_2 = (void *)(s32)(v0 + 0x10);
        f0 = sceVu0InnerProduct(a0_2, (void *)a0_2);
        f1 = ({ float native_result_1; __asm__("sqrt.s %0,%1" : "=f"(native_result_1) : "f"(f0));
            native_result_1; });
        v0 = 0x3f800000;
        *(f32 *)((u8 *)&stackFrame_70[0]) = (*(float *)(s3 + 0x60) * f20);
        f0 = (*(float *)(s3 + 0x64) * f1);
        ((u32 *)stackFrame_70)[2] = 0x3f800000;
        ((u32 *)stackFrame_70)[3] = 0;
        ((f32 *)stackFrame_70)[1] = f0;
    } else {
        sceVu0CopyVector((void *)((u8 *)&stackFrame_70[0]), (void *)(s3 + 0x60));
    }
    v0 = *(s8 *)((s_mngp + 0x3c));
    v0_64 = (s64)((u64)((s64)(s32)v0) << 0x3f) >> 0x3f;
    if ((u64)v0_64 != 0) {
        ((f32 *)stackFrame_70)[1] = (((float *)stackFrame_70)[1] * -1.0f);
    }
    SfxDraw_DrawSprite_Wld((float *)((u8 *)&stackFrame_80[0]), (void *)((u8 *)&stackFrame_70[0]),
        *(float *)(s3 + 0x58), (void *)(s3 + 0x70), (void *)0, *(float *)(s1 + 0x44));
    SfxDraw_SetRenderStateBlock(s0_q);
    _L001B79F0:;
    return;
}

void __SFX_InitSprite2(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    u8 *s5;
    u8 *s4;
    u8 *s3;
    u32 v1;
    u32 v0;
    u8 *s2;
    u8 s1;
    float f4;
    float f3;
    float f2;
    float f1;
    float f0;
    float r;
    float spdz;
    float py;
    float yaw;
    void *a0_2;
    void *a1_2;

    v0 = 3;
    s5 = (u8 *)a0;
    s3 = (u8 *)*(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PFIXPARAM_FECB6825);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_FIX_PARAM_89E876C2) = (s32)s3;
    v1 = *(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PSEQPARAM_30AF687F);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_SEQ_PARAM_BCE30E49) = v1;
    v1 = *(u8 *)(s3 + DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__59__CDUMMY_A7408244);
    s4 = (u8 *)a1;
    v0 = 2;
    v0 = 1;
    switch (v1) {
    case 0:
        ((struct dw_1891466_fields_a92cd2e9 *)s5)->bit_flag.draw_stage = v0;
        break;
    case 1:
        v1 = 0x40;
        ((struct dw_1891466_fields_a92cd2e9 *)s5)->bit_flag.draw_stage = 4;
        break;
    case 2:
        v1 = 0x60;
        ((struct dw_1891466_fields_a92cd2e9 *)s5)->bit_flag.draw_stage = 6;
        break;
    case 3:
        v1 = 0x60;
        ((struct dw_1891466_fields_a92cd2e9 *)s5)->bit_flag.draw_stage = 6;
    }
    v1 = *(u16 *)s3;
    a0_2 = (void *)s5;
    v0 = (u32)s_aTexMng;
    a1_2 = (void *)(s4 + 0x60);
    a2 = (void *)(s4 + 0x50);
    v0 = *(s32 *)(u32)(s32)(u32)&((struct { u8 b[4]; } *)s_aTexMng)[v1];
    *(u32 *)(s5 + 0x80) = v0;
    SfxCalc_MakeMatrix_SPYRT(a0_2, (float *)a1_2, (float *)a2, (float *)(u8 *)(s4 + 0x40));
    v0 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_P_MATRIX_856A4D9C);
    if (v0 != 0) {
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_MATRIX_84DDDCB3) = v0;
    } else {
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_MATRIX_84DDDCB3) = 0;
    }
    v1 = *(s16 *)(s3 + 2);
    if ((s32)v1 < 0) {
        v0 = 0x7fffffff;
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_LIFECNT_7CEC2A9C) = 0x7fffffff;
    } else {
        v0 = *(u16 *)(s3 + 4);
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_LIFECNT_7CEC2A9C) = v1 + v0;
    }
    a0_2 = (void *)*(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_PTCL_NUM_5C66241F);
    v0 = (u32)_AllocPtcl((signed int)a0_2);
    *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_PTCL_TOP_1E22B1BC) = v0;
    v1 = *(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_PTCL_NUM_5C66241F);
    s2 = (u8 *)*(s32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_PTCL_TOP_1E22B1BC);
    s1 = 0;
    if (0 < (s32)v1) {
        do {
            if ((u32)(s32)s2 == 0) {
                break;
            }
            v0 = *(s16 *)(s3 + 2);
            if ((s32)v0 < 0) {
                v0 = 0x7fffffff;
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LIFECNT_92F2613A) =
                    0x7fffffff;
            } else {
                r = (float)(u16)SfxCalc_RandU32() * 1.5259022e-05f;
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LIFECNT_92F2613A) = (u32)((float)*(s16 *)(s3 + 2) + (float)*(u16 *)(s3 + 4) * (r - 0.5f));
            }
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_0__A5F80208) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_1__649EEDFC) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_2__16CFF809) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_3__2BF6EA67) = (s32)(100.0f * (r - 0.5f));
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_0__5DFAC5FD) = 0;
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_1__7C315EB0) = 0;
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_2__44E621F2) = 0.01745f * (*(float *)(s3 + 0x14) + *(float *)(s3 + 0x18) * (r - 0.5f));
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_3__84C321C3) = 0x3f800000;
            {
                float spd[4] __attribute__((aligned(16))) = {0};
                float mRot[4][4] __attribute__((aligned(16)));
                PTCL_RNDRANGE(spdz, *(float *)(s3 + 0x1c), *(float *)(s3 + 0x20));
                spd[2] = spdz;
                PTCL_RNDRANGE(py, *(float *)(s3 + 0x24), *(float *)(s3 + 0x28));
                PTCL_RNDRANGE(yaw, *(float *)(s3 + 0x2c), *(float *)(s3 + 0x30));
                SfxCalc_MakeMatrixFromPYR((void *)mRot, 0.01745f * py, 0.01745f * yaw, 0.0f);
                sceVu0ApplyMatrix((void *)(s2 + 0x80), (void *)mRot, (void *)spd);
            }
            a0_2 = (void *)(s2 + 0x80);
            sceVu0ApplyMatrix(a0_2, (void *)s5, (void *)(u8 *)a0_2);
            a0_2 = (void *)(s2 + 0x40);
            SfxUtil_CalcRndPos((float *)a0_2, *(u16 *)(s3 + 6), (float *)(u8 *)(s3 + 8));
            a0_2 = (void *)(s2 + 0x40);
            sceVu0AddVector(a0_2, (void *)(u32)(s32)a0_2, (void *)(u8 *)(s4 + 0x40));
            a0_2 = (void *)0x3f800000;
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LOC_3__E52D55BB) = 0x3f800000;
            s1 += 1;
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_PEMITTER_8D2B2DDD) = (u32)s5;
            v1 = *(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_PTCL_NUM_5C66241F);
            v1 = (s32)s1 < (s32)v1;
            s2 = (u8 *)*(s32 *)(s2 +
                DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_P_SIBLING_8BDDA96F);
        } while (v1 != 0);
    }
    *(u8 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_PTCL_NUM_86E21A87) = s1;
    return;
}


void __SFX_ActSprite2(void *a0 /* r4 */, float f12 /* f12 */) {
    u8 *s3;
    u8 s2;
    u32 *s5;
    u8 *s1;
    u8 *s6;
    u8 *s7;
    u8 *s0;
    s32 fp;
    float f20;
    u32 *t0;
    u8 *s4;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f4;
    float f2;
    float f1;
    float f0;
    float f21;
    float f22;
    void *a0_2;
    u8 stackFrame_16C[4] __attribute__((aligned(4)));
    u8 stackFrame_168[4] __attribute__((aligned(8)));
    u8 stackFrame_160[8] __attribute__((aligned(16)));
    u8 stackFrame_150[16] __attribute__((aligned(16)));
    u8 stackFrame_130[24] __attribute__((aligned(16)));
    u8 stackFrame_120[16] __attribute__((aligned(16)));
    u8 stackFrame_110[16] __attribute__((aligned(16)));
    u8 stackFrame_D0[64] __attribute__((aligned(16)));
    u8 stackFrame_C0[16] __attribute__((aligned(16)));
    u8 stackFrame_B0[16] __attribute__((aligned(16)));

    fp = 0;
    s7 = (u8 *)0;
    s6 = (u8 *)0;
    s5 = (u32 *)0;
    s3 = (u8 *)a0;
    s2 = 0;
    s1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x48));
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x4c));
    f20 = (float)f12;
    goto _L001B7050;
    _L001B6900:;
    v0 = *(s32 *)(s1 + 0xa0);
    s4 = (u8 *)*(s32 *)(s1 + 0xa4);
    if (v0 == 0) {
        s4 = (u8 *)s1;
        if ((u32)s6 != 0) {
            v0 = *(s32 *)(s1 + 0xa8);
            *(u32 *)(s6 + 0xa8) = v0;
        }
        a0_2 = (void *)*(s32 *)(s4 + 0xac);
        v1 = s_mngp;
        v0 = (u32)s_FuncTable;
        a0_2 = (void *)*(u16 *)(((u8 *)a0_2 + 0x44));
        a0_2 = (void *)(s32)((u32)a0_2 << 2);
        v1 = *(s32 *)(u32)(s32)((u8 *)(u32)*(s32 *)((v1 + 0x10)) + (u32)(a0_2));
        a0_2 = (void *)*(s32 *)v1;
        v0 = (s32)((u8 *)s_FuncTable + (s32)((u32)((u32)(a0_2)) * (u32)(0x14)));
        v0 = *(s32 *)((v0 + 0x10));
        s1 = (u8 *)*(s32 *)(s1 + 0xa8);
        if (v0 != 0) {
            a0_2 = (void *)s4;
            ((void (*)(s32))(s32)v0)((s32)a0_2);
        }
        a0_2 = (void *)s4;
        memset(a0_2, 0, 0xe0);
        v1 = *(s32 *)((s_mngp + 0x30));
        *(u32 *)(s4 + 0xa8) = v1;
        v1 = s_mngp;
        *(u32 *)((v1 + 0x30)) = (s32)s4;
        a0_2 = (void *)s_mngp;
        v1 = *(s16 *)(((u8 *)a0_2 + 0x38));
        v1 = v1 + -1;
        *(u16 *)(((u8 *)a0_2 + 0x38)) = v1;
    } else {
        if ((u32)s7 == 0) {
            s7 = (u8 *)s1;
        }
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 6;
        a2 = 2;
        s6 = (u8 *)s1;
        a3 = *(s32 *)((v0 + 0xc));
        s5 = (u32 *)((u8 *)s5 + 1);
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_160[0]), a1, a2, (void *)a3, (s32)s4);
        a0_2 = (void *)*(s8 *)(s1 + 0x9e);
        v0 = 0x3c230000;
        v1 = 0x3c230000 | 0xd70a;
        f4 = ((float *)stackFrame_160)[1];
        f1 = *(float *)(s1 + 0x58);
        v0 = 0x3c8e0000;
        v1 = 0x3c8e0000 | 0xf34d;
        v0 = -0x3fb6f030;
        f2 = (f20 * (0.01745f * (*(float *)((u8 *)&stackFrame_160[0]) + (f4 * (0.01f *
            (float)((float)(s32)(u32)a0_2))))));
        {
            float angle=f1+f2;
            *(float *)(s1+0x58)=angle;
            angle=(angle < -3.14159f || 3.14159f < angle) ? SfxCalc_IntoAngle_0_2PI(angle)-6.28318f : angle;
            *(float *)(s1+0x58)=angle;
        }
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 6;
        a2 = 2;
        a3 = *(s32 *)((v0 + 0x14));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_130[0]), a1, a2, (void *)a3, (s32)s4);
        v0 = *(u8 *)(s0 + 0x3a);
        if (v0 != 0) {
            f0 = *(float *)stackFrame_130 + *(float *)(stackFrame_130+4)*(0.01f*(float)(s32)*(s8 *)(s1+0x9c));
            *(f32 *)(s1 + 0x64) = f0;
            *(f32 *)(s1 + 0x60) = f0;
        } else {
            v0 = *(s32 *)(s3 + 0x50);
            a3 = *(s32 *)((v0 + 0x1c));
            SFX_GetSeqParam((void *)((u8 *)&stackFrame_130[0] + 0x8), 6, 2, (void *)a3, (s32)s4);
            *(float *)(s1+0x60) = *(float *)stackFrame_130 + *(float *)(stackFrame_130+4)*(0.01f*(float)(s32)*(s8 *)(s1+0x9c));
            *(float *)(s1+0x64) = *(float *)(stackFrame_130+8) + *(float *)(stackFrame_130+12)*(0.01f*(float)(s32)*(s8 *)(s1+0x9d));
        }
        sceVu0ScaleVector((void *)((u8 *)&stackFrame_120[0]), (void *)(s1 + 0x80), (float)f20);
        a0_2 = (void *)(s1 + 0x40);
        sceVu0AddVector(a0_2, (void *)a0_2, (void *)((u8 *)&stackFrame_120[0]));
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 6;
        a2 = 1;
        a3 = *(s32 *)((v0 + 4));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_16C[0]), a1, a2, (void *)a3, (s32)s4);
        f0 = *(float *)((u8 *)&stackFrame_16C[0]);
        if (!(0.0f == f0)) {
            if ((u32)fp == 0) {
                {
                    void *source=*(void **)(s3+0x40);
                    if (source) {
                        void *destination=stackFrame_D0;
                        dcomp_cop2_9397A3F6B7(destination,source,s3);
                    } else sceVu0CopyMatrix(stackFrame_D0,s3);
                }
                SfxCalc_Vector2Angle((float *)((u8 *)&stackFrame_110[0]), (float *)((u8
                    *)&stackFrame_D0[0] + 0x8));
                {
                    float shifted, angle;
                    angle=*(float *)(stackFrame_110+4);
                    shifted=3.1415927f-angle;
                    f12=shifted>=0.0f ? -angle-6.2831855f*(float)(s32)(shifted/6.2831855f) : 6.2831855f+(-angle-6.2831855f*(float)(s32)(shifted/6.2831855f));
                }
                sceVu0RotMatrixY((void *)((u8 *)&stackFrame_D0[0]), (void *)MRX1, f12);
                {
                    float shifted, angle;
                    angle=*(float *)stackFrame_110;
                    shifted=3.1415927f-angle;
                    f12=shifted>=0.0f ? -angle-6.2831855f*(float)(s32)(shifted/6.2831855f) : 6.2831855f+(-angle-6.2831855f*(float)(s32)(shifted/6.2831855f));
                }
                sceVu0RotMatrixX((void *)((u8 *)&stackFrame_D0[0]), (void *)((u8
                    *)&stackFrame_D0[0]), f12);
                a2 = (u32)VY;
                sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_150[0]), (void *)((u8
                    *)&stackFrame_D0[0]), (void *)VY);
                fp = 1;
            }
            f0 = *(float *)((u8 *)&stackFrame_16C[0]);
            sceVu0ScaleVector((void *)((u8 *)&stackFrame_C0[0]), (void *)((u8
                *)&stackFrame_150[0]), (f0 * f20));
            a0_2 = (void *)(s1 + 0x80);
            sceVu0AddVector(a0_2, (void *)((u8 *)&stackFrame_C0[0]), (void *)a0_2);
        }
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 1;
        a2 = 3;
        a3 = *(s32 *)((v0 + 0x24));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_168[0]), a1, a2, (void *)a3, (s32)s4);
        f1 = (float)(u32)*(u8 *)((u8 *)&stackFrame_168[0]);
        *(f32 *)(s1 + 0x70) = (f1 / 128.0f);
        f1 = (float)(u32)((u8 *)stackFrame_168)[1];
        *(f32 *)(s1 + 0x74) = (f1 / 128.0f);
        f1 = (float)(u32)((u8 *)stackFrame_168)[2];
        a1 = 1;
        t0 = (u32 *)s4;
        *(f32 *)(s1 + 0x78) = (f1 / 128.0f);
        v0 = *(s32 *)(s3 + 0x50);
        a3 = *(s32 *)((v0 + 0x2c));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_168[0] + 0x3), a1, a1, (void *)a3, (signed
            int)t0);
        v1 = (u32)((u8 *)&stackFrame_168[0] + 0x3);
        f1 = (float)(u32)((u8 *)stackFrame_168)[3];
        *(f32 *)(s1 + 0x7c) = (f1 / 128.0f);
        v1 = *(u8 *)(s0 + 0x3f);
        if (v1 != 0) {
            a1 = *(s32 *)(s3 + 0x40);
            if (a1 != 0) {
                sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_B0[0]), (void *)a1, (void *)(s1 +
                    0x40));
            } else {
                sceVu0CopyVector((void *)((u8 *)&stackFrame_B0[0]), (void *)(s1 + 0x40));
            }
            {
                float distance, farLimit, start, phase;
                distance=Math_GetDist((float *)stackFrame_B0,(float *)(lpDrawMng+0x230));
                farLimit=*(float *)SFX_GetSettingData();
                start=*(float *)(SFX_GetSettingData()+4);
                phase=(distance-start)/(farLimit-start);
                if (0.0f<phase && phase<1.0f) {
                    farLimit=SfxCalc_Sin(3.1415927f*phase);
                    f0=powf(farLimit,*(float *)(SFX_GetSettingData()+8));
                    *(float *)(s1+0x7c)=*(float *)(s1+0x7c)*f0;
                } else *(u32 *)(s1+0x7c)=0;
            }
        }
        a0_2 = (void *)*(s32 *)(s1 + 0xa0);
        v1 = 0x7fffffff;
        if ((u32)(s32)a0_2 != v1) {
            v1 = (s32)((u8 *)a0_2 + -1);
            *(u32 *)(s1 + 0xa0) = v1;
        }
        v1 = *(s32 *)(s1 + 0xa4);
        v1 = v1 + 1;
        *(u32 *)(s1 + 0xa4) = v1;
        a0_2 = (void *)*(u16 *)(s0 + 0x3c);
        if ((u32)a0_2 != 0 && (u32)a0_2 <= (u32)*(s32 *)(s1 + 0xa4)) {
            *(u32 *)(s1 + 0xa4) = 0;
        }
        s1 = (u8 *)*(s32 *)(s1 + 0xa8);
    }
    s2 += 1;
    while (1) {
        _L001B7050:;
        v1 = *(u8 *)(s3 + 0x46);
        a0_2 = (void *)s2;
        if ((s32)a0_2 >= (s32)v1) {
            break;
        }
        if ((u32)(s32)s1 != 0) {
            goto _L001B6900;
        }
        break;
    }
    *(u32 *)(s3 + 0x48) = (s32)s7;
    *(u8 *)(s3 + 0x46) = (s32)s5;
    return;
}
void __SFX_DrawSprite2(void *a0 /* r4 */) {
    u8 *p_sfx;
    u8 *p_fix_param;
    u8 *p_ptcl;
    u_long128 sb;
    u8 *pSfxSetting;
    int bOut;
    int bLowAlpha;
    float scaleX;
    float scaleY;
    float pos[4] __attribute__((aligned(16)));
    float scale[4] __attribute__((aligned(16)));

    p_fix_param = (u8 *)*(s32 *)((u8 *)a0 + 0x4c);
    p_ptcl = (u8 *)*(s32 *)((u8 *)a0 + 0x48);
    p_sfx = (u8 *)a0;
    if (*(u16 *)p_fix_param > 0) {
        sb = SfxDraw_GetRenderStateBlock();
        SfxDraw_SetBlendType(*(u8 *)(p_fix_param + 0x39));
        SfxDraw_SetTexture((void *)*(s32 *)(p_sfx + 0x80));
        SfxDraw_EnableFog(*(u8 *)(p_fix_param + 0x38));
        SfxDraw_UseTexture(1);
        SfxDraw_EnableZTest(*(u8 *)(p_fix_param + 0x3e));
        SfxDraw_UseST(1);
        while (p_ptcl != 0) {
            if (*(s32 *)(p_sfx + 0x40) != 0) {
                sceVu0ApplyMatrix(pos, (void *)*(s32 *)(p_sfx + 0x40), p_ptcl + 0x40);
            } else {
                sceVu0CopyVector(pos, p_ptcl + 0x40);
            }
            pSfxSetting = (u8 *)SFX_GetSettingData();
            bOut = !(0 < (u32)SfxCalc_CheckInsightCamera(pos));
            bLowAlpha = *(float *)(p_ptcl + 0x7c) < *(float *)(pSfxSetting + 0xc);
            if (bOut != 0 || bLowAlpha != 0) {
                return;
            }
            a0 = (void *)*(s32 *)(p_sfx + 0x40);
            if ((u32)a0 != 0) {
                scaleY = sqrtf(sceVu0InnerProduct(a0, a0));
                a0 = (u8 *)*(void **)(p_sfx + 0x40) + 16;
                {
                    float y = sqrtf(sceVu0InnerProduct(a0, a0));
                    scale[0] = *(float *)(p_ptcl + 0x60) * scaleY;
                    scale[1] = *(float *)(p_ptcl + 0x64) * y;
                    scale[2] = 1.0f;
                    scale[3] = 0.0f;
                }
            } else {
                sceVu0CopyVector(scale, p_ptcl + 0x60);
            }
            SfxDraw_SetColor(((u32)(128.0f * *(float *)(p_ptcl + 0x70)) << 24) + ((u32)(128.0f * *(float *)(p_ptcl + 0x74)) << 16) + ((u32)(128.0f * *(float *)(p_ptcl + 0x78)) << 8) + (u32)(128.0f * *(float *)(p_ptcl + 0x7c)));
            if (((struct { signed char reflect:1; } *)(s_mngp + 60))->reflect != 0) {
                scale[1] *= -1.0f;
            }
            SfxDraw_DrawSprite_Wld2(pos, scale, *(float *)(p_ptcl + 0x58), 0, *(float *)(p_fix_param + 0x34));
            p_ptcl = (u8 *)*(s32 *)(p_ptcl + 0xa8);
        }
        SfxDraw_SetRenderStateBlock(sb);
    }
}



void __SFX_DrawPtclSprite2(void *particle)
{
    u8 *saved;
    s32 matrix;
    u8 *object;
    u8 *params;
    u8 *settings;
    u32 outside;
    s32 below;
    float limit;
    u32 value;
    float alpha;
    u8 *texture;
    u_long128 state;
    float xscale;
    void *ptr;
    float position[4] __attribute__((aligned(16)));
    float scale[4] __attribute__((aligned(16)));
    object = (u8 *)*(s32 *)((u8 *)particle + 0xac);
    params = (u8 *)*(s32 *)(object + 0x4c);
    saved = particle;
    if (((struct { signed char reflect:1; } *)(s_mngp + 0x3c))->reflect != 0 &&
        !SFX_ConfirmReflect((void *)*(u16 *)(object + 0x6e),0)) goto finished;
    matrix = *(s32 *)(object + 0x40);
    if (matrix) sceVu0ApplyMatrix(position,(void *)matrix,saved+0x40);
    else sceVu0CopyVector(position,saved+0x40);
    settings = (u8 *)SFX_GetSettingData();
    outside = !(0 < (u32)SfxCalc_CheckInsightCamera(position));
    below = *(float *)(saved + 0x7c) < *(float *)(settings + 12);
    if (outside != 0 || below != 0) return;
    texture = (u8 *)*(s32 *)(object + 0x80);
    state = SfxDraw_GetRenderStateBlock();
    SfxDraw_SetBlendType(*(u8 *)(params + 0x39));
    SfxDraw_SetTexture(texture);
    SfxDraw_EnableFog(*(u8 *)(params + 0x38));
    SfxDraw_UseTexture(1);
    SfxDraw_EnableZTest(*(u8 *)(params + 0x3e));
    SfxDraw_UseST(1);
    ptr = (void *)*(s32 *)(object + 0x40);
    if (ptr) {
        alpha = sceVu0InnerProduct(ptr,ptr);
        value = *(s32 *)(object + 0x40);
        __asm__("sqrt.s %0,%1" : "=f"(xscale) : "f"(alpha));
        ptr = (void *)(value + 16);
        alpha = sceVu0InnerProduct(ptr,ptr);
        __asm__("sqrt.s %0,%1" : "=f"(limit) : "f"(alpha));
        scale[0] = *(float *)(saved + 0x60) * xscale;
        alpha = *(float *)(saved + 0x64) * limit;
        scale[2] = 1.0f;
        scale[3] = 0;
        scale[1] = alpha;
    } else sceVu0CopyVector(scale,saved+0x60);
    {
        struct dcomp_uv uv __attribute__((aligned(16))) = dcomp_uv_data;
        if (((struct { signed char reflect:1; } *)(s_mngp + 0x3c))->reflect != 0) scale[1] *= -1.0f;
        SfxDraw_DrawSprite_Wld(position,scale,*(float *)(saved+0x58),saved+0x70,uv.f,*(float *)(params+0x34));
        SfxDraw_SetRenderStateBlock(state);
    }
finished:
    return;
}
void __SFX_InitDistortion(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    u8 *s5;
    u8 *s4;
    u8 *s3;
    u32 v1;
    s32 s2;
    u8 *s1;
    float f4;
    float f2;
    float f1;
    u32 v0;
    u16 s0;
    float r;
    void *a0_2;
    void *a1_2;

    s5 = (u8 *)a0;
    s4 = (u8 *)a1;
    v0 = *(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571) = v0;
    v0 = *(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20) = v0;
    sceVu0UnitMatrix(a0);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7) = *(float *)(s4 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9) = *(float *)(s4 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0) = *(float *)(s4 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2);
    dcomp_cop2_9397A3F6B7((void *)((u8 *)s5), (void *)((u8 *)s5), (void *)((u8 *)s4));
    sceVu0CopyVector((void *)(s5 + 0x30), (void *)(s4 + 0x40));
    v0 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24);
    if (v0 != 0) {
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) = v0;
    } else {
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) = 0;
    }
    s3 = (u8 *)*(s32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571);
    v0 = *(s16 *)s3;
    *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD) = v0;
    v0 = (u32)_AllocPtcl((signed int)*(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A));
    *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087) = v0;
    v1 = *(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
    s1 = (u8 *)*(s32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    s2 = 0;
    if (0 < (s32)v1) {
        do {
            if ((u32)(s32)s1 == 0) {
                break;
            }
            v0 = *(s16 *)s3;
            if ((s32)v0 < 0) {
                *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = 0x7fffffff;
            } else {
                r = (float)(u16)SfxCalc_RandU32() * 1.5259022e-05f;
                *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = (u32)((float)*(s16 *)s3 + (float)*(u16 *)(s3 + 2) * (r - 0.5f));
            }
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F) = (s32)(100.0f * (r - 0.5f));
            v0 = SfxCalc_RandU32();
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E) = (*(float *)(s3
                + 0x14) + (*(float *)(s3 + 0x18) * ((1.5259022e-05f * (float)(float)(u32)(u16)v0) -
                0.5f)));
            v0 = SfxCalc_RandU32();
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9) = (*(float *)(s3
                + 0x1c) + (*(float *)(s3 + 0x20) * ((1.5259022e-05f * (float)(float)(u32)(u16)v0) -
                0.5f)));
            v0 = SfxCalc_RandU32();
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E) = (*(float *)(s3
                + 0x24) + (*(float *)(s3 + 0x28) * ((1.5259022e-05f * (float)(float)(u32)(u16)v0) -
                0.5f)));
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC) = 0;
            SfxCalc_RotateVector((float *)(s1 + 0x80), *(float *)(s4 +
                DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_0__5ED7228F), *(float *)(s4 +
                DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_1__A795EEE1), *(float *)(s4 +
                DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_2__3B661BD7));
            if (*(s32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) != 0) {
                sceVu0ApplyMatrix((void *)(s1 + 0x80), (void *)*(s32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B), (void *)(s1 + 0x80));
            } else {
                sceVu0CopyVector((void *)(s1 + 0x80), (void *)(s1 + 0x80));
            }
            SfxUtil_CalcRndPos((float *)(s1 + 0x40), *(u16 *)(s3 + 6), (float *)(s3 + 8));
            sceVu0AddVector((void *)(s1 + 0x40), (void *)(s1 + 0x40), (void *)(s4 + 0x40));
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED) = 0x3f800000;
            v0 = SfxFlicker_Create(3);
            s0 = v0;
            *(u16 *)(s1 + 0xb0) = v0;
            if ((u32)s0 != (u32)0xffff) {
                v0 = SfxCalc_RandU32();
                f4 = (float)(u32)(u16)v0;
                SfxFlicker_SetCycle(s0, (*(float *)(s3 + 0x2c) + (*(float *)(s3 + 0x30) *
                    ((1.5259022e-05f * f4) - 0.5f))));
            }
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510) = (u32)s5;
            v1 = *(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
            s2 = s2 + 1;
            v1 = s2 < (s32)v1;
            s1 = (u8 *)*(s32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76);
        } while (v1 != 0);
    }
    *(u8 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B) = s2;
    return;
}

void __SFX_ActDistortion(void *a0 /* r4 */, float f12 /* f12 */) {
    u8 *s4;
    u8 s3;
    u32 *s5;
    u8 *s2;
    u8 *s6;
    u8 *s7;
    float f20;
    u32 a3;
    u32 s1;
    u8 *s0;
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f1;
    float f0;
    u8 *a0_2;
    u8 stackFrame_BC[4] __attribute__((aligned(4)));
    u8 stackFrame_B8[4] __attribute__((aligned(4)));
    u8 stackFrame_B4[4] __attribute__((aligned(4)));
    u8 stackFrame_A0[20] __attribute__((aligned(16)));

    s7 = (u8 *)0;
    s6 = (u8 *)0;
    s5 = (u32 *)0;
    s4 = (u8 *)a0;
    s3 = 0;
    s2 = (u8 *)*(s32 *)(((u8 *)a0 + 0x48));
    f20 = (float)f12;
    goto _L001B5C68;
    _L001B5AA0:;
    v0 = *(s32 *)(s2 + 0xa0);
    s1 = *(s32 *)(s2 + 0xa4);
    s0 = (u8 *)(s2 + 0xb0);
    if (v0 == 0) {
        s0 = (u8 *)s2;
        if ((u32)s6 != 0) {
            v0 = *(s32 *)(s2 + 0xa8);
            *(u32 *)(s6 + 0xa8) = v0;
        }
        a0_2 = (u8 *)*(s32 *)(s0 + 0xac);
        v1 = s_mngp;
        v0 = (u32)s_FuncTable;
        a0_2 = (u8 *)*(u16 *)(a0_2 + 0x44);
        a0_2 = (u8 *)(s32)((u32)a0_2 << 2);
        v1 = *(s32 *)(u32)(s32)((u8 *)(u32)*(s32 *)((v1 + 0x10)) + (u32)(a0_2));
        a0_2 = (u8 *)*(s32 *)v1;
        v0 = (s32)((u8 *)s_FuncTable + (s32)((u32)((u32)(a0_2)) * (u32)(0x14)));
        v0 = *(s32 *)((v0 + 0x10));
        s2 = (u8 *)*(s32 *)(s2 + 0xa8);
        if (v0 != 0) {
            a0_2 = (u8 *)s0;
            ((void (*)(s32))(s32)v0)((s32)a0_2);
        }
        a0_2 = (u8 *)s0;
        a2 = 0xe0;
        memset((void *)a0_2, 0, a2);
        v1 = *(s32 *)((s_mngp + 0x30));
        *(u32 *)(s0 + 0xa8) = v1;
        v1 = s_mngp;
        *(u32 *)((v1 + 0x30)) = (s32)s0;
        a0_2 = (u8 *)s_mngp;
        v1 = *(s16 *)(a0_2 + 0x38);
        v1 = v1 + -1;
        *(u16 *)(a0_2 + 0x38) = v1;
    } else {
        if ((u32)s7 == 0) {
            s7 = (u8 *)s2;
        }
        s6 = (u8 *)s2;
        s5 = (u32 *)((u8 *)s5 + 1);
        sceVu0ScaleVector((void *)((u8 *)&stackFrame_A0[0]), (void *)(s2 + 0x80), (float)f20);
        a0_2 = (u8 *)(s2 + 0x40);
        sceVu0AddVector((void *)a0_2, (void *)a0_2, (void *)((u8 *)&stackFrame_A0[0]));
        v0 = *(s32 *)(s4 + 0x50);
        a1 = 6;
        a2 = 1;
        a3 = *(s32 *)((v0 + 4));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_BC[0]), a1, a2, (void *)a3, s1);
        f1 = *(float *)((u8 *)&stackFrame_BC[0]);
        f0 = 0.0f;
        if (!(0.0f == f1)) {
            *(f32 *)(s2 + 0x84) = (*(float *)(s2 + 0x84) + (f1 * f20));
        }
        a0_2 = (u8 *)*(u16 *)s0;
        v1 = 0xffff;
        if ((u32)a0_2 != v1) {
            v0 = *(s32 *)(s4 + 0x50);
            a1 = 6;
            a2 = 1;
            a3 = *(s32 *)((v0 + 0x14));
            SFX_GetSeqParam((void *)((u8 *)&stackFrame_B8[0]), a1, a2, (void *)a3, s1);
            v0 = *(s32 *)(s4 + 0x50);
            a1 = 6;
            a3 = *(s32 *)((v0 + 0xc));
            a2 = 1;
            SFX_GetSeqParam((void *)((u8 *)&stackFrame_B4[0]), a1, a2, (void *)a3, s1);
            a0_2 = (u8 *)*(u16 *)s0;
            SfxFlicker_SetScale((unsigned short)a0_2, *(float *)((u8 *)&stackFrame_B4[0]));
            a0_2 = (u8 *)*(u16 *)s0;
            SfxFlicker_SetAmplitude((unsigned short)a0_2, *(float *)((u8 *)&stackFrame_B8[0]));
            a0_2 = (u8 *)*(u16 *)s0;
            SfxFlicker_Action((unsigned short)a0_2, (float)f20);
        }
        a0_2 = (u8 *)*(s32 *)(s2 + 0xa4);
        v1 = 0x7fffffff;
        a0_2 = (u8 *)(a0_2 + 1);
        *(u32 *)(s2 + 0xa4) = (s32)a0_2;
        a0_2 = (u8 *)*(s32 *)(s2 + 0xa0);
        if ((u32)(s32)a0_2 != v1) {
            v1 = (s32)(a0_2 + -1);
            *(u32 *)(s2 + 0xa0) = v1;
        }
        s2 = (u8 *)*(s32 *)(s2 + 0xa8);
    }
    s3 += 1;
    while (1) {
        _L001B5C68:;
        v1 = *(u8 *)(s4 + 0x46);
        a0_2 = (u8 *)s3;
        if ((s32)a0_2 >= (s32)v1) {
            break;
        }
        if ((u32)(s32)s2 != 0) {
            goto _L001B5AA0;
        }
        break;
    }
    *(u32 *)(s4 + 0x48) = (s32)s7;
    *(u8 *)(s4 + 0x46) = (s32)s5;
    return;
}

static void __SFX_DrawDistortion(void *a0 /* r4 */) {
    u8 *s3;
    u32 s2;
    u_long128 v0_q;
    u_long128 s1;
    u8 s0;
    u32 v0;
    void *a0_2;

    s2 = *(s32 *)(((u8 *)a0 + 0x48));
    s3 = (u8 *)a0;
    if (s2 != 0) {
        v0_q = SfxDraw_GetRenderStateBlock();
        s1 = v0_q;
        a0_2 = (void *)(s32)1;
        SfxDraw_EnableZTest((signed int)a0_2);
        s0 = 0;
        goto _L001B5A08;
        _L001B59F0:;
        a0_2 = (void *)(s32)s2;
        __SFX_DrawPtclDistortion(a0_2);
        s2 = *(s32 *)((s2 + 0xa8));
        s0 += 1;
        while (1) {
            _L001B5A08:;
            v0 = *(u8 *)(s3 + 0x46);
            if ((s32)v0 <= (s32)s0) {
                break;
            }
            if (s2 != 0) {
                goto _L001B59F0;
            }
            break;
        }
        SfxDraw_SetRenderStateBlock(s1);
    }
    return;
}

static void __SFX_EndPtclDistortion(u16 *a0 /* r4 */, u8 *a1 /* r5 */, u32 *a2 /* r6 */) {
    u16 a0_narrow; // a0

    a0_narrow = *(u16 *)(((u8 *)a0 + 0xb0));
    if ((u32)a0_narrow != (u32)0xffff) {
        SfxFlicker_Delete(a0_narrow);
    }
    return;
}

static void __SFX_DrawPtclDistortion(void *a0 /* r4 */) {
    u8 *a2;
    u32 a1;
    u8 *s0;
    u16 a0_narrow; // a0
    u16 a0_narrow_; // a0
    s32 v1;
    u32 v0;
    u8 stackFrame_20[16] __attribute__((aligned(16)));

    v1 = 0xffff;
    a1 = *(u16 *)(((u8 *)a0 + 0xb0));
    a2 = (u8 *)*(s32 *)(((u8 *)a0 + 0xac));
    s0 = (u8 *)((u8 *)a0 + 0xb0);
    if (a1 != (u32)v1) {
        v1 = *(s8 *)(s_mng + 0x3c);
        if ((u64)((s64)((s64)((u64)((s64)v1) << 0x3f)) >> 0x3f) == 0) {
            a1 = *(s32 *)(a2 + 0x40);
            if (a1 != 0) {
                a2 = (u8 *)((u8 *)a0 + 0x40);
                sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_20[0]), (void *)a1, (void *)a2);
            } else {
                sceVu0CopyVector((void *)((u8 *)&stackFrame_20[0]), (void *)(u32)(s32)((u8 *)a0 +
                    0x40));
            }
            v0 = CheckPosOutOfSight((float *)((u8 *)&stackFrame_20[0]));
            if (v0 == 0) {
                a0_narrow_ = *(u16 *)s0;
                if ((u32)a0_narrow_ != (u32)0xffff) {
                    SfxFlicker_SetPos(a0_narrow_, (float *)((u8 *)&stackFrame_20[0]));
                    a0_narrow = *(u16 *)s0;
                    SfxFlicker_Draw(a0_narrow);
                }
            }
        }
    }
    return;
}
void __SFX_InitTracer(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    struct dw_1891466_fields *p_sfx = (struct dw_1891466_fields *)a0;
    struct dw_1890401_dsc *dsc = (struct dw_1890401_dsc *)a1;
    struct dw_1892300_dsc *p_param = (struct dw_1892300_dsc *)a2;
    struct dw_1899432_fields *p_fix_param;
    int i;
    struct dw_1890884_fields *p_ptcl;
    u8 *pTex;
    unsigned short hTracer;
    char szFilename[16];
    struct dw_1915845_fields params;
    u8 szFile[256] __attribute__((aligned(16)));
    float r;

    p_sfx->p_fix_param = (struct dw_1904865_fields *)p_param->pFixParam;
    p_sfx->p_seq_param = (struct dw_1905892_fields *)p_param->pSeqParam;
    sceVu0UnitMatrix(p_sfx);
    p_sfx->matrix[0][0] = dsc->scale[0];
    p_sfx->matrix[1][1] = dsc->scale[1];
    p_sfx->matrix[2][2] = dsc->scale[2];
    dcomp_cop2_9397A3F6B7((void *)p_sfx, (void *)p_sfx, (void *)dsc);
    sceVu0CopyVector(&p_sfx->matrix[3][0], dsc->loc);
    if (dsc->p_matrix != 0) {
        p_sfx->p_matrix = dsc->p_matrix;
    } else {
        p_sfx->p_matrix = (float (*)[4][4])MRX1;
    }
    p_fix_param = (struct dw_1899432_fields *)p_sfx->p_fix_param;
    p_sfx->lifecnt = p_fix_param->life;
    p_sfx->p_ptcl_top = (struct dw_1890884_fields *)_AllocPtcl(dsc->ptcl_num);
    p_ptcl = p_sfx->p_ptcl_top;
    for (i = 0; i < dsc->ptcl_num; i++) {
        if (p_ptcl == 0) {
            break;
        }
        if (p_fix_param->life < 0) {
            p_ptcl->lifecnt = 0x7fffffff;
        } else {
            p_ptcl->lifecnt = p_fix_param->life;
        }
        r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
        p_ptcl->rand[0] = (s32)(100.0f * (r - 0.5f));
        r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
        p_ptcl->rand[1] = (s32)(100.0f * (r - 0.5f));
        r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
        p_ptcl->rand[2] = (s32)(100.0f * (r - 0.5f));
        r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
        p_ptcl->rand[3] = (s32)(100.0f * (r - 0.5f));
        p_ptcl->n_speed[0] = 0.0f;
        p_ptcl->n_speed[1] = 0.0f;
        p_ptcl->n_speed[2] = 0.0f;
        p_ptcl->n_speed[3] = 0.0f;
        SfxCalc_RotateVector(p_ptcl->n_speed, dsc->ang[0], dsc->ang[1], dsc->ang[2]);
        sceVu0ApplyMatrix(p_ptcl->n_speed, p_sfx->p_matrix, p_ptcl->n_speed);
        sceVu0CopyVector(p_ptcl->loc, dsc->loc);
        sprintf(szFilename, (char *)"sfxt%03d.tm2", p_fix_param->model_id);
        pTex = (u8 *)GetTexMngByName(0, szFilename);
        params.type = p_fix_param->type;
        params.pTex = (struct dw_1896911_fields *)pTex;
        params.size = p_fix_param->size;
        params.length = p_fix_param->length;
        params.life = 0.0166666f * (float)p_fix_param->life;
        params.split = 0.02f;
        params.divH = p_fix_param->divH;
        params.divV = p_fix_param->divV;
        params.cut = p_fix_param->cut;
        params.alpha = p_fix_param->alpha;
        hTracer = SfxTracer_Create(&params);
        *(u16 *)((u8 *)p_ptcl + 0xb0) = hTracer;
        if (hTracer == 0xffff) {
            strcpy((char *)szFile, (char *)"PtclMng.c");
            SfxDbg_SetDebugMsg(0, (char *)"\x83\x67\x83\x8c\x81\x5b\x83\x54\x83\x49\x83\x75\x83\x57\x83\x46\x83\x4e\x83\x67\x82\xcc\x8d\xec\x90\xac\x82\xc9\x8e\xb8\x94\x73\x82\xb5\x82\xdc\x82\xb5\x82\xbd", (char *)szFile, 0xd58);
        }
        p_ptcl->pEmitter = p_sfx;
        p_ptcl = p_ptcl->p_sibling;
    }
    p_sfx->ptcl_num = i;
}
void __SFX_ActTracer(void *a0 /* r4 */, float f12 /* f12 */) {
    u8 *s4;
    u8 s3;
    u32 *s2;
    u8 *s1;
    u8 *s5;
    u32 *s6;
    float f20;
    u32 a2;
    u8 *s0;
    u32 a1;
    u32 v1;
    u32 v0;
    u8 *a0_2;
    float vAdd[4] __attribute__((aligned(16)));
    float pos0[4] __attribute__((aligned(16)));
    float mrx[4][4] __attribute__((aligned(16)));
    float qtn[4] __attribute__((aligned(16)));

    s6 = (u32 *)0;
    s5 = (u8 *)0;
    s4 = (u8 *)a0;
    s3 = 0;
    s2 = (u32 *)0;
    s1 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    f20 = (float)f12;
    goto _L001B53C8;
    _L001B5168:;
    v0 = *(s32 *)(s1 + 0xa0);
    s0 = (u8 *)(s1 + 0xb0);
    if (v0 == 0) {
        s0 = (u8 *)s1;
        if ((u32)s5 != 0) {
            v0 = *(s32 *)(s1 + 0xa8);
            *(u32 *)(s5 + 0xa8) = v0;
        }
        a0_2 = (u8 *)*(s32 *)(s0 + 0xac);
        v1 = s_mngp;
        v0 = (u32)s_FuncTable;
        a0_2 = (u8 *)*(u16 *)(a0_2 + 0x44);
        a0_2 = (u8 *)(s32)((u32)a0_2 << 2);
        v1 = *(s32 *)(u32)(s32)((u8 *)(u32)*(s32 *)((v1 + 0x10)) + (u32)(a0_2));
        a0_2 = (u8 *)*(s32 *)v1;
        v0 = (s32)((u8 *)s_FuncTable + (s32)((u32)((u32)(a0_2)) * (u32)(0x14)));
        v0 = *(s32 *)((v0 + 0x10));
        s1 = (u8 *)*(s32 *)(s1 + 0xa8);
        if (v0 != 0) {
            a0_2 = (u8 *)s0;
            ((void (*)(s32))(s32)v0)((s32)a0_2);
        }
        a0_2 = (u8 *)s0;
        memset((void *)a0_2, 0, 0xe0);
        v1 = *(s32 *)((s_mngp + 0x30));
        *(u32 *)(s0 + 0xa8) = v1;
        v1 = s_mngp;
        *(u32 *)((v1 + 0x30)) = (s32)s0;
        a0_2 = (u8 *)s_mngp;
        v1 = *(s16 *)(a0_2 + 0x38);
        v1 = v1 + -1;
        *(u16 *)(a0_2 + 0x38) = v1;
    } else {
        if ((u32)s6 == 0) {
            s6 = (u32 *)s1;
        }
        s5 = (u8 *)s1;
        s2 = (u32 *)((u8 *)s2 + 1);
        sceVu0ScaleVector((void *)((u8 *)&vAdd[0]), (void *)(s1 + 0x80), (float)f20);
        a0_2 = (u8 *)(s1 + 0x40);
        sceVu0AddVector((void *)a0_2, (void *)a0_2, (void *)((u8 *)&vAdd[0]));
        if (*(u16 *)s0 != 0xffff) {
            sceVu0ApplyMatrix((void *)pos0, (void *)s4, (void *)(s1 + 0x40));
            sceVu0ApplyMatrix((void *)pos0, (void *)*(s32 *)(s4 + 0x40), (void *)pos0);
            sceVu0RotMatrixZ((void *)mrx, (void *)MRX1, -3.1415927f);
            dcomp_cop2_9397A3F6B7((void *)mrx, (void *)s4, (void *)mrx);
            dcomp_cop2_9397A3F6B7((void *)mrx, (void *)*(s32 *)(s4 + 0x40), (void *)mrx);
            SfxCalc_QtnMakeFromMatrix((float *)qtn, (void *)mrx);
            SfxTracer_AddLog(*(u16 *)s0, (float *)pos0, (float *)qtn);
        }
        a0_2 = (u8 *)*(s32 *)(s1 + 0xa4);
        v1 = 0x7fffffff;
        a0_2 = (u8 *)(a0_2 + 1);
        *(u32 *)(s1 + 0xa4) = (s32)a0_2;
        a0_2 = (u8 *)*(s32 *)(s1 + 0xa0);
        if ((u32)(s32)a0_2 != v1) {
            v1 = (s32)(a0_2 + -1);
            *(u32 *)(s1 + 0xa0) = v1;
        }
        s1 = (u8 *)*(s32 *)(s1 + 0xa8);
    }
    s3 += 1;
    while (1) {
        _L001B53C8:;
        v1 = *(u8 *)(s4 + 0x46);
        a0_2 = (u8 *)s3;
        if ((s32)a0_2 >= (s32)v1) {
            break;
        }
        if ((u32)(s32)s1 != 0) {
            goto _L001B5168;
        }
        break;
    }
    *(u32 *)(s4 + 0x48) = (s32)s6;
    *(u8 *)(s4 + 0x46) = (s32)s2;
    return;
}

static void __SFX_EndPtclTracer(u16 *a0 /* r4 */, u8 *a1 /* r5 */, u32 *a2 /* r6 */) {
    u16 a0_narrow; // a0

    a0_narrow = *(u16 *)(((u8 *)a0 + 0xb0));
    if ((u32)a0_narrow != (u32)0xffff) {
        SfxTracer_Kill(a0_narrow);
    }
    return;
}
void __SFX_InitConnectedSprite(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    u8 *s4;
    u8 *s3;
    u8 *s2;
    u32 v1;
    u32 v0;
    u8 *s1;
    u8 s0;
    float f2;
    float f1;
    float r;
    void *a0_2;
    void *a1_2;
    void *a2_2;
    u8 stackFrame_60[32] __attribute__((aligned(16)));

    s4 = (u8 *)a0;
    s3 = (u8 *)a1;
    a1_2 = (void *)(char *)"sfxt%03d.tm2";
    s2 = (u8 *)*(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571) = (s32)s2;
    v0 = *(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20) = v0;
    sprintf((char *)((u8 *)&stackFrame_60[0]), (const char *)(char *)"sfxt%03d.tm2", (u32)*(u16 *)s2);
    v0 = (u32)GetTexMngByName((void *)0, (char *)((u8 *)&stackFrame_60[0]));
    *(u32 *)(s4 + 0x80) = v0;
    sceVu0UnitMatrix((void *)s4);
    *(f32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7) = *(float *)(s3 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D);
    *(f32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9) = *(float *)(s3 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01);
    *(f32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0) = *(float *)(s3 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2);
    dcomp_cop2_9397A3F6B7((void *)((u8 *)s4), (void *)((u8 *)s4), (void *)((u8 *)s3));
    a0_2 = (void *)(s4 + 0x30);
    a1_2 = (void *)(s3 + 0x40);
    sceVu0CopyVector(a0_2, a1_2);
    v0 = *(s32 *)(s3 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24);
    if (v0 != 0) {
        *(u32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) = v0;
    } else {
        v0 = (u32)MRX1;
        *(u32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) = (u32)MRX1;
    }
    v1 = *(s16 *)(s2 + 2);
    if ((s32)v1 < 0) {
        v0 = 0x7fffffff;
        *(u32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD) = 0x7fffffff;
    } else {
        v0 = *(u16 *)(s2 + 4);
        *(u32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD) = v1 + v0;
    }
    a0_2 = (void *)*(u16 *)(s3 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
    v0 = (u32)_AllocPtcl((signed int)a0_2);
    *(u32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087) = v0;
    v1 = *(u16 *)(s3 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
    s1 = (u8 *)*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    s0 = 0;
    if (0 < (s32)v1) {
        do {
            if ((u32)(s32)s1 == 0) {
                break;
            }
            v0 = *(s16 *)(s2 + 2);
            if ((s32)v0 < 0) {
                v0 = 0x7fffffff;
                *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = 0x7fffffff;
            } else {
                r = (float)(u16)SfxCalc_RandU32() * 1.5259022e-05f;
                *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = (u32)((float)*(s16 *)(s2 + 2) + (float)*(u16 *)(s2 + 4) * (r - 0.5f));
            }
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F) = (s32)(100.0f * (r - 0.5f));
            sceVu0CopyVector((void *)(s1 + 0x50), (void *)V0);
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E) = (*(float *)(s2
                + 0x14) + (*(float *)(s2 + 0x18) * (r -
                0.5f)));
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9) = (*(float *)(s2
                + 0x1c) + (*(float *)(s2 + 0x20) * (r -
                0.5f)));
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E) = (*(float *)(s2
                + 0x24) + (*(float *)(s2 + 0x28) * (r -
                0.5f)));
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC) = 0;
            SfxUtil_CalcRndPos((float *)(s1 + 0x40), *(u16 *)(s2 + 6), (float *)(s2 + 8));
            a0_2 = (void *)(s1 + 0x40);
            a2_2 = (void *)(s3 + 0x40);
            sceVu0AddVector(a0_2, (void *)a0_2, a2_2);
            v0 = 0x3f800000;
            a0_2 = (void *)(s1 + 0xb0);
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED) = 0x3f800000;
            a1_2 = (void *)(s1 + 0x40);
            sceVu0CopyVector(a0_2, a1_2);
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510) = (u32)s4;
            s0 += 1;
            v1 = *(u16 *)(s3 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
            v1 = (s32)s0 < (s32)v1;
            s1 = (u8 *)*(s32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76);
        } while (v1 != 0);
    }
    *(u8 *)(s4 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B) = s0;
    return;
}
void __SFX_ActConnectedSprite(void *a0 /* r4 */, float f12 /* f12 */) {
    u8 *s3;
    u8 s2;
    u32 *s1;
    u8 *s0;
    u8 *s5;
    u8 *s6;
    u32 *s7;
    u8 *s4;
    float f20;
    u32 *t0;
    u32 fp;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f0;
    void *a0_2;
    u8 stackFrame_16C[4] __attribute__((aligned(4)));
    u8 stackFrame_168[4] __attribute__((aligned(8)));
    u8 stackFrame_150[24] __attribute__((aligned(16)));
    float last_pos[4] __attribute__((aligned(16)));
    float scl[3][2] __attribute__((aligned(16)));
    float vAdd[4] __attribute__((aligned(16)));
    float tmp_vector[4] __attribute__((aligned(16)));
    u8 mrx[64] __attribute__((aligned(16)));
    float vt[4] __attribute__((aligned(16)));

    s7 = (u32 *)0;
    s6 = (u8 *)0;
    s5 = (u8 *)0;
    fp = (u32)MRX1;
    s3 = (u8 *)a0;
    s2 = 0;
    s1 = (u32 *)0;
    s0 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    f20 = (float)f12;
    goto _L001B4AB0;
    _L001B46F0:;
    v0 = *(s32 *)(s0 + 0xa0);
    s4 = (u8 *)*(s32 *)(s0 + 0xa4);
    if (v0 == 0) {
        s4 = (u8 *)s0;
        if ((u32)s5 != 0) {
            v0 = *(s32 *)(s0 + 0xa8);
            *(u32 *)(s5 + 0xa8) = v0;
        }
        a0_2 = (void *)*(s32 *)(s4 + 0xac);
        v1 = s_mngp;
        v0 = (u32)s_FuncTable;
        a0_2 = (void *)*(u16 *)(((u8 *)a0_2 + 0x44));
        a0_2 = (void *)(s32)((u32)a0_2 << 2);
        v1 = *(s32 *)(u32)(s32)((u8 *)(u32)*(s32 *)((v1 + 0x10)) + (u32)(a0_2));
        a0_2 = (void *)*(s32 *)v1;
        v0 = (s32)((u8 *)s_FuncTable + (s32)((u32)((u32)(a0_2)) * (u32)(0x14)));
        v0 = *(s32 *)((v0 + 0x10));
        s0 = (u8 *)*(s32 *)(s0 + 0xa8);
        if (v0 != 0) {
            a0_2 = (void *)s4;
            ((void (*)(s32))(s32)v0)((s32)a0_2);
        }
        a0_2 = (void *)s4;
        memset(a0_2, 0, 0xe0);
        v1 = *(s32 *)((s_mngp + 0x30));
        *(u32 *)(s4 + 0xa8) = v1;
        v1 = s_mngp;
        *(u32 *)((v1 + 0x30)) = (s32)s4;
        a0_2 = (void *)s_mngp;
        v1 = *(s16 *)(((u8 *)a0_2 + 0x38));
        v1 = v1 + -1;
        *(u16 *)(((u8 *)a0_2 + 0x38)) = v1;
    } else {
        if ((u32)s6 == 0) {
            s6 = (u8 *)s0;
        }
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 6;
        a2 = 2;
        s5 = (u8 *)s0;
        a3 = *(s32 *)((v0 + 0xc));
        s1 = (u32 *)((u8 *)s1 + 1);
        SFX_GetSeqParam((void *)((u8 *)&scl[0]), a1, a2, (void *)a3, (s32)s4);
        a2 = *(s8 *)(s0 + 0x9c);
        v0 = 0x3c230000;
        v1 = 0x3c230000 | 0xd70a;
        f0 = (scl[0][0] + (scl[0][1] * (0.01f * (float)((float)(s32)a2))));
        *(f32 *)(s0 + 0x64) = f0;
        *(f32 *)(s0 + 0x60) = f0;
        sceVu0CopyVector((void *)((u8 *)&last_pos[0]), (void *)(s0 + 0x40));
        sceVu0ScaleVector((void *)((u8 *)&vAdd[0]), (void *)(s0 + 0x80), (float)f20);
        a0_2 = (void *)(s0 + 0x40);
        sceVu0AddVector(a0_2, (void *)a0_2, (void *)((u8 *)&vAdd[0]));
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 6;
        a2 = 1;
        a3 = *(s32 *)((v0 + 4));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_16C[0]), a1, a2, (void *)a3, (s32)s4);
        f0 = *(float *)((u8 *)&stackFrame_16C[0]);
        if (!(0.0f == f0)) {
            if ((u32)s7 == 0) {
                a1 = *(s32 *)(s3 + 0x40);
                fsvu0_MulMatrix((void *)mrx, (void *)a1, (void *)s3);
                SfxCalc_Vector2Angle((float *)((u8 *)&tmp_vector[0]), (float *)(mrx + 0x8));
                f0 = tmp_vector[1];
                sceVu0RotMatrixY((void *)mrx, (void *)fp, (-f0));
                f0 = tmp_vector[0];
                sceVu0RotMatrixX((void *)mrx, (void *)mrx, (-f0));
                v0 = (u32)VY;
                dcomp_cop2_21F95D43C1((void *)stackFrame_150, (void *)mrx, (void *)VY);
                s7 = (u32 *)(s32)1;
            }
            f0 = *(float *)((u8 *)&stackFrame_16C[0]);
            sceVu0ScaleVector((void *)((u8 *)&vt[0]), (void *)((u8 *)&stackFrame_150[0]), (f0 *
                f20));
            a0_2 = (void *)(s0 + 0x80);
            sceVu0AddVector(a0_2, (void *)((u8 *)&vt[0]), (void *)a0_2);
        }
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 1;
        a2 = 3;
        a3 = *(s32 *)((v0 + 0x14));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_168[0]), a1, a2, (void *)a3, (s32)s4);
        f0 = ((float)(float)(u32)*(u8 *)((u8 *)&stackFrame_168[0]) / 128.0f);
        *(f32 *)(s0 + 0x70) = f0;
        f0 = ((float)(float)(u32)((u8 *)stackFrame_168)[1] / 128.0f);
        *(f32 *)(s0 + 0x74) = f0;
        a1 = 1;
        f0 = ((float)(float)(u32)((u8 *)stackFrame_168)[2] / 128.0f);
        *(f32 *)(s0 + 0x78) = f0;
        v0 = *(s32 *)(s3 + 0x50);
        a3 = *(s32 *)((v0 + 0x1c));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_168[0] + 0x3), a1, a1, (void *)a3, (s32)s4);
        v0 = (u32)((u8 *)&stackFrame_168[0] + 0x3);
        v0 = *(u8 *)v0;
        *(f32 *)(s0 + 0x7c) = ((float)(float)v0 / 128.0f);
        sceVu0CopyVector((void *)(s0 + 0xb0), (void *)((u8 *)&last_pos[0]));
        a0_2 = (void *)*(s32 *)(s0 + 0xa0);
        v1 = 0x7fffffff;
        if ((u32)(s32)a0_2 != v1) {
            v1 = (s32)((u8 *)a0_2 + -1);
            *(u32 *)(s0 + 0xa0) = v1;
        }
        v1 = *(s32 *)(s0 + 0xa4);
        v1 = v1 + 1;
        *(u32 *)(s0 + 0xa4) = v1;
        s0 = (u8 *)*(s32 *)(s0 + 0xa8);
    }
    s2 += 1;
    while (1) {
        _L001B4AB0:;
        v1 = *(u8 *)(s3 + 0x46);
        a0_2 = (void *)s2;
        if ((s32)a0_2 >= (s32)v1) {
            break;
        }
        if ((u32)(s32)s0 != 0) {
            goto _L001B46F0;
        }
        break;
    }
    *(u32 *)(s3 + 0x48) = (s32)s6;
    *(u8 *)(s3 + 0x46) = (s32)s1;
    return;
}


/* __SFX_DrawConnectedSprite @ 0x1B4600 .. 0x1B4688 (0x88 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   cfg: kept goto: 0x1b462c -> .L001B4650
 *   cfg: loop body is not one contiguous region: .L001B4650
 *   cfg: kept branch: 0x1b4664 if (..) goto .L001B4638
 *   a1 typed from the __SFX_DrawConnectedSprite call table
 *   a2 typed from the __SFX_DrawConnectedSprite call table
 *   declaration vs inferred signature: return void vs inferred u8
 */

static void __SFX_DrawConnectedSprite(void *a0 /* r4 */) {
    u8 *s0;
    u8 s2;
    u32 s1;
    u32 v1;

    v1 = *(s32 *)(((u8 *)a0 + 0x4c));
    s1 = *(s32 *)(((u8 *)a0 + 0x48));
    v1 = *(u16 *)v1;
    s0 = (u8 *)a0;
    if ((s32)v1 > 0 && s1) {
        s2 = 0;
        goto _L001B4650;
        _L001B4638:;
        a0 = (void *)(s32)s1;
        __SFX_DrawPtclConnectedSprite(a0);
        s1 = *(s32 *)((s1 + 0xa8));
        s2 += 1;
        while (1) {
            _L001B4650:;
            v1 = *(u8 *)(s0 + 0x46);
            a0 = (void *)s2;
            if ((s32)a0 >= (s32)v1) {
                break;
            }
            if (s1 != 0) {
                goto _L001B4638;
            }
            break;
        }
    }
    return;
}

void __SFX_DrawPtclConnectedSprite(void *a0 /* r4 */) {
    u8 *s3;
    u8 *a2;
    u8 *s2;
    u8 *s1;
    u8 *s0;
    u32 a1;
    u32 v0;
    float f12;
    float f20;
    float f1;
    u_long128 v0_q;
    u_long128 s2_q;
    float f0;
    void *a0_2;
    u8 stackFrame_90[16] __attribute__((aligned(16)));
    u8 stackFrame_80[16] __attribute__((aligned(16)));
    u8 stackFrame_70[16] __attribute__((aligned(16)));
    u8 stackFrame_60[16] __attribute__((aligned(16)));

    s3 = (u8 *)a0;
    v0 = s_mngp;
    s2 = (u8 *)*(s32 *)(((u8 *)a0 + 0xac));
    v0 = *(s8 *)((v0 + 0x3c));
    s1 = (u8 *)*(s32 *)(s2 + 0x4c);
    s0 = (u8 *)(s3 + 0xb0);
    if ((u64)((s64)((u64)((s64)(s32)v0) << 0x3f) >> 0x3f) != 0) {
        a0_2 = (void *)*(u16 *)(s2 + 0x6e);
        v0 = SFX_ConfirmReflect(a0_2, 0);
        if (v0 == 0) {
            goto _L001B45E0;
        }
    }
    a1 = *(s32 *)(s2 + 0x40);
    if (a1 != 0) {
        sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_90[0]), (void *)a1, (void *)(s3 + 0x40));
        a1 = *(s32 *)(s2 + 0x40);
        sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_80[0]), (void *)a1, (void *)s0);
    } else {
        sceVu0CopyVector((void *)((u8 *)&stackFrame_90[0]), (void *)(s3 + 0x40));
        sceVu0CopyVector((void *)((u8 *)&stackFrame_80[0]), (void *)s0);
    }
    v0 = SfxCalc_CheckInsightCamera((float *)((u8 *)&stackFrame_90[0]));
    if (v0 != 0) {
        v0 = SfxCalc_CheckInsightCamera((float *)((u8 *)&stackFrame_80[0]));
        if (v0 != 0) {
            goto _L001B44F8;
        }
    }
    return;
    _L001B44F8:;
    a0_2 = (void *)*(s32 *)(s2 + 0x40);
    s0 = (u8 *)*(s32 *)(s2 + 0x80);
    if ((u32)(s32)a0_2 != 0) {
        f0 = sceVu0InnerProduct(a0_2, (void *)a0_2);
        v0 = *(s32 *)(s2 + 0x40);
        f20 = ({ float native_result_0; __asm__("sqrt.s %0,%1" : "=f"(native_result_0) : "f"(f0));
            native_result_0; });
        a0_2 = (void *)(s32)(v0 + 0x10);
        f0 = sceVu0InnerProduct(a0_2, (void *)a0_2);
        f1 = ({ float native_result_1; __asm__("sqrt.s %0,%1" : "=f"(native_result_1) : "f"(f0));
            native_result_1; });
        v0 = 0x3f800000;
        *(f32 *)((u8 *)&stackFrame_70[0]) = (*(float *)(s3 + 0x60) * f20);
        f0 = (*(float *)(s3 + 0x64) * f1);
        ((u32 *)stackFrame_70)[2] = 0x3f800000;
        ((u32 *)stackFrame_70)[3] = 0;
        ((f32 *)stackFrame_70)[1] = f0;
    } else {
        sceVu0CopyVector((void *)((u8 *)&stackFrame_70[0]), (void *)(s3 + 0x60));
    }
    v0_q = SfxDraw_GetRenderStateBlock();
    s2_q = v0_q;
    SfxDraw_UseTexture(1);
    a0_2 = (void *)*(u8 *)(s1 + 0x30);
    SfxDraw_SetBlendType((unsigned short)a0_2);
    a0_2 = (void *)s0;
    SfxDraw_SetTexture(a0_2);
    f12 = 0.0833330005f;
    sceVu0ScaleVector((void *)((u8 *)&stackFrame_60[0]), (void *)(s3 + 0x80), 0.0833330005f);
    a2 = ((u8 *)&stackFrame_60[0]);
    sceVu0SubVector((void *)((u8 *)&stackFrame_60[0]), (void *)((u8 *)&stackFrame_90[0]), (void
        *)a2);
    SfxDraw_DrawSprite_Wld2Pt((float *)((u8 *)&stackFrame_90[0]), (float *)((u8
        *)&stackFrame_60[0]), *(float *)((u8 *)&stackFrame_70[0]), (void *)(s3 + 0x70), *(float
        *)(s1 + 0x2c));
    SfxDraw_SetRenderStateBlock(s2_q);
    _L001B45E0:;
    return;
}


/* __SFX_EndPtclConnectedSprite @ 0x1B4420 .. 0x1B4428 (0x8 bytes) */
/*
 * dcomp notes:
 *   a0 typed from the __SFX_EndPtclConnectedSprite call table
 *   a1 typed from the __SFX_EndPtclConnectedSprite call table
 *   a2 typed from the __SFX_EndPtclConnectedSprite call table
 */

static void __SFX_EndPtclConnectedSprite(u8 *a0 /* r4 */, u8 *a1 /* r5 */, u32 *a2 /* r6 */) {
    return;
}
void __SFX_InitAnimSprite(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    u8 *s5;
    u8 *s4;
    u8 *s3;
    u32 v1;
    u8 *s2;
    u8 s1;
    float f3;
    float f2;
    float f1;
    u32 v0;
    u8 *s0;
    float f20;
    float r;
    void *a0_2;
    void *a1_2;

    v0 = (u32)s_aTexMng;
    s5 = (u8 *)a0;
    s4 = (u8 *)a1;
    s3 = (u8 *)*(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571) = (s32)s3;
    v1 = *(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20) = v1;
    v1 = *(u16 *)s3;
    v0 = *(s32 *)(u32)(s32)(u32)&((struct { u8 b[4]; } *)s_aTexMng)[v1];
    *(u32 *)(((u8 *)a0 + 0x80)) = v0;
    sceVu0UnitMatrix(a0);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7) = *(float *)(s4 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9) = *(float *)(s4 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0) = *(float *)(s4 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2);
    dcomp_cop2_9397A3F6B7((void *)((u8 *)s5), (void *)((u8 *)s5), (void *)((u8 *)s4));
    a0_2 = (void *)(s5 + 0x30);
    a1_2 = (void *)(s4 + 0x40);
    sceVu0CopyVector(a0_2, a1_2);
    v0 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24);
    if (v0 != 0) {
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) = v0;
    } else {
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) = 0;
    }
    v1 = *(s16 *)(s3 + 2);
    if ((s32)v1 < 0) {
        v0 = 0x7fffffff;
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD) = 0x7fffffff;
    } else {
        v0 = *(u16 *)(s3 + 4);
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD) = v1 + v0;
    }
    a0_2 = (void *)*(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
    v0 = (u32)_AllocPtcl((signed int)a0_2);
    *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087) = v0;
    v1 = *(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
    s2 = (u8 *)*(s32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    s1 = 0;
    if (0 < (s32)v1) {
        do {
            if ((u32)(s32)s2 == 0) {
                break;
            }
            v0 = *(s16 *)(s3 + 2);
            if ((s32)v0 < 0) {
                v0 = 0x7fffffff;
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = 0x7fffffff;
            } else {
                r = (float)(u16)SfxCalc_RandU32() * 1.5259022e-05f;
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = (u32)((float)*(s16 *)(s3 + 2) + (float)*(u16 *)(s3 + 4) * (r - 0.5f));
            }
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F) = (s32)(100.0f * (r - 0.5f));
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_0__D25AFE8C) = 0;
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_1__C6D2CBBE) = 0;
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            f3 = r;
            v0 = 0x3c8e0000;
            v1 = 0x3c8e0000 | 0xf34d;
            v0 = 0x3f800000;
            *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_2__3D0AAEDE) = (0.01745f *
                (*(float *)(s3 + 0x24) + (*(float *)(s3 + 0x28) * (f3 - 0.5f))));
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ANG_3__500368EC) = 0x3f800000;
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E) = (*(float *)(s3
                + 0x2c) + (*(float *)(s3 + 0x30) * (r -
                0.5f)));
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9) = (*(float *)(s3
                + 0x34) + (*(float *)(s3 + 0x38) * (r -
                0.5f)));
            v0 = SfxCalc_RandU32();
            *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E) = (*(float *)(s3
                + 0x3c) + (*(float *)(s3 + 0x40) * ((1.5259022e-05f * (float)(float)(u32)(u16)v0) -
                0.5f)));
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC) = 0;
            SfxUtil_CalcRndPos((float *)(s2 + 0x40), *(u16 *)(s3 + 6), (float *)(u8 *)(s3 + 8));
            a0_2 = (void *)(s2 + 0x40);
            sceVu0AddVector(a0_2, (void *)(u32)(s32)a0_2, (void *)(u8 *)(s4 + 0x40));
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED) = 0x3f800000;
            v1 = *(u8 *)(s3 + DCOMP_OFF_STRUCT_DW_1904865_FIELDS__79__CDUMMY_E7F7B9D7);
            s0 = (u8 *)(s2 + 0xb0);
            if (v1 != 0) {
                f20 = (float)(*(u8 *)(s3 + 0x49) * *(u8 *)(s3 + 0x4a));
                r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
                *(u8 *)(s0 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_EXTRA_DATA_0__72E3C7F7) = (u32)(f20
                    * r);
            } else {
                *(u8 *)(s0 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_EXTRA_DATA_0__72E3C7F7) = 0;
            }
            s1 += 1;
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510) = (u32)s5;
            s2 = (u8 *)*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76);
        } while ((s32)s1 < (s32)*(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A));
    }
    *(u8 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B) = s1;
    return;
}
void __SFX_ActAnimSprite(void *a0 /* r4 */, float f12 /* f12 */) {
    u8 *s3;
    u32 t0;
    u8 s2;
    u32 *s5;
    u8 *s1;
    u8 *s6;
    u8 *s7;
    u8 *s0;
    float f20;
    s32 fp;
    u8 *s4;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f2;
    float f1;
    float f0;
    void *a0_2;
    u8 *pEx;
    void *pMrx1;
    void *pm;
    u8 stackFrame_18C[4] __attribute__((aligned(4)));
    u8 stackFrame_188[4] __attribute__((aligned(4)));
    u8 stackFrame_184[4] __attribute__((aligned(4)));
    float ang[3] __attribute__((aligned(8)));
    u8 stackFrame_160[24] __attribute__((aligned(16)));
    float scl[3][2] __attribute__((aligned(16)));
    float vAdd[4] __attribute__((aligned(16)));
    float tmp_vector[4] __attribute__((aligned(16)));
    u8 mrx[64] __attribute__((aligned(16)));
    float vt[4] __attribute__((aligned(16)));

    fp = 0;
    s7 = (u8 *)0;
    s6 = (u8 *)0;
    s5 = (u32 *)0;
    s3 = (u8 *)a0;
    s1 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    s2 = 0;
    f20 = (float)f12;
    s0 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571);
    pMrx1 = (void *)MRX1;
    goto _L001B3CA8;
    _L001B3578:;
    s4 = (u8 *)*(s32 *)(s1 + 0xa4);
    pEx = s1 + 0xb0;
    v0 = *(s32 *)(s1 + 0xa0);
    if (v0 == 0) {
        s4 = (u8 *)s1;
        if ((u32)s6 != 0) {
            v0 = *(s32 *)(s1 + 0xa8);
            *(u32 *)(s6 + 0xa8) = v0;
        }
        a0_2 = (void *)*(s32 *)(s4 + 0xac);
        v1 = s_mngp;
        v0 = (u32)s_FuncTable;
        a0_2 = (void *)*(u16 *)(((u8 *)a0_2 + 0x44));
        a0_2 = (void *)(s32)((u32)a0_2 << 2);
        v1 = *(s32 *)(u32)(s32)((u8 *)(u32)*(s32 *)((v1 + 0x10)) + (u32)(a0_2));
        a0_2 = (void *)*(s32 *)v1;
        v0 = (s32)((u8 *)s_FuncTable + (s32)((u32)((u32)(a0_2)) * (u32)(0x14)));
        v0 = *(s32 *)((v0 + 0x10));
        s1 = (u8 *)*(s32 *)(s1 + 0xa8);
        if (v0 != 0) {
            a0_2 = (void *)s4;
            ((void (*)(s32))(s32)v0)((s32)a0_2);
        }
        a0_2 = (void *)s4;
        memset(a0_2, 0, 0xe0);
        v1 = *(s32 *)((s_mngp + 0x30));
        *(u32 *)(s4 + 0xa8) = v1;
        v1 = s_mngp;
        *(u32 *)((v1 + 0x30)) = (s32)s4;
        a0_2 = (void *)s_mngp;
        v1 = *(s16 *)(((u8 *)a0_2 + 0x38));
        v1 = v1 + -1;
        *(u16 *)(((u8 *)a0_2 + 0x38)) = v1;
    } else {
        if ((u32)s7 == 0) {
            s7 = (u8 *)s1;
        }
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 6;
        a2 = 3;
        s6 = (u8 *)s1;
        a3 = *(s32 *)((v0 + 0x14));
        s5 = (u32 *)((u8 *)s5 + 1);
        SFX_GetSeqParam((void *)((u8 *)&ang[0]), a1, a2, (void *)a3, (s32)s4);
        f1 = *(float *)(s1 + 0x58);
        f2 = ((*(volatile float *)&ang[2] * 0.01745f) * f20);
        {
            float angle = f1 + f2;
            *(float *)(s1 + 0x58) = angle;
            angle = (angle < -3.14159f || 3.14159f < angle) ? SfxCalc_IntoAngle_0_2PI(angle) - 6.28318f : angle;
            f12 = angle;
        }
        *(f32 *)(s1 + 0x58) = f12;
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 6;
        a2 = 2;
        a3 = *(s32 *)((v0 + 0x1c));
        SFX_GetSeqParam((void *)((u8 *)&scl[0]), a1, a2, (void *)a3, (s32)s4);
        v0 = *(u8 *)(s0 + 0x4e);
        if (v0 != 0) {
            f0 = (scl[0][0] + (scl[0][1] * (0.01f * (float)*(s8 *)(s1 + 0x9c))));
            *(f32 *)(s1 + 0x64) = f0;
            *(f32 *)(s1 + 0x60) = f0;
        } else {
            v0 = *(s32 *)(s3 + 0x50);
            a3 = *(s32 *)((v0 + 0x24));
            SFX_GetSeqParam((void *)((u8 *)&scl[0] + 0x8), 6, 2, (void *)a3, (s32)s4);
            *(f32 *)(s1 + 0x60) = (scl[0][0] + (scl[0][1] * (0.01f * (float)*(s8 *)(s1 + 0x9c))));
            *(f32 *)(s1 + 0x64) = (scl[1][0] + (scl[1][1] * (0.01f * (float)*(s8 *)(s1 + 0x9d))));
        }
        sceVu0ScaleVector((void *)((u8 *)&vAdd[0]), (void *)(s1 + 0x80), (float)f20);
        a0_2 = (void *)(s1 + 0x40);
        sceVu0AddVector(a0_2, (void *)a0_2, (void *)((u8 *)&vAdd[0]));
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 6;
        a2 = 1;
        a3 = *(s32 *)((v0 + 0xc));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_18C[0]), a1, a2, (void *)a3, (s32)s4);
        f0 = *(float *)((u8 *)&stackFrame_18C[0]);
        if (!(0.0f == f0)) {
            if ((u32)fp == 0) {
                pm = *(void **)(s3 + 0x40);
                if (pm != 0) {
                    dcomp_cop2_9397A3F6B7((void *)mrx, pm, (void *)s3);
                } else {
                    sceVu0CopyMatrix((void *)mrx, (void *)s3);
                }
                SfxCalc_Vector2Angle((float *)((u8 *)&tmp_vector[0]), (float *)(mrx + 0x8));
                f0 = tmp_vector[1];
                sceVu0RotMatrixY((void *)mrx, pMrx1, (-f0));
                f0 = tmp_vector[0];
                sceVu0RotMatrixX((void *)mrx, (void *)mrx, (-f0));
                dcomp_cop2_21F95D43C1((void *)stackFrame_160, (void *)mrx, (void *)VY);
                fp = 1;
            }
            f0 = *(float *)((u8 *)&stackFrame_18C[0]);
            sceVu0ScaleVector((void *)((u8 *)&vt[0]), (void *)((u8 *)&stackFrame_160[0]), (f0 *
                f20));
            a0_2 = (void *)(s1 + 0x80);
            sceVu0AddVector(a0_2, (void *)((u8 *)&vt[0]), (void *)a0_2);
        }
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 1;
        a2 = 3;
        a3 = *(s32 *)((v0 + 0x2c));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_188[0]), a1, a2, (void *)a3, (s32)s4);
        f0 = ((float)(float)(u32)*(u8 *)((u8 *)&stackFrame_188[0]) / 128.0f);
        *(f32 *)(s1 + 0x70) = f0;
        f0 = ((float)(float)(u32)((u8 *)stackFrame_188)[1] / 128.0f);
        *(f32 *)(s1 + 0x74) = f0;
        a1 = 1;
        a2 = a1;
        f0 = ((float)(float)(u32)((u8 *)stackFrame_188)[2] / 128.0f);
        *(f32 *)(s1 + 0x78) = f0;
        v0 = *(s32 *)(s3 + 0x50);
        a3 = *(s32 *)((v0 + 0x34));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_188[0] + 0x3), a1, a2, (void *)a3, (s32)s4);
        v1 = (u32)((u8 *)&stackFrame_188[0] + 0x3);
        f0 = ((float)(float)(u32)((u8 *)stackFrame_188)[3] / 128.0f);
        *(f32 *)(s1 + 0x7c) = f0;
        v1 = *(u8 *)(s0 + 0x49);
        if (0 < (s32)v1) {
            v0 = *(s32 *)(s3 + 0x50);
            a1 = 6;
            a3 = *(s32 *)((v0 + 0x3c));
            SFX_GetSeqParam((void *)((u8 *)&stackFrame_184[0]), a1, 1, (void *)a3, (s32)s4);
            {
                u32 cur;
                u32 th;
                u32 tw;
                s32 idx;
                tw = *(u8 *)(s0 + 0x49);
                cur = *(volatile u8 *)pEx;
                th = *(u8 *)(s0 + 0x4a);
                idx = (s32)(*(float *)((u8 *)&stackFrame_184[0]) + (float)cur);
                {
                    float fx = (float)(u16)(idx % (u16)tw);
                    *(f32 *)(s1 + 0x90) = fx * (1.0f / (float)tw);
                    fx = (float)(u16)((idx / (u16)tw) % (u16)th);
                    *(f32 *)(s1 + 0x94) = fx * (1.0f / (float)th);
                }
            }
        }
        a0_2 = (void *)*(s32 *)(s1 + 0xa0);
        v1 = 0x7fffffff;
        if ((u32)(s32)a0_2 != v1) {
            v1 = (s32)((u8 *)a0_2 + -1);
            *(u32 *)(s1 + 0xa0) = v1;
        }
        v1 = *(s32 *)(s1 + 0xa4);
        v1 = v1 + 1;
        *(u32 *)(s1 + 0xa4) = v1;
        a0_2 = (void *)*(u16 *)(s0 + 0x4c);
        if ((u32)a0_2 != 0 && (u32)a0_2 <= (u32)*(s32 *)(s1 + 0xa4)) {
            *(u32 *)(s1 + 0xa4) = 0;
        }
        s1 = (u8 *)*(s32 *)(s1 + 0xa8);
    }
    s2 += 1;
    while (1) {
        _L001B3CA8:;
        if ((s32)*(u8 *)(s3 + 0x46) <= (s32)s2) {
            break;
        }
        if ((u32)(s32)s1 != 0) {
            goto _L001B3578;
        }
        break;
    }
    *(u32 *)(s3 + 0x48) = (s32)s7;
    *(u8 *)(s3 + 0x46) = (s32)s5;
    return;
}


/* __SFX_DrawAnimSprite @ 0x1B3480 .. 0x1B3508 (0x88 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   cfg: kept goto: 0x1b34ac -> .L001B34D0
 *   cfg: loop body is not one contiguous region: .L001B34D0
 *   cfg: kept branch: 0x1b34e4 if (..) goto .L001B34B8
 *   a1 typed from the __SFX_DrawAnimSprite call table
 *   a2 typed from the __SFX_DrawAnimSprite call table
 *   declaration vs inferred signature: return void vs inferred u8
 */

static void __SFX_DrawAnimSprite(void *a0 /* r4 */) {
    u8 *s0;
    u8 s2;
    u32 s1;
    u32 v1;

    v1 = *(s32 *)(((u8 *)a0 + 0x4c));
    s1 = *(s32 *)(((u8 *)a0 + 0x48));
    v1 = *(u16 *)v1;
    s0 = (u8 *)a0;
    if ((s32)v1 > 0 && s1) {
        s2 = 0;
        goto _L001B34D0;
        _L001B34B8:;
        a0 = (void *)(s32)s1;
        __SFX_DrawPtclAnimSprite(a0);
        s1 = *(s32 *)((s1 + 0xa8));
        s2 += 1;
        while (1) {
            _L001B34D0:;
            v1 = *(u8 *)(s0 + 0x46);
            a0 = (void *)s2;
            if ((s32)a0 >= (s32)v1) {
                break;
            }
            if (s1 != 0) {
                goto _L001B34B8;
            }
            break;
        }
    }
    return;
}





void __SFX_DrawPtclAnimSprite(void *object) {
    u8 *saved;
    u8 *controller;
    u8 *params;
    u8 *setting;
    u32 outside;
    int below;
    u8 *texture;
    u_long128 state;
    float scale;
    float position[4] __attribute__((aligned(16)));
    float uv[4] __attribute__((aligned(16)));
    float size[4] __attribute__((aligned(16)));
    controller=*(u8 **)((u8 *)object+172);
    params=*(u8 **)(controller+76);
    saved=(u8 *)object;
    if(((struct { signed char reflect:1; } *)(s_mngp+60))->reflect!=0) {
        if(SFX_ConfirmReflect(*(u16 *)(controller+110),0)==0) return;
    }
    if(*(u32 *)(controller+64)!=0) sceVu0ApplyMatrix(position,*(void **)(controller+64),saved+64);
    else sceVu0CopyVector(position,saved+64);
    setting=(u8 *)SFX_GetSettingData();
    outside=!(0<(u32)SfxCalc_CheckInsightCamera(position));
    below=*(float *)(saved+124)<*(float *)(setting+12);
    if(outside!=0 || below!=0) return;
    texture=*(u8 **)(controller+128);
    state=SfxDraw_GetRenderStateBlock();
    SfxDraw_UseTexture(1);
    SfxDraw_SetBlendType(*(u8 *)(params+72));
    SfxDraw_SetTexture(texture);
    SfxDraw_EnableFog(*(u8 *)(params+75));
    SfxDraw_UseST(1);
    uv[0]=*(float *)(saved+144); uv[1]=*(float *)(saved+148);
    uv[2]=*(float *)(saved+144)+1.0f/(float)*(u8 *)(params+73);
    uv[3]=*(float *)(saved+148)+1.0f/(float)*(u8 *)(params+74);
    object=*(void **)(controller+64);
    if((u32)object!=0) {
        scale=sqrtf(sceVu0InnerProduct(object,object));
        object=(u8 *)*(void **)(controller+64)+16;
        { float y=sqrtf(sceVu0InnerProduct(object,object));
          size[0]=*(float *)(saved+96)*scale;
          size[1]=*(float *)(saved+100)*y;
          size[2]=1.0f; size[3]=0.0f; }
    } else sceVu0CopyVector(size,saved+96);
    if(((struct { signed char reflect:1; } *)(s_mngp+60))->reflect!=0) size[1]*=-1.0f;
    SfxDraw_DrawSprite_Wld(position,size,*(float *)(saved+88),saved+112,uv,*(float *)(params+68));
    SfxDraw_SetRenderStateBlock(state);
}

void __SFX_InitAnimSprite2(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    u8 *s5;
    u8 *s4;
    u8 *s3;
    float f4;
    u32 v1;
    u8 *s2;
    u8 s1;
    u8 *s0;
    float f3;
    float f2;
    float f1;
    float f0;
    float f20;
    float r;
    float spdz;
    float py;
    float yaw;
    u32 v0;
    void *a0_2;
    void *a1_2;

    v0 = 3;
    s5 = (u8 *)a0;
    s3 = (u8 *)*(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PFIXPARAM_FECB6825);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_FIX_PARAM_89E876C2) = (s32)s3;
    v1 = *(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_A92CD2E9_PSEQPARAM_30AF687F);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_SEQ_PARAM_BCE30E49) = v1;
    v1 = *(u8 *)(s3 + DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__65__CDUMMY_8D4B2421);
    s4 = (u8 *)a1;
    v0 = 2;
    v0 = 1;
    switch (v1) {
    case 0:
        ((struct dw_1891466_fields_a92cd2e9 *)s5)->bit_flag.draw_stage = v0;
        break;
    case 1:
        ((struct dw_1891466_fields_a92cd2e9 *)s5)->bit_flag.draw_stage = 4;
        break;
    case 2:
        ((struct dw_1891466_fields_a92cd2e9 *)s5)->bit_flag.draw_stage = 6;
        break;
    case 3:
        ((struct dw_1891466_fields_a92cd2e9 *)s5)->bit_flag.draw_stage = 6;
    }
    v1 = *(u16 *)s3;
    a0_2 = (void *)s5;
    v0 = (u32)s_aTexMng;
    v0 = *(s32 *)(u32)(s32)(u32)&((struct { u8 b[4]; } *)s_aTexMng)[v1];
    *(u32 *)(s5 + 0x80) = v0;
    sceVu0UnitMatrix(a0_2);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_MATRIX_0__0__90CCE4D2) = *(float
        *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_SCALE_0__C00CD91D);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_MATRIX_1__1__6BB6CA6F) = *(float
        *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_SCALE_1__9F7D8219);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_MATRIX_2__2__8F829CA2) = *(float
        *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_SCALE_2__84ED8173);
    dcomp_cop2_9397A3F6B7((void *)((u8 *)s5), (void *)((u8 *)s5), (void *)((u8 *)s4));
    a0_2 = (void *)(s5 + 0x30);
    a1_2 = (void *)(s4 + 0x40);
    sceVu0CopyVector(a0_2, a1_2);
    v0 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_P_MATRIX_856A4D9C);
    if (v0 != 0) {
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_MATRIX_84DDDCB3) = v0;
    } else {
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_MATRIX_84DDDCB3) = 0;
    }
    v1 = *(s16 *)(s3 + 2);
    if ((s32)v1 < 0) {
        v0 = 0x7fffffff;
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_LIFECNT_7CEC2A9C) = 0x7fffffff;
    } else {
        v0 = *(u16 *)(s3 + 4);
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_LIFECNT_7CEC2A9C) = v1 + v0;
    }
    a0_2 = (void *)*(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_PTCL_NUM_5C66241F);
    v0 = (u32)_AllocPtcl((signed int)a0_2);
    *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_PTCL_TOP_1E22B1BC) = v0;
    v1 = *(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_PTCL_NUM_5C66241F);
    s2 = (u8 *)*(s32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_P_PTCL_TOP_1E22B1BC);
    s1 = 0;
    if (0 < (s32)v1) {
        do {
            if ((u32)(s32)s2 == 0) {
                break;
            }
            v0 = *(s16 *)(s3 + 2);
            if ((s32)v0 < 0) {
                v0 = 0x7fffffff;
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LIFECNT_92F2613A) =
                    0x7fffffff;
            } else {
                r = (float)(u16)SfxCalc_RandU32() * 1.5259022e-05f;
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LIFECNT_92F2613A) = (u32)((float)*(s16 *)(s3 + 2) + (float)*(u16 *)(s3 + 4) * (r - 0.5f));
            }
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_0__A5F80208) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_1__649EEDFC) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_2__16CFF809) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_RAND_3__2BF6EA67) = (s32)(100.0f * (r - 0.5f));
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_0__5DFAC5FD) = 0;
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_1__7C315EB0) = 0;
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_2__44E621F2) = 0.01745f * (*(float *)(s3 + 0x14) + *(float *)(s3 + 0x18) * (r - 0.5f));
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_ANG_3__84C321C3) = 0x3f800000;
            {
                float spd[4] __attribute__((aligned(16))) = {0};
                float mRot[4][4] __attribute__((aligned(16)));
                PTCL_RNDRANGE(spdz, *(float *)(s3 + 0x1c), *(float *)(s3 + 0x20));
                spd[2] = spdz;
                PTCL_RNDRANGE(py, *(float *)(s3 + 0x24), *(float *)(s3 + 0x28));
                PTCL_RNDRANGE(yaw, *(float *)(s3 + 0x2c), *(float *)(s3 + 0x30));
                SfxCalc_MakeMatrixFromPYR((void *)mRot, 0.01745f * py, 0.01745f * yaw, 0.0f);
                sceVu0ApplyMatrix((void *)(s2 + 0x80), (void *)mRot, (void *)spd);
            }
            a0_2 = (void *)(s2 + 0x80);
            sceVu0ApplyMatrix(a0_2, (void *)s5, (void *)(u8 *)a0_2);
            a0_2 = (void *)(s2 + 0x40);
            SfxUtil_CalcRndPos((float *)a0_2, *(u16 *)(s3 + 6), (float *)(u8 *)(s3 + 8));
            a0_2 = (void *)(s2 + 0x40);
            sceVu0AddVector(a0_2, (void *)(u32)(s32)a0_2, (void *)(u8 *)(s4 + 0x40));
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_LOC_3__E52D55BB) = 0x3f800000;
            v1 = *(u8 *)(s3 + DCOMP_OFF_STRUCT_DW_1904865_FIELDS_A92CD2E9__64__CDUMMY_13EB4259);
            s0 = (u8 *)(s2 + 0xb0);
            if (v1 != 0) {
                f20 = (float)(*(u8 *)(s3 + 0x3a) * *(u8 *)(s3 + 0x3b));
                r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
                *(u8 *)(s0 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_EXTRA_DATA_0__B1AAA7B6) = (u32)(f20 * r);
            } else {
                *(u8 *)(s0 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_EXTRA_DATA_0__B1AAA7B6) =
                    0;
            }
            s1 += 1;
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_PEMITTER_8D2B2DDD) = (u32)s5;
            s2 = (u8 *)*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_A92CD2E9_P_SIBLING_8BDDA96F);
        } while ((s32)s1 < (s32)*(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_A92CD2E9_PTCL_NUM_5C66241F));
    }
    *(u8 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_A92CD2E9_PTCL_NUM_86E21A87) = s1;
    return;
}
void __SFX_ActAnimSprite2(void *a0 /* r4 */, float f12 /* f12 */) {
    u8 *s3;
    u32 t0;
    u8 s2;
    u32 *s5;
    u8 *s1;
    u8 *s6;
    u8 *s7;
    u8 *s0;
    float f20;
    s32 fp;
    u8 *s4;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f4;
    float f2;
    float f1;
    float f0;
    u8 *pEx;
    void *pMrx1;
    void *pm;
    void *a0_2;
    u8 stackFrame_18C[4] __attribute__((aligned(4)));
    u8 stackFrame_188[4] __attribute__((aligned(4)));
    u8 stackFrame_184[4] __attribute__((aligned(4)));
    u8 stackFrame_180[4] __attribute__((aligned(8)));
    float rotspd[2] __attribute__((aligned(8)));
    u8 stackFrame_160[24] __attribute__((aligned(16)));
    float scl[3][2] __attribute__((aligned(16)));
    float vAdd[4] __attribute__((aligned(16)));
    float tmp_vector[4] __attribute__((aligned(16)));
    u8 mrx[64] __attribute__((aligned(16)));
    float vt[4] __attribute__((aligned(16)));

    fp = 0;
    s7 = (u8 *)0;
    s6 = (u8 *)0;
    s5 = (u32 *)0;
    s3 = (u8 *)a0;
    s1 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    s2 = 0;
    f20 = (float)f12;
    s0 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571);
    pMrx1 = (void *)MRX1;
    goto _L001B28C8;
    _L001B2128:;
    s4 = (u8 *)*(s32 *)(s1 + 0xa4);
    pEx = s1 + 0xb0;
    v0 = *(s32 *)(s1 + 0xa0);
    if (v0 == 0) {
        s4 = (u8 *)s1;
        if ((u32)s6 != 0) {
            v0 = *(s32 *)(s1 + 0xa8);
            *(u32 *)(s6 + 0xa8) = v0;
        }
        a0_2 = (void *)*(s32 *)(s4 + 0xac);
        v1 = s_mngp;
        v0 = (u32)s_FuncTable;
        a0_2 = (void *)*(u16 *)(((u8 *)a0_2 + 0x44));
        a0_2 = (void *)(s32)((u32)a0_2 << 2);
        v1 = *(s32 *)(u32)(s32)((u8 *)(u32)*(s32 *)((v1 + 0x10)) + (u32)(a0_2));
        a0_2 = (void *)*(s32 *)v1;
        v0 = (s32)((u8 *)s_FuncTable + (s32)((u32)((u32)(a0_2)) * (u32)(0x14)));
        v0 = *(s32 *)((v0 + 0x10));
        s1 = (u8 *)*(s32 *)(s1 + 0xa8);
        if (v0 != 0) {
            a0_2 = (void *)s4;
            ((void (*)(s32))(s32)v0)((s32)a0_2);
        }
        a0_2 = (void *)s4;
        memset(a0_2, 0, 0xe0);
        v1 = *(s32 *)((s_mngp + 0x30));
        *(u32 *)(s4 + 0xa8) = v1;
        v1 = s_mngp;
        *(u32 *)((v1 + 0x30)) = (s32)s4;
        a0_2 = (void *)s_mngp;
        v1 = *(s16 *)(((u8 *)a0_2 + 0x38));
        v1 = v1 + -1;
        *(u16 *)(((u8 *)a0_2 + 0x38)) = v1;
    } else {
        if ((u32)s7 == 0) {
            s7 = (u8 *)s1;
        }
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 6;
        a2 = 2;
        s6 = (u8 *)s1;
        a3 = *(s32 *)((v0 + 0xc));
        s5 = (u32 *)((u8 *)s5 + 1);
        SFX_GetSeqParam((void *)((u8 *)&rotspd[0]), a1, a2, (void *)a3, (s32)s4);
        a0_2 = (void *)*(s8 *)(s1 + 0x9e);
        v0 = 0x3c230000;
        v1 = 0x3c230000 | 0xd70a;
        f4 = rotspd[1];
        f1 = *(float *)(s1 + 0x58);
        v0 = 0x3c8e0000;
        v1 = 0x3c8e0000 | 0xf34d;
        v0 = -0x3fb6f030;
        f2 = (f20 * (0.01745f * (rotspd[0] + (f4 * (0.01f * (float)((float)(s32)(u32)a0_2))))));
        f12 = (f1 + f2);
        *(f32 *)(s1 + 0x58) = f12;
        f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
        *(f32 *)(s1 + 0x58) = f12;
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 6;
        a2 = 2;
        a3 = *(s32 *)((v0 + 0x14));
        SFX_GetSeqParam((void *)((u8 *)&scl[0]), a1, a2, (void *)a3, (s32)s4);
        v0 = *(u8 *)(s0 + 0x3c);
        if (v0 != 0) {
            f0 = (scl[0][0] + (scl[0][1] * (0.01f * (float)*(s8 *)(s1 + 0x9c))));
            *(f32 *)(s1 + 0x64) = f0;
            *(f32 *)(s1 + 0x60) = f0;
        } else {
            v0 = *(s32 *)(s3 + 0x50);
            a3 = *(s32 *)((v0 + 0x1c));
            SFX_GetSeqParam((void *)((u8 *)&scl[0] + 0x8), 6, 2, (void *)a3, (s32)s4);
            *(f32 *)(s1 + 0x60) = (scl[0][0] + (scl[0][1] * (0.01f * (float)*(s8 *)(s1 + 0x9c))));
            *(f32 *)(s1 + 0x64) = (scl[1][0] + (scl[1][1] * (0.01f * (float)*(s8 *)(s1 + 0x9d))));
        }
        sceVu0ScaleVector((void *)((u8 *)&vAdd[0]), (void *)(s1 + 0x80), (float)f20);
        a0_2 = (void *)(s1 + 0x40);
        sceVu0AddVector(a0_2, (void *)a0_2, (void *)((u8 *)&vAdd[0]));
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 6;
        a2 = 1;
        a3 = *(s32 *)((v0 + 4));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_18C[0]), a1, a2, (void *)a3, (s32)s4);
        f0 = *(float *)((u8 *)&stackFrame_18C[0]);
        if (!(0.0f == f0)) {
            if ((u32)fp == 0) {
                pm = *(void **)(s3 + 0x40);
                if (pm != 0) {
                    dcomp_cop2_9397A3F6B7((void *)mrx, pm, (void *)s3);
                } else {
                    sceVu0CopyMatrix((void *)mrx, (void *)s3);
                }
                SfxCalc_Vector2Angle((float *)((u8 *)&tmp_vector[0]), (float *)(mrx + 0x8));
                f0 = tmp_vector[1];
                sceVu0RotMatrixY((void *)mrx, pMrx1, (-f0));
                f0 = tmp_vector[0];
                sceVu0RotMatrixX((void *)mrx, (void *)mrx, (-f0));
                dcomp_cop2_21F95D43C1((void *)stackFrame_160, (void *)mrx, (void *)VY);
                fp = 1;
            }
            f0 = *(float *)((u8 *)&stackFrame_18C[0]);
            sceVu0ScaleVector((void *)((u8 *)&vt[0]), (void *)((u8 *)&stackFrame_160[0]), (f0 *
                f20));
            a0_2 = (void *)(s1 + 0x80);
            sceVu0AddVector(a0_2, (void *)((u8 *)&vt[0]), (void *)a0_2);
        }
        v0 = *(s32 *)(s3 + 0x50);
        a1 = 1;
        a2 = 3;
        a3 = *(s32 *)((v0 + 0x24));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_188[0]), a1, a2, (void *)a3, (s32)s4);
        f0 = ((float)(float)(u32)*(u8 *)((u8 *)&stackFrame_188[0]) / 128.0f);
        *(f32 *)(s1 + 0x70) = f0;
        f0 = ((float)(float)(u32)((u8 *)stackFrame_188)[1] / 128.0f);
        *(f32 *)(s1 + 0x74) = f0;
        a1 = 1;
        a2 = a1;
        f0 = ((float)(float)(u32)((u8 *)stackFrame_188)[2] / 128.0f);
        *(f32 *)(s1 + 0x78) = f0;
        v0 = *(s32 *)(s3 + 0x50);
        a3 = *(s32 *)((v0 + 0x2c));
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_188[0] + 0x3), a1, a2, (void *)a3, (s32)s4);
        v1 = (u32)((u8 *)&stackFrame_188[0] + 0x3);
        f0 = ((float)(float)(u32)((u8 *)stackFrame_188)[3] / 128.0f);
        *(f32 *)(s1 + 0x7c) = f0;
        v1 = *(u8 *)(s0 + 0x3a);
        if (0 < (s32)v1) {
            v0 = *(s32 *)(s3 + 0x50);
            a1 = 6;
            a2 = 1;
            a3 = *(s32 *)((v0 + 0x34));
            SFX_GetSeqParam((void *)((u8 *)&stackFrame_184[0]), a1, a2, (void *)a3, (s32)s4);
            v1 = *(u8 *)(s0 + 0x3d);
            a2 = 1;
            switch (v1) {
            case 0: {
                u32 cur;
                u32 th;
                u32 tw;
                s32 idx;
                float sq = *(volatile float *)((u8 *)&stackFrame_184[0]);
                cur = *(volatile u8 *)pEx;
                th = *(volatile u8 *)(s0 + 0x3b);
                tw = *(volatile u8 *)(s0 + 0x3a);
                idx = (s32)(sq + (float)cur);
                {
                    float fx = (float)(u16)(idx % (u16)tw);
                    *(f32 *)(s1 + 0x90) = fx * (1.0f / (float)tw);
                    fx = (float)(u16)((idx / (u16)tw) % (u16)th);
                    *(f32 *)(s1 + 0x94) = fx * (1.0f / (float)th);
                }
                break;
            }
            case 1:
                v0 = *(s32 *)(s3 + 0x50);
                a3 = *(s32 *)((v0 + 0x3c));
                SFX_GetSeqParam((void *)((u8 *)&stackFrame_180[0]), 6, a2, (void *)a3, (s32)s4);
                *(f32 *)(s1 + 0x90) = *(float *)((u8 *)&stackFrame_184[0]);
                *(f32 *)(s1 + 0x94) = *(float *)((u8 *)&stackFrame_180[0]);
            }
        }
        a0_2 = (void *)*(s32 *)(s1 + 0xa0);
        v1 = 0x7fffffff;
        if ((u32)(s32)a0_2 != v1) {
            v1 = (s32)((u8 *)a0_2 + -1);
            *(u32 *)(s1 + 0xa0) = v1;
        }
        v1 = *(s32 *)(s1 + 0xa4);
        v1 = v1 + 1;
        *(u32 *)(s1 + 0xa4) = v1;
        a0_2 = (void *)*(u16 *)(s0 + 0x3e);
        if ((u32)a0_2 != 0 && (u32)a0_2 <= (u32)*(s32 *)(s1 + 0xa4)) {
            *(u32 *)(s1 + 0xa4) = 0;
        }
        s1 = (u8 *)*(s32 *)(s1 + 0xa8);
    }
    s2 += 1;
    while (1) {
        _L001B28C8:;
        if ((s32)*(u8 *)(s3 + 0x46) <= (s32)s2) {
            break;
        }
        if ((u32)(s32)s1 != 0) {
            goto _L001B2128;
        }
        break;
    }
    *(u32 *)(s3 + 0x48) = (s32)s7;
    *(u8 *)(s3 + 0x46) = (s32)s5;
    return;
}


/* __SFX_DrawAnimSprite2 @ 0x1B2030 .. 0x1B20B8 (0x88 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   cfg: kept goto: 0x1b205c -> .L001B2080
 *   cfg: loop body is not one contiguous region: .L001B2080
 *   cfg: kept branch: 0x1b2094 if (..) goto .L001B2068
 *   a1 typed from the __SFX_DrawAnimSprite2 call table
 *   a2 typed from the __SFX_DrawAnimSprite2 call table
 *   declaration vs inferred signature: return void vs inferred u8
 */

static void __SFX_DrawAnimSprite2(void *a0 /* r4 */) {
    u8 *s0;
    u8 s2;
    u32 s1;
    u32 v1;

    v1 = *(s32 *)(((u8 *)a0 + 0x4c));
    s1 = *(s32 *)(((u8 *)a0 + 0x48));
    v1 = *(u16 *)v1;
    s0 = (u8 *)a0;
    if ((s32)v1 > 0 && s1) {
        s2 = 0;
        goto _L001B2080;
        _L001B2068:;
        a0 = (void *)(s32)s1;
        __SFX_DrawPtclSprite(a0);
        s1 = *(s32 *)((s1 + 0xa8));
        s2 += 1;
        while (1) {
            _L001B2080:;
            v1 = *(u8 *)(s0 + 0x46);
            a0 = (void *)s2;
            if ((s32)a0 >= (s32)v1) {
                break;
            }
            if (s1 != 0) {
                goto _L001B2068;
            }
            break;
        }
    }
    return;
}
void __SFX_DrawPtclAnimSprite2(void *object) {
    u8 *saved;
    u8 *controller;
    u8 *params;
    u8 *setting;
    u32 outside;
    int below;
    u8 *texture;
    u_long128 state;
    float scaleY;
    float scaleX;
    float position[4] __attribute__((aligned(16)));
    float uv[4] __attribute__((aligned(16)));
    float size[4] __attribute__((aligned(16)));
    controller=*(u8 **)((u8 *)object+172);
    params=*(u8 **)(controller+76);
    saved=(u8 *)object;
    if(((struct { signed char reflect:1; } *)(s_mngp+60))->reflect!=0) {
        if(SFX_ConfirmReflect(*(u16 *)(controller+110),0)==0) return;
    }
    if(*(u32 *)(controller+64)!=0) sceVu0ApplyMatrix(position,*(void **)(controller+64),saved+64);
    else sceVu0CopyVector(position,saved+64);
    setting=(u8 *)SFX_GetSettingData();
    outside=!(0<(u32)SfxCalc_CheckInsightCamera(position));
    below=*(float *)(saved+124)<*(float *)(setting+12);
    if(outside!=0 || below!=0) return;
    texture=*(u8 **)(controller+128);
    state=SfxDraw_GetRenderStateBlock();
    SfxDraw_UseTexture(1);
    SfxDraw_SetBlendType(*(u8 *)(params+57));
    SfxDraw_SetTexture(texture);
    SfxDraw_EnableFog(*(u8 *)(params+56));
    SfxDraw_EnableZTest(*(u8 *)(params+66));
    SfxDraw_UseST(1);
    uv[0]=*(float *)(saved+144); uv[1]=*(float *)(saved+148);
    if(*(u8 *)(params+61)==0) {
        scaleX=1.0f;
        uv[2]=*(float *)(saved+144)+1.0f/(float)*(u8 *)(params+58);
        uv[3]=*(float *)(saved+148)+1.0f/(float)*(u8 *)(params+59);
    } else {
        scaleX=1.0f;
        uv[2]=1.0f+*(float *)(saved+144); uv[3]=1.0f+*(float *)(saved+148);
    }
    object=*(void **)(controller+64);
    if((u32)object!=0) {
        scaleY=sqrtf(sceVu0InnerProduct(object,object));
        object=(u8 *)*(void **)(controller+64)+16;
        { float y=sqrtf(sceVu0InnerProduct(object,object));
          size[0]=*(float *)(saved+96)*scaleY;
          size[1]=*(float *)(saved+100)*y;
          size[2]=scaleX; size[3]=0.0f; }
    } else sceVu0CopyVector(size,saved+96);
    if(((struct { signed char reflect:1; } *)(s_mngp+60))->reflect!=0) size[1]*=-1.0f;
    SfxDraw_DrawSprite_Wld(position,size,*(float *)(saved+88),saved+112,uv,*(float *)(params+52));
    SfxDraw_SetRenderStateBlock(state);
}
void __SFX_InitFireFly(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    u8 *a0_bytes; // s6
    u8 *s5;
    s32 xt1;
    void *a0_s6; // a0
    u8 *s4;
    void *a1_2;
    s32 s3;
    u8 *s2;
    u8 *s1;
    float f3;
    u8 *s0;
    void *a2_2;

    a0_bytes = (u8 *)a0;
    s5 = (u8 *)a1;
    a1_2 = (void *)(0x40 + s5);
    xt1 = ((u32)s_aTexMng);
    s4 = (u8 *)*(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F);
    *(u32 *)(DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571 + a0_bytes) = (u32)s4;
    xt1 = *(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D);
    a2_2 = (void *)(0x50 + s5);
    *(u32 *)(a0_bytes + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20) = xt1;
    xt1 = *(u16 *)s4;
    xt1 = *(s32 *)&((struct { u8 b[4]; } *)s_aTexMng)[xt1];
    *(u32 *)(a0_bytes + 0x80) = xt1;
    SfxCalc_MakeRotTransMatrix_I((void *)a0_bytes, (float *)a1_2, (float *)a2_2, (float *)(u8 *)(s5
        + 0x60));
    xt1 = (u32)MRX1;
    *(u32 *)(a0_bytes + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) = xt1;
    xt1 = (u32)MRX1;
    xt1 = *(s16 *)(2 + s4);
    *(u32 *)(DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD + a0_bytes) = (s16)xt1;
    a0_s6 = (void *)*(u16 *)(DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A + s5);
    xt1 = (u32)_AllocPtcl((signed int)a0_s6);
    *(u32 *)(DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087 + a0_bytes) = xt1;
    xt1 = *(u16 *)(s5 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
    s3 = 0;
    s2 = (u8 *)*(s32 *)(DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087 + (s32)a0_bytes);
    if (0 < xt1) {
        do {
            if (s2 == 0) {
                break;
            }
            xt1 = *(s16 *)(s4 + 2);
            if (xt1 < 0) {
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = 0x7fffffff;
            } else {
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = xt1;
                xt1 = 0x7fffffff;
            }
            f3 = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038) = (s32)(100.0f * (f3 - 0.5f));
            f3 = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C) = (s32)(100.0f * (f3 - 0.5f));
            f3 = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC) = (s32)(100.0f * (f3 - 0.5f));
            f3 = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F) = (s32)(100.0f * (f3 - 0.5f));
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_0__836F7B5E) = 0;
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_1__91B967E9) = 0;
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_2__A7B3C47E) = 0;
            *(u32 *)(DCOMP_OFF_STRUCT_DW_1890884_FIELDS_N_SPEED_3__085311BC + s2) = 0;
            SfxCalc_RotateVector((float *)(void *)(s2 + 0x80), *(float *)(s5 +
                DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_0__5ED7228F), *(float *)(s5 +
                DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_1__A795EEE1), *(float *)(s5 +
                DCOMP_OFF_STRUCT_DW_1890401_FIELDS_ANG_2__3B661BD7));
            a2_2 = (void *)(s4 + 8);
            a0_s6 = (void *)(s2 + 0x80);
            sceVu0ApplyMatrix(a0_s6, (void *)*(s32 *)(a0_bytes +
                DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B), (void *)a0_s6);
            SfxUtil_CalcRndPos((float *)(void *)(s2 + 0x40), *(u16 *)(s4 + 6), (float *)a2_2);
            xt1 = *(s32 *)(DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24 + s5);
            if (xt1 != 0) {
                a0_s6 = (void *)(0x40 + s2);
                sceVu0AddVector(a0_s6, (void *)a0_s6, (void *)(0x30 + xt1));
            } else {
                a2_2 = (void *)(0x40 + s5);
                a0_s6 = (void *)(0x40 + s2);
                sceVu0AddVector(a0_s6, (void *)a0_s6, a2_2);
            }
            xt1 = (u32)a0_bytes;
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED) = 0x3f800000;
            *(u32 *)(DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510 + s2) = xt1;
            xt1 = 0x3f800000;
            a1_2 = (void *)1;
            s1 = (u8 *)(0xb0 + s2);
            f3 = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(f32 *)(0x14 + s1) = 0.5f + 1.5f * f3;
            f3 = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            *(f32 *)(s1 + 0x18) = *(float *)(0x14 + s4) * (0.5f + 1.5f * f3);
            s0 = (u8 *)(0xb0 + s2);
            xt1 = *(s32 *)(*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510) +
                DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571);
            xt1 = (0x18 + xt1);
            SfxUtil_CalcRndPos((float *)(void *)s0, (signed int)a1_2, (float *)xt1);
            xt1 = *(s32 *)(DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510 + s2);
            sceVu0AddVector((void *)s0, (void *)(s0), (void *)(xt1 + 0x30));
            f3 = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            *(f32 *)(0x10 + s0) = 5.0f * f3;
            s3 = 1 + s3;
            xt1 = *(u16 *)(DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A + s5);
            xt1 = xt1;
            xt1 = s3 < xt1;
            s2 = (u8 *)*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76);
        } while (xt1 != 0);
    }
    *(u8 *)(DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B + a0_bytes) = s3;
    return;
}
void __SFX_ActFireFly(void *a0 /* r4 */, float f12 /* f12 */) {
    u8 *s4;
    u32 a1;
    u8 *fp;
    u8 s3;
    u32 *s5;
    u8 *s2;
    float f21;
    u8 *s6;
    u8 *s7;
    float f20;
    u8 *s0;
    u8 *s1;
    u32 v1;
    float f2;
    u32 v0;
    float f1;
    float f0;
    u8 *a0_2;
    float dv[4] __attribute__((aligned(16)));
    float vAdd[4] __attribute__((aligned(16)));

    s7 = (u8 *)0;
    s6 = (u8 *)0;
    s5 = (u32 *)0;
    s4 = (u8 *)a0;
    s3 = 0;
    f20 = (float)f12;
    fp = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571);
    s2 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    f21 = (2.0f * f20);
    goto _L001B1808;
    _L001B15C8:;
    v0 = *(s32 *)(s2 + 0xa0);
    s1 = (u8 *)(s2 + 0xb0);
    if (v0 == 0) {
        s0 = (u8 *)s2;
        if ((u32)s6 != 0) {
            v0 = *(s32 *)(s2 + 0xa8);
            *(u32 *)(s6 + 0xa8) = v0;
        }
        a0_2 = (u8 *)*(s32 *)(s0 + 0xac);
        v1 = s_mngp;
        v0 = (u32)s_FuncTable;
        a0_2 = (u8 *)*(u16 *)(a0_2 + 0x44);
        a0_2 = (u8 *)(s32)((u32)a0_2 << 2);
        v1 = *(s32 *)(u32)(s32)((u8 *)(u32)*(s32 *)((v1 + 0x10)) + (u32)(a0_2));
        a0_2 = (u8 *)*(s32 *)v1;
        v0 = (s32)((u8 *)s_FuncTable + (s32)((u32)((u32)(a0_2)) * (u32)(0x14)));
        v0 = *(s32 *)((v0 + 0x10));
        s2 = (u8 *)*(s32 *)(s2 + 0xa8);
        if (v0 != 0) {
            a0_2 = (u8 *)s0;
            ((void (*)(s32))(s32)v0)((s32)a0_2);
        }
        a0_2 = (u8 *)s0;
        memset((void *)a0_2, 0, 0xe0);
        v1 = *(s32 *)((s_mngp + 0x30));
        *(u32 *)(s0 + 0xa8) = v1;
        v1 = s_mngp;
        *(u32 *)((v1 + 0x30)) = (s32)s0;
        a0_2 = (u8 *)s_mngp;
        v1 = *(s16 *)(a0_2 + 0x38);
        v1 = v1 + -1;
        *(u16 *)(a0_2 + 0x38) = v1;
    } else {
        if ((u32)s7 == 0) {
            s7 = (u8 *)s2;
        }
        s6 = (u8 *)s2;
        f1 = *(float *)(s1 + 0x10);
        s5 = (u32 *)((u8 *)s5 + 1);
        f1 = (f1 - f20);
        *(f32 *)(s1 + 0x10) = f1;
        if (f1 < 0.0f) {
            v0 = *(s32 *)(s2 + 0xac);
            s0 = (u8 *)(s2 + 0xb0);
            a0_2 = (u8 *)s0;
            a1 = 1;
            v0 = *(s32 *)((v0 + 0x4c));
            SfxUtil_CalcRndPos((float *)a0_2, a1, (float *)(s32)(v0 + 0x18));
            v0 = *(s32 *)(s2 + 0xac);
            a0_2 = (u8 *)s0;
            sceVu0AddVector((void *)a0_2, (void *)s0, (void *)(s32)(v0 + 0x30));
            *(f32 *)(s0 + 0x10) = 5.0f * ((float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f));
        }
        sceVu0SubVector((void *)((u8 *)&dv[0]), (void *)s1, (void *)(s2 + 0x40));
        sceVu0Normalize((void *)((u8 *)&dv[0]), (void *)((u8 *)&dv[0]));
        sceVu0ScaleVector((void *)dv, (void *)dv, f21);
        a0_2 = (u8 *)(s2 + 0x80);
        sceVu0AddVector((void *)a0_2, (void *)a0_2, (void *)((u8 *)&dv[0]));
        if (*(float *)(fp + 0x1c) < sqrtf(sceVu0InnerProduct((void *)(s2 + 0x80), (void *)(s2 + 0x80)))) {
            sceVu0Normalize((void *)(s2 + 0x80), (void *)(s2 + 0x80));
            sceVu0ScaleVector((void *)(s2 + 0x80), (void *)(s2 + 0x80), *(float *)(fp + 0x1c));
        }
        sceVu0ScaleVector((void *)((u8 *)&vAdd[0]), (void *)(s2 + 0x80), (float)f20);
        a0_2 = (u8 *)(s2 + 0x40);
        sceVu0AddVector((void *)a0_2, (void *)a0_2, (void *)((u8 *)&vAdd[0]));
        a0_2 = (u8 *)*(s32 *)(s2 + 0xa4);
        v1 = 0x7fffffff;
        a0_2 = (u8 *)(a0_2 + 1);
        *(u32 *)(s2 + 0xa4) = (s32)a0_2;
        a0_2 = (u8 *)*(s32 *)(s2 + 0xa0);
        if ((u32)(s32)a0_2 != v1) {
            v1 = (s32)(a0_2 + -1);
            *(u32 *)(s2 + 0xa0) = v1;
        }
        s2 = (u8 *)*(s32 *)(s2 + 0xa8);
    }
    s3 += 1;
    while (1) {
        _L001B1808:;
        v1 = *(u8 *)(s4 + 0x46);
        a0_2 = (u8 *)s3;
        if ((s32)a0_2 >= (s32)v1) {
            break;
        }
        if ((u32)(s32)s2 != 0) {
            goto _L001B15C8;
        }
        break;
    }
    *(u32 *)(s4 + 0x48) = (s32)s7;
    *(u8 *)(s4 + 0x46) = (s32)s5;
    return;
}

/* __SFX_DrawFireFly @ 0x1B1550 .. 0x1B1558 (0x8 bytes) */
/*
 * dcomp notes:
 *   a0 typed from the __SFX_DrawFireFly call table
 *   a1 typed from the __SFX_DrawFireFly call table
 *   a2 typed from the __SFX_DrawFireFly call table
 */

static void __SFX_DrawFireFly(u8 *a0 /* r4 */, u8 *a1 /* r5 */, u32 *a2 /* r6 */) {
    return;
}

static void __SFX_DrawPtclFireFly(void *a0 /* r4 */) {
    u8 *s3;
    u8 *s2;
    u32 a1;
    u8 *s1;
    u32 v1;
    float f1;
    u32 v0;
    float *s0;
    float f0;
    u_long128 v0_q2;
    void *a0_2;
    u8 stackFrame_70[16] __attribute__((aligned(4)));
    u8 stackFrame_6C[4] __attribute__((aligned(4)));
    u8 stackFrame_60[12] __attribute__((aligned(16)));

    s3 = (u8 *)a0;
    s2 = (u8 *)(s3 + 0xb0);
    v0 = s_mngp;
    v1 = *(s32 *)(((u8 *)a0 + 0xac));
    v0 = *(s8 *)((v0 + 0x3c));
    s1 = (u8 *)(s32)(v1 + 0x80);
    if ((u64)((s64)((s64)((u64)((s64)(s32)v0) << 0x3f)) >> 0x3f) != 0) {
        a0_2 = (void *)*(u16 *)((v1 + 0x6e));
        v0 = SFX_ConfirmReflect(a0_2, 0);
        if (v0 == 0) {
            goto _L001B1530;
        }
    }
    a0_2 = (void *)(s3 + 0x40);
    v0 = SfxCalc_CheckInsightCamera((float *)a0_2);
    v1 = v0 != 0;
    v1 = v1 ^ 1;
    if (v1 == 0) {
        v0 = 0x3f800000;
        a0_2 = (void *)((u8 *)&stackFrame_60[0]);
        a1 = (u32)V1;
        *(f32 *)((u8 *)&stackFrame_70[0]) = *(float *)(s2 + 0x18);
        ((f32 *)stackFrame_70)[1] = *(float *)(s2 + 0x18);
        ((u32 *)stackFrame_70)[2] = 0x3f800000;
        ((u32 *)stackFrame_70)[3] = 0;
        sceVu0CopyVector(a0_2, (void *)V1);
        v0 = *(s32 *)(s3 + 0xa4);
        s0 = (float *)((u8 *)&stackFrame_6C[0]);
        f1 = 60.0f;
        f0 = 6.28318548f;
        f0 = SfxCalc_Cos((6.28318548f * (((float)(float)v0 / 60.0f) * *(float *)(s2 + 0x14))));
        f1 = 0.0f;
        *(f32 *)s0 = f0;
        if ((s32)(f0 < 0.0f)) {
            *(f32 *)s0 = f1;
        }
        v0_q2 = SfxDraw_GetRenderStateBlock();
        a0_2 = (void *)(s32)1;
        SfxDraw_UseTexture((signed int)a0_2);
        a0_2 = (void *)(s32)1;
        SfxDraw_SetBlendType((unsigned short)a0_2);
        a0_2 = (void *)*(s32 *)s1;
        SfxDraw_SetTexture(a0_2);
        SfxDraw_EnableFog(0);
        a0_2 = (void *)(s32)1;
        SfxDraw_UseST((signed int)a0_2);
        v0 = 0x248530;
        a0_2 = (void *)(s3 + 0x40);
        {
            struct stackFrame_50 { u8 b[16]; } stackFrame_50 __attribute__((aligned(16))) = {{0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80,
                0x3f}};
            SfxDraw_DrawSprite_Wld((float *)a0_2, (void *)((u8 *)&stackFrame_70[0]), *(float *)(s3
                + 0x58), (void *)(u8 *)((u8 *)&stackFrame_60[0]), (void *)(u8 *)((u8
                *)&stackFrame_50), 0.0f);
            SfxDraw_SetRenderStateBlock(v0_q2);
        }
    }
    _L001B1530:;
    return;
}
static void _SubFunc_Plume_Move(void *p_ptcl_v /* r4 */, float dt_ /* f12 */) {
    struct dw_1890884_fields *p_ptcl = (struct dw_1890884_fields *)p_ptcl_v;
    struct dw_1899235_fields *pPtclExDat;
    float SPEED;
    float C_PRESS;
    float C_PITCH_SPD;
    float C_PITCH_VAL;
    float pitch_mov;
    float speed;
    float dot;
    float vMovDir[4] __attribute__((aligned(16)));
    float mrx[4][4] __attribute__((aligned(16)));
    float vPress[4] __attribute__((aligned(16)));
    float vGrav[4] __attribute__((aligned(16)));
    float sgn;
    float tb;
    float ta;
    float press;

    pPtclExDat = (struct dw_1899235_fields *)p_ptcl->extra_data;
    SPEED = sqrtf(sceVu0InnerProduct(p_ptcl->n_speed, p_ptcl->n_speed));
    C_PRESS = pPtclExDat->press_coeff;
    C_PITCH_SPD = 6.2831855f * *(volatile float *)&pPtclExDat->pitch_coeff;
    C_PITCH_VAL = 18.849556f * *(volatile float *)&pPtclExDat->valance;
    sceVu0Normalize(vMovDir, p_ptcl->n_speed);
    SfxCalc_MakeMatrixFromQtn(mrx, p_ptcl->qtn);
    {
    float grav[4] __attribute__((aligned(16))) = {0.0f, 9.8f, 0.0f, 0.0f};
    float vt[4] __attribute__((aligned(16)));
    float mRot[4][4] __attribute__((aligned(16)));
    float mPitch[4][4] __attribute__((aligned(16)));
    sceVu0ScaleVector(vGrav, grav, dt_);
    speed = SPEED + sqrtf(sceVu0InnerProduct(vGrav, vGrav));
    dot = sceVu0InnerProduct(vMovDir, mrx[1]);
    if (0.0f < dot) {
        sgn = 1.0f;
    } else {
        sgn = -1.0f;
    }
    press = C_PRESS * (speed * fabsf(dot));
    sceVu0ScaleVector(vPress, mrx[1], (-1.0f * sgn) * press);
    speed = SPEED + sqrtf(sceVu0InnerProduct(vGrav, vGrav));
    dot = sceVu0InnerProduct(vMovDir, mrx[2]);
    if (0.0f < dot) {
        sgn = 1.0f;
    } else {
        sgn = -1.0f;
    }
    pitch_mov = sgn * (speed * C_PITCH_SPD);
    dot = sceVu0InnerProduct((float *)VY, mrx[1]);
    if (0.0f < dot) {
        sgn = -1.0f;
    } else {
        sgn = 1.0f;
    }
    C_PITCH_VAL = C_PITCH_VAL * fabsf(dot);
    sceVu0AddVector(p_ptcl->n_speed, p_ptcl->n_speed, vGrav);
    sceVu0AddVector(p_ptcl->n_speed, p_ptcl->n_speed, vPress);
    sceVu0ScaleVector(vt, p_ptcl->n_speed, dt_);
    sceVu0AddVector(p_ptcl->loc, vt, p_ptcl->loc);
    {
    float rot[4] __attribute__((aligned(16))) = {0.0f};
    rot[0] = dt_ * (pitch_mov + sgn * C_PITCH_VAL);
    SfxCalc_MakeMatrixFromPYR(mPitch, rot[0], rot[1], rot[2]);
    }
    SfxCalc_MakeMatrixFromQtn(mRot, p_ptcl->qtn);
    dcomp_cop2_9397A3F6B7((void *)mRot, (void *)mRot, (void *)mPitch);
    SfxCalc_QtnMakeFromMatrix(p_ptcl->qtn, (void *)mRot);
    }
}
void __SFX_InitPlume(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    u8 *a0_bytes; // s5
    u8 *s4;
    void *a0_s5; // a0
    u8 *s3;
    s32 s2;
    u8 *s1;
    u8 *s0;
    float f12;
    float f2;
    float f20;
    float r;
    float f1;
    u32 v1;
    u32 v0;
    void *a1_2;
    float mRot[4][4] __attribute__((aligned(16)));
    u8 szFile[256] __attribute__((aligned(16)));
    float mrx[4][4] __attribute__((aligned(16)));

    a0_bytes = (u8 *)a0;
    s4 = (u8 *)a1;
    a1_2 = (void *)MRX1;
    s3 = (u8 *)*(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F);
    *(u32 *)(a0_bytes + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571) = (s32)s3;
    v0 = *(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D);
    *(u32 *)(a0_bytes + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20) = v0;
    sceVu0CopyMatrix((void *)a0_bytes, (void *)MRX1);
    v0 = (u32)MRX1;
    *(u32 *)(a0_bytes + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) = (u32)MRX1;
    v0 = *(s16 *)(s3 + 2);
    *(u32 *)(a0_bytes + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD) = v0;
    a0_s5 = (void *)*(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
    v0 = (u32)_AllocPtcl((signed int)a0_s5);
    *(u32 *)(a0_bytes + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087) = v0;
    v1 = *(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
    s1 = (u8 *)*(s32 *)(a0_bytes + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    s2 = 0;
    if (0 < (s32)v1) {
        do {
            s0 = (u8 *)(s1 + 0xb0);
            if ((u32)(s32)s1 == 0) {
                break;
            }
            v0 = *(s16 *)(s3 + 2);
            if ((s32)v0 < 0) {
                v0 = 0x7fffffff;
                *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = 0x7fffffff;
            } else {
                *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = v0;
            }
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F) = (s32)(100.0f * (r - 0.5f));
            v0 = *(u8 *)(s3 + DCOMP_OFF_STRUCT_DW_1904865_FIELDS__23__CDUMMY_8292A35A);
            if (v0 != 0) {
                f20 = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
                f1 = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
                SfxCalc_QtnMakeFromPYR((float *)(void *)(s1 + 0xd0), 6.2831855f * (f1 - 0.5f), 6.2831855f * (f20 - 0.5f), 0.0f);
            } else {
                SfxCalc_QtnMakeFromMatrix((float *)(void *)(s1 + 0xd0), (void *)*(s32 *)(s4 +
                    DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24));
            }
            {
            float spd[4] __attribute__((aligned(16))) = {0};
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            spd[2] = (*(float *)(s3 + 0x18) + (*(float *)(s3 + 0x1c) * (r - 0.5f)));
            sceVu0CopyVector((void *)(s1 + 0x80), (void *)spd);
            SfxCalc_MakeMatrixFromQtn((void *)mRot, (float *)(s1 + 0xd0));
            a0_s5 = (void *)(s1 + 0x80);
            sceVu0ApplyMatrix(a0_s5, (void *)mRot, (void *)(u8 *)a0_s5);
            a0_s5 = (void *)(s1 + 0x80);
            sceVu0ApplyMatrix(a0_s5, (void *)*(s32 *)(a0_bytes +
                DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B), (void *)(u8 *)a0_s5);
            SfxUtil_CalcRndPos((float *)(void *)(s1 + 0x40), *(u16 *)(s3 + 6), (float *)(u8 *)(s3 +
                8));
            v0 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24);
            if (v0 != 0) {
                a0_s5 = (void *)(s1 + 0x40);
                sceVu0AddVector(a0_s5, (void *)(u32)(s32)a0_s5, (void *)(u8 *)(s4 + 0x40));
                v0 = 0x3f800000;
                a0_s5 = (void *)(s1 + 0x40);
                *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED) = 0x3f800000;
                sceVu0ApplyMatrix(a0_s5, (void *)*(s32 *)(s4 +
                    DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24), (void *)(u8 *)a0_s5);
            } else {
                a0_s5 = (void *)(s1 + 0x40);
                sceVu0AddVector(a0_s5, (void *)(u32)(s32)a0_s5, (void *)(u8 *)(s4 + 0x40));
            }
            v0 = 0x3f800000;
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LOC_3__B19D56ED) = 0x3f800000;
            a1_2 = (void *)V1;
            sceVu0CopyVector((void *)(s1 + 0x60), (void *)V1);
            a1_2 = (void *)V1;
            sceVu0CopyVector((void *)(s1 + 0x70), (void *)V1);
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510) = (u32)a0_bytes;
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            *(f32 *)s0 = (*(float *)(s3 + 0x20) + (*(float *)(s3 + 0x24) * (r - 0.5f)));
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            *(f32 *)(s0 + 4) = (*(float *)(s3 + 0x28) + (*(float *)(s3 + 0x2c) * (r - 0.5f)));
            r = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            *(f32 *)(s0 + 8) = (*(float *)(s3 + 0x30) + (*(float *)(s3 + 0x34) * (r - 0.5f)));
            v0 = SFX_ConfirmReflect((void *)*(u16 *)(a0_bytes +
                DCOMP_OFF_STRUCT_DW_1891466_FIELDS_SFX_STTDATA_IDX_BFD85288), 0);
            a1_2 = (void *)v0;
            v0 = SfxMdl_Alloc((unsigned short)(void *)*(u16 *)s3, (signed int)a1_2);
            *(u16 *)(s0 + 0xc) = v0;
            a0_s5 = (void *)*(u16 *)(s0 + 0xc);
            if ((u32)a0_s5 == (u32)0xffff) {
                a1_2 = (void *)"PtclMng.c";
                strcpy((char *)szFile, (const char *)"PtclMng.c");
                a1_2 = (void *)"3D\323\303\336\331\212\204\202\350\223\226\202\304\216\270\224s";
                SfxDbg_SetDebugMsg(0,
                    "3D\323\303\336\331\212\204\202\350\223\226\202\304\216\270\224s", (char *)szFile, 0x1585);
            }
            v1 = *(u8 *)(a0_bytes + 0x6c);
            if ((u32)(v1 & 1) == 0) {
                SfxCalc_MakeMatrixFromQtn((void *)mrx, (float *)(s1 + 0xd0));
                a1_2 = (void *)(s1 + 0x40);
                sceVu0CopyVector((void *)((u8 *)mrx + 0x30), a1_2);
                dcomp_cop2_9397A3F6B7((void *)(void *)mrx, (void *)((u8
                    *)a0_bytes), (void *)(void *)mrx);
                a0_s5 = (void *)*(u16 *)(s0 + 0xc);
                SfxMdl_SetMatrix((unsigned short)a0_s5, (void *)mrx);
                f12 = *(float *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_0__89D82EC2);
                a0_s5 = (void *)*(u16 *)(s0 + 0xc);
                SfxMdl_SetColor((unsigned short)a0_s5, f12, *(float *)(s1 +
                    DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_1__872F13A5), *(float *)(s1 +
                    DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_2__2B1C9A34));
                a0_s5 = (void *)*(u16 *)(s0 + 0xc);
                SfxMdl_SetAlpha((unsigned short)a0_s5, *(float *)(s1 +
                    DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_3__47898D35));
                a0_s5 = (void *)*(u16 *)(s0 + 0xc);
                SfxMdl_SetTexScroll((unsigned short)a0_s5, *(float *)(s1 +
                    DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ADD_UV_0__91FC4FD4), *(float *)(s1 +
                    DCOMP_OFF_STRUCT_DW_1890884_FIELDS_ADD_UV_1__B796255F));
            }
            }
            s1 = (u8 *)*(s32 *)(s1 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76);
            s2 = s2 + 1;
        } while (s2 < (s32)*(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A));
    }
    *(u8 *)(a0_bytes + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B) = s2;
    return;
}


void __SFX_ActPlume(void *a0 /* r4 */, float f12 /* f12 */) {
    u8 *s3;
    u8 s2;
    u32 *s1;
    u8 *s0;
    u8 *s5;
    u8 *s6;
    u8 *s4;
    float f20;
    u8 *s7;
    u32 v1;
    u32 v0;
    u8 *a0_2;
    u8 stackFrame_A0[64] __attribute__((aligned(16)));

    s7 = ((u8 *)&stackFrame_A0[48]);
    s6 = (u8 *)0;
    s5 = (u8 *)0;
    s3 = (u8 *)a0;
    s2 = 0;
    s1 = (u32 *)0;
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x48));
    f20 = f12;
    goto _L001B08E8;
    _L001B06A0:;
    v0 = *(s32 *)(s0 + 0xa0);
    s4 = (u8 *)(s0 + 0xb0);
    if (v0 == 0) {
        s4 = (u8 *)s0;
        if ((u32)s5 != 0) {
            v0 = *(s32 *)(s0 + 0xa8);
            *(u32 *)(s5 + 0xa8) = v0;
        }
        a0_2 = (u8 *)*(s32 *)(s4 + 0xac);
        v1 = s_mngp;
        v0 = (u32)s_FuncTable;
        a0_2 = (u8 *)*(u16 *)(a0_2 + 0x44);
        a0_2 = (u8 *)(s32)((u32)a0_2 << 2);
        v1 = *(s32 *)(u32)(s32)((u8 *)(u32)*(s32 *)((v1 + 0x10)) + (u32)(a0_2));
        a0_2 = (u8 *)*(s32 *)v1;
        v0 = (s32)((u8 *)s_FuncTable + (s32)((u32)((u32)(a0_2)) * (u32)(0x14)));
        v0 = *(s32 *)((v0 + 0x10));
        s0 = (u8 *)*(s32 *)(s0 + 0xa8);
        if (v0 != 0) {
            a0_2 = (u8 *)s4;
            ((void (*)(s32))(s32)v0)((s32)a0_2);
        }
        a0_2 = (u8 *)s4;
        memset((void *)a0_2, 0, 0xe0);
        v1 = *(s32 *)((s_mngp + 0x30));
        *(u32 *)(s4 + 0xa8) = v1;
        v1 = s_mngp;
        *(u32 *)((v1 + 0x30)) = (s32)s4;
        a0_2 = (u8 *)s_mngp;
        v1 = *(s16 *)(a0_2 + 0x38);
        v1 = v1 + -1;
        *(u16 *)(a0_2 + 0x38) = v1;
    } else {
        if ((u32)s6 == 0) {
            s6 = (u8 *)s0;
        }
        a0_2 = (u8 *)s0;
        s5 = (u8 *)s0;
        s1 = (u32 *)((u8 *)s1 + 1);
        _SubFunc_Plume_Move((void *)a0_2, (float)f20);
        a0_2 = (u8 *)*(s32 *)(s0 + 0xa4);
        v1 = 0x7fffffff;
        a0_2 = (u8 *)(a0_2 + 1);
        *(u32 *)(s0 + 0xa4) = (s32)a0_2;
        a0_2 = (u8 *)*(s32 *)(s0 + 0xa0);
        if ((u32)(s32)a0_2 != v1) {
            v1 = (s32)(a0_2 + -1);
            *(u32 *)(s0 + 0xa0) = v1;
        }
        v1 = *(u8 *)(s3 + 0x6c);
        v1 = v1 & 1;
        if (v1 == 0) {
            SfxCalc_MakeMatrixFromQtn((void *)((u8 *)&stackFrame_A0[0]), (float *)(s0 + 0xd0));
            a0_2 = s7;
            sceVu0CopyVector((void *)a0_2, (void *)(s0 + 0x40));
            dcomp_cop2_9397A3F6B7((void *)((u8 *)((u8 *)&stackFrame_A0[0])), (void *)((u8 *)s3),
                (void *)((u8 *)((u8 *)&stackFrame_A0[0])));
            v0 = *(s32 *)(s3 + 0x40);
            dcomp_cop2_9397A3F6B7((void *)((u8 *)((u8 *)&stackFrame_A0[0])), (void *)((u8 *)v0),
                (void *)((u8 *)((u8 *)&stackFrame_A0[0])));
            a0_2 = (u8 *)*(u16 *)(s4 + 0xc);
            SfxMdl_SetMatrix((unsigned short)a0_2, (void *)((u8 *)&stackFrame_A0[0]));
            a0_2 = (u8 *)*(u16 *)(s4 + 0xc);
            SfxMdl_SetColor((unsigned short)a0_2, *(float *)(s0 + 0x70), *(float *)(s0 + 0x74),
                *(float *)(s0 + 0x78));
            a0_2 = (u8 *)*(u16 *)(s4 + 0xc);
            SfxMdl_SetAlpha((unsigned short)a0_2, *(float *)(s0 + 0x7c));
            a0_2 = (u8 *)*(u16 *)(s4 + 0xc);
            SfxMdl_SetTexScroll((unsigned short)a0_2, *(float *)(s0 + 0x90), *(float *)(s0 + 0x94));
        }
        s0 = (u8 *)*(s32 *)(s0 + 0xa8);
    }
    s2 += 1;
    while (1) {
        _L001B08E8:;
        v1 = *(u8 *)(s3 + 0x46);
        a0_2 = (u8 *)s2;
        if ((s32)a0_2 >= (s32)v1) {
            break;
        }
        if ((u32)(s32)s0 != 0) {
            goto _L001B06A0;
        }
        break;
    }
    *(u32 *)(s3 + 0x48) = (s32)s6;
    *(u8 *)(s3 + 0x46) = (s32)s1;
    return;
}

/* __SFX_DrawPlume @ 0x1B0640 .. 0x1B0648 (0x8 bytes) */
/*
 * dcomp notes:
 *   a0 typed from the __SFX_DrawPlume call table
 *   a1 typed from the __SFX_DrawPlume call table
 *   a2 typed from the __SFX_DrawPlume call table
 */

static void __SFX_DrawPlume(u8 *a0 /* r4 */, u8 *a1 /* r5 */, u32 *a2 /* r6 */) {
    return;
}

/* __SFX_DrawPtclPlume @ 0x1B0630 .. 0x1B0638 (0x8 bytes) */
/*
 * dcomp notes:
 *   a0 typed from the __SFX_DrawPtclPlume call table
 *   a1 typed from the __SFX_DrawPtclPlume call table
 *   a2 typed from the __SFX_DrawPtclPlume call table
 */

static void __SFX_DrawPtclPlume(u8 *a0 /* r4 */, u8 *a1 /* r5 */, u32 *a2 /* r6 */) {
    return;
}

static void __SFX_EndPtclPlume(u16 *a0 /* r4 */, u8 *a1 /* r5 */, u32 *a2 /* r6 */) {
    u16 a0_narrow; // a0

    a0_narrow = *(u16 *)(((u8 *)a0 + 0xbc));
    if ((u32)a0_narrow != (u32)0xffff) {
        SfxMdl_Free(a0_narrow);
    }
    return;
}

void __SFX_InitModel2(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    u8 *s5;
    u8 *s4;
    u8 *s3;
    u32 t0;
    float f4;
    u32 a3;
    u8 *s2;
    u8 s1;
    u8 *s0;
    u8 *fp;
    float f2;
    float f1;
    float f0;
    float f21;
    float r;
    float f20;
    float *s7;
    u32 v1;
    u8 *s6;
    u32 v0;
    void *a0_2;
    void *a1_2;
    void *a2_2;
    u8 col[4];
    float spdz;
    float py;
    float yaw;

    s5 = (u8 *)a0;
    s4 = (u8 *)a1;
    s3 = (u8 *)*(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PFIXPARAM_98A49D1F);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571) = (s32)s3;
    v0 = *(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_1892300_FIELDS_PSEQPARAM_5F58AD5D);
    *(u32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20) = v0;
    sceVu0UnitMatrix(a0);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_0__0__E3B618C7) = *(float *)(s4 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_0__8126415D);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_1__1__D4A45AE9) = *(float *)(s4 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_1__0BD6BF01);
    *(f32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_MATRIX_2__2__351E5DD0) = *(float *)(s4 +
        DCOMP_OFF_STRUCT_DW_1890401_FIELDS_SCALE_2__2D9463C2);
    dcomp_cop2_9397A3F6B7((void *)((u8 *)s5), (void *)((u8 *)s4), (void *)((u8 *)s5));
    a0_2 = (void *)(s5 + 0x30);
    a1_2 = (void *)(s4 + 0x40);
    sceVu0CopyVector(a0_2, a1_2);
    v0 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_P_MATRIX_3EB5FB24);
    if (v0 != 0) {
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) = v0;
    } else {
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_MATRIX_94752F9B) = 0;
    }
    v1 = *(s16 *)(s3 + 2);
    if ((s32)v1 < 0) {
        v0 = 0x7fffffff;
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD) = 0x7fffffff;
    } else {
        v0 = *(u16 *)(s3 + 4);
        *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_LIFECNT_6B4F4CFD) = v1 + v0;
    }
    a0_2 = (void *)*(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
    v0 = (u32)_AllocPtcl((signed int)a0_2);
    *(u32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087) = v0;
    v1 = *(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A);
    s2 = (u8 *)*(s32 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    s1 = 0;
    if (0 < (s32)v1) {
        do {
            if ((u32)(s32)s2 == 0) {
                break;
            }
            *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510) = (u32)s5;
            v0 = *(s16 *)(s3 + 2);
            if ((s32)v0 < 0) {
                v0 = 0x7fffffff;
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = 0x7fffffff;
            } else {
                r = (float)(u16)SfxCalc_RandU32() * 1.5259022e-05f;
                *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_LIFECNT_2D709700) = (u32)((float)*(s16 *)(s3 + 2) + (float)*(u16 *)(s3 + 4) * (r - 0.5f));
            }
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC) = (s32)(100.0f * (r - 0.5f));
            r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
            *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_3__67BB3F3F) = (s32)(100.0f * (r - 0.5f));
            {
                float mRot[4][4] __attribute__((aligned(16)));
                float spd[4] __attribute__((aligned(16))) = {0};
                PTCL_RNDRANGE(spdz, *(float *)(s3 + 0x14), *(float *)(s3 + 0x18));
                spd[2] = spdz;
                PTCL_RNDRANGE(py, *(float *)(s3 + 0x1c), *(float *)(s3 + 0x20));
                PTCL_RNDRANGE(yaw, *(float *)(s3 + 0x24), *(float *)(s3 + 0x28));
                SfxCalc_MakeMatrixFromPYR((void *)mRot, 0.01745f * py, 0.01745f * yaw, 0.0f);
                sceVu0ApplyMatrix((void *)(s2 + 0x80), (void *)mRot, (void *)spd);
            }
            PTCL_RNDRANGE(f21, *(float *)(s3 + 0x2c), *(float *)(s3 + 0x30));
            PTCL_RNDRANGE(f20, *(float *)(s3 + 0x34), *(float *)(s3 + 0x38));
            PTCL_RNDRANGE(f1, *(float *)(s3 + 0x3c), *(float *)(s3 + 0x40));
            SfxCalc_MakeMatrixFromPYR((void *)s2, (0.01745f * f21), (0.01745f * f20), (0.01745f *
                f1));
            {
            u8 szFile[256] __attribute__((aligned(16)));
            float scl[8] __attribute__((aligned(16)));
            s7 = (float *)((u8 *)&scl[1]);
            fp = ((u8 *)&scl[2]);
            a0_2 = (void *)(s2 + 0x40);
            a2_2 = (void *)(s3 + 8);
            SfxUtil_CalcRndPos((float *)a0_2, *(u16 *)(s3 + 6), (float *)a2_2);
            s0 = (u8 *)*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510);
            t0 = *(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_CNT_43F0299F);
            v0 = *(s32 *)(s0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20);
            s6 = (u8 *)*(s32 *)(s0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571);
            a3 = *(s32 *)(v0 + DCOMP_OFF_STRUCT_DW_1905892_FIELDS__3__PKEYTOP_4BDB433E);
            SFX_GetSeqParam((void *)scl, 6, 2, (void *)a3, t0);
            v0 = *(u8 *)(s6 + DCOMP_OFF_STRUCT_DW_1904865_FIELDS__81__CDUMMY_9F800173);
            if (v0 != 0) {
                v1 = *(s8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038);
                f0 = (scl[0] + (*(float *)s7 * (0.01f *
                    (float)((float)(s32)v1))));
                *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_2__ED13F378) = f0;
                *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_1__0DD44650) = f0;
                *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_0__A4EC329F) = f0;
            } else {
                v0 = *(s32 *)(s0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20);
                t0 = *(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_CNT_43F0299F);
                a3 = *(s32 *)(v0 + DCOMP_OFF_STRUCT_DW_1905892_FIELDS__4__PKEYTOP_A9D4A4E0);
                SFX_GetSeqParam((void *)&scl[2], 6, 2, (void *)a3, t0);
                v0 = *(s32 *)(s0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20);
                t0 = *(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_CNT_43F0299F);
                a3 = *(s32 *)(v0 + DCOMP_OFF_STRUCT_DW_1905892_FIELDS__5__PKEYTOP_AC5C6D3D);
                SFX_GetSeqParam((void *)&scl[4], 6, 2, (void *)a3, t0);
                v1 = *(s8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_0__7BB46038);
                *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_0__A4EC329F) = (scl[0] + (*(float *)s7 * (0.01f * (float)((float)(s32)v1))));
                v1 = *(s8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_1__EBB2B76C);
                *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_1__0DD44650) = (scl[2] + (scl[3] * (0.01f *
                    (float)((float)(s32)v1))));
                v1 = *(s8 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RAND_2__28197DFC);
                *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_SCALE_2__ED13F378) = (scl[4] + (scl[5] *
                    (0.01f * (float)((float)(s32)v1))));
            }
            s0 = (u8 *)*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_PEMITTER_589B6510);
            t0 = *(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_CNT_43F0299F);
            v0 = *(s32 *)(s0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20);
            a3 = *(s32 *)(v0 + DCOMP_OFF_STRUCT_DW_1905892_FIELDS__6__PKEYTOP_609FF26B);
            SFX_GetSeqParam((void *)&col[0], 1, 3, (void *)a3, t0);
            f0 = ((float)(float)(u32)col[0] / 128.0f);
            *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_0__89D82EC2) = f0;
            f0 = ((float)(float)(u32)col[1] / 128.0f);
            *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_1__872F13A5) = f0;
            a1_2 = (void *)(s32)1;
            f0 = ((float)(float)(u32)col[2] / 128.0f);
            *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_2__2B1C9A34) = f0;
            v0 = *(s32 *)(s0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_SEQ_PARAM_24340A20);
            t0 = *(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_CNT_43F0299F);
            a3 = *(s32 *)(v0 + DCOMP_OFF_STRUCT_DW_1905892_FIELDS__7__PKEYTOP_A318AB84);
            SFX_GetSeqParam((void *)&col[3], (signed int)a1_2, (s32)a1_2, (void
                *)a3, t0);
            f0 = ((float)(float)(u32)col[3] / 128.0f);
            *(f32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_RGBA_3__47898D35) = f0;
            s0 = (u8 *)(s2 + 0xb0);
            v0 = SFX_ConfirmReflect((u32)*(u16 *)(s5 +
                DCOMP_OFF_STRUCT_DW_1891466_FIELDS_SFX_STTDATA_IDX_BFD85288), 0);
            a1_2 = (void *)v0;
            v0 = SfxMdl_Alloc(*(u16 *)s3, (signed int)a1_2);
            *(u16 *)(s0 + 4) = v0;
            v1 = *(u16 *)(s0 + 4);
            if (v1 == (u32)0xffff) {
                a1_2 = (void *)(char *)"PtclMng.c";
                strcpy((char *)szFile, (const char *)(char *)"PtclMng.c");
                a1_2 = (void *)(char *)"\x33\x44\xd3\xc3\xde\xd9\x8a\x84\x82\xe8\x93\x96\x82\xc4\x8e\xb8\x94\x73";
                SfxDbg_SetDebugMsg(0,
                    (char *)"\x33\x44\xd3\xc3\xde\xd9\x8a\x84\x82\xe8\x93\x96\x82\xc4\x8e\xb8\x94\x73", (char *)szFile, 0x1722);
            }
            a0_2 = (void *)*(u16 *)(s0 + 4);
            SfxMdl_SetZOffset((unsigned short)a0_2, *(float *)(s3 + 0x54));
            v1 = *(u8 *)(s5 + 0x6c);
            a0_2 = (void *)s2;
            if ((u32)(v1 & 1) == 0) {
                _Model2_SetMdlParamToMdlMng(a0_2);
            }
            }
            s2 = (u8 *)*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_1890884_FIELDS_P_SIBLING_EF412D76);
            s1 += 1;
        } while ((s32)s1 < (s32)*(u16 *)(s4 + DCOMP_OFF_STRUCT_DW_1890401_FIELDS_PTCL_NUM_0EF4998A));
    }
    *(u8 *)(s5 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_PTCL_NUM_6F459B2B) = s1;
    return;
}

void __SFX_ActModel2(void *a0 /* r4 */, float f12 /* f12 */) {
    u8 *s4;
    u8 *s3;
    u8 s6;
    u32 s7;
    u8 *s2;
    float f20;
    u8 *fp;
    u32 t0;
    u32 s5;
    u8 *s1;
    u8 *s0;
    u32 a3;
    u32 a2;
    u32 a1;
    u32 v1;
    u32 v0;
    float f2;
    float f1;
    float f0;
    float f3;
    u8 *a0_2;
    float gravity;
    u8 col[4];
    float ang[3] __attribute__((aligned(8)));
    float vec_gravity[4] __attribute__((aligned(16)));
    u8 szFile[256] __attribute__((aligned(16)));
    float vAdd[4] __attribute__((aligned(16)));
    u8 mrx[64] __attribute__((aligned(16)));
    float vt[4] __attribute__((aligned(16)));
    float scl[6] __attribute__((aligned(16)));
    u8 *p_ptcl_top;
    u32 calc_gravity;
    u8 *p_fix2;
    void *pm;

    fp = (u8 *)0;
    s4 = (u8 *)a0;
    s6 = 0;
    s3 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_FIX_PARAM_94012571);
    s7 = 0;
    f20 = (float)f12;
    s2 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_1891466_FIELDS_P_PTCL_TOP_2D76A087);
    p_ptcl_top = (u8 *)0;
    calc_gravity = 0;
    goto _L001AFA58;
    _L001AED28:;
    v0 = *(s32 *)(s2 + 0xa0);
    s5 = *(s32 *)(s2 + 0xa4);
    s1 = (u8 *)(s2 + 0xb0);
    if (v0 == 0) {
        s0 = (u8 *)s2;
        if ((u32)fp != 0) {
            v0 = *(s32 *)(s2 + 0xa8);
            *(u32 *)(fp + 0xa8) = v0;
        }
        a0_2 = (u8 *)*(s32 *)(s0 + 0xac);
        v1 = s_mngp;
        v0 = (u32)s_FuncTable;
        a0_2 = (u8 *)*(u16 *)(a0_2 + 0x44);
        a0_2 = (u8 *)(s32)((u32)a0_2 << 2);
        v1 = *(s32 *)(u32)(s32)((u8 *)(u32)*(s32 *)((v1 + 0x10)) + (u32)(a0_2));
        a0_2 = (u8 *)*(s32 *)v1;
        v0 = (s32)((u8 *)s_FuncTable + (s32)((u32)((u32)(a0_2)) * (u32)(0x14)));
        v0 = *(s32 *)((v0 + 0x10));
        s2 = (u8 *)*(s32 *)(s2 + 0xa8);
        if (v0 != 0) {
            a0_2 = (u8 *)s0;
            ((void (*)(s32))(s32)v0)((s32)a0_2);
        }
        a0_2 = (u8 *)s0;
        a2 = 0xe0;
        memset((void *)a0_2, 0, a2);
        v1 = *(s32 *)((s_mngp + 0x30));
        *(u32 *)(s0 + 0xa8) = v1;
        v1 = s_mngp;
        *(u32 *)((v1 + 0x30)) = (s32)s0;
        a0_2 = (u8 *)s_mngp;
        v1 = *(s16 *)(a0_2 + 0x38);
        v1 = v1 + -1;
        *(u16 *)(a0_2 + 0x38) = v1;
    } else {
        if (p_ptcl_top == 0) {
            p_ptcl_top = s2;
        }
        v1 = *(u8 *)(s3 + 0x50);
        v0 = 2;
        fp = (u8 *)s2;
        s7 = s7 + 1;
        switch (v1) {
        case 0:
            v0 = *(s32 *)(s4 + 0x50);
            a2 = 3;
            a3 = *(s32 *)((v0 + 0x14));
            SFX_GetSeqParam((void *)ang, 6, a2, (void *)a3, s5);
            *(f32 *)(s2 + 0x50) = (*(float *)(s2 + 0x50) + ((0.01745f * ang[0])
                * f20));
            f2 = (0.01745f * ang[1]);
            *(f32 *)(s2 + 0x54) = (*(float *)(s2 + 0x54) + (f2 * f20));
            *(f32 *)(s2 + 0x58) = (*(float *)(s2 + 0x58) + ((0.01745f * ang[2]) * f20));
            f12 = __SFX_ActModel2__inl0(s2);
            *(f32 *)(s2 + 0x58) = f12;
            break;
        case 1:
            v0 = *(s32 *)(s4 + 0x50);
            a2 = 3;
            a3 = *(s32 *)((v0 + 0x14));
            SFX_GetSeqParam((void *)ang, 6, a2, (void *)a3, s5);
            v0 = -0x3fb6f030;
            f3 = *(volatile float *)&ang[1];
            *(f32 *)(s2 + 0x54) = *(float *)(s2 + 0x54) + (0.01745f * f3) * f20;
            f12 = *(float *)(s2 + 0x50);
            f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
            *(f32 *)(s2 + 0x50) = f12;
            f12 = *(float *)(s2 + 0x54);
            f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
            *(f32 *)(s2 + 0x54) = f12;
            f12 = *(float *)(s2 + 0x58);
            f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
            *(f32 *)(s2 + 0x58) = f12;
            break;
        case 2:
            v0 = *(s32 *)(s4 + 0x50);
            a2 = 3;
            a3 = *(s32 *)((v0 + 0x14));
            SFX_GetSeqParam((void *)ang, 6, a2, (void *)a3, s5);
            *(f32 *)(s2 + 0x50) = (*(float *)(s2 + 0x50) + ((0.01745f * ang[0])
                * f20));
            f2 = (0.01745f * ang[1]);
            *(f32 *)(s2 + 0x54) = (*(float *)(s2 + 0x54) + (f2 * f20));
            *(f32 *)(s2 + 0x58) = (*(float *)(s2 + 0x58) + ((0.01745f * ang[2]) * f20));
            f12 = __SFX_ActModel2__inl0(s2);
            *(f32 *)(s2 + 0x58) = f12;
            break;
        default:
            a1 = (u32)(char *)"PtclMng.c";
            strcpy((char *)szFile, (const char *)(char *)"PtclMng.c");
            a1 = (u32)(char *)"Invalid angle control type";
            SfxDbg_SetDebugMsg(0, (char *)"Invalid angle control type", (char *)szFile,
                0x179b);
        }
        s0 = (u8 *)*(s32 *)(s2 + 0xac);
        t0 = *(s32 *)(s2 + 0xa4);
        a1 = 6;
        v0 = *(s32 *)(s0 + 0x4c);
        p_fix2 = (u8 *)v0;
        v0 = *(s32 *)(s0 + 0x50);
        a3 = *(s32 *)((v0 + 0x1c));
        SFX_GetSeqParam((void *)&scl[0], a1, 2, (void *)a3, t0);
        v0 = *(u8 *)(p_fix2 + 0x51);
        if (v0 != 0) {
            f0 = (scl[0] + (scl[1] * (0.01f * (float)*(s8 *)(s2 + 0x9c))));
            *(f32 *)(s2 + 0x68) = f0;
            *(f32 *)(s2 + 0x64) = f0;
            *(f32 *)(s2 + 0x60) = f0;
        } else {
            v0 = *(s32 *)(s0 + 0x50);
            t0 = *(s32 *)(s2 + 0xa4);
            a1 = 6;
            a3 = *(s32 *)((v0 + 0x24));
            SFX_GetSeqParam((void *)&scl[2], a1, 2, (void *)a3, t0);
            v0 = *(s32 *)(s0 + 0x50);
            t0 = *(s32 *)(s2 + 0xa4);
            a1 = 6;
            a3 = *(s32 *)((v0 + 0x2c));
            SFX_GetSeqParam((void *)&scl[4], a1, 2, (void *)a3, t0);
            *(f32 *)(s2 + 0x60) = (scl[0] + (scl[1] * (0.01f * (float)*(s8 *)(s2 + 0x9c))));
            *(f32 *)(s2 + 0x64) = (scl[2] + (scl[3] * (0.01f * (float)*(s8 *)(s2 + 0x9d))));
            *(f32 *)(s2 + 0x68) = (scl[4] + (scl[5] * (0.01f * (float)*(s8 *)(s2 + 0x9e))));
        }
        sceVu0ScaleVector((void *)vAdd, (void *)(s2 + 0x80), (float)f20);
        a0_2 = (u8 *)(s2 + 0x40);
        sceVu0AddVector((void *)a0_2, (void *)a0_2, (void *)vAdd);
        v0 = *(s32 *)(s4 + 0x50);
        a1 = 6;
        a3 = *(s32 *)((v0 + 0xc));
        SFX_GetSeqParam((void *)&gravity, a1, 1, (void *)a3, s5);
        f0 = gravity;
        if (!(0.0f == f0)) {
            if (calc_gravity == 0) {
                pm = *(void **)(s4 + 0x40);
                if (pm != 0) {
                    dcomp_cop2_9397A3F6B7((void *)mrx, pm, (void *)s4);
                } else {
                    sceVu0CopyMatrix((void *)mrx, (void *)s4);
                }
                sceVu0InversMatrix((void *)mrx, (void *)mrx);
                sceVu0ApplyMatrix((void *)vec_gravity, (void *)mrx, (void *)VY);
                calc_gravity = 1;
            }
            f0 = gravity;
            sceVu0ScaleVector((void *)vt, (void *)vec_gravity,
                (f0 * f20));
            a0_2 = (u8 *)(s2 + 0x80);
            sceVu0AddVector((void *)a0_2, (void *)vt, (void *)a0_2);
        }
        s0 = (u8 *)*(s32 *)(s2 + 0xac);
        t0 = *(s32 *)(s2 + 0xa4);
        a1 = 1;
        v0 = *(s32 *)(s0 + 0x50);
        a3 = *(s32 *)((v0 + 0x34));
        a2 = 3;
        SFX_GetSeqParam((void *)&col[0], a1, a2, (void *)a3, t0);
        f0 = ((float)(float)(u32)col[0] / 128.0f);
        *(f32 *)(s2 + 0x70) = f0;
        f0 = ((float)(float)(u32)col[1] / 128.0f);
        *(f32 *)(s2 + 0x74) = f0;
        a1 = 1;
        f0 = ((float)(float)(u32)col[2] / 128.0f);
        *(f32 *)(s2 + 0x78) = f0;
        v0 = *(s32 *)(s0 + 0x50);
        t0 = *(s32 *)(s2 + 0xa4);
        a3 = *(s32 *)((v0 + 0x3c));
        SFX_GetSeqParam((void *)&col[3], a1, a1, (void *)a3, t0);
        f1 = (float)(u32)col[3];
        v0 = 1;
        *(f32 *)(s2 + 0x7c) = (f1 / 128.0f);
        v1 = *(u8 *)(s3 + 0x47);
        switch (v1) {
        case 0: {
            u32 fcnt;
            float fu;
            float fv;
            float one;
            u32 tw;
            u32 th;
            s32 idx;
            fcnt = *(u32 *)s1;
            tw = *(u8 *)(s3 + 0x45);
            th = *(u8 *)(s3 + 0x46);
            idx = (s32)((float)fcnt * *(float *)(s3 + 0x48));
            fu = (float)(u16)(idx % (u16)tw);
            one = 1.0f;
            *(f32 *)(s2 + 0x90) = fu * (one / (float)tw);
            one = 1.0f;
            *(f32 *)(s2 + 0x94) = (float)(u16)((idx / (u16)tw) % (u16)th) * (one / (float)th);
            break;
        }
        case 1:
            v0 = *(s32 *)s1;
            *(f32 *)(s2 + 0x90) = ((float)(float)v0 * *(float *)(s3 + 0x48));
            v0 = *(s32 *)s1;
            f2 = (float)v0;
            *(f32 *)(s2 + 0x94) = (f2 * *(float *)(s3 + 0x4c));
            f1 = *(float *)(s2 + 0x90);
            if (1.0f < f1) {
                *(f32 *)(s2 + 0x90) = (f1 - (float)((float)(s32)f1));
            }
            f1 = *(float *)(s2 + 0x94);
            if (1.0f < f1) {
                *(f32 *)(s2 + 0x94) = (f1 - (float)((float)(s32)f1));
            }
            f1 = *(float *)(s2 + 0x90);
            if (f1 < 0.0f) {
                *(f32 *)(s2 + 0x90) = 1.0f + (f1 - (float)(s32)f1);
            }
            f1 = *(float *)(s2 + 0x94);
            if (f1 < 0.0f) {
                *(f32 *)(s2 + 0x94) = 1.0f + (f1 - (float)(s32)f1);
            }
        }
        v1 = *(s32 *)s1;
        v0 = 0x7fffffff;
        v1 = v1 + 1;
        *(u32 *)s1 = v1;
        v1 = *(s32 *)(s2 + 0xa0);
        if (v1 != v0) {
            v0 = v1 + -1;
            *(u32 *)(s2 + 0xa0) = v0;
        }
        v0 = *(s32 *)(s2 + 0xa4);
        v0 = v0 + 1;
        *(u32 *)(s2 + 0xa4) = v0;
        v1 = *(u16 *)(s3 + 0x52);
        if (v1 != 0 && v1 <= (u32)*(s32 *)(s2 + 0xa4)) {
            *(u32 *)(s2 + 0xa4) = 0;
        }
        v0 = (((struct { u8 f0:1; u8 f1:1; u8 pad:6; } *)(s4 + 0x6c))->f0 != 0 || ((struct { u8 f0:1; u8 f1:1; u8 pad:6; } *)(s4 + 0x6c))->f1 != 0) ^ 1;
        if (v0 != 0) {
            a0_2 = (u8 *)s2;
            _Model2_SetMdlParamToMdlMng((void *)a0_2);
            a0_2 = (u8 *)*(u16 *)(s1 + 4);
            SfxMdl_EnableDraw((unsigned short)a0_2, 1);
        } else {
            a0_2 = (u8 *)*(u16 *)(s1 + 4);
            SfxMdl_EnableDraw((unsigned short)a0_2, 0);
        }
        s2 = (u8 *)*(s32 *)(s2 + 0xa8);
    }
    s6 += 1;
    while (1) {
        _L001AFA58:;
        v1 = *(u8 *)(s4 + 0x46);
        a0_2 = (u8 *)s6;
        if ((s32)a0_2 >= (s32)v1) {
            break;
        }
        if ((u32)(s32)s2 != 0) {
            goto _L001AED28;
        }
        break;
    }
    *(u32 *)(s4 + 0x48) = (s32)p_ptcl_top;
    *(u8 *)(s4 + 0x46) = s7;
    return;
}

static void _Model2_SetMdlParamToMdlMng(void *pPtcl__) {
    struct dw_1890884_fields *pPtcl_;
    struct dw_1891466_fields *p_sfx;
    struct M2_ExtData *p_ext_data;
    float mrx[4][4] __attribute__((aligned(16)));
    float mPYR[4][4] __attribute__((aligned(16)));
    float dir[4] __attribute__((aligned(16)));
    float pos[4] __attribute__((aligned(16)));
    float mRot[4][4] __attribute__((aligned(16)));
    float mCam[4][4] __attribute__((aligned(16)));
    float mScale[4][4] __attribute__((aligned(16)));

    pPtcl_ = (struct dw_1890884_fields *)pPtcl__;
    p_sfx = pPtcl_->pEmitter;
    p_ext_data = (struct M2_ExtData *)pPtcl_->extra_data;
    switch (*((unsigned char *)p_sfx->p_fix_param + 0x50)) {
    case 0:
        SfxCalc_MakeMatrixFromPYR(mPYR, pPtcl_->ang[0], pPtcl_->ang[1], pPtcl_->ang[2]);
        dcomp_cop2_9397A3F6B7(mrx, pPtcl_->mRot, mPYR);
        sceVu0CopyVector(mrx[3], pPtcl_->loc);
        dcomp_cop2_9397A3F6B7(mrx, p_sfx->matrix, mrx);
        if (p_sfx->p_matrix != 0) {
            dcomp_cop2_9397A3F6B7(mrx, *p_sfx->p_matrix, mrx);
        }
        break;
    case 1: {
        float v[4] = {0};
        v[1] = pPtcl_->ang[1];
        SfxCalc_MakeMatrixFromPYR(mrx, v[0], *(float *)((u8 *)v + 4), v[2]);
        sceVu0CopyVector(mrx[3], pPtcl_->loc);
        dcomp_cop2_9397A3F6B7(mrx, p_sfx->matrix, mrx);
        if (p_sfx->p_matrix != 0) {
            dcomp_cop2_9397A3F6B7(mrx, *p_sfx->p_matrix, mrx);
        }
        sceVu0CopyVector(dir, mrx[2]);
        sceVu0CopyVector(pos, mrx[3]);
        dir[1] = 0;
        sceVu0Normalize(dir, dir);
        SfxCalc_MakeMatrixFromDir(mrx, dir);
        sceVu0CopyVector(mrx[3], pos);
        break;
    }
    case 2:
        sceVu0CopyVector(mrx[0], VX);
        sceVu0CopyVector(mrx[1], VY);
        sceVu0CopyVector(mrx[2], VZ);
        sceVu0CopyVector(mrx[3], pPtcl_->loc);
        dcomp_cop2_9397A3F6B7(mrx, p_sfx->matrix, mrx);
        if (p_sfx->p_matrix != 0) {
            dcomp_cop2_9397A3F6B7(mrx, *p_sfx->p_matrix, mrx);
        }
        SfxCalc_MakeMatrixFromPYR(mRot, pPtcl_->ang[0], pPtcl_->ang[1], pPtcl_->ang[2]);
        SfxCalc_MakeMatrixFromPYR(mCam, ((struct dw_1892708_fields *)lpDrawMng)->camAng[0],
            ((struct dw_1892708_fields *)lpDrawMng)->camAng[1],
            ((struct dw_1892708_fields *)lpDrawMng)->camAng[2]);
        sceVu0ScaleVector(mCam[0], mCam[0], -1.0f);
        sceVu0ScaleVector(mCam[2], mCam[2], -1.0f);
        dcomp_cop2_9397A3F6B7(mRot, mCam, mRot);
        sceVu0ScaleVector(mrx[0], mRot[0], sqrtf(sceVu0InnerProduct(p_sfx->matrix[0], p_sfx->matrix[0])));
        sceVu0ScaleVector(mrx[1], mRot[1], sqrtf(sceVu0InnerProduct(p_sfx->matrix[1], p_sfx->matrix[1])));
        sceVu0ScaleVector(mrx[2], mRot[2], sqrtf(sceVu0InnerProduct(p_sfx->matrix[2], p_sfx->matrix[2])));
        break;
    }
    sceVu0ScaleVector(mScale[0], VX, pPtcl_->scale[0]);
    sceVu0ScaleVector(mScale[1], VY, pPtcl_->scale[1]);
    sceVu0ScaleVector(mScale[2], VZ, pPtcl_->scale[2]);
    sceVu0CopyVector(mScale[3], VW);
    dcomp_cop2_9397A3F6B7(mrx, mrx, mScale);
    SfxMdl_SetMatrix(p_ext_data->mdl_id, mrx);
    SfxMdl_SetColor(p_ext_data->mdl_id, pPtcl_->rgba[0], pPtcl_->rgba[1], pPtcl_->rgba[2]);
    SfxMdl_SetAlpha(p_ext_data->mdl_id, pPtcl_->rgba[3]);
    SfxMdl_SetTexScroll(p_ext_data->mdl_id, pPtcl_->add_uv[0], pPtcl_->add_uv[1]);
}

static void __SFX_EndPtclModel2(u16 *a0 /* r4 */, u8 *a1 /* r5 */, u32 *a2 /* r6 */) {
    u16 a0_narrow; // a0

    a0_narrow = *(u16 *)(((u8 *)a0 + 0xb4));
    if ((u32)a0_narrow != (u32)0xffff) {
        SfxMdl_Free(a0_narrow);
    }
    return;
}
