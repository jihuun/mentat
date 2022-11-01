class Solution {
public:
    void reverse(vector<int> &v, int st, int end) {
        while (st < end) {
            int tmp = v[st];
            v[st] = v[end];
            v[end] = tmp;
            st++;
            end--;
        }
    }
    
    void rotate(vector<int> &nums, int k) {
        int nsize = nums.size();
        k = k % nsize;
        
        reverse(nums, 0, nsize - k - 1);
        reverse(nums, nsize -k, nsize - 1);
        reverse(nums, 0, nsize - 1);
    }
};