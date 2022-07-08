
// shuffle-the-array


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int *ret = (int *)calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    int odd = 0; 
    int even = n;
    int retcnt = 0;
    bool is_odd = true;
    
    while (odd < n || even < numsSize) {
        if (is_odd) {
            ret[retcnt++] = nums[odd++];
            is_odd = false;
        } else {
            ret[retcnt++] = nums[even++];
            is_odd = true;
        }
    }
    return ret;
}
