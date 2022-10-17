/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        queue<pair<Node *, int>> q;
        Node *prev = NULL;
        int prev_level = 0;
        
        root->next = NULL;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<Node *, int> check = q.front();
            q.pop();
            Node *node = check.first;
            int level = check.second;
            if (prev_level != level) {
                prev = NULL;
                prev_level = level;
            }
            node->next = prev;
            prev = node;
            
            if (node->right)
                q.push(make_pair(node->right, level + 1));
            if (node->left)
                q.push(make_pair(node->left, level + 1));
            
        }
        return root;
    }
};