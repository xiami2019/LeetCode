/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Binary Tree Inorder Traversal
/*
solution one: recursion writting
*/
class Solution {
    vector<int> ans;
    void inOrder(TreeNode* root) {
        if (root == NULL) return;
        inOrder(root->left);
        ans.push_back(root->val);
        inOrder(root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};


/*
solution two: iteration writting
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans; // 用来保存结果序列
        if (root == NULL) return ans; // 出错处理
        stack<TreeNode*> s; // 用来保存待访问的结点
        TreeNode* temp = root; // 初始的根结点
        while (temp || s.size()) { 
            while (temp) {
                s.push(temp); // 先访问左子树
                temp = temp->left;
            }
            temp = s.top(); // 左子树访问完毕，开始访问根节点
            s.pop();
            ans.push_back(temp->val);
            temp = temp->right; // 开始访问右子树
        }
        return ans;
    }
};