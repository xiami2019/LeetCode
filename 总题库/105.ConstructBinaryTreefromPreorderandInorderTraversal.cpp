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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
        if (inEnd - inStart < 0) return NULL;

        TreeNode* node = new TreeNode(preorder[0]);
        int index = inStart;
        while (index <= inEnd && inorder[index] != preorder[0]) ++index;
        preorder.erase(preorder.begin());
        node->left = buildTreeHelper(preorder, inorder, inStart, index - 1);
        node->right = buildTreeHelper(preorder, inorder, index + 1, inEnd);
        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1);
    }
};