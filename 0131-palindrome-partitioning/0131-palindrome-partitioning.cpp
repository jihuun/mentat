class Solution {
    vector<vector<string>> ret;
    vector<string> tmp;
    
    bool is_palindrome(string s) {
        int ssize = s.length();
        for (int i = 0; i < ssize / 2; i++) {
            if (s[i] != s[ssize - i - 1])
                return false;
        }
        return true;
    }
    void recur(string s, int cur) {
        if (cur >= s.length()) {
            ret.push_back(tmp);
            return;
        }
        
        for (int i = cur; i < s.length(); i++) {
            string tgt = s.substr(cur, i-cur+1);
            if (!is_palindrome(tgt))
                continue;
            tmp.push_back(tgt);
            recur(s, i+1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        recur(s, 0);
        return ret;
    }
};