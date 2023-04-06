class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        unordered_map<int, int> indeg;
        vector<int> ret;
        queue<int> q;
        
        if (n == 1)
            return {0};
        for (auto it: edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
            indeg[it[0]]++;
            indeg[it[1]]++;
        }
        for (int i = 0; i < n; i++)
            if (indeg[i] == 1)
                q.push(i);   
        
        while (!q.empty()) {
            ret.clear();
            int nr_leaf = q.size();
            while (nr_leaf--) {
                int node = q.front();
                q.pop();
                ret.push_back(node);
                for (int i = 0; i < graph[node].size(); i++) {
                    int adj = graph[node][i];
                    if (--indeg[adj] == 1)
                        q.push(adj);
                }
            }
        }
        return ret;        
    }
};