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
 
[2,1,3]
[5,1,4,null,null,3,6]
[4,1,5,null,null,null,3]
[2,2,2]
[3,2,2]
[5,4,6,null,null,3,7]
 */
class Solution {
    bool dfs(TreeNode* root, vector<int> &arr) {
        if (root == NULL)
            return true;
        if (!dfs(root->left, arr))
            return false;
        //cout << root->val << " ";
        if (!arr.empty() && arr.back() >= root->val)
            return false;
        arr.push_back(root->val);
        if (!dfs(root->right, arr))
            return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> arr;
        return dfs(root, arr);
    }
};