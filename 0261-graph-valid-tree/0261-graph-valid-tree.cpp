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
    
    bool validTree(int n, vector<vector<int>>& edges) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (auto it: edges) {
            int root1 = find(it[0]);
            int root2 = find(it[1]);
            if (root1 == root2) /* for loop detection */
                return false;
            do_union(it[0], it[1]);
        }
        /* for multi group */
        int prev = find(0);
        for (int i = 1; i < n; i++) {
            int root = find(i);
            if (prev != root)
                return false;
            prev = root; 
        }
        
        return true;
    }
};