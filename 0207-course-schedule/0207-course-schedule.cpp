class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        unordered_map<int, int> indeg;
        queue<int> q;
        
        for (auto it: prerequisites) {
            // 1 -> 0
            graph[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }
        
        int nodecnt = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();    
            nodecnt++;
            for (int i = 0; i < graph[cur].size(); i++) {
                int next = graph[cur][i];
                indeg[next]--;
                if (indeg[next] == 0)
                    q.push(next);
            }
        }
        if (nodecnt != numCourses)
            return false;
        return true;
    }
};