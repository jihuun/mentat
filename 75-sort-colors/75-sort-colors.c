
void sortColors(int* nums, int numsSize){
    int freq[3] = {0};
    int curidx = 0;
    int i = 0;
    for (int i = 0; i < numsSize; i++)
        freq[nums[i]]++;
    while (i < numsSize) {
        if (freq[curidx]--)
            nums[i++] = curidx;
        else
            curidx++;
    }
}