# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def myReverse(self, head: ListNode, tail: ListNode):
        prev = tail.next;
        p = head;
        while prev != tail:
            nex = p.next;
            p.next = prev
            prev = p
            p = nex
        return tail, head

    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        preNode = ListNode(0)
        preNode.next = head
        pre = preNode

        while head != None:
            tail = pre
            for i in range(k):
                tail = tail.next
                if tail == None:
                    return preNode.next
            
            nex = tail.next
            head, tail = self.myReverse(head, tail)

            pre.next = head
            tail.next = nex
            pre = tail
            head = tail.next
        
        return preNode.next