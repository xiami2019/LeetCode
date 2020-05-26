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
    bool dfs(TreeNode* root, int curSum, int sum) {
        if (root == NULL) return false;

        curSum += root->val;
        if (root->left == NULL && root->right == NULL && curSum == sum) return true; 
        return dfs(root->left, curSum, sum) || dfs(root->right, curSum, sum);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, 0, sum);
    }
};