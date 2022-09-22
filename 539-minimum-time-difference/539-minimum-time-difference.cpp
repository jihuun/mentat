#include <string>

class Solution {
    int calc_minute(string time) {
        string h_str = time.substr(0, 2);
        string m_str = time.substr(3, 5);
        int h = stoi(h_str);
        int m = stoi(m_str);
        return h * 60 + m;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        int tsize = timePoints.size();
        int min_minute = INT_MAX;
        int max_minute = 24 * 60;
        
        for (auto it: timePoints) {
            // calculate hh:mm -> minute integer
            minutes.push_back(calc_minute(it));
        }
        std::sort(minutes.begin(), minutes.end());
        int diff = 0;
        int min_diff = 0;
        for (int i = 1; i < tsize; i++) {
            diff = minutes[i] - minutes[i - 1];
            if (diff < 24*30)
                min_diff = diff;
            else
                min_diff = abs(max_minute - diff);
            min_minute = std::min(min_minute, min_diff);
        } 
        diff = minutes[tsize - 1] - minutes[0];
        min_diff = std::min(abs(max_minute - diff), abs(diff - max_minute));
        min_minute = std::min(min_minute, min_diff);
        return min_minute;
        
    }
};
// 23:55 23:59 00:01
// 1 1335 1339