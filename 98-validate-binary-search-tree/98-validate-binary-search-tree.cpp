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
 
[2,1,3]
[5,1,4,null,null,3,6]
[4,1,5,null,null,null,3]
[2,2,2]
[3,2,2]
[5,4,6,null,null,3,7]
 */
class Solution {
    TreeNode* prev = NULL;
    bool inorder(TreeNode* root) {
        if (root == NULL)
            return true;
        if (!inorder(root->left))
            return false;
        /* inorder traval */
        if (prev && prev->val >= root->val)
            return false;
        prev = root;
        return inorder(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};