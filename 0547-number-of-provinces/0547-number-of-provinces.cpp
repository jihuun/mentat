class Solution {
    vector<int> visit; // node already visited
    void mark_connection(vector<vector<int>>& graph, int from) {
        for (int i = 0; i < graph[from].size(); i++) {
            if (graph[from][i] == 0 || visit[i] == 1)
                continue;
            visit[i] = 1;
            mark_connection(graph, i);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int rsize = isConnected.size();
        visit = vector<int>(rsize, 0);
        int nr_province = 0;
        
        for (int i = 0; i < rsize; i++) {
            if (visit[i] == 1)
                continue;
            mark_connection(isConnected, i);
            nr_province++;
        }
        return nr_province;
    }
};