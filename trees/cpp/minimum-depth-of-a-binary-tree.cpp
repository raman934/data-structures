/* Given a binary tree, find its minimum depth. The minimum depth is the number
   of nodes along the shortest path from the root node down to the nearest leaf
   node.
   LC 111. Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0; // if tree empty
        }
        if(!root->left && !root->right) {
            return 1; // if leaf node
        }
        if(!root->right) {
            return minDepth(root->left) + 1; // recurse on left subtree
        }
        if(!root->left) {
            return minDepth(root->right) + 1; // recurse on right subtree
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1; // recurse on right subtree
    }
};
