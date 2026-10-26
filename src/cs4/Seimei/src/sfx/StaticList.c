#include "common.h"

/* SList_DeleteAll @ 0x1D0FD0 .. 0x1D0FDC (0xc bytes) */
/*
 * dcomp notes:
 *   tail: j SList_Init at 0x1d0fd4 leaves the function
 */

extern void * SList_Init(void *, unsigned int, unsigned short);

typedef struct { u16 prev; u16 next; } SLDelElem;
typedef struct { u16 head; u16 free; u16 nfree; u16 pad[5]; SLDelElem *elem; } SLDelHeader;


typedef struct { u16 prev, next; } SLPushElem;
typedef struct { u16 head, free, nfree, stride, capacity, limit; u32 buffer; SLPushElem *elem; u8 *data; } SLPushHeader;
extern void *memcpy(void *, const void *, unsigned int);


typedef struct { u16 prev, next; } SLInitElem;
typedef struct { u16 head, free, nfree, stride, capacity, limit; u32 size; SLInitElem *elem; u8 *data; u32 reserved[2]; } SLInitHeader;
extern void *memset(void *, int, unsigned int);


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void *SList_Init(void *memory, unsigned int size, unsigned short stride);
unsigned short SList_PushFront(void *list, void *data);
signed int SList_Delete(void *pSList_, unsigned short hElem_);
void SList_DeleteAll(void *a0 );
void * SList_GetElemPtr(void *a0 , unsigned short a1 );
u16 SList_GetFrontElem(u16 *a0 );
unsigned short SList_GetNextElem(void *a0 , unsigned short a1 );
unsigned short SList_GetExistElemNum(void *a0 );
signed int SList_SetLimitter(void *a0 , unsigned short a1 );

void *SList_Init(void *memory, unsigned int size, unsigned short stride) {
    SLInitHeader *header = memory;
    if (size <= 31) return 0;
    else {
        u16 count;
        SLInitHeader local __attribute__((aligned(16)));
        u16 i;
        u8 alignment;
        local.free = 0;
        count = (u16)(size - 32) / (u16)(stride + 4);
        local.head = -1;
        local.nfree = count;
        local.stride = stride;
        local.capacity = count;
        local.size = size;
        local.limit = -1;
        local.elem = (SLInitElem *)((u8 *)header + 32);
        local.data = (u8 *)header + count * 4 + 32;
        if ((u32)local.data & 15) {
            alignment = 16 - ((u32)local.data & 15);
            local.data += alignment;
            count -= (u8)(alignment / stride + 1);
            local.nfree = count;
            local.capacity = count;
        }
        for (i = 0; i < count; i++) {
            local.elem[i].prev = i - 1;
            local.elem[i].next = i + 1;
        }
        local.elem[0].prev = 0xffff;
        local.elem[count - 1].next = 0xffff;
        memset(local.data, 0, count * stride);
        *header = local;
        return header;
    }
}
unsigned short SList_PushFront(void *list, void *data) {
    SLPushHeader *header = list;
    u16 index;
    if (*(volatile u16 *)((u8 *)list + 4) == 0) return 0xffff;
    if (header->limit != 0xffff && header->limit <= (u16)(header->capacity - header->nfree)) return 0xffff;
    index = header->free;
    header->free = header->elem[index].next;
    if (header->free != 0xffff) header->elem[header->free].prev = 0xffff;
    header->elem[index].prev = 0xffff;
    header->elem[index].next = header->head;
    if (header->head != 0xffff) header->elem[header->head].prev = index;
    header->head = index;
    header->nfree--;
    if (data) memcpy(header->data + index * header->stride, data, header->stride);
    return index;
}

signed int SList_Delete(void *pSList_, unsigned short hElem_) {
    SLDelHeader *pHeader = pSList_;

    if (pHeader->elem[hElem_].prev != 0xffff) {
        pHeader->elem[pHeader->elem[hElem_].prev].next = pHeader->elem[hElem_].next;
    }
    if (pHeader->elem[hElem_].next != 0xffff) {
        pHeader->elem[pHeader->elem[hElem_].next].prev = pHeader->elem[hElem_].prev;
    }
    if (pHeader->elem[hElem_].prev == 0xffff) {
        pHeader->head = pHeader->elem[hElem_].next;
    }
    if (pHeader->free != 0xffff) {
        pHeader->elem[pHeader->free].prev = hElem_;
    }
    pHeader->elem[hElem_].next = pHeader->free;
    pHeader->elem[hElem_].prev = 0xffff;
    pHeader->free = hElem_;
    pHeader->nfree++;
    return 1;
}

void SList_DeleteAll(void *a0 /* r4 */) {
    u32 a2;
    u32 a1;

    a2 = *(u16 *)(((u8 *)a0 + 6));
    a1 = *(s32 *)(((u8 *)a0 + 0xc));
    SList_Init(a0, a1, a2);
    return;
}

/* SList_GetElemPtr @ 0x1D0FA0 .. 0x1D0FD0 (0x30 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1d0fac writes a register its branch at 0x1d0fa8 reads
 *   declaration vs inferred signature: return void * vs inferred u32
 */

void * SList_GetElemPtr(void *a0 /* r4 */, unsigned short a1 /* r5 */) {
    u32 a1_word = a1;
    u32 v0;
    u32 v1;

    a1_word = (u16)a1_word;
    if (a1_word == (u32)0xffff) {
        return (void *)(u32)0;
    }
    v1 = *(u16 *)(((u8 *)a0 + 6));
    v0 = *(s32 *)(((u8 *)a0 + 0x14));
    return (void *)(u32)(v0 + (u32)((u32)(a1_word) * (u32)(v1)));
}

/* SList_GetFrontElem @ 0x1D0F90 .. 0x1D0F98 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lhu at 0x1d0f94 computes the return value
 */

u16 SList_GetFrontElem(u16 *a0 /* r4 */) {
    return *(u16 *)a0;
}

/* SList_GetNextElem @ 0x1D0F70 .. 0x1D0F88 (0x18 bytes) */
/*
 * dcomp notes:
 *   return: lhu at 0x1d0f84 computes the return value
 *   declaration vs inferred signature: return unsigned short vs inferred u16
 */

unsigned short SList_GetNextElem(void *a0 /* r4 */, unsigned short a1 /* r5 */) {
    u32 v1;
    u32 v0;

    v1 = *(s32 *)(((u8 *)a0 + 0x10));
    v0 = a1;
    v0 = v0 << 2;
    return *(u16 *)(((u32)(v0 + v1) + 2));
}

/* SList_GetExistElemNum @ 0x1D0F50 .. 0x1D0F64 (0x14 bytes) */
/*
 * dcomp notes:
 *   return: andi at 0x1d0f60 computes the return value
 *   declaration vs inferred signature: return unsigned short vs inferred u32
 */

unsigned short SList_GetExistElemNum(void *a0 /* r4 */) {
    u32 v1;
    u32 v0;

    v1 = *(u16 *)(((u8 *)a0 + 8));
    v0 = *(u16 *)(((u8 *)a0 + 4));
    return (u16)(v1 - v0);
}

/* SList_SetLimitter @ 0x1D0F10 .. 0x1D0F48 (0x38 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int SList_SetLimitter(void *a0 /* r4 */, unsigned short a1 /* r5 */) {
    u16 v1;
    u16 v0;

    v1 = *(u16 *)(((u8 *)a0 + 8));
    v0 = *(u16 *)(((u8 *)a0 + 4));
    if ((s32)(u16)a1 < (s32)(u16)((u32)(v1) - (u32)(v0))) {
        return 0;
    }
    *(u16 *)(((u8 *)a0 + 0xa)) = a1;
    return 1;
}
