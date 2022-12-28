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
    unordered_map<int, int> inidx;
public:
    /*
    [9,15,7,20,3] post
               ^
    [9,3,15,20,7] in
       ^
    */
    TreeNode* gen_tree(vector<int> in, vector<int> post, int left, int right, int post_idx) {
        if (left > right)
            return NULL;
        // search post[post_idx] in in[]
        int pivot = inidx[post[post_idx]];
        TreeNode *node = new TreeNode;
        node->val = post[post_idx];
        node->left = gen_tree(in, post, left, pivot - 1, post_idx - (right - pivot + 1));
        node->right = gen_tree(in, post, pivot + 1, right, post_idx - 1);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            inidx[inorder[i]] = i;
        return gen_tree(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    }
};