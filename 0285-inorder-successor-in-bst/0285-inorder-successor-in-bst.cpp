/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *succ;
    TreeNode *p_node;
    
    void travel(TreeNode *root) {
        if (!root)
            return;
        if (root->val <= p_node->val) {
            travel(root->right);
        } else {
            succ = root;
            travel(root->left);
        }
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        p_node = p;
        travel(root);
        return succ;
        
    }
};