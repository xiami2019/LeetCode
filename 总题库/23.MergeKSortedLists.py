# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: List[ListNode], l2: List[ListNode]) -> ListNode:
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        
        head = ListNode
        tail = head
        while l1 and l2:
            if l1.val < l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next
        
        tail.next = l1 if l1 else l2

        return head.next

    def merge(self, lists: List[ListNode], left: int, right: int) -> ListNode:
        if left == right: return lists[left]
        if left > right: return None
        mid = (left + right) >> 1
        return self.mergeTwoLists(self.merge(lists, left, mid), self.merge(lists, mid + 1, right))

    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        return self.merge(lists, 0, len(lists) - 1)