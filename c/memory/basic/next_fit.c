/*
 * Next Fit Allocation
 */

#include "common.h"

char mem[MEM_SIZE];
FreeList free_list;
static Node *start = NULL;  /* Point to the start search node */

static void *nf_alloc(size_t size)
{
    Node *cur = free_list.dummy_head.next, 
        *next = NULL, *prev = &free_list.dummy_head;
    void *mem_ptr = NULL;

    if (!cur) return NULL;

    /* find the prev of start node */
    while (cur != start) {
        prev = cur;
        cur = cur->next;
    }

    do {
        next = cur->next;
        if (cur->size >= size + sizeof(Header)) {
            /* set the allocated memory chunk */
            Header *header = (Header *) cur->ptr;
            header->size = size;
            header->magic = MAGIC;
            mem_ptr = (char *) header + sizeof(Header);

            /* update current node */
            cur->size -= size + sizeof(Header);
            cur->ptr = (char *) cur->ptr + size + sizeof(Header);

            /* update free list */
            free_list.free_size -= size + sizeof(Header);
            if (cur->size == 0) {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;   /* start pointer need it */
            }

            break;
        }
        prev = cur;
        cur = next;
        if (!cur) {
            /* a ring: start -> tail -> head -> start */
            cur = free_list.dummy_head.next;
            prev = &free_list.dummy_head;
        }
    } while (cur && cur != start);

    /* update the start pointer */
    start = cur;

    return mem_ptr;
}

free_func(nf)   /* The implemention of void nf_free(void *ptr) */

int main(void)
{
    init();
    start = free_list.dummy_head.next;
                                /* ptr: header+sizeof(header) */
    void *ptr0 = nf_alloc(64);  /* ptr: 0+16   */
    void *ptr1 = nf_alloc(64);  /* ptr: 80+16  */
    void *ptr2 = nf_alloc(64);  /* ptr: 160+16 */
    void *ptr3 = nf_alloc(64);  /* ptr: 240+16 */
    void *ptr4 = nf_alloc(64);  /* ptr: 320+16 */
    void *ptr5 = nf_alloc(64);  /* ptr: 400+16 */
    void *ptr6 = nf_alloc(64);  /* ptr: 480+16 */
    void *ptr7 = nf_alloc(64);  /* ptr: 560+16 */
    void *ptr8 = nf_alloc(64);  /* ptr: 640+16 */
    void *ptr9 = nf_alloc(64);  /* ptr: 720+16 */

    nf_free(ptr1);
    nf_free(ptr3);
    nf_free(ptr4);
    nf_free(ptr5);
    nf_free(ptr7);

    Node *cur = free_list.dummy_head.next;
    PRINT_LIST(cur);

    nf_alloc(64);
    nf_alloc(64);
    nf_alloc(64);
    nf_alloc(64);

    cur = free_list.dummy_head.next;
    PRINT_LIST(cur);

    cur = free_list.dummy_head.next;
    Node *next = NULL;
    while (cur) {
        next = cur->next;
        free(cur);
        cur = next;
    }

    return 0;
}
