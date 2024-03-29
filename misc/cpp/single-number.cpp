/* Given a non-empty array of integers, every element appears twice except for
   one. Find that single one.

    Note: Your algorithm should have a linear runtime complexity. Could you
    implement it without using extra memory?

    Example 1:

    Input: [2,2,1]
    Output: 1
    Example 2:

    Input: [4,1,2,1,2]
    Output: 4

   LC 136. Single Number
   Author: Shruti
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0]; // result
        for(int i = 1; i < nums.size(); i++) {
            result = result ^ nums[i]; // XORing of two same numbers will be 0, and 0 XOR y = y
        }
        return result;
    }
};
