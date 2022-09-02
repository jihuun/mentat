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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<pair<TreeNode *, int>> q;
        int cur_h = 0;
        
        if (root)
            q.push(make_pair(root, cur_h + 1));
        while (!q.empty()) {
            pair<TreeNode *, int> check = q.front();
            q.pop();
            TreeNode *node = check.first;
            if (check.second > cur_h) {
                ret.push_back(node->val);
                cur_h = check.second;
            }
            if (node->right)
                q.push(make_pair(node->right, cur_h + 1));
            if (node->left)
                q.push(make_pair(node->left, cur_h + 1));
        }
        return ret;
    }
};