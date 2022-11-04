class Solution {
    void reverse(vector<int> &nums, int st, int end) {
        while (st < end) {
            int tmp = nums[st];
            nums[st] = nums[end];
            nums[end] = tmp;
            st++;
            end--;
        }    
    }
public:
    void rotate(vector<int> &nums, int k) {
        int nsize = nums.size();
        k = k % nsize;
        reverse(nums, 0, nsize - k - 1);
        reverse(nums, nsize - k, nsize - 1);
        reverse(nums, 0, nsize - 1);
    }
};