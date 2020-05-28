"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head == None:
            return None
        
        curNode = head;
        while curNode != None:
            temp = curNode.next
            curNode.next = Node(curNode.val)
            curNode.next.next = temp
            curNode.next.random = curNode.random
            curNode = temp
        curNode = head.next
        while True:
            curNode.random = curNode.random if curNode.random == None else curNode.random.next
            if curNode.next == None: 
                break
            curNode = curNode.next.next

        newHead = head.next
        curNode = head
        newcurNode = newHead

        while curNode != None:
            curNode.next = curNode.next.next
            curNode = curNode.next
            if newcurNode.next != None:
                newcurNode.next = newcurNode.next.next
                newcurNode = newcurNode.next
        
        return newHead
