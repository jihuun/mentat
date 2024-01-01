class Solution {
public:
    vector<int> parent;
    int find(int n) {
        if (parent[n] == n)
            return n;
        return find(parent[n]);
    }
    void do_union(int a, int b) {
        int roota = find(a);
        int rootb = find(b);
        parent[roota] = rootb;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent = vector<int>(n);
        int comp = 0;
        unordered_map<int, int> freq;
        
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (auto it: edges)
            do_union(it[0], it[1]);
        
        int root = 0;
        for (int i = 0; i < n; i++) {
            root = find(i);
            if (freq.find(root) == freq.end()) {
                comp++;
                freq[root] = 1;
            }
        }
        return comp;
    }
};