/* Given a non-negative index k where k ≤ 33, return the kth index row of the
   Pascal's triangle.
   Note that the row index starts from 0.
    Example:

    Input: 3
    Output: [1,3,3,1]
    Follow up:

    Could you optimize your algorithm to use only O(k) extra space?

   LC 119. Pascal's Triangle II
   Author: Shruti
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1); // create a vector of size rowIndex + 1 with all zeros
        for (int i=0;i<=rowIndex;i++) {
            v[0] = 1; // first index will always be zero
            for (int j=i;j>0;j--) {
              v[j] = v[j] + v[j-1]; // for j = i, set ith value to 1, starting at i-1, update the middle values
            }
      }
      return v;
    }
};
