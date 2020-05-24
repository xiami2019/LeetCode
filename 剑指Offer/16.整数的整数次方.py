class Solution:
    def quickMul(self, x: float, n: int) -> float:
        ans = 1.0
        xContribute = x

        while n:
            if n & 1:
                # 在这一位上x有贡献
                ans *= xContribute
            xContribute *= xContribute
            n >>= 1
        return ans
    def myPow(self, x: float, n: int) -> float:
        if abs(x - 0) < 1e-9:
            return 0

        return self.quickMul(x, n) if n >= 0 else 1 / self.quickMul(x, -n)
