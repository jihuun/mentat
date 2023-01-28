class Solution {
public:
    int maxarr(vector<int> &nums, int left, int right) {
        if (left > right)
            return 0;
        if (left == right)
            return nums[left];
        
        /* find max sum expanding from mid to both side*/
        int mid = left + (right - left) / 2;
        int max_l = nums[mid];
        int l_sum = 0;
        for (int i = mid; i >= left; i--) { // [left, mid] must check the range
            l_sum += nums[i];
            max_l = std::max(max_l, l_sum);
        }
        int max_r = nums[mid + 1];
        int r_sum = 0;
        for (int i = mid + 1; i <= right; i++) { // [mid+1, right]
            r_sum += nums[i];
            max_r = std::max(max_r, r_sum);
        }
        
        /* compare three values */
        int lefthalf = maxarr(nums, left, mid);
        int righthalf = maxarr(nums, mid + 1, right);
        return std::max(max_l + max_r, std::max(lefthalf, righthalf));
    }
    
    int maxSubArray(vector<int>& nums) {
        return maxarr(nums, 0, nums.size() - 1);
    }
};