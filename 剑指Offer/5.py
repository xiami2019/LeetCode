class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if len(inorder) == 0:
            return None
        
        # preorder 的第一个结点为根节点
        root = TreeNode(preorder[0])
        # 获取根节点在 inorder 中的索引
        idx = inorder.index(preorder[0])
        # 左子树
        root.left = self.buildTree(preorder[1:idx+1], inorder[:idx])
        # 右子树
        root.right = self.buildTree(preorder[idx+1:], inorder[idx+1:])
        return root