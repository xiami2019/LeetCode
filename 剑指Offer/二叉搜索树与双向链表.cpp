/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
    void convertNode(Node* root, Node** pLastNodeInList) {
        if (root == nullptr) return;

        Node* current = root;

        if (current->left != nullptr) {
            convertNode(current->left, pLastNodeInList);
        }

        current->left = *pLastNodeInList;
        if (*pLastNodeInList != nullptr) {
            (*pLastNodeInList)->right = current;
        }

        *pLastNodeInList = current;

        if (current->right != nullptr) {
            convertNode(current->right, pLastNodeInList);
        }
    }

public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return root;
        Node* pLastNodeInList = nullptr;
        convertNode(root, &pLastNodeInList);

        // pLastNodeInList指向双向链表的尾结点
        // 需要返回的是头结点
        Node* pHeadOfList = pLastNodeInList;
        while (pHeadOfList != nullptr && pHeadOfList->left != nullptr) {
            pHeadOfList = pHeadOfList->left;
        }
        pHeadOfList->left = pLastNodeInList;
        pLastNodeInList->right = pHeadOfList;
        return pHeadOfList;
    }
};