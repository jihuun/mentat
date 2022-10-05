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
/*
    1  3  4
nh 
    2  2  5  6
*/

class Solution {
    ListNode *merge_list(ListNode *left, ListNode *right) {
        ListNode *newhead = new ListNode;
        ListNode *prev = newhead;
        
        while (left && right) {
            if (left->val < right->val) {
                prev->next = left;
                left = left->next;
            } else {
                prev->next = right;
                right = right->next;
            }
            prev = prev->next;
        }
        prev->next = (left) ? left : right; // node is not null
        return newhead->next;
    }
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *r_head = head;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        r_head = slow->next;
        slow->next = NULL;
        
        return merge_list(sortList(head), sortList(r_head));
    }
};