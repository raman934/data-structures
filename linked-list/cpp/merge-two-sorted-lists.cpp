/* Merge two sorted linked lists and return it as a new list. The new list
   should be made by splicing together the nodes of the first two lists.
   LC 21. Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && l2) {
            return l2;
        } else if(l1 && !l2) {
            return l1;
        } else if(!l1 && !l2) {
            return NULL;
        }
        ListNode* l3 = NULL;
        ListNode* head = NULL;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                if(!l3) {
                    l3 = new ListNode(l1->val);
                    head = l3;
                } else {
                    l3->next = new ListNode(l1->val);
                    l3 = l3->next;
                }
                l1 = l1->next;
            } else {
                if(!l3) {
                    l3 = new ListNode(l2->val);
                    head = l3;
                } else {
                    l3->next = new ListNode(l2->val);
                    l3 = l3->next;
                }
                l2 = l2->next;
            }
        }
        if(l1) {
            l3->next = l1;
        }
        if (l2) {
            l3->next = l2;
        }
        return head;
    }
};
