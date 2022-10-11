class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        int ret_idx = 0;
        int cmp_idx = 1;
        
        std::sort(intervals.begin(), intervals.end());
        vector<int> tmp;
        tmp.push_back(intervals[0][0]);
        tmp.push_back(intervals[0][1]);
        ret.push_back(tmp);
        
        for (int i = cmp_idx; i < intervals.size(); i++) {
            if (ret[ret_idx][1] >= intervals[i][0]) { // must combine to ret[ret_idx]
                ret[ret_idx][1] = std::max(ret[ret_idx][1], intervals[i][1]);
            } else {
                vector<int> tmp;
                tmp.push_back(intervals[i][0]);
                tmp.push_back(intervals[i][1]);
                ret.push_back(tmp);
                ret_idx++;
            }
        }
        return ret;
    }
};