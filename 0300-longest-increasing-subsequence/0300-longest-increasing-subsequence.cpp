class Solution {
    int binary_search(vector<int> &nums, int tgt) {
        int left = 0;
        int right = nums.size() - 1;
        //  1 2 3 5  (4)
        // 1 3 5 7  (2)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == tgt) {
                return mid;
            } else if (nums[mid] < tgt) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        for (int i = 0; i < nums.size(); i++) {
            if (sub[sub.size()-1] < nums[i]) {
                sub.push_back(nums[i]);
            } else {
                int j = binary_search(sub, nums[i]);
                sub[j] = nums[i];
            }
        }
        return sub.size();
    }
};