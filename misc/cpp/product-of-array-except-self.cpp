/* Given an array nums of n integers where n > 1,  return an array output such
   that output[i] is equal to the product of all the elements of nums except
   nums[i].

    Example:

    Input:  [1,2,3,4]
    Output: [24,12,8,6]
    Note: Please solve it without division and in O(n).

    Follow up:
    Could you solve it with constant space complexity? (The output array does
    not count as extra space for the purpose of space complexity analysis.)

   LC 238. Product of Array Except Self
   Author: Shruti
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int temp_right = 1;
        // calculate product of left except self
        for(int i = 0; i < nums.size(); i++) {
            if(result.empty()) {
                result.push_back(1); // product of left for leftmost element will be 1, as nothing on left
            } else {
                result.push_back(nums[i-1]*result[i-1]);
            }
        }

        // calculate product of array except self
        for(int i = nums.size() - 2; i >= 0; i--) {
            temp_right *= nums[i+1];
            result[i] *= temp_right;
        }
        return result;
    }
};
