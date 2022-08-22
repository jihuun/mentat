class Solution {
    unordered_set<string> w_table;
    int ssize;
    vector<int> mem;
    
    bool recur(string s, int start) {
        if (start == ssize)
            return true;
        if (mem[start] != -1)
            return mem[start];
        
        for (int last = start + 1; last <= ssize; last++) {
            if (w_table.find(s.substr(start, last - start)) == w_table.end())
                continue;
            if (recur(s, last)) {
                mem[start] = true; // idx is start (not last)
                return true;
            }
        }
        mem[start] = false;
        return false;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        ssize = s.length();
        mem.assign(ssize, -1);
        for (auto a: wordDict)
            w_table.insert(a);
        return recur(s, 0);
    }
};