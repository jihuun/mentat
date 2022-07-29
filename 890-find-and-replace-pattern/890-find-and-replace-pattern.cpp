class Solution {
    bool check_isomorphic(string str, string pat) {
        int ssize = str.length();
        unordered_map<char, char> table_str;
        unordered_map<char, char> table_pat;
        for (int i = 0; i < ssize; i++) {
            if (table_str[str[i]] && table_str[str[i]] != pat[i])
                return false;
            table_str[str[i]] = pat[i];
            if (table_pat[pat[i]] && table_pat[pat[i]] != str[i])
                return false;
            table_pat[pat[i]] = str[i];
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        
        for (auto s: words) {
            if (check_isomorphic(s, pattern))
                ret.push_back(s);
        }
        return ret;
    }
};