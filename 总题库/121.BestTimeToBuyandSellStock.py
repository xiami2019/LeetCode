class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2: return 0
        buy, sell = -prices[0], 0
        for i in range(1, len(prices)):
            sell = max(sell, prices[i] + buy)
            buy = max(buy, -prices[i])
        return sell