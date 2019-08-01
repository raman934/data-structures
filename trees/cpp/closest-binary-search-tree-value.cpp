/* Given a non-empty binary search tree and a target value, find the value in
   the BST that is closest to the target.
   LC 270. Closest Binary Search Tree Value
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
    double min_diff = DBL_MAX;
    int min_node;
public:
    int closestValue(TreeNode* root, double target) {
        dfs(root, target);
        return min_node;
    }

    void dfs(TreeNode* root, double target) {
        if(!root) {
            return;
        }
        dfs(root->left, target);
        if(abs(target - root->val) < min_diff) {
            min_diff = abs(target - root->val);
            min_node = root->val;
        }
        dfs(root->right, target);
    }
};
