#include "common.h"

/* LoadDebugParam @ 0x1348B0 .. 0x134C80 (0x3d0 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: __FUNCTION__$1033 is the string 'LoadDebugParam'
 *   literal: @1297 is the string ''
 *   literal: @1298 is the string 'debug/DbgPrm.dpr'
 */

extern void * MemAllocReal(unsigned int, char *, char *);
extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);
extern void * memcpy(void *, const void *, unsigned int);
extern void MemFree(void *);

#ifndef PROTO_DW_75175_FIELDS
#define PROTO_DW_75175_FIELDS
struct dw_75175_fields { unsigned char Num; unsigned char Length; unsigned char unused[2]; float Speed; float RangeDiff; float RangeMin; float RangeMax; float SizeDiff; float SizeMin; float SizeMax; unsigned char ColorRMax; unsigned char ColorRMin; unsigned char ColorGMax; unsigned char ColorGMin; unsigned char ColorBMax; unsigned char ColorBMin; unsigned char ColorAMax; unsigned char ColorAMin; };
#endif
#ifndef PROTO_DW_73742_FIELDS
#define PROTO_DW_73742_FIELDS
struct dw_73742_fields { unsigned char Type[2]; unsigned char Wave[2]; float Speed[2]; float Amplitude[2]; float SinSpeed[2]; float SinAmplitude[2]; float SinWavelength[2]; };
#endif
#ifndef PROTO_DW_73295_FIELDS
#define PROTO_DW_73295_FIELDS
struct dw_73295_fields { unsigned char Threshold[3]; unsigned char Rate; };
#endif
#ifndef PROTO_DW_74537_FIELDS
#define PROTO_DW_74537_FIELDS
struct dw_74537_fields { unsigned int FileVersion; unsigned int FileSize; struct dw_75175_fields DizzyEffect; struct dw_73742_fields TexScroll[32]; float AmbientColor[32][4]; struct dw_73295_fields GlareInfo[32]; };
#endif


extern void *lpDebugParam;
struct dw_75175 { unsigned char Num; unsigned char Length; unsigned char unused[2]; float Speed; float RangeDiff; float RangeMin; float RangeMax; float SizeDiff; float SizeMin; float SizeMax; unsigned char ColorRMax; unsigned char ColorRMin; unsigned char ColorGMax; unsigned char ColorGMin; unsigned char ColorBMax; unsigned char ColorBMin; unsigned char ColorAMax; unsigned char ColorAMin; };
struct dw_74996 { unsigned char Type[2]; unsigned char unused[2]; float Speed[2]; float Amplitude[2]; };
struct dw_73742 { unsigned char Type[2]; unsigned char Wave[2]; float Speed[2]; float Amplitude[2]; float SinSpeed[2]; float SinAmplitude[2]; float SinWavelength[2]; };
struct dw_73295 { unsigned char Threshold[3]; unsigned char Rate; };
struct dw_73471 { unsigned int FileVersion; unsigned int FileSize; struct dw_75175 DizzyEffect; struct dw_74996 TexScroll[32]; float AmbientColor[32][4]; };
struct dw_74537 { unsigned int FileVersion; unsigned int FileSize; struct dw_75175 DizzyEffect; struct dw_73742 TexScroll[32]; float AmbientColor[32][4]; struct dw_73295 GlareInfo[32]; };
#define DBGP ((struct dw_74537 *)lpDebugParam)


/* ResetDebug @ 0x134C80 .. 0x134C90 (0x10 bytes) */
/*
 * dcomp notes:
 *   repo declaration vs inferred signature: return void vs inferred u32
 */

extern u16 DebugSystem[];
static u16 DebugSystem[0x20];
void *lpDebugParam;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void ResetDebug(void);
void LoadDebugParam(void);


void ResetDebug(void) {
    *(u16 *)((u8 *)&DebugSystem + 0x24) = 3;
    return;
}

void LoadDebugParam(void) {
    int FileSize;
    void *lpReadFile;
    struct dw_73471 *lpOldParam;
    void *rf;

    lpDebugParam = MemAllocReal(0x830, (char *)__FUNCTION__, "");
    FileSize = FileRead("debug/DbgPrm.dpr", -1, (unsigned char **)&lpReadFile, 1, -1, 0x13, 0);
    if (FileSize > 0) {
        if ((u32)FileSize > 0x830) FileSize = 0x830;
        rf = lpReadFile;
        if (((struct dw_73471 *)rf)->FileVersion >= 0x400) {
            memcpy(lpDebugParam, rf, FileSize);
        } else {
            DBGP->FileVersion = ((struct dw_73471 *)rf)->FileVersion;
            DBGP->FileSize = ((struct dw_73471 *)rf)->FileSize;
            lpOldParam = (struct dw_73471 *)rf;
            if (DBGP->FileVersion >= 0x100) {
                memcpy(&DBGP->DizzyEffect, &lpOldParam->DizzyEffect, sizeof(struct dw_75175));
            }
            {
            struct dw_74996 *lpOldScroll;
            struct dw_73742 *lpNewScroll;
            int i;
            if (DBGP->FileVersion >= 0x200) {
                lpNewScroll = DBGP->TexScroll;
                lpOldScroll = lpOldParam->TexScroll;
                i = 0;
                do {
                    lpNewScroll->Type[0] = lpOldScroll->Type[0];
                    lpNewScroll->Speed[0] = lpOldScroll->Speed[0];
                    lpNewScroll->Amplitude[0] = lpOldScroll->Amplitude[0];
                    lpNewScroll->Type[1] = lpOldScroll->Type[1];
                    lpNewScroll->Speed[1] = lpOldScroll->Speed[1];
                    lpNewScroll->Amplitude[1] = lpOldScroll->Amplitude[1];
                    i++;
                    lpOldScroll++;
                    lpNewScroll++;
                } while (i < 32);
            }
            }
            if (DBGP->FileVersion >= 0x300) {
                memcpy(DBGP->AmbientColor, lpOldParam->AmbientColor, sizeof(DBGP->AmbientColor));
            }
        }
        MemFree(lpReadFile);
    } else {
        DBGP->FileVersion = 0;
    }
    if (DBGP->FileVersion < 0x100) {
        DBGP->DizzyEffect.Num = 0x1e;
        DBGP->DizzyEffect.Length = 0x1e;
        DBGP->DizzyEffect.Speed = 1.0f;
        DBGP->DizzyEffect.RangeDiff = 2.0f;
        DBGP->DizzyEffect.RangeMin = 150.0f;
        DBGP->DizzyEffect.RangeMax = 300.0f;
        DBGP->DizzyEffect.SizeDiff = 2.0f;
        DBGP->DizzyEffect.SizeMin = 5.0f;
        DBGP->DizzyEffect.SizeMax = 50.0f;
        DBGP->DizzyEffect.ColorRMax = 0x80;
        DBGP->DizzyEffect.ColorRMin = 0x40;
        DBGP->DizzyEffect.ColorGMax = 0x20;
        DBGP->DizzyEffect.ColorGMin = 0x10;
        DBGP->DizzyEffect.ColorBMax = 0x60;
        DBGP->DizzyEffect.ColorBMin = 0x30;
        DBGP->DizzyEffect.ColorAMax = 0xa;
        DBGP->DizzyEffect.ColorAMin = 5;
        DBGP->DizzyEffect.unused[0] = 0;
        DBGP->DizzyEffect.unused[1] = 0;
    }
    if (DBGP->FileVersion < 0x200) {
        struct dw_73742 *lpTexScroll;
        for (lpTexScroll = DBGP->TexScroll; lpTexScroll < &DBGP->TexScroll[32]; lpTexScroll++) {
            lpTexScroll->Type[0] = 0;
            lpTexScroll->Type[1] = 0;
            lpTexScroll->Speed[0] = 0;
            lpTexScroll->Speed[1] = 0;
            lpTexScroll->Amplitude[0] = 1.0f;
            lpTexScroll->Amplitude[1] = 1.0f;
        }
    }
    if (DBGP->FileVersion < 0x300) {
        float (*lpAmbient)[4];
        for (lpAmbient = DBGP->AmbientColor; lpAmbient < &DBGP->AmbientColor[32]; lpAmbient++) {
            (*lpAmbient)[0] = 0.5f;
            (*lpAmbient)[1] = 0.5f;
            (*lpAmbient)[2] = 0.5f;
            (*lpAmbient)[3] = 1.0f;
        }
    }
    if (DBGP->FileVersion < 0x400) {
        struct dw_73742 *lpTexScroll;
        for (lpTexScroll = DBGP->TexScroll; lpTexScroll < &DBGP->TexScroll[32]; lpTexScroll++) {
            lpTexScroll->Wave[0] = 0;
            lpTexScroll->Wave[1] = 0;
            lpTexScroll->SinSpeed[0] = 0.01f;
            lpTexScroll->SinSpeed[1] = 0.01f;
            lpTexScroll->SinAmplitude[0] = 0.1f;
            lpTexScroll->SinAmplitude[1] = 0.1f;
            lpTexScroll->SinWavelength[0] = 1.0f;
            lpTexScroll->SinWavelength[1] = 1.0f;
        }
    }
    if (DBGP->FileVersion < 0x500) {
        struct dw_73295 *lpGlareInfo;
        for (lpGlareInfo = DBGP->GlareInfo; lpGlareInfo < &DBGP->GlareInfo[32]; lpGlareInfo++) {
            lpGlareInfo->Threshold[0] = 0x80;
            lpGlareInfo->Threshold[1] = 0x80;
            lpGlareInfo->Threshold[2] = 0x80;
            lpGlareInfo->Rate = 0x40;
        }
    }
}
