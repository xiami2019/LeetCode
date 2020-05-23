class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        
        preNum1 = 1
        preNum2 = 0

        n -= 1
        for i in range(n):
            temp = preNum2
            preNum2 = preNum1
            preNum1 = temp + preNum2
            preNum1 %= 1000000007
        
        return preNum1