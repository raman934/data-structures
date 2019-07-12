/* Reverse a linked list from position m to n. Do it in one-pass.
   LC 92. Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || !m || !n || m == n) {
            return head;
        }
        ListNode* curr = head;
        ListNode* nxt = head;
        ListNode* prev = NULL;
        ListNode* mprev = NULL; // pointer to prev to m pos in list
        ListNode* nnxt = NULL; // pointer to nxt to n pos in list
        ListNode* mhead = head; // pointer to head pos in reversed list
        int mcount = m;
        /* position pointers to m pos in list */
        while(mcount) {
            curr = curr->next;
            nxt = curr;
            if(curr == head->next) {
                prev = head;
            } else {
                prev = prev->next;
            }
            mcount--;
            if(mcount == 1) {
                mprev = prev; // save m-1 pos node in list for later
                mhead = curr; // save m pos node in list for later
            }
        }
        /* reverse list from m to n */
        int diff = n - m;
        while(diff) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            diff--;
        }
        /* update mprev, mhead node pointers */
        nnxt = nxt;
        if(mprev && nnxt) { // reversed list lies in the middle
            mprev->next = prev;
            mhead->next = nnxt;
            return head;
        } else if (!mprev && nnxt) { // reversed list lies at the left
            mhead->next = nnxt;
            return prev;
        } else if (mprev && !nnxt) { // reversed list lies at the right
            mprev->next = prev;
            mhead->next = NULL;
            return head;
        } else {
            mhead->next = NULL;
            return prev; // reverse the entire list
        }
    }
};
