'''
法一：使用hashset检查循环
'''
class Solution:
    def isHappy(self, n: int) -> bool:
        
        def getNext(n):
            totalSum = 0
            while n > 0:
                n, remains = divmod(n, 10)
                totalSum += remains ** 2
            return totalSum
        
        seen = set()
        while n != 1 and n not in seen:
            seen.add(n)
            n = getNext(n)

        return n == 1


'''
法二：模拟快慢指针
'''
class Solution:
    def isHappy(self, n: int) -> bool:

        def getNext(n):
            totalSum = 0
            while n > 0:
                n, remains = divmod(n, 10)
                totalSum += remains ** 2
            return totalSum

        slow = n
        fast = getNext(n)
        while fast != 1 and slow != fast:
            slow = getNext(slow)
            fast = getNext(getNext(fast))
        
        return fast == 1