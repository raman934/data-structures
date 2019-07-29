/* Given a n-ary tree, find its maximum depth. The maximum depth is the number
   of nodes along the longest path from the root node down to the farthest leaf
   node.
   LC 559. Maximum Depth of N-ary Tree
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
    int maxDepth(Node* root) {
        if(!root) {
            return 0;
        }
        if(root->children.empty()) {
            return 1;
        }
        int max_height = INT_MIN;
        for(int i = 0; i < root->children.size(); i++) {
            if(root->children[i]) {
                max_height = max(max_height, maxDepth(root->children[i]) + 1);
            }
        }
        return max_height;
    }
};
