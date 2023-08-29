class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int l = i + 1, r = nums.size() - 1;
            int sum = 0;
            
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    r--;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }
        return ret;
    }
};