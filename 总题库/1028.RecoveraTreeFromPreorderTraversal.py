# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        path = []
        pos = 0
        while pos < len(S):
            level, value = 0, 0
            while pos < len(S) and S[pos] == '-':
                level += 1
                pos += 1
            while pos < len(S) and S[pos].isdigit():
                value = 10 * value + int(S[pos])
                pos += 1
            
            node = TreeNode(value)
            if level == len(path):
                if len(path) != 0:
                    path[-1].left = node
            else:
                while len(path) > level:
                    path.pop()
                path[-1].right = node
            path.append(node)
        while len(path) > 1:
            path.pop()
        return path[0]