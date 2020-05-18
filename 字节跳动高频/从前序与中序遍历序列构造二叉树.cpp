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
    TreeNode* buildSubTree(vector<int>& preorder, int &preorderIndex, vector<int>& inorder, int inLeft, int inRight) {
        if (inLeft > inRight) return NULL;
        TreeNode *root = new TreeNode(preorder[preorderIndex]);
        int mid = inLeft;
        for (; mid <= inRight; mid++) {
            if (inorder[mid] == preorder[preorderIndex]) {
                break;
            }
        }
        preorderIndex++;
        root->left = buildSubTree(preorder, preorderIndex, inorder, inLeft, mid - 1);
        root->right = buildSubTree(preorder, preorderIndex, inorder, mid + 1, inRight);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        return buildSubTree(preorder, preorderIndex, inorder, 0, inorder.size() - 1);
    }
};