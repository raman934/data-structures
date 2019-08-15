/* You are climbing a stair case. It takes n steps to reach to the top.
   Each time you can either climb 1 or 2 steps. In how many distinct ways
   can you climb to the top?

   LC 70. Climbing Stairs
   Author: Shruti
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) {
            return 1; // only one way to reach one step
        }
        vector<int> dp(n + 1, 0); // storage vector for dp
        dp[1] = 1; // base case 1
        dp[2] = 2; // base case 2
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];// ith step can be reached by adding ways to reach i-1th step and i-2th step
        }
        return dp[n]; // return the value of ways to reach the last step
    }
};
