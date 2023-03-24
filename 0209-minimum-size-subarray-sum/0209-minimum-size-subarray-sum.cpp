class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = nums[left];
        int len = 1;
        int minlen = INT_MAX;
        
        while (left <= right && right < nums.size()) {
            if (sum >= target) {
                minlen = std::min(minlen, len);
                sum -= nums[left++];
                len--;
            } else {
                if (right + 1 == nums.size())
                    break;
                sum += nums[++right];
                len++;
            }
        }
        if (minlen == INT_MAX)
            return 0;
        return minlen;
    }
};