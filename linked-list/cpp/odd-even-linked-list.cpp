/* Given a singly linked list, group all odd nodes together followed by the
   even nodes. Please note here we are talking about the node number and not
   the value in the nodes. You should try to do it in place. The program should
   run in O(1) space complexity and O(nodes) time complexity.
   LC 328. Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) {
            return head;
        }
        ListNode* odd_head = head;
        ListNode* even_head = head->next;
        ListNode* odd = odd_head;
        ListNode* even = even_head;
        while(even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return odd_head;
    }
};
