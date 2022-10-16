class Solution {
public:
    unordered_map<int, int> mem;
    
    /* f(i) = f(i+1) + f(i+2) */
    int recur(string s, int cur) {
        if (mem.find(cur) != mem.end())
            return mem[cur];
        if (cur == s.length())
            return 1;
        if (cur > s.length() || s[cur] == '0')
            return 0;
        
        int ret = recur(s, cur + 1);
        if (stoi(s.substr(cur, 2)) <= 26)
            ret += recur(s, cur + 2);
        mem[cur] = ret;
        return ret;
    }
    int numDecodings(string s) {
        return recur(s, 0);
    }
};