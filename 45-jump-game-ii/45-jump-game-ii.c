
#define max(a, b) (((a) > (b)) ? (a) : (b))
int jump(int* nums, int numsSize){
    int maxidx = 0;
    int curjumpend= 0;
    int cnt = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        maxidx = max(maxidx, i + nums[i]);
        if (i == curjumpend) {
            cnt++;
            curjumpend = maxidx;
        }
    }
    return cnt;
}