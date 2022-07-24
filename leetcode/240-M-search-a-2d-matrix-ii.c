// https://velog.io/@soopsaram/Leetcode-240.-Search-a-2D-Matrix-II

int bin_search(int *arr, int size, int tgt)
{
    int left = 0, right = size - 1, mid = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == tgt)
            return mid;
        else if (arr[mid] < tgt)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    for (int i = 0; i < matrixSize; i++) {
        if (target < matrix[i][0])
            break;
        if (target > matrix[i][*matrixColSize - 1])
            continue;
        if (bin_search(matrix[i], *matrixColSize, target) != -1)
            return true;
    }
    return false;
}
