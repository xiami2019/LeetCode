# 暴力
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        numsLen = len(nums)
        res = 0
        for i in range(numsLen):
            subSum = 0
            for j in range(i, numsLen):
                subSum += nums[j]
                if subSum == k:
                    res += 1

        return res

# 前缀和
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        preSum = {}
        pre = 0
        count = 0
        preSum[0] = 1
        for i in nums:
            pre += i
            if pre - k in preSum:
                count += preSum[pre - k]
            if pre in preSum:
                preSum[pre] += 1
            else:
                preSum[pre] = 1

        return count