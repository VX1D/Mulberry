#include "common.h"

#ifndef PROTO_DW_2738554
#define PROTO_DW_2738554
struct dw_2738554 { short top; short num; };
#endif
#ifndef PROTO_DW_2738849
#define PROTO_DW_2738849
struct dw_2738849 { struct dw_2738554 free[16]; struct dw_2738554 alloc[16]; struct dw_2738554 info; };
#endif

static u16 s_SMemInfo[0x80] __attribute__((aligned(16)));
static union {
    u16 raw[0x42];
    struct dw_2738849 mng;
} s_SMemMng;
extern void _SortInsertInfo(void *, s32, s32);
#define HEAD(id) (*(s16 *)((u8 *)(s_SMemMng.raw + 0x20) + (id)))
#define CNT(id) (*(s16 *)((u8 *)(s_SMemMng.raw + 0x21) + (id)))
#define ENT(i) ((u8 *)s_SMemInfo + ((i) << 4))
struct SMInfo { int iSpuAddr; int iSize; short next; short prev; int pad; };
#define EP(i) (&((struct SMInfo *)s_SMemInfo)[i])
#define E_ADDR(i) (EP(i)->iSpuAddr)
#define E_NEXT(i) (EP(i)->next)
#define E_PREV(i) (EP(i)->prev)


#ifndef PROTO_DW_2738649
#define PROTO_DW_2738649
struct dw_2738649 { int iSpuAddr; int iSize; short next; short prev; int pad; };
#endif
#ifndef SPU_MMNG_ALLOC_HELPERS
#define SPU_MMNG_ALLOC_HELPERS
#define SA_INFO(i) (((struct dw_2738649 *)&s_SMemInfo)[i])
#define SA_NEXTOF(i) (*(s16 *)((u8 *)(s_SMemInfo + 4) + ((i) << 4)))
#define SA_PREVOF(i) (*(s16 *)((u8 *)(s_SMemInfo + 5) + ((i) << 4)))
#define SA_ATOP(id) (*(s16 *)((u8 *)(s_SMemMng.raw + 0x20) + ((id) << 2)))
#define SA_ANUM(id) (*(s16 *)((u8 *)(s_SMemMng.raw + 0x21) + ((id) << 2)))
#define SA_MNG (s_SMemMng.mng)
#define SA_ITOP (*(s16 *)(s_SMemMng.raw + 0x40))
#define SA_INUM (*(s16 *)(s_SMemMng.raw + 0x41))

static inline int _SaGetInfo(void) {
    int idx;
    struct dw_2738649 *e;

    if (SA_INUM == 0) {
        return -1;
    }
    SA_INUM = SA_INUM - 1;
    idx = SA_ITOP;
    e = &SA_INFO(idx);
    SA_ITOP = e->next;
    if (e->next != -1) {
        SA_INFO(e->next).prev = -1;
    }
    e->next = -1;
    return idx;
}

static inline void _SaDelFree(struct dw_2738554 *pList, int Index) {
    struct dw_2738649 *pInfo = &SA_INFO(Index);

    if (pList->top == Index) {
        pList->top = pInfo->next;
    }
    pList->num--;
    if (pInfo->prev != -1) {
        SA_NEXTOF(pInfo->prev) = pInfo->next;
    }
    if (pInfo->next != -1) {
        SA_PREVOF(pInfo->next) = pInfo->prev;
    }
    pInfo->prev = -1;
    pInfo->next = -1;
}
#endif


struct SpuInfoEnt { int iSpuAddr; int iSize; short next; short prev; int pad; };
#define INFO ((struct SpuInfoEnt *)s_SMemInfo)
#define INFO_NUM (*(s16 *)(s_SMemMng.raw + 0x41))
#define INFO_TOP (*(s16 *)(s_SMemMng.raw + 0x40))


/* FsSpuMmng_Init @ 0x205E80 .. 0x20603C (0x1bc bytes, frame 0x10) */

extern void * memset(void *, int, unsigned int);

#ifndef PROTO_DW_2738554
#define PROTO_DW_2738554
struct dw_2738554 { short top; short num; };
#endif
#ifndef PROTO_DW_2738849
#define PROTO_DW_2738849
struct dw_2738849 { struct dw_2738554 free[16]; struct dw_2738554 alloc[16]; struct dw_2738554 info; };
#endif
#ifndef PROTO_DW_2738649
#define PROTO_DW_2738649
struct dw_2738649 { int iSpuAddr; int iSize; short next; short prev; int pad; };
#endif

#ifndef SPU_MMNG_HELPERS
#define SPU_MMNG_HELPERS
#define SM_NEXTOF(i) (*(s16 *)((u8 *)(s_SMemInfo + 4) + ((i) << 4)))
#define SM_PREVOF(i) (*(s16 *)((u8 *)(s_SMemInfo + 5) + ((i) << 4)))
#define SM_INFO(i) (((struct dw_2738649 *)&s_SMemInfo)[i])
#define SM_MNG ((struct dw_2738849 *)&s_SMemMng)

static inline void _DelList(struct dw_2738554 *pList, int Index) {
    struct dw_2738649 *pInfo = &SM_INFO(Index);

    if (pList->top == Index) {
        pList->top = pInfo->next;
    }
    pList->num--;
    if (pInfo->prev != -1) {
        SM_NEXTOF(pInfo->prev) = pInfo->next;
    }
    if (pInfo->next != -1) {
        SM_PREVOF(pInfo->next) = pInfo->prev;
    }
    pInfo->prev = -1;
    pInfo->next = -1;
}

static inline void _AddInfoList(int Index) {
    struct dw_2738649 *pInfo = &SM_INFO(Index);

    pInfo->prev = -1;
    pInfo->next = *(s16 *)(s_SMemMng.raw + 0x40);
    *(s16 *)(s_SMemMng.raw + 0x40) = Index;
    SM_MNG->info.num++;
    if (pInfo->next != -1) {
        SM_PREVOF(pInfo->next) = (s16)Index;
    }
}
#endif


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void _SortInsertInfo(void *pList_, signed int Index, signed int unused);
void FsSpuMmng_Init(void);
void FsSpuMmng_AddMemBlock(signed int id, signed int iSpuAddr, signed int iSize);
signed int FsSpuMmng_Alloc(signed int id, signed int iSize);
void FsSpuMmng_Free(signed int id, signed int iSpuAddr);


void _SortInsertInfo(void *pList_, signed int Index, signed int unused) {
    struct dw_2738554 *pList;
    struct dw_2738649 *pInfo;
    struct dw_2738649 *pNext;
    struct dw_2738649 *pPrev;
    short Idx;

    pList = (struct dw_2738554 *)pList_;
    pInfo = &SM_INFO(Index);
    Idx = pList->top;
    if (Idx == -1) {
        pList->top = Index;
        pList->num++;
        pInfo->prev = -1;
        pInfo->next = -1;
        return;
    }
    while (Idx != -1) {
        pNext = &SM_INFO(Idx);
        if (pInfo->iSpuAddr < pNext->iSpuAddr) {
            break;
        }
        Idx = pNext->next;
    }
    if (Idx == -1) {
        pNext->next = Index;
        if (pNext->prev != -1) {
            pInfo->prev = SM_NEXTOF(pNext->prev);
        } else {
            pInfo->prev = pList->top;
        }
        pInfo->next = -1;
        pList->num++;
        if (pNext->iSpuAddr + pNext->iSize == pInfo->iSpuAddr) {
            pNext->iSize = pNext->iSize + pInfo->iSize;
            _DelList(pList, Index);
            _AddInfoList(Index);
        }
    } else {
        pInfo->next = Idx;
        pInfo->prev = pNext->prev;
        pNext->prev = Index;
        if (pInfo->prev != -1) {
            SM_NEXTOF(pInfo->prev) = Index;
        }
        pList->num++;
        if (pList->top == Idx) {
            pList->top = Index;
        }
        if (pInfo->prev != -1) {
            pPrev = &SM_INFO(pInfo->prev);
            if (pInfo->iSpuAddr == pPrev->iSpuAddr + pPrev->iSize) {
                pPrev->iSize = pPrev->iSize + pInfo->iSize;
                _DelList(pList, Index);
                _AddInfoList(Index);
                pInfo = pPrev;
            }
        }
        if (pNext->iSpuAddr == pInfo->iSpuAddr + pInfo->iSize) {
            pInfo->iSize = pInfo->iSize + pNext->iSize;
            _DelList(pList, Idx);
            _AddInfoList(Idx);
        }
    }
}

void FsSpuMmng_Init(void) {
    u8 *t5;
    s32 t4;
    s32 t3;
    s32 t2;
    s32 t1;
    s32 t0;
    s32 a3;
    s32 a2;
    u32 a1;
    s16 a0;
    s32 v1;

    a0 = (u32)s_SMemMng.raw;
    memset((void *)s_SMemMng.raw, 0, 0x84);
    a0 = (u32)s_SMemInfo;
    memset((void *)s_SMemInfo, 0, 0x100);
    a2 = 0;
    a1 = (u32)s_SMemMng.raw;
    a0 = -1;
    do {
        *(s16 *)a1 = a0;
        *(u16 *)((a1 + 2)) = 0;
        a2 = a2 + 8;
        *(s16 *)((a1 + 0x40)) = a0;
        v1 = a2 < (s32)0x10;
        *(u16 *)((a1 + 0x42)) = 0;
        *(s16 *)((a1 + 4)) = a0;
        *(u16 *)((a1 + 6)) = 0;
        *(s16 *)((a1 + 0x44)) = a0;
        *(u16 *)((a1 + 0x46)) = 0;
        *(s16 *)((a1 + 8)) = a0;
        *(u16 *)((a1 + 0xa)) = 0;
        *(s16 *)((a1 + 0x48)) = a0;
        *(u16 *)((a1 + 0x4a)) = 0;
        *(s16 *)((a1 + 0xc)) = a0;
        *(u16 *)((a1 + 0xe)) = 0;
        *(s16 *)((a1 + 0x4c)) = a0;
        *(u16 *)((a1 + 0x4e)) = 0;
        *(s16 *)((a1 + 0x10)) = a0;
        *(u16 *)((a1 + 0x12)) = 0;
        *(s16 *)((a1 + 0x50)) = a0;
        *(u16 *)((a1 + 0x52)) = 0;
        *(s16 *)((a1 + 0x14)) = a0;
        *(u16 *)((a1 + 0x16)) = 0;
        *(s16 *)((a1 + 0x54)) = a0;
        *(u16 *)((a1 + 0x56)) = 0;
        *(s16 *)((a1 + 0x18)) = a0;
        *(u16 *)((a1 + 0x1a)) = 0;
        *(s16 *)((a1 + 0x58)) = a0;
        *(u16 *)((a1 + 0x5a)) = 0;
        *(s16 *)((a1 + 0x1c)) = a0;
        *(u16 *)((a1 + 0x1e)) = 0;
        *(s16 *)((a1 + 0x5c)) = a0;
        *(u16 *)((a1 + 0x5e)) = 0;
        a1 = a1 + 0x20;
    } while ((u32)v1 != 0);
    ((struct dw_2738849 *)&s_SMemMng)->info.top = (u16)0;
    ((struct dw_2738849 *)&s_SMemMng)->info.num = (u16)0x10;
    t4 = 0;
    t5 = (u8 *)s_SMemInfo;
    do {
        *(u32 *)t5 = 0;
        *(u32 *)(t5 + 4) = 0;
        t3 = t4 + 1;
        *(u16 *)(t5 + 8) = t3;
        *(u16 *)(t5 + 0xa) = t4 + -1;
        t2 = t4 + 2;
        *(u32 *)(t5 + 0x10) = 0;
        t1 = t4 + 3;
        *(u32 *)(t5 + 0x14) = 0;
        t0 = t4 + 4;
        *(u16 *)(t5 + 0x18) = t2;
        a3 = t4 + 5;
        *(u16 *)(t5 + 0x1a) = t4;
        a2 = t4 + 6;
        *(u32 *)(t5 + 0x20) = 0;
        a1 = t4 + 7;
        *(u32 *)(t5 + 0x24) = 0;
        a0 = t4 + 8;
        *(u16 *)(t5 + 0x28) = t1;
        t4 = t4 + 8;
        *(u16 *)(t5 + 0x2a) = t3;
        v1 = t4 < (s32)0x10;
        *(u32 *)(t5 + 0x30) = 0;
        *(u32 *)(t5 + 0x34) = 0;
        *(u16 *)(t5 + 0x38) = t0;
        *(u16 *)(t5 + 0x3a) = t2;
        *(u32 *)(t5 + 0x40) = 0;
        *(u32 *)(t5 + 0x44) = 0;
        *(u16 *)(t5 + 0x48) = a3;
        *(u16 *)(t5 + 0x4a) = t1;
        *(u32 *)(t5 + 0x50) = 0;
        *(u32 *)(t5 + 0x54) = 0;
        *(u16 *)(t5 + 0x58) = a2;
        *(u16 *)(t5 + 0x5a) = t0;
        *(u32 *)(t5 + 0x60) = 0;
        *(u32 *)(t5 + 0x64) = 0;
        *(u16 *)(t5 + 0x68) = a1;
        *(u16 *)(t5 + 0x6a) = a3;
        *(u32 *)(t5 + 0x70) = 0;
        *(u32 *)(t5 + 0x74) = 0;
        *(u16 *)(t5 + 0x78) = a0;
        *(u16 *)(t5 + 0x7a) = a2;
        t5 = (u8 *)(t5 + 0x80);
    } while ((u32)v1 != 0);
    ((struct dw_2738649 *)&s_SMemInfo)[15].next = (u16)-1;
    return;
}

void FsSpuMmng_AddMemBlock(signed int id, signed int iSpuAddr, signed int iSize) {
    struct SpuInfoEnt *e;
    s32 idx;

    if (id < 0 || id >= 16) {
        return;
    }
    if (INFO_NUM == 0) {
        idx = -1;
    } else {
        INFO_NUM = INFO_NUM - 1;
        idx = INFO_TOP;
        e = &INFO[idx];
        INFO_TOP = e->next;
        if (e->next != -1) {
            INFO[INFO[idx].next].prev = -1;
        }
        e->next = -1;
    }
    INFO[idx].iSpuAddr = iSpuAddr;
    INFO[idx].iSize = iSize;
    INFO[idx].prev = -1;
    INFO[idx].next = *(s16 *)((u8 *)s_SMemMng.raw + (id << 2));
    *(s16 *)((u8 *)s_SMemMng.raw + (id << 2)) = idx;
    *(s16 *)((u8 *)(s_SMemMng.raw + 1) + (id << 2)) += 1;
    if (INFO[idx].next != -1) {
        *(s16 *)((u8 *)(s_SMemInfo + 5) + (INFO[idx].next << 4)) = (s16)idx;
    }
}

signed int FsSpuMmng_Alloc(signed int id, signed int iSize) {
    int Index;
    struct dw_2738649 *pAlloc;
    int idx;

    pAlloc = 0;
    if (id < 0 || id >= 16) {
        return 0;
    }
    if (iSize <= 0) {
        return 0;
    }
    if (SA_MNG.free[id].num == 0) {
        return 0;
    }
    Index = SA_MNG.free[id].top;
    while (Index != -1) {
        struct dw_2738649 *pInfo = &SA_INFO(Index);

        if (pInfo->iSize >= iSize) {
            if (pInfo->iSize == iSize) {
                _SaDelFree(&SA_MNG.free[id], Index);
                pInfo->prev = -1;
                pInfo->next = SA_ATOP(id);
                SA_ATOP(id) = Index;
                SA_ANUM(id)++;
                if (pInfo->next != -1) {
                    SA_PREVOF(pInfo->next) = (s16)Index;
                }
                return pInfo->iSpuAddr;
            }
            idx = _SaGetInfo();
            if (idx == -1) {
                return 0;
            }
            pAlloc = &SA_INFO(idx);
            pAlloc->iSpuAddr = pInfo->iSpuAddr;
            pAlloc->iSize = iSize;
            pInfo->iSpuAddr += iSize;
            pInfo->iSize -= iSize;
            pAlloc->prev = -1;
            pAlloc->next = SA_ATOP(0);
            SA_ATOP(0) = idx;
            SA_ANUM(0)++;
            if (pAlloc->next != -1) {
                SA_PREVOF(pAlloc->next) = (s16)idx;
            }
            break;
        }
        Index = pInfo->next;
    }
    if (pAlloc == 0) {
        return 0;
    }
    return pAlloc->iSpuAddr;
}

void FsSpuMmng_Free(signed int id, signed int iSpuAddr) {
    s32 Index;
    s32 addr;
    s16 *ph;
    s32 head;

    if (id < 0 || id >= 16) {
        return;
    }
    id = (u32)id << 2;
    ph = &HEAD(id);
    head = *ph;
    if (head == -1) {
        return;
    }
    Index = head;
    while (Index != -1) {
        addr = E_ADDR(Index);
        if (addr == iSpuAddr) {
            if (head == Index) {
                *ph = E_NEXT(Index);
            }
            CNT(id) -= 1;
            if (E_PREV(Index) != -1) {
                *(u16 *)((u8 *)(s_SMemInfo + 4) + (E_PREV(Index) << 4)) = E_NEXT(Index);
            }
            if (E_NEXT(Index) != -1) {
                *(u16 *)((u8 *)(s_SMemInfo + 5) + (E_NEXT(Index) << 4)) = *(s16 *)((u8 *)EP(Index) + 0xa);
            }
            *(s16 *)((u8 *)EP(Index) + 0xa) = -1;
            *(s16 *)((u8 *)EP(Index) + 8) = -1;
            _SortInsertInfo((u8 *)s_SMemMng.raw + id, Index, -1);
            return;
        }
        Index = E_NEXT(Index);
    }
}
