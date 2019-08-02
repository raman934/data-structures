/* Given a binary tree, imagine yourself standing on the right side of it,
   return the values of the nodes you can see ordered from top to bottom.
   LC 199. Binary Tree Right Side View
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
     vector<int> rightSideView(TreeNode* root) {
         vector<int> result;
         int level;
         queue<TreeNode*> temp;
         if(root) {
             temp.push(root);
         }
         while(!temp.empty()) {
             level = 0;
             int len = temp.size();
             for(int i = 0; i < len; i++) {
                 TreeNode* curr = temp.front();
                 temp.pop();
                 level = curr->val;
                 if(curr->left) {
                     temp.push(curr->left);
                 }
                 if(curr->right) {
                     temp.push(curr->right);
                 }
             }
             result.push_back(level);
         }
         return result;
     }
 };
