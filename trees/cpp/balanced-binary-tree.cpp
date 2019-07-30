/* Given a binary tree, determine if it is height-balanced. For this problem,
   a height-balanced binary tree is defined as:  a binary tree in which the
   depth of the two subtrees of every node never differ by more than 1.
   LC 110. Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        if(!root) {
            return true;
        }
        int l = getDepth(root->left);
        int r = getDepth(root->right);
        return (abs(l - r) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }

    int getDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
};
