/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in
   the diagram below).
   The robot can only move either down or right at any point in time. The robot
   is trying to reach the bottom-right corner of the grid (marked 'Finish' in
   the diagram below).
   Now consider if some obstacles are added to the grids. How many unique paths
   would there be? An obstacle and empty space is marked as 1 and 0
   respectively in the grid.

   Input:
   [
    [0,0,0],
    [0,1,0],
    [0,0,0]
   ]
   Output: 2
   Explanation:
   There is one obstacle in the middle of the 3x3 grid above.
   There are two ways to reach the bottom-right corner:
   1. Right -> Right -> Down -> Down
   2. Down -> Down -> Right -> Right

   LC 63. Unique Paths II
   Author: Shruti
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(obstacleGrid.size() == 0) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        vector<vector<long>> path_vec(m, vector<long>(n,0)); // output vector
        // base cases
        if(obstacleGrid[0][0] == 1) {
            return 0; // start pos is blocked
        }
        if(obstacleGrid[m-1][n-1] == 1) {
            return 0; // end pos is blocked
        }
        if(obstacleGrid.size() == 1 and obstacleGrid[0][0] == 0) {
            return 1; // only one open pos in the geid
        }
        // update first row and col, as they can only be reached by one way if no blocks
        for(int i = 0; i < m; i++) {
            if(obstacleGrid[i][0] != 1) {
                path_vec[i][0] = 1; // update first row
            } else {
                break; // no way to go down if way blocked
            }
        }

        for(int j = 0; j < n; j++) {
            if(obstacleGrid[0][j] != 1) {
                path_vec[0][j] = 1; // update first col
            } else {
                break; // no way to go right if way blocked
            }
        }
        // update remaining entries in path_vec
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1){
                   continue;
                }
                path_vec[i][j] = path_vec[i-1][j] + path_vec[i][j-1];
            }
        }
        return path_vec[m-1][n-1];
    }
};
