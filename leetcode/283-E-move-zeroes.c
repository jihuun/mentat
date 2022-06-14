// https://velog.io/@soopsaram/Leetcode-283.-Move-Zeroes

void moveZeroes(int* nums, int numsSize){
    int retcnt = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i])
            nums[retcnt++] = nums[i];
    for (int i = retcnt; i < numsSize; i++)
        nums[i] = 0;
}
