// Binary Tree Preorder Traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
Solution one: recursion writting
*/
class Solution {
    vector<int> ans;
    void preorder(TreeNode* root) {
        if (root == NULL) return;
        ans.emplace_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
};

/*
Solution two: iteration writting
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans; // 用来保存结果序列
        stack<TreeNode*> s; // 保存待访问的结点
        TreeNode* temp = root; // 初始根结点
        while (temp || s.size()) {
            while (temp) {
                s.push(temp->right); // 把待访问的右子树结点保存起来
                ans.push_back(temp->val); // 访问当前的中间结点
                temp = temp->left; // 继续遍历左子树
            }
            temp = s.top(); // 左子树已经遍历完毕，开始遍历右子树
            s.pop();
        }
        return ans;
    }
};