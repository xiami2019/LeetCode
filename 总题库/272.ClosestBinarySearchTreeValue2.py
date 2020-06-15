# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        # 在中序遍历的过程中维护result数组；
        if not root: return []
        stack = []
        result = []
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if len(result) < k: 
                result.append(root.val)
            elif abs(result[0] - target) > abs(root.val - target):
                result.pop(0)
                result.append(root.val)
            else: 
                # 因为中序遍历得到的是一个升序序列，此时可以进行剪枝；
                break
            root = root.right
        return result
