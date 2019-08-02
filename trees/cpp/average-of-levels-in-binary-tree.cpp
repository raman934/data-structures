/* Given a non-empty binary tree, return the average value of the nodes on each
   level in the form of an array.
   LC 637. Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        double level;
        queue<TreeNode*> temp;
        if(root) {
            temp.push(root);
        }
        while(!temp.empty()) {
            level = 0;
            int count = 0;
            int len = temp.size();
            for(int i = 0; i < len; i++) {
                TreeNode* curr = temp.front();
                temp.pop();
                level += curr->val;
                count++;
                if(curr->left) temp.push(curr->left);
                if(curr->right) temp.push(curr->right);
            }
            result.push_back(level/count);
        }
        return result;
    }
};
