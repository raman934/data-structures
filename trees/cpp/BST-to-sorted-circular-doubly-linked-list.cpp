/* Convert a BST to a sorted circular doubly-linked list in-place.
   LC 426. Convert Binary Search Tree to Sorted Doubly Linked List
   Author: Shruti
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
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        Node* prev = NULL; // tracks the current node
        Node* head = NULL; // tracks the head of the doubly linked list
        inorderTraversal(root, prev, head);
        prev->right = head; // make the doubly linked list circular
        head->left = prev; // make the doubly linked list circular
        return head;
    }

    void inorderTraversal(Node* curr_node, Node*& prev, Node*& head) {
        if(curr_node->left) {
            inorderTraversal(curr_node->left, prev, head); // traverse the left subtree
        }
        if (!head) {
            head = curr_node; // if a node has no left child and the head is NULL => first most leaf from the left is the head
        }

        curr_node->left = prev; // set the left pointer to the predecessor of the curr_node
        if(prev) {
            prev->right = curr_node; // set the predecessor's right pointer to the curr_node
        }
        prev = curr_node; // increment the predecessor

        if(curr_node->right) {
            inorderTraversal(curr_node->right, prev, head); // traverse the right subtree
        }
    }
};
