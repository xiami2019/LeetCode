class Solution:
    def jump(self, nums: List[int]) -> int:
        maxPos = 0
        numsLen = len(nums)
        end = 0
        step = 0

        for i in range(numsLen - 1):
            if maxPos >= i:
                maxPos = max(maxPos, nums[i] + i);
                if i == end:
                    end = maxPos
                    step += 1

        return step