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
    ListNode* reverseList(ListNode* head) {
        ListNode *node = head;
        ListNode *prev = NULL;
        ListNode *tmp = NULL;
        
        for (; node != NULL ; node = tmp) {
            tmp = node->next;
            node->next = prev;
            prev = node;
        }
        return prev;
    }
};