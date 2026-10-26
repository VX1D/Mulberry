#include "common.h"

/* __sghDraw_Dice @ 0x2087E0 .. 0x208880 (0xa0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   call: sghGetGameInfo is declared void but its v0 is read: called as returning u32
 *   cfg: loop body is not one contiguous region: .L00208808
 */

extern void sghGetGameInfo(void);
extern void MasterMove(void *);
extern void PlayMi3(void *);
extern void sghDice_AnimeExecute(void *);
extern unsigned int CheckDrawModel(void *);
extern void DrawModel(void *);
extern void MGDrawShadow(void *);
extern u32 MdlMng[];

/* __sghDraw_Koma @ 0x208880 .. 0x208920 (0xa0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   call: sghGetGameInfo is declared void but its v0 is read: called as returning u32
 *   cfg: loop body is not one contiguous region: .L002088A8
 */




extern void sghKoma_AnimeExecute(void *);

/* sghDraw @ 0x208920 .. 0x208A44 (0x124 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x208948 writes a register its branch at 0x208944 reads
 *   cfg: loop body is not one contiguous region: .L002089C8
 */

extern u32 GetMGPrcStatus(void);
extern void sghGetGameInfo(void);
extern void sghSprite_BackGround(void);
extern void MasterMove(void *);
extern void PlayMi3(void *);
extern unsigned int CheckDrawModel(void *);
extern void DrawModel(void *);
static void __sghDraw_Koma(void);
static void __sghDraw_Dice(void);
extern void sghSprite_Frontend(void);
extern void sghSprite_Tutorial(void);
extern u32 MdlMng[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void sghDraw(void);
static void __sghDraw_Koma(void);
static void __sghDraw_Dice(void);


void sghDraw(void) {
    u32 v0;
    u32 s0;
    u32 a0;
    s32 v1;
    u8 *s1;

    v0 = GetMGPrcStatus();
    s0 = v0;
    sghGetGameInfo();
    a0 = *(u8 *)((s0 + 1));
    v1 = 2;
    switch (a0) {
    case 0:
    case 1:
        sghSprite_BackGround();
        s0 = (u32)((u8 *)MdlMng + 0x5400);
        v0 = *(u8 *)s0;
        a0 = s0;
        if (v0 != 0) {
            MasterMove((void *)a0);
            a0 = s0;
            PlayMi3((void *)a0);
            a0 = s0;
            v0 = CheckDrawModel((void *)a0);
            a0 = s0;
            if (v0 != 0) {
                DrawModel((void *)a0);
            }
        }
        __sghDraw_Koma();
        s0 = 0;
        s1 = (u8 *)MdlMng + 0x174c0;
        do {
            v0 = *(u8 *)s1;
            a0 = (u32)s1;
            if (v0 != 0) {
                MasterMove((void *)a0);
                a0 = (u32)s1;
                PlayMi3((void *)a0);
                a0 = (u32)s1;
                v0 = CheckDrawModel((void *)a0);
                a0 = (u32)s1;
                if (v0 != 0) {
                    DrawModel((void *)a0);
                }
            }
            s0 = s0 + 1;
            v0 = s0 < (u32)2;
            s1 = (u8 *)(s32)((u8 *)s1 + 0x1c0);
        } while (v0 != 0);
        __sghDraw_Dice();
        sghSprite_Frontend();
        break;
    case 2:
        sghSprite_Tutorial();
    }
    return;
}





static void __sghDraw_Koma(void) {
    extern u32 sghGetGameInfo(void);
    u32 v1;
    u8 *s2;
    u8 *s1;
    s32 s0;
    u32 v0;

    v0 = sghGetGameInfo();
    s2 = (u8 *)v0;
    s0 = 0;
    s1 = (u8 *)MdlMng + 0x119c0;
    do {
        v1 = *(u8 *)s1;
        if (v1 != 0) {
            v0 = *(u8 *)(s2 + 1);
            if (v0 == 0) {
                MasterMove((void *)(u8 *)s1);
                PlayMi3((void *)(u8 *)s1);
                sghKoma_AnimeExecute((void *)(u8 *)s1);
            }
            v0 = CheckDrawModel((void *)(u8 *)s1);
            if (v0 != 0) {
                DrawModel((void *)(u8 *)s1);
                MGDrawShadow((void *)(u8 *)s1);
            }
        }
        s0 = s0 + 1;
        v1 = (u32)s0 < (u32)0x20;
        s1 = (u8 *)(s1 + 0x1c0);
    } while (v1 != 0);
    return;
}

static void __sghDraw_Dice(void) {
    extern u32 sghGetGameInfo(void);
    u32 v1;
    u8 *s2;
    u8 *s1;
    s32 s0;
    u32 v0;

    v0 = sghGetGameInfo();
    s2 = (u8 *)v0;
    s0 = 0;
    s1 = (u8 *)MdlMng + 0x17140;
    do {
        v1 = *(u8 *)s1;
        if (v1 != 0) {
            v0 = *(u8 *)(s2 + 1);
            if (v0 == 0) {
                MasterMove((void *)(u8 *)s1);
                PlayMi3((void *)(u8 *)s1);
                sghDice_AnimeExecute((void *)(u8 *)s1);
            }
            v0 = CheckDrawModel((void *)(u8 *)s1);
            if (v0 != 0) {
                DrawModel((void *)(u8 *)s1);
                MGDrawShadow((void *)(u8 *)s1);
            }
        }
        s0 = s0 + 1;
        v1 = (u32)s0 < (u32)2;
        s1 = (u8 *)(s1 + 0x1c0);
    } while (v1 != 0);
    return;
}
