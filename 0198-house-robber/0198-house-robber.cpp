class Solution {
public:
    vector<int> vis;
    int act(vector<int>& nums, int h) { 
        if (h < 0)
            return 0;
        if (vis[h] != -1)
            return vis[h];
        vis[h] = max(act(nums, h-2) + nums[h], act(nums, h-1));
        return vis[h];
    }
    int rob(vector<int>& nums) {
        vis = vector<int>(101, -1);
        return act(nums, nums.size() - 1);
    }
};