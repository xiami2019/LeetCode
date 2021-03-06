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
    bool doesTree1HasTree2(TreeNode* A, TreeNode* B) {
        if (B == NULL) return true;
        if (A == NULL) return false;
        if (A->val != B->val) return false;
        return this->doesTree1HasTree2(A->left, B->left) && this->doesTree1HasTree2(A->right, B->right);
    }

public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool result = false;

        if (A != NULL && B != NULL) {
            if (A->val == B->val) {
                result = this->doesTree1HasTree2(A, B);
            }
            if (!result) {
                result = this->isSubStructure(A->left,  B);
            }
            if (!result) {
                result = this->isSubStructure(A->right, B);
            }
        }
        return result;
    }
};