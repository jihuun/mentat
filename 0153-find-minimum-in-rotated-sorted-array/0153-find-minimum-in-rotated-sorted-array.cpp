class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        return nums[left];
    }
};

/* 
if nums[mid] < nums[right] -> then the answer is in the left part
[2,3,4,5,6,0,1]
       ^     ^
[6,0,1,2,3,4,5]  answer must be in left part
       ^  <  ^
[0,1,2,3,4,5,6]  answer must be in left part
       ^  <  ^
[1,2,3,4,5,6,0]
       ^     ^
*/