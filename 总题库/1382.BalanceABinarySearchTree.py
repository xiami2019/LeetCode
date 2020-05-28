# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        def getInorder(root: TreeNode) -> None:
            if root == None:
                return None
            
            getInorder(root.left)
            inorderList.append(root.val)
            getInorder(root.right)

        def build(left: int, right: int) -> TreeNode:
            if right - left < 0:
                return None

            middle = (left + right) // 2
            root = TreeNode(inorderList[middle])
            root.left = build(left, middle - 1)
            root.right = build(middle + 1, right)
            return root

        inorderList = list()
        getInorder(root)
        root = build(0, len(inorderList) - 1)
        return root