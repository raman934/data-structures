/* Given the root node of a binary search tree (BST) and a value. You need to
   find the node in the BST that the node's value equals the given value.
   Return the subtree rooted with that node. If such node doesn't exist,
   you should return NULL.
   LC 700. Search in a Binary Search Tree
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) {
            return NULL; // val not found
        } else if(root->val == val) {
            return root; // base case
        } else if(val <= root->val) {
            root->right = NULL;
            return searchBST(root->left, val); // search in left tree
        } else {
            root->left = NULL;
            return searchBST(root->right, val); // search in right tree
        }
    }
};
