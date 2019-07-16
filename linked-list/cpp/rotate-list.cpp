/* Given a linked list, rotate the list to the right by k places,
   where k is non-negative.
   LC 61. Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) {
            return NULL;
        }
        if (!k || !head->next) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;
        dummy->next = head;
        ListNode* prev = getTail(curr);
        ListNode* tail = prev->next;
        int len = getLen(curr);
        k = k%len;
        while(k) {
            ListNode* temp = dummy->next;
            dummy->next = tail;
            tail->next = temp;
            prev->next = NULL;
            tail = prev;
            curr = dummy->next;
            prev = getTail(curr);
            k--;
        }
        return dummy->next;
    }

    ListNode* getTail(ListNode* head) {
        while(head->next && head->next->next) {
            head = head->next;
        }
        return head;
    }

    int getLen(ListNode* head) {
        int len = 0;
        while(head) {
            head = head->next;
            len++;
        }
        return len;
    }
};
