class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        maxF = nums[0]
        minF = nums[0] 
        ans = nums[0]
        for i in range(1, len(nums)):
            mx = maxF
            mn = minF
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]))
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]))
            ans = max(maxF, ans)
        
        return ans