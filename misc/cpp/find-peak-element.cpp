/* A peak element is an element that is greater than its neighbors. Given an
   input array nums, where nums[i] ≠ nums[i+1], find a peak element and return
   its index.

   The array may contain multiple peaks, in that case return the index to any
   one of the peaks is fine. You may imagine that nums[-1] = nums[n] = -∞.

    Example 1:

    Input: nums = [1,2,3,1]
    Output: 2
    Explanation: 3 is a peak element and your function should return the index number 2.
    Example 2:

    Input: nums = [1,2,1,3,5,6,4]
    Output: 1 or 5
    Explanation: Your function can return either index number 1 where the peak element is 2,
                 or index number 5 where the peak element is 6.
    Note:

    Your solution should be in logarithmic complexity.
    
   LC 162. Find Peak Element
   Author: Shruti
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // use binary search for logarithmic complexity
        int left = 0;
        int right = nums.size() - 1;
        // if there are atleast three elements in the vector
        while(left + 1 < right) {
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid; // mid is the peak
            }
            // find peak in right sub vector
            if(nums[mid + 1] > nums[mid]) {
                left = mid+1;
            } else { // find peak in left sub vector
                right = mid;
            }
        }
        // two elements in the array
        if(nums[right] > nums[left]) {
            return right;
        }
        return left;
    }
};
