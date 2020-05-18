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
    int maxLengthOfPaths = INT_MIN;

    int subTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int tempLength = root->val;
        int leftTreeLength = subTree(root->left);
        int rightTreeLength = subTree(root->right);
        if (leftTreeLength > 0) tempLength += leftTreeLength;
        if (rightTreeLength > 0) tempLength += rightTreeLength;
        int subTreeLength = leftTreeLength > rightTreeLength ? leftTreeLength : rightTreeLength;
        maxLengthOfPaths = max(tempLength, maxLengthOfPaths);
        if (subTreeLength > 0) {
            return root->val + subTreeLength;
        }
        return root->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        subTree(root);
        return maxLengthOfPaths;
    }
};