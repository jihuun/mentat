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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        /*
         1 2 
           ^ |
         1 2 3 4
             ^   |
         1 2 3 4 5 6      end of even case:
               ^     |     -> fast is NULL
         
         1
         ^|
         1 2 3
           ^ |
         1 2 3 4 5        end of odd case
             ^   |        -> fast->next is NULL
        */
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // both of even and odd case
    }
    
    ListNode* middleNode2(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        /*
         1 2
         ^|
         1 2 3 4
           ^ |
         1 2 3 4 5 6      for even
             ^   |     -> fast->next->next is NULL
         
         1
         ^|
         1 2 3
           ^ |
         
         1 2 3 4 5        for odd
             ^   |     -> fast->next is NULL
        */
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (!fast->next) // for odd case
            return slow;
        return slow->next; // for even case
    }
};