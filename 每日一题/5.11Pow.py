class Solution:
    def quickMul(self, x: float, N: int) -> float:
        if N == 0:
            return 1.0

        y = self.quickMul(x, int(N / 2))
        return y * y if N % 2 == 0 else y * y * x

    def myPow(self, x: float, n: int) -> float:
        N = n;
        return self.quickMul(x, N) if N >= 0 else 1 / self.quickMul(x, -N)