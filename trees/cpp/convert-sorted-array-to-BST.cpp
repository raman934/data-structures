/* Given an array where elements are sorted in ascending order, convert it to a
   height balanced BST.
   For this problem, a height-balanced binary tree is defined as a binary tree
   in which the depth of the two subtrees of every node never differ by more
   than 1.

    Example:

    Given the sorted array: [-10,-3,0,5,9],

    One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

          0
         / \
       -3   9
       /   /
     -10  5

   LC 108. Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums, 0, nums.size() - 1);
    }

    TreeNode* createBST(vector<int>& nums, int start, int end) {
        if(start > end) {
            return NULL; // base condition
        }
        int mid = (start + end)/2; // find the mid of the vector, it is the new root
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createBST(nums, start, mid - 1); // mid from the left portion of the vector is the root of left subtree
        root->right = createBST(nums, mid + 1, end); // mid from the right portion of the vector is the root of right subtree
        return root;
    }
};
