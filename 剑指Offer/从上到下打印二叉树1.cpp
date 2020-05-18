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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            TreeNode* currentNode = bfs.front();
            bfs.pop();
            ans.emplace_back(currentNode->val);
            if (currentNode->left != NULL) bfs.push(currentNode->left);
            if (currentNode->right != NULL) bfs.push(currentNode->right);
        }
        return ans;
    }
};