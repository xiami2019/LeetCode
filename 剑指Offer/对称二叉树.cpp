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
可以运用递归和迭代两种方法解决这个问题
通过比较树的前序遍历和拟前序遍历是否一致来解决这个问题
*/
//递归：
class Solution {
    vector<TreeNode*> preorderList, preorderReverseList;
public:

    bool isSymmetric(TreeNode* root) {
        preorder(root);
        preorderReverse(root);
        int listLen = preorderList.size();
        for (int i = 0; i < listLen; i++){
            if ((preorderList[i] == NULL && preorderReverseList[i] == NULL) || (preorderList[i] != NULL && \
            preorderReverseList[i] != NULL && preorderList[i]->val == preorderReverseList[i]->val)){
                continue;
            }
            return false;
        }
        return true;
    }

    void preorder(TreeNode* root){
        preorderList.push_back(root);
        if (root != NULL){
            preorder(root->left);
            preorder(root->right);
        }

    }

    void preorderReverse(TreeNode* root){
        preorderReverseList.push_back(root);
        if (root != NULL){
            preorderReverse(root->right);
            preorderReverse(root->left);
        }
    }
};