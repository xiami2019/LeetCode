/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 比较二叉树的前序遍历和逆前序遍历是否相同
class Solution {
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) return true;
        
        if (root1 == NULL || root2 == NULL) return false;

        if (root1->val != root2->val) return false;

        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
};