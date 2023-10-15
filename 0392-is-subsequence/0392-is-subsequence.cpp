class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length())
            return false;
        int si = 0, ti = 0;
        for (; si < s.length(); si++) {
            while (s[si] != t[ti++]) {
                if (ti >= t.length())
                    return false;
            }
        }
        return true;
    }
};