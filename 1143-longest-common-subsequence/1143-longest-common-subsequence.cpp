class Solution {
public:
    string t1, t2;
    int longestCommonSubsequence(string text1, string text2) {
        int mem[1002][1002] = {0};
        t1 = text1;
        t2 = text2;
        for (int i = t1.size() - 1; i >= 0; i--) {
            for (int j = t2.size() - 1; j >= 0; j--) {
                if (t1[i] == t2[j]) {
                    mem[i][j] = mem[i+1][j+1] + 1;
                } else {
                    mem[i][j] = std::max(mem[i+1][j], mem[i][j+1]);
                }
            }
        }
        return mem[0][0];
    }
};