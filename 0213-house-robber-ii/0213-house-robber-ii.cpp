class Solution {
public:
    vector<int> mem;
    int max_rob(vector<int> nums, int begin, int idx) {
        if (idx < begin)
            return 0;
        if (mem[idx] != -1)
            return mem[idx];
        mem[idx] = std::max(max_rob(nums, begin, idx - 1), max_rob(nums, begin, idx - 2) + nums[idx]);
        return mem[idx];
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        // 1 (2 3 4 5)
        mem = vector<int>(nums.size(), -1);
        int val1 = max_rob(nums, 1, nums.size() - 1);
        
        // (1 2 3 4) 5
        mem = vector<int>(nums.size(), -1);
        int val2 = max_rob(nums, 0, nums.size() - 2);
        
        return std::max(val1, val2);
    }
};