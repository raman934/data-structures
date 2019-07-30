/* Given a binary tree, check whether it is a mirror of itself (ie, symmetric
   around its center).
   LC 101. Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if(!root) {
            return true;
        }
        return checkNode(root->left, root->right);
    }

    bool checkNode(TreeNode* left_tree, TreeNode* right_tree) {
        if(!left_tree && !right_tree) {
            return true; // leaf node
        }
        if(!left_tree || !right_tree) {
            return false; // one of the two nodes compared is NULL
        }
        if(left_tree->val != right_tree->val) {
            return false; // the two nodes don't have equal val
        }
        return checkNode(left_tree->left, right_tree->right) && checkNode(left_tree->right, right_tree->left);
    }
};
