# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if root is None:
            return None
        
        if p.val == root.val or q.val == root.val:
            return root
        
        right = self.lowestCommonAncestor(root.right, p, q)
        left = self.lowestCommonAncestor(root.left, p, q)

        if left is not None and right is not None:
            return root
        else:
            return right if right is not None else left
