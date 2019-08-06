/* Given a binary tree, flatten it to a linked list in-place.
   LC 114. Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        while(root){
            if(root->left && root->right) {
                TreeNode* temp = root->left; // put the right subtree as right child of left subtree
                while(temp->right) {
                    temp = temp->right;
                }
                temp->right = root->right;
            } if(root->left) {     // put the consolidated left subtree as right child of root
                root->right = root->left;
                root->left = NULL; // set left child as NULL
            }
            root = root->right; // increment root
        }
    }
};
