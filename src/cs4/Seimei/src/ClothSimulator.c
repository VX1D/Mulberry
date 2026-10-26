#include "common.h"

/* CsMngSetBufType @ 0x1693E0 .. 0x169408 (0x28 bytes, frame 0x20) */

extern void *RtaMngGetRtaMng(void);

/* CsMngCheckClothJoint @ 0x169410 .. 0x1694A4 (0x94 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: daddu at 0x169488 writes a register its branch at 0x169484 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void * RtaMng_GetRtaParamFromObjectId(unsigned int, unsigned int, unsigned int);
extern u32 MdlMng[];

extern void RtaMngSetstabilizeOnOff(signed int);
extern signed int RtaMngRtaUpdate(unsigned int, unsigned int);


/* CsMngRtaSetMat @ 0x1695A0 .. 0x169600 (0x60 bytes) */

extern signed int RtaMngRtaSetMat(unsigned int, unsigned int, void *, int);
extern u32 MdlMng[];

/* CsMngRtaUpdate @ 0x169600 .. 0x169674 (0x74 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int RtaMngRtaUpdate(unsigned int, unsigned int);
extern u8 GameSt[];

/* CsMngUpdate @ 0x169680 .. 0x1696A4 (0x24 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return int vs inferred u32
 */

extern signed int RtaMngUpdate(void);

/* CsMngFreeRtaData @ 0x1696B0 .. 0x169714 (0x64 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int RtaMngDeleteRtaData(unsigned int);

/* CsMngMakeRtaData @ 0x169720 .. 0x1697BC (0x9c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int GetClothDataId(void *);
extern signed int RtaMngMakeRtaData(unsigned int, unsigned int);

/* CsMngInit @ 0x1697C0 .. 0x169898 (0xd8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: addiu at 0x169878 writes a register its branch at 0x169874 reads
 *   cfg: loop body is not one contiguous region: .L00169800
 */

extern signed int RtaMngInit(void);


/* CsMngInitialize @ 0x1698A0 .. 0x1698A8 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j RtaMngInitialize at 0x1698a0 leaves the function
 *   repo declaration vs inferred signature: return int vs inferred void
 */

extern signed int RtaMngInitialize(void);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int CsMngInitialize(void);
signed int CsMngInit(void);
signed int CsMngMakeRtaData(unsigned int a0 );
signed int CsMngFreeRtaData(unsigned int a0 );
int CsMngUpdate(void);
signed int CsMngRtaUpdate(unsigned int a0 );
signed int CsMngRtaSetMat(s32 a0 , u8 *a1 , s32 a2 );
signed int CsMngStabilize(unsigned int model, unsigned int count);
int CsMngDraw(void);
signed int CsMngCheckClothJoint(unsigned int a0 , unsigned int a1 );
void CsMngSetBufType(unsigned int a0 );


signed int CsMngInitialize(void) {
    return RtaMngInitialize();
}

signed int CsMngInit(void) {
    u32 v0;
    u8 *s1;
    s32 s2;

    v0 = RtaMngInit();
    if (v0 != (u32)1) {
        v0 = 0;
    } else {
        s1 = (u8 *)MdlMng;
        do {
            v0 = GetClothDataId((void *)s1);
            if ((s32)v0 >= 0 && (u32)s1) {
                s2 = (u32)(s32)(s1 - (u32)(MdlMng)) / 0x1c0;
                v0 = GetClothDataId((void *)s1);
                if ((s32)v0 > 0) {
                    v0 = GetClothDataId((void *)s1);
                    RtaMngMakeRtaData(s2, v0);
                }
            }
            s1 = (u8 *)(s1 + 0x1c0);
        } while (s1 != (u8 *)(MdlMng + 0x150e0));
        v0 = 1;
    }
    return v0;
}

signed int CsMngMakeRtaData(unsigned int a0 /* r4 */) {
    u32 s0;
    s32 s1;
    u32 v0;

    s0 = a0;
    if (s0 == 0) {
        return 0;
    }
    v0 = (u32)MdlMng;
    s1 = (u32)(s0 - (u32)((u32)(MdlMng))) / (u32)(0x1c0);
    v0 = GetClothDataId((void *)a0);
    a0 = (u32)s0;
    if ((s32)v0 > 0) {
        v0 = RtaMngMakeRtaData(s1, GetClothDataId((void *)a0));
    } else {
        v0 = 0;
    }
    return v0;
}


signed int CsMngFreeRtaData(unsigned int a0 /* r4 */) {
    u32 v0;

    if ((u32)(s32)a0 == 0) {
        v0 = 0;
    } else {
        v0 = (u32)MdlMng;
        a0 = (u32)(a0) - (u32)((u32)(MdlMng));
        RtaMngDeleteRtaData((u32)a0 / (u32)(0x1c0));
        v0 = 0;
    }
    return v0;
}

int CsMngUpdate(void) {
    s32 v0;

    v0 = RtaMngUpdate();
    return (u32)(v0 ^ 1) < (u32)1;
}


signed int CsMngRtaUpdate(unsigned int a0 /* r4 */) {
    s32 a1;
    u8 v1;
    u32 v0;

    v0 = 4;
    v1 = GameSt[5];
    a1 = a0;
    if ((u32)v1 == v0) {
        v0 = 0;
    } else {
        v0 = (u32)MdlMng;
        a0 = a1 - (u32)((u32)(MdlMng));
        v0 = RtaMngRtaUpdate((u32)a0 / (u32)(0x1c0), a1);
        v0 = v0 ^ 1;
        v0 = v0 < (u32)1;
    }
    return v0;
}

signed int CsMngRtaSetMat(s32 a0 /* r4 */, u8 *a1 /* r5 */, s32 a2 /* r6 */) {
    u32 v0;

    v0 = (u32)MdlMng;
    v0 = RtaMngRtaSetMat((u32)(a0 - (u32)((u32)(MdlMng))) / 0x1c0, a0, (void *)a1, a2);
    return (u32)(v0 ^ 1) < (u32)1;
}
signed int CsMngStabilize(unsigned int model, unsigned int count) {
    unsigned int id = (model - (u32)MdlMng) / 0x1c0;
    unsigned int i;
    RtaMngSetstabilizeOnOff(1);
    for (i = 0; i < count; i++) {
        if (i == count - 1) RtaMngSetstabilizeOnOff(0);
        if (RtaMngRtaUpdate(id, model) != 1) return 0;
    }
    RtaMngSetstabilizeOnOff(0);
    return 1;
}

/* CsMngDraw @ 0x1694B0 .. 0x1694B8 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x1694b4 computes the return value
 *   repo declaration vs inferred signature: return int vs inferred u32
 */

int CsMngDraw(void) {
    return 1;
}

signed int CsMngCheckClothJoint(unsigned int a0 /* r4 */, unsigned int a1 /* r5 */) {
    u32 v1;
    u32 v0;

    v0 = (u32)MdlMng;
    v0 = (u32)RtaMng_GetRtaParamFromObjectId((u32)((u32)(a0) - (u32)((u32)(MdlMng))) /
        (u32)(0x1c0), a0, a1);
    if (v0 == 0) {
        v0 = 0;
        return v0;
    }
    v1 = *(u8 *)((v0 + 0xc));
    if (v1 == 0) {
        return 1;
    }
    return v1 == (u32)1 ? (s32)2 : 0;
}

void CsMngSetBufType(unsigned int a0 /* r4 */) {
    u8 *v0;

    v0 = (u8 *)RtaMngGetRtaMng();
    *(u32 *)(v0 + 0xd48) = a0;
    return;
}
