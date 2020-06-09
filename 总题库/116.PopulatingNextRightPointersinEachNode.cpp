/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
// 使用广度优先搜索进行二叉树的层序遍历
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        int currentLayer = 1, nextLayer = 0;
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if (temp->left != NULL) {
                q.push(temp->left);
                ++nextLayer;
            }
            if (temp->right != NULL) {
                q.push(temp->right);
                ++nextLayer;
            }
            --currentLayer;
            if (currentLayer == 0) {
                temp->next = NULL;
                currentLayer = nextLayer;
                nextLayer = 0;
            }
            else {
                temp->next = q.front();
            }
        }
        return root;
    }
};