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
    vector<vector<int>> res;
    void dfs(TreeNode* root, vector<int>& singlePath, int curSum, int sum) {
        if (root == NULL) return;

        curSum += root->val;
        singlePath.push_back(root->val);
        if (root->left == NULL && root->right == NULL && curSum == sum) {
            res.emplace_back(singlePath);
        }
        else {
            dfs(root->left, singlePath, curSum, sum);
            dfs(root->right, singlePath, curSum, sum);
        }
        singlePath.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> singleplayer;
        dfs(root, singleplayer, curSum, sum);
        return res;
    }
};