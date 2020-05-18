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
    //层次遍历用BFS，另外添加几个变量维护当前层和下一层打印的数量
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        int toBePrinted = 1;
        int nextLayerNodes = 0;
        bool even = false;
        queue<TreeNode*> bfs;
        bfs.push(root);
        vector<int> singleLayerNode;
        while (!bfs.empty()) {
            TreeNode* currentNode = bfs.front();

            if (currentNode->left != NULL) {
                bfs.push(currentNode->left);
                nextLayerNodes++;
            }
            if (currentNode->right != NULL) {
                bfs.push(currentNode->right);
                nextLayerNodes++;
            }
            
            singleLayerNode.emplace_back(currentNode->val);
            bfs.pop();
            toBePrinted--;
            if (toBePrinted == 0) {
                if (even) {
                    reverse(singleLayerNode.begin(), singleLayerNode.end());
                }
                ans.emplace_back(singleLayerNode);
                singleLayerNode.clear();
                toBePrinted = nextLayerNodes;
                nextLayerNodes = 0;
                even = !even;
            }
        }
        return ans;
    }
};

/*
法二：不用reverse，用两个栈来实现
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        stack<TreeNode*> evenStack;
        stack<TreeNode*> oddStack;
        int toBePrinted = 1;
        int nextLayerNodes = 0;
        bool even = false; // 表示当前打印的层是奇数层还是偶数层
        oddStack.push(root);
        vector<int> singleLayerNode;
        while (!evenStack.empty() || !oddStack.empty()) {
            TreeNode* currentNode = NULL;
            if (even) {
                currentNode = evenStack.top();
                evenStack.pop();
                if (currentNode->right != NULL) {
                    oddStack.push(currentNode->right);
                    nextLayerNodes++;
                }
                if (currentNode->left != NULL) {
                    oddStack.push(currentNode->left);
                    nextLayerNodes++;
                }
            }
            else {
                currentNode = oddStack.top();
                oddStack.pop();
                if (currentNode->left != NULL) {
                    evenStack.push(currentNode->left);
                    nextLayerNodes++;
                }
                if (currentNode->right != NULL) {
                    evenStack.push(currentNode->right);
                    nextLayerNodes++;
                }
            }
            
            singleLayerNode.emplace_back(currentNode->val);
            toBePrinted--;
            if (toBePrinted == 0) {
                ans.emplace_back(singleLayerNode);
                singleLayerNode.clear();
                toBePrinted = nextLayerNodes;
                nextLayerNodes = 0;
                even = !even;
            }
        }
        return ans;
    }
};