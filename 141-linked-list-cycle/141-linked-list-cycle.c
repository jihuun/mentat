/**
1. Constraints
 - single node can be cycle?
 - how many node? 0 ~ 10000
 - the valses can be duplicated? 
 - if pos == -1, what is tail->next? NULL?
2. Ideas
3. TestCases
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL)
        return false;
    struct ListNode *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        if (slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}