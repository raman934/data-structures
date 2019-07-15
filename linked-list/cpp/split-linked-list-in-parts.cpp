/* Given a (singly) linked list with head node root, write a function to split
   the linked list into k consecutive linked list "parts".
   The length of each part should be as equal as possible: no two parts should
   have a size differing by more than 1. This may lead to some parts being null.
   The parts should be in order of occurrence in the input list, and parts
   occurring earlier should always have a size greater than or equal parts
   occurring later.
   Return a List of ListNode's representing the linked list parts that are
   formed.
   LC 725. Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int size1, size2, num1, num2; // size of parts and number of such parts
        int len = findLen(root);
        int npp = len/k; // nodes per part
        vector<ListNode*> result;
        /* calculate num of parts and size of each part */
        if(npp < 1) {
            size1 = 1;
            num1 = len;
            size2 = 0;
            num2 = k - len;
        } else {
            int rem = len%k;
            if(rem != 0) {
                size1 = npp + 1;
                num1 = rem;
                size2 = npp;
                num2 = k - rem;
            } else {
                size1 = npp;
                num1 = k;
                size2 = 0;
                num2 = 0;
            }
        }
        /* populate vector */
        while(num1 && root) {
            ListNode* head = new ListNode(root->val);
            root = root->next;
            ListNode* temp_head = head;
            int temp_size = size1 - 1;
            while(temp_size) {
                head->next = root;
                head = head->next;
                root = root->next;
                temp_size--;
            }
            head->next = NULL;
            result.push_back(temp_head);
            num1--;
        }
        while(num2) {
            if(size2 && root) {
                ListNode* head = new ListNode(root->val);
                root = root->next;
                ListNode* temp_head = head;
                int temp_size = size2 - 1;
                while(temp_size && head) {
                    head->next = root;
                    head = head->next;
                    root = root->next;
                    temp_size--;
                }
                if(head) {
                    head->next = NULL;
                }
                result.push_back(temp_head);
            } else {
                result.push_back(NULL);
            }
            num2--;
        }
        return result;
    }

    int findLen(ListNode* head) {
        int len = 0;
        while(head) {
            head = head->next;
            len++;
        }
        return len;
    }
};
