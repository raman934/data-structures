/* Given a singly linked list where elements are sorted in ascending order,
   convert it to a height balanced BST.
   For this problem, a height-balanced binary tree is defined as a binary tree
   in which the depth of the two subtrees of every node never differ by more
   than 1.

    Example:

    Given the sorted linked list: [-10,-3,0,5,9],

    One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

          0
         / \
       -3   9
       /   /
     -10  5

   LC 109. Convert Sorted List to Binary Search Tree
   Author: Shruti
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return createBST(head);
    }

    TreeNode* createBST(ListNode* head) {
        if(!head) {
            return NULL; // base condition
        }
        if(!head->next) {
            return new TreeNode(head->val); // single element remaining, add to tree
        }
        // get mid and tail using fast and slow runner technique;
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow && fast && fast->next) {
            prev = slow; // keep track of mid's previous pointer to break the list
            fast = fast->next->next;
            slow = slow->next;
        }
        if(prev) {
            prev->next = NULL;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = createBST(head);
        root->right = createBST(slow->next);
        return root;
    }
};
