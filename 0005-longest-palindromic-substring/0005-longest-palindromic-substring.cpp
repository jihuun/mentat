class Solution {
public:
    // abcb
    // abba
    // babad
    string pal_from_middle(string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        l++;
        r--;
        return s.substr(l, r - l + 1);
    }
    string longestPalindrome(string s) {
        string ret;
        for (int i = 0; i < s.length(); i++) {
            string larger = "";
            string odd = pal_from_middle(s, i, i);
            string even = pal_from_middle(s, i, i + 1);
            larger = odd.length() > even.length() ? odd : even;
            ret = larger.length() > ret.length() ? larger : ret;
        }
        return ret;
    }
};