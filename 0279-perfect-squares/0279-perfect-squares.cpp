class Solution {
    int mem[10001];
public:
    int numSquares(int n) {
        int ret = INT_MAX;
        if (mem[n])
            return mem[n];
        if (n == 0)
            return 0;
        
        for (int i = 1; i*i <= n; i++) {
            if (n - (i*i) < 0)
                continue;
            ret = min(ret, numSquares(n - (i*i)) + 1);
        }
        mem[n] = ret;
        return ret;
    }
};