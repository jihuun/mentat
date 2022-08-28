/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *node = head;
    struct ListNode *prev = NULL;
    
    while (node != NULL) {
        if (node ->val != val) {
            prev = node;
            node = node->next;
            continue;
        }
        if (node == head) {
            head = node->next;
            prev = node;
            node = node->next;
        } else {
            prev->next = node->next;
            node = node->next;
        }
        
    }    
    return head;
}