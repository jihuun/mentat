class Solution {
    int minval(int a, int b, int c) {
        int ret = 0;
        if (a < b)
            ret = a;
        else
            ret = b;
        if (c < ret)
            ret = c;
        return ret;
    }
    int vis[101][3] = {0};
public:
    int paint(vector<vector<int>>& cost, int h, int clr) {
        if (h == cost.size())
            return 0;
        if (vis[h][clr])
            return vis[h][clr];
        // the other value is always be: (clr + 1) % 3 and (clr + 2) % 3
        vis[h][clr] = min(paint(cost, h + 1, (clr + 1) % 3), paint(cost, h + 1, (clr + 2) % 3))  + cost[h][clr];
        return vis[h][clr];
    }
    int minCost(vector<vector<int>>& costs) {
        return minval(paint(costs, 0, 0), paint(costs, 0, 1), paint(costs, 0, 2));
    }
};