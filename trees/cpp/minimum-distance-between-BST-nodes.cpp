/* Given a Binary Search Tree (BST) with the root node root, return the minimum
   difference between the values of any two different nodes in the tree.
   LC 783. Minimum Distance Between BST Nodes
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
    int min_dist = INT_MAX;
    int diff = INT_MAX;
    int prev = -1;
public:
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return min_dist;
    }

    void dfs(TreeNode* root) {
        if(!root) {
            return;
        }
        dfs(root->left);
        if(prev != -1) {
            min_dist = min(min_dist, root->val - prev);
        }
        prev = root->val;
        dfs(root->right);
    }
};
