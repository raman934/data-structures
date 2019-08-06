/* Given a complete binary tree, count the number of nodes.
   LC 222. Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        // find depth of the tree
        int depth = getDepth(root) - 1; // depth is the number of edges
        if(depth == 0) {
            return 1; // one node only exists
        }
        // find the number of nodes in the last level using binary search
        int left = 0;
        int right = pow(2,depth) - 1; // number of nodes in the last level
        while(left <= right) {
            int middle = (left + right)/2; // middle node index of the last level
            if(exists(middle, depth, root)) {
                left = middle + 1; // middle node index is present, find the number of nodes in the right subtree
            } else {
                right = middle - 1; // look for middle in left subtree;
            }
        }
        return pow(2,depth) - 1 + left;
    }

    bool exists(int mid, int depth, TreeNode* root) {
        // at each level indentify which subtree to take
        int left = 0;
        int right = pow(2,depth) - 1;
        int pivot;
        for(int i = 0; i < depth; i++) {
            pivot = (left + right)/2;
            if(mid <= pivot) {
                root = root->left;
                right = pivot;
            } else {
                root = root->right;
                left = pivot + 1;
            }
        }
        if(root) {
            return true;
        } else {
            return false;
        }
    }

    int getDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return max(left,right) + 1;
    }
};
