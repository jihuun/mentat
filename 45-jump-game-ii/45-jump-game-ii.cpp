class Solution {
    int last_idx;
    vector<int> mem;
    vector<int> nums;
    
    int min_jump(int cur) {
        if (cur == last_idx)
            return 0;
        
        int local_min = 20000;
        int until_idx = std::min(last_idx, cur + nums[cur]);
        for (int i = cur + 1; i <= until_idx; i++) {
            if (mem[i] == -1)   // call recursion
                local_min = std::min(local_min, min_jump(i) + 1);
            else                // get memoization
                local_min = std::min(local_min, mem[i] + 1);
        }
        mem[cur] = local_min;
        return local_min;
    }
public:
    int jump(vector<int>& orig) {
        last_idx = orig.size() - 1;
        mem = vector<int>(orig.size(), -1);
        nums = orig;
        return min_jump(0);
    }
};