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
public:
//递归(二叉树问题多考虑递归，空间复杂度高)；
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL){
            return NULL;
        }

        if (root->val == p->val || root->val == q->val){
            return root;
        }

        TreeNode* right;
        TreeNode* left;

        right = lowestCommonAncestor(root->right, p, q);
        left = lowestCommonAncestor(root->left, p, q);

        if (right != NULL && left != NULL){
            return root;
        }
        else{
            return right == NULL ? left : right;
        }
    }
};

class Solution {
public:
//迭代方法
/*
由于我们不需要回溯来找到LCA(最近公共祖先)节点，所以我们是完全可以不利用栈或者是递归的。
我们只需找到分割点就可以了。这个分割点就是能让节点p和节点q不能在同一棵子
树上的那个节点，或者是结点p和结点q中的一个，这种情况下其中一个结点是另一
个结点的父亲结点。找分割点可以利用二叉搜索树的性质。
*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != NULL){
            if (p->val > root->val && q->val > root->val){
                //LCA结点位于父结点的右子树
                root = root->right;
                continue;
            }
            else if (p->val < root->val && q->val < root->val){
                //LCA结点位于父结点的左子树
                root = root->left;
                continue;
            }
            else{
                return root;
            }
        }

        return root;
    }
};