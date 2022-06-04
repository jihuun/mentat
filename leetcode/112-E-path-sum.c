/*
 * https://velog.io/@soopsaram/Leetcode-Tree-%EB%AC%B8%EC%A0%9C
 *
 */

bool hasPathSum(struct TreeNode* root, int targetSum){
    if (!root)
        return false;
    int newtarget = targetSum - root->val; 
    if (!root->left && !root->right) {
        if (newtarget == 0)
            return true;
        return false;
    }
    if (hasPathSum(root->left, newtarget))
        return true;
    if (hasPathSum(root->right , newtarget))
        return true;
    return false;
}
