/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
二叉树的序列化本质上是对其值进行编码，更重要的是对其结构进行编码。
可以通过遍历树来完成上述任务。众所周知，有两个遍历的一般策略：

广度优先搜索（BFS）：
按照高度的顺序从上到下逐级扫描树。更高级别的节点将先于较低级别的节点访问。
深度优先搜索（DFS）：
采用深度作为优先顺序，这样我们就可以从一个根开始，一直延伸到某个叶，然后回到根，到达另一个分支。
根据根节点、左节点和右节点之间的相对顺序，可以进一步将DFS策略区分为：preorder、inorder和postorder。

在这个任务中，DFS策略更适合我们的需要，因为相邻节点之间的链接按顺序编码，这对后面的反序列化任务非常
有帮助。

先序遍历的DFS按root->left subtree->right subtree的顺序递归进行。
*/

class Codec {
public:

    void rserialize(TreeNode* root, string& str) {
        if (root == nullptr) {
            str += "null,";
        }
        else {
            str += to_string(root->val) + ",";
            this->rserialize(root->left, str);
            this->rserialize(root->right, str);
        }
    }

    TreeNode* rdeserialize(string data, int& u) {
        if (u == data.size()) return nullptr;
        int k = u;
        while (data[k] != ',') k++;
        if (data[u] == 'n') {
            // 如果读到了null子串
            u = k + 1;
            return nullptr;
        }
        int val = 0, sign = 1;
        if (u < k && data[u] == '-') {
            // 为负数的情况
            sign = -1;
            u++;
        }
        for (int i = u; i < k; i++) {
            val = val * 10 + (data[i] - '0');
        }
        val *= sign;
        u = k + 1;
        TreeNode* root = new TreeNode(val);
        root->left = this->rdeserialize(data, u);
        root->right = this->rdeserialize(data, u);

        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        this->rserialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return this->rdeserialize(data, u);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));