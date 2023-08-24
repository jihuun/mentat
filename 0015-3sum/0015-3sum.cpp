class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;   
        
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = nums.size() - 1;
            int tgt = - nums[i];
            int sum = 0;
            
            while (l < r) {
                sum = nums[l] + nums[r];
                if (sum > tgt) {
                    r--;
                } else if (sum < tgt) {
                    l++;
                } else {
                    // -2 0 0 2 2  
                    ret.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l < r && nums[l - 1] == nums[l])
                        l++;
                }
            }
        }
        return ret;
    }
};