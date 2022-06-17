// https://velog.io/@soopsaram/C-Binary-Search-%EA%B5%AC%ED%98%84

int bin_search(int *nums, int numsSize, int tgt)
{
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;

    while (left <= right) {
        mid = (left + right) >> 1;
        if (tgt == nums[mid])
            return mid;
        else if (tgt < nums[mid])
            right = mid - 1;
        else if (tgt > nums[mid])
            left = mid + 1;
    }
    return -1;
}

int search(int* nums, int numsSize, int target){
    return bin_search(nums, numsSize, target);
}
