class Solution {
    vector<vector<int>> dp;
    string t1;
    string t2;
    int recur(int i, int j) {
        if (i < 0 || j < 0)
            return 0;
        if (i == 0 && j == 0) {
            return (int)t1[i] == t2[j];
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (t1[i] == t2[j]) {
            dp[i][j] = recur(i - 1, j - 1) + 1;
        } else {
            dp[i][j] = max(recur(i - 1, j), recur(i, j - 1));
        }
        return dp[i][j];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        dp = vector<vector<int>>(1001, vector<int>(1001, -1));
        t1 = text1;
        t2 = text2;
        return recur(t1.length() - 1, t2.length() - 1);
    }
};