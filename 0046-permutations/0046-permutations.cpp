class Solution {
    vector<vector<int>> ret;
    vector<int> tmp;
    unordered_map<int, bool> tmp_map;
public:
    void back_tracking(vector<int> nums, int size) {
        if (size < 0)
            return;
        if (size == 0) {
            ret.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // if nums[i] is already exist in nums[i]; then continue
            if (tmp_map[nums[i]] == true) // O(1) Wow!
                continue;
            
            tmp.push_back(nums[i]);
            tmp_map[nums[i]] = true;
            back_tracking(nums, size - 1);
            tmp_map[nums[i]] = false;
            tmp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int nsize = nums.size();
        back_tracking(nums, nsize);
        return ret;
    }
};