class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0;
        string longest = "";
        
        while (1) {
            for (int i = 0; i < strs.size(); i++) {
                if (strs[i][idx] == '\0' || strs[i][idx] != strs[0][idx])
                    return longest;
            }
            longest = longest + strs[0][idx];
            idx++;
        }
        return longest;
    }
};