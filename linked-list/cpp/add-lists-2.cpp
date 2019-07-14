/* Given two non-empty linked lists representing two non-negative integers.
   The most significant digit comes first and each of their nodes contain a
   single digit. Add the two numbers and return it as a linked list. You may
   assume the two numbers do not contain any leading zero,
   except the number 0 itself.
   Follow up: What if you cannot modify the input lists?
   In other words, reversing the lists is not allowed
   LC 445. Add Two Numbers II
   Author: Shruti
*/

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode* l3;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_size = findLength(l1);
        int l2_size = findLength(l2);
        int carry = 0;
        if(l1_size > l2_size) {
            l2 = padList(l1, l2, l1_size, l2_size);
        } else {
            l1 = padList(l1, l2, l1_size, l2_size);
        }
        carry = addLists(l1, l2, carry);
        /* append carry(if present) from most significant digit addition */
        if(carry) {
            ListNode* temp = l3;
            l3 = new ListNode(carry);
            l3->next = temp;
        }
        return l3;
    }

    /* recursive function that generates l3*/
    int addLists(ListNode* l1, ListNode* l2, int& carry) {
        if(!l1->next && !l2->next) {
            l3 = new ListNode((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry)/10;
            return carry;
        }
        int temp_sum = l1->val + l2->val + addLists(l1->next,l2->next,carry);
        ListNode* temp = new ListNode((temp_sum)%10);
        carry = temp_sum/10;
        temp->next = l3;
        l3 = temp;
        return carry;
    }


    /* pad the smaller linked list with zeros till they are equal in size */
    ListNode* padList(ListNode* l1, ListNode* l2, int l1_size, int l2_size) {
        int size_diff = abs(l1_size - l2_size);
        ListNode* temp;
        if(l1_size > l2_size) {
            while(size_diff) {
                temp = l2;
                l2 = new ListNode(0);
                l2->next = temp;
                size_diff--;
            }
            return l2;
        }
        while(size_diff) {
            temp = l1;
            l1 = new ListNode(0);
            l1->next = temp;
            size_diff--;
        }
        return l1;
    }

    /* find length of a linked list */
    int findLength(ListNode* l) {
        int length = 0;
        while(l) {
            l = l->next;
            length++;
        }
        return length;
    }
};
