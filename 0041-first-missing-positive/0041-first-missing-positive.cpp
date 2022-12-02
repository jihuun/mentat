class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> table;
        int maxval = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                table[nums[i]]++;
                maxval = max(maxval, nums[i]);
            }
        }
        for (int i = 1; i <= maxval; i++) {
            if (table.find(i) == table.end())
                return i;
        }
        return maxval + 1;
    }
};