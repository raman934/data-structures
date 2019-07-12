/* Remove nth node from end of linked list given head
   LC 19. Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* when list is empty or has a single node that is to be removed */
        if(!head || (!head->next && n == 1)) {
            return NULL;
        }
        /* use two pointers p1 and p2
           iterate p1 n steps
           iterate p1 and p2 together until p1 reaches end of list
           p2 has now iterated length - n steps i.e. nth from last
           */
        ListNode* p1 = head;
        ListNode* p2 = head;
        int temp = n;
        while(temp) {
            p1 = p1->next;
            temp--;
        }
        /* if n is equal to list length, p1 iterating n steps => p1 is NULL
           thus remove the first element in the list if !p1
           */
        if(!p1) {
            head = p2->next;
        }
        while(p1) {
            cout << p1->val << endl;
            p1 = p1->next;
            if(!p1 && p2->next) {
                p2->next = p2->next->next;
            } else {
                p2 = p2->next;
            }
        }
        return head;
    }
};
