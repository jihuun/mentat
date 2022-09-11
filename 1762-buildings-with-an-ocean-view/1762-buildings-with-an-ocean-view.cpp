class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ret;
        deque<pair<int, int>> stk;
        
        stk.push_back(make_pair(0, heights[0]));
        for (int cur = 1; cur < heights.size(); cur++) {
            // decreasing monotonic stack
            while (!stk.empty() && heights[cur] >= stk.back().second) {
                stk.pop_back();
            }
            stk.push_back(make_pair(cur, heights[cur]));
        }
        while (!stk.empty()) {
            ret.push_back(stk.front().first);
            stk.pop_front();
        }        
        return ret;
    }
};