class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    unordered_map<int, int> count;
    
    void back_tracking(vector<int> nums, int size) {
        if (size < 0)
            return;
        if (size == 0) {
            ret.push_back(tmp);
            return;
        }
        for (auto it: count) { // iterate hashtable ...!
            if (it.second == 0)
                continue;
            
            count[it.first]--;
            tmp.push_back(it.first);
            back_tracking(nums, size - 1);
            tmp.pop_back();
            count[it.first]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (auto it: nums)
            count[it]++;
        back_tracking(nums, nums.size());
        return ret;
    }
};