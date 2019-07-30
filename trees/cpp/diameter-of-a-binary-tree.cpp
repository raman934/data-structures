/* Given a binary tree, you need to compute the length of the diameter of the
   tree. The diameter of a binary tree is the length of the longest path between
   any two nodes in a tree. This path may or may not pass through the root.
   LC 543. Diameter of Binary Tree
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
     int diameter = 0;
 public:
     int diameterOfBinaryTree(TreeNode* root) {
         if(!root) {
             return 0;
         }
         maxDepth(root);
         return diameter - 1;
     }

     int maxDepth(TreeNode* root) {
         if(!root) {
             return 0;
         }
         int l = maxDepth(root->left);
         int r = maxDepth(root->right);
         diameter = max(diameter, l + r + 1);
         return max(l, r) + 1;
     }
 };
