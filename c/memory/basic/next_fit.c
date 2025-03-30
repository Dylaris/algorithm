#include "common.h"

int main(void)
{
    init();
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
