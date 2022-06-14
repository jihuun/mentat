// https://velog.io/@soopsaram/Leetcode-414.-Third-Maximum-Number

int cmp(const void *a, const void *b)
{
    //return *(int *)b - *(int *)a;
    int num1 = *(int *)b;
    int num2 =  *(int *)a;
    if (num1 > num2)
        return 1;
    else if(num1 < num2)
        return -1;
    else
        return 0;
}

int thirdMax(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int prev = nums[0];
    int cnt = 1;
    int max = 0;
    for (int i = 1; i < numsSize; i++) {
        max = nums[i];
        if (max != prev)
            cnt++;
        prev = max;
        if (cnt == 3)
            return max;
    }
    if (cnt < 3)
        return nums[0];
    else
        return max;
}
