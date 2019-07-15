/* Given a linked list, swap every two adjacent nodes and return its head. You
   may not modify the values in the list's nodes, only nodes itself may be
   changed.
   LC 24. Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* curr = head->next;
        ListNode* nxt = head->next;
        ListNode* prev = head;
        ListNode* pre_prev = NULL;
        while(curr && nxt) {
            nxt = curr->next;
            curr->next = prev;
            prev->next = nxt;
            if(pre_prev) {
                pre_prev->next = curr;
            } else {
                head = curr;
            }
            if(!nxt) {
                break;
            }
            pre_prev = prev;
            curr = nxt->next;
            prev = nxt;
        }
        return head;
    }
};
