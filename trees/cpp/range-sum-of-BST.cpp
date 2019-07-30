/* Given the root node of a binary search tree, return the sum of values of all
   nodes with value between L and R (inclusive). The binary search tree is
   guaranteed to have unique values.
   LC 938. Range Sum of BST
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
    int sum = 0;
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root) {
            return 0;
        }
        if(root->val >= L && root->val <= R) {
            sum += root->val; // root->val in range, add to sum
        }
        if(L < root->val && root->left) {
            sum = rangeSumBST(root->left, L, R); // recurse left, as L in left subtree
        }
        if(R > root->val && root->right) {
            sum = rangeSumBST(root->right, L, R); // recurse right, as R in right subtree
        }
        return sum;
    }
};
