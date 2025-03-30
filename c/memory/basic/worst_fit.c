#include "common.h"

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
