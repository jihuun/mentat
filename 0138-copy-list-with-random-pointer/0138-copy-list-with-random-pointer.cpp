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
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> map;
        
        Node *new_head = new Node(0);
        Node *gen = new_head;
        Node *n = head;
        int idx = 0;
        for (; n; n = n->next) {
            gen->next = new Node(n->val);
            gen = gen->next;
            map[n] = gen;
            idx++;
        }
        n = head;
        gen = new_head->next;
        for (; n; n = n->next, gen = gen->next) {
            if (n->random)
                gen->random = map[n->random];
            else
                gen->random = NULL;
        }
        return new_head->next;
    }
};