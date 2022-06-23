// https://velog.io/@soopsaram/Leetcode-198.-House-Robber

/*
f(n) = max(f(n-2) ~ f(0)) + nums(n)
*/

int rob(int* nums, int numsSize){
    if (numsSize == 1) return nums[0];
    int *money = (int *)calloc(numsSize, sizeof(int));
    money[0] = nums[0];
    money[1] = nums[1];
    int max_money = money[0] > money[1] ? money[0]: money[1];

    for (int i = 2; i < numsSize; i++) {
        int cur_max = 0;
        for (int j = i - 2; j >= 0; j--) {
            if (money[j] > cur_max)
                cur_max = money[j];
        }
        money[i] = cur_max + nums[i];
        if (money[i] > max_money)
            max_money = money[i];
    }
    return max_money;
}
