/* Given n non-negative integers representing an elevation map where the width
   of each bar is 1, compute how much water it is able to trap after raining.

    Example:

    Input: [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6

   LC 42. Trapping Rain Water
   Author: Shruti
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if(!height.size()) {
            return 0;
        }
        // create a vector of size height with max value known at the index from left to right
        // create a vector of size height with max value known at the index from right to left
        // at every index calculate the min of the heights of left and right
        // subtracting the current height for the index from the min of left_max and right_max
        // gives the water trapped at that index
        vector<int> left_max(height.size());
        vector<int> right_max(height.size());
        int result = 0;
        left_max[0] = height[0];
        for(int i = 1; i < height.size(); i++) {
            left_max[i] = max(left_max[i-1],height[i]);
        }
        right_max[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i+1],height[i]);
        }
        for(int i = 0; i < height.size(); i++) {
            result += min(left_max[i], right_max[i]) - height[i];
        }
        return result;
    }
};
