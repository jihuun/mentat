class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int cur_sum = 0;
        int cnt = 0;
        
        freq[0]++; // for case of (cur_sum - k == 0)
        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            
            if (freq.find(cur_sum - k) != freq.end()) {
                cnt += freq[cur_sum - k];
            }
            freq[cur_sum]++;
        }
        return cnt;
    }
};