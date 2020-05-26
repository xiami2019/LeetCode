# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def doesTree1HasTree2(self, A: TreeNode, B: TreeNode) -> bool:
        if not B: return True
        if not A: return False
        if A.val != B.val: return False

        return self.doesTree1HasTree2(A.left, B.left) and self.doesTree1HasTree2(A.right, B.right)

    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        result = False

        if A and B:
            if A.val == B.val:
                result = self.doesTree1HasTree2(A, B)
            if result != True:
                result = self.isSubStructure(A.left, B)
            if result != True:
                result = self.isSubStructure(A.right, B)
        return result