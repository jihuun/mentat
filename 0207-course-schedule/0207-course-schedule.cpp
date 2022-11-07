class Solution {
    vector<vector<int>> adj;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses);
        unordered_map<int, int> indeg;
        vector<int> ret;
        // [1] -> [0]
        for (auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int tgt = q.front();
            q.pop();
            ret.push_back(tgt);
            for (int i = 0; i < adj[tgt].size(); i++) {
                int adjval = adj[tgt][i];
                indeg[adjval]--;
                if (indeg[adjval] == 0)
                    q.push(adjval);
            }
        }
        if (ret.size() == numCourses)
            return true;
        return false;
    }
};