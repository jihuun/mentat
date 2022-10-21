class Solution {
public:
    unordered_map<int, int> mem;
    int recur(string s, int pos) {
        if (mem.find(pos) != mem.end())
            return mem[pos];
        if (pos == s.length())
            return 1;
        if (pos > s.length())
            return 0;
        if (s[pos] == '0')
            return 0;
        
        int ret = 0;
        ret += recur(s, pos + 1);
        if (stoi(s.substr(pos, 2)) <= 26)
            ret += recur(s, pos + 2);
        mem[pos] = ret;
        return ret;
    }
    int numDecodings(string s) {
        return recur(s, 0);
    }
};