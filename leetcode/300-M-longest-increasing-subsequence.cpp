

/*
https://velog.io/@soopsaram/Leetcode-300.-Longest-Increasing-Subsequence

f(n) = max(f(n-1) ~ f(0)) (if < nums[n]) + 1
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int nsize = nums.size();
        int ret = 1;
        vector<int> dp(nsize, 1);

        for (int i = 0; i < nsize; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                    ret = std::max(ret, dp[i]);
                }
            }
        }
        return ret;
    }
};
