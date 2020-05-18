/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*法1，自顶向下递归；
复杂度分析：
时间复杂度：每个结点都要访问一次，因此时间复杂度为O(N)
其中N是结点的数量。
空间复杂度：在最糟糕的情况下，树是完全不平衡的，例如每个结点只剩下左子节点，
递归将会被调用N次（树的高度），因此函数调用栈的存储将是O(N)。但在最好的情况
下（树是完全平衡的），树的高度将是log(N)。因此，在这种情况下的空间复杂度将
是O(log(N))。
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL){
            return 0;
        }

        int leftTree = maxDepth(root->left);
        int rightTree = maxDepth(root->right);

        return max(leftTree, rightTree) + 1;
    }
};

//将递归改写为迭代的形式
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*, int> > bfs;
        if (root != NULL){
            bfs.push(make_pair(root, 1));
        }

        int depth = 0;

        while (!bfs.empty()){
            pair<TreeNode*, int> current = bfs.front();
            bfs.pop();
            if (current.first != NULL){
                depth = max(depth, current.second);
                bfs.push(make_pair(current.first->left, current.second + 1));
                bfs.push(make_pair(current.first->right, current.second + 1));
            }
        }

        return depth;
    }
};