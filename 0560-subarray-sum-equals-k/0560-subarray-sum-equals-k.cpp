class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        int sum = 0;
        int cnt = 0;
        
        table[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (table.find(sum - k) != table.end()) {
                cnt += table[sum - k];
            }
            table[sum]++;
        }
        return cnt;
    }
};