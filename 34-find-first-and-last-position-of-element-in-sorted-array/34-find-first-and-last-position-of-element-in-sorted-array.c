
int binary_search(int *nums, int left, int right, int target) 
{
    int mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (target == nums[mid])
            return mid;
        else if (target < nums[mid])
            right = mid - 1;
        else if (nums[mid] < target)
            left = mid + 1;
    }
    return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *ret = (int *)malloc(sizeof(int) * 2);
    
    int idx = binary_search(nums, 0, numsSize - 1, target);
    if (idx == -1) {
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    int l_idx = idx, r_idx = idx;
    while (l_idx >= 0 && nums[l_idx] == target)
        l_idx--;
    while (r_idx < numsSize && nums[r_idx] == target)
        r_idx++;
    
    ret[0] = l_idx + 1;
    ret[1] = r_idx - 1;
    return ret;
}