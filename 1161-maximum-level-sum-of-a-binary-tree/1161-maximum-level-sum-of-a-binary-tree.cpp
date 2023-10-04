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
    int freq[1001] = {0};
    int maxval = INT_MIN;
    int maxhgt = 0;
    
    void traval(TreeNode *root, int lv) {
        if (!root)
            return;
        freq[lv] += root->val;
        if (lv > maxhgt)
            maxhgt = lv;
        traval(root->left, lv + 1);
        traval(root->right, lv + 1);
    }
    int maxLevelSum(TreeNode* root) {
        int maxlv = 0;
        traval(root, 1);
        for (int i = 1; i <= maxhgt; i++) {
           if (freq[i] > maxval) {
               maxval = freq[i];
               maxlv = i; 
           }
        }
        return maxlv;
    }
};