// https://velog.io/@soopsaram/Leetcode-322.-Coin-Change

int visit[10001];
int coin_amount(int* coins, int coinsSize, int amount){
    int ret = 0, val = 0;
    int min_amt = INT_MAX;
    int max_coin = 0;

    /* base case */
    if (amount == 0)
        return 0;
    if (amount < 0)
        return -1;
    if (visit[amount])
        return visit[amount];
    for (int i = 0; i < coinsSize; i++) {
        if (coins[i] == amount)
            return 1;
    }

    /* recursion */
    for (int i = 0; i < coinsSize; i++) {
        val = coin_amount(coins, coinsSize, amount - coins[i]);
        if (val == -1)
            continue;
        if (val < min_amt)
            min_amt = val;
    }
    if (min_amt == INT_MAX)
        visit[amount] = -1;
    else
        visit[amount] = min_amt + 1;
    return visit[amount];

}

int coinChange(int* coins, int coinsSize, int amount){
    memset(visit, 0, sizeof(int) * 10001);
    return coin_amount(coins, coinsSize, amount);
}
