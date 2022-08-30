/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *n1 = NULL, *n2 = NULL, *prev = NULL;

void inorder(struct TreeNode* root) 
{
    if (root == NULL)
        return;
    inorder(root->left);
    if (prev && root->val < prev->val) {
        n2 = root; // search the final target 2
        if (n1 == NULL) n1 = prev; // fix the target 1
        else return;
    } 
    prev = root;
    inorder(root->right);
    return; 
}

void swap(struct TreeNode* a, struct TreeNode* b)
{
    if (!a || !b)
        fprintf(stderr, "failed to find targets\n");
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
}

void recoverTree(struct TreeNode* root){
    n1 = NULL, n2 = NULL, prev = NULL;
    inorder(root);
    swap(n1, n2);
    return;
}