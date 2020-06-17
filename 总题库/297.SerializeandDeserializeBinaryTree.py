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
        if root is None:
            res = "null,"
        else:
            res = str(root.val) + ','
            res = res + self.serialize(root.left) + self.serialize(root.right)
        return res

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        data = data.strip(',').split(',')
        def rdeserialize(data):
            if not len(data):
                return None
            if data[0] == "null":
                root = None
                data.pop(0)
            else:
                root = TreeNode(int(data[0]))
                data.pop(0)
                root.left = rdeserialize(data)
                root.right = rdeserialize(data)
            return root
        
        root = rdeserialize(data)
        return root

        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))