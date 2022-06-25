// https://velog.io/@soopsaram/Leetcode-14.-Longest-Common-Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest = "";
        int nr_strs = strs.size();
        int ssize = strs[0].size();

        for (int idx = 0; idx < ssize; idx++) {
            int same_cnt = 1;
            for (int elem = 1; elem < nr_strs; elem++) {
                if (strs[elem][idx] == '\0')
                    return longest;
                if (strs[0][idx] != strs[elem][idx])
                    return longest;
                same_cnt++;
            }
            if (same_cnt == nr_strs)
                longest = strs[0].substr(0, idx+1);
        }

        return longest;
    }
};
