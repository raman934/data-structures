/* Given a binary tree, return the values of its boundary in anti-clockwise
   direction starting from root. Boundary includes left boundary, leaves, and
   right boundary in order without duplicate nodes.  (The values of the nodes
   may still be duplicates.)
   Left boundary is defined as the path from root to the left-most node. Right
   boundary is defined as the path from root to the right-most node. If the
   root doesn't have left subtree or right subtree, then the root itself is left
   boundary or right boundary. Note this definition only applies to the input
   binary tree, and not applies to any subtrees.
   The left-most node is defined as a leaf node you could reach when you always
   firstly travel to the left subtree if exists. If not, travel to the right
   subtree. Repeat until you reach a leaf node.
   The right-most node is also defined by the same way with left and right
   exchanged.

   LC 545. Boundary of Binary Tree
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
        if(!root) {
            return result;
        }
        result.push_back(root->val);
        if(!root->left && !root->right) {
            return result;
        }
        getLeft(root->left, result);
        getLeaves(root, result);
        getRight(root->right, result);
        return result;
    }

    void getLeft(TreeNode* root, vector<int>& result) {
        if(!root || (!root->left && !root->right)) {
            return;
        }
        result.push_back(root->val);
        if(root->left) {
            getLeft(root->left, result);
        } else {
            getLeft(root->right, result);
        }
        return;
    }

    void getLeaves(TreeNode* root, vector<int>& result) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            result.push_back(root->val);
            return;
        }
        getLeaves(root->left, result);
        getLeaves(root->right, result);
        return;
    }

    void getRight(TreeNode* root, vector<int>& result) {
        if(!root || (!root->left && !root->right)) {
            return;
        }
        if(root->right) {
            getRight(root->right, result);
        } else {
            getRight(root->left, result);
        }
        result.push_back(root->val);
        return;
    }

};
