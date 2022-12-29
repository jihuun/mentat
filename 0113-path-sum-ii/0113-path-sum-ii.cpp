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
    // # mistaken number
    void dfs(TreeNode* root, int sum, vector<int> &tmp, vector<vector<int>> &ret) {
        if (!root) // #1  (sum < 0) -> consider if values are negative?
            return;
        if (sum - root->val == 0 && !root->left && !root->right) {  // #2 only if root has no child,  [1,2] 1 -> answer must be []
            tmp.push_back(root->val);
            ret.push_back(tmp);
            tmp.pop_back(); // #3  must pop at this position
            return;
        }
        tmp.push_back(root->val);
        dfs(root->left, sum - root->val, tmp, ret);
        dfs(root->right, sum - root->val, tmp, ret);
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        vector<int> tmp;
        dfs(root, targetSum, tmp, ret);
        return ret;
    }
};