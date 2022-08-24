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

class myCompare {
public:
    bool operator() (const ListNode *p1, const ListNode *p2) {
        return p1->val < p2->val;
    }
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        priority_queue<ListNode*, vector<ListNode*>, myCompare> pq;
        ListNode *node = head;
        while (node != NULL) {
            pq.push(node);
            node = node->next;
        }
        ListNode *newhead = NULL;
        while (!pq.empty() ) {
            node = pq.top();
            node->next = newhead;
            newhead = node;
            pq.pop();
        }
        return newhead;
    }
};