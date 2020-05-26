# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        if head is None:
            return None
        if k == 0:
            return None

        fast = head;
        slow = head;
        while k != 0:
            if fast is None:
                return None
            fast = fast.next
            k -= 1

        while fast is not None:
            fast = fast.next
            slow = slow.next

        return slow