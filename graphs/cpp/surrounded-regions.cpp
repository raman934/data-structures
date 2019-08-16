/* Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
   surrounded by 'X'.
   A region is captured by flipping all 'O's into 'X's in that surrounded
   region.

   LC 130. Surrounded Regions
   Author: Shruti
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int nr = board.size();
        if(nr == 0) {
            return;
        }
        int nc = board[0].size();
        if(nr <= 2 || nc <= 2) {
            return;
        }
        for(int i = 0; i < nr; i++) {
            for(int j = 0; j < nc; j++) {
                if(i == 0 || j == 0 || i == nr-1 || j == nc-1) {
                    if(board[i][j] == 'O') {
                        dfs(i,j, board, nr, nc);  // identify connected components of 'O' on all the border

                    }
                }
            }
        }
        for(int i = 0; i < nr; i++) {
            for(int j = 0; j < nc; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '1') {
                    board[i][j] = 'O'; // revert all O's w/out surrounded regions
                }
            }
        }
    }
    void dfs(int i, int j, vector<vector<char>>& board, int nr, int nc) {
        if(i < 0 || j < 0 || i >= nr || j >= nc) {
            return;
        }
        if(board[i][j] == 'O') {
            board[i][j] = '1'; // mark the connected component vals to save them from change
            dfs(i-1, j, board, nr, nc);
            dfs(i+1, j, board, nr, nc);
            dfs(i, j-1, board, nr, nc);
            dfs(i, j+1, board, nr, nc);
        }
        return;
    }
};
