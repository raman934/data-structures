/* Given a singly linked list, determine if it is a palindrome.
   LC 234. Palindrome Linked List
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // base conditions
        if(!l1 && l2) {
            return l2;
        } else if(l1 && !l2) {
            return l1;
        } else if(!l1 && !l2) {
            return NULL;
        }
        int carry = 0;
        ListNode* l3 = NULL; // sum list
        ListNode* l3_head = NULL; // head of resultant linked list
        /* both l1 and l2 are of equal length */
        while(l1 && l2) {
            if(!l3) {
                l3 = new ListNode((l1->val + l2->val + carry)%10);  // put only second digit
                l3_head = l3;
            } else {
                l3->next = new ListNode((l1->val + l2->val + carry)%10);
                l3 = l3->next;
            }
            carry = (l1->val + l2->val+ carry)/10; 
            l1 = l1->next;
            l2 = l2->next;
        }
        /* case of l1 longer than l2*/
        while(l1 && !l2) {
            l3->next = new ListNode((l1->val + carry)%10);
            l3 = l3->next;
            carry = (l1->val + carry)/10;
            l1 = l1->next;
        }
        /* case of l2 longer than l1*/
        while(!l1 && l2) {
            l3->next = new ListNode((l2->val + carry)%10);
            l3 = l3->next;
            carry = (l2->val + carry)/10;
            l2 = l2->next;
        }
        /* case of outstanding carry */
        if(!l1 && !l2 && carry) {
            l3->next = new ListNode(carry);
            l3 = l3->next;
        }
        return l3_head;
    }
};
