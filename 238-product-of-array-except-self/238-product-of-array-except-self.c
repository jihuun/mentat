

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int z_cnt = 0;
    int prod = 1;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            z_cnt++;
            if (z_cnt > 1)
                break;
            continue;
        }
        prod *= nums[i];
    }
    if (z_cnt == 0) {
        for (int i = 0; i < numsSize; i++)
            nums[i] = prod / nums[i];
    } else if (z_cnt == 1) {
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] == 0)
                nums[i] = prod;
            else 
                nums[i] = 0;
        }
    } else {
        for (int i = 0; i < numsSize; i++)
            nums[i] = 0;
    }
    return nums;
}