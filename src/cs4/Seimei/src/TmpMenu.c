#include "common.h"

/* TmpMenuMng_SetUDBlackDraw @ 0x17DB70 .. 0x17DC34 (0xc4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x17db80 if (..) goto .L0017DBA0
 *   cfg: kept goto: 0x17db9c -> .L0017DC20
 */

extern signed int MngState_UpdateExeCheck(void *);

/* TmpMenuMng_Draw @ 0x17DC40 .. 0x17DE80 (0x240 bytes, frame 0x140) */
/*
 * dcomp notes:
 *   quad: a1: 128-bit web split from its scalar uses
 *   literal: @725 -> 0x22b1f0
 *   fpu: float literal 0x3f800000 at 0x17dc9c
 *   fpu: float literal 0x3e19999a at 0x17dcb4
 *   fpu: float literal 0x3f800000 at 0x17dcd0
 *   fpu: float literal 0x00000000 at 0x17dcf4
 *   fpu: float literal 0x3e19999a at 0x17dd0c
 *   fpu: float literal 0x00000000 at 0x17dd24
 *   fpu: float literal 0x00000000 at 0x17dd50
 *   fpu: float literal 0xc3600000 at 0x17dd78
 *   fpu: float literal 0xc3800000 at 0x17dd84
 *   fpu: float literal 0x42866667 at 0x17dda8
 *   fpu: float literal 0x42333333 at 0x17ddc4
 *   stack: address of the slot at 0x50 escapes at 0x17dde4
 *   stack: address of the slot at 0x40 escapes at 0x17dde4
 *   fpu: float literal 0x43600000 at 0x17de14
 *   fpu: float literal 0x3f800000 at 0x17de1c
 *   stack: address of the slot at 0x50 escapes at 0x17de44
 *   stack: address of the slot at 0x40 escapes at 0x17de44
 *   literal: @725 initializes the 16-byte local at 0x40
 *   cfg: kept branch: 0x17dd4c if (..) goto .L0017DE60
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int MngState_DrawExeCheck(void *);
extern void SetSprite(void *, signed int, signed int, signed int, signed int, signed int *,
    unsigned short, unsigned char);
extern unsigned int * MakeSpritePacketUseSpr(void *, unsigned int *);
extern u32 lpMdlPacketMem;
extern u32 L725[];

#ifndef PROTO_DW_1055454_FIELDS
#define PROTO_DW_1055454_FIELDS
struct dw_1055454_fields { int state; unsigned int flag; unsigned int calc_total_time; unsigned int total_time; unsigned int get_time; unsigned int dmy[3]; };
#endif
#ifndef PROTO_DW_1054843_FIELDS
#define PROTO_DW_1054843_FIELDS
struct dw_1054843_fields { struct dw_1055454_fields mng_state; int DrawState; unsigned char **pTmpMenuFileBuf; float draw_up_rate; unsigned char dmy[12]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1054843_FIELDS_DRAWSTATE_19326D45_DEFINED
#define DCOMP_OFF_STRUCT_DW_1054843_FIELDS_DRAWSTATE_19326D45_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1054843_FIELDS_DRAWSTATE_19326D45 = (int)&(((struct dw_1054843_fields *)0)->DrawState) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1054843_FIELDS_DRAW_UP_RATE_383DDDCC_DEFINED
#define DCOMP_OFF_STRUCT_DW_1054843_FIELDS_DRAW_UP_RATE_383DDDCC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1054843_FIELDS_DRAW_UP_RATE_383DDDCC = (int)&(((struct dw_1054843_fields *)0)->draw_up_rate) - 0 };
#endif
struct TmSp { u8 tm_b[240]; };


/* TmpMenuMng_Update @ 0x17DE80 .. 0x17DEB4 (0x34 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int MngState_UpdateExeCheck(void *);

/* TmpMenuMng_Init @ 0x17DEC0 .. 0x17DF28 (0x68 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int MngState_Init(void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int TmpMenuMng_Init(void *a0 );
signed int TmpMenuMng_Update(void *a0 );
signed int TmpMenuMng_Draw(struct dw_1054843_fields *pTmpMenuMng);
u32 TmpMenuMng_SetUDBlackDraw(void *a0 , int a1 );
signed int TmpMenuMng_CheckDraw(void *a0 );


signed int TmpMenuMng_Init(void *a0 /* r4 */) {
    u32 *s0;
    s32 v0;

    s0 = (u32 *)a0;
    v0 = 0;
    if ((u32)s0 == 0) {
        return v0;
    }
    MngState_Init(a0);
    *(u32 *)(((u8 *)s0 + 0x20)) = 0;
    *(u32 *)(((u8 *)s0 + 0x28)) = 0;
    if ((u32)s0 == 0) {
        if ((u32)s0 != 0) {
            *(u32 *)s0 = 0;
        }
        v0 = 0;
    } else {
        *(u32 *)s0 = 2;
        v0 = 1;
    }
    return v0;
}

signed int TmpMenuMng_Update(void *a0 /* r4 */) {
    s32 v0;

    if ((u32)a0 == 0) {
        v0 = 0;
    } else {
        v0 = MngState_UpdateExeCheck(a0);
        v0 = v0 ^ 1;
        v0 = (u32)v0 < (u32)1;
    }
    return v0;
}

signed int TmpMenuMng_Draw(struct dw_1054843_fields *pTmpMenuMng) {
    unsigned int *lpPacket;
    struct TmSp SpTest;
    float size_d;
    int sx;
    int sy;
    float fx;
    float fy;

    if (pTmpMenuMng == 0) {
        return 0;
    }
    if (MngState_DrawExeCheck(pTmpMenuMng) != 1) {
        return 1;
    }
    lpPacket = (unsigned int *)lpMdlPacketMem;
    if (pTmpMenuMng->DrawState) {
        if (pTmpMenuMng->draw_up_rate < 1.0f) {
            pTmpMenuMng->draw_up_rate += 0.15f;
        }
        if (pTmpMenuMng->draw_up_rate > 1.0f) {
            pTmpMenuMng->draw_up_rate = 1.0f;
        }
    } else {
        if (pTmpMenuMng->draw_up_rate > 0.0f) {
            pTmpMenuMng->draw_up_rate -= 0.15f;
        }
        if (pTmpMenuMng->draw_up_rate < 0.0f) {
            pTmpMenuMng->draw_up_rate = 0.0f;
        }
    }
    if (pTmpMenuMng->DrawState != 0 || pTmpMenuMng->draw_up_rate > 0.0f) {
        int col[4] = {0, 0, 0, 0x7f};

        fx = -256.0f;
        fy = -224.0f;
        size_d = 67.200005f * pTmpMenuMng->draw_up_rate;
        SetSprite(&SpTest, (int)fx, (int)fy - 6, 0x200, (int)(44.8f * pTmpMenuMng->draw_up_rate) + 6, col, 0, 0);
        lpPacket = MakeSpritePacketUseSpr(&SpTest, lpPacket);
        lpPacket = MakeSpritePacketUseSpr(&SpTest, lpPacket);
        SetSprite(&SpTest, (int)fx, (int)(224.0f - size_d), 0x200, (int)(1.0f + size_d), col, 0, 0);
        lpMdlPacketMem = (u32)MakeSpritePacketUseSpr(&SpTest, lpPacket);
    }
    return 1;
}

u32 TmpMenuMng_SetUDBlackDraw(void *a0 /* r4 */, int a1 /* r5 */) {
    u32 s1;
    u8 *s0;
    u32 v0;
    u8 v1;

    s1 = a1;
    s0 = (u8 *)a0;
    v0 = MngState_UpdateExeCheck(a0);
    a0 = (void *)(s32)1;
    if (v0 == (u32)(s32)a0) {
        goto _L0017DBA0;
    }
    v0 = 0;
    goto _L0017DC20;
    _L0017DBA0:;
    v0 = 0;
    if ((u32)s0 == 0) {
        return v0;
    }
    v1 = s1;
    if ((u32)v1 != (u32)(s32)a0) {
        v0 = 2;
        switch ((u32)v1) {
        case 2:
            *(u32 *)(s0 + 0x20) = 0;
            break;
        case 0:
            v0 = *(s32 *)(s0 + 0x20);
            if ((s32)v0 > (s32)0xff) {
                break;
            }
            v0 = v0 + 1;
            *(u32 *)(s0 + 0x20) = v0;
            break;
        }
    } else {
        v0 = *(s32 *)(s0 + 0x20);
        if ((s32)v0 > 0) {
            v0 = v0 + -1;
            *(u32 *)(s0 + 0x20) = v0;
        }
    }
    v0 = 1;
    _L0017DC20:;
    return v0;
}

/* TmpMenuMng_CheckDraw @ 0x17DB40 .. 0x17DB64 (0x24 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x17db44
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int TmpMenuMng_CheckDraw(void *a0 /* r4 */) {
    return 0.0f != *(float *)(((u8 *)a0 + 0x28));
}
