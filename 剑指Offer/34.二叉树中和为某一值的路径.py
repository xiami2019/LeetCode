# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        def dfs(singlePath: List[int], root: TreeNode, curSum: int, sum: int) -> None:
            if root == None:
                return None

            curSum += root.val
            singlePath.append(root.val)
            if root.left == None and root.right == None and curSum == sum:
                res.append(singlePath[:])
            else:
                dfs(singlePath, root.left, curSum, sum)
                dfs(singlePath, root.right, curSum, sum)
            
            singlePath.pop()

        res = []
        singlePath = []
        dfs(singlePath, root, 0, sum)
        return res