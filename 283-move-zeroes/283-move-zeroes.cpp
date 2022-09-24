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
    void swap(vector<int>& nums, int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
public:
    void moveZeroes(vector<int>& nums) {
        int retcnt = 0;
        int last_zero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                swap(nums, i, last_zero++);
        }
    }
};