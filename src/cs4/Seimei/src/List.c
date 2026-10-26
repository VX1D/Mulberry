#include "common.h"

/* ListMng_GetNextId @ 0x17D0C0 .. 0x17D160 (0xa0 bytes, frame 0x20) */

extern signed int MngState_DrawExeCheck(void *);


typedef struct { s32 next; s32 prev; } ListNode;


extern void * memcpy(void *, const void *, unsigned int);

struct ListM { u8 pad0[0x20]; u8 type; u8 pad1[3]; ListNode *pList; u8 *pData; u8 cmpType; u8 pad2[3]; u32 elem; s32 keyOff; s32 pad3; s32 head; s32 tail; };


/* ListMng_Delete @ 0x17D5E0 .. 0x17D630 (0x50 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void MemFree(void *);

/* ListMng_Init @ 0x17D630 .. 0x17D8A0 (0x270 bytes, frame 0x80) */

extern signed int MngState_Init(void *);
extern void * MemAllocReal(unsigned int, char *, char *);

typedef struct {
    u32 state;
    u8 pad0[0x1c];
    u8 type;
    u8 pad1[3];
    ListNode *pNodes;
    void *pDataTop;
    u8 type_type;
    u8 pad2[3];
    u32 data_size;
    u32 key_offset;
    s32 node_num;
    s32 head;
    s32 tail;
    u32 count;
} ListMng;

static inline void ListMng_Free(ListMng *p) {
    if (p != 0) {
        MemFree(p->pNodes);
        p->pNodes = 0;
    }
}

static inline signed int ListMng_Alloc(ListMng *p) {
    ListNode *n;

    if (p == 0) {
        return 0;
    }
    ListMng_Free(p);
    n = (ListNode *)MemAllocReal(p->node_num * 8, "ListMng_Alloc", "");
    p->pNodes = n;
    if (n == 0) {
        return 0;
    }
    return 1;
}

static inline void ListMng_Reset(ListMng *p) {
    int i;

    if (p != 0) {
        for (i = 0; i < p->node_num; i++) {
            p->pNodes[i].next = i + 1;
            p->pNodes[i].prev = i - 1;
        }
        p->pNodes[0].next = (p->node_num + 1) % p->node_num;
        p->pNodes[0].prev = p->node_num - 1;
        p->pNodes[p->node_num - 1].next = 0;
        p->pNodes[p->node_num - 1].prev = (p->node_num + p->node_num - 2) % p->node_num;
    }
}


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int ListMng_Init(ListMng *pListMng, void *pDataTop, int node_num, unsigned int data_size, unsigned int key_offset, int type, int type_type);
signed int ListMng_Delete(void *a0 );
signed int ListMng_AddList(struct ListM *m, unsigned char *pData);
signed int ListMng_RemoveList(void *a0 );
signed int ListMng_GetNextId(void *a0 );


signed int ListMng_Init(ListMng *pListMng, void *pDataTop, int node_num, unsigned int data_size, unsigned int key_offset, int type, int type_type) {
    if (pListMng == 0) {
        return 0;
    }
    if (pDataTop == 0) {
        return 0;
    }
    if (node_num <= 0) {
        return 0;
    }
    if (data_size == 0) {
        return 0;
    }
    if ((unsigned char)type >= 4) {
        return 0;
    }
    if ((unsigned char)type_type >= 0xd) {
        return 0;
    }
    MngState_Init(pListMng);
    pListMng->type = type;
    pListMng->pNodes = 0;
    pListMng->pDataTop = pDataTop;
    pListMng->data_size = data_size;
    pListMng->key_offset = key_offset;
    pListMng->node_num = node_num;
    pListMng->head = -1;
    pListMng->tail = -1;
    pListMng->count = 0;
    pListMng->type_type = type_type;
    if (ListMng_Alloc(pListMng) != 1) {
        if (pListMng != 0) {
            ListMng_Free(pListMng);
            pListMng->state = 0;
        }
        return 0;
    }
    ListMng_Reset(pListMng);
    pListMng->state = 2;
    return 1;
}

signed int ListMng_Delete(void *a0 /* r4 */) {
    u8 *s0;

    s0 = (u8 *)a0;
    if ((u32)s0 == 0) {
        return 0;
    }
    if ((u32)s0 != 0) {
        MemFree((void *)*(s32 *)(s0 + 0x24));
        *(u32 *)(s0 + 0x24) = 0;
    }
    *(u32 *)s0 = 0;
    return 1;
}

signed int ListMng_AddList(struct ListM *m, unsigned char *pData) {
    unsigned char *pPriorityData_End;
    unsigned int exchange;
    int now_node_id;
    unsigned int loop_end;

    if (m == 0) {
        return -1;
    }
    if (pData == 0) {
        return -1;
    }
    if (MngState_DrawExeCheck(m) != 1) {
        return -1;
    }
    if (m->head == -1) {
        m->tail = 0;
        m->head = 0;
        memcpy(m->pData, pData, m->elem);
        return 0;
    }
    if (m->head == m->pList[m->tail].next) {
        pPriorityData_End = m->pData + m->elem * m->tail + m->keyOff;
        exchange = 0;
        switch (m->cmpType) {
        case 7:
            if (*(unsigned int *)pPriorityData_End < *(unsigned int *)(pData + m->keyOff)) {
                exchange = 1;
            }
        }
        if (exchange == 1) {
            switch (m->type) {
            case 0:
                return -1;
            case 1:
            case 2:
                return -1;
            case 3:
                memcpy(m->pData + m->elem * m->tail, pData, m->elem);
                break;
            }
        } else {
            return -1;
        }
    }
    switch (m->type) {
    case 0:
        return -1;
    case 1:
    case 2:
        m->tail = m->pList[m->tail].next;
        now_node_id = m->tail;
        memcpy(m->pData + m->elem * now_node_id, pData, m->elem);
        return now_node_id;
    case 3:
        m->tail = m->pList[m->tail].next;
        now_node_id = m->tail;
        memcpy(m->pData + m->elem * now_node_id, pData, m->elem);
        do {
            unsigned char *pPriorityData_prev;
            unsigned char *pPriorityData_now;
            int prev_node_id;
            unsigned int exchange;
            exchange = 0;
            loop_end = 1;
            if (now_node_id == m->head) {
                break;
            }
            prev_node_id = m->pList[now_node_id].prev;
            pPriorityData_prev = m->pData + m->elem * prev_node_id + m->keyOff;
            pPriorityData_now = m->pData + m->elem * now_node_id + m->keyOff;
            switch (m->cmpType) {
            case 7:
                if (*(unsigned int *)pPriorityData_prev < *(unsigned int *)pPriorityData_now) {
                    exchange = 1;
                }
            }
            if (exchange == 1) {
                m->pList[now_node_id].prev = m->pList[prev_node_id].prev;
                m->pList[prev_node_id].next = m->pList[now_node_id].next;
                m->pList[m->pList[prev_node_id].prev].next = now_node_id;
                m->pList[m->pList[now_node_id].next].prev = prev_node_id;
                m->pList[now_node_id].next = prev_node_id;
                m->pList[prev_node_id].prev = now_node_id;
                if (now_node_id == m->tail) {
                    m->tail = prev_node_id;
                }
                if (prev_node_id == m->head) {
                    m->head = now_node_id;
                }
                loop_end = 0;
            }
        } while (loop_end != 1);
        return now_node_id;
    default:
        return -1;
    }
}


signed int ListMng_RemoveList(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    s32 idx;
    s32 ret;
    ListNode *list;

    s0 = (u8 *)a0;
    if (s0 == 0) {
        return 0;
    }
    if (MngState_DrawExeCheck(a0) != 1) {
        return 1;
    }
    v1 = *(u8 *)(s0 + 0x20);
    ret = 3;
    switch (v1) {
    case 0:
        return 0;
    case 1:
        if (*(s32 *)(s0 + 0x3c) == *(s32 *)(s0 + 0x40)) {
            *(s32 *)(s0 + 0x3c) = -1;
            *(s32 *)(s0 + 0x40) = -1;
            ret = 1;
        } else {
            ret = 1;
            list = *(ListNode **)(s0 + 0x24);
            idx = *(s32 *)(s0 + 0x40);
            *(s32 *)(s0 + 0x40) = list[idx].prev;
        }
        break;
    case 2:
    case 3:
        if (*(s32 *)(s0 + 0x3c) == *(s32 *)(s0 + 0x40)) {
            *(s32 *)(s0 + 0x3c) = -1;
            *(s32 *)(s0 + 0x40) = -1;
            ret = 1;
        } else {
            idx = *(s32 *)(s0 + 0x3c);
            ret = 1;
            *(s32 *)(s0 + 0x3c) = (*(ListNode **)(s0 + 0x24))[idx].next;
        }
        break;
    default:
        ret = 0;
    }
    return ret;
}

signed int ListMng_GetNextId(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;

    s0 = (u8 *)a0;
    if (s0 == 0) {
        return -1;
    }
    if (MngState_DrawExeCheck(a0) != 1) {
        return 1;
    }
    v1 = *(u8 *)(s0 + 0x20);
    switch (v1) {
    case 0:
        return -1;
    case 1:
        return *(s32 *)(s0 + 0x40);
    case 2:
    case 3:
        return *(s32 *)(s0 + 0x3c);
    default:
        return -1;
    }
}
