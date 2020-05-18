//判断一棵二叉树是不是平衡二叉树。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//自顶向下递归
//时间复杂的：O(nlogn)；
//空间复杂度：O(n)；
class Solution {
public:

    int height(TreeNode* root)
    {
        if (root == NULL){
            return 0;
        }

        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) 
    {
        if (root == NULL){
            return true;
        }
        //一个树使平衡二叉树则它的子树也是平衡二叉树
        return abs(height(root->left) - height(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }
};

//自底向上递归
/*
自顶向下递归计算height存在大量冗余。每次调用height时，要同时计算其子树高度。但是自底向上计算
每个子树的高度只会计算一次。可以递归先计算当前节点的子节点高度，然后再通过子节点高度判断当前
节点是否平衡，从而消除冗余。
算法：使用方法一中定义的height方法。自底向上与自顶向下的逻辑相反，首先判断子树是否平衡，然后
比较子树高度判断父结点是否平衡。
时间复杂度：O(n)
空间复杂度：O(n)
*/
class Solution {
public:

    bool isBalancedTreeHelper(TreeNode* root, int& height)
    {
        if (root == NULL){
            height = 0;
            return true;
        }

        int left, right;
        if (isBalancedTreeHelper(root->left, left) && isBalancedTreeHelper(root->right, right) 
        && abs(left - right) < 2){
            height = max(left, right) + 1;
            return true;
        }

        return false;
    }

    bool isBalanced(TreeNode* root) 
    {
        int height;
        //一个树使平衡二叉树则它的子树也是平衡二叉树
        return isBalancedTreeHelper(root, height);
    }
};