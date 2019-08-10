/* Given a non-empty array of integers, return the k most frequent elements.

   LC 347. Top K Frequent Elements
   Author: Shruti
*/

class Solution {
    vector<int> result;
    typedef pair<int,int> p;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // store frequency of each element in a map
        unordered_map<int,int> freq_map;
        for(auto i : nums) {
            freq_map[i]++; // update the freq of element i in freq_map[nums[i]]
        }
        priority_queue<p, vector<p>, greater<p>> min_heap;
        for(auto m : freq_map) {
            min_heap.push(make_pair(m.second, m.first)); // create min_heap, ordered by frequency
            if(min_heap.size() > k) {
                min_heap.pop();
            }
        }
        while(k--) {
            result.push_back(min_heap.top().second); // get the element value from the top
            min_heap.pop();
        }
        return result;
    }
};
