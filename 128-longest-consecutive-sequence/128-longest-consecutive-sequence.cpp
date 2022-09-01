class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> table;
        int nmin = INT_MAX;
        int nmax = INT_MIN;
        int max_cnt = 0;
        
        for (auto it: nums) {
            table[it] = 1;
            nmin = min(nmin, it);
            nmax = max(nmax, it);
        }
        
        for (auto it: table) {
            int cur = it.first;
            /* if prev value is exist in table, there is no need to proceed 
               because in that case this cur value already has been checked. */
            if (table.find(cur - 1) != table.end())
                continue;
            
            /* check continuous from cur to */
            int cnt = 1;
            while (table.find(cur + 1) != table.end()) {
                cnt++;
                cur++;
            }
            max_cnt = max(max_cnt, cnt);
        }
        return max_cnt;
    }
};