// https://velog.io/@soopsaram/Leetcode-108.-Convert-Sorted-Array-to-Binary-Search-Tree

class Solution {
private:
    vector<int> gnums;
    TreeNode *gen_tree(int left, int right) {
        if (left > right)
            return NULL;
        int mid = (left + right ) / 2;
        TreeNode *root = new TreeNode;
        root->val = gnums[mid];
        root->left = gen_tree(left, mid - 1);
        root->right = gen_tree(mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        gnums = nums;
        return gen_tree(0, nums.size() - 1);
    }
};
