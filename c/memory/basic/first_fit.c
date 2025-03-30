/*
 * First Fit Allocation
 */

#include "common.h"

char mem[MEM_SIZE];
FreeList free_list;

static void *ff_alloc(size_t size)
{
    Node *cur = free_list.dummy_head.next, 
         *next = NULL, *prev = &free_list.dummy_head;
    void *mem_ptr = NULL;

    while (cur) {
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
            }

            break;
        }
        prev = cur;
        cur = next;
    }

    return mem_ptr;
}

free_func(ff)   /* The implemention of void ff_free(void *ptr) */

int main(void)
{
    init();
                                /* ptr: header+sizeof(header) */
    void *ptr0 = ff_alloc(64);  /* ptr: 0+16   */
    void *ptr1 = ff_alloc(64);  /* ptr: 80+16  */
    void *ptr2 = ff_alloc(64);  /* ptr: 160+16 */
    void *ptr3 = ff_alloc(64);  /* ptr: 240+16 */
    void *ptr4 = ff_alloc(64);  /* ptr: 320+16 */
    void *ptr5 = ff_alloc(64);  /* ptr: 400+16 */
    void *ptr6 = ff_alloc(64);  /* ptr: 480+16 */
    void *ptr7 = ff_alloc(64);  /* ptr: 560+16 */
    void *ptr8 = ff_alloc(64);  /* ptr: 640+16 */
    void *ptr9 = ff_alloc(64);  /* ptr: 720+16 */

    ff_free(ptr1);
    ff_free(ptr3);
    ff_free(ptr4);
    ff_free(ptr5);
    ff_free(ptr7);

    Node *cur = free_list.dummy_head.next;
    PRINT_LIST(cur);

    ff_alloc(64);
    ff_alloc(64);
    ff_alloc(64);
    ff_alloc(64);

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
