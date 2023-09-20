class Solution {
public:
    int vis[101][101] = {0};
    int path(vector<vector<int>>& obs, int i , int j) {
        if (i < 0 || j < 0)
            return 0;
        if (obs[i][j])
            return 0;
        if (i == 0 && j == 0)
            return 1;
        if (vis[i][j])
            return vis[i][j];
        
        vis[i][j] = path(obs, i - 1, j) + path(obs, i, j-1);
        return vis[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        return path(obs, obs.size() - 1, obs[0].size() - 1);
    }
};