class Solution {
    vector<vector<int>> adj;
    bool is_cycle(vector<int> &vis, int cur) {
        /*
        vis 0: not visited
        vis 1: visited
        vis 2: no need to visit
        */
        if (vis[cur] == 1)
            return true;
        if (vis[cur] == 0) {
            vis[cur] = 1;
            for (int i = 0; i < adj[cur].size(); i++) {
                if (is_cycle(vis, adj[cur][i]))
                    return true;
            }
        }
        vis[cur] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses);
        vector<int> visites(numCourses, 0);
        
        for (auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (is_cycle(visites, i))
                return false;
        }
        return true;
    }
};