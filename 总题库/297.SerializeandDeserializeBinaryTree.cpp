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
    void rserialize(TreeNode* root, string& res) {
        if (root == NULL) {
            res += "null,";
            return;
        }
        res += to_string(root->val) + ',';
        rserialize(root->left, res);
        rserialize(root->right, res);
    }

    string serialize(TreeNode* root) {
        string res = "";
        rserialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* rdeserialize(string data, int& start) {
        if (start == data.size()) {
            return NULL;
        }
        int index = start;
        while (data[index] != ',') index++;
        if (data[start] == 'n') {
            start = index + 1;
            return NULL;
        }
        int val = 0, sign = 1;
        if (data[start] == '-'){
            sign = -1;
            ++start;
        }
        for (int i = start; i < index; ++i) {
            val = 10 * val + (data[i] - '0');
        }
        val *= sign;
        start = index + 1;
        TreeNode* root = new TreeNode(val);
        root->left = rdeserialize(data, start);
        root->right = rdeserialize(data, start);
        return root;
    }

    TreeNode* deserialize(string data) {
        int start = 0;
        TreeNode* root = rdeserialize(data, start);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));