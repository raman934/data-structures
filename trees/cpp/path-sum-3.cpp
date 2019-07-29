/* You are given a binary tree in which each node contains an integer value.
   Find the number of paths that sum to a given value.
   The path does not need to start or end at the root or a leaf, but it must go
   downwards (traveling only from parent nodes to child nodes).
   LC 437. Path Sum III
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
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        if(!root) {
            return 0;
        }
        count += pathSumFromNode(root, sum);
        count += pathSum(root->left, sum);
        count += pathSum(root->right, sum);
        return count;
    }

    int pathSumFromNode(TreeNode* node, int sum) {
        if(!node) {
            return 0;
        }
        int count = 0;
        /* base case */
        if(node->val == sum) {
            count += 1;
        }
        count += pathSumFromNode(node->left, sum - node->val);
        count += pathSumFromNode(node->right, sum - node->val);
        return count;
    }
};
