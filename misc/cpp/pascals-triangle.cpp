/* Given a non-negative integer numRows, generate the first numRows of Pascal's
   triangle.

    Example:

    Input: 5
    Output:
    [
        [1],
       [1,1],
      [1,2,1],
     [1,3,3,1],
    [1,4,6,4,1]
    ]

   LC 118. Pascal's Triangle
   Author: Shruti
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>> result;
        if(numRows == 0) {
            return result;
        }
        for(int i = 0; i < numRows; i++) {
            result.push_back(vector<int>(i+1, 1));// for each row, put all elements as 1
            // the number of inner elements to be inserted for each row is curr row_size - 1
            for(int j = 1; j <= i - 1; j++) {
               result[i][j] = result[i-1][j-1] + result[i-1][j]; // result is sum of values in previous row, at the current row's index and previous index
            }
        }
        return result;
    }
};
