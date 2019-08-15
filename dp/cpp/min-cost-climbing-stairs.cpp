/* On a staircase, the i-th step has some non-negative cost cost[i] assigned
   (0 indexed).
   Once you pay the cost, you can either climb one or two steps. You need to
   find minimum cost to reach the top of the floor, and you can either start
   from the step with index 0, or the step with index 1.

   LC 746. Min Cost Climbing Stairs
   Author: Shruti
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <= 1) {
            return cost.size();
        }
        vector<int> min_cost(cost.size(), 0);
        min_cost[0] = cost[0]; // base case 1
        min_cost[1] = cost[1]; // base case 2
        for(int i=2; i < cost.size(); i++) {
            min_cost[i] = min(min_cost[i-1], min_cost[i-2]) + cost[i]; // cost to reach every step
        }
        return min(min_cost[cost.size()-1], min_cost[cost.size()-2]); // return the min of the last two cumulative step cost
    }
};
