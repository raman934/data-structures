/* LC 1019. Next Greater Node In Linked List

   Author: Shruti
*/

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> curr_vector;
        /* copy list to curr_vector */
        while(head) {
            curr_vector.push_back(head->val);
            head = head->next;
        }

        int vec_len = curr_vector.size();
        vector<int> result(vec_len,0);  //initialize the result vector with zeros
        stack<int> prev_index; // stack to track index of previous nodes that must be updated

        for(int i = 0; i < vec_len; ++i) {
            while(!prev_index.empty() && curr_vector[i] > curr_vector[prev_index.top()]) {
                result[prev_index.top()] = curr_vector[i];
                prev_index.pop();
            }
            prev_index.push(i);
        }
        return result;
    }
};
