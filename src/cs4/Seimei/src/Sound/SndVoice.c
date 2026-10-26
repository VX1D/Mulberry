#include "common.h"

#ifndef PROTO_DW_1841300_FIELDS
#define PROTO_DW_1841300_FIELDS
struct dw_1841300_fields { int type; float scale; };
#endif
#ifndef PROTO_DW_1842230_FIELDS
#define PROTO_DW_1842230_FIELDS
struct dw_1842230_fields { char on; char job; char type; char cDmy1[1]; int SeKind; unsigned short usSndId; short BankId; short bd_prog; short vid; float fAngleNoClip; short sVolume; short sCalcedVolume; short sPan; short bend; short p_bend; short sDmy3[1]; float Pos[4]; float (*pPos)[4]; float fDistMax; float fDistMin; int flm; };
#endif
#ifndef PROTO_DW_1848559_FIELDS
#define PROTO_DW_1848559_FIELDS
struct dw_1848559_fields { float (*fvListenerPosPtr)[4]; float (*fvListenerAngPtr)[4]; float (*fmListenerMatPtr)[4][4]; };
#endif
#ifndef PROTO_DW_1847791_FIELDS
#define PROTO_DW_1847791_FIELDS
struct dw_1847791_fields { float panlim; float zofs; char dopp; char pad[3]; float range; char reserved[16]; };
#endif
#ifndef PROTO_DW_1845166_FIELDS
#define PROTO_DW_1845166_FIELDS
struct dw_1845166_fields { short sCalcedVol; char bid; char sid; char PlayId; char reserv[3]; int sq_fade; int sq_vol; };
#endif
#ifndef PROTO_DW_1847015_FIELDS
#define PROTO_DW_1847015_FIELDS
struct dw_1847015_fields { unsigned short usFreq; unsigned char ucLoop; char cDmy[1]; };
#endif
#ifndef PROTO_DW_1847369_FIELDS
#define PROTO_DW_1847369_FIELDS
struct dw_1847369_fields { unsigned int uiProgNum; char cDmy[12]; struct dw_1847015_fields aParam[128]; };
#endif
#ifndef PROTO_DW_1845925_FIELDS
#define PROTO_DW_1845925_FIELDS
struct dw_1845925_fields { struct dw_1848559_fields Listener; struct dw_1847791_fields Param; signed char SndMode; unsigned char bfMasterVolume : 1; unsigned char bfReserv : 7; unsigned char ucMasterVolume; unsigned char ucBgmVolume; unsigned char ucSqVolume; unsigned char ucSeVolume; unsigned short usVolumeFadeOutFrame; char rid[8]; unsigned short ucVoiceCnt; unsigned char _pad0[2]; int Handle[12]; struct dw_1845166_fields aSqSong[4]; unsigned char calloff; unsigned char _pad1[3]; struct dw_1847369_fields aBankInfo[12]; unsigned short aaIdTable[12][128]; unsigned int uiUseVoiceNum; };
#endif
#ifndef PROTO_DW_1847585_FIELDS
#define PROTO_DW_1847585_FIELDS
struct dw_1847585_fields { int vol; int pan; int id; int update; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1841300_FIELDS_SCALE_F66A89F1_DEFINED
#define DCOMP_OFF_STRUCT_DW_1841300_FIELDS_SCALE_F66A89F1_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1841300_FIELDS_SCALE_F66A89F1 = (int)&(((struct dw_1841300_fields *)0)->scale) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1841300_FIELDS_TYPE_C6EF04B8_DEFINED
#define DCOMP_OFF_STRUCT_DW_1841300_FIELDS_TYPE_C6EF04B8_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1841300_FIELDS_TYPE_C6EF04B8 = (int)&(((struct dw_1841300_fields *)0)->type) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1842230_FIELDS_FLM_39E65722_DEFINED
#define DCOMP_OFF_STRUCT_DW_1842230_FIELDS_FLM_39E65722_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1842230_FIELDS_FLM_39E65722 = (int)&(((struct dw_1842230_fields *)0)->flm) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1842230_FIELDS_JOB_E0D1D47D_DEFINED
#define DCOMP_OFF_STRUCT_DW_1842230_FIELDS_JOB_E0D1D47D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1842230_FIELDS_JOB_E0D1D47D = (int)&(((struct dw_1842230_fields *)0)->job) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1842230_FIELDS_ON_908D796E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1842230_FIELDS_ON_908D796E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1842230_FIELDS_ON_908D796E = (int)&(((struct dw_1842230_fields *)0)->on) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1842230_FIELDS_SCALCEDVOLUME_2512EA91_DEFINED
#define DCOMP_OFF_STRUCT_DW_1842230_FIELDS_SCALCEDVOLUME_2512EA91_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1842230_FIELDS_SCALCEDVOLUME_2512EA91 = (int)&(((struct dw_1842230_fields *)0)->sCalcedVolume) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1842230_FIELDS_SPAN_2E7E666B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1842230_FIELDS_SPAN_2E7E666B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1842230_FIELDS_SPAN_2E7E666B = (int)&(((struct dw_1842230_fields *)0)->sPan) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1842230_FIELDS_TYPE_AF23E0E2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1842230_FIELDS_TYPE_AF23E0E2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1842230_FIELDS_TYPE_AF23E0E2 = (int)&(((struct dw_1842230_fields *)0)->type) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1845925_FIELDS_UCVOICECNT_8F60FBA6_DEFINED
#define DCOMP_OFF_STRUCT_DW_1845925_FIELDS_UCVOICECNT_8F60FBA6_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1845925_FIELDS_UCVOICECNT_8F60FBA6 = (int)&(((struct dw_1845925_fields *)0)->ucVoiceCnt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1845925_FIELDS_UIUSEVOICENUM_0A78FB3F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1845925_FIELDS_UIUSEVOICENUM_0A78FB3F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1845925_FIELDS_UIUSEVOICENUM_0A78FB3F = (int)&(((struct dw_1845925_fields *)0)->uiUseVoiceNum) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1847585_FIELDS_ID_87EADE7C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1847585_FIELDS_ID_87EADE7C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1847585_FIELDS_ID_87EADE7C = (int)&(((struct dw_1847585_fields *)0)->id) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1847585_FIELDS_PAN_00499765_DEFINED
#define DCOMP_OFF_STRUCT_DW_1847585_FIELDS_PAN_00499765_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1847585_FIELDS_PAN_00499765 = (int)&(((struct dw_1847585_fields *)0)->pan) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1847585_FIELDS_UPDATE_F75B0526_DEFINED
#define DCOMP_OFF_STRUCT_DW_1847585_FIELDS_UPDATE_F75B0526_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1847585_FIELDS_UPDATE_F75B0526 = (int)&(((struct dw_1847585_fields *)0)->update) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1847585_FIELDS_VOL_9C52F57A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1847585_FIELDS_VOL_9C52F57A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1847585_FIELDS_VOL_9C52F57A = (int)&(((struct dw_1847585_fields *)0)->vol) - 0 };
#endif



extern f32 s_fLoopSndVolumeScale;

struct SeGroupInfo {
    u16 grpHead;
    u16 aSeId[7];
};
struct SndMngBankTbl {
    u8 mngHead[0x1974];
    u16 bank[12][0x80];
};
struct SurEnt { s32 vol, pan, id, update; };
extern void MemFree(void *);
extern void * MemAllocAlignReal(unsigned int, unsigned int, char *, char *);
extern void * MemAllocReal(unsigned int, char *, char *);
extern void *memcpy();
extern u32 s_aSeGroup;
extern u32 s_aucGrpLastOn;
extern u32 s_iSeGroupNum;
extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);
static u32 pDmy_1206;
extern u8 s_aVoice[];
extern int rand();
extern u32 g_pSndMng;
extern float powf(float, float);
extern u32 s_aFadeInfo[];
extern signed int fssdsynthSeStreamOff(signed int);
static signed int _SeKick_Assemble(void *a0);
static signed int _SeKick_Assemble(void *);
extern void fsvu0_CopyVectorF(float *, float *);
static void _Proc2D(void *a0 );
static void _Proc2D(void *a0 );
static void _Proc3D(void *a0 );
static void _Proc3D(void *a0 );
static void _FadeProc(signed int a0 );
static void _FadeProc(signed int a0 );
extern void fssdsynthPackSeStreamSurroundOn();
extern u32 surPack[];
extern signed int fssdsynthGetSeState(signed int);
static void _Pan(struct dw_1842230_fields *pVoice);
static void _Pan(struct dw_1842230_fields *);
extern void *memset(void *, int, unsigned int);
void SND_SetLoopSeVolumeScale(float f12 );
void SND_SetLoopSeVolumeScale(float f12 /* f12 */);
signed int SND_LoadRandSeFromFileInMemory(void *a0 );
signed int SND_LoadRandSeFromFileInMemory(void *a0 /* r4 */);
signed int SND_LoadRandSeFromFile(char *a0 );
signed int SND_LoadRandSeFromFile(char *a0 /* r4 */);
static void * _GetFreeVoice(signed int *a0 );
static void * _GetFreeVoice(signed int *a0 /* r4 */);
static signed int _GetBankInfo(signed int *pBankNo, signed int *pBankInId, signed int iSndId);
static signed int _GetBankInfo(signed int *pBankNo, signed int *pBankInId, signed int iSndId);
static void _CalcPitch(void *voice);
static void _CalcPitch(void *voice);
void SND_FadeStop(signed int a0 );
void SND_FadeStop(signed int a0 /* r4 */);
void SND_Stop(signed int a0 );
void SND_Stop(signed int a0 /* r4 */);
u32 SND_Play3D(signed int a0 , signed short a1 , signed short a2 , void *a3 , float f12 );
u32 SND_Play3D(signed int a0 /* r4 */, signed short a1 /* r5 */, signed short a2 /* r6 */, void *a3
        /* r7 */, float f12 /* f12 */);
signed int SND_Play3DPoint(signed int a0 , signed short a1 , signed short a2 , float *a3 , float f12 );
signed int SND_Play3DPoint(signed int a0 /* r4 */, signed short a1 /* r5 */, signed short a2 /* r6
        */, float *a3 /* r7 */, float f12 /* f12 */);
signed int SND_Play2D(signed int a0 , signed short a1 , signed short a2 );
signed int SND_Play2D(signed int a0 /* r4 */, signed short a1 /* r5 */, signed short a2 /* r6 */);
void SND_VoiceProc(void);
void SND_VoiceProc(void);
static void _FadeProc(signed int a0 /* r4 */);
static void _Proc3D(void *a0 /* r4 */);
static void _Proc2D(void *a0 /* r4 */);
void SND_VoiceOffSeKind(u8 a0 );
void SND_VoiceOffSeKind(u8 a0 /* r4 */);
void SND_VoiceFadeOffAll(void);
void SND_VoiceFadeOffAll(void);
void SND_VoiceOffAll(void);
void SND_VoiceOffAll(void);
void SND_VoiceInitMng(void);
void SND_VoiceInitMng(void);


static s32 s_curPack = 0;
static u32 s_aSeGroup = 0;
static u32 s_iSeGroupNum = 0;
static u32 s_aucGrpLastOn = 0;
static s32 s_iNextVoice = 0;








u8 g_RollOffType;
extern float (*SND_GetListenerMatPtr(void))[4][4];
extern void fsvu0_ApplyMatrix(float *, void *, float *);
extern float sceVu0InnerProduct(void *, void *);
extern float atanf(float);
extern float atan2f(float, float);
extern float sqrtf(float);

extern u32 lpDrawMng;


extern float g_fSndScaleFactor;
extern float s_fDistScale;


struct PanDrawMng { u8 pad[0x41c]; float fov; };


/* _SeKick_Assemble @ 0x1AB920 */
extern signed int fssdsynthSeStreamOn(signed int, signed int, char, char, char, char, char,
    unsigned short);

extern signed int fssdsynthSeStreamOn_forSurround(signed int, signed int, char, char, char,
    unsigned short);
extern float g_fSndDefDistMin;

struct SkVoice { char on; char job; char type; char cDmy1[1]; int SeKind; unsigned short usSndId; short BankId; short bd_prog; short vid; float fAngleNoClip; short sVolume; short sCalcedVolume; short sPan; short bend; short p_bend; short sDmy3[1]; float Pos[4]; float (*pPos)[4]; float fDistMax; float fDistMin; int flm; };
struct SkParam { unsigned short usFreq; unsigned char ucLoop; char cDmy[1]; };
struct SkBank { unsigned int uiProgNum; char cDmy[12]; struct SkParam aParam[128]; };
enum SkLoopBool { SkLoop_F, SkLoop_T };
struct SkFade { int type; float scale; };
struct SkMng { u8 pad0[0x31]; unsigned char ucSeVolume; u8 pad1[0x3c - 0x32]; unsigned short ucVoiceCnt; int Handle[12]; u8 pad2[0xb4 - 0x70]; struct SkBank aBankInfo[12]; };

static u8 s_aVoice[0x1000];
static u32 s_aFadeInfo[0x80];

static u32 surPack[0x104]; /* +0x10 B unreferenced tail in the original */
u8 g_RollOffType = 1;
float g_fSndScaleFactor = 1.0f;
float g_fSndDefDistMin = 3.0f;
static float s_fDistScale = 1.0f;
static f32 s_fLoopSndVolumeScale = 1.0f;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SND_VoiceInitMng(void);
void SND_VoiceOffAll(void);
void SND_VoiceFadeOffAll(void);
void SND_VoiceOffSeKind(u8 a0 );
static void _Proc2D(void *a0 );
static void _Proc3D(void *a0 );
static void _FadeProc(signed int a0 );
void SND_VoiceProc(void);
static void _Pan(struct dw_1842230_fields *pVoice);
static signed int _SeKick_Assemble(void *a0);
signed int SND_Play2D(signed int a0 , signed short a1 , signed short a2 );
signed int SND_Play3DPoint(signed int a0 , signed short a1 , signed short a2 , float *a3 , float f12 );
u32 SND_Play3D(signed int a0 , signed short a1 , signed short a2 , void *a3 , float f12 );
void SND_Stop(signed int a0 );
void SND_FadeStop(signed int a0 );
static void _CalcPitch(void *voice);
static signed int _GetBankInfo(signed int *pBankNo, signed int *pBankInId, signed int iSndId);
static void * _GetFreeVoice(signed int *a0 );
signed int SND_LoadRandSeFromFile(char *a0 );
signed int SND_LoadRandSeFromFileInMemory(void *a0 );
void SND_SetLoopSeVolumeScale(float f12 );


/* SND_VoiceInitMng @ 0x1AC8F0 .. 0x1AC904 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j memset at 0x1ac8fc leaves the function
 *   return value dropped, call kept: the function is void
 */


void SND_VoiceInitMng(void) {
    memset((u8 *)s_aVoice, 0, 0x1000);
    return;
}












/* SND_VoiceOffAll @ 0x1AC870 .. 0x1AC8F0 (0x80 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001AC890
 */



void SND_VoiceOffAll(void) {
    s32 s1;
    u8 *s0;
    s32 v0;
    u32 a0;

    s1 = 0;
    s0 = (u8 *)s_aVoice;
    do {
        v0 = *(s8 *)s0;
        if (v0 > 0) {
            a0 = *(s16 *)(s0 + 0xe);
            if ((s32)a0 >= 0 && (s32)a0 < (s32)0x40) {
                fssdsynthSeStreamOff(a0);
            }
        }
        s1 = s1 + 1;
        v0 = s1 < (s32)0x40;
        s0 = (u8 *)(s0 + 0x40);
    } while ((u32)v0 != 0);
    a0 = (u32)s_aVoice;
    memset(s_aVoice, 0, (s32)0x1000);
    return;
}






/* SND_VoiceFadeOffAll @ 0x1AC810 .. 0x1AC868 (0x58 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001AC838
 */




void SND_VoiceFadeOffAll(void) {
    s32 a3;
    u32 *a2;
    u8 *a1;
    s32 v1;

    a3 = 0x40;
    a2 = s_aFadeInfo;
    a1 = s_aVoice;
    if (a3-- != 0) {
        do {
            v1 = *(s8 *)a1;
            if (v1 > 0) {
                *(u32 *)a2 = 3;
            }
            a2 = (u32 *)(u8 *)(a2 + 2);
            a1 = (u8 *)(a1 + 0x40);
        } while (a3-- != 0);
    }
    return;
}






/* SND_VoiceOffSeKind @ 0x1AC750 .. 0x1AC808 (0xb8 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1ac7b0 writes a register its branch at 0x1ac7ac reads
 *   cfg: loop body is not one contiguous region: .L001AC780
 */







void SND_VoiceOffSeKind(u8 a0 /* r4 */) {
    s32 s3;
    u8 *s2;
    u8 *s1;
    u32 v1;
    u32 a0_2;

    s3 = 0;
    s2 = (u8 *)s_aVoice;
    s1 = (u8 *)s_aVoice;
    do {
        v1 = *(s8 *)s2;
        if ((s32)v1 > 0 && (u32)*(s32 *)(s2 + 4) == (u32)a0 && s3 >= 0 && s3 < (s32)0x40 &&
            (s32)*(s8 *)s1 > 0) {
            *(s8 *)s1 = -1;
            *(u32 *)(s1 + 0x3c) = 0;
            a0_2 = *(s16 *)(s1 + 0xe);
            if ((s32)a0_2 >= 0 && (s32)a0_2 < (s32)0x40) {
                fssdsynthSeStreamOff(a0_2);
            }
        }
        s3 = s3 + 1;
        v1 = s3 < (s32)0x40;
        s1 = (u8 *)(s1 + 0x40);
        s2 = (u8 *)(s2 + 0x40);
    } while (v1 != 0);
    return;
}












static void _Proc2D(void *a0 /* r4 */) {
    __asm__ volatile(
        ".set noreorder\n"
        "daddu $16,$4,$0\n"
        ".word 0x12000019\n"
        "nop\n"
        "lb $4,2($16)\n"
        "addiu $3,$0,1\n"
        ".word 0x10830015\n"
        "nop\n"
        "lw $3,0x3c($16)\n"
        "slti $1,$3,0xb\n"
        ".word 0x14200011\n"
        "nop\n"
        "jal fssdsynthGetSeState\n"
        "lh $4,0xe($16)\n"
        ".word 0x1440000d\n"
        "nop\n"
        "lh $4,0xe($16)\n"
        ".word 0x04800006\n"
        "nop\n"
        "slti $1,$4,0x40\n"
        ".word 0x10200003\n"
        "nop\n"
        "jal fssdsynthSeStreamOff\n"
        "nop\n"
        "addiu $3,$0,-1\n"
        ".word 0x10000002\n"
        "sb $3,0($16)\n"
        "nop\n"
        ".set reorder\n"
        :
        :
        : "memory");
}





static void _Proc3D(void *a0 /* r4 */) {
    __asm__ volatile(
        ".set noreorder\n"
        "daddu $16,$4,$0\n"
        ".word 0x1200001b\n"
        "nop\n"
        "lb $3,2($16)\n"
        "addiu $2,$0,1\n"
        ".word 0x10620015\n"
        "nop\n"
        "lw $2,0x3c($16)\n"
        "slti $1,$2,0xb\n"
        ".word 0x14200011\n"
        "nop\n"
        "jal fssdsynthGetSeState\n"
        "lh $4,0xe($16)\n"
        ".word 0x1440000d\n"
        "nop\n"
        "lh $4,0xe($16)\n"
        ".word 0x04800006\n"
        "nop\n"
        "slti $1,$4,0x40\n"
        ".word 0x10200003\n"
        "nop\n"
        "jal fssdsynthSeStreamOff\n"
        "nop\n"
        "addiu $3,$0,-1\n"
        ".word 0x10000004\n"
        "sb $3,0($16)\n"
        "nop\n"
        "jal _Pan\n"
        "daddu $4,$16,$0\n"
        ".set reorder\n"
        :
        :
        : "memory");
}




/* _FadeProc @ 0x1AC4E0 .. 0x1AC628 (0x148 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1ac518 writes a register its branch at 0x1ac514 reads
 *   fpu: float literal 0x3c88893b at 0x1ac53c
 *   fpu: float literal 0x3f800000 at 0x1ac544
 *   fpu: float literal 0x3c88893b at 0x1ac574
 *   fpu: float literal 0x00000000 at 0x1ac578
 *   fpu: float literal 0x3d8888b5 at 0x1ac5ac
 *   fpu: float literal 0x00000000 at 0x1ac5b0
 *   declaration vs inferred signature: return void vs inferred u32
 */







static void _FadeProc(signed int a0 /* r4 */) {
    u8 *a2;
    u32 a1;
    float f2;
    u32 v1;
    float f1;
    float f0;
    s32 fpcc;
    s32 s0;

    a1 = (u32)a0 << 3;
    v1 = (u32)s_aFadeInfo;
    a2 = (u8 *)((u8 *)s_aFadeInfo + a1);
    a1 = *(s32 *)a2;
    v1 = 3;
    switch (a1) {
    case 1:
        f2 = *(float *)(a2 + 4);
        a0 = 0x3c88893b;
        f1 = 0.0166669991f;
        v1 = 0x3f800000;
        f0 = 1.0f;
        f1 = (f2 + (float)f1);
        fpcc = f1 <= 1.0f;
        *(f32 *)(a2 + 4) = f1;
        if (fpcc) {
            break;
        }
        *(f32 *)(a2 + 4) = f0;
        *(u32 *)a2 = 0;
        break;
    case 2:
        f2 = *(float *)(a2 + 4);
        v1 = 0x3c88893b;
        f1 = 0.0166669991f;
        f0 = 0.0f;
        f1 = (f2 - 0.0166669991f);
        fpcc = f1 < 0.0f;
        *(f32 *)(a2 + 4) = f1;
        if (!fpcc) {
            break;
        }
        *(f32 *)(a2 + 4) = f0;
        *(u32 *)a2 = 0;
        break;
    case 3:
        f2 = *(float *)(a2 + 4);
        v1 = 0x3d8888b5;
        f1 = 0.066666998f;
        f0 = 0.0f;
        f1 = (f2 - 0.066666998f);
        fpcc = f1 < 0.0f;
        *(f32 *)(a2 + 4) = f1;
        if (!fpcc) {
            break;
        }
        s0 = (u32)a0 << 6;
        *(f32 *)(a2 + 4) = f0;
        v1 = (u32)((u8 *)s_aVoice + 0xe);
        *(u32 *)a2 = 0;
        v1 = v1 + s0;
        a0 = *(s16 *)v1;
        if ((s32)a0 >= 0 && (s32)a0 < (s32)0x40) {
            fssdsynthSeStreamOff(a0);
        }
        v1 = (u32)s_aVoice;
        a0 = -1;
        v1 = (s32)((u8 *)s_aVoice + s0);
        *(s8 *)v1 = a0;
    case 0:
        break;
    }
    return;
}






/* SND_VoiceProc @ 0x1AC340 .. 0x1AC4D8 (0x198 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v1 at 0x1ac400
 *   cfg: loop body is not one contiguous region: .L001AC378
 */
/* r4 */
/* r4 */
/* r4 */


void SND_VoiceProc(void) {
    s32 i;
    u8 *v;
    u8 *fade;
    struct SurEnt *p;

    s_curPack = 0;
    v = s_aVoice;
    fade = (u8 *)s_aFadeInfo;
    *(u32 *)(g_pSndMng + DCOMP_OFF_STRUCT_DW_1845925_FIELDS_UIUSEVOICENUM_0A78FB3F) = 0;
    for (i = 0; i < 0x40; i++, fade += 8, v += 0x40) {
        if (*(s8 *)v <= 0) {
            *(u8 *)v = 0;
            continue;
        }
        *(s32 *)(g_pSndMng + DCOMP_OFF_STRUCT_DW_1845925_FIELDS_UIUSEVOICENUM_0A78FB3F) += 1;
        switch (*(s8 *)(v + 1)) {
        case 0:
            _Proc2D((void *)v);
            break;
        case 1:
            _Proc3D((void *)v);
        }
        _FadeProc(i);
        if (*(s8 *)v > 0) {
            p = &((struct SurEnt *)surPack)[s_curPack];
            p->vol = (s32)((float)*(s16 *)(v + 0x16) * *(float *)(fade + 4));
            p->pan = *(s16 *)(v + 0x18);
            p->id = i;
            if (*(s32 *)fade == 0) {
                p->update = !(*(s8 *)(v + 1) == 0 && *(s8 *)(v + 2) != 1);
            } else {
                p->update = 1;
            }
            s_curPack++;
            *(s32 *)(v + 0x3c) += 1;
        }
    }
    if (s_curPack > 0) {
        fssdsynthPackSeStreamSurroundOn((u32)-1, s_curPack, surPack);
    }
    *(u16 *)(g_pSndMng + DCOMP_OFF_STRUCT_DW_1845925_FIELDS_UCVOICECNT_8F60FBA6) = 0;
}

static void _Pan(struct dw_1842230_fields *pVoice)
{
    float (*fmListenerMatPtr)[4][4];
    float fvToListener[4] __attribute__((aligned(16)));
    float fToListenerDist;
    float fVolume;
    float fFovCoef;
    float fDistMax;
    float fVoiceVol;
    float fPan;
    float fAngY;

    fmListenerMatPtr = SND_GetListenerMatPtr();
    fVolume = 0.0f;
    fDistMax = pVoice->fDistMax * s_fDistScale;
    fVoiceVol = (float)pVoice->sVolume;
    if (pVoice == 0) {
        return;
    }
    if (fmListenerMatPtr == 0) {
        return;
    }
    if (pVoice->pPos == 0) {
        return;
    }
    fsvu0_ApplyMatrix(fvToListener, fmListenerMatPtr, (float *)pVoice->pPos);
    fFovCoef = atanf(0.5f * ((struct PanDrawMng *)lpDrawMng)->fov);
    if (fFovCoef != 0.0f) {
        fvToListener[0] = fvToListener[0] / fFovCoef;
    }
    fToListenerDist = sqrtf(sceVu0InnerProduct(fvToListener, fvToListener));
    fToListenerDist = fToListenerDist * g_fSndScaleFactor;
    fToListenerDist = fToListenerDist * fFovCoef;
    if (pVoice->type == 1) {
        fVoiceVol = fVoiceVol * s_fLoopSndVolumeScale;
    }
    {
        float fMin = pVoice->fDistMin;

        if (fToListenerDist <= fMin) {
            fVolume = fVoiceVol;
        } else if (g_RollOffType == 1) {
            float fMax;
            float fCoef;

            if (fMin < 1.0f) fMin = 1.0f;
            if (fDistMax < 1.0f) fDistMax = 1.0f;
            fMax = fDistMax;
            if (fToListenerDist >= fMax) {
                fCoef = fMin / fMax;
            } else if (fToListenerDist != 0.0f) {
                fCoef = fMin / fToListenerDist;
            } else {
                fCoef = 1.0f;
            }
            fVolume = fVoiceVol * powf(fCoef, 1.0f);
        } else if (g_RollOffType == 2) {
            if (fToListenerDist >= fDistMax) {
                fVolume = 0.0f;
            } else {
                float fCoef = (fToListenerDist - fMin) / (fDistMax - fMin) - 1.0f;
                fVolume = fCoef * (fVoiceVol * fCoef);
            }
        } else if (g_RollOffType == 0) {
            if (fToListenerDist >= fDistMax) {
                fVolume = 0.0f;
            } else {
                fVolume = fVoiceVol * (1.0f - (fToListenerDist - fMin) / (fDistMax - fMin));
            }
        }
    }
    pVoice->sCalcedVolume = (short)fVolume;
    pVoice->sCalcedVolume = (unsigned char)(127.0f * (((float)pVoice->sCalcedVolume * (float)((struct dw_1845925_fields *)g_pSndMng)->ucSeVolume) / 127.0f) / 127.0f);
    if (pVoice->sCalcedVolume < 0) pVoice->sCalcedVolume = 0;
    if (pVoice->sCalcedVolume > 127) pVoice->sCalcedVolume = 127;
    if (*(u8 *)&((struct dw_1845925_fields *)g_pSndMng)->SndMode == 0) {
        pVoice->sPan = -0x100;
    } else {
        fAngY = atan2f(fvToListener[0], fvToListener[2]);
        if (pVoice->flm == 0) {
            while (fAngY < -3.1415927f) fAngY += 6.2831855f;
            while (fAngY >= 3.1415927f) fAngY -= 6.2831855f;
            pVoice->fAngleNoClip = fAngY;
        }
        while (fAngY < 0.0f) fAngY += 6.2831855f;
        while (fAngY >= 6.2831855f) fAngY -= 6.2831855f;
        fAngY = fAngY - pVoice->fAngleNoClip;
        while (fAngY < -3.1415927f) fAngY += 6.2831855f;
        while (fAngY >= 3.1415927f) fAngY -= 6.2831855f;
        if (fAngY < -0.3926991f) fAngY = -0.3926991f;
        if (fAngY > 0.3926991f) fAngY = 0.3926991f;
        pVoice->fAngleNoClip = pVoice->fAngleNoClip + fAngY;
        fPan = 1024.0f * ((1.5707964f + pVoice->fAngleNoClip) / 6.2831855f);
        while (fPan < -2048.0f) fPan += 4096.0f;
        while (fPan >= 2048.0f) fPan -= 4096.0f;
        pVoice->sPan = (short)fPan;
        if (*(u8 *)&((struct dw_1845925_fields *)g_pSndMng)->SndMode == 1) {
            while (pVoice->sPan < -0x200) pVoice->sPan += 0x400;
            while (pVoice->sPan >= 0x200) pVoice->sPan -= 0x400;
            pVoice->sPan = -(pVoice->sPan < 0 ? -pVoice->sPan : pVoice->sPan);
        } else {
            pVoice->sPan = -pVoice->sPan;
        }
    }
}

static signed int _SeKick_Assemble(void *a0) {
    struct SkVoice *pInVoice = (struct SkVoice *)a0;
    struct SkVoice *pVoice;
    int iVoiceMngId;
    int SeKind;
    int smartSS;
    struct SkBank *pBankInfo;
    struct SkParam *pParam;
    struct SkFade *pFade;

    if (pInVoice == 0) {
        return 0x51;
    }
    if (pInVoice->usSndId == 0xffff) {
        return 0x51;
    }
    if (_GetBankInfo(&SeKind, &smartSS, pInVoice->usSndId) == -1) {
        return 0x51;
    }
    pBankInfo = &((struct SkMng *)g_pSndMng)->aBankInfo[SeKind];
    pParam = &pBankInfo->aParam[smartSS];
    if (!(0 <= smartSS && smartSS <= pBankInfo->uiProgNum)) {
        return 0x51;
    }
    pVoice = (struct SkVoice *)_GetFreeVoice(&iVoiceMngId);
    if (pVoice == 0) {
        return 0x51;
    }
    pVoice->job = pInVoice->job;
    pVoice->SeKind = SeKind;
    pVoice->flm = 0;
    pVoice->type = pParam->ucLoop ? SkLoop_T : SkLoop_F;
    pVoice->sVolume = pInVoice->sVolume;
    pVoice->BankId = (*(struct SkMng **)&g_pSndMng)->Handle[SeKind];
    pVoice->bd_prog = smartSS;
    if (!(0 <= pVoice->BankId && pVoice->BankId <= 15)) {
        return 0x51;
    }
    pVoice->p_bend = pInVoice->p_bend;
    pFade = &((struct SkFade *)s_aFadeInfo)[iVoiceMngId];
    pFade->type = 0;
    pFade->scale = 1.0f;
    if (pInVoice->type != 1) {
        ((struct SkMng *)g_pSndMng)->ucVoiceCnt++;
        if (((struct SkMng *)g_pSndMng)->ucVoiceCnt >= 12) {
            return 0x51;
        }
    }
    _CalcPitch(pVoice);
    switch (pVoice->job) {
    case 0:
        pVoice->sCalcedVolume = (u8)(127.0f * ((float)pInVoice->sVolume * (float)((struct SkMng *)g_pSndMng)->ucSeVolume / 127.0f) / 127.0f);
        pVoice->sPan = -0x100;
        pVoice->vid = fssdsynthSeStreamOn(iVoiceMngId, pVoice->BankId, 0, pVoice->bd_prog, 0x3c, pVoice->sCalcedVolume, 0x3f, pVoice->p_bend);
        if (pVoice->vid < 0) {
            return 0x51;
        }
        pVoice->on = 1;
        break;
    case 1:
        pVoice->pPos = pInVoice->pPos;
        if (pVoice->pPos == 0) {
            fsvu0_CopyVectorF(pVoice->Pos, pInVoice->Pos);
            pVoice->pPos = (float (*)[4])pVoice->Pos;
        }
        pVoice->fDistMax = pInVoice->fDistMax;
        pVoice->fDistMin = g_fSndDefDistMin;
        _Pan((void *)pVoice);
        pVoice->vid = fssdsynthSeStreamOn_forSurround(iVoiceMngId, pVoice->BankId, 0, pVoice->bd_prog, 0x3c, pVoice->p_bend);
        if (pVoice->vid < 0) {
            return 0x51;
        }
        pVoice->on = 1;
        break;
    }
    return iVoiceMngId;
}






/* SND_Play2D @ 0x1AB8D0 .. 0x1AB914 (0x44 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1ab8e4 writes a register its branch at 0x1ab8e0 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




signed int SND_Play2D(signed int a0 /* r4 */, signed short a1 /* r5 */, signed short a2 /* r6 */) {
    u32 v0;
    u8 stackFrame_10[64] __attribute__((aligned(16)));

    v0 = g_pSndMng;
    v0 = *(u8 *)((v0 + 0xb0));
    if (v0 != 0) {
        return 0x51;
    }
    *(u16 *)((u8 *)&stackFrame_10[8]) = a0;
    *(u16 *)((u8 *)&stackFrame_10[20]) = a1;
    a0 = (signed int)((u8 *)&stackFrame_10[0]);
    *(u16 *)((u8 *)&stackFrame_10[28]) = a2;
    *(u8 *)((u8 *)&stackFrame_10[1]) = 0;
    v0 = _SeKick_Assemble((void *)a0);
    return v0;
}


/* SND_Play3DPoint @ 0x1AB840 .. 0x1AB8C4 (0x84 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1ab860 is a float copy
 *   stack: address of the slot at 0x50 escapes at 0x1ab898
 *   cfg: kept branch: 0x1ab850 if (..) goto .L001AB870
 *   cfg: kept goto: 0x1ab868 -> .L001AB8B0
 */


signed int SND_Play3DPoint(signed int a0 /* r4 */, signed short a1 /* r5 */, signed short a2 /* r6
        */, float *a3 /* r7 */, float f12 /* f12 */) {
    float f20;
    u32 v0;
    u8 stackFrame_50[32] __attribute__((aligned(16)));
    u8 stackFrame_30[32] __attribute__((aligned(16)));

    v0 = g_pSndMng;
    v0 = *(u8 *)((v0 + 0xb0));
    f20 = f12;
    if (v0 == 0) {
        goto _L001AB870;
    }
    v0 = 0x51;
    goto _L001AB8B0;
    _L001AB870:;
    if ((u32)a3 == 0) {
        v0 = 0x51;
        return v0;
    }
    ((u16 *)stackFrame_30)[10] = a1;
    ((u16 *)stackFrame_30)[4] = a0;
    v0 = 1;
    ((u8 *)stackFrame_30)[1] = v0;
    a0 = (signed int)((u8 *)&stackFrame_50[0]);
    ((u32 *)stackFrame_50)[4] = 0;
    fsvu0_CopyVectorF((float *)a0, (float *)a3);
    a0 = (signed int)((u8 *)&stackFrame_30[0]);
    ((u16 *)stackFrame_30)[14] = a2;
    ((f32 *)stackFrame_50)[5] = f20;
    v0 = _SeKick_Assemble((void *)a0);
    _L001AB8B0:;
    return v0;
}


/* SND_Play3D @ 0x1AB7D0 .. 0x1AB834 (0x64 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1ab7e4 writes a register its branch at 0x1ab7e0 reads
 */


u32 SND_Play3D(signed int a0 /* r4 */, signed short a1 /* r5 */, signed short a2 /* r6 */, void *a3
        /* r7 */, float f12 /* f12 */) {
    u32 v0;
    s32 branchcond_1ab7e0;
    u8 stackFrame[64] __attribute__((aligned(16)));

    v0 = g_pSndMng;
    v0 = *(u8 *)((v0 + 0xb0));
    branchcond_1ab7e0 = v0 == 0;
    v0 = 0x51;
    if (!branchcond_1ab7e0) {
        return v0;
    }
    v0 = 0x51;
    if ((u32)a3 == 0) {
        return v0;
    }
    v0 = 1;
    *(u16 *)((u8 *)&stackFrame[8]) = (s32)a0;
    *(f32 *)((u8 *)&stackFrame[52]) = (float)f12;
    *(u16 *)((u8 *)&stackFrame[20]) = (u16)a1;
    a0 = (signed int)((u8 *)&stackFrame[0]);
    *(u32 *)((u8 *)&stackFrame[48]) = (u32)a3;
    *(u8 *)((u8 *)&stackFrame[1]) = v0;
    *(u16 *)((u8 *)&stackFrame[28]) = (u16)a2;
    v0 = _SeKick_Assemble((void *)a0);
    return v0;
}











/* SND_Stop @ 0x1AB760 .. 0x1AB7CC (0x6c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1ab798 writes a register its branch at 0x1ab794 reads
 */


void SND_Stop(signed int a0 /* r4 */) {
    u32 v1;

    if ((s32)a0 < 0 || (s32)a0 >= (s32)0x40) {
        return;
    }
    a0 = (u32)a0 << 6;
    v1 = (u32)s_aVoice;
    a0 = (s32)((u8 *)s_aVoice + a0);
    v1 = *(s8 *)a0;
    if ((s32)v1 > 0) {
        *(s8 *)a0 = -1;
        *(u32 *)(((s32)(a0) + 0x3c)) = 0;
        a0 = *(s16 *)(((s32)(a0) + 0xe));
        if ((s32)a0 >= 0 && (s32)a0 < (s32)0x40) {
            fssdsynthSeStreamOff(a0);
        }
    }
    return;
}


/* SND_FadeStop @ 0x1AB710 .. 0x1AB760 (0x50 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1ab750 writes a register its branch at 0x1ab74c reads
 *   declaration vs inferred signature: return void vs inferred u32
 */


void SND_FadeStop(signed int a0 /* r4 */) {
    u32 v1;
    u32 a1;

    if ((s32)a0 < 0 || (s32)a0 >= (s32)0x40) {
        return;
    }
    a1 = (u32)a0 << 3;
    v1 = (u32)s_aFadeInfo;
    a1 = (s32)((u8 *)s_aFadeInfo + a1);
    v1 = (u32)s_aVoice;
    v1 = (s32)((u8 *)s_aVoice + (s32)((u32)a0 << 6));
    v1 = *(s8 *)v1;
    if ((s32)v1 > 0) {
        *(u32 *)a1 = 3;
    }
    return;
}





static void _CalcPitch(void *voice) {
    u8 *p = voice;
    u32 bank = *(u32 *)(p + 4);
    int channel = *(s16 *)(p + 12);
    float base = 0.08533333f * (float)*(u16 *)((channel = channel * 4, channel += (u32)(g_pSndMng + bank * 0x210)) + 0xc4);
    int cents = *(s16 *)(p + 0x1c);
    if (cents) {
        float octave = (float)cents / 1200.0f;
        if (octave < -2.0f) octave = -2.0f;
        if (!(octave <= 2.0f)) octave = 2.0f;
        if (octave < 0.0f) {
            *(s16 *)(p + 0x1c) = (int)(base / powf(2.0f, octave < 0.0f ? -octave : octave));
        } else {
            *(s16 *)(p + 0x1c) = (int)(base * powf(2.0f, octave < 0.0f ? -octave : octave));
        }
    } else *(s16 *)(p + 0x1c) = (int)base;
    if (*(s16 *)(p + 0x1c) < 0) *(s16 *)(p + 0x1c) = 0;
    if (*(s16 *)(p + 0x1c) > 0x3fff) *(s16 *)(p + 0x1c) = 0x3fff;
}





static signed int _GetBankInfo(signed int *pBankNo, signed int *pBankInId, signed int iSndId) {
    int i;
    int SeKind;
    int iBreak;
    int idx;
    int iSeNum;

    iBreak = 0;

    if (pBankNo == 0) return -1;
    if (pBankInId == 0) return -1;

    if (iSndId >= 10000) {
        int iGrp = iSndId - 10000;
        if (0 > iGrp || iGrp >= (int)s_iSeGroupNum) {
            return -1;
        }
        for (iSeNum = 0; iSeNum < 7; iSeNum++) {
            if ((*(struct SeGroupInfo **)&s_aSeGroup)[iGrp].aSeId[iSeNum] == 0xffff) break;
        }
        if (iSeNum <= 0) return -1;
        idx = rand() % iSeNum;
        if (idx == *(u8 *)(s_aucGrpLastOn + (iSndId - 10000))) {
            idx = (idx + 1) % iSeNum;
        }
        *(u8 *)(s_aucGrpLastOn + (iSndId - 10000)) = idx;
        iSndId = (*(struct SeGroupInfo **)&s_aSeGroup)[iGrp].aSeId[idx];
    }

    for (SeKind = 0; SeKind < 12; SeKind++) {
        for (i = 0; i < 0x80; i++) {
            if (((struct SndMngBankTbl *)g_pSndMng)->bank[SeKind][i] == 0xffff) break;
            if (((struct SndMngBankTbl *)g_pSndMng)->bank[SeKind][i] == iSndId) {
                iBreak = 1;
                break;
            }
        }
        if (iBreak) break;
    }

    if (0 > SeKind || SeKind >= 12) return -1;

    *pBankNo = SeKind;
    *pBankInId = i;
    return 0;
}


/* _GetFreeVoice @ 0x1AB270 .. 0x1AB368 (0xf8 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001AB290
 *   cfg: loop body is not one contiguous region: .L001AB300
 *   declaration vs inferred signature: return void * vs inferred u32
 */


static void * _GetFreeVoice(signed int *a0 /* r4 */) {
    int a2;
    int a1;
    int v1;
    int v0;

    a2 = s_iNextVoice;
    v0 = (u32)s_aVoice;
    a1 = a2;
    v0 = (s32)((u8 *)s_aVoice + (u32)(a2 << 6));
    if ((s32)a2 < (s32)0x40) {
        do {
            v1 = *(s8 *)v0;
            if (v1 == 0) {
                s_iNextVoice += 1;
                v1 = s_iNextVoice;
                if ((u32)((s32)v1 < (s32)0x40) == 0) {
                    s_iNextVoice = 0;
                }
                if ((u32)a0 != 0) {
                    *(u32 *)a0 = a1;
                }
                return (void *)v0;
            }
            a1 = a1 + 1;
            v1 = (s32)a1 < (s32)0x40;
            v0 = v0 + 0x40;
        } while (v1 != 0);
    }
    v0 = (u32)s_aVoice;
    a1 = 0;
    if (0 < (s32)a2) {
        do {
            v1 = *(s8 *)v0;
            if (v1 == 0) {
                s_iNextVoice += 1;
                v1 = s_iNextVoice;
                if ((u32)((s32)v1 < (s32)0x40) == 0) {
                    s_iNextVoice = 0;
                }
                if ((u32)a0 != 0) {
                    *(u32 *)a0 = a1;
                }
                return (void *)v0;
            }
            a1 = a1 + 1;
            v1 = (s32)a1 < (s32)a2;
            v0 = v0 + 0x40;
        } while (v1 != 0);
    }
    return (void *)(u32)0;
}


/* SND_LoadRandSeFromFile @ 0x1AB220 .. 0x1AB264 (0x44 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int SND_LoadRandSeFromFile(char *a0 /* r4 */) {
    u32 v0;

    if ((u32)a0 == 0) {
        v0 = -1;
    } else {
        FileRead(a0, -1, (unsigned char **)&pDmy_1206, 0, 0, 0x21, 0);
        v0 = 0;
    }
    return v0;
}








/* SND_LoadRandSeFromFileInMemory @ 0x1AB120 .. 0x1AB220 (0x100 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: __FUNCTION__$1209 is the string 'SND_LoadRandSeFromFileInMemory'
 *   literal: @1278 is the string ''
 *   cfg: loop body is not one contiguous region: .L001AB158
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int SND_LoadRandSeFromFileInMemory(void *a0 /* r4 */) {
    u16 *s1;
    u32 v0;
    s32 s0;
    u32 a1;
    u32 v1;
    s32 s2;
    u32 a2;

    s1 = (u16 *)a0;
    if ((u32)s1 == 0) {
        v0 = -1;
    } else {
        s0 = 0;
        a1 = 0;
        v1 = 0xffff;
        do {
            v0 = *(u16 *)(((u8 *)a0 + 2));
            if (v0 == v1) {
                break;
            }
            a1 = a1 + 1;
            s0 = s0 + 1;
            v0 = (s32)a1 < (s32)0x2000;
            a0 = (void *)(s32)((u8 *)a0 + 0x10);
        } while (v0 != 0);
        a0 = (void *)s_aSeGroup;
        if ((u32)(s32)a0 != 0) {
            MemFree(a0);
        }
        a0 = (void *)s_aucGrpLastOn;
        if ((u32)(s32)a0 != 0) {
            MemFree(a0);
        }
        s2 = (u32)s0 << 4;
        a2 = (u32)((char *)__FUNCTION__);
        v0 = (u32)MemAllocAlignReal((u32)s2, (u32)0x10, ((char *)__FUNCTION__), "");
        s_aSeGroup = v0;
        a1 = (u32)((char *)__FUNCTION__);
        a2 = (u32)"";
        v0 = (u32)MemAllocReal((u32)s0, ((char *)__FUNCTION__), "");
        a0 = (void *)s_aSeGroup;
        a2 = s2;
        s_aucGrpLastOn = v0;
        memcpy((s32)a0, (u32)s1, a2);
        a0 = (void *)s1;
        s_iSeGroupNum = s0;
        MemFree(a0);
        v0 = 0;
    }
    return v0;
}







/* SND_SetLoopSeVolumeScale @ 0x1AB110 .. 0x1AB118 (0x8 bytes) */

void SND_SetLoopSeVolumeScale(float f12 /* f12 */) {
    s_fLoopSndVolumeScale = (float)f12;
    return;
}
