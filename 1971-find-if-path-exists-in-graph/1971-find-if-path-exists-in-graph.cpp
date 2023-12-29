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
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        parent = vector<int>(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (auto it: edges)
            do_union(it[0], it[1]);
        return find(src) == find(dst);
    }
};