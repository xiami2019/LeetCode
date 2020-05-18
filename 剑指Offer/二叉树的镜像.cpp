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
    //自顶向下，采用递归的方法；
    TreeNode* mirrorTree(TreeNode* root) {
        //先进行递归重点的判定：
        if (root == NULL){
            return root;
        }

        TreeNode* temp = root->right;
        root->right = mirrorTree(root->left);
        root->left = mirrorTree(temp);

        return root;
    }
};