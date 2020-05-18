/*
通过比较二叉树的前序遍历和对称前序遍历序列来判断二叉树是不是对称的。如果两个
序列是一样的，那么二叉树就是对称的。
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return this->isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
            return true;
        }

        if (root1 == NULL || root2 == NULL) {
            return false;
        }

        if (root1->val != root2->val) {
            return false;
        }
        return this->isSymmetric(root1->left, root2->right) && this->isSymmetric(root1->right, root2->left);
    }
};