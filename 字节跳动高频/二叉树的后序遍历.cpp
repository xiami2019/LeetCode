// Binary Tree Postorder Traversal
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
Solution one: recursion writting
*/
class Solution {
    vector<int> ans;
    void postOrder(TreeNode* root) {
        if (root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        ans.emplace_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return ans;
    }
};

/*
Solution two: iteration writting
*/
// 法一：先进行拟前序遍历（根，右，左），得到前序遍历后，再将序列反序
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* temp = root;
        while (temp || s.size()) {
            while (temp) {
                ans.emplace_back(temp->val);
                s.push(temp->left);
                temp = temp->right;
            }
            temp = s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/* 
法二：
思路：每到一个节点A，因为根要最后访问，将其入栈。然后遍历左子树，遍历右子树，最后返回到A。
但是出现一个问题，无法区分是从左子树返回，还是从右子树返回。
因此，给A节点附加一个标记T。在访问其右子树前，T置为True。之后子树返回时，当T为True表示从
右子树返回，否则从左子树返回。
当T为false时，表示A的左子树遍历完，还要访问右子树。
当为true时，表示A的两棵子树都遍历过了，要访问A了。并且在A访问完后，A这课子树都访问完成了。
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        unordered_map<TreeNode*, int> done; // 节点的标记
        TreeNode* temp = root;
        while (temp || s.size()) {
            while (temp) {
                // 每到一个节点，因为根要最后访问，所以现将其入栈，然后遍历左子树，再遍历右子树
                s.push(temp);
                temp = temp->left;
            }
            while (s.size() && done[s.top()]) { // 此时代表左右子树都已经遍历完
                ans.push_back(s.top()->val);
                s.pop();
            }
            if (s.size()) { // 此时只遍历了左子树
                temp = s.top()->right;
                done[s.top()] = 1;
            }
        }
        return ans;
    }
};