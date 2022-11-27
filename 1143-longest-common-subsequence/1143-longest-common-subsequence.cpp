class Solution {
    vector<vector<int>> mem;
    string t1;
    string t2;
    
    int longest(int i1, int i2) {
        if (i1 < 0 || i2 < 0)
            return 0;
        if (mem[i1][i2] != -1)
            return mem[i1][i2];
        if (t1[i1] == t2[i2]) {
            mem[i1][i2] = longest(i1 - 1, i2 - 1) + 1;
        } else {
            mem[i1][i2] = max(longest(i1, i2 - 1), longest(i1 - 1, i2));
        }
        return mem[i1][i2];
        
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        mem = vector<vector<int>>(1001, vector<int>(1001, -1));
        t1 = text1;
        t2 = text2;
        return longest(t1.size() - 1, t2.size() - 1);
    }
};