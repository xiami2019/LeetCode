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
    vector<vector<int> > ans;

    void dfs(vector<int>& path, TreeNode* root, int sum, int currentSum) {
        if (root == NULL) return;
        if (root->right == NULL && root->left == NULL) {
            if (currentSum + root->val == sum) {
                path.emplace_back(root->val);
                ans.emplace_back(path);
                path.pop_back();
                return;
            }
            return;
        }

        path.emplace_back(root->val);
        this->dfs(path, root->left, sum, currentSum + root->val);
        this->dfs(path, root->right, sum, currentSum + root->val);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        this->dfs(path, root, sum, 0);
        return ans;
    }
};

/*
LeetCode写法
*/
class Solution {
    vector<vector<int> > ans;

    void dfs(vector<int>& path, TreeNode* root, int expectedSum, int currentSum) {
        currentSum += root->val;
        path.emplace_back(root->val);

        // 如果是叶结点，并且路径上结点值的和等于输入值，则保存下这条路径
        bool isLeaf = root->left == NULL && root->right == NULL;
        if (currentSum == expectedSum && isLeaf) {
            ans.emplace_back(path);
        }

        // 如果不是叶结点，则遍历它的子结点
        if (root->left != NULL) {
            this->dfs(path, root->left, expectedSum, currentSum);
        }
        else if (root->right != NULL) {
            this->dfs(path, root->right, expectedSum, currentSum);
        }
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) return ans;
        vector<int> path;
        int currentSum = 0;
        this->dfs(path, root, sum, currentSum);
        return ans;
    }
};
