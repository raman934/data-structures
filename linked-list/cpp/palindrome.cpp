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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> temp;
        bool result;
        int length = findLen(head);
        /* put the first half of the list using slow runner fast runner in stack */
        while(fast && fast->next) {
            temp.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        while(slow) {
            if(length%2 == 0) {
                while(!temp.empty()) {
                    if(temp.top() != slow->val) {
                        return false;
                    } else {
                        temp.pop();
                        slow = slow->next;
                    }
                }
            } else {
                slow = slow->next; //skip middle node
                while(!temp.empty()) {
                    if(temp.top() != slow->val) {
                        return false;
                    } else {
                        temp.pop();
                        slow = slow->next;
                    }
                }
            }
        }
        return true;
    }

    int findLen(ListNode* head) {
        ListNode* curr = head;
        int length = 0;
        /* find length of list */
        while(curr) {
            curr = curr->next;
            length++;
        }
        return length;
    }
};
