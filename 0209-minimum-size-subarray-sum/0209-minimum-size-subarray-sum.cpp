class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = nums[left];
        int minlen = INT_MAX;
        int len = 1;
        
        while (right < nums.size() && left <= right) {
            if (sum < target) {
                if (right == nums.size() -1)
                    break;
                sum += nums[++right];
                len++;
            } else {
                minlen = std::min(minlen, len);
                sum -= nums[left++];
                len--;
            }
        }
        return (minlen == INT_MAX) ? 0 : minlen; 
    }
};