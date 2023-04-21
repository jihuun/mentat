class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indeg(n);
        vector<int> ret;
        if (n <= 1)
            return {0};
        for (auto it: edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
            indeg[it[0]]++;
            indeg[it[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 1)
                q.push(i);
        }
        
        while (!q.empty()) {
            int qsize = q.size();
            ret.clear();
            
            while (qsize--) {
                int node = q.front();
                q.pop();
                ret.push_back(node);
                for (int i = 0; i < graph[node].size(); i++) {
                    int adj = graph[node][i];
                    indeg[adj]--;
                    if (indeg[adj] == 1)
                        q.push(adj);
                }
            }
            
        } 
        return ret;
    }
};