/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode *, int> table;
        while (head) {
            if (table[head])
                return head;
            table[head]++;
            head = head->next;
        }
        return NULL;
    }
};