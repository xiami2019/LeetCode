/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recursion
class Solution {
    vector<int> res;
    void postorderRecursivlyTraversal(TreeNode* root) {
        if (root == NULL) return;
        postorderRecursivlyTraversal(root->left);
        postorderRecursivlyTraversal(root->right);
        res.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postorderRecursivlyTraversal(root);
        return res;
    }
};

// Iteration
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;

        while (cur || !s.empty()) {
            while (cur) {
                res.push_back(cur->val);
                s.push(cur->left);
                cur = cur->right;
            }
            cur = s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};