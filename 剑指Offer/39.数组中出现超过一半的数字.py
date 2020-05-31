class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        preNum = nums[0]
        count = 1
        for i in range(1, len(nums)):
            if nums[i] == preNum:
                count += 1
            else:
                count -= 1

            if count < 0:
                preNum = nums[i]
                count = 1
        return preNum