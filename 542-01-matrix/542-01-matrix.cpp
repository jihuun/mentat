/*
1. constraints
- 0, 1
- not squre
- at least one 0

2. Idea
- brute-force search mat from 0 to n -> O(N^2) (N=m*n)
- using Queue -> O(N) / O(N)
- possible O(N) / O(1)?

3. Test cases
000 adjacent 0
010
000

010 share inc target 
111 
111 

0110 check simultaniasly
1111
1111
1110
*/

class Solution {
    std::queue<pair<int, int>> q;
    int rsize;
    int csize;
    vector<vector<int>> visit;
    
    void inc_count_push(vector<vector<int>> &mat, int r, int c) {
        int pos_val = mat[r][c];
        
        // check 4 direction 
        // each val is 1 -> increase by pos_val + 1
        // then push it
        if (r-1 >= 0 && visit[r-1][c] == 0 && mat[r-1][c] == 1) {
            mat[r-1][c] = pos_val + 1;
            q.push(make_pair(r-1, c));
            visit[r-1][c] = 1;
        }
        if (r+1 < rsize && visit[r+1][c] == 0 && mat[r+1][c] == 1) {
            mat[r+1][c] = pos_val + 1;
            q.push(make_pair(r+1, c));
            visit[r+1][c] = 1;
        }
        if (c-1 >= 0 && visit[r][c-1] == 0 && mat[r][c-1] == 1) {
            mat[r][c-1] = pos_val + 1;
            q.push(make_pair(r, c-1));
            visit[r][c-1] = 1;
        }
        if (c+1 < csize && visit[r][c+1] == 0 && mat[r][c+1] == 1) {
            mat[r][c+1] = pos_val + 1;
            q.push(make_pair(r, c+1));
            visit[r][c+1] = 1;
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        rsize = mat.size();
        csize = mat[0].size();
        //vector<vector<int>> visit(rsize, vector<int> (csize, 0)); 
        visit = vector<vector<int>> (rsize, vector<int> (csize, 0));
        
        for (int i = 0; i < rsize; i++) {
            for (int j = 0; j < csize; j++) {
                if (mat[i][j] == 0)
                    q.push(make_pair(i, j));
            }
        }
        while (!q.empty()) {
            pair<int, int> pos = q.front();
            q.pop();
            inc_count_push(mat, pos.first, pos.second);
        }
        return mat;
    }
};