/* Given a binary tree, return all duplicate subtrees. For each kind of
   duplicate subtrees, you only need to return the root node of any one of them.
   Two trees are duplicate if they have the same structure with same node values.

    Example 1:

            1
           / \
          2   3
         /   / \
        4   2   4
           /
          4
    The following are two duplicate subtrees:

          2
         /
        4
    and

        4

   LC 652. Find Duplicate Subtrees
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
    vector<TreeNode*> result;
    unordered_map<string,int> m;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // use preorder traversal to traverse the tree
        // store every subtree as a string, as a key in map
        // keep the count of the subtree seen as value in the map
        if(!root) {
            return result;
        }
        preorder(root);
        return result;
    }

    string preorder(TreeNode* root) {
        if(!root) {
            return "#";
        }
        string tree = to_string(root->val) + preorder(root->left) + preorder(root->right);
        m[tree]++;
        if(m[tree] == 2) {
            result.push_back(root);
        }
        return tree;
    }
};
