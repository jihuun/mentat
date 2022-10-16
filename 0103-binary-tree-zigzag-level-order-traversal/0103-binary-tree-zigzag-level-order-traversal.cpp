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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;
        vector<int> cur_lv;
        queue<pair<TreeNode *, int>> q;
        int prev_level = 0;
        int level = 0;
        
        q.push(make_pair(root, 0)); //val, level
        while (!q.empty()) {
            pair<TreeNode *, int> check = q.front();
            q.pop();
            TreeNode *cur_node = check.first;
            level = check.second;
            if (prev_level != level) { // when next level begin, push prev level vector
                if (level % 2 == 0)
                    std::reverse(cur_lv.begin(), cur_lv.end());
                ret.push_back(cur_lv);
                cur_lv.clear();
            }
            cur_lv.push_back(cur_node->val);
            prev_level = level;
            
            if (cur_node->left)
                q.push(make_pair(cur_node->left, level + 1));
            if (cur_node->right)
                q.push(make_pair(cur_node->right, level + 1));
        }
        if (level % 2 != 0)
            std::reverse(cur_lv.begin(), cur_lv.end());
        ret.push_back(cur_lv);
        return ret;
    }
};