#include "common.h"




extern int SND_SqPlay(u8, int);
extern void SND_SqFadeStart(int, int);
extern u32 GetCamInfo(void);
extern void * GetCamPathData(void *, signed int);
extern void SetCamReverb(void *);
extern u8 GameSt[];
extern u32 SND_RemoveSec();
extern u32 SND_SqRemove(void);
extern int sprintf(void *, void *, ...);
extern void SND_LoadSecFromFile(s32, u8 *);
extern void SND_SqLoadSqFromFile(char *);
extern u8 GameSt[];
u8 * RestartMapSe(void);
signed int SND_SecRemoveSpirit(signed int a0 /* r4 */);
u32 SND_SecRemoveMap(void);
u32 SND_SecRemovePlayer(void);
signed int SND_SecLoadSpirit(signed int a0 /* r4 */, signed int a1 /* r5 */);
signed int SND_SecLoadMap(signed int a0 /* r4 */);
signed int SND_SecLoadPlayer(signed int a0 /* r4 */);


extern void FreeAllMyEquipSound();
extern void ReadAllMyEquipSound();



/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int SND_SecLoadCommon(void);
signed int SND_SecLoadPlayer(signed int a0 );
signed int SND_SecLoadMap(signed int a0 );
signed int SND_SecLoadSpirit(signed int a0 , signed int a1 );
u32 SND_SecRemovePlayer(void);
u32 SND_SecRemoveMap(void);
signed int SND_SecRemoveSpirit(signed int a0 );
void ChangeLanguageSound(void);
u8 * RestartMapSe(void);








/* SND_SecLoadCommon @ 0x1A91D0 .. 0x1A9208 (0x38 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   literal: @765 is the string 'sound\\common.sec'
 *   literal: @766 is the string 'sound\\common2.sec'
 */

signed int SND_SecLoadCommon(void) {
    u8 *a1;

    a1 = (u8 *)"sound\\common.sec";
    SND_LoadSecFromFile(0, (u8 *)"sound\\common.sec");
    a1 = (u8 *)"sound\\common2.sec";
    SND_LoadSecFromFile(1, (u8 *)"sound\\common2.sec");
    return 0;
}


/* SND_SecLoadPlayer @ 0x1A9170 .. 0x1A91CC (0x5c bytes, frame 0x110) */
/*
 * dcomp notes:
 *   literal: @740 is the string 'sound\\char\\c%03d.sec'
 *   literal: @741 is the string 'sound\\char\\c%03de.sec'
 *   stack: address of the slot at 0x10 escapes at 0x1a9190
 *   stack: address of the slot at 0x10 escapes at 0x1a91a8
 *   stack: address of the slot at 0x10 escapes at 0x1a91b4
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int SND_SecLoadPlayer(signed int a0 /* r4 */) {
    u32 v0;
    s32 a2;
    u8 *a1;
    u8 stackFrame[256] __attribute__((aligned(16)));

    v0 = *(u8 *)((u8 *)&GameSt + 0x2c);
    a2 = (s32)a0;
    if (v0 == 0) {
        a0 = (signed int)((u8 *)&stackFrame[0]);
        a1 = (u8 *)"sound\\char\\c%03d.sec";
        sprintf((u8 *)a0, "sound\\char\\c%03d.sec", a2);
    } else {
        a0 = (signed int)((u8 *)&stackFrame[0]);
        a1 = (u8 *)"sound\\char\\c%03de.sec";
        sprintf((u8 *)a0, "sound\\char\\c%03de.sec", a2);
    }
    a0 = (s32)2;
    SND_LoadSecFromFile(a0, (u8 *)((u8 *)&stackFrame[0]));
    v0 = 0;
    return v0;
}








/* SND_SecLoadMap @ 0x1A9090 .. 0x1A916C (0xdc bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @742 is the string 'sound\\map\\s%04d.sec'
 *   literal: @743 is the string 'sound\\map\\s%04de.sec'
 *   literal: @744 is the string 'sound\\ene\\s%04d_e.sec'
 *   literal: @745 is the string 'sound\\ene\\s%04d_ee.sec'
 *   literal: @746 is the string 'sound\\sqmidi\\sq%04d.bnd'
 *   stack: address of the slot at 0x20 escapes at 0x1a90b8
 *   stack: address of the slot at 0x20 escapes at 0x1a90d4
 *   stack: address of the slot at 0x20 escapes at 0x1a90e4
 *   stack: address of the slot at 0x20 escapes at 0x1a9104
 *   stack: address of the slot at 0x20 escapes at 0x1a9124
 *   stack: address of the slot at 0x20 escapes at 0x1a9134
 *   stack: address of the slot at 0x20 escapes at 0x1a9148
 *   stack: address of the slot at 0x20 escapes at 0x1a9150
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int SND_SecLoadMap(signed int a0 /* r4 */) {
    s32 s0;
    u8 *a1;
    u32 v0;
    u8 stackFrame_20[256] __attribute__((aligned(16)));

    v0 = GameSt[0x2c];
    s0 = a0;
    if (v0 == 0) {
        a1 = (u8 *)"sound\\map\\s%04d.sec";
        sprintf((void *)((u8 *)&stackFrame_20[0]), (void *)"sound\\map\\s%04d.sec", s0);
    } else {
        a1 = (u8 *)"sound\\map\\s%04de.sec";
        sprintf((void *)((u8 *)&stackFrame_20[0]), (void *)"sound\\map\\s%04de.sec", s0);
    }
    SND_LoadSecFromFile(3, (u8 *)((u8 *)&stackFrame_20[0]));
    v0 = GameSt[0x2c];
    if (v0 == 0) {
        a1 = (u8 *)"sound\\ene\\s%04d_e.sec";
        sprintf((void *)((u8 *)&stackFrame_20[0]), (void *)"sound\\ene\\s%04d_e.sec", s0);
    } else {
        a1 = (u8 *)"sound\\ene\\s%04d_ee.sec";
        sprintf((void *)((u8 *)&stackFrame_20[0]), (void *)"sound\\ene\\s%04d_ee.sec", s0);
    }
    SND_LoadSecFromFile(4, (u8 *)((u8 *)&stackFrame_20[0]));
    a1 = (u8 *)"sound\\sqmidi\\sq%04d.bnd";
    sprintf((void *)((u8 *)&stackFrame_20[0]), (void *)"sound\\sqmidi\\sq%04d.bnd", s0);
    SND_SqLoadSqFromFile((char *)((u8 *)&stackFrame_20[0]));
    return 0;
}







/* SND_SecLoadSpirit @ 0x1A9020 .. 0x1A9088 (0x68 bytes, frame 0x120) */
/*
 * dcomp notes:
 *   literal: @754 is the string 'sound\\per\\p%03d.sec'
 *   literal: @755 is the string 'sound\\per\\p%03de.sec'
 *   stack: address of the slot at 0x20 escapes at 0x1a9048
 *   stack: address of the slot at 0x20 escapes at 0x1a9060
 *   stack: address of the slot at 0x20 escapes at 0x1a906c
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int SND_SecLoadSpirit(signed int a0 /* r4 */, signed int a1 /* r5 */) {
    s32 a2;
    s32 s0;
    u32 v0;
    u8 stackFrame_20[256] __attribute__((aligned(16)));

    a2 = a1;
    v0 = GameSt[0x2c];
    s0 = (u32)(a0) + 5;
    if (v0 == 0) {
        a1 = (signed int)"sound\\per\\p%03d.sec";
        sprintf((void *)((u8 *)&stackFrame_20[0]), (void *)"sound\\per\\p%03d.sec", a2);
    } else {
        a1 = (signed int)"sound\\per\\p%03de.sec";
        sprintf((void *)((u8 *)&stackFrame_20[0]), (void *)"sound\\per\\p%03de.sec");
    }
    SND_LoadSecFromFile((u8)s0, (u8 *)((u8 *)&stackFrame_20[0]));
    return 0;
}





/* SND_SecRemovePlayer @ 0x1A9000 .. 0x1A9020 (0x20 bytes, frame 0x10) */


u32 SND_SecRemovePlayer(void) {
    SND_RemoveSec(2);
    return (u32)0;
}






/* SND_SecRemoveMap @ 0x1A8FD0 .. 0x1A9000 (0x30 bytes, frame 0x10) */


u32 SND_SecRemoveMap(void) {
    SND_SqRemove();
    SND_RemoveSec(4);
    SND_RemoveSec(3);
    return (u32)0;
}







/* SND_SecRemoveSpirit @ 0x1A8FA0 .. 0x1A8FC4 (0x24 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int SND_SecRemoveSpirit(signed int a0 /* r4 */) {
    u32 v0;

    v0 = (u32)(a0) + 5;
    a0 = (u8)v0;
    SND_RemoveSec(a0);
    v0 = 0;
    return v0;
}

void ChangeLanguageSound(void) {
    u8 *a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u32 s0;
    u32 charNo;
    u8 stackFrame_120[256] __attribute__((aligned(16)));
    u8 stackFrame_20[256] __attribute__((aligned(16)));

    a0 = GameSt[0x2c];
    v1 = GameSt[0x2d];
    if (a0 != (u32)v1) {
        FreeAllMyEquipSound();
        SND_SqRemove();
        SND_RemoveSec((u32)4);
        SND_RemoveSec((u32)3);
        SND_RemoveSec((u32)2);
        v1 = GameSt[0x14];
        charNo = v1 + 1;
        v0 = GameSt[0x2c];
        if (v0 == 0) {
            a1 = (u8 *)"sound\\char\\c%03d.sec";
            sprintf((void *)((u8 *)&stackFrame_120[0]), (void *)"sound\\char\\c%03d.sec",
                (u32)charNo);
        } else {
            a1 = (u8 *)"sound\\char\\c%03de.sec";
            sprintf((void *)((u8 *)&stackFrame_120[0]), (void *)"sound\\char\\c%03de.sec");
        }
        SND_LoadSecFromFile(2, (u8 *)((u8 *)&stackFrame_120[0]));
        s0 = GameSt[9];
        v0 = GameSt[0x2c];
        if (v0 == 0) {
            a1 = (u8 *)"sound\\map\\s%04d.sec";
            sprintf((void *)((u8 *)&stackFrame_20[0]), (void *)"sound\\map\\s%04d.sec", (u32)s0);
        } else {
            a1 = (u8 *)"sound\\map\\s%04de.sec";
            sprintf((void *)((u8 *)&stackFrame_20[0]), (void *)"sound\\map\\s%04de.sec", (u32)s0);
        }
        SND_LoadSecFromFile(3, (u8 *)((u8 *)&stackFrame_20[0]));
        v0 = GameSt[0x2c];
        if (v0 == 0) {
            a1 = (u8 *)"sound\\ene\\s%04d_e.sec";
            sprintf((void *)((u8 *)&stackFrame_20[0]), (void *)"sound\\ene\\s%04d_e.sec", (u32)s0);
        } else {
            a1 = (u8 *)"sound\\ene\\s%04d_ee.sec";
            sprintf((void *)((u8 *)&stackFrame_20[0]), (void *)"sound\\ene\\s%04d_ee.sec", (u32)s0);
        }
        SND_LoadSecFromFile(4, (u8 *)((u8 *)&stackFrame_20[0]));
        a1 = (u8 *)"sound\\sqmidi\\sq%04d.bnd";
        sprintf((void *)((u8 *)&stackFrame_20[0]), (void *)"sound\\sqmidi\\sq%04d.bnd", (u32)s0);
        SND_SqLoadSqFromFile((char *)((u8 *)&stackFrame_20[0]));
        ReadAllMyEquipSound();
        GameSt[0x2d] = 0xff;
    }
    return;
}

/* RestartMapSe @ 0x1A8D50 .. 0x1A8E04 (0xb4 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1a8d68 writes a register its branch at 0x1a8d64 reads
 *   return without a value in a non-void function
 */


u8 * RestartMapSe(void) {
    u32 v1;
    u32 a0;
    u32 a1;
    u8 *v0;

    v1 = 0xff;
    a0 = GameSt[0x2d];
    if (a0 == v1) {
        SND_SqPlay(0, 0);
        SND_SqFadeStart(0, 2);
        a0 = 1;
        SND_SqPlay(a0, a0);
        SND_SqFadeStart(1, 2);
        a0 = 2;
        SND_SqPlay(a0, a0);
        a0 = 2;
        SND_SqFadeStart(a0, a0);
        a0 = 3;
        SND_SqPlay(a0, a0);
        SND_SqFadeStart(3, 2);
        v0 = (u8 *)GetCamInfo();
        a1 = *(s32 *)(v0 + 4);
        a0 = (u32)v0;
        v0 = (u8 *)GetCamPathData((void *)a0, a1);
        SetCamReverb((void *)(u32)v0);
        v1 = GameSt[0x2c];
        GameSt[0x2d] = v1;
    }
    return;
}
