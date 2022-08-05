class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        vector<int> ret;
        int num1 = 0;
        int nsize = nums.size();
        
        for (int i = 0; i < nsize; i++) {
            table[nums[i]] = i;
        }
        for (int i = 0; i < nsize; i++) {
            int num2 = target - nums[i];
            if (table[num2] && i != table[num2]) {
                ret.push_back(i);
                ret.push_back(table[num2]);
                break;
            }
        }
        return ret;
    }
};