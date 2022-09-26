/*
 [7,2,5,10,8] , candi : 21
       ^
 
*/
class Solution {
    bool check_mid_capable(vector<int> nums, int candidate, int tgt_split) {
        // check how many split with candidate value
        int split = 1;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > candidate) {
                sum = nums[i];
                split++;
            }
        }
        if (split > tgt_split) // if candidate value sperate more than m, then false 
            return false;
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int left = *std::max_element(nums.begin(), nums.end());
        int right = std::accumulate(nums.begin(), nums.end(), 0);
        int mid = 0;
        
        while (left < right) {
            mid = left + (right - left) / 2;
            if (check_mid_capable(nums, mid, m))    // if mid can seperate m times. it means there could be more small value exist.
                right = mid;
            else                                    // means mid value is too small,
                left = mid + 1;
        }
        return left;
    }
};