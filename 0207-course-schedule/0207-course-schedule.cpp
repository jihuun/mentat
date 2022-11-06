class Solution {
    vector<vector<int>> adj;
    bool is_cycle(vector<int> &vis, int cur) {
        if (vis[cur] == 1) // if cycle, 
            return true; 
        if (vis[cur] == 0) {
            //cout << cur << " ";
            vis[cur] = 1;
            for (int i = 0; i < adj[cur].size(); i++) {
                if (is_cycle(vis, adj[cur][i]))
                    return true;
            }
        }
        vis[cur] = 2; // if no cycle, visited node will be 2
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses);
        vector<int> visited(numCourses, 0);
        
        for (auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (is_cycle(visited, i))
                return false;
        }
        return true;
    }
};

/*
2
[[1,1]]
2
[[1,0]]
2
[[1,0],[0,1]]
4
[[1,0],[2,1],[2,0],[3,2]]
4
[[0,2],[2,1],[1,0],[3,2]]
5
[[2,0],[0,1],[1,2],[4,3],[0,4]]

*/