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
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        queue<TreeNode*> bfs;
        int toBeStored = 1, nextLayer = 0;
        vector<int> singleLayer;
        bfs.push(root);
        
        while (!bfs.empty()) {
            TreeNode* currentNode = bfs.front();
            bfs.pop();
            singleLayer.emplace_back(currentNode->val);
            toBeStored--;

            if (currentNode->left != NULL) {
                bfs.push(currentNode->left);
                nextLayer++;
            }
            if (currentNode->right != NULL) {
                bfs.push(currentNode->right);
                nextLayer++;
            }

            if (toBeStored == 0) {
                toBeStored = nextLayer;
                nextLayer = 0;
                ans.emplace_back(singleLayer);
                singleLayer.clear();
            }
        }
        return ans;
    }
};