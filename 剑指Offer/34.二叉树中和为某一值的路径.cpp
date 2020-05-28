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
    void dfs(vector<int>& singlePath, TreeNode* root, int curSum, int sum) {
        if (root == NULL) return;

        curSum += root->val;
        singlePath.push_back(root->val);
        if (root->left == NULL && root->right == NULL && curSum == sum) {
            res.emplace_back(singlePath);
        }
        else {
            dfs(singlePath, root->left, curSum, sum);
            dfs(singlePath, root->right, curSum, sum);
        }
        singlePath.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> singlePath;
        dfs(singlePath, root, 0, sum);
        return res;
    }
};