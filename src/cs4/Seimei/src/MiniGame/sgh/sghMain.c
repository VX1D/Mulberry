#include "common.h"

/* sghMainLoop @ 0x20BE20 .. 0x20BF54 (0x134 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x20be44 if (..) goto .L0020BE58
 *   cfg: loop header already being structured: .L0020BE78
 */

extern signed int CheckVagStmState(unsigned char);
extern u32 sghGetGameInfo();
extern void PlayGeneralVagStm(signed int);
extern void ClearTime();
extern void KickMdlPacket();
extern void sghMode_Execute();
extern void sghPad_Execute();
extern void DrawCalcView();
extern void sghDraw();
extern void sghMsg_Execute();
extern void SND_Update();
extern void DrawFrameFilter();
extern void DrawSynch();
extern u32 GetTime();
extern void FlushCache(int);
extern u32 GameSt[];
extern u32 lpDrawMng;

u32 sghMainLoop(void) {
    u32 a0;
    u32 v0;
    u32 v1;
    s32 s0;

    a0 = 5;
    v0 = CheckVagStmState(a0);
    v1 = v0 + -1;
    s0 = 0;
    if (v1 > (u32)2) {
        v1 = 4;
        if (v0 != v1) {
            goto _L0020BE58;
        }
    }
    s0 = 1;
    _L0020BE58:;
    v0 = sghGetGameInfo();
    *(u8 *)((v0 + 1)) = 0;
    *(u8 *)v0 = 0;
    *(u8 *)((v0 + 3)) = 0;
    *(u8 *)((v0 + 2)) = 0;
    *(u8 *)((v0 + 7)) = 0;
    *(u8 *)((v0 + 8)) = 0;
    while (1) {
        a0 = 5;
        if ((u32)s0 == 0) {
            v0 = CheckVagStmState(a0);
            a0 = 1;
            if (v0 == 0) {
                PlayGeneralVagStm(a0);
                s0 = 1;
            }
        }
        ClearTime();
        v0 = *(s32 *)GameSt;
        v0 = v0 + 1;
        *(u32 *)GameSt = v0;
        KickMdlPacket();
        sghMode_Execute();
        v0 = sghGetGameInfo();
        v0 = *(u8 *)((v0 + 1));
        v0 = v0 ^ 2;
        v0 = v0 < (u32)1;
        if (v0 != 0) {
            break;
        }
        sghPad_Execute();
        DrawCalcView();
        sghDraw();
        sghMsg_Execute();
        SND_Update();
        DrawFrameFilter();
        DrawSynch();
        v0 = GetTime();
        v1 = lpDrawMng;
        *(u32 *)((v1 + 0x418)) = v0;
        FlushCache(0);
    }
    v0 = 1;
    return v0;
}
