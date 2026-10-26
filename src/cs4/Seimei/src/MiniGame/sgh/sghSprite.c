#include "common.h"

extern u32 GetSpriteDraw(void);
extern u32 sghTime_GetWait(void);
extern void MGSetSprite(void *, signed int, signed int, signed int, signed int, signed int *, unsigned short, unsigned char, signed int, signed int, signed int, signed int, unsigned char);
extern void *GetTexMngByID(unsigned short);
extern unsigned int *MakeTexPacket(unsigned int *, void *);
extern unsigned int *MakeSpritePacketUseSpr(void *, unsigned int *);
extern u32 lpMdlPacketMem;


/* sghSprite_Tutorial @ 0x20F890 .. 0x20F8D8 (0x48 bytes, frame 0x20) */

extern void *sghPad_GetPadInfo(void);
extern void *sghGetGameInfo(void);
extern void sghDrawSprite(unsigned int, signed int);

extern u32 GetMGPrcStatus();


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void sghSprite_BackGround(void);
void sghSprite_Frontend(void);
void sghSprite_Tutorial(void);
void sghDrawSprite(unsigned int number, signed int mode);



/* sghSprite_BackGround @ 0x20FAC0 .. 0x20FBD0 (0x110 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x20fafc writes a register its branch at 0x20faf8 reads
 *   delay: addiu at 0x20fb10 writes a register its branch at 0x20fb0c reads
 *   delay: addiu at 0x20fb24 writes a register its branch at 0x20fb20 reads
 *   delay: addiu at 0x20fb38 writes a register its branch at 0x20fb34 reads
 *   delay: addiu at 0x20fb4c writes a register its branch at 0x20fb48 reads
 *   delay: addiu at 0x20fb60 writes a register its branch at 0x20fb5c reads
 */

void sghSprite_BackGround(void) {
    u32 a1;
    u8 *s0;
    u32 a0;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)sghGetGameInfo();
    s0 = v0;
    a0 = 2;
    sghDrawSprite(a0, 0);
    v1 = *(u8 *)(s0 + 1);
    a1 = 1;
    if (v1 != a1) {
        a0 = *(u8 *)s0;
        v1 = 0x19;
        switch (a0) {
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 9:
        case 12:
        case 13:
        case 14:
        case 15:
        case 18:
        case 23:
            a0 = 3;
            sghDrawSprite(a0, 0);
            break;
        case 24:
            a0 = 5;
            sghDrawSprite(a0, a1);
            break;
        case 25:
            a0 = 5;
            sghDrawSprite(a0, 0);
        }
    }
    return;
}
void sghSprite_Frontend(void) {
    u8 *status;
    u8 *game;
    status = (u8 *)GetMGPrcStatus();
    game = (u8 *)sghGetGameInfo();
    {
        s32 first[2][2] __attribute__((aligned(16))) = {{6,7},{8,9}};
        s32 second[2][2] __attribute__((aligned(16))) = {{10,11},{12,13}};
        s32 third[2][2] __attribute__((aligned(16))) = {{255,255},{255,14}};
        if (game[1] == 1) {
            sghDrawSprite(4,0);
        } else {
            switch (game[0]) {
            case 3: case 4: case 5: case 6:
                sghDrawSprite(15,0);
                sghDrawSprite(16,0);
                break;
            case 24:
                sghDrawSprite(first[status[1]][game[4]],1);
                sghDrawSprite(second[status[1]][game[4]],1);
                sghDrawSprite(third[status[1]][game[4]],1);
                break;
            case 25:
                sghDrawSprite(first[status[1]][game[4]],0);
                sghDrawSprite(second[status[1]][game[4]],0);
                sghDrawSprite(third[status[1]][game[4]],0);
            }
        }
    }
}

void sghSprite_Tutorial(void) {
    u32 v1;
    u8 *s0;
    u32 v0;

    v0 = (u32)sghPad_GetPadInfo();
    s0 = (u8 *)v0;
    v0 = (u32)sghGetGameInfo();
    v1 = *(u8 *)v0;
    if ((s32)v1 > (s32)0x1a) {
        v0 = *(s32 *)(s0 + 8);
        sghDrawSprite(v0 + 0x65, 0);
    }
    return;
}
void sghDrawSprite(unsigned int number, signed int mode) {
    u32 table;
    u32 packet;
    u32 wait;
    u8 sprite[240] __attribute__((aligned(16)));
    s32 color[4] __attribute__((aligned(16)));
    table = GetSpriteDraw();
    packet = lpMdlPacketMem;
    wait = sghTime_GetWait();
    if (number != 255) {
        u8 *entry = (u8 *)(table + number * 112);
        color[0] = *(s32 *)(entry + 0x30);
        color[1] = *(s32 *)(entry + 0x34);
        color[2] = *(s32 *)(entry + 0x38);
        switch (mode) {
        case 1: color[3] = 128 - wait; break;
        case 0: color[3] = *(s32 *)(entry + 0x3c); break;
        case 2: color[3] = wait;
        }
        MGSetSprite(sprite, *(s32 *)(entry+4), *(s32 *)(entry+8), *(s32 *)(entry+12), *(s32 *)(entry+16), color, *(u16 *)entry, 0, *(s32 *)(entry+0x50), *(s32 *)(entry+0x54), *(s32 *)(entry+0x58), *(s32 *)(entry+0x5c), *(u8 *)(entry+0x60));
        packet = (u32)MakeTexPacket((u32 *)packet, GetTexMngByID(((u16 *)sprite)[1]));
        lpMdlPacketMem = (u32)MakeSpritePacketUseSpr(sprite, (u32 *)packet);
    }
}
