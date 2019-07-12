/* Find the node at which the intersection of two singly linked lists begins.
   LC 160. Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) {
            return NULL;
        }
        ListNode* currA = headA;
        ListNode* currB = headB;
        int lenA = 0;
        int lenB = 0;
        /* find length of list A */
        while(currA) {
            currA = currA->next;
            lenA++;
        }
        /* find length of list B */
        while(currB) {
            currB = currB->next;
            lenB++;
        }
        /* check if intersection */
        if(currA != currB) {
            return NULL;
        }
        /* reset current pointers */
        currA = headA;
        currB = headB;
        /* update current ptr of the longer list with the difference in list lengths */
        if(lenB > lenA) {
            int lenDiff = lenB - lenA;
            while(lenDiff) {
                currB = currB->next;
                lenDiff--;
            }
        } else {
            int lenDiff = lenA - lenB;
            while(lenDiff) {
                currA = currA->next;
                lenDiff--;
            }
        }
        /* return intersection */
        while(currA != currB) {
            currA = currA->next;
            currB = currB->next;
        }
        return currA;
    }
};
