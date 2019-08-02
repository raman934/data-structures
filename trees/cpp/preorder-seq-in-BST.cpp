/* Given an array of numbers, verify whether it is the correct preorder
   traversal sequence of a binary search tree. You may assume each number in the
   sequence is unique.
   LC 255. Verify Preorder Sequence in Binary Search Tree
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
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> temp;
        int lower_bound = INT_MIN;
        for(int i = 0; i < preorder.size(); i++) {
            if(temp.empty() || preorder[i] < preorder[i-1])  {// curr val is less than prev val; in left subtree
                if(preorder[i] < lower_bound) {
                    return false; // curr val must always be greater than its root
                }
                temp.push(preorder[i]);
            } else {
                while(!temp.empty() && (temp.top() < preorder[i])) {
                    lower_bound = temp.top(); // get the root of preoder[i], i.e. node is just smaller than preoder[i]
                    temp.pop();
                }
                temp.push(preorder[i]);
            }
        }
        return true;
    }
};
