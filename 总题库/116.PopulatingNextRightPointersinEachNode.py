"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return root
        
        q = []
        currentLayer = 1
        nextLayer = 0
        q.append(root)
        while len(q):
            temp = q[0]
            q.pop(0)
            if temp.left:
                q.append(temp.left)
                nextLayer += 1
            if temp.right:
                q.append(temp.right)
                nextLayer += 1
            
            currentLayer -= 1
            if currentLayer == 0:
                temp.next = None
                currentLayer = nextLayer
                nextLayer = 0
            else:
                temp.next = q[0]
        return root