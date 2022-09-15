class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int isize = intervals.size();
        vector<vector<int>> ret;
        int remains;
        vector<int> tmp(2,0);
        tmp[0] = newInterval[0];
        tmp[1] = newInterval[1];
        
        for (int i = 0; i < isize; i++) {    
            if (intervals[i][1] < newInterval[0]) {
                ret.push_back(intervals[i]);
            } else if (newInterval[1] < intervals[i][0]) {
                remains = i;
                break;
            } else {
                tmp[0] = std::min(intervals[i][0], tmp[0]);
                tmp[1] = std::max(intervals[i][1], tmp[1]);
            }
        }
        ret.push_back(tmp);
        for (int i = remains; i < isize; i++)
            ret.push_back(intervals[i]);
        return ret;
    }
};