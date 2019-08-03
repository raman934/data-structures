/* Given preorder and inorder traversal of a tree, construct the binary tree.
   LC 105. Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return NULL;
        // initialize start and end values
        int pre_start = 0;
        int pre_end = preorder.size() - 1;
        int in_start = 0;
        int in_end = inorder.size() - 1;
        return createTree(preorder, inorder, pre_start, pre_end, in_start, in_end);
    }

    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end) {
        // create new node
        TreeNode* root = new TreeNode(preorder[pre_start]);
        // termination condition
        if(pre_start > pre_end) return NULL;
        // find root in inorder vector
        int in_root_pos;
        for(int i = in_start; i <= in_end; i++) {
            if(inorder[i] == root->val) {
                in_root_pos = i;
            }
        }
        // repeat recursively for root's left and right children
        root->left = createTree(preorder, inorder, pre_start + 1, pre_start + in_root_pos - in_start, in_start, in_root_pos - 1);
        root->right = createTree(preorder, inorder, pre_start + in_root_pos - in_start + 1, pre_end, in_root_pos + 1, in_end);
        return root;
    }

};
