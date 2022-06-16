// https://velog.io/@soopsaram/Leetcode-7.-Reverse-Integer

int reverse(int n){
    int digit[11] = {0};
    int sign = 1;
    int dcnt = 0;
    long ret = 0;
    long x = n;

    if (x < 0) {
        sign = -1;
        x = x * sign;
    }

    while (x > 0) {
        int val = x % 10;
        digit[dcnt++] = val;
        x = x / 10;
    }

    for (int i = 0; i < dcnt; i++) {
        ret += digit[i];
        ret = ret * 10;
    }
    ret /= 10;
    if (ret >= -INT_MAX && ret < INT_MAX)
        return (int)ret * sign;
    else
        return 0;
}
