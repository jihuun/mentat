class Solution {
    bool condition(vector<int> &nums, int idx, int tgt) {
        if (nums[idx] >= tgt)
            return true;
        else
            return false;
    }
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid = 0;
        
        while (left < right) {
            mid = left + (right - left) / 2;
            if (condition(nums, mid, target)) {
                right = mid;
            } else {
                left = mid + 1;    
            }
        }
        if (nums[left] == target)
            return left;
        else 
            return -1;
    }
};