class Solution {
    vector<vector<int>> ret;
    vector<int> tmp;
    unordered_map<int, int> map;
public:
    void back_tracking(vector<int> nums, int cnt) {
        if (cnt == 0) {
            ret.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (map[nums[i]] == true)
                continue;
            map[nums[i]] = true;
            tmp.push_back(nums[i]);
            back_tracking(nums, cnt - 1);
            tmp.pop_back();
            map[nums[i]] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        back_tracking(nums, nums.size());
        return ret;
    }
};