/*
 * First Fit Allocation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_SIZE (1 << 10)  /* 1KB */
#define MAGIC    123456
#define ERR(msg) do { \
        fprintf(stderr, "%s\n", msg); \
        exit(1); \
    } while (0)

typedef struct Header {
    size_t size;    /* Size of allocated memory chunk (excluding the header) */
    int magic;      /* Magic number used to verify that the memory chunk has not been damaged */
} Header;

typedef struct Node {
    size_t size;        /* Size of free memory chunk */
    void *ptr;          /* Point to the start address */
    struct Node *next;  /* Point to the next memory chunk */
} Node;

typedef struct FreeList {
    size_t free_size;
    Node dummy_head;
} FreeList;

static char mem[MEM_SIZE];
static FreeList free_list;

static void init(void)
{
    memset(mem, 0, MEM_SIZE);

    Node *node = malloc(sizeof(Node));
    if (!node) ERR("new node in init");
    node->next = NULL;
    node->ptr = mem;
    node->size = MEM_SIZE;

    free_list.dummy_head = (Node) {
        .size = 0,
        .ptr  = NULL,
        .next = node
    };
    free_list.free_size = MEM_SIZE;
}

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

static void merge(Node *prev, Node *cur, Node *next)
{
    if ((char *) cur->ptr - (char *) prev->ptr == prev->size) {
        prev->size += cur->size;
        prev->next = cur->next;
        free_list.free_size += cur->size;
        free(cur);
        cur = prev;
    }
    if ((char *) next->ptr - (char *) cur->ptr == cur->size) {
        cur->size += next->size;
        cur->next = next->next;
        free_list.free_size += next->size;
        free(next);
    }
}

static void ff_free(void *ptr)
{
    Header *header = (Header *) ((char *) ptr - sizeof(Header));
    Node *node = malloc(sizeof(Node));
    if (!node) ERR("new node in ff_free");
    node->size = header->size + sizeof(Header);
    node->ptr = header;
    node->next = NULL;

    /* add it to free list */
    Node *cur = free_list.dummy_head.next, 
         *next = NULL, *prev = &free_list.dummy_head;
    while (cur) {
        next = cur->next;
        if (node->ptr < cur->ptr) {
            prev->next = node;
            node->next = cur;
            /* merge */
            merge(prev, node, cur);
            break;
        }
        prev = cur;
        cur = next;
    }

    /* do not find a position, append the node */
    if (!cur) prev->next = node;

    free_list.free_size += node->size;
}

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
    while (cur) {
        printf("%ld->", (char *) cur->ptr - (char *) mem);
        cur = cur->next;
    }
    printf("NULL\n");

    cur = free_list.dummy_head.next;
    Node *next = NULL;
    while (cur) {
        next = cur->next;
        free(cur);
        cur = next;
    }

    return 0;
}
