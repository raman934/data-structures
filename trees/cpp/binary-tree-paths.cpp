/* Given a binary tree, return all root-to-leaf paths.
   LC 257. Binary Tree Paths
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
     vector<string> result;
     string path;
 public:
     vector<string> binaryTreePaths(TreeNode* root) {
         if(!root) {
             return result;
         }
         getPaths(root, path);
         return result;
     }

     void getPaths(TreeNode* root, string path) {
         if(!root) {
             return;
         }
         if(!root->left && !root->right) {
             path += to_string(root->val); // leaf node
             result.push_back(path);
         } else {
             path += to_string(root->val)  + "->";
         }
         getPaths(root->left, path);
         getPaths(root->right, path);
         return;
     }
 };
