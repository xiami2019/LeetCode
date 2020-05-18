/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//用bfs，同时维护一个优先队列；
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        priority_queue<int> leaves; //降序优先队列;
        // priority_queue<int, vector<int>, greater<int> > 升序优先队列;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()){
            TreeNode* temp = bfs.front();
            bfs.pop();
            if (temp == NULL){
                continue;
            }

            leaves.push(temp->val);
            bfs.push(temp->left);
            bfs.push(temp->right);
        }

        k--;
        while (k--){
            leaves.pop();
        }

        return leaves.top();
    }
};

class Solution {
    //逆中序遍历二叉搜索树的递归写法；
public:
    int kthLargest(TreeNode* root, int k){
        inorder(root, k); //进行递归遍历；

        return result; 
    }

    void inorder(TreeNode* root, int k){
        if (root == NULL){ //递归终止条件；
            return;
        }

        if (root->right != NULL){ //逆中序，先右边；
            inorder(root->right, k);
        }

        if (++counts == k){ //中间；
            result = root->val;
        }

        if (root->left != NULL){ //左边；
            inorder(root->left, k);
        }

        return;
    }

    int counts = 0; //当前遍历到的结点的个数;
    int result = 0; //结果；
};

class Solution {
    /*逆中序遍历二叉搜索树的迭代写法，使用栈实现：
    遇到一个结点入栈，然后遍历它的右子树，当右子树结束遍历后 ，从栈顶弹出
    这个结点并访问，然后继续遍历它的左子树。
    */
public:
    int kthLargest(TreeNode* root, int k){
        stack<TreeNode*> inorder;
        while (root != NULL || !inorder.empty()){
            while (root != NULL){ //一直往右入栈；
                inorder.push(root);
                root = root->right;
            }
            if (!inorder.empty()){
                k--;
                if (k == 0){
                    return inorder.top()->val;
                }
                root = inorder.top();
                inorder.pop();
                root = root->left; //开始往左遍历；
            }
            
        }

        return 0; 
    }
};