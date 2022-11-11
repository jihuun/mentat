class Solution {
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
public:
    /*
    0 1 2 3 4 5 6 n=7 k=3
    1,2,3,4,5,6,7
            ^
    4 3 2 1 7 6 5
    5 6 7 1 2 3 4
    */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};