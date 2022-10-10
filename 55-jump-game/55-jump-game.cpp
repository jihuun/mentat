/*
2 4 2 1 0 4 0 0 0 3
T T F F F T F F F
1 0 2
*/
class Solution {
    vector<int> mem;
    int last_idx;
    bool check_reach(vector<int>& nums, int cur, int end) {
        if (mem[cur] != -1)
            return mem[cur];
        if (cur == last_idx)
            return true;
        if (end > last_idx)
            end = last_idx;
        for (int i = cur + 1; i <= end; i++) {
            if (mem[i] == -1)
                mem[i] = check_reach(nums, i, i + nums[i]);
            if (mem[i] == true)
                return true;
        }
        mem[cur] = false;
        return mem[cur];
    }
public:
    bool canJump(vector<int>& nums) {
        last_idx = nums.size() - 1;
        if (last_idx == 0) return true;
        mem = vector<int>(nums.size(), -1);
        
        return check_reach(nums, 0, nums[0]);
    }
};