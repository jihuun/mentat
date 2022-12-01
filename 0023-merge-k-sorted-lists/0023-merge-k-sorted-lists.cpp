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
    struct compare {
        bool operator()(int a, int b) {
            return a > b;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, compare> pq;
        ListNode *newhead = new ListNode;
        ListNode *node = newhead;
        for (int i = 0; i < lists.size(); i++) {
            while (lists[i]) {
                pq.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        while (!pq.empty()) {
            node->next = new ListNode(pq.top());
            node = node->next;
            pq.pop();
        }
        return newhead->next;
    }
};