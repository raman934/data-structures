/* Given a binary tree and a sum, find all root-to-leaf paths where each path's
   sum equals the given sum.
   LC 113. Path Sum II
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
    vector<vector<int>> result;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) {
            return result;
        }
        getPathSum(root, sum);
        return result;
    }

    void getPathSum(TreeNode* root, int sum) {
        if(!root) {
            return;
        }
        sum -= root->val;
        path.push_back(root->val);
        if((!root->left && !root->right) && (sum == 0)) {
            result.push_back(path);
        }
        getPathSum(root->left, sum);
        getPathSum(root->right, sum);
        path.pop_back(); // remove from path vector; node & its children have been visited
    }
};
