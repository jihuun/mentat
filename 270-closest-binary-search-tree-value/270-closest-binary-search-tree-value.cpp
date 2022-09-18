/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int left_most = -1;
        int right_lest = -1;
        TreeNode *node = root;
        while (node) {
            if (target < (double)node->val) {
                right_lest = node->val;
                node = node->left;
            } else if ((double)node->val < target) {
                left_most = node->val;
                node = node->right;
            } else { // node->val == target
                return node->val;
            }
        }            
        if (left_most == -1 && right_lest != -1)
            return right_lest;
        else if (left_most != -1 && right_lest == -1)
            return left_most;
        // left_most   target  right_lest
        double a = right_lest - (double)target;
        double b = (double)target - left_most;
        return a > b ? left_most : right_lest;
    }
};