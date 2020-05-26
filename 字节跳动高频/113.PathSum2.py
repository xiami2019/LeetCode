# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.res = []

    def dfs(self, root: TreeNode, singlePath: List[int], curSum: int, sum: int) -> None:
        if root == None:
            return None

        curSum += root.val
        singlePath.append(root.val)
        if root.left == None and root.right == None and curSum == sum:
            self.res.append(singlePath[:]) # 注意浅拷贝的问题
        else:
            self.dfs(root.left, singlePath, curSum, sum)
            self.dfs(root.right, singlePath, curSum, sum)
        
        singlePath.pop()
        return None

    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        singlePath = []
        self.dfs(root, singlePath, 0, sum)
        return self.res
