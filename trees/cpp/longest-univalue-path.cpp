/* Given a binary tree, find the length of the longest path where each node
   in the path has the same value. This path may or may not pass through the
   root. The length of path between two nodes is represented by the number of
   edges between them
   LC 687. Longest Univalue Path
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
    int len = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) {
            return 0;
        }
        dfs(root, root->val);
        return len;
    }

    int dfs(TreeNode* root, int prev) {
        if(!root) {
            return 0;
        }
        int left = dfs(root->left, root->val);
        int right = dfs(root->right, root->val);
        len = max(len, left + right);
        if(prev == root->val) {
            return max(left, right) + 1;
        }
        return 0;
    }
};
