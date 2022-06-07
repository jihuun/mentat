// https://velog.io/@soopsaram/Leetcode-121.-Best-Time-to-Buy-and-Sell-Stock

#define max(a,b) (((a) > (b)) ? (a) : (b))
int maxProfit(int* prices, int pricesSize){
    int min_val = INT_MAX;
    int max_val = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min_val)
            min_val = prices[i];
        else
            max_val = max(prices[i] - min_val, max_val);
    }
    return max_val;
}
