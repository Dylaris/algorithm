#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_SIZE (1 << 10)  /* 1KB */
#define MAGIC    123456
#define ERR(msg) do { \
        fprintf(stderr, "%s\n", msg); \
        exit(1); \
    } while (0)
#define PRINT_LIST(node) do { \
        while (node) { \
            printf("%ld (%zu) -> ", (char *) node->ptr - (char *) mem, node->size); \
            node = node->next; \
        } \
        printf("NULL\n"); \
    } while (0)
#define free_func(name) void name##_free(void *ptr) { _free(ptr); }

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

extern char mem[MEM_SIZE];
extern FreeList free_list;

static inline void init(void)
{
    memset(mem, 0, MEM_SIZE);

    Node *node = (Node *) malloc(sizeof(Node));
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

static inline void merge(Node *prev, Node *cur, Node *next)
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

static inline void _free(void *ptr)
{
    Header *header = (Header *) ((char *) ptr - sizeof(Header));
    if (header->magic != MAGIC)
        ERR("Memory had been damaged!!!");

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

#endif /* COMMON_H */
