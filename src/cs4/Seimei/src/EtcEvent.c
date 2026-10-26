#include "common.h"




extern void FreeMdlMng(void *);
extern void MemFree(void *);
extern void EnePlay(void *);
extern void PlayMi3(void *);
extern signed int SetDrawOTModel(void *, float *, unsigned char);
extern int rand();
extern void EneAppear(signed int, signed int, void *, float *, float, float *, unsigned char,
    unsigned short, unsigned char, void *, void *);
signed int EtcEventMng_EneExtGeneEvent_End(void *a0 /* r4 */);
signed int EtcEventMng_EneExtGeneEvent_Update(void *a0 /* r4 */);
signed int EtcEventMng_EneExtGeneEvent_Start_Corpse(void *a0 /* r4 */);


/* EtcEventMng_EneExtGeneEvent_Start_Room @ 0x1913D0 .. 0x191678 (0x2a8 bytes, frame 0xb0) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: __FUNCTION__$715 is the string 'EtcEventMng_EneExtGeneEvent_Start_Room'
 *   literal: @907 is the string ''
 *   literal: @730 -> 0x22c380
 *   literal: @732 -> 0x22c390
 *   literal: @734 -> 0x22c3a0
 *   stack: address of the slot at 0x98 escapes at 0x191510
 *   stack: address of the slot at 0x84 escapes at 0x191510
 *   fpu: float literal 0x3c23d70a at 0x19154c
 *   fpu: float literal 0x41080000 at 0x191554
 *   fpu: mtc1 reinterprets v0 at 0x19155c
 *   fpu: float literal 0x3c23d70a at 0x191594
 *   fpu: mtc1 reinterprets a0 at 0x19159c
 *   fpu: float literal 0x40f00000 at 0x1915a4
 *   fpu: float literal 0x3dcccccd at 0x1915f8
 *   fpu: mtc1 reinterprets v0 at 0x191600
 *   stack: address of the slot at 0x90 escapes at 0x19162c
 *   stack: address of the slot at 0xa0 escapes at 0x19162c
 *   literal: @734 initializes the 16-byte local at 0x80
 *   literal: @732 initializes the 16-byte local at 0x90
 *   literal: @730 initializes the 16-byte local at 0xa0
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void * MemAllocReal(unsigned int, char *, char *);




struct dw_1348374_fields;
struct dw_1352783_fields;
#ifndef PROTO_DW_1355604_FIELDS
#define PROTO_DW_1355604_FIELDS
struct dw_1355604_fields { int state; unsigned int flag; unsigned int calc_total_time; unsigned int total_time; unsigned int get_time; unsigned int dmy[3]; };
#endif
#ifndef PROTO_DW_1352498_FIELDS
#define PROTO_DW_1352498_FIELDS
struct dw_1352498_fields { int state; struct dw_1352783_fields *pMdlMng; struct dw_1348374_fields *pEneCtrl; unsigned int ene_num; unsigned int counter; unsigned int dmy[3]; };
#endif
#ifndef PROTO_DW_1351970_FIELDS
#define PROTO_DW_1351970_FIELDS
struct dw_1351970_fields { struct dw_1355604_fields mng_state; int DrawState; unsigned char **pEtcEventFileBuf; struct dw_1352498_fields EneExtGeneEventData; };
#endif

struct EneMdlE { u8 bUse; u8 pad[0x1bf]; };
struct EneCtrlE { u8 pad[0x260]; };
#define MemAllocF(n) MemAllocReal((n), (char *)__FUNCTION__, "")
signed int EtcEventMng_EneExtGeneEvent_Start_Room(void *a0) {
    struct dw_1352498_fields *d = &((struct dw_1351970_fields *)a0)->EneExtGeneEventData;
    int i;

    if (d->state != 0) {
        d->state = 0;
        for (i = 0; i < d->ene_num; i++) {
            FreeMdlMng((u8 *)d->pMdlMng + i * 0x1c0);
        }
        MemFree(d->pMdlMng);
        d->pMdlMng = 0;
        MemFree(d->pEneCtrl);
        d->pEneCtrl = 0;
    }
    d->state = 1;
    d->ene_num = 0x1e;
    d->counter = 0;
    d->pMdlMng = MemAllocF(d->ene_num * 0x1c0);
    d->pEneCtrl = MemAllocF(d->ene_num * 0x260);
    { int j; for (j = 0; j < d->ene_num; j++) {
        ((struct EneMdlE *)d->pMdlMng)[j].bUse = 0;
    } }
    for (i = 0; i < (d->ene_num >> 1); i++) {
        float vPos[4] = {1.0f, 1.0f, 1.0f, 1.0f};
        float vAng[4] = {0.0f, -1.3f, 0.0f, 1.0f};

        vAng[0] = 8.5f + 0.01f * (float)(rand() % 300);
        vAng[2] = 7.5f + 0.01f * (float)(rand() % 300);
        {
            float vDir[4] = {0.0f, 0.0f, 0.0f, 1.0f};

            vDir[1] = 0.1f * (float)(rand() % 3600);
            EneAppear(0x10, 1, (u8 *)d->pMdlMng + i * 0x1c0, vAng, vDir[1], vPos, 1, 0xffff, 0, (u8 *)d->pEneCtrl + i * 0x260, 0);
        }
    }
    return 1;
}








/* EtcEventMng_EneExtGeneEvent_Start_Corpse @ 0x191260 .. 0x1913C8 (0x168 bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: a2: 128-bit web split from its scalar uses
 *   literal: @750 -> 0x22c3b0
 *   literal: @752 -> 0x22c3c0
 *   literal: @754 -> 0x22c3d0
 *   stack: address of the slot at 0x74 escapes at 0x1912d0
 *   fpu: float literal 0x3dcccccd at 0x191320
 *   fpu: mtc1 reinterprets v0 at 0x191328
 *   stack: address of the slot at 0x80 escapes at 0x19137c
 *   stack: address of the slot at 0x90 escapes at 0x19137c
 *   literal: @754 initializes the 16-byte local at 0x70
 *   literal: @752 initializes the 16-byte local at 0x80
 *   literal: @750 initializes the 16-byte local at 0x90
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int EtcEventMng_EneExtGeneEvent_Start_Corpse(void *a0 /* r4 */) {
    u8 *a3;
    u32 a1;
    u8 *s4;
    s32 s3;
    s32 s2;
    s32 s1;
    float *s0;
    u32 v1;
    u32 v0;
    s32 hi;
    float f0;
    struct stackFrame_90 { u8 b[16]; } stackFrame_90 __attribute__((aligned(16)));
    struct stackFrame_80 { u8 b[16]; } stackFrame_80 __attribute__((aligned(16)));
    struct stackFrame_70 { u8 b[16]; } stackFrame_70 __attribute__((aligned(16)));

    v0 = 1;
    v1 = *(s32 *)(((u8 *)a0 + 0x28));
    s4 = (u8 *)((u8 *)a0 + 0x28);
    if (v1 != v0) {
        v0 = 0;
    } else {
        *(u32 *)s4 = 2;
        v0 = *(s32 *)(s4 + 0xc);
        s3 = v0 >> 1;
        if ((u32)s3 < v0) {
            v0 = (u32)s3 << 3;
            s0 = (float *)((u8 *)&stackFrame_70 + 0x4);
            v1 = v0 - s3;
            v0 = v0 + s3;
            s2 = v1 << 6;
            v0 = v0 << 1;
            s1 = (u32)(v0 + s3) << 5;
            do {
                v0 = 0x22c3b0;
                a3 = ((u8 *)&stackFrame_90);
                a0 = (void *)0x22c3c0;
                a1 = (u32)((u8 *)&stackFrame_80);
                v1 = (u32)((u8 *)&stackFrame_70);
                stackFrame_90 = (struct stackFrame_90){{0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80,
                    0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f}};
                v0 = 0x22c3d0;
                stackFrame_80 = (struct stackFrame_80){{0x33, 0x33, 0x1b, 0x41, 0x66, 0x66, 0xa6,
                    0xbf, 0xcd, 0xcc, 0x2c, 0x41, 0x00, 0x00, 0x80, 0x3f}};
                stackFrame_70 = (struct stackFrame_70){{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f}};
                v0 = rand();
                a0 = (void *)(s32)0xe10;
                v1 = 0x3dcc0000;
                hi = (s32)v0 % (s32)(0xe10);
                v0 = 0x3dcc0000 | 0xcccd;
                f0 = 0.100000001f;
                *(f32 *)s0 = (0.100000001f * (float)((float)(s32)(u32)hi));
                v0 = *(s32 *)(s4 + 4);
                FreeMdlMng((void *)(u32)(v0 + s2));
                v0 = *(s32 *)(s4 + 8);
                a1 = 1;
                v0 = v0 + s1;
                EneAppear(0x10, a1, (void *)(s32)((*(s32 *)(s4 + 4)) + s2), (float *)(u8 *)((u8 *)&stackFrame_80),
                    *(float *)s0, (float *)(u8 *)((u8 *)&stackFrame_90), a1, 0xffff, 0, (void
                    *)(s32)v0, (void *)0);
                v0 = *(s32 *)(s4 + 0xc);
                s3 = s3 + 1;
                s2 = s2 + 0x1c0;
                v0 = (u32)s3 < v0;
                s1 = s1 + 0x260;
            } while (v0 != 0);
        }
        v0 = 1;
    }
    return v0;
}







/* EtcEventMng_EneExtGeneEvent_Update @ 0x191190 .. 0x191254 (0xc4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001911D8
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int EtcEventMng_EneExtGeneEvent_Update(void *a0 /* r4 */) {
    u8 *a1;
    u8 *s1;
    s32 s0;
    u8 *s3;
    s32 s2;
    u32 v1;
    u32 v0;
    void *a0_2;

    v0 = *(s32 *)(((u8 *)a0 + 0x28));
    s1 = (u8 *)((u8 *)a0 + 0x28);
    if (v0 == 0) {
        v0 = 0;
    } else {
        v0 = *(s32 *)(s1 + 0xc);
        s0 = 0;
        if ((u8 *)0 < (u8 *)v0) {
            s2 = 0;
            do {
                v0 = *(s32 *)(s1 + 4);
                s3 = (u8 *)(s32)(v0 + s2);
                v0 = *(u8 *)s3;
                a0_2 = (void *)s3;
                if (v0 != 0) {
                    EnePlay(a0_2);
                    PlayMi3((void *)(u8 *)s3);
                    a1 = (u8 *)(s3 + 0x20);
                    SetDrawOTModel((void *)(u8 *)s3, (float *)a1, *(u8 *)(s3 + 6));
                }
                v0 = *(s32 *)(s1 + 0xc);
                s0 = s0 + 1;
                v0 = (u32)s0 < v0;
                s2 = s2 + 0x1c0;
            } while (v0 != 0);
        }
        v1 = *(s32 *)(s1 + 0x10);
        v0 = 1;
        *(u32 *)(s1 + 0x10) = v1 + 1;
    }
    return v0;
}


/* EtcEventMng_EneExtGeneEvent_End @ 0x1910F0 .. 0x191188 (0x98 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int EtcEventMng_EneExtGeneEvent_End(void *a0 /* r4 */) {
    s32 s2;
    u8 *s1;
    s32 s0;
    u32 v0;
    void *a0_2;

    v0 = *(s32 *)(((u8 *)a0 + 0x28));
    s1 = (u8 *)((u8 *)a0 + 0x28);
    if (v0 == 0) {
        v0 = 1;
    } else {
        *(u32 *)s1 = 0;
        v0 = *(s32 *)(s1 + 0xc);
        s2 = 0;
        if ((u8 *)0 < (u8 *)v0) {
            s0 = 0;
            do {
                v0 = *(s32 *)(s1 + 4);
                FreeMdlMng((void *)(u32)(v0 + s0));
                v0 = *(s32 *)(s1 + 0xc);
                s2 = s2 + 1;
                v0 = (u32)s2 < v0;
                s0 = s0 + 0x1c0;
            } while (v0 != 0);
        }
        a0_2 = (void *)*(s32 *)(s1 + 4);
        MemFree(a0_2);
        *(u32 *)(s1 + 4) = 0;
        MemFree((void *)*(s32 *)(s1 + 8));
        *(u32 *)(s1 + 8) = 0;
        v0 = 1;
    }
    return v0;
}


u32 g_EtcEventMng[0x12];
