# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        res = []
        singleLayer = []
        q = [root]
        toBeStored = 1
        nextLayer = 0
        while len(q) != 0:
            temp = q[0]
            if (temp.left != None):
                q.append(temp.left)
                nextLayer += 1
            if (temp.right != None):
                q.append(temp.right)
                nextLayer += 1
                
            q.pop(0)
            toBeStored -= 1
            singleLayer.append(temp.val)

            if toBeStored == 0:
                toBeStored = nextLayer
                nextLayer = 0
                res.append(singleLayer)
                singleLayer = []

        return res
