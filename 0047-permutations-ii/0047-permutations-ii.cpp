class Solution {
    vector<vector<int>> ret;
    vector<int> tmp;
public:
    void back_tracking(unordered_map<int, int> &freq, int size) {
        if (size < 0)
            return;
        if (size == 0) {
            ret.push_back(tmp);
            return;
        }
        for (auto it: freq) {
            if (freq[it.first] == 0)
                continue;
            
            freq[it.first]--;
            tmp.push_back(it.first);
            back_tracking(freq, size - 1);
            tmp.pop_back();
            freq[it.first]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> freq; // nums[i] / frequency
        for (auto it: nums)
            freq[it]++;
        back_tracking(freq, nums.size());
        return ret;
    }
};