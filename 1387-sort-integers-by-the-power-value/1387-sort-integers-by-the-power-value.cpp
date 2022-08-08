class Solution {
    int dp[1000001];
    int power_of_num(int val) {
        if (val == 1)
            return 0;
        if (dp[val])
            return dp[val];
        if (val % 2 == 0)
            dp[val] = power_of_num(val / 2) + 1;
        else
            dp[val] = power_of_num(val * 3 + 1) + 1;
        return dp[val];
    }
public:
    int getKth(int lo, int hi, int k) {
        int ret = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        for (int i = lo; i <= hi; i++)
            pq.push(make_pair(power_of_num(i), i));
        while (k--) {
            ret = pq.top().second;
            pq.pop();
        }
        return ret;
    }
};