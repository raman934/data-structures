/* Given a 2d grid map of '1's (land) and '0's (water), count the number of
   islands. An island is surrounded by water and is formed by connecting
   adjacent lands horizontally or vertically. You may assume all four edges of
   the grid are all surrounded by water.

   Example 1:

   Input:
   11110
   11010
   11000
   00000

   Output: 1
   Example 2:

   Input:
   11000
   11000
   00100
   00011

   Output: 3

   LC 200. Number of Islands
   Author: Shruti
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if(nr == 0) {return 0;}
        int nc = grid[0].size();
        int islands = 0;
        for(int i = 0; i < nr; i++) {
            for(int j = 0; j < nc; j++) {
                if(grid[i][j] == '1') { // land found
                    islands++;
                    dfs(i, j, grid, nr, nc); // find all neighboring land
                }
            }
        }
        return islands;
    }

    // visit the univisited node
    void dfs(int i, int j, vector<vector<char>>& grid, int nr, int nc) {
        if(i < 0 || j < 0 || i >= nr || j >= nc) {
            return; // base condition
        }
        if(grid[i][j] == '1') {
            grid[i][j] = '0'; // set the node to 0, so that it is not visited again
            // check all neighbors
            dfs(i-1, j, grid, nr, nc);
            dfs(i+1, j, grid, nr, nc);
            dfs(i, j-1, grid, nr, nc);
            dfs(i, j+1, grid, nr, nc);
        }
        return;
    }
};
