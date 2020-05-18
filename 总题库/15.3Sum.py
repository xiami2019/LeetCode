class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        numsLen = len(nums)
        if numsLen < 3:
            return []

        res = []
        for i in range(numsLen):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left = i + 1
            right = numsLen - 1
            while left < right:
                tempSum = nums[i] + nums[left] + nums[right]

                if tempSum == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1
                
                elif tempSum < 0:
                    left += 1
                elif tempSum > 0:
                    right -= 1
        return res