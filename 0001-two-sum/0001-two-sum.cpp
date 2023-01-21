class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2, 0);
        unordered_map<int, int> map; // nums[index], index
        
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                if (map[target - nums[i]] == i)
                    continue;
                ret[0] = map[target - nums[i]];
                ret[1] = i;
                break;
            } else {
                map[nums[i]] = i;
            }
        }
        return ret;
    }
};