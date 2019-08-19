/* Given n non-negative integers a1, a2, ..., an , where each represents a point
   at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
   of line i is at (i, ai) and (i, 0). Find two lines, which together with
   x-axis forms a container, such that the container contains the most water.

    Example:

    Input: [1,8,6,2,5,4,8,3,7]
    Output: 49

   LC 11. Container With Most Water
   Author: Shruti
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int start = 0;
        int end = height.size() - 1;
        return getMaxArea(height, start, end, max_area);
    }

    int getMaxArea(vector<int>& height, int& start, int& end, int& max_area) {
        if(start > end) {
            return max_area;
        }
        max_area = max(max_area, (end - start)*min(height[start], height[end]));
        if(height[start] < height[end]) {
            start++;
        } else {
            end--;
        }
        getMaxArea(height, start, end, max_area);
        return max_area;
    }
};
