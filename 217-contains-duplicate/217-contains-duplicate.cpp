class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++) {
            if (table[nums[i]] > 0)
                return true;
            table[nums[i]]++;
        }
        return false;
    }
};