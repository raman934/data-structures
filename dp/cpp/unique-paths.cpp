/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in
   the diagram below).
   The robot can only move either down or right at any point in time. The robot
   is trying to reach the bottom-right corner of the grid (marked 'Finish' in
   the diagram below).
   How many possible unique paths are there?

   LC 62. Unique Paths
   Author: Shruti
*/

class Solution {
public:
    /* o(mn) time and space
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,1)); // stores number of ways to reach a grid point i,j at index [i][j], initialize first row and col to 1 as there is only one way to reach those
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }*/

    // o(n) time and space
    int uniquePaths(int m, int n) {
        vector<int> prev(n,1); // store prev row, initialize first row and col to 1 as there is only one way to reach those
        vector<int> curr(n,1); // store curr row
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                curr[j] = curr[j-1] + prev[j]; // every jth value is sum of its left and top value
            }
            swap(prev,curr); //curr holds the last calculated row, prev is overwritten with every i after the swap as it becomes curr
        }
        return prev[n-1]; // prev is curr after swap, hence has the last calculate value
    }
};
