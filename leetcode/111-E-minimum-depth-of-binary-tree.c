
/**
 * https://velog.io/@soopsaram/Leetcode-Tree-%EB%AC%B8%EC%A0%9C
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define min(a,b) (((a) < (b)) ? (a) : (b))

int minDepth(struct TreeNode* root){
    if (root == NULL)
        return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    if (!left && right)
        return right + 1;
    else if (left && !right)
        return left + 1;
    else
        return min(left, right) + 1;
}
