class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        
        low = prices[0]
        maxProfit = 0
        for i in range(1, len(prices)):
            maxProfit = max(maxProfit, prices[i] - low)
            low = min(low, prices[i])
        
        return maxProfit