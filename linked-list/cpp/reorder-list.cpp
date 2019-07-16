/* Given a singly linked list L: L0→L1→…→Ln-1→Ln,
   reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
   LC 143. Reorder List
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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) {
            return;
        }
        // divide the list in the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l2 = slow->next;
        slow->next = NULL;
        ListNode* l1 = head;

        l2 = reverse(l2);
        head = merge(l1,l2);
        return;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = head;
        while(curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* head = l3;
        while(l1 && l2) {
            l3->next = l1;
            l1 = l1->next;
            l3 = l3->next;
            l3->next = l2;
            l2 = l2->next;
            l3 = l3->next;
        }
        if(l1) {
            l3->next = l1;
        } if(l2) {
            l3->next = l2;
        }
        return head->next;
    }
};
