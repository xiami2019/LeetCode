class Solution:
    def numWays(self, n: int) -> int:
        if n < 2:
            return 1

        oneStep = 1
        twoStep = 1
        for i in range(2, n + 1):
            temp = twoStep
            twoStep = oneStep
            oneStep = temp + twoStep
            oneStep %= int(1e9 + 7)
        return oneStep