/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, int> orig_idx;
        unordered_map<int, Node *> idx_new;
        
        Node *newhead = new Node(0);
        Node *node = head;
        Node *copy = newhead;
        int idx = 0;
        for (; node; node = node->next, copy = copy->next) {
            copy->next = new Node(node->val);   
            orig_idx[node] = idx;
            idx_new[idx] = copy->next;
            idx++;
        }
        node = head;
        copy = newhead->next;
        for (; node; node = node->next, copy = copy->next) {
            if (node->random)
                copy->random = idx_new[orig_idx[node->random]];
            else
                copy->random = NULL;
        }
            
        return newhead->next;
    }
};