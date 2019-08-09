/* We have a list of points on the plane.  Find the K closest points to the
   origin (0, 0).
   (Here, the distance between two points on a plane is the Euclidean distance.)
   You may return the answer in any order.  The answer is guaranteed to be
   unique (except for the order that it is in.)

   LC 973. K Closest Points to Origin
   Author: Shruti
*/

class Solution {
    vector<vector<int>> result;
    struct compare {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            // return true if a^2 > b^2
            // if true, b is on top, else a is on top
            return pow(a[0],2) + pow(a[1],2) > pow(b[0],2) + pow(b[1],2);
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, compare> min_heap(points.begin(), points.end());
        for(int i = 0; i < K; i++) {
            result.push_back(min_heap.top());
            min_heap.pop();
        }
        return result;
    }
};
