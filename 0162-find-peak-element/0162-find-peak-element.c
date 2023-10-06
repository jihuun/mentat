int findPeakElement(int* nums, int numsSize){
    int l = 0, r = numsSize - 1;
    int mid = 0;
    
    while (l < r) {
        mid = l + (r - l) / 2;
        if (nums[mid] > nums[mid + 1])
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}