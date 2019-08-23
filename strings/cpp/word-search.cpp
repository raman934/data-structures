/* Given a 2D board and a word, find if the word exists in the grid. The word
   can be constructed from letters of sequentially adjacent cell, where
   "adjacent" cells are those horizontally or vertically neighboring. The same
   letter cell may not be used more than once.

    Example:

    board =
    [
      ['A','B','C','E'],
      ['S','F','C','S'],
      ['A','D','E','E']
    ]

    Given word = "ABCCED", return true.
    Given word = "SEE", return true.
    Given word = "ABCB", return false.

   LC 79. Word Search
   Author: Shruti
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // use dfs for word search
        // create a bool vector of vector of the size of board
        // true => word character found, else false
        int nr = board.size();
        int nc = board[0].size();
        vector<vector<bool>> v(nr, vector<bool>(nc, false));
        int count = 0; // index of the word being searched
        for(int i = 0; i < nr; i++) {
            for(int j = 0; j < nc; j++) {
                if(board[i][j] == word[count]) {
                    // character matched
                    v[i][j] = true; // mark true for that i,j index in v
                    if(dfs(board, v, nr, nc, i, j, count + 1, word)) {
                        return true;
                    }
                    v[i][j] = false;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& v, int nr, int nc, int i, int j, int count, string word) {
        vector<vector<int>> neighbors = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        if(count == word.size()) {
            return true;
        }
        // find indices of neighbors
        for(auto neigh : neighbors) {
            int r = neigh[0] + i;
            int c = neigh[1] + j;
            if(r < 0 || c < 0 || r >= nr || c >= nc || v[r][c]) {
                continue; // base case, illegal neighbor or already visited neighbor
            }
            // if neighbor has next word char
            if(board[r][c] == word[count]) {
                v[r][c] = true;
                if(dfs(board, v, nr, nc, r, c, count + 1, word)) {
                    return true;
                }
                v[r][c] = false;
            }
        }
        return false;
    }
};
