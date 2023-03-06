class Solution {
public:
    int mem[1001][1001];
    string s1, s2;
    
    int recur(int i1, int i2) {
        if (i1 < 0 || i2 < 0)
            return 0;
        if (i1 == 0 && i2 == 0) {
            if (s1[i1] == s2[i2])
                return 1;
            else
                return 0;
        }
        if (mem[i1][i2] != -1)
            return mem[i1][i2];
        
        if (s1[i1] == s2[i2]) {
            mem[i1][i2] = recur(i1-1, i2-1) + 1;
        } else {
            mem[i1][i2] = std::max(recur(i1, i2-1), recur(i1-1, i2));
        }
        return mem[i1][i2];
            
    }
    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1;
        s2 = text2;
        for (int i = 0; i < 1001; i++)
            for (int j = 0; j < 1001; j++)
                mem[i][j] = -1;
        
        return recur(s1.size() -1, s2.size() -1);
    }
};