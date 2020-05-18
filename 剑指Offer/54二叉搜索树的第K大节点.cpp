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
    TreeNode* inOrder(TreeNode* root, int& k) {
        TreeNode* target = NULL;

        if (root->right != NULL) target = this->inOrder(root->right, k);

        if (target == NULL) {
            if (k == 1) target = root;
            k--;
        }

        if (target == NULL && root->left != NULL) target = this->inOrder(root->left, k);

        return target;
    }

public:
    int kthLargest(TreeNode* root, int k) {
        if (root == NULL || k == 0) return 0;

        return this->inOrder(root, k)->val;
    }
};