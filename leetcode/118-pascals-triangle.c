

/*
 * https://velog.io/@soopsaram/Leetcode-118.-Pascals-Triangle
 */

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **ret = (int **)malloc(sizeof(int *) * numRows);
    *returnColumnSizes = (int *)calloc(numRows, sizeof(int));
    *returnSize = numRows;

    for (int i = 0; i < numRows; i++) {
        ret[i] = (int *)malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                ret[i][j] = 1;
                continue;
            }
            ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
    }
    return ret;
}
