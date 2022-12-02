class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                table[nums[i]]++;
        }
        int maxval = 0;
        for (auto it: table) {
            maxval = max(maxval, it.first);
        }
        for (int i = 1; i <= maxval; i++) {
            if (table.find(i) == table.end())
                return i;
        }
        return maxval + 1;
    }
};