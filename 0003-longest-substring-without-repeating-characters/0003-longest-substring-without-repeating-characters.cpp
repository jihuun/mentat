class Solution {
public:
    std::unordered_map<char, int> table;
    int l = 0, r = 0;
    int maxlen = 0;

    int lengthOfLongestSubstring(std::string s) {
        while (r < s.length()) {
            table[s[r]]++;
            while (table[s[r]] > 1) {
                table[s[l]]--;
                l++;
            }
            maxlen = std::max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};