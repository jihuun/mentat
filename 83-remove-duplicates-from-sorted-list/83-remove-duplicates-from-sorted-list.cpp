/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *newhead = head;
        
        for (; cur != NULL; cur = cur->next) {
            if (prev && prev->val == cur->val)
                prev->next = cur->next;
            else
                prev = cur;
        }
        return newhead;
    }
};