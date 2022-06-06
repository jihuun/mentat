/* 
 * https://velog.io/@soopsaram/Leetcode-119.-Pascals-Triangle-II
 */

int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
    int *ret = malloc(sizeof(int) * (*returnSize));
    
    for (int i = 0; i < (*returnSize); i++)
        ret[i] = 1;
    for (int i = 1; i < rowIndex; i++)
        for (int j = i; j > 0; j--)
            ret[j] = ret[j-1] + ret[j];
    return ret;
}
