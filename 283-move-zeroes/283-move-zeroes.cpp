/*

0 0 1

    z
5 0 1 0 3
        n
    z
1 2 0 3 0 0 4
      n
      z
    3 0 0 0 4
            n
            
            
z : increase at  
nz: increase at
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int retcnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                nums[retcnt++] = nums[i];
        }
        for (int i = retcnt; i < nums.size(); i++)
            nums[i] = 0;
    }
};