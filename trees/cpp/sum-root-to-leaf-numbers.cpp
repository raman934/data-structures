/* Given a binary tree containing digits from 0-9 only, each root-to-leaf path
   could represent a number.
   An example is the root-to-leaf path 1->2->3 which represents the number 123.
   Find the total sum of all root-to-leaf numbers

    Example:

    Input: [4,9,0,5,1]
        4
       / \
      9   0
     / \
    5   1
    Output: 1026
    Explanation:
    The root-to-leaf path 4->9->5 represents the number 495.
    The root-to-leaf path 4->9->1 represents the number 491.
    The root-to-leaf path 4->0 represents the number 40.
    Therefore, sum = 495 + 491 + 40 = 1026.

   LC 129. Sum Root to Leaf Numbers
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
    int sum = 0;
    vector<int> number;
public:
    int sumNumbers(TreeNode* root) {
        if(!root) {
            return 0;
        }
        dfs(root);
        return sum;
    }

    void dfs(TreeNode* root) {
        if(!root) {
            return;
        }
        number.push_back(root->val);
        if(!root->left && !root->right) {
            addNumberToSum(); // add the root->leaf number to current sum value
        }
        dfs(root->left);
        dfs(root->right);
        number.pop_back(); // pop the visited node
    }

    void addNumberToSum() {
        int result = 0;
        for(int i = 0; i < number.size(); i++) {
            result = result*10 + number[i]; // convert the vector to a single int
        }
        sum += result; // add the int to result
    }
};
