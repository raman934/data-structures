/* Given an array of size n, find the majority element. The majority element is
   the element that appears more than ⌊ n/2 ⌋ times.
   You may assume that the array is non-empty and the majority element always
   exist in the array.

    Example 1:

    Input: [3,2,3]
    Output: 3
    Example 2:

    Input: [2,2,1,1,1,2,2]
    Output: 2

   LC 169. Majority Element
   Author: Shruti
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // use boyer moore's voting algorithm to find the majority element
        int maj_index = 0; // index of the majority element
        int maj_elem = nums[0];
        int count = 1; // count of the majority element relative to the last different element
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == maj_elem) {
                count++;
            } else {
                count--;
            }
            // the curr maj_elem is no longer a majority
            if(count == 0) {
                maj_elem = nums[i]; // make curr element the maj element
                count = 1;
                maj_index = i;
            }
        }
        return maj_elem;
    }
};
