/* Given two binary trees, write a function to check if they are the same or
   not. Two binary trees are considered the same if they are structurally
   identical and the nodes have the same value.
   LC 100. Same Tree
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
     bool isSameTree(TreeNode* p, TreeNode* q) {
         bool result = true;
         if(!p && !q) {
             return true; // leaf node
         }
         else if(!p || !q) {
             result = false; // one of the two nodes compared is NULL
         }
         else if(p->val != q->val) {
             result = false; // he two nodes don't have equal val
         } else {
             result = isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
         }
         return result;
     }
 };
