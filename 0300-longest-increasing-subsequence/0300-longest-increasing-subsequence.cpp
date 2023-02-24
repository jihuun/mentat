/*
새로운 sub배열(정렬된)을 생성하는 방법. sub배열의 크기가 LIS임
20 100 10 12 5 13

20 100
10 100
10 12
5 12
5 12 13
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxlen = 1;
        vector<int> mem(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    mem[i] = std::max(mem[i], mem[j] + 1);
                }
            }
            maxlen = std::max(maxlen, mem[i]);
        }
        return maxlen;
    }
};