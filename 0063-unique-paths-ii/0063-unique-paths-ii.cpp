class Solution {
public:
    int size_r = 0;
    int size_c = 0;
    int vis[101][101] = {0};

    int path(vector<vector<int>>& obt, int i, int j) {
        if (i < 0 || j < 0)
            return 0;
        if (obt[i][j] == 1)
            return 0;
        if (i == 0 && j == 0)
            return 1;
        if (vis[i][j])
            return vis[i][j];
        vis[i][j] = path(obt, i - 1, j) + path(obt, i, j - 1);
        return vis[i][j];
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obt) {
        size_r = obt.size();
        size_c = obt[0].size();
        return path(obt, size_r - 1, size_c - 1);
    }
};