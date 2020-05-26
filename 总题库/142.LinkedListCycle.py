# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head == None:
            return None
        
        fast = head
        slow = head
        while fast != None and fast.next != None:
            fast = fast.next.next
            slow = slow.next
            if slow == fast:
                break
        
        if fast == None or fast.next == None:
            return None

        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next
        
        return slow