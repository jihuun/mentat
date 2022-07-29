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
    void level_order_travel(TreeNode *root, int level, vector<vector<int>> &ret) {
        if (root == NULL)
            return;
        if (ret.size() <= level) { /* there is no ret[level], need to addsign a new vector */
            vector<int> lv;
            lv.push_back(root->val);
            ret.push_back(lv);
        } else {
            ret[level].push_back(root->val);
        }
        level_order_travel(root->left, level + 1, ret);
        level_order_travel(root->right, level + 1, ret);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        level_order_travel(root, 0, ret);
        return ret;
    }
};