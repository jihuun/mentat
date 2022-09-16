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
        ListNode *node = head, *prev = NULL, *tmp = head;
        for (; node != NULL; prev = node, node = tmp) {
            tmp = node->next;
            node->next = prev;
        }
        return prev;
    }
};