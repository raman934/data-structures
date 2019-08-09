/* Find the kth largest element in an unsorted array. Note that it is the kth
   largest element in the sorted order, not the kth distinct element.

   LC 215. Kth Largest Element in an Array
   Author: Shruti
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*priority_queue<int, vector<int>, greater<int>> min_heap; // use min-heap
        for(int num : nums) {
            min_heap.push(num);
            if(min_heap.size() > k) {
                min_heap.pop(); // pop the k smallest elements
            }
        }
        return min_heap.top(); // return the kth largest element*/

        priority_queue<int, vector<int>> max_heap(nums.begin(), nums.end()); // use max-heap
        for(int i = 0; i < k - 1; i++) {
            max_heap.pop(); // pop the K largest elements
        }
        return max_heap.top();
    }
};
