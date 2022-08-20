

int findDuplicate(int* nums, int numsSize){
    int freq[100001] = {};
    
    for (int i = 0; i < numsSize; i++) {
        if (freq[nums[i]] > 0)
            return nums[i];
        freq[nums[i]]++;
    }
    return nums[0];
}