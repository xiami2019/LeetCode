class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        numsLen = len(nums)
        if numsLen <= 1:
            return

        index = numsLen - 1
        while index > 0 and nums[index] <= nums[index - 1]:
            index -= 1

        if index == 0:
            nums.reverse()

        else:
            left = index
            right = numsLen - 1
            while left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
            
            for i in range(index, numsLen):
                if nums[i] > nums[index - 1]:
                    nums[i], nums[index - 1] = nums[index - 1], nums[i]
                    break

        