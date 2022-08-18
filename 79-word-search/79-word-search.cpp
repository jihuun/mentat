class Solution {
    string w;
    int rsize;
    int csize;
    int **visit;
    
    bool check_str(vector<vector<char>>& board, int i, int j, int widx, int size)
    {
        /* base case */
        if (i < 0 || i >= rsize || j < 0 || j >= csize)
            return false;
        if (size < 0)
            return false;
        if (visit[i][j])
            return false;
        if (w[widx] != board[i][j])
            return false;

        if (size == 0)
            return true;
        
        /* visited */
        visit[i][j] = 1;

        /* recursion */
        if (check_str(board, i + 1, j, widx + 1, size - 1))
            return true;
        if (check_str(board, i, j + 1, widx + 1, size - 1))
            return true;
        if (check_str(board, i - 1, j, widx + 1, size - 1))
            return true;
        if (check_str(board, i, j - 1, widx + 1, size - 1))
            return true;
        
        visit[i][j] = 0;
        
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        w = word;
        rsize = board.size();
        csize = board[0].size();
        visit = new int *[rsize]{0};
        for (int i = 0; i < rsize; i++)
            visit[i] = new int[csize]{0};
        
        
        for (int i = 0; i < rsize; i++) {
            for (int j = 0; j < csize; j++) {
                if (board[i][j] != word[0])
                    continue;
                if (check_str(board, i, j, 0, word.size() - 1))
                    return true;
            }
        }
        return false;
    }
};