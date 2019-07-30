/* A binary tree is univalued if every node in the tree has the same value.
   Return true if and only if the given tree is univalued.
   LC 965. Univalued Binary Tree
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
    bool isUnivalTree(TreeNode* root) {
        if(!root) {
            return true;
        }
        if(root->left) {
            if(root->val != root->left->val) {
                return false; // compare root val with root->left val
            }
        }
        if(root->right) {
            if(root->val != root->right->val) {
                return false; // compare root val with root->right val
            }
        }
        return (isUnivalTree(root->left) && isUnivalTree(root->right));
    }
};
