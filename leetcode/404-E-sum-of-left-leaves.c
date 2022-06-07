
//  https://velog.io/@soopsaram/Leetcode-Tree-%EB%AC%B8%EC%A0%9C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumOfLeftLeaves(struct TreeNode* root){
        if (root == NULL)
                return 0; 
        int sum = sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        if (root->left && !root->left->left && !root->left->right)
                sum += root->left->val;
        return sum;
}
