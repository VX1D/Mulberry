#include "common.h"

/* Named strings preserve the original pool order without sharing a CSE base. */
static const char sLfsPathFmt[8] __attribute__((section(".rodata"), aligned(8))) = "%s%s";
static const char sLfsListSep[8] __attribute__((section(".rodata"), aligned(8))) = ",=\n";
static const char sLfsCr[8] __attribute__((section(".rodata"), aligned(8))) = "\r";
static const char sLfsNl[8] __attribute__((section(".rodata"), aligned(8))) = "\n";
static const char sLfsFogFmt[16] __attribute__((section(".rodata"), aligned(8))) = "%d, %d, %f";
static const char sLfsSep[8] __attribute__((section(".rodata"), aligned(8))) = "=\n";
static const char sLfsFclip[32] __attribute__((section(".rodata"), aligned(8))) = "SPRITE_ALPHACTRL_FCLIP";
static const char sLfsNclip[32] __attribute__((section(".rodata"), aligned(8))) = "SPRITE_ALPHACTRL_NCLIP";
static const char sLfsPower[32] __attribute__((section(".rodata"), aligned(8))) = "SPRITE_ALPHACTRL_POWER";
static const char sLfsLowAlpha[32] __attribute__((section(".rodata"), aligned(8))) = "SPRITE_LOWALPHA_LIMIT";
static const char sLfsFog[32] __attribute__((section(".rodata"), aligned(8))) = "[DRAMA_FOGSPHERE]";
static const char sLfsInhibit[24] __attribute__((section(".rodata"), aligned(8))) = "[INHIBIT_REFLECT]";

/* _LoadFile_Setting @ 0x1C3B50 */
extern char * strtok(char *, const char *);
extern unsigned int strlen(const char *);
extern int strncmp(const char *, const char *, unsigned int);
extern double atof(const char *);
extern int strcmp(const char *, const char *);
extern int sscanf(const char *, const char *, ...);
extern void SfxFog_AddDramaSetting(unsigned short, unsigned short, float);
extern void * memset(void *, int, unsigned int);
extern int atoi(const char *);
extern void SFX_SetSettingData(void *);

typedef struct { float st_fclip; float st_nclip; float st_power; float st_lowalpha; unsigned char st_inhibit[0x400]; } LFS_SETTING;

/* SfxFIO_CallBack_FinishLoadSfxBindFile @ 0x1C3E60 .. 0x1C3E88 (0x28 bytes, frame 0x10) */

extern signed int SfxFIO_CheckLoadSfxBindFile(void);
extern signed int SFX_Initialize_LoadFinish_CallBack(void);
extern u16 s_SfxBndFile_LoadState;

static u16 s_num_sfxm;
static u32 s_pFileData_Texture;
static u32 s_pFileData_Ptcl;
static u32 s_pFileData_Sfx;
static u32 s_pBindHead;
/* SfxFIO_CheckLoadSfxBindFile @ 0x1C3E90 .. 0x1C4148 (0x2b8 bytes, frame 0x170) */
/*
 * dcomp notes:
 *   literal: @1211 is the string 'Sfx.bnd'
 *   literal: @1212 is the string 'Ptcl.bnd'
 *   literal: @1213 is the string 'SfxSetting.txt'
 *   literal: @1214 is the string 'Static.tex'
 *   literal: @1215 is the string 'sfxm'
 *   literal: @1216 is the string 'sfxt'
 *   literal: @1219 -> 0x255700
 *   literal: @1217 is the string 'SfxFileIO.c'
 *   literal: @1218 is the string 'Unknown Filetype'
 *   delay: addiu at 0x1c3eb8 writes a register its branch at 0x1c3eb4 reads
 *   indirect: jr v0 at 0x1c3ff8 -> <v0>
 *   stack: address of the slot at 0x168 escapes at 0x1c4044
 *   stack: address of the slot at 0x60 escapes at 0x1c40e0
 *   stack: address of the slot at 0x60 escapes at 0x1c40f8
 *   cfg: loop body is not one contiguous region: .L001C3F00
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void RemapBinderFile(void *);
extern unsigned int GetBindNum(void *);
extern int strcmp(const char *, const char *);
extern int strncmp(const char *, const char *, unsigned int);
extern u32 GetBindOffsetByIndex();
extern char * strncpy(char *, const char *, unsigned int);
extern int atoi(const char *);
extern void SetMdlBndFile(signed int);
static signed int _LoadFile_Setting(char *);
extern void RemapMdlLink(void *);
extern void SetTexList(void *, unsigned int);
extern char * strcpy(char *, const char *);
extern void SfxDbg_SetDebugMsg(unsigned char, char *, char *, unsigned int);
extern struct dw_2058487_fields MdlData[];

#ifndef PROTO_DW_2060872_FIELDS
#define PROTO_DW_2060872_FIELDS
struct dw_2060872_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_2058487_FIELDS
#define PROTO_DW_2058487_FIELDS
struct dw_2058487_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_2060872_fields DmyPoly[32]; };
#endif

struct SfxBndOfs { u32 unk; void *pData; char *pName; };



/* SfxFIO_StartLoadSfxBindFile @ 0x1C4150 .. 0x1C41C4 (0x74 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   literal: @1032 is the string '%s%s'
 *   stack: address of the slot at 0x10 escapes at 0x1c416c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern int sprintf(void *, void *, ...);
extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);
extern u32 s_szSfxFolderPath[];
extern u32 s_pBindHead;

/* SfxFIO_GetPtclDataNum @ 0x1C41D0 .. 0x1C41DC (0xc bytes) */
/*
 * dcomp notes:
 *   return: lhu at 0x1c41d8 computes the return value
 */

extern u32 s_pFileData_Ptcl;

/* SfxFIO_GetSfxDataNum @ 0x1C41E0 .. 0x1C41EC (0xc bytes) */
/*
 * dcomp notes:
 *   return: lhu at 0x1c41e8 computes the return value
 */

extern u32 s_pFileData_Sfx;

/* SfxFIO_GetTextureFile_Data @ 0x1C41F0 .. 0x1C41F8 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1c41f4 computes the return value
 */

extern u32 s_pFileData_Texture;

/* SfxFIO_GetPtclDataFile_Data @ 0x1C4200 .. 0x1C420C (0xc bytes) */
/*
 * dcomp notes:
 *   tail: j GetBindOffsetByIndex at 0x1c4204 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 GetBindOffsetByIndex();
extern u32 s_pFileData_Ptcl;

/* SfxFIO_GetSfxDataFile_Data @ 0x1C4210 .. 0x1C421C (0xc bytes) */
/*
 * dcomp notes:
 *   tail: j GetBindOffsetByIndex at 0x1c4214 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern u32 GetBindOffsetByIndex();
extern u32 s_pFileData_Sfx;
static u32 s_szSfxFolderPath[0x8] = {
    0x2f786653
};
static u16 s_num_sfxm;
static u32 s_pFileData_Texture;
static u32 s_pFileData_Ptcl;
static u32 s_pFileData_Sfx;
static u32 s_pBindHead;
static u16 s_SfxBndFile_LoadState;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SfxFIO_GetSfxDataFile_Data(void);
void SfxFIO_GetPtclDataFile_Data(void);
u32 SfxFIO_GetTextureFile_Data(void);
u16 SfxFIO_GetSfxDataNum(void);
u16 SfxFIO_GetPtclDataNum(void);
signed int SfxFIO_StartLoadSfxBindFile(char *a0 );
signed int SfxFIO_CheckLoadSfxBindFile(void);
void SfxFIO_CallBack_FinishLoadSfxBindFile(void);
static signed int _LoadFile_Setting(char *pFileData_);


void SfxFIO_GetSfxDataFile_Data(void) {
    u32 a0;

    a0 = s_pFileData_Sfx;
    GetBindOffsetByIndex(a0, 0);
    return;
}

void SfxFIO_GetPtclDataFile_Data(void) {
    u32 a0;

    a0 = s_pFileData_Ptcl;
    GetBindOffsetByIndex(a0, 0);
    return;
}

u32 SfxFIO_GetTextureFile_Data(void) {
    return s_pFileData_Texture;
}

u16 SfxFIO_GetSfxDataNum(void) {
    u16 *v0;

    v0 = (u16 *)s_pFileData_Sfx;
    return *(u16 *)(((u8 *)v0 + 0xc));
}

u16 SfxFIO_GetPtclDataNum(void) {
    u16 *v0;

    v0 = (u16 *)s_pFileData_Ptcl;
    return *(u16 *)(((u8 *)v0 + 0xc));
}

signed int SfxFIO_StartLoadSfxBindFile(char *a0 /* r4 */) {
    u8 *a2;
    u32 a1;
    s32 v0;
    u8 stackFrame_10[64] __attribute__((aligned(16)));

    a1 = (u32)sLfsPathFmt;
    a2 = (u8 *)s_szSfxFolderPath;
    sprintf((void *)((u8 *)&stackFrame_10[0]), (void *)sLfsPathFmt, s_szSfxFolderPath, (u32)a0);
    a1 = -1;
    a2 = (u8 *)&s_pBindHead;
    v0 = FileRead((char *)((u8 *)&stackFrame_10[0]), a1, (unsigned char **)&s_pBindHead, 0, a1,
        0x1b, 0x10);
    if (0 <= v0) {
        v0 = s_pBindHead;
    } else {
        v0 = 0;
    }
    s_pBindHead = v0;
    v0 = 1;
    s_SfxBndFile_LoadState = v0;
    return v0;
}





signed int SfxFIO_CheckLoadSfxBindFile(void) {
    unsigned int i;
    unsigned int file_num;
    struct SfxBndOfs *pOffset;
    char *pszFilename;
    unsigned short file_type;
    char szFile[256];
    char szNum[8];
    signed int ret;

    if (s_SfxBndFile_LoadState == 3) {
        ret = 1;
    } else if (s_SfxBndFile_LoadState == 2) {
        RemapBinderFile((void *)s_pBindHead);
        file_num = GetBindNum((void *)s_pBindHead);
        pOffset = (struct SfxBndOfs *)(s_pBindHead + 0x10);
        for (i = 0; i < file_num; i++) {
            pszFilename = pOffset->pName;
            file_type = 0xffff;
            if (strcmp(pszFilename, "Sfx.bnd") == 0) {
                file_type = 0;
            } else if (strcmp(pszFilename, "Ptcl.bnd") == 0) {
                file_type = 1;
            } else if (strcmp(pszFilename, "SfxSetting.txt") == 0) {
                file_type = 4;
            } else if (strcmp(pszFilename, "Static.tex") == 0) {
                file_type = 5;
            } else if (strncmp(pszFilename, "sfxm", 4) == 0) {
                file_type = 2;
            } else if (strncmp(pszFilename, "sfxt", 4) == 0) {
                file_type = 3;
            }
            switch (file_type) {
            case 0: {
                void *pData = pOffset->pData;
                RemapBinderFile(pData);
                s_pFileData_Sfx = (u32)pData;
                break;
            }
            case 1: {
                void *pData = pOffset->pData;
                RemapBinderFile(pData);
                GetBindOffsetByIndex(pData, 0);
                s_pFileData_Ptcl = (u32)pData;
                break;
            }
            case 2: {
                void *pData = pOffset->pData;
                u32 no;
                strncpy(szNum, pszFilename + 4, 3);
                no = (u16)atoi(szNum) + 0x8c;
                MdlData[no].lpBndFile = pData;
                RemapBinderFile(pData);
                SetMdlBndFile(no);
                s_num_sfxm++;
                break;
            }
            case 4:
                _LoadFile_Setting((char *)pOffset->pData);
                break;
            case 5: {
                void *pData = pOffset->pData;
                s_pFileData_Texture = (u32)pData;
                RemapMdlLink(pData);
                SetTexList(pData, 2);
                break;
            }
            default:
                strcpy(szFile, (const char *)(void *)"SfxFileIO.c");
                SfxDbg_SetDebugMsg(0, "Unknown Filetype", szFile, 0xb5);
            case 3:
                break;
            }
            pOffset++;
        }
        s_SfxBndFile_LoadState = 3;
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

/* SfxFIO_CallBack_FinishLoadSfxBindFile @ 0x1C3E60 .. 0x1C3E88 (0x28 bytes, frame 0x10) */
void SfxFIO_CallBack_FinishLoadSfxBindFile(void) {
    s_SfxBndFile_LoadState = 2;
    SfxFIO_CheckLoadSfxBindFile();
    SFX_Initialize_LoadFinish_CallBack();
    return;
}

static signed int _LoadFile_Setting(char *pFileData_) {
    unsigned char *pInh;
    LFS_SETTING setting;
    char *token;

    token = strtok(pFileData_, sLfsSep);
    setting.st_fclip = 25.0f;
    setting.st_nclip = 5.0f;
    setting.st_power = 0.3f;
    setting.st_lowalpha = 0.0f;
    if (token != 0) {
        pInh = setting.st_inhibit;
        do {
            if (strncmp(token, sLfsFclip, strlen(sLfsFclip)) == 0) {
                setting.st_fclip = atof(strtok(0, sLfsSep));
            } else if (strncmp(token, sLfsNclip, strlen(sLfsNclip)) == 0) {
                setting.st_nclip = atof(strtok(0, sLfsSep));
            } else if (strncmp(token, sLfsPower, strlen(sLfsPower)) == 0) {
                setting.st_power = atof(strtok(0, sLfsSep));
            } else if (strncmp(token, sLfsLowAlpha, strlen(sLfsLowAlpha)) == 0) {
                setting.st_lowalpha = atof(strtok(0, sLfsSep));
            } else if (strncmp(token, sLfsFog, strlen(sLfsFog)) == 0) {
                while (1) {
                    int ia;
                    int ib;
                    float fc;
                    token = strtok(0, sLfsNl);
                    if (strcmp(token, sLfsCr) == 0) break;
                    sscanf(token, sLfsFogFmt, &ia, &ib, &fc);
                    SfxFog_AddDramaSetting(ia, ib, fc);
                }
            } else if (strncmp(token, sLfsInhibit, strlen(sLfsInhibit)) == 0) {
                memset(pInh, 1, 0x400);
                token = strtok(0, sLfsListSep);
                while (token != 0) {
                    if (strcmp(token, sLfsCr) == 0) break;
                    setting.st_inhibit[atoi(token)] = 0;
                    token = strtok(0, sLfsListSep);
                }
            }
            token = strtok(0, sLfsSep);
        } while (token != 0);
    }
    SFX_SetSettingData(&setting);
    return 1;
}
