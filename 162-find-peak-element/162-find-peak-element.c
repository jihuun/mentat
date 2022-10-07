
/*
peak - down-high-down pair
[1,2,1, 3,5,6,4]
   |
 0         1        2       3 4 5 6 7 
 [0]-[1]  [1]-[2]  [3]-[2]
 -1        1       1

 76543462
_|   _ | _

- left > mid   -> left side
- mid < right  -> right side
- left < mid && mid > right -> answer
*/
int findPeakElement(int* nums, int numsSize){
    int left = 0, right = numsSize - 1, mid = 0;
    // check input valid range : 
    if (numsSize == 0) {
        fprintf(stderr, "invalid input\n");
        return 1;
    }
        
    while (left < right) {
        mid = left + (right - left) / 2; 
        if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]) {
            right = mid - 1;
        } else if (mid + 1 < numsSize && nums[mid] < nums[mid + 1]) {
            left = mid + 1;  
        } else if (((mid - 1 >=0 && mid + 1 < numsSize) && (nums[mid - 1] < nums[mid] && nums[mid > nums[mid - 1]])) ||
                     mid == 0 && nums[mid + 1] < nums[mid] || 
                     mid == numsSize - 1 && nums[mid] > nums[mid - 1]) {
            return mid;
        }
    }
    return left;
}