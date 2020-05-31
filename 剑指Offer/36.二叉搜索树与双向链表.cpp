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
    void convertNode(Node* pNode, Node** pLastNodeInList) {
        if (pNode == NULL) return;

        Node* curNode = pNode;

        if (curNode->left != NULL) {
            convertNode(curNode->left, pLastNodeInList);
        }

        curNode->left = *pLastNodeInList;
        if (*pLastNodeInList != NULL) {
            (*pLastNodeInList)->right = curNode;
        }

        *pLastNodeInList = curNode;

        if (curNode->right != NULL) {
            convertNode(curNode->right, pLastNodeInList);
        }
    }

public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return root;
        Node* pLastNodeInList = NULL;
        convertNode(root, &pLastNodeInList);

        Node* pHeadOfList = pLastNodeInList;
        while (pHeadOfList != NULL && pHeadOfList->left != NULL) {
            pHeadOfList = pHeadOfList->left;
        }
        pHeadOfList->left = pLastNodeInList;
        pLastNodeInList->right = pHeadOfList;
        return pHeadOfList;
    }
};