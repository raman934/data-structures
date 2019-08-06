/* You are given a perfect binary tree where all leaves are on the same level,
   and every parent has two children. The binary tree has the following
   definition:
   struct Node {
      int val;
      Node *left;
      Node *right;
      Node *next;
    }
    Populate each next pointer to point to its next right node. If there is no
    next right node, the next pointer should be set to NULL. Initially,
    all next pointers are set to NULL.
    LC 116. Populating Next Right Pointers in Each Node
    Author: Shruti
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode* next;
 *     TreeNode(){}
 *     TreeNode(int _val, TreeNode* _left, TreeNode* _right, TreeNode* _next) {
 *        val = _val;
 *        left = _left;
 *        right = _right;
 *        next = _next;
 *     }
 * };
 */

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) {
            return root;
        }
        if(root->left && root->right) {
            root->left->next = root->right; // connect two children of same subtree
        }
        if(root->right && root->next) {
            root->right->next = root->next->left; // connect two children of adjacent subtrees
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};
