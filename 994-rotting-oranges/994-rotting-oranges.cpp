class Solution {
    int r_size;
    int c_size;
    bool is_fresh(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= r_size || c < 0 || c >= c_size)
            return false;
        if (grid[r][c] == 1)
            return true;
        return false;
    }
    void rotting(queue<tuple<int, int, int>> &q, vector<vector<int>> &grid, int r, int c, int step) {
        if (is_fresh(grid, r, c)) {
            grid[r][c] = 2;
            q.push(make_tuple(r, c, step + 1));
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        r_size = grid.size();
        c_size = grid[0].size();
        queue<tuple<int, int, int>> q; // (row, col, step)
        int r = 0; 
        int c = 0;
        int step = 0;
        
        for (int i = 0; i < r_size; i++) {
            for (int j = 0; j < c_size; j++) {
                if (grid[i][j] == 2)
                    q.push(make_tuple(i, j, 0));
            }
        }
        
        while (!q.empty()) {
            tuple<int, int, int> check = q.front();
            q.pop();
            r = get<0>(check);
            c = get<1>(check);
            step = get<2>(check);
            
            rotting(q, grid, r+1, c, step);
            rotting(q, grid, r, c+1, step);
            rotting(q, grid, r-1, c, step);
            rotting(q, grid, r, c-1, step);
        }

        for (int i = 0; i < r_size; i++) {
            for (int j = 0; j < c_size; j++) {
                if (grid[i][j] == 1) {
                    step = -1;
                    break;
                }
            }
        }
        return step;
    }
};