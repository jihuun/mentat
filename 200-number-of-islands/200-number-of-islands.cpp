class Solution {
    int rsize;
    int csize;
    int **visited;
    bool check_island(vector<vector<char>>& grid, int sr, int sc) {
        
        if (sr < 0 || sr >= rsize)
            return false;
        if (sc < 0 || sc >= csize)
            return false;
        if (grid[sr][sc] == '0')
            return false;
        if (visited[sr][sc] == 1)
            return false;
        
        visited[sr][sc] = 1;
        grid[sr][sc] = '0';
        check_island(grid, sr-1, sc);
        check_island(grid, sr+1, sc);
        check_island(grid, sr, sc-1);
        check_island(grid, sr, sc+1); 
        return true;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        rsize = grid.size();
        csize = grid[0].size();
        int nr_island = 0;
        visited = (int **)calloc(rsize, sizeof(int *));
        for (int i = 0; i < rsize; i++)
            visited[i] = (int *)calloc(csize, sizeof(int));
        
        for (int i = 0; i < rsize; i++) {
            for (int j = 0; j < csize; j++) {
                if (check_island(grid, i, j))
                    nr_island++;
            }
        }
        return nr_island;
    }
};