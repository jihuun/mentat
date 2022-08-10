class Solution {
    vector<vector<int>> ret;
    vector<int> tmp;
    void solve(vector<int>& candidates, int target, int curr)
    {
        if (target < 0) return;
        if (target == 0) {
            ret.push_back(tmp);
            return;
        }
        for (int i = curr; i < candidates.size(); i++) {
            tmp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return ret;
    }
};