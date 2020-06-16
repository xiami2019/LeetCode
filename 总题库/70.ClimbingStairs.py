class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 2:
            return n
        pre1, pre2 = 1, 1

        for _ in range(2, n + 1):
            temp = pre2
            pre2 = pre1
            pre1 = temp + pre2
        
        return pre1