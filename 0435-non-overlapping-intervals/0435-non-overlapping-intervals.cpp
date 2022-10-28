class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cur = 0;
        int nex = 1;
        int ret = 0;
        sort(intervals.begin(), intervals.end());
        
        while (nex != intervals.size()) {
            if (intervals[cur][1] <= intervals[nex][0]) {
                cur = nex;
            } else if (intervals[cur][1] >= intervals[nex][1]) {
                cur = nex;
                ret++;
            } else {
                ret++;
            }
            nex++;
        }
        return ret;
/*

---  ---

cur  ----
nex   --

cur ---
nex   ---

*/
    }
};