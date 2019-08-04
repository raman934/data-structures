/* Implement an iterator over a binary search tree (BST). Your iterator will be
   initialized with the root node of a BST. Calling next() will return the next
   smallest number in the BST.
   LC 173. Binary Search Tree Iterator
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

 class BSTIterator {
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode* root) {
        getLeft(root);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* temp = stk.top();
        stk.pop();
        getLeft(temp->right);
        return temp->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(!stk.empty()) {
            return true;
        }
        return false;
    }

    void getLeft(TreeNode* root) {
        if(!root) {
            return;
        }
        stk.push(root);
        while(root->left) {
            stk.push(root->left);
            root = root->left;
        }
    }

    void popNode(TreeNode* root) {
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
