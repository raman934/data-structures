/* Given an array nums, write a function to move all 0's to the end of it while
   maintaining the relative order of the non-zero elements.

    Example:

    Input: [0,1,0,3,12]
    Output: [1,3,12,0,0]
    Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.

   LC 283. Move Zeroes
   Author: Shruti
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int shift = 0; // the maximum positions a digit might have to shift is dependent on the number of zeros in front
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                shift++;
            } else {
                nums[i - shift] = nums[i]; // shift number
            }
        }
        for(int i = nums.size() - shift; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
