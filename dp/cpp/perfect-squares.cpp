/* Given a positive integer n, find the least number of perfect square numbers
   (for example, 1, 4, 9, 16, ...) which sum to n.

    Example 1:

    Input: n = 12
    Output: 3 
    Explanation: 12 = 4 + 4 + 4.
    Example 2:

    Input: n = 13
    Output: 2
    Explanation: 13 = 4 + 9.

   LC 279. Perfect Squares
   Author: Shruti
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX); // stores least number of perfect suares for every index
        // for each integer i in (1,n)
        // for each integer j s.t. (1, j*j <= i)
        // dp[i] = min(dp[i], dp[i-j*j] + 1);
        // dp[0] = 0
        // i = 1, j = 1: dp[1] = min(dp[1], dp[0] + 1) = 1
        // i = 2, j = 1: dp[2] = min(dp[2], dp[1] + 1) = 2
        // i = 3, j = 1: dp[3] = min(dp[3], dp[2] + 1) = 3 // the least num of perfect squares for 2 is 2.
        // i = 4, j = 1: dp[4] = min(dp[4], dp[3] + 1) = 4 // the least num of perfect squares for 3 is 3.
        // i = 4, j = 2: dp[4] = min(dp[4], dp[0] + 1) = 1 // the least num of perfect squares for 4 is 1.
        // i = 5, j = 1: dp[5] = min(dp[5], dp[4] + 1) = 2 // the least num of perfect squares for 5 is 2.
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j*j <= i; j++) {
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp[n];
    }
};
