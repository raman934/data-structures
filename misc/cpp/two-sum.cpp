/* Given an array of integers, return indices of the two numbers such that they
   add up to a specific target. You may assume that each input would have
   exactly one solution, and you may not use the same element twice.

    Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].

   LC 1. Two Sum
   Author: Shruti
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> m; // stores num seen along with its index
        for(int i = 0; i < nums.size(); i++) {
            m.insert({nums[i], i}); // insert the num seen along with the index it was seen at
            // for that num, find its complement in the map
            // verify that the complement is not itself by checking the index
            // if the complement exists, store its index, along with num's index in result
            auto itr = m.find(target - nums[i]);
            if(itr != m.end() && i != itr->second) {
                result = {i, itr->second};
            }
        }
        return result;
    }
};
