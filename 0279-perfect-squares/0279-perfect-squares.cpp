class Solution {
    unordered_map<int, int> mem;
public:
    int numSquares(int n) {
        int min = INT_MAX;
        if (mem.find(n) != mem.end())
            return mem[n];
        if (n == 0) {
            return 0;
        }
        
        for (int i = 1; i * i <= n; i++) {
            if (n - i * i < 0)
                continue;
            min = std::min(min, numSquares(n - i * i) + 1);
        }
        mem[n] = min;
        return min;
    }
};