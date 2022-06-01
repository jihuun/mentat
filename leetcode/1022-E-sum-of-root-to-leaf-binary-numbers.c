/*
 * https://velog.io/@soopsaram/Leetcode-1022.-Sum-of-Root-To-Leaf-Binary-Numbers
 * https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int recur(struct TreeNode* root, int val)
{
    int sum = 0; 
    
    if (root->left == NULL && root->right == NULL)
        return val;
    if (root->left)
        sum += recur(root->left, root->left->val + val * 2);
    if (root->right)
        sum += recur(root->right, root->right->val + val * 2);
    return sum;
}

int sumRootToLeaf(struct TreeNode* root){
    return recur(root, root->val);
}
