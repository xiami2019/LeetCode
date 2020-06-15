/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// maintain the result k values when doing inorder traveral
class Solution {
    vector<int> inorderTraversal;
    queue<int> q;

    void inorder(TreeNode* root, double target, int k) {
        stack<TreeNode*> s;
        TreeNode* temp = root;
        while (temp != NULL || !s.empty()) {
            while (temp != NULL) {
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            if (q.size() < k) {
                q.push(temp->val);
            }
            else if (abs(temp->val - target) < abs(q.front() - target)) {
                q.pop();
                q.push(temp->val);
            }
            else {
                break;
            }
            temp = temp->right;
        }
    }

public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        inorder(root, target, k);
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};