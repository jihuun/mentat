class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cur = 0;
        int next = 1;
        int min_rm = 0;
        if (intervals.size() == 1)
            return min_rm;
        sort(intervals.begin(), intervals.end());
        
        /*
        case 1 
          ---- ---
        case 2 : remove cur
          --------x
             ---
        case 3 : remove next
          -----
            ------x
        */
        while (next < intervals.size()) {
            // if case 1
            if (intervals[cur][1] <= intervals[next][0]) {
                cur = next; // <- cur will be next , not cur++
                next++;
            } else if (intervals[cur][1] >= intervals[next][1]) { // case 2
                min_rm++;
                cur = next; // <- cur will be next
                next++;
            } else { // case 3 
                min_rm++;
                next++;
            }
        }
        return min_rm;
    }
};