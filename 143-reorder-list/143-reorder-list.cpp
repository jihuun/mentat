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
    void reorderList(ListNode* head) {
        stack<ListNode *> st;
        ListNode *node = head;
        int node_cnt = 0;
        
        for (;node != NULL; node = node->next) {
            st.push(node);
            node_cnt++;
        }
        
        node = head;
        // 1 4 (2) 3 N
        for (int i = node_cnt/2; i > 0; i--) {
            ListNode *temp = st.top();
            st.pop();
            temp->next = node->next;
            node->next = temp;
            node = node->next->next;
        }
        node->next = NULL;
    }
};