/* Sort a linked list using insertion sort.
   LC 147. Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head; // dummy node to anchor head
        ListNode* curr = head;
        ListNode* prev = dummy;
        while(curr) {
            // find correct position for curr->next
            if(curr->next && curr->next->val < curr->val) {
                // increment prev to find the node with value smaller than curr->next
                while(prev->next && prev->next->val < curr->next->val) {
                    prev = prev->next;
                }
                ListNode* temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
                prev = dummy;
            } else {
                curr = curr->next; // no node pos to update, increment curr
            }
        }
        return dummy->next;
    }
};
