class Solution {
public:
    vector<vector<int>> mem;
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        mem = vector(row + 1, vector<int>(col + 1, -1));
        return minsum(grid, 0, 0);
    }
    
    int minsum(vector<vector<int>>& grid, int i, int j) {
        if (mem[i][j] != -1)
            return mem[i][j];
        if (i == grid.size() || j == grid[0].size())
            return INT_MAX;
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];
        
        mem[i][j] = grid[i][j] + min(minsum(grid, i+1, j), minsum(grid, i, j+1));
        return mem[i][j];
    }
};