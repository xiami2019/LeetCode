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
法一：递归法
*/
class Solution {
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return false;

        bool leftTree = this->dfs(root->left, p, q);
        bool rightTree = this->dfs(root->right, p, q);
        
        if ((leftTree || rightTree) && (root->val == q->val || root->val == p->val) || (leftTree && rightTree)) {
            ans = root;
        }
        return leftTree || rightTree || root->val == p->val || root->val == q->val;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->dfs(root, p, q);
        return ans;
    }
};

/*
法二：存储父节点

思路：我们可以用哈希表存储所有节点的父节点，然后我们就可以利用节点的父节点信息从p节点开始不断往上跳，
并记录已经访问过的节点，再从q节点开始不断往上跳，如果碰到已经访问过的节点，那么这个节点就是我们要找
的最近公共祖先。

算法：
1. 从根节点开始遍历整棵二叉树，用哈希表记录每个节点的父节点指针。
2. 从p节点开始不断往它的祖先移动，并用数据结构记录已经访问过的祖先节点。
3. 同样，我们再从q节点开始不断往它的祖先移动，如果有祖先已经被访问过，即意味着这是p和q的深度最深的公共
祖先，即LCA节点。
*/
class Solution {
public:
    unordered_map<int, TreeNode*> father;
    unordered_map<int, bool> vis;
    void dfs(TreeNode* root) {
        if (root->left != NULL) {
            this->father[root->left->val] = root;
            this->dfs(root->left);
        }

        if (root->right != NULL) {
            this->father[root->right->val] = root;
            this->dfs(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->father[root->val] = NULL;
        this->dfs(root);
        while (p != NULL) {
            this->vis[p->val] = true;
            p = this->father[p->val];
        }

        while (q != NULL) {
            if (this->vis[q->val]) return q;
            q = this->father[q->val];
        }
        return NULL;
    }
};