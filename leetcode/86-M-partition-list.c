// https://velog.io/@soopsaram/Leetcode-86.-Partition-List


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *partition(struct ListNode *head, int x){
    struct ListNode *l_head = NULL, *l_tail = head;
    struct ListNode *r_head = NULL, *r_tail = head;
    struct ListNode *node = head;

    for (;node != NULL; node = node->next) {
        if (node->val < x) {
            if (l_head == NULL) {
                l_head = node;
                l_tail = l_head;
            } else {
                l_tail->next = node;
                l_tail = node;
            }
        } else {
            if (r_head == NULL) {
                r_head = node;
                r_tail = node;
            } else {
                r_tail->next = node;
                r_tail = node;
            }
        }
    }
    /* x is less than all of nodes */
    if (l_head == NULL && r_head) {
        if (r_tail)
            r_tail->next = NULL;
        return r_head;
    }
    /* x is greater than all of nodes */
    if (r_head == NULL && l_head) {
        return l_head;
    }
    /* x is between the nodes */
    if (r_tail)
        r_tail->next = NULL;
    if (l_tail)
        l_tail->next = r_head;
    return l_head;
}
