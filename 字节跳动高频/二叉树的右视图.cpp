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
方法一：广度优先搜索
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        int toBePrinted = 1;
        int nextSingleLayer = 0;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            auto currentNode = bfs.front();
            if (currentNode->left != NULL) {
                bfs.push(currentNode->left);
                nextSingleLayer++;
            }
            if (currentNode->right != NULL) {
                bfs.push(currentNode->right);
                nextSingleLayer++;
            }
            bfs.pop();
            toBePrinted--;
            if (toBePrinted == 0) {
                toBePrinted = nextSingleLayer;
                nextSingleLayer = 0;
                ans.emplace_back(currentNode->val);
            }
        }
        return ans;
    }
};

// LeetCode解法
/*
方法二：深度优先搜索
在深度优先搜索中，我们总是先访问右子树。这样就保证了当我们访问树的某个特定深度时，我们正在访问的节点总是该
深度的最右侧节点。于是，可以存储在每个深度访问的第一个结点，一旦我们知道了树的层数，就可以得到最终的结果数组。
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> rightMostValueDepth;
        int maxDepth = -1;
        
        /*
        These two stacks are always synchronized, providing an implicit
        association values with the same offset on each stack.
        */
        stack<TreeNode*> nodeStack;
        stack<int> depthStack;
        nodeStack.push(root);
        depthStack.push(0);

        // 开始深搜
        while (!nodeStack.empty()) {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            int depth = depthStack.top();
            depthStack.pop();

            if (node != NULL) {
                maxDepth = max(maxDepth, depth);

                /*
                The first node that we encounter at a particular depth contains the correct value
                Because we firstly visit the right sub-tree.
                */
                if (rightMostValueDepth.find(depth) == rightMostValueDepth.end()) {
                    rightMostValueDepth[depth] = node->val;
                }

                nodeStack.push(node->left);
                nodeStack.push(node->right);
                depthStack.push(depth + 1);
                depthStack.push(depth + 1);
            }
        }
        vector<int> ans;
        for (int depth = 0; depth <= maxDepth; depth++) {
            ans.emplace_back(rightMostValueDepth[depth]);
        }
        return ans;
    }
};