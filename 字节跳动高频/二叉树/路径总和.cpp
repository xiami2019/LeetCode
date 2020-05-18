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
递归写法
*/
class Solution {
    bool dfs(TreeNode* root, int tempSum, int sum) {
        if (root == NULL) return false;
        tempSum += root->val;
        if (tempSum == sum && root->left == NULL && root->right == NULL) {
            return true;
        }
        // if (tempSum > sum) return false;
        return dfs(root->left, tempSum, sum) || dfs(root->right, tempSum, sum);
        

    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, 0, sum);
    }
};

/*
迭代写法
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;

        stack<TreeNode*> nodeStack;
        stack<int> sumStack;
        nodeStack.push(root);
        sumStack.push(sum - root->val);

        TreeNode *node;
        int currentSum = 0;
        while (!nodeStack.empty()) {
            node = nodeStack.top();
            currentSum = sumStack.top();
            nodeStack.pop();
            sumStack.pop();

            if (node->left == NULL && node->right == NULL && currentSum == 0) {
                return true;
            }

            if (node->left != NULL) {
                nodeStack.push(node->left);
                sumStack.push(currentSum - node->left->val);
            }

            if (node->right != NULL) {
                nodeStack.push(node->right);
                sumStack.push(currentSum - node->right->val);
            }
        }
        return false;
    }
};