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
    unordered_map<TreeNode *, int> with_mem;
    unordered_map<TreeNode *, int> without_mem;
    
    int dfs(TreeNode* root, bool visit) {
        if (!root)
            return 0;
        
        if (visit) {
            if (with_mem.find(root) != with_mem.end())
                return with_mem[root];
            int with_self = dfs(root->left, false) + dfs(root->right, false) + root->val;
            int without_self = dfs(root->left, true) + dfs(root->right, true);
            with_mem[root] = max(with_self, without_self);
            return with_mem[root];
        } else {
            if (without_mem.find(root) != without_mem.end())
                return without_mem[root];
            without_mem[root] = dfs(root->left, true) + dfs(root->right, true);
            return without_mem[root];
        }
    }
    int rob(TreeNode* root) {
        return dfs(root, true);
    }
};