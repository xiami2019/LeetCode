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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> singleLayer;
        int toBeVisted = 1, nextLayer = 0; // 标记这一层节点数和下一层节点数
        queue<TreeNode*> bfs;
        if (root == NULL) return res;

        bfs.push(root);
        while (!bfs.empty()) {
            TreeNode* currentNode = bfs.front();
            singleLayer.push_back(currentNode->val);
            if (currentNode->left != NULL) {
                nextLayer++;
                bfs.push(currentNode->left);
            }
            if (currentNode->right != NULL) {
                nextLayer++;
                bfs.push(currentNode->right);
            }

            bfs.pop();
            toBeVisted--;
            if (0 == toBeVisted) {
                res.emplace_back(singleLayer);
                singleLayer.clear();
                toBeVisted = nextLayer;
                nextLayer = 0;
            }
        }

        return res;
    }
};