class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest = "";
        int ssize = strs.size();
        
        if (ssize == 1)
            return strs[0];
        for (int pos = 0; pos < 201; pos++) {
            char prev = strs[0][pos];
            for (int i = 0; i < ssize; i++) {
                if (strs[i][pos] == '\0')
                    return longest;
                if (prev != strs[i][pos])
                    return longest;
            }
            longest += strs[0][pos];
        }
        
        return longest;
    }
};