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
    int minDepth(TreeNode* root) {
        int left = 0;
        int right = 0;
        
        if (!root)
            return 0;
        // no compare with minDepth() is 0
        left = minDepth(root->left);
        right = minDepth(root->right);        
        if (left == 0)
            return right + 1;
        if (right == 0)
            return left + 1;
        return std::min(left, right) + 1;
    }
};

/*
  2
n   3
   n  4
     n 5
   
   
*/