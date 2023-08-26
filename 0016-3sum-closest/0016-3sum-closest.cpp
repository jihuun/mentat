class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = INT_MAX;
        int ret = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            int sum = 0;
            
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < closest) {
                    closest = abs(sum - target);
                    ret = sum;
                }
                if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
            
        }
        return ret;
    }
};