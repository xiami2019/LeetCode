class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSubSum = float('-inf')
        curSum = 0
        for num in nums:
            curSum = max(curSum + num, num)
            maxSubSum = max(maxSubSum, curSum)
        return maxSubSum