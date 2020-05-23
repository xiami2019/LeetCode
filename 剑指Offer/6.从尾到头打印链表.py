# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 递归实现
class Solution:
    def __init__(self):
        self.ans = []

    def reversePrintHelper(self, head: ListNode) -> None:
        if head == None:
            return
        self.reversePrintHelper(head.next);
        self.ans.append(head.val)

    def reversePrint(self, head: ListNode) -> List[int]:
        self.reversePrintHelper(head)
        return self.ans        