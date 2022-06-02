
/*
 *  https://velog.io/@soopsaram/Leetcode-Tree-%EB%AC%B8%EC%A0%9C
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define max(a,b) ((a) > (b)? (a): (b))
#define min(a,b) ((a) < (b)? (a): (b))


int height(struct TreeNode *node)
{
    if (node == NULL)
        return 0;
    int left = height(node->left);
    int right = height(node->right);
    if (left == -1 || right == -1)
        return -1;
    if (left - right > 1 || left - right < -1)
        return -1;
    else
        return max(left, right) + 1;
}

bool isBalanced(struct TreeNode* root){
    if (height(root) == -1)
        return false;
    return true;
}

/* examplse
[1,2,3,null,3,3,1,1]
[1,2,2,3,3,3,null,4,4]
[3,9,20,null,null,15,7]
[1,2,2,3,3,null,null,4,4]
[3,null,30,null,7,null,9]
[3,null,30,8]
[1,2,3]
[1,2]
[1,null,3]
[1,2,3,4,5,6,null,8]
[1]
[]
[1,2,2,3,null,null,3,4,null,null,4]
[1,2,2,3,null,null,3,4,null,3,4]
[1,2,null,3,3]
[1,2,null,3]
*/
