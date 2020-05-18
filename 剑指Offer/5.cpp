/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//二叉树的前序遍历和中序遍历可以唯一确定一颗二叉树。
/*
方法：分治思想
二叉树的问题一般都是分治思想，递归去做。因为二叉树本身就是递归定义的。
解题思路：
前序遍历的第1个节点一定是二叉树的根节点；
在中序遍历时，根结点把中序遍历分成了两个部分，左边部分构成了二叉树的根结点的左子树，右边部分构成了
二叉树的根结点的右子树
查找根结点在中序遍历序列中的位置，可以遍历，也可以在一开始就记录下来。
根据中序遍历中找到的父结点位置index，可以划分前序遍历序列中的左子树列表和右子树列表（以index+1为边界）。
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0){
            return NULL;
        }

        int root = preorder[0];
        bool ifRight = false;
        vector<int> right, left;
        for (int i = 0; i < inorder.size(); i++){
            if (inorder[i] == root){
                ifRight = true;
                continue;
            }
            if (ifRight){
                right.push_back(inorder[i]);
            }
            else{
                left.push_back(inorder[i]);
            }
        }
        preorder.erase(preorder.begin());
        TreeNode* head = new TreeNode(root);
        head->left = buildTree(preorder, left);
        head->right = buildTree(preorder, right);

        return head;
    }
};