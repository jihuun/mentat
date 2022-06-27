// https://velog.io/@soopsaram/Leetcode-665.-Non-decreasing-Array

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int nsize = nums.size();
        int chances = 2;
        
        for (int i = 1; i < nsize; i++) {
            if (nums[i - 1] > nums[i]) {
                chances--;
                if (chances <= 0)
                    return false;
                // 4 5 1 2
                // 4 5 1
                // 4 5 1 8
                if (i > 1 && nums[i - 2] > nums[i])
                    nums[i] = nums[i-1];
            }
        }
        return true;
    }
};
