/* Given a non-negative integer represented as non-empty a singly linked list of
   digits, plus one to the integer.
   LC 369. Plus One Linked List
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
    ListNode* plusOne(ListNode* head) {
        if(!head) {
            return NULL;
        }

        ListNode* curr = reverse(head);
        ListNode* temp_head = curr;
        int carry = 0;
        int temp_sum = 0;
        /* add one to most significant digit */
        if(curr) {
            temp_sum = curr->val + 1;
            curr->val = (temp_sum)%10;
            carry = (temp_sum)/10;
            if(!curr->next && carry) {
                curr->next = new ListNode(carry);
                carry = 0;
            }
            curr = curr->next;
        }
        /* add carry to the remaining digits */
        while(curr && carry) {
            temp_sum = curr->val + carry;
            curr->val = (temp_sum)%10;
            carry = (temp_sum)/10;
            if(!curr->next && carry) { // append only carry if curr is least significant digit
                curr->next = new ListNode(carry);
                curr = curr->next;
                break;
            }
            curr = curr->next;
        }
        return reverse(temp_head);
    }

    /* reverse linked list */
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* nxt = head;
        ListNode* prev = NULL;
        while(curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};
