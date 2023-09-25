class Solution {
public:
    int vis[201][201] = {0};
    int minsum(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0)
            return INT_MAX;
        if (i == 0 && j == 0)
            return grid[i][j];
        if (vis[i][j])
           return vis[i][j];
        vis[i][j] = grid[i][j] + min(minsum(grid, i - 1, j), minsum(grid, i, j-1));
        return vis[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        return minsum(grid, grid.size() - 1, grid[0].size() - 1);
    }
};