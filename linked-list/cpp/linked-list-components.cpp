/* We are given head, the head node of a linked list containing unique integer
   values. We are also given the list G, a subset of the values in the linked
   list. Return the number of connected components in G, where two values are
   connected if they appear consecutively in the linked list.
   LC 817. Linked List Components
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
    int numComponents(ListNode* head, vector<int>& G) {
        if(!head || G.empty()) {
            return 0;
        }
        int components = 0;
        ListNode* curr = head->next;
        ListNode* prev = head;

        /* copy G in tempG as find is cheaper in unordered_set as compared to vector */
        unordered_set<int> tempG;
        for(int i = 0; i < G.size(); i++) {
            tempG.insert(G[i]);
        }
        while(curr && prev) {
            if(tempG.find(curr->val) == tempG.end() && tempG.find(prev->val) != tempG.end() ) {
                components++;
            }
            curr = curr->next;
            prev = prev->next;
        }
        if(tempG.find(prev->val) != tempG.end()  && !curr) {
            components++;
        }
        return components;
    }
};
