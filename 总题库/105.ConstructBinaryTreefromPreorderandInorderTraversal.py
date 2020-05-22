# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTreeHelper(self, preorder: List[int], inorder: List[int], inStart: int, inEnd: int) -> TreeNode:
        if inEnd - inStart < 0:
            return None

        node = TreeNode(preorder[0])
        index = 0
        while index <= inEnd and inorder[index] != preorder[0]:
            index += 1
        
        preorder.pop(0)
        node.left = self.buildTreeHelper(preorder, inorder, inStart, index - 1)
        node.right = self.buildTreeHelper(preorder, inorder, index + 1, inEnd)
        return node


    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        return self.buildTreeHelper(preorder, inorder, 0, len(inorder) - 1)