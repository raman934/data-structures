/* Given a linked list and a value x, partition it such that all nodes less
   than x come before nodes greater than or equal to x.
   Preserve the original relative order of the nodes in each of the two partitions.
   LC 86. Partition List
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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) {
            return head;
        }
        /* two head and tail pointers for two linked lists */
        ListNode* h1 = NULL;
        ListNode* t1 = NULL;
        ListNode* h2 = NULL;
        ListNode* t2 = NULL;
        ListNode* temp = head;
        while(temp){
          /* if val less than x insert into list 1 */
            if(temp->val < x) {
                if(!h1) {
                    h1 = new ListNode(temp->val);
                    t1 = h1;
                } else {
                    t1->next = new ListNode(temp->val);
                    if(t1->next) {
                        t1 = t1->next;
                    }
                }
            } else { /* if val greater than x insert into list 2 */
                if(!h2) {
                    h2 = new ListNode(temp->val);
                    t2 = h2;
                } else {
                    t2->next = new ListNode(temp->val);
                    t2 = t2->next;
                }
            }
            temp = temp->next;
        }
        /* return the merged list if both list 1 and 2 non empty */
        if(!h1 && h2) {
            return h2;
        } else if(h1 && h2) {
            t1->next = h2;
        }
        return h1;
    }
};
