/* Given a binary search tree with non-negative values, find the minimum
   absolute difference between values of any two nodes.
   LC 530. Minimum Absolute Difference in BST
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
    int prev = -1;
public:
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return min_dist;
    }

    void inOrder(TreeNode* root) {
        if(!root) {
            return;
        }
        inOrder(root->left);
        if(prev != -1) {
            min_dist = min(min_dist, root->val - prev);
        }
        prev = root->val;
        inOrder(root->right);
        return;
    }
};
