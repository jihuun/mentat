class Solution {
    string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ret;
    
    void backtracking(string s, string combi, int pos) {
        if (pos > s.length())
            return;
        if (pos == s.length()) {
            if (pos != 0)
                ret.push_back(combi);
            return;
        }
            
        string btn = map[s[pos] - '0'];
        for (int i = 0; i < btn.length(); i++) {
            backtracking(s, combi + btn[i], pos + 1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string combi = "";
        backtracking(digits, combi, 0);
        return ret;
    }
};