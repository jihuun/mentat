class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        unordered_map<int, int> indeg;
        vector<int> ret;
        
        for (auto it: prerequisites) {
            graph[it[1]].push_back(it[0]);
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
            for (int i = 0; i < graph[tgt].size(); i++) {
                int adj = graph[tgt][i];
                indeg[adj]--;
                if (indeg[adj] == 0)
                    q.push(adj);
            }
        }
        if (ret.size() == numCourses)
            return ret;
        return {};
    }
};