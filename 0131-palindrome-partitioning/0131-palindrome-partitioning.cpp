class Solution {
    vector<vector<string>> ret;
    vector<string> tmp;
    
    bool is_palindrome(string s) {
        int slen = s.length();
        
        for (int i = 0; i < slen / 2; i++) {
            if (s[i] != s[slen - i - 1])
                return false;
        }
        return true;
    }
    
    void recur(string s, int cur) {
        int ssize = s.length();
        if (cur >= ssize) {
            ret.push_back(tmp);
            return;
        }
        
        for (int i = cur; i < ssize; i++) {
            string sub = s.substr(cur, i - cur + 1);
            if (!is_palindrome(sub))
                continue;
            tmp.push_back(sub);
            recur(s, i + 1);
            tmp.pop_back();
        }        
    }
    
public:
    vector<vector<string>> partition(string s) {
        recur(s, 0);
        return ret;
    }
};