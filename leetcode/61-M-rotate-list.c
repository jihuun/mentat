// https://velog.io/@soopsaram/Leetcode-61.-Rotate-List
struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode *node = head, *prev = NULL, *tail = NULL;
    int list_size = 0;
    int head_pos = 0;

    /* get list size */
    for (; node; prev = node, node = node->next)
        list_size++;
    if (list_size == 0 || list_size == 1)
        return head;

    /* initialize the position and nodes */
    head_pos = list_size - (k % list_size); //FIXME div by 0
    if (head_pos == list_size)
        return head; /* no need to rotate */
    tail = prev;
    node = head;
    prev = NULL;

    /* ratate by head_pos */
    for (int i = 0; i < head_pos; i++, prev = node, node = node->next)
        ;
    prev->next = NULL;
    tail->next = head;
    head = node;
    return head;
}
