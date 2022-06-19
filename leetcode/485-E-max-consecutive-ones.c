int findMaxConsecutiveOnes(int* nums, int numsSize){
    int cnt = 0;
    int max = 0;
    
    for (int i = 0; i <= numsSize; i++) {
        if (i == numsSize) {
            if (cnt > max)
                max = cnt;
            break;
        }
        if (nums[i] == 0) {
            if (cnt > max)
                max = cnt;
            cnt = 0;
        } else {
            cnt++;
        }
    }
    return max;
}
