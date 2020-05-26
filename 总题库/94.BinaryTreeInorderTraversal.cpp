/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursion
class Solution {
    vector<int> res;
    void inorderRecursiveTraversal(TreeNode* root) {
        if (root == NULL) return;
        inorderRecursiveTraversal(root->left);
        res.emplace_back(root->val);
        inorderRecursiveTraversal(root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorderRecursiveTraversal(root);
        return res;
    }
};

// iteration
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* temp = root;

        while (root || !s.empty()) {
            while (temp != NULL) {
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            res.push_back(temp->val);
            temp = temp.right();
        }
        return res;
    }
};