# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        index = head
        if head.val == val:
            head = head.next
        while index.next != None and index.next.val != val:
            index = index.next
        
        if index.next != None:
            index.next = index.next.next
        return head