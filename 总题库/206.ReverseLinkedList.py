# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        tail = None
        while head != None:
            temp = head
            head = head.next
            temp.next = tail
            tail = temp
        
        return tail