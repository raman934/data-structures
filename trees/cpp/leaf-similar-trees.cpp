/* Consider all the leaves of a binary tree.  From left to right order, the
   values of those leaves form a leaf value sequence. Two binary trees are
   considered leaf-similar if their leaf value sequence is the same. Return
   true if and only if the two given trees with head nodes root1 and root2 are
   leaf-similar.
   LC 872. Leaf-Similar Trees
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
    vector<int> seq1;
    vector<int> seq2;
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2) {
            return false;
        }
        getLeafSequence(root1, seq1);
        getLeafSequence(root2, seq2);
        return (seq1==seq2);
    }

    void getLeafSequence(TreeNode* root, vector<int>& seq) {
        if(!root) {
            return;
        }
        getLeafSequence(root->left, seq);
        if(!root->left && !root->right) {
            seq.push_back(root->val);
        }
        getLeafSequence(root->right, seq);
        return;
    }
};
