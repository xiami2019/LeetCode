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
    bool isBalanced(TreeNode* root, int& depth) {
        if (NULL == root) {
            depth = 0;
            return true;
        }

        int left, right; // 用来保存左子树和右子树的高度
        if (this->isBalanced(root->left, left) && this->isBalanced(root->right, right)) {
            int diff = abs(left - right);
            if (diff <= 1) {
                depth = 1 + (left > right ? left : right);
                return true;
            }
        }

        return false;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return this->isBalanced(root, depth);
    }
};