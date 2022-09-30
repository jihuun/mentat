/*
2 3 -2 4
^^^
2 8 1 5
^^^^^^^
1 -1 2 8 9 -1 29
^    ^^^^^    ^^
-1 -3 -7 -2
^^^^^  

[0] [0][1] [0][1][2] [0][1][2][3]
                        

*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int final_max = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int saved_max_so_far = max_so_far; 
            max_so_far = std::max({nums[i], nums[i] * max_so_far, nums[i] * min_so_far});
            min_so_far = std::min({nums[i], nums[i] * saved_max_so_far, nums[i] * min_so_far}); // need to use max_so_far of previous version
            //printf("(%d,%d)", max_so_far, min_so_far);
            final_max = std::max(final_max, max_so_far);
        }
        return final_max;
    }
};