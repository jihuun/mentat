// https://velog.io/@soopsaram/Leetcode-101.-Symmetric-Tree

class Solution {
private:
    TreeNode *invert_tree(TreeNode *root) {
        if (root == NULL)
            return NULL;
        TreeNode *tmp = root->left;
        root->left = invert_tree(root->right);
        root->right = invert_tree(tmp);
        return root;
    }
    void dfs(TreeNode *root) {
        if (root == NULL)
            return;
        std::cout << root->val << " ";
        dfs(root->left);
        dfs(root->right);
    }
    bool dfs(TreeNode *n1, TreeNode *n2) {
        if (n1 == NULL && n2 == NULL)
            return true;
        if ((!n1 && n2) || (n1 && !n2))
            return false;
        if (n1->val != n2->val)
            return false;
        if (!dfs(n1->left, n2->left))
            return false;
        if (!dfs(n1->right, n2->right))
            return false;
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        invert_tree(root->left);
        return dfs(root->left, root->right);
    }
};
