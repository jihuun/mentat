
// flatten-binary-tree-to-linked-list
// https://velog.io/@soopsaram/Leetcode-114.-Flatten-Binary-Tree-to-Linked-List


struct TreeNode *gen_list(struct TreeNode *root)
{
    if (root == NULL)
        return NULL;
    struct TreeNode *tmp = root->right;
    if (root->left) {
        root->right = gen_list(root->left);
        root->left = NULL;
    }
    if (root->right) {
        struct TreeNode *right_last = root->right;
        if (right_last == tmp) {
            right_last = gen_list(tmp);
        } else {
            for (; right_last->right != NULL; right_last = right_last->right)
                ;
            right_last->right = gen_list(tmp);
        }
    }
    return root;
}

void flatten(struct TreeNode* root){
    root = gen_list(root);
}
