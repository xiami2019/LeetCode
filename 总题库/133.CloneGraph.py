"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors
"""

class Solution:
    def __init__(self):
        self.visited = {}

    def cloneGraph(self, node: 'Node') -> 'Node':
        if node == None: return None
        if node in self.visited:
            return self.visited[node]
        
        newNode = Node(node.val)
        self.visited[node] = newNode
        for neighbor in node.neighbors:
            newNode.neighbors.append(self.cloneGraph(neighbor))
        return newNode