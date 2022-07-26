/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
   head  1 -> 2 -> 3 -> null
 null <- 1 <- 2 <- 3  head
   */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *node = head, *prev = NULL, *tmp = head;
    for (; node != NULL; prev = node, node = tmp) {
        tmp = node->next;
        node->next = prev;
    }
    return prev;
}