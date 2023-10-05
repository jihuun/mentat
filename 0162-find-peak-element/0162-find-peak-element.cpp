class Solution {
public:
    int cond(vector<int>& nums, int n) {
        int nsize = nums.size();
        if (n+1 < nsize && nums[n] > nums[n+1])
            return true;
        if (n > 0 && n == nsize - 1 && nums[n-1] < nums[n])
            return true;
        if (n == 0 && n + 1 < nsize && nums[n] > nums[n+1])
            return true;
        return false;
    }
            
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        
        while (l < r) {
            mid = l + (r - l) / 2;
            if (cond(nums, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};