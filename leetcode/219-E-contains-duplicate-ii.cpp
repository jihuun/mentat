// https://velog.io/@soopsaram/Leetcode-219.-Contains-Duplicate-II

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> table;
        int nsize = nums.size();
        
        for (int i = 0; i <= k && i < nsize; i++) {
            if (i < nsize && table[nums[i]] > 0)
                return true;
            table[nums[i]]++;
        }
        for (int i = 0; i+k+1 < nsize; i++) {
            table[nums[i]]--;
            if (table[nums[i+k+1]] > 0)
                return true;
            table[nums[i+k+1]]++;
        }
        return false;
    }
};
