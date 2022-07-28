
#define max(a,b) (((a) > (b)) ? (a) : (b))
int maxProfit(int* prices, int pricesSize){
    int min_val = INT_MAX;
    int max_profit = 0;
    
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min_val)
            min_val = prices[i];
        else
            max_profit = max(prices[i] - min_val, max_profit);
    }
    return max_profit;
}