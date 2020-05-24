class Solution:
    def cuttingRope(self, n: int) -> int:
        if n < 2: return 0
        if n == 2: return 1
        if n == 3: return 2

        dpTable = [0 for i in range(n + 1)]
        dpTable[1] = 1
        dpTable[2] = 2
        dpTable[3] = 3

        for i in range(4, n + 1):
            maxProduct = 0
            for j in range(1, n // 2 + 1):
                maxProduct = max(maxProduct, dpTable[j] * dpTable[i - j])
            dpTable[i] = maxProduct

        return dpTable[n]