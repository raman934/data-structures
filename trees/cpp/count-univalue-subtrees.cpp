/* Given a binary tree, count the number of uni-value subtrees. A Uni-value
   subtree means all nodes of the subtree have the same value.
   LC 250. Count Univalue Subtrees
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
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int count = 0;
        isUnival(root, count);
        return count;
    }

    bool isUnival(TreeNode* root, int& count) {
        if(!root) {
            return true;
        }
        bool l = isUnival(root->left, count);
        bool r = isUnival(root->right, count);
        if(l && r && (root->left == NULL || root->left->val == root->val) && (root->right == NULL || root->right->val == root->val)) {
            count++;
            return true;
        }
        else {
            return false;
        }
    }
};
