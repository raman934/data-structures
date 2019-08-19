/* Given an integer array of size n, find all elements that appear more than
   ⌊ n/3 ⌋ times. Note: The algorithm should run in linear time and in O(1)
   space.

    Example 1:

    Input: [3,2,3]
    Output: [3]
    Example 2:

    Input: [1,1,1,3,3,2,2,2]
    Output: [1,2]

   LC 229. Majority Element II
   Author: Shruti
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        // get the top two majority elements using boyer-moore voting algorithm
        int count1 = 0, count2 = 0, maj_elem1 = 0, maj_elem2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(maj_elem1 == nums[i]) {
                count1 += 1;
            } else if(maj_elem2 == nums[i]) {
                count2 += 1;
            } else if(count1 == 0) {
                maj_elem1 = nums[i];
                count1 = 1;
            } else if(count2 == 0) {
                maj_elem2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        // find the counts of the top two majority elements, if > n/3 add to result
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == maj_elem1) {
                count1++;
            } else if(nums[i] == maj_elem2) {
                count2++;
            }
        }
        if(count1 > (nums.size())/3) {
            result.push_back(maj_elem1);
        }
        if(count2 > (nums.size())/3) {
            result.push_back(maj_elem2);
        }
        return result;
    }
};
