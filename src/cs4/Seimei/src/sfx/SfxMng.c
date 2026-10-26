#include "common.h"

#ifndef PROTO_DW_2106543
#define PROTO_DW_2106543
struct dw_2106543 { float loc[4]; float ang[4]; float scale[4]; float rgba[4]; };
#endif
#ifndef PROTO_DW_2095879
#define PROTO_DW_2095879
struct dw_2095879 { unsigned char f_independent : 1; unsigned char f_disable_draw : 1; unsigned char f_disable_draw_by_map : 1; unsigned char f_disable_act : 1; unsigned char f_disable_act_by_map : 1; unsigned char f_dummy : 3; };
#endif
#ifndef PROTO_DW_2094394
#define PROTO_DW_2094394
struct dw_2094394 { struct dw_2106543 pb; struct dw_2094394 *pRoot; struct dw_2096304 *p_sfx_data; struct dw_2103726 *p_fix_param; struct dw_2104139 *p_seq_param; struct dw_2094394 *p_parent; struct dw_2094394 *p_child; struct dw_2094394 *p_sibling; struct dw_2094394 *p_prev_sibling; float (*p_matrix)[4][4]; float (*p_parent_matrix)[4][4]; void *p_arg; char *p_data; unsigned int life_cnt; unsigned int cnt; int ptcl_handle; unsigned char atk_no; unsigned char dmg_char_id; struct dw_2095879 flags; unsigned char prog_no; };
#endif
#ifndef PROTO_DW_2101295
#define PROTO_DW_2101295
struct dw_2101295 { float radius; float speed; float scale; float rnd_range; unsigned int tex_no; float rgb[3]; float life; char dmy[12]; };
#endif
typedef struct SfxKill_Handle { u32 state; u32 serial : 20; } SfxKill_Handle;
typedef struct SfxKill_Sfx { u8 b[0x80]; } SfxKill_Sfx;
typedef struct SfxKill_Mng { u8 pad[0x10]; SfxKill_Sfx *sfx; u8 pad2[8]; SfxKill_Handle *handle; } SfxKill_Mng;
extern void sceVu0CopyVector(void *, void *);
extern unsigned short SfxBugs_Create(void *);
extern void * memset(void *, int, unsigned int);
extern u32 s_pSfxMng;
extern void * GetDummyPolyData(void *, unsigned char, unsigned char);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern void sceVu0SubVector(void *, void *, void *);
extern void sceVu0Normalize(void *, void *);
extern void SfxCalc_QtnMakeFromDir(float *, float *);
extern signed int SFX_GetSeqParam(void *, signed int, signed int, void *, signed int);
extern void SfxCalc_QtnSLerp(float *, float *, float *, float);
extern void SfxCalc_DirMakeFromQtn(float *, float *);
extern void sceVu0ScaleVector(void *, void *, float);
extern void sceVu0AddVector(void *, void *, void *);
extern void SfxCalc_MakeMatrixFromQtn(void *, float *);
extern u8 GameSt[];
extern u8 MdlMng[];
extern signed int SfxMdl_Free(unsigned short);
static void _SubFunc_Plume_Move(void *, float);
extern signed int SfxMdl_SetMatrix(unsigned short, void *);
extern void DeleteAppearEffect(signed int);
extern void UpdateAppearEffect(signed int, float *, float);
static char * __SFXMNG_DataAlloc(signed int);
extern signed int SetAppearEffect(float *, float);
extern void SfxDomanString_SetPos(float *);
extern void SfxDomanString_SetAzim(float);
extern void SfxDomanString_Start(float, unsigned short);
extern void SetCamVibration(void *);
extern void StartCamVibration(float, signed int);
extern signed int SfxPLight_Delete(unsigned short, float);
extern unsigned short SfxPLight_Create(float);
extern signed int SfxPLight_EnableBlink(unsigned short, signed int);
extern signed int SfxPLight_SetBlink(unsigned short, float, float);
extern signed int SfxPLight_EnableWindEffect(unsigned short, signed int);
extern signed int SfxPLight_SetWindParam(unsigned short, float, float);
extern signed int SfxPLight_EnableShadow(unsigned short, signed int);
extern void SND_Stop(signed int);
extern float sceVu0InnerProduct(void *, void *);
extern float CheckHitMapLineGetNormal(void *, void *, void *);
extern signed int SFX_Create_OnDir(unsigned short, float *, float *);
extern signed int SFX_Create_OnAng(unsigned short, float *, float *);
static signed int __SFXMNG_SfxDelete(void *, signed int);
extern void SetDamageMng(void *, unsigned char, void *, float, unsigned char, void *, void *,
    signed short, unsigned char);
extern void __SFXMNG_HitObject_EneHit_CallBack(void *, void *);
extern void SfxCalc_Vector2Angle(float *, float *);
extern void SfxCalc_MakeMatrixFromPYR(void *, float, float, float);
extern char * strcpy(char *, const char *);
extern void SfxDbg_SetDebugMsg(unsigned char, char *, char *, unsigned int);
extern signed int PtclMng_SfxFreeAll(signed int);
extern void SfxCalc_MakeRotTransMatrix_I(void *, float *, float *, float *);
extern u32 MRX1[];
static signed int __SFXMNG_Bugs_Init(struct dw_2094394 *a0 /* r4 */);
static signed int __SFXMNG_DmyPolyHoming_End(void *a0 /* r4 */);
static signed int __SFXMNG_DmyPolyHoming_Act(void *a0 /* r4 */);
static signed int __SFXMNG_Plume_End(void *a0 /* r4 */);
static signed int __SFXMNG_Plume_Act(void *a0 /* r4 */);
static signed int __SFXMNG_WhirlPool_End(void *a0 /* r4 */);
static signed int __SFXMNG_WhirlPool_Act(void *a0 /* r4 */);
static signed int __SFXMNG_WhirlPool_Init(void *a0 /* r4 */);
static u32 __SFXMNG_EventCall_Act(u32 *a0 /* r4 */);
static signed int __SFXMNG_EventCall_Init(void *a0 /* r4 */);
static signed int __SFXMNG_Ground_End(void *a0 /* r4 */);
static u32 __SFXMNG_CameraVib_Act(u32 *a0 /* r4 */);
static signed int __SFXMNG_CameraVib_Init(void *a0 /* r4 */);
static signed int __SFXMNG_PLight_End(void *a0 /* r4 */);
static signed int __SFXMNG_PLight_Init(void *a0 /* r4 */);
static signed int __SFXMNG_SE_End(void *a0 /* r4 */);
static signed int __SFXMNG_SE_Init(void *a0 /* r4 */);
static signed int __SFXMNG_Spirit_Init(void *a0 /* r4 */);
static signed int __SFXMNG_HitObject_Act(void *a0 /* r4 */);
static signed int __SFXMNG_HitObject_Init(void *a0 /* r4 */);
static signed int __SFXMNG_CallSfx_Init(void *a0 /* r4 */);
static signed int __SFXMNG_CallEmitter_End(void *a0 /* r4 */);
static signed int __SFXMNG_CallEmitter_Init(void *a0 /* r4 */);
static signed int __SFXMNG_Default2_End(void *a0 /* r4 */);
static signed int __SFXMNG_Default_End(void *a0 /* r4 */);
unsigned char SfxMng_GetSfxState(signed int a0 /* r4 */);
signed int SfxMng_AttachMatrix(signed int a0 /* r4 */, void *a1 /* r5 */);
void SfxMng_DeleteAll(signed int a0 /* r4 */);
signed int SfxMng_Kill(signed int handle);
signed int SfxMng_SetPos(signed int a0 /* r4 */, float *a1 /* r5 */);



/* SfxMng_InitSystem @ 0x1CDFC0 .. 0x1CE1C0 (0x200 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   literal: __FUNCTION__$921 is the string 'SfxMng_InitSystem'
 *   literal: @6516 is the string ''
 */

extern void * MemAllocAlignReal(unsigned int, unsigned int, char *, char *);
extern signed int SFX_DataRemap(char *, void *, signed int);
extern void _InitFireAttachData(void);
extern u32 s_SfxMng[];




/* SfxMng_SfxCreate @ 0x1CDEB0 .. 0x1CDFB4 (0x104 bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @2740 is the string 'SfxMng.c'
   literal: @6476 is the string 'SFX Create Failed'
 *   stack: address of the slot at 0x20 escapes at 0x1cdf28
 *   stack: address of the slot at 0x20 escapes at 0x1cdf40
 *   cfg: kept goto: 0x1cdf6c -> .L001CDF84
 *   a1 takes slot 1 only because of the ABI order
 *   a3 takes slot 3 only because of the ABI order
 *   t0 takes slot 4 only because of the ABI order
 *   t1 takes slot 5 only because of the ABI order
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

static void * __SFXMNG_SfxCreateFromData(void *, float *, float *, float *, void *, void *, void *,
    unsigned char, unsigned char);









struct dw_2094394;
struct dw_2096304;
struct dw_2103726;
struct dw_2104139;








static void __SFXMNG_ProcOne(void *, float);
struct ManualSfxEntry { u8 state; u8 pad[5]; unsigned short low:4; unsigned short high:12; };



















extern signed int PtclMng_UpdateHandle(signed int);
static void *__SFXMNG_SfxCreateFromData(void *,float *,float *,float *,void *,void *,void *,unsigned char,unsigned char);
extern u32 s_FuncTable[];



extern u32 VW[];
extern u32 V1[];
struct SfxNode { u8 pad[0x54]; struct SfxNode *child; struct SfxNode *next; struct SfxNode *prev; };
struct SfxCreateEnt { u8 state; u8 pad[3]; u32 serial : 20; u32 rest : 12; };








/* __SFXMNG_SfxDelete @ 0x1CD310 .. 0x1CD6E4 (0x3d4 bytes, frame 0x70) */
struct SfxDelMng { u8 pad[0x24]; u32 count; u32 first; u32 *mask; };








extern signed int PtclMng_EnableDraw(signed int, signed int, unsigned short);







extern signed int PtclMng_EnableAction(signed int, signed int, unsigned short);



/* __SFXMNG_Default_Init @ 0x1CC4B0 .. 0x1CC948 (0x498 bytes, frame 0x180) */
/*
 * dcomp notes:
 *   literal: @2740 is the string 'SfxMng.c'
 *   literal: @2741 is the string 'Failed to alloc matrix.'
 *   stack: address of the slot at 0x80 escapes at 0x1cc4e8
 *   stack: address of the slot at 0x80 escapes at 0x1cc500
 *   delay: daddu at 0x1cc510 writes a register its branch at 0x1cc50c reads
 *   fpu: mtc1 reinterprets v0 at 0x1cc554
 *   fpu: mtc1 reinterprets v1 at 0x1cc568
 *   fpu: float literal 0x37800080 at 0x1cc584
 *   fpu: mtc1 reinterprets v0 at 0x1cc590
 *   fpu: mtc1 reinterprets v1 at 0x1cc5a8
 *   fpu: float literal 0x3f000000 at 0x1cc5c0
 *   fpu: mtc1 reinterprets v0 at 0x1cc5d4
 *   fpu: mtc1 reinterprets v1 at 0x1cc5ec
 *   fpu: float literal 0x4f000000 at 0x1cc604
 *   fpu: mtc1 reinterprets v0 at 0x1cc658
 *   fpu: mtc1 reinterprets v1 at 0x1cc66c
 *   fpu: float literal 0x37800080 at 0x1cc688
 *   fpu: float literal 0x3f000000 at 0x1cc68c
 *   fpu: float literal 0x3c8ef34d at 0x1cc6b0
 *   fpu: mtc1 reinterprets v0 at 0x1cc6d4
 *   fpu: mtc1 reinterprets v1 at 0x1cc6e8
 *   fpu: float literal 0x37800080 at 0x1cc704
 *   fpu: float literal 0x3f000000 at 0x1cc708
 *   fpu: float literal 0x3c8ef34d at 0x1cc734
 *   fpu: float literal 0xc0490fd0 at 0x1cc74c
 *   fpu: float literal 0x40490fd0 at 0x1cc764
 *   fpu: float literal 0x40c90fd0 at 0x1cc790
 *   fpu: float literal 0xc0490fd0 at 0x1cc7ac
 *   fpu: float literal 0x40490fd0 at 0x1cc7c4
 *   fpu: float literal 0x40c90fd0 at 0x1cc7f0
 *   fpu: float literal 0xc0490fd0 at 0x1cc80c
 *   fpu: float literal 0x40490fd0 at 0x1cc824
 *   fpu: float literal 0x40c90fd0 at 0x1cc850
 *   fpu: mtc1 reinterprets v0 at 0x1cc8b4
 *   fpu: mtc1 reinterprets v1 at 0x1cc8c8
 *   fpu: float literal 0x37800080 at 0x1cc8e8
 *   fpu: float literal 0x3f000000 at 0x1cc900
 *   stack: address of the slot at 0x40 escapes at 0x1cc914
 *   stack: address of the slot at 0x40 escapes at 0x1cc924
 *   cfg: kept branch: 0x1cc764 if (..) goto .L001CC780
 *   cfg: kept branch: 0x1cc7c4 if (..) goto .L001CC7E0
 *   cfg: kept branch: 0x1cc824 if (..) goto .L001CC840
 *   v0#5 is the pointer held in a0+0x6c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern unsigned int SfxCalc_RandU32(void);
extern float SfxCalc_IntoAngle_0_2PI(float);
extern u32 V0[];

struct dw_2094394_fields;
struct dw_2096304_fields;
struct dw_2103726_fields;
struct dw_2104139_fields;
#ifndef PROTO_DW_2106543_FIELDS
#define PROTO_DW_2106543_FIELDS
struct dw_2106543_fields { float loc[4]; float ang[4]; float scale[4]; float rgba[4]; };
#endif
#ifndef PROTO_DW_2095879_FIELDS
#define PROTO_DW_2095879_FIELDS
struct dw_2095879_fields { unsigned char f_independent : 1; unsigned char f_disable_draw : 1; unsigned char f_disable_draw_by_map : 1; unsigned char f_disable_act : 1; unsigned char f_disable_act_by_map : 1; unsigned char f_dummy : 3; };
#endif
#ifndef PROTO_DW_2094394_FIELDS
#define PROTO_DW_2094394_FIELDS
struct dw_2094394_fields { struct dw_2106543_fields pb; struct dw_2094394_fields *pRoot; struct dw_2096304_fields *p_sfx_data; struct dw_2103726_fields *p_fix_param; struct dw_2104139_fields *p_seq_param; struct dw_2094394_fields *p_parent; struct dw_2094394_fields *p_child; struct dw_2094394_fields *p_sibling; struct dw_2094394_fields *p_prev_sibling; float (*p_matrix)[4][4]; float (*p_parent_matrix)[4][4]; void *p_arg; char *p_data; unsigned int life_cnt; unsigned int cnt; int ptcl_handle; unsigned char atk_no; unsigned char dmg_char_id; struct dw_2095879_fields flags; unsigned char prog_no; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_LIFE_CNT_84B35CAE_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_LIFE_CNT_84B35CAE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_LIFE_CNT_84B35CAE = (int)&(((struct dw_2094394_fields *)0)->life_cnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9 = (int)&(((struct dw_2094394_fields *)0)->p_data) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214 = (int)&(((struct dw_2094394_fields *)0)->p_fix_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF = (int)&(((struct dw_2094394_fields *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_0__A42E032D_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_0__A42E032D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_0__A42E032D = (int)&(((struct dw_2094394_fields *)0)->pb.ang[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_1__0FE27C30_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_1__0FE27C30_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_1__0FE27C30 = (int)&(((struct dw_2094394_fields *)0)->pb.ang[1]) - 0 };
#endif


extern void SfxCalc_Angle2VectorZXY(float *, float *);
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif



/* __SFXMNG_Default2_Init @ 0x1CBB20 .. 0x1CBFD8 (0x4b8 bytes, frame 0x180) */
/*
 * dcomp notes:
 *   literal: @2740 is the string 'SfxMng.c'
 *   literal: @2741 is the string 'Failed to alloc matrix.'
 *   stack: address of the slot at 0x80 escapes at 0x1cbb58
 *   stack: address of the slot at 0x80 escapes at 0x1cbb70
 *   delay: daddu at 0x1cbb80 writes a register its branch at 0x1cbb7c reads
 *   fpu: mtc1 reinterprets v0 at 0x1cbbc4
 *   fpu: mtc1 reinterprets v1 at 0x1cbbd8
 *   fpu: float literal 0x37800080 at 0x1cbbf4
 *   fpu: mtc1 reinterprets v0 at 0x1cbc00
 *   fpu: mtc1 reinterprets v1 at 0x1cbc18
 *   fpu: float literal 0x3f000000 at 0x1cbc30
 *   fpu: mtc1 reinterprets v0 at 0x1cbc44
 *   fpu: mtc1 reinterprets v1 at 0x1cbc5c
 *   fpu: float literal 0x4f000000 at 0x1cbc74
 *   delay: addiu at 0x1cbcc0 writes a register its branch at 0x1cbcbc reads
 *   fpu: mtc1 reinterprets v0 at 0x1cbcf4
 *   fpu: mtc1 reinterprets v1 at 0x1cbd08
 *   fpu: float literal 0x37800080 at 0x1cbd24
 *   fpu: float literal 0x3f000000 at 0x1cbd28
 *   fpu: float literal 0x3c8ef34d at 0x1cbd4c
 *   fpu: mtc1 reinterprets v0 at 0x1cbd70
 *   fpu: mtc1 reinterprets v1 at 0x1cbd84
 *   fpu: float literal 0x37800080 at 0x1cbda0
 *   fpu: float literal 0x3f000000 at 0x1cbda4
 *   fpu: float literal 0x3c8ef34d at 0x1cbdd0
 *   fpu: float literal 0xc0490fd0 at 0x1cbde8
 *   fpu: float literal 0x40490fd0 at 0x1cbe00
 *   fpu: float literal 0x40c90fd0 at 0x1cbe2c
 *   fpu: float literal 0xc0490fd0 at 0x1cbe48
 *   fpu: float literal 0x40490fd0 at 0x1cbe60
 *   fpu: float literal 0x40c90fd0 at 0x1cbe8c
 *   fpu: float literal 0xc0490fd0 at 0x1cbea8
 *   fpu: float literal 0x40490fd0 at 0x1cbec0
 *   fpu: float literal 0x40c90fd0 at 0x1cbeec
 *   delay: addiu at 0x1cbf0c writes a register its branch at 0x1cbf08 reads
 *   fpu: mtc1 reinterprets v0 at 0x1cbf40
 *   fpu: mtc1 reinterprets v1 at 0x1cbf54
 *   fpu: float literal 0x37800080 at 0x1cbf70
 *   fpu: float literal 0x3f000000 at 0x1cbf7c
 *   stack: address of the slot at 0x40 escapes at 0x1cbfa4
 *   stack: address of the slot at 0x40 escapes at 0x1cbfb4
 *   cfg: kept branch: 0x1cbe00 if (..) goto .L001CBE1C
 *   cfg: kept branch: 0x1cbe60 if (..) goto .L001CBE7C
 *   cfg: kept branch: 0x1cbec0 if (..) goto .L001CBEDC
 *   v0#5 is the pointer held in a0+0x6c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */








#ifndef PROTO_DW_2106543_FIELDS
#define PROTO_DW_2106543_FIELDS

#endif
#ifndef PROTO_DW_2095879_FIELDS
#define PROTO_DW_2095879_FIELDS

#endif
#ifndef PROTO_DW_2094394_FIELDS
#define PROTO_DW_2094394_FIELDS

#endif
#ifndef PROTO_DW_2103726_FIELDS
#define PROTO_DW_2103726_FIELDS
struct dw_2103726_fields { char cdummy; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_LIFE_CNT_84B35CAE_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_LIFE_CNT_84B35CAE_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_0__A42E032D_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_0__A42E032D_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_1__0FE27C30_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_1__0FE27C30_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_2103726_FIELDS__56__CDUMMY_6528F9A2_DEFINED
#define DCOMP_OFF_STRUCT_DW_2103726_FIELDS__56__CDUMMY_6528F9A2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2103726_FIELDS__56__CDUMMY_6528F9A2 = (int)&(((struct dw_2103726_fields *)0)[56].cdummy) - 0 };
#endif








#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif


extern float SfxCalc_IntoAngle_0_2PI(float);
extern void SfxCalc_PYRfromRotMatrix(void *, float *, float *, float *);
extern void sceVu0CopyMatrix(void *, void *);
extern signed int PtclMng_SfxCreate(void *);
extern unsigned int SfxCalc_RandU32(void);
extern u32 VW[];

struct dw_2105820 {
    unsigned int id;
    int life;
    unsigned int frame;
    unsigned int num;
    unsigned short independent;
    unsigned short kill_ptcl;
    float loc[3];
    float ang[3];
    unsigned short call_num;
    short gen_rnd;
};

struct dw_2109473 {
    unsigned short gen_wait;
    unsigned short call_num;
};

struct dw_2094099 {
    unsigned int Frame;
    char szName[26];
    unsigned short sfx_idx;
};

struct dw_2096304 {
    int ProgramId;
    void *pParent;
    void *pChild;
    void *pSibling;
    int FixParamNum;
    void *pFixParam;
    int SeqParamNum;
    void *pSeqParam;
    struct dw_2094099 CommonParam;
};

struct dw_2113189 {
    unsigned char disable_draw_scr : 1;
    unsigned char disable_draw_map : 1;
    unsigned char disable_act_scr : 1;
    unsigned char disable_act_map : 1;
    unsigned char unused : 4;
};

struct dw_2110996 {
    float mRot[4][4];
    float loc[4];
    float ang[4];
    float scale[4];
    float (*p_matrix)[4][4];
    int prev_ptcl;
    short life_time;
    unsigned short ptcl_num;
    unsigned short prog_no;
    struct dw_2113189 flag;
    unsigned short sfx_sttdata_idx;
    unsigned char _pad0[14];
};

#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif



extern void SfxCalc_MakeMatrix_SPYRT(void *, float *, float *, float *);



#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif













struct HitCleanupManager {
    u8 pad[0x24];
    u32 count;
    u32 first;
    u32 *mask;
};




extern void NM_GetPcHeadPos(float *);
extern float Math_GetDist(float *, float *);
extern void sceVu0RotMatrixX(void *, void *, float);
extern void sceVu0RotMatrixY(void *, void *, float);
static float param1_1948[1] = {0.5f};
static float param2_1949[1] = {0.3f};








/* __SFXMNG_SE_Act @ 0x1C9920 .. 0x1C9BE0 (0x2c0 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42700000 at 0x1c992c
 *   fpu: float literal 0x4f000000 at 0x1c9940
 *   delay: addiu at 0x1c9994 writes a register its branch at 0x1c9990 reads
 *   fpu: mtc1 reinterprets v0 at 0x1c9a34
 *   fpu: mtc1 reinterprets v1 at 0x1c9a48
 *   fpu: float literal 0x37800080 at 0x1c9a64
 *   fpu: mtc1 reinterprets v0 at 0x1c9a70
 *   fpu: mtc1 reinterprets v1 at 0x1c9a88
 *   fpu: float literal 0x3f000000 at 0x1c9a9c
 *   fpu: mtc1 reinterprets v0 at 0x1c9ad0
 *   fpu: mtc1 reinterprets v1 at 0x1c9ae4
 *   fpu: float literal 0x37800080 at 0x1c9b00
 *   fpu: mtc1 reinterprets v0 at 0x1c9b0c
 *   fpu: mtc1 reinterprets v1 at 0x1c9b24
 *   fpu: float literal 0x3f000000 at 0x1c9b3c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int SND_Play3D(signed int, signed short, signed short, void *, float);

struct dw_2094394_fields;
struct dw_2096304_fields;
struct dw_2103726_fields;
struct dw_2104139_fields;
#ifndef PROTO_DW_2106543_FIELDS
#define PROTO_DW_2106543_FIELDS
struct dw_2106543_fields { float loc[4]; float ang[4]; float scale[4]; float rgba[4]; };
#endif
#ifndef PROTO_DW_2095879_FIELDS
#define PROTO_DW_2095879_FIELDS
struct dw_2095879_fields { unsigned char f_independent : 1; unsigned char f_disable_draw : 1; unsigned char f_disable_draw_by_map : 1; unsigned char f_disable_act : 1; unsigned char f_disable_act_by_map : 1; unsigned char f_dummy : 3; };
#endif
#ifndef PROTO_DW_2094394_FIELDS
#define PROTO_DW_2094394_FIELDS
struct dw_2094394_fields { struct dw_2106543_fields pb; struct dw_2094394_fields *pRoot; struct dw_2096304_fields *p_sfx_data; struct dw_2103726_fields *p_fix_param; struct dw_2104139_fields *p_seq_param; struct dw_2094394_fields *p_parent; struct dw_2094394_fields *p_child; struct dw_2094394_fields *p_sibling; struct dw_2094394_fields *p_prev_sibling; float (*p_matrix)[4][4]; float (*p_parent_matrix)[4][4]; void *p_arg; char *p_data; unsigned int life_cnt; unsigned int cnt; int ptcl_handle; unsigned char atk_no; unsigned char dmg_char_id; struct dw_2095879_fields flags; unsigned char prog_no; };
#endif
#ifndef PROTO_DW_2103726_FIELDS
#define PROTO_DW_2103726_FIELDS
struct dw_2103726_fields { char cdummy; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_CNT_23AE2C16_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_CNT_23AE2C16_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_CNT_23AE2C16 = (int)&(((struct dw_2094394_fields *)0)->cnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9 = (int)&(((struct dw_2094394_fields *)0)->p_data) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214 = (int)&(((struct dw_2094394_fields *)0)->p_fix_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_PARENT_MATRIX_A767B80A_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_PARENT_MATRIX_A767B80A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_PARENT_MATRIX_A767B80A = (int)&(((struct dw_2094394_fields *)0)->p_parent_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2103726_FIELDS__10__CDUMMY_C6675C35_DEFINED
#define DCOMP_OFF_STRUCT_DW_2103726_FIELDS__10__CDUMMY_C6675C35_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2103726_FIELDS__10__CDUMMY_C6675C35 = (int)&(((struct dw_2103726_fields *)0)[10].cdummy) - 0 };
#endif















/* __SFXMNG_PLight_Act @ 0x1C9540 .. 0x1C970C (0x1cc bytes, frame 0x60) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x5c escapes at 0x1c95cc
 *   stack: address of the slot at 0x58 escapes at 0x1c95f4
 *   fpu: mtc1 reinterprets v0 at 0x1c9608
 *   fpu: mtc1 reinterprets v1 at 0x1c961c
 *   fpu: float literal 0x437f0000 at 0x1c9634
 *   fpu: mtc1 reinterprets v0 at 0x1c9650
 *   fpu: mtc1 reinterprets v1 at 0x1c9668
 *   fpu: float literal 0x437f0000 at 0x1c9680
 *   fpu: mtc1 reinterprets v0 at 0x1c969c
 *   fpu: mtc1 reinterprets v1 at 0x1c96b4
 *   fpu: float literal 0x437f0000 at 0x1c96cc
 *   stack: address of the slot at 0x40 escapes at 0x1c96e4
 *   cfg: kept branch: 0x1c9580 if (..) goto .L001C95A0
 *   cfg: kept goto: 0x1c9590 -> .L001C95A8
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int SfxPLight_Enable(unsigned short, signed int);
extern signed int SfxPLight_SetPos(unsigned short, float *);
extern signed int SfxPLight_SetRadius(unsigned short, float);
extern signed int SfxPLight_SetColor(unsigned short, float *);

struct dw_2094394_fields;
struct dw_2096304_fields;
struct dw_2103726_fields;
struct dw_2104139_fields;
#ifndef PROTO_DW_2106543_FIELDS
#define PROTO_DW_2106543_FIELDS
struct dw_2106543_fields { float loc[4]; float ang[4]; float scale[4]; float rgba[4]; };
#endif
#ifndef PROTO_DW_2095879_FIELDS
#define PROTO_DW_2095879_FIELDS
struct dw_2095879_fields { unsigned char f_independent : 1; unsigned char f_disable_draw : 1; unsigned char f_disable_draw_by_map : 1; unsigned char f_disable_act : 1; unsigned char f_disable_act_by_map : 1; unsigned char f_dummy : 3; };
#endif
#ifndef PROTO_DW_2094394_FIELDS
#define PROTO_DW_2094394_FIELDS
struct dw_2094394_fields { struct dw_2106543_fields pb; struct dw_2094394_fields *pRoot; struct dw_2096304_fields *p_sfx_data; struct dw_2103726_fields *p_fix_param; struct dw_2104139_fields *p_seq_param; struct dw_2094394_fields *p_parent; struct dw_2094394_fields *p_child; struct dw_2094394_fields *p_sibling; struct dw_2094394_fields *p_prev_sibling; float (*p_matrix)[4][4]; float (*p_parent_matrix)[4][4]; void *p_arg; char *p_data; unsigned int life_cnt; unsigned int cnt; int ptcl_handle; unsigned char atk_no; unsigned char dmg_char_id; struct dw_2095879_fields flags; unsigned char prog_no; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_CNT_23AE2C16_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_CNT_23AE2C16_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_CNT_23AE2C16 = (int)&(((struct dw_2094394_fields *)0)->cnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9 = (int)&(((struct dw_2094394_fields *)0)->p_data) - 0 };
#endif













extern void *SfxUtil_FindChar_Sphere(signed int, float *, float, signed int);






/* __SFXMNG_WolfCard_Act @ 0x1C89C0 .. 0x1C8C10 (0x250 bytes, frame 0xf0) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0xb0 escapes at 0x1c89e4
 *   stack: address of the slot at 0xa0 escapes at 0x1c89f4
 *   delay: lui at 0x1c8a04 writes a register its branch at 0x1c8a00 reads
 *   fpu: float literal 0x41a00000 at 0x1c8a0c
 *   fpu: float literal 0x3c888865 at 0x1c8a74
 *   stack: address of the slot at 0x90 escapes at 0x1c8a80
 *   stack: address of the slot at 0xd0 escapes at 0x1c8a80
 *   stack: address of the slot at 0x90 escapes at 0x1c8a90
 *   fpu: float literal 0x3c888865 at 0x1c8b14
 *   stack: address of the slot at 0x80 escapes at 0x1c8b18
 *   stack: address of the slot at 0xa0 escapes at 0x1c8b28
 *   stack: address of the slot at 0x80 escapes at 0x1c8b28
 *   stack: address of the slot at 0xa0 escapes at 0x1c8b28
 *   stack: address of the slot at 0x40 escapes at 0x1c8b44
 *   fpu: float literal 0x3f000000 at 0x1c8b68
 *   stack: address of the slot at 0x70 escapes at 0x1c8b7c
 *   stack: address of the slot at 0x40 escapes at 0x1c8b7c
 *   stack: address of the slot at 0x60 escapes at 0x1c8b90
 *   stack: address of the slot at 0x70 escapes at 0x1c8b90
 *   stack: address of the slot at 0x60 escapes at 0x1c8b9c
 *   stack: address of the slot at 0x60 escapes at 0x1c8b9c
 *   stack: address of the slot at 0x50 escapes at 0x1c8ba8
 *   stack: address of the slot at 0x60 escapes at 0x1c8ba8
 *   fpu: float literal 0x3f800000 at 0x1c8bb8
 *   stack: address of the slot at 0x50 escapes at 0x1c8bc0
 *   stack: address of the slot at 0xa0 escapes at 0x1c8bdc
 *   cfg: kept goto: 0x1c8aac -> .L001C8BF8
 *   v0#5 is the pointer held in s0#1+0x24
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

struct dw_2094394_fields;
struct dw_2096304_fields;
struct dw_2103726_fields;
struct dw_2104139_fields;
#ifndef PROTO_DW_2106543_FIELDS
#define PROTO_DW_2106543_FIELDS
struct dw_2106543_fields { float loc[4]; float ang[4]; float scale[4]; float rgba[4]; };
#endif
#ifndef PROTO_DW_2095879_FIELDS
#define PROTO_DW_2095879_FIELDS
struct dw_2095879_fields { unsigned char f_independent : 1; unsigned char f_disable_draw : 1; unsigned char f_disable_draw_by_map : 1; unsigned char f_disable_act : 1; unsigned char f_disable_act_by_map : 1; unsigned char f_dummy : 3; };
#endif
#ifndef PROTO_DW_2094394_FIELDS
#define PROTO_DW_2094394_FIELDS
struct dw_2094394_fields { struct dw_2106543_fields pb; struct dw_2094394_fields *pRoot; struct dw_2096304_fields *p_sfx_data; struct dw_2103726_fields *p_fix_param; struct dw_2104139_fields *p_seq_param; struct dw_2094394_fields *p_parent; struct dw_2094394_fields *p_child; struct dw_2094394_fields *p_sibling; struct dw_2094394_fields *p_prev_sibling; float (*p_matrix)[4][4]; float (*p_parent_matrix)[4][4]; void *p_arg; char *p_data; unsigned int life_cnt; unsigned int cnt; int ptcl_handle; unsigned char atk_no; unsigned char dmg_char_id; struct dw_2095879_fields flags; unsigned char prog_no; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9 = (int)&(((struct dw_2094394_fields *)0)->p_data) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214 = (int)&(((struct dw_2094394_fields *)0)->p_fix_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF = (int)&(((struct dw_2094394_fields *)0)->p_matrix) - 0 };
#endif



/* __SFXMNG_Ground_Init @ 0x1C85A0 .. 0x1C880C (0x26c bytes, frame 0x200) */
/*
 * dcomp notes:
 *   literal: @2740 is the string 'SfxMng.c'
 *   literal: @2741 is the string 'Failed to alloc matrix.'
 *   stack: address of the slot at 0x100 escapes at 0x1c85d4
 *   stack: address of the slot at 0x100 escapes at 0x1c85ec
 *   delay: daddu at 0x1c8600 writes a register its branch at 0x1c85fc reads
 *   stack: address of the slot at 0xf0 escapes at 0x1c8674
 *   stack: address of the slot at 0xf0 escapes at 0x1c868c
 *   fpu: float literal 0x3f800000 at 0x1c86a4
 *   fpu: float literal 0x41200000 at 0x1c86ac
 *   stack: address of the slot at 0xe0 escapes at 0x1c86bc
 *   fpu: float literal 0xbf800000 at 0x1c8724
 *   stack: address of the slot at 0x90 escapes at 0x1c8728
 *   stack: address of the slot at 0xd0 escapes at 0x1c8728
 *   stack: address of the slot at 0xa0 escapes at 0x1c8734
 *   stack: address of the slot at 0x70 escapes at 0x1c8734
 *   stack: address of the slot at 0x30 escapes at 0x1c8748
 *   stack: address of the slot at 0xb0 escapes at 0x1c87d0
 *   stack: address of the slot at 0x80 escapes at 0x1c87e4
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int SfxUtil_HitCheck_Line_Map(float *, float *, void *, void *, unsigned int *);
extern void sceVu0InversMatrix(void *, void *);
extern u32 VY[];
extern u32 VX[];
#ifndef DCOMP_COP2_5499821473
#define DCOMP_COP2_5499821473
#endif

#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif


/* __SFXMNG_Ground_Act @ 0x1C8450 .. 0x1C8594 (0x144 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x40 escapes at 0x1c8480
 *   stack: address of the slot at 0x48 escapes at 0x1c84a0
 *   stack: address of the slot at 0x50 escapes at 0x1c84c0
 *   stack: address of the slot at 0x48 escapes at 0x1c8578
 *   stack: address of the slot at 0x50 escapes at 0x1c8578
 *   declaration vs inferred signature: return signed int vs inferred u32
 */
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7

#endif







/* __SFXMNG_Plume_Init @ 0x1C7980 .. 0x1C7D84 (0x404 bytes, frame 0x170) */
/*
 * dcomp notes:
 *   literal: @2740 is the string 'SfxMng.c'
 *   literal: @2888 is the string '3DÓÃÞÙ\x8a\x84\x82è\x93\x96\x82Ä\x8e¸\x94s'
 *   fpu: mtc1 reinterprets v0 at 0x1c7a28
 *   fpu: mtc1 reinterprets v1 at 0x1c7a3c
 *   fpu: float literal 0x37800080 at 0x1c7a54
 *   fpu: mtc1 reinterprets v0 at 0x1c7a6c
 *   fpu: mtc1 reinterprets v1 at 0x1c7a80
 *   fpu: float literal 0x37800080 at 0x1c7a9c
 *   fpu: float literal 0x3f000000 at 0x1c7ab0
 *   fpu: float literal 0x40c90fdb at 0x1c7ab4
 *   fpu: float literal 0x00000000 at 0x1c7ac4
 *   stack: address of the slot at 0x50 escapes at 0x1c7afc
 *   fpu: mtc1 reinterprets v0 at 0x1c7b2c
 *   fpu: mtc1 reinterprets v1 at 0x1c7b40
 *   fpu: float literal 0x37800080 at 0x1c7b60
 *   fpu: float literal 0x3f000000 at 0x1c7b70
 *   stack: address of the slot at 0x50 escapes at 0x1c7b84
 *   stack: address of the slot at 0x160 escapes at 0x1c7ba4
 *   stack: address of the slot at 0x160 escapes at 0x1c7bb4
 *   fpu: mtc1 reinterprets v0 at 0x1c7bd4
 *   fpu: mtc1 reinterprets v1 at 0x1c7be8
 *   fpu: float literal 0x37800080 at 0x1c7c04
 *   fpu: float literal 0x3f000000 at 0x1c7c10
 *   fpu: mtc1 reinterprets v0 at 0x1c7c38
 *   fpu: mtc1 reinterprets v1 at 0x1c7c4c
 *   fpu: float literal 0x37800080 at 0x1c7c68
 *   fpu: float literal 0x3f000000 at 0x1c7c74
 *   fpu: mtc1 reinterprets v0 at 0x1c7c9c
 *   fpu: mtc1 reinterprets v1 at 0x1c7cb0
 *   fpu: float literal 0x37800080 at 0x1c7ccc
 *   fpu: float literal 0x3f000000 at 0x1c7cd8
 *   stack: address of the slot at 0x60 escapes at 0x1c7d24
 *   stack: address of the slot at 0x60 escapes at 0x1c7d3c
 *   v0 is the pointer held in @3760+0x6c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void SfxUtil_CalcRndPos(float *, signed int, float *);
extern signed int SFX_ConfirmReflect();
extern unsigned short SfxMdl_Alloc(unsigned short, signed int);





#ifndef PROTO_DW_2106543_FIELDS
#define PROTO_DW_2106543_FIELDS

#endif
#ifndef PROTO_DW_2095879_FIELDS
#define PROTO_DW_2095879_FIELDS

#endif
#ifndef PROTO_DW_2094394_FIELDS
#define PROTO_DW_2094394_FIELDS

#endif
#ifndef PROTO_DW_2094099_FIELDS
#define PROTO_DW_2094099_FIELDS
struct dw_2094099_fields { unsigned int Frame; char szName[26]; unsigned short sfx_idx; };
#endif
#ifndef PROTO_DW_2096304_FIELDS
#define PROTO_DW_2096304_FIELDS
struct dw_2096304_fields { int ProgramId; struct dw_2096304_fields *pParent; struct dw_2096304_fields *pChild; struct dw_2096304_fields *pSibling; int FixParamNum; struct dw_2103726_fields *pFixParam; int SeqParamNum; struct dw_2104139_fields *pSeqParam; struct dw_2094099_fields CommonParam; };
#endif
#ifndef PROTO_DW_2103726_FIELDS
#define PROTO_DW_2103726_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_LIFE_CNT_84B35CAE_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_LIFE_CNT_84B35CAE_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_PARENT_MATRIX_A767B80A_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_PARENT_MATRIX_A767B80A_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_SFX_DATA_637F3CD2_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_SFX_DATA_637F3CD2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_SFX_DATA_637F3CD2 = (int)&(((struct dw_2094394_fields *)0)->p_sfx_data) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_LOC_3__0ABBF1EA_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_LOC_3__0ABBF1EA_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_LOC_3__0ABBF1EA = (int)&(((struct dw_2094394_fields *)0)->pb.loc[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2096304_FIELDS_COMMONPARAM_SFX_IDX_B45DC23E_DEFINED
#define DCOMP_OFF_STRUCT_DW_2096304_FIELDS_COMMONPARAM_SFX_IDX_B45DC23E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2096304_FIELDS_COMMONPARAM_SFX_IDX_B45DC23E = (int)&(((struct dw_2096304_fields *)0)->CommonParam.sfx_idx) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2103726_FIELDS__23__CDUMMY_1B53159F_DEFINED
#define DCOMP_OFF_STRUCT_DW_2103726_FIELDS__23__CDUMMY_1B53159F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2103726_FIELDS__23__CDUMMY_1B53159F = (int)&(((struct dw_2103726_fields *)0)[23].cdummy) - 0 };
#endif




/* __SFXMNG_DmyPolyHoming_Init @ 0x1C74E0 .. 0x1C7838 (0x358 bytes, frame 0x140) */
/*
 * dcomp notes:
 *   literal: @2740 is the string 'SfxMng.c'
 *   literal: @2741 is the string 'Failed to alloc matrix.'
 *   stack: address of the slot at 0x40 escapes at 0x1c753c
 *   stack: address of the slot at 0x40 escapes at 0x1c7554
 *   delay: daddu at 0x1c7568 writes a register its branch at 0x1c7564 reads
 *   fpu: mtc1 reinterprets v0 at 0x1c7590
 *   fpu: mtc1 reinterprets v1 at 0x1c75a4
 *   fpu: float literal 0x37800080 at 0x1c75c0
 *   fpu: float literal 0x3f000000 at 0x1c75c4
 *   fpu: float literal 0x3c8ef34d at 0x1c75e8
 *   fpu: mtc1 reinterprets v0 at 0x1c760c
 *   fpu: mtc1 reinterprets v1 at 0x1c7620
 *   fpu: float literal 0x37800080 at 0x1c763c
 *   fpu: float literal 0x3f000000 at 0x1c7640
 *   fpu: float literal 0x3c8ef34d at 0x1c766c
 *   fpu: float literal 0xc0490fd0 at 0x1c7684
 *   fpu: float literal 0x40490fd0 at 0x1c769c
 *   fpu: float literal 0x40c90fd0 at 0x1c76c8
 *   fpu: float literal 0xc0490fd0 at 0x1c76e4
 *   fpu: float literal 0x40490fd0 at 0x1c76fc
 *   fpu: float literal 0x40c90fd0 at 0x1c7728
 *   fpu: float literal 0xc0490fd0 at 0x1c7744
 *   fpu: float literal 0x40490fd0 at 0x1c775c
 *   fpu: float literal 0x40c90fd0 at 0x1c7788
 *   fpu: mtc1 reinterprets v0 at 0x1c77c0
 *   fpu: mtc1 reinterprets v1 at 0x1c77d4
 *   fpu: float literal 0x37800080 at 0x1c77f0
 *   fpu: float literal 0x3f000000 at 0x1c77f4
 *   cfg: kept goto: 0x1c7518 -> .L001C7820
 *   cfg: kept branch: 0x1c7694 if (..) goto .L001C76B8
 *   cfg: kept branch: 0x1c76f4 if (..) goto .L001C7718
 *   cfg: kept branch: 0x1c7754 if (..) goto .L001C7778
 *   v0 is the pointer held in @2576+0x6c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void SfxCalc_QtnMakeFromPYR(float *, float, float, float);





#ifndef PROTO_DW_2106543_FIELDS
#define PROTO_DW_2106543_FIELDS

#endif
#ifndef PROTO_DW_2095879_FIELDS
#define PROTO_DW_2095879_FIELDS

#endif
#ifndef PROTO_DW_2094394_FIELDS
#define PROTO_DW_2094394_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214_DEFINED

#endif



typedef struct BM_Attach { u16 sfx_idx; s16 skip; u8 pad[12]; u64 fParts[2]; } BM_Attach;
typedef struct BM_Data { u16 char_id; u8 pad[14]; BM_Attach aAttach[2]; } BM_Data;
typedef struct BM_Fire { u16 num_data; u16 default_sfx; s16 default_skip; u8 pad[10]; BM_Data aData[64]; } BM_Fire;
typedef struct BM_AX { u8 pre[0x20]; u16 sfx_idx; s16 skip; u8 pad[12]; u64 fParts[2]; } BM_AX;
extern signed int SFX_Create_OnAng_Attach(unsigned short, float *, float *, void *, unsigned short,
    unsigned char, unsigned char);

#define FA(i) (((u16 *)s_fire_attach)[i])
struct fa_Ent { u16 f[40]; };


extern signed int __SFXMNG_CallEmitter_Act(void *);
extern signed int __SFXMNG_CallSfx_Act(void *);
extern signed int __SFXMNG_Default2_Act(void *);
extern signed int __SFXMNG_Default2_Init(void *);
extern signed int __SFXMNG_Default_Act(void *);
extern signed int __SFXMNG_Default_Init(void *);
extern signed int __SFXMNG_DmyPolyHoming_Init(void *);
extern signed int __SFXMNG_Ground_Act(void *);
extern signed int __SFXMNG_Ground_Init(void *);
extern signed int __SFXMNG_HitObject_End(void *);
extern signed int __SFXMNG_Karyu_Act(void *);
extern signed int __SFXMNG_Karyu_End(void *);
extern signed int __SFXMNG_Karyu_Init(void *);
extern signed int __SFXMNG_PLight_Act(void *);
extern signed int __SFXMNG_Plume_Init(void *);
extern signed int __SFXMNG_SE_Act(void *);
extern signed int __SFXMNG_Spirit_Act(void *);
extern signed int __SFXMNG_Spirit_End(void *);
extern signed int __SFXMNG_WolfCard_Act(void *);
extern signed int __SFXMNG_WolfCard_End(void *);
extern signed int __SFXMNG_WolfCard_Init(void *);
static u32 s_FuncTable[0x36] = {
    0, 0, 0, (u32)&__SFXMNG_Default_Init, (u32)&__SFXMNG_Default_Act,
    (u32)&__SFXMNG_Default_End, (u32)&__SFXMNG_CallEmitter_Init, (u32)&__SFXMNG_CallEmitter_Act,
    (u32)&__SFXMNG_CallEmitter_End, (u32)&__SFXMNG_CallSfx_Init, (u32)&__SFXMNG_CallSfx_Act, 0,
    (u32)&__SFXMNG_HitObject_Init, (u32)&__SFXMNG_HitObject_Act, (u32)&__SFXMNG_HitObject_End,
    (u32)&__SFXMNG_Spirit_Init, (u32)&__SFXMNG_Spirit_Act, (u32)&__SFXMNG_Spirit_End,
    (u32)&__SFXMNG_Default2_Init, (u32)&__SFXMNG_Default2_Act, (u32)&__SFXMNG_Default2_End,
    (u32)&__SFXMNG_SE_Init, (u32)&__SFXMNG_SE_Act, (u32)&__SFXMNG_SE_End,
    (u32)&__SFXMNG_PLight_Init, (u32)&__SFXMNG_PLight_Act, (u32)&__SFXMNG_PLight_End,
    (u32)&__SFXMNG_Karyu_Init, (u32)&__SFXMNG_Karyu_Act, (u32)&__SFXMNG_Karyu_End,
    (u32)&__SFXMNG_WolfCard_Init, (u32)&__SFXMNG_WolfCard_Act, (u32)&__SFXMNG_WolfCard_End,
    (u32)&__SFXMNG_CameraVib_Init, (u32)&__SFXMNG_CameraVib_Act, 0, (u32)&__SFXMNG_Ground_Init,
    (u32)&__SFXMNG_Ground_Act, (u32)&__SFXMNG_Ground_End, (u32)&__SFXMNG_EventCall_Init,
    (u32)&__SFXMNG_EventCall_Act, 0, (u32)&__SFXMNG_WhirlPool_Init,
    (u32)&__SFXMNG_WhirlPool_Act, (u32)&__SFXMNG_WhirlPool_End, (u32)&__SFXMNG_Plume_Init,
    (u32)&__SFXMNG_Plume_Act, (u32)&__SFXMNG_Plume_End, (u32)&__SFXMNG_DmyPolyHoming_Init,
    (u32)&__SFXMNG_DmyPolyHoming_Act, (u32)&__SFXMNG_DmyPolyHoming_End,
    (u32)&__SFXMNG_Bugs_Init
};/* __SFXMNG_Karyu_Init @ 0x1C91D0 .. 0x1C940C (0x23c bytes, frame 0x70) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @2066 -> 0x248820
 *   literal: @2071 -> 0x248830
 *   fpu: float literal 0x41a00000 at 0x1c9278
 *   fpu: mtc1 reinterprets v0 at 0x1c92a4
 *   fpu: mtc1 reinterprets v1 at 0x1c92b8
 *   fpu: float literal 0x37800080 at 0x1c92d0
 *   fpu: float literal 0x3e32b020 at 0x1c92e0
 *   fpu: float literal 0x3f000000 at 0x1c92ec
 *   fpu: mtc1 reinterprets v0 at 0x1c9310
 *   fpu: mtc1 reinterprets v1 at 0x1c9324
 *   fpu: float literal 0x37800080 at 0x1c9340
 *   fpu: float literal 0x3f000000 at 0x1c9358
 *   fpu: float literal 0x3e32b020 at 0x1c935c
 *   fpu: mov.s at 0x1c9378 is a float copy
 *   delay: lui at 0x1c9390 writes a register its branch at 0x1c938c reads
 *   stack: address of the slot at 0x60 escapes at 0x1c93a4
 *   stack: address of the slot at 0x50 escapes at 0x1c93d0
 *   literal: @2071 initializes the 16-byte local at 0x50
 *   literal: @2066 initializes the 16-byte local at 0x60
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void *SfxUtil_FindChar_Sphere(signed int, float *, float, signed int);
extern void SfxCalc_QtnMakeFromMatrix(float *, void *);

struct dw_2094394_fields;
struct dw_2096304_fields;
struct dw_2103726_fields;
struct dw_2104139_fields;
#ifndef PROTO_DW_2106543_FIELDS
#define PROTO_DW_2106543_FIELDS
struct dw_2106543_fields { float loc[4]; float ang[4]; float scale[4]; float rgba[4]; };
#endif
#ifndef PROTO_DW_2095879_FIELDS
#define PROTO_DW_2095879_FIELDS
struct dw_2095879_fields { unsigned char f_independent : 1; unsigned char f_disable_draw : 1; unsigned char f_disable_draw_by_map : 1; unsigned char f_disable_act : 1; unsigned char f_disable_act_by_map : 1; unsigned char f_dummy : 3; };
#endif
#ifndef PROTO_DW_2094394_FIELDS
#define PROTO_DW_2094394_FIELDS
struct dw_2094394_fields { struct dw_2106543_fields pb; struct dw_2094394_fields *pRoot; struct dw_2096304_fields *p_sfx_data; struct dw_2103726_fields *p_fix_param; struct dw_2104139_fields *p_seq_param; struct dw_2094394_fields *p_parent; struct dw_2094394_fields *p_child; struct dw_2094394_fields *p_sibling; struct dw_2094394_fields *p_prev_sibling; float (*p_matrix)[4][4]; float (*p_parent_matrix)[4][4]; void *p_arg; char *p_data; unsigned int life_cnt; unsigned int cnt; int ptcl_handle; unsigned char atk_no; unsigned char dmg_char_id; struct dw_2095879_fields flags; unsigned char prog_no; };
#endif
#ifndef PROTO_DW_2103726_FIELDS
#define PROTO_DW_2103726_FIELDS
struct dw_2103726_fields { char cdummy; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_LIFE_CNT_84B35CAE_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_LIFE_CNT_84B35CAE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_LIFE_CNT_84B35CAE = (int)&(((struct dw_2094394_fields *)0)->life_cnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9 = (int)&(((struct dw_2094394_fields *)0)->p_data) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214 = (int)&(((struct dw_2094394_fields *)0)->p_fix_param) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF = (int)&(((struct dw_2094394_fields *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_PARENT_MATRIX_A767B80A_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_PARENT_MATRIX_A767B80A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_PARENT_MATRIX_A767B80A = (int)&(((struct dw_2094394_fields *)0)->p_parent_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_0__A42E032D_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_0__A42E032D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_0__A42E032D = (int)&(((struct dw_2094394_fields *)0)->pb.ang[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_1__0FE27C30_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_1__0FE27C30_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_1__0FE27C30 = (int)&(((struct dw_2094394_fields *)0)->pb.ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_2__750A2196_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_2__750A2196_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_2__750A2196 = (int)&(((struct dw_2094394_fields *)0)->pb.ang[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2103726_FIELDS__1__CDUMMY_804D1605_DEFINED
#define DCOMP_OFF_STRUCT_DW_2103726_FIELDS__1__CDUMMY_804D1605_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2103726_FIELDS__1__CDUMMY_804D1605 = (int)&(((struct dw_2103726_fields *)0)[1].cdummy) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2103726_FIELDS_CDUMMY_C7F5C357_DEFINED
#define DCOMP_OFF_STRUCT_DW_2103726_FIELDS_CDUMMY_C7F5C357_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2103726_FIELDS_CDUMMY_C7F5C357 = (int)&(((struct dw_2103726_fields *)0)->cdummy) - 0 };
#endif

/* __SFXMNG_WolfCard_Init @ 0x1C8C10 .. 0x1C8DF0 (0x1e0 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @2124 -> 0x248840
 *   fpu: float literal 0x41a00000 at 0x1c8c9c
 *   fpu: mtc1 reinterprets v0 at 0x1c8cc0
 *   fpu: mtc1 reinterprets v1 at 0x1c8cd4
 *   fpu: float literal 0x37800080 at 0x1c8cec
 *   fpu: float literal 0x3e32b020 at 0x1c8cfc
 *   fpu: float literal 0x3f000000 at 0x1c8d08
 *   fpu: mtc1 reinterprets v0 at 0x1c8d2c
 *   fpu: mtc1 reinterprets v1 at 0x1c8d40
 *   fpu: float literal 0x37800080 at 0x1c8d5c
 *   fpu: float literal 0x3f000000 at 0x1c8d74
 *   fpu: float literal 0x3e32b020 at 0x1c8d78
 *   fpu: mov.s at 0x1c8d94 is a float copy
 *   stack: address of the slot at 0x40 escapes at 0x1c8db8
 *   literal: @2124 initializes the 16-byte local at 0x40
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void SfxCalc_QtnMakeFromMatrix(float *, void *);

struct dw_2094394_fields;
struct dw_2096304_fields;
struct dw_2103726_fields;
struct dw_2104139_fields;
#ifndef PROTO_DW_2106543_FIELDS
#define PROTO_DW_2106543_FIELDS
struct dw_2106543_fields { float loc[4]; float ang[4]; float scale[4]; float rgba[4]; };
#endif
#ifndef PROTO_DW_2095879_FIELDS
#define PROTO_DW_2095879_FIELDS
struct dw_2095879_fields { unsigned char f_independent : 1; unsigned char f_disable_draw : 1; unsigned char f_disable_draw_by_map : 1; unsigned char f_disable_act : 1; unsigned char f_disable_act_by_map : 1; unsigned char f_dummy : 3; };
#endif
#ifndef PROTO_DW_2094394_FIELDS
#define PROTO_DW_2094394_FIELDS
struct dw_2094394_fields { struct dw_2106543_fields pb; struct dw_2094394_fields *pRoot; struct dw_2096304_fields *p_sfx_data; struct dw_2103726_fields *p_fix_param; struct dw_2104139_fields *p_seq_param; struct dw_2094394_fields *p_parent; struct dw_2094394_fields *p_child; struct dw_2094394_fields *p_sibling; struct dw_2094394_fields *p_prev_sibling; float (*p_matrix)[4][4]; float (*p_parent_matrix)[4][4]; void *p_arg; char *p_data; unsigned int life_cnt; unsigned int cnt; int ptcl_handle; unsigned char atk_no; unsigned char dmg_char_id; struct dw_2095879_fields flags; unsigned char prog_no; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_LIFE_CNT_84B35CAE_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_LIFE_CNT_84B35CAE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_LIFE_CNT_84B35CAE = (int)&(((struct dw_2094394_fields *)0)->life_cnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9 = (int)&(((struct dw_2094394_fields *)0)->p_data) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_MATRIX_A872CFAF = (int)&(((struct dw_2094394_fields *)0)->p_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_PARENT_MATRIX_A767B80A_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_PARENT_MATRIX_A767B80A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_PARENT_MATRIX_A767B80A = (int)&(((struct dw_2094394_fields *)0)->p_parent_matrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_0__A42E032D_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_0__A42E032D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_0__A42E032D = (int)&(((struct dw_2094394_fields *)0)->pb.ang[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_1__0FE27C30_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_1__0FE27C30_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_1__0FE27C30 = (int)&(((struct dw_2094394_fields *)0)->pb.ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_2__750A2196_DEFINED
#define DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_2__750A2196_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2094394_FIELDS_PB_ANG_2__750A2196 = (int)&(((struct dw_2094394_fields *)0)->pb.ang[2]) - 0 };
#endif
/* _SubFunc_Plume_Move @ 0x1C7D90 .. 0x1C80F8 (0x368 bytes, frame 0x130) */
extern float fabsf(float);
struct PlumeDat { float press_coeff; float valance; float pitch_coeff; float pad; float n_speed[4]; };
static u32 s_SfxMng[0x40c];
static u32 s_pSfxMng __attribute__((aligned(64)));

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SfxMng_InitSystem(void *a0 , signed int a1 , signed int a2 , signed int a3 );
signed int SfxMng_SfxCreate(signed short a0 , float *a1 , float *a2 , float *a3 , void *t0 , void *t1 , unsigned char t2 , unsigned char arg7);
void SfxMng_Action(float delta);
signed int SfxMng_EnableDraw(signed int hSfx_, signed int bEnable_, signed int bApplySibling_, unsigned short ctrl_);
signed int SfxMng_EnableAction(signed int hSfx_, signed int bEnable_, signed int bApplySibling_, unsigned short ctrl_);
void SfxMng_DeleteBySfxIdx(unsigned short effect);
signed int SfxMng_BurnModel(void *pMdl_);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */



void SfxMng_InitSystem(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */, signed
        int a3 /* r7 */) {
    signed int a1_2; // a1
    u32 a0_index; // a0
    u32 a0_index_; // a0
    void *a0_2; // a0
    u8 *v1;
    u32 v0;
    signed int a2_2;
    signed int a3_2;

    v0 = (u32)s_SfxMng;
    s_pSfxMng = (u32)s_SfxMng;
    if (a2 != 0) {
        a0_2 = (void *)s_pSfxMng;
        memset(a0_2, 0, 0x1030);
    }
    v0 = s_pSfxMng;
    *(u32 *)((v0 + 0xc)) = 0;
    v0 = s_pSfxMng;
    *(u32 *)((v0 + 4)) = 0;
    v0 = s_pSfxMng;
    *(u32 *)v0 = a1;
    if (a2 != 0) {
        a0_index = (u32)a1 << (u32)3;
        a2_2 = (signed int)((char *)__FUNCTION__);
        a3_2 = (signed int)"";
        v0 = (u32)MemAllocAlignReal((unsigned int)(void *)a0_index, 0x10, ((char *)__FUNCTION__),
            "");
        v1 = (u8 *)s_pSfxMng;
        *(u32 *)(v1 + 0x1c) = v0;
    }
    v0 = s_pSfxMng;
    memset((void *)*(s32 *)((v0 + 0x1c)), 0, (u32)a1 << 3);
    if (a2 != 0) {
        a0_index_ = (u32)a1 << (u32)7;
        a2_2 = (signed int)((char *)__FUNCTION__);
        a3_2 = (signed int)"";
        v0 = (u32)MemAllocAlignReal((unsigned int)(void *)a0_index_, 0x10, ((char *)__FUNCTION__),
            "");
        v1 = (u8 *)s_pSfxMng;
        *(u32 *)(v1 + 0x10) = v0;
    }
    v0 = s_pSfxMng;
    a0_2 = (void *)*(s32 *)((v0 + 0x10));
    memset(a0_2, 0, (u32)a1 << 7);
    v1 = (u8 *)s_pSfxMng;
    a0_2 = (void *)(s32)1;
    v0 = *(s32 *)(v1 + 0x10);
    *(u32 *)(v1 + 0x14) = v0;
    v0 = s_pSfxMng;
    a1_2 = *(s32 *)((v0 + 0x14));
    v0 = *(s32 *)v0;
    v1 = (u8 *)(s32)((u32)(a1_2) + 0x80);
    if ((s32)v0 > (s32)1) {
        do {
            *(u32 *)(((s32)(a1_2) + 0x58)) = (s32)v1;
            v0 = s_pSfxMng;
            a1_2 = (s32)v1;
            a0_2 = (void *)((u8 *)a0_2 + 1);
            v0 = *(s32 *)v0;
            v0 = (s32)a0_2 < (s32)v0;
            v1 = (u8 *)(v1 + 0x80);
        } while (v0 != 0);
    }
    *(u32 *)(((s32)(a1_2) + 0x58)) = 0;
    v0 = s_pSfxMng;
    v1 = (u8 *)(s32)0x400;
    *(u32 *)((v0 + 0x18)) = a1_2;
    v0 = s_pSfxMng;
    *(u32 *)((v0 + 0x24)) = (s32)v1;
    if (a2 != 0) {
        a2_2 = (signed int)((char *)__FUNCTION__);
        a3_2 = (signed int)"";
        v0 = (u32)MemAllocAlignReal(0x8000, 0x10, ((char *)__FUNCTION__), "");
        v1 = (u8 *)s_pSfxMng;
        *(u32 *)(v1 + 0x28) = v0;
    }
    v0 = s_pSfxMng;
    memset((void *)*(s32 *)((v0 + 0x28)), 0, 0x8000);
    if (a2 != 0) {
        a2_2 = (signed int)((char *)__FUNCTION__);
        a3_2 = (signed int)"";
        v0 = (u32)MemAllocAlignReal(0x80, 0x10, ((char *)__FUNCTION__), "");
        v1 = (u8 *)s_pSfxMng;
        *(u32 *)(v1 + 0x2c) = v0;
    }
    v0 = s_pSfxMng;
    memset((void *)*(s32 *)((v0 + 0x2c)), 0, 0x80);
    v0 = s_pSfxMng;
    a2_2 = a3;
    *(u32 *)((v0 + 0x20)) = (u32)a0;
    v0 = s_pSfxMng;
    a0_2 = (void *)*(s32 *)((v0 + 0x20));
    a1_2 = v0 + 0x30;
    v0 = SFX_DataRemap((char *)a0_2, (void *)a1_2, a2_2);
    v1 = (u8 *)s_pSfxMng;
    *(u32 *)(v1 + 8) = v0;
    _InitFireAttachData();
    return;
}

signed int SfxMng_SfxCreate(signed short a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */, float
        *a3 /* r7 */, void *t0 /* r8 */, void *t1 /* r9 */, unsigned char t2 /* r10 */, unsigned
        char arg7) {
    u32 a0_word = a0;
    u32 v1;
    u32 v0;
    s32 result;
    s32 index;
    float *a1_2;
    u8 stackFrame_20[256] __attribute__((aligned(16)));

    a0_word = (s16)a0_word;
    v1 = s_pSfxMng;
    v0 = *(s32 *)((v1 + 8));
    if ((s32)v0 < (s32)a0_word) {
        return -1;
    } else {
        v0 = a0_word << 2;
        v0 = v0 + v1;
        a0_word = *(s32 *)((v0 + 0x30));
        if (a0_word == 0) {
            return -1;
        } else {
            v0 = (u32)__SFXMNG_SfxCreateFromData((void *)a0_word, a1, a2, a3, t0, t1, (void *)0,
                t2, arg7);
            if (v0 == 0) {
                if (v0 == 0) {
                    a1_2 = (float *)"SfxMng.c";
                    strcpy((char *)((u8 *)&stackFrame_20[0]), (const char *)"SfxMng.c");
                    a1_2 = (float *)"SFX Create Failed";
                    SfxDbg_SetDebugMsg(0, "SFX Create Failed", (char *)((u8 *)&stackFrame_20[0]),
                        0x1b3);
                }
                return -1;
            } else {
                index = v0 ? ((s32)(v0 - *(s32 *)(s_pSfxMng + 0x10)) / 128) : 0;
                result = (index & 0xfff) | ((*(s32 *)(*(s32 *)(s_pSfxMng + 0x1c) + index * 8 + 4) & 0xfffff) << 12);
            }
        }
    }
    return result;
}
/* SfxMng_SetPos @ 0x1CDDE0 .. 0x1CDEB0 (0xd0 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1cde3c writes a register its branch at 0x1cde38 reads
 *   delay: daddu at 0x1cde50 writes a register its branch at 0x1cde4c reads
 *   delay: daddu at 0x1cde70 writes a register its branch at 0x1cde6c reads
 *   cfg: kept branch: 0x1cdde4 if (..) goto .L001CDE00
 *   cfg: kept goto: 0x1cddf8 -> .L001CDEA0
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int SfxMng_SetPos(signed int a0 /* r4 */, float *a1 /* r5 */) {
    u32 a2;
    u32 v1;
    u8 *s0;
    u32 v0;

    v0 = -1;
    if ((u32)(s32)a0 != v0) {
        goto _L001CDE00;
    }
    v0 = 0;
    goto _L001CDEA0;
    _L001CDE00:;
    a2 = (u32)(a0) & 0xfff;
    a0 = s_pSfxMng;
    s0 = (u8 *)(s32)(u32)&((struct { u8 b[0x80]; } *)*(s32 *)(((s32)(a0) + 0x10)))[a2];
    if ((u32)(s32)s0 == 0) {
        v0 = 0;
        return v0;
    }
    v0 = (u32)&((struct { u8 b[8]; } *)*(s32 *)(((s32)(a0) + 0x1c)))[a2];
    v0 = *(u8 *)v0;
    if (v0 == 0) {
        v0 = 0;
        return v0;
    }
    v0 = *(s32 *)(s0 + 0x50);
    if (v0 != 0) {
        v0 = 0;
        return v0;
    }
    v1 = *(s32 *)(s0 + 0x64);
    v0 = (u32)MRX1;
    if (v1 != v0) {
        v0 = 0;
        return v0;
    }
    a0 = (s32)s0;
    sceVu0CopyVector((void *)a0, (void *)a1);
    a0 = *(s32 *)(s0 + 0x60);
    a1 = (float *)s0;
    SfxCalc_MakeRotTransMatrix_I((void *)a0, a1, (float *)(s0 + 0x10), (float *)(u32 *)(s0 + 0x20));
    v0 = 1;
    _L001CDEA0:;
    return v0;
}
void SfxMng_Action(float delta) {
    s32 i = 0;
    u8 *manager = (u8 *)s_pSfxMng;
    struct ManualSfxEntry *entry = (struct ManualSfxEntry *)*(s32 *)(manager + 28);
    s32 count = *(s32 *)manager;
    s32 offset;
    if (0 < count) {
        offset = 0;
        do {
            if (entry->state != 0 && entry->state != 3)
                __SFXMNG_ProcOne((void *)(*(s32 *)(manager + 16) + offset), delta);
            offset += 128;
            manager = (u8 *)s_pSfxMng;
            count = *(s32 *)manager;
            i++;
            entry++;
        } while (i < count);
    }
    {
        struct ManualSfxEntry *clear = (struct ManualSfxEntry *)*(s32 *)(manager + 28);
        s32 index = 0;
        if (0 < count) {
            do {
                clear->high = 0;
                manager = (u8 *)s_pSfxMng;
                index++;
                clear++;
            } while (index < *(s32 *)manager);
        }
    }
    (*(s32 *)(manager + 12))++;
}
static void __SFXMNG_ProcOne(void *object,float delta) {
    u8 *saved,*data;
    float elapsed;
    s32 index;
    struct ManualSfxEntry *entry;
    saved=(u8 *)object;
    data=(u8 *)*(u32 *)(saved+0x44);
    elapsed=(float)delta;
    index=saved ? ((s32)saved-*(s32 *)(s_pSfxMng+0x10))/128 : 0;
    entry=(struct ManualSfxEntry *)(*(u32 *)(s_pSfxMng+0x1c)+index*8);
    if(entry->state!=0 && entry->high!=1) {
        if (((struct dw_2095879 *)(saved+0x7e))->f_disable_act || ((struct dw_2095879 *)(saved+0x7e))->f_disable_act_by_map) return;
        entry->high=1;
        if(entry->state==4) __SFXMNG_SfxDelete(saved,0);
        else {
            if(*(s32 *)(saved+0x78)!=-1) *(s32 *)(saved+0x78)=PtclMng_UpdateHandle(*(s32 *)(saved+0x78));
            if(*(u32 *)(saved+0x70)==0) __SFXMNG_SfxDelete(saved,0);
            else {
                u32 callback=s_FuncTable[*(s32 *)data*3+1];
                if(callback!=0 && !((struct dw_2095879 *)(saved+0x7e))->f_disable_act) {
                    if(((u32 (*)(void *))callback)(saved)==0) goto done;
                }
                data=(u8 *)*(u32 *)(data+8);
                while(data!=0) {
                    if(*(u32 *)(data+0x20)==*(u32 *)(saved+0x74))
                        __SFXMNG_SfxCreateFromData(data,0,0,0,(void *)*(u32 *)(saved+0x60),(void *)*(u32 *)(saved+0x68),saved,saved[0x7d],saved[0x7c]);
                    data=(u8 *)*(u32 *)(data+0xc);
                }
                data=(u8 *)*(u32 *)(saved+0x54);
                while(data!=0) {__SFXMNG_ProcOne(data,(float)elapsed);data=(u8 *)*(u32 *)(data+0x58);}
                if(*(u32 *)(saved+0x70)!=0x7fffffff) --*(u32 *)(saved+0x70);
                ++*(u32 *)(saved+0x74);
            }
        }
    }
done:;
}
static inline u8 *Sfx_Alloc(void) {
    u8 *sfx;
    s32 index;
    if (*(s32 *)(s_pSfxMng + 4) >= *(s32 *)s_pSfxMng) return 0;
    sfx = *(u8 **)(s_pSfxMng + 0x14);
    *(s32 *)(s_pSfxMng + 4) = *(s32 *)(s_pSfxMng + 4) + 1;
    *(u32 *)(s_pSfxMng + 0x14) = *(u32 *)(*(u32 *)(s_pSfxMng + 0x14) + 0x58);
    *(u32 *)(sfx + 0x58) = 0;
    if (*(u32 *)(s_pSfxMng + 0x14) == 0) *(u32 *)(s_pSfxMng + 0x18) = 0;
    {
        struct SfxCreateEnt *ent;
        index = sfx ? ((s32)sfx - *(s32 *)(s_pSfxMng + 0x10)) / 128 : 0;
        ent = (struct SfxCreateEnt *)(*(u32 *)(s_pSfxMng + 0x1c) + index * 8);
        ent->state = 1;
        ent->serial = *(u32 *)(s_pSfxMng + 0xc);
    }
    memset(sfx, 0, 128);
    return sfx;
}
static inline void Sfx_AddChild(struct SfxNode *par, struct SfxNode *c) {
    struct SfxNode *p;
    if (par && c) {
        p = par->child;
        if (p == 0) {
            *(u32 *)((u8 *)par + 0x54) = (u32)c;
        } else {
            while (p->next != 0) p = p->next;
            p->next = c;
            c->prev = p;
        }
    }
}
static void *__SFXMNG_SfxCreateFromData(void *data, float *pos, float *ang, float *scl, void *mat, void *arg, void *parent, unsigned char flagA, unsigned char flagB) {
    u8 *sfx;
    s32 index;
    if (data == 0) return 0;
    sfx = Sfx_Alloc();
    index = sfx ? ((s32)sfx - *(s32 *)(s_pSfxMng + 0x10)) / 128 : 0;
    if (sfx == 0) return 0;
    *(u32 *)(sfx + 0x44) = (u32)data;
    *(u32 *)(sfx + 0x48) = *(u32 *)((u8 *)data + 0x14);
    *(u32 *)(sfx + 0x4c) = *(u32 *)((u8 *)data + 0x1c);
    sfx[0x7f] = *(u32 *)data;
    *(u32 *)(sfx + 0x50) = (u32)parent;
    *(u32 *)(sfx + 0x68) = (u32)arg;
    *(u32 *)(sfx + 0x74) = 0;
    *(s32 *)(sfx + 0x78) = -1;
    sfx[0x7d] = flagA;
    sfx[0x7c] = flagB;
    *(u32 *)(sfx + 0x40) = parent ? *(u32 *)((u8 *)parent + 0x40) : (u32)sfx;
    if (pos) sceVu0CopyVector(sfx, pos); else sceVu0CopyVector(sfx, VW);
    if (ang) sceVu0CopyVector(sfx + 0x10, ang); else sceVu0CopyVector(sfx + 0x10, VW);
    if (scl) sceVu0CopyVector(sfx + 0x20, scl); else sceVu0CopyVector(sfx + 0x20, V1);
    if (parent) {
        Sfx_AddChild((struct SfxNode *)parent, (struct SfxNode *)sfx);
        ((struct SfxCreateEnt *)(*(u32 *)(s_pSfxMng + 0x1c) + index * 8))->state = 3;
        *(u32 *)(sfx + 0x64) = *(u32 *)((u8 *)parent + 0x60);
    } else {
        ((struct SfxCreateEnt *)(*(u32 *)(s_pSfxMng + 0x1c) + index * 8))->state = 2;
        if (mat) *(u32 *)(sfx + 0x64) = (u32)mat; else *(u32 *)(sfx + 0x64) = (u32)MRX1;
    }
    if (*(s32 *)data < 0x12) {
        u32 cb = s_FuncTable[*(s32 *)data * 3];
        if (cb != 0) {
            if (((u32 (*)(void *))cb)(sfx) == 0) {
                __SFXMNG_SfxDelete(sfx, 1);
                return 0;
            }
        }
    }
    __SFXMNG_ProcOne(sfx, 0.0f);
    return sfx;
}
static signed int __SFXMNG_SfxDelete(void *object, signed int force_) {
    u8 *saved = (u8 *)object;
    u32 force = (u32)force_;
    u32 *data = (u32 *)*(u32 *)(saved + 0x44);
    s32 failed = 0;
    s32 index;
    struct SfxNode *c;
    struct SfxNode *cur;
    if (saved == 0) return 0;
    index = saved ? ((s32)saved - *(s32 *)(s_pSfxMng + 0x10)) / 128 : 0;
    if (((struct SfxCreateEnt *)(*(u32 *)(s_pSfxMng + 0x1c) + index * 8))->state == 0) return 1;
    if (*(u32 *)(saved + 0x54) != 0) {
        for (c = ((struct SfxNode *)*(u32 *)(saved + 0x54))->next; c != 0; ) {
            cur = c;
            c = c->next;
            if (__SFXMNG_SfxDelete(cur, force) == 0) failed++;
        }
        if (__SFXMNG_SfxDelete((void *)*(u32 *)(saved + 0x54), force) == 0) failed++;
    }
    if (failed != 0) {
        ((struct SfxCreateEnt *)(*(u32 *)(s_pSfxMng + 0x1c) + index * 8))->state = 4;
        return 0;
    }
    {
        u32 cb = s_FuncTable[*(s32 *)data * 3 + 2];
        if (cb != 0 && ((u32 (*)(void *))cb)(saved) == 0) {
            ((struct SfxCreateEnt *)(*(u32 *)(s_pSfxMng + 0x1c) + index * 8))->state = 4;
            return 0;
        }
    }
    if (*(s32 *)(saved + 0x78) != -1) {
        if (force != 0) {
            PtclMng_SfxFreeAll(*(s32 *)(saved + 0x78));
            *(s32 *)(saved + 0x78) = -1;
        } else {
            *(s32 *)(saved + 0x78) = PtclMng_UpdateHandle(*(s32 *)(saved + 0x78));
            if (*(s32 *)(saved + 0x78) != -1) {
                ((struct SfxCreateEnt *)(*(u32 *)(s_pSfxMng + 0x1c) + index * 8))->state = 4;
                return 0;
            }
        }
    }
    {
        struct SfxNode *par = (struct SfxNode *)*(u32 *)(saved + 0x50);
        struct SfxNode *me = (struct SfxNode *)saved;
        if (par != 0) {
            struct SfxNode **pp = &par->child;
            if (par->child == me) *pp = me->next;
        }
        if (me->next != 0) me->next->prev = me->prev;
        if (me->prev != 0) me->prev->next = me->next;
    }
    if (*(u32 *)(saved + 0x60) != 0) {
        u32 ptr = *(u32 *)(saved + 0x60);
        u32 manager = s_pSfxMng;
        u32 first = *(u32 *)(manager + 0x28);
        if (ptr >= first && ptr + 0x40 < first + (*(u32 *)(manager + 0x24) << 5)) {
            s32 bit = (ptr - first) >> 5;
            memset((void *)ptr, 0, 0x40);
            ((struct SfxDelMng *)s_pSfxMng)->mask[bit / 32] &= ~(1U << (31 - bit % 32));
            ((struct SfxDelMng *)s_pSfxMng)->mask[(bit + 1) / 32] &= ~(1U << (31 - (bit + 1) % 32));
        }
        *(u32 *)(saved + 0x60) = 0;
    }
    if (*(u32 *)(s_pSfxMng + 0x18) != 0) *(u32 *)(*(u32 *)(s_pSfxMng + 0x18) + 0x58) = (u32)saved;
    *(u32 *)(s_pSfxMng + 0x18) = (u32)saved;
    *(s32 *)(s_pSfxMng + 4) = *(s32 *)(s_pSfxMng + 4) - 1;
    memset((void *)*(u32 *)(s_pSfxMng + 0x18), 0, 0x80);
    if (*(u32 *)(s_pSfxMng + 0x14) == 0) *(u32 *)(s_pSfxMng + 0x14) = *(u32 *)(s_pSfxMng + 0x18);
    ((struct SfxCreateEnt *)(*(u32 *)(s_pSfxMng + 0x1c) + index * 8))->state = 0;
    return 1;
}








signed int SfxMng_Kill(signed int handle) {
    u32 index;

    if ((u32)handle == (u32)-1) {
        return 0;
    }
    index = (u32)handle & 0xfff;
    if (((u32)(handle >> 0xc) & 0xfffff) != (((SfxKill_Mng *)s_pSfxMng)->handle[index].serial)) {
        return 0;
    }
    return __SFXMNG_SfxDelete(&((SfxKill_Mng *)s_pSfxMng)->sfx[index], 0);
}


/* SfxMng_DeleteAll @ 0x1CD210 .. 0x1CD290 (0x80 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001CD248
 *   declaration vs inferred signature: return void vs inferred u32
 */




void SfxMng_DeleteAll(signed int a0 /* r4 */) {
    s32 s2;
    u32 v1;
    s32 s1;
    s32 s0;

    s2 = a0;
    a0 = s_pSfxMng;
    if ((u32)(s32)a0 != 0 && 0 < (s32)*(s32 *)a0) {
        s1 = 0;
        s0 = 0;
        do {
            v1 = *(s32 *)(((s32)(a0) + 0x10));
            a0 = v1 + s0;
            if ((u32)(s32)a0 != 0) {
                __SFXMNG_SfxDelete((void *)a0, s2);
            }
            a0 = s_pSfxMng;
            s1 = s1 + 1;
            s0 = s0 + 0x80;
        } while ((u32)(s1 < (s32)*(s32 *)a0) != 0);
    }
    return;
}


/* SfxMng_AttachMatrix @ 0x1CD190 .. 0x1CD208 (0x78 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1cd198 writes a register its branch at 0x1cd194 reads
 *   delay: addiu at 0x1cd1d8 writes a register its branch at 0x1cd1d4 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */





signed int SfxMng_AttachMatrix(signed int a0 /* r4 */, void *a1 /* r5 */) {
    u32 a3;
    u32 v0;

    if ((u32)(s32)a0 == (u32)-1) {
        return 0;
    }
    a3 = (u32)(a0) & 0xfff;
    v0 = (s32)a0 >> 0xc;
    a0 = v0 & 0xfffff;
    v0 = (u32)&((struct { u8 b[8]; } *)*(s32 *)(((u8 *)(u32 *)s_pSfxMng + 0x1c)))[a3];
    v0 = *(s32 *)((v0 + 4));
    if ((u32)a0 != (u32)(v0 & 0xfffff)) {
        return 1;
    }
    *(u32 *)(((u32)(u32)&((struct { u8 b[0x80]; } *)*(s32 *)(((u8 *)(u32 *)s_pSfxMng + 0x10)))[a3]
        + 0x64)) = (u32)a1;
    return 1;
}

static inline signed int SfxMng_HandleOf(struct dw_2094394 *p) {
    s32 index = p ? ((s32)((u8 *)p - *(u8 **)(s_pSfxMng + 0x10)) / 128) : 0;
    return (index & 0xfff) | ((*(s32 *)(*(s32 *)(s_pSfxMng + 0x1c) + index * 8 + 4) & 0xfffff) << 12);
}

signed int SfxMng_EnableDraw(signed int hSfx_, signed int bEnable_, signed int bApplySibling_, unsigned short ctrl_) {
    struct dw_2094394 *p;
    u32 index;

    if ((u32)hSfx_ == (u32)-1) {
        return 0;
    }
    index = (u32)hSfx_ & 0xfff;
    if (((u32)(hSfx_ >> 0xc) & 0xfffff) != (u32)(((SfxKill_Mng *)s_pSfxMng)->handle[index].serial)) {
        return 0;
    }
    p = (struct dw_2094394 *)&((SfxKill_Mng *)s_pSfxMng)->sfx[index];
    if (p->ptcl_handle != -1) {
        PtclMng_EnableDraw(p->ptcl_handle, bEnable_, ctrl_);
    }
    switch (ctrl_) {
    case 0:
        p->flags.f_disable_draw = (bEnable_ != 0) ^ 1;
        break;
    case 1:
        p->flags.f_disable_draw_by_map = (bEnable_ != 0) ^ 1;
        break;
    }
    if (p->prog_no == 8) {
        u32 cb = s_FuncTable[*(s32 *)p->p_sfx_data * 3 + 1];
        if (cb != 0 && !p->flags.f_disable_act) {
            ((void (*)(void *))cb)(p);
        }
    }
    if (p->p_child != 0) {
        SfxMng_EnableDraw(SfxMng_HandleOf(p->p_child), bEnable_, 1, ctrl_);
    }
    if (bApplySibling_ != 0) {
        if (p->p_sibling != 0) {
            SfxMng_EnableDraw(SfxMng_HandleOf(p->p_sibling), bEnable_, 1, ctrl_);
        }
    }
    return 1;
}

signed int SfxMng_EnableAction(signed int hSfx_, signed int bEnable_, signed int bApplySibling_, unsigned short ctrl_) {
    struct dw_2094394 *p;
    u32 index;

    if ((u32)hSfx_ == (u32)-1) {
        return 0;
    }
    index = (u32)hSfx_ & 0xfff;
    if (((u32)(hSfx_ >> 0xc) & 0xfffff) != (u32)(((SfxKill_Mng *)s_pSfxMng)->handle[index].serial)) {
        return 0;
    }
    p = (struct dw_2094394 *)&((SfxKill_Mng *)s_pSfxMng)->sfx[index];
    if (p->ptcl_handle != -1) {
        PtclMng_EnableAction(p->ptcl_handle, bEnable_, ctrl_);
    }
    switch (ctrl_) {
    case 0:
        p->flags.f_disable_act = (bEnable_ != 0) ^ 1;
        break;
    case 1:
        p->flags.f_disable_act_by_map = (bEnable_ != 0) ^ 1;
        break;
    }
    if (p->prog_no == 7) {
        u32 cb = s_FuncTable[*(s32 *)p->p_sfx_data * 3 + 1];
        if (cb != 0) {
            ((void (*)(void *))cb)(p);
        }
    }
    if (p->p_child != 0) {
        SfxMng_EnableAction(SfxMng_HandleOf(p->p_child), bEnable_, 1, ctrl_);
    }
    if (bApplySibling_ != 0) {
        if (p->p_sibling != 0) {
            SfxMng_EnableAction(SfxMng_HandleOf(p->p_sibling), bEnable_, 1, ctrl_);
        }
    }
    return 1;
}








/* SfxMng_GetSfxState @ 0x1CCC50 .. 0x1CCC98 (0x48 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1ccc80 writes a register its branch at 0x1ccc7c reads
 *   declaration vs inferred signature: return unsigned char vs inferred u8
 */


unsigned char SfxMng_GetSfxState(signed int a0 /* r4 */) {
    s32 a1;
    u32 v1;
    u32 v0;

    v0 = (u32)(a0) & 0xfff;
    a1 = v0 << 3;
    v0 = (s32)a0 >> 0xc;
    v1 = v0 & 0xfffff;
    v0 = s_pSfxMng;
    v0 = *(s32 *)((v0 + 0x1c));
    a0 = v0 + a1;
    v0 = *(s32 *)(((s32)(a0) + 4));
    v0 = v0 & 0xfffff;
    if (v1 != v0) {
        return 0;
    }
    v0 = *(u8 *)a0;
    return v0;
}



void SfxMng_DeleteBySfxIdx(unsigned short effect) {
    s32 i;
    u8 *entry;
    s32 offset;
    u16 index;
    u32 manager, base, object, handle, slot, generation;
    manager = s_pSfxMng;
    entry = (u8 *)*(u32 *)(manager + 28);
    i = 0;
    if (0 < *(s32 *)manager) {
        index = effect;
        offset = 0;
        do {
            if (*entry == 2) {
                base = *(u32 *)(manager + 16);
                object = base + offset;
                if (index == *(u16 *)(*(u32 *)(object + 68) + 62)) {
                    if (!object) handle = -1;
                    else {
                        if (object) slot = (s32)(object - base) / 128;
                        else slot = 0;
                        handle = (slot & 4095) | ((*(u32 *)(*(u32 *)(manager + 28) + slot * 8 + 4) & 0xfffff) << 12);
                    }
                    if (handle != (u32)-1) {
                        slot = handle & 4095;
                        generation = ((s32)handle >> 12) & 0xfffff;
                        if (generation == (*(u32 *)(*(u32 *)(manager + 28) + slot * 8 + 4) & 0xfffff))
                            __SFXMNG_SfxDelete((void *)(base + slot * 128), 0);
                    }
                }
            }
            i++;
            offset += 128;
            manager = s_pSfxMng;
            entry += 8;
        } while (i < *(s32 *)manager);
    }
}











static char * __SFXMNG_DataAlloc(int size) {
    int ii;
    int cell_num;
    unsigned int flag;
    unsigned int bit_flag;
    int jj;
    int kk;

    cell_num = (size + 31U) >> 5;
    for (ii = 0, flag = 1; ii < cell_num - 1; ii++) {
        flag <<= 1;
        flag |= 1;
    }
    for (ii = 0; ii < *(s32 *)(s_pSfxMng + 0x24) / 32; ii++) {
        if (((u32 *)*(u32 *)(s_pSfxMng + 0x2c))[ii] != -1) {
            bit_flag = ((u32 *)*(u32 *)(s_pSfxMng + 0x2c))[ii];
            for (kk = 0, jj = cell_num - 1; jj < 32; jj++, kk++) {
                if (((bit_flag >> (31 - jj)) & flag) == 0) {
                    ((u32 *)*(u32 *)(s_pSfxMng + 0x2c))[ii] |= flag << (31 - jj);
                    return (char *)(*(u32 *)(s_pSfxMng + 0x28) + (ii * 32 + kk) * 32);
                }
            }
        }
    }
    return 0;
}
static signed int __SFXMNG_Default_Init(void *a0 /* r4 */) {
    u8 *saved;
    u8 *params;
    u8 *data;
    float f12;
    float *a1;
    float rnd;
    char dbg[256] __attribute__((aligned(16)));
    float mrx[4][4] __attribute__((aligned(16)));

    saved = (u8 *)a0;
    params = *(u8 **)(saved + DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214);
    *(u32 *)(saved + 0x60) = (u32)__SFXMNG_DataAlloc(0x40);
    if (*(u32 *)(saved + 0x60) == 0) {
        a1 = (float *)"SfxMng.c";
        strcpy((char *)((u8 *)&dbg[0]), "SfxMng.c");
        a1 = (float *)"Failed to alloc matrix.";
        SfxDbg_SetDebugMsg(0, "Failed to alloc matrix.", (char *)((u8 *)&dbg[0]), 0x746);
    }
    if (*(u32 *)(saved + 0x60) == 0) return 0;
    *(u32 *)(saved + 0x6c) = (u32)__SFXMNG_DataAlloc(0x10);
    data = *(u8 **)(saved + 0x6c);
    if (data == 0) return 0;
    rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
    *(u32 *)(saved + 0x70) = (u32)((float)*(u32 *)params + (float)*(u32 *)(params + 4) * (rnd - 0.5f));
    rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
    *(float *)(saved + 0x10) = *(float *)(saved + 0x10) + 0.01745f * (*(float *)(params + 8) + *(float *)(params + 0xc) * (rnd - 0.5f));
    rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
    *(float *)(saved + 0x14) = *(float *)(saved + 0x14) + 0.01745f * (*(float *)(params + 0x10) + *(float *)(params + 0x14) * (rnd - 0.5f));
    f12 = *(float *)(saved + 0x10);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(float *)(saved + 0x10) = f12;
    f12 = *(float *)(saved + 0x14);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(float *)(saved + 0x14) = f12;
    f12 = *(float *)(saved + 0x18);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(float *)(saved + 0x18) = f12;
    *(float *)saved = *(float *)saved + *(float *)(params + 0x20);
    *(float *)(saved + 4) = *(float *)(saved + 4) + *(float *)(params + 0x24);
    *(float *)(saved + 8) = *(float *)(saved + 8) + *(float *)(params + 0x28);
    a1 = (float *)V0;
    sceVu0CopyVector(data, (void *)V0);
    rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
    *(float *)(data + 8) = *(float *)(params + 0x18) + *(float *)(params + 0x1c) * (rnd - 0.5f);
    SfxCalc_MakeRotTransMatrix_I(mrx, (float *)saved, (float *)(saved + 0x10), (float *)(saved + 0x20));
    sceVu0ApplyMatrix(data, mrx, data);
    return 1;
}
static signed int __SFXMNG_Default_Act(void *object) {
    u8 *saved;
    u8 *fix;
    s32 cnt;
    u8 *data;
    float grav[1];
    float ang[3];
    float acc[2];
    float step[4] __attribute__((aligned(16)));
    float dir[4] __attribute__((aligned(16)));
    float vt[4] __attribute__((aligned(16)));
    float v[6];
    float f12;
    void *pm;
    saved = object;
    data = *(u8 **)(saved + 0x6c);
    cnt = *(s32 *)(saved + 0x74);
    SFX_GetSeqParam(ang, 6, 3, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 0x1c), cnt);
    *(float *)(saved + 0x10) = *(float *)(saved + 0x10) + 0.0166666f * (0.01745f * ang[0]);
    *(float *)(saved + 0x14) = *(float *)(saved + 0x14) + 0.0166666f * (0.01745f * ang[1]);
    *(float *)(saved + 0x18) = *(float *)(saved + 0x18) + 0.0166666f * (0.01745f * ang[2]);
    f12 = *(float *)(saved + 0x10);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(float *)(saved + 0x10) = f12;
    f12 = *(float *)(saved + 0x14);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(float *)(saved + 0x14) = f12;
    f12 = *(float *)(saved + 0x18);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(float *)(saved + 0x18) = f12;
    fix = *(u8 **)(saved + 0x48);
    SFX_GetSeqParam(&v[0], 6, 2, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 0x24), *(s32 *)(saved + 0x74));
    if (fix[0x2c] != 0) {
        *(float *)(saved + 0x20) = *(float *)(saved + 0x24) = *(float *)(saved + 0x28) = v[0];
    } else {
        SFX_GetSeqParam(&v[2], 6, 2, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 0x2c), *(s32 *)(saved + 0x74));
        SFX_GetSeqParam(&v[4], 6, 2, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 0x34), *(s32 *)(saved + 0x74));
        *(float *)(saved + 0x20) = v[0];
        *(float *)(saved + 0x24) = v[2];
        *(float *)(saved + 0x28) = v[4];
    }
    sceVu0ScaleVector(step, data, 0.0166666f);
    sceVu0AddVector(saved, step, saved);
    SFX_GetSeqParam(acc, 6, 2, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 0xc), cnt);
    SfxCalc_Angle2VectorZXY(dir, (float *)(saved + 0x10));
    sceVu0ScaleVector(vt, dir, 0.0166666f * acc[0]);
    sceVu0AddVector(data, vt, data);
    SFX_GetSeqParam(grav, 6, 1, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 0x14), cnt);
    *(float *)(data + 4) = *(float *)(data + 4) + 0.0166666f * grav[0] * (float)cnt;
    SfxCalc_MakeRotTransMatrix_I(*(void **)(saved + 0x60), (float *)saved, (float *)(saved + 0x10), (float *)(saved + 0x20));
    pm = *(void **)(saved + 0x64);
    if (pm != 0) {
        dcomp_cop2_9397A3F6B7(*(void **)(saved + 0x60), pm, *(void **)(saved + 0x60));
    }
    return 1;
}


/* __SFXMNG_Default_End @ 0x1CBFE0 .. 0x1CC0B8 (0xd8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */








static signed int __SFXMNG_Default_End(void *a0 /* r4 */) {
    u8 *s1;
    u32 a1;
    u32 v1;
    s32 s0;

    s1 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x6c));
    if ((u32)(s32)a0 != 0) {
        v1 = s_pSfxMng;
        a1 = *(s32 *)((v1 + 0x28));
        if ((u32)((u32)(s32)a0 < a1) == 0) {
            if ((u32)(s32)((u8 *)a0 + 0x20) < (u32)(a1 + (s32)((u32)*(s32 *)((v1 + 0x24)) << 5))) {
                s0 = (u32)(s32)((u8 *)a0 - a1) >> 5;
                memset(a0, 0, 0x20);
                a0 = (void *)s_pSfxMng;
                v1 = *(s32 *)(((u8 *)a0 + 0x2c)) + (s32)((u32)(s0 / (s32)(0x20)) << 2);
                *(u32 *)v1 &= ~(u32)((u32)1 << (u32)(s32)((u8 *)(s32)0x1f - (u32)(s0 %
                    (s32)(0x20))));
            }
        }
        *(u32 *)(s1 + 0x6c) = 0;
    }
    return 1;
}
static signed int __SFXMNG_Default2_Init(void *a0 /* r4 */) {
    u8 *saved;
    u8 *params;
    u8 *data;
    float f12;
    float *a1;
    float rnd;
    char dbg[256] __attribute__((aligned(16)));
    float mrx[4][4] __attribute__((aligned(16)));

    saved = (u8 *)a0;
    params = *(u8 **)(saved + DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214);
    *(u32 *)(saved + 0x60) = (u32)__SFXMNG_DataAlloc(0x40);
    if (*(u32 *)(saved + 0x60) == 0) {
        a1 = (float *)"SfxMng.c";
        strcpy((char *)((u8 *)&dbg[0]), "SfxMng.c");
        a1 = (float *)"Failed to alloc matrix.";
        SfxDbg_SetDebugMsg(0, "Failed to alloc matrix.", (char *)((u8 *)&dbg[0]), 0x81d);
    }
    if (*(u32 *)(saved + 0x60) == 0) return 0;
    *(u32 *)(saved + 0x6c) = (u32)__SFXMNG_DataAlloc(0x10);
    data = *(u8 **)(saved + 0x6c);
    if (data == 0) return 0;
    rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
    *(u32 *)(saved + 0x70) = (u32)((float)*(u32 *)params + (float)*(u32 *)(params + 4) * (rnd - 0.5f));
    switch (*(u8 *)(params + 0x38)) {
    case 0:
    rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
    *(float *)(saved + 0x10) = *(float *)(saved + 0x10) + 0.01745f * (*(float *)(params + 8) + *(float *)(params + 0xc) * (rnd - 0.5f));
    rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
    *(float *)(saved + 0x14) = *(float *)(saved + 0x14) + 0.01745f * (*(float *)(params + 0x10) + *(float *)(params + 0x14) * (rnd - 0.5f));
    f12 = *(float *)(saved + 0x10);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(float *)(saved + 0x10) = f12;
    f12 = *(float *)(saved + 0x14);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(float *)(saved + 0x14) = f12;
    f12 = *(float *)(saved + 0x18);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(float *)(saved + 0x18) = f12;
        break;
    case 1:
    case 2:
        break;
    }
    switch (*(u8 *)(params + 0x38)) {
    case 0:
        *(u32 *)data = 0;
        *(u32 *)(data + 4) = 0;
        rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
        *(float *)(data + 8) = *(float *)(params + 0x30) + *(float *)(params + 0x34) * (rnd - 0.5f);
        *(u32 *)(data + 0xc) = 0;
        break;
    case 1:
    case 2:
        break;
    }
    SfxCalc_MakeRotTransMatrix_I(mrx, (float *)saved, (float *)(saved + 0x10), (float *)(saved + 0x20));
    sceVu0ApplyMatrix(data, mrx, data);
    return 1;
}
static signed int __SFXMNG_Default2_Act(void *object) {
    u8 *saved;
    s32 cnt;
    u8 *data;
    float grav[1];
    float ang[3];
    float acc[2];
    float v[6];
    float step[4] __attribute__((aligned(16)));
    float dir[4] __attribute__((aligned(16)));
    float f12;
    void *pm;
    saved = object;
    data = *(u8 **)(saved + 0x6c);
    cnt = *(s32 *)(saved + 0x74);
    SFX_GetSeqParam(ang, 6, 3, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 0x14), cnt);
    *(float *)(saved + 0x10) = *(float *)(saved + 0x10) + 0.0166666f * (0.01745f * ang[0]);
    *(float *)(saved + 0x14) = *(float *)(saved + 0x14) + 0.0166666f * (0.01745f * ang[1]);
    *(float *)(saved + 0x18) = *(float *)(saved + 0x18) + 0.0166666f * (0.01745f * ang[2]);
    f12 = *(float *)(saved + 0x10);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(float *)(saved + 0x10) = f12;
    f12 = *(float *)(saved + 0x14);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(float *)(saved + 0x14) = f12;
    f12 = *(float *)(saved + 0x18);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(float *)(saved + 0x18) = f12;
    SFX_GetSeqParam(&v[0], 6, 2, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 0x1c), cnt);
    SFX_GetSeqParam(&v[2], 6, 2, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 0x24), cnt);
    SFX_GetSeqParam(&v[4], 6, 2, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 0x2c), cnt);
    *(float *)(saved + 0x20) = v[0];
    *(float *)(saved + 0x24) = v[2];
    *(float *)(saved + 0x28) = v[4];
    sceVu0ScaleVector(step, data, 0.0166666f);
    sceVu0AddVector(saved, saved, step);
    SFX_GetSeqParam(acc, 6, 2, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 0x4), cnt);
    SfxCalc_Angle2VectorZXY(dir, (float *)(saved + 0x10));
    sceVu0ScaleVector(dir, dir, 0.0166666f * (acc[0] + acc[1]));
    sceVu0AddVector(data, data, dir);
    SFX_GetSeqParam(grav, 6, 1, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 0xc), cnt);
    *(float *)(data + 4) = *(float *)(data + 4) + 0.0166666f * grav[0];
    SfxCalc_MakeRotTransMatrix_I(*(void **)(saved + 0x60), (float *)saved, (float *)(saved + 0x10), (float *)(saved + 0x20));
    pm = *(void **)(saved + 0x64);
    if (pm != 0) {
        dcomp_cop2_9397A3F6B7(*(void **)(saved + 0x60), pm, *(void **)(saved + 0x60));
    }
    return 1;
}


/* __SFXMNG_Default2_End @ 0x1CB680 .. 0x1CB758 (0xd8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */








static signed int __SFXMNG_Default2_End(void *a0 /* r4 */) {
    u8 *s1;
    u32 a1;
    u32 v1;
    s32 s0;

    s1 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x6c));
    if ((u32)(s32)a0 != 0) {
        v1 = s_pSfxMng;
        a1 = *(s32 *)((v1 + 0x28));
        if ((u32)((u32)(s32)a0 < a1) == 0) {
            if ((u32)(s32)((u8 *)a0 + 0x20) < (u32)(a1 + (s32)((u32)*(s32 *)((v1 + 0x24)) << 5))) {
                s0 = (u32)(s32)((u8 *)a0 - a1) >> 5;
                memset(a0, 0, 0x20);
                a0 = (void *)s_pSfxMng;
                v1 = *(s32 *)(((u8 *)a0 + 0x2c)) + (s32)((u32)(s0 / (s32)(0x20)) << 2);
                *(u32 *)v1 &= ~(u32)((u32)1 << (u32)(s32)((u8 *)(s32)0x1f - (u32)(s0 %
                    (s32)(0x20))));
            }
        }
        *(u32 *)(s1 + 0x6c) = 0;
    }
    return 1;
}


/* __SFXMNG_CallEmitter_Init @ 0x1CB5B0 .. 0x1CB67C (0xcc bytes, frame 0x130) */
/*
 * dcomp notes:
 *   literal: @2740 is the string 'SfxMng.c'
 *   literal: @4122 is the string 'DataAlloc Failed'
 *   stack: address of the slot at 0x30 escapes at 0x1cb5e4
 *   stack: address of the slot at 0x30 escapes at 0x1cb5fc
 *   declaration vs inferred signature: return signed int vs inferred u32
 */








static signed int __SFXMNG_CallEmitter_Init(void *a0 /* r4 */) {
    u8 *s1;
    u8 *s0;
    u32 a1;
    u8 *a0_2; // a0
    u32 bitfield_snapshot_1cb638;
    u32 v1;
    u32 v0;
    u8 stackFrame_30[256] __attribute__((aligned(16)));

    s1 = (u8 *)a0;
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x48));
    v0 = (u32)__SFXMNG_DataAlloc(4);
    *(u32 *)(s1 + 0x6c) = v0;
    v0 = *(s32 *)(s1 + 0x6c);
    if (v0 == 0) {
        a1 = (u32)"SfxMng.c";
        strcpy((char *)((u8 *)&stackFrame_30[0]), (const char *)"SfxMng.c");
        a1 = (u32)"DataAlloc Failed";
        SfxDbg_SetDebugMsg(0, "DataAlloc Failed", (char *)(u8 *)((u8 *)&stackFrame_30[0]), 0x900);
        v0 = 0;
    } else {
        v0 = *(s32 *)(s0 + 4);
        if ((s32)v0 < 0) {
            v0 = 0x7fffffff;
            *(u32 *)(s1 + 0x70) = 0x7fffffff;
        } else {
            *(u32 *)(s1 + 0x70) = v0;
        }
        bitfield_snapshot_1cb638 = *(u16 *)(s0 + 0x10);
        v0 = 1;
        ((struct { unsigned char f:1; } *)&*(u8 *)(s1 + 0x7e))->f = bitfield_snapshot_1cb638;
        a0_2 = (u8 *)*(s32 *)(s1 + 0x6c);
        *(u16 *)a0_2 = 0;
        v1 = *(u16 *)(s0 + 0x2c);
        *(u16 *)(a0_2 + 2) = v1;
    }
    return v0;
}

static inline float SfxCalc_NormAng(float a) {
    return (a < -3.14159f || 3.14159f < a) ? SfxCalc_IntoAngle_0_2PI(a) - 6.28318f : a;
}
static signed int __SFXMNG_CallEmitter_Act(void *a0 /* r4 */) {
    struct dw_2094394 *p_sfx;
    struct dw_2105820 *p_fix_param;
    struct dw_2109473 *p_sfx_data;
    struct dw_2110996 desc;
    float add_loc[4];
    float mRot[4][4];
    int handle;
    int next;

    p_sfx = (struct dw_2094394 *)a0;
    p_fix_param = (struct dw_2105820 *)p_sfx->p_fix_param;
    p_sfx_data = (struct dw_2109473 *)p_sfx->p_data;

    if (p_sfx_data->gen_wait == 0 && 0 < p_sfx_data->call_num) {
        memset(&desc, 0, 0x90);
        desc.prog_no = p_fix_param->id;
        desc.prev_ptcl = p_sfx->ptcl_handle;
        desc.ptcl_num = p_fix_param->num;
        desc.sfx_sttdata_idx = ((struct dw_2096304 *)p_sfx->p_sfx_data)->CommonParam.sfx_idx;
        if (p_sfx->flags.f_independent) {
            add_loc[0] = p_fix_param->loc[0];
            add_loc[1] = p_fix_param->loc[1];
            add_loc[2] = p_fix_param->loc[2];
            add_loc[3] = 1.0f;
            sceVu0ApplyMatrix(&desc.loc, p_sfx->p_parent_matrix, add_loc);
            SfxCalc_PYRfromRotMatrix(p_sfx->p_parent_matrix, &desc.ang[0], &desc.ang[1], &desc.ang[2]);
            desc.ang[0] += p_fix_param->ang[0] * 0.01745f;
            desc.ang[1] += p_fix_param->ang[1] * 0.01745f;
            desc.ang[2] += p_fix_param->ang[2] * 0.01745f;
            desc.ang[0] = SfxCalc_NormAng(desc.ang[0]);
            desc.ang[1] = SfxCalc_NormAng(desc.ang[1]);
            desc.ang[2] = SfxCalc_NormAng(desc.ang[2]);
            sceVu0CopyMatrix(&desc, p_sfx->p_parent_matrix);
            sceVu0Normalize(&desc.mRot[0], &desc.mRot[0]);
            sceVu0Normalize(&desc.mRot[1], &desc.mRot[1]);
            sceVu0Normalize(&desc.mRot[2], &desc.mRot[2]);
            sceVu0CopyVector(&desc.mRot[3], VW);
            if (p_sfx->p_parent != 0) {
                sceVu0CopyVector(&desc.scale, p_sfx->p_parent->pb.scale);
            } else {
                float one[4] = { 1.0f, 1.0f, 1.0f, 0.0f };
                sceVu0CopyVector(&desc.scale, one);
            }
            desc.p_matrix = 0;
        } else {
            desc.loc[0] = p_fix_param->loc[0];
            desc.loc[1] = p_fix_param->loc[1];
            desc.loc[2] = p_fix_param->loc[2];
            desc.loc[3] = 1.0f;
            desc.ang[0] = p_fix_param->ang[0] * 0.01745f;
            desc.ang[1] = p_fix_param->ang[1] * 0.01745f;
            desc.ang[2] = p_fix_param->ang[2] * 0.01745f;
            desc.ang[3] = 0.0f;
            desc.scale[2] = 1.0f;
            desc.scale[1] = 1.0f;
            desc.scale[0] = 1.0f;
            desc.ang[0] = SfxCalc_NormAng(desc.ang[0]);
            desc.ang[1] = SfxCalc_NormAng(desc.ang[1]);
            desc.ang[2] = SfxCalc_NormAng(desc.ang[2]);
            sceVu0CopyMatrix(&desc, MRX1);
            desc.p_matrix = p_sfx->p_parent_matrix;
        }
        SfxCalc_MakeMatrixFromPYR(&mRot, p_fix_param->ang[0], p_fix_param->ang[1],
                                  p_fix_param->ang[2]);
        dcomp_cop2_9397A3F6B7(&desc.mRot, &desc.mRot, &mRot);
        desc.flag.disable_draw_scr = p_sfx->flags.f_disable_draw;
        desc.flag.disable_draw_map = p_sfx->flags.f_disable_draw_by_map;
        handle = PtclMng_SfxCreate(&desc);
        if (p_sfx->ptcl_handle == -1) {
            p_sfx->ptcl_handle = handle;
        }
        if (p_fix_param->frame != 0) {
            next = p_fix_param->frame - 1;
            if (0 < p_fix_param->gen_rnd) {
                float r;
                r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
                next = (int)(next + p_fix_param->gen_rnd * (r - 0.5f));
            }
            p_sfx_data->gen_wait = (0 < next) ? (unsigned short)next : 0;
        } else {
            p_sfx_data->gen_wait = 0xffff;
        }
        if (p_sfx_data->call_num != 0xffff) {
            p_sfx_data->call_num -= 1;
        }
    } else {
        if (p_fix_param->frame != 0) {
            p_sfx_data->gen_wait -= 1;
        }
    }
    return 1;
}



/* __SFXMNG_CallEmitter_End @ 0x1CAE20 .. 0x1CAF30 (0x110 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




static signed int __SFXMNG_CallEmitter_End(void *a0 /* r4 */) {
    u8 *s1;
    u32 a1;
    u32 v1;
    u32 v0;
    s32 s0;

    v0 = -1;
    s1 = (u8 *)a0;
    v1 = *(s32 *)(((u8 *)a0 + 0x48));
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x78));
    if ((u32)(s32)a0 != v0) {
        v1 = *(u16 *)((v1 + 0x12));
        v0 = 1;
        if (v1 == v0) {
            v0 = PtclMng_SfxFreeAll((signed int)a0);
            if (v0 == 0) {
                *(u32 *)(s1 + 0x78) = -1;
            }
        }
    }
    a0 = (void *)*(s32 *)(s1 + 0x6c);
    if ((u32)(s32)a0 != 0) {
        v1 = s_pSfxMng;
        a1 = *(s32 *)((v1 + 0x28));
        v0 = (u32)(s32)a0 < a1;
        if (v0 == 0) {
            v0 = (u32)*(s32 *)((v1 + 0x24)) << 5;
            v1 = (s32)((u8 *)a0 + 0x20);
            if (v1 < (u32)(a1 + v0)) {
                s0 = (u32)(s32)((u8 *)a0 - a1) >> 5;
                memset(a0, 0, 0x20);
                a0 = (void *)s_pSfxMng;
                v1 = *(s32 *)(((u8 *)a0 + 0x2c)) + (s32)((u32)(s0 / (s32)(0x20)) << 2);
                *(u32 *)v1 &= ~(s32)((u32)1 << (u32)(s32)((u8 *)(s32)0x1f - (u32)(s0 %
                    (s32)(0x20))));
            }
        }
        *(u32 *)(s1 + 0x6c) = 0;
    }
    return 1;
}


/* __SFXMNG_CallSfx_Init @ 0x1CAD00 .. 0x1CAE18 (0x118 bytes, frame 0x140) */
/*
 * dcomp notes:
 *   literal: @2740 is the string 'SfxMng.c'
 *   literal: @4122 is the string 'DataAlloc Failed'
 *   stack: address of the slot at 0x40 escapes at 0x1cad7c
 *   stack: address of the slot at 0x40 escapes at 0x1cad94
 *   v0#3 is the pointer held in a0+0x6c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int __SFXMNG_CallSfx_Init(void *a0 /* r4 */) {
    u8 *s1;
    u8 *s0;
    u32 a1;
    u32 s2;
    u8 *a0_2; // a0
    u32 bitfield_snapshot_1cadd0;
    u32 v1;
    u32 v0;
    u8 stackFrame_40[256] __attribute__((aligned(16)));

    s1 = (u8 *)a0;
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x48));
    v0 = (u32)__SFXMNG_DataAlloc(0x40);
    *(u32 *)(s1 + 0x60) = v0;
    s2 = *(s32 *)(s1 + 0x60);
    if (s2 == 0) {
        v0 = 0;
    } else {
        SfxCalc_MakeMatrixFromPYR((void *)s2, *(float *)(s1 + 0x10), *(float *)(s1 + 0x14), *(float
            *)(s1 + 0x18));
        sceVu0CopyVector((void *)(u32)(s2 + 0x30), (void *)s1);
        v0 = (u32)__SFXMNG_DataAlloc(4);
        *(u32 *)(s1 + 0x6c) = v0;
        v0 = *(s32 *)(s1 + 0x6c);
        if (v0 == 0) {
            a1 = (u32)"SfxMng.c";
            strcpy((char *)((u8 *)&stackFrame_40[0]), (const char *)"SfxMng.c");
            a1 = (u32)"DataAlloc Failed";
            SfxDbg_SetDebugMsg(0, "DataAlloc Failed", (char *)(u8 *)((u8 *)&stackFrame_40[0]),
                0xa3e);
            v0 = 0;
        } else {
            v0 = *(s32 *)(s0 + 4);
            if ((s32)v0 < 0) {
                v0 = 0x7fffffff;
                *(u32 *)(s1 + 0x70) = 0x7fffffff;
            } else {
                *(u32 *)(s1 + 0x70) = v0;
            }
            bitfield_snapshot_1cadd0 = *(u16 *)(s0 + 0x10);
            v0 = 1;
            ((struct { unsigned char f:1; } *)&*(u8 *)(s1 + 0x7e))->f = bitfield_snapshot_1cadd0;
            a0_2 = (u8 *)*(s32 *)(s1 + 0x6c);
            *(u16 *)a0_2 = 0;
            v1 = *(u16 *)(s0 + 0x2c);
            *(u16 *)(a0_2 + 2) = v1;
        }
    }
    return v0;
}
static signed int __SFXMNG_CallSfx_Act(void *object) {
    s32 i;
    u8 *parent;
    s32 next;
    u8 *saved;
    u8 *fix;
    u8 *data;
    u8 *sfxdata;
    float pos[4] __attribute__((aligned(16)));
    float ang[4] __attribute__((aligned(16)));
    float scl[4] __attribute__((aligned(16)));
    float tmp[4] __attribute__((aligned(16)));
    void *pm;
    saved = object;
    data = *(u8 **)(saved + 0x6c);
    fix = *(u8 **)(saved + 0x48);
    if (*(u16 *)data == 0 && 0 < *(u16 *)(data + 2)) {
        sfxdata = ((u8 **)((u8 *)s_pSfxMng + 0x30))[*(s32 *)fix];
        if (*(u32 *)(saved + 0x50) != 0 && (saved[0x7e] & 1)) {
            if (*(u32 *)(saved + 0x64) != 0) {
                tmp[0] = *(float *)(fix + 0x14);
                tmp[1] = *(float *)(fix + 0x18);
                tmp[2] = *(float *)(fix + 0x1c);
                tmp[3] = 1.0f;
                sceVu0ApplyMatrix(pos, (void *)*(u32 *)(saved + 0x64), tmp);
                SfxCalc_Vector2Angle(ang, (float *)(*(u32 *)(saved + 0x64) + 0x20));
            } else {
                sceVu0CopyVector(pos, saved);
                sceVu0CopyVector(ang, saved + 0x10);
                pos[0] += *(float *)(fix + 0x14);
                pos[1] += *(float *)(fix + 0x18);
                pos[2] += *(float *)(fix + 0x1c);
            }
            sceVu0CopyVector(scl, (void *)(*(u32 *)(saved + 0x50) + 0x20));
            ang[0] += 0.01745f * *(float *)(fix + 0x20);
            ang[1] += 0.01745f * *(float *)(fix + 0x24);
            ang[2] += 0.01745f * *(float *)(fix + 0x28);
            ang[0] = SfxCalc_NormAng(ang[0]);
            ang[1] = SfxCalc_NormAng(ang[1]);
            ang[2] = SfxCalc_NormAng(ang[2]);
            parent = 0;
        } else {
            sceVu0CopyVector(pos, saved);
            sceVu0CopyVector(ang, saved + 0x10);
            pos[0] += *(float *)(fix + 0x14);
            pos[1] += *(float *)(fix + 0x18);
            pos[2] += *(float *)(fix + 0x1c);
            pos[3] = 1.0f;
            ang[0] += 0.01745f * *(float *)(fix + 0x20);
            ang[1] += 0.01745f * *(float *)(fix + 0x24);
            ang[2] += 0.01745f * *(float *)(fix + 0x28);
            ang[3] = 0.0f;
            scl[0] = scl[1] = scl[2] = scl[3] = 1.0f;
            parent = 0;
        }
        for (i = 0; i < *(u32 *)(fix + 0xc); i++) {
            __SFXMNG_SfxCreateFromData(sfxdata, pos, ang, scl, 0, (void *)*(u32 *)(saved + 0x68), parent, saved[0x7d], saved[0x7c]);
        }
        if (*(u32 *)(fix + 8) != 0) {
            next = *(u32 *)(fix + 8) - 1;
            if (0 < *(s16 *)(fix + 0x2e)) {
                float r;
                r = (float)(SfxCalc_RandU32() & 0xffff) * (1.0f / 65535.0f);
                next = (int)(next + *(s16 *)(fix + 0x2e) * (r - 0.5f));
            }
            *(u16 *)data = (0 < next) ? (unsigned short)next : 0;
        } else {
            *(u16 *)data = 0xffff;
        }
        if (*(u16 *)(data + 2) != 0xffff) {
            *(u16 *)(data + 2) -= 1;
            if (*(u16 *)(data + 2) == 0) {
                *(u32 *)(saved + 0x70) = 0;
                return 0;
            }
        }
    } else {
        if (*(u32 *)(fix + 8) != 0) {
            *(u16 *)data -= 1;
        }
    }
    SfxCalc_MakeMatrix_SPYRT(*(void **)(saved + 0x60), (float *)(saved + 0x20), (float *)(saved + 0x10), (float *)saved);
    pm = *(void **)(saved + 0x64);
    if (pm != 0) {
        dcomp_cop2_9397A3F6B7(*(void **)(saved + 0x60), pm, *(void **)(saved + 0x60));
    }
    return 1;
}







/* __SFXMNG_HitObject_Init @ 0x1CA670 .. 0x1CA788 (0x118 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x60 escapes at 0x1ca6b8
 *   stack: address of the slot at 0x60 escapes at 0x1ca6c4
 *   fpu: float literal 0x42c80000 at 0x1ca70c
 *   stack: address of the slot at 0x50 escapes at 0x1ca714
 *   fpu: float literal 0x3f800000 at 0x1ca730
 *   fpu: mov.s at 0x1ca740 is a float copy
 *   stack: address of the slot at 0x40 escapes at 0x1ca748
 *   stack: address of the slot at 0x50 escapes at 0x1ca748
 *   stack: address of the slot at 0x40 escapes at 0x1ca758
 *   v0 is the pointer held in @15264+0x6c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int __SFXMNG_HitObject_Init(void *a0 /* r4 */) {
    u8 *s2;
    u8 *s1;
    u32 v1;
    u8 *s0;
    u32 v0;
    float f12;
    float f0;
    void *a0_2;
    u8 stackFrame_60[16] __attribute__((aligned(16)));
    u8 stackFrame_50[16] __attribute__((aligned(16)));
    u8 stackFrame_40[16] __attribute__((aligned(16)));

    s2 = (u8 *)a0;
    s1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x48));
    v0 = (u32)__SFXMNG_DataAlloc(0x40);
    *(u32 *)(s2 + 0x6c) = v0;
    s0 = (u8 *)*(s32 *)(s2 + 0x6c);
    if ((u32)(s32)s0 == 0) {
        v0 = 0;
    } else {
        v0 = *(s32 *)(s2 + 0x64);
        sceVu0Normalize((void *)((u8 *)&stackFrame_60[0]), (void *)(u32)(v0 + 0x20));
        a0_2 = (void *)(s2 + 0x10);
        SfxCalc_Vector2Angle((float *)a0_2, (float *)((u8 *)&stackFrame_60[0]));
        *(u32 *)(s2 + 0x18) = 0;
        v0 = *(s32 *)(s2 + 0x64);
        sceVu0CopyVector((void *)s2, (void *)(u32)(v0 + 0x30));
        v0 = *(s32 *)s1;
        *(u32 *)(s2 + 0x70) = v0;
        v0 = *(u8 *)(s1 + 0x12);
        if (v0 != 0 && 0 <= (s32)*(s16 *)(s1 + 8)) {
            v1 = *(s32 *)(s2 + 0x64);
            f12 = 100.0f;
            sceVu0ScaleVector((void *)((u8 *)&stackFrame_50[0]), (void *)(u32)(v1 + 0x20), 100.0f);
            f0 = CheckHitMapLineGetNormal((void *)s2, (void *)((u8 *)&stackFrame_50[0]), (void
                *)(u8 *)(s0 + 0x10));
            v0 = 0x3f800000;
            if (!(1.0f == f0)) {
                sceVu0ScaleVector((void *)((u8 *)&stackFrame_40[0]), (void *)((u8
                    *)&stackFrame_50[0]), (float)f0);
                sceVu0AddVector((void *)s0, (void *)((u8 *)&stackFrame_40[0]), (void *)(u8 *)s2);
                *(u16 *)(s0 + 0x30) = 1;
            }
        }
        v0 = 1;
    }
    return v0;
}


/* __SFXMNG_HitObject_Act @ 0x1CA400 .. 0x1CA670 (0x270 bytes, frame 0xc0) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   stack: address of the slot at 0xb0 escapes at 0x1ca428
 *   stack: address of the slot at 0xa0 escapes at 0x1ca448
 *   stack: address of the slot at 0xb0 escapes at 0x1ca448
 *   stack: address of the slot at 0x70 escapes at 0x1ca478
 *   stack: address of the slot at 0x70 escapes at 0x1ca484
 *   stack: address of the slot at 0x70 escapes at 0x1ca484
 *   stack: address of the slot at 0x60 escapes at 0x1ca490
 *   stack: address of the slot at 0xa0 escapes at 0x1ca490
 *   fpu: float literal 0x00000000 at 0x1ca4a4
 *   stack: address of the slot at 0x80 escapes at 0x1ca4d8
 *   stack: address of the slot at 0x50 escapes at 0x1ca4ec
 *   stack: address of the slot at 0xb0 escapes at 0x1ca4ec
 *   fpu: float literal 0x3f800000 at 0x1ca508
 *   stack: address of the slot at 0x80 escapes at 0x1ca58c
 *   stack: 32-byte aggregate copy in 16-byte chunks at 0x1ca4d0
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int __SFXMNG_HitObject_Act(void *a0 /* r4 */) {
    u8 t3;
    u8 *a0_bytes; // s3
    u8 *s2;
    u8 t2;
    u8 *t1;
    u8 *s1;
    float f12;
    float f1;
    u32 a1;
    float f0;
    void *a0_s3; // a0
    u32 v1;
    u32 v0;
    u32 s0;
    u8 stackFrame_B0[16] __attribute__((aligned(16)));
    u8 stackFrame_A0[16] __attribute__((aligned(16)));
    u8 stackFrame_80[32] __attribute__((aligned(16)));
    u8 stackFrame_70[16] __attribute__((aligned(16)));
    u8 stackFrame_60[16] __attribute__((aligned(16)));
    u8 stackFrame_50[16] __attribute__((aligned(16)));
    struct __copy_u_long128_2 { u_long128 b[2]; };

    a0_bytes = (u8 *)a0;
    s2 = (u8 *)*(s32 *)(a0_bytes + 0x48);
    s1 = (u8 *)*(s32 *)(a0_bytes + 0x6c);
    sceVu0CopyVector((void *)((u8 *)&stackFrame_B0[0]), (void *)a0_bytes);
    v0 = *(s32 *)(a0_bytes + 0x64);
    sceVu0CopyVector((void *)a0_bytes, (void *)(u32)(v0 + 0x30));
    sceVu0SubVector((void *)((u8 *)&stackFrame_A0[0]), (void *)a0_bytes, (void *)(u8 *)((u8
        *)&stackFrame_B0[0]));
    v0 = *(s32 *)(a0_bytes + 0x74);
    if (v0 != 0) {
        v0 = *(u8 *)(s2 + 0x12);
        s0 = 0;
        if (v0 != 0) {
            v0 = *(u16 *)(s1 + 0x30);
            if (v0 != 0) {
                sceVu0SubVector((void *)((u8 *)&stackFrame_70[0]), (void *)s1, (void *)(u8
                    *)a0_bytes);
                sceVu0Normalize((void *)((u8 *)&stackFrame_70[0]), (void *)((u8
                    *)&stackFrame_70[0]));
                sceVu0Normalize((void *)((u8 *)&stackFrame_60[0]), (void *)((u8
                    *)&stackFrame_A0[0]));
                f0 = sceVu0InnerProduct((void *)((u8 *)&stackFrame_70[0]), (void *)((u8
                    *)&stackFrame_60[0]));
                f1 = 0.0f;
                if (f0 <= 0.0f) {
                    a0_s3 = (void *)((u8 *)&stackFrame_80[0]);
                    s0 = 1;
                    *(struct __copy_u_long128_2 *)((u8 *)&stackFrame_80[0]) = *(struct
                        __copy_u_long128_2 *)(s1 + 0x10);
                }
            }
        } else {
            v0 = *(s16 *)(s2 + 8);
            if (0 <= (s32)v0) {
                sceVu0SubVector((void *)((u8 *)&stackFrame_50[0]), (void *)a0_bytes, (void *)(u8
                    *)((u8 *)&stackFrame_B0[0]));
                f0 = CheckHitMapLineGetNormal((void *)((u8 *)&stackFrame_B0[0]), (void *)((u8
                    *)&stackFrame_50[0]), (void *)(u8 *)((u8 *)&stackFrame_80[0]));
                v0 = 0x3f800000;
                f1 = 1.0f;
                s0 = 1.0f != f0;
            }
        }
        if (s0 != 0) {
            v1 = ((s32 *)stackFrame_80)[4];
            a1 = 1;
            a0_s3 = (void *)(s32)a1;
            if ((u32)(v1 & 1) == 0 && (v1 & 0x40) == 0) {
                a0_s3 = (void *)0;
            }
            if ((u32)a0_s3 == 0 && (v1 & (u32)0x10000) == 0) {
                a1 = 0;
            }
            if (a1 != 0) {
                s1 = (u8 *)*(s32 *)(a0_bytes + 0x48);
                v0 = *(s16 *)(s1 + 8);
                if (0 < (s32)v0) {
                    if ((u32)((u8 *)&stackFrame_80[0]) != 0) {
                        SFX_Create_OnDir((unsigned short)(void *)(u16)v0, (float *)a0_bytes, (float
                            *)(u8 *)((u8 *)&stackFrame_80[0]));
                    } else {
                        SFX_Create_OnAng((unsigned short)(void *)(u16)v0, (float *)a0_bytes, (float
                            *)(u8 *)(a0_bytes + 0x10));
                    }
                }
                v0 = *(u8 *)(s1 + 0x11);
                if (v0 == 0) {
                    __SFXMNG_SfxDelete((void *)*(s32 *)(a0_bytes + 0x50), 0);
                }
            }
        }
        if (s0 == 0) {
            v0 = *(s16 *)(s2 + 0xa);
            if (0 <= (s32)v0) {
                t2 = *(u8 *)(a0_bytes + 0x7d);
                f12 = *(float *)(s2 + 4);
                t3 = *(u8 *)(a0_bytes + 0x7c);
                t1 = (u8 *)__SFXMNG_HitObject_EneHit_CallBack;
                SetDamageMng((void *)0, 0xff, (void *)(u8 *)a0_bytes, f12, 0, (void *)(u8
                    *)a0_bytes, __SFXMNG_HitObject_EneHit_CallBack, t2, t3);
            }
            v0 = *(s16 *)(s2 + 0xc);
            if (0 <= (s32)v0) {
                f12 = *(float *)(s2 + 4);
                t2 = *(u8 *)(a0_bytes + 0x7d);
                t3 = *(u8 *)(a0_bytes + 0x7c);
                t1 = (u8 *)__SFXMNG_HitObject_EneHit_CallBack;
                SetDamageMng((void *)0, 0xff, (void *)(u8 *)a0_bytes, f12, 1, (void *)(u8
                    *)a0_bytes, __SFXMNG_HitObject_EneHit_CallBack, t2, t3);
            }
        }
    }
    return 1;
}
static signed int __SFXMNG_HitObject_End(void *object) {
    u8 *saved = object;
    int index;
    u32 ptr = *(u32 *)(saved + 0x6c);
    if (ptr) {
        u32 manager = s_pSfxMng;
        u32 first = *(u32 *)(manager + 0x28);
        if (ptr >= first && ptr + 0x40 < first + (*(u32 *)(manager + 0x24) << 5)) {
            index = (ptr - first) >> 5;
            memset((void *)ptr, 0, 0x40);
            ((struct HitCleanupManager *)s_pSfxMng)->mask[index / 32] &= ~(1U << (31 - index % 32));
            ((struct HitCleanupManager *)s_pSfxMng)->mask[(index + 1) / 32] &= ~(1U << (31 - (index + 1) % 32));
        }
        *(u32 *)(saved + 0x6c) = 0;
    }
    return 1;
}








void __SFXMNG_HitObject_EneHit_CallBack(void *object, void *enemy) {
    u8 *savedObject;
    u8 *hit;
    s32 effect;
    hit = (u8 *)*(s32 *)((u8 *)object + 0x48);
    if (!hit) {
        u8 filename[256] __attribute__((aligned(16)));
        strcpy((char *)(u8 *)&filename[0], "SfxMng.c");
        SfxDbg_SetDebugMsg(0, "ABNORMAL HIT-CB", (char *)(u8 *)&filename[0], 0xbcf);
    } else {
        if (*(u8 *)((u8 *)enemy + 0x128) == 1) {
            effect = *(s16 *)(hit + 10);
            savedObject = (u8 *)object;
            if (0 < effect) SFX_Create_OnAng(effect, (float *)savedObject, (float *)(savedObject + 16));
            if (!hit[17]) __SFXMNG_SfxDelete((void *)*(s32 *)(savedObject + 0x50), 0);
        } else {
            effect = *(s16 *)(hit + 12);
            savedObject = (u8 *)object;
            if (0 < effect) SFX_Create_OnAng(effect, (float *)savedObject, (float *)(savedObject + 16));
            if (!hit[17]) __SFXMNG_SfxDelete((void *)*(s32 *)(savedObject + 0x50), 0);
        }
    }
}


/* __SFXMNG_Spirit_Init @ 0x1CA110 .. 0x1CA1D4 (0xc4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int __SFXMNG_Spirit_Init(void *a0 /* r4 */) {
    u8 *s0;
    u8 *s1;
    u32 v0;

    s1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x48));
    s0 = (u8 *)a0;
    v0 = (u32)__SFXMNG_DataAlloc(0x40);
    *(u32 *)(s0 + 0x60) = v0;
    v0 = *(s32 *)(s0 + 0x60);
    if (v0 == 0) {
        v0 = 0;
    } else {
        v0 = (u32)__SFXMNG_DataAlloc(0x30);
        *(u32 *)(s0 + 0x6c) = v0;
        v0 = *(s32 *)(s0 + 0x6c);
        if (v0 == 0) {
            v0 = 0;
        } else {
            v0 = *(s32 *)s1;
            *(u32 *)(s0 + 0x70) = v0;
            s1 = (u8 *)*(s32 *)(s0 + 0x6c);
            a0 = (void *)s1;
            *(u32 *)(s1 + 0x1c) = 0;
            sceVu0CopyVector(a0, (void *)(u32 *)s0);
            *(u32 *)(s1 + 0x10) = 0;
            v0 = 0x3f000000;
            *(u32 *)(s1 + 0x14) = 0;
            *(u32 *)(s1 + 0x18) = 0x3f000000;
            v0 = *(s32 *)(s0 + 0x68);
            if (v0 != 0) {
                v0 = *(s32 *)v0;
                if (v0 != 0) {
                    v0 = *(s32 *)((v0 + 0x1b8));
                    *(u32 *)(s1 + 0x20) = v0;
                }
            }
            v0 = *(s32 *)(s0 + 0x60);
            v0 = v0 != 0;
        }
    }
    return v0;
}
static signed int __SFXMNG_Spirit_Act(void *object) {
    u8 *saved;
    u8 *fix;
    u8 *data;
    float step;
    float pcpos[4] __attribute__((aligned(16)));
    float mov[4] __attribute__((aligned(16)));
    float pos[4] __attribute__((aligned(16)));
    float mrx[4][4] __attribute__((aligned(16)));
    float dist;
    saved = object;
    fix = *(u8 **)(saved + 0x48);
    data = *(u8 **)(saved + 0x6c);
    NM_GetPcHeadPos(pcpos);
    SFX_GetSeqParam(&step, 6, 1, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 4), *(u32 *)(saved + 0x74));
    dist = Math_GetDist(pcpos, (float *)saved);
    step *= 0.0166666f;
    if (dist < step) step = dist;
    if (dist < *(float *)(fix + 0xc)) {
        s32 index;
        if (0 < *(u16 *)(fix + 8)) SFX_Create_OnAng(*(u16 *)(fix + 8), (float *)saved, (float *)(saved + 0x10));
        index = saved ? ((s32)saved - *(s32 *)(s_pSfxMng + 0x10)) / 128 : 0;
        ((struct ManualSfxEntry *)(*(u32 *)(s_pSfxMng + 0x1c) + index * 8))->state = 4;
        *(s32 *)(MdlMng + 0x11920) = (s32)((float)*(s32 *)(MdlMng + 0x11920) + 0.25f * (float)*(s32 *)(data + 0x20));
        return 1;
    }
    sceVu0SubVector(mov, pcpos, data);
    sceVu0Normalize(mov, mov);
    sceVu0ScaleVector(mov, mov, step);
    sceVu0AddVector(data, data, mov);
    dist = Math_GetDist((float *)data, pcpos) / 5.0f;
    if (0.5f < dist) dist = 0.5f;
    {
        float t;
        float a = *(float *)(data + 0x10);
        float r;
        t = 3.1415927f + a;
        if (t >= 0.0f) r = a - 6.2831855f * (float)(s32)(t / 6.2831855f);
        else r = 6.2831855f + (a - 6.2831855f * (float)(s32)(t / 6.2831855f));
        sceVu0RotMatrixX(mrx, MRX1, r);
    }
    {
        float t;
        float a = *(float *)(data + 0x14);
        float r;
        t = 3.1415927f + a;
        if (t >= 0.0f) r = a - 6.2831855f * (float)(s32)(t / 6.2831855f);
        else r = 6.2831855f + (a - 6.2831855f * (float)(s32)(t / 6.2831855f));
        sceVu0RotMatrixY(mrx, mrx, r);
    }
    {
        float vec[4] __attribute__((aligned(16))) = {0};
        vec[2] = dist;
        sceVu0ApplyMatrix(pos, mrx, vec);
    }
    sceVu0AddVector(pos, data, pos);
    sceVu0CopyVector(saved, pos);
    fix = *(u8 **)(saved + 0x60);
    SfxCalc_MakeMatrixFromPYR(fix, *(float *)(saved + 0x10), *(float *)(saved + 0x14), *(float *)(saved + 0x18));
    sceVu0CopyVector(fix + 0x30, pos);
    *(float *)(data + 0x1c) = *(float *)(data + 0x1c) + 0.0166666f;
    *(float *)(data + 0x10) = *(float *)(data + 0x10) + 0.10471934f * param1_1948[0];
    *(float *)(data + 0x14) = *(float *)(data + 0x14) + 0.10471934f * param2_1949[0];
    return 1;
}


static signed int __SFXMNG_Spirit_End(void *object) {
    u8 *saved = object;
    int index;
    u32 ptr = *(u32 *)(saved + 0x6c);
    if (ptr) {
        u32 manager = s_pSfxMng;
        u32 first = *(u32 *)(manager + 0x28);
        if (ptr >= first && ptr + 0x40 < first + (*(u32 *)(manager + 0x24) << 5)) {
            index = (ptr - first) >> 5;
            memset((void *)ptr, 0, 0x40);
            ((struct HitCleanupManager *)s_pSfxMng)->mask[index / 32] &= ~(1U << (31 - index % 32));
            ((struct HitCleanupManager *)s_pSfxMng)->mask[(index + 1) / 32] &= ~(1U << (31 - (index + 1) % 32));
        }
        *(u32 *)(saved + 0x6c) = 0;
    }
    return 1;
}


/* __SFXMNG_SE_Init @ 0x1C9BE0 .. 0x1C9C40 (0x60 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   v0 is the pointer held in @12556+0x6c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */





static signed int __SFXMNG_SE_Init(void *a0 /* r4 */) {
    u8 *s0;
    u32 v0;
    u8 *a0_2;

    s0 = (u8 *)a0;
    v0 = (u32)__SFXMNG_DataAlloc(8);
    *(u32 *)(s0 + 0x6c) = v0;
    a0_2 = (u8 *)*(s32 *)(s0 + 0x6c);
    if ((u32)(s32)a0_2 == 0) {
        return 0;
    }
    v0 = 0x7fff0000;
    *(u32 *)(s0 + 0x70) = 0x7fff0000 | 0xffff;
    *(u32 *)a0_2 = 0x50;
    *(u32 *)(a0_2 + 4) = -1;
    return 1;
}
static signed int __SFXMNG_SE_Act(void *a0 /* r4 */) {
    u8 *saved;
    u8 *params;
    u8 *data;
    u32 interval;
    u32 cnt;
    s32 handle;
    s16 volOfs;
    s16 pan;
    float r;
    u32 run;

    saved = (u8 *)a0;
    params = *(u8 **)(saved + 0x48);
    data = *(u8 **)(saved + 0x6c);
    interval = (u32)(60.0f * *(float *)(params + 0x10));
    if (*(u8 *)(params + DCOMP_OFF_STRUCT_DW_2103726_FIELDS__10__CDUMMY_C6675C35) != 0) {
        run = !(((struct dw_2095879 *)(saved + 0x7e))->f_disable_act || ((struct dw_2095879 *)(saved + 0x7e))->f_disable_act_by_map);
    } else {
        run = 1;
    }
    if (run) {
        cnt = *(u32 *)(saved + DCOMP_OFF_STRUCT_DW_2094394_FIELDS_CNT_23AE2C16);
        if (*(u32 *)(data + 4) != cnt) {
            handle = *(s32 *)data;
            if (handle == 0x50 || (interval != 0 && cnt % interval == 0)) {
                if (handle <= 0x4f) {
                    SND_Stop(handle);
                }
                r = 1.5259022e-05f * (float)(u32)(u16)SfxCalc_RandU32();
                volOfs = (s32)((float)(u32)*(u16 *)(params + 4) * (r - 0.5f));
                r = 1.5259022e-05f * (float)(u32)(u16)SfxCalc_RandU32();
                pan = *(s16 *)(params + 6) + (s16)(s32)((float)(u32)*(u16 *)(params + 8) * (r - 0.5f));
                *(u32 *)data = SND_Play3D(*(u16 *)params, *(u16 *)(params + 2) + volOfs, pan,
                    (void *)(*(u32 *)(saved + 0x64) + 0x30), *(float *)(params + 0xc));
                *(u32 *)(data + 4) = *(u32 *)(saved + DCOMP_OFF_STRUCT_DW_2094394_FIELDS_CNT_23AE2C16);
            }
        }
    } else {
        handle = *(s32 *)data;
        if (handle <= 0x4f) {
            SND_Stop(handle);
            *(u32 *)data = 0x50;
        }
    }
    return 1;
}


/* __SFXMNG_SE_End @ 0x1C9840 .. 0x1C9920 (0xe0 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




static signed int __SFXMNG_SE_End(void *a0 /* r4 */) {
    u8 *s1;
    u32 a1;
    u32 v1;
    u32 v0;
    s32 s0;

    v0 = *(s32 *)(((u8 *)a0 + 0x6c));
    s1 = (u8 *)a0;
    if (v0 != 0) {
        a0 = (void *)*(s32 *)v0;
        SND_Stop((signed int)a0);
        v1 = s_pSfxMng;
        a0 = (void *)*(s32 *)(s1 + 0x6c);
        a1 = *(s32 *)((v1 + 0x28));
        if ((u32)((u32)(s32)a0 < a1) == 0) {
            if ((u32)(s32)((u8 *)a0 + 0x20) < (u32)(a1 + (s32)((u32)*(s32 *)((v1 + 0x24)) << 5))) {
                s0 = (u32)(s32)((u8 *)a0 - a1) >> 5;
                memset(a0, 0, 0x20);
                a0 = (void *)s_pSfxMng;
                v1 = *(s32 *)(((u8 *)a0 + 0x2c)) + (s32)((u32)(s0 / (s32)(0x20)) << 2);
                *(u32 *)v1 &= ~(u32)((u32)1 << (u32)(s32)((u8 *)(s32)0x1f - (u32)(s0 %
                    (s32)(0x20))));
            }
        }
        *(u32 *)(s1 + 0x6c) = 0;
    }
    return 1;
}


/* __SFXMNG_PLight_Init @ 0x1C9710 .. 0x1C9840 (0x130 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1c9754
 *   fpu: mtc1 reinterprets v0 at 0x1c978c
 *   fpu: mtc1 reinterprets v1 at 0x1c97a0
 *   fpu: float literal 0x3c888865 at 0x1c97bc
 *   fpu: float literal 0x3f000000 at 0x1c97f0
 *   fpu: mov.s at 0x1c97f8 is a float copy
 *   v0 is the pointer held in @11324+0x6c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int __SFXMNG_PLight_Init(void *a0 /* r4 */) {
    u8 *s2;
    u16 a0_narrow; // a0
    u8 *s1;
    u16 *s0;
    float f12;
    float f0;
    u16 a0_narrow_; // a0
    u16 a0_narrow__; // a0
    u16 a0_narrow___; // a0
    u16 a0_narrow____; // a0
    u32 v0;

    s2 = (u8 *)a0;
    v0 = (u32)__SFXMNG_DataAlloc(0x10);
    *(u32 *)(s2 + 0x6c) = v0;
    s0 = (u16 *)*(s32 *)(s2 + 0x6c);
    if ((u32)(s32)s0 == 0) {
        v0 = 0;
    } else {
        s1 = (u8 *)*(s32 *)(s2 + 0x48);
        v0 = 0x7fffffff;
        f12 = 0.0f;
        *(u32 *)(s2 + 0x70) = 0x7fffffff;
        v0 = SfxPLight_Create(0.0f);
        *(u16 *)s0 = v0;
        v0 = *(u16 *)(s1 + 2);
        if (0 < (s32)v0) {
            a0_narrow = *(u16 *)s0;
            SfxPLight_EnableBlink(a0_narrow, 1);
            v0 = *(u16 *)(s1 + 2);
            a0_narrow_ = *(u16 *)s0;
            f0 = 0.0166666005f;
            SfxPLight_SetBlink(a0_narrow_, (0.0166666005f * (float)(float)v0), *(float *)(s1 + 4));
        }
        v0 = *(s8 *)(s1 + 8);
        if (v0 != 0) {
            a0_narrow__ = *(u16 *)s0;
            SfxPLight_EnableWindEffect(a0_narrow__, 1);
            a0_narrow___ = *(u16 *)s0;
            f12 = 0.5f;
            SfxPLight_SetWindParam(a0_narrow___, 0.5f, (float)0.5f);
        }
        v0 = *(s8 *)(s1 + 9);
        if (v0 != 0) {
            a0_narrow____ = *(u16 *)s0;
            SfxPLight_EnableShadow(a0_narrow____, (u32)(v0 != 0) ^ 1);
        }
        v0 = 1;
    }
    return v0;
}
static signed int __SFXMNG_PLight_Act(void *a0 /* r4 */) {
    u8 *saved;
    u16 *data;
    u32 cnt;
    float radius;
    u8 rgb[3];
    float col[4] __attribute__((aligned(16)));

    saved = (u8 *)a0;
    data = *(u16 **)(saved + 0x6c);
    if (data[0] != 0xffff) {
        cnt = *(u32 *)(saved + DCOMP_OFF_STRUCT_DW_2094394_FIELDS_CNT_23AE2C16);
        if (((struct dw_2095879 *)(saved + 0x7e))->f_disable_draw || ((struct dw_2095879 *)(saved + 0x7e))->f_disable_draw_by_map) {
            SfxPLight_Enable(data[0], 0);
        } else {
            SfxPLight_Enable(data[0], 1);
        }
        SfxPLight_SetPos(data[0], (float *)(*(u32 *)(saved + 0x64) + 0x30));
        SFX_GetSeqParam(&radius, 6, 1, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 4), cnt);
        SfxPLight_SetRadius(data[0], radius);
        SFX_GetSeqParam(rgb, 1, 3, (void *)*(u32 *)(*(u32 *)(saved + 0x4c) + 0xc), cnt);
        col[0] = (float)rgb[0] / 255.0f;
        col[1] = (float)rgb[1] / 255.0f;
        col[2] = (float)rgb[2] / 255.0f;
        col[3] = 1.0f;
        SfxPLight_SetColor(data[0], col);
    }
    return 1;
}








/* __SFXMNG_PLight_End @ 0x1C9410 .. 0x1C9540 (0x130 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x1c9448
 *   fpu: mtc1 reinterprets v1 at 0x1c9460
 *   fpu: float literal 0x3c888865 at 0x1c9478
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




static signed int __SFXMNG_PLight_End(void *a0 /* r4 */) {
    u8 *s1;
    u32 a1;
    u16 a0_narrow; // a0
    float f0;
    u32 v1;
    s32 s0;
    u32 v0;
    void *a0_2;

    v0 = *(s32 *)(((u8 *)a0 + 0x6c));
    s1 = (u8 *)a0;
    if (v0 != 0) {
        a0_narrow = *(u16 *)v0;
        v0 = 0xffff;
        v1 = *(s32 *)(s1 + 0x48);
        if ((u32)a0_narrow != v0) {
            v0 = *(u16 *)v1;
            f0 = 0.0166666005f;
            SfxPLight_Delete(a0_narrow, (0.0166666005f * (float)(float)v0));
        }
        v1 = s_pSfxMng;
        a0_2 = (void *)*(s32 *)(s1 + 0x6c);
        a1 = *(s32 *)((v1 + 0x28));
        v0 = (u32)(s32)a0_2 < a1;
        if (v0 == 0) {
            v0 = (u32)*(s32 *)((v1 + 0x24)) << 5;
            v1 = (s32)((u8 *)a0_2 + 0x20);
            if (v1 < (u32)(a1 + v0)) {
                s0 = (u32)(s32)((u8 *)a0_2 - a1) >> 5;
                memset(a0_2, 0, 0x20);
                v1 = *(s32 *)(((u8 *)s_pSfxMng + 0x2c)) + (s32)((u32)(s0 / (s32)(0x20)) << 2);
                *(u32 *)v1 &= ~(s32)((u32)1 << (u32)(s32)((u8 *)(s32)0x1f - (u32)(s0 %
                    (s32)(0x20))));
            }
        }
        *(u32 *)(s1 + 0x6c) = 0;
    }
    return 1;
}
static signed int __SFXMNG_Karyu_Init(void *a0 /* r4 */) {
    u8 *saved;
    u8 *params;
    u8 *data;
    float pitch;
    float rnd;
    float ang;

    saved = (u8 *)a0;
    params = *(u8 **)(saved + DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214);
    *(u32 *)(saved + 0x60) = (u32)__SFXMNG_DataAlloc(0x40);
    if (*(u32 *)(saved + 0x60) == 0) return 0;
    *(u32 *)(saved + 0x6c) = (u32)__SFXMNG_DataAlloc(0x30);
    if (*(u32 *)(saved + 0x6c) == 0) return 0;
    *(u32 *)(saved + 0x70) = *(u32 *)(params + 4);
    data = *(u8 **)(saved + 0x6c);
    *(u32 *)(data + 0x20) = 0;
    *(u32 *)(data + 0x24) = 0;
    if (*(u8 *)(params + DCOMP_OFF_STRUCT_DW_2103726_FIELDS_CDUMMY_C7F5C357) != 0) {
        *(u16 *)(data + 0x28) = 0;
    } else {
        *(u16 *)(data + 0x28) = 1;
    }
    sceVu0CopyMatrix((void *)*(u32 *)(saved + 0x60), (void *)(*(u32 *)(saved + 0x64) + 0x30));
    *(u32 *)(data + 0x24) = (u32)SfxUtil_FindChar_Sphere(!(*(u8 *)(params + DCOMP_OFF_STRUCT_DW_2103726_FIELDS__1__CDUMMY_804D1605) != 0), (float *)saved, 20.0f, 1);
    rnd = 1.5259022e-05f * (float)(u32)(u16)SfxCalc_RandU32();
    ang = *(float *)(saved + 0x10);
    pitch = ang + 0.17449999f * (rnd - 0.5f);
    rnd = 1.5259022e-05f * (float)(u32)(u16)SfxCalc_RandU32();
    SfxCalc_MakeMatrixFromPYR((void *)*(u32 *)(saved + 0x60), pitch, *(float *)(saved + 0x14) + 0.17449999f * (rnd - 0.5f), *(float *)(saved + 0x18));
    SfxCalc_QtnMakeFromMatrix((float *)data, (void *)*(u32 *)(saved + 0x60));
    if (*(u8 *)(params + DCOMP_OFF_STRUCT_DW_2103726_FIELDS_CDUMMY_C7F5C357) != 0) {
        float down[4] __attribute__((aligned(16))) = {0.0f, -1.0f, 0.0f, 0.0f};
        sceVu0CopyVector(data + 0x10, down);
    } else {
        float fwd[4] __attribute__((aligned(16))) = {0.0f, 0.0f, 2.0f, 0.0f};
        sceVu0ApplyMatrix(data + 0x10, (void *)*(u32 *)(saved + 0x60), fwd);
    }
    sceVu0CopyVector((void *)(*(u32 *)(saved + 0x60) + 0x30), (void *)saved);
    return *(u32 *)(saved + 0x60) != 0;
}
static signed int __SFXMNG_Karyu_Act(void *object) {
    u8 *saved;
    u8 *params;
    u8 *state;
    float matrix[4][4] __attribute__((aligned(16)));
    float position[4] __attribute__((aligned(16)));
    float acceleration[4] __attribute__((aligned(16)));
    float drag[4] __attribute__((aligned(16)));
    float delta[4] __attribute__((aligned(16)));
    float targetPos[4] __attribute__((aligned(16)));
    float direction[4] __attribute__((aligned(16)));
    float rotation[4] __attribute__((aligned(16)));
    saved = object;
    state = *(u8 **)((u8 *)object + 0x6c);
    params = *(u8 **)((u8 *)object + 0x48);
    SfxCalc_MakeMatrixFromQtn(matrix, (float *)state);
    sceVu0CopyVector(position, (void *)(*(u32 *)(saved + 0x60) + 0x30));
    if (*(u32 *)(state + 0x24) == 0) *(u32 *)(state + 0x24) = (u32)SfxUtil_FindChar_Sphere(!params[1], (float *)saved, 20.0f, 1);
    switch (*(u16 *)(state + 0x28)) {
    case 0:
        if (1.0f < *(float *)(state + 0x20)) (*(u16 *)(state + 0x28))++;
        break;
    case 1:
        sceVu0ScaleVector(drag, state + 0x10, -0.008333334f);
        sceVu0AddVector(state + 0x10, state + 0x10, drag);
        sceVu0ScaleVector(acceleration, matrix[2], 0.0166666f * *(float *)(params + 8));
        sceVu0AddVector(state + 0x10, state + 0x10, acceleration);
        if ((float)*(u32 *)(params + 4) < *(float *)(state + 0x20)) *(u32 *)(saved + 0x70) = 0;
    }
    if (*(float *)(params + 0xc) < sqrtf(sceVu0InnerProduct(state + 0x10, state + 0x10))) {
        sceVu0Normalize(state + 0x10, state + 0x10);
        sceVu0ScaleVector(state + 0x10, state + 0x10, *(float *)(params + 0xc));
    }
    sceVu0ScaleVector(delta, state + 0x10, 0.0166666f);
    sceVu0AddVector(position, delta, position);
    {
        u8 *target = *(u8 **)(state + 0x24);
        if (target) {
            float height[4] __attribute__((aligned(16))) = {0};
            height[1] = 0.5f * *(float *)(target + 0x114);
            sceVu0SubVector(targetPos, target + 0x20, height);
            sceVu0SubVector(direction, targetPos, (void *)(*(u32 *)(saved + 0x60) + 0x30));
            sceVu0Normalize(direction, direction);
            SfxCalc_QtnMakeFromDir(rotation, direction);
            SfxCalc_QtnSLerp((float *)state, (float *)state, rotation, 1.0f);
        }
    }
    SfxCalc_MakeMatrixFromQtn(*(void **)(saved + 0x60), (float *)state);
    sceVu0CopyVector((void *)(*(u32 *)(saved + 0x60) + 0x30), position);
    *(float *)(state + 0x20) += 0.0166666f;
    return 1;
}








static signed int __SFXMNG_Karyu_End(void *object) {
    u8 *saved = object;
    int index;
    u32 ptr = *(u32 *)(saved + 0x6c);
    if (ptr) {
        u32 manager = s_pSfxMng;
        u32 first = *(u32 *)(manager + 0x28);
        if (ptr >= first && ptr + 0x40 < first + (*(u32 *)(manager + 0x24) << 5)) {
            index = (ptr - first) >> 5;
            memset((void *)ptr, 0, 0x40);
            ((struct HitCleanupManager *)s_pSfxMng)->mask[index / 32] &= ~(1U << (31 - index % 32));
            ((struct HitCleanupManager *)s_pSfxMng)->mask[(index + 1) / 32] &= ~(1U << (31 - (index + 1) % 32));
        }
        *(u32 *)(saved + 0x6c) = 0;
    }
    return 1;
}
static signed int __SFXMNG_WolfCard_Init(void *a0 /* r4 */) {
    u8 *saved;
    u8 *data;
    float pitch;
    float rnd;
    float ang;

    saved = (u8 *)a0;
    *(u32 *)(saved + 0x60) = (u32)__SFXMNG_DataAlloc(0x40);
    if (*(u32 *)(saved + 0x60) == 0) return 0;
    *(u32 *)(saved + 0x6c) = (u32)__SFXMNG_DataAlloc(0x30);
    if (*(u32 *)(saved + 0x6c) == 0) return 0;
    *(u32 *)(saved + 0x70) = 0x7fffffff;
    data = *(u8 **)(saved + 0x6c);
    *(u32 *)(data + 0x20) = 0;
    *(u32 *)(data + 0x24) = 0;
    *(u16 *)(data + 0x28) = 0;
    sceVu0CopyMatrix((void *)*(u32 *)(saved + 0x60), (void *)(*(u32 *)(saved + 0x64) + 0x30));
    *(u32 *)(data + 0x24) = (u32)SfxUtil_FindChar_Sphere(1, (float *)saved, 20.0f, 1);
    rnd = 1.5259022e-05f * (float)(u32)(u16)SfxCalc_RandU32();
    ang = *(float *)(saved + 0x10);
    pitch = ang + 0.17449999f * (rnd - 0.5f);
    rnd = 1.5259022e-05f * (float)(u32)(u16)SfxCalc_RandU32();
    SfxCalc_MakeMatrixFromPYR((void *)*(u32 *)(saved + 0x60), pitch, *(float *)(saved + 0x14) + 0.17449999f * (rnd - 0.5f), *(float *)(saved + 0x18));
    SfxCalc_QtnMakeFromMatrix((float *)data, (void *)*(u32 *)(saved + 0x60));
    {
        float down[4] __attribute__((aligned(16))) = {0.0f, -1.0f, 0.0f, 0.0f};
        sceVu0CopyVector(data + 0x10, down);
    }
    sceVu0CopyVector((void *)(*(u32 *)(saved + 0x60) + 0x30), (void *)saved);
    return *(u32 *)(saved + 0x60) != 0;
}
static signed int __SFXMNG_WolfCard_Act(void *object) {
    u8 *saved;
    u8 *params;
    u8 *state;
    float mRot[4][4] __attribute__((aligned(16)));
    float vPos[4] __attribute__((aligned(16)));
    float dv[4] __attribute__((aligned(16)));
    float vt[4] __attribute__((aligned(16)));
    float vTgtPos[4] __attribute__((aligned(16)));
    float vDir[4] __attribute__((aligned(16)));
    float qToTgt[4] __attribute__((aligned(16)));
    saved = object;
    state = *(u8 **)((u8 *)object + 0x6c);
    params = *(u8 **)((u8 *)object + 0x48);
    SfxCalc_MakeMatrixFromQtn(mRot, (float *)state);
    sceVu0CopyVector(vPos, (void *)(*(u32 *)(saved + 0x60) + 0x30));
    if (*(u32 *)(state + 0x24) == 0) *(u32 *)(state + 0x24) = (u32)SfxUtil_FindChar_Sphere(1, (float *)saved, 20.0f, 1);
    switch (*(u16 *)(state + 0x28)) {
    case 0:
        if (*(u32 *)(params + 4) < *(u32 *)(state + 0x20)) {
            *(u32 *)(state + 0x20) = 0;
            (*(u16 *)(state + 0x28))++;
        }
        break;
    case 1:
        sceVu0ScaleVector(dv, mRot[2], 0.0166666f * *(float *)(params + 8));
        sceVu0AddVector(state + 0x10, state + 0x10, dv);
        if (*(u32 *)params < *(u32 *)(state + 0x20)) {
            __SFXMNG_SfxDelete(saved, 0);
            return 0;
        }
    }
    if (*(float *)(params + 0xc) < sqrtf(sceVu0InnerProduct(state + 0x10, state + 0x10))) {
        sceVu0Normalize(state + 0x10, state + 0x10);
        sceVu0ScaleVector(state + 0x10, state + 0x10, *(float *)(params + 0xc));
    }
    sceVu0ScaleVector(vt, state + 0x10, 0.0166666f);
    sceVu0AddVector(vPos, vt, vPos);
    {
        u8 *target = *(u8 **)(state + 0x24);
        if (target) {
            float height[4] __attribute__((aligned(16))) = {0};
            height[1] = 0.5f * *(float *)(target + 0x114);
            sceVu0SubVector(vTgtPos, target + 0x20, height);
            sceVu0SubVector(vDir, vTgtPos, (void *)(*(u32 *)(saved + 0x60) + 0x30));
            sceVu0Normalize(vDir, vDir);
            SfxCalc_QtnMakeFromDir(qToTgt, vDir);
            SfxCalc_QtnSLerp((float *)state, (float *)state, qToTgt, 1.0f);
        }
    }
    SfxCalc_MakeMatrixFromQtn(*(void **)(saved + 0x60), (float *)state);
    sceVu0CopyVector((void *)(*(u32 *)(saved + 0x60) + 0x30), vPos);
    (*(u32 *)(state + 0x20))++;
    return 1;
}


static signed int __SFXMNG_WolfCard_End(void *a0 /* r4 */) {
    u8 *s1;
    u32 a1;
    u32 v1;
    s32 s0;
    u32 a2;

    s1 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x6c));
    if ((u32)(s32)a0 != 0) {
        v1 = s_pSfxMng;
        a1 = *(s32 *)((v1 + 0x28));
        if ((u32)((u32)(s32)a0 < a1) == 0) {
            if ((u32)(s32)((u8 *)a0 + 0x40) < (u32)(a1 + (s32)((u32)*(s32 *)((v1 + 0x24)) << 5))) {
                s0 = (u32)(s32)((u8 *)a0 - a1) >> 5;
                memset(a0, 0, 0x40);
                *(u32 *)(*(s32 *)((u8 *)s_pSfxMng + 0x2c) + (s32)((u32)(s0 / (s32)(0x20)) << 2)) &= ~(u32)((u32)1 << (u32)(0x1f - (u32)(s0 % (s32)(0x20))));
                *(u32 *)(*(s32 *)((u8 *)s_pSfxMng + 0x2c) + (s32)((u32)((s0 + 1) / (s32)(0x20)) << 2)) &= ~(u32)((u32)1 << (u32)(0x1f - (u32)((s0 + 1) % (s32)(0x20))));
            }
        }
        *(u32 *)(s1 + 0x6c) = 0;
    }
    return 1;
}


/* __SFXMNG_CameraVib_Init @ 0x1C8820 .. 0x1C888C (0x6c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3c8ef34d at 0x1c8834
 *   stack: address of the slot at 0x20 escapes at 0x1c8864
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int __SFXMNG_CameraVib_Init(void *a0 /* r4 */) {
    u8 *s0;
    u8 stackFrame_20[16] __attribute__((aligned(16)));

    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x48));
    a0 = (void *)((u8 *)&stackFrame_20[0]);
    *(f32 *)((u8 *)&stackFrame_20[0]) = (0.0174499992f * *(float *)s0);
    ((f32 *)stackFrame_20)[1] = (0.0174499992f * *(float *)(s0 + 4));
    ((f32 *)stackFrame_20)[2] = *(float *)(s0 + 8);
    ((f32 *)stackFrame_20)[3] = *(float *)(s0 + 0xc);
    SetCamVibration(a0);
    StartCamVibration(*(float *)(s0 + 0x10), 2);
    return 1;
}


/* __SFXMNG_CameraVib_Act @ 0x1C8810 .. 0x1C8818 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x1c8814 computes the return value
 *   a0 typed from the __SFXMNG_CameraVib_Act call table
 */





static u32 __SFXMNG_CameraVib_Act(u32 *a0 /* r4 */) {
    return 1;
}
static inline void dcomp_cop2_5499821473(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf16,0(%1)\nlqc2 vf17,0(%2)\nvopmula.xyz ACC,vf16,vf17\nvopmsub.xyz vf16,vf17,vf16\nsqc2 vf16,0(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}


static signed int __SFXMNG_Ground_Init(void *a0 /* r4 */) {
    u8 *s0;
    u8 *s1;
    u32 a1;
    u32 v1;
    float f12;
    float f0;
    u32 v0;
    u8 stackFrame_100[256] __attribute__((aligned(16)));
    u8 stackFrame_F0[16] __attribute__((aligned(16)));
    u8 stackFrame_E0[16] __attribute__((aligned(16)));
    u8 stackFrame_D0[16] __attribute__((aligned(16)));
    u8 stackFrame_C0[16] __attribute__((aligned(16)));
    u8 stackFrame_80[64] __attribute__((aligned(16)));
    u8 stackFrame_70[16] __attribute__((aligned(16)));
    u8 stackFrame_30[64] __attribute__((aligned(16)));

    s1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x48));
    s0 = (u8 *)a0;
    v0 = (u32)__SFXMNG_DataAlloc(0x40);
    *(u32 *)(s0 + 0x60) = v0;
    v0 = *(s32 *)(s0 + 0x60);
    if (v0 == 0) {
        a1 = (u32)"SfxMng.c";
        strcpy((char *)((u8 *)&stackFrame_100[0]), (const char *)"SfxMng.c");
        a1 = (u32)"Failed to alloc matrix.";
        SfxDbg_SetDebugMsg(0, "Failed to alloc matrix.", (char *)(u8 *)((u8 *)&stackFrame_100[0]),
            0xff5);
    }
    v0 = *(s32 *)(s0 + 0x60);
    if (v0 == 0) {
        return 0;
    }
    v0 = (u32)__SFXMNG_DataAlloc(1);
    *(u32 *)(s0 + 0x6c) = v0;
    v0 = *(s32 *)(s0 + 0x6c);
    if (v0 == 0) {
        v0 = 0;
    } else {
        v0 = *(s32 *)s1;
        *(u32 *)(s0 + 0x70) = v0;
        *(f32 *)s0 = (*(float *)s0 + (float)*(float *)(s1 + 4));
        *(f32 *)(s0 + 4) = (*(float *)(s0 + 4) + (float)*(float *)(s1 + 8));
        *(f32 *)(s0 + 8) = (*(float *)(s0 + 8) + (float)*(float *)(s1 + 0xc));
        a1 = *(s32 *)(s0 + 0x64);
        if (a1 != 0) {
            sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_F0[0]), (void *)a1, (void *)(u8 *)s0);
        } else {
            sceVu0CopyVector((void *)((u8 *)&stackFrame_F0[0]), (void *)s0);
        }
        f0 = 1.0f;
        f12 = 10.0f;
        a1 = (u32)VY;
        ((f32 *)stackFrame_F0)[1] = (((float *)stackFrame_F0)[1] - 1.0f);
        sceVu0ScaleVector((void *)((u8 *)&stackFrame_E0[0]), (void *)VY, 10.0f);
        v0 = SfxUtil_HitCheck_Line_Map((float *)((u8 *)&stackFrame_F0[0]), (float *)((u8
            *)&stackFrame_E0[0]), (void *)(u8 *)((u8 *)&stackFrame_C0[0]), (void *)((u8
            *)&stackFrame_D0[0]), (unsigned int *)0);
        if (v0 != 0) {
            v0 = (u32)VX;
            v1 = (u32)((u8 *)&stackFrame_70[0]);
            dcomp_cop2_5499821473((void *)(&stackFrame_70[0]), (void *)((u8 *)((u8
                *)&stackFrame_D0[0])), (void *)((u8 *)v0));
            v0 = (u32)((u8 *)&stackFrame_80[0]);
            dcomp_cop2_5499821473((void *)(&stackFrame_80[0]), (void *)(&stackFrame_70[0]), (void
                *)((u8 *)((u8 *)&stackFrame_D0[0])));
            f12 = -1.0f;
            sceVu0ScaleVector((void *)((u8 *)&stackFrame_80[16]), (void *)((u8
                *)&stackFrame_D0[0]), -1.0f);
            sceVu0CopyVector((void *)((u8 *)&stackFrame_80[32]), (void *)((u8 *)&stackFrame_70[0]));
            a1 = *(s32 *)(s0 + 0x64);
            if (a1 != 0) {
                sceVu0InversMatrix((void *)((u8 *)&stackFrame_30[0]), (void *)a1);
                v1 = (u32)((u8 *)&stackFrame_80[0]);
                v0 = (u32)((u8 *)&stackFrame_30[0]);
                dcomp_cop2_9397A3F6B7((void *)(&stackFrame_80[0]), (void *)(&stackFrame_30[0]),
                    (void *)(&stackFrame_80[0]));
                a1 = (u32)VW;
                sceVu0CopyVector((void *)((u8 *)&stackFrame_80[48]), (void *)VW);
            }
            SfxCalc_PYRfromRotMatrix((void *)((u8 *)&stackFrame_80[0]), (float *)(s0 + 0x10), (float *)(s0 + 0x14), (float *)(s0 + 0x18));
            *(u32 *)(s0 + 0x1c) = 0;
        }
        v0 = 1;
    }
    return v0;
}


static signed int __SFXMNG_Ground_Act(void *a0 /* r4 */) {
    u8 *s0;
    u32 t0;
    u32 s1;
    u8 *v1;
    float *s2;
    u8 *v0;
    u8 stackFrame_40[24] __attribute__((aligned(16)));

    s0 = (u8 *)a0;
    s1 = *(s32 *)(((u8 *)a0 + 0x74));
    SFX_GetSeqParam((void *)((u8 *)&stackFrame_40[0]), 6, 2, (void *)*(s32 *)(((u8 *)*(s32 *)(((u8
        *)a0 + 0x4c)) + 4)), s1);
    s2 = (float *)((u8 *)&stackFrame_40[0] + 0x8);
    SFX_GetSeqParam((void *)((u8 *)&stackFrame_40[0] + 0x8), 6, 2, (void *)*(s32 *)(((u8 *)*(s32
        *)(s0 + 0x4c) + 0xc)), s1);
    t0 = s1;
    s1 = (u32)((u8 *)&stackFrame_40[0] + 0x10);
    SFX_GetSeqParam((void *)((u8 *)&stackFrame_40[0] + 0x10), 6, 2, (void *)*(s32 *)(((u8 *)*(s32
        *)(s0 + 0x4c) + 0x14)), t0);
    *(f32 *)(s0 + 0x20) = *(float *)((u8 *)&stackFrame_40[0]);
    *(f32 *)(s0 + 0x24) = ((float *)stackFrame_40)[2];
    *(f32 *)(s0 + 0x28) = ((float *)stackFrame_40)[4];
    SfxCalc_MakeRotTransMatrix_I((void *)*(s32 *)(s0 + 0x60), (float *)s0, (float *)(s0 + 0x10),
        (float *)(s0 + 0x20));
    v1 = (u8 *)*(s32 *)(s0 + 0x64);
    if ((u32)(s32)v1 != 0) {
        v0 = (u8 *)*(s32 *)(s0 + 0x60);
        dcomp_cop2_9397A3F6B7((void *)((u8 *)v0), (void *)((u8 *)v1), (void *)((u8 *)v0));
    }
    return (signed int)(u8 *)(s32)1;
}


/* __SFXMNG_Ground_End @ 0x1C8370 .. 0x1C8448 (0xd8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */







static signed int __SFXMNG_Ground_End(void *a0 /* r4 */) {
    u8 *s1;
    u32 a1;
    u32 v1;
    s32 s0;

    s1 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x6c));
    if ((u32)(s32)a0 != 0) {
        v1 = s_pSfxMng;
        a1 = *(s32 *)((v1 + 0x28));
        if ((u32)((u32)(s32)a0 < a1) == 0) {
            if ((u32)(s32)((u8 *)a0 + 0x20) < (u32)(a1 + (s32)((u32)*(s32 *)((v1 + 0x24)) << 5))) {
                s0 = (u32)(s32)((u8 *)a0 - a1) >> 5;
                memset(a0, 0, 0x20);
                a0 = (void *)s_pSfxMng;
                v1 = *(s32 *)(((u8 *)a0 + 0x2c)) + (s32)((u32)(s0 / (s32)(0x20)) << 2);
                *(u32 *)v1 &= ~(u32)((u32)1 << (u32)(s32)((u8 *)(s32)0x1f - (u32)(s0 %
                    (s32)(0x20))));
            }
        }
        *(u32 *)(s1 + 0x6c) = 0;
    }
    return 1;
}


/* __SFXMNG_EventCall_Init @ 0x1C82E0 .. 0x1C836C (0x8c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x20 escapes at 0x1c8314
 *   stack: address of the slot at 0x20 escapes at 0x1c832c
 *   stack: address of the slot at 0x20 escapes at 0x1c8338
 *   fpu: float literal 0x3f800000 at 0x1c834c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int __SFXMNG_EventCall_Init(void *a0 /* r4 */) {
    u8 *s0;
    u32 a1;
    u32 v0;
    float f12;
    void *a0_2;
    u8 stackFrame_20[16] __attribute__((aligned(16)));

    v0 = *(s32 *)(((u8 *)a0 + 0x48));
    v0 = *(u8 *)v0;
    s0 = (u8 *)a0;
    switch (v0) {
    case 0:
        a1 = *(s32 *)(s0 + 0x64);
        if (a1 != 0) {
            sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_20[0]), (void *)a1, (void *)(u8 *)s0);
        } else {
            a1 = (u32)s0;
            sceVu0CopyVector((void *)((u8 *)&stackFrame_20[0]), (void *)a1);
        }
        SfxDomanString_SetPos((float *)((u8 *)&stackFrame_20[0]));
        SfxDomanString_SetAzim(*(float *)(s0 + 0x14));
        f12 = 1.0f;
        a0_2 = (void *)*(u8 *)(s0 + 0x7d);
        SfxDomanString_Start(1.0f, (unsigned short)a0_2);
    }
    return 1;
}


/* __SFXMNG_EventCall_Act @ 0x1C82D0 .. 0x1C82D8 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x1c82d4 computes the return value
 *   a0 typed from the __SFXMNG_EventCall_Act call table
 */




static u32 __SFXMNG_EventCall_Act(u32 *a0 /* r4 */) {
    return 1;
}







/* __SFXMNG_WhirlPool_Init @ 0x1C8240 .. 0x1C82D0 (0x90 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x4c escapes at 0x1c829c
 *   v0 is the pointer held in @6000+0x6c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int __SFXMNG_WhirlPool_Init(void *a0 /* r4 */) {
    u8 *s2;
    u32 *s1;
    u32 v0;
    u32 *s0;
    float f12;
    u8 stackFrame_4C[4] __attribute__((aligned(4)));

    s2 = (u8 *)a0;
    s1 = (u32 *)*(s32 *)(((u8 *)a0 + 0x48));
    v0 = (u32)__SFXMNG_DataAlloc(4);
    *(u32 *)(s2 + 0x6c) = v0;
    s0 = (u32 *)*(s32 *)(s2 + 0x6c);
    if ((u32)(s32)s0 == 0) {
        v0 = 0;
    } else {
        v0 = *(s32 *)s1;
        a0 = (void *)((u8 *)&stackFrame_4C[0]);
        *(u32 *)(s2 + 0x70) = v0;
        v0 = *(s32 *)(s2 + 0x4c);
        SFX_GetSeqParam(a0, 6, 1, (void *)*(s32 *)((v0 + 4)), 0);
        f12 = *(float *)((u8 *)&stackFrame_4C[0]);
        v0 = SetAppearEffect((float *)s2, f12);
        *(u32 *)s0 = v0;
        v0 = 1;
    }
    return v0;
}


/* __SFXMNG_WhirlPool_Act @ 0x1C81E0 .. 0x1C823C (0x5c bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x3c escapes at 0x1c820c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int __SFXMNG_WhirlPool_Act(void *a0 /* r4 */) {
    u32 *s1;
    u32 t0;
    u32 *s0;
    u8 *v0;
    float f12;
    u8 stackFrame_3C[4] __attribute__((aligned(4)));

    s1 = (u32 *)a0;
    v0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x4c));
    s0 = (u32 *)*(s32 *)(((u8 *)a0 + 0x6c));
    t0 = *(s32 *)(((u8 *)a0 + 0x74));
    SFX_GetSeqParam((void *)((u8 *)&stackFrame_3C[0]), 6, 1, (void *)*(s32 *)(v0 + 4), t0);
    a0 = (void *)*(s32 *)s0;
    f12 = *(float *)((u8 *)&stackFrame_3C[0]);
    UpdateAppearEffect((signed int)a0, (float *)s1, f12);
    return (signed int)(u32 *)(s32)1;
}


/* __SFXMNG_WhirlPool_End @ 0x1C8100 .. 0x1C81E0 (0xe0 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




static signed int __SFXMNG_WhirlPool_End(void *a0 /* r4 */) {
    u8 *s1;
    u32 a1;
    u32 v1;
    u32 v0;
    s32 s0;

    v0 = *(s32 *)(((u8 *)a0 + 0x6c));
    s1 = (u8 *)a0;
    if (v0 != 0) {
        a0 = (void *)*(s32 *)v0;
        DeleteAppearEffect((signed int)a0);
        v1 = s_pSfxMng;
        a0 = (void *)*(s32 *)(s1 + 0x6c);
        a1 = *(s32 *)((v1 + 0x28));
        if ((u32)((u32)(s32)a0 < a1) == 0) {
            if ((u32)(s32)((u8 *)a0 + 0x20) < (u32)(a1 + (s32)((u32)*(s32 *)((v1 + 0x24)) << 5))) {
                s0 = (u32)(s32)((u8 *)a0 - a1) >> 5;
                memset(a0, 0, 0x20);
                a0 = (void *)s_pSfxMng;
                v1 = *(s32 *)(((u8 *)a0 + 0x2c)) + (s32)((u32)(s0 / (s32)(0x20)) << 2);
                *(u32 *)v1 &= ~(u32)((u32)1 << (u32)(s32)((u8 *)(s32)0x1f - (u32)(s0 %
                    (s32)(0x20))));
            }
        }
        *(u32 *)(s1 + 0x6c) = 0;
    }
    return 1;
}
static void _SubFunc_Plume_Move(void *p_sfx_v /* r4 */, float dt_ /* f12 */) {
    u8 *p_sfx = (u8 *)p_sfx_v;
    struct PlumeDat *pDat;
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
    float press;

    pDat = (struct PlumeDat *)*(u32 *)(p_sfx + 0x6c);
    SPEED = sqrtf(sceVu0InnerProduct(pDat->n_speed, pDat->n_speed));
    C_PRESS = pDat->press_coeff;
    C_PITCH_SPD = 6.2831855f * *(volatile float *)&pDat->pitch_coeff;
    C_PITCH_VAL = 18.849556f * *(volatile float *)&pDat->valance;
    sceVu0Normalize(vMovDir, pDat->n_speed);
    sceVu0CopyMatrix(mrx, (void *)*(u32 *)(p_sfx + 0x60));
    {
    float grav[4] __attribute__((aligned(16))) = {0.0f, 9.8f, 0.0f, 0.0f};
    float vt[4] __attribute__((aligned(16)));
    float mRot[4][4] __attribute__((aligned(16)));
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
    sceVu0AddVector(pDat->n_speed, pDat->n_speed, vGrav);
    sceVu0AddVector(pDat->n_speed, pDat->n_speed, vPress);
    sceVu0ScaleVector(vt, pDat->n_speed, dt_);
    sceVu0AddVector((float *)p_sfx, vt, (float *)p_sfx);
    sceVu0CopyVector((void *)(*(u32 *)(p_sfx + 0x60) + 0x30), p_sfx);
    {
        float t;
        float spin = pitch_mov + sgn * C_PITCH_VAL;
        float a = spin * dt_;
        float r;
        t = 3.1415927f + a;
        if (t >= 0.0f) r = a - 6.2831855f * (float)(s32)(t / 6.2831855f);
        else r = 6.2831855f + (a - 6.2831855f * (float)(s32)(t / 6.2831855f));
        sceVu0RotMatrixX(mRot, MRX1, r);
    }
    dcomp_cop2_9397A3F6B7((void *)*(u32 *)(p_sfx + 0x60), (void *)*(u32 *)(p_sfx + 0x60), (void *)mRot);
    }
}
static signed int __SFXMNG_Plume_Init(void *a0 /* r4 */) {
    u8 *saved;
    u8 *params;
    u8 *data;
    float *a1;
    float r1;
    float r2;
    float rnd;
    float pos[4] __attribute__((aligned(16)));
    char dbg[256] __attribute__((aligned(16)));

    saved = (u8 *)a0;
    params = *(u8 **)(saved + DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214);
    *(u32 *)(saved + 0x6c) = (u32)__SFXMNG_DataAlloc(0x20);
    data = *(u8 **)(saved + 0x6c);
    if (data == 0) return 0;
    *(u32 *)(saved + 0x60) = (u32)__SFXMNG_DataAlloc(0x40);
    if (*(u32 *)(saved + 0x60) == 0) return 0;
    if (*(s16 *)(params + 2) < 0) {
        *(u32 *)(saved + 0x70) = 0x7fffffff;
    } else {
        *(u32 *)(saved + 0x70) = *(s16 *)(params + 2);
    }
    if (*(u8 *)(params + DCOMP_OFF_STRUCT_DW_2103726_FIELDS__23__CDUMMY_1B53159F) != 0) {
        r1 = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
        r2 = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
        SfxCalc_MakeMatrixFromPYR((void *)*(u32 *)(saved + 0x60), 6.2831855f * (r1 - 0.5f), 6.2831855f * (r2 - 0.5f), 0.0f);
    } else {
        if (*(u32 *)(saved + 0x64) != 0) {
            sceVu0CopyMatrix((void *)*(u32 *)(saved + 0x60), (void *)*(u32 *)(saved + 0x64));
        }
    }
    {
        float vec[4] __attribute__((aligned(16))) = {0};
        rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
        vec[2] = *(float *)(params + 0x18) + *(float *)(params + 0x1c) * (rnd - 0.5f);
        sceVu0CopyVector(data + 0x10, vec);
        sceVu0ApplyMatrix(data + 0x10, (void *)*(u32 *)(saved + 0x60), data + 0x10);
        SfxUtil_CalcRndPos(pos, *(u16 *)(params + 6), (float *)(params + 8));
        sceVu0AddVector(saved, saved, pos);
        *(float *)(saved + 0xc) = 1.0f;
        rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
        *(float *)data = *(float *)(params + 0x20) + *(float *)(params + 0x24) * (rnd - 0.5f);
        rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
        *(float *)(data + 4) = *(float *)(params + 0x28) + *(float *)(params + 0x2c) * (rnd - 0.5f);
        rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
        *(float *)(data + 8) = *(float *)(params + 0x30) + *(float *)(params + 0x34) * (rnd - 0.5f);
        *(u16 *)(data + 0xc) = SfxMdl_Alloc(*(u16 *)params, SFX_ConfirmReflect(*(u16 *)(*(u32 *)(saved + 0x44) + DCOMP_OFF_STRUCT_DW_2096304_FIELDS_COMMONPARAM_SFX_IDX_B45DC23E), 0));
        if (*(u16 *)(data + 0xc) == 0xffff) {
            a1 = (float *)"SfxMng.c";
            strcpy((char *)((u8 *)&dbg[0]), "SfxMng.c");
            a1 = (float *)"3D\323\303\336\331\212\204\202\350\223\226\202\304\216\270\224s";
            SfxDbg_SetDebugMsg(0, "3D\323\303\336\331\212\204\202\350\223\226\202\304\216\270\224s", (char *)((u8 *)&dbg[0]), 0x11d4);
        }
        sceVu0CopyVector((void *)(*(u32 *)(saved + 0x60) + 0x30), saved);
        SfxMdl_SetMatrix(*(u16 *)(data + 0xc), (void *)*(u32 *)(saved + 0x60));
    }
    return 1;
}


/* __SFXMNG_Plume_Act @ 0x1C7930 .. 0x1C797C (0x4c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3c888865 at 0x1c7944
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int __SFXMNG_Plume_Act(void *a0 /* r4 */) {
    u8 *s1;
    u8 *s0;

    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x6c));
    s1 = (u8 *)a0;
    _SubFunc_Plume_Move(a0, 0.0166666005f);
    SfxMdl_SetMatrix(*(u16 *)(s0 + 0xc), (void *)*(s32 *)(s1 + 0x60));
    return 1;
}


/* __SFXMNG_Plume_End @ 0x1C7840 .. 0x1C7930 (0xf0 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




static signed int __SFXMNG_Plume_End(void *a0 /* r4 */) {
    u8 *s1;
    u32 a1;
    u16 a0_narrow; // a0
    u32 v1;
    s32 s0;
    u32 v0;
    void *a0_2;

    v0 = *(s32 *)(((u8 *)a0 + 0x6c));
    s1 = (u8 *)a0;
    if (v0 != 0) {
        a0_narrow = *(u16 *)((v0 + 0xc));
        if ((u32)a0_narrow != (u32)0xffff) {
            SfxMdl_Free(a0_narrow);
        }
        v1 = s_pSfxMng;
        a0_2 = (void *)*(s32 *)(s1 + 0x6c);
        a1 = *(s32 *)((v1 + 0x28));
        if ((u32)((u32)(s32)a0_2 < a1) == 0) {
            if ((u32)(s32)((u8 *)a0_2 + 0x20) < (u32)(a1 + (s32)((u32)*(s32 *)((v1 + 0x24)) << 5)))
                {
                s0 = (u32)(s32)((u8 *)a0_2 - a1) >> 5;
                memset(a0_2, 0, 0x20);
                v1 = *(s32 *)(((u8 *)s_pSfxMng + 0x2c)) + (s32)((u32)(s0 / (s32)(0x20)) << 2);
                *(u32 *)v1 &= ~(u32)((u32)1 << (u32)(s32)((u8 *)(s32)0x1f - (u32)(s0 %
                    (s32)(0x20))));
            }
        }
        *(u32 *)(s1 + 0x6c) = 0;
    }
    return 1;
}
static signed int __SFXMNG_DmyPolyHoming_Init(void *a0 /* r4 */) {
    u8 *s2;
    u8 *s1;
    float *a1;
    u8 *s0;
    s32 v1;
    u32 v0;
    float f14;
    float f13;
    float f12;
    float rnd;
    float f0;
    void *a0_2;
    u8 stackFrame_40[256] __attribute__((aligned(16)));

    s2 = (u8 *)a0;
    s1 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_FIX_PARAM_F2BE8214);
    a0_2 = (void *)(s32)0x20;
    v0 = (u32)__SFXMNG_DataAlloc((signed int)a0_2);
    *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9) = v0;
    s0 = (u8 *)*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_2094394_FIELDS_P_DATA_4C74DEC9);
    if ((u32)(s32)s0 == 0) {
        v0 = 0;
        goto _L001C7820;
    }
    a0_2 = (void *)(s32)0x40;
    v0 = (u32)__SFXMNG_DataAlloc((signed int)a0_2);
    *(u32 *)(s2 + 0x60) = v0;
    v0 = *(s32 *)(s2 + 0x60);
    if (v0 == 0) {
        a1 = (float *)"SfxMng.c";
        strcpy((char *)((u8 *)&stackFrame_40[0]), (const char *)"SfxMng.c");
        a1 = (float *)"Failed to alloc matrix.";
        SfxDbg_SetDebugMsg(0, "Failed to alloc matrix.", (char *)(u8 *)((u8 *)&stackFrame_40[0]),
            0x1236);
    }
    v0 = *(s32 *)(s2 + 0x60);
    if (v0 == 0) {
        return 0;
    }
    v0 = *(s32 *)s1;
    *(u32 *)(s2 + 0x70) = v0;
    rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
    *(f32 *)(s2 + 0x10) = *(float *)(s2 + 0x10) + 0.01745f * (*(float *)(s1 + 4) + *(float *)(s1 + 8) * (rnd - 0.5f));
    rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
    *(f32 *)(s2 + 0x14) = *(float *)(s2 + 0x14) + 0.01745f * (*(float *)(s1 + 0xc) + *(float *)(s1 + 0x10) * (rnd - 0.5f));
    f12 = *(float *)(s2 + 0x10);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(f32 *)(s2 + 0x10) = f12;
    f12 = *(float *)(s2 + 0x14);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(f32 *)(s2 + 0x14) = f12;
    f12 = *(float *)(s2 + 0x18);
    f12 = (f12 < -3.14159f || 3.14159f < f12) ? SfxCalc_IntoAngle_0_2PI(f12) - 6.28318f : f12;
    *(f32 *)(s2 + 0x18) = f12;
    f12 = *(float *)(s2 + 0x10);
    f13 = *(float *)(s2 + 0x14);
    f14 = *(float *)(s2 + 0x18);
    a0_2 = (void *)s0;
    SfxCalc_QtnMakeFromPYR((float *)a0_2, f12, f13, f14);
    rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
    *(f32 *)(s0 + 0x10) = *(float *)(s1 + 0x14) + *(float *)(s1 + 0x18) * (rnd - 0.5f);
    v0 = 1;
    _L001C7820:;
    return v0;
}


/* __SFXMNG_DmyPolyHoming_Act @ 0x1C7360 .. 0x1C74E0 (0x180 bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1c73c4 writes a register its branch at 0x1c73c0 reads
 *   stack: address of the slot at 0x80 escapes at 0x1c7404
 *   stack: address of the slot at 0x50 escapes at 0x1c7418
 *   stack: address of the slot at 0x80 escapes at 0x1c7418
 *   stack: address of the slot at 0x50 escapes at 0x1c7424
 *   stack: address of the slot at 0x50 escapes at 0x1c7424
 *   stack: address of the slot at 0x70 escapes at 0x1c7430
 *   stack: address of the slot at 0x50 escapes at 0x1c7430
 *   stack: address of the slot at 0x9c escapes at 0x1c744c
 *   stack: address of the slot at 0x70 escapes at 0x1c7460
 *   stack: address of the slot at 0x60 escapes at 0x1c746c
 *   fpu: float literal 0x3c888865 at 0x1c7484
 *   stack: address of the slot at 0x40 escapes at 0x1c748c
 *   stack: address of the slot at 0x60 escapes at 0x1c748c
 *   stack: address of the slot at 0x40 escapes at 0x1c749c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int __SFXMNG_DmyPolyHoming_Act(void *a0 /* r4 */) {
    u8 *s1;
    u32 a2;
    u32 a1;
    u32 s0;
    u32 v1;
    u8 *s2;
    u32 v0;
    float f12;
    u8 stackFrame_9C[4] __attribute__((aligned(4)));
    u8 stackFrame_80[28] __attribute__((aligned(16)));
    u8 stackFrame_70[16] __attribute__((aligned(16)));
    u8 stackFrame_60[16] __attribute__((aligned(16)));
    u8 stackFrame_50[16] __attribute__((aligned(16)));
    u8 stackFrame_40[16] __attribute__((aligned(16)));

    v1 = GameSt[5];
    a1 = *(s32 *)(((u8 *)a0 + 0x48));
    s0 = *(s32 *)(((u8 *)a0 + 0x6c));
    s1 = (u8 *)a0;
    if (v1 == (u32)1) {
        v1 = *(u8 *)((a1 + 0x1c));
        v0 = (u32)MdlMng;
        a0 = (void *)(s32)(v1 + 0xdb);
        s2 = (u8 *)((u8 *)MdlMng + (u32)((u32)((s32)((u32)((u32)(a0)) * (u32)(7))) << 6));
    } else {
        s2 = (u8 *)(MdlMng + 0x11800);
    }
    v0 = *(u8 *)s2;
    if (v0 == 0) {
        return 1;
    }
    v0 = (u32)GetDummyPolyData((void *)*(s32 *)(s2 + 0xc), 0, *(u8 *)((a1 + 0x1d)));
    if (v0 == 0) {
        v0 = 0;
    } else {
        a1 = *(s16 *)((v0 + 0x20));
        v1 = *(s32 *)(s2 + 0x10);
        a2 = v0;
        v0 = a1 << 6;
        sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_80[0]), (void *)(s32)(v1 + v0), (void *)a2);
        v0 = *(s32 *)(s1 + 0x60);
        sceVu0SubVector((void *)((u8 *)&stackFrame_50[0]), (void *)((u8 *)&stackFrame_80[0]), (void
            *)(u32)(v0 + 0x30));
        sceVu0Normalize((void *)((u8 *)&stackFrame_50[0]), (void *)((u8 *)&stackFrame_50[0]));
        SfxCalc_QtnMakeFromDir((float *)((u8 *)&stackFrame_70[0]), (float *)((u8
            *)&stackFrame_50[0]));
        v0 = *(s32 *)(s1 + 0x4c);
        a1 = 6;
        SFX_GetSeqParam((void *)((u8 *)&stackFrame_9C[0]), a1, 1, (void *)*(s32 *)((v0 + 4)), *(s32
            *)(s1 + 0x74));
        SfxCalc_QtnSLerp((float *)s0, (float *)s0, (float *)((u8 *)&stackFrame_70[0]), *(float
            *)((u8 *)&stackFrame_9C[0]));
        SfxCalc_DirMakeFromQtn((float *)((u8 *)&stackFrame_60[0]), (float *)s0);
        f12 = (0.0166666005f * *(float *)((s0 + 0x10)));
        sceVu0ScaleVector((void *)((u8 *)&stackFrame_40[0]), (void *)((u8 *)&stackFrame_60[0]),
            f12);
        sceVu0AddVector((void *)s1, (void *)((u8 *)&stackFrame_40[0]), (void *)s1);
        a1 = s0;
        s0 = *(s32 *)(s1 + 0x60);
        SfxCalc_MakeMatrixFromQtn((void *)s0, (float *)a1);
        sceVu0CopyVector((void *)(u32)(s0 + 0x30), (void *)s1);
        v0 = 1;
    }
    return v0;
}


/* __SFXMNG_DmyPolyHoming_End @ 0x1C7280 .. 0x1C7358 (0xd8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int __SFXMNG_DmyPolyHoming_End(void *a0 /* r4 */) {
    u8 *s1;
    u32 a1;
    u32 v1;
    s32 s0;

    s1 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x6c));
    if ((u32)(s32)a0 != 0) {
        v1 = s_pSfxMng;
        a1 = *(s32 *)((v1 + 0x28));
        if ((u32)((u32)(s32)a0 < a1) == 0) {
            if ((u32)(s32)((u8 *)a0 + 0x20) < (u32)(a1 + (s32)((u32)*(s32 *)((v1 + 0x24)) << 5))) {
                s0 = (u32)(s32)((u8 *)a0 - a1) >> 5;
                memset(a0, 0, 0x20);
                a0 = (void *)s_pSfxMng;
                v1 = *(s32 *)(((u8 *)a0 + 0x2c)) + (s32)((u32)(s0 / (s32)(0x20)) << 2);
                *(u32 *)v1 &= ~(u32)((u32)1 << (u32)(s32)((u8 *)(s32)0x1f - (u32)(s0 %
                    (s32)(0x20))));
            }
        }
        *(u32 *)(s1 + 0x6c) = 0;
    }
    return 1;
}








/* __SFXMNG_Bugs_Init @ 0x1C70D0 .. 0x1C7278 (0x1a8 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x40 escapes at 0x1c70ec
 *   fpu: float literal 0x43000000 at 0x1c70fc
 *   fpu: float literal 0x4f000000 at 0x1c7104
 *   fpu: float literal 0x43000000 at 0x1c7180
 *   fpu: float literal 0x4f000000 at 0x1c7188
 *   fpu: float literal 0x43000000 at 0x1c71d0
 *   fpu: float literal 0x4f000000 at 0x1c71dc
 *   stack: address of the slot at 0x30 escapes at 0x1c7258
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int __SFXMNG_Bugs_Init(struct dw_2094394 *a0 /* r4 */) {
    struct dw_2101295 *s0;
    u32 a1;
    u32 v1;
    u32 v0;
    u8 stackFrame_40[80] __attribute__((aligned(16)));
    u8 stackFrame_30[16] __attribute__((aligned(16)));

    s0 = (struct dw_2101295 *)(s32)a0->p_fix_param;
    sceVu0CopyVector((void *)((u8 *)&stackFrame_40[0]), (void *)a0);
    ((f32 *)stackFrame_40)[4] = a0->pb.ang[1];
    *(u8 *)((u8 *)&stackFrame_30[0]) = 0;
    ((f32 *)stackFrame_40)[5] = s0->radius;
    ((f32 *)stackFrame_40)[7] = s0->speed;
    ((f32 *)stackFrame_40)[6] = s0->scale;
    ((f32 *)stackFrame_40)[8] = s0->rnd_range;
    ((u16 *)stackFrame_40)[18] = s0->tex_no;
    v0 = (s32)((u32)(128.0f * s0->rgb[2]) << 8) + (u32)(((u32)(128.0f * s0->rgb[0]) << 0x18) +
        (u32)((u32)(128.0f * s0->rgb[1]) << 0x10));
    a1 = -0x41000000;
    v1 = 1;
    ((u32 *)stackFrame_40)[10] = v0 + 0x80;
    ((f32 *)stackFrame_40)[11] = s0->life;
    ((u32 *)stackFrame_40)[14] = 0x3f000000;
    ((u32 *)stackFrame_40)[15] = -0x41000000;
    ((u8 *)stackFrame_40)[64] = v1;
    ((u16 *)stackFrame_40)[19] = 0x100;
    ((u8 *)stackFrame_40)[65] = v1;
    SfxBugs_Create((void *)((u8 *)&stackFrame_30[0]));
    return 1;
}


signed int SfxMng_BurnModel(void *pMdl_) {
    extern BM_Fire s_fire_attach;
    u16 nPartsNum;
    u16 model_no;
    int bExistData;
    int i;
    int j;
    int k;

    if (((u8 *)pMdl_)[0] == 0) {
        return 0;
    }
    nPartsNum = *(u16 *)(*(u8 **)(*(u8 **)((u8 *)pMdl_ + 0xc) + 0x10) + 0x10);
    model_no = **(u16 **)(*(u8 **)((u8 *)pMdl_ + 0xc) + 0x4c);
    bExistData = 0;
    if (((u8 *)pMdl_)[0x129] == 1) {
        for (i = 0; i < s_fire_attach.num_data; i++) {
            if (s_fire_attach.aData[i].char_id == model_no) {
                BM_AX *ptr;
                int tmp;
                j = 0;
                ptr = (BM_AX *)((u8 *)&s_fire_attach + i * 0x50);
                tmp = nPartsNum;
                for (; j < 2; j++, ptr = (BM_AX *)((u8 *)ptr + 0x20)) {
                    if (ptr->sfx_idx != 0) {
                        if (ptr->fParts[0] == (u64)-1 && ptr->fParts[0] == (u64)-1) {
                            s16 skip = ptr->skip != -1 ? ptr->skip : s_fire_attach.default_skip;
                            for (k = 0; k < tmp; k += (s16)(skip + 1)) {
                                SFX_Create_OnAng_Attach(ptr->sfx_idx, 0, 0, pMdl_, k, 0, 0);
                            }
                        } else {
                            u64 *hi;
                            k = 0;
                            if (k < tmp) {
                                hi = &ptr->fParts[1];
                                do {
                                    if ((j < 0x40 ? (s32)(ptr->fParts[0] >> k) & 1 : (s32)(*hi >> (k - 0x40)) & 1) != 0) {
                                        SFX_Create_OnAng_Attach(ptr->sfx_idx, 0, 0, pMdl_, k, 0, 0);
                                    }
                                    k++;
                                } while (k < tmp);
                            }
                        }
                    }
                }
                break;
            }
        }
        if (i < s_fire_attach.num_data) {
            bExistData = 1;
        }
    }
    if (bExistData == 0) {
        for (k = 0; k < (s32)nPartsNum; k += s_fire_attach.default_skip) {
            SFX_Create_OnAng_Attach(s_fire_attach.default_sfx, 0, 0, pMdl_, k, 0, 0);
        }
    }
    return 1;
}


/* _InitFireAttachData @ 0x1C6AE0 .. 0x1C6E14 (0x334 bytes) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 */


extern u32 s_fire_attach[];
static u32 s_fire_attach[0x504];
void _InitFireAttachData(void) {
    int i;
    struct fa_Ent *ent;
    s32 m1i;
    u_long128 m1;
    FA(0) = 23;
    FA(1) = 404;
    FA(2) = 10;
    m1i = -1;
    m1 = (u_long128)m1i;
    for (i = 0; i < FA(0); i++) {
        ent = (struct fa_Ent *)s_fire_attach + i;
        ent->f[8] = 0;
        ent->f[16] = 0;
        ent->f[32] = 0;
        *(u_long128 *)&ent->f[24] = m1;
        *(u_long128 *)&ent->f[40] = m1;
        *(s16 *)&ent->f[17] = -1;
        *(s16 *)&ent->f[33] = -1;
    }
    FA(8) = 2;
    FA(16) = 404;
    FA(17) = 10;
    FA(48) = 3;
    FA(56) = 404;
    FA(57) = 11;
    FA(88) = 11;
    FA(96) = 404;
    FA(97) = 9;
    FA(128) = 14;
    FA(136) = 404;
    FA(137) = 8;
    FA(168) = 15;
    FA(176) = 404;
    FA(177) = 10;
    FA(208) = 21;
    FA(216) = 404;
    FA(217) = 8;
    FA(248) = 22;
    FA(256) = 405;
    FA(257) = 8;
    FA(288) = 23;
    FA(296) = 404;
    FA(297) = 16;
    FA(328) = 25;
    FA(336) = 404;
    FA(337) = 3;
    FA(368) = 26;
    FA(376) = 404;
    FA(377) = 6;
    FA(408) = 28;
    FA(416) = 404;
    FA(417) = 13;
    FA(448) = 31;
    FA(456) = 404;
    FA(457) = 10;
    FA(488) = 32;
    FA(496) = 404;
    FA(497) = 12;
    FA(528) = 33;
    FA(536) = 404;
    FA(537) = 14;
    FA(568) = 34;
    FA(576) = 404;
    FA(577) = 18;
    FA(608) = 35;
    FA(616) = 404;
    FA(617) = 18;
    FA(648) = 36;
    FA(656) = 404;
    FA(657) = 12;
    FA(688) = 37;
    FA(696) = 404;
    FA(697) = 12;
    FA(728) = 41;
    FA(736) = 404;
    FA(737) = 10;
    FA(768) = 42;
    FA(776) = 404;
    FA(777) = 8;
    FA(808) = 43;
    FA(816) = 404;
    FA(817) = 8;
    FA(848) = 44;
    FA(856) = 404;
    FA(857) = 8;
    FA(888) = 45;
    FA(897) = 20;
    FA(896) = 404;
}
