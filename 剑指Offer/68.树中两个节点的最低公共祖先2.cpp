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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        if (p->val == root->val || q->val == root->val) {
            return root;
        }

        TreeNode *right, *left;
        right = lowestCommonAncestor(root->right, p, q);
        left = lowestCommonAncestor(root->left, p, q);
        
        if (right != NULL && left != NULL) {
            return root;
        }
        else return right == NULL ? left : right;
    }
};