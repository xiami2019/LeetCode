# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, root: TreeNode, curSum: int, sum: int) ->bool:
        if root == None:
            return False

        curSum += root.val
        if root.left == None and root.right == None and curSum == sum:
            return True
        
        return self.dfs(root.left, curSum, sum) or self.dfs(root.right, curSum, sum)

    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        return self.dfs(root, 0, sum)
