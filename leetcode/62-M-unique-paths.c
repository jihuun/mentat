// https://velog.io/@soopsaram/Leetcode-62.-Unique-Paths 

/* DP bottom-up */
int uniquePaths(int m, int n){
    int ret[101][101] = {0};

    for (int i = 1; i <= m; i++)
        ret[i][1] = 1;
    for (int j = 1; j <= n; j++)
        ret[1][j] = 1;
    for (int i = 2; i <= m; i++) {
        for (int j = 2; j <= n; j++) {
            ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
        }
    }
    return ret[m][n];
}

#if 0
/* DP top-down */
int visited[101][101];
int uniquePaths(int m, int n){
    /* base case */
    if (visited[m][n])
        return visited[m][n];
    if (m == 1 || n == 1) return 1;
    /* recursive */
    visited[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    return visited[m][n];
}

/* brute force */
// f(m,n) = f(m-1, n) + f(m, n-1)
int uniquePaths(int m, int n){
    /* base case */
    if (m == 1 || n == 1) return 1;
    /* recursive */
    return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}
#endif
