/*
 * https://velog.io/@soopsaram/Leetcode-Tree-%EB%AC%B8%EC%A0%9C
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int retcnt = 0;
void pre_travel(struct TreeNode* node, int *arr)
{
    if (node == NULL)
        return;
    arr[retcnt++] = node->val;
    pre_travel(node->left, arr);
    pre_travel(node->right, arr);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *ret = (int *)calloc(101, sizeof(int));
    retcnt = 0;
    pre_travel(root, ret);
    *returnSize = retcnt;
    return ret;
}
