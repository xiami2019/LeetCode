/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 树是二叉搜索树时的情况
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        
        if (p->val < q->val) {
            TreeNode *temp = p;
            p = q;
            q = temp;
        }

        TreeNode *temp;
        if ((p->val > root->val && q->val < root->val) || (p->val == root->val || q->val == root->val)) return root;
        else if (p->val > root->val && q->val > root->val) {
            temp = lowestCommonAncestor(root->right, p, q);
            if (temp) return temp;
        }
        else if (p->val < root->val && q->val < root->val) {
            temp = lowestCommonAncestor(root->left, p, q);
        }
        return temp;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val > root->val && q->val > root->val) {
                root = root->right;
                continue;
            }
            else if (p->val < root->val && q->val < root->val) {
                root = root->left;
                continue;
            }
            else {
                return root;
            }
        }
        return root;
    }
};