class Solution {
public:
    int bin_search(vector<int>& nums, int l, int r, int tgt) {
        int mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > tgt)
                r = mid;
            else 
                l = mid + 1;
        }
        return l;
    }
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1;
            for (int r = nums.size() - 1; l < r; r--) {
                // i l 0 0 0 r
                // b > c - a
                int tgt = nums[r] - nums[i];
                int pos = bin_search(nums, l, r, tgt);
                cnt += r - pos;
            }
        }
        return cnt;
    }
};