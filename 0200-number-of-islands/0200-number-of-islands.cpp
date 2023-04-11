class Solution {
public:
    int cnt = 0;
    int get_cnt(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return 0;
        if (grid[row][col] == '0')
            return 0;
        grid[row][col] = '0';
        get_cnt(grid, row + 1, col);
        get_cnt(grid, row - 1, col);
        get_cnt(grid, row, col + 1);
        get_cnt(grid, row, col - 1);
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '0')
                    continue;
                cnt += get_cnt(grid, i, j);
            }
        }
        return cnt;
    }
};