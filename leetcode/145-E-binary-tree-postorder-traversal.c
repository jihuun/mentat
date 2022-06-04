/*
 * https://velog.io/@soopsaram/Leetcode-Tree-%EB%AC%B8%EC%A0%9C
 */

int retcnt;
void post_travel(struct TreeNode* node, int *arr) 
{
    if (node == NULL)
        return;
    post_travel(node->left, arr);
    post_travel(node->right, arr);
    arr[retcnt++] = node->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *ret = (int *)calloc(101, sizeof(int));
    retcnt = 0;
    post_travel(root, ret);
    *returnSize = retcnt;
    return ret;
}
