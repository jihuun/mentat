class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_p = 0;
        int cur_min = prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            cur_min = std::min(cur_min , prices[i]);
            max_p = std::max(max_p, prices[i] - cur_min);
        }
        return max_p;
    }
};