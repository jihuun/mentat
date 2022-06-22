// https://velog.io/@soopsaram/Leetcode-46.-Permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        do {
            ret.push_back(nums);
        } while(std::next_permutation(nums.begin(), nums.end()));
        return ret;
    }
};
