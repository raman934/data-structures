/* Given a non-empty special binary tree consisting of nodes with the
   non-negative value, where each node in this tree has exactly two or zero
   sub-node. If the node has two sub-nodes, then this node's value is the
   smaller value among its two sub-nodes. More formally, the property
   root.val = min(root.left.val, root.right.val) always holds. Given such a
   binary tree, you need to output the second minimum value in the set made of
   all the nodes' value in the whole tree. If no such second minimum value
   exists, output -1 instead.
   LC 671. Second Minimum Node In a Binary Tree
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
    int second_min = -1;
public:
    int findSecondMinimumValue(TreeNode* root) {
        int min_val = root->val;
        if(!root) {
            return -1;
        }
        dfs(root, min_val);
        return second_min;
    }

    void dfs(TreeNode* root, int min_val) {
        if(!root) {
            return;
        }
        if(root->val > min_val) {
            if(second_min != -1) {
                second_min = min(root->val, second_min);
            } else {
                second_min = root->val;
            }
        }
        dfs(root->left, min_val);
        dfs(root->right, min_val);
    }
};
