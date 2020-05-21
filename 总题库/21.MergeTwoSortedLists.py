# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:
            return l2
        if l2 is None:
            return l1

        dummy = ListNode(0)
        preNode = dummy
        while l1 != None and l2 != None:
            if l1.val < l2.val:
                preNode.next = l1
                l1 = l1.next
            else:
                preNode.next = l2
                l2 = l2.next
            preNode = preNode.next
        
        while l1 is not None:
            preNode.next = l1
            l1 = l1.next
            preNode = preNode.next

        while l2 is not None:
            preNode.next = l2
            l2 = l2.next
            preNode = preNode.next
        return dummy.next

