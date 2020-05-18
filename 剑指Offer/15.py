class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1;
        
        if n < 0:
            return 1 / myPow(x, -n)
        
        temp = self.myPow(x, int(n / 2))
        if n & 1 :
            return temp * temp * x
        else:
            return temp * temp