class Solution {
    string btn[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ret;
    string tmp;
    int ssize;
public:
    void btrack(string s, int idx) {
        if (idx == ssize) {
            ret.push_back(tmp);
            return;
        }
        
        int num = s[idx] - '0';
        for (int i = 0; i < btn[num].size(); i++) {
            tmp += (btn[num][i]);
            btrack(s, idx + 1);
            tmp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        ssize = digits.size();
        if (ssize == 0)
            return ret;
        btrack(digits, 0);   
        return ret;
    }
};