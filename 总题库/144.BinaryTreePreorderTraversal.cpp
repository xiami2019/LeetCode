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
    void preorderRecursivlyTraversal(TreeNode* root) {
        if (!root) return;
        res.push_back(root->val);
        preorderRecursivlyTraversal(root->left);
        preorderRecursivlyTraversal(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorderRecursivlyTraversal(root);
        return res;
    }
};

// Iteration
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s; // nodes waited to be visited
        vector<int> res; // result
        TreeNode* curNode = root; // current node

        while (curNode || !s.empty()) {
            while (curNode) {
                res.push_back(curNode->val);
                s.push(curNode->right);
                curNode = curNode->left;
            }
            curNode = s.top();
            s.pop();
        }
        return res;
    }
};