/* Given a binary tree, return all root-to-leaf paths.
   LC 257. Binary Tree Paths
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
    vector<int> res_int;
    vector<string> res;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) {
            return res;
        }
        res_int.push_back(root->val); // push current root in int vector
        if(root->left) {
            binaryTreePaths(root->left); // visit left subtree
        }
        if(root->right) {
            binaryTreePaths(root->right);  // visit right subtree
        }
        if(!root->left && !root->right) { // visit leaf node
            string temp;
            for(int i = 0; i < res_int.size(); i++) {
                if(i != res_int.size() - 1) {
                    temp += to_string(res_int[i]) + "->";
                } else {
                    temp += to_string(res_int[i]);
                }
            }
            res.push_back(temp); // add string to result vector; path ended
        }
        res_int.pop_back(); // pop the visited node from int vector
        return res;
    }
};
