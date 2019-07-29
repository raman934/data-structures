/* Given a binary tree and a sum, determine if the tree has a root-to-leaf path
   such that adding up all the values along the path equals the given sum.
   LC 112. Path Sum
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
    bool hasPathSum(TreeNode* root, int sum) {
        /* base case */
        if(!root) {
            return false;
        }
        sum -= root->val;
        /* base case */
        if(!root->left && !root->right) {
            return (sum == 0);
        }
        return (hasPathSum(root->right, sum) || hasPathSum(root->left, sum));
    }
}
