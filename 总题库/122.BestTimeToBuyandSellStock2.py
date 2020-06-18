class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        buy, sell = -prices[0], 0
        for i in range(1, len(prices)):
            oldSell = sell
            sell = max(oldSell, buy + prices[i])
            buy = max(buy, oldSell - prices[i])
        return sell