/* Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
   (representing land) connected 4-directionally (horizontal or vertical.) You
   may assume all four edges of the grid are surrounded by water.
   Count the number of distinct islands. An island is considered to be the same
   as another if and only if one island can be translated (and not rotated or
   reflected) to equal the other.

    Example 1:
    11000
    11000
    00011
    00011
    Given the above grid map, return 1.
    Example 2:
    11011
    10000
    00001
    11011
    Given the above grid map, return 3.

    Notice that:
    11
    1
    and
     1
    11
    are considered different island shapes, because we do not consider
    reflection / rotation.

   LC 694. Number of Distinct Islands
   Author: Shruti
*/

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        // for each gridpoint if equal to 1, island found
        // keep track of dfs path (string) used to get the complete island
        // unordered set of dfs paths used to keep track of distinct number of islands
        // string characters o,u,d,l,r used to keep track of directions
        int nr = grid.size();
        if(nr == 0) {
            return 0;
        }
        int nc = grid[0].size();
        unordered_set<string> distinct_islands;
        for(int i = 0; i < nr; i++) {
            for(int j = 0; j < nc; j++) {
                if(grid[i][j] == 1) {
                    string path;
                    dfs(i, j, nr, nc, grid, path, 'o'); // start from origin
                    cout << path << endl;
                    distinct_islands.insert(path); // push the path to the distinct island set
                }
            }
        }
        return distinct_islands.size();
    }

    void dfs(int i, int j, int nr, int nc, vector<vector<int>>& grid, string& path, char dir) {
        if(i < 0 || j < 0 || i >= nr || j >= nc) {
            return;
        }
        if(grid[i][j] == 1) {
            path.push_back(dir); // track path with direction, everytime island found
            grid[i][j] = 0;
            dfs(i+1, j, nr, nc, grid, path, 'd'); // visit down
            dfs(i-1, j, nr, nc, grid, path, 'u'); // visit up
            dfs(i, j-1, nr, nc, grid, path, 'l'); // visit left
            dfs(i, j+1, nr, nc, grid, path, 'r'); // visit right
            path.push_back('e'); // track when dfs ends for an island
        }
        return;
    }
};
