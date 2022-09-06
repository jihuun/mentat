/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* pruneTree(struct TreeNode* root){
    if (root == NULL)
        return NULL;
    
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root && root->val == 0 && !root->left && !root->right)
        return NULL;
    return root;
}