/* Given a Binary Search Tree (BST), convert it to a Greater Tree such that
   every key of the original BST is changed to the original key plus sum of all
   keys greater than the original key in BST.
   LC 538. Convert BST to Greater Tree
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
    int sum_to_add = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) {
            return NULL;
        }
        if(root->right) {
            convertBST(root->right);  // recurse right
        }
        root->val += sum_to_add; // update root val with sum
        sum_to_add = root->val; // update sum with the new root val
        if(root->left) {
            convertBST(root->left); //recurse left
        }
        return root;
    }
};
