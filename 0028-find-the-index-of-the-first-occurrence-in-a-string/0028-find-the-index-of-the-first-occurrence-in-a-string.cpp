class Solution {
public:
    int strStr(string haystack, string needle) {
        std::hash<string> str_hash;
        size_t hval_needle = str_hash(needle);
        int nsize = needle.length();
        // abcd (cd)
        
        for (int i = 0; i + nsize - 1 < haystack.length(); i++) {
            if (str_hash(haystack.substr(i, nsize)) == hval_needle)
                return i;
        }
        return -1;
    }
};