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
    // 1 -> 2 -> 3 -> 4 -> 5 -> n
    // 1 -> 4 -> 3 -> 2 -> 5 -> n
    
    ListNode *reverse(ListNode *head, ListNode *before) {
        ListNode *prev = before;
        ListNode *next = NULL;
        ListNode *node = head;
        
        for (; node != before; node = next) {
            next = node->next;
            node->next = prev;
            prev = node;
        }
        return prev;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *head_left = NULL;
        ListNode *tail_right = NULL;
        ListNode *new_head = new ListNode();
        new_head->next = head;
        ListNode *node = new_head;
        ListNode *prev = new_head;
        int node_cnt = 0;

        while (node) {
            if (node_cnt == left)
                head_left = prev;
            if (node_cnt == right) {
                tail_right = node->next;
                break;
            }
            prev = node;
            node = node->next;
            node_cnt++;
        }
        head_left->next = reverse(head_left->next, tail_right);
        return new_head->next;
    }
};