/* Given a non-empty binary tree, find the maximum path sum. For this problem,
   a path is defined as any sequence of nodes from some starting node to any
   node in the tree along the parent-child connections. The path must contain
   at least one node and does not need to go through the root.
   LC 124. Binary Tree Maximum Path Sum
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
    int max_sum = INT_MIN;
    int sum = 0;
public:
    int maxPathSum(TreeNode* root) {
        getPathSum(root);
        return max_sum;
    }

    int getPathSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int left = getPathSum(root->left);
        int right = getPathSum(root->right);
        left = max(0, left);
        right = max(0, right);
        max_sum = max(max_sum, left + right + root->val);
        return root->val + max(left,right);
    }

};
