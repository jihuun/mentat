class Solution {
    unordered_map<string, bool> map;
    unordered_map<int, int> mem;
    
    int recur(string s, int cur) {
        if (mem.find(cur) != mem.end())
            return mem[cur];
        if (cur == s.length())
            return 1;
        if (cur > s.length() || s[cur] == '0')
            return 0;
        int ret = 0;
        if (map.find(s.substr(cur, 1)) != map.end())
            ret += recur(s, cur + 1); 
        if (map.find(s.substr(cur, 2)) != map.end())
            ret += recur(s, cur + 2); 
        mem[cur] = ret;
        return ret;
    }
public:
    int numDecodings(string s) {
        for (int i = 1; i <= 26; i++)
            map[std::to_string(i)] = true;
        return recur(s, 0);
    }
};