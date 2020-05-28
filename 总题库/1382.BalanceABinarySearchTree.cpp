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
    vector<int> inorderList;
    void getInorder(TreeNode* root) {
        if (root == NULL) return;
        getInorder(root->left);
        inorderList.push_back(root->val);
        getInorder(root->right);
    }

    TreeNode* build(int left, int right) {
        if (right - left < 0) return NULL;
        int middle = (left + right) >> 1;
        TreeNode *root = new TreeNode(inorderList[middle]);
        root->left = build(left, middle - 1);
        root->right = build(middle + 1, right);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        getInorder(root);
        root = build(0, inorderList.size() - 1);
        return root;
    }
};