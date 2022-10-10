/*
2 4 2 1 0 4 0 0 0 3
T T F F F T F F F
1 0 2
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nsize = nums.size();
        if (nsize == 1) return true;
        vector<bool> mem(nsize, false);
        for (int i = nsize - 2; i >= 0; i--) {
            for (int j = i; j <= i + nums[i]; j++) {
                if (j == nsize - 1 || mem[j] == true) {
                    mem[i] = true;
                    if (i == 0)
                        return true;
                    break;
                }
            }
        }    
        return false;
    }
};