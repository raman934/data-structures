/* Design an algorithm to serialize and deserialize a binary search tree.
   LC 449. Serialize and Deserialize BST
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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) {
            return "#";
        }
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") {
            return NULL;
        }
        stringstream s(data);
        TreeNode* root;
        return makeDeserialize(root, s);
    }

    TreeNode* makeDeserialize(TreeNode* root, stringstream& s) {
        string str;
        getline(s, str,',');
        if(str == "#") {
            return NULL;
        }
        root = new TreeNode(stoi(str));
        root->left = makeDeserialize(root->left, s);
        root->right = makeDeserialize(root->right, s);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
