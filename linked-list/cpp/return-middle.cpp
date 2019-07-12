/* Return middle of linked list given head
   LC 876. Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        /* use fast and slow pointers
           when fast reaches end of the list
           slow is at middle
        */
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(!fast || !fast->next) {
                break;
            }
        }
        return slow;
    }
};
