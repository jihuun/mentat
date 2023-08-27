class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int smaller = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            int sum = 0;
            
            // -2 0 0 2 2 
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum >= target) {
                    r--;
                } else {
                    smaller += r - l;
                    l++;
                    r = nums.size() - 1;
                }
            }
        }
        return smaller;
    }
};