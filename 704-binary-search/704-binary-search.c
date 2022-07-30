

int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1, mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (target == nums[mid])
            return mid;
        else if (target < nums[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}