/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//DFS
class Solution {
public:
    int lengthes;

    int diameterOfBinaryTree(TreeNode* root) {
        this->lengthes = 1;
        dfs(root);
        return this->lengthes - 1;
    }

    int dfs(TreeNode* root) {
        if (NULL == root){
            return 0;
        }
        int L = dfs(root->left);
        int R = dfs(root->right);
        this->lengthes = max(this->lengthes, L + R + 1);
        return max(L, R) + 1;
    }
};