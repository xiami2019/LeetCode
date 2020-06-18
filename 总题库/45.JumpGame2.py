class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) < 2: return 0
        numsLen, border, index, stepCounts = len(nums), nums[0], 0, 1
        while index < numsLen and index <= border:
            if border >= numsLen - 1:
                return stepCounts
            longest = 0
            for i in range(index + 1, border + 1):
                longest = max(longest, i + nums[i])
            if longest > border:
                index = border
                border = longest
                stepCounts += 1
            else: return 0
        return 0
