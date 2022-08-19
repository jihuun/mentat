class Solution {
    vector<vector<int>> ret;
    vector<int> tmp;
    int nsize;
    
    void back_tracking(vector<int> nums, int cur, int tgt) {
        if (tgt < 0)
            return;
        if (tgt == 0) {
            ret.push_back(tmp);
            return;
        }
        for (int i = cur; i < nsize; i++) {
            tmp.push_back(nums[i]);
            back_tracking(nums, i + 1, tgt - 1);
            tmp.pop_back();
        }
    }
        
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        nsize = nums.size();
        for (int i = 0; i <= nsize; i++) {
            back_tracking(nums, 0, i);
        }
        return ret;
    }
};