/* Invert a binary tree.
   LC 226. Invert Binary Tree
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) {
            return NULL;
        }
        TreeNode* left = invertTree(root->left); // recurse left subtree
        TreeNode* right = invertTree(root->right); // recurse right subtree
        root->left = right; // swap left and right children of the subtree
        root->right = left;
        return root;
    }
};
