class Solution {
public:
    unordered_map<char, int> pos;
    int l = 0, r = 0;
    int maxlen = 0;

    int lengthOfLongestSubstring(std::string s) {
        for (int r = 0; r < s.length(); r++) {
            if (pos.find(s[r]) != pos.end()) // abba
                l = max(l, pos[s[r]] + 1);
            pos[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};