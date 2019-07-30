/* Find the sum of all left leaves in a given binary tree.
   LC 404. Sum of Left Leaves
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
    int sum = 0; // track sum
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) {
            return 0;
        }
        if(root->left && !root->left->left && !root->left->right) {
            sum += root->left->val; // is left leaf, add to sum
        } else if(root->left) {
            sum = sumOfLeftLeaves(root->left); // recurse left
        }
        if(root->right) {
            sum = sumOfLeftLeaves(root->right); // recurse right
        }
        return sum;
    }
};
