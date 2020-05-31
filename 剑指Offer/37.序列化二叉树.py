# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        def rserialize(root: TreeNode, s: str) -> str:
            if root == None:
                s += "None,"
            else:
                s += str(root.val) + ','
                s = rserialize(root.left, s)
                s = rserialize(root.right, s)
            return s
        
        return rserialize(root, "")

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def rdeserialize(data: str) -> TreeNode:
            if data[0] == "None":
                data.pop(0)
                return None
            
            curNode = TreeNode(int(data[0]))
            data.pop(0)
            curNode.left = rdeserialize(data)
            curNode.right = rdeserialize(data)
            return curNode

        data = data.split(',')
        root = rdeserialize(data)
        return root

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))