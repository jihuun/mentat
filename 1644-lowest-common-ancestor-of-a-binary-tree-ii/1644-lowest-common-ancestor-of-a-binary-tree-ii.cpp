/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool p_cnt = false;
    bool q_cnt = false;
public:
    TreeNode *travel(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == NULL)
            return root;
        TreeNode *left = travel(root->left, p, q);
        TreeNode *right = travel(root->right, p, q);
        if (root == p || root == q) {
            if (root == p)
                p_cnt = true;
            else
                q_cnt = true;
            return root;
        }
        if (left && right)
            return root;
        else if (left && !right)
            return left;
        else if (!left && right)
            return right;
        return NULL;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *ret = travel(root, p, q);
        if (p_cnt && q_cnt)
            return ret;
        else
            return NULL;
    }
};