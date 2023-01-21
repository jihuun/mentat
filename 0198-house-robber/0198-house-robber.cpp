class Solution {
public:
    vector<int> mem;
    int max_rob(vector<int> nums, int cur) {
        if (cur < 0)
            return 0;
        if (mem[cur] != -1)
            return mem[cur];
        
        mem[cur] = std::max(max_rob(nums, cur - 1), max_rob(nums, cur - 2) + nums[cur]);
        return mem[cur];
    }
    int rob(vector<int>& nums) {
        mem = vector<int>(nums.size(), -1);
        return max_rob(nums, nums.size() - 1);
    }
};