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
    vector<int> ret;
    void inorder(TreeNode *root) {
        if (root == NULL)
            return;
        inorderTraversal(root->left);
        ret.push_back(root->val);
        inorderTraversal(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ret;
    }
};