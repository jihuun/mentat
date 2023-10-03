class Solution {
public:
    vector<int> vis;
    int act(vector<int>& nums, int n) {
        if (n < 0)
            return 0;
        if (vis[n] != -1)
            return vis[n];
        vis[n] = max(act(nums, n-1), act(nums, n -2) + nums[n]);
        return vis[n];
    }
    
    int rob(vector<int>& nums) {
        vis = vector<int>(101, -1);
        return act(nums, nums.size() - 1);
    }
};