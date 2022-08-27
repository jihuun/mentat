class Solution {
    int ssize;
    
    int palin_center(string &s, int lo, int hi) {
        int cnt = 0;
        
        while (lo >= 0 && hi < ssize) {
            if (s[lo] != s[hi])
                break;
            lo--;
            hi++;
            cnt++;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        ssize = s.length();
        int pcnt = 0;
        
        for (int i = 0; i < ssize; i++) {
            pcnt += palin_center(s, i, i);
            pcnt += palin_center(s, i, i + 1);
        }
        return pcnt;
    }
};