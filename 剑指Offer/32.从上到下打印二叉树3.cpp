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
        bool isEven = false;
        vector<vector<int>> res;
        if (root == NULL) return res;
        stack<int> odd;
        stack<int> even;
        queue<int> q;
        q.push(root);
        int toBeStored = 1, nextLayer = 0;

        while (!q.empty()) {
            TreeNode* temp = q.front();
            
        }
    }
};