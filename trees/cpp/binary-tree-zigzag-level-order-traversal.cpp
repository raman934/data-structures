/* Given a binary tree, return the zigzag level order traversal of its nodes'
   values. (ie, from left to right, then right to left for the next level and
   alternate between).
   LC 103. Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        vector<int> level;
        queue<TreeNode*> q;
        if(root) {
            q.push(root);
        }
        int count = 0;
        while(!q.empty()) {
            level.clear();
            int len = q.size();
            for(int i = 0; i < len; i++) {
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            count++;
            if(count%2 == 0) {
                reverse(level.begin(), level.end()); // reverse every other level
            }
            results.push_back(level);
        }
        return results;
    }
};
