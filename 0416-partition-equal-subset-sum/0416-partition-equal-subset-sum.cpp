/* DFS with memoization */
class Solution {
    vector<vector<int>> mem;
    bool dfs(vector<vector<int>> &mem, vector<int> nums, int idx, int sum) {
        if (sum == 0)
            return true;
        if (idx < 0 || sum < 0)
            return false;
        if (mem[idx][sum] != -1)
            return mem[idx][sum];
        
        mem[idx][sum] = dfs(mem, nums, idx - 1, sum - nums[idx]) || dfs(mem, nums, idx - 1, sum);
        return mem[idx][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        
        int tot_sum = 0;
        for (auto it: nums)
            tot_sum += it;
        if (tot_sum % 2 == 0)
            tot_sum /= 2;
        else
            return false;
        mem = vector<vector<int>>(nums.size() + 1, vector<int>(tot_sum + 1, -1));
        return dfs(mem, nums, nums.size() - 1, tot_sum);
    }
};


/*
Brute Force (DFS)

class Solution {
    
    bool dfs(vector<int> nums, int idx, int sum) {
        if (sum == 0)
            return true;
        if (idx < 0 || sum < 0)
            return false;
        return dfs(nums, idx - 1, sum - nums[idx]) || dfs(nums, idx - 1, sum);
    }
public:
    bool canPartition(vector<int>& nums) {
        int tot_sum = 0;
        for (auto it: nums)
            tot_sum += it;
        if (tot_sum % 2 == 0)
            tot_sum /= 2;
        else
            return false;
        return dfs(nums, nums.size() - 1, tot_sum);
    }
};
*/