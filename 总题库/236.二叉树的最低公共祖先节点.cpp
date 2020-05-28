/**
 * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {
    }
};
 */

// 法一：先找到到两个节点的路径，然后在找路径上重合的地方。
/**
 * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {
    }
};
 */
class Solution {
    bool path(TreeNode* root, vector<TreeNode*>& singlePath, TreeNode* p) {
        if (root == NULL) return false;
        singlePath.push_back(root);
        if (p->val == root->val) {
            return true;
        }
        if (path(root->left, singlePath, p) || path(root->right, singlePath, p)) {
            return true;
        }
        singlePath.pop_back();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathOfP;
        vector<TreeNode*> pathOfQ;
        path(root, pathOfP, p);
        path(root, pathOfQ, q);
        for (int i = 0; i < pathOfP.size() || i < pathOfQ.size(); i++) {
            if (i >= pathOfP.size() || i >= pathOfQ.size() || pathOfP[i]->val != pathOfQ[i]->val) {
                return pathOfP[i - 1];
            }
        }
        return NULL;
    }
};

// 法二：直接递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        
        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode *left, *right;
        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);

        if (left != NULL && right != NULL) {
            return root;
        }

        return left == NULL ? right : left;
    }
};