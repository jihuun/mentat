class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    
    void back_tracking(int n, int start, int k) {
        if (k < 0)
            return;
        if (k == 0) {
            ret.push_back(tmp);
            return;
        }
        for (int i = start; i <= n; i++) {
            tmp.push_back(i);
            back_tracking(n, i + 1, k - 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        back_tracking(n, 1, k);
        return ret;
    }
};