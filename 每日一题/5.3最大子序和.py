class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = -float('inf')
        tempSum = 0
        for i in nums:
            if tempSum >= 0:
                tempSum += i
            else:
                tempSum = i
            ans = max(ans, tempSum)
        return ans