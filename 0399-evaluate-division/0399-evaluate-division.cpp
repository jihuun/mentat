class Solution {
    unordered_map<string, vector<pair<string, double>>> graph;
    vector<double> ret;
    
    void eval_div(unordered_map<string, bool> &vis, string from, string tgt, int tgt_idx, double ratio) {
        if (vis.find(from) != vis.end())
            return;
        if (from == tgt) {
            ret[tgt_idx] = ratio;
            return;
        }
        vis[from] = true;
        for (int i = 0; i < graph[from].size(); i++) {
            eval_div(vis, graph[from][i].first, tgt, tgt_idx, ratio * graph[from][i].second);
        }
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        ret = vector<double>(queries.size(), 0);
        for (int i = 0; i < equations.size(); i++) {
            // "a"->"b" means "a"/"b"
            // adjacent list of "a" is a pair(b, a/b)
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            // opposite direction: b->a
            graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        for (int i = 0; i < queries.size(); i++) {
            unordered_map<string, bool> visited;
            if (graph.find(queries[i][0]) == graph.end() || graph.find(queries[i][1]) == graph.end()) {
                ret[i] = (double)-1;
                continue;
            }
            eval_div(visited, queries[i][0], queries[i][1], i, 1);
            if (ret[i] == 0) {
                ret[i] = (double)-1;
            }
        }
        return ret;        
    }
};

/*
[["a","b"],["b","c"]]
[2.0,3.0]
[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
[["a","b"],["b","c"],["bc","cd"]]
[1.5,2.5,5.0]
[["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
[["a","b"]]
[0.5]
[["a","b"],["b","a"],["a","c"],["x","y"]]

[["a","b"],["c","d"]]
[1.0,1.0]
[["a","c"],["b","d"],["b","a"],["d","c"]]
[["a","b"],["b","c"],["a","c"]]
[2.0,3.0,6.0]
[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]

*/