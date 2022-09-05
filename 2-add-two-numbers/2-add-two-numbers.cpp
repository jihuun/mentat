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
    ListNode *add_node(int val) {
        ListNode *node = new ListNode;
        node->val = val;
        node->next = NULL;
        return node;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = add_node(0);
        ListNode *node = head;
        int carry = 0;
        
        while (l1 || l2) {
            int calc = carry;
            if (l1) {
                calc += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                calc += l2->val;
                l2 = l2->next;
            }
            if (calc > 9)
                carry = 1;
            else 
                carry = 0;
            calc = calc % 10;
            
            node->next = add_node(calc);
            node = node->next;
        }
        if (carry == 1)
            node->next = add_node(carry);
        
        return head->next;
    }
};