/*
number of k-faces dice

brute force -> check all possiblity : n power k


n = 3  k = 6  tgt = 12


(1) 2 3 4 5 6
1 2 3 4 5 (6)
1 2 3 4 (5) 6

(0, 6, 5) 

*/

// n: number of k-faces dice
class Solution {
    vector<vector<int>> memo;
    int total;
    int bt(int n, int face, int sum, int tgt) {
        /* base case */
        if (sum > tgt) // 
            return 0;
        if (n == 0) {
            if (sum == tgt) //found
                return 1;
            return 0;
        }
        if (memo[n][sum] != -1)
            return memo[n][sum];
        int way = 0;
        for (int i = 1; i <= face; i++) {
            // bt() with unique (n, sum) is calculated repeatedly. and it return the same result, so memoize it.
            way = (way + bt(n - 1, face, sum + i, tgt)) % 1000000007;
        }
        memo[n][sum] = way;
        return memo[n][sum];
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        memo = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));
        return bt(n, k, 0, target);
    }
};