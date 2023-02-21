class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (sub[sub.size() - 1] < nums[i]) {
                sub.push_back(nums[i]);
            } else {
                int j = 0;
                while (sub[j] < nums[i]) j++;
                sub[j] = nums[i];
            }
            if (sub.size() >= 3)
                return true;
        }
        return false;
    }
};