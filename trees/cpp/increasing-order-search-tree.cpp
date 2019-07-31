/* Given a binary search tree, rearrange the tree in in-order so that the
   leftmost node in the tree is now the root of the tree, and every node has no
   left child and only 1 right child.
   LC 897. Increasing Order Search Tree
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
    TreeNode* curr;
public:
    TreeNode* increasingBST(TreeNode* root) {
        curr = new TreeNode(0); // create a new node
        TreeNode* ans = curr;
        inOrder(root); // inorder traversal to populate the tree
        return ans->right; // return right of the new node
    }

    void inOrder(TreeNode* root) {
        if(!root) {
            return;
        }
        inOrder(root->left);
        root->left = NULL;
        curr->right = root;
        curr = curr->right;
        inOrder(root->right);
    }
};
