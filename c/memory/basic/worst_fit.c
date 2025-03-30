/*
 * Worst Fit Allocation
 */

#include "common.h"

char mem[MEM_SIZE];
FreeList free_list;

static Node *find_worst_node(size_t size, Node **prev)
{
    Node *cur = free_list.dummy_head.next, 
            *next = NULL, *ptr = NULL;
    *prev = &free_list.dummy_head;
    size_t max_size = 0;

    /* find the max size node */
    while (cur) {
        next = cur->next;
        if (cur->size > max_size) {
            max_size = cur->size;
            ptr = cur;
        }
        *prev = cur;
        cur = next;
    }

    if (!ptr || ptr->size < size) return NULL;

    return ptr;
}

static void *wf_alloc(size_t size)
{
    void *mem_ptr = NULL;
    Node *prev = NULL;
    Node *cur = find_worst_node(size + sizeof(Header), &prev); 
    if (!cur) return NULL;

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
    }

    return mem_ptr;
}

free_func(wf)   /* The implemention of void wf_free(void *ptr) */

int main(void)
{
    init();
                                /* ptr: header+sizeof(header) */
    void *ptr0 = wf_alloc(64);  /* ptr: 0+16   */
    void *ptr1 = wf_alloc(64);  /* ptr: 80+16  */
    void *ptr2 = wf_alloc(64);  /* ptr: 160+16 */
    void *ptr3 = wf_alloc(64);  /* ptr: 240+16 */
    void *ptr4 = wf_alloc(64);  /* ptr: 320+16 */
    void *ptr5 = wf_alloc(64);  /* ptr: 400+16 */
    void *ptr6 = wf_alloc(64);  /* ptr: 480+16 */
    void *ptr7 = wf_alloc(64);  /* ptr: 560+16 */
    void *ptr8 = wf_alloc(64);  /* ptr: 640+16 */
    void *ptr9 = wf_alloc(64);  /* ptr: 720+16 */

    wf_free(ptr1);
    wf_free(ptr3);
    wf_free(ptr4);
    wf_free(ptr5);
    wf_free(ptr7);

    Node *cur = free_list.dummy_head.next;
    PRINT_LIST(cur);

    wf_alloc(64);
    wf_alloc(64);
    wf_alloc(64);
    wf_alloc(64);

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
