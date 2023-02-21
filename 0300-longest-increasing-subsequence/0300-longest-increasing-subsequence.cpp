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
        vector<int> sub;
        sub.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            if (sub[sub.size() - 1] < nums[i]) {
                sub.push_back(nums[i]);
            } else {
                int j = 0;
                while (sub[j] < nums[i]) j++;
                sub[j] = nums[i];
            }
        }
        return sub.size();
    }
};