class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        int isize = intervals.size();
        int retidx = 0;
        
        sort(intervals.begin(), intervals.end());
        ret.push_back(intervals[0]);
        for (int i = 1; i < isize; i++) {
            // check ret[retidx] and interval[i]
            if (ret[retidx][1] >= intervals[i][0]) {
                ret[retidx][1] = max(ret[retidx][1], intervals[i][1]);
            } else {
                ret.push_back(intervals[i]);
                retidx++;
            }
        }
        return ret;
    }
};