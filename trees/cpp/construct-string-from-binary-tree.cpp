/* You need to construct a string consists of parenthesis and integers from a
   binary tree with the preorder traversing way. The null node needs to be
   represented by empty parenthesis pair "()". And you need to omit all the
   empty parenthesis pairs that don't affect the one-to-one mapping
   relationship between the string and the original binary tree.
   LC 606. Construct String from Binary Tree
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
    string result;
public:
    string tree2str(TreeNode* t) {
        preOrder(t);
        return result;
    }

    void preOrder(TreeNode* root) {
        if(!root) {
            return;
        }
        result += to_string(root->val);
        if(root->left) {
            result += "(";
            preOrder(root->left);
            result += ")";
        }
        if(!root->left && root->right) {
            result += "()";
        }
        if(root->right) {
            result += "(";
            preOrder(root->right);
            result += ")";
        }
    }
};
