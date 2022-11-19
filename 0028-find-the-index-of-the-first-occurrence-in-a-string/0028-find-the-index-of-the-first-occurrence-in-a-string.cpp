class Solution {
public:
    int strStr(string haystack, string needle) {
        int nsize = needle.length();
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack.substr(i, nsize) == needle)
                return i;
        }
        return -1;
    }
};