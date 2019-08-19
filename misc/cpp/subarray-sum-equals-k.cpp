/* Given an array of integers and an integer k, you need to find the total
   number of continuous subarrays whose sum equals to k.

    Example 1:
    Input:nums = [1,1,1], k = 2
    Output: 2

   LC 560. Subarray Sum Equals K
   Author: Shruti
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0; // sum upto the ith element accessed
        int result = 0; // final result
        unordered_map<int,int> sum_map; // stores the sum and its count
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum == k) {
                result++; //first result found
            }
            if(sum_map.find(sum-k) != sum_map.end()) { // looking for remainder at each nums index, if the remainder encountered previously, increment result by the count found
                result += sum_map[sum-k];
            }
            sum_map[sum] += 1; // increment the count for the current sum
        }
        return result;
    }
};
