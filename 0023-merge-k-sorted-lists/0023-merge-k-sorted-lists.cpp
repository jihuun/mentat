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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        ListNode *newhead = new ListNode();
        ListNode *save = newhead;
        
        for (int i = 0; i < lists.size(); i++) {
            while (lists[i]) {
                pq.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
            
        }
        while (!pq.empty()) {
            ListNode *node = new ListNode(pq.top());
            pq.pop();
            newhead->next = node;
            newhead = newhead->next;
        }
        return save->next;
    }
};