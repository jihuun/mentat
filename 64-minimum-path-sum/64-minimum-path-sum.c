#define min(a,b)    (((a) < (b)) ? (a) : (b))
int mem[201][201];
int path_sum(int **grid, int row, int col) {
    if (row < 0)
        return -1;
    if (col < 0)
        return -1;
    if (mem[row][col])
        return mem[row][col];
    
    int a = path_sum(grid, row - 1, col);
    int b = path_sum(grid, row, col - 1);
    if (a == -1 && b == -1) {
        return grid[row][col];
    } else if (b == -1) {
        return a + grid[row][col];
    } else if (a == -1) {
        return b + grid[row][col];
    }
    
    mem[row][col] = min(a, b) + grid[row][col];
    return mem[row][col];
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    memset(mem, 0, sizeof(int) * 201 * 201);
    return path_sum(grid, gridSize - 1, *gridColSize - 1);
}