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
    // 1 2 3 3 2 1
    //
    // 1 2 3 2 1
    //         
    ListNode *reverse(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *next = NULL;
        ListNode *node = head;
        
        for (; node; node = next) {
            next = node->next;
            node->next = prev;
            prev = node;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *rev = NULL;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        rev = reverse(slow->next);
        
        while (rev) {
            if (head->val != rev->val)
                return false;
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};