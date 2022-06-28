// https://velog.io/@soopsaram/Leetcode-230.-Kth-Smallest-Element-in-a-BST

class Solution {
public:
    void dfs(TreeNode *root, int k, vector<int> &nums) {
        if (root == NULL && k < 0)
            return;
        if (root->left) dfs(root->left, k - 1, nums);
        nums.push_back(root->val);
        if (root->right) dfs(root->right, k - 1, nums);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        dfs(root, k, nums);
        return nums[k - 1];
    }
};
