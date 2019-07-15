/* Sort a linked list in O(n log n) time using constant space complexity.
   LC 148. Sort List
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
    ListNode* sortList(ListNode* head) {
        ListNode* curr = head;
        return mergeSort(curr);
    }

    /* recursively sort */
    ListNode* mergeSort(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* l1 = head;
        ListNode* l2 = head;
        /* divide list into two using fast slow pointers */
        while(l2->next && l2->next->next) {
            l1 = l1->next;
            l2 = l2->next->next;
        }
        l2 = l1->next;
        l1->next = NULL;
        l1 = mergeSort(head); // call mergeSort on first half
        l2 = mergeSort(l2); // call mergeSort on second half
        return merge(l1,l2);
    }

    // merge the two lists
    ListNode* merge(ListNode* l1,ListNode* l2) {
        ListNode head_l3(0);
        ListNode* l3 = &head_l3;
        /* if two lists have equal sizes */
        while(l1 && l2) {
            if(l1->val < l2->val) {
                l3->next = l1;
                l1 = l1->next;
            } else {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        if(l1) {
            l3->next = l1;
        } if(l2) {
            l3->next = l2;
        }
        return head_l3.next;
    }
};
