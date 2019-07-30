/* Given a binary search tree and the lowest and highest boundaries as L and R,
   trim the tree so that all its elements lies in [L, R] (R >= L). You might
   need to change the root of the tree, so the result should return the new
   root of the trimmed binary search tree.
   LC 669. Trim a Binary Search Tree
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) {
            return NULL;
        }
        if(L > root->val) {
            return trimBST(root->right, L, R); // recurse right, L is in right subtree
        }
        if(R < root->val) {
            return trimBST(root->left, L, R); // recurse left, R is in left subtree
        }
        root->left = trimBST(root->left, L, R); // trim at left as L in left subtree
        root->right = trimBST(root->right, L, R); // trim at right as R in right subtree
        return root;
    }
};
