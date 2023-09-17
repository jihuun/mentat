class Solution {
public:
    int vis[101][101] = {0};
    int uniquePaths(int m, int n) {
        if (m < 0 || n < 0)
            return 0;
        if (m == 1 && n == 1)
            return 1;
        if (vis[m][n])
            return vis[m][n];
        vis[m][n] = uniquePaths(m-1, n) + uniquePaths(m, n-1);
        return vis[m][n];
    }
};