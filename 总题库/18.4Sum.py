class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        numsLen = len(nums)
        if numsLen < 4:
            return []

        nums = sorted(nums)
        res = []
        for i in range(numsLen):
            if nums[i] > target and nums[i] > 0:
                break

            if i > 0 and nums[i] == nums[i - 1]:
                continue
                
            newTarget = target - nums[i]

            for j in range(i + 1, numsLen):
                if nums[j] > newTarget and nums[j] > 0:
                    break

                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                
                left = j + 1
                right = numsLen - 1
                while left < right:
                    tempSum = nums[j] + nums[left] + nums[right]

                    if tempSum == newTarget:
                        res.append([nums[i], nums[j], nums[left], nums[right]])
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        left += 1
                        right -= 1
                    elif tempSum < newTarget:
                        left += 1
                    elif tempSum > newTarget:
                        right -= 1
        return res