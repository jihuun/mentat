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
    int count;
    unordered_map<long int, int> freq;
public:
    void dfs(TreeNode* root, int tgt, long int sum) {
        if (root == NULL)
            return;
        long int newsum = sum + root->val;
        if (freq.find(newsum - tgt) != freq.end()) {
            count += freq[newsum - tgt];
        }
        freq[newsum]++;
        dfs(root->left, tgt, newsum);
        dfs(root->right, tgt, newsum);
        freq[newsum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        freq[0] = 1;
        dfs(root, targetSum, 0);
        return count;
    }
};