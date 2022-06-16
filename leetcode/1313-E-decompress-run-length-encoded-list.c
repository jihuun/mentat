// https://velog.io/@soopsaram/Leetcode-1313.-Decompress-Run-Length-Encoded-List

int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    for (int i = 0; i < numsSize; i += 2)
        *returnSize += nums[i];
    int *ret = (int *)malloc(sizeof(int) * *returnSize);
    int retidx = 0;
    for (int i = 0; i < numsSize; i += 2)
        for (int j = 0; j < nums[i]; j++)
            ret[retidx++] = nums[i+1];
    //assert(*returnSize == retidx);
    return ret;
}
