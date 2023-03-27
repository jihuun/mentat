class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();
        vector<vector<int>> mem(size1 + 1, vector<int>(size2 + 1, 0));
        
        for (int i = size1 - 1; i >= 0; i--) {
            for (int j = size2 - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    mem[i][j] = mem[i+1][j+1] + 1;
                } else {
                    mem[i][j] = std::max(mem[i+1][j], mem[i][j+1]);
                }
            }
        }
        return mem[0][0];
    }
};