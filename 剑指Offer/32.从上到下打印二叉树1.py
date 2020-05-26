# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        
        res = []
        q = [root]
        while len(q) != 0:
            temp = q[0]
            q.pop(0)
            res.append(temp.val)
            if temp.left != None:
                q.append(temp.left)
            if temp.right != None:
                q.append(temp.right)
        
        return res
            

        