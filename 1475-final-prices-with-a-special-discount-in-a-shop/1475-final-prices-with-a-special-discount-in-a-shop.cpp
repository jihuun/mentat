class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int, int>> disc; // idx, val
        
        disc.push(make_pair(0, prices[0]));
        for (int cur = 1; cur < prices.size(); cur++) {
            // incresing monotonic stack
            while (!disc.empty() && disc.top().second >= prices[cur]) {
                pair<int, int> check = disc.top();
                disc.pop();
                prices[check.first] = prices[check.first] - prices[cur];
            }
            disc.push(make_pair(cur, prices[cur]));
        }
        return prices;
    }
};