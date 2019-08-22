/* Given an integer array with no duplicates. A maximum tree building on this
   array is defined as follow:

   The root is the maximum number in the array.
   The left subtree is the maximum tree constructed from left part subarray
   divided by the maximum number.
   The right subtree is the maximum tree constructed from right part subarray
   divided by the maximum number.
   Construct the maximum tree by the given array and output the root node of
   this tree.

    Example 1:
    Input: [3,2,1,6,0,5]
    Output: return the tree root node representing the following tree:

      6
    /   \
    3     5
    \    /
     2  0
       \
        1

   LC 654. Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(!nums.size()) {
            return NULL;
        }
        return getTree(nums, 0, nums.size());
    }

    int getMax(vector<int>& nums, int start, int end) {
        int max_idx;
        int max_elem = INT_MIN;
        for(int i = start; i < end; i++) {
            if(nums[i] > max_elem) {
                max_elem = nums[i];
                max_idx = i;
            }
        }
        return max_idx;
    }

    TreeNode* getTree(vector<int>& nums, int start, int end) {
        if(start >= end) {
            return NULL;
        }
        int index = getMax(nums,start, end);
        // get max element in the array
        // make the max element the root
        TreeNode* root = new TreeNode(nums[index]);
        // left child is max element in the array elements to the left of the root element
        root->left = getTree(nums, start, index);
        // right child is max element in the array elements to the right of the root element
        root->right = getTree(nums, index + 1, end);
        return root;
    }
};
