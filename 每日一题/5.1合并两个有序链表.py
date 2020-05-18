# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        preHeadNode = ListNode(0)
        iterPoint = preHeadNode
        while l1 != None and l2 != None:
            if l1.val < l2.val:
                iterPoint.next = l1
                l1 = l1.next
            else:
                iterPoint.next = l2
                l2 = l2.next
            iterPoint = iterPoint.next
        iterPoint.next = l1 if l1 else l2
        return preHeadNode.next