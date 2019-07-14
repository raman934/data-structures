/* Given a linked list, determine if it has a cycle in it.
   LC 141. Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow) {
            if(slow->next && fast->next && fast->next->next) {
                fast = fast->next->next;
                slow = slow->next;
                if(slow == fast) {
                    return true;
                }
            } else {
                return false;
            }
        }
        return false;
    }
};
