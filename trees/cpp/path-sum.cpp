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
         if(!root) {
             return false;
         }
         sum -= root->val; // subtract the curr root val from sum
         if(!root->left && !root->right) {
             if (sum == 0) {
                 return true; // if leaf && sum == 0, path sum found
             }
         }
         bool left = hasPathSum(root->right, sum); // recurse on left subtree
         bool right = hasPathSum(root->left, sum); // recurse on right subtree
         return (left||right); // return true if any path found in any subtree
     }
 };
