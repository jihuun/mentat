class Solution {
public:
    /*
[1,0] [2,0] [3,1] [3,2] 로 주어질때

이를 그래프 자료구조로 표현하면
[0] -> 1 -> 2
[1] -> 3
[2] -> 3

진입차수(indegree)를 표현하면
[0] 0
[1] 1
[2] 1
[3] 2
    */
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        unordered_map<int, int> indeg;
        vector<int> ret;
        queue<int> q;
        
        for (auto it: prerequisites) {
            graph[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }
        
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            ret.push_back(n);
            for (int i = 0; i < graph[n].size(); i++) {
                indeg[graph[n][i]]--;
                if (indeg[graph[n][i]] == 0)
                    q.push(graph[n][i]);
            }
        }
        if (ret.size() == numCourses)    
            return ret;
        return {};
    }
};