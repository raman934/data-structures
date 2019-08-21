/* Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
   appear twice and others appear once.

    Find all the elements that appear twice in this array.

    Could you do it without extra space and in O(n) runtime?

    Example:
    Input:
    [4,3,2,7,8,2,3,1]

    Output:
    [2,3]

   LC 442. Find All Duplicates in an Array
   Author: Shruti
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        // O(1) space solution
        // for every visited num in nums, mark num visited by -1*nums[num]
        // we utilize the fact that all num in nums vary from [1,nums.size()] in value
        // as we check every number, if its value is negative, it has been visited
        // push the number in result
        for(int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0) { // nums[i] visited
                result.push_back(idx + 1);
            }
            nums[idx] = -nums[idx]; // make the nuumber negative
        }
        return result;
    }
};
