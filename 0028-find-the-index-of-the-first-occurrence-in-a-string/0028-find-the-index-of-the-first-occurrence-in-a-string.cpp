class Solution {
public:
    unsigned int make_hash(string s, int st, int end) {
        unsigned int sum = 0;
        for (int i = st; i < end; i++) {
            sum += (unsigned int)s[i];
        }
        return sum;
    }
    bool double_check(string s1, string s2, int st, int end) {
        int idx = 0;
        for (int i = st; i < end; i++) {
            if (s1[i] != s2[idx++])
                return false;
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        int nsize = needle.size();
        unsigned int hval_needle = make_hash(needle, 0, nsize);
        unsigned int hval_window = make_hash(haystack, 0, nsize);
        //cout << hval_needle << endl;
        
        if (hval_window == hval_needle && double_check(haystack, needle, 0, nsize))
            return 0;
        for (int i = 1; i + nsize <= haystack.length(); i++) {
            hval_window -= (unsigned int)haystack[i - 1];
            hval_window += (unsigned int)haystack[i + nsize - 1];
            //cout << hval_window << " "; 
            if (hval_window == hval_needle && double_check(haystack, needle, i, i + nsize))
                return i;
        }
        return -1;
    }
};