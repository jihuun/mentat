class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        int ret_pos = 0;
        
        std::sort(intervals.begin(), intervals.end());
        ret.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            if (ret[ret_pos][1] >= intervals[i][0]) {
                ret[ret_pos][1] = std::max(ret[ret_pos][1], intervals[i][1]);
            } else {
                ret.push_back(intervals[i]);
                ret_pos++;
            }
        }
        return ret;
            
    }
};