class Solution {
    vector<vector<int>> ret;
    vector<int> tmp;
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
            bool cont = false;
            for (int j = 0; j < tmp.size(); j++) {
                if (tmp[j] == nums[i]) {
                    cont = true;
                    break;
                }
            }
            if (cont == true)
                continue;
            tmp.push_back(nums[i]);
            back_tracking(nums, size - 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int nsize = nums.size();
        back_tracking(nums, nsize);
        return ret;
    }
};