BinaryTreeNode* GetNext(BinaryTreeNode *pNode) {
    if (pNode == NULL) return NULL;
    
    BinaryTreeNode *pNext = NULL;
    if (pNode->right != NULL) {
        // 如果该节点有右子树，则它的下一个节点就是它右子树的最左节点
        BinaryTreeNode *pRight = pNode->right;
        while (pRight->left != NULL) {
            pRight = pRight->left;
        }
        pNext = pRight;
    }
    else if (pNode->parent != NULL) {
        BinaryTreeNode *pCurrent = pNode;
        BinaryTreeNode *pParent = pNode->parent;
        while (pParent != NULL && pCurrent == pParent->right) {
            pCurrent = pParent;
            pParent = pParent->parent;
        }
        pNext = pParent;
    }
    return pNext;
}