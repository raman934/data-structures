/* Given a binary tree, find its maximum depth. The maximum depth is the number
   of nodes along the longest path from the root node down to the farthest leaf
   node.
   LC 104. Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        if(!root->left && !root->right) {
            return 1; // root is leaf node
        }
        if(!root->right) {
            return maxDepth(root->left) + 1; //right sub-tree NULL, recurse on left sub-tree
        }
        if(!root->left) {
            return maxDepth(root->right) + 1; //left sub-tree NULL, recurse on right sub-tree
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1; // both sub-trees exist, choose max of the two
    }
};
