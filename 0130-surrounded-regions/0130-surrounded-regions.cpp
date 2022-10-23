class Solution {
    int rsize;
    int csize;

    void flip_by(vector<vector<char>>& board, int r, int c, char tgt, char to) {
        if (r < 0 || r >= rsize || c < 0 || c >= csize)
            return;
        if (board[r][c] == to || board[r][c] == 'X') {
            return;
        }
        board[r][c] = to;
        flip_by(board, r + 1, c, tgt, to);
        flip_by(board, r - 1, c, tgt, to);
        flip_by(board, r, c + 1, tgt, to);
        flip_by(board, r, c - 1, tgt, to);
    }
public:
    void solve(vector<vector<char>>& board) {
        rsize = board.size();
        csize = board[0].size();
        
        /* mark boader's 'O' to 'E' */
        /* check col 0 and last boarer */
        for (int i = 0; i < rsize; i++) {
            if (board[i][0] == 'O')
                flip_by(board, i, 0, 'O', 'E');
            if (board[i][csize - 1] == 'O')
                flip_by(board, i, csize - 1, 'O','E');
        }
        /* check row 0 and last boarer */
        for (int i = 0; i < csize; i++) {
            if (board[0][i] == 'O')
                flip_by(board, 0, i, 'O', 'E');
            if (board[rsize - 1][i] == 'O')
                flip_by(board, rsize - 1, i, 'O','E');
        }
        /* convert O to X */
        for (int i = 0; i < rsize; i++) {
            for (int j = 0; j < csize; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        /* convert E to O */
        for (int i = 0; i < rsize; i++) {
            for (int j = 0; j < csize; j++) {
                if (board[i][j] == 'E')
                    board[i][j] = 'O';
            }
        }
    }
};