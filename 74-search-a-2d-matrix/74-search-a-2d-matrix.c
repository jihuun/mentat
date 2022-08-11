

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = matrixSize - 1;
    int col = 0;
    while (row >= 0 && row < matrixSize && col >= 0 && col < *matrixColSize) {
        if (target == matrix[row][col])
            return true;
        else if (target < matrix[row][col]) {
            row--;
        } else {
            col++;
        }
    }
    return false;
}