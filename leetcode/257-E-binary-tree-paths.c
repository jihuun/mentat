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
char **ret;
int retcnt;

void recur(struct TreeNode* root, char *str)
{
    if (root == NULL)
        return;
    char newstr[300] = {'\0'};
    strcpy(newstr, str);
    if (!root->left && !root->right) {
        sprintf(newstr, "%s%d", newstr, root->val);
        ret[retcnt] = malloc(sizeof(char) * (strlen(newstr) + 1));
        strcpy(ret[retcnt], newstr);
        retcnt++;
        return;
    }
    sprintf(newstr, "%s%d->", newstr, root->val);
    recur(root->left, newstr);
    recur(root->right, newstr);
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    ret = (char **)malloc(sizeof(char *) * 50); // maximum return size if log100
    char retstr[300] = {'\0'};
    retcnt = 0;
    recur(root, retstr);
    *returnSize = retcnt;
    return ret;
}
