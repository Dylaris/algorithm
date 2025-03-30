/*
 * Best Fit Allocation
 */

#include "common.h"

char mem[MEM_SIZE];
FreeList free_list;

static Node *find_best_node(size_t size, Node **prev)
{
    Node *cur = free_list.dummy_head.next, 
            *next = NULL, *ptr = NULL;
    *prev = &free_list.dummy_head;
    int min_diff = MEM_SIZE;    /* difference between cur->size and size */

    while (cur) {
        next = cur->next;
        if (cur->size > size) {
            if (cur->size - size < min_diff) {
                min_diff = cur->size - size;
                ptr = cur;
            }
        }
        else if (cur->size == size)
            return cur;
        *prev = cur;
        cur = next;
    }

    return ptr;
}

static void *bf_alloc(size_t size)
{
    void *mem_ptr = NULL;
    Node *prev = NULL;
    Node *cur = find_best_node(size + sizeof(Header), &prev); 
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

free_func(bf)   /* The implemention of void bf_free(void *ptr) */

int main(void)
{
    init();
                                /* ptr: header+sizeof(header) */
    void *ptr0 = bf_alloc(64);  /* ptr: 0+16   */
    void *ptr1 = bf_alloc(64);  /* ptr: 80+16  */
    void *ptr2 = bf_alloc(64);  /* ptr: 160+16 */
    void *ptr3 = bf_alloc(64);  /* ptr: 240+16 */
    void *ptr4 = bf_alloc(64);  /* ptr: 320+16 */
    void *ptr5 = bf_alloc(64);  /* ptr: 400+16 */
    void *ptr6 = bf_alloc(64);  /* ptr: 480+16 */
    void *ptr7 = bf_alloc(64);  /* ptr: 560+16 */
    void *ptr8 = bf_alloc(64);  /* ptr: 640+16 */
    void *ptr9 = bf_alloc(64);  /* ptr: 720+16 */

    bf_free(ptr1);
    bf_free(ptr3);
    bf_free(ptr4);
    bf_free(ptr5);
    bf_free(ptr7);

    Node *cur = free_list.dummy_head.next;
    PRINT_LIST(cur);

    bf_alloc(64);
    bf_alloc(64);
    bf_alloc(64);
    bf_alloc(64);

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
