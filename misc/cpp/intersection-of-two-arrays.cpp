/* Given two arrays, write a function to compute their intersection.

    Example 1:

    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2]
    Example 2:

    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [9,4]

   LC 349. Intersection of Two Arrays
   Author: Shruti
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> out;
        unordered_set<int> result;
        unordered_map<int,int> map;
        if(nums1.size() > nums2.size()) {
                for(int num1 : nums1) {
                map[num1]++; // store the count of each element of nums1 in map
            }
            for(int num2: nums2) {
                if(map[num2]) { // if the count of any element in nums2 already exists in the map, intersection found
                    result.insert(num2);
                }
            }
        } else {
            for(int num2 : nums2) {
                map[num2]++;
            }
            for(int num1: nums1) {
                if(map[num1]) {
                    result.insert(num1);
                }
            }
        }
        out.assign(result.begin(), result.end());
        return out;
    }
};
