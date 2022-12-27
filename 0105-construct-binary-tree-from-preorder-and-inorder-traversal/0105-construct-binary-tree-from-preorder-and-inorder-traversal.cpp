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
/*
3 9 20 15 7     preorder
^ l rrrrrrr

9 3 15 20 7     inorder
l | rrrrrrr
  |
  pivot
  
*/
class Solution {
    unordered_map<int, int> in_idx;
public:
    TreeNode *build_tree(vector<int> pre, vector<int> in, int left, int right, int root_idx) {
        // left, right -> index of in
        // root_idx -> index of pre
        if (left > right) /* base case */
            return NULL;
        /*
        int pivot = left;
        for (pivot = left; pivot <= right; pivot++) // O(n)
            if (in[pivot] == pre[root_idx])
                break;
        */
        int pivot = in_idx[pre[root_idx]]; // O(1)
            
        TreeNode *node = new TreeNode;
        node->val = pre[root_idx];
        node->left = build_tree(pre, in, left, pivot - 1, root_idx + 1);
        node->right = build_tree(pre, in, pivot + 1, right, root_idx + (pivot - left + 1));
        return node;
    }
    
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            in_idx[inorder[i]] = i;
        
        return build_tree(preorder, inorder, 0, inorder.size() - 1, 0);
    }
};