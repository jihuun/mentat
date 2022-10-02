class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table; //key: num, value: index
        vector<int> ret;
        
        for (int i = 0; i < nums.size(); i++) {
            int newnum = target - nums[i];
            if (table.find(newnum) != table.end()) {
                ret.push_back(i);
                ret.push_back(table[newnum]);
            } else {
                table[nums[i]] = i;
            }
        }
        return ret;
    }
};