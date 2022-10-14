class Solution {
public:
    int strStr(string haystack, string needle) {
        int ssize = haystack.length();
        int wsize = needle.length();
        for (int i = 0; i < ssize - wsize + 1; i++) {
            if (haystack.substr(i, wsize) == needle)
                return i;
        }
        return -1;
    }
};