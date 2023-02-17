/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node *succ = NULL;
    Node *getroot(Node *node) {
        if (!node->parent)
            return node;
        return getroot(node->parent);
    }
    void travel(Node *root, Node *node) {
        if (!root)
            return;
        if (root->val > node->val) {
            succ = root;
            travel(root->left, node);
        } else {
            travel(root->right, node);
        }
    }
    Node *inorderSuccessor(Node* node) {
        Node *root = getroot(node);
        cout << root->val;
        travel(root, node);
        return succ;
    }
};