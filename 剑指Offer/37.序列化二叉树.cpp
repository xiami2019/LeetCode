/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 使用先序遍历加特殊符号的方法来处理；
class Codec {
public:
    void rserialize(TreeNode* root, string& str) {
        if (root == NULL) {
            str += "null,";
            return;
        }

        str += to_string(root->val) + ',';
        rserialize(root->left, str);
        rserialize(root->right, str);
    }

    TreeNode* rdeserialize(string data, int& index) {
        if (index == data.length()) return NULL;
        int k = index;
        while (data[k] != ',') k++;
        if (data[index] == 'n') {
            index = k + 1;
            return NULL;
        }
        
        int val = 0;
        int negative = 1;
        if (index < k && data[index] == '-') {
            // 此节点的值为负数
            negative = -1;
            index++;
        }
        for (int i = index; i < k; i++) {
            val = val * 10 + (data[i] - '0');
        }
        val *= negative;
        index = k + 1;
        TreeNode *root = new TreeNode(val);
        root->left = rdeserialize(data, index);
        root->right = rdeserialize(data, index);
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        rserialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return rdeserialize(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));