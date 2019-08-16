/* Given a m x n grid filled with non-negative numbers, find a path from top
   left to bottom right which minimizes the sum of all numbers along its path.
   Note: You can only move either down or right at any point in time.
   Example:

   Input:
    [
      [1,3,1],
      [1,5,1],
      [4,2,1]
    ]
   Output: 7
   Explanation: Because the path 1→3→1→1→1 minimizes the sum.

   LC 64. Minimum Path Sum
   Author: Shruti
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) {
            return 0; // empty grid
        }
        int n = grid[0].size();
        //vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i = 1; i < m; i++) {
            grid[i][0] += grid[i-1][0]; // update first row with cumulative path sum
        }
        for(int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j-1]; // update first col with cumulative path sum
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]); // update grid with min(left,top) + curr_val
            }
        }
        return grid[m-1][n-1]; // return min path sum
    }
};
