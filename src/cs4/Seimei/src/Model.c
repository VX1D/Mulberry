#include "common.h"
extern void sceVu0CopyMatrix();
extern float Math_VectorToAngle(float, float);
extern u32 MdlPacketMemID;
extern u32 lpMdlPacketMem;
extern u32 MdlPacketMem[];
extern void FreeMdlMng(void *);
extern u8 MdlMng[];
extern void MemFree(void *);
extern void FreeTexList(void *);
extern void *memset();
extern u8 GameSt[];
extern u16 MdlData[];
extern void ReadBinderFile(char *, void **, signed int, signed int);
signed int GetMdlCtrlId(void *a0 /* r4 */);
void * GetDummyPolyData(void *a0 /* r4 */, unsigned char a1 /* r5 */, unsigned char a2 /* r6 */);
void SetModelWorldMatrix(u8 *a0 /* r4 */);
void SetModelTargetToModel(void *a0 /* r4 */, void *a1 /* r5 */);
void SetModelTargetToPos(void *a0 /* r4 */, float *a1 /* r5 */);
signed int GetClothDataId(void *a0 /* r4 */);
void SetMdlFade(u8 *a0 /* r4 */, s32 a1 /* r5 */, float f12 /* f12 */);
u8 * ResetMdlPacketMem(void);
void FreeAllMdlMng(void);
void FreeMdlData(void *a0 /* r4 */, signed int a1 /* r5 */);
static void SetMdlType(void *a0 /* r4 */);
void ReadMdlBndFile(char *a0 /* r4 */, signed int a1 /* r5 */, void *a2 /* r6 */);
u8 * InitMdlMng(void);

/* InitMdlMng @ 0x13D0D0 .. 0x13D118 (0x48 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u8 * InitMdlMng(void) {
    u8 *a0;
    u8 *v1;

    a0 = (u8 *)MdlMng;
    v1 = (u8 *)MdlMng + 0x54000;
    do {
        *(u8 *)a0 = 0;
        *(u8 *)(((u8 *)a0 + 0x1c0)) = 0;
        *(u8 *)(((u8 *)a0 + 0x380)) = 0;
        *(u8 *)(((u8 *)a0 + 0x540)) = 0;
        *(u8 *)(((u8 *)a0 + 0x700)) = 0;
        *(u8 *)(((u8 *)a0 + 0x8c0)) = 0;
        *(u8 *)(((u8 *)a0 + 0xa80)) = 0;
        *(u8 *)(((u8 *)a0 + 0xc40)) = 0;
        a0 = (u8 *)a0 + 0xe00;
    } while ((u32)(a0) != (u32)(v1));
    *(u8 *)a0 = 0;
    *(u8 *)(((u8 *)a0 + 0x1c0)) = 0;
    return;
}


/* ReadMdlBndFile @ 0x13D060 .. 0x13D0CC (0x6c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   a0 forwarded to ReadBinderFile
 */


void ReadMdlBndFile(char *a0 /* r4 */, signed int a1 /* r5 */, void *a2 /* r6 */) {
    u32 v0;
    s32 a3;

    v0 = (u32)MdlData;
    a3 = (s32)a1;
    v0 = (s32)((u8 *)MdlData + (s32)((u32)((u32)a1) * (u32)(0x680)));
    if ((u32)a2 == 0) {
        a2 = (void *)a3;
        a1 = (s32)(v0 + 0x30);
        ReadBinderFile(a0, (void **)a1, (signed int)a2, 0);
    } else {
        *(u32 *)((v0 + 0x30)) = (s32)a2;
        a2 = (void *)a3;
        a1 = (s32)(v0 + 0x30);
        a3 = 0x80;
        ReadBinderFile(a0, (void **)a1, (signed int)a2, a3);
    }
    return;
}



/* SetMdlBndFile @ 0x13CD90 .. 0x13D054 (0x2c4 bytes, frame 0x30) */
extern unsigned int GetBindOffsetByIndex(void *, unsigned short);
extern void RemapMdlLink(void *);
extern void SetTexList(void *, unsigned int);
void SetMdlData(signed int a0 /* r4 */, void *a1 /* r5 */);
extern void SetAniData(signed int, void *);
extern void SetHdlData(signed int, void *);
extern void SetSdlData(signed int, void *);
extern void * MemAllocReal(unsigned int, char *, char *);

static inline u32 RemakeTexPacket(u32 size);
static inline u32 RemakeMdlPacket(u32 size);

extern void SetMdlTexListPacket(void *);
extern void SetVmdData(void *);
extern void SetSmdData(void *);
extern u32 FrdFixTexPacketBuf[];
extern u32 FrdFixMdlPacketBuf[];

void SetMdlBndFile(signed int a0 /* r4 */) {
    s32 s1;
    u32 a2;
    u32 a1;
    u8 *s0;
    u32 v1;
    u32 v0;

    s1 = a0;
    s0 = (u8 *)((u8 *)MdlData + (u32)a0 * 0x680);
    a0 = *(s32 *)(s0 + 0x30);
    a1 = 1;
    v0 = GetBindOffsetByIndex((void *)a0, a1);
    *(u32 *)(s0 + 0x44) = v0;
    a0 = *(s32 *)(s0 + 0x44);
    RemapMdlLink((void *)a0);
    a0 = *(s32 *)(s0 + 0x44);
    SetTexList((void *)a0, 1);
    a0 = *(s32 *)(s0 + 0x30);
    v0 = GetBindOffsetByIndex((void *)a0, 0);
    *(u32 *)(s0 + 0x34) = v0;
    a0 = *(s32 *)(s0 + 0x34);
    RemapMdlLink((void *)a0);
    a1 = *(s32 *)(s0 + 0x34);
    a0 = (s32)s1;
    SetMdlData(a0, (void *)a1);
    v1 = *(s32 *)(s0 + 0x34);
    if (v1 != 0) {
        a0 = *(s32 *)(s0 + 0x30);
        a1 = 2;
        v0 = GetBindOffsetByIndex((void *)a0, a1);
        *(u32 *)(s0 + 0x38) = v0;
        a0 = *(s32 *)(s0 + 0x38);
        RemapMdlLink((void *)a0);
        a1 = *(s32 *)(s0 + 0x38);
        a0 = s1;
        SetAniData(a0, (void *)a1);
        a0 = *(s32 *)(s0 + 0x30);
        a1 = 3;
        v0 = GetBindOffsetByIndex((void *)a0, a1);
        *(u32 *)(s0 + 0x3c) = v0;
        a0 = *(s32 *)(s0 + 0x3c);
        RemapMdlLink((void *)a0);
        a1 = *(s32 *)(s0 + 0x3c);
        a0 = s1;
        SetHdlData(a0, (void *)a1);
        v0 = *(s32 *)((*(s32 *)(s0 + 0x34) + 0x18));
        *(u32 *)(s0 + 0x40) = v0;
        a1 = *(s32 *)(s0 + 0x40);
        a0 = s1;
        SetSdlData(a0, (void *)a1);
        a0 = *(s32 *)(s0 + 0x30);
        a1 = 4;
        v0 = GetBindOffsetByIndex((void *)a0, a1);
        *(u32 *)(s0 + 0x48) = v0;
        a0 = *(s32 *)(s0 + 0x30);
        a1 = 5;
        v0 = GetBindOffsetByIndex((void *)a0, a1);
        *(u32 *)(s0 + 0x4c) = v0;
        v1 = *(s32 *)(s0 + 0x60);
        v0 = *(s32 *)(s0 + 0x5c);
        v1 = v1 - v0;
        v0 = (s32)v1 / 4;
        v1 = v0 << 2;
        *(u32 *)(s0 + 0x68) = v1;
        v0 = 2;
        *(u32 *)(s0 + 0x5c) = 0;
        v1 = *(u16 *)(s0 + 0xa);
        if (v1 == v0) {
            v0 = 4;
            v1 = GameSt[5];
            if (v1 == v0) {
                goto _L0013CF40;
            }
            a0 = *(u16 *)(s0 + 8);
            v0 = (u32)FrdFixTexPacketBuf;
            v1 = (u32)a0 * 0x370;
            a0 = (s32)((u8 *)FrdFixTexPacketBuf + v1);
            memset(a0, 0, (u32)0x370);
            a0 = *(u16 *)(s0 + 8);
            v0 = (u32)FrdFixTexPacketBuf;
            v1 = (u32)a0 * 0x370;
            v0 = (s32)((u8 *)FrdFixTexPacketBuf + v1);
            *(u32 *)(s0 + 0x5c) = v0;
        } else {
            _L0013CF40:;
            v0 = RemakeTexPacket(*(s32 *)(s0 + 0x68));
            *(u32 *)(s0 + 0x5c) = v0;
        }
        v0 = *(s32 *)(s0 + 0x5c);
        a0 = (s32)s0;
        *(u32 *)(s0 + 0x60) = v0;
        SetMdlTexListPacket((void *)a0);
        v1 = *(s32 *)(s0 + 0x58);
        v0 = *(s32 *)(s0 + 0x54);
        v1 = v1 - v0;
        v0 = (s32)v1 / 4;
        v1 = v0 << 2;
        *(u32 *)(s0 + 0x64) = v1;
        v0 = 2;
        *(u32 *)(s0 + 0x54) = 0;
        v1 = *(u16 *)(s0 + 0xa);
        if (v1 == v0) {
            v0 = 4;
            v1 = GameSt[5];
            if (v1 == v0) {
                goto _L0013CFF8;
            }
            v1 = *(u16 *)(s0 + 8);
            a2 = 0xb890;
            v0 = (u32)FrdFixMdlPacketBuf;
            v1 = v1 * (u32)0xb890;
            a0 = (s32)((u8 *)FrdFixMdlPacketBuf + v1);
            memset(a0, 0, 0xb890);
            a0 = *(u16 *)(s0 + 8);
            v1 = 0xb890;
            v0 = (u32)FrdFixMdlPacketBuf;
            v1 = (u32)a0 * (u32)0xb890;
            v0 = (s32)((u8 *)FrdFixMdlPacketBuf + v1);
            *(u32 *)(s0 + 0x54) = v0;
        } else {
            _L0013CFF8:;
            v0 = RemakeMdlPacket(*(s32 *)(s0 + 0x64));
            *(u32 *)(s0 + 0x54) = v0;
        }
        v0 = *(s32 *)(s0 + 0x54);
        a0 = (s32)s0;
        *(u32 *)(s0 + 0x58) = v0;
        SetVmdData((void *)a0);
        v1 = *(s32 *)(s0 + 0x40);
        a0 = (s32)s0;
        if (v1 != 0) {
            SetSmdData((void *)a0);
        }
    }
    return;
}








/* SetMdlData @ 0x13CC90 .. 0x13CD88 (0xf8 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x13cd44 writes a register its branch at 0x13cd40 reads
 */

extern void RemapVmdData(void *);
extern void SetMdlTexListPacket(void *);
extern void SetVmdData(void *);
extern void SetDummyPolyData(void *);
extern void SetObjectParamMirror(void *);
extern u32 TmpMdlBuf[];
extern u32 TmpTexBuf[];

void SetMdlData(signed int a0 /* r4 */, void *a1 /* r5 */) {
    u32 a3;
    u32 v1;
    u8 *s0;
    u32 v0;

    a3 = (u32)a1;
    a1 = (void *)(s32)((u32)a0 << 1);
    a1 = (void *)((u8 *)a1 + a0);
    a1 = (void *)(s32)((u32)a1 << 2);
    a0 = (s32)((u8 *)a1 + a0);
    v1 = (u32)MdlData;
    a0 = (u32)a0 << 7;
    s0 = (u8 *)((u8 *)MdlData + a0);
    if (a3 != 0 && (u32)*(s32 *)(s0 + 0x10) == 0) {
        a0 = (s32)s0;
        SetMdlType((void *)a0);
        v0 = *(s32 *)((a3 + 0x10));
        *(u32 *)(s0 + 0x10) = v0;
        a0 = *(s32 *)(s0 + 0x10);
        RemapVmdData((void *)a0);
        v1 = 0x60000;
        v0 = 0x8000;
        *(u32 *)(s0 + 0x64) = 0x60000;
        a0 = (s32)s0;
        *(u32 *)(s0 + 0x68) = 0x8000;
        v1 = (u32)TmpMdlBuf;
        *(u32 *)(s0 + 0x54) = (u32)TmpMdlBuf;
        v0 = (u32)TmpTexBuf;
        v1 = *(s32 *)(s0 + 0x54);
        *(u32 *)(s0 + 0x58) = v1;
        *(u32 *)(s0 + 0x5c) = (u32)TmpTexBuf;
        v0 = *(s32 *)(s0 + 0x5c);
        *(u32 *)(s0 + 0x60) = v0;
        SetMdlTexListPacket((void *)a0);
        a0 = (s32)s0;
        SetVmdData((void *)a0);
        a0 = (s32)s0;
        SetDummyPolyData((void *)a0);
        a0 = *(u16 *)(s0 + 0xa);
        v1 = 7;
        switch ((u32)a0) {
        case 0:
        case 5:
        case 6:
        case 7:
            a0 = (s32)s0;
            SetObjectParamMirror((void *)a0);
        }
    }
    return;
}





/* SetMdlType @ 0x13CB10 .. 0x13CC90 (0x180 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */


static void SetMdlType(void *a0 /* r4 */) {
    u32 v1;

    v1 = (u32)MdlData;
    v1 = 0x4ec4ec4f;
    v1 = (s32)((u8 *)a0 - (u32)(MdlData)) / (s32)(0x680);
    if ((s32)v1 < (s32)4) {
        *(u16 *)(((u8 *)a0 + 0xa)) = 0;
        *(u16 *)(((u8 *)a0 + 8)) = v1;
    } else if ((s32)v1 < (s32)0x14) {
        v1 = v1 + -4;
        *(u16 *)(((u8 *)a0 + 0xa)) = 1;
        *(u16 *)(((u8 *)a0 + 8)) = v1;
    } else if ((s32)v1 < (s32)0x1c) {
        v1 = v1 + -0x14;
        *(u16 *)(((u8 *)a0 + 0xa)) = 2;
        *(u16 *)(((u8 *)a0 + 8)) = v1;
    } else if ((s32)v1 < (s32)0x4c) {
        v1 = v1 + -0x1c;
        *(u16 *)(((u8 *)a0 + 0xa)) = 3;
        *(u16 *)(((u8 *)a0 + 8)) = v1;
    } else if ((s32)v1 < (s32)0x7c) {
        v1 = v1 + -0x4c;
        *(u16 *)(((u8 *)a0 + 0xa)) = 4;
        *(u16 *)(((u8 *)a0 + 8)) = v1;
    } else if ((s32)v1 < (s32)0x8c) {
        v1 = v1 + -0x7c;
        *(u16 *)(((u8 *)a0 + 0xa)) = 5;
        *(u16 *)(((u8 *)a0 + 8)) = v1;
    } else if ((s32)v1 < (s32)0x10c) {
        v1 = v1 + -0x8c;
        *(u16 *)(((u8 *)a0 + 0xa)) = 6;
        *(u16 *)(((u8 *)a0 + 8)) = v1;
    } else if ((s32)v1 < (s32)0x10f) {
        v1 = v1 + -0x10c;
        *(u16 *)(((u8 *)a0 + 0xa)) = 7;
        *(u16 *)(((u8 *)a0 + 8)) = v1;
    } else if ((s32)v1 < (s32)0x110) {
        v1 = v1 + -0x10f;
        *(u16 *)(((u8 *)a0 + 0xa)) = 8;
        *(u16 *)(((u8 *)a0 + 8)) = v1;
    } else if ((s32)v1 < (s32)0x120) {
        v1 = v1 + -0x110;
        *(u16 *)(((u8 *)a0 + 0xa)) = 9;
        *(u16 *)(((u8 *)a0 + 8)) = v1;
    } else {
        v1 = v1 + -0x120;
        *(u16 *)(((u8 *)a0 + 0xa)) = 0xa;
        *(u16 *)(((u8 *)a0 + 8)) = v1;
    }
    return;
}


/* SetMdlMng @ 0x13C860 .. 0x13CB08 (0x2a8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: __FUNCTION__$892 is the string 'SetMdlMng'
 *   literal: @1434 is the string ''
 *   delay: daddu at 0x13c898 writes a register its branch at 0x13c894 reads
 *   fpu: float literal 0x00000000 at 0x13c96c
 *   fpu: float literal 0x00000000 at 0x13c99c
 *   delay: addiu at 0x13cab8 writes a register its branch at 0x13cab4 reads
 *   cfg: kept branch: 0x13c880 if (..) goto .L0013C890
 *   cfg: kept goto: 0x13c888 -> .L0013CAF0
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

extern void * MemAllocAlignReal(unsigned int, unsigned int, char *, char *);
extern void InitAnimCtrl(void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetAnimInitData(void *);
extern void PlayNoAnim(void *);
extern void sceVu0CopyVector(void *, void *);
extern void FlushCache(int);
extern void * SetDss(void *);
extern signed int CsMngMakeRtaData(unsigned int);
extern void SetClothJointFlag(void *);

unsigned int SetMdlMng(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u32 s1;
    u8 *a3;
    u32 a2;
    u8 *s0;
    u32 a0_index; // a0
    u32 a0_index_; // a0
    float f12;
    u32 a0_index__; // a0
    u32 v1;
    u32 v0;
    void *a0_2;
    void *a1_2;

    s2 = (u8 *)a0;
    s1 = (u32)a1;
    if ((u32)s2 != 0) {
        if (s1 != 0) {
            goto _L0013C890;
        }
    }
    v0 = 0;
    goto _L0013CAF0;
    _L0013C890:;
    v0 = *(u8 *)s2;
    if (v0 != 0) {
        v0 = 0;
        return v0;
    }
    memset(a0, 0, (s32)0x1c0);
    *(u32 *)(s2 + 0xc) = s1;
    s0 = (u8 *)*(s32 *)((s1 + 0x10));
    if ((u32)(s32)s0 == 0) {
        v0 = 0;
        return v0;
    }
    v0 = 1;
    *(u8 *)s2 = v0;
    v0 = *(s16 *)(s0 + 0x10);
    a1_2 = (void *)(s32)0x40;
    a2 = (u32)((char *)__FUNCTION__);
    a3 = (u8 *)"";
    a0_index = v0 << (u32)6;
    v0 = (u32)MemAllocAlignReal((unsigned int)(void *)a0_index, (unsigned int)a1_2, ((char
        *)__FUNCTION__), "");
    *(u32 *)(s2 + 0x10) = v0;
    v0 = *(s32 *)((*(s32 *)(s2 + 0xc) + 0x1c));
    if (v0 != 0) {
        v0 = *(s16 *)(s0 + 0x10);
        a1_2 = (void *)(s32)0x40;
        a2 = (u32)((char *)__FUNCTION__);
        a3 = (u8 *)"";
        a0_index_ = v0 << (u32)6;
        v0 = (u32)MemAllocAlignReal((unsigned int)(void *)a0_index_, (unsigned int)a1_2, ((char
            *)__FUNCTION__), "");
        *(u32 *)(s2 + 0x14) = v0;
    }
    v1 = 0x3f800000;
    *(u32 *)(s2 + 0x10c) = 0x3f800000;
    v0 = 0x3f000000;
    *(u32 *)(s2 + 0x110) = 0x3f000000;
    v0 = 0x3fcccccd;
    *(u32 *)(s2 + 0x114) = 0x3fcccccd;
    *(u32 *)(s2 + 0x118) = 0x3f800000;
    *(u32 *)(s2 + 0x11c) = 0;
    *(u32 *)(s2 + 0x108) = 0x3f800000;
    v0 = *(s32 *)((s1 + 0x14));
    a0_2 = (void *)s2;
    if (v0 != 0) {
        s1 = 0;
        InitAnimCtrl(a0_2);
        f12 = 0.0f;
        a0_2 = (void *)s2;
        v0 = ChangeAnimParam(a0_2, 0, 0.0f);
        v0 = v0 != 0;
        v0 = v0 ^ 1;
        if (v0 != 0) {
            do {
                v0 = s1 + 1;
                s1 = (u16)v0;
                a0_2 = (void *)s2;
                f12 = 0.0f;
                a1_2 = (void *)s1;
                v0 = ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
                v0 = v0 != 0;
                v0 = v0 ^ 1;
            } while (v0 != 0);
        }
        SetAnimInitData((void *)s2);
    } else {
        v0 = *(s16 *)(s0 + 0x10);
        a1_2 = (void *)(s32)0x40;
        a2 = (u32)((char *)__FUNCTION__);
        a3 = (u8 *)"";
        a0_index__ = v0 << (u32)6;
        v0 = (u32)MemAllocAlignReal((unsigned int)(void *)a0_index__, (unsigned int)a1_2, ((char
            *)__FUNCTION__), "");
        *(u32 *)(s2 + 0x18) = v0;
        PlayNoAnim((void *)s2);
    }
    *(u32 *)(s2 + 0x20) = 0;
    *(u32 *)(s2 + 0x24) = 0;
    v0 = 0x3f800000;
    *(u32 *)(s2 + 0x28) = 0;
    a0_2 = (void *)(s2 + 0x70);
    *(u32 *)(s2 + 0x2c) = 0x3f800000;
    a1_2 = (void *)(s2 + 0x20);
    *(u32 *)(s2 + 0x30) = 0;
    *(u32 *)(s2 + 0x34) = 0;
    *(u32 *)(s2 + 0x38) = 0;
    *(u32 *)(s2 + 0x3c) = 0x3f800000;
    *(u32 *)(s2 + 0x40) = 0x3f800000;
    *(u32 *)(s2 + 0x44) = 0x3f800000;
    *(u32 *)(s2 + 0x48) = 0x3f800000;
    *(u32 *)(s2 + 0x4c) = 0x3f800000;
    sceVu0CopyVector(a0_2, a1_2);
    a0_2 = (void *)(s2 + 0x80);
    a1_2 = (void *)(s2 + 0x30);
    sceVu0CopyVector(a0_2, a1_2);
    FlushCache(0);
    v0 = *(s32 *)((*(s32 *)(s2 + 0xc) + 0x48));
    a0_2 = (void *)s2;
    if (v0 != 0) {
        SetDss(a0_2);
    }
    a2 = *(s32 *)(s0 + 0x38);
    a0_2 = (void *)-0x80000;
    v0 = 0x5100d;
    v1 = 0;
    a2 = *(u8 *)((a2 + 8));
    *(u8 *)(s2 + 6) = a2;
    ((struct { unsigned int f:19; } *)&*(u32 *)(s2 + 0x150))->f = 0x5100d;
    ((struct { unsigned char f:1; } *)&*(u8 *)(s2 + 0x153))->f = 0;
    v0 = *(u8 *)s2;
    if (v0 != 0) {
        v0 = *(u8 *)((*(s32 *)((*(s32 *)((*(s32 *)(s2 + 0xc) + 0x10)) + 0x38)) + 0xc));
    } else {
        v0 = -1;
    }
    a0_2 = (void *)s2;
    if ((s32)v0 > 0) {
        CsMngMakeRtaData((unsigned int)a0_2);
        a0_2 = (void *)s2;
        SetClothJointFlag(a0_2);
    }
    v0 = 1;
    _L0013CAF0:;
    return v0;
}

static inline u32 RemakeTexPacket(u32 size) {
    return (u32)MemAllocReal(size, (char *)__FUNCTION__, "");
}

static inline u32 RemakeMdlPacket(u32 size) {
    return (u32)MemAllocReal(size, (char *)__FUNCTION__, "");
}




/* FreeMdlData @ 0x13C7D0 .. 0x13C85C (0x8c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x13c7fc if (..) goto .L0013C820
 */


void FreeMdlData(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u8 *s1;
    s32 s0;
    u32 v1;
    s32 v0;

    s1 = (u8 *)a0;
    s0 = (s32)a1;
    if ((u32)s1 != 0) {
        v1 = *(u16 *)(((u8 *)s1 + 0xa));
        v0 = 2;
        if (v1 == (u32)v0) {
            v0 = 4;
            v1 = *(u8 *)((u8 *)&GameSt + 5);
            if (v1 != (u32)v0) {
                goto _L0013C820;
            }
        }
        a0 = (void *)*(s32 *)(((u8 *)s1 + 0x54));
        MemFree(a0);
        a0 = (void *)*(s32 *)(((u8 *)s1 + 0x5c));
        MemFree(a0);
        _L0013C820:;
        a0 = (void *)*(s32 *)(((u8 *)s1 + 0x44));
        FreeTexList(a0);
        if ((u32)s0 != 0) {
            a0 = (void *)*(s32 *)(((u8 *)s1 + 0x30));
            MemFree(a0);
        }
        a0 = (void *)s1;
        memset((u32)a0, 0, 0x680);
    }
    return;
}


/* FreeMdlMng @ 0x13C6F0 .. 0x13C7D0 (0xe0 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x13c790 writes a register its branch at 0x13c78c reads
 */

extern void FreeDss(void *);
extern signed int CsMngFreeRtaData(unsigned int);

void FreeMdlMng(void *a0 /* r4 */) {
    u8 *s0;
    void *a0_2; // a0
    u32 v1;

    v1 = *(u8 *)a0;
    s0 = (u8 *)a0;
    if (v1 != 0) {
        a0_2 = (void *)*(s32 *)(s0 + 0x10);
        MemFree(a0_2);
        *(u32 *)(s0 + 0x10) = 0;
        a0_2 = (void *)*(s32 *)(s0 + 0x14);
        if ((u32)(s32)a0_2 != 0) {
            MemFree(a0_2);
            *(u32 *)(s0 + 0x14) = 0;
        }
        a0_2 = (void *)*(s32 *)(s0 + 0x18);
        if ((u32)(s32)a0_2 != 0) {
            MemFree(a0_2);
            *(u32 *)(s0 + 0x18) = 0;
        }
        a0_2 = (void *)*(s32 *)(s0 + 0x18c);
        if ((u32)(s32)a0_2 != 0) {
            MemFree(a0_2);
            *(u32 *)(s0 + 0x18c) = 0;
        }
        MemFree((void *)*(s32 *)(s0 + 0x100));
        *(u32 *)(s0 + 0x100) = 0;
        v1 = *(s32 *)((*(s32 *)(s0 + 0xc) + 0x48));
        a0_2 = (void *)s0;
        if (v1 != 0) {
            FreeDss(a0_2);
        }
        v1 = *(u8 *)s0;
        if (v1 != 0) {
            v1 = *(u8 *)((*(s32 *)((*(s32 *)((*(s32 *)(s0 + 0xc) + 0x10)) + 0x38)) + 0xc));
        } else {
            v1 = -1;
        }
        a0_2 = (void *)s0;
        if ((s32)v1 > 0) {
            CsMngFreeRtaData((unsigned int)a0_2);
        }
        *(u8 *)s0 = 0;
    }
    return;
}

/* FreeAllMdlMng @ 0x13C690 .. 0x13C6E4 (0x54 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0013C6A8
 */


void FreeAllMdlMng(void) {
    u8 *s0;
    u8 v1;

    s0 = (u8 *)MdlMng;
    do {
        v1 = *(u8 *)s0;
        if ((u32)v1 != 0) {
            FreeMdlMng((void *)(u8 *)s0);
        }
        s0 = (u8 *)(s0 + 0x1c0);
    } while (s0 != (u8 *)(MdlMng + 0x54380));
    return;
}


/* ResetMdlPacketMem @ 0x13C670 .. 0x13C684 (0x14 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u8 * ResetMdlPacketMem(void) {
    MdlPacketMemID = 0;
    lpMdlPacketMem = (u32)MdlPacketMem;
    return;
}


/* KickMdlPacket @ 0x13C590 .. 0x13C66C (0xdc bytes, frame 0x20) */

extern void FlushCache(int);

void KickMdlPacket(void) {
    u8 *a2;
    u32 a1;
    u32 v1;
    s32 v0;
    s32 s0;

    a2 = (u8 *)lpMdlPacketMem;
    if ((u32)(s32)a2 != 0) {
        a1 = MdlPacketMemID;
        v0 = 0x70000000;
        v1 = (u32)MdlPacketMem;
        v0 = a1 << 0x15;
        v0 = (u32)v0 >> 2;
        v0 = (u32)v0 >> 1;
        s0 = (s32)((u8 *)MdlPacketMem + (s32)((u32)v0 << 2));
        *(u32 *)a2 = 0x70000000;
        *(u32 *)(a2 + 4) = 0;
        *(u32 *)(a2 + 8) = 0;
        *(u32 *)(a2 + 0xc) = 0;
        FlushCache(0);
        do {
            v1 = *(volatile s32 *)0x10009000 & 0x100;
        } while (v1 != 0);
        *(volatile u32 *)0x10009020 = 0;
        *(volatile u32 *)0x10009010 = 0;
        *(volatile u32 *)0x10009030 = s0;
        *(volatile u32 *)0x10009000 = 0x145;
    }
    v1 = (u32)MdlPacketMem;
    MdlPacketMemID = (u32)1 - MdlPacketMemID;
    lpMdlPacketMem = (s32)((u8 *)MdlPacketMem + (u32)((u32)((u32)((u32)((u32)MdlPacketMemID <<
        0x15) >> 2) >> 1) << 2));
    return;
}








/* SetMdlFade @ 0x13C580 .. 0x13C58C (0xc bytes) */




void SetMdlFade(u8 *a0 /* r4 */, s32 a1 /* r5 */, float f12 /* f12 */) {
    *(u8 *)(((u8 *)a0 + 5)) = a1;
    *(f32 *)(((u8 *)a0 + 0x14c)) = f12;
    return;
}







/* MdlFadeProc @ 0x13C4F0 .. 0x13C578 (0x88 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x13c4fc writes a register its branch at 0x13c4f8 reads
 *   fpu: float literal 0x3f800000 at 0x13c524
 *   fpu: float literal 0x00000000 at 0x13c550
 *   declaration vs inferred signature: return void vs inferred float
 */

void MdlFadeProc(void *a0 /* r4 */) {
    u32 a1;
    u8 *a0_bytes; // a0
    float f2;
    float f1;
    float f0;
    s32 v1;

    a0_bytes = (u8 *)a0;
    a1 = *(u8 *)(a0_bytes + 5);
    v1 = 2;
    v1 = 1;
    switch (a1) {
    case 0:
        break;
    case 1:
        v1 = 0x3f800000;
        f2 = *(float *)(a0_bytes + 0x14c);
        f0 = 1.0f;
        f1 = (*(f32 *)(a0_bytes + 0x10c) += (float)f2);
        if (f1 < 1.0f) {
            break;
        }
        *(f32 *)(a0_bytes + 0x10c) = f0;
        *(u8 *)(a0_bytes + 5) = 0;
        break;
    case 2:
        f2 = *(float *)(a0_bytes + 0x14c);
        f0 = 0.0f;
        f1 = (*(f32 *)(a0_bytes + 0x10c) -= f2);
        if (!(f1 <= 0.0f)) {
            break;
        }
        *(f32 *)(a0_bytes + 0x10c) = f0;
        *(u8 *)(a0_bytes + 5) = 0;
    }
    return;
}

/* GetClothDataId @ 0x13C4C0 .. 0x13C4E4 (0x24 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x13c4c8 writes a register its branch at 0x13c4c4 reads
 *   declaration vs inferred signature: return signed int vs inferred u8
 */





signed int GetClothDataId(void *a0 /* r4 */) {
    u8 v0;

    v0 = *(u8 *)a0;
    return (u32)v0 != 0 ? *(u8 *)((*(s32 *)((*(s32 *)((*(s32 *)(((u8 *)a0 + 0xc)) + 0x10)) + 0x38))
        + 0xc)) : (s32)-1;
}










/* SetModelEraseByMapDraw @ 0x13C3B0 .. 0x13C4BC (0x10c bytes, frame 0x40) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int CheckDrawMapByCamParam(signed int);

void SetModelEraseByMapDraw(void *a0 /* r4 */) {
    u8 *s1;
    u32 t1;
    u32 a3;
    s32 a2;
    u32 a1;
    u8 s0;
    u32 a0_scalar; // a0
    s32 s2;
    u32 v1;
    s32 v0;

    v1 = -0x6db70000;
    a3 = -0x6db70000 | 0x2493;
    a1 = (u32)MdlMng;
    s1 = (u8 *)a0;
    s0 = 0;
    a0_scalar = (s32)((u8 *)*(s32 *)(((u8 *)a0 + 0x138)) - (u32)(MdlMng)) / (s32)(0x1c0);
    a2 = *(s32 *)(s1 + 0x13c) - (u32)((u32)(MdlMng));
    a1 = (u32)a2 >> 0x1f;
    s2 = a2 / (s32)(0x1c0);
    *(u8 *)(s1 + 3) = 0;
    t1 = *(s32 *)(s1 + 0x138);
    if (t1 != 0 && (u32)*(s32 *)(s1 + 0x13c) != 0) {
        v0 = CheckDrawMapByCamParam(a0_scalar);
        if ((u32)v0 == 0) {
            v0 = CheckDrawMapByCamParam(s2);
            if ((u32)v0 == 0) {
                s0 = 1;
            }
        }
    } else if (t1 != 0) {
        v0 = CheckDrawMapByCamParam(a0_scalar);
        if ((u32)v0 == 0) {
            s0 = 1;
        }
    } else if ((u32)*(s32 *)(s1 + 0x13c) != 0) {
        v0 = CheckDrawMapByCamParam(s2);
        if ((u32)v0 == 0) {
            s0 = 1;
        }
    }
    *(u8 *)(s1 + 3) = s0;
    return;
}

/* SetModelTargetToPos @ 0x13C340 .. 0x13C3AC (0x6c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred float
 */






void SetModelTargetToPos(void *a0 /* r4 */, float *a1 /* r5 */) {
    u8 *s0;
    float f3;
    float f2;
    float f1;
    float f0;
    float f21;
    float f20;
    float f12;
    float f13;

    s0 = (u8 *)a0;
    *(u32 *)(((u8 *)a0 + 0x1b4)) = 0;
    f3 = *(float *)a1;
    f2 = *(float *)(((u8 *)a0 + 0x20));
    f1 = *(float *)(((u8 *)a1 + 8));
    f0 = *(float *)(((u8 *)a0 + 0x28));
    f21 = (f3 - f2);
    f20 = (f1 - f0);
    f12 = (-f21);
    f13 = (-f20);
    f0 = Math_VectorToAngle(f12, f13);
    __asm__ volatile("mula.s %0,%1" : : "f"(f21), "f"(f21) : "memory");
    *(f32 *)(((u8 *)s0 + 0x198)) = f0;
    f0 = ({ float native_result_0; __asm__ volatile("madd.s %0,%1,%2" : "=f"(native_result_0) :
        "f"(f20), "f"(f20) : "memory"); native_result_0; });
    f0 = ({ float native_result_1; __asm__ volatile("sqrt.s %0,%1" : "=f"(native_result_1) :
        "f"(f0) : "memory"); native_result_1; });
    *(f32 *)(((u8 *)s0 + 0x19c)) = f0;
    return;
}







/* SetModelTargetToModel @ 0x13C2D0 .. 0x13C33C (0x6c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred float
 */


void SetModelTargetToModel(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s0;
    float f3;
    float f2;
    float f1;
    float f0;
    float f21;
    float f20;
    float f12;
    float f13;

    s0 = (u8 *)a0;
    *(u32 *)(((u8 *)a0 + 0x1b4)) = (u32)a1;
    f3 = *(float *)(((u8 *)a1 + 0x20));
    f2 = *(float *)(((u8 *)a0 + 0x20));
    f1 = *(float *)(((u8 *)a1 + 0x28));
    f0 = *(float *)(((u8 *)a0 + 0x28));
    f21 = (f3 - f2);
    f20 = (f1 - f0);
    f12 = (-f21);
    f13 = (-f20);
    f0 = Math_VectorToAngle(f12, f13);
    __asm__ volatile("mula.s %0,%1" : : "f"(f21), "f"(f21) : "memory");
    *(f32 *)(((u8 *)s0 + 0x198)) = f0;
    f0 = ({ float native_result_0; __asm__ volatile("madd.s %0,%1,%2" : "=f"(native_result_0) :
        "f"(f20), "f"(f20) : "memory"); native_result_0; });
    f0 = ({ float native_result_1; __asm__ volatile("sqrt.s %0,%1" : "=f"(native_result_1) :
        "f"(f0) : "memory"); native_result_1; });
    *(f32 *)(((u8 *)s0 + 0x19c)) = f0;
    return;
}


/* SetModelWorldMatrix @ 0x13C2C0 .. 0x13C2D0 (0x10 bytes) */
/*
 * dcomp notes:
 *   tail: j sceVu0CopyMatrix at 0x13c2c8 leaves the function
 *   return value dropped, call kept: the function is void
 */


void SetModelWorldMatrix(u8 *a0 /* r4 */) {
    *(u8 *)(((u8 *)a0 + 9)) = 1;
    a0 = (u8 *)a0 + 0xc0;
    sceVu0CopyMatrix(a0);
    return;
}



/* SetDummyPolyData @ 0x13BF10 .. 0x13C2B4 (0x3a4 bytes, frame 0xc0) */
/*
 * dcomp notes:
 *   quad: t1: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1170 -> 0x228780
 *   fpu: float literal 0x3f800000 at 0x13bf1c
 *   fpu: float literal 0x3c010204 at 0x13bf7c
 *   fpu: float literal 0x40400000 at 0x13bf84
 *   stack: address of the slot at 0xb4 escapes at 0x13bfa0
 *   stack: address of the slot at 0xb8 escapes at 0x13bfa0
 *   stack: address of the slot at 0xa0 escapes at 0x13bfa0
 *   stack: address of the slot at 0xb0 escapes at 0x13bfa0
 *   fpu: mtc1 reinterprets t1 at 0x13c0a4
 *   fpu: mtc1 reinterprets t1 at 0x13c0c4
 *   fpu: mtc1 reinterprets t1 at 0x13c0e4
 *   fpu: mtc1 reinterprets t1 at 0x13c104
 *   fpu: mtc1 reinterprets t1 at 0x13c124
 *   fpu: mtc1 reinterprets t1 at 0x13c144
 *   fpu: mtc1 reinterprets t1 at 0x13c164
 *   fpu: mtc1 reinterprets t1 at 0x13c184
 *   fpu: mtc1 reinterprets t1 at 0x13c1a4
 *   fpu: mtc1 reinterprets t1 at 0x13c200
 *   fpu: mtc1 reinterprets t1 at 0x13c218
 *   fpu: mtc1 reinterprets t1 at 0x13c230
 *   cfg: loop body is not one contiguous region: .L0013BFA0
 *   cfg: loop body is not one contiguous region: .L0013BFB8
 *   cfg: loop body is not one contiguous region: .L0013C010
 *   declaration vs inferred signature: return void vs inferred float
 */

extern u_long128 L1170[];

#ifndef PROTO_DW_211886_FIELDS
#define PROTO_DW_211886_FIELDS
struct dw_211886_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_191857_FIELDS
#define PROTO_DW_191857_FIELDS
struct dw_191857_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_211886_fields DmyPoly[32]; };
#endif


struct sdp_Mat { unsigned char pad[0x29]; unsigned char DummyPolyId; };
struct sdp_Prim { short flags; unsigned char PolyNum; unsigned char PrimNum; void *lpBoundBox; struct sdp_Prim *lpNext; short (*lpVertex)[4]; char (*lpNormal)[3]; void *lpTexCoord; unsigned char (*lpColor)[4]; void *a; void *b; void *c; void *d; struct sdp_Mat *lpMaterial; };
struct sdp_Obj { float Position[4]; float Angle[4]; float Scale[4]; short ObjectId; short GeomObjectId; short ParentObjectId; short ChildObjectId; short SiblingObjectId; short MatrixNum; unsigned short *lpMatrixId; int PrimListNum; struct sdp_Prim *lpPrimHead; unsigned short PolyNum; unsigned short TreeNum; void *lpBoundBox; char *lpObjectName; void *lpObjParam; void *lpTree; void *lpObjReserve; };
struct sdp_Head { unsigned int VmdFileVersion; char *lpAp2FileName; int VmdFileSize; short MaterialNum; short MatrixNum; short ObjectNum; short GeomObjectNum; void *lpMaterial; void *lpMatrix; struct sdp_Obj *lpObject; float GeomScale; };
struct sdp_Dmy { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
struct sdp_Mdl { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; struct sdp_Head *lpVmdHead; void *rest[22]; float aMorphRate[3]; unsigned int unused[2]; struct sdp_Dmy DmyPoly[32]; };

void SetDummyPolyData(void *lpMdlData_) {
    struct sdp_Mdl *lpMdlData = (struct sdp_Mdl *)lpMdlData_;
    int i;
    int j;
    int k;
    int dmyNum;
    struct sdp_Head *lpVmdHead;
    struct sdp_Obj *lpVmdObj;
    struct sdp_Prim *lpPrimHead;
    short (*lpVertex)[4];
    char (*lpNormal)[3];
    unsigned char (*lpColor)[4];
    struct sdp_Dmy *lpDmyPoly;
    float VerScl;
    float NrmScl;
    float Pos[4] __attribute__((aligned(16)));

    lpVmdHead = lpMdlData->lpVmdHead;
    VerScl = 1.0f / lpVmdHead->GeomScale;
    NrmScl = 1.0f / 127.0f;
    lpMdlData->DmyPolyNum = 0;
    lpVmdObj = lpVmdHead->lpObject;
    for (i = 0; i < lpVmdHead->ObjectNum; i++) {
        lpPrimHead = lpVmdObj->lpPrimHead;
        for (j = 0; j < lpVmdObj->PrimListNum; j++) {
            if (lpPrimHead->lpMaterial != 0 && lpPrimHead->lpMaterial->DummyPolyId != 0xff) {
                dmyNum = lpPrimHead->PrimNum / 3;
                for (k = 0; k < dmyNum; k++) {
                    lpDmyPoly = &lpMdlData->DmyPoly[lpMdlData->DmyPolyNum];
                    lpDmyPoly->ObjectId = lpVmdObj->ObjectId;
                    lpVertex = lpPrimHead->lpVertex + k * 3;
                    lpNormal = lpPrimHead->lpNormal + k * 3;
                    lpColor = lpPrimHead->lpColor + k * 3;
                    if ((*lpColor)[0] == 0xff) {
                        lpDmyPoly->Type = 0;
                    } else if ((*lpColor)[0] == 0) {
                        lpDmyPoly->Type = 1;
                    }
                    lpDmyPoly->Id = (*lpColor)[2];
                    {
                        struct sdp_Q { u_long128 q[1]; };
                        struct sdp_I { u8 b[16]; } InitPos __attribute__((aligned(16))) = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x00, 0x80, 0x3f}};
                        *(struct sdp_Q *)Pos = *(struct sdp_Q *)&InitPos;
                    }
                    Pos[0] += lpVertex[0][0] * VerScl;
                    Pos[1] += lpVertex[0][1] * VerScl;
                    Pos[2] += lpVertex[0][2] * VerScl;
                    Pos[0] += lpVertex[1][0] * VerScl;
                    Pos[1] += lpVertex[1][1] * VerScl;
                    Pos[2] += lpVertex[1][2] * VerScl;
                    Pos[0] += lpVertex[2][0] * VerScl;
                    Pos[1] += lpVertex[2][1] * VerScl;
                    Pos[2] += lpVertex[2][2] * VerScl;
                    Pos[0] /= 3.0f;
                    Pos[1] /= 3.0f;
                    Pos[2] /= 3.0f;
                    lpDmyPoly->Pos[0] = Pos[0];
                    lpDmyPoly->Pos[1] = Pos[1];
                    lpDmyPoly->Pos[2] = Pos[2];
                    lpDmyPoly->Pos[3] = 1.0f;
                    lpDmyPoly->Nrm[0] = (*lpNormal)[0] * NrmScl;
                    lpDmyPoly->Nrm[1] = (*lpNormal)[1] * NrmScl;
                    lpDmyPoly->Nrm[2] = (*lpNormal)[2] * NrmScl;
                    lpDmyPoly->Nrm[3] = 1.0f;
                    lpMdlData->DmyPolyNum++;
                }
            }
            lpPrimHead = lpPrimHead->lpNext;
        }
        lpVmdObj++;
    }
}








/* GetDummyPolyData @ 0x13BE90 .. 0x13BF08 (0x78 bytes) */
/*
 * dcomp notes:
 *   delay: sll at 0x13bed0 writes a register its branch at 0x13becc reads
 *   cfg: loop body is not one contiguous region: .L0013BEB0
 *   declaration vs inferred signature: return void * vs inferred u32
 */




void * GetDummyPolyData(void *a0 /* r4 */, unsigned char a1 /* r5 */, unsigned char a2 /* r6 */) {
    s32 t1;
    u8 t0;
    u8 a3;
    s32 v1;
    u32 v0;
    u8 a1_2;
    u32 a2_2;

    a3 = *(u8 *)(((u8 *)a0 + 0xd));
    t1 = 0;
    if (0 < (s32)a3) {
        t0 = a1;
        a1_2 = a2;
        a2_2 = (u32)a0;
        v1 = 0xff;
        do {
            if ((u32)t0 == (u32)v1 || (u32)*(u8 *)((a2_2 + 0xa2)) == (u32)t0) {
                v0 = *(u8 *)((a2_2 + 0xa3));
                if (v0 == (u32)a1_2) {
                    v0 = (u32)t1 * (u32)(0x30);
                    v0 = (s32)((u8 *)a0 + (u32)v0);
                    return (void *)(u32)(v0 + 0x80);
                }
            }
            t1 = t1 + 1;
            v0 = t1 < (s32)a3;
            a2_2 = a2_2 + 0x30;
        } while (v0 != 0);
    }
    return (void *)(u32)0;
}






/* GetMdlCtrlId @ 0x13BE60 .. 0x13BE84 (0x24 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */





signed int GetMdlCtrlId(void *a0 /* r4 */) {
    u8 *v0;

    v0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x140));
    return (u32)(s32)v0 != 0 ? *(s32 *)*(s32 *)(v0 + 0x38) : (s32)-1;
}

u8 MdlMng[0x54380];
u16 MdlData[0x3dc00];
static u32 MdlPacketMem[0x80000];
static u32 TmpMdlBuf[0x18000];
static u32 TmpTexBuf[0x2000];
static u32 FrdFixTexPacketBuf[0x1b8];
static u32 FrdFixMdlPacketBuf[0x5c48];
static u32 MdlPacketMemID;
u32 lpMdlPacketMem;
