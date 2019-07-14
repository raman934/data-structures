/* Remove all elements from a linked list of integers that have value val.
   LC 203. Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) {
            return NULL;
        }
        while(head->val == val) {
            if(head->next) {
                head = head->next; // remove val at head
            } else {
                return NULL;
            }
        }
        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr) {
            if(curr->val == val && curr->next) {
                prev->next = curr->next;
                curr = curr->next;
            } else if(curr->val == val && !curr->next) { // remove at tail
                prev->next = NULL;
                return head;
            } else {
                curr = curr->next;
                prev = prev->next;
            }
        }
        return head;
    }
};
