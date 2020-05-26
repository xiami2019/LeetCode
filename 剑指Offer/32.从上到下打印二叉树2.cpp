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
        vector<vector<int> > res;
        vector<int> singleLayer;
        if (root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        int toBeStored = 1;
        int nextLayer = 0;
        while (!q.empty()) {
            TreeNode* temp = q.front();
            if (temp->left != NULL) {
                q.push(temp->left);
                nextLayer++;
            }
            if (temp->right != NULL) {
                q.push(temp->right);
                nextLayer++;
            }
            q.pop();
            singleLayer.push_back(temp->val);
            toBeStored--;
            if (toBeStored == 0) {
                toBeStored = nextLayer;
                nextLayer = 0;
                res.emplace_back(singleLayer);
                singleLayer.clear();
            }
        }

        return res;
    }
};