class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // if greater, size down by begin
        // if smaller, size up by last
        int st = 0;
        int end = 0;
        int sum = nums[st];
        int len = 1;
        int minlen = nums.size();
        
        
        while (st <= end && end < nums.size()) {
            
            if (sum >= target) {
                minlen = std::min(len, minlen);
                
                if (st == end) {
                    st++;
                    end++;
                    sum = nums[st];
                } else {
                    sum -= nums[st++];
                    len--;
                }
            } else {
                end++;
                if (end >= nums.size())
                    break;
                sum += nums[end];
                len++;
            }
        }
        if (st == 0 && end >= nums.size() && sum < target)
            return 0;
        return minlen;
    }
};