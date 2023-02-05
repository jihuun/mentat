class Solution {
public:
    int maxsub(vector<int>& nums, int left, int right) {
        if (left > right)
            return 0;
        if (left == right)
            return nums[left];
        int mid = left + (right - left) / 2;
        int l_sum = nums[mid];
        int sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            l_sum = std::max(l_sum, sum);
        }
        int r_sum = nums[mid+1];
        sum = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            r_sum = std::max(r_sum, sum);
        }
        int left_half = maxsub(nums, left, mid);
        int right_half = maxsub(nums, mid + 1, right);
        return std::max(l_sum + r_sum, std::max(left_half, right_half));
    }
    int maxSubArray(vector<int>& nums) {
        return maxsub(nums, 0, nums.size() - 1);
    }
};