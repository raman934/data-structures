/* Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path
   represents a binary number starting with the most significant bit.  For
   example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent
   01101 in binary, which is 13.  For all leaves in the tree, consider the
   numbers represented by the path from the root to that leaf. Return the sum of
   these numbers.
   LC 1022. Sum of Root To Leaf Binary Numbers
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
    int ans;
public:
    int sumRootToLeaf(TreeNode* root) {
        getSumDFS(root,0);
        return ans;
    }

    /* get sum from binary numbers */
    void getSumDFS(TreeNode* root, int val) {
        if(!root) {
            return;
        }
        val = val << 1 | root->val; // construct binary number, left shift prev val, add curr root val
        if(!root->left && !root->right) {
            ans += val; // if leaf, add the constructed binary number to ans.
            return;
        }
        getSumDFS(root->left, val); // recurse left
        getSumDFS(root->right, val); // recurse right
    }
};
