

int numIdenticalPairs(int* nums, int numsSize){
    int ret = 0;
    int map_table[101] = {0,};

    for (int i = 0; i < numsSize; i++)
        map_table[nums[i]]++;
    
    for (int i = 0; i < 101; i++)
        if (map_table[i])
            ret += map_table[i] * (map_table[i] - 1) / 2;

    return ret;
}