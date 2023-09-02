/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool is_same(TreeNode* r, TreeNode* s) {
        if (!r && !s)
            return true;
        if (r && !s)
            return false;
        if (!r && s)
            return false;
        
        if (r->val == s->val) {
            if (is_same(r->left, s->left) && is_same(r->right, s->right))
                return true;
        }
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        if (is_same(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) ||  isSubtree(root->right, subRoot);
    }
};