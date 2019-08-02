/* Given a binary tree, return the level order traversal of its nodes' values.
   (ie, from left to right, level by level).
   LC 102. Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> level;
        queue<TreeNode*> temp;
        if(root) {
            temp.push(root);
        }

        while(!temp.empty()) {
            level.clear();
            int size = temp.size();
            for(int i = 0; i < size; i++) {
                TreeNode* curr_root = temp.front();
                temp.pop();
                level.push_back(curr_root->val);
                if(curr_root->left) temp.push(curr_root->left);
                if(curr_root->right) temp.push(curr_root->right);
            }
            result.push_back(level);
        }
        return result;
    }
};
