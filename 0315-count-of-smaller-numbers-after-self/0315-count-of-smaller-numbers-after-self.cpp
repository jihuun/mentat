class Solution {
    vector<int> ret;
public:
    void merge(vector<pair<int, int>> &nums, int left, int mid, int right) {
        vector<pair<int, int>> sorted(right - left + 1, make_pair(0,0));
        int l = left;
        int r = mid + 1;
        int i = 0;
        int cnt = 0;
        
        while (l <= mid && r <= right) {
            if (nums[l].first > nums[r].first) {
                cnt++;
                sorted[i++] = nums[r++];
            } else {
                ret[nums[l].second] += cnt;
                sorted[i++] = nums[l++];
            }
        }
        while (l <= mid) {
            ret[nums[l].second] += cnt;
            sorted[i++] = nums[l++];
        }
        while (r <= right) {
            sorted[i++] = nums[r++];
        }
        for (auto it: sorted)
            nums[left++] = it;
    }
    
    void merge_sort(vector<pair<int, int>> &nums, int left, int right) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        merge_sort(nums, left, mid);
        merge_sort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> newnum;
        ret = vector<int>(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            newnum.push_back(make_pair(nums[i], i));
        }
        merge_sort(newnum, 0, nums.size() - 1);
        return ret;
    }
};