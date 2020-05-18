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
    //层次遍历用BFS
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int> > bfs;
        bfs.push(make_pair(root, 0));
        vector<vector<int> > result;

        if (root == NULL){
            return result;
        }

        while (!bfs.empty()){
            pair<TreeNode*, int> current = bfs.front();
            if (result.size() <= current.second){
                vector<int> temp;
                result.push_back(temp);
            }
            result[current.second].push_back(current.first->val);
            bfs.pop();
            if (current.first->left != NULL){
                bfs.push(make_pair(current.first->left, current.second + 1));
            }
            if (current.first->right != NULL){
                bfs.push(make_pair(current.first->right, current.second + 1));
            }
        }

        return result;
    }
};

/*
剑指Offer解法
*/
class Solution {
public:
    //层次遍历用BFS，另外添加几个变量维护当前层和下一层打印的数量
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        int toBePrinted = 1;
        int nextLayerNodes = 0;
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
                ans.emplace_back(singleLayerNode);
                singleLayerNode.clear();
                toBePrinted = nextLayerNodes;
                nextLayerNodes = 0;
            }
        }
        return ans;
    }
};