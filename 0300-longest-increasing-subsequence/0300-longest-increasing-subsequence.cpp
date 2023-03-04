class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> mem(nums.size(), 1);
        int maxlen = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    mem[i] = std::max(mem[i], mem[j] + 1);
            }
            maxlen = std::max(maxlen, mem[i]);
        }
        return maxlen;
    }
};